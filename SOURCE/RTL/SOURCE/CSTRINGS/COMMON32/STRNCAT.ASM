;[]-----------------------------------------------------------------[]
;|   STRNCAT.ASM -- appends one string to another                    |
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
;Name           strncat - appends strings
;
;Usage          char *strncat(char *destin, const char *source, size_t maxlen);
;
;Prototype in   string.h
;
;Description    strncat copies at most maxlen characters of source to the
;               end of destin and then appends a null character. The maximum
;               length of the resulting string is strlen(destin) + maxlen.
;		This implementation has been optimized for the Pentium processor.
;
;Return value   pointer to destin
;
;-----------------------------------------------------------------------

Code_seg@

Func@	strncat, _EXPFUNC, _RTLENTRYF, <pointer dest>, <pointer src>, <int maxlen>

	Link@   edi, ebx
	mov     edi, dest	; get dest string
	mov     ecx, -1
	xor     al, al		; search for null at end of source string
	cld
	repne   scasb		; scan one character past null
	mov     ecx, maxlen
	lea     ebx, [edi-1]	; esi points to terminating null in dest
	and     ecx, 3		; copy first three character
	mov     edx, src	; get src string
	jecxz   dwordcopy

bytecopy:
	mov	al, [edx]
	mov	[ebx], al	; move one byte
	test    al, al		; was it the end ?
	jz	Exit
	inc     edx
	inc     ebx
	dec     ecx
	jnz     bytecopy

dwordcopy:
	mov     ecx, maxlen
	shr     ecx, 2
	jecxz   endstring

Again:
	mov	al, [edx]
	mov	[ebx], al	; move one byte
	test	al, al		; was it the end ?
	jz	Exit
	mov	al, [edx + 1]
	mov	[ebx + 1], al	; move one byte
	test	al, al		; was it the end ?
	jz	Exit
	mov	al, [edx + 2]
	mov	[ebx + 2], al	; first byte
	test	al, al		; was it the end ?
	jz	Exit
	mov	al, [edx + 3]
	add	edx, 4		; interleaved to allow pipelining
	mov	[ebx + 3], al
	add	ebx, 4
	test	al, al		; was it the end
	jz	Exit
	dec	ecx
	jnz	Again

endstring:
	mov	BYTE PTR [ebx], 0

Exit:
	mov	eax, dest	; return dest
	Unlink@ edi, ebx
	Return@

EndFunc@ strncat

Code_EndS@

	end
	
