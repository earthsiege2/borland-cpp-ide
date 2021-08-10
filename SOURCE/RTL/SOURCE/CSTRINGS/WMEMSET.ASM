;[]-----------------------------------------------------------------[]
;|   WMEMSET.ASM --  sets memory to value (16-bits)                  |
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
;Name            _wmemset - RTL helper function that sets memory to 16-bit value
;
;Usage           void *_wmemset(void *src, int c, size_t n);
;
;Prototype in    _string.h
;
;Description     sets the n words of the block pointed to by src to c.
;
;Return value    src
;
;-----------------------------------------------------------------------

Code_seg@

Func@   _wmemset, _EXPFUNC, _RTLENTRYF, <pointer src>,<int c>,<int n>

        Link@   edi
        mov     edi,src         ; get src
        mov     ax,c            ; get word to store
        mov     ecx,n
        cld
        rep     stosw           ; store words
        mov     eax,src         ; return src
        Unlink@ edi
        Return@

EndFunc@ _wmemset

Code_EndS@

        end
