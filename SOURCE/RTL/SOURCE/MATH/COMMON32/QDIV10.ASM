;[]-----------------------------------------------------------------[]
;|   QDIV10.ASM -- divide quadword integer by 10                     |
;[]-----------------------------------------------------------------[]

;
;       C/C++ Run Time Library - Version 2.0
; 
;       Copyright (c) 1991, 1996 by Borland International
;       All Rights Reserved.
; 

        include RULES.ASI

;       Segments Definitions

Header@

;-----------------------------------------------------------------------
;
;Name           _qdiv10 - divide quadword integer by10
;
;Usage          int _qdiv10(long *quadint)
;
;Prototype in   _math.h
;
;Description    This is a helper function for xcvt.  It divides the
;               unsigned 64-bit integer (pointed to by quadint) by 10, and
;               returns the remainder.
;
;Return value   The remainder of *quadint/10.
;
;------------------------------------------------------------------------

Code_seg@

Func@   _qdiv10, public, _RTLENTRY, <pointer quadint>

        Link@   esi
        mov     esi, quadint            ; get pointer to quadword
        mov     ecx, 10

        mov     eax, [esi+4]            ; divide high 32 bits
        xor     edx, edx
        or      eax,eax                 ; skip the division if zero
        jz      low32
        div     ecx
        mov     [esi+4], eax
low32:
        mov     eax, [esi]              ; divide low 32 bits
        div     ecx
        mov     [esi], eax
        mov     eax, edx                ; return remainder

        Unlink@ esi
        Return@

EndFunc@ _qdiv10

Code_EndS@

        end
