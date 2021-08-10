//----------------------------------------------------------------------------
// ObjectWindows
// Copyright (c) 1991, 1997 by Borland International, All Rights Reserved
//
//$Revision:   10.13  $
//
//----------------------------------------------------------------------------
#if !defined(OWL_VERSION_H)
#define OWL_VERSION_H

// Updated for v5.2 - Release 504
//
#define OWLInternalVersion 0x05000400L  // Internal version OWL build with
#define OWLVersion         0x0520       // Version building with: XX.XX
#define OWLVersionStr      "5.2\0\0"   // String version of above

#if defined(__WIN32__)
# define OWLDLLName        "OWL52F\0"
#else
# define OWLDLLName        "OWL52\0"
#endif

#endif  //  OWL_VERSION_H
