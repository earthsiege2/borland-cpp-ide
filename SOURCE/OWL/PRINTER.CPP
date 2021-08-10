//----------------------------------------------------------------------------
// ObjectWindows
// Copyright (c) 1992, 1996 by Borland International, All Rights Reserved
//
//$Revision:   10.12  $
//----------------------------------------------------------------------------
#pragma hdrignore SECTION
#include <owl/pch.h>
#if !defined(OWL_APPLICAT_H)
# include <owl/applicat.h>
#endif
#if !defined(OWL_APPDICT_H)
# include <owl/appdict.h>
#endif
#if !defined(OWL_WINDOW_H)
# include <owl/window.h>
#endif
#if !defined(OWL_FRAMEWIN_H)
# include <owl/framewin.h>
#endif
#if !defined(OWL_DC_H)
# include <owl/dc.h>
#endif
#if !defined(OWL_STATIC_H)
# include <owl/static.h>
#endif
#if !defined(OWL_PRINTER_H)
# include <owl/printer.h>
#endif
#include <stdio.h>

#if !defined(SECTION) || SECTION == 1

//
// Template used to set and clear a bunch of flags at once
//
template <class T1, class T2>
inline void SetClear(T1& var, T2 bitsOn, T2 bitsOff) {
  var &= ~bitsOff;
  var |=  bitsOn;
}

//#define MANUAL_ABORT_CALL   // define to manually call abort proc


//----------------------------------------------------------------------------

//
// class TFormattedStatic
// ~~~~~ ~~~~~~~~~~~~~~~~
// Static control that uses its resource title as a printf format string to
// format one or two text strings provided in the constructor
//
class TFormattedStatic: public TStatic {
  public:
    TFormattedStatic(TWindow* parent, int resId, const char far* text,
                     const char far* text2 = 0);
   ~TFormattedStatic();

  protected:
    void SetupWindow();

  private:
    char far* Text;    // Text to display
    char far* Text2;
};

//
// Construct the object.
// Copy the two strings passed.
// Second string is optional.
//
TFormattedStatic::TFormattedStatic(TWindow* parent, int resId,
                                   const char far* text, const char far* text2)
:
  TStatic(parent, resId, 0)
{
  Text = strnewdup(text);
  Text2 = text2 ? strnewdup(text2) : 0;
}

//
// Destructor.
// Delete any previously allocated memory.
//
TFormattedStatic::~TFormattedStatic()
{
  delete[] Text;
  delete[] Text2;
}

//
// Override SetupWindow to set the text for the static control.
//
void
TFormattedStatic::SetupWindow()
{
  TStatic::SetupWindow();

  // Use the Title retrieved from the resource as a printf template for
  // the one or two text strings, then set the text directly to the control to
  // preserve the Title
  //
  static char buff[256];
  sprintf(buff, Title, Text, Text2);
  SetText(buff);
}

//
// class TNumericStatic
// ~~~~~ ~~~~~~~~~~~~~~
// Static control that uses its resource title as a printf format string to
// format one or two text strings provided in the constructor
//
class TNumericStatic: public TStatic {
  public:
    TNumericStatic(TWindow* parent, int resId, int number);

  protected:
    TResult EvSetNumber(TParam1 param1, TParam2 param2);

  private:
    int Number;         // Number to display

  DECLARE_RESPONSE_TABLE(TNumericStatic);
};
#define WM_SETNUMBER    WM_USER+100

DEFINE_RESPONSE_TABLE1(TNumericStatic, TStatic)
  EV_MESSAGE(WM_SETNUMBER, EvSetNumber),
END_RESPONSE_TABLE;

//
// Construct the object and remember the number to display.
//
TNumericStatic::TNumericStatic(TWindow* parent, int resId, int number)
:
  TStatic(parent, resId, 0),
  Number(number)
{
}

//
// Handle our user defined message to set the number displayed in the %d part
// of the Title format string. If the number is <= 0, then hide this window
//
TResult
TNumericStatic::EvSetNumber(TParam1 param1, TParam2)
{
  Number = param1;
  if (Number > 0) {
    char buff[80];
    wsprintf(buff, Title, Number);  // Need wsprintf for char far*
    SetText(buff);
  }
  THandle hWndDefault = Parent->GetDlgItem(-1);
  if (Number > 0) {
    SetWindowPos(HWND_TOP, 0, 0, 0, 0,
                 SWP_NOACTIVATE|SWP_NOMOVE|SWP_NOSIZE|SWP_SHOWWINDOW);
    if (hWndDefault)
      ::ShowWindow(hWndDefault, SW_HIDE);
    UpdateWindow();
  }
  return 0;
}


//----------------------------------------------------------------------------

DEFINE_RESPONSE_TABLE1(TPrinterAbortDlg, TDialog)
  EV_COMMAND(IDCANCEL, CmCancel),
END_RESPONSE_TABLE;


//
// Construct the object.
// The information passed-in will be displayed in the abort dialog.
//
TPrinterAbortDlg::TPrinterAbortDlg(TWindow*        parent,
                                   TResId          resId,
                                   const char far* title,
                                   const char far* device,
                                   const char far* port,
                                   HDC             prnDC)
:
  TDialog(parent, resId),
  TWindow(parent, 0),
  PrnDC(prnDC)
{
  new TNumericStatic(this, ID_PAGE, 0);
  new TFormattedStatic(this, ID_TITLE, title);
  new TFormattedStatic(this, ID_DEVICE, device, port);
  new TNumericStatic(this, ID_TOPAGE, 0);
}

//
// Override SetupWindow.
// This function disables the Close system menu option.
//
void
TPrinterAbortDlg::SetupWindow()
{
  // Ignore missing controls, resource may be different
  //
  TRY {
    TDialog::SetupWindow();
  }
  CATCH( (...) {
  } )
  EnableMenuItem(GetSystemMenu(false), SC_CLOSE, MF_GRAYED);
}

//
// Handle the print-cancel button by setting the user print abort flag in the
// application.
//
void
TPrinterAbortDlg::CmCancel()
{
  TPrinter::SetUserAbort(PrnDC);
  THandle hBtn = GetDlgItem(IDCANCEL);
  if (hBtn)
    ::EnableWindow(hBtn, false);
}


//----------------------------------------------------------------------------
//
//  TPrinter is an encapsulation around the Windows printer device interface.
//
//  Examples:
//   Creating a default device printing object:
//
//     DefaultPrinter = new TPrinter();
//
//   Creating a device for a specific printer:
//
//     PostScriptPrinter = new TPrinter();
//     PostScriptPrinter->SetDevice("PostScript Printer", "PSCRIPT", "LPT2:");
//
//   Allowing the user to setup the printer:
//
//     DefaultPrinter->Setup(MyWindow);
//

// Set by printing dialog if user cancels
HDC TPrinter::UserAbortDC = 0;

//
// Initialize the TPrinter object assigned to the default printer
//
TPrinter::TPrinter(TApplication* app)
{
  Data = new TPrintDialog::TData;
  Error = 0;
  Application = app ? app : ::GetApplicationObject();
  CHECK(Application);

  // Initialize with user's default printer.
  // NOTE: GetDefaultPrinter is virtual. However, we're currently
  //       in the constructor. Hence, TPrinter's version will be called
  //       in this case even for derived classes which override that
  //       method
  //
  GetDefaultPrinter();
}

//
// Deallocate allocated resources
//
TPrinter::~TPrinter()
{
  delete Data;
}

//
// Clears the association of this printer object with the current device
//
void TPrinter::ClearDevice()
{
  Data->ClearDevMode();
  Data->ClearDevNames();
}

//
// Updata Data with info on the user's default printer.
//
void
TPrinter::GetDefaultPrinter()
{
  //
  // Have a printDialog go get the default printer information for us
  // into DevMode and DevNames. We never actually Execute() the dialog.
  //
  SetClear(Data->Flags, 0L, long(PD_RETURNDC));
  TPrintDialog printDialog(Application->GetMainWindow(), *Data);
  if (!printDialog.GetDefaultPrinter()) {
    Data->Error = PDERR_NODEFAULTPRN;
  }
}

//
// Associate this printer object with actual printer info: driver name, device
// name and output port name.
//
void
TPrinter::SetPrinter(const char* driver, const char* device, const char* output)
{
  Data->SetDevNames(driver, device, output);
}

//
// Abort procedure used during printing, called by windows. Returns true to
// continue the print job, false to cancel.
//
/*OWL_EXPORT*/ int CALLBACK
TPrinterAbortProc(HDC hDC, int code)
{
  GetApplicationObject()->PumpWaitingMessages();

  // UserAbortDC will have been set by the AbortDialog
  //
  if (TPrinter::GetUserAbort() == hDC || TPrinter::GetUserAbort() == HDC(-1)) {
    TPrinter::SetUserAbort(0);
    return false;
  }
  return code == 0 || code == SP_OUTOFDISK;
}

//
// Virtual called from within Print() to construct and execute a print dialog
// before actual printing occurs. Return true to continue printing, false to
// cancel
//
bool
TPrinter::ExecPrintDialog(TWindow* parent)
{
  return TPrintDialog(parent, *Data).Execute() == IDOK;
}

//
// Page setup dialog for Win95 support.
//
bool
TPrinter::ExecPageSetupDialog(TWindow* parent)
{
#if defined(BI_PLAT_WIN32)
  Data->DoPageSetup = true;
  bool ret = TPrintDialog(parent, *Data).Execute() == IDOK;
  Data->DoPageSetup = false;
  return ret;
#else
  return false;
#endif
}

//
// Virtual called from withing Print() just before the main printing loop to
// construct and create the printing status, or abort window. This window
// should use the control IDs specified in printer.rh
//
TWindow*
TPrinter::CreateAbortWindow(TWindow* parent, TPrintout& printout)
{
  TDC* dc = printout.GetPrintDC();
  TWindow* win = new TPrinterAbortDlg(parent, IDD_ABORTDIALOG,
                                      printout.GetTitle(),
                                      Data->GetDeviceName(),
                                      Data->GetOutputName(),
                                      dc ? HDC(*dc) : HDC(-1));
  win->Create();
  return win;
}

//
// Updates the PageSize variables by querying the device capabilities
// of the specified device context
//
void
TPrinter::SetPageSizes(const TPrintDC& prnDC)
{
  //    fallback on HORZRES and VERTRES
  PageSize.cx = prnDC.GetDeviceCaps(HORZRES);
  PageSize.cy = prnDC.GetDeviceCaps(VERTRES);
  PageSizeInch.cx = prnDC.GetDeviceCaps(LOGPIXELSX);
  PageSizeInch.cy = prnDC.GetDeviceCaps(LOGPIXELSY);
}

//
// Helper function for Print when it is banding used to calculate banding flags
// and rectangle.
//
void
TPrinter::CalcBandingFlags(TPrintDC& prnDC)
{
  //
  // Calculate text versus graphics banding
  //
  if (UseBandInfo) {
    TBandInfo bandInfo;
    unsigned  flags = 0;

    prnDC.BandInfo(bandInfo);
    if (bandInfo.HasGraphics)
      flags = pfGraphics;
    if (bandInfo.HasText)
      flags |= pfGraphics;
    Flags = (Flags & ~pfBoth) | flags;
  }
  else {
    //
    // If a driver does not support BANDINFO the Microsoft recommended way
    // of determining text only bands is if the first band is the full page,
    // all others are graphics only.  Otherwise it handles both.
    //
    if (FirstBand && !BandRect.left && !BandRect.top &&
        BandRect.right == PageSize.cx && BandRect.bottom == PageSize.cy)
      Flags = pfText;
    else
      if ((Flags & pfBoth) == pfGraphics)
        // All other bands are graphics only
        Flags = (Flags & ~pfBoth) | pfGraphics;
      else
        Flags = Flags | pfBoth;
  }
  FirstBand = false;
}

//
// Print the given printout to the printer, prompting the user with a
// commdlg print dialog if indicated.
//
bool
TPrinter::Print(TWindow* parent, TPrintout& printout, bool prompt)
{
  PRECONDITION(parent);

  // Start from scratch
  //
  Error = 1;            // Positive 'Error' means print job is OK
  TPrintDC* prnDC = 0;  // Pointer to printer DC created by Printer Object
  HCURSOR hOrigCursor = ::SetCursor(::LoadCursor(0, IDC_WAIT));

  //

  //
  // Get page range & selection range (if any) from document
  //
  int selFromPage = 0;
  int selToPage = 0;
  printout.GetDialogInfo(Data->MinPage, Data->MaxPage, selFromPage, selToPage);

  if (selFromPage) {
    Data->Flags &= ~PD_NOSELECTION;
    Data->FromPage = selFromPage;
    Data->ToPage   = selToPage;
  }
  else {
    Data->Flags |= PD_NOSELECTION;
    Data->FromPage = 0;
    Data->ToPage = 999;
  }

  if (Data->MinPage) {
    Data->Flags &= ~PD_NOPAGENUMS;
    if (Data->FromPage < Data->MinPage)
      Data->FromPage = Data->MinPage;
    else if (Data->FromPage > Data->MaxPage)
      Data->FromPage = Data->MaxPage;
    if (Data->ToPage < Data->MinPage)
      Data->ToPage = Data->MinPage;
    else if (Data->ToPage > Data->MaxPage)
      Data->ToPage = Data->MaxPage;
  }
  else
    Data->Flags |= PD_NOPAGENUMS;

  //
  // Create & execute a TPrintDialog (or derived) and have it return a usable
  // DC if prompt is enabled. If the dialog fails because the default printer
  // changed, clear our device information & try again.
  //
  if (prompt) {
    SetClear(Data->Flags, PD_RETURNDC, PD_RETURNDEFAULT|PD_PRINTSETUP);
    bool ok = ExecPrintDialog(parent);
    if (!ok && Data->Error == PDERR_DEFAULTDIFFERENT) {
      ClearDevice();
      ok = ExecPrintDialog(parent);
    }
    if (!ok)
      return false;

    prnDC = Data->TransferDC();   // We now own the DC, let prnDC manage it
  }
  // Construct the DC directly if prompting was not enabled.
  //
  else {
    prnDC = new TPrintDC(Data->GetDriverName(), Data->GetDeviceName(),
                         Data->GetOutputName(), Data->GetDevMode());
  }
  if (!prnDC)
    TXPrinter::Raise();

  // Update the printer's page and forward DC and pageSize to printout
  //
  SetPageSizes(*prnDC);
  printout.SetPrintParams(prnDC, GetPageSize());

  // Create modeless abort dialog using strings
  //
  TWindow* abortWin;
  TRY {
    abortWin = CreateAbortWindow(parent, printout);
  }
  CATCH( (...) {
    delete prnDC;
    RETHROW;
  })

  ::SetCursor(hOrigCursor);
  parent->EnableWindow(false);

  prnDC->SetAbortProc(TPrinterAbortProc);

  // Only band if the user requests banding and the printer
  // supports banding
  //
  bool banding = printout.WantBanding() &&
                (prnDC->GetDeviceCaps(RASTERCAPS) & RC_BANDING);
  if (banding)

    // Only use BANDINFO if supported.
    //
    UseBandInfo = ToBool(prnDC->QueryEscSupport(BANDINFO));

  else
    //
    // Set the banding rectangle to full page
    //
    BandRect.Set(0, 0, PageSize.cx, PageSize.cy);

  // If more than one (uncollated) copy was requested, see if printer can
  // handle it for performance and user convenience.
  //
  int copiesPerPass = 1;
  int tempCopiesPerPass = copiesPerPass;
  if (!(Data->Flags & PD_COLLATE))
    prnDC->SetCopyCount(Data->Copies, copiesPerPass);

  // Figure out which page range to use: Selection, Dialog's from/to,
  // whole doc range or all possible pages.
  //
  int fromPage;
  int toPage;
  if (prompt && (Data->Flags & PD_SELECTION) || selFromPage) {
    fromPage = selFromPage;
    toPage = selToPage;
  }
  else if (prompt && (Data->Flags & PD_PAGENUMS)) {
    fromPage = Data->FromPage;
    toPage = Data->ToPage;
  }
  else if (Data->MinPage) {
    fromPage = Data->MinPage;
    toPage = Data->MaxPage;
  }
  else {
    fromPage = 1;
    toPage = INT_MAX;
  }

  // Copies loop, one pass per block of document copies.
  //
  printout.BeginPrinting();
  for (int copies = Data->Copies;
       copies > 0 && Error > 0;
       copies -= tempCopiesPerPass) {

    // On last multi-copy pass, may need to adjust copy count
    //
    if (copiesPerPass > 1 && copies < copiesPerPass)
      prnDC->SetCopyCount(copies, copiesPerPass);

    // Whole document loop, one pass per page
    //
    Flags = pfBoth;
    Error = prnDC->StartDoc(printout.GetTitle(), 0);  // get PD_PRINTTOFILE ?
    printout.BeginDocument(fromPage, toPage, Flags);

    abortWin->SendDlgItemMessage(ID_TOPAGE, WM_SETNUMBER, toPage);
    for (int pageNum = fromPage;
         Error > 0 && pageNum <= toPage && printout.HasPage(pageNum);
         pageNum++) {

      abortWin->SendDlgItemMessage(ID_PAGE, WM_SETNUMBER, pageNum);

      // Begin the page by getting the first band or calling StartPage()
      //
      if (banding) {
        FirstBand = true;
        Error = prnDC->NextBand(BandRect);
      }
      else
        Error = prnDC->StartPage();

      // Whole page loop, one pass per band (once when not banding)
      //
      while (Error > 0 && !BandRect.IsEmpty()) {
        //
        // [Manually call the abort proc between bands or pages]
        //
#if defined(MANUAL_ABORT_CALL)
        prnDC->QueryAbort();
#endif

        if (banding) {
          CalcBandingFlags(*prnDC);
          if (printout.WantForceAllBands() && (Flags & pfBoth) == pfGraphics)
            prnDC->SetPixel(TPoint(0, 0), 0);  // Some old drivers need this
          prnDC->DPtoLP(BandRect, 2);
        }

        printout.PrintPage(pageNum, BandRect, Flags);
        if (banding)
          Error = prnDC->NextBand(BandRect);
        else
          break;
      }

      // EndPage (NEWFRAME) need only called if not banding
      //
      if (Error > 0 && !banding) {
        Error = prnDC->EndPage();
        if (Error == 0)    // a zero return here is OK for this call
          Error = 1;
      }

    }  // End of Whole Document-loop

    // Tell GDI the document is finished
    //
    if (Error > 0)
#if defined(MANUAL_ABORT_CALL)
      if (banding && (UserAbortDC == *prnDC || UserAbortDC == HDC(-1))
        prnDC->AbortDoc();
      else
        prnDC->EndDoc();
#else
      prnDC->EndDoc();
#endif

    printout.EndDocument();

  } // End of Copy-loop
  printout.EndPrinting();

  // Set the printer back to 1 copy
  //
  if (copiesPerPass > 1)
    prnDC->SetCopyCount(1, copiesPerPass);

  // Re-enable parent and free allocated resources
  //
  parent->EnableWindow(true);
  abortWin->Destroy();
  delete abortWin;
  if (UserAbortDC == *prnDC)  // User tried to abort, but it was too late
    UserAbortDC = 0;
  delete prnDC;

  // Report error if not already done so by printmgr
  //
  if (Error & SP_NOTREPORTED)
    ReportError(parent, printout);

  return Error > 0;
}

//
// Setup opens a dialog as a child of the given window to setup the
// printer using the commdlg printer setup. The options button
// allows the user acces to the specific driver's options.
//
void TPrinter::Setup(TWindow* parent)
{
#if defined(BI_PLAT_WIN32)  
  ExecPageSetupDialog(parent);
#else
  SetClear(Data->Flags, PD_PRINTSETUP, PD_RETURNDEFAULT|PD_RETURNDC);
  ExecPrintDialog(parent);
#endif
}

//
// Report the printer error in a message box. First translate the SP_ codes
// into ObjectWindows string resource IDs, and then load the strings. Don't
// display anything if the string is not found, or the code is unknown.
//
void
TPrinter::ReportError(TWindow* parent, TPrintout& printout)
{
  uint16  errorId;

  switch (Error) {
    case SP_ERROR:
      errorId = IDS_PRNGENERROR;
      break;
    case SP_APPABORT:
      errorId = IDS_PRNCANCEL;
      break;
    case SP_USERABORT:
      errorId = IDS_PRNMGRABORT;
      break;
    case SP_OUTOFDISK:
      errorId = IDS_PRNOUTOFDISK;
      break;
    case SP_OUTOFMEMORY:
      errorId = IDS_PRNOUTOFMEMORY;
      break;
    default:
      return;
  }

  TModule& module = *parent->GetModule();

  char  errorCaption[80];
  if (!module.LoadString(IDS_PRNERRORCAPTION, errorCaption, sizeof(errorCaption)))
    return;

  char  errorTemplate[40];
  char  errorStr[40];
  if (!module.LoadString(IDS_PRNERRORTEMPLATE, errorTemplate, sizeof(errorTemplate)))
    return;
  if (!module.LoadString(errorId, errorStr, sizeof(errorStr)))
    return;

  char  errorMsg[80];
  sprintf(errorMsg, errorTemplate, printout.GetTitle(), (char far*)errorStr);

  parent->MessageBox(errorMsg, errorCaption, MB_OK | MB_ICONSTOP);
}

//----------------------------------------------------------------------------

//
// Construct the exception object with the string resource.
//
TXPrinter::TXPrinter(uint resId)
:
  TXOwl(resId)
{
}

//
// Clone the exception object for safe throwing across Win16 stack frames.
//
#if defined(BI_NO_COVAR_RET)
TXBase*
#else
TXPrinter*
#endif
TXPrinter::Clone()
{
  return new TXPrinter(*this);
}

//
// Throws the exception.
//
void
TXPrinter::Throw()
{
  THROW( *this );
}

//
// Create the exception object and throws it.
//
void
TXPrinter::Raise(uint resId)
{
  TXPrinter(resId).Throw();
}

#endif
#if !defined(SECTION) || SECTION == 2

IMPLEMENT_STREAMABLE(TPrinter);

#if !defined(BI_NO_OBJ_STREAMING)

//
// Restore the printer object from the persistent stream.
//
void*
TPrinter::Streamer::Read(ipstream& is, uint32 version) const
{
  GetObject()->Data->Read(is, version);
  return GetObject();
}

//
// Save the object into the persistent stream.
//
void
TPrinter::Streamer::Write(opstream& os) const
{
  GetObject()->Data->Write(os);
}

#endif  // if !defined(BI_NO_OBJ_STREAMING)

#endif

