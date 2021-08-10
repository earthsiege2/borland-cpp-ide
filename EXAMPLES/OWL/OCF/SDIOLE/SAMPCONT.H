///----------------------------------------------------------------------------
// ObjectWindows - (C) Copyright 1994 by Borland International
// The sample ole container window. Use as a client of a frame window
//-----------------------------------------------------------------------------
#if !defined(SAMPCONT_H)
#define SAMPCONT_H

#define IDS_DOCFILEFILTER    1
#define CM_EDIT_PASTESPECIAL 301
#define CM_EDIT_PASTELINK    302
#define CM_EDIT_INSERTOBJECT 303

#if !defined(RC_INVOKED)

#if !defined(OWL_OLEWINDO_H)
# include <owl/olewindo.h>
#endif

#if !defined(OWL_PRINTER_H)
# include <owl/printer.h>
#endif

#if !defined(OWL_OPENSAVE_H)
# include <owl/opensave.h>
#endif
#include <owl/editfile.rh>

class TOleSampContainer : public TOleWindow {
  public:
    TOleSampContainer(TWindow*        parent = 0,
                      const char far* fileName = 0,
                      TModule*        module = 0);
   ~TOleSampContainer();

  private:
    void SetupWindow();
    void CleanupWindow();

    void CmFileSave();
    void CmFileSaveAs();
    void CmExit();
    void CmFilePrint();
    void CmFilePrinterSetup();
    void CmPrintPreview();

    bool CanClose();

    TOpenSaveDialog::TData   FileData;
    TPrinter*                Printer;

  DECLARE_RESPONSE_TABLE(TOleSampContainer);
};

#endif
#endif
