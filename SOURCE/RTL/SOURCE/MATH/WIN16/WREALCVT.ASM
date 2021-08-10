;[]-----------------------------------------------------------------[]
;|      REALCVT.ASM -- Real number conversion routine                |
;[]-----------------------------------------------------------------[]

;
;       C/C++ Run Time Library - Version 8.0
; 
;       Copyright (c) 1987, 1997 by Borland International
;       All Rights Reserved.
; 
; $Revision:   8.2  $

        INCLUDE RULES.ASI
        %MACS

;       External References

ExtSym@         _cvtfak, ABS, __CDECL__
extrn           __RealCvtVector:word

_TEXT   SEGMENT

                public __REALCVT
__REALCVT       proc near
                jmp     [__RealCvtVector]
                endp
_TEXT   ENDS
        END
