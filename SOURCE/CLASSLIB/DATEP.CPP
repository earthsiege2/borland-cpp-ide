//----------------------------------------------------------------------------
// Borland Class Library
// Copyright (c) 1993, 1996 by Borland International, All Rights Reserved
//
//$Revision:   5.4  $
//
// TDate class persistant streaming implementation
//----------------------------------------------------------------------------
#include <classlib/pch.h>
#include <classlib/date.h>
#include <classlib/objstrm.h>
#include <strstrea.h>

opstream _BIDSFAR & _BIDSFUNC operator << ( opstream _BIDSFAR & os, const TDate _BIDSFAR & d )
{
    return os << d.Julnum;
}

ipstream _BIDSFAR & _BIDSFUNC operator >> ( ipstream _BIDSFAR & is, TDate _BIDSFAR & d )
{
    return is >> d.Julnum;
}
