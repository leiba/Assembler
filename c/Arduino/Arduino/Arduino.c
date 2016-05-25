#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
	DDRB  = 0xFF;
	PORTB = 0x00;
	
    while(1)
    {
		_delay_ms(1000);
		PORTB |= 0b00100000;
        _delay_ms(10000);
		PORTB = 0x00;  
    }
}