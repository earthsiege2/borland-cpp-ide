
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

	EXTRN	_ReadChar:NEAR, _SeekEof:NEAR, _ValExt:NEAR, SetInOutRes:NEAR

	PUBLIC	_ReadExt

	.CODE

;	FUNCTION _ReadExt( t: Text ) : Extended;

_ReadExt PROC

; ->	EAX	Pointer to text record
; <-	FST(0)	Result

	PUSH	EBX
	PUSH	ESI
	PUSH	EDI
	SUB	ESP,68			; var numbuf: array[0..64] of char;

	MOV	ESI,EAX
	CALL	_SeekEof
	DEC	AL
	JZ	@@eof

	MOV	EDI,ESP			; EDI -> numBuf[0]
	MOV	BL,64
@@loop:
	MOV	EAX,ESI
	CALL	_ReadChar
	CMP	AL,' '
	JBE	@@endNum
	STOSB
	DEC	BL
	JNZ	@@loop
@@convert:
	MOV	byte ptr [EDI],0
	MOV	EAX,ESP			; EAX -> numBuf
	PUSH	EDX			; allocate code result
	MOV	EDX,ESP			; pass pointer to code
	CALL	_ValExt			; convert
	POP	EDX			; pop code result into EDX
	TEST	EDX,EDX
	JZ	@@exit
        MOV     EAX,106
	CALL	SetInOutRes

@@exit:
	ADD	ESP,68
	POP	EDI
	POP	ESI
	POP	EBX
	RET

@@endNum:
	CMP	AL,eof
	JE	@@convert
	DEC	[ESI].BufPos
	JMP	@@convert

@@eof:
	FLDZ
	JMP	@@exit


_ReadExt ENDP

	END
