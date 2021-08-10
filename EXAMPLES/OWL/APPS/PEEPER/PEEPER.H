//----------------------------------------------------------------------------
// ObjectWindows
// Copyright (c) 1993, 1995 by Borland International, All Rights Reserved
//
//   Peeper is a program that allows the user to select some windows and
//   perform one or more actions on those windows.  Actions include:
//      . Changing the window text (caption).
//      . Sending messages.
//
//   The windows that are selected are put into a list which can be cleared
//   at any time to start over.
//
//   To choose a window click on the 'Peep!' button and when the mouse if over
//   a window that you want to choose, click the left mouse button.  To stop
//   'peeping' click the right mouse button.  You can't peep Peeper.
//----------------------------------------------------------------------------
#if !defined(PEEPER_H)
#define PEEPER_H

#include <owl/applicat.h>
#include <owl/dialog.h>
#include <classlib/vectimp.h>
#include "peeper.rh"

//
// Global functions used with ForEach():
//
void SendWMSetText(HWND& hWnd, void* p);
void SendSysMessage(HWND& hWnd, void* p);
void SendWMMessage(HWND& hWnd, void* p);

//////////////////////////////////////////////////////////////////////

//
// Handles the 'peeping' process by capturing, tracking and releasing
// the mouse.
//
class TClientWindow : public TWindow {
  public:
    TClientWindow() : TWindow(0, "") {}

  protected:
    void  DisplayWinInfo();
    void  EvLButtonDown(UINT mod_keys, TPoint& point);
    void  EvRButtonDown(UINT mod_keys, TPoint& point);

  DECLARE_RESPONSE_TABLE(TClientWindow);
};

//////////////////////////////////////////////////////////////////////

// Transfer buffer for the messages dialog.
struct MessagesTB {
   MessagesTB()
   {
      MaxCB = MinCB = PaintCB = RestoreCB = PasteCB = CloseCB = 0;
   }

   uint16  MaxCB, MinCB, PaintCB, RestoreCB, PasteCB, CloseCB;
};

//
// Dialog that contains checkboxs that reprsent the messages the user wants
// to send to the selected windows.
//
class TMessagesDialog : public TDialog {
  public:
    TMessagesDialog(TWindow* parent, MessagesTB* mtb)
      : TDialog(parent, IDD_MESSAGES)
    {
      MaximizeCB = new TCheckBox(this, IDC_MAXIMIZE);
      MinimizeCB = new TCheckBox(this, IDC_MINIMIZE);
      PaintCB = new TCheckBox(this, IDC_PAINT);
      RestoreCB = new TCheckBox(this, IDC_RESTORE);
      PasteCB = new TCheckBox(this, IDC_PASTE);
      CloseCB = new TCheckBox(this, IDC_CLOSE);
      SetTransferBuffer(mtb);
    }

  private:
    TCheckBox*  MaximizeCB;
    TCheckBox*  MinimizeCB;
    TCheckBox*  PaintCB;
    TCheckBox*  RestoreCB;
    TCheckBox*  PasteCB;
    TCheckBox*  CloseCB;
};

//////////////////////////////////////////////////////////////////////

//
// Peeper application. Handles most of the messages.
//
class TPeeper : public TApplication {
  public:
    TPeeper();
   ~TPeeper();

  protected:
    void  InitMainWindow();

  private:
    TWindow*           Client;
    TStatic*           SelWinText;
    TListBox*          SelectedWindows;
    TControlBar*       Actions;
    TMessageBar*       StatusLine;
    TCVectorImp<HWND>* WindowList;

    void  CmPeeping();
    void  CmChangeCaption();
    void  CmClearWindowList();
    void  CmSendMessage();
    void  CmHelp();

  friend class TClientWindow;
  DECLARE_RESPONSE_TABLE(TPeeper);
};

#endif
