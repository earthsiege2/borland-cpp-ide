;[]-----------------------------------------------------------------[]
;|      INIT.INC  --  macro for defining _INIT_ records              |
;[]-----------------------------------------------------------------[]

;
;       C/C++ Run Time Library - Version 2.0
; 
;       Copyright (c) 1991, 1996 by Borland International
;       All Rights Reserved.
; 

; Macro for defining an _INIT_ record for an external function.
; This is used when we have a compiler that doesn't support
; #pragma startup.

;----------------------------------------------------------------------
; Name      InitExt@  - define an _INIT_ record for an external function
;
; Usage     InitExt@ extname, prior, calltype, pubname, val
;
; Notes     The InitExt@ macro defines an _INIT_ record that causes an
;           external function to be called at startup time.
;
;  extname  The name of the external initialization function;
;           the name will be appropriate mangled according to calltype.
;  prior    The priority of the function (0 == highest).
;  calltype Must be _RTLENTRY, _RTLENTRYF, cdecl, pascal, or stdcall
;  pubname  [OPTIONAL] The name of a public symbol to be defined in
;           this module; a leading undescore will be added to the name.
;  val      An optional value to assign to 'pub'.

InitExt@   macro    extname, prior, calltype, pubname, val
    ifnb <pubname>
PUBLIC  _&pubname               ; public symbol to force linking
        ifnb <val>
_&pubname equ     val           ; define absolute symbol
        else
_&pubname equ     0
         endif
    endif
        Mangle@ extrn, extname, <:near>, calltype, 0
        Init@   extname, prior, calltype
        endm
