;-----------------------------------------------------------------------
; filename - __strchr.asm
;
; function(s)
;
; jump stub for C++ implementation of strchr()
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

ExtFunc@        strchr, _RTLENTRY

Code_seg@

Func@           @std@strchr$qpxci, public, pascal
                jmp     strchr@
EndFunc@        @std@strchr$qpxci
Func@           @std@strchr$qpci, public, pascal
                jmp     strchr@
EndFunc@        @std@strchr$qpci

Code_EndS@

end


