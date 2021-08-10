;[]-----------------------------------------------------------------[]
;|   WCSCHR.ASM -- scans a wide-character string for the first      |
;|                 occurrence of a given wide-character             |
;[]-----------------------------------------------------------------[]

;
;       C/C++ Run Time Library - Version 8.0
; 
;       Copyright (c) 1996, 1997 by Borland International
;       All Rights Reserved.
; 
; $Revision:   8.1  $

        include RULES.ASI

;       Segments Definitions

Header@

;-----------------------------------------------------------------------
;
;Name            wcschr - scans a string for the first occurrence
;                         of a given wide-character
;
;Usage           wchar_t *wcschr(const wchar_t *str, int c);
;
;Prototype in    string.h
;
;Description     wcschr scans a string in the forward direction, looking for a
;                specific wide-character. wcschr finds the first occurrence of
;		 the wide-character ch in the wide-character string str.
;
;                The null-terminator is considered to be part of the string, so
;		 that, for example
;
;                        wcschr(strs, 0)
;
;                returns a pointer to the terminating null character of the
;                string "strs".
;
;Return value    wcschr returns a pointer to the first occurrence of the
;                character ch in str; if ch does not occur in str, wcschr
;                returns NULL.
;
;-----------------------------------------------------------------------

Code_seg@

Func@   wcschr, _EXPFUNC, _RTLENTRYF, <pointer strng>, <int c>
	
	Link@   edi
        mov     edi,strng       ; get source string
        mov     edx,edi         ; save in edx
        mov     ecx,-1
        xor     ax,ax           ; search for null byte/word at end of source string
	cld
        repne   scasw           ; scan one wide-character past null
	not     ecx             ; ecx = no. of characters including null
        mov     edi,edx         ; get destination buffer back
        mov     ax,c            ; get byte/wide-character to search for
        repne   scasw           ; search for it
        jne     notfound        ; didn't find it
        lea     eax,[edi-2]     ; back up pointer to found character
return:
        Unlink@ edi
        Return@
notfound:
        xor     eax, eax        ; not found, return NULL
        jmp     return

EndFunc@ wcschr

Code_EndS@

	end

