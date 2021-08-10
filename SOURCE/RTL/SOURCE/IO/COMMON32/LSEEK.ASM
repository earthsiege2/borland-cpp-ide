;----------------------------------------------------------------------
; lseek.asm - user-callable entry point to lseek() function.
;----------------------------------------------------------------------

;
;       C/C++ Run Time Library - Version 1.5
; 
;       Copyright (c) 1991, 1994 by Borland International
;       All Rights Reserved.
; 

        include rules.asi
	include entry.inc
        Entry@ lseek, __lseek, _RTLENTRYF, 12
        end
