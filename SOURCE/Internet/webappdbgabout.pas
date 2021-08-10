unit WebAppDbgAbout;

interface

uses
  Windows, Messages, SysUtils, Classes, Graphics, Controls,
  Forms, Dialogs, StdCtrls, Buttons, ExtCtrls;

type
  TAboutBox = class(TForm)
    OKButton: TButton;
    Bevel1: TBevel;
    PhysMem: TLabel;
    OS: TLabel;
    Label3: TLabel;
    DetailsPanel: TPanel;
    Painter: TPaintBox;
    Copyright: TLabel;
    Version: TLabel;
    SKUName: TLabel;
    Logo: TImage;
    CompanyName: TLabel;
    procedure FormCreate(Sender: TObject);
  private
    { Private declarations }
    procedure InitializeCaptions;
    procedure SetOSInfo;
  public
    { Public declarations }
  end;

procedure ShowAboutBox;

resourcestring
  sMemKB = '#,###,###" KB"';

implementation

uses SvrConst, ShellAPI;

const
  BltSize = 12;

{$R *.dfm}

procedure ShowAboutBox;
var
  AboutBox: TAboutBox;
begin
  AboutBox := TAboutBox.Create(Application);
  try
    AboutBox.ShowModal;
  finally
    AboutBox.Free;
  end;
end;

procedure TAboutBox.SetOSInfo;
var
  Platform: string;
  BuildNumber: Integer;
  Version: string;
begin
  Version := '%d.%d ';
  case Win32Platform of
    VER_PLATFORM_WIN32_WINDOWS:
    begin
      Platform := 'Windows 95'; // do not localize
      BuildNumber := Win32BuildNumber and $0000FFFF;
      if Win32MinorVersion = 10 then
        Platform := 'Windows 98'; // do not localize
    end;
    VER_PLATFORM_WIN32_NT:
    begin
      if Win32MajorVersion >= 5 then
      begin
        Platform := 'Windows 2000';  // do not localize
        Version := '';
      end else Platform := 'Windows NT'; // do not localize
      BuildNumber := Win32BuildNumber;
    end;
    else
    begin
      Platform := 'Windows'; // do not localize
      BuildNumber := 0; // set to avoid compiler warning
    end;
  end;
  
  if (Win32Platform = VER_PLATFORM_WIN32_WINDOWS) or
    (Win32Platform = VER_PLATFORM_WIN32_NT) then
  begin
    if (Win32MajorVersion = 4) and (Win32MinorVersion = 10) then
      OS.Caption := Format('%s (%s %d.%d.%d %s)', [Platform, sBuild,
        Win32MajorVersion, Win32MinorVersion, BuildNumber, Win32CSDVersion])
    else if Win32CSDVersion = '' then
      OS.Caption := Format('%s %s(%s %d)', [Platform, Format(Version,
        [Win32MajorVersion, Win32MinorVersion]), sBuild, BuildNumber])
    else
      OS.Caption := Format('%s %s(%s %d: %s)', [Platform, Format(Version,
        [Win32MajorVersion, Win32MinorVersion]), sBuild, BuildNumber, Win32CSDVersion]);
  end
  else
    OS.Caption := Format('%s %d.%d', [Platform, Win32MajorVersion,
      Win32MinorVersion])
end;

procedure TAboutBox.InitializeCaptions;
var
  MS: TMemoryStatus;
begin
  SetOSInfo;
  MS.dwLength := SizeOf(TMemoryStatus);
  GlobalMemoryStatus(MS);
  PhysMem.Caption := FormatFloat(sMemKB, MS.dwTotalPhys / 1024);
end;

procedure TAboutBox.FormCreate(Sender: TObject);
begin
  InitializeCaptions;
end;

end.

