;[]-----------------------------------------------------------------[]
;|   TA.ASM -- helper functions for XX.CPP                           |
;[]-----------------------------------------------------------------[]

;
;       C/C++ Run Time Library - Version 11.0
; 
;       Copyright (c) 1992, 2002 by Borland Software Corporation
;       All Rights Reserved.
; 

; $Revision: 9.4.2.1 $

;------------------------------------------------------------------

                .386

;------------------------------------------------------------------

                public  @jump$qv
                public  ___doGlobalUnwind
                public  @invokeHnd$qv

ifdef   __WIN32__
                extrn   RtlUnwind:near
else
                extrn   DosUnwindException:near
endif

;------------------------------------------------------------------

_TEXT           segment dword public use32 'CODE'
_TEXT           ends
_DATA           segment dword public use32 'DATA'
_DATA           ends
_BSS            segment dword public use32 'BSS'
_BSS            ends

ifndef MASM
                .model  FLAT
endif

                assume  cs: FLAT, ds: FLAT, ss: FLAT, es: FLAT

_TEXT           segment dword public use32 'CODE'

;------------------------------------------------------------------

@jump$qv        proc    near

                mov     esp, ebx
                mov     ebp, ecx
                jmp     eax

@jump$qv        endp

;------------------------------------------------------------------

___doGlobalUnwind proc    near

                push    ebx
                push    esi
                push    edi

ifdef   __WIN32__		
		push	0
endif
                push    edx                     ; descriptor addr
                push    offset FLAT:return      ; target EIP
                push    eax                     ; target ERR addr
ifdef   __WIN32__
                call    RtlUnwind
else
                call    DosUnwindException
endif

return:
ifndef  __WIN32__
		add	esp,12
endif
                pop     edi
                pop     esi
                pop     ebx

                ret

                endp

;------------------------------------------------------------------

@invokeHnd$qv   proc    near

                push    ebp

                mov     ebp, ecx
                call    [ebx]

                pop     ebp
                ret


@invokeHnd$qv   endp

;------------------------------------------------------------------

_TEXT           ends
                end
