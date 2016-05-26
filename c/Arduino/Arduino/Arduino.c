#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include <avr/sfr_defs.h>

#define F_CPU 16E6

ISR(INT1_vect) {
	int8_t i, temp = PORTB;
	PORTB = 0;
	
	for (i = 0; i <= 6; i++) {
		PORTB |= 1 << i;
		_delay_ms(3000);
	}
	
	PORTB = temp;
}

int main(void)
{
	DDRB  = 0xFF;
	PORTB = 0x00;
	
	EICRA |= (1<<ISC11);
	EIMSK |= (1<<INT1);
	
	sei();
	
    while(1)
    {
		PORTB = 0b00111111;
		_delay_ms(1000);
		PORTB = 0;
		_delay_ms(1000);	
    }
}