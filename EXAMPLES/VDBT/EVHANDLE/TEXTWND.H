//----------------------------------------------------------------------------
//  Project EVHANDLE
//  
//  Copyright © 1996. All Rights Reserved.
//
//  SUBSYSTEM:    EVHANDLE Application
//  FILE:         textwnd.h
//  AUTHOR:       
//
//  OVERVIEW
//  ~~~~~~~~
//  Class definition for TexWindow.
//
//----------------------------------------------------------------------------
#if !defined(textwnd_h) // Sentry, use file only if it's not already included.
#define textwnd_h

#include <owl\window.h>
#include <owl\listbox.h>
#include <string.h>

//
// this class will have a listbox child that will be sized
// to take up the entire client area and will display the strings
// passed into OutputString()
//
class TextWindow: public TWindow
{
public:
	TextWindow(TWindow *par, char *title,TModule *mod=0);
   void OutputString(char *text);
   void SetupWindow();

protected:
	TListBox *EventsList;
};

#endif  // textwnd_h sentry.
