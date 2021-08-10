// Borland C++ Builder
// Copyright (c) 1995, 1999 by Borland International
// All rights reserved

// (DO NOT EDIT: machine generated header) 'DRTable.pas' rev: 5.00

#ifndef DRTableHPP
#define DRTableHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <DBTables.hpp>	// Pascal unit
#include <Db.hpp>	// Pascal unit
#include <Bde.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <SysUtils.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Drtable
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TDRList;
class PASCALIMPLEMENTATION TDRList : public Dbtables::TBDEDataSet 
{
	typedef Dbtables::TBDEDataSet inherited;
	
protected:
	virtual Bde::hDBICur __fastcall CreateHandle(void);
public:
	#pragma option push -w-inl
	/* TBDEDataSet.Create */ inline __fastcall virtual TDRList(Classes::TComponent* AOwner) : Dbtables::TBDEDataSet(
		AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TBDEDataSet.Destroy */ inline __fastcall virtual ~TDRList(void) { }
	#pragma option pop
	
};


class DELPHICLASS TDRDataSet;
class PASCALIMPLEMENTATION TDRDataSet : public Dbtables::TBDEDataSet 
{
	typedef Dbtables::TBDEDataSet inherited;
	
private:
	Bde::_hDBIObj *FDBIDR;
	
public:
	__property Bde::hDBIDR DRHandle = {read=FDBIDR, write=FDBIDR};
public:
	#pragma option push -w-inl
	/* TBDEDataSet.Create */ inline __fastcall virtual TDRDataSet(Classes::TComponent* AOwner) : Dbtables::TBDEDataSet(
		AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TBDEDataSet.Destroy */ inline __fastcall virtual ~TDRDataSet(void) { }
	#pragma option pop
	
};


class DELPHICLASS TDRObjectDescList;
class PASCALIMPLEMENTATION TDRObjectDescList : public TDRDataSet 
{
	typedef TDRDataSet inherited;
	
protected:
	virtual Bde::hDBICur __fastcall CreateHandle(void);
public:
	#pragma option push -w-inl
	/* TBDEDataSet.Create */ inline __fastcall virtual TDRObjectDescList(Classes::TComponent* AOwner) : 
		TDRDataSet(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TBDEDataSet.Destroy */ inline __fastcall virtual ~TDRObjectDescList(void) { }
	#pragma option pop
	
};


class DELPHICLASS TDRObjectItems;
class PASCALIMPLEMENTATION TDRObjectItems : public TDRDataSet 
{
	typedef TDRDataSet inherited;
	
protected:
	AnsiString FObjectName;
public:
	#pragma option push -w-inl
	/* TBDEDataSet.Create */ inline __fastcall virtual TDRObjectItems(Classes::TComponent* AOwner) : TDRDataSet(
		AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TBDEDataSet.Destroy */ inline __fastcall virtual ~TDRObjectItems(void) { }
	#pragma option pop
	
};


class DELPHICLASS TDRRelationshipDescList;
class PASCALIMPLEMENTATION TDRRelationshipDescList : public TDRObjectItems 
{
	typedef TDRObjectItems inherited;
	
protected:
	virtual Bde::hDBICur __fastcall CreateHandle(void);
	
__published:
	__property AnsiString ObjectTypeName = {read=FObjectName, write=FObjectName};
public:
	#pragma option push -w-inl
	/* TBDEDataSet.Create */ inline __fastcall virtual TDRRelationshipDescList(Classes::TComponent* AOwner
		) : TDRObjectItems(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TBDEDataSet.Destroy */ inline __fastcall virtual ~TDRRelationshipDescList(void) { }
	#pragma option pop
	
};


class DELPHICLASS TDRAttrDescList;
class PASCALIMPLEMENTATION TDRAttrDescList : public TDRObjectItems 
{
	typedef TDRObjectItems inherited;
	
protected:
	virtual Bde::hDBICur __fastcall CreateHandle(void);
	
__published:
	__property AnsiString TypeName = {read=FObjectName, write=FObjectName};
public:
	#pragma option push -w-inl
	/* TBDEDataSet.Create */ inline __fastcall virtual TDRAttrDescList(Classes::TComponent* AOwner) : TDRObjectItems(
		AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TBDEDataSet.Destroy */ inline __fastcall virtual ~TDRAttrDescList(void) { }
	#pragma option pop
	
};


class DELPHICLASS TDRInstanceItems;
class PASCALIMPLEMENTATION TDRInstanceItems : public TDRObjectItems 
{
	typedef TDRObjectItems inherited;
	
private:
	AnsiString FCond;
	
__published:
	__property AnsiString Condition = {read=FCond, write=FCond};
public:
	#pragma option push -w-inl
	/* TBDEDataSet.Create */ inline __fastcall virtual TDRInstanceItems(Classes::TComponent* AOwner) : 
		TDRObjectItems(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TBDEDataSet.Destroy */ inline __fastcall virtual ~TDRInstanceItems(void) { }
	#pragma option pop
	
};


class DELPHICLASS TDRObjectList;
class PASCALIMPLEMENTATION TDRObjectList : public TDRInstanceItems 
{
	typedef TDRInstanceItems inherited;
	
private:
	AnsiString FRelName;
	#pragma pack(push, 1)
	Bde::DRObject FSource;
	#pragma pack(pop)
	
	
protected:
	virtual Bde::hDBICur __fastcall CreateHandle(void);
	
public:
	void __fastcall NavigateFrom(const Bde::DRObject &ASource, const AnsiString ARelationship);
	
__published:
	__property AnsiString ObjectTypeName = {read=FObjectName, write=FObjectName};
public:
	#pragma option push -w-inl
	/* TBDEDataSet.Create */ inline __fastcall virtual TDRObjectList(Classes::TComponent* AOwner) : TDRInstanceItems(
		AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TBDEDataSet.Destroy */ inline __fastcall virtual ~TDRObjectList(void) { }
	#pragma option pop
	
};


class DELPHICLASS TDRRelationshipList;
class PASCALIMPLEMENTATION TDRRelationshipList : public TDRInstanceItems 
{
	typedef TDRInstanceItems inherited;
	
private:
	#pragma pack(push, 1)
	Bde::DRObject FSource;
	#pragma pack(pop)
	
	#pragma pack(push, 1)
	Bde::DRObject FTarget;
	#pragma pack(pop)
	
	
protected:
	virtual Bde::hDBICur __fastcall CreateHandle(void);
	
public:
	void __fastcall NavigateFromTo(const Bde::DRObject &ASource, const Bde::DRObject &ATarget);
	
__published:
	__property AnsiString RelationshipTypeName = {read=FObjectName, write=FObjectName};
public:
	#pragma option push -w-inl
	/* TBDEDataSet.Create */ inline __fastcall virtual TDRRelationshipList(Classes::TComponent* AOwner)
		 : TDRInstanceItems(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TBDEDataSet.Destroy */ inline __fastcall virtual ~TDRRelationshipList(void) { }
	#pragma option pop
	
};


class DELPHICLASS TQueryDescription;
class PASCALIMPLEMENTATION TQueryDescription : public Dbtables::TBDEDataSet 
{
	typedef Dbtables::TBDEDataSet inherited;
	
private:
	Dbtables::TQuery* FQuery;
	bool FPrepared;
	
protected:
	virtual Bde::hDBICur __fastcall CreateHandle(void);
	virtual void __fastcall DestroyHandle(void);
	virtual void __fastcall OpenCursor(bool InfoQuery);
	
public:
	__property Dbtables::TQuery* Query = {read=FQuery, write=FQuery};
public:
	#pragma option push -w-inl
	/* TBDEDataSet.Create */ inline __fastcall virtual TQueryDescription(Classes::TComponent* AOwner) : 
		Dbtables::TBDEDataSet(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TBDEDataSet.Destroy */ inline __fastcall virtual ~TQueryDescription(void) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------
extern PACKAGE Bde::DRObject NullDRObject;

}	/* namespace Drtable */
#if !defined(NO_IMPLICIT_NAMESPACE_USE)
using namespace Drtable;
#endif
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// DRTable
