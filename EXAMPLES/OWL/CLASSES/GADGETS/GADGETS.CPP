// ---------------------------------------------------------------------------
// Copyright (C) 1995, 1995 Borland International
// ---------------------------------------------------------------------------
#include <owl/pch.h>
#include <owl/controlb.h>
#include <owl/statusba.h>
#include <owl/menugadg.h>
#include <owl/timegadg.h>
#include <owl/modegad.h>
#include <owl/controlg.h>
#include <owl/buttonga.h>
#include <owl/edit.h>
#include "gadgets.rh"

const int EditId = 10001;
TEdit* GlobalEdit;
TMenuGadget* MenuGadget;
TTextGadget* TextGadget;

class TMyControlBar : public TControlBar {
  public:
    TMyControlBar(TWindow*        parent = 0,
                  TTileDirection  direction = Horizontal,
                  TFont*          font = new TGadgetWindowFont,
                  TModule*        module = 0)
    :
      TControlBar(parent, direction, font, module)
    {
    }

    void EnUpdate()
    {
      GetApplication()->GetMainWindow()->GetClientWindow()->Invalidate();
    }

  DECLARE_RESPONSE_TABLE(TMyControlBar);
};

DEFINE_RESPONSE_TABLE1(TMyControlBar, TControlBar)
  EV_EN_UPDATE(EditId, EnUpdate),
END_RESPONSE_TABLE;


//
// TTestWindow
// ~~~~~~~~~~~
class TTestWindow : public TWindow {
  public:
    TTestWindow() : TWindow(0, 0, 0) { Item2Active = false; }

    void CmItem1()
    {
      MenuGadget->SetText("Item 1");
      Item2Active = !Item2Active;
    }

    void CmItem2()
    {
      MenuGadget->SetText("Item 2");
      MessageBox("Thank you", "Item 2", MB_OK);
    }

    void CeItem2(TCommandEnabler& ce) { ce.Enable(Item2Active); }

    void CmItem3()
    {
      MenuGadget->SetText("This is an Item 3");
      MessageBox("Thank you", "Item 3", MB_OK);
    }

    void Paint(TDC& dc, bool, TRect&)
    {
      if (GlobalEdit) {
        int len = GlobalEdit->GetTextLen();
        if (len > 0) {
          char* buffer = new char[len+1];
          GlobalEdit->GetText(buffer, len+1);
          TRect r = GetClientRect();
          dc.DrawText(buffer, len, r, DT_SINGLELINE | DT_VCENTER | DT_CENTER);
          delete[] buffer;
        }
      }
    }

    void CmHappy()
    {
      ::MessageBeep(-1);
    }

    void EvLButtonDown(uint modKeys, TPoint& point)
    {
      SetFocus();
    }

    bool Item2Active;

  DECLARE_RESPONSE_TABLE(TTestWindow);
};

DEFINE_RESPONSE_TABLE1(TTestWindow, TWindow)
  EV_WM_LBUTTONDOWN,
  EV_COMMAND(CM_ITEM1, CmItem1),
  EV_COMMAND(CM_ITEM2, CmItem2),
  EV_COMMAND_ENABLE(CM_ITEM2, CeItem2),
  EV_COMMAND(CM_ITEM3, CmItem3),
  EV_COMMAND(ID_HAPPY, CmHappy),
END_RESPONSE_TABLE;

//
// TTestApplication
// ~~~~~~~~~~~~~~~~
class TTestApp : public TApplication {
  public:
    TTestApp() {
    }

   ~TTestApp() {
    }

    void InitMainWindow();

    TMyControlBar* ControlBar;
    TStatusBar*    StatusBar;
};

void
TTestApp::InitMainWindow()
{
  TWindow* testWindow = new TTestWindow;
  TDecoratedFrame* frame = new TDecoratedFrame(0, "Test application", testWindow, true);

  // decorations
  //
  ControlBar = new TMyControlBar(frame);
  frame->Insert(*ControlBar, TDecoratedFrame::Top);
  TMenu menu(*this, "TRACKMENU");
  MenuGadget = new TMenuGadget(menu, frame);
  ControlBar->Insert(*new TButtonGadget(ID_HAPPY, ID_HAPPY));
  ControlBar->Insert(*new TSeparatorGadget);

  ControlBar->Insert(*MenuGadget);
  ControlBar->Insert(*new TSeparatorGadget);
  ControlBar->Insert(*new TModeGadget(VK_LEFT, "Left"));

  TGadget* gadget = new TSeparatorGadget;
  gadget->WideAsPossible = true;
  ControlBar->Insert(*gadget);

  ControlBar->Insert(*new TModeGadget(VK_RIGHT, "Right"));
  ControlBar->Insert(*new TSeparatorGadget);
  TextGadget = new TTextGadget(0, TGadget::Recessed, TTextGadget::Left, 8);
  TextGadget->SetText("WWWWWWW");
  ControlBar->Insert(*TextGadget);
  TextGadget->SetEnabled(false);

  ControlBar->Insert(*new TSeparatorGadget);
  GlobalEdit = new TEdit(0, EditId, "", 0, 0, 150, 25);
  ControlBar->Insert(*new TControlGadget(*GlobalEdit));

  StatusBar = new TStatusBar(frame);
  StatusBar->Insert(*new TSeparatorGadget);
  StatusBar->Insert(*new TModeGadget(VK_UP, "Up"));
  StatusBar->Insert(*new TSeparatorGadget);
  StatusBar->Insert(*new TModeGadget(VK_DOWN, "Down"));
  StatusBar->Insert(*new TSeparatorGadget);
  StatusBar->Insert(*new TModeGadget(VK_NUMLOCK, "Num"));
  StatusBar->Insert(*new TSeparatorGadget);
  StatusBar->Insert(*new TModeGadget(VK_INSERT, "Ins"));
  StatusBar->Insert(*new TSeparatorGadget);
  StatusBar->Insert(*new TModeGadget(VK_SCROLL, "Scr"));
  StatusBar->Insert(*new TSeparatorGadget);

  StatusBar->Insert(*new TTimeGadget);
#if defined(BI_PLAT_WIN32)
  StatusBar->Insert(*new TTimeGadget(&TTimeGadget::GetSystemTime));
#endif
  frame->Insert(*StatusBar, TDecoratedFrame::Bottom);

  SetMainWindow(frame);
}

int
OwlMain(int /*argc*/, char* /*argv*/ [])
{
  int retVal = 0;
  try {
    TTestApp app;
    retVal = app.Run();
  }
  catch (...) {
    ::MessageBeep(-1);
  }
  return retVal;
}

