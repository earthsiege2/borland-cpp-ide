
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

	EXTRN	SetFilePointer:NEAR, GetLastError:NEAR
        EXTRN   SetInOutRes:NEAR, InOutError:NEAR

	PUBLIC	_FilePos

	.CODE

;	PROCEDURE _FilePos( f: File );

_FilePos PROC

; ->	EAX	Pointer to file variable

	PUSH	EBX
	MOV	EBX,EAX

	MOV	EDX,[EBX].Mode		; check whether file is open
	SUB	EDX,fmInput
	CMP	EDX,fmInOut-fmInput
	JA	@@fileNotOpen

	PUSH	FILE_CURRENT
	PUSH	0
	PUSH	0
	PUSH	[EBX].Handle
	CALL	SetFilePointer		; get current position
	CMP	EAX,-1
	JZ	@@error

	XOR	EDX,EDX
        DIV	[EBX].RecSize		; position is in records

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

_FilePos ENDP

	END

