;[]-----------------------------------------------------------------[]
;|   STRCHR.ASM -- scans a string for the first occurrence of a      |
;|                 given character                                   |
;[]-----------------------------------------------------------------[]

;
;       C/C++ Run Time Library - Version 10.0
; 
;       Copyright (c) 1991, 2000 by Inprise Corporation
;       All Rights Reserved.
; 

; $Revision:   9.0  $

        include RULES.ASI

;       Segments Definitions

Header@

;-----------------------------------------------------------------------
;
;Name		strchr - scans a string for the first occurrence of a
;		         given character
;
;Usage		char *strchr(const char *str, int c);
;
;Prototype in	string.h
;
;Description	strchr scans a string in the forward direction, looking for a
;		specific character. strchr finds the first occurrence of the
;		character ch in the string str.
;
;		The null-terminator is considered to be a part of the string,
;		so that, for example
;
;			strchr(strs, 0)
;
;		returns a pointer to the terminating null character of the
;		string "strs".  This implementation has been optimized
;		for the Pentium processor.
;
;Return value	strchr  returns a pointer to the first occurrence of the
;		character ch in str; if ch does not occur in str, strchr
;		returns NULL.
;
;-----------------------------------------------------------------------

Code_seg@

Func@   strchr, _EXPFUNC, _RTLENTRYF, <pointer strng>, <int c>

	Link@   ebx
	mov     edx,strng	; get source string
	mov     ecx,edx		; save in edx
	mov     al, c		; search for character
	cld

Again:
	mov     bl, [edx]
	cmp     al, bl
	je      Found0
	test    bl, bl
	jz      notfound

	mov     bl, [edx+1]
	cmp     al, bl
	je      Found1
	test    bl, bl
	jz      notfound

	mov     bl, [edx+2]
	cmp     al, bl
	je      Found2
	test    bl, bl
	jz      notfound

	mov     bl, [edx+3]
	cmp     al, bl
	je      Found3
	add     edx, 4
	test    bl, bl
	jnz     Again

notfound:
	xor     eax, eax
	jmp     return

Found0:
	mov     eax, edx
	jmp     return

Found1:
	lea     eax, [edx+1]
	jmp     return

Found2:
	lea     eax, [edx+2]
	jmp     return

Found3:
	lea     eax, [edx+3]

return:
	Unlink@ ebx
	Return@

EndFunc@ strchr

Code_EndS@

	end
