//----------------------------------------------------------------------------
// (C) Copyright 1994 by Borland International, All Rights Reserved
//
// TUString implementation (others functions are inline)
//
//----------------------------------------------------------------------------
#if !defined(_Windows)
# define _Windows      // pretend we are in windows to get the headers we need
#endif
#if !defined(INC_OLE2)
# define INC_OLE2      // Make sure we get Ole2 headers
#endif
#include <osl/ustring.h>
#include <string.h>

TUString TUString::Null;   // null TAutoStrings reference this object

#if !defined(BI_HAS_WCHAR)
# define lstrcpyA lstrcpy
# define lstrlenA lstrlen
#endif

#if defined(BI_HAS_WCHAR)
//
// Take a wide char string & return an ANSI string in a new'd char[] buffer
//
char* TUString::ConvertWtoA(const wchar_t* src, size_t len)
{
  size_t size = WideCharToMultiByte(CP_ACP, 0, src, len, 0, 0, 0, 0);
  char* dst = new char[size + (len != -1)];  // room for null if fixed size
  size = WideCharToMultiByte(CP_ACP, 0, src, len, dst, size, 0, 0);
  if (len != -1)
    dst[size] = 0;
  return dst;
}

//
// Take an ANSI char string & return a wide string in a new'd wchar_t[] buffer
//
wchar_t* TUString::ConvertAtoW(const char* src, size_t len)
{
  size_t size = MultiByteToWideChar(CP_ACP, 0, src, len, 0, 0);
  wchar_t* dst = new wchar_t[size + (len != -1)];
  size = MultiByteToWideChar(CP_ACP, 0, src, len, dst, size);
  if (len != -1)
    dst[size] = 0;
  return dst;
}
#endif

//------------------------------------------------------------------------

//
// Change UString to isCopy regardless of current type
//
char* TUString::ChangeToCopy()
{
  char* dst = 0;
  const char far* src;
  int len;
  switch (Kind) {
    case isNull:
      return 0;
    case isConst:
      src = Const;
      len = lstrlenA(Const);
      break;
    case isCopy:
      return Copy;
#if defined(BI_HAS_WCHAR)
    case isWConst:
      dst = ConvertWtoA(WConst);
      break;
    case isWCopy:
      dst = ConvertWtoA(WCopy);
      delete [] WCopy;
      break;
#endif
#if defined(BI_OLECHAR_WIDE)
    case isBstr:
    case isExtBstr:
      dst = ConvertWtoA(Bstr, ::SysStringLen(Bstr));
      break;
#else
    case isBstr:
    case isExtBstr:
      src = Bstr;
      len = ::SysStringLen(Bstr);
      break;
#endif
    case isString:
      src = ((string*)&String)->c_str();
      len = ((string*)&String)->length();
  }
  if (!dst) {
    dst = new char[len+1];
    _fmemcpy(dst, src, len+1);
  }
  if (Kind == isBstr)
    ::SysFreeString(Bstr);
  Kind = isCopy;
  Copy = dst;
  return Copy;
}

#if defined(BI_HAS_WCHAR)
//
// Change UString to isWCopy regardless of current type
//
wchar_t* TUString::ChangeToWCopy()
{
  wchar_t* dst = 0;
  const wchar_t* src;
  int len;
  switch (Kind) {
    case isNull:
      return 0;
    case isConst:
      dst = ConvertAtoW(Const);
      break;
    case isCopy:
      dst = ConvertAtoW(Copy);
      delete [] Copy;
      break;
    case isWConst:
      src = WConst;
      len = lstrlenW(WConst);
      break;
    case isWCopy:
      return WCopy;
#if defined(BI_OLECHAR_WIDE)
    case isBstr:
    case isExtBstr:
      src = Bstr;
      len = ::SysStringLen(Bstr);
      if (Kind == isBstr)
        ::SysFreeString(Bstr);
      break;
#else                // This case probably never happens
    case isBstr:
    case isExtBstr:
      dst = ConvertAtoW(Bstr, ::SysStringLen(Bstr));
      if (Kind == isBstr)
        ::SysFreeString(Bstr);
      break;
#endif
    case isString:
      dst = ConvertAtoW(((string*)&String)->c_str(), ((string*)&String)->length());
  }
  if (!dst) {
    dst = new wchar_t[len+1];
    _fmemcpy(dst, src, (len+1) * sizeof(wchar_t));
  }
  Kind = isWCopy;
  WCopy = dst;
  return WCopy;
}
#endif

//------------------------------------------------------------------------
// inline ctors used by Create functions

inline TUString::TUString(const char far& str)
:
  Kind(isConst), Const(&str), RefCnt(1), Lang(0)
{
}

inline TUString::TUString(char& str)
:
  Kind(isCopy), RefCnt(1), Lang(0)
{
  Copy = new char[lstrlenA(&str)+1];
  lstrcpyA(Copy, &str);
}

#if defined(BI_HAS_WCHAR)
inline TUString::TUString(const wchar_t& str)
:
  Kind(isWConst), WConst(&str), RefCnt(1), Lang(0)
{
}
  
inline TUString::TUString(wchar_t& str)
:
  Kind(isWCopy), RefCnt(1), Lang(0)
{
  WCopy = new wchar_t[lstrlenW(&str)+1];
  lstrcpyW(WCopy, &str);
}
#endif

inline TUString::TUString(BSTR str, bool loan, TLangId lang)
:
  Kind(loan ? isExtBstr : isBstr), Bstr(str), RefCnt(loan ? 2 : 1), Lang(lang)
{
}

inline void* operator new(size_t, TStringRef** p) {return p;}

inline TUString::TUString(const string& str)
:
  Kind(isString), RefCnt(1), Lang(0)
{
  new(&String) string(str);
}

//------------------------------------------------------------------------

TUString* TUString::Create(const char far* str)
{
  return str && *str ? new TUString(*str) : &++Null;
}

TUString* TUString::Create(char* str)
{
  return str && *str ? new TUString(*str) : &++Null;
}

#if defined(BI_HAS_WCHAR)
TUString* TUString::Create(const wchar_t* str)
{
  return str && *str ? new TUString(*str) : &++Null;
}

TUString* TUString::Create(wchar_t* str)
{
  return str && *str ? new TUString(*str) : &++Null;
}
#endif

TUString* TUString::Create(BSTR str, bool loan, TLangId lang)
{
  if (str && ::SysStringLen(str))
    return new TUString(str, loan, lang);
  if (!loan)
    ::SysFreeString(str);
  return &++Null;
}

TUString* TUString::Create(const string& str)
{
  return str.length() ? new TUString(str) : &++Null;
}

TUString* TUString::Assign(const TUString& s)
{
  if (RefCnt == 1 && Kind != isNull && Kind != isExtBstr)
    Free();
  else
    --*this;

  const_cast<TUString&>(s).RefCnt++;
  return &const_cast<TUString&>(s);
}

TUString* TUString::Assign(const string& s)
{
  if (s.length() && RefCnt == 1 && Kind != isNull && Kind != isExtBstr) {
    Free();
    Kind = isString;
    new(&String) string(s);
    return this;
  }
  else {
    --*this;
    return Create(s);
  }
}

TUString* TUString::Assign(const char far* s)
{
  if (s && *s && RefCnt == 1 && Kind != isNull && Kind != isExtBstr) {
    Free();
    Kind = isConst;
    Const = s;
    return this;
  }
  else {
    --*this;
    return Create(s);
  }
}

TUString* TUString::Assign(char* s)
{
  if (s && *s && RefCnt == 1 && Kind != isNull && Kind != isExtBstr) {
    Free();
    Kind = isCopy;
    Copy = new char[lstrlenA(s)+1];
    lstrcpyA(Copy, s);
    return this;
  }
  else {
    --*this;
    return Create(s);
  }
}

#if defined(BI_HAS_WCHAR)
TUString* TUString::Assign(const wchar_t* s)
{
  if (s && *s && RefCnt == 1 && Kind != isNull && Kind != isExtBstr) {
    Free();
    Kind = isWConst;
    WConst = s;
    return this;
  }
  else {
    --*this;
    return Create(s);
  }
}

TUString* TUString::Assign(wchar_t* s)
{
  if (s && *s && RefCnt == 1 && Kind != isNull && Kind != isExtBstr) {
    Free();
    Kind = isWCopy;
    WCopy = new wchar_t[lstrlenW(s)+1];
    lstrcpyW(WCopy, s);
    return this;
  }
  else {
    --*this;
    return Create(s);
  }
}
#endif

TUString* TUString::Assign(BSTR str, TLangId lang)
{
  if (RefCnt==1 && Kind != isNull && Kind != isExtBstr) {
    Free();
    Kind = isBstr;
    Bstr = str;
    Lang = lang;
    if (Bstr && ::SysStringLen(Bstr))
      return this;
    delete this;
    return &++Null;
  }
  else {
    --*this;
    return Create(str, false, lang);
  }
}

TUString::operator const char far*() const
{
  switch (Kind) {
    case isNull:    return 0;
    case isConst:   return Const;
    case isCopy:    return Copy;    
    case isString:  return ((string*)&String)->c_str();
#if defined(BI_OLECHAR_WIDE)
    case isBstr:
    case isExtBstr: return const_cast<TUString*>(this)->ChangeToCopy();
#else
    case isBstr:
    case isExtBstr: return Bstr;
#endif
    case isWConst:
    case isWCopy:   return const_cast<TUString*>(this)->ChangeToCopy();
  }
  return 0; // suppress warning
}

TUString::operator char*()
{
  return ChangeToCopy();
}

#if defined(BI_HAS_WCHAR)
TUString::operator const wchar_t*() const
{
  switch (Kind) {
    case isNull:    return 0;
    case isWConst:  return WConst;
    case isWCopy:   return WCopy;    
#if defined(BI_OLECHAR_WIDE)
    case isBstr:
    case isExtBstr: return Bstr;
#else
    case isBstr:
    case isExtBstr: return const_cast<TUString*>(this)->ChangeToWCopy();
#endif
    case isConst:
    case isCopy: 
    case isString:  return const_cast<TUString*>(this)->ChangeToWCopy();
  }
  return 0; // suppress warning
}

TUString::operator wchar_t*()
{
  return ChangeToWCopy();
}
#endif

//
// 
//
int TUString::Length() const
{
  switch (Kind) {
    case isNull:    return 0;
#if defined(BI_HAS_WCHAR)
    case isWConst:  return lstrlenW(WConst);
    case isWCopy:   return lstrlenW(WCopy);
#endif
    case isBstr:
    case isExtBstr: return ::SysStringLen(Bstr);
    case isConst:   return lstrlenA(Const);
    case isCopy:    return lstrlenA(Copy);
    case isString:  return ((string*)&String)->length();
  }
  return 0; // suppress warning
}

//
// Revokes BSTR ownership from this UString
//
void TUString::RevokeBstr(BSTR s)
{
  if (Kind != isExtBstr || Bstr != s)
    return;
  if (RefCnt == 1) {
    Kind = isNull;
    delete this;
    return;
  }
  Kind = isCopy;
#if defined(BI_OLECHAR_WIDE)
  WCopy = new wchar_t[lstrlenW(s)+1];
  lstrcpyW(WCopy, s);
#else
  Copy = new char[lstrlenA(s)+1];
  lstrcpyA(Copy, s);
#endif
}

//
// Passes BSTR ownership to this UString
//
void TUString::ReleaseBstr(BSTR s)
{
  if (Kind == isExtBstr && Bstr == s) {
    Kind = isBstr;
    --*this;
  }
  else       // has been overwritten with converted type
    ::SysFreeString(Bstr);
}

//
// Free any resources held by this UString. Union & Kind left in random state;
// must be reinitialized before use.
//
void TUString::Free()
{
  switch (Kind) {
    case isCopy:    delete [] Copy; break;
#if defined(BI_HAS_WCHAR)
    case isWCopy:   delete [] WCopy; break;
#endif
    case isBstr:    ::SysFreeString(Bstr); break;
    case isString:  ((string*)&String)->string::~string();
  }
  Lang = 0;
//Kind = isNull;  // for safety, not really needed
}
