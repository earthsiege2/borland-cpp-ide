//---------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "About.h"
#include "W2kMain.h"
#include "W2kStrs.h"
#include "MAPI.hpp"
#include <shfolder.h>
//---------------------------------------------------------------------------
#pragma resource "*.dfm"
TWin2kAppForm *Win2kAppForm;
//---------------------------------------------------------------------------
const AnsiString sShouldSave = "Save changes?";
//---------------------------------------------------------------------------

__fastcall TWin2kAppForm::TWin2kAppForm(TComponent *Owner)
	: TForm(Owner)
{
        FileNew1->Execute(); /* sets the default file name and clears the RichEdit Control */
}

//---------------------------------------------------------------------------
AnsiString DefaultSaveLocation(void)
{
  char *P;
  AnsiString Result;
  /*
    returns the location of 'My Documents' if it exists, otherwise it returns
    the current directory.
  */
  __try
  {
    P = (char *)malloc(MAX_PATH);
    if (SHGetFolderPath(0, CSIDL_PERSONAL, 0, 0, P) != S_OK)
      P = GetCurrentDir().c_str();
  }
  __finally
  {
    Result = P;
    free(P);
    return Result;
  }
};
//---------------------------------------------------------------------------

bool __fastcall TWin2kAppForm::FileSave(bool ChangeName)
{
	String str;
	TVarRec vrs[1];

        if (!ChangeName)
        {
	        	RichEdit1->Lines->SaveToFile(SaveDialog->FileName);
        		RichEdit1->Modified = false;
        }
        else
        {
                SaveDialog->FileName = FFileName;
	        if (SaveDialog->Execute())
        	{
	        	if (FileExists(SaveDialog->FileName))
		        {
			        str = FmtLoadStr(sOverwrite, OPENARRAY(TVarRec, (SaveDialog->FileName)));
        			if (MessageDlg(str, mtConfirmation, TMsgDlgButtons() << mbYes << mbNo <<
	        			mbCancel, 0) != IDYES)
		        		return false;
        		}
	        	RichEdit1->Lines->SaveToFile(SaveDialog->FileName);
		        FFileName = SaveDialog->FileName;
        		RichEdit1->Modified = false;
	        }
        }
        return true;
};

//---------------------------------------------------------------------------
void __fastcall TWin2kAppForm::FileNew1Execute(TObject *Sender)
{
        SaveDialog->InitialDir = DefaultSaveLocation();
	FFileName = LoadStr(sUntitled);
	RichEdit1->Lines->Clear();
	RichEdit1->Modified = false;
}
//---------------------------------------------------------------------------

void __fastcall TWin2kAppForm::FileOpen1Execute(TObject *Sender)
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

void __fastcall TWin2kAppForm::FileSave1Execute(TObject *Sender)
{
  FileSave(FFileName == LoadStr(sUntitled));
}
//---------------------------------------------------------------------------

void __fastcall TWin2kAppForm::FileSaveAs1Execute(TObject *Sender)
{
  FileSave(true);
}
//---------------------------------------------------------------------------

void __fastcall TWin2kAppForm::FileSend1Execute(TObject *Sender)
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

void __fastcall TWin2kAppForm::FileExit1Execute(TObject *Sender)
{
	Close();
}
//---------------------------------------------------------------------------

void __fastcall TWin2kAppForm::HelpAbout1Execute(TObject *Sender)
{
	AboutBox->ShowModal();
}
//---------------------------------------------------------------------------


void __fastcall TWin2kAppForm::FormCloseQuery(TObject *Sender,
      bool &CanClose)
{
	TMsgDlgButtons Buttons;	
	TModalResult mr;

	if (RichEdit1->Modified)
	{
        	Buttons << mbYes << mbNo << mbCancel;
		mr = MessageDlg(sShouldSave, mtWarning, Buttons, 0);
		switch (mr)
		{
			default: return;
			case mrCancel: CanClose = False; break;
			case mrYes: FileSave1->Execute(); break;
		}
	}
}
//---------------------------------------------------------------------------

