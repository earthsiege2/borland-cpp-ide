;[]-----------------------------------------------------------------[]
;|   COS.ASM -- trigonometric function                               |
;[]-----------------------------------------------------------------[]

;
;       C/C++ Run Time Library - Version 11.0
; 
;       Copyright (c) 1991, 2002 by Borland Software Corporation
;       All Rights Reserved.
; 

; $Revision: 9.4 $

;----------------------------------------------------------------------
; function(s)
;        cos - trigonometric function
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
;Name            cos - trigonometric function
;
;Usage           double cos(double x);
;
;Prototype in    math.h
;
;Description     cos  returns the  cosine of   the input  value. Angles  are
;                specified in radians.
;
;Return value    cos returns a value in the range -1 to 1.
;                For very  large arguments (magnitude 2^53  radians or more)
;                there  is no  precision. This  is "silent",  since the ANSI
;                spec allows no error return for this function.
;
;--------------------------------------------------------------------------

Code_Seg@

Func@   cos, _EXPFUNC, _RTLENTRY, <double x>

        Link@   ebx

        FLD     DOUBLE (x)

        mov     ax, 7FF0h
        and     ax, W0 (x [6])          ; extract the exponent field
        cmp     ax, (53 * 16) + 3FF0h   ; biased version of exponent 53
        jae     cos_tooLarge

        FCOS

cos_end:
        Unlink@ ebx
        Return@

cos_tooLarge:
        FSTP    ST(0)                   ; pop x from stack

;       return  __matherr (TLOSS, "cos", &x, NULL, *(double *) NANTRIG);

        matherr TLOSS, cos, x, NULL, NANTRIG
        jmp     cos_end

EndFunc@ cos

Code_EndS@

        end
