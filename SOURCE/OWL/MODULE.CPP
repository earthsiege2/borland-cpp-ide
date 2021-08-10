//----------------------------------------------------------------------------
// ObjectWindows
// Copyright (c) 1991, 1997 by Borland International, All Rights Reserved
//
//$Revision:   10.24  $
//
// Implementation of class TModule. TModule defines the base behavior for
// OWL libraries and applications.
//----------------------------------------------------------------------------
#pragma hdrignore SECTION
#include <owl/pch.h>
#if !defined(OWL_MODULE_H)
# include <owl/module.h>
#endif
#if !defined(OWL_APPDICT_H)
# include <owl/appdict.h>
#endif
#if !defined(OWL_APPLICAT_H)
# include <owl/applicat.h>
#endif
#if !defined(CLASSLIB_POINTER_H)
# include <classlib/pointer.h>
#endif
#include <stdio.h>
#if defined(BI_PLAT_WIN32)
# include <winnls.h>
#endif

extern 
uint _OWLDATA GetWindowPtrMsgId;   // Defined in APPLICAT.CPP

OWL_DIAGINFO;
DIAG_DECLARE_GROUP(OwlApp);        // General Application diagnostic group

#if !defined(SECTION) || SECTION == 1

//----------------------------------------------------------------------------

//
// Implementation of Constructors for a TModule object
//

//
// Construct a TModule that is an alias for a DLL. TModule will load & free
// the DLL if "shouldLoad" is true. If "shouldLoad" is false, then the Handle
// must be set some time later using InitModule().
// "mustLoad" determines if a load failure should cause an exception throw
//
TModule::TModule(const char far* name, bool shouldLoad, bool mustLoad)
        :Name(0)
{
  if (shouldLoad) {
    TErrorMode loadMode(SEM_NOOPENFILEERRORBOX | SEM_FAILCRITICALERRORS);
    Handle = ::LoadLibrary(name);
    if (Handle <= HINSTANCE(HINSTANCE_ERROR) && mustLoad) {
      TRACEX(OwlApp, 0, "Unable to load DLL '" << string(name) << '\'');
      TXInvalidModule::Raise(name);  
    }
  }
  else {
    Handle = 0;
  }

  ShouldFree = shouldLoad;
  SetName(name);
#if defined(OWL1_COMPAT)
  lpCmdLine = 0;
#endif
}

//
// Construct a TModule that is an alias for an already loaded DLL or program
// with an Handle available. Name is optional & can be 0. No cmdLine is
// setup
//
TModule::TModule(const char far* name, HINSTANCE hInstance)
        :Name(0)
{
  PRECONDITION(hInstance > HINSTANCE(HINSTANCE_ERROR));
  Handle = hInstance;
  ShouldFree = false;
  SetName(name);
#if defined(OWL1_COMPAT)
  lpCmdLine = 0;
#endif
}

//
// Construct a TModule for an Owl Program via TApplication. InitModule is
// called from here to initialize Handle & the CmdLine
//
TModule::TModule(const char far* name, HINSTANCE hInstance,
                 const char far* cmdLine) : Name(0)
{
  Handle = 0;
  ShouldFree = false;
  SetName(name);
#if defined(OWL1_COMPAT)
  lpCmdLine = 0;
#endif
  if (hInstance)
    InitModule(hInstance, cmdLine);
}

//
// Destruct a TModule, freeing the instance if appropriate, and deleting
// new'd strings
//
TModule::~TModule()
{
  if (ShouldFree && Handle > HINSTANCE(HINSTANCE_ERROR))
    ::FreeLibrary(Handle);
  delete[] Name;
#if defined(OWL1_COMPAT)
  delete[] lpCmdLine;
#endif
}

//
//
//
void
TModule::SetName(const char far* name)
{
  delete[] Name;
  TAPointer<char> moduleName;
  if (Handle > HINSTANCE(HINSTANCE_ERROR) && !name) {
    moduleName = new char[_MAX_PATH];
    if (GetModuleFileName(moduleName, _MAX_PATH))
      name = moduleName;
  }
  Name = strnewdup(name);
}

//
// Perform initialization of modules cmd line copy, and get proc
// instance handles for the standard procs.
//
void
#if defined(OWL1_COMPAT)
TModule::InitModule(HINSTANCE hInstance, const char far* cmdLine)
#else
TModule::InitModule(HINSTANCE hInstance, const char far*)
#endif
{
  SetHandle(hInstance);

#if (__BORLANDC__ < 0x0500) && defined(BI_PLAT_WIN32)
  // This used to be a problem, but now the RTL takes care of this.
  // Win32 prepends the full application path to the command line arguments
  // skip over this "extra" argument for 16-bit compatibility
  // _argc and _argv do the correct processing, _argv[0] being the pathname
  //
  if (cmdLine)
    while (*cmdLine && *cmdLine++ != ' ')
      ;
#endif

#if defined(OWL1_COMPAT)
  if (cmdLine)
    lpCmdLine = strnewdup(cmdLine);
#endif

  // Register a system-wide "GetWindowPtr" message as GetWindowPtr(_hInstance)
  // Each running copy of ObjectWindows will get a unique message Id
  //
  if (!GetWindowPtrMsgId) {
    const char msgTemplate[] = "GetWindowPtr(%X)";
    char msgName[sizeof(msgTemplate) + 8];
    sprintf(msgName, msgTemplate, unsigned(_hInstance));
    GetWindowPtrMsgId = ::RegisterWindowMessage(msgName);
    CHECK(GetWindowPtrMsgId);
  }
}

//
// Replaceable exception handler; may be redefined to process OWL exceptions
// if canResume is false, then the user doesn't have the option of ignoring
//
int
TModule::Error(xmsg& x, unsigned captionResId, unsigned promptResId)
{
  char cbuf[80];
  char pbuf[80];

  if (!captionResId)
    captionResId = IDS_UNHANDLEDXMSG;
  return HandleGlobalException(x,
    LoadString(captionResId, cbuf, sizeof(cbuf)) ? cbuf : 0,
    promptResId ?
      (LoadString(promptResId, pbuf, sizeof(pbuf)) ? pbuf : "OK to Resume?")
      : 0);
}

//
// Set the instance handle for a module that does not yet have one. Cannot
// be called on a module that already has an instance handle.
//
void
TModule::SetHandle(HINSTANCE hInstance)
{
  PRECONDITION(!ShouldFree && !Handle);
  Handle = hInstance;
}

//
// LoadString replacements which do not generated debug warning output
//
#if defined(BI_PLAT_WIN32)
 typedef WCHAR* TResText;
 typedef WCHAR* TResCount;
#else
 typedef char far* TResText;
 typedef uint8 far* TResCount;
#endif

//
// Wrapper for loading a string resource.
//
int
TModule::LoadString(uint id, char far* buf, int bufSize) const
{
  uint len = 0;
  HRSRC     resHdl;
  HGLOBAL   glbHdl;
  TResText  resData;

  if ((resHdl = FindResource(id/16+1, RT_STRING)) != 0
   && (glbHdl = LoadResource(resHdl)) != 0) {
    if ((resData = (TResText)LockResource(glbHdl)) != 0) {
      int cnt;
      for (cnt = id % 16; len = *(TResCount)resData++, cnt--; resData += len)
        ;
      if (len != 0) {
#if defined(BI_PLAT_WIN32)
        len = ::WideCharToMultiByte(CP_ACP, 0, resData, len, buf, bufSize, 0, 0);
        if (len > 0)
          buf[len] = 0;
#else
        if (len >= uint(bufSize))
          len = bufSize-1;
        for (cnt = len; cnt--; *buf++ = (char)*resData++)
          ;
        *buf = 0;
#endif
      }
      UnlockResource(glbHdl);
    }
    FreeResource(glbHdl);
    if (len)
      return len;
  }

  if (::Module != this)                   // look in OWL module if different
    return ::Module->LoadString(id, buf, bufSize);

  if (bufSize)
    *buf = 0;  // make empty string just in case caller doesn't check return
  return 0;    // indicate string not found
}

//
// Wrapper for loading a string resource.
// Returns a string object.
//
string
TModule::LoadString(uint id) const
{
  uint len = 0;
  HRSRC     resHdl;
  HGLOBAL   glbHdl;
  TResText  resData;
  string    retString;

  if ((resHdl = FindResource(id/16+1, RT_STRING)) != 0
   && (glbHdl = LoadResource(resHdl)) != 0) {
    if ((resData = (TResText)LockResource(glbHdl)) != 0) {
      int cnt;
      for (cnt = id % 16; len = *(TResCount)resData++, cnt--; resData += len)
        ;
      if (len != 0) {
#if (0) // This is dangerous unless string is changed to handle non-terminated
        // char arrays
        //
        retString.append(resData, 0, len);
#else
# if defined(BI_PLAT_WIN32)
        int n = ::WideCharToMultiByte(CP_ACP, 0, resData, len, 0, 0, 0, 0);
        TAPointer<char> buf = new char[n+1];
        len = ::WideCharToMultiByte(CP_ACP, 0, resData, len, buf, n+1, 0, 0);
  #if   0
        retString.resize(len+1);
        uint i;
        for (i = 0; i < len; i++)
          retString[i] = (char)buf[i];
        retString[i] = 0;
  #else
        // The string object does not need the terminating null of C-strings
        //
        retString.resize(len);
        uint i;
        for (i = 0; i < len; i++)
          retString[i] = (char)buf[i];
  #endif
# else
        retString.resize(len);
        uint i = 0;
        for (cnt = len; cnt--; retString[i++] = (char)*resData++)
          ;
# endif
#endif
      }
      UnlockResource(glbHdl);
    }
    FreeResource(glbHdl);
    if (len)
      return retString;
  }

  if (::Module != this)                   // look in OWL module if different
    return ::Module->LoadString(id);

  return retString;    // empty if string not found
}

//----------------------------------------------------------------------------

//
// Obsolete error handler--use Error(xmsg&,...) instead
//
#if defined(OWL1_COMPAT)
void
TModule::Error(int errorCode)
{
  char       errorStr[51];
  TModule*   module = GetApplicationObject();

  sprintf(errorStr,
           "Error received: error code = %d\nOK to proceed?",
           errorCode);

  if (::MessageBox(0, errorStr, module ? module->GetName() : Name,
                   MB_ICONSTOP | MB_YESNO | MB_TASKMODAL) == IDNO)
#if defined(BI_PLAT_WIN32)
  ::PostThreadMessage(GetCurrentThreadId(), WM_QUIT, 0, 0);
#else
  ::PostAppMessage(GetCurrentTask(), WM_QUIT, 0, 0);
#endif
}
#endif

//----------------------------------------------------------------------------
// Module entry dynamic binding base class

//
// Construct a Module entry object from a function name string or ordinal
//
TModuleProc::TModuleProc(const TModule& module, const char far* id)
{
  Proc = module.GetProcAddress(id);
  if (!Proc) {
    string msg;
    if (HiUint16(uint32(id)) != 0)
      msg = TXOwl::MakeMessage(IDS_INVALIDMODULEFCN, id);
    else
      msg = TXOwl::MakeMessage(IDS_INVALIDMODULEORD, LoUint16(uint32(id)));
    msg += module.GetName();  // Just tack on the module name...
    TXOwl::Raise(msg);
  }
}


//----------------------------------------------------------------------------
// Wrappers for Windows API
//
#if defined(BI_PLAT_WIN32)
  static const char userStr[] = "USER32";
# if defined(UNICODE)
    static const char LoadIconStr[] = "LoadIconW";
    static const char GetClassInfoStr[] = "GetClassInfoW";
    static const char GetMenuStringStr[]= "GetMenuStringW";
# else
    static const char LoadIconStr[] = "LoadIconA";
    static const char GetClassInfoStr[] = "GetClassInfoA";
    static const char GetMenuStringStr[]= "GetMenuStringA";
# endif
#elif defined(BI_PLAT_WIN16)
  static const char userStr[] = "USER";
  static const char LoadIconStr[] = "LoadIcon";
  static const char GetClassInfoStr[] = "GetClassInfo";
  static const char GetMenuStringStr[] = "GetMenuString";
#endif
static const char GetMenuStateStr[] = "GetMenuState";
static const char DestroyIconStr[] = "DestroyIcon";

//
// Returns TModule object wrapping the handle of the USER module
//
TModule&
TUser::GetModule()
{
  static TModule userModule(0, ::GetModuleHandle(userStr));
  return userModule;
}

//
// Invokes 'LoadIcon' indirectly
//
HICON
TUser::LoadIcon(HINSTANCE p1, LPCTSTR p2)
{
  static TModuleProc2<HICON, HINSTANCE, LPCTSTR>
         loadIcon(GetModule(), LoadIconStr);
  return loadIcon(p1, p2);
}

//
// Invokes 'DestroyIcon' indirectly
//
BOOL
TUser::DestroyIcon(HICON p1)
{
  static TModuleProc1<BOOL, HICON> destroyIcon(GetModule(), DestroyIconStr);
  return destroyIcon(p1);
}

//
// Invokes 'GetClassInfo' indirectly
//
BOOL
TUser::GetClassInfo(HINSTANCE p1, LPCTSTR p2, LPWNDCLASS p3)
{
  static TModuleProc3<BOOL, HINSTANCE, LPCTSTR, LPWNDCLASS>
         getClassInfo(GetModule(), GetClassInfoStr);
  return getClassInfo(p1, p2, p3);
}

//
// Invokes 'GetMenuString' indirectly
//
int
TUser::GetMenuString(HMENU p1, UINT p2, LPTSTR p3, int p4, UINT p5)
{
  static TModuleProc5<int, HMENU, uint, LPTSTR, int, int>
         getMenuString(GetModule(), GetMenuStringStr);
  return getMenuString(p1, p2, p3, p4, p5);
}

//
// Invokes 'GetMenuState' indirectly
//
UINT
TUser::GetMenuState(HMENU p1, UINT p2, UINT p3)
{
  static TModuleProc3<UINT, HMENU, UINT, UINT>
         getMenuState(GetModule(), GetMenuStateStr);
  return getMenuState(p1, p2, p3);
}


//----------------------------------------------------------------------------
//
// Exception class
//

//
// Create the Invalid Module exception.
//
TXInvalidModule::TXInvalidModule(const char far* name)
:
  TXOwl(MakeMessage(IDS_INVALIDMODULE, name))
{
}

//
// Creates a copy of exception for 16-bit Windows.
//
#if defined(BI_NO_COVAR_RET)
TXBase*
#else
TXInvalidModule*
#endif
TXInvalidModule::Clone()
{
  return new TXInvalidModule(*this);
}

//
// Throw the exception
//
void
TXInvalidModule::Throw()
{
  THROW( *this );
}

//
// Throw the exception
//
void
TXInvalidModule::Raise(const char far* name)
{
  TXInvalidModule(name).Throw();
}

#endif
#if !defined(SECTION) || SECTION == 2

//----------------------------------------------------------------------------
// TModule streaming
//

IMPLEMENT_STREAMABLE(TModule);

#if !defined(BI_NO_OBJ_STREAMING)

//
// Extract the module object from the persistent stream.
//
void*
TModule::Streamer::Read(ipstream& is, uint32 /*version*/) const
{
  TModule* o = GetObject();
  is >> (TResId&)o->Name;
#if defined(OWL1_COMPAT)
  is >> (TResId&)o->lpCmdLine;
#endif
  is >> o->ShouldFree;
  if (o->ShouldFree)
    o->Handle = ::LoadLibrary(o->Name);

  return o;
}

//
// Write the module into a persistent stream.
//
void
TModule::Streamer::Write(opstream& os) const
{
  TModule* o = GetObject();
  os << TResId(o->Name);
#if defined(OWL1_COMPAT)
  os << TResId(o->lpCmdLine);
#endif
  os << o->ShouldFree;
}

#endif  // if !defined(BI_NO_OBJ_STREAMING)

#endif
#if !defined(SECTION) || SECTION == 3

//----------------------------------------------------------------------------
//
// Entry (& exit) functions for Owl in a DLL
//

#if defined(_BUILDOWLDLL)

//
// TModule derived class to facilitate streaming pointer to the OWL Library
// the OWL module must be streamed by reference before any pointers to it
// the following code simply prevents writing data back over the OWL module
//

class _OWLCLASS TObjectWindowsLibrary : public TModule {
 public:
  TObjectWindowsLibrary(HINSTANCE hInst) : TModule("ObjectWindowsDLL", hInst){}
  DECLARE_STREAMABLE(_OWLCLASS, TObjectWindowsLibrary, 1);
};

IMPLEMENT_STREAMABLE1(TObjectWindowsLibrary, TModule);

#if !defined(BI_NO_OBJ_STREAMING)

//
// Read the object from the persistent stream.
//
void*
TObjectWindowsLibrary::Streamer::Read(ipstream&, uint32) const
{
  return GetObject();
}

//
// Write the object into a persistent stream.
//
void
TObjectWindowsLibrary::Streamer::Write(opstream&) const
{
}

#endif  // if !defined(BI_NO_OBJ_STREAMING)

//
// Global pointer to this module
//
#if defined(BI_NAMESPACE)
namespace OWL {
#endif

TModule* Module = 0;

#if defined(BI_NAMESPACE)
} // namespace OWL
#endif

#if defined(BI_PLAT_WIN32)

static int  Attaches = 0;  // Win32s doesn't have per-instance data-- keep
                           // track of number of attached processes

int WINAPI
DllEntryPoint(HINSTANCE hInstance, uint32 reason, void*)
{
  switch (reason) {
    case DLL_PROCESS_ATTACH: {
      if (!Attaches) {
        ::Module = new TObjectWindowsLibrary(hInstance);
      }
      Attaches++;
      break;
    }
    case DLL_PROCESS_DETACH: {
      Attaches--;
      if (!Attaches)
        delete ::Module;
      break;
    }
  }
  return true;
}

#else  // !defined(BI_PLAT_WIN32)

static char BidsDllName[] = BIDS_DLLNAME ".DLL";
static HINSTANCE BidsInst = 0;

// Add extra ref. counts on BIDS DLL since 16-bit Windows may (does) unload
// DLLs in wrong order causing a crash at shutdown.
//
// NOTE: We use priority 31 to come just before/after ctr/dtr of global
//       objects (which are assigned a priorority of 32)
//
static void lockDlls()
{
  BidsInst = ::LoadLibrary(BidsDllName);  
}
#pragma startup lockDlls 31

// Remove extra ref. count on BIDS DLL
//
static void unlockDlls()
{
  if (BidsInst > HINSTANCE(HINSTANCE_ERROR))
    ::FreeLibrary(BidsInst);
}
#pragma exit unlockDlls 31

//
// Entry point for the Owl DLL itself
//
int FAR PASCAL
LibMain(HINSTANCE   hInstance,
        uint16    /*wDataSeg*/,
        uint16    /*cbHeapSize*/,
        char far* /*lpCmdLine*/)
{
  // Static object aliasing the ObjectWindows DLL
  //
  static TObjectWindowsLibrary OWLDLLModule(hInstance);
  ::Module = &OWLDLLModule;

  return Module->Status == 0;
}

int
FAR PASCAL
WEP(int /*bSystemExit*/)
{
  return 1;
}


#endif  // defined(BI_PLAT_WIN32)
#endif  // defined(_BUILDOWLDLL)
#endif  // SECTION == 3

#if !defined(SECTION) || SECTION == 4

#if defined(BI_NAMESPACE)
namespace OWL {
#endif
//
// Inserter for formated output of instance handle
//
ostream& _OWLFUNC
operator <<(ostream& os, const TModule& m)
{
  return os << hex << uint(m.Handle);
}
#if defined(BI_NAMESPACE)
} // namespace OWL
#endif

#endif //section 4

