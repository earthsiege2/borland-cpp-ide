// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'MXDSSQRY.pas' rev: 6.00

#ifndef MXDSSQRYHPP
#define MXDSSQRYHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <DesignIntf.hpp>	// Pascal unit
#include <MXQPARSE.hpp>	// Pascal unit
#include <MXTABLES.hpp>	// Pascal unit
#include <Mxstore.hpp>	// Pascal unit
#include <MXCOMMON.hpp>	// Pascal unit
#include <MXDB.hpp>	// Pascal unit
#include <MXGRID.hpp>	// Pascal unit
#include <Mxconsts.hpp>	// Pascal unit
#include <Menus.hpp>	// Pascal unit
#include <ComCtrls.hpp>	// Pascal unit
#include <Buttons.hpp>	// Pascal unit
#include <ExtCtrls.hpp>	// Pascal unit
#include <Forms.hpp>	// Pascal unit
#include <Grids.hpp>	// Pascal unit
#include <DBTables.hpp>	// Pascal unit
#include <DB.hpp>	// Pascal unit
#include <Graphics.hpp>	// Pascal unit
#include <StdCtrls.hpp>	// Pascal unit
#include <Controls.hpp>	// Pascal unit
#include <Dialogs.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <SysUtils.hpp>	// Pascal unit
#include <Messages.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Mxdssqry
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS ECubeDesignError;
class PASCALIMPLEMENTATION ECubeDesignError : public Sysutils::Exception 
{
	typedef Sysutils::Exception inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall ECubeDesignError(const AnsiString Msg) : Sysutils::Exception(Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall ECubeDesignError(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size) : Sysutils::Exception(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall ECubeDesignError(int Ident)/* overload */ : Sysutils::Exception(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall ECubeDesignError(int Ident, const System::TVarRec * Args, const int Args_Size)/* overload */ : Sysutils::Exception(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall ECubeDesignError(const AnsiString Msg, int AHelpContext) : Sysutils::Exception(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall ECubeDesignError(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size, int AHelpContext) : Sysutils::Exception(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall ECubeDesignError(int Ident, int AHelpContext)/* overload */ : Sysutils::Exception(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall ECubeDesignError(System::PResStringRec ResStringRec, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : Sysutils::Exception(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~ECubeDesignError(void) { }
	#pragma option pop
	
};


class DELPHICLASS EAddWarning;
class PASCALIMPLEMENTATION EAddWarning : public Sysutils::Exception 
{
	typedef Sysutils::Exception inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall EAddWarning(const AnsiString Msg) : Sysutils::Exception(Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EAddWarning(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size) : Sysutils::Exception(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EAddWarning(int Ident)/* overload */ : Sysutils::Exception(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EAddWarning(int Ident, const System::TVarRec * Args, const int Args_Size)/* overload */ : Sysutils::Exception(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EAddWarning(const AnsiString Msg, int AHelpContext) : Sysutils::Exception(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EAddWarning(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size, int AHelpContext) : Sysutils::Exception(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EAddWarning(int Ident, int AHelpContext)/* overload */ : Sysutils::Exception(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EAddWarning(System::PResStringRec ResStringRec, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : Sysutils::Exception(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EAddWarning(void) { }
	#pragma option pop
	
};


class DELPHICLASS EAddError;
class PASCALIMPLEMENTATION EAddError : public Sysutils::Exception 
{
	typedef Sysutils::Exception inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall EAddError(const AnsiString Msg) : Sysutils::Exception(Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EAddError(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size) : Sysutils::Exception(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EAddError(int Ident)/* overload */ : Sysutils::Exception(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EAddError(int Ident, const System::TVarRec * Args, const int Args_Size)/* overload */ : Sysutils::Exception(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EAddError(const AnsiString Msg, int AHelpContext) : Sysutils::Exception(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EAddError(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size, int AHelpContext) : Sysutils::Exception(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EAddError(int Ident, int AHelpContext)/* overload */ : Sysutils::Exception(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EAddError(System::PResStringRec ResStringRec, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : Sysutils::Exception(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EAddError(void) { }
	#pragma option pop
	
};


class DELPHICLASS TDSSQueryEditor;
class PASCALIMPLEMENTATION TDSSQueryEditor : public Forms::TForm 
{
	typedef Forms::TForm inherited;
	
__published:
	Stdctrls::TListBox* FieldList;
	Stdctrls::TListBox* ActiveDimList;
	Stdctrls::TListBox* SummaryList;
	Stdctrls::TLabel* Label2;
	Stdctrls::TLabel* Label3;
	Stdctrls::TMemo* ShowBox;
	Menus::TPopupMenu* AggPopup;
	Buttons::TBitBtn* Cancel;
	Stdctrls::TButton* CancelQryMod;
	Menus::TMenuItem* count1;
	Menus::TMenuItem* count2;
	Stdctrls::TButton* EditQry;
	Stdctrls::TButton* VQB;
	Stdctrls::TButton* SelectAllFields;
	Stdctrls::TLabel* Label4;
	Stdctrls::TButton* OKButton;
	Menus::TMenuItem* average1;
	Stdctrls::TButton* HelpButton;
	Comctrls::TPageControl* Pager;
	Comctrls::TTabSheet* Dimensions;
	Comctrls::TTabSheet* Query;
	Stdctrls::TLabel* Label1;
	Stdctrls::TComboBox* TableCombo;
	Stdctrls::TComboBox* DatabaseCombo;
	Stdctrls::TLabel* Label5;
	Stdctrls::TLabel* Label6;
	Buttons::TBitBtn* AddButton;
	Buttons::TBitBtn* AddAgg;
	Buttons::TBitBtn* RemoveButton;
	Buttons::TBitBtn* RemoveAgg;
	Stdctrls::TLabel* Label7;
	Stdctrls::TCheckBox* CountStarAvg;
	void __fastcall AddButtonClick(System::TObject* Sender);
	void __fastcall RemoveButtonClick(System::TObject* Sender);
	void __fastcall FieldListClick(System::TObject* Sender);
	void __fastcall ActiveDimListClick(System::TObject* Sender);
	void __fastcall SummaryListClick(System::TObject* Sender);
	void __fastcall AddAggClick(System::TObject* Sender);
	void __fastcall RemoveAggClick(System::TObject* Sender);
	void __fastcall Sum1Click(System::TObject* Sender);
	void __fastcall Count1Click(System::TObject* Sender);
	void __fastcall OKButtonClick(System::TObject* Sender);
	void __fastcall CancelQryModClick(System::TObject* Sender);
	void __fastcall ShowBoxChange(System::TObject* Sender);
	void __fastcall EditQryClick(System::TObject* Sender);
	void __fastcall VQBClick(System::TObject* Sender);
	void __fastcall SelectAllFieldsClick(System::TObject* Sender);
	void __fastcall FieldListDblClick(System::TObject* Sender);
	void __fastcall average1Click(System::TObject* Sender);
	void __fastcall ActiveDimListDragDrop(System::TObject* Sender, System::TObject* Source, int X, int Y);
	void __fastcall ActiveDimListDragOver(System::TObject* Sender, System::TObject* Source, int X, int Y, Controls::TDragState State, bool &Accept);
	void __fastcall FieldListDragOver(System::TObject* Sender, System::TObject* Source, int X, int Y, Controls::TDragState State, bool &Accept);
	void __fastcall SummaryListDragOver(System::TObject* Sender, System::TObject* Source, int X, int Y, Controls::TDragState State, bool &Accept);
	void __fastcall FieldListDragDrop(System::TObject* Sender, System::TObject* Source, int X, int Y);
	void __fastcall SummaryListDragDrop(System::TObject* Sender, System::TObject* Source, int X, int Y);
	void __fastcall FieldListKeyPress(System::TObject* Sender, char &Key);
	void __fastcall ShowBoxKeyPress(System::TObject* Sender, char &Key);
	void __fastcall ActiveDimListKeyPress(System::TObject* Sender, char &Key);
	void __fastcall SummaryListKeyPress(System::TObject* Sender, char &Key);
	void __fastcall PagerChanging(System::TObject* Sender, bool &AllowChange);
	void __fastcall TableComboChange(System::TObject* Sender);
	void __fastcall DatabaseComboChange(System::TObject* Sender);
	void __fastcall DatabaseComboExit(System::TObject* Sender);
	void __fastcall DatabaseComboKeyPress(System::TObject* Sender, char &Key);
	void __fastcall TableComboKeyPress(System::TObject* Sender, char &Key);
	void __fastcall TableComboExit(System::TObject* Sender);
	void __fastcall HelpButtonClick(System::TObject* Sender);
	void __fastcall DatabaseComboKeyDown(System::TObject* Sender, Word &Key, Classes::TShiftState Shift);
	void __fastcall TableComboKeyDown(System::TObject* Sender, Word &Key, Classes::TShiftState Shift);
	void __fastcall CountStarAvgClick(System::TObject* Sender);
	
private:
	bool bEditEnabled;
	bool bisOK;
	bool bQueryLegal;
	bool bAllFields;
	bool bDataBaseEditing;
	bool bDataBaseChanged;
	bool bTableNameEditing;
	bool bTableNameChanged;
	bool bQueryEditing;
	bool bSQLChangeOff;
	bool bStarAvgChanging;
	Mxtables::TQueryDims* myMap;
	Mxtables::TQueryDims* fieldMap;
	Dbtables::TQuery* myQuery;
	Dbtables::TQuery* vqbQuery;
	Dbtables::TDatabase* myDB;
	AnsiString mySQL;
	AnsiString myAlias;
	Mxqparse::TXtabQuery* fQParse;
	void __fastcall SetQueryEditState(bool State);
	void __fastcall ListBoxUnSelect(Stdctrls::TListBox* aListBox);
	bool __fastcall AddNewItem(Mxcommon::TDimFlags sType, Mxtables::TQueryDim* DM, AnsiString Name);
	bool __fastcall AddSummary(Mxcommon::TDimFlags sType);
	void __fastcall AddCountStar(void);
	void __fastcall RemoveCountStar(void);
	AnsiString __fastcall FieldListDisplay(Mxtables::TQueryDim* Map);
	void __fastcall ProcessNewQuery(AnsiString newSQL);
	void __fastcall ProcessNewQueryError(AnsiString newSQL);
	void __fastcall SetDatabaseName(AnsiString tAlias);
	void __fastcall SetTableName(AnsiString TableName);
	void __fastcall UpdateLists(void);
	void __fastcall UpdateTableList(void);
	void __fastcall UpdateDataBaseList(void);
	void __fastcall UpdateFieldList(void);
	void __fastcall UpdateDimLists(void);
	void __fastcall UpdateSQLBox(void);
	void __fastcall UpdateTableName(void);
	
public:
	bool __fastcall SInitialize(const Designintf::_di_IDesigner Designer, Dbtables::TQuery* aQuery);
	__fastcall virtual TDSSQueryEditor(Classes::TComponent* AOwner);
	__fastcall virtual ~TDSSQueryEditor(void);
public:
	#pragma option push -w-inl
	/* TCustomForm.CreateNew */ inline __fastcall virtual TDSSQueryEditor(Classes::TComponent* AOwner, int Dummy) : Forms::TForm(AOwner, Dummy) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TDSSQueryEditor(HWND ParentWindow) : Forms::TForm(ParentWindow) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------
extern PACKAGE void __fastcall ShowDSSQueryEditor(const Designintf::_di_IDesigner Designer, Dbtables::TQuery* aQuery);

}	/* namespace Mxdssqry */
using namespace Mxdssqry;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// MXDSSQRY
