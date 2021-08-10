;-----------------------------------------------------------------------
; filename - __strpbr.asm
;
; function(s)
;
; jump stub for C++ implementation of strpbrk()
;-----------------------------------------------------------------------

;
;       C/C++ Run Time Library - Version 11.0
; 
;       Copyright (c) 1987, 2002 by Borland Software Corporation
;       All Rights Reserved.
; 

; $Revision: 9.6.2.1 $

        include RULES.ASI

;       Segments Definitions

Header@

ExtFunc@        strpbrk, _RTLENTRY

Code_seg@

Func@           @std@strpbrk$qpxct1, public, pascal
                jmp     strpbrk@
EndFunc@        @std@strpbrk$qpxct1

Func@           @std@strpbrk$qpcpxc, public, pascal
                jmp     strpbrk@
EndFunc@        @std@strpbrk$qpcpxc

Code_EndS@

end


