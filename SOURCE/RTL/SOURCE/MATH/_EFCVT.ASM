;----------------------------------------------------------------------
; _efcvt.asm - user-callable entry points to _ecvt() and _fcvt() functions.
;----------------------------------------------------------------------

;
;       C/C++ Run Time Library - Version 10.0
; 
;       Copyright (c) 1996, 2000 by Inprise Corporation
;       All Rights Reserved.
; 

; $Revision:   9.0  $

        include rules.asi
	include entry.inc
        Entry@ ecvt, _ecvt, _RTLENTRY, 16
        Entry@ fcvt, _fcvt, _RTLENTRY, 16
        end

