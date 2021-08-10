//----------------------------------------------------------------------------
//Borland C++ Builder
//Copyright (c) 1987, 1998 Borland International Inc. All Rights Reserved.
//----------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include <memory>       //for STL auto_ptr class
#include "SaveQAs.h"
#pragma resource "*.DFM"
//---------------------------------------------------------------------------

__fastcall TSaveQueryAs::TSaveQueryAs(TComponent* AOwner)
                                :TForm(AOwner)
{
}
__fastcall TSaveQueryAs::~TSaveQueryAs(void)
{
}
//---------------------------------------------------------------------------

bool __fastcall GetNewName(AnsiString& QueryName)
{
   bool Result;
   std::auto_ptr<TSaveQueryAs> pQuery(new TSaveQueryAs(Application));

   pQuery->NameEdit->Text = QueryName;
   Result = pQuery->ShowModal() == mrOk;
   if(Result){
     QueryName = pQuery->NameEdit->Text;
   }
   return Result;
};

void __fastcall TSaveQueryAs::NameEditChange( TObject* Sender)
{
  OKBtn->Enabled = NameEdit->Text != "";
};

//End of conversion...
