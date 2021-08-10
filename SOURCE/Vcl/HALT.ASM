
; *******************************************************
; *                                                     *
; *     Delphi Runtime Library                          *
; *                                                     *
; *	Copyright (c) 1996,98 Inprise Corporation	*
; *                                                     *
; *******************************************************

        INCLUDE SE.ASM
        INCLUDE FILEIO.ASM

        .386
        .MODEL  FLAT

        EXTRN   ExitProcess:NEAR, ExitProc:DWORD, ErrorAddr:DWORD, _Close:NEAR
        EXTRN   _Write0CString:NEAR, _WriteLn:NEAR, MessageBoxA:NEAR
        EXTRN   UninitAllocator:NEAR, UnsetExceptionHandler:NEAR
        EXTRN   DLLSaveEBX:DWORD, DLLSaveEBP:DWORD, DLLSaveESI:DWORD
        EXTRN   DLLSaveEDI:DWORD, DLLInitState:BYTE, IsLibrary:BYTE, IsConsole:BYTE
        EXTRN   ExitCode:DWORD
        EXTRN   Input, Output, TextStart

        PUBLIC  _Halt, _Halt0, _RunError, _Run0Error

        .DATA

runErrMsg       DB      'Runtime error     at 00000000',0
;       columns:         0123456789012345678901234567890
errCaption      DB      'Error',0

        .CODE

;       PROCEDURE Terminate( exitCode: Longint );

Terminate PROC

; ->    EAX     Exitcode

        MOV     ExitCode,EAX
        CMP     IsLibrary,0
        JE      @@DoExitProcs
        CMP     DLLInitState,1
        JB      @@ProgExit
        JE      @@DoExitProcs
        OR      EAX,EAX
        JE      @@LibExit

@@DoExitProcs:
        MOV     EAX,ExitProc            ;Run exit procedures
        OR      EAX,EAX
        JE      @@CheckError
        XOR     EDX,EDX
        MOV     ExitProc,EDX
        CALL    EAX
        JMP     @@DoExitProcs

@@CheckError:
        CMP     ErrorAddr,0
        JE      @@CloseInOut

        MOV     EAX,ExitCode
        MOV     EBX,offset runErrMsg + 16
        MOV     ECX,10

@@digLoop:
        XOR     EDX,EDX
        DIV     ECX
        ADD     DL,'0'
        MOV     [EBX],DL
        DEC     EBX
        TEST    EAX,EAX
        JNZ     @@digLoop

        MOV     EBX,offset runErrMsg + 28
        MOV     EAX,ErrorAddr
        SUB     EAX,offset TextStart

@@hdigLoop:
        MOV     EDX,EAX
        AND     EDX,0FH
        MOV     DL,dig[EDX]
        MOV     [EBX],DL
        DEC     EBX
        SHR     EAX,4
        JNE     @@hdigLoop

        CMP     IsConsole,0
        JNE     @@IsConsole

        PUSH    0
        PUSH    offset errCaption
        PUSH    offset runErrMsg
        PUSH    0
        CALL    MessageBoxA
        JMP     SHORT @@CloseInOut

@@IsConsole:
        MOV     EAX,OFFSET Output
        MOV     EDX,OFFSET runErrMsg
        CALL    _Write0CString
        CALL    _WriteLn

@@CloseInOut:
        MOV     EAX,OFFSET Input
        CALL    _Close
        MOV     EAX,OFFSET Output
        CALL    _Close
        CALL    UninitAllocator
        CMP     DLLInitState,0
        JNE     @@LibExit
        CALL    UnsetExceptionHandler

@@ProgExit:
        PUSH    ExitCode
        CALL    ExitProcess

@@LibExit:
        CALL    UnsetExceptionHandler
        MOV     DLLInitState,0
        MOV     EAX,ExitCode    ; Return True if ExitCode = 0
        NEG     EAX
        SBB     EAX,EAX
        INC     EAX
        MOV     EDI,DLLSaveEDI
        MOV     ESI,DLLSaveESI
        MOV     EBX,DLLSaveEBX
        MOV     EBP,DLLSaveEBP
        LEAVE
        RET     12

dig     DB      '0123456789ABCDEF'

Terminate ENDP


;       PROCEDURE _Halt0;

_Halt0  PROC

        XOR     EAX,EAX
        JMP     _Halt

_Halt0  ENDP


;       PROCEDURE _Halt( exitCode: Longint );

_Halt   PROC

        XOR     EDX,EDX
        MOV     ErrorAddr,EDX
        JMP     Terminate

_Halt   ENDP


;       PROCEDURE _Run0Error;

_Run0Error PROC

        XOR     EAX,EAX
        JMP     _RunError

_Run0Error ENDP


;       PROCEDURE _RunError( ErrorCode: Longint );

_RunError PROC

; ->    EAX     ErrorCode

        POP     ErrorAddr
        JMP     Terminate

_RunError ENDP

        END
