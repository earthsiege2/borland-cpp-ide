;[]-----------------------------------------------------------------[]
;|   ACOSASINL.ASM -- trigonometric functions                        |
;[]-----------------------------------------------------------------[]

;
;       C/C++ Run Time Library - Version 1.5
; 
;       Copyright (c) 1991, 1994 by Borland International
;       All Rights Reserved.
; 

;----------------------------------------------------------------------
; function(s)
;        AcosAsinl - compute acosl or asinl
;        acosl     - trigonometric function
;        asinl     - trigonometric function
;----------------------------------------------------------------------

        include RULES.ASI
        include _MATH.INC

;       Segments Definitions

Header@


Data_Seg@

piBy2           dw      0C235H, 02168H, 0DAA2H, 0C90FH, 03FFFH
NANINVTRIGL     dw      00000H, 00000H, 00000H, 0C022H, 07FFFH

Data_EndS@

;---------------------------------------------------------------------
;
;Name           AcosAsinl - compute sin or cos
;
;Usage          long double AcosAsinl (char *whoS, bits16 flags,
;                                       long double *xP);
;
;Description    Computes acosl or sinl of the number pointed to by xP.
;               whoS is the name of the function.  flags is 0 for asinl
;               and non-zero for acosl.
;
;Return value   Returns acosl or asinl of xP.
;
;---------------------------------------------------------------------

Code_Seg@

; static long double AcosAsin(char *whoS, bits15 flags, long double *xp)
; {     volatile bits16 status; volatile int temp;

Func@   AcosAsinl, static, _RTLENTRY, <pointer whos>,<int flags>,<pointer xP>
Locals@ <word status>,<word temp>

        Link@   esi
        mov     dx, flags               ; DH = 0, DL = flags
        mov     esi, xP

        mov     cx, [esi+8]             ; get sign/exponent word
        and     BY0 ([esi+9]), 07Fh     ; absolute value
        fld     LONGDOUBLE ([esi])

        shl     cx, 1
        rcr     dh, 1                   ; DH = sign bit
        jcxz    acs_zero

        cmp     cx, 7FFEh               ; biased exponent of 1.0
        jnb     acs_extreme

; Use the trig identity asin (x) = atan (x / sqrt (1 - x^2)).

        FLD1
        FLD     ST(1)                   ; duplicate X
        FMUL    ST(0), ST(0)            ; square it
        FSUBP   ST(1), ST               ; 1 - X^2
        FSQRT

; We now have tangent = ST(1)/ST.  In order to use the FPATAN instruction
; we must order them so that ST(1) < ST.  The special case of equality
; (angle pi/4) must be treated separately.

        FCOM
        FSTSW   W0 (status)
        mov     ah, 41h                 ; C3, C0 are the important bits
        FWAIT

; At this stage note that acos (x) = atan (sqrt (1-x^2) / x), which is
; the inverse of the tangent ratio used for asin (x).  That is why
; DL, the inversion flag, started as 0FF for acos, and 0 for asin.

        and     ah, BY1 (status)
        jz      acs_atan
        add     ah, ah
        js      acs_pi_4
        FXCH
        not     dl                      ; remember the exchanged order

acs_atan:
        FPATAN                          ; arctan (ST(1) / ST)

        or      dl, dl                  ; should ratio be inverted ?
        jz      acs_sign

        mov     W0 (temp), -1
        FILD    W0 (temp)
        FLDPI
        FSCALE                          ; pi/2
        fstp_st1
        FSUBRP  st(1), st               ; ST = pi/2 - ST

acs_sign:
        or      dh, dh
        jns     acs_end

        FCHS

        cmp     BY0 (flags), 0FFh       ; are we doing acos () ?
        jne     acs_end

        FLDPI
        FADDP   ST(1), ST
        jmp     acs_end

; Special cases.

acs_zero:
        mov     dh, 0                   ; make zero unsigned.
        FSTP    ST(0)                   ; pop stack
        cmp     BY0 (flags), 0FFh       ; are we doing acos () ?
        je      acs_resultP2
acs_resultZ:
        FLDZ
        jmp     short   acs_sign

acs_extreme:
        ja      acs_domain
        mov     ax, [esi+6]             ; check for an exact value +- 1.0
        xor     ah, 80h
        or      ax, [esi+4]
        or      ax, [esi+2]
        or      ax, [esi]
        jnz     acs_domain
        jmp     short   acs_one

acs_one:
        FSTP    ST(0)                   ; pop stack
        cmp     BY0 (flags), 0FFh       ; are we doing acos () ?
        je      acs_resultZ
acs_resultP2:
        mov     W0 (temp), -1
        FILD    W0 (temp)
        FLDPI
        FSCALE                          ; pi/2
        fstp_st1
        jmp     short   acs_sign

acs_pi_4:
        FSTP    ST(0)                   ; pop two items off the stack
        FSTP    ST(0)
        mov     W0 (temp), -2
        FILD    W0 (temp)
        FLDPI
        FSCALE                          ; pi/4
        fstp_st1
        jmp     acs_sign

;  If the argument was outside [-1,+1] then it is a domain error.

acs_domain:
        or      BY0 ([esi+7]), dh       ; put the sign back
        FSTP    ST (0)                  ; pop x from stack

; return __matherrl (DOMAIN, whoS, xP, NULL, *((long double *) NANINVTRIGL));
; Can't use the matherrl macro; the arguments aren't quite the same type.

ExtFunc@ __matherrl, _RTLENTRY, 28

        push    dword ptr NANINVTRIGL[8]
        push    dword ptr NANINVTRIGL[4]
        push    dword ptr NANINVTRIGL
        push    0       ; NULL
        push    dword ptr xP
        push    dword ptr whoS
        push    DOMAIN
        Call@   __matherrl

acs_end:
        Unlink@ esi
        return@

EndFunc@ AcosAsinl

;--------------------------------------------------------------------------
;
;Name            acosl & asinl - trigonometric functions
;
;Usage           long double acosl(long double x);
;                long double asinl(long double x);
;
;Prototype in    math.h
;
;Description     asinl,   acosl  return   the  arc   sine,  and   arc  cosine,
;                respectively,  of the  input value.  Arguments to  asinl and
;                acosl must be  in the range -1 to 1.  Arguments outside that
;                range will cause asinl or acosl to return 0 and set errno to:
;                        EDOM    Domain error
;
;Return value    acosl returns a value in the range 0 to pi.
;                asinl returns a value in the range -pi/2 to pi/2.
;
;---------------------------------------------------------------------------

Data_Seg@

acosl_s db      'acosl', 0
asinl_s db      'asinl', 0

Data_EndS@

Func@   acosl, _EXPFUNC, _RTLENTRY,       <longdouble x>

;        return  AcosAsinl ("acosl", 0xFF, &x);

        link@
        lea     eax, x
        push    eax
        push    0ffh
        push    offset flat: acosl_s
        Call@   AcosAsinl
        Unlink@
        Return@

EndFunc@ acosl


Func@   asinl, _EXPFUNC, _RTLENTRY, <longdouble x>

;        return  AcosAsinl ("asinl", 0x00, &x);

        Link@
        lea     eax, x
        push    eax
        push    0
        push    offset flat: asinl_s
        Call@   AcosAsinl
        Unlink@
        Return@

EndFunc@ asinl

Code_EndS@

        end
