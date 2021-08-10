;[]-----------------------------------------------------------------[]
;|   DIV.ASM -- integer division                                     |
;[]-----------------------------------------------------------------[]

;
;       C/C++ Run Time Library - Version 1.5
; 
;       Copyright (c) 1991, 1994 by Borland International
;       All Rights Reserved.
; 

        include RULES.ASI

;       Segments Definitions

Header@

; Definition of div_t must match that in stdlib.h

div_t   STRUC
quot    dd      ?
rem     dd      ?
div_t   ENDS

;-----------------------------------------------------------------------
;
;Name           div - integer division
;               ldiv - long integer division
;
;Usage          div_t div(int numer, int denom);
;               ldiv_t ldiv(long numer, long denom);
;
;Prototype in   stdlib.h
;
;Description    div computes the quotient and  remainder of the division of
;               the numerator  "numer" by the  denominator "denom". If  the
;               result cannot be represented, the behavior is undefined.
;
;               ldiv is similar, except that it operates on long integers.
;
;Return value   div returns a structure of  type div_t, comprising both the
;               quotient and the remainder.  ldiv returns a similar structure
;               of type ldiv_t, whose members are long integers.
;
;-----------------------------------------------------------------------

Code_seg@

Func@   ldiv, _EXPFUNC, _RTLENTRY, <pointer retval>,<long numer>,<long denom>

        ; drop into div -- long is the same size as int

EndFunc@ ldiv

Func@   div, _EXPFUNC, _RTLENTRY, <pointer retval>,<int numer>,<int denom>

        Link@

        mov     eax,numer               ; get numerator
        cdq                             ; convert to quadword EDX:EAX
        idiv    dword ptr denom         ; EAX = quotient, EDX = remainder
        mov     ecx,retval              ; get pointer to return value
        mov     [ecx].quot, eax         ; fill in the div_t structure
        mov     [ecx].rem, edx
        mov     eax, ecx                ; return pointer to ret. value

        Unlink@
        Return@

EndFunc@ div

Code_EndS@

        end
