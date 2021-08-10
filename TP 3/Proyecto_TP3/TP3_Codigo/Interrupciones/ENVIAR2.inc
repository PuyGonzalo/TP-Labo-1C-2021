;
;ENVIAR2.inc
;
; Created: 5/6/2021 01:43:15
; Alumno : Puy Gonzalo
; Padron : 99784

; Mensaje incial
DISPLAY_MSG:
		initZ	INIT_MSG
SET_CHAR:
		LPM		Caracter,Z+
		CPI		Caracter,MSG_END
		BREQ	RETORNO
SEND:
		LDS		dummyreg,UCSR0A
		SBRS	dummyreg, UDRE0
		JMP		SEND
		
		STS		UDR0,Caracter
		JMP		SET_CHAR
RETORNO:
		RET

