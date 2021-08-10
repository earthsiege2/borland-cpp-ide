//
//----------------------------------------------------------------------------
// ObjectComponents
// (C) Copyright 1994 by Borland International, All Rights Reserved
//
//   Implementation of TOcApp Class
//----------------------------------------------------------------------------
#include <ocf/ocfpch.h>
#include <ocf/autodefs.h>
#include <ocf/appdesc.h>
#include <ocf/ocreg.h>
#include <ocf/ocapp.h>
#include <ocf/ocpart.h>
#if defined(BI_PLAT_WIN32)
# include <winver.h>
#elif defined(BI_PLAT_WIN16)
# include <ver.h>
#endif

DIAG_DEFINE_GROUP(OcApp, true, 1);
DIAG_DECLARE_GROUP(OcDll);
DIAG_DECLARE_GROUP(OcRefCount);

//
// Constructor for TOcApp
//
TOcApp::TOcApp(TOcRegistrar& registrar, uint32 options, TOcApp*& retOcApp)
:
  OcAppPtr(retOcApp),
  Options(options),
  FrameWnd(0),
  DisableDlgs(false),
#if defined(BI_DATA_NEAR)
  Name(*new TString),
  NameList(*new TOcNameList),
#endif
  Registrar(registrar),
  Registered(false)
{
  Registrar.AppCount++;
  Init();
  RegisterClasses();
  retOcApp = this;    // setup the client's pointer last if all else is OK
  TRACEX(OcRefCount, 1, "TOcApp() @" << (void*)this);
}

//
// Common constructor initialization
//
void
TOcApp::Init()
{
  // Initialize BOle service ptrs that may or may not get setup later
  //
  BService = 0;
  BServiceI = 0;

  AddRef();  // TUnknown defaults to 0, we need 1

  // Create a BOle class manager for this app
  //
  BCmI = Registrar.CreateBOleClassMgr();

  // Create BOle service object & get its interface
  //
  BOleComponentCreate(&BService, GetOuter(), cidBOleService);
  if (BService && HRSucceeded(BService->QueryInterface(IID_IBService,
                                                       &(LPVOID)BServiceI))) {
    Release();
    BServiceI->Init(this);
  }
  else
    TXObjComp::Throw(TXObjComp::xBOleBindFail); // give up if no IBService

#if defined(BI_PLAT_WIN16)
  // Make this task's message queue larger for Ole.
  // This is necessary for all Win16 apps requiring LRPC calls.
  //
  int queueSize = 96;
  while (!::SetMessageQueue(queueSize) && queueSize > 0)
    queueSize -= 8;
#endif

  // Get the clipboard format strings
  //
  for (uint i = IDS_CFFIRST; i <= IDS_CFLAST; i++) {
    char name[128];
    if (::FindResource(_hInstance, MAKEINTRESOURCE(i/16+1), RT_STRING)) {
      if (::LoadString(_hInstance, i, name, 128)) {
        char far* resultName = strchr(name, '\n');
        *resultName++ = 0;
        NameList.Add(new TOcFormatName(name, resultName));
      }
    }
  }

  // Get & copy the appname from the reginfo
  //
  Name = Registrar.GetAppDescriptor().GetAppName(LangSysDefault);
}

//
// Clean up this object be releasing all helpers.
//
TOcApp::~TOcApp()
{
  OcAppPtr = 0;  // we're gone, make sure nobody calls us through unref'd ptr
  UnregisterClasses();

  // refcnt was held by controller
  //
  if (ForwardEvent(OC_APPSHUTDOWN) && IsOptionSet(amServedApp) &&
      !IsOptionSet(amExeModule)) {
    Registrar.Shutdown(0, Options);
  }

  if (BService)
    BService->Release();
#if defined(BI_DATA_NEAR)
  delete &Name;
  delete &NameList;
#endif
  Registrar.AppCount--;
  if (BCmI)
    BCmI->Release();
}

//
// Should only be called by the owner/creator of this object
//
void
TOcApp::ReleaseObject()
{
  FrameWnd = 0;
  if (!IsOptionSet(amServedApp))
    Release();   // if our container app holds the refcnt, then release it
}

//
// Callback from TUnknown's implementation of QueryInterface
//
HRESULT
TOcApp::QueryObject(const IID far& iid, void far* far* iface)
{
  HRESULT hr;

  // interfaces
     SUCCEEDED(hr = IBApplication_QueryInterface(this, iid, iface))
  || SUCCEEDED(hr = IBClassMgr_QueryInterface(this, iid, iface))

  // helpers
  || (BService && SUCCEEDED(hr = BService->QueryInterface(iid, iface)))
  ;
  return hr;
}

//----------------------------------------------------------------------------

//
// Create a BOle helper for one of our OC objects in this app
//
HRESULT
TOcApp::BOleComponentCreate(IUnknown far* far* iface, IUnknown* outer, BCID idClass)
{
  return BCmI->ComponentCreate(iface, outer, idClass);
}

//----------------------------------------------------------------------------
// Runtime document factory registration

//
// Register doc factories based on their 'progid' and their templates
//
void
TOcApp::RegisterClasses()
{
  if (Registered)
    return;
  if (!(IsOptionSet(amExeModule)))
    return;     // no class registration for inproc servers
  if (IsOptionSet(amSingleUse) &&
     (IsOptionSet(amAutomation)||
     !IsOptionSet(amEmbedding)))
    return;     // no class registration for single use apps unless embedded

  // Loop thru all templates, registering registerable classes
  //
  const TRegLink* link = GetRegistrar().GetAppDescriptor().GetRegLinkHead();
  for ( ; link; link = link->GetNext()) {
    TRegList&   regList = link->GetRegList();
    const char* progid = regList[IsOptionSet(amDebug) ? "debugprogid" : "progid" ];
    if (progid) {
      if (!IsOptionSet(amEmbedding) &&
          !(const char*)regList["insertable"])
        continue;   // don't register container classes unless embedding

      bool multiUse = !IsOptionSet(amSingleUse);
      if (multiUse) {
        const char* usage = regList.Lookup("usage");
        char su[] = ocrSingleUse;
        multiUse = ToBool(!(usage && *usage == *su));
      }
      if (!RegisterClass(progid, reinterpret_cast<BCID>(link), multiUse))
        TXObjComp::Throw(TXObjComp::xDocFactoryFail);
    }
  }
  Registered = true;
}

//
// Unregister doc class factories based on their 'progid' and their templates
//
void
TOcApp::UnregisterClasses()
{
  if (!Registered)
    return;

  // Loop thru all templates, unregistering registerable classes
  //
  const TRegLink* link = GetRegistrar().GetAppDescriptor().GetRegLinkHead();
  for ( ; link; link = link->GetNext()) {
    TRegList& regList = link->GetRegList();
    const char* progid = regList[IsOptionSet(amDebug) ? "debugprogid" : "progid" ];
    if (progid)
      if (!UnregisterClass(progid))
        TXObjComp::Throw(TXObjComp::xDocFactoryFail);
  }
  Registered = false;
}

//
// Add a user defined clipboard format name
//
void
TOcApp::AddUserFormatName(const char far* name, const char far* resultName, const char far* id)
{
  NameList.Add(new TOcFormatName(name, resultName, id));
}


//----------------------------------------------------------------------------
// OC side exposure of selected IBService functions

bool
TOcApp::UnregisterClass(const string& className)
{
  if (BServiceI)
    return HRSucceeded(BServiceI->UnregisterClass(OleStr(className.c_str())));
  return false;
}

//
// Let BOle know that the main window has resized. In-place servers may need to
// adjust their toolbars
//
void
TOcApp::EvResize()
{
  if (BServiceI)
    BServiceI->OnResize();
}

//
// Let BOle know that the main window has [de]activated.
//
void
TOcApp::EvActivate(bool active)
{
  if (BServiceI)
    BServiceI->OnActivate(active);
}

bool
TOcApp::RegisterClass(const string& className, BCID classId, bool multiUse)
{
  // Self-embedding works only if the app is multi-use
  //
  if (BServiceI)
    return HRSucceeded(BServiceI->RegisterClass(OleStr(className.c_str()),
                       this, classId, ToBool(multiUse), ToBool(!multiUse)));
  return false;
}

bool
TOcApp::CanClose()
{
  return BServiceI ? HRIsOK(BServiceI->CanClose()) : true;  // there are no servers running
}

uint
TOcApp::EnableEditMenu(TOcMenuEnable menuEnable, IBDataConsumer far* ocView)
{
  return BServiceI ? BServiceI->EnableEditMenu(menuEnable, ocView) : 0;
}

bool
TOcApp::Browse(TOcInitInfo& init)
{
  return BServiceI ? HRIsOK(BServiceI->Browse(&init)) : false;
}

bool
TOcApp::BrowseClipboard(TOcInitInfo& init)
{
  return BServiceI ? HRIsOK(BServiceI->BrowseClipboard(&init)): false;
}

bool
TOcApp::Paste(TOcInitInfo& init)
{
  return BServiceI ? HRIsOK(BServiceI->Paste(&init)) : false;
}

//
// Copy Selected embedded object
//
bool
TOcApp::Copy(TOcPart* ocPart)
{
  IBPart far* bPartI;
  if (ocPart && SUCCEEDED(ocPart->QueryInterface(IID_IBPart, &(LPVOID)bPartI))) {
    ocPart->Release();

    // Copy part with delayed rendering done by Bolero
    //
    return BServiceI ? HRIsOK(BServiceI->Clip(bPartI, true, true, true)) : false;
  }
  return false;
}

//
// Copy a selection in server document
//
bool
TOcApp::Copy(TOcDataProvider* ocData)
{
  PRECONDITION(ocData);
  if (BServiceI)
    BServiceI->Clip(0, false, false, false);
  else
    return false;

/*
  IBDataProvider far* bDataI;
  if (ocData && SUCCEEDED(ocData->QueryInterface(IID_IBDataProvider, &(LPVOID)bDataI))) {
    ocData->Release();

    // Copy part with delayed rendering done by ocDataProvider
    //
    return HRIsOK(BServiceI->Clip(bDataI, true, true, false));
  }
  return false;
*/
  return HRIsOK(BServiceI->Clip(ocData, true, true, false));
}

//
// Drag a selection
//
bool
TOcApp::Drag(TOcDataProvider* ocData, TOcDropAction inAction, TOcDropAction& outAction)
{
  PRECONDITION(ocData);
  /*
  if (!BServiceI)
    return false;

  IBDataProvider far* bDataI;
  if (ocData && SUCCEEDED(ocData->QueryInterface(IID_IBDataProvider, &(LPVOID)bDataI))) {
    ocData->Release();
    return HRSucceeded(BServiceI->Drag(ocData, inAction, &outAction));
  }
  return false;
  */

  return BServiceI? HRSucceeded(BServiceI->Drag(ocData, inAction, &outAction)) : false;
}

//
// Drag an embedded object
//
bool
TOcApp::Drag(TOcPart* ocPart, TOcDropAction inAction, TOcDropAction& outAction)
{
  IBPart far* bPartI;
  if (ocPart && SUCCEEDED(ocPart->QueryInterface(IID_IBPart, &(LPVOID)bPartI))) {
    ocPart->Release();
    // Drag part with delayed rendering done by Bolero
    //
    return HRSucceeded(BServiceI->Drag(bPartI, inAction, &outAction));
  }
  return false;
//  return BServiceI? HRSucceeded(BServiceI->Drag(ocPart, inAction, &outAction)) : false;
}

//
// Open the Convert dialog, and perform the conversion if OK. return true if
// conversion was perfromed successfully.
//
bool
TOcApp::Convert(TOcPart* ocPart, bool b)
{
  PRECONDITION(ocPart);

  if (BServiceI == 0)
    return false;

  // The Convert dialog is split into two pieces: one to run the dialog box
  // and one to do the actual work. This way, the caller can record the
  // actions of the dialog box for playback later.
  //
  TOcConvertInfo ci;
  if (HRIsOK(BServiceI->ConvertUI(ocPart->GetBPartI(), b, &ci)))
    return HRSucceeded(BServiceI->ConvertGuts(ocPart->GetBPartI(), b, &ci));

  return false;
}

//----------------------------------------------------------------------------
// IBApplication implementation

//
// Return the application's name
//
LPCOLESTR _IFUNC
TOcApp::GetAppName()
{
  return Name;
}

TOcHelp _IFUNC
TOcApp::HelpMode(TOcHelp /*newMode*/)
{
  return hlpExit;  // no built in help support
}

//
// Insert the container's menus into a provided menubar
//
HRESULT _IFUNC
TOcApp::InsertContainerMenus(HMENU hMenu, TOcMenuWidths far* omw)
{
  PRECONDITION(omw);
  if (!hMenu)
    return HR_NOERROR;

  TOcMenuDescr md;
  md.HMenu = hMenu;
  for (int i = 0; i < 6; i++) {
    md.Width[i] = (int)omw->Width[i] = 0;  // make sure the server's are zeroed
    i++;
    md.Width[i] = (int)omw->Width[i];
  }

  if (!(bool)ForwardEvent(OC_APPINSMENUS, &md))
    return HR_FAIL;

  for (i = 0; i < 6; i++)
    omw->Width[i] = md.Width[i];

  return HR_NOERROR;
}

//
// Now set the provided menubar into the container's main frame window
//
HRESULT _IFUNC
TOcApp::SetFrameMenu(HMENU hMenu)
{
  TOcMenuDescr md;
  md.HMenu = hMenu;
  return HRFailIfZero((bool)ForwardEvent(OC_APPMENUS, &md));
}

//
//
//
HRESULT _IFUNC
TOcApp::Accelerator(MSG far* msg)
{
  PRECONDITION(msg);

  return HRFailIfZero((bool)ForwardEvent(OC_APPPROCESSMSG, msg));
}

//
// Let BOle know if we (container app) have an accelerator table
//
HRESULT _IFUNC
TOcApp::GetAccelerators(HACCEL far*, int far*)
{
  return HR_FAIL;  // would retrieve or generate an accelerator table here
}

//
// Let BOle know if this app can/will accept links
//
HRESULT _IFUNC
TOcApp::CanLink()
{
  return HR_OK;  // return HR_FAIL to disallow Linking
}

//
// Let BOle know if this app can/will accept embeddings
//
HRESULT _IFUNC
TOcApp::CanEmbed()
{
  return HR_OK;  // return HR_FAIL to disallow Embedding
}

//
// Get and return the app frame's HWND
//
HWND _IFUNC
TOcApp::GetWindow()
{
  return FrameWnd;
}

//
// Get client rectangle of app's main frame window
//
HRESULT _IFUNC
TOcApp::GetWindowRect(TRect far* r)
{
  PRECONDITION(r);

  return HRFailIfZero((bool)ForwardEvent(OC_APPFRAMERECT, r));
}

//
// Return the app's title, same as GetAppName()
//
LPCOLESTR _IFUNC
TOcApp::GetWindowTitle()
{
  return Name;
}

//
// The server is asking for space along the app borders to put toolbars, etc.
// This call is used to determine whether the container is willing and able to
// provide a given combination.
//
HRESULT _IFUNC
TOcApp::RequestBorderSpace(const TRect far* space)
{
  return HRFailIfZero((bool)ForwardEvent(OC_APPBORDERSPACEREQ, space));
}

//
// Now, actually provide the space along the app frame borders for inplace
// server adornments
//
HRESULT _IFUNC
TOcApp::SetBorderSpace(const TRect far* space)
{
  return HRFailIfZero((bool)ForwardEvent(OC_APPBORDERSPACESET, space));
}

//
// Append supplied Ole title to frame's title, saving old title
//
void _IFUNC
TOcApp::AppendWindowTitle(LPCOLESTR /*title*/)
{
}

//
// Pass status bar text to container app to have app display it
//
HRESULT _IFUNC
TOcApp::SetStatusText(LPCOLESTR text)
{
  // Convert ole str into ascii
  //

  return HRFailIfZero((bool)ForwardEvent(OC_APPSTATUSTEXT, (const char far*)OleStr(text)));
}

//
// Respond to let BOle know if our app is MDI or not
//
HRESULT _IFUNC
TOcApp::IsMDI()
{
  // Since this flag is used only to do toolbar negotiation,
  // we're always MDI as far as BOle is concerned.
  //
  return HR_NOERROR;
}

//
// The server is entering or leaving a modal state. Keep track so that we don't
// interfere when it is modal.
//
HRESULT _IFUNC
TOcApp::OnModalDialog(BOOL svrModal)
{
  DisableDlgs = (bool)svrModal;
  return HR_NOERROR;
}

//
// The in-place server is done. Tell the container to restore its normal UI.
// We can handle the window text here, let the app do the rest.
//
void _IFUNC
TOcApp::RestoreUI()
{
  SetStatusText(0);
  ForwardEvent(OC_APPRESTOREUI);
}

//
//
//
void _IFUNC
TOcApp::DialogHelpNotify(TOcDialogHelp help)
{
  ForwardEvent(OC_APPDIALOGHELP, help);
}

//
// called by BOle when last embedding is closed
// if that's the only reason the app is up we need to shut ourselves down
//
void _IFUNC
TOcApp::ShutdownMaybe()
{
  TRACEX(OcApp, 1,
         "ShutdownMaybe() on " << (void*)this <<
         " Embedding:" << ToBool(IsOptionSet(amEmbedding)) <<
         " Win:" << hex << (uint)GetWindow());

  // Check first to see if TOcApp should initiate a shutdown
  //
  if (ForwardEvent(OC_APPSHUTDOWN) || !GetWindow()) {
    // The server initiated the shutdown
    //
    if (!IsOptionSet(amExeMode)) {  // DLL server
      AddRef();    // prevent destroying ourselves yet
      Registrar.Shutdown(&(IUnknown&)*this, Options);
      Release();   // this should do us in now
    }
  }
}

//----------------------------------------------------------------------------

uint32
TOcApp::ForwardEvent(int eventId, const void far* param)
{
  if (::IsWindow(GetWindow()))
    return ::SendMessage(GetWindow(), WM_OCEVENT, eventId, (LPARAM)param);

  return 0;
}

uint32
TOcApp::ForwardEvent(int eventId, uint32 param)
{
  if (::IsWindow(GetWindow()))
    return ::SendMessage(GetWindow(), WM_OCEVENT, eventId, param);

  return 0;
}

//-----------------------------------------------------------------------------
// TOcClassMgr, IBClassMgr implementation for TOcRegistrar
//

class _ICLASS TOcClassMgr : private TUnknown, public IBClassMgr {
  public:
    TOcClassMgr(TComponentFactory cc, uint32 options);
    ~TOcClassMgr();
    ulong _IFUNC   AddRef() ;
    ulong _IFUNC   Release();

  private:
    HRESULT _IFUNC QueryInterface(const GUID far& iid, void far*far* iface)
                     {return GetOuter()->QueryInterface(iid, iface);}
    HRESULT _IFUNC ComponentCreate(IUnknown far* far* iface,
                                   IUnknown far* outer, BCID classId);
    HRESULT _IFUNC ComponentInfoGet(IUnknown far* far* info,
                                    IUnknown far* outer, BCID classId);
    // TUnknown virtual overrides
    //
    HRESULT      QueryObject(const IID far& iid, void far* far* iface);

    TComponentFactory OcCallback;  // callback for creating component
    uint32    Options;  // options flags from TOcRegistrar
  friend class TOcApp;  // could delegate the interface instead...
};

TOcClassMgr::TOcClassMgr(TComponentFactory cc, uint32 options)
:
  OcCallback(cc), Options(options)
{
}

TOcClassMgr::~TOcClassMgr()
{
}

ulong _IFUNC
TOcClassMgr::AddRef()
{
  return GetOuter()->AddRef();
}

ulong _IFUNC
TOcClassMgr::Release()
{
  return GetOuter()->Release();
}

//
// IBClassMgr implementation for TOcRegistrar
//
HRESULT _IFUNC
TOcClassMgr::ComponentCreate(IUnknown far* far* retIface, IUnknown far* outer, BCID idClass)
{
  PRECONDITION(idClass && retIface);

  *retIface = 0;
  if (!OcCallback)
    return HR_FAIL;

  try {

    // Test for special condition to force run as an EXE
    //
    void far* v;
    if (outer && !(Options & amExeModule) && outer->QueryInterface(IID_NULL, &v) == HR_NOERROR)
      *retIface = OcCallback(0, Options | amExeMode | amRun, idClass);
    else
      *retIface = OcCallback(outer, Options | amEmbedding, idClass);
    return *retIface ? HR_OK : HR_FAIL;
  }
  catch (...) {  // we can't throw any exception through OLE
    return HR_OUTOFMEMORY;  // probably a resource problem, better error code?
  }
}

HRESULT _IFUNC
TOcClassMgr::ComponentInfoGet(IUnknown far* far* info, IUnknown far* /*outer*/,
                              BCID /*idClass*/)
{
  *info = 0;
  return HR_FAIL;
}

HRESULT
TOcClassMgr::QueryObject(const IID far& iid, void far* far* iface)
{
  HRESULT hr;

  // interfaces
     HRSucceeded(hr = IBClassMgr_QueryInterface(this, iid, iface))
  ;
  return hr;
}

//----------------------------------------------------------------------------
// IBClassMgr implementation for TOcApp
//

HRESULT _IFUNC
TOcApp::ComponentCreate(IUnknown far* far* retIface, IUnknown far* outer, BCID idClass)
{
  return Registrar.OcClassMgr->ComponentCreate(retIface, outer, idClass);
}

HRESULT _IFUNC
TOcApp::ComponentInfoGet(IUnknown far* far* info, IUnknown far* outer, BCID idClass)
{
  return Registrar.OcClassMgr->ComponentInfoGet(info, outer, idClass);
}

//-----------------------------------------------------------------------------
// TOcRegistrar
//

TOcRegistrar::TOcRegistrar(TRegList& regInfo, TComponentFactory callback,
                           string& cmdLine, TRegLink* linkHead,
                           HINSTANCE hInst)
:
  TRegistrar(*new TAppDescriptor(regInfo, callback, cmdLine, hInst, linkHead)),
  BOleInstance(0),
  BCmI(0),
  OcClassMgr(0),
  AppCount(0)
{
  OcClassMgr = new TOcClassMgr(callback, GetOptions());
  OcClassMgr->AddRef();
}

TOcRegistrar::~TOcRegistrar()
{
  if (BCmI)
    BCmI->Release();
  if (OcClassMgr)
    OcClassMgr->Release();
  if (BOleInstance > HINSTANCE(32))
    ::FreeLibrary(BOleInstance);
}

//
// Create and return a BOle class manager helper interface with 1 ref on it
//
IBClassMgr*
TOcRegistrar::CreateBOleClassMgr()
{
  if (!BOleInstance)
    LoadBOle();

  HRESULT PASCAL FAR _export (*createClassMgr)(IUnknown far* far*,
                                               IUnknown far*, IMalloc far*);
  (FARPROC)createClassMgr = ::GetProcAddress(BOleInstance, BOLEBIND);
  if (createClassMgr) {

    // Call thru the exported function to get a BOle class manager
    // Don't aggregate it to anything
    //
    IUnknown*   bcm;
    createClassMgr(&bcm, 0, 0);
    if (bcm) {
      IBClassMgr* bcmi;
      bcm->QueryInterface(IID_IBClassMgr, &(LPVOID)bcmi);
      bcm->Release();
      if (bcmi)
        return bcmi;
    }
  }
  TXObjComp::Throw(TXObjComp::xBOleBindFail);
  return 0; // never reached
}

//
// Override TRegistrar's GetFactory to provide additional factory support
// using BOle factories
//
void far*
TOcRegistrar::GetFactory(const GUID& clsid, const GUID far& iid)
{
  void far* factory = TRegistrar::GetFactory(clsid, iid);
  if (factory)
    return factory;

  if (!BCmI)
    BCmI = CreateBOleClassMgr();

  IUnknown* objFactory = 0;
  IBClass* classMgr    = 0;

  TRegLink* link = GetAppDescriptor().GetRegLink(clsid);
  if (!link)
    return 0;

  TRegList&   regList = link->GetRegList();
  const char* progid = regList[IsOptionSet(amDebug) ? "debugprogid" : "progid" ];

  // Create BoleFactory helper object & init it, giving it our OcClassMgr
  // object to work with
  //
  if (!(HRSucceeded(BCmI->ComponentCreate(&objFactory, 0, cidBOleFactory)) &&
      HRSucceeded(objFactory->QueryInterface(IID_IBClass, &(LPVOID)classMgr)) &&
      HRSucceeded(classMgr->Init(false, OleStr(progid), OcClassMgr, reinterpret_cast<BCID>(link))) &&
      HRSucceeded(classMgr->QueryInterface(iid, &factory)))) {
    if (objFactory)
      objFactory->Release();
    if (classMgr)
      classMgr->Release();

    return 0;
  }

  return factory;
}

bool
TOcRegistrar::CanUnload()
{
  TRACEX(OcDll, 1, "CanUnload() AppCount:" << AppCount);
  return TRegistrar::CanUnload() && AppCount == 0;
}

static bool
sGetFileVersionInfo(const char far* fileName, VS_FIXEDFILEINFO& vInfo)
{
  OLECHAR* viBuff;      // version buffer
  uint32   infoSize;    // Size of version info resource in file

  // Find out how big the file version info buffer is supposed to be and
  // create a buffer of that size
  //
  uint32 infoHandle;
  if ((infoSize = ::GetFileVersionInfoSize(OleStr(fileName), &infoHandle)) == 0)
    return false;
  viBuff = new OLECHAR[(int)infoSize];

  // Copy the file version info buffer from the file into viBuff
  //
  if (::GetFileVersionInfo(OleStr(fileName), 0, infoSize, viBuff)) {

    // Perform some magic on the phantom buffer to get an actual structure with
    // the version information
    //
    uint vInfoLen;
    VS_FIXEDFILEINFO far* vInfoPtr;
    if (::VerQueryValue(viBuff, "\\", &(void far*)vInfoPtr, &vInfoLen)) {
      vInfo = *vInfoPtr;
      delete [] viBuff;
      return true;
    }
  }
  delete [] viBuff;
  return false;
}

//
// Dynamically load the OcOle Dll, get the one entry point that we need &
// make the class manager object that we use
//
void
TOcRegistrar::LoadBOle()
{
  // Check BOle DLL existance & version first, failing if it is incompatible
  // (old)
  //
  char name[30];
  OFSTRUCT ofs;
  ofs.cBytes = sizeof ofs;

#if defined(BI_PLAT_WIN32)
  bool winNT = !ToBool(::GetVersion()&0x80000000);
  if (winNT) // NT platform
  {
    lstrcpy(name, BOLEDLLW);

    // Try the ANSI dll if couldn't find Unicode version
    if (::OpenFile(name, &ofs, OF_EXIST) == HFILE_ERROR)
      lstrcpy(name, BOLEDLL);
  }
  else
#endif
    lstrcpy(name, BOLEDLL);

  if (::OpenFile(name, &ofs, OF_EXIST) >= 0) {
    VS_FIXEDFILEINFO vInfo;
    if (!sGetFileVersionInfo(name, vInfo) ||
        vInfo.dwFileVersionMS < BOLE_FILEVER_MS ||
          vInfo.dwFileVersionMS == BOLE_FILEVER_MS &&
          vInfo.dwFileVersionLS < BOLE_FILEVER_LS)
      TXObjComp::Throw(TXObjComp::xBOleVersFail);

    BOleInstance = ::LoadLibrary(ofs.szPathName);
  }

  // If we failed to load the DLL, throw a general cannot-load exception.
  // Otherwise get the class manager interface
  //
  if (BOleInstance <= HINSTANCE(32))
    TXObjComp::Throw(TXObjComp::xBOleLoadFail);
}

//-----------------------------------------------------------------------------
// TOcFormatName
//

TOcFormatName::TOcFormatName()
{
}

TOcFormatName::TOcFormatName(const char far* name, const char far* resultName,
                             const char far* id)
:
  Name(name),
  ResultName(resultName),
  Id(id)
{
}

//----------------------------------------------------------------------------
// TOcNameList
//

TOcNameList::TOcNameList()
:
  TICVectorImp<TOcFormatName>(15, 3)
{
}

TOcNameList::~TOcNameList()
{
  Clear();
}

//
// Find the format name with the corresponding id
//
TOcFormatName*
TOcNameList::operator [](char far* id)
{
  for (uint i = 0; i < Count(); i++) {
    TOcFormatName* formatName = (*this)[i];
    if (strcmp(formatName->GetId(), id) == 0)
      return formatName;
  }

  return 0;
}

//----------------------------------------------------------------------------
// TOcInitInfo
//

TOcInitInfo::TOcInitInfo(IBContainer far* container)
:
  How(ihEmbed),
  Where(iwNew),
  Container(container),
  HIcon(0),
  Storage(0)
{
}

TOcInitInfo::TOcInitInfo(TOcInitHow how, TOcInitWhere where, IBContainer far* container)
:
  How(how),
  Where(where),
  Container(container),
  HIcon(0),
  Storage(0)
{
}

