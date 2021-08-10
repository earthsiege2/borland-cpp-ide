;[]-----------------------------------------------------------------[]
;|      SETJMP.ASM -- entry points for Windows versions of setjmp()  |
;[]-----------------------------------------------------------------[]

;
;       C/C++ Run Time Library - Version 6.0
; 
;       Copyright (c) 1987, 1993 by Borland International
;       All Rights Reserved.
; 

        INCLUDE RULES.ASI

        LOCALS

        assume cs:_TEXT

public  SETJMP
public  LONGJMP

extrn   CATCH            : FAR
extrn   THROW            : FAR
extrn   __CurrExcContext : DIST
extrn   __Local_unwind   : DIST
extrn   __Global_unwind  : DIST

ExceptionList   EQU     14h

JMPBuff STRUC
    j_sp        DW      ?
    j_ss        DW      ?
    j_flag      DW      ?
    j_cs        DW      ?
    j_ip        DW      ?
    j_bp        DW      ?
    j_di        DW      ?
    j_es        DW      ?
    j_si        DW      ?
    j_ds        DW      ?
    j_excep     DW      ?
    j_context   DW      ?
    ENDS

_TEXT   segment

SETJMP  proc PASCAL FAR

        mov     bx, sp
        push    di                              ;save this
        les     di, DWORD PTR ss:[bx + 4]       ;get jmp buff
        mov     ax, ss:[ExceptionList]          ;get exception reg rec
        mov     es:[di].j_excep, ax             ;save it
        push    es                              ;save this
        push    ax                              ;push exception reg rec as arg
        call    __CurrExcContext                ;get context
        pop     cx
        pop     es                              ;restore this
        mov     es:[di].j_context, 0            ;save it
        pop     di                              ;restore this

        jmp    CATCH   ; the catch buffer used by Windows is smaller
                        ; than the one used by TC, so we can simply
                        ; call the Windows function with our buffer
SETJMP  endp

LONGJMP proc PASCAL FAR

        ARG     jmpb    :DWORD, \
                value   :WORD

        ;;
        ;;  Note:  Because we call Windows to restore the state, if
        ;;  we are on another stack, we will do something horrible here.
        ;;  In the DOS version of setjmp, we restore the stack before
        ;;  we attempt to do the unwinds.
        ;;

        ;;
        ;;  If exception list hasn't changed, don't do global unwind:
        ;;
        les     di, jmpb
        mov     ax, es:[di].j_excep
        cmp     ss:[ExceptionList], ax
        je      @@noGlobalUnwind

        push    es                      ;save this across C call
        push    es:[di].j_context       ;push context as arg
        push    ax                      ;push exception reg rec as arg
        call    __Global_unwind
        pop     cx
	pop	cx
        pop     es                      ;restore this

        ;;
        ;;  Reset the exception registration record for safety:
        ;;
        mov     ax, es:[di].j_excep
        mov     ss:[ExceptionList], ax

@@noGlobalUnwind:
        push    es                      ;save this
        push    ax                      ;push as arg
        call    __CurrExcContext        ;get context for exception reg rec
        pop     cx                      ;dump arg
        pop     es                      ;restore this
        cmp     ax, -1                  ;our exception record?
        je      @@doneUnwind            ;no
        cmp     ax, es:[di].j_context   ;are context recs the same?
        je      @@doneUnwind            ;yes, we're done
        push    es:[di].j_context       ;push as arg
        push    es                      ;save this
        call    __Local_unwind
        pop     cx                      ;dump arg
        pop     es                      ;restore this
@@doneUnwind:

        pushf
        cmp     word ptr [bp+6], 1      ;generates carry if param == 0
        adc     word ptr [bp+6], 0      ;if it was zero now it's one
        popf

        mov     sp, bp                  ;dump TASM built stack frame
        pop     bp
        jmp THROW                       ;just as if nothing ever happened

LONGJMP endp

ends

end
