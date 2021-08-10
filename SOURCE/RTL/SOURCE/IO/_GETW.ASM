;----------------------------------------------------------------------
; getw.asm - user-callable entry point to _getw() function.
;----------------------------------------------------------------------

;
;       C/C++ Run Time Library - Version 11.0
; 
;       Copyright (c) 1996, 2002 by Borland Software Corporation
;       All Rights Reserved.
; 

; $Revision: 9.4.2.1 $

        include rules.asi
	include entry.inc
        Entry@ getw, _getw, _RTLENTRY, 4
        end

