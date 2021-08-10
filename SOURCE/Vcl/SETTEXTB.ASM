
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

	PUBLIC	_SetTextBuf

	.CODE

;	PROCEDURE _SetTextBuf( f: Text; p: Pointer; size: Longint );

_SetTextBuf PROC

; ->	EAX	Pointer to file variable
;	EDX	Pointer to new buffer
;	ECX	Size of new buffer

	MOV	[EAX].BufPtr,EDX
	XOR	EDX,EDX
	MOV	[EAX].BufSize,ECX
	MOV	[EAX].BufPos,EDX
	MOV	[EAX].BufEnd,EDX

	RET

_SetTextBuf ENDP

	END
