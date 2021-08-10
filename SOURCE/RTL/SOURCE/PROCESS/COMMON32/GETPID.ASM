;----------------------------------------------------------------------
; getpid.asm - user-callable entry point to _getpid() function.
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
        Entry@ getpid, _getpid, _RTLENTRY, 0
        end
