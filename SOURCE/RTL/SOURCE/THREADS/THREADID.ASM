;[]-----------------------------------------------------------------[]
;|   THREADID.ASM -- routines to access thread information block     |
;[]-----------------------------------------------------------------[]

;
;       C/C++ Run Time Library - Version 11.0
; 
;       Copyright (c) 1991, 2002 by Borland Software Corporation
;       All Rights Reserved.
; 

; $Revision: 9.4.2.1 $

        include RULES.ASI

;       Segments Definitions

Header@

;----------------------------------------------------------------------
;Name           __threadid - return thread ID
;
;Usage          #include <stddef.h>
;               unsigned long _RTLENTRY __threadid(void);
;
;Prototype in   stddef.h
;
;Description    This function returns the current thread ID.  FS points to
;               the TEB (thread environment block?), and at offset 18H
;               there is a DS-relative alias for the TEB.  The thread ID
;               itself is at offset 24H in the TEB.
;
;Return value   A long word containing the current thread ID.
;------------------------------------------------------------------------

Code_seg@

Func@   __threadid, _EXPFUNC, _RTLENTRY

        mov     eax,fs:[18h]            ; get alias for TEB
        mov     eax,[eax+24h]           ; get address of thread ID
        ret
        align   4

EndFunc@ __threadid

Code_EndS@

        end
