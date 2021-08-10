//----------------------------------------------------------------------------
// ObjectWindows - (C) Copyright 1991, 1993 by Borland International
//   source\owl\version.cpp
//   OWL global version structure
//----------------------------------------------------------------------------
#include <owl\version.h>

#define WhoIsUs "OWL"

struct TVersionHeader {
  char          Signature[6];
  unsigned long InternalVersionNumber;
  char          ComponentIdString[sizeof(WhoIsUs)+1];
};

TVersionHeader VersionHeader = {
  {'$', '*', '$', '*', '$', '*'},
  {InternalVersion},
  WhoIsUs,
};
