//----------------------------------------------------------------------------
// ObjectWindows
// Copyright (c) 1995, 1996 by Borland International, All Rights Reserved
//
// $Revision:   10.0  $
//
// Sample illustrating a container with an OCX as client window
//----------------------------------------------------------------------------
#if !defined(_OCXCONT_H)
#define _OCXCONT_H

#if !defined(OWL_OLEWINDOW_H)
# include <owl/olewindo.h>
#endif

// Application's main client window
//
class TOCXContWindow : public TOleWindow {

  public:
    TOCXContWindow(TWindow* parent = 0);

    // Override virtuals of TWindow
    //
    void  SetupWindow();

    // Override default handlers of Property/Event notifications/request
    //

    // Ambient property specific messages
    //
    bool      EvOcAmbientGetBackColor(long* rgb);
    bool      EvOcAmbientGetForeColor(long* rgb);
    bool      EvOcAmbientGetLocaleID(long* locale);
    bool      EvOcAmbientGetTextAlign(short* align);
    bool      EvOcAmbientGetMessageReflect(bool* msgReflect);
    bool      EvOcAmbientGetUserMode(bool* mode);
    bool      EvOcAmbientGetUIDead(bool* dead);
    bool      EvOcAmbientGetShowGrabHandles(bool* show);
    bool      EvOcAmbientGetShowHatching(bool* show);
    bool      EvOcAmbientGetDisplayAsDefault(bool* disp);
    bool      EvOcAmbientGetSupportsMnemonics(bool* support);
    bool      EvOcAmbientGetDisplayName(TString** name);
    bool      EvOcAmbientGetScaleUnits(TString** units);
    bool      EvOcAmbientGetFont(IDispatch** font);

    bool      EvOcAmbientSetBackColor(long rgb);
    bool      EvOcAmbientSetForeColor(long rgb);
    bool      EvOcAmbientSetLocaleID(long locale);
    bool      EvOcAmbientSetTextAlign(short align);
    bool      EvOcAmbientSetMessageReflect(bool msgReflect);
    bool      EvOcAmbientSetUserMode(bool mode);
    bool      EvOcAmbientSetUIDead(bool dead);
    bool      EvOcAmbientSetShowGrabHandles(bool show);
    bool      EvOcAmbientSetShowHatching(bool show);
    bool      EvOcAmbientSetDisplayAsDefault(bool disp);
    bool      EvOcAmbientSetSupportsMnemonics(bool support);
    bool      EvOcAmbientSetDisplayName(TString* name);
    bool      EvOcAmbientSetScaleUnits(TString* units);
    bool      EvOcAmbientSetFont(IDispatch* font);

    // Ctrl event specific messages
    //
    bool      EvOcCtrlClick(TCtrlEvent* pev);
    bool      EvOcCtrlDblClick(TCtrlEvent* pev);
    bool      EvOcCtrlMouseDown(TCtrlMouseEvent* pev);
    bool      EvOcCtrlMouseMove(TCtrlMouseEvent* pev);
    bool      EvOcCtrlMouseUp(TCtrlMouseEvent* pev);
    bool      EvOcCtrlKeyDown(TCtrlKeyEvent* pev);
    bool      EvOcCtrlKeyUp(TCtrlKeyEvent* pev);
    bool      EvOcCtrlErrorEvent(TCtrlErrorEvent* pev);
    bool      EvOcCtrlFocus(TCtrlFocusEvent* pev);
    bool      EvOcCtrlPropertyChange(TCtrlPropertyEvent* pev);
    bool      EvOcCtrlPropertyRequestEdit(TCtrlPropertyEvent* pev);
    bool      EvOcCtrlCustomEvent(TCtrlCustomEvent* pev);

  DECLARE_RESPONSE_TABLE(TOCXContWindow);
};

#endif  // _OCXCONT_H
