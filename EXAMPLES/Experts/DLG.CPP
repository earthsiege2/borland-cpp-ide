//---------------------------------------------------------------------------
// Borland C++Builder
// Copyright (c) 1987, 1999-2002 Borland Corporation.  All Rights Reserved.
//---------------------------------------------------------------------------
/* DLG.CPP: Dialogbox Expert implementation (DlgExpert class)
*/

//---------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include <Proxies.hpp>
#include <controls.hpp>
#include <classes.hpp>
#include <VirtIntf.hpp>
#include <IStreams.hpp>

#include <memory>         // auto_ptr (no .H on this!)
using namespace std;

#include "dlg.h"          // dialogbox expert class defintion
#include <stdio.h>
//---------------------------------------------------------------
#pragma resource "*.dfm"
TDlgExpert *DlgExpert;

const int
  // page numbers
  pgStyle          = 0,    // multi vs. single page dialog
  pgPages          = 1,    // page names
  pgButtons        = 2,    // button layouts
  SourceBufferSize = 8096;

int DlgHeight = 250;
int DlgWidth  = 400;
int BtnHeight =  25;
int BtnWidth  =  75;

//========================================[ TDlgExpert ]=========
__fastcall TDlgExpert::TDlgExpert(TComponent* AOwner)
                      :TForm(AOwner)
{
}

//========================================[ TDlgExpert ]=========
__fastcall TDlgExpert::TDlgExpert(HWND ParentWindow)
                      :TForm(ParentWindow)
{
}

//========================================[ TDlgExpert ]=========
__fastcall TDlgExpert::TDlgExpert(TComponent* AOwner, int Dummy)
                      :TForm(AOwner, Dummy)
{
}

//========================================[ TDlgExpert ]=========
__fastcall TDlgExpert::~TDlgExpert(void) {
}

//========================================= TDlgExpert ==========
void __fastcall TDlgExpert::FormCreate(TObject *Sender)
{
  DrawBitmap = new Graphics::TBitmap;
  PrevClick(this);
  RefreshButtons();
} // end of TDlgExpert.FormCreate()

//========================================= TDlgExpert ==========
void __fastcall TDlgExpert::FormDestroy(TObject *Sender)
{
  delete DrawBitmap;
} // end of TDlgExpert.FormDestroy()

//========================================= TDlgExpert ==========
void __fastcall TDlgExpert::CancelClick(TObject *Sender)
{
  Close();
} // end of TDlgExpert.CancelClick()

//========================================= TDlgExpert ==========
// Paint the sample pane based on the currently selected options
void __fastcall TDlgExpert::SamplePaint(TObject *Sender)
{
  int X;
  int Y;

  // always paint the background dialog
  DrawBitmap = new Graphics::TBitmap;
  DrawBitmap->Handle = LoadBitmap(instance, "DIALOG");
  Sample->Canvas->Draw(0, 0, DrawBitmap);

  if (Definition.Contains(daMultPg))
  {
    DrawBitmap->Handle = LoadBitmap(instance, "MULTPG");
    Sample->Canvas->Draw(4, 16, DrawBitmap);
  }

  if (Definition.Contains(daBtnsV))
  {
    DrawBitmap->Handle = LoadBitmap(instance, "BTNSV");
    X = 75;
    Y = 22;

    if (Definition.Contains(daMultPg))
    {
      X -= 2;
      Y += 4;
    }

    Sample->Canvas->Draw(X, Y, DrawBitmap);
  }

  if (Definition.Contains(daBtnsH))
  {
    DrawBitmap->Handle = LoadBitmap(instance, "BTNSH");
    X = 50;
    Y = 55;

    if (Definition.Contains(daMultPg))
      Y -= 4;

    Sample->Canvas->Draw(X, Y, DrawBitmap);
  }

  delete DrawBitmap;
  DrawBitmap = 0;
} // end of TDlgExpert::SamplePaint()

//========================================= TDlgExpert ==========
void __fastcall TDlgExpert::StyleClick(TObject *Sender)
{
  if (rbMultPg->Checked)
    Definition << daMultPg;
  else
    Definition >> daMultPg;

  SamplePaint(this);
} // end of TDlgExpert.StyleClick(

//========================================= TDlgExpert ==========
void __fastcall TDlgExpert::BtnClick(TObject *Sender)
{
  if (rbBtnsV->Checked)
    Definition << daBtnsV;
  else
    Definition >> daBtnsV;

  if (rbBtnsH->Checked)
    Definition << daBtnsH;
  else
    Definition >> daBtnsH;

  SamplePaint(this);
} // end of TDlgExpert.BtnClick()

//========================================= TDlgExpert ==========
void __fastcall TDlgExpert::PrevClick(TObject *Sender)
{
  switch(PageControl->ActivePage->PageIndex)
  {
    case pgStyle:
      return;
    case pgPages:
      PageControl->ActivePage = PageControl->Pages[pgStyle];
      break;
    case pgButtons:
      if (Definition.Contains(daMultPg))
        PageControl->ActivePage = PageControl->Pages[pgPages];
      else
        PageControl->ActivePage = PageControl->Pages[pgStyle];
      break;
  }

  RefreshButtons();
} // end of TDlgExpert::PrevClick()

//========================================= TDlgExpert ==========
void __fastcall TDlgExpert::NextClick(TObject *Sender)
{
  switch(PageControl->ActivePage->PageIndex)
  {
    case pgStyle:
      if (Definition.Contains(daMultPg))
        PageControl->ActivePage = PageControl->Pages[pgPages];
      else
        PageControl->ActivePage = PageControl->Pages[pgButtons];
      break;
    case pgPages:
      PageControl->ActivePage = PageControl->Pages[pgButtons];
      break;
    case pgButtons:
      ModalResult = mrOK;
      return;
  }

  RefreshButtons();
} // end of TDlgExpert::NextClick()

//========================================= TDlgExpert ==========
void __fastcall TDlgExpert::RefreshButtons(void)
{
  PrevButton->Enabled = PageControl->ActivePage->PageIndex > 0;
  if (PageControl->ActivePage->PageIndex == pgButtons)
    NextButton->Caption = LoadStr(sFinish);
  else
    NextButton->Caption = LoadStr(sNext);
} // end of TDlgExpert::RefreshButtons()

//========================================= TDlgExpert ==========
// Create the dialog defined by the user
TForm* __fastcall TDlgExpert::DoFormCreation(const String ffn)
{
  TPoint       BtnPos;
  TPageControl *PgCtrl;
  TForm        *Result;

  // Create form symbol based on button orientation and...
  if (!Definition.Contains(daBtnsV) && !Definition.Contains(daBtnsH))
    FormName = "OKNoButDlg";
  else {
    if (Definition.Contains(daBtnsH))
      FormName = "OKBottomDlg";
    else
      FormName = "OKRightDlg";
  }

  // ...number associated with the forms's module (file) name.
  FormName += ffn.c_str()[ffn.Length()-1];

  // Create the dialog's form and...
  Result = new TForm(this);

  // ...a proxy form for it.
  Proxies::CreateSubClass(Result, "T" + FormName, __classid(TForm));

  // Give the form its personality and...
  Result->BorderStyle = bsDialog;
  Result->ClientWidth = DlgWidth;
  Result->ClientHeight= DlgHeight;
  Result->Position    = poScreenCenter;
  Result->Name        = FormName;
  Result->Caption     = FormName;
  Font->Name          = "MS Sans Serif";
  Font->Size          = 8;

  // ...create its pages (if a paged dialog box was selected).
  if (Definition.Contains(daMultPg))
  {
    PgCtrl         = new TPageControl(Result);
    PgCtrl->Parent = Result;
    PgCtrl->Name   = "PageControl1";
    PgCtrl->Align  = alClient;

    int i = 0;
    int p;
    for (i = 0; i < PageNames->Lines->Count; i++)
    {
      TTabSheet *temp   = new TTabSheet(Result);
      temp->Parent      = Result;
      temp->PageControl = PgCtrl;
      temp->Caption     = PageNames->Lines->Strings[i];
      temp->Name        = Format("TabSheet%d",
                                 OPENARRAY(TVarRec, (i+1)));
    }
  }

  // Setup and create vertical/horizontal buttons.
  if (Definition.Contains(daBtnsH) || Definition.Contains(daBtnsV))
  {

    // Get the starting point for the buttons and...
    if (Definition.Contains(daBtnsH)) {
      BtnPos = Point(Result->ClientWidth-((BtnWidth+2)*3)-(5*3),
                     Result->ClientHeight-(BtnHeight+2)-5);
    }
    else
      BtnPos = Point(Result->ClientWidth-(BtnWidth+2)-5,
                     BtnHeight+5);

    // ...finalize positions.
    if (Definition.Contains(daMultPg))
    {
      BtnPos.x -= 5;
      if (Definition.Contains(daBtnsV))
        BtnPos.y += 5;
      else
        BtnPos.y -= 5;
    }

   // Create the buttons. This is the 'OK' button,...
    TButton *temp     = new TButton(Result);
    temp->Parent      = Result;
    temp->Left        = BtnPos.x;
    temp->Top         = BtnPos.y;
    temp->Height      = BtnHeight;
    temp->Width       = BtnWidth;
    temp->Caption     = LoadStr(sOKButton);
    temp->Name        = "Button1";
    temp->Default     = True;
    temp->ModalResult = mrOk;

    // (Move to the next button position)
    if (Definition.Contains(daBtnsH))
      BtnPos.x += BtnWidth + 5;
    else
      BtnPos.y += BtnHeight + 5;

    // ...this is the 'Cancel' button and...
    temp              = new TButton(Result);
    temp->Parent      = Result;
    temp->Left        = BtnPos.x;
    temp->Top         = BtnPos.y;
    temp->Height      = BtnHeight;
    temp->Width       = BtnWidth;
    temp->Name        = "Button2";
    temp->Caption     = LoadStr(sCancelButton);
    temp->Cancel      = True;
    temp->ModalResult = mrCancel;

    // (Move to the next button position)
    if (Definition.Contains(daBtnsH))
      BtnPos.x += 75 + 5;
    else
      BtnPos.y += 25 + 5;

    // ...this is the 'Help' button.
    temp          = new TButton(Result);
    temp->Parent  = Result;
    temp->Left    = BtnPos.x;
    temp->Top     = BtnPos.y;
    temp->Height  = BtnHeight;
    temp->Width   = BtnWidth;
    temp->Name    = "Button3";
    temp->Caption = LoadStr(sHelpButton);
  }

  return Result;
} // end of TDlgExpert::DoFormCreation()

//========================================= TDlgExpert ==========
TMemoryStream* __fastcall TDlgExpert::CreateForm(const String FormIdent)
{
  TForm         *DlgForm;
  TMemoryStream *Result;

  DlgForm = DoFormCreation(FormIdent);
  try
  {
    Result = new TMemoryStream;
    Result->WriteComponentRes(FormIdent, DlgForm);
    Result->Position = 0;
  } catch(...)
  {
    delete DlgForm;
    delete Result;
  }

  delete DlgForm;
  return Result;
} // end of TDlgExpert::CreateForm()

//========================================= TDlgExpert ==========
TMemoryStream* __fastcall TDlgExpert::CreateHdrSource(const String UnitIdent,
                                                      const String FormIdent)
{
  TMemoryStream *Result;

  SourceBuffer = new char[SourceBufferSize];
  try
  {
    Result = new TMemoryStream;
    try
    {
      // Write header's macro guard and includes:
      //#ifndef tunameH
      //#define tunameH
      //
      //#include <SysUtils.hpp>
      //#include <Windows.hpp>
      //#include <Messages.hpp>
      //#include <Classes.hpp>
      //#include <Graphics.hpp>
      //#include <Controls.hpp>
      //#include <StdCtrls.hpp>
      //#include <ExtCtrls.hpp>
      //#include <Forms.hpp>
      {
      String s = (String)SEPARATOR + CRLF;
      s       += (String)"#ifndef %sH" + CRLF;
      s       += (String)"#define %sH" + CRLF;
      s       += (String)SEPARATOR + CRLF;
      s       += (String)"#include <\SysUtils.hpp>" + CRLF;
      s       += (String)"#include <\Windows.hpp>" + CRLF + CRLF;
      s       += (String)"#include <\Messages.hpp>" + CRLF;
      s       += (String)"#include <\Classes.hpp>" + CRLF;
      s       += (String)"#include <\Graphics.hpp>" + CRLF;
      s       += (String)"#include <\Controls.hpp>" + CRLF;
      s       += (String)"#include <\StdCtrls.hpp>" + CRLF;
      s       += (String)"#include <\ExtCtrls.hpp>" + CRLF;
      s       += (String)"#include <\Forms.hpp>" + CRLF + CRLF;
      FmtWrite(Result, s.c_str(),
               OPENARRAY(TVarRec, (UnitIdent, UnitIdent)));
      }

      // If multipage dialogbox, include COMCTLS.HPP
      if (Definition.Contains(daMultPg)) {
        String s  = (String)"#include <\ComCtrls.hpp>" + CRLF;
               s += (String)CRLF + SEPARATOR + CRLF;
        FmtWrite(Result, s.c_str(), OPENARRAY(TVarRec, (NULL)));
      }

      // The class declaration
      {
      String s  = (String)"class T%s: public TForm" + CRLF;
               s += (String)"{" + CRLF;
               s += (String)"__published:" + CRLF;
      FmtWrite(Result, s.c_str(), OPENARRAY(TVarRec, (FormName)));
      }

      // Add variable declarations
      if (Definition.Contains(daBtnsH) || Definition.Contains(daBtnsV))
      {
        String s  = (String)"%sTButton *Button1;" + CRLF;
               s += (String)"%sTButton *Button2;" + CRLF;
               s += (String)"%sTButton *Button3;" + CRLF;
        FmtWrite(Result, s.c_str(),
                 OPENARRAY(TVarRec, (INDENT, INDENT, INDENT)));
       }

      // If this is a multipage dialogbox...
      if (Definition.Contains(daMultPg))
      {

        // ...we'll need a page control object and...
        String s = (String)"%sTPageControl *PageControl1;" + CRLF;
        FmtWrite(Result, s.c_str(), OPENARRAY(TVarRec, (INDENT)));

        // ...tabsheet objects for each page.
        if (PageNames->Lines->Count > 0)
          for (int i = 0; i < PageNames->Lines->Count; i++) {
            String s = (String)"%sTTabSheet *TabSheet%d;" + CRLF;
            FmtWrite(Result, s.c_str(),
                     OPENARRAY(TVarRec, (INDENT, i + 1)));
          }
      }

      // Write the user maintained class sections and the class's
      // constructor prototype:
      //private:
      //public:
      //    virtual __fastcall Tclassname(TComponent *Owner);
      //};
      {
      String s  = (String)"private:" + CRLF;
             s += (String)"public:" + CRLF;
             s += (String)"%svirtual __fastcall T%s(TComponent *Owner);" + CRLF;
             s += (String)"};" + CRLF;
      FmtWrite(Result, s.c_str(),
               OPENARRAY(TVarRec, (INDENT, FormName)));
      }

      // Write the form's extern and close the macro guard:
      //---------------------------------------------------------
      //extern TClassname *classname;
      //---------------------------------------------------------
      //
      //#endif // headernameH
      {
      String s  = (String)SEPARATOR + CRLF;
             s += (String)"extern T%s *%s;" + CRLF;
             s += (String)SEPARATOR + CRLF;
             s += (String)"#endif"; // // %sH" + CRLF;
      FmtWrite(Result, s.c_str(),
               OPENARRAY(TVarRec, (FormName, FormName)));
      }

      // Finally, rewind to start of stream.
      Result->Position = 0;

    } catch(...)
    {
      delete Result;
      Result = NULL;
    }
  } catch(...)
  {
    delete SourceBuffer;
    SourceBuffer = NULL;
  }

  delete SourceBuffer;
  SourceBuffer = NULL;
  return Result;
} // end of TDlgExpert::CreateSource()

//========================================= TDlgExpert ==========
TMemoryStream* __fastcall TDlgExpert::CreateSource(const String UnitIdent,
                                                   const String FormIdent)
{
  TMemoryStream *Result;

  try
  {
    SourceBuffer = new char[SourceBufferSize];
    Result = new TMemoryStream;
    try
    {
      // CPP (source) setup looks like:
      //---------------------------------------------------------
      //#include <vcl.h>
      //#pragma hdrstop
      //
      {
      String s  = (String)SEPARATOR + CRLF;
             s += (String)"#include <vcl.h>" + CRLF;
             s += (String)"#pragma hdrstop" + CRLF;
      FmtWrite(Result, s.c_str(), OPENARRAY(TVarRec, (NULL)));
      }

      // Additional include if multipaged dialog selected
      //#include <ComCtrls.h>
      if (Definition.Contains(daMultPg)) {
        String s = (String)"#include <\ComCtrls.hpp>" + CRLF;
        FmtWrite(Result, s.c_str(), OPENARRAY(TVarRec, (NULL)));
      }

      // Include the source's own header file:
      //#include <modnam.h>
      //---------------------------------------------------------
      //#pragma resource "*.dfm"
      //
      {
      sprintf(SourceBuffer, "\n\r#include \"%s.h\"\n\r\n\r"
                            "#pragma resource \"*.dfm\"\n\r",
              UnitIdent.c_str());
      Result->Write(SourceBuffer, strlen(SourceBuffer));
      }

      // Add variable declarations and constructor:
      //TOKRightDlg *OKRightDlg;
      //---------------------------------------------------------
      //__fastcall TOKRightDlg::TOKRightDlg(TComponent *AOwner)
      //                       :TForm(AOwner)
      //{
      //}
      //---------------------------------------------------------
      //
      {
      String s  = (String)"T%s *%s;" + CRLF + SEPARATOR + CRLF + CRLF;
             s += (String)"__fastcall T%s::T%s(TComponent* AOwner)" + CRLF;
             s += (String)"              :TForm(AOwner)" + CRLF;
             s += (String)"{" + CRLF;
             s += (String)"}" + CRLF +  SEPARATOR;
      FmtWrite(Result, s.c_str(), OPENARRAY(TVarRec,
                                            (FormName, FormName,
                                             FormName, FormName)));
      }

      // Finally, rewind to start of stream.
      Result->Position = 0;
    } catch(...)
    {
      delete Result;
      Result = NULL;
    }
  } catch(...)
  {
    delete SourceBuffer;
    SourceBuffer = NULL;
  }

  delete SourceBuffer;
  SourceBuffer = NULL;
  return Result;
} // end of TDlgExpert::CreateSource()

//========================================= TDlgExpert ==========
void __fastcall TDlgExpert::FmtWrite(TStream *Stream, char *Fmt,
                                     const TVarRec *Args,
                                     const int Args_Size)
{
  String p("%");
  String f(Fmt);

  if (Stream && SourceBuffer)
  {
    StrLFmt(SourceBuffer, SourceBufferSize, Fmt, Args, Args_Size);
    Stream->Write(SourceBuffer, strlen(SourceBuffer));
  }
} // end of TDlgExpert::FmtWrite()

//***************************************************************
void __stdcall DialogExpert(TIToolServices *ToolServices)
{
  TDlgExpert     *D;
  TIMemoryStream *ISourceStream;
  TIMemoryStream *IHdrStream;
  TIMemoryStream *IFormStream;
  String                   UnitIdent;
  String                   FormIdent;

  // If we were not pass a toolservices object, forget it.
  if (!ToolServices) exit(1);

  try {
    auto_ptr<TFileName> FileName(new TFileName);

    // If we can get a name set for the new dialog box...
    if (ToolServices->GetNewModuleName(UnitIdent, *FileName)) {
      try
      {
        // ...allocate the dialog expert and set the path for the
        // dialog box files.
        D = new TDlgExpert(Application);

        // Display the dialog expert dialog box modally. If we
        // come back with a go...
        if (D->ShowModal() == mrOK) {

          // ...make everything but the first letter of the unit
          // name lowercase.
          UnitIdent.LowerCase();
          UnitIdent[1] &= 0x5F ;

          // The form's file name is dependent on the button
          // orientation and we add a number to the end to reduce
          // name conflict when several dialogs are created in
          // quick succession.
          FormIdent = "Form" + UnitIdent.SubString(5, 255);

          // Get a stream for the form (name.DFM),...
          try
          {
            IFormStream = new TIMemoryStream(D->CreateForm(FormIdent), soReference);
            try
            {
              // ...the source file (name.CPP) and...
              ISourceStream = new TIMemoryStream(D->CreateSource(UnitIdent, FormIdent), soReference);
              try {

                // ...the header file (name.H).
                IHdrStream = new TIMemoryStream(D->CreateHdrSource(UnitIdent,
                                                       FormIdent),soReference);

                // Setup the create flags and...
                TCreateModuleFlags CreateFlags;
                CreateFlags << cmAddToProject << cmShowSource
                            << cmShowForm << cmUnNamed
                            << cmMarkModified;

                // ...create the dialog box source set.
                IStream * Hdr = *IHdrStream;
                IStream * Source = *ISourceStream;
                IStream * Form = *IFormStream;  
                ToolServices->CreateCppModule(*FileName, "", "", "",
                                              Hdr,
                                              Source,
                                              Form,
                                              CreateFlags);
              } catch(...)
              {
                delete IHdrStream;
              }
            } catch(...)
            {
              delete IHdrStream;
            }
          } catch(...)
          {
              delete IFormStream;
          }

        }
      } catch(...)
      {
        delete D;
      }
    }
  } catch(...)
  {
  }

  delete D;
} // end of DialogExpert()

//---------------------------------------------------------------

