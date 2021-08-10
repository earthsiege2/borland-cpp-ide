/*------------------------------------------------------------------------*/
/*                                                                        */
/*  VERSION.CPP                                                           */
/*                                                                        */
/*  Copyright (c) 1993, 1994 Borland International                        */
/*  All Rights Reserved                                                   */
/*                                                                        */
/*------------------------------------------------------------------------*/

#if !defined( CLASSLIB_VERSION_H )
#include <classlib/version.h>
#endif

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
