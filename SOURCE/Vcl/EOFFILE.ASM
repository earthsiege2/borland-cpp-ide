
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

	EXTRN	GetFileSize:NEAR, SetFilePointer:NEAR, GetLastError:NEAR
        EXTRN   SetInOutRes:NEAR, InOutError:NEAR

	PUBLIC	_EofFile

	.CODE

;	FUNCTION _EofFile( f: File ): Boolean;

_EofFile PROC

; ->	EAX	Pointer to file variable
; <-	AL	Boolean result

	PUSH	EBX

	MOV	EBX,EAX

	MOV	EDX,[EBX].Mode		; File must be open
	SUB	EDX,fmInput
	CMP	EDX,fmInOut-fmInput
	JA	@@fileNotOpen

	PUSH	0			; get file size from OS
	PUSH	[EBX].Handle
	CALL	GetFileSize
	CMP	EAX,-1
	JZ	@@error

	PUSH	EAX

	PUSH	FILE_CURRENT		; get file pointer from OS
	PUSH	0
	PUSH	0
	PUSH	[EBX].Handle
	CALL	SetFilePointer
	CMP	EAX,-1
	JZ	@@error

	POP	EDX
	CMP	EAX,EDX			; eof := pos >= size
	SETAE	AL

@@exit:
	POP	EBX

	RET

@@error:
	CALL	InOutError
	MOV	AL,1
	JMP	@@exit

@@fileNotOpen:
	MOV	EAX,103
        CALL    SetInOutRes
	MOV	AL,-1
	JMP	@@exit

_EofFile ENDP

	END
