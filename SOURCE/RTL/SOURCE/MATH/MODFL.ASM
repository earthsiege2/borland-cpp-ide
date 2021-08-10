;[]-----------------------------------------------------------------[]
;|   MODFL.ASM -- split a floating point value                       |
;[]-----------------------------------------------------------------[]

;
;       C/C++ Run Time Library - Version 10.0
; 
;       Copyright (c) 1991, 2000 by Inprise Corporation
;       All Rights Reserved.
; 

; $Revision:   9.0  $

;----------------------------------------------------------------------
; function(s)
;        modfl - splits a long double into mantissa and exponent
;----------------------------------------------------------------------

        include RULES.ASI
        include _MATH.INC

;       Segments Definitions

Header@

;--------------------------------------------------------------------------
;
;Name            modfl - splits long double into mantissa and exponent
;
;Usage           long double  modfl(long double value, long double *wholeP);
;
;Prototype in    math.h
;
;Description     modfl breaks  the long double value into two parts: the integer
;                and  the fraction.  It stores the integer in wholeP and
;                returns the fraction.
;
;Return value    modfl returns the fractional part of value.
;
;--------------------------------------------------------------------------

Code_Seg@

ExtFunc@ _round, _RTLENTRY, 0

Func@   modfl, _EXPFUNC, _RTLENTRY, <longdouble value>, <pointer wholeP>

        Link@   ebx

        FLD     value.longdouble

        mov     ax, value [8]
        shl     ax, 1
        cmp     ax, 0FFFEh              ; infinite exponent ?
        jnb     mdf_infinite

        FLD     st(0)                   ; duplicate ST

        mov     ch, 0Ch                 ; chop towards zero
        Call@   _round                  ; _round() modifies the '87 TOS

        FSUB    st(1), st               ; fraction = value - chop(value)
        mov     ebx, wholeP
        FSTP    [ebx].longdouble        ; *wholeP = chop (value)

mdf_end:
        Unlink@ ebx
        Return@

mdf_infinite:                           ; infinity == rounded (infinity)
        mov     ebx, wholeP
        FSTP    [ebx].longdouble
        FLDZ                            ; zero = infinity - infinity
        jmp     short   mdf_end

EndFunc@ modfl

Code_EndS@
        end
