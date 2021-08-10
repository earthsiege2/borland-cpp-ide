#if !defined(__fshfctap_h)              // Sentry, use file only if it's not already included.
#define __fshfctap_h

/*  Project fishfact
    Borland International
    Copyright © 1996. All Rights Reserved.

    SUBSYSTEM:    fishfact.exe Application
    FILE:         ffactwin.h
    AUTHOR:       


    OVERVIEW
    ========
    Class definition for fishfactApp (TApplication).

	$Revision:   1.1  $
	$Author:   JHEHER  $
	$Date:   03 Jan 1996 15:54:30  $

*/


#include <owl\pch.h>
#pragma hdrstop


#include "ffactwin.rh"            // Definition of all resources.


//
// FrameWindow must be derived to override Paint for Preview and Print.
//
//{{TDecoratedFrame = SDIDecFrame}}
class SDIDecFrame : public TDecoratedFrame {
public:
    SDIDecFrame (TWindow *parent, const char far *title, TWindow *clientWnd, bool trackMenuSelection = false, TModule *module = 0);
    ~SDIDecFrame ();
};    //{{SDIDecFrame}}


//{{TApplication = fishfactApp}}
class fishfactApp : public TApplication {
private:

public:
    fishfactApp ();
    virtual ~fishfactApp ();

//{{fishfactAppVIRTUAL_BEGIN}}
public:
    virtual void InitMainWindow();
//{{fishfactAppVIRTUAL_END}}

//{{fishfactAppRSP_TBL_BEGIN}}
protected:
    void CmHelpAbout ();
//{{fishfactAppRSP_TBL_END}}
DECLARE_RESPONSE_TABLE(fishfactApp);
};    //{{fishfactApp}}


#endif                                      // __fshfctap_h sentry.
