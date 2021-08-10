;[]-----------------------------------------------------------------[]
;|   SETEXC.ASM -- install, remove, and unwind exception handlers    |
;[]-----------------------------------------------------------------[]

;
;       C/C++ Run Time Library - Version 8.0
; 
;       Copyright (c) 1991, 1997 by Borland International
;       All Rights Reserved.
; 
; $Revision:   8.2  $

        include rules.asi

        Header@

        Code_Seg@

;---------------------------------------------------------------------
;
;Name            _SetExceptionHandler - install exception handler
;
;Usage           void _SetExceptionHandler(PEXCEPTIONREGISTRATIONRECORD p);
;
;Prototype in    dosexcpt.h
;
;Related
;functions usage void UnsetExceptionHandler(PEXCEPTIONREGISTRATIONRECORD p);
;
;Description     This function inserts the specified exception
;                registration record at the head of the current
;                thread's exception chain.  This is similar to
;                the OS/2 DosSetExceptionHandler function.
;
;Return value    None.
;
;---------------------------------------------------------------------

Func@ _SetExceptionHandler, public, cdecl, <pointer regrec>

        Link@
        mov     eax, regrec         ; get exception register record to install
        mov     ecx, fs:[0]         ; get current head of chain
        mov     [eax], ecx          ; save current head
        mov     fs:[0], eax         ; install new record at head
        Unlink@
        Return@

EndFunc@ _SetExceptionHandler

;---------------------------------------------------------------------
;
;Name            _UnsetExceptionHandler - remove RTL exception handler
;
;Usage           void _UnsetExceptionHandler(PEXCEPTIONREGISTRATIONRECORD p);
;
;Prototype in    dosexcpt.h
;
;Related
;functions usage void _UnsetExceptionHandler(PEXCEPTIONREGISTRATIONRECORD p);
;
;Description     This function removes the specified exception registration
;                record from the current thread's exception chain.  This
;                is similar to the OS/2 Dos_UnsetExceptionHandler function.
;
;Return value    None.
;
;---------------------------------------------------------------------

Func@ _UnsetExceptionHandler, public, cdecl, <pointer regrec>

        Link@
        mov     eax, regrec         ; get exception register record to remove
        mov     ecx, fs:[0]         ; get current head of chain
        cmp     eax, ecx            ; is this the head of the chain?
        jne     search              ; no - we have to search the list
        mov     eax, [eax]          ; get next record on list
        mov     fs:[0], eax         ; make this the new head
return:
        Unlink@
        Return@
search:
        cmp     ecx, -1             ; at end of list?
        je      return              ; yes - didn't find it
        cmp     [ecx], eax          ; is it the next one on the list?
        je      unlink              ; yes - unlink our record
        mov     ecx, [ecx]          ; no - look at next one on list
        jmp     search
unlink:
        mov     eax, [eax]          ; get next record on list
        mov     [ecx], eax          ; unlink our record
        jmp     return
EndFunc@ _UnsetExceptionHandler

;---------------------------------------------------------------------
;
;Name            _UnwindException - Unwind exception handlers
;
;Usage           void _cdecl _UnwindException
;                       (PEXCEPTIONREGISTRATIONRECORD regrec,
;                        PVOID targetip,
;                        PEXCEPTIONREPORTRECORD rptrec);
;
;Prototype in    dosexcpt.h
;
;Description     This function unwinds active exception handlers until
;                the specified exception handler (regrec) is reached.
;                If regrec is NULL, all handlers for the current thread
;                are unwound.  If rptrec is not NULL, each handler
;                that is called during the unwind process is called
;                with this as the exception report record.  This
;                is similar to the OS/2 DosUnwindException function.
;
;                The function does not return to the caller;
;                instead, it jumps the address specified by targetip.
;
;Return value    None.
;
;---------------------------------------------------------------------

ExtFunc@ RtlUnwind, APIENTRY, 12

Func@ _UnwindException, public, cdecl, <pointer rg>, <pointer i>, <pointer rp>

        jmp     RtlUnwind@         ; jump to the Win32 API that does it all

EndFunc@ _UnwindException

        Code_EndS@
        end
