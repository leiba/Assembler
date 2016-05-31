#include <avr/io.h>
#include <avr/interrupt.h>

#define F_CPU  16000000
#define BAUD   9600
#define BRC    ((F_CPU / 16 / BAUD) - 1)

uint8_t* rxRead();

int main(void)
{
    sei();
	
    UBRR0H = (BRC >> 8);
    UBRR0L = BRC;
	
    UCSR0B = (1 << TXEN0);	
    UCSR0C = (1 << UCSZ01) | (1 << UCSZ00);
	
	DDRB = (1 << PORTB2);

	while(1) {		
		txWrite("Say\n");	
    }	
}

void txWrite(uint8_t letters[]){	
    int i, cnt = strlen(letters);
	
    for (i = 0; i < cnt; i++) {
		// ∆дем, пока не будет доступен буфер вывода дл€ записи
		while (!(UCSR0A & (1 << UDRE0)));
		UDR0 = letters[i];
    }	
}