;[]-----------------------------------------------------------------[]
;|      F87EXP.ASM                                                   |
;[]-----------------------------------------------------------------[]

;
;       C/C++ Run Time Library - Version 1.5
; 
;       Copyright (c) 1986, 1994 by Borland International
;       All Rights Reserved.
; 

        include RULES.ASI
        include _MATH.INC

;       Segments Definitions

Header@

; 11 Sep 88     Tanj    unified sources from TB and TC/TP
; 15 Dec 88     tanj    alternative form of NANs for TestaRossa
;  4 Mar 89     Roger   expand domain for Exp()
; 22 Jul 89     Roger   handle INF and NAN in Exp()
; 18 Sep 89     Roger   handle INF in Log()
; 17 Nov 89     Roger   handle NAN in Log(), slight Exp() optimization
;  1 Jun 90     Dave S  adapt to Windows C RTL
; 26 Aug 91     Mark A  adapt to OS/2 C RTL

;----------------------------------------------------------------------
; Special constants are placed here.

Const_Seg@

half            dd      03F000000r

sqrt2           dt      3FFFB504F333F9DE6485r

infinity        dd      7F800000R               ; plus infinity

Const_EndS@


;----------------------------------------------------------------------
; General notes:

; - operands are on the iNDP stack
; - results will be on the iNDP stack
; - EAX,EBX,ECX,EDX may be consumed.  Others must be preserved.
; - unnormals are not specifically processed because this module is
;       intended to work with HLL's which place results into IEEE
;       "double" format, whereas only the IEEE "temporary" format can
;       handle unnormals.  If you want to run with assembler programs
;       that may use unnormals then you should check these algorithms
;       for what happens with un-normal parameters.  De-normals are
;       processed correctly, since they have been arranged to follow
;       the same paths as zeroes with only slight extra care needed to
;       accomodate them.

Code_seg@

;----------------------------------------------------------------------
; Exp2, Exp10, and Exp

; Exp2 (X) = 2^(X)

Func@ _f87_Exp2, public, _RTLENTRY
        sub     cx, cx                  ; scale not needed
        jmp     short   DoExps
EndFunc@ _f87_Exp2

; Exp10 (X) = 2^(X * Log2of10)

Func@ _f87_Exp10, public, _RTLENTRY
        fldl2t
        mov     cl, 1                   ; scaling is needed
        fxch
        jmp     short   DoExps
EndFunc@ _f87_Exp10

; Exp (X) = 2^(X * Log2ofE)

Func@ _f87_Exp, public, _RTLENTRY
        fldl2e
        mov     cl, 1                   ; scaling is needed
        fxch
;       jmp     short   DoExps
; fall thru

; Use the following method:

; The basic limitation of X2M1 is that it accepts parameters only in the
; range 0 <= X <= 0.5.  Thus we must reduce the parameter to that range.
; Another limitation is that we shall consider any parameter of more than
; 2047 to generate an infinite result, since the result is too large to
; express in the long IEEE format.

; (Q, R) := Rem (X, 0.5);

; { X = Q/2 + R exactly, and 0 <= R < 0.5 }

; 2^X   = 2^(Q/2 + R)
;       = 2^(Q/2) * 2^R
;       = 2^(Q DIV 2) * (Sqrt(2))^(Q MOD 2) * 2^R

; Each of those three terms is easily calculated.
; The first term is a fraction of 0.5 with exponent (Q DIV 2) + 1.
; The second term is a choice of constants 1.0 or Sqrt(2).
; The third is  1 + 2XM1 (R).


exp_term1       equ     [esp].w0
exp_status      equ     [esp+2].w0

DoExps:

;       jcxz    exp_swapped
;       fxch
;exp_swapped:
        fxam

        sub     esp,4                   ; make room for exp_term1, exp_status

        fstsw   exp_status
        jcxz    exp_deppaws
        fxch
exp_deppaws:
        wait
        mov     ah, exp_status.by1
        sahf                            ; FL now reflects FXAM status
        xchg    bx, ax                  ; save parameter's sign
        jc      exp_badParam
        jnz     exp_normal

exp_tiny:                               ; denormal or zero
        fstp    st(0)                   ; pop TOS
        jcxz    exp_result1             ; was there a scale factor also ?
        fstp    st(0)
exp_result1:
        fld1
        jmp     exp_end

exp_badParam:                           ; NAN, infinite, or Empty
        jcxz    exp_badNowTos           ; was there a scale factor also ?
        fstp    st(0)                   ; pop TOS
exp_badNowTos:
        jz      exp_empty               ; st(0) was empty
        jnp     exp_NAN                 ; st(0) was NAN

exp_tooBig:
        fstp    st(0)                   ; pop st(0)
        fld     infinity
        jmp     exp_setSign

exp_NAN:
exp_empty:
        ftst                            ; trigger exception
        jmp     exp_end

exp_normal:
        jcxz    exp_scaled
        fmul

exp_scaled:
        fabs
        fcom    half
        fstsw   exp_status
        wait
        test    exp_status.by1, 41h
        jz      exp_notSimpleRange

; We can run |st(0)| <= 0.5 as a special case because it is quick and easy.

        f2xm1
        fld1
        fadd
        jmp     short   exp_setSign

; to get a rapid division by 0.5 we double and truncate.

exp_notSimpleRange:
        fld1
        fld     st(1)
        fstcw   exp_status
        fscale
        or      exp_status.by1, 0Fh     ; specify truncation mode
        fldcw   exp_status
        frndint
        and     exp_status.by1, 0F3h    ; default back to round-nearest
        fldcw   exp_status
        fist    exp_term1

; then to obtain the remainder we scale back to normal and
;       subtract from the original.

        fxch
        fchs
        fxch
        fscale
        fstp_st1                ; fscale did not adjust stack
        fsub                    ; st(0) is now 0 <= R < 0.5

; is this test useful?
;       cmp     exp_term1, 4095
;       jg      exp_tooBig

; now we are into the final section.  First calculate the
;       exponent of TOS, the remainder.

        f2xm1
        fld1
        fadd                    ; calculated third term, 2^R

        shr     exp_term1, 1
        jnc     exp_noHalf

        fld     sqrt2           ; multiply by second term
        fmul

exp_noHalf:
        fild    exp_term1
        fxch
        fscale                  ; multiply by first term, 2^(Q DIV 2)
        fstp_st1                ; (fscale doesn't adjust stack)


exp_setSign:
        test    bh, 02          ; was original parameter negative ?
        jz      exp_end         ; jump if it was positive

        fld1
        fdivr

exp_end:
        add     esp,4
        ret

EndFunc@ _f87_Exp

Code_EndS@

        end
