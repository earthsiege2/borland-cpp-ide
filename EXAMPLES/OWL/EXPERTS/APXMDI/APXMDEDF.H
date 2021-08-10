//----------------------------------------------------------------------------
//  Project ApxMdi
//  Borland International
//  Copyright © 1996. All Rights Reserved.
//
//  SUBSYSTEM:    ApxMdi Application
//  FILE:         apxmdedf.h
//  AUTHOR:       
//
//  OVERVIEW
//  ~~~~~~~~
//  Class definition for TApxMdiEditFile (TEditFile).
//
//----------------------------------------------------------------------------
#if !defined(apxmdedf_h)              // Sentry, use file only if it's not already included.
#define apxmdedf_h

#include <owl/editfile.h>

#include "apxmdapp.rh"            // Definition of all resources.


//{{TEditFile = TApxMdiEditFile}}
class TApxMdiEditFile : public TEditFile {
  public:
    TApxMdiEditFile(TWindow* parent = 0, int id = 0, const char far* text = 0, int x = 0, int y = 0, int w = 0, int h = 0, const char far* fileName = 0, TModule* module = 0);
    virtual ~TApxMdiEditFile();

//{{TApxMdiEditFileVIRTUAL_BEGIN}}
  public:
    virtual void Paint(TDC& dc, bool erase, TRect& rect);
    virtual void SetupWindow();
    virtual bool SaveAs();
//{{TApxMdiEditFileVIRTUAL_END}}
//{{TApxMdiEditFileRSP_TBL_BEGIN}}
  protected:
    void EvGetMinMaxInfo(MINMAXINFO far& minmaxinfo);
//{{TApxMdiEditFileRSP_TBL_END}}
DECLARE_RESPONSE_TABLE(TApxMdiEditFile);
};    //{{TApxMdiEditFile}}


#endif  // apxmdedf_h sentry.
