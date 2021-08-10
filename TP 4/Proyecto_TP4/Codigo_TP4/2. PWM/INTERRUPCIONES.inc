;
; INTERRUPCIONES.inc
;
; Created: 7/7/2021 22:47:55
; Autor : Puy Gonzalo
; Padron : 99784
;



 isr_DOWN:
		NOP
		CALL	DELAY
		NOP
		SBIS	PIND,PIN_SDOWN
		JMP		RETORNO_isrDOWN

		LDI	UP_DOWN,DC_DOWN

RETORNO_isrDOWN:
		SBI		EIFR,0
		RETI

isr_UP:
		NOP
		CALL	DELAY
		NOP
		SBIS	PIND,PIN_SUP
		JMP		RETORNO_isrUP

		LDI	UP_DOWN,DC_UP

RETORNO_isrUP:
		SBI		EIFR,0
		RETI


;Delay de 10 ms
DELAY:
    ldi  r21, 208
    ldi  r22, 202
L1: 
	dec  r22
    brne L1
    dec  r21
    brne L1
    nop
	ret