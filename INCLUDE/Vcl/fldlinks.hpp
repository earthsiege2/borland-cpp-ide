// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'FldLinks.pas' rev: 6.00

#ifndef FldLinksHPP
#define FldLinksHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <DesignEditors.hpp>	// Pascal unit
#include <DesignIntf.hpp>	// Pascal unit
#include <Buttons.hpp>	// Pascal unit
#include <DB.hpp>	// Pascal unit
#include <ExtCtrls.hpp>	// Pascal unit
#include <StdCtrls.hpp>	// Pascal unit
#include <Forms.hpp>	// Pascal unit
#include <Controls.hpp>	// Pascal unit
#include <Graphics.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <Messages.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <SysUtils.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Fldlinks
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TFieldLinkProperty;
class PASCALIMPLEMENTATION TFieldLinkProperty : public Designeditors::TStringProperty 
{
	typedef Designeditors::TStringProperty inherited;
	
private:
	bool FChanged;
	Db::TDataSet* FDataSet;
	
protected:
	Db::TDataSet* __fastcall GetDataSet(void);
	virtual void __fastcall GetFieldNamesForIndex(Classes::TStrings* List);
	virtual bool __fastcall GetIndexBased(void);
	virtual Db::TIndexDefs* __fastcall GetIndexDefs(void);
	virtual AnsiString __fastcall GetIndexFieldNames();
	virtual AnsiString __fastcall GetIndexName();
	virtual AnsiString __fastcall GetMasterFields(void) = 0 ;
	virtual void __fastcall SetIndexFieldNames(const AnsiString Value);
	virtual void __fastcall SetIndexName(const AnsiString Value);
	virtual void __fastcall SetMasterFields(const AnsiString Value) = 0 ;
	
public:
	__fastcall virtual TFieldLinkProperty(Db::TDataSet* ADataSet);
	void __fastcall GetIndexNames(Classes::TStrings* List);
	__property bool IndexBased = {read=GetIndexBased, nodefault};
	__property Db::TIndexDefs* IndexDefs = {read=GetIndexDefs};
	__property AnsiString IndexFieldNames = {read=GetIndexFieldNames, write=SetIndexFieldNames};
	__property AnsiString IndexName = {read=GetIndexName, write=SetIndexName};
	__property AnsiString MasterFields = {read=GetMasterFields, write=SetMasterFields};
	__property bool Changed = {read=FChanged, nodefault};
	virtual void __fastcall Edit(void);
	virtual Designintf::TPropertyAttributes __fastcall GetAttributes(void);
	__property Db::TDataSet* DataSet = {read=GetDataSet};
public:
	#pragma option push -w-inl
	/* TPropertyEditor.Create */ inline __fastcall virtual TFieldLinkProperty(const Designintf::_di_IDesigner ADesigner, int APropCount) : Designeditors::TStringProperty(ADesigner, APropCount) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TPropertyEditor.Destroy */ inline __fastcall virtual ~TFieldLinkProperty(void) { }
	#pragma option pop
	
};


class DELPHICLASS TLinkFields;
class PASCALIMPLEMENTATION TLinkFields : public Forms::TForm 
{
	typedef Forms::TForm inherited;
	
__published:
	Stdctrls::TListBox* DetailList;
	Stdctrls::TListBox* MasterList;
	Stdctrls::TListBox* BindList;
	Stdctrls::TLabel* Label30;
	Stdctrls::TLabel* Label31;
	Stdctrls::TComboBox* IndexList;
	Stdctrls::TLabel* IndexLabel;
	Stdctrls::TLabel* Label2;
	Extctrls::TBevel* Bevel1;
	Extctrls::TBevel* Bevel2;
	Stdctrls::TButton* AddButton;
	Stdctrls::TButton* DeleteButton;
	Stdctrls::TButton* ClearButton;
	Stdctrls::TButton* Button1;
	Stdctrls::TButton* Button2;
	Stdctrls::TButton* Help;
	void __fastcall FormCreate(System::TObject* Sender);
	void __fastcall BindingListClick(System::TObject* Sender);
	void __fastcall AddButtonClick(System::TObject* Sender);
	void __fastcall DeleteButtonClick(System::TObject* Sender);
	void __fastcall BindListClick(System::TObject* Sender);
	void __fastcall ClearButtonClick(System::TObject* Sender);
	void __fastcall FormDestroy(System::TObject* Sender);
	void __fastcall BitBtn1Click(System::TObject* Sender);
	void __fastcall HelpClick(System::TObject* Sender);
	void __fastcall IndexListChange(System::TObject* Sender);
	
private:
	Db::TDataSet* FDataSet;
	Db::TDataSet* FMasterDataSet;
	TFieldLinkProperty* FDataSetProxy;
	AnsiString FFullIndexName;
	AnsiString MasterFieldList;
	AnsiString IndexFieldList;
	Classes::TStringList* OrderedDetailList;
	Classes::TStringList* OrderedMasterList;
	void __fastcall OrderFieldList(Classes::TStrings* OrderedList, Classes::TStrings* List);
	void __fastcall AddToBindList(const AnsiString Str1, const AnsiString Str2);
	void __fastcall Initialize(void);
	__property AnsiString FullIndexName = {read=FFullIndexName};
	void __fastcall SetDataSet(Db::TDataSet* Value);
	
public:
	__property Db::TDataSet* DataSet = {read=FDataSet, write=SetDataSet};
	__property TFieldLinkProperty* DataSetProxy = {read=FDataSetProxy, write=FDataSetProxy};
	bool __fastcall Edit(void);
public:
	#pragma option push -w-inl
	/* TCustomForm.Create */ inline __fastcall virtual TLinkFields(Classes::TComponent* AOwner) : Forms::TForm(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.CreateNew */ inline __fastcall virtual TLinkFields(Classes::TComponent* AOwner, int Dummy) : Forms::TForm(AOwner, Dummy) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.Destroy */ inline __fastcall virtual ~TLinkFields(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TLinkFields(HWND ParentWindow) : Forms::TForm(ParentWindow) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------
extern PACKAGE bool __fastcall EditMasterFields(Db::TDataSet* ADataSet, TFieldLinkProperty* ADataSetProxy);

}	/* namespace Fldlinks */
using namespace Fldlinks;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// FldLinks
