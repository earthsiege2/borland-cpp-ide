
; *******************************************************
; *							*
; *     Delphi Runtime Library                          *
; *							*
; *	Copyright (c) 1996,98 Inprise Corporation	*
; *							*
; *******************************************************

	INCLUDE	SE.ASM
	INCLUDE	FILEIO.ASM


	.386
	.MODEL	FLAT

	EXTRN	_ReadChar:NEAR

	PUBLIC	_Eoln

	.CODE

;	FUNCTION _Eoln( t: Text ) : Boolean;

_Eoln	PROC

; ->	EAX	Pointer to text record
; <-	AL	Boolean result

	CMP	[EAX].Mode,fmInput
	JNE	@@readChar
	MOV	EDX,[EAX].BufPos
	CMP	EDX,[EAX].BufEnd
	JAE	@@readChar
	ADD	EDX,[EAX].BufPtr
	MOV	AL,0
	MOV	CL,[EDX]
	CMP	CL,cr
	JE	@@cr
	CMP	CL,eof
	JE	@@eof
	RET
@@cr:
@@eof:
	MOV	AL,1
	RET

@@readChar:
	PUSH	EAX
	CALL	_ReadChar
	POP	EDX
	CMP	AL,eof
	JE	@@eof
	DEC	[EDX].BufPos
	CMP	AL,cr
	JE	@@cr
	MOV	AL,0
	RET

_Eoln	ENDP

	END
