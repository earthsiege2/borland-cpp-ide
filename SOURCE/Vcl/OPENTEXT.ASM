
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

	EXTRN	_Close:NEAR, SetInOutRes:NEAR

	PUBLIC	_ResetText, _RewritText, _Append


	.CODE

;	PROCEDURE OpenText( VAR t: Text; Mode: Word);

OpenText PROC

; ->	EAX	Pointer to text record
; ->	EDX	Mode	(fmInput, fmOutput, fmInOut)

	PUSH	EBX
	PUSH	ESI
	MOV	ESI,EAX
	MOV	EBX,EDX

	MOV	EDX,[ESI].Mode
	SUB	EDX,fmClosed
	JE	@@alreadyClosed

	CMP	EDX,fmInOut-fmClosed
	JA	@@notAssignedError

	CALL	_Close

@@alreadyClosed:

	MOV	EAX,ESI
	MOV	[ESI].Mode,EBX
	CALL	[ESI].OpenFunc
	TEST	EAX,EAX
	JE	@@exit
        CALL    SetInOutRes

@@exit:

	POP	ESI
	POP	EBX
	RET

@@notAssignedError:

	MOV	EAX,102
        CALL    SetInOutRes
	JMP	@@exit

OpenText ENDP


;	PROCEDURE _ResetText( VAR t: Text );

_ResetText PROC

; ->	EAX	Pointer to text record

	MOV	EDX,fmInput
	JMP	OpenText

_ResetText ENDP


;	PROCEDURE _RewriteText( VAR t: Text );

_RewritText PROC

; ->	EAX	Pointer to text record

	MOV	EDX,fmOutput
	JMP	OpenText

_RewritText ENDP


;	PROCEDURE _Append( VAR t: Text );

_Append	PROC

; ->	EAX	Pointer to text record

	MOV	EDX,fmInOut
	JMP	OpenText

_Append	ENDP

	END
