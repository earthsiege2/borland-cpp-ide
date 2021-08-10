
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

	EXTRN	_ReadChar:NEAR, _SeekEof:NEAR, _ValInt64:NEAR, SetInOutRes:NEAR

	PUBLIC	_ReadInt64

	.CODE

;	FUNCTION _ReadInt64( t: Text ) : Int64;

_ReadInt64 PROC

; ->	EAX	Pointer to text record
; <-	EAX:EDX	Result

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
	CALL	_ValInt64		; convert
	POP	ECX			; pop code result into EDX
	TEST	ECX,ECX
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


_ReadInt64 ENDP

	END
