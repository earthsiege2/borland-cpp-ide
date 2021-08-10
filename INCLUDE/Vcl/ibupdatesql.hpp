// Borland C++ Builder
// Copyright (c) 1995, 1999 by Borland International
// All rights reserved

// (DO NOT EDIT: machine generated header) 'IBUpdateSQL.pas' rev: 5.00

#ifndef IBUpdateSQLHPP
#define IBUpdateSQLHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <IBQuery.hpp>	// Pascal unit
#include <IBCustomDataSet.hpp>	// Pascal unit
#include <IB.hpp>	// Pascal unit
#include <StdVCL.hpp>	// Pascal unit
#include <Db.hpp>	// Pascal unit
#include <Controls.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <Graphics.hpp>	// Pascal unit
#include <SysUtils.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Ibupdatesql
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TIBUpdateSQL;
class PASCALIMPLEMENTATION TIBUpdateSQL : public Ibcustomdataset::TIBDataSetUpdateObject 
{
	typedef Ibcustomdataset::TIBDataSetUpdateObject inherited;
	
private:
	Ibcustomdataset::TIBCustomDataSet* FDataSet;
	Ibquery::TIBQuery* FQueries[3];
	Classes::TStrings* FSQLText[3];
	Ibquery::TIBQuery* __fastcall GetQuery(Db::TUpdateKind UpdateKind);
	Classes::TStrings* __fastcall GetSQLIndex(int Index);
	void __fastcall SetSQL(Db::TUpdateKind UpdateKind, Classes::TStrings* Value);
	void __fastcall SetSQLIndex(int Index, Classes::TStrings* Value);
	
protected:
	virtual Classes::TStrings* __fastcall GetSQL(Db::TUpdateKind UpdateKind);
	virtual Ibcustomdataset::TIBCustomDataSet* __fastcall GetDataSet(void);
	virtual void __fastcall SetDataSet(Ibcustomdataset::TIBCustomDataSet* ADataSet);
	void __fastcall SQLChanged(System::TObject* Sender);
	
public:
	__fastcall virtual TIBUpdateSQL(Classes::TComponent* AOwner);
	__fastcall virtual ~TIBUpdateSQL(void);
	virtual void __fastcall Apply(Db::TUpdateKind UpdateKind);
	void __fastcall ExecSQL(Db::TUpdateKind UpdateKind);
	void __fastcall SetParams(Db::TUpdateKind UpdateKind);
	__property DataSet ;
	__property Ibquery::TIBQuery* Query[Db::TUpdateKind UpdateKind] = {read=GetQuery};
	__property Classes::TStrings* SQL[Db::TUpdateKind UpdateKind] = {read=GetSQL, write=SetSQL};
	
__published:
	__property Classes::TStrings* ModifySQL = {read=GetSQLIndex, write=SetSQLIndex, index=0};
	__property Classes::TStrings* InsertSQL = {read=GetSQLIndex, write=SetSQLIndex, index=1};
	__property Classes::TStrings* DeleteSQL = {read=GetSQLIndex, write=SetSQLIndex, index=2};
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Ibupdatesql */
#if !defined(NO_IMPLICIT_NAMESPACE_USE)
using namespace Ibupdatesql;
#endif
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// IBUpdateSQL
