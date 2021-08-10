// ************************************************************************ //
// The types declared in this file were generated from data read from the
// WSDL File described below:
// WSDL     : http://localhost/soap/IIS_EchoSimpleTypes.dll/wsdl/IEchoSimpleTypes
// Version  : 1.0
// (11/6/2001 12:08:11 PM - $Revision:   1.0.2.0.1.0  $)
// ************************************************************************ //

#ifndef   __IEchoSimpleTypes_h__
#define   __IEchoSimpleTypes_h__

#include <System.hpp>
#include <InvokeRegistry.hpp>
#include <XSBuiltIns.hpp>
#include <SoapHTTPClient.hpp>

// ************************************************************************ //
// The following types, referred to in the WSDL document are not being represented
// in this file. They are either aliases[@] of other types represented or were simply
// not explicitly[!] declared in the WSDL document. The types from the latter category
// typically map to known XML Schema or Borland types.
// ************************************************************************ //
// !:base64Binary    - "http://www.w3.org/2001/XMLSchema"
// !:string          - "http://www.w3.org/2001/XMLSchema"
// !:boolean         - "http://www.w3.org/2001/XMLSchema"
// !:Unknown         - ""
// !:short           - "http://www.w3.org/2001/XMLSchema"
// !:int             - "http://www.w3.org/2001/XMLSchema"
// !:unsignedInt     - "http://www.w3.org/2001/XMLSchema"
// !:float           - "http://www.w3.org/2001/XMLSchema"
// !:double          - "http://www.w3.org/2001/XMLSchema"


// ************************************************************************ //
// Namespace : urn:ISimpleTypes-IEchoSimpleTypes
// soapAction: urn:ISimpleTypes-IEchoSimpleTypes#%operationName%
// transport : http://schemas.xmlsoap.org/soap/http
// style     : rpc
// binding   : tns:IEchoSimpleTypesbinding
// ************************************************************************ //
__interface INTERFACE_UUID("{B0BD61C4-576C-4228-9D43-43E164AEB0DF}") IEchoSimpleTypes : public IInvokable
{
public:
  virtual TByteDynArray   echoBase64Binary(const TByteDynArray anarray) = 0; 
  virtual AnsiString      echoString(const AnsiString astring) = 0; 
  virtual bool            echoBoolean(const bool aboolean) = 0; 
  virtual Unknown         echoDate(const Unknown adate) = 0; 
  virtual Smallint        echoShort(const Smallint asmallint) = 0; 
  virtual int             echoLong(const int alongint) = 0; 
  virtual int             echoInt(const int aint) = 0; 
  virtual unsigned int    echoUnsignedInt(const unsigned int alongword) = 0; 
  virtual float           echoFloat(const float asingle) = 0; 
  virtual double          echoDouble(const double adouble) = 0; 
};
typedef DelphiInterface<IEchoSimpleTypes> IEchoSimpleTypesIntf;


#endif // __IEchoSimpleTypes_h__
