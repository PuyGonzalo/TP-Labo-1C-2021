;
; TP INTEGRADOR
;
; Autor : Puy Gonzalo
; Padron : 99784
;

.include "m328pdef.inc"
.include "MACROS.inc"
.include "DEFINES.inc"

.DSEG
.ORG SRAM_START
PERIODO: .BYTE SIZE

.CSEG
.ORG 0x0000
		JMP		CONFIG

.ORG INT_VECTORS_SIZE

CONFIG:
		initSP
		initPORTS
		initUSART
		initTimer0
		initTimer1

MAIN:
		CALL	CALCULAR_PERIODO
		turn_off_Timer1
		initADC
ADC_CONVERT:
		CALL	ADC_SEND
		JMP		ADC_CONVERT


.INCLUDE "PERIODO.inc"
.INCLUDE "SEND_ADC.INC"
