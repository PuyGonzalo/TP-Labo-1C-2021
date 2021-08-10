;
; MACROS.inc
;
; Created: 6/7/2021 00:40:03
; Autor : Puy Gonzalo
; Padron : 99784
;
; Este archivo contiene macros utiles para el programa.

; Esta macro inicializa el stack pointer
; Uso:		initSP	
.MACRO	initSP
			LDI dummyreg,LOW(RAMEND)
			OUT spl,dummyreg
			LDI dummyreg,HIGH(RAMEND)
			OUT sph,dummyreg
.ENDMACRO

; Esta macro inicializa los puertos correspondientes
; Uso:		initPORTS
.MACRO	initPORTS
; Puerto PB0 como salida
		LDI	dummyreg, (1<<PB0)
		OUT DDRB,dummyreg
; Puerto D como entrada
		LDI	dummyreg,0
		OUT	DDRD,dummyreg
.ENDMACRO

; Esta macro configura la interrupcion por overflow
; del Timer/Counter 1
; Uso: configTimer1
.MACRO	configTimer1
		LDI	dummyreg,(1<<TOIE1)
		STS	TIMSK1,dummyreg
		SEI
.ENDMACRO