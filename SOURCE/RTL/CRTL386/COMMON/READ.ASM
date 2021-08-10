;----------------------------------------------------------------------
; read.asm - user-callable entry point to read() function.
;----------------------------------------------------------------------

;
;       C/C++ Run Time Library - Version 6.0
; 
;       Copyright (c) 1991, 1993 by Borland International
;       All Rights Reserved.
; 

        include rules.asi
	include entry.inc
        Entry@ read, __read, _RTLENTRYF, 12
        end
