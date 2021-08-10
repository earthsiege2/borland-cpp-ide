// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Updsqled.pas' rev: 6.00

#ifndef UpdsqledHPP
#define UpdsqledHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <Menus.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <SysUtils.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <ComCtrls.hpp>	// Pascal unit
#include <Controls.hpp>	// Pascal unit
#include <StdCtrls.hpp>	// Pascal unit
#include <ExtCtrls.hpp>	// Pascal unit
#include <DBTables.hpp>	// Pascal unit
#include <DB.hpp>	// Pascal unit
#include <Forms.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Updsqled
{
//-- type declarations -------------------------------------------------------
typedef void __fastcall (__closure *TWaitMethod)(void);

class DELPHICLASS TUpdateSQLEditForm;
class PASCALIMPLEMENTATION TUpdateSQLEditForm : public Forms::TForm 
{
	typedef Forms::TForm inherited;
	
__published:
	Stdctrls::TButton* OkButton;
	Stdctrls::TButton* CancelButton;
	Stdctrls::TButton* HelpButton;
	Stdctrls::TButton* GenerateButton;
	Stdctrls::TButton* PrimaryKeyButton;
	Stdctrls::TButton* DefaultButton;
	Stdctrls::TComboBox* UpdateTableName;
	Comctrls::TTabSheet* FieldsPage;
	Comctrls::TTabSheet* SQLPage;
	Comctrls::TPageControl* PageControl;
	Stdctrls::TListBox* KeyFieldList;
	Stdctrls::TListBox* UpdateFieldList;
	Stdctrls::TGroupBox* GroupBox1;
	Stdctrls::TLabel* Label1;
	Stdctrls::TMemo* SQLMemo;
	Dbtables::TTable* FTempTable;
	Extctrls::TRadioGroup* StatementType;
	Stdctrls::TCheckBox* QuoteFields;
	Stdctrls::TButton* GetTableFieldsButton;
	Menus::TPopupMenu* FieldListPopup;
	Menus::TMenuItem* miSelectAll;
	Menus::TMenuItem* miClearAll;
	void __fastcall FormCreate(System::TObject* Sender);
	void __fastcall HelpButtonClick(System::TObject* Sender);
	void __fastcall StatementTypeClick(System::TObject* Sender);
	void __fastcall OkButtonClick(System::TObject* Sender);
	void __fastcall DefaultButtonClick(System::TObject* Sender);
	void __fastcall GenerateButtonClick(System::TObject* Sender);
	void __fastcall PrimaryKeyButtonClick(System::TObject* Sender);
	void __fastcall PageControlChanging(System::TObject* Sender, bool &AllowChange);
	void __fastcall FormDestroy(System::TObject* Sender);
	void __fastcall GetTableFieldsButtonClick(System::TObject* Sender);
	void __fastcall SettingsChanged(System::TObject* Sender);
	void __fastcall FormCloseQuery(System::TObject* Sender, bool &CanClose);
	void __fastcall UpdateTableNameChange(System::TObject* Sender);
	void __fastcall UpdateTableNameClick(System::TObject* Sender);
	void __fastcall SelectAllClick(System::TObject* Sender);
	void __fastcall ClearAllClick(System::TObject* Sender);
	void __fastcall SQLMemoKeyPress(System::TObject* Sender, char &Key);
	
private:
	int StmtIndex;
	Dbtables::TDBDataSet* DataSet;
	Dbtables::TDatabase* Database;
	bool DatabaseOpened;
	Dbtables::TUpdateSQL* UpdateSQL;
	bool FSettingsChanged;
	bool FDatasetDefaults;
	Classes::TStrings* SQLText[3];
	AnsiString __fastcall GetTableRef(const AnsiString TabName, const AnsiString QuoteChar);
	bool __fastcall DatabaseOpen(void);
	bool __fastcall Edit(void);
	void __fastcall GenWhereClause(const AnsiString TabAlias, const AnsiString QuoteChar, Classes::TStrings* KeyFields, Classes::TStrings* SQL);
	void __fastcall GenDeleteSQL(const AnsiString TableName, const AnsiString QuoteChar, Classes::TStrings* KeyFields, Classes::TStrings* SQL);
	void __fastcall GenInsertSQL(const AnsiString TableName, const AnsiString QuoteChar, Classes::TStrings* UpdateFields, Classes::TStrings* SQL);
	void __fastcall GenModifySQL(const AnsiString TableName, const AnsiString QuoteChar, Classes::TStrings* KeyFields, Classes::TStrings* UpdateFields, Classes::TStrings* SQL);
	void __fastcall GenerateSQL(void);
	void __fastcall GetDataSetFieldNames(void);
	void __fastcall GetTableFieldNames(void);
	void __fastcall InitGenerateOptions(void);
	void __fastcall InitUpdateTableNames(void);
	void __fastcall SetButtonStates(void);
	void __fastcall SelectPrimaryKeyFields(void);
	void __fastcall SetDefaultSelections(void);
	void __fastcall ShowWait(TWaitMethod WaitMethod);
	Dbtables::TTable* __fastcall TempTable(void);
public:
	#pragma option push -w-inl
	/* TCustomForm.Create */ inline __fastcall virtual TUpdateSQLEditForm(Classes::TComponent* AOwner) : Forms::TForm(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.CreateNew */ inline __fastcall virtual TUpdateSQLEditForm(Classes::TComponent* AOwner, int Dummy) : Forms::TForm(AOwner, Dummy) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.Destroy */ inline __fastcall virtual ~TUpdateSQLEditForm(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TUpdateSQLEditForm(HWND ParentWindow) : Forms::TForm(ParentWindow) { }
	#pragma option pop
	
};


#pragma option push -b-
enum TSQLToken { stSymbol, stAlias, stNumber, stComma, stEQ, stOther, stLParen, stRParen, stEnd };
#pragma option pop

class DELPHICLASS TSQLParser;
class PASCALIMPLEMENTATION TSQLParser : public System::TObject 
{
	typedef System::TObject inherited;
	
private:
	AnsiString FText;
	char *FSourcePtr;
	char *FTokenPtr;
	AnsiString FTokenString;
	TSQLToken FToken;
	bool FSymbolQuoted;
	TSQLToken __fastcall NextToken(void);
	bool __fastcall TokenSymbolIs(const AnsiString S);
	void __fastcall Reset(void);
	
public:
	__fastcall TSQLParser(const AnsiString Text);
	void __fastcall GetSelectTableNames(Classes::TStrings* List);
	void __fastcall GetUpdateTableName(AnsiString &TableName);
	void __fastcall GetUpdateFields(Classes::TStrings* List);
	void __fastcall GetWhereFields(Classes::TStrings* List);
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TSQLParser(void) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------
extern PACKAGE bool __fastcall EditUpdateSQL(Dbtables::TUpdateSQL* AUpdateSQL);

}	/* namespace Updsqled */
using namespace Updsqled;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// Updsqled
