/*-----------------------------------------------------------------------*
 * filename - setnew.cpp
 * C++ new
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
#include <stdlib.h>
#include <new.h>


new_handler _new_handler;

#if !defined(__TINY__) && !defined(NOXX)

#include <cstring.h>
#include <except.h>

xalloc __xalloc( "Out of memory", 0 );

static void xnew_handler() { throw __xalloc; }

static void init_new_handler(void)
{
    set_new_handler(xnew_handler);
}
#pragma startup init_new_handler 0

#endif  /* !__TINY__ && !NOXX */


