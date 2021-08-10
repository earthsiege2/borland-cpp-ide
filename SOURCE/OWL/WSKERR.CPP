//----------------------------------------------------------------------------
// ObjectWindows
// Copyright (c) 1995, 1997 by Borland International, All Rights Reserved
//
//$Revision:   10.17  $
//
// Winsock for OWL subsystem.
// Based on work by Paul Pedriana, 70541.3223@compuserve.com
//----------------------------------------------------------------------------
#include <owl/pch.h>
#if !defined(OWL_MODULE_H)
# include <owl/module.h>
#endif
#if !defined(OWL_WINSOCK_H)
# include <owl/winsock.h>
#endif
#if !defined(OWL_WINSOCK_RH)
# include <owl/winsock.rh>
#endif
#include <stdio.h>

OWL_DIAGINFO;

extern HINSTANCE _hInstance;   //Defined by startup code for windows programs.

//
// Construct with the error code and the size of the buffer to allocate.
//
TSocketError::TSocketError(int error, int sizeToAllocate)
:
  Error(error),
  String(0),
  SizeToAllocate(sizeToAllocate)
{
  GetErrorString();
}

//
// Destroy the allocated string.
//
TSocketError::~TSocketError()
{
  delete[] String;
}

//
// Copies the error code and string.
//
TSocketError& TSocketError::operator =(const TSocketError& src)
{
  Error = src.Error;

  delete[] String;
  String = strnewdup(src.String);

  return *this;
}

#if defined(BI_NAMESPACE)
namespace OWL {
#endif

//
// The important criteria for determining equality is the error value.  The
//  string is unimportant.
//
bool operator ==(const TSocketError& socketError1,
                 const TSocketError& socketError2)
{
  return socketError1.Error == socketError2.Error;
}

#if defined(BI_NAMESPACE)
} // namespace OWL
#endif

//
// Initialize the error code.
//
void TSocketError::Init(int error)
{
  Error = error;
  GetErrorString();
}

//
// Return the error code.
//
int TSocketError::GetReasonValue() const
{
  return Error;
}

//
// This function simply hands the pointer to the string to the caller.
// The caller should not mess with this string, as it doesn't belong to him.
//
const char* TSocketError::GetReasonString() const
{
  return String;
}

//
// This function appends an error string to whatever is in the string
// 'stringToAppendErrorTo' and put the result in 'destination'.  You may
// want to put something specific about the error in the string and then use
// AppendError() to add the Winsock error code and description to it.
//
// For example, you could say:
//   MessageBox(TSocketError(WSAENOTCONN).AppendError("Unable to send your mail"),
//                                                   "Error", MB_OK);
// And AppendError() will put "\n\nWinsock Error 10057: Socket is not presently connected"
// after the "Unable to send you mail" string.  Quite convenient.
// szStringToAppendErrorTo must be able to hold at least 128 characters.
//
char* TSocketError::AppendError(char* stringToAppendErrorTo, char* destination)
{
  // If no destination, then the user wants to use our own string space.
  //
  if (!destination) {
    TAPointer<char> tempString = new char[SizeToAllocate];
    strcpy(tempString, stringToAppendErrorTo);
    strcat(tempString, "\n\n");
    strcat(tempString, GetReasonString());
    return tempString;
  }

  strcpy(destination, stringToAppendErrorTo);
  strcat(destination, "\n\n");
  strcat(destination, GetReasonString());
  return destination;
}

//
// This function is similar to AppendError(char*), but the pre-string is taken from
//  a string resource and 'szStringToAppendErrorTo' will be overwritten with what is
//  in the string resource and appended with the Winsock Error description.
//
// stringToAppendErrorTo must be able to hold at least 128 characters.
//
char* TSocketError::AppendError(int stringResourceToAppendErrorTo, char* destination)
{
  if (!destination) { // In this case, the user wants to use our own string.
    TAPointer<char> tempString = new char[SizeToAllocate];
    GetModule().LoadString(stringResourceToAppendErrorTo, tempString, 90);
    AppendError(tempString);
    strcpy(String, tempString);
    return String;
   }
   GetModule().LoadString(stringResourceToAppendErrorTo, destination, 90);
   return AppendError(destination);
}

//
// This function gets a string, suitable for display, based on the nError value.
// The previous string is deleted if necessary.
// Note that the string allocated is ALWAYS at least 128 characters long.
// Note that even though the error strings you see below don't have
//  error numbers associated with them, the function pre-pends the error number
//  to the szString before returning.  If you are writing string resources
//  for the error strings, don't put error numbers in the string, since we
//  do that for you below.
//
void TSocketError::GetErrorString()
{
  delete[] String;
  String = new char[SizeToAllocate];
  String[0] = 0;

  int resIdLookup[] = {
    WSAEINTR,
    WSAEBADF,
    WSAEACCES,
    WSAEFAULT,
    WSAEINVAL,
    WSAEMFILE,
    WSAEWOULDBLOCK,
    WSAEINPROGRESS,
    WSAEALREADY,
    WSAENOTSOCK,
    WSAEDESTADDRREQ,
    WSAEMSGSIZE,
    WSAEPROTOTYPE,
    WSAENOPROTOOPT,
    WSAEPROTONOSUPPORT,
    WSAESOCKTNOSUPPORT,
    WSAEOPNOTSUPP,
    WSAEPFNOSUPPORT,
    WSAEAFNOSUPPORT,
    WSAEADDRINUSE,
    WSAEADDRNOTAVAIL,
    WSAENETDOWN,
    WSAENETUNREACH,
    WSAENETRESET,
    WSAECONNABORTED,
    WSAECONNRESET,
    WSAENOBUFS,
    WSAEISCONN,
    WSAENOTCONN,
    WSAESHUTDOWN,
    WSAETOOMANYREFS,
    WSAETIMEDOUT,
    WSAECONNREFUSED,
    WSAELOOP,
    WSAENAMETOOLONG,
    WSAEHOSTDOWN,
    WSAEHOSTUNREACH,
    WSAENOTEMPTY,
    WSAEPROCLIM,
    WSAEUSERS,
    WSAEDQUOT,
    WSAESTALE,
    WSAEREMOTE,
    WSAEDISCON,
    WSASYSNOTREADY,
    WSAVERNOTSUPPORTED,
    WSANOTINITIALISED,
    WSAHOST_NOT_FOUND,
    WSATRY_AGAIN,
    WSANO_RECOVERY,
    WSANO_DATA,
  };
  int id = 0;
  while (id < COUNTOF(resIdLookup) && resIdLookup[id] != Error)
    id++;
  TAPointer<char> temp = new char[SizeToAllocate];
  GetModule().LoadString(IDS_WINSOCK_BASE+id+1, temp, SizeToAllocate);
  sprintf(String, "Winsock Error %d %s", Error, (char*)temp);
}

//
// Return the current module.  Used when loading strings.
// Important when linking to OWL dynamically because ::LoadString
// would try to load from the EXE, but the WinSock resource
// strings are in the DLL.
//
TModule&
TSocketError::GetModule()         // this is a static function
{
  return *Module;
}

