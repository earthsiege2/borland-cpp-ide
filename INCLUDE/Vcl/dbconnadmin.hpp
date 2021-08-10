// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'DBConnAdmin.pas' rev: 6.00

#ifndef DBConnAdminHPP
#define DBConnAdminHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <IniFiles.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <SysUtils.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Dbconnadmin
{
//-- type declarations -------------------------------------------------------
__interface IConnectionAdmin;
typedef System::DelphiInterface<IConnectionAdmin> _di_IConnectionAdmin;
__interface IConnectionAdmin  : public IInterface 
{
	
public:
	virtual int __fastcall GetDriverNames(Classes::TStrings* List) = 0 ;
	virtual int __fastcall GetDriverParams(const AnsiString DriverName, Classes::TStrings* Params) = 0 ;
	virtual void __fastcall GetDriverLibNames(const AnsiString DriverName, AnsiString &LibraryName, AnsiString &VendorLibrary) = 0 ;
	virtual int __fastcall GetConnectionNames(Classes::TStrings* List, AnsiString DriverName) = 0 ;
	virtual int __fastcall GetConnectionParams(const AnsiString ConnectionName, Classes::TStrings* Params) = 0 ;
	virtual void __fastcall GetConnectionParamValues(const AnsiString ParamName, Classes::TStrings* Values) = 0 ;
	virtual void __fastcall AddConnection(const AnsiString ConnectionName, const AnsiString DriverName) = 0 ;
	virtual void __fastcall DeleteConnection(const AnsiString ConnectionName) = 0 ;
	virtual void __fastcall ModifyConnection(const AnsiString ConnectionName, Classes::TStrings* Params) = 0 ;
	virtual void __fastcall RenameConnection(const AnsiString OldName, const AnsiString NewName) = 0 ;
	virtual void __fastcall ModifyDriverParams(const AnsiString DriverName, Classes::TStrings* Params) = 0 ;
};

class DELPHICLASS TConnectionAdmin;
class PASCALIMPLEMENTATION TConnectionAdmin : public System::TInterfacedObject 
{
	typedef System::TInterfacedObject inherited;
	
private:
	Inifiles::TIniFile* FDriverConfig;
	Inifiles::TIniFile* FConnectionConfig;
	
protected:
	int __fastcall GetDriverNames(Classes::TStrings* List);
	int __fastcall GetDriverParams(const AnsiString DriverName, Classes::TStrings* Params);
	void __fastcall GetDriverLibNames(const AnsiString DriverName, AnsiString &LibraryName, AnsiString &VendorLibrary);
	int __fastcall GetConnectionNames(Classes::TStrings* List, AnsiString DriverName);
	int __fastcall GetConnectionParams(const AnsiString ConnectionName, Classes::TStrings* Params);
	void __fastcall GetConnectionParamValues(const AnsiString ParamName, Classes::TStrings* Values);
	void __fastcall AddConnection(const AnsiString ConnectionName, const AnsiString DriverName);
	void __fastcall DeleteConnection(const AnsiString ConnectionName);
	void __fastcall ModifyConnection(const AnsiString ConnectionName, Classes::TStrings* Params);
	void __fastcall RenameConnection(const AnsiString OldName, const AnsiString NewName);
	void __fastcall ModifyDriverParams(const AnsiString DriverName, Classes::TStrings* Params);
	
public:
	__fastcall TConnectionAdmin(void);
	__fastcall virtual ~TConnectionAdmin(void);
	__property Inifiles::TIniFile* ConnectionConfig = {read=FConnectionConfig};
	__property Inifiles::TIniFile* DriverConfig = {read=FDriverConfig};
private:
	void *__IConnectionAdmin;	/* Dbconnadmin::IConnectionAdmin */
	
public:
	operator IConnectionAdmin*(void) { return (IConnectionAdmin*)&__IConnectionAdmin; }
	
};


//-- var, const, procedure ---------------------------------------------------
extern PACKAGE _di_IConnectionAdmin __fastcall GetConnectionAdmin();

}	/* namespace Dbconnadmin */
using namespace Dbconnadmin;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// DBConnAdmin
