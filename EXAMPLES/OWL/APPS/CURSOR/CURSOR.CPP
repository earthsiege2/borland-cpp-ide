//----------------------------------------------------------------------------
// ObjectWindows
// Copyright (c) 1993, 1995 by Borland International, All Rights Reserved
//----------------------------------------------------------------------------
#include <owl/pch.h>
#include <owl/applicat.h>
#include <owl/dialog.h>
#include <owl/framewin.h>
#include <winsys/system.h>
#include <stdlib.h>
#include "cursor.h"

#if BI_PLAT_WIN32
# error This example is 16-bit only.
#endif

//
//
//
class TCursorDlg : public TDialog {
  public:
    TCursorDlg(TWindow* parent, const char far* name);

    void   UpdateDialog();
    bool   ShouldUpdate() {return Update;}

  protected:
    void   SetupWindow();
    void   CloseWindow(int);

    void   CmOk() {}     // Override the meaning of OK & Cancel to do nothing.
    void   CmCancel() {}

  private:
    bool    Update;

  DECLARE_RESPONSE_TABLE(TCursorDlg);
};

DEFINE_RESPONSE_TABLE1(TCursorDlg, TDialog)
  EV_COMMAND(IDOK, CmOk),
  EV_COMMAND(IDCANCEL, CmCancel),
END_RESPONSE_TABLE;

//
//
//
TCursorDlg::TCursorDlg(TWindow* parent, const char far* name)
:
  TWindow(parent),
  TDialog(parent, name),
  Update(FALSE)
{
  EnableAutoCreate();
}

//
//
//
void
TCursorDlg::SetupWindow()
{
  TDialog::SetupWindow();
  Update = TRUE;
}

//
//
//
void
TCursorDlg::CloseWindow(int retVal)
{
  Update = FALSE;       // disable updating
  TDialog::CloseWindow(retVal);
}

//
//
//
void
TCursorDlg::UpdateDialog()
{
  TPoint Point;
  static TPoint prevPoint(-1,-1);
  static HWND hPrevWnd = (HWND)-1;
  static HWND hPrevParent = (HWND)-1;
  HWND hWndFromPt;
  HWND hParent = hPrevParent;
  HWND hFocus;
  static HWND hPrevFocus = (HWND)-1;
  static TRect Rect;
  static TRect prevRect(-1, -1, -1, -1);
  char buffer[26];

  if (Update) {
    GetCursorPos(Point);

    // If the cursor position has changed...
    //
    if (Point != prevPoint) {
      prevPoint = Point;
      SetDlgItemText(IDD_SX, ltoa(Point.x, buffer, 10));
      SetDlgItemText(IDD_SY, ltoa(Point.y, buffer, 10));
      if ((hWndFromPt = ::WindowFromPoint(Point)) != 0) {
        // Set the x and y coordinates in terms
        // of the client area of the underlying window.
        //
        ::ScreenToClient(hWndFromPt, &Point);
        SetDlgItemText(IDD_WX, ltoa(Point.x, buffer, 10));
        SetDlgItemText(IDD_WY, ltoa(Point.y, buffer, 10));

        if ((hParent = ::GetParent(hWndFromPt)) != 0) {
          // Set the x and y coordinates in terms of the client area of
          // the parent of the window.
          //
          Point = prevPoint;
          ::ScreenToClient(hParent, &Point);
          SetDlgItemText(IDD_PX, ltoa(Point.x, buffer, 10));
          SetDlgItemText(IDD_PY, ltoa(Point.y, buffer, 10));

        }
        else {
          // If the window has no parent,
          // leave the x and y fields blank.
          //
          SetDlgItemText(IDD_PX, "");
          SetDlgItemText(IDD_PY, "");
        }

      // If there is no window at the current point,
      // the x and y coordinates should be blank
      // in the dialog box.
      //
      }
      else {
        SetDlgItemText(IDD_WX, "");
        SetDlgItemText(IDD_WY, "");
      }

      // Update the display of the handle of the
      // underlying window if necessary.
      //
      if (hWndFromPt != hPrevWnd)
        SetDlgItemText(IDD_HW, itoa((UINT)hWndFromPt, buffer, 16));

      // If the parent window has changed,
      // update the display of its handle.
      //
      if (hParent != hPrevParent) {
        if (!hWndFromPt || !hParent)
          SetDlgItemText(IDD_HP, "");
        else
          SetDlgItemText(IDD_HP, itoa((UINT)hParent, buffer, 16));

      }
      else {
        // If there is no underlying window,
        // do not display a handle for a parent.
        //
        if (!hWndFromPt)
          SetDlgItemText(IDD_HP, "");
      }
      hPrevWnd = hWndFromPt;
      hPrevParent = hParent;
    }

    // Update the focus display fields if necessary.
    //
    hFocus = ::GetFocus();
    if (!hFocus) {
      if (hFocus != hPrevFocus) {
        SetDlgItemText(IDD_HF, "");
        SetDlgItemText(IDD_LEFT, "");
        SetDlgItemText(IDD_TOP, "");
        SetDlgItemText(IDD_RIGHT, "");
        SetDlgItemText(IDD_BOTTOM, "");
      }
    }
    else {
      if (hFocus != hPrevFocus) {
        SetDlgItemText(IDD_HF, itoa((UINT)hFocus, buffer, 16));
      }
      ::GetWindowRect(hFocus, &Rect);
      if (Rect != prevRect) {
        prevRect = Rect;
        SetDlgItemText(IDD_LEFT, ltoa(Rect.left, buffer, 10));
        SetDlgItemText(IDD_TOP, ltoa(Rect.top, buffer, 10));
        SetDlgItemText(IDD_RIGHT, ltoa(Rect.right, buffer, 10));
        SetDlgItemText(IDD_BOTTOM, ltoa(Rect.bottom, buffer, 10));
      }
    }
    hPrevFocus = hFocus;
  }
}

//----------------------------------------------------------------------------

//
//
//
class TCursorApplication : public TApplication {
  public:
    TCursorApplication() : TApplication("Cursor Location App") {}
    void InitMainWindow() {
      EnableCtl3d();
      Dialog = new TCursorDlg(0, "CursorDlg");
      MainWindow = new TFrameWindow(0, "Cursor Location", Dialog, TRUE);
      MainWindow->SetIcon(this, "CursorDlg");
      MainWindow->Attr.Style &= ~(WS_MAXIMIZEBOX|WS_THICKFRAME);
    }

    bool IdleAction(long) {
      if (Dialog && Dialog->ShouldUpdate())
        Dialog->UpdateDialog();
      return true;                // Keep calling us
    }

  private:
    TCursorDlg* Dialog;
};

//
//
//
int
OwlMain(int /*argc*/, char* /*argv*/ [])
{
#if defined(BI_PLAT_WIN32)
  if (TSystem::GetPlatformId() == TSystem::Win32NT) {
    ::MessageBox(0, "This is not a Win NT Example", "OWL Examples", MB_OK);
    return 0;
  }
#endif
  return TCursorApplication().Run();
}
