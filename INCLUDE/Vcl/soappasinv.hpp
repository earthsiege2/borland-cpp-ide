// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'SOAPPasInv.pas' rev: 6.00

#ifndef SOAPPasInvHPP
#define SOAPPasInvHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <OPToSOAPDomConv.hpp>	// Pascal unit
#include <OPConvert.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <TypInfo.hpp>	// Pascal unit
#include <Invoker.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Soappasinv
{
//-- type declarations -------------------------------------------------------
typedef void __fastcall (__closure *TBeforeDispatchEvent)(const AnsiString MethodName, const Classes::TStream* Request);

typedef void __fastcall (__closure *TAfterDispatchEvent)(const AnsiString MethodName, Classes::TStream* SOAPResponse);

typedef void __fastcall (__closure *TOnExceptionEvent)(const AnsiString MethodName, const Classes::TStream* Request, const Classes::TStream* Response);

__interface IAdapterConverter;
typedef System::DelphiInterface<IAdapterConverter> _di_IAdapterConverter;
__interface INTERFACE_UUID("{82165DF4-B1B9-D511-9561-00C04FA06B45}") IAdapterConverter  : public IInterface 
{
	
public:
	virtual Optosoapdomconv::TOPToSoapDomConvert* __fastcall GetDomConverter(void) = 0 ;
};

class DELPHICLASS TSoapPascalInvoker;
class PASCALIMPLEMENTATION TSoapPascalInvoker : public Classes::TComponent 
{
	typedef Classes::TComponent inherited;
	
private:
	TBeforeDispatchEvent FBeforeDispatchEvent;
	TAfterDispatchEvent FAfterDispatchEvent;
	TOnExceptionEvent FOnExceptionEvent;
	void __fastcall SetDomConverter(Optosoapdomconv::TOPToSoapDomConvert* Value);
	
protected:
	Opconvert::_di_IOPConvert FConverter;
	Optosoapdomconv::TOPToSoapDomConvert* FDomConverter;
	Optosoapdomconv::TOPToSoapDomConvert* __fastcall GetDomConverter(void);
	virtual void __fastcall Notification(Classes::TComponent* AComponent, Classes::TOperation Operation);
	
public:
	__fastcall virtual TSoapPascalInvoker(Classes::TComponent* AOwner);
	__fastcall virtual ~TSoapPascalInvoker(void);
	HIDESBASE virtual void __fastcall Invoke(TMetaClass* AClass, Typinfo::PTypeInfo IntfInfo, AnsiString MethName, const Classes::TStream* Request, Classes::TStream* Response);
	
__published:
	__property TBeforeDispatchEvent BeforeDispatchEvent = {read=FBeforeDispatchEvent, write=FBeforeDispatchEvent};
	__property TAfterDispatchEvent AfterDispatchEvent = {read=FAfterDispatchEvent, write=FAfterDispatchEvent};
	__property TOnExceptionEvent OnExceptionEvent = {read=FOnExceptionEvent, write=FOnExceptionEvent};
	__property Optosoapdomconv::TOPToSoapDomConvert* Converter = {read=GetDomConverter, write=SetDomConverter};
private:
	void *__IAdapterConverter;	/* Soappasinv::IAdapterConverter */
	
public:
	operator IAdapterConverter*(void) { return (IAdapterConverter*)&__IAdapterConverter; }
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Soappasinv */
using namespace Soappasinv;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// SOAPPasInv
