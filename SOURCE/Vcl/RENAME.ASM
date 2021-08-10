
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

	EXTRN	MoveFileA:NEAR, GetLastError:NEAR, __PasToCStr:NEAR, SetInOutRes:NEAR

	PUBLIC	_Rename

	.CODE

;	PROCEDURE _Rename( f: Text or File; newName: PChar );

_Rename	PROC

; ->	EAX	Pointer to file variable
;	EDX	Pointer to new name

	CMP	[EAX].Mode,fmClosed
	JNE	@@notAssigned

	TEST	EDX,EDX
	JNE	@@notNull
	MOV	EDX,offset @@nullByte
@@notNull:

	LEA	EAX,[EAX].FileName
	PUSH	EDX			; save new name
	PUSH	EAX			; save old name

	PUSH	EDX
	PUSH	EAX
	CALL	MoveFileA
	DEC	EAX
	POP	EAX			; restore old name
	POP	EDX			; restore new name
	JNZ	@@error

	MOV	CH,fNameLen / 2

@@loop:
	MOV	CL,[EDX]
	INC	EDX
	MOV	[EAX],CL
	INC	EAX
	TEST	CL,CL
	JE	@@exit

	MOV	CL,[EDX]
	INC	EDX
	MOV	[EAX],CL
	INC	EAX
	TEST	CL,CL
	JE	@@exit

	DEC	CH
	JNE	@@loop

	MOV	[EAX],CH
@@exit:
	RET

@@error:
	CALL	GetLastError
@@errExit:
	JMP     SetInOutRes

@@notAssigned:
	MOV	EAX,102
	JMP	@@errExit

@@nullByte:
	db	0

_Rename	ENDP

	END
