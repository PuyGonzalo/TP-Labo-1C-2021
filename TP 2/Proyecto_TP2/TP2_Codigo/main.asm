;
; TP2.asm
;
; Created: 4/6/2021 20:57:45
; Autor : Puy Gonzalo
; Padron : 99784
;

.include "m328pdef.inc"
.include "Macros.inc"

; .equ y .def necesarios para el codigo
.equ	NUEVE = 0x7B
.equ	CERO = 0x7E
.equ	POS_INICIAL = 6		;Define la posicion inicial del display. Si quiero que empiece en el digito 'n' POS_INICIAL = n+1
.equ	LEN_TABLA = 10
.equ	BYTES_TABLA_RAM = 10
.equ	PIN_S1 = 2
.equ	PIN_S2 = 3
.equ	C_MASK = 0b01111110
.equ	B_MASK = 0b00000001
.equ	EICRA_MASK = 0b0010
.equ	EIMSK_MASK = 0b01


.def	dummyreg = r16
.def	aux1 = r17
.def	aux2 = r18
.def	contador = r19

.dseg
.org SRAM_START
DISPLAY_NUMEROS_RAM: .byte BYTES_TABLA_RAM


.cseg
.org 0x0000
		jmp		config

.org INT0addr
		jmp		isr_int0

.org INT_VECTORS_SIZE

config:
; Inicializo el stack pointer
		initSP
; Seteo los puertos de entrada y salida. Ademas activo las resistencias de pull-up correspondientes
		setPorts
; Seteo interrupciones externas
		setINT0
								
main:
		call	copiar_a_RAM
		call	inicio
		clr		dummyreg

end:
		jmp		end

;Copio la tabla ROM en la memora SRAM
;Con esto tengo mejor control sobre los datos
copiar_a_RAM:
			initZ	DISPLAY_NUMEROS_ROM
			initX	DISPLAY_NUMEROS_RAM
			ldi		contador,LEN_TABLA
copy:		lpm		dummyreg,z+
			st		x+,dummyreg
			djnz	contador,copy
			ret

inicio:
		initX	DISPLAY_NUMEROS_RAM			;Vuevlo a iniciar el puntero X
		clr		dummyreg					;ya que despues de copiar a RAM quedo en la ultima posicion de la tabla
		ldi		contador,POS_INICIAL
		
posicion_inicial:							;Seteo la posicion inicial del display ('5')
		ld		dummyreg,x+
		djnz	contador,posicion_inicial
		call	setear_display
		ld		dummyreg,-x					;Con esto me aseguro de dejar el puntero X apuntando en la direccion de 5
		ret

;Rutina para setear el display con el numero que esta en dummyreg
setear_display:
		mov		aux1,dummyreg
		mov		aux2,dummyreg

		andi	aux1,C_MASK
		lsr		aux1
		out		PORTC,aux1

		andi	aux2,B_MASK
		shift5BitsL		aux2
		out		PORTB,aux2
		ret

;Rutina de interrupciones
isr_int0:

bucle_delay:
		nop
		call	delay
		nop
		sbic	PIND,PIN_S1
		jmp		retorno_isr
		
		sbis	PIND,PIN_S2					
		jmp		incrementar
		jmp		decrementar

incrementar:
		ld		dummyreg,x
		cpi		dummyreg,NUEVE
		breq	fin_incremento	;Si el valor que lei es el numero '9' -> Voy hacia fin_incremento
		ld		dummyreg,x+		;Hago una lectura solo para avanzar al suiguiente valor
		ld		dummyreg,x		;Leo el valor y dejo el puntero en esta direccion.

		call	setear_display
		jmp		retorno_isr
fin_incremento:
		call	setear_display
		jmp		retorno_isr		

decrementar:
		ld		dummyreg,x
		cpi		dummyreg,CERO
		breq	fin_decremento	;Si el valor que lei es '0' -> Voy hacia fin_decremento

		ld		dummyreg,-x		;Decremento el puntero y leo el valor
		
		call	setear_display
		jmp		retorno_isr
fin_decremento:
		call	setear_display
		jmp		retorno_isr

;Seteo en 1 el bit 0 de EIFR (INTF0) antes de RETI
;Con esto, me aseguro de ignorar las interrupciones
;que pueden haberse dado mientras estaba en esta rutina.
retorno_isr:
		sbi		EIFR,0
		reti

;Delay de 10 ms
delay:
    ldi  r21, 208
    ldi  r22, 202
L1: 
	dec  r22
    brne L1
    dec  r21
    brne L1
    nop
	ret

;Tabla ROM con los valores de los numeros para el display de 7 segmentos
.cseg		
.org 0x500
DISPLAY_NUMEROS_ROM: .db 0x7E,0x30,0x6D,0x79,0x33,0x5B,0X5F,0x70,0x7F,0x7B

