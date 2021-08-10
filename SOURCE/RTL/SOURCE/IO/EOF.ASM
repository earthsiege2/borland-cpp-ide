;----------------------------------------------------------------------
; eof.asm - user-callable entry point to eof() function.
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
        Entry@ eof, __eof, _RTLENTRY, 4
        end
