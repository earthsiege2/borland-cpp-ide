//----------------------------------------------------------------------------
//  Project EVHANDLE
//  
//  Copyright © 1996. All Rights Reserved.
//
//  SUBSYSTEM:    EVHANDLE Application
//  FILE:         textwnd.cpp
//  AUTHOR:       
//
//  OVERVIEW
//  ~~~~~~~~
//  Source file for implementation of TextWindow.
//
//----------------------------------------------------------------------------


#include "textwnd.h"

TextWindow::TextWindow(TWindow *par,char *title,TModule *mod):
	TWindow(par,title,mod)
{
	Attr.X=5;
   Attr.Y=5;
   Attr.W=300;
   Attr.H=100;
   Attr.Style = WS_POPUPWINDOW | WS_CAPTION;
   EventsList= new TListBox(this,101,0,0,300,100);
   EventsList->Attr.Style &= ~LBS_SORT;
}

void TextWindow::SetupWindow()
{
	TWindow::SetupWindow();
   TRect rect=GetClientRect();
   // resize listbox to the entire client area of its parent window
   EventsList->SetWindowPos(0,rect,SWP_NOZORDER);
}

//
// Add the string passed in into the listbox
//
void TextWindow::OutputString(char *text)
{
	EventsList->AddString(text);
}


