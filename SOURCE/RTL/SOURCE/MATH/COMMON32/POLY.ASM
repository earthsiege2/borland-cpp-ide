;[]-----------------------------------------------------------------[]
;|   POLY.ASM -- generate polynomial                                 |
;[]-----------------------------------------------------------------[]

;
;       C/C++ Run Time Library - Version 2.0
; 
;       Copyright (c) 1991, 1996 by Borland International
;       All Rights Reserved.
; 

;----------------------------------------------------------------------
; function(s)
;        poly - generates a polynomial from arguments
;----------------------------------------------------------------------

        include RULES.ASI
        include _MATH.INC

;       Segments Definitions

Header@

;----------------------------------------------------------------------
; External variables

Data_Seg@

ExtSym@         _huge_dble, qword, cdecl
HUGE_VAL        equ     _huge_dble@

Data_EndS@

;--------------------------------------------------------------------------
;
;Name           poly - generates a polynomial from arguments
;
;Usage          double  poly(double x, int n, double c []);
;
;Prototype in   math.h
;
;Description    poly  generates  a  polynomial  in  x,  of  degree  n, with
;               coefficients c[0],  c[1], ..., c[n].  For example, if  n=4,
;               the generated polynomial is
;
;                       c[4].x^4 + c[3].x^3 + c[2].x^2] + c[1].x + c[0]
;
;               The polynomial is calculated using Horner's method:
;
;                       polynom = (..((x.c[n] + c[n-1]).x + c[n-2])..).x + c[0]
;
;Return value   poly returns the  value of the polynomial as  evaluated for
;               the given x.
;               If n < 0  then the result is a domain error.
;               A range error occurs if the result exceeds double range.
;
;--------------------------------------------------------------------------

Code_Seg@

Func@   poly, _EXPFUNC, _RTLENTRY, <double x>, <int n>, <pointer c>
Locals@ <int sw>                ; volatile unsigned    sw;

        Link@

        FLD     x.double
        mov     edx, n
        or      edx, edx                ; if n < 0, domain error
        jl      ply_domain
        mov     eax, c
        FLD     [eax+edx*8].double
        jz      short   ply_end         ; while (n != 0)
ply_loop:
        FMUL    ST, ST(1)               ; x*c[n]
        sub     edx, 1                  ; n--
        FADD    [eax+edx*8].double      ; get next coefficient
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

;       return  __matherr (_EDX, "poly", &x, c, HUGE_VAL);

        mov     ecx, c
        matherr edx, poly, x, [ecx], HUGE_VAL
        jmp     ply_return

EndFunc@ poly

Code_Ends@
        end
