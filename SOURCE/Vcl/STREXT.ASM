
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

	EXTRN	_Pow10:NEAR
	PUBLIC	_Str0Ext, _Str1Ext, _Str2Ext

	.CODE

one	DQ	1.0
ten	DQ	10.0
tenE17	DQ	1E17
tenE18	DQ	1E18

;	PROCEDURE _Str0Ext( val: Extended; var s: String );

_Str0Ext PROC

; ->	[ESP+4]	Extended value
;	EAX	Pointer to string

	MOV	ECX,EAX			; pass string
	MOV	EAX,23			; pass default field width
	OR	EDX,-1			; pass precision -1
	JMP	_Str2Ext

_Str0Ext ENDP


;	PROCEDURE _Str1Ext( val: Extended; width: Longint; var s: String );

_Str1Ext PROC

; ->	[ESP+4]	Extended value
;	EAX	Field width
;	EDX	Pointer to string

	MOV	ECX,EDX
	OR	EDX,-1			; pass precision -1
	JMP	_Str2Ext

_Str1Ext ENDP


;	PROCEDURE _Str2Ext( val: Extended; width, precision: Longint; var s: String );

_Str2Ext PROC

; ->	[ESP+4]	Extended value
;	EAX	Width
;	EDX	Precision
;	ECX	Pointer to string

MAXDIGS	EQU	256

	FLD	tbyte ptr [ESP+4]

	PUSH	EBX
	PUSH	ESI
	PUSH	EDI
	MOV	EBX,EAX
	MOV	ESI,EDX
	PUSH	ECX			; save string pointer
	SUB	ESP,MAXDIGS		; VAR digBuf: array [0..MAXDIGS-1] of Char

;	limit width to 255

	CMP	EBX,255			; if width > 255 then width := 255;
	JLE	@@1
	MOV	EBX,255
@@1:

;	save sign bit in bit 0 of EDI, take absolute value of val, check for
;	Nan and infinity.

	FLD	ST(0)
	FSTP	tbyte ptr [ESP]
	XOR	EAX,EAX
	MOV	AX,word ptr [ESP+8]
	MOV	EDI,EAX
	SHR	EDI,15
	AND	AX,7FFFH
	CMP	AX,7FFFH
	JE	@@nanInf
	FABS

;	if precision < 0 then do scientific else do fixed;

	TEST	ESI,ESI
	JGE	@@fixed

;	the following call finds a decimal exponent and a reduced
;	mantissa such that val = mant * 10**exp

	CALL	_ScaleExt		; val is FST(0), exp is EAX

;	for scientific notation, we have width - 8 significant digits
;	however, we can not have less than 2 or more than 18 digits.

@@scientific:

	MOV	ESI,EBX			; digCnt := width - 8;
	SUB	ESI,8
	CMP	ESI,2			; if digCnt < 2 then digCnt := 2
	JGE	@@2
	MOV	ESI,2
	JMP	@@3
@@2:
	CMP	ESI,18			; else if digCnt > 18 then digCnt := 18;
	JLE	@@3
	MOV	ESI,18
@@3:

;	_EmitDigits( val, digCnt, digBuf )

	MOV	EDX,ESP			; pass digBuf
	PUSH	EAX			; save exponent
	MOV	EAX,ESI			; pass digCnt
	CALL	_EmitDigits		; convert val to ASCII

	MOV	EDX,EDI			; save sign in EDX
	MOV	EDI,[ESP+MAXDIGS+4]	; load result string pointer

	MOV	[EDI],BL		; length of result string := width
	INC	EDI

	MOV	AL,' '			; prepare for leading blanks and sign

	MOV	ECX,EBX			; blankCnt := width - digCnt - 8
	SUB	ECX,ESI
	SUB	ECX,8
	JLE	@@4

	REP	STOSB			; emit blankCnt blanks
@@4:
	SUB	[EDI-1],CL		; if blankCnt < 0, adjust length

	TEST	DL,DL			; emit the sign (' ' or '-')
	JE	@@5
	MOV	AL,'-'
@@5:
	STOSB

	POP	EAX

	MOV	ECX,ESI			; emit digCnt digits

	MOV	ESI,ESP			; point ESI to digBuf

	CMP	byte ptr [ESI],'0'
	JE	@@5a			; if rounding overflowed, adjust exponent and ESI
	INC	EAX
	DEC	ESI
@@5a:
	INC	ESI

	MOVSB				; emit one digit
	MOV	byte ptr [EDI],'.'	; emit dot
	INC	EDI			; adjust dest pointer
	DEC	ECX			; adjust count

	REP	MOVSB

	MOV	byte ptr [EDI],'E'

	MOV	CL,'+'			; emit sign of exponent ('+' or '-')
	TEST	EAX,EAX
	JGE	@@6
	MOV	CL,'-'
	NEG	EAX
@@6:
	MOV	[EDI+1],CL

	XOR	EDX,EDX			; emit exponent
	MOV	CX,10
	DIV	CX
	ADD	DL,'0'
	MOV	[EDI+5],DL

	XOR	EDX,EDX
	DIV	CX
	ADD	DL,'0'
	MOV	[EDI+4],DL

	XOR	EDX,EDX
	DIV	CX
	ADD	DL,'0'
	MOV	[EDI+3],DL

	ADD	AL,'0'
	MOV	[EDI+2],AL

	JMP	@@exit

@@fixed:

;	FST(0)	= value >= 0.0
;	EBX	= width
;	ESI	= precision
;	EDI	= sign

	CMP	ESI,MAXDIGS-40		; else if precision > MAXDIGS-40 then precision := MAXDIGS-40;
	JLE	@@6a
	MOV	ESI,MAXDIGS-40
@@6a:
	FCOM	ten
	FSTSW	AX
	SAHF
	MOV	EAX,0
	JB	@@7

	CALL	_ScaleExt		; val is FST(0), exp is EAX

	CMP	EAX,35			; if val is too large, use scientific
	JG	@@scientific

@@7:
;	FST(0)	= scaled value, 0.0 <= value < 10.0
;	EAX	= exponent, 0 <= exponent

;	intDigCnt := exponent + 1;

	INC	EAX

;	_EmitDigits( value, intDigCnt + precision, digBuf );

	MOV	EDX,ESP
	PUSH	EAX
	ADD	EAX,ESI
	CALL	_EmitDigits
	POP	EAX

;	Now we need to check whether rounding to the right number of
;	digits overflowed, and if so, adjust things accordingly

	MOV	EDX,ESI			; put precision in EDX
	MOV	ESI,ESP			; point EDI to digBuf
	CMP	byte ptr [ESI],'0'
	JE	@@8
	INC	EAX
	DEC	ESI
@@8:
	INC	ESI

	MOV	ECX,EAX			; numWidth := sign + intDigCnt;
	ADD	ECX,EDI

	TEST	EDX,EDX			; if precision > 0 then
	JE	@@9
	INC	ECX			;   numWidth := numWidth + 1 + precision
	ADD	ECX,EDX

	CMP	EBX,ECX			; if width <= numWidth
	JG	@@9
	MOV	EBX,ECX			;   width := numWidth
@@9:
	PUSH	EAX
	PUSH	EDI

	MOV	EDI,[ESP+MAXDIGS+2*4]	; point EDI to dest string

	MOV	[EDI],BL		; store final length in dest string
	INC	EDI

	SUB	EBX,ECX			; width := width - numWidth
	MOV	ECX,EBX
	JLE	@@10

	MOV	AL,' '			; emit width blanks
	REP	STOSB
@@10:
	SUB	[EDI-1],CL		; if blankCnt < 0, adjust length
	POP	EAX
	POP	ECX

	TEST	EAX,EAX
	JE	@@11

	MOV	byte ptr [EDI],'-'
	INC	EDI

@@11:
	REP	MOVSB			; copy intDigCnt digits

	TEST	EDX,EDX			; if precision > 0 then
	JE	@@12

	MOV	byte ptr [EDI],'.'	;   emit '.'
	INC	EDI
	MOV	ECX,EDX			;   emit precision digits
	REP	MOVSB

@@12:

@@exit:
	ADD	ESP,MAXDIGS
	POP	ECX
	POP	EDI
	POP	ESI
	POP	EBX
	RET	12

@@nanInf:
;	here: EBX = width, ECX = string pointer, EDI = sign, [ESP] = value

	FSTP	ST(0)
	CMP	[ESP+4],80000000H
	MOV	ESI,offset nanStr
	JNE	@@13
	DEC	EDI
	MOV	ESI,offset plusInfStr
	JNZ	@@13
	MOV	ESI,offset minInfStr
@@13:
	MOV	EDI,ECX
	MOV	ECX,EBX
	MOV	[EDI],CL
	INC	EDI
	SUB	CL,[ESI]
	JBE	@@14
	MOV	AL,' '
	REP	STOSB
@@14:
	SUB	[EDI-1],CL
	MOV	CL,[ESI]
	INC	ESI
	REP	MOVSB

	JMP	@@exit

nanStr		DB	3,'Nan'
plusInfStr	DB	4,'+Inf'
minInfStr	DB	4,'-Inf'

_Str2Ext ENDP


_EmitDigits PROC

; ->	FST(0)	Value, 0 <= value < 10.0
;	EAX	Count of digits to generate
;	EDX	Pointer to digit buffer

	PUSH	EDI
	MOV	EDI,EDX
	MOV	ECX,EAX

	SUB	ESP,10			; VAR bcdBuf: array [0..9] of Byte
	MOV	byte ptr [EDI],'0'	; digBuf[0] := '0';
	FMUL	tenE17			; val := Round(val*1e17);
	FRNDINT

	FCOM	tenE18			; if val >= 1e18 then
	FSTSW	AX
	SAHF
	JB	@@1

	FSUB	tenE18			;   val := val - 1e18;
	MOV	byte ptr [EDI],'1'	;   digBuf[0] := '1';
@@1:
	FBSTP	[ESP]			; store packed bcd digits in bcdBuf

	MOV	EDX,8
	INC	EDI

@@2:
	WAIT
	MOV	AL,[ESP+EDX]		; unpack 18 bcd digits in 9 bytes
	MOV	AH,AL			; into 9 words = 18 bytes
	SHR	AL,4
	AND	AH,0FH
	ADD	AX,'00'
	STOSW
	DEC	EDX
	JNS	@@2

	SUB	ECX,18			; we need at least digCnt digits
	JL	@@3			; we have generated 18

	MOV	AL,'0'			; if this is not enough, append zeroes
	REP	STOSB
	JMP	@@4			; in this case, we don't need to round

@@3:
	ADD	EDI,ECX			; point EDI to the round digit
	CMP	byte ptr [EDI],'5'
	JL	@@4
@@5:
	DEC	EDI
	INC	byte ptr [EDI]
	CMP	byte ptr [EDI],'9'
	JLE	@@4
	MOV	byte ptr [EDI],'0'
	JMP	@@5

@@4:
	ADD	ESP,10
	POP	EDI
	RET

_EmitDigits ENDP


_ScaleExt PROC

; ->	FST(0)	Value
; <-	EAX	exponent (base 10)
;	FST(0)	Value / 10**eax

	PUSH	EBX
	SUB	ESP,12

	XOR	EBX,EBX

@@normLoop:				; loop necessary for denormals

	FLD	ST(0)
	FSTP	tbyte ptr [ESP]
	MOV	AX,[ESP+8]
	TEST	AX,AX
	JE	@@testZero
@@cont:
	SUB	AX,3FFFH
	MOV	DX,4D10H	; log10(2) * 2**16
	IMUL	DX
	MOVSX	EAX,DX		; exp10 = exp2 * log10(2)
	NEG	EAX
	JE	@@exit
	SUB	EBX,EAX
	CALL	_Pow10
	JMP	@@normLoop

@@exit:
	ADD	ESP,12
	MOV	EAX,EBX
	POP	EBX
	RET

@@testZero:
	CMP     dword ptr [ESP+4],0
	JNE	@@cont
	CMP	dword ptr [ESP+0],0
	JNE	@@cont
	JMP	@@exit

_ScaleExt ENDP

	END
