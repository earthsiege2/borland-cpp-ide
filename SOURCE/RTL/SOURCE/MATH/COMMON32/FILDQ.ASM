;[]-----------------------------------------------------------------[]
;|   FILDQ.ASM -- convert quadword integer to long double            |
;[]-----------------------------------------------------------------[]

;
;       C/C++ Run Time Library - Version 1.5
; 
;       Copyright (c) 1991, 1994 by Borland International
;       All Rights Reserved.
; 

        include RULES.ASI

;       Segments Definitions

Header@

;-----------------------------------------------------------------------
;
;Name           _fildq - convert a quadword integer to a long double
;
;Usage          long double _fildq(long double *valP);
;
;Prototype in   _math.h
;
;Description    This is a helper function for scantod.c and bcd1.c.  It
;               converts the 64-bit integer pointed to by valP to a
;               long double.
;
;Return value   _fildq returns the converted value (i.e. leaves the
;               long double value on the top of the x87 stack).
;
;------------------------------------------------------------------------

Code_seg@

Func@ _fildq, public, _RTLENTRY, <pointer valP>

        mov     eax,[esp+4]             ; get pointer to quadword
        fild    qword ptr [eax]         ; convert the value, leave on TOS
        Return@

EndFunc@ _fildq

Code_EndS@

        end
