;
; LEDs.inc
;
; Created: 3/7/2021 15:07:04
; Alumno: Puy Gonzalo
; Padron : 99784
;

 SET_LEDs:
		CPI		Dato_R,1
		BREQ	LED_1

		CPI		Dato_R,2
		BREQ	LED_2

		CPI		Dato_R,3
		BREQ	LED_3

		CPI		Dato_R,4
		BREQ	LED_4

		RET

LED_1:
		LDI		Pin_Mask,0b00000001
		JMP		on_off

LED_2:
		LDI		Pin_Mask,0b00000010
		JMP		on_off

LED_3:
		LDI		Pin_Mask,0b00000100
		JMP		on_off

LED_4:
		LDI		Pin_Mask,0b00001000
		JMP		on_off

on_off:
		IN		dummyreg,PORTB
		EOR		dummyreg,Pin_Mask
		OUT		PORTB,dummyreg
		RET
