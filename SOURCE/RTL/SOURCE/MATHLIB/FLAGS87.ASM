;[]------------------------------------------------------------[]
;|      FLAGS87.ASM -- Coprocessor Status Storage               |
;[]------------------------------------------------------------[]

;
;       C/C++ Run Time Library - Version 8.0
; 
;       Copyright (c) 1987, 1997 by Borland International
;       All Rights Reserved.
; 
; $Revision:   8.2  $

        NAME    Flags87

        INCLUDE RULES.ASI

Header@

BSeg@
PubSym@ FLAGS8087@, <dw 1 dup(?)>, __PASCAL__
BSegEnd@
        END
