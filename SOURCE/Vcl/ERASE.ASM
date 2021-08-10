
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

	EXTRN	DeleteFileA:NEAR, GetLastError:NEAR, SetInOutRes:NEAR

	PUBLIC	_Erase

	.CODE

;	PROCEDURE _Erase( f: Text or File );

_Erase	PROC

; ->	EAX	Pointer to file variable

	MOV	EDX,[EAX].Mode
	SUB	EDX,fmClosed
	CMP	EDX,fmInOut-fmClosed
	JA      @@notAssigned
	LEA	EAX,[EAX].FileName
	PUSH	EAX
	CALL	DeleteFileA
	DEC	EAX
	JNZ	@@error
@@exit:
	RET

@@error:
	CALL	GetLastError
@@errExit:
	CALL    SetInOutRes
	JMP	@@exit

@@notAssigned:
	MOV	EAX,102
	JMP	@@errExit

_Erase	ENDP

	END
