
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

	EXTRN	ReadFile:NEAR, GetLastError:NEAR, SetInOutRes:NEAR

	PUBLIC	_BlockRead

	.CODE

;	PROCEDURE _BlockRead( f: File; buffer: Pointer; recCnt: Longint; var result: Longint);

_BlockRead PROC

; ->	EAX	Pointer to file variable
;	EDX	Pointer to buffer
;	ECX	Number of records to read
;	[ESP+4]	Pointer to result or nil

	PUSH	EBX
	PUSH	ESI

	MOV	EBX,EAX
	MOV	ESI,EDX

	MOV	EDX,[EBX].Mode		; File must be open
	SUB	EDX,fmInput
	CMP	EDX,fmInOut-fmInput
	JA	@@fileNotOpen

;	ReadFile(f.Handle, buffer, recCnt*f.RecSize, @result, Nil);

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
	CALL	ReadFile
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
	MOV	EAX,100
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

_BlockRead ENDP

	END
