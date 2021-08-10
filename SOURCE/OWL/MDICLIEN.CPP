//----------------------------------------------------------------------------
// ObjectWindows - (C) Copyright 1991, 1993 by Borland International
//   source\owl\mdiclien.cpp
//   Implementation of class TMDIClient.  This defines the basic behavior
//   of all MDI client windows.
//----------------------------------------------------------------------------
#pragma hdrignore SECTION
#include <owl\owlpch.h>
#include <owl\mdi.h>

#if !defined(SECTION) || SECTION == 1

DEFINE_RESPONSE_TABLE1(TMDIClient, TWindow)
  EV_COMMAND(CM_CREATECHILD, CmCreateChild),
  EV_COMMAND(CM_TILECHILDREN, CmTileChildren),
  EV_COMMAND(CM_TILECHILDRENHORIZ, CmTileChildrenHoriz),
  EV_COMMAND(CM_CASCADECHILDREN, CmCascadeChildren),
  EV_COMMAND(CM_ARRANGEICONS, CmArrangeIcons),
  EV_COMMAND(CM_CLOSECHILDREN, CmCloseChildren),
  EV_COMMAND_ENABLE(CM_TILECHILDREN, CmChildActionEnable),
  EV_COMMAND_ENABLE(CM_CASCADECHILDREN, CmChildActionEnable),
  EV_COMMAND_ENABLE(CM_ARRANGEICONS, CmChildActionEnable),
  EV_COMMAND_ENABLE(CM_CLOSECHILDREN, CmChildActionEnable),
  EV_WM_MDICREATE,
  EV_WM_MDIDESTROY,
END_RESPONSE_TABLE;

//
// constructor for a TMDIClient
//
// allocates space for the CLIENTCREATESTRUCT on the heap and sets
// ClientAttr to point to this space
//
TMDIClient::TMDIClient(TModule* module)
{
  //
  // Initialize virtual base, in case the derived-most used default ctor
  //
  TWindow::Init(0, 0, module);

  Attr.Id = IDW_MDICLIENT;
  //
  // allow client area to grow scroll bars if necessary
  //
  Attr.Style |= MDIS_ALLCHILDSTYLES | WS_GROUP | WS_TABSTOP | WS_CLIPCHILDREN|
                WS_VSCROLL | WS_HSCROLL;
  ClientAttr = new CLIENTCREATESTRUCT; // far
  ClientAttr->hWindowMenu = 0;
  ClientAttr->idFirstChild = IDW_FIRSTMDICHILD;
  Attr.Param = (LPSTR)ClientAttr;
  SetFlag(wfStreamTop);
}

//
// constructor for a TMDIClient which is being used in a DLL as an alias
// for a non-OWL window. This ctor is generally not used by derived
// classes
//
TMDIClient::TMDIClient(HWND hWnd, TModule* module)
  : TWindow(hWnd, module)
{
  ClientAttr = 0;
  SetFlag(wfStreamTop);
}

//
// frees the memory associated with ClientAttr
//
TMDIClient::~TMDIClient()
{
  delete ClientAttr;
}

char far*
TMDIClient::GetClassName()
{
  return "MDICLIENT";
}

TMDIChild*
TMDIClient::GetActiveMDIChild()
{
  HWND hWnd = (HWND)HandleMessage(WM_MDIGETACTIVE);

  return TYPESAFE_DOWNCAST(GetWindowPtr(hWnd),TMDIChild);
}

void
TMDIClient::ArrangeIcons()
{
  HandleMessage(WM_MDIICONARRANGE);
}

void
TMDIClient::CascadeChildren()
{
  HandleMessage(WM_MDICASCADE);
}

void
TMDIClient::TileChildren(int tile)
{
  HandleMessage(WM_MDITILE, tile);
}

BOOL
TMDIClient::PreProcessMsg(MSG& msg)
{
  if (msg.message == WM_KEYDOWN || msg.message == WM_SYSKEYDOWN)
    return TranslateMDISysAccel(HWindow, &msg);

  else
    return FALSE;
}

BOOL
TMDIClient::Create()
{
  TMDIFrame*  frame = TYPESAFE_DOWNCAST(Parent,TMDIFrame);
  
  CHECK(frame);

  ClientAttr->hWindowMenu = frame->FindChildMenu(frame->GetMenu());
  return TWindow::Create();
}

//
// creates a valid new MDI child window after calling InitChild() to construct
// a new MDI child window object
//
TWindow*
TMDIClient::CreateChild()
{
  TMDIChild* child = InitChild();
  CHECK(child);
  if (child->Create())
    return child;
  return 0;
}

TMDIChild*
TMDIClient::InitChild()
{
  return new TMDIChild(*this);
}

static BOOL
CannotClose(TWindow* win, void*)
{
  return !win->CanClose();
}

static void
CloseChild(TWindow* win, void*)
{
  win->Destroy();
  delete win;
}

//
// closes each MDI child, after calling the child's CanClose() method to
// ensure that it is Ok to do so
//
// returns TRUE if all children are closed(or there were no children),
// FALSE if any child can't be closed
//
BOOL
TMDIClient::CloseChildren()
{
  if (!FirstThat(CannotClose)) {
    ForEach(CloseChild);
    return TRUE;
  }
  return FALSE;
}

//
// fill in default child window styles if they request style 0 since this
// client by default has set allchildstyles
//
LRESULT
TMDIClient::EvMDICreate(MDICREATESTRUCT far& createStruct)
{
  if ((Attr.Style&MDIS_ALLCHILDSTYLES) && !createStruct.style)
    createStruct.style =
               WS_VISIBLE | WS_CHILD | WS_CLIPSIBLINGS | WS_CLIPCHILDREN |
               WS_SYSMENU | WS_CAPTION | WS_THICKFRAME |
               WS_MINIMIZEBOX | WS_MAXIMIZEBOX;

  //
  // deal with create maximized child problems
  //
  DWORD origStyle = createStruct.style;
  if (createStruct.style & WS_MAXIMIZE) {
    SetRedraw(FALSE);
    createStruct.style &= ~(WS_MAXIMIZE | WS_VISIBLE | WS_VSCROLL | WS_HSCROLL);
    createStruct.style |= WS_DISABLED;
  }

  LRESULT result = DefaultProcessing();

  if (HWND(result) && (origStyle & WS_MAXIMIZE)) {
    SetRedraw(TRUE);

    if (!(origStyle & WS_DISABLED))
      ::EnableWindow(HWND(result), TRUE);

    HandleMessage(WM_MDIMAXIMIZE, WPARAM(result));

    ::SetWindowLong(HWND(result), GWL_STYLE, origStyle);
  }

  return result;
}

//
// When an MDI child is destroyed while other children are hidden or disabled,
// the Windows MDI child management gets confused causing subsequent failure.
// To prevent this, we temporarily unhide and enable siblings during destroy.
//
static void sUnHide(TWindow* win, void* hWnd)
{
  if (*win == (HWND)hWnd)
    return;
  if (!win->IsWindowVisible()) {
    win->SetWindowPos(0,0,0,0,0,SWP_NOMOVE|SWP_NOSIZE|SWP_SHOWWINDOW|SWP_NOZORDER|SWP_NOACTIVATE|SWP_NOREDRAW);
    win->SetFlag(wfUnHidden);
  }
  if (!win->IsWindowEnabled()) {
    win->EnableWindow(TRUE);
    win->SetFlag(wfUnDisabled);
  }
}

static void sReHide(TWindow* win, void*)
{
  if (!*win)
    return;
  if (win->IsFlagSet(wfUnHidden)) {
    win->ClearFlag(wfUnHidden);
    win->ShowWindow(SW_HIDE);
  }
  if (win->IsFlagSet(wfUnDisabled)) {
    win->ClearFlag(wfUnDisabled);
    win->EnableWindow(FALSE);
  }
}

void
TMDIClient::EvMDIDestroy(HWND hWnd)
{
  ForEach(sUnHide,(void*)hWnd);
  DefaultProcessing();
  ForEach(sReHide, 0);
#if defined(__WIN32__)
  HandleMessage(WM_MDIREFRESHMENU);
#else
  HandleMessage(WM_MDISETMENU, TRUE);
#endif
}

//
// Enables any of the child action menu items if any MDI children exit
//
void
TMDIClient::CmChildActionEnable(TCommandEnabler& commandEnabler)
{
  commandEnabler.Enable(GetFirstChild() != 0);
}


#endif
#if !defined(SECTION) || SECTION == 2

IMPLEMENT_STREAMABLE1(TMDIClient, TWindow);

//
// reads an instance of TMDIClient from the passed ipstream
//
void*
TMDIClient::Streamer::Read(ipstream& is, uint32 /*version*/) const
{
  ReadBaseObject((TWindow*)GetObject(), is);

  GetObject()->ClientAttr = new CLIENTCREATESTRUCT;  //far

  UINT idFirstChild;  // Need temp for near data model since ClientAttr is far
  is >> idFirstChild;
  GetObject()->ClientAttr->idFirstChild = idFirstChild;
  GetObject()->ClientAttr->hWindowMenu = (HMENU) 0;
  GetObject()->Attr.Param = (LPSTR)GetObject()->ClientAttr;

  return GetObject();
}

//
// writes the TMDIClient to the passed opstream
//
void
TMDIClient::Streamer::Write(opstream& os) const
{
  WriteBaseObject((TWindow*)GetObject(), os);
  os << GetObject()->ClientAttr->idFirstChild;
}

#endif
