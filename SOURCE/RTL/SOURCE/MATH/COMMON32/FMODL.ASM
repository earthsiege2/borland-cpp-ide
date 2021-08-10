;[]-----------------------------------------------------------------[]
;|   FMODL.ASM -- modulo function                                    |
;[]-----------------------------------------------------------------[]

;
;       C/C++ Run Time Library - Version 8.0
; 
;       Copyright (c) 1991, 1997 by Borland International
;       All Rights Reserved.
; 
; $Revision:   8.2  $

;----------------------------------------------------------------------
; function(s)
;        fmodl - calculates long double x modulo y, the remainder of x/y
;----------------------------------------------------------------------

        include RULES.ASI
        include _MATH.INC

;       Segments Definitions

Header@

;--------------------------------------------------------------------------
;
;Name           fmodl - calculates long double x modulo y, the remainder of x/y
;
;Usage          long double fmodl(long double x, long double y);
;
;Prototype in   math.h
;
;Description    fmodl calculates  x - (y * chop (x / y));
;               This difference can be more accurately calculated using the
;               FPREM instruction in a repeat  loop, though it is slower if
;               x/y is large.
;
;               while (not finished)  result = fprem (x, y)
;
;Return value   fmodl returns x modulo y as described
;
;--------------------------------------------------------------------------

Code_Seg@

Func@   fmodl, _EXPFUNC, _RTLENTRY, <longdouble x>, <longdouble y>
Locals@ <int status>

        Link@

        FLD     y.longdouble

        mov     ax, y [8]
        shl     ax, 1                   ; ignore the sign bit
        jz      mod_resultZero          ; if the divisor is zero
        cmp     ax, 0FFFEh
        jnb     mod_isX                 ; if y is infinite

        FLD     x.longdouble

        mov     ax, x [8]
        shl     ax, 1
        jz      mod_xZero               ; if x is zero
        cmp     ax, 0FFFEh
        jnb     mod_overflow            ; if x is infinite

mod_keepTrying:
        FPREM
        FSTSW   status.w0               ; C2 will be set if not yet finished
        FWAIT
        mov     ax,status.w0
        sahf
        jp      mod_keepTrying          ; C2 bit maps onto parity flag.

        fstp_st1                        ; discard the divisor

mod_end:
        Unlink@
        Return@

;  If the divisor is infinite then return the dividend.

mod_isX:
        FSTP    st(0)                   ; pop y off the stack
        FLD     x.longdouble
        jmp     short   mod_end

; All other forms of overflow are mapped onto zero.

mod_xZero:
mod_overflow:
        FSTP    st(0)                   ; pop x off the stack
mod_resultZero:
        FSTP    st(0)                   ; pop y off the stack
        FLDZ
        jmp     short   mod_end

EndFunc@ fmodl

Code_Ends@
        end
