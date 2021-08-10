;[]-----------------------------------------------------------------[]
;|   SQRTL.ASM -- long double square root function                   |
;[]-----------------------------------------------------------------[]

;
;       C/C++ Run Time Library - Version 1.5
; 
;       Copyright (c) 1991, 1994 by Borland International
;       All Rights Reserved.
; 

;----------------------------------------------------------------------
; function(s)
;        sqrtl - calculates square root (long double)
;----------------------------------------------------------------------

        include RULES.ASI
        include _MATH.INC

;       Segments Definitions

Header@

;----------------------------------------------------------------------
; External and local variables

Data_Seg@

NANSQRTL        dw      0,0,0,0C001H,07FFFH

Data_EndS@

;--------------------------------------------------------------------------
;
;Name            sqrtl - calculates square root of long double
;
;Usage           long double     sqrtl (long double  x);
;
;Prototype in    math.h
;
;Description     sqrtl calculates the square root of input value.
;
;Return value    sqrtl returns the square root of input value.
;                If the input value is less than 0, sqrtl returns 0 and sets
;                errno to
;                        EDOM    Domain error
;--------------------------------------------------------------------------

Code_Seg@

Func@   sqrtl, _EXPFUNC, _RTLENTRY, <longdouble x>

        Link@

        FLD     x.longdouble

        mov     ax, x [8]
        shl     ax, 1
        jz      sqrt_zero
        jc      sqrt_imaginary

        FSQRT

sqrt_zero:                      ; zero = sqrtl (zero)
sqrt_end:
        Unlink@
        Return@

sqrt_imaginary:
        FSTP    st (0)                  ; pop x from stack

;       return  __matherrl (DOMAIN, "sqrtl", &x, NULL, *((long double *) NANSQRTL));

        matherrl DOMAIN, sqrtl, x, NULL, NANSQRTL
        jmp     sqrt_end

EndFunc@ sqrtl

Code_Ends@
        end
