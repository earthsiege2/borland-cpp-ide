//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Parser.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::btnDoItClick(TObject *Sender)
{
        TIdURI *URI = new TIdURI(edtURI->Text);
        try{
           edtProtocol->Text    = URI->Protocol;
           edtHost->Text        = URI->Host;
           edtPort->Text        = URI->Port;
           edtPath->Text        = URI->Path;
           edtDocument->Text    = URI->Document;
        }__finally{
           delete URI;
        }
}
//---------------------------------------------------------------------------

