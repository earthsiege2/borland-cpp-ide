;[]-----------------------------------------------------------------[]
;|   STRNCAT.ASM -- appends one string to another                     |
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
;Name           strncat - appends strings
;
;Usage          char *strncat(char *destin, const char *source, size_t maxlen);
;
;Prototype in   string.h
;
;Description    strncat copies at most maxlen characters of source to the end
;               of destin and then appends a null character. The maximum length
;               of the resulting string is strlen(destin) + maxlen.
;
;Return value   pointer to destin
;
;-----------------------------------------------------------------------

Code_seg@

Func@   strncat, _EXPFUNC, _RTLENTRYF, <pointer dest>, <pointer src>, <int maxlen>

        Link@   esi,edi
        mov     edi,dest        ; get dest string
        mov     edx,edi         ; save dest in edx
        mov     ecx,-1
        xor     al,al           ; search for null at end of source string
        cld
        repne   scasb           ; scan one character past null
        lea     esi,[edi-1]     ; esi points to terminating null in dest

        mov     edi,src         ; get src string
        mov     ecx,-1          ; figure out strlen(src)
        repne   scasb
        not     ecx             ; cx = strlen(src) + 1
        sub     edi,ecx         ; point edi back to start of src
        xchg    esi,edi         ; esi = src, edi = dest+strlen(dest)

        dec     ecx             ; don't count the null terminator
        mov     eax,maxlen      ; get maxlen
        cmp     ecx,eax         ; is strlen(src) <= maxlen?
        jbe     do_copy         ; yes, use strlen as count
        mov     ecx,eax         ; no, use maxlen as count
do_copy:
        mov     edx,ecx         ; save count
        shr     ecx,1           ; calculate longword count
        shr     ecx,1
        cld
        rep     movsd           ; copy longwords
        mov     ecx,edx         ; get back count
        and     ecx,3           ; calculate remainder byte count (0-3)
        rep     movsb           ; copy remaining bytes
        xor     al,al           ; store a null terminator
        stosb

        mov     eax, dest       ; return dest
        Unlink@ esi,edi
        Return@

EndFunc@ strncat

Code_EndS@

        end
