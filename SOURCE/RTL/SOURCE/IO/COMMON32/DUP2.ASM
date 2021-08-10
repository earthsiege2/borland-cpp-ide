;----------------------------------------------------------------------
; dup2.asm - user-callable entry point to dup2() function.
;----------------------------------------------------------------------

;
;       C/C++ Run Time Library - Version 8.0
; 
;       Copyright (c) 1991, 1997 by Borland International
;       All Rights Reserved.
; 
; $Revision:   8.2  $

        include rules.asi
	include entry.inc
        Entry@ dup2, __dup2, _RTLENTRY, 8
        end
