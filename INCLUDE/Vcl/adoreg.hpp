// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'ADOReg.pas' rev: 6.00

#ifndef ADORegHPP
#define ADORegHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <DiagramSupport.hpp>	// Pascal unit
#include <ADODB.hpp>	// Pascal unit
#include <ColnEdit.hpp>	// Pascal unit
#include <DBReg.hpp>	// Pascal unit
#include <DsnDBCst.hpp>	// Pascal unit
#include <DesignEditors.hpp>	// Pascal unit
#include <DesignIntf.hpp>	// Pascal unit
#include <DB.hpp>	// Pascal unit
#include <TreeIntf.hpp>	// Pascal unit
#include <DsnDb.hpp>	// Pascal unit
#include <FldLinks.hpp>	// Pascal unit
#include <Controls.hpp>	// Pascal unit
#include <Forms.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <SysUtils.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Adoreg
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TProviderProperty;
class PASCALIMPLEMENTATION TProviderProperty : public Dbreg::TDBStringProperty 
{
	typedef Dbreg::TDBStringProperty inherited;
	
public:
	virtual void __fastcall GetValueList(Classes::TStrings* List);
public:
	#pragma option push -w-inl
	/* TPropertyEditor.Create */ inline __fastcall virtual TProviderProperty(const Designintf::_di_IDesigner ADesigner, int APropCount) : Dbreg::TDBStringProperty(ADesigner, APropCount) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TPropertyEditor.Destroy */ inline __fastcall virtual ~TProviderProperty(void) { }
	#pragma option pop
	
};


class DELPHICLASS TConnectionStringProperty;
class PASCALIMPLEMENTATION TConnectionStringProperty : public Designeditors::TStringProperty 
{
	typedef Designeditors::TStringProperty inherited;
	
public:
	virtual Designintf::TPropertyAttributes __fastcall GetAttributes(void);
	virtual void __fastcall Edit(void);
public:
	#pragma option push -w-inl
	/* TPropertyEditor.Create */ inline __fastcall virtual TConnectionStringProperty(const Designintf::_di_IDesigner ADesigner, int APropCount) : Designeditors::TStringProperty(ADesigner, APropCount) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TPropertyEditor.Destroy */ inline __fastcall virtual ~TConnectionStringProperty(void) { }
	#pragma option pop
	
};


class DELPHICLASS TCommandTextProperty;
class PASCALIMPLEMENTATION TCommandTextProperty : public Dbreg::TDBStringProperty 
{
	typedef Dbreg::TDBStringProperty inherited;
	
private:
	Adodb::TCommandType FCommandType;
	Adodb::TADOConnection* FConnection;
	
public:
	virtual void __fastcall Activate(void);
	virtual bool __fastcall AutoFill(void);
	virtual void __fastcall Edit(void);
	virtual void __fastcall EditSQLText(void);
	virtual Designintf::TPropertyAttributes __fastcall GetAttributes(void);
	Adodb::TADOConnection* __fastcall GetConnection(bool Opened);
	virtual void __fastcall GetValueList(Classes::TStrings* List);
	__property Adodb::TCommandType CommandType = {read=FCommandType, write=FCommandType, nodefault};
public:
	#pragma option push -w-inl
	/* TPropertyEditor.Create */ inline __fastcall virtual TCommandTextProperty(const Designintf::_di_IDesigner ADesigner, int APropCount) : Dbreg::TDBStringProperty(ADesigner, APropCount) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TPropertyEditor.Destroy */ inline __fastcall virtual ~TCommandTextProperty(void) { }
	#pragma option pop
	
};


class DELPHICLASS TTableNameProperty;
class PASCALIMPLEMENTATION TTableNameProperty : public TCommandTextProperty 
{
	typedef TCommandTextProperty inherited;
	
public:
	virtual void __fastcall Activate(void);
public:
	#pragma option push -w-inl
	/* TPropertyEditor.Create */ inline __fastcall virtual TTableNameProperty(const Designintf::_di_IDesigner ADesigner, int APropCount) : TCommandTextProperty(ADesigner, APropCount) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TPropertyEditor.Destroy */ inline __fastcall virtual ~TTableNameProperty(void) { }
	#pragma option pop
	
};


class DELPHICLASS TProcedureNameProperty;
class PASCALIMPLEMENTATION TProcedureNameProperty : public TCommandTextProperty 
{
	typedef TCommandTextProperty inherited;
	
public:
	virtual void __fastcall Activate(void);
public:
	#pragma option push -w-inl
	/* TPropertyEditor.Create */ inline __fastcall virtual TProcedureNameProperty(const Designintf::_di_IDesigner ADesigner, int APropCount) : TCommandTextProperty(ADesigner, APropCount) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TPropertyEditor.Destroy */ inline __fastcall virtual ~TProcedureNameProperty(void) { }
	#pragma option pop
	
};


class DELPHICLASS TParametersProperty;
class PASCALIMPLEMENTATION TParametersProperty : public Colnedit::TCollectionProperty 
{
	typedef Colnedit::TCollectionProperty inherited;
	
public:
	virtual void __fastcall Edit(void);
public:
	#pragma option push -w-inl
	/* TPropertyEditor.Create */ inline __fastcall virtual TParametersProperty(const Designintf::_di_IDesigner ADesigner, int APropCount) : Colnedit::TCollectionProperty(ADesigner, APropCount) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TPropertyEditor.Destroy */ inline __fastcall virtual ~TParametersProperty(void) { }
	#pragma option pop
	
};


class DELPHICLASS TADODataSetFieldLinkProperty;
class PASCALIMPLEMENTATION TADODataSetFieldLinkProperty : public Fldlinks::TFieldLinkProperty 
{
	typedef Fldlinks::TFieldLinkProperty inherited;
	
private:
	Adodb::TADODataSet* FADODataSet;
	
protected:
	virtual AnsiString __fastcall GetIndexFieldNames();
	virtual AnsiString __fastcall GetMasterFields();
	virtual void __fastcall SetIndexFieldNames(const AnsiString Value);
	virtual void __fastcall SetMasterFields(const AnsiString Value);
	
public:
	virtual void __fastcall Edit(void);
public:
	#pragma option push -w-inl
	/* TFieldLinkProperty.CreateWith */ inline __fastcall virtual TADODataSetFieldLinkProperty(Db::TDataSet* ADataSet) : Fldlinks::TFieldLinkProperty(ADataSet) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TPropertyEditor.Create */ inline __fastcall virtual TADODataSetFieldLinkProperty(const Designintf::_di_IDesigner ADesigner, int APropCount) : Fldlinks::TFieldLinkProperty(ADesigner, APropCount) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TPropertyEditor.Destroy */ inline __fastcall virtual ~TADODataSetFieldLinkProperty(void) { }
	#pragma option pop
	
};


class DELPHICLASS TADOTableFieldLinkProperty;
class PASCALIMPLEMENTATION TADOTableFieldLinkProperty : public Fldlinks::TFieldLinkProperty 
{
	typedef Fldlinks::TFieldLinkProperty inherited;
	
private:
	Adodb::TADOTable* FTable;
	
protected:
	virtual AnsiString __fastcall GetIndexFieldNames();
	virtual AnsiString __fastcall GetMasterFields();
	virtual void __fastcall SetIndexFieldNames(const AnsiString Value);
	virtual void __fastcall SetMasterFields(const AnsiString Value);
	
public:
	virtual void __fastcall Edit(void);
public:
	#pragma option push -w-inl
	/* TFieldLinkProperty.CreateWith */ inline __fastcall virtual TADOTableFieldLinkProperty(Db::TDataSet* ADataSet) : Fldlinks::TFieldLinkProperty(ADataSet) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TPropertyEditor.Create */ inline __fastcall virtual TADOTableFieldLinkProperty(const Designintf::_di_IDesigner ADesigner, int APropCount) : Fldlinks::TFieldLinkProperty(ADesigner, APropCount) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TPropertyEditor.Destroy */ inline __fastcall virtual ~TADOTableFieldLinkProperty(void) { }
	#pragma option pop
	
};


class DELPHICLASS TADOIndexNameProperty;
class PASCALIMPLEMENTATION TADOIndexNameProperty : public Dbreg::TDBStringProperty 
{
	typedef Dbreg::TDBStringProperty inherited;
	
public:
	virtual void __fastcall GetValueList(Classes::TStrings* List);
public:
	#pragma option push -w-inl
	/* TPropertyEditor.Create */ inline __fastcall virtual TADOIndexNameProperty(const Designintf::_di_IDesigner ADesigner, int APropCount) : Dbreg::TDBStringProperty(ADesigner, APropCount) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TPropertyEditor.Destroy */ inline __fastcall virtual ~TADOIndexNameProperty(void) { }
	#pragma option pop
	
};


class DELPHICLASS TADOConnectionEditor;
class PASCALIMPLEMENTATION TADOConnectionEditor : public Designeditors::TComponentEditor 
{
	typedef Designeditors::TComponentEditor inherited;
	
public:
	virtual void __fastcall ExecuteVerb(int Index);
	virtual AnsiString __fastcall GetVerb(int Index);
	virtual int __fastcall GetVerbCount(void);
public:
	#pragma option push -w-inl
	/* TComponentEditor.Create */ inline __fastcall virtual TADOConnectionEditor(Classes::TComponent* AComponent, Designintf::_di_IDesigner ADesigner) : Designeditors::TComponentEditor(AComponent, ADesigner) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TADOConnectionEditor(void) { }
	#pragma option pop
	
};


class DELPHICLASS TADOCommandEditor;
class PASCALIMPLEMENTATION TADOCommandEditor : public Designeditors::TComponentEditor 
{
	typedef Designeditors::TComponentEditor inherited;
	
public:
	virtual void __fastcall ExecuteVerb(int Index);
	virtual AnsiString __fastcall GetVerb(int Index);
	virtual int __fastcall GetVerbCount(void);
public:
	#pragma option push -w-inl
	/* TComponentEditor.Create */ inline __fastcall virtual TADOCommandEditor(Classes::TComponent* AComponent, Designintf::_di_IDesigner ADesigner) : Designeditors::TComponentEditor(AComponent, ADesigner) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TADOCommandEditor(void) { }
	#pragma option pop
	
};


class DELPHICLASS TADODataSetEditor;
class PASCALIMPLEMENTATION TADODataSetEditor : public Dbreg::TDataSetEditor 
{
	typedef Dbreg::TDataSetEditor inherited;
	
private:
	bool FCanCreate;
	
public:
	virtual void __fastcall ExecuteVerb(int Index);
	virtual AnsiString __fastcall GetVerb(int Index);
	virtual int __fastcall GetVerbCount(void);
public:
	#pragma option push -w-inl
	/* TComponentEditor.Create */ inline __fastcall virtual TADODataSetEditor(Classes::TComponent* AComponent, Designintf::_di_IDesigner ADesigner) : Dbreg::TDataSetEditor(AComponent, ADesigner) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TADODataSetEditor(void) { }
	#pragma option pop
	
};


class DELPHICLASS TADOConnectionSprig;
class PASCALIMPLEMENTATION TADOConnectionSprig : public Treeintf::TComponentSprig 
{
	typedef Treeintf::TComponentSprig inherited;
	
public:
	virtual bool __fastcall AnyProblems(void);
	virtual AnsiString __fastcall Caption();
public:
	#pragma option push -w-inl
	/* TComponentSprig.Create */ inline __fastcall virtual TADOConnectionSprig(Classes::TPersistent* AItem)/* overload */ : Treeintf::TComponentSprig(AItem) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TSprig.Destroy */ inline __fastcall virtual ~TADOConnectionSprig(void) { }
	#pragma option pop
	
};


class DELPHICLASS TADOImpliedConnectionSprig;
class PASCALIMPLEMENTATION TADOImpliedConnectionSprig : public Treeintf::TTransientSprig 
{
	typedef Treeintf::TTransientSprig inherited;
	
private:
	AnsiString FConnectionString;
	
public:
	virtual bool __fastcall AnyProblems(void);
	virtual AnsiString __fastcall UniqueName();
	virtual AnsiString __fastcall Caption();
	virtual TMetaClass* __fastcall ItemClass(void);
public:
	#pragma option push -w-inl
	/* TSprig.Create */ inline __fastcall virtual TADOImpliedConnectionSprig(Classes::TPersistent* AItem)/* overload */ : Treeintf::TTransientSprig(AItem) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TSprig.Destroy */ inline __fastcall virtual ~TADOImpliedConnectionSprig(void) { }
	#pragma option pop
	
};


class DELPHICLASS TRDSConnectionSprig;
class PASCALIMPLEMENTATION TRDSConnectionSprig : public Treeintf::TComponentSprig 
{
	typedef Treeintf::TComponentSprig inherited;
	
public:
	#pragma option push -w-inl
	/* TComponentSprig.Create */ inline __fastcall virtual TRDSConnectionSprig(Classes::TPersistent* AItem)/* overload */ : Treeintf::TComponentSprig(AItem) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TSprig.Destroy */ inline __fastcall virtual ~TRDSConnectionSprig(void) { }
	#pragma option pop
	
};


class DELPHICLASS TADOCommandSprig;
class PASCALIMPLEMENTATION TADOCommandSprig : public Treeintf::TComponentSprig 
{
	typedef Treeintf::TComponentSprig inherited;
	
public:
	virtual void __fastcall FigureParent(void);
	virtual bool __fastcall DragDropTo(Treeintf::TSprig* AItem);
	virtual bool __fastcall DragOverTo(Treeintf::TSprig* AItem);
	virtual bool __fastcall AnyProblems(void);
	/* virtual class method */ virtual bool __fastcall PaletteOverTo(TMetaClass* vmt, Treeintf::TSprig* AParent, TMetaClass* AClass);
	virtual AnsiString __fastcall Caption();
public:
	#pragma option push -w-inl
	/* TComponentSprig.Create */ inline __fastcall virtual TADOCommandSprig(Classes::TPersistent* AItem)/* overload */ : Treeintf::TComponentSprig(AItem) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TSprig.Destroy */ inline __fastcall virtual ~TADOCommandSprig(void) { }
	#pragma option pop
	
};


class DELPHICLASS TADOCommandIsland;
class PASCALIMPLEMENTATION TADOCommandIsland : public Diagramsupport::TIsland 
{
	typedef Diagramsupport::TIsland inherited;
	
public:
	virtual bool __fastcall VisibleTreeParent(void);
public:
	#pragma option push -w-inl
	/* TIsland.Create */ inline __fastcall virtual TADOCommandIsland(void)/* overload */ : Diagramsupport::TIsland() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TIsland.Destroy */ inline __fastcall virtual ~TADOCommandIsland(void) { }
	#pragma option pop
	
};


class DELPHICLASS TCustomADODataSetSprig;
class PASCALIMPLEMENTATION TCustomADODataSetSprig : public Dsndb::TDataSetSprig 
{
	typedef Dsndb::TDataSetSprig inherited;
	
public:
	virtual void __fastcall FigureParent(void);
	virtual bool __fastcall AnyProblems(void);
	virtual bool __fastcall DragDropTo(Treeintf::TSprig* AItem);
	virtual bool __fastcall DragOverTo(Treeintf::TSprig* AItem);
	/* virtual class method */ virtual bool __fastcall PaletteOverTo(TMetaClass* vmt, Treeintf::TSprig* AParent, TMetaClass* AClass);
public:
	#pragma option push -w-inl
	/* TComponentSprig.Create */ inline __fastcall virtual TCustomADODataSetSprig(Classes::TPersistent* AItem)/* overload */ : Dsndb::TDataSetSprig(AItem) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TSprig.Destroy */ inline __fastcall virtual ~TCustomADODataSetSprig(void) { }
	#pragma option pop
	
};


class DELPHICLASS TADODataSetSprig;
class PASCALIMPLEMENTATION TADODataSetSprig : public TCustomADODataSetSprig 
{
	typedef TCustomADODataSetSprig inherited;
	
public:
	virtual void __fastcall FigureParent(void);
	virtual bool __fastcall AnyProblems(void);
	virtual bool __fastcall DragDropTo(Treeintf::TSprig* AItem);
	virtual bool __fastcall DragOverTo(Treeintf::TSprig* AItem);
	/* virtual class method */ virtual bool __fastcall PaletteOverTo(TMetaClass* vmt, Treeintf::TSprig* AParent, TMetaClass* AClass);
	virtual AnsiString __fastcall Caption();
public:
	#pragma option push -w-inl
	/* TComponentSprig.Create */ inline __fastcall virtual TADODataSetSprig(Classes::TPersistent* AItem)/* overload */ : TCustomADODataSetSprig(AItem) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TSprig.Destroy */ inline __fastcall virtual ~TADODataSetSprig(void) { }
	#pragma option pop
	
};


class DELPHICLASS TADOTableSprig;
class PASCALIMPLEMENTATION TADOTableSprig : public TCustomADODataSetSprig 
{
	typedef TCustomADODataSetSprig inherited;
	
public:
	virtual bool __fastcall AnyProblems(void);
	virtual AnsiString __fastcall Caption();
public:
	#pragma option push -w-inl
	/* TComponentSprig.Create */ inline __fastcall virtual TADOTableSprig(Classes::TPersistent* AItem)/* overload */ : TCustomADODataSetSprig(AItem) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TSprig.Destroy */ inline __fastcall virtual ~TADOTableSprig(void) { }
	#pragma option pop
	
};


class DELPHICLASS TADOStoredProcSprig;
class PASCALIMPLEMENTATION TADOStoredProcSprig : public TCustomADODataSetSprig 
{
	typedef TCustomADODataSetSprig inherited;
	
public:
	virtual bool __fastcall AnyProblems(void);
	virtual AnsiString __fastcall Caption();
public:
	#pragma option push -w-inl
	/* TComponentSprig.Create */ inline __fastcall virtual TADOStoredProcSprig(Classes::TPersistent* AItem)/* overload */ : TCustomADODataSetSprig(AItem) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TSprig.Destroy */ inline __fastcall virtual ~TADOStoredProcSprig(void) { }
	#pragma option pop
	
};


class DELPHICLASS TADOQuerySprig;
class PASCALIMPLEMENTATION TADOQuerySprig : public TCustomADODataSetSprig 
{
	typedef TCustomADODataSetSprig inherited;
	
public:
	virtual bool __fastcall AnyProblems(void);
public:
	#pragma option push -w-inl
	/* TComponentSprig.Create */ inline __fastcall virtual TADOQuerySprig(Classes::TPersistent* AItem)/* overload */ : TCustomADODataSetSprig(AItem) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TSprig.Destroy */ inline __fastcall virtual ~TADOQuerySprig(void) { }
	#pragma option pop
	
};


class DELPHICLASS TCustomADODataSetIsland;
class PASCALIMPLEMENTATION TCustomADODataSetIsland : public Dsndb::TDataSetIsland 
{
	typedef Dsndb::TDataSetIsland inherited;
	
public:
	virtual bool __fastcall VisibleTreeParent(void);
public:
	#pragma option push -w-inl
	/* TIsland.Create */ inline __fastcall virtual TCustomADODataSetIsland(void)/* overload */ : Dsndb::TDataSetIsland() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TIsland.Destroy */ inline __fastcall virtual ~TCustomADODataSetIsland(void) { }
	#pragma option pop
	
};


class DELPHICLASS TADODataSetIsland;
class PASCALIMPLEMENTATION TADODataSetIsland : public TCustomADODataSetIsland 
{
	typedef TCustomADODataSetIsland inherited;
	
public:
	#pragma option push -w-inl
	/* TIsland.Create */ inline __fastcall virtual TADODataSetIsland(void)/* overload */ : TCustomADODataSetIsland() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TIsland.Destroy */ inline __fastcall virtual ~TADODataSetIsland(void) { }
	#pragma option pop
	
};


class DELPHICLASS TADOTableIsland;
class PASCALIMPLEMENTATION TADOTableIsland : public TCustomADODataSetIsland 
{
	typedef TCustomADODataSetIsland inherited;
	
public:
	#pragma option push -w-inl
	/* TIsland.Create */ inline __fastcall virtual TADOTableIsland(void)/* overload */ : TCustomADODataSetIsland() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TIsland.Destroy */ inline __fastcall virtual ~TADOTableIsland(void) { }
	#pragma option pop
	
};


class DELPHICLASS TADOQueryIsland;
class PASCALIMPLEMENTATION TADOQueryIsland : public TCustomADODataSetIsland 
{
	typedef TCustomADODataSetIsland inherited;
	
public:
	#pragma option push -w-inl
	/* TIsland.Create */ inline __fastcall virtual TADOQueryIsland(void)/* overload */ : TCustomADODataSetIsland() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TIsland.Destroy */ inline __fastcall virtual ~TADOQueryIsland(void) { }
	#pragma option pop
	
};


class DELPHICLASS TCustomADODataSetMasterDetailBridge;
class PASCALIMPLEMENTATION TCustomADODataSetMasterDetailBridge : public Dsndb::TMasterDetailBridge 
{
	typedef Dsndb::TMasterDetailBridge inherited;
	
public:
	/* virtual class method */ virtual Db::TDataSource* __fastcall GetOmegaSource(TMetaClass* vmt, Classes::TPersistent* AItem);
	/* virtual class method */ virtual void __fastcall SetOmegaSource(TMetaClass* vmt, Classes::TPersistent* AItem, Db::TDataSource* ADataSource);
	virtual AnsiString __fastcall Caption();
public:
	#pragma option push -w-inl
	/* TBridge.Create */ inline __fastcall virtual TCustomADODataSetMasterDetailBridge(Diagramsupport::TIsland* AAlpha, Diagramsupport::TIsland* AOmega)/* overload */ : Dsndb::TMasterDetailBridge(AAlpha, AOmega) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TBridge.Destroy */ inline __fastcall virtual ~TCustomADODataSetMasterDetailBridge(void) { }
	#pragma option pop
	
};


class DELPHICLASS TADODataSetMasterDetailBridge;
class PASCALIMPLEMENTATION TADODataSetMasterDetailBridge : public TCustomADODataSetMasterDetailBridge 
{
	typedef TCustomADODataSetMasterDetailBridge inherited;
	
public:
	virtual bool __fastcall CanEdit(void);
	virtual bool __fastcall Edit(void);
	/* virtual class method */ virtual TMetaClass* __fastcall OmegaIslandClass(TMetaClass* vmt);
public:
	#pragma option push -w-inl
	/* TBridge.Create */ inline __fastcall virtual TADODataSetMasterDetailBridge(Diagramsupport::TIsland* AAlpha, Diagramsupport::TIsland* AOmega)/* overload */ : TCustomADODataSetMasterDetailBridge(AAlpha, AOmega) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TBridge.Destroy */ inline __fastcall virtual ~TADODataSetMasterDetailBridge(void) { }
	#pragma option pop
	
};


class DELPHICLASS TADOTableMasterDetailBridge;
class PASCALIMPLEMENTATION TADOTableMasterDetailBridge : public TCustomADODataSetMasterDetailBridge 
{
	typedef TCustomADODataSetMasterDetailBridge inherited;
	
public:
	virtual bool __fastcall CanEdit(void);
	virtual bool __fastcall Edit(void);
	/* virtual class method */ virtual TMetaClass* __fastcall OmegaIslandClass(TMetaClass* vmt);
public:
	#pragma option push -w-inl
	/* TBridge.Create */ inline __fastcall virtual TADOTableMasterDetailBridge(Diagramsupport::TIsland* AAlpha, Diagramsupport::TIsland* AOmega)/* overload */ : TCustomADODataSetMasterDetailBridge(AAlpha, AOmega) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TBridge.Destroy */ inline __fastcall virtual ~TADOTableMasterDetailBridge(void) { }
	#pragma option pop
	
};


class DELPHICLASS TADOQueryMasterDetailBridge;
class PASCALIMPLEMENTATION TADOQueryMasterDetailBridge : public TCustomADODataSetMasterDetailBridge 
{
	typedef TCustomADODataSetMasterDetailBridge inherited;
	
public:
	/* virtual class method */ virtual TMetaClass* __fastcall OmegaIslandClass(TMetaClass* vmt);
public:
	#pragma option push -w-inl
	/* TBridge.Create */ inline __fastcall virtual TADOQueryMasterDetailBridge(Diagramsupport::TIsland* AAlpha, Diagramsupport::TIsland* AOmega)/* overload */ : TCustomADODataSetMasterDetailBridge(AAlpha, AOmega) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TBridge.Destroy */ inline __fastcall virtual ~TADOQueryMasterDetailBridge(void) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------
#define cConnectionSprigPrefix "<ImpliedConnection>"
extern PACKAGE void __fastcall Register(void);

}	/* namespace Adoreg */
using namespace Adoreg;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// ADOReg
