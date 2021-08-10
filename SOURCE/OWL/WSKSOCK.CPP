//----------------------------------------------------------------------------
// ObjectWindows
// Copyright (c) 1995, 1996 by Borland International, All Rights Reserved
//
//$Revision:   10.10  $
//
// Winsock for OWL subsystem.
// Based on work by Paul Pedriana, 70541.3223@compuserve.com
//----------------------------------------------------------------------------
#include <owl/pch.h>
#if !defined(OWL_WINSOCK_H)
# include <owl/winsock.h>
#endif

//
// default constructor for a socket.  You can set the individual members of
// the TSocket later.
//
TSocket::TSocket()
:
  Window(this),
  Family(PF_UNSPEC),
  Type(0),
  Protocol(0),
  MaxReadBufferSize(N_DEF_MAX_READ_BUFFFER_SIZE),
  Bound(false),
  SaveSocket(0),
  Handle(INVALID_SOCKET)
{
  Init();
}

//
// TSocket(SOCKET&) is a constructor based on a Winsock SOCKET descriptor.
//
TSocket::TSocket(SOCKET& newS)
:
  Window(this),
  MaxReadBufferSize(N_DEF_MAX_READ_BUFFFER_SIZE),
  Bound(false),
  SaveSocket(0),
  Handle(newS)
{
  int temp;
  GetMyAddress(SocketAddress, temp, Handle); // Fills in our address information.
  Family = SocketAddress.sa_family;
  GetPeerAddress(SocketAddress, temp, Handle); // Fills in out Peer's address info if it exists.
  Init();
}

//
// This is the standard constructor for a TSocket.  It doesn't call socket() nor bind().  You must
//  do those independently.
//
TSocket::TSocket(TSocketAddress& newSocketAddress, int newFamily, int newType, int newProtocol)
:
  Window(this),
  SocketAddress(newSocketAddress),
  Family(newFamily),
  Type(newType),
  Protocol(newProtocol),
  MaxReadBufferSize(N_DEF_MAX_READ_BUFFFER_SIZE),
  Bound(false),
  SaveSocket(0),
  Handle(INVALID_SOCKET)
{
  Init();
}

//
// This TSocket destructor will close the socket it if has not be closed already.
// It will also delete the friend notification window as well.
//
TSocket::~TSocket()
{
  if (Handle != INVALID_SOCKET && !SaveSocket) {
    SetLingerOption(0, 60); //Don't wait till data gets sent.  Just kill the socket now.
    CloseSocket();
  }
}

//
// This function is an intitialization function called by the TSocket constructors.  It
//  simply creates the friend window that the TSocket needs for Winsock notifications.
//
void TSocket::Init()
{
  // This is for initialization steps that are common to all constructors.
  //
  LastError = 0;
  try {
     Window.Create();
  }
  catch (...) {
    //::MessageBox();
  }
}

//
// Check the return error value from a sockets call, caching the last error
// if one occured, i.e error is non-zero. Return a Winsock error/noerror code.
//
int TSocket::SocketsCallCheck(int error)
{
  if (error) {
    LastError = TWinSock::Dll()->WSAGetLastError();
    return WINSOCK_ERROR;
  }
  return WINSOCK_NOERROR;
}

//
// Does a deep copy of the TSocket, as much as possible.
//
TSocket& TSocket::operator =(TSocket& newSocket)
{
  Family            = newSocket.Family;
  Type              = newSocket.Type;
  Protocol          = newSocket.Protocol;
  LastError         = newSocket.LastError;
  Handle            = newSocket.Handle;
  SocketAddress     = newSocket.SocketAddress;
  PeerSocketAddress = newSocket.PeerSocketAddress;
  SaveSocket        = newSocket.SaveSocket;

  // Copy the friend (helper) window.  Note that there is an operator= defined
  //  for the class TSocketWindow.  However, the TSocketWindow::operator= will
  //  set its 'SocketParent' member to be the newSocket SocketWindow's previous
  //  TSocket parent, which may not be us.  Thus, after setting 'Window =
  //  newSocket.Window;', we set 'Window.SocketParent = this;'.
  //
  Window              = newSocket.Window;
  Window.SocketParent = this;

  return *this;
}

//
// While it is possible that two sockets could refer to the same SOCKET (though
//  this would likely create a mess if not governed with care), it is defined as
//  not possible that two Sockets could lhave the same window member.  THis is
//  because the window is created uniquely on construction for each TSocket.
//
bool operator ==(const TSocket& socket1, const TSocket& socket2)
{
  return socket1.Handle == socket2.Handle && socket1.Window == socket2.Window;
}

//
// See SocketWindow::StartAcceptNotification() for documentation
//
int TSocket::StartAcceptNotification()
{
  int error = Window.StartAcceptNotification();
  if (error == WINSOCK_ERROR) {
    LastError = Window.GetLastError();
  }
  return error;
}

//
// See TSocketWindow::StartRegularNotification() for documentation
//
int TSocket::StartRegularNotification()
{
  int error = Window.StartRegularNotification();
  if (error == WINSOCK_ERROR) {
    LastError = Window.GetLastError();
  }
  return error;
}

//
//
//
int TSocket::StartCustomNotification(int selectionOptions)
{
  int error = Window.StartCustomNotification(selectionOptions);
  if (error == WINSOCK_ERROR) {
    LastError = Window.GetLastError();
  }
  return error;
}

//
// See SocketWindow::CancelNotification() for documentation
//
int TSocket::CancelNotification()
{
  int error = Window.CancelNotification();
  if (error == WINSOCK_ERROR) {
    LastError = Window.GetLastError();
  }
  return error;
}

//
// The SetSocketStyle function can be used to set or change some TSocket member data.
// Note that the newFamily is also represented in the TSocketAddress member, thus they
//  should match.
//
void TSocket::SetSocketStyle(int newFamily, int newType, int newProtocol)
{
  Family   = newFamily;
  Type     = newType;
  Protocol = newProtocol;
}

//
// Converts a string protocol to integer value.
// Makes assumptions about the protocol string.
// Only "tcp" and udp return valid values.
//
int TSocket::ConvertProtocol(char* protocol)
{
  if (!protocol)
    return IPPROTO_TCP;
  if (strcmp("tcp", protocol) == 0)
    return IPPROTO_TCP;
  if(strcmp("udp", protocol) == 0)
    return IPPROTO_UDP;
  return IPPROTO_IP;
}

//
// The CreateSocket function is much like the Winsock socket() function.
// This function assumes that nFamily, nType, and nProtocol are already set properly.
// Note also that since the return of socket() is assigned to 's', that 's' must not
//  be alredy used.  This is another way of saying that there can only be one
//  SOCKET for each TSocket object.
//
int TSocket::CreateSocket()
{
  Handle = TWinSock::Dll()->socket(Family, Type, Protocol);
  return SocketsCallCheck(Handle == INVALID_SOCKET);
}

//
// The CloseSocket() function is much like the Winsock closesocket() function.
//
int TSocket::CloseSocket()
{
  if (Handle != INVALID_SOCKET) {
    int error = TWinSock::Dll()->closesocket(Handle);
    if (error) {
      LastError = TWinSock::Dll()->WSAGetLastError();
      return WINSOCK_ERROR;
    }
  }
  Handle = INVALID_SOCKET;  // It's invalid now.
  Bound = false;
  return WINSOCK_NOERROR;
}

//
// The ShutDownSocket() function is much like the Winsock shutdown() function.
// It is important to note that shutting down a socket essentially means that
//  you can't un-shut it down.  It is like a graceful way of preparing to
//  end a session.  It is somewhat like a yellow stoplight.
//
//  You would want to use this function to close your socket, while still allowing data
//  be received from the network.  This is as opposed to CloseSocket(), which kills
//  all transfers in both directions.
//
//  shutMode is one of the enumerations: ShutModeNoRecv, ShutModeNoSend, or ShutModeNoRecvSend.
int TSocket::ShutDownSocket(TShutMode shutMode)
{
  if (Handle != INVALID_SOCKET) {
    int error = TWinSock::Dll()->shutdown(Handle, shutMode);
    if (error) {
      LastError = TWinSock::Dll()->WSAGetLastError();
      return WINSOCK_ERROR;
    }
    Handle = INVALID_SOCKET;  // It's invalid now.
    Bound = false;
  }
  return WINSOCK_NOERROR;
}

//
// BindSocket is much like the Winsock bind() function.
// Regardless of what mySocketAddress may have been previously, a call to 'bind()'
//  immediately makes the socket's address the one put into the bind() call.
//  Thus we simply always assign mySocketAddress to be boundSocketAddress.
// The address argument must be in network byte ordering. On the other hand, the
//  SocketAddress class always keeps is addresses in network byte ordering.
//
int TSocket::BindSocket(TSocketAddress& addressToBindTo)
{
  SocketAddress = addressToBindTo;

  // bind() ideally returns 0.
  //
  if (TWinSock::Dll()->bind(Handle, &SocketAddress, sizeof(sockaddr))) {
    LastError = TWinSock::Dll()->WSAGetLastError();
    return WINSOCK_ERROR;
  }
  Bound = true;
  return WINSOCK_NOERROR;
}

//
// This BindSocket simply binds with our previously defined member data socket
// address.
//
int TSocket::BindSocket()
{
  return BindSocket(SocketAddress);
}

//
// This function stores the address into the reference argument 'socketAddress'.
// 'addressLength' will hold the length of the address.
// 'socket' refers to the socket who's address wil be examined.
//
int TSocket::GetMyAddress(TSocketAddress& socketAddress, int& addressLength, SOCKET& socket)
{
  return SocketsCallCheck(!TWinSock::Dll()->getsockname(socket, &socketAddress, &addressLength));
}

//
// This function stores the address into the reference argument 'socketAddress'.
// 'addressLength' will hold the length of the address.
// Uses the SOCKET in my member data as the socket to get the address of.
//
int TSocket::GetMyAddress(TSocketAddress& socketAddress, int& addressLength)
{
  return GetMyAddress(socketAddress, addressLength, Handle);
}

//
//The GetPeerAddress() function is much like the Winsock getpeername() function.
//  The Winsock getpeername() function is misnamed; it should be getpeeraddress().
//socketAddress will be changed to have the right addressing info, and nAddressLength
//  will be set to be the address length.
//Note that this function can be used to get the address for any socket descriptor,
//  not just our own socket descriptor.
//
int TSocket::GetPeerAddress(TSocketAddress& socketAddress, int& addressLength, SOCKET& socket)
{
  // This code only works because SOCKET is defined as a uint and not a struct
  //
  if (!socket)
    socket = Handle;

  return SocketsCallCheck(!TWinSock::Dll()->getpeername(socket, &socketAddress, &addressLength));
}

//
// This version of GetPeerAddress() works on our own socket descriptor.
//
int TSocket::GetPeerAddress(TSocketAddress& socketAddress, int& addressLength)
{
  return GetPeerAddress(socketAddress, addressLength, Handle);
}

//
// This may be useful for changing the address or setting the address before
//  binding.  It's no good to change this after binding, as a binding is a
//  permanent association between a socket descriptor and a full address (for
//  IP, this is a ushort port and ulong address).
//
void TSocket::SetMyAddress(TSocketAddress& newSocketAddress)
{
  SocketAddress = newSocketAddress;
}

//
// The 'myPeerSocketAddress' member variable is useful for Datagram sockets because it
//  allows them to specify a default destination to send datagrams to.  With a default
//  destination, a datagram socket that always or often sends to one address can simply call
//  the Write() or Send() functions with no address arguments and the data will send
//  to the default address.
// This function can also be used by a stream socket to set the address for a peer
//  that it wants to connect to.
//
void TSocket::SetPeerSocketAddress(TSocketAddress& newPeerSocketAddress)
{
  PeerSocketAddress = newPeerSocketAddress;
}

//
// GetDriverWaitingSize() is much like calling ioctlsocket(s, FIONREAD,...) in Winsock.
// It returns the number of bytes waiting to be read on our socket.
// For datagrams, it is the size of the next datagram.
// For streams, it "should" be the total waiting bytes.
//
ulong TSocket::GetDriverWaitingSize()
{
  ulong charsWaiting;
  if (TWinSock::Dll()->ioctlsocket(Handle, FIONREAD, &charsWaiting)) {
    return 0;
  }
  return charsWaiting;
}

//
// Returns the total number of bytes waiting to be read.
//
ulong TSocket::GetTotalWaitingSize()
{
  return GetDriverWaitingSize();
}

//
// This function gets called whenever the socket gets a read notification.  This means
//  that data on the port is ready to be read.
// Thus this function must be subclassed by a DatagramSocket and StreamSocket.
//
TSocket::DoReadNotification(const SOCKET& /*socket*/, int /*nError*/)
{
  return 0;
}

//
// The generic socket doesn't know how many bytes it can send, since this limit
//  is dependent on whether the socket is a stream or datagram socket.
// Thus this function must be subclassed by a DatagramSocket and StreamSocket.
//
TSocket::DoWriteNotification(const SOCKET& /*s*/, int /*nError*/)
{
  return 0;
}

//
// We don't respond to this in the generic TSocket class.
//
TSocket::DoOOBNotification(const SOCKET& /*s*/, int /*nError*/)
{
  return 0;
}

//
// We don't respond to this in the generic TSocket class.
//
TSocket::DoAcceptNotification(const SOCKET& /*s*/, int /*nError*/)
{
  return 0;
}

//
// We don't respond to this in the generic TSocket class.
//
TSocket::DoConnectNotification(const SOCKET& /*s*/, int /*nError*/)
{
  return 0;
}

//
// We don't respond to this in the generic TSocket class.
//
TSocket::DoCloseNotification(const SOCKET& /*s*/, int /*nError*/)
{
  return 0;
}

//
// This should be called by someone that knows what the correct value is.
//
void TSocket::SetMaxReadBufferSize(int maxReadBufferSize)
{
  if(maxReadBufferSize > 0)
    MaxReadBufferSize = maxReadBufferSize;
}

//
// Allow transmission of broadcast messages.
//
int TSocket::SetBroadcastOption(bool broadcast)
{
  return SocketsCallCheck(TWinSock::Dll()->setsockopt(Handle, SOL_SOCKET, SO_BROADCAST, (char*)&broadcast, sizeof broadcast));
}

//
// Record debugging info.
//
int TSocket::SetDebugOption(bool debug)
{
  return SocketsCallCheck(TWinSock::Dll()->setsockopt(Handle, SOL_SOCKET, SO_DEBUG, (char*)&debug, sizeof debug));
}

//
// If you set 'linger' to true, then that means to linger for 'lingerTime' seconds.
// Examples:
//   linger=true, lingerTime=0   Hard immediate close. All queued data for sending gets canned immediately.
//   linger=true, lingerTime=2.  Graceful close, waits 2 seconds to try to send any pending data.
//   linger=false, lingerTime=<any>. "Graceful" immediate close, causes data to still be in queue to send when ready.
//
int TSocket::SetLingerOption(bool linger, ushort lingerTime)
{
  LINGER lingerOptions;

  lingerOptions.l_onoff = linger;  //Note that bLinger is a bool and LINGER.l_onoff is a u_short.
  lingerOptions.l_linger = lingerTime;

  return SocketsCallCheck(TWinSock::Dll()->setsockopt(Handle, SOL_SOCKET, SO_LINGER, (char*)&lingerOptions, sizeof lingerOptions));
}

//
// A false argument means don't route.
//
int TSocket::SetRouteOption(bool route)
{
  route = !route;
  return SocketsCallCheck(TWinSock::Dll()->setsockopt(Handle, SOL_SOCKET, SO_DONTROUTE, (char*)&route, sizeof route));
}

//
// Send keepAlive messages.
//
int TSocket::SetKeepAliveOption(bool keepAlive)
{
  return SocketsCallCheck(TWinSock::Dll()->setsockopt(Handle, SOL_SOCKET, SO_KEEPALIVE, (char*)&keepAlive, sizeof keepAlive));
}

//
// Receive out of band data in the normal data stream.
//
int TSocket::SetOOBOption(bool sendOOBDataInline)
{
  return SocketsCallCheck(TWinSock::Dll()->setsockopt(Handle, SOL_SOCKET, SO_OOBINLINE, (char*)&sendOOBDataInline, sizeof sendOOBDataInline));
}

//
// Set the buffer size for receiving messages.
//
int TSocket::SetReceiveBufferOption(int receiveBufferSize)
{
  return SocketsCallCheck(TWinSock::Dll()->setsockopt(Handle, SOL_SOCKET, SO_RCVBUF, (char*)&receiveBufferSize, sizeof receiveBufferSize));
}

//
// Set the buffer size for sending messages.
//
int TSocket::SetSendBufferOption(int sendBufferSize)
{
  return SocketsCallCheck(TWinSock::Dll()->setsockopt(Handle, SOL_SOCKET, SO_SNDBUF, (char*)&sendBufferSize, sizeof sendBufferSize));
}

//
// Allow socket to bind to an already bound address
//
int TSocket::SetReuseAddressOption(bool allowReuseAddress)
{
  return SocketsCallCheck(TWinSock::Dll()->setsockopt(Handle, SOL_SOCKET, SO_REUSEADDR, (char*)&allowReuseAddress, sizeof allowReuseAddress));
}

//
// Retrieve the current broadcast option.
//
int TSocket::GetBroadcastOption(bool& broadcast)
{
  int size = sizeof broadcast;
  return SocketsCallCheck(TWinSock::Dll()->getsockopt(Handle, SOL_SOCKET, SO_BROADCAST, (char*)&broadcast, &size));
}

//
// Retrieve the current debugging option.
//
int TSocket::GetDebugOption(bool& debug)
{
  int size = sizeof debug;
  return SocketsCallCheck(TWinSock::Dll()->getsockopt(Handle, SOL_SOCKET, SO_DEBUG, (char*)&debug, &size));
}

//
// Retreive the current linger option.
//
int TSocket::GetLingerOption(bool& linger, ushort& lingerTime)
{
  LINGER lingerOptions;
  int size = sizeof lingerOptions;

  if (SocketsCallCheck(TWinSock::Dll()->getsockopt(Handle, SOL_SOCKET, SO_LINGER, (char*)&lingerOptions, &size)) == WINSOCK_NOERROR) {
    linger = lingerOptions.l_onoff;
    lingerTime = lingerOptions.l_linger;
    return WINSOCK_NOERROR;
  }
  return WINSOCK_ERROR;
}

//
// Retrieve the routing option.
//
int TSocket::GetRouteOption(bool& route)
{
  int size = sizeof route;
  if (SocketsCallCheck(TWinSock::Dll()->getsockopt(Handle, SOL_SOCKET, SO_DONTROUTE, (char*)&route, &size)) == WINSOCK_NOERROR) {
    // route value of true means "don't route."  So we change it to mean what
    // you'd think.
    //
    route = !route;
    return WINSOCK_NOERROR;
  }
  return WINSOCK_ERROR;
}

//
// Retrieve the keepAlive option.
//
int TSocket::GetKeepAliveOption(bool& keepAlive)
{
  int size = sizeof keepAlive;
  return SocketsCallCheck(TWinSock::Dll()->getsockopt(Handle, SOL_SOCKET, SO_KEEPALIVE, (char*)&keepAlive, &size));
}

//
// Retrieve the out-of-band option.
//
int TSocket::GetOOBOption(bool& sendOOBDataInline)
{
  int size = sizeof sendOOBDataInline;
  return SocketsCallCheck(TWinSock::Dll()->getsockopt(Handle, SOL_SOCKET, SO_OOBINLINE, (char*)&sendOOBDataInline, &size));
}

//
// Retrieve the current receiving buffer size.
//
int TSocket::GetReceiveBufferOption(int& receiveBufferSize)
{
  int size = sizeof receiveBufferSize;
  return SocketsCallCheck(TWinSock::Dll()->getsockopt(Handle, SOL_SOCKET, SO_RCVBUF, (char*)&receiveBufferSize, &size));
}

//
// Retrieve the current sending buffer size.
//
int TSocket::GetSendBufferOption(int& sendBufferSize)
{
  int size = sizeof sendBufferSize;
  return SocketsCallCheck(TWinSock::Dll()->getsockopt(Handle, SOL_SOCKET, SO_SNDBUF, (char*)&sendBufferSize, &size));
}

//
// Retrieve the reusable address option.
//
int TSocket::GetReuseAddressOption(bool& allowReuseAddress)
{
  int size = sizeof allowReuseAddress;
  return SocketsCallCheck(TWinSock::Dll()->getsockopt(Handle, SOL_SOCKET, SO_REUSEADDR, (char*)&allowReuseAddress, &size));
}

//----------------------------------------------------------------------------

//
//
//
DEFINE_RESPONSE_TABLE1(TSocketWindow, TWindow)
  EV_MESSAGE(MSG_SOCKET_NOTIFY, DoNotification),
END_RESPONSE_TABLE;

//
// Default this to be our standard MSG_SOCKET_NOTIFY
//
uint TSocketWindow::MsgSocketNotification = MSG_SOCKET_NOTIFY;

TSocketWindow::TSocketWindow(TSocket* socketParent)
:
  TWindow(0, "TSocketWindow"),
  SelectOptions(0),
  NotificationSet(NotifyAll),
  WindowNotification(0),
  SocketParent(socketParent)
{
  Attr.Style = 0;  // Turn off WS_CHILD (the default) style.
}

//
// From the user's standpoint, the only thing that is required to make two SocketWindows
//  act as equal is to make their parents and selection options the same.  The actual
//  window handle identities are unimportant.  Thus, we keep our original Window handle,
//  even if the newSocketWindow had an empty window handle.
//
// However, it may be impossible to assign the parent correctly if this operator is being called
//  in the parent's operator=().  The new parent SHOULD be the original parent, yet the
//  newSocketWindow has a new parent.  We cannot know in this function the conditions
//  under which this assignment is called, so we blindly copy the new parent.
//  The parent will have to override this assignment if the old parent is to
//  remain as it was.
//
// This function does the best it can to make this window act just like newSocketWindow:
//
TSocketWindow& TSocketWindow::operator =(TSocketWindow& src)
{
  SelectOptions      = src.SelectOptions;
  SocketParent       = src.SocketParent;
  WindowNotification = src.WindowNotification;
  NotificationSet    = src.NotificationSet;

  if (SocketParent->Handle) {
    // Note that if SelectOptions were empty (0), then we are saying to turn
    //  off notifications and make the socket blocking.
    //
    TWinSock::Dll()->WSAAsyncSelect(SocketParent->Handle, *this, MSG_SOCKET_NOTIFY, SelectOptions);
  }
  return *this;
}

//
// This function says to only listen to FD_ACCEPT messages.  It is important to note that a
//  socket set up to be a listening socket will never be a connected socket, and a connected
//  socket will never receive FD_ACCEPT messages.  Thus all stream sockets are implicitly either
//  connected sockets or listening sockets.
//
// Since the accepted socket will want to have a different notification window than the
//  listening socket, and the sockets specification says that an accepted socket
//  inherits the notification properties of the listening socket, it is imperative
//  that the listening socket not be set to receive FD_READ, etc notifications.  This
//  is because it is possible that between the accept() call for the new socket and
//  the WSAAsyncSelect() call for the new socket, data may be received for the new socket.
//  Thus the listening socket may get sent the message and it would never get routed to
//  the new socket.
//
// Calling this function is saying that this SocketWindow is for listening for connections.
//
// The return value is WINSOCK_ERROR or WINSOCK_NOERROR.  You can then examine GetLastError().
//
int TSocketWindow::StartAcceptNotification()
{
  SelectOptions = FD_ACCEPT;
  return StartCustomNotification(SelectOptions);
}

//
// This function turns on all Winsock notifications except FD_ACCEPT.
//
// Calling this function is saying that this SocketWindow is for connections rather
// than for listening.  Since a Winsock socket cannot be a listening socket and
// a connected socket at the same time, we have serarate the notification functions
// from each other: StartAcceptNotification() and StartRegularNotification().
//
// The return value is WINSOCK_ERROR or WINSOCK_NOERROR.  You can then examine
// GetLastError().
//
int TSocketWindow::StartRegularNotification()
{
  SelectOptions = FD_ALL & ~FD_ACCEPT;
  return StartCustomNotification(SelectOptions);
}

//
// The return value is WINSOCK_ERROR or WINSOCK_NOERROR.  You can then examine
// GetLastError().
//
int TSocketWindow::StartCustomNotification(int selectOptions)
{
  SelectOptions = selectOptions;

  int error = TWinSock::Dll()->WSAAsyncSelect(*SocketParent, *this, MSG_SOCKET_NOTIFY, SelectOptions);
  if (error) {
    LastError = TWinSock::Dll()->WSAGetLastError();
    return WINSOCK_ERROR;
  }
  return WINSOCK_NOERROR;
}

//
// CancelNotification() turns off the notification to this window. This also changes the
//  socket to be blocking.
// The return value is WINSOCK_ERROR or WINSOCK_NOERROR.  You can then examine GetLastError().
//
int TSocketWindow::CancelNotification()
{
  SelectOptions = 0;
  return StartCustomNotification(SelectOptions);
}

//
// DoNotification() is the SocketWindow's protected internal notification system.
//
TResult TSocketWindow::DoNotification(TParam1 param1, TParam2 param2)
{
  SOCKET& socket = param1;
  int     error   = (int)WSAGETSELECTERROR(param2);

  if (socket != SocketParent->Handle)
    return 0;

  switch (WSAGETSELECTEVENT(param2)) {
    case FD_READ:
      if (WindowNotification && (NotificationSet & NotifyRead)) {
        return WindowNotification->SendMessage(MsgSocketNotification, param1, param2);
      }
      SocketParent->DoReadNotification(socket, error);
      break;
    case FD_WRITE:
      if (WindowNotification && (NotificationSet & NotifyWrite)) {
        return WindowNotification->SendMessage(MsgSocketNotification, param1, param2);
      }
      SocketParent->DoWriteNotification(socket, error);
      break;
    case FD_OOB:
      if (WindowNotification && (NotificationSet & NotifyOOB)) {
        return WindowNotification->SendMessage(MsgSocketNotification, param1, param2);
      }
      SocketParent->DoOOBNotification(socket, error);
      break;
    case FD_ACCEPT:
      if (WindowNotification && (NotificationSet & NotifyAccept)) {
        return WindowNotification->SendMessage(MsgSocketNotification, param1, param2);
      }
      SocketParent->DoAcceptNotification(socket, error);
      break;
    case FD_CONNECT:
      if (WindowNotification && (NotificationSet & NotifyConnect)) {
        return WindowNotification->SendMessage(MsgSocketNotification, param1, param2);
      }
      SocketParent->DoConnectNotification(socket, error);
      break;
    case FD_CLOSE:
      if (WindowNotification && (NotificationSet & NotifyClose)) {
        return WindowNotification->SendMessage(MsgSocketNotification, param1, param2);
      }
      SocketParent->DoCloseNotification(socket, error);
  }
  return 1;
}
