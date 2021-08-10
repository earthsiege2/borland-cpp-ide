// SYSMAC.H: Generic macros and forward type definitions of Pascal types
// Copyright (c) 1997, 1999 Borland International

#if !defined(SYSMAC_H)
#define SYSMAC_H

#if !defined(SystemHPP)
#error Do not include this file directly.  Include 'system.hpp'.
#endif

#if !defined(__RTL_BUILD__)
#pragma comment(lib, "vcle50.lib")
#endif

#if __BORLANDC__ < 0x500
#error BCW 5.0 or greater required
#endif

// !! This is on now (Oops!)
#pragma anon_struct on      // support anonymous structs (within unions)

// Bring in Interface definitions - Supply what may be missing in LEAN_AND_MEAN mode
//
#if !defined(BEGIN_INTERFACE)       // If OBJBASE.H has not been seen yet!
#define BEGIN_INTERFACE
#endif
#if !defined(END_INTERFACE)         // If OBJBASE.H has not been seen yet!
#define END_INTERFACE
#endif
#if !defined(WINOLEAPI)             // If OBJBASE.H has not been seen yet!
#define WINOLEAPI        EXTERN_C DECLSPEC_IMPORT HRESULT STDAPICALLTYPE
#endif
#if !defined(HUGEP)                 // If OBJBASE.H has not been seen yet!
#define HUGEP
#endif

#include <windows.h>

// begin <windows.h> fixups

// Some macros defined in <windows.h> clash with names used elsewhere in
// VCL.  If this list grows, consider moving to another header file.

#if defined(UNICODE)
#define _MAP_WINNAME(n) n ## W
#else
#define _MAP_WINNAME(n) n ## A
#endif // UNICODE || _UNICODE

extern "C" {
#pragma option push -vi // force inlining on

#undef GetDiskFreeSpaceEx
inline BOOL WINAPI
GetDiskFreeSpaceEx(LPCTSTR lpDirectoryName,
                   PULARGE_INTEGER lpFreeBytesAvailableToCaller,
                   PULARGE_INTEGER lpTotalNumberOfBytes,
                   PULARGE_INTEGER lpTotalNumberOfFreeBytes)
{
  return _MAP_WINNAME(GetDiskFreeSpaceEx)(lpDirectoryName,
                                          lpFreeBytesAvailableToCaller,
                                          lpTotalNumberOfBytes,
                                          lpTotalNumberOfFreeBytes);
}

#include <winspool.h> // this is fortunately fairly small
#undef SetPort
inline BOOL WINAPI
SetPort(LPTSTR pName, LPTSTR pPortName, DWORD dwLevel, LPBYTE pPortInfo)
{
  return _MAP_WINNAME(SetPort)(pName, pPortName, dwLevel, pPortInfo);
}
        
#pragma option pop // -vi
} // extern "C"

#undef _MAP_WINNAME
// end <windows.h> fixups

#if !defined(_BASETYPS_H_)
#include <basetyps.h>
#endif

#define _ARRAYOF								// Used as a special token to tell the IDE when a
												// event handler contains an open array

#define __safecall __stdcall
#define __interface class
#define __dispinterface class

#define PACKAGE              __declspec(package)                 // Implemented in a package
#define PASCALIMPLEMENTATION __declspec(pascalimplementation, package) // Implemented in Delphi - no code should be generated
#define DELPHIRETURN         __declspec(delphireturn, package)  // Uses Delphi's return semantic; resides in a package
#define DELPHICLASS          __declspec(delphiclass, package)   // Implemented in Delphi (C++ does not generate RTTI)
#define DYNAMIC              __declspec(dynamic)                // For compatibility with Delphi's old virtual mechanism

#if (__BORLANDC__ >= 0x0550)
#define INTERFACE_UUID(guid) __declspec(uuid(guid))             // For associating a GUID with a type
#else
#define INTERFACE_UUID(guid)
#endif

// Macros specifically for C++ emulation of Delphi language features
// Used for RTL functionality which should not be packaged.
//
#define RTL_DELPHIRETURN     __declspec(delphireturn)           // Uses Delphi's return semantic (not in package)
#define RTL_DELPHICLASS      __declspec(delphiclass)            // Implemented in Delphi

#define HIDESBASEDYNAMIC     __declspec(hidesbase, dynamic)     // For compatibility with Delphi
#define HIDESBASE            __declspec(hidesbase)              // For compatibility with Delphi

#if !defined(MESSAGE)
#define MESSAGE
#endif

#if !defined(__typeinfo)
#define __typeinfo(type)  (PTypeInfo)TObject::ClassInfo(__classid(type))
#endif

#define BEGIN_MESSAGE_MAP   virtual void __fastcall Dispatch(void *Message) \
        {                                           \
          switch  (((PMessage)Message)->Msg)        \
          {

#define VCL_MESSAGE_HANDLER(msg,type,meth)          \
          case    msg:                              \
            meth(*((type *)Message));               \
            break;

// NOTE: ATL defines a MESSAGE_HANDLER macro which conflicts with VCL's macro. The
//       VCL macro has been renamed to VCL_MESSAGE_HANDLER. If you are not using ATL,
//       MESSAGE_HANDLER is defined as in previous versions of BCB.
//
#if !defined(USING_ATL) && !defined(USING_ATLVCL) && !defined(INC_ATL_HEADERS)
#define MESSAGE_HANDLER  VCL_MESSAGE_HANDLER
#endif // ATL_COMPAT

#define END_MESSAGE_MAP(base)           default:    \
                        base::Dispatch(Message);    \
                        break;                      \
          }                                         \
        }


namespace System
{
    class DELPHICLASS TObject;
    class PACKAGE TMetaClass;
    typedef TMetaClass* TClass;
    template <class T> class RTL_DELPHIRETURN DelphiInterface;
    class DELPHICLASS TInterfacedObject;

    class RTL_DELPHIRETURN AnsiString;
    class RTL_DELPHIRETURN WideString;

    template <unsigned char sz> class SmallStringBase;
    template <unsigned char sz> class SmallString;

    class RTL_DELPHIRETURN CurrencyBase;
    class RTL_DELPHIRETURN Currency;

    class RTL_DELPHIRETURN OleVariant;
    class RTL_DELPHIRETURN Variant;

    struct PACKAGE TLibModule;
    struct PACKAGE TModuleUnloadRec;

    class PACKAGE THeapStatus;
    class PACKAGE TMemoryManager;

    // Inspector Query
    struct THeapBlock;

    template<class T> class RTL_DELPHIRETURN DynamicArray;

    typedef DynamicArray<THeapBlock> THeapBlockArray;
    typedef DynamicArray<System::TObject *> TObjectArray;

    // Inspector Query

    typedef class TMemoryManager *PMemoryManager;

    class RTL_DELPHIRETURN TDateTimeBase;
    class RTL_DELPHIRETURN TDateTime;

    struct        CompBase;
    struct        Comp;

    struct PACKAGE TLibModule;
    typedef TLibModule *PLibModule;

    struct PACKAGE TResStringRec;
    typedef TResStringRec *PResStringRec;

    template<class T, unsigned char minEl, unsigned char maxEl> class RTL_DELPHIRETURN SetBase;
    template<class T, unsigned char minEl, unsigned char maxEl> class RTL_DELPHIRETURN Set;

    class PACKAGE TVarArrayBound;
    class PACKAGE TVarArray;
    typedef TVarArray *PVarArray;

    typedef bool                 Boolean;          //
    typedef int                  Integer;          // -2147483648..2147484647
    typedef char                 Char;             // 0..255
    typedef wchar_t              WideChar;         // Unicode character
    typedef signed char          Shortint;         // -128..127
    typedef short                Smallint;         // -32768..32767
    typedef unsigned char        Byte;             // 0..255
    typedef unsigned short       Word;             // 0..65535
    typedef unsigned long        DWord;            // 0..4294967295
    typedef void*                Pointer;          //
    typedef char                 AnsiChar;         //
    typedef signed long          Longint;          // -2147483648..2147484647
    typedef unsigned int         Cardinal;         // 0..2147484647
    typedef long double          Extended;         // 10 byte real
    typedef float                Single;           // 4 byte real
    typedef double               Double;           // 8 byte real
    typedef char* const          Openstring;       // D16 string/D32 shortstring formalparm
    typedef void*                file;             //
    typedef void*                Text;             //
    typedef Text                 TextFile;         //
    typedef char*                PChar;            //
    typedef char*                PAnsiChar;        //
    typedef wchar_t*             PWideChar;        //
    typedef unsigned char        ByteBool;         //
    typedef unsigned short       WordBool;         //
    typedef Cardinal             LongBool;         //
    typedef AnsiString           String;           //
    typedef SmallStringBase<255> ShortStringBase;  //
    typedef SmallString<255>     ShortString;      //
    typedef ShortString*         PShortString;     //
    typedef AnsiString*          PAnsiString;      //
    typedef PAnsiString          PString;          //
    typedef WideString*          PWideString;      //
    typedef Extended*            PExtended;        //
    typedef Currency*            PCurrency;        //
    typedef Variant*             PVariant;         //
    typedef OleVariant*          POleVariant;      //    
    typedef __int64              LONG64;           // !! obsolete
    typedef GUID                 TGUID;            //
    typedef TGUID*               PGUID;            //
    typedef HRESULT              HResult;          //

    typedef Integer __fastcall (*TThreadFunc)(Pointer Parameter);
    typedef void (*TModuleUnloadProc)(HINSTANCE hinstance);
    typedef bool (*TEnumModuleFunc)(HINSTANCE hinstance, void *data);
    typedef void (*TModuleUnloadProcLW)(HINSTANCE hinstance);
    typedef bool (*TEnumModuleFuncLW)(HINSTANCE hinstance, void *data);

    typedef struct TVarData *PVarData;
}

extern "C" __int64 _roundToInt64(long double);
#endif
