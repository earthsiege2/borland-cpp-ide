//----------------------------------------------------------------------------
//Borland C++Builder
//Copyright (c) 1987, 1998-2002 Borland International Inc. All Rights Reserved.
//----------------------------------------------------------------------------
//---------------------------------------------------------------------------
//	Demostrates how to execute a query in a background thread.  This
//  files contains the main user interface for this program.  The background
//  query code is in ResltFrm.
//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "QueryFrm.h"
#include "bkstring.rc"
#include <stdio.h>
//---------------------------------------------------------------------------
#pragma resource "*.dfm"
TAdhocForm *AdhocForm;

AnsiString StrToIniStr(const AnsiString Str)
{
  char Buffer[4096];
  PChar B, S;

  if (Str.Length() > sizeof(Buffer))
  	throw Exception("AnsiString too large to save in INI file");
  S = Str.c_str();
  B = Buffer;
  while (*S != '\0')
  {
  	switch (*S)
     {
     	case 13:
        case 10:
           if ((*S == 13) && (S[1] == 10)) S++;
           else if ((*S == 10) && (S[1] == 13)) S++;
           *B = '\\';
           B++;
           *B = 'n';
           B++;
           S++;
           break;
        default:
      		*B = *S;
      		B++;
      		S++;
     }
  }
  *B = '\0';
  return String(Buffer);
}

String IniStrToStr(const String Str)
{
  char Buffer[4096];
  PChar B, S;

  if (Str.Length() > sizeof(Buffer))
  	throw Exception("String to read from an INI file");
  S = Str.c_str();
  B = Buffer;
  while (*S != '\0')
  {
    if ((S[0] == '\\') && (S[1] == 'n'))
    {
      *B = 13;
      B++;
      *B = 10;
      B++;
      S++;
      S++;
    }
    else
    {
      *B = *S;
      B++;
      S++;
    }
  }
  *B = '\0';
  return String(Buffer);
}

//---------------------------------------------------------------------------
__fastcall TAdhocForm::TAdhocForm(TComponent* Owner)
  : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TAdhocForm::FormCloseQuery(TObject *Sender,
      Boolean &CanClose)
{
  CanClose = CheckModified();
}
//---------------------------------------------------------------------

Boolean __fastcall TAdhocForm::IsModified(void)
{
  return ((AliasCombo->Text != OldAlias) || NameEdit->Modified ||
    QueryEdit->Modified);
}

//---------------------------------------------------------------------
Boolean  __fastcall TAdhocForm::CheckModified(void)
{
//  char szTemp[256];
  Boolean Result = true;

//  sprintf(szTemp, "Query %s has been modified. Save?", QueryName);
  String Str = "Query " + QueryName + " has been modified. Save?";
  if (IsModified())
  	switch (MessageDlg(Str,
                       mtConfirmation,
     	               TMsgDlgButtons() << mbYes << mbNo << mbCancel,
                       0)){
      case mrOk:
        SaveQuery();
        break;
      case mrCancel:
        Result = false;
        break;
    }
  return Result;
}

//---------------------------------------------------------------------
void __fastcall TAdhocForm::Unmodify(void)
{
  OldAlias = AliasCombo->Text;
  NameEdit->Modified = false;
  QueryEdit->Modified = false;
}

//---------------------------------------------------------------------
void __fastcall TAdhocForm::ReadQuery(void)
{
  if (!CheckModified()) return;
  QueryName = SavedQueryCombo->Items->Strings[SavedQueryCombo->ItemIndex];
  QueryEdit->Text = IniStrToStr(SavedQueries->ReadString(QueryName, "Query", ""));
  AliasCombo->Text = SavedQueries->ReadString(QueryName, "Alias", "");
  NameEdit->Text = SavedQueries->ReadString(QueryName, "Name", "");
 	Unmodify();
  if (Showing)
    if (NameEdit->Text != "")
      PasswordEdit->SetFocus();
    else
      QueryEdit->SetFocus();
}

//---------------------------------------------------------------------
void __fastcall TAdhocForm::SaveQuery(void)
{
  if (Unnamed)
    SaveQueryAs();
  else
  {
      SavedQueries->WriteString(QueryName, "Query", StrToIniStr(QueryEdit->Text));
      SavedQueries->WriteString(QueryName, "Alias", AliasCombo->Text);
      SavedQueries->WriteString(QueryName, "Name", NameEdit->Text);
      Unmodify();
  }
}

void __fastcall TAdhocForm::SaveQueryAs(void)
{
  if (GetNewName(QueryName)){
     Unnamed = false;
     SaveQuery();
     if (SavedQueryCombo->Items->IndexOf(QueryName) < 0)
         SavedQueryCombo->Items->Add(QueryName);
     SavedQueryCombo->ItemIndex = SavedQueryCombo->Items->IndexOf(QueryName);
  }
}

//---------------------------------------------------------------------
void __fastcall TAdhocForm::FormDestroy(TObject *Sender)
{
  delete SavedQueries;
}

//---------------------------------------------------------------------
void __fastcall TAdhocForm::FormCreate(TObject *Sender)
{

  // Grab session aliases
  Session->GetAliasNames(AliasCombo->Items);

  // Load in saved queries
  SavedQueries = new TIniFile(".\\BKQUERY.INI");
  SavedQueries->ReadSections(SavedQueryCombo->Items);
  if (SavedQueryCombo->Items->Count <= 0)
     CreateInitialIni();
  SavedQueryCombo->ItemIndex = 0;
  QueryName = SavedQueryCombo->Items->Strings[0];
  Unmodify();
  ReadQuery();
}
//---------------------------------------------------------------------
// CreateInitialIni
//Creates initial INI file when one doesn't already exist
void __fastcall TAdhocForm::CreateInitialIni()
{
  //Load first SQL query text and add it to the combo box
  char szQueryName[64];
  LoadString((HINSTANCE)HInstance,
             IDS_VeryInefficientName,
             szQueryName,
             sizeof(szQueryName));
  HGLOBAL hSQLQuery =  LoadResource((HINSTANCE)HInstance,
                                    FindResource((HINSTANCE)HInstance,
                                                 MAKEINTRESOURCE(IDSQLQUERY_VeryInefficientQuery),
                                                 "SQLQUERY1"));
  char* pszSQLQuery = (char*)LockResource(hSQLQuery);
  SavedQueries->WriteString(szQueryName, "Query", StrToIniStr(pszSQLQuery));
  SavedQueries->WriteString(szQueryName, "Alias", "IBLOCAL");
  SavedQueries->WriteString(szQueryName, "Name", "SYSDBA");
  SavedQueryCombo->Items->Add(szQueryName);

  //Load next SQL query text and add it to the combo box
  LoadString((HINSTANCE)HInstance, IDS_AmountDueName, szQueryName, sizeof(szQueryName));
  hSQLQuery =  LoadResource((HINSTANCE)HInstance,
                            FindResource((HINSTANCE)HInstance,
                                         MAKEINTRESOURCE(IDSQLQUERY_AmountDueByCustomer),
                                         "SQLQUERY2"));
  pszSQLQuery = (char*)LockResource(hSQLQuery);
  SavedQueries->WriteString(szQueryName, "Query", StrToIniStr(pszSQLQuery));
  SavedQueries->WriteString(szQueryName, "Alias", "BCDEMOS");
  SavedQueries->WriteString(szQueryName, "Name", "");
  SavedQueryCombo->Items->Add(szQueryName);
}
//---------------------------------------------------------------------

void __fastcall TAdhocForm::ExecuteBtnClick(TObject *Sender)
{
  BackgroundQuery(QueryName,
                  AliasCombo->Text,
                  NameEdit->Text,
                  PasswordEdit->Text,
                  QueryEdit->Text);
  BringToFront();
}
//---------------------------------------------------------------------

String __fastcall TAdhocForm::UniqueName()
{
  int I;
  String result;
  I = 1;
  do
    result.Format("Query%d", ARRAYOFCONST((I)));
  while(SavedQueryCombo->Items->IndexOf(result) >= 0);
  return result;
}
//---------------------------------------------------------------------

void __fastcall TAdhocForm::NewBtnClick(TObject *Sender)
{
  AliasCombo->Text = "BCDEMOS";
  NameEdit->Text = "";
  PasswordEdit->Text = "";
  QueryEdit->Text = "";
  QueryEdit->SetFocus();
  QueryName = UniqueName();
  SavedQueryCombo->ItemIndex = -1;
  Unnamed = true;
}
//---------------------------------------------------------------------
void __fastcall TAdhocForm::SaveBtnClick(TObject *Sender)
{
  SaveQuery();
}
//---------------------------------------------------------------------
void __fastcall TAdhocForm::SaveAsBtnClick(TObject *Sender)
{
  SaveQueryAs();
}
//---------------------------------------------------------------------
void __fastcall TAdhocForm::CloseBtnClick(TObject *Sender)
{
  Close();
}
//---------------------------------------------------------------------
void __fastcall TAdhocForm::SavedQueryComboChange(TObject *Sender)
{
  ReadQuery();
}
//---------------------------------------------------------------------
