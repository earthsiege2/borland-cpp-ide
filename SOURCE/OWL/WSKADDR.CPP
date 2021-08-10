//----------------------------------------------------------------------------
// ObjectWindows
// Copyright (c) 1995, 1997 by Borland International, All Rights Reserved
//
//$Revision:   10.16  $
//
// Winsock for OWL subsystem.
// Based on work by Paul Pedriana, 70541.3223@compuserve.com
//----------------------------------------------------------------------------
#include <owl/pch.h>
#if !defined(OWL_WINSOCK_H)
# include <owl/winsock.h>
#endif

OWL_DIAGINFO;

//
// Only the family is specified.  The rest of the data will currently be
// undefined.
//
TSocketAddress::TSocketAddress()
{
  sa_family = AF_UNSPEC;
}

//
// The argument is a sockaddr in network byte ordering.
//
TSocketAddress::TSocketAddress(const sockaddr& src)
{
  operator =(src);
}

//
// The argument address should be in network byte ordering.
//
TSocketAddress::TSocketAddress(const TSocketAddress& src)
{
  operator =(src);
}

//
// The argument address should be in network byte ordering.
//
TSocketAddress::TSocketAddress(ushort newFamily, char* data, short dataLength)
{
  SetAddress(newFamily, data, dataLength);
}

//
// The argument address should be in network byte ordering.
//
TSocketAddress& TSocketAddress::operator =(const sockaddr& src)
{
  SetAddress(src.sa_family, src.sa_data, 14);
  return *this;
}

//
// Both addresses should be in the same byte ordering as each other.
// We just happen to know for a fact that the sockaddr's have same data as
// TSocketAddress's.
//
bool operator ==(const TSocketAddress& address1, const TSocketAddress& address2)
{
  if (address1.sa_family != address2.sa_family)
    return false;

  for (int i = 0; i < 14; i++) {
    if (address1.sa_data[i] != address2.sa_data[i])
      return false;
  }
  return true;
}

//
// 'newFamily' is AF_INET, etc.  'data' is a pointer to data in the same
// format as sockaddr.sa_data[].  'dataLength' is the length of data.  It is
// limited to 14 bytes in WinSock 1.1.  The passed data should be in network
// byte ordering.
//
void TSocketAddress::SetAddress(ushort family, const char* data, short dataLength)
{
  sa_family = family;
  for (int i = 0; i < dataLength && i < 14; i++)
    sa_data[i] = data[i];
}

//----------------------------------------------------------------------------

//
// Empty constructor.  Useful for creating an TInetSocketAddress, but delaying
// the actual assignment of addressing data until later.
//
TINetSocketAddress::TINetSocketAddress()
:
  TSocketAddress()
{
  SetAddress(AF_INET, 0, INADDR_ANY);  // default values.  Can be changed later.
}

//
// The argument should be in network byte ordering
//
TINetSocketAddress::TINetSocketAddress(const sockaddr& src)
:
  TSocketAddress(src)
{
}

//
// All arguments should be in network byte ordering. newFamily is an
// enumeration, so there is no specific byte ordering.  Note that address can
// also be INADDR_ANY, INADDR_LOOPBACK, INADDR_BROADCAST, INADDR_NONE.  Also
// note that in winsock.h (1.1), Microsoft defines these addresses in network
// byte ordering format, so you don't need to convert to network byte ordering
// upon passing to this function or any other that expects network byte
// ordering.
//
TINetSocketAddress::TINetSocketAddress(ushort newPort, ulong newAddress, ushort newFamily)
{
  SetAddress(newFamily, newPort, newAddress);
}

//
// newPort should be passed in network byte ordering.  newAddress is in the
// format of numerical IP addressing (e.g. "132.212.43.1").  It cannot be in
// the form of "user@place" nFamily is in the form of AF_INET, etc.
//
TINetSocketAddress::TINetSocketAddress(ushort newPort, const char* newAddressStr, ushort newFamily)
{
  ulong newAddress = ConvertAddress(newAddressStr);
  SetAddress(newFamily, newPort, newAddress);
}

// 
// Obsolete version of previous constructor included for backward
// compatibility (doesn't use const)
// 

TINetSocketAddress::TINetSocketAddress(ushort newPort, char* newAddressStr, ushort newFamily)
{
  ulong newAddress = ConvertAddress(newAddressStr);
  SetAddress(newFamily, newPort, newAddress);
}

//
// The argument should be in the same byte ordering (network) as this object.
//
TINetSocketAddress& TINetSocketAddress::operator =(const sockaddr& newSockaddr)
{
  TSocketAddress::SetAddress(newSockaddr.sa_family, newSockaddr.sa_data, 14);
  return *this;
}

//
// This function accepts a string in the form of e.g. 162.132.211.204" and
// converts it to an IP address (ulong) if possible.  The returned value will
// be in network byte ordering. It should be INADDR_NONE if there was an error.
//
ulong TINetSocketAddress::ConvertAddress(const char far* address)
{
  return TWinSockDll::inet_addr(address);
}

//
// This function accepts a ulong in the form of an IP binary address and
// converts it to an character string IP address (e.g.  "123.213.132.122") if
// possible.  The lAddress parameter must be given in network byte ordering to
// work properly.  Note that this function returns a character pointer to a
// string allocated by the system.  It is imperative that the caller
// immediately copy this data, and neither modify it nor de-allocate it, etc.
// This restriction is imposed by Winsock.
//
char far* TINetSocketAddress::ConvertAddress(ulong address)
{
  in_addr   tempAddress;
  char far* addressStr;

  tempAddress.s_addr = address;
  addressStr = TWinSockDll::inet_ntoa(tempAddress);
  return addressStr;
}

//
// This function can be used to tell if a character string points to an
// address in dotted-decimal IP format (e.g. "162.132.211.204") or in name
// format (e.g.  "jimmy_carter@wh.com").  You could call this function if the
// user typed in a destination address in one of either of the above formats,
// and you need to know which one it is, so you can know how to convert it to
// a ulong IP address.  If the address is dotted-decimal, then you can simpoy
// use the TINetSocketAddress::ConvertAddress() function.  Otherwise, you need
// to use one ofthe HostInfoManager functions.  The szAddress is a pointer to
// a string that can be in any format, but most likely, one of either the
// dotted-decimal or the name formats mentioned above.  This function's job is
// only to tell you if it is in dotted-decimal format or not.  The return
// value is 1 if in dotted-decimal format, and 0 if not.
//
#pragma warn -cln
short TINetSocketAddress::IsAddressDottedDecimal(const char far* addressStr)
{
  ulong returnValue = TWinSockDll::inet_addr(addressStr);
  if (returnValue == INADDR_NONE)
    return 0;
  return 1;
}
#pragma warn .cln

//
// This function makes an address out of the necessary IP address components.
// newFamily is an enumeration, e.g. AF_INET.
// newPort is in network byte ordering, as is lNewAddress.
//
void TINetSocketAddress::SetAddress(ushort newFamily, ushort newPort,
                                    ulong newAddress)
{
  SetFamily(newFamily);
  SetPort(newPort);
  SetNetworkAddress(newAddress);
  SetFiller();
}

//
// Returns port in network byte ordering
//
ushort TINetSocketAddress::GetPort() const
{
  return ((sockaddr_in*)this)->sin_port;
}

//
// Returns IP binary address in network byte ordering
//
ulong TINetSocketAddress::GetNetworkAddress() const
{
  return ((sockaddr_in*)this)->sin_addr.s_addr;
}

//
// This function returns 0 if the network cannot be determined.
//
#pragma warn -cln
ulong TINetSocketAddress::GetNetwork() const
{
  TINetClass theINetClass = GetClass();

  ulong    subnetMask;
  if (theINetClass == ClassA)
    subnetMask = IN_CLASSA_NET;  //0xFF000000L;
  else if (theINetClass == ClassB)
    subnetMask = IN_CLASSB_NET; //0xFFFF0000L;
  else if (theINetClass == ClassC)
    subnetMask = IN_CLASSC_NET; //0xFFFFFF00L;
  else // ClassUnknown
    return 0;

  return GetNetwork(subnetMask);
}
#pragma warn .cln

//
// Return network address with subnet masked out
//
ulong TINetSocketAddress::GetNode() const
{
  TINetClass theINetClass = GetClass();

  ulong    subnetMask;
  if (theINetClass == ClassA)
    subnetMask = 0xFF000000L;
  else if (theINetClass == ClassB)
    subnetMask = 0xFFFF0000L;
  else if (theINetClass == ClassC)
    subnetMask = 0xFFFFFF00L;
  else //ClassUnknown
    return 0;

  return GetNode(subnetMask);
}

//
// Sets the port.
// This function expects the argument to be in network byte ordering.
//
void TINetSocketAddress::SetPort(ushort port)
{
  ((sockaddr_in*)this)->sin_port = port;
}

//
// Sets the network address.
// This function expects the argument to be in network byte ordering.
//
void TINetSocketAddress::SetNetworkAddress(ulong address)
{
   ((sockaddr_in*)this)->sin_addr.s_addr = address;
}

//
// Sets the network address.
//
void TINetSocketAddress::SetNetworkAddress(const char* addressDottedDecimal)
{
   SetNetworkAddress(ConvertAddress(addressDottedDecimal));
}

//
// This is an internal function.  It is merely used to zero out the unused
//  data of the address.
//
void TINetSocketAddress::SetFiller()
{
  for (int i = 0; i < 8; i++)
    ((sockaddr_in*)this)->sin_zero[i] = 0;
}

//
// This function uses WinSock macros to get standard class information.
// It knows nothing about subnetting, nor any classes beyond class C.
//
#pragma warn -cln
TINetSocketAddress::TINetClass TINetSocketAddress::GetClass() const
{
  if (IN_CLASSA(GetNetworkAddress()))
    return ClassA;
  if (IN_CLASSB(GetNetworkAddress()))
    return ClassB;
  if (IN_CLASSC(GetNetworkAddress()))
    return ClassC;
  return ClassUnknown;
}
#pragma warn .cln
