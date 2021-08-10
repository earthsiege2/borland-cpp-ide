;[]-----------------------------------------------------------------[]
;|   WCSCMP.ASM -- compare one wide-characer string to another       |
;[]-----------------------------------------------------------------[]

;
;       C/C++ Run Time Library - Version 8.0
; 
;       Copyright (c) 1996, 1997 by Borland International
;       All Rights Reserved.
; 
; $Revision:   8.1  $

        include RULES.ASI

;       Segments Definitions

Header@

;-----------------------------------------------------------------------
;
;Name            wcscmp - compare one wide-character string to another
;
;Usage           int wcscmp(const wchar_t *str1, const wchar_t str2);
;
;Prototype in    string.h
;
;Description     Compare *str1  with *str2, returning  a negative, zero,  or
;                positive integer  according to whether *str1  is less than,
;                equal, or greater than *str2, respectively.
;
;Return value    wcscmp returns an integer value as follows:
;                 < 0    if str1 is less than str2
;                 = 0    if str1 is the same as str2
;                 > 0    if str2 is greater than str2
;
;-----------------------------------------------------------------------

Code_seg@

Func@   wcscmp, _EXPFUNC, _RTLENTRYF, <pointer str1>, <pointer str2>

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
	repne   scasw
	not     ecx

        mov     edi, esi
        mov     esi, str1

; Scan until either *str2 terminates or a difference is found.  Note that it is
; sufficient to check only for right termination, since if the left terminates
; before the right then that difference will also terminate the scan.

	repe    cmpsw

; The result is the signed difference of the final character pair, be they
; equal or different. A simple byte subtract and CBW doesn't work here because
; it does the wrong thing when the characters are 'ff' and '7f'.  In that case
; 255 would be reported as less than 127. ie '80' sign extends to 'ff80' which
; is a negative number.  Remember, EAX and EDX are zero from above.

	mov     ax, WORD PTR[esi-2]
        mov     dx, WORD PTR[edi-2]
	sub     eax, edx

        Unlink@ esi,edi
        Return@
EndFunc@ wcscmp

Code_EndS@

        end


