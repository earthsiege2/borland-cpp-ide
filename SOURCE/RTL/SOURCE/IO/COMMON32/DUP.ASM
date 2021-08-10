;----------------------------------------------------------------------
; dup.asm - user-callable entry point to dup() function.
;----------------------------------------------------------------------

;
;       C/C++ Run Time Library - Version 2.0
; 
;       Copyright (c) 1991, 1996 by Borland International
;       All Rights Reserved.
; 

        include rules.asi
	include entry.inc
        Entry@ dup, __dup, _RTLENTRY, 4
        end
