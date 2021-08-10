//----------------------------------------------------------------------------
// Borland Class Library
// Copyright (c) 1991, 1996 by Borland International, All Rights Reserved
//
//$Revision:   5.4  $
//
//----------------------------------------------------------------------------
#if !defined(CLASSLIB_SHDDEL_H)
#define CLASSLIB_SHDDEL_H

#if !defined( CLASSLIB_DEFS_H )
# include <classlib/defs.h>
#endif

#pragma option -Vo-
#if defined(BI_CLASSLIB_NO_po)
# pragma option -po-
#endif

//
// class TShouldDelete
// ~~~~~ ~~~~~~~~~~~~~
class TShouldDelete
{
  public:
    enum TDelete { NoDelete, DefDelete, Delete };
    typedef TDelete DeleteType;  // For compatibility

    TShouldDelete(TDelete dt = Delete);

    bool OwnsElements();
    void OwnsElements(bool del);
    bool DelObj(TDelete dt);

#if defined(BI_OLDNAMES)
    int ownsElements() { return OwnsElements(); }
    void ownsElements(int del) { OwnsElements(del); }
    int delObj(DeleteType dt) { return DelObj(dt); }
#endif

  private:
    TDelete ShouldDelete;  // Is either Delete or NoDelete
};

//----------------------------------------------------------------------------
// Inline implementation
//

inline TShouldDelete::TShouldDelete(TDelete dt)
{
  OwnsElements(dt != NoDelete);
}

inline bool TShouldDelete::OwnsElements()
{
  return ShouldDelete == Delete;
}

inline void TShouldDelete::OwnsElements(bool del)
{
  ShouldDelete = del ? Delete : NoDelete;
}

inline bool TShouldDelete::DelObj(TDelete dt)
{
  return dt == Delete || (dt==DefDelete && ShouldDelete==Delete);
}

#if defined(BI_OLDNAMES)
# define BI_ShouldDelete TShouldDelete
#endif

#if defined(BI_CLASSLIB_NO_po)
# pragma option -po.
#endif
#pragma option -Vo.

#endif  // CLASSLIB_SHDDEL_H
