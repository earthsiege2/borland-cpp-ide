;[]-----------------------------------------------------------------[]
;|   TANH.ASM -- hyperbolic tangent function                         |
;[]-----------------------------------------------------------------[]

;
;       C/C++ Run Time Library - Version 1.5
; 
;       Copyright (c) 1991, 1994 by Borland International
;       All Rights Reserved.
; 

;----------------------------------------------------------------------
; function(s)
;        tanh - hyperbolic tangent function
;----------------------------------------------------------------------

        include RULES.ASI
        include _MATH.INC

;       Segments Definitions

Header@

;--------------------------------------------------------------------------
;
;Name            tanh - hyperbolic tangent function
;
;Usage           double tanh(double x);
;
;Prototype in    math.h
;
;Description     tanh calculates the hyperbolic tangent of the input.
;
;Return value    tanh returns the hyperbolic tangent of the input value.
;                For large arguments (magnitude greater than 32) the result
;                will be +1.0 or -1.0.
;
;-------------------------------------------------------------------------

;Algorithm.
;
;The usual formula is:
;        tanh(x) = (exp(x) - exp(-x))/(exp(x) + exp(-x))/
;but there is a loss of precision in using this formula directly near 0.
;
;Since tanh(-x) = -tanh(x), compute tanh(|x|) and adjust the sign later.
;
;If 0 <= x < 2^-33, return x.
;
;If x >= 32 return 1.
;
;If x >= .17325, use
;        y = exp(x)
;        tanh(x) = (y - 1/y)/(y + 1/y)
;
;If 2^-33 <= x < .17325, use
;        y = exp(2x) - 1
;        sinh(x) = y/(2 + y)
;where special chip functions are used to get exp(2x)-1 accurately.


Code_Seg@

Func@   tanh, _EXPFUNC, _RTLENTRY, <double x>

        Link@   ebx

        FLD     x.double
        sub     dh, dh
        mov     cx, x [6]
        shl     cx, 1
        rcr     dh, 1                   ; DH = sign
        cmp     cx, 8080h
        FABS
        ja      tanh_extreme

        cmp     cx, 7F8Ch
        jb      tanh_small

        f87     Exp

        FLD1
        FDIV    st, st(1)               ; Exp (-x)

; tanh = sinh / cosh = (exp(x) - exp(-x)) / (exp(x) + exp(-x))

        FLD     st(1)
        FSUB    st, st(1)
        FXCH
        FADD    st, st(2)
        FDIVP   st(1), st
        fstp_st1

tanh_end:
        or      dh, dh
        jns     tanh_end2
        FCHS
tanh_end2:
        Unlink@ ebx
        Return@

; tanh is asymptotic to -1 for negative arguments and +1 for positives.
; It approaches very fast, with exponentially increasing accuracy,
; so it is 1.0 for IEEE accuracy when |x| > 23.

tanh_extreme:
        FSTP    st(0)           ; pop stack
        FLD1
        jmp     tanh_end

tanh_small:
        cmp     cx, 7BC0h
        jb      tanh_end
        FLD1
        FXCH
        FSCALE

        FLDL2E
        FMUL
        F2XM1
; TOS = y = exp(2x) - 1
        FXCH
        FLD1
        FADD
        FADD    st(0),st(1)
; stack = 2+y,y
        FDIV
        jmp     tanh_end

EndFunc@ tanh

Code_EndS@
        end

