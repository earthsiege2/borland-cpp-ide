//----------------------------------------------------------------------------
// ObjectWindows
// Copyright (c) 1994, 1995 by Borland International, All Rights Reserved
//----------------------------------------------------------------------------
#include <owl/pch.h>
#include <owl/applicat.h>
#include <owl/gdiobjec.h>

#include <ocf/ocapp.h>
#include <ocf/ocdoc.h>
#include <ocf/ocview.h>
#include <ocf/ocstorag.h>
#include <ocf/ocreg.h>

#include <owl/ocfevent.h>
#include <owl/uihelper.h>
#include <owl/printer.h>
#include <owl/preview.h>

#include <owl/oleframe.h>
#include <owl/docview.rh>
#include <owl/editfile.rh>

#include "sampcont.h"
#define USE_WINDOW_PRINTOUT

//----------------------------------------------------------------------------
// Printout class that prints the contents of a window
//
class TWindowPrintout : public TPrintout {
  public:
    TWindowPrintout(const char* title, TWindow* window, bool scale = true)
      : TPrintout(title)
      { Window = window;
        Scale = scale;
        MapMode = MM_ISOTROPIC;    // Respect aspect ratio of window
        //MapMode = MM_ANISOTROPIC;  // Make printout fill the page
      }

    void GetDialogInfo(int& minPage, int& maxPage, int& selFromPage, int& selToPage);
    void PrintPage(int page, TRect& rect, unsigned flags);

  protected:
    TWindow*  Window;
    bool      Scale;
    int       MapMode;
};

//
// Do not enable page range in the print dialog since only one page is
// available to be printed
//
void TWindowPrintout::GetDialogInfo(int& minPage, int& maxPage, int& selFromPage, int& selToPage)
{
  minPage = 0;
  maxPage = 0;
  selFromPage = selToPage = 0;
}

//
//
//
void TWindowPrintout::PrintPage(int /*page*/, TRect& bandRect, unsigned /*flags*/)
{
  // Conditionally scale the DC to the window so the printout will
  // resemble the window
  //
  int    oldMode;
  TSize  oldVExt, oldWExt;
  if (Scale) {
    oldMode = DC->SetMapMode(MapMode);
    TRect clientR = Window->GetClientRect();
    DC->SetViewportExt(PageSize, &oldVExt);
    DC->SetWindowExt(clientR.Size(), &oldWExt);
    DC->IntersectClipRect(clientR);
    DC->DPtoLP(bandRect, 2);
  }

  // Call the window to paint itself to the printer DC.
  //
  Window->Paint(*DC, FALSE, bandRect);

  // Restore changes made to the DC
  //
  if (Scale) {
    DC->SetWindowExt(oldWExt);
    DC->SetViewportExt(oldVExt);
    DC->SetMapMode(oldMode);
  }
}

//----------------------------------------------------------------------------

//
//
//
class TModalFrame : public TFrameWindow {
  public:
    TModalFrame(TWindow* parent, const char far* title, TWindow* client) :
      TFrameWindow(parent, title, client),
      TWindow(parent, title)  {}

    virtual void Destroy(int ret);
};

//
//
//
void TModalFrame::Destroy(int ret)
{
  GetApplication()->EndModal(IDCANCEL);
  GetApplication()->MainWindow->EnableWindow(TRUE);

  TWindow::Destroy(ret);
}

//----------------------------------------------------------------------------

DEFINE_RESPONSE_TABLE1(TOleSampContainer, TOleWindow)
  EV_COMMAND(CM_FILESAVE, CmFileSave),
  EV_COMMAND(CM_FILESAVEAS, CmFileSaveAs),
  EV_COMMAND(CM_FILEPRINT, CmFilePrint),
  EV_COMMAND(CM_FILEPRINTERSETUP, CmFilePrinterSetup),
  EV_COMMAND(CM_FILEPRINTPREVIEW, CmPrintPreview),
END_RESPONSE_TABLE;

BEGIN_REGISTRATION(docReg)
  REGDATA(progid,     "SdiOle")
  REGDATA(description,"SdiOle Document")
  REGFORMAT(0, ocrEmbedSource,  ocrContent,  ocrIStorage, ocrGet)
  REGFORMAT(1, ocrMetafilePict, ocrContent,  ocrMfPict|ocrStaticMed, ocrGet)
  REGFORMAT(2, ocrBitmap, ocrContent,  ocrGDI|ocrStaticMed, ocrGet)
  REGFORMAT(3, ocrDib, ocrContent,  ocrHGlobal|ocrStaticMed, ocrGet)
  REGFORMAT(4, ocrLinkSource, ocrContent,  ocrIStream, ocrGet)
END_REGISTRATION


//
//
//
TOleSampContainer::TOleSampContainer(TWindow*        parent,
                                     const char far* fileName,
                                     TModule*        module)
:
  TOleWindow(parent, module)
{
  // Create a OcDocument object to hold the ole parts that we create
  // and a OcView to provide ole services
  //
  OcDoc = new TOcDocument(*OcApp, fileName);
  OcView = new TOcView(*OcDoc, &docReg);

  // Perform actual file loading, and let the OcDoc load its parts
  //
  if (fileName) {
    strcpy(FileData.FileName, fileName);
    OcDoc->LoadParts();
  }
  else {
    strcpy(FileData.FileName, "");
  }
  FileData.Flags = OFN_HIDEREADONLY|OFN_OVERWRITEPROMPT;
  FileData.SetFilter(string(*GetModule(), IDS_DOCFILEFILTER).c_str());
  Printer = new TPrinter;
}

//
//
//
TOleSampContainer::~TOleSampContainer()
{
  delete Printer;
}

//
// Perform normal SetupWindow, plus let the OcView object know our HWND so that
// it can talk to us.
//
void
TOleSampContainer::SetupWindow()
{
  TOleWindow::SetupWindow();
  SetDocTitle(*FileData.FileName ? FileData.FileName : "Untitled", 0);
}

//
//
//
void
TOleSampContainer::CleanupWindow()
{
  TOleWindow::CleanupWindow();
}

//
//
//
void
TOleSampContainer::CmExit()
{
  OcView->EvClose();
  OcDoc->Close();
//  GetApplication()->CmExit();
}

//
// Perform a save operation (or saveAs if doc is untitled) This saves the parts
// and commits the storage
//
void
TOleSampContainer::CmFileSave()
{
  if (!OcDoc->GetName().length()) {
    CmFileSaveAs();
  }
  else {
    OcDoc->SaveParts(0, true);
    OcDoc->GetStorage()->Commit(STGC_DEFAULT);
  }
}

//
// Save the document to a new storage file
//
void
TOleSampContainer::CmFileSaveAs()
{
  *FileData.FileName = 0;
  if (TFileSaveDialog(this, FileData).Execute() == IDOK) {
    if (OcDoc->SaveToFile(FileData.FileName)) {
      OcDoc->GetStorage()->Commit(STGC_DEFAULT);
      SetDocTitle(FileData.FileName, 0);
    }
    else
      MessageBox("Cannot save to new file", "File save error", MB_OK);
  }
}

//
//
//
void
TOleSampContainer::CmFilePrint()          // Execute File:Print command
{
  if (Printer) {
    TWindowPrintout printout("OLE2 Container", this);
    Printer->Print(this, printout, TRUE);
  }
}

//
//
//
void
TOleSampContainer::CmFilePrinterSetup()    // Execute File:Printer-setup command
{
  if (Printer)
    Printer->Setup(this);
}

//
//
//
void
TOleSampContainer::CmPrintPreview()
{
  // Create the printer DC. If it fails, let the print dialog report the error
  // for us.
  //
  TPrintDC* prnDC;
  try {
    prnDC = new TPrintDC(Printer->GetSetup().GetDriverName(),
                         Printer->GetSetup().GetDeviceName(),
                         Printer->GetSetup().GetOutputName(),
                         Printer->GetSetup().GetDevMode());
  }
  catch (TXGdi) {
    TPrintDialog(Parent, Printer->GetSetup()).Execute();
    return;
  }

  TSize printExtent(prnDC->GetDeviceCaps(HORZRES), prnDC->GetDeviceCaps(VERTRES));

#if defined(USE_WINDOW_PRINTOUT)
  TWindowPrintout printout("Print Preview", this);
#else
  TTestPrintout   printout("Print Preview");
#endif

  TLayoutWindow* layout = new TLayoutWindow(0);
  layout->SetBkgndColor(GetSysColor(COLOR_APPWORKSPACE));

  for (int i = 0; i < 1; i++) {
    TPreviewPage* page = new TPreviewPage(layout, printout, *prnDC, printExtent);

    TLayoutMetrics metrics;
    metrics.X.Set(lmLeft, lmRightOf, lmParent, lmLeft, 15);
    metrics.Y.Set(lmTop, lmBelow, lmParent, lmTop, 15);

    // Determine major axis of preview page, have that follow parent size.
    // Make minor axis a percentage (aspect ratio) of the page's major axis
    //
    if (printExtent.cx > printExtent.cy) {
      metrics.Width.Set(lmRight, lmLeftOf, lmParent, lmRight, 15);
      metrics.Height.PercentOf(page, int((long(printExtent.cy)*100)/printExtent.cx),
                               lmWidth);
    }
    else {
      metrics.Height.Set(lmBottom, lmAbove, lmParent, lmBottom, 15);
      metrics.Width.PercentOf(page, int((long(printExtent.cx)*100)/printExtent.cy),
                              lmHeight);
    }

    layout->SetChildLayoutMetrics(*page, metrics);
  }

  TFrameWindow* frame = new TModalFrame(this, "Preview", layout);
  frame->Create();
  frame->ShowWindow(SW_SHOWNORMAL);

  GetApplication()->BeginModal(Parent);
  delete prnDC;
}

//
// See if we can close. Also let OcView know we are going away
//
bool
TOleSampContainer::CanClose()
{
  if (!TOleWindow::CanClose())
    return false;

  OcView->EvClose();
  OcDoc->Close();
  return true;
}
