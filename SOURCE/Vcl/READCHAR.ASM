
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

	EXTRN	Input:DWORD, _ResetText:NEAR, SetInOutRes:NEAR

	PUBLIC	_ReadChar

	.CODE

;	FUNCTION _ReadChar( t: Text ) : Char;

_ReadChar PROC

; ->	EAX	Pointer to text record
; <-	AL	Character read. For eof, #$1A is returned. For errors,
;		SetInOutRes is called and #$1A is returned.

	CMP	[EAX].Mode,fmInput
	JNE	@@fileNotOpenForInput
@@checkBuf:
	MOV	EDX,[EAX].BufPos
	CMP	EDX,[EAX].BufEnd
	JAE	@@fillBuf
@@cont:
	MOV	ECX,[EAX].BufPtr
	MOV	CL,[ECX+EDX]
	CMP	CL,eof
	JZ	@@exit
	INC	EDX
	MOV	[EAX].BufPos,EDX
@@exit:
	MOV	AL,CL
	RET

@@fileNotOpenForInput:
	CMP	EAX,offset Input
	JE	@@openInput
@@notOpenError:
	MOV	EAX,104
        CALL    SetInOutRes
	MOV	AL,eof
	RET

@@openInput:
	CALL	_ResetText
	MOV	EAX,offset Input
	CMP	[EAX].Mode,fmInput
	JE	@@checkBuf
	JMP	@@notOpenError

@@fillBuf:
	PUSH	EAX
	CALL	[EAX].InOutFunc
	TEST	EAX,EAX
	JNE	@@error
	POP	EAX
	MOV	EDX,[EAX].BufPos
	CMP	EDX,[EAX].BufEnd
	JB	@@cont

;	so we didn't get characters. must be eof then.
;	store one eof in the buffer and increment BufEnd

@@eof:
	MOV	ECX,[EAX].BufPtr
	MOV	byte ptr [ECX+EDX],eof
	INC	[EAX].BufEnd
	MOV	AL,eof
	RET

@@error:
        CALL    SetInOutRes
	POP	EAX
	MOV	AL,eof
	RET

_ReadChar ENDP


	END
