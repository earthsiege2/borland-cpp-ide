;[]------------------------------------------------------------[]
;|      WINTRANS.ASM                                            |
;[]------------------------------------------------------------[]

;
;       C/C++ Run Time Library - Version 8.0
; 
;       Copyright (c) 1987, 1997 by Borland International
;       All Rights Reserved.
; 
; $Revision:   8.2  $

;This module is memory model indepedent

        include RULES.ASI

emul    ; generate emulated '87 code

_TEXT   segment
        assume cs:_TEXT

        include ..\emu\equates.asi
        include ..\emu\e87trans.asm

_TEXT   ends
        end
