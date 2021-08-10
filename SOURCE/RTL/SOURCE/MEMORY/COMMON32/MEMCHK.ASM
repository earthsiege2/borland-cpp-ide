;[]-----------------------------------------------------------------[]
;|   MEMCHK.ASM --  checks memory for value                          |
;[]-----------------------------------------------------------------[]

;
;       C/C++ Run Time Library - Version 1.5
; 
;       Copyright (c) 1999 by Borland International
;       All Rights Reserved.
; 

        include RULES.ASI

;       Segments Definitions

Header@

;-----------------------------------------------------------------------
;
;Name            _memchk - checks memory for value
;
;Usage           int _memchk(void *src, int c, size_t n);
;
;Prototype in    none
;
;Description     Checks that the n bytes of the block pointed to by src
;                contain the value c.
;
;Return value    If all bytes in the block are the value c, _memchk
;                returns 1; otherwise it returns 0.
;
;-----------------------------------------------------------------------

Code_seg@

Func@   _memchk, public, _RTLENTRYF, <pointer src>,<int c>,<int n>

        Link@   edi
        mov     edi,src         ; get src
        mov     ecx,n           ; get count
        jecxz   ret_1           ; if zero, block is ok
        mov     al,c            ; get byte to check
        mov     ah,al           ; copy to ah
        mov     dx,ax
        shl     eax,16          ; mov to upper word
        mov     ax,dx           ; get back lower word
        mov     edx,ecx         ; save count
        shr     ecx,1           ; calculate longword count
        shr     ecx,1
        cld
        repe    scasd           ; scan longwords
        jne     ret_0           ; found a non-matching byte
        mov     ecx,edx         ; get back count
        and     ecx,3           ; calculate remainder byte count (0-3)
        repe    scasb           ; scan remaining bytes
        jne     ret_0           ; 
ret_1:
        mov     eax,1           ; return 1 if block is OK
return:
        Unlink@ edi
        Return@
ret_0:
        xor     eax, eax        ; return 0 if block is OK
        jmp     return
EndFunc@ _memchk

Code_EndS@

        end
