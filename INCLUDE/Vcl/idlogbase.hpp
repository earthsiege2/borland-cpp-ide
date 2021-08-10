// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'IdLogBase.pas' rev: 6.00

#ifndef IdLogBaseHPP
#define IdLogBaseHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <IdSocketHandle.hpp>	// Pascal unit
#include <IdIntercept.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Idlogbase
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TIdLogBase;
class PASCALIMPLEMENTATION TIdLogBase : public Idintercept::TIdConnectionIntercept 
{
	typedef Idintercept::TIdConnectionIntercept inherited;
	
protected:
	bool FActive;
	bool FLogTime;
	virtual void __fastcall Log(AnsiString AText) = 0 ;
	virtual void __fastcall SetActive(const bool AValue);
	
public:
	virtual void __fastcall Connect(Idsockethandle::TIdSocketHandle* ABinding);
	__fastcall virtual TIdLogBase(Classes::TComponent* AOwner);
	virtual void __fastcall DataReceived(void *ABuffer, const int AByteCount);
	virtual void __fastcall DataSent(void *ABuffer, const int AByteCount);
	virtual void __fastcall Disconnect(void);
	virtual void __fastcall DoLog(AnsiString AText);
	
__published:
	__property bool Active = {read=FActive, write=SetActive, default=0};
	__property bool LogTime = {read=FLogTime, write=FLogTime, default=1};
public:
	#pragma option push -w-inl
	/* TComponent.Destroy */ inline __fastcall virtual ~TIdLogBase(void) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------
static const bool ID_LOGBASE_Active = false;
static const bool ID_LOGBASE_LogTime = true;

}	/* namespace Idlogbase */
using namespace Idlogbase;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// IdLogBase
