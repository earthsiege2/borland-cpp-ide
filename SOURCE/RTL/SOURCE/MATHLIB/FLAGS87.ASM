;[]------------------------------------------------------------[]
;|      FLAGS87.ASM -- Coprocessor Status Storage               |
;[]------------------------------------------------------------[]

;
;       C/C++ Run Time Library - Version 6.5
; 
;       Copyright (c) 1987, 1994 by Borland International
;       All Rights Reserved.
; 

        NAME    Flags87

        INCLUDE RULES.ASI

Header@

BSeg@
PubSym@ FLAGS8087@, <dw 1 dup(?)>, __PASCAL__
BSegEnd@
        END
