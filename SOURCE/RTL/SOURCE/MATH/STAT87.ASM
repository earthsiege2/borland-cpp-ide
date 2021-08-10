;[]-----------------------------------------------------------------[]
;|   STAT87.ASM -- access floating-point status word                 |
;[]-----------------------------------------------------------------[]

;
;       C/C++ Run Time Library - Version 11.0
; 
;       Copyright (c) 1991, 2002 by Borland Software Corporation
;       All Rights Reserved.
; 

; $Revision: 9.3 $

        include RULES.ASI

;       Segments Definitions

Header@

;--------------------------------------------------------------------------
;
;Name            _status87 - gets floating-point status
;
;Usage           unsigned int _status87(void);
;
;Prototype in    float.h
;
;Description     _status87 gets the floating-point status word, which is a
;                combination of the 80x87 status word and other
;                conditions detected by the 80x87 exception handler.
;
;Return value    The bits in the return value give the floating-point
;                status.  See <float.h> for a complete definition of the bits
;                returned by _status87.
;
;--------------------------------------------------------------------------

Code_seg@

Func@   _status87, _EXPFUNC, _RTLENTRY
Locals@ <int Status>            ; volatile unsigned int Status;

        Link@

        fstsw   Status.w0
        fwait
        movzx   eax, Status.w0

        Unlink@
        Return@

EndFunc@ _status87

Code_EndS@

        end
