;-----------------------------------------------------------------------
; filename - __memchr.asm
;
; function(s)
;
; jump stub for C++ implementation of memchr()
; jump stub for C++ implementation of _wmemchr()
;-----------------------------------------------------------------------

;
;       C/C++ Run Time Library - Version 8.0
; 
;       Copyright (c) 1987, 1997 by Borland International
;       All Rights Reserved.
; 
; $Revision:   8.5  $


        include RULES.ASI

;       Segments Definitions

Header@

ExtFunc@        memchr, _RTLENTRY
ExtFunc@      _wmemchr, _RTLENTRY

Code_seg@

Func@           @memchr$qpxviui, _EXPFUNC, pascal
                jmp     memchr@
EndFunc@        @memchr$qpxviui
Func@           @memchr$qpviui, _EXPFUNC, pascal
                jmp     memchr@
EndFunc@        @memchr$qpviui

Func@           @_wmemchr$qpxviui, _EXPFUNC, pascal
                jmp     _wmemchr@
EndFunc@        @_wmemchr$qpxviui
Func@           @_wmemchr$qpviui, _EXPFUNC, pascal
                jmp     _wmemchr@
EndFunc@        @_wmemchr$qpviui

Code_EndS@

end
