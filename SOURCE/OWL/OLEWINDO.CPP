//----------------------------------------------------------------------------
// ObjectWindows
// Copyright (c) 1994, 1996 by Borland International, All Rights Reserved
//
//$Revision:   10.14  $
//
// Implementation of TOleWindow. Window class that supports OLE 2
// container & server using OCF TOcView & TOcRemView
//----------------------------------------------------------------------------
#define INC_OLE2
#include <owl/pch.h>
#if !defined(OWL_WINDOW_H)
# include <owl/window.h>
#endif
#if !defined(OWL_GDIOBJEC_H)
# include <owl/gdiobjec.h>
#endif
#if !defined(OWL_SCROLLER_H)
# include <owl/scroller.h>
#endif
#if !defined(OCF_OCDOC_H)
# include <ocf/ocdoc.h>
#endif
#if !defined(OCF_OCVIEW_H)
# include <ocf/ocview.h>
#endif
#if !defined(OCF_OCCTRL_H)
# include <ocf/occtrl.h>
#endif
#if !defined(OWL_OLEFRAME_H)
# include <owl/oleframe.h>
#endif
#if !defined(OWL_OLEWINDO_H)
# include <owl/olewindo.h>
#endif
#if !defined(WINSYS_UIMETRIC_H)
# include <winsys/uimetric.h>
#endif
#include <owl/edit.rh>
#include <owl/docview.rh>
#include <owl/oleview.rh>

DIAG_DECLARE_GROUP(OwlCmd);

//----------------------------------------------------------------------------
// Size of rectangle in two clks must occur to be a doubleClick
// ---- moved in StartDrag ----
//#if !defined(BI_PLAT_WIN32)
//  TSize DblClkDelta(3, 3);
//#else
//  TSize DblClkDelta(TUIMetric::CxDoubleClk/2,
//                    TUIMetric::CyDoubleClk/2);
//#endif


//----------------------------------------------------------------------------
// TOleClientDC
//

//
//
//
TOleClientDC::TOleClientDC(TOleWindow& win, bool scale)
:
  TClientDC(win)
{
  win.SetupDC(*this, scale);
}

//----------------------------------------------------------------------------
// TOleWindow
//

DEFINE_RESPONSE_TABLE1(TOleWindow, TWindow)
  EV_WM_PAINT,
  EV_WM_LBUTTONDOWN,
  EV_WM_RBUTTONDOWN,
  EV_WM_LBUTTONDBLCLK,
  EV_WM_MOUSEMOVE,
  EV_WM_LBUTTONUP,
  EV_WM_SIZE,
  EV_WM_MDIACTIVATE,
  EV_WM_MOUSEACTIVATE,
  EV_WM_SETFOCUS,
  EV_WM_SETCURSOR,
  EV_WM_DROPFILES,
  EV_WM_VSCROLL,
  EV_WM_HSCROLL,
  EV_WM_MENUSELECT,

  EV_COMMAND_ENABLE(CM_FILECLOSE, CeFileClose),

  EV_COMMAND(CM_EDITDELETE, CmEditDelete),
  EV_COMMAND_ENABLE(CM_EDITDELETE, CeEditDelete),
  EV_COMMAND(CM_EDITCUT, CmEditCut),
  EV_COMMAND_ENABLE(CM_EDITCUT, CeEditCut),
  EV_COMMAND(CM_EDITCOPY, CmEditCopy),
  EV_COMMAND_ENABLE(CM_EDITCOPY, CeEditCopy),
  EV_COMMAND(CM_EDITPASTE, CmEditPaste),
  EV_COMMAND_ENABLE(CM_EDITPASTE, CeEditPaste),
  EV_COMMAND(CM_EDITPASTESPECIAL, CmEditPasteSpecial),
  EV_COMMAND_ENABLE(CM_EDITPASTESPECIAL, CeEditPasteSpecial),
  EV_COMMAND(CM_EDITPASTELINK, CmEditPasteLink),
  EV_COMMAND_ENABLE(CM_EDITPASTELINK, CeEditPasteLink),
  EV_COMMAND(CM_EDITINSERTOBJECT, CmEditInsertObject),
  EV_COMMAND(CM_EDITINSERTCONTROL, CmEditInsertControl),
  EV_COMMAND_ENABLE(CM_EDITINSERTOBJECT, CeEditInsertObject),
  EV_COMMAND_ENABLE(CM_EDITINSERTCONTROL, CeEditInsertControl),
  EV_COMMAND_ENABLE(CM_EDITLINKS, CeEditLinks),
  EV_COMMAND(CM_EDITLINKS, CmEditLinks),
  EV_COMMAND_ENABLE(CM_EDITOBJECT, CeEditObject),
  EV_COMMAND_ENABLE(CM_EDITCONVERT, CeEditConvert),
  EV_COMMAND(CM_EDITCONVERT, CmEditConvert),
  EV_COMMAND_ENABLE(CM_EDITSHOWOBJECTS, CeEditShowObjects),
  EV_COMMAND(CM_EDITSHOWOBJECTS, CmEditShowObjects),

  EV_MESSAGE(WM_OCEVENT, EvOcEvent),
//  EV_OC_VIEWDISCARDUNDO,  

  // Container specific messages
  //
  EV_OC_VIEWPARTINVALID,
  EV_OC_VIEWTITLE,
  EV_OC_VIEWSETTITLE,
  EV_OC_VIEWBORDERSPACEREQ,
  EV_OC_VIEWBORDERSPACESET,
  EV_OC_VIEWDROP,
  EV_OC_VIEWDRAG,
  EV_OC_VIEWSCROLL,
  EV_OC_VIEWGETSCALE,
  EV_OC_VIEWGETSITERECT,
  EV_OC_VIEWSETSITERECT,
  EV_OC_VIEWPARTACTIVATE,
  EV_OC_VIEWPASTEOBJECT,

  // Server specific messages
  //
  EV_OC_VIEWPAINT,
  EV_OC_VIEWSAVEPART,
  EV_OC_VIEWLOADPART,
  EV_OC_VIEWINSMENUS,
  EV_OC_VIEWSHOWTOOLS,
  EV_OC_VIEWGETPALETTE,
  EV_OC_VIEWCLIPDATA,
  EV_OC_VIEWSETDATA,
  EV_OC_VIEWCLOSE,
  EV_OC_VIEWPARTSIZE,
  EV_OC_VIEWOPENDOC,
  EV_OC_VIEWATTACHWINDOW,
  EV_OC_VIEWSETSCALE,
  EV_OC_VIEWGETITEMNAME,
  EV_OC_VIEWSETLINK,
  EV_OC_VIEWBREAKLINK,
  EV_OC_VIEWDOVERB,

  // Ambient properties
  //
  EV_OC_AMBIENT_GETBACKCOLOR,
  EV_OC_AMBIENT_GETFORECOLOR,
  EV_OC_AMBIENT_GETLOCALEID,
  EV_OC_AMBIENT_GETTEXTALIGN,
  EV_OC_AMBIENT_GETMESSAGEREFLECT,
  EV_OC_AMBIENT_GETUSERMODE,
  EV_OC_AMBIENT_GETUIDEAD,
  EV_OC_AMBIENT_GETSHOWGRABHANDLES,
  EV_OC_AMBIENT_GETSHOWHATCHING,
  EV_OC_AMBIENT_GETDISPLAYASDEFAULT,
  EV_OC_AMBIENT_GETSUPPORTSMNEMONICS,
  EV_OC_AMBIENT_GETDISPLAYNAME,
  EV_OC_AMBIENT_GETSCALEUNITS,
  EV_OC_AMBIENT_GETFONT,
  EV_OC_AMBIENT_SETBACKCOLOR,
  EV_OC_AMBIENT_SETFORECOLOR,
  EV_OC_AMBIENT_SETLOCALEID,
  EV_OC_AMBIENT_SETTEXTALIGN,
  EV_OC_AMBIENT_SETMESSAGEREFLECT,
  EV_OC_AMBIENT_SETUSERMODE,
  EV_OC_AMBIENT_SETUIDEAD,
  EV_OC_AMBIENT_SETSHOWGRABHANDLES,
  EV_OC_AMBIENT_SETSHOWHATCHING,
  EV_OC_AMBIENT_SETDISPLAYASDEFAULT,
  EV_OC_AMBIENT_SETSUPPORTSMNEMONICS,
  EV_OC_AMBIENT_SETDISPLAYNAME,
  EV_OC_AMBIENT_SETSCALEUNITS,
  EV_OC_AMBIENT_SETFONT,

  // Standard Events
  //
  EV_OC_CTRLEVENT_CLICK,
  EV_OC_CTRLEVENT_DBLCLICK,


  // Ctrl events
  //
  EV_OC_CTRLEVENT_CLICK,
  EV_OC_CTRLEVENT_DBLCLICK,
  EV_OC_CTRLEVENT_FOCUS,
  EV_OC_CTRLEVENT_MOUSEDOWN,
  EV_OC_CTRLEVENT_MOUSEMOVE,
  EV_OC_CTRLEVENT_MOUSEUP,
  EV_OC_CTRLEVENT_KEYDOWN,
  EV_OC_CTRLEVENT_KEYUP,
  EV_OC_CTRLEVENT_PROPERTYCHANGE,
  EV_OC_CTRLEVENT_PROPERTYREQUESTEDIT,
  EV_OC_CTRLEVENT_ERROREVENT,
  EV_OC_CTRLEVENT_CUSTOMEVENT,

END_RESPONSE_TABLE;

//
//
//
TOleWindow::TOleWindow(TWindow* parent, TModule* module)
:
  TWindow(parent, 0, module),
  Pos(0, 0, 0, 0),
  Remote(false),
  ShowObjects(false)
{
  // Initialize virtual base, in case the derived-most used default ctor
  //
  TWindow::Init(parent, 0, module);

  // Derived class will need to create a OcDocument object to hold the ole
  // parts that we create and a OcView to provide ole services
  //
  OcApp  = 0;
  OcDoc  = 0;
  OcView = 0;

  Init();
}

//
//
//
void
TOleWindow::Init()
{
  // Clip children to not paint on in-place servers, & clip siblings to not
  // paint on floating tool palettes
  //
  Attr.Style |= WS_CLIPCHILDREN | WS_CLIPSIBLINGS;

  Attr.AccelTable = IDA_OLEVIEW;
  DragHit   = TUIHandle::Outside;
  DragPart  = 0;
  DragDC    = 0;

  // Minimum part size
  //
  HDC dc = GetDC(0);
  MinWidth  = GetDeviceCaps(dc, LOGPIXELSX) / 4;
  MinHeight = GetDeviceCaps(dc, LOGPIXELSY) / 4;
  ReleaseDC(0, dc);

  // Snag the OcApp from the TOleFrame object for quick reference
  //
  TOleFrame* olefr = TYPESAFE_DOWNCAST(GetApplication()->GetMainWindow(), TOleFrame);
  CHECK(olefr);
  OcApp = olefr->GetOcApp();
  OcApp->AddRef();
}

//
//
//
TOleWindow::~TOleWindow()
{
  // Let the OC objects go. They will delete themselves when they can
  // If it's a remote view, then the last release is called by the container.
  //
  if (OcDoc)
    OcDoc->Close();           // close all the embedded parts first
  if (OcView && !IsRemote()) {
    OcView->ReleaseObject();  // use ReleaseObject here to tell it we are gone
    OcView = 0;
  }

  delete OcDoc;
  if (OcApp) {
    OcApp->Release();
    OcApp = 0;
  }
}

//
// Perform normal SetupWindow, plus let the OcView object know our HWND so that
// it can talk to us.
//
void
TOleWindow::SetupWindow()
{
  if (!OcView)
    CreateOcView(0, false, 0);  // don't have much context by this time
  CHECK(OcView);
  TWindow::SetupWindow();
  OcView->SetupWindow(*this, IsRemote());
}

//
// Called to perform the actual setting up of the OcView member
// Derived class needs to construct the TOcView/TOcRemView here & return it
//
TOcView*
TOleWindow::CreateOcView(TRegLink* link, bool isRemote, IUnknown* outer)
{
  if (!OcDoc)
    OcDoc = new TOcDocument(*GetOcApp());

  if (!OcView) {
    TRegList* regList = link ? &link->GetRegList() : 0;

    // Create a remote view on the server document if it embeded, else make a
    // normal, container view
    //
    if (isRemote)
      OcView = new TOcRemView(*GetOcDoc(), regList, outer);
    else
      OcView = new TOcxView(*GetOcDoc(), regList, outer);

    Remote = isRemote;
  }
  return OcView;
}

//
// Handle the command enabling for a range of command IDs for verbs
//
void
TOleWindow::EvCommandEnable(TCommandEnabler& commandEnabler)
{
  if (CM_EDITFIRSTVERB <= commandEnabler.Id && commandEnabler.Id <= CM_EDITLASTVERB) {
    CeEditVerbs(commandEnabler);
  }
  else if (IsRemote()) {
    // Get the focus, in case it is a child that should receive the cmds
    // fall back to this window in case the Ole menu bar stole focus!
    //
    THandle  hCmdTarget = ::GetFocus();
    if (hCmdTarget != GetHandle() && !IsChild(hCmdTarget))
      hCmdTarget = GetHandle();

    RouteCommandEnable(hCmdTarget, commandEnabler);
  }
  else {
    TWindow::EvCommandEnable(commandEnabler);
  }
}

//
// processing a range of command IDs for verbs
//
TResult
TOleWindow::EvCommand(uint id, THandle hCtl, uint notifyCode)
{
#if !defined(_OWLDLL)
  TRACEX(OwlCmd, 1, "TOleWindow::EvCommand - id(" << id << "), ctl(" <<\
                     hex << uint(hCtl) << "), code(" << notifyCode  << ")");
#endif

  if (hCtl == 0) {
    if (CM_EDITFIRSTVERB <= id && id <= CM_EDITLASTVERB) {
      EvDoVerb(id - CM_EDITFIRSTVERB);
      return 0;
    }
  }
  return TWindow::EvCommand(id, hCtl, notifyCode);
}

//
// Intercept CanClose() to interpose OpenEdit semantics. Ole 2 servers don't
// prompt the user on close--just save & close.
//
bool
TOleWindow::CanClose()
{
  // We don't want to close the view for DLL servers
  //
  if (IsOpenEditing() && !OcApp->IsOptionSet(amExeMode)) {
    TOleFrame* olefr = TYPESAFE_DOWNCAST(GetApplication()->GetMainWindow(), TOleFrame);
    CHECK(olefr);
    olefr->ShowWindow(SW_HIDE);
    OleShutDown();
    return false;
  }

  if (GetOcRemView() || TWindow::CanClose()) {
    if (OcDoc)
      OcDoc->Close();
    return true;
  }
  return false;
}

//
// Notify part
//
void
TOleWindow::InvalidatePart(TOcInvalidate invalid)
{
  if (GetOcRemView())
    GetOcRemView()->Invalidate(invalid);
}

//
// Is the window in Open-Edit mode
//
bool
TOleWindow::IsOpenEditing() const
{
  TOcRemView* ocRemView = const_cast<TOleWindow*>(this)->GetOcRemView();
  return ocRemView && ocRemView->GetState() == TOcRemView::OpenEditing;
}

//
// Handles the file File>Close menu option for server app
//
void
TOleWindow::CeFileClose(TCommandEnabler& ce)
{
  // if open editing server, reflect the container's name in "close" option
  //
  if (IsOpenEditing() && GetOcRemView() && GetOcRemView()->GetKind() != TOcRemView::Link) {
    char strCloseMenu[128];
    string optName = GetModule()->LoadString(IDS_CLOSESERVER);
    TString title = GetOcRemView()->GetContainerTitle();
    if (title.Length() > 0) {
      strcpy(strCloseMenu, optName.c_str());
      strcat(strCloseMenu, title);
      //const char far* str = title;
      //optName += str;
    }
    //ce.SetText(optName.c_str());
    ce.SetText(strCloseMenu);
  }
}

//
//
//
void
TOleWindow::CeEditInsertObject(TCommandEnabler& ce)
{
  ce.Enable(OcApp && OcView);
}

//
//
//
void
TOleWindow::CeEditInsertControl(TCommandEnabler& ce)
{
  ce.Enable(OcApp && OcView);
}

//
// Get the insertion point for the embedded object in device units.
// Currently we're using only the top left point for position, size is
// redundant.
//
void
TOleWindow::GetInsertPosition(TRect& rect)
{
  TOleClientDC dc(*this);

  // Default insertion point is at 0.5" away from current viewport origin
  //
  rect.left  = dc.GetDeviceCaps(LOGPIXELSX) / 2;  // in pixels
  rect.top = dc.GetDeviceCaps(LOGPIXELSY) / 2;    // in pixels

  // Adjust the position of embedded object to be in pixels and reflect the
  // zoom factor.
  //
  dc.LPtoDP((TPoint*)&rect, 1);

  // No size yet.
  //
  rect.right = rect.left;
  rect.bottom = rect.top;
}

//
// Insert an OLE object into the view
//
void
TOleWindow::CmEditInsertObject()
{
  PRECONDITION(OcView);
  TOcInitInfo initInfo(OcView);

  if (OcApp->Browse(initInfo)) {
    TRect rect;
    GetInsertPosition(rect);
    TOcPart* part = new TOcPart (*GetOcDoc());
    part->Init(&initInfo, rect);
    SetSelection(part);

    OcView->Rename();
    InvalidatePart(invView);
  }
}

//
// Insert an OLE object into the view
//
void
TOleWindow::CmEditInsertControl()
{
  PRECONDITION(OcView);
  TOcInitInfo initInfo(OcView);

  if (OcApp->BrowseControls(initInfo)) {
    TRect rect;
    GetInsertPosition(rect);
    rect.right  = rect.left + 100;
    rect.bottom = rect.top + 100;
    TOcControl* ctrl = new TOcControl (*GetOcDoc());
    ctrl->Init(&initInfo, rect);
    SetSelection(ctrl);

    OcView->Rename();
    InvalidatePart(invView);
  }
}

void
TOleWindow::CeEditDelete(TCommandEnabler& ce)
{
  ce.Enable(DragPart != 0);
}

//
//
//
void
TOleWindow::CmEditDelete()
{
  if (!DragPart)
    return;

  TOcPartChangeInfo changeInfo(DragPart, TOcInvalidate(invData | invView));
  EvOcViewPartInvalid(changeInfo);

  DragPart->Delete();
  DragPart = 0;
}

//
//
//
void
TOleWindow::CeEditCut(TCommandEnabler& ce)
{
  ce.Enable(DragPart != 0);
}

//
//
//
void
TOleWindow::CmEditCut()
{
  DragPart->Detach();
  OcApp->Copy(DragPart);
  SetSelection(0);
}

//
//
//
void
TOleWindow::CeEditCopy(TCommandEnabler& ce)
{
  ce.Enable(DragPart != 0);
}

//
//
//
void
TOleWindow::CmEditCopy()
{
  if (DragPart)
    OcApp->Copy(DragPart);
}

//
//
//
void
TOleWindow::CeEditPasteLink(TCommandEnabler& ce)
{
  PRECONDITION(OcApp && OcView);
  ce.Enable(OcApp->EnableEditMenu(meEnablePasteLink, OcView));
}

//
//
//
void
TOleWindow::CmEditPasteLink()
{
   OcView->Paste(true);
}

//
//
//
void
TOleWindow::CeEditPaste(TCommandEnabler& ce)
{
  PRECONDITION(OcApp && OcView);
  ce.Enable(OcApp->EnableEditMenu(meEnablePaste, OcView));
}

//
//
//
void
TOleWindow::CmEditPaste()
{
   OcView->Paste(false);
   InvalidatePart(invView);
}

//
//
//
void
TOleWindow::CeEditPasteSpecial(TCommandEnabler& ce)
{
  PRECONDITION(OcApp && OcView);
  ce.Enable(OcApp->EnableEditMenu(meEnableBrowseClipboard, OcView));
}

//
//
//
void
TOleWindow::CmEditPasteSpecial()
{
  TOcInitInfo initInfo(GetOcView());

  if (GetOcView()->BrowseClipboard(initInfo)) {
    if (!OcView->PasteNative(initInfo)) { // Not native data
      EvOcViewPasteObject(initInfo);
    }
    InvalidatePart(invView);
  }
}

//
// Append the object menu and enable it
//
void
TOleWindow::CeEditObject(TCommandEnabler& ce)
{
  // Downcast to get at submenu item
  //
  TMenuItemEnabler* me = TYPESAFE_DOWNCAST(&ce, TMenuItemEnabler);
  if (!me)
    return;

  int verbPos = me->GetPosition(); // remember the verb menu position
  TMenu editMenu(me->GetMenu());

  string optName = GetModule()->LoadString(IDS_EDITOBJECT);
  if (!DragPart) {
    // Remove the verb menu, if any
    //
    if (editMenu.GetSubMenu(verbPos)) {
      editMenu.DeleteMenu(verbPos, MF_BYPOSITION);
      editMenu.InsertMenu(verbPos, MF_GRAYED | MF_BYPOSITION | MF_STRING,
            CM_EDITOBJECT, optName.c_str());
    }
    ce.Enable(false);
    return;
  }

  // Add verb menu
  //
  TOcVerb ocVerb;
  TMenu* verbMenu = CreateVerbPopup(ocVerb);
  string newMenuName(OleStr(ocVerb.TypeName));
  newMenuName += ' ';
  newMenuName += optName;
  editMenu.ModifyMenu(verbPos, MF_ENABLED | MF_BYPOSITION | MF_POPUP,
                      (uint)verbMenu->GetHandle(), newMenuName.c_str());
  delete verbMenu;
  ce.Enable(true);
}

//
// Command enabler for "Edit" "Convert..." option
//
void
TOleWindow::CeEditConvert(TCommandEnabler& ce)
{
  ce.Enable(DragPart != 0);
}

void
TOleWindow::CmEditConvert()
{
  OcApp->Convert(DragPart, false);
}

//
// Command enabler for "Edit" "Links..." option
//
void
TOleWindow::CeEditLinks(TCommandEnabler& ce)
{
  PRECONDITION(OcApp && OcView);
  ce.Enable(OcApp->EnableEditMenu(meEnableBrowseLinks, OcView));
}

//
//
//
void
TOleWindow::CmEditLinks()
{
  PRECONDITION(OcView);
  OcView->BrowseLinks();
}

//
//
//
void
TOleWindow::CeEditVerbs(TCommandEnabler& ce)
{
  ce.Enable(DragPart != 0);
}

//
//
//
void
TOleWindow::CmEditShowObjects()
{
  ShowObjects = !ShowObjects;
  Invalidate();
}

//
//
//
void
TOleWindow::CeEditShowObjects(TCommandEnabler& ce)
{
  ce.SetCheck(ShowObjects ? TCommandEnabler::Checked : TCommandEnabler::Unchecked);
}

//
// Has in-place active part?
//
bool
TOleWindow::HasActivePart()
{
  return OcView->GetActivePart() != 0;
}

//
// Change cursor shape if within an embedded object
//
bool
TOleWindow::EvSetCursor(THandle hWnd, uint hitTest, uint mouseMsg)
{
  TPoint pt;
  GetCursorPos(pt);
  ScreenToClient(pt);
  TOcPart* p = OcView->GetActivePart();

  if (hitTest == HTCLIENT) {
    if (p) {   // there is an activated part
      TUIHandle handle(p->GetRect(), TUIHandle::Framed);
      if (handle.HitTest(pt) == TUIHandle::MidCenter) {
        return false; // let the inplace server set its cursor shape
      }
      else {   // use arrow cursor
        ::SetCursor(::LoadCursor(0, IDC_ARROW));
        return true;
      }
    }
  }

  // Set cursor for resize when cursor over inactive part
  //
  if (!p && DragPart) {
    TRect rect(DragPart->GetRect());
    TOleClientDC dc(*this);
    dc.LPtoDP((TPoint*)&rect, 2);

    TUIHandle handle(rect, TUIHandle::HandlesIn | TUIHandle::Grapples |
                     TUIHandle::Framed);

    if (handle.HitTest(pt) != TUIHandle::Outside)
      ::SetCursor(::LoadCursor(0, TResId(handle.GetCursorId(handle.HitTest(pt)))));
    else
      ::SetCursor(::LoadCursor(0, IDC_ARROW));

    return true;
  }

  return ShowCursor(hWnd, hitTest, mouseMsg);
}

//
// Show cursor when it's not in an embedded object
//
bool
TOleWindow::ShowCursor(THandle /*hWnd*/, uint /*hitTest*/, uint /*mouseMsg*/)
{
  ::SetCursor(::LoadCursor(0, IDC_ARROW));
  return true;
}

//
// Find out if drag and drop needs to be started
//
bool
TOleWindow::StartDrag(uint modKeys, TPoint& point)
{
	#if !defined(BI_PLAT_WIN32)
	  static TSize DblClkDelta(3, 3);
	#else
	  static TSize DblClkDelta(TUIMetric::CxDoubleClk/2,
	                    TUIMetric::CyDoubleClk/2);
	#endif

  // no part no drag
	if (!DragPart)
  	return false;

  // maybe it was a double click
	if (abs(point.x-DragStart.x) <= DblClkDelta.cx ||
      			abs(point.y-DragStart.y) <= DblClkDelta.cy)
  	return false;

  // start drag and drop anyway if outside client area
  if (!InClient(*DragDC, point))
  	return true;

  // start if ctrl or ctrl-shift is pressed but not if alt since move inside client area
  // doesn't really make sense (a move is a move don't bother ole for that)
	if ((modKeys & MK_CONTROL))
  	return true;

  return false;
}

//
// Accept dropped file from file manager
//
void
TOleWindow::EvDropFiles(TDropInfo dropInfo)
{
  int fileCount = dropInfo.DragQueryFileCount();
  for (int index = 0; index < fileCount; index++) {
    int fileLength = dropInfo.DragQueryFileNameLen(index)+1;
    OLECHAR* filePath = new OLECHAR[fileLength];
    dropInfo.DragQueryFile(index, OleStr(filePath), fileLength);

    TOcInitInfo initInfo(ihEmbed, iwFile, OcView);
    initInfo.Path = filePath;

    TRect rect;
    GetInsertPosition(rect);
    TOcPart* part = new TOcPart (*GetOcDoc());
    part->Init(&initInfo, rect);
    SetSelection(part);

    OcView->Rename();
    InvalidatePart(invView);

    delete[] filePath;
  }
  dropInfo.DragFinish();
}

//
// Handle left double-click message
//
void
TOleWindow::EvLButtonDblClk(uint modKeys, TPoint& point)
{
  PRECONDITION(GetOcDoc() && GetOcView());
  TOleClientDC dc(*this);
  dc.DPtoLP(&point);

  TOcPart* p = GetOcDoc()->GetParts().Locate(point);

  if (modKeys & MK_CONTROL) {
    if (p)
      p->Open(true);  // Ctrl key forces open editing
  }
  else {
    SetSelection(p);

    if (p && p == GetOcView()->GetActivePart()) { // resync the active flag
      p->Activate(false);
    }

    GetOcView()->ActivatePart(p); // In-place activation
  }
}

//
// Set new selection, clear/set handles around objects
//
void
TOleWindow::SetSelection(TOcPart* part)
{
  if (part == DragPart)
    return;

  // Invalidate old part
  //
  TOcPartChangeInfo changeInfo(DragPart, invView);
  if (DragPart) {
    DragPart->Select(false);
    DragPart->Activate(false);
    EvOcViewPartInvalid(changeInfo);
  }

  DragPart = part;
  changeInfo.SetPart(DragPart);
  if (DragPart) {
    part->Select(true); // select this one
    EvOcViewPartInvalid(changeInfo);
  }
}

//
// Create popup menu
//
void
TOleWindow::EvRButtonDown(uint, TPoint& point)
{
  PRECONDITION(GetOcDoc());

  // Perform hit test on parts...
  //
  TPoint oldPoint = point;
  TOleClientDC dc(*this);
  dc.DPtoLP(&point);

  TOcPart* p = GetOcDoc()->GetParts().Locate(point);
  SetSelection(p);

  if (DragPart) {
    // Create popup menu
    //
    TMenu menu(GetModule()->LoadMenu(IDM_OLEPOPUP), AutoDelete);
    TPopupMenu popMenu(menu.GetSubMenu(0));

    if (popMenu.GetHandle()) {
      TOcVerb ocVerb;
      TMenu* verbMenu = CreateVerbPopup(ocVerb);

      string optName = GetModule()->LoadString(IDS_EDITOBJECT);
      string newMenuName(OleStr(ocVerb.TypeName));
      newMenuName += ' ';
      newMenuName += optName;
      popMenu.ModifyMenu(CM_EDITOBJECT, MF_ENABLED | MF_BYCOMMAND | MF_POPUP,
                         (uint)verbMenu->GetHandle(), newMenuName.c_str());
      delete verbMenu;

      // Add the verb menu
      //
      ClientToScreen(oldPoint);

      // Route commands through main window
      //
      popMenu.TrackPopupMenu(TPM_RIGHTBUTTON, oldPoint, 0, *this);
    }
  }
}

//
// Deactivate active embedded object if any
//
bool
TOleWindow::Deactivate()
{
  // Deactivate active part, if any
  //
  if (DragPart && DragPart->IsActive()) {
    SetSelection(0);
    return true;
  }
  else
    return false;
}

//
// Select embedded object, point is in logical units
//
bool
TOleWindow::Select(uint, TPoint& point)
{
  PRECONDITION(GetOcDoc());

  // If the point is not on the current selection, perform hit test on parts
  // to find & select one
  //
  if (!DragPart || !DragPart->IsVisible(TRect(point, TSize(1,1))))
    SetSelection(GetOcDoc()->GetParts().Locate(point));

  // If a part is now selected, manipulate it.
  //
  if (DragPart) {
    DragRect = DragPart->GetRect();
    DragRect.right++;
    DragRect.bottom++;
    if (DragPart->IsSelected()) {
      TUIHandle handle(DragRect, TUIHandle::HandlesIn | TUIHandle::Grapples |
                       TUIHandle::Framed);
      DragHit = handle.HitTest(point);
    }
    else {
      DragHit = TUIHandle::MidCenter;
    }

    if (!DragDC)
      DragDC = new TOleClientDC(*this);
    DragDC->DrawFocusRect(DragRect);

    DragStart = DragPt = point;
    SetCapture();

    return true;
  }

  return false;
}

//
// Check if any embedded object is selected
//
void
TOleWindow::EvLButtonDown(uint modKeys, TPoint& point)
{
  // Deactivating in-place active object, if any
  //
  if (Deactivate())
    return;

  // Convert the point to logical unit
  //
  if (!DragDC)
    DragDC = new TOleClientDC(*this);

  DragDC->DPtoLP(&point);
  Select(modKeys, point);
}

//
// Is the logical point within the client area?
//
bool
TOleWindow::InClient(TDC& dc, TPoint& point)
{
  TRect logicalRect = GetClientRect();

  dc.DPtoLP((TPoint*)&logicalRect, 2);
  return logicalRect.Contains(point);
}

//
//
//
void
TOleWindow::EvMouseMove(uint modKeys, TPoint& point)
{
  if (!DragDC)
    return;

  // Convert the point to logical unit
  //
  DragDC->DPtoLP(&point);

  // A MidCenter hit is a move
  //
  if (DragHit == TUIHandle::MidCenter) {
    DragDC->DrawFocusRect(DragRect);   // erase old rect

		// check if initiate drag and drop
    if (StartDrag(modKeys, point)) {
      TOcDropAction outAction;
      OcApp->Drag(DragPart, TOcDropAction(daDropCopy | daDropMove | daDropLink),
                  outAction);

      TOcPartChangeInfo changeInfo(DragPart, TOcInvalidate(invView | invData));
      EvOcViewPartInvalid(changeInfo);
      DragHit = TUIHandle::Outside;
      ReleaseCapture();

      // Delete the dragged part since it was dragged out
      //
      if (outAction == daDropMove) {
        DragPart->Delete();
        DragPart = 0;
      }
    }
    else {
      TPoint delta = point - DragPt;
      DragRect.Offset(delta.x, delta.y);
      DragDC->DrawFocusRect(DragRect);   // draw new rect
    }
  }
  // All other non-outside hits are resizes
  //
  else if (DragHit != TUIHandle::Outside) { // handle
    DragDC->DrawFocusRect(DragRect);   // erase old rect
    int dl = (DragHit%3) == 0 ? point.x - DragPt.x : 0;
    int dr = (DragHit%3) == 2 ? point.x - DragPt.x : 0;
    int dt = (DragHit/3) == 0 ? point.y - DragPt.y : 0;
    int db = (DragHit/3) == 2 ? point.y - DragPt.y : 0;

    // maintain minimum part size
    //
    if ((DragRect.Width() + dr - dl) >= MinWidth) {
      DragRect.left += dl;
      DragRect.right += dr;
    }
    if ((DragRect.Height() + db - dt) >= MinHeight) {
      DragRect.top  += dt;
      DragRect.bottom += db;
    }

    DragDC->DrawFocusRect(DragRect);   // draw new rect
  }

  DragPt = point;
}

//
//
//
void
TOleWindow::EvLButtonUp(uint /*modKeys*/, TPoint& /*point*/)
{
  if (DragPart) {
    TOcPartChangeInfo changeInfo(DragPart, TOcInvalidate(invView | invData));

    // All non-outside hits are moves or resizes
    //
    if (DragHit != TUIHandle::Outside) {
      EvOcViewPartInvalid(changeInfo);
      DragPart->SetPos(DragRect.TopLeft());
      if (DragHit != TUIHandle::MidCenter)
        DragPart->SetSize(DragRect.Size());  // A MidCenter hit is a move only
      EvOcViewPartInvalid(changeInfo);
    }
    InvalidatePart(invView);

    DragHit = TUIHandle::Outside;
    ReleaseCapture();
  }

  if (DragDC) {
    delete DragDC;
    DragDC = 0;
    DragRect.SetNull();
  }
}

//
// Let OcView know that the view window has changed sizes
//
void
TOleWindow::EvSize(uint sizeType, TSize& size)
{
  TWindow::EvSize(sizeType, size);
  OcView->EvResize();
}

//
// Handle message forwarded from our mdi child frame (if any) to let OcView
// know that the view window has changed size
//
void
TOleWindow::EvMDIActivate(THandle hActivated, THandle /*hDeactivated*/)
{
  if (OcView)
    OcView->EvActivate(hActivated == *Parent);
}

uint
TOleWindow::EvMouseActivate(THandle topParent, uint /*hitCode*/, uint /*msg*/)
{
  if (topParent)
    ForwardMessage(topParent);

  return MA_ACTIVATE;
}

//
// May need to pass focus to an in-place server if there is one
//
void
TOleWindow::EvSetFocus(THandle hLostFocus)
{
  TWindow::EvSetFocus(hLostFocus);
  if (OcView)
    OcView->EvSetFocus(true); // Maybe active part (if any) wants focus
}

//
// response method for an incoming WM_VSCROLL message
//
void
TOleWindow::EvHScroll(uint scrollCode, uint thumbPos, THandle hCtl)
{
  TWindow::EvHScroll(scrollCode, thumbPos, hCtl);

  InvalidatePart(invView);
}

//
// response method for an incoming WM_VSCROLL message
//
void
TOleWindow::EvVScroll(uint scrollCode, uint thumbPos, THandle hCtl)
{
  TWindow::EvVScroll(scrollCode, thumbPos, hCtl);

  InvalidatePart(invView);
}

//
// Handle WM_MENUSELECT to provide hint text in the container's status bar
// based on the menu item id. Treat popup items separatly and ask them for
// their ids. Similar to code in TDecoratedFrame.
//
void
TOleWindow::EvMenuSelect(uint menuItemId, uint flags, HMENU hMenu)
{
  if (GetOcRemView()) {
    if (flags == 0xFFFF && hMenu == 0) {  // menu closing
      GetOcRemView()->SetContainerStatusText("");
      return;
    }
    else if (flags & MF_POPUP) {
      TMenu popupMenu(hMenu);
      int   count = popupMenu.GetMenuItemCount();
      int   pos = 0;
      for (;pos < count && popupMenu.GetSubMenu(pos) != HMENU(menuItemId);
            pos++)
        ;
      menuItemId = popupMenu.GetMenuItemID(pos);
    }
    else if (flags & (MF_SEPARATOR | MF_MENUBREAK | MF_MENUBARBREAK)
      || (menuItemId >= IDW_FIRSTMDICHILD && menuItemId < IDW_FIRSTMDICHILD+9)) {
      menuItemId = 0;  // display an empty help message
    }
    string text = GetModule()->LoadString(menuItemId);
    GetOcRemView()->SetContainerStatusText(text.c_str());
  }
  else
    TWindow::EvMenuSelect(menuItemId, flags, hMenu);
}

//
// Handle & sub-dispatch the OC event message.
//
TResult
TOleWindow::EvOcEvent(TParam1 param1, TParam2 param2)
{
  TEventHandler::TEventInfo eventInfo(WM_OCEVENT, param1);
  if (Find(eventInfo))
    return Dispatch(eventInfo, param1, param2);
  return 0;
}

//
// Return our frame's title
//
const char far*
TOleWindow::EvOcViewTitle()
{
  char title[128];
  Parent->GetWindowText(title, sizeof title);
  ContainerName = title;

  return ContainerName.c_str();
}

//
// Set our frame's title
//
void
TOleWindow::EvOcViewSetTitle(const char far* title)
{
  if (title && *title)
    Parent->SetWindowText(title);
  else if (GetOcRemView() && GetOcRemView()->GetKind() == TOcRemView::Link) {
    const char far* caption = GetFileName();
    if (caption)
      Parent->SetWindowText(caption);
  }
}

//
// Can the server put toolbars in our view? Say no--make him use the app frame
//
bool
TOleWindow::EvOcViewBorderSpaceReq(TRect far* /*space*/)
{
  return false;
}

//
// Can the server put toolbars in our view? Say no--make him use the app frame
//
bool
TOleWindow::EvOcViewBorderSpaceSet(TRect far* /*space*/)
{
  return false;
}

//
// Can the indicated ole object be dropped here? Say yes to everything as a
// default
//
bool
TOleWindow::EvOcViewDrop(TOcDragDrop far& /*ddInfo*/)
{
  return true;    // ok to drop anything, we can take it...
}

//
// Provide drag UI feedback
//
bool
TOleWindow::EvOcViewDrag(TOcDragDrop far& ddInfo)
{
  TClientDC dc(*this);
  TPen pen(TColor(128, 128, 128), 4, PS_DOT);
  dc.SelectObject(pen);
  dc.SelectStockObject(HOLLOW_BRUSH);
  dc.SetROP2(R2_NOTXORPEN);

  dc.Rectangle(*ddInfo.Pos);
  return true;
}

//
// Scroll our view window. Update any internal state as needed. This is called
// when the server is sizing, or a drop interaction is near the edge
//
bool
TOleWindow::EvOcViewScroll(TOcScrollDir /*scrollDir*/)
{
  return false;
}

//
// Convert the part rect into device units
//
bool
TOleWindow::EvOcViewGetSiteRect(TRect far* rect)
{
  TOleClientDC dc(*this);

  return dc.LPtoDP((TPoint*)rect, 2);
}

//
// Convert the part rect into logical units
//
bool
TOleWindow::EvOcViewSetSiteRect(TRect far* rect)
{
  TOleClientDC dc(*this);

  return dc.DPtoLP((TPoint*)rect, 2);
}

//
// Handle the scaling for server app
//
bool
TOleWindow::EvOcViewGetScale(TOcScaleFactor& scaleFactor)
{
  scaleFactor = Scale;
  return true;
}

//
// Handle the scaling for server app
//
bool
TOleWindow::EvOcViewPartActivate(TOcPart& ocPart)
{
  SetSelection(&ocPart);
  return true;
}

//
// Handle the scaling for server app
//
bool
TOleWindow::EvOcViewPasteObject(TOcInitInfo& init)
{
  TRect rect;
  GetInsertPosition(rect);
  TOcPart* part = new TOcPart (*GetOcDoc());
  part->Init(&init, rect);
  init.ReleaseDataObject();
  return true;
}

//
// Ask server to paint itself in the position and dc provided
//
bool
TOleWindow::EvOcViewPaint(TOcViewPaint far& vp)
{
  // Paint according to the view paint structure
  //
  TDC dc(vp.DC);
  Pos = *vp.Pos;

  // Paint embedded objects
  //

  bool metafile = dc.GetDeviceCaps(TECHNOLOGY) == DT_METAFILE;
  SetupDC(dc, !metafile);

  if (vp.Moniker) {
    PaintLink(dc, true, Pos, *vp.Moniker);
  }
  else if (vp.PaintSelection) {
    PaintSelection(dc, true, Pos, vp.UserData);
  }
  else {
    Paint(dc, true, Pos);
    PaintParts(dc, true, Pos, metafile);
  }

  Pos.SetNull();

  return true;
}

//
// TOcRemView is going away, disconnect TOleWindow with it so we don't use it
// later. If this is a remote view, then close the doc too.
//
bool
TOleWindow::EvOcViewClose()
{
  if (IsRemote() && OcDoc)
    OcDoc->Close();

  OcView = 0;
  return true;
}

//
// Ask server to save itself in the IStorage
//
bool
TOleWindow::EvOcViewSavePart(TOcSaveLoad far& /*ocSave*/)
{
  return true;
}

//
// Ask server to load itself from the IStorage
//
bool
TOleWindow::EvOcViewLoadPart(TOcSaveLoad far& /*ocLoad*/)
{
  return true;
}

//
// Let container know about the server view size in pixels
//
bool
TOleWindow::EvOcViewPartSize(TOcPartSize far& /*size*/)
{
  return false;
}

//
// Ask container to open an existing document
// Used for linking from embedding
//
bool
TOleWindow::EvOcViewOpenDoc(const char far* /*path*/)
{
  return true;
}

//
// Insert server menu into the composite one
//
bool
TOleWindow::EvOcViewInsMenus(TOcMenuDescr far& /*sharedMenu*/)
{
  return false;
}

//
// Request for server to put up its toolbar. This implementation assume that
// this server is single use, and the MainWindow's ToolBar is ours to snarf
//
bool
TOleWindow::EvOcViewShowTools(TOcToolBarInfo far& tbi)
{
  TWindow* mainWindow = GetApplication()->GetMainWindow();
  CHECK(mainWindow);
  TWindow* toolBar = mainWindow->ChildWithId(IDW_TOOLBAR);
  if (!toolBar)
    return false;
  tbi.HTopTB = THandle(*toolBar);
  return true;
}

//
// Get server's color palette
//
bool
TOleWindow::EvOcViewGetPalette(LOGPALETTE far* far* /*palette*/)
{
  return false;
}

//
// Ask server to provide data according to the format in a handle
//
bool
TOleWindow::EvOcViewClipData(TOcFormatData far& /*format*/)
{
  return false;
}

//
// Set format data into server
//
bool
TOleWindow::EvOcViewSetData(TOcFormatData far& /*format*/)
{
  return false;
}

//
// Get Ambient properties
//
bool
TOleWindow::EvOcAmbientGetBackColor(long* /*backColor*/)
{
  return false;
}

bool
TOleWindow::EvOcAmbientGetForeColor(long* /*foreColor*/)
{
  return false;
}

bool
TOleWindow::EvOcAmbientGetLocaleID(long* /*localeId*/)
{
  return false;
}

bool
TOleWindow::EvOcAmbientGetTextAlign(short* /*align*/)
{
  return false;
}

bool
TOleWindow::EvOcAmbientGetMessageReflect(bool* /*reflectMessage*/)
{
  return false;
}

bool
TOleWindow::EvOcAmbientGetUserMode(bool* /*userMode*/)
{
  return false;
}

bool
TOleWindow::EvOcAmbientGetUIDead(bool* /*deadUI*/)
{
  return false;
}

bool
TOleWindow::EvOcAmbientGetShowGrabHandles(bool* /*showGrabHandles*/)
{
  return false;
}

bool
TOleWindow::EvOcAmbientGetShowHatching(bool* /*showHatching*/)
{
  return false;
}

bool
TOleWindow::EvOcAmbientGetDisplayAsDefault(bool* /*displayAsDefault*/)
{
  return false;
}

bool
TOleWindow::EvOcAmbientGetSupportsMnemonics(bool* /*supportMnemonics*/)
{
  return false;
}

bool
TOleWindow::EvOcAmbientGetDisplayName(TString** /*name*/)
{
  return false;
}

bool
TOleWindow::EvOcAmbientGetScaleUnits(TString** /*units*/)
{
  return false;
}

bool
TOleWindow::EvOcAmbientGetFont(IDispatch** /*font*/)
{
  return false;
}

bool
TOleWindow::EvOcAmbientSetBackColor(long /*backColor*/)
{
  return false;
}

bool
TOleWindow::EvOcAmbientSetForeColor(long /*foreColor*/)
{
  return false;
}

bool
TOleWindow::EvOcAmbientSetLocaleID(long /*localeId*/)
{
  return false;
}

bool
TOleWindow::EvOcAmbientSetTextAlign(short /*align*/)
{
  return false;
}

bool
TOleWindow::EvOcAmbientSetMessageReflect(bool /*reflect*/)
{
  return false;
}

bool
TOleWindow::EvOcAmbientSetUserMode(bool /*userMode*/)
{
  return false;
}

bool
TOleWindow::EvOcAmbientSetUIDead(bool /*dead*/)
{
  return false;
}

bool
TOleWindow::EvOcAmbientSetShowGrabHandles(bool /*showHandles*/)
{
  return false;
}

bool
TOleWindow::EvOcAmbientSetShowHatching(bool /*showHatching*/)
{
  return false;
}

bool
TOleWindow::EvOcAmbientSetDisplayAsDefault(bool /*displayAsDefault*/)
{
  return false;
}

bool
TOleWindow::EvOcAmbientSetSupportsMnemonics(bool /*supportMnemonics*/)
{
  return false;
}

bool
TOleWindow::EvOcAmbientSetDisplayName(TString* /*name*/)
{
  return false;
}

bool
TOleWindow::EvOcAmbientSetScaleUnits(TString* /*units*/)
{
  return false;
}

bool
TOleWindow::EvOcAmbientSetFont(IDispatch* /*font*/)
{
  return false;
}

//
// Control Event Dispatches
//
bool
TOleWindow::EvOcCtrlClick(TCtrlEvent* /*pev*/)
{
  return false;
}

bool
TOleWindow::EvOcCtrlDblClick(TCtrlEvent* /*pev*/)
{
  return false;
}

bool
TOleWindow::EvOcCtrlMouseDown(TCtrlMouseEvent* /*pev*/)
{
  return false;
}

bool
TOleWindow::EvOcCtrlMouseUp(TCtrlMouseEvent* /*pev*/)
{
  return false;
}

bool
TOleWindow::EvOcCtrlMouseMove(TCtrlMouseEvent* /*pev*/)
{
  return false;
}

bool
TOleWindow::EvOcCtrlKeyDown(TCtrlKeyEvent* /*pev*/)
{
  return false;
}

bool
TOleWindow::EvOcCtrlKeyUp(TCtrlKeyEvent* /*pev*/)
{
  return false;
}

bool
TOleWindow::EvOcCtrlErrorEvent(TCtrlErrorEvent* /*pev*/)
{
  return false;
}

bool
TOleWindow::EvOcCtrlFocus(TCtrlFocusEvent* /*pev*/)
{
  return false;
}

bool
TOleWindow::EvOcCtrlPropertyChange(TCtrlPropertyEvent* /*pev*/)
{
  return false;
}

bool
TOleWindow::EvOcCtrlPropertyRequestEdit(TCtrlPropertyEvent* /*pev*/)
{
  return false;
}

bool
TOleWindow::EvOcCtrlCustomEvent(TCtrlCustomEvent* /*pev*/)
{
  return false;
}

//
// Paint the embedded objects
//
bool
TOleWindow::PaintParts(TDC& dc, bool, TRect&, bool metafile)
{
  if (!GetOcDoc())
    return false;

  TRect clientRect;
  TRect logicalRect = GetClientRect();

  if (IsRemote()) {
    clientRect = GetWindowRect();
    clientRect.Offset(-clientRect.left, -clientRect.top);
  }
  else {
    clientRect = logicalRect;
  }

  TPoint scrollPos(0, 0);

  if (!metafile) {
    dc.DPtoLP((TPoint*)&logicalRect, 2);
  }
  else {
    if (Scroller) {
      scrollPos.x = (int)Scroller->XPos;
      scrollPos.y = (int)Scroller->YPos;
    }
  }

  for (TOcPartCollectionIter i(GetOcDoc()->GetParts()); i; i++) {
    TOcPart& p = *i.Current();
    if (p.IsVisible(logicalRect) || metafile) {
      TRect r = p.GetRect();
      r.Offset(-scrollPos.x, -scrollPos.y);
      p.Draw(dc, r, clientRect, asDefault);

      if (metafile)
        continue;

      // Paint selection
      //
      if ((p.IsSelected() || ShowObjects) && r.Width() > 0 && r.Height() > 0) {
        uint handleStyle = p.IsLink() ? TUIHandle::DashFramed : TUIHandle::Framed;
        if (p.IsSelected())
          handleStyle |= TUIHandle::Grapples;
        TUIHandle(r, handleStyle).Paint(dc);
      }
    }
  }
  return true;
}

//
// Change the scaling factor
//
void
TOleWindow::SetScale(uint16 percent)
{
  Scale.SetScale(percent);
  Invalidate();
}

//
// Get the logical unit per inch for document
//
void
TOleWindow::GetLogPerUnit(TSize& logPerUnit)
{
  TScreenDC dc;

  logPerUnit.cx = dc.GetDeviceCaps(LOGPIXELSX);
  logPerUnit.cy = dc.GetDeviceCaps(LOGPIXELSY);
}

//
// Setup the dc before painting
//
void
TOleWindow::SetupDC(TDC& dc, bool scale)
{
  dc.SetMapMode(MM_ANISOTROPIC);

  // Setup window and viewport origin according to scroll amount
  //
  TPoint scrollPos(0, 0);
  if (Scroller) {
    scrollPos.x = (int)Scroller->XPos;
    scrollPos.y = (int)Scroller->YPos;
  }

  if (!scale) {
    dc.SetWindowOrg(scrollPos);
    return;
  }

  // Don't scale the scrolling amount
  //
  if (Scale.SiteSize.cx)
    scrollPos.x = (int)(((uint32)scrollPos.x * Scale.PartSize.cx +
                        Scale.SiteSize.cx/2) / Scale.SiteSize.cx);
  if (Scale.SiteSize.cy)
    scrollPos.y = (int)(((uint32)scrollPos.y * Scale.PartSize.cy +
                        Scale.SiteSize.cy/2) / Scale.SiteSize.cy);
  dc.SetWindowOrg(scrollPos);

  dc.SetViewportOrg(Pos.TopLeft());

  // set the window and viewport extaccording to zoom factor
  //
  TSize ext;
  GetLogPerUnit(ext);
  dc.SetWindowExt(ext);

  ext.cx = dc.GetDeviceCaps(LOGPIXELSX);
  ext.cy = dc.GetDeviceCaps(LOGPIXELSY);

  if (Scale.PartSize.cx)
    ext.cx = (int)(((uint32)ext.cx * Scale.SiteSize.cx + Scale.PartSize.cx/2) /
                   Scale.PartSize.cx);
  if (Scale.PartSize.cy)
    ext.cy = (int)(((uint32)ext.cy * Scale.SiteSize.cy + Scale.PartSize.cy/2) /
                   Scale.PartSize.cy);
  dc.SetViewportExt(ext);
}

//
// response method for an incoming WM_PAINT message
//
void
TOleWindow::EvPaint()
{
  if (IsFlagSet(wfAlias))
    DefaultProcessing();  // use application-defined wndproc

  else {
    TPaintDC dc(*this);
    TRect&   rect = *(TRect*)&dc.Ps.rcPaint;

    if (Scroller)
      Scroller->BeginView(dc, rect);

    bool metafile = dc.GetDeviceCaps(TECHNOLOGY) == DT_METAFILE;
    SetupDC(dc, !metafile);
    Paint(dc, dc.Ps.fErase, rect);
    PaintParts(dc, dc.Ps.fErase, rect, metafile);

    if (Scroller)
      Scroller->EndView();
  }
}

//
// Notify the active view of part data changes
//
bool
TOleWindow::EvOcViewPartInvalid(TOcPartChangeInfo& changeInfo)
{
  // Our document is now dirty...

  // Reflect the change in part in other (non-active) views
  //
  TRect rect(changeInfo.GetPart()->GetRect());
  rect.right++;
  rect.bottom++;
  TOleClientDC dc(*this);
  dc.LPtoDP((TPoint*)&rect, 2);

  InvalidateRect(rect);  // Multiview support to be done in derived classes

  // Notify container if this is an intermediate container
  //
  InvalidatePart((TOcInvalidate)changeInfo.GetType());

  return true; // stop further processing by OCF
}

//
//
//
TPopupMenu*
TOleWindow::CreateVerbPopup(const TOcVerb& ocVerb)
{
  TPopupMenu* verbMenu = new TPopupMenu(NoAutoDelete);
  while (DragPart->EnumVerbs(ocVerb)) {
    verbMenu->AppendMenu(MF_STRING|MF_ENABLED,
                         (uint)CM_EDITFIRSTVERB + ocVerb.VerbIndex,
                         (const char far*)OleStr(ocVerb.VerbName));
  }

  verbMenu->AppendMenu(MF_SEPARATOR, 0, 0);
  string optName = GetModule()->LoadString(IDS_EDITCONVERT);
  verbMenu->AppendMenu(MF_STRING, CM_EDITCONVERT, optName.c_str());

  return verbMenu;
}

//
// Execute a verb pertaining to the selected object
//
void
TOleWindow::EvDoVerb(uint whichVerb)
{
  DragPart->DoVerb(whichVerb);
}

//
// Attach this view back to its owl parent for either open editing, or
// mearly inplace de-activating
//
bool
TOleWindow::EvOcViewAttachWindow(bool attach)
{
  TOleFrame* mainWindow = TYPESAFE_DOWNCAST(GetApplication()->GetMainWindow(),
                                            TOleFrame);
  if (!mainWindow)
    return false;  // server app is shutting down

  if (attach) {
    if (IsOpenEditing()) {
      // Derived class needs to managed setting up frame differently, like
      // for MDI etc.
      //
      mainWindow->SetClientWindow(this);
    }
  }
  else {
    if (IsOpenEditing() && Parent != mainWindow)
      Parent->PostMessage(WM_CLOSE);
    SetParent(mainWindow->GetRemViewBucket());  // simple reparent
  }
  return true;
}

//
// Perform the action indentified by verb
//
bool
TOleWindow::EvOcViewDoVerb(uint /*verb*/)
{
  return false;
}

//
// Perform the action indentified by verb
//
bool
TOleWindow::EvOcViewTransformCoords(uint /*verb*/)
{
  return false;
}

//
// Shut down the associated OCF partners if possible
//
bool
TOleWindow::OleShutDown()
{
  if (IsRemote()) {
    TOcRemView* ocRemView = GetOcRemView();
    if (IsOpenEditing())
      ocRemView->Disconnect();
  }
  else {
    if (OcView)
      OcView->EvClose();
  }
  return true;
}

//
// Perform normal CleanupWindow, plus let the OcView object know we have closed
//
void
TOleWindow::CleanupWindow()
{
  TOleFrame* mainWindow = TYPESAFE_DOWNCAST(GetApplication()->GetMainWindow(),
                                            TOleFrame);

  if (mainWindow)
    mainWindow->OleViewClosing(true);
  OleShutDown();
  if (mainWindow)
    mainWindow->OleViewClosing(false);
  TWindow::CleanupWindow();
}


#if 0
static void
DoIdleAction(TWindow* win, void* idleCount)
{
  win->IdleAction(*(long*)idleCount);
}
#endif

//
// TOleWindow processes idle action occurs once per block of messages
//
bool
TOleWindow::IdleAction(long idleCount)
{
/*
  if (idleCount == 0) {
    // give child windows an opportunity to do any idle processing
    //
    ForEach(DoIdleAction, &idleCount);
  }
  return false;  // we don't need any more time for now
*/ 

  return TWindow::IdleAction(idleCount);
}

bool
TOleWindow::PreProcessMsg(MSG& msg)
{
  if (TWindow::PreProcessMsg(msg))
    return true;  // Processed accelerators
  return false;
}

//
// Handle the scaling for server app
//
bool
TOleWindow::EvOcViewSetScale(TOcScaleFactor& scaleFactor)
{
  Scale = scaleFactor;
  return true;
}

//
// Find the item name for whole doc or selection
//
bool
TOleWindow::EvOcViewGetItemName(TOcItemName& /*item*/)
{
  return false;
}

//----------------------------------------------------------------------------
// Linking Spport
//

//
// Establish link with whole doc or selection
//
bool
TOleWindow::EvOcViewSetLink(TOcLinkView& /*view*/)
{
  return false;
}

//
// Break link with whole doc or selection
//
bool
TOleWindow::EvOcViewBreakLink(TOcLinkView& /*view*/)
{
  return false;
}
