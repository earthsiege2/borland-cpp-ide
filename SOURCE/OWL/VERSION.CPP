//----------------------------------------------------------------------------
// ObjectWindows
// Copyright (c) 1991, 1996 by Borland International, All Rights Reserved
//
//$Revision:   10.4  $
//
// ObjectWindows global version structure for vprint
//----------------------------------------------------------------------------
#if !defined(OWL_VERSION_H)
# include <owl/version.h>
#endif

#if defined(__CODEGUARD__)
# define WhoIsUs "ObjectWindows (CodeGuarded)"
#else
# define WhoIsUs "ObjectWindows"
#endif

struct TVersionHeader {
  char          Signature[6];
  unsigned long InternalVersionNumber;
  char          ComponentIdString[sizeof(WhoIsUs)+1];
};

TVersionHeader VersionHeader = {
  {'$', '*', '$', '*', '$', '*'},
  {OWLInternalVersion},
  WhoIsUs,
};
