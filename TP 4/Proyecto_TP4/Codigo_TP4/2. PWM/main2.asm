;
; TP4 - PWM
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

.ORG INT0addr
		JMP		isr_DOWN

.ORG INT1addr
		JMP		isr_UP

.ORG INT_VECTORS_SIZE

CONFIG:
		initSP
		initPORTS
		setInt
		configTimer0

MAIN:
		CLR		UP_DOWN
		LDI		DC,0
		OUT		OCR0B,DC
DC_CONTROL:
		SBRC	UP_DOWN,0
		CALL	UP
		SBRC	UP_DOWN,1
		CALL	DOWN
		JMP		DC_CONTROL

.INCLUDE	"INTERRUPCIONES.inc"
.INCLUDE	"DCCONTROL.inc"
