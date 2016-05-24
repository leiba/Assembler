// Init stack
.MACRO STACK
	LDI R16,Low(RAMEND)
	OUT SPL,R16
	LDI R16,High(RAMEND)
	OUT SPH,R16
.ENDM

// Global interrupt
.MACRO INTERRUPT_GLOBAL
	SEI                // Access for global interrupts, CLI - Denied
	LDI R16,(1<<RXCIE) // Access for interrupts when byte reciving
	OUT UCSRB,R16
.ENDM

// Interrupt
.MACRO INTERRUPT
	.ORG $000 // Reset
	RJMP IReset
	.ORG $001 // (INT0)
	RETI
	.ORG $002 // (INT1)
	RETI
	.ORG $003 // (TIMER2, COMP)
	RETI
	.ORG $004 // (TIMER2, OVF)
	RETI
	.ORG $005 // (TIMER1, CAPT)
	RETI
	.ORG $006 // (TIMER1, COMPA)
	RETI
	.ORG $007 // (TIMER1, COMPB)
	RETI
	.ORG $008 // (TIMER1, OVF)
	RETI
	.ORG $009 // (TIMER0, OVF)
	RETI
	.ORG $00A // (SPI, STC)
	RETI
	.ORG $00B // (USART, RXC)
	RJMP IRx
	//RETI
	.ORG $00C
	RETI
	.ORG $00D
	RETI
	.ORG $00E
	RETI
	.ORG $00F
	RETI
	.ORG $010
	RETI
	.ORG $011
	RETI
	.ORG $012
	RETI
	.ORG INT_VECTORS_SIZE
.ENDM

// Macro for set value in low register
.MACRO LLDI
	PUSH R17
	LDI R17,@1
	MOV @0,R17
	POP R17
.ENDM 

