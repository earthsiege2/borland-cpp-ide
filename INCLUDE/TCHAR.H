/*
 *      C/C++ Run Time Library - Version 8.0
 *
 *      Copyright (c) 1995, 1997 by Borland International
 *      All Rights Reserved.
 *
 */
/* $Revision:   8.58  $ */

#if !defined(__TCHAR_H)
#define __TCHAR_H

#if !defined(__STDDEF_H)
#include <stddef.h>
#endif

#if !defined(___DEFS_H)
#include <_defs.h>
#endif

#if !defined(__STRING_H)
#include <string.h>
#endif

#ifdef  __cplusplus
extern "C" {
#endif

#if defined(_MBCS)
#include <mbstring.h>
#endif

#if !defined(_UNICODE)

/* Common functions between SBCS & MBCS */

#ifndef __TCHAR_DEFINED
typedef char            _TCHAR;
typedef signed char     _TSCHAR;
typedef unsigned char   _TUCHAR;
typedef char            _TXCHAR;
typedef int             _TINT;
#define __TCHAR_DEFINED
#endif

#if !defined(__FLAT__)
#define _tfdopen        fdopen
#define _fputtchar      fputchar
#define _fgettchar      fgetchar
#define _tmktemp        mktemp
#define _tunlink        unlink
#define _ttempnam       tempnam
#define _trmdir         rmdir
#define _tmkdir         mkdir
#define _tutime         utime
#define _ltot           ltoa
#define _tsopen         sopen
#else
#define _tfdopen        _fdopen
#define _fputtchar      _fputchar
#define _fgettchar      _fgetchar
#define _tmktemp        _mktemp
#define _tunlink        _unlink
#define _ttempnam       _tempnam
#define _trmdir         _rmdir
#define _tmkdir         _mkdir
#define _tutime         _utime
#define _ltot           _ltoa
#define _tsopen         _sopen
#endif

/* program specific mappings*/

#define _tmain          main
#define _tWinMain       WinMain
#define _tenviron       _environ
#define _targv          _argv

/*  Path / Environment  specific mappings  */

#define _tfullpath      _fullpath
#define _tmakepath      _makepath
#define _tsplitpath     _splitpath
#define _tsearchpath    searchpath
#define _tsearchenv     _searchenv
#define _tsearchstr     _searchstr
#define _tgetenv        getenv
#define _tputenv        putenv
#define _tfnsplit       fnsplit
#define _tfnmerge       fnmerge

/* directory functions */

#define _topendir       opendir
#define _treaddir       readdir
#define _trewinddir     rewinddir
#define _tclosedir      closedir
#define _tDIR           DIR
#define _tdirent        dirent

/* stdio functions   */

#define _tpopen         _popen
#define _tfsopen        _fsopen
#define _tfopen         fopen
#define _tfreopen       freopen
#define _tperror        perror
#define _ttmpnam        tmpnam

/* Time functions     */

#define _tstrdate       _strdate
#define _tstrtime       _strtime
#define _tasctime       asctime
#define _tctime         ctime
#define _tcsftime       strftime
#define _ttzset         _tzset
#define _ttzname        _tzname

/*  I/O functions   */

#define _taccess        access
#define _tchmod         chmod
#define _trtl_open      _rtl_open
#define _trtl_creat     _rtl_creat
#define _trtl_chmod     _rtl_chmod
#define _tcreat         creat
#define _tfindfirst     findfirst
#define _tfindnext      findnext
#define _topen          open
#define _tremove        remove
#define _trename        rename

#define _tffblk         ffblk

/* string conversion functions */

#define _ttof           atof
#define _ttoi           atoi
#define _ttol           atol
#define _ttoi64         _atoi64
#define _ttold          _atold
#define _tcstod         strtod
#define _tcstol         strtol
#define _tcstold        _strtold
#define _tcstoul        strtoul
#define _itot           itoa
#define _ultot          ultoa
#define _i64tot         _i64toa
#define _ui64tot        _ui64toa

/* string functions  */

#define _tcscat         strcat
#define _tcscpy         strcpy
#define _tcspcpy        _stpcpy
#define _tcslen         strlen
#define _tcsdup         strdup

/* directory functions */

#define _tchdir         chdir
#define _tgetcurdir     getcurdir
#define _tgetcwd        getcwd
#define _tgetdcwd       _getdcwd

/* Execute functions */

#define _texecl     execl
#define _texecle    execle
#define _texeclp    execlp
#define _texeclpe   execlpe
#define _texecv     execv
#define _texecve    execve
#define _texecvp    execvp
#define _texecvpe   execvpe

#define _tspawnl    spawnl
#define _tspawnle   spawnle
#define _tspawnlp   spawnlp
#define _tspawnlpe  spawnlpe
#define _tspawnv    spawnv
#define _tspawnve   spawnve
#define _tspawnvp   spawnvp
#define _tspawnvpe  spawnvpe

#define _tsystem    system

/* Unformated I/O */

#define _fgettc         fgetc
#define _fgetts         fgets
#define _fputtc         fputc
#define _fputts         fputs
#define _gettc          getc
#define _gettchar       getchar
#define _getts          gets
#define _puttc          putc
#define _puttchar       putchar
#define _putts          puts
#define _ungettc        ungetc

/* Formated I/O */

#define _ftprintf       fprintf
#define _tprintf        printf
#define _stprintf       sprintf
#define _vtprintf       vprintf
#define _vftprintf      vfprintf
#define _vstprintf      vsprintf

#define _tscanf         scanf
#define _stscanf        sscanf
#define _ftscanf        fscanf
#define _stscanf        sscanf
#define _vstscanf       vsscanf
#define _vtscanf        vscanf
#define _vftscanf       vfscanf

/* Stat functions */

#define _tstat          _stat
#define _tstati64       _stati64

/* Setlocale functions */

#define _tsetlocale setlocale

/* memory functions */

#define _tmemcpy        memcpy
#define _tmemchr        memchr
#define _tmemset        memset

/* Generic Text macros */

#define __T(x)          x
#define _TEXT(x)        __T(x)
#define _T(x)           __T(x)
#define _TEOF           EOF

#if defined(_MBCS)

/* ----------------- MBCS functions -------------------------- */

#ifndef __TCHAR_DEFINED
typedef char            _TCHAR;
typedef signed char     _TSCHAR;
typedef unsigned char   _TUCHAR;
typedef unsigned char   _TXCHAR;
typedef unsigned int    _TINT;
#define __TCHAR_DEFINED
#endif

#ifdef _MBC_USE_MACROS
/* string functions */

#define _tcschr         _mbschr
#define _tcscspn        _mbscspn
#define _tcsncat        _mbsnbcat
#define _tcsncpy        _mbsnbcpy
#define _tcspbrk        _mbspbrk
#define _tcsrchr        _mbsrchr
#define _tcsspn         _mbsspn
#define _tcsstr         _mbsstr
#define _tcstok         _mbstok

#define _tcsset         _mbsset
#define _tcsnset        _mbsnbset
#define _tcsrev         _mbsrev
#define _tcscmp         _mbscmp
#define _tcsicmp        _mbsicmp
#define _tcsncmp        _mbsnbcmp
#define _tcsnicmp       _mbsnbicmp
#define _tcsnccmp       _mbsncmp
#define _tcsncicmp      _mbsnicmp

/* todo : correct the mapping of these functions and add the new functions */
#define _tcscoll        _mbscoll
#define _tcsncoll       _mbsnbcoll
#define _tcsnccoll      _mbsncoll
#define _tcsicoll       _mbsicoll
#define _tcsnicoll      _mbsnbicoll
#define _tcsncicoll     _mbsnicoll

/* logical-character mappings */

#define _tcsclen        _mbslen
#define _tcsnccat       _mbsncat
#define _tcsnccpy       _mbsncpy
#define _tcsncset       _mbsnset

/* MBCS specific mappings */

#define _tcsdec         _mbsdec
#define _tcsinc         _mbsinc
#define _tcsnbcnt       _mbsnbcnt
#define _tcsnccnt       _mbsnccnt
#define _tcsnextc       _mbsnextc
#define _tcsninc        _mbsninc
#define _tcsspnp        _mbsspnp

#define _tcslwr         _mbslwr
#define _tcsupr         _mbsupr

#define _tclen          _mbclen
#define _tccpy          _mbccpy
#define _tccmp(a,b)     _mbsncmp(a,b,1)

#else /* _MBC_USE_MACROS */

#if (!defined ( __cplusplus) || defined( _NO_INLINING ))

/* String functions */

char * _RTLENTRY  _EXPFUNC _tcschr(const char *, unsigned int);
size_t _RTLENTRY  _EXPFUNC _tcscspn(const char *, const char *);
char * _RTLENTRY  _EXPFUNC _tcsncat(char *, const char *, size_t);
char * _RTLENTRY  _EXPFUNC _tcsncpy(char *, const char *, size_t);
char * _RTLENTRY  _EXPFUNC _tcspbrk(const char *, const char *);
char * _RTLENTRY  _EXPFUNC _tcsrchr(const char *, int);
size_t _RTLENTRY  _EXPFUNC _tcsspn(const char *, const char *);
char * _RTLENTRY  _EXPFUNC _tcsstr(const char *, const char *);
char * _RTLENTRY  _EXPFUNC _tcstok(char *, const char *);

char * _RTLENTRY  _EXPFUNC _tcsnset(char *, unsigned int, size_t);
char * _RTLENTRY  _EXPFUNC _tcsrev(char *);
char * _RTLENTRY  _EXPFUNC _tcsset(char *, unsigned int);

int _RTLENTRY  _EXPFUNC _tcscmp(const char *, const char *);
int _RTLENTRY  _EXPFUNC _tcsicmp(const char *, const char *);
int _RTLENTRY  _EXPFUNC _tcsnccmp(const char *, const char *, size_t);
int _RTLENTRY  _EXPFUNC _tcsncmp(const char *, const char *, size_t);
int _RTLENTRY  _EXPFUNC _tcsncicmp(const char *, const char *, size_t);
int _RTLENTRY  _EXPFUNC _tcsnicmp(const char *, const char *, size_t);

int _RTLENTRY  _EXPFUNC _tcscoll(const char *, const char *);
int _RTLENTRY  _EXPFUNC _tcsicoll(const char *, const char *);
int _RTLENTRY  _EXPFUNC _tcsnccoll(const char *, const char *, size_t);
int _RTLENTRY  _EXPFUNC _tcsncoll(const char *, const char *, size_t);
int _RTLENTRY  _EXPFUNC _tcsncicoll(const char *, const char *, size_t);
int _RTLENTRY  _EXPFUNC _tcsnicoll(const char *, const char *, size_t);


/* "logical-character" mappings */

size_t _RTLENTRY  _EXPFUNC _tcsclen(const char *);
char * _RTLENTRY  _EXPFUNC _tcsnccat(char *, const char *, size_t);
char * _RTLENTRY  _EXPFUNC _tcsnccpy(char *, const char *, size_t);
char * _RTLENTRY  _EXPFUNC _tcsncset(char *, unsigned int, size_t);


/* MBCS-specific mappings */

char * _RTLENTRY  _EXPFUNC _tcsdec(const char *, const char *);
char * _RTLENTRY  _EXPFUNC _tcsinc(const char *);
size_t _RTLENTRY  _EXPFUNC _tcsnbcnt(const char *, size_t);
size_t _RTLENTRY  _EXPFUNC _tcsnccnt(const char *, size_t);
unsigned int _RTLENTRY  _EXPFUNC _tcsnextc (const char *);
char * _RTLENTRY  _EXPFUNC _tcsninc(const char *, size_t);
char * _RTLENTRY  _EXPFUNC _tcsspnp(const char *, const char *);

char * _RTLENTRY  _EXPFUNC _tcslwr(char *);
char * _RTLENTRY  _EXPFUNC _tcsupr(char *);

size_t _RTLENTRY  _EXPFUNC _tclen(const char *);
void   _RTLENTRY  _EXPFUNC _tccpy(char *, const char *);
int    _RTLENTRY  _EXPFUNC _tccmp(const char *s1, const char *s2);

#else  /* (!defined( __cplusplus) || defined( _NO_INLINING )) */

inline char * _tcschr(const char * s1,unsigned int c) {return (char *)_mbschr((const unsigned char *)s1,c);}
inline size_t _tcscspn(const char * s1,const char * s2) {return _mbscspn((const unsigned char *)s1,(const unsigned char *)s2);}
inline char * _tcsncat(char * s1,const char * s2,size_t n) {return (char *)_mbsnbcat((unsigned char *)s1,(const unsigned char *)s2,n);}
inline char * _tcsncpy(char * s1,const char * s2,size_t n) {return (char *)_mbsnbcpy((unsigned char *)s1,(const unsigned char *)s2,n);}
inline char * _tcspbrk(const char * s1,const char * s2) {return (char *)_mbspbrk((const unsigned char *)s1,(const unsigned char *)s2);}
inline char * _tcsrchr(const char * s1,unsigned int c) {return (char *)_mbsrchr((const unsigned char *)s1,c);}
inline size_t _tcsspn(const char * s1,const char * s2) {return _mbsspn((const unsigned char *)s1,(const unsigned char *)s2);}
inline char * _tcsstr(const char * s1,const char * s2) {return (char *)_mbsstr((const unsigned char *)s1,(const unsigned char *)s2);}
inline char * _tcstok(char * s1,const char * s2) {return (char *)_mbstok((unsigned char *)s1,(const unsigned char *)s2);}

inline char * _tcsnset(char * s1,unsigned int c,size_t n) {return (char *)_mbsnbset((unsigned char *)s1,c,n);}
inline char * _tcsrev(char * s1) {return (char *)_mbsrev((unsigned char *)s1);}
inline char * _tcsset(char * s1,unsigned int c) {return (char *)_mbsset((unsigned char *)s1,c);}

inline int _tcscmp(const char * s1,const char * s2) {return _mbscmp((const unsigned char *)s1,(const unsigned char *)s2);}
inline int _tcsicmp(const char * s1,const char * s2) {return _mbsicmp((const unsigned char *)s1,(const unsigned char *)s2);}
inline int _tcsnccmp(const char * s1,const char * s2,size_t n) {return _mbsncmp((const unsigned char *)s1,(const unsigned char *)s2,n);}
inline int _tcsncmp(const char * s1,const char * s2,size_t n) {return _mbsnbcmp((const unsigned char *)s1,(const unsigned char *)s2,n);}
inline int _tcsncicmp(const char * s1,const char * s2,size_t n) {return _mbsnicmp((const unsigned char *)s1,(const unsigned char *)s2,n);}
inline int _tcsnicmp(const char * s1,const char * s2,size_t n) {return _mbsnbicmp((const unsigned char *)s1,(const unsigned char *)s2,n);}

inline int _tcscoll(const char * s1,const char * s2) {return _mbscoll((const unsigned char *)s1,(const unsigned char *)s2);}
inline int _tcsicoll(const char * s1,const char * s2) {return _mbsicoll((const unsigned char *)s1,(const unsigned char *)s2);}
inline int _tcsnccoll(const char * s1,const char * s2,size_t n) {return _mbsncoll((const unsigned char *)s1,(const unsigned char *)s2,n);}
inline int _tcsncoll(const char * s1,const char * s2,size_t n) {return _mbsnbcoll((const unsigned char *)s1,(const unsigned char *)s2,n);}
inline int _tcsncicoll(const char * s1,const char * s2,size_t n) {return _mbsnicoll((const unsigned char *)s1,(const unsigned char *)s2,n);}
inline int _tcsnicoll(const char * s1,const char * s2,size_t n) {return _mbsnbicoll((const unsigned char *)s1,(const unsigned char *)s2,n);}


/* logical-character mappings */

inline size_t _tcsclen(const char * s1) {return _mbslen((const unsigned char *)s1);}
inline char * _tcsnccat(char * s1,const char * s2,size_t n) {return (char *)_mbsncat((unsigned char *)s1,(const unsigned char *)s2,n);}
inline char * _tcsnccpy(char * s1,const char * s2,size_t n) {return (char *)_mbsncpy((unsigned char *)s1,(const unsigned char *)s2,n);}
inline char * _tcsncset(char * s1,unsigned int c,size_t n) {return (char *)_mbsnset((unsigned char *)s1,c,n);}


/* MBCS-specific mappings */

inline char * _tcsdec(const char * s1,const char * s2) {return (char *)_mbsdec((const unsigned char *)s1,(const unsigned char *)s2);}
inline char * _tcsinc(const char * s1) {return (char *)_mbsinc((const unsigned char *)s1);}
inline size_t _tcsnbcnt(const char * s1,size_t n) {return _mbsnbcnt((const unsigned char *)s1,n);}
inline size_t _tcsnccnt(const char * s1,size_t n) {return _mbsnccnt((const unsigned char *)s1,n);}

inline unsigned int _tcsnextc(const char * s1) {unsigned int n=0; if (_ismbblead((unsigned int)*(unsigned char *)s1)) n=((unsigned int)*s1++)<<8; n+=(unsigned int)*s1; return(n);}

inline char * _tcsninc(const char * s1,size_t n) {return (char *)_mbsninc((const unsigned char *)s1,n);}
inline char * _tcsspnp(const char * s1,const char * s2) {return (char *)_mbsspnp((const unsigned char *)s1,(const unsigned char *)s2);}
inline char * _tcslwr(char * s1) {return (char *)_mbslwr((unsigned char *)s1);}
inline char * _tcsupr(char * s1) {return (char *)_mbsupr((unsigned char *)s1);}

inline size_t _tclen(const char * s1) {return _mbclen((const unsigned char *)s1);}
inline void   _tccpy(char * s1,const char * s2) {_mbccpy((unsigned char *)s1,(const unsigned char *)s2); return;}
inline int    _tccmp(const char *s1, const char *s2){ return  _mbsncmp((const unsigned char *)s1,(const unsigned char *)s2,1);}

#endif  /* (!defined ( __cplusplus) || defined( _NO_INLINING )) */

#endif  /* _MBC_USE_MACROS */

#define _tcscmpi        _tcsicmp
#define _tcsncmpi       _tcsnicmp

/* ctype functions */
#define _istalnum       _ismbcalnum
#define _istalpha       _ismbcalpha
#define _istdigit       _ismbcdigit
#define _istgraph       _ismbcgraph
#define _istlower       _ismbclower
#define _istprint       _ismbcprint
#define _istpunct       _ismbcpunct
#define _istspace       _ismbcspace
#define _istupper       _ismbcupper
#define _istlegal       _ismbclegal

#define _totlower       _mbctolower
#define _totupper       _mbctoupper

#define _istlead        _ismbblead
#define _istleadbyte    _ismbblead

#else  /* _MBCS */

/* ------------------- SBCS functions ----------------------- */


/* string functions */

#define _tcschr         strchr
#define _tcscspn        strcspn
#define _tcsncpy        strncpy
#define _tcsncat        strncat
#define _tcspbrk        strpbrk
#define _tcsrchr        strrchr
#define _tcsspn         strspn
#define _tcsstr         strstr
#define _tcstok         strtok

#define _tcsnset        strnset
#define _tcsrev         strrev
#define _tcsset         strset

#define _tcscmp         strcmp
#define _tcsicmp        stricmp
#define _tcsnccmp       strncmp
#define _tcsncmp        strncmp
#define _tcsncicmp      strnicmp
#define _tcsnicmp       strnicmp
#define _tcscmpi        strcmpi
#define _tcsncmpi       strncmpi

#define _tcscoll        strcoll
#define _tcsicoll       _stricoll
#define _tcsnccoll      _strncoll
#define _tcsncoll       _strncoll
#define _tcsncicoll     _strnicoll
#define _tcsnicoll      _strnicoll
#define _tcsxfrm        strxfrm

#define _ltcscoll       _lstrcoll
#define _ltcsicoll      _lstricoll
#define _ltcsnccoll     _lstrncoll
#define _ltcsncoll      _lstrncoll
#define _ltcsncicoll    _lstrnicoll
#define _ltcsnicoll     _lstrnicoll
#define _ltcsxfrm       _lstrxfrm

/* MBCS specific functions */

#define _tcsdec         _strdec
#define _tcsinc         _strinc
#define _tcsnbcnt       _strncnt
#define _tcsnccnt       _strncnt
#define _tcsnextc       _strnextc
#define _tcsninc        _strninc
#define _tcsspnp        _strspnp

#define _tcslwr         strlwr
#define _tcsupr         strupr

#define _istlegal(a)    (1)
#define _istlead(a)     (0)
#define _istleadbyte(a) (0)


#if (!defined ( __cplusplus) || defined( _NO_INLINING ))

#define _tclen(a)       (1)
#define _tccpy(a,b)     ((*(a))=(*(b)))
#define _tccmp(a,b)     ((*(a))-(*(b)))

#else  /* (!defined ( __cplusplus) || defined( _NO_INLINING )) */

inline size_t _RTLENTRY _tclen(const char *s ){return (1); }
inline void   _RTLENTRY _tccpy(char *s1, const char *s2) {*(s1) = *(s2); }
inline int    _RTLENTRY _tccmp(const char *s1, const char *s2){ return (int) ( ((unsigned char*)s1)-((unsigned char*)s2)); }

#endif  /* (!defined ( __cplusplus) || defined( _NO_INLINING )) */

/* logical-character mappings */

#define _tcsclen        strlen
#define _tcsnccat       strncat
#define _tcsnccpy       strncpy
#define _tcsncset       strnset

/* ctype functions */

#define _istalnum       isalnum
#define _istalpha       isalpha
#define _istdigit       isdigit
#define _istgraph       isgraph
#define _istlower       islower
#define _istprint       isprint
#define _istpunct       ispunct
#define _istspace       isspace
#define _istupper       isupper
#define _istascii       isascii
#define _istcntrl       iscntrl
#define _istxdigit      isxdigit

#define _totlower       tolower
#define _totupper       toupper

#if (!defined (__cplusplus) || defined( _NO_INLINING ))

#define _strinc(a)       ((a)+1)
#define _strdec(a, b)    ((b)-1)
#define _strnextc(a)     ((unsigned int) *(a))
#define _strninc(a, b)   ((a)+(b))
#define _strncnt(a, b)   ((strlen(a)>b) ? b : strlen(a))
#define _strspnp(a, b)   ((*((a)+strspn(a,b))) ? ((a)+strspn(a,b)) : NULL)

#else  /* (!defined( __cplusplus) || defined( _NO_INLINING )) */

inline char * _RTLENTRY strinc(const char * s) { return (char *)(s+1); }
inline char * _RTLENTRY strdec(const char * s1, const char * s2) { return (char *)(s1,(s2-1)); }

inline char * _RTLENTRY _strinc(const char * s) { return (char *)(s+1); }
inline char * _RTLENTRY _strdec(const char * s1, const char * s2) { return (char *)(s1,(s2-1)); }
inline unsigned int _RTLENTRY _strnextc(const char *s) { return (unsigned int)*s; }
inline char * _RTLENTRY _strninc(const char * s, size_t n) { return (char *)(s+n); }
inline size_t _RTLENTRY _strncnt( const char * s, size_t n) { size_t len; len = strlen(s); return (len>n) ? n : len; }
inline char * _RTLENTRY _strspnp( const char * s1, const char * s2) { return (*(s1 += strspn(s1,s2))!='\0') ? (char*)s1 : NULL; }

#endif /* (!defined (__cplusplus) || defined( _NO_INLINING )) */

#endif /* _MBCS */

#else  /* _UNICODE */

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

#ifndef _WCTYPE_T_DEFINED
typedef wchar_t wctype_t;
#define _WCTYPE_T_DEFINED
#endif

#ifndef __TCHAR_DEFINED
typedef wchar_t         _TCHAR;
typedef wchar_t         _TSCHAR;
typedef wchar_t         _TUCHAR;
typedef wchar_t         _TXCHAR;
typedef wint_t          _TINT;
#define __TCHAR_DEFINED
#endif

#define _TEOF           WEOF
#define __T(x)          L ## x
#define _TEXT(x)        __T(x)
#define _T(x)           __T(x)

/* string functions */

#define _tcschr         wcschr
#define _tcscspn        wcscspn
#define _tcsncpy        wcsncpy
#define _tcsncat        wcsncat
#define _tcspbrk        wcspbrk
#define _tcsrchr        wcsrchr
#define _tcsspn         wcsspn
#define _tcsstr         wcsstr
#define _tcstok         wcstok
#define _tcsnset        _wcsnset
#define _tcsrev         _wcsrev
#define _tcsset         _wcsset
#define _tcscmp         wcscmp
#define _tcsicmp        _wcsicmp
#define _tcsnccmp       wcsncmp
#define _tcsncmp        wcsncmp
#define _tcsnicmp       _wcsnicmp
#define _tcsncicmp      _wcsnicmp
#define _tcscmpi        wcscmpi
#define _tcsncmpi       wcsncmpi
#define _tcscat         wcscat
#define _tcscpy         wcscpy
#define _tcspcpy        _wcspcpy
#define _tcslen         wcslen
#define _tcsdup         _wcsdup
#define _tcslwr         _wcslwr
#define _tcsupr         _wcsupr

#define _tcsdec         _wcsdec
#define _tcsinc         _wcsinc
#define _tcsnbcnt       _wcsncnt
#define _tcsnccnt       _wcsncnt
#define _tcsnextc       _wcsnextc
#define _tcsninc        _wcsninc
#define _tcsspnp        _wcsspnp

#define _tcscoll        wcscoll
#define _tcsicoll       _wcsicoll
#define _tcsnccoll      _wcsncoll
#define _tcsncoll       _wcsncoll
#define _tcsncicoll     _wcsnicoll
#define _tcsnicoll      _wcsnicoll
#define _tcsxfrm        wcsxfrm

#define _ltcscoll       _lwcscoll
#define _ltcsicoll      _lwcsicoll
#define _ltcsnccoll     _lwcsncoll
#define _ltcsncoll      _lwcsncoll
#define _ltcsncicoll    _lwcsnicoll
#define _ltcsnicoll     _lwcsnicoll
#define _ltcsxfrm       _lwcsxfrm

/* time functions */

#define _tasctime       _wasctime
#define _tutime         _wutime
#define _tctime         _wctime
#define _tstrdate       _wstrdate
#define _tstrtime       _wstrtime
#define _tcsftime       wcsftime
#define _ttzset         _wtzset
#define _ttzname        _wtzname

/* ctype functions */

#define _istalnum       iswalnum
#define _istalpha       iswalpha
#define _istdigit       iswdigit
#define _istgraph       iswgraph
#define _istlower       iswlower
#define _istprint       iswprint
#define _istpunct       iswpunct
#define _istspace       iswspace
#define _istupper       iswupper
#define _istascii       iswascii
#define _istcntrl       iswcntrl
#define _istxdigit      iswxdigit

#define _istlegal(a)    (1)
#define _istlead(a)     (0)
#define _istleadbyte(a) (0)

#define _totlower       towlower
#define _totupper       towupper

/* Execute functions */

#define _texecl     _wexecl
#define _texecle    _wexecle
#define _texeclp    _wexeclp
#define _texeclpe   _wexeclpe
#define _texecv     _wexecv
#define _texecve    _wexecve
#define _texecvp    _wexecvp
#define _texecvpe   _wexecvpe

#define _tspawnl    _wspawnl
#define _tspawnle   _wspawnle
#define _tspawnlp   _wspawnlp
#define _tspawnlpe  _wspawnlpe
#define _tspawnv    _wspawnv
#define _tspawnve   _wspawnve
#define _tspawnvp   _wspawnvp
#define _tspawnvp   _wspawnvp
#define _tspawnvpe  _wspawnvpe

#define _tsystem        _wsystem

/*  Path / Environment  specific mappings  */

#define _tfullpath      _wfullpath
#define _tsplitpath     _wsplitpath
#define _tfnsplit       _wfnsplit
#define _tfnmerge       _wfnmerge
#define _tmakepath      _wmakepath
#define _tsearchpath    wsearchpath
#define _tsearchenv     _wsearchenv
#define _tsearchstr     _wsearchstr
#define _tgetenv        _wgetenv
#define _tputenv        _wputenv

/*  I/O functions   */

#define _taccess        _waccess
#define _tchmod         _wchmod
#define _trtl_open      _wrtl_open
#define _trtl_creat     _wrtl_creat
#define _trtl_chmod     _wrtl_chmod
#define _tcreat         _wcreat
#define _tfindfirst     _wfindfirst
#define _tfindnext      _wfindnext
#define _tmktemp        _wmktemp
#define _topen          _wopen
#define _tremove        _wremove
#define _trename        _wrename
#define _tsopen         _wsopen
#define _tunlink        _wunlink

#define _tffblk         _wffblk

/* directory functions */

#define _topendir       wopendir
#define _treaddir       wreaddir
#define _trewinddir     wrewinddir
#define _tclosedir      wclosedir
#define _tDIR           wDIR
#define _tdirent        wdirent

/* stdio functions   */

#define _tpopen         _wpopen
#define _tfopen         _wfopen
#define _tfsopen        _wfsopen
#define _tfreopen       _wfreopen
#define _tfdopen        _wfdopen
#define _tperror        _wperror
#define _ttmpnam        _wtmpnam
#define _ttempnam       _wtempnam

/* program specific mappings*/

#define _tmain          wmain
#define _tWinMain       wWinMain
#define _tenviron       _wenviron
#define _targv          _wargv

/* Directory functions */

#define _tchdir     _wchdir
#define _tgetcurdir _wgetcurdir
#define _tgetcwd    _wgetcwd
#define _tgetdcwd   _wgetdcwd
#define _tmkdir     _wmkdir
#define _trmdir     _wrmdir

/* string conversion functions */

#define _ttof           _wtof
#define _ttoi           _wtoi
#define _ttol           _wtol
#define _ttoi64         _wtoi64
#define _ttold          _wtold
#define _tcstod         wcstod
#define _tcstol         wcstol
#define _tcstold        _wcstold
#define _tcstoul        wcstoul
#define _itot           _itow
#define _ltot           _ltow
#define _ultot          _ultow
#define _i64tot         _i64tow
#define _ui64tot        _ui64tow

/* Stat functions */

#define _tstat          _wstat
#define _tstati64       _wstati64

/* Setlocale functions */

#define _tsetlocale _wsetlocale

/* memory functions */

#define _tmemcpy        _wmemcpy
#define _tmemchr        _wmemchr
#define _tmemset        _wmemset

/* Unformated I/O */

#define _fgettc         fgetwc
#define _gettc          getwc
#define _fputtc         fputwc
#define _puttc          putwc
#define _fgettchar      _fgetwchar
#define _fgetts         fgetws
#define _fputtchar      _fputwchar
#define _puttchar       putwchar
#define _getts          _getws
#define _fputts         fputws
#define _gettchar       getwchar
#define _putts          _putws
#define _ungettc        ungetwc

/* Formated I/O */
#define _tprintf        wprintf
#define _vstprintf      vswprintf
#define _stprintf       swprintf
#define _ftprintf       fwprintf
#define _vftprintf      vfwprintf
#define _vtprintf       vwprintf


#define _tscanf         wscanf
#define _stscanf        swscanf
#define _vstscanf       vswscanf
#define _vtscanf        vwscanf
#define _vftscanf       vfwscanf
#define _ftscanf        fwscanf


#define _wcsinc(a)       ((a)+1)
#define _wcsdec(a, b)    ((b)-1)
#define _wcsnextc(a)     ((wchar_t) *(a))
#define _wcsninc(a, b)   ((a)+(b))
#define _wcsncnt(a, b)   ((wcslen(a)>b) ? b : wcslen(a))
#define _wcsspnp(a, b)   ((*((a)+wcsspn(a,b))) ? ((a)+wcsspn(a,b)) : NULL)

#endif /* _UNCODE */

#ifdef __cplusplus
}
#endif

#endif  /* __TCHAR_H */
