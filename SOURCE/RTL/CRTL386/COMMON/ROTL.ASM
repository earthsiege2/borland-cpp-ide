;[]-----------------------------------------------------------------[]
;|   ROTL.ASM -- left rotate of unsigned short                       |
;[]-----------------------------------------------------------------[]

;
;       C/C++ Run Time Library - Version 6.0
; 
;       Copyright (c) 1991, 1993 by Borland International
;       All Rights Reserved.
; 

        include RULES.ASI

;       Segments Definitions

Header@

;-----------------------------------------------------------------------
;
;Name           _rotl - rotates an unsigned short left
;
;Usage          unsigned short _rotl(unsigned short val, int rotate_count)
;
;Prototype in   stdlib.h
;
;Description    _rotl rotates an unsigned integer val left rotate_count
;               bits.
;
;Return value   the value after rotation
;
;-----------------------------------------------------------------------

Code_seg@

Func@   _rotl, _EXPFUNC, _RTLENTRY, <short val>, <int rcount>

        movzx   eax, word ptr [esp+4]   ; get short value and zero high word
        mov     ecx, [esp+8]            ; get rotate count
        rol     ax,cl                   ; rotate the low word
        Return@

EndFunc@ _rotl

Code_EndS@

        end
