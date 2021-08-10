//----------------------------------------------------------------------------
// ObjectWindows
// Copyright (c) 1995, 1997 by Borland International, All Rights Reserved
//
//$Revision:   10.13  $
//
// Winsock for OWL subsystem.
// Based on work by Paul Pedriana, 70541.3223@compuserve.com
//----------------------------------------------------------------------------
#if !defined(OWL_WSKADDR_H)
#define OWL_WSKADDR_H

#if !defined(OWL_DEFS_H)
# include <owl/defs.h>
#endif
#if !defined (_WINSOCKAPI_)
# include <winsock.h>
#endif

#if defined(BI_NAMESPACE)
namespace OWL {
#endif

// Generic definitions/compiler options (eg. alignment) preceeding the 
// definition of classes
#include <services/preclass.h>

//
// class TSocketAddress
// ~~~~~ ~~~~~~~~~~~~~~
// TSocketAddress normally stores its data in network byte ordering, as
// opposed to host byte ordering.
//
class _OWLCLASS TSocketAddress : public sockaddr {
  public:
    TSocketAddress();
    TSocketAddress(const sockaddr& src);
    TSocketAddress(const TSocketAddress& src);
    TSocketAddress(ushort family, char* data, short dataLength);

    TSocketAddress& operator =(const sockaddr& src);
    friend bool operator ==(const TSocketAddress& address1, const TSocketAddress& address2);

    ushort GetFamily() const;
    void SetFamily(ushort family);
    void SetAddress(ushort family, const char* data, short dataLength);
};

//
// class TINetSocketAddress
// ~~~~~ ~~~~~~~~~~~~~~~~~~
// Encapsulates the Internet socket address structure (sockaddr_in).
//
class _OWLCLASS TINetSocketAddress : public TSocketAddress {
  public:
    // Different classes of Internet addressing.  An address resolves to a
    // 32-bit value. Each class has a different encoding scheme.
    //
    //
    enum TINetClass {
      ClassA,         // A class net addressing
      ClassB,         // B class net addressing
      ClassC,         // C class net addressing
      ClassUnknown    // Unknown class net addressing
    };

    TINetSocketAddress();
    TINetSocketAddress(const sockaddr& src);
    TINetSocketAddress(ushort newPort, ulong newAddress = INADDR_ANY,
                       ushort newFamily = AF_INET);
    TINetSocketAddress(ushort newPort, const char* newAddress,
                       ushort newFamily = AF_INET);

    TINetSocketAddress& operator =(const sockaddr& src);
    operator sockaddr_in() const;

    TINetClass GetClass() const;
    ushort GetPort() const;
    ulong GetNetworkAddress() const;
    ulong GetNetwork() const;
    ulong GetNetwork(ulong subnet) const;
    ulong GetNode() const;
    ulong GetNode(ulong subnet) const;
    void SetAddress(ushort newFamily, ushort newPort, ulong newAddress);
    void SetPort(ushort port);
    void SetNetworkAddress(ulong address);
    void SetNetworkAddress(const char* addressDottedDecimal);
    void SetFiller();

    static ulong ConvertAddress(const char far* address);
    static char far* ConvertAddress(ulong address);
    static short IsAddressDottedDecimal(const char far* address);

    // These routines are rendered obsolete by newer versions
    // that use const for the address argument.  Included for
    // backwards compatibility.

    TINetSocketAddress(ushort newPort, char* newAddress,
                       ushort newFamily = AF_INET);
    void SetNetworkAddress(char* addressDottedDecimal);
    static ulong ConvertAddress(char far* address);
    static short IsAddressDottedDecimal(char far* address);

};

// Generic definitions/compiler options (eg. alignment) following the 
// definition of classes
#include <services/posclass.h>

#if defined(BI_NAMESPACE)
} // namespace OWL
#endif

//----------------------------------------------------------------------------
// Inline implementations
//

//
// Return the family of addressing this address belongs to.
//
inline ushort
TSocketAddress::GetFamily() const
{
  return sa_family;
}

//
// Set the family of addressing this address belongs to.
//
inline void
TSocketAddress::SetFamily(ushort family)
{
  sa_family = family;
}

//
// Convert this address to the sockaddr_in structure.
//
inline
TINetSocketAddress::operator sockaddr_in() const
{
  return *((sockaddr_in*)this);
}

//
// Return the network id masked with the subnet.
//
inline ulong
TINetSocketAddress::GetNetwork(ulong subnet) const
{
  return GetNetworkAddress() & subnet;
}

//
// Return the node of this address.
//
inline ulong
TINetSocketAddress::GetNode(ulong subnet) const
{
  return GetNetworkAddress() & ~subnet;
}


//
//  Obsolete functions replaced by versions that make 
//  use of const
//

inline void
TINetSocketAddress::SetNetworkAddress(char* addressDottedDecimal)
{
  SetNetworkAddress(CONST_CAST(const char*, addressDottedDecimal));
}

inline static ulong
TINetSocketAddress::ConvertAddress(char far* address)
{
  return ConvertAddress(CONST_CAST(const char far*, address));
}

inline static short
TINetSocketAddress::IsAddressDottedDecimal(char far* address)
{
  return IsAddressDottedDecimal(CONST_CAST(const char far*, address));
}

#endif  // OWL_WSKADDR_H
