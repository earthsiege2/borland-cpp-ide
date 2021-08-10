//----------------------------------------------------------------------------
// ObjectWindows - (C) Copyright 1991, 1993 by Borland International
//----------------------------------------------------------------------------
#ifndef COLORS_H
#define COLORS_H

#define CL_KILLFOCUS    (WM_USER + 101)

class TColorsDialog : public TDialog {
  public:
    TColorsDialog(TWindow* parent, const char* name);
    ~TColorsDialog();

  protected:
    void SetupWindow();
    HBRUSH EvCtlColor(HDC hDC, HWND hWndChild, UINT ctlType);
    void EvVScroll(UINT scrollCode, UINT thumbPos, HWND hWndCtl);
    LRESULT EvCommand(UINT, HWND, UINT);
    void EvDrawItem(UINT ctrlID, DRAWITEMSTRUCT far& drawInfo);

    void CmOk();
    LRESULT EvKillFocus(WPARAM, LPARAM);

  private:
    enum ScrollBarColors { Red, Green, Blue };
    HBRUSH hWStatic, hBStatic, hSBBrush[3];
    int RWID, GWID, BWID, RBID, GBID, BBID;
    int WStatic, BStatic;
    HWND BlackSq, WhiteSq;
    BYTE WSqColors[3];
    BYTE BSqColors[3];
    void CLSetFocus(HWND);
    BOOL GetColorValue(WORD);

  DECLARE_RESPONSE_TABLE(TColorsDialog);
};

#endif  // COLORS_H
