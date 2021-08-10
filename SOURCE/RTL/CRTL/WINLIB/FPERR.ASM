;[]-----------------------------------------------------------------[]
;|      FPERR.ASM -- Entry point for floating point exception        |
;[]-----------------------------------------------------------------[]

;
;       C/C++ Run Time Library - Version 6.0
; 
;       Copyright (c) 1987, 1993 by Borland International
;       All Rights Reserved.
; 

;This module is memory model indepedent

                include RULES.ASI

                extrn __GetDGROUP:far
                extrn __FpeHandler:DIST

_TEXT           segment
                assume cs:_TEXT

                public  __fperr

__fperr         proc    far
                push    ds
                push    ax
                call    __GetDGROUP
                mov     ds, ax
                call    __FpeHandler
                pop     ax
                pop     ds
                ret
__fperr         endp

                ends
                end

