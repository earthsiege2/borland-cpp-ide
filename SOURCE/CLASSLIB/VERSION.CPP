/*------------------------------------------------------------------------*/
/*                                                                        */
/*  VERSION.CPP                                                           */
/*                                                                        */
/*  Copyright Borland International 1993                                  */
/*  All Rights Reserved                                                   */
/*                                                                        */
/*------------------------------------------------------------------------*/

#if !defined( __CLASSLIB_VERSION_H )
#include "classlib\version.h"
#endif	// __CLASSLIB_VERSION_H

#define ID "CLASSLIB"

struct TVersionHeader
{
    char          Signature[6];
    unsigned long InternalVersionNumber;
    char          ComponentIDstring[sizeof (ID)];
} VersionHeader =

{
    {'$', '*', '$', '*', '$', '*'},
    {InternalVersion},
    ID
};
