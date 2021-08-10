;[]-----------------------------------------------------------------[]
;|   CROTR.ASM -- right rotate of unsigned char                      |
;[]-----------------------------------------------------------------[]

;
;       C/C++ Run Time Library - Version 7.0
; 
;       Copyright (c) 1991, 1996 by Borland International
;       All Rights Reserved.
; 

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

if LPROG
VALUE   equ     4
COUNT   equ     6
else
VALUE   equ     2
COUNT   equ     4
endif

Code_seg@

PubProc@   _crotr, __CDECL__
        mov     bx, sp
        mov     al, byte ptr SS_ [bx+VALUE]     ; get char value
        xor     ah, ah                          ; zero high byte
        mov     cx, SS_ [bx+COUNT]              ; get rotate count
        ror     al,cl                           ; rotate the low byte
        ret
EndProc@ _crotr

Code_EndS@

        end
