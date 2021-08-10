//----------------------------------------------------------------------------
// Borland Class Library
// Copyright (c) 1993, 1997 by Borland International, All Rights Reserved
//
//$Revision:   5.8  $
//
// Internal version marking structure
//----------------------------------------------------------------------------
#include <classlib/version.h>
#include <tchar.h>

#define ID "CLASSLIB"

struct TVersionHeader
{
    _TCHAR          Signature[6];
    unsigned long InternalVersionNumber;
    _TCHAR          ComponentIDstring[sizeof ID];
} VersionHeader =

{
    {'$', '*', '$', '*', '$', '*'},
    {InternalVersion},
    ID
};
