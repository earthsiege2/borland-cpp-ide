// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'SOAPHTTPDisp.pas' rev: 6.00

#ifndef SOAPHTTPDispHPP
#define SOAPHTTPDispHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <Classes.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Soaphttpdisp
{
//-- type declarations -------------------------------------------------------
__interface IHTTPSoapDispatch;
typedef System::DelphiInterface<IHTTPSoapDispatch> _di_IHTTPSoapDispatch;
__interface INTERFACE_UUID("{9E733EDC-7639-4DAF-96FF-BCF141F7D8F2}") IHTTPSoapDispatch  : public IInterface 
{
	
public:
	virtual void __fastcall DispatchSOAP(const WideString Path, const WideString SoapAction, const Classes::TStream* Request, Classes::TStream* Response) = 0 ;
};

class DELPHICLASS THTTPSoapDispatchNode;
class PASCALIMPLEMENTATION THTTPSoapDispatchNode : public Classes::TComponent 
{
	typedef Classes::TComponent inherited;
	
private:
	void __fastcall SetSoapDispatcher(const _di_IHTTPSoapDispatch Value);
	
protected:
	_di_IHTTPSoapDispatch FSoapDispatcher;
	virtual void __fastcall Notification(Classes::TComponent* AComponent, Classes::TOperation Operation);
	
public:
	virtual void __fastcall DispatchSOAP(const WideString Path, const WideString SoapAction, const Classes::TStream* Request, Classes::TStream* Response);
	
__published:
	__property _di_IHTTPSoapDispatch Dispatcher = {read=FSoapDispatcher, write=SetSoapDispatcher};
public:
	#pragma option push -w-inl
	/* TComponent.Create */ inline __fastcall virtual THTTPSoapDispatchNode(Classes::TComponent* AOwner) : Classes::TComponent(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TComponent.Destroy */ inline __fastcall virtual ~THTTPSoapDispatchNode(void) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Soaphttpdisp */
using namespace Soaphttpdisp;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// SOAPHTTPDisp
