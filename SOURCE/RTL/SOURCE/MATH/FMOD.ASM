;[]-----------------------------------------------------------------[]
;|   FMOD.ASM -- modulo function                                     |
;[]-----------------------------------------------------------------[]

;
;       C/C++ Run Time Library - Version 11.0
; 
;       Copyright (c) 1991, 2002 by Borland Software Corporation
;       All Rights Reserved.
; 

; $Revision: 9.3 $

;----------------------------------------------------------------------
; function(s)
;        fmod - calculates x modulo y, the remainder of x/y
;----------------------------------------------------------------------

        include RULES.ASI
        include _MATH.INC

;       Segments Definitions

Header@

;--------------------------------------------------------------------------
;
;Name           fmod - calculates x modulo y, the remainder of x/y
;
;Usage          double fmod(double x, double y);
;
;Prototype in   math.h
;
;Description    fmod calculates  x - (y * chop (x / y));
;               This difference can be more accurately calculated using the
;               FPREM instruction in a repeat  loop, though it is slower if
;               x/y is large.
;
;               while (not finished)  result = fprem (x, y)
;
;Return value   fmod returns x modulo y as described
;
;--------------------------------------------------------------------------

Code_Seg@

Func@   fmod, _EXPFUNC, _RTLENTRY, <double x>, <double y>
Locals@ <int status>

        Link@

        FLD     y.double

        mov     ax, y [6]
        shl     ax, 1                   ; ignore the sign bit
        jz      mod_resultZero          ; if the divisor is zero
        cmp     ax, 0FFE0h
        jnb     mod_isX                 ; if y is infinite

        FLD     x.double

        mov     ax, x [6]
        shl     ax, 1
        jz      mod_xZero               ; if x is zero
        cmp     ax, 0FFE0h
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
        FLD     x.double
        jmp     short   mod_end

; All other forms of overflow are mapped onto zero.

mod_xZero:
mod_overflow:
        FSTP    st(0)                   ; pop x off the stack
mod_resultZero:
        FSTP    st(0)                   ; pop y off the stack
        FLDZ
        jmp     short   mod_end

EndFunc@ fmod

Code_Ends@
        end
