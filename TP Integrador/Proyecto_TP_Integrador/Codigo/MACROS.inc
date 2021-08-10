;
; MACROS.inc
;
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

; Esta macro inicializa el puntero X a una posicion en RAM
; Uso:		initX	<Etiqueta>
.MACRO	initX
			LDI		XH,HIGH(@0) 
			LDI		XL,LOW(@0)	
.ENDMACRO

; :::::::::: PUERTOS :::::::::::: 

; Esta macro inicializa los puertos correspondientes
; Uso:		initPORTS
.MACRO	initPORTS
; Puerto PD5 como salida (OC0B). 
; Puerto PB0 como entrada (ICP1). 
; Pin PC0 (ADC0) como entrada.
		LDI	dummyreg, (0<<PB0)
		OUT	DDRB,dummyreg
		LDI	dummyreg, (1<<PB0)
		OUT	PORTB,dummyreg
		LDI	dummyreg, (1<<PD5)
		OUT	DDRD, dummyreg
		LDI	dummyreg, (0<<PC0)
		OUT	DDRC,dummyreg
.ENDMACRO

; :::::::::: TIMERS :::::::::: 

; Estas macros configuran el Timer/Counter 1 y el Timer/Counter 0

; Timer0: Modo Fast PWM no-invertido (Modo 3) Con prescaler de 1024
; Onda generada: f = 50 Hz, Duty Cycle = 50%

; Timer1: Modo normal, OC1A y OC1B desactivados. Seteo input capture

; Configuracion Timer0
;

.MACRO	initTimer0
		LDI	dummyreg, (0<<COM0A1) | (0<<COM0A0) | (1<<COM0B1) | (0<<COM0B0) | (1<<WGM01) | (1<<WGM00)
		OUT	TCCR0A,dummyreg
		LDI	dummyreg, (0<<WGM02) | (1<<CS02) | (0<<CS01) | (1<<CS00)
		OUT	TCCR0B,dummyreg
		LDI	dummyreg, OCR0B_VALUE
		OUT	OCR0B,dummyreg
.ENDMACRO

; Esta macro apaga el Timer0
; Uso: turn_off_Timer0

.MACRO	turn_off_Timer0
		LDI		dummyreg,0
		OUT		TCCR0B,dummyreg
.ENDMACRO

; Configuracion Timer1
;

.MACRO	initTimer1
		LDI	dummyreg, (0<<COM1A1) | (0<<COM1A0) | (0<<COM1B1) | (0<<COM1B0) | (0<<WGM11) | (0<<WGM10)
		STS TCCR1A,dummyreg
		LDI	dummyreg,(0<<ICNC1) | (1<<ICES1) | (0<<WGM13) | (0<<WGM12) | (0<<CS12) | (1<<CS11) | (0<<CS10)
		STS	TCCR1B,dummyreg
.ENDMACRO

; Esta macro apaga el Timer1
;

.MACRO	turn_off_Timer1
		LDI		dummyreg,0
		STS		TCCR1B,dummyreg
.ENDMACRO

; :::::::: Puerto Serie ::::::::::

; Esta macro configura USART0
; Uso: initUSART

.MACRO	initUSART
;Seteo Baud Rate en 96000 bps
		LDI	dummyreg,BAUDRATEH
		STS UBRR0H,dummyreg
		LDI dummyreg,BAUDRATEL
		STS	UBRR0L,dummyreg
;Activo Transmisor y receptor.
		LDI	dummyreg, (1<<RXEN0) | (1<<TXEN0)
		STS	UCSR0B,dummyreg
; Asincronico, Datos 8N1 (8-bits de datos, sin paridad y 1 bit de stop).
		LDI	dummyreg,6
		STS	UCSR0C,dummyreg
.ENDMACRO

; ::::::::::::: ADC :::::::::::::::

;Estas macros configuran todo lo correspondiente al ADC

.MACRO	initADC
	LDI	dummyreg, ADMUX_MASK
	STS	ADMUX,dummyreg
	LDI	dummyreg, ADCSRA_MASK
	STS	ADCSRA,dummyreg
	LDI	dummyreg, ADCSRB_MASK
	STS	ADCSRB, dummyreg
.ENDMACRO

.MACRO	turn_off_ADC
	LDI	dummyreg, 0
	STS ADCSRA,dummyreg
.ENDMACRO