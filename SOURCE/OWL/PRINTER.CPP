//----------------------------------------------------------------------------
// ObjectWindows - (C) Copyright 1992, 1993 by Borland International
//   source\owl\printer.cpp
//----------------------------------------------------------------------------
#pragma hdrignore SECTION
#include <owl\owlpch.h>
#include <owl\applicat.h>
#include <owl\window.h>
#include <owl\dc.h>
#include <owl\static.h>
#include <owl\printer.h>

#if !defined(SECTION) || SECTION == 1

//
// Macro used to set and clear a bunch of flags at once
//
#define SETCLEAR(flag, set, clear)((flag) = ((flag)&~(clear))|(set))

//#define MANUAL_ABORT_CALL   // define to manually call abort proc


//----------------------------------------------------------------------------

// TFormattedStatic - Static control that uses its resource title as a printf
// format string to format text provided in the constructor
//
class TFormattedStatic: public TStatic {
  public:
    TFormattedStatic(TWindow* parent, int resId, const char far* text);
   ~TFormattedStatic();
  
  protected:
    void SetupWindow();

  private:
    char far*  Text;
};

TFormattedStatic::TFormattedStatic(TWindow* parent, int resId, const char far* text)
  : TStatic(parent, resId, 0)
{
  Text = strnewdup(text);
}

TFormattedStatic::~TFormattedStatic()
{
  delete Text;
}

void
TFormattedStatic::SetupWindow()
{
  TStatic::SetupWindow();

  char format[80];
  GetText(format, sizeof(format) - 1);

  char buff[80];
  wsprintf(buff, format, Text);
  SetText(buff);
}

//----------------------------------------------------------------------------

TPrinterAbortDlg::TPrinterAbortDlg(TWindow* parent, TResId resId,
  const char far* title, const char far* device, const char far* port)
  : TDialog(parent, resId),
    TWindow(parent, 0)
{
  new TFormattedStatic(this, ID_TITLE, title);
  new TFormattedStatic(this, ID_DEVICE, device);
  new TFormattedStatic(this, ID_PORT, port);
}

void
TPrinterAbortDlg::SetupWindow()
{
  TDialog::SetupWindow();
  EnableMenuItem(GetSystemMenu(FALSE), SC_CLOSE, MF_GRAYED);
}

LRESULT
TPrinterAbortDlg::EvCommand(UINT id, HWND hWndCtl, UINT notifyCode)
{
  TPrinter::SetUserAbort();
  return TDialog::EvCommand(id, hWndCtl, notifyCode);
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

BOOL TPrinter::UserAbort;    // Set by printing dialog if user cancels

//
// Initialize the TPrinter object assigned to the default printer
//
TPrinter::TPrinter()
{
  Data = new TPrintDialog::TData;
  memset(Data, 0, sizeof(TPrintDialog::TData));
  Data->Flags = PD_ALLPAGES | PD_COLLATE;
  Data->FromPage = Data->ToPage = -1;

  Error = 0;
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
  SETCLEAR(Data->Flags, 0, PD_RETURNDC);
  TPrintDialog printDialog(0, *Data);
  printDialog.GetDefaultPrinter();
}

void
TPrinter::SetPrinter(const char* driver, const char* device, const char* output)
{
  Data->SetDevNames(driver, device, output);
}

//
// Abort procedure used during printing
//
BOOL FAR PASCAL _export
TPrinterAbortProc(HDC, short)
{
  TApplication* app = GetApplicationObject();
  app->PumpWaitingMessages();
  return !TPrinter::GetUserAbort(); // UserAbort will have been set in the AbortDialog
}

BOOL
TPrinter::ExecPrintDialog(TWindow* parent)
{
  return TPrintDialog(parent, *Data).Execute() == IDOK;
}

TWindow*
TPrinter::CreateAbortWindow(TWindow* parent, TPrintout& printout)
{
  TWindow* win = new TPrinterAbortDlg(parent, IDD_ABORTDIALOG,
                                      printout.GetTitle(),
                                      Data->GetDeviceName(),
                                      Data->GetOutputName());
  win->Create();
  return win;
}

//
// Helper function for Print when it is banding to calculate banding flags
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

  } else {
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
  FirstBand = FALSE;
}

//
// Print the given printout to the printer, prompting the user with a
// commdlg print dialog if indicated.
//
BOOL
TPrinter::Print(TWindow* parent, TPrintout& printout, BOOL prompt)
{
  PRECONDITION(parent);

  // Start from scratch
  //
  Error = 0;
  UserAbort = FALSE;
  TPrintDC*   prnDC;
  HCURSOR hOrigCursor = ::SetCursor(::LoadCursor(0, IDC_WAIT));

  //
  // Get page range & selection range (if any) from document
  //
  int selFromPage;
  int selToPage;
  printout.GetDialogInfo(Data->MinPage, Data->MaxPage, selFromPage, selToPage);
  if (selFromPage)
    Data->Flags &= ~PD_NOSELECTION;
  else
    Data->Flags |= PD_NOSELECTION;
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
  } else
    Data->Flags |= PD_NOPAGENUMS;

  //
  // Create & execute a TPrintDialog (or derived) and have it return a usable
  // DC if prompt is enabled. If the dialog fails because the default printer
  // changed, clear our device information & try again.
  //
  if (prompt) {
    SETCLEAR(Data->Flags, PD_RETURNDC, PD_RETURNDEFAULT|PD_PRINTSETUP);
    BOOL ok = ExecPrintDialog(parent);
    if (!ok && Data->Error == PDERR_DEFAULTDIFFERENT) {
      ClearDevice();
      ok = ExecPrintDialog(parent);
    }
    if (!ok)
      return FALSE;

    prnDC = Data->TransferDC();   // We now own the DC, let prnDC manage it

  // Construct the DC directly if prompting was not enabled.
  //
  } else {
    prnDC = new TPrintDC(Data->GetDriverName(), Data->GetDeviceName(),
                         Data->GetOutputName(), Data->GetDevMode());
  }
  if (!prnDC)
    THROW( TXPrinter() );

  //
  // Get the page size
  //
  PageSize.cx = prnDC->GetDeviceCaps(HORZRES);
  PageSize.cy = prnDC->GetDeviceCaps(VERTRES);
  printout.SetPrintParams(prnDC, PageSize);

  //
  // Create modeless abort dialog using strings & unlock the devname struct
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
  parent->EnableWindow(FALSE);

  #if defined (__DLL__)
    // We don't need to make a proc instance for DLLs
    ABORTPROC abortProcInst = (ABORTPROC)TPrinterAbortProc;
  #else
    ABORTPROC abortProcInst = (ABORTPROC)MakeProcInstance((FARPROC)TPrinterAbortProc, *parent->GetModule());
  #endif
  prnDC->SetAbortProc(abortProcInst);

  //
  // Only band if the user requests banding and the printer
  // supports banding
  //
  BOOL banding = printout.WantBanding() &&
                (prnDC->GetDeviceCaps(RASTERCAPS) & RC_BANDING);
  if (banding)
    //
    // Only use BANDINFO if supported.
    //
    UseBandInfo = prnDC->QueryEscSupport(BANDINFO);

  else
    //
    // Set the banding rectangle to full page
    //
    BandRect.Set(0, 0, PageSize.cx, PageSize.cy);

  //
  // If more than one(uncollated) copy was requested, see if printer can
  // handle it for performance and user convenience.
  //
  int copiesPerPass = 1;
  if (!(Data->Flags & PD_COLLATE))
    prnDC->SetCopyCount(Data->Copies, copiesPerPass);

  //
  // Figure out which page range to use: Selection, Dialog's from/to,
  // whole doc range or all possible pages.
  //
  int fromPage;
  int toPage;
  if (prompt && (Data->Flags & PD_SELECTION) || selFromPage) {
    fromPage = selFromPage;
    toPage = selToPage;
  } else if (prompt && (Data->Flags & PD_PAGENUMS)) {
    fromPage = Data->FromPage;
    toPage = Data->ToPage;
  } else if (Data->MinPage) {
    fromPage = Data->MinPage;
    toPage = Data->MaxPage;
  } else {
    fromPage = 1;
    toPage = INT_MAX;
  }

  //
  // Copies loop, one pass per block of document copies.
  //
  printout.BeginPrinting();
  for (int copies = Data->Copies; copies > 0; copies -= copiesPerPass) {

    //
    // On last multi-copy pass, may need to adjust copy count
    //
    if (copiesPerPass > 1 && copies < copiesPerPass)
      prnDC->SetCopyCount(copies, copiesPerPass);

    //
    // Whole document loop, one pass per page
    //
    Flags = pfBoth;
    Error = prnDC->StartDoc(printout.GetTitle(), 0);  // get PD_PRINTTOFILE ?
    printout.BeginDocument(fromPage, toPage, Flags);

    for (int pageNum = fromPage;
         Error > 0 && pageNum <= toPage && printout.HasPage(pageNum);
         pageNum++) {

      //
      // Begin the page by getting the first band or calling StartPage()
      //
      if (banding) {
        FirstBand = TRUE;
        Error = prnDC->NextBand(BandRect);
      } else
        Error = prnDC->StartPage();

      //
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

      //
      // EndPage (NEWFRAME) need only called if not banding
      //
      if (Error > 0 && !banding)
        Error = prnDC->EndPage();

    }  // Whole Document-loop

    // Tell GDI the document is finished
    if (Error > 0)
      #if defined(MANUAL_ABORT_CALL)
        if (banding && UserAbort)
          prnDC->AbortDoc();
        else
      #endif
        prnDC->EndDoc();

    printout.EndDocument();

  } // Copy-loop
  printout.EndPrinting();

  if (copiesPerPass > 1)
    prnDC->SetCopyCount(1, copiesPerPass);

  //
  // Re-enable parent and free allocated resources
  //
  # if !defined (__DLL__)
    FreeProcInstance((FARPROC)abortProcInst);
  #endif

  parent->EnableWindow(TRUE);
  abortWin->Destroy();
  delete abortWin;
  delete prnDC;

  //
  // Report error if not already done so by printmgr
  //
  if (Error & SP_NOTREPORTED)
    ReportError(parent, printout);

  return Error > 0 && !UserAbort;
}

//
// Setup opens a dialog as a child of the given window to setup the
// printer using the commdlg printer setup. The options button
// allows the user acces to the specific driver's options.
//
void TPrinter::Setup(TWindow* parent)
{
  SETCLEAR(Data->Flags, PD_PRINTSETUP, PD_RETURNDEFAULT|PD_RETURNDC);
  ExecPrintDialog(parent);
}

void
TPrinter::ReportError(TWindow* parent, TPrintout& printout)
{
  WORD  errorId;

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
  char  errorTemplate[40];
  char  errorStr[40];
  module.LoadString(IDS_PRNERRORTEMPLATE, errorTemplate, sizeof(errorTemplate));
  module.LoadString(errorId, errorStr, sizeof(errorStr));

  char  errorMsg[80];
  wsprintf(errorMsg, errorTemplate, printout.GetTitle(), (char far*)errorStr);

  char  errorCaption[80];
  module.LoadString(IDS_PRNERRORCAPTION, errorCaption, sizeof(errorCaption));
  parent->MessageBox(errorMsg, errorCaption, MB_OK | MB_ICONSTOP);
}

TPrinter::TXPrinter::TXPrinter(UINT resId) : TXOwl(resId)
{
}

#endif
#if !defined(SECTION) || SECTION == 2

IMPLEMENT_STREAMABLE(TPrinter);

void*
TPrinter::Streamer::Read(ipstream& is, uint32 version) const
{
  GetObject()->Data->Read(is, version);
  return GetObject();
}

void
TPrinter::Streamer::Write(opstream& os) const
{
  GetObject()->Data->Write(os);
}

#endif

