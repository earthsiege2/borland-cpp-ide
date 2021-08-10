program CgiStub;

{$APPTYPE CONSOLE}



uses
  WebBroker in 'WebBroker.pas',
  CGIApp in 'CGIApp.pas',
  CGIStubApp in 'CGIStubApp.pas',
  ReqImpl in 'ReqImpl.pas',
  StubAction in 'StubAction.pas' {StubActionModule: TWebModule};

{$R *.RES}

begin
  Application.Initialize;
  Application.CreateForm(TStubActionModule, StubActionModule);
  Application.Run;
end.
