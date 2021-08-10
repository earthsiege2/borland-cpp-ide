;----------------------------------------------------------------------
; dup2.asm - user-callable entry point to dup2() function.
;----------------------------------------------------------------------

;
;       C/C++ Run Time Library - Version 1.5
; 
;       Copyright (c) 1991, 1994 by Borland International
;       All Rights Reserved.
; 

        include rules.asi
	include entry.inc
        Entry@ dup2, __dup2, _RTLENTRY, 8
        end
