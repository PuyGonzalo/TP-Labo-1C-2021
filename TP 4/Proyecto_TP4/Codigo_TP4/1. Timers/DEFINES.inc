;
; DEFINES.inc
;
; Created: 6/7/2021 00:40:03
; Autor : Puy Gonzalo
; Padron : 99784
;
; Este archivo contiene .DEF y .EQU utiles para el programa.

.DEF	dummyreg = r16
.DEF	MODO_LED = r17
.DEF	CONTROL_LED = r18

.EQU	SWITCH_MASK = 0b00001100
.EQU	LED_MASK = 0b00000001
.EQU	LED_PIN = 0
.EQU	MODO_FIJO = 0b00000000
.EQU	MODO_64 = 0b00001000
.EQU	MODO_256 = 0b00000100
.EQU	MODO_1024 = 0b00001100