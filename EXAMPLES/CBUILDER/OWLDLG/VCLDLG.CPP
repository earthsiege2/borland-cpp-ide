//----------------------------------------------------------------------------
// ObjectWindows
// Copyright (c) 1996 by Borland International, All Rights Reserved
//
// This file defines a VCL form class.  It was originally generated
// by C++Builder.  The VCLDLG example invokes the form from an OWL
// application. 
//
// None of the original C++Builder code was altered, but the 
// GetSelectedColor function was added by hand.
//----------------------------------------------------------------------------
#define STRICT
#include <vcl\vcl.h>
#pragma hdrstop
#include "vcldlg.h"
//---------------------------------------------------------------------------
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
COLORREF TForm1::GetSelectedColor(void)
{
  // Note: the Max and Min properties of each scrollbar in this
  // form guarantee that the Position value will always be < 256.
  //
  return RGB(
             (unsigned char)ScrollBar_Red->Position,
             (unsigned char)ScrollBar_Green->Position,
             (unsigned char)ScrollBar_Blue->Position);
}
//---------------------------------------------------------------------------
void TForm1::SetSelectedColor(COLORREF color)
{
  ScrollBar_Red->Position   = GetRValue(color);
  ScrollBar_Green->Position = GetGValue(color);
  ScrollBar_Blue->Position  = GetBValue(color);
}
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
  : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormCreate(TObject* /*Sender*/)
{
  Label_Selection->Color = TColor(GetSelectedColor());
}
//---------------------------------------------------------------------
void __fastcall TForm1::ScrollBar_Change(TObject* /*Sender*/)
{
  Label_Selection->Color = TColor(GetSelectedColor());
}
//---------------------------------------------------------------------

