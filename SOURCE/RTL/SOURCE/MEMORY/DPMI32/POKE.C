/*-------------------------------------------------------------------------*
 * filename - poke.c
 *
 * function(s)
 *        poke - stores value at a given memory location
 *        pokeb - value at memory location
 *--------------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 1.5
 *
 *      Copyright (c) 1987, 1994 by Borland International
 *      All Rights Reserved.
 *
 */

#pragma inline
#include <dos.h>
#undef  poke
#undef  pokeb

/* Don't allow DPMI32 modules on Win32 */
void _RTLENTRY __disallowDPMI32onWin32(void);
#pragma extref __disallowDPMI32onWin32

/*---------------------------------------------------------------------*

Name            poke - stores value at a given memory location

Usage           void poke(unsigned segment, unsigned offset, int value);

Related
functions usage void pokeb(unsigned segment, unsigned offset, char value);

Prototype in    dos.h

Description     poke stores the integer value at the memory location
                segment:offset.

                If these routines are called when dos.h has been included, they
                will be treated as macros@INDEX[Macros] that  expand to in-line
                code. If you don't include dos.h (or if you do include it and
                #undef the routines) you will get the functions rather than the
                macros.

                pokeb is the same as poke, except that a byte value is
                deposited instead of an integer.

Return value    None

*---------------------------------------------------------------------*/
void _RTLENTRY poke(unsigned segment, unsigned offset, int value)
{
        asm     push es
        asm     push ebx
        asm     mov es, segment
        _EBX =  offset;
        asm     mov eax, value
        asm     mov es:[ebx], eax
        asm     pop ebx
        asm     pop es
}


/*---------------------------------------------------------------------*

Name            pokeb - value at memory location

Usage           #include <dos.h>
                void pokeb(unsigned segment, unsigned offset, char value);

Prototype in    dos.h

Description     see poke

*---------------------------------------------------------------------*/
void _RTLENTRY pokeb(unsigned segment, unsigned offset, char value)
{
        asm     push es
        asm     push ebx
        asm     mov es, segment
        _EBX =  offset;
        asm     mov al, value
        asm     mov es:[ebx], al
        asm     pop ebx
        asm     pop es
}
