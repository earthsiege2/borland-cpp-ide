;[]-----------------------------------------------------------------[]
;|   FPRESET.ASM -- reset floating-point processor                   |
;[]-----------------------------------------------------------------[]

;
;       C/C++ Run Time Library - Version 11.0
; 
;       Copyright (c) 1991, 2002 by Borland Software Corporation
;       All Rights Reserved.
; 

; $Revision: 9.4 $

        include RULES.ASI

;       Segments Definitions

Header@

;----------------------------------------------------------------------
; External variables

Data_Seg@

ExtSym@     _default87, dword, cdecl    ; default x87 control word

Data_EndS@


;--------------------------------------------------------------------------
;
;Name           _fpreset - reinitializes floating point math package
;
;Usage          void _fpreset(void);
;
;Prototype in   float.h
;
;Description    _fpreset  reinitializes the   floating point  math package.
;               This function  is usually used in  conjunction with signal,
;               system, or the exec... or spawn... functions.
;
;Return value   No return value
;
;--------------------------------------------------------------------------

Code_seg@

ExtFunc@ _control87, _RTLENTRY, 8

Func@   _fpreset, _EXPFUNC, _RTLENTRY
Locals@ <int Control>

        fninit                          ; FNINIT causes all exceptions to
                                        ; be ignored, FINIT allows exceptions
                                        ; to occur.

        push    dword ptr 1fffh         ; control word mask
;Hack
        push    dword ptr _default87@   ; get default control word
        Call@   _control87              ; set new control word

        Return@

EndFunc@ _fpreset

Code_EndS@

        end
