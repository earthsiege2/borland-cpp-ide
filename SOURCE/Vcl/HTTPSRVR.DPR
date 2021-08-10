library HTTPSrvr;

uses
  WebBroker,
  ISAPIApp,
  HTTPIntr in 'HTTPIntr.pas' {HTTPServer: TWebModule};

{$R *.RES}

exports
  GetExtensionVersion,
  HttpExtensionProc,
  TerminateExtension;

begin
  Application.Initialize;
  Application.CreateForm(THTTPServer, HTTPServer);
  Application.Run;
end.
