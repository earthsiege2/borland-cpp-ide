//----------------------------------------------------------------------------
// Borland WinSys Library
// Copyright (c) 1994, 1997 by Borland International, All Rights Reserved
//
//$Revision:   5.9  $
//
// Definition of class TString, a flexible universal string envelope class.
// Facilitates efficient construction and assignment of many string types
//----------------------------------------------------------------------------
#if !defined(WINSYS_STRING_H)
#define WINSYS_STRING_H

#if !defined(WINSYS_DEFS_H)
# include <winsys/defs.h>
#endif
#if !defined(SERVICES_OLE2INC_H)
# include <services/ole2inc.h>
#endif
#if !defined(SERVICES_MEMORY_H)
# include <services/memory.h>
#endif

#if !defined(BI_PLAT_MSW)
# error Locale classes are only supported under MSW
#endif

#if !defined(WINSYS_LCLSTRNG_H)
# include <winsys/lclstrng.h>
#endif
#if !defined(SERVICES_CSTRING_H)
# include <services/cstring.h>
#endif

#if defined(BI_NAMESPACE)
namespace ClassLib {
#endif

//
// class TSysStr
// ~~~~~ ~~~~~~~
// System string (BSTR) encapsulation. Also gives BSTRs a unique type
// Always assumes ownership of the BSTR, use Relinquish to take BSTR away.
//
class TSysStr {
  public:
    TSysStr() : P(0) {}
    TSysStr(const BSTR p) : P(p) {}
    TSysStr(const TSysStr& src) : P(::SysAllocString(src.P)) {}

   ~TSysStr() {if (P) ::SysFreeString(P);}

    int    operator !() const {return P == 0;}
    operator const BSTR() const {return P;}
    operator BSTR() {return P;}

    TSysStr& operator =(BSTR p) {if (P) ::SysFreeString(P); P = p; return *this;}
    operator BSTR far*() {if (P) {::SysFreeString(P); P = 0;} return &P;}

    BSTR   Relinquish() {BSTR p = P; P = 0; return p;}

  protected:
    BSTR P;

  private:
    void* operator new(size_t) {return 0;} // prohibit use of new, delete, etc
    void  operator delete(void*) {}
};

class TUString;

//
// class TString
// ~~~~~ ~~~~~~~
// Reference to reference counted string object TUString
// Lightweight reference object consisting of a pointer to actual object
// Facilitates copying and assignment with minimal string reallocations
//
class TString {
  public:
    // Construct a TString from any type of string
    //
    TString(const _TCHAR far* s = 0);
#if defined(BI_HAS_WCHAR)
    TString(const wchar_t* s);
#endif
    TString(BSTR s, bool loan);
    TString(TSysStr& s, bool loan);
    TString(const string& s);
    TString(TUString* s);
    TString(const TString& src);

   ~TString();

    // Information
    //
    int  Length() const;        // The length in characters of this string
    bool IsNull() const;        // Is the string NULL?
    bool IsWide() const;        // Are the string contents any kind of wide?

    // Assign any type of string into this TString
    //
    TString& operator =(const TString& s);
    TString& operator =(const string& s);
    TString& operator =(const _TCHAR far* s);
    TString& operator =(_TCHAR* s);
#if defined(BI_HAS_WCHAR)
    TString& operator =(const wchar_t* s);
    TString& operator =(wchar_t* s);
#endif

    // Convert this TString into the desired string type & return pointer into
    // this TString
    //
    operator const _TCHAR far*() const;
    operator _TCHAR*();
#if defined(BI_HAS_WCHAR)
    operator const wchar_t*() const;
    operator wchar_t*();
#endif

    // Relinquish ownership and return contents of this TString. Caller then
    // owns the string & must delete or free it.
    //
    BSTR     RelinquishSysStr() const;
#if defined(BI_HAS_WCHAR)
    wchar_t* RelinquishWide() const;
#endif
    _TCHAR*    RelinquishNarrow() const;
#if 1 
    _TCHAR*    Relinquish() const;
#else
    wchar_t* Relinquish() const;
#endif

    // Language related
    //
    TLangId GetLangId();
    void    SetLangId(TLangId id);

  protected:
    TUString* S;
};

//
// Provide ANSI to Wide conversion when OLE requires wide chars
// Allocate a unicode BSTR from an ANSI char*
//
#if defined(BI_OLECHAR_WIDE)
# define OleStr(s) TString(s)
# define OleText(s) L##s
  inline BSTR SysAllocString(const char far* str) {
    return ::SysAllocString((const wchar_t*)TString(str));
  }
#else
# define OleStr(s) s
# define OleText(s) s
#endif

//----------------------------------------------------------------------------

//
// class TUString
// ~~~~~ ~~~~~~~~
// Privately used by TString to manage string pointers
// This is a reference counted union of various string representatons
// Constructors/destructors are private to enforce reference count model
// Create functions are used to facilitate rapid allocation schemes
// Null pointers are never stored; instead a static null object is ref'd
//
class TUString {
  public:
    static TUString* Create(const _TCHAR far* str);
    static TUString* Create(_TCHAR* str);
#if defined(BI_HAS_WCHAR)
    static TUString* Create(const wchar_t* str);
    static TUString* Create(wchar_t* str);
#endif
    static TUString* Create(TSysStr& str, bool loan, TLangId lang = 0);
    static TUString* Create(BSTR str, bool loan, TLangId lang = 0);
    static TUString* Create(const string& str);

    TUString* Assign(const TUString& s);
    TUString* Assign(const string& s);
    TUString* Assign(const _TCHAR far* s);
    TUString* Assign(_TCHAR* s);
#if defined(BI_HAS_WCHAR)
    TUString* Assign(const wchar_t* s);
    TUString* Assign(wchar_t* s);
#endif
    TUString* Assign(BSTR str, TLangId lang);

    operator const _TCHAR far*() const;
    operator _TCHAR*();
#if defined(BI_HAS_WCHAR)
    operator const wchar_t*() const;
    operator wchar_t*();
#endif

    TUString& operator ++();    // Preincrement operator only
    TUString& operator --();    // Predecrement operator only

    int  Length() const;        // Return appropriate string length
    bool IsNull() const;        // Is the string a null string?
    bool IsWide() const;        // Are the string contents any kind of wide?

    TLangId Lang;
    void RevokeBstr(BSTR s);    // Used to restore if Created with loan==true
    void ReleaseBstr(BSTR s);   // Used to unhook  if Created with loan==true

#if defined(BI_HAS_WCHAR)
    static wchar_t* ConvertAtoW(const char* src, size_t len = -1);
    static char* ConvertWtoA(const wchar_t* src, size_t len = -1);
#endif

#if defined(BI_COMP_MSC)    // MSC can't handle the dtor being private
  public:
#else
  private:
#endif
   ~TUString() {Free();}

  private:
    TUString(const _TCHAR far& str);
    TUString(_TCHAR& str);
#if defined(BI_HAS_WCHAR)
    TUString(const wchar_t& str);
    TUString(wchar_t& str);
#endif
    TUString(TSysStr& str, bool loan, TLangId lang);
    TUString(BSTR str, bool loan, TLangId lang);
    TUString(const string& str);

    void Free();

    _TCHAR*    ChangeToCopy();
#if defined(BI_HAS_WCHAR)
    wchar_t* ChangeToWCopy();
#endif

    enum TKind {
      isNull,
      isConst, isCopy,
      isWConst, isWCopy,
      isBstr, isExtBstr,
      isString,
    } Kind : 16;
    int16 RefCnt;
    union {
      const _TCHAR far* Const;  // Passed-in string, NOT owned here, read-only
      _TCHAR* Copy;             // Local copy, must be deleted, read-write
#if defined(BI_HAS_WCHAR)
      const wchar_t* WConst;  // Unicode version of Const (Win32)
      wchar_t* WCopy;         // Unicode version of Copy (Win32)
#endif
      BSTR Bstr;              // Copy of pointer, owned here
      TStringRef* String;     // Placeholder for string:: object
    };

    static TUString Null;     // Null TString references this
    TUString() : Kind(isNull),Const(0),RefCnt(1),Lang(0) {} // for Null object

  friend class TString;       // Envelope string class
};

#if defined(BI_NAMESPACE)
}     // namespace ClassLib
#endif

//----------------------------------------------------------------------------
// Inlines
//

//
// Construct a TString from a character array
//
inline TString::TString(const _TCHAR far* s)
:
  S(TUString::Create(s))
{
}

#if defined(BI_HAS_WCHAR)
//
// Construct a TString from a wide character array
//
inline TString::TString(const wchar_t* s)
:
  S(TUString::Create(s))
{
}
#endif

//
// Construct a TString from a BSTR (OLE String)
//
inline TString::TString(BSTR s, bool loan)
:
  S(TUString::Create(s, loan))
{
}

//
// Construct a TString from a System string (BSTR)
//
inline TString::TString(TSysStr& s, bool loan)
:
  S(TUString::Create(s, loan))
{
}

//
// Construct a TString from a string
//
inline TString::TString(const string& s)
:
  S(TUString::Create(s))
{
}

//
// Construct a TString from a TUString
//
inline TString::TString(TUString* s)
:
  S(s)
{
}

//
// Construct a TString from a TString (Copy Constructor)
//
inline TString::TString(const TString& src)
:
  S(src.S)
{
  ++*S;
}

//
// Destruct a TString (actually decrements a reference counter)
//
inline TString::~TString()
{
  --*S;
}

//
// Return the length of the string
//
inline int TString::Length() const
{
  return S->Length();
}

//
// Return true if string is empty
//
inline bool TString::IsNull() const
{
  return S->IsNull();
}

//
// Return true if string uses wide character set
//
inline bool TString::IsWide() const
{
  return S->IsWide();
}

//
// Copy contents of TString s into this string
//
inline TString& TString::operator =(const TString& s)
{
  S = S->Assign(*s.S); return *this;
}

//
// Copy contents of string s into this string
//
inline TString& TString::operator =(const string& s)
{
  S = S->Assign(s); return *this;
}

//
// Copy contents of const char* s into this string
//
inline TString& TString::operator =(const _TCHAR far* s)
{
  S = S->Assign(s); return *this;
}

//
// Copy contents of char* s into this string
//
inline TString& TString::operator =(_TCHAR* s)
{
  S = S->Assign(s); return *this;
}

#if defined(BI_HAS_WCHAR)

//
// Copy contents of const wchar_t* s into this string
//
inline TString& TString::operator =(const wchar_t* s)
{
  S = S->Assign(s); return *this;
}

//
// Copy contents of wchar_t* s into this string
//
inline TString& TString::operator =(wchar_t* s)
{
  S = S->Assign(s); return *this;
}
#endif

//
// Return string as a const char far*
//
inline TString::operator const _TCHAR far*() const
{
  return S->operator const _TCHAR far*();
}

//
// Return string as a char*
//
inline TString::operator _TCHAR*()
{
  return S->operator _TCHAR*();
}

#if defined(BI_HAS_WCHAR)

//
// Return string as a const wchar_t*
//
inline TString::operator const wchar_t*() const
{
  return S->operator const wchar_t*();
}

//
// Return string as a wchar_t*
//
inline TString::operator wchar_t*()
{
  return S->operator wchar_t*();
}
#endif

//
// Return a pointer (BSTR) to a copy of the string
//
inline BSTR TString::RelinquishSysStr() const
{
#if defined(BI_OLECHAR_WIDE)
  return ::SysAllocString((const wchar_t*)*S);
#else
  return ::SysAllocString((const _TCHAR*)*S);
#endif
}

#if defined(BI_HAS_WCHAR)
//
// Return a pointer (wchar_t*) to a copy of the string
//
inline wchar_t* TString::RelinquishWide() const
{
  return strnewdup((const wchar_t*)*S);
}
#endif

//
// Return a pointer (char*) to a copy of the string
//
inline _TCHAR* TString::RelinquishNarrow() const
{
  return strnewdup((const _TCHAR*)*S);
}

//
// Return a pointer (char*) to a copy of the string
//
#if 1 
inline _TCHAR* TString::Relinquish() const
{
  return RelinquishNarrow();
}
#else
inline wchar_t* TString::Relinquish() const
{
  return RelinquishWide();
}
#endif

//
// Get Language Id of this string
//
inline TLangId TString::GetLangId()
{
  return S->Lang;
}


//
// Set Language Id of this string
//
inline void TString::SetLangId(TLangId id)
{
  S->Lang = id;
}

//----------------------------------------------------------------------------

//
// Increment reference counter for this string
//
inline TUString& TUString::operator ++()
{
  ++RefCnt;
  return *this;
}

//
// Decrement reference counter for this string
//
inline TUString& TUString::operator --()
{
  if (--RefCnt != 0)
    return *this;
  delete this;
  return Null;
}

//
// Return true if string is empty
//
inline bool TUString::IsNull() const
{
  return Kind == isNull;
}

//
// Return true if string uses wide character set
//
inline bool TUString::IsWide() const
{
#if defined(BI_OLECHAR_WIDE)
  return Kind == isWConst || Kind == isWCopy || Kind == isBstr || Kind == isExtBstr;
#else
  return Kind == isWConst || Kind == isWCopy;
#endif
}

#endif  // WINSYS_STRING_H
