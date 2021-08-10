;
; Defines2.inc
;
; Created: 6/7/2021 00:40:03
; Autor : Puy Gonzalo
; Padron : 99784
;
; Este archivo contiene .DEF y .EQU utiles para el programa.

.EQU	MAXIMO_DC = 252
.EQU	MINIMO_DC = 0
.EQU	DC_25 = 63
.EQU	DC_UP = 1
.EQU	DC_DOWN = 2
.equ	PIN_SDOWN = 2
.equ	PIN_SUP = 3

.DEF	dummyreg = r16
.DEF	DC = r17
.DEF	UP_DOWN = r18