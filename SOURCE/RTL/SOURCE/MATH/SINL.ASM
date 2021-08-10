;[]-----------------------------------------------------------------[]
;|   SINL.ASM -- long double trigonometric function                  |
;[]-----------------------------------------------------------------[]

;
;       C/C++ Run Time Library - Version 10.0
; 
;       Copyright (c) 1991, 2000 by Inprise Corporation
;       All Rights Reserved.
; 

; $Revision:   9.1  $

;----------------------------------------------------------------------
; function(s)
;        sinl - long double trigonometric function
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
;Name            sinl - long double trigonometric sine function
;
;Usage           long double sinl(long double x);
;
;Prototype in    math.h
;
;Description     sinl  returns  the  sine  of  the  input  value.  Angles are
;                specified in radians.
;
;Return value    sinl returns a value in range -1 to 1.
;                For very  large arguments (magnitude 2^63  radians or more)
;                there  is no  precision. This  is "silent",  sinlce the ANSI
;                spec allows no error return for this function.
;
;--------------------------------------------------------------------------

Code_Seg@

Func@   sinl, _EXPFUNC, _RTLENTRY, <longdouble x>

        Link@   ebx

        FLD     x.longdouble

        mov     ax, 7FFFh
        and     ax, W0 (x [8])          ; extract the exponent field
        cmp     ax, 63 + 3FFFh          ; biased version of exponent 63
        jae     sin_tooLarge

        FSIN

sin_end:
        Unlink@ ebx
        Return@

sin_tooLarge:
        FSTP    ST (0)                  ; pop x from stack

;       return  __matherrl (TLOSS, "sinl", &x, NULL, *((long double *) NANTRIGL));

        matherrl TLOSS, sinl, x, NULL, NANTRIGL
        jmp     sin_end

EndFunc@ sinl

Code_EndS@

        end
