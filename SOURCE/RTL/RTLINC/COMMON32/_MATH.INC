;[]-----------------------------------------------------------------[]
;|      _MATH.INC  --  Macros and definitions for math library       |
;[]-----------------------------------------------------------------[]

;
;       C/C++ Run Time Library - Version 8.0
; 
;       Copyright (c) 1987, 1997 by Borland International
;       All Rights Reserved.
; 
; $Revision:   8.1  $

EMU_BROKEN  equ 0   ; set to 0 when fstp st(1) works correctly

;----------------------------------------------------------------------
; Error codes for __matherr and __matherrl

DOMAIN      equ 1   ; argument domain error -- log (-1)
SING        equ 2   ; argument singularity  -- pow (0,-2))
OVERFLOW    equ 3   ; overflow range error  -- exp (1000)
UNDERFLOW   equ 4   ; underflow range error -- exp (-1000)
TLOSS       equ 5   ; total loss of significance -- sin(10e70)
PLOSS       equ 6   ; partial loss of signif. -- not used
STACKFAULT  equ 7   ; floating point unit stack overflow

;----------------------------------------------------------------------
; matherr - macro for calling __matherr
;   why     Error code from above list
;   fun     String identifying the function
;   arg1p   Address of first argument
;   arg2p   Address of second argument
;   retval  Address of double precision floating point value
;
; WARNING: this macro destroys EAX!

matherr macro   why, fun, arg1p, arg2p, retval

ExtFunc@ __matherr, _RTLENTRY, 24

_DATA   SEGMENT  DWORD USE32 PUBLIC 'DATA'
fun&_s  DB  '&fun',  00H
    ALIGN 4
_DATA   ENDS

    push    dword ptr retval[4]
    push    dword ptr retval
    ifidn <arg2p>, <NULL>
    push    0
    else
    lea     eax, arg2p
    push    eax
    endif
    ifidn <arg1p>, <NULL>
    push    0
    else
    lea     eax, arg1p
    push    eax
    endif
    push    offset flat: fun&_s
    push    why
    Call@   __matherr

    endm

;----------------------------------------------------------------------
; matherrl - macro for calling __matherrl
;   why     Error code from above list
;   fun     String identifying the function
;   arg1p   Address of first argument
;   arg2p   Address of second argument
;   retval  Address of extended precision floating point value
;
; WARNING: this macro destroys EAX!

matherrl macro  why, fun, arg1p, arg2p, retval

ExtFunc@ __matherrl, _RTLENTRY, 28

_DATA   SEGMENT  DWORD USE32 PUBLIC 'DATA'
fun&_s  DB  '&fun',  00H
    ALIGN 4
_DATA   ENDS

    push    dword ptr retval[8]
    push    dword ptr retval[4]
    push    dword ptr retval
    ifidn <arg2p>, <NULL>
    push    0
    else
    lea     eax, arg2p
    push    eax
    endif
    ifidn <arg1p>, <NULL>
    push    0
    else
    lea     eax, arg1p
    push    eax
    endif
    push    offset flat: fun&_s
    push    why
    Call@   __matherrl

    endm

;----------------------------------------------------------------------
; f87 - macro for calling the _f87_xxx helper functions.  Using this
; macro avoids having to explicitly declare each function as external,
; which could lead to unwanted code being linked.
;
; The name can be one of the following: Sine, Cosine, Tangent, ArcTan,
; Log, Log2, Log10, Exp, Exp2, or Exp10.

f87 macro   name
ExtFunc@ _f87_&name, _RTLENTRY, 0
    call    _f87_&name&@
    endm

;----------------------------------------------------------------------
; fstp_st1 - macro for executing "fstp st(1)" instruction
;
; Some versions of the OS/2 floating point emulator do not execute
; the "fstp st(x)" instruction correctly when x is non-zero.  Since
; the BC++ math library only needs "fstp st(1)", the following macro
; is used to simulate that instruction.  If the emulator is fixed
; before OS/2 2.0 is released, set EMU_BROKEN to 0 (see top of this file).

fstp_st1 macro
    if EMU_BROKEN
        fxch
        fstp    st(0)
    else
        fstp    st(1)
    endif
    endm
