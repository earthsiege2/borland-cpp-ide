;[]-----------------------------------------------------------------[]
;|   FISTQ.ASM -- convert long double to quadword integer            |
;[]-----------------------------------------------------------------[]

;
;       C/C++ Run Time Library - Version 2.0
; 
;       Copyright (c) 1991, 1996 by Borland International
;       All Rights Reserved.
; 

        include RULES.ASI

;       Segments Definitions

Header@

;-----------------------------------------------------------------------
;
;Name           _fistq - convert a long double to a quadword integer
;
;Usage          void _fistq(long * quadint, long double *valP);
;
;Prototype in   _math.h
;
;Description    This is a helper function for bcd1.c.  It converts the
;               long double pointed to by valP to a 64-bit integer,
;               storing the result at *quadint.
;
;Return value   none
;
;------------------------------------------------------------------------

Code_seg@

Func@ _fistq, public, _RTLENTRY, <pointer quadint>, <pointer valP>

        mov     eax,[esp+4]             ; get pointer to quadword
        mov     edx,[esp+8]             ; get pointer to long double
        fld     tbyte ptr [edx]         ; load the long double
        fistp   qword ptr [eax]         ; convert the value, store at quadword
        Return@

EndFunc@ _fistq

Code_EndS@

        end
