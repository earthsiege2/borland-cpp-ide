// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'SOAPDomConv.pas' rev: 6.00

#ifndef SOAPDomConvHPP
#define SOAPDomConvHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <XMLDoc.hpp>	// Pascal unit
#include <XMLIntf.hpp>	// Pascal unit
#include <xmldom.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Soapdomconv
{
//-- type declarations -------------------------------------------------------
__interface IDOMHeaderProcessor;
typedef System::DelphiInterface<IDOMHeaderProcessor> _di_IDOMHeaderProcessor;
__interface INTERFACE_UUID("{27F23F8F-23A2-4257-95A8-0204EEFF937B}") IDOMHeaderProcessor  : public IInterface 
{
	
public:
	virtual void __fastcall ProcessHeader(Xmlintf::_di_IXMLNode HeaderNode, bool &Handled, bool &AbortRequest) = 0 ;
	virtual Xmlintf::_di_IXMLNode __fastcall CreateHeader(Xmlintf::_di_IXMLNode HeaderNode) = 0 ;
};

#pragma pack(push, 4)
struct TDOMHeaderProcessorEntry
{
	_di_IDOMHeaderProcessor Processor;
	WideString NameSpace;
	WideString HeaderName;
	WideString TypeName;
} ;
#pragma pack(pop)

typedef DynamicArray<TDOMHeaderProcessorEntry >  TDOMHeaderProcessorArray;

class DELPHICLASS TSOAPDOMProcessor;
class PASCALIMPLEMENTATION TSOAPDOMProcessor : public Classes::TComponent 
{
	typedef Classes::TComponent inherited;
	
private:
	int FRefCount;
	bool FOwnerIsComponent;
	
protected:
	DynamicArray<TDOMHeaderProcessorEntry >  FHeaderProcessors;
	virtual _di_IDOMHeaderProcessor __fastcall FindHeaderProcessor(WideString Namespace, WideString HeaderName, WideString TypeName);
	Xmlintf::_di_IXMLNode __fastcall MakeHeaderNodes(Xmlintf::_di_IXMLNode HeaderNode);
	HIDESBASE int __stdcall _AddRef(void);
	HIDESBASE int __stdcall _Release(void);
	
public:
	virtual void __fastcall AddHeaderProcessor(WideString Namespace, WideString HeaderName, WideString TypeName, _di_IDOMHeaderProcessor Processor);
	virtual void __fastcall DefaultProcessHeader(Xmlintf::_di_IXMLNode HeaderNode, bool &Handled, bool &AbortRequest);
	/* virtual class method */ virtual System::TObject* __fastcall NewInstance(TMetaClass* vmt);
	virtual void __fastcall AfterConstruction(void);
	__fastcall virtual ~TSOAPDOMProcessor(void);
public:
	#pragma option push -w-inl
	/* TComponent.Create */ inline __fastcall virtual TSOAPDOMProcessor(Classes::TComponent* AOwner) : Classes::TComponent(AOwner) { }
	#pragma option pop
	
private:
	void *__IInterface;	/* System::IInterface */
	
public:
	operator IInterface*(void) { return (IInterface*)&__IInterface; }
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Soapdomconv */
using namespace Soapdomconv;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// SOAPDomConv
