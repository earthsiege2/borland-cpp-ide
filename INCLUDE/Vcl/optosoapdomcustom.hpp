// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'OPToSOAPDomCustom.pas' rev: 6.00

#ifndef OPToSOAPDomCustomHPP
#define OPToSOAPDomCustomHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <XMLIntf.hpp>	// Pascal unit
#include <XMLDoc.hpp>	// Pascal unit
#include <InvokeRegistry.hpp>	// Pascal unit
#include <IntfInfo.hpp>	// Pascal unit
#include <TypInfo.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Optosoapdomcustom
{
//-- type declarations -------------------------------------------------------
__interface ICustomConvert;
typedef System::DelphiInterface<ICustomConvert> _di_ICustomConvert;
__interface INTERFACE_UUID("{96832CB3-BC12-4C45-B482-26F7160EDE51}") ICustomConvert  : public IInterface 
{
	
public:
	virtual void __fastcall ConvertSoapParamToNative(Intfinfo::PIntfMethEntry MethMD, Invokeregistry::TInvContext* InvContext, int ArgCount, Xmlintf::_di_IXMLNode Node) = 0 ;
	virtual void __fastcall ConvertNativeParamToSoap(Xmlintf::_di_IXMLNode Node, AnsiString Name, Typinfo::PTypeInfo Info, void * P) = 0 ;
};

#pragma pack(push, 4)
struct TConverterEntry
{
	_di_ICustomConvert Converter;
	TMetaClass*AClass;
} ;
#pragma pack(pop)

typedef DynamicArray<TConverterEntry >  OPToSOAPDomCustom__2;

class DELPHICLASS TOPToSoapDomCustomRegistry;
class PASCALIMPLEMENTATION TOPToSoapDomCustomRegistry : public System::TObject 
{
	typedef System::TObject inherited;
	
private:
	DynamicArray<TConverterEntry >  FConverters;
	
public:
	void __fastcall RegisterCustomConverter(TMetaClass* AClass, AnsiString URI, AnsiString TypeName, _di_ICustomConvert Converter);
	_di_ICustomConvert __fastcall GetConverter(TMetaClass* AClass);
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall TOPToSoapDomCustomRegistry(void) : System::TObject() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TOPToSoapDomCustomRegistry(void) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------
extern PACKAGE TOPToSoapDomCustomRegistry* ConverterRegistry;

}	/* namespace Optosoapdomcustom */
using namespace Optosoapdomcustom;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// OPToSOAPDomCustom
