
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

	EXTRN	Output:DWORD, _RewritText:NEAR, _Flush:NEAR, SetInOutRes:NEAR
        EXTRN   @GetTLS:NEAR, InOutRes:DWORD
	PUBLIC	_WriteString, _Write0String, _WriteBytes, _WriteSpaces
	PUBLIC	_WriteCString, _Write0CString, _WriteChar, _Write0Char, _WriteLn

	.CODE

;	PROCEDURE _WriteBytes( VAR t: Text; VAR b; cnt : Longint );

_WriteBytes PROC

; ->	EAX	Pointer to file record
;	EDX	Pointer to buffer
;	ECX	Number of bytes to write
; <-	EAX	Pointer to file record

	PUSH	ESI
	PUSH	EDI

	MOV	ESI,EDX

	CMP	[EAX].Mode,fmOutput
	JNE	@@fileNotOutput

@@loop:
	MOV	EDI,[EAX].BufPtr
	ADD	EDI,[EAX].BufPos

;	remainingBytes = t.bufSize - t.bufPos

	MOV	EDX,[EAX].BufSize
	SUB	EDX,[EAX].BufPos

;	if (remainingBytes <= cnt)

	CMP	EDX,ECX
	JG	@@1

;	t.BufPos += remainingBytes, cnt -= remainingBytes

	ADD	[EAX].BufPos,EDX
	SUB	ECX,EDX

;	copy remainingBytes, advancing ESI

	PUSH	EAX
	PUSH	ECX
	MOV	ECX,EDX
	REP	MOVSB

	CALL	[EAX].InOutFunc
	TEST	EAX,EAX
	JNZ	@@error

	POP	ECX
	POP	EAX
	JMP	@@loop

@@1:
	ADD	[EAX].BufPos,ECX
	REP	MOVSB
@@exit:
	POP	EDI
	POP	ESI
	RET

@@fileNotOutput:
	CMP	EAX,offset Output
	JNE	@@fileNotOutputError
	PUSH	ECX
	PUSH	EDX
	PUSH	EAX
	CALL	_RewritText
	POP	EAX
	POP	EDX
	POP	ECX
	CMP	[EAX].Mode,fmOutput
	JE	@@loop

@@fileNotOutputError:
	MOV	EAX,105
        CALL    SetInOutRes
	JMP	@@exit

@@error:
        CALL    SetInOutRes
	POP	ECX
	POP	EAX
	JMP	@@exit

_WriteBytes ENDP


	.DATA
spCnt	EQU	64
spBuf	DB	spCnt DUP (' ')
	.CODE

;	PROCEDURE _WriteSpaces( VAR t: Text; cnt: Longint );

_WriteSpaces PROC

; ->	EAX	Pointer to text record
;	EDX	Number of spaces (<= 0: None)

	MOV	ECX,EDX
@loop:
	MOV	EDX,offset spBuf

	CMP	ECX,spCnt
	JLE	@@1

	SUB	ECX,spCnt
	PUSH	EAX
	PUSH	ECX
	MOV	ECX,spCnt
	CALL	_WriteBytes
        CALL    @GetTLS
	CMP	[EAX].InOutRes,0
	JNE	@@error
	POP	ECX
	POP	EAX
	JMP	@loop

@@1:
	TEST	ECX,ECX
	JG	_WriteBytes

	RET

@@error:
	POP	ECX
	POP	EAX
	RET

_WriteSpaces ENDP


;	PROCEDURE _Write0String( VAR t: Text; s: String );

_Write0String PROC

; ->	EAX	Pointer to text record
;	EDX	Pointer to string

	XOR	ECX,ECX
	MOV	CL,[EDX]
	INC	EDX
	JMP	_WriteBytes

_Write0String ENDP


;	PROCEDURE _WriteString( VAR t: Text; s: String; width: Longint );

_WriteString PROC

; ->	EAX	Pointer to text record
;	EDX	Pointer to string
;	ECX	Field width

	PUSH	EBX

	XOR	EBX,EBX
	MOV	BL,[EDX]
	SUB	ECX,EBX
	JLE	@@1

	PUSH	EAX
	PUSH	EDX

	MOV	EDX,ECX
	CALL	_WriteSpaces

	POP	EDX
	POP	EAX
@@1:
	MOV	ECX,EBX
	POP	EBX
	INC	EDX
	JMP	_WriteBytes

_WriteString ENDP

	.DATA
crlf	DB	0DH,0AH
	.CODE

;	PROCEDURE _WriteLn( VAR t: Text );

_WriteLn PROC

; ->	EAX	Pointer to text record

	MOV	EDX,offset crlf
	MOV	ECX,2
	CALL	_WriteBytes
	JMP	_Flush

_WriteLn ENDP

;	PROCEDURE _Write0Char( VAR t: Text; c: Char );

_Write0Char PROC

; ->	EAX	Pointer to text record
;	DL	Character

	CMP	[EAX].Mode,fmOutput
	JNE	@@fileNotOutput
@@loop:
	MOV	ECX,[EAX].BufPos
	CMP	ECX,[EAX].BufSize
	JGE	@@flush

	ADD	ECX,[EAX].BufPtr
	MOV	[ECX],DL

	INC	[EAX].BufPos

	RET

@@flush:
	PUSH	EAX
	PUSH	EDX
	CALL	[EAX].InOutFunc
	TEST	EAX,EAX
	JNZ	@@error
	POP	EDX
	POP	EAX
	JMP	@@loop

@@fileNotOutput:
	CMP	EAX,offset Output
	JNE	@@fileNotOutputError
	PUSH	EDX
	PUSH	EAX
	CALL	_RewritText
	POP	EAX
	POP	EDX
	CMP	[EAX].Mode,fmOutput
	JE	@@loop

@@fileNotOutputError:
	MOV	EAX,105
        JMP    SetInOutRes

@@error:
        CALL    SetInOutRes
	POP	EDX
	POP	EAX
	RET

_Write0Char ENDP


;	PROCEDURE _WriteChar( VAR t: Text; c: Char; width: Integer );

_WriteChar PROC

; ->	EAX	Pointer to text record
;	DL	Character
;	ECX	Field width

	PUSH	EDX

	LEA	EDX,[ECX-1]
	CALL	_WriteSpaces

	MOV	EDX,ESP
	MOV	ECX,1
	CALL	_WriteBytes

	POP	EDX

	RET

_WriteChar ENDP


;	PROCEDURE _Write0CString( VAR t: Text; s: PChar );

_Write0CString PROC

; ->	EAX	Pointer to text record
;	EDX	Pointer to string

	XOR	ECX,ECX
	JMP	_WriteCString

_Write0CString ENDP

;	PROCEDURE _WriteCString( VAR t: Text; s: PChar; width: Longint );

_WriteCString PROC

; ->	EAX	Pointer to text record
;	EDX	Pointer to string
;	ECX	Field width

	PUSH	ESI
	PUSH	EDI

	MOV	ESI,EAX
	PUSH	ECX

	MOV	EDI,EDX
	OR	ECX,-1
	MOV	AL,0
	REPNE	SCASB
	NOT	ECX
	DEC	ECX

	MOV	EDI,EDX

	POP	EDX


	SUB	EDX,ECX
	MOV	EAX,ESI
	PUSH	ECX
	CALL	_WriteSpaces
	POP	ECX

	MOV	EAX,ESI
	MOV	EDX,EDI

	POP	EDI
	POP	ESI
	JMP	_WriteBytes

_WriteCString ENDP

	END

