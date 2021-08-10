
{*******************************************************}
{                                                       }
{       Borland Delphi Visual Component Library         }
{                                                       }
{       Copyright (c) 1995,99 Inprise Corporation       }
{                                                       }
{*******************************************************}

unit IStreams;

interface

uses Windows, ActiveX, SysUtils, Classes, VirtIntf, Axctrls;

type

  { TIStreamAdapter }

  TIStreamAdapter = class(TStreamAdapter, IStreamModifyTime)
  protected
    FModifyTime: Longint;
  public
    constructor Create(Stream: TStream; Ownership: TStreamOwnership = soReference);
    function Write(pv: Pointer; cb: Longint; pcbWritten: PLongint): HResult; override;
    function Stat(out statstg: TStatStg; grfStatFlag: Longint): HResult; override;
    function GetModifyTime: Longint; virtual; stdcall;
    procedure SetModifyTime(Value: Longint); virtual; stdcall;
  end;

  { TIMemoryStream }

  TIMemoryStream = class(TIStreamAdapter)
  private
    function GetMemoryStream: TMemoryStream;
  public
    constructor Create(Stream: TMemoryStream; Ownership: TStreamOwnership = soReference);
    property MemoryStream: TMemoryStream read GetMemoryStream;
  end;

  { TIFileStream }

  TIFileStream = class(TStreamAdapter, IStreamModifyTime)
  private
    function GetFileStream: TFileStream;
  public
    constructor Create(const FileName: string; Mode: Word);
    function Commit(grfCommitFlags: Longint): HResult; override;
    function Stat(out statstg: TStatStg; grfStatFlag: Longint): HResult; override;
    function GetModifyTime: Longint; stdcall;
    procedure SetModifyTime(Time: Longint); stdcall;
    property FileStream: TFileStream read GetFileStream;
  end;

  { TVirtualStream }

  TVirtualStream = class(TOleStream)
  private
    FStreamModifyTime: IStreamModifyTime;
  public
    constructor Create(AStream: IStream);
    function GetModifyTime: Longint;
    procedure SetModifyTime(Time: Longint);
  end;

  TExceptionHandler = procedure;

const
  ExceptionHandler: TExceptionHandler = nil;

implementation

{ TIStreamAdapter }

constructor TIStreamAdapter.Create(Stream: TStream;
  Ownership: TStreamOwnership);
begin
  inherited Create(Stream, Ownership);
  FModifyTime := DateTimeToFileDate(Now);
end;

function TIStreamAdapter.Write(pv: Pointer; cb: Longint;
  pcbWritten: PLongint): HResult;
begin
  Result := inherited Write(pv, cb, pcbWritten);
  FModifyTime := DateTimeToFileDate(Now);
end;

function TIStreamAdapter.Stat(out statstg: TStatStg; grfStatFlag: Longint): HResult;
var
  DosFileTime: Longint;
  LocalFileTime: TFileTime;
begin
  Result := inherited Stat(statstg, grfStatFlag);
  if Result <> 0 then Exit;
  DosFileTime := GetModifyTime;
  DosDateTimeToFileTime(LongRec(DosFileTime).Hi, LongRec(DosFileTime).Lo, LocalFileTime);
  LocalFileTimeToFileTime(LocalFileTime, statstg.mtime);
end;

function TIStreamAdapter.GetModifyTime: Longint;
begin
  Result := FModifyTime;
end;

procedure TIStreamAdapter.SetModifyTime(Value: Longint);
begin
  FModifyTime := Value;
end;

{ TIMemoryStream }

constructor TIMemoryStream.Create(Stream: TMemoryStream;
  Ownership: TStreamOwnership);
begin
  if Stream = nil then
  begin
    Ownership := soOwned;
    Stream := TMemoryStream.Create;
  end;
  inherited Create(Stream, Ownership);
end;

function TIMemoryStream.GetMemoryStream: TMemoryStream;
begin
  Result := TMemoryStream(Stream);
end;

{ TIFileStream }

constructor TIFileStream.Create(const FileName: string; Mode: Word);
begin
  inherited Create(TFileStream.Create(FileName, Mode), soOwned);
end;

function TIFileStream.GetFileStream: TFileStream;
begin
  Result := TFileStream(Stream);
end;

function TIFileStream.Stat(out statstg: TStatStg; grfStatFlag: Longint): HResult;
begin
  Result := inherited Stat(statstg, grfStatFlag);
  if Result <> 0 then Exit;
  GetFileTime(TFileStream(Stream).Handle, @statstg.ctime, @statstg.atime, @statstg.mtime);
end;

function TIFileStream.GetModifyTime: Longint;
begin
  Result := FileGetDate(FileStream.Handle);
end;

procedure TIFileStream.SetModifyTime(Time: Longint);
begin
  FileSetDate(FileStream.Handle, Time);
end;

function TIFileStream.Commit(grfCommitFlags: Longint): HResult;
begin
  FlushFileBuffers(FileStream.Handle);
  Result := inherited Commit(grfCommitFlags);
end;

{ TVirtualStream }

constructor TVirtualStream.Create(AStream: IStream);
begin
  inherited Create(AStream);
  if AStream.QueryInterface(IStreamModifyTime, FStreamModifyTime) <> 0 then
    FStreamModifyTime := nil;
end;

function TVirtualStream.GetModifyTime: Longint;
begin
  if FStreamModifyTime <> nil then
    Result := FStreamModifyTime.GetModifyTime
  else
    Result := 0;
end;

procedure TVirtualStream.SetModifyTime(Time: Longint);
begin
  if FStreamModifyTime <> nil then
    FStreamModifyTime.SetModifyTime(Time);
end;

end.

