{ *************************************************************************** }
{                                                                             }
{ Delphi and Kylix Cross-Platform Visual Component Library                    }
{                                                                             }
{ Copyright (c) 2000, 2001 Borland Software Corporation                       }
{                                                                             }
{ *************************************************************************** }


unit QClipbrd;

{$R-,T-,H+,X+}

interface

uses
  SysUtils, Classes, Qt, QTypes, QConsts, QGraphics;

type
  TClipboard = class(TPersistent)
  private
    FCachedProvidesFormat: string;
    FCachedText: WideString;
    FHandle: QClipboardH;
    FHook: QClipboard_hookH;
    FCachedProvidesResponse: Boolean;
    FCachedTextValid: Boolean;
    procedure ClearCache;
    procedure ClipboardChangedNotification; cdecl;
    procedure AssignGraphic(Source: TGraphic);
    procedure AssignPicture(Source: TPicture);
    procedure AssignMimeSource(Source: TMimeSource);
    procedure AssignToBitmap(Dest: TBitmap);
    procedure AssignToPicture(Dest: TPicture);
    function GetAsText: WideString;
    procedure SetAsText(const Value: WideString);
    function GetHandle: QClipboardH;
  protected
    procedure AssignTo(Dest: TPersistent); override;
  public
    destructor Destroy; override;
    function AddFormat(const Format: string; Stream: TStream): Boolean;
    procedure Assign(Source: TPersistent); override;
    procedure Clear;
    function GetComponent(Owner, Parent: TComponent): TComponent;
    function GetFormat(const Format: string; Stream: TStream): Boolean;
    procedure SetFormat(const Format: string; Stream: TStream);
    function Provides(const Format: string): Boolean;
    function RegisterClipboardFormat(const Format: string): Integer;
    procedure SetComponent(Component: TComponent);
    procedure SupportedFormats(List: TStrings);
    property AsText: WideString read GetAsText write SetAsText;
    property Handle: QClipboardH read GetHandle;
  end;

function Clipboard: TClipboard;
function SetClipboard(NewClipboard: TClipboard): TClipboard;

implementation

var
  FClipboard: TClipboard = nil;

function Clipboard: TClipboard;
begin
  if not Assigned(FClipboard) then
    FClipboard := TClipboard.Create;
  Result := FClipboard;
end;

function SetClipboard(NewClipboard: TClipboard): TClipboard;
begin
  Result := FClipboard;
  FClipboard := NewClipboard;
end;

{ TClipboard }

destructor TClipboard.Destroy; 
begin
  QClipboard_hook_destroy(FHook);
  inherited;
end;

function TClipboard.AddFormat(const Format: string; Stream: TStream): Boolean;
var
  Temp: TClxMimeSource;
begin
  Temp := TClxMimeSource.Create(QClxMimeSource_create(QClipboard_data(Handle)));
  try
    Temp.LoadFromStream(Stream, Format);
    Clear;
    QClipboard_setData(Handle, Temp.Handle);
    Result := True;
  finally
    Temp.ReleaseHandle;
    Temp.Free;
  end;
end;

procedure TClipboard.Assign(Source: TPersistent);
begin
  if Source is TPicture then
    AssignPicture(TPicture(Source))
  else if Source is TGraphic then
    AssignGraphic(TGraphic(Source))
  else if Source is TMimeSource then
    AssignMimeSource(TMimeSource(Source))
  else
    inherited Assign(Source);
end;

procedure TClipboard.AssignGraphic(Source: TGraphic);
var
  MimeSource: TClxMimeSource;
begin
  MimeSource := nil;
  try
    MimeSource := TClxMimeSource.Create;
    Source.SaveToMimeSource(MimeSource);
    QClipboard_setData(Handle, MimeSource.Handle);
  finally
    MimeSource.Free;
  end;
end;

procedure TClipboard.AssignMimeSource(Source: TMimeSource);
begin
  QClipboard_setData(Handle, Source.Handle);
end;

procedure TClipboard.AssignPicture(Source: TPicture);
var
  MimeSource: TClxMimeSource;
begin
  MimeSource := nil;
  try
    MimeSource := TClxMimeSource.Create;
    Source.SaveToMimeSource(MimeSource);
    QClipboard_setData(Handle, MimeSource.Handle);
  finally
    MimeSource.Free;
  end;
end;

procedure TClipboard.AssignTo(Dest: TPersistent);
begin
  if Dest is TPicture then
    AssignToPicture(TPicture(Dest))
  else if Dest is TBitmap then
    AssignToBitmap(TBitmap(Dest))
  else
    inherited AssignTo(Dest);
end;

procedure TClipboard.AssignToBitmap(Dest: TBitmap);
var
  MimeSource: TMimeSource;
  Stream: TMemoryStream;
begin
  MimeSource := TMimeSource.Create(QClipboard_data(Handle));
  try
    if MimeSource.Provides(SDelphiBitmap) then
    begin
      Stream := TMemoryStream.Create;
      try
        MimeSource.SaveToStream(SDelphiBitmap, Stream);
        Stream.Position := 0;
        Dest.LoadFromStream(Stream);
      finally
        Stream.Free;
      end;
    end;
  finally
    MimeSource.Free;
  end;
end;

procedure TClipboard.AssignToPicture(Dest: TPicture);
var
  MimeSource: TMimeSource;
  Stream: TMemoryStream;
begin
  MimeSource := TMimeSource.Create(QClipboard_data(Handle));
  try
    if MimeSource.Provides(SDelphiPicture) then
    begin
      Stream := TMemoryStream.Create;
      try
        MimeSource.SaveToStream(SDelphiPicture, Stream);
        Stream.Position := 0;
        Dest.Graphic.LoadFromStream(Stream);
      finally
        Stream.Free;
      end;
    end;
  finally
    MimeSource.Free;
  end;
end;

procedure TClipboard.Clear;
begin
  QClipboard_clear(Handle);
end;

procedure TClipboard.ClearCache;
begin
  FCachedProvidesFormat := '';
  FCachedText := '';
  FCachedTextValid := False;
end;

procedure TClipboard.ClipboardChangedNotification; cdecl;
begin
  ClearCache;
end;

function TClipboard.GetAsText: WideString;
begin
  if not FCachedTextValid then
  begin
    QClipboard_text(Handle, PWideString(@FCachedText));
    FCachedTextValid := True;
  end;
  Result := FCachedText;
end;

function TClipboard.GetComponent(Owner, Parent: TComponent): TComponent;
var
  Stream: TMemoryStream;
  Reader: TReader;
begin
  Result := nil;
  Stream := nil;
  try
    Stream := TMemoryStream.Create;
    if GetFormat(SDelphiComponent, Stream) then
    begin
      Stream.Position := 0;
      Reader := TReader.Create(Stream, 256);
      try
        Reader.Parent := Parent;
        Result := Reader.ReadRootComponent(nil);
        try
          if Owner <> nil then
            Owner.InsertComponent(Result);
        except
          Result.Free;
          raise;
        end;
      finally
        Reader.Free;
      end;
    end;
  finally
    Stream.Free;
  end;
end;

function TClipboard.GetFormat(const Format: string; Stream: TStream): Boolean;
begin
  with TMimeSource.Create(QClipboard_data(Handle)) do
  begin
    Result := SaveToStream(Format, Stream);
    Free;
  end;
end;

function TClipboard.GetHandle: QClipboardH;
var
  ChangedEvent: QClipboard_dataChanged_Event;
begin
  if FHandle = nil then
  begin
    FHandle := QApplication_clipboard;
    FHook := QClipboard_hook_create(FHandle);
    ChangedEvent := ClipboardChangedNotification;
    QClipboard_hook_hook_dataChanged(FHook, TMethod(ChangedEvent));
  end;
  Result := FHandle;
end;

function TClipboard.Provides(const Format: string): Boolean;
begin
  if Format <> FCachedProvidesFormat then
  begin
    FCachedProvidesFormat := Format;
    FCachedProvidesResponse := QMimeSource_provides(QClipboard_data(Handle),
      PChar(Format));
  end;
  Result := FCachedProvidesResponse;
end;

function TClipboard.RegisterClipboardFormat(const Format: string): Integer;
begin
{$IFDEF MSWINDOWS}
  Result := QWindowsMime_registerMimeType(PChar(Format));
{$ELSE}
  Result := -1;
{$ENDIF}
end;

procedure TClipboard.SetAsText(const Value: WideString);
begin
  QClipboard_setText(Handle, PWideString(@Value));
  ClearCache;
end;

procedure TClipboard.SetComponent(Component: TComponent);
var
  Stream: TMemoryStream;
  MimeSource: TClxMimeSource;
begin
  Stream := TMemoryStream.Create;
  try
    Stream.WriteComponent(Component);
    Stream.Position := 0;
    MimeSource := TClxMimeSource.Create(SDelphiComponent, Stream);
    try
      QClipboard_setData(Handle, MimeSource.Handle);
      ClearCache;
    finally
      MimeSource.Free;
    end;
  finally
    Stream.Free;
  end;
end;

procedure TClipboard.SetFormat(const Format: string; Stream: TStream);
var
  MimeSource: TClxMimeSource;
begin
  Clear;
  MimeSource := TClxMimeSource.Create(Format, Stream);
  try
    QClipboard_setData(Handle, MimeSource.Handle);
    ClearCache;
  finally
    MimeSource.ReleaseHandle;
    MimeSource.Free;
  end;
end;

procedure TClipboard.SupportedFormats(List: TStrings);
begin
  with TMimeSource.Create(QClipboard_data(Handle)) do
  try
    SupportedFormats(List);
  finally
    Free;
  end;
end;

initialization
{$IFDEF MSWINDOWS}
  QWindowsMime_registerMimeType(SDelphiComponent);
  QWindowsMime_registerMimeType(SDelphiBitmap);
  QWindowsMime_registerMimeType(SDelphiPicture);
  QWindowsMime_registerMimeType(SDelphiDrawing);
{$ENDIF}

finalization
  FClipboard.Free;

end.
