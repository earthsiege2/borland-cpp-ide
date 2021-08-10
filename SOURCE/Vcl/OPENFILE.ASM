
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

	EXTRN	GetLastError:NEAR, CreateFileA:NEAR, CloseHandle:NEAR
	EXTRN	GetStdHandle:NEAR, FileMode:BYTE, SetInOutRes:NEAR, InOutError:NEAR

	PUBLIC	_ResetFile, _RewritFile

	.CODE

;	PROCEDURE OpenFile( VAR f: File; recSiz: Longint; mode: Longint );

OpenFile PROC

; ->	EAX	Pointer to file record
;	EDX	Record size
;	ECX	File mode

	PUSH	EBX
	PUSH	ESI
	PUSH	EDI

	MOV	EBX,EAX
	MOV	ESI,EDX
	MOV	EDI,ECX

	MOV	EDX,[EBX].Mode
	SUB	EDX,fmClosed
	JE	@@alreadyClosed
	CMP	EDX,fmInOut-fmClosed
	JA	@@notAssignedError

;	not yet closed: close it. File parameter is still in EAX

	CALL	[EBX].CloseFunc
	TEST	EAX,EAX
	JE	@@alreadyClosed
        CALL    SetInOutRes

@@alreadyClosed:

	MOV	[EBX].Mode,fmInOut
	MOV	[EBX].RecSize,ESI
	MOV	[EBX].CloseFunc,offset CloseFile
	MOV	[EBX].InOutFunc,offset @@NullProc

	CMP	byte ptr [EBX].FileName,0
	JE	@@isCon

	MOV	EAX,GENERIC_READ OR GENERIC_WRITE
	MOV	DL,FileMode
	AND	EDX,070H
	SHR	EDX,4-2
	MOV	EDX,dword ptr [@@shareTab+EDX]
	MOV	ECX,CREATE_ALWAYS

	SUB	EDI,3
	JE	@@calledByRewrite

	MOV	ECX,OPEN_EXISTING
	INC	EDI
	JE	@@skip

	MOV	EAX,GENERIC_WRITE
	INC	EDI
	MOV	[EBX].Mode,fmOutput
	JE	@@skip

	MOV	EAX,GENERIC_READ
	MOV	[EBX].Mode,fmInput

@@skip:
@@calledByRewrite:

;	CreateFile(t.FileName, EAX, EDX, Nil, ECX, FILE_ATTRIBUTE_NORMAL, 0);

	PUSH	0
	PUSH	FILE_ATTRIBUTE_NORMAL
	PUSH	ECX
	PUSH	0
	PUSH	EDX
	PUSH	EAX
	LEA	EAX,[EBX].FileName
	PUSH	EAX
	CALL	CreateFileA
@@checkHandle:
	CMP	EAX,-1
	JZ	@@error

	MOV	[EBX].Handle,EAX
@@exit:
	POP	EDI
	POP	ESI
	POP	EBX
	RET

@@NullProc:
	XOR	EAX,EAX
	RET

@@isCon:
	MOV	[EBX].CloseFunc,offset @@NullProc
	CMP	EDI,3
	JE	@@output
	PUSH	STD_INPUT_HANDLE
	JMP	@@1
@@output:
	PUSH	STD_OUTPUT_HANDLE
@@1:
	CALL	GetStdHandle
	JMP	@@checkHandle

@@notAssignedError:
	MOV	EAX,102
	JMP	@@errExit

@@error:
	MOV	[EBX].Mode,fmClosed
	CALL	GetLastError
@@errExit:
        CALL    SetInOutRes
	JMP	@@exit

@@shareTab:
	DD	FILE_SHARE_READ OR FILE_SHARE_WRITE	; OF_SHARE_COMPAT     0x00000000
	DD	0					; OF_SHARE_EXCLUSIVE  0x00000010
	DD	FILE_SHARE_READ				; OF_SHARE_DENY_WRITE 0x00000020
	DD	FILE_SHARE_WRITE			; OF_SHARE_DENY_READ  0x00000030
	DD	FILE_SHARE_READ OR FILE_SHARE_WRITE	; OF_SHARE_DENY_NONE  0x00000040
	DD	0
	DD	0
	DD	0

OpenFile ENDP


;	PROCEDURE _ResetFile( VAR f: File; recSize: Longint );

_ResetFile PROC

; ->	EAX	Pointer to file record
;	EDX	Record size

	XOR	ECX,ECX
	MOV	CL,FileMode
	AND	CL,3
	CMP	CL,2
	JBE	@@skip
	MOV	CL,2
@@skip:
	JMP	OpenFile

_ResetFile ENDP


;	PROCEDURE _RewritFile( VAR f: File; recSize: Longint );

_RewritFile PROC

; ->	EAX	Pointer to file record
;	EDX	Record size

	MOV	ECX,3
	JMP	OpenFile

_RewritFile ENDP


CloseFile PROC

; ->	EAX	Pointer to file record

	PUSH	[EAX].Handle
	MOV	[EAX].Mode,fmClosed
	Call	CloseHandle
	DEC	EAX
	JNZ	InOutError
	RET

CloseFile ENDP
	END
