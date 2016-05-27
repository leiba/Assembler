#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

#define F_CPU 20000000

int a = 0, b = 0;

ISR (TIMER0_COMPA_vect) {
	if (a++ > 100) {
		PORTB ^= (1 << PORTB0);
		a = 0;
	}
}
	
ISR (TIMER0_COMPB_vect) {
	if (b++ > 50) {
		PORTB ^= (1 << PORTB1);
		b = 0;
	}	
}

int main(void)
{
	DDRB = 0xFF;
	
	sei();
	TCCR0A = (1 << WGM01);
	TCCR0B = (1 << CS02) | (1 << CS00);
	
	OCR0A  = 195;
	OCR0B  = 195; 
	
	TIMSK0 = (1 << OCIE0A) | (1 << OCIE0B);	

	while (1) {}	
}

