// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'HTTPIntr.pas' rev: 6.00

#ifndef HTTPIntrHPP
#define HTTPIntrHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <SConnect.hpp>	// Pascal unit
#include <HTTPApp.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <SysUtils.hpp>	// Pascal unit
#include <Variants.hpp>	// Pascal unit
#include <Messages.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Httpintr
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS THTTPServer;
class PASCALIMPLEMENTATION THTTPServer : public Httpapp::TWebModule 
{
	typedef Httpapp::TWebModule inherited;
	
__published:
	void __fastcall InterpreterAction(System::TObject* Sender, Httpapp::TWebRequest* Request, Httpapp::TWebResponse* Response, bool &Handled);
	
private:
	Sconnect::TDataBlockInterpreter* FInterpreter;
	Sconnect::_di_IDataBlock FData;
	
protected:
	Sconnect::_di_IDataBlock __stdcall Send(const Sconnect::_di_IDataBlock Data, bool WaitForResult);
public:
	#pragma option push -w-inl
	/* TWebModule.Create */ inline __fastcall virtual THTTPServer(Classes::TComponent* AOwner) : Httpapp::TWebModule(AOwner) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TCustomWebDispatcher.Destroy */ inline __fastcall virtual ~THTTPServer(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TDataModule.CreateNew */ inline __fastcall virtual THTTPServer(Classes::TComponent* AOwner, int Dummy) : Httpapp::TWebModule(AOwner, Dummy) { }
	#pragma option pop
	
private:
	void *__ISendDataBlock;	/* Sconnect::ISendDataBlock */
	
public:
	operator ISendDataBlock*(void) { return (ISendDataBlock*)&__ISendDataBlock; }
	
};


//-- var, const, procedure ---------------------------------------------------
extern PACKAGE THTTPServer* HTTPServer;
extern PACKAGE BOOL __stdcall TerminateExtension(unsigned dwFlags);

}	/* namespace Httpintr */
using namespace Httpintr;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// HTTPIntr
