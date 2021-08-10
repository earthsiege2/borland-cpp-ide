//----------------------------------------------------------------------------
// ObjectWindows
// Copyright (c) 1995, 1996 by Borland International, All Rights Reserved
//
//$Revision:   10.8  $
//
// Winsock for OWL subsystem.
// Based on work by Paul Pedriana, 70541.3223@compuserve.com
//----------------------------------------------------------------------------
#if !defined(OWL_WSKHOSTM_H)
#define OWL_WSKHOSTM_H

#if !defined(OWL_DEFS_H)
# include <owl/defs.h>
#endif
#if !defined(OWL_WINDOW_H)
# include <owl/window.h>
#endif
#if !defined(OWL_WINSOCK_H)
# include <owl/winsock.h>
#endif

// Generic definitions/compiler options (eg. alignment) preceeding the 
// definition of classes
#include <services/preclass.h>

//
// Forward ref.   
//
class _OWLCLASS TSocketAddress;

#define WINSOCK_NOERROR (int)0
#define WINSOCK_ERROR   (int)SOCKET_ERROR

//
// Supposedly in RFC 883.
//
#define N_MAX_HOST_NAME 128
#define MSG_HOST_INFO_NOTIFY ((UINT)(WM_USER+303))

class _OWLCLASS THostInfoManager;

//
// class THostInfoWindow
// ~~~~~ ~~~~~~~~~~~~~~~
// A private class created by THostInfoManager to catch WinSock messages.
//
class _OWLCLASS THostInfoWindow : public TWindow {
  public:
    THostInfoWindow(THostInfoManager* hostInfoManagerParent);

    TResult DoNotification(TParam1 param1, TParam2 param2);

  public_data:
    // Object to notify of Winsock events
    //
    THostInfoManager* HostInfoManagerParent;

  DECLARE_RESPONSE_TABLE(THostInfoWindow);
};

//
// class THostEntry
// ~~~~~ ~~~~~~~~~~
// Encapsulates the attributes of a host (hostent).
//
class _OWLCLASS THostEntry : public hostent {
  public:
    THostEntry();

    int   GetAddressCount();
    ulong GetINetAddress();

    // An internet addressing -specific function.
    //
    ulong GetNthINetAddress(int nIndex = 0);
};

//
// class THostInfoManager
// ~~~~~ ~~~~~~~~~~~~~~~~
// Encapsulates hostent database functions.
//
class _OWLCLASS THostInfoManager {
  public:
    THostInfoManager();
    virtual ~THostInfoManager();

    int   GetLastError();
    int   GetHostName(char far* name, int nameLength = N_MAX_HOST_NAME);
    int   GetHostAddress(char far* szHostAddress, const char far* szHostName);
    int   GetHostAddress(TSocketAddress& sAddress, const char far* szHostName);
    int   GetHostInfo(THostEntry*& hEntry, const TSocketAddress& sAddress);
    int   GetHostInfo(THostEntry*& hEntry, const char far* szName);
    int   GetHostInfoAsync(HANDLE& hTheHostRequest, TSocketAddress& sAddress);
    int   GetHostInfoAsync(HANDLE& hTheHostRequest, char far* szName);
    int   GetHostInfoAsync(TWindow& wndNotify, HANDLE& hTheHostRequest,
                           TSocketAddress& sAddress, uint nMessage = MSG_HOST_INFO_NOTIFY,
                           char far* chBuffer = 0);
    int   GetHostInfoAsync(TWindow& wndNotify, HANDLE& hTheHostRequest,
                           char far* szName, uint nMessage=MSG_HOST_INFO_NOTIFY,
                           char far* chBuffer = 0);
    int   CancelHostRequest(HANDLE hTheHostRequest = 0);
    short GetHostRequestCompleted();
    static int HostEntryToAddress(THostEntry* hEntry, char far* szAddress);
    static int HostEntryToAddress(THostEntry* hEntry, TSocketAddress& sAddress);

    // Set to point to HostInfoBuffer.
    //
  public_data:
    THostEntry*     HostEntry;

  protected:
    bool            HostRequestCompleted;              // Flag if host completed last request
    HANDLE          HostRequest;                       // Handle of host to get info about
    int             LastError;                         // Last error code
    char            HostInfoBuffer[MAXGETHOSTSTRUCT];  // Used for calls to WSAAsync...()
    THostInfoWindow HostWindow;                        // Hidden window to catch notifications

    void  SetHostRequestCompleted(int error);

  friend class THostInfoWindow;
};

// Generic definitions/compiler options (eg. alignment) following the 
// definition of classes
#include <services/posclass.h>

//----------------------------------------------------------------------------
// Inline implementations
//

//
// Return the Internet address of the host.
//
inline ulong
THostEntry::GetINetAddress()
{
  return GetNthINetAddress(0);
}

//
// Return the last error code.
//
inline int
THostInfoManager::GetLastError()
{
  return LastError;
}

//
// Return true if the host complete the last requested transaction.
//
inline short
THostInfoManager::GetHostRequestCompleted()
{
  return HostRequestCompleted;
}

#endif  // OWL_WSKHOSTM_H
