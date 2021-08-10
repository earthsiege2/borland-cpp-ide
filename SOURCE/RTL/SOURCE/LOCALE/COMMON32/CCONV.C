/*
*
*    CCONV.C
*
*    the "C" locale lconv structure.
*
*/

/*
 *      C/C++ Run Time Library - Version 1.5
 *
 *      Copyright (c) 1987, 1994 by Borland International
 *      All Rights Reserved.
 *
 */


#include <string.h>
#include <ctype.h>
#include <limits.h>
#include <_locale.h>

struct lconv _EXPDATA _localeconvention =

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

struct lconv * _RTLENTRY _EXPFUNC localeconv( void )
{
  return( &_localeconvention );
}


