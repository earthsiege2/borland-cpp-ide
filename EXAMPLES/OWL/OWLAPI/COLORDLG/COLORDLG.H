//----------------------------------------------------------------------------
// ObjectWindows - (C) Copyright 1991, 1993 by Borland International
//----------------------------------------------------------------------------
#ifndef __COLORDLG_H
#define __COLORDLG_H

#include "colordlg.rh"
#include <owl\dialog.h>
#include <owl\control.h>
#include <owl\color.h>
#include <owl\scrollba.h>

#if defined(BUILDEXAMPLEDLL)
	#define _EXAMPLECLASS __export
#elif defined (USEEXAMPLEDLL)
	#define _EXAMPLECLASS __import
#else
	#define _EXAMPLECLASS 
#endif

class _EXAMPLECLASS TColorControl : public TControl {
  public:
    TColorControl(TWindow* parent, int resId, TColor color);
    virtual void SetColor(TColor color);
    TColor       GetColor() const {return Color;}

  private:
    TColor  Color;

    char far* GetClassName() {return "ColorControl";}

    UINT Transfer(void* buffer, TTransferDirection direction);

    void EvPaint();

    void EvLButtonDown(UINT, TPoint&);
    void EvLButtonDblClk(UINT, TPoint&);

  DECLARE_RESPONSE_TABLE(TColorControl);
};

class _EXAMPLECLASS TColorDialog : public TDialog {
  public:
    TColorDialog(TWindow* parent, TColor& color);

  protected:
    TScrollBar*    ColorBar1;
    TScrollBar*    ColorBar2;
    TScrollBar*    ColorBar3;
    TColorControl* SelColor;

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
		void SetColorFmControl(UINT Id);
		void SetColorFmSlider();

  DECLARE_RESPONSE_TABLE(TColorDialog);
};

#endif

