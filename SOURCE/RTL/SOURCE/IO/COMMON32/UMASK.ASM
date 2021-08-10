;----------------------------------------------------------------------
; umask.asm - user-callable entry point to umask() function.
;----------------------------------------------------------------------

;
;       C/C++ Run Time Library - Version 1.5
; 
;       Copyright (c) 1992, 1994 by Borland International
;       All Rights Reserved.
; 

        include rules.asi
        include entry.inc
        Entry@ umask, _umask, _RTLENTRYF, 4
        end
