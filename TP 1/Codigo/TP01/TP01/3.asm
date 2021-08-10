;
; TP01 - Laboratorio de Microprocesadores (86.07)
;
; Created: 15/5/2021 17:13:43
; Author : Puy Gonzalo
; Padron : 99784

;Codigo para punto 3) del TP - 01

.include "m328pdef.inc"

.def		aux1=r16
.def		aux2=r17

.cseg
.org 0x0000
			jmp		main

.org INT_VECTORS_SIZE


main:

; Configuro puertos

			ldi		aux1,0xff
			out		DDRB,aux1	;Puerto B como salida
			ldi		aux2,0x00	;
			out		DDRC,aux2	;Puerto C como entrada

;Seteo PORTB para que esten todos en 1.
;De esta forma los leds empiezan apagados
;Debo hacer esto debido al funcionamiento del shield.
			out		PORTB,aux1
			out		PORTC,aux1	;Resistencia de Pull-up activada

; Subrutina de Led apagado
loopapagado:
			sbis	PINC,1		;Skipeo l siguiente linea si el bit 1 de PINC esta en "1"
			jmp		ciclo
			jmp		loopapagado		
			
; Subrutina de parpadeo del led
ciclo:
			cbi		PORTB,2		;encendio del led
			call	delay_50ms	;llamo a delay
			sbi		PORTB,2		;apago led
			call	delay_50ms	;llamo de nuevo a delay
			sbis	PINC,2		;Skipeo la siguiente linea si el bit 2 de PINC esta en "1"
			jmp		loopapagado	;Vuevlo al loop del Led apagado
			jmp		ciclo		;Vuelvo a comezar el ciclo

; Subrutina de Delay

delay_50ms: 
    ldi  r20, 5
    ldi  r21, 15
    ldi  r22, 242
L1: dec  r22
    brne L1
    dec  r21
    brne L1
    dec  r20
    brne L1
ret