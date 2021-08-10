// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'COMAdmin.pas' rev: 6.00

#ifndef COMAdminHPP
#define COMAdminHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <ActiveX.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------
#include <comadmin.h>

namespace Comadmin
{
//-- type declarations -------------------------------------------------------
__interface ICOMAdminCatalog;
typedef System::DelphiInterface<ICOMAdminCatalog> _di_ICOMAdminCatalog;
typedef ICOMAdminCatalog COMAdminCatalog;
;

__interface ICatalogObject;
typedef System::DelphiInterface<ICatalogObject> _di_ICatalogObject;
typedef ICatalogObject COMAdminCatalogObject;
;

__interface ICatalogCollection;
typedef System::DelphiInterface<ICatalogCollection> _di_ICatalogCollection;
typedef ICatalogCollection COMAdminCatalogCollection;
;

typedef Activex::PSafeArray *PPSafeArray1;

__interface INTERFACE_UUID("{DD662187-DFC2-11D1-A2CF-00805FC79235}") ICOMAdminCatalog  : public IDispatch 
{
	
public:
	virtual HRESULT __safecall GetCollection(const WideString bstrCollName, _di_IDispatch &GetCollection_result) = 0 ;
	virtual HRESULT __safecall Connect(const WideString bstrConnectString, _di_IDispatch &Connect_result) = 0 ;
	virtual HRESULT __safecall Get_MajorVersion(int &Get_MajorVersion_result) = 0 ;
	virtual HRESULT __safecall Get_MinorVersion(int &Get_MinorVersion_result) = 0 ;
	virtual HRESULT __safecall GetCollectionByQuery(const WideString bstrCollName, Activex::PSafeArray &aQuery, _di_IDispatch &GetCollectionByQuery_result) = 0 ;
	virtual HRESULT __safecall ImportComponent(const WideString bstrApplIdOrName, const WideString bstrCLSIDOrProgId) = 0 ;
	virtual HRESULT __safecall InstallComponent(const WideString bstrApplIdOrName, const WideString bstrDLL, const WideString bstrTLB, const WideString bstrPSDLL) = 0 ;
	virtual HRESULT __safecall ShutdownApplication(const WideString bstrApplIdOrName) = 0 ;
	virtual HRESULT __safecall ExportApplication(const WideString bstrApplIdOrName, const WideString bstrApplicationFile, int lOptions) = 0 ;
	virtual HRESULT __safecall InstallApplication(const WideString bstrApplicationFile, const WideString bstrDestinationDirectory, int lOptions, const WideString bstrUserId, const WideString bstrPassword, const WideString bstrRSN) = 0 ;
	virtual HRESULT __safecall StopRouter(void) = 0 ;
	virtual HRESULT __safecall RefreshRouter(void) = 0 ;
	virtual HRESULT __safecall StartRouter(void) = 0 ;
	virtual HRESULT __safecall Reserved1(void) = 0 ;
	virtual HRESULT __safecall Reserved2(void) = 0 ;
	virtual HRESULT __safecall InstallMultipleComponents(const WideString bstrApplIdOrName, Activex::PSafeArray &varFileNames, Activex::PSafeArray &varCLSIDS) = 0 ;
	virtual HRESULT __safecall GetMultipleComponentsInfo(const WideString bstrApplIdOrName, Activex::PSafeArray &varFileNames, /* out */ Activex::PSafeArray &varCLSIDS, /* out */ Activex::PSafeArray &varClassNames, /* out */ Activex::PSafeArray &varFileFlags, /* out */ Activex::PSafeArray &varComponentFlags) = 0 ;
	virtual HRESULT __safecall RefreshComponents(void) = 0 ;
	virtual HRESULT __safecall BackupREGDB(const WideString bstrBackupFilePath) = 0 ;
	virtual HRESULT __safecall RestoreREGDB(const WideString bstrBackupFilePath) = 0 ;
	virtual HRESULT __safecall QueryApplicationFile(const WideString bstrApplicationFile, /* out */ WideString &bstrApplicationName, /* out */ WideString &bstrApplicationDescription, /* out */ Word &bHasUsers, /* out */ Word &bIsProxy, /* out */ Activex::PSafeArray &varFileNames) = 0 ;
	virtual HRESULT __safecall StartApplication(const WideString bstrApplIdOrName) = 0 ;
	virtual HRESULT __safecall ServiceCheck(int lService, int &ServiceCheck_result) = 0 ;
	virtual HRESULT __safecall InstallMultipleEventClasses(const WideString bstrApplIdOrName, Activex::PSafeArray &varFileNames, Activex::PSafeArray &varCLSIDS) = 0 ;
	virtual HRESULT __safecall InstallEventClass(const WideString bstrApplIdOrName, const WideString bstrDLL, const WideString bstrTLB, const WideString bstrPSDLL) = 0 ;
	virtual HRESULT __safecall GetEventClassesForIID(const WideString bstrIID, /* out */ Activex::PSafeArray &varCLSIDS, /* out */ Activex::PSafeArray &varProgIDs, /* out */ Activex::PSafeArray &varDescriptions) = 0 ;
	#pragma option push -w-inl
	/* safecall wrapper */ inline int _scw_Get_MajorVersion() { int r; HRESULT hr = Get_MajorVersion(r); System::CheckSafecallResult(hr); return r; }
	#pragma option pop
	__property int MajorVersion = {read=_scw_Get_MajorVersion};
	#pragma option push -w-inl
	/* safecall wrapper */ inline int _scw_Get_MinorVersion() { int r; HRESULT hr = Get_MinorVersion(r); System::CheckSafecallResult(hr); return r; }
	#pragma option pop
	__property int MinorVersion = {read=_scw_Get_MinorVersion};
};

__dispinterface ICOMAdminCatalogDisp;
typedef System::DelphiInterface<ICOMAdminCatalogDisp> _di_ICOMAdminCatalogDisp;
__dispinterface INTERFACE_UUID("{DD662187-DFC2-11D1-A2CF-00805FC79235}") ICOMAdminCatalogDisp  : public IDispatch 
{
	
};

__interface INTERFACE_UUID("{6EB22871-8A19-11D0-81B6-00A0C9231C29}") ICatalogObject  : public IDispatch 
{
	
public:
	virtual HRESULT __safecall Get_Value(const WideString bstrPropName, OleVariant &Get_Value_result) = 0 ;
	virtual HRESULT __safecall Set_Value(const WideString bstrPropName, const OleVariant retval) = 0 ;
	virtual HRESULT __safecall Get_Key(OleVariant &Get_Key_result) = 0 ;
	virtual HRESULT __safecall Get_Name(OleVariant &Get_Name_result) = 0 ;
	virtual HRESULT __safecall IsPropertyReadOnly(const WideString bstrPropName, Word &IsPropertyReadOnly_result) = 0 ;
	virtual HRESULT __safecall Get_Valid(Word &Get_Valid_result) = 0 ;
	virtual HRESULT __safecall IsPropertyWriteOnly(const WideString bstrPropName, Word &IsPropertyWriteOnly_result) = 0 ;
	#pragma option push -w-inl
	/* safecall wrapper */ inline OleVariant _scw_Get_Value(const WideString bstrPropName) { OleVariant r; HRESULT hr = Get_Value(bstrPropName, r); System::CheckSafecallResult(hr); return r; }
	#pragma option pop
	__property OleVariant Value[WideString bstrPropName] = {read=_scw_Get_Value, write=Set_Value};
	#pragma option push -w-inl
	/* safecall wrapper */ inline OleVariant _scw_Get_Key() { OleVariant r; HRESULT hr = Get_Key(r); System::CheckSafecallResult(hr); return r; }
	#pragma option pop
	__property OleVariant Key = {read=_scw_Get_Key};
	#pragma option push -w-inl
	/* safecall wrapper */ inline OleVariant _scw_Get_Name() { OleVariant r; HRESULT hr = Get_Name(r); System::CheckSafecallResult(hr); return r; }
	#pragma option pop
	__property OleVariant Name = {read=_scw_Get_Name};
	#pragma option push -w-inl
	/* safecall wrapper */ inline Word _scw_Get_Valid() { Word r; HRESULT hr = Get_Valid(r); System::CheckSafecallResult(hr); return r; }
	#pragma option pop
	__property Word Valid = {read=_scw_Get_Valid};
};

__dispinterface ICatalogObjectDisp;
typedef System::DelphiInterface<ICatalogObjectDisp> _di_ICatalogObjectDisp;
__dispinterface INTERFACE_UUID("{6EB22871-8A19-11D0-81B6-00A0C9231C29}") ICatalogObjectDisp  : public IDispatch 
{
	
};

__interface INTERFACE_UUID("{6EB22872-8A19-11D0-81B6-00A0C9231C29}") ICatalogCollection  : public IDispatch 
{
	
public:
	virtual HRESULT __safecall Get__NewEnum(System::_di_IInterface &Get__NewEnum_result) = 0 ;
	virtual HRESULT __safecall Get_Item(int lIndex, _di_IDispatch &Get_Item_result) = 0 ;
	virtual HRESULT __safecall Get_Count(int &Get_Count_result) = 0 ;
	virtual HRESULT __safecall Remove(int lIndex) = 0 ;
	virtual HRESULT __safecall Add(_di_IDispatch &Add_result) = 0 ;
	virtual HRESULT __safecall Populate(void) = 0 ;
	virtual HRESULT __safecall SaveChanges(int &SaveChanges_result) = 0 ;
	virtual HRESULT __safecall GetCollection(const WideString bstrCollName, const OleVariant varObjectKey, _di_IDispatch &GetCollection_result) = 0 ;
	virtual HRESULT __safecall Get_Name(OleVariant &Get_Name_result) = 0 ;
	virtual HRESULT __safecall Get_AddEnabled(Word &Get_AddEnabled_result) = 0 ;
	virtual HRESULT __safecall Get_RemoveEnabled(Word &Get_RemoveEnabled_result) = 0 ;
	virtual HRESULT __safecall GetUtilInterface(_di_IDispatch &GetUtilInterface_result) = 0 ;
	virtual HRESULT __safecall Get_DataStoreMajorVersion(int &Get_DataStoreMajorVersion_result) = 0 ;
	virtual HRESULT __safecall Get_DataStoreMinorVersion(int &Get_DataStoreMinorVersion_result) = 0 ;
	virtual HRESULT __safecall PopulateByKey(Activex::PSafeArray aKeys) = 0 ;
	virtual HRESULT __safecall PopulateByQuery(const WideString bstrQueryString, int lQueryType) = 0 ;
	#pragma option push -w-inl
	/* safecall wrapper */ inline System::_di_IInterface _scw_Get__NewEnum() { System::_di_IInterface r; HRESULT hr = Get__NewEnum(r); System::CheckSafecallResult(hr); return r; }
	#pragma option pop
	__property System::_di_IInterface _NewEnum = {read=_scw_Get__NewEnum};
	#pragma option push -w-inl
	/* safecall wrapper */ inline _di_IDispatch _scw_Get_Item(int lIndex) { _di_IDispatch r; HRESULT hr = Get_Item(lIndex, r); System::CheckSafecallResult(hr); return r; }
	#pragma option pop
	__property _di_IDispatch Item[int lIndex] = {read=_scw_Get_Item};
	#pragma option push -w-inl
	/* safecall wrapper */ inline int _scw_Get_Count() { int r; HRESULT hr = Get_Count(r); System::CheckSafecallResult(hr); return r; }
	#pragma option pop
	__property int Count = {read=_scw_Get_Count};
	#pragma option push -w-inl
	/* safecall wrapper */ inline OleVariant _scw_Get_Name() { OleVariant r; HRESULT hr = Get_Name(r); System::CheckSafecallResult(hr); return r; }
	#pragma option pop
	__property OleVariant Name = {read=_scw_Get_Name};
	#pragma option push -w-inl
	/* safecall wrapper */ inline Word _scw_Get_AddEnabled() { Word r; HRESULT hr = Get_AddEnabled(r); System::CheckSafecallResult(hr); return r; }
	#pragma option pop
	__property Word AddEnabled = {read=_scw_Get_AddEnabled};
	#pragma option push -w-inl
	/* safecall wrapper */ inline Word _scw_Get_RemoveEnabled() { Word r; HRESULT hr = Get_RemoveEnabled(r); System::CheckSafecallResult(hr); return r; }
	#pragma option pop
	__property Word RemoveEnabled = {read=_scw_Get_RemoveEnabled};
	#pragma option push -w-inl
	/* safecall wrapper */ inline int _scw_Get_DataStoreMajorVersion() { int r; HRESULT hr = Get_DataStoreMajorVersion(r); System::CheckSafecallResult(hr); return r; }
	#pragma option pop
	__property int DataStoreMajorVersion = {read=_scw_Get_DataStoreMajorVersion};
	#pragma option push -w-inl
	/* safecall wrapper */ inline int _scw_Get_DataStoreMinorVersion() { int r; HRESULT hr = Get_DataStoreMinorVersion(r); System::CheckSafecallResult(hr); return r; }
	#pragma option pop
	__property int DataStoreMinorVersion = {read=_scw_Get_DataStoreMinorVersion};
};

__dispinterface ICatalogCollectionDisp;
typedef System::DelphiInterface<ICatalogCollectionDisp> _di_ICatalogCollectionDisp;
__dispinterface INTERFACE_UUID("{6EB22872-8A19-11D0-81B6-00A0C9231C29}") ICatalogCollectionDisp  : public IDispatch 
{
	
};

//-- var, const, procedure ---------------------------------------------------
static const Shortint COMAdminMajorVersion = 0x1;
static const Shortint COMAdminMinorVersion = 0x0;
extern PACKAGE GUID CLASS_COMAdminCatalog;
extern PACKAGE GUID CLASS_COMAdminCatalogObject;
extern PACKAGE GUID CLASS_COMAdminCatalogCollection;

}	/* namespace Comadmin */
using namespace Comadmin;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// COMAdmin
