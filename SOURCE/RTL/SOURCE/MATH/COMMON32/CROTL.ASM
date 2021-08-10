;[]-----------------------------------------------------------------[]
;|   CROTL.ASM -- left rotate of unsigned char                       |
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
;Name           _crotl - rotates an unsigned char left
;
;Usage          unsigned char _crotl(unsigned char val, int rotate_count)
;
;Prototype in   stdlib.h
;
;Description    _crotl rotates an unsigned char value left rotate_count
;               bits.
;
;Return value   the value after rotation
;
;-----------------------------------------------------------------------

Code_seg@

Func@   _crotl, _EXPFUNC, _RTLENTRY, <short val>, <int rcount>

        movzx   eax, byte ptr [esp+4]   ; get char value and zero high bytes
        mov     ecx, [esp+8]            ; get rotate count
        rol     al,cl                   ; rotate the low byte
        Return@

EndFunc@ _crotl

Code_EndS@

        end
