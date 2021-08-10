// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'DBWeb.pas' rev: 6.00

#ifndef DBWebHPP
#define DBWebHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <HTTPProd.hpp>	// Pascal unit
#include <DB.hpp>	// Pascal unit
#include <HTTPApp.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <SysUtils.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Dbweb
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TDSTableProducerEditor;
class DELPHICLASS TDSTableProducer;
#pragma option push -b-
enum THTMLCaptionAlignment { caDefault, caTop, caBottom };
#pragma option pop

class DELPHICLASS THTTPDataLink;
class PASCALIMPLEMENTATION THTTPDataLink : public Db::TDataLink 
{
	typedef Db::TDataLink inherited;
	
private:
	TDSTableProducer* FDSTableProducer;
	int FFieldCount;
	int FFieldMapSize;
	void *FFieldMap;
	bool FModified;
	bool FSparseMap;
	bool __fastcall GetDefaultFields(void);
	Db::TField* __fastcall GetFields(int I);
	
protected:
	virtual void __fastcall ActiveChanged(void);
	virtual void __fastcall DataSetChanged(void);
	virtual void __fastcall DataSetScrolled(int Distance);
	virtual void __fastcall FocusControl(Db::TFieldRef Field);
	virtual void __fastcall EditingChanged(void);
	virtual void __fastcall LayoutChanged(void);
	virtual void __fastcall RecordChanged(Db::TField* Field);
	virtual void __fastcall UpdateData(void);
	int __fastcall GetMappedIndex(int ColIndex);
	
public:
	__fastcall THTTPDataLink(TDSTableProducer* DSTableProducer);
	__fastcall virtual ~THTTPDataLink(void);
	bool __fastcall AddMapping(const AnsiString FieldName);
	void __fastcall ClearMapping(void);
	void __fastcall Modified(void);
	void __fastcall Reset(void);
	__property bool DefaultFields = {read=GetDefaultFields, nodefault};
	__property int FieldCount = {read=FFieldCount, nodefault};
	__property Db::TField* Fields[int I] = {read=GetFields};
	__property bool SparseMap = {read=FSparseMap, write=FSparseMap, nodefault};
};


class DELPHICLASS THTMLTableColumns;
class DELPHICLASS THTMLTableColumn;
#pragma option push -b-
enum THTMLColumnState { csDefault, csCustom };
#pragma option pop

typedef TMetaClass*THTMLTableColumnClass;

class PASCALIMPLEMENTATION THTMLTableColumns : public Classes::TCollection 
{
	typedef Classes::TCollection inherited;
	
public:
	THTMLTableColumn* operator[](int Index) { return Items[Index]; }
	
private:
	TDSTableProducer* FDSTableProducer;
	THTMLTableColumn* __fastcall GetColumn(int Index);
	THTMLColumnState __fastcall GetState(void);
	void __fastcall SetColumn(int Index, THTMLTableColumn* Value);
	void __fastcall SetState(THTMLColumnState Value);
	
protected:
	DYNAMIC int __fastcall GetAttrCount(void);
	DYNAMIC AnsiString __fastcall GetAttr(int Index);
	DYNAMIC AnsiString __fastcall GetItemAttr(int Index, int ItemIndex);
	DYNAMIC Classes::TPersistent* __fastcall GetOwner(void);
	virtual void __fastcall Update(Classes::TCollectionItem* Item);
	
public:
	__fastcall THTMLTableColumns(TDSTableProducer* DSTableProducer, TMetaClass* ColumnClass);
	HIDESBASE THTMLTableColumn* __fastcall Add(void);
	void __fastcall RestoreDefaults(void);
	void __fastcall RebuildColumns(void);
	__property THTMLColumnState State = {read=GetState, write=SetState, nodefault};
	__property TDSTableProducer* DSTableProducer = {read=FDSTableProducer};
	__property THTMLTableColumn* Items[int Index] = {read=GetColumn, write=SetColumn/*, default*/};
public:
	#pragma option push -w-inl
	/* TCollection.Destroy */ inline __fastcall virtual ~THTMLTableColumns(void) { }
	#pragma option pop
	
};


typedef void __fastcall (__closure *TCreateContentEvent)(System::TObject* Sender, bool &Continue);

typedef void __fastcall (__closure *THTMLFormatCellEvent)(System::TObject* Sender, int CellRow, int CellColumn, AnsiString &BgColor, Httpprod::THTMLAlign &Align, Httpprod::THTMLVAlign &VAlign, AnsiString &CustomAttrs, AnsiString &CellData);

typedef void __fastcall (__closure *THTMLGetTableCaptionEvent)(System::TObject* Sender, AnsiString &Caption, THTMLCaptionAlignment &Alignment);

class PASCALIMPLEMENTATION TDSTableProducer : public Httpapp::TCustomContentProducer 
{
	typedef Httpapp::TCustomContentProducer inherited;
	
private:
	AnsiString FCaption;
	THTMLCaptionAlignment FCaptionAlignment;
	THTTPDataLink* FDataLink;
	Db::TDataSource* FInternalDataSource;
	TDSTableProducerEditor* FEditor;
	THTMLTableColumns* FColumns;
	Classes::TStrings* FHeader;
	Classes::TStrings* FFooter;
	int FMaxRows;
	bool FModified;
	int FLayoutLock;
	int FUpdateLock;
	Httpprod::THTMLTableRowAttributes* FRowAttributes;
	Httpprod::THTMLTableAttributes* FTableAttributes;
	TCreateContentEvent FOnCreateContent;
	THTMLFormatCellEvent FOnFormatCell;
	THTMLGetTableCaptionEvent FOnGetTableCaption;
	void __fastcall AttributeChanged(System::TObject* Sender);
	void __fastcall Changed(void);
	void __fastcall InternalLayout(void);
	void __fastcall SetCaption(const AnsiString Value);
	void __fastcall SetCaptionAlignment(THTMLCaptionAlignment Value);
	void __fastcall SetFooter(Classes::TStrings* Value);
	void __fastcall SetHeader(Classes::TStrings* Value);
	void __fastcall SetMaxRows(int Value);
	void __fastcall SetRowAttributes(Httpprod::THTMLTableRowAttributes* Value);
	void __fastcall SetTableAttributes(Httpprod::THTMLTableAttributes* Value);
	
protected:
	bool __fastcall AcquireLayoutLock(void);
	void __fastcall BeginLayout(void);
	DYNAMIC AnsiString __fastcall ColumnHeader();
	void __fastcall DefineFieldMap(void);
	bool __fastcall DoCreateContent(void);
	DYNAMIC void __fastcall DoFormatCell(int CellRow, int CellColumn, AnsiString &BgColor, Httpprod::THTMLAlign &Align, Httpprod::THTMLVAlign &VAlign, AnsiString &CustomAttrs, AnsiString &CellData);
	DYNAMIC void __fastcall DoGetCaption(AnsiString &TableCaption, THTMLCaptionAlignment &CaptionAlign);
	void __fastcall EndLayout(void);
	DYNAMIC AnsiString __fastcall FormatCell(int CellRow, int CellColumn, AnsiString CellData, const AnsiString Tag, const AnsiString BgColor, Httpprod::THTMLAlign Align, Httpprod::THTMLVAlign VAlign, const AnsiString Custom);
	virtual Db::TDataSet* __fastcall GetDataSet(void) = 0 ;
	Db::TDataSource* __fastcall GetDataSource(void);
	virtual void __fastcall Notification(Classes::TComponent* AComponent, Classes::TOperation Operation);
	void __fastcall LayoutChanged(void);
	void __fastcall LinkActive(bool Value);
	DYNAMIC AnsiString __fastcall RowHeader();
	void __fastcall SetColumns(THTMLTableColumns* Value);
	virtual void __fastcall SetDataSet(Db::TDataSet* ADataSet) = 0 ;
	void __fastcall SetDataSource(Db::TDataSource* Value);
	bool __fastcall StoreColumns(void);
	DYNAMIC AnsiString __fastcall TableHeader();
	DYNAMIC AnsiString __fastcall TableCaption();
	__property THTTPDataLink* DataLink = {read=FDataLink};
	__property Db::TDataSource* DataSource = {read=GetDataSource, write=SetDataSource};
	__property Db::TDataSource* InternalDataSource = {read=FInternalDataSource};
	__property TCreateContentEvent OnCreateContent = {read=FOnCreateContent, write=FOnCreateContent};
	__property THTMLFormatCellEvent OnFormatCell = {read=FOnFormatCell, write=FOnFormatCell};
	__property THTMLGetTableCaptionEvent OnGetTableCaption = {read=FOnGetTableCaption, write=FOnGetTableCaption};
	
public:
	__fastcall virtual TDSTableProducer(Classes::TComponent* AOwner);
	__fastcall virtual ~TDSTableProducer(void);
	void __fastcall BeginUpdate(void);
	void __fastcall EndUpdate(void);
	__property AnsiString Caption = {read=FCaption, write=SetCaption};
	__property THTMLCaptionAlignment CaptionAlignment = {read=FCaptionAlignment, write=SetCaptionAlignment, default=0};
	__property THTMLTableColumns* Columns = {read=FColumns, write=SetColumns, stored=StoreColumns};
	__property Db::TDataSet* DataSet = {read=GetDataSet, write=SetDataSet};
	__property TDSTableProducerEditor* Editor = {read=FEditor, write=FEditor};
	__property Classes::TStrings* Footer = {read=FFooter, write=SetFooter};
	__property Classes::TStrings* Header = {read=FHeader, write=SetHeader};
	__property int MaxRows = {read=FMaxRows, write=SetMaxRows, default=20};
	__property Httpprod::THTMLTableRowAttributes* RowAttributes = {read=FRowAttributes, write=SetRowAttributes};
	__property Httpprod::THTMLTableAttributes* TableAttributes = {read=FTableAttributes, write=SetTableAttributes};
};


class PASCALIMPLEMENTATION TDSTableProducerEditor : public System::TObject 
{
	typedef System::TObject inherited;
	
private:
	TDSTableProducer* FDSTableProducer;
	Db::TDataSource* __fastcall GetDataSource(void);
	void __fastcall SetDataSource(Db::TDataSource* DataSource);
	
public:
	__fastcall TDSTableProducerEditor(TDSTableProducer* DSTableProducer);
	__fastcall virtual ~TDSTableProducerEditor(void);
	virtual void __fastcall Changed(void);
	virtual void __fastcall PostChange(void);
	__property TDSTableProducer* DSTableProducer = {read=FDSTableProducer};
	__property Db::TDataSource* DataSource = {read=GetDataSource, write=SetDataSource};
};


class PASCALIMPLEMENTATION THTMLTableColumn : public Classes::TCollectionItem 
{
	typedef Classes::TCollectionItem inherited;
	
private:
	Db::TField* FField;
	AnsiString FFieldName;
	Httpprod::THTMLAlign FAlign;
	AnsiString FBgColor;
	AnsiString FCustom;
	Httpprod::THTMLVAlign FVAlign;
	Httpprod::THTMLTableHeaderAttributes* FTitle;
	Db::TField* __fastcall GetField(void);
	TDSTableProducer* __fastcall GetTableProducer(void);
	void __fastcall SetAlign(Httpprod::THTMLAlign Value);
	void __fastcall SetBgColor(const AnsiString Value);
	void __fastcall SetCustom(const AnsiString Value);
	void __fastcall SetField(Db::TField* Value);
	void __fastcall SetFieldName(const AnsiString Value);
	void __fastcall SetTitle(Httpprod::THTMLTableHeaderAttributes* Value);
	void __fastcall SetVAlign(Httpprod::THTMLVAlign Value);
	void __fastcall TitleChanged(System::TObject* Sender);
	
protected:
	TDSTableProducer* __fastcall GeTDSTableProducer(void);
	virtual AnsiString __fastcall GetDisplayName();
	bool __fastcall IsStored(void);
	
public:
	__fastcall virtual THTMLTableColumn(Classes::TCollection* Collection);
	__fastcall virtual ~THTMLTableColumn(void);
	virtual void __fastcall AssignTo(Classes::TPersistent* Dest);
	void __fastcall RestoreDefaults(void);
	void __fastcall Update(void);
	__property Db::TField* Field = {read=GetField, write=SetField};
	__property TDSTableProducer* DSTableProducer = {read=GetTableProducer};
	
__published:
	__property Httpprod::THTMLAlign Align = {read=FAlign, write=SetAlign, default=0};
	__property AnsiString BgColor = {read=FBgColor, write=SetBgColor};
	__property AnsiString Custom = {read=FCustom, write=SetCustom};
	__property AnsiString FieldName = {read=FFieldName, write=SetFieldName};
	__property Httpprod::THTMLTableHeaderAttributes* Title = {read=FTitle, write=SetTitle};
	__property Httpprod::THTMLVAlign VAlign = {read=FVAlign, write=SetVAlign, default=0};
};


typedef void __fastcall (__closure *THTMLDataSetEmpty)(System::TObject* Sender, bool &Continue);

class DELPHICLASS TDataSetTableProducer;
class PASCALIMPLEMENTATION TDataSetTableProducer : public TDSTableProducer 
{
	typedef TDSTableProducer inherited;
	
private:
	Db::TDataSet* FDataSet;
	
protected:
	virtual Db::TDataSet* __fastcall GetDataSet(void);
	virtual void __fastcall Notification(Classes::TComponent* AComponent, Classes::TOperation Operation);
	virtual void __fastcall SetDataSet(Db::TDataSet* ADataSet);
	
public:
	virtual AnsiString __fastcall Content();
	
__published:
	__property Caption ;
	__property CaptionAlignment  = {default=0};
	__property Columns ;
	__property Footer ;
	__property Header ;
	__property MaxRows  = {default=20};
	__property DataSet ;
	__property RowAttributes ;
	__property TableAttributes ;
	__property OnCreateContent ;
	__property OnFormatCell ;
	__property OnGetTableCaption ;
public:
	#pragma option push -w-inl
	/* TDSTableProducer.Create */ inline __fastcall virtual TDataSetTableProducer(Classes::TComponent* AOwner) : TDSTableProducer(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TDSTableProducer.Destroy */ inline __fastcall virtual ~TDataSetTableProducer(void) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------
extern PACKAGE AnsiString __fastcall HtmlTable(Db::TDataSet* DataSet, TDSTableProducer* DataSetHandler, int MaxRows);

}	/* namespace Dbweb */
using namespace Dbweb;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// DBWeb
