program sites;

uses
  Forms,
  siteform in 'siteform.pas' {Form1},
  sitedata in 'sitedata.pas' {DataModule1: TDataModule};

{$R *.RES}

begin
  Application.Initialize;
  Application.CreateForm(TForm1, Form1);
  Application.CreateForm(TDataModule1, DataModule1);
  Application.Run;
end.
