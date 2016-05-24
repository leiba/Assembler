.DSEG
		.ORG SRAM_START // Skip adresses to start SRAM
Vars1:	.byte 3

.CSEG
	
	// Go to
	JMP 0x00001    // Go to program counter 1
M1:	RJMP M1        // Go to M1 (2 bytes). PC - Current
	IJMP           // Go to (from reister pair Z {R30, R31});  
	
// Data
	.ORG 0x0008    // Skip addresses behind 0x0008. For write commands in end
	LDI R18,1      // Load 1 into register
	MOV R1,R16     // Copy byte to low register
	OUT 0x00,1     // Load 1 into I\O register
	IN  R18,0x00   // Read to register from I\O register
	LDS R16, Vars1 // Load byte from SRAM to register
	STS Vars1, R16 // Store byte from register to SRAM

// Math
	SUBI R16,(-1) // Subtraction 1

// Stack
	LDI R16,Low(RAMEND)
	OUT SPL,R16
	LDI R16,High(Ramend)
	OUT SPH,R16

	LDI R16,0
	PUSH R16   // Push into stack
	POP R16    // Pop from stack

	

// EEPROM
		LDI ZL,low(data*2)
		LDI ZH,high(data*2)
		LPM R16,Z           // Move 2 byte (Z Pair) data to R16
data:	.db 12,34,45        // Store data

// Interrupt
// If in the end of interrupt, stack is different then on start, return point been broken
		RCALL Wait // Call interrupt

Wait:	LDI R16,10 // Start
Cyc:	DEC R16
		NOP
		BRNE Cyc   // If !0
		RET	       // End. Took return address from stack top

// System interrupt (Interrupt vectors)
		.ORG $000 // Reset
		RJMP Reset
		.ORG $002 // (INT0)
		RETI
		.ORG $004 // (INT1)
		RETI
		.ORG $006
		RETI
		.ORG $006
		RETI
		.ORG $008
		RETI
		.ORG $00A
		RETI
		.ORG $00C
		RETI
		.ORG $00E
		RETI
		.ORG $010
		RETI
		.ORG $012
		RETI
		.ORG $014
		RETI
		.ORG $016
		RETI
		.ORG $018
		RETI
		.ORG $01A
		RETI
		.ORG $01C
		RETI
		.ORG $01E
		RETI
		.ORG $020
		RETI
		.ORG $022
		RETI
		.ORG $024
		RETI
		.ORG $026
		RETI
		.ORG $028
		RETI
		.ORG INT_VECTORS_SIZE

Reset:	NOP
		RETI

// Commands
		INC // Increment
		DEC // Decrement
		TST // Zero or minus

.ESEG

/*
Addresses and const:

R26 - XL
R27 - XH
R28 - YL
R29 - YH
R30 - ZL
R31 - ZH

SRAM_START - Address of SRAM START
RAMEND     - Address of SRAM END

0x0000 - 0x001F - Registers
0x0020 - 0x005F - I\O Registers (Peripherial)
0x0060 - 0x045F - OZU (SRAM)
0x00   - 0x3F   - I\O Registers, Address for IN\OUT command 