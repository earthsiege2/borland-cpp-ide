;[]-----------------------------------------------------------------[]
;|   LOG10.ASM -- base 10 logarithm                                  |
;[]-----------------------------------------------------------------[]

;
;       C/C++ Run Time Library - Version 2.0
; 
;       Copyright (c) 1991, 1996 by Borland International
;       All Rights Reserved.
; 

;----------------------------------------------------------------------
; function(s)
;       log10 - base 10 logarithm function
;----------------------------------------------------------------------

        include RULES.ASI
        include _MATH.INC

;       Segments Definitions

Header@

;----------------------------------------------------------------------
; External and local variables

Data_Seg@

ExtSym@         _huge_dble, qword, cdecl
HUGE_VAL        equ     _huge_dble@

NANLOG          dw      0,0,00480H, 0FFF8H

Data_EndS@

;--------------------------------------------------------------------------
;
;Name            log10 - base 10 logarithm function
;
;Usage           double log10(double x);
;
;Prototype in    math.h
;
;Description     log10 calculates the base 10 logarithm of x, which must be
;                greater than zero.
;
;Return value    log10 returns  the base 10 logarithm of x, which must be
;                greater than zero.
;
;--------------------------------------------------------------------------

Code_Seg@

Func@   log10, _EXPFUNC, _RTLENTRY, <double x>
Locals@ <double temp>

        Link@   ebx

        FLD     x.double

        mov     ax, W0 (x [6])          ; get the exponent field
        shl     ax, 1
        jz      l10_zero
        jc      l10_imaginary
        cmp     ax, 0FFE0h
        je      l10_infinite

        f87     Log10
l10_end:
        Unlink@ ebx
        Return@

l10_zero:
        mov     edx, SING
        fld     HUGE_VAL.double         ; temp = -HUGE_VAL;
        fchs
        fstp    temp.double
        lea     ecx, temp
        jmp     short   l10_complain

l10_infinite:
        mov     edx, OVERFLOW
        mov     ecx, offset FLAT: HUGE_VAL
        jmp     short   l10_complain

l10_imaginary:
        mov     edx, DOMAIN
        mov     ecx, offset FLAT: NANLOG

l10_complain:
        FSTP    ST(0)                   ; pop x from stack

;       return  __matherr (_EDX, "log10", &x, NULL, *(double *)_ECX);

        matherr edx, log10, x, NULL, [ecx]
        jmp     l10_end

EndFunc@ log10

Code_EndS@
        end
