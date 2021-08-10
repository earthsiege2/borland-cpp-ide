//---------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "About.h"
#include "LogoMain.h"
#include "LogoStrs.h"
#include "MAPI.hpp"
//---------------------------------------------------------------------------
#pragma resource "*.dfm"
TLogoAppForm *LogoAppForm;
//---------------------------------------------------------------------------

__fastcall TLogoAppForm::TLogoAppForm(TComponent *Owner)
	: TForm(Owner)
{
        FileNew1->Execute(); /* sets the default file name and clears the RichEdit Control */
}
//---------------------------------------------------------------------------

void __fastcall TLogoAppForm::FileNew1Execute(TObject *Sender)
{
	FFileName = LoadStr(sUntitled);
	RichEdit1->Lines->Clear();
	RichEdit1->Modified = false;
}
//---------------------------------------------------------------------------

void __fastcall TLogoAppForm::FileOpen1Execute(TObject *Sender)
{
	if (OpenDialog->Execute())
	{
		RichEdit1->Lines->LoadFromFile(OpenDialog->FileName);
		FFileName = OpenDialog->FileName;
		RichEdit1->SetFocus();
		RichEdit1->Modified = false;
		RichEdit1->ReadOnly = OpenDialog->Options.Contains(ofReadOnly);
	}
}
//---------------------------------------------------------------------------

void __fastcall TLogoAppForm::FileSave1Execute(TObject *Sender)
{
	if (FFileName == LoadStr(sUntitled))
		FileSaveAs1Execute(Sender);
	else
	{
		RichEdit1->Lines->SaveToFile(FFileName);
		RichEdit1->Modified = false;
	}
}
//---------------------------------------------------------------------------

void __fastcall TLogoAppForm::FileSaveAs1Execute(TObject *Sender)
{
	String str;
	TVarRec vrs[1];

	if (SaveDialog->Execute())
	{
		if (FileExists(SaveDialog->FileName))
		{
			str = FmtLoadStr(sOverwrite, OPENARRAY(TVarRec, (SaveDialog->FileName)));
			if (MessageDlg(str, mtConfirmation, TMsgDlgButtons() << mbYes << mbNo <<
				mbCancel, 0) != IDYES)
				return;
		}
		RichEdit1->Lines->SaveToFile(SaveDialog->FileName);
		FFileName = SaveDialog->FileName;
		RichEdit1->Modified = false;
	}
}
//---------------------------------------------------------------------------

void __fastcall TLogoAppForm::FileSend1Execute(TObject *Sender)
{
	TMapiMessage MapiMessage;
	Cardinal MError;

	MapiMessage.ulReserved = 0;
	MapiMessage.lpszSubject = NULL;
	MapiMessage.lpszNoteText = RichEdit1->Lines->Text.c_str();
	MapiMessage.lpszMessageType = NULL;
	MapiMessage.lpszDateReceived = NULL;
	MapiMessage.lpszConversationID = NULL;
	MapiMessage.flFlags = 0;
	MapiMessage.lpOriginator = NULL;
	MapiMessage.nRecipCount = 0;
	MapiMessage.lpRecips = NULL;
	MapiMessage.nFileCount = 0;
	MapiMessage.lpFiles = NULL;

	MError = MapiSendMail(0, reinterpret_cast<unsigned int>(Application->Handle), 
                 MapiMessage, MAPI_DIALOG | MAPI_LOGON_UI | MAPI_NEW_SESSION, 0);
	if (MError)
		MessageDlg(LoadStr(sSendError), mtError, TMsgDlgButtons() << mbOK, 0);
}
//---------------------------------------------------------------------------

void __fastcall TLogoAppForm::FileExit1Execute(TObject *Sender)
{
	Close();
}
//---------------------------------------------------------------------------

void __fastcall TLogoAppForm::HelpAbout1Execute(TObject *Sender)
{
	AboutBox->ShowModal();
}
//---------------------------------------------------------------------------

