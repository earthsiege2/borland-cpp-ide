;[]-----------------------------------------------------------------[]
;|   COSHL.ASM -- trigonometric function                     |
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
;        coshl - hyperbolic function
;----------------------------------------------------------------------

        include RULES.ASI
    include _MATH.INC

;       Segments Definitions

Header@


;----------------------------------------------------------------------
; External and local variables

Data_Seg@

ExtSym@     _huge_ldble, tbyte, cdecl
_LHUGE_VAL  equ _huge_ldble@

ifdef MASM
zero        dw  0,0,0,0,0        ; was dt 0.0, but NT MASM386 blows up
else
zero        dt  0.0
endif

Data_EndS@

;--------------------------------------------------------------------------
;
;Name            coshl - hyperbolic function
;
;Usage           long double coshl(long double x);
;
;Prototype in    math.h
;
;Description     coshl computes the hyperbolic cosine of the input value.
;
;Return value    coshl returns the hyperbolic cosine of the input value.
;                For  large arguments (absolute value greater than
;                ~11356.5) the result  will be  _LHUGE_VAL of the appropriate
;                sign and errno will be set to:
;                        ERANGE  Range error.
;
;--------------------------------------------------------------------------

Code_Seg@

ExtFunc@ _expld, _RTLENTRY, 0

Func@   coshl, _EXPFUNC, _RTLENTRY, <longdouble x>

        Link@   ebx

        FLD1
        mov     ax, 7FFFh
        FCHS                    ; TOS = -1.0, used in FSCALE later
        and     ax, x [8]       ; select exponent

        FLD     LONGDOUBLE (x)
        cmp     ax, 3fffh+13
        jae     coshl_tooBig    ; exp (+-2^13) considered too large
        cmp     ax, 3fffh-13
        jb      coshl_tiny

coshl_justFits:
        Call@    _expld         ; TOS = expl(x)

        FLD1
        FDIV    st, st(1)       ; TOS = expl (-x) = 1 / expl(x)
        FADDP   st(1), st       ; TOS = expl(x) + expl(-x)
        FSCALE                  ; coshl (x) = (expl(x) + expl(-x)) / 2
        fstp_st1

coshl_end:
        Unlink@ ebx
        Return@

coshl_tooBig:
        mov     ax, 0FFFFh      ; force extreme
        ja      coshl_excess
        mov     ax, x [6]

coshl_excess:
        test    BY0 (x [9]), 80h
        jnz     coshl_tooTiny
        cmp     ax, 0B172h
        jb      coshl_justFits
        mov     edx, OVERFLOW
        mov     ecx, offset FLAT: _LHUGE_VAL
        jmp     short   coshl_err

coshl_tooTiny:
        cmp     ax, 0B16Ch
        jb      coshl_justFits
        mov     edx, UNDERFLOW
        mov     ecx, offset FLAT: zero

coshl_err:
        FSTP    ST(0)                   ; pop two items off the stack
        FSTP    ST(0)

;       return  __matherrl (_EDX, "coshl", &x, NULL,
;                          (UNDERFLOW == _EDX) ? 0.0 : _LHUGE_VAL);

        matherrl edx, coshl, x, NULL, [ecx]
        jmp short   coshl_end

;  coshl is more accurately calculated by the polynomial
;
;       (1 + x^2/2)
;
;  when x is tiny (|x| < 2^-13).

coshl_tiny:
        FMUL    ST(0), ST(0)
        FSCALE                  ; divide by 2
        FSUBRP  ST(1), ST(0)    ; +1 == - (-1)
        jmp     short   coshl_end

EndFunc@ coshl
Code_EndS@
        end
