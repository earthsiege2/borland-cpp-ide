// ************************************************************************ //
// The types declared in this file were generated from data read from the
// WSDL File described below:
// WSDL     : http://localhost/soap/IIS_EchoSimpleTypes.dll/wsdl/IEchoSimpleTypes
// Version  : 1.0
// (11/6/2001 12:08:11 PM - $Revision:   1.0.2.0.1.0  $)
// ************************************************************************ //

#include <vcl.h>
#pragma hdrstop

#if !defined(__IEchoSimpleTypes_h__)
#include "IEchoSimpleTypes.h"
#endif


// ************************************************************************ //
// This routine registers the interfaces and types used by invoke the SOAP
// Service.
// ************************************************************************ //
static void RegTypes()
{
  /* IEchoSimpleTypes */
  InvRegistry()->RegisterInterface(__delphirtti(IEchoSimpleTypes), "urn:ISimpleTypes-IEchoSimpleTypes", "");
  InvRegistry()->RegisterDefaultSOAPAction(__delphirtti(IEchoSimpleTypes), "urn:ISimpleTypes-IEchoSimpleTypes#%operationName%");
}
#pragma startup RegTypes 32
