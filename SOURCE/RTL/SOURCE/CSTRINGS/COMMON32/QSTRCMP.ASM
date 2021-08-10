;[]-----------------------------------------------------------------[]
;|   QSTRCMP.ASM -- compare one string to another (quick version)    |
;[]-----------------------------------------------------------------[]

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
;Name            __strcmp__ - compare one string to another
;
;Usage           int __strcmp__(const char *str1, const char str2);
;
;Prototype in    string.h
;
;Description     Compare *str1  with *str2, returning  a negative, zero,  or
;                positive integer  according to whether *str1  is less than,
;                equal, or greater than *str2, respectively.
;
;                NOTE: this is the "quick" version of strcmp; it cheats
;                by fetching 32-bit words, which can GP fault if either
;                of the strings is near the end of a memory region.
;
;Return value    __strcmp__ return an integer value such as:
;                 < 0    if str1 is less than str2
;                 = 0    if str1 is the same as str2
;                 > 0    if str2 is greater than str2
;
;-----------------------------------------------------------------------

Code_seg@

Func@   __strcmp__, public, _RTLENTRYF, <pointer str1>, <pointer str2>

        Link@   ebx
        mov     ecx, str1
        mov     edx, str2
fetch:
        mov     eax, [ecx]      ; fetch four bytes from str1
        mov     ebx, [edx]      ; fetch four bytes from str2
        cmp     eax, ebx        ; compare four bytes
        jne     notequal        ; not equal, find which byte is different

; The following weird piece of code tests if EAX (equal to EBX) has
; a null byte in it.  In C this would be implemented with the macro:
;
; #define HAS_NULLBYTE(x) ((x - 0x01010101) & ~x & 0x80808080)
;
; This works by subtracting one from each byte.  If and only if a byte
; is zero, the subtraction changes the most significant bit of that
; byte from zero to one.

        sub     eax, 01010101h
        and     eax, 80808080h
        not     ebx
        test    eax, ebx
        jnz     isequal         ; a zero byte was found, so exit
        add     ecx, 4
        add     edx, 4
        jmp     fetch
notequal:
        cmp     al, bl          ; compare byte 0
        jne     setflags
        or      al, al          ; check for null terminator
        jz      isequal
        cmp     ah, bh          ; compare byte 1
        jne     setflags
        or      ah, ah          ; check for null terminator
        jz      isequal
        shr     eax, 16
        shr     ebx, 16
        cmp     al, bl          ; compare byte 2
        jne     setflags
        or      al, al          ; check for null terminator
        jz      isequal
        cmp     ah, bh          ; compare byte 3
setflags:
        rcr     eax, 1          ; extend carry bit to high bit of EAX
        or      eax, 1          ; ensure that the result is non-zero
        Unlink@ ebx
        Return@
isequal:                        ; equal, return zero
        xor     eax, eax
        Unlink@ ebx
        Return@

EndFunc@ __strcmp__

Code_EndS@

        end
