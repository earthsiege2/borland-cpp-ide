/* $Copyright: 1995$ */

#if !defined(__TCHAR_H)
#define __TCHAR_H

#ifdef  __cplusplus
extern "C" {
#endif

#if defined(_UNICODE)

#ifndef __TCHAR_DEFINED
typedef wchar_t     _TCHAR;
typedef wchar_t     _TSCHAR;
typedef wchar_t     _TUCHAR;
typedef wchar_t     _TXCHAR;
#if !defined (__BORLANDC__)  /* Borland C++ does not support 64-bit chars */
  typedef wint_t      _TINT;
#endif /* __BORLANDC__ */
#define __TCHAR_DEFINED
#endif

#define _TEOF		WEOF
#define __T(x)		L ## x

#else

#ifndef __TCHAR_DEFINED
typedef char            _TCHAR;
typedef signed char     _TSCHAR;
typedef unsigned char   _TUCHAR;
typedef char            _TXCHAR;
typedef int             _TINT;
#define __TCHAR_DEFINED
#endif

#define _TEOF       EOF
#define __T(x)      x

#endif 	/* _UNICODE */

#define _TEXT(x)    __T(x)
#define _T(x)       __T(x)

#ifdef __cplusplus
}
#endif

#endif	/* __TCHAR_H */
