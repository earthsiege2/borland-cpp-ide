;-----------------------------------------------------------------------
; filename - _strpbrk.asm
;
; function(s)
;
; jump stubs for C++ implementation of strpbrk()
;-----------------------------------------------------------------------

;
;       C/C++ Run Time Library - Version 8.0
; 
;       Copyright (c) 1993, 1997 by Borland International
;       All Rights Reserved.
; 
; $Revision:   8.2  $


        include rules.asi

        assume cs:_TEXT

extrn	_strpbrk	: DIST

ifdef __l__ or __c__ or __h__
public	@strpbrk$qnxct1
public	@strpbrk$qncnxc

else ; defined __t__ or __s__ or __m__ or __f__

public	@strpbrk$qpxct1
public	@strpbrk$qpcpxc

endif

_TEXT	segment

ifdef __l__ or __c__ or __h__
@strpbrk$qnxct1 proc DIST
	jmp _strpbrk
endp

@strpbrk$qncnxc	proc DIST
	jmp _strpbrk
endp

else ; defined __t__ or __s__ or __m__ or __f__

@strpbrk$qpxct1 proc DIST
	jmp _strpbrk
endp

@strpbrk$qpcpxc	proc DIST
	jmp _strpbrk
endp
endif

ends

end
