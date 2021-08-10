//----------------------------------------------------------------------------
// ObjectWindows
// Copyright (c) 1995, 1997 by Borland International, All Rights Reserved
//
//$Revision:   10.10  $
//
// Winsock for OWL subsystem.
// Based on work by Paul Pedriana, 70541.3223@compuserve.com
//----------------------------------------------------------------------------
#if !defined(OWL_WSKSOCKD_H)
#define OWL_WSKSOCKD_H

#if !defined(OWL_WINSOCK_H)
# include <owl/wsksock.h>
#endif

#if defined(BI_NAMESPACE)
namespace OWL {
#endif

// Generic definitions/compiler options (eg. alignment) preceeding the 
// definition of classes
#include <services/preclass.h>

//
// class TDatagramSocket
// ~~~~~ ~~~~~~~~~~~~~~~
// TDatagramSocket encapsulates a Winsock datagram socket.
// NOTE: Unlike stream sockets, datagram sockets are unreliable - i.e. the 
//       bi-directional flow of data is not guaranteed to be sequenced and/or 
//       unduplicated.
//
class _OWLCLASS TDatagramSocket : public TSocket {
  public:
    TDatagramSocket();
    TDatagramSocket(SOCKET& newS);
    TDatagramSocket(TSocketAddress& newSocketAddress, int addressFormat = PF_INET,
                    int type = SOCK_DGRAM, int protocol = 0);
    TDatagramSocket& operator =(TDatagramSocket& newDatagramSocket1);

    void SetMaxPacketSendSize(int size);
    int Read(char* data, int& charsToRead, TSocketAddress& sAddress);
    int Write(char* data, int& charsToWrite, TSocketAddress& outSocketAddress,
              bool becomeOwnerOfData = true, bool copyData = true);
    int Write(char* data, int& charsToWrite, bool becomeOwnerOfData = true,
              bool copyData = true);

  protected:
    //Defined by the WSAStartup() call return information (WSAData).
    //
    static int MaxPacketSendSize;

    DoReadNotification(const SOCKET& s, int error);
    DoWriteNotification(const SOCKET& s, int error);
};

#define N_DEF_MAX_QUEUED_CONNECTIONS 5

//
// class TStreamSocket
// ~~~~~ ~~~~~~~~~~~~~
// The StreamSocket encapsulates a Winsock stream socket.
//
class _OWLCLASS TStreamSocket : public TSocket {
  public:
    // Current status of this stream socket
    //
    enum TConnectStatus {
      NotConnected,       // This socket is not used
      ConnectPending,     // Connection is pending
      Connected,          // Currently connected
      Listening           // Waiting for a connection
    } ConnectStatus;

    TStreamSocket();
    TStreamSocket(SOCKET& newS);
    TStreamSocket(TSocketAddress& socketAddress, int addressFormat = PF_INET,
                  int Type = SOCK_STREAM, int protocol = 0);
    TStreamSocket& operator =(TStreamSocket& src);

    int Listen(int nMaxQueuedConnections = N_DEF_MAX_QUEUED_CONNECTIONS);
    int Connect();
    int Connect(TSocketAddress& addressToConnectTo);
    int Accept(TStreamSocket& socket);
    int Accept(SOCKET& socket, sockaddr& sAddress);

    int Read(char* data, int& charsToRead);
    int Write(char* data, int& charsToWrite, int flags = 0,
              bool becomeOwnerOfData = true, bool copyData = true);
              //Is the same as send func
    int ReadOOB(char* data, int& charsToRead);
    int WriteOOB(char* data, int& charsToWrite, int nFlags = MSG_OOB,
                 bool becomeOwnerOfData = true, bool copyData = true);
                 //ORs nFlags w MSG_OOB.

  protected:
    DoReadNotification(const SOCKET& s, int nError);
    DoWriteNotification(const SOCKET& s, int nError);
    DoOOBNotification(const SOCKET& s, int nError);
    DoAcceptNotification(const SOCKET& s, int nError);
    DoConnectNotification(const SOCKET& s, int nError);
    DoCloseNotification(const SOCKET& s, int nError);
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
// Copies the datagram socket connection information.
//
inline TDatagramSocket&
TDatagramSocket::operator =(TDatagramSocket& newDatagramSocket1)
{
  TSocket::operator =(newDatagramSocket1);
  return *this;
}

//
// Set the maximum size of the send packet buffer.
//
inline void
TDatagramSocket::SetMaxPacketSendSize(int size)
{
  MaxPacketSendSize = size;
}

#endif  // OWL_WSKSOCKD_H
