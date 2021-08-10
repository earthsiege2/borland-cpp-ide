;[]-----------------------------------------------------------------[]
;|      F87ATAN.ASM                                                  |
;[]-----------------------------------------------------------------[]

;
;       C/C++ Run Time Library - Version 10.0
; 
;       Copyright (c) 1986, 2000 by Inprise Corporation
;       All Rights Reserved.
; 

; $Revision:   9.0  $

        include RULES.ASI

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
; ArcTan
;
; There are two symmetries used here:

; a)    ATan (1/x) = Pi/2 - ATan (x)
; b)     ATan (-x) = - ATan (x)

; Special cases are:

;  0 = ArcTan (0)
;  Pi/2 = ArcTan (infinity)


Func@   _f87_ArcTan, public, _RTLENTRY

atan_status     equ     [esp].w0

        fxam                            ; keep '87 busy in parallel

        sub     esp,4                   ; make room for atan_status

        fstsw   atan_status
        wait
        mov     ah, atan_status.by1
        sahf                            ; FL now reflects FXAM status
        xchg    cx, ax                  ; save for later negation check
        jc      atan_badParam
        jnz     atan_normal

atan_tiny:                              ; denormal or zero
        jmp     short   atan_end        ; Atan (tiny) = tiny


atan_badParam:                          ; NAN, infinite, or Empty
        jz      atan_empty              ; st(0) was empty
        jnp     atan_NAN                ; st(0) was NAN
        fstp    st(0)                   ; st(0) was infinite, pop it
        fld     piBy2                   ;   Atan (infinity) = pi/2
        jmp     short   atan_setSign


atan_of1:
        fcompp                          ; pop stack twice
        fld     piBy4
        jmp     short   atan_setSign


atan_normal:
        fabs
        fld1
        fcom
        fstsw   atan_status
        wait
        mov     ah, atan_status.by1
        sahf                            ; FL now reflects FCOM status

        je      atan_of1                ; st(1)=st(0)=1 is a special case
        jnc     atan_ordered

        fxch                            ; st(1) > st(0) requires inversion

atan_ordered:
        fpatan
        jnc     atan_setSign            ; flags still indicate FCOM status

        fld     piBy2
        fsub
        xor     ch, 02                  ; invert sign flag

atan_setSign:
        test    ch, 02                  ; what was parameters true sign ?
        jz      atan_end

        fchs                            ; parameter was negative

atan_NAN:
atan_empty:
atan_end:
        add     esp,4
        ret

EndFunc@ _f87_ArcTan

Code_EndS@

        end
