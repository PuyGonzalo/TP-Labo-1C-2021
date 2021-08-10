;
; Defines.inc
;
; Este archivo contiene .EQU y .DEF necesarios para el codigo
;
; Created: 5/6/2021 01:43:15
; Alumno : Puy Gonzalo
; Padron : 99784

.EQU	MSG_END = '\0'
.EQU	BAUDRATEH = 0X00
.EQU	BAUDRATEL = 0X67

.DEF	dummyreg = r16
.DEF	Caracter = r17
.DEF	Dato_R = r18
.DEF	Pin_Mask = r19