//----------------------------------------------------------------------------
// Borland WinSys Library
// Copyright (c) 1995, 1996 by Borland International, All Rights Reserved
//
//$Revision:   5.1  $
//
// Include for winsys gets common includes when precompiled headers are
// enabled.
//----------------------------------------------------------------------------
#if defined(_WSYSPCH) && !defined(WINSYS_PCH_H)
#define WINSYS_PCH_H

#if !defined(WINSYS_DEFS_H)
# include <winsys/defs.h>
#endif
#if !defined(WINSYS_COLOR_H)
# include <winsys/color.h>
#endif
#if !defined(WINSYS_EXBASE_H)
# include <winsys/exbase.h>
#endif
#if !defined(WINSYS_GEOMETRY_H)
# include <winsys/geometry.h>
#endif
#if !defined(WINSYS_LCLSTRNG_H)
# include <winsys/lclstrng.h>
#endif
#if !defined(WINSYS_WSYSINC_H)
# include <winsys/wsysinc.h>
#endif
#if !defined(WINSYS_STRING_H)
# include <winsys/string.h>
#endif
#if !defined(WINSYS_WSYSCLS_H)
# include <winsys/wsyscls.h>
#endif

#endif  // WINSYS_PCH_H
