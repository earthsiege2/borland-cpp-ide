//----------------------------------------------------------------------------
// ObjectWindows
// Copyright (c) 1995, 1996 by Borland International, All Rights Reserved
//
//$Revision:   10.8  $
//
// Winsock for OWL subsystem.
// Based on work by Paul Pedriana, 70541.3223@compuserve.com
//----------------------------------------------------------------------------
#include <owl/pch.h>
#if !defined(OWL_WINSOCK_H)
# include <owl/winsock.h>
#endif

//
//
//
DEFINE_RESPONSE_TABLE1(TServiceWindow, TWindow)
   EV_MESSAGE(MSG_SERVICE_NOTIFY, DoNotification),
END_RESPONSE_TABLE;

//
// A TServiceWindow requires a TServiceManager parent.
//
TServiceWindow::TServiceWindow(TServiceManager* serviceManagerParent)
:
  TWindow(0, "WinsockServiceWindow"),
  ServiceManagerParent(serviceManagerParent)
{
  Attr.Style = 0;  // Turn off WS_CHILD (the default) style).
}

//
// This function merely calls the parent notification function.  Since Windows is designed
//  to only allow Windows to receive system messages, we use a dummy window that does nothing
//  but simulate the concept of Objects receiveing messages, in this case, the ServceManager
//  object.  The TServiceWindow hides this from the user (programmer).
//
TResult TServiceWindow::DoNotification(TParam1, TParam2 param2)
{
  ServiceManagerParent->ServiceCompleted(WSAGETASYNCERROR(param2));
  return 1;
}

//----------------------------------------------------------------------------

//
// Initialize all data members of servent to 0.
//
TServiceEntry::TServiceEntry()
{
  s_name    = 0;
  s_aliases = 0;
  s_port    = 0;
  s_proto   = 0;
}

//----------------------------------------------------------------------------

//
// Create the hidden window and initialize data members.
//
TServiceManager::TServiceManager()
:
  Window(this)
{
  ServiceEntry = (TServiceEntry*)&ServiceBuffer;
  LastServiceRequest          = 0;
  LastError                   = 0;
  LastServiceRequestCompleted = 0;
  OutstandingServiceRequests  = 0;
  try {
    Window.Create();
  }
  catch (...) {
    //Invalid Window exception.
  }
}

//
// Perform cleanup by cancelling any outstanding service requests.
//
TServiceManager::~TServiceManager()
{
  // If there is an outstanding request...
  //
  if (LastServiceRequest && !LastServiceRequestCompleted)
    CancelServiceRequest();
}

//
// Implements the blocking 'getservbyport()'.
//
// 'entry' is a pointer to a ServiceEntry*. The caller does NOT allocate a
//  ServiceEntry, it will be set by the system.  DO NOT chanage any data in the
//  returned structure.
// 'port' is passed to this function in network byte ordering.
// 'protocol' is the protocol name, but may be passed as 0 to mean default or first found.
// The returned entry has the port in network byte order.
//
int TServiceManager::GetService(TServiceEntry*& entry, int port, const char* protocol)
{
  entry = (TServiceEntry*)TWinSock::Dll()->getservbyport(port, protocol);
  if (!entry) {
    LastError = TWinSock::Dll()->WSAGetLastError();
    return WINSOCK_ERROR;
  }
  return WINSOCK_NOERROR;
}

//
// Implements the blocking 'getservbyname()'.
//
// 'entry' is a pointer to a ServiceEntry*. The caller does NOT allocate a
//  ServiceEntry, it will be set by the system.  DO NOT chanage any data in the
//  returned structure.
// The 'name' argument points to string representing the service name, such as
//  "ftp". It is generally case sensitive.
// 'protocol' is the protocol name, but may be passed as 0 to mean default or
//  first found.
// The returned entry has the port in network byte order.
//
int TServiceManager::GetService(TServiceEntry*& entry, const char* name, const char* protocol)
{
  entry = (TServiceEntry*)TWinSock::Dll()->getservbyname(name, protocol);
  if (!entry) {
    LastError = TWinSock::Dll()->WSAGetLastError();
    return WINSOCK_ERROR;
  }
  return WINSOCK_NOERROR;
}

//
// This function is blocking.
// Given an input service in 'name', this function fills in nPort with the
//  port (in network order).
// 'port' is a reference to an int.  If the call retuns OK, then this will be the port
//  in network ordering.
// protocol is the protocol name, but may be passed as 0 to mean default or first found.
//
int TServiceManager::GetServicePort(char* name, int& port, const char* protocol)
{
  TServiceEntry* tempServiceEntry;

  int returnValue = GetService(tempServiceEntry, name, protocol);
  port = tempServiceEntry->s_port; // Note that port is already in host byte order.
  return returnValue;
}

//
// This function is blocking.
// 'name' needs to be big enough to hold the service's name (N_MAX_SERVICE_NAME).
// 'port' must be passed in network byte ordering.
// 'protocol' is the protocol name, but may be passed as 0 to mean default or first found.
//
int TServiceManager::GetServiceName(int port, char* name, const char* protocol)
{
  // Note that because we are calling our own member function, we don't convert
  //  the address from local to network format.
  //
  TServiceEntry* tempServiceEntry;
  int returnValue = GetService(tempServiceEntry, port, protocol);
  if (returnValue == WINSOCK_NOERROR)
    strcpy(name, tempServiceEntry->s_name);
  return returnValue;
}

//
// Cancels an pending service that equals the hService.  Note that if service
// is 0 or unspecified, then this function uses its own current Service.
//
int TServiceManager::CancelServiceRequest(HANDLE hService)
{
  if (!hService)
    hService = LastServiceRequest;
  if (!hService) {
    LastError = WSAEINVAL;
    return WINSOCK_ERROR;
  }

  int tempValue = TWinSock::Dll()->WSACancelAsyncRequest(hService);
  if (tempValue == SOCKET_ERROR) {
    LastError = TWinSock::Dll()->WSAGetLastError();
    return WINSOCK_ERROR;
  }
  OutstandingServiceRequests--;
  return WINSOCK_NOERROR;
}

//
// This call is non-blocking.  It sets up a callback to its own member window.
// hService is a HANDLE reference.  If the call is successful, it will hold the handle for
//  the asynchrous call.  Note that the caller can save the handle, but also that this
//  class stores the handle for itself as well.
// port is passed into this function in network byte ordering.
// Note that due to the design of this class, you cannot have two outstanding Service
//  requests that get notified directly to this class.  You may use the hwnd-specific
//  notification version of this function to manage multiple requests at a time.
//  You may also simply create more than one instance of this class.
// The service is complete when bServiceRequestCompleted is TRUE.  You must look at nLastError in
//  this case to see if there was an error.
//
int TServiceManager::GetServiceAsync(HANDLE& hService, int port, const char* protocol)
{
  LastServiceRequestCompleted = 0;
  hService = LastServiceRequest = TWinSock::Dll()->WSAAsyncGetServByPort(Window, MSG_SERVICE_NOTIFY,
                                         port, protocol, ServiceBuffer, MAXGETHOSTSTRUCT);
  if (!hService) {
    LastError = TWinSock::Dll()->WSAGetLastError();
    return WINSOCK_ERROR;
  }

  OutstandingServiceRequests++;
  return WINSOCK_NOERROR;
}

//
// This call is non-blocking.  It sets up a callback to its own member window.
// 'hService' is a HANDLE reference.  If the call is successful, it will hold the handle for
//  the asynchrous call.  Note that the caller can save the handle, but also that this
//  class stores the handle for itself as well.
// The 'name' argument points to a service name, such as "finger".
// protocol is the protocol name, but may be passed as 0 or not passed at all to mean
//  default or first found.
//
int TServiceManager::GetServiceAsync(HANDLE& hService, char* name, const char* protocol)
{
  LastServiceRequestCompleted=0;
  hService = LastServiceRequest = TWinSock::Dll()->WSAAsyncGetServByName(Window, MSG_SERVICE_NOTIFY,
                                    name, protocol, ServiceBuffer, MAXGETHOSTSTRUCT);
  if (!hService) {
    LastError = TWinSock::Dll()->WSAGetLastError();
    return WINSOCK_ERROR;
  }
  OutstandingServiceRequests++;
  return WINSOCK_NOERROR;
}

//
// This function notifies the given wndNotify about the completion of the request.
// nMessage is the message that the hwndNotify will receive. It defaults to MSG_SERVICE_NOTIFY,
//  which is defined in the TServiceManager's header file.
// The hService will hold a handle that the caller can use to reference the request on call-back.
// port should be passed in network byte ordering.
// The chBuffer is a pointer to buffer that will be filled in with a SERVENT.  Needs to be at least
//  MAXGETHOSTSTRUCT bytes.  If chBuffer is 0 (or not specified), then the TServiceManager's
//  internal buffer will be used.
// protocol is the protocol name, but may be passed as 0 to mean default or first found.
// This class will NOT save the hServcice for itself.
//   wParam will be equal to the hService returned.
//   WSAGETSYNCERROR(lParam)   holds an error, if any (0 is OK).
//   WSAGETSYNCBUFLEN(lParam)  hold actual length of buffer
//
int TServiceManager::GetServiceAsync(TWindow& wndNotify, HANDLE& hService,
                                     int port, const char* protocol,
                                     uint message, char* buffer)
{
  char* bufferToUse = buffer ? buffer : ServiceBuffer;

  LastServiceRequestCompleted=0;
  hService = TWinSock::Dll()->WSAAsyncGetServByPort(wndNotify, message, port,
                                    protocol, bufferToUse, MAXGETHOSTSTRUCT);
  if (!hService) {
    LastError = TWinSock::Dll()->WSAGetLastError();
    return WINSOCK_ERROR;
  }
  return WINSOCK_NOERROR;
}

//
// This function notifies the given wndNotify about the completion of the request.
// nMessage is the message that the hwndNotify will receive. It defaults to MSG_SERVICE_NOTIFY,
//  which is defined in the TServiceManager's header file.
// The hService will hold a handle that the caller can use to reference the request on call-back.
// The chBuffer is a pointer to buffer that will be filled in with a SERVENT.  Needs to be at least
//  MAXGETHOSTSTRUCT bytes.  If chBuffer is 0 (or not specified), then the TServiceManager's
//  internal buffer will be used.
// 'name' is a pointer to a c string service name, such as "ftp".
// 'protocol' is the protocol name, but may be passed as 0 to mean default or first found.
//
// This class will NOT save the 'hService' for itself.
//   wParam will be equal to the hService returned.
//   WSAGETSYNCERROR(lParam)   holds an error, if any (0 is OK).
//   WSAGETSYNCBUFLEN(lParam)  hold actual length of buffer
//
int TServiceManager::GetServiceAsync(TWindow& wndNotify, HANDLE& hService,
                                     char* name, const char* protocol,
                                     uint message, char* buffer)
{
  char* bufferToUse = buffer ? buffer : ServiceBuffer;

  LastServiceRequestCompleted = 0;
  hService = TWinSock::Dll()->WSAAsyncGetServByName(wndNotify, message, name,
                                     protocol, bufferToUse, MAXGETHOSTSTRUCT);
  if (!hService) {
    LastError = TWinSock::Dll()->WSAGetLastError();
    return WINSOCK_ERROR;
  }
  return WINSOCK_NOERROR;
}

//
// This function is called whenever an internal window callback is used for an
//  async call.  When this function is called, the ServiceRequestCompleted member
//  will be true (it got set to true right before this function was called).
//
// You may want to override this function. If you do, you will probably want to
// call this function as part of the subclassed function.
//
void TServiceManager::ServiceCompleted(int error)
{
  if (error == SOCKET_ERROR)
    LastError = error;
  OutstandingServiceRequests--;
  LastServiceRequestCompleted = 1;
}
