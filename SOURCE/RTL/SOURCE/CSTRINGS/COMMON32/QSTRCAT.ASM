;[]-----------------------------------------------------------------[]
;|   QSTRCAT.ASM -- appends one string to another (quick version)    |
;[]-----------------------------------------------------------------[]

DWALIGN equ     1               ; set to 1 to enable dword-aligning of string

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
;Name            __strcat__ - appends one string to another
;
;Usage           char *__strcat__(char *dest, const char *src);
;
;Prototype in    string.h
;
;Description     __strcat__ appends a copy of src to the end of dest. The
;                length of the resulting string is strlen(dest) +
;                strlen(src).
;
;                NOTE: this is the "quick" version of strcat; it cheats
;                by fetching 32-bit words, which can GP fault if the
;                src string is near the end of a memory region and DWALIGN
;                is not enabled above.

;Return value    returns dest
;
;-----------------------------------------------------------------------

Code_seg@

Func@   __strcat__, public, _RTLENTRYF, <pointer dest>, <pointer src>

        Link@   edi
        mov     edi,dest        ; get dest string
        mov     ecx,-1
        xor     al,al           ; search for null at end of dest string
        cld
        repne   scasb           ; scan one character past null
        dec     edi             ; edi points to terminating null in dest
        mov     ecx, src        ; get source string

if DWALIGN
        mov     eax, ecx
        and     eax, 3
        jmp     jmptab[eax*4]

jmptab  dd      offset FLAT:fetch
        dd      offset FLAT:fetch3
        dd      offset FLAT:fetch2
        dd      offset FLAT:fetch1

; Copy three bytes

fetch3:
        mov     al, [ecx]
        or      al, al
        je      return0
        mov     [edi], al
        add     ecx, 1
        add     edi, 1

; Copy two bytes

fetch2:
        mov     al, [ecx]
        or      al, al
        je      return0
        mov     [edi], al
        add     ecx, 1
        add     edi, 1

; Copy one byte

fetch1:
        mov     al, [ecx]
        or      al, al
        je      return0
        mov     [edi], al
        add     ecx, 1
        add     edi, 1

;       jmp     fetch

endif   ; DWALIGN

fetch:
        mov     eax, [ecx]      ; get four bytes from source
        or      al, al          ; check byte 0 for null
        jz      return0
        or      ah, ah          ; check byte 1 for null
        jz      return1
        test    eax, 000ff0000h ; check byte 2 for null
        jz      return2
        test    eax, 0ff000000h ; check byte 3 for null
        jz      return3
        mov     [edi], eax
        add     ecx, 4
        add     edi, 4
        jmp     fetch
return3:
        mov     [edi], eax      ; copy bytes 0-3
        mov     eax, dest       ; return dest
        Unlink@ edi
        Return@
return2:
        mov     [edi], ax       ; copy bytes 0-2
        mov     byte ptr [edi+2], 0
        mov     eax, dest       ; return dest
        Unlink@ edi
        Return@
return1:
        mov     [edi], ax       ; copy bytes 0-1
        mov     eax, dest       ; return dest
        Unlink@ edi
        Return@
return0:
        mov     [edi], al       ; copy byte 0
        mov     eax, dest       ; return dest
        Unlink@ edi
        Return@

EndFunc@ __strcat__

Code_EndS@

        end
