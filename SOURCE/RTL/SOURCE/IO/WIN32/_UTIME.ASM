;----------------------------------------------------------------------
; utime.asm - user-callable entry point to _utime() function.
;----------------------------------------------------------------------

;
;       C/C++ Run Time Library - Version 8.0
; 
;       Copyright (c) 1996, 1997 by Borland International
;       All Rights Reserved.
; 
; $Revision:   8.0  $

        include rules.asi
	include entry.inc
        Entry@ utime, _utime, _RTLENTRY, 4
        end

