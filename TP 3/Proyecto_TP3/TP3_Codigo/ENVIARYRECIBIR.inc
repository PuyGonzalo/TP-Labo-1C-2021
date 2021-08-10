;
;  ENVIARYRECIBIR.inc
;
; Created: 3/7/2021 15:04:46
;  Alumno: Puy Gonzalo
; Padron : 99784
;

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

; Recibir datos
GET_DATA:
		LDS		dummyreg, UCSR0A
		SBRS	dummyreg, RXC0
		JMP		GET_DATA

		LDS		Dato_R,UDR0
		RET
