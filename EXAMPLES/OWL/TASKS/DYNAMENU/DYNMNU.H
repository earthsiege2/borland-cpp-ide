// ---------------------------------------------------------------------------
// ObjectWindows
// Copyright (C) 1995, 1995 by Borland International, All Rights Reserved
// ---------------------------------------------------------------------------
#if !defined(DYNMNU_H)
#define DYNMNU_H

#include <owl/applicat.h>
#include <owl/decframe.h>
#include <owl/gdiobjec.h>
#include <owl/statusba.h>
#include <owl/inputdia.h>
#include <owl/menu.h>
#include <owl/dc.h>
#include <cstring.h>
#include "dynmnu.rh"

extern char* MainMenu;

//
// class MenuTestApplication
// ~~~~~ ~~~~~~~~~~~~~~~~~~~
class TMenuTestApp : public TApplication {
  public:
    TMenuTestApp();
   ~TMenuTestApp();

    void InitMainWindow();

    TStatusBar* StatusBar;
};


//
// class TDynamicMenuAttr
// ~~~~~ ~~~~~~~~~~~~~~~~
// Information about each individual menu item
//
class TDynamicMenuAttr {
  public:
    TDynamicMenuAttr(const string itemString, const string hintText, int id);
   ~TDynamicMenuAttr();

    bool IsEnabled() const            { return Enabled; }
    void Enable(bool bEnabled)        { Enabled = bEnabled; }

    string GetItemString() const      { return ItemString; }
    string GetHintText() const        { return HintText; }
    int    GetItemId() const          { return ItemId; }

  protected:
    string ItemString;
    string HintText;
    int ItemId;
    bool Enabled;
};

//
// class TDynamicMenuDecoratedFrame
// ~~~~~ ~~~~~~~~~~~~~~~~~~~~~~~~~~
// Allow special processing for the hints on the dynamic menu items.
//
class TDynamicMenuDecoratedFrame : public TDecoratedFrame {
  public:
    TDynamicMenuDecoratedFrame(TWindow* parent, const char far* title,
      TWindow* clientWnd, bool trackMenuSelection = false,
      TModule* module = 0);

    void EvEnterIdle(uint source, HWND hWndDlg);

  DECLARE_RESPONSE_TABLE(TDynamicMenuDecoratedFrame);
};

//
// class MenuTestWindow
// ~~~~~ ~~~~~~~~~~~~~~
class TMenuTestWindow : public TWindow {
  friend class TDynamicMenuDecoratedFrame;
  public:
    TMenuTestWindow();
   ~TMenuTestWindow();

    // override TWindow's virtual functions
    //
    LRESULT EvCommand(uint id, HWND hWndCtl, uint notifyCode);
    void    EvCommandEnable(TCommandEnabler& ce);

  protected:
    void EvRButtonDown(uint modKeys, TPoint& point);

    void CmAddMenu();
    void CmDeleteMenu();
    void CeDeleteMenu(TCommandEnabler& ce);
    void CmEnableMenu();
    void CeEnableMenu(TCommandEnabler& ce);
    void CmDisableMenu();
    void CeDisableMenu(TCommandEnabler& ce);

    int GetIndex(int low, int high);

    // keep track of the dynamic menu states
    //
    TDynamicMenuAttr* DynamicMenuAttr[NUMDYNMENUITEMS];
    int NumMenuItems;

  DECLARE_RESPONSE_TABLE(TMenuTestWindow);
};

#endif // DYNMNU_H
