{****************************************************************}
{                                                                }
{       Borland Delphi Visual Component Library                  }
{                                                                }
{       Copyright (c) 2000, 2001 Borland Software Corporation    }
{                                                                }
{****************************************************************}

unit AutoDisp;

interface

uses Classes, HTTPApp, Masks;

type

  TWebPathInfo = class;

  TWebDispatch = class(TPersistent)
  private
    FPathInfo: TWebPathInfo;
    FMethodType: TMethodType;
    FEnabled: Boolean;
    function GetMask: TMask;
  protected
    procedure AssignTo(Dest: TPersistent); override;
    procedure SetPathInfo(const Value: string);
    function GetPathInfo: string;
  public
    constructor Create(AComponent: TComponent);
    destructor Destroy; override;
    property Mask: TMask read GetMask;
  published
    property Enabled: Boolean read FEnabled write FEnabled default True;
    property MethodType: TMethodType read FMethodType write FMethodType default mtPost;
    property PathInfo: string read GetPathInfo write SetPathInfo;
  end;

  TWebPathInfo = class
  private
    FMask: TMask;
    FMaskPathInfo: string;
    FPathInfo: string;
    FOwner: TComponent;
    function GetMask: TMask;
    function GetPathInfo: string;
    procedure SetPathInfo(const Value: string);
  public
    constructor Create(AOwner: TComponent);
    destructor Destroy; override;
    property Mask: TMask read GetMask;
    property PathInfo: string read GetPathInfo write SetPathInfo;
  end;

implementation 


{ TWebDispatch }

constructor TWebDispatch.Create(AComponent: TComponent);
begin
  inherited Create;
  FEnabled := True;
  FMethodType := mtPost;
  FPathInfo := TWebPathInfo.Create(AComponent);
end;

destructor TWebDispatch.Destroy;
begin
  inherited;
  FPathInfo.Free;
end;

procedure TWebDispatch.SetPathInfo(const Value: string);
begin
  FPathInfo.PathInfo := Value;
end;

procedure TWebDispatch.AssignTo(Dest: TPersistent);
begin
  if Dest is TWebDispatch then
    with TWebDispatch(Dest) do
    begin
      PathInfo := Self.PathInfo;
      MethodType := Self.MethodType;
      Enabled := Self.Enabled;
    end else inherited AssignTo(Dest);
end;

function TWebDispatch.GetPathInfo: string;
begin
  Result := FPathInfo.PathInfo;
end;

function TWebDispatch.GetMask: TMask;
begin
  Result := FPathInfo.Mask;
end;

{ TWebPathInfo }

constructor TWebPathInfo.Create(AOwner: TComponent);
begin
  FMaskPathInfo := '';
  FMask := TMask.Create(FMaskPathInfo);
  FOwner := AOwner;
end;

destructor TWebPathInfo.Destroy;
begin
  FMask.Free;
  inherited;
end;

function TWebPathInfo.GetMask: TMask;
var
  Mask: TMask;
  NewValue: string;
begin
  if PathInfo <> FMaskPathInfo then
  begin
    FMaskPathInfo := PathInfo;
    if FMaskPathInfo <> '' then NewValue := DosPathToUnixPath(FMaskPathInfo);
    if (NewValue <> '') and (NewValue[1] <> '/') then Insert('/', NewValue, 1);
    Mask := TMask.Create(NewValue);
    try
      FPathInfo := NewValue;
      FMask.Free;
      FMask := nil;
    except
      Mask.Free;
      raise;
    end;
    FMask := Mask;
  end;
  Result := FMask;
end;

function TWebPathInfo.GetPathInfo: string;
begin
  Result := FPathInfo;
  if Result = '' then
    if Assigned(FOwner) then
      Result := FOwner.Name;
end;

procedure TWebPathInfo.SetPathInfo(const Value: string);
begin
  if Assigned(FOwner) and (Value = FOwner.Name) then
    FPathInfo := ''
  else
    FPathInfo := Value;
end;

end.
