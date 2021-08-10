// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Dataform.pas' rev: 6.00

#ifndef DataformHPP
#define DataformHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <FrmExprt.hpp>	// Pascal unit
#include <DBGrids.hpp>	// Pascal unit
#include <BDE.hpp>	// Pascal unit
#include <DBCtrls.hpp>	// Pascal unit
#include <DBTables.hpp>	// Pascal unit
#include <DB.hpp>	// Pascal unit
#include <Controls.hpp>	// Pascal unit
#include <ExtCtrls.hpp>	// Pascal unit
#include <Forms.hpp>	// Pascal unit
#include <Graphics.hpp>	// Pascal unit
#include <StdCtrls.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <SysUtils.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Dataform
{
//-- type declarations -------------------------------------------------------
#pragma option push -b-
enum TUsedControls { ucGrid, ucScrollBox, ucSplitter };
#pragma option pop

class DELPHICLASS TDataForm;
class PASCALIMPLEMENTATION TDataForm : public Forms::TForm 
{
	typedef Forms::TForm inherited;
	
__published:
	Dbtables::TQuery* Query1;
	Dbtables::TQuery* Query2;
	Db::TDataSource* DataSource1;
	Db::TDataSource* DataSource2;
	Extctrls::TPanel* Panel1;
	Dbtables::TTable* Table1;
	Dbtables::TTable* Table2;
	Dbctrls::TDBNavigator* DBNavigator;
	void __fastcall FormCreate(System::TObject* Sender);
	
private:
	int NumFields;
	int XPos;
	int YPos;
	Forms::TScrollBox* FScrollBox;
	Extctrls::TPanel* FScrollPanel;
	Extctrls::TPanel* FGridPanel1;
	Extctrls::TPanel* FGridPanel2;
	int MaxLabelWidth;
	Word CharWidth;
	int LowestControl;
	System::Set<TUsedControls, ucGrid, ucSplitter>  UsedControls;
	Controls::TControl* __fastcall CreateControl(Frmexprt::PFieldInfo Field);
	AnsiString __fastcall CreateName(Classes::TComponent* Component, AnsiString Value);
	Types::TPoint __fastcall GetMaxControlValue();
	void __fastcall RestructureForm(int Value);
	
public:
	bool MultiQuery;
	bool ByRow;
	int Pass;
	bool LabelsLeft;
	int LastHeight;
	bool CreateTable;
	bool GenDataSets;
	AnsiString UsesName;
	Db::TDataSource* MainDataSource1;
	Db::TDataSource* MainDataSource2;
	void __fastcall NextPass(void);
	Classes::TMemoryStream* __fastcall CreateRes(const AnsiString FormName);
	Classes::TMemoryStream* __fastcall CreateHdrSource(const AnsiString FilePath, const AnsiString FormName);
	Classes::TMemoryStream* __fastcall CreateCppSource(const AnsiString FilePath, const AnsiString FormName, AnsiString DMFileName);
	Classes::TMemoryStream* __fastcall CreateSource(const AnsiString FilePath, const AnsiString FormName);
	void __fastcall CreateField(const AnsiString FieldName, Frmexprt::PFieldInfo Field);
	void __fastcall CreateGrid(void);
	__property Forms::TScrollBox* ScrollBox = {read=FScrollBox};
public:
	#pragma option push -w-inl
	/* TCustomForm.Create */ inline __fastcall virtual TDataForm(Classes::TComponent* AOwner) : Forms::TForm(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.CreateNew */ inline __fastcall virtual TDataForm(Classes::TComponent* AOwner, int Dummy) : Forms::TForm(AOwner, Dummy) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.Destroy */ inline __fastcall virtual ~TDataForm(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TDataForm(HWND ParentWindow) : Forms::TForm(ParentWindow) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Dataform */
using namespace Dataform;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// Dataform
