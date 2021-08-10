;[]-----------------------------------------------------------------[]
;|   MEMSET.ASM --  sets memory to value                             |
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
;Name            memset - sets memory to value
;
;Usage           void *memset(void *src, int c, size_t n);
;
;Prototype in    mem.h
;
;Description     sets the n bytes of the block pointed to by src to
;                c.
;
;Return value    src
;
;-----------------------------------------------------------------------

Code_seg@

Func@   memset, _EXPFUNC, _RTLENTRYF, <pointer src>,<int c>,<int n>

        Link@   edi
        mov     edi,src         ; get src
        mov     al,c            ; get byte to store
        mov     ah,al           ; copy to ah
        mov     dx,ax
        shl     eax,16          ; mov to upper word
        mov     ax,dx           ; get back lower word
        mov     ecx,n
        mov     edx,ecx         ; save count
        shr     ecx,1           ; calculate longword count
        shr     ecx,1
        cld
        rep     stosd           ; store longwords
        mov     ecx,edx         ; get back count
        and     ecx,3           ; calculate remainder byte count (0-3)
        rep     stosb           ; store remaining bytes
        mov     eax,src         ; return src
        Unlink@ edi
        Return@

EndFunc@ memset

Code_EndS@

        end
