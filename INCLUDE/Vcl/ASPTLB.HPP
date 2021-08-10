// Borland C++ Builder
// Copyright (c) 1995, 1999 by Borland International
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Asptlb.pas' rev: 5.00

#ifndef AsptlbHPP
#define AsptlbHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <Mtx.hpp>	// Pascal unit
#include <ComObj.hpp>	// Pascal unit
#include <ActiveX.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Asptlb
{
//-- type declarations -------------------------------------------------------
__interface IASPObject;
typedef System::DelphiInterface<IASPObject> _di_IASPObject;
__interface INTERFACE_UUID("{7A8B9910-F33C-11D2-9EDD-00C04F6539EE}") IASPObject  : public IUnknown 
{
	
public:
	virtual HRESULT __safecall OnStartPage(_di_IUnknown AScriptingContext) = 0 ;
	virtual HRESULT __safecall OnEndPage(void) = 0 ;
};

class DELPHICLASS TASPObject;
class PASCALIMPLEMENTATION TASPObject : public TAutoObject 
{
	typedef TAutoObject inherited;
	
private:
	_di_IScriptingContext FScriptingContext;
	_di_IApplicationObject __fastcall GetApplication();
	_di_IRequest __fastcall GetRequest();
	_di_IResponse __fastcall GetResponse();
	_di_IScriptingContext __fastcall GetScriptingContext();
	_di_IServer __fastcall GetServer();
	_di_ISessionObject __fastcall GetSession();
	
public:
	HRESULT __safecall OnStartPage(_di_IUnknown AScriptingContext);
	HRESULT __safecall OnEndPage(void);
	__property _di_IScriptingContext ScriptingContext = {read=GetScriptingContext};
	__property _di_IRequest Request = {read=GetRequest};
	__property _di_IResponse Response = {read=GetResponse};
	__property _di_ISessionObject Session = {read=GetSession};
	__property _di_IServer Server = {read=GetServer};
	__property _di_IApplicationObject Application = {read=GetApplication};
public:
	#pragma option push -w-inl
	/* TComObject.Create */ inline __fastcall TASPObject(void) : TAutoObject() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TComObject.CreateAggregated */ inline __fastcall TASPObject(const _di_IUnknown Controller) : TAutoObject(
		Controller) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TComObject.CreateFromFactory */ inline __fastcall TASPObject(TComObjectFactory* Factory, const _di_IUnknown 
		Controller) : TAutoObject(Factory, Controller) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TComObject.Destroy */ inline __fastcall virtual ~TASPObject(void) { }
	#pragma option pop
	
private:
	void *__IASPObject;	/* Asptlb::IASPObject */
	
public:
	operator IASPObject*(void) { return (IASPObject*)&__IASPObject; }
	
};


class DELPHICLASS TASPMTSObject;
class PASCALIMPLEMENTATION TASPMTSObject : public TAutoObject 
{
	typedef TAutoObject inherited;
	
private:
	_di_IApplicationObject __fastcall GetApplication();
	_di_IRequest __fastcall GetRequest();
	_di_IResponse __fastcall GetResponse();
	_di_IServer __fastcall GetServer();
	_di_ISessionObject __fastcall GetSession();
	
public:
	__property _di_IRequest Request = {read=GetRequest};
	__property _di_IResponse Response = {read=GetResponse};
	__property _di_ISessionObject Session = {read=GetSession};
	__property _di_IServer Server = {read=GetServer};
	__property _di_IApplicationObject Application = {read=GetApplication};
public:
	#pragma option push -w-inl
	/* TComObject.Create */ inline __fastcall TASPMTSObject(void) : TAutoObject() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TComObject.CreateAggregated */ inline __fastcall TASPMTSObject(const _di_IUnknown Controller) : 
		TAutoObject(Controller) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TComObject.CreateFromFactory */ inline __fastcall TASPMTSObject(TComObjectFactory* Factory, const 
		_di_IUnknown Controller) : TAutoObject(Factory, Controller) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TComObject.Destroy */ inline __fastcall virtual ~TASPMTSObject(void) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Asptlb */
#if !defined(NO_IMPLICIT_NAMESPACE_USE)
using namespace Asptlb;
#endif
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// Asptlb
