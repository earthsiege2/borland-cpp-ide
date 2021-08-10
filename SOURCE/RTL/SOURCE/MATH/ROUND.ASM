;[]-----------------------------------------------------------------[]
;|   ROUND.ASM -- rounding function		                     |
;[]-----------------------------------------------------------------[]

;
;       C/C++ Run Time Library - Version 10.0
; 
;       Copyright (c) 1991, 2000 by Inprise Corporation
;       All Rights Reserved.
; 

; $Revision:   9.0  $

;------------------------------------------------------------------------
; filename - round.cas
;
; function(s)
;        __round - rounding helper function
;------------------------------------------------------------------------

	include RULES.ASI

;       Segments Definitions

Header@

;-------------------------------------------------------------------------
;
;Name            _round - rounding helper function
;
;Usage           void near _round(void)
;
;Prototype in    _math.h
;
;Description     _round rounds the argument on the floating point stack.
;                The CH register contains the rounding flags:
;                        00H     Round to nearest or even
;                        04H     Round down toward -INF
;                        08H     Round up toward +INF
;                        0CH     Chop (truncate toward 0)
;                This function is a helper for modf(), floor(), ceil(),
;                and their long double counterparts.
;
;Return value    _round does not return a value, but leaves the rounded
;                result on the top of the FPU stack.
;
;---------------------------------------------------------------------------

Code_Seg@

Func@	_round, public, _RTLENTRY
Locals@	<word cword>	        ; unsigned int cword;

	Link@

	FSTCW   cword   	; read out the current control word
	mov     ax, 0F3FFh
	FWAIT
	mov     dx, cword
	and     ax, dx  	; mask out the rounding control
	or      ah, ch  	; iNDP-87 control bits for rounding mode
	mov     cword, ax
	FLDCW   cword
	FRNDINT         	; round to integer
	mov     cword, dx
	FLDCW   cword   	; restore original rounding control

	Unlink@
	Return@

EndFunc@ _round

Code_EndS@

	end
