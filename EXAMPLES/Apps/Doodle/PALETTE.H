//----------------------------------------------------------------------------
//Borland C++Builder
//Copyright (c) 1987, 1998 Borland International Inc. All Rights Reserved.
//----------------------------------------------------------------------------
//---------------------------------------------------------------------------
#ifndef paletteH
#define paletteH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
#include <ExtCtrls.hpp>
#include <Buttons.hpp>
#include <cgrid.h>
//---------------------------------------------------------------------------
class TToolPalette : public TForm
{
__published:	// IDE-managed Components
    TPageControl *PageControl1;
    TTabSheet *Tab1;
    TTabSheet *Tab2;
    TCColorGrid *ColorGrid1;
    TPanel *Panel1;
    TShape *BGShape;
    TShape *FGShape;
    TSpeedButton *PencilButton;
    TSpeedButton *FillButton;
    TSpeedButton *EraseButton;
    TSpeedButton *CircleButton;
    TSpeedButton *SquareButton;
    TSpeedButton *SolidCirButton;
    TSpeedButton *SolidSqButton;
    void __fastcall ColorGrid1Change(TObject *Sender);
    void __fastcall ShapeButtonClick(TObject *Sender);
    void __fastcall FillButtonClick(TObject *Sender);
    void __fastcall PencilButtonClick(TObject *Sender);
    void __fastcall EraseButtonClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
    virtual __fastcall TToolPalette(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern TToolPalette *ToolPalette;
//---------------------------------------------------------------------------
#endif
 
