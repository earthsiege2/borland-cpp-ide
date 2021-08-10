;[]-----------------------------------------------------------------[]
;|   FUILDQ.ASM -- convert quadword unsigned integer to long double  |
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
;Name           _fuildq - convert a quadword unsigned integer to a long double
;
;Usage          long double _fuildq(long *valP);
;
;Prototype in   _math.h
;
;Description    This is a helper function for scantod.c.  It converts
;               the 64-bit unsigned integer pointed to by valP to a
;               long double.
;
;Return value   _fuildq returns the converted value (i.e. leaves the
;               long double value on the top of the x87 stack).
;
;------------------------------------------------------------------------

Code_seg@

Func@   _fuildq, public, _RTLENTRY, <pointer valP>
Locals@ <tbyte temp>

        Link@
        mov     eax,valP                ; get pointer to quadword
        test    byte ptr [eax+7], 80h   ; is sign bit set?
        jnz     signed                  ; yes - treat as special case
        fild    qword ptr [eax]         ; convert the value, leave on TOS
        Unlink@
        Return@

; The fild instruction treats numbers as signed, but we want to load
; unsigned numbers, and this number has the sign bit set.  This means
; that the number is greater than or equal to 2^63.  We can simply leave
; the number where it is for the mantissa, since it's already normalized
; and in the correct position.  Then all we have to do is set the exponent
; field to 63.

signed:
        mov     ecx, [eax]              ; copy the mantissa to temp variable
        mov     temp, ecx
        mov     ecx, [eax+4]
        mov     temp+4, ecx
        mov     word ptr temp+8, 403Eh  ; set exponent to 63 (biased)
        fld     tbyte ptr temp          ; load the number in the FPU
        Unlink@
        Return@
        
EndFunc@ _fuildq

Code_EndS@

        end
