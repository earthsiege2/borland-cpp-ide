
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

	EXTRN	_ReadChar:NEAR, _ResetText:NEAR, Input:DWORD, SetInOutRes:NEAR

	PUBLIC	_ReadString, _ReadCString

	.CODE

;	PROCEDURE _ReadString( t: Text; var s: string; maxLen: Longint );

_ReadString PROC

; ->	EAX	Pointer to text record
;	EDX	Pointer to string
;	ECX	Maximum length of string

	PUSH	EDX
	INC	EDX
	CALL	ReadLine
	POP	EDX
	MOV	[EDX],CL
	RET

_ReadString ENDP

;	PROCEDURE _ReadCString( t: Text; s: PChar; maxLen: Longint );

_ReadCString PROC

; ->	EAX	Pointer to text record
;	EDX	Pointer to string
;	ECX	Maximum length of string

	PUSH	EDX
	CALL	ReadLine
	POP	EDX
	MOV	byte ptr [EDX+ECX],0
	RET

_ReadCString ENDP


;	PROCEDURE ReadLine( t: Text; buf: Pointer; maxLen: Longint );

ReadLine PROC

; ->	EAX	Pointer to text record
;	EDX	Pointer to buffer
;	ECX	Maximum count of chars to read
; <-	ECX	Actual count of chars in buffer


	PUSH	EBX
	PUSH	ESI
	PUSH	EDI
	PUSH	ECX

	MOV	EBX,EAX
	MOV	ESI,ECX
	MOV	EDI,EDX

	CMP	[EBX].Mode,fmInput
	JNE	@@fileNotOpenForInput

@@isOpenNow:

	TEST	ESI,ESI
	JLE	@@exit

	MOV	EDX,[EBX].BufPos
	MOV	ECX,[EBX].BufEnd
	SUB	ECX,EDX
	ADD	EDX,[EBX].BufPtr

@@loop:
	DEC	ECX
	JL	@@readChar
	MOV	AL,[EDX]
	INC	EDX
@@cont:
	CMP	AL,eof
	JE	@@exit

	CMP	AL,cr
	JE	@@cr

	STOSB
	DEC	ESI
	JG	@@loop
	JMP	@@finish

@@cr:
	DEC	EDX
@@finish:
	SUB	EDX,[EBX].BufPtr
	MOV	[EBX].BufPos,EDX
@@exit:
	POP	ECX
	SUB	ECX,ESI
	POP	EDI
	POP	ESI
	POP	EBX
	RET

@@readChar:
	MOV	[EBX].BufPos,EDX
	MOV	EAX,EBX
	CALL	_ReadChar
	MOV	EDX,[EBX].BufPos
	MOV	ECX,[EBX].BufEnd
	SUB	ECX,EDX
	ADD	EDX,[EBX].BufPtr
	JMP	@@cont

@@fileNotOpenForInput:
	CMP	EAX,offset Input
	JE	@@openInput
@@notOpenError:
	MOV	EAX,104
        CALL    SetInOutRes
	JMP	@@exit

@@openInput:
	CALL	_ResetText
	CMP	[EBX].Mode,fmInput
	JE	@@isOpenNow
	JMP	@@notOpenError

ReadLine ENDP





	END
