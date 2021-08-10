//----------------------------------------------------------------------------
//  Project ApxSdi
//  Borland International
//  Copyright © 1996. All Rights Reserved.
//
//  SUBSYSTEM:    ApxSdi Application
//  FILE:         apxsdedf.h
//  AUTHOR:       
//
//  OVERVIEW
//  ~~~~~~~~
//  Class definition for TApxSdiEditFile (TEditFile).
//
//----------------------------------------------------------------------------
#if !defined(apxsdedf_h)              // Sentry, use file only if it's not already included.
#define apxsdedf_h

#include <owl/editfile.h>

#include "apxsdapp.rh"            // Definition of all resources.


//{{TEditFile = TApxSdiEditFile}}
class TApxSdiEditFile : public TEditFile {
  public:
    TApxSdiEditFile(TWindow* parent = 0, int id = 0, const char far* text = 0, int x = 0, int y = 0, int w = 0, int h = 0, const char far* fileName = 0, TModule* module = 0);
    virtual ~TApxSdiEditFile();

//{{TApxSdiEditFileVIRTUAL_BEGIN}}
  public:
    virtual void Paint(TDC& dc, bool erase, TRect& rect);
    virtual void SetupWindow();
    virtual bool SaveAs();
//{{TApxSdiEditFileVIRTUAL_END}}
//{{TApxSdiEditFileRSP_TBL_BEGIN}}
  protected:
    void EvGetMinMaxInfo(MINMAXINFO far& minmaxinfo);
//{{TApxSdiEditFileRSP_TBL_END}}
DECLARE_RESPONSE_TABLE(TApxSdiEditFile);
};    //{{TApxSdiEditFile}}


#endif  // apxsdedf_h sentry.
