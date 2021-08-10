;----------------------------------------------------------------------
; write.asm - user-callable entry point to write() function.
;----------------------------------------------------------------------

;
;       C/C++ Run Time Library - Version 11.0
; 
;       Copyright (c) 1991, 2002 by Borland Software Corporation
;       All Rights Reserved.
; 

; $Revision: 9.3 $

        include rules.asi
	include entry.inc
        Entry@ write, __write, _RTLENTRYF, 12
        end
