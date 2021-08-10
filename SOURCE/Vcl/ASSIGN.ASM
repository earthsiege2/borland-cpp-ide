
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

	EXTRN	CreateFileA:NEAR, ReadFile:NEAR, WriteFile:NEAR
	EXTRN	CloseHandle:NEAR, GetStdHandle:NEAR, GetLastError:NEAR
	EXTRN	SetFilePointer:NEAR, GetFileSize:NEAR, SetEndOfFile:NEAR
	EXTRN	GetFileType:NEAR, SetInOutRes:NEAR
	PUBLIC	_Assign, __Flush, _Flush

	.CODE

;	FUNCTION TextIn( VAR t: Text ) : Integer;

TextIn	PROC

; ->	EAX	Pointer to text record

;	Make buffer empty

	XOR	EDX,EDX
	MOV	[EAX].BufEnd,EDX
	MOV	[EAX].BufPos,EDX

;	ReadFile(t.Handle, t.BufPtr, t.BufSize, @t.BufEnd, Nil);

	PUSH	EDX			; pass lpOverLapped
	LEA	EDX,[EAX].BufEnd	; pass lpNumberOfBytesRead
	PUSH	EDX
	PUSH	[EAX].BufSize		; pass nNumberOfBytestoRead
	PUSH	[EAX].BufPtr		; pass lpBuffer
	PUSH	[EAX].Handle		; pass hFile
	CALL	ReadFile
	TEST    EAX,EAX			; result FALSE means error
	JZ	@@error
@@noerror:
	XOR	EAX,EAX

	RET

@@error:				; return extended error code
	CALL	GetLastError
        CMP     EAX,109                 ; NT quirk: got "broken pipe"? it's really eof
        JE      @@noerror
	RET

TextIn	ENDP


;	PROCEDURE TextNullProc( VAR t: Text );

TextNullProc PROC

; ->	EAX	Pointer to text record

	XOR	EAX,EAX			; signal success

	RET

TextNullProc ENDP


;	PROCEDURE TextOut( VAR t: Text );

TextOut	PROC

; ->	EAX	Pointer to text record

;       WriteFile(t.Handle, t.BufPtr, t.BufPos, @dummy, Nil);

	PUSH	ECX			; VAR dummy: Longint;

	MOV	EDX,[EAX].BufPos
	TEST	EDX,EDX
	JLE	@@skip

	XOR	ECX,ECX
	MOV	[EAX].BufPos,ECX

	PUSH	ECX			; pass lpOverLapped
	LEA     ECX,[ESP+4]		; pass lpNumberOfBytes written
	PUSH	ECX
	PUSH	EDX			; pass nNumberOfBytesToWrite
	PUSH	[EAX].BufPtr		; pass lpBuffer
	PUSH	[EAX].Handle		; pass hFile
	CALL	WriteFile
	TEST	EAX,EAX
	JZ	@@error

@@skip:
	XOR	EAX,EAX

@@exit:
	POP	ECX			; deallocate dummy
	RET

@@error:				; return dos error code or 0
	Call	GetLastError
	JMP	@@exit

TextOut	ENDP


;	PROCEDURE TextClose( VAR t: Text );

TextClose PROC

; ->	EAX	Pointer to text record

;	CloseHandle( t.Handle );

	PUSH	[EAX].Handle
	MOV	[EAX].Mode,fmClosed
	CALL	CloseHandle
	DEC	EAX
	JNZ	@@error
	RET
@@error:
	CALL	GetLastError
	RET

TextClose ENDP


;	PROCEDURE TextOpen( VAR t: Text );

TextOpen PROC

; ->	EAX	Pointer to text record

;
	PUSH	ESI

	MOV	ESI,EAX

	XOR	EAX,EAX
	MOV	[ESI].BufPos,EAX
	MOV	[ESI].BufEnd,EAX
	MOV	EAX,[ESI].Mode

	SUB	EAX,fmInput
	JE	@@calledByReset

	DEC	EAX
	JE	@@calledByRewrite

	DEC	EAX
	JE	@@calledByAppend

	JMP	@@exit

@@calledByReset:

	MOV	EAX,GENERIC_READ			; open for read
	MOV	EDX,FILE_SHARE_READ
	MOV	ECX,OPEN_EXISTING

	MOV	[ESI].InOutFunc,offset TextIn

	JMP	@@common

@@calledByRewrite:

	MOV	EAX,GENERIC_WRITE			; open for write
	MOV	EDX,FILE_SHARE_READ
	MOV	ECX,CREATE_ALWAYS
	JMP	@@commonOut

@@calledByAppend:

	MOV	EAX,GENERIC_READ OR GENERIC_WRITE	; open for read/write
	MOV	EDX,FILE_SHARE_READ
	MOV	ECX,OPEN_EXISTING

@@commonOut:

	MOV	[ESI].InOutFunc,offset TextOut

@@common:

	MOV	[ESI].CloseFunc,offset TextClose
	MOV	[ESI].FlushFunc,offset TextNullProc
	CMP	byte ptr [ESI].FileName,0
	JE	@@isCon

;	CreateFile(t.FileName, EAX, EDX, Nil, ECX, FILE_ATTRIBUTE_NORMAL, 0);

	PUSH	0
	PUSH	FILE_ATTRIBUTE_NORMAL
	PUSH	ECX
	PUSH	0
	PUSH	EDX
	PUSH	EAX
	LEA	EAX,[ESI].FileName
	PUSH	EAX
	CALL	CreateFileA

	CMP	EAX,-1
	JZ	@@error

	MOV	[ESI].Handle,EAX
	CMP	[ESI].Mode,fmInOut
	JNE	@@success

	DEC	[ESI].Mode			; fmInOut -> fmOutput

;	???  we really have to look for the first eof byte in the
;	???  last record and truncate the file there.
;	Not very nice and clean...
;
;	lastRecPos = Max( GetFileSize(...) - 128, 0);

	PUSH	0
	PUSH	[ESI].Handle
	CALL	GetFileSize

	INC	EAX
	JZ	@@error
	SUB	EAX,129
	JNC	@@3
	XOR	EAX,EAX
@@3:
;	lseek(f.Handle, SEEK_SET, lastRecPos);

	PUSH	FILE_BEGIN
	PUSH	0
	PUSH	EAX
	PUSH	[ESI].Handle
	CALL	SetFilePointer

	INC	EAX
	JE	@@error

;	bytesRead = read(f.Handle, f.Buffer, 128);

	PUSH	0
	MOV	EDX,ESP
	PUSH	0
	PUSH	EDX
	PUSH	128
	LEA	EDX,[ESI].Buffer
	PUSH	EDX
	PUSH	[ESI].Handle
	CALL	ReadFile
	POP	EDX
	DEC	EAX
	JNZ	@@error

;	for	(i = 0; i < bytesRead; i++)

	XOR	EAX,EAX
@@loop:
	CMP	EAX,EDX
	JAE	@@success

;		if	(f.Buffer[i] == eof)

	CMP	byte ptr [ESI].Buffer[EAX],eof
	JE	@@truncate
	INC	EAX
	JMP	@@loop

@@truncate:

;	lseek( f.Handle, SEEK_END, i - bytesRead );

	PUSH	FILE_END
	PUSH	0
	SUB	EAX,EDX
	PUSH	EAX
	PUSH	[ESI].Handle
	CALL	SetFilePointer
	INC	EAX
	JE	@@error

;	SetEndOfFile( f.Handle );

	PUSH	[ESI].Handle
	CALL	SetEndOfFile
	DEC	EAX
	JNE	@@error

	JMP	@@success

@@isCon:
	MOV	[ESI].CloseFunc,offset TextNullProc
	CMP	[ESI].Mode,fmOutput
	JE	@@output
	PUSH	STD_INPUT_HANDLE
	JMP	@@1
@@output:
	PUSH	STD_OUTPUT_HANDLE
@@1:
	CALL	GetStdHandle
	CMP	EAX,-1
	JE	@@error
	MOV	[ESI].Handle,EAX

@@success:
	CMP	[ESI].Mode,fmInput
	JE	@@2
	PUSH	[ESI].Handle
	CALL	GetFileType
        TEST    EAX,EAX
        JE      @@badFileType
	CMP	EAX,2
	JNE	@@2
	MOV	[ESI].FlushFunc,offset TextOut
@@2:
	XOR	EAX,EAX
@@exit:
	POP	ESI
	RET

@@badFileType:
        PUSH    [ESI].Handle
        CALL    CloseHandle
	MOV	[ESI].Mode,fmClosed
        MOV     EAX,105
        JMP     @@exit

@@error:
	MOV	[ESI].Mode,fmClosed
	CALL	GetLastError
	JMP	@@exit

TextOpen ENDP


;	PROCEDURE _Assign( VAR t: Text; s: PChar );

_Assign	PROC

; ->	EAX	Pointer to text record
;	EDX	Pointer to file name

;	we just initialize the various fields

	LEA	ECX,[EAX].Buffer
	MOV	[EAX].BufPtr,ECX
	XOR	ECX,ECX
	MOV	[EAX].Handle,ECX
	MOV	[EAX].Mode,fmClosed
	MOV	[EAX].BufSize,128
	MOV	[EAX].BufPos,ECX
	MOV	[EAX].BufEnd,ECX
	MOV	[EAX].OpenFunc,offset TextOpen
	MOV	[EAX].InOutFunc,ECX
	MOV	[EAX].FlushFunc,ECX
	MOV	[EAX].CloseFunc,ECX

;	and copy the file name, truncating it to fNameLen-1 chars

	LEA	EAX,[EAX].FileName

	TEST	EDX,EDX
	JE	@@term

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
	DEC	EAX
@@term:
	MOV	[EAX],CH
@@exit:
	RET

_Assign	ENDP


;	PROCEDURE Flush( VAR f: Text );

__Flush	PROC

; ->	EAX	Pointer to text record

	MOV	EDX,[EAX].Mode
	CMP	EDX,fmOutput
	JNE	@@fileNotOutput
	CALL	[EAX].InOutFunc
	TEST	EAX,EAX
	JNE	@@error
@@exit:
	RET

@@fileNotOutput:
	CMP	EDX,fmInput
	JE	@@exit
	MOV	EAX,103
@@error:
	JMP	SetInOutRes


__Flush	ENDP

;	PROCEDURE _Flush( VAR f: Text );

_Flush	PROC

; ->	EAX	Pointer to text record

	MOV	EDX,[EAX].Mode
	CMP	EDX,fmOutput
	JNE	@@fileNotOutput
	CALL	[EAX].FlushFunc
	TEST	EAX,EAX
	JNE	@@error
@@exit:
	RET

@@fileNotOutput:
	CMP	EDX,fmInput
	JE	@@exit
	MOV	EAX,103
@@error:
	JMP	SetInOutRes

_Flush	ENDP

	END

