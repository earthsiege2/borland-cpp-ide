;-----------------------------------------------------------------------
; filename - _strstr.asm
;
; function(s)
;
; jump stubs for C++ implementation of strstr()
;-----------------------------------------------------------------------

;
;       C/C++ Run Time Library - Version 6.5
; 
;       Copyright (c) 1993, 1994 by Borland International
;       All Rights Reserved.
; 

        include rules.asi

        assume cs:_TEXT

extrn	_strstr: DIST

ifdef __l__ or __c__ or __h__
public	@strstr$qnxct1
public	@strstr$qncnxc

else ; defined __t__ or __s__ or __m__ or __f__

public	@strstr$qpxct1
public	@strstr$qpcpxc

endif

_TEXT	segment

ifdef __l__ or __c__ or __h__
@strstr$qnxct1	proc DIST
	jmp _strstr
endp

@strstr$qncnxc	proc DIST
	jmp _strstr
endp

else ; defined __t__ or __s__ or __m__ or __f__

@strstr$qpxct1	proc DIST
	jmp _strstr
endp

@strstr$qpcpxc	proc DIST
	jmp _strstr
endp
endif

ends

end
