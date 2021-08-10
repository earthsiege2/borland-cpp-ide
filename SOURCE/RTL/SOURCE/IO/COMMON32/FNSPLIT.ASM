;----------------------------------------------------------------------
; fnsplit.asm - user-callable entry point to _fnsplit() function.
;----------------------------------------------------------------------

;
;       C/C++ Run Time Library - Version 1.5
; 
;       Copyright (c) 1991, 1994 by Borland International
;       All Rights Reserved.
; 

        include rules.asi
	include entry.inc
        Entry@ fnsplit, _fnsplit, _RTLENTRYF, 20
        end
