//----------------------------------------------------------------------------
//  Project OcxDlg
//  Borland International, Inc.
//  Copyright © 1996. All Rights Reserved.
//
//  SUBSYSTEM:    OcxDlg Application
//  FILE:         OcxDlgAp.h
//  AUTHOR:       Chris McConn
//
//  OVERVIEW
//  ~~~~~~~~
//  Class definition for TOcxDlgApp (TApplication).
//
//----------------------------------------------------------------------------
#if !defined(_OCXDLGAPP_H) // Sentry, use file only if it's not already included.
#define _OCXDLGAPP_H

//============================================================================
// Main Application object
class TOcxDlgApp : public TApplication, public TOcModule {

  // Functions --------------------------------------------------------------
  public:// Constructors/Destructors
    TOcxDlgApp();
    virtual ~TOcxDlgApp();

    // Since this is a non-docview application, an implementation of 
    // CreateOleObject for app class must be provided.
    TUnknown* CreateOleObject(uint32 options, TRegLink* link) {return 0;}

  public:// Implement virtual methods of TApplication
    virtual void InitMainWindow();
    virtual void InitInstance();

  // Response Table Declaration
  DECLARE_RESPONSE_TABLE(TOcxDlgApp);

};


#endif  // _OCXDLGAPP_H sentry.
