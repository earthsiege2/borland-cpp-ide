//----------------------------------------------------------------------------
// ObjectWindows - (C) Copyright 1991, 1993 by Borland International
//----------------------------------------------------------------------------
#ifndef PVALUE_H
#define PVALUE_H

#ifndef OWL_DIALOG_H
  #include <owl/dialog.h>
#endif

#define PV_KILLFOCUS     (WM_USER + 100)

class TPieceValueDialog : public TDialog {
  public:
    TPieceValueDialog(TWindow* parent, const char* name);
    void SetupWindow();
    LRESULT EvPvKillFocus(WPARAM, LPARAM);
    void CmOk();
    void EvHScroll(UINT scrollCode, UINT thumbPos, HWND hWndCtl);
    LRESULT EvCommand(UINT, HWND, UINT);
    void CmDefault();

  private:
    int  Values[5];
    void PVSetFocus(HWND);
    BOOL GetColorValue(WORD);
    
  DECLARE_RESPONSE_TABLE(TPieceValueDialog);
};

#endif  // __PVALUE_H
