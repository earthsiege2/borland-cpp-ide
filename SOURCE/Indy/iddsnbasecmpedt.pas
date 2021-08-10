unit IdDsnBaseCmpEdt;

interface

uses
{$IFDEF VER140}DesignIntf, DesignEditors;
{$ELSE}Dsgnintf;
{$ENDIF}

type
  TIdBaseComponentEditor = class(TDefaultEditor)
  public
    procedure ExecuteVerb(Index: Integer); override;
    function GetVerb(Index: Integer): string; override;
    function GetVerbCount: Integer; override;
  end;

implementation

uses
  IdAbout,
  IdGlobal,
  IdResourceStrings,
  SysUtils;

procedure TIdBaseComponentEditor.ExecuteVerb(Index: Integer);
begin
  case Index of
    0: ShowAboutBox(RSAAboutBoxCompName, gsIdVersion);
  end;
end;

function TIdBaseComponentEditor.GetVerb(Index: Integer): string;
begin
  case Index of
    0: Result := Format(RSAAboutMenuItemName, [gsIdVersion]);
  end;
end;

function TIdBaseComponentEditor.GetVerbCount: Integer;
begin
  Result := 1;
end;

end.
