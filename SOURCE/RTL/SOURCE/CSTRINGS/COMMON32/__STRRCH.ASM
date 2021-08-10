;-----------------------------------------------------------------------
; filename - __strrch.asm
;
; function(s)
;
; jump stub for C++ implementation of strrchr()
;-----------------------------------------------------------------------

;
;       C/C++ Run Time Library - Version 8.0
; 
;       Copyright (c) 1987, 1997 by Borland International
;       All Rights Reserved.
; 
; $Revision:   8.3  $

        include RULES.ASI

;       Segments Definitions

Header@

ExtFunc@        strrchr, _RTLENTRY
        
Code_seg@

Func@           @strrchr$qpxci, _EXPFUNC, pascal
                jmp     strrchr@
EndFunc@        @strrchr$qpxci
Func@           @strrchr$qpci, _EXPFUNC, pascal
                jmp     strrchr@
EndFunc@        @strrchr$qpci

Code_EndS@

end
