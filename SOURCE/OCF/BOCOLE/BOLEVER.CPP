//----------------------------------------------------------------------------
// ObjectWindows
// (C) Copyright 1991, 1994 by Borland International, All Rights Reserved
//
//   OWL global version structure for vprint
//----------------------------------------------------------------------------
#include "bolever.h"

#define WhoIsUs "BOCOLE"

struct TVersionHeader {
  char          Signature[6];
  unsigned long InternalVersionNumber;
  char          ComponentIdString[sizeof(WhoIsUs)+1];
};

TVersionHeader VersionHeader = {
  {'$', '*', '$', '*', '$', '*'},
  {BOLE_FILEVER_LS},
  WhoIsUs,
};

