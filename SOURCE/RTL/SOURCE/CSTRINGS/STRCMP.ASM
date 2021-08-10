;[]-----------------------------------------------------------------[]
;|   STRCMP.ASM -- compare one string to another                     |
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
;Name		strcmp - compare one string to another
;
;Usage		int strcmp(const char *str1, const char str2);
;
;Prototype in	string.h
;
;Description	Compare *str1  with *str2, returning  a negative, zero,  or
;		positive integer  according to whether *str1  is less than,
;		equal, or greater than *str2, respectively. This
;		implementation has been optimized for the Pentium processor.
;
;Return value	strcmp return an integer value such as:
;		< 0    if str1 is less than str2
;		= 0    if str1 is the same as str2
;		> 0    if str2 is greater than str2
;
;-----------------------------------------------------------------------

Code_seg@
Func@   strcmp, _EXPFUNC, _RTLENTRYF, <pointer str1>, <pointer str2>
	mov  ecx, [esp+4]   ; str1
	mov  edx, [esp+8]   ; str2
	push ebx
	xor  eax, eax
	xor  ebx, ebx

PSloop:
	mov  al, [ecx]
	mov  bl, [edx]
	sub  eax, ebx
	jne  PSend
	test bl,bl
	je   PSend

	mov  al, [ecx+1]
	mov  bl, [edx+1]
	sub  eax, ebx
	jne  PSend
	test bl,bl
	je   PSend

	mov  al, [ecx+2]
	mov  bl, [edx+2]
	sub  eax, ebx
	jne  PSend
	test bl,bl
	je   PSend

	mov  al, [ecx+3]
	mov  bl, [edx+3]
	sub  eax, ebx
	jne  PSend
	add  ecx, 4
	add  edx, 4
	test bl, bl
	jne  PSloop

PSend:
	 pop ebx
	 Return@

EndFunc@ strcmp

Code_EndS@

	end

