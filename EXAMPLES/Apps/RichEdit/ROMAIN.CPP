//----------------------------------------------------------------------------
//Borland C++Builder
//Copyright (c) 1987 - 2000 Borland International Inc. All Rights Reserved.
//----------------------------------------------------------------------------
//---------------------------------------------------------------------
// RICH EDIT DEMO v.02
//
//
//---------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
#include <windows.hpp>
#include <stdlib.h>
#include <stdio.h>
#include "Romain.h"
#include "RichAbt.h"
#include "ReConst.hpp"
#include "reinit.hpp"

const float RulerAdj = 4.0/3.0;
const int GutterWid = 6;
//----------------------------------------------------------------------------
#pragma resource "*.dfm"
TMainForm *MainForm;
//----------------------------------------------------------------------------
__fastcall TMainForm::TMainForm(TComponent *Owner)
  : TForm(Owner)
{
  SetFileName(Reconst_SUntitled);
}
//----------------------------------------------------------------------------
void __fastcall TMainForm::SelectionChange(TObject */*Sender*/)
{
  char sizebuf[6];

  try {
	   FUpdating = True;
	   FirstInd->Left = int(RichEdit1->Paragraph->FirstIndent*RulerAdj)-
							4+GutterWid;
	   LeftInd->Left  = int((RichEdit1->Paragraph->LeftIndent+
							RichEdit1->Paragraph->FirstIndent)*RulerAdj)-
							4+GutterWid;
	   RightInd->Left = Ruler->ClientWidth-6-int(
						(RichEdit1->Paragraph->RightIndent+GutterWid)*RulerAdj);

	   BoldButton->Down = RichEdit1->SelAttributes->Style.Contains(fsBold);
	   ItalicButton->Down = RichEdit1->SelAttributes->Style.Contains(fsItalic);
	   UnderlineButton->Down = RichEdit1->SelAttributes->Style.Contains(fsUnderline);

	   BulletsButton->Down = bool(RichEdit1->Paragraph->Numbering);

	   FontSize->Text = itoa(RichEdit1->SelAttributes->Size, sizebuf, 10);
	   FontName->Text = RichEdit1->SelAttributes->Name;

	   switch((int)RichEdit1->Paragraph->Alignment)
	   { case 0: LeftAlign->Down   = True; break;
		 case 1: RightAlign->Down  = True; break;
		 case 2: CenterAlign->Down = True; break;
	   }
	 }
     catch (...) {
       FUpdating = False;
     }
     FUpdating = False;
}
//----------------------------------------------------------------------------
TTextAttributes *__fastcall TMainForm::CurrText(void)
{
    return RichEdit1->SelAttributes;
}
//----------------------------------------------------------------------------
int __stdcall EnumFontsProc(TLogFontA &LogFont, TTextMetricA &/*TextMetric*/,
                                int /*FontType*/, Pointer Data)
{
     TCharsetObject *FontCharset;
     FontCharset = new TCharsetObject((int)LogFont.lfCharSet);
     ((TStrings *)Data)->AddObject((AnsiString)LogFont.lfFaceName,FontCharset);
     return 1;
}
//----------------------------------------------------------------------------
void __fastcall TMainForm::GetFontNames(void)
{    HDC hDC = GetDC(0);
     void * cTmp = (void *)FontName->Items;
     EnumFonts(hDC, NULL, (FONTENUMPROC) EnumFontsProc, (long) cTmp );
     ReleaseDC(0,hDC);
     FontName->Sorted = True;
}
//----------------------------------------------------------------------------
void __fastcall TMainForm::SetFileName(const AnsiString FileName)
{
     LPSTR lpBuf = new char[MAX_PATH];
     sprintf(lpBuf, Reconst_SPercent_s.c_str(), ExtractFileName(FileName).c_str(),
             Application->Title.c_str());
     Caption = (AnsiString)lpBuf;
     FFileName = FileName;
     delete lpBuf;
}
//----------------------------------------------------------------------------
void __fastcall TMainForm::CheckFileSave(void)
{    if ( RichEdit1->Modified ) {
        switch(MessageBox(Handle, Reconst_SSaveChanges.c_str(),
          Reconst_SConfirmation.c_str(),MB_YESNOCANCEL | MB_ICONQUESTION))
        {  case ID_YES    : FileSaveClick(this);
           case ID_CANCEL : Abort();
        };
     }
}
//----------------------------------------------------------------------------
void __fastcall TMainForm::SetupRuler(void)
{    int iCtr = 1;
     char sTmp[201];
     while (iCtr < 200) {
       sTmp[iCtr] = 9;
       iCtr++;
       sTmp[iCtr] = '|';
       iCtr++;
     }
     Ruler->Caption = (AnsiString)sTmp;
}
//----------------------------------------------------------------------------
void __fastcall TMainForm::SetEditRect(void)
{    TRect Rct = Rect(GutterWid, 0, RichEdit1->ClientWidth-GutterWid,
                               ClientHeight);
     SendMessage(RichEdit1->Handle, EM_SETRECT, 0, long(&Rct));
}
//----------------------------------------------------------------------------
void __fastcall TMainForm::FormCreate(TObject* /*Sender*/)
{
  AnsiString asLcid;
  int iLcid;

  Application->OnHint = &ShowHint;
  OpenDialog->InitialDir = ExtractFilePath(ParamStr(0));
  SaveDialog->InitialDir = OpenDialog->InitialDir;
  GetFontNames();
  SetupRuler();
  SelectionChange(this);

  US1->Tag = ENGLISH;
  German1->Tag = GERMAN;
  French1->Tag = FRENCH;

  asLcid = LoadStr(_SLcid.id);
  iLcid = asLcid.ToInt();

  US1->Checked = iLcid == US1->Tag;
  German1->Checked = iLcid == German1->Tag;
  French1->Checked = iLcid == French1->Tag;
}
//----------------------------------------------------------------------------
void __fastcall TMainForm::ShowHint(TObject* /*Sender*/)
{    StatusBar->SimpleText = Application->Hint;
}
//----------------------------------------------------------------------------
void __fastcall TMainForm::FileNewClick(TObject* /*Sender*/)
{    CheckFileSave();
     SetFileName(Reconst_SUntitled);
     RichEdit1->Lines->Clear();
     RichEdit1->Modified = False;
}
//----------------------------------------------------------------------------
void __fastcall TMainForm::FileOpenClick(TObject* /*Sender*/)
{    CheckFileSave();
     if (OpenDialog->Execute()) {
        RichEdit1->Lines->LoadFromFile(OpenDialog->FileName);
        SetFileName(OpenDialog->FileName);
        RichEdit1->SetFocus();
        RichEdit1->Modified = False;
        RichEdit1->ReadOnly = OpenDialog->Options.Contains(ofReadOnly);
     }
}
//----------------------------------------------------------------------------
void __fastcall TMainForm::FileSaveClick(TObject* Sender)
{    if ( !strcmp(FFileName.c_str(), Reconst_SUntitled.c_str()) )
        FileSaveAsClick(Sender);
     else
     {
        RichEdit1->Lines->SaveToFile(FFileName);
        RichEdit1->Modified = False;
     }
}
//----------------------------------------------------------------------------
void __fastcall TMainForm::FileSaveAsClick(TObject* /*Sender*/)
{    if ( SaveDialog->Execute() ) {
        // Options + OverwritePrompt = True thus no need to check.
        RichEdit1->Lines->SaveToFile(SaveDialog->FileName);
        SetFileName(SaveDialog->FileName);
        RichEdit1->Modified = False;
     }
}
//----------------------------------------------------------------------------
void __fastcall TMainForm::FilePrintClick(TObject* /*Sender*/)
{    if ( PrintDialog->Execute() ) RichEdit1->Print( FFileName );
}
//----------------------------------------------------------------------------
void __fastcall TMainForm::FileExitClick(TObject* /*Sender*/)
{    Close();
}
//----------------------------------------------------------------------------
void __fastcall TMainForm::EditUndoClick(TObject* /*Sender*/)
{    if ( RichEdit1->HandleAllocated() )
        SendMessage(RichEdit1->Handle, EM_UNDO, 0, 0);
}
//----------------------------------------------------------------------------
void __fastcall TMainForm::EditCutClick(TObject* /*Sender*/)
{    RichEdit1->CutToClipboard();
}
//----------------------------------------------------------------------------
void __fastcall TMainForm::EditCopyClick(TObject* /*Sender*/)
{    RichEdit1->CopyToClipboard();
}
//----------------------------------------------------------------------------
void __fastcall TMainForm::EditPasteClick(TObject* /*Sender*/)
{    RichEdit1->PasteFromClipboard();
}
//----------------------------------------------------------------------------
void __fastcall TMainForm::HelpContentsClick(TObject* /*Sender*/)
{
     Application->HelpCommand(HELP_CONTENTS, 0);
}
//----------------------------------------------------------------------------
void __fastcall TMainForm::HelpSearchClick(TObject* /*Sender*/)
{
     Application->HelpCommand(HELP_PARTIALKEY, (long) "");
}
//----------------------------------------------------------------------------
void __fastcall TMainForm::HelpHowToClick(TObject* /*Sender*/)
{
     Application->HelpCommand(HELP_HELPONHELP, 0);
}
//----------------------------------------------------------------------------
void __fastcall TMainForm::HelpAboutClick(TObject* /*Sender*/)
{
     Form2 = new TForm2(Application);
     Form2->ShowModal();
     delete Form2;
}
//----------------------------------------------------------------------------
void __fastcall TMainForm::SelectFont(TObject* /*Sender*/)
{    FontDialog1->Font->Assign( RichEdit1->SelAttributes );
     if ( FontDialog1->Execute() )
        CurrText()->Assign( FontDialog1->Font );

     RichEdit1->SetFocus();
}
//----------------------------------------------------------------------------
void __fastcall TMainForm::RulerResize(TObject* /*Sender*/)
{     RulerLine->Width = (int)Ruler->ClientWidth - (RulerLine->Left*2);
}
//----------------------------------------------------------------------------
void __fastcall TMainForm::FormResize(TObject* Sender)
{    SetEditRect();
     SelectionChange(Sender);
}
//----------------------------------------------------------------------------
void __fastcall TMainForm::FormPaint(TObject* /*Sender*/)
{    SetEditRect();
}
//----------------------------------------------------------------------------
void __fastcall TMainForm::BoldButtonClick(TObject* /*Sender*/)
{    if ( !FUpdating )
     {  if ( BoldButton->Down )
           CurrText()->Style = CurrText()->Style << fsBold;
        else
           CurrText()->Style = CurrText()->Style >> fsBold;
     }
}
//----------------------------------------------------------------------------
void __fastcall TMainForm::ItalicButtonClick(TObject* /*Sender*/)
{    if ( !FUpdating )
     {
        if ( ItalicButton->Down )
           CurrText()->Style = CurrText()->Style << fsItalic;
        else
           CurrText()->Style = CurrText()->Style >> fsItalic;
     }
}
//----------------------------------------------------------------------------
void __fastcall TMainForm::UnderlineButtonClick(TObject* /*Sender*/)
{    if ( !FUpdating )
     {
        if ( UnderlineButton->Down )
           CurrText()->Style = CurrText()->Style << fsUnderline;
        else
           CurrText()->Style = CurrText()->Style >> fsUnderline;
     }
}
//----------------------------------------------------------------------------
void __fastcall TMainForm::FontSizeChange(TObject* /*Sender*/)
{
     int fontsize = atoi(FontSize->Text.c_str());

     if ((!FUpdating) &&  (fontsize))
     {
         if (fontsize < 1)
         {
             ShowMessage(Reconst_SNumberbetween);
             FontSize->Text = 1;
         }
         else if (fontsize > 1638)
         {
             ShowMessage(Reconst_SNumberbetween);
             FontSize->Text = 1638;
         }
         CurrText()->Size = atoi(FontSize->Text.c_str());
     }
}
//----------------------------------------------------------------------------
void __fastcall TMainForm::AlignClick(TObject* Sender)
{    if ( !FUpdating ) {
        TControl *oAliBtn = (TControl*)(Sender);
        RichEdit1->Paragraph->Alignment = (TAlignment)oAliBtn->Tag;
     }
}
//----------------------------------------------------------------------------
void __fastcall TMainForm::FontNameChange(TObject* /*Sender*/)
{
     TCharsetObject* ChasrsetObject;

     if ( !FUpdating )
     {
        int FontIndex = FontName->ItemIndex;
        if ((FontIndex > -1) & (FontIndex < FontName->Items->Count))
        {
          ChasrsetObject = (TCharsetObject*)FontName->Items->Objects[FontName->ItemIndex];
          CurrText()->Charset = (unsigned char)ChasrsetObject->Charset;
          CurrText()->Name = FontName->Items->Strings[FontName->ItemIndex];
        }
     }
}
//----------------------------------------------------------------------------
void __fastcall TMainForm::BulletsButtonClick(TObject* /*Sender*/)
{    if ( !FUpdating )
        RichEdit1->Paragraph->Numbering = (TNumberingStyle)BulletsButton->Down;
}
//----------------------------------------------------------------------------
void __fastcall TMainForm::FormCloseQuery(TObject* /*Sender*/,
     bool & CanClose)
{    try {
       CheckFileSave();
     }
     catch (...) {
       CanClose = False;
     }
}
//----------------------------------------------------------------------------

//***************************
//***Ruler Indent Dragging***
//***************************

//----------------------------------------------------------------------------
void __fastcall TMainForm::RulerItemMouseDown(TObject * Sender,
     TMouseButton Button, TShiftState Shift, int X, int Y)
{    TLabel * oTmpLabel = (TLabel *)Sender;
     FDragOfs = oTmpLabel->Width / 2;
     oTmpLabel->Left = oTmpLabel->Left+X-FDragOfs;
     FDragging = True;
}
//----------------------------------------------------------------------------
void __fastcall TMainForm::RulerItemMouseMove(TObject *Sender, TShiftState Shift,
     int X, int /*Y*/)
{    if (FDragging) {
        TLabel * oTmpLabel = (TLabel *)Sender;
        oTmpLabel->Left = oTmpLabel->Left+X-FDragOfs;
     }
}
//----------------------------------------------------------------------------
void __fastcall TMainForm::FirstIndMouseUp(TObject *Sender, TMouseButton
     Button, TShiftState Shift, int X, int Y)
{    FDragging = False;
     RichEdit1->Paragraph->FirstIndent = int((FirstInd->Left+FDragOfs-GutterWid) / RulerAdj);
     LeftIndMouseUp(Sender, Button, Shift, X, Y);
}
//----------------------------------------------------------------------------
void __fastcall TMainForm::LeftIndMouseUp(TObject *Sender, TMouseButton
      /*Button*/, TShiftState /*Shift*/, int /*X*/,	int /*Y*/)
{    FDragging = False;
     RichEdit1->Paragraph->LeftIndent = int((LeftInd->Left+FDragOfs-GutterWid)/
                RulerAdj)-RichEdit1->Paragraph->FirstIndent;
     SelectionChange(Sender);
}
//----------------------------------------------------------------------------
void __fastcall TMainForm::RightIndMouseUp(TObject *Sender, TMouseButton
      /*Button*/, TShiftState /*Shift*/, int /*X*/,	int /*Y*/)
{    FDragging = False;
     RichEdit1->Paragraph->RightIndent =
         int((Ruler->ClientWidth-RightInd->Left+FDragOfs-2) /
         RulerAdj)-2*GutterWid;
     SelectionChange(Sender);
}
//----------------------------------------------------------------------------
void __fastcall TMainForm::FormActivate(TObject *Sender)
{
     Application->HelpFile = "RICHEDIT.HLP";
     RichEdit1->SetFocus();
}
//---------------------------------------------------------------------
void SetLocaleOverrides(char* FileName, char* LocaleOverride)
{
 HKEY Key;
 const char* LocaleOverrideKey = "Software\\Borland\\Locales";
 if (RegOpenKeyEx(HKEY_CURRENT_USER,LocaleOverrideKey, 0, KEY_ALL_ACCESS, &Key)
     == ERROR_SUCCESS)
     {
      if (lstrlen(LocaleOverride) == 3)
         RegSetValueEx(Key, FileName, 0, REG_SZ, (const BYTE*)LocaleOverride, 4);
      RegCloseKey(Key);
     }
}

//---------------------------------------------------------------------
void __fastcall TMainForm::US1Click(TObject *Sender)
{
  AnsiString Name;
  int Size;

  if (LoadNewResourceModule(((TComponent*)Sender)->Tag) != 0)
  {
    Name = FontName->Text;
    Size = StrToInt(FontSize->Text);
    ReinitializeForms();
    US1->Checked = US1 == Sender;
    German1->Checked  = German1 == Sender;
    French1->Checked  = French1 == Sender;

    CurrText()->Name = Name;
    CurrText()->Size = Size;
    SelectionChange(this);
    FontName->SelLength = 0;

    SetupRuler();
    RichEdit1->SetFocus();
  }
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::FormDestroy(TObject *Sender)
{
     for(int n = 0;n < FontName->Items->Count;n++)
       if( FontName->Items->Objects[n] ){
         delete FontName->Items->Objects[n];
         FontName->Items->Objects[n] = NULL;
       }
}
//----------------------------------------------------------------------------
__fastcall TCharsetObject::TCharsetObject(int FCharset)
  : TObject()
{
     Charset = FCharset;
}
//---------------------------------------------------------------------------

