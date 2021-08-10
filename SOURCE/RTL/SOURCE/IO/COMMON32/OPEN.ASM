;----------------------------------------------------------------------
; open.asm - user-callable entry point to open() function.
;----------------------------------------------------------------------

;
;       C/C++ Run Time Library - Version 8.0
; 
;       Copyright (c) 1991, 1997 by Borland International
;       All Rights Reserved.
; 
; $Revision:   8.3  $

        include rules.asi
        include entry.inc
        Entry@ open, __open, cdecl
        Entry@ _wopen, __wopen, cdecl
        end
