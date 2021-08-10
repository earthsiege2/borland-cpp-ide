//----------------------------------------------------------------------------
// ObjectWindows
// Copyright (c) 1995, 1996 by Borland International, All Rights Reserved
//
//$Revision:   10.9  $
//
// Winsock for OWL subsystem.
// Based on work by Paul Pedriana, 70541.3223@compuserve.com
//----------------------------------------------------------------------------
#if !defined(OWL_WSKSERVM_H)
#define OWL_WSKSERVM_H

#if !defined(OWL_DEFS_H)
# include <owl/defs.h>
#endif
#if !defined(OWL_WINDOW_H)
# include <owl/window.h>
#endif
#if !defined (_WINSOCKAPI_)
# include <winsock.h>
#endif

// Generic definitions/compiler options (eg. alignment) following the 
// definition of classes
#include <services/posclass.h>

#define WINSOCK_NOERROR (int)0
#define WINSOCK_ERROR   (int)SOCKET_ERROR

//
// Is supposedly in RFC 883.
//
#define N_MAX_SERVICE_NAME 128
#define MSG_SERVICE_NOTIFY ((UINT)(WM_USER+302))

class _OWLCLASS TServiceManager;

//
// class TServiceWindow
// ~~~~~ ~~~~~~~~~~~~~~
// A private class created by the TServiceManager to catch notifications.
//
class _OWLCLASS TServiceWindow : public TWindow {
  public:
    TServiceWindow(TServiceManager* newServiceManagerParent);

  protected: 
    // Object to pass notifications
    //
    TServiceManager* ServiceManagerParent;

    TResult DoNotification(TParam1 param1, TParam2 param2);

  DECLARE_RESPONSE_TABLE(TServiceWindow);
};

//
// class TServiceEntry
// ~~~~~ ~~~~~~~~~~~~~
// Encapsulates information about a service.
//
class _OWLCLASS TServiceEntry : public servent {
  public:
    TServiceEntry();
};

//
// class TServiceManager
// ~~~~~ ~~~~~~~~~~~~~~~
// Encapsulates service database functions.
//
class _OWLCLASS TServiceManager {
  public:
    TServiceManager();
    virtual ~TServiceManager();

    int   GetLastError();
    int   GetLastServiceCompletion();
    int   GetService(TServiceEntry*& sEntry, int nPort, const char* szProtocol = 0);
    int   GetService(TServiceEntry*& sEntry, const char* szName,
                     const char* szProtocol = 0);
    int   GetServicePort(char* szName, int& nPort, const char* szProtocol = 0);
    int   GetServiceName(int nPort, char* szName, const char* szProtocol = 0);
    int   GetServiceAsync(HANDLE& hService, int nPort, const char* szProtocol = 0);
    int   GetServiceAsync(HANDLE& hService, char* szName, const char* szProtocol = 0);
    int   GetServiceAsync(TWindow& wndNotify, HANDLE& hService, int nPort,
                          const char* szProtocol = 0, uint nMessage = MSG_SERVICE_NOTIFY,
                          char* chBuffer = 0);
    int   GetServiceAsync(TWindow& wndNotify, HANDLE& hService, char* szName,
                          const char* szProtocol = 0, uint nMessage = MSG_SERVICE_NOTIFY,
                          char* chBuffer = 0);
    int   CancelServiceRequest(HANDLE hService = 0);
    bool  GetServiceRequestCompleted();

  public_data:
    //Set to point to chServiceBuffer.
    //
    TServiceEntry* ServiceEntry;

  protected:
    int            LastError;                       // Last error code
    int            OutstandingServiceRequests;      // Count of total requests done by myself that haven't completed yet.
    bool           LastServiceRequestCompleted;     // Is the last request done?
    char           ServiceBuffer[MAXGETHOSTSTRUCT]; // Used for calls to WSAAsync...()
    HANDLE         LastServiceRequest;              // Handle of last service request
    TServiceWindow Window;                          // Private window for catching notification

    void ServiceCompleted(int nError);

  friend class TServiceWindow;
};

// Generic definitions/compiler options (eg. alignment) following the 
// definition of classes
#include <services/posclass.h>

//----------------------------------------------------------------------------
// Inline implementations
//

//
// Return the last error code.
//
inline int
TServiceManager::GetLastError()
{
  return LastError;
}

//
// Return the last service completion.
//
inline int
TServiceManager::GetLastServiceCompletion()
{
  return LastServiceRequestCompleted;
}

//
// Return true if the last service requested has been completed.
//
inline bool
TServiceManager::GetServiceRequestCompleted()
{
  return LastServiceRequestCompleted;
}

#endif  // OWL_WSKSERVM_H
