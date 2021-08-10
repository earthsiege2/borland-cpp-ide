
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

	EXTRN	SetEndOfFile:NEAR, GetLastError:NEAR, InOutError:NEAR, SetInOutRes:NEAR

	PUBLIC	_Truncate

	.CODE

;	PROCEDURE _Truncate( f: Text or File );

_Truncate PROC

; ->	EAX	Pointer to file variable

	MOV	EDX,[EAX].Mode		; check whether file is open
	SUB	EDX,fmInput
	CMP	EDX,fmInOut-fmInput
	JA	@@fileNotOpen

	PUSH	[EAX].Handle
	CALL	SetEndOfFile
	DEC	EAX
	JNZ	InOutError
	RET

@@fileNotOpen:
	MOV	EAX,103
	JMP	SetInOutRes

_Truncate ENDP

	END
