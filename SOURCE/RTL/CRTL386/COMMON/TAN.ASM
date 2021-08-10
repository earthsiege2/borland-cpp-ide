;[]-----------------------------------------------------------------[]
;|   TAN.ASM -- trigonometric function                               |
;[]-----------------------------------------------------------------[]

;
;       C/C++ Run Time Library - Version 6.0
; 
;       Copyright (c) 1991, 1993 by Borland International
;       All Rights Reserved.
; 

;----------------------------------------------------------------------
; function(s)
;        tan - trigonometric tangent function
;----------------------------------------------------------------------


        include RULES.ASI
        include _MATH.INC

;       Segments Definitions

Header@


Data_Seg@

NANTRIG dw      00000H, 00000H, 00420H, 07FF8H

Data_EndS@

;--------------------------------------------------------------------------
;
;Name            tan - trigonometric tangent function
;
;Usage           double tan(double x);
;
;Prototype in    math.h
;
;Description     tan  returns the  tangent of  the input  value. Angles  are
;                specified in radians.
;
;Return value    tan returns any value for valid angles.
;                For very  large arguments (magnitude  2^53 or greater)  all
;                precision is lost. This occurs  "silently" since the ANSI C
;                spec does  not specify an  error return.
;
;--------------------------------------------------------------------------


Code_Seg@

Func@   tan, _EXPFUNC, _RTLENTRY, <double x>

        Link@   ebx

        FLD     x.double

        mov     ax, 7FF0h
        and     ax, W0 (x [6])          ; extract the exponent field
        cmp     ax, (53 * 16) + 3FF0h   ; biased version of exponent 53
        jae     tan_tooLarge

        f87     Tangent
tan_end:
        Unlink@ ebx
        Return@

tan_tooLarge:                           ; total loss of precision
        FSTP    ST(0)                   ; pop x from stack

;       return  __matherr (TLOSS, "tan", &x, NULL, *((double *) NANTRIG));

        matherr TLOSS, tan, x, NULL, NANTRIG
        jmp     tan_end

EndFunc@ tan

Code_EndS@

        end
