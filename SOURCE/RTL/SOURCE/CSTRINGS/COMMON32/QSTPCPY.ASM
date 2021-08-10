;[]-----------------------------------------------------------------[]
;|   QSTPCPY.ASM -- copy string src to string dest (quick version)   |
;[]-----------------------------------------------------------------[]

DWALIGN equ     1               ; set to 1 to enable dword-aligning of string

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
;Name           __stpcpy__ - copy string src to string dest
;
;Usage          char *__stpcpy__ (char *dest, const char *src);
;
;Prototype in   string.h
;
;Description    Copy the ASCIIZ string *src to  the buffer *dest. It is the
;               callers responsibility  to ensure that  the dest buffer  is
;               large enough  to contain the  string, and to  guard against
;               supplying NULL arguments.  This function is identical
;               to __strcpy__ except that the return values differ.
;
;               NOTE: this is the "quick" version of stpcpy; it cheats
;               by fetching 32-bit words, which can GP fault if either
;               of the strings is near the end of a memory region.
;
;Return value   __stpcpy__ returns dest + strlen(src)
;
;-----------------------------------------------------------------------

Code_seg@

Func@   __stpcpy__, public, _RTLENTRYF, <pointer dest>, <pointer src>

        Link@
        mov     ecx,src         ; get source string
        mov     edx,dest        ; get destination buffer
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
        mov     [edx], al
        add     ecx, 1
        add     edx, 1

; Copy two bytes

fetch2:
        mov     al, [ecx]
        or      al, al
        je      return0
        mov     [edx], al
        add     ecx, 1
        add     edx, 1

; Copy one byte

fetch1:
        mov     al, [ecx]
        or      al, al
        je      return0
        mov     [edx], al
        add     ecx, 1
        add     edx, 1

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
        mov     [edx], eax
        add     ecx, 4
        add     edx, 4
        jmp     fetch
return3:
        mov     [edx], eax      ; copy bytes 0-3
        lea     eax, [edx+3]    ; return address of terminating null
        Unlink@
        Return@
return2:
        mov     [edx], ax       ; copy bytes 0-2
        mov     byte ptr [edx+2], 0 
        lea     eax, [edx+2]    ; return address of terminating null
        Unlink@
        Return@
return1:
        mov     [edx], ax       ; copy bytes 0-1
        lea     eax, [edx+1]    ; return address of terminating null
        Unlink@
        Return@
return0:
        mov     [edx], al       ; copy byte 0
        mov     eax, edx        ; return address of terminating null
        Unlink@
        Return@

EndFunc@ __stpcpy__

Code_EndS@

        end
