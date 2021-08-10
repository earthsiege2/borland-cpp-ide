/*------------------------------------------------------------------------
 * filename - abs.c
 *
 * function(s)
 *        abs - absolute value
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 8.0
 *
 *      Copyright (c) 1987, 1997 by Borland International
 *      All Rights Reserved.
 *
 */
/* $Revision:   8.2  $        */

#include <stdlib.h>

#undef abs              /* abs is defined as a macro in stdlib.h */

/*------------------------------------------------------------------------*

Name            abs - absolute value

Usage           int abs(int i);

Prototype in    stdlib.h

Description     abs returns the absolute value of the integer argument i

Return value    Integer value in  the range 0 to 32767,  with the exception
                that an argument of -32768 is returned as -32768.
                
*--------------------------------------------------------------------------*/

int _RTLENTRYF _EXPFUNC abs(int i)
{
    return (i >= 0 ? i : -i);
}
