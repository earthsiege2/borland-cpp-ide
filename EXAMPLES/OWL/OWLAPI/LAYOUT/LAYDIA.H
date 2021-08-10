//----------------------------------------------------------------------------
// ObjectWindows - (C) Copyright 1993 by Borland International
//----------------------------------------------------------------------------
#ifndef __LAYDIA_H
#define __LAYDIA_H

#ifndef __OWL_DIALOG_H
  #include <owl\dialog.h>
#endif
class _OWLCLASS TEdit;
class _OWLCLASS TComboBox;
class _OWLCLASS TListBox;

#define WM_SET_X (WM_USER + 100)

const int MaxWindows = 10;

struct TChildInfo {
  TWindow*       Child;
  TLayoutMetrics LayoutMetrics;
};

class TLayoutDialog : public TDialog {
  public:
	  TLayoutDialog(TLayoutWindow* parent, TResId resId, TChildInfo* info);
    enum Constraint { X1, X2, Y1, Y2};

  protected:
    char*          Title;
    TLayoutWindow* LayoutWindow;

    void    SetupWindow();
    void    HandleLayout();
    void    HandleWindowChange();

    void    SetLayoutConstraint(TLayoutConstraint& lc, Constraint which);
    void    GetLayoutConstraint(TLayoutConstraint& lc, Constraint which);

    TChildInfo*        ChildInfo;
    int                ChildNum;

    TListBox*  WindowList;

    TComboBox* X1EdgeCombo;
    TComboBox* X2EdgeCombo;
    TComboBox* Y1EdgeCombo;
    TComboBox* Y2EdgeCombo;

    TComboBox* X1OtherEdgeCombo;
    TComboBox* X2OtherEdgeCombo;
    TComboBox* Y1OtherEdgeCombo;
    TComboBox* Y2OtherEdgeCombo;

    TComboBox* X1UnitsCombo;
    TComboBox* X2UnitsCombo;
    TComboBox* Y1UnitsCombo;
    TComboBox* Y2UnitsCombo;

    TEdit*     X1ValueEdit;
    TEdit*     X2ValueEdit;
    TEdit*     Y1ValueEdit;
    TEdit*     Y2ValueEdit;

    TComboBox* X1RelationCombo;
    TComboBox* X2RelationCombo;
    TComboBox* Y1RelationCombo;
    TComboBox* Y2RelationCombo;

    TComboBox* X1RelWinCombo;
    TComboBox* X2RelWinCombo;
    TComboBox* Y1RelWinCombo;
    TComboBox* Y2RelWinCombo;

  DECLARE_RESPONSE_TABLE(TLayoutDialog);
};


#endif
