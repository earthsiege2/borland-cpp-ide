// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'SOAPLinked.pas' rev: 6.00

#ifndef SOAPLinkedHPP
#define SOAPLinkedHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <IntfInfo.hpp>	// Pascal unit
#include <SOAPPasInv.hpp>	// Pascal unit
#include <WebNode.hpp>	// Pascal unit
#include <TypInfo.hpp>	// Pascal unit
#include <Rio.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Soaplinked
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TLinkedWebNode;
class PASCALIMPLEMENTATION TLinkedWebNode : public Classes::TComponent 
{
	typedef Classes::TComponent inherited;
	
private:
	Soappasinv::TSoapPascalInvoker* FInvoker;
	Typinfo::TTypeInfo *IntfInfo;
	TMetaClass*FClass;
	
public:
	__fastcall virtual TLinkedWebNode(Classes::TComponent* AOwner);
	__fastcall virtual ~TLinkedWebNode(void);
	void __fastcall BeforeExecute(const Intfinfo::TIntfMetaData &IntfMetaData, const Intfinfo::TIntfMethEntry &MethodMetaData);
	virtual void __fastcall Execute(const WideString DataMsg, Classes::TStream* Resp);
	__property Soappasinv::TSoapPascalInvoker* Invoker = {read=FInvoker};
private:
	void *__IWebNode;	/* Webnode::IWebNode */
	
public:
	operator IWebNode*(void) { return (IWebNode*)&__IWebNode; }
	
};


class DELPHICLASS TLogLinkedWebNode;
class PASCALIMPLEMENTATION TLogLinkedWebNode : public TLinkedWebNode 
{
	typedef TLinkedWebNode inherited;
	
private:
	AnsiString FReqFile;
	AnsiString FRespFile;
	
public:
	__fastcall virtual TLogLinkedWebNode(Classes::TComponent* AOwner);
	__fastcall virtual ~TLogLinkedWebNode(void);
	virtual void __fastcall Execute(const WideString DataMsg, Classes::TStream* Resp);
	
__published:
	__property AnsiString ReqFile = {read=FReqFile, write=FReqFile};
	__property AnsiString RespFile = {read=FRespFile, write=FRespFile};
};


class DELPHICLASS TLinkedRIO;
class PASCALIMPLEMENTATION TLinkedRIO : public Rio::TRIO 
{
	typedef Rio::TRIO inherited;
	
private:
	TLinkedWebNode* FLinkedWebNode;
	
public:
	virtual HRESULT __stdcall QueryInterface(const GUID &IID, /* out */ void *Obj);
	/**
	 * Template function to ease querying for a
	 * smart-Interface-object
	 */
	template <typename T>
	HRESULT __stdcall QueryInterface(DelphiInterface<T>& smartIntf)
	{
	  return QueryInterface(__uuidof(T), reinterpret_cast<void*>(static_cast<T**>(&smartIntf)));
	}
	__fastcall virtual TLinkedRIO(Classes::TComponent* AOwner)/* overload */;
	__fastcall TLinkedRIO(Classes::TComponent* AOwner, AnsiString ReqFile, AnsiString RespFile)/* overload */;
	__fastcall virtual ~TLinkedRIO(void);
	__property TLinkedWebNode* WebNode = {read=FLinkedWebNode};
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Soaplinked */
using namespace Soaplinked;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// SOAPLinked
