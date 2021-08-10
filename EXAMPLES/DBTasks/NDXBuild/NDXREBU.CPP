//----------------------------------------------------------------------------
//Borland C++Builder
//Copyright (c) 1987, 1998 Borland International Inc. All Rights Reserved.
//----------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "ndxrebu.h"
//---------------------------------------------------------------------------
#pragma resource "*.dfm"
TFormMain *FormMain;
//---------------------------------------------------------------------------
__fastcall TFormMain::TFormMain(TComponent* Owner)
  : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFormMain::FormCreate(TObject *Sender)
{

  // Set up the exception handler.
  Application->OnException = HandleExceptions;

  // Populate the Alias drop down with the currently defined aliases.
  Screen->Cursor = crHourGlass;
  try {
    Session->GetAliasNames(cbAlias->Items);
    cbAlias->ItemIndex = 0;
  }
  catch (...) {}  // dummy catch block to guarantee we get here.
  Screen->Cursor = crDefault;

  // Now, get the table name for the first index in the list.
  cbAliasChange(NULL);
}
//---------------------------------------------------------------------

void __fastcall TFormMain::HandleExceptions(TObject *Sender, Exception *E)
{
  if (E->Message.Length())
  {
    Screen->Cursor = crArrow;
    MessageDlg(E->Message, mtError, TMsgDlgButtons() << mbOK, 0);
  }
}

void __fastcall TFormMain::cbAliasChange(TObject *Sender)
{
  // Get the tables in the new index.
  Screen->Cursor = crHourGlass;
  try {
    Session->GetTableNames(cbAlias->Items->Strings[cbAlias->ItemIndex],
        "", True, False, cbTable->Items);
    cbTable->Items->Insert(0, "<All Tables>");
    cbTable->ItemIndex = 0;
  }
  catch (...) {}  // dummy catch block to guarantee we get here.
  Screen->Cursor = crDefault;
}
//---------------------------------------------------------------------
void __fastcall TFormMain::BitBtn1Click(TObject *Sender)
{
  AnsiString strTable;
  int Counter;
  int iNTables;
  AnsiString strError;
  char strMsg[1024];

  strError = "";
	if (cbTable->ItemIndex > 0)
  {
    if (!RebuildIndexes(cbAlias->Items->Strings[cbAlias->ItemIndex],
        cbTable->Items->Strings[cbTable->ItemIndex],
        strError)) {
		wsprintf(strMsg,
                 "Unable to rebuild indexes for %s. Reason: %s",
      	         cbTable->Items->Strings[cbTable->ItemIndex].c_str(),
                 strError.c_str());
      	MessageDlg(strMsg, mtError, TMsgDlgButtons() << mbOK, 0);
    }
  }
  else
  {
  	iNTables = cbTable->Items->Count;
     for (Counter = 1; Counter <= cbTable->Items->Count - 1; Counter++)     {
     	StatusBar1->Panels->Items[1]->Text = AnsiString(iNTables - Counter);
        StatusBar1->Update();
        if (!RebuildIndexes(cbAlias->Items->Strings[cbAlias->ItemIndex],
        	                cbTable->Items->Strings[Counter],
                            strError)){
           wsprintf(strMsg,
                    "Unable to rebuild indexes for %s. Reason: %s",
                    cbTable->Items->Strings[Counter].c_str(),
                    strError.c_str());
           MessageDlg(strMsg, mtError, TMsgDlgButtons() << mbOK, 0 );
        }
      }
      StatusBar1->Panels->Items[1]->Text = " ";
      StatusBar1->Update();
  }
}
//---------------------------------------------------------------------

bool __fastcall TFormMain::RebuildIndexes(AnsiString strAlias, AnsiString strTable,
    AnsiString& strError)
{
  bool Result = False;
	DBIResult bdeResult;

  if (tblIndex-> Active) tblIndex->Active = False;

  tblIndex->DatabaseName = strAlias;
  tblIndex->TableName = strTable;

  Screen->Cursor = crHourGlass;
  try {
    WriteMsg("Opening " + strTable + "...");
    tblIndex->Open();
  }
  catch (...) {}
  Screen->Cursor = crDefault;

  if (!tblIndex->Active)
    strError = "The table could not be opened exclusively.  It is " \
    				 "probably being used by another user or application.";
  else {
    WriteMsg("Regenerating indexes for " + strTable + "...");
    Screen->Cursor = crHourGlass;
    try {
      bdeResult = DbiRegenIndexes(tblIndex->Handle);
      switch (bdeResult) {
        case DBIERR_NONE: Result = True; break;
        case DBIERR_INVALIDHNDL: strError = "Invalid table handle."; break;
        case DBIERR_NEEDEXCLACCESS: strError = "Table is open in shared mode."; break;
        case DBIERR_NOTSUPPORTED: strError = "Remote indexes cannot be rebuilt."; break;
      	default: strError = "Unexpected Error Returned by BDE.";
      }
    }
    catch (...) {}
    Screen->Cursor = crDefault;
  }
  WriteMsg("");
  return Result;
}

void __fastcall TFormMain::WriteMsg(AnsiString strWrite)
{
  StatusBar1->Panels->Items[0]->Text = strWrite;
  StatusBar1->Update();
}
