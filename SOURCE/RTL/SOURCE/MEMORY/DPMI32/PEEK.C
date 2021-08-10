/*-------------------------------------------------------------------------*
 * filename - peek.c
 *
 * function(s)
 *        peek  - examines memory location
 *        peekb - examines memory location
 *--------------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 2.0
 *
 *      Copyright (c) 1987, 1996 by Borland International
 *      All Rights Reserved.
 *
 */

#pragma inline
#include <dos.h>
#undef  peek
#undef  peekb

/* Don't allow DPMI32 modules on Win32 */
void _RTLENTRY __disallowDPMI32onWin32(void);
#pragma extref __disallowDPMI32onWin32

/*---------------------------------------------------------------------*

Name            peek - examines memory location

Usage           int peek(unsigned segment, unsigned offset);

Related
functions usage char peekb(unsigned segment, unsigned offset);

Prototype in    dos.h

Description     peek and peekb examine the memory location addressed
                by segment:offset.

                If these routines are called when dos.h has been included,
                they will be treated as macros that  expand to in-line code.
                If you don't include dos.h (or if you do include it and
                #undef the routines) you will get the functions rather
                than the macros.

Return value    peek and peekb return the value stored at the
                memory location segment:offset. peek returns a word, and
                peekb returns a byte.

*---------------------------------------------------------------------*/
int _RTLENTRY peek(unsigned segment, unsigned offset)
{
        asm     push es
        asm     push ebx
        asm     mov es, segment
        _EBX =  offset;
        asm     mov eax, es:[ebx]
        asm     pop ebx
        asm     pop es
        return _EAX;
}


/*---------------------------------------------------------------------*

Name            peekb - examines memory location

Usage           #include <dos.h>
                char peekb(unsigned segment, unsigned offset);

Prototype in    dos.h

Description     see peek above

*---------------------------------------------------------------------*/
char _RTLENTRY peekb(unsigned segment, unsigned offset)
{
        asm     push es
        asm     push ebx
        asm     mov es, segment
        _EBX =  offset;
        asm     xor eax, eax
        asm     mov al, es:[ebx]
        asm     pop ebx
        asm     pop es
        return _AL;
}
