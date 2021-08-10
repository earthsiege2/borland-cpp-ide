;[]-----------------------------------------------------------------[]
;|   SQRT.ASM -- square root function                                |
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
;        sqrt - calculates square root
;----------------------------------------------------------------------

        include RULES.ASI
        include _MATH.INC

;       Segments Definitions

Header@

;----------------------------------------------------------------------
; External and local variables

Data_Seg@

NANSQRT         dw      0,0,0020H, 07FF8H

Data_EndS@

;--------------------------------------------------------------------------
;
;Name           sqrt - calculates square root
;
;Usage          double  sqrt (double  x);
;
;Prototype in   math.h
;
;Description    sqrt calculates the square root of input value.
;
;Return value   sqrt returns the square root of input value.
;               If the input  value is lees than 0, sqrt  returns 0 and set
;               errno to
;                       EDOM    Domain error
;---------------------------------------------------------------------------

Code_Seg@

Func@   sqrt, _EXPFUNC, _RTLENTRY, <double x>

        Link@

        FLD     x.double

        mov     ax, x [6]
        shl     ax, 1
        jz      sqrt_zero
        jc      sqrt_imaginary

        FSQRT

sqrt_zero:                      ; zero = sqrt (zero)
sqrt_end:
        Unlink@
        Return@

sqrt_imaginary:
        FSTP    st (0)                  ; pop x from stack

;       return  __matherr (DOMAIN, "sqrt", &x, NULL, *((double *) NANSQRT));

        matherr DOMAIN, sqrt, x, NULL, NANSQRT
        jmp     sqrt_end

EndFunc@ sqrt

Code_Ends@
        end
