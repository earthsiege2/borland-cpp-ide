//----------------------------------------------------------------------------
// ObjectWindows
// Copyright (c) 1995, 1996 by Borland International, All Rights Reserved
//
// $Revision:   10.0  $
//
// Sample illustrating a container with an OCX as main window
//----------------------------------------------------------------------------
#include <owl/pch.h>
#if !defined(OWL_OLEWINDOW_H)
# include<owl/olewindo.h>
#endif
#include "ocxcont.h"

DEFINE_RESPONSE_TABLE1(TOCXContWindow, TOleWindow)
END_RESPONSE_TABLE;

//
//
//
TOCXContWindow::TOCXContWindow(TWindow* parent)
               :TOleWindow(parent)
{}

//
//
//
void
TOCXContWindow::SetupWindow()
{
  // Chain to base class
  //
  TOleWindow::SetupWindow();
}

//
//
//
bool
TOCXContWindow::EvOcAmbientGetBackColor(long* rgb)
{
  return false;
}

//
//
//
bool
TOCXContWindow::EvOcAmbientGetForeColor(long* rgb)
{
  return false;
}

//
//
//
bool
TOCXContWindow::EvOcAmbientGetLocaleID(long* locale)
{
  return false;
}

//
//
//
bool
TOCXContWindow::EvOcAmbientGetTextAlign(short* align)
{
  return false;
}

//
//
//
bool
TOCXContWindow::EvOcAmbientGetMessageReflect(bool* msgReflect)
{
  return false;
}

//
//
//
bool
TOCXContWindow::EvOcAmbientGetUserMode(bool* mode)
{
  return false;
}

//
//
//
bool
TOCXContWindow::EvOcAmbientGetUIDead(bool* dead)
{
  return false;
}

//
//
//
bool
TOCXContWindow::EvOcAmbientGetShowGrabHandles(bool* show)
{
  return false;
}

//
//
//
bool
TOCXContWindow::EvOcAmbientGetShowHatching(bool* show)
{
  return false;
}

//
//
//
bool
TOCXContWindow::EvOcAmbientGetDisplayAsDefault(bool* disp)
{
  return false;
}

//
//
//
bool
TOCXContWindow::EvOcAmbientGetSupportsMnemonics(bool* support)
{
  return false;
}

//
//
//
bool
TOCXContWindow::EvOcAmbientGetDisplayName(TString** name)
{
  return false;
}

//
//
//
bool
TOCXContWindow::EvOcAmbientGetScaleUnits(TString** units)
{
  return false;
}

//
//
//
bool
TOCXContWindow::EvOcAmbientGetFont(IDispatch** font)
{
  return false;
}

//
//
//
bool
TOCXContWindow::EvOcAmbientSetBackColor(long rgb)
{
  return false;
}

//
//
//
bool
TOCXContWindow::EvOcAmbientSetForeColor(long rgb)
{
  return false;
}

//
//
//
bool
TOCXContWindow::EvOcAmbientSetLocaleID(long locale)
{
  return false;
}

//
//
//
bool
TOCXContWindow::EvOcAmbientSetTextAlign(short align)
{
  return false;
}

//
//
//
bool
TOCXContWindow::EvOcAmbientSetMessageReflect(bool msgReflect)
{
  return false;
}

//
//
//
bool
TOCXContWindow::EvOcAmbientSetUserMode(bool mode)
{
  return false;
}

//
//
//
bool
TOCXContWindow::EvOcAmbientSetUIDead(bool dead)
{
  return false;
}

//
//
//
bool
TOCXContWindow::EvOcAmbientSetShowGrabHandles(bool show)
{
  return false;
}

//
//
//
bool
TOCXContWindow::EvOcAmbientSetShowHatching(bool show)
{
  return false;
}

//
//
//
bool
TOCXContWindow::EvOcAmbientSetDisplayAsDefault(bool disp)
{
  return false;
}

//
//
//
bool
TOCXContWindow::EvOcAmbientSetSupportsMnemonics(bool support)
{
  return false;
}

//
//
//
bool
TOCXContWindow::EvOcAmbientSetDisplayName(TString* name)
{
  return false;
}

//
//
//
bool
TOCXContWindow::EvOcAmbientSetScaleUnits(TString* units)
{
  return false;
}

//
//
//
bool
TOCXContWindow::EvOcAmbientSetFont(IDispatch* font)
{
  return false;
}

//
//
//
bool
TOCXContWindow::EvOcCtrlClick(TCtrlEvent* pev)
{
  return false;
}

//
//
//
bool
TOCXContWindow::EvOcCtrlDblClick(TCtrlEvent* pev)
{
  return false;
}

//
//
//
bool
TOCXContWindow::EvOcCtrlMouseDown(TCtrlMouseEvent* pev)
{
  return false;
}

//
//
//
bool
TOCXContWindow::EvOcCtrlMouseMove(TCtrlMouseEvent* pev)
{
  return false;
}

//
//
//
bool
TOCXContWindow::EvOcCtrlMouseUp(TCtrlMouseEvent* pev)
{
  return false;
}

//
//
//
bool
TOCXContWindow::EvOcCtrlKeyDown(TCtrlKeyEvent* pev)
{
  return false;
}

//
//
//
bool
TOCXContWindow::EvOcCtrlKeyUp(TCtrlKeyEvent* pev)
{
  return false;
}

//
//
//
bool
TOCXContWindow::EvOcCtrlErrorEvent(TCtrlErrorEvent* pev)
{
  return false;
}

//
//
//
bool
TOCXContWindow::EvOcCtrlFocus(TCtrlFocusEvent* pev)
{
  return false;
}

//
//
//
bool
TOCXContWindow::EvOcCtrlPropertyChange(TCtrlPropertyEvent* pev)
{
  return false;
}

//
//
//
bool
TOCXContWindow::EvOcCtrlPropertyRequestEdit(TCtrlPropertyEvent* pev)
{
  return false;
}

//
//
//
bool
TOCXContWindow::EvOcCtrlCustomEvent(TCtrlCustomEvent* pev)
{
  return false;
}


