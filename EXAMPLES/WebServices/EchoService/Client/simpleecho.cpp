// ************************************************************************ //
// The types declared in this file were generated from data read from the
// WSDL File described below:
// WSDL     : http://localhost/scripts/CGI_SimpleEcho.exe/wsdl/InteropTestPortType
// Version  : 1.0
// (1/11/2002 1:00:22 PM - $Revision:   1.0.2.0.1.1  $)
// ************************************************************************ //

#include <vcl.h>
#pragma hdrstop

#if !defined(__SimpleEcho_h__)
#include "SimpleEcho.h"
#endif



namespace SimpleEcho {

_di_InteropTestPortType GetInteropTestPortType(bool useWSDL, AnsiString addr)
{
  static const char* defWSDL= "http://localhost/scripts/CGI_SimpleEcho.exe/wsdl/InteropTestPortType";
  static const char* defURL = "http://localhost/scripts/CGI_SimpleEcho.exe/soap/InteropTestPortType";
  static const char* defSvc = "InteropTestPortTypeservice";
  static const char* defPrt = "InteropTestPortTypePort";
  if (addr=="")
    addr = useWSDL ? defWSDL : defURL;
  THTTPRIO* rio = new THTTPRIO(0);
  if (useWSDL) {
    rio->WSDLLocation = addr;
    rio->Service = defSvc;
    rio->Port = defPrt;
  } else {
    rio->URL = addr;
  }
  _di_InteropTestPortType service;
  rio->QueryInterface(service);
  if (!service)
    delete rio;
  return service;
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
}
#pragma startup RegTypes 32

};     // SimpleEcho

