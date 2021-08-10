//----------------------------------------------------------------------------
// Borland Class Library
// Copyright (c) 1993, 1996 by Borland International, All Rights Reserved
//
//$Revision:   5.4  $
//
// Internal version marking structure
//----------------------------------------------------------------------------
#include <classlib/version.h>

#define ID "CLASSLIB"

struct TVersionHeader
{
    char          Signature[6];
    unsigned long InternalVersionNumber;
    char          ComponentIDstring[sizeof ID];
} VersionHeader =

{
    {'$', '*', '$', '*', '$', '*'},
    {InternalVersion},
    ID
};
