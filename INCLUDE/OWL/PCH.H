//----------------------------------------------------------------------------
// ObjectWindows
// Copyright (c) 1992, 1996 by Borland International, All Rights Reserved
//
//$Revision:   10.2  $
//
// Include for ObjectWindows, gets owlcore.h or owlall.h when precompiled
// headers are enabled.
//----------------------------------------------------------------------------
#if defined(_OWLALLPCH) && !defined(OWL_OWLALL_H)
# include <owl/owlall.h>
#elif defined(_OWLPCH) && !defined(OWL_OWLCORE_H)
# include <owl/owlcore.h>
#endif
