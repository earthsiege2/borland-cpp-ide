;[]-----------------------------------------------------------------[]
;|   CROTL.ASM -- left rotate of unsigned char                       |
;[]-----------------------------------------------------------------[]

;
;       C/C++ Run Time Library - Version 6.5
; 
;       Copyright (c) 1991, 1994 by Borland International
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

if LPROG
VALUE   equ     4
COUNT   equ     6
else
VALUE   equ     2
COUNT   equ     4
endif

Code_seg@

PubProc@   _crotl, __CDECL__
        mov     bx, sp
        mov     al, byte ptr SS_ [bx+VALUE]     ; get char value
        xor     ah, ah                          ; zero high byte
        mov     cx, SS_ [bx+COUNT]              ; get rotate count
        rol     al,cl                           ; rotate the low byte
        ret
EndProc@ _crotl

Code_EndS@

        end
