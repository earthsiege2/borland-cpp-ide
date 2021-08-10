
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

	EXTRN	_ReadChar:NEAR, _SeekEof:NEAR, _ValLong:NEAR, SetInOutRes:NEAR

	PUBLIC	_ReadLong

	.CODE

;	FUNCTION _ReadLong( t: Text ) : Longint;

_ReadLong PROC

; ->	EAX	Pointer to text record
; <-	EAX	Result

	PUSH	EBX
	PUSH	ESI
	PUSH	EDI
	SUB	ESP,36			; var numbuf: String[32];

	MOV	ESI,EAX
	CALL	_SeekEof
	DEC	AL
	JZ	@@eof

	MOV	EDI,ESP			; EDI -> numBuf[0]
	MOV	BL,32
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
	CALL	_ValLong		; convert
	POP	EDX			; pop code result into EDX
	TEST	EDX,EDX
	JZ	@@exit
        MOV     EAX,106
        CALL    SetInOutRes

@@exit:
	ADD	ESP,36
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
	XOR	EAX,EAX
	JMP	@@exit


_ReadLong ENDP

	END
