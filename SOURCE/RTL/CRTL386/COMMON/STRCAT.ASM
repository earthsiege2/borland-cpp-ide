;[]-----------------------------------------------------------------[]
;|   STRCAT.ASM -- appends one string to another                     |
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
;Name            strcat - appends one string to another
;
;Usage           char *strcat(char *dest, const char *src);
;
;Prototype in    string.h
;
;Description     strcat appends a copy of src to the end of dest. The
;                length of the resulting string is strlen(dest) +
;                strlen(src).
;
;Return value    returns a pointer dest
;
;-----------------------------------------------------------------------

Code_seg@

Func@   strcat, _EXPFUNC, _RTLENTRYF, <pointer dest>, <pointer src>

        Link@   esi,edi
        mov     edi,dest        ; get dest string
        mov     ecx,-1
        xor     al,al           ; search for null at end of dest string
        cld
        repne   scasb           ; scan one character past null
        lea     esi,[edi-1]     ; esi points to terminating null in dest

        mov     edi,src         ; get src string
        mov     ecx,-1          ; figure out strlen(src)
        repne   scasb
        not     ecx             ; cx = strlen(src) + 1
        sub     edi,ecx         ; point edi back to start of src
        xchg    esi,edi         ; esi = src, edi = dest+strlen(dest)

        mov     edx,ecx         ; save count
        shr     ecx,1           ; calculate longword count
        shr     ecx,1
        cld
        rep     movsd           ; copy longwords
        mov     ecx,edx         ; get back count
        and     ecx,3           ; calculate remainder byte count (0-3)
        rep     movsb           ; copy remaining bytes

        mov     eax, dest       ; return dest
        Unlink@ esi,edi
        Return@

EndFunc@ strcat

Code_EndS@

        end
