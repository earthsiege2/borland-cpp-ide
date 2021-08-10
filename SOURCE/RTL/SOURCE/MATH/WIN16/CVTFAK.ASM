;[]-----------------------------------------------------------------[]
;|      CVTFAK.ASM -- abort when float isn't present                 |
;|                                                                   |
;[]-----------------------------------------------------------------[]

;
;       C/C++ Run Time Library - Version 6.5
; 
;       Copyright (c) 1987, 1994 by Borland International
;       All Rights Reserved.
; 


	INCLUDE RULES.ASI

;	External references

extrn		__errorExitBox:near

;	Public references

		public	__cvtfak
__cvtfak	equ	0

_TEXT		segment
                assume cs:_TEXT, ds:DGROUP
;-------------------------------------------------------------------------
;		Copy printf() specific part of message in place of scanf()
;-------------------------------------------------------------------------
_FakRealCvt	proc near
		mov	si, offset DGROUP: PrintMSG
                mov     di, offset DGROUP: CommonMSG
                push    ds
                pop     es
                mov     cx, Print_UNIQ

                repnz   movsb

;-------------------------------------------------------------------------
;		Get address of message
;-------------------------------------------------------------------------
_FakScanTod:
		mov	di, offset DGROUP: CommonMSG	; Message address
;
; By letting the _FakScanTod PROC to 'fall into' the 'DisplayMessage' routine
; we save the cost of a JMP instruction.  This is a somewhat cheap trick but
; the purpose is quite clear here.

;-------------------------------------------------------------------------
;		Display FLOAT not linked message
;-------------------------------------------------------------------------
                mov     ax, 3
                push    ax
                push    di

                call    __errorExitBox

                add sp, 4

                ret

		endp
     		ends

_DATA           segment
;-------------------------------------------------------------------------
;		Message texts for 'float not linked' messages
;
; Note : by putting an 'extra' blank in the scanf unique message part we
; save some code space by having a common message length.
;-------------------------------------------------------------------------
;
; Message part unique to the printf() message.
;
PrintMSG 	db	'print' 	; Unique part of 'printf' message
Print_UNIQ	equ	$ - PrintMSG	; Length of unique msg parts
;
; Message part common to the 'printf and 'scanf' messages.
;
CommonMSG	db	' scanf : floating point formats not linked', 0
DSegEnd@

_CVTSEG SEGMENT WORD PUBLIC 'DATA'
_realcvt	dw	offset _FakRealCvt
_CVTSEG ENDS

_SCNSEG SEGMENT WORD PUBLIC 'DATA'
__scantod	dw	offset _FakScanTod
__scanrslt	dw	offset _FakScanTod
__scanpop	dw	offset _FakScanTod
_SCNSEG ENDS

	END
