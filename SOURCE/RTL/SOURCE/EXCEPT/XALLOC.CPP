/*
 *      C/C++ Run Time Library - Version 6.5
 *
 *      Copyright (c) 1993, 1994 by Borland International
 *      All Rights Reserved.
 *
 */

#include <except.h>
#include <cstring.h>

_RTLENTRY xalloc::xalloc( const string _FAR & msg, size_t size )
                 : xmsg(msg), siz(size)
{
}

void _RTLENTRY xalloc::raise() throw( xalloc )
{
    throw *this;
}


