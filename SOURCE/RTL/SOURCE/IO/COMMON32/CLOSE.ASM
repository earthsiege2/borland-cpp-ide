;----------------------------------------------------------------------
; close.asm - user-callable entry point to close() function.
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
        Entry@ close, __close, _RTLENTRYF, 4
        end
