
; *******************************************************
; *							*
; *     Delphi Runtime Library                          *
; *							*
; *	Copyright (c) 1996,98 Inprise Corporation	*
; *							*
; *******************************************************

	INCLUDE	SE.ASM

	.386
	.MODEL	FLAT

	EXTRN	Error:NEAR

	PUBLIC	_Ext2Real

	.CODE

RealBias EQU	129
ExtBias  EQU    3FFFH

;	FUNCTION _Ext2Real( val : Extended ) : Real;

_Ext2Real PROC

; ->	FST(0)	Value
;	EAX	Pointer to result

	PUSH	EBX

	SUB	ESP,12
	FSTP	tbyte ptr [ESP]

	POP	EBX			; EBX is low half of fraction
	POP	EDX			; EDX is high half of fraction
	POP	ECX			; CX is exponent and sign

	SHR	EBX,24			; set carry to last bit shifted out
	ADC	BL,0			; if bit was 1, round up
	ADC	EDX,0
	ADC	CX,0
	JO	@@overflow

	ADD	EDX,EDX			; shift fraction 1 bit left
	ADD	CX,CX			; shift sign bit into carry
	RCR	EDX,1			; attach sign bit to fraction
	SHR	CX,1			; restore exponent, deleting sign

	SUB	CX,ExtBias-RealBias	; adjust exponent
	JLE	@@underflow
	TEST	CH,CH			; CX must be in 1..255
	JG	@@overflow

	MOV	[EAX],CL
	MOV	[EAX+1],BL
	MOV	[EAX+2],EDX

	POP	EBX
	RET

@@underflow:
	XOR	ECX,ECX
	MOV	[EAX],ECX
	MOV	[EAX+4],CX
	POP	EBX
	RET

@@overflow:
	POP	EBX
	MOV	AL,8
	JMP	Error

_Ext2Real ENDP

	END
