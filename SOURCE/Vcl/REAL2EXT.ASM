
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

	PUBLIC	_Real2Ext, @Real2Ext

	.CODE

RealBias EQU	129
ExtBias  EQU    3FFFH

;	FUNCTION _Real2Ext( val : Real ) : Extended;

@Real2Ext:
_Real2Ext PROC

; ->	EAX	Pointer to value
; <-	FST(0)	Result

;	the REAL data type has the following format:
;	8 bit exponent (bias 129), 39 bit fraction, 1 bit sign

	MOV	DH,[EAX+5]	; isolate the sign bit
	AND	DH,80H
	MOV	DL,[EAX]	; fetch exponent
	TEST	DL,DL		; exponent zero means number is zero
	JE	@@zero

	ADD	DX,ExtBias-RealBias	; adjust exponent bias

	PUSH    EDX		; the exponent is at the highest address

	MOV	EDX,[EAX+2]	; load high fraction part, set hidden bit
	OR	EDX,80000000H
	PUSH	EDX		; push high fraction part

	MOV	DL,[EAX+1]	; load remaining low byte of fraction
	SHL	EDX,24		; clear low 24 bits
	PUSH	EDX

	FLD	tbyte ptr [ESP]	; pop result onto chip
	ADD	ESP,12

	RET

@@zero:	FLDZ
	RET

_Real2Ext ENDP

	END
