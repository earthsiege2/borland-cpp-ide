/*-----------------------------------------------------------------------*
 * filename - newf.cpp
 * C++ NEW
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 8.0
 *
 *      Copyright (c) 1990, 1997 by Borland International
 *      All Rights Reserved.
 *
 */
/* $Revision:   8.2  $        */


#include <stddef.h>
#include <alloc.h>
#include <new.h>
#include <rtldata.h>

#if !defined(_BUILDRTLDLL)
extern new_handler _new_handler;
#endif

void far * _EXPFUNC operator new(unsigned long size)
{
    _QRTLDataBlock;
    void far * p;

    size = size ? size : 1;
    while ( (p = farmalloc(size)) == NULL && _QRTLInstanceData(_new_handler) != NULL)
        _QRTLInstanceData(_new_handler)();
    return p;
}

