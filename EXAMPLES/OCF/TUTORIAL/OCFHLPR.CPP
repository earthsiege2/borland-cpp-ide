// ---------------------------------------------------------------------------
// Copyright (C) 1994 Borland International
// ---------------------------------------------------------------------------
#include <ocf/pch.h>
#include <ocf/ocapp.h>
#include <ocf/ocdoc.h>
#include <ocf/ocview.h>
#include <ocf/ocremvie.h>
#include <ocf/ocpart.h>
#include <windowsx.h>

#include "ocfhlpr.h"
#include "ocfhlpr.rh"

//
// constants for menu enabling/disabling
//
const int MF_ON = MF_ENABLED;
const int MF_OFF= MF_DISABLED|MF_GRAYED;
const int MENU_GROUP_COUNT = 6;   // sizeof(TOcMenuDescr.Width) /
                                  // sizeof(TOcMenuDescr.Width[0])

//
// The TOcApp* pointer ...
//
static TOcApp*  TheOcApp = 0;


//
// Initializes OLE to use default IMalloc allocator.
// Creates OCF helper objects
//
TOleInitEx::TOleInitEx(TRegList& regInfo,
                       TComponentFactory callback,
                       string& cmdLine, TRegLink* linkHead,
                       HINSTANCE hInst) 
           : OcRegistrar(0), OcApp(TheOcApp)
{
  // Initialize OCF objects: Create TOcRegistrar & TOcApp
  //
  OcRegistrar = new TOcRegistrar(regInfo, callback, cmdLine,
                                 linkHead, hInst);
  OcRegistrar->CreateOcApp(OcRegistrar->GetOptions(), OcApp);
}


//
// Cleans up the OCF helper objects
//
TOleInitEx::~TOleInitEx()
{
  // Free the Registrar
  //
  delete OcRegistrar;
}


//
// Accessor to the OcApp helper object - used mainly by OLE Window
//
TOcApp*
GetOcApp()
{
  return TheOcApp;
}


//
// Constructor of object encapsulating an OLE Frame window
//
TOleFrameWin::TOleFrameWin(HWND hwnd) :
  Hwnd(hwnd)
{
}


//
// Method to call when OLE Frame Window receives a WM_CREATE message
//
void
TOleFrameWin::OnCreate()
{
  // Hand our frame HWND to OCF so it may send OLE notifications/requests
  //
  if (GetOcApp())
    GetOcApp()->SetupWindow(Hwnd);
}


//
// Method to call when OLE Frame Window receives a WM_DESTROY message
//
void
TOleFrameWin::OnDestroy()
{
  // Release the OCF Application helper object
  //
  if (GetOcApp())
    GetOcApp()->Release();
}


//
// Method to call when OLE Frame Window receives a WM_ACTIVATEAPP message
//
void
TOleFrameWin::OnActivateApp(bool active)
{
  GetOcApp()->EvActivate(active);
}


//
// Constructor of object encapsulating an OLE Window
// Simply initialize OCF Helper objects
//
TOleWin::TOleWin(HWND hwnd) : Hwnd(hwnd),
                              Pos(0, 0, 0, 0),
                              Embedded(false),
                              ShowObjects(true)
{
  OcDoc     = 0;
  OcView    = 0;
  DragPart  = 0;

  //
  // Init menu related variables
  //
  MergedMenu = 0;
  HMenu      = 0;
  memset(Width, 0, sizeof(Width));
}


//
// Method to call when OLE Window receives a WM_CREATE message
//
void
TOleWin::OnCreate()
{
  // Create OCF Document/View pair associated with each OLE Window
  //
  OcDoc  = new TOcDocument(*GetOcApp());
  OcView = new TOcView(*OcDoc);

  // Hand OCF our window handle so it may send OLE notifications/requests
  //
  if (OcView)
    OcView->SetupWindow(Hwnd);
}


//
// Method to call when OLE Window receives a WM_DESTROY message
//
void
TOleWin::OnDestroy()
{
  // Deactivate the embedded parts
  //
  for (TOcPartCollectionIter i(OcDoc->GetParts()); i; i++) {
    TOcPart& p = *i.Current();
    p.Activate(false);
  }

  // Release the OCF View helper object
  //
  if (OcView) {
    OcView->EvClose();
    OcView->ReleaseObject();
  }

  // Close the OCF document helper object
  //
  if (OcDoc)
    OcDoc->Close();

  // Delete the OCF document helper object
  //
  delete OcDoc;
}


//
// Method to call when OLE Window receives a WM_SIZE message
//
void
TOleWin::OnSize()

{
  // Inform the OCF View helper that we've been resized
  //
  if (OcView)
    OcView->EvResize();
}


//
// Method to call when OLE Window receives a WM_PAINT message.
// Asks parts to draw themselves
//
void
TOleWin::OnPaint(HDC dc, PAINTSTRUCT& ps)
{
  bool metafile = GetDeviceCaps(dc, TECHNOLOGY) == DT_METAFILE;
  SetupDC(dc, !metafile);

  PaintParts(dc, ps.fErase, TRect(ps.rcPaint), metafile);
}


//
// Method to call when OLE Window receives a WM_COMMAND with an
// id it does not care for. This method handles the various
// OLE UI commands such as InsertObject or PasteSpecial
//
bool
TOleWin::OnCommand(uint cmdID)
{
  switch (cmdID) {
    case CM_EDITINSERTOBJECT:
      EditInsertObject();
      break;

    case CM_EDITPASTESPECIAL:
      EditPasteSpecial();
      break;

    case CM_EDITCONVERT:
      EditConvert();
      break;

    case CM_EDITLINKS:
      EditLinks();
      break;

    case CM_EDITSHOWOBJECTS:
      ShowObjects = !ShowObjects;
      InvalidateRect(Hwnd, 0, TRUE);
      break;

    default:
      return false;       // We did not handle the command!
  }
  return true;            // We handled the command
}


//
//
//
void
TOleWin::OnInitMenu(HMENU hMenu)
{

  EnableMenuItem(hMenu, CM_EDITINSERTOBJECT, MF_BYCOMMAND |
                 ((GetOcApp() && GetOcView()) ? MF_ON : MF_OFF));
  EnableMenuItem(hMenu, CM_EDITCONVERT,
              MF_BYCOMMAND|((DragPart != 0) ? MF_ON : MF_OFF));

  uint mask = GetOcApp()->EnableEditMenu(
                  TOcMenuEnable(meEnablePaste|meEnablePasteLink|
                                meEnableBrowseClipboard|meEnableBrowseLinks),
                                         GetOcView());

  EnableMenuItem(hMenu, CM_EDITPASTE,
              MF_BYCOMMAND|((mask & meEnablePaste) ? MF_ON : MF_OFF));
  EnableMenuItem(hMenu, CM_EDITPASTELINK,
              MF_BYCOMMAND|((mask & meEnablePasteLink) ? MF_ON : MF_OFF));
  EnableMenuItem(hMenu, CM_EDITPASTESPECIAL,
              MF_BYCOMMAND|((mask & meEnableBrowseClipboard) ? MF_ON : MF_OFF));
  EnableMenuItem(hMenu, CM_EDITLINKS,
              MF_BYCOMMAND|((mask & meEnableBrowseLinks) ? MF_ON : MF_OFF));

  CheckMenuItem(hMenu, CM_EDITSHOWOBJECTS,
                MF_BYCOMMAND |(ShowObjects ? MF_CHECKED : MF_UNCHECKED));
}


//
// Method to call when OLE Window receives a WM_INITMENUPOPUP message
// (which is typically a hand-down from the frame window).
// Method takes care of enabling/disabling/checking etc. OLE related
// commands.
//
void
TOleWin::OnInitMenuPopup(HMENU hMenu, int /*item*/)
{
  OnInitMenu(hMenu);
}


//
// Method to call when OLE Window receives a WM_LBUTTONDOWN message.
// Deactivates any active parts.
//
bool
TOleWin::OnLButtonDown(int /*x*/, int /*y*/, UINT /*keyFlags*/)
{
  if (Deactivate())
    return true;        // We handled the message...

  return false;
}


//
// Method to call when OLE Window receives an WM_LBUTTONDBLCLK message.
// Activates the part if the mouse was clicked on an inactivate part.
//
bool
TOleWin::OnLButtonDblClk(int x, int y, UINT modKeys)
{
  TPoint point(x, y);
  OleClientDC dc(*this);
  DPtoLP(dc, &point, 1);

  TOcPart* p = GetOcDoc()->GetParts().Locate(point);

  if (modKeys & MK_CONTROL) {
    if (p)
      p->Open(true);
  } else {
    SetSelection(p);

    if (p && p == GetOcView()->GetActivePart())
      p->Activate(false);

#if !defined(BOLE_ACTIVATE)
    GetOcView()->ActivatePart(p);
#else
    if (p)
      p->Activate(true);
#endif
  }

  return true;
}


//
// Method to call when OLE window receives a WM_ACTIVATE or
// WM_MDIACTIVATE message.
//
void
TOleWin::OnActivate(bool active)
{
  GetOcView()->EvActivate(active);
}


//
//
//
void
TOleWin::OnSetFocus(HWND /*hwndLostFocus*/)
{
  GetOcView()->EvSetFocus(true);
}


//
// Method to call when OLE Window receives a WM_RBUTTONDOWN message.
// Implements the Local Object menu (with VERBS) if the mouse was
// clicked on a part.
//
bool
TOleWin::OnRButtonDown(int /*x*/, int /*y*/, uint /*keyFlags*/)
{
  return true;
}


//
// Method to call when OLE Window receives a WM_OCEVENT message.
// This method invokes a separate handler for the various OCF
// events. These in turn provide various default behaviours.
//
LRESULT
TOleWin::OnOcEvent(WPARAM wParam, LPARAM lParam)
{
  switch (wParam) {
    case OC_VIEWTITLE:
         return (LRESULT)OnOcViewTitle();

    case OC_VIEWSETTITLE:
         OnOcViewSetTitle((const char far*)lParam);
         return (LRESULT)true;

    case OC_VIEWSETSITERECT:
         return (LRESULT)OnOcViewSetSiteRect((TRect far*)lParam);

    case OC_VIEWGETSCALE:
         return (LRESULT)OnOcViewGetScale((TOcScaleFactor far*)lParam);

    case OC_VIEWPARTINVALID:
         return (LRESULT)OnOcViewPartInvalid((TOcPartChangeInfo far*)lParam);

    case OC_VIEWGETSITERECT:
          return (LRESULT)OnOcViewGetSiteRect((TRect far*)lParam);

    case OC_VIEWDROP:
         return OnOcViewDrop((TOcDragDrop far*)lParam);

    default:
      return LRESULT(false);
  }
}


const char*
TOleWin::OnOcViewTitle()
{
  static char title[100];

  if (IsWindow(Hwnd)) {
    GetWindowText(Hwnd, title, sizeof(title));
  }
  return title;
}


void
TOleWin::OnOcViewSetTitle(const char far* text)
{
  if (IsWindow(Hwnd))
    SetWindowText(Hwnd, text);
}


bool
TOleWin::OnOcViewGetScale(TOcScaleFactor* scaleInfo)
{
  if (scaleInfo)
    *scaleInfo = Scale;

  return true;
}


bool
TOleWin::OnOcViewSetSiteRect(TRect far* rect)
{
  OleClientDC dc(*this);
  return DPtoLP(dc, (POINT*)rect, 2);
}


bool
TOleWin::OnOcViewGetSiteRect(TRect far* rect)
{
  OleClientDC dc(*this);
  return LPtoDP(dc, (POINT*)rect, 2);

}


bool
TOleWin::OnOcViewPartInvalid(TOcPartChangeInfo far* changeInfo)
{
  TRect rect(changeInfo->GetPart()->GetRect());
  rect.right++;
  rect.bottom++;

  OleClientDC dc(*this);
  LPtoDP(dc, (TPoint*)&rect, 2);
  InvalidateRect(Hwnd, &rect, true);
  InvalidatePart((TOcInvalidate)changeInfo->GetType());
  return true;
}


bool
TOleWin::OnOcViewDrop(TOcDragDrop far*)
{
  //
  // Answer positively: we'll take any drop
  //
  return true;
}


//
// Displays the InsertObject dialog and allows user to
// embed an object [newly created or created from file]
//
void
TOleWin::EditInsertObject()
{
  try {
    TOcInitInfo initInfo(OcView);
    if (GetOcApp()->Browse(initInfo)) {
      TRect rect;
      GetInsertPosition(rect);
      SetSelection(new TOcPart(*GetOcDoc(), initInfo, rect));

      OcView->Rename();
      InvalidatePart(invView);
    }
  }
  catch (TXBase& xbase) {
    MessageBox(Hwnd, xbase.why().c_str(), "EXCEPTION: InsertObject", MB_OK);
  }
}


//
// Displays PasteSpecial dialog and allows use to paste/pasteLink
// object current on the clipboard.
//
void
TOleWin::EditPasteSpecial()
{
  try {
    TOcInitInfo initInfo(GetOcView());

    if (GetOcView()->BrowseClipboard(initInfo)) {
      TRect rect;
      GetInsertPosition(rect);
      new TOcPart(*GetOcDoc(), initInfo, rect);
      initInfo.ReleaseDataObject();
    }
  }
  catch (TXBase& xbase) {
    MessageBox(Hwnd, xbase.why().c_str(), "EXCEPTION: PasteSpecial", MB_OK);
  }
}


void
TOleWin::EditConvert()
{
  GetOcApp()->Convert(DragPart, false);
}


void
TOleWin::EditLinks()
{
  GetOcView()->BrowseLinks();
}


//
//
//
bool
TOleWin::SelectEmbedded()
{
  return DragPart != 0;
}


void
TOleWin::InvalidatePart(TOcInvalidate invalid)
{
  if (GetOcRemView())
    GetOcRemView()->Invalidate(invalid);
}


//
//
//
bool
TOleWin::Deactivate()
{
  if (DragPart && DragPart->IsActive()) {
    SetSelection(0);
    return true;
  } else {
    return false;
  }
}


//
//
//
void
TOleWin::SetSelection(TOcPart* part)
{
  if (part == DragPart)
    return;

  // Invalidate old part
  //
  TOcPartChangeInfo changeInfo(DragPart, invView);
  if (DragPart) {
    DragPart->Select(false);
#if !defined(BOLE_ACTIVATE)
    DragPart->Activate(false);
#endif
    OnOcViewPartInvalid(&changeInfo);
  }

  // Select and invalidate new one
  //
  DragPart = part;
  changeInfo.SetPart(DragPart);
  if (DragPart) {
    part->Select(true);
    OnOcViewPartInvalid(&changeInfo);
  }
}


//
//
//
void
TOleWin::GetInsertPosition(TRect& rect)
{
  OleClientDC dc(*this);

  // Default to 0.5" from viewport origin
  //
  rect.left  = rect.top = 0;
  rect.right = GetDeviceCaps(dc, LOGPIXELSX) >> 1;
  rect.bottom= GetDeviceCaps(dc, LOGPIXELSY) >> 1;

  LPtoDP(dc, (TPoint*)&rect, 2);

  // Embedded rect is in pixel
  //
  rect.left  = rect.Width();
  rect.top   = rect.Height();
  rect.right = rect.bottom = 0;
}


//
// Get the logical unit per inch for document
//
void
TOleWin::GetLogPerUnit(TSize& logPerUnit)
{
  HDC dc = GetWindowDC(0);  // Screen DC
  logPerUnit.cx = GetDeviceCaps(dc, LOGPIXELSX);
  logPerUnit.cy = GetDeviceCaps(dc, LOGPIXELSY);
  ReleaseDC(0, dc);
}


void
TOleWin::SetupDC(HDC dc, bool scale)
{
  SetMapMode(dc, MM_ANISOTROPIC);

  TPoint scrollPos(0, 0);

  // Adjust for scrolling here
  //

  SetWindowOrgEx(dc, scrollPos.x, scrollPos.y, 0);


  if (!scale)
    return;

  SetViewportOrgEx(dc, Pos.left, Pos.top, 0);

  //
  //
  //
  TSize ext;
  GetLogPerUnit(ext);
  SetWindowExtEx(dc, ext.cx, ext.cy, 0);

  ext.cx = GetDeviceCaps(dc, LOGPIXELSX);
  ext.cy = GetDeviceCaps(dc, LOGPIXELSY);


  ext.cx = (int)(((uint32)ext.cx * Scale.SiteSize.cx + (Scale.PartSize.cx >> 1)) /
                Scale.PartSize.cx);
  ext.cy = (int)(((uint32)ext.cy * Scale.SiteSize.cy + (Scale.PartSize.cy >> 1)) /
                Scale.PartSize.cy);

  SetViewportExtEx(dc, ext.cx, ext.cy, 0);
}


bool
TOleWin::PaintParts(HDC dc, bool, TRect&, bool metafile)
{
  TRect clientRect;
  TRect logicalRect;

  GetClientRect(Hwnd, &logicalRect);

  if (!IsEmbedded())
    clientRect = logicalRect;
  else {
    GetWindowRect(Hwnd, &clientRect);
    clientRect.Offset(-clientRect.left, -clientRect.top);
  }

  TPoint scrollPos(0, 0);

  if (!metafile)
    DPtoLP(dc, (TPoint*)&logicalRect, 2);

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
      // >> Can draw selection (eg. XOR rectangle here)
    }
  }

  return true;
}


//
// Sets and returns previous user-defined pointer which
// can be stored along with the OCF helper.
//
void*
TOleWin::SetUserInfo(void* ui)
{
  void* previous = UserInfo;
  UserInfo = ui;
  return previous;
}


//
// Hands a menu handle and menu description to the OCF helper
// object so the latter can handle OLE menu merging on behalf
// of the window.
//
void
TOleWin::SetWinMenu(const TOcMenuDescr& menuDescr)
{
  HMenu = menuDescr.HMenu;
  if (HMenu)
    memcpy(Width, menuDescr.Width, sizeof(Width));
  else
    memset(Width, 0, sizeof(Width));
}


//
// Merge the container's menu in OLE's menu handle
//
bool
TOleWin::OnOcAppInsMenus(TOcMenuDescr far* sharedMenu)
{
  //
  // If we don't have a menu handle to merge, return false
  //
  if (!HMenu)
    return false;

  //
  // If we've merged into OLE's menu already, don't bother remerging
  //
  if(MergedMenu)
    return true;

  //
  // Merge the container menu in OLE's menu
  //
  MergeContainerMenu(*sharedMenu, *this);
  return true;

}


//
// Handles OC_APPMENUS, a request to set a new menu bar
// We return the handle so the frame may set the menu.
//
HMENU
TOleWin::OnOcAppMenus(TOcMenuDescr far* menuDescr)
{
  //
  // If OLE does not pass a handle, hand our original menu
  //
  if (!menuDescr->HMenu) {
    MergedMenu = 0;
    return HMenu;
  }

  return MergedMenu ? MergedMenu : menuDescr->HMenu;
}


//
//
//
HMENU
TOleWin::OnOcAppRestoreUI()
{
  MergedMenu = 0;
  return HMenu;
}


//
// Merges source menu popups into the destination menu.
// SrcOwnsEven determines whether the source or destination
// own the even or odd entries within the menu.
//
static bool
MergeMenu(MenuDescr& dst, const MenuDescr& src, bool srcOwnsEven)
{
  int dstOff = 0;
  int srcOff = 0;

  for (int i=0; i<MENU_GROUP_COUNT; i++) {
    if ((!(i%2) && srcOwnsEven) || ((i%2) && !srcOwnsEven)) {
      // If the current location is owned by the source, there should
      // not be anything there from the destination already.
      //
      if (dst.Width[i]) {
        // However, if the entries are occupied,
        // should they be removed/deleted - or should we just append ours?
        //
      }

      // If source has something to merge
      //
      if (src.Width[i]) {
        // Iterate through the source's menu items
        //
        int insertCount = 0;
        for (int j=0; j<src.Width[i]; j++) {
          uint state = GetMenuState(src, srcOff+j, MF_BYPOSITION);

          // Validate source menu item
          //
          if (state == uint(-1))
            break;

          // Retrieve string
          //
          char str[256];
          GetMenuString(src, srcOff+j, str, sizeof(str), MF_BYPOSITION);

          // If it's a popup, we'll share the handle
          //
          uint idOrPopup;
          if (state & MF_POPUP) {
            state &= (MF_STRING|MF_POPUP);
            HMENU sub = GetSubMenu(src, srcOff+j);
            idOrPopup = UINT(sub);
          } else {
            idOrPopup = GetMenuItemID(src, srcOff+j);
          }

          // Insert destination menu
          //
          if (GetMenuItemCount(dst) <= dstOff+j)
            AppendMenu(dst, state|MF_BYPOSITION, idOrPopup, str);
          else
            InsertMenu(dst, dstOff+j, state|MF_BYPOSITION, idOrPopup, str);

          insertCount++;
        }

        // Update dst. width by # of new entries we've added
        //
        dst.Width[i] += insertCount;
      }
    } else {
      // Here, if src.Width[i] == -1, we could delete the destinations entries
      //
    }

    // Update offset by width of entries just processed.
    //
    srcOff += src.Width[i];
    dstOff += dst.Width[i];
  }

  return true;
}


//
// Merge so that source (container) owns the even entries
//
bool
MergeContainerMenu(TOcMenuDescr& dst, const TOcMenuDescr& src)
{
  return MergeMenu(*((MenuDescr*)&dst), *((MenuDescr*)&src), true);
}


//
// Merge so that source (server) owns the odd entries
//
bool
MergeServerMenu(TOcMenuDescr& dst, const TOcMenuDescr& src)
{
  return MergeMenu(*((MenuDescr*)&dst), *((MenuDescr*)&src), false);
}


//
// Prompts user for a filename using Common Dialog
//
bool
GetOpenFileName(HWND owner, const char* filter, char* fileName,
                int size, DWORD flags)
{
   OPENFILENAME ofn;
   memset(&ofn, 0, sizeof(ofn));
   ofn.lStructSize   = sizeof(ofn);
   ofn.hwndOwner     = owner;
   ofn.lpstrFilter   = filter;
   ofn.lpstrFile     = fileName;
   ofn.nMaxFile      = size;
   ofn.Flags         = flags;
   return GetOpenFileName(&ofn);
}


//
// Prompts user for a filename using Common Dialog
//
bool
GetSaveFileName(HWND owner, const char* filter, char* fileName,
                int size, DWORD flags)
{
   OPENFILENAME ofn;
   memset(&ofn, 0, sizeof(ofn));
   ofn.lStructSize   = sizeof(ofn);
   ofn.hwndOwner     = owner;
   ofn.lpstrFilter   = filter;
   ofn.lpstrFile     = fileName;
   ofn.nMaxFile      = size;
   ofn.Flags         = flags;
   return GetSaveFileName(&ofn);
}

