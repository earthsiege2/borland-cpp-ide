;[]-----------------------------------------------------------------[]
;|   QSTRCHR.ASM -- scans a string for a character (quick version)   |
;[]-----------------------------------------------------------------[]

DWALIGN equ     1               ; set to 1 to enable dword-aligning of string

;
;       C/C++ Run Time Library - Version 8.0
; 
;       Copyright (c) 1992, 1997 by Borland International
;       All Rights Reserved.
; 
; $Revision:   8.2  $

        include RULES.ASI

;       Segments Definitions

Header@

;-----------------------------------------------------------------------
;
;Name            __strchr__ - scans a string for the first occurrence of a
;                         given character
;
;Usage           char *__strchr__(const char *str, int c);
;
;Prototype in    string.h
;
;Description     __strchr__ scans a string in the forward direction, looking
;                for a specific character. __strchr__ finds the first
;                occurrence of the character ch in the string str.
;
;                The null-terminator is considered
;                to be part of the string, so that, for example
;
;                        __strchr__(strs, 0)
;
;                returns a pointer to the terminating null character of the
;                string "strs".
;
;                NOTE: this is the "quick" version of strchr; it cheats
;                by fetching 32-bit words, which can GP fault if the
;                string is near the end of a memory region and DWALIGN
;                is not set to 1 above.
;
;Return value    __strchr__  returns a pointer to the first occurrence of the
;                character ch in str; if ch does not occur in str, __strchr__
;                returns NULL.
;
;-----------------------------------------------------------------------

Code_seg@

Func@   __strchr__, public, _RTLENTRYF, <pointer strng>, <int c>

        Link@
        mov     eax,strng       ; get source string
        mov     dl,c            ; get char to search for
if DWALIGN
        mov     ecx, eax
        and     ecx, 3
        jmp     jmptab[ecx*4]

jmptab  dd      offset FLAT:fetch
        dd      offset FLAT:fetch3
        dd      offset FLAT:fetch2
        dd      offset FLAT:fetch1


; Fetch and compare three bytes

fetch3:
        mov     cl, [eax]
        cmp     cl, dl
        je      return0
        or      cl, cl
        jz      notfound
        add     eax, 1

; Fetch and compare two bytes

fetch2:
        mov     cl, [eax]
        cmp     cl, dl
        je      return0
        or      cl, cl
        jz      notfound
        add     eax, 1

; Fetch and compare one byte

fetch1:
        mov     cl, [eax]
        cmp     cl, dl
        je      return0
        or      cl, cl
        jz      notfound
        add     eax, 1

;       jmp     fetch


endif   ; DWALIGN

fetch:
        mov     ecx, [eax]      ; get next longword

        cmp     cl, dl          ; check byte 0
        je      return0
        or      cl, cl
        jz      notfound

        cmp     ch, dl          ; check byte 1
        je      return1
        or      ch, ch
        jz      notfound

        shr     ecx, 16         ; now check high bytes

        cmp     cl, dl          ; check byte 2
        je      return2
        or      cl, cl
        jz      notfound

        cmp     ch, dl          ; check byte 3
        je      return3
        or      ch, ch
        jz      notfound
        add     eax, 4
        jmp     fetch
notfound:
        xor     eax, eax        ; not found, return NULL
        Unlink@
        Return@
return3:
        add     eax, 3
        Unlink@
        Return@
return2:
        add     eax, 2
        Unlink@
        Return@
return1:
        inc     eax
return0:
        Unlink@
        Return@

EndFunc@ __strchr__
Code_EndS@

        end
