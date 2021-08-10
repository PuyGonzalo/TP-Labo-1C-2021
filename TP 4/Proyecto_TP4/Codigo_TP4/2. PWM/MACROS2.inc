;
; MACROS2.inc
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
; Puerto PD2, PD3 como entrada (interrupcion) Puerto PD5 como salida (OC0B).
		LDI	dummyreg,(0<<PD2) | (0<<PD3) | (1<<PD5)
		OUT	DDRD,dummyreg
.ENDMACRO

; Esta macro setea la interrupcion externa en INT0 e INT1
; Uso: setINT0
.macro setInt
		LDI	dummyreg, (1<<ISC11) | (1<<ISC10) | (1<<ISC01) | (1<<ISC00)
		STS	EICRA,dummyreg
		LDI	dummyreg, (1<<INT1) | (1<<INT0)
		OUT	EIMSK,dummyreg
		SEI
.endmacro

; Esta macro configura el Timer/Counter 0
; Modo Fast PWM no-invertido con prescaler de 1024
; Uso: configTimer0
.MACRO	configTimer0
		LDI	dummyreg, (1<<COM0B1) | (0<<COM0B0) | (1<<WGM01) | (1<<WGM00)
		OUT	TCCR0A,dummyreg
		LDI	dummyreg, (0<<WGM02) | (1<<CS02) | (0<<CS01) | (1<<CS00)
		OUT	TCCR0B,dummyreg
.ENDMACRO