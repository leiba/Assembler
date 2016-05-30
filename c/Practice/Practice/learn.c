/*
 Типы
*/
typedef signed char int8_t;              // -128 .. 128
typedef unsigned char uint8_t;           // 0 .. 255
typedef int int16_t;                     // -32768 .. 32767
typedef unsigned int uint16_t;           // 0 .. 65535
typedef signed long int int32_t;         // -2147483648 .. 2147483647
typedef unsigned long int uint32_t;      // 0 .. 4294967295
typedef signed long long int int64_t;    // -9223372036854775808 .. 9223372036854775807
typedef unsigned long long int uint64_t; // 0 .. 18446744073709551615

/*
 Синтаксис
*/
extern int n = 1;      // Область видимости во всех файлах
const int x = 1;       // Константа
enum(one, two, three); // Перечисление, без значений
n = sizeof(n);         // Занимаемое место в памяти в байтах, 2
func(int n);           // Прототип функции до ее определения, затычка

/*
 Статические переменные
*/
int plus5(){
    static int n; // Инициализируется как 0, заоминается значение между вызовами
    return n + 5;
}

/*
 Структуры. 
 Допускаются вложенные. 
 Могут быть параметрами и возвращаемыми значениями функций
*/
struct Date {
    int year;
    int month;
    int day;
};
struct Date myDate;             // Пустая инициализация
struct Date myDate = {28,5,90}; // Инициализация с установкой значений
myDate.day;                     // Обращение к полям струткуры

/*
 Указатели
 Может ссылатся на переменную, функцию, константу
*/
int *u;       // Указатель на целое число. 
int x = 1, y;
u = &x;       // Присваеваем указателю адрес переменной в памяти 
y = *u;       // Присваеваем переменной y, значение находящиеся по адресу указателя
*u = 2;       // Присваеваем переменной x, значение. Ложим в адрес переменной значение
u = 0xff;     // Присваеваем указателю произвольный участок памяти

/*
 Указатели как параметры функции
 Можно возвращать такми способом больше 1 значения
*/
int sum(int *a, int *b){
    int s = *a + *b; // В указателях содержатся значения
    *a = *a / s;     // Меняем значение по указателю
    *b = *b / s;     // Меняем значение по указателю
    return s;        // Возвращаемое значение
}

/*
 Указатели на структуры
*/
struct Date myDate;
struct Date *u;
u = &myDate;
u->day = 7;         // Присваивание значения по указателю
(*u).day = 7;       // Присваивание значения через разименовывание по указателю

/*
 Указатели как поля структуры
*/
struct Dates {
    int day,
    struct Dates *next
};
struct Dates myDates, myDates2;
myDates.next = &myDates2;
myDates.next->day;              // Обращение по указателю к вложенной структуре

/*
 Массивы
 Название массива, это указатель на его 0й элемент
*/
int[2] m0;         // Объявление пустого массива
int[] m1 = {0, 1}; // Объявление заполненного массива
m1[1] = 1;         // Присваивание значения элементу массива
*(m1 + 1) = 1;     // Присваивание значения элементу массива
m1[1];             // Получение значения элемента
*(m1 + 1);         // Получение значения элемента

/*
 Многомерные массивы
 Данные хранятся в памяти последовательно,
 поэтому справедливы разные способы инициализации и обращения 
*/
int[][] m = {0, 0};
int[][] m = {{0}, {0}}; // Два одинаковых объявления
m[1][0];                // Обращение к 0му элементу 1 вложенного массива
*(m + 1);               // Обращение к 0му элементу 1 вложенного массива

/*
 Строки
 Это массивы типа char
 Реальная длина на 1 больше количества символов, в конце добавляется \0
*/ 
char[] = "My String";

// Логические опреации
n = 1 << 1;                  // Разрядный сдвиг влево
n = 1 >> 1;                  // Разрядный сдвиг вправо
n = ~1;                      // Инвертирует каждый разряд 0 -> 1, 1 -> 0
n = 0b01010010 ^ 0b01011000; // 0b00001010, 1 если отличаются, 0 если совпадают
n = 0b00100100 | 0b00100001; // 0b00100101, 1 если есть хоть 1 единица
n = 0b00110000 & 0b00100000; // 0b00100000, 1 если обе 1

/*
 Установка разрядов в 1 с обнулением остальных
*/
n = (1 << 3);            // Установит 4 разряд в 1
n = (1 << 3) | (1 << 5); // Установит 4 и 6 разряд в 1
n = 0b00001000;			 // Установит 4 разряд в 1

/*
 Установка разрядов в 1 без обнуления остальных
*/
n |= (1 << 3);  		  // Установит 4 разряд в 1
n |= (1 << 3) | (1 << 5); // Установит 4 и 6 разряд в 1
n |= 0b00001000;		  // Установит 4 разряд в 1

/*
  Сброс разряда в 0 без обнуления остальных
*/
n &= ~(1 << 3)		        // Сбросит 4 разряд в 0
n &= ~(1 << 3) & ~(1 << 5); // Сбросит 4 и 6 разряд в 0
n &= 0b00001000;		    // Сбросит 4 разряд в 0

/*
 Сброс разряда в 0 с установкой в 1 остальных
*/
n = ~(1 << 3);             // Установит 4 разряд в 0, остальные в 1
n = ~(1 << 3) | ~(1 << 5); // Установит 4 и 6 разряд в 0, остальных в 1
n = 0b11110111;			   // Установит 4 разряд в 0, остальные в 1

/*
 Проверка разряда на 0
*/
if (0 == (n & (1 << 3))) {} // Проверка, что в 4-м разряде 0
if (~n & (1 << 3)) {}       // Проверка, что в 4-м разряде 0
	
/*
 Проверка разряда на 1
*/
if (0 != (n & (1 << 3))) {}        // Проверка, что в 4-м разряде 1
if (n & (1 << 3)) {}               // Проверка, что в 4-м разряде 1
if ((n & (1 << 3)) == (1 << 3)) {} // Проверка, что в 4-м разряде 1
	
/*
 Ожидание появления 1 в разряде
*/
while (~n & (1 << 3));   // Ожидание 1 в 4м разряде
while (!(n & (1 << 3))); // Ожидание 1 в 4м разряде

/*
 Ожидание появления 0 в разряде
*/
while (n & (1 << 3)); // Ожидание 0 в 4м разряде

/*
 Проверка состояния разрядов
*/
if ((n & 0b11100000) == 0b10100000) {} // Проверка разрядов 6-8 на значение 101
	
/*
 Бесконечные циклы
*/
while (1) {}
for(;;) {}

/*
 Функции ввода\вывода
*/

/*
 Директивы препроцессора
*/
#include <avr/io.h>                // Подключение файла из стандартной библиотеки
#include "file.h"                  // Подключение файла из той же апки что и исполняемый код
#define MyName "Le"                // Подстановка кода "Le" вместо MeName
#undef MyName                      // Отмена #define
#error "Error message"             // Генерация сообщения об ошибке компиляции

/*
 Макросы
 Не требуют типа данных, не забивают стек, выполняются быстрее
*/
#define max(a, b) (a > b ? a : b); // Вызов n = max(3, 4);
#define out(s) puts(#s);           // # Преобразовывает параметр в строку. Вызов out("Str");
#define concat(a, b) a ## b;       // ## Преобразовывает в конкатенацию. Вызов concat(1, 2);

/*
 Макросы с проверкой существования макросов
*/
#ifdef MyName             // Если определен макрос
    #define MyName2 "One"
#else                     // В противном случае
    #define MyName2 "Two"
#endif

#ifndef MyName            // Если не определен макрос
    #define MyName2 "One"
#else                     // В противном случае
    #define MyName2 "Two"
#endif

/*
 Макросы с условиями
*/
#if 1 == 2
    #define MyName2 "One"
#elif 1 == 3
    #define MyName2 "Two"
#else
    #error "Wrong rules"  // Генерируем сообщение об ошибке 
#endif

/*
 Макросы очистки и установки бита
*/
#define cbi(sfr, bit) (_SFR_BYTE(sfr) &= ~_BV(bit))
#define sbi(sfr, bit) (_SFR_BYTE(sfr) |= _BV(bit))

/*
 Arduino UNO
*/
1  - 
2  - 0  // PORTD |= 0b00000001
3  - 1  // PORTD |= 0b00000010
4  - 2  // PORTD |= 0b00000100
5  - 3  // PORTD |= 0b00001000 (PWM)
6  - 4  // PORTD |= 0b00010000
7  - 
8  - 
9  - 
10 - 
11 - 5  // PORTD |= 0b00100000 (PWM)
12 - 6  // PORTD |= 0b01000000 (PWM)
13 - 7  // PORTD |= 0b10000000
14 - 8  // PORTB |= 0b00000001
15 - 9  // PORTB |= 0b00000010 (PWM)
16 - 10 // PORTB |= 0b00000100 (PWM)
17 - 11 // PORTB |= 0b00001000 (PWM)
18 - 12 // PORTB |= 0b00010000
19 - 13 // PORTB |= 0b00100000
20 - 
21 - 
22 - 
23 - A0 // PORTC |= 0b00000001 (Analog)
24 - A1 // PORTC |= 0b00000010 (Analog)
25 - A2 // PORTC |= 0b00000100 (Analog)
26 - A3 // PORTC |= 0b00001000 (Analog)
27 - A4 // PORTC |= 0b00010000 (Analog)
28 - A5 // PORTC |= 0b00100000 (Analog)

/*
 Порты
*/
void main(){
    DDRB = 0x00; // Настраиваем порты B на вход
    DDRC = 0xFF; // Настраиваем порты C на выход
	
    DDRB = (1 << PORTB0); // Настраиваем порт B0 на выход
    PORTB = (1 << PORTB0); // Устанавливаем 1 на порте B0
	
    while(1) {
        PORTC = PINB; // Пишем в порты C значения портов B
    }
}

/*
 Таймеры\Счетчики
 http://eleccelerator.com/avr-timer-calculator
 
 Datasheet -> 8/16-bit timer.
   Output compare unit. Что с чем сравнивается
   Register description. Описание регистров
*/
#include <avr/interrupt.h>

int main(void)
{
    sei(); // Разрешение глобальных прерываний. Set "I" bit in Status Register
	
    // Waveform generation mode. Режим работы таймера
    TCCR0A |= (1 << WGM01); // CTC Mode. Clear timer on compare. Сброс при достижении
	
    // Clock select bit. Предделитель
    TCCR0B |= (1 << CS02) | (CS00); // Предделитель 1024
	
    // Timer counter register
    TCNT0; // Счетчик тиков
	
    // Output compare register. Регистры сравнения для прерывания
    // Для одного таймера может быть несколько 
    OCR0A = 200; // Прерывание после 200 тиков	
    OCR0B = 100; // Прерывание после 100 тиков
	
    // Timer/Counter Interrupt mask register
    // Разрешение прерывания
    TIMSK0 |= (1 << OCIE0A); // Разрешение прерывания OCR0A. Output compare match A Enabled
    TIMSK0 |= (1 << OCIE0B); // Разрешение прерывания OCR0B. Output compare match B Enabled
}

ISR(TIMER0_COMPA_vect) {
    // Совпадение OCR0A
}

ISR (TIMER0_COMPB_vect) {
    // Совпадение OCR0B
}

/*
 Fast PWM (OCnA, OCnB)
*/
#include <avr/interrupt.h>
#include <util/delay.h>

double pwm = 0;

int main(void)
{
    // Разрешаем глобальные прерывания
    sei();
	
    // Устанавливаем порты OCR0A и OCR0B, для вывода ШИМ
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
    OCR0A = OCR0B = 0; // Счетчик сравнения. При 0, Нулевая ширина импулься 5v
	
    // Timer/Counter Interrupt mask register
    // Разрешение прерывания
    TIMSK0 = (1 << TOIE0); // Прерывание по переполнению счетчика

    while (1) {
        _delay_ms(10);
		
        // Увеличиваем ширину ШИМ импульсов
        if ((pwm += 1) > 100) {
            pwm = 0;
        }
    }	
}

/*
 Analog read (ADCn)
 
 Datasheet -> Analog To Digital Converter
*/
#include <avr/interrupt.h>

double pwm = 0;

int main(void)
{
    // Разрешаем глобальные прерывания
    sei();
		
    // Multiplexer selection register
    ADMUX = (1 << REFS0); // AVcc. Сравнение входящего напряжения с питанием 5v
	
    // Input channel selection. Выбор аналогового входа
    ADMUX |= (1 << MUX0); // Порт ADC1 (PC1)
	
    // Adc control. Настройка сравнения
    ADCSRA = (1 << ADEN); // ADC Enable. Включение аналогового конвертора
	
    // Включение разрешения на прерывания аналогового конвертора
    // Сработает когда сконвертирует входное напряжение в цифру
    ADCSRA |= (1 << ADIE); 
	
    // Prescaler. Деление частоты системы и частоты пина
    ADCSRA |= (1 << ADPS0) | (1 << ADPS1) | (ADPS2); // 128
	
    // Digital input disable 
    // Выключаем работу пина как цифрового, для работы в аналоговом режиме
    DIDR0 = (1 << ADC1D);
	
    // Запускаем единичную конвертацию входящего напряжения в цифру
    adcConvert();
	
    while (1) {}	
}

void adcConvert()
{
    // Запускаем единичную конвертацию входящего напряжения в цифру
    ADCSRA |= (1 << ADSC);
}

ISR (ADC_vect) {
    // Чтение значение напряжения на пине
    // 0 .. 1024. ADC / 4.0 для конвертации в 0 .. 255
    pwm = ADC;
	
    // Перезапуск конвертации
    adcConvert();
}

// Обработка прерываения переполнения счетчика
ISR(TIMER0_OVF_vect) {
    // Устанавливаем сравнение для счетчика
    // Сдвигая счетчик, увеличивается длина импульса 5v
    OCR0A = OCR0B = (pwm / 100) * 255;
}

/*
 Внешние прерывания (INTn)
 Отличие INTn от PCINTn. У первых есть вектор прерывания
 
 Datasheet -> External Interrupts
*/
#include <avr/interrupt.h>

void main() {
    sei(); // Разрешаем глобальные прерывания
	
    // Control register. Настройка реакции на уровни фронт\спад
    EICRA = (1 << ISC10) | (1 << ISC11); // Реакция на нарастающий уровень порта INT1
	EICRA = (1 << ISC00) | (1 << ISC01); // Реакция на нарастающий уровень порта INT0
	
    // External interrupt mask register. Разрешение прерываний в портах
    EIMSK = (1 << INT0) | (1 << INT1);  // Разрешение прерывания на портах INT0 и INT1	
}

ISR(INT0_vect) {
    // Прерывание INT0
}
	
ISR(INT1_vect) {
    // Прерывание INT1
}

/*
 Serial TX (TXD)
 
 Datasheet -> USART
*/
#include <avr/io.h>
#include <avr/interrupt.h>

#define F_CPU  16000000
#define BAUD   9600
#define BRC    ((F_CPU / 16 / BAUD) - 1) // Baud rate calculate
#define SERIAL 1024 // Размер Serial буффера

int8_t serialBuffer[SERIAL];
int serialPosWrite = 0;
int serialPosRead = 0;

int main(void)
{
    // Разрешение глобальных прерываний
    sei();
	
    // Usart Baud Rate register. Регистры настройки бод\сек
    UBRR0H = (BRC >> 8); // Записываем 8 старших бит
    UBRR0L = BRC; // Записываем 8 младших бит
	
    // Разрешаем прерывания USART
    UCSR0B = (1 << TXEN0); // Включаем передачу через USART, отключая работу порта в обычном режиме
	UCSR0B |= (1 << TXCIE0); // Разрешаем прерывание по завершение передачи байта
	
    // Parity. Контрольный бит проверки четности двоичного числа
    // UCSR0C = (1 << UPM01); // Enable even parity
	
    // Control and status regiter n C.
    // Настройки данных 
    UCSR0C = (1 << UCSZ01) | (1 << UCSZ00); // Character size. Размер пакета. 8 бит
	
    while(1) {
        serialWrite("Message\n", 1); // \n - Символ переноса строки
    }	
}

void serialWrite(int8_t letters[], int8_t isNewLine){	
    int i, cnt = strlen(letters);
	
    for (i = 0; i < cnt; i++) {
        serialBuffer[serialPosWrite++] = letters[i];
		
        if (serialPosWrite >= SERIAL) {
            serialPosWrite = 0;
        }
    }
	
    // UCSR0A. Регистр состояния передачи
    // UDRE0. Флаг в UCSR0A говорящий о том что буффер готов к принятию новых данных, когда 1
    if (UCSR0A & (1 << UDRE0)) {
        UDR0 = 0;
    }	
}

// Прерывания завершения передачи байта
ISR(USART_TX_vect) {
    // Если есть что передавать
    if (serialPosRead != serialPosWrite) {
        // Установка байта в UDR0 автоматически передает его через USART
        UDR0 = serialBuffer[serialPosRead++];
		
        if (serialPosRead > SERIAL) {
           serialPosRead = 0;
        }
    }	
}

http://www.nongnu.org/avr-libc/user-manual/group__avr__interrupts.html