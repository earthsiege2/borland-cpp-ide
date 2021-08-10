//---------------------------------------------------------------------------

#ifndef ReconcileProdH
#define ReconcileProdH
//---------------------------------------------------------------------------

#include <SysUtils.hpp>
#include <Controls.hpp>
#include <Classes.hpp>
#include <Forms.hpp>
#include <CompProd.hpp>
#include <HTTPApp.hpp>
#include <MidProd.hpp>
#include <PagItems.hpp>

#include <MidItems.hpp>	

//-- user supplied -----------------------------------------------------------

namespace Reconcileprod
{
//-- type declarations -------------------------------------------------------
class PACKAGE TReconcilePageProducer;
class PACKAGE TReconcileGrid;
class PACKAGE TReconcileColumn;
class PACKAGE TReconcileColumn : public Classes::TPersistent
{
	typedef Classes::TPersistent inherited;

private:
	void __fastcall SetCaptionAttributes(const Miditems::TCaptionAttributes* Value);
protected:
	AnsiString FCaption;
	AnsiString FStyle;
	AnsiString FStyleRule;
	AnsiString FCustom;
	Miditems::TCaptionAttributes* FCaptionAttributes;
	int FDisplayWidth;
	int FMaxWidth;
	AnsiString FName;
	AnsiString FEvents;

	virtual void __fastcall AssignTo(Classes::TPersistent* Dest);
	__property AnsiString Name = {read=FName, write=FName};
	__property AnsiString Events = {read=FEvents, write=FEvents};

public:
	__fastcall TReconcileColumn(Classes::TComponent* AOwner);
	__fastcall virtual ~TReconcileColumn(void);
	AnsiString __fastcall ControlContent(Webcomp::TWebContentOptions* Options);
	AnsiString __fastcall GetHTMLControlName();

__published:
	__property AnsiString Caption = {read=FCaption, write=FCaption};
	__property AnsiString Custom = {read=FCustom, write=FCustom};
	__property AnsiString Style = {read=FStyle, write=FStyle};
	__property int MaxWidth = {read=FMaxWidth, write=FMaxWidth, default=-1};
	__property Miditems::TCaptionAttributes* CaptionAttributes = {read=FCaptionAttributes, write=SetCaptionAttributes};
	__property int DisplayWidth = {read=FDisplayWidth, write=FDisplayWidth, nodefault};
	__property AnsiString StyleRule = {read=FStyleRule, write=FStyleRule};
};


class PACKAGE TReconcileGrid : public Classes::TPersistent
{
	typedef Classes::TPersistent inherited;
        friend class TReconcilePageProducer;
private:
	int FDisplayRows;
	Miditems::TGridAttributes* FTableAttributes;
	Miditems::TGridRowAttributes* FHeadingAttributes;
	Miditems::TGridRowAttributes* FRowAttributes;
	TReconcileColumn* FFieldNameColumn;
	TReconcileColumn* FModifiedColumn;
	TReconcileColumn* FConflictingColumn;
	TReconcileColumn* FOriginalColumn;
	TReconcileColumn* __fastcall GetColumn(int I);
	int __fastcall GetColumnCount(void);
	void __fastcall SetConflictingColumn(const TReconcileColumn* Value);
	void __fastcall SetFieldNameColumn(const TReconcileColumn* Value);
	void __fastcall SetModifiedColumn(const TReconcileColumn* Value);
	void __fastcall SetOriginalColumn(const TReconcileColumn* Value);
        AnsiString __fastcall _TableHeader();
        AnsiString __fastcall _RowHeader(TGridRowAttributes & HeadingAttributes);
        AnsiString __fastcall _FormatColumn(TReconcileColumn &AColumn, AnsiString &OneRow,
          Webcomp::TWebContentOptions* Options);

protected:
	AnsiString __fastcall HTMLTableName();
	AnsiString __fastcall FormatTable(Webcomp::TLayoutWebContent* Layout, Webcomp::TWebContentOptions* Options);
	void __fastcall SetTableAttributes(const Miditems::TGridAttributes* Value);
	void __fastcall SetHeadingAttributes(const Miditems::TGridRowAttributes* Value);
	void __fastcall SetRowAttributes(const Miditems::TGridRowAttributes* Value);
	virtual void __fastcall AssignTo(Classes::TPersistent* Dest);
	
public:
	__fastcall TReconcileGrid(Classes::TComponent* AOwner);
	__fastcall virtual ~TReconcileGrid(void);
	__property int ColumnCount = {read=GetColumnCount, nodefault};
	__property TReconcileColumn* Column[int I] = {read=GetColumn};
	
__published:
	__property int DisplayRows = {read=FDisplayRows, write=FDisplayRows, default=4};
	__property Miditems::TGridAttributes* TableAttributes = {read=FTableAttributes, write=SetTableAttributes};
	__property Miditems::TGridRowAttributes* HeadingAttributes = {read=FHeadingAttributes, write=SetHeadingAttributes};
	__property Miditems::TGridRowAttributes* RowAttributes = {read=FRowAttributes, write=SetRowAttributes};
	__property TReconcileColumn* ConflictingColumn = {read=FConflictingColumn, write=SetConflictingColumn};
	__property TReconcileColumn* FieldNameColumn = {read=FFieldNameColumn, write=SetFieldNameColumn};
	__property TReconcileColumn* ModifiedColumn = {read=FModifiedColumn, write=SetModifiedColumn};
	__property TReconcileColumn* OriginalColumn = {read=FOriginalColumn, write=SetOriginalColumn};
};


class PACKAGE TReconcilePageProducer : public Midprod::TCustomMidasPageProducer
{
	typedef Midprod::TCustomMidasPageProducer inherited;

private:
	TReconcileGrid* FReconcileGrid;
	Xmlbrokr::TXMLBroker* FXMLBroker;
	void __fastcall SetReconcileGrid(const TReconcileGrid* Value);
        TXMLBroker* __fastcall _FindXMLBroker();
        AnsiString __fastcall _DeclareXMLDocument(const char * XMLBrokerName, const char * XmlVarName,
          const char * DocVarName, const char * TagName, const char * XMLData);
        AnsiString __fastcall _DeclareXMLIsland(const char * XMLBrokerName,
           const char * VarName, const char * AnsiString, const char * XMLData);

protected:
	DYNAMIC void __fastcall DoTagEvent(TTag Tag, const AnsiString TagString, Classes::TStrings* TagParams, AnsiString &ReplaceText);
	virtual void __fastcall GeneratePageElements(void);
	virtual Midprod::TMidasPageElements* __fastcall CreatePageElements(void);
	virtual void __fastcall AddIncludes(void);
	virtual AnsiString __fastcall DeclareRowSets();
	virtual void __fastcall AddScriptComponents(void);
	virtual AnsiString __fastcall DeclareXMLDocuments();
	virtual AnsiString __fastcall DeclareXMLIslands();
	void __fastcall GetXMLInfo(AnsiString &XMLBrokerName, AnsiString &XMLErrors, AnsiString &XMLDelta, Xmlbrokr::TXMLOptions XMLOptions);

public:
	__fastcall virtual TReconcilePageProducer(Classes::TComponent* AOwner);
	__fastcall virtual ~TReconcilePageProducer(void);

__published:
	__property IncludePathURL ;
	__property OnBeforeGetContent ;
	__property OnAfterGetContent ;
	__property Styles ;
	__property StylesFile ;
	__property WebPageItems ;
	__property EnableXMLIslands ;
	__property TReconcileGrid* ReconcileGrid = {read=FReconcileGrid, write=SetReconcileGrid};
};


class PACKAGE TFieldNameColumn;
class PACKAGE TFieldNameColumn : public TReconcileColumn
{
	typedef TReconcileColumn inherited;

public:
	__fastcall TFieldNameColumn(Classes::TComponent* AOwner);
public:
	#pragma option push -w-inl
	inline __fastcall virtual ~TFieldNameColumn(void) { }
	#pragma option pop

};


class PACKAGE TModifiedColumn;
class PACKAGE TModifiedColumn : public TReconcileColumn
{
	typedef TReconcileColumn inherited;

public:
	__fastcall TModifiedColumn(Classes::TComponent* AOwner);
public:
	#pragma option push -w-inl
	inline __fastcall virtual ~TModifiedColumn(void) { }
	#pragma option pop

};

class PACKAGE TConflictingColumn;
class PACKAGE TConflictingColumn : public TReconcileColumn
{
	typedef TReconcileColumn inherited;

public:
	__fastcall TConflictingColumn(Classes::TComponent* AOwner);
public:
	#pragma option push -w-inl
	inline __fastcall virtual ~TConflictingColumn(void) { }
	#pragma option pop

};

class PACKAGE TOriginalColumn;
class PACKAGE TOriginalColumn : public TReconcileColumn
{
	typedef TReconcileColumn inherited;

public:
	__fastcall TOriginalColumn(Classes::TComponent* AOwner);
public:
	#pragma option push -w-inl
	inline __fastcall virtual ~TOriginalColumn(void) { }
	#pragma option pop

};

class PACKAGE TReconcilePageElements;
class PACKAGE TReconcilePageElements : public Midprod::TMidasPageElements
{
	typedef Midprod::TMidasPageElements inherited;

public:
	AnsiString ReconcileGridContent;
public:
	#pragma option push -w-inl
	inline __fastcall TReconcilePageElements(void) : Midprod::TMidasPageElements() { }
	#pragma option pop
	#pragma option push -w-inl
	inline __fastcall virtual ~TReconcilePageElements(void) { }
	#pragma option pop
	
};

//-- var, const, procedure ---------------------------------------------------

}	/* namespace Reconcileprod */
#if !defined(NO_IMPLICIT_NAMESPACE_USE)
using namespace Reconcileprod;
#endif
//-- end unit ----------------------------------------------------------------
#endif
 