//----------------------------------------------------------------------------
// ObjectWindows
// Copyright (c) 1995, 1997 by Borland International, All Rights Reserved
//
//$Revision:   10.14  $
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
//
//
DEFINE_RESPONSE_TABLE1(THostInfoWindow, TWindow)
   EV_MESSAGE(MSG_HOST_INFO_NOTIFY, DoNotification),
END_RESPONSE_TABLE;

//
// The HostInfoWindow requires a HostInfoManager, so it can
// relay messages to it.
//
THostInfoWindow::THostInfoWindow(THostInfoManager* hostInfoManagerParent)
:
  TWindow(0, "HostInfo Window"),
  HostInfoManagerParent(hostInfoManagerParent)
{
  Attr.Style = 0;  // Turn off WS_CHILD (the default) style).
}

//
// This is the relay function.
//
TResult THostInfoWindow::DoNotification(TParam1, TParam2 param2)
{
  HostInfoManagerParent->SetHostRequestCompleted(WSAGETASYNCERROR(param2));
  return 1;
}

//----------------------------------------------------------------------------

//
// Constructor of THostEntry object. Initialize members describing host to 0.
//
THostEntry::THostEntry()
{
  h_name      = 0;
  h_aliases   = 0;
  h_addrtype  = 0;
  h_length    = 0;
  h_addr_list = 0;
}

//
// Returns the number of pointers to addresses in the hostent (parent
// class of THostEntry).
//
int THostEntry::GetAddressCount()
{
  int i = 0;
  while (h_addr_list[i])
    i++;

  return i;
}

//
// This function is FLAWED in that it is internet addressing-specific
//  (AF_INET/PF_INET).
// The proper way to implement this function would be to look at h_addrtype
//  and h_length to determine the nature of the address type and return
//  something useful or make a derived class that knows about each address
//  family. (...)
//
ulong THostEntry::GetNthINetAddress(int index)
{
  int addressCount = GetAddressCount();

  if (index >= addressCount)
    return 0;  //The caller asked for an address index that is out of range.

  return *((ulong*)h_addr_list[index]);
}

//----------------------------------------------------------------------------
// THostInfoManager
//

//
// Initialize the hidden window.
//
THostInfoManager::THostInfoManager()
:
  HostWindow(this)
{
  HostEntry            = (THostEntry*)&HostInfoBuffer;
  HostRequest          = 0;
  LastError            = 0;
  HostRequestCompleted = false;
  try {
    HostWindow.Create();
  }
  catch (...) {
    //::MessageBeep(10);  
 }
}

//
// In this destructor, we need to clear any pending requests before we
// get deleted.
//
THostInfoManager::~THostInfoManager()
{
  if (HostRequest && !HostRequestCompleted) // If there is an outstanding request...
    CancelHostRequest();
}

//
// This function returns the name of the computer on which this program is running. The
//  szName paramter will be set to be the name.
// The return value is either WINSOCK_ERROR or WINSOCK_NOERROR.  You can call the
//  THostInfoManager's GetLastError() to get the actual error value.
// name is a pointer to pre-allocated buffer of minimum size of nNameLength
// nameLength should be at least N_MAX_HOST_NAME.
//
int THostInfoManager::GetHostName(char far* name, int nameLength)
{
  if (TWinSockDll::gethostname(name, nameLength) == SOCKET_ERROR) {
    LastError = TWinSockDll::WSAGetLastError();
    return WINSOCK_ERROR;
  }
  return WINSOCK_NOERROR;
}

//
// This function effectively converts szHostName to szHostAddress.  If you have a
//  name such as "joe_schmoe@borland.com", and you want the dotted-decimal IP
//  address for it, you would call this function.
// This function assumes that you have enough space in szHostAddress for the address.
// This function, like most of Winsock 1.1, currently works with only IP addresses.
//  Thus, the szHostAddress is always going to be dotted-decimal format in Winsock 1.1.
// Note that while the inet_ntoa() function has the limitation (feature) that the
//  char* string returned resides in Winsock memory space, the szHostAddress returned
//  is allocated and owned by the caller of this function and can be manipulated any way
//  the caller wants.
// This function returns an error value of WINSOCK_ERROR or WINSOCK_NOERROR.
//
int THostInfoManager::GetHostAddress(char far* hostAddress, const char far* hostName)
{
  THostEntry* tempHostEntry;

  int error = GetHostInfo(tempHostEntry, hostName);
  if (error == WINSOCK_ERROR)
     return error;
  return HostEntryToAddress(tempHostEntry, hostAddress);
}

//
// This function effectively converts szHostName to a SocketAddres.  If you have
//  a name such as "joe_schmoe@borland.com", and you want the TSocketAddress for
//  it, you could call this function.
// This function, like most of Winsock 1.1, currently works with only IP addresses.
//  Thus, the szHostAddress is always going to be dotted-decimal format in Winsock 1.1.
// This function returns an error value of WINSOCK_ERROR or WINSOCK_NOERROR.
//
int THostInfoManager::GetHostAddress(TSocketAddress& address, const char far* hostName)
{
   THostEntry* tempHostEntry;

   int error = GetHostInfo(tempHostEntry, hostName);
   if (error == WINSOCK_ERROR)
      return error;
   return HostEntryToAddress(tempHostEntry, address);
}

//
// The caller of this function is supplying a pointer to be assigned by this function.  Note
//  that the caller need not allocate space for any THostEntry structure.  Note also that
//  because of this, the data needs to be read immediately or copied for later use.
//
// address is a preallocated SocketAddress reference.  Due to the design of the socket api, the
//  call to gethostbyaddr currently requires a pointer to the internet address, rather than
//  a sockaddr or even a sockaddr_in.  Because passing a ulong pointer would most likely
//  not work if the socket api was to support something other than IP, we fix this issue by
//  making a sockaddr interface to this api.  This comment applies to some other functions
//  in this class as well.
//
// The address is in network byte ordering.  Note that the call below requires the address in
//  network byte ordering.
//
int THostInfoManager::GetHostInfo(THostEntry*& entry, const TSocketAddress& address)
{
  sockaddr_in* tempSockAddrIn = (sockaddr_in*)&address;
  tempSockAddrIn->sin_addr.s_addr = tempSockAddrIn->sin_addr.s_addr;

  entry = (THostEntry*)TWinSockDll::gethostbyaddr(
                                   (const char far*)&tempSockAddrIn->sin_addr.s_addr,
                                   sizeof(ulong), PF_INET);
  if (!entry) {
    LastError = TWinSockDll::WSAGetLastError();
    return WINSOCK_ERROR;
  }
  return WINSOCK_NOERROR;
}

//
// This call is potentially blocking.
//
// entry is a pointer passed by reference.  The system will change that pointer to
//  point to an internal winsock data structure.  You must NOT modify its contents.
//
// name is a pre-allocated string that holds a string.  Holds address in text format.
//
// The caller of this function passes a pointer to a THostEntry struct. e.g.:
//   THostEntry* tempTHostEntry;
//   GetHostInfo(tempTHostEntry, "JoeShmoe@anywhere.com");
//   printf("%s", tempTHostEntry->h_name);  //h_name should be "joeSchmoe@anywhere,com"
//
int THostInfoManager::GetHostInfo(THostEntry*& entry, const char far* name)
{
  entry = (THostEntry*)TWinSockDll::gethostbyname(name);
  if (!entry) {
    LastError = TWinSockDll::WSAGetLastError();
    return WINSOCK_ERROR;
  }
  return WINSOCK_NOERROR;
}

//
// The caller can cancel the last pending request with this call.
//
int THostInfoManager::CancelHostRequest(HANDLE hostRequest)
{
  if (!hostRequest)
    hostRequest = HostRequest;

  if (!hostRequest) {
    LastError = WSAEINVAL;  // There is no handle to use.
    return WINSOCK_ERROR;
  }

  if (TWinSockDll::WSACancelAsyncRequest(hostRequest) == SOCKET_ERROR) {
    LastError = TWinSockDll::WSAGetLastError();
    return WINSOCK_ERROR;
  }

  return WINSOCK_NOERROR;
}

//
// The 'theHostRequest' parameter will be returned to the caller with the
//  asynchrous request handle.
// 'address' needs to be in network byte ordering.
//
// Note that due to the design of this class, you cannot have two outstanding
//  Service requests that get notified directly to this class.  You may use the
//  hwnd-specific notification version of this function to manage multiple
//  requests at a time.
//  You may also simply create more than one instance of this class.
//
// The service is complete when HostRequestCompleted is true.  You must look at
//  LastError in this case to see if there was an error. Note also that you must
//  not issue any async calls that post to this class' hwnd until the previous
//  request is completed.
//  The alternative is simply to create multiple THostInfoManagers, or manage
//  the call-backs yourself.
//
// For info about the nasty casting done below, see the comments about the
//  non-Async version of this call.
//
int THostInfoManager::GetHostInfoAsync(HANDLE& hostRequest, TSocketAddress& address)
{
  sockaddr_in* tempSockAddrIn = (sockaddr_in*)&address;
  tempSockAddrIn->sin_addr.s_addr = tempSockAddrIn->sin_addr.s_addr;

  HostRequestCompleted = false;
  HostRequest = hostRequest =
    TWinSockDll::WSAAsyncGetHostByAddr(HostWindow, MSG_HOST_INFO_NOTIFY,
                                    (char far*)&tempSockAddrIn->sin_addr.s_addr,
                                    sizeof(ulong), PF_INET, HostInfoBuffer,
                                    MAXGETHOSTSTRUCT);
  if (!hostRequest) {
    LastError = TWinSockDll::WSAGetLastError();
    return WINSOCK_ERROR;
  }
  return WINSOCK_NOERROR;
}

//
// Return same information as other version of GetHostInfoAsync.
// The difference is the host name can be a string, rather than a TSocketAddress.
//
int THostInfoManager::GetHostInfoAsync(HANDLE& theHostRequest, char far* name)
{
  HostRequestCompleted = false;
  HostRequest = theHostRequest =
      TWinSockDll::WSAAsyncGetHostByName(HostWindow, MSG_HOST_INFO_NOTIFY, name,
                                      HostInfoBuffer, MAXGETHOSTSTRUCT);

  if (!HostRequest) {
    LastError = TWinSockDll::WSAGetLastError();
    return WINSOCK_ERROR;
  }
  return WINSOCK_NOERROR;
}

//
// This function notifies the given window about the completion of the request.
// nMessage is the message that the hwndNotify will receive. It defaults to MSG_HOST_INFO_NOTIFY,
//  which is defined in the THostInfoManager's header file.
// The chBuffer is a pointer to buffer that will be filled in with a hostent.  Needs to be at least
//  MAXGETHOSTSTRUCT bytes.  If chBuffer is 0 (or not specified), then the THostInfoManager's
//  internal buffer will be used.
// The hTheHostRequest will hold a handle that the caller can use to reference the request on call-back.
//   wParam will be equal to the hService returned.
//   WSAGETSYNCERROR(lParam)   holds an error, if any (0 is OK).
//   WSAGETSYNCBUFLEN(lParam)  hold actual length of buffer
// When this function returns, myTHostEntry will be filled in with the appropriate information.
//  Since this information belongs to this object, you can delay reading it as long as you wish.
// Note that while the sAddress should be passed in network byte ordering, the output on callback
//  will also be in network ordering.
//
int THostInfoManager::GetHostInfoAsync(TWindow& wndNotify, HANDLE& hostRequest,
                                       TSocketAddress& address, uint message,
                                       char far* buffer)
{
  sockaddr_in* tempSockAddrIn = (sockaddr_in*)&address;
  tempSockAddrIn->sin_addr.s_addr = tempSockAddrIn->sin_addr.s_addr;

  char far* bufferToUse = buffer ? buffer : HostInfoBuffer;

  HostRequestCompleted = false;
  HostRequest = hostRequest =
    TWinSockDll::WSAAsyncGetHostByAddr(wndNotify, message,
                                    (char far*)&tempSockAddrIn->sin_addr.s_addr,
                                    sizeof(ulong), PF_INET, bufferToUse,
                                    MAXGETHOSTSTRUCT);

  if (!hostRequest) {
    LastError = TWinSockDll::WSAGetLastError();
    return WINSOCK_ERROR;
  }
  return WINSOCK_NOERROR;
}

//
// hwndNotify is the window that will get the message that the request has completed.
// nMessage is the message that the hwndNotify will receive. It defaults to MSG_HOST_INFO_NOTIFY,
//  which is defined in the THostInfoManager's header file.
// hTheHostRequest is the asynchrous request handle that will be a reference to the request.
// szName is the name of the host, as in "coyote@acme.com"
// The chBuffer is a pointer to buffer that will be filled in with a hostent.  Needs to be at least
//  MAXGETHOSTSTRUCT bytes.  If chBuffer is 0 (or not specified), then the THostInfoManager's
//  internal buffer will be used.
// The returned address will be in network byte ordering.
//
int THostInfoManager::GetHostInfoAsync(TWindow& wndNotify, HANDLE& hostRequest, char far* name,
                                       uint message, char far* buffer)
{
  char far* bufferToUse = buffer ? buffer : HostInfoBuffer;

  HostRequestCompleted = false;
  HostRequest = hostRequest =
     TWinSockDll::WSAAsyncGetHostByName(wndNotify, message, name, bufferToUse,
                                     MAXGETHOSTSTRUCT);

  if (!hostRequest) {
    LastError = TWinSockDll::WSAGetLastError();
    return WINSOCK_ERROR;
  }
  return WINSOCK_NOERROR;
}

//
// Given a THostEntry*, this function converts it to a dotted-decimal szAddress.
// Since Winsock 1.1 supports only IP addressing, this function is limited to
//  IP addressing and the address will always be only dotted-decimal.
//
// The return value is WINSOCK_ERROR or WINSOCK_NOERROR.
//
int THostInfoManager::HostEntryToAddress(THostEntry* entry, char far* address)
{
  in_addr    tempInAddr;
  tempInAddr.s_addr = *((ulong*)entry->h_addr);
            //else: = *((ulong*)hEntry->h_addr_list[0])

  char far* tempAddress = TWinSockDll::inet_ntoa(tempInAddr);
  if (!tempAddress)
    return WINSOCK_ERROR;
  strcpy(address, tempAddress);
  return WINSOCK_NOERROR;
}

//
// Given a THostEntry*, this function converts it to a SocketAddress. Since
//  Winsock 1.1 supports only IP addressing, this function is limited to IP
//  addressing and the address will be an INetSocketAddress.
// The return value is WINSOCK_ERROR or WINSOCK_NOERROR.
//
int THostInfoManager::HostEntryToAddress(THostEntry* entry, TSocketAddress& address)
{
  TINetSocketAddress *addr = STATIC_CAST(TINetSocketAddress*, &address);
  addr->SetNetworkAddress(*((ulong*)entry->h_addr));
  return WINSOCK_NOERROR;
}

//
// This function is called whenever an async request is completed.
// You may want to subclass this function.  If you do, you will probably want to call this
//  function as part of the subclassed function.
//
void THostInfoManager::SetHostRequestCompleted(int result)
{
  int error = WSAGETASYNCERROR(result);
  if (error != 0)
    LastError = error;
  HostRequestCompleted = true;  // Of course, there may have been an error.
}
