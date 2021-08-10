//----------------------------------------------------------------------------
// Borland BIDS Container Library
// Copyright (c) 1992, 1997 by Borland International, All Rights Reserved
//
//$Revision:   5.13  $
//
//----------------------------------------------------------------------------
#if !defined( CLASSLIB_ALLOCTR_H )
#define CLASSLIB_ALLOCTR_H

#if !defined(CLASSLIB_DEFS_H)
# include <classlib/defs.h>
#endif
#if !defined(__STDLIB_H) && !defined(_INC_STDLIB)
# include <stdlib.h>
#endif

#if defined(BI_CLASSLIB_NO_po)
# pragma option -po-
#endif

#if defined(BI_NAMESPACE)
namespace ClassLib {
#endif

//----------------------------------------------------------------------------
// class TStandardAllocator
// ~~~~~ ~~~~~~~~~~~~~~~~~~
// Provides class-specific operator new and operator delete that simply call
// the global operator new and operator delete.  That is, TStandardAllocator
// does not provide any specialized behavior. It is used in the non-managed
// versions of the parametrized containers.
//
class _BIDSCLASS TStandardAllocator
{
  public:
    friend void _BIDSFAR* _RTLENTRY _EXPFUNC32
            operator new(size_t sz, const TStandardAllocator&)
        { return ::operator new(sz); }
    friend void _BIDSFAR* _RTLENTRY _EXPFUNC32
         operator new(unsigned, void *ptr)
        { return ptr; }
    void _RTLENTRY _EXPFUNC32 operator delete(void _BIDSFAR *ptr)
        { ::operator delete(ptr); }
#if !defined(BI_NO_ARRAYNEW)
    friend void _BIDSFAR* _RTLENTRY _EXPFUNC32
            operator new [] (size_t sz, const TStandardAllocator&)
        { return ::operator new [] (sz); }
    friend void _BIDSFAR* _RTLENTRY _EXPFUNC32
         operator new [] (unsigned, void *ptr)
        { return ptr; }
    void _RTLENTRY _EXPFUNC32 operator delete [] (void _BIDSFAR *ptr)
        { ::operator delete [] (ptr); }
#endif
};

#if defined(BI_OLDNAMES)
# define BI_StandardAllocator TStandardAllocator
#endif

//----------------------------------------------------------------------------
// class TSharedAllocator
// ~~~~~ ~~~~~~~~~~~~~~~~
// Provides class-specific operator new and operator delete that allocate from
// shared memory.
//
class _BIDSFARCLASS TSharedAllocator
{
  public:
    friend void _BIDSFARDATA* operator new(size_t sz, const TSharedAllocator&);
    void operator delete(void _BIDSFARDATA* ptr);
#if !defined(BI_NO_ARRAYNEW)
    friend void _BIDSFARDATA* operator new [](size_t sz, const TSharedAllocator&);
    void operator delete [](void _BIDSFARDATA* ptr);
#endif
};

#if defined(BI_OLDNAMES)
# define BI_SharedAllocator TSharedAllocator
#endif

//----------------------------------------------------------------------------
// template <class T, class Alloc> class TManaged_T
// ~~~~~~~~  ~~~~~ ~  ~~~~~ ~~~~~  ~~~~~ ~~~~~~~~~~
// Provides a parametrized wrapper for type T which uses a class-specific
// operator new and operator delete supplied by Alloc.
//
template <class T, class Alloc> class TManaged_T : private Alloc
{
  public:
    Alloc::operator delete;
#if !defined(BI_NO_ARRAYNEW)
    Alloc::operator delete [];
#endif

    TManaged_T() {}
    TManaged_T(const T& t) : data(t) {}

    const TManaged_T& operator =(const TManaged_T& t)
    {
      data = t.data;
      return *this;
    }

    operator T&()
    {
      return data;
    }

  private:
    T data;
};

#if defined(BI_OLDNAMES)
# define BI_Managed_T TManaged_T
#endif

#if defined(BI_NAMESPACE)
}   // namespace ClassLib
#endif

//----------------------------------------------------------------------------
// TSharedAllocator::operator new
// TSharedAllocator::operator delete
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Normally uses the global operator new and delete for memory allocaiton.
// Users of BIDS for Windows and DPMI DOS applications may wish to
// use GlobalAlloc instead to allow allocation of huge blocks.
// To do so, enable the BI_CLASSLIB_ALLOW_WINALLOC define below:
//
// #define BI_CLASSLIB_ALLOW_WINALLOC
//
#if defined(BI_CLASSLIB_ALLOW_WINALLOC)

#if !defined(SERVICES_WSYSINC_H)
# include <services/wsysinc.h>
#endif
#if !defined(__DOS_H) && !defined(_INC_DOS)
# include <dos.h>
#endif

#if defined(BI_NAMESPACE)
namespace ClassLib {
#endif

inline void _BIDSFARDATA* operator new(size_t sz, const TSharedAllocator&)
{
  return GlobalLock(GlobalAlloc(GHND | GMEM_SHARE, sz));
}

#if defined(BI_NAMESPACE)
}   // namespace ClassLib
#endif

inline void TSharedAllocator::operator delete(void _BIDSFARDATA* ptr)
{
  HGLOBAL hMem = (HGLOBAL)GlobalHandle(FP_SEG(ptr));
  if (GlobalUnlock(hMem) == 0)
    GlobalFree(hMem);
}

#if !defined(BI_NO_ARRAYNEW)

#if defined(BI_NAMESPACE)
namespace ClassLib {
#endif

inline void _BIDSFARDATA* operator new [](size_t sz, const TSharedAllocator&)
{
  return GlobalLock(GlobalAlloc(GHND | GMEM_DDESHARE, sz));
}

#if defined(BI_NAMESPACE)
}   // namespace ClassLib
#endif

inline void TSharedAllocator::operator delete [](void _BIDSFARDATA* ptr)
{
  HGLOBAL hMem = (HGLOBAL)GlobalHandle(FP_SEG(ptr));
  if (GlobalUnlock(hMem) == 0)
    GlobalFree(hMem);
}

#endif  //#if !defined(BI_NO_ARRAYNEW)

#else   //#if defined(BI_PLAT_WIN16) || defined(BI_PLAT_DOS)

#if defined(BI_NAMESPACE)
namespace ClassLib {
#endif

inline void _BIDSFARDATA* operator new(size_t sz, const TSharedAllocator&)
{
  return ::operator new(sz);
}

#if defined(BI_NAMESPACE)
}   // namespace ClassLib
#endif

inline void TSharedAllocator::operator delete(void _BIDSFARDATA* ptr)
{
  ::operator delete(ptr);
}

#if !defined(BI_NO_ARRAYNEW)

#if defined(BI_NAMESPACE)
namespace ClassLib {
#endif

inline void _BIDSFARDATA* operator new [](size_t sz, const TSharedAllocator&)
{
  return ::operator new [](sz);
}

#if defined(BI_NAMESPACE)
}   // namespace ClassLib
#endif

inline void TSharedAllocator::operator delete [](void _BIDSFARDATA* ptr)
{
  ::operator delete [](ptr);
}
#endif  //#if !defined(BI_NO_ARRAYNEW)

#endif  //#if defined(BI_PLAT_WIN16) || defined(BI_PLAT_DOS)

#if defined(BI_CLASSLIB_NO_po)
# pragma option -po.
#endif

#endif  // CLASSLIB_ALLOCTR_H
