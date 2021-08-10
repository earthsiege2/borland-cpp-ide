//----------------------------------------------------------------------------
//  Project ApxOle
//  Borland International
//  Copyright © 1996. All Rights Reserved.
//
//  SUBSYSTEM:    ApxOle Application
//  FILE:         apxomdic.h
//  AUTHOR:       
//
//  OVERVIEW
//  ~~~~~~~~
//  Class definition for TApxOleMDIClient (TMDIClient).
//
//----------------------------------------------------------------------------
#if !defined(apxomdic_h)              // Sentry, use file only if it's not already included.
#define apxomdic_h

#include "apxolapp.rh"            // Definition of all resources.


//{{TMDIClient = TApxOleMDIClient}}
class TApxOleMDIClient : public TMDIClient {
  public:
    int      ChildCount;                 // Number of child window created.

    TApxOleMDIClient(TModule* module = 0);
    virtual ~TApxOleMDIClient();

    void OpenFile(const char* fileName = 0);

//{{TApxOleMDIClientVIRTUAL_BEGIN}}
  protected:
    virtual void SetupWindow();
//{{TApxOleMDIClientVIRTUAL_END}}

//{{TApxOleMDIClientRSP_TBL_BEGIN}}
  protected:
    void CmFilePrint();
    void CmFilePrintSetup();
    void CmFilePrintPreview();
    void CmPrintEnable(TCommandEnabler& tce);
    void EvDropFiles(TDropInfo);
//{{TApxOleMDIClientRSP_TBL_END}}
DECLARE_RESPONSE_TABLE(TApxOleMDIClient);
};    //{{TApxOleMDIClient}}


#endif  // apxomdic_h sentry.
