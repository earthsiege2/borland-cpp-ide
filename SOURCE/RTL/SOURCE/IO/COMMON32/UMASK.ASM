;----------------------------------------------------------------------
; umask.asm - user-callable entry point to umask() function.
;----------------------------------------------------------------------

;
;       C/C++ Run Time Library - Version 8.0
; 
;       Copyright (c) 1992, 1997 by Borland International
;       All Rights Reserved.
; 
; $Revision:   8.2  $

        include rules.asi
        include entry.inc
        Entry@ umask, _umask, _RTLENTRYF, 4
        end
