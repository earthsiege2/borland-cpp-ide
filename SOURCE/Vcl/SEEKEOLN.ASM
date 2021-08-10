
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

	PUBLIC	_SeekEoln

	.CODE

;	FUNCTION _SeekEoln( t: Text ) : Boolean;

_SeekEoln PROC

; ->	EAX	Pointer to text record
; <-	AL	Boolean result

	PUSH	EBX
	MOV	EBX,EAX
@@loop:
	MOV	EAX,EBX
	CALL	_ReadChar
	CMP	AL,' '
	JA	@@falseExit
	CMP	AL,eof
	JE	@@eof
	CMP	AL,cr
	JNE	@@loop

	MOV	AL,1
	JMP	@@exit

@@falseExit:
	MOV	AL,0
@@exit:
	DEC	[EBX].BufPos
	POP	EBX
	RET

@@eof:
	MOV	AL,1
	POP	EBX
	RET

_SeekEoln ENDP

	END
