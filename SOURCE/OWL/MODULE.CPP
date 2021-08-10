//----------------------------------------------------------------------------
// ObjectWindows
// (C) Copyright 1991, 1994 by Borland International, All Rights Reserved
//
//   Implementation of class TModule.  TModule defines the
//   basic behavior for OWL libraries and applications.
//----------------------------------------------------------------------------
#pragma hdrignore SECTION
#include <owl/owlpch.h>
#include <owl/module.h>
#include <owl/appdict.h>

extern uint _OWLDATA GetWindowPtrMsgId;  // in applicat.cpp


#if !defined(SECTION) || SECTION == 1

//----------------------------------------------------------------------------

//
// implementation of Constructors for a TModule object
//

//
// Construct a TModule that is an alias for a DLL. TModule will load & free
// the DLL if shouldLoad is true. If shouldLoad is false, then the HInstance
// must be set some time later using InitModule()
//
TModule::TModule(const char far* name, bool shouldLoad)
{
  if (shouldLoad) {
    HInstance = ::LoadLibrary(name);
    if (HInstance <= HINSTANCE(32))
      THROW( TXInvalidModule() );
  }
  else {
    HInstance = 0;
  }

  ShouldFree = shouldLoad;
  Name = strnewdup(name);
  lpCmdLine = 0;
}

//
// Construct a TModule that is an alias for an already loaded DLL or program
// with an HInstance available. Name is optional & can be 0. No cmdLine is
// setup
//
TModule::TModule(const char far* name, HINSTANCE hInstance)
{
  PRECONDITION(hInstance > HINSTANCE(32));
  HInstance = hInstance;
  ShouldFree = false;
  Name = strnewdup(name);
  lpCmdLine = 0;
}

//
// Construct a TModule for an Owl Program via TApplication. InitModule is
// called from here to initialize HInstance & the CmdLine
//
TModule::TModule(const char far* name, HINSTANCE hInstance,
                 const char far* cmdLine)
{
  HInstance = 0;
  ShouldFree = false;
  Name = strnewdup(name);
  lpCmdLine = 0;
  if (hInstance)
    InitModule(hInstance, cmdLine);
}

//
// Destruct a TModule, freeing the instance if appropriate, and deleting
// new'd strings
//
TModule::~TModule()
{
  if (ShouldFree)
    ::FreeLibrary(HInstance);
  delete [] Name;
  delete [] lpCmdLine;
}

void
TModule::SetName(const char far* name)
{
  delete [] Name;
  Name = strnewdup(name);
}

//
// perform initialization of modules cmd line copy, and get proc
// instance handles for the standard procs.
//
void
TModule::InitModule(HINSTANCE hInstance, const char far* cmdLine)
{
  SetInstance(hInstance);

#if defined(BI_PLAT_WIN32)
  //
  // Win32 prepends the full application path to the command line arguments
  // skip over this "extra" argument for 16-bit compatibility
  // _argc and _argv do the correct processing, _argv[0] being the pathname
  //
  if (cmdLine)
    while (*cmdLine && *cmdLine++ != ' ')
      ;
#endif

  if (cmdLine)
    lpCmdLine = strnewdup(cmdLine);

  // Register a system-wide "GetWindowPtr" message as "GetWindowPtr(_hInstance)"
  // Each running copy of ObjectWindows will get a unique message Id
  //
  if (!GetWindowPtrMsgId) {
    const char msgTemplate[] = "GetWindowPtr(%X)";
    char msgName[sizeof(msgTemplate) + 8];
    wsprintf(msgName, msgTemplate, unsigned(_hInstance));
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
      (LoadString(promptResId, pbuf, sizeof(cbuf)) ? pbuf : "OK to Resume?")
      : 0);
}

//
// Set the instance handle for a module that does not yet have one. Cannot
// be called on a module that already has an instance handle.
//
void
TModule::SetInstance(HINSTANCE hInstance)
{
  PRECONDITION(!ShouldFree && !HInstance);
  HInstance = hInstance;
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
      for (int cnt = id % 16; len = *(TResCount)resData++, cnt--; resData += len)
        ;
      if (len != 0) {
        if (len >= bufSize)
          len = bufSize-1;
        for (cnt = len; cnt--; *buf++ = (char)*resData++)
          ;
        *buf = 0;
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
      for (int cnt = id % 16; len = *(TResCount)resData++, cnt--; resData += len)
        ;
      if (len != 0) {
#if (0) // This is dangerous unless string is changed to handle non-terminated
        // char arrays
        //
        retString.append(resData, 0, len);
#else
        retString.resize(len);
        int i = 0;
        for (cnt = len; cnt--; retString[i++] = (char)*resData++)
          ;
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

#include <owl/applicat.h>

//
// obsolete error handler--use Error(xmsg&,...) instead
//
void
TModule::Error(int errorCode)
{
  char       errorStr[51];
  TModule*   module = GetApplicationObject();

  wsprintf(errorStr,
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

//----------------------------------------------------------------------------
//
// Exception class
//

TModule::TXInvalidModule::TXInvalidModule() : TXOwl(IDS_INVALIDMODULE)
{
}

TXOwl*
TModule::TXInvalidModule::Clone()
{
  return new TXInvalidModule(*this);
}

void
TModule::TXInvalidModule::Throw()
{
  THROW( *this );
}

#endif
#if !defined(SECTION) || SECTION == 2

//----------------------------------------------------------------------------
// TModule streaming
//

IMPLEMENT_STREAMABLE(TModule);

void*
TModule::Streamer::Read(ipstream& is, uint32 /*version*/) const
{
  TModule* o = GetObject();
  is >> (TResId&)o->Name;
  is >> (TResId&)o->lpCmdLine;
  is >> o->ShouldFree;
  if (o->ShouldFree)
    o->HInstance = ::LoadLibrary(o->Name);

  return o;
}

void
TModule::Streamer::Write(opstream& os) const
{
  TModule* o = GetObject();
  os << TResId(o->Name);
  os << TResId(o->lpCmdLine);
  os << o->ShouldFree;
}

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

void*
TObjectWindowsLibrary::Streamer::Read(ipstream&, uint32) const
{
  return GetObject();
}

void
TObjectWindowsLibrary::Streamer::Write(opstream&) const
{
}

//
// Global pointer to this module
//
TModule* Module = 0;

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

//
// Entry point for the Owl DLL itself
//
int FAR PASCAL
LibMain(HINSTANCE   hInstance,
        uint16    /*wDataSeg*/,
        uint16    /*cbHeapSize*/,
        char far* /*lpCmdLine*/)
{
  //
  // Allocate the TModule object for the Owl DLL. The RTL makes sure that
  // the memory allocated is GMEM_SHARE.
  //
  ::Module = new TObjectWindowsLibrary(hInstance);

  return Module->Status == 0;
}

int
FAR PASCAL
WEP(int /*bSystemExit*/)
{
  delete ::Module;
  return 1;
}

#endif  // defined(BI_PLAT_WIN32)
#endif  // defined(_BUILDOWLDLL)
#endif  // SECTION == 3

#if !defined(SECTION) || SECTION == 4
//
// Inserter for formated output of instance handle
//
ostream& _OWLFUNC
operator <<(ostream& os, const TModule& m)
{
  return os << hex << uint(m.HInstance);
}
#endif //section 4
