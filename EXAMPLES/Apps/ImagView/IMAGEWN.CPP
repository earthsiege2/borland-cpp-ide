//----------------------------------------------------------------------------
//Borland C++Builder
//Copyright (c) 1987, 1998 Borland International Inc. All Rights Reserved.
//----------------------------------------------------------------------------
 //---------------------------------------------------------------------
// IMAGE VIEWER DEMO v.01
//---------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include <sysutils.hpp>
#include <stdio.h>
#include "imagewn.h"
#include "ViewFrm.h"
//---------------------------------------------------------------------
#pragma resource "*.dfm"
TImageForm *ImageForm;
//---------------------------------------------------------------------
__fastcall TImageForm::TImageForm(TComponent *Owner)
  : TForm(Owner)
{
}
//---------------------------------------------------------------------
void __fastcall TImageForm::FormCreate(TObject* /*Sender*/)
{     FormCaption = Caption + " - ";
}
//----------------------------------------------------------------------------
 void __fastcall TImageForm::ViewBtnClick(TObject* /*Sender*/)
{     ViewFrm->HorzScrollBar->Range = Image1->Picture->Width;
      ViewFrm->VertScrollBar->Range = Image1->Picture->Height;
      ViewFrm->Caption = Caption;
      ViewFrm->Show();
}
//----------------------------------------------------------------------------
 void __fastcall TImageForm::UpDownEditChange(TObject* /*Sender*/)
{
      SpeedButton1->NumGlyphs = UpDown1->Position;
      SpeedButton2->NumGlyphs = UpDown1->Position;
}
//----------------------------------------------------------------------------
 void __fastcall TImageForm::StretchCheckClick(TObject* /*Sender*/)
{     Image1->Stretch = StretchCheck->Checked;
}
//----------------------------------------------------------------------------
#pragma argsused
 void __fastcall TImageForm::FileEditKeyPress(TObject* Sender,
      Char &Key)
{     if (Key == 0x13) {
         FileListBox1->ApplyFilePath(FileEdit->Text);
         Key = 0x0;
      }
}
//----------------------------------------------------------------------------
 void __fastcall TImageForm::GlyphCheckClick(TObject* /*Sender*/)
{
     ViewAsGlyph(FileExt);
}
//----------------------------------------------------------------------------
 void __fastcall TImageForm::ViewAsGlyph(const AnsiString FileExt)
{
    if ( GlyphCheck->Checked && !strcmp(FileExt.c_str(),".BMP") ) {
         SpeedButton1->Glyph = Image1->Picture->Bitmap;
         SpeedButton2->Glyph = Image1->Picture->Bitmap;
         UpDown1->Position   = SpeedButton1->NumGlyphs;
         BitBtn1->Glyph      = Image1->Picture->Bitmap;
         BitBtn2->Glyph      = Image1->Picture->Bitmap;
         UpDown1->Enabled    = True;
         UpDownEdit->Enabled = True;
         Label2->Enabled     = True;
      }
      else {
         SpeedButton1->Glyph = NULL;
         SpeedButton2->Glyph = NULL;
         BitBtn1->Glyph      = NULL;
         BitBtn2->Glyph      = NULL;
         UpDown1->Enabled    = False;
         UpDownEdit->Enabled = False;
         Label2->Enabled     = False;
      }
}
//----------------------------------------------------------------------------
void __fastcall TImageForm::FileListBox1Click(TObject* /*Sender*/)
{    char cCaption[25];
     memset(cCaption,NULL,sizeof(cCaption));

     FileExt = ExtractFileExt(FileListBox1->FileName);
     FileExt = UpperCase(FileExt);

     if ( !strcmp(FileExt.c_str(),".BMP") || !strcmp(FileExt.c_str(),".ICO") ||
          !strcmp(FileExt.c_str(),".WMF") || !strcmp(FileExt.c_str(),".EMF" ))
     {
        Image1->Picture->LoadFromFile(FileListBox1->FileName);
        Caption = FormCaption + ExtractFileName(FileListBox1->FileName);

        if ( !strcmp(FileExt.c_str(),".BMP") )
        {
           sprintf(cCaption," (%d x %d)",Image1->Picture->Width,Image1->Picture->Height);
           Caption = (AnsiString)cCaption;
           ViewFrm->Image1->Picture = Image1->Picture;
           ViewFrm->Caption = Caption;
           GlyphCheck->Enabled = true;
           if (GlyphCheck->Checked)
                ViewAsGlyph(FileExt);
        }
        if ( !strcmp(FileExt.c_str(),".ICO") )
        {
             ViewFrm->Image1->Picture->Icon = Image1->Picture->Icon;
             Icon = Image1->Picture->Icon;
             GlyphCheck->Checked = false;
             GlyphCheck->Enabled = false;
        }
        if ( !strcmp(FileExt.c_str(),".WMF") || !strcmp(FileExt.c_str(),".EMF") )
        {
             ViewFrm->Image1->Picture->Metafile = Image1->Picture->Metafile;
             GlyphCheck->Checked = false;
             GlyphCheck->Enabled = false;
        }
     }
}
//----------------------------------------------------------------------------
