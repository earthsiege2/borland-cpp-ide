// Borland C++ Builder
// Copyright (c) 1995, 1999 by Borland International
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Midas.pas' rev: 5.00

#ifndef MidasHPP
#define MidasHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <ActiveX.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Midas
{
//-- type declarations -------------------------------------------------------
__interface IAppServer;
typedef System::DelphiInterface<IAppServer> _di_IAppServer;
__interface INTERFACE_UUID("{1AEFCC20-7A24-11D2-98B0-C69BEB4B5B6D}") IAppServer  : public IDispatch 
	
{
	
public:
	virtual HRESULT __safecall AS_ApplyUpdates(const WideString ProviderName, const OleVariant Delta, int 
		MaxErrors, /* out */ int &ErrorCount, OleVariant &OwnerData, OleVariant &AS_ApplyUpdates_result) = 0 
		;
	virtual HRESULT __safecall AS_GetRecords(const WideString ProviderName, int Count, /* out */ int &RecsOut
		, int Options, const WideString CommandText, OleVariant &Params, OleVariant &OwnerData, OleVariant &AS_GetRecords_result
		) = 0 ;
	virtual HRESULT __safecall AS_DataRequest(const WideString ProviderName, const OleVariant Data, OleVariant &AS_DataRequest_result
		) = 0 ;
	virtual HRESULT __safecall AS_GetProviderNames(OleVariant &AS_GetProviderNames_result) = 0 ;
	virtual HRESULT __safecall AS_GetParams(const WideString ProviderName, OleVariant &OwnerData, OleVariant &AS_GetParams_result
		) = 0 ;
	virtual HRESULT __safecall AS_RowRequest(const WideString ProviderName, const OleVariant Row, int RequestType
		, OleVariant &OwnerData, OleVariant &AS_RowRequest_result) = 0 ;
	virtual HRESULT __safecall AS_Execute(const WideString ProviderName, const WideString CommandText, 
		OleVariant &Params, OleVariant &OwnerData) = 0 ;
};

__dispinterface IAppServerDisp;
typedef System::DelphiInterface<IAppServerDisp> _di_IAppServerDisp;
__dispinterface INTERFACE_UUID("{1AEFCC20-7A24-11D2-98B0-C69BEB4B5B6D}") IAppServerDisp  : public IDispatch 
	
{
	
};

//-- var, const, procedure ---------------------------------------------------
extern PACKAGE GUID LIBID_Midas;
extern PACKAGE GUID IID_IAppServer;

}	/* namespace Midas */
#if !defined(NO_IMPLICIT_NAMESPACE_USE)
using namespace Midas;
#endif
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// Midas
