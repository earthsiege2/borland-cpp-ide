;-----------------------------------------------------------------------
; filename - _memchr.asm
;
; function(s)
;
; jump stubs for C++ implementation of memchr()
;-----------------------------------------------------------------------

;
;       C/C++ Run Time Library - Version 6.5
; 
;       Copyright (c) 1993, 1994 by Borland International
;       All Rights Reserved.
; 

        include rules.asi

        assume cs:_TEXT

extrn	_memchr	: DIST

ifdef __l__ or __c__ or __h__
public	@memchr$qnxviui
public	@memchr$qnviui

else ; defined __t__ or __s__ or __m__ or __f__

public	@memchr$qpxviui
public	@memchr$qpviui

endif

_TEXT	segment

ifdef __l__ or __c__ or __h__
@memchr$qnxviui proc DIST
	jmp _memchr
endp

@memchr$qnviui	proc DIST
	jmp _memchr
endp

else ; defined __t__ or __s__ or __m__ or __f__

@memchr$qpxviui proc DIST
	jmp _memchr
endp

@memchr$qpviui	proc DIST
	jmp _memchr
endp
endif

ends

end
