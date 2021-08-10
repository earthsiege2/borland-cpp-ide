;[]-----------------------------------------------------------------[]
;|   FBSTP.ASM -- convert long double to 10-byte BCD                 |
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
;Name           _fbstp - convert long double to 10-byte BCD
;
;Usage          void _fbstp(long double *valP);
;
;Prototype in   _math.h
;
;Description    This is a helper function for __xcvt().  It converts
;               the long double value pointed to by valP to a 10-byte
;               packed BCD value, overwriting the original value.
;               The conversion is actually performed by an FBSTP
;               instruction.
;
;Return value   No value is returned.  The converted value is
;               written back over the original value.
;
;------------------------------------------------------------------------

Code_seg@

Func@ _fbstp, public, _RTLENTRY, <pointer valP>

        mov     eax,[esp+4]             ; get pointer to long double value
        fld     tbyte ptr [eax]         ; load the value
        frndint                         ; FBSTP doesn't round properly
        fbstp   tbyte ptr [eax]         ; store BCD number
        fwait                           ; wait for conversion to finish
        Return@

EndFunc@ _fbstp

Code_EndS@

        end
