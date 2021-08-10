;-----------------------------------------------------------------------
; filename - __strrch.asm
;
; function(s)
;
; jump stub for C++ implementation of strrchr()
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

ExtFunc@        strrchr, _RTLENTRY

Code_seg@

Func@           @std@strrchr$qpxci, public, pascal
                jmp     strrchr@
EndFunc@        @std@strrchr$qpxci
Func@           @std@strrchr$qpci, public, pascal
                jmp     strrchr@
EndFunc@        @std@strrchr$qpci

Code_EndS@

end
