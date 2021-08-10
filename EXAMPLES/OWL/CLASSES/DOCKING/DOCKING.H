//----------------------------------------------------------------------------
// ObjectWindows
// Copyright (c) 1995, 1995 by Borland International, All Rights Reserved
//
// Docking window example main header file
//----------------------------------------------------------------------------
#if !defined(DOCKING_H)
#define DOCKING_H

#include <owl/docking.h>
#include <owl/opensave.h>

#include "docking.rh"            // Definition of all resources.

class TDockingApp : public TApplication {
  public:
    TDockingApp();
   ~TDockingApp();

    TOpenSaveDialog::TData  FileData;       // Data to control open/saveas standard dialog.

    THarbor*    Harbor;
    TMDIClient* MdiClient;
    int         ChildCount;                 // Number of child window created. 

    // Public data members used by the print menu commands and Paint routine in MDIChild.

  protected:
    virtual void InitMainWindow();

    void OpenFile(const char* fileName = 0);

    void CmHelpAbout();

    void CmFileNew();
    void CmFileOpen();
    void CmFilePrint();
    void CmFilePrintSetup();
    void CmFilePrintPreview();
    void CePrint(TCommandEnabler& ce);

  private:
    void SetupSpeedBar(TDecoratedFrame* frame);
    void AddFiles(TFileDropletList& files);

  DECLARE_RESPONSE_TABLE(TDockingApp);
};

#endif
