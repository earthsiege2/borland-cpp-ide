//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
#include "nntpmain.h"
//---------------------------------------------------------------------------
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
  NMNNTP1->ReportLevel = Status_Basic;
  NMNNTP1->TimeOut = 20000;
  NMNNTP1->NewsDir = Edit5->Text;
  NMNNTP1->AttachFilePath = Edit6->Text;
  NMNNTP1->Host = Edit1->Text;
  NMNNTP1->Port = StrToInt(Edit2->Text);
  if (Edit3->Text != "")
  {
    NMNNTP1->UserId = Edit3->Text;
    NMNNTP1->Password = Edit4->Text;
  }
  if (RadioButton1->Checked)
    NMNNTP1->CacheMode = cmLocal;
  if (RadioButton2->Checked)
    NMNNTP1->CacheMode = cmMixed;
  if (RadioButton3->Checked)
    NMNNTP1->CacheMode = cmRemote;
  if (CheckBox1->Checked)
    NMNNTP1->ParseAttachments = true;
  else
    NMNNTP1->ParseAttachments = false;
  NMNNTP1->Connect();
}
//---------------------------------------------------------------------------
void __fastcall TFormMain::Button2Click(TObject *Sender)
{
  NMNNTP1->Disconnect();	
}
//---------------------------------------------------------------------------
void __fastcall TFormMain::Button3Click(TObject *Sender)
{
  NMNNTP1->GetArticleList(true,0);	
}
//---------------------------------------------------------------------------
void __fastcall TFormMain::Button4Click(TObject *Sender)
{
  NMNNTP1->GetArticle(StrToInt(Edit7->Text));
}
//---------------------------------------------------------------------------
void __fastcall TFormMain::Button7Click(TObject *Sender)
{
  NMNNTP1->PostBody->Assign(Memo5->Lines);
  NMNNTP1->PostRecord->PrFromAddress = Edit9->Text;
  NMNNTP1->PostRecord->PrReplyTo = Edit10->Text;
  NMNNTP1->PostRecord->PrSubject = Edit11->Text;
  NMNNTP1->PostRecord->PrNewsGroups = NMNNTP1->SelectedGroup;
  NMNNTP1->Attachments->Assign(ListBox2->Items);
  NMNNTP1->PostArticle();
}
//---------------------------------------------------------------------------
void __fastcall TFormMain::Button6Click(TObject *Sender)
{
  ListBox2->Items->Delete(ListBox2->ItemIndex);
}
//---------------------------------------------------------------------------
void __fastcall TFormMain::CheckBox1Click(TObject *Sender)
{
  if (CheckBox1->Checked)
    NMNNTP1->ParseAttachments = true;
  else
    NMNNTP1->ParseAttachments = false;
}
//---------------------------------------------------------------------------
void __fastcall TFormMain::Button5Click(TObject *Sender)
{
  if (OpenDialog1->Execute())
    ListBox2->Items->Add(OpenDialog1->FileName);
}
//---------------------------------------------------------------------------
void __fastcall TFormMain::ListBox2DblClick(TObject *Sender)
{
  NMNNTP1->SetGroup(ListBox1->Items->Strings[ListBox1->ItemIndex]);
}
//---------------------------------------------------------------------------
void __fastcall TFormMain::NMNNTP1Abort(TObject *Sender)
{
  StatusBar1->SimpleText = "Operation aborted";
}
//---------------------------------------------------------------------------
void __fastcall TFormMain::NMNNTP1Article(TObject *Sender)
{
  Memo3->Text = NMNNTP1->Header->Text;
  Memo2->Text = NMNNTP1->Body->Text;
  Memo1->Text = NMNNTP1->Attachments->Text;
}
//---------------------------------------------------------------------------
void __fastcall TFormMain::NMNNTP1ArticleCacheUpdate(bool &Handled, int IdNo,
	AnsiString From, AnsiString Subject, AnsiString MsgId, AnsiString Date,
	int ArticleNo)
{
  Memo3->Text = NMNNTP1->Header->Text;
  Memo2->Text = NMNNTP1->Body->Text;
  Memo1->Text = NMNNTP1->Attachments->Text;
}
//---------------------------------------------------------------------------
void __fastcall TFormMain::NMNNTP1Body(TObject *Sender)
{
  Memo3->Text = NMNNTP1->Body->Text;
}
//---------------------------------------------------------------------------
void __fastcall TFormMain::NMNNTP1BodyCacheUpdate(bool &handled)
{
  Memo3->Text = NMNNTP1->Body->Text;
}
//---------------------------------------------------------------------------
void __fastcall TFormMain::NMNNTP1Connect(TObject *Sender)
{
  StatusBar1->SimpleText = "Connected";
  NMNNTP1->GetGroupList();	
}
//---------------------------------------------------------------------------
void __fastcall TFormMain::NMNNTP1ConnectionFailed(TObject *Sender)
{
  ShowMessage("Connection Failed");	
}
//---------------------------------------------------------------------------
void __fastcall TFormMain::NMNNTP1ConnectionRequired(bool &handled)
{
  AnsiString BoxCaption;
  AnsiString BoxMsg;
  BoxCaption = "Connection Required";
  BoxMsg = "Connection Required. Connect?";
  if (MessageBox(0, &BoxMsg[1], &BoxCaption[1], MB_YESNO + MB_ICONEXCLAMATION) == IDYES)
  {
    handled = TRUE;
    Button1Click(this);
  }
}
//---------------------------------------------------------------------------
void __fastcall TFormMain::NMNNTP1Disconnect(TObject *Sender)
{
  if (StatusBar1 != 0)
    StatusBar1->SimpleText = "Disconnected";	
}
//---------------------------------------------------------------------------
void __fastcall TFormMain::NMNNTP1GroupListCacheUpdate(bool &Handled,
	AnsiString Name, int FirstArticle, int LastArticle, bool Posting)
{
  ListBox1->Items->Add(Name);
}
//---------------------------------------------------------------------------
void __fastcall TFormMain::NMNNTP1GroupListUpdate(AnsiString Name,
	int FirstArticle, int LastArticle, bool Posting)
{
  ListBox1->Items->Add(Name);
}
//---------------------------------------------------------------------------
void __fastcall TFormMain::NMNNTP1GroupSelect(TObject *Sender)
{
  Caption = "NNTP Demo - ["+NMNNTP1->SelectedGroup+" Lo:"+IntToStr(NMNNTP1->LoMessage)+" Hi:"+IntToStr(NMNNTP1->HiMessage);
  if (NMNNTP1->Posting == true)
    Caption = Caption + " Posting Allowed]";
  else
    Caption = Caption + " Posting Prohibited]";
}
//---------------------------------------------------------------------------
void __fastcall TFormMain::NMNNTP1GroupSelectRequired(bool &handled)
{
  AnsiString TmpStr;
  if (InputQuery("Newsgroup selectoion Required","Enter NewsGroup Name: ", TmpStr))
  {
    NMNNTP1->SetGroup(TmpStr);
    handled = true;
  }
}
//---------------------------------------------------------------------------
void __fastcall TFormMain::NMNNTP1Header(TObject *Sender)
{
  Memo3->Text = NMNNTP1->Header->Text;
}
//---------------------------------------------------------------------------
void __fastcall TFormMain::NMNNTP1HeaderCacheUpdate(bool &Handled, int IdNo,
	AnsiString From, AnsiString Subject, AnsiString MsgId, AnsiString Date,
	int ArticleNo)
{
  Memo3->Text = NMNNTP1->Header->Text;
}
//---------------------------------------------------------------------------
void __fastcall TFormMain::NMNNTP1HeaderList(TObject *Sender)
{
  Memo4->Lines->Add("["+IntToStr(NMNNTP1->HeaderRecord->PrArticleId)+"] From: " + NMNNTP1->HeaderRecord->PrFromAddress);
  Memo4->Lines->Add("    Subject: " + NMNNTP1->HeaderRecord->PrSubject);
}
//---------------------------------------------------------------------------
void __fastcall TFormMain::NMNNTP1HeaderListCacheUpdate(bool &handled)
{
  Memo4->Lines->Add("["+IntToStr(NMNNTP1->HeaderRecord->PrArticleId)+"] From: " + NMNNTP1->HeaderRecord->PrFromAddress);
  Memo4->Lines->Add("    Subject: " + NMNNTP1->HeaderRecord->PrSubject);
}
//---------------------------------------------------------------------------
void __fastcall TFormMain::NMNNTP1HostResolved(TComponent *Sender)
{
  StatusBar1->SimpleText = "Host Resolved";	
}
//---------------------------------------------------------------------------
void __fastcall TFormMain::NMNNTP1InvalidArticle(TObject *Sender)
{
  ShowMessage("Article number invalid");
}
//---------------------------------------------------------------------------
void __fastcall TFormMain::NMNNTP1InvalidHost(bool &handled)
{
  AnsiString NewHost;
  if (InputQuery("Invalid Host", "Please Choose another host", NewHost))
  {
    //ShowMessage(NewHost);
    NMNNTP1->Host = NewHost;
    handled = true;
  }
}
//---------------------------------------------------------------------------
void __fastcall TFormMain::NMNNTP1Posted(TObject *Sender)
{
  ShowMessage("Article Posted");	
}
//---------------------------------------------------------------------------
void __fastcall TFormMain::NMNNTP1PostFailed(TComponent *Sender, WORD Errno,
	AnsiString Errmsg)
{
  ShowMessage("Post Failed. Error: "+IntToStr(Errno)+"; "+Errmsg);	
}
//---------------------------------------------------------------------------
void __fastcall TFormMain::NMNNTP1Status(TComponent *Sender, AnsiString Status)
{
  if (StatusBar1 != 0)
    StatusBar1->SimpleText = Status;
}
//---------------------------------------------------------------------------





