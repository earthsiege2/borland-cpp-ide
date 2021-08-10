//----------------------------------------------------------------------------
//  Project ApxMdi
//  Borland International
//  Copyright © 1996. All Rights Reserved.
//
//  SUBSYSTEM:    ApxMdi Application
//  FILE:         apxmmdic.h
//  AUTHOR:       
//
//  OVERVIEW
//  ~~~~~~~~
//  Class definition for TApxMdiMDIClient (TMDIClient).
//
//----------------------------------------------------------------------------
#if !defined(apxmmdic_h)              // Sentry, use file only if it's not already included.
#define apxmmdic_h

#include "apxmdapp.rh"            // Definition of all resources.


//{{TMDIClient = TApxMdiMDIClient}}
class TApxMdiMDIClient : public TMDIClient {
  public:
    int      ChildCount;                 // Number of child window created.

    TApxMdiMDIClient(TModule* module = 0);
    virtual ~TApxMdiMDIClient();

    void OpenFile(const char* fileName = 0);

//{{TApxMdiMDIClientVIRTUAL_BEGIN}}
  protected:
    virtual void SetupWindow();
//{{TApxMdiMDIClientVIRTUAL_END}}

//{{TApxMdiMDIClientRSP_TBL_BEGIN}}
  protected:
    void CmFileNew();
    void CmFileOpen();
    void CmFileClose();
    void CmFilePrint();
    void CmFilePrintSetup();
    void CmFilePrintPreview();
    void CmPrintEnable(TCommandEnabler& tce);
    void EvDropFiles(TDropInfo);
//{{TApxMdiMDIClientRSP_TBL_END}}
DECLARE_RESPONSE_TABLE(TApxMdiMDIClient);
};    //{{TApxMdiMDIClient}}


#endif  // apxmmdic_h sentry.
