;[]-----------------------------------------------------------------[]
;|      DDVT.ASM -- DDVT dispatcher                                  |
;[]-----------------------------------------------------------------[]

;
;       C/C++ Run Time Library - Version 1.5
; 
;       Copyright (c) 1991, 1994 by Borland International
;       All Rights Reserved.
; 

        include RULES.ASI

;       Segments Definitions

Header@

Code_Seg@
Code_EndS@


Data_Seg@

FAIL_addr_NULL  dd      0                       ; NULL 'fail' value
FAIL_addr_abort dd      offset FLAT:DDVTabort@  ; RTL  'fail' value

abortmsg        db      'DDVT search failure', 0

Data_EndS@


;----------------------------------------------------------------------
; NULL dispatcher entry point:

Code_Seg@

Func@    @_DDVTdispatchNULL$qpvi,  public, syscall

        mov     eax, offset FLAT:FAIL_addr_NULL
        jmp     SHORT start_dispatch

EndFunc@ @_DDVTdispatchNULL$qpvi

;----------------------------------------------------------------------
; Compiler 'virtual DDVT call' entry point:

Func@   @_DDVTdispatch$qpvi,  public, syscall, <pointer vptr>, <int id>

        mov     eax, offset FLAT:FAIL_addr_abort

start_dispatch:

        Link@   ebx, esi, edi

        mov     esi, eax                ; save 'fail' address
        mov     ebx, vptr               ; get address of vtable
        mov     eax, id                 ; get ID to search for
        std                             ; search down

;
; This is the loop that searches for a matching ID.
;
search_loop:
        mov     ecx, [ebx-8]            ; get # of entries
        jecxz   search_next
;
; The table is below the # of entries, count is in ECX.
; Table format:
;
;           ... table of functions (n entries)
;           ...   ...
;         [-12] table of IDs (n entries)
;         [ -8] no. of table entries (n)
;   vptr->[ -4] base class pointer
;
        mov     edx, ecx                ; save the count
;
; Search this table for a matching ID.
;
        lea     edi, [ebx-12]           ; point at first ID
        repne   scasd
        jne     short search_next
;
; Here if we have a match; [EDI] points just below the matching ID.
;
        neg     edx                     ; negate count
        lea     eax, [edi+edx*4+4]      ; point at function address
done:
        cld
        Unlink@ ebx, esi, edi
ifdef __WIN32__
        ret                             ; on Win32, use _cdecl convention
else
        ret     8                       ; on OS/2, use _stdcall convention
endif

;
; No luck with this class; see if it has a base class.
;
search_next:
        mov     ebx, [ebx-4]            ; get base class link
        or      ebx, ebx
        jnz     search_loop             ; continue if non-zero
;
; No match; return address of the 'fail' function pointer.
;
        mov     eax, esi                ; get 'fail' address
        jmp     SHORT done

EndFunc@ @_DDVTdispatch$qpvi

;----------------------------------------------------------------------
; DDVTabort
;
; Abort the program if a DDVT dispatch fails to find a matching ID.

        ExtFunc@   _ErrorExit, _RTLENTRY, 4

Func@   DDVTabort, static, _RTLENTRY
        push    offset FLAT:abortmsg
        Call@   _ErrorExit             ; never returns
EndFunc@ DDVTabort

;----------------------------------------------------------------------

Code_EndS@

        end

