//----------------------------------------------------------------------------
// Borland Services Library
// Copyright (c) 1995, 1997 by Borland International, All Rights Reserved
//
//$Revision:   5.4  $
//
//----------------------------------------------------------------------------
#if !defined(SERVICES_DIR_H)
#define SERVICES_DIR_H

#if !defined(SERVICES_DEFS_H)
# include <services/defs.h>
#endif

#if defined(BI_COMP_BORLANDC)
# include <dir.h>

#elif defined(BI_COMP_MSC)
# include <direct.h>

#else
# error  "Need <dir.h> equivalent header file to be included"
#endif

#endif  //  SERVICES_DIR_H
