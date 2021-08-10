;[]-----------------------------------------------------------------[]
;|   FREXP.ASM -- split a double number                              |
;[]-----------------------------------------------------------------[]

;
;       C/C++ Run Time Library - Version 6.0
; 
;       Copyright (c) 1991, 1993 by Borland International
;       All Rights Reserved.
; 

;----------------------------------------------------------------------
; function(s)
;        frexp - splits a double number into mantissa and exponent
;----------------------------------------------------------------------

        include RULES.ASI
        include _MATH.INC

;       Segments Definitions

Header@

;--------------------------------------------------------------------------
;
;Name            frexp - splits a double number into mantissa and exponent
;
;Usage           double frexp(double value, int *expP);
;
;Prototype in    math.h
;
;Description     Split  a  floating  point  number  into  its  exponent and
;                fractional parts, with the exponent placed into *expP, and
;                the fraction is the function return value.
;
;Return value    frexp returns  value - (*expP = chop (value));
;
;-------------------------------------------------------------------------

Code_Seg@

Func@   frexp, _EXPFUNC, _RTLENTRY, <double value> <pointer expP>
Locals@ <int statword>                  ; volatile unsigned statword;

        Link@

        FLD     value.double

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
; wanted for the definition of frexp() so we need to tweak the result
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

EndFunc@ frexp

Code_EndS@
        end
