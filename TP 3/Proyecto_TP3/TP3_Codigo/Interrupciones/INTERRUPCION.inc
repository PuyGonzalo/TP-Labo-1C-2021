;
; INTERRUPCION.inc
;
; Created: 5/6/2021 01:43:15
; Alumno : Puy Gonzalo
; Padron : 99784

; Rutina de Interrupcion
; Guardo el dato recibido en un registro
; Luego seteo el bit T de SREG en 1.

 isr_rxComplete:
		LDS		Dato_R,UDR0
		SET
		RETI