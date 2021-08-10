//---------------------------------------------------------------------------
//Borland C++Builder
//Copyright (c) 1987, 1998 Borland International Inc. All Rights Reserved.
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
#ifndef DDCustomPaletteH
#define DDCustomPaletteH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "ddraw.h"
//---------------------------------------------------------------------------
class TFormMain : public TForm
{
__published:	// IDE-managed Components
	void __fastcall FormPaint(TObject *Sender);
        void __fastcall FormKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
private:	// User declarations
public:		// User declarations
	__fastcall TFormMain(TComponent* Owner);
    void __fastcall InitializeDirectDraw();
    void __fastcall SetupPrimarySurface();
    void __fastcall ShowPalette();
    int ddColors, ddWidth, ddHeight;
    IDirectDraw *DirectDraw;
    IDirectDrawSurface *PrimarySurface;
};
//---------------------------------------------------------------------------
extern PACKAGE TFormMain *FormMain;
//---------------------------------------------------------------------------
#endif
