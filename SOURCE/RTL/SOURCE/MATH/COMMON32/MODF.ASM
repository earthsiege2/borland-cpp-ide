;[]-----------------------------------------------------------------[]
;|   MODF.ASM -- split a floating point value                        |
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
;        modf - splits into mantissa and exponent
;----------------------------------------------------------------------

        include RULES.ASI
        include _MATH.INC

;       Segments Definitions

Header@

;--------------------------------------------------------------------------
;
;Name            modf - splits into mantissa and exponent
;
;Usage           double  modf(double value, double *wholeP);
;
;Prototype in    math.h
;
;Description     modf breaks  the double value into two parts: the integer
;                and  the fraction.  It stores the integer in wholeP and
;                returns the fraction.
;
;Return value    modf returns the fractional part of value.
;
;--------------------------------------------------------------------------

Code_Seg@

ExtFunc@ _round, _RTLENTRY, 0

Func@   modf, _EXPFUNC, _RTLENTRY, <double value>, <pointer wholeP>

        Link@   ebx

        FLD     value.double

        mov     ax, value [6]
        shl     ax, 1
        cmp     ax, 0FFE0h              ; infinite exponent ?
        jnb     mdf_infinite

        FLD     st(0)                   ; duplicate ST

        mov     ch, 0Ch                 ; chop towards zero
        Call@   _round                  ; _round() modifies the '87 TOS

        mov     ebx, wholeP
        FST     [ebx].double            ; *wholeP = chop (value)

        FSUBP   st(1), st               ; fraction = value - chop(value)

mdf_end:
        Unlink@ ebx
        Return@

mdf_infinite:                           ; infinity == rounded (infinity)
        mov     ebx, wholeP
        FSTP    [ebx].double
        FLDZ                            ; zero = infinity - infinity
        jmp     short   mdf_end

EndFunc@ modf

Code_EndS@
        end
