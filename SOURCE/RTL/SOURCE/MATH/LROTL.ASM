;[]-----------------------------------------------------------------[]
;|   LROTL.ASM -- left rotate of unsigned long                       |
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

;-----------------------------------------------------------------------
;
;Name           _lrotl - rotates an unsigned long left
;
;Usage          unsigned long _lrotl(unsigned long val, int rotate_count)
;
;Prototype in   stdlib.h
;
;Description    _lrotl rotates an unsigned long integer val left
;               rotate_count bits.
;
;Return value   the value after rotation
;
;-----------------------------------------------------------------------

Code_seg@

Func@   _lrotl, _EXPFUNC, _RTLENTRY, <long val>, <int rcount>

        mov     eax, [esp+4]        ; get value
        mov     ecx, [esp+8]        ; get rotate count
        rol     eax,cl              ; rotate the value
        Return@

EndFunc@ _lrotl

Code_EndS@

        end
