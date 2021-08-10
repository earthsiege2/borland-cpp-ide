// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'IdAntiFreeze.pas' rev: 6.00

#ifndef IdAntiFreezeHPP
#define IdAntiFreezeHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <IdBaseComponent.hpp>	// Pascal unit
#include <IdAntiFreezeBase.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Idantifreeze
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TIdAntiFreeze;
class PASCALIMPLEMENTATION TIdAntiFreeze : public Idantifreezebase::TIdAntiFreezeBase 
{
	typedef Idantifreezebase::TIdAntiFreezeBase inherited;
	
public:
	virtual void __fastcall Process(void);
public:
	#pragma option push -w-inl
	/* TIdAntiFreezeBase.Create */ inline __fastcall virtual TIdAntiFreeze(Classes::TComponent* AOwner) : Idantifreezebase::TIdAntiFreezeBase(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TIdAntiFreezeBase.Destroy */ inline __fastcall virtual ~TIdAntiFreeze(void) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Idantifreeze */
using namespace Idantifreeze;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// IdAntiFreeze
