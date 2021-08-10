// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Invoker.pas' rev: 6.00

#ifndef InvokerHPP
#define InvokerHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <InvokeRegistry.hpp>	// Pascal unit
#include <IntfInfo.hpp>	// Pascal unit
#include <TypInfo.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <SysUtils.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Invoker
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TInterfaceInvoker;
class PASCALIMPLEMENTATION TInterfaceInvoker : public System::TObject 
{
	typedef System::TObject inherited;
	
public:
	void __fastcall Invoke(const System::TObject* Obj, const Intfinfo::TIntfMetaData &IntfMD, const int MethNum, const Invokeregistry::TInvContext* Context);
	__fastcall TInterfaceInvoker(void);
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TInterfaceInvoker(void) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Invoker */
using namespace Invoker;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// Invoker
