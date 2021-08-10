;[]-----------------------------------------------------------------[]
;|   SINHL.ASM -- hyperbolic sine function                           |
;[]-----------------------------------------------------------------[]

;
;       C/C++ Run Time Library - Version 1.5
; 
;       Copyright (c) 1991, 1994 by Borland International
;       All Rights Reserved.
; 

;----------------------------------------------------------------------
; function(s)
;        sinhl - long double hyperbolic sine function
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

Data_EndS@

;--------------------------------------------------------------------------
;
;Name            sinhl - long double hyperbolic sine function
;
;Usage           long double sinhl(long double x);
;
;Prototype in    math.h
;
;Description     sinhl computes the hyperbolic sine of the input value.
;
;Return value    sinhl returns the hyperbolic sine of the input value.
;                For  large arguments  (absolute value greater  than
;                ~11356.5) the result  will be  _LHUGE_VAL of
;                the appropriate sign and errno will be set to:
;                        ERANGE  Range error.
;
;--------------------------------------------------------------------------

;Algorithm.
;
;The usual formula is:
;        sinh(x) = .5*(expl(x) - expl(-x))
;but there is a loss of precision in using this formula directly near 0.
;
;Since sinh(-x) = -sinh(x), compute sinh(|x|) and adjust the sign later.
;
;If 0 <= x < 2^-33, return x.
;
;If x >= 11356.5 call matherr.
;
;If x >= .3465, use
;        y = expl(x)
;        sinh(x) = (y - 1/y)/2
;
;If 2^-33 <= x < .3465, use
;        y = expl(x) - 1
;        sinh(x) = (y + y/(1 + y))/2
;where special chip functions are used to get exp(x)-1 accurately.


Code_Seg@

ExtFunc@ _expld, _RTLENTRY, 0

Func@   sinhl, _EXPFUNC, _RTLENTRY, <longdouble x>
Locals@ <longdouble temp>

        Link@   ebx

        FLD1
        mov     ax, 7FFFh
        FCHS                    ; TOS = -1.0, used in FSCALE later
        mov     dx, x [8]
        and     ax, dx          ; select exponent

        FLD     x.longdouble
        cmp     ax, 3fffh+13    ; 2^13 is near the limit
        jae     sinh_tooBig

        FABS
        cmp     ax, 3FFDh       ; compare with .3465
        jb      jb_sinh_small  ; avoid "jmp out of range" error
        ja      sinh_justFits
        cmp     W0 (x [6]), 0B168h
jb_sinh_small:
        jb      sinh_small

sinh_justFits:
        Call@   _expld

        FLD1
        FDIV    st, st(1)       ; Exp (-x)
        FSUBP   st(1), st
        FSCALE                  ; sinhl (x) = (expl(x) - expl(-x)) / 2

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
        cmp     W0 (x [6]), 0B172h
        jb      sinh_justFits

sinh_over:
        FSTP    ST(0)                   ; discard ST and ST(1)
        FSTP    ST(0)

;       return  __matherrl (OVERFLOW, "sinhl", &x, NULL,
;                          (_DX & 0x8000) ? - _LHUGE_VAL : _LHUGE_VAL);

        FLD     _LHUGE_VAL.longdouble
        test    dh, 80H
        jz      sinh_temp
        FCHS
sinh_temp:
        FSTP    temp.longdouble

        matherrl OVERFLOW, sinhl, x, NULL, temp
        jmp     sinh_end2

sinh_small:
        cmp     ax, 3fffh-33            ; x less than 2^-33 ?
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

EndFunc@ sinhl

Code_EndS@
        end

