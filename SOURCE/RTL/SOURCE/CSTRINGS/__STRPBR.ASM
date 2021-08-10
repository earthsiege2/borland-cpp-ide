;-----------------------------------------------------------------------
; filename - __strpbr.asm
;
; function(s)
;
; jump stub for C++ implementation of strpbrk()
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


