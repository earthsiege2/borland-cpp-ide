; C0NT.ASM - C run time library entry point for NT

; $Copyright: 1991$

                .386P
ifndef MASM
                model flat
endif
                ASSUME   CS: FLAT, DS: FLAT, SS: FLAT, ES: FLAT

;----------------------------------------------------------------------
; Code segment

_TEXT           SEGMENT PUBLIC DWORD USE32 PUBLIC 'CODE'
_TEXT           ENDS

;----------------------------------------------------------------------
; Data segments

_DATA           SEGMENT PUBLIC DWORD USE32 PUBLIC 'DATA'
                db      'Borland C++ - Copyright 1992 Borland Intl.',0
_DATA           ENDS

_TLSCBA         SEGMENT PUBLIC DWORD USE32 PUBLIC 'TLSCBA'
_TLSCBA         ENDS

_INIT_          SEGMENT PUBLIC WORD USE32 PUBLIC 'INITDATA'
InitStart       label byte
_INIT_          ENDS

_INITEND_       SEGMENT PUBLIC WORD USE32 PUBLIC 'INITDATA'
InitEnd         label byte
_INITEND_       ENDS

_EXIT_          SEGMENT PUBLIC WORD USE32 PUBLIC 'EXITDATA'
ExitStart       label byte
_EXIT_          ENDS

_EXITEND_       SEGMENT PUBLIC WORD USE32 PUBLIC 'EXITDATA'
ExitEnd         label byte
_EXITEND_       ENDS

ifndef MASM
                NOWARN  RES
endif
CONST           SEGMENT PUBLIC DWORD USE32 PUBLIC 'CONST'
CONST           ENDS
ifndef MASM
                WARN    RES
endif

_BSS            SEGMENT PUBLIC DWORD USE32 PUBLIC 'BSS'
_BSS            ENDS

DGROUP          GROUP _DATA, _TLSCBA, _INIT_, _INITEND_, _EXIT_, _EXITEND_, CONST, _BSS

;----------------------------------------------------------------------
; External function definitions

_TEXT           SEGMENT PUBLIC DWORD USE32 PUBLIC 'CODE'

ifdef DLL       ; DLL startup

EXTRN           DllEntryPoint:NEAR
EXTRN           __startupd:NEAR
EXTRN           __ErrorMessage:NEAR
EXTRN           GetVersion:NEAR

else            ; EXE startup

ifdef WINDOWS
EXTRN           WinMain:NEAR
else
EXTRN           _main:NEAR
endif
endif

EXTRN           __startup:NEAR
EXTRN           __matherr:NEAR
EXTRN           __matherrl:NEAR

EXTRN           __ExceptInit:NEAR
EXTRN           __GetExceptDLLinfoInternal:NEAR
EXTRN           __DestructorCountPtr:DWORD

_TEXT           ENDS

;----------------------------------------------------------------------
; External data definitions

_DATA           SEGMENT PUBLIC DWORD USE32 'DATA'

ifndef DLL       ; EXE startup
EXTRN           __fmode:NEAR
endif

_DATA           ENDS

;----------------------------------------------------------------------
; CV4 debugging information: a pointer to main, WinMain, or DllEntryPoint

ifndef MASM ; MASM386 can't handle 'dp' directive

$$BSYMS         SEGMENT PUBLIC BYTE USE32 'DEBSYM'
                dd  2       ; magic
                dw  8       ; magic
                dw  210h    ; magic (S_ENTRY32)
ifdef DLL
                dp  DllEntryPoint
else
ifdef WINDOWS
                dp  WinMain
else
                dp  _main
endif
endif
$$BSYMS         ENDS

endif   ; ndef MASM

;----------------------------------------------------------------------
; MODULE_DATA table.
;
; This table contains information about this EXE or DLL that is used
; by startup.c to properly initialize or clean up the module.
; IMPORTANT: the layout must exactly match the MODULE_DATA structure
; definition in startup.c!


_DATA           SEGMENT PUBLIC DWORD USE32 'DATA'

                align   4
module_data     dd      offset FLAT:InitStart
                dd      offset FLAT:InitEnd
                dd      offset FLAT:ExitStart
                dd      offset FLAT:ExitEnd
ifdef WINDOWS
                dd      1                       ; flags
else
                dd      0                       ; flags
endif
                dd      0                       ; module handle
ifdef DLL
                dd      offset FLAT:DllEntryPoint
                dd      0                       ; matherr
                dd      0                       ; matherrl
                dd      0                       ; stack base
                dd      0                       ; fmode
else
ifdef WINDOWS
                dd      offset FLAT:WinMain
else
                dd      offset FLAT:_main
endif
                dd      offset FLAT:__matherr
                dd      offset FLAT:__matherrl
                dd      0                       ; stack base
                dd      offset FLAT:__fmode
endif

public          ___isDLL
ifdef DLL
___isDLL        db      1
else
___isDLL        db      0
endif

public          __TLS_index
__TLS_index     dd      0
public          __TLS_index4
__TLS_index4    dd      0

save_stacktop   dd      0,0


public          ___isGUI
ifdef DLL
___isGUI        db      1
else
ifdef WINDOWS
___isGUI        db      1
else
___isGUI        db      0
endif
endif

ifdef DLL
usecount	db	0
nonsharedMsg	db	'Nonshared DATA segment required',0
win32sMsg	db	'Cannot run multiple instances of a DLL under WIN32s',0
endif
_data           ENDS

;----------------------------------------------------------------------
; Startup code

_TEXT           SEGMENT  DWORD USE32 PUBLIC 'CODE'

                public __acrtused
__acrtused      PROC NEAR

                mov     eax, __TLS_index
                shl     eax, 2
                mov     __TLS_index4, eax
;
;       When an EXE is loaded, all of the statically linked DLL's are
;       initialized before the EXE starts running. That means that we
;       have to make sure to initialize the exception-handling values
;       before we let the DLL initialize itself, since all DLL's use
;       the EXE's exception-handling variables; for this purpose, we
;       call the function _ExceptInit() with a 0 argument whenever a
;       DLL is told that it is being attached to a process. Inside
;       this routine we will call into the EXE to get the addresses
;       of the exception-handling variables. We also call the same
;       function when the EXE itself is initialized.

ifdef DLL
                cmp     dword ptr [esp+8], 1
                jne     not_process_attach
		cmp	usecount, 0
		je	firstInit
		mov	edx, offset nonsharedMsg
		call	GetVersion
		and	eax, 080000000h
		jz	msgSet
		mov	edx, offset win32sMsg
msgSet:
		push	edx
		call	__ErrorMessage
		pop	eax
		xor	eax, eax
		jmp	return
firstInit:
		inc	usecount
endif
                mov     edx, fs:[4]
                mov     eax, [edx-8]
                mov     [save_stacktop  ], eax
                mov     eax, [edx-4]
                mov     [save_stacktop+4], eax
                sub     edx, 4
                mov     [__DestructorCountPtr], edx

ifndef DLL
                sub     edx, 4
                cmp     edx, esp
                jae     stacktop_OK
                mov     esp, edx
stacktop_OK:

endif

                push    0
                call    __ExceptInit
                pop     ecx

not_process_attach:

                push    offset FLAT:module_data
ifdef DLL
                call    __startupd
                add     esp, 4      ; discard module_data parameter

                mov     edx, fs:[4]
                mov     ecx, [save_stacktop  ]
                mov     [edx-8], ecx
                mov     ecx, [save_stacktop+4]
                mov     [edx-4], ecx

return:
                ret     12          ; return to NT
else
                xor     eax,eax
                push    eax         ; dummy return address
                jmp     __startup
endif

__acrtused      ENDP

ifdef   DLL
public          __GetExceptDLLinfo
else
publicdll       __GetExceptDLLinfo
endif

__GetExceptDLLinfo      proc    near
                jmp     __GetExceptDLLinfoInternal
__GetExceptDLLinfo      ENDP

_TEXT           ENDS

                END     __acrtused
