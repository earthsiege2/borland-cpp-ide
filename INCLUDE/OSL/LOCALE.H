//----------------------------------------------------------------------------
// ObjectSupport
// (C) Copyright 1994 by Borland International, All Rights Reserved
//
//  TLocaleString - localized name support
//  TRegItem, TRegList - associative array of localizable string parameters
//----------------------------------------------------------------------------
#if !defined(OSL_LOCALE_H)
#define OSL_LOCALE_H

#if !defined(OSL_DEFS_H)
# include <osl/defs.h>
#endif
#if !defined(BI_PLAT_MSW)
# error Locale classes are only supported under MSW
#endif
#if !defined(__COMMDLG_H)
# include <commdlg.h>   // only for OFN_xxx defines
#endif
#if !defined(__CSTRING_H)
# include <cstring.h>
#endif

#define DEFAULT_SYSTEM_LANGID 0x409   // in case 16-bit with no NLS support
typedef unsigned short TLangId;       // language ID - same as NT LANGID
typedef int (*TstricmpLang)(const char far*, const char far*, TLangId);
const TLangId LangSysDefault  = 0x0800;
const TLangId LangUserDefault = 0x0400;
const TLangId LangNeutral     = 0x0000;

//----------------------------------------------------------------------------
// TLocaleString - localizable substitute for char*
//

struct TLocaleString {
  const char* Translate(TLangId lang);                      // translate string
  operator const char*();      // return current string
  void operator =(const char* str) { Private = str; }
  int   Compare(const char far* str, TLangId lang);   // insensitive compare

  const char* Private;         // string pointer used for initialization

  static TLangId GetSystemLangId();  // platform-dependent implementation
  static TLangId GetUserLangId();    // platform-dependent implementation
  static int     IsNativeLangId(TLangId lang);  // returns bool true if native
  static TLangId SystemDefaultLangId;// must define and set to system language
  static TLangId UserDefaultLangId;  // same as system language if single user
  static TLangId NativeLangId;   // must define and set to lang. of literals
  static HINSTANCE Module;       // must define and set to resource module
  static TLocaleString Null;     // reference a null string
  static int CompareLang(const char far* s1, const char far* s2, TLangId);
          // CompareLang() may be implemented in another module for NLS support
};

//
// Prefix characters for locale strings
//
#define AUTOLANG_RCID  '#' // indicates name specified by numeric ID
#define AUTOLANG_XLAT  '!' // indicates name to be localized (binary)
#define AUTOLANG_LOAD  '@' // indicates resource name to load (binary)

//
// custom resource for translations
//
#define RT_LOCALIZATION MAKEINTRESOURCE(201)

//----------------------------------------------------------------------------
// Registration parameter table macro definitions
//

#define BEGIN_REGISTRATION(regname) extern  TRegItem regname##_list[]; \
                                    TRegList regname(regname##_list); \
                                    static  TRegItem regname##_list[] = {
#define END_REGISTRATION {0,{0}} };

#define REGDATA(var,val) {#var, {val}}, 
#define REGXLAT(var,val) {#var, {AUTOPREF_XLAT val}}, 
#define REGITEM(key,val) {" " key, {val}}, 
#define REGFORMAT(i,f,a,t,d) {"format" #i,{TRegItem::RegFormat(f,a,t,d,TRegItem::Heap)}},
#define REGSTATUS(a,f) {"aspect" #a, {TRegItem::RegFlags(f,TRegItem::Heap)}},
#define REGVERBOPT(v,mf,sf) {#v "opt",{TRegItem::RegVerbOpt(mf,sf,TRegItem::Heap)}},
#define REGICON(i) {"iconindex",{TRegItem::RegFlags(i,TRegItem::Heap)}},
#define REGDOCFLAGS(i) {"docflags",{TRegItem::RegFlags(i,TRegItem::Heap)}},

#define REGISTRATION_FORMAT_BUFFER(n) \
  char OCRegFormatBuffer[n]; \
  TRegFormatHeap TRegItem::Heap = {n, 0, OCRegFormatBuffer};

//----------------------------------------------------------------------------
// Registration parameter structures and formatting functions
//

//
// Used internally to format registration strings
//
struct TRegFormatHeap {
  int   Size;
  int   Used;
  char* Data;
};

//
// A single reglist entry
//
struct TRegItem {
  char*         Key;           // non-localized parameter or registry subkey
  TLocaleString Value;         // localizable value for parameter or subkey

  // used privately by REGFORMAT, REGSTATUS macros
  //
  static TRegFormatHeap Heap;   // string buffer defined in instance memory
  static char* RegFormat(int   f, int a, int t, int d, TRegFormatHeap& heap);
  static char* RegFormat(const char* f, int a, int t, int d, TRegFormatHeap& heap);
  static char* RegFlags(long flags, TRegFormatHeap& heap);
  static char* RegVerbOpt(int mf, int sf, TRegFormatHeap& heap);
};

//
// A registration parameter table, composed of a list of TRegItems 
//
class TRegList {
  public:
    TRegList(TRegItem* list) : Items(list) {}    
    const char* Lookup(const char* key,
                       TLangId lang = TLocaleString::UserDefaultLangId);
    TLocaleString& LookupRef(const char* key);
    const char* operator[](const char* key) {return Lookup(key);}

    TRegItem* Items;
};

//
// Registration link node, holding a pointer to a TRegList
//
class _BIDSCLASS TRegLink {
  public:
    TRegLink(TRegList& regList, TRegLink*& head);
   ~TRegLink() {}
    TRegLink*   GetNext() const {return Next;}
    TRegList&   GetRegList() const {return *RegList;}

    static void AddLink(TRegLink*& head, TRegLink& newLink);
    static bool RemoveLink(TRegLink*& head, TRegLink& remLink);

  protected:
    TRegLink() : Next(0), RegList(0) {} // Derived class must fill in ptrs
    TRegLink*  Next;      // Next RegLink
    TRegList*  RegList;   // Pointer to registration parameter table
};

#endif  // OSL_LOCALE_H
