;[]-----------------------------------------------------------------[]
;|   CLEAR87.ASM -- clear status word                                |
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
;        _clear87 - clears floating-point status word
;------------------------------------------------------------------------


        include RULES.ASI

;       Segments Definitions

Header@

;--------------------------------------------------------------------------
;
;Name           _clear87 - clears floating-point status word
;
;Usage          unsigned int _clear87(void);
;
;Prototype in   float.h
;
;Description    _clear87 clears the floating-point status word, which is a
;               combination of the 80x87 status word and other
;               conditions detected by the 80x87 exception handler.
;
;Return value   The bits in the value returned indicate the old floating-
;               point status. See float.h for a complete definition of the
;               bits returned by _clear87.
;
;--------------------------------------------------------------------------

Code_Seg@

Func@   _clear87, _EXPFUNC, _RTLENTRY

Locals@ <word Status>

; get the chip status

        Link@
        FNSTSW   Status.W0

; clear the chip

        FNCLEX

; return the status word in bits 0-15, zero out bits 16-31

        movzx   eax,Status.W0
        Unlink@
        Return@

EndFunc@ _clear87

Code_EndS@

        end
