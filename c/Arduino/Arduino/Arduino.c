#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

#define F_CPU 20000000

double pwm = 0;

int main(void)
{
	sei();
	//PORTC0
	
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
	
	// Multiplexer selection register
	ADMUX = (1 << REFS0); // AVcc. ��������� ��������� ���������� � �������� 5v
	
	// Input channel selection. ����� ����������� �����
	ADMUX |= (1 << MUX0); // ���� ADC1 (PC1)
	
	// Adc control. ��������� ���������
	ADCSRA = (1 << ADEN); // ADC Enable. ��������� ����������� ����������
	
	// ��������� ���������� �� ���������� ����������� ����������
	// ��������� ����� ������������� ������� ���������� � �����
	ADCSRA |= (1 << ADIE); 
	
	ADCSRA |= (1 << ADPS0) | (1 << ADPS1) | (ADPS2); // 128
	
	// Digital input disable 
	// ��������� ������ ���� ��� ���������, ��� ������ � ���������� ������
	DIDR0 = (1 << ADC1D);
	
	adcConvert();
	while (1) {	
	}	
}

void adcConvert()
{
	// ��������� ��������� ����������� ��������� ���������� � �����
	ADCSRA |= (1 << ADSC);
}

ISR (ADC_vect) {
	pwm = ADC;
	adcConvert();
}

ISR(TIMER0_OVF_vect) {
	OCR0A = OCR0B = pwm;	
}

