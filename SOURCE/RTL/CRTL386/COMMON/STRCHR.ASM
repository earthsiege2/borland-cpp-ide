;[]-----------------------------------------------------------------[]
;|   STRCHR.ASM -- scans a string for the first occurrence of a      |
;[]-----------------------------------------------------------------[]

;
;       C/C++ Run Time Library - Version 6.0
; 
;       Copyright (c) 1991, 1993 by Borland International
;       All Rights Reserved.
; 

        include RULES.ASI

;       Segments Definitions

Header@

;-----------------------------------------------------------------------
;
;Name            strchr - scans a string for the first occurrence of a
;                         given character
;
;Usage           char *strchr(const char *str, int c);
;
;Prototype in    string.h
;
;Description     strchr scans a string in the forward direction, looking for a
;                specific character. strchr finds the first occurrence of the
;                character ch in the string str.
;
;                The null-terminator is considered
;                to be part of the string, so that, for example
;
;                        strchr(strs, 0)
;
;                returns a pointer to the terminating null character of the
;                string "strs".
;
;Return value    strchr  returns a pointer to the first occurrence of the
;                character ch in str; if ch does not occur in str, strchr
;                returns NULL.
;
;-----------------------------------------------------------------------

Code_seg@

Func@   strchr, _EXPFUNC, _RTLENTRYF, <pointer strng>, <int c>

        Link@   edi
        mov     edi,strng       ; get source string
        mov     edx,edi         ; save in edx
        mov     ecx,-1
        xor     al,al           ; search for null at end of source string
        cld
        repne   scasb           ; scan one character past null
        not     ecx             ; ecx = no. of characters including null
        mov     edi,edx         ; get destination buffer back
        mov     al,c            ; get char to search for
        repne   scasb           ; search for it
        jne     notfound        ; didn't find it
        lea     eax,[edi-1]     ; back up pointer to found character
return:
        Unlink@ edi
        Return@
notfound:
        xor     eax, eax        ; not found, return NULL
        jmp     return

EndFunc@ strchr
Code_EndS@

        end
