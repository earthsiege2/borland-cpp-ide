{*******************************************************}
{                                                       }
{       Borland Delphi Test Server                      }
{                                                       }
{  Copyright (c) 2001 Borland Software Corporation      }
{                                                       }
{*******************************************************}

unit SvrConst;

interface

resourcestring
  sWebAppDebugger = 'Web App Debugger';
  sStopServer = 'Stop';
  sStartServer = 'Start';
  sCouldNotOpenRegKey = 'Unable to not open registry key: %s';
  sUnauthorizedString = '<HTML><HEAD><TITLE>Unauthorized</TITLE></HEAD>' +
    '<BODY><H1>Unauthorized</H1>' +
    'Proper authorization is required for this area. ' +
    'Either your browser does not perform authorization, ' +
    'or your authorization has failed.' +
    '</BODY></HTML>'#13#10;
  sForbiddenString = '<HTML><TITLE>The requested URL is forbidden</TITLE>' + '<BODY>' + '<H1>The requested URL is forbidden</H1>' + '<P>HTTP status code: 403' + '</BODY></HTML>'#13#10;
  sNoDirBrowseString = '<HTML><TITLE>Directory browsing is forbidden</TITLE>' + '<BODY>' + '<H1>The requested URL is forbidden</H1>' + '<P>HTTP status code: 403' + '</BODY></HTML>'#13#10;
  sBadRequest = '<HTML><TITLE>Invalid HTTP request: Method not allowed for HTTP/1.0</TITLE>' + '<BODY>' + '<H1>Invalid HTTP request: Method not allowed for HTTP/1.0</H1>' + '<P>HTTP status code: 400' + '</BODY></HTML>'#13#10;
  sNotFound =
    '<TITLE>The requested URL was not found</TITLE>' +
    '<BODY>' +
    '<H1>The requested URL was not found</H1>' +
    '<P>HTTP status code: 404' +
    '</BODY>';
  sInternalServerError =
    '<TITLE>Internal Server Error</TITLE>' +
    '<BODY>' +
    '<H1>Internal Server Error</H1>' +
    '<P>HTTP status code: 500' +
    '<P>HTTP error message: %s' +
    '</BODY>';

  sInvalidActionRegistration = 'Invalid Action registration';
  sErrorEvent = 'ERROR';
  sResponseEvent = 'RESPONSE';
  sEvent = 'Event';
  sTime = 'Time';
  sDate = 'Date';
  sElapsed = 'Elapsed';
  sPath = 'Path';
  sCode = 'Code';
  sContentLength = 'Content Length';
  sContentType = 'Content Type';
  sThread = 'Thread';

  sNoDefaultURL = '(none)';
  sLogTab = 'Log(%d)';

  sSend = 'Send';
  sReceive = 'Receive';
  sLogStrTemplate = '%s %s Error: (%d)%s';

  UnauthorizedString = '<HTML><HEAD><TITLE>Unauthorized</TITLE></HEAD>' +
    '<BODY><H1>Unauthorized</H1>' +
    'Proper authorization is required for this area. ' +
    'Either your browser does not perform authorization, ' +
    'or your authorization has failed.' +
    '</BODY></HTML>'#13#10;
  ForbiddenString = '<HTML><TITLE>The requested URL is forbidden</TITLE>' + '<BODY>' + '<H1>The requested URL is forbidden</H1>' + '<P>HTTP status code: 403' + '</BODY></HTML>'#13#10;
  NoDirBrowseString = '<HTML><TITLE>Directory browsing is forbidden</TITLE>' + '<BODY>' + '<H1>The requested URL is forbidden</H1>' + '<P>HTTP status code: 403' + '</BODY></HTML>'#13#10;
  BadRequest = '<HTML><TITLE>Invalid HTTP request: Method not allowed for HTTP/1.0</TITLE>' + '<BODY>' + '<H1>Invalid HTTP request: Method not allowed for HTTP/1.0</H1>' + '<P>HTTP status code: 400' + '</BODY></HTML>'#13#10;
  NotFound =
    '<TITLE>The requested URL was not found</TITLE>' +
    '<BODY>' +
    '<H1>The requested URL was not found</H1>' +
    '<P>HTTP status code: 404' +
    '</BODY>';
  DateFormat = 'ddd, dd mmm yyyy hh:mm:ss';
  sBuild = 'Build';
  sDirHeader = '<HTML><HEAD><TITLE>Directory of %s</TITLE></HEAD>' +
    '<BODY><H1>Directory of %0:s</H1>'#13#10;
  sDirParent = 'Up to <A HREF="%s">%0:s</A>'#13#10'<UL>';
  sDirRoot = 'Up to <A HREF="%s">root directory</A>'#13#10'<UL>';
  sDirEntry = '<LI>[ <A HREF="%s">%s</A> ]'#13#10;
  sFileEntry = '<LI><A HREF="%s">%s</A> (%d bytes)'#13#10;
  sListStart = '<UL>'#13#10;
  sDirFooter = '</UL></BODY></HTML>'#13#10;


implementation

end.
