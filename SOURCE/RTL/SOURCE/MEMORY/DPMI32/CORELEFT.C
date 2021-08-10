/*---------------------------------------------------------------------------
 * filename - coreleft.cas
 *
 * function(s)
 *    coreleft   - returns a measure of unused memory
 *--------------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 8.0
 *
 *      Copyright (c) 1987, 1997 by Borland International
 *      All Rights Reserved.
 *
 */
/* $Revision:   8.2  $        */

#include <ntbc.h>

/*--------------------------------------------------------------------------*

Name            coreleft - returns a measure of unused memory

Usage           unsigned coreleft(void);

Prototype in    alloc.h

Description     returns a measure of the unused memory.

Return value    the number bytes available in physical memory and
                the paging file.

*---------------------------------------------------------------------------*/

unsigned _RTLENTRY coreleft(void)
{
    MEMORYSTATUS memStat;

    memStat.dwLength = sizeof(MEMORYSTATUS);
    GlobalMemoryStatus(&memStat);

    return (memStat.dwAvailPhys + memStat.dwAvailPageFile);
}
