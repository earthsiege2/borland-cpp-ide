
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

	EXTRN	GetFileSize:NEAR, GetLastError:NEAR, SetInOutRes:NEAR, InOutError:NEAR

	PUBLIC	_FileSize

	.CODE

;	PROCEDURE _FileSize( f: File );

_FileSize PROC

; ->	EAX	Pointer to file variable
; <-	EAX	File size in records

	PUSH	EBX
	MOV	EBX,EAX

	MOV	EDX,[EBX].Mode		; check whether file is open
	SUB	EDX,fmInput
	CMP	EDX,fmInOut-fmInput
	JA	@@fileNotOpen

	PUSH	0			; get file size from OS
	PUSH	[EBX].Handle
	CALL	GetFileSize
	CMP	EAX,-1
	JZ	@@error

	XOR	EDX,EDX
	DIV	[EBX].RecSize

@@exit:
	POP	EBX
	RET

@@error:
	CALL	InOutError
	OR	EAX,-1
	JMP	@@exit

@@fileNotOpen:
	MOV	EAX,103
        CALL    SetInOutRes
	OR	EAX,-1
	JMP	@@exit

_FileSize ENDP

	END
