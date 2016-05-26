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
 ���������� ������ (INT0, INT1)
 
 EICRA. Datasheet -> External Interrupts. ��������� ������������ �� ������
 EIMSK. Datasheet -> External Interrupts. ���������� ����������� ����������
*/
#include <avr/interrupt.h>

ISR(INT0_vect) {}          // ��������������� ����������� ����������
void main() {
	sei();                 // ��������� ���������� ����������
	cli();                 // ��������� ���������� ����������
	EICRA |= (1 << ISC01); // ��������� ������
	EIMSK |= (1 << INT0);  // ���������� ���������� INT0	
}

/*
 �����
*/
void main(){
	DDRB = 0x00; // ����������� ����� B �� ����
	DDRC = 0xFF; // ����������� ����� C �� �����
	
	while(1) {
		PORTC = PINB; // ����� � ����� C �������� ������ B
	}
}
DDRA |= 0b0000001;     // ��������� ����� A0 �� �����, �� ��������� 0 - ����
PORTA |= 0b00000001;   // ��������� 1 �� ������ A0
n = PINA & 0b00000001; // ������ ���� �� ������

http://www.nongnu.org/avr-libc/user-manual/group__avr__interrupts.html