;-----------------------------------------------------------------------
; filename - _strrchr.asm
;
; function(s)
;
; jump stubs for C++ implementation of strrchr()
;-----------------------------------------------------------------------

;
;       C/C++ Run Time Library - Version 7.0
; 
;       Copyright (c) 1993, 1996 by Borland International
;       All Rights Reserved.
; 

        include rules.asi

        assume cs:_TEXT

extrn	_strrchr: DIST

ifdef __l__ or __c__ or __h__
public	@strrchr$qnxci
public	@strrchr$qnci

else ; defined __t__ or __s__ or __m__ or __f__

public	@strrchr$qpxci
public	@strrchr$qpci

endif

_TEXT	segment

ifdef __l__ or __c__ or __h__
@strrchr$qnxci	proc DIST
	jmp _strrchr
endp

@strrchr$qnci	proc DIST
	jmp _strrchr
endp

else ; defined __t__ or __s__ or __m__ or __f__

@strrchr$qpxci	proc DIST
	jmp _strrchr
endp

@strrchr$qpci	proc DIST
	jmp _strrchr
endp
endif

ends

end
