// ************************************************************************ //
// The types declared in this file were generated from data read from the
// WSDL File described below:
// WSDL     : http://www.whitemesa.com/interop/InteropTest.wsdl
// Codegen  : [wfServer]
// Version  : 1.0
// (1/11/2002 12:22:57 PM - $Revision:   1.0.2.0.1.1  $)
// ************************************************************************ //

#include <vcl.h>
#pragma hdrstop

#if !defined(__SimpleEchoImpl_h__)
#include "SimpleEchoImpl.h"
#endif



namespace SimpleEchoImpl {

class TInteropTestPortTypeImpl : public TInvokableClass, public InteropTestPortType
{
public:

  /* InteropTestPortType */
  AnsiString      echoString(const AnsiString inputString); 
  ArrayOfstring   echoStringArray(const ArrayOfstring inputStringArray); 
  int             echoInteger(const int inputInteger); 
  ArrayOfint      echoIntegerArray(const ArrayOfint inputIntegerArray); 
  float           echoFloat(const float inputFloat); 
  ArrayOffloat    echoFloatArray(const ArrayOffloat inputFloatArray); 
  SOAPStruct*     echoStruct(const SOAPStruct* inputStruct); 
  ArrayOfSOAPStruct echoStructArray(const ArrayOfSOAPStruct inputStructArray); 
  void            echoVoid(); 
  TByteDynArray   echoBase64(const TByteDynArray inputBase64); 
  TXSDateTime*    echoDate(const TXSDateTime* inputDate); 
  TXSHexBinary*   echoHexBinary(const TXSHexBinary* inputHexBinary); 
  TXSDecimal*     echoDecimal(const TXSDecimal* inputDecimal); 
  bool            echoBoolean(const bool inputBoolean); 

  /* IUnknown */
  HRESULT STDMETHODCALLTYPE QueryInterface(const GUID& IID, void **Obj)
                        { return GetInterface(IID, Obj) ? S_OK : E_NOINTERFACE; }
  ULONG STDMETHODCALLTYPE AddRef() { return TInterfacedObject::_AddRef();  }
  ULONG STDMETHODCALLTYPE Release(){ return TInterfacedObject::_Release(); }
};

AnsiString TInteropTestPortTypeImpl::echoString(const AnsiString inputString)
{
  /* TODO : Implement WebService method echoString */
  return inputString;
}

ArrayOfstring TInteropTestPortTypeImpl::echoStringArray(const ArrayOfstring inputStringArray)
{
  /* TODO : Implement WebService method echoStringArray */
  return inputStringArray;
}

int TInteropTestPortTypeImpl::echoInteger(const int inputInteger)
{
  /* TODO : Implement WebService method echoInteger */
  return inputInteger;
}

ArrayOfint TInteropTestPortTypeImpl::echoIntegerArray(const ArrayOfint inputIntegerArray)
{
  /* TODO : Implement WebService method echoIntegerArray */
  return inputIntegerArray;
}

float TInteropTestPortTypeImpl::echoFloat(const float inputFloat)
{
  /* TODO : Implement WebService method echoFloat */
  return inputFloat;
}

ArrayOffloat TInteropTestPortTypeImpl::echoFloatArray(const ArrayOffloat inputFloatArray)
{
  /* TODO : Implement WebService method echoFloatArray */
  return inputFloatArray;
}

SOAPStruct* TInteropTestPortTypeImpl::echoStruct(const SOAPStruct* inputStruct)
{
  /* TODO : Implement WebService method echoStruct */
  return const_cast<SOAPStruct*>(inputStruct);
}

ArrayOfSOAPStruct TInteropTestPortTypeImpl::echoStructArray(const ArrayOfSOAPStruct inputStructArray)
{
  /* TODO : Implement WebService method echoStructArray */
  return inputStructArray;
}

void TInteropTestPortTypeImpl::echoVoid()
{
  /* TODO : Implement WebService method echoVoid */
}

TByteDynArray TInteropTestPortTypeImpl::echoBase64(const TByteDynArray inputBase64)
{
  /* TODO : Implement WebService method echoBase64 */
  return inputBase64;
}

TXSDateTime* TInteropTestPortTypeImpl::echoDate(const TXSDateTime* inputDate)
{
  /* TODO : Implement WebService method echoDate */
  return const_cast<TXSDateTime*>(inputDate);
}

TXSHexBinary* TInteropTestPortTypeImpl::echoHexBinary(const TXSHexBinary* inputHexBinary)
{
  /* TODO : Implement WebService method echoHexBinary */
  return const_cast<TXSHexBinary*>(inputHexBinary);
}

TXSDecimal* TInteropTestPortTypeImpl::echoDecimal(const TXSDecimal* inputDecimal)
{
  /* TODO : Implement WebService method echoDecimal */
  return const_cast<TXSDecimal*>(inputDecimal);
}

bool TInteropTestPortTypeImpl::echoBoolean(const bool inputBoolean)
{
  /* TODO : Implement WebService method echoBoolean */
  return inputBoolean;
}

// ************************************************************************ //
// This routine registers the interfaces and types used by invoke the SOAP
// Service.
// ************************************************************************ //
static void RegTypes()
{
  /* InteropTestPortType */
  InvRegistry()->RegisterInterface(__interfaceTypeinfo(InteropTestPortType), L"http://soapinterop.org/", L"");
  InvRegistry()->RegisterDefaultSOAPAction(__interfaceTypeinfo(InteropTestPortType), L"http://soapinterop.org/");
  RemClassRegistry()->RegisterXSInfo(__arrayTypeinfo(ArrayOfstring), L"http://soapinterop.org/xsd", L"ArrayOfstring");
  RemClassRegistry()->RegisterXSInfo(__arrayTypeinfo(ArrayOfint), L"http://soapinterop.org/xsd", L"ArrayOfint");
  RemClassRegistry()->RegisterXSInfo(__arrayTypeinfo(ArrayOffloat), L"http://soapinterop.org/xsd", L"ArrayOffloat");
  /* SOAPStruct */
  RemClassRegistry()->RegisterXSClass(__classid(SOAPStruct), L"http://soapinterop.org/xsd", L"SOAPStruct");
  RemClassRegistry()->RegisterXSInfo(__arrayTypeinfo(ArrayOfSOAPStruct), L"http://soapinterop.org/xsd", L"ArrayOfSOAPStruct");
  /* InteropTestPortType - Server implementation class */
  InvRegistry()->RegisterInvokableClass(__classid(TInteropTestPortTypeImpl));
}
#pragma startup RegTypes 32

};     // SimpleEchoImpl

