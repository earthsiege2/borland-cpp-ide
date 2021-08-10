;[]-----------------------------------------------------------------[]
;|      F87SINE.ASM                                                  |
;[]-----------------------------------------------------------------[]

;
;       C/C++ Run Time Library - Version 10.0
; 
;       Copyright (c) 1986, 2000 by Inprise Corporation
;       All Rights Reserved.
; 

; $Revision:   9.0  $

        include RULES.ASI
        include _MATH.INC

;       Segments Definitions

Header@

; 11 Sep 88     Tanj    unified sources from TB and TC/TP
; 15 Dec 88     tanj    alternative form of NANs for TestaRossa
;  4 Mar 89     Roger   expand domain for Exp()
; 22 Jul 89     Roger   handle INF and NAN in Exp()
; 18 Sep 89     Roger   handle INF in Log()
; 17 Nov 89     Roger   handle NAN in Log(), slight Exp() optimization
;  1 Jun 90     Dave S  adapt to Windows C RTL
; 26 Aug 91     Mark A  adapt to OS/2 C RTL

;----------------------------------------------------------------------
; Special constants are placed here.

Const_Seg@


piBy4           dt      3FFEC90FDAA22168C235r
piBy2           dt      3FFFC90FDAA22168C235r

NANtrig         dd      0FFC04200r

infinity        dd      7F800000R               ; plus infinity

Const_EndS@


;----------------------------------------------------------------------
; General notes:

; - operands are on the iNDP stack
; - results will be on the iNDP stack
; - EAX,EBX,ECX,EDX may be consumed.  Others must be preserved.
; - unnormals are not specifically processed because this module is
;       intended to work with HLL's which place results into IEEE
;       "double" format, whereas only the IEEE "temporary" format can
;       handle unnormals.  If you want to run with assembler programs
;       that may use unnormals then you should check these algorithms
;       for what happens with un-normal parameters.  De-normals are
;       processed correctly, since they have been arranged to follow
;       the same paths as zeroes with only slight extra care needed to
;       accomodate them.

Code_seg@


;----------------------------------------------------------------------
; Sine, Cosine, and Tangent
;

Func@ _f87_Sine, public, _RTLENTRY
        mov     cl, 0           ; remember we want the Sine
        jmp     short   trig
EndFunc@ _f87_Sine

Func@ _f87_Cosine, public, _RTLENTRY
        mov     cl, 2           ; remember we want the Cosine
        jmp     short   trig
EndFunc@ _f87_Cosine

Func@ _f87_Tangent, public, _RTLENTRY

        mov     cl, 4           ; remember we want the Tangent

; the following code is shared by Sine, Cosine, and Tangent

trig:

; trig_sign     CH
; trig_fun      CL
; trig_octant   AL
trig_status     equ     [esp].w0

        fxam                            ; '87 works while we enter routine

        sub     esp,4                   ; make room for trig_status

        fstsw   trig_status
        wait
        mov     ah, trig_status.by1
        sahf                            ; FL now reflects FXAM status
        jc      trig_badParam
        jnz     trig_normal

trig_tiny:                              ; denormal or zero
        cmp     cl, 2                   ; are we trying for cosine ?
        jne     trig_noChange           ;   Sin or Tan (tiny) = tiny
        fstp    ST(0)                   ; pop stack
        fld1                            ; Cos (tiny) = 1.0
trig_noChange:
        jmp     short   trig_endJmp

trig_badParam:                          ; NAN, infinite, or Empty
        jz      trig_empty              ; st(0) was empty
        jnp     trig_NAN                ; st(0) was NAN
        fstp    st(0)                   ; pop st(0)
        fld     NANtrig                 ; st(0) was infinite, now NAN
        ftst                            ; trigger exception
trig_NAN:
trig_empty:
        jmp     short   trig_endJmp


; For numbers of size 2^62 or larger in magnitude, the error of just
;       one lsb in the parameter is equivalent to at least 0.25 radian,
;       and so it is spurious to compute exact results.

; Note that parameters between 2^62 and 2^64 could be exact integers, for
;       which the result may be valid.  However, as we are designing
;       this module to support an HLL which will be using IEEE Long for
;       ordinary storage of variables, only numbers up to 2^53 could be
;       exactly represented (and indeed the limit of 2^62 on parameter is
;       far beyond accurate range).

; This reasoning is also convenient, since the 8087 REM instruction
;       does not process numbers differing by more than 64 bits magnitude.

trig_tooBig:
        fcompp          ; convenient double pop
        fld     NANtrig
        ftst                            ; trigger exception
trig_endJmp:
        jmp     trig_end

;;;;;

trig_normal:                            ; or un-normal
        fabs
        fld     piBy4
        fxam            ; From Intel 287 doc, if quotient is less than 2 then
        fxch            ; C3 equals the value C1 had before the FPREM.
        fprem           ; The FXAM clears C1 since PI/4 is positive.
                        ; NOTE: This behavior does not happen on my 287, but
                        ; it does in the Windows emulator

; while the '87 crunches that, we check the sign the parameter had

        mov     ch, 2
        and     ch, ah                  ; what was the sign ?
        shr     ch, 1                   ; CH = sign

        fstsw   trig_status
        wait
        mov     ah, trig_status.by1
        sahf
        jp      trig_tooBig


; apologies for the following mindbending paragraph.  It takes fewer
;       bytes than a table look-up.

        mov     al, 3
        and     al, ah          ; select the C1 and C0 status bits in AL
        shl     ah, 1           ; shift C3 bit out into carry
        shl     ah, 1
        rcl     al, 1           ; rotate C3 into AL, now AL = 0 C1 C0 C3
        add     al, 0FCh        ; move C1 out to carry
        rcl     al, 1           ; rotate C1 into AL, now AL = ? C0 C3 C1
                                ; ls 3 bits of AL now contain the octant

        cmp     cl, 2           ; are we doing Cosine ?
        jne     trig_notCosine

        add     al, cl          ; Cos (x) = Sin (x + 2 octants)
        mov     ch, 0           ; Cosine has even symmetry around 0
trig_notCosine:
        and     al, 7           ; AL now has octant number


; the octants 1,3,5,7 need (pi/4 - x) as their operand

        test    al, 1
        jz      trig_evens

        fsub                    ; overwrites pi/4 in st(1), pops.
        jmp     short   trig_ptan

; the octants 0,2,4,6 must check against zero operand and remove pi/4
;       from st(1)

trig_evens:
        fstp_st1                ; st(0) overwrites st(1), pops

trig_ptan:
        fptan                   ; returns ST(1)/ST(0) = Tan

; while the '87 crunches that, let's decide what to do with the result

        cmp     cl, 4           ; was it Tangent ?
        je      trig_tangent

; sine or cosine, are similar, varying only in phase of the octant, which
;       we have already adjusted so that the calculation is now only for
;       Sine.

;   octant      sine
;       0       sin (x)
;       1       cos (pi/4 - x)
;       2       cos (x)
;       3       sin (pi/4 - x)
;       4       - sin (x)
;       5       - cos (pi/4 - x)
;       6       - cos (x)
;       7       - sin (pi/4 - x)

        test    al, 3
        jpe     trig_sineOctant         ; even-parity is Sine forms

; Sin (s) = ST(1) / Sqrt (ST(0)^2 + ST(1)^2)
; Cos (x) = ST(0) / Sqrt (ST(0)^2 + ST(1)^2)

trig_cosOctant:
        fxch

trig_sineOctant:
        fld     st(1)           ; make a copy of ST(1)

        fmul    st, st(0)
        fxch
        fmul    st, st(0)
        fadd
        fsqrt

; while sqrt is crunching, what sign do we give the final result ?

        shr     al, 1
        shr     al, 1
        xor     al, ch
        jz      trig_sineDiv

        fchs                    ; cause result to be negative

trig_sineDiv:
        fdiv
        jmp     short   trig_end  ; complete calculation in the caller's time


trig_tangent:

; Tangent is a repeating pattern over 4 octants:

;   octant      tangent
;       0       sin (x) / cos (x)
;       1       cos (pi/4-x) / sin (pi/4 - x)
;       2       -cos (x) / sin (x)
;       3       -sin (pi/4 - x) / cos (pi/4 - x)

; When we arrive here AL = octant and ST(0) = x OR pi/4-x, already
;       adjusted for the octant.

; The PTAN instruction is already initiated, so we now decide what
;       to do with the result.

        mov     ah, al
        shr     ah, 1
        and     ah, 1                   ; octants 2, 3 are negatives
        xor     ah, ch                  ; combine with parameter's sign
        jz      trig_tanSigned

        fchs

trig_tanSigned:
        test    al, 3
        jpe     trig_ratio      ; octants 0, 3 have even parity

; in a freak case, like arg = pi/2 exactly, might get divide by 0
; return tan(pi/2) = +INF, although arguably it should generate an exception
        fxch
        ftst
        fstsw   trig_status
        fwait
        test    trig_status.by1, 40h    ; C3 flag
        jz      trig_ratio
        fcompp                          ; pop st(0) and st(1)
        fld     infinity
        jmp     short   trig_end  ; complete calculation in the caller's time

trig_ratio:
        fdiv
trig_end:
        add     esp,4
        ret                     ; '87 calculates while we return

EndFunc@ _f87_Tangent
Code_EndS@

        end
