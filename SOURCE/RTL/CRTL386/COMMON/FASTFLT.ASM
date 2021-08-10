;[]-----------------------------------------------------------------[]
;|   FASTFLT.ASM
;[]-----------------------------------------------------------------[]

;
;       C/C++ Run Time Library - Version 6.0
; 
;       Copyright (c) 1992, 1993 by Borland International
;       All Rights Reserved.
; 

        include rules.asi

Header@

;----------------------------------------------------------------------
;
;Name            _FastFloat - initialize FPU for fast float calling convention
;
;Usage           void _FastFloat(void);
;
;Prototype in    none
;
;Description     When the fast floating point calling convention is
;                used, BCOS2 generates an external reference to
;                _FastFloat.  This function is run at startup, and
;                pushes three zeroes on the FPU stack.  This
;                prevents FPU stack exceptions in the first
;                function that preserves the FPU registers.
;
;Return value    none
;----------------------------------------------------------------------

Code_Seg@

Func@ _FastFloat, public, _RTLENTRY

; Load three zeros onto the FPU stack.

        fldz
        fldz
        fldz
        Return@

EndFunc@ _FastFloat

Code_EndS@

Init@   _FastFloat, 0, _RTLENTRY

        end
