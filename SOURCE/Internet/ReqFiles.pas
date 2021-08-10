
{*******************************************************}
{                                                       }
{       Borland Delphi Visual Component Library         }
{       Web server application components               }
{                                                       }
{ Copyright (c) 2000-2001, Borland Software Corporation }
{                                                       }
{*******************************************************}

unit ReqFiles;

interface

uses SysUtils, Classes, Contnrs, HTTPApp;

type

{ TWebRequestFile }

  TWebRequestFile = class(TAbstractWebRequestFile)
  private
    FFieldName: string;
    FFileName: string;
    FStream: TStream;
    FContentType: string;
  protected
    function GetFieldName: string; override;
    function GetFileName: string; override;
    function GetStream: TStream; override;
    function GetContentType: string; override;
  public
    constructor Create(const AFieldName, AFileName, AContentType: string;
  AContent: Pointer; AContentLength: Integer);
    destructor Destroy; override;
  end;

{ TWebRequestFiles }

  TWebRequestFiles = class(TAbstractWebRequestFiles)
  private
    FList: TObjectList;
  protected
    function GetCount: Integer; override;
    function GetItem(I: Integer): TAbstractWebRequestFile; override;
  public
    constructor Create;
    destructor Destroy; override;
    procedure Add(const AName, AFileName, AContentType: string; AContent: Pointer; AContentLength: Integer); overload;
    procedure Add(AFile: TWebRequestFile); overload;
  end;

  TWebRequestFileStream = class(TCustomMemoryStream)
  public
    constructor Create(ABuffer: Pointer; Size: Integer);
    function Write(const Buffer; Count: Longint): Longint; override;
  end;

implementation

uses WebConst, WebComp, BrkrConst;

{ TWebRequestFiles }

procedure TWebRequestFiles.Add(const AName, AFileName, AContentType: string;
  AContent: Pointer; AContentLength: Integer);
begin
  Add(TWebRequestFile.Create(AName, AFileName, AContentType,
    AContent, AContentLength));
end;

procedure TWebRequestFiles.Add(AFile: TWebRequestFile);
begin
  FList.Add(AFile);
end;

constructor TWebRequestFiles.Create;
begin
  FList := TObjectList.Create(True {Owned});
  inherited Create;
end;

destructor TWebRequestFiles.Destroy;
begin
  inherited;
  FList.Free;
end;

function TWebRequestFiles.GetCount: Integer;
begin
  Result := FList.Count;
end;

function TWebRequestFiles.GetItem(I: Integer): TAbstractWebRequestFile;
begin
  Result := FList[I] as TAbstractWebRequestFile;
end;

{ TWebRequestFile }

constructor TWebRequestFile.Create(const AFieldName, AFileName, AContentType: string;
  AContent: Pointer; AContentLength: Integer);
begin
  FFieldName := AFieldName;
  FFileName := AFileName;
  FContentType := AContentType;
  FStream := TWebRequestFileStream.Create(AContent, AContentLength);
  inherited Create;
end;

destructor TWebRequestFile.Destroy;
begin
  inherited;
  FStream.Free;
end;

function TWebRequestFile.GetContentType: string;
begin
  Result := FContentType;
end;

function TWebRequestFile.GetFieldName: string;
begin
  Result := FFieldName;
end;

function TWebRequestFile.GetFileName: string;
begin
  Result := FFileName;
end;

function TWebRequestFile.GetStream: TStream;
begin
  Result := FStream;
end;

{ TWebRequestFileStream }

constructor TWebRequestFileStream.Create(ABuffer: Pointer; Size: Integer);
begin
  SetPointer(ABuffer, Size);
  inherited Create;
end;

function TWebRequestFileStream.Write(const Buffer;
  Count: Integer): Longint;
begin
  // Write not supported
  Assert(False);
  Result := 0;
end;

end.
