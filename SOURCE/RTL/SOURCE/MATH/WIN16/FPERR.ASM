;[]-----------------------------------------------------------------[]
;|      FPERR.ASM -- Entry point for floating point exception        |
;[]-----------------------------------------------------------------[]

;
;       C/C++ Run Time Library - Version 8.0
; 
;       Copyright (c) 1987, 1997 by Borland International
;       All Rights Reserved.
; 
; $Revision:   8.2  $

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

