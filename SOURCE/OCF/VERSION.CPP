//----------------------------------------------------------------------------
// ObjectComponents
// Copyright (c) 1994, 1997 by Borland International, All Rights Reserved
//
// $Revision:   2.4  $
//----------------------------------------------------------------------------
#include <ocf/version.h>

#if     !defined(WHOAMI)
# define WHOAMI "OCF"
#endif

struct VersionHeader {
  // The next three fields must be consecutive for VPRINT to locate
  // the info
        // Therefore, watch for 'improper' alignment settings.
        //
  char          VprintSignature[6];
  unsigned long InternalVersion;
  char          ComponentIDstring[ sizeof( WHOAMI )];
};

// The following is for VPRINT's usage
//
VersionHeader HeaderVersion = {
  {'$', '*', '$', '*', '$', '*'},
  { OCFInternalVersion },
  WHOAMI,
};
