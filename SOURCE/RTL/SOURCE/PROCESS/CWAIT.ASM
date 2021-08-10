;----------------------------------------------------------------------
; cwait.asm - user-callable entry point to cwait() function.
;----------------------------------------------------------------------

;
;       C/C++ Run Time Library - Version 11.0
; 
;       Copyright (c) 1991, 2002 by Borland Software Corporation
;       All Rights Reserved.
; 

; $Revision: 9.4.2.1 $

        include rules.asi
        include entry.inc
        Entry@ cwait, _cwait, _RTLENTRY, 12
        end
