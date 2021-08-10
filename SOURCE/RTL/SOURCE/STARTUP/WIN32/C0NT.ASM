; C0NT.ASM - C run time library entry point for Win32

;
;       C/C++ Run Time Library - Version 2.0
; 
;       Copyright (c) 1991, 1996 by Borland International
;       All Rights Reserved.
; 

                .386P
ifndef MASM
                model flat
endif
                ASSUME   CS: FLAT, DS: FLAT, SS: FLAT, ES: FLAT

BSSINIT         equ     1       ; Fix for problem with OS not initializing
                                ;  the first page of BSS to zero
FULLBSS         equ     1       ; Fix for problem with OS not initializing
                                ;  the entire BSS to zero

;----------------------------------------------------------------------
; Code segment

_TEXT           SEGMENT PUBLIC DWORD USE32 PUBLIC 'CODE'
_TEXT           ENDS

;----------------------------------------------------------------------
; Data segments

_DATA           SEGMENT PUBLIC DWORD USE32 PUBLIC 'DATA'
                db      'Borland C++ - Copyright 1995 Borland Intl.',0
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
IFDEF   BSSINIT
bdata@          label   byte
ENDIF
_BSS            ENDS

IFDEF   BSSINIT
_BSSEND         SEGMENT PUBLIC DWORD USE32 PUBLIC 'BSS'
edata@          label   byte
_BSSEND         ENDS
ENDIF

IFDEF   BSSINIT
DGROUP          GROUP _DATA, _TLSCBA, _INIT_, _INITEND_, _EXIT_, _EXITEND_, CONST, _BSS, _BSSEND
ELSE
DGROUP          GROUP _DATA, _TLSCBA, _INIT_, _INITEND_, _EXIT_, _EXITEND_, CONST, _BSS
ENDIF

;----------------------------------------------------------------------
; External function definitions

_TEXT           SEGMENT PUBLIC DWORD USE32 PUBLIC 'CODE'

ifdef DLL       ; DLL startup

EXTRN           __startupd:NEAR
EXTRN           __ErrorMessage:NEAR
EXTRN		__free_heaps:NEAR
EXTRN           DllEntryPoint:NEAR
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

ifndef	NOXX
EXTRN           __ExceptInit:NEAR
EXTRN           __GetExceptDLLinfoInternal:NEAR
EXTRN           __DestructorCountPtr:DWORD
endif

EXTRN           GetModuleHandleA:NEAR

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

public          __TLS_index
__TLS_index     dd      0
public          __TLS_index4
__TLS_index4    dd      0

public          __hInstance
__hInstance     dd      0  ; Global _hInstance

saveStackTop    dd      0,0
saveStackBase   dd      0

ifdef DLL
usecount        db      0
nonsharedMsg    db      'Nonshared DATA segment required',0
win32sMsg       db      'Cannot run multiple instances of a DLL under WIN32s',0
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
ifdef DLL
;;  If we are attaching to a process, make sure that we have a per-instance data segment.
;;  If we do not, then determine whether it's due to NONSHARED or Win32s limitation.
                cmp     dword ptr [esp+8], 1
                jne     not_process_attach
                cmp     usecount, 0
                je      firstInit
                call    GetVersion
                mov     edx, offset nonsharedMsg
                and     eax, 080000000h
                jz      msgSet
                mov     edx, offset win32sMsg
msgSet:
                push    edx
                call    __ErrorMessage
                pop     eax
                xor     eax, eax
                jmp     return
firstInit:
                inc     usecount
endif ;DLL

;----------------------------------------------------------------------
ifdef   BSSINIT
ifdef   DLL
                cmp     dword ptr [esp+8], 1    ; Check whether Process Attach
                jne     skipBSSInit
endif
                push    edi
                push    ecx

                xor     eax, eax
                mov     edi, offset DGROUP: bdata@
                mov     ecx, offset DGROUP: edata@
                cmp     ecx, edi
                jna     BSSInitDone
ifdef   FULLBSS
                sub     ecx, edi
else
                mov     ecx, edi
                and     ecx, 0fffh
                jecxz   BSSInitDone
                sub     ecx, 1000h
                neg     ecx
endif   ;FULLBSS
                cld
                rep     stosb
BSSInitDone:
                pop     ecx
                pop     edi
skipBSSInit:
endif   ;BSSINIT
;----------------------------------------------------------------------

ifndef	NOXX
;;  Save off stack top and stack base so we can restore them later and
;;  to check and make sure we are on the correct stack during shutdown
                mov     edx, fs:[4]
                mov     [saveStackBase], edx
                mov     eax, [edx-8]
                mov     [saveStackTop  ], eax
                mov     eax, [edx-4]
                mov     [saveStackTop+4], eax
                sub     edx, 4
                mov     [__DestructorCountPtr], edx

ifndef DLL
;;  Make sure there is room at the base of the stack
                sub     edx, 4
                cmp     edx, esp
                jae     stacktop_OK
                mov     esp, edx
stacktop_OK:

endif

;;
;;  When an EXE is loaded, all of the statically linked DLL's are
;;  initialized before the EXE starts running. That means that we
;;  have to make sure to initialize the exception-handling values
;;  before we let the DLL initialize itself, since all DLL's use
;;  the EXE's exception-handling variables; for this purpose, we
;;  call the function _ExceptInit() with a 0 argument whenever a
;;  DLL is told that it is being attached to a process. Inside
;;  this routine we will call into the EXE to get the addresses
;;  of the exception-handling variables. We also call the same
;;  function when the EXE itself is initialized.

                push    0
                call    __ExceptInit
                pop     ecx
endif	;NOXX

not_process_attach:

ifdef DLL
                cmp     dword ptr [esp+8], 0
                jne     not_process_detach

ifndef	NOXX
;;  PROCESS_DETACH
                mov     edx, fs:[4]
                cmp     edx, [saveStackBase]
                je      not_process_detach      ; stack is fine proceed as usual

;;  Ouch!  We aren't on the same stack as startup
                mov     edx, fs:[4]
                mov     eax, [edx-8]
                mov     [saveStackTop  ], eax
                mov     eax, [edx-4]
                mov     [saveStackTop+4], eax
                sub     edx, 4
                mov     [__DestructorCountPtr], edx

                push    0
                call    __ExceptInit            ; reinitialize exception pointers
                pop     ecx

endif	;NOXX

not_process_detach:
endif

                push    offset FLAT:module_data
ifdef DLL
                mov     eax, [esp+8]            ; get mod_handle to
                mov     __hInstance, eax        ; initialize _hInstance
                call    __startupd
                add     esp, 4                  ; discard module_data parameter

ifndef	NOXX
                ; check whether Process Attach or Detach (1 or 0)
                test    dword ptr [esp+8], 0FFFFFFFEh
                jnz     return

                mov     edx, fs:[4]             ; restore TOS
                mov     ecx, [saveStackTop  ]
                mov     [edx-8], ecx
                mov     ecx, [saveStackTop+4]
                mov     [edx-4], ecx
endif	;NOXX

return:
                ; check whether Process Detach (0)
		or    	dword ptr [esp+8], 0
		jnz     returnNT
		call	__free_heaps

returnNT:
                ret     12                      ; return to NT
else
                push    0                       ; NULL returns current module
                call    GetModuleHandleA
                mov     __hInstance, eax

                push    0                       ; dummy return address
                jmp     __startup
endif

__acrtused      ENDP

ifndef	NOXX
ifdef   DLL
public          __GetExceptDLLinfo
else
publicdll       __GetExceptDLLinfo
endif

__GetExceptDLLinfo      proc    near
                jmp     __GetExceptDLLinfoInternal
__GetExceptDLLinfo      ENDP
endif	;NOXX

_TEXT           ENDS

                END     __acrtused
