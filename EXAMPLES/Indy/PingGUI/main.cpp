//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Main.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TTfrmPing *TfrmPing;
//---------------------------------------------------------------------------
__fastcall TTfrmPing::TTfrmPing(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TTfrmPing::btnPingClick(TObject *Sender)
{
     int i;

     ICMP->OnReply = ICMPReply;
     ICMP->ReceiveTimeout = 1000;
     btnPing->Enabled = False;

     try
     {
          ICMP->Host = edtHost->Text;

          for(i = 1; i <= 4; i++)
          {
               ICMP->Ping();
               Application->ProcessMessages();
               // Sleep(1000);
          }
     }
     __finally
     {
          btnPing->Enabled = True;
     }
}
//---------------------------------------------------------------------------
void __fastcall TTfrmPing::ICMPReply(TComponent *ASender,
      const TReplyStatus &AReplyStatus)
{
     AnsiString sTime, result[5];

     // TODO: Check for error on ping reply (ReplyStatus->MsgType?)
     if(AReplyStatus.MsRoundTripTime == 0)
     {
          sTime = "<1";
     }
     else
     {
          sTime = "=";
     }

     result[0] = IntToStr(AReplyStatus.BytesReceived);
     result[1] = AReplyStatus.FromIpAddress;
     result[2] = IntToStr((int)AReplyStatus.SequenceId);
     result[3] = IntToStr((int)AReplyStatus.TimeToLive);
     result[4] = sTime;
     result[5] = IntToStr(AReplyStatus.MsRoundTripTime);

     lstReplies->Items->Add(result[0] + " bytes from " + result[1] +
                            ": icmp_seq=" + result[2] + " ttl=" + result[3] +
                            " time" + result[4] + result[5] + " ms");
}
//---------------------------------------------------------------------------
