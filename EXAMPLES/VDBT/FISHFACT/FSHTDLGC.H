#if !defined(__fshtdlgc_h)              // Sentry, use file only if it's not already included.
#define __fshtdlgc_h

/*  Project fishfact
    Borland International
    Copyright © 1996. All Rights Reserved.

    SUBSYSTEM:    fishfact.exe Application
    FILE:         fshtdlgc.h
    AUTHOR:       


    OVERVIEW
    ========
    Class definition for fishfactTDLGClient (TDialog).

	$Revision:   1.2  $
	$Author:   JHEHER  $
	$Date:   09 Feb 1996 15:47:36  $

*/


#include <owl\pch.h>
#pragma hdrstop
#include <owl\vbxctl.h>
#include "ffactwin.rh"                  // Definition of all resources.


//{{TDialog = fishfactTDLGClient}}
class fishfactTDLGClient : public TDialog, public TVbxEventHandler {
public:
	 fishfactTDLGClient (TWindow *parent, TResId resId = IDD_FISHFACT, TModule *module = 0);
    virtual ~fishfactTDLGClient ();

	 DECLARE_RESPONSE_TABLE(fishfactTDLGClient);

};    //{{fishfactTDLGClient}}


#endif                                      // __fshtdlgc_h sentry.
