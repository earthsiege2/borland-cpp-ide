;[]-----------------------------------------------------------------[]
;|   EXP.ASM -- exponential function                                 |
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
;        exp - exponential function
;----------------------------------------------------------------------

        include RULES.ASI
        include _MATH.INC

;       Segments Definitions

Header@

;----------------------------------------------------------------------
; External and local variables

Data_Seg@

ExtSym@     _huge_dble, qword, cdecl
HUGE_VAL    equ _huge_dble@

ifdef MASM
zero        dw  0,0,0,0          ; was dq 0.0, but NT MASM386 blows up
else
zero        dq  0.0
endif

Data_EndS@

;--------------------------------------------------------------------------
;
;Name            exp - exponential function
;
;Usage           double exp(double x);
;
;Prototype in    math.h
;
;Description     exp calculates the exponent of x. For large exponents
;                (magnitude greater than or equal to 709) the result will be
;                an overflow to infinity or an underflow to zero.
;
;
;Return value    exp returns the exponent of x.  For large exponents
;                (magnitude greater than or equal to 709) the result will be
;                an overflow to infinity or an underflow to zero.
;
;--------------------------------------------------------------------------

Code_Seg@

Func@   exp, _EXPFUNC, _RTLENTRY, <double x>

        Link@   ebx

        FLD     x.double
        mov     ax, 7FFFh
        and     ax, x [6]       ; select exponent and most signif. bits
        cmp     ax, 4086h
        jnb     exp_tooBig      ; exp (+-709) is the limit for double

exp_justFits:

        f87     Exp
exp_end:
        Unlink@ ebx
        Return@

exp_tooBig:
        mov     ax, 0FFFFh      ; force extreme
        ja      exp_excess
        mov     ax, x [4]

exp_excess:
        test    BY0 (x [7]), 80h
        jnz     exp_tooTiny
        cmp     ax, 02E42h
        jb      exp_justFits
        mov     edx, OVERFLOW
        mov     ecx, offset FLAT: HUGE_VAL
        jmp     short   exp_err

exp_tooTiny:
        cmp     ax, 0232Bh
        jb      exp_justFits
        mov     edx, UNDERFLOW
        mov     ecx, offset FLAT: zero

exp_err:
        FSTP    ST(0)           ; discard ST

;       return  __matherr (_EDX, "exp", &x, NULL,
;                          (UNDERFLOW == _EDX) ? 0.0 : HUGE_VAL);

        matherr edx, exp, x, NULL, [ecx]
        jmp     short exp_end

EndFunc@ exp

Code_EndS@

        end
