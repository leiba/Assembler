#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

#define F_CPU 16E6

ISR (TIMER0_COMPA_vect) {
	PORTB ^= PORTB0;
	_delay_ms(1000);
}
	
ISR (TIMER0_COMPB_vect) {
	PORTB ^= PORTB1;
	_delay_ms(1000);
}

int main(void)
{
	DDRB = 0xFF;
	
	sei();
	TCCR0A = (1 << WGM01);
	TCCR0B = (1 << CS02) | (1 << CS00);
	
	OCR0A  = 200;
	OCR0B  = 200; 
	
	TIMSK0 = (1 << OCIE0A) | (1 << OCIE0B);	

	while (1) {}	
}

