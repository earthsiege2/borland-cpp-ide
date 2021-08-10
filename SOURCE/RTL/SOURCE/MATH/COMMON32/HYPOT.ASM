;[]-----------------------------------------------------------------[]
;|   HYPOT.ASM -- trigonometric function                             |
;[]-----------------------------------------------------------------[]

;
;       C/C++ Run Time Library - Version 1.5
; 
;       Copyright (c) 1991, 1994 by Borland International
;       All Rights Reserved.
; 

;----------------------------------------------------------------------
; function(s)
;        hypot - calculates hypotenuse of right angle
;----------------------------------------------------------------------

        include RULES.ASI
        include _MATH.INC

;       Segments Definitions

Header@

;----------------------------------------------------------------------
; External variables

Data_Seg@

ExtSym@         _huge_dble, qword, cdecl
HUGE_VAL        equ     _huge_dble@

Data_EndS@

;-------------------------------------------------------------------------
;
;Name            hypot - calculates hypotenuse of right angle
;
;Usage           double hypot(double x, double y);
;
;Prototype in    math.h
;
;Description     hypot calculates the value z where
;                        z^2 = x^2 + y^2
;
;                This is  equivalent to the length of the  hypotenuse of a
;                right triangle, if the lengths of the two sides are x and
;                y.
;
;Return value    hypot returns sqrt (x^2 + y^2);
;                On error (such as an overflow), hypot returns the value
;                HUGE_VAL, and sets errno to
;                        ERANGE  Value out of range
;
;--------------------------------------------------------------------------

Code_Seg@

Func@   hypot, _EXPFUNC, _RTLENTRY, <double x>, <double y>
Locals@ <int temp>

        Link@

        FLD     x.double
        mov     ax, x [6]
        FMUL    st, st                  ;      (z.x)^2
        shl     ax, 1
        cmp     ax, 0FFE0h
        jnb     hyp_infiniteX

        FLD     y.double
        mov     ax, y [6]
        FMUL    st, st                  ;               (z.y)^2
        shl     ax, 1
        cmp     ax, 0FFE0h
        jnb     hyp_infiniteY

        FADD                            ;       --"--  +  --"--
        FSQRT                           ; sqrt (               )
        FCOM    DOUBLE (HUGE_VAL)
        FSTSW   temp
        test    word ptr temp, 04500H
        jz      hyp_infiniteX           ; Result too large for double
hyp_end:
        Unlink@
        Return@

hyp_infiniteY:
        FSTP    st(0)                   ; pop y off stack
hyp_infiniteX:
        FSTP    st(0)                   ; pop x off stack

;       return  __matherr (OVERFLOW, "hypot", &x, &y, HUGE_VAL);

        matherr OVERFLOW, hypot, x, y, HUGE_VAL
        jmp     hyp_end

EndFunc@ hypot

Code_EndS@
        end

