library IsapiStub;

uses
  WebBroker in 'WebBroker.pas',
  ISAPIApp in 'ISAPIApp.pas',
  IsapiStubApp in 'IsapiStubApp.pas',
  ReqImpl in 'ReqImpl.pas',
  StubAction in 'StubAction.pas' {StubActionModule: TWebModule};

{$R *.RES}

exports
  GetExtensionVersion,
  HttpExtensionProc,
  TerminateExtension;

begin
  Application.Initialize;
  Application.CreateForm(TStubActionModule, StubActionModule);
  Application.Run;
end.
