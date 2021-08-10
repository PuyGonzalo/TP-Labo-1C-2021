;
; TP3 - Puerto Serie
;
; Created: 3/7/2021 20:57:45
; Autor : Puy Gonzalo
; Padron : 99784
;

.include "m328pdef.inc"
.include "MACROS.inc"
.include "DEFINES.inc"

.CSEG
.ORG 0x0000
		JMP		CONFIG

.ORG INT_VECTORS_SIZE

CONFIG:
		initSP
		initPORTS
		initUSART

MAIN:
		CALL	DISPLAY_MSG
RECIBIR:
		CALL	GET_DATA
		CALL	SET_LEDs
		JMP		RECIBIR


.INCLUDE "ENVIARYRECIBIR.inc"
.INCLUDE "LEDs.inc"
		


INIT_MSG: .DB "*** Hola Labo de Micro ***", '\n', '\n', "Escriba 1,2,3 o 4 para controlar los LEDs",'\0'