;-----------------------------------------------------------------------
; filename - _strchr.asm
;
; function(s)
;
; jump stubs for C++ implementation of strchr()
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

extrn	_strchr: DIST

ifdef __l__ or __c__ or __h__
public	@strchr$qnxci
public	@strchr$qnci

else ; defined __t__ or __s__ or __m__ or __f__

public	@strchr$qpxci
public	@strchr$qpci

endif

_TEXT	segment

ifdef __l__ or __c__ or __h__
@strchr$qnxci	proc DIST
	jmp _strchr
endp

@strchr$qnci	proc DIST
	jmp _strchr
endp

else ; defined __t__ or __s__ or __m__ or __f__

@strchr$qpxci	proc DIST
	jmp _strchr
endp

@strchr$qpci	proc DIST
	jmp _strchr
endp
endif

ends

end
