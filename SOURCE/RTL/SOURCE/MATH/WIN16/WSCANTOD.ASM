;[]-----------------------------------------------------------------[]
;|      SCANTOD.ASM -- Ascii to double conversion                    |
;[]-----------------------------------------------------------------[]

;
;       C/C++ Run Time Library - Version 8.0
; 
;       Copyright (c) 1987, 1997 by Borland International
;       All Rights Reserved.
; 
; $Revision:   8.2  $

        INCLUDE RULES.ASI

;       External References

extrn           __cvtfak:word
extrn           __ScanTodVector:word

_TEXT   SEGMENT

                public __scantod
__scantod       proc near
                jmp     [__ScanTodVector]
                endp


                public __scanrslt
__scanrslt      proc near
                jmp     [__ScanTodVector + 2]
                endp

                public __scanpop
__scanpop       proc near
                jmp     [__ScanTodVector + 4]
                endp

_TEXT   ENDS
        END
