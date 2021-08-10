
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

	EXTRN	WriteFile:NEAR, GetLastError:NEAR, SetInOutRes:NEAR

	PUBLIC	_WriteRec

	.CODE

;	PROCEDURE _WriteRec( f: File; buffer: Pointer );

_WriteRec PROC

; ->	EAX	Pointer to file variable
;	EDX	Pointer to buffer
; <-	EAX	Pointer to file variable
	PUSH	EBX

	MOV	EBX,EAX

	MOV	EAX,[EAX].Mode
	SUB	EAX,fmOutput
	CMP	EAX,fmInOut-fmOutput	; File must be fmInOut or fmOutput
	JA	@@fileNotOpen

;	WriteFile(f.Handle, buffer, f.RecSize, @result, Nil);

	PUSH	0			; space for OS result
	MOV	EAX,ESP

	PUSH	0			; pass lpOverlapped
	PUSH	EAX			; pass @result

	PUSH	[EBX].RecSize		; pass nNumberOfBytesToRead

	PUSH	EDX			; pass lpBuffer
	PUSH	[EBX].Handle		; pass hFile
	CALL	WriteFile
	POP	EDX			; pop result
	DEC	EAX			; check EAX = TRUE
	JNZ	@@error

	CMP	EDX,[EBX].RecSize	; result = f.RecSize ?
	JNE	@@writeError
@@exit:
	MOV	EAX,EBX
	POP	EBX

	RET

@@error:
	CALL	GetLastError
@@errExit:
        CALL    SetInOutRes
	JMP	@@exit

@@fileNotOpen:
	MOV	EAX,5
	JMP	@@errExit

@@writeError:
	MOV	EAX,101
	JMP	@@errExit

_WriteRec ENDP

	END
