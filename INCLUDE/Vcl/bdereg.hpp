// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'BDEReg.pas' rev: 6.00

#ifndef BDERegHPP
#define BDERegHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <DiagramSupport.hpp>	// Pascal unit
#include <DsnDb.hpp>	// Pascal unit
#include <TreeIntf.hpp>	// Pascal unit
#include <DrTable.hpp>	// Pascal unit
#include <CNCOLEDT.hpp>	// Pascal unit
#include <FldLinks.hpp>	// Pascal unit
#include <Updsqled.hpp>	// Pascal unit
#include <Ixedit.hpp>	// Pascal unit
#include <Dbedit.hpp>	// Pascal unit
#include <DesignEditors.hpp>	// Pascal unit
#include <DesignIntf.hpp>	// Pascal unit
#include <TblDsgn.hpp>	// Pascal unit
#include <ColnEdit.hpp>	// Pascal unit
#include <GqeDelph.hpp>	// Pascal unit
#include <bdeconst.hpp>	// Pascal unit
#include <Dbxplor.hpp>	// Pascal unit
#include <DBReg.hpp>	// Pascal unit
#include <DSAttrA.hpp>	// Pascal unit
#include <DSAttrS.hpp>	// Pascal unit
#include <DsnDBCst.hpp>	// Pascal unit
#include <DRIntf.hpp>	// Pascal unit
#include <DB.hpp>	// Pascal unit
#include <DBTables.hpp>	// Pascal unit
#include <Menus.hpp>	// Pascal unit
#include <DSDesign.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <SysUtils.hpp>	// Pascal unit
#include <FileCtrl.hpp>	// Pascal unit
#include <dblookup.hpp>	// Pascal unit
#include <Dialogs.hpp>	// Pascal unit
#include <LibHelp.hpp>	// Pascal unit
#include <RSCONSTS.hpp>	// Pascal unit
#include <Report.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Bdereg
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TTableFieldLinkProperty;
class PASCALIMPLEMENTATION TTableFieldLinkProperty : public Fldlinks::TFieldLinkProperty 
{
	typedef Fldlinks::TFieldLinkProperty inherited;
	
private:
	Dbtables::TTable* FTable;
	
protected:
	virtual void __fastcall GetFieldNamesForIndex(Classes::TStrings* List);
	virtual bool __fastcall GetIndexBased(void);
	virtual Db::TIndexDefs* __fastcall GetIndexDefs(void);
	virtual AnsiString __fastcall GetIndexFieldNames();
	virtual AnsiString __fastcall GetIndexName();
	virtual AnsiString __fastcall GetMasterFields();
	virtual void __fastcall SetIndexFieldNames(const AnsiString Value);
	virtual void __fastcall SetIndexName(const AnsiString Value);
	virtual void __fastcall SetMasterFields(const AnsiString Value);
	
public:
	__property bool IndexBased = {read=GetIndexBased, nodefault};
	__property Db::TIndexDefs* IndexDefs = {read=GetIndexDefs};
	__property AnsiString IndexFieldNames = {read=GetIndexFieldNames, write=SetIndexFieldNames};
	__property AnsiString IndexName = {read=GetIndexName, write=SetIndexName};
	__property AnsiString MasterFields = {read=GetMasterFields, write=SetMasterFields};
	virtual void __fastcall Edit(void);
public:
	#pragma option push -w-inl
	/* TFieldLinkProperty.CreateWith */ inline __fastcall virtual TTableFieldLinkProperty(Db::TDataSet* ADataSet) : Fldlinks::TFieldLinkProperty(ADataSet) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TPropertyEditor.Create */ inline __fastcall virtual TTableFieldLinkProperty(const Designintf::_di_IDesigner ADesigner, int APropCount) : Fldlinks::TFieldLinkProperty(ADesigner, APropCount) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TPropertyEditor.Destroy */ inline __fastcall virtual ~TTableFieldLinkProperty(void) { }
	#pragma option pop
	
};


class DELPHICLASS TSessionSprig;
class PASCALIMPLEMENTATION TSessionSprig : public Treeintf::TComponentSprig 
{
	typedef Treeintf::TComponentSprig inherited;
	
public:
	virtual AnsiString __fastcall Name();
	virtual AnsiString __fastcall Caption();
	virtual bool __fastcall AnyProblems(void);
public:
	#pragma option push -w-inl
	/* TComponentSprig.Create */ inline __fastcall virtual TSessionSprig(Classes::TPersistent* AItem)/* overload */ : Treeintf::TComponentSprig(AItem) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TSprig.Destroy */ inline __fastcall virtual ~TSessionSprig(void) { }
	#pragma option pop
	
};


class DELPHICLASS TDefaultSessionSprig;
class PASCALIMPLEMENTATION TDefaultSessionSprig : public Treeintf::TTransientSprig 
{
	typedef Treeintf::TTransientSprig inherited;
	
public:
	virtual AnsiString __fastcall UniqueName();
	virtual AnsiString __fastcall Caption();
	virtual TMetaClass* __fastcall ItemClass(void);
public:
	#pragma option push -w-inl
	/* TSprig.Create */ inline __fastcall virtual TDefaultSessionSprig(Classes::TPersistent* AItem)/* overload */ : Treeintf::TTransientSprig(AItem) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TSprig.Destroy */ inline __fastcall virtual ~TDefaultSessionSprig(void) { }
	#pragma option pop
	
};


class DELPHICLASS TImpliedSessionSprig;
class PASCALIMPLEMENTATION TImpliedSessionSprig : public Treeintf::TTransientSprig 
{
	typedef Treeintf::TTransientSprig inherited;
	
private:
	AnsiString FSessionName;
	
public:
	virtual AnsiString __fastcall UniqueName();
	virtual AnsiString __fastcall Caption();
	virtual TMetaClass* __fastcall ItemClass(void);
public:
	#pragma option push -w-inl
	/* TSprig.Create */ inline __fastcall virtual TImpliedSessionSprig(Classes::TPersistent* AItem)/* overload */ : Treeintf::TTransientSprig(AItem) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TSprig.Destroy */ inline __fastcall virtual ~TImpliedSessionSprig(void) { }
	#pragma option pop
	
};


class DELPHICLASS TDatabaseSprig;
class PASCALIMPLEMENTATION TDatabaseSprig : public Treeintf::TComponentSprig 
{
	typedef Treeintf::TComponentSprig inherited;
	
public:
	virtual AnsiString __fastcall Name();
	virtual AnsiString __fastcall Caption();
	virtual bool __fastcall AnyProblems(void);
	virtual void __fastcall FigureParent(void);
	virtual bool __fastcall DragDropTo(Treeintf::TSprig* AItem);
	virtual bool __fastcall DragOverTo(Treeintf::TSprig* AItem);
	/* virtual class method */ virtual bool __fastcall PaletteOverTo(TMetaClass* vmt, Treeintf::TSprig* AParent, TMetaClass* AClass);
public:
	#pragma option push -w-inl
	/* TComponentSprig.Create */ inline __fastcall virtual TDatabaseSprig(Classes::TPersistent* AItem)/* overload */ : Treeintf::TComponentSprig(AItem) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TSprig.Destroy */ inline __fastcall virtual ~TDatabaseSprig(void) { }
	#pragma option pop
	
};


class DELPHICLASS TImpliedDatabaseSprig;
class PASCALIMPLEMENTATION TImpliedDatabaseSprig : public Treeintf::TTransientSprig 
{
	typedef Treeintf::TTransientSprig inherited;
	
private:
	AnsiString FSessionName;
	AnsiString FAlias;
	
public:
	virtual bool __fastcall AnyProblems(void);
	virtual AnsiString __fastcall UniqueName();
	virtual AnsiString __fastcall Caption();
	virtual TMetaClass* __fastcall ItemClass(void);
	virtual void __fastcall FigureParent(void);
	virtual bool __fastcall DragDropTo(Treeintf::TSprig* AItem);
	virtual bool __fastcall DragOverTo(Treeintf::TSprig* AItem);
public:
	#pragma option push -w-inl
	/* TSprig.Create */ inline __fastcall virtual TImpliedDatabaseSprig(Classes::TPersistent* AItem)/* overload */ : Treeintf::TTransientSprig(AItem) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TSprig.Destroy */ inline __fastcall virtual ~TImpliedDatabaseSprig(void) { }
	#pragma option pop
	
};


class DELPHICLASS TBatchMoveSprig;
class PASCALIMPLEMENTATION TBatchMoveSprig : public Treeintf::TComponentSprig 
{
	typedef Treeintf::TComponentSprig inherited;
	
public:
	virtual bool __fastcall AnyProblems(void);
	virtual AnsiString __fastcall Caption();
public:
	#pragma option push -w-inl
	/* TComponentSprig.Create */ inline __fastcall virtual TBatchMoveSprig(Classes::TPersistent* AItem)/* overload */ : Treeintf::TComponentSprig(AItem) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TSprig.Destroy */ inline __fastcall virtual ~TBatchMoveSprig(void) { }
	#pragma option pop
	
};


class DELPHICLASS TUpdateSQLSprig;
class PASCALIMPLEMENTATION TUpdateSQLSprig : public Treeintf::TComponentSprig 
{
	typedef Treeintf::TComponentSprig inherited;
	
public:
	virtual bool __fastcall AnyProblems(void);
public:
	#pragma option push -w-inl
	/* TComponentSprig.Create */ inline __fastcall virtual TUpdateSQLSprig(Classes::TPersistent* AItem)/* overload */ : Treeintf::TComponentSprig(AItem) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TSprig.Destroy */ inline __fastcall virtual ~TUpdateSQLSprig(void) { }
	#pragma option pop
	
};


class DELPHICLASS TBDEDataSetSprig;
class PASCALIMPLEMENTATION TBDEDataSetSprig : public Dsndb::TDataSetSprig 
{
	typedef Dsndb::TDataSetSprig inherited;
	
public:
	virtual TMetaClass* __fastcall GetDSDesignerClass(void);
public:
	#pragma option push -w-inl
	/* TComponentSprig.Create */ inline __fastcall virtual TBDEDataSetSprig(Classes::TPersistent* AItem)/* overload */ : Dsndb::TDataSetSprig(AItem) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TSprig.Destroy */ inline __fastcall virtual ~TBDEDataSetSprig(void) { }
	#pragma option pop
	
};


class DELPHICLASS TNestedTableSprig;
class PASCALIMPLEMENTATION TNestedTableSprig : public TBDEDataSetSprig 
{
	typedef TBDEDataSetSprig inherited;
	
public:
	/* virtual class method */ virtual AnsiString __fastcall ParentProperty(TMetaClass* vmt);
public:
	#pragma option push -w-inl
	/* TComponentSprig.Create */ inline __fastcall virtual TNestedTableSprig(Classes::TPersistent* AItem)/* overload */ : TBDEDataSetSprig(AItem) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TSprig.Destroy */ inline __fastcall virtual ~TNestedTableSprig(void) { }
	#pragma option pop
	
};


class DELPHICLASS TDBDataSetSprig;
class PASCALIMPLEMENTATION TDBDataSetSprig : public TBDEDataSetSprig 
{
	typedef TBDEDataSetSprig inherited;
	
public:
	virtual bool __fastcall AnyProblems(void);
	virtual void __fastcall FigureParent(void);
	virtual void __fastcall Reparent(void);
	virtual bool __fastcall DragDropTo(Treeintf::TSprig* AItem);
	virtual bool __fastcall DragOverTo(Treeintf::TSprig* AItem);
	/* virtual class method */ virtual bool __fastcall PaletteOverTo(TMetaClass* vmt, Treeintf::TSprig* AParent, TMetaClass* AClass);
public:
	#pragma option push -w-inl
	/* TComponentSprig.Create */ inline __fastcall virtual TDBDataSetSprig(Classes::TPersistent* AItem)/* overload */ : TBDEDataSetSprig(AItem) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TSprig.Destroy */ inline __fastcall virtual ~TDBDataSetSprig(void) { }
	#pragma option pop
	
};


class DELPHICLASS TTableSprig;
class PASCALIMPLEMENTATION TTableSprig : public TDBDataSetSprig 
{
	typedef TDBDataSetSprig inherited;
	
public:
	virtual bool __fastcall AnyProblems(void);
	virtual AnsiString __fastcall Caption();
public:
	#pragma option push -w-inl
	/* TComponentSprig.Create */ inline __fastcall virtual TTableSprig(Classes::TPersistent* AItem)/* overload */ : TDBDataSetSprig(AItem) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TSprig.Destroy */ inline __fastcall virtual ~TTableSprig(void) { }
	#pragma option pop
	
};


class DELPHICLASS TQuerySprig;
class PASCALIMPLEMENTATION TQuerySprig : public TDBDataSetSprig 
{
	typedef TDBDataSetSprig inherited;
	
public:
	virtual bool __fastcall AnyProblems(void);
public:
	#pragma option push -w-inl
	/* TComponentSprig.Create */ inline __fastcall virtual TQuerySprig(Classes::TPersistent* AItem)/* overload */ : TDBDataSetSprig(AItem) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TSprig.Destroy */ inline __fastcall virtual ~TQuerySprig(void) { }
	#pragma option pop
	
};


class DELPHICLASS TStoredProcSprig;
class PASCALIMPLEMENTATION TStoredProcSprig : public TDBDataSetSprig 
{
	typedef TDBDataSetSprig inherited;
	
public:
	virtual bool __fastcall AnyProblems(void);
	virtual AnsiString __fastcall Caption();
public:
	#pragma option push -w-inl
	/* TComponentSprig.Create */ inline __fastcall virtual TStoredProcSprig(Classes::TPersistent* AItem)/* overload */ : TDBDataSetSprig(AItem) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TSprig.Destroy */ inline __fastcall virtual ~TStoredProcSprig(void) { }
	#pragma option pop
	
};


class DELPHICLASS TBDEDataSetIsland;
class PASCALIMPLEMENTATION TBDEDataSetIsland : public Dsndb::TDataSetIsland 
{
	typedef Dsndb::TDataSetIsland inherited;
	
public:
	#pragma option push -w-inl
	/* TIsland.Create */ inline __fastcall virtual TBDEDataSetIsland(void)/* overload */ : Dsndb::TDataSetIsland() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TIsland.Destroy */ inline __fastcall virtual ~TBDEDataSetIsland(void) { }
	#pragma option pop
	
};


class DELPHICLASS TDBDataSetIsland;
class PASCALIMPLEMENTATION TDBDataSetIsland : public TBDEDataSetIsland 
{
	typedef TBDEDataSetIsland inherited;
	
public:
	#pragma option push -w-inl
	/* TIsland.Create */ inline __fastcall virtual TDBDataSetIsland(void)/* overload */ : TBDEDataSetIsland() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TIsland.Destroy */ inline __fastcall virtual ~TDBDataSetIsland(void) { }
	#pragma option pop
	
};


class DELPHICLASS TTableIsland;
class PASCALIMPLEMENTATION TTableIsland : public TDBDataSetIsland 
{
	typedef TDBDataSetIsland inherited;
	
public:
	#pragma option push -w-inl
	/* TIsland.Create */ inline __fastcall virtual TTableIsland(void)/* overload */ : TDBDataSetIsland() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TIsland.Destroy */ inline __fastcall virtual ~TTableIsland(void) { }
	#pragma option pop
	
};


class DELPHICLASS TTableMasterDetailBridge;
class PASCALIMPLEMENTATION TTableMasterDetailBridge : public Dsndb::TMasterDetailBridge 
{
	typedef Dsndb::TMasterDetailBridge inherited;
	
public:
	virtual bool __fastcall CanEdit(void);
	/* virtual class method */ virtual TMetaClass* __fastcall OmegaIslandClass(TMetaClass* vmt);
	/* virtual class method */ virtual Db::TDataSource* __fastcall GetOmegaSource(TMetaClass* vmt, Classes::TPersistent* AItem);
	/* virtual class method */ virtual void __fastcall SetOmegaSource(TMetaClass* vmt, Classes::TPersistent* AItem, Db::TDataSource* ADataSource);
	virtual AnsiString __fastcall Caption();
	virtual bool __fastcall Edit(void);
public:
	#pragma option push -w-inl
	/* TBridge.Create */ inline __fastcall virtual TTableMasterDetailBridge(Diagramsupport::TIsland* AAlpha, Diagramsupport::TIsland* AOmega)/* overload */ : Dsndb::TMasterDetailBridge(AAlpha, AOmega) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TBridge.Destroy */ inline __fastcall virtual ~TTableMasterDetailBridge(void) { }
	#pragma option pop
	
};


class DELPHICLASS TQueryIsland;
class PASCALIMPLEMENTATION TQueryIsland : public TDBDataSetIsland 
{
	typedef TDBDataSetIsland inherited;
	
public:
	#pragma option push -w-inl
	/* TIsland.Create */ inline __fastcall virtual TQueryIsland(void)/* overload */ : TDBDataSetIsland() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TIsland.Destroy */ inline __fastcall virtual ~TQueryIsland(void) { }
	#pragma option pop
	
};


class DELPHICLASS TQueryMasterDetailBridge;
class PASCALIMPLEMENTATION TQueryMasterDetailBridge : public Dsndb::TMasterDetailBridge 
{
	typedef Dsndb::TMasterDetailBridge inherited;
	
public:
	/* virtual class method */ virtual bool __fastcall RemoveMasterFieldsAsWell(TMetaClass* vmt);
	/* virtual class method */ virtual TMetaClass* __fastcall OmegaIslandClass(TMetaClass* vmt);
	/* virtual class method */ virtual Db::TDataSource* __fastcall GetOmegaSource(TMetaClass* vmt, Classes::TPersistent* AItem);
	/* virtual class method */ virtual void __fastcall SetOmegaSource(TMetaClass* vmt, Classes::TPersistent* AItem, Db::TDataSource* ADataSource);
	virtual AnsiString __fastcall Caption();
public:
	#pragma option push -w-inl
	/* TBridge.Create */ inline __fastcall virtual TQueryMasterDetailBridge(Diagramsupport::TIsland* AAlpha, Diagramsupport::TIsland* AOmega)/* overload */ : Dsndb::TMasterDetailBridge(AAlpha, AOmega) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TBridge.Destroy */ inline __fastcall virtual ~TQueryMasterDetailBridge(void) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------
#define cDefaultSessionSprigName "<DefaultSession>"
#define cImpliedSessionSprigPrefix "<ImpliedSession>"
#define cImpliedDatabaseSprigPrefix "<ImpliedDatabase>"
extern PACKAGE AnsiString __fastcall SprigBDESessionName(const AnsiString AName);
extern PACKAGE AnsiString __fastcall SprigBDEImpliedDatabaseName(const AnsiString AName);
extern PACKAGE AnsiString __fastcall SprigBDEImpliedSessionName(const AnsiString AName);
extern PACKAGE void __fastcall Register(void);

}	/* namespace Bdereg */
using namespace Bdereg;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// BDEReg
