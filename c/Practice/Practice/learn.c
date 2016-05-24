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
 �������. �� ������� ���� ������, �� �������� ����, ����������� �������
*/
#include <avr/io.h>                // ����������� ����� �� ����������� ����������
#include "file.h"                  // ����������� ����� �� ��� �� ���� ��� � ����������� ���
#define MyName "Le"                // ����������� ���� "Le" ������ MeName
#define max(a, b) (a > b ? a : b); // ������. ����� n = max(3, 4);

/*
 �����
*/
DDRA |= 0b0000001;     // ��������� ����� A0 �� �����, �� ��������� 0 - ����
PORTA |= 0b00000001;   // ��������� 1 �� ������ A0
n = PINA & 0b00000001; // ������ ���� �� ������