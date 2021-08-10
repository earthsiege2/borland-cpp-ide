// SYSCLASS.H: Definitions of Pascal types
// Copyright (c) 1997, 1999 Borland International

#if !defined(SYSCLASS_H)
#define SYSCLASS_H

#if !defined(SystemHPP)
#error Do not include this file directly.  Include 'system.hpp'.
#endif

#if !defined(SYSMAC_H)
#include <sysmac.h>
#endif

// VCL_IOSTREAM: This macro enables the i/ostream insertion/extraction operators of VCL
//               classes. The operators are otherwise hidden to cut down on the amount
//               of lines (i.e. symbols) that must be compiled. (The redefinition of
//               i/ostream as templates in the Standard Library made these headers
//               fairly significant).
//
// If <iostream.h> has already been included, then expose the VCL insertion/extraction operators.
//
#if defined(__STD_IOSTREAM__)
#define VCL_IOSTREAM
using namespace std;
#elif defined(VCL_IOSTREAM) && !defined(__STD_IOSTREAM__)
#include <iostream.h>
#endif

#if !defined(DSTRING_H)
#include <dstring.h>
#endif
#if !defined(WSTRING_H)
#include <wstring.h>
#endif

#if !defined(SYSTOBJ_H)
#include <systobj.h>
#endif

#if !defined(SYSTDATE_H)
#include <systdate.h>
#endif

#if !defined(SYSCURR_H)
#include <syscurr.h>
#endif

#if !defined(SYSCOMP_H)
#include <syscomp.h>
#endif

#if !defined(SYSSET_H)
#include <sysset.h>
#endif

#if !defined(SYSMAC_H)
#include <sysmac.h>
#endif

#if !defined(SYSTVAR_H)
#include <systvar.h>
#endif

#if !defined(SYSDYN_H)
#include <sysdyn.h>
#endif

#if !defined(SYSOPEN_H)
#include <sysopen.h>
#endif

#if !defined(SYSTOBJ_H)
#include <systobj.h>
#endif

#if !defined(SYSVARI_H)
#include <sysvari.h>
#endif

#pragma option push -w-inl -w-lvc

namespace System
{
  class PACKAGE TVarArrayBound
  {
  public:
    Integer ElementCount;
    Integer LowBound;
  };

  class PACKAGE TVarArray
  {
  public:
    Word DimCount;
    Word Flags;
    Integer ElementSize;
    Integer LockCount;
    Pointer Data;
    TVarArrayBound Bounds[256] /* [0..255] */;
  };

  typedef class TMemoryManager *PMemoryManager;

  class PACKAGE TMemoryManager
  {
  public:
    Pointer __fastcall (*GetMem)(Integer Size);
    Integer __fastcall (*FreeMem)(Pointer P);
    Pointer __fastcall (*ReallocMem)(Pointer P, Integer Size);
  } ;

  class PACKAGE THeapStatus
  {
  public:
    Cardinal TotalAddrSpace;
    Cardinal TotalUncommitted;
    Cardinal TotalCommitted;
    Cardinal TotalAllocated;
    Cardinal TotalFree;
    Cardinal FreeSmall;
    Cardinal FreeBig;
    Cardinal Unused;
    Cardinal Overhead;
    Cardinal HeapErrorCode;
  } ;

    typedef Integer __fastcall (*TThreadFunc)(Pointer Parameter);

    // Inspector Query
    struct THeapBlock
    {
        void         *Start;
        unsigned int Size;
    };
    // Inspector Query

#ifdef BCBVER1
  #define USEDATAMODULE(FileName, DataModuleName)  \
    class DELPHICLASS T##DataModuleName;       \
    extern T##DataModuleName *DataModuleName;
#else
  #define USEDATAMODULE(FileName, DataModuleName)  \
    class DELPHICLASS T##DataModuleName;       \
    extern PACKAGE T##DataModuleName *DataModuleName;
#endif

#ifdef BCBVER1
  #define USEDATAMODULENS(FileName, UnitName, DataModuleName)  \
    namespace UnitName {         \
    class DELPHICLASS T##DataModuleName;       \
    extern T##DataModuleName *DataModuleName;              \
   };               \
   using namespace UnitName
#else
  #define USEDATAMODULENS(FileName, UnitName, DataModuleName)  \
    namespace UnitName {         \
    class DELPHICLASS T##DataModuleName;       \
    extern PACKAGE T##DataModuleName *DataModuleName;              \
    };               \
    using namespace UnitName
#endif

#ifdef BCBVER1
  #define USEFORM(FileName, FormName) \
    class DELPHICLASS T##FormName;       \
    extern T##FormName *FormName;
#else
  #define USEFORM(FileName, FormName) \
    class DELPHICLASS T##FormName;       \
    extern PACKAGE T##FormName *FormName;
#endif

#define USEFORMRES(FileName, FormName, AncestorName) \
   extern PACKAGE DummyThatIsNeverReferenced

#ifdef BCBVER1
  #define USEFORMNS(FileName, UnitName, FormName) \
    namespace UnitName {         \
    class DELPHICLASS T##FormName;       \
    extern T##FormName *FormName;          \
    };               \
    using namespace UnitName
#else
  #define USEFORMNS(FileName, UnitName, FormName) \
    namespace UnitName {         \
    class DELPHICLASS T##FormName;       \
    extern PACKAGE T##FormName *FormName;          \
    };               \
    using namespace UnitName
#endif

#define USEUNIT(ModName) \
   extern PACKAGE DummyThatIsNeverReferenced

#define USEOBJ(FileName) \
   extern PACKAGE DummyThatIsNeverReferenced

#define USERC(FileName) \
   extern PACKAGE DummyThatIsNeverReferenced

#define USEASM(FileName) \
   extern PACKAGE DummyThatIsNeverReferenced

#define USEDEF(FileName) \
   extern PACKAGE DummyThatIsNeverReferenced

#define USERES(FileName) \
   extern PACKAGE DummyThatIsNeverReferenced

#define USETLB(FileName) \
   extern PACKAGE DummyThatIsNeverReferenced

#define USELIB(FileName) \
   extern PACKAGE DummyThatIsNeverReferenced

#define USEFILE(FileName) \
   extern PACKAGE DummyThatIsNeverReferenced

#define USEPACKAGE(FileName) \
   extern PACKAGE DummyThatIsNeverReferenced

#define USEIDL(FileName) \
   extern PACKAGE DummyThatIsNeverReferenced

#define USE(FileName, ContainerId) \
   extern PACKAGE DummyThatIsNeverReferenced

  struct PACKAGE ResourceString
  {
    HINSTANCE       *hinstance;
    unsigned long   id;                     // resource string id
  };

  struct PACKAGE TModuleUnloadRec
  {
    TModuleUnloadRec    *next;
    TModuleUnloadProc   *proc;
  };
  typedef TModuleUnloadRec *PModuleUnloadRec;

  struct PACKAGE TLibModule
  {
    TLibModule  *next;
    long        instance;
    long        codeinstance;
    long        datainstance;   
    long        resinstance;
    long        reserved;
  };

  struct PACKAGE TResStringRec
  {
    long        *module;
    long        ident;
  };
  typedef TResStringRec *PResStringRec;

  // always get statically from vcleXX.lib
  extern AnsiString __fastcall LoadResourceString(ResourceString const * const rsrc);

  // always get statically from vcleXX.lib
  extern void __fastcall CheckSafecallResult(HRESULT hr);

  // always get statically from vcleXX.lib
  extern void * __fastcall FindDynaInst(void * vmt, int ID);

} // namespace System
using namespace System;

#if 0
namespace Typinfo
{
  struct  TTypeInfo;
  typedef TTypeInfo *PTypeInfo;
}

namespace Controls
{
  typedef System::TDateTime TDate;
  typedef System::TDateTime TTime;
}
#endif

// Define VCL_IOSTREAM operators
//
#if defined(VCL_IOSTREAM)

namespace System
{
  inline void read_to_delim(istream& strm, char delim, AnsiString& str)
  {
    char ch;
    int nchars = 0;
    char array[4096];
    int capacity = sizeof array;

    while ( 1 )
    {

      // Read as many characters as we can, up to the delimiter:
      strm.get( array+nchars, capacity-nchars+1, delim );

      // This is the new string length:
      nchars += strlen( array+nchars );

      // What stopped us?  An EOF?
      if ( !strm.good() )
        break;      // EOF encountered (or worse!)

      // Nope.  Was it the delimiter?
      strm.get(ch);
      if (ch==delim)
        break;  // Yup. We're done.  Don't put it back on the stream.
      else
        strm.putback(ch); // Nope, Put it back and keep going.

    }
    str = array;
  }

  inline istream& operator >> (istream& is, AnsiString& arg)
  {
    read_to_delim(is, 0, arg);
    return is;
  }

  inline ostream& operator << (ostream& os, const AnsiString& arg)
  {
    return os << arg.c_str();
  }

  template <unsigned char sz>
  inline ostream& operator << (ostream& os, const SmallString<sz>& arg)
  {
    os << AnsiString(arg).c_str();
    return os;
  }

  template <unsigned char sz>
  inline istream& operator >> (istream& is, SmallString<sz>& arg)
  {
    AnsiString s;
    is >> s;
    arg = s;
    return is;
  }


  // Currency IOStream operators
  //
  inline ostream& operator << (ostream& os, const Currency& arg)
  {
    os << AnsiString(arg);
    return os;
  }

  inline istream& operator >> (istream& is, Currency& arg)
  {
    AnsiString s;
    is >> s;
    arg = s;
    return is;
  }


  // TDateTime IOStream operators
  //
  inline ostream& operator << (ostream& os, const TDateTime& arg)
  {
    os << AnsiString(arg);
    return os;
  }

  inline istream& operator >> (istream& is, TDateTime& arg)
  {
    AnsiString s;
    is >> s;
    arg = s;
    return is;
  }


  // Variant IOStream operators
  //
  inline ostream& operator <<(ostream& os, const Variant& arg)
  {
    switch (arg.VType)
    {
    case varEmpty:
      os << "varEmpty";
      break;
    case varNull:
      os << "varNull";
      break;
    case varSmallint:
      os << "varSmallint: " << arg.VSmallint;
      break;
    case varInteger:
      os << "varInteger: " << arg.VInteger;
      break;
    case varSingle:
      os << "varSingle: " << arg.VSingle;
      break;
    case varDouble:
      os << "varDouble: " << arg.VDouble;
      break;
    case varCurrency:
      os << "varCurrency: " << arg.VCurrency;
      break;
    case varDate:
      os << "varDate: " << arg.VDate;
      break;
    case varOleStr:
      os << "varOleStr: " << AnsiString(arg.VOleStr);
      break;
    case varDispatch:
      // workaround compiler bug: can't use static_cast with incomplete type
      os << "varDispatch: " << (void*)arg.VDispatch;
      break;
    case varError:
      os << "varError: " << arg.VError;
      break;
    case varBoolean:
      os << "varBoolean: " << arg.operator bool();
      break;
    case varUnknown:
      // workaround compiler bug: can't use static_cast with incomplete type
      os << "varUnknown: " << (void*)arg.VUnknown;
      break;
    case varByte:
      os << "varByte: " << arg.VByte;
      break;
    case varString:
      os << "varString: " << arg.operator AnsiString();
      break;
    case varArray:
      os << "varArray: " << static_cast<void*>(arg.VArray);
      break;
    case varSmallint | varByRef:
      os << "varSmallint | varByRef: " << arg.VPointer;
      break;
    case varInteger | varByRef:
      os << "varInteger | varByRef: " << arg.VPointer;
      break;
    case varSingle | varByRef:
      os << "varSingle | varByRef: " << arg.VPointer;
      break;
    case varDouble | varByRef:
      os << "varDouble | varByRef: " << arg.VPointer;
      break;
    case varCurrency | varByRef:
      os << "varCurrency | varByRef: " << arg.VPointer;
      break;
    case varDate | varByRef:
      os << "varDate | varByRef: " << arg.VPointer;
      break;
    case varOleStr | varByRef:
      os << "varOleStr | varByRef: " << arg.VPointer;
      break;
    case varDispatch | varByRef:
      os << "varDispatch | varByRef: " << arg.VPointer;
      break;
    case varError | varByRef:
      os << "varError | varByRef: " << arg.VPointer;
      break;
    case varBoolean | varByRef:
      os << "varBoolean | varByRef: " << arg.VPointer;
      break;
    case varUnknown | varByRef:
      os << "varUnknown | varByRef: " << arg.VPointer;
      break;
    case varByte | varByRef:
      os << "varByte | varByRef: " << arg.VPointer;
      break;
    case varString | varByRef:
      os << "varString | varByRef: " << arg.VPointer;
      break;
    case varArray | varByRef:
      os << "varArray | varByRef: " << arg.VPointer;
      break;
    }
    return os;
  }
}       // namespace System
#endif  // VCL_IOSTREAM


#pragma option pop

// Undo the MACROs which mapped the Automation related types to their tagStruct.
//
#if defined(CURRENCY)
#undef CURRENCY
#endif
#if defined(SAFEARRAY)
#undef SAFEARRAY
#endif
#if defined(VARIANT)
#undef  VARIANT
#endif

#endif

