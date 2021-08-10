//----------------------------------------------------------------------------
// ObjectWindows
// Copyright (c) 1995, 1996 by Borland International, All Rights Reserved
//
// $Revision:   10.8  $
//
// Sample illustrating the use of OCXes in dialogs - Defines TOcxDlgApp 
//----------------------------------------------------------------------------
#if !defined(_OCXDLGAPP_H) 
#define _OCXDLGAPP_H

// Main Application object
//
class TOcxDlgApp : public TApplication, public TOcModule {

  public:
    TOcxDlgApp();

    // Since this is a non-docview application, an implementation of 
    // CreateOleObject for app class must be provided.
    //
    TUnknown* CreateOleObject(uint32 options, TRegLink* link) {return 0;}

  public:
	 // Overriden virtuals of TApplication
	 //
    void InitMainWindow();
    void InitInstance();
};


#endif  // _OCXDLGAPP_H 
