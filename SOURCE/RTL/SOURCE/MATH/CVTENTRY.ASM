;[]-----------------------------------------------------------------[]
;|   CVTENTRY.ASM -- real number conversion entry points             |
;[]-----------------------------------------------------------------[]

;
;       C/C++ Run Time Library - Version 11.0
; 
;       Copyright (c) 1991, 2002 by Borland Software Corporation
;       All Rights Reserved.
; 

; $Revision: 9.3 $

        include RULES.ASI

;       Segments Definitions

Header@

; Pointers to the conversion functions

Data_seg@

ifndef _UNICODE
cPtrExt@ _realcvtptr,  cdecl
cPtrExt@ _nextrealptr, cdecl
cPtrExt@ _scantodptr,  cdecl
cPtrExt@ _scanrsltptr, cdecl
else
cPtrExt@ _realcvtwptr,  cdecl
cPtrExt@ _nextrealwptr, cdecl
cPtrExt@ _scanwtodptr,  cdecl
cPtrExt@ _scanwrsltptr, cdecl
endif
Data_EndS@

; Entry points for the conversion functions

Code_seg@

ifndef _UNICODE
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
else
Func@ __realcvtw,  public, _RTLENTRY, <long val>, <int ndec>, <pointer s>, <int radx>, <char signed>, <char hex>
        jmp [_realcvtwptr@]
EndFunc@ __realcvtw

Func@ __nextrealw, public, _RTLENTRY, <pointer ap>, <int isld>
        jmp [_nextrealwptr@]
EndFunc@ __nextrealw, _RTLENTRY

Func@ _scanwtod, public, _RTLENTRY, <pointer valP>, <pointer get>, <pointer unget>, <pointer srcP>, <int wid>, <pointer cP>, <pointer stP>
        jmp [_scanwtodptr@]
EndFunc@ _scanwtod, _RTLENTRY

Func@ _scanrsltw, public, _RTLENTRY, <pointer valP>, <pointer rsltP>, <int rtype>
        jmp [_scanwrsltptr@]
EndFunc@ _scanrsltw, _RTLENTRY
endif
Code_EndS@

        end
