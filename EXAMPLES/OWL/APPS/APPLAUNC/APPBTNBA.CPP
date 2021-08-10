//----------------------------------------------------------------------------
// ObjectWindows
// Copyright (c) 1993, 1995 by Borland International, All Rights Reserved
//----------------------------------------------------------------------------
#include <owl/pch.h>
#include <owl/applicat.h>
#include <math.h>
#include "appbtnba.h"
#include "applaunc.rh"

DEFINE_RESPONSE_TABLE1(TAppButtonBar, TToolBox)
  EV_WM_RBUTTONDOWN,
  EV_WM_LBUTTONUP,
  EV_WM_LBUTTONDOWN,
  EV_WM_MOUSEMOVE,
END_RESPONSE_TABLE;

const int TAppButtonBar::AppButtonIdBase = 500;

//
//
//
void
TAppButtonBar::SetupWindow()
{
  TToolBox::SetupWindow();
  DragState = 0;
  OrigCursor = 0;
  DragCursor = ::LoadCursor(GetModule()->GetInstance(),
                            MAKEINTRESOURCE(IDC_DRAG_BUTTON));
  CM_PROPERTIES = ::RegisterWindowMessage("CM_PROPERTIES");
  CM_BUTTON_PRESSED = ::RegisterWindowMessage("CM_BUTTON_PRESSED");
  CM_BUTTON_DRAG = ::RegisterWindowMessage("CM_BUTTON_DRAG");

}

//
// MoveButton(). Move a button, specified by 'srcLoc', to another location,
// specified by 'destLoc'.  The button to be 'moved' is removed from the
// button bar and then a new one (with same characteristics) is re-inserted into
// the proper place.  Assumes that all the buttons will be re-ided after call.
//
void
TAppButtonBar::MoveButton(int srcLoc, int destLoc, const string& iconPath )
{
  TAppButton* toMove = ButtonWithId(IdFromLoc(srcLoc));
  TAppButton* toInsertBefore = ButtonWithId(IdFromLoc(destLoc));
  TAppButton* newButton = new TAppButton(GetApplication()->GetInstance(),
                                         iconPath, IdFromLoc(srcLoc));

  if (toInsertBefore)
    Insert(*newButton, Before, toInsertBefore);
  else
    Insert(*newButton, Before, GadgetWithId(IDB_APPREMOVER));
  delete Remove(*toMove);
}

//
// ChangeOrientation(). Change layout of application buttons (vertical or
// horizontal).
//
void
TAppButtonBar::ChangeOrientation(TTileDirection direction)
{
  SetDirection(direction);
}

//
// DestroyButton(). Delete a button given by location.
//
void
TAppButtonBar::DestroyButton(int loc)
{
  TAppButton* b = ButtonWithId(IdFromLoc(loc));
  Remove(*b);
  delete b;
}

//
// Return button with given 'real' id.
//
TAppButton*
TAppButtonBar::ButtonWithId(int id)
{
  TAppButton* b = TYPESAFE_DOWNCAST(FirstGadget(), TAppButton);
  while (b) {
    if (b->RealId == id)
      return b;
    else
      b = TYPESAFE_DOWNCAST(NextGadget(*b), TAppButton);
  }
  return 0;
}

//
// Flush().  Remove all buttons from button bar.
//
void
TAppButtonBar::Flush(int del)
{
  TGadget* g = FirstGadget();
  while (g) {
    Remove(*g);
    if (del)
      delete g;
    g = FirstGadget();
  }
}

//
// EvRButtonDown(). Send message (CM_PROPERTIES) to main window so
// properties dialog can be displayed for this button.
//
void
TAppButtonBar::EvRButtonDown(UINT /*modKeys*/, TPoint& point)
{
  TAppButton* temp;
  if ((temp = TYPESAFE_DOWNCAST(GadgetFromPoint(point), TAppButton)) != 0)
    Parent->PostMessage(CM_PROPERTIES, temp->RealId, 0);
}

//
// EvLButtonUp(). If a drag was in program send a message, CM_BUTTON_DRAG,
// to main window.  If button was simple pressed send message,
// CM_BUTTON_PRESSED, to main window so selected app can be run.
//
void
TAppButtonBar::EvLButtonUp(UINT modKeys, TPoint& point)
{
  TAppButton* temp = TYPESAFE_DOWNCAST(GadgetFromPoint(point), TAppButton);

  if (DragState == 2) {
    TPoint  screenPoint(point);

    ClientToScreen(screenPoint);
    ResetOrigCursor();
    if ((temp && temp->RealId != DragButtonId) || !temp &&
        Parent->GetWindowRect().Contains(screenPoint))
      Parent->PostMessage(CM_BUTTON_DRAG, DragButtonId,
                          MAKELPARAM(point.x, point.y));
  } else {
    if (temp != 0)
      Parent->PostMessage(CM_BUTTON_PRESSED, temp->RealId, LPARAM(HWindow));
  }
  DragState = 0;
  TToolBox::EvLButtonUp(modKeys, point);
}

//
// EvLButtonDown(). Indicate that a possible button drag is in progress.
//
void
TAppButtonBar::EvLButtonDown(UINT modKeys, TPoint& point)
{
  TAppButton* temp = TYPESAFE_DOWNCAST(GadgetFromPoint(point), TAppButton);
  if (temp && temp->GetId() != IDB_APPREMOVER) {
    DragButtonId = temp->RealId;
    DragState = 1;
    StartDragPoint = point;
  }
  TToolBox::EvLButtonDown(modKeys, point);
}

//
// EvMouseMove().  If dragging, set the cursor.  A check is made
// to see if we have moved far enough to regard the mouse move as a drag.
//
void
TAppButtonBar::EvMouseMove(UINT modKeys, TPoint& point)
{
  if (DragState == 1 && (abs(point.x - StartDragPoint.x) > 5 ||
                         abs(point.y - StartDragPoint.y) > 5)) {
    DragState = 2;
    SetDragCursor();
  }
  TToolBox::EvMouseMove(modKeys, point);
}

//
// ReDraw(). Begin a layout session. Then move window so everthing gets
// drawn again.
//
void
TAppButtonBar::ReDraw()
{
  LayoutSession();
}

//
// SetDragCursor().  Change cursor to button drag cursor.
//
void
TAppButtonBar::SetDragCursor()
{
  if (!OrigCursor)
    OrigCursor = ::GetCursor();
  ::SetCursor(DragCursor);
}

//
// ResetOrigCursor().  Change cursor back to whatever is was before.
//
void
TAppButtonBar::ResetOrigCursor()
{
  if (OrigCursor)
    ::SetCursor(OrigCursor);
  OrigCursor = 0;
}
