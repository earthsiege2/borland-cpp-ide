/*-----------------------------------------------------------------------*
 * filename - cconv.c
 *
 *    the "C" locale lconv structure.
 *
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 10.0
 *
 *      Copyright (c) 1996, 2000 by Inprise Corporation
 *      All Rights Reserved.
 *
 */

/* $Revision:   9.0  $        */

#include <string.h>
#include <ctype.h>
#include <limits.h>
#include <_locale.h>

struct lconv _localeconvention =

{
    ".",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    CHAR_MAX,
    CHAR_MAX,
    CHAR_MAX,
    CHAR_MAX,
    CHAR_MAX,
    CHAR_MAX,
    CHAR_MAX,
    CHAR_MAX
};

struct lconv * _Cdecl localeconv( void )
{
  return( &_localeconvention );
}
