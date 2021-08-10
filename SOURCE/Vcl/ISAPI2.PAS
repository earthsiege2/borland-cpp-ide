{ *********************************************************************** }
{                                                                         }
{ Delphi Runtime Library                                                  }
{                                                                         }
{ Copyright (c) 1997-2001 Borland Software Corporation                    }
{                                                                         }
{ *********************************************************************** }

{*******************************************************}
{       Structure definitions and prototypes for the    }
{       version 2.0 HTTP Server Extension interface.    }
{*******************************************************}

unit Isapi2;

{$WEAKPACKAGEUNIT}

interface

{$HPPEMIT '#include <httpfilt.h>'}

uses Windows;

const
  HSE_VERSION_MAJOR         =   2;      // major version of this spec
  {$EXTERNALSYM HSE_VERSION_MAJOR}
  HSE_VERSION_MINOR         =   0;      // minor version of this spec
  {$EXTERNALSYM HSE_VERSION_MINOR}
  HSE_LOG_BUFFER_LEN        =  80;
  {$EXTERNALSYM HSE_LOG_BUFFER_LEN}
  HSE_MAX_EXT_DLL_NAME_LEN  = 256;
  {$EXTERNALSYM HSE_MAX_EXT_DLL_NAME_LEN}

type
  HCONN = THandle;
  {$EXTERNALSYM HCONN}

// the following are the status codes returned by the Extension DLL

const
  HSE_STATUS_SUCCESS                      = 1;
  {$EXTERNALSYM HSE_STATUS_SUCCESS}
  HSE_STATUS_SUCCESS_AND_KEEP_CONN        = 2;
  {$EXTERNALSYM HSE_STATUS_SUCCESS_AND_KEEP_CONN}
  HSE_STATUS_PENDING                      = 3;
  {$EXTERNALSYM HSE_STATUS_PENDING}
  HSE_STATUS_ERROR                        = 4;
  {$EXTERNALSYM HSE_STATUS_ERROR}

// The following are the values to request services with the ServerSupportFunction.
//  Values from 0 to 1000 are reserved for future versions of the interface

  HSE_REQ_BASE                             = 0;
  {$EXTERNALSYM HSE_REQ_BASE}
  HSE_REQ_SEND_URL_REDIRECT_RESP           = ( HSE_REQ_BASE + 1 );
  {$EXTERNALSYM HSE_REQ_SEND_URL_REDIRECT_RESP}
  HSE_REQ_SEND_URL                         = ( HSE_REQ_BASE + 2 );
  {$EXTERNALSYM HSE_REQ_SEND_URL}
  HSE_REQ_SEND_RESPONSE_HEADER             = ( HSE_REQ_BASE + 3 );
  {$EXTERNALSYM HSE_REQ_SEND_RESPONSE_HEADER}
  HSE_REQ_DONE_WITH_SESSION                = ( HSE_REQ_BASE + 4 );
  {$EXTERNALSYM HSE_REQ_DONE_WITH_SESSION}
  HSE_REQ_END_RESERVED                     = 1000;
  {$EXTERNALSYM HSE_REQ_END_RESERVED}

//
//  These are Microsoft specific extensions
//

  HSE_REQ_MAP_URL_TO_PATH                  = (HSE_REQ_END_RESERVED+1);
  {$EXTERNALSYM HSE_REQ_MAP_URL_TO_PATH}
  HSE_REQ_GET_SSPI_INFO                    = (HSE_REQ_END_RESERVED+2);
  {$EXTERNALSYM HSE_REQ_GET_SSPI_INFO}
  HSE_APPEND_LOG_PARAMETER                 = (HSE_REQ_END_RESERVED+3);
  {$EXTERNALSYM HSE_APPEND_LOG_PARAMETER}
  HSE_REQ_SEND_URL_EX                      = (HSE_REQ_END_RESERVED+4);
  {$EXTERNALSYM HSE_REQ_SEND_URL_EX}
  HSE_REQ_IO_COMPLETION                    = (HSE_REQ_END_RESERVED+5);
  {$EXTERNALSYM HSE_REQ_IO_COMPLETION}
  HSE_REQ_TRANSMIT_FILE                    = (HSE_REQ_END_RESERVED+6);
  {$EXTERNALSYM HSE_REQ_TRANSMIT_FILE}
  HSE_REQ_REFRESH_ISAPI_ACL                = (HSE_REQ_END_RESERVED+7);
  {$EXTERNALSYM HSE_REQ_REFRESH_ISAPI_ACL}

//
//  Bit Flags for TerminateExtension
//
//    HSE_TERM_ADVISORY_UNLOAD - Server wants to unload the extension,
//          extension can return TRUE if OK, FALSE if the server should not
//          unload the extension
//
//    HSE_TERM_MUST_UNLOAD - Server indicating the extension is about to be
//          unloaded, the extension cannot refuse.
//

  HSE_TERM_ADVISORY_UNLOAD                 = $00000001;
  {$EXTERNALSYM HSE_TERM_ADVISORY_UNLOAD}
  HSE_TERM_MUST_UNLOAD                     = $00000002;
  {$EXTERNALSYM HSE_TERM_MUST_UNLOAD}

//
// Flags for IO Functions, supported for IO Funcs.
//  TF means ServerSupportFunction( HSE_REQ_TRANSMIT_FILE)
//

{  HSE_IO_SYNC                      = $00000001;   // for WriteClient
  HSE_IO_ASYNC                     = $00000002;   // for WriteClient/TF
  HSE_IO_DISCONNECT_AFTER_SEND     = $00000004;   // for TF
  HSE_IO_SEND_HEADERS              = $00000008;   // for TF }

//
// passed to GetExtensionVersion
//

type
  PHSE_VERSION_INFO = ^HSE_VERSION_INFO;
  HSE_VERSION_INFO = packed record
    dwExtensionVersion: DWORD;
    lpszExtensionDesc: array [0..HSE_MAX_EXT_DLL_NAME_LEN-1] of Char;
  end;
  THSE_VERSION_INFO = HSE_VERSION_INFO;
  LPHSE_VERSION_INFO = PHSE_VERSION_INFO;
  {$EXTERNALSYM LPHSE_VERSION_INFO}

type
  TGetServerVariableProc = function ( hConn: HCONN;
                                      VariableName: PChar;
                                      Buffer: Pointer;
                                      var Size: DWORD ): BOOL stdcall;

  TWriteClientProc = function ( ConnID: HCONN;
                                Buffer: Pointer;
                                var Bytes: DWORD;
                                dwReserved: DWORD ): BOOL stdcall;

  TReadClientProc = function ( ConnID: HCONN;
                               Buffer: Pointer;
                               var Size: DWORD ): BOOL stdcall;

  TServerSupportFunctionProc = function ( hConn: HCONN;
                                          HSERRequest: DWORD;
                                          Buffer: Pointer;
                                          Size: LPDWORD;
                                          DataType: LPDWORD ): BOOL stdcall;

//
// passed to extension procedure on a new request
//
type

  PEXTENSION_CONTROL_BLOCK = ^TEXTENSION_CONTROL_BLOCK;
  TEXTENSION_CONTROL_BLOCK = packed record
    cbSize: DWORD;                    // size of this struct.
    dwVersion: DWORD;                 // version info of this spec
    ConnID: HCONN;                    // Context number not to be modified!
    dwHttpStatusCode: DWORD;          // HTTP Status code
                     // null terminated log info specific to this Extension DLL
    lpszLogData: array [0..HSE_LOG_BUFFER_LEN-1] of Char;
    lpszMethod: PChar;                // REQUEST_METHOD
    lpszQueryString: PChar;           // QUERY_STRING
    lpszPathInfo: PChar;              // PATH_INFO
    lpszPathTranslated: PChar;        // PATH_TRANSLATED
    cbTotalBytes: DWORD;              // Total bytes indicated from client
    cbAvailable: DWORD;               // Available number of bytes
    lpbData: Pointer;                 // pointer to cbAvailable bytes
    lpszContentType: PChar;           // Content type of client data

    GetServerVariable: TGetServerVariableProc;
    WriteClient: TWriteClientProc;
    ReadClient: TReadClientProc;
    ServerSupportFunction: TServerSupportFunctionProc;
  end;

//
//  these are the prototypes that must be exported from the extension DLL
//

//  function GetExtensionVersion(var Ver: THSE_VERSION_INFO): BOOL; stdcall;
//  function HttpExtensionProc(var ECB: TEXTENSION_CONTROL_BLOCK): DWORD; stdcall;
//  function TerminateExtension(dwFlags: DWORD): BOOL; stdcall;

// the following type declarations are for the server side

  TGetExtensionVersion = function (var Ver: THSE_VERSION_INFO): BOOL stdcall;
  THttpExtensionProc = function (var ECB: TEXTENSION_CONTROL_BLOCK): DWORD stdcall;
  TTerminateExtension = function (dwFlags: DWORD): BOOL stdcall;

  THseIoCompletion = procedure (var ECB: TEXTENSION_CONTROL_BLOCK; pContext: Pointer;
    cbIO: DWORD; dwError: DWORD) stdcall;

//
// HSE_TF_INFO defines the type for HTTP SERVER EXTENSION support for
//  ISAPI applications to send files using TransmitFile.
// A pointer to this object should be used with ServerSupportFunction()
//  for HSE_REQ_TRANSMIT_FILE.
//

  PHSE_TF_INFO = ^THSE_TF_INFO;
  THSE_TF_INFO = record

    //
    // callback and context information
    // the callback function will be called when IO is completed.
    // the context specified will be used during such callback.
    //
    // These values (if non-NULL) will override the one set by calling
    //  ServerSupportFunction() with HSE_REQ_IO_COMPLETION
    //
    pfnHseIO: THseIoCompletion;
    pContext: Pointer;

    // file should have been opened with FILE_FLAG_SEQUENTIAL_SCAN
    hFile: THandle;

    //
    // HTTP header and status code
    // These fields are used only if HSE_IO_SEND_HEADERS is present in dwFlags
    //

    pszStatusCode: PChar; // HTTP Status Code  eg: "200 OK"

    BytesToWrite: DWORD;  // special value of "0" means write entire file.
    Offset: DWORD;        // offset value within the file to start from

    pHead: Pointer;       // Head buffer to be sent before file data
    HeadLength: DWORD;    // header length
    pTail: Pointer;       // Tail buffer to be sent after file data
    TailLength: DWORD;    // tail length

    dwFlags: DWORD;       // includes HSE_IO_DISCONNECT_AFTER_SEND, ...
  end;
   
/////////////////////////////////////////////////////////////////////////////

{********
*
*    This module contains the Microsoft HTTP filter extension info
*
******************}

//
//  Current version of the filter spec is 2.0
//

const
  HTTP_FILTER_REVISION    = $00020000;
  {$EXTERNALSYM HTTP_FILTER_REVISION}

  SF_MAX_USERNAME         = (256+1);
  {$EXTERNALSYM SF_MAX_USERNAME}
  SF_MAX_PASSWORD         = (256+1);
  {$EXTERNALSYM SF_MAX_PASSWORD}

  SF_MAX_FILTER_DESC_LEN  = (256+1);
  {$EXTERNALSYM SF_MAX_FILTER_DESC_LEN}

  //
  //  These values can be used with the pfnSFCallback function supplied in
  //  the filter context structure
  //

  //
  //  Sends a complete HTTP server response header including
  //  the status, server version, message time and MIME version.
  //
  //  Server extensions should append other information at the end,
  //  such as Content-type, Content-length etc followed by an extra
  //  '\r\n'.
  //
  //  pData - Zero terminated string pointing to optional
  //      status string (i.e., "401 Access Denied") or NULL for
  //      the default response of "200 OK".
  //
  //  ul1 - Zero terminated string pointing to optional data to be
  //      appended and set with the header.  If NULL, the header will
  //      be terminated with an empty line.
  //

  SF_REQ_SEND_RESPONSE_HEADER = 0;
  {$EXTERNALSYM SF_REQ_SEND_RESPONSE_HEADER}

  //
  //  If the server denies the HTTP request, add the specified headers
  //  to the server error response.
  //
  //  This allows an authentication filter to advertise its services
  //  w/o filtering every request.  Generally the headers will be
  //  WWW-Authenticate headers with custom authentication schemes but
  //  no restriction is placed on what headers may be specified.
  //
  //  pData - Zero terminated string pointing to one or more header lines
  //      with terminating '\r\n'.
  //

  SF_REQ_ADD_HEADERS_ON_DENIAL = 1;
  {$EXTERNALSYM SF_REQ_ADD_HEADERS_ON_DENIAL}

  //
  //  Only used by raw data filters that return SF_STATUS_READ_NEXT
  //
  //  ul1 - size in bytes for the next read
  //

  SF_REQ_SET_NEXT_READ_SIZE = 2;
  {$EXTERNALSYM SF_REQ_SET_NEXT_READ_SIZE}

  //
  //  Used to indicate this request is a proxy request
  //
  //  ul1 - The proxy flags to set
  //      0x00000001 - This is a HTTP proxy request
  //
  //

  SF_REQ_SET_PROXY_INFO = 3;
  {$EXTERNALSYM SF_REQ_SET_PROXY_INFO}

  //
  //  These values are returned by the filter entry point when a new request is
  //  received indicating their interest in this particular request
  //

  //
  //  The filter has handled the HTTP request.  The server should disconnect
  //  the session.
  //

  SF_STATUS_REQ_FINISHED = $8000000;
  {$EXTERNALSYM SF_STATUS_REQ_FINISHED}

  //
  //  Same as SF_STATUS_FINISHED except the server should keep the TCP
  //  session open if the option was negotiated
  //

  SF_STATUS_REQ_FINISHED_KEEP_CONN = $8000001;
  {$EXTERNALSYM SF_STATUS_REQ_FINISHED_KEEP_CONN}

  //
  //  The next filter in the notification chain should be called
  //

  SF_STATUS_REQ_NEXT_NOTIFICATION = $8000002;
  {$EXTERNALSYM SF_STATUS_REQ_NEXT_NOTIFICATION}

  //
  //  This filter handled the notification.  No other handles should be
  //  called for this particular notification type
  //

  SF_STATUS_REQ_HANDLED_NOTIFICATION = $8000003;
  {$EXTERNALSYM SF_STATUS_REQ_HANDLED_NOTIFICATION}

  //
  //  An error occurred.  The server should use GetLastError() and indicate
  //  the error to the client
  //

  SF_STATUS_REQ_ERROR = $8000004;
  {$EXTERNALSYM SF_STATUS_REQ_ERROR}

  //
  //  The filter is an opaque stream filter and we're negotiating the
  //  session parameters.  Only valid for raw read notification.
  //

  SF_STATUS_REQ_READ_NEXT = $8000005;
  {$EXTERNALSYM SF_STATUS_REQ_READ_NEXT}

//
//  pvNotification points to this structure for all request notification types
//

type

  TFilterGetServerVariableProc = function (var pfc{: THTTP_FILTER_CONTEXT};
    VariableName: PChar; Buffer: Pointer; var Size: DWORD ): BOOL stdcall;

  TFilterAddResponseHeadersProc = function (var pfc{: THTTP_FILTER_CONTEXT};
    lpszHeaders: PChar; dwReserved: DWORD): BOOL stdcall;

  TFilterWriteClientProc = function (var pfc{: THTTP_FILTER_CONTEXT};
    Buffer: Pointer; var Bytes: DWORD; dwReserved: DWORD ): BOOL stdcall;

  TFilterAllocMemProc = function (var pfc{: THTTP_FILTER_CONTEXT}; cbSize: DWORD;
    dwReserved: DWORD): Pointer stdcall;

  TFilterServerSupportFunctionProc = function (var pfc{: THTTP_FILTER_CONTEXT};
    sfReq: DWORD; pData: Pointer; ul1, ul2: DWORD): BOOL stdcall;

  PHTTP_FILTER_CONTEXT = ^THTTP_FILTER_CONTEXT;
  THTTP_FILTER_CONTEXT = record
    cbSize: DWORD;

    //
    //  This is the structure revision level.
    //

    Revision: DWORD;

    //
    //  Private context information for the server.
    //

    ServerContext: Pointer;
    ulReserved: DWORD;

    //
    //  TRUE if this request is coming over a secure port
    //

    fIsSecurePort: BOOL;

    //
    //  A context that can be used by the filter
    //

    pFilterContext: Pointer;

    //
    //  Server callbacks
    //

    GetServerVariable: TFilterGetServerVariableProc;
    AddResponseHeaders: TFilterAddResponseHeadersProc;
    WriteClient: TFilterWriteClientProc;
    AllocMem: TFilterAllocMemProc;
    ServerSupportFunction: TFilterServerSupportFunctionProc;
  end;

  //
  //  This structure is the notification info for the read and send raw data
  //  notification types
  //

  PHTTP_FILTER_RAW_DATA = ^HTTP_FILTER_RAW_DATA;
  HTTP_FILTER_RAW_DATA = record
    //
    //  This is a pointer to the data for the filter to process.
    //

    pvInData: Pointer;
    cbInData: DWORD;       // Number of valid data bytes
    cbInBuffer: DWORD;     // Total size of buffer

    dwReserved: DWORD;
  end;
  {$EXTERNALSYM HTTP_FILTER_RAW_DATA}
  THTTP_FILTER_RAW_DATA = HTTP_FILTER_RAW_DATA;
  LPHTTP_FILTER_RAW_DATA = PHTTP_FILTER_RAW_DATA;
  {$EXTERNALSYM LPHTTP_FILTER_RAW_DATA}

  //
  //  This structure is the notification info for when the server is about to
  //  process the client headers
  //

  TGetHeaderProc = function (var pfc: THTTP_FILTER_CONTEXT; lpszName: PChar;
    var lpvBuffer; var lpdwSize: DWORD): BOOL stdcall;

  TSetHeaderProc = function (var pfc: THTTP_FILTER_CONTEXT; lpszName,
    lpszValue: PChar): BOOL stdcall;

  TAddHeaderProc = function (var pfc: THTTP_FILTER_CONTEXT; lpszName,
    lpszValue: PChar): BOOL stdcall;

  PHTTP_FILTER_PREPROC_HEADERS = ^THTTP_FILTER_PREPROC_HEADERS;
  THTTP_FILTER_PREPROC_HEADERS = record
    //
    //  Retrieves the specified header value.  Header names should include
    //  the trailing ':'.  The special values 'method', 'url' and 'version'
    //  can be used to retrieve the individual portions of the request line
    //

    GetHeader: TGetHeaderProc;

    //
    //  Replaces this header value to the specified value.  To delete a header,
    //  specified a value of '\0'.
    //

    SetHeader: TSetHeaderProc;

    //
    //  Adds the specified header and value
    //

    AddHeader: TAddHeaderProc;

    dwReserved: DWORD;
  end;

  //
  //  Authentication information for this request.
  //

  PHTTP_FILTER_AUTHENT = ^HTTP_FILTER_AUTHENT;
  HTTP_FILTER_AUTHENT = record
    //
    //  Pointer to username and password, empty strings for the anonymous user
    //
    //  Client's can overwrite these buffers which are guaranteed to be at
    //  least SF_MAX_USERNAME and SF_MAX_PASSWORD bytes large.
    //

    pszUser: PChar;
    cbUserBuff: DWORD;

    pszPassword: PChar;
    cbPasswordBuff: DWORD;
  end;
  {$EXTERNALSYM HTTP_FILTER_AUTHENT}
  THTTP_FILTER_AUTHENT = HTTP_FILTER_AUTHENT;
  LPHTTP_FILTER_AUTHENT = PHTTP_FILTER_AUTHENT;
  {$EXTERNALSYM LPHTTP_FILTER_AUTHENT}

  //
  //  Indicates the server is going to use the specific physical mapping for
  //  the specified URL.  Filters can modify the physical path in place.
  //

  PHTTP_FILTER_URL_MAP = ^HTTP_FILTER_URL_MAP;
  HTTP_FILTER_URL_MAP = record
    pszURL: PChar;
    pszPhysicalPath: PChar;
    cbPathBuff: DWORD;
  end;
  {$EXTERNALSYM HTTP_FILTER_URL_MAP}
  THTTP_FILTER_URL_MAP = HTTP_FILTER_URL_MAP;
  LPHTTP_FILTER_URL_MAP = PHTTP_FILTER_URL_MAP;
  {$EXTERNALSYM LPHTTP_FILTER_URL_MAP}

const
  //
  //  Bitfield indicating the requested resource has been denied by the server due
  //  to a logon failure, an ACL on a resource, an ISAPI Filter or an
  //  ISAPI Application/CGI Application.
  //
  //  SF_DENIED_BY_CONFIG can appear with SF_DENIED_LOGON if the server
  //  configuration did not allow the user to logon.
  //

  SF_DENIED_LOGON             = $00000001;
  {$EXTERNALSYM SF_DENIED_LOGON}
  SF_DENIED_RESOURCE          = $00000002;
  {$EXTERNALSYM SF_DENIED_RESOURCE}
  SF_DENIED_FILTER            = $00000004;
  {$EXTERNALSYM SF_DENIED_FILTER}
  SF_DENIED_APPLICATION       = $00000008;
  {$EXTERNALSYM SF_DENIED_APPLICATION}
  SF_DENIED_BY_CONFIG         = $00010000;
  {$EXTERNALSYM SF_DENIED_BY_CONFIG}

type
  PHTTP_FILTER_ACCESS_DENIED = ^HTTP_FILTER_ACCESS_DENIED;
  HTTP_FILTER_ACCESS_DENIED = record
    pszURL: PChar;            // Requesting URL
    pszPhysicalPath: PChar;   // Physical path of resource
    dwReason: DWORD;          // Bitfield of SF_DENIED flags
  end;
  {$EXTERNALSYM HTTP_FILTER_ACCESS_DENIED}
  THTTP_FILTER_ACCESS_DENIED = HTTP_FILTER_ACCESS_DENIED;
  LPHTTP_FILTER_ACCESS_DENIED = PHTTP_FILTER_ACCESS_DENIED;
  {$EXTERNALSYM LPHTTP_FILTER_ACCESS_DENIED}

  //
  //  The log information about to be written to the server log file.  The
  //  string pointers can be replaced but the memory must remain valid until
  //  the next notification
  //

  PHTTP_FILTER_LOG = ^HTTP_FILTER_LOG;
  HTTP_FILTER_LOG = record
    pszClientHostName: PChar;
    pszClientUserName: PChar;
    pszServerName: PChar;
    pszOperation: PChar;
    pszTarget: PChar;
    pszParameters: PChar;
    dwHttpStatus: DWORD;
    dwWin32Status: DWORD;
  end;
  {$EXTERNALSYM HTTP_FILTER_LOG}
  THTTP_FILTER_LOG = HTTP_FILTER_LOG;
  LPHTTP_FILTER_LOG = PHTTP_FILTER_LOG;
  {$EXTERNALSYM LPHTTP_FILTER_LOG}

const
  //
  //  Notification Flags
  //
  //  SF_NOTIFY_SECURE_PORT
  //  SF_NOTIFY_NONSECURE_PORT
  //
  //      Indicates whether the application wants to be notified for transactions
  //      that are happenning on the server port(s) that support data encryption
  //      (such as PCT and SSL), on only the non-secure port(s) or both.
  //
  //  SF_NOTIFY_READ_RAW_DATA
  //
  //      Applications are notified after the server reads a block of memory
  //      from the client but before the server does any processing on the
  //      block.  The data block may contain HTTP headers and entity data.
  //
  //
  //

  SF_NOTIFY_SECURE_PORT               = $00000001;
  {$EXTERNALSYM SF_NOTIFY_SECURE_PORT}
  SF_NOTIFY_NONSECURE_PORT            = $00000002;
  {$EXTERNALSYM SF_NOTIFY_NONSECURE_PORT}
  SF_NOTIFY_READ_RAW_DATA             = $00008000;
  {$EXTERNALSYM SF_NOTIFY_READ_RAW_DATA}
  SF_NOTIFY_PREPROC_HEADERS           = $00004000;
  {$EXTERNALSYM SF_NOTIFY_PREPROC_HEADERS}
  SF_NOTIFY_AUTHENTICATION            = $00002000;
  {$EXTERNALSYM SF_NOTIFY_AUTHENTICATION}
  SF_NOTIFY_URL_MAP                   = $00001000;
  {$EXTERNALSYM SF_NOTIFY_URL_MAP}
  SF_NOTIFY_ACCESS_DENIED             = $00000800;
  {$EXTERNALSYM SF_NOTIFY_ACCESS_DENIED}
  SF_NOTIFY_SEND_RAW_DATA             = $00000400;
  {$EXTERNALSYM SF_NOTIFY_SEND_RAW_DATA}
  SF_NOTIFY_LOG                       = $00000200;
  {$EXTERNALSYM SF_NOTIFY_LOG}
  SF_NOTIFY_END_OF_NET_SESSION        = $00000100;
  {$EXTERNALSYM SF_NOTIFY_END_OF_NET_SESSION}

  //
  //  Filter ordering flags
  //
  //  Filters will tend to be notified by their specified
  //  ordering.  For ties, notification order is determined by load order.
  //
  //  SF_NOTIFY_ORDER_HIGH - Authentication or data transformation filters
  //  SF_NOTIFY_ORDER_MEDIUM
  //  SF_NOTIFY_ORDER_LOW  - Logging filters that want the results of any other
  //                      filters might specify this order.
  //

  SF_NOTIFY_ORDER_HIGH               = $00080000;
  {$EXTERNALSYM SF_NOTIFY_ORDER_HIGH}
  SF_NOTIFY_ORDER_MEDIUM             = $00040000;
  {$EXTERNALSYM SF_NOTIFY_ORDER_MEDIUM}
  SF_NOTIFY_ORDER_LOW                = $00020000;
  {$EXTERNALSYM SF_NOTIFY_ORDER_LOW}
  SF_NOTIFY_ORDER_DEFAULT            = SF_NOTIFY_ORDER_LOW;
  {$EXTERNALSYM SF_NOTIFY_ORDER_DEFAULT}
  SF_NOTIFY_ORDER_MASK               = SF_NOTIFY_ORDER_HIGH or
                                       SF_NOTIFY_ORDER_MEDIUM or
                                       SF_NOTIFY_ORDER_LOW;
  {$EXTERNALSYM SF_NOTIFY_ORDER_MASK}

  //
  //  Filter version information, passed to GetFilterVersion
  //

type
  PHTTP_FILTER_VERSION = ^HTTP_FILTER_VERSION;
  HTTP_FILTER_VERSION = record
    //
    //  Version of the spec the server is using
    //

    dwServerFilterVersion: DWORD;

    //
    //  Fields specified by the client
    //

    dwFilterVersion: DWORD;
    lpszFilterDesc: array[0..SF_MAX_FILTER_DESC_LEN - 1] of Char;
    dwFlags: DWORD;
  end;
  {$EXTERNALSYM HTTP_FILTER_VERSION}
  THTTP_FILTER_VERSION = HTTP_FILTER_VERSION;
  LPHTTP_FILTER_VERSION = PHTTP_FILTER_VERSION;
  {$EXTERNALSYM LPHTTP_FILTER_VERSION}

//
//  A filter DLL's entry point looks like this.  The return code should be
//  an SF_STATUS_TYPE
//
//  NotificationType - Type of notification
//  pvNotification - Pointer to notification specific data
//

// function HttpFilterProc(var pfc: THTTP_FILTER_CONTEXT; Notificationtype: DWORD;
//   pvNotification: Pointer): DWORD; stdcall;
//
// function GetFilterVersion(var pVer: THTTP_FILTER_VERSION): BOOL; stdcall;

// the following type declarations are for the server side

  THttpFilterProc = function (var pfc: THTTP_FILTER_CONTEXT;
    Notificationtype: DWORD; pvNotification: Pointer): DWORD stdcall;

  TGetFilterVersion = function (var pVer: THTTP_FILTER_VERSION): BOOL stdcall;

implementation

end.
