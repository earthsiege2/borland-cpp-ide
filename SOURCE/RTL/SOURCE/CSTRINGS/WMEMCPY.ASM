;[]-----------------------------------------------------------------[]
;|   WMEMCPY.ASM --  copy a block of n words from src to dst         |
;[]-----------------------------------------------------------------[]

;
;       C/C++ Run Time Library - Version 11.0
; 
;       Copyright (c) 1996, 2002 by Borland Software Corporation
;       All Rights Reserved.
; 

; $Revision: 9.4.2.1 $

        include RULES.ASI

;       Segments Definitions

Header@

;-----------------------------------------------------------------------
;
;Name           _wmemcpy - copy a block of n words from src to dst
;
;Usage          void *_wmemcpy(void *dest, const void *src, size_t n);
;
;Prototype in   mem.h & string.h
;
;Description    _wmemcpy copies  a block of n words from src to dest.
;                       No overlap checking is performed.
;
;Return value   _wmemcpy returns dest
;
;-----------------------------------------------------------------------

Code_seg@

Func@   _wmemcpy, _EXPFUNC, _RTLENTRY, <pointer dest>,<pointer src>,<int n>

        Link@   esi,edi
        mov     edi,dest        ; get dest
        mov     eax,edi         ; copy to eax for return value
        mov     esi,src
        mov     ecx,n
        mov     edx,ecx         ; save count
        shr     ecx,1           ; calculate longword count
        cld
        rep     movsd           ; copy longwords
        mov     ecx,edx         ; get back count
        shl     ecx,1           ; count was in dwords
        and     ecx,3           ; calculate remainder byte count (0-3)
        rep     movsb           ; copy remaining bytes
        Unlink@ esi,edi
        Return@

EndFunc@ _wmemcpy

Code_EndS@

        end
