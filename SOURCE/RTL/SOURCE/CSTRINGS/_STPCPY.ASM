;[]-----------------------------------------------------------------[]
;|   STPCPY.ASM -- copy string src to string dest                    |
;[]-----------------------------------------------------------------[]

;
;       C/C++ Run Time Library - Version 11.0
; 
;       Copyright (c) 1991, 2002 by Borland Software Corporation
;       All Rights Reserved.
; 

; $Revision: 9.4.2.1 $

	include RULES.ASI

;       Segments Definitions

Header@

;-----------------------------------------------------------------------
;
;Name           _stpcpy - copy string src to string dest
;
;Usage          char *_stpcpy (char *dest, const char *src);
;
;Prototype in   string.h
;
;Description    Copy the ASCIIZ string *src to the buffer *dest. It is the
;               callers responsibility  to ensure that the dest buffer is
;               large enough  to contain the  string, and to guard against
;               supplying NULL arguments.  This implementation has been
;		optimized for the Pentium processor.
;
;Return value   pointer to the end of the resulting string.
;
;-----------------------------------------------------------------------

Code_seg@

Func@   _stpcpy, _EXPFUNC, _RTLENTRYF, <pointer dest>, <pointer src>
	
	Link@
	mov     eax, dest	; get dest string
	mov     edx, src	; get source string

Again:
	mov	cl, [edx]
	mov	[eax], cl	; move one byte
	test	cl, cl		; was it the end ?
	jz	Exit
	inc	eax

	mov	cl, [edx+1]
	mov	[eax], cl	; move one byte
	test	cl, cl		; was it the end ?
	jz	Exit
	inc	eax

	mov	cl, [edx+2]
	mov	[eax], cl	; first byte
	test	cl, cl		; was it the end ?
	jz	Exit
	inc	eax

	mov	cl, [edx+3]
	add	edx, 4		; interleaved to allow pipelining
	mov     [eax] , cl
	test    cl, cl		; was it the end?
	jz	Exit
	inc	eax

	jmp	Again

Exit:
	Unlink@
	Return@

EndFunc@ _stpcpy

Code_EndS@

	end
	
