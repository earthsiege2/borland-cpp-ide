// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'WSDLIntf.pas' rev: 6.00

#ifndef WSDLIntfHPP
#define WSDLIntfHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <XMLDoc.hpp>	// Pascal unit
#include <XMLIntf.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <SysUtils.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Wsdlintf
{
//-- type declarations -------------------------------------------------------
#pragma option push -b-
enum TBindingType { btUnknown, btSoap, btHttp, btMime };
#pragma option pop

#pragma option push -b-
enum TWSDLElement { weServiceIntf, weServiceImpl, weMessage, wePortType, weBinding, weService, weTypes, WeImport, weOperation, wePart };
#pragma option pop

typedef Set<TWSDLElement, weServiceIntf, wePart>  TWSDLElements;

#pragma pack(push, 4)
struct TWString
{
	WideString WString;
} ;
#pragma pack(pop)

class DELPHICLASS TWideStrings;
class PASCALIMPLEMENTATION TWideStrings : public System::TObject 
{
	typedef System::TObject inherited;
	
public:
	WideString operator[](int Index) { return Strings[Index]; }
	
private:
	Classes::TList* FWideStringList;
	WideString __fastcall Get(int Index);
	void __fastcall Put(int Index, const WideString S);
	
public:
	__fastcall TWideStrings(void);
	__fastcall virtual ~TWideStrings(void);
	int __fastcall Count(void);
	void __fastcall Clear(void);
	int __fastcall Add(const WideString S);
	int __fastcall IndexOf(const WideString S);
	int __fastcall IndexOfIgnoreCase(const WideString S);
	void __fastcall Insert(int Index, const WideString S);
	__property WideString Strings[int Index] = {read=Get, write=Put/*, default*/};
};


typedef AnsiString WSDLIntf__2[65];

typedef AnsiString WSDLIntf__3[44];

typedef AnsiString WSDLIntf__4[13];

typedef AnsiString WSDLIntf__5[13];

typedef AnsiString WSDLIntf__6[13];

//-- var, const, procedure ---------------------------------------------------
#define SDefinitions "definitions"
#define SMessage "message"
#define SPart "part"
#define SType "type"
#define STypes "types"
#define SImport "import"
#define SPort "port"
#define SPortType "portType"
#define SOperation "operation"
#define SBinding "binding"
#define SService "service"
#define SSchema "schema"
#define SName "name"
#define STns "targetNamespace"
#define SInput "input"
#define SOutput "output"
#define SInOut "inout"
#define SRequest "Request"
#define SResponse "Response"
#define SReturn "return"
#define SElement "element"
#define SComplexType "complexType"
#define xsdns "http://www.w3.org/1999/XMLSchema"
#define tns "http://tempuri.org/"
#define Wsdlns "http://schemas.xmlsoap.org/wsdl/"
#define Soapns "http://schemas.xmlsoap.org/wsdl/soap/"
#define Httpns "http://schemas.xmlsoap.org/wsdl/http/"
#define SAddress "address"
#define SBody "body"
#define SHeader "header"
#define SFault "fault"
#define SVerb "verb"
#define SStyle "style"
#define STransport "transport"
#define SLocation "location"
#define SSoapAction "soapAction"
#define SParts "parts"
#define SUse "use"
#define SNameSpace "namespace"
#define SEncodingStyle "encodingStyle"
#define SArrayOf "ArrayOf"
#define SArray "Array"
#define SArrayType "arrayType"
#define SUnknown "Unknown"
#define SDynArray "array of "
#define SAnySimpleType "anySimpleType"
#define SNsPrefix "ns"
extern PACKAGE AnsiString ReservedWords[65];
extern PACKAGE AnsiString Directives[44];
extern PACKAGE AnsiString Operators[13];
extern PACKAGE AnsiString ScalarArrayTypes[13];
extern PACKAGE AnsiString DynArrayTypes[13];

}	/* namespace Wsdlintf */
using namespace Wsdlintf;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// WSDLIntf
