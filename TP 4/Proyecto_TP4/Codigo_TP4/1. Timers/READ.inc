;
; READ.inc
;
; Created: 6/7/2021 00:40:03
; Autor : Puy Gonzalo
; Padron : 99784
;

READ_VALUE:
		IN		MODO_LED,PIND
		ANDI	MODO_LED,SWITCH_MASK
		CALL	DELAY
		IN		dummyreg,PIND
		ANDI	dummyreg,SWITCH_MASK
		CP		MODO_LED,dummyreg
		BRNE	READ_VALUE
		RET

; Delay hecho con Timer0 de 10ms.
DELAY:
		LDI R20,0x64
		OUT TCNT0,R20 ;load Timer0
		LDI R20,0X05
		OUT TCCR0B,R20 ;Timer0, Normal mode, int clk, 1024 prescaler
AGAIN:
		IN R20,TIFR0 ;read TIFR
		SBRS R20,TOV0 ;if TOV0 is set skip next instruction
		RJMP AGAIN
		LDI R20,0x00
		OUT TCCR0B,R20 ;stop Timer0
		LDI R20,(1<<TOV0)
		OUT TIFR0,R20 ;clear TOV0 flag
		RET