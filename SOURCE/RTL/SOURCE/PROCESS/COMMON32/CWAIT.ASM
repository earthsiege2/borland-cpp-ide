;----------------------------------------------------------------------
; cwait.asm - user-callable entry point to cwait() function.
;----------------------------------------------------------------------

;
;       C/C++ Run Time Library - Version 8.0
; 
;       Copyright (c) 1991, 1997 by Borland International
;       All Rights Reserved.
; 
; $Revision:   8.2  $

        include rules.asi
        include entry.inc
        Entry@ cwait, _cwait, _RTLENTRY, 12
        end
