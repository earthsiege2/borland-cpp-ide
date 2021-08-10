// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'SOAPDm.pas' rev: 6.00

#ifndef SOAPDmHPP
#define SOAPDmHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <Types.hpp>	// Pascal unit
#include <SOAPMidas.hpp>	// Pascal unit
#include <HTTPApp.hpp>	// Pascal unit
#include <SysUtils.hpp>	// Pascal unit
#include <Provider.hpp>	// Pascal unit
#include <Midas.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <Variants.hpp>	// Pascal unit
#include <ComObj.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

/* Automatically link to SOAPMidas where IAppServer is registered */
#pragma link "SOAPMidas.obj"


namespace Soapdm
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TSoapDataModule;
class PASCALIMPLEMENTATION TSoapDataModule : public Classes::TDataModule 
{
	typedef Classes::TDataModule inherited;
	
private:
	Classes::TList* FProviders;
	_RTL_CRITICAL_SECTION FLock;
	int FRefCount;
	int __fastcall GetProviderCount(void);
	
protected:
	virtual Provider::TCustomProvider* __fastcall GetProvider(const AnsiString ProviderName);
	OleVariant __fastcall GetProviderNames();
	OleVariant __fastcall ApplyUpdates(const WideString ProviderName, const OleVariant &Delta, int MaxErrors, /* out */ int &ErrorCount, OleVariant &OwnerData);
	OleVariant __fastcall GetRecords(const WideString ProviderName, int Count, /* out */ int &RecsOut, int Options, const WideString CommandText, OleVariant &Params, OleVariant &OwnerData);
	OleVariant __fastcall DataRequest(const WideString ProviderName, const OleVariant &Data);
	OleVariant __fastcall GetParams(const WideString ProviderName, OleVariant &OwnerData);
	OleVariant __fastcall RowRequest(const WideString ProviderName, const OleVariant &Row, int RequestType, OleVariant &OwnerData);
	void __fastcall Execute(const WideString ProviderName, const WideString CommandText, OleVariant &Params, OleVariant &OwnerData);
	HRESULT __safecall AS_GetProviderNames(OleVariant &AS_GetProviderNames_result);
	HRESULT __safecall AS_ApplyUpdates(const WideString ProviderName, const OleVariant Delta, int MaxErrors, /* out */ int &ErrorCount, OleVariant &OwnerData, OleVariant &AS_ApplyUpdates_result);
	HRESULT __safecall AS_GetRecords(const WideString ProviderName, int Count, /* out */ int &RecsOut, int Options, const WideString CommandText, OleVariant &Params, OleVariant &OwnerData, OleVariant &AS_GetRecords_result);
	HRESULT __safecall AS_DataRequest(const WideString ProviderName, const OleVariant Data, OleVariant &AS_DataRequest_result);
	HRESULT __safecall AS_GetParams(const WideString ProviderName, OleVariant &OwnerData, OleVariant &AS_GetParams_result);
	HRESULT __safecall AS_RowRequest(const WideString ProviderName, const OleVariant Row, int RequestType, OleVariant &OwnerData, OleVariant &AS_RowRequest_result);
	HRESULT __safecall AS_Execute(const WideString ProviderName, const WideString CommandText, OleVariant &Params, OleVariant &OwnerData);
	virtual OleVariant __stdcall SAS_ApplyUpdates(const WideString ProviderName, const OleVariant Delta, int MaxErrors, /* out */ int &ErrorCount, OleVariant &OwnerData);
	virtual OleVariant __stdcall SAS_GetRecords(const WideString ProviderName, int Count, /* out */ int &RecsOut, int Options, const WideString CommandText, OleVariant &Params, OleVariant &OwnerData);
	virtual OleVariant __stdcall SAS_DataRequest(const WideString ProviderName, const OleVariant Data);
	virtual TWideStringDynArray __stdcall SAS_GetProviderNames();
	virtual OleVariant __stdcall SAS_GetParams(const WideString ProviderName, OleVariant &OwnerData);
	virtual OleVariant __stdcall SAS_RowRequest(const WideString ProviderName, const OleVariant Row, int RequestType, OleVariant &OwnerData);
	virtual void __stdcall SAS_Execute(const WideString ProviderName, const WideString CommandText, OleVariant &Params, OleVariant &OwnerData);
	
public:
	__fastcall virtual TSoapDataModule(Classes::TComponent* AOwner);
	__fastcall virtual ~TSoapDataModule(void);
	virtual void __fastcall AfterConstruction(void);
	virtual void __fastcall BeforeDestruction(void);
	/* virtual class method */ virtual System::TObject* __fastcall NewInstance(TMetaClass* vmt);
	HIDESBASE int __stdcall _AddRef(void);
	HIDESBASE int __stdcall _Release(void);
	virtual void __fastcall Lock(void);
	virtual void __fastcall Unlock(void);
	void __fastcall RegisterProvider(Provider::TCustomProvider* Value);
	void __fastcall UnRegisterProvider(Provider::TCustomProvider* Value);
	__property Provider::TCustomProvider* Providers[AnsiString ProviderName] = {read=GetProvider};
	__property int ProviderCount = {read=GetProviderCount, nodefault};
	__property int RefCount = {read=FRefCount, nodefault};
	virtual HRESULT __fastcall SafeCallException(System::TObject* ExceptObject, void * ExceptAddr);
public:
	#pragma option push -w-inl
	/* TDataModule.CreateNew */ inline __fastcall virtual TSoapDataModule(Classes::TComponent* AOwner, int Dummy) : Classes::TDataModule(AOwner, Dummy) { }
	#pragma option pop
	
private:
	void *__IAppServer;	/* Midas::IAppServer */
	void *__IAppServerSOAP;	/* Soapmidas::IAppServerSOAP */
	void *__IProviderContainer;	/* Provider::IProviderContainer */
	
public:
	operator IProviderContainer*(void) { return (IProviderContainer*)&__IProviderContainer; }
	operator IAppServerSOAP*(void) { return (IAppServerSOAP*)&__IAppServerSOAP; }
	operator IAppServer*(void) { return (IAppServer*)&__IAppServer; }
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Soapdm */
using namespace Soapdm;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// SOAPDm
