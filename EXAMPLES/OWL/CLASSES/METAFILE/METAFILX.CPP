//----------------------------------------------------------------------------
// ObjectWindows
// Copyright (c) 1995, 1996 by Borland International, All Rights Reserved
//----------------------------------------------------------------------------
#include <owl/pch.h>
#if !defined(OWL_APPLICAT_H)
# include <owl/applicat.h>
#endif
#if !defined(OWL_FRAMEWIN_H)
# include <owl/framewin.h>
#endif
#if !defined(OWL_STATIC_H)
# include <owl/static.h>
#endif
#if !defined(OWL_METAFILE_H)
# include <owl/metafile.h>
#endif
#if !defined(OWL_OPENSAVE_H)
# include <owl/opensave.h>
#endif
#if !defined(OWL_EDITFILE_RH)
# include <owl/editfile.rh>
#endif
#include <stdio.h>

//
// class TMetaFileExWindow
// ~~~~~ ~~~~~~~~~~~~~~~~~
class TMetaFileExWindow : public TWindow {
  public:
    TMetaFileExWindow() : TWindow(0, 0, 0)
    {}

    TAPointer<char>   FileName;

#if defined(BI_PLAT_WIN32)
    bool              Enhanced;
#endif

    void              CmFileOpen();
    void              Paint(TDC& dc, bool erase, TRect& rect);
    void              EvSize(uint sizeType, TSize& size);

  DECLARE_RESPONSE_TABLE(TMetaFileExWindow);
};

DEFINE_RESPONSE_TABLE1(TMetaFileExWindow, TWindow)
  EV_COMMAND(CM_FILEOPEN, CmFileOpen),
  EV_WM_SIZE,
END_RESPONSE_TABLE;

//
//
//
void
TMetaFileExWindow::CmFileOpen()
{
  char* filter = 
#if defined(BI_PLAT_WIN32)
                       "Enh. Metafiles|*.emf|"
#endif
                       "Metafiles |*.wmf|";

  // Prompt user for filenane
  //
  TOpenSaveDialog::TData data(OFN_FILEMUSTEXIST, filter);
  if (TFileOpenDialog(this, data).Execute() == IDOK) {
    FileName = strnewdup(data.FileName);

#if defined(BI_PLAT_WIN32)
    Enhanced = data.FilterIndex == 1;
#endif
    
    // Force redraw
    //
    Invalidate();
  }
}

//
//
//
void              
TMetaFileExWindow::Paint(TDC& dc, bool /*erase*/, TRect& /*rect*/)
{
  TRect clientRect;
  GetClientRect(clientRect);

  if ((char*)FileName) {
    try {
    
#if defined(BI_PLAT_WIN32)
      if (Enhanced) {
        TEnhMetaFilePict emf(FileName);
        emf.PlayOnto(dc, &clientRect);
        return;
      }
#endif
      TMetaFilePict mf(FileName);
      mf.PlayOnto(dc, clientRect.Size());
    }
    catch (TXGdi& xcpt) {
      MessageBeep(-1);
    }
  }
}

//
//
//
void              
TMetaFileExWindow::EvSize(uint sizeType, TSize& size)
{
  TWindow::EvSize(sizeType, size);
  Invalidate();
}

//
// class TMetaFileExApp
// ~~~~~ ~~~~~~~~~~~~~~
class _USERCLASS TMetaFileExApp : public TApplication {
  public:
    void InitMainWindow();
};

void
TMetaFileExApp::InitMainWindow()
{
  TFrameWindow* frame = new TFrameWindow(0, "Metafile Example",
                                         new TMetaFileExWindow);
  frame->AssignMenu("MAINMENU");
  SetMainWindow(frame);
}

int
OwlMain(int /*argc*/, char* /*argv*/ [])
{
  return TMetaFileExApp().Run();
}
