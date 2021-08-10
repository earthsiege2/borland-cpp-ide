//----------------------------------------------------------------------------
// ObjectWindows - (C) Copyright 1991, 1993 by Borland International
//   source\owl\module.cpp
//   Implementation of class TModule.  TModule defines the
//   basic behavior for OWL libraries and applications.
//----------------------------------------------------------------------------
#pragma hdrignore SECTION
#include <owl\owlpch.h>
#include <owl\module.h>

extern UINT _OWLDATA GetWindowPtrMsgId;  // in owl.cpp


#if !defined(SECTION) || SECTION == 1

//----------------------------------------------------------------------------

//
// implementation of Constructors for a TModule object
//

//
// Construct a TModule that is an alias for a DLL. TModule will load & free
// the DLL if shouldLoad is TRUE. If shouldLoad is FALSE, then the HInstance
// must be set some time later using InitModule()
//
TModule::TModule(const char far* name, BOOL shouldLoad)
{
  if (shouldLoad) {
    HInstance = ::LoadLibrary(name);
    if (HInstance <= HINSTANCE(32))
      THROW( TXInvalidModule() );

  } else {
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
  ShouldFree = FALSE;
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
  ShouldFree = FALSE;
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
  delete Name;
  delete lpCmdLine;
}

void
TModule::SetName(const char far* name)
{
  delete Name;
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

  #if defined(__WIN32__)
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

  //
  // register a system-wide "GetWindowPtr" message as "OWLxxxx:GetWindowPtr"
  //
  if (!GetWindowPtrMsgId) {
    const char msgName[] = "OWL%X:GetWindowPtr";
    char buff[sizeof(msgName) + 6];
    wsprintf(buff, msgName, OWLVersion);
    GetWindowPtrMsgId = ::RegisterWindowMessage(buff);
  }
}

//
// Replaceable exception handler; may be redefined to process OWL exceptions
// if canResume is FALSE, then the user doesn't have the option of ignoring
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
// LoadString replacement which does not generated debug warning output
//
#if defined(__WIN32__)
typedef WCHAR* resText;
#else
typedef char far* resText;
#endif

int
TModule::LoadString(UINT id, char far* buf, int bufSize) const
{
  int len = 0;
  HRSRC     resHdl;
  HGLOBAL   glbHdl;
  resText   resData;
  
  if ((resHdl = FindResource(id/16+1, RT_STRING)) != 0
   && (glbHdl = LoadResource(resHdl)) != 0) {
    if ((resData = (resText)LockResource(glbHdl)) != 0) {
      for (int cnt = id % 16; len = *resData++, cnt--; resData += len) ;
      if (len != 0) {
        if (len >= bufSize)
          len = bufSize-1;
        for (cnt = len; len--; *buf++ = (char)*resData++) ;
        *(buf) = 0;
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


//----------------------------------------------------------------------------

#include <owl\applicat.h>

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
  #if defined(__WIN32__)
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

#if defined(__DLL__)

//
// TModule derived class to facilitate streaming pointer to the OWL Library
//	the OWL module must be streamed by reference before any pointers to it
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

#if defined(__WIN32__)

static int  Attaches = 0;  // Win32s doesn't have per-instance data-- keep
                           // track of number of attached processes

BOOL WINAPI
DllEntryPoint(HINSTANCE hInstance, DWORD reason, LPVOID)
{
  switch (reason) {
    case DLL_PROCESS_ATTACH: {
      if (!Attaches)
        ::Module = new TObjectWindowsLibrary(hInstance);
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
  return TRUE;
}

#else  // !defined(__WIN32__)

//
// Construct a TModule on the local heap to represent this Owl DLL
// Leave the heap locked so that we can have far pointers to it.
//
int FAR PASCAL
LibMain(HINSTANCE   hInstance,
        WORD      /*wDataSeg*/,
        WORD      /*cbHeapSize*/,
        char far* /*lpCmdLine*/)
{
  //
  // Allocate the module object for the Owl DLL. The RTL makes sure that
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

#endif  // defined(__WIN32__)
#endif  // defined(__DLL__)
#endif  // SECTION == 3

#if !defined(SECTION) || SECTION == 4
//
// Inserter for formated output of instance handle
//
ostream& _OWLFUNC
operator <<(ostream& os, const TModule& m)
{
  return os << hex << UINT(m.HInstance);
}
#endif //section 4
