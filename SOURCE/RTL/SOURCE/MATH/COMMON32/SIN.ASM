;[]-----------------------------------------------------------------[]
;|   SIN.ASM -- trigonometric function                               |
;[]-----------------------------------------------------------------[]

;
;       C/C++ Run Time Library - Version 1.5
; 
;       Copyright (c) 1991, 1994 by Borland International
;       All Rights Reserved.
; 

;----------------------------------------------------------------------
; function(s)
;        sin - trigonometric function
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
;Name            sin - trigonometric sine function
;
;Usage           double sin(double x);
;
;Prototype in    math.h
;
;Description     sin  returns  the  sine  of  the  input  value.  Angles are
;                specified in radians.
;
;Return value    sin returns a value in range -1 to 1.
;                For very  large arguments (magnitude 2^53  radians or more)
;                there  is no  precision. This  is "silent",  since the ANSI
;                spec allows no error return for this function.
;
;--------------------------------------------------------------------------

Code_Seg@

Func@   sin, _EXPFUNC, _RTLENTRY, <double x>

        Link@   ebx

        FLD     x.double

        mov     ax, 7FF0h
        and     ax, W0 (x [6])          ; extract the exponent field
        cmp     ax, (53 * 16) + 3FF0h   ; biased version of exponent 53
        jae     sin_tooLarge

        f87     Sine

sin_end:
        Unlink@ ebx
        Return@

sin_tooLarge:
        FSTP    ST (0)                  ; pop x from stack

;       return  __matherr (TLOSS, "sin", &x, NULL, *((double *) NANTRIG));

        matherr TLOSS, sin, x, NULL, NANTRIG
        jmp     sin_end

EndFunc@ sin

Code_EndS@

        end
