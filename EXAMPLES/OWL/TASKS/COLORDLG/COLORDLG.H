//----------------------------------------------------------------------------
// ObjectWindows
// Copyright (c) 1991, 1995 by Borland International, All Rights Reserved
//----------------------------------------------------------------------------
#if !defined(COLORDLG_H)
#define COLORDLG_H

#include <owl/dialog.h>
#include <owl/control.h>
#include <owl/scrollba.h>
#include <winsys/color.h>
#include "colordlg.rh"

#if defined(BUILDEXAMPLEDLL)
# define _EXAMPLECLASS __export
#elif defined (USEEXAMPLEDLL)
# define _EXAMPLECLASS __import
#else
# define _EXAMPLECLASS
#endif

//
// class TColorControl
// ~~~~~ ~~~~~~~~~~~~~
class _EXAMPLECLASS TColorControl : public TControl {
  public:
    TColorControl(TWindow* parent, int resId, TColor color);
    virtual void SetColor(TColor color);
    TColor       GetColor() const {return Color;}

  private:
    char far* GetClassName() {return "ColorControl";}
    uint Transfer(void* buffer, TTransferDirection direction);
    void EvPaint();
    void EvLButtonDown(uint, TPoint&);
    void EvLButtonDblClk(uint, TPoint&);

    TColor Color;

  DECLARE_RESPONSE_TABLE(TColorControl);
};


//
// class TColorDialog
// ~~~~~ ~~~~~~~~~~~~
class _EXAMPLECLASS TColorDialog : public TDialog {
  public:
    TColorDialog(TWindow* parent, TColor& color);

  protected:
    void SetupWindow();
    void TransferData(TTransferDirection direction);

    virtual void UpdateBars(TColor color);

    void ClickFmControl1();
    void ClickFmControl2();
    void ClickFmControl3();
    void ClickFmControl4();
    void ClickFmControl5();
    void ClickFmControl6();
    void ClickFmControl7();
    void ClickFmControl8();
    void SetColorFmControl(uint Id);
    void SetColorFmSlider();

    TScrollBar*    ColorBar1;
    TScrollBar*    ColorBar2;
    TScrollBar*    ColorBar3;
    TColorControl* SelColor;

  DECLARE_RESPONSE_TABLE(TColorDialog);
};

#endif // COLORDLG_H

