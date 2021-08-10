;-----------------------------------------------------------------------
; filename - __strchr.asm
;
; function(s)
;
; jump stub for C++ implementation of strchr()
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

ExtFunc@        strchr, _RTLENTRY
        
Code_seg@

Func@           @strchr$qpxci, _EXPFUNC, pascal
                jmp     strchr@
EndFunc@        @strchr$qpxci
Func@           @strchr$qpci, _EXPFUNC, pascal
                jmp     strchr@
EndFunc@        @strchr$qpci

Code_EndS@

end


