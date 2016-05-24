#include <avr/io.h>

int main(void)
{
	DDRD  = 0x7F;
	PORTD = 0x7F;
	TCNT0 = 0;
	TCCR0 = 0x05;
	
    while(1)
    {
		if (TCNT0 == 0x00) {
			PORTD = 0x7F;	
		} else {
			PORTD = 0x00;
		}        
    }
}