;[]------------------------------------------------------------[]
;|   _FTOUL.ASM -- Float to 64-bit unsigned long conversion     |
;[]------------------------------------------------------------[]

;
;       C/C++ Run Time Library - Version 10.0
; 
;       Copyright (c) 1996, 2000 by Inprise Corporation
;       All Rights Reserved.
; 

; $Revision:   9.0  $

        include RULES.ASI

Header@

Data_Seg@

Data_EndS@

Code_Seg@

;
; _ftoul - Takes a float and returns an unsigned __int64
;
; Prototype: unsigned __int64 _ftoul (float value);
;

Func@   _ftoul, _EXPFUNC, cdecl


       	add	esp,-12

       	fstcw   [esp]
       	fwait
       	mov     al,[esp+1]
       	or      byte ptr [esp+1],0Ch ; Rounding control -> Chop
       	fldcw   [esp]
       	fistp   qword ptr [esp+4]
       	mov     byte ptr [esp+1], al
       	fldcw   [esp]
       	mov     eax,[esp+4]
       	mov     edx,[esp+8]

       	add	esp,12

        Return@

EndFunc@ _ftoul

Code_EndS@
end
