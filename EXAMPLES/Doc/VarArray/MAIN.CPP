//----------------------------------------------------------------------------
//Borland C++Builder
//Copyright (c) 1987, 1998 Borland International Inc. All Rights Reserved.
//----------------------------------------------------------------------------
//-----------------------------------------------------------------------
//Borland C++Builder
//Copyright (c) 1987, 1998 Borland International Inc. All Rights Reserved.
//-----------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "Main.h"
//-----------------------------------------------------------------------
#pragma resource "*.dfm"
TVariantArrayForm *VariantArrayForm;
//-----------------------------------------------------------------------
__fastcall TVariantArrayForm::TVariantArrayForm(TComponent* Owner)
  : TForm(Owner)
{
}
//-----------------------------------------------------------------------
__fastcall TVariantArrayForm::~TVariantArrayForm(void)
{
}
//-----------------------------------------------------------------------
void __fastcall TVariantArrayForm::bOneDimClick( TObject* Sender)
{
  AnsiString S;
  int I;

  S = "";

  Variant MyVariant(OPENARRAY(int,(0,5)),varInteger);
  for(I=0; I <= 5; I++){
    MyVariant.PutElement(I*2,I);
  }
  for(I=0; I <= 5; I++){
    S = S + " " + AnsiString(MyVariant.GetElement(I));
  }
    ShowMessage(S);
  }
//-----------------------------------------------------------------------
void __fastcall TVariantArrayForm::bTwoDimClick( TObject* Sender)
{
  AnsiString S;
  int I,J;

  S = "";

  Variant MyVariant(OPENARRAY(int,(0,5,0,5)),varInteger);
  for(I=0; I <= 5; I++){
    for(J=0; J <= 5; J++){
      MyVariant.PutElement(I*J,I,J);
    }
  }

  for(I=0; I <= 5; I++){
    for(J=0; J <= 5; J++){
      S = S + " " + AnsiString(MyVariant.GetElement(I,J));
    }
  S = S + "\n";
  }
  ShowMessage(S);
}
//-----------------------------------------------------------------------
