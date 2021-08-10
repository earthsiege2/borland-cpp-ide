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
;        expl - exponential function
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
;Name            expl - exponential function
;
;Usage           long double expl(long double x);
;
;Prototype in    math.h
;
;Description    expl calculates the exponent of x. For large arguments
;               (absolute value greater than or equal to ~11356.5) the result
;               will be an overflow to infinity or an underflow to zero,
;               and __matherrl will be called.
;
;
;Return value   expl returns the exponent of x.   For large arguments
;               (absolute value greater than or equal to ~11356.5) the result
;               will be an overflow to infinity or an underflow to zero.
;
;--------------------------------------------------------------------------

Code_Seg@

ExtFunc@ _expld, _RTLENTRY, 0

Func@   expl, _EXPFUNC, _RTLENTRY, <double x>

        Link@   ebx

        FLD     x.longdouble
        mov     ax, x [8]       ; select exponent
        and     ah, 7Fh         ; remove sign bit
        cmp     ax, 3fffh+13
        jb      exp_OK          ; expl (+-2^13) is the limit for long double

exp_tooBig:
        mov     ax, 0FFFFh      ; force extreme
        ja      exp_excess
        mov     ax, x [6]

exp_excess:
        test    BY0 (x [9]), 80h
        jnz     exp_tooTiny
        cmp     ax, 0B172h
        jb      exp_OK
        mov     edx, OVERFLOW
        mov     ecx, offset FLAT: _LHUGE_VAL
        jmp     short   exp_err

exp_tooTiny:
        cmp     ax, 0B16Ch
        jb      exp_OK
        mov     edx, UNDERFLOW
        mov     ecx, offset FLAT: zero

exp_err:
        FSTP    ST(0)           ; discard ST

;       return  __matherrl (_EDX, "expl", &x, NULL,
;                          (UNDERFLOW == _EDX) ? 0.0 : _LHUGE_VAL);

        matherrl edx, expl, x, NULL, [ecx]
        jmp     short exp_end

exp_OK:
        Call@    _expld
exp_end:
        Unlink@ ebx
        Return@

EndFunc@ expl

Code_EndS@

        end
