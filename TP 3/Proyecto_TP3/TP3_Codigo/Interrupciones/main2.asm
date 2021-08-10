;
; TP3 - Puerto Serie
; Actividad adicional dada por enunciado.
;
; Created: 3/7/2021 20:57:45
; Autor : Puy Gonzalo
; Padron : 99784
;

.include "m328pdef.inc"
.include "MACROS2.inc"
.include "DEFINES2.inc"

.CSEG
.ORG 0x0000
		JMP		CONFIG
.ORG URXCaddr
		JMP		isr_rxComplete

.ORG INT_VECTORS_SIZE

CONFIG:
		initSP
		initPORTS
		initUSART

MAIN:
		CALL	DISPLAY_MSG
LOOP:
		BRTC	NO_DATA
		CALL	SET_LEDs
NO_DATA:
		JMP		LOOP

.INCLUDE "ENVIAR2.inc"
.INCLUDE "LEDs2.inc"
.INCLUDE "INTERRUPCION.inc"
		


INIT_MSG: .DB "*** Hola Labo de Micro ***", '\n', '\n', "Escriba 1,2,3 o 4 para controlar los LEDs",'\0'