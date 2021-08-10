
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

	PUBLIC	_ReadRec

	.CODE

;	PROCEDURE _ReadRec( f: File; buffer: Pointer );

_ReadRec PROC

; ->	EAX	Pointer to file variable
;	EDX	Pointer to buffer

	PUSH	EBX

	MOV	EBX,EAX

	MOV	ECX,[EBX].Mode		; File must be open
	SUB	ECX,fmInput
	JE	@@skip
	SUB	ECX,fmInOut-fmInput
	JNE	@@fileNotOpen
@@skip:

;	ReadFile(f.Handle, buffer, f.RecSize, @result, Nil);

	PUSH	0			; space for OS result
	MOV	EAX,ESP

	PUSH	0			; pass lpOverlapped
	PUSH	EAX			; pass @result

	PUSH	[EBX].RecSize		; pass nNumberOfBytesToRead

	PUSH	EDX			; pass lpBuffer
	PUSH	[EBX].Handle		; pass hFile
	CALL	ReadFile
	POP	EDX			; pop result
	DEC	EAX			; check EAX = TRUE
	JNZ	@@error

	CMP	EDX,[EBX].RecSize	; result = f.RecSize ?
	JNE     @@readError
@@exit:
	POP	EBX

	RET

@@error:
	CALL	GetLastError
@@errExit:
	CALL	SetInOutRes
	JMP	@@exit

@@fileNotOpen:
	MOV	EAX,103
	JMP	@@errExit

@@readError:
	MOV	EAX,100
	JMP	@@errExit

_ReadRec ENDP

	END
