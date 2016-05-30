#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

#define cbi(sfr, bit) (_SFR_BYTE(sfr) &= ~_BV(bit))
#define sbi(sfr, bit) (_SFR_BYTE(sfr) |= _BV(bit))

#define F_CPU  16000000
#define BAUD   9600
#define BRC    ((F_CPU / 16 / BAUD) - 1) // Baud rate calculate
#define SERIAL 100 // ������ Serial �������

uint8_t txBuffer[SERIAL];
int txPosWrite = 0;
int txPosRead  = 0;

uint8_t rxBuffer[SERIAL];
int rxPosWrite = 0;
int rxPosRead  = 0;

uint8_t rxAvailable();
uint8_t rxRead();

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
	UCSR0B |= (1 << RXEN0); // �������� ����� ����� USART
	UCSR0B |= (1 << RXCIE0); // ��������� ���������� �� ���������� ������ ����
	
    // Parity. ����������� ��� �������� �������� ��������� �����
    // UCSR0C = (1 << UPM01); // Enable even parity
	
    // Control and status regiter n C.
    // ��������� ������ 
    UCSR0C = (1 << UCSZ01) | (1 << UCSZ00); // Character size. ������ ������. 8 ���
	
	sbi(DDRB, PORTB2);
int8_t c;

	while(1) {		
		if (rxAvailable() == 1) {
			c = rxRead(); // \n ��������� ������ ������
			
			if (c != '\n') {
				txWrite("Received\n");
			
				if (c == '1') {
					sbi(PORTB, PORTB2);
				} else {
					cbi(PORTB, PORTB2);
				}
			}
			
		} else {
			_delay_ms(10);
		}		
    }	
}

void txWrite(uint8_t letters[]){	
    int i, cnt = strlen(letters);
	
    for (i = 0; i < cnt; i++) {
        txBuffer[txPosWrite++] = letters[i];
		
        if (txPosWrite >= SERIAL) {
            txPosWrite = 0;
        }
    }
	
    // UCSR0A. ������� ��������� ��������
    // UDRE0. ���� � UCSR0A ��������� � ��� ��� ������ ����� � �������� ����� ������, ����� 1
    if (UCSR0A & (1 << UDRE0)) {
        UDR0 = 0;
    }	
}

uint8_t rxAvailable()
{
	return rxPosRead != rxPosWrite ? 1 : 0;	
}

uint8_t rxRead()
{
	uint8_t ret = '\0';
	
	if (rxAvailable() == 1) {
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

// ���������� ���������� ������ �����
ISR(USART_RX_vect) {
	// ������ �� �������� �������� � ��������� ������
	rxBuffer[rxPosWrite++] = UDR0;
	
	if (rxPosWrite >= SERIAL) {
		rxPosWrite = 0;
	}
}