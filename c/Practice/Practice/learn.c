/*
 ����
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
 ���������
*/
extern int n = 1;      // ������� ��������� �� ���� ������
const int x = 1;       // ���������
enum(one, two, three); // ������������, ��� ��������
n = sizeof(n);         // ���������� ����� � ������ � ������, 2
func(int n);           // �������� ������� �� �� �����������, �������

/*
 ����������� ����������
*/
int plus5(){
    static int n; // ���������������� ��� 0, ����������� �������� ����� ��������
    return n + 5;
}

/*
 ���������. 
 ����������� ���������. 
 ����� ���� ����������� � ������������� ���������� �������
*/
struct Date {
    int year;
    int month;
    int day;
};
struct Date myDate;             // ������ �������������
struct Date myDate = {28,5,90}; // ������������� � ���������� ��������
myDate.day;                     // ��������� � ����� ���������

/*
 ���������
 ����� �������� �� ����������, �������, ���������
*/
int *u;       // ��������� �� ����� �����. 
int x = 1, y;
u = &x;       // ����������� ��������� ����� ���������� � ������ 
y = *u;       // ����������� ���������� y, �������� ����������� �� ������ ���������
*u = 2;       // ����������� ���������� x, ��������. ����� � ����� ���������� ��������
u = 0xff;     // ����������� ��������� ������������ ������� ������

/*
 ��������� ��� ��������� �������
 ����� ���������� ����� �������� ������ 1 ��������
*/
int sum(int *a, int *b){
    int s = *a + *b; // � ���������� ���������� ��������
    *a = *a / s;     // ������ �������� �� ���������
    *b = *b / s;     // ������ �������� �� ���������
    return s;        // ������������ ��������
}

/*
 ��������� �� ���������
*/
struct Date myDate;
struct Date *u;
u = &myDate;
u->day = 7;         // ������������ �������� �� ���������
(*u).day = 7;       // ������������ �������� ����� ��������������� �� ���������

/*
 ��������� ��� ���� ���������
*/
struct Dates {
    int day,
    struct Dates *next
};
struct Dates myDates, myDates2;
myDates.next = &myDates2;
myDates.next->day;              // ��������� �� ��������� � ��������� ���������

/*
 �������
 �������� �������, ��� ��������� �� ��� 0� �������
*/
int[2] m0;         // ���������� ������� �������
int[] m1 = {0, 1}; // ���������� ������������ �������
m1[1] = 1;         // ������������ �������� �������� �������
*(m1 + 1) = 1;     // ������������ �������� �������� �������
m1[1];             // ��������� �������� ��������
*(m1 + 1);         // ��������� �������� ��������

/*
 ����������� �������
 ������ �������� � ������ ���������������,
 ������� ����������� ������ ������� ������������� � ��������� 
*/
int[][] m = {0, 0};
int[][] m = {{0}, {0}}; // ��� ���������� ����������
m[1][0];                // ��������� � 0�� �������� 1 ���������� �������
*(m + 1);               // ��������� � 0�� �������� 1 ���������� �������

/*
 ������
 ��� ������� ���� char
 �������� ����� �� 1 ������ ���������� ��������, � ����� ����������� \0
*/ 
char[] = "My String";

// ���������� ��������
n = 1 << 1;                  // ��������� ����� �����
n = 1 >> 1;                  // ��������� ����� ������
n = ~1;                      // ����������� ������ ������ 0 -> 1, 1 -> 0
n = 0b01010010 ^ 0b01011000; // 0b00001010, 1 ���� ����������, 0 ���� ���������
n = 0b00100100 | 0b00100001; // 0b00100101, 1 ���� ���� ���� 1 �������
n = 0b00110000 & 0b00100000; // 0b00100000, 1 ���� ��� 1

/*
 ��������� �������� � 1 � ���������� ���������
*/
n = (1 << 3);            // ��������� 4 ������ � 1
n = (1 << 3) | (1 << 5); // ��������� 4 � 6 ������ � 1
n = 0b00001000;			 // ��������� 4 ������ � 1

/*
 ��������� �������� � 1 ��� ��������� ���������
*/
n |= (1 << 3);  		  // ��������� 4 ������ � 1
n |= (1 << 3) | (1 << 5); // ��������� 4 � 6 ������ � 1
n |= 0b00001000;		  // ��������� 4 ������ � 1

/*
  ����� ������� � 0 ��� ��������� ���������
*/
n &= ~(1 << 3)		        // ������� 4 ������ � 0
n &= ~(1 << 3) & ~(1 << 5); // ������� 4 � 6 ������ � 0
n &= 0b00001000;		    // ������� 4 ������ � 0

/*
 ����� ������� � 0 � ���������� � 1 ���������
*/
n = ~(1 << 3);             // ��������� 4 ������ � 0, ��������� � 1
n = ~(1 << 3) | ~(1 << 5); // ��������� 4 � 6 ������ � 0, ��������� � 1
n = 0b11110111;			   // ��������� 4 ������ � 0, ��������� � 1

/*
 �������� ������� �� 0
*/
if (0 == (n & (1 << 3))) {} // ��������, ��� � 4-� ������� 0
if (~n & (1 << 3)) {}       // ��������, ��� � 4-� ������� 0
	
/*
 �������� ������� �� 1
*/
if (0 != (n & (1 << 3))) {}        // ��������, ��� � 4-� ������� 1
if (n & (1 << 3)) {}               // ��������, ��� � 4-� ������� 1
if ((n & (1 << 3)) == (1 << 3)) {} // ��������, ��� � 4-� ������� 1
	
/*
 �������� ��������� 1 � �������
*/
while (~n & (1 << 3));   // �������� 1 � 4� �������
while (!(n & (1 << 3))); // �������� 1 � 4� �������

/*
 �������� ��������� 0 � �������
*/
while (n & (1 << 3)); // �������� 0 � 4� �������

/*
 �������� ��������� ��������
*/
if ((n & 0b11100000) == 0b10100000) {} // �������� �������� 6-8 �� �������� 101
	
/*
 ����������� �����
*/
while (1) {}
for(;;) {}

/*
 ������� �����\������
*/

/*
 ��������� �������������
*/
#include <avr/io.h>                // ����������� ����� �� ����������� ����������
#include "file.h"                  // ����������� ����� �� ��� �� ���� ��� � ����������� ���
#define MyName "Le"                // ����������� ���� "Le" ������ MeName
#undef MyName                      // ������ #define
#error "Error message"             // ��������� ��������� �� ������ ����������

/*
 �������
 �� ������� ���� ������, �� �������� ����, ����������� �������
*/
#define max(a, b) (a > b ? a : b); // ����� n = max(3, 4);
#define out(s) puts(#s);           // # ��������������� �������� � ������. ����� out("Str");
#define concat(a, b) a ## b;       // ## ��������������� � ������������. ����� concat(1, 2);

/*
 ������� � ��������� ������������� ��������
*/
#ifdef MyName             // ���� ��������� ������
    #define MyName2 "One"
#else                     // � ��������� ������
    #define MyName2 "Two"
#endif

#ifndef MyName            // ���� �� ��������� ������
    #define MyName2 "One"
#else                     // � ��������� ������
    #define MyName2 "Two"
#endif

/*
 ������� � ���������
*/
#if 1 == 2
    #define MyName2 "One"
#elif 1 == 3
    #define MyName2 "Two"
#else
    #error "Wrong rules"  // ���������� ��������� �� ������ 
#endif

/*
 ������� ������� � ��������� ����
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
 �����
*/
void main(){
    DDRB = 0x00; // ����������� ����� B �� ����
    DDRC = 0xFF; // ����������� ����� C �� �����
	
    DDRB = (1 << PORTB0); // ����������� ���� B0 �� �����
    PORTB = (1 << PORTB0); // ������������� 1 �� ����� B0
	
    while(1) {
        PORTC = PINB; // ����� � ����� C �������� ������ B
    }
}

/*
 �������\��������
 http://eleccelerator.com/avr-timer-calculator
 
 Datasheet -> 8/16-bit timer.
   Output compare unit. ��� � ��� ������������
   Register description. �������� ���������
*/
#include <avr/interrupt.h>

int main(void)
{
    sei(); // ���������� ���������� ����������. Set "I" bit in Status Register
	
    // Waveform generation mode. ����� ������ �������
    TCCR0A |= (1 << WGM01); // CTC Mode. Clear timer on compare. ����� ��� ����������
	
    // Clock select bit. ������������
    TCCR0B |= (1 << CS02) | (CS00); // ������������ 1024
	
    // Timer counter register
    TCNT0; // ������� �����
	
    // Output compare register. �������� ��������� ��� ����������
    // ��� ������ ������� ����� ���� ��������� 
    OCR0A = 200; // ���������� ����� 200 �����	
    OCR0B = 100; // ���������� ����� 100 �����
	
    // Timer/Counter Interrupt mask register
    // ���������� ����������
    TIMSK0 |= (1 << OCIE0A); // ���������� ���������� OCR0A. Output compare match A Enabled
    TIMSK0 |= (1 << OCIE0B); // ���������� ���������� OCR0B. Output compare match B Enabled
}

ISR(TIMER0_COMPA_vect) {
    // ���������� OCR0A
}

ISR (TIMER0_COMPB_vect) {
    // ���������� OCR0B
}

/*
 Fast PWM (OCnA, OCnB)
*/
#include <avr/interrupt.h>
#include <util/delay.h>

double pwm = 0;

int main(void)
{
    // ��������� ���������� ����������
    sei();
	
    // ������������� ����� OCR0A � OCR0B, ��� ������ ���
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
    OCR0A = OCR0B = 0; // ������� ���������. ��� 0, ������� ������ �������� 5v
	
    // Timer/Counter Interrupt mask register
    // ���������� ����������
    TIMSK0 = (1 << TOIE0); // ���������� �� ������������ ��������

    while (1) {
        _delay_ms(10);
		
        // ����������� ������ ��� ���������
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
    // ��������� ���������� ����������
    sei();
		
    // Multiplexer selection register
    ADMUX = (1 << REFS0); // AVcc. ��������� ��������� ���������� � �������� 5v
	
    // Input channel selection. ����� ����������� �����
    ADMUX |= (1 << MUX0); // ���� ADC1 (PC1)
	
    // Adc control. ��������� ���������
    ADCSRA = (1 << ADEN); // ADC Enable. ��������� ����������� ����������
	
    // ��������� ���������� �� ���������� ����������� ����������
    // ��������� ����� ������������� ������� ���������� � �����
    ADCSRA |= (1 << ADIE); 
	
    // Prescaler. ������� ������� ������� � ������� ����
    ADCSRA |= (1 << ADPS0) | (1 << ADPS1) | (ADPS2); // 128
	
    // Digital input disable 
    // ��������� ������ ���� ��� ���������, ��� ������ � ���������� ������
    DIDR0 = (1 << ADC1D);
	
    // ��������� ��������� ����������� ��������� ���������� � �����
    adcConvert();
	
    while (1) {}	
}

void adcConvert()
{
    // ��������� ��������� ����������� ��������� ���������� � �����
    ADCSRA |= (1 << ADSC);
}

ISR (ADC_vect) {
    // ������ �������� ���������� �� ����
    // 0 .. 1024. ADC / 4.0 ��� ����������� � 0 .. 255
    pwm = ADC;
	
    // ���������� �����������
    adcConvert();
}

// ��������� ����������� ������������ ��������
ISR(TIMER0_OVF_vect) {
    // ������������� ��������� ��� ��������
    // ������� �������, ������������� ����� �������� 5v
    OCR0A = OCR0B = (pwm / 100) * 255;
}

/*
 ������� ���������� (INTn)
 ������� INTn �� PCINTn. � ������ ���� ������ ����������
 
 Datasheet -> External Interrupts
*/
#include <avr/interrupt.h>

void main() {
    sei(); // ��������� ���������� ����������
	
    // Control register. ��������� ������� �� ������ �����\����
    EICRA = (1 << ISC10) | (1 << ISC11); // ������� �� ����������� ������� ����� INT1
	EICRA = (1 << ISC00) | (1 << ISC01); // ������� �� ����������� ������� ����� INT0
	
    // External interrupt mask register. ���������� ���������� � ������
    EIMSK = (1 << INT0) | (1 << INT1);  // ���������� ���������� �� ������ INT0 � INT1	
}

ISR(INT0_vect) {
    // ���������� INT0
}
	
ISR(INT1_vect) {
    // ���������� INT1
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
#define SERIAL 1024 // ������ Serial �������

int8_t serialBuffer[SERIAL];
int serialPosWrite = 0;
int serialPosRead = 0;

int main(void)
{
    // ���������� ���������� ����������
    sei();
	
    // Usart Baud Rate register. �������� ��������� ���\���
    UBRR0H = (BRC >> 8); // ���������� 8 ������� ���
    UBRR0L = BRC; // ���������� 8 ������� ���
	
    // ��������� ���������� USART
    UCSR0B = (1 << TXEN0); // �������� �������� ����� USART, �������� ������ ����� � ������� ������
	UCSR0B |= (1 << TXCIE0); // ��������� ���������� �� ���������� �������� �����
	
    // Parity. ����������� ��� �������� �������� ��������� �����
    // UCSR0C = (1 << UPM01); // Enable even parity
	
    // Control and status regiter n C.
    // ��������� ������ 
    UCSR0C = (1 << UCSZ01) | (1 << UCSZ00); // Character size. ������ ������. 8 ���
	
    while(1) {
        serialWrite("Message\n", 1); // \n - ������ �������� ������
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
	
    // UCSR0A. ������� ��������� ��������
    // UDRE0. ���� � UCSR0A ��������� � ��� ��� ������ ����� � �������� ����� ������, ����� 1
    if (UCSR0A & (1 << UDRE0)) {
        UDR0 = 0;
    }	
}

// ���������� ���������� �������� �����
ISR(USART_TX_vect) {
    // ���� ���� ��� ����������
    if (serialPosRead != serialPosWrite) {
        // ��������� ����� � UDR0 ������������� �������� ��� ����� USART
        UDR0 = serialBuffer[serialPosRead++];
		
        if (serialPosRead > SERIAL) {
           serialPosRead = 0;
        }
    }	
}

http://www.nongnu.org/avr-libc/user-manual/group__avr__interrupts.html