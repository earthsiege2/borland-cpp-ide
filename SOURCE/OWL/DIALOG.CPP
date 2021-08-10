//----------------------------------------------------------------------------
// ObjectWindows - (C) Copyright 1991, 1993 by Borland International
//   source\owl\dialog.cpp
//   Defines type TDialog.  This defines the basic behavior of all dialogs.
//----------------------------------------------------------------------------
#pragma hdrignore SECTION
#include <owl\owlpch.h>
#include <owl\dialog.h>
#include <owl\applicat.h>
#include <string.h>
#include <bwcc.h>

DIAG_DECLARE_GROUP(OwlMsg);  // diagnostic group for message tracing
DIAG_DECLARE_GROUP(OwlWin);  // diagnostic group for windows

#if !defined(SECTION) || SECTION == 1

#if !defined(RT_DLGINIT)
  #define RT_DLGINIT       MAKEINTRESOURCE(240)
#endif

extern UINT _OWLDATA GetWindowPtrMsgId; // in owl.cpp

//
// Our exported dialog proc & its proc instance
//
BOOL FAR PASCAL _export StdDlgProc(HWND, UINT, WPARAM, LPARAM);
TProcInstance StdDlgProcInstance((FARPROC)StdDlgProc);

TDialog* _OWLDATA DlgCreationWindow = 0;  // public so derived classes can create

DEFINE_RESPONSE_TABLE1(TDialog, TWindow)
  EV_WM_CLOSE,
  EV_WM_PAINT,
  EV_WM_CTLCOLOR,
  EV_COMMAND(IDOK, CmOk),
  EV_COMMAND(IDCANCEL, CmCancel),
END_RESPONSE_TABLE;

//
// constructor for a TDialog object
//
// takes an TResId for its template name or numeric Id
//
TDialog::TDialog(TWindow* parent, TResId resId, TModule* module)
{
  //
  // Initialize virtual base, in case the derived-most used default ctor
  //
  TWindow::Init(parent, 0, module);

  DisableAutoCreate();
  if (HIWORD(Title))
    delete Title;
  Title = (LPSTR)MAKEINTRESOURCE(0xFFFF); // Title setting--"don't-change"

  SetFlag(wfFromResource);
  Attr.Param = 0;
  IsModal = FALSE;
  Attr.Name = resId.IsString() ? strnewdup(resId) : (char far*)resId;
}

//
// destructor for a TDialog
//
// ~TWindow frees the instance thunk
//
TDialog::~TDialog()
{
  if (HIWORD(Attr.Name))
    delete Attr.Name;
}

BOOL
TDialog::PreProcessMsg(MSG& msg)
{
  if (TWindow::PreProcessMsg(msg))
    return TRUE;  // process accelerators

  else
    return ::IsDialogMessage(HWindow, &msg);
}

char far*
TDialog::GetClassName()
{
  if (GetApplication()->BWCCEnabled())
    return BORDLGCLASS;
  else
    return (char far*)WC_DIALOG;
}

void
TDialog::GetWindowClass(WNDCLASS& wndClass)
{
  TResId dlgClass;

  if (GetApplication()->BWCCEnabled()) {
    BOOL FAR PASCAL(*bwccRegister)(HINSTANCE);
    (FARPROC)bwccRegister = GetApplication()->GetBWCCModule()->GetProcAddress("BWCCRegister");
    if (bwccRegister)
      (*bwccRegister)(*GetModule());

    dlgClass = BORDLGCLASS;

  } else
    dlgClass = WC_DIALOG;

  if (!::GetClassInfo(0, dlgClass, &wndClass))
    GetModule()->GetClassInfo(dlgClass, &wndClass);

  wndClass.lpszClassName = GetClassName();
}

void
TDialog::EvSetFont(HFONT)
{
}

void
TDialog::EvPaint()
{
  DefaultProcessing();  // don't call TWindow::EvPaint()
}

//
// If this app is using Ctl3d, forward the WM_CTLCOLOR message to the
// ctl3d.dll since it needs to handle that & we don't let it autosubclass
//
HBRUSH
TDialog::EvCtlColor(HDC hDC, HWND hWndChild, UINT ctlType)
{
  if (GetApplication()->Ctl3dEnabled()) {
    static HBRUSH FAR PASCAL(*ctl3dCtlColorEx)(UINT, WPARAM, LPARAM) = 0;
    if (!ctl3dCtlColorEx)
      (FARPROC)ctl3dCtlColorEx = GetApplication()->GetCtl3dModule()->
                                   GetProcAddress("Ctl3dCtlColorEx");

    HBRUSH hBr = 0;
    if (ctl3dCtlColorEx)
      #if defined(__WIN32__)
        hBr = ctl3dCtlColorEx(WM_CTLCOLORMSGBOX+ctlType, WPARAM(hDC), LPARAM(hWndChild));
      #else
        hBr = ctl3dCtlColorEx(WM_CTLCOLOR, WPARAM(hDC), MAKELPARAM(hWndChild, ctlType));
      #endif

    if (hBr)
      return hBr;
  }
  return TWindow::EvCtlColor(hDC, hWndChild, ctlType);
}

//
// The default dialog function. Handles the two mesages, WM_INITDIALOG and
// WM_SETFONT that may be sent before we get a chance to thunk
// DIALOG's window proc.
//
BOOL
TDialog::DialogFunction(UINT msg, WPARAM wParam, LPARAM lParam)
{
  TRACEX(OwlMsg, 2, MsgName(msg) << "(DlgFcn)=> " << *this);

  switch (msg) {
    case WM_INITDIALOG:
      return EvInitDialog((HWND)wParam);

    case WM_SETFONT:
      EvSetFont((HFONT)wParam);
      return TRUE;

    case WM_SETTEXT:
    case WM_NCPAINT:
    case WM_NCACTIVATE:
      if (GetApplication()->Ctl3dEnabled()) {
        static BOOL FAR PASCAL(*ctl3dDlgFramePaint)(HWND, UINT, WPARAM, LPARAM) = 0;
        if (!ctl3dDlgFramePaint)
          (FARPROC)ctl3dDlgFramePaint = GetApplication()->GetCtl3dModule()->
                                          GetProcAddress("Ctl3dDlgFramePaint");
        if (ctl3dDlgFramePaint) {
          SetWindowLong(DWL_MSGRESULT, (*ctl3dDlgFramePaint)(HWindow, msg, wParam, lParam));
          return TRUE;
        }
      }
      break;
  }
  return FALSE;  // not handled
}

//
// Handles messages that comes from WC_DIALOG's wndProc
// DlgCreationWindow is not 0, is destined for DlgCreationWindow.
// Setup DlgCreationWindow's HWindow, subclass the WC_DIALOG class's window
// function. Calls the virtual DialogFunction() to handle specific messages
//
BOOL FAR PASCAL _export
StdDlgProc(HWND hDlg, UINT msg, WPARAM wParam, LPARAM lParam)
{
  //
  // Thunk on first message to a non-thunked window & thats not one sent to
  // parent dialogs.
  //
  if (msg == GetWindowPtrMsgId) // if it gets here, we wont know how to get it
    return FALSE;

  TWindow*  w = GetWindowPtr(hDlg);
  TDialog*  dialog = TYPESAFE_DOWNCAST(w, TDialog);

  if (DlgCreationWindow && !dialog && msg != WM_CANCELMODE && msg != WM_ENABLE) {
    DlgCreationWindow->HWindow = hDlg;

    DlgCreationWindow->SubclassWindowFunction();
    dialog = DlgCreationWindow;
    DlgCreationWindow = 0;
  }
  if (!dialog)
    return FALSE;

  //
  // Handle all messages once thunked.
  // Call the virtual DialogFunction() to handle specific messages
  //
#if defined(__WIN32__)
  static DWORD version = ::GetVersion();
  if (!(version & 0x80000000))
    return dialog->DialogFunction(msg, wParam, lParam);
#endif
  TRY {
    return dialog->DialogFunction(msg, wParam, lParam);
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
  CATCH( (Bad_cast) {
    w->GetApplication()->SuspendThrow(TApplication::xsBadCast);
  })
  CATCH( (Bad_typeid) {
    w->GetApplication()->SuspendThrow(TApplication::xsBadTypeid);
  })
  CATCH( (...) {
    w->GetApplication()->SuspendThrow(TApplication::xsUnknown);
  })

  // When we're building small model, exceptions are disabled
  // CATCH is defined as empty, so the only code is the TRY block,
  // making this return unreachable
  #pragma warn -rch
  return TRUE;  // default value returned when exception caught
  #pragma warn .rch
}

static BOOL
RegisterFails(TWindow* win, void*)
{
  return !win->Register();
}

//
// creates an MS-Windows modeless dialog and associates the modeless
// dialog interface element with the TDialog
//
BOOL
TDialog::Create()
{
  PRECONDITION(HWindow == 0);

  IsModal = FALSE;

  if (!Register())
    THROW( TXWindow(this, IDS_CLASSREGISTERFAIL) );

  DlgCreationWindow = this;

  LoadAcceleratorTable();

  //
  // register all the dialog's child objects (for custom control support)
  //
  if (FirstThat(RegisterFails))
    THROW( TWindow::TXWindow(this, IDS_CHILDREGISTERFAIL) );

  HWindow = DoCreate();
  GetApplication()->ResumeThrow();
  if (!HWindow)
    THROW( TWindow::TXWindow(this, IDS_WINDOWCREATEFAIL) );

  GetHWndState();
  return TRUE;
}

HWND
TDialog::DoCreate()
{
  return CreateDialogParam(*GetModule(), Attr.Name, Parent? Parent->HWindow : 0,
                           (DLGPROC)(FARPROC)StdDlgProcInstance, Attr.Param);
}

//
// creates an modal dialog and associates the modal dialog interface
// element with the TDialog.  Registers all the dialog's child objects
// (for custom control support).  If this registering fails, throws TXWindow
// exception.  If the dialog fails to execute, throw a TXWindow exception.
// Returns the return value from the dialog manager.
//
int
TDialog::Execute()
{
  PRECONDITION(HWindow == 0);

  IsModal = TRUE;

  if (!Register())
    THROW( TXWindow(this, IDS_CLASSREGISTERFAIL) );

  DlgCreationWindow = this;

  //
  // register all the dialog's child objects (for custom control support)
  //
  if (FirstThat(RegisterFails))
    THROW( TXWindow(0, IDS_CHILDREGISTERFAIL) );   // unspecified child window

  int retValue = DoExecute();
  GetApplication()->ResumeThrow();

  //
  // -1 if the function cannot create the dialog box
  //
  if (retValue == -1)
    THROW( TXWindow(this, IDS_WINDOWEXECUTEFAIL) );

  return retValue;
}

int
TDialog::DoExecute()
{
  return DialogBoxParam(*GetModule(), Attr.Name, Parent ? Parent->HWindow : 0,
                        (DLGPROC)(FARPROC)StdDlgProcInstance, Attr.Param);
}

BOOL
TDialog::PerformDlgInit()
{
  BOOL ok = TRUE;
  if (Attr.Name) {
    HRSRC hRes = GetModule()->FindResource(Attr.Name, RT_DLGINIT);
    if (hRes) {
      HGLOBAL hDat = GetModule()->LoadResource(hRes);
      if (hDat) {
        BYTE HUGE* hpRes = (BYTE HUGE*)::LockResource(hDat);
        if (hpRes) {
          while (ok && *hpRes) {
            BYTE buff[4];

            buff[0] = *hpRes++;
            buff[1] = *hpRes++;
            UINT  nIDC = *((UINT FAR*)buff);

            buff[0] = *hpRes++;
            buff[1] = *hpRes++;
            UINT  nMsg = *((UINT FAR*)buff);

            buff[0] = *hpRes++;
            buff[1] = *hpRes++;
            buff[2] = *hpRes++;
            buff[3] = *hpRes++;
            DWORD dwLen = *((DWORD FAR*)buff);

            if (SendDlgItemMessage(nIDC, nMsg, 0, LPARAM(hpRes)) == -1)
              ok = FALSE;
            hpRes += dwLen;
          }
          #if !defined(__WIN32__)
            ::UnlockResource(hDat);
          #endif
        }
        #if !defined(__WIN32__)
          ::FreeResource(hDat);
        #endif
        GetApplication()->ResumeThrow();
      }
    }
  }
  return ok;
}

//
// responds to an incoming WM_INITDIALOG message
//
// this message is sent after an MS-Windows dialog is created and before
// the dialog is displayed
//
// calls SetupWindow() to perform setup for the dialog
//
BOOL
TDialog::EvInitDialog(HWND /*hWndFocus*/)
{
  GetHWndState();
  PerformDlgInit();
  SetupWindow();
  return TRUE;  // have Windows set focus to "hWndFocus"
}

//
// sets up the dialog box by calling setting up ctl3d if enabled, then
// calling SetCaption() and then TWindow::SetupWindow()
//
// calling SetCaption() here allows us to override the dialog caption
// (specified in the dialog resource) by setting Title prior to this point
//
void
TDialog::SetupWindow()
{
  //
  // If this app is using Ctl3d, tell it to explicitly subclass this dialog's
  // controls (CTL3D_ALL). Its better to do this here than enable
  // autosubclassing since that requires a CBT hook set all the time which
  // slows the app considerably.
  //
  if (GetApplication()->Ctl3dEnabled()) {
    static BOOL FAR PASCAL(*ctl3dSubclassDlg)(HWND, WORD) = 0;
    if (!ctl3dSubclassDlg)
     (FARPROC)ctl3dSubclassDlg = GetApplication()->GetCtl3dModule()->
                                   GetProcAddress("Ctl3dSubclassDlg");
    if (ctl3dSubclassDlg)
      ctl3dSubclassDlg(*this, 0xFFFF);
  }

  SetCaption(Title);
  TWindow::SetupWindow();
}

//
// conditionally shuts down the dialog box
//
// if this is a modal dialog calls CanClose() and, if CanClose() returns TRUE,
// transfers its data and shuts down, passing retValue (default IDCANCEL)
//
// calls TWindow::CloseWindow(retValue) if this is a modeless dialog
//
void
TDialog::CloseWindow(int retValue)
{
  if (IsModal) {
    if (CanClose()) {
      TransferData(tdGetData);
      Destroy(retValue);
    }

  } else {
    TWindow::CloseWindow(retValue);
  }
}

//
// destroys the MS-Windows dialog associated with the TDialog
//
void
TDialog::Destroy(int retValue)
{
  if (IsModal && HWindow) {
    ForEach(DoEnableAutoCreate);
    ::EndDialog(HWindow, retValue);

  } else {
    TWindow::Destroy(retValue);
  }
}

//
// set Dialog's Title data member and Caption. This is non-virtual, but is
// always called with a TDialog or more specific pointer.
//
void
TDialog::SetCaption(const char far* title)
{
  if (HIWORD(title) && LOWORD(title) != 0xFFFF)
    TWindow::SetCaption(title);
}

//
// responds to an incoming notification message from a button with
// an Id equal to IDOK
//
void
TDialog::CmOk()
{
  CloseWindow(IDOK);
}

//
// responds to an incoming notification message from a button with
// an Id equal to IDCANCEL. Unconditionally destroy the window.
//
void
TDialog::CmCancel()
{
  Destroy(IDCANCEL);
}

//
// message response function for WM_CLOSE. Behave the same as a cancel
//
void
TDialog::EvClose()
{
  CmCancel();
}

#endif
#if !defined(SECTION) || SECTION == 2

IMPLEMENT_STREAMABLE1(TDialog, TWindow);

//
// reads an instance of TDialog from the passed ipstream
//
void*
TDialog::Streamer::Read(ipstream& is, uint32 /*version*/) const
{
  ReadBaseObject((TWindow*)GetObject(), is);

  is >> (TResId&)GetObject()->Attr.Name;
  is >> GetObject()->IsModal;
  return GetObject();
}

//
// writes the TDialog to the passed opstream
//
void
TDialog::Streamer::Write(opstream& os) const
{
  WriteBaseObject((TWindow*)GetObject(), os);

  os << TResId(GetObject()->Attr.Name);
  os << GetObject()->IsModal;
}
#endif
