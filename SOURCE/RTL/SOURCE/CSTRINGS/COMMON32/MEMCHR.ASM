;[]-----------------------------------------------------------------[]
;|   MEMCHR.ASM -- search for a character                            |
;[]-----------------------------------------------------------------[]

;
;       C/C++ Run Time Library - Version 1.5
; 
;       Copyright (c) 1991, 1994 by Borland International
;       All Rights Reserved.
; 

        include RULES.ASI

;       Segments Definitions

Header@

;-----------------------------------------------------------------------
;
;Name            memchr - search for a character
;
;Usage           void *memchr(const void *s, int val, size_t n);
;
;Prototype in    mem.h & string.h
;
;Description     memchr scans up to n bytes at the memory location s
;                looking for a match to val.
;
;Return value    If  val  was matched then the  return value is a
;                pointer to the first matching position, otherwise it
;                is NULL.
;
;-----------------------------------------------------------------------

Code_seg@

Func@   memchr, _EXPFUNC, _RTLENTRY, <pointer s>, <int val>, <int n>

        Link@   edi
        mov     edi, s
        mov     ecx, n
        jecxz   notfound
        mov     al, val
        cld
        repne   scasb
        jne     notfound
        lea     eax,[edi-1]
return:
        Unlink@ edi
        Return@
notfound:
        xor     eax, eax        ; not found, return NULL
        jmp     return

EndFunc@ memchr

Code_EndS@

        end
