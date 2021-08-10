;[]-----------------------------------------------------------------[]
;|   MEMSET.ASM --  sets memory to value                             |
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
;Name		memset - sets memory to value
;
;Usage		void *memset(void *src, int c, size_t n);
;
;Prototype in	mem.h
;
;Description	sets the n bytes of the block pointed to by src to
;		c.  This implementation has been optimized for the
;		Pentium processor.
;
;Return value	src
;
;-----------------------------------------------------------------------

Code_seg@

Func@   memset, _EXPFUNC, _RTLENTRYF, <pointer src>,<int c>,<int n>

	Link@   edi
	mov     al, c		; get byte to store

	mov     edx,n		; get the byte count
	mov     edi, src	; get src
	mov     ah, al
	test    edx, not 3	; byte count is less than 4 ?
	je      lessthan4

	mov     [edi], ax	; u
	lea     ecx, [edi+edx-4]; v, point at the end of dest

	mov     [edi+2], ax	; u
	mov     eax, [edi]	; v

	shr     edx, 3		; u, divide the count by 8
	jz      lessthan8	; v

bigchunk:
	mov     [edi], eax	; 1 u
	mov     [edi+4], eax	; 1 v
	dec     edx		; 2 u
	jz      afterbigchunk	; 2 v

	mov     [edi+8], eax
	mov     [edi+12], eax
	dec     edx
	jz      afterbigchunk

	mov     [edi+16], eax
	mov     [edi+20], eax
	dec     edx
	jz      afterbigchunk

	mov     [edi+24], eax
	mov     [edi+28], eax
	dec     edx
	jz      afterbigchunk

	mov     [edi+32], eax
	mov     [edi+36], eax
	dec     edx
	jz      afterbigchunk

	mov     [edi+40], eax
	mov     [edi+44], eax
	lea     edi, [edi+48]
	dec     edx
	jnz     bigchunk

afterbigchunk:
	mov     [ecx], eax	; u, copy the last two dword of the buffer
	mov     [ecx-4], eax	; v, NB : it could be misaligned !!!
	mov     eax, src	; return src
	Unlink@ edi
	Return@


lessthan8:			; but more than 3
	mov     [ecx], eax
	mov     eax, src	; return src
	Unlink@ edi
	Return@

lessthan4:
	and     edx, 3
	jz      done
	mov     [edi], al
	dec     dl
	jz      done              ; 1 byte
	mov     [edi+edx-1], ax
done:
	mov      eax, src
	Unlink@  edi
	Return@

EndFunc@ memset

Code_EndS@

	end
