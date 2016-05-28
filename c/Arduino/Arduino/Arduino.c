#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

#define F_CPU  16000000
#define BAUD   9600
#define BRC    ((F_CPU / 16 / BAUD) - 1) // Baud rate calculate
#define SERIAL 1024

int8_t serialBuffer[SERIAL];
int serialPosWrite = 0;
int serialPosRead = 0;

int main(void)
{
	sei();
	
	// Usart Baud Rate register. �������� ��������� ���\���
	UBRR0H = (BRC >> 8); // ���������� 8 ������� ���
	UBRR0L = BRC; // ���������� 8 ������� ���
	
	// ��������� ���������� USART
	UCSR0B = (1 << TXEN0); // �������� �������� ����� USART, �������� ������ ����� � ������� ������
	UCSR0B |= (1 << TXCIE0); // ��������� ���������� �� ���������� �������� �����
	
	// Parity. ����������� ��� �������� �������� ��������� �����
	// UCSR0C = (1 << UPM01); // Enable even parity
	
	// Control and status regiter n C.
	// ��������� ������ 
	UCSR0C = (1 << UCSZ01) | (1 << UCSZ00); // Character size. ������ ������. 8 ���
	
	while(1) {
		serialWrite("Message\n", 1); // \n - ������ �������� ������
		_delay_ms(1000);
	}	
}

void serialWrite(int8_t letters[], int8_t isNewLine){	
	int i, cnt = strlen(letters);
	
	for (i = 0; i < cnt; i++) {
		serialBuffer[serialPosWrite++] = letters[i];
		
		if (serialPosWrite >= SERIAL) {
			serialPosWrite = 0;
		}
	}
	
	// UCSR0A. ������� ��������� ��������
	// UDRE0. ���� � UCSR0A ��������� � ��� ��� ������ ����� � �������� ����� ������
	if (UCSR0A & (1 << UDRE0)) {
		UDR0 = 0;
	}	
}

// ���������� ���������� �������� �����
ISR(USART_TX_vect) {
	// ���� ���� ��� ����������
	if (serialPosRead != serialPosWrite) {
		// ��������� ����� � UDR0 ������������� �������� ��� ����� USART
		UDR0 = serialBuffer[serialPosRead++];
		
		if (serialPosRead > SERIAL) {
			serialPosRead = 0;
		}
	}	
}

