;[]-----------------------------------------------------------------[]
;|   GENINT.ASM -- DPMI32 interrupt generation routine               |
;[]-----------------------------------------------------------------[]

;
;       C/C++ Run Time Library - Version 2.0
; 
;       Copyright (c) 1994, 1996 by Borland International
;       All Rights Reserved.
; 

.386

_TEXT   SEGMENT DWORD PUBLIC 'CODE' USE32

	PUBLIC  __genericInterrupt

intTable        label   byte
	intNum = 0
	REPT    256
	db      0CDh
	db      intNum
	intNum = intNum + 1
	ret
	nop
	endm

__genericInterrupt      PROC NEAR

	push    eax                                     ;save eax
	push    ebx                                     ;save ebx
	mov     ebx, dword ptr [esp + 12]               ;get interrupt number
	lea     eax, intTable                           ;point to interrupt table
	shl     ebx, 2                                  ;multiply by 4 for displacement
	add     eax, ebx                                ;get final ptr to interrupt code snippet
	xchg    eax, [esp + 4]                          ;restore eax, and set up stack for
							; return to interrupt code
	pop     ebx                                     ;restore ebx
	ret

__genericInterrupt      ENDP

_TEXT   ENDS

	END

