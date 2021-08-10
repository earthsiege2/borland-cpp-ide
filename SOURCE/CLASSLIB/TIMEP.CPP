//----------------------------------------------------------------------------
// Borland Class Library
// Copyright (c) 1993, 1996 by Borland International, All Rights Reserved
//
//$Revision:   5.4  $
//
// TTime class persistent streaming implementation
//----------------------------------------------------------------------------
#include <classlib/pch.h>
#include <classlib/time.h>
#include <classlib/objstrm.h>
#include <strstrea.h>

opstream _BIDSFAR & _BIDSFUNC operator << ( opstream _BIDSFAR & os,
                                            const TTime _BIDSFAR & d )
{
    return os << d.Sec;
}

ipstream _BIDSFAR & _BIDSFUNC operator >> ( ipstream _BIDSFAR & is,
                                            TTime _BIDSFAR & d )
{
    return is >> d.Sec;
}



