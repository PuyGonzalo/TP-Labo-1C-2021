;
; SEND_ADC.inc
;
; Autor : Puy Gonzalo
; Padron : 99784
;
;

ADC_SEND:
		LDS		dummyreg, UCSR0A
		SBRS	dummyreg, UDRE0
		JMP		ADC_SEND

		LDS		ADC_DATA, ADCH
		STS		UDR0,r20
		RET