//----------------------------------------------------------------------------
// ObjectComponents
// Copyright (c) 1994, 1996 by Borland International, All Rights Reserved
//
// $Revision:   2.5  $
//
// Actual BOcOle GUIDs spit out here
//
// NOTE! This file must be compiled with the following flags for 16-bit:
//   -zE_TEXT -zFCODE    (this forces the GUIDs into the code segment)
//----------------------------------------------------------------------------
#define INIT_BGUID            // Force Bolero GUIDs to be defined
#include <ocf/defs.h>         // Ole basics & GUIDs
#if !defined(OCF_OCBOCOLE_H)
# include <ocf/ocbocole.h>    // Bolero GUIDs
#endif

#define INITGUID              // Force OLE GUIDs to be defined
#include <olectlid.h>         // Ole control GUIDs
