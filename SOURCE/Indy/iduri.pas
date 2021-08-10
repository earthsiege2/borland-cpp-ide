unit IdURI;

interface

type
  TIdURI = class
  protected
    FDocument: string;
    FProtocol: string;
    FURI: string;
    FPort: string;
    Fpath: string;
    FHost: string;
    FBookmark: string;
    procedure SetHost(const Value: string);
    procedure SetDocument(const Value: string);
    procedure SetBookmark(const Value: string);
    procedure Setpath(const Value: string);
    procedure SetPort(const Value: string);
    procedure SetProtocol(const Value: string);
    procedure SetURI(const Value: string);
    procedure Refresh;
  public
    class procedure NormalizePath(var APath: string);
    class procedure ParseURI(URI: string; var Protocol, Host, path, Document,
      Port, Bookmark: string);
    constructor Create(const AURI: string = ''); virtual;
    property Protocol: string read FProtocol write SetProtocol;
    property Path: string read Fpath write Setpath;
    property Host: string read FHost write SetHost;
    property Document: string read FDocument write SetDocument;
    property Port: string read FPort write SetPort;
    property URI: string read FURI write SetURI;
    property Bookmark: string read FBookmark write SetBookmark;
  end;

implementation

uses
  IdGlobal, IdResourceStrings,
  SysUtils;

constructor TIdURI.Create(const AURI: string = '');
begin
  if length(AURI) > 0 then
  begin
    URI := AURI;
  end;
end;

class procedure TIdURI.NormalizePath(var APath: string);
var
  i: Integer;
begin
  i := 1;
  while i <= Length(APath) do
  begin
    if APath[i] in LeadBytes then
    begin
      inc(i, 2)
    end
    else
      if APath[i] = '\' then
    begin
      APath[i] := '/';
      inc(i, 1);
    end
    else
    begin
      inc(i, 1);
    end;
  end;
end;

class procedure TIdURI.ParseURI(URI: string; var Protocol, Host, path, Document,
  Port, Bookmark: string);
var
  sBuffer: string;
  iTokenPos: Integer;
begin
  Host := '';
  Protocol := '';
  Path := '';
  Document := '';
  NormalizePath(URI);
  if IndyPos('://', URI) > 0 then
  begin
    iTokenPos := IndyPos('://', URI);
    Protocol := Copy(URI, 1, iTokenPos - 1);
    Delete(URI, 1, iTokenPos + 2);
    sBuffer := fetch(URI, '/', true);
    Host := fetch(sBuffer, ':', true);
    Port := sBuffer;
    iTokenPos := RPos('/', URI, -1);
    Path := Copy(URI, 1, iTokenPos);
    Delete(URI, 1, iTokenPos);
    Document := URI;
  end
  else
  begin
    iTokenPos := RPos('/', URI, -1);
    Path := Copy(URI, 1, iTokenPos);
    Delete(URI, 1, iTokenPos);
    Document := URI;
  end;

  if Copy(Path, 1, 1) <> '/' then
  begin
    Path := '/' + Path;
  end;
  sBuffer := Fetch(Document, '#');
  Bookmark := Document;
  Document := sBuffer;
end;

procedure TIdURI.Refresh;
begin
  FURI := FProtocol + '://' + FHost;
  if Length(FPort) > 0 then
    FURI := FURI + ':' + FPort;
  FURI := FURI + FPath + FDocument;
  if Length(FBookmark) > 0 then
    FURI := FURI + '#' + FBookmark;
end;

procedure TIdURI.SetBookmark(const Value: string);
begin
  FBookmark := Value;
  Refresh;
end;

procedure TIdURI.SetDocument(const Value: string);
begin
  FDocument := Value;
  Refresh;
end;

procedure TIdURI.SetHost(const Value: string);
begin
  FHost := Value;
  Refresh;
end;

procedure TIdURI.Setpath(const Value: string);
begin
  Fpath := Value;
  Refresh;
end;

procedure TIdURI.SetPort(const Value: string);
begin
  FPort := Value;
  Refresh;
end;

procedure TIdURI.SetProtocol(const Value: string);
begin
  FProtocol := Value;
  Refresh;
end;

procedure TIdURI.SetURI(const Value: string);
begin
  FURI := Value;
  NormalizePath(FURI);
  ParseURI(FURI, FProtocol, FHost, FPath, FDocument, FPort, FBookmark);
end;

end.
