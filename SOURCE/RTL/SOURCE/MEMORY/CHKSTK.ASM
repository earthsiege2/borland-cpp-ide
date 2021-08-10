;[]-----------------------------------------------------------------[]
;|   CHKSTK.ASM -- allocate local stack space                        |
;[]-----------------------------------------------------------------[]

;
;       C/C++ Run Time Library - Version 11.0
; 
;       Copyright (c) 1991, 2002 by Borland Software Corporation
;       All Rights Reserved.
; 

; $Revision: 9.4.2.1 $

        include RULES.ASI
        include INIT.INC

;       Segments Definitions

        Header@

;----------------------------------------------------------------------
; Name          __chkstk - allocate temporary stack memory
;
; Description   __chkstk is a helper function for the compiler.  It is
;               called in the prologue to a function that has more than
;               4K bytes of local variables.  It performs a stack probe
;               by poking all pages in the new stack area, then allocates
;               the required stack space.  The number of bytes to
;               allocate is passed in EAX.
;
;               A typical function prologue that uses __chkstk looks
;               like this:
;
;                   PUSH    EBP
;                   MOV     EBP,ESP
;                   MOV     EAX,1234H       ; no. of bytes of locals
;                   CALL    __chkstk        ; allocate locals
;----------------------------------------------------------------------

        Code_seg@

Func@   _chkstk, public, cdecl

        pop     edx             ; pop return address
        mov     ecx, 1000h      ; page size is 4K
loop1:
        cmp     eax, ecx        ; more than 4K left?
        jae     probe
        mov     ecx, eax        ; less than 4K - make this our bump count
probe:
        sub     esp, ecx        ; bump stack down a bit
        mov     [esp], eax      ; probe this page
        sub     eax, ecx        ; decrement no. of bytes left
        jnz     loop1
        jmp     edx             ; return to caller

EndFunc@ _chkstk

        Code_EndS@

;----------------------------------------------------------------------
; Cause the _initstk function to be called at startup time.  This
; will set up things for automatic stack growth and checking.

        InitExt@ _initstk, 0, _RTLENTRY

        end
