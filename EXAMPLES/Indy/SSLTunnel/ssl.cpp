//---------------------------------------------------------------------------
//Project       :SSLTunnel
//Version       :1.0
//Purpose       :Demonstrates setting up an SSL connection.
//Date          :Friday November 2, 2001
//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "ssl.h"

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
void __fastcall TformMain::FormCreate(TObject *Sender)
{
        if(ParamCount() == 3){
           MappedPort->DefaultPort = StrToInt(ParamStr(1));
           MappedPort->MappedHost = StrToInt(ParamStr(2));
           MappedPort->MappedPort = StrToInt(ParamStr(3));
           MappedPort->Active = true;
           lablLocal->Visible = true;
           lablHost->Visible = true;
        }
}
//---------------------------------------------------------------------------
void __fastcall TformMain::MappedPortBeforeClientConnect(
      TComponent *ASender, TIdPeerThread *AThread, TIdTCPClient *AClient)
{
  TIdConnectionInterceptOpenSSL  *LIntercept = new TIdConnectionInterceptOpenSSL(AClient);
  TIdSSLVerifyModeSet Mode;

  LIntercept->SSLOptions->Method = sslvSSLv2;
  LIntercept->SSLOptions->Mode = sslmClient;
  LIntercept->SSLOptions->VerifyMode = Mode;
  LIntercept->SSLOptions->VerifyDepth = 0;
  LIntercept->OnGetPassword = SSLInterceptGetPassword;


}
//---------------------------------------------------------------------------
void __fastcall TformMain::SSLInterceptGetPassword(AnsiString &Password){

  Password = "aaaa";
}


