program ServerInfo;

{$APPTYPE GUI}

uses
  Forms,
  ComApp,
  SvrInfoConsole in 'SvrInfoConsole.pas' {Form1},
  SvrInfoModule in 'SvrInfoModule.pas' {WebModule2: TWebModule},
  SvrInfoConst in 'SvrInfoConst.pas';

{$R *.RES}

begin
  Application.Initialize;
  Application.CreateForm(TForm1, Form1);
  Application.Run;
end.
