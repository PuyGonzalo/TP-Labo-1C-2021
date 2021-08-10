;
; DCCONTROL.inc
;
; Created: 7/7/2021 22:47:28
; Autor : Puy Gonzalo
; Padron : 99784
;

 UP:
		CPI		DC,MAXIMO_DC
		BREQ	UP_RETORNO

		LDI		dummyreg, DC_25
		ADD		DC,dummyreg
		OUT		OCR0B,DC
		CLR		UP_DOWN

UP_RETORNO:
		RET

DOWN:
		CPI		DC,MINIMO_DC
		BREQ	DOWN_RETORNO

		LDI		dummyreg,DC_25
		SUB		DC,dummyreg
		OUT		OCR0B,DC
		CLR		UP_DOWN

DOWN_RETORNO:
		RET