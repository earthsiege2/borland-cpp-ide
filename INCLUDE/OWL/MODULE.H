//----------------------------------------------------------------------------
// ObjectWindows
// Copyright (c) 1991, 1997 by Borland International, All Rights Reserved
//
//$Revision:   10.26  $
//
// Definition of class TModule.  TModule defines the basic behavior for OWL
// libraries and applications.
//----------------------------------------------------------------------------
#if !defined(OWL_MODULE_H)
#define OWL_MODULE_H

#if !defined(OWL_DEFS_H)
# include <owl/defs.h>
#endif
#if !defined(CLASSLIB_OBJSTRM_H)
# include <classlib/objstrm.h>
#endif
#if !defined(OWL_EXCEPT_H)
# include <owl/except.h>
#endif
#if !defined(CLASSLIB_POINTER_H)
# include <classlib/pointer.h>
#endif

#if defined(BI_NAMESPACE)
namespace OWL {
#endif

// Generic definitions/compiler options (eg. alignment) preceeding the
// definition of classes
#include <services/preclass.h>

// TModuleVersionInfo needs FILETIME defined, which may not be seen for
// 16-bit apps - It is defined in COMPOBJ.H
//
#if defined(BI_PLAT_WIN16)
# if !defined(_FILETIME_)
    struct far tagFILETIME {uint32 dwLowDateTime; uint32 dwHighDateTime;};
    typedef tagFILETIME FILETIME;
#   define _FILETIME_
# endif
#endif

// These DLL name strings are used in INITDLL.CPP and MODULE.CPP
// for locking DLLs in memory
//
#if defined(_OWLDLL) && !defined(BI_PLAT_WIN32)
# if !defined(BIDS_DLLNAME)
#   if defined(__TRACE) || defined(__WARN)
#     define BIDS_DLLNAME "BDS52D"
#   else
#     define BIDS_DLLNAME "BDS52"
#   endif
# endif
# if !defined(OWL_DLLNAME)
#   if defined(__TRACE) || defined(__WARN)
#     define OWL_DLLNAME "OWL52D"
#   else
#     define OWL_DLLNAME "OWL52"
#   endif
# endif
#endif

class _OWLCLASS TWindow;
class _OWLCLASS TDialog;
class _OWLCLASS_RTL TXInvalidModule;

//
// class TModule
// ~~~~~ ~~~~~~~
class _OWLCLASS TModule : public TStreamableBase {
  public:
    // Class scoped types
    //
    typedef HINSTANCE THandle;  // TModule encapsulates an HINSTANCE

    // Constructors & destructor
    //
    TModule(const char far* name, bool shouldLoad = true, bool mustLoad = true);
    TModule(const char far* name, THandle handle);
    TModule(const char far* name, THandle handle, const char far* cmdLine);
    virtual ~TModule();

    // Finish-up initialization of a module
    //
    void          InitModule(THandle handle, const char far* cmdLine);

    // Get & set members. Use these instead of directly accessing members
    //
    const char far* GetName() const;
    void          SetName(const char far* name);

    THandle       GetHandle() const;      // Get the module instance handle
    operator      THandle() const;
    bool operator ==(const TModule& m) const;
    bool          IsLoaded() const;

    // Module wide error handler. Called when fatal exceptions are caught.
    //
    virtual int   Error(xmsg& x, uint captionResId, uint promptResId=0);

    // Windows HINSTANCE/HMODULE related API functions encapsulated
    //
    int           GetModuleFileName(char far* buff, int maxChars);

    FARPROC       GetProcAddress(const char far* fcnName) const;

#if defined(BI_PLAT_WIN16)
    int           GetModuleUsage() const;
    int           GetInstanceData(void NEAR* data, int len) const;
#endif

    HRSRC         FindResource(TResId id, const char far* type) const;
    HGLOBAL       LoadResource(HRSRC hRsrc) const;
    uint32        SizeofResource(HRSRC hRsrc) const;

#if defined(BI_PLAT_WIN16)
    int           AccessResource(HRSRC hRsrc) const;
    HGLOBAL       AllocResource(HRSRC hRsrc, uint32 size) const;
    RSRCHDLRPROC  SetResourceHandler(const char far* type, RSRCHDLRPROC loadProc) const;
#endif

    int           LoadString(uint id, char far* buf, int maxChars) const;
    string        LoadString(uint id) const;
    HBITMAP       LoadBitmap(TResId id) const;
    bool          GetClassInfo(const char far* name, WNDCLASS far* wndclass) const;
    HACCEL        LoadAccelerators(TResId id) const;
    HMENU         LoadMenu(TResId id) const;
    HCURSOR       LoadCursor(TResId id) const;
    HICON         LoadIcon(const char far* name) const;

#if defined(BI_PLAT_WIN16)
    HCURSOR       CopyCursor(HCURSOR hCursor) const;
#endif

    HICON         CopyIcon(HICON hIcon) const;

  protected:
    void          SetHandle(THandle handle);  // Set the module instance handle

  protected_data:
    char*         Name;       // Name of the module
    union {
#if defined(OWL2_COMPAT)
      THandle     HInstance;  // Old 2.x name
#endif
      THandle     Handle;     // New name
    };

  private:
    bool          ShouldFree; // Should free the module when done?

    // Hidden to prevent accidental copying or assignment
    //
    TModule(const TModule&);
    TModule& operator =(const TModule&);

#if defined(OWL2_COMPAT)
  // Obsolete members for Owl 2.x compatibility
  //
  public:
    THandle       GetInstance() const;
    void          SetInstance(THandle handle);
    typedef ::TXInvalidModule TXInvalidModule;  // Exceptions moved to global scope
#endif
#if defined(OWL1_COMPAT)
  // Obsolete members for Owl 1 compatibility
  //
  public:
    char far* lpCmdLine;    // Use argv & argc for portability
    TStatus   Status;       // Use exceptions

    TWindow*  ValidWindow(TWindow* win);
    TWindow*  MakeWindow(TWindow* win);
    int       ExecDialog(TDialog* dialog);

    virtual void  Error(int errorCode);

    HWND      GetClientHandle(HWND hWnd);
    TWindow*  GetParentObject(HWND hWndParent);

    bool      LowMemory();
    void      RestoreMemory();
#endif

  friend ostream& _OWLFUNC operator <<(ostream& os, const TModule& m);
  DECLARE_STREAMABLE(_OWLCLASS, TModule, 1);
};

//
// Bring in the system's version info header if not already included
//
#if defined(BI_PLAT_WIN16) && !defined(VS_FILE_INFO)
# include <ver.h>  // struct VS_FIXEDFILEINFO;
#endif

//
// class TModuleVersionInfo
// ~~~~~ ~~~~~~~~~~~~~~~~~~
// Access to a TModule's VERSIONINFO resource.
//
class _OWLCLASS TModuleVersionInfo {
  public:
    // TFileOS values are returned by GetFileOS()
    enum TFileOS { OSUnknown    = VOS_UNKNOWN,
                   DOS          = VOS_DOS,
                   OS216        = VOS_OS216,
                   OS232        = VOS_OS232,
                   NT           = VOS_NT,
                   Windows16    = VOS__WINDOWS16,
                   PM16         = VOS__PM16,
                   PM32         = VOS__PM32,
                   Windows32    = VOS__WINDOWS32,
                   DosWindows16 = VOS_DOS_WINDOWS16,
                   DosWindows32 = VOS_DOS_WINDOWS32,
                   OS216PM16    = VOS_OS216_PM16,
                   OS232PM32    = VOS_OS232_PM32,
                   NTWindows32  = VOS_NT_WINDOWS32
    };
    // TFileType is returned by GetFileType()
    enum TFileType { TypeUnknown = VFT_UNKNOWN,
                     App         = VFT_APP,
                     DLL         = VFT_DLL,
                     DevDriver   = VFT_DRV,
                     Font        = VFT_FONT,
                     VirtDevice  = VFT_VXD,
                     StaticLib   = VFT_STATIC_LIB
    };
    // TFileSubType values are returned by GetFileSubType() if GetFileType
    // returned DevDriver or Font
    enum TFileSubType { UnknownDevDriver,  //VFT2_UNKNOWN
                        PtrDriver,         //VFT2_DRV_PRINTER
                        KybdDriver,        //VFT2_DRV_KEYBOARD
                        LangDriver,        //VFT2_DRV_LANGUAGE
                        DisplayDriver,     //VFT2_DRV_DISPLAY
                        MouseDriver,       //VFT2_DRV_MOUSE
                        NtwkDriver,        //VFT2_DRV_NETWORK
                        SysDriver,         //VFT2_DRV_SYSTEM
                        InstallableDriver, //VFT2_DRV_INSTALLABLE
                        SoundDriver,       //VFT2_DRV_SOUND
                        UnknownFont,       //VFT2_UNKNOWN
                        RasterFont,        //VFT2_FONT_RASTER
                        VectorFont,        //VFT2_FONT_VECTOR
                        TrueTypeFont       //VFT2_FONT_TRUETYPE
    };
    TModuleVersionInfo(TModule::THandle module);
    TModuleVersionInfo(const char far* modFName);
   ~TModuleVersionInfo();

    VS_FIXEDFILEINFO far& GetFixedInfo();

    uint32    GetSignature() const;
    uint32    GetStrucVersion() const;
    uint32    GetFileVersionMS() const;
    uint32    GetFileVersionLS() const;
    uint32    GetProductVersionMS() const;
    uint32    GetProductVersionLS() const;
    bool      IsFileFlagSet(uint32 flag) const;
    uint32    GetFileFlagsMask() const;
    uint32    GetFileFlags() const;
    bool      IsDebug() const;
    bool      InfoInferred() const;
    bool      IsPatched() const;
    bool      IsPreRelease() const;
    bool      IsPrivateBuild() const;
    bool      IsSpecialBuild() const;
    uint32    GetFileOS() const;  // returns TFileOS values
    TFileType GetFileType() const;
    uint32    GetFileSubType() const;
    FILETIME  GetFileDate() const;

    bool GetInfoString(const char far* str, const char far*& value, uint lang=0);

    bool GetFileDescription(const char far*& fileDesc, uint lang=0);
    bool GetFileVersion(const char far*& fileVersion, uint lang=0);
    bool GetInternalName(const char far*& internalName, uint lang=0);
    bool GetLegalCopyright(const char far*& copyright, uint lang=0);
    bool GetOriginalFilename(const char far*& originalFilename, uint lang=0);
    bool GetProductName(const char far*& prodName, uint lang=0);
    bool GetProductVersion(const char far*& prodVersion, uint lang=0);
    bool GetSpecialBuild(const char far*& debug, uint lang=0);

    uint   GetLanguage() const;
    string GetLanguageName() const;

    static string GetLanguageName(uint language);

  protected:
    bool Init(const char far* modFName);

    void far*         Buff;           // new'd File version info buffer
    uint32            Lang;           // Default language translation
    VS_FIXEDFILEINFO far* FixedInfo;  // Fixed file info structure

  private:
    // Don't allow this object to be copied.
    //
    TModuleVersionInfo(const TModuleVersionInfo&);
    TModuleVersionInfo& operator =(const TModuleVersionInfo&);
};

//
// class TXInvalidModule
// ~~~~~ ~~~~~~~~~~~~~~~
class _OWLCLASS_RTL TXInvalidModule : public TXOwl {
  public:
    TXInvalidModule(const char far* name = 0);

#if defined(BI_NO_COVAR_RET)
    TXBase* Clone();
#else
    TXInvalidModule* Clone();
#endif
    void Throw();

    static void Raise(const char far* name = 0);
};

//
// class TErrorMode
// ~~~~~ ~~~~~~~~~~
// Simple encapsulation of the SetErrorMode call. Manages putting the error
// mode back to its previous state on destruction, thus is exception safe.
//
class TErrorMode {
  public:
    TErrorMode(uint mode);
   ~TErrorMode();

  private:
    uint PrevMode;
};

//----------------------------------------------------------------------------
// Global variable and functions

//
// Global pointer to the current module. One must be available in each linked
// DLL or EXE.
//
extern TModule* Module;

//
// Exported pointers from OWL modules, implemented in GLOBAL.CPP
// Unmanagled to allow easy loading via LoadLibrary
//
class _OWLCLASS TDocTemplate;
extern "C" {
  TDocTemplate** PASCAL GetDocTemplateHead(int version);
  TModule** PASCAL GetModulePtr(int version);
}

#if defined(BI_NAMESPACE)
} // namespace OWL
#endif

//
// Main entry point for an Owl application
//
int OwlMain(int argc, char* argv[]);


extern "C" {

//
// Initialization routine that must be called from User DLL if DLL
// provides it's own entry point [i.e. LibMain or DllEntryPoint]
//
bool OWLInitUserDLL(HINSTANCE hInstance, LPSTR cmdLine);
}


#if defined(BI_NAMESPACE)
namespace OWL {
#endif


//----------------------------------------------------------------------------
// Definition of TDllLoader template, and TModuleProc class & derived
// templates. TDllLoader<> provides an easy way to load one instance of a dll
// on demand.
// TModuleProcX<>s provide dynamic binding & call access to exported module
// procs
//

//
// class TDllLoader<>
// ~~~~~ ~~~~~~~~~~~~
template <class T> class TDllLoader {
  public:
    TDllLoader();
   ~TDllLoader();
    static bool IsAvailable();
    static T*   Dll();

#if 0

    static T*   Dll;
#endif
  private:
    static T*&  DllPtrRef();
};


#if 0

//
// One static pointer to the dll object, loaded on demand
//
template <class T> T* TDllLoader<T>::Dll = 0;
#endif

//
// Create a dynamic copy of the DLL object (i.e. an instance of T) if we
// do not have one already...
//
template <class T> TDllLoader<T>::TDllLoader()
{
  T*& dll = DllPtrRef();
  WARN(dll != 0, "Multiple copies of DllLoaders for DLL: " << *dll);
  if (dll == 0) {
    try {
      dll = new T;
    }
    catch (...) {
    }
  }
}

//
// Delete the dll object when we go away to release the dll from memory
//
template <class T> TDllLoader<T>::~TDllLoader()
{
#if 0
  delete Dll;
  Dll = 0;
#endif
  T*& dll = DllPtrRef();
  delete dll;
  dll = 0;
}

//
// Load the dll on demand, returning true if it was loaded OK
//
template <class T> bool TDllLoader<T>::IsAvailable()
{
  static TDllLoader<T> ThisLoader;
  return DllPtrRef() != 0;
}

//
//
//
template <class T> T* TDllLoader<T>::Dll()
{
  PRECONDITION(DllPtrRef() != 0);
  return DllPtrRef();
}

//
// Method encapsulating single instance of pointer to DLL objecct
//
template <class T> T*& TDllLoader<T>::DllPtrRef()
{
  static T* ThisDll = 0;
  return ThisDll;
}

//
// class TModuleProc
// ~~~~~ ~~~~~~~~~~~
// Base module proc class does inital binding. Throws an exception if it
// cannot bind
//
class _OWLCLASS TModuleProc {
  public:
    TModuleProc(const TModule& module, const char far* id);

  protected:
    FARPROC Proc;
};

//
// Derived template classes perform type-safe parameter passing on call.
// Different class for each number of parameters, 'V' version for void return.
//

//
class TModuleProcV0 : public TModuleProc {
  public:
    TModuleProcV0(const TModule& module, const char far* id) : TModuleProc(module, id) {}

    void operator ()() {
      typedef void (far WINAPI* TProc)();
      ((TProc)Proc)();
    }
};

//
template <class R>
class TModuleProc0 : public TModuleProc {
  public:
    TModuleProc0(const TModule& module, const char far* id) : TModuleProc(module, id) {}

    R operator ()() {
      typedef R (far WINAPI* TProc)();
      return ((TProc)Proc)();
    }
};

//
template <class P1>
class TModuleProcV1 : public TModuleProc {
  public:
    TModuleProcV1(const TModule& module, const char far* id) : TModuleProc(module, id) {}

    void operator ()(P1 p1) {
      typedef void (far WINAPI* TProc)(P1 p1);
      ((TProc)Proc)(p1);
    }
};

//
template <class R, class P1>
class TModuleProc1 : public TModuleProc {
  public:
    TModuleProc1(const TModule& module, const char far* id) : TModuleProc(module, id) {}

    R operator ()(P1 p1) {
      typedef R (far WINAPI* TProc)(P1 p1);
      return ((TProc)Proc)(p1);
    }
};

//
template <class P1, class P2>
class TModuleProcV2 : public TModuleProc {
  public:
    TModuleProcV2(const TModule& module, const char far* id) : TModuleProc(module, id) {}

    void operator ()(P1 p1, P2 a2) {
      typedef void (far WINAPI* TProc)(P1 p1, P2 a2);
      ((TProc)Proc)(p1, a2);
    }
};

//
template <class R, class P1, class P2>
class TModuleProc2 : public TModuleProc {
  public:
    TModuleProc2(const TModule& module, const char far* id) : TModuleProc(module, id) {}

    R operator ()(P1 p1, P2 p2) {
      typedef R (far WINAPI* TProc)(P1 p1, P2 p2);
      return ((TProc)Proc)(p1, p2);
    }
};

//
template <class P1, class P2, class P3>
class TModuleProcV3 : public TModuleProc {
  public:
    TModuleProcV3(const TModule& module, const char far* id) : TModuleProc(module, id) {}

    void operator ()(P1 p1, P2 p2, P3 p3) {
      typedef void (far WINAPI* TProc)(P1 p1, P2 p2, P3 p3);
      ((TProc)Proc)(p1, p2, p3);
    }
};

//
template <class R, class P1, class P2, class P3>
class TModuleProc3 : public TModuleProc {
  public:
    TModuleProc3(const TModule& module, const char far* id) : TModuleProc(module, id) {}

    R operator ()(P1 p1, P2 p2, P3 p3) {
      typedef R (far WINAPI* TProc)(P1 p1, P2 p2, P3 p3);
      return ((TProc)Proc)(p1, p2, p3);
    }
};

//
template <class P1, class P2, class P3, class P4>
class TModuleProcV4 : public TModuleProc {
  public:
    TModuleProcV4(const TModule& module, const char far* id) : TModuleProc(module, id) {}

    void operator ()(P1 p1, P2 p2, P3 p3, P4 p4) {
      typedef void (far WINAPI* TProc)(P1 p1, P2 p2, P3 p3, P4 p4);
      ((TProc)Proc)(p1, p2, p3, p4);
    }
};

//
template <class R, class P1, class P2, class P3, class P4>
class TModuleProc4 : public TModuleProc {
  public:
    TModuleProc4(const TModule& module, const char far* id) : TModuleProc(module, id) {}

    R operator ()(P1 p1, P2 p2, P3 p3, P4 p4) {
      typedef R (far WINAPI* TProc)(P1 p1, P2 p2, P3 p3, P4 p4);
      return ((TProc)Proc)(p1, p2, p3, p4);
    }
};

//
template <class P1, class P2, class P3, class P4, class P5>
class TModuleProcV5 : public TModuleProc {
  public:
    TModuleProcV5(const TModule& module, const char far* id) : TModuleProc(module, id) {}

    void operator ()(P1 p1, P2 p2, P3 p3, P4 p4, P5 p5) {
      typedef void (far WINAPI* TProc)(P1 p1, P2 p2, P3 p3, P4 p4, P5 p5);
      ((TProc)Proc)(p1, p2, p3, p4, p5);
    }
};

//
template <class R, class P1, class P2, class P3, class P4, class P5>
class TModuleProc5 : public TModuleProc {
  public:
    TModuleProc5(const TModule& module, const char far* id) : TModuleProc(module, id) {}

    R operator ()(P1 p1, P2 p2, P3 p3, P4 p4, P5 p5) {
      typedef R (far WINAPI* TProc)(P1 p1, P2 p2, P3 p3, P4 p4, P5 p5);
      return ((TProc)Proc)(p1, p2, p3, p4, p5);
    }
};

//
template <class P1, class P2, class P3, class P4, class P5, class P6>
class TModuleProcV6 : public TModuleProc {
  public:
    TModuleProcV6(const TModule& module, const char far* id) : TModuleProc(module, id) {}

    void operator ()(P1 p1, P2 p2, P3 p3, P4 p4, P5 p5, P6 p6) {
      typedef void (far WINAPI* TProc)(P1 p1, P2 p2, P3 p3, P4 p4, P5 p5, P6 p6);
      ((TProc)Proc)(p1, p2, p3, p4, p5, p6);
    }
};

//
template <class R, class P1, class P2, class P3, class P4, class P5, class P6>
class TModuleProc6 : public TModuleProc {
  public:
    TModuleProc6(const TModule& module, const char far* id) : TModuleProc(module, id) {}

    R operator ()(P1 p1, P2 p2, P3 p3, P4 p4, P5 p5, P6 p6) {
      typedef R (far WINAPI* TProc)(P1 p1, P2 p2, P3 p3, P4 p4, P5 p5, P6 p6);
      return ((TProc)Proc)(p1, p2, p3, p4, p5, p6);
    }
};

//
template <class P1, class P2, class P3, class P4, class P5, class P6, class P7>
class TModuleProcV7 : public TModuleProc {
  public:
    TModuleProcV7(const TModule& module, const char far* id) : TModuleProc(module, id) {}

    void operator ()(P1 p1, P2 p2, P3 p3, P4 p4, P5 p5, P6 p6, P7 p7) {
      typedef void (far WINAPI* TProc)(P1 p1, P2 p2, P3 p3, P4 p4, P5 p5, P6 p6,
                                       P7 p7);
      ((TProc)Proc) (p1, p2, p3, p4, p5, p6, p7);
    }
};

//
template <class R, class P1, class P2, class P3, class P4, class P5, class P6,
          class P7>
class TModuleProc7 : public TModuleProc {
  public:
    TModuleProc7(const TModule& module, const char far* id) : TModuleProc(module, id) {}

    R operator ()(P1 p1, P2 p2, P3 p3, P4 p4, P5 p5, P6 p6, P7 p7) {
      typedef R (far WINAPI* TProc)(P1 p1, P2 p2, P3 p3, P4 p4, P5 p5, P6 p6,
                                    P7 p7);
      return ((TProc)Proc)(p1, p2, p3, p4, p5, p6, p7);
    }
};

//
template <class P1, class P2, class P3, class P4, class P5, class P6,
          class P7, class P8>
class TModuleProcV8 : public TModuleProc {
  public:
    TModuleProcV8(const TModule& module, const char far* id) : TModuleProc(module, id) {}

    void operator ()(P1 p1, P2 p2, P3 p3, P4 p4, P5 p5, P6 p6, P7 p7, P8 p8) {
      typedef void (far WINAPI* TProc)(P1 p1, P2 p2, P3 p3, P4 p4, P5 p5, P6 p6,
                                    P7 p7, P8 p8);
      ((TProc)Proc)(p1, p2, p3, p4, p5, p6, p7, p8);
    }
};

//
template <class R, class P1, class P2, class P3, class P4, class P5, class P6,
          class P7, class P8>
class TModuleProc8 : public TModuleProc {
  public:
    TModuleProc8(const TModule& module, const char far* id) : TModuleProc(module, id) {}

    R operator ()(P1 p1, P2 p2, P3 p3, P4 p4, P5 p5, P6 p6, P7 p7, P8 p8) {
      typedef R (far WINAPI* TProc)(P1 p1, P2 p2, P3 p3, P4 p4, P5 p5, P6 p6,
                                    P7 p7, P8 p8);
      return ((TProc)Proc)(p1, p2, p3, p4, p5, p6, p7, p8);
    }
};

//
template <class P1, class P2, class P3, class P4, class P5, class P6,
          class P7, class P8, class P9>
class TModuleProcV9 : public TModuleProc {
  public:
    TModuleProcV9(const TModule& module, const char far* id) : TModuleProc(module, id) {}

    void operator ()(P1 p1, P2 p2, P3 p3, P4 p4, P5 p5, P6 p6, P7 p7, P8 p8, P9 p9) {
      typedef void (far WINAPI* TProc)(P1 p1, P2 p2, P3 p3, P4 p4, P5 p5, P6 p6,
                                    P7 p7, P8 p8, P9 p9);
      ((TProc)Proc)(p1, p2, p3, p4, p5, p6, p7, p8, p9);
    }
};

//
template <class R, class P1, class P2, class P3, class P4, class P5, class P6,
          class P7, class P8, class P9>
class TModuleProc9 : public TModuleProc {
  public:
    TModuleProc9(const TModule& module, const char far* id) : TModuleProc(module, id) {}

    R operator ()(P1 p1, P2 p2, P3 p3, P4 p4, P5 p5, P6 p6, P7 p7, P8 p8, P9 p9) {
      typedef R (far WINAPI* TProc)(P1 p1, P2 p2, P3 p3, P4 p4, P5 p5, P6 p6,
                                    P7 p7, P8 p8, P9 p9);
      return ((TProc)Proc)(p1, p2, p3, p4, p5, p6, p7, p8, p9);
    }
};

//
template <class P1, class P2, class P3, class P4, class P5, class P6,
          class P7, class P8, class P9, class P10>
class TModuleProcV10 : public TModuleProc {
  public:
    TModuleProcV10(const TModule& module, const char far* id) : TModuleProc(module, id) {}

    void operator ()(P1 p1, P2 p2, P3 p3, P4 p4, P5 p5, P6 p6, P7 p7, P8 p8, P9 p9,
                  P10 p10) {
      typedef void (far WINAPI* TProc)(P1 p1, P2 p2, P3 p3, P4 p4, P5 p5, P6 p6,
                                    P7 p7, P8 p8, P9 p9, P10 p10);
      ((TProc)Proc)(p1, p2, p3, p4, p5, p6, p7, p8, p9, p10);
    }
};

//
template <class R, class P1, class P2, class P3, class P4, class P5, class P6,
          class P7, class P8, class P9, class P10>
class TModuleProc10 : public TModuleProc {
  public:
    TModuleProc10(const TModule& module, const char far* id) : TModuleProc(module, id) {}

    R operator ()(P1 p1, P2 p2, P3 p3, P4 p4, P5 p5, P6 p6, P7 p7, P8 p8, P9 p9,
                  P10 p10) {
      typedef R (far WINAPI* TProc)(P1 p1, P2 p2, P3 p3, P4 p4, P5 p5, P6 p6,
                                    P7 p7, P8 p8, P9 p9, P10 p10);
      return ((TProc)Proc)(p1, p2, p3, p4, p5, p6, p7, p8, p9, p10);
    }
};

//
template <class P1, class P2, class P3, class P4, class P5, class P6,
          class P7, class P8, class P9, class P10, class P11>
class TModuleProcV11 : public TModuleProc {
  public:
    TModuleProcV11(const TModule& module, const char far* id) : TModuleProc(module, id) {}

    void operator ()(P1 p1, P2 p2, P3 p3, P4 p4, P5 p5, P6 p6, P7 p7, P8 p8, P9 p9,
                  P10 p10, P11 p11) {
      typedef void (far WINAPI* TProc)(P1 p1, P2 p2, P3 p3, P4 p4, P5 p5, P6 p6,
                                    P7 p7, P8 p8, P9 p9, P10 p10, P11 p11);
      ((TProc)Proc)(p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11);
    }
};

//
template <class R, class P1, class P2, class P3, class P4, class P5, class P6,
          class P7, class P8, class P9, class P10, class P11>
class TModuleProc11 : public TModuleProc {
  public:
    TModuleProc11(const TModule& module, const char far* id) : TModuleProc(module, id) {}

    R operator ()(P1 p1, P2 p2, P3 p3, P4 p4, P5 p5, P6 p6, P7 p7, P8 p8, P9 p9,
                  P10 p10, P11 p11) {
      typedef R (far WINAPI* TProc)(P1 p1, P2 p2, P3 p3, P4 p4, P5 p5, P6 p6,
                                    P7 p7, P8 p8, P9 p9, P10 p10, P11 p11);
      return ((TProc)Proc)(p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11);
    }
};

//
template <class P1, class P2, class P3, class P4, class P5, class P6,
          class P7, class P8, class P9, class P10, class P11, class P12>
class TModuleProcV12 : public TModuleProc {
  public:
    TModuleProcV12(const TModule& module, const char far* id) : TModuleProc(module, id) {}

    void operator ()(P1 p1, P2 p2, P3 p3, P4 p4, P5 p5, P6 p6, P7 p7, P8 p8, P9 p9,
                  P10 p10, P11 p11, P12 p12) {
      typedef void (far WINAPI* TProc)(P1 p1, P2 p2, P3 p3, P4 p4, P5 p5, P6 p6,
                                    P7 p7, P8 p8, P9 p9, P10 p10, P11 p11, P12 p12);
      ((TProc)Proc)(p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12);
    }
};

//
template <class R, class P1, class P2, class P3, class P4, class P5, class P6,
          class P7, class P8, class P9, class P10, class P11, class P12>
class TModuleProc12 : public TModuleProc {
  public:
    TModuleProc12(const TModule& module, const char far* id) : TModuleProc(module, id) {}

    R operator ()(P1 p1, P2 p2, P3 p3, P4 p4, P5 p5, P6 p6, P7 p7, P8 p8, P9 p9,
                  P10 p10, P11 p11, P12 p12) {
      typedef R (far WINAPI* TProc)(P1 p1, P2 p2, P3 p3, P4 p4, P5 p5, P6 p6,
                                    P7 p7, P8 p8, P9 p9, P10 p10, P11 p11, P12 p12);
      return ((TProc)Proc)(p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12);
    }
};

//
template <class P1, class P2, class P3, class P4, class P5, class P6,
          class P7, class P8, class P9, class P10, class P11, class P12, class P13>
class TModuleProcV13 : public TModuleProc {
  public:
    TModuleProcV13(const TModule& module, const char far* id) : TModuleProc(module, id) {}

    void operator ()(P1 p1, P2 p2, P3 p3, P4 p4, P5 p5, P6 p6, P7 p7, P8 p8, P9 p9,
                  P10 p10, P11 p11, P12 p12, P13 p13) {
      typedef void (far WINAPI* TProc)(P1 p1, P2 p2, P3 p3, P4 p4, P5 p5, P6 p6,
                                    P7 p7, P8 p8, P9 p9, P10 p10, P11 p11,
                                    P12 p12, P13 p13);
      ((TProc)Proc)(p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13);
    }
};

//
template <class R, class P1, class P2, class P3, class P4, class P5, class P6,
          class P7, class P8, class P9, class P10, class P11, class P12, class P13>
class TModuleProc13 : public TModuleProc {
  public:
    TModuleProc13(const TModule& module, const char far* id) : TModuleProc(module, id) {}

    R operator ()(P1 p1, P2 p2, P3 p3, P4 p4, P5 p5, P6 p6, P7 p7, P8 p8, P9 p9,
                  P10 p10, P11 p11, P12 p12, P13 p13) {
      typedef R (far WINAPI* TProc)(P1 p1, P2 p2, P3 p3, P4 p4, P5 p5, P6 p6,
                                    P7 p7, P8 p8, P9 p9, P10 p10, P11 p11,
                                    P12 p12, P13 p13);
      return ((TProc)Proc)(p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13);
    }
};

//----------------------------------------------------------------------------
// System DLL Wrapper
//

#if defined(BI_PLAT_WIN16)
# if !defined(LPCTSTR)
#   define  LPCTSTR LPCSTR
# endif
# if !defined(LPTSTR)
#   define  LPTSTR  LPSTR
# endif
#endif

//
//
//
class _OWLCLASS TUser {
  public:
    static  HICON    LoadIcon(HINSTANCE, LPCTSTR);
    static  BOOL     DestroyIcon(HICON);
    static  BOOL     GetClassInfo(HINSTANCE, LPCTSTR, LPWNDCLASS);
    static  int      GetMenuString(HMENU, UINT, LPTSTR, int, UINT);
    static  UINT     GetMenuState(HMENU, UINT, UINT);
    static  TModule& GetModule();
};

// Generic definitions/compiler options (eg. alignment) following the
// definition of classes
#include <services/posclass.h>

#if defined(BI_NAMESPACE)
} // namespace OWL
#endif

//----------------------------------------------------------------------------
// Inline implementation
//

//
// Return the name of the module.
//
inline const char far* TModule::GetName() const
{
  return Name;
}

//
// Return the instance handle of the library module represented by the
// TModule obect.
//
inline TModule::THandle TModule::GetHandle() const
{
  return Handle;
}

//
// Operator returning the instance handle of the library module represented
// by the TModule obect.
//
inline TModule::operator TModule::THandle() const
{
  return GetHandle();
}

//
// Return true if the handles of the modules are identical.
//
inline bool TModule::operator ==(const TModule& m) const
{
  return GetHandle() == m.GetHandle();
}

//
// Return true if the module has been successfully loaded.
//
inline bool TModule::IsLoaded() const
{
  return GetHandle() > HINSTANCE(HINSTANCE_ERROR);
}


#if defined(OWL2_COMPAT)
//
// Return the handle of the module.
//
inline TModule::THandle TModule::GetInstance() const
{
  return GetHandle();
}

//
// Set the handle of the module.
//
inline void TModule::SetInstance(TModule::THandle handle)
{
  SetHandle(handle);
}
#endif

#if defined(OWL1_COMPAT)
//
inline TWindow* TModule::ValidWindow(TWindow* win)
{
  return win;
}

//
inline bool TModule::LowMemory()
{
  return false;
}

//
inline void TModule::RestoreMemory()
{
}
#endif

//
// Return the full path of the location of the module.
//
inline int TModule::GetModuleFileName(char far* buff, int maxChars)
{
  PRECONDITION(Handle > HINSTANCE(HINSTANCE_ERROR));
  return ::GetModuleFileName(Handle, buff, maxChars);
}

//
// Return the function address of a module.
//
inline FARPROC TModule::GetProcAddress(const char far* fcnName) const
{
  PRECONDITION(Handle > HINSTANCE(HINSTANCE_ERROR));
  return ::GetProcAddress(Handle, fcnName);
}

#if defined(BI_PLAT_WIN16)
//
// Retrieve the count of users on this module.
//
inline int TModule::GetModuleUsage() const
{
  PRECONDITION(Handle > HINSTANCE(HINSTANCE_ERROR));
  return ::GetModuleUsage(Handle);
}

//
// Get the instance data.
//
inline int TModule::GetInstanceData(void NEAR* data, int len) const
{
  PRECONDITION(Handle > HINSTANCE(HINSTANCE_ERROR));
  return ::GetInstanceData(Handle, (uint8 NEAR*)data, len);
}
#endif

//
// Wrapper for the Windows API to find a particular resource.
//
inline HRSRC TModule::FindResource(TResId id, const char far* type) const
{
  PRECONDITION(Handle > HINSTANCE(HINSTANCE_ERROR));
  return ::FindResource(Handle, id, type);
}

//
// Wrapper for the Windows API.
//
inline HGLOBAL TModule::LoadResource(HRSRC hRsrc) const
{
  PRECONDITION(Handle > HINSTANCE(HINSTANCE_ERROR));
  return ::LoadResource(Handle, hRsrc);
}

//
// Wrapper for the Windows API.
//
inline uint32 TModule::SizeofResource(HRSRC hRsrc) const
{
  PRECONDITION(Handle > HINSTANCE(HINSTANCE_ERROR));
  return ::SizeofResource(Handle, hRsrc);
}

#if defined(BI_PLAT_WIN16)
//
// Wrapper for the Windows API.
//
inline int TModule::AccessResource(HRSRC hRsrc) const
{
  PRECONDITION(Handle > HINSTANCE(HINSTANCE_ERROR));
  return ::AccessResource(Handle, hRsrc);
}

//
// Wrapper for the Windows API.
//
inline HGLOBAL TModule::AllocResource(HRSRC hRsrc, uint32 size) const
{
  PRECONDITION(Handle > HINSTANCE(HINSTANCE_ERROR));
  return ::AllocResource(Handle, hRsrc, size);
}

//
// Wrapper for the Windows API.
//
inline RSRCHDLRPROC TModule::SetResourceHandler(const char far* type, RSRCHDLRPROC loadProc) const
{
  PRECONDITION(Handle > HINSTANCE(HINSTANCE_ERROR));
  return ::SetResourceHandler(Handle, type, loadProc);
}
#endif

//
// Wrapper for the Windows API.
//
inline HBITMAP TModule::LoadBitmap(TResId id) const
{
  PRECONDITION(Handle > HINSTANCE(HINSTANCE_ERROR));
  return ::LoadBitmap(Handle, id);
}

//
// Wrapper for the Windows API.
//
inline bool TModule::GetClassInfo(const char far* name, WNDCLASS far* wndclass) const
{
  PRECONDITION(Handle > HINSTANCE(HINSTANCE_ERROR));
  return TUser::GetClassInfo(Handle, name, wndclass);
}

//
// Wrapper for the Windows API.
//
inline HACCEL TModule::LoadAccelerators(TResId id) const
{
  PRECONDITION(Handle > HINSTANCE(HINSTANCE_ERROR));
  return ::LoadAccelerators(Handle, id);
}

//
// Wrapper for the Windows API.
//
inline HMENU TModule::LoadMenu(TResId id) const
{
  PRECONDITION(Handle > HINSTANCE(HINSTANCE_ERROR));
  return ::LoadMenu(Handle, id);
}

//
// Wrapper for the Windows API.
//
inline HCURSOR TModule::LoadCursor(TResId id) const
{
  PRECONDITION(Handle > HINSTANCE(HINSTANCE_ERROR));
  return ::LoadCursor(Handle, id);
}

//
// Wrapper for the Windows API.
//
inline HICON TModule::LoadIcon(const char far* name) const
{
  PRECONDITION(Handle > HINSTANCE(HINSTANCE_ERROR));
  return ::LoadIcon(Handle, name);
}

#if defined(BI_PLAT_WIN16)
//
// Wrapper for the Windows API.
//
inline HCURSOR TModule::CopyCursor(HCURSOR hCursor) const
{
  PRECONDITION(Handle > HINSTANCE(HINSTANCE_ERROR));
  return ::CopyCursor(Handle, hCursor);
}

//
// Wrapper for the Windows API.
//
inline HICON TModule::CopyIcon(HICON hIcon) const
{
  PRECONDITION(Handle > HINSTANCE(HINSTANCE_ERROR));
  return ::CopyIcon(Handle, hIcon);
}
#else

//
// Wrapper for the Windows API.
//
inline HICON TModule::CopyIcon(HICON hIcon) const
{
  return ::CopyIcon(hIcon);
}
#endif

//
// Return the version information about this module.
//
inline VS_FIXEDFILEINFO far& TModuleVersionInfo::GetFixedInfo()
{
  PRECONDITION(FixedInfo);
  return *FixedInfo;
}

//
inline uint32 TModuleVersionInfo::GetSignature() const
{
  PRECONDITION(FixedInfo);
  return FixedInfo->dwSignature;
}

//
inline uint32 TModuleVersionInfo::GetStrucVersion() const
{
  PRECONDITION(FixedInfo);
  return FixedInfo->dwStrucVersion;
}

//
// Get the major file version (first 32-bits).
//
inline uint32 TModuleVersionInfo::GetFileVersionMS() const
{
  PRECONDITION(FixedInfo);
  return FixedInfo->dwFileVersionMS;
}

//
// Get the minor file version (last 32-bits).
//
inline uint32 TModuleVersionInfo::GetFileVersionLS() const
{
  PRECONDITION(FixedInfo);
  return FixedInfo->dwFileVersionLS;
}

//
// Get the major product version number (first 32-bits).
//
inline uint32 TModuleVersionInfo::GetProductVersionMS() const
{
  PRECONDITION(FixedInfo);
  return FixedInfo->dwProductVersionMS;
}

//
// Get the minor product version number (last 32-bits).
//
inline uint32 TModuleVersionInfo::GetProductVersionLS() const
{
  PRECONDITION(FixedInfo);
  return FixedInfo->dwProductVersionLS;
}

//
// Return true if the flag has been set in the version info.
//
inline bool TModuleVersionInfo::IsFileFlagSet(uint32 flag) const
{
  PRECONDITION(FixedInfo);
  return (FixedInfo->dwFileFlagsMask & flag) && (FixedInfo->dwFileFlags & flag);
}

//
inline uint32 TModuleVersionInfo::GetFileFlagsMask() const
{
  PRECONDITION(FixedInfo);
  return FixedInfo->dwFileFlagsMask;
}

//
inline uint32 TModuleVersionInfo::GetFileFlags() const
{
  PRECONDITION(FixedInfo);
  return FixedInfo->dwFileFlags;
}

//
inline bool TModuleVersionInfo::IsDebug() const
{
  PRECONDITION(FixedInfo);
  return (FixedInfo->dwFileFlags & FixedInfo->dwFileFlagsMask & VS_FF_DEBUG) ?
         true : false;
}

//
inline bool TModuleVersionInfo::InfoInferred() const
{
  PRECONDITION(FixedInfo);
  return (FixedInfo->dwFileFlags & FixedInfo->dwFileFlagsMask & VS_FF_INFOINFERRED) ?
          true : false;
}

//
inline bool TModuleVersionInfo::IsPatched() const
{
  PRECONDITION(FixedInfo);
  return (FixedInfo->dwFileFlags & FixedInfo->dwFileFlagsMask & VS_FF_PATCHED) ?
          true : false;
}

//
inline bool TModuleVersionInfo::IsPreRelease() const
{
  PRECONDITION(FixedInfo);
  return (FixedInfo->dwFileFlags & FixedInfo->dwFileFlagsMask & VS_FF_PRERELEASE) ?
          true : false;
}

//
inline bool TModuleVersionInfo::IsPrivateBuild() const
{
  PRECONDITION(FixedInfo);
  return (FixedInfo->dwFileFlags & FixedInfo->dwFileFlagsMask & VS_FF_PRIVATEBUILD) ?
          true : false;
}

//
inline bool TModuleVersionInfo::IsSpecialBuild() const
{
  PRECONDITION(FixedInfo);
  return (FixedInfo->dwFileFlags & FixedInfo->dwFileFlagsMask & VS_FF_SPECIALBUILD) ?
          true : false;
}

// returns TFileOS values
inline uint32 TModuleVersionInfo::GetFileOS() const
{
  PRECONDITION(FixedInfo);
  return FixedInfo->dwFileOS;
}

//
inline TModuleVersionInfo::TFileType TModuleVersionInfo::GetFileType() const
{
  PRECONDITION(FixedInfo);
  return (TFileType)FixedInfo->dwFileType;
}

//
// Return the language id of this module.
//
inline uint TModuleVersionInfo::GetLanguage() const
{
  return uint(Lang);
}

//
// Return the language name of this module.
//
inline string TModuleVersionInfo::GetLanguageName() const
{
  return GetLanguageName(GetLanguage());
}

//
// Construct a TErrorMode object which invokes the 'SetErrorMode' API
// function to control how/whether Windows handles interrupt 24h errors.
//
inline TErrorMode::TErrorMode(uint mode)
{
  PrevMode = ::SetErrorMode(mode);
}

//
// Destructor of TErrorMode object - restore the state of the error mode
// saved during construction of the object.
//
inline TErrorMode::~TErrorMode()
{
  ::SetErrorMode(PrevMode);
}



//
// Get this header to get GetApplicationObject() for backward compatibility
// with Owl 2.0
//
#if defined(OWL2_COMPAT) && !defined(OWL_APPDICT_H)
# include <owl/appdict.h>
#endif

#endif  // OWL_MODULE_H
