; C0NT.ASM - C/C++ run time library entry point for Win32 apps.

;
;       C/C++ Run Time Library - Version 11.0
; 
;       Copyright (c) 1991, 2002 by Borland Software Corporation
;       All Rights Reserved.
; 

; $Revision: 9.45.2.1 $

                .386P
ifndef MASM
                model flat
LOCALS
endif
                ASSUME   CS: FLAT, DS: FLAT, SS: FLAT, ES: FLAT

BSSINIT         equ     0

FULLBSS         equ     0

;----------------------------------------------------------------------
; EQU defines

HEAP_ZERO_MEMORY equ 08h        ; from winnt.h

;----------------------------------------------------------------------

;----------------------------------------------------------------------
; Code segment

_TEXT           SEGMENT PUBLIC DWORD USE32 PUBLIC 'CODE'
_TEXT           ENDS

;----------------------------------------------------------------------
; Data segments

_DATA           SEGMENT PUBLIC DWORD USE32 PUBLIC 'DATA'
                db      'Borland C++ - Copyright 2002 Borland Corporation',0
_DATA           ENDS

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

_BSS            SEGMENT PUBLIC DWORD USE32 PUBLIC 'BSS'
IF      BSSINIT
bdata@          label   byte
ENDIF
_BSS            ENDS

IF      BSSINIT
_BSSEND         SEGMENT PUBLIC DWORD USE32 PUBLIC 'BSS'
edata@          label   byte
_BSSEND         ENDS
ENDIF

_TLS            SEGMENT PUBLIC DWORD USE32 'TLS'
_TLS            ENDS
_TLSEND         SEGMENT PUBLIC DWORD USE32 'TLS'
etls@           label byte
_TLSEND         ENDS

THREADGROUP     GROUP _TLS, _TLSEND

IF      BSSINIT
;DGROUP          GROUP _DATA, _TLSCBA, _INIT_, _INITEND_, _EXIT_, _EXITEND_, _BSS, _BSSEND
DGROUP          GROUP _DATA, _INIT_, _INITEND_, _EXIT_, _EXITEND_, _BSS, _BSSEND
ELSE
;DGROUP          GROUP _DATA, _TLSCBA, _INIT_, _INITEND_, _EXIT_, _EXITEND_, _BSS
DGROUP          GROUP _DATA, _INIT_, _INITEND_, _EXIT_, _EXITEND_, _BSS
ENDIF

;----------------------------------------------------------------------
; External function definitions

_TEXT           SEGMENT PUBLIC DWORD USE32 PUBLIC 'CODE'

EXTRN           ___CRTL_VCLLIB_Linkage:NEAR; A hook to trap VCL->CW lib mismatches
EXTRN           ___CRTL_MEM_UseBorMM:NEAR  ; A hook-in spot to allow usebormm.lib
EXTRN           ___CRTL_VCL_Init:NEAR      ; Used if in the CPxxx libs, else stubbed out
EXTRN           ___CRTL_VCL_Exit:NEAR      ; Used if in the CPxxx libs, else stubbed out
EXTRN           ___CRTL_DLL_Lock:NEAR      ; Used if linking with the RTLDLL implib.
EXTRN           ___CRTL_DLL_Unlock:NEAR    ; Used if linking with the RTLDLL implib.

ifndef DLL
;EXTRN           ___CRTL_RTLDLL_Init       ; Used to init RTLDLL pointers with EXE addresses
endif ; DLL

; The following functions duplicate the system TLS functions allowing many
; TLS pseudo-slots to be assigned to a single real system TLS slot (since there
; are only 64 max system TLS slots).

ifndef SIMULATE_TLS
EXTRN           ___CRTL_TLS_Alloc:NEAR
EXTRN           ___CRTL_TLS_Free:NEAR
EXTRN           ___CRTL_TLS_GetValue:NEAR
EXTRN           ___CRTL_TLS_SetValue:NEAR

EXTRN           ___CRTL_TLS_InitThread:NEAR ; Helper for ref counting
EXTRN           ___CRTL_TLS_ExitThread:NEAR ; Helper for ref counting and mem freeing
endif ; SIMULATE_TLS

ifdef DLL       ; DLL startup

ifndef _UNICODE
EXTRN           __startupd:NEAR
else
EXTRN           __wstartupd:NEAR
endif
EXTRN           __ErrorMessage:NEAR
EXTRN           __free_heaps:NEAR
EXTRN           DllEntryPoint:NEAR
EXTRN           GetVersion:NEAR
EXTRN           __pRawDllMain:NEAR

else            ; EXE startup

ifdef WINDOWS
ifndef _UNICODE
EXTRN           WinMain:NEAR
EXTRN           __setargv__:NEAR
EXTRN           __setenvp__:NEAR
else
EXTRN           wWinMain:NEAR
EXTRN           __wsetargv__:NEAR
EXTRN           __wsetenvp__:NEAR
endif
else
ifndef _UNICODE
EXTRN           _main:NEAR
EXTRN           __setargv__:NEAR
EXTRN           __setenvp__:NEAR
else
EXTRN           _wmain:NEAR
EXTRN           __wsetargv__:NEAR
EXTRN           __wsetenvp__:NEAR
endif
endif

ifndef _UNICODE
EXTRN           __startup:NEAR
else
EXTRN           __wstartup:NEAR
endif

endif

EXTRN           __matherr:NEAR
EXTRN           __matherrl:NEAR

ifndef  NOXX
EXTRN           __ExceptInit:NEAR
EXTRN           __GetExceptDLLinfoInternal:NEAR
endif

ifndef _UNICODE
EXTRN           GetModuleHandleA:NEAR
else
EXTRN           GetModuleHandleW:NEAR
endif

EXTRN           HeapAlloc:NEAR
EXTRN           HeapFree:NEAR
EXTRN           GetProcessHeap:NEAR

ifdef DLLDIAG
EXTRN           _wsprintfA:NEAR
EXTRN           OutputDebugStringA:NEAR
endif;DLLDIAG

_TEXT           ENDS

;----------------------------------------------------------------------
; External data definitions

_DATA           SEGMENT PUBLIC DWORD USE32 'DATA'

ifndef DLL       ; EXE startup
EXTRN           __fmode:NEAR
endif
EXTRN           __wargv_expand_ptr:NEAR
EXTRN           __argv_expand_ptr:NEAR
EXTRN           __handle_setargv:NEAR
EXTRN           __handle_exitargv:NEAR
EXTRN           __handle_wsetargv:NEAR
EXTRN           __handle_wexitargv:NEAR
EXTRN           __fileinfo:NEAR
EXTRN           __turboFloat:NEAR
_DATA           ENDS

;----------------------------------------------------------------------
; CV4 debugging information: a pointer to main, WinMain, or DllEntryPoint
;
ifndef __DEBUG__  ; Don't do this if we are building with debug info (/zi)
ifndef MASM ; MASM386 can't handle 'dp' directive

$$BSYMS         SEGMENT PUBLIC BYTE USE32 'DEBSYM'
                dd  2       ; magic
                dw  8       ; magic
                dw  210h    ; magic (S_ENTRY32)
ifdef DLL
                dp  DllEntryPoint
else
ifdef WINDOWS
ifndef _UNICODE
                dp  WinMain
else
                dp  wWinMain
endif
else
ifndef _UNICODE
                dp  _main
else
                dp  _wmain
endif
endif
endif
$$BSYMS         ENDS

endif   ; ndef MASM
endif   ; ndef __DEBUG__

;----------------------------------------------------------------------
; MODULE_DATA table.
;
; This table contains information about this EXE or DLL that is used
; by initexit.c to properly initialize or clean up the module.
; IMPORTANT: the layout must exactly match the MODULE_DATA structure
; definition in _startup.h!


_DATA           SEGMENT PUBLIC DWORD USE32 'DATA'

;
; This is the global instance of the module_data structure.  It must match
; the definition in _startup.h.  It is used from startup.c
;
; BEGIN TABLE - module_init
;
                align   4
module_data     dd      offset FLAT:InitStart
                dd      offset FLAT:InitEnd
                dd      offset FLAT:ExitStart
                dd      offset FLAT:ExitEnd

___isGUI label  byte                            ; VCLINIT.CPP in VCLExx.LIB uses
public ___isGUI                                 ; this as a byte.

ifdef WINDOWS OR DLL
                db      1                       ; flags for _isWindow
else
                db      0                       ; flags for _isWindow
endif
                db      0,0,0                   ; padding since _isWindow
                                                ; is 32-bits wide.

                dd      0                       ; module handle
ifdef DLL
                dd      offset FLAT:DllEntryPoint
                dd      0                       ; matherr
                dd      0                       ; matherrl
                dd      0                       ; stack base
                dd      0                       ; fmode
else
ifdef WINDOWS
ifndef _UNICODE
                dd      offset FLAT:WinMain
else
                dd      offset FLAT:wWinMain
endif
else
ifndef _UNICODE
                dd      offset FLAT:_main
else
                dd      offset FLAT:_wmain
endif
endif
                dd      offset FLAT:__matherr
                dd      offset FLAT:__matherrl
                dd      0                       ; stack base
                dd      offset FLAT:__fmode
endif

                dd      offset FLAT:__argv_expand_ptr  ; wild_func
                dd      offset FLAT:__wargv_expand_ptr ; wwild_func

                dd      offset FLAT:__handle_setargv    ; setargv_func
                dd      offset FLAT:__handle_exitargv   ; exitargv_func
                dd      offset FLAT:__handle_wsetargv   ; wsetargv_func
                dd      offset FLAT:__handle_wexitargv  ; wexitargv_func

                dd      offset FLAT:__fileinfo          ; controls child handle
                                                        ; inherritance
;
; END TABLE - module_init
;


public          ___isVCLPackage
ifdef VCLPACKAGE
___isVCLPackage db      1
else
___isVCLPackage db      0
endif

public          ___isDLL
ifdef DLL
___isDLL        db      1
else
___isDLL        db      0

;
; The following table is needed only to generate references (with fixupps)
; to the listed symbols.  The dwords don't need to be allocated and aren't
; used again, but this is the only way to guarantee that both EXTDEF and
; FIXUPP records are generated for these symbols.
;
; BEGIN TABLE - misc
;
ifndef _UNICODE
                dd      offset FLAT:__setargv__    ; for setting up argv[]
                dd      offset FLAT:__setenvp__    ; for setting up envp[]
else
                dd      offset FLAT:__wsetargv__   ; for setting up wargv[]
                dd      offset FLAT:__wsetenvp__   ; for setting up wenvp[]
endif
                dd      offset FLAT:__turboFloat   ; for setting up cvt_init
                                                   ; and scan_init
endif
;
; END TABLE - misc
;

public          ___useDynamicTLS
ifdef   DLL
___useDynamicTLS db      1
else
___useDynamicTLS db      0
endif

public          __TLS_index
__TLS_index     dd      0
public          __TLS_index4
__TLS_index4    dd      0

public          __hInstance
__hInstance     dd      0  ; Global _hInstance

ifdef SIMULATE_TLS
SimTLSSlot      dd      0  ; This is where the data is acutally stored
                           ; for the one and only simulated TLS slot.

SimTLSSlotInUse db      0  ; flag that allows us to do our initial
                           ; TLS memory allocation only on the first
                           ; thread created which is the main process
                           ; load thread.

SimTLSErrorSecondThread db 'SIMULATE_TLS: A second thread was about to be created and '
                        db 'the c0s32 startup code is in use', 0
endif ; SIMULATE_TLS

ifdef DLL
usecount        db      0
nonsharedMsg    db      'Nonshared DATA segment required',0
win32sMsg       db      'Cannot run multiple instances of a DLL under WIN32s',0
isDLLAttach     db      0  ; flag indicating process/thread attach/detach
endif ; DLL

TlsIndex EQU __TLS_index

;
; Currently, for the debugger to be able to get exception notifications for
; the PE files it debugs, we export the symbol ___CPPdebugHook.
; Eventually we may change the way the debugger finds this address and then
; be able to stop exporting it.  But for now it must be exported from all PE
; files.
;
; In the blinding haze of VCL package complexity, there exists an issue in
; the linker which requires this symbol to live in a VIRDEF for everything
; to work correctly when packages are created.  So here we create the virtual
; segment whos symbol is also exported.
;

___CPPdebugHook_segment segment virtual
___CPPdebugHook dd 0
___CPPdebugHook_segment ends

publicdll       ___CPPdebugHook ; export the symbol

ifdef DLL
;;;
;;;  This is a vector of functions to be called at DLL initialization time
;;;  to make sure that TLS is on line and initialized correctly for each
;;;  thread.
;;;
tlsProc         DD      offset PreExitProcessTLS ; PostExitProcess is called later
                DD      offset InitProcessTLS
                DD      offset InitThreadTLS
                DD      offset ExitThreadTLS

tlsCode         dd      -1 ; Used to remember the TLS code (0-3)

ifdef DLLDIAG
;
; Some diagnostic data.  If DLLDIAG is defined, then each DLLs startup code
; will log these four notifications to the debugger via OutputDebugString()
;
__0             db  'HMod: %08X: ExitProcess',0
__1             db  'HMod: %08X: InitProcess',0
__2             db  'HMod: %08X: InitThread',0
__3             db  'HMod: %08X: ExitThread',0
tlsProcStr      dd  offset __0
                dd  offset __1
                dd  offset __2
                dd  offset __3
tlsStrBuf       db  100d dup (0)
endif ; DLLDIAG
endif ; DLL

_DATA           ENDS

;----------------------------------------------------------------------
; Startup code

_TEXT           SEGMENT  DWORD USE32 PUBLIC 'CODE'

                public __acrtused
__acrtused      PROC NEAR
 ;
 ; The entrypoint of all PE files will now contain a jump around the address
 ; of the debugger hook vector.  Eventually, the debugger will load it from
 ; here, but for now the debugger still looks for the exported name.
 ;
 ; We need to touch this symbol somewhere in the startup code so that it
 ; doesn't get smart-linked out, and the most logical place to put it was here
 ; where it will eventually need to be when we change the debugger to look
 ; for it here and not to use the exported name.
 ;
                jmp     skip_dbg_vector
                db      'fb:C++HOOK'           ; special signature
                nop                            ; alignment byte
                db      0E9h                   ; encode a jmp instruction
                                               ; so that the disassembler in
                                               ; the IDE can see past this
                                               ; address to the skip_dbg_vector
                dd      offset ___CPPdebugHook_segment
skip_dbg_vector:
                mov     eax, __TLS_index
                shl     eax, 2
                mov     __TLS_index4, eax

ifdef DLL
ifdef DLLDIAG
                pushad                          ; decrements esp by 020h
                mov      eax, [esp+20h+04h]     ; Get DLL hInstance
                mov      edx, [esp+20h+08h]     ; 0-3 code
                push     eax
                mov      eax, tlsProcStr[edx*4]
                push     eax
                push     offset tlsStrBuf
                call     _wsprintfA
                ; wsprintf (tlsStrBuf, tlsProcStr[code], code);
                add      esp, 0Ch               ; clean up stack for cdecl
                push     offset tlsStrBuf
                call     OutputDebugStringA
                popad

endif;DLLDIAG
                ;; Do the appropriate TLS initialization
                mov     eax, [esp+8]
                mov     [tlsCode], eax
                call    dword ptr tlsProc[eax*4]

;;  If we are attaching to a process, make sure that we have a per-instance data segment.
;;  If we do not, then determine whether it's due to NONSHARED or Win32s limitation.
                cmp     dword ptr [tlsCode], 1
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
if      BSSINIT
ifdef   DLL
                cmp     dword ptr [tlsCode], 1    ; Check whether Process Attach
                jne     skipBSSInit
endif
                push    edi
                push    ecx

                xor     eax, eax
                mov     edi, offset DGROUP: bdata@
                mov     ecx, offset DGROUP: edata@
                cmp     ecx, edi
                jna     BSSInitDone
if      FULLBSS
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
ifdef   DLL
;;
;; We only want to preform the following CRTL_xxx stuff when the DLL is
;; initally loaded.
;;
                cmp     dword ptr [tlsCode], 1  ; are we in DLL_PROCESS_ATTACH?
                jne     skip_CRTL_xxxx

;;
;; CRTL_DLL_Lock - locks the RTL (with a LoadLibrary) when the DLL being built
;;                 (which is using this startup code) is linked to the RTLDLL's
;;                 import library.  Else, the static RTL stubs out this call.
;;
;;                 This is needed for Windows95/98 since it has problems
;;                 unloading DLLs which have references to other DLLs that may
;;                 be both implicitly and explicitly loaded.  WinNT handles
;;                 this properly, and this extra locking shouldn't affect it.
;;
                call    ___CRTL_DLL_Lock        ; Lock the RTLDLL

endif ; DLL

;; If we're linked to the CPxxx libs, this function will be from the
;; CRTLVCL module and will initialize some VCL stuff
;;
;; If we're linked to the CWxxx libs, this function will be from the
;; CRTLSTUB module and will do nothing but return.

                push     edx
ifdef   DLL
                mov      edx, [esp+8]           ; Get DLL hInstance
else  ; DLL
                push    0                       ; NULL returns current module
  ifndef  _UNICODE
                call    GetModuleHandleA
  else  ; _UNICODE
                call    GetModuleHandleW
  endif ; _UNICODE
                mov     edx, eax
endif ; DLL
                call    ___CRTL_VCL_Init        ; EDX now has hInstance in it
                pop     edx

                call    ___CRTL_MEM_UseBorMM    ; Call out to potentially
                                                ; re-vector the memory manager

                call    ___CRTL_VCLLIB_Linkage  ; Call out to touch a symbol
                                                ; that will be undefined if
                                                ; vcl.lib was used with any
                                                ; of the CW32xx forms of the
                                                ; RTL.
skip_CRTL_xxxx:

ifndef  NOXX

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
endif ; NOXX

not_process_attach:

                push    offset FLAT:module_data
ifdef DLL

                mov     eax, [esp+8]            ; get mod_handle to
                mov     __hInstance, eax        ; initialize _hInstance

;;
;;  DLL entry points:  Some DLLs, like MFC, supply 2 entry points -
;;  RawDllMain and DllMain.
;;
;;  RawDllMain must be called * BEFORE * DllMain on process/thread attach.
;;  RawDllmain must be called * AFTER  * DllMain on process/thread detach.
;;
                cmp     dword ptr [tlsCode], 1  ; are we in DLL_PROCESS_ATTACH?
                je      flag_attach
                cmp     dword ptr [tlsCode], 2  ; are we in DLL_THREAD_ATTACH?
                je      flag_attach
;;
;;  By this point, we know we are detaching, so call __startupd (which
;;  calls DllMain) first, then call RawDllmain
;;
ifndef _UNICODE
                call    __startupd
else
                call    __wstartupd
endif
                mov     isDLLAttach, 0
                jmp     call_rawdllmain         ; we are detaching, so go
                                                ; straight to RawDllMain

flag_attach:
                mov     isDLLAttach, 1


;;
;;  Call _pRawDllMain if it's set.
;;
call_rawdllmain:
                cmp     dword ptr [__pRawDllMain], 0
                je      call_startupd

                push    eax                     ; __hInstance
                mov     eax, [tlsCode]          ; get 'reason'
                push    eax
                mov     eax, [esp+18h]          ; get 'reserved'
                                                ; [esp+18h] = 10h + 8 from two
                                                ; prior pushes: module_data,
                                                ; and __hInstance.
                push    eax

                call    dword ptr [__pRawDllMain] ; Call the user's function
                                                  ; __stdcall so no cleanup
                                                  ; needed.
;;
;;  If we are attaching, call __startupd.  If not, don't.
;;

call_startupd:
                cmp     isDLLAttach, 0
                je      return

ifndef _UNICODE
                call    __startupd
else
                call    __wstartupd
endif

return:
                add     esp, 4                  ; discard module_data parameter
                ; check whether Process Detach (0)
                cmp     dword ptr [tlsCode], 0
                jne     ReturnNT

; We only get here when the DLLs final ExitProcessTls routine finishes
; Now we do some last minute cleanup.

                call    __free_heaps

                call    ___CRTL_VCL_Exit        ; Do VCL exiting stuff if needed
                call    ___CRTL_DLL_Unlock      ; Unlock the RTLDLL if needed
                                                ;  (such as when under Win95)

                call    PostExitProcessTLS      ; do the final TLS cleanup
ReturnNT:
                ret     12                      ; return to NT
else  ; DLL
                push    0                       ; NULL returns current module
ifndef  _UNICODE
                call    GetModuleHandleA
else
                call    GetModuleHandleW
endif
                mov     __hInstance, eax

                push    0                       ; dummy return address
ifndef  _UNICODE
                jmp     __startup
else
                jmp     __wstartup
endif
endif ; DLL

__acrtused      ENDP

ifndef  NOXX
ifdef   DLL
public          __GetExceptDLLinfo
else
publicdll       __GetExceptDLLinfo
endif

__GetExceptDLLinfo      proc    near
                jmp     __GetExceptDLLinfoInternal
__GetExceptDLLinfo      ENDP
endif   ;NOXX

public  __isDLL
__isDLL         proc    near
                xor     eax, eax
                mov     al, ___isDLL
                ret
__isDLL         ENDP

public  __getHInstance
__getHInstance  proc    near
                mov     eax, __hInstance
                ret
__getHInstance  ENDP


;;;
;;;  Support for __declspec(thread) in all incarnations.
;;;

RunError        proc near
;
; Ok, here we want to signal a harsh failure, so we jump to an address that
; we know isn't loaded. (00000BADh)
;
;
;
                pushad                 ; Attempt to save all registers.
                mov     ebx,0BCB05000h ; Give us a chance to recognize this.
                push    ebx            ; Put this on the stack too.
                                       ; EAX should have a reason code in it
                push    00000BADh
                ret
RunError        endp

InitThreadTLS   proc near
                mov     ecx, offset THREADGROUP: etls@
                or      ecx, ecx
                je      @@done          ; No TLS section, so don't bother
                cmp     TlsIndex, 0
                jae     @@doAlloc
                mov     eax, 255-1        ; Very bad
                call    RunError
@@doAlloc:
ifdef  SIMULATE_TLS
                cmp     [SimTLSSlotInUse], 0 ; Only alloc the memory if we're
                                             ; the first thread in, which
                                             ; means ProcessInit time.
                jne     @@done
                mov     [SimTLSSlotInUse], 1 ; set the flag so we know not to
                                             ; alloc again.
endif ; SIMULATE_TLS
                mov     ecx, offset THREADGROUP: etls@
                push    ecx             ; size for HeapAlloc
                push    HEAP_ZERO_MEMORY; flags for HeapAlloc
                call    GetProcessHeap
                push    eax             ; handle to the process heap
                call    HeapAlloc
                or      eax, eax
                jne     @@setValue
                mov     eax, 255-2        ; Very bad
                call    RunError
@@setValue:
;
;  Here we will allocate a block of data the size of the TLS section.  We
;  then copy the TLS section into this block, and the block is used during
;  the life of the thread.  If another thread is created, this happens the
;  same way for it too.  When the compiler needs to refer to a piece of data
;  in the TLS section it will always generate a call to the ___System__GetTls
;  function to get the address of this block of memory, instead of going
;  directly to the TLS area.  Therefore, the TLS section should never change,
;  and only the local copies of the same data in this thread specific block
;  will be modified.  Also note that this is only for DLLs.  Exe's will be
;  supported directly by the OS.  -- 08/21/97 jjp
;
ifdef DLL
                push    edi             ; Save edi
                push    esi             ; Save esi
endif ; DLL
                push    eax             ; Save a copy of the mem block for edi
                push    eax             ; value for TlsSetValue
                push    TlsIndex
                call    ___CRTL_TLS_SetValue

                push    TlsIndex
                call    ___CRTL_TLS_InitThread

                pop     edi             ; put mem block into dest. reg.

ifdef DLL
;
; This isn't implemented yet.  Thus don't assume any inited TLS data in DLLs
; will contain any value other than 0 (for now...)
;
comment ~
                call    GetStartOfTLS
                mov     esi, eax        ; start addr. of initialized TLS data
                mov     ecx, offset THREADGROUP: etls@
                cld
                rep     movsb           ; copy TLS into our mem block
~
                pop     esi             ; restore esi
                pop     edi             ; restore edi
endif ; DLL
@@done:
                ret
InitThreadTLS   ENDP

InitProcessTLS  proc near
                mov     ecx, offset THREADGROUP: etls@
                or      ecx, ecx
                je      @@done          ; No TLS section, so don't bother

                call    ___CRTL_TLS_Alloc
                mov     TlsIndex, eax
                cmp     eax, 0
                jae     InitThreadTLS
                mov     eax, 255-3        ; Very bad, TlsAlloc failed
                call    RunError
@@done:
                ret
InitProcessTLS  ENDP

ExitThreadTLS   proc    near
                cmp     TlsIndex, 0
                jb      @@done
                push    TlsIndex
                call    ___CRTL_TLS_GetValue
                or      eax, eax
                je      @@done
ifdef  SIMULATE_TLS
                cmp     [SimTLSSlotInUse], 1 ; Only free the memory if we're
                                             ; exiting the thread that loaded us.
                                             ; This is determined by PostExitProcessTLS
                je      @@done
endif ; SIMULATE_TLS

                push    eax             ; block to be freed
                push    HEAP_ZERO_MEMORY; flags for HeapAlloc
                call    GetProcessHeap
                push    eax             ; handle to the process heap
                call    HeapFree

                push    TlsIndex
                call    ___CRTL_TLS_ExitThread

@@done:
                ret
ExitThreadTLS   ENDP

PreExitProcessTLS proc near
; This is only a stub function.  The real work for Process Exit is preformed
; in PostExitProcessTLS and is called after the DLLs start/exit routines are
; done and some other cleanup is finnished.
                ret
PreExitProcessTLS ENDP

PostExitProcessTLS  proc    near
                cmp     TlsIndex, 0
                jb      @@done
ifdef  SIMULATE_TLS
                mov     [SimTLSSlotInUse], 0 ; Zero this flag so that
                                             ; ExitThreadTLS knows that we're
                                             ; leaving and thus frees
                                             ; the allocated memory.

endif ; SIMULATE_TLS
                call    ExitThreadTLS
                push    TlsIndex
                call    ___CRTL_TLS_Free
@@done:
                ret
PostExitProcessTLS  ENDP

ifdef DLL
;
;  GetStartOfTLS returns the RVA of the TLS section in eax
;
;GetStartOfTLS   proc near
;                lea     eax, __acrtused[-1000h]  ; Dos EXE Header offset
;                add     eax, [eax + 3Ch]         ; PE Header @ 03Ch
;                add     eax, 0C0h                ; TLS Dir. offset @ 0C0h
;                mov     eax, [eax]               ; TLS RVA is first element in
;                                                 ;  TLS Dir.
;                ret
;GetStartOfTLS   ENDP
endif ; DLL

public  ___System__GetTls
public    @Sysinit@@GetTls$qqrv
___System__GetTls       proc    near    ; C/C++ entry point
@Sysinit@@GetTls$qqrv:    ; VCL   entry point

ifndef   DLL
; For EXEs we use the fast FS: method
                mov     eax,TlsIndex
                mov     edx, dword ptr FS:[2ch]
                mov     eax,[edx+eax*4]
                ret
else ; DLL
;
; For DLLs we use the slower API method that is sub-allocated in the RTLDLL
;

                cmp     TlsIndex, 0     ; If 0 then it needs to be allocated
                jnz     sgtls_next
;
; Now we must allocate a pseudo slot since there is none now.
;
                call    ___CRTL_TLS_Alloc
                mov     TlsIndex, eax

sgtls_next:
                push    TlsIndex
                call    ___CRTL_TLS_GetValue
                test    eax,eax
                je      @@initTls
                ret

@@initTls:
;
; We get here in the case the DLL has called the API DisableThreadLibraryCalls
; and thus our InitThreadTLS callback was never executed.  So here we call it
; to initialize its stuff.
;
                call    InitThreadTLS
                mov     eax,TlsIndex
                push    eax
                call    ___CRTL_TLS_GetValue
                ret
endif
___System__GetTls       ENDP
ifdef VCLPACKAGE
;
; This code provides some of the support needed for loading VCL Packages.
;
extrn @System@@PackageLoad$qqrpx23System@PackageInfoTablep17System@TLibModule:near
extrn @System@@PackageUnload$qqrpx23System@PackageInfoTablep17System@TLibModule:near
extrn __PackageInfoTable:near

public @GetPackageInfoTable
@GetPackageInfoTable proc near
                mov     eax, offset __PackageInfoTable
                ret
@GetPackageInfoTable endp

; Eventually the internal names in the EXPDEFs for both Initialize and
;  Finalize should be renamed to something like @PackageLoad and @PackageUnload.
;  If we need to do this now before we get the syntax for PUBLICDLL enhanced,
;  Something like the following ?debug statement could be used, but this
;  would prevent this file from being assembled with debug info (not good).
;
; make an EXPDEF record with a different external name than the internal one:
;
; ; ?debug  C A00200 0A "Initialize" 0C "@PackageLoad" ; syntax not accepted
;   ?debug  C A002000A496E697469616C697A650C405061636B6167654C6F6164 ; ok

;@PackageLoad proc near
Initialize proc near
                mov     eax, offset __PackageInfoTable
                mov     edx, [eax]
                call    @System@@PackageLoad$qqrpx23System@PackageInfoTablep17System@TLibModule
                ret
;@PackageLoad endp
Initialize endp


;@PackageUnload proc near
Finalize proc near
                mov     eax, offset __PackageInfoTable
                mov     edx, [eax]
                call    @System@@PackageUnload$qqrpx23System@PackageInfoTablep17System@TLibModule
                ret
;@PackageUnload endp
Finalize endp

publicdll Initialize, Finalize

endif ; VCLPACKAGE

ifdef SIMULATE_TLS
;---------------------------------------------------------------------------
;
; This code implements the ___CRTL_TLS_xxx routines in order simulate
; a working TLS system for systems that guarantee that they will only
; have one thread ever.  This allows using the multithreaded RTL and
; VCL libs without burning up any system TLS slots.
;
extrn __ErrorExit: near

SIMULATED_TLS_SLOT_ID    = 1

CheckSimSlot proc near
                cmp     eax, SIMULATED_TLS_SLOT_ID
                je      @@1
                mov     eax, 255-4
                call    RunError
@@1:
                ret     ; eax still has the passed in value here
CheckSimSlot endp


___CRTL_TLS_Alloc proc near
                mov     eax, SIMULATED_TLS_SLOT_ID
                ret
___CRTL_TLS_Alloc endp


___CRTL_TLS_Free proc near
                mov     eax, [esp+4]
                call    CheckSimSlot
                mov     eax, 1            ; success
                ret     4
___CRTL_TLS_Free endp


___CRTL_TLS_GetValue proc near
                mov     eax, [esp+4]
                call    CheckSimSlot
                mov     eax, [SimTLSSlot]
                ret     4
___CRTL_TLS_GetValue endp


___CRTL_TLS_SetValue proc near
                ; esp+4 -> id
                ; esp+8 -> value to save
                mov     eax, [esp+4]
                call    CheckSimSlot
                mov     eax, [esp+8]
                mov     [SimTLSSlot], eax
                ret     8
___CRTL_TLS_SetValue endp


___CRTL_TLS_InitThread proc near
                mov     eax, [esp+4]
                call    CheckSimSlot
                ret     4
___CRTL_TLS_InitThread endp


___CRTL_TLS_ExitThread proc near
                mov     eax, [esp+4]
                call    CheckSimSlot
                ret     4
___CRTL_TLS_ExitThread endp


;
; The following four symbols are purposely not defined in order to cause
; meaningful error messages during linktime if the VIRDEF'ed entrypoints
; that jmp to them are ever called.
;
extrn __c0s32_obj_does_not_support_calling__beginthread:near
extrn __c0s32_obj_does_not_support_calling__beginthreadex:near
extrn __c0s32_obj_does_not_support_calling__beginthreadNT:near
extrn __c0s32_obj_does_not_support_using_VCL_TThread_class:near

;
; Any of these VIRDEF'ed routines will cause a linker error if they are
; touched.  If the user still insists on using the PE file after getting
; the link errors, we provide a useful runtime error message that kills
; the app before the un-fixed-up 0x0BADC0DE address faults
;
__beginthread segment virtual
@__beginthread proc near
                push    offset SimTLSErrorSecondThread
                call    __ErrorExit  ; This never returns
                jmp     __c0s32_obj_does_not_support_calling__beginthread
@__beginthread endp
__beginthread ends

__beginthreadex segment virtual
@__beginthreadex proc near
                push    offset SimTLSErrorSecondThread
                call    __ErrorExit  ; This never returns
                jmp     __c0s32_obj_does_not_support_calling__beginthreadex
@__beginthreadex endp
__beginthreadex ends

__beginthreadNT segment virtual
@__beginthreadNT proc near
                push    offset SimTLSErrorSecondThread
                call    __ErrorExit  ; This never returns
                jmp     __c0s32_obj_does_not_support_calling__beginthreadNT
@__beginthreadNT endp
__beginthreadNT ends

@System@BeginThread$qqrpvuipqqrpv$it1uirui segment virtual ; VCL entry point
_@System@BeginThread$qqrpvuipqqrpv$it1uirui proc near
                push    offset SimTLSErrorSecondThread
                call    __ErrorExit  ; This never returns
                jmp     __c0s32_obj_does_not_support_using_VCL_TThread_class
_@System@BeginThread$qqrpvuipqqrpv$it1uirui endp
@System@BeginThread$qqrpvuipqqrpv$it1uirui ends


public           ___CRTL_TLS_Alloc
public           ___CRTL_TLS_Free
public           ___CRTL_TLS_GetValue
public           ___CRTL_TLS_SetValue
public           ___CRTL_TLS_InitThread
public           ___CRTL_TLS_ExitThread

;---------------------------------------------------------------------------

endif ; SIMULATE_TLS

_TEXT           ENDS

                END     __acrtused
