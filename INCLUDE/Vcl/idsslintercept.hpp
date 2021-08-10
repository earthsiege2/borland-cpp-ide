// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'IdSSLIntercept.pas' rev: 6.00

#ifndef IdSSLInterceptHPP
#define IdSSLInterceptHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <IdIntercept.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Idsslintercept
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TIdSSLConnectionIntercept;
class PASCALIMPLEMENTATION TIdSSLConnectionIntercept : public Idintercept::TIdConnectionIntercept 
{
	typedef Idintercept::TIdConnectionIntercept inherited;
	
public:
	__fastcall virtual TIdSSLConnectionIntercept(Classes::TComponent* AOwner);
public:
	#pragma option push -w-inl
	/* TComponent.Destroy */ inline __fastcall virtual ~TIdSSLConnectionIntercept(void) { }
	#pragma option pop
	
};


class DELPHICLASS TIdSSLServerIntercept;
class PASCALIMPLEMENTATION TIdSSLServerIntercept : public Idintercept::TIdServerIntercept 
{
	typedef Idintercept::TIdServerIntercept inherited;
	
public:
	#pragma option push -w-inl
	/* TComponent.Create */ inline __fastcall virtual TIdSSLServerIntercept(Classes::TComponent* AOwner) : Idintercept::TIdServerIntercept(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TComponent.Destroy */ inline __fastcall virtual ~TIdSSLServerIntercept(void) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Idsslintercept */
using namespace Idsslintercept;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// IdSSLIntercept
