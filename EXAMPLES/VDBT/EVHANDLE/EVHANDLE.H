//----------------------------------------------------------------------------
//  Project EVHANDLE
//  
//  Copyright © 1996. All Rights Reserved.
//
//  SUBSYSTEM:    EVHANDLE Application
//  FILE:         EVHANDLE.H
//  AUTHOR:       
//
//  OVERVIEW
//  ~~~~~~~~
//  Class definition for TSinkDlgApp (TApplication).
//
//----------------------------------------------------------------------------
#if !defined(evhandle_h)              // Sentry, use file only if it's not already included.
#define evhandle_h

#include <owl/opensave.h>


#include "evhandle.rh"            // Definition of all resources.


//
// Over riding this class to take control of window placement on startup
//
class TSDIDecFrame : public TDecoratedFrame
{
public:
	TSDIDecFrame(TWindow* parent, const char far* title, TWindow* clientWnd, bool trackMenuSelection = false, TModule* module = 0);
	~TSDIDecFrame();
};

class TSinkDlgApp : public TApplication
{
private:


public:
    TSinkDlgApp();
    virtual ~TSinkDlgApp();
    virtual void InitMainWindow();
protected:

DECLARE_RESPONSE_TABLE(TSinkDlgApp);
};    


#endif  // evhandle_h sentry.
