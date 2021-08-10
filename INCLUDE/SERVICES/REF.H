//----------------------------------------------------------------------------
// Borland Services Library
// Copyright (c) 1993, 1997 by Borland International, All Rights Reserved
//
//$Revision:   5.5  $
//
// Implementation of class TReference -- base class for reference counting
//
//----------------------------------------------------------------------------
#if !defined(CLASSLIB_REF_H)
#define CLASSLIB_REF_H

#if !defined(CLASSLIB_DEFS_H)
# include <classlib/defs.h>
#endif

#if defined(BI_COMP_BORLANDC)
# include <ref.h>

#else

#if defined(BI_NAMESPACE)
namespace ClassLib {
#endif

class _EXPCLASS TReference {
  public:
    _RTLENTRY TReference(unsigned short initRef = 0) : Refs(initRef) { }
    void _RTLENTRY AddReference() { Refs++; }
    unsigned short _RTLENTRY References() { return Refs; }
    unsigned short _RTLENTRY RemoveReference() { return --Refs; }

  private:
    unsigned short Refs;    // Number of references to this block
};

#if defined(BI_NAMESPACE)
}     // namespace ClassLib
#endif

#endif  // else if BI_COMP_BORLANDC

#if defined(BI_OLDNAMES)
# define BI_Reference TReference
#endif

#endif  // CLASSLIB_REF_H
