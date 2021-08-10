;[]-----------------------------------------------------------------[]
;|   LDEXP.ASM -- calculate 2^x                                      |
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
;        ldexp - calculates value * 2^exp
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

ifdef MASM
zero            dw      0,0,0,0          ; was dq 0.0, but NT MASM386 blows up
else
zero            dq      0.0
endif

Data_EndS@

;--------------------------------------------------------------------------
;
;Name           ldexp - calculates value * 2^exp
;
;Usage          double ldexp(double value, int exp);
;
;Prototype in   math.h
;
;Description    ldexp calculates value * 2^exp
;
;Return value   ldexp returns value * 2^exp
;               Overflows return HUGE_VAL * sign(value), underflows return
;               0.0, in both cases with errno set to ERANGE.
;
;--------------------------------------------------------------------------

Code_Seg@

Func@   ldexp, _EXPFUNC, _RTLENTRY, <double value>,<int scale>
Locals@ <double yVal>               ; used in error exits

        Link@   ebx

        FILD    scale.w0

;  While that is loading, we should check for range error.

        mov     ax, 7FF0h
        and     ax, value [6]
        mov     cl, 4
        ror     ax, cl

        FLD     value.double
        jz      ldx_zero

        mov     bx, scale
        cmp     bh, 7h
        jg      ldx_overflow
        cmp     bh, -7h
        jl      ldx_overflow

        add     ax, bx
        jng     ldx_underflow
        cmp     ax, 7FFh
        jnl     ldx_overflow

        FSCALE
ldx_zero:
        fstp_st1                        ; remove the scale from the stack

ldx_end:
        Unlink@ ebx
        Return@


ldx_overflow:
        mov     edx, OVERFLOW
        mov     ecx, offset FLAT: HUGE_VAL
        jmp     short   ldx_err


ldx_underflow:
        mov     edx, UNDERFLOW
        mov     ecx, offset FLAT: zero

ldx_err:
        FSTP    st(0)                   ; pop value from stack
        FSTP    yVal.double             ; yVal = scale

;       return  __matherr (_EDX, "ldexp", &value, &yVal,
;               (OVERFLOW == _EDX) ? HUGE_VAL : 0.0);

        matherr edx, ldexp, value, yVal, [ecx]
        jmp     short   ldx_end

EndFunc@ ldexp

Code_EndS@

        end
