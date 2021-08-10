;[]-----------------------------------------------------------------[]
;|   MEMMOVE.ASM --  copy a block of n bytes from src to dst         |
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
;Name           memmove - copy a block of n bytes from src to dst
;
;Usage          void *memmove(void *dest, const void *src, size_t n);
;
;Prototype in   mem.h & string.h
;
;Description    memmove copies  a block of n  bytes from src to dest. Even
;               when the source and destination blocks overlap, bytes in
;               the overlapping locations are copied correctly.
;
;Return value   memmove returns dest
;
;-----------------------------------------------------------------------

Code_seg@

Func@   memmove, _EXPFUNC, _RTLENTRYF, <pointer dest>,<pointer src>,<int n>

        Link@   esi,edi
        mov     edi,dest
        mov     esi,src
        mov     ecx,n
        mov     edx,ecx
        cmp     edi,esi         ; dest < source ?
        jb      mov_fwd         ; yes, do a simple forward move
        je      mov_end         ; dest == source ? do nothing
        std                     ; force esi and edi to decrement
        lea     esi,[esi+ecx-1] ; point to last byte of source buffer
        lea     edi,[edi+ecx-1] ; point to last byte of dest buffer
        and     ecx,3           ; copy trailing bytes
        rep     movsb
        mov     ecx,edx         ; get original count back
        shr     ecx,1           ; calculate no. of longwords
        shr     ecx,1
        sub     esi,3           ; point to previous longword in source
        sub     edi,3           ; point to previous longword in dest
        rep     movsd           ; copy longwords
        cld                     ; clear direction flag
        jmp     short mov_end
mov_fwd:
        cld
        shr     ecx,1
        shr     ecx,1
        rep     movsd           ; copy longwords
        mov     ecx,edx         ; get original count back
        and     ecx,3           ; calculate remainder byte count (0-3)
        rep     movsb           ; copy remaining bytes
mov_end:
        mov     eax,dest
        Unlink@ esi,edi
        Return@

EndFunc@ memmove

Code_EndS@

        end
