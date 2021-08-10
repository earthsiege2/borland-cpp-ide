;----------------------------------------------------------------------
; fputchar.asm - user-callable entry point to _fputchar() function.
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
        Entry@ fputchar, _fputchar, _RTLENTRY, 4
        end

