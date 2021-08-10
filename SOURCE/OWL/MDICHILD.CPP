//----------------------------------------------------------------------------
// ObjectWindows
// (C) Copyright 1991, 1994 by Borland International, All Rights Reserved
//
//   Implementation of TMDIChild. This defines the basic behavior of all MDI
//   child windows
//----------------------------------------------------------------------------
#pragma hdrignore SECTION
#include <owl/owlpch.h>
#include <owl/mdichild.h>
#include <owl/mdi.h>
#include <owl/applicat.h>

DIAG_DECLARE_GROUP(OwlWin);  // diagnostic group for windows

// Define to work around here in the child, the 'creating MDI child maximized
// corrupts the menu bar' bug 
//
#define MDIMAX_WORKAROUND

#if !defined(SECTION) || SECTION == 1

DEFINE_RESPONSE_TABLE1(TMDIChild, TFrameWindow)
  EV_WM_MDIACTIVATE,
  EV_WM_NCACTIVATE,
END_RESPONSE_TABLE;

//
// constructor for a TMDIChild
//
TMDIChild::TMDIChild(TMDIClient&     parent,
                     const char far* title,
                     TWindow*        clientWnd,
                     bool            shrinkToClient,
                     TModule*        module)
{
  //
  // Initialize virtual bases, in case the derived-most used default ctor
  //
  TWindow::Init(&parent, title, module);
  TFrameWindow::Init(clientWnd, shrinkToClient);

  Attr.Style = WS_VISIBLE | WS_CHILD | WS_CLIPSIBLINGS | WS_CLIPCHILDREN |
               WS_SYSMENU | WS_CAPTION | WS_THICKFRAME |
               WS_MINIMIZEBOX | WS_MAXIMIZEBOX;
  Attr.Y = Attr.H = CW_USEDEFAULT;
}

//
// Constructor for a TMDIChild which is being used in a DLL as an alias
// for a non-OWL window
//
TMDIChild::TMDIChild(HWND hWnd, TModule*   module)
:
  TFrameWindow(hWnd, module),
  TWindow(hWnd, module)
{
  Attr.Style = WS_CLIPSIBLINGS;
}

//
// Don't allow NC Activation if we are only temporarily unhidden for window
// menu maintainance
//
bool
TMDIChild::EvNCActivate(bool active)
{
  return IsFlagSet(wfUnHidden) ? false : TFrameWindow::EvNCActivate(active);
}

//
// Perform special processing for showing MDI children to make sure that
// the MDI client maintains the window list correctly
//
bool
TMDIChild::ShowWindow(int cmdShow)
{
  int  retVal = TFrameWindow::ShowWindow(cmdShow);     // 0 if had been hidden

  // Process only if visible state has changed
  //
  if ((retVal != 0) != (cmdShow != SW_HIDE)) {
    if ((HWND)Parent->HandleMessage(WM_MDIGETACTIVE) == *this) {
      if (cmdShow == SW_HIDE)
        Parent->HandleMessage(WM_MDINEXT, (uint)(HWND)*this);
      else
        HandleMessage(WM_NCACTIVATE, true); // resend suppressed message
    }
#if defined(BI_PLAT_WIN32)
    Parent->HandleMessage(WM_MDIREFRESHMENU);
#else
    Parent->HandleMessage(WM_MDISETMENU, true);
#endif
  }
  return retVal;
}

//
// Perform special processing for enabling MDI children to make sure that
// the MDI client maintains the window list correctly
//
bool
TMDIChild::EnableWindow(bool enable)
{
  int retVal = TFrameWindow::EnableWindow(enable);  // 0 if previously enabled

  // Process only if disabled state has actually changed
  //
  if ((retVal!=0) != (enable==0)) {
    if (!enable && (HWND)Parent->HandleMessage(WM_MDIGETACTIVE) == *this)
      Parent->HandleMessage(WM_MDINEXT, (uint)(HWND)*this);
#if defined(BI_PLAT_WIN32)
    Parent->HandleMessage(WM_MDIREFRESHMENU);
#else
    Parent->HandleMessage(WM_MDISETMENU, true);
#endif
  }
  return retVal;
}

bool
TMDIChild::PreProcessMsg(MSG& msg)
{
  //
  // if the MDI child has requested keyboard navigation then TFrameWindow's
  // PreProcessMsg() member function will call ::IsDialogMessage() which will
  // eat the event and the MDI client window won't get a chance to do MDI
  // accelerator processing
  //
  // so, we will do it here to make sure it gets done
  //
  if (KeyboardHandling && Parent->PreProcessMsg(msg))
    return true;

  if (hAccel && ::TranslateAccelerator(Parent->Parent->HWindow, hAccel, &msg))
    return true;

  return TFrameWindow::PreProcessMsg(msg);
}

//
// Destroys the MS-Windows element associated with the TMDIChild
//
void
TMDIChild::Destroy(int)
{
  if (HWindow) {
    ForEach(DoEnableAutoCreate);  // use iterator function in window.cpp

    if (Parent) { // send destroy message to MDI client window
      Parent->HandleMessage(WM_MDIDESTROY, (WPARAM)HWindow);
      HWindow = 0;  // Assume success
    }
    else {
      if (::DestroyWindow(HWindow))
        HWindow = 0;
      GetApplication()->ResumeThrow();
      WARNX(OwlWin, HWindow, 0, "::DestroyWindow(" << (uint)HWindow << ") failed");
    }
  }
}

//
// An MDI Child creates its HWindow by sending an MDI Create packet to the MDI
// client.
//
void
TMDIChild::PerformCreate(int)
{
  PRECONDITION(Parent);

  MDICREATESTRUCT  createStruct;
  createStruct.szClass = GetClassName();
  createStruct.szTitle = Title;
  createStruct.hOwner = *GetModule();
  createStruct.x = Attr.X;
  createStruct.y = Attr.Y;
  createStruct.cx = Attr.W;
  createStruct.cy = Attr.H;
  createStruct.style = Attr.Style;
  createStruct.lParam = (LPARAM)Attr.Param;

  // Work around a Windows MDI bug w/ bad menus if MDI child is created
  // maximized, by hiding child now & maximizing later
  //
#if defined(MDIMAX_WORKAROUND)
  uint32 origStyle = Attr.Style;
  if (createStruct.style & WS_MAXIMIZE)
    createStruct.style &= ~(WS_MAXIMIZE | WS_VISIBLE);
#endif

  HWindow = (HWND)Parent->HandleMessage(WM_MDICREATE, 0, (LPARAM)&createStruct);

  // Finish up maximized MDI child workaround
  //
#if defined(MDIMAX_WORKAROUND)
  if (HWindow && (origStyle & WS_MAXIMIZE)) {
    Parent->HandleMessage(WM_MDIMAXIMIZE, WPARAM(HWindow));
#if defined(BI_PLAT_WIN32)
    Parent->HandleMessage(WM_MDIREFRESHMENU);
#else
    Parent->HandleMessage(WM_MDISETMENU, true);
#endif
  }
#endif
}

void
TMDIChild::EvMDIActivate(HWND hWndActivated, HWND hWndDeactivated)
{
  if (HWindow == hWndActivated) {
    // A bug in Windows MDI causes the first MDI child to not get a
    // WM_SETFOCUS. Simulate it now
    //
    if (!GetWindow(GW_HWNDNEXT) && GetFocus() != HWindow)
      HandleMessage(WM_SETFOCUS, WPARAM(HWindow));

    // Merge this windows menubar with the MDI frame's if there is a
    // MenuDescr assigned
    //
    if (GetMenuDescr()) {
      TFrameWindow* frame = TYPESAFE_DOWNCAST(Parent->Parent,TFrameWindow);
      if (frame)
        frame->MergeMenu(*GetMenuDescr());
    }
  }
  else {
    // Restore the MDI frame's menubar if there is no other MDI child being
    // activated
    //
    if (GetMenuDescr() && !hWndActivated) {
      TFrameWindow* frame = TYPESAFE_DOWNCAST(Parent->Parent,TFrameWindow);
      if (frame)
        frame->RestoreMenu();
    }
  }

  // Forward MDI child activation to our client (if we have one) so that it can
  // perform any type of activate/deactivate processing that it needs
  //
  TWindow* w = GetClientWindow();
  if (w && w->IsWindow())
#if defined(BI_PLAT_WIN32)
    w->HandleMessage(WM_MDIACTIVATE, WPARAM(hWndDeactivated), LPARAM(hWndActivated));
#else
    w->HandleMessage(WM_MDIACTIVATE, 0, MAKELPARAM(hWndActivated,hWndDeactivated));
#endif
}

//
// override DefWindowProc to use DefMDIChildProc
//
LRESULT
TMDIChild::DefWindowProc(uint msg, WPARAM wParam, LPARAM lParam)
{
  if (IsFlagSet(wfAlias))
    return TWindow::DefWindowProc(msg, wParam, lParam);

  return ::DefMDIChildProc(HWindow, msg, wParam, lParam);
}

#endif
#if !defined(SECTION) || SECTION == 2


IMPLEMENT_STREAMABLE2(TMDIChild, TFrameWindow, TWindow);

void*
TMDIChild::Streamer::Read(ipstream& is, uint32 /*version*/) const
{
  ReadVirtualBase((TFrameWindow*)GetObject(), is);
  return GetObject();
}

//
// writes data of the TMDIChild to the passed opstream
//
void
TMDIChild::Streamer::Write(opstream& os) const
{
  WriteVirtualBase((TFrameWindow*)GetObject(), os);
}

#endif
