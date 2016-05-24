#include <avr/io.h>
#include <stdio.h>

int main(void)
{
	char str[] = "12345";
	int i = 0;
	
	UBRRH = 25;
    UC = 0x18;
	
    while(1)
    {
		if (i > 4) {
			i = 0;
		}	
		        
	    putchar(str[i++]);
    }
}