
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

	PUBLIC	_ReadLn

	.CODE

;	PROCEDURE _ReadLn( t: Text );

_ReadLn	PROC

; ->	EAX	Pointer to text record

	PUSH	EBX
	MOV	EBX,EAX
@@loop:
	MOV	EAX,EBX
	CALL	_ReadChar

	CMP	AL,eof
	JE	@@eof
	CMP	AL,cr
	JNE	@@loop

	MOV	EAX,EBX
	CALL	_ReadChar

	CMP	AL,lf
	JE	@@exit
	CMP	AL,eof
	JE	@@eof
	DEC	[EBX].BufPos
@@exit:
	POP	EBX
	RET

@@eof:
	POP	EBX
	RET

_ReadLn ENDP

	END
