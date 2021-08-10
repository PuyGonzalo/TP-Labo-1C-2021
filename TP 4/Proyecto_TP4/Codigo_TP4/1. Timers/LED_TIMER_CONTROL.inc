;
; LED_TIMER_CONTROL.inc
;
; Created: 7/7/2021 02:14:22
; Autor : Puy Gonzalo
; Padron : 99784
;

 SELEC_MODO:
		CPI		MODO_LED,MODO_FIJO
		BREQ	FIJO

		CPI		MODO_LED,MODO_64
		BREQ	M_64

		CPI		MODO_LED,MODO_256
		BREQ	M_256
		
		CPI		MODO_LED,MODO_1024
		BREQ	M_1024

FIJO:
		LDI		dummyreg,0
		STS		TCCR1B,dummyreg
		SBI		PORTB,LED_PIN
		JMP		RETORNO
M_64:
		LDI		dummyreg, (0<<CS12) | (1<<CS11) | (1<<CS10)
		STS		TCCR1B,dummyreg
		JMP		RETORNO
M_256:
		LDI		dummyreg, (1<<CS12) | (0<<CS11) | (0<<CS10)
		STS		TCCR1B,dummyreg
		JMP		RETORNO
M_1024:
		LDI		dummyreg, (1<<CS12) | (0<<CS11) | (1<<CS10)
		STS		TCCR1B,dummyreg
		JMP		RETORNO

RETORNO:
		RET

; Rutina de interrupcion
ISR_OVERFLOW:
		IN		CONTROL_LED,PORTB
		LDI		dummyreg,LED_MASK
		EOR		CONTROL_LED,dummyreg
		OUT		PORTB,CONTROL_LED
		RETI