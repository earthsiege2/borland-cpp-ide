;[]-----------------------------------------------------------------[]
;|   TANL.ASM -- long double trigonometric function                                  |
;[]-----------------------------------------------------------------[]

;
;       C/C++ Run Time Library - Version 8.0
; 
;       Copyright (c) 1991, 1997 by Borland International
;       All Rights Reserved.
; 
; $Revision:   8.2  $

;----------------------------------------------------------------------
; function(s)
;        tanl - long double trigonometric tangent function
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
;Name            tanl - trigonometric tangent function
;
;Usage           long double tanl(long double x);
;
;Prototype in    math.h
;
;Description     tanl  returns the  tangent of  the input  value. Angles are
;                specified in radians.
;
;Return value    tanl returns any value for valid angles.
;                For very  large arguments (magnitude 2^63 or greater) all
;                precision is lost. This occurs  "silently" since the ANSI C
;                spec does  not specify an  error return.
;
;--------------------------------------------------------------------------

Code_Seg@

Func@   tanl, _EXPFUNC, _RTLENTRY, <longdouble x>

        Link@   ebx

        FLD     x.longdouble

        mov     ax, 7FFFh
        and     ax, W0 (x [8])          ; extract the exponent field
        cmp     ax, 63 + 3FFFh          ; biased version of exponent 63
        jae     tan_tooLarge

        f87     Tangent
tan_end:
        Unlink@ ebx
        Return@

tan_tooLarge:                           ; total loss of precision
        FSTP    ST(0)                   ; pop x from stack

;       return  __matherrl (TLOSS, "tanl", &x, NULL, *((long double *) NANTRIGL));

        matherrl TLOSS, tanl, x, NULL, NANTRIGL
        jmp     tan_end

EndFunc@ tanl

Code_EndS@

        end
