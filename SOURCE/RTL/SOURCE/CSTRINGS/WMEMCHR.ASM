;[]-----------------------------------------------------------------[]
;|   WMEMCHR.ASM -- search for a wide character                      |
;[]-----------------------------------------------------------------[]

;
;       C/C++ Run Time Library - Version 10.0
; 
;       Copyright (c) 1996, 2000 by Inprise Corporation
;       All Rights Reserved.
; 

; $Revision:   9.0  $

        include RULES.ASI

;       Segments Definitions

Header@

;-----------------------------------------------------------------------
;
;Name            _wmemchr - search for a wide character
;
;Usage           void *_wmemchr(const void *s, int val, size_t n);
;
;Prototype in    mem.h & string.h
;
;Description     _wmemchr scans up to n words at the memory location s
;                looking for a match to val.
;
;Return value    If  val  was matched then the  return value is a
;                pointer to the first matching position, otherwise it
;                is NULL.
;
;-----------------------------------------------------------------------

Code_seg@

Func@   _wmemchr, _EXPFUNC, _RTLENTRY, <pointer s>, <int val>, <int n>

        Link@   edi
        mov     edi, s
        mov     ecx, n
        jecxz   notfound
        mov     ax, val
        cld
        repne   scasw
        jne     notfound
        lea     eax,[edi-2]
return:
        Unlink@ edi
        Return@
notfound:
        xor     eax, eax        ; not found, return NULL
        jmp     return

EndFunc@ _wmemchr

Code_EndS@

        end