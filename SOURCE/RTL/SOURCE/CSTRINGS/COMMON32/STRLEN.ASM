;[]-----------------------------------------------------------------[]
;|   STRLEN.ASM -- search for a character                            |
;[]-----------------------------------------------------------------[]

;
;       C/C++ Run Time Library - Version 2.0
; 
;       Copyright (c) 1991, 1996 by Borland International
;       All Rights Reserved.
; 

        include RULES.ASI

;       Segments Definitions

Header@

;-----------------------------------------------------------------------
;
;Name            strlen - calculates the length of a string
;
;Usage           size_t strlen(const char *str);
;
;Prototype in    string.h
;
;Description     returns the length of a null terminated string
;
;-----------------------------------------------------------------------

Code_seg@

Func@   strlen, _EXPFUNC, _RTLENTRYF, <pointer s>

        Link@   edi
        mov     edi, s
        mov     ecx, -1
        xor     al, al          ; search for null
        cld
        repne   scasb           ; scan one character past null
        not     ecx
        lea     eax, [ecx-1]
        Unlink@ edi
        Return@

EndFunc@ strlen

Code_EndS@

        end
