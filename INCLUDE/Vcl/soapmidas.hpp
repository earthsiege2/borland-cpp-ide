// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'SOAPMidas.pas' rev: 6.00

#ifndef SOAPMidasHPP
#define SOAPMidasHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <Types.hpp>	// Pascal unit
#include <InvokeRegistry.hpp>	// Pascal unit
#include <Midas.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Soapmidas
{
//-- type declarations -------------------------------------------------------
__interface IAppServerSOAP;
typedef System::DelphiInterface<IAppServerSOAP> _di_IAppServerSOAP;
__interface INTERFACE_UUID("{C99F4735-D6D2-495C-8CA2-E53E5A439E61}") IAppServerSOAP  : public IInvokable 
{
	
public:
	virtual OleVariant __stdcall SAS_ApplyUpdates(const WideString ProviderName, const OleVariant Delta, int MaxErrors, /* out */ int &ErrorCount, OleVariant &OwnerData) = 0 ;
	virtual OleVariant __stdcall SAS_GetRecords(const WideString ProviderName, int Count, /* out */ int &RecsOut, int Options, const WideString CommandText, OleVariant &Params, OleVariant &OwnerData) = 0 ;
	virtual OleVariant __stdcall SAS_DataRequest(const WideString ProviderName, const OleVariant Data) = 0 ;
	virtual TWideStringDynArray __stdcall SAS_GetProviderNames(void) = 0 ;
	virtual OleVariant __stdcall SAS_GetParams(const WideString ProviderName, OleVariant &OwnerData) = 0 ;
	virtual OleVariant __stdcall SAS_RowRequest(const WideString ProviderName, const OleVariant Row, int RequestType, OleVariant &OwnerData) = 0 ;
	virtual void __stdcall SAS_Execute(const WideString ProviderName, const WideString CommandText, OleVariant &Params, OleVariant &OwnerData) = 0 ;
};

//-- var, const, procedure ---------------------------------------------------
extern PACKAGE void __fastcall RegDefIAppServerInvClass(void);

}	/* namespace Soapmidas */
using namespace Soapmidas;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// SOAPMidas
