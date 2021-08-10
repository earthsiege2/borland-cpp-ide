//----------------------------------------------------------------------------
//  Project ApxMdiDv
//  Borland International
//  Copyright © 1996. All Rights Reserved.
//
//  SUBSYSTEM:    ApxMdiDv Application
//  FILE:         apmdmdic.h
//  AUTHOR:       
//
//  OVERVIEW
//  ~~~~~~~~
//  Class definition for TApxMdiDvMDIClient (TMDIClient).
//
//----------------------------------------------------------------------------
#if !defined(apmdmdic_h)              // Sentry, use file only if it's not already included.
#define apmdmdic_h

#include "apxmddva.rh"            // Definition of all resources.


//{{TMDIClient = TApxMdiDvMDIClient}}
class TApxMdiDvMDIClient : public TMDIClient {
  public:
    int      ChildCount;                 // Number of child window created.

    TApxMdiDvMDIClient(TModule* module = 0);
    virtual ~TApxMdiDvMDIClient();

    void OpenFile(const char* fileName = 0);

//{{TApxMdiDvMDIClientVIRTUAL_BEGIN}}
  protected:
    virtual void SetupWindow();
//{{TApxMdiDvMDIClientVIRTUAL_END}}

//{{TApxMdiDvMDIClientRSP_TBL_BEGIN}}
  protected:
    void CmFilePrint();
    void CmFilePrintSetup();
    void CmFilePrintPreview();
    void CmPrintEnable(TCommandEnabler& tce);
    void EvDropFiles(TDropInfo);
//{{TApxMdiDvMDIClientRSP_TBL_END}}
DECLARE_RESPONSE_TABLE(TApxMdiDvMDIClient);
};    //{{TApxMdiDvMDIClient}}


#endif  // apmdmdic_h sentry.
