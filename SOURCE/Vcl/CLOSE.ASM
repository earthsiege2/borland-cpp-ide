
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

	EXTRN	GetLastError:NEAR, Input:DWORD, SetInOutRes:NEAR

	PUBLIC	_Close

	.CODE

;	PROCEDURE _Close( f: File or Text);

_Close	PROC

; ->	EAX	Pointer to file variable

	PUSH	EBX
	MOV	EBX,EAX

	MOV	EDX,[EAX].Mode		; check whether file is open
	SUB	EDX,fmInput
	JE	@@isInput
	CMP	EDX,fmInOut-fmInput
	JA	@@fileNotOpen

	CALL	[EAX].InOutFunc
	TEST	EAX,EAX
	JNE	@@error
	MOV	EAX,EBX
@@isInput:
	CALL	[EBX].CloseFunc
	TEST	EAX,EAX
	JNE	@@error
@@exit:
	POP	EBX
	RET

@@error:
	CALL	SetInOutRes
	JMP	@@exit

@@fileNotOpen:
	CMP	EAX,offset Input
        JE	@@exit
	MOV	EAX,103
	JMP	@@error

_Close	ENDP

	END
