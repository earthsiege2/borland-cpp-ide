//----------------------------------------------------------------------------
// ObjectWindows
// Copyright (c) 1991, 1995 by Borland International, All Rights Reserved
//----------------------------------------------------------------------------
#include <owl/pch.h>
#include <owl/applicat.h>
#include <owl/button.h>
#include <owl/framewin.h>
#include <owl/dialog.h>
#include <owl/dc.h>
#include "ownerdra.h"
#include <stdio.h>

//
//
//
class TDrawableButton : public TButton {
  public:
    TDrawableButton(TWindow* parent, int resId) : TButton(parent, resId) {}
   ~TDrawableButton() {}

    void ODADrawEntire(DRAWITEMSTRUCT far& drawInfo);
    void ODAFocus(DRAWITEMSTRUCT far& drawInfo);
    void ODASelect(DRAWITEMSTRUCT far& drawInfo);
};

//
// Function called when button needs to be drawn
//
void
TDrawableButton::ODADrawEntire(DRAWITEMSTRUCT far& drawInfo)
{
  TDC drawDC(drawInfo.hDC);
  TRect itemRect(drawInfo.rcItem.left, drawInfo.rcItem.top,
                 drawInfo.rcItem.right, drawInfo.rcItem.bottom);
  drawDC.Rectangle(itemRect);
  if (IsCurrentDefPB)
    drawDC.Rectangle(itemRect.InflatedBy(-1,-1));

  itemRect.Inflate(-4,-6);
  drawDC.DrawText("DRAWN", -1, itemRect, DT_CENTER | DT_VCENTER);
  if (drawInfo.itemState & ODS_FOCUS)
    drawDC.DrawFocusRect(itemRect);
}

//
// Function called when button gains or loses focus
//
void
TDrawableButton::ODAFocus(DRAWITEMSTRUCT far& drawInfo)
{
  TDC drawDC(drawInfo.hDC);
  TRect itemRect(drawInfo.rcItem.left+4, drawInfo.rcItem.top+6,
                 drawInfo.rcItem.right-4, drawInfo.rcItem.bottom-6);
  drawDC.DrawFocusRect(itemRect);
}

//
// Function called when button's selection status changes
//
void
TDrawableButton::ODASelect(DRAWITEMSTRUCT far& drawInfo)
{
  TDC drawDC(drawInfo.hDC);
  TRect itemRect(drawInfo.rcItem.left, drawInfo.rcItem.top,
                 drawInfo.rcItem.right, drawInfo.rcItem.bottom);
  drawDC.Rectangle(itemRect);
  if (IsCurrentDefPB)
    drawDC.Rectangle(itemRect.InflatedBy(-1,-1));

  itemRect.Inflate(-4,-6);
  if (drawInfo.itemState & ODS_SELECTED)
    drawDC.DrawText("SELECTED", -1, itemRect, DT_CENTER | DT_VCENTER);
  else
    drawDC.DrawText("DESELECTED", -1, itemRect, DT_CENTER | DT_VCENTER);
  if (drawInfo.itemState & ODS_FOCUS)
    drawDC.DrawFocusRect(itemRect);
}

//----------------------------------------------------------------------------

//
//
//
class TTestDialog : public TDialog {
  public:
    TDrawableButton* Button1;
    TDrawableButton* Button2;

    TTestDialog(TWindow* parent);
    void CmButton1() {MessageBeep(0);}

  DECLARE_RESPONSE_TABLE(TTestDialog);
};

DEFINE_RESPONSE_TABLE1(TTestDialog,TDialog)
  EV_COMMAND(ID_BUTTON1,CmButton1),
END_RESPONSE_TABLE;

//
//
//
TTestDialog::TTestDialog(TWindow* parent)
:
  TDialog(parent, "TESTDIALOG"),
  TWindow(parent)
{
  Button1 = new TDrawableButton(this, ID_BUTTON1);
  Button2 = new TDrawableButton(this, ID_BUTTON2);
}

//
//
//
class TTestWindow : public TWindow {
  public:
    TTestWindow();
    void CmTest();

  DECLARE_RESPONSE_TABLE(TTestWindow);
};

DEFINE_RESPONSE_TABLE1(TTestWindow,TWindow)
  EV_COMMAND(CM_TEST,CmTest),
END_RESPONSE_TABLE;

//
//
//
TTestWindow::TTestWindow()
:
  TWindow(0, 0, 0)
{
}

//
//
//
void
TTestWindow::CmTest()
{
  TTestDialog(this).Execute();
}

//----------------------------------------------------------------------------

//
//
//
class TTestApp : public TApplication {
  public:
    TTestApp() : TApplication() {}
    void InitMainWindow()
    {
        MainWindow = new TFrameWindow(0, "Drawable Button Tester", new TTestWindow);
        MainWindow->AssignMenu("COMMANDS");
    }
};

//
//
//
int
OwlMain(int /*argc*/, char* /*argv*/ [])
{
  return TTestApp().Run();
}
