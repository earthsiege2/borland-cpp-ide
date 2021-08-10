// Borland C++ Builder
// Copyright (c) 1995, 1999 by Borland International
// All rights reserved

// (DO NOT EDIT: machine generated header) 'DSDefine.pas' rev: 5.00

#ifndef DSDefineHPP
#define DSDefineHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <DsgnIntf.hpp>	// Pascal unit
#include <Db.hpp>	// Pascal unit
#include <Buttons.hpp>	// Pascal unit
#include <ExtCtrls.hpp>	// Pascal unit
#include <StdCtrls.hpp>	// Pascal unit
#include <Forms.hpp>	// Pascal unit
#include <Controls.hpp>	// Pascal unit
#include <Graphics.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <Messages.hpp>	// Pascal unit
#include <SysUtils.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Dsdefine
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TDefineField;
class PASCALIMPLEMENTATION TDefineField : public Forms::TForm 
{
	typedef Forms::TForm inherited;
	
__published:
	Stdctrls::TButton* OkBtn;
	Stdctrls::TButton* CancelBtn;
	Stdctrls::TButton* HelpBtn;
	Stdctrls::TGroupBox* FieldGroup;
	Stdctrls::TLabel* ComponentNameLabel;
	Stdctrls::TLabel* FieldNameLabel;
	Stdctrls::TEdit* ComponentNameEdit;
	Stdctrls::TEdit* FieldNameEdit;
	Stdctrls::TComboBox* FieldTypeList;
	Stdctrls::TLabel* SizeEditLabel;
	Stdctrls::TEdit* SizeEdit;
	Extctrls::TRadioGroup* FieldKind;
	Stdctrls::TGroupBox* LookupGroup;
	Stdctrls::TComboBox* DatasetList;
	Stdctrls::TLabel* DatasetLabel;
	Stdctrls::TComboBox* KeyFieldsList;
	Stdctrls::TComboBox* LookupKeysList;
	Stdctrls::TComboBox* ResultFieldList;
	Stdctrls::TLabel* KeyFieldsLabel;
	Stdctrls::TLabel* LookupKeysLabel;
	Stdctrls::TLabel* ResultFieldLabel;
	Stdctrls::TLabel* FieldTypeLabel;
	void __fastcall FieldNameEditChange(System::TObject* Sender);
	void __fastcall FormCreate(System::TObject* Sender);
	void __fastcall OkBtnClick(System::TObject* Sender);
	void __fastcall DatasetListDropDown(System::TObject* Sender);
	void __fastcall LookupKeysListDropDown(System::TObject* Sender);
	void __fastcall KeyFieldsListDropDown(System::TObject* Sender);
	void __fastcall ResultFieldListDropDown(System::TObject* Sender);
	void __fastcall FieldKindClick(System::TObject* Sender);
	void __fastcall DatasetListChange(System::TObject* Sender);
	void __fastcall HelpBtnClick(System::TObject* Sender);
	void __fastcall FieldTypeListChange(System::TObject* Sender);
	
private:
	Db::TDataSet* FDataset;
	Dsgnintf::_di_IFormDesigner FDesigner;
	Db::TDataSetDesigner* FDSDesigner;
	Db::TField* FField;
	bool __fastcall GetCalculated(void);
	AnsiString __fastcall GetComponentName();
	TMetaClass* __fastcall GetFieldClass(void);
	AnsiString __fastcall GetFieldName();
	bool __fastcall GetLookup(void);
	Db::TDataSet* __fastcall GetLookupDataset(void);
	AnsiString __fastcall GetKeyFields();
	AnsiString __fastcall GetLookupKeyFields();
	AnsiString __fastcall GetLookupResultField();
	void __fastcall GetLookupFields(Classes::TStrings* Items);
	int __fastcall GetSize(void);
	void __fastcall SetCalculated(bool Value);
	void __fastcall SetComponentName(const AnsiString Value);
	void __fastcall SetDataset(Db::TDataSet* Value);
	void __fastcall SetFieldClass(TMetaClass* Value);
	void __fastcall SetFieldName(const AnsiString Value);
	void __fastcall SetLookup(bool Value);
	void __fastcall SetSize(int Value);
	void __fastcall UpdateLookupControls(void);
	
public:
	void __fastcall ConfigureForLookupOnly(const AnsiString ADataSet, const AnsiString AKey, const AnsiString 
		ALookup, const AnsiString AResult, const AnsiString AType, Word ASize);
	__property bool Calculated = {read=GetCalculated, write=SetCalculated, nodefault};
	__property bool Lookup = {read=GetLookup, write=SetLookup, nodefault};
	__property AnsiString ComponentName = {read=GetComponentName, write=SetComponentName};
	__property TMetaClass* FieldClass = {read=GetFieldClass, write=SetFieldClass};
	__property AnsiString FieldName = {read=GetFieldName, write=SetFieldName};
	__property Db::TField* Field = {read=FField};
	__property int Size = {read=GetSize, write=SetSize, nodefault};
	__property Db::TDataSet* LookupDataset = {read=GetLookupDataset};
	__property AnsiString KeyFields = {read=GetKeyFields};
	__property AnsiString LookupKeyFields = {read=GetLookupKeyFields};
	__property AnsiString LookupResultField = {read=GetLookupResultField};
	__property Db::TDataSet* Dataset = {read=FDataset, write=SetDataset};
	__property Dsgnintf::_di_IFormDesigner Designer = {read=FDesigner, write=FDesigner};
	__property Db::TDataSetDesigner* DSDesigner = {read=FDSDesigner, write=FDSDesigner};
public:
	#pragma option push -w-inl
	/* TCustomForm.Create */ inline __fastcall virtual TDefineField(Classes::TComponent* AOwner) : Forms::TForm(
		AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.CreateNew */ inline __fastcall virtual TDefineField(Classes::TComponent* AOwner, int 
		Dummy) : Forms::TForm(AOwner, Dummy) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.Destroy */ inline __fastcall virtual ~TDefineField(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TDefineField(HWND ParentWindow) : Forms::TForm(ParentWindow
		) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------
extern PACKAGE TDefineField* DefineField;
extern PACKAGE AnsiString __fastcall ClassNameNoT(TMetaClass* FieldClass);

}	/* namespace Dsdefine */
#if !defined(NO_IMPLICIT_NAMESPACE_USE)
using namespace Dsdefine;
#endif
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// DSDefine
