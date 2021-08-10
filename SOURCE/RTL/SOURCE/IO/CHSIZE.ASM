;----------------------------------------------------------------------
; chsize.asm - user-callable entry point to ftruncate() function.
;----------------------------------------------------------------------

;
;       C/C++ Run Time Library - Version 10.0
; 
;       Copyright (c) 1991, 2000 by Inprise Corporation
;       All Rights Reserved.
; 

; $Revision:   9.0  $

        include rules.asi
	include entry.inc
        Entry@ chsize, __ftruncate, _RTLENTRY, 8
        end
