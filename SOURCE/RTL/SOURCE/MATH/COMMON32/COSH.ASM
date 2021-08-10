;[]-----------------------------------------------------------------[]
;|   COSH.ASM -- trigonometric function                              |
;[]-----------------------------------------------------------------[]

;
;       C/C++ Run Time Library - Version 2.0
; 
;       Copyright (c) 1991, 1996 by Borland International
;       All Rights Reserved.
; 

;----------------------------------------------------------------------
; function(s)
;        cosh - hyperbolic function
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

;--------------------------------------------------------------------------
;
;Name            cosh - hyperbolic function
;
;Usage           double cosh(double x);
;
;Prototype in    math.h
;
;Description     cosh computes the hyperbolic cosine of the input value.
;
;Return value    cosh returns the hyperbolic cosine of the input value.
;                For  large arguments  (magnitude greater  than or  equal to
;                710.475)  the result  will be  HUGE_VAL of  the appropriate
;                sign and errno will be set to:
;                        ERANGE  Range error.
;
;--------------------------------------------------------------------------

Code_Seg@
Func@   cosh, _EXPFUNC, _RTLENTRY, <double x>

        Link@   ebx

        FLD1
        mov     ax, 7FFFh
        FCHS                    ; TOS = -1.0
        and     ax, x [6]       ; select exponent and most signif. bits

        FLD     DOUBLE (x)
        cmp     ax, 4086h
        jnb     cosh_tooBig     ; exp (+-710.475) considered too large
        cmp     ax, 3F20h
        jb      cosh_tiny
cosh_justFits:

        f87     Exp

        FLD1
        FDIV    st, st(1)       ; Exp (-x)
        FADDP   st(1), st
        FSCALE                  ; cosh (x) = (exp(x) + exp(-x)) / 2
        fstp_st1

cosh_end:
        Unlink@ ebx
        Return@

cosh_tooBig:
        ja      cosh_over
        cmp     W0 (x [4]), 033CEh
        jb      cosh_justFits

cosh_over:

        FSTP    ST(0)                   ; pop two items off the stack
        FSTP    ST(0)

;       return __matherr (OVERFLOW, "cosh", &x, NULL, HUGE_VAL);

        matherr OVERFLOW, cosh, x, NULL, HUGE_VAL
        jmp     short   cosh_end

;  cosh is more accurately calculated by the polynomial
;
;        (1 + x^2/2)
;
;  when x is tiny (|x| < 2^-13).

cosh_tiny:
        FMUL    ST(0), ST(0)
        FSCALE                  ; divide by 2
        FSUBRP  ST(1), ST(0)    ; +1 == - (-1)
        jmp     short   cosh_end

EndFunc@ cosh
Code_EndS@
        end
