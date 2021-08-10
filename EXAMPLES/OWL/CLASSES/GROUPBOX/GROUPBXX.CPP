//----------------------------------------------------------------------------
// ObjectWindows
// Copyright (c) 1991, 1995 by Borland International, All Rights Reserved
//----------------------------------------------------------------------------
#include <owl/pch.h>
#include <owl/applicat.h>
#include <owl/radiobut.h>
#include <owl/groupbox.h>
#include <owl/static.h>
#include <owl/framewin.h>
#include <cstring.h>
#include <stdio.h>
#include <string.h>

const int ID_BCCGROUP     = 100;
const int ID_BCC1         = 101;
const int ID_BCC5         = 102;
const int ID_BCC10        = 103;
const int ID_BCCX         = 104;
const int ID_CPPGROUP     = 110;
const int ID_CPP1         = 111;
const int ID_CPP5         = 112;
const int ID_CPP10        = 113;
const int ID_CPPX         = 114;
const int ID_PLACEBUTTON  = 131;
const int ID_CANCELBUTTON = 132;


//
// class TOrderGroupBox
// ~~~~~ ~~~~~~~~~~~~~~
class TOrderGroupBox : public TGroupBox {
  public:
    TOrderGroupBox(TWindow*        parent,
                   int             id,
                   const char far* text,
                   int X, int Y, int W, int H,
                   TModule*        module = 0)
    :
      TGroupBox(parent, id, text, X, Y, W, H, module)
    {}

    void SelectionChanged(int controlId);

    string  itemsOrderedStr;    // stuff ordered.
};

//
// SelectionChanged(). Called by check boxes and radio buttons (or your own
// control) when checked/unchecked.
//
void
TOrderGroupBox::SelectionChanged(int controlId)
{
  switch (controlId) {
    case ID_BCC1 :
      itemsOrderedStr = "1 BCC compiler";
      break;
    case ID_BCC5 :
      itemsOrderedStr = "5 BCC compilers";
      break;
    case ID_BCC10 :
      itemsOrderedStr = "10 BCC compilers";
      break;
    case ID_BCCX :
      itemsOrderedStr = "X BCC compilers";
      break;
    case ID_CPP1 :
      itemsOrderedStr = "1 Professional Pack";
      break;
    case ID_CPP5 :
      itemsOrderedStr = "5 Professional Packs";
      break;
    case ID_CPP10 :
      itemsOrderedStr = "10 Professional Packs";
      break;
    case ID_CPPX :
      itemsOrderedStr = "X Professional Packs";
      break;
  };
}

//
// class TOrderWindow
// ~~~~~ ~~~~~~~~~~~~
class TOrderWindow : public TWindow {
  public:
    TOrderWindow();
    void PlaceOrder();
    void CancelOrder();

    TOrderGroupBox* BCCGroup;
    TOrderGroupBox* CPPGroup;

  DECLARE_RESPONSE_TABLE(TOrderWindow);
};

DEFINE_RESPONSE_TABLE1(TOrderWindow, TWindow)
  EV_COMMAND(ID_PLACEBUTTON, PlaceOrder),
  EV_COMMAND(ID_CANCELBUTTON, CancelOrder),
END_RESPONSE_TABLE;

TOrderWindow::TOrderWindow()
:
  TWindow(0, 0, 0)
{
  Attr.X = 20;
  Attr.Y = 5;
  Attr.W = 380;
  Attr.H = 260;
  new TStatic(this, -1, "Borland C++ now includes an extensive Windows",
    20, 10, 380, 15, 55);
  new TStatic(this, -1, "class library and a complete toolkit for Windows",
    20, 27, 380, 15, 45);
  new TStatic(this, -1, "resource editing.", 20, 44, 380, 15, 55);
  new TStatic(this, -1, "              How many copies would you like?",
    10, 61, 380, 15, 35);

  TRadioButton* radio;
  BCCGroup = new TOrderGroupBox(this, ID_BCCGROUP, "BCC Compiler",
    20, 80, 150, 105);
  radio = new TRadioButton(this, ID_BCC1, "1", 30, 100, 40, 17, BCCGroup);
  radio->Attr.Style |= WS_TABSTOP;
  new TRadioButton(this, ID_BCC5, "5", 30, 120, 40, 17, BCCGroup);
  new TRadioButton(this, ID_BCC10, "10", 30, 140, 40, 17, BCCGroup);
  new TRadioButton(this, ID_BCCX, "X", 30, 160, 40, 17, BCCGroup);
  CPPGroup = new TOrderGroupBox(this, ID_CPPGROUP, "Professional Packs",
    189, 80, 150, 105);
  radio = new TRadioButton(this, ID_CPP1, "1", 200, 100, 40, 17, CPPGroup);
  radio->Attr.Style |= WS_TABSTOP;
  new TRadioButton(this, ID_CPP5, "5", 200, 120, 40, 17, CPPGroup);
  new TRadioButton(this, ID_CPP10, "10", 200, 140, 40, 17, CPPGroup);
  new TRadioButton(this, ID_CPPX, "X", 200, 160, 40, 17, CPPGroup);
  new TButton(this, ID_PLACEBUTTON, "PLACE ORDER", 20, 195, 157, 25, FALSE);
  new TButton(this, ID_CANCELBUTTON, "CANCEL ORDER", 181, 195, 157, 25, FALSE);
}

//
// PlaceOrder(). Display order.  Display header and items ordered, from group
// box.
//
void
TOrderWindow::PlaceOrder()
{
  string msg;
  string zero("0");   // if nothing ordered.

  msg += "BCC: " + (BCCGroup->itemsOrderedStr.is_null() ? zero :
                    BCCGroup->itemsOrderedStr) + "\n";
  msg += "Professional: " + (CPPGroup->itemsOrderedStr.is_null() ? zero :
                             CPPGroup->itemsOrderedStr) + "\n";
  MessageBox(msg.c_str(), "Order", MB_OK);
}

void
TOrderWindow::CancelOrder()
{
  MessageBox("Order Cancelled", "Order", MB_OK);
}


//
// class TOrderApp
// ~~~~~ ~~~~~~~~~
class TOrderApp : public TApplication {
  public:
    TOrderApp() : TApplication() {}
    void InitMainWindow() {
      TFrameWindow* frame = new TFrameWindow(0, "BCC Order Form", new TOrderWindow);
      frame->EnableKBHandler();
      SetMainWindow(frame);
    }
};

int
OwlMain(int /*argc*/, char* /*argv*/ [])
{
  TOrderApp app;
  return app.Run();
}
