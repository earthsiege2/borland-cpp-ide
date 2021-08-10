//----------------------------------------------------------------------------
// ObjectWindows - (C) Copyright 1991, 1993 by Borland International
//   source\owl\mdichild.cpp
//   Defines class TMDIChild. This defines the basic behavior of all MDI
//   child windows
//----------------------------------------------------------------------------
#pragma hdrignore SECTION
#include <owl\owlpch.h>
#include <owl\mdichild.h>
#include <owl\mdi.h>


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
                     BOOL            shrinkToClient,
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
// constructor for a TMDIChild which is being used in a DLL as an alias
// for a non-OWL window
//
TMDIChild::TMDIChild(HWND hWnd, TModule*   module)
  : TFrameWindow(hWnd, module),
    TWindow(hWnd, module)
{
  Attr.Style = WS_CLIPSIBLINGS;
}

BOOL
TMDIChild::EvNCActivate(BOOL active)
{
  return IsFlagSet(wfUnHidden) ? FALSE : TFrameWindow::EvNCActivate(active);
}

BOOL
TMDIChild::ShowWindow(int cmdShow)
{
  int  retVal = TFrameWindow::ShowWindow(cmdShow);     // 0 if had been hidden
  if ((retVal != 0) != (cmdShow != SW_HIDE)) { // if visible state has changed
    if ((HWND)Parent->HandleMessage(WM_MDIGETACTIVE) == *this) {
      if (cmdShow == SW_HIDE)
        Parent->HandleMessage(WM_MDINEXT, (UINT)(HWND)*this);
      else
        HandleMessage(WM_NCACTIVATE, TRUE); // resend suppressed message
    }
#if defined(__WIN32__)
    Parent->HandleMessage(WM_MDIREFRESHMENU);
#else
    Parent->HandleMessage(WM_MDISETMENU, TRUE);
#endif
  }
  return retVal;
}

BOOL
TMDIChild::EnableWindow(BOOL enable)
{
  int retVal = TFrameWindow::EnableWindow(enable);  // 0 if previously enabled
  if ((retVal!=0) != (enable==0)) {  // if disabled state has actually changed
    if (!enable && (HWND)Parent->HandleMessage(WM_MDIGETACTIVE) == *this)
      Parent->HandleMessage(WM_MDINEXT, (UINT)(HWND)*this);
#if defined(__WIN32__)
    Parent->HandleMessage(WM_MDIREFRESHMENU);
#else
    Parent->HandleMessage(WM_MDISETMENU, TRUE);
#endif
  }
  return retVal;
}

BOOL
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
    return TRUE;

  if (hAccel && ::TranslateAccelerator(Parent->Parent->HWindow, hAccel, &msg))
    return TRUE;

  return TFrameWindow::PreProcessMsg(msg);
}

//
// destroys the MS-Windows element associated with the TMDIChild
//
void
TMDIChild::Destroy(int)
{
  if (HWindow) {
    ForEach(DoEnableAutoCreate);

    if (Parent) // send destroy message to MDI client window
      Parent->HandleMessage(WM_MDIDESTROY, (WPARAM) HWindow);

    else
      ::DestroyWindow(HWindow);
  }
}

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

  DWORD style = Attr.Style;
  if (style & WS_MAXIMIZE) {  // Work around a Windows MDI bug
    Attr.Style &= ~(WS_MAXIMIZE | WS_VISIBLE);
    Attr.Style |= WS_DISABLED;
  }
  createStruct.style = Attr.Style;
  createStruct.lParam = (LPARAM)Attr.Param;

  HWindow = (HWND)Parent->HandleMessage(WM_MDICREATE, 0, (LPARAM)&createStruct);

  if (style & WS_MAXIMIZE) {  // finish up maximized mdi workaround
    EnableWindow(TRUE);
                Attr.Style = style;
    Parent->HandleMessage(WM_MDIMAXIMIZE, WPARAM(HWindow));
  }
}

void
TMDIChild::EvMDIActivate(HWND hWndActivated,
                         HWND /*hWndDeactivated*/)
{
  if (HWindow == hWndActivated) {
    //
    // A bug in Windows MDI causes the first MDI child to not get a
    // WM_SETFOCUS. Simulate it now
    //
    if (!GetWindow(GW_HWNDNEXT) && GetFocus() != HWindow)
      HandleMessage(WM_SETFOCUS, WPARAM(HWindow));

    //
    // Merge this windows menubar with the MDI frame's if there is a
    // MenuDescr assigned
    //
    if (GetMenuDescr()) {
      TFrameWindow* frame = TYPESAFE_DOWNCAST(Parent->Parent,TFrameWindow);
      if (frame)
        frame->MergeMenu(*GetMenuDescr());
    }

  } else {
    //
    // Restore the MDI frame's menubar if there is no other MDI child being
    // activated
    //
    if (GetMenuDescr() && !hWndActivated) {
      TFrameWindow* frame = TYPESAFE_DOWNCAST(Parent->Parent,TFrameWindow);
      if (frame)
        frame->RestoreMenu();
    }
  }
}

//
// override DefWindowProc to use DefMDIChildProc
//
LRESULT
TMDIChild::DefWindowProc(UINT msg, WPARAM wParam, LPARAM lParam)
{
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
