;[]-----------------------------------------------------------------[]
;|   WCSNCAT.ASM -- appends one wide_character string to another     |
;[]-----------------------------------------------------------------[]

;
;       C/C++ Run Time Library - Version 11.0
; 
;       Copyright (c) 1996, 2002 by Borland Software Corporation
;       All Rights Reserved.
; 

; $Revision: 9.4.2.1 $

        include RULES.ASI

;       Segments Definitions

Header@

;-----------------------------------------------------------------------
;
;Name           wcsncat - appends wide-character strings
;
;Usage          wchar_t *strncat(wchar_t *destin, const wchar_t *source, size_t maxlen);
;
;Prototype in   string.h
;
;Description    wcsncat copies at most maxlen wide- characters of source to the end
;               of destin and then appends a null character. The maximum length
;               of the resulting string is wcslen(destin) + maxlen.
;
;Return value   pointer to destin
;
;-----------------------------------------------------------------------

Code_seg@

Func@   wcsncat, _EXPFUNC, _RTLENTRYF, <pointer dest>, <pointer src>, <int maxlen>
        Link@   esi,edi
        mov     edi,dest        ; get dest string
        mov     edx,edi         ; save dest in edx
        mov     ecx,-1
        xor     ax,ax           ; search for null at end of source string
        cld
	repne   scasw           ; scan one wide-character past null
	lea     esi,[edi-2]     ; esi points to terminating null in dest
        mov     edi,src         ; get src string
        mov     ecx,-1          ; figure out wcslen(src)
        repne   scasw
	not     ecx             ; cx = wcslen(src) + 1
	shl	ecx, 1		; wide-char = 2 bytes ea.
	sub     edi,ecx         ; point edi back to start of src
        xchg    esi,edi         ; esi = src, edi = dest+wcslen(dest)

        dec     ecx             ; don't count the null terminator
        mov     eax,maxlen      ; get maxlen
        cmp     ecx,eax         ; is wcslen(src) <= maxlen?
        jbe     do_copy         ; yes, use wcslen as count
        mov     ecx,eax         ; no, use maxlen as count
do_copy:
	cld
        rep     movsw           ; copy words
        xor     ax,ax           ; store a null terminator
        stosw
        mov     eax, dest       ; return dest

	Unlink@ esi,edi
        Return@

EndFunc@ wcsncat

Code_EndS@

        end

