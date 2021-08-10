;----------------------------------------------------------------------
; open.asm - user-callable entry point to open() function.
;----------------------------------------------------------------------

;
;       C/C++ Run Time Library - Version 2.0
; 
;       Copyright (c) 1991, 1996 by Borland International
;       All Rights Reserved.
; 

        include rules.asi
        include entry.inc
        Entry@ open, __open, cdecl
        end
