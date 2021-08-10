;[]-----------------------------------------------------------------[]
;|   LOG10L.ASM -- base 10 logarithm (long double)                   |
;[]-----------------------------------------------------------------[]

;
;       C/C++ Run Time Library - Version 11.0
; 
;       Copyright (c) 1991, 2002 by Borland Software Corporation
;       All Rights Reserved.
; 

; $Revision: 9.3 $

;----------------------------------------------------------------------
; function(s)
;        log10l - base 10 logarithm function (long double)
;----------------------------------------------------------------------

        include RULES.ASI
        include _MATH.INC

;       Segments Definitions

Header@

;----------------------------------------------------------------------
; External and local variables

Data_Seg@

ExtSym@         _huge_ldble, tbyte, cdecl
_LHUGE_VAL      equ     _huge_ldble@

NANLOGL         dw      0,0,0,0C024H,0FFFFH

Data_EndS@

;--------------------------------------------------------------------------
;
;Name            log10l - base 10 logarithm function of long double
;
;Usage           long double log10l(long double x);
;
;Prototype in    math.h
;
;Description     log10l calculates  the base 10 logarithm of x, which must be
;                greater than zero.
;
;Return value    log10l  returns the  base 10 logarithm of x, which must be
;                greater than zero.
;
;--------------------------------------------------------------------------

Code_Seg@

Func@   log10l, _EXPFUNC, _RTLENTRY, <longdouble x>
Locals@ <longdouble temp>, <word filler>
                                        ; (filler pads the stack to align 4)
        Link@   ebx

        FLD     x.longdouble

        mov     ax, W0 (x [8])          ; get the exponent field
        shl     ax, 1
        jz      l10_zero
        jc      l10_imaginary
        cmp     ax, 0FFFEh
        je      l10_infinite

        f87     Log10
l10_end:
        Unlink@ ebx
        Return@

l10_zero:
        mov     edx, SING
        fld     _LHUGE_VAL.longdouble           ; temp = -_LHUGE_VAL;
        fchs
        fstp    temp.longdouble
        lea     ecx, temp
        jmp     short   l10_complain

l10_infinite:
        mov     edx, OVERFLOW
        mov     ecx, offset FLAT: _LHUGE_VAL
        jmp     short   l10_complain

l10_imaginary:
        mov     edx, DOMAIN
        mov     ecx, offset FLAT: NANLOGL

l10_complain:
        FSTP    ST(0)                   ; pop x from stack

;       return  __matherrl (_EDX, "log10l", &x, NULL, *(long double *)_ECX);

        matherrl edx, log10l, x, NULL, [ecx]
        jmp     l10_end

EndFunc@ log10l

Code_EndS@
        end
