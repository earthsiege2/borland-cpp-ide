// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'MXTABLES.pas' rev: 6.00

#ifndef MXTABLESHPP
#define MXTABLESHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <Mxarrays.hpp>	// Pascal unit
#include <MXQEDCOM.hpp>	// Pascal unit
#include <MXQPARSE.hpp>	// Pascal unit
#include <MXCOMMON.hpp>	// Pascal unit
#include <DBTables.hpp>	// Pascal unit
#include <BDE.hpp>	// Pascal unit
#include <DBCommon.hpp>	// Pascal unit
#include <DB.hpp>	// Pascal unit
#include <Controls.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <Graphics.hpp>	// Pascal unit
#include <SysUtils.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Mxtables
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TQueryDim;
class PASCALIMPLEMENTATION TQueryDim : public Mxcommon::TDimensionItem 
{
	typedef Mxcommon::TDimensionItem inherited;
	
public:
	__property Active ;
public:
	#pragma option push -w-inl
	/* TDimensionItem.Create */ inline __fastcall virtual TQueryDim(Classes::TCollection* Collection) : Mxcommon::TDimensionItem(Collection) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TCollectionItem.Destroy */ inline __fastcall virtual ~TQueryDim(void) { }
	#pragma option pop
	
};


typedef TMetaClass*TQueryDimClass;

class DELPHICLASS TQueryDims;
class PASCALIMPLEMENTATION TQueryDims : public Mxcommon::TDimensionItems 
{
	typedef Mxcommon::TDimensionItems inherited;
	
public:
	TQueryDim* operator[](int Index) { return Items[Index]; }
	
protected:
	TQueryDim* __fastcall GetQueryDim(int Index);
	void __fastcall SetQueryDim(int Index, TQueryDim* Value);
	__fastcall TQueryDims(Classes::TPersistent* Owner, TMetaClass* ItemClass);
	
public:
	HIDESBASE TQueryDim* __fastcall Add(void);
	__property TQueryDim* Items[int Index] = {read=GetQueryDim, write=SetQueryDim/*, default*/};
public:
	#pragma option push -w-inl
	/* TCollection.Destroy */ inline __fastcall virtual ~TQueryDims(void) { }
	#pragma option pop
	
};


class DELPHICLASS TDecisionQuery;
class PASCALIMPLEMENTATION TDecisionQuery : public Dbtables::TQuery 
{
	typedef Dbtables::TQuery inherited;
	
public:
	#pragma option push -w-inl
	/* TQuery.Create */ inline __fastcall virtual TDecisionQuery(Classes::TComponent* AOwner) : Dbtables::TQuery(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TQuery.Destroy */ inline __fastcall virtual ~TDecisionQuery(void) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------
extern PACKAGE Mxcommon::TQueryError __fastcall BuildMasterDimensionMap(Mxqparse::TXtabQuery* myQuery, TQueryDims* Map);
extern PACKAGE Mxcommon::TQueryError __fastcall BuildDimensionMap(Mxqparse::TXtabQuery* myQuery, TQueryDims* Map, AnsiString SQLString);
extern PACKAGE Mxcommon::TQueryError __fastcall AddDimensionItem(Mxqparse::TXtabQuery* myQuery, TQueryDims* Map, int index, AnsiString Name);
extern PACKAGE Mxcommon::TQueryError __fastcall RemoveDimensionItem(Mxqparse::TXtabQuery* myQuery, TQueryDims* Map, int index);

}	/* namespace Mxtables */
using namespace Mxtables;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// MXTABLES
