// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'SqlEdit.pas' rev: 6.00

#ifndef SqlEditHPP
#define SqlEditHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <ExtCtrls.hpp>	// Pascal unit
#include <StdCtrls.hpp>	// Pascal unit
#include <Graphics.hpp>	// Pascal unit
#include <Controls.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <Forms.hpp>	// Pascal unit
#include <SysUtils.hpp>	// Pascal unit
#include <ActiveX.hpp>	// Pascal unit
#include <Messages.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Sqledit
{
//-- type declarations -------------------------------------------------------
typedef void __fastcall (__closure *TExecuteEvent)(void);

class DELPHICLASS TPopulateThread;
class PASCALIMPLEMENTATION TPopulateThread : public Classes::TThread 
{
	typedef Classes::TThread inherited;
	
private:
	TExecuteEvent FExecuteEvent;
	
public:
	__fastcall TPopulateThread(TExecuteEvent ExecuteEvent);
	virtual void __fastcall Execute(void);
public:
	#pragma option push -w-inl
	/* TThread.Destroy */ inline __fastcall virtual ~TPopulateThread(void) { }
	#pragma option pop
	
};


typedef void __fastcall (__closure *TGetTableNamesProc)(Classes::TStrings* List, bool SystemTables);

typedef void __fastcall (__closure *TGetFieldNamesProc)(const AnsiString TableName, Classes::TStrings* List);

typedef bool __fastcall (__closure *TRequiresQuoteCharProc)(const AnsiString Name);

class DELPHICLASS TSQLEditForm;
class PASCALIMPLEMENTATION TSQLEditForm : public Forms::TForm 
{
	typedef Forms::TForm inherited;
	
__published:
	Stdctrls::TButton* OkButton;
	Stdctrls::TButton* HelpButton;
	Stdctrls::TButton* CancelButton;
	Stdctrls::TButton* AddFieldButton;
	Stdctrls::TButton* AddTableButton;
	Stdctrls::TLabel* SQLLabel;
	Stdctrls::TLabel* FieldListLabel;
	Stdctrls::TLabel* TableListLabel;
	Extctrls::TPanel* TopPanel;
	Extctrls::TPanel* ButtonPanel;
	Extctrls::TPanel* FieldsPanel;
	Extctrls::TPanel* MetaInfoPanel;
	Extctrls::TPanel* TableListPanel;
	Extctrls::TSplitter* TableFieldsSplitter;
	Extctrls::TSplitter* MetaInfoSQLSplitter;
	Stdctrls::TMemo* SQLMemo;
	Extctrls::TImage* Image1;
	Stdctrls::TListBox* TableList;
	Stdctrls::TListBox* FieldList;
	void __fastcall FormShow(System::TObject* Sender);
	void __fastcall HelpButtonClick(System::TObject* Sender);
	void __fastcall TableFieldsSplitterCanResize(System::TObject* Sender, int &NewSize, bool &Accept);
	void __fastcall MetaInfoSQLSplitterCanResize(System::TObject* Sender, int &NewSize, bool &Accept);
	void __fastcall MetaInfoSQLSplitterMoved(System::TObject* Sender);
	void __fastcall TableListClick(System::TObject* Sender);
	void __fastcall AddTableButtonClick(System::TObject* Sender);
	void __fastcall AddFieldButtonClick(System::TObject* Sender);
	void __fastcall SQLMemoExit(System::TObject* Sender);
	void __fastcall FormDestroy(System::TObject* Sender);
	void __fastcall SQLMemoEnter(System::TObject* Sender);
	
private:
	int CharHeight;
	AnsiString FQuoteChar;
	TPopulateThread* FPopulateThread;
	AnsiString FStartTable;
	TGetTableNamesProc GetTableNames;
	TGetFieldNamesProc GetFieldNames;
	Controls::TControlCanvas* SQLCanvas;
	void __fastcall InsertText(AnsiString Text, bool AddComma = true);
	void __fastcall DrawCaretPosIndicator(void);
	void __fastcall PopulateTableList(void);
	void __fastcall PopulateFieldList(void);
	
protected:
	TRequiresQuoteCharProc NameRequiresQuoteChar;
	__property AnsiString QuoteChar = {read=FQuoteChar, write=FQuoteChar};
	__property AnsiString StartTable = {read=FStartTable, write=FStartTable};
public:
	#pragma option push -w-inl
	/* TCustomForm.Create */ inline __fastcall virtual TSQLEditForm(Classes::TComponent* AOwner) : Forms::TForm(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.CreateNew */ inline __fastcall virtual TSQLEditForm(Classes::TComponent* AOwner, int Dummy) : Forms::TForm(AOwner, Dummy) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.Destroy */ inline __fastcall virtual ~TSQLEditForm(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TSQLEditForm(HWND ParentWindow) : Forms::TForm(ParentWindow) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------
extern PACKAGE bool __fastcall EditSQL(AnsiString &SQL, TGetTableNamesProc AGetTableNames, TGetFieldNamesProc AGetFieldNames, AnsiString AStartTblName = "", AnsiString AQuoteChar = "", TRequiresQuoteCharProc ANeedsQuoteCharFunc = 0x0)/* overload */;
extern PACKAGE bool __fastcall EditSQL(Classes::TStrings* SQL, TGetTableNamesProc AGetTableNames, TGetFieldNamesProc AGetFieldNames, AnsiString AStartTblName = "", AnsiString AQuoteChar = "", TRequiresQuoteCharProc ANeedsQuoteCharFunc = 0x0)/* overload */;
extern PACKAGE bool __fastcall DefaultReqQuoteChar(AnsiString Name);

}	/* namespace Sqledit */
using namespace Sqledit;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// SqlEdit
