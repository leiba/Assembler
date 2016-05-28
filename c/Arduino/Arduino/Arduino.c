#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

#define F_CPU 20000000

double pwm = 0;

int main(void)
{
	sei();
	
	DDRD = (1 << PORTD6) | (1 << PORTD5);
	
	// Compare output mode, Fast PWM mode. Режим работы ШИМ
	// Очистка счетчика, установка уровня в 0 при совпадении
	TCCR0A = (1 << COM0A1); // Clear on compare match, set bottom OCR0A
	TCCR0A |= (1 << COM0B1); // Clear on compare match, set bottom OCR0B
	
	// Waveform generation mode. Режим работы таймера
	TCCR0A |= (1 << WGM01) | (1 << WGM00); // Fast PWM
	
	// Clock select bit. Предделитель
	TCCR0B = (1 << CS00); // Предделитель 1
	
	// Output compare register
	// Регистр сравнения
	OCR0A = OCR0B = 0; // Всегда в 0. ШИМ уровень 5v, заканчивается сразу счета
	
	// Timer/Counter Interrupt mask register
    // Разрешение прерывания
	TIMSK0 = (1 << TOIE0); // Прерывание по переполнению счетчика

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

