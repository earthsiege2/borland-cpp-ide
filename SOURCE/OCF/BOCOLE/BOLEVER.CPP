//----------------------------------------------------------------------------
// ObjectComponents
// Copyright (c) 1991, 1996 by Borland International, All Rights Reserved
//
// $Revision:   2.1  $
//
//   Global version structure for vprint
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
