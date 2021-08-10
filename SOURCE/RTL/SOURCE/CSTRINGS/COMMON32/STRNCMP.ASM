;[]-----------------------------------------------------------------[]
;|   STRNCMP.ASM -- compare one string to another                    |
;[]-----------------------------------------------------------------[]

;
;       C/C++ Run Time Library - Version 8.0
; 
;       Copyright (c) 1991, 1997 by Borland International
;       All Rights Reserved.
; 
; $Revision:   8.4  $

        include RULES.ASI

;       Segments Definitions

Header@

;-----------------------------------------------------------------------
;
;Name           strncmp, wcsncmp - compare one string to another
;
;Usage          int strncmp(const char *str1, const char *str2, size_t maxlen);
;		int wcsncmp(const wchar_t *str1, const wchar_t *str2, size_t maxlen);
;
;Prototype in   string.h
;
;
;Description    Compare *str1  with *str2, returning  a negative, zero,  or
;               positive integer  according to whether *str1  is less than,
;               equal, or greater than *str2, respectively.
;
;               At most "maxlen" characters will be compared. A "maxlen" of zero
;               results in an equal compare, i.e. returns a zero.
;
;Return value   strncmp and wcsncmp return an integer value as follows:
;                   < 0 if str1 is less than str2
;                   = 0 if str1 is the same as str2
;                   > 0 if str2 is greater than str2
;
;-----------------------------------------------------------------------

Code_seg@

ifndef	_UNICODE
Func@   strncmp, _EXPFUNC, _RTLENTRYF, <pointer str1>, <pointer str2>, <int maxlen>
else
Func@   wcsncmp, _EXPFUNC, _RTLENTRYF, <pointer str1>, <pointer str2>, <int maxlen>
endif
	Link@   esi,edi
        cld

; Determine size of 2nd source string.

        mov     edi, str2
        mov     esi, edi
        mov     eax, maxlen
        mov     ecx, eax
        jecxz   ncm_end
        mov     edx, eax
        xor     ax, ax
ifndef	_UNICODE
        repne   scasb
else
        repne   scasw
endif
        sub     edx, ecx
        mov     ecx, edx

        mov     edi, esi
        mov     esi, str1

; Scan until either *str2 terminates, a difference is found, or "maxlen"
; characters are compared.  Note that it is sufficient to check only for
; right termination, since if the left terminates before the right then
; that difference will also terminate the scan.

ifndef	_UNICODE
	repe    cmpsb
else
	repe    cmpsw
endif

; The result is the signed difference of the final character pair, be they
; equal or different. A simple byte subtract and CBW doesn't work here because
; it does the wrong thing when the characters are 'ff' and '7f'.  In that case
; 255 would be reported as less than 127. ie '80' sign extends to 'ff80' which
; is a negative number.

        xor     eax, eax
        mov     edx, eax
ifndef	_UNICODE
        mov     al, [esi-1]
        mov     dl, [edi-1]
else
	mov     ax, WORD PTR[esi-2]
        mov     dx, WORD PTR[edi-2]
endif
        sub     eax, edx
ncm_end:
        Unlink@ esi,edi
        Return@

ifndef	_UNICODE
EndFunc@ strncmp
else
EndFunc@ wcsncmp
endif
Code_EndS@

        end
