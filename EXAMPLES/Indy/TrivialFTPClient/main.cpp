//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Main.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfrmMain *frmMain;
//---------------------------------------------------------------------------
__fastcall TfrmMain::TfrmMain(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TfrmMain::btnUploadClick(TObject *Sender)
{
     AnsiString s;

     s = edtRemoteFile->Text;

     if(s == "")
     {
          s = ExtractFileName(edtLocalFile->Text);
     }

     TrivialFTP->Host = edtHost->Text;
     TrivialFTP->Put(edtLocalFile->Text, s);
}
//---------------------------------------------------------------------------
void __fastcall TfrmMain::btnDownloadClick(TObject *Sender)
{
     TFileStream *strm;
     AnsiString s;

     s = edtLocalFile->Text;

     if(s == "")
     {
          s = ExtractFileName(edtRemoteFile->Text);
     }

     strm = new TFileStream(s, fmCreate);

     try
     {
          TrivialFTP->Host = edtHost->Text;
          TrivialFTP->Get(edtRemoteFile->Text, strm);
     }
     __finally
     {
          delete strm;
     }
}
//---------------------------------------------------------------------------

