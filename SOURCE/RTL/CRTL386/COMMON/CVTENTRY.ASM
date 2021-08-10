;[]-----------------------------------------------------------------[]
;|   CVTENTRY.ASM -- real number conversion entry points             |
;[]-----------------------------------------------------------------[]

;
;       C/C++ Run Time Library - Version 6.0
; 
;       Copyright (c) 1991, 1993 by Borland International
;       All Rights Reserved.
; 

        include RULES.ASI

;       Segments Definitions

Header@

; Pointers to the conversion functions

Data_seg@

cPtrExt@ _realcvtptr,  cdecl
cPtrExt@ _nextrealptr, cdecl
cPtrExt@ _scantodptr,  cdecl
cPtrExt@ _scanrsltptr, cdecl

Data_EndS@

; Entry points for the conversion functions

Code_seg@

Func@ __realcvt,  public, _RTLENTRY, <long val>, <int ndec>, <pointer s>, <int radx>, <char signed>, <char hex>
        jmp [_realcvtptr@]
EndFunc@ __realcvt

Func@ __nextreal, public, _RTLENTRY, <pointer ap>, <int isld>
        jmp [_nextrealptr@]
EndFunc@ __nextreal, _RTLENTRY

Func@ _scantod, public, _RTLENTRY, <pointer valP>, <pointer get>, <pointer unget>, <pointer srcP>, <int wid>, <pointer cP>, <pointer stP>
        jmp [_scantodptr@]
EndFunc@ _scantod, _RTLENTRY

Func@ _scanrslt, public, _RTLENTRY, <pointer valP>, <pointer rsltP>, <int rtype>
        jmp [_scanrsltptr@]
EndFunc@ _scanrslt, _RTLENTRY

Code_EndS@

        end
