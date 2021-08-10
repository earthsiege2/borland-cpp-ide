//----------------------------------------------------------------------------
// ObjectWindows - (C) Copyright 1991, 1993 by Borland International
//   include\owl\dialog.h
//   Definition of TDialog class and TDialogAttr struct
//----------------------------------------------------------------------------
#if !defined(__OWL_DIALOG_H)
#define __OWL_DIALOG_H

#if !defined(__OWL_WINDOW_H)
  #include <owl\window.h>
#endif

//
//  struct TDialogAttr
//  ------ -----------
//
//  TDialog creation attributes
//
struct TDialogAttr {
  char far* Name;
  DWORD     Param;
};

//
//  class TDialog
//  ----- -------
//
class _OWLCLASS TDialog : virtual public TWindow {
  public:
    TDialogAttr  Attr;
    BOOL         IsModal;

    TDialog(TWindow* parent, TResId resId, TModule* module = 0);

   ~TDialog();

    //
    // override this to process messages within the dialog function
    // Return TRUE if message handled, FALSE if not.
    //
    // default behavior is to call EvInitDialog & EvSetFont
    //
    virtual BOOL    DialogFunction(UINT message, WPARAM wParam, LPARAM lParam);

    //
    // override this to process WM_INITDIALOG message
    //
    // default behavior is to call PerformDlgInit & SetupWindow() and return 
    // TRUE
    //
    virtual BOOL    EvInitDialog(HWND hWndFocus);

    //
    // Initialize dialog controls with contents of RT_DLGINIT
    //
    BOOL            PerformDlgInit();

    //
    // override this to process WM_SETFONT
    //
    virtual void    EvSetFont(HFONT);

    //
    // create a modeless dialog box, and perform actual create call
    //
    virtual BOOL    Create();
    virtual HWND    DoCreate();

    //
    // create a modal dialog box, and perform actual modal call
    //
    virtual int     Execute();
    virtual int     DoExecute();

    //
    // override virtual functions defined by class TWindow
    //
    BOOL            PreProcessMsg(MSG& msg);
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
    DWORD SendDlgItemMsg(int ChildId, WORD Msg, WORD WParam, DWORD LParam);

    UINT            GetDefaultId() const;
    void            SetDefaultId(UINT Id) {HandleMessage(DM_SETDEFID, Id, 0);}

    //
    // message response functions
    //
    void            EvClose();
    void            EvPaint();
    HBRUSH          EvCtlColor(HDC, HWND hWndChild, UINT ctlType);

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


inline DWORD
TDialog::SendDlgItemMsg(int ChildId, WORD Msg, WORD WParam, DWORD LParam) {
  return SendDlgItemMessage(ChildId, Msg, WParam, LParam);
}

inline UINT
TDialog::GetDefaultId() const {
  return LOWORD(CONST_CAST(TDialog*,this)->HandleMessage(DM_GETDEFID));
}

#endif  // __OWL_DIALOG_H
