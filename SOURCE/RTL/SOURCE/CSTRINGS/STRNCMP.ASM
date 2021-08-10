;[]-----------------------------------------------------------------[]
;|   STRNCMP.ASM -- compare one string to another                    |
;[]-----------------------------------------------------------------[]

;
;       C/C++ Run Time Library - Version 10.0
; 
;       Copyright (c) 1991, 2000 by Inprise Corporation
;       All Rights Reserved.
; 

; $Revision:   9.1  $

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

	mov	esi, str1
	mov	edi, str2
	mov	ecx, maxlen

; loop until maxlen bytes have been examined, a matching character has
; been found, or the end of a string has been reached
@@loop:
	;; checked maxlen characters?
	dec	ecx
	js	@@equal
ifndef _UNICODE
	lodsb
	scasb
else
	lodsw
	scasw
endif
	jne	@@unequal
	;; check for end of string
ifndef _UNICODE
	test	al, al
else
	test	ax, ax
endif
	jne	@@loop

@@equal:
	xor	eax, eax
	jmp	@@exit

@@unequal:
	;; carry flag is set by scas{b,w} above if *str1 < *str2
	;; eax = cf ? -1 : 0;
	;; if (!eax) eax = 1;
	sbb	eax, eax
	or	eax, 1

@@exit:
        Unlink@ esi,edi
        Return@

ifndef	_UNICODE
EndFunc@ strncmp
else
EndFunc@ wcsncmp
endif
Code_EndS@

        end
