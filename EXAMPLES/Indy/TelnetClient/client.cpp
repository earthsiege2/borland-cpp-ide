//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Client.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TTelnetForm *TelnetForm;
//---------------------------------------------------------------------------
__fastcall TTelnetForm::TTelnetForm(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TTelnetForm::UpDown1Click(TObject *Sender, TUDBtnType Button)
{
   int PortNumber = StrToInt(spnedtPort->Text);


   if(Button == btNext){
        PortNumber++;
   }
   if(Button == btPrev){
        PortNumber--;
   }

   spnedtPort->Text = IntToStr(PortNumber);
}
//---------------------------------------------------------------------------
void __fastcall TTelnetForm::FormCreate(TObject *Sender)
{
   spnedtPort->Text = "23";        
}
//---------------------------------------------------------------------------

void __fastcall TTelnetForm::btnConnectClick(TObject *Sender)
{
        IdTelnetDemo->Host = edtServer->Text;
        IdTelnetDemo->Port = StrToInt(spnedtPort->Text);
        IdTelnetDemo->Connect();

}
//---------------------------------------------------------------------------

void __fastcall TTelnetForm::btnDisconnectClick(TObject *Sender)
{
        IdTelnetDemo->Disconnect();
}
//---------------------------------------------------------------------------

void __fastcall TTelnetForm::Memo1KeyPress(TObject *Sender, char &Key)
{
        if(IdTelnetDemo->Connected()){
           IdTelnetDemo->SendCh(Key);
           Key = 0;
        }
}
//---------------------------------------------------------------------------

void __fastcall TTelnetForm::IdTelnetDemoDataAvailable(AnsiString Buffer)
{
  int Start, Stop;

  if(Memo1->Lines->Count == 0)
     Memo1->Lines->Add("");

     Start = 1;
     Stop = Buffer.Pos(IntToStr('\n')); //the character count to a CR in the buffer

     if(Stop == 0)
        Stop = Buffer.Length() + 1;

     while(Start <= Buffer.Length()){
        Memo1->Lines->Strings[Memo1->Lines->Count -1] =
        Memo1->Lines->Strings[Memo1->Lines->Count -1] +
        Buffer.SubString(Start,Stop-Start);
  
        if(Buffer.SubString(Stop,1)=='\n')
        {
           Memo1->Lines->Add("");
           SendMessage(Memo1->Handle,WM_KEYDOWN, VK_UP,1);
        }
        Start = Stop + 1;
        if(Start > Buffer.Length()){
          break;
        }
        if(Buffer.SubString(Start,1)=='\n'){
          Start++;
        }
        Stop = Start;
        while((Buffer.SubString(Stop, 1)!= '\n')&&(Stop <= Buffer.Length())){
           Stop++;
        }
     }

}
//---------------------------------------------------------------------------
void __fastcall TTelnetForm::IdTelnetDemoConnected(TObject *Sender)
{
   sbrStatus->SimpleText = "Connected";
}
//---------------------------------------------------------------------------

void __fastcall TTelnetForm::IdTelnetDemoConnect()
{
   sbrStatus->SimpleText = "Connect";
}
//---------------------------------------------------------------------------

