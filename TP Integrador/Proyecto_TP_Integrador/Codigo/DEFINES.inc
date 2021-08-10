;
; Defines.inc
;
; Autor : Puy Gonzalo
; Padron : 99784
;
; Este archivo contiene .DEF y .EQU utiles para el programa.

.EQU	BAUDRATEH = 0X00
.EQU	BAUDRATEL = 0X67
.EQU	SIZE = 2
.EQU	MAX_CONTADOR_PERIODO = 3
.EQU	OCR0B_VALUE = 0x7F
.EQU	ADMUX_MASK = 0b01100000
.EQU	ADCSRA_MASK = 0b11100111
.EQU	ADCSRB_MASK = 0b00000000


.DEF	dummyreg = r16
.DEF	contador = r17
.DEF	auxL = r18
.DEF	auxH = r19
.DEF	ADC_DATA = r20
.DEF	periodo_L = r21
.DEF	periodo_H = r22