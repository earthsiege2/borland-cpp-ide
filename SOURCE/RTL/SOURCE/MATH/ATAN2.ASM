;[]-----------------------------------------------------------------[]
;|   ATAN2.ASM -- trigonometric function                                     |
;[]-----------------------------------------------------------------[]

;
;       C/C++ Run Time Library - Version 11.0
; 
;       Copyright (c) 1991, 2002 by Borland Software Corporation
;       All Rights Reserved.
; 

; $Revision: 9.4.2.1 $

        include RULES.ASI
        include _MATH.INC

;       Segments Definitions

Header@

Data_Seg@

piBy2           dw      0C235H, 02168H, 0DAA2H, 0C90FH, 03FFFH
NANINVTRIG      dw      00000H, 00000H, 00440H, 07FF8H

Data_EndS@

;--------------------------------------------------------------------------
;
;Name            atan2 - trigonometric function
;
;Usage           double atan2(double y, double x);
;
;Prototype in    math.h
;
;Description     atan2  returns the  arc tangent   of y/x  and will  produce
;                correct results even  when resulting is near pi/2  or -pi/2
;                (x near 0).
;
;Return value    atan2 returns a value in the range -pi to pi.
;                If a ratio of 0/0  is supplied then _RANGE_VAL is returned
;                and errno is set to:
;                        EDOM Domain error
;
;Caution: atan2(+0,-1) = +pi but atan2(-0,-1) = -pi.
;
;---------------------------------------------------------------------------

Code_Seg@

Func@   atan2, _EXPFUNC, _RTLENTRY, <double y>,<double x>

        Link@   ebx

        FLD     x.double
        mov     ax, x [6]               ; select MSW of x ..
        and     al, 0F0h                ; ignore fraction
        mov     bx, y [6]               ; .. and of y
        and     bl, 0F0h
        shl     bx, 1                   ; discard sign
        FLD     y.double
        jz      at2_yIsZero
        shl     ax, 1                   ; discard sign
        jz      at2_xIsZero
        cmp     ax, 0FFE0h
        jnb     at2_xIsInf
        cmp     bx, 0FFE0h
        jnb     at2_yIsInf

        FDIVRP  ST(1), ST(0)

        f87     ArcTan

; convert the simple answer to a four quadrant answer.

at2_setQuad:
        test    BY0 (x [7]), 80h        ; the sign bit
        jz      at2_end

        FLDPI

        test    BY0 (y [7]), 80h
        jz      at2_2ndQuad

at2_3rdQuad:
        FSUBP   ST(1), ST
        jmp     short   at2_end1

at2_2ndQuad:
        FADDP   ST(1), ST
        jmp     short   at2_end1


;      Special cases.

at2_yIsZero:
        rcl     cx, 1                   ; save sign of y = 0
        shl     ax, 1
        jz      at2_indeterminate       ; if both are zero
        jc      at2_retPi               ; x<0, return Pi
        fstp_st1                        ; else y is result
at2_end1:
        jmp     short   at2_end

at2_retPi:                              ; y = 0, x < 0
        FSTP    ST(0)                   ; discard x and y
        FSTP    ST(0)
        FLDPI                           ; and return PI
        shr     cx, 1                   ; was y +0 or -0 ?
        jnc     at2_end
        FCHS
        jmp     short at2_end

at2_xIsZero:                            ; and y is not zero
                                        ;      or
at2_yIsInf:                             ; and x is finite
        FSTP    ST(0)                   ; discard x and y
        FSTP    ST(0)
        FLD     tbyte ptr (piBy2)
        test    BY0 (y [7]), 80h        ; check sign of Y
        jz      at2_HPi                 ; positive - return PI/2
        FCHS                            ; negative - return -PI/2
at2_HPi:
        jmp     short   at2_end

at2_xIsInf:
        cmp     bx, 0FFE0h
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

;       return __matherr (DOMAIN, "atan2", &x, &y,  *((double *) NANINVTRIG));

        matherr DOMAIN, atan2, x, y, NANINVTRIG

at2_end:
        Unlink@ ebx
        Return@

EndFunc@ atan2

Code_Ends@

        end
