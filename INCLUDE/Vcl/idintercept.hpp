// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'IdIntercept.pas' rev: 6.00

#ifndef IdInterceptHPP
#define IdInterceptHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <IdSocketHandle.hpp>	// Pascal unit
#include <IdBaseComponent.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Idintercept
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TIdConnectionIntercept;
class PASCALIMPLEMENTATION TIdConnectionIntercept : public Idbasecomponent::TIdBaseComponent 
{
	typedef Idbasecomponent::TIdBaseComponent inherited;
	
protected:
	Idsockethandle::TIdSocketHandle* FBinding;
	Classes::TNotifyEvent FOnConnect;
	bool FRecvHandling;
	bool FSendHandling;
	bool FIsClient;
	
public:
	virtual void __fastcall Connect(Idsockethandle::TIdSocketHandle* ABinding);
	virtual void __fastcall DataReceived(void *ABuffer, const int AByteCount);
	virtual void __fastcall DataSent(void *ABuffer, const int AByteCount);
	virtual void __fastcall Disconnect(void);
	virtual int __fastcall Recv(void *ABuf, int ALen);
	virtual int __fastcall Send(void *ABuf, int ALen);
	__property Idsockethandle::TIdSocketHandle* Binding = {read=FBinding};
	__property bool IsClient = {read=FIsClient, nodefault};
	__property bool RecvHandling = {read=FRecvHandling, nodefault};
	__property bool SendHandling = {read=FSendHandling, nodefault};
	
__published:
	__property Classes::TNotifyEvent OnConnect = {read=FOnConnect, write=FOnConnect};
public:
	#pragma option push -w-inl
	/* TComponent.Create */ inline __fastcall virtual TIdConnectionIntercept(Classes::TComponent* AOwner) : Idbasecomponent::TIdBaseComponent(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TComponent.Destroy */ inline __fastcall virtual ~TIdConnectionIntercept(void) { }
	#pragma option pop
	
};


class DELPHICLASS TIdServerIntercept;
class PASCALIMPLEMENTATION TIdServerIntercept : public Idbasecomponent::TIdBaseComponent 
{
	typedef Idbasecomponent::TIdBaseComponent inherited;
	
public:
	virtual void __fastcall Init(void) = 0 ;
	virtual TIdConnectionIntercept* __fastcall Accept(Idsockethandle::TIdSocketHandle* ABinding) = 0 ;
public:
	#pragma option push -w-inl
	/* TComponent.Create */ inline __fastcall virtual TIdServerIntercept(Classes::TComponent* AOwner) : Idbasecomponent::TIdBaseComponent(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TComponent.Destroy */ inline __fastcall virtual ~TIdServerIntercept(void) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Idintercept */
using namespace Idintercept;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// IdIntercept
