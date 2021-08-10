//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "WhoIsMain.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfmMain *fmMain;
//---------------------------------------------------------------------------
__fastcall TfmMain::TfmMain(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TfmMain::edDomainKeyPress(TObject *Sender, char &Key)
{
     if(Key == '\r')
     {
          btLookup->OnClick(this);
     }
}
//---------------------------------------------------------------------------
void __fastcall TfmMain::btLookupClick(TObject *Sender)
{
     AnsiString ALine, AResult;
     int iPos;

     meResults->Clear();
     AResult = IdWhois->WhoIs(edDomain->Text);

     while(AResult.Length() > 0)
     {
          iPos = AResult.Pos('\n');

          if(iPos == 1)
          {
               AResult.Delete(1, 1);
          }
          else
          {
               ALine = AResult.SubString(1, iPos - 1);
               meResults->Lines->Add(ALine);
               AResult.Delete(1, ALine.Length());
          }
     }
}
//---------------------------------------------------------------------------
