/*
 * Copyright (c) 1999 
 * Boris Fomitchev
 *
 * This material is provided "as is", with absolutely no warranty expressed
 * or implied. Any use is at your own risk.
 *
 * Permission to use or copy this software for any purpose is hereby granted 
 * without fee, provided the above notices are retained on all copies.
 * Permission to modify the code and to distribute modified code is granted,
 * provided the above notices are retained, and a notice that the code was
 * modified is included with the above copyright notice.
 *
 */

#ifndef _STLP_CWCHAR_H
# define _STLP_CWCHAR_H

# ifdef __GNUC__
#  include <cstddef>
# endif

# if ! defined (_STLP_WINCE)

# if defined (__BORLANDC__) &&  (__BORLANDC__ >= 0x530 ) && ! defined (_STLP_OWN_IOSTREAMS)
/*  Borland defines this stuff here */
#   include <iosfwd>
# endif

# if !  defined (_STLP_NO_CWCHAR) && defined  (_STLP_USE_NEW_C_HEADERS)
#  include _STLP_NATIVE_CPP_C_HEADER(cwchar)

# elif defined (__MRC__) || defined (__SC__) || defined (__BORLANDC__) || defined(__FreeBSD__) || (defined (__GNUC__) && defined (__APPLE__\
)) || defined (_STLP_NO_WCHAR_T)

#  include _STLP_NATIVE_C_HEADER(stddef.h)
#  if defined (__FreeBSD__)
#   ifndef _WINT_T
typedef long int wint_t;
#    define _WINT_T
#   endif /* _WINT_T */
#  endif

# else 
#  include _STLP_NATIVE_C_HEADER(wchar.h)

#  if defined(__sun) && (defined(_XOPEN_SOURCE) || (_XOPEN_VERSION - 0 == 4))
extern wint_t   btowc();
extern int      fwprintf();
extern int      fwscanf();
extern int      fwide();
extern int      mbsinit();
extern size_t   mbrlen();
extern size_t   mbrtowc();
extern size_t   mbsrtowcs();
extern int      swprintf();
extern int      swscanf();
extern int      vfwprintf();
extern int      vwprintf();
extern int      vswprintf();
extern size_t   wcrtomb();
extern size_t   wcsrtombs();
extern wchar_t  *wcsstr();
extern int      wctob();
extern wchar_t  *wmemchr();
extern int      wmemcmp();
extern wchar_t  *wmemcpy();
extern wchar_t  *wmemmove();
extern wchar_t  *wmemset();
extern int      wprintf();
extern int      wscanf();
#  endif
# endif

#if defined(__MSL__) && __MSL__ <= 0x51FF	/* dwa 2/28/99 - not yet implemented by MSL  */
#   define _STLP_WCHAR_MSL_EXCLUDE 1
namespace std
{ 
  extern "C" size_t wcsftime(wchar_t * str, size_t max_size, const wchar_t * format_str, const struct tm * timeptr);
}
#  define _STLP_NO_MBSTATE_T 1
#elif defined (__BORLANDC__)
#  ifdef _STLP_OWN_IOSTREAMS
#   define _STLP_NO_NATIVE_MBSTATE_T
#  endif
#  define _STLP_WCHAR_BORLAND_EXCLUDE 1
#  if (__BORLANDC__ < 0x540 )
#   define _STLP_NO_MBSTATE_T 1
#   define _STLP_WCHAR_SUNPRO_EXCLUDE
#  endif
#endif

#include <stl/_mbstate_t>

# ifdef _STLP_IMPORT_VENDOR_CSTD

#if defined (__SUNPRO_CC) && defined (_STLP_NO_OWN_IOSTREAMS) && !defined (_STLP_HAS_NO_NEW_C_HEADERS)
using _STLP_VENDOR_CSTD::wint_t; 
#endif

_STLP_BEGIN_NAMESPACE
# ifdef _STLP_NO_WCHAR_T
typedef int wint_t;
# else
// gcc 3.0 has a glitch : wint_t only sucked into the global namespace if _GLIBCPP_USE_WCHAR_T is defined
#  if defined (__GNUC__) && ! defined (_GLIBCPP_USE_WCHAR_T)
using ::wint_t;
#  else
using _STLP_VENDOR_CSTD::wint_t;
#  endif
# endif


using _STLP_VENDOR_CSTD::size_t;

#  if !defined (_STLP_NO_NATIVE_MBSTATE_T)
using _STLP_VENDOR_MB_NAMESPACE::mbstate_t;

# if !defined (_STLP_NO_CSTD_FUNCTION_IMPORTS) && !defined(_STLP_WCHAR_BORLAND_EXCLUDE) \
  && (!defined(__MSL__) || __MSL__ > 0x6001)
#  if ! (defined (__KCC) || defined (__GNUC__) && defined (sun))
using _STLP_VENDOR_MB_NAMESPACE::btowc;
#   if (!defined(__MSL__) || __MSL__ > 0x7001)
using _STLP_VENDOR_MB_NAMESPACE::mbsinit;
#   endif
#  endif
using _STLP_VENDOR_MB_NAMESPACE::mbrlen;
using _STLP_VENDOR_MB_NAMESPACE::mbrtowc;
using _STLP_VENDOR_MB_NAMESPACE::mbsrtowcs;
using _STLP_VENDOR_MB_NAMESPACE::wcrtomb;
using _STLP_VENDOR_MB_NAMESPACE::wcsrtombs;
#    endif /* BORLAND && !__MSL__ || __MSL__ > 0x6001 */

#  endif /* _STLP_NO_NATIVE_MBSTATE_T */

# if !defined (_STLP_NO_NATIVE_WIDE_FUNCTIONS) && ! defined (_STLP_NO_CSTD_FUNCTION_IMPORTS)

# if !defined (_STLP_WCHAR_BORLAND_EXCLUDE) && ! defined (_STLP_NO_CSTD_FUNCTION_IMPORTS)
using _STLP_VENDOR_CSTD::fgetwc;
using _STLP_VENDOR_CSTD::fgetws;
using _STLP_VENDOR_CSTD::fputwc;
using _STLP_VENDOR_CSTD::fputws;
# endif

#  if !( defined (_STLP_WCHAR_SUNPRO_EXCLUDE) || defined (_STLP_WCHAR_BORLAND_EXCLUDE) \
      || defined(_STLP_WCHAR_HPACC_EXCLUDE) ) 
# ifndef __DECCXX
using _STLP_VENDOR_CSTD::fwide;
# endif
using _STLP_VENDOR_CSTD::fwprintf;
using _STLP_VENDOR_CSTD::fwscanf;
using _STLP_VENDOR_CSTD::getwchar;
#  endif

# ifndef _STLP_WCHAR_BORLAND_EXCLUDE
using _STLP_VENDOR_CSTD::getwc;
using _STLP_VENDOR_CSTD::ungetwc;

using _STLP_VENDOR_CSTD::putwc;
using _STLP_VENDOR_CSTD::putwchar;
# endif

#  if !( defined (_STLP_WCHAR_SUNPRO_EXCLUDE) || defined (_STLP_WCHAR_BORLAND_EXCLUDE)\
      || defined(_STLP_WCHAR_HPACC_EXCLUDE) ) 
using _STLP_VENDOR_CSTD::swprintf;
using _STLP_VENDOR_CSTD::swscanf;
using _STLP_VENDOR_CSTD::vfwprintf;
using _STLP_VENDOR_CSTD::vwprintf;
using _STLP_VENDOR_CSTD::vswprintf;

#   if !defined(__MSL__) || __MSL__ > 0x7001
using _STLP_VENDOR_CSTD::wcsftime;
#   endif
using _STLP_VENDOR_CSTD::wcstok;

#  endif

# if !(defined (__BORLANDC__) && (__BORLANDC__ < 0x540))
using _STLP_VENDOR_CSTD::wcscat;
using _STLP_VENDOR_CSTD::wcsrchr;
using _STLP_VENDOR_CSTD::wcscmp;
using _STLP_VENDOR_CSTD::wcscoll;

using _STLP_VENDOR_CSTD::wcscpy;
using _STLP_VENDOR_CSTD::wcscspn;

using _STLP_VENDOR_CSTD::wcslen;
using _STLP_VENDOR_CSTD::wcsncat;
using _STLP_VENDOR_CSTD::wcsncmp;
using _STLP_VENDOR_CSTD::wcsncpy;
using _STLP_VENDOR_CSTD::wcspbrk;
using _STLP_VENDOR_CSTD::wcschr;

using _STLP_VENDOR_CSTD::wcsspn;
using _STLP_VENDOR_CSTD::wcsxfrm;

# endif

#  if !defined (_STLP_WCHAR_BORLAND_EXCLUDE)

using _STLP_VENDOR_CSTD::wcstod;
using _STLP_VENDOR_CSTD::wcstol;

# endif

#  if !( defined (_STLP_WCHAR_SUNPRO_EXCLUDE) || defined(_STLP_WCHAR_HPACC_EXCLUDE) )

using _STLP_VENDOR_CSTD::wcsstr;
using _STLP_VENDOR_CSTD::wmemchr;

#  if !defined (_STLP_WCHAR_BORLAND_EXCLUDE)

using _STLP_VENDOR_CSTD::wctob;
using _STLP_VENDOR_CSTD::wmemcmp;
using _STLP_VENDOR_CSTD::wmemmove;
using _STLP_VENDOR_CSTD::wprintf;
using _STLP_VENDOR_CSTD::wscanf;

#  endif

using _STLP_VENDOR_CSTD::wmemcpy;
using _STLP_VENDOR_CSTD::wmemset;
#  endif

# endif /* _STLP_NO_NATIVE_WIDE_FUNCTIONS */
_STLP_END_NAMESPACE
# endif /* _STLP_IMPORT_VENDOR_CSTD */

# undef _STLP_WCHAR_SUNPRO_EXCLUDE
# undef _STLP_WCHAR_MSL_EXCLUDE

# endif /* WINCE */




#if !defined (_STLP_NO_WCHAR_T)
# ifndef WCHAR_MIN
#  define WCHAR_MIN 0
// SUNpro has some bugs with casts. wchar_t is size of int there anyway.
#  if defined (__SUNPRO_CC) || defined (__DJGPP)
#   define WCHAR_MAX (~0)
#  else
#   define WCHAR_MAX ((wchar_t)~0)
#  endif
# endif
#endif

#endif /* _STLP_CWCHAR_H */

