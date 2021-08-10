;-----------------------------------------------------------------------
; filename - __memchr.asm
;
; function(s)
;
; jump stub for C++ implementation of memchr()
; jump stub for C++ implementation of _wmemchr()
;-----------------------------------------------------------------------

;
;       C/C++ Run Time Library - Version 10.0
; 
;       Copyright (c) 1987, 2000 by Inprise Corporation
;       All Rights Reserved.
; 

; $Revision:   9.2  $


        include RULES.ASI

;       Segments Definitions

Header@

ExtFunc@        memchr, _RTLENTRY
ExtFunc@      _wmemchr, _RTLENTRY

Code_seg@

Func@           @std@memchr$qpxviui, public, pascal
                jmp     memchr@
EndFunc@        @std@memchr$qpxviui
Func@           @std@memchr$qpviui, public, pascal
                jmp     memchr@
EndFunc@        @std@memchr$qpviui

Func@           @std@_wmemchr$qpxviui, public, pascal
                jmp     _wmemchr@
EndFunc@        @std@_wmemchr$qpxviui
Func@           @std@_wmemchr$qpviui, public, pascal
                jmp     _wmemchr@
EndFunc@        @std@_wmemchr$qpviui

Code_EndS@

end
