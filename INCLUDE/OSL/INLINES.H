//----------------------------------------------------------------------------
// ObjectSupport
// (C) Copyright 1992, 1994 by Borland International, All Rights Reserved
//
//   Common inline templates & functions
//----------------------------------------------------------------------------
#if !defined(OSL_INLINES_H)
#define OSL_INLINES_H

#if !defined(OSL_DEFS_H)
# include <osl/defs.h>
#endif
#if !defined(STRING_H)
# include <string.h>
#endif

//
// Misc support functions & macros
//
template <class T> inline void Swap(T far& a, T far& b) {a^=b; b^=a; a^=b;}
template <class T> inline T Min(T a, T b) {return a<b ? a : b;}
template <class T> inline T Max(T a, T b) {return a>b ? a : b;}
int    Sqrt(long val);
#define COUNTOF(s)   (sizeof(s) / sizeof((s)[0]))
#if !defined(LOWORD)
# define LOWORD(l)           ((uint16)(l))
#endif
#if !defined(HIWORD)
# define HIWORD(l)           ((uint16)((uint32)(l) >> 16))
#endif

//
// Inline versions of common RTL functions, overloaded for far ptrs for use
// when in a near data model.
//
#if defined(BI_DATA_NEAR)
  inline void far* memccpy(void far* d, const void far* s, int c, size_t n)
                     {return _fmemccpy(d, s, c, n);}
  inline void far* memchr(const void far* s, int c, size_t n)
                     {return _fmemchr(s, c, n);}
  inline int       memcmp(const void far* s1, const void far* s2, size_t n)
                     {return _fmemcmp(s1, s2, n);}
  inline void far* memcpy(void far* d, const void far* s, size_t n)
                     {return _fmemcpy(d, s, n);}
  inline int       memicmp(const void far* s1, const void far* s2, size_t n)
                     {return _fmemicmp(s1, s2, n);}
  inline void far* memset(void far* s, int c, size_t n)
                     {return _fmemset(s, c, n);}
  inline void far* memmove(void far* d, const void far* s, size_t n)
                     {return _fmemmove(d, s, n);}

  inline char far* strcat(char far* d, const char far* s)
                     {return _fstrcat(d, s);}
  inline char far* strchr(const char far* s, int c) {return _fstrchr(s, c);}
  inline int       strcmp(const char far* s1, const char far* s2)
                     {return _fstrcmp(s1, s2);}
  inline char far* strcpy(char far* d, const char far* s)
                     {return _fstrcpy(d, s);}
  inline int       stricmp(const char far* s1, const char far* s2)
                     {return _fstricmp(s1, s2);}
  inline size_t    strlen(const char far* s) {return _fstrlen(s);}
  inline char far* strlwr(char far* s) {return _fstrlwr(s);}
  inline char far* strncat(char far* d, const char far* s, size_t maxlen)
                     {return _fstrncat(d, s, maxlen);}
  inline int       strncmp(const char far* s1, const char far* s2, size_t maxlen)
                     {return _fstrncmp(s1, s2, maxlen);}
  inline char far* strncpy(char far* d, const char far* s, size_t maxlen)
                     {return _fstrncpy(d, s, maxlen);}
  inline int       strnicmp(const char far* s1, const char far* s2, size_t maxlen)
                     {return _fstrnicmp(s1, s2, maxlen);}
  inline char far* strrchr(const char far* s, int c) {return _fstrrchr(s, c);}
  inline char far* strtok(char far* s1, const char far* s2)
                     {return _fstrtok(s1, s2);}
  inline char far* strupr(char far* s) {return _fstrupr(s);}
#endif

//
// type overloaded version of Window's huge mem copy (hmemcpy) for flat models
//
#if !defined(BI_PLAT_WIN16)
  inline void      hmemcpy(void* d, const void* s, long n) {memcpy(d, s, n);}
#endif

//
// strnewdup() uses new char[], to allow duplicated strings to be deleted
//
char* _BIDSFUNC strnewdup(const char* s, size_t allocSize = 0);
#if defined(BI_DATA_NEAR)
  char far* _BIDSFUNC strnewdup(const char far* s, size_t allocSize = 0);
  long atol(const char far* s);
#endif
#if !defined(BI_PLAT_WIN16)
  wchar_t* _BIDSFUNC strnewdup(const wchar_t* s, size_t allocSize = 0);
  wchar_t* _BIDSFUNC strcpy(wchar_t* dst, const wchar_t* src);
  size_t   _BIDSFUNC strlen(const wchar_t* s);
#endif
  
#endif  // OSL_INLINES_H
