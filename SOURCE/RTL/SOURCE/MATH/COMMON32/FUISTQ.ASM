;[]-----------------------------------------------------------------[]
;|   FUISTQ.ASM -- convert long double to unsigned quadword integer  |
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
;Name           _fuistq - convert long double to unsigned quadword integer
;
;Usage          void _fuistq(long * quadint, long double *valP);
;
;Prototype in   _math.h
;
;Description    This is a helper function for xcvt.c.  It converts the
;               long double pointed to by valP to an unsigned 64-bit
;               integer, storing the result at *quadint.
;
;Return value   none
;
;------------------------------------------------------------------------

Code_seg@

Func@ _fuistq, public, _RTLENTRY, <pointer quadint>, <pointer valP>

        mov     eax,[esp+4]             ; get pointer to quadword
        mov     edx,[esp+8]             ; get pointer to long double
        cmp     word ptr [edx+8], 403Eh ; is 2^63 <= number < 2^64 ?
        je      toobig                  ; handle this specially
        fld     tbyte ptr [edx]         ; load the long double
        fistp   qword ptr [eax]         ; convert the value, store at quadword
        fwait
        Return@

; The fuistq instruction treats numbers as signed, which means it can't
; handle numbers >= 2^63.  So for numbers where the exponent is exactly
; 63, we can cheat by simply copying the mantissa to the quadword integer,
; because it's already aligned correctly.

toobig:
        mov     ecx, [edx]              ; copy low 32 bits of mantissa
        mov     [eax], ecx
        mov     ecx, [edx+4]            ; copy high 32 bits of mantissa
        mov     [eax+4], ecx
        Return@

EndFunc@ _fuistq

Code_EndS@

        end
