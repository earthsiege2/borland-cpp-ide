;[]-----------------------------------------------------------------[]
;|   STRNCMP.ASM -- compare one string to another                     |
;[]-----------------------------------------------------------------[]

;
;       C/C++ Run Time Library - Version 1.5
; 
;       Copyright (c) 1991, 1994 by Borland International
;       All Rights Reserved.
; 

        include RULES.ASI

;       Segments Definitions

Header@

;-----------------------------------------------------------------------
;
;Name           strncmp - compare one string to another
;
;Usage          int strncmp(const char *str1, const char *str2, size_t maxlen);
;
;Prototype in   string.h
;
;
;Description    Compare *str1  with *str2, returning  a negative, zero,  or
;               positive integer  according to whether *str1  is less than,
;               equal, or greater than *str2, respectively.
;
;               At most "maxlen" bytes will be compared. A "maxlen" of zero
;               results in an equal compare, i.e. returns a zero.
;
;Return value   strncmp return an integer value such as:
;                   < 0 if str1 is less than str2
;                   = 0 if str1 is the same as str2
;                   > 0 if str2 is greater than str2
;
;-----------------------------------------------------------------------

Code_seg@

Func@   strncmp, _EXPFUNC, _RTLENTRYF, <pointer str1>, <pointer str2>, <int maxlen>

        Link@   esi,edi
        cld

; Determine size of 2nd source string.

        mov     edi, str2
        mov     esi, edi
        mov     eax, maxlen
        mov     ecx, eax
        jecxz   ncm_end
        mov     edx, eax
        xor     al, al
        repne   scasb
        sub     edx, ecx
        mov     ecx, edx

        mov     edi, esi
        mov     esi, str1

; Scan until either *str2 terminates, a difference is found, or "maxlen"
; characters are compared.  Note that it is sufficient to check only for
; right termination, since if the left terminates before the right then
; that difference will also terminate the scan.

        repe    cmpsb

; The result is the signed difference of the final character pair, be they
; equal or different. A simple byte subtract and CBW doesn't work here because
; it does the wrong thing when the characters are 'ff' and '7f'.  In that case
; 255 would be reported as less than 127. ie '80' sign extends to 'ff80' which
; is a negative number.

        xor     eax, eax
        mov     edx, eax
        mov     al, [esi-1]
        mov     dl, [edi-1]
        sub     eax, edx
ncm_end:
        Unlink@ esi,edi
        Return@

EndFunc@ strncmp

Code_EndS@

        end
