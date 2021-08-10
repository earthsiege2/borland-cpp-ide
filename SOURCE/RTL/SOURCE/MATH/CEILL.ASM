;[]-----------------------------------------------------------------[]
;|   CEILL.ASM -- rounding function                                  |
;[]-----------------------------------------------------------------[]

;
;       C/C++ Run Time Library - Version 10.0
; 
;       Copyright (c) 1991, 2000 by Inprise Corporation
;       All Rights Reserved.
; 

; $Revision:   9.0  $

;------------------------------------------------------------------------
; function(s)
;    ceill - rounds up
;------------------------------------------------------------------------


        include RULES.ASI

;       Segments Definitions

Header@

;--------------------------------------------------------------------------
;
;Name            ceill - rounds up
;
;Usage           long double ceill(long double x);
;
;Prototype in    math.h
;
;Description     ceill finds the smallest integer not less than x.
;
;Return value    ceill returns the integer found as a long double.
;---------------------------------------------------------------------------

Code_Seg@

ExtFunc@ _round, _RTLENTRY, 0

Func@   ceill, _EXPFUNC, _RTLENTRY, <longdouble x>

        Link@

        FLD     LONGDOUBLE (x)

        mov     ax, x [8]
        and     ax, 7FFFh
        cmp     ax, 3FFFh + 64  ; 2^64, maximum long double precision
        ja      dlm_beyond

        mov     ch, 08          ; iNDP-87 control bits for ceiling mode
        Call@   _round          ; _round() modifies the '87 TOS

dlm_beyond:                     ; magnitudes beyond 2^64 have no fraction
        Unlink@
        Return@

EndFunc@ ceill

Code_EndS@

        end
