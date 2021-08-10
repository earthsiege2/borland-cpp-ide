;[]-----------------------------------------------------------------[]
;|   POLYL.ASM -- generate polynomial                                |
;[]-----------------------------------------------------------------[]

;
;       C/C++ Run Time Library - Version 10.0
; 
;       Copyright (c) 1991, 2000 by Inprise Corporation
;       All Rights Reserved.
; 

; $Revision:   9.0  $

;----------------------------------------------------------------------
; function(s)
;        polyl - generates a long double polynomial from arguments
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

Data_EndS@

;--------------------------------------------------------------------------
;
;Name           polyl - generates a long double polynomial from arguments
;
;Usage          long double polyl(long double x, int n, long double c []);
;
;Prototype in   math.h
;
;Description    polyl  generates  a  polynomial in  x,  of  degree  n, with
;               coefficients c[0],  c[1], ..., c[n].  For example, if  n=4,
;               the generated polynomial is
;
;                       c[4].x^4 + c[3].x^3 + c[2].x^2] + c[1].x + c[0]
;
;               The polynomial is calculated using Horner's method:
;
;                       polynom = (..((x.c[n] + c[n-1]).x + c[n-2])..).x + c[0]
;
;Return value   polyl returns the  value of the polynomial as  evaluated for
;               the given x.
;               If n < 0  then the result is a domain error.
;               A range error occurs if the result exceeds long double range.
;
;--------------------------------------------------------------------------

Code_Seg@

Func@   polyl, _EXPFUNC, _RTLENTRY, <longdouble x>, <int n>, <pointer c>
Locals@ <int sw>                ; volatile unsigned    sw;

        Link@

        FLD     x.longdouble
        mov     eax, n
        or      eax, eax                ; if n < 0, domain error
        jl      ply_domain
        lea     edx, [eax*8]            ; edx = n * sizeof(long double);
        lea     edx, [edx+eax*2]
        mov     eax, c                  ; eax = c;
        FLD     [eax+edx].longdouble
        or      edx, edx
        jz      short   ply_end         ; while (n != 0)
ply_loop:
        FMUL    ST, ST(1)               ; x*c[n]
        sub     edx, tbyte              ; n--
        FLD     [eax+edx].longdouble    ; get next coefficient
        FADD
        jnz     ply_loop

ply_end:
        FXAM
        FSTSW   sw.w0
        fstp_st1                        ; discard ST(1)
        mov     ax, sw.w0
        sahf
        jc      ply_range
ply_return:
        Unlink@
        Return@

ply_domain:
        mov     edx, DOMAIN
        jmp     short   ply_err

ply_range:
        mov     edx, OVERFLOW

ply_err:
        FSTP    ST(0)                   ; discard ST

;       return  __matherrl (_EDX, "polyl", &x, c, _LHUGE_VAL);

        mov     ecx, c
        matherrl edx, polyl, x, [ecx], _LHUGE_VAL
        jmp     ply_return

EndFunc@ polyl

Code_Ends@
        end
