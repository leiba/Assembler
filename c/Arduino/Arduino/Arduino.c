
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

#define F_CPU  16000000
#define BAUD   9600
#define BRC    ((F_CPU / 16 / BAUD) - 1) // Baud rate calculate
#define SERIAL 1024 // ������ Serial �������

uint8_t serialBuffer[SERIAL];
int serialPosWrite = 0;
int serialPosRead = 0;

int main(void)
{
    // ���������� ���������� ����������
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
        serialWrite("Message22\n", 1); // \n - ������ �������� ������
		_delay_ms(2000);
    }	
}

void serialWrite(uint8_t letters[], int8_t isNewLine){	
    int i, cnt = strlen(letters);
	
    for (i = 0; i < cnt; i++) {
        serialBuffer[serialPosWrite++] = letters[i];
		
        if (serialPosWrite >= SERIAL) {
            serialPosWrite = 0;
        }
    }
	
    // UCSR0A. ������� ��������� ��������
    // UDRE0. ���� � UCSR0A ��������� � ��� ��� ������ ����� � �������� ����� ������, ����� 1
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
		
        if (serialPosRead >= SERIAL) {
           serialPosRead = 0;
        }
    }	
}

/*
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

#define cbi(sfr, bit) (_SFR_BYTE(sfr) &= ~_BV(bit))
#define sbi(sfr, bit) (_SFR_BYTE(sfr) |= _BV(bit))

#define F_CPU  16000000
#define BAUD   9600
#define BRC    ((F_CPU / 16 / BAUD) - 1) // Baud rate calculate
#define SERIAL 1024

uint8_t txBuffer[SERIAL];
int txPosWrite = 0;
int txPosRead = 0;

uint8_t rxBuffer[SERIAL];
int rxPosWrite = 0;
int rxPosRead = 0;

void serialWrite(uint8_t letters[]);
uint8_t serialAvailable();
uint8_t serialRead();

int main(void)
{
	sei();
	
	// Usart Baud Rate register. �������� ��������� ���\���
	UBRR0H = (BRC >> 8); // ���������� 8 ������� ���
	UBRR0L = BRC; // ���������� 8 ������� ���
	
	// ��������� ���������� USART
	UCSR0B = (1 << TXEN0); // �������� �������� ����� USART, �������� ������ ����� � ������� ������
	UCSR0B |= (1 << TXCIE0); // ��������� ���������� �� ���������� �������� �����
	//UCSR0B |= (1 << RXEN0); // �������� ����� ����� USART
	//UCSR0B |= (1 << RXCIE0); // ��������� ���������� �� ���������� ������ ����
	
	// Parity. ����������� ��� �������� �������� ��������� �����
	// UCSR0C = (1 << UPM01); // Enable even parity
	
	// Control and status regiter n C.
	// ��������� ������ 
	UCSR0C = (1 << UCSZ01) | (1 << UCSZ00); // Character size. ������ ������. 8 ���
	
	//sbi(DDRB, PORTB2);
	while(1) {
		serialWrite("Not available\n");
		_delay_ms(3000);
		
	}	
}

void serialWrite(uint8_t letters[]){	
	int i, cnt = strlen(letters);
	
	for (i = 0; i < cnt; i++) {
		txBuffer[txPosWrite++] = letters[i];
		
		if (txPosWrite >= SERIAL) {
			txPosWrite = 0;
		}
	}
	
	// UCSR0A. ������� ��������� ��������
	// UDRE0. ���� � UCSR0A ��������� � ��� ��� ������ ����� � �������� ����� ������
	if (UCSR0A & (1 << UDRE0)) {
		UDR0 = 0;
	}	
}

uint8_t serialAvailable()
{
	return rxPosRead != rxPosWrite ? 1 : 0;	
}

uint8_t serialRead()
{
	uint8_t ret = '\0';
	
	if (serialAvailable() == 1) {
		ret = rxBuffer[rxPosRead++];
		
		if (rxPosRead >= SERIAL) {
			rxPosRead = 0;
		}
	}
	
	return ret;
}

// ���������� ���������� �������� �����
ISR(USART_TX_vect) {
	// ���� ���� ��� ����������
	if (txPosRead != txPosWrite) {
		// ��������� ����� � UDR0 ������������� �������� ��� ����� USART
		UDR0 = txBuffer[txPosRead++];
		
		if (txPosRead >= SERIAL) {
			txPosRead = 0;
		}
	}	
}

ISR(USART_RX_vect) {
	// ������ �� �������� �������� � ��������� ������
	rxBuffer[rxPosWrite++] = UDR0;
	
	if (rxPosWrite >= SERIAL) {
		rxPosWrite = 0;
	}
}
*/
