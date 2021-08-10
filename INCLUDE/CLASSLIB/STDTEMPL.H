//----------------------------------------------------------------------------
// Borland Class Library
// Copyright (c) 1991, 1996 by Borland International, All Rights Reserved
//
//$Revision:   5.7  $
//
// Implements commonly used template functions min(), max(), range()
//
//   T min( T, T ) returns the lesser of its arguments
//
//   T min( T, T, T ) returns the least of its arguments
//
//   T max( T, T ) returns the greater of its arguments
//
//   T max( T, T, T ) returns the greatest of its arguments
//
//   T range( T minVal, T maxVal, T val ) returns val if val is
//       between minVal and maxVal.  If val is greater than maxVal,
//       returns maxVal.  If val is less than minVal, returns minVal.
//
//   void Swap( T, T ) swaps the contents of the two given references
//
//----------------------------------------------------------------------------
#if !defined(CLASSLIB_STDTEMPL_H)
#define CLASSLIB_STDTEMPL_H

#if !defined(CLASSLIB_DEFS_H)
# include <classlib/defs.h>
#endif

//#pragma option -Vo-
#if defined( BI_CLASSLIB_NO_po )
# pragma option -po-
#endif

//
// Make sure that there are no min() or max() macros defined
//
#undef min
#undef max

//
// Check macro to avoid conflict with RTL's template functions
//
#if !defined( __MINMAX_DEFINED )
#define __MINMAX_DEFINED
template <class T> inline const T& min( const T& t1, const T& t2 )
{
    return t1>t2 ? t2 : t1;
}

template <class T> inline const T& max( const T& t1, const T& t2 )
{
    return t1>t2 ? t1 : t2;
}
#endif  // __MINMAX_DEFINED

//
// The following Min() and Max() are for compatibility
//
template <class T> inline T Min(const T& a, const T& b)
{
  return a<b ? a : b;
}

template <class T> inline T Max(const T& a, const T& b)
{
  return a>b ? a : b;
}

template <class T> inline const T& min( const T& t1, const T& t2, const T& t3 )
{
    return t1>t2 ? (t2>t3 ? t3 : t2) : (t1>t3 ? t3 : t1 );
}

template <class T> inline T max( const T& t1, const T& t2, const T& t3 )
{
    return t1>t2 ? (t1>t3 ? t1 : t3) : (t2>t3 ? t2 : t3);
}

template <class T> inline const T& range( const T& minVal, const T& maxVal,
                                          const T& val )
{
    return min( maxVal, max( minVal, val ) );
}

template <class T> inline void Swap(T _BIDSFARDATA& a, T _BIDSFARDATA& b)
{
  T t = a;
  a = b;
  b = t;
}

#if defined( BI_CLASSLIB_NO_po )
# pragma option -po.
#endif
//#pragma option -Vo.

#endif  // CLASSLIB_STDTEMPL_H
