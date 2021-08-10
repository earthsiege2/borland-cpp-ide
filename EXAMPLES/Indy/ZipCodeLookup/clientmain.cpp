//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "ClientMain.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TformMain *formMain;
//---------------------------------------------------------------------------
__fastcall TformMain::TformMain(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TformMain::butnClearClick(TObject *Sender)
{
     memoInput->Clear();
     lboxResults->Clear();
}
//---------------------------------------------------------------------------

void __fastcall TformMain::butnLookupClick(TObject *Sender)
{
     int i;
     AnsiString s;

     butnLookup->Enabled = True;

     try
     {
          lboxResults->Clear();

          Client->Connect();

          try
          {
               lboxResults->Items->Add(Client->ReadLn());

               for(i = 0; i <= memoInput->Lines->Count - 1; i++)
               {
                    Client->WriteLn("ZipCode " + memoInput->Lines->Strings[i]);
                    lboxResults->Items->Add(memoInput->Lines->Strings[i]);
                    s = Client->ReadLn();

                    if(s == "")
                    {
                         s = "-- No entry found for this zip code.";
                    }

                    lboxResults->Items->Add(s);
                    lboxResults->Items->Add("");
               }

               Client->WriteLn("QUIT");
          }
          __finally
          {
               Client->Disconnect();
          }
     }
     __finally
     {
          butnLookup->Enabled = True;
     }
}
//---------------------------------------------------------------------------


