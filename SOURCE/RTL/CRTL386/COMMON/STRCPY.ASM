;[]-----------------------------------------------------------------[]
;|   STRCPY.ASM -- copy string src to string dest                    |
;[]-----------------------------------------------------------------[]

;
;       C/C++ Run Time Library - Version 6.0
; 
;       Copyright (c) 1991, 1993 by Borland International
;       All Rights Reserved.
; 

        include RULES.ASI

;       Segments Definitions

Header@

;-----------------------------------------------------------------------
;
;Name           strcpy - copy string src to string dest
;
;Usage          char *strcpy (char *dest, const char *src);
;
;Prototype in   string.h
;
;Description    Copy the ASCIIZ string *src to  the buffer *dest. It is the
;               callers responsibility  to ensure that  the dest buffer  is
;               large enough  to contain the  string, and to  guard against
;               supplying NULL arguments.
;
;Return value   strcpy returns dest.
;
;-----------------------------------------------------------------------

Code_seg@

Func@   strcpy, _EXPFUNC, _RTLENTRYF, <pointer dest>, <pointer src>
        Link@   esi,edi
        mov     edi,src         ; get source string
        mov     esi,edi         ; copy to esi and edi
        mov     ecx,-1
        xor     al,al           ; search for null at end of source string
        cld
        repne   scasb           ; scan one character past null
        not     ecx             ; ecx = no. of characters including null
        mov     edi,dest        ; get destination buffer
        mov     eax,edi         ; copy to eax for return value
        mov     edx,ecx         ; save count
        shr     ecx,1           ; calculate longword count
        shr     ecx,1
        cld
        rep     movsd           ; copy longwords
        mov     ecx,edx         ; get back count
        and     ecx,3           ; calculate remainder byte count (0-3)
        rep     movsb           ; copy remaining bytes

        Unlink@ esi,edi
        Return@

EndFunc@ strcpy

Code_EndS@

        end
