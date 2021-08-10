
	include	rules.asi

	Header@


DENOM		EQU	0
NUMER		EQU	12
PREV_CW		EQU	28	; 24 + 4 (return size)
PATCH_CW 	EQU	32	; 28 + 4 (return size)

MAIN_DENOM	EQU	4
MAIN_NUMER	EQU	16

STACK_SIZE	EQU	44
ONESMASK	EQU	0e000000h

fdivp_sti	MACRO	reg_index, reg_index_minus1
	fstp	tbyte ptr [esp+DENOM]
IF	reg_index_minus1 GE 1
	fxch	st(reg_index_minus1)
ENDIF
	fstp	tbyte ptr [esp+NUMER]
	call	fdiv_main_routine
IF	reg_index_minus1 GE 1
	fxch	st(reg_index_minus1)
ENDIF
	add	esp, STACK_SIZE
ENDM

	Data_seg@

fdiv_risc_table	DB	0, 1, 0, 0, 4, 0, 0, 7, 0, 0, 10, 0, 0, 13, 0, 0
fdiv_scale_1	DD	03f700000h		;0.9375
fdiv_scale_2	DD	03f880000h		;1.0625
one_shl_63	DD	05f000000h

;
;  This is the flag that is tested by all the compiler branches
;  before the divide instruction.
;
;	0 = unknown whether running on a part with the flaw
;	1 = running on a part with no flaw
;	-1= running on a part with the flaw
;

	public	__fdivflag
__fdivflag	DD	0h

;
;  The following are initializers for known values that cause
;  the divide problem.
;

test_dividend	DB	0,0,0,0c0h,07eh,01h,050h,041h	 ; x = 4195835.0
test_divisor	DB	0,0,0,080h,0ffh,0ffh,047h,041h   ; y = 3145727.0
one		DB	0,0,0,0,0,0,0f0h,03fh

	Data_EndS@

	Code_seg@

fdiv_main_routine PROC	NEAR

	fld     tbyte ptr [esp+MAIN_NUMER]	; load the numerator
	fld	tbyte ptr [esp+MAIN_DENOM]	; load the denominator
retry:

;  The following three lines test for denormals and zeros.
;  A denormal or zero has a 0 in the explicit digit to the left of the
;  binary point.  Since that bit is the high bit of the word, adding
;  it to itself will produce a carry if and only if the number is not
;  denormal or zero.
;
	mov	eax, [esp+MAIN_DENOM+4]	; get mantissa bits 32-64
	add	eax,eax			; shift the one's bit onto carry
	jnc	denormal		; if no carry, we're denormal

;  The following three lines test the three bits after the four bit
;  pattern (1,4,7,a,d).  If these three bits are not all one, then
;  the denominator cannot expose the flaw.  This condition is tested by
;  inverting the bits and testing that all are equal to zero afterward.

	xor	eax, ONESMASK		; invert the bits that must be ones
	test	eax, ONESMASK		; and make sure they are all ones
	jz	scale_if_needed		; if all are one scale numbers
	fdivp	st(1), st		; use of hardware is OK.
	ret

;
;  Now we test the four bits for one of the five patterns.
;
scale_if_needed:
	shr	eax, 28			; keep first 4 bits after point
	cmp	byte ptr fdiv_risc_table[eax], 0	; check for (1,4,7,a,d)
	jnz	divide_scaled		; are in potential problem area
	fdivp	st(1), st		; use of hardware is OK.
	ret

divide_scaled:
	mov	eax, [esp + MAIN_DENOM+8]	; test denominator exponent
	and	eax, 07fffh             ; if pseudodenormal ensure that only
	jz	invalid_denom		; invalid exception flag is set
	cmp	eax, 07fffh             ; if NaN or infinity  ensure that only
	je	invalid_denom		; invalid exception flag is set
;
;  The following six lines turn off exceptions and set the
;  precision control to 80 bits.  The former is necessary to
;  force any traps to be taken at the divide instead of the scaling
;  code.  The latter is necessary in order to get full precision for
;  codes with incoming 32 and 64 bit precision settings.  If
;  it can be guaranteed that before reaching this point, the underflow
;  exception is masked and the precision control is at 80 bits, these
;  six lines can be omitted.
;
	fnstcw	[esp+PREV_CW]		; save caller's control word
	mov	eax, [esp+PREV_CW]
	or	eax, 033fh		; mask exceptions, pc=80
	and	eax, 0f3ffh		; set rounding mode to nearest
	mov	[esp+PATCH_CW], eax
	fldcw	[esp+PATCH_CW]		; mask exceptions & pc=80

;  The following lines check the numerator exponent before scaling.
;  This in order to prevent undeflow when scaling the numerator,
;  which will cause a denormal exception flag to be set when the
;  actual divide is preformed. This flag would not have been set
;  normally. If there is a risk of underflow, the scale factor is
;  17/16 instead of 15/16.
;
 	mov	eax, [esp+MAIN_NUMER+8]	; test numerator exponent
 	and	eax, 07fffh
 	cmp	eax, 00001h
 	je	small_numer

	fmul	fdiv_scale_1		; scale denominator by 15/16
	fxch
	fmul	fdiv_scale_1		; scale numerator by 15/16
	fxch

;
;  The next line restores the users control word.  If the incoming
;  control word had the underflow exception masked and precision
;  control set to 80 bits, this line can be omitted.
;

	fldcw	[esp+PREV_CW]		; restore caller's control word
	fdivp	st(1), st		; use of hardware is OK.
	ret

small_numer:
	fmul	fdiv_scale_2		; scale denominator by 17/16
	fxch
	fmul	fdiv_scale_2		; scale numerator by 17/16
	fxch

;
;  The next line restores the users control word.  If the incoming
;  control word had the underflow exception masked and precision
;  control set to 80 bits, this line can be omitted.
;

	fldcw	[esp+PREV_CW]		; restore caller's control word
	fdivp	st(1), st		; use of hardware is OK.
	ret

denormal:
	mov	eax, [esp+MAIN_DENOM]	; test for whole mantissa == 0
	or	eax, [esp+MAIN_DENOM+4]	; test for whole mantissa == 0
	jnz	denormal_divide_scaled	; denominator is not zero
invalid_denom:				; zero or invalid denominator
	fdivp	st(1), st		; use of hardware is OK.
	ret

denormal_divide_scaled:
	mov	eax, [esp + MAIN_DENOM + 8]	; get exponent
	and	eax, 07fffh		; check for zero exponent
	jnz	invalid_denom		;
;
;  The following six lines turn off exceptions and set the
;  precision control to 80 bits.  The former is necessary to
;  force any traps to be taken at the divide instead of the scaling
;  code.  The latter is necessary in order to get full precision for
;  codes with incoming 32 and 64 bit precision settings.  If
;  it can be guaranteed that before reaching this point, the underflow
;  exception is masked and the precision control is at 80 bits, these
;  six lines can be omitted.
;

	fnstcw	[esp+PREV_CW]		; save caller's control word
	mov	eax, [esp+PREV_CW]
	or	eax, 033fh		; mask exceptions, pc=80
	and	eax, 0f3ffh		; set rounding mode to nearest
	mov	[esp+PATCH_CW], eax
	fldcw	[esp+PATCH_CW]		; mask exceptions & pc=80

	mov	eax, [esp + MAIN_NUMER +8]	; test numerator exponent
	and	eax, 07fffh		; check for denormal numerator
	je	denormal_numer	
	cmp	eax, 07fffh		; NaN or infinity
	je	invalid_numer
	mov	eax, [esp + MAIN_NUMER + 4]	; get bits 32..63 of mantissa
	add	eax, eax		; shift the first bit into carry
	jnc	invalid_numer		; if there is no carry, we have an
					; invalid numer
	jmp	numer_ok

denormal_numer:
	mov	eax, [esp + MAIN_NUMER + 4]	; get bits 32..63 of mantissa
	add	eax, eax		; shift the first bit into carry
	jc	invalid_numer		; if there is a carry, we have an
					; invalid numer
	
numer_ok:
	fxch
	fstp	st			; pop numerator
	fld	st			; make copy of denominator
	fmul	dword ptr[one_shl_63]	; make denominator not denormal
	fstp	tbyte ptr [esp+MAIN_DENOM]	; save modified denominator
	fld	tbyte ptr [esp+MAIN_NUMER]	; load numerator
	fxch				; restore proper order
	fwait

;  The next line restores the users control word.  If the incoming
;  control word had the underflow exception masked and precision
;  control set to 80 bits, this line can be omitted.
;

	fldcw	[esp+PREV_CW]		; restore caller's control word
	jmp	retry			; start the whole thing over

invalid_numer:
;
;  The next line restores the users control word.  If the incoming
;  control word had the underflow exception masked and precision
;  control set to 80 bits, this line can be omitted.
;
	fldcw	[esp + PREV_CW]
	fdivp	st(1), st		; use of hardware is OK.
	ret

fdiv_main_routine	ENDP

;;  Performs an fdivp st(1),st

	public	__fdiv
__fdiv	PROC	NEAR
	push	eax
	sub	esp, STACK_SIZE
	fdivp_sti 1 0
	; Macro cleans up stack
	pop	eax
	ret
__fdiv	ENDP

;
; int fdiv_detect(void)
;

FDIV_DETECT PROC NEAR
	fld	qword ptr [test_dividend]
	fwait
	fdiv	qword ptr [test_divisor] ; no_error = ((x - (x / y)*y) < 1.0
	fwait
	fmul	qword ptr [test_divisor]
	fwait
	fsubr	qword ptr [test_dividend]
	fwait
	fcomp	qword ptr [one]
	fwait
	fstsw	ax
	fwait
	and	eax, 0100h              ; 0: uninitialized
	shr	eax, 7
	sub	eax, 1
	mov	__fdivflag, eax
	ret
FDIV_DETECT ENDP

	Code_EndS@

_INIT_  segment word public 'INITDATA'
	db      0                       ; near call
	db      1                       ; priority 1
	dd      offset FDIV_DETECT
	ends

	end

