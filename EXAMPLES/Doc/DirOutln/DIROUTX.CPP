//----------------------------------------------------------------------------
//Borland C++Builder
//Copyright (c) 1987, 1998 Borland International Inc. All Rights Reserved.
//----------------------------------------------------------------------------
//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "diroutx.h"
//---------------------------------------------------------------------------
#pragma link "cdiroutl"
#pragma resource "*.dfm"
TFormMain *FormMain;
//---------------------------------------------------------------------------
__fastcall TFormMain::TFormMain(TComponent* Owner)
  : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFormMain::DirectoryOutline1Change(TObject *Sender)
{
	FileListBox1->Directory=DirectoryOutline1->Directory;  
}
//---------------------------------------------------------------------
void __fastcall TFormMain::DriveComboBox1Change(TObject *Sender)
{
	DirectoryOutline1->Drive=DriveComboBox1->Drive;  
}
//---------------------------------------------------------------------
void __fastcall TFormMain::Edit1Change(TObject *Sender)
{
	FileListBox1->Mask=Edit1->Text;  
}
//---------------------------------------------------------------------
void __fastcall TFormMain::FileListBox1Change(TObject *Sender)
{
	// put some data in the memo
    const int size=1024;
    char buffer[size];
    memset(buffer,0,size);
    HFILE file=_lopen(FileListBox1->FileName.c_str(),OF_READ);
    if (file!=NULL) _lread(file,buffer,size);
    // nulls will terminate this too soon, so we will
    // replace them with '.'
    for (int i=0;i<1023;i++) if (buffer[i]==0) buffer[i]='.';
    Memo1->Text=AnsiString(buffer);
    _lclose(file);
}
//---------------------------------------------------------------------
void __fastcall TFormMain::FileListBox1Enter(TObject *Sender)
{
 // The first item in the box is not yet selected, let's take care of that.
 if (FileListBox1->ItemIndex == 0)
 {
     SendMessage(FileListBox1->Handle, LB_SETSEL, TRUE, FileListBox1->ItemIndex );	
     FileListBox1->OnChange(Sender);
 }    	
}
//---------------------------------------------------------------------------

