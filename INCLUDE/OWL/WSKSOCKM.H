//----------------------------------------------------------------------------
// ObjectWindows
// Copyright (c) 1995, 1996 by Borland International, All Rights Reserved
//
//$Revision:   10.11  $
//
// Winsock for OWL subsystem.
// Based on work by Paul Pedriana, 70541.3223@compuserve.com
//----------------------------------------------------------------------------
#if !defined(OWL_WSKSOCKM_H)
#define OWL_WSKSOCKM_H

#if !defined(OWL_DEFS_H)
# include <owl/defs.h>
#endif
#if !defined (_WINSOCKAPI_)
# include <winsock.h>
#endif

// Generic definitions/compiler options (eg. alignment) preceeding the 
// definition of classes
#include <services/preclass.h>

//
// class TSocketInfo
// ~~~~~ ~~~~~~~~~~~
// TSocketInfo encapsulates the structure that contains details of the
// Windows Socket implementation. For example, it contains the version
// of the Windows Socket specification implemented, the maximum number of
// sockets that a single process can open etc. etc.
//
class _OWLCLASS TSocketInfo : public WSAData {
  public:
    TSocketInfo();
};

//
// class TSocketManager
// ~~~~~ ~~~~~~~~~~~~~~
// A class that starts up WinSock and provides information about
// the system's WinSock.
//
class _OWLCLASS TSocketManager {
  public:
    TSocketManager(short versionMajor = 1, short versionMinor = 1,
                   bool autoStartup = true);
    virtual ~TSocketManager();

    void Init(short versionMajor = 1, short versionMinor = 1);

    int Startup();
    int ShutDown();

    int       IsAvailable();
    int       GetMajorVersion();
    int       GetMinorVersion();
    char*     GetDescription();
    char*     GetSystemStatus();
    ushort    GetMaxUdpDgAvailable();
    ushort    GetMaxSocketsAvailable();
    char far* GetVendorInfo();
    int       GetLastError();
    void      Information(TSocketInfo& socketInfo);

  protected:
    int          LastError;      // Last error code
    short        Available;      // Flag for Winsock availability
    short        StartupCount;   // Make sure to not overflow number of connects
    TSocketInfo  SocketInfo;     // Information about this WinSocket implementation
    short        VersionMajor;   // Major verion number
    short        VersionMinor;   // Minor verion number
};

// Generic definitions/compiler options (eg. alignment) following the 
// definition of classes
#include <services/posclass.h>

//----------------------------------------------------------------------------
// Inline implementations
//

//
// Return true if WinSock is available.
//
inline int
TSocketManager::IsAvailable()
{
  return Available;
}

//
// Return the major version of WinSock support.
//
inline int
TSocketManager::GetMajorVersion()
{
  return VersionMajor;
}

//
// Return the minor version of WinSock support.
//
inline int
TSocketManager::GetMinorVersion()
{
  return VersionMinor;
}

//
// Return the system's description of WinSock.
//
inline char*
TSocketManager::GetDescription()
{
  return SocketInfo.szDescription;
}

//
// Return the status of WinSock.
//
inline char*
TSocketManager::GetSystemStatus()
{
  return SocketInfo.szSystemStatus;
}

//
// Return maximum number of bytes each UDP packet can be.
//
inline ushort
TSocketManager::GetMaxUdpDgAvailable()
{
  return SocketInfo.iMaxUdpDg;
}

//
// Return maximum number of WinSock connections avaialble.
//
inline ushort
TSocketManager::GetMaxSocketsAvailable()
{
  return SocketInfo.iMaxSockets;
}

//
// Return this Winsocket's vendor's information.
//
inline char far*
TSocketManager::GetVendorInfo()
{
  return SocketInfo.lpVendorInfo;
}

//
// Return the last error code.
//
inline int
TSocketManager::GetLastError()
{
  return LastError;
}

//
// Set the information about this WinSocket.
//
inline void
TSocketManager::Information(TSocketInfo& socketInfo)
{
  socketInfo = SocketInfo;
}


#endif  // OWL_SOCKMGR_H
