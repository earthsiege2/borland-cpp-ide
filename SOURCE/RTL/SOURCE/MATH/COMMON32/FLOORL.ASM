;[]-----------------------------------------------------------------[]
;|   FLOORL.ASM -- rounding function                                 |
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
;        floorl - rounds down a long double
;----------------------------------------------------------------------

        include RULES.ASI
        include _MATH.INC

;       Segments Definitions

Header@

;--------------------------------------------------------------------------
;
;Name            floorl - rounds down a long double
;
;Usage           long double floorl(long double x);
;
;Prototype in    math.h
;
;Description     floorl finds the largest integer not greater than x.
;
;Return value    floorl returns the integer found as a long double.
;
;--------------------------------------------------------------------------

Code_Seg@

ExtFunc@ _round, _RTLENTRY, 0

Func@   floorl, _EXPFUNC, _RTLENTRY, <longdouble x>

        Link@

        FLD     x.longdouble

        mov     ax, x [8]
        and     ax, 7FFFh
        cmp     ax, 3FFFh + 64  ; 2^64, maximum long double precision
        ja      dlm_beyond

        mov     ch, 04          ; iNDP-87 control bits for floor mode
        Call@   _round          ; _round() modifies the '87 TOS

dlm_beyond:                     ; magnitudes beyond 2^64 have no fraction
dlm_end:
        Unlink@                 ; return (result on TOS)
        Return@

EndFunc@ floorl

Code_EndS@
        end
