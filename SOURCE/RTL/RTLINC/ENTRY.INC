;[]-----------------------------------------------------------------[]
;|      ENTRY.INC  --  macro for definining library entry points     |
;[]-----------------------------------------------------------------[]

;
;       C/C++ Run Time Library - Version 11.0
; 
;       Copyright (c) 1991, 2002 by Borland Software Corporation
;       All Rights Reserved.
; 



; $Revision: 9.4.2.1 $

;----------------------------------------------------------------------
; Name      Entry@  - define a user-callable entry point
;
; Usage     Entry@ pubname, extname, calltype, parmsize
;
; Notes     The Entry@ macro defines a user-callable entry point
;           to an internal library function.  Pubname specifies
;           the name of the user-callable entry point.  Extname specifies
;           the name of the internal library function.  Calltype
;           specifies the calling convention (_RTLENTRY, _RTLENTRYF, cdecl,
;           pascal, or stdcall).  Parmsize specifies the number of
;           bytes of parameters passed to the function.
;
;           The effect of the macro is to generate a public label
;           and a JMP instruction.

Entry@  macro   pubname, extname, calltype, parmsize
        Header@
        Code_Seg@
ifdef _BUILDRTLDLL
        Mangle@ publicdll, pubname, <>,        calltype, parmsize
else
        Mangle@ public, pubname, <>,        calltype, parmsize
endif
        Mangle@ extrn, extname, <:near>,    calltype, parmsize
        Mangle@ <>, pubname, <proc near>,   calltype, parmsize
        Mangle@ jmp, extname, <>,           calltype, parmsize
        align 4
        Mangle@ <>, pubname, <endp>,        calltype, parmsize
        Code_EndS@
        endm
