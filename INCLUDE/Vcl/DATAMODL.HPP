// Borland C++ Builder
// Copyright (c) 1995, 1999 by Borland International
// All rights reserved

// (DO NOT EDIT: machine generated header) 'DataModl.pas' rev: 5.00

#ifndef DataModlHPP
#define DataModlHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <DBTables.hpp>	// Pascal unit
#include <Db.hpp>	// Pascal unit
#include <Dialogs.hpp>	// Pascal unit
#include <Forms.hpp>	// Pascal unit
#include <Controls.hpp>	// Pascal unit
#include <Graphics.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <SysUtils.hpp>	// Pascal unit
#include <Messages.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Datamodl
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TDataMod;
class PASCALIMPLEMENTATION TDataMod : public Forms::TDataModule 
{
	typedef Forms::TDataModule inherited;
	
__published:
	Dbtables::TTable* Table1;
	Dbtables::TQuery* Query1;
	Dbtables::TTable* Table2;
	Dbtables::TQuery* Query2;
	Db::TDataSource* DataSource1;
	Db::TDataSource* DataSource2;
	void __fastcall DataModuleCreate(System::TObject* Sender);
	
public:
	bool MultiQuery;
	bool CreateTable;
	Classes::TMemoryStream* __fastcall CreateRes(const AnsiString ModuleName);
	Classes::TMemoryStream* __fastcall CreateHdrSource(const AnsiString FilePath, const AnsiString FormName
		);
	Classes::TMemoryStream* __fastcall CreateCppSource(const AnsiString FilePath, const AnsiString FormName
		);
	Classes::TMemoryStream* __fastcall CreateSource(const AnsiString FilePath, const AnsiString FormName
		);
public:
	#pragma option push -w-inl
	/* TDataModule.Create */ inline __fastcall virtual TDataMod(Classes::TComponent* AOwner) : Forms::TDataModule(
		AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TDataModule.CreateNew */ inline __fastcall virtual TDataMod(Classes::TComponent* AOwner, int Dummy
		) : Forms::TDataModule(AOwner, Dummy) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TDataModule.Destroy */ inline __fastcall virtual ~TDataMod(void) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Datamodl */
#if !defined(NO_IMPLICIT_NAMESPACE_USE)
using namespace Datamodl;
#endif
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// DataModl
