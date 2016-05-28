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
	
	// Multiplexer selection register
	ADMUX = (1 << REFS0); // AVcc. Сравнение входящего напряжения с питанием 5v
	
	// Input channel selection. Выбор аналогового входа
	ADMUX |= (1 << MUX0); // Порт ADC1 (PC1)
	
	// Adc control. Настройка сравнения
	ADCSRA = (1 << ADEN); // ADC Enable. Включение аналогового конвертора
	
	// Включение разрешения на прерывания аналогового конвертора
	// Сработает когда сконвертирует входное напряжение в цифру
	ADCSRA |= (1 << ADIE); 
	
	ADCSRA |= (1 << ADPS0) | (1 << ADPS1) | (ADPS2); // 128
	
	// Digital input disable 
	// Выключаем работу пина как цифрового, для работы в аналоговом режиме
	DIDR0 = (1 << ADC1D);
	
	adcConvert();
	while (1) {	
	}	
}

void adcConvert()
{
	// Запускаем единичную конвертацию входящего напряжения в цифру
	ADCSRA |= (1 << ADSC);
}

ISR (ADC_vect) {
	pwm = ADC;
	adcConvert();
}

ISR(TIMER0_OVF_vect) {
	OCR0A = OCR0B = pwm;	
}

