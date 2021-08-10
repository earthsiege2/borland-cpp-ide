;[]-----------------------------------------------------------------[]
;|   STRCMP.ASM -- compare one string to another                     |
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
;Name            strcmp - compare one string to another
;
;Usage           int strcmp(const char *str1, const char str2);
;
;Prototype in    string.h
;
;Description     Compare *str1  with *str2, returning  a negative, zero,  or
;                positive integer  according to whether *str1  is less than,
;                equal, or greater than *str2, respectively.
;
;Return value    strcmp return an integer value such as:
;                 < 0    if str1 is less than str2
;                 = 0    if str1 is the same as str2
;                 > 0    if str2 is greater than str2
;
;-----------------------------------------------------------------------

Code_seg@

Func@   strcmp, _EXPFUNC, _RTLENTRYF, <pointer str1>, <pointer str2>

        Link@   esi,edi
        cld

; It's handy to have upper nibbles of EAX and EDX zero later for
; the final subtraction.

        xor     eax, eax
        mov     edx, eax

;   Determine size of 2nd source string.

        mov     edi, str2
        mov     esi, edi
        mov     ecx, -1
        repne   scasb
        not     ecx

        mov     edi, esi
        mov     esi, str1

; Scan until either *str2 terminates or a difference is found.  Note that it is
; sufficient to check only for right termination, since if the left terminates
; before the right then that difference will also terminate the scan.

        repe    cmpsb

; The result is the signed difference of the final character pair, be they
; equal or different. A simple byte subtract and CBW doesn't work here because
; it does the wrong thing when the characters are 'ff' and '7f'.  In that case
; 255 would be reported as less than 127. ie '80' sign extends to 'ff80' which
; is a negative number.  Remember, EAX and EDX are zero from above.

        mov     al, [esi-1]
        mov     dl, [edi-1]
        sub     eax, edx

        Unlink@ esi,edi
        Return@

EndFunc@ strcmp

Code_EndS@

        end
