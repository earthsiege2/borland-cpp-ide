;-----------------------------------------------------------------------
; filename - __strstr.asm
;
; function(s)
;
; jump stub for C++ implementation of strstr()
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

ExtFunc@        strstr, _RTLENTRY

Code_seg@

Func@           @std@strstr$qpxct1, public, pascal
                jmp     strstr@
EndFunc@        @std@strstr$qpxct1
Func@           @std@strstr$qpcpxc, public, pascal
                jmp     strstr@
EndFunc@        @std@strstr$qpcpxc

Code_EndS@

end
