
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

	EXTRN	SetFilePointer:NEAR, GetLastError:NEAR, SetInOutRes:NEAR
        EXTRN   InOutError:NEAR

	PUBLIC	_Seek

	.CODE

;	PROCEDURE _Seek( f: File; recNum: Longint );

_Seek	PROC

; ->	EAX	Pointer to file variable
;	EDX	Record number

	MOV	ECX,EAX
	MOV	EAX,[ECX].Mode		; check whether file is open
	SUB	EAX,fmInput
	CMP	EAX,fmInOut-fmInput
	JA	@@fileNotOpen

;	SetFilePointer(f.Handle, recNum*f.RecSize, FILE_BEGIN

	PUSH	FILE_BEGIN		; pass dwMoveMethod
	MOV	EAX,[ECX].RecSize
	MUL	EDX
	PUSH	0			; pass lpDistanceToMoveHigh
	PUSH	EAX			; pass lDistanceToMove
	PUSH	[ECX].Handle		; pass hFile
	CALL	SetFilePointer		; get current position
	INC	EAX
	JZ	InOutError

@@exit:
	RET

@@fileNotOpen:
	MOV	EAX,103
        JMP     SetInOutRes

_Seek	ENDP

	END
