//----------------------------------------------------------------------------
//Borland C++Builder
//Copyright (c) 1987, 1998 Borland International Inc. All Rights Reserved.
//----------------------------------------------------------------------------
//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
#include <ctype.h>
#include <process.h>
#include <stdio.h>
#include "fmxUtils.h"
#include "FAttrdlg.h"
#include "fchngdlg.h"
#include "fmxwin.h"
//---------------------------------------------------------------------------
#pragma link "CDIROUTL"
#pragma link "cdiroutl"
#pragma resource "*.dfm"
TFormMain *FormMain;
//---------------------------------------------------------------------------
__fastcall TFormMain::TFormMain(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFormMain::Exit1Click(TObject *Sender)
{
  Close();
}
//---------------------------------------------------------------------
#pragma warn -sig
void __fastcall TFormMain::Properties1Click(TObject *Sender)
{

  unsigned short  Attributes;
  unsigned short  NewAttributes;

  FileAttrDlg->FileDirName->Caption = FileList->Items->Strings[FileList->ItemIndex];
  FileAttrDlg->FilePathName->Caption = FileList->Directory;
  FileAttrDlg->ChangeDate->Caption = DateTimeToStr(FileDateTime(FileList->FileName));
  Attributes = FileGetAttr(FileList->Items->Strings[FileList->ItemIndex]);
  FileAttrDlg->ReadOnly->Checked = Attributes & faReadOnly;
  FileAttrDlg->Archive->Checked = Attributes & faArchive;
  FileAttrDlg->System->Checked = Attributes & faSysFile;
  FileAttrDlg->Hidden->Checked = Attributes & faHidden;
  if (FileAttrDlg->ShowModal()!= mrCancel){
     NewAttributes = Attributes;
     if (FileAttrDlg->ReadOnly->Checked)
       NewAttributes = NewAttributes | faReadOnly;
     else
		NewAttributes = NewAttributes & ~faReadOnly;

     if (FileAttrDlg->Archive->Checked)
       NewAttributes = NewAttributes | faArchive;
     else
       NewAttributes = NewAttributes & ~faArchive;

     if (FileAttrDlg->System->Checked)
       NewAttributes = NewAttributes | faSysFile;
     else
       NewAttributes = NewAttributes & ~faSysFile;

     if (FileAttrDlg->Hidden->Checked)
       NewAttributes = NewAttributes | faHidden;
     else
       NewAttributes = NewAttributes  & ~faHidden;
     if (NewAttributes != Attributes)
       FileSetAttr(FileAttrDlg->FileDirName->Caption, NewAttributes);
  }
}
#pragma warn .sig

//---------------------------------------------------------------------
void __fastcall TFormMain::DirectoryOutlineChange(TObject *Sender)
{
  FileList->Directory = DirectoryOutline->Directory;
  DirectoryPanel->Caption=DirectoryOutline->Directory;
}
//---------------------------------------------------------------------
void __fastcall TFormMain::DirectoryOutlineDragDrop(TObject *Sender,
                                                    TObject *Source,
                                                    int X, int Y)
{
  if (dynamic_cast<TFileListBox *> (Source)!=0)
    ConfirmChange("Move", FileList->FileName,
    DirectoryOutline ->Items[DirectoryOutline ->GetItem(X, Y)]->FullPath);
}
//---------------------------------------------------------------------
void __fastcall TFormMain::DirectoryOutlineDragOver(TObject *Sender,
                                                    TObject *Source,
                                                    int X, int Y,
                                                    TDragState State,
                                                    bool &Accept)
{
  if (dynamic_cast<TFileListBox *> (Source))
      Accept = True;
}

//---------------------------------------------------------------------
#pragma warn -stv
void __fastcall TFormMain::ConfirmChange(const AnsiString ACaption,
                                         AnsiString FromFile,
                                         AnsiString ToFile)
{
  char buffer[700];
  sprintf(buffer,"%s %s to %s?",ACaption, FromFile, ToFile);
  if(MessageDlg(buffer,
                mtConfirmation,
                TMsgDlgButtons() << mbYes << mbNo,
                0) == mrYes){
      {
        if (ACaption == "Move")
          MoveFile(FromFile, ToFile);
        else if (ACaption == "Copy")
          CopyFile(FromFile, ToFile);
        else if (ACaption =="Rename")
          RenameFile(FromFile, ToFile);
      }
     FileList->Update();
   }
}
#pragma warn .stv

//---------------------------------------------------------------------
void __fastcall TFormMain::FormCreate(TObject *Sender)
{
  static char * Drive_Letter[]={"a:\\","b:\\","c:\\","d:\\","e:\\","f:\\",
      "g:\\","h:\\","i:\\","j:\\","k:\\","l:\\","m:\\","n:\\","o:\\","p:\\",
      "q:\\","r:\\","s:\\","t:\\","u:\\","v:\\","w:\\","x:\\","y:\\","z:\\"};

  int  AddedIndex;
     for(int x =0; x <= 25; x++ )
      {
        switch(GetDriveType(Drive_Letter[x]))
          {
              case DRIVE_REMOVABLE:
                AddedIndex=DriveTabSet->Tabs->AddObject(String(Drive_Letter[x]),
                Floppy->Picture->Graphic);
              break;
              case DRIVE_FIXED:
                AddedIndex=DriveTabSet->Tabs->AddObject(String(Drive_Letter[x]),
                Fixed->Picture->Graphic);
              break;
              case DRIVE_REMOTE:
                AddedIndex=DriveTabSet->Tabs->AddObject(String(Drive_Letter[x]),
                Network->Picture->Graphic);
              break;
              case DRIVE_CDROM:
                AddedIndex=DriveTabSet->Tabs->AddObject(Drive_Letter[x],
                Floppy->Picture->Graphic);
              break;
              case DRIVE_RAMDISK:
                AddedIndex=DriveTabSet->Tabs->AddObject(Drive_Letter[x],
                Floppy->Picture->Graphic);
              break;
            }

          if (toupper(*Drive_Letter[x]) == FileList->Drive)
              DriveTabSet->TabIndex = AddedIndex;

       }
}

//---------------------------------------------------------------------
#pragma warn -stv
void __fastcall TFormMain::FileListChange(TObject *Sender)
{
  AnsiString TheFileName;
    if(FileList->ItemIndex>=0){
        char buffer[255];
        TheFileName =FileList->Items->Strings[FileList->ItemIndex];
        sprintf(buffer,
                "%s  %d bytes",
                TheFileName,
                GetFileSize(TheFileName));
        FilePanel->Caption = buffer;

        if (GetFileAttributes(TheFileName.c_str()) & FILE_ATTRIBUTE_DIRECTORY)
          FileSelected = false;
        else
          FileSelected = true;
    }
    else {
         FilePanel->Caption="";
         FileSelected = false;
    }
}
#pragma warn .stv

//---------------------------------------------------------------------
void __fastcall TFormMain::FileListEndDrag(TObject *Sender,TObject *Target,
                                           Integer X, Integer Y)

{
   if (Target != NULL)
   FileList->Update();
}
//---------------------------------------------------------------------
void __fastcall TFormMain::FileListMouseDown(TObject *Sender,
	 TMouseButton Button, TShiftState Shift, Integer X, Integer Y)
{
  if(Button==mbLeft)
    {
      if (dynamic_cast<TFileListBox *>(Sender)!=0)
           {
             if(dynamic_cast<TFileListBox *>(Sender)->ItemAtPos(Point(X,Y),
                            True) >=0)
              dynamic_cast<TFileListBox *>(Sender)->BeginDrag(false, -1);
           }
    }
}
//---------------------------------------------------------------------
void __fastcall TFormMain::DriveTabSetClick(TObject *Sender)
{
  DirectoryOutline->Drive= *((DriveTabSet->Tabs->Strings
                             [DriveTabSet->TabIndex]).c_str());
}
//---------------------------------------------------------------------
void __fastcall TFormMain::DriveTabSetDrawTab(TObject *Sender,
                                              TCanvas *TabCanvas,
                                              TRect &R, Integer Index,
                                              Boolean Selected)
{
  Graphics::TBitmap *Bitmap;
  Bitmap = (Graphics::TBitmap *) (DriveTabSet->Tabs->Objects[Index]);
  TabCanvas->Draw(R.Left, R.Top + 4, Bitmap);
  TabCanvas->TextOut(R.Left + 2 + Bitmap->Width, R.Top + 2,
  			DriveTabSet->Tabs->Strings[Index].SubString(1,1));

}
//---------------------------------------------------------------------
void __fastcall TFormMain::DriveTabSetMeasureTab(TObject *Sender,
	             Integer Index, Integer &TabWidth)
{
  int BitmapWidth;
  BitmapWidth = ((Graphics::TBitmap *)
                (DriveTabSet->Tabs->Objects[Index]))->Width;
  TabWidth=TabWidth+2+BitmapWidth;
}
//---------------------------------------------------------------------
void __fastcall TFormMain::File1Click(TObject *Sender)
{
    Open1->Enabled = FileSelected;
    Delete1->Enabled = FileSelected;
    Copy1->Enabled = FileSelected;
    Move1->Enabled = FileSelected;
    Rename1->Enabled = FileSelected;
    Properties1->Enabled = FileSelected;
}
//---------------------------------------------------------------------
void __fastcall TFormMain::Delete1Click(TObject *Sender)
{
  if(MessageDlg("Delete" + FileList->FileName + "?",
                mtConfirmation,
                TMsgDlgButtons() << mbYes << mbNo, 0) == mrYes){
    if(DeleteFile(FileList->FileName.c_str()))
      FileList->Items->Delete(FileList->ItemIndex);
  }
}
//---------------------------------------------------------------------
void __fastcall TFormMain::Open1Click(TObject *Sender)
{
  if (HasAttr(FileList->FileName, faDirectory))
    DirectoryOutline->Directory = FileList->FileName;
  else
    ExecuteFile(FileList->FileName," ", DirectoryOutline->Directory, SW_SHOW);
 }
//---------------------------------------------------------------------
void __fastcall TFormMain::FileChange(TObject *Sender)
{
  if (dynamic_cast<TMenuItem *>(Sender) == Move1 )
    ChangeDlg->Caption = "Move" ;
  else if (dynamic_cast<TMenuItem *>(Sender) == Copy1)
    ChangeDlg->Caption = "Copy";
  else if (dynamic_cast<TMenuItem *>(Sender) == Rename1)
    ChangeDlg->Caption = "Rename";
  else
    _c_exit();

  ChangeDlg->CurrentDir->Caption = DirectoryOutline->Directory;
  ChangeDlg->FromFileName->Text = FileList->FileName;
  ChangeDlg->ToFileName->Text = "";

  if ((ChangeDlg->ShowModal() != mrCancel) &&
     (ChangeDlg->ToFileName->Text != ""))

    ConfirmChange(ChangeDlg->Caption,
                  ChangeDlg->FromFileName->Text,
                  ChangeDlg->ToFileName->Text);

}

void __fastcall TFormMain::FileListDblClick(TObject *Sender)
{
  Open1Click(Sender);
}
//---------------------------------------------------------------------
