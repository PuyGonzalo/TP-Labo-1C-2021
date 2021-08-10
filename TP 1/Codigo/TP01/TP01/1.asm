;
; TP01 - Laboratorio de Microprocesadores (86.07)
;
; Created: 15/5/2021 17:13:43
; Author : Puy Gonzalo
; Padron : 99784

;Codigo para punto 1) del TP - 01

.include "m328pdef.inc"

.def		aux1=r16
.def		aux2=r17

.cseg
.org 0x0000
			jmp		main

.org INT_VECTORS_SIZE


main:

; Configuro puerto

			ldi		aux1,0xff
			out		DDRB,aux1	;Puerto B como salida

;Seteo PORTB para que esten todos en 1.
;De esta forma los leds empiezan apagados
;Debo hacer esto debido al funcionamiento del shield.
			out		PORTB,aux1

ciclo:
			cbi		PORTB,2		;encendio del led
			call	delay_1s	;llamo a delay
			sbi		PORTB,2		;apago led
			call	delay_1s	;llamo de nuevo a delay
			jmp	ciclo			;Comienzo el ciclo de nuevo

; Subrutina de Delay

delay_1s:
			ldi  r18, 102
			ldi  r19, 118
			ldi  r20, 194
L1:
			dec  r20
			brne L1
			dec  r19
			brne L1
			dec  r18
			brne L1
ret