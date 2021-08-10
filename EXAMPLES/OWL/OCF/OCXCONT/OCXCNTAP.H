//----------------------------------------------------------------------------
// ObjectWindows
// Copyright (c) 1995, 1996 by Borland International, All Rights Reserved
//
// $Revision:   10.0  $
//
// Sample illustrating a container with an OCX as client window
//----------------------------------------------------------------------------
#if !defined(OCXCONTAPP_H)
#define OCXCONTAPP_H

#if !defined(OCF_OCAPP_H)
# include <ocf/ocapp.h>
#endif
#if !defined(OWL_APPLICAT_H)
# include <owl/applicat.h>
#endif


// Main Application object
//
class TOCXContApp : public TApplication, public TOcAppHost {

  public:
    TOCXContApp();

    // Since this is a non-docview application, an implementation of
    // CreateOleObject for app class must be provided.
    //
    TUnknown* CreateOleObject(uint32 options, TRegLink* link) {return 0;}

  public:

    // Override virtual methods of TApplication
    //
    virtual void InitMainWindow();
    virtual void InitInstance();
};

#endif
