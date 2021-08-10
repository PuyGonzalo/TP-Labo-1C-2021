;
; Macros2.inc
;
; Este archivo contiene Macros utiles para el progama. 
;
;  Created: 5/6/2021 01:43:15
;  Autor  : Puy Gonzalo
;	Padron : 99784


 ; Esta macro inicializa el puntero Z a una posicion en ROM
; Uso:		initZ	<Etiqueta>
.MACRO	initZ
			LDI		ZH,HIGH(@0<<1) 
			LDI		ZL,LOW(@0<<1)
.ENDMACRO


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
; Puerto PB0-4 como salida
		LDI	dummyreg,0x0F
		OUT DDRB,dummyreg
;Puerto D como salida salvo PD0
		LDI	dummyreg,0xFE
		OUT	DDRD,dummyreg
.ENDMACRO



; Esta macro configura USART0
;
.MACRO	initUSART
		;Seteo Baud Rate en 96000 bps
		LDI	dummyreg,BAUDRATEH
		STS UBRR0H,dummyreg
		LDI dummyreg,BAUDRATEL
		STS	UBRR0L,dummyreg
;Activo Transmisor, receptor e interrupcion para el receptor.
		LDI	dummyreg, (1<<RXCIE0) | (1<<RXEN0) | (1<<TXEN0)
		STS	UCSR0B,dummyreg
; Asincronico, Datos 8N1 (8-bits de datos, sin paridad y 1 bit de stop).
		LDI	dummyreg,6
		STS	UCSR0C,dummyreg
; Activo interrupciones globales
		SEI
.ENDMACRO

