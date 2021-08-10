// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'DBReg.pas' rev: 6.00

#ifndef DBRegHPP
#define DBRegHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <DSDesign.hpp>	// Pascal unit
#include <DesignEditors.hpp>	// Pascal unit
#include <DesignIntf.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <SysUtils.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Dbreg
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TDBStringProperty;
class PASCALIMPLEMENTATION TDBStringProperty : public Designeditors::TStringProperty 
{
	typedef Designeditors::TStringProperty inherited;
	
public:
	virtual Designintf::TPropertyAttributes __fastcall GetAttributes(void);
	virtual void __fastcall GetValueList(Classes::TStrings* List);
	virtual void __fastcall GetValues(Classes::TGetStrProc Proc);
public:
	#pragma option push -w-inl
	/* TPropertyEditor.Create */ inline __fastcall virtual TDBStringProperty(const Designintf::_di_IDesigner ADesigner, int APropCount) : Designeditors::TStringProperty(ADesigner, APropCount) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TPropertyEditor.Destroy */ inline __fastcall virtual ~TDBStringProperty(void) { }
	#pragma option pop
	
};


class DELPHICLASS TDataFieldProperty;
class PASCALIMPLEMENTATION TDataFieldProperty : public TDBStringProperty 
{
	typedef TDBStringProperty inherited;
	
public:
	virtual AnsiString __fastcall GetDataSourcePropName();
	virtual void __fastcall GetValueList(Classes::TStrings* List);
public:
	#pragma option push -w-inl
	/* TPropertyEditor.Create */ inline __fastcall virtual TDataFieldProperty(const Designintf::_di_IDesigner ADesigner, int APropCount) : TDBStringProperty(ADesigner, APropCount) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TPropertyEditor.Destroy */ inline __fastcall virtual ~TDataFieldProperty(void) { }
	#pragma option pop
	
};


class DELPHICLASS TDataFieldAggProperty;
class PASCALIMPLEMENTATION TDataFieldAggProperty : public TDBStringProperty 
{
	typedef TDBStringProperty inherited;
	
public:
	virtual AnsiString __fastcall GetDataSourcePropName();
	virtual void __fastcall GetValueList(Classes::TStrings* List);
public:
	#pragma option push -w-inl
	/* TPropertyEditor.Create */ inline __fastcall virtual TDataFieldAggProperty(const Designintf::_di_IDesigner ADesigner, int APropCount) : TDBStringProperty(ADesigner, APropCount) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TPropertyEditor.Destroy */ inline __fastcall virtual ~TDataFieldAggProperty(void) { }
	#pragma option pop
	
};


class DELPHICLASS TDataSetEditor;
class PASCALIMPLEMENTATION TDataSetEditor : public Designeditors::TComponentEditor 
{
	typedef Designeditors::TComponentEditor inherited;
	
protected:
	virtual TMetaClass* __fastcall GetDSDesignerClass(void);
	
public:
	virtual void __fastcall ExecuteVerb(int Index);
	virtual AnsiString __fastcall GetVerb(int Index);
	virtual int __fastcall GetVerbCount(void);
public:
	#pragma option push -w-inl
	/* TComponentEditor.Create */ inline __fastcall virtual TDataSetEditor(Classes::TComponent* AComponent, Designintf::_di_IDesigner ADesigner) : Designeditors::TComponentEditor(AComponent, ADesigner) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TDataSetEditor(void) { }
	#pragma option pop
	
};


class DELPHICLASS TIndexFieldNamesProperty;
class PASCALIMPLEMENTATION TIndexFieldNamesProperty : public TDBStringProperty 
{
	typedef TDBStringProperty inherited;
	
public:
	virtual void __fastcall GetValueList(Classes::TStrings* List);
public:
	#pragma option push -w-inl
	/* TPropertyEditor.Create */ inline __fastcall virtual TIndexFieldNamesProperty(const Designintf::_di_IDesigner ADesigner, int APropCount) : TDBStringProperty(ADesigner, APropCount) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TPropertyEditor.Destroy */ inline __fastcall virtual ~TIndexFieldNamesProperty(void) { }
	#pragma option pop
	
};


class DELPHICLASS TIndexNameProperty;
class PASCALIMPLEMENTATION TIndexNameProperty : public TDBStringProperty 
{
	typedef TDBStringProperty inherited;
	
public:
	virtual void __fastcall GetValueList(Classes::TStrings* List);
public:
	#pragma option push -w-inl
	/* TPropertyEditor.Create */ inline __fastcall virtual TIndexNameProperty(const Designintf::_di_IDesigner ADesigner, int APropCount) : TDBStringProperty(ADesigner, APropCount) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TPropertyEditor.Destroy */ inline __fastcall virtual ~TIndexNameProperty(void) { }
	#pragma option pop
	
};


class DELPHICLASS TListFieldProperty;
class PASCALIMPLEMENTATION TListFieldProperty : public TDataFieldProperty 
{
	typedef TDataFieldProperty inherited;
	
public:
	virtual AnsiString __fastcall GetDataSourcePropName();
public:
	#pragma option push -w-inl
	/* TPropertyEditor.Create */ inline __fastcall virtual TListFieldProperty(const Designintf::_di_IDesigner ADesigner, int APropCount) : TDataFieldProperty(ADesigner, APropCount) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TPropertyEditor.Destroy */ inline __fastcall virtual ~TListFieldProperty(void) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------
extern PACKAGE void __fastcall Register(void);

}	/* namespace Dbreg */
using namespace Dbreg;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// DBReg
