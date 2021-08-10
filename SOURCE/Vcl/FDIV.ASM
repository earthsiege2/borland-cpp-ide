
; *******************************************************
; *							*
; *     Delphi Runtime Library                          *
; *	Pentium-safe floating-point divide support	*
; *							*
; *	Copyright (c) 1995,98 Inprise Corporation	*
; *							*
; *******************************************************

	TITLE	FDIV

	.386
	.MODEL	FLAT

	INCLUDE	SE.ASM

	.CODE

; FDIV constants

FDIVRiscTable	DB	0,1,0,0,4,0,0,7,0,0,10,0,0,13,0,0

FDIVScale1	DD	3F700000H		;0.9375
FDIVScale2	DD	3F880000H		;1.0625
FDIV1SHL63	DD	5F000000H		;1 SHL 63

TestDividend	DQ	4150017EC0000000H	;4195835.0
TestDivisor	DQ	4147FFFF80000000H	;3145727.0
TestOne		DQ	3FF0000000000000H	;1.0


	.DATA

; Externals

	EXTRN	TestFDIV:BYTE

	.CODE

; Publics

	PUBLIC	_FSafeDivide,_FSafeDivideR

Dividend	EQU	(TBYTE PTR [ESP])
Divisor		EQU	(TBYTE PTR [ESP+12])

; Flawed FDIV detection

FDivideDetect:

	MOV	TestFDIV,1		;Indicate correct FDIV

	PUSH	EAX
	SUB	ESP,12
	FSTP	TBYTE PTR [ESP]		;Save off ST
	FLD	TestDividend		;Ok if x - (x / y) * y < 1.0
	FDIV	TestDivisor
	FMUL	TestDivisor
	FSUBR	TestDividend
	FCOMP	TestOne
	FSTSW	AX
	SHR	EAX,7
	AND	EAX,002H		;Zero if FDIV is flawed
	DEC	EAX
	MOV	TestFDIV,AL		;1 means Ok, -1 means flawed
	FLD	TBYTE PTR [ESP]		;Restore ST
	ADD	ESP,12
	POP	EAX
	JMP	SHORT _FSafeDivide

; Floating-point divide reverse routine
; ST(1) = ST(0) / ST(1), pop ST

_FSafeDivideR:

	FXCH

; Floating-point divide routine
; ST(1) = ST(1) / ST(0), pop ST

_FSafeDivide:

	CMP	TestFDIV,0		;Check FDIV indicator
	JLE	FDivideChecked		;Jump if flawed or don't know
	FDIV				;Known to be ok, so just do FDIV
	RET

FDivideChecked:

	JE	FDivideDetect		;Do detection if TestFDIV = 0

@@1:	PUSH	EAX
	SUB	ESP,24
	FSTP	Divisor			;Store Divisor and Dividend
	FSTP	Dividend
	FLD	Dividend
	FLD	Divisor
@@2:	MOV	EAX,Divisor.d4		;Is Divisor a denormal?
	ADD	EAX,EAX
	JNC	@@20			;Yes, @@20
	XOR	EAX,0E000000H		;If these three bits are not all
	TEST	EAX,0E000000H		;ones, FDIV will work
	JZ	@@10			;Jump if all ones
@@3:	FDIV				;Do FDIV and exit
	ADD	ESP,24
	POP	EAX
	RET

@@10:	SHR	EAX,28			;If the four bits following the MSB
					;of the mantissa have a decimal
					;of 1, 4, 7, 10, or 13, FDIV may
	CMP	FDIVRiscTable[EAX],0	;not work correctly
	JZ	@@3			;Do FDIV if not 1, 4, 7, 10, or 13
	MOV	EAX,Divisor.d8		;Get Divisor exponent
	AND	EAX,7FFFH
	JZ	@@3			;Ok to FDIV if denormal
	CMP	EAX,7FFFH
	JE	@@3			;Ok to FDIV if NAN or INF
	MOV	EAX,Dividend.d8		;Get Dividend exponent
	AND	EAX,7FFFH
	CMP	EAX,1			;Small number?
	JE	@@11			;Yes, @@11
	FMUL	FDIVScale1		;Scale by 15/16
	FXCH
	FMUL	FDIVScale1
	FXCH
	JMP	@@3			;FDIV is now safe

@@11:	FMUL	FDIVScale2		;Scale by 17/16
	FXCH
	FMUL	FDIVScale2
	FXCH
	JMP	@@3			;FDIV is now safe

@@20:	MOV	EAX,Divisor.d0		;Is entire Divisor zero?
	OR	EAX,Divisor.d4
	JZ	@@3			;Yes, ok to FDIV
	MOV	EAX,Divisor.d8		;Get Divisor exponent
	AND	EAX,7FFFH		;Non-zero exponent is invalid
	JNZ	@@3			;Ok to FDIV if invalid
	MOV	EAX,Dividend.d8		;Get Dividend exponent
	AND	EAX,7FFFH		;Denormal?
	JZ	@@21			;Yes, @@21
	CMP	EAX,7FFFH		;NAN or INF?
	JE	@@3			;Yes, ok to FDIV
	MOV	EAX,Dividend.d4		;If MSB of mantissa is zero, the
	ADD	EAX,EAX			;number is invalid
	JNC	@@3			;Ok to FDIV if invalid
	JMP	SHORT @@22
@@21:	MOV	EAX,Dividend.d4		;If MSB of mantissa is non-zero, the
	ADD	EAX,EAX			;number is invalid
	JC	@@3			;Ok to FDIV if invalid
@@22:	FXCH				;Scale stored Divisor image by
	FSTP	ST(0)			;1 SHL 63 and restart
	FLD	ST(0)
	FMUL	FDIV1SHL63
	FSTP	Divisor
	FLD	Dividend
	FXCH
	JMP	@@2

	END
