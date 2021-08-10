;-----------------------------------------------------------------------
; filename - __strpbr.asm
;
; function(s)
;
; jump stub for C++ implementation of strpbrk()
;-----------------------------------------------------------------------

;
;       C/C++ Run Time Library - Version 8.0
; 
;       Copyright (c) 1987, 1997 by Borland International
;       All Rights Reserved.
; 
; $Revision:   8.4  $

        include RULES.ASI

;       Segments Definitions

Header@

ExtFunc@        strpbrk, _RTLENTRY
        
Code_seg@

Func@           @strpbrk$qpxct1, _EXPFUNC, pascal
                jmp     strpbrk@
EndFunc@        @strpbrk$qpxct1

Func@           @strpbrk$qpcpxc, _EXPFUNC, pascal
                jmp     strpbrk@
EndFunc@        @strpbrk$qpcpxc

Code_EndS@

end


