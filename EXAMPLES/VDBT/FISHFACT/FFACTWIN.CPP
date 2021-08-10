/*  Project fishfact
    Borland International
    Copyright © 1996. All Rights Reserved.

    SUBSYSTEM:    fishfact.exe Application
    FILE:         ffactwin.cpp
    AUTHOR:       


    OVERVIEW
    ========
    Source file for implementation of fishfactApp (TApplication).

*/


#include <owl\pch.h>
#pragma hdrstop


#include "ffactwin.h"
#include "fshtdlgc.h"                        // Definition of client class.

#include <owl\vbxctl.h>       


//{{fishfactApp Implementation}}


//
// Build a response table for all messages/commands handled
// by the application.
//
DEFINE_RESPONSE_TABLE1(fishfactApp, TApplication)
//{{fishfactAppRSP_TBL_BEGIN}}
    EV_COMMAND(CM_HELPABOUT, CmHelpAbout),
//{{fishfactAppRSP_TBL_END}}
END_RESPONSE_TABLE;


//////////////////////////////////////////////////////////
// fishfactApp
// =====
//
fishfactApp::fishfactApp () : TApplication("fishfact")
{

    // INSERT>> Your constructor code here.
}


fishfactApp::~fishfactApp ()
{
    // INSERT>> Your destructor code here.
}


//////////////////////////////////////////////////////////
// fishfactApp
// =====
// Application intialization.
//
void fishfactApp::InitMainWindow ()
{
    if (nCmdShow != SW_HIDE)
        nCmdShow = (nCmdShow != SW_SHOWMINNOACTIVE) ? SW_SHOWNORMAL : nCmdShow;

    SDIDecFrame *frame = new SDIDecFrame(0, GetName(), 0, false);
    frame->SetFlag(wfShrinkToClient);

    // Override the default window style for the main window.
    frame->Attr.Style |= WS_BORDER | WS_CAPTION | WS_CLIPCHILDREN | WS_THICKFRAME | WS_VISIBLE;
    frame->Attr.Style &= ~(WS_CHILD | WS_MAXIMIZEBOX | WS_MINIMIZEBOX | WS_SYSMENU);

    //
    // Assign ICON w/ this application.
    //
    frame->SetIcon(this, IDI_FISHFACT);

  
    SetMainWindow(frame);

}


//{{SDIDecFrame Implementation}}


SDIDecFrame::SDIDecFrame (TWindow *parent, const char far *title, TWindow *clientWnd, bool trackMenuSelection, TModule *module)
    : TDecoratedFrame(parent, title, clientWnd == 0 ? new fishfactTDLGClient(0) : clientWnd, trackMenuSelection, module)
{
    // INSERT>> Your constructor code here.

}


SDIDecFrame::~SDIDecFrame ()
{
    // INSERT>> Your destructor code here.

}


//////////////////////////////////////////////////////////
// fishfactApp
// ===========
// Menu Help About fishfact.exe command
void fishfactApp::CmHelpAbout ()
{
}
int OwlMain (int , char* [])
{
	TBIVbxLibrary BiLibrary;
   
    try {
        fishfactApp    app;
        return app.Run();
    }
    catch (xmsg& x) {
        ::MessageBox(0, x.why().c_str(), "Exception", MB_OK);
    }

    return -1;
}
