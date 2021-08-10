// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'CmAdmCtl.pas' rev: 6.00

#ifndef CmAdmCtlHPP
#define CmAdmCtlHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <COMAdmin.hpp>	// Pascal unit
#include <StdVCL.hpp>	// Pascal unit
#include <OleCtrls.hpp>	// Pascal unit
#include <OleServer.hpp>	// Pascal unit
#include <Graphics.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <ActiveX.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Cmadmctl
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS CoCOMAdminCatalog;
class PASCALIMPLEMENTATION CoCOMAdminCatalog : public System::TObject 
{
	typedef System::TObject inherited;
	
public:
	/*         class method */ static Comadmin::_di_ICOMAdminCatalog __fastcall Create(TMetaClass* vmt);
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall CoCOMAdminCatalog(void) : System::TObject() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~CoCOMAdminCatalog(void) { }
	#pragma option pop
	
};


class DELPHICLASS TCOMAdminCatalog;
class DELPHICLASS TCOMAdminCatalogCollection;
class PASCALIMPLEMENTATION TCOMAdminCatalog : public Oleserver::TOleServer 
{
	typedef Oleserver::TOleServer inherited;
	
private:
	Comadmin::_di_ICOMAdminCatalog FIntf;
	Comadmin::_di_ICOMAdminCatalog __fastcall GetDefaultInterface();
	
protected:
	virtual void __fastcall InitServerData(void);
	
public:
	__fastcall virtual TCOMAdminCatalog(Classes::TComponent* AOwner);
	__fastcall virtual ~TCOMAdminCatalog(void);
	virtual void __fastcall Connect(void);
	void __fastcall ConnectTo(Comadmin::_di_ICOMAdminCatalog svrIntf);
	virtual void __fastcall Disconnect(void);
	TCOMAdminCatalogCollection* __fastcall GetCollection(const WideString bstrCollName);
	TCOMAdminCatalogCollection* __fastcall ICOMAdminCatalog_Connect(const WideString bstrConnectString);
	int __fastcall Get_MajorVersion(void);
	int __fastcall Get_MinorVersion(void);
	TCOMAdminCatalogCollection* __fastcall GetCollectionByQuery(const WideString bstrCollName, Activex::PSafeArray &aQuery);
	void __fastcall ImportComponent(const WideString bstrApplIdOrName, const WideString bstrCLSIDOrProgId);
	void __fastcall InstallComponent(const WideString bstrApplIdOrName, const WideString bstrDLL, const WideString bstrTLB, const WideString bstrPSDLL);
	void __fastcall ShutdownApplication(const WideString bstrApplIdOrName);
	void __fastcall ExportApplication(const WideString bstrApplIdOrName, const WideString bstrApplicationFile, int lOptions);
	void __fastcall InstallApplication(const WideString bstrApplicationFile, const WideString bstrDestinationDirectory, int lOptions, const WideString bstrUserId, const WideString bstrPassword, const WideString bstrRSN);
	void __fastcall StopRouter(void);
	void __fastcall RefreshRouter(void);
	void __fastcall StartRouter(void);
	void __fastcall InstallMultipleComponents(const WideString bstrApplIdOrName, Activex::PSafeArray &varFileNames, Activex::PSafeArray &varCLSIDS);
	void __fastcall GetMultipleComponentsInfo(const WideString bstrApplIdOrName, Activex::PSafeArray &varFileNames, /* out */ Activex::PSafeArray &varCLSIDS, /* out */ Activex::PSafeArray &varClassNames, /* out */ Activex::PSafeArray &varFileFlags, /* out */ Activex::PSafeArray &varComponentFlags);
	void __fastcall RefreshComponents(void);
	void __fastcall BackupREGDB(const WideString bstrBackupFilePath);
	void __fastcall RestoreREGDB(const WideString bstrBackupFilePath);
	void __fastcall QueryApplicationFile(const WideString bstrApplicationFile, /* out */ WideString &bstrApplicationName, /* out */ WideString &bstrApplicationDescription, /* out */ Word &bHasUsers, /* out */ Word &bIsProxy, /* out */ Activex::PSafeArray &varFileNames);
	void __fastcall StartApplication(const WideString bstrApplIdOrName);
	int __fastcall ServiceCheck(int lService);
	void __fastcall InstallMultipleEventClasses(const WideString bstrApplIdOrName, Activex::PSafeArray &varFileNames, Activex::PSafeArray &varCLSIDS);
	void __fastcall InstallEventClass(const WideString bstrApplIdOrName, const WideString bstrDLL, const WideString bstrTLB, const WideString bstrPSDLL);
	void __fastcall GetEventClassesForIID(const WideString bstrIID, /* out */ Activex::PSafeArray &varCLSIDS, /* out */ Activex::PSafeArray &varProgIDs, /* out */ Activex::PSafeArray &varDescriptions);
	__property Comadmin::_di_ICOMAdminCatalog DefaultInterface = {read=GetDefaultInterface};
	__property int MajorVersion = {read=Get_MajorVersion, nodefault};
	__property int MinorVersion = {read=Get_MinorVersion, nodefault};
};


class DELPHICLASS CoCOMAdminCatalogObject;
class PASCALIMPLEMENTATION CoCOMAdminCatalogObject : public System::TObject 
{
	typedef System::TObject inherited;
	
public:
	/*         class method */ static Comadmin::_di_ICatalogObject __fastcall Create(TMetaClass* vmt);
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall CoCOMAdminCatalogObject(void) : System::TObject() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~CoCOMAdminCatalogObject(void) { }
	#pragma option pop
	
};


class DELPHICLASS TCOMAdminCatalogObject;
class PASCALIMPLEMENTATION TCOMAdminCatalogObject : public Oleserver::TOleServer 
{
	typedef Oleserver::TOleServer inherited;
	
private:
	Comadmin::_di_ICatalogObject FIntf;
	Comadmin::_di_ICatalogObject __fastcall GetDefaultInterface();
	
protected:
	virtual void __fastcall InitServerData(void);
	
public:
	__fastcall virtual TCOMAdminCatalogObject(Classes::TComponent* AOwner);
	__fastcall virtual ~TCOMAdminCatalogObject(void);
	virtual void __fastcall Connect(void);
	void __fastcall ConnectTo(Comadmin::_di_ICatalogObject svrIntf);
	virtual void __fastcall Disconnect(void);
	OleVariant __fastcall Get_Value(const WideString bstrPropName);
	void __fastcall Set_Value(const WideString bstrPropName, const OleVariant &retval);
	OleVariant __fastcall Get_Key();
	OleVariant __fastcall Get_Name();
	Word __fastcall IsPropertyReadOnly(const WideString bstrPropName);
	Word __fastcall Get_Valid(void);
	Word __fastcall IsPropertyWriteOnly(const WideString bstrPropName);
	__property OleVariant Value[WideString bstrPropName] = {read=Get_Value, write=Set_Value};
	__property Comadmin::_di_ICatalogObject DefaultInterface = {read=GetDefaultInterface};
	__property OleVariant Key = {read=Get_Key};
	__property OleVariant Name = {read=Get_Name};
	__property Word Valid = {read=Get_Valid, nodefault};
};


class DELPHICLASS CoCOMAdminCatalogCollection;
class PASCALIMPLEMENTATION CoCOMAdminCatalogCollection : public System::TObject 
{
	typedef System::TObject inherited;
	
public:
	/*         class method */ static Comadmin::_di_ICatalogCollection __fastcall Create(TMetaClass* vmt);
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall CoCOMAdminCatalogCollection(void) : System::TObject() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~CoCOMAdminCatalogCollection(void) { }
	#pragma option pop
	
};


class PASCALIMPLEMENTATION TCOMAdminCatalogCollection : public Oleserver::TOleServer 
{
	typedef Oleserver::TOleServer inherited;
	
private:
	Comadmin::_di_ICatalogCollection FIntf;
	Comadmin::_di_ICatalogCollection __fastcall GetDefaultInterface();
	
protected:
	virtual void __fastcall InitServerData(void);
	
public:
	__fastcall virtual TCOMAdminCatalogCollection(Classes::TComponent* AOwner);
	__fastcall virtual ~TCOMAdminCatalogCollection(void);
	virtual void __fastcall Connect(void);
	void __fastcall ConnectTo(Comadmin::_di_ICatalogCollection svrIntf);
	virtual void __fastcall Disconnect(void);
	TCOMAdminCatalogObject* __fastcall Get_Item(int lIndex);
	int __fastcall Get_Count(void);
	HIDESBASE void __fastcall Remove(int lIndex);
	TCOMAdminCatalogObject* __fastcall Add(void);
	void __fastcall Populate(void);
	int __fastcall SaveChanges(void);
	TCOMAdminCatalogCollection* __fastcall GetCollection(const WideString bstrCollName, const OleVariant &varObjectKey);
	OleVariant __fastcall Get_Name();
	Word __fastcall Get_AddEnabled(void);
	Word __fastcall Get_RemoveEnabled(void);
	_di_IDispatch __fastcall GetUtilInterface();
	int __fastcall Get_DataStoreMajorVersion(void);
	int __fastcall Get_DataStoreMinorVersion(void);
	void __fastcall PopulateByKey(Activex::PSafeArray aKeys);
	void __fastcall PopulateByQuery(const WideString bstrQueryString, int lQueryType);
	__property Comadmin::_di_ICatalogCollection DefaultInterface = {read=GetDefaultInterface};
	__property int Count = {read=Get_Count, nodefault};
	__property OleVariant Name = {read=Get_Name};
	__property Word AddEnabled = {read=Get_AddEnabled, nodefault};
	__property Word RemoveEnabled = {read=Get_RemoveEnabled, nodefault};
	__property int DataStoreMajorVersion = {read=Get_DataStoreMajorVersion, nodefault};
	__property int DataStoreMinorVersion = {read=Get_DataStoreMinorVersion, nodefault};
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Cmadmctl */
using namespace Cmadmctl;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// CmAdmCtl
