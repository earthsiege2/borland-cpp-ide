;[]-----------------------------------------------------------------[]
;|   ALLOCA.ASM -- allocate stack space                              |
;[]-----------------------------------------------------------------[]

;
;       C/C++ Run Time Library - Version 1.5
; 
;       Copyright (c) 1991, 1994 by Borland International
;       All Rights Reserved.
; 

        include rules.asi
	include entry.inc

;----------------------------------------------------------------------
; Name          alloca - allocate temporary stack memory
;
; Usage         void *alloca(size_t size);
;
; Prototype in  malloc.h
;
; Description   alloca allocates size bytes on the stack; the allocated
;               space is automatically freed up when the calling function
;               exits.
;
;               Because alloca modifies the stack pointer, do not place calls
;               to alloca in an expression that is an argument to a function.
;
;               If the calling function does not contain any references
;               to local variables in the stack, the stack will not
;               be restored correctly when the function exits, resulting
;               in a program crash.  To ensure that the stack is restored
;               correctly, use the following code in the calling function:
;
;                       char *p;
;                       char dummy[1];
;
;                       dummy[0] = 0;
;                       ...
;                       p = alloca(nbytes);
;
;               This function calls the internal function _alloca.
;               See _alloca.asm for details.

; Return value  Returns a pointer to the allocated stack area on success.
;               If the stack cannot be extended, a NULL pointer is returned.
;               The returned pointer should never be passed to free().
;
; Note          Compatible with Microsoft C and UNIX.  Not recommended.
;               Use malloc() instead.
;----------------------------------------------------------------------

        Entry@   alloca,  _alloca, _RTLENTRY, 4
        end
