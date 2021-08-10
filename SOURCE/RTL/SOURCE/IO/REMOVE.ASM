;----------------------------------------------------------------------
; remove.asm - user-callable entry point to _unlink() function.
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
        Entry@ remove, _unlink, _RTLENTRYF, 4
        Entry@ _wremove, _wunlink, _RTLENTRYF, 4
        end
