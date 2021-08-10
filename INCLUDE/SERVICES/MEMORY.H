//----------------------------------------------------------------------------
// Borland Services Library
// Copyright (c) 1995, 1996 by Borland International, All Rights Reserved
//
//$Revision:   5.13  $
//
// Reliable platform independent header for common memory and string functions
//
//----------------------------------------------------------------------------
#if !defined(SERVICES_MEMORY_H)
#define SERVICES_MEMORY_H

#if !defined(SERVICES_DEFS_H)
# include <services/defs.h>
#endif
#if defined(BI_COMP_BORLANDC)
# include <mem.h>
#else
# include <memory.h>
#endif
#if !defined(__STRING_H) && !defined(_INC_STRING)
# include <string.h>
#endif

#if !defined(SERVICES_WSYSINC_H)
# include <services/wsysinc.h>
#endif

#if defined(BI_PLAT_MSW)
//
// To support double-byte and extended characters, map the standard string
// functions to the windows calls (but not if they are macros)
//
inline int _RTLENTRYF strcmp(const char far* s1, const char far* s2)
                   {return lstrcmp(s1, s2);}
inline int _RTLENTRYF stricmp(const char far* s1, const char far* s2)
                   {return lstrcmpi(s1, s2);}
#if !defined(strcmpi)
inline int       strcmpi(const char far* s1, const char far* s2)
                   {return lstrcmpi(s1, s2);}
#endif
#endif //BI_PLAT_MSW

#if defined(BI_DBCS_SUPPORT)
  inline uint      CharSize(const char far* s) {return ::AnsiNext(s) - s;}
#else
  inline uint      CharSize(const char far*) {return sizeof(char);}
#endif

#if defined(BI_PLAT_MSW)
inline char CharUpper(char c) {::AnsiUpperBuff(&c,1); return c;}
inline char CharLower(char c) {::AnsiLowerBuff(&c,1); return c;}
#endif

//
//
//
template<class T> class TCharIterator {
  public:
    TCharIterator(T far* p);

    T far* Next() const;
    T far* Current() const;

    T far* operator ++();    // prefix
    T far* operator ++(int); // postfix

    operator T far*() const;

  protected:
    T far* P;
};

//
//
//
template<class T> class TBidirCharIterator : public TCharIterator<T> {
  public:
    TBidirCharIterator(T far* begin, T far* p);

    T far* Prev() const;

    T far* operator --();    // prefix
    T far* operator --(int); // postfix

  private:
    T far* Begin;
};

//
template<class T> inline TCharIterator<T>::TCharIterator(T far* p)
:
  P(p)
{
}

//
template<class T> inline T far* TCharIterator<T>::Next() const
{
#if defined(BI_DBCS_SUPPORT)
  return *P ? ::AnsiNext(P) : P + 1;
#else
  return P + 1;
#endif
}

//
template<class T> inline T far* TCharIterator<T>::Current() const
{
  return P;
}

//
template<class T> inline T far* TCharIterator<T>::operator ++()
{
  return P = Next();
}

//
template<class T> inline T far* TCharIterator<T>::operator ++(int)
{
  T far* p = P;
  P = Next();
  return p;
}

//
template<class T> inline TCharIterator<T>::operator T far*() const
{
  return P;
}

//
template<class T> inline TBidirCharIterator<T>::TBidirCharIterator(T far* begin, T far* p)
:
  P(p), Begin(begin)
{
}

//
template<class T> inline T far* TBidirCharIterator<T>::Prev() const
{
#if defined(BI_DBCS_SUPPORT)
  return ::AnsiPrev(Begin, P);
#else
  return P > Begin ? P - 1 : P;
#endif
}

//
template<class T> inline T far* TBidirCharIterator<T>::operator --()    // prefix
{
  return P = Prev();
}

//
template<class T> inline T far* TBidirCharIterator<T>::operator --(int) // postfix
{
  T far* p = P;
  P = Prev();
  return p;
}

//
// Inline versions of memory.h & string.h functions, overloaded for far ptrs
// for use when in a near data model.
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
  inline char far* strcpy(char far* d, const char far* s)
                     {return _fstrcpy(d, s);}
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
// Type overloaded version of Window's huge mem copy (hmemcpy) for flat memory
// models.
//
#if defined(BI_PLAT_WIN32)
  inline void      hmemcpy(void* d, const void* s, long n) {memcpy(d, s, n);}
#endif

//
// A C++ version of strdup(), strnewdup(). Uses new char[], to allow duplicated
// strings to be deleted[].
// Also a far string version of atol for near data models
//
char* _SVCSFUNC strnewdup(const char* s, size_t minAllocSize = 0);
#if defined(BI_DATA_NEAR)
  char far* _SVCSFUNC strnewdup(const char far* s, size_t minAllocSize = 0);
  char* _SVCSFUNC nstrnewdup(const char far* s, size_t minAllocSize = 0);
  long atol(const char far* s);
#else
# define nstrnewdup strnewdup
#endif

#if !defined(BI_PLAT_WIN16)
# if !defined(_WCHAR_T_DEFINED)
    typedef unsigned short wchar_t;
#   define _WCHAR_T_DEFINED
# endif
  wchar_t* _SVCSFUNC strnewdup(const wchar_t* s, size_t minAllocSize = 0);
  wchar_t* _SVCSFUNC strcpy(wchar_t* dst, const wchar_t* src);
  size_t   _SVCSFUNC strlen(const wchar_t* s);
#endif

#endif  // SERVICES_MEM_H
