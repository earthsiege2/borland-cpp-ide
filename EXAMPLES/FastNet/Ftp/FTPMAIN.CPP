//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "ftpmain.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFormMain *FormMain;
//---------------------------------------------------------------------------
__fastcall TFormMain::TFormMain(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TFormMain::Button1Click(TObject *Sender)
{
  if (CheckBox1->Checked)
  {
    NMFTP1->Proxy = Edit6->Text;
    NMFTP1->Proxy = StrToInt(Edit7->Text);
  }
  NMFTP1->Host = HostTxt->Text;
  NMFTP1->Port = StrToInt(PortTxt->Text);
  NMFTP1->UserID = UserTxt->Text;
  NMFTP1->Password = PassTxt->Text;
  NMFTP1->Connect();
}
//---------------------------------------------------------------------------
void __fastcall TFormMain::Button2Click(TObject *Sender)
{
  NMFTP1->Disconnect();	        
}
//---------------------------------------------------------------------------
void __fastcall TFormMain::Button3Click(TObject *Sender)
{
  NMFTP1->Nlist();        
}
//---------------------------------------------------------------------------
void __fastcall TFormMain::Button4Click(TObject *Sender)
{
  NMFTP1->List();        
}
//---------------------------------------------------------------------------
void __fastcall TFormMain::Button5Click(TObject *Sender)
{
  NMFTP1->ChangeDir(DirTxt->Text);        
}
//---------------------------------------------------------------------------
void __fastcall TFormMain::Button6Click(TObject *Sender)
{
  NMFTP1->Download(RemoteTxt->Text, LocalTxt->Text);        
}
//---------------------------------------------------------------------------
void __fastcall TFormMain::Button7Click(TObject *Sender)
{
  NMFTP1->Abort();        
}
//---------------------------------------------------------------------------
void __fastcall TFormMain::Button8Click(TObject *Sender)
{
  NMFTP1->DownloadRestore(RemoteTxt->Text, LocalTxt->Text);        
}
//---------------------------------------------------------------------------
void __fastcall TFormMain::Button18Click(TObject *Sender)
{
  NMFTP1->Rename(Edit8->Text, Edit9->Text);        
}
//---------------------------------------------------------------------------
void __fastcall TFormMain::Button17Click(TObject *Sender)
{
  NMFTP1->Reinitialize();
  PageControl1->ActivePage = TabSheet2;
}
//---------------------------------------------------------------------------
void __fastcall TFormMain::Button16Click(TObject *Sender)
{
  NMFTP1->Delete(Edit5->Text);
}
//---------------------------------------------------------------------------
void __fastcall TFormMain::Button14Click(TObject *Sender)
{
  NMFTP1->MakeDirectory(Edit1->Text);        
}
//---------------------------------------------------------------------------
void __fastcall TFormMain::Button15Click(TObject *Sender)
{
  NMFTP1->RemoveDir(Edit2->Text);        
}
//---------------------------------------------------------------------------
void __fastcall TFormMain::Button11Click(TObject *Sender)
{
  NMFTP1->UploadAppend(Edit3->Text, Edit4->Text);        
}
//---------------------------------------------------------------------------
void __fastcall TFormMain::Button12Click(TObject *Sender)
{
  NMFTP1->UploadUnique(Edit3->Text);        
}
//---------------------------------------------------------------------------
void __fastcall TFormMain::Button13Click(TObject *Sender)
{
  NMFTP1->UploadRestore(Edit3->Text, Edit4->Text, StrToInt(PosTxt->Text));
}
//---------------------------------------------------------------------------
void __fastcall TFormMain::Button10Click(TObject *Sender)
{
  NMFTP1->Upload(Edit3->Text, Edit4->Text);
}
//---------------------------------------------------------------------------
void __fastcall TFormMain::Button9Click(TObject *Sender)
{
  NMFTP1->Abort();
}
//---------------------------------------------------------------------------
void __fastcall TFormMain::NMFTP1Connect(TObject *Sender)
{
  StatusBar1->SimpleText = "Connected";        
}
//---------------------------------------------------------------------------
void __fastcall TFormMain::NMFTP1ConnectionFailed(TObject *Sender)
{
  ShowMessage("Connection Failed");        
}
//---------------------------------------------------------------------------
void __fastcall TFormMain::NMFTP1Disconnect(TObject *Sender)
{
  if (StatusBar1 != 0)
    StatusBar1->SimpleText = "Disconnected";        
}
//---------------------------------------------------------------------------
void __fastcall TFormMain::NMFTP1Error(TComponent *Sender, WORD Errno,
      AnsiString Errmsg)
{
  ShowMessage("Error "+IntToStr(Errno)+": "+Errmsg);        
}
//---------------------------------------------------------------------------
void __fastcall TFormMain::NMFTP1Failure(bool &handled, TCmdType Trans_Type)
{
  switch (Trans_Type) {
    case cmdChangeDir: StatusBar1->SimpleText = "ChangeDir failure"; break;
    case cmdMakeDir: StatusBar1->SimpleText = "MakeDir failure"; break;
    case cmdDelete: StatusBar1->SimpleText = "Delete failure"; break;
    case cmdRemoveDir: StatusBar1->SimpleText = "RemoveDir failure"; break;
    case cmdList: StatusBar1->SimpleText = "List failure"; break;
    case cmdRename: StatusBar1->SimpleText = "Rename failure"; break;
    case cmdUpRestore: StatusBar1->SimpleText = "UploadRestore failure"; break;
    case cmdDownRestore: StatusBar1->SimpleText = "DownloadRestore failure"; break;
    case cmdDownload: StatusBar1->SimpleText = "Download failure"; break;
    case cmdUpload: StatusBar1->SimpleText = "Upload failure"; break;
    case cmdAppend: StatusBar1->SimpleText = "UploadAppend failure"; break;
    case cmdReInit: StatusBar1->SimpleText = "ReInit failure"; break;
    case cmdAllocate: StatusBar1->SimpleText = "Allocate failure"; break;
    case cmdNList: StatusBar1->SimpleText = "NList failure"; break;
    case cmdDoCommand: StatusBar1->SimpleText = "DoCommand failure"; break;
	default: ShowMessage("Unrecognized command failed."); break;
  }
}
//---------------------------------------------------------------------------
void __fastcall TFormMain::NMFTP1HostResolved(TComponent *Sender)
{
  StatusBar1->SimpleText = "Host Resolved";        
}
//---------------------------------------------------------------------------
void __fastcall TFormMain::NMFTP1InvalidHost(bool &handled)
{
  AnsiString NewHost;
  if (InputQuery("Invalid Host", "Please Choose another host", NewHost))
  {
    NMFTP1->Host = NewHost;
    handled = true;
  }
}
//---------------------------------------------------------------------------
void __fastcall TFormMain::NMFTP1ListItem(AnsiString Listing)
{
  Memo1->Lines->Add(Listing);
}
//---------------------------------------------------------------------------
void __fastcall TFormMain::NMFTP1PacketRecvd(TObject *Sender)
{
  StatusBar1->SimpleText = IntToStr(NMFTP1->BytesRecvd)+" bytes of "+IntToStr(NMFTP1->BytesTotal)+" received";
}
//---------------------------------------------------------------------------
void __fastcall TFormMain::NMFTP1PacketSent(TObject *Sender)
{
  StatusBar1->SimpleText = IntToStr(NMFTP1->BytesSent)+" bytes of "+IntToStr(NMFTP1->BytesTotal)+" sent";        
}
//---------------------------------------------------------------------------
void __fastcall TFormMain::NMFTP1Status(TComponent *Sender, AnsiString Status)
{
  if (StatusBar1 != 0)
    StatusBar1->SimpleText = Status;        
}
//---------------------------------------------------------------------------
void __fastcall TFormMain::NMFTP1Success(TCmdType Trans_Type)
{
  switch(Trans_Type)
  {
    case cmdChangeDir: StatusBar1->SimpleText = "ChangeDir success"; break;
    case cmdMakeDir: StatusBar1->SimpleText = "MakeDir success"; break;
    case cmdDelete: StatusBar1->SimpleText = "Delete success"; break;
    case cmdRemoveDir: StatusBar1->SimpleText = "RemoveDir success"; break;
    case cmdList: StatusBar1->SimpleText = "List success"; break;
    case cmdRename: StatusBar1->SimpleText = "Rename success"; break;
    case cmdUpRestore: StatusBar1->SimpleText = "UploadRestore success"; break;
    case cmdDownRestore: StatusBar1->SimpleText = "DownloadRestore success"; break;
    case cmdDownload: StatusBar1->SimpleText = "Download success"; break;
    case cmdUpload: StatusBar1->SimpleText = "Upload success"; break;
    case cmdAppend: StatusBar1->SimpleText = "UploadAppend success"; break;
    case cmdReInit: StatusBar1->SimpleText = "ReInit success"; break;
    case cmdAllocate: StatusBar1->SimpleText = "Allocate success"; break;
    case cmdNList: StatusBar1->SimpleText = "NList success"; break;
    case cmdDoCommand: StatusBar1->SimpleText = "DoCommand success"; break;
  }
}
//---------------------------------------------------------------------------
void __fastcall TFormMain::NMFTP1TransactionStart(TObject *Sender)
{
  StatusBar1->SimpleText = "Starting data transaction";        
}
//---------------------------------------------------------------------------
void __fastcall TFormMain::NMFTP1TransactionStop(TObject *Sender)
{
  StatusBar1->SimpleText = "Transaction Complete";        
}
//---------------------------------------------------------------------------
void __fastcall TFormMain::NMFTP1UnSupportedFunction(TCmdType Trans_Type)
{
  switch(Trans_Type)
  {
    case cmdChangeDir: ShowMessage("ChangeDir not supported"); break;
    case cmdMakeDir: ShowMessage("MakeDir not supported"); break;
    case cmdDelete: ShowMessage("Delete not supported"); break;
    case cmdRemoveDir: ShowMessage("RemoveDir not supported"); break;
    case cmdList: ShowMessage("List not supported"); break;
    case cmdRename: ShowMessage("Rename not supported"); break;
    case cmdUpRestore: ShowMessage("UploadRestore not supported"); break;
    case cmdDownRestore: ShowMessage("DownloadRestore not supported"); break;
    case cmdDownload: ShowMessage("Download not supported"); break;
    case cmdUpload: ShowMessage("Upload not supported"); break;
    case cmdAppend: ShowMessage("UploadAppend not supported"); break;
    case cmdReInit: ShowMessage("ReInit not supported"); break;
    case cmdAllocate: ShowMessage("Allocate not supported"); break;
    case cmdNList: ShowMessage("NList not supported"); break;
    case cmdDoCommand: ShowMessage("DoCommand not supported"); break;
  }
}
//---------------------------------------------------------------------------



