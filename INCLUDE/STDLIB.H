/*  stdlib.h

    Definitions for common types, variables, and functions.

*/

/*
 *      C/C++ Run Time Library - Version 8.0
 *
 *      Copyright (c) 1987, 1997 by Borland International
 *      All Rights Reserved.
 *
 */
/* $Revision:   8.16  $ */

#ifndef __STDLIB_H
#define __STDLIB_H

#if !defined(___DEFS_H)
#include <_defs.h>
#endif

#ifndef NULL
#include <_null.h>
#endif


#if !defined(RC_INVOKED)

#if defined(__STDC__)
#pragma warn -nak
#endif

#pragma pack(push, 1)

#endif  /* !RC_INVOKED */


#ifndef _SIZE_T
#define _SIZE_T
typedef unsigned size_t;
#endif

#ifndef _DIV_T
#define _DIV_T
typedef struct {
        int     quot;
        int     rem;
} div_t;
#endif

#ifndef _LDIV_T
#define _LDIV_T
typedef struct {
        long    quot;
        long    rem;
} ldiv_t;
#endif

#ifndef __cplusplus
#if !defined(_WCHAR_T) && !defined(_WCHAR_T_DEFINED)
#define _WCHAR_T
#define _WCHAR_T_DEFINED  /* For WINDOWS.H */
typedef unsigned short wchar_t;
#endif
#endif

#if !defined(_WINT_T)
typedef wchar_t wint_t;
#define _WINT_T
#endif

#define MB_CUR_MAX 1

/* Maximum value returned by "rand" function
*/
#define RAND_MAX 0x7FFFU

#define EXIT_SUCCESS 0
#define EXIT_FAILURE 1

typedef void (_USERENTRY * atexit_t)(void);

/*
  These 2 constants are defined in MS's stdlib.h.
*/

#define DOS_MODE    0  /* DOS 16-bit */
#define OS2_MODE    1  /* OS/2 16-bit */

#if !defined(__FLAT__)


#ifdef __cplusplus
extern "C" {
#endif

void        _RTLENTRY abort(void);

#if !defined(__ABS_DEFINED)
#define __ABS_DEFINED

int         _RTLENTRY __abs__(int);
#ifdef __cplusplus
inline int _RTLENTRY  abs(int __x) { return __abs__(__x); }
#else
int         _RTLENTRYF abs(int __x);
#  define abs(x)   __abs__(x)
#endif

#endif /* __ABS_DEFINED */

int         _RTLENTRY  atexit(void (_USERENTRY *__func)(void));
double      _RTLENTRY  atof(const char _FAR *__s);
int         _RTLENTRYF atoi(const char _FAR *__s);
long        _RTLENTRYF atol(const char _FAR *__s);
void _FAR * _RTLENTRYF bsearch(const void _FAR *__key, const void _FAR *__base,
                           size_t __nelem, size_t __width,
                           int (_USERENTRYF *fcmp)(const void _FAR *,
                           const void _FAR *));
void _FAR * _RTLENTRY  calloc(size_t __nitems, size_t __size);
div_t       _RTLENTRY  div(int __numer, int __denom);
void        _RTLENTRY  exit(int __status);
void        _RTLENTRY  free(void _FAR *__block);
char _FAR * _RTLENTRYF getenv(const char _FAR *__name);
long        _RTLENTRY  labs(long __x);
ldiv_t      _RTLENTRY  ldiv(long __numer, long __denom);
void _FAR * _RTLENTRY  malloc(size_t __size);
int         _RTLENTRYF _EXPFUNC mblen(const char _FAR *__s, size_t __n);
size_t      _RTLENTRYF _EXPFUNC mbstowcs(wchar_t _FAR *__pwcs, const char _FAR *__s,
                                    size_t __n);
int         _RTLENTRYF _EXPFUNC mbtowc(wchar_t _FAR *__pwc, const char _FAR *__s, size_t __n);
void        _RTLENTRYF _EXPFUNC qsort(void _FAR *__base, size_t __nelem, size_t __width,
                       int _USERENTRYF (*_EXPFUNC __fcmp)(const void _FAR *, const void _FAR *));
int         _RTLENTRY  rand(void);
void  _FAR *_RTLENTRY  realloc(void _FAR *__block, size_t __size);
void        _RTLENTRY  srand(unsigned __seed);
double      _RTLENTRY  strtod(const char _FAR *__s, char _FAR *_FAR *__endptr);
long        _RTLENTRY _EXPFUNC strtol(const char _FAR *__s, char _FAR *_FAR *__endptr,
                                    int __radix);
long double _RTLENTRY  _strtold(const char _FAR *__s, char _FAR *_FAR *__endptr);
unsigned long _RTLENTRY _EXPFUNC strtoul(const char _FAR *__s, char _FAR *_FAR *__endptr,
                                       int __radix);
int         _RTLENTRY _EXPFUNC system(const char _FAR *__command);
size_t      _RTLENTRYF _EXPFUNC wcstombs(char _FAR *__s, const wchar_t _FAR *__pwcs,
                                    size_t __n);
int         _RTLENTRYF _EXPFUNC wctomb(char _FAR *__s, wchar_t __wc);

#ifdef __cplusplus
}
#endif

extern  unsigned        _RTLENTRY _psp;

#if !defined(__STDC__) /* obsolete */
#define environ  _environ
#endif

extern  char          **_RTLENTRY _environ;
extern  int             _RTLENTRY _fmode;
extern  unsigned char   _RTLENTRY _osmajor;
extern  unsigned char   _RTLENTRY _osminor;
extern  unsigned int    _RTLENTRY _version;

#if !defined(__STDC__)
#define sys_nerr     _sys_nerr
#define sys_errlist  _sys_errlist
#endif

#if defined( _RTLDLL )

#ifdef __cplusplus
extern "C" {
#endif
extern  char far * far * far  _RTLENTRY __get_sys_errlist(void);
extern  int  far              _RTLENTRY __get_sys_nerr(void);
#ifdef __cplusplus
}
#endif

#define _sys_errlist  __get_sys_errlist()
#define _sys_nerr     __get_sys_nerr()

#else
extern  char      _FAR *_RTLENTRY _sys_errlist[];
extern  int             _RTLENTRY _sys_nerr;
#endif


#if !defined(__STDC__) && !defined(__CODEGUARD__)
#if defined(__cplusplus)
inline int  _RTLENTRY atoi(const char _FAR *__s) { return (int) atol(__s); }
#else
#define atoi(s)     ((int) atol(s))
#endif
#endif

/* Constants for MSC pathname functions */

#define _MAX_PATH       80
#define _MAX_DRIVE      3
#define _MAX_DIR        66
#define _MAX_FNAME      9
#define _MAX_EXT        5

#ifdef __cplusplus
extern "C" {
#endif

long double    _RTLENTRY   _atold(const char _FAR *__s);
unsigned char  _RTLENTRY   _crotl(unsigned char __value, int __count);
unsigned char  _RTLENTRY   _crotr(unsigned char __value, int __count);
char   _FAR   *_RTLENTRY   ecvt(double __value, int __ndig, int _FAR *__dec,
                           int _FAR *__sign);
void           _RTLENTRY   _exit(int __status);
char   _FAR   *_RTLENTRY   fcvt(double __value, int __ndig, int _FAR *__dec,
                           int _FAR *__sign);
char _FAR     *_RTLENTRYF  _EXPFUNC _fullpath( char _FAR *__buf,
                                 const char _FAR *__path,
                                 size_t __maxlen );
char   _FAR   *_RTLENTRY   gcvt(double __value, int __ndec, char _FAR *__buf);
char   _FAR   *_RTLENTRYF  _EXPFUNC itoa(int __value, char _FAR *__string, int __radix);
void   _FAR   *_RTLENTRY   _EXPFUNC lfind(const void _FAR *__key, const void _FAR *__base,
                                 size_t _FAR *__num, size_t __width,
                                 int _USERENTRY (*_EXPFUNC __fcmp)(const void _FAR *,
                                 const void _FAR *));
unsigned long  _RTLENTRY   _lrotl(unsigned long __val, int __count);
unsigned long  _RTLENTRY   _lrotr(unsigned long __val, int __count);

void   _FAR   *_RTLENTRY   _EXPFUNC lsearch(const void _FAR *__key, void _FAR *__base,
                                 size_t _FAR *__num, size_t __width,
                           int _RTLENTRY(*_EXPFUNC __fcmp)(const void _FAR *, const void _FAR *));
char _FAR     *_RTLENTRYF  _EXPFUNC ltoa(long __value, char _FAR *__string, int __radix);
void           _RTLENTRY   _EXPFUNC _makepath( char _FAR *__path,
                                 const char _FAR *__drive,
                                 const char _FAR *__dir,
                                 const char _FAR *__name,
                                 const char _FAR *__ext );
int            _RTLENTRY   _EXPFUNC putenv(const char _FAR *__name);

unsigned       _RTLENTRY   _rotl(unsigned __value, int __count);
unsigned       _RTLENTRY   _rotr(unsigned __value, int __count);

unsigned       _RTLENTRY   __rotl__(unsigned __value, int __count);     /* intrinsic */
unsigned       _RTLENTRY   __rotr__(unsigned __value, int __count);     /* intrinsic */

void           _RTLENTRY   _searchenv(const char _FAR *__file,
                                 const char _FAR *__varname,
                                 char _FAR *__pathname);
void           _RTLENTRY   _searchstr(const char _FAR *__file,
                                 const char _FAR *__ipath,
                                 char _FAR *__pathname);
void           _RTLENTRY   _EXPFUNC _splitpath( const char _FAR *__path,
                                 char _FAR *__drive,
                                 char _FAR *__dir,
                                 char _FAR *__name,
                                 char _FAR *__ext );
void           _RTLENTRY   _EXPFUNC swab(char _FAR *__from, char _FAR *__to, int __nbytes);
char _FAR     *_RTLENTRYF  _EXPFUNC ultoa(unsigned long __value, char _FAR *__string,
                                 int __radix);

#ifdef __cplusplus
}
#endif

#ifdef __BCOPT__
#define  _rotl(__value, __count)  __rotl__(__value, __count)
#define  _rotr(__value, __count)  __rotr__(__value, __count)
#endif


#if !defined(__STDC__)  /* NON-ANSI */

#if defined( _RTLDLL )

#ifdef __cplusplus
extern "C" {
#endif
int far * far _RTLENTRY __getErrno(void);
int far * far _RTLENTRY __getDOSErrno(void);
#ifdef __cplusplus
}
#endif


#define errno (*__getErrno())
#define _doserrno (*__getDOSErrno())

#else

extern  int   _RTLENTRY _doserrno;
extern  int   _RTLENTRY errno;

#endif

#endif  /* !__STDC__ */

#ifdef __cplusplus
inline int _RTLENTRY     random(int __num)
                        { return(int)(((long)rand()*__num)/(RAND_MAX+1)); }
#else /* __cplusplus */
#define random(num)(int)(((long)rand()*(num))/(RAND_MAX+1))
#endif


#else  /* defined __FLAT__ */


#ifdef __cplusplus
extern "C" {
#endif

void        _RTLENTRY _EXPFUNC abort(void);

#if !defined(__ABS_DEFINED)
#define __ABS_DEFINED

int         _RTLENTRY __abs__(int);
#ifdef __cplusplus
inline int _RTLENTRY  abs(int __x) { return __abs__(__x); }
#else
int         _RTLENTRYF _EXPFUNC abs(int __x);
#  define abs(x)   __abs__(x)
#endif

#endif /* __ABS_DEFINED */

int         _RTLENTRY   _EXPFUNC atexit(void (_USERENTRY * __func)(void));
double      _RTLENTRY   _EXPFUNC atof(const char * __s);
int         _RTLENTRYF  _EXPFUNC atoi(const char * __s);
long        _RTLENTRYF  _EXPFUNC atol(const char * __s);
void *      _RTLENTRYF  _EXPFUNC bsearch(const void * __key, const void * __base,
                           size_t __nelem, size_t __width,
                           int (_USERENTRY *fcmp)(const void *,
                           const void *));
void *      _RTLENTRY _EXPFUNC   calloc(size_t __nitems, size_t __size);
div_t       _RTLENTRY _EXPFUNC   div(int __numer, int __denom);
void        _RTLENTRY _EXPFUNC   exit(int __status);
void        _RTLENTRY _EXPFUNC   free(void * __block);
char *      _RTLENTRYF _EXPFUNC  getenv(const char * __name);
long        _RTLENTRY _EXPFUNC   labs(long __x);
ldiv_t      _RTLENTRY _EXPFUNC   ldiv(long __numer, long __denom);
void *      _RTLENTRY _EXPFUNC   malloc(size_t __size);
int         _RTLENTRY _EXPFUNC   mblen(const char * __s, size_t __n);
size_t      _RTLENTRY _EXPFUNC   mbstowcs(wchar_t *__pwcs, const char * __s,
                           size_t __n);
int         _RTLENTRY _EXPFUNC   mbtowc(wchar_t *__pwc, const char * __s, size_t __n);
void        _RTLENTRYF _EXPFUNC  qsort(void * __base, size_t __nelem, size_t __width,
                           int (_USERENTRY *__fcmp)(const void *, const void *));
int         _RTLENTRY _EXPFUNC   rand(void);
void *      _RTLENTRY _EXPFUNC   realloc(void * __block, size_t __size);
void        _RTLENTRY _EXPFUNC   srand(unsigned __seed);
double      _RTLENTRY _EXPFUNC   strtod(const char * __s, char * *__endptr);
long        _RTLENTRY _EXPFUNC   strtol(const char * __s, char * *__endptr,
                           int __radix);
long double _RTLENTRY _EXPFUNC   _strtold(const char * __s, char * *__endptr);
unsigned long _RTLENTRY _EXPFUNC strtoul(const char * __s, char * *__endptr,
                           int __radix);
int         _RTLENTRY _EXPFUNC   system(const char * __command);

size_t      _RTLENTRY _EXPFUNC   wcstombs(char * __s, const wchar_t *__pwcs,size_t __n);
int         _RTLENTRY _EXPFUNC   wctomb(char * __s, wchar_t __wc);
double      _RTLENTRY _EXPFUNC   _wtof(const wchar_t * __s);
int         _RTLENTRY _EXPFUNC   _wtoi(const wchar_t * __s);
long        _RTLENTRY _EXPFUNC   _wtol(const wchar_t * __s);
long double _RTLENTRY _EXPFUNC   _wtold(const wchar_t * __s);
double      _RTLENTRY _EXPFUNC   wcstod(const wchar_t * __s, wchar_t * *__endptr);
long        _RTLENTRY _EXPFUNC   wcstol(const wchar_t * __s, wchar_t * *__endptr, int __radix);
long double _RTLENTRY _EXPFUNC   _wcstold(const wchar_t * __s, wchar_t * *__endptr);
unsigned long _RTLENTRY _EXPFUNC wcstoul(const wchar_t * __s, wchar_t * *__endptr, int __radix);
int         _RTLENTRY  _EXPFUNC  _wsystem(const wchar_t * __command);
wchar_t *   _RTLENTRY  _EXPFUNC  _itow(int __value, wchar_t *__string, int __radix);
wchar_t *   _RTLENTRY  _EXPFUNC  _ltow(long __value, wchar_t *__string, int __radix);
wchar_t *   _RTLENTRY  _EXPFUNC  _ultow(unsigned long __value, wchar_t *__string, int __radix);

#if !defined(__STDC__)
#if (__BORLANDC__ >= 0x0520) && defined (_INTEGRAL_MAX_BITS) && (_INTEGRAL_MAX_BITS >= 64)
__int64     _RTLENTRY   _EXPFUNC _atoi64(const char * __s);
char *      _RTLENTRY   _EXPFUNC _i64toa(__int64 value, char *strP, int radix);
char *      _RTLENTRY   _EXPFUNC _ui64toa(unsigned __int64 value, char *strP, int radix);
__int64     _RTLENTRY   _EXPFUNC _wtoi64(const wchar_t * __s);
wchar_t *   _RTLENTRY   _EXPFUNC _i64tow(__int64 value, wchar_t *strP, int radix);
wchar_t *   _RTLENTRY   _EXPFUNC _ui64tow(unsigned __int64 value, wchar_t *strP, int radix);
#endif
char *      _RTLENTRY   _EXPFUNC ltoa(long __value, char * __string, int __radix);
char *      _RTLENTRY   _EXPFUNC ltoa(long __value, char * __string, int __radix);
char *      _RTLENTRY   _EXPFUNC ecvt(double __value, int __ndig, int * __dec, int * __sign);
char *      _RTLENTRY   _EXPFUNC fcvt(double __value, int __ndig, int * __dec, int * __sign);
char *      _RTLENTRY   _EXPFUNC gcvt(double __value, int __ndec, char * __buf);

#endif /* __STDC__ */

#ifdef __cplusplus
}
#endif

/* Variables */

#ifdef _MT

#ifdef __cplusplus
extern "C" {
#endif
extern  int * _RTLENTRY _EXPFUNC __errno(void);
extern  int * _RTLENTRY _EXPFUNC __doserrno(void);
#ifdef  __cplusplus
}
#endif
#define errno (*__errno())
#define _doserrno (*__doserrno())

#else   /* MT */

extern  int   _RTLENTRY _EXPDATA errno;
extern  int   _RTLENTRY _EXPDATA _doserrno;

#endif  /* MT */

#if !defined(__STDC__)

/* Values for _osmode */

#define _WIN_MODE    2  /* Windows 16- or 32-bit */
#define _OS2_20_MODE 3  /* OS/2 32-bit */
#define _DOSX32_MODE 4  /* DOS 32-bit */

#define environ  _environ

#endif /* __STDC__ */

extern  char          **_RTLENTRY _EXPDATA _environ;
extern  wchar_t       **_RTLENTRY _EXPDATA _wenviron;
extern  int             _RTLENTRY _EXPDATA _fileinfo;
extern  int             _RTLENTRY          _fmode;
extern  unsigned char   _RTLENTRY _EXPDATA _osmajor;
extern  unsigned char   _RTLENTRY _EXPDATA _osminor;
extern  unsigned char   _RTLENTRY _EXPDATA _osmode;
extern  unsigned int    _RTLENTRY _EXPDATA _osversion;

#if !defined(__STDC__) && !defined(__CODEGUARD__)
#ifdef __cplusplus
   inline int _RTLENTRY atoi(const char *__s) { return (int)atol(__s); }
#else
#  define atoi(s)((int) atol(s))
#endif
#endif

#if !defined(__STDC__)
#define sys_nerr     _sys_nerr
#define sys_errlist  _sys_errlist
#endif

extern  char          * _RTLENTRY _EXPDATA _sys_errlist[];
extern  int             _RTLENTRY _EXPDATA _sys_nerr;


/* Constants for MSC pathname functions */

#if defined(__OS2__) || defined(__WIN32__)
#define _MAX_PATH       260
#define _MAX_DRIVE      3
#define _MAX_DIR        256
#define _MAX_FNAME      256
#define _MAX_EXT        256
#else
#define _MAX_PATH       80
#define _MAX_DRIVE      3
#define _MAX_DIR        66
#define _MAX_FNAME      9
#define _MAX_EXT        5
#endif

#ifdef __cplusplus
extern "C" {
#endif

long double   _RTLENTRY  _EXPFUNC _atold(const char * __s);

unsigned char _RTLENTRY  _EXPFUNC _crotl(unsigned char __value, int __count);
unsigned char _RTLENTRY  _EXPFUNC _crotr(unsigned char __value, int __count);

char *        _RTLENTRY  _EXPFUNC _ecvt(double __value, int __ndig, int * __dec,
                                       int * __sign);
void          _RTLENTRY  _EXPFUNC _exit(int __status);
char *        _RTLENTRY  _EXPFUNC _fcvt(double __value, int __ndig, int * __dec,
                                       int * __sign);
char *        _RTLENTRYF _EXPFUNC _fullpath(char * __buf, const char * __path,
                                            size_t __maxlen);
char *        _RTLENTRY  _EXPFUNC _gcvt(double __value, int __ndec,
                                       char * __buf);
char *        _RTLENTRYF _EXPFUNC itoa(int __value, char * __string,
                                       int __radix);
void *        _RTLENTRY  _EXPFUNC lfind(const void * __key,
                                        const void * __base,
                                        size_t *__num, size_t __width,
                                        int (_USERENTRY *fcmp)(const void *, const void *));

long          _RTLENTRY  _EXPFUNC _lrand(void);
unsigned long _RTLENTRY  _EXPFUNC _lrotl(unsigned long __val, int __count);
unsigned long _RTLENTRY  _EXPFUNC _lrotr(unsigned long __val, int __count);

void *        _RTLENTRY  _EXPFUNC lsearch(const void * __key, void * __base,
                                          size_t *__num, size_t __width,
                                          int (_USERENTRY *fcmp)(const void *, const void *));

char *        _RTLENTRYF _EXPFUNC _ltoa(long __value, char * __string,
                                       int __radix);
void          _RTLENTRY  _EXPFUNC _makepath(char * __path,
                                            const char * __drive,
                                            const char * __dir,
                                            const char * __name,
                                            const char * __ext );
int           _RTLENTRY  _EXPFUNC putenv(const char * __name);

unsigned short  _RTLENTRY _EXPFUNC _rotl(unsigned short __value, int __count);
unsigned short  _RTLENTRY _EXPFUNC _rotr(unsigned short __value, int __count);

void            _RTLENTRY _EXPFUNC _searchenv(const char * __file,
                                             const char * __varname,
                                             char *__pathname);
void            _RTLENTRY _EXPFUNC _searchstr(const char * __file,
                                             const char * __ipath,
                                             char *__pathname);
void            _RTLENTRY _EXPFUNC _splitpath(const char * __path,
                                             char * __drive,
                                             char * __dir,
                                             char * __name,
                                             char * __ext );
void            _RTLENTRY _EXPFUNC swab(char * __from, char * __to, int __nbytes);
char *          _RTLENTRY _EXPFUNC ultoa(unsigned long __value, char * __string,
                                        int __radix);
void            _RTLENTRY _EXPFUNC perror(const char * __s);

void            _RTLENTRY _EXPFUNC _wperror(const wchar_t * __s);
wchar_t *       _RTLENTRY _EXPFUNC _wfullpath(wchar_t * __buf,const wchar_t * __path,
                                             size_t __maxlen);
void            _RTLENTRY _EXPFUNC _wmakepath(wchar_t * __path,
                                             const wchar_t * __drive,
                                             const wchar_t * __dir,
                                             const wchar_t * __name,
                                             const wchar_t * __ext );
void          _RTLENTRY  _EXPFUNC _wsplitpath(const wchar_t * __path,
                                              wchar_t * __drive,
                                              wchar_t * __dir,
                                              wchar_t * __name,
                                              wchar_t * __ext );

void          _RTLENTRY  _EXPFUNC _wsearchenv(const wchar_t * __file,
                                             const wchar_t * __varname,
                                             wchar_t *__pathname);
void          _RTLENTRY  _EXPFUNC _wsearchstr(const wchar_t * __file,
                                             const wchar_t * __ipath,
                                             wchar_t *__pathname);
wchar_t *     _RTLENTRY _EXPFUNC  _wgetenv(const wchar_t * __name);
int           _RTLENTRY _EXPFUNC  _wputenv(const wchar_t * __name);
/* Intrinsic functions */

unsigned char _RTLENTRY  ___crotl__(unsigned char __value, int __count);
unsigned char _RTLENTRY  ___crotr__(unsigned char __value, int __count);
unsigned long _RTLENTRY  ___lrotl__(unsigned long __val, int __count);
unsigned long _RTLENTRY  ___lrotr__(unsigned long __val, int __count);
unsigned short _RTLENTRY ___rotl__ (unsigned short __value, int __count);
unsigned short _RTLENTRY ___rotr__ (unsigned short __value, int __count);

#ifdef __cplusplus
}
#endif

#if !defined(__STDC__)

#if defined(__cplusplus)
inline int  _RTLENTRY random(int __num)
                       { return __num ? (int)(_lrand()%(__num)) : 0; }
#else /* __cplusplus */
#define random(num) (num ? (int)(_lrand()%(num)) : 0)
#endif  /* __cplusplus  */

#endif /* __STDC__ */

#endif  /* __FLAT__ */

#if defined(__cplusplus)
extern "C" long _RTLENTRY _EXPFUNC time(long _FAR *);
#endif

#if !defined(__STDC__)

#if defined(__cplusplus)

/* Need prototype of time() for C++ randomize() */
inline void _RTLENTRY randomize(void) { srand((unsigned) time(NULL)); }

#if defined(__MFC_COMPAT__)
#if !defined( __MINMAX_DEFINED)
#define __MINMAX_DEFINED
#define max(a,b)    (((a) > (b)) ? (a) : (b))
#define min(a,b)    (((a) < (b)) ? (a) : (b))
#define __max       max
#define __min       min
#endif /*__MINMAX_DEFINED */

inline char * _RTLENTRY  _ecvt(double __value, int __ndig, int * __dec,
                         int * __sign)
                         { return ecvt (__value, __ndig, __dec, __sign); }
inline char * _RTLENTRY  _fcvt(double __value, int __ndig, int * __dec,
                         int * __sign)
                         { return fcvt (__value, __ndig, __dec, __sign); }
inline char * _RTLENTRY  _gcvt(double __value, int __ndec,
                         char * __buf)
                         { return gcvt(__value, __ndec, __buf); }
inline char * _RTLENTRYF _itoa(int __value, char * __string,
                         int __radix)
                         { return itoa(__value, __string, __radix); }
inline char * _RTLENTRYF _ltoa(long __value, char * __string,
                         int __radix)
                         { return ltoa(__value, __string, __radix); }
inline char * _RTLENTRYF _ultoa(unsigned long __value, char * __string,
                         int __radix)
                         { return ultoa(__value, __string, __radix); }
inline int    _RTLENTRY  _putenv(const char * __name) {return putenv(__name);}
inline void   _RTLENTRY  _swab(char * __from, char * __to, int __nbytes)
                         { swab (__from, __to, __nbytes); }
#if !defined(__DLL__)
extern  int           _RTLENTRY __argc;
extern  char        **_RTLENTRY __argv;
#endif  /* __DLL__ */
#else   /* __MFC_COMPAT__ */
#if !defined( __MINMAX_DEFINED) && defined(__cplusplus)
#define __MINMAX_DEFINED
template <class T> inline const T _FAR &min( const T _FAR &t1, const T _FAR &t2 )
{
    if  (t1 < t2)
        return t1;
    else
        return t2;
}

template <class T> inline const T _FAR &max( const T _FAR &t1, const T _FAR &t2 )
{
    if  (t1 > t2)
        return t1;
    else
        return t2;
}
#endif
#endif /* __MFC_COMPAT__ */

#else /* __cplusplus */

#define randomize() srand((unsigned)time(NULL))
#define max(a,b)    (((a) > (b)) ? (a) : (b))
#define min(a,b)    (((a) < (b)) ? (a) : (b))
#endif /* __cplusplus */


#define  MB_CUR_MAX              1

#endif /* __STDC__ */

#if defined(__MSC) && !defined(__MFC_COMPAT__)
#define _itoa(__value, __string, __radix) itoa(__value, __string, __radix)
#endif


#if !defined(RC_INVOKED)

/* restore default packing */
#pragma pack(pop)

#if defined(__STDC__)
#pragma warn .nak
#endif

#endif  /* !RC_INVOKED */


#endif  /* __STDLIB_H */

