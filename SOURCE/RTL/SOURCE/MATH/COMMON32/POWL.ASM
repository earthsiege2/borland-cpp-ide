;[]-----------------------------------------------------------------[]
;|   POWL.ASM -- long double power function                          |
;[]-----------------------------------------------------------------[]

;
;       C/C++ Run Time Library - Version 1.5
; 
;       Copyright (c) 1991, 1994 by Borland International
;       All Rights Reserved.
; 

;----------------------------------------------------------------------
; function(s)
;        powl - long double power function, x^y
;----------------------------------------------------------------------

        include RULES.ASI
        include _MATH.INC

;       Segments Definitions

Header@


;----------------------------------------------------------------------
; External variables

Data_Seg@

ExtSym@         _huge_ldble, tbyte, cdecl
_LHUGE_VAL      equ     _huge_ldble@

ifdef MASM
zero    dw      0,0,0,0,0               ; was dt 0.0, but NT MASM386 blows up
one     dw      0,0,0,8000h,3fffh       ; was dt 1.0, but NT MASM386 blows up
else
zero    dt      0.0
one     dt      1.0
endif

NANLOGL dw      0,0,0,0C024H,0FFFFH

Data_EndS@

;--------------------------------------------------------------------------
;
;Name            powl - power function, x^y
;
;Usage           long double powl(long double x, long double y);
;
;Prototype in    math.h
;
;Description     Return the value of x to the  power of y. If x is zero then
;                y must be  positive, and if  x is negative  then y must  be
;                integral.
;
;                First the special cases  Y == 0 or X == 0  or X == infinity
;                are detected and given standard answers.
;
;                Two methods of calculation are used, depending upon whether
;                Y is an integer of less than 64 bits. If not, then
;
;                        X^Y = 2^(Log2(X) * Y)
;                            = DoExps ( DoLogs (X, Y), not scaled)
;
;                If Y is  an integer then it can be  represented as a binary
;                number
;
;                        Y = B0 + B1.2 + B2.+ .. Bn.2^n
;
;                where the  B coefficients are 0  or 1, and Bn  is always 1,
;                for some n. The power of X is then calculated as:
;
;                        Z = X;
;                        while (n-- > 0)
;                                Z *= Z;
;                                if (Bn) Z *= X;
;
;                which is  the standard trick  for fast integral  powers. It
;                works for any X, positive or negative, if Y is not zero. In
;                practice  it will  run faster than the  DoExps (DoLogs())
;                method for  |Y|  <  100,  roughly,  and  slower for larger
;                powers. Such large powers are very rare in actual usage.
;
;                Powers greater  than  2^64  in  theory  may  be  integers.
;                However,  it is  also likely  that such  large numbers have
;                lost  precision (especially  when you  consider that  the C
;                data  type "long double" is 53 bits precise).  These will be
;                treated as if  fractional. If X is positive  and very close
;                to  1.0,  then an  answer  may  be  possible, but if X is
;                negative an  exception is generated. The  rationale for the
;                exception is  that if the  least bits of  Y have been  lost
;                then  it is  not possible   to be  sure whether  the result
;                should be positive or negative, so there is a total loss of
;                precision.
;
;Return value    Return the value of x to the power of y.
;                When  the correct  value  would  overflow, powl returns the
;                value _LHUGE_VAL.
;
;                If the argument x passed to powl  is less than or equal to 0
;                and y  is not a whole  number, then errno is set to
;                        EDOM    Domain error
;
;                If x and y are both zero, then the return value is 1.0 and
;                there is no error.  Many C compilers consider this a DOMAIN
;                error as technically 0^0 is undefined.  There are continuous
;                function f(x) and g(x) such that f(0) = 0 and g(0) = 0, but
;                with the limit of f(x)/g(x) as x tends to 0 being any real
;                number.  However, there is an elementary theorem that states
;                that f(x) and g(x) are analytic and nonzero, then the limit
;                is always 1.  Thus in a finite precision computing
;                environment, it is hard to imagine a situation where a
;                number other than 1 is desirable.
;
;--------------------------------------------------------------------------

Code_Seg@

Func@   powl, _EXPFUNC, _RTLENTRY, <longdouble x>, <longdouble y>
Locals@ <longdouble temp>,<word sword>,<word negate>

;       long double temp;           ; also used as a 64-bit integer
;       unsigned    sword;          ; status-word from testing y
;       char        negate = 0;     ; boolean, negate after exp() ?

        Link@   ebx

        mov     negate.by0, 0
        FLD     x.longdouble
        mov     bx, 7FFFh                       ; mask just the exponent
        mov     ax, x [8]
        and     ax, bx
        jz      pow_ofZero
        cmp     ax, bx
        je      pow_ofInfinity

        FLD     y.longdouble
        mov     ax, y [8]
        and     ax, bx
        jz      pow_toZero
        cmp     ax, bx
        je      pow_toInfinity
        jmp     pow_normal


;**            Special cases           **
;
;  Raising any number to infinity is treated as a range error.

pow_toInfinity:
        FSTP    temp.longdouble                 ; propagate Y thru to result
        jmp     short   pow_discard

;  Powers of infinity are range errors.

pow_ofInfinity:
        FSTP    temp.longdouble                 ; propagate X thru to result
        mov     ax, y[8]
        or      ax, ax
        jge     pow_overflow                    ; jump if exponent nonnegative
        mov     edx, UNDERFLOW
        mov     ecx, offset FLAT: zero
;       temp = 0.0;
        jmp     short   pow_complain

; Arrive here if Y is zero.  The zero'th power of any number is 1.

pow_toZero:
        FSTP    ST(0)                           ; discard Y
        FSTP    ST(0)                           ; discard X
;       return (1.0);
        FLD1
        jmp     pow_end

pow_discard:
        FSTP    ST(0)                           ; discard X

pow_overflow:
        mov     edx, OVERFLOW
        lea     ecx, temp
        jmp     short   pow_complain

;  Powers of 0 are (EDOM, 1, 0) as Y ranges over (negative, zero, positive).

pow_ofZero:
        FSTP    ST(0)                           ; discard  X
        mov     ax, y [8]
        or      ax, ax                          ; was Y positive ?
        jg      pow_zero
        mov     edx, DOMAIN
        je      pow_zz
;       temp = _LHUGE_VAL;
        mov     ecx, offset FLAT: _LHUGE_VAL
        jmp     short   pow_complain

pow_zz:
;       temp = 1.0;
        mov     ecx, offset FLAT: one

pow_complain:
;       return  __matherrl (EDX, "powl", &x, &y, [ECX]);
        matherrl edx, powl, x, y, [ecx]
        jmp     pow_end

pow_zero:
;       return 0.0
        FLDZ
        jmp     pow_end

;**            End of Special Cases            **


; If arrived here then both x and y seem to be ordinary numbers.

pow_normal:
        FCLEX
        FRNDINT
        FSTSW   sword.w0                ; is Y an integer
        FWAIT
        test    sword.by0, 20h          ; precision error if not
        jz      pow_integral
        FSTP    ST(0)                   ; discard Y

; Arrive here if the exponent exceeds integer range or if it contains
; a fractional part.  Calculate using Log and Exp functions.  Just
; x is on 87-stack.


pow_fractional:
; make sure that x > 0
        FTST
        FSTSW   sword.w0                ; is Y an integer
        FWAIT
        mov     ax, sword
        sahf
        jae     pow_log
        FSTP    ST(0)

;       temp = *((long double *) NANLOGL);
        mov     edx, DOMAIN
        mov     ecx, offset FLAT: NANLOGL
        jmp     short   pow_complain

pow_log:
; arg is > 0, so log cannot fail

        f87     Log
        FLD     y.longdouble
        FMUL
        FSTP    temp.longdouble
        mov     ax, temp [8]            ; select exponent
        and     ah, 7Fh                 ; remove sign big
        cmp     ax, 3fffh+13
        jb      exp_justFits            ; exp (+-2^13) is limit for longdouble

exp_tooBig:
        mov     ax, 0FFFFh              ; force extreme
        ja      exp_excess
        mov     ax, temp [6]

exp_excess:
        test    BY0 (temp [9]), 80h
        jnz     exp_tooTiny
        cmp     ax, 0B172h
        jb      exp_justFits
        mov     edx, OVERFLOW
        mov     ecx, offset FLAT: _LHUGE_VAL
        jmp     pow_complain

exp_tooTiny:
        cmp     ax, 0B16Ch
        jb      exp_justFits
        mov     edx, UNDERFLOW
        mov     ecx, offset FLAT: zero
        jmp     pow_complain

exp_justFits:
        FLD     temp.longdouble
        f87     Exp

;       if (negate) FCHS;
        cmp     negate.by0, 0
        je      pow_end2
        FCHS
pow_end2:
        jmp     pow_end

; If arrived here then Y is some integer of up to 64 bits and has
; been copied to temp. Y is ST(0), X is ST(1), AX is exponent of Y.

pow_integral:
        sub     ax, 3FFFh                       ; remove the bias
        cmp     ax, 63                          ; AX = n, the exponent
        jb      pow_trueIntegral
        FSTP    ST(0)                           ; discard Y
        jmp     pow_fractional

; The shift-and-add method is not accurate for extreme powers since
; round off errors are magnified.  However, we cannot simply call for
; evaluation like fractional powers because X may be negative and
; fractional negative powers are treated as exceptions.

pow_trueIntegral:
        cmp     al, 12
        jb      pow_shiftAndAdd
pow_unsafeRange:
        FISTP   qword ptr (temp)                ; store an integer copy of Y
        test    BY0 (x [9]), 80h                ; X less than 0 ?
        jz      pow_fractional                  ; X not signed, so no worry
        FCHS                                    ; make X absolute
        test    BY0 (temp), 01h                 ; odd or even ?
        jz      pow_fractional                  ; even powers are positive

; If we arrive here then X was negative and Y was odd.  Calculate with
; abs(X) and then negate result.

;       negate = 1;
        mov     negate.by0, 1
        jmp     pow_fractional


; Arrive here for modest integral powers of any number.  We must also
; check for overflow, by making a worst-case check on log (X^Y).  If
; it has a potential to overflow, then we use the exp(log()) method.

pow_shiftAndAdd:
        mov     bx, x [8]
        shl     bx, 1
        sub     bx, 7FFEh                       ; BX estimates log2 (X)
        mov     dx, bx
        xchg    cx, ax
        inc     cx                              ; 2^CL is max possible Y
        shl     bx, cl                          ; multiply BX by max Y
        sar     bx, cl
        dec     cx
        xchg    ax, cx
        cmp     bx, dx                          ; did BX lose any bits ?
        jne     pow_unsafeRange

        FLD     ST (1)                          ; Z = X
        mov     dx, y [6]                       ; top 16 bits of fraction
        shl     dx, 1

pow_iWhileBit:
        dec     al
        jl      pow_maybeInverse

        FMUL    ST(0), ST(0)                    ; Z *= Z

        shl     dx, 1
        jnc     pow_iWhileBit

        FMUL    ST(0), ST(2)                    ; Z *= X

        jmp     short   pow_iWhileBit

pow_maybeInverse:
        fstp_st1                                ; overwrite Y
        test    BY0 (y [9]), 80h                ; was Y a negative power ?
        fstp_st1                                ; overwrite X
        jz      pow_iDone
        FLD1
        FDIVRP  ST(1), ST(0)                    ;   if so, invert result.
pow_iDone:
pow_end:
        Unlink@ ebx
        Return@

EndFunc@ powl

Code_EndS@

        end
