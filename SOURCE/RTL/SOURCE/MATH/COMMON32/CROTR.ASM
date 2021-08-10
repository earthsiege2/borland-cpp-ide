;[]-----------------------------------------------------------------[]
;|   CROTR.ASM -- right rotate of unsigned char                      |
;[]-----------------------------------------------------------------[]

;
;       C/C++ Run Time Library - Version 8.0
; 
;       Copyright (c) 1991, 1997 by Borland International
;       All Rights Reserved.
; 
; $Revision:   8.2  $

        include RULES.ASI

;       Segments Definitions

Header@

;-----------------------------------------------------------------------
;
;Name           _crotr - rotates an unsigned char right
;
;Usage          unsigned char _crotr(unsigned char val, int rotate_count)
;
;Prototype in   stdlib.h
;
;Description    _crotr rotates an unsigned char value right rotate_count
;               bits.
;
;Return value   the value after rotation
;
;-----------------------------------------------------------------------

Code_seg@

Func@   _crotr, _EXPFUNC, _RTLENTRY, <char val>, <int rcount>

        movzx   eax, byte ptr [esp+4]   ; get char value and zero high bytes
        mov     ecx, [esp+8]            ; get rotate count
        ror     al,cl                   ; rotate the low byte
        Return@

EndFunc@ _crotr

Code_EndS@

        end
