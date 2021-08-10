//----------------------------------------------------------------------------
// ObjectWindows
// (C) Copyright 1991, 1994 by Borland International, All Rights Reserved
//
//   Definition of TDialog class and TDialogAttr struct
//----------------------------------------------------------------------------
#if !defined(OWL_DIALOG_H)
#define OWL_DIALOG_H

#if !defined(OWL_WINDOW_H)
# include <owl/window.h>
#endif

//
//  struct TDialogAttr
//  ------ -----------
//
//  TDialog creation attributes
//
struct TDialogAttr {
  char far* Name;
  uint32    Param;
};

//
//  class TDialog
//  ----- -------
//
class _OWLCLASS TDialog : virtual public TWindow {
  public:
    TDialogAttr  Attr;
    bool         IsModal;

    TDialog(TWindow* parent, TResId resId, TModule* module = 0);

   ~TDialog();

    //
    // override this to process messages within the dialog function
    // Return true if message handled, false if not.
    //
    // default behavior is to call EvInitDialog & EvSetFont
    //
    virtual bool    DialogFunction(uint message, WPARAM wParam, LPARAM lParam);

    //
    // virtual handler for WM_INITDIALOG message, called from DialogFunction()
    //
    // default behavior is to call PerformDlgInit & SetupWindow() and return 
    // true
    //
    virtual bool    EvInitDialog(HWND hWndFocus);

    //
    // Initialize dialog controls with contents of RT_DLGINIT
    //
    bool            PerformDlgInit();

    //
    // Handler for WM_SETFONT, is dispatched from DialogFunction() once
    // during dialog creation, subsequently as normal.
    //
    void            EvSetFont(HFONT hFont, bool redraw);

    //
    // create a modeless dialog box, and perform actual create call
    //
    virtual bool    Create();
    virtual HWND    DoCreate();

    //
    // create a modal dialog box, and perform actual modal call
    //
    virtual int     Execute();
    virtual int     DoExecute();

    //
    // override virtual functions defined by class TWindow
    //
    bool            PreProcessMsg(MSG& msg);
    void            CloseWindow(int retValue = IDCANCEL);
    void            Destroy(int retValue = IDCANCEL);

    void            SetCaption(const char far* title);

    //
    // returns the handle of the dialog's control with the passed Id
    // Obsolete- use TWindow::GetDlgItem(Id)
    //
    HWND            GetItemHandle(int childId) {return GetDlgItem(childId); }

    //
    // sends the passed message to the dialog's control which has id DlgItemId
    // Obsolete- use TWindow::SendDlgItemMessage()
    //
    uint32 SendDlgItemMsg(int childId, uint16 msg, uint16 wParam, uint32 lParam);

    uint            GetDefaultId() const;
    void            SetDefaultId(uint id) {HandleMessage(DM_SETDEFID, id, 0);}

    //
    // message response functions
    //
    void            EvClose();
    void            EvPaint();
    HBRUSH          EvCtlColor(HDC, HWND hWndChild, uint ctlType);

    //
    // child notifications
    //
    void            CmOk();      // IDOK
    void            CmCancel();  // IDCANCEL

  protected:
    //
    // override virtual functions defined by class TWindow
    //
    void            SetupWindow();
    char far*       GetClassName();
    void            GetWindowClass(WNDCLASS& wndClass);

  private:
    //
    // hidden to prevent accidental copying or assignment
    //
    TDialog(const TDialog&);
    TDialog& operator =(const TDialog&);

  DECLARE_RESPONSE_TABLE(TDialog);
  DECLARE_STREAMABLE(_OWLCLASS, TDialog, 1);
};


inline uint32
TDialog::SendDlgItemMsg(int ChildId, uint16 Msg, uint16 WParam, uint32 LParam) {
  return SendDlgItemMessage(ChildId, Msg, WParam, LParam);
}

inline uint
TDialog::GetDefaultId() const {
  return LOWORD(CONST_CAST(TDialog*,this)->HandleMessage(DM_GETDEFID));
}

#endif  // OWL_DIALOG_H
