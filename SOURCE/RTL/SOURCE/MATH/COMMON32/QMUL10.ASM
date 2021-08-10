;[]-----------------------------------------------------------------[]
;|   QMUL10.ASM -- multiply quadword integer by 10                   |
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
;Name           _qmul10 - multiply quadword integer by 10
;
;Usage          int _qmul10(long *quadint, int digit)
;
;Prototype in   _math.h
;
;Description    This is a helper function for scantod.c.  It multiplies the
;               unsigned 64-bit integer (pointed to by quadint) by 10 and
;               adds digit.
;
;Return value   Zero if no overflow occurred, or a non-zero value if
;               an overflow occurred.
;
;------------------------------------------------------------------------

Code_seg@

Func@   _qmul10, public, _RTLENTRY, <pointer quadint>, <int digit>

        Link@   esi, edi
        mov     esi, quadint            ; get pointer to quadword
        mov     ecx, 10

        mov     eax, [esi]              ; multiply low 32 bits
        mul     ecx                     ; EDX:EAX = EAX * 10
        add     eax, digit              ; add digit
        adc     edx, 0
        mov     [esi], eax
        mov     edi, edx                ; save high 32 bits of multiply

        mov     eax, [esi+4]            ; multiply high 32 bits
        mul     ecx
        add     eax, edi                ; add overflow from low 32 bits
        adc     edx, 0    
        mov     [esi+4], eax
        mov     eax, edx                ; return overflow word

        Unlink@ esi, edi
        Return@

EndFunc@ _qmul10

Code_EndS@

        end
