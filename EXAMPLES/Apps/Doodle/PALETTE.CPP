//----------------------------------------------------------------------------
//Borland C++Builder
//Copyright (c) 1987, 1998 Borland International Inc. All Rights Reserved.
//----------------------------------------------------------------------------
//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "palette.h"
#include "main.h"
//---------------------------------------------------------------------------
#pragma resource "*.dfm"
TToolPalette *ToolPalette;
//---------------------------------------------------------------------------
__fastcall TToolPalette::TToolPalette(TComponent* Owner)
    : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TToolPalette::ColorGrid1Change(TObject *Sender)
{
    // Set the colors of the glyphs that show foreground and background color.
    // Since the ColorGrid already displays FG and BG, the glyphs aren't really
    // needed.   Note that in the case of the color being black, the color of
    // the boarder of the glyph (aka the Pen) is changed to white.  This is
    // just so that the frame can still be seen against the fill color.
    FGShape->Brush->Color = ColorGrid1->ForegroundColor;
    if (FGShape->Brush->Color == TColor(clBlack))
        FGShape->Pen->Color = TColor(clWhite);
    else
        FGShape->Pen->Color = TColor(clBlack);

    BGShape->Brush->Color = ColorGrid1->BackgroundColor;
    if (BGShape->Brush->Color == TColor(clBlack))
        BGShape->Pen->Color = TColor(clWhite);
    else
        BGShape->Pen->Color = TColor(clBlack);
}
//---------------------------------------------------------------------------
void __fastcall TToolPalette::ShapeButtonClick(TObject *Sender)
{
    DoodleForm->Cursor = TCursor(crPlus);
}
//---------------------------------------------------------------------------
void __fastcall TToolPalette::FillButtonClick(TObject *Sender)
{
    DoodleForm->Cursor = TCursor(crFill);
}
//---------------------------------------------------------------------------
void __fastcall TToolPalette::PencilButtonClick(TObject *Sender)
{
    DoodleForm->Cursor = TCursor(crDraw);
}
//---------------------------------------------------------------------------
void __fastcall TToolPalette::EraseButtonClick(TObject *Sender)
{
    DoodleForm->Cursor = TCursor(crErase);
}
//---------------------------------------------------------------------------


 