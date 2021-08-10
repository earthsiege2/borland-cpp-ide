
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

	PUBLIC	_SeekEof

	.CODE

;	FUNCTION _SeekEof( t: Text ) : Boolean;

_SeekEof PROC

; ->	EAX	Pointer to text record
; <-	AL	Boolean result

	PUSH	EBX
	MOV	EBX,EAX
@@loop:
	MOV	EAX,EBX
	CALL	_ReadChar
	CMP	AL,' '
	JA	@@exit
	CMP	AL,eof
	JE	@@eof
	JMP	@@loop
@@exit:
	DEC	[EBX].BufPos
	POP	EBX
	MOV	AL,0
	RET

@@eof:
	MOV	AL,1
	POP	EBX
	RET

_SeekEof ENDP

	END
