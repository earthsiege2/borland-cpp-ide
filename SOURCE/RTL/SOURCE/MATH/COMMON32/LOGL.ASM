;[]-----------------------------------------------------------------[]
;|   LOGL.ASM -- natural logarithm (long double)                     |
;[]-----------------------------------------------------------------[]

;
;       C/C++ Run Time Library - Version 2.0
; 
;       Copyright (c) 1991, 1996 by Borland International
;       All Rights Reserved.
; 

;----------------------------------------------------------------------
; function(s)
;        logl - natural logarithm function
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
;Name            logl - natural logarithm function of long double
;
;Usage           long double logl(long double x);
;
;Prototype in    math.h
;
;Description     logl calculates  the natural logarithm of x, which must be
;                greater than zero.
;
;Return value    logl  returns the  natural logarithm of x, which must be
;                greater than zero.
;
;--------------------------------------------------------------------------

Code_Seg@

Func@   logl, _EXPFUNC, _RTLENTRY, <longdouble x>
Locals@ <longdouble temp>

        Link@   ebx

        FLD     x.longdouble

        mov     ax, W0 (x [8])          ; get the exponent field
        shl     ax, 1
        jz      log_zero
        jc      log_imaginary
        cmp     ax, 0FFFEh
        je      log_infinite

        f87     Log
log_end:
        Unlink@ ebx
        Return@

log_zero:
        mov     edx, SING
        fld     _LHUGE_VAL.longdouble           ; temp = -_LHUGE_VAL;
        fchs
        fstp    temp.longdouble
        lea     ecx, temp
        jmp     short   log_complain

log_infinite:
        mov     edx, OVERFLOW
        mov     ecx, offset FLAT: _LHUGE_VAL
        jmp     short   log_complain

log_imaginary:
        mov     edx, DOMAIN
        mov     ecx, offset FLAT: NANLOGL

log_complain:
        FSTP    ST(0)                   ; pop x from stack

;       return  __matherrl (_EDX, "logl", &x, NULL, *(long double *)_ECX);

        matherrl edx, logl, x, NULL, [ecx]
        jmp     log_end

EndFunc@ logl

Code_EndS@
        end
