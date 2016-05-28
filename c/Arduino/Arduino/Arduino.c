#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

#define F_CPU 20000000

double pwm = 0;

int main(void)
{
	sei();
	
	DDRD = (1 << PORTD6) | (1 << PORTD5);
	
	// Compare output mode, Fast PWM mode. ����� ������ ���
	// ������� ��������, ��������� ������ � 0 ��� ����������
	TCCR0A = (1 << COM0A1); // Clear on compare match, set bottom OCR0A
	TCCR0A |= (1 << COM0B1); // Clear on compare match, set bottom OCR0B
	
	// Waveform generation mode. ����� ������ �������
	TCCR0A |= (1 << WGM01) | (1 << WGM00); // Fast PWM
	
	// Clock select bit. ������������
	TCCR0B = (1 << CS00); // ������������ 1
	
	// Output compare register
	// ������� ���������
	OCR0A = OCR0B = 0; // ������ � 0. ��� ������� 5v, ������������� ����� �����
	
	// Timer/Counter Interrupt mask register
    // ���������� ����������
	TIMSK0 = (1 << TOIE0); // ���������� �� ������������ ��������

	while (1) {
		_delay_ms(10);
		
		if ((pwm += 1) > 100) {
			pwm = 0;
		}
	}	
}

ISR(TIMER0_OVF_vect) {
	OCR0A = OCR0B = (pwm / 100) * 255;	
}

