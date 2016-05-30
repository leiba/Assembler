#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

#define cbi(sfr, bit) (_SFR_BYTE(sfr) &= ~_BV(bit))
#define sbi(sfr, bit) (_SFR_BYTE(sfr) |= _BV(bit))

#define F_CPU  16000000
#define BAUD   9600
#define BRC    ((F_CPU / 16 / BAUD) - 1) // Baud rate calculate
#define SERIAL 100 // Размер Serial буффера

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
    // Разрешение глобальных прерываний
    sei();
	
    // Usart Baud Rate register. Регистры настройки бод\сек
    UBRR0H = (BRC >> 8); // Записываем 8 старших бит
    UBRR0L = BRC; // Записываем 8 младших бит
	
    // Разрешаем прерывания USART
    UCSR0B = (1 << TXEN0); // Включаем передачу через USART, отключая работу порта в обычном режиме
	UCSR0B |= (1 << TXCIE0); // Разрешаем прерывание по завершение передачи байта
	UCSR0B |= (1 << RXEN0); // Включаем прием через USART
	UCSR0B |= (1 << RXCIE0); // Разрешаем прерывание по завершении приема бита
	
    // Parity. Контрольный бит проверки четности двоичного числа
    // UCSR0C = (1 << UPM01); // Enable even parity
	
    // Control and status regiter n C.
    // Настройки данных 
    UCSR0C = (1 << UCSZ01) | (1 << UCSZ00); // Character size. Размер пакета. 8 бит
	
	sbi(DDRB, PORTB2);
int8_t c;

	while(1) {		
		if (rxAvailable() == 1) {
			c = rxRead(); // \n Последний символ строки
			
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
	
    // UCSR0A. Регистр состояния передачи
    // UDRE0. Флаг в UCSR0A говорящий о том что буффер готов к принятию новых данных, когда 1
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

// Прерывания завершения передачи байта
ISR(USART_TX_vect) {
    // Если есть что передавать
    if (txPosRead != txPosWrite) {
        // Установка байта в UDR0 автоматически передает его через USART
        UDR0 = txBuffer[txPosRead++];
		
        if (txPosRead >= SERIAL) {
           txPosRead = 0;
        }
    }	
}

// Прерывания завершения приема байта
ISR(USART_RX_vect) {
	// Чтение из регистра приводит к получению данных
	rxBuffer[rxPosWrite++] = UDR0;
	
	if (rxPosWrite >= SERIAL) {
		rxPosWrite = 0;
	}
}