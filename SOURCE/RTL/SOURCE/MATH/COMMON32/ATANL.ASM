;[]-----------------------------------------------------------------[]
;|   ATANL.ASM -- trigonometric function                             |
;[]-----------------------------------------------------------------[]

;
;       C/C++ Run Time Library - Version 8.0
; 
;       Copyright (c) 1991, 1997 by Borland International
;       All Rights Reserved.
; 
; $Revision:   8.2  $

        include RULES.ASI
        include _MATH.INC

;       Segments Definitions

Header@

;----------------------------------------------------------------------
;
;Name            atanl - trigonometric function
;
;Usage           long double atanl(long double x);
;
;Prototype in    math.h
;
;Description     atanl returns the arc tangent  of the input value, which may
;                be any finite value.
;
;Return value    atanl returns a value in the range -pi/2 to pi/2.
;
;----------------------------------------------------------------------

Code_Seg@

Func@   atanl, _EXPFUNC, _RTLENTRY,       <longdouble x>

        Link@   ebx
        fld     x.longdouble
        f87     ArcTan
        Unlink@ ebx
        Return@

EndFunc@ atanl

Code_Ends@

        end
