
; *******************************************************
; *							*
; *     Delphi Runtime Library                          *
; *	Floating point formatting routines		*
; *							*
; *	Copyright (c) 1995,98 Inprise Corporation	*
; *							*
; *******************************************************

	TITLE	FFMT

	.386
	.MODEL	FLAT

	INCLUDE	SE.ASM

; TFloatRec layout

fdExponent	EQU	(WORD PTR 0)
fdNegative	EQU	(BYTE PTR 2)
fdDigits	EQU	(BYTE PTR 3)
fdRecSize	EQU	24

; TFloatValue constants

fvExtended	EQU	0
fvCurrency	EQU	1

; TFloatFormat constants

ffGeneral	EQU	0
ffExponent	EQU	1
ffFixed		EQU	2
ffNumber	EQU	3
ffCurrency	EQU	4

; 1E18 as a 64-bit integer

Const1E18Lo	EQU	0A7640000H
Const1E18Hi	EQU	00DE0B6B3H

; Externals

	EXTRN	FPower10:NEAR
	EXTRN	CurrencyString:DWORD
	EXTRN	CurrencyFormat:BYTE
	EXTRN	NegCurrFormat:BYTE
	EXTRN	ThousandSeparator:BYTE
	EXTRN	DecimalSeparator:BYTE

; Publics

	PUBLIC	FloatToText,FloatToTextFmt,FloatToDecimal,TextToFloat

	.CODE

; Constants

DCon10		DD	10
DCon100		DD	100
DCon1000	DD	1000
DCon10000	DD	10000

FCon1E18	DT	1E18

; 8087 control word
; Infinity control  = 1 Affine
; Rounding Control  = 0 Round to nearest or even
; Precision Control = 3 64 bits
; All interrupts masked

CWNear		DW	133FH

; INF and NAN strings

INFNAN		DB	'INFNAN'

; function FloatToText(Buffer: PChar; const Value; ValueType: TFloatValue;
;   Format: TFloatFormat; Precision, Digits: Integer): Integer;

FloatToText:

	ARG	BufferArg,DWORD,1
	ARG	Value,DWORD,1
	ARG	ValueType,BYTE,4
	ARG	Format,BYTE,4
	ARG	Precision,DWORD,1
	ARG	Digits,DWORD,1
	LOC	Buffer,DWORD,1
	LOC	FloatRec,BYTE,fdRecSize

	ENTRY	FAR
	PUSH	EDI
	PUSH	ESI
	PUSH	EBX
	MOV	Buffer,EAX
	MOV	EAX,19
	CMP	CL,fvExtended
	JNE	@@2
	MOV	EAX,Precision
	CMP	EAX,2
	JGE	@@1
	MOV	EAX,2
@@1:	CMP	EAX,18
	JLE	@@2
	MOV	EAX,18
@@2:	MOV	Precision,EAX
	PUSH	EAX
	MOV	EAX,9999
	CMP	Format,ffFixed
	JB	@@3
	MOV	EAX,Digits
@@3:	PUSH	EAX
	LEA	EAX,FloatRec
	CALL	FloatToDecimal
	MOV	EDI,Buffer
	MOVZX	EAX,FloatRec.fdExponent
	SUB	EAX,7FFFH
	CMP	EAX,2
	JAE	@@4
        MOV     ECX, EAX
        CALL    PutSign
	LEA	ESI,INFNAN[ECX+ECX*2]
	MOV	ECX,3
	REP	MOVSB
	JMP	@@7
@@4:	LEA	ESI,FloatRec.fdDigits
	MOVZX	EBX,Format
	CMP	BL,ffExponent
	JE	@@6
	CMP	BL,ffCurrency
	JA	@@5
	MOVSX	EAX,FloatRec.fdExponent
	CMP	EAX,Precision
	JLE	@@6
@@5:	MOV	BL,ffGeneral
@@6:	CALL	DWORD PTR FormatVector[EBX*4]
@@7:	MOV	EAX,EDI
	SUB	EAX,Buffer
	POP	EBX
	POP	ESI
	POP	EDI
	EXIT

FormatVector	LABEL	DWORD

	DD	PutFGeneral
	DD	PutFExponent
	DD	PutFFixed
	DD	PutFNumber
	DD	PutFCurrency

; Get digit or '0' if at end of digit string

GetDigit:

	LODSB
	OR	AL,AL
	JNE	@@1
	MOV	AL,'0'
	DEC	ESI
@@1:	RET

; Store '-' if number is negative

PutSign:

	CMP	FloatRec.fdNegative,0
	JE	@@1
	MOV	AL,'-'
	STOSB
@@1:	RET

; Convert number using ffGeneral format

PutFGeneral:

	CALL	PutSign
	MOVSX	ECX,FloatRec.fdExponent
	XOR	EDX,EDX
	CMP	ECX,Precision
	JG	@@1
	CMP	ECX,-3
	JL	@@1
	OR	ECX,ECX
	JG	@@2
	MOV	AL,'0'
	STOSB
	CMP	BYTE PTR [ESI],0
	JE	@@6
	MOV	AL,DecimalSeparator
	STOSB
	NEG	ECX
	MOV	AL,'0'
	REP	STOSB
	JMP	@@3
@@1:	MOV	ECX,1
	INC	EDX
@@2:	LODSB
	OR	AL,AL
	JE	@@4
	STOSB
	LOOP	@@2
	LODSB
	OR	AL,AL
	JE	@@5
	MOV	AH,AL
	MOV	AL,DecimalSeparator
	STOSW
@@3:	LODSB
	OR	AL,AL
	JE	@@5
	STOSB
	JMP	@@3
@@4:	MOV	AL,'0'
	REP	STOSB
@@5:	OR	EDX,EDX
	JE	@@6
	XOR	EAX,EAX
	XOR	ECX,ECX
	JMP	PutFloatExp
@@6:	RET

; Convert number using ffExponent format

PutFExponent:

	CALL	PutSign
	CALL	GetDigit
	MOV	AH,DecimalSeparator
	STOSW
	MOV	ECX,Precision
	DEC	ECX
@@1:	CALL	GetDigit
	STOSB
	LOOP	@@1
	MOV	AH,'+'
	MOV	ECX,Digits
	CMP	ECX,4
	JB	PutFloatExp
	XOR	ECX,ECX
;	JMP	PutFloatExp

; Store exponent
; In	AH  = Positive sign character ('+' or 0)
;	ECX = Minimum number of digits (0..4)

PutFloatExp:

	MOV	AL,'E'
	MOV	BL,FloatRec.fdDigits
	MOVSX	EDX,FloatRec.fdExponent
	DEC	EDX
;	JMP	PutExponent

; Store exponent
; In	AL  = Exponent character ('E' or 'e')
;	AH  = Positive sign character ('+' or 0)
;	BL  = Zero indicator
;	ECX = Minimum number of digits (0..4)
;	EDX = Exponent

PutExponent:

	STOSB
	OR	BL,BL
	JNE	@@0
	XOR	EDX,EDX
	JMP	@@1
@@0:	OR	EDX,EDX
	JGE	@@1
	MOV	AL,'-'
	NEG	EDX
	JMP	@@2
@@1:	OR	AH,AH
	JE	@@3
	MOV	AL,AH
@@2:	STOSB
@@3:	XCHG	EAX,EDX
	PUSH	EAX
	MOV	EBX,ESP
@@4:	XOR	EDX,EDX
	DIV	DCon10
	ADD	DL,'0'
	MOV	[EBX],DL
	INC	EBX
	DEC	ECX
	OR	EAX,EAX
	JNE	@@4
	OR	ECX,ECX
	JG	@@4
@@5:	DEC	EBX
	MOV	AL,[EBX]
	STOSB
	CMP	EBX,ESP
	JNE	@@5
	POP	EAX
	RET

; Convert number using ffFixed or ffNumber format

PutFFixed:
PutFNumber:

	CALL	PutSign

; Store number in fixed point format

PutNumber:

	MOV	EDX,Digits
	CMP	EDX,18
	JB	@@1
	MOV	EDX,18
@@1:	MOVSX	ECX,FloatRec.fdExponent
	OR	ECX,ECX
	JG	@@2
	MOV	AL,'0'
	STOSB
	JMP	@@4
@@2:	XOR	EBX,EBX
	CMP	Format,ffFixed
	JE	@@3
	MOV	EAX,ECX
	DEC	EAX
	MOV	BL,3
	DIV	BL
	MOV	BL,AH
	INC	EBX
@@3:	CALL	GetDigit
	STOSB
	DEC	ECX
	JE	@@4
	DEC	EBX
	JNE	@@3
	MOV	AL,ThousandSeparator
	STOSB
	MOV	BL,3
	JMP	@@3
@@4:	OR	EDX,EDX
	JE	@@7
	MOV	AL,DecimalSeparator
	STOSB
	JECXZ	@@6
	MOV	AL,'0'
@@5:	STOSB
	DEC	EDX
	JE	@@7
	INC	ECX
	JNE	@@5
@@6:	CALL	GetDigit
	STOSB
	DEC	EDX
	JNE	@@6
@@7:	RET

; Convert number using ffCurrency format

PutFCurrency:

	XOR	EBX,EBX
	MOV	BL,CurrencyFormat
	MOV	ECX,0003H
	CMP	FloatRec.fdNegative,0
	JE	@@1
	MOV	BL,NegCurrFormat
	MOV	ECX,040FH
@@1:	CMP	BL,CL
	JBE	@@2
	MOV	BL,CL
@@2:	ADD	BL,CH
	LEA	EBX,MoneyFormats[EBX+EBX*4]
	MOV	ECX,5
@@10:	MOV	AL,[EBX]
	CMP	AL,'@'
	JE	@@14
	PUSH	ECX
	PUSH	EBX
	CMP	AL,'$'
	JE	@@11
	CMP	AL,'*'
	JE	@@12
	STOSB
	JMP	@@13
@@11:	CALL	PutCurSym
	JMP	@@13
@@12:	CALL	PutNumber
@@13:	POP	EBX
	POP	ECX
	INC	EBX
	LOOP	@@10
@@14:	RET

; Store currency symbol string

PutCurSym:

	PUSH	ESI
	MOV	ESI,CurrencyString
	TEST	ESI,ESI
	JE	@@1
	MOV	ECX,[ESI-4]
	REP	MOVSB
@@1:	POP	ESI
	RET

; Currency formatting templates

MoneyFormats	LABEL	BYTE

	DB	'$*@@@'
	DB	'*$@@@'
	DB      '$ *@@'
	DB	'* $@@'
	DB	'($*)@'
	DB	'-$*@@'
	DB	'$-*@@'
	DB	'$*-@@'
	DB	'(*$)@'
	DB	'-*$@@'
	DB	'*-$@@'
	DB	'*$-@@'
	DB	'-* $@'
	DB	'-$ *@'
	DB	'* $-@'
	DB	'$ *-@'
	DB	'$ -*@'
	DB	'*- $@'
	DB	'($ *)'
	DB	'(* $)'

; function FloatToTextFmt(Buffer: PChar; const Value; ValueType: TValueType;
;   Format: PChar): Integer;

FloatToTextFmt:

	ARG	BufferArg,DWORD,1
	ARG	Value,DWORD,1
	ARG	ValueType,BYTE,4
	ARG	Format,DWORD,1
	LOC	Buffer,DWORD,1
	LOC	ThousandSep,BYTE,4
	LOC	Scientific,BYTE,4
	LOC	Section,DWORD,1
	LOC	DigitCount,DWORD,1
	LOC	DecimalIndex,DWORD,1
	LOC	FirstDigit,DWORD,1
	LOC	LastDigit,DWORD,1
	LOC	DigitPlace,DWORD,1
	LOC	DigitDelta,DWORD,1
	LOC	FloatRec,BYTE,fdRecSize

	ENTRY	FAR
	PUSH	EDI
	PUSH	ESI
	PUSH	EBX
	MOV	Buffer,EAX
	MOV	EDI,EDX
	MOV	EBX,ECX
	MOV	ECX,2
	CMP	BL,fvExtended
	JE	@@1
	MOV	EAX,[EDI].d0
	OR	EAX,[EDI].d4
	JE	@@2
	MOV	ECX,[EDI].d4
	SHR	ECX,31
	JMP	@@2
@@1:	MOVZX	EAX,[EDI].w8
	OR	EAX,[EDI].d0
	OR	EAX,[EDI].d4
	JE	@@2
	MOVZX	ECX,[EDI].w8
	SHR	ECX,15
@@2:	CALL	FindSection
	JE	@@5
	CALL	ScanSection
	MOV	EAX,DigitCount
	MOV	EDX,9999
	CMP	Scientific,0
	JNE	@@3
	SUB	EAX,DecimalIndex
	MOV	EDX,EAX
	MOV	EAX,18
@@3:	PUSH	EAX
	PUSH	EDX
	LEA	EAX,FloatRec
	MOV	EDX,EDI
	MOV	ECX,EBX
	CALL	FloatToDecimal
	MOV	AX,FloatRec.fdExponent
	CMP	AX,8000H
	JE	@@5
	CMP	AX,7FFFH
	JE	@@5
	CMP	BL,fvExtended
	JNE	@@6
	CMP	AX,18
	JLE	@@6
	CMP	Scientific,0
	JNE	@@6
@@5:	PUSH	ffGeneral
	PUSH	15
	PUSH	0
	MOV	EAX,Buffer
	MOV	EDX,EDI
	MOV	ECX,EBX
	CALL	FloatToText
	JMP	@@8
@@6:	CMP	FloatRec.fdDigits,0
	JNE	@@7
	MOV	ECX,2
	CALL	FindSection
	JE	@@5
	CMP	ESI,Section
	JE	@@7
	CALL	ScanSection
@@7:	CALL	ApplyFormat
@@8:	POP	EBX
	POP	ESI
	POP	EDI
	EXIT

; Find format section
; In	ECX = Section index
; Out	ESI = Section offset
;	ZF  = 1 if section is empty

FindSection:

	MOV	ESI,Format
	JECXZ	@@2
@@1:	LODSB
	CMP	AL,"'"
	JE	@@4
	CMP	AL,'"'
	JE	@@4
	OR	AL,AL
	JE	@@2
	CMP	AL,';'
	JNE	@@1
	LOOP	@@1
	MOV	AL,[ESI]
	OR	AL,AL
	JE	@@2
	CMP	AL,';'
	JNE	@@3
@@2:	MOV	ESI,Format
	MOV	AL,[ESI]
	OR	AL,AL
	JE	@@3
	CMP	AL,';'
@@3:	RET
@@4:	MOV	AH,AL
@@5:	LODSB
	CMP	AL,AH
	JE	@@1
	OR	AL,AL
	JNE	@@5
	JMP	@@2

; Scan format section

ScanSection:

	PUSH	EBX
	MOV	Section,ESI
	MOV	EBX,32767
	XOR	ECX,ECX
	XOR	EDX,EDX
	MOV	DecimalIndex,-1
	MOV	ThousandSep,DL
	MOV	Scientific,DL
@@1:	LODSB
@@2:	CMP	AL,'#'
	JE	@@10
	CMP	AL,'0'
	JE	@@11
	CMP	AL,'.'
	JE	@@13
	CMP	AL,','
	JE	@@14
	CMP	AL,"'"
	JE	@@15
	CMP	AL,'"'
	JE	@@15
	CMP	AL,'E'
	JE	@@20
	CMP	AL,'e'
	JE	@@20
	CMP	AL,';'
	JE	@@30
	OR	AL,AL
	JNE	@@1
	JMP	@@30
@@10:	INC	EDX
	JMP	@@1
@@11:	CMP	EDX,EBX
	JGE	@@12
	MOV	EBX,EDX
@@12:	INC	EDX
	MOV	ECX,EDX
	JMP	@@1
@@13:	CMP	DecimalIndex,-1
	JNE	@@1
	MOV	DecimalIndex,EDX
	JMP	@@1
@@14:	MOV	ThousandSep,1
	JMP	@@1
@@15:	MOV	AH,AL
@@16:	LODSB
	CMP	AL,AH
	JE	@@1
	OR	AL,AL
	JNE	@@16
	JMP	@@30
@@20:	LODSB
	CMP	AL,'-'
	JE	@@21
	CMP	AL,'+'
	JNE	@@2
@@21:	MOV	Scientific,1
@@22:	LODSB
	CMP	AL,'0'
	JE	@@22
	JMP	@@2
@@30:	MOV	DigitCount,EDX
	CMP	DecimalIndex,-1
	JNE	@@31
	MOV	DecimalIndex,EDX
@@31:	MOV	EAX,DecimalIndex
	SUB	EAX,ECX
	JLE	@@32
	XOR	EAX,EAX
@@32:	MOV	LastDigit,EAX
	MOV	EAX,DecimalIndex
	SUB	EAX,EBX
	JGE	@@33
	XOR	EAX,EAX
@@33:	MOV	FirstDigit,EAX
	POP	EBX
	RET

; Apply format string

ApplyFormat:

	CMP	Scientific,0
	JE	@@1
	MOV	EAX,DecimalIndex
	XOR	EDX,EDX
	JMP	@@3
@@1:	MOVSX	EAX,FloatRec.fdExponent
	CMP	EAX,DecimalIndex
	JG	@@2
	MOV	EAX,DecimalIndex
@@2:	MOVSX	EDX,FloatRec.fdExponent
	SUB	EDX,DecimalIndex
@@3:	MOV	DigitPlace,EAX
	MOV	DigitDelta,EDX
	MOV	ESI,Section
	MOV	EDI,Buffer
	LEA	EBX,FloatRec.fdDigits
	CMP	FloatRec.fdNegative,0
	JE	@@10
	CMP	ESI,Format
	JNE	@@10
	MOV	AL,'-'
	STOSB
@@10:	LODSB
	CMP	AL,'#'
	JE	@@20
	CMP	AL,'0'
	JE	@@20
	CMP	AL,'.'
	JE	@@10
	CMP	AL,','
	JE	@@10
	CMP	AL,"'"
	JE	@@25
	CMP	AL,'"'
	JE	@@25
	CMP	AL,'E'
	JE	@@30
	CMP	AL,'e'
	JE	@@30
	CMP	AL,';'
	JE	@@40
	OR	AL,AL
	JE	@@40
@@11:	STOSB
	JMP	@@10
@@20:	CALL	PutFmtDigit
	JMP	@@10
@@25:	MOV	AH,AL
@@26:	LODSB
	CMP	AL,AH
	JE	@@10
	OR	AL,AL
	JE	@@40
	STOSB
	JMP	@@26
@@30:	MOV	AH,[ESI]
	CMP	AH,'+'
	JE	@@31
	CMP	AH,'-'
	JNE	@@11
	XOR	AH,AH
@@31:	MOV	ECX,-1
@@32:	INC	ECX
	INC	ESI
	CMP	[ESI].b0,'0'
	JE	@@32
	CMP	ECX,4
	JB	@@33
	MOV	ECX,4
@@33:	PUSH	EBX
	MOV	BL,FloatRec.fdDigits
	MOVSX	EDX,FloatRec.fdExponent
	SUB	EDX,DecimalIndex
	CALL	PutExponent
	POP	EBX
	JMP	@@10
@@40:	MOV	EAX,EDI
	SUB	EAX,Buffer
	RET

; Store formatted digit

PutFmtDigit:

	CMP	DigitDelta,0
	JE	@@3
	JL	@@2
@@1:	CALL	@@3
	DEC	DigitDelta
	JNE	@@1
	JMP	@@3
@@2:	INC	DigitDelta
	MOV	EAX,DigitPlace
	CMP	EAX,FirstDigit
	JLE	@@4
	JMP	@@7
@@3:	MOV	AL,[EBX]
	INC	EBX
	OR	AL,AL
	JNE	@@5
	DEC	EBX
	MOV	EAX,DigitPlace
	CMP	EAX,LastDigit
	JLE	@@7
@@4:	MOV	AL,'0'
@@5:	CMP	DigitPlace,0
	JNE	@@6
	MOV	AH,AL
	MOV	AL,DecimalSeparator
	STOSW
	JMP	@@7
@@6:	STOSB
	CMP	ThousandSep,0
	JE	@@7
	MOV	EAX,DigitPlace
	CMP	EAX,1
	JLE	@@7
	MOV	DL,3
	DIV	DL
	CMP	AH,1
	JNE	@@7
	MOV	AL,ThousandSeparator
	STOSB
@@7:	DEC	DigitPlace
	RET

; procedure FloatToDecimal(var Result: TFloatDecimal; const Value;
;   ValueType: TValueType; Precision, Decimals: Integer);

FloatToDecimal:

	ARG	Result,DWORD,1
	ARG	Value,DWORD,1
	ARG	ValueType,BYTE,4
	ARG	Precision,DWORD,1
	ARG	Decimals,DWORD,1
	LOC	StatWord,WORD,2
	LOC	Exponent,DWORD,1
	LOC	Temp,QWORD,1
	LOC	BCDValue,TBYTE,1

	ENTRY   FAR
	PUSH	EDI
	PUSH	ESI
	PUSH	EBX
	MOV	EBX,EAX
	MOV	ESI,EDX
	CMP	CL,fvExtended
	JE	@@1
	CALL	CurrToDecimal
	JMP	@@2
@@1:	CALL	ExtToDecimal
@@2:	POP	EBX
	POP	ESI
	POP	EDI
	EXIT

; Convert Extended to decimal

ExtToDecimal:

	MOV	AX,[ESI].w8
	MOV	EDX,EAX
	AND	EAX,7FFFH
	JE	@@1
	CMP	EAX,7FFFH
	JNE	@@10
; check for special values (INF, NAN)
	TEST	[ESI].w6,8000H
	JZ	@@2
; any significand bit set = NAN
; all significand bits clear = INF
        CMP     dword ptr [ESI], 0
        JNZ     @@0
        CMP     dword ptr [ESI+4], 80000000H
        JZ      @@2
@@0:    INC	EAX
@@1:	XOR	EDX,EDX
@@2:	MOV	[EBX].fdDigits,0
	JMP	@@31
@@10:	FLD	TBYTE PTR [ESI]
	SUB	EAX,3FFFH
	IMUL	EAX,19728
	SAR	EAX,16
	INC	EAX
	MOV	Exponent,EAX
	MOV	EAX,18
	SUB	EAX,Exponent
	FABS
	CALL	FPower10
	FRNDINT
	FLD	FCon1E18
	FCOMP
	FSTSW	StatWord
	FWAIT
	TEST	StatWord,mC0+mC3
	JE	@@11
	FIDIV	DCon10
	INC	Exponent
@@11:	FBSTP	BCDValue
	LEA	EDI,[EBX].fdDigits
	MOV	EDX,9
	FWAIT
@@12:	MOV	AL,BCDValue[EDX-1].b0
	MOV	AH,AL
	SHR	AL,4
	AND	AH,0FH
	ADD	AX,'00'
	STOSW
	DEC	EDX
	JNE	@@12
	XOR	AL,AL
	STOSB
@@20:	MOV	EDI,Exponent
	ADD	EDI,Decimals
	JNS	@@21
	XOR	EAX,EAX
	JMP	@@1
@@21:	CMP	EDI,Precision
	JB	@@22
	MOV	EDI,Precision
@@22:	CMP	EDI,18
	JAE	@@26
	CMP	[EBX].fdDigits[EDI],'5'
	JB	@@25
@@23:	MOV	[EBX].fdDigits[EDI],0
	DEC	EDI
	JS	@@24
	INC	[EBX].fdDigits[EDI]
	CMP	[EBX].fdDigits[EDI],'9'
	JA	@@23
	JMP	@@30
@@24:	MOV	[EBX].fdDigits.w0,'1'
	INC	Exponent
	JMP	@@30
@@26:	MOV	EDI,18
@@25:	MOV	[EBX].fdDigits[EDI],0
	DEC	EDI
	JS	@@32
	CMP	[EBX].fdDigits[EDI],'0'
	JE	@@25
@@30:	MOV	DX,[ESI].w8
@@30a:MOV	EAX,Exponent
@@31:	SHR	DX,15
	MOV	[EBX].fdExponent,AX
	MOV	[EBX].fdNegative,DL
	RET
@@32: XOR EDX,EDX
      JMP @@30a


; Convert Currency to decimal

CurrToDecimal:

	MOV	EAX,[ESI].d0
	MOV	EDX,[ESI].d4
	MOV	ECX,EAX
	OR	ECX,EDX
	JE	@@20
	OR	EDX,EDX
	JNS	@@1
	NEG	EDX
	NEG	EAX
	SBB	EDX,0
@@1:	XOR	ECX,ECX
	MOV	EDI,Decimals
	OR	EDI,EDI
	JGE	@@2
	XOR	EDI,EDI
@@2:	CMP	EDI,4
	JL	@@4
	MOV	EDI,4
@@3:	INC	ECX
	SUB	EAX,Const1E18Lo
	SBB	EDX,Const1E18Hi
	JNC	@@3
	DEC	ECX
	ADD	EAX,Const1E18Lo
	ADC	EDX,Const1E18Hi
@@4:	MOV	Temp.d0,EAX
	MOV	Temp.d4,EDX
	FILD	Temp
	MOV	EDX,EDI
	MOV	EAX,4
	SUB	EAX,EDX
	JE	@@5
	FIDIV	DCon10[EAX*4-4]
@@5:	FBSTP	BCDValue
	LEA	EDI,[EBX].fdDigits
	FWAIT
	OR	ECX,ECX
	JNE	@@11
	MOV	ECX,9
@@10:	MOV	AL,BCDValue[ECX-1].b0
	MOV	AH,AL
	SHR	AL,4
	JNE	@@13
	MOV	AL,AH
	AND	AL,0FH
	JNE	@@14
	DEC	ECX
	JNE	@@10
	JMP	@@20
@@11:	MOV	AL,CL
	ADD	AL,'0'
	STOSB
	MOV	ECX,9
@@12:	MOV	AL,BCDValue[ECX-1].b0
	MOV	AH,AL
	SHR	AL,4
@@13:	ADD	AL,'0'
	STOSB
	MOV	AL,AH
	AND	AL,0FH
@@14:	ADD	AL,'0'
	STOSB
	DEC	ECX
	JNE	@@12
	MOV	EAX,EDI
	LEA	ECX,[EBX].fdDigits[EDX]
	SUB	EAX,ECX
@@15:	MOV	BYTE PTR [EDI],0
	DEC	EDI
	CMP	BYTE PTR [EDI],'0'
	JE	@@15
	MOV	EDX,[ESI].d4
	SHR	EDX,31
	JMP	@@21
@@20:	XOR	EAX,EAX
	XOR	EDX,EDX
	MOV	[EBX].fdDigits,AL
@@21:	MOV	[EBX].fdExponent,AX
	MOV	[EBX].fdNegative,DL
	RET

; function TextToFloat(var Buffer; var Value;
;   ValueType: TFloatValue): Boolean;

TextToFloat:

	ARG	Buffer,DWORD,1
	ARG	Value,DWORD,1
	ARG	ValueType,BYTE,4
	LOC	Temp,DWORD,1
	LOC	CtrlWord,WORD,1

	ENTRY	FAR
	PUSH	EDI
	PUSH	ESI
	PUSH	EBX
	MOV	ESI,EAX
	MOV	EDI,EDX
	MOV	EBX,ECX
	FSTCW	CtrlWord
	FCLEX
	FLDCW	CWNear
	FLDZ
	CALL	SkipBlanks
	MOV	BH,[ESI]
	CMP	BH,'+'
	JE	@@1
	CMP	BH,'-'
	JNE	@@2
@@1:	INC	ESI
@@2:	MOV	ECX,ESI
	CALL	GetDigitStr
	XOR	EDX,EDX
	MOV	AL,[ESI]
	CMP	AL,DecimalSeparator
	JNE	@@3
	INC	ESI
	CALL	GetDigitStr
	NEG	EDX
@@3:	CMP	ECX,ESI
	JE	@@9
	MOV	AL,[ESI]
	AND	AL,0DFH
	CMP	AL,'E'
	JNE	@@4
	INC	ESI
	PUSH	EDX
	CALL	GetExponent
	POP	EAX
	ADD	EDX,EAX
@@4:	CALL	SkipBlanks
	CMP	BYTE PTR [ESI],0
	JNE	@@9
	MOV	EAX,EDX
	CMP	BL,fvCurrency
	JNE	@@5
	ADD	EAX,4
@@5:	CALL	FPower10
	CMP	BH,'-'
	JNE	@@6
	FCHS
@@6:	CMP	BL,fvExtended
	JE	@@7
	FISTP	QWORD PTR [EDI]
	JMP	@@8
@@7:	FSTP	TBYTE PTR [EDI]
@@8:	FSTSW	AX
	TEST	AX,mIE+mOE
	JNE	@@10
	MOV	AL,1
	JMP	@@11
@@9:	FSTP	ST(0)
@@10:	XOR	EAX,EAX
@@11:	FCLEX
	FLDCW	CtrlWord
	FWAIT
	POP	EBX
	POP	ESI
	POP	EDI
	EXIT

; Skip blanks

SkipBlanks:

@@1:	LODSB
	OR	AL,AL
	JE	@@2
	CMP	AL,' '
	JE	@@1
@@2:	DEC	ESI
	RET

; Process string of digits
; Out	EDX = Digit count

GetDigitStr:

	XOR	EAX,EAX
	XOR	EDX,EDX
@@1:	LODSB
	SUB	AL,'0'+10
	ADD	AL,10
	JNC	@@2
	FIMUL	DCon10
	MOV	Temp,EAX
	FIADD	Temp
	INC	EDX
	JMP	@@1
@@2:	DEC	ESI
	RET

; Get exponent
; Out	EDX = Exponent (-4999..4999)

GetExponent:

	XOR	EAX,EAX
	XOR	EDX,EDX
	MOV	CL,[ESI]
	CMP	CL,'+'
	JE	@@1
	CMP	CL,'-'
	JNE	@@2
@@1:	INC	ESI
@@2:	MOV	AL,[ESI]
	SUB	AL,'0'+10
	ADD	AL,10
	JNC	@@3
	INC	ESI
	IMUL	EDX,10
	ADD	EDX,EAX
	CMP	EDX,500
	JB	@@2
@@3:	CMP	CL,'-'
	JNE	@@4
	NEG	EDX
@@4:	RET

	END
