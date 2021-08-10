;[]-----------------------------------------------------------------[]
;|   EXPL.ASM -- exponential function                                |
;[]-----------------------------------------------------------------[]

;
;       C/C++ Run Time Library - Version 6.0
; 
;       Copyright (c) 1991, 1993 by Borland International
;       All Rights Reserved.
; 

;----------------------------------------------------------------------
; function(s)
;        ldexpl - calculates value * 2^exp (long double version)
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

ifdef MASM
zero            dw      0,0,0,0,0        ; was dt 0.0, but NT MASM386 blows up
else
zero            dt      0.0
endif

Data_EndS@

;--------------------------------------------------------------------------
;
;Name            ldexpl - calculates value * 2^exp
;
;Usage           long double ldexpl(long double value, int exp);
;
;Prototype in    math.h
;
;Description     ldexpl calculates value * 2^exp
;
;Return value    ldexpl returns value * 2^exp
;                Overflows return HUGE_VAL * sign(value), underflows return
;                0.0, in both cases with errno set to ERANGE.
;
;--------------------------------------------------------------------------
Code_Seg@

Func@   ldexpl, _EXPFUNC, _RTLENTRY, <longdouble value>,<int scale>
Locals@ <longdouble yVal>                   ; used in error exits

        Link@

        FILD    scale.w0

; While that is loading, we should check for range error.

        mov     ax, 7FFFh
        and     ax, value [8]

        FLD     value.longdouble
        jz      ldx_zero

        add     ax, scale
        jo      ldx_overflow            ; exponent too large
        jle     ldx_underflow           ; exponent zero or negative
        cmp     ax,7FFFH                ; exponent is INF
        je      ldx_overflow

        FSCALE
ldx_zero:
        fstp_st1                        ; remove the scale from the stack
ldx_end:
        Unlink@
        Return@

ldx_overflow:
        mov     edx, OVERFLOW
        mov     ecx, offset FLAT: _LHUGE_VAL
        jmp     short   ldx_err

ldx_underflow:
        mov     edx, UNDERFLOW
        mov     ecx, offset FLAT: zero

ldx_err:
        FSTP    st(0)                   ; pop value from stack
        FSTP    yVal.longdouble         ; yVal = scale


;       return  __matherrl (_EDX, "ldexpl", &value, &yVal,
;                (OVERFLOW == _EDX) ? _LHUGE_VAL : 0.0);

        matherrl edx, ldexpl, value, yVal, [ecx]
        jmp     short ldx_end

EndFunc@ ldexpl

Code_EndS@

        end
