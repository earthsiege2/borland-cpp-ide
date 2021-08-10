;----------------------------------------------------------------------
; umask.asm - user-callable entry point to umask() function.
;----------------------------------------------------------------------

;
;       C/C++ Run Time Library - Version 10.0
; 
;       Copyright (c) 1992, 2000 by Inprise Corporation
;       All Rights Reserved.
; 

; $Revision:   9.0  $

        include rules.asi
        include entry.inc
        Entry@ umask, _umask, _RTLENTRYF, 4
        end
