/*-----------------------------------------------------------------------*
 * filename - hrdir_g.c
 *
 * function(s)
 *
 *     _get_heap_redirector_info
 *
 *
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 10.0
 *
 *      Copyright (c) 1998, 2000 by Inprise Corporation
 *      All Rights Reserved.
 *
 */

/* $Revision:   9.0  $        */

#include <_hrdir.h>

_heap_redirector_t * _RTLENTRY _EXPFUNC _get_heap_redirector_info (void)
{
    return &_heap_redirector;
}