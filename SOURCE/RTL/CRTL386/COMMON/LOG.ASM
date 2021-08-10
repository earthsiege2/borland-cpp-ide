;[]-----------------------------------------------------------------[]
;|   LOG.ASM -- natural logarithm                                    |
;[]-----------------------------------------------------------------[]

;
;       C/C++ Run Time Library - Version 6.0
; 
;       Copyright (c) 1991, 1993 by Borland International
;       All Rights Reserved.
; 

;----------------------------------------------------------------------
; function(s)
;        log - natural logarithm function
;----------------------------------------------------------------------

        include RULES.ASI
        include _MATH.INC

;       Segments Definitions

Header@

;----------------------------------------------------------------------
; External and local variables

Data_Seg@

ExtSym@         _huge_dble, qword, cdecl
HUGE_VAL        equ     _huge_dble@

NANLOG          dw      0,0,00480H, 0FFF8H

Data_EndS@

;--------------------------------------------------------------------------
;
;Name            log - natural logarithm function
;
;Usage           double log(double x);
;
;Prototype in    math.h
;
;Description     log calculates  the natural logarithm of x, which must be
;                greater than zero.
;
;Return value    log  returns the  natural logarithm of x, which must be
;                greater than zero.
;
;--------------------------------------------------------------------------

Code_Seg@

Func@   log, _EXPFUNC, _RTLENTRY, <double x>
Locals@ <double temp>

        Link@   ebx

        FLD     x.double

        mov     ax, W0 (x [6])          ; get the exponent field
        shl     ax, 1
        jz      log_zero
        jc      log_imaginary
        cmp     ax, 0FFE0h
        je      log_infinite

        f87     Log
log_end:
        Unlink@ ebx
        Return@

log_zero:
        mov     edx, SING
        fld     HUGE_VAL.double         ; temp = -HUGE_VAL;
        fchs
        fstp    temp.double
        lea     ecx, temp
        jmp     short   log_complain

log_infinite:
        mov     edx, OVERFLOW
        mov     ecx, offset FLAT: HUGE_VAL
        jmp     short   log_complain

log_imaginary:
        mov     edx, DOMAIN
        mov     ecx, offset FLAT: NANLOG

log_complain:
        FSTP    ST(0)                   ; pop x from stack

;       return  __matherr (_EDX, "log", &x, NULL, *(double *)_ECX);

        matherr edx, log, x, NULL, [ecx]
        jmp     log_end

EndFunc@ log

Code_EndS@
        end
