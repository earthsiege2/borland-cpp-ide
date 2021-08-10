;[]-----------------------------------------------------------------[]
;|   SETJMP.ASM -- non-local gotos                                   |
;[]-----------------------------------------------------------------[]

;
;       C/C++ Run Time Library - Version 10.0
; 
;       Copyright (c) 1991, 2000 by Inprise Corporation
;       All Rights Reserved.
; 

; $Revision:   9.0  $

        include RULES.ASI

;       Segments Definitions

Header@

; Structure of a jmp_buf.  The layout was chosen for compatibility with MSC.

jmp_buf STRUC
        j_ebp       dd      ?
        j_ebx       dd      ?
        j_edi       dd      ?
        j_esi       dd      ?
        j_esp       dd      ?
        j_ret       dd      ?
        j_excep     dd      ?
	j_context   dd      ?
jmp_buf ENDS

ExtFunc@ _CurrExcContext, _RTLENTRY, 4
ExtFunc@ _Local_unwind, _RTLENTRY, 8


;-----------------------------------------------------------------------
;
;Name            setjmp - nonlocal goto
;
;Usage           #include <setjmp.h>
;                int setjmp(jmp_buf jmpb);
;
;Prototype in    setjmp.h
;
;Description     Saves   current context information     (register,  stack
;                position, and segment values)  in the jmp_buf structure and
;                then returns to the caller.
;
;                Setjmp returns 0 when called directly. The caller of setjmp
;                may be  "returned to" again  by longjmp, when  the function
;                result will never be zero.
;
;                The jmp_buf contains  the entire context necessary for  a C
;                task, including  all segments and  the complete flag  word.
;                Only  the  EX,ECX, and EDX  registers are lost, but then the
;                caller  of setjmp  does not expect them  to be  preserved
;                through a function call.
;
;                On entry, the stack frame looks like:
;
;                top     EIP
;                        jmp_buf pointer
;
;Return value    setjmp returns 0 when it is initially called.
;
;------------------------------------------------------------------------

Code_seg@

Func@   setjmp, _EXPFUNC, _RTLENTRYF, <pointer jbuf>

	mov	eax, fs:[0]		; get exception error record
	push	eax			
	Call@   _CurrExcContext		; get exception context
	mov	edx, eax

        pop     ecx                     ; get return address
        pop     eax                     ; get pointer to jmp_buf
        mov     [eax.j_ebp], ebp        ; save EBP
        mov     [eax.j_ebx], ebx        ; save EBX
        mov     [eax.j_edi], edi        ; save EDI
        mov     [eax.j_esi], esi        ; save ESI
        mov     [eax.j_esp], esp        ; save ESP
        mov     [eax.j_ret], ecx        ; save return address
        mov     [eax.j_context], edx    ; save context number
        mov     edx,fs:[0]              ; get head of exception chain
        mov     [eax.j_excep],edx       ; save it
        xor     eax,eax                 ; always return 0
    if PopParms@ eq 0
        sub     esp, 4                  ; fake setjmp arg for caller to pop
    endif
        jmp     ecx                     ; return

EndFunc@ setjmp


;-----------------------------------------------------------------------
;
;Name            longjmp - performs a nonlocal goto
;
;Usage           #include <setjmp.h>
;                void longjmp(jmp_buf jmpb, int retval);
;
;Prototype in    setjmp.h
;
;Description     Restores context information (register, stack position, and
;                segment  values)  from  the  jmp_buf  structure, which must
;                previously  have  been  saved  there  by  setjmp,  and then
;                returns to  the original caller  of setjmp with  val as the
;                return value  as if returning  from setjmp. The  difference
;                between  a  setjmp  return  and  a  longjmp  is that setjmp
;                returns zero, longjmp returns "val". Val can never be zero:
;                if zero argument is supplied, 1 is substituted.
;
;                Longjmp never returns to its own caller. If the contents of
;                jmpb  are not  set, or  if  the  context therein  is for  a
;                function which  is not now  active (if it  has finished and
;                returned) then  the result will  generally be to  crash the
;                program.  The safest  styles of  use of  the setjmp/longjmp
;                pair are to effect a  return  upward through several nested
;                procedure layers  to a parent procedure  designed to handle
;                exceptions, or  to place both  setjmp and longjmp  within a
;                single scheduler/event handler lexical block.
;
;Return value    longjmp  cannot return  the value  0; if  passed 0  in val,
;                longjmp will return 1.
;
;------------------------------------------------------------------------

ExtFunc@ RtlUnwind, APIENTRY, 12

Func@   longjmp, _EXPFUNC, _RTLENTRYF, <pointer jbuf>, <int retval>

; Call RtlUnwind to get rid of exception handlers that may been added to
; the chain since the setjmp() that set up this jmp_buf.  Skip this step
; if the head handler on the the chain is the same as when setjmp() was
; called.

        pop     eax                     ; discard return address
        mov     ecx,[esp]               ; get jmp_buf address
        mov     eax,[ecx.j_excep]       ; address of excep. reg. record
        cmp     eax,fs:[0]              ; if the exception list hasn't changed,
        je      no_global_unwind        ;  don't bother to unwind

        push    [saveESP]
        mov     saveESP, esp            ; save ESP since it gets trashed

        push    0                       ; NULL exc.
        push    offset FLAT: return     ; address of new EIP (simulate return)
        push    eax                     ; exc. reg. record
        call    RtlUnwind@              ; unwind exceptions
return:
        mov     esp, [saveESP]          ; restore ESP
        pop     [saveESP]

	mov     ecx,[esp]               ; get jmp_buf address
        mov     eax,[ecx.j_excep]       ; address of excep. reg. record
        mov     fs:[0], eax             ; set fs:0 for safety

no_global_unwind:
	push	eax
	Call@   _CurrExcContext
	cmp	eax, -1			; check if exception record is ours
	je	done_unwind		; if not then done
	mov     ecx,[esp]               ; get jmp_buf address
        cmp     eax,[ecx.j_context]     ; check if context records are same
	je	done_unwind		; if so then done
	push	[ecx.j_context]
	push	[ecx.j_excep]
	Call@	_Local_unwind

done_unwind:
        pop     ecx                     ; get pointer to jmp_buf

; Restore registers and return to original setjmp() caller.

        pop     eax                     ; get return value
        cmp     eax, 1                  ; disallow zero return
        adc     eax, 0                  ; eax += (eax == 0)
        mov     ebp, [ecx.j_ebp]        ; restore EBP
        mov     ebx, [ecx.j_ebx]        ; restore EBX
        mov     edi, [ecx.j_edi]        ; restore EDI
        mov     esi, [ecx.j_esi]        ; restore ESI
        mov     esp, [ecx.j_esp]        ; restore ESP
    if PopParms@ eq 0
        sub     esp, 4                  ; fake setjmp arg for caller to pop
    endif
__DoLongJump__:
        jmp     dword ptr [ecx.j_ret]   ; jump to return address

public __DoLongJump__

EndFunc@ longjmp

Code_EndS@

Data_Seg@

        saveESP dd ?

Data_EndS@

        end
