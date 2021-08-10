//----------------------------------------------------------------------------
// ObjectWindows
// Copyright (c) 1991, 1997 by Borland International, All Rights Reserved
//
//$Revision:   10.15  $
//
// Implementation of class TDialog. TDialogs are the base for any type of
// modal or modeless window that loads itself from resource.
//----------------------------------------------------------------------------
#pragma hdrignore SECTION
#include <owl/pch.h>
#if !defined(OWL_DIALOG_H)
# include <owl/dialog.h>
#endif
#if !defined(OWL_APPLICAT_H)
# include <owl/applicat.h>
#endif
# include <string.h>

#if defined(BI_COMP_BORLANDC)
# include <bwcc.h>           // Currently only available with Borland C++
#endif

OWL_DIAGINFO;
DIAG_DECLARE_GROUP(OwlMsg);  // diagnostic group for message tracing
DIAG_DECLARE_GROUP(OwlWin);  // diagnostic group for windows

#if !defined(SECTION) || SECTION == 1

#if !defined(RT_DLGINIT)
# define RT_DLGINIT       MAKEINTRESOURCE(240)
#endif

//
// Global message id for GetWindowPtr call defined in applicat.cpp
//
extern uint _OWLDATA GetWindowPtrMsgId;

//
// Public so derived classes can create  
//
TDialog* _OWLDATA DlgCreationWindow = 0;

DEFINE_RESPONSE_TABLE1(TDialog, TWindow)
  EV_WM_CLOSE,
  EV_WM_PAINT,
  EV_WM_CTLCOLOR,
  EV_WM_SETFONT,
  EV_DM_GETDEFID,
  EV_DM_SETDEFID,
#if defined(BI_PLAT_WIN32)
  EV_DM_REPOSITION,
#endif
  EV_COMMAND(IDOK, CmOk),
  EV_COMMAND(IDCANCEL, CmCancel),
END_RESPONSE_TABLE;

//
// Constructor for a TDialog object
//
// Takes an TResId for its template name or numeric Id
//
TDialog::TDialog(TWindow* parent, TResId resId, TModule* module)
{
  // Initialize virtual base, in case the derived-most used default ctor
  //
  TWindow::Init(parent, 0, module);

  DisableAutoCreate();
  if (HiUint16(uint32(Title)))
    delete[] Title;
  Title = (LPSTR)MAKEINTRESOURCE(0xFFFF); // Title setting--"don't-change"

  SetFlag(wfFromResource);
  ClearFlag(wfDeleteOnClose);

  DialogAttr.Param = 0;
  IsModal = false;
  DialogAttr.Name = resId.IsString() ? strnewdup(resId) : (char far*)resId;
}

//
// Destructor for a TDialog
//
TDialog::~TDialog()
{
  if (HiUint16(uint32(DialogAttr.Name)))
    delete[] DialogAttr.Name;
}

//
// Preprocess posted messages to provide various accelerator translations.
// Handles normal window accelerators, MDI accelerators & dialog accelerators
//
bool
TDialog::PreProcessMsg(MSG& msg)
{
  // Processed any accelerators associated with this window
  //
  if (TWindow::PreProcessMsg(msg))
    return true;

  // See if we are in an mdi child, & try mdi accelerator translation if so
  //
  THandle child;
  THandle client;
  if ((child = GetParentH()) != 0 &&
      (client = ::GetParent(child)) != 0 &&
      child == (THandle)::SendMessage(client, WM_MDIGETACTIVE, 0, 0) &&
      ::TranslateMDISysAccel(client, &msg))
    return true;

  // Do dialog accelerator translation last, since it tends to eat other
  // accelerators
  //
  return ::IsDialogMessage(GetHandle(), &msg);
}

//
// Override TWindow virtual in order to supply the classname for Windows class
// registration. Handles BWCC and native dialog classnames.
//
char far*
TDialog::GetClassName()
{
#if defined(BI_COMP_BORLANDC)
  if (GetApplication()->BWCCEnabled())
    return BORDLGCLASS;
  else
#endif
    return (char far*)WC_DIALOG;
}

//
// Override TWindow virtual in order to fill in the appropriate information
// in the WNDCLASS structure. Handles BWCC and native dialogs, retrieving the
// default class information from those existing classes.
//
void
TDialog::GetWindowClass(WNDCLASS& wndClass)
{
  TResId dlgClass;

#if defined(BI_COMP_BORLANDC)
  if (GetApplication()->BWCCEnabled()) {
    GetApplication()->GetBWCCModule()->Register(*GetModule());
    dlgClass = BORDLGCLASS;
  }
  else
#endif
    dlgClass = WC_DIALOG;

  if (!TUser::GetClassInfo(0, dlgClass, &wndClass))
    GetModule()->GetClassInfo(dlgClass, &wndClass);

  wndClass.lpszClassName = GetClassName();
  wndClass.hInstance = *GetModule();   
}

//
// Handler for WM_SETFONT, is dispatched from DialogFunction() once
// during dialog creation. Subsequent dispatched are done normally.
//
void
TDialog::EvSetFont(HFONT /*hFont*/, bool /*redraw*/)
{
  if (IsFlagSet(wfFullyCreated))
    DefaultProcessing();
}

//
// Handler for WM_PAINT. Rerout this message back to the underlying dialog to
// keep TWindow::EvPaint from eating it.
//
void
TDialog::EvPaint()
{
  DefaultProcessing();
}

//
// If this app is using Ctl3d, forward the WM_CTLCOLOR message to the
// ctl3d.dll since it needs to handle that & we don't let it autosubclass
//
HBRUSH
TDialog::EvCtlColor(HDC hDC, THandle hChild, uint ctlType)
{
  if (GetApplication()->Ctl3dEnabled()) {
#if defined(BI_PLAT_WIN32)
    HBRUSH hBr = GetApplication()->GetCtl3dModule()->
          CtlColorEx(WM_CTLCOLORMSGBOX+ctlType, TParam1(hDC), TParam2(hChild));
#else
    HBRUSH hBr = GetApplication()->GetCtl3dModule()->
          CtlColorEx(WM_CTLCOLOR, TParam1(hDC), MkParam2(uint16(hChild), ctlType));
#endif

    if (hBr)
      return hBr;
  }
  return TWindow::EvCtlColor(hDC, hChild, ctlType);
}

//
// Return the default Id.
// High word must be DC_HASDEFID.
//
uint32
TDialog::EvGetDefId()
{
  return DefaultProcessing();
}

//
// Set the pushbutton with identifier id the default button for the dialog.
//
bool
TDialog::EvSetDefId(int /*id*/)
{
  return (bool)DefaultProcessing();
}

#if defined(BI_PLAT_WIN32)
//
// Reposition the dialog so that it fits within the desktop area
//
void
TDialog::EvReposition()
{
  DefaultProcessing();
}
#endif

//
// The default dialog function. Handles the two mesages, WM_INITDIALOG and
// WM_SETFONT that may be passed to us without sending, or sent before we get
// a chance to thunk DIALOG's window proc.
//
// EvInitDialog is called as a virtual function, while EvSetFont is dispatched
// to.
//
bool
TDialog::DialogFunction(uint msg, TParam1 param1, TParam2 param2)
{
  TRACEX(OwlMsg, 2, MsgName(msg) << "(DlgFcn)=> " << *this);

  switch (msg) {

    // 'Dispatch' WM_INITDIALOG by making a virtual call--no response table
    // used. This is not generally overriden, and only arrives once.
    //
    case WM_INITDIALOG:
      return EvInitDialog((THandle)param1);

    // Dispatch WM_SETFONT only for the first, non-sent occurance. Subsequent
    // WM_SETFONTs will be dispatched normally in TWindow.
    //
    case WM_SETFONT:
      if (!IsFlagSet(wfFullyCreated)) {
        TEventInfo  eventInfo(msg);
        if (Find(eventInfo)) {
          return Dispatch(eventInfo, param1, param2) == 0;
        }
      }
      return true;

    // Catch these few messages here & forward to the ctrl3d dll if it is
    // loaded and enabled.
    //
    case WM_SETTEXT:
    case WM_NCPAINT:
    case WM_NCACTIVATE:
      if (GetApplication()->Ctl3dEnabled()) {
        SetMsgResult(GetApplication()->GetCtl3dModule()->
          DlgFramePaint(GetHandle(), msg, param1, param2));
      }
      break;
  }
  return false;  // Not handled
}

//
// Handles messages that comes from WC_DIALOG's wndProc
//
// If DlgCreationWindow is not 0, then msg is destined for DlgCreationWindow.
// Setup DlgCreationWindow's GetHandle(), subclass the WC_DIALOG class's window
// function. Calls the virtual DialogFunction() to handle specific messages,
// mostly for startup sequence.
//
/*OWL_EXPORT*/ int CALLBACK OWL_EXPORT16
TDialog::StdDlgProc(THandle hDlg, uint msg, TParam1 param1, TParam2 param2)
{
  // Thunk on first message to a non-thunked window & thats not one sent to
  // parent dialogs.
  //
  if (msg == GetWindowPtrMsgId) // if it gets here, we wont know how to get it
    return false;

  // Get the window ptr using the global version since there is no other
  // context.
  //
#if defined(BI_NAMESPACE)
  TWindow*  w = OWL::GetWindowPtr(hDlg);
#else
  TWindow*  w = ::GetWindowPtr(hDlg);
#endif
  TDialog*  dialog = TYPESAFE_DOWNCAST(w, TDialog);

  if (DlgCreationWindow && !dialog && msg != WM_CANCELMODE && msg != WM_ENABLE) {
    DlgCreationWindow->SetHandle(hDlg);

    DlgCreationWindow->SubclassWindowFunction();
    dialog = DlgCreationWindow;
    DlgCreationWindow = 0;
  }
  if (!dialog)
    return false;

  // Handle all messages once thunked.
  // Call the virtual DialogFunction() to handle specific messages
  //
#if defined(BI_PLAT_WIN32)
  if (TSystem::SupportsExceptions())
    return dialog->DialogFunction(msg, param1, param2);
#endif
#if defined(BI_PLAT_WIN16) || defined(WIN32S_SUPPORT)
  TRY {
    return dialog->DialogFunction(msg, param1, param2);
  }
  CATCH( (TXOwl& x) {
    w->GetApplication()->SuspendThrow(x);
  })
  CATCH( (xalloc& x) {
    w->GetApplication()->SuspendThrow(x);
  })
  CATCH( (xmsg& x) {
    w->GetApplication()->SuspendThrow(x);
  })
#if !defined(BI_NO_NEW_CASTS)
  CATCH( (Bad_cast) {
    w->GetApplication()->SuspendThrow(TApplication::xsBadCast);
  })
  CATCH( (Bad_typeid) {
    w->GetApplication()->SuspendThrow(TApplication::xsBadTypeid);
  })
#endif
  CATCH( (...) {
    w->GetApplication()->SuspendThrow(TApplication::xsUnknown);
  })
#endif

  // When exceptions are disabled CATCH is defined as empty, so the only code
  // is the TRY block, making this return unreachable
  //
#pragma warn -rch
  return true;  // default value returned when exception caught
#pragma warn .rch
}

//
//
//
static bool
RegisterFails(TWindow* win, void*)
{
  return !win->Register();
}

// Register all the dialog's child objects (for custom control support)
//
void
TDialog::RegisterChildObjects()
{
  if (FirstThat(RegisterFails))
    TXWindow::Raise(this, IDS_CHILDREGISTERFAIL);
}

//
// Creates an Windows modeless dialog and associates the modeless dialog
// interface element with the TDialog
//
bool
TDialog::Create()
{
  PRECONDITION(GetHandle() == 0);

  IsModal = false;

  if (!Register())
    TXWindow::Raise(this, IDS_CLASSREGISTERFAIL);

  DlgCreationWindow = this;

  LoadAcceleratorTable();

  // Register all the dialog's child objects (for custom control support)
  //
  RegisterChildObjects();

  SetHandle(DoCreate());
  GetApplication()->ResumeThrow();
  if (!GetHandle())
    TXWindow::Raise(this, IDS_WINDOWCREATEFAIL);

  GetHWndState();
  return true;
}

//
// Overriden TWindow virtual to create & return the actual Handle for this
// dialog.
//
TWindow::THandle
TDialog::DoCreate()
{
  return ::CreateDialogParam(*GetModule(), DialogAttr.Name,
                             Parent? Parent->GetHandle() : 0,
                             (DLGPROC)StdDlgProc,
                             DialogAttr.Param);
}

//
// Creates an modal dialog and associates the modal dialog interface
// element with the TDialog.  Registers all the dialog's child objects
// (for custom control support).  If this registering fails, throws TXWindow
// exception.  If the dialog fails to execute, throw a TXWindow exception.
// Returns the return value from the dialog manager.
//
int
TDialog::Execute()
{
  PRECONDITION(GetHandle() == 0);

  IsModal = true;

  if (!Register())
    TXWindow::Raise(this, IDS_CLASSREGISTERFAIL);

  DlgCreationWindow = this;

  // Register all the dialog's child objects (for custom control support)
  //
  RegisterChildObjects();

  int retValue = DoExecute();
  GetApplication()->ResumeThrow();

  // DoEcecute returns -1 if it could not create the dialog box
  //
  if (retValue == -1)
    TXWindow::Raise(this, IDS_WINDOWEXECUTEFAIL);

  return retValue;
}

//
//
// Overriden TWindow virtual to modaly execute this dialog & return the result.
//
int
TDialog::DoExecute()
{
  return ::DialogBoxParam(*GetModule(), DialogAttr.Name,
                          Parent ? Parent->GetHandle() : 0,
                          (DLGPROC)StdDlgProc,
                          DialogAttr.Param);
}

//
// Perform resource directed initialization of controls. Uses RT_DLGINIT
// resource with an id matching this dialog's as structured message packets
// to send to controls.
//
// Returns true if successful, or nothing to be done.
//
bool
TDialog::PerformDlgInit()
{
  int rslt = (int)SendMessage(WM_VBXINITFORM, TParam1(GetHandle()),
                              TParam2(DialogAttr.Name));
  if (rslt)
    return rslt > 0;

  bool ok = true;

#if defined(BI_COMP_BORLANDC)
  if (DialogAttr.Name) {
    HRSRC hRes = GetModule()->FindResource(DialogAttr.Name, RT_DLGINIT);
    if (hRes) {
      HGLOBAL hDat = GetModule()->LoadResource(hRes);
      if (hDat) {
        char HUGE* res = (char HUGE*)::LockResource(hDat);
        if (res) {
          while (ok && *res) {
            uint16 idCtl = *((uint16 far*)res)++;
            uint16 msg = *((uint16 far*)res)++;
            uint32 len = *((uint32 far*)res)++;

            if (SendDlgItemMessage(idCtl, msg, 0, TParam2(res)) == -1)
              ok = false;
            res += len;
          }
#if !defined(BI_PLAT_WIN32)
          ::UnlockResource(hDat);
#endif
        }
#if !defined(BI_PLAT_WIN32)
        ::FreeResource(hDat);
#endif
        GetApplication()->ResumeThrow();
      }
    }
  }
#endif
  return ok;
}

//
// Virtual handler for WM_INITDIALOG message, called from DialogFunction()
//
// This message is sent after an Windows dialog is created and before the
// dialog is displayed
//
// Calls SetupWindow() to perform setup for the dialog
//
bool
TDialog::EvInitDialog(THandle /*hFocus*/)
{
  GetHWndState();
  PerformDlgInit();
  SetupWindow();
  SetFlag(wfFullyCreated);
  return true;  // have Windows set focus to "hFocus"
}

//
// Sets up the dialog box by calling setting up Ctl3d if enabled, then
// calling SetCaption() and then TWindow::SetupWindow()
//
// Calling SetCaption() here allows us to override the dialog caption
// (specified in the dialog resource) by setting Title prior to this point
//
void
TDialog::SetupWindow()
{
  // If this app is using Ctl3d, tell it to explicitly subclass this dialog's
  // controls (CTL3D_ALL). Its better to do this here than enable
  // autosubclassing since that requires a CBT hook set all the time which
  // slows the app considerably.
  //
  if (GetApplication()->Ctl3dEnabled())
    GetApplication()->GetCtl3dModule()->SubclassDlg(*this, 0xFFFF);

  SetCaption(Title);
  TWindow::SetupWindow();
}

//
// Conditionally shuts down the dialog box
//
// If this is a modal dialog calls CanClose() and, if CanClose() returns true,
// transfers its data and shuts down, passing retValue (default IDCANCEL)
//
// Calls TWindow::CloseWindow(retValue) if this is a modeless dialog
//
void
TDialog::CloseWindow(int retValue)
{
  if (IsModal) {
    if (CanClose()) {
      TransferData(tdGetData);
      Destroy(retValue);
    }
  }
  else {
    TWindow::CloseWindow(retValue);
  }
}

//
// Destroys the Handle associated with the TDialog
//
void
TDialog::Destroy(int retValue)
{
  if (IsModal && GetHandle()) {
    ForEach(DoEnableAutoCreate);
    ::EndDialog(GetHandle(), retValue);
  }
  else {
    TWindow::Destroy(retValue);
  }
}

//
// Set Dialog's Title data member and Caption. This is non-virtual, but is
// always called with a TDialog or more derived pointer.
//
void
TDialog::SetCaption(const char far* title)
{
  if (HiUint16(uint32(title)) && LoUint16(uint32(title)) != 0xFFFF)
    TWindow::SetCaption(title);
}

//
// Responds to an incoming notification message from a button with
// an Id equal to IDOK
//
void
TDialog::CmOk()
{
  CloseWindow(IDOK);

  if (!IsModal  && !GetHandle() && IsFlagSet(wfDeleteOnClose))
    GetApplication()->Condemn(this);
}

//
// Responds to an incoming notification message from a button with
// an Id equal to IDCANCEL. Unconditionally destroy the window.
//
void
TDialog::CmCancel()
{
  EvClose();
}

//
// Message response function for WM_CLOSE by unconditionally closing
// the window.
//
void
TDialog::EvClose()
{
  Destroy(IDCANCEL);

  if (!IsModal && !GetHandle() && IsFlagSet(wfDeleteOnClose))
    GetApplication()->Condemn(this);
}


//
// Initialize the base class
//
TControlEnabler::TControlEnabler(uint id, HWND hWndReceiver)
:
  TCommandEnabler(id, hWndReceiver)
{
}

//
// Enable/Disable the control
//
void
TControlEnabler::Enable(bool enable)
{
  ::EnableWindow(GetReceiver(), enable);
  TCommandEnabler::Enable(enable);
}

//
// Set the text of the control
//
void
TControlEnabler::SetText(const char far* text)
{
  ::SetWindowText(GetReceiver(), text);
}

//
// Use with only buttons!
//
void
TControlEnabler::SetCheck(int check)
{
  ::SendMessage(GetReceiver(), BM_SETCHECK, check, 0);
}

//
// Iterate over each child control and routes the command enabler.
// Does not rely on an OWL interface object to work.
//
bool
TDialog::IdleAction(long idleCount)
{
  TWindow::IdleAction(idleCount);

  if (idleCount == 0) {
    HWND child = GetWindow(GW_CHILD);
    while (::IsWindow(child)) {
#if defined(BI_PLAT_WIN32)
      int id = ::GetWindowLong(child, GWL_ID);
#else
      int id = ::GetWindowWord(child, GWW_ID);
#endif
      TControlEnabler ce(id, child);
      RouteCommandEnable(*this, ce);
      child = ::GetWindow(child, GW_HWNDNEXT);
    }
  }
  return false;
}

//
// Set focus within a dialog to a specific control.
//
void
TDialog::SetControlFocus(HWND hwnd)
{
  CHECK(hwnd);
  SendMessage(WM_NEXTDLGCTL, TParam1(hwnd), 1);
}

//
// Set the focus to either the previous control with WS_TABSTOP or
// the next control with WS_TABSTOP.
//
void
TDialog::SetControlFocus(THow how)
{
  SendMessage(WM_NEXTDLGCTL, (how == Next) ? 1 : 0, 0);
}


#endif
#if !defined(SECTION) || SECTION == 2

IMPLEMENT_STREAMABLE1(TDialog, TWindow);

#if !defined(BI_NO_OBJ_STREAMING)

//
// Reads an instance of TDialog from the passed ipstream
//
void*
TDialog::Streamer::Read(ipstream& is, uint32 /*version*/) const
{
  ReadBaseObject((TWindow*)GetObject(), is);

  is >> (TResId&)GetObject()->DialogAttr.Name;
  is >> GetObject()->IsModal;
  return GetObject();
}

#if !defined(BI_NO_OBJ_STREAMING)

//
// Writes the TDialog to the passed opstream
//
void
TDialog::Streamer::Write(opstream& os) const
{
  WriteBaseObject((TWindow*)GetObject(), os);

  os << TResId(GetObject()->DialogAttr.Name);
  os << GetObject()->IsModal;
}
#endif  // if !defined(BI_NO_OBJ_STREAMING)

#endif  // if !defined(BI_NO_OBJ_STREAMING)

#endif
