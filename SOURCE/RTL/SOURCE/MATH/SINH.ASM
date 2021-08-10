;[]-----------------------------------------------------------------[]
;|   SINH.ASM -- hyperbolic sine function                            |
;[]-----------------------------------------------------------------[]

;
;       C/C++ Run Time Library - Version 10.0
; 
;       Copyright (c) 1991, 2000 by Inprise Corporation
;       All Rights Reserved.
; 

; $Revision:   9.0  $

;----------------------------------------------------------------------
; function(s)
;        sinh - hyperbolic sine function
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

Data_EndS@

;--------------------------------------------------------------------------
;
;Name            sinh - hyperbolic sine function
;
;Usage           double sinh(double x);
;
;Prototype in    math.h
;
;Description     sinh computes the hyperbolic sine of the input value.
;
;Return value    sinh returns the hyperbolic sine of the input value.
;                For large arguments (magnitude greater than or equal to
;                710.475) the result will be an EDOM error.
;
;--------------------------------------------------------------------------

;Algorithm.
;
;The usual formula is:
;        sinh(x) = .5*(exp(x) - exp(-x))
;but there is a loss of precision in using this formula directly near 0.
;
;Since sinh(-x) = -sinh(x), compute sinh(|x|) and adjust the sign later.
;
;If 0 <= x < 2^-33, return x.
;
;If x >= 710.475 call matherr.
;
;If x >= .3465, use
;        y = exp(x)
;        sinh(x) = (y - 1/y)/2
;
;If 2^-33 <= x < .3465, use
;        y = exp(x) - 1
;        sinh(x) = (y + y/(1 + y))/2
;where special chip functions are used to get exp(x)-1 accurately.


Code_Seg@

Func@   sinh, _EXPFUNC, _RTLENTRY, <double x>
Locals@ <double temp>

        Link@   ebx

        FLD1
        mov     ax, 7FFFh
        FCHS                    ; TOS = -1.0, used in FSCALE later
        mov     dx, x [6]
        and     ax, dx          ; select exponent and most signif. bits

        FLD     x.double
        cmp     ax, 4086h
        jnb     sinh_tooBig     ; exp (+-710.475) is the limit

        FABS
        cmp     ax, 3FD6h
        jb      sinh_small

sinh_justFits:
        f87     Exp

        FLD1
        FDIV    st, st(1)       ; Exp (-x)
        FSUBP   st(1), st
        FSCALE                  ; sinh (x) = (exp(x) - exp(-x)) / 2

sinh_end:
        fstp_st1                ; discard the -1

; change sign if original argument was negative

        test    dh, 80h
        jz      sinh_end2
        FCHS
sinh_end2:
        Unlink@ ebx
        Return@

sinh_tooBig:
        ja      sinh_over
        cmp     W0 (x [4]), 33CEh
        jb      sinh_justFits

sinh_over:
        FSTP    ST(0)                   ; discard ST and ST(1)
        FSTP    ST(0)

;       return  __matherr (OVERFLOW, "sinh", &x, NULL,
;                                                (_DX & 0x8000) ? - HUGE_VAL : HUGE_VAL);

        FLD     HUGE_VAL.double
        test    dh, 80H
        jz      sinh_temp
        FCHS
sinh_temp:
        FSTP    temp.double

        matherr OVERFLOW, sinh, x, NULL, temp
        jmp     sinh_end2

sinh_small:
        cmp     ax, 3DE0h
        jb      sinh_end                ; x tiny, return x

        FLDL2E
        FMUL
        F2XM1
; TOS = y = exp(x) - 1
        FLD1
        FADD    st(0),st(1)
; stack = 1+y,y,-1
        FDIVR   st(0),st(1)
        FADD
        FSCALE
        jmp     sinh_end;

EndFunc@ sinh

Code_EndS@
        end

