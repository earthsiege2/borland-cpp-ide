//----------------------------------------------------------------------------
// ObjectWindows
// Copyright (c) 1991, 1996 by Borland International, All Rights Reserved
//
//$Revision:   10.5  $
//
// Implementation of TMDIChild. This defines the basic behavior of all MDI
// child windows
//----------------------------------------------------------------------------
#pragma hdrignore SECTION
#include <owl/pch.h>
#if !defined(OWL_MDICHILD_H)
# include <owl/mdichild.h>
#endif
#if !defined(OWL_MDI_H)
# include <owl/mdi.h>
#endif
#if !defined(OWL_APPLICAT_H)
# include <owl/applicat.h>
#endif

DIAG_DECLARE_GROUP(OwlWin);  // diagnostic group for windows

#if !defined(WS_EX_MDICHILD)
# define WS_EX_MDICHILD          0x00000040L
#endif

//
// Define to not work around here in the client, the 'creating MDI child
// maximized corrupts the menu bar' bug
//
//#define NO_MDIMAX_WORKAROUND

#if !defined(SECTION) || SECTION == 1

DEFINE_RESPONSE_TABLE1(TMDIChild, TFrameWindow)
  EV_WM_MDIACTIVATE,
  EV_WM_NCACTIVATE,
END_RESPONSE_TABLE;

//
// Constructor for a TMDIChild
//
TMDIChild::TMDIChild(TMDIClient&     parent,
                     const char far* title,
                     TWindow*        clientWnd,
                     bool            shrinkToClient,
                     TModule*        module)
{
  // Initialize virtual bases, in case the derived-most used default ctor
  //
  TWindow::Init(&parent, title, module);
  TFrameWindow::Init(clientWnd, shrinkToClient);

  Attr.Style = WS_VISIBLE | WS_CHILD | WS_CLIPSIBLINGS | WS_CLIPCHILDREN |
               WS_SYSMENU | WS_CAPTION | WS_THICKFRAME |
               WS_MINIMIZEBOX | WS_MAXIMIZEBOX;

  Attr.ExStyle |= WS_EX_MDICHILD;

  Attr.Y = Attr.H = CW_USEDEFAULT;
}

//
// Constructor for a TMDIChild which is being used in a DLL as an alias
// for a non-OWL window
//
TMDIChild::TMDIChild(THandle handle, TModule* module)
:
  TFrameWindow(handle, module),
  TWindow(handle, module)
{
  Attr.Style = WS_CLIPSIBLINGS;
  Attr.ExStyle |= WS_EX_MDICHILD;
}

//
// Destructor for a MDI child
//
TMDIChild::~TMDIChild()
{
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
    if ((THandle)Parent->HandleMessage(WM_MDIGETACTIVE) == *this) {
      if (cmdShow == SW_HIDE)
        Parent->HandleMessage(WM_MDINEXT, (uint)(THandle)*this);
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
    if (!enable && (THandle)Parent->HandleMessage(WM_MDIGETACTIVE) == *this)
      Parent->HandleMessage(WM_MDINEXT, (uint)(THandle)*this);
#if defined(BI_PLAT_WIN32)
    Parent->HandleMessage(WM_MDIREFRESHMENU);
#else
    Parent->HandleMessage(WM_MDISETMENU, true);
#endif
  }
  return retVal;
}

//
// If the MDI child has requested keyboard navigation then TFrameWindow's
// PreProcessMsg() member function will call ::IsDialogMessage() which will
// eat the event and the MDI client window won't get a chance to do MDI
// accelerator processing
//
// So, we will do it here to make sure it gets done
//
bool
TMDIChild::PreProcessMsg(MSG& msg)
{
  if (KeyboardHandling && Parent->PreProcessMsg(msg))
    return true;

  if (HAccel && ::TranslateAccelerator(Parent->Parent->GetHandle(), HAccel, &msg))
    return true;

  return TFrameWindow::PreProcessMsg(msg);
}

//
// Destroys the MS-Windows element associated with the TMDIChild
//
void
TMDIChild::Destroy(int)
{
  if (GetHandle()) {
    ForEach(::DoEnableAutoCreate);  // use iterator function in window.cpp

    if (Parent) {
      // Send destroy message to MDI client window to have it destroy this THandle
      //
      Parent->HandleMessage(WM_MDIDESTROY, TParam1(GetHandle()));
      SetHandle(0);  // Assume success
    }
    else {
      if (::DestroyWindow(GetHandle()))
        SetHandle(0);
      GetApplication()->ResumeThrow();
      WARNX(OwlWin, GetHandle(), 0, "::DestroyWindow(" << (uint)GetHandle() << ") failed");
    }
  }
}

//
// An MDI Child creates its GetHandle() by sending an MDI Create packet to the MDI
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
  createStruct.lParam = TParam2(Attr.Param);

  // Work around a Windows MDI bug w/ bad menus if MDI child is created
  // maximized, by hiding child now & maximizing later
  //
#if defined(MDIMAX_WORKAROUND)
  uint32 origStyle = Attr.Style;
  if (createStruct.style & WS_MAXIMIZE)
    createStruct.style &= ~(WS_MAXIMIZE | WS_VISIBLE);
#endif

  SetHandle((THandle)Parent->HandleMessage(WM_MDICREATE, 0, TParam2(&createStruct)));

  // Finish up maximized MDI child workaround
  //
#if defined(MDIMAX_WORKAROUND)
  if (GetHandle() && (origStyle & WS_MAXIMIZE)) {
    Parent->HandleMessage(WM_MDIMAXIMIZE, TParam1(GetHandle()));
#if defined(BI_PLAT_WIN32)
    Parent->HandleMessage(WM_MDIREFRESHMENU);
#else
    Parent->HandleMessage(WM_MDISETMENU, true);
#endif
  }
#endif
}

//
//
//
void
TMDIChild::EvMDIActivate(THandle hActivated, THandle hDeactivated)
{
  if (GetHandle() == hActivated) {

    // A bug in Windows MDI causes the first MDI child to not get a
    // WM_SETFOCUS. Simulate it now
    //
    if (!GetWindow(GW_HWNDNEXT) && GetFocus() != GetHandle())
      HandleMessage(WM_SETFOCUS, TParam1(GetHandle()));

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
    if (GetMenuDescr() && !hActivated) {
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
    w->HandleMessage(WM_MDIACTIVATE, TParam1(hDeactivated), TParam2(hActivated));
#else
    w->HandleMessage(WM_MDIACTIVATE, 0, MkParam2(hActivated,hDeactivated));
#endif

  DefaultProcessing();
}

//
// Override DefWindowProc to use DefMDIChildProc
//
TResult
TMDIChild::DefWindowProc(uint msg, TParam1 param1, TParam2 param2)
{
  if (IsFlagSet(wfAlias))
    return TWindow::DefWindowProc(msg, param1, param2);

  return ::DefMDIChildProc(GetHandle(), msg, param1, param2);
}

#endif
#if !defined(SECTION) || SECTION == 2


IMPLEMENT_STREAMABLE2(TMDIChild, TFrameWindow, TWindow);

#if !defined(BI_NO_OBJ_STREAMING)

//
// Reads data of the TMDIChild from the passed opstream
//
void*
TMDIChild::Streamer::Read(ipstream& is, uint32 /*version*/) const
{
  ReadVirtualBase((TFrameWindow*)GetObject(), is);
  return GetObject();
}

//
// Writes data of the TMDIChild to the passed opstream
//
void
TMDIChild::Streamer::Write(opstream& os) const
{
  WriteVirtualBase((TFrameWindow*)GetObject(), os);
}

#endif  // if !defined(BI_NO_OBJ_STREAMING)

#endif
