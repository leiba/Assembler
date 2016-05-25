#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
	DDRC  = 0xFF;
	PORTC = 0x00;
	
    while(1)
    {
		_delay_ms(1000);
		PORTC |= 0b00010000;
        _delay_ms(10000);
		PORTC = 0x00;  
    }
}