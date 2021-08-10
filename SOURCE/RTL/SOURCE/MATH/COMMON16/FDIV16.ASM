; $Revision:   8.2  $
	include	rules.asi

	Header@

	LOCALS

EMUL            ; generate emulated instructions

DENOM		EQU	0
NUMER		EQU	12
PATCH_CW 	EQU	28
PREV_CW		EQU	24
DENOM_SAVE	EQU	32

MAIN_DENOM	EQU	0
MAIN_NUMER	EQU	12

STACK_SIZE	EQU	44
ONESMASK	EQU	0e00h

fdivp_sti	MACRO	reg_index, reg_index_minus1
	fstp	tbyte ptr [bp+DENOM]
IF	reg_index_minus1 GE 1
	fxch	st(reg_index_minus1)
ENDIF
	fstp	tbyte ptr [bp+NUMER]
	call	fdiv_main_routine
IF	reg_index_minus1 GE 1
	fxch	st(reg_index_minus1)
ENDIF
	add	sp, STACK_SIZE		; update stack
ENDM

fdivrp_sti	MACRO	reg_index, reg_index_minus1
	fstp	tbyte ptr [bp+NUMER]
IF	reg_index_minus1 GE 1
	fxch	st(reg_index_minus1)
ENDIF
	fstp	tbyte ptr [bp+DENOM]
	call	fdiv_main_routine
IF	reg_index_minus1 GE 1
	fxch	st(reg_index_minus1)
ENDIF
	add	sp, STACK_SIZE		; update stack
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
__fdivflag	DW	0h

;
;  The following are initializers for known values that cause
;  the divide problem.
;

test_dividend	DB	0,0,0,0c0h,07eh,01h,050h,041h	 ; x = 4195835.0
test_divisor	DB	0,0,0,080h,0ffh,0ffh,047h,041h   ; y = 3145727.0
one		DB	0,0,0,0,0,0,0f0h,03fh

	Data_EndS@

	Code_seg@

;
; int FDIV_DETECT(void)
;
; Use only 8086 instructions to test for FDIV flaw (don't bother with CPU check)

.8086

FDIV_DETECT proc near
	push	bp
	mov	bp, sp
	sub	sp, 2
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
	fstsw	[bp-2]
	mov	ax, [bp-2]
	fwait
	and	ax, 0100h		; 0: uninitialized
	shr	ax, 7
	sub	ax, 1
	mov	__fdivflag, ax		; DS set to DGROUP even in huge model
	mov	sp, bp			;   startup procedures
	pop	bp
	ret
FDIV_DETECT endp

	Code_EndS@

_INIT_  SEGMENT WORD PUBLIC 'INITDATA'
	db      0                       ; near call
	db      17                      ; priority 17 (FPINIT is 16)
	dw      offset FDIV_DETECT
	dw      ?
_INIT_	ends

	Code_seg@

					; In this implementation the
					; fdiv_main_routine is called,
					; therefore all the stack frame
					; locations are adjusted for the
					; return pointer.

NOEMUL		; generate real instructions

fdiv_main_routine PROC	NEAR

	fld     tbyte ptr [bp+MAIN_NUMER]    ; load the numerator
	fld	tbyte ptr [bp+MAIN_DENOM]	; load the denominator
retry:

;  The following three lines test for denormals and zeros.
;  A denormal or zero has a 0 in the explicit digit to the left of the
;  binary point.  Since that bit is the high bit of the word, adding
;  it to itself will produce a carry if and only if the number is not
;  denormal or zero.
;
	mov	ax, [bp+MAIN_DENOM+6]	; get mantissa bits 48-64
	add	ax,ax			; shift one's bit into carry
	jc	not_denormal		; if no carry, we have a denormal
	jmp	denormal
not_denormal:

;  The following three lines test the three bits after the four bit
;  pattern (1,4,7,a,d).  If these three bits are not all one, then
;  the denominator cannot expose the flaw.  This condition is tested by
;  inverting the bits and testing that all are equal to zero afterward.

	xor	ax, ONESMASK		; invert the bits that must be one
	test	ax, ONESMASK		; test for needed bits
	jz	scale_if_needed		; if all one, it may need scalling
	fdivp	st(1), st		; OK to use the hardware
	ret
	
;
;  Now we test the four bits for one of the five patterns.
;
scale_if_needed:
	shr	ax, 12			; keep first four bits after point
        push    bx                      ; save bx
        mov     bx,ax                   ; bx = index
	cmp	byte ptr fdiv_risc_table[bx], 0	; check for (1,4,7,a,d)
        pop     bx                      ; restore bx
	jnz	divide_scaled
	fdivp	st(1), st		; OK to use the hardware
	ret
	
divide_scaled:
	mov	ax, [bp + MAIN_DENOM+8]	; test denominator exponent
	and	ax, 07fffh              ; if pseudodenormal ensure that only
	jz	invalid_denom		; invalid exception flag is set
	cmp	ax, 07fffh              ; if NaN or infinity  ensure that only
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
	fnstcw	[bp+PREV_CW]		; save caller's control word
	mov	ax, [bp+PREV_CW]
	or	ax, 033fh		; mask exceptions, pc=80
	and	ax, 0f3ffh		; set rounding mode to nearest
	mov	[bp+PATCH_CW], ax
	fldcw	[bp+PATCH_CW]		; mask exceptions & pc=80

;  The following lines check the numerator exponent before scaling.
;  This in order to prevent undeflow when scaling the numerator,
;  which will cause a denormal exception flag to be set when the
;  actual divide is preformed. This flag would not have been set
;  normally. If there is a risk of underflow, the scale factor is
;  17/16 instead of 15/16.
;
 	mov	ax, [bp+MAIN_NUMER+8]	; test numerator exponent
 	and	ax, 07fffh
 	cmp	ax, 00001h
 	je	small_numer

; perform scaling of both numerator and denominator

	fmul	fdiv_scale_1		; scale denominator by 15/16
	fxch
	fmul	fdiv_scale_1		; scale numerator by 15/16
	fxch

;
;  The next line restores the users control word.  If the incoming
;  control word had the underflow exception masked and precision
;  control set to 80 bits, this line can be omitted.
;

	fldcw	[bp+PREV_CW]		; restore caller's control word
	fdivp	st(1), st		; OK to use the hardware
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

	fldcw	[bp+PREV_CW]		; restore caller's control word
	fdivp	st(1), st		; OK to use the hardware
	ret
	
denormal:
	mov	ax, [bp+MAIN_DENOM]	; test for whole mantissa == 0
	or	ax, [bp+MAIN_DENOM+2]	; test for whole mantissa == 0
	or	ax, [bp+MAIN_DENOM+4]	; test for whole mantissa == 0
	or	ax, [bp+MAIN_DENOM+6]	; test for whole mantissa == 0
	jnz	denormal_divide_scaled	; denominator is not zero
invalid_denom:				; zero or invalid denominator
	fdivp	st(1), st		; OK to use the hardware
	ret
	
denormal_divide_scaled:
	mov	ax, word ptr[bp + MAIN_DENOM + 8]	; get exponent
	and	ax, 07fffh		; check for zero exponent
	jnz	invalid_denom
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

	fnstcw	[bp+PREV_CW]		; save caller's control word
	mov	ax, [bp+PREV_CW]
	or	ax, 033fh		; mask exceptions, pc=80
	and	ax, 0f3ffh		; set rounding mode to nearest
	mov	[bp+PATCH_CW], ax
	fldcw	[bp+PATCH_CW]		; mask exceptions & pc=80

	mov	ax, [bp + MAIN_NUMER +8]	; test numerator exponent
	and	ax, 07fffh		; check for denormal numerator
	je	denormal_numer	
	cmp	ax, 07fffh		; NaN or infinity
	je	invalid_numer
	mov	ax, [bp + MAIN_NUMER + 6]	; get bits 48..63 of mantissa
	add	ax, ax			; shift the first bit into carry
	jnc	invalid_numer		; if there is no carry, we have an
					; invalid numer
	jmp	numer_ok

denormal_numer:
	mov	ax, [bp + MAIN_NUMER + 6]	; get bits 48..63 of mantissa
	add	ax, ax			; shift the first bit into carry
	jc	invalid_numer		; if there is a carry, we have an
					; invalid numer
	
numer_ok:
	fxch
	fstp	st			; pop numerator
	fld	st			; make copy of denominator
	fmul	[one_shl_63]		; make denominator not denormal
	fstp	tbyte ptr [bp+MAIN_DENOM]
	fld	tbyte ptr [bp+MAIN_NUMER]	; load numerator
	fxch				; restore proper order
	fwait

;  The next line restores the users control word.  If the incoming
;  control word had the underflow exception masked and precision
;  control set to 80 bits, this line can be omitted.
;
	fldcw	[bp+PREV_CW]		; restore caller's control word
	jmp	retry			; start the whole thing over

invalid_numer:
;
;  The next line restores the users control word.  If the incoming
;  control word had the underflow exception masked and precision
;  control set to 80 bits, this line can be omitted.
;
	fldcw	[bp + PREV_CW]

	fdivp	st(1), st		; use of hardware is OK.
	ret

fdiv_main_routine	ENDP

;;  Note that compiler helper functions assume that the flaw dectection has
;;  already been determined.

EMUL            ; generate emulated instructions

;;  Performs an fdivp st(1),st (fdiv)
	public  N_FDIV@
N_FDIV@		PROC	NEAR
		cmp	__fdivflag,0ffffh
		je	@@flaw_detected
		fdiv
		ret
@@flaw_detected:
		push	bp
		push	ax
		sub	sp, STACK_SIZE
		mov	bp, sp
		fdivp_sti 1 0
		; Macro cleans up stack
		pop	ax
		pop	bp
		ret
N_FDIV@		ENDP

;;  Performs an fdivp st(1),st (fdiv)
	public  F_FDIV@
F_FDIV@		PROC	FAR
ifdef __HUGE__
		push	ds
		push	ax
		mov	ax, seg __fdivflag
		mov	ds, ax
endif
		cmp	__fdivflag,0ffffh
		je	@@flaw_detected
		fdiv
ifdef __HUGE__
		pop	ax
		pop	ds
endif
		ret
@@flaw_detected:
		push	bp
		push	ax
		sub	sp, STACK_SIZE
		mov	bp, sp
		fdivp_sti 1 0
		; Macro cleans up stack
		pop	ax
		pop	bp
ifdef __HUGE__
		pop	ax
		pop	ds
endif
		ret
F_FDIV@		ENDP

;;  Performs an fdivrp st(1),st (fdivr)
	public  N_FDIVR@
N_FDIVR@	PROC	NEAR
		cmp	__fdivflag,0ffffh
		je	@@flaw_detected
		fdivr
		ret
@@flaw_detected:
		push	bp
		push	ax
		sub	sp, STACK_SIZE
		mov	bp, sp
		fdivrp_sti 1 0
		; Macro cleans up stack
		pop	ax
		pop	bp
		ret
N_FDIVR@	ENDP

;;  Performs an fdivrp st(1),st (fdivr)
	public  F_FDIVR@
F_FDIVR@	PROC	FAR
ifdef __HUGE__
		push	ds
		push	ax
		mov	ax, seg __fdivflag
		mov	ds, ax
endif
		cmp	__fdivflag,0ffffh
		je	@@flaw_detected
		fdivr
ifdef __HUGE__
		pop	ax
		pop	ds
endif
		ret
@@flaw_detected:
		push	bp
		push	ax
		sub	sp, STACK_SIZE
		mov	bp, sp
		fdivrp_sti 1 0
		; Macro cleans up stack
		pop	ax
		pop	bp
ifdef __HUGE__
		pop	ax
		pop	ds
endif
		ret
F_FDIVR@	ENDP

	Code_EndS@

	end

