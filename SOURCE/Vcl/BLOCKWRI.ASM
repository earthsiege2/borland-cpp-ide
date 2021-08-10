
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

	EXTRN	WriteFile:NEAR, GetLastError:NEAR, SetInOutRes:NEAR

	PUBLIC	_BlockWrite

	.CODE

;	PROCEDURE _BlockWrite( f: File; buffer: Pointer; recCnt: Longint; VAR result: Longint);

_BlockWrite PROC

; ->	EAX	Pointer to file variable
;	EDX	Pointer to buffer
;	ECX	Number of records to write
;	[ESP+4]	Pointer to result or nil

	PUSH	EBX
	PUSH	ESI

	MOV	EBX,EAX
	MOV	ESI,EDX

	MOV	EAX,[EAX].Mode		; File must be fmOutput or fmInOut
	SUB	EAX,fmOutput
	CMP	EAX,fmInOut-fmOutput
	JA	@@fileNotOpen

;	WriteFile(f.Handle, buffer, recCnt*f.RecSize, @result, Nil);

	PUSH	ECX

	PUSH	0			; space for OS result
	MOV	EAX,ESP

	PUSH	0			; pass lpOverlapped
	PUSH	EAX			; pass @result

	MOV	EAX,[EBX].RecSize
	MUL	ECX
	PUSH	EAX			; pass nNumberOfBytesToRead

	PUSH	ESI			; pass lpBuffer
	PUSH	[EBX].Handle		; pass hFile
	CALL	WriteFile
	DEC	EAX			; check EAX = TRUE
	POP	EAX			; pop result
	POP	ECX
	JNZ	@@error

	XOR	EDX,EDX
	DIV	[EBX].RecSize		; recCnt = result DIV f.RecSize
	MOV	EDX,[ESP+4+8]
	TEST	EDX,EDX
	JE	@@noResult
	MOV	[EDX],EAX
@@exit:
	POP	ESI
	POP	EBX

	RET	4

@@noResult:
	CMP	EAX,ECX
	JE	@@exit
	MOV	EAX,101
	JMP	@@errExit
@@error:
	CALL	GetLastError
@@errExit:
	CALL	SetInOutRes
	XOR	EAX,EAX
	JMP	@@exit

@@fileNotOpen:
	MOV	EAX,103
	JMP	@@errExit

_BlockWrite ENDP

	END
