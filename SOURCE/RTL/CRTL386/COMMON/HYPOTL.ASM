;[]-----------------------------------------------------------------[]
;|   HYPOTL.ASM -- trigonometric function                            |
;[]-----------------------------------------------------------------[]

;
;       C/C++ Run Time Library - Version 6.0
; 
;       Copyright (c) 1991, 1993 by Borland International
;       All Rights Reserved.
; 

;----------------------------------------------------------------------
; function(s)
;        hypotl - calculates hypotenuse of right angle (long double)
;----------------------------------------------------------------------

        include RULES.ASI
        include _MATH.INC

;       Segments Definitions

Header@

;----------------------------------------------------------------------
; External variables

Data_Seg@

ExtSym@         _huge_ldble, tbyte, cdecl
_LHUGE_VAL      equ     _huge_ldble@

Data_EndS@

;-------------------------------------------------------------------------
;
;Name            hypotl - calculates hypotenuse of right angle
;
;Usage           long double hypotl(long double x, long double y);
;
;Prototype in    math.h
;
;Description     hypotl calculates the value z where
;                        z^2 = x^2 + y^2
;
;                This is  equivalent to the length of the  hypotenuse of a
;                right triangle, if the lengths of the two sides are x and
;                y.
;
;Return value    hypotl returns sqrt (x^2 + y^2).
;
;                On error (such as an overflow), hypotl returns the value
;                _LHUGE_VAL, and sets errno to
;                        ERANGE  Value out of range
;
;--------------------------------------------------------------------------

Code_Seg@

Func@   hypotl, _EXPFUNC, _RTLENTRY, <longdouble x>, <longdouble y>

        Link@

        FLD     x.longdouble
        mov     ax, x [8]               ; fetch exponent
        and     ax, 07fffh
        cmp     ax,1fffh+3fffh          ; exponent >= 1fffH (biased)?
        jae     hyp_infiniteX
        FMUL    st, st

        FLD     y.longdouble
        mov     ax, y [8]               ; fetch exponent
        and     ax, 07fffh
        cmp     ax,1fffh+3fffh          ; exponent >= 1fffH (biased)?
        jae     hyp_infiniteY
        FMUL    st, st

        FADD
        FSQRT

hyp_end:
        Unlink@
        Return@

hyp_infiniteY:
        FSTP    st(0)                   ; pop y off stack
hyp_infiniteX:
        FSTP    st(0)                   ; pop x off stack

;       return  __matherr (OVERFLOW, "hypotl", &x, &y, HUGE_VAL);

        matherrl OVERFLOW, hypotl, x, y, _LHUGE_VAL
        jmp     hyp_end

EndFunc@ hypotl

Code_EndS@
        end
