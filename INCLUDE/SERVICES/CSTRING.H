//----------------------------------------------------------------------------
// Borland Services Library
// Copyright (c) 1993, 1996 by Borland International, All Rights Reserved
//
//$Revision:   5.4  $
//
// Reliable header for standard C++ string class
//----------------------------------------------------------------------------
#if !defined(SERVICES_CSTRING_H)
#define SERVICES_CSTRING_H

#if !defined(SERVICES_DEFS_H)
# include <services/defs.h>
#endif

#if defined(BI_COMP_BORLANDC)
# if defined(BI_PLAT_MSW) && !defined(SERVICES_WSYSINC_H)
#   include <services/wsysinc.h>  // Let services get MSW headers, not RTL
# endif
# include <cstring.h>
#else
# include <services/private/cstring.h>
#endif

#endif
