program Win2kApp;

uses
  Forms,
  W2kMain in 'W2kMain.pas' {Win2kAppForm},
  About in 'About.pas' {AboutBox};

{$R *.RES}

begin
  Application.Initialize;
  Application.CreateForm(TWin2kAppForm, Win2kAppForm);
  Application.CreateForm(TAboutBox, AboutBox);
  Application.Run;
end.
 
