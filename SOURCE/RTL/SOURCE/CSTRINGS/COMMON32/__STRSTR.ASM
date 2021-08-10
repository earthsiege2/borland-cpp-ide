;-----------------------------------------------------------------------
; filename - __strstr.asm
;
; function(s)
;
; jump stub for C++ implementation of strstr()
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

ExtFunc@        strstr, _RTLENTRY
        
Code_seg@

Func@           @strstr$qpxct1, _EXPFUNC, pascal
                jmp     strstr@
EndFunc@        @strstr$qpxct1
Func@           @strstr$qpcpxc, _EXPFUNC, pascal
                jmp     strstr@
EndFunc@        @strstr$qpcpxc

Code_EndS@

end
