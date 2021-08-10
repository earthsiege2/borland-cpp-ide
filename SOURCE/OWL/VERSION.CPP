//----------------------------------------------------------------------------
// ObjectWindows
// Copyright (c) 1991, 1997 by Borland International, All Rights Reserved
//
//$Revision:   10.9  $
//
// ObjectWindows global version structure for vprint
//----------------------------------------------------------------------------
#if !defined(OWL_DEFS_H)
# include <owl/defs.h>
#endif
#if !defined(OWL_VERSION_H)
# include <owl/version.h>
#endif

OWL_DIAGINFO;

struct __dummyStructure {
 char   c;
 long   l;
};

struct TVersionHeader {
  char          Signature[6];
  unsigned long InternalVersionNumber;
  /*
  char          ComponentIdString[];
  */
};

// NOTE: The following variables must be contiguous in memory
//
TVersionHeader VersionHeader = {
  {'$', '*', '$', '*', '$', '*'},
  {OWLInternalVersion}
};
char WhoAmI[] = "ObjectWindows"

// Codeguard
//
#if defined(__CODEGUARD__)
  ", Codeguarded"
#endif

// Alignment
//
#if   sizeof(__dummyStructure) == 5
  ", Byte aligned"
#elif sizeof(__dummyStructure) == 6
  ", Word aligned"
#elif sizeof(__dummyStructure) == 8
  ", Dword aligned"
#else
  ", Unknown alignment"
#endif

// Diagnostics
//
#if defined(__TRACE)
  ", +TRACE"
#endif
#if defined(__WARN)
  ", +WARN"
#endif
;
