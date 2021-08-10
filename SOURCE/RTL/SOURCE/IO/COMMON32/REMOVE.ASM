;----------------------------------------------------------------------
; remove.asm - user-callable entry point to _unlink() function.
;----------------------------------------------------------------------

;
;       C/C++ Run Time Library - Version 8.0
; 
;       Copyright (c) 1991, 1997 by Borland International
;       All Rights Reserved.
; 
; $Revision:   8.4  $

        include rules.asi
        include entry.inc
        Entry@ remove, _unlink, _RTLENTRYF, 4
        Entry@ _wremove, _wunlink, _RTLENTRYF, 4
        end
