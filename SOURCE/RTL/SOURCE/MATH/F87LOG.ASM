;[]-----------------------------------------------------------------[]
;|      F87LOG.ASM                                                   |
;[]-----------------------------------------------------------------[]

;
;       C/C++ Run Time Library - Version 10.0
; 
;       Copyright (c) 1986, 2000 by Inprise Corporation
;       All Rights Reserved.
; 

; $Revision:   9.0  $

        include RULES.ASI
	include	_MATH.INC

;       Segments Definitions

Header@

;----------------------------------------------------------------------
; Special constants are placed here.

Const_Seg@

NANlog		dd	0FFC04800r

half 		dd	03F000000r

sqrt2		dt	3FFFB504F333F9DE6485r

infinity	dd	7F800000R		; plus infinity

Const_EndS@


;----------------------------------------------------------------------
; General notes:

; - operands are on the iNDP stack
; - results will be on the iNDP stack
; - EAX,EBX,ECX,EDX may be consumed.  Others must be preserved.
; - unnormals are not specifically processed because this module is
;	intended to work with HLL's which place results into IEEE
;	"double" format, whereas only the IEEE "temporary" format can
;	handle unnormals.  If you want to run with assembler programs
;	that may use unnormals then you should check these algorithms
;	for what happens with un-normal parameters.  De-normals are
;	processed correctly, since they have been arranged to follow
;	the same paths as zeroes with only slight extra care needed to
;	accomodate them.

Code_seg@

;----------------------------------------------------------------------
; Log2, Log10, and Log


; Log2 (X) = Log2 (X)

Func@ _f87_Log2, public, _RTLENTRY
	fld1
	jmp	short	DoLogs
EndFunc@ _f87_Log2

; Log10 (X) = Log10 (2) * Log2 (X)

Func@ _f87_Log10, public, _RTLENTRY
	fldlg2
	jmp	short	DoLogs
EndFunc@ _f87_Log10

; Log (X) = Log (2) * Log2 (X)

Func@ _f87_Log, public, _RTLENTRY
	fldln2
;	jmp	short	DoLogs
;	fall thru to DoLogs

log_temp	equ	[esp]		; a 10-byte floating point value
log_status	equ	[esp+10].w0

DoLogs:
	fxch				; keep '87 busy in parallel

	sub	esp,12			; make room for log_temp and log_status

	fxam

	fstsw	log_status
	wait
	mov	ah, log_status.by1
	sahf				; FL now reflects FXAM status
	jc	log_badParam
	jz	log_tiny
	test	ah, 2			; was parameter negative ?
	jz	log_normal

log_negative:
log_tiny:				; denormal or zero
log_tooBig:
	fstp	st(0)			; pop st(0)
	jmp	short	log_indefinite

log_badParam:				; NAN, infinite, or Empty
	jz	log_empty		; st(0) was empty
	fstp_st1			; pop st(1)
	jnp	log_NAN			; st(0) was NAN

;infinite arg
	fstp_st1			; pop st(1)
	test	ah, 2			; was parameter negative ?
	jz	log_end

log_indefinite:
	fstp	st(0)			; pop st(0)
	fld	NANlog			; st(0) was infinite, now NAN

log_NAN:
log_empty:
	ftst				; trigger exception
	jmp	short	log_end


log_normal:

; the first million 8087s and 80287s had a bug
; fyl2x failed if x = smallest 10-byte real > 1
; FYL2X(1,x) gave you garbage *only* if x = 1+2**-63:

;If you looked at Intel's CEL library code, you would see some code that
;checks if difference between x and 1 is < 2^-16, and if so does a ylogxp1
;instead.  This was explicitly commented there as a work around for an old
;chip bug.  The problem comes in the argument reduction not normalizing the
;mantissa after subtracting 1 from it, prior to doing the Cordic reduction.

; If anyone decides this case is too obscure to bother with,
; or that everyone has bug-free chips,
; then just delete the code from here to log_normal1.

; test whether number is near +1 by examining bits directly
;	fld	st(0)		; duplicate TOS
;	lea	esp, log_temp	; space already allocated
;	fstp	tbyte ptr log_temp;
;	fwait

; +1 is stored as 0000 0000 0000 8000 3FFF
;	cmp	word ptr log_temp[8], 3FFFh
;	jne	log_normal1
;	cmp	word ptr log_temp[6], 8000h
;	jne	log_normal1

; arg now in range [1,1+2^-16].
;	fld1
;	fsub
;	fyl2xp1
;	jmp	short log_end

log_normal1:
	fyl2x

log_end:
	add	esp,12
	ret

EndFunc@ _f87_Log
Code_EndS@

	end
