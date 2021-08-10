 ;
 ; Macros.inc
 ;
 ;  Created: 5/6/2021 01:43:15
 ;  Autor  : Puy Gonzalo
 ;	Padron : 99784
 ; 

; Esta macro inicializa el puntero Z a una posicion en ROM
; Uso:		initZ	<Etiqueta>
.macro	initZ
			ldi		Zh,HIGH(@0<<1) 
			ldi		Zl,LOW(@0<<1)
.endmacro

; Esta macro inicializa el puntero X a una posicion en RAM
; Uso:		initX	<Etiqueta>
.macro	initX
			ldi		Xh,HIGH(@0) 
			ldi		Xl,LOW(@0)	
.endmacro

; Esta macro inicializa el stack pointer
; Uso:		initSP	
.macro	initSP
			ldi dummyreg,LOW(RAMEND)
			out spl,dummyreg
			ldi dummyreg,HIGH(RAMEND)
			out sph,dummyreg
.endmacro

; Esta macro: setea el puerto C como salida, el puerto PB5 como salida
;el puerto D como entrada
;activa las resistencias de pull-up en los puertos D correspondientes
;Uso:	setPorts
.macro	setPorts
		ldi		dummyreg,0x7F
		out		DDRC,dummyreg				;PC0-PC5 como salida
		sbi		DDRB,5						;PB5 como salida
		ldi		dummyreg,0x00
		out		DDRD,dummyreg				;Puerto D como entrada
		sbi		PORTD,2						; Activo las resistencias de Pull-up en el puerto PD2 y PD3
		sbi		PORTD,3
.endmacro

; Esta macro setea la interrupcion externa en INT0
; Uso: setINT0
.macro setInt0
		ldi		dummyreg,EICRA_MASK
		sts		EICRA,dummyreg
		ldi		dummyreg,EIMSK_MASK
		out		EIMSK,dummyreg
		sei
.endmacro

; Esta macro shiftea un registro 5 veces hacia la izquierda
; Uso: shift5BitsL	<Rd>
.macro	shift5BitsL
		swap	@0
		andi	@0,0xF0
		lsl		@0	
.endmacro

; Esta macro decrementa el registro que se pasa como argumento 1 y si llega a cero, 
; salta a la etiqueta que se pasa como argumento 2
; Uso:		djnz	<Rd>,<Etiqueta>
.macro	djnz
			dec		@0
			tst		@0
			brne	@1
.endmacro	