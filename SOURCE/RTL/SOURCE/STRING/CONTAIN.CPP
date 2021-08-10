/*------------------------------------------------------------------------*/
/*                                                                        */
/*  CONTAIN.CPP                                                           */
/*                                                                        */
/*  int string::contains( const char _FAR *cp ) const throw();            */
/*                                                                        */
/*------------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 8.0
 *
 *      Copyright (c) 1992, 1997 by Borland International
 *      All Rights Reserved.
 *
 */
/* $Revision:   8.2  $        */


#include <string.h>
#include <cstring.h>

int string::contains( const char _FAR *cp ) const throw()
{
    return string::find(cp) != NPOS;
}


