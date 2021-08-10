//----------------------------------------------------------------------------
//Borland C++Builder
//Copyright (c) 1987, 1998 Borland International Inc. All Rights Reserved.
//----------------------------------------------------------------------------
//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "Rsltform.h"
//---------------------------------------------------------------------------
#pragma resource "*.dfm"
TResultForm *ResultForm;
//---------------------------------------------------------------------------
__fastcall TResultForm::TResultForm(TComponent* Owner)
  : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TResultForm::SpeedButton2Click(TObject *Sender)
{
  AnsiString strText;    // Variable to hold display text
  int iCounter;  // Loop counter variable

  // Build a string containing the query
  strText = "";
  for (iCounter = 0; iCounter <= Query1->SQL->Count - 1; iCounter++)
  	strText += Query1->SQL->Strings[iCounter];

  // Display the query text
  MessageDlg("The underlying query is: \n\n" + strText,
              mtInformation, TMsgDlgButtons() << mbOK, 0 );

}
//---------------------------------------------------------------------
void __fastcall TResultForm::SpeedButton1Click(TObject *Sender)
{
  Close();
}
//---------------------------------------------------------------------