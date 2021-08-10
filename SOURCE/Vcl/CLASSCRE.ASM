	.386
	.MODEL  FLAT

	LOCALS  @@

	PUBLIC  __ClassCreate,__ClassDestroy,__AfterConstruction,__BeforeDestruction


vtAfterConstruction EQU -28
vtBeforeDestruction EQU -24
vtNewInstance       EQU -12
vtFreeInstance      EQU -8

	.CODE

__ClassCreate PROC
	; ->    EAX = pointer to VMT
	; <-    EAX = pointer to instance
	PUSH    EDX
	PUSH    ECX
	CALL    dword ptr [EAX].vtNewInstance
	POP     ECX
	POP     EDX
	RET

__ClassCreate ENDP


__ClassDestroy  PROC
	; ->    EAX = pointer to instance
	MOV     EDX,[EAX]
	JMP     dword ptr [EDX].vtFreeInstance

__ClassDestroy  ENDP


__AfterConstruction PROC
	; ->    EAX = pointer to instance

	PUSH    EAX
	MOV     EDX,[EAX]
	CALL    dword ptr [EDX].vtAfterConstruction
	POP     EAX
	RET

__AfterConstruction ENDP

__BeforeDestruction PROC
	; ->    EAX  = pointer to instance
	;       DL   = dealloc flag

	TEST    DL,DL
	JG      @@outerMost
	RET
@@outerMost:
	PUSH    EAX
	PUSH    EDX
	MOV     EDX,[EAX]
	CALL    dword ptr [EDX].vtBeforeDestruction
	POP     EDX
	POP     EAX
	RET

__BeforeDestruction ENDP

public  __roundToInt64
__roundToInt64  proc    near

	sub     esp, 8
	fld     tbyte ptr [esp + 12]
	fistp   qword ptr [esp]
	pop     eax
	pop     edx
	ret

__roundToInt64  endp

;
; The code previously in this section has been moved into the RTL
; (file CRTLVCL.CPP) to fix BCB-12433
;

	end
