/*-----------------------------------------------------------------------*
 * filename - tmpnam.c
 *
 * function(s)
 *        tmpnam   - builds a unique file name
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 10.0
 *
 *      Copyright (c) 1987, 2000 by Inprise Corporation
 *      All Rights Reserved.
 *
 */

/* $Revision:   9.0  $        */

#include <stdio.h>
#include <_stdio.h>
#include <_tchar.h>

/*---------------------------------------------------------------------*

Name            _ttmpnam used as tmpnam and _wtmpnam
                tmpnam   - builds a unique file name
                _wtmpnam - builds a unique wide file name

Usage           char *tmpnam(char *s);
                wchar_t *_wtmpnam(wchar_t *s);

Prototype in    stdio.h

Return value    a unique temporary file name

*---------------------------------------------------------------------*/

_TCHAR * _RTLENTRY _EXPFUNC _ttmpnam(_TCHAR *s)
{
    _lock_all_streams();

    s = __ttmpnam(s, &_tmpnum);

    _unlock_all_streams();
    return (s);
}
