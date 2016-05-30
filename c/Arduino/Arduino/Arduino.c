
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

#define F_CPU  16000000
#define BAUD   9600
#define BRC    ((F_CPU / 16 / BAUD) - 1) // Baud rate calculate
#define SERIAL 1024 // Размер Serial буффера

uint8_t serialBuffer[SERIAL];
int serialPosWrite = 0;
int serialPosRead = 0;

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
	
    // Parity. Контрольный бит проверки четности двоичного числа
    // UCSR0C = (1 << UPM01); // Enable even parity
	
    // Control and status regiter n C.
    // Настройки данных 
    UCSR0C = (1 << UCSZ01) | (1 << UCSZ00); // Character size. Размер пакета. 8 бит
	
    while(1) {
        serialWrite("Message22\n", 1); // \n - Символ переноса строки
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
	
    // UCSR0A. Регистр состояния передачи
    // UDRE0. Флаг в UCSR0A говорящий о том что буффер готов к принятию новых данных, когда 1
    if (UCSR0A & (1 << UDRE0)) {
        UDR0 = 0;
    }	
}

// Прерывания завершения передачи байта
ISR(USART_TX_vect) {
    // Если есть что передавать
    if (serialPosRead != serialPosWrite) {
        // Установка байта в UDR0 автоматически передает его через USART
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
	
	// Usart Baud Rate register. Регистры настройки бод\сек
	UBRR0H = (BRC >> 8); // Записываем 8 старших бит
	UBRR0L = BRC; // Записываем 8 младших бит
	
	// Разрешаем прерывания USART
	UCSR0B = (1 << TXEN0); // Включаем передачу через USART, отключая работу порта в обычном режиме
	UCSR0B |= (1 << TXCIE0); // Разрешаем прерывание по завершение передачи байта
	//UCSR0B |= (1 << RXEN0); // Включаем прием через USART
	//UCSR0B |= (1 << RXCIE0); // Разрешаем прерывание по завершении приема бита
	
	// Parity. Контрольный бит проверки четности двоичного числа
	// UCSR0C = (1 << UPM01); // Enable even parity
	
	// Control and status regiter n C.
	// Настройки данных 
	UCSR0C = (1 << UCSZ01) | (1 << UCSZ00); // Character size. Размер пакета. 8 бит
	
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
	
	// UCSR0A. Регистр состояния передачи
	// UDRE0. Флаг в UCSR0A говорящий о том что буффер готов к принятию новых данных
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

ISR(USART_RX_vect) {
	// Чтение из регистра приводит к получению данных
	rxBuffer[rxPosWrite++] = UDR0;
	
	if (rxPosWrite >= SERIAL) {
		rxPosWrite = 0;
	}
}
*/
