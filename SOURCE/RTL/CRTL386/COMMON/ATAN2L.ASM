;[]-----------------------------------------------------------------[]
;|   ATAN2L.ASM -- trigonometric function                            |
;[]-----------------------------------------------------------------[]

;
;       C/C++ Run Time Library - Version 6.0
; 
;       Copyright (c) 1991, 1993 by Borland International
;       All Rights Reserved.
; 

        include RULES.ASI
        include _MATH.INC

;       Segments Definitions

Header@


Data_Seg@

piBy2           dw      0C235H, 02168H, 0DAA2H, 0C90FH, 03FFFH
NANINVTRIG      dw      00000H, 00000H, 00000H, 0C022H, 07FFFH

Data_EndS@

;--------------------------------------------------------------------------
;
;Name            atan2l - trigonometric function
;
;Usage           long double atan2l(long double y, long double x);
;
;Prototype in    math.h
;
;Description     atan2l  returns the  arc tangent   of y/x  and will  produce
;                correct results even  when resulting is near pi/2  or -pi/2
;                (x near 0).
;
;Return value    atan2l returns a value in the range -pi to pi.
;                If a ratio of 0/0  is supplied then _RANGE_VAL is returned
;                and errno is set to:
;                        EDOM Domain error
;
;Caution: atan2l(+0,-1) = +pi but atan2l(-0,-1) = -pi.
;
;---------------------------------------------------------------------------

Code_Seg@

Func@   atan2l, _EXPFUNC, _RTLENTRY, <longdouble y>, <longdouble x>

        Link@   ebx

        FLD     x.longdouble
        mov     ax, x [8]               ; select MSW of x ..
        mov     bx, y [8]               ; .. and of y
        shl     bx, 1                   ; discard sign
        FLD     y.longdouble
        jz      at2_yIsZero
        shl     ax, 1                   ; discard sign
        jz      at2_xIsZero
        cmp     ax, 0FFFEh
        jnb     at2_xIsInf
        cmp     bx, 0FFFEh
        jnb     at2_yIsInf

        FDIVRP  ST(1), ST(0)

        f87     ArcTan

; convert the simple answer to a four quadrant answer.

at2_setQuad:
        test    BY0 (x [9]), 80h        ; the sign bit
        jz      at2_end

        FLDPI

        test    BY0 (y [9]), 80h
        jz      at2_2ndQuad

at2_3rdQuad:
        FSUBP   ST(1), ST
        jmp     short   jmp_at2_end

at2_2ndQuad:
        FADDP   ST(1), ST
        jmp     short   jmp_at2_end


;      Special cases.

at2_yIsZero:
        rcl     cx, 1                   ; save sign of y = 0
        shl     ax, 1
        jz      at2_indeterminate       ; if both are zero
        jc      at2_retPi               ; x<0, return Pi
        fstp_st1                        ; else y is result
        jmp     short   at2_end

at2_retPi:                              ; y = 0, x < 0
        FSTP    ST(0)                   ; discard x and y
        FSTP    ST(0)
        FLDPI                           ; and return PI
        shr     cx, 1                   ; was y +0 or -0 ?
        jnc     at2_end
        FCHS
jmp_at2_end:
        jmp     short at2_end

at2_xIsZero:                            ; and y is not zero
                                        ;      or
at2_yIsInf:                             ; and x is finite
        FSTP    ST(0)                   ; discard x and y
        FSTP    ST(0)
        FLD     tbyte ptr (piBy2)
        test    BY0 (y [9]), 80h        ; check sign of Y
        jz      at2_HPi                 ; positive - return PI/2
        FCHS                            ; negative - return -PI/2
at2_HPi:
        jmp     short   at2_end

at2_xIsInf:
        cmp     bx, 0FFFEh
        jnb     at2_indeterminate       ; if both are infinite
        FSTP    ST(0)                   ; discard x and y
        FSTP    ST(0)
        FLDZ
        jmp     short   at2_setQuad

;  There are two cases considered irresolvable: both operands zero, or
;  both operands infinite.

at2_indeterminate:                      ; either equal or both infinite
        FSTP    ST(0)                   ; discard x and y
        FSTP    ST(0)

;       return __matherrl (DOMAIN, "atan2l", &x, &y,  *((long double *) NANINVTRIG));

        matherrl DOMAIN, atan2l, x, y, NANINVTRIG

at2_end:
        Unlink@ ebx
        Return@

EndFunc@ atan2l

Code_Ends@

        end
