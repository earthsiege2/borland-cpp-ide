//----------------------------------------------------------------------------
// ObjectSupport
// (C) Copyright 1994 by Borland International, All Rights Reserved
//
//  TString, TUstring - localized name support
//  TRegItem, TRegList - associative array of localizable string parameters
//----------------------------------------------------------------------------
#if !defined(OSL_USTRING_H)
#define OSL_USTRING_H

#if !defined(OSL_DEFS_H)
# if !defined(INC_OLE2)
#   define INC_OLE2        // Locale needs Ole2 when 16bit, let osl/defs get it
# endif
# include <osl/defs.h>
#elif !defined(__OLE2_H)
# if defined(BI_PLAT_WIN16)
#   include <ole2.h>       // Get Win16 Ole2 headers now if we missed above
#   if !defined(__DISPATCH_H)
#     include <dispatch.h>
#   endif
#   if !defined(__OLENLS_H)
#     include <olenls.h>
#   endif
# else
#   error Win32 Ole2 headers cannot be included after Windows.h, define INC_OLE2 first
# endif
#endif
#if !defined(BI_PLAT_MSW)
# error Locale classes are only supported under MSW
#endif
#if !defined(OSL_LOCALE_H)
# include <osl/locale.h>
#endif
#if !defined(__COMMDLG_H)
# include <commdlg.h>   // only for OFN_xxx defines
#endif
#if !defined(__CSTRING_H)
# include <cstring.h>
#endif

//----------------------------------------------------------------------------
// OLECHAR & BSTR is char under Win16, and wchar_t under Win32
//
#if !defined(BI_PLAT_WIN16)
# define BI_OLECHAR_WIDE    // OLECHAR is wide (wchar_t)
# define BI_HAS_WCHAR       // platform has wide char functions
#endif

//----------------------------------------------------------------------------
// TUString class - privately used by TString to manage string pointers
//   This is a reference counted union of various string representatons
//   Constructors/destructors are private to enforce reference count model
//   Create functions are used to facilitate rapid allocation schemes
//   Null pointers are never stored; instead a static null object is ref'd
//
class TUString {
  public:
    static TUString* Create(const char far* str);
    static TUString* Create(char* str);
#if defined(BI_HAS_WCHAR)
    static TUString* Create(const wchar_t* str);
    static TUString* Create(wchar_t* str);
#endif
    static TUString* Create(BSTR str, bool loan, TLangId lang = 0);
    static TUString* Create(const string& str);

    TUString* Assign(const TUString& s);
    TUString* Assign(const string& s);
    TUString* Assign(const char far* s);
    TUString* Assign(char* s);
#if defined(BI_HAS_WCHAR)
    TUString* Assign(const wchar_t* s);
    TUString* Assign(wchar_t* s);
#endif
    TUString* Assign(BSTR str, TLangId lang);

    operator const char far*() const;
    operator char*();
#if defined(BI_HAS_WCHAR)
    operator const wchar_t*() const;
    operator wchar_t*();
#endif

    TUString& operator ++();    // preincrement operator only
    TUString& operator --();    // predecrement operator only

    int Length() const;         // return appropriate string length
    bool IsNull() const;        // is the string a null string?

    TLangId Lang;
    void RevokeBstr(BSTR s);    // used to restore if Created with loan==true
    void ReleaseBstr(BSTR s);   // used to unhook  if Created with loan==true

#if defined(BI_HAS_WCHAR)
    static wchar_t* ConvertAtoW(const char* src, size_t len = -1);
    static char* ConvertWtoA(const wchar_t* src, size_t len = -1);
#endif

  private:
    TUString(const char far& str);
    TUString(char& str);
#if defined(BI_HAS_WCHAR)
    TUString(const wchar_t& str);
    TUString(wchar_t& str);
#endif
    TUString(BSTR str, bool loan, TLangId lang);
    TUString(const string& str);

   ~TUString() {Free();}
    void Free();

    char*    ChangeToCopy();
#if defined(BI_HAS_WCHAR)
    wchar_t* ChangeToWCopy();
#endif

    enum TKind {
      isNull=0, isConst, isCopy, isWConst, isWCopy, isBstr, isExtBstr, isString
    } Kind;
    int RefCnt;
    union {
      const char far* Const;  // Passed-in string, NOT owned here, read-only
      char* Copy;             // Local copy, must be deleted, read-write
#if defined(BI_HAS_WCHAR)
      const wchar_t* WConst;  // Unicode version of Const (Win32)
      wchar_t* WCopy;         // Unicode version of Copy (Win32)
#endif
      BSTR Bstr;              // Copy of pointer, owned here
      TStringRef* String;     // Placeholder for string:: object
    };

    static TUString Null;     // null TString references this
    TUString() : Kind(isNull),Const(0),RefCnt(1),Lang(0) {} // for Null object
};

//----------------------------------------------------------------------------
// TString class - reference to reference counted string object TUString
//   Lightweight reference object consisting of a pointer to actual object
//   Facilitates copying and assignment with minimal string reallocations
//
class TString {
  public:
    TString(const char far* s = 0) : S(TUString::Create(s)) {}
#if defined(BI_HAS_WCHAR)
    TString(const wchar_t* s)      : S(TUString::Create(s)) {}
#endif
//!CQ no non-const? UString always assumes [W]Const union member
    TString(BSTR s, bool loan)     : S(TUString::Create(s, loan)) {}
    TString(const string& s)       : S(TUString::Create(s)) {}
    TString(TUString* s)           : S(s) {}
    TString(const TString& src)    : S(src.S) {++*S;}

   ~TString() {--*S;}

    int Length() const {return S->Length();}
    bool IsNull() const {return S->IsNull();}

    TString& operator =(const TString& s)  {S = S->Assign(*s.S); return *this;}
    TString& operator =(const string& s)   {S = S->Assign(s); return *this;}
    TString& operator =(const char far* s) {S = S->Assign(s); return *this;}
    TString& operator =(char* s)           {S = S->Assign(s); return *this;}
#if defined(BI_HAS_WCHAR)
    TString& operator =(const wchar_t* s)  {S = S->Assign(s); return *this;}
    TString& operator =(wchar_t* s)        {S = S->Assign(s); return *this;}
#endif

    operator const char far*() const {return S->operator const char far*();}
    operator char*()           {return S->operator char*();}
#if defined(BI_HAS_WCHAR)
    operator const wchar_t*() const  {return S->operator const wchar_t*();}
    operator wchar_t*()        {return S->operator wchar_t*();}
#endif

    TLangId GetLangId() {return S->Lang;}
    void    SetLangId(TLangId id) {S->Lang = id;}

  protected:
    TUString* S;
};

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
// Inlines

inline TUString& TUString::operator ++()
{
  ++RefCnt;
  return *this;
}

inline TUString& TUString::operator --()
{
  if (--RefCnt != 0)
    return *this;
  delete this;
  return Null;
}

inline bool TUString::IsNull() const
{
  return Kind == isNull;
}

#endif  // OSL_USTRING_H
