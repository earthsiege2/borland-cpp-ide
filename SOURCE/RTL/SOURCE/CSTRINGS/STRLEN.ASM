;[]-----------------------------------------------------------------[]
;|   STRLEN.ASM -- calculate the length of a string                  |
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
;Name		strlen - calculates the length of a string
;
;Usage		size_t strlen(const char *str);
;
;Prototype in	string.h
;
;Description	returns the length of a null terminated string.  This
;		implementation has been optimized for the Pentium processor.
;
;-----------------------------------------------------------------------

Code_seg@

Func@   strlen, _EXPFUNC, _RTLENTRYF, <pointer s>
	mov     eax, [esp+4]	; load s in eax

	test     al, 3
	jne      StrLenalign	; align the pointer

StrLenloop:
	mov       edx, [eax]	; 1 u
	add       eax, 4	; 1 v
	mov       ecx, edx	; 2 u
	sub       edx, 01010101h; 2 v
	and       edx, 080808080h;3 u
	je        StrLenloop	; 3 v
	not       ecx
	and       edx, ecx
	je        StrLenloop

	test      dl, dl	; There is a null terminator somewhere
	jne       StrLenend1
	test      dh, dh
	jne       StrLenend2
	test      edx, 00FF0000h
	jne       StrLenend3
	jmp       StrLenend4

StrLenalign:
	add       eax, 4
	test      byte ptr [eax-4], 0FFh
	jz        StrLenend1
	test      byte ptr [eax-3 ], 0FFh
	jz        StrLenend2
	test      byte ptr [eax-2], 0FFh
	jz        StrLenend3
	dec       eax
	and       al, 0FCh
	jmp       StrLenloop

StrLenend1:
	dec       eax

StrLenend2:
	dec       eax

StrLenend3:
	dec       eax

StrLenend4:
	mov       ecx, [esp+4]	; load s in ecx
	dec       eax
	sub       eax, ecx
	Return@
EndFunc@ strlen

Code_EndS@

	end
