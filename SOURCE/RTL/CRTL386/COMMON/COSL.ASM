;[]-----------------------------------------------------------------[]
;|   COSL.ASM -- trigonometric function                              |
;[]-----------------------------------------------------------------[]

;
;       C/C++ Run Time Library - Version 6.0
; 
;       Copyright (c) 1991, 1993 by Borland International
;       All Rights Reserved.
; 

;----------------------------------------------------------------------
; function(s)
;        cosl - trigonometric function
;----------------------------------------------------------------------


        include RULES.ASI
        include _MATH.INC

;       Segments Definitions

Header@


Data_Seg@

NANTRIGL        dw      00000H, 00000H,  00000H, 0C021H, 07FFFH

Data_EndS@

;--------------------------------------------------------------------------
;
;Name            cosl - trigonometric function
;
;Usage           long double cosl(long double x);
;
;Prototype in    math.h
;
;Description     cosl  returns the cosine of the long double input value.
;                Angles are  specified in radians.
;
;Return value    cosl returns a value in the range -1 to 1.
;                For very  large arguments (magnitude 2^63  radians or more)
;                there  is no  precision. This  is "silent",  since the ANSI
;                spec allows no error return for this function.
;
;--------------------------------------------------------------------------

Code_Seg@

Func@   cosl, _EXPFUNC, _RTLENTRY, <longdouble x>

        Link@   ebx

        FLD     LONGDOUBLE (x)

        mov     ax, 7FFFh
        and     ax, W0 (x [8])          ; extract the exponent field
        cmp     ax, 63 + 3FFFh          ; biased version of exponent 53
        jae     cosl_tooLarge

        f87     Cosine

cosl_end:
        Unlink@ ebx
        Return@

cosl_tooLarge:
        FSTP    ST(0)                   ; pop x from stack

;       return  __matherrl (TLOSS, "cosl", &x, NULL, *(long double *) NANTRIGL);

        matherr TLOSS, cosl, x, NULL, NANTRIGL
        jmp     cosl_end

EndFunc@ cosl

Code_EndS@

        end
