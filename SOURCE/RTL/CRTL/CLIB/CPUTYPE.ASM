;[]-----------------------------------------------------------------[]
;|	CPUTYPE.ASM -- Dectect CPU type				     |
;|								     |
;|      Modified from Intel processor dectection code		     |
;[]-----------------------------------------------------------------[]

;
;       C/C++ Run Time Library - Version 6.0
; 
;       Copyright (c) 1993, 1992 by Borland International
;       All Rights Reserved.
; 


        INCLUDE RULES.ASI

;	Segment and Group declarations

Header@

_INIT_		SEGMENT WORD PUBLIC 'INITDATA'
		db	0			;near call
		db	16			;priority 16
		dw	offset GetCpuType
		dw	?
_INIT_		ENDS


_DATA		SEGMENT
PUBLIC	__8086
	__8086	dw	0
_DATA		ENDS


_TEXT		SEGMENT

GetCpuType	PROC NEAR

;
;	8086 CPU check
;	Bits 12-15 are always set on the 8086 processor.
;	
		pushf			; save EFLAGS
		pop	bx		; store EFLAGS in BX
		mov	ax,0FFFh	; clear bits 12-15 in EFLAGS
		and	ax,bx	
		push	ax		; store new EFLAGS value on stack
		popf			; replace current EFLAGS value
		pushf			; set new EFLAGS
		pop	ax		; store new EFLAGS in AX 
		and	ax,0F000h	; if bits 12-15 are set, then 8086/8088
		cmp	ax,0F000h
		mov	__8086,0	; turn on 8086/8088 flag
		je	exit	
					  
;
;	80286 CPU check
;	Bits 12-15 are always clear on the 80286 processor.
;
		or	bx,0F000h	; try to set bits 12-15
		push	bx
		popf
		pushf
		pop	ax
		and	ax,0F000h	; if bits 12-15 are cleared, then 80286
		mov	__8086,2	; turn on 802886 flag
		jz	exit
	
;
;	i386 CPU check
;	The AC bit, bit #18, is a new bit introduced in the EFLAGS register on the i486 DX CPU to 
;	generate alignment faults.  This bit can be set on the i486 DX CPU, but not on the i386 CPU.
;
.386
		mov	edx,esp		; save current stack pointer to align it
		and	sp,not 3	; align stack to avoid AC fault
		pushfd			; push original EFLAGS
		pop	eax		; get original EFLAGS 
		mov	ecx,eax		; save original EFLAGS
		xor	eax,40000h	; flip AC bit in EFLAGS
		push	eax		; save for EFLAGS
		popfd			; copy to EFLAGS
		pushfd			; push EFLAGS
		pop	eax		; get new EFLAGS value
		xor	eax,ecx		; if AC bit cannot be changed, then 80386
		mov	__8086,3	; turn on i386 flag
		mov	esp,edx		; restore stack pointer
		jz	exit	

;	i486 DX CPU / i487 SX MCP and i486 SX CPU checking
;
		mov	__8086,4	; turn on i486 flag

exit:
		ret
		ENDP
_TEXT		ENDS

		END
