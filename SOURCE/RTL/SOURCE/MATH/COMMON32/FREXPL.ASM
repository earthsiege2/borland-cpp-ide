;[]-----------------------------------------------------------------[]
;|   FREXPL.ASM -- split a long double number                        |
;[]-----------------------------------------------------------------[]

;
;       C/C++ Run Time Library - Version 1.5
; 
;       Copyright (c) 1991, 1994 by Borland International
;       All Rights Reserved.
; 

;----------------------------------------------------------------------
; function(s)
;        frexpl - splits a long double number into mantissa and exponent
;----------------------------------------------------------------------

        include RULES.ASI
        include _MATH.INC

;       Segments Definitions

Header@

;--------------------------------------------------------------------------
;
;Name            frexpl - splits a long double number into mantissa and exponent
;
;Usage           long double frexpl(long double value, int *expP);
;
;Prototype in    math.h
;
;Description     Split  a  floating  point  number  into  its  exponent and
;                fractional parts, with the exponent placed into *expP, and
;                the fraction is the function return value.
;
;Return value    frexpl returns  value - (*expP = chop (value));
;
;-------------------------------------------------------------------------

Code_Seg@

Func@   frexpl, _EXPFUNC, _RTLENTRY, <longdouble value>, <pointer expP>
Locals@ <int statword>                  ; volatile unsigned statword;

        Link@

        FLD     value.longdouble

        mov     ecx, expP
        mov     dword ptr [ecx], 0

; if value was +-0, return it

        FTST
        FSTSW   statword.w0
        FWAIT
        mov     ah, statword.by1
        sahf
        jz      done

        FXTRACT                 ; ST(1) = exponent, (pushed) ST = fraction
        FXCH

; The FXTRACT instruction normalizes the fraction 1 bit higher than
; wanted for the definition of frexpl() so we need to tweak the result
; by scaling the fraction down and incrementing the exponent.

        FISTP   dword ptr [ecx]
        FLD1
        FCHS
        FXCH
        FSCALE                  ; fraction scaled as C expects
        inc     dword ptr [ecx] ; exponent biased to match
        fstp_st1                ; discard -1, leave fraction as TOS

done:
        Unlink@
        Return@

EndFunc@ frexpl

Code_EndS@
        end
