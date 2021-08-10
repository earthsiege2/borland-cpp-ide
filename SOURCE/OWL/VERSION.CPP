//----------------------------------------------------------------------------
// ObjectWindows
// (C) Copyright 1991, 1994 by Borland International, All Rights Reserved
//
//   OWL global version structure for vprint
//----------------------------------------------------------------------------
#include <owl/version.h>

#define WhoIsUs "OWL"

struct TVersionHeader {
  char          Signature[6];
  unsigned long InternalVersionNumber;
  char          ComponentIdString[sizeof(WhoIsUs)+1];
};

TVersionHeader VersionHeader = {
  {'$', '*', '$', '*', '$', '*'},
  {ObjectWindowsInternalVersion},
  WhoIsUs,
};
