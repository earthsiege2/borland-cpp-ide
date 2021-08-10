program Delphi2C;

uses
  Forms,
  main in 'main.pas' {DelphiToC};

{$R *.RES}

begin
  Application.Initialize;
  Application.CreateForm(TDelphiToBC, DelphiToBC);
  Application.Run;
end.
