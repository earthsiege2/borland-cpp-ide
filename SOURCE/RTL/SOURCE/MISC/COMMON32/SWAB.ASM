;[]-----------------------------------------------------------------[]
;|   SWAB.ASM -- swap bytes                                          |
;[]-----------------------------------------------------------------[]

;
;       C/C++ Run Time Library - Version 8.0
; 
;       Copyright (c) 1991, 1997 by Borland International
;       All Rights Reserved.
; 
; $Revision:   8.2  $

        include RULES.ASI

;       Segments Definitions

Header@

;-----------------------------------------------------------------------
;
;Name            swab -  swaps bytes
;
;Usage           void swab(char *from, char *to, int nbytes);
;
;Prototype in    stdlib.h
;
;Description     swab copies n bytes from the from string to the to
;                string. Adjacent even- and odd-byte positions are swapped.
;                This is useful for moving data from one machine to another
;                machine with a different byte order. nbytes should be even.
;
;Return value    There is no return value.
;
;-----------------------------------------------------------------------

Code_seg@

Func@   swab, _EXPFUNC, _RTLENTRY, <pointer from>, <pointer to>, <int nbytes>

        Link@   esi,edi
        mov     ecx, nbytes             ; ECX <- nbytes
        shr     ecx, 1                  ; Convert bytes -> words
        jecxz   exit_swab               ; If degenerate case, exit.
        cld                             ; Make string ops go forward
        mov     edi, to                 ; EDI <- destination
        mov     esi, from               ; ESI <- source
next_word:
        lodsw                           ; Load word from source string
        xchg    ah, al                  ; Swap the bytes
        stosw                           ; Store result in destination
        loop    next_word               ; Do the next word
exit_swab:
        Unlink@ esi,edi
        Return@

EndFunc@ swab

Code_EndS@

        end
