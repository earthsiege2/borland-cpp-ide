//----------------------------------------------------------------------------
// ObjectComponents
// Copyright (c) 1994, 1996 by Borland International, All Rights Reserved
//
// $Revision:   2.11  $
//
// Implementation of TOcView Class
//----------------------------------------------------------------------------
#include <ocf/pch.h>
#include <ocf/ocstorag.h>
#include <ocf/ocview.h>
#include <ocf/ocremvie.h>
#include <ocf/ocapp.h>
#include <ocf/ocpart.h>
#include <ocf/ocdata.h>
#include <ocf/autodefs.h>
#include <services/memory.h>
#include <winsys/lclstrng.h>
#include <winsys/geometry.h>

DIAG_DECLARE_GROUP(OcRefCount);

const char  DocContent[] = "All";

//
// Compatibility constructor
//
TOcView::TOcView(TOcDocument& doc, TRegList* regList, IUnknown* outer)
:
  OcApp(doc.OcApp),
  OcDocument(doc),
  ContainerHost(new TOcContainerHostMsg),
  ServerHost(new TOcServerHostMsg),
  ActivePart(0),
  LinkFormat(-1),
  RegList(regList),
  OcData(0),
  Options(0),
#if defined(BI_DATA_NEAR)
  WinTitle(*new string),
  Origin(*new TPoint(0,0)),
  Extent(*new TSize(0,0)),
  FormatList(*new TOcFormatList),
  OrgTitle(*new TString),
#else
  Origin(0,0),
  Extent(0,0),
#endif
  BContainer(0),
  BDocumentI(0),
  BDocument(0),
  BLDocumentI(0)
{
  SetOuter(outer);
  AddRef();    // TUnknown defaults to 0, we need 1
  if (regList)
    RegisterClipFormats(*regList);

  // Necessary to initialize TOcPart for linking
  //
  OcDocument.SetActiveView(this);

  if (SUCCEEDED(OcApp.BOleComponentCreate(&BDocument,
                (IUnknown*)(IBContainer*)this, cidBOleDocument))) {
    BDocument->QueryInterface(IID_IBDocument, &(LPVOID)BDocumentI);
    Release();
  }

  if (SUCCEEDED(OcApp.BOleComponentCreate(&BContainer,
                (IUnknown*)(IBContainer*)this, cidBOleContainer))) {
    if (regList) {
      const char* progid = regList->Lookup(OcApp.IsOptionSet(amDebug) ?
                                           "debugprogid" : "progid");
      if (progid &&
          SUCCEEDED(BContainer->QueryInterface(IID_IBRootLinkable, &(LPVOID)BLDocumentI))) {
        Release();
        BLDocumentI->Init((TOcView*)this, OleStr(progid));
      }
    }
  }

  TRACEX(OcRefCount, 1, "TOcView() @" << (void*)this);
}

//
// New, interface constructor
//
TOcView::TOcView(TOcDocument& doc, TOcContainerHost* ch, TOcServerHost* sh,
                 TRegList* regList, IUnknown* outer)
:
  OcApp(doc.OcApp),
  OcDocument(doc),
  ContainerHost(ch),
  ServerHost(sh),
  ActivePart(0),
  LinkFormat(-1),
  RegList(regList),
  OcData(0),
  Options(0),
#if defined(BI_DATA_NEAR)
  WinTitle(*new string),
  Origin(*new TPoint(0,0)),
  Extent(*new TSize(0,0)),
  FormatList(*new TOcFormatList),
  OrgTitle(*new TString),
#else
  Origin(0,0),
  Extent(0,0),
#endif
  BContainer(0),
  BDocumentI(0),
  BDocument(0),
  BLDocumentI(0)
{
  SetOuter(outer);
  AddRef();    // TUnknown defaults to 0, we need 1
  if (regList)
    RegisterClipFormats(*regList);

  // Necessary to initialize TOcPart for linking
  //
  OcDocument.SetActiveView(this);

  if (SUCCEEDED(OcApp.BOleComponentCreate(&BDocument,
                (IUnknown*)(IBContainer*)this, cidBOleDocument))) {
    BDocument->QueryInterface(IID_IBDocument, &(LPVOID)BDocumentI);
    Release();
  }

  if (SUCCEEDED(OcApp.BOleComponentCreate(&BContainer,
                (IUnknown*)(IBContainer*)this, cidBOleContainer))) {
    if (regList) {
      const char* progid = regList->Lookup(OcApp.IsOptionSet(amDebug) ?
                                           "debugprogid" : "progid");
      if (progid &&
          SUCCEEDED(BContainer->QueryInterface(IID_IBRootLinkable, &(LPVOID)BLDocumentI))) {
        Release();
        BLDocumentI->Init((TOcView*)this, OleStr(progid));
      }
    }
  }

  TRACEX(OcRefCount, 1, "TOcView() @" << (void*)this);
}

//
//
//
TOcView::~TOcView()
{
  Shutdown();
#if defined(BI_DATA_NEAR)
  delete &WinTitle;
  delete &FormatList;
  delete &Origin;
  delete &Extent;
  delete &OrgTitle;
#endif
}

//
// Called from destructor of this class or of derived class to release helpers
// & host interfaces
//
void
TOcView::Shutdown()
{
  if (BContainer) {
    BContainer->Release();
    BContainer = 0;
  }
  if (BDocument) {
    BDocument->Release();
    BDocument = 0;
  }
  if (ContainerHost) {
    ContainerHost->ReleaseOcObject();
    ContainerHost = 0;
  }
  if (ServerHost) {
    ServerHost->ReleaseOcObject();
    ServerHost = 0;
  }
}

//
// Should only be called by the owner/creator of this object. Releases host
// interfaces & this.
//
void
TOcView::ReleaseObject()
{
  if (ContainerHost) {
    ContainerHost->ReleaseOcObject();
    ContainerHost = 0;
  }
  if (ServerHost) {
    ServerHost->ReleaseOcObject();
    ServerHost = 0;
  }
  Release();
}

//
// Callback from TUnknown's implementation of QueryInterface
//
HRESULT
TOcView::QueryObject(const IID far& iid, void far* far* iface)
{
  PRECONDITION(iface);
  HRESULT hr;

  // interfaces
  //
     SUCCEEDED(hr = IBContainer_QueryInterface(this, iid, iface))
  || SUCCEEDED(hr = IBContains_QueryInterface(this, iid, iface))
  || SUCCEEDED(hr = IBDataConsumer_QueryInterface(this, iid, iface))
  || SUCCEEDED(hr = IBDropDest_QueryInterface(this, iid, iface))
  || SUCCEEDED(hr = IBDataNegotiator_QueryInterface(this, iid, iface))

  // helpers (BContainer needed for embed/link from file)
  //
  || (BContainer && SUCCEEDED(hr = BContainer->QueryInterface(iid, iface)))
  || (BDocument && SUCCEEDED(hr = BDocument->QueryInterface(iid, iface)))
  ;

  // If the QueryInterface failed, try the TOcLinkView
  //

  if (hr == HR_NOINTERFACE && iid == IID_IDataObject) {
    TOcLinkView* view = GetDocLink(0);
    if (view)
      hr = view->QueryInterface(iid, iface);
  }

  return hr;
}

//----------------------------------------------------------------------------

//
//
//
void
TOcView::SetupWindow(HWND hWin, bool embedded)
{
  // Don't register drag&drop target here since it will do QueryInterface
  // in ComponentCreate before the outer is set up. RefCount will be messed
  // up in this case. Keep Win==0 while initing BDocumentI. OcRemView will init
  // later.
  //
  if (!embedded) {
    ContainerHost->SetWindow(hWin);
    ServerHost->SetWindow(hWin);
  }

  // Make sure at least the BDocument gets its container & application ptrs
  // setup
  //
  if (BDocumentI)
    BDocumentI->Init(this);

  if (!embedded)
    Rename();

  // Now keep window handle if embedded
  //
  if (embedded) {
    ContainerHost->SetWindow(hWin);
    ServerHost->SetWindow(hWin);
  }

  EvActivate(true);    // Default to being the active view on creation
}

//
// Obtain a TOcLinkView representing a moniker, the whole document by default
//
TOcLinkView*
TOcView::GetDocLink(const char far* name)
{
  // Default to the whole document contents
  //
  if (!name)
    name = DocContent;

  TOcViewCollection& views = OcDocument.GetViews();

  // Ask the document whether an TOcLinkView corresponding to the item name
  // already exists
  //
  TOcLinkView* ocLinkView = views.Find(name);

  // If not, Create an TOcLinkView for the linked doc/item the TOcLinkView
  // should remember the moniker. If the host does not accept the link,
  // then get rid of the linkview & return nothing.
  //
  if (!ocLinkView) {
    ocLinkView = new TOcLinkView(this, RegList);
    views.Add(ocLinkView);

    ocLinkView->SetMoniker(OleStr(name));
    ocLinkView->GetLinkRect();

    CHECK(ServerHost);
    if (!ServerHost->EvOcViewSetLink(*ocLinkView)) {
      views.Detach(ocLinkView, true);
      return 0;
    }
  }

  return ocLinkView;
}

//
//
//
void
TOcView::EvResize()
{
  if (BDocumentI)
    BDocumentI->OnResize();
}

//
// View is shuting down
//
void
TOcView::EvClose()
{
  // Release the data provider object
  //
  if (OcData) {
    OcData->Disconnect();
    OcData = 0;
  }

  if (BContainer && BDocument && BDocumentI) {
    // Unregisters drag target
    //
    BDocumentI->OnClose();

    // Unregisters moniker for this container
    //
    if (BLDocumentI)
      BLDocumentI->OnRename(0, 0);
  }
}

//
// View is activated/deactivated
//
void
TOcView::EvActivate(bool activate)
{
  // Set the current active document
  //
  if (BDocumentI)
    BDocumentI->OnActivate(activate);
  if (activate)
    OcDocument.SetActiveView(this);
}

//
// Returns true if view keeps focus, false if the inplace server got it
//
bool
TOcView::EvSetFocus(bool set)
{
  if (BDocumentI)
    BDocumentI->OnSetFocus(set);

  return OcApp.EvSetFocus(set);
}

//
//
//
bool
TOcView::EnumLinks(IBLinkInfo far* far* linkInfo)
{
  PRECONDITION(linkInfo);

  return BDocumentI ? HRSucceeded(BDocumentI->EnumLinks(linkInfo)) : false;
}

//
//
//
bool
TOcView::BrowseLinks()
{
  return BDocumentI ? HRSucceeded(BDocumentI->BrowseLinks()) : false;
}

//
//
//
bool
TOcView::UpdateLinks()
{
  return BDocumentI ? HRSucceeded(BDocumentI->UpdateLinks()) : false;
}

//
//
//
void
TOcView::Rename()
{
  if (!BLDocumentI || OcDocument.GetName().is_null())
    return;

  // update the file moniker
  //
  BLDocumentI->OnRename(0, OleStr(OcDocument.GetName().c_str()));

  OcDocument.RenameParts(BLDocumentI);
}

//----------------------------------------------------------------------------

//
// Return the client rect for the view window
//
TRect
TOcView::GetWindowRect() const
{
  TRect r;
  const_cast<TOcView*>(this)->GetWindowRect(&r);
  return r;
}

//
// Scroll this container window a give dx,dy
//
void
TOcView::ScrollWindow(int dx, int dy)
{
  Origin += TPoint(dx, dy);
}

void
TOcView::InvalidatePart(TOcPartChangeInfo& changeInfo)
{
  if (changeInfo.GetPart()) {
    CHECK(ContainerHost);
    if (!ContainerHost->EvOcPartInvalid(changeInfo))
      ::InvalidateRect(GetWindow(),
                       &(changeInfo.GetPart()->GetRect() - *(TSize*)&GetOrigin()),
                       true);
  }
}

//
// Activate a given part
//
bool
TOcView::ActivatePart(TOcPart* part)
{
  if (part == ActivePart)
    return true;

  if (ActivePart && ActivePart->IsActive()) {
    ActivePart->Activate(false);
    ActivePart = 0;
  }
  if (part) {
    if (!part->IsActive() && !part->Activate(true))
      return false;
    ActivePart = part;
  }
  return true;
}

/*
//
//
//
uint32
TOcView::ForwardEvent(int eventId, const void far* param)
{
  return ::SendMessage(GetWindow(), WM_OCEVENT, eventId, (LPARAM)param);
}

//
//
//
uint32
TOcView::ForwardEvent(int eventId, uint32 param)
{
  return ::SendMessage(GetWindow(), WM_OCEVENT, eventId, param);
}
*/

//----------------------------------------------------------------------------
// IBContains implementation

//
// Ask the container to load document named 'path'
//
HRESULT _IFUNC
TOcView::Init(LPCOLESTR path)
{
  CHECK(ContainerHost);
  bool result = ContainerHost->EvOcViewOpenDoc(OleStr(path));
  if (result) {

    // Register this document in running object table
    //
    OcDocument.SetName(string(OleStr(path)));
    Rename();
  }

  return HRFailIfZero(result);
}

//
//
//
HRESULT _IFUNC
TOcView::GetPart(IBPart far* far* bpart, LPCOLESTR name)
{
  PRECONDITION(bpart);

  for (TOcPartCollectionIter i(OcDocument.GetParts()); i; i++) {
    TOcPart* ocPart = (TOcPart*)i.Current();
    if (ocPart && strcmp(ocPart->GetName(), OleStr(name)) == 0) {
      ocPart->FinishLoading();  // In case the part hasn't been loaded
      if (SUCCEEDED(ocPart->QueryInterface(IID_IBPart, (LPVOID*)bpart))) {
        return HR_NOERROR;      // Now there is one more refcount on ocPart
      }
    }
  }

  // Ask the document whether an TOcLinkView corresponding to the item name
  // already exists. Create one automatically if needed & let host know.
  //
  TOcLinkView* ocLinkView = GetDocLink(OleStr(name));

  if (ocLinkView) {
    if (SUCCEEDED(ocLinkView->QueryInterface(IID_IBPart, (LPVOID*)bpart)))
      return HR_NOERROR; // Now there is one more refcount on ocRemView 
    else
      return HR_FAIL;  // This should never happen--its our own link view...
  }

  return HR_FAIL;
}

//----------------------------------------------------------------------------
// IBDataNegotiator implementation

//
// Format count
//
uint _IFUNC
TOcView::CountFormats()
{
  return FormatList.Count();
}

//
// Format retrieval
//
HRESULT _IFUNC
TOcView::GetFormat(uint index, TOcFormatInfo far* fmt)
{
  PRECONDITION(fmt);

  // Link source is FormatList[0]
  // Link source will be the first format returned if Link is 0
  // Link source will be the last format returned if Link is -1
  //
  index = (index - LinkFormat) % CountFormats();
  FormatList[index]->GetFormatInfo(*fmt);
  return HR_NOERROR;
}

//----------------------------------------------------------------------------
// IBWindow implementation

//
//
//
HWND _IFUNC
TOcView::GetWindow()
{
  return ContainerHost->EvOcGetWindow();
}

//
//
//
HRESULT _IFUNC
TOcView::GetWindowRect(TRect far* r)
{
  PRECONDITION(r);

  ::GetClientRect(GetWindow(), r);
  return HR_NOERROR;
}

//
//
//
LPCOLESTR _IFUNC
TOcView::GetWindowTitle()
{
  // Delegate to app's view window to get its title
  //
  OrgTitle = ContainerHost->EvOcViewTitle();
  return (LPCOLESTR)OrgTitle;
}

//
// Append server's doc title info to our view's window title
//
void _IFUNC
TOcView::AppendWindowTitle(LPCOLESTR title)
{
  WinTitle = (const char far*)OleStr(GetWindowTitle());
  char in[32];
  ::LoadString(_hInstance, IDS_IN, in, sizeof in);

  string newTitle = (const char far*)OleStr(title);
  newTitle += in;
  newTitle += WinTitle;

  ContainerHost->EvOcViewSetTitle(newTitle.c_str());
}

//
//
//
HRESULT _IFUNC
TOcView::SetStatusText(LPCOLESTR /*text*/)
{
  return HR_FAIL;  // Not called on BOle sites
}

//
//
//
HRESULT _IFUNC
TOcView::RequestBorderSpace(const TRect far* space)
{
  PRECONDITION(space);

  // Let individual views decide this
  //
  return HRFailIfZero(ContainerHost->EvOcViewBorderSpaceReq(space));
}

//
//
//
HRESULT _IFUNC
TOcView::SetBorderSpace(const TRect far* space)
{
  PRECONDITION(space);

  // Let individual views do this
  //
  return HRFailIfZero(ContainerHost->EvOcViewBorderSpaceSet(space));
}

//
//
//
HRESULT _IFUNC
TOcView::InsertContainerMenus(HMENU, TOcMenuWidths far*)
{
  return HR_FAIL;  
}

//
//
//
HRESULT _IFUNC
TOcView::SetFrameMenu(HMENU)
{
  return HR_FAIL;  
}

//
// The in-place server is done. Tell the container to restore its normal UI.
//
void _IFUNC
TOcView::RestoreUI()
{
  ContainerHost->EvOcViewSetTitle(WinTitle.c_str());
}

//
//
//
HRESULT _IFUNC
TOcView::Accelerator(MSG far*)
{
  return HR_FAIL;  
}

//
//
//
HRESULT _IFUNC
TOcView::GetAccelerators(HACCEL far*, int far*)
{
  return HR_FAIL;  
}

//----------------------------------------------------------------------------
// IBDropDest implementation

//
// Drop a part onto this view. Creates the part based on initInfo, activating
// it as appropriate
//
HRESULT _IFUNC
TOcView::Drop(TOcInitInfo far* initInfo, TPoint far* where, const TRect far* objPos)
{
  PRECONDITION(initInfo && where && objPos);

  initInfo->Container = this;
  TPoint awhere(*where);
  TRect  aobjPos(*objPos);
  TOcDragDrop dd = {
    (TOcInitInfo far*)initInfo, &awhere, &aobjPos
  };

  if (PasteNative((TOcInitInfo&)*initInfo, where))
    return HR_NOERROR;

  // Make sure that the view will accept this drop
  //
  if (!ContainerHost->EvOcViewDrop(dd))
   return HR_FAIL;

  // Create part now that view approved. BDocument calls AddSite on all views.
  //
  try {
    new TOcPart(OcDocument, *dd.InitInfo, aobjPos);
  }
  catch (...) {
    return HR_FAIL;
  }

  Rename();

  return HR_NOERROR;
}

//
// Provide feedback to the users drag action in our container window
//
void _IFUNC
TOcView::DragFeedback(TPoint far* where, const TRect far* objPos, TOcMouseAction /*action*/, uint, HRESULT& hr)
{
  PRECONDITION(where && objPos);

  TPoint awhere(*where);
  TRect  aobjPos(*objPos);
  TOcDragDrop dd = { 0, &awhere, &aobjPos };

  hr = HRFailIfZero(ContainerHost->EvOcViewDrag(dd));
}

//
// Ask the container view window to scroll itself in a given direction. Asked
// by the server when dragging or working in a clipped site.
//
HRESULT _IFUNC
TOcView::Scroll(TOcScrollDir scrollDir)
{
  // Have the real view do the work here.
  //
  if (!ContainerHost->EvOcViewScroll(scrollDir))
    return HR_FALSE;
  return HR_NOERROR;
}

//
//
//
HRESULT _IFUNC
TOcView::GetScrollRect(TRect far*)
{
  return HR_NOERROR;
}

//----------------------------------------------------------------------------
// IBContainer implementation

//
// Locate the drop destination object. For default OC, it is just this view.
// Other extensions might have subtargets within the view.
//
HRESULT _IFUNC
TOcView::FindDropDest(TPoint far*, IBDropDest far* far* dropDest)
{
  *dropDest = this;
  return HR_NOERROR;
}

//
//
//
HRESULT _IFUNC
TOcView::BringToFront()
{
  // See if we are in an MDI child & if so activate it
  //
  HWND hMdiChild = ::GetParent(GetWindow());
  if (hMdiChild) {
    HWND hMdiClient = ::GetParent(hMdiChild);
    if (hMdiClient) {
      HWND hMdiFrame = ::GetParent(hMdiClient);
      while (::GetParent(hMdiFrame)) {
        hMdiChild = hMdiClient;
        hMdiClient = hMdiFrame;
        hMdiFrame = ::GetParent(hMdiFrame);
      }
      ::SendMessage(hMdiClient, WM_MDIACTIVATE, (WPARAM)hMdiChild, 0);
    }
  }

  // Bring our app frame to the top, show it & give it focus. Also make sure
  // that this view is on top & visible
  //
  ::SetWindowPos(OcApp.GetWindow(), HWND_TOP, 0, 0, 0, 0,
                 SWP_NOMOVE|SWP_NOSIZE | SWP_SHOWWINDOW);
  ::SetFocus(OcApp.GetWindow());
  ::ShowWindow(GetWindow(), SW_SHOWNORMAL);
  ::SetWindowPos(GetWindow(), HWND_TOP, 0, 0, 0, 0,
                 SWP_NOMOVE|SWP_NOSIZE | SWP_SHOWWINDOW); // why force a show window?

  return HR_NOERROR;
}

//
//
//
HRESULT _IFUNC
TOcView::AllowInPlace()
{
  if (IsOptionSet(voNoInPlace))
    return HR_FALSE;
  else
    return HR_NOERROR;
}

//----------------------------------------------------------------------------
// Clipboard related

//
// Register the clipboard formats supported
//
bool
TOcView::RegisterClipFormats(TRegList& regList)
{
  // Register link source first
  //
  uint cfLinkSource = ::RegisterClipboardFormat("Link Source");
  if (cfLinkSource)
    FormatList.Add(new TOcFormat(cfLinkSource, "%s", "%s",
                                 4 /*BOLE_MED_STREAM*/, true));

  char  key[32];
  char  val[128];
  char* buf;
  uint  i = 0;
  bool  succ = true;

  while (true) {
    wsprintf(key, "format%d", i);
    buf = const_cast<char*>(regList[key]);
    if (!buf)
      break;
    else {
      // parse the value string
      //
      strcpy(val, buf);
      buf = val;

      TOcFormat* format = new TOcFormat;

      for (int i = 0; i < 3; i++) {
        char* current = strchr(buf, ',');
        if (!current) {
          succ = false;
          break; // error
        }

        *current = 0;
        switch (i) {
          case 0: // Format id or name
            if (isdigit(*buf)) {
              uint id = atoi(buf);
              format->SetFormatId(id);
              format->SetFormatName(id - 1, OcApp);
            }
            else { // register the user defined clipboard format
              uint cf = ::RegisterClipboardFormat(buf);
              if (cf == cfLinkSource)
                format->SetLinkable();

              format->SetFormatId(cf);
              format->SetFormatName(buf, OcApp);
            }
            break;

          case 1: // Aspect
            format->SetAspect((uint)atoi(buf));
            break;

          case 2:
            format->SetMedium((uint)atoi(buf)); // Storage medium
            format->SetDirection((uint)atoi(current+1)); // Direction
            break;
        } // switch

        buf = current + 1;
      } // for

      if (succ)
        FormatList.Add(format); // Add to the format list
      else
        delete format;
    } // else

    i++;
  } // while

  return succ;
}

//
//
//
bool
TOcView::BrowseClipboard(TOcInitInfo& initInfo)
{
  return OcApp.BrowseClipboard(initInfo);
}

//
// Paste native data into the container
//
bool
TOcView::PasteNative(TOcInitInfo& init, TPoint far* where)
{
  bool result = false;
  if (init.Where == iwHandle && init.How == ihEmbed) {  // Could be native data
    TOcFormat* format = FormatList.Find(init.Handle.DataFormat);
    if (!format) {
      return false;  // Not my native data
    }

    TOcFormatData formatData(*format, 0, init.Handle.Data, true, where);
    result = ServerHost->EvOcViewClipData(formatData);
    if (result)
      init.ReleaseDataObject();
  }

  return result;
}

//
//
//
bool
TOcView::Paste(bool linking)
{
  LinkFormat = linking ? 0 : -1;  // Whether or not to accept a link format
  TOcInitInfo init(this);
  bool result = OcApp.Paste(init);

  if (result) {
    result = PasteNative(init);
    if (!result)
      result = ContainerHost->EvOcViewPasteObject(init);
  }

  return result;
}

//-----------------------------------------------------------------------------
// TOcFormat
//

//
//
//
TOcFormat::TOcFormat()
{
  char fstr[] = "%s";

  Id = 0;
  RegName[0] = 0;
  strcpy(Name, fstr);
  strcpy(ResultName, fstr);
  Medium     = ocrNull;
  IsLinkable = false;
  Aspect     = 1;  // content
  Direction  = 1;  // get
}

//
//
//
TOcFormat::TOcFormat(uint id, char far* name, char far* resultName,
                     uint medium, bool isLinkable,
                     uint aspect, uint direction)
{
  Id         = (WORD)id;
  Medium     = (ocrMedium)medium;
  IsLinkable = isLinkable;
  Aspect     = aspect;
  Direction  = direction;

  RegName[0] = 0;
  strcpy(Name, name);
  strcpy(ResultName, resultName);
}

//
//
//
void
TOcFormat::operator =(const TOcFormatInfo& f)
{
  Id = f.Id;
  strcpy(Name, OleStr(f.Name));
  strcpy(ResultName, OleStr(f.ResultName));
  Medium = f.Medium;
  IsLinkable = f.IsLinkable;
}

//
//
//
void
TOcFormat::GetFormatInfo(TOcFormatInfo far& f)
{
  f.Id = uint16(Id);
#if defined(BI_OLECHAR_WIDE)
//  lstrcpyW(f.Name, OleStr(Name));
  memcpy(f.Name, (LPCWSTR)OleStr(Name), (strlen(Name)+1)*2);
// lstrcpyW(f.ResultName, OleStr(ResultName));
  memcpy(f.ResultName, (LPCWSTR)OleStr(ResultName), (strlen(ResultName)+1)*2);
#else
  strncpy(f.Name, Name, sizeof Name);
  strncpy(f.ResultName, ResultName, sizeof ResultName);
#endif
  f.Medium = (ocrMedium)Medium;
  f.IsLinkable = (BOOL)IsLinkable;
}

//
//
//
void
TOcFormat::SetFormatName(char far* name, TOcApp& ocApp)
{
  TOcFormatName* formatName = ocApp.GetNameList()[name];
  if (!formatName)
    return;

  strcpy(RegName, name);
  strcpy(Name, formatName->GetName());
  strcpy(ResultName, formatName->GetResultName());
}

//
//
//
void
TOcFormat::SetFormatName(uint id, TOcApp& ocApp)
{
  TOcFormatName* formatName = ocApp.GetNameList()[id];
  if (!formatName)
    return;

  strcpy(Name, formatName->GetName());
  strcpy(ResultName, formatName->GetResultName());
}


//----------------------------------------------------------------------------
// TOcFormatList
//

//
//
//
TOcFormatList::TOcFormatList()
:
  TICVectorImp<TOcFormat>(10, 0)
{
}

//
//
//
TOcFormatList::~TOcFormatList()
{
  Clear();
}

//
//
//
TOcFormat*
TOcFormatList::Find(uint const id) const
{
  for (TOcFormatListIter j(*this); j; j++) {
    TOcFormat* format = (TOcFormat*)j.Current();
    if (format && format->GetFormatId() == id) {
      return format;
    }
  }

  return 0;
}


//----------------------------------------------------------------------------
// TOcSiteRect
//

TOcSiteRect::TOcSiteRect()
:
  Rect(0,0,0,0), Part(0)
{
}

TOcSiteRect::TOcSiteRect(TOcPart *part, const TRect& rect)
:
  Rect(rect), Part(part)
{
}

//----------------------------------------------------------------------------
// TOcScaleFactor
//

//
//
//
TOcScaleFactor::TOcScaleFactor()
:
  SiteSize(1, 1),
  PartSize(1, 1)
{
}

//
//
//
TOcScaleFactor::TOcScaleFactor(const TRect& siteRect, const TSize& partSize)
{
  SiteSize.cx = siteRect.Width();
  SiteSize.cy = siteRect.Height();

  PartSize = partSize;
}

//
//
//
TOcScaleFactor::TOcScaleFactor(const TOcScaleInfo far& scale)
{
  *this = scale;
}

//
// Assign a BOle structure to this scale factor
//
TOcScaleFactor&
TOcScaleFactor::operator =(const TOcScaleInfo far& scaleInfo)
{
  SiteSize.cx = (int)scaleInfo.xN;
  SiteSize.cy = (int)scaleInfo.yN;
  PartSize.cx = (int)scaleInfo.xD;
  PartSize.cy = (int)scaleInfo.yD;

  return *this;
}

//
// Assign one TOcScaleFactor to another
//
TOcScaleFactor&
TOcScaleFactor::operator =(const TOcScaleFactor& scaleFactor)
{
  SiteSize = scaleFactor.SiteSize;
  PartSize = scaleFactor.PartSize;

  return *this;
}

//
// Copy a BOle scale factor structure
//
void
TOcScaleFactor::GetScaleFactor(TOcScaleInfo far& scaleInfo) const
{
  scaleInfo.xN = SiteSize.cx;
  scaleInfo.yN = SiteSize.cy;
  scaleInfo.xD = PartSize.cx;
  scaleInfo.yD = PartSize.cy;
}

//
// Whether there is zoom factor
//
bool
TOcScaleFactor::IsZoomed()
{
  return SiteSize != PartSize;
}

//
// Change the scaling factor
//
void
TOcScaleFactor::SetScale(uint16 percent)
{
  PartSize.cx = PartSize.cy = 100;
  SiteSize.cx = SiteSize.cy = percent;
}

//
// Get the scale percentage
//
uint16
TOcScaleFactor::GetScale()
{
  return (uint16)(((uint32)SiteSize.cx * 100 + (PartSize.cx >> 1)) / PartSize.cx);
}

//
// Set scaling factor to 1
//
void
TOcScaleFactor::Reset()
{
  PartSize.cx = PartSize.cy = 1;
  SiteSize.cx = SiteSize.cy = 1;
}

//----------------------------------------------------------------------------

bool
TOcContainerHostMsg::EvOcViewOpenDoc(const char far* path)
{
  return (bool)ForwardEvent(OC_VIEWOPENDOC, path);
}

const char far*
TOcContainerHostMsg::EvOcViewTitle()
{
  return (const char far*)ForwardEvent(OC_VIEWTITLE);
}

void
TOcContainerHostMsg::EvOcViewSetTitle(const char far* title)
{
  ForwardEvent(OC_VIEWSETTITLE, title);
}

bool
TOcContainerHostMsg::EvOcViewBorderSpaceReq(const TRect far* space)
{
  return (bool)ForwardEvent(OC_VIEWBORDERSPACEREQ, space);
}

bool
TOcContainerHostMsg::EvOcViewBorderSpaceSet(const TRect far* space)
{
  return (bool)ForwardEvent(OC_VIEWBORDERSPACESET, space);
}

bool
TOcContainerHostMsg::EvOcViewDrag(TOcDragDrop far& ddInfo)
{
  return (bool)ForwardEvent(OC_VIEWDRAG, &ddInfo);
}

bool
TOcContainerHostMsg::EvOcViewDrop(TOcDragDrop far& ddInfo)
{
  return (bool)ForwardEvent(OC_VIEWDROP, &ddInfo);
}

bool
TOcContainerHostMsg::EvOcViewScroll(TOcScrollDir scrollDir)
{
  return (bool)ForwardEvent(OC_VIEWSCROLL, scrollDir);
}

bool
TOcContainerHostMsg::EvOcPartInvalid(TOcPartChangeInfo& changeInfo)
{
  return (bool)ForwardEvent(OC_VIEWPARTINVALID, &changeInfo);
}

bool
TOcContainerHostMsg::EvOcViewPasteObject(TOcInitInfo& init)
{
  return (bool)ForwardEvent(OC_VIEWPASTEOBJECT, &init);
}

bool
TOcContainerHostMsg::EvOcViewGetSiteRect(TOcSiteRect& sr)
{
  return (bool)ForwardEvent(OC_VIEWGETSITERECT, &sr);
}

bool
TOcContainerHostMsg::EvOcViewSetSiteRect(TOcSiteRect& sr)
{
  return (bool)ForwardEvent(OC_VIEWSETSITERECT, &sr);
}

bool
TOcContainerHostMsg::EvOcViewPartActivate(TOcPart& ocPart)
{
  return (bool)ForwardEvent(OC_VIEWPARTACTIVATE, &ocPart);
}

bool
TOcContainerHostMsg::EvOcViewGetScale(TOcScaleFactor& scaleFactor)
{
  return (bool)ForwardEvent(OC_VIEWGETSCALE, &scaleFactor);
}

//
//
//
uint32
TOcContainerHostMsg::ForwardEvent(int eventId, const void far* param)
{
  return ::SendMessage(EvOcGetWindow(), WM_OCEVENT, eventId, (LPARAM)param);
}

//
//
//
uint32
TOcContainerHostMsg::ForwardEvent(int eventId, uint32 param)
{
  return ::SendMessage(EvOcGetWindow(), WM_OCEVENT, eventId, param);
}

//----------------------------------------------------------------------------

bool
TOcServerHostMsg::EvOcViewGetItemName(TOcItemName& item)
{
  return (bool)ForwardEvent(OC_VIEWGETITEMNAME, &item);
}

bool
TOcServerHostMsg::EvOcViewClipData(TOcFormatData far& formatData)
{
  return (bool)ForwardEvent(OC_VIEWCLIPDATA, &formatData);
}

bool
TOcServerHostMsg::EvOcViewSetData(TOcFormatData far& formatData)
{
  return (bool)ForwardEvent(OC_VIEWSETDATA, &formatData);
}

bool
TOcServerHostMsg::EvOcViewPartSize(TOcPartSize far& ps)
{
  return (bool)ForwardEvent(OC_VIEWPARTSIZE, &ps);
}

bool
TOcServerHostMsg::EvOcViewSavePart(TOcSaveLoad far& ocSave)
{
  return (bool)ForwardEvent(OC_VIEWSAVEPART, &ocSave);
}

bool
TOcServerHostMsg::EvOcViewPaint(TOcViewPaint far& vp)
{
  return (bool)ForwardEvent(OC_VIEWPAINT, &vp);
}

bool
TOcServerHostMsg::EvOcViewAttachWindow(bool attach)
{
  return (bool)ForwardEvent(OC_VIEWATTACHWINDOW, attach);
}

void
TOcServerHostMsg::EvOcViewSetTitle(const char far* title)
{
  ForwardEvent(OC_VIEWSETTITLE, title);
}

bool
TOcServerHostMsg::EvOcViewDrag(TOcDragDrop far& ddInfo)
{
  return (bool)ForwardEvent(OC_VIEWDRAG, &ddInfo);
}

bool
TOcServerHostMsg::EvOcViewSetLink(TOcLinkView& linkView)
{
  return (bool)ForwardEvent(OC_VIEWSETLINK, &linkView);
}

bool
TOcServerHostMsg::EvOcViewBreakLink(TOcLinkView& linkView)
{
  return (bool)ForwardEvent(OC_VIEWBREAKLINK, &linkView);
}

bool
TOcServerHostMsg::EvOcViewGetPalette(LOGPALETTE far* far* palette)
{
  return (bool)ForwardEvent(OC_VIEWGETPALETTE, palette);
}

bool
TOcServerHostMsg::EvOcViewLoadPart(TOcSaveLoad far& ocLoad)
{
  return (bool)ForwardEvent(OC_VIEWLOADPART, &ocLoad);
}

bool
TOcServerHostMsg::EvOcViewInsMenus(TOcMenuDescr far& sharedMenu)
{
  return (bool)ForwardEvent(OC_VIEWINSMENUS, &sharedMenu);
}

bool
TOcServerHostMsg::EvOcViewShowTools(TOcToolBarInfo far& tbi)
{
  return (bool)ForwardEvent(OC_VIEWSHOWTOOLS, &tbi);
}

bool
TOcServerHostMsg::EvOcViewClose()
{
  return (bool)ForwardEvent(OC_VIEWCLOSE);
}

bool
TOcServerHostMsg::EvOcViewSetScale(TOcScaleFactor& scaleFactor)
{
  return (bool)ForwardEvent(OC_VIEWSETSCALE, &scaleFactor);
}

bool
TOcServerHostMsg::EvOcViewDoVerb(uint verb)
{
  return (bool)ForwardEvent(OC_VIEWDOVERB, verb);
}

//
//
//
uint32
TOcServerHostMsg::ForwardEvent(int eventId, const void far* param)
{
  return ::SendMessage(EvOcGetWindow(), WM_OCEVENT, eventId, (LPARAM)param);
}

//
//
//
uint32
TOcServerHostMsg::ForwardEvent(int eventId, uint32 param)
{
  return ::SendMessage(EvOcGetWindow(), WM_OCEVENT, eventId, param);
}
