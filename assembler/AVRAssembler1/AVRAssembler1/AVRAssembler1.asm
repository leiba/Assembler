.include "m8def.inc"
.include "c_macro.inc"

.DSEG

.CSEG
		INTERRUPT

IRx:	IN R16,UDR
		RETI
			
IReset:	STACK
		INTERRUPT_GLOBAL

M1:		LDI R16,11
		NOP	
		NOP
		NOP
		RJMP M1			
.ESEG