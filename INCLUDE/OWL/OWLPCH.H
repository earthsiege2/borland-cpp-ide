//----------------------------------------------------------------------------
// ObjectWindows
// (C) Copyright 1992, 1994 by Borland International, All Rights Reserved
//
//   Include for Owl, gets owlcore.h or owlall.h when precompiled headers are
//   enabled.
//----------------------------------------------------------------------------
#if defined(_OWLALLPCH) && !defined(OWL_OWLALL_H)
#  include <owl/owlall.h>
#elif defined(_OWLPCH) && !defined(OWL_OWLCORE_H)
#  include <owl/owlcore.h>
#endif
