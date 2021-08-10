// ************************************************************************ //
// The types declared in this file were generated from data read from the
// WSDL File described below:
// WSDL     : http://www.whitemesa.com/interop/InteropTest.wsdl
// Codegen  : [wfServer]
// Version  : 1.0
// (1/11/2002 12:22:57 PM - $Revision:   1.0.2.0.1.1  $)
// ************************************************************************ //

#ifndef   __SimpleEchoImpl_h__
#define   __SimpleEchoImpl_h__

#include <System.hpp>
#include <InvokeRegistry.hpp>
#include <XSBuiltIns.hpp>


namespace SimpleEchoImpl {

// ************************************************************************ //
// The following types, referred to in the WSDL document are not being represented
// in this file. They are either aliases[@] of other types represented or were referred
// to but never[!] declared in the document. The types from the latter category
// typically map to predefined/known XML or Borland types; however, they could also 
// indicate incorrect WSDL documents that failed to declare or import a schema type.
// ************************************************************************ //
// !:string          - "http://soapinterop.org/xsd"
// !:int             - "http://soapinterop.org/xsd"
// !:float           - "http://soapinterop.org/xsd"
// !:string          - "http://www.w3.org/2001/XMLSchema"
// !:int             - "http://www.w3.org/2001/XMLSchema"
// !:float           - "http://www.w3.org/2001/XMLSchema"
// !:base64Binary    - "http://www.w3.org/2001/XMLSchema"
// !:dateTime        - "http://www.w3.org/2001/XMLSchema"
// !:hexBinary       - "http://www.w3.org/2001/XMLSchema"
// !:decimal         - "http://www.w3.org/2001/XMLSchema"
// !:boolean         - "http://www.w3.org/2001/XMLSchema"

class  SOAPStruct;

typedef DynamicArray<AnsiString>  ArrayOfstring;  /* "http://soapinterop.org/xsd" */
typedef DynamicArray<int>         ArrayOfint;     /* "http://soapinterop.org/xsd" */
typedef DynamicArray<float>       ArrayOffloat;   /* "http://soapinterop.org/xsd" */


// ************************************************************************ //
// Namespace : http://soapinterop.org/xsd
// ************************************************************************ //
class SOAPStruct : public TRemotable {
private:
  AnsiString      FvarString;
  int             FvarInt;
  float           FvarFloat;
public:
__published:
  __property AnsiString  varString = { read=FvarString, write=FvarString };
  __property int            varInt = { read=FvarInt, write=FvarInt };
  __property float        varFloat = { read=FvarFloat, write=FvarFloat };
};


typedef DynamicArray<SOAPStruct*> ArrayOfSOAPStruct; /* "http://soapinterop.org/xsd" */

// ************************************************************************ //
// Namespace : http://soapinterop.org/
// soapAction: http://soapinterop.org/
// transport : http://schemas.xmlsoap.org/soap/http
// style     : rpc
// binding   : InteropTestSoapBinding
// ************************************************************************ //
__interface INTERFACE_UUID("{BBCF633F-2FCA-C18C-C5C8-251A972883F5}") InteropTestPortType : public IInvokable
{
public:
  virtual AnsiString      echoString(const AnsiString inputString) = 0; 
  virtual ArrayOfstring   echoStringArray(const ArrayOfstring inputStringArray) = 0; 
  virtual int             echoInteger(const int inputInteger) = 0; 
  virtual ArrayOfint      echoIntegerArray(const ArrayOfint inputIntegerArray) = 0; 
  virtual float           echoFloat(const float inputFloat) = 0; 
  virtual ArrayOffloat    echoFloatArray(const ArrayOffloat inputFloatArray) = 0; 
  virtual SOAPStruct*     echoStruct(const SOAPStruct* inputStruct) = 0; 
  virtual ArrayOfSOAPStruct echoStructArray(const ArrayOfSOAPStruct inputStructArray) = 0; 
  virtual void            echoVoid() = 0; 
  virtual TByteDynArray   echoBase64(const TByteDynArray inputBase64) = 0; 
  virtual TXSDateTime*    echoDate(const TXSDateTime* inputDate) = 0; 
  virtual TXSHexBinary*   echoHexBinary(const TXSHexBinary* inputHexBinary) = 0; 
  virtual TXSDecimal*     echoDecimal(const TXSDecimal* inputDecimal) = 0; 
  virtual bool            echoBoolean(const bool inputBoolean) = 0; 
};
typedef DelphiInterface<InteropTestPortType> _di_InteropTestPortType;



#endif // __SimpleEchoImpl_h__

};     // SimpleEchoImpl

#if !defined(NO_IMPLICIT_NAMESPACE_USE)
using  namespace SimpleEchoImpl;
#endif

