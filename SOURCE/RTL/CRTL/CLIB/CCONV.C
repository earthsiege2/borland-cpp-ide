/*
*
*    CCONV.C
*
*    the "C" locale lconv structure.
*
*/

/*
 *      C/C++ Run Time Library - Version 6.0
 *
 *      Copyright (c) 1987, 1993 by Borland International
 *      All Rights Reserved.
 *
 */


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
