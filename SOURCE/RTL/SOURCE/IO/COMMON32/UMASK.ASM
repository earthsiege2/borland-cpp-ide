;----------------------------------------------------------------------
; umask.asm - user-callable entry point to umask() function.
;----------------------------------------------------------------------

;
;       C/C++ Run Time Library - Version 2.0
; 
;       Copyright (c) 1992, 1996 by Borland International
;       All Rights Reserved.
; 

        include rules.asi
        include entry.inc
        Entry@ umask, _umask, _RTLENTRYF, 4
        end
