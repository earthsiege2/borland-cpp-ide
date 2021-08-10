//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Main.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfrmTimeDemo *frmTimeDemo;
//---------------------------------------------------------------------------
__fastcall TfrmTimeDemo::TfrmTimeDemo(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
// No real code required - all functionality built into component!
void __fastcall TfrmTimeDemo::btnGetTimeClick(TObject *Sender)
{
     IdDemoTime->Host = cmboTimeServer->Text;
     // After setting Host, this is all you have to do to get the time from a
     // time server.  We do the rest.
     edtTimeResult->Text = DateTimeToStr(IdDemoTime->DateTime);
}
//---------------------------------------------------------------------------
