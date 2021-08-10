;[]-----------------------------------------------------------------[]
;|   EXPLD.ASM -- long double exponential helper function	     |
;[]-----------------------------------------------------------------[]

;
;       C/C++ Run Time Library - Version 1.5
; 
;       Copyright (c) 1991, 1994 by Borland International
;       All Rights Reserved.
; 

;----------------------------------------------------------------------
; function(s)
;        _expld - long double exponential function helper function
;----------------------------------------------------------------------

	include RULES.ASI
	include _MATH.INC

;       Segments Definitions

Header@

Data_Seg@

log2hi		dw	00000H,0D1D0H,017F7H,0B172H,03FFEH	; +0.693E+0
log2hi_ov_2	dw	00000H,0D1D0H,017F7H,0B172H,03FFDH	; +0.34657E+0
log2lo		dw	0FC0DH,04C67H,0361CH,08654H,0BFCEH      ; -0.1864E-14

Data_EndS@

;--------------------------------------------------------------------------
;
;Name            _expld - long double exponential function
;
;Usage           void _expld(void)
;
;Prototype in    _math.h
;
;Description     _expld calculates the exponent of the argument on the top
;                of the FPU stack (e^TOS).  The result is left on the
;                top of the FPU stack.  No error checking on the argument
;                is performed.  This function is a helper for expl(),
;                sinhl(), and coshl().
;
;Return value    _expld does not return a value, but leaves the result
;                e^TOS on the TOS.
;--------------------------------------------------------------------------

Code_Seg@
Func@	_expld, public, _RTLENTRY
Locals@	<int status>		; unsigned short status

	Link@

	FLD     log2hi.longdouble       ; st(0)= log2hi st(1)= x 
	FLD     st(1)           	; st(0)= x; st(1)= log2hi; st(2)= x 
	FPREM                   	; st(0)=hi; st(1)=log2hi; st(2)=x 
	FLD     log2hi_ov_2.longdouble  ; st(0)=log2hi/2 
	FCOMP   st(1)           	; log2hi/2 >= hi ? 
	FSTSW   status
	FWAIT
	mov     ah, status[1]
	sahf
	jae     expl_test_neg
	FSUB    st(0), st(1)    ; st(0)= hi; st(1)= log2hi; st(2)= x 
	jmp     short expl_begin

expl_test_neg:
	FLD     log2hi_ov_2.longdouble  ; st(0)=-log2hi/2 
	FCHS
	FCOMP   st(1)           ; -log2hi/2 <= hi ? 
	FSTSW   status
	FWAIT
	mov     ah, status[1]
	sahf
	jbe     expl_begin
	FADD    st(0), st(1)    ; st(0)=hi; st(1)=log2hi; st(2)=x 

expl_begin:
	FXCH    st(2)           ; st(0)= x; st(1)= log2hi; st(2)= hi 
	FSUB    st(0), st(2)    ; st(0)= x-hi; st(1)= log2hi; st(2)= hi 
	FDIVRP  st(1), st(0)    ; st(0)= (x-hi)/log2hi; st(1)= hi 
	FRNDINT                 ; st(0)= i= rint((x-hi)/log2hi); st(1)= hi 
	FXCH    st(1)           ; st(0)= hi; st(1)= i 
	FLD     log2lo.longdouble	; st(0)=log2lo; st(1)=hi; st(2)=i 
	FMUL    st(0), st(2)    ; st(0)= i*log2lo; st(1)= hi; st(2)= i 
	FSUBP   st(1), st(0)    ; st(0)= r= x-i*log2; st(1)= i 
	FLDL2E                  ; st(0)= log2(e); st(1)= r; st(2)= i 
	FMUL                    ; st(0)= f; st(1)= i 

	FTST                    ; f >= 0? 
	FSTSW   status
	FWAIT
	mov     ah, status[1]
	sahf
	jb      expl_red_neg
	F2XM1                   ; st(0)= 2^f-1; st(1)= i 
	FLD1                    ; st(0)= 1; st(1)= 2^f-1; st(2)= i 
	FADDP   st(1), st(0)    ; st(0)= 2^f; st(1)= i 
	jmp     short expl_red_next

expl_red_neg:
	FCHS                    ; st(0)= -f; st(1)= i 
	F2XM1                   ; st(0)= 2^(-f)-1; st(1)= i 
	FLD1                    ; st(0)= 1; st(1)= 2^(-f)-1; st(2)= i 
	FADD    st(1), st(0)    ; st(0)= 1; st(1)= 2^(-f); st(2)= i 
	FDIVRP  st(1), st(0)    ; st(0)= 2^f; st(1)= i 

expl_red_next:
	FSCALE                  ; st(0)= (2^i)*(2^f) 
	fstp_st1
	Unlink@
        Return@

EndFunc@ _expld
Code_EndS@
	end
