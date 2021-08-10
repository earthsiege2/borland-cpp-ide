;[]-----------------------------------------------------------------[]
;|   MEMCPY.ASM --  copy a block of n bytes from src to dst          |
;[]-----------------------------------------------------------------[]

;
;       C/C++ Run Time Library - Version 11.0
; 
;       Copyright (c) 1991, 2002 by Borland Software Corporation
;       All Rights Reserved.
; 


; $Revision: 9.4.2.1 $

        include RULES.ASI

;       Segments Definitions

Header@

;-----------------------------------------------------------------------
;
;Name           memcpy - copy a block of n bytes from src to dst
;
;Usage          void *memcpy(void *dest, const void *src, size_t n);
;
;Prototype in   mem.h & string.h
;
;Description    memcpy copies  a block of n  bytes from src to dest.
;                       No overlap checking is performed.
;
;Return value   memcpy returns dest
;
;-----------------------------------------------------------------------

Code_seg@

Func@   memcpy, _EXPFUNC, _RTLENTRY, <pointer dest>,<pointer src>,<int n>

        Link@   esi,edi
        mov     edi,dest        ; get dest
        mov     eax,edi         ; copy to eax for return value
        mov     esi,src
        mov     ecx,n
        mov     edx,ecx         ; save count
        shr     ecx,1           ; calculate longword count
        shr     ecx,1
        cld
        rep     movsd           ; copy longwords
        mov     ecx,edx         ; get back count
        and     ecx,3           ; calculate remainder byte count (0-3)
        rep     movsb           ; copy remaining bytes
        Unlink@ esi,edi
        Return@

EndFunc@ memcpy

Code_EndS@

        end
