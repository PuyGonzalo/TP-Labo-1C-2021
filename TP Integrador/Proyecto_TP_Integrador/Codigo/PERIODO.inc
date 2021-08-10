;
; PERIODO.inc
;
; Autor : Puy Gonzalo
; Padron : 99784
;
;

 CALCULAR_PERIODO:
		CLR		contador
		initX	PERIODO
LOOP_P1:
		IN		dummyreg,TIFR1
		SBRS	dummyreg,ICF1
		JMP		LOOP_P1
		LDS		auxL,ICR1L
		LDS		auxH,ICR1H
		SBI		TIFR1,ICF1		;Hago clear de ICF1
LOOP_P2:
		IN		dummyreg,TIFR1
		SBRS	dummyreg,ICF1
		JMP		LOOP_P2
		SBI		TIFR1,ICF1
		LDS		periodo_L,ICR1L	; Guardo en periodo_L el NUEVO valor LOW
		SUB		periodo_L,auxL
		ST		X+,periodo_L	; En PERIODO queda: periodo_L:periodo_H
		LDS		periodo_H,ICR1H	; Guardo en periodo_H el NUEVO valor HIGH
		SBC		periodo_H,auxH
		ST		X+,periodo_H
		initX	PERIODO

SET_NUM:
		LD		r20,X+
		INC		contador
		CPI		contador,MAX_CONTADOR_PERIODO
		BREQ	RETORNO_CALCULAR_PERIODO
		
SEND:
		LDS		dummyreg, UCSR0A
		SBRS	dummyreg, UDRE0
		JMP		SEND
		
		STS		UDR0,r20
		JMP		SET_NUM

RETORNO_CALCULAR_PERIODO:
		RET