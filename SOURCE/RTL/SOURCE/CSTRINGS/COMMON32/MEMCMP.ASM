;[]-----------------------------------------------------------------[]
;|   MEMCMP.ASM -- compare two memory arrays                         |
;[]-----------------------------------------------------------------[]

;
;       C/C++ Run Time Library - Version 8.0
; 
;       Copyright (c) 1996, 1997 by Borland International
;       All Rights Reserved.
; 
; $Revision:   8.0  $

	include RULES.ASI

;       Segments Definitions

Header@

;-----------------------------------------------------------------------
;
;Name		memcmp - compare two memory arrays
;
;Usage		int memcmp(const void *s1, const void *s2, size_t n);
;
;Prototype in	mem.h & string.h
;
;Description	memcmp compares two memory areas, s1 and s2, for a length
;		of exactly n bytes. This function compares bytes as
;		unsigned chars, so memcmp ("\0xFF", "\0x7F", 1) returns
;		a positive value.  This implementation has been optimized
;		for the Pentium processor.
;
;Return value	< 0 if s1 is less than s2
;		= 0 if s1 is the same as s2
;		> 0 if s1 is greater than s2
;
;-----------------------------------------------------------------------

Code_seg@

Func@   memcmp, _EXPFUNC, _RTLENTRYF, <pointer buf1>, <pointer buf2> , < int n >
	
	Link@   esi,edi
	mov       edi, n
	mov       ecx, buf1
	mov       esi, buf2
	
@2:
	cmp       edi,4
	jl        short @3
	
	mov       al,byte ptr [ecx]
	mov       dl,byte ptr [esi]
	cmp       dl,al
	jne       short @5
	mov       al,byte ptr [ecx+1]
	mov       dl,byte ptr [esi+1]
	cmp       dl,al
	jne       short @5
	mov       al,byte ptr [ecx+2]
	mov       dl,byte ptr [esi+2]
	cmp       dl,al
	jne       short @5
	mov       al,byte ptr [ecx+3]
	mov       dl,byte ptr [esi+3]
	cmp       dl,al
	jne       short @5
	sub       edi,4
	add       ecx,4
	add       esi,4
	cmp       edi,4
	jge       short @2
@3:
@5:
	test      edi,edi
	jne       short @9
	xor       eax,eax
	jmp       short @10
@9:
@11:
	mov       al,byte ptr [ecx]
	mov       dl,byte ptr [esi]
	cmp       dl,al
	jne       short @12
	inc       ecx
	inc       esi
	dec       edi
	jne       short @11
@12:
	xor       ecx,ecx
	mov       cl,al
	xor       eax,eax
	mov       al,dl
	sub       ecx,eax
	mov       eax,ecx
@14:
@10:
	Unlink@ esi, edi
	Return@

EndFunc@ memcmp

Code_EndS@
	
	end
