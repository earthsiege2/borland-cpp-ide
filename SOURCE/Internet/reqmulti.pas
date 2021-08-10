
{*******************************************************}
{                                                       }
{       Borland Delphi Visual Component Library         }
{       Web server application components               }
{                                                       }
{ Copyright (c) 2000-2001, Borland Software Corporation }
{                                                       }
{*******************************************************}

// Parse a multipart form data request which may contain
// uploaded files.  use ReqMulti to register this parser.

unit ReqMulti;

interface

uses SysUtils, Classes, Masks, Contnrs, HTTPApp,
  ReqFiles, HTTPParse;

type

{ TMultipartContentParser }

  TMultipartContentParser = class(TAbstractContentParser)
  private
    FContentFields: TStrings;
    FFiles: TWebRequestFiles;
    FContentBuffer: string;
  protected
    function GetContentFields: TStrings; override;
    function GetFiles: TAbstractWebRequestFiles; override;

    procedure ExtractContentTypeFields(Strings: TStrings);
    procedure ParseMultiPartContent;
    procedure ParseMultiPart(Part: Pointer; Size: Integer);
    procedure BufferContent;
    procedure ParseMultipartHeaders(Parser: THTTPParser; AContent: Pointer;
      AContentLength: Integer);
    procedure ExtractMultipartContentFields;
  public
    destructor Destroy; override;
    class function CanParse(AWebRequest: TWebRequest): Boolean; override;
  end;

implementation

uses WebConst, WebComp, BrkrConst;

const
  sMultiPartFormData = 'multipart/form-data';

function IsMultipartForm(ARequest: TWebRequest): Boolean;
begin
  Result := CompareText(Copy(ARequest.ContentType, 1, Length(sMultiPartFormData)), sMultiPartFormData) = 0;
end;

{ TMultipartContentParser }

destructor TMultipartContentParser.Destroy;
begin
  FContentFields.Free;
  FFiles.Free;
  inherited Destroy;
end;

procedure TMultipartContentParser.BufferContent;
var
  L, R: Integer;
  P: PChar;
begin
  if (WebRequest.ContentLength > 0) and (FContentBuffer = '') then
  begin
    FContentBuffer := WebRequest.Content;
    if Length(WebRequest.Content) < WebRequest.ContentLength then
    begin
      L := Length(FContentBuffer);
      SetLength(FContentBuffer, WebRequest.ContentLength);
      P := PChar(FContentBuffer) + L;
      while L < WebRequest.ContentLength do
      begin
        R := WebRequest.ReadClient(P^, WebRequest.ContentLength - L);
        if R = 0 then break;
        Inc(L, R);
        Inc(P, R);
      end;
    end;
  end;
end;

procedure TMultipartContentParser.ExtractMultipartContentFields;
begin
  if WebRequest.ContentLength > 0 then
  begin
    BufferContent;
    ParseMultiPartContent;
  end;
end;

procedure TMultipartContentParser.ExtractContentTypeFields(Strings: TStrings);
var
  S: string;
begin
  S := WebRequest.ContentType;
  ExtractHeaderFields([';'], [' '], PChar(S), Strings, True, True);
end;


procedure TMultipartContentParser.ParseMultiPartContent;
type
  TMultipartBoundaries = array of Integer;

  function FindBoundaries(const Boundary: string): TMultipartBoundaries;
  var
    P1: Integer;
    C1: Char;
    I: Integer;
    Boundaries: TMultipartBoundaries;
    Count: Integer;
    SaveChar: array of Char;
  begin
    Count := 0;
    P1 := Pos(Boundary, FContentBuffer);
    while P1 > 0 do
    begin
      C1 := FContentBuffer[P1];
      FContentBuffer[P1] := #0;
      Inc(Count);
      SetLength(SaveChar, Count);
      SetLength(Boundaries, Count);
      SaveChar[Count-1] := C1;
      Boundaries[Count-1] := P1;
      P1 := Pos(Boundary, FContentBuffer);
    end;
    for I := Low(Boundaries) to High(Boundaries) do
    begin
      FContentBuffer[Boundaries[I]] := SaveChar[I];
    end;
    Result := Boundaries;
  end;
var
  ContentTypeFields: TStrings;
  Boundaries: TMultipartBoundaries;
  Boundary: string;
  I: Integer;
  P: Integer;
begin
  SetLength(Boundaries, 0);
  ContentTypeFields := TStringList.Create;
  try
    ExtractContentTypeFields(ContentTypeFields);
    Boundary := ContentTypeFields.Values['boundary'];
    if Boundary <> '' then
      Boundary := '--' + Boundary;
  finally
    ContentTypeFields.Free;
  end;
  if Boundary = '' then
    Exit;
  Boundaries := FindBoundaries(Boundary);
  for I := Low(Boundaries) to High(Boundaries)-1 do
  begin
    P := Boundaries[I] + Length(Boundary) + 2;
    ParseMultiPart(Pointer(@FContentBuffer[P]),
      Boundaries[I+1] - P);
  end;
end;

procedure TMultipartContentParser.ParseMultipartHeaders(Parser: THTTPParser;
  AContent: Pointer; AContentLength: Integer);
var
  PartContentType: string;
  PartFileName: string;
  PartName: string;
  ContentDisposition: string;

  procedure SkipLine;
  begin
    Parser.CopyToEOL;
    Parser.SkipEOL;
  end;

  procedure ParseContentType;
  begin
    with Parser do
    begin
      NextToken;
      if Token = ':' then NextToken;
      if PartContentType = '' then
        PartContentType := TrimLeft(CopyToEOL)
      else CopyToEOL;
      NextToken;
    end;
  end;

  procedure ExtractContentDispositionFields;
  var
    S: string;
    Strings: TSTrings;
  begin
    S := ContentDisposition;
    Strings := TStringList.Create;
    try
      ExtractHeaderFields([';'], [' '], PChar(S), Strings, True, True);
      PartName := Strings.Values['name'];
      PartFileName := Strings.Values['filename'];
    finally
      Strings.Free;
    end;
  end;

  procedure ParseContentDisposition;
  begin
    with Parser do
    begin
      NextToken;
      if Token = ':' then NextToken;
      if ContentDisposition = '' then
        ContentDisposition := TrimLeft(CopyToEOL)
      else CopyToEOL;
      NextToken;
      ExtractContentDispositionFields;
    end;
  end;

var
  Temp: string;
begin
  while Parser.Token <> toEOF do with Parser do
  begin
    case Token of
      toContentType: ParseContentType;
      toContentDisposition: ParseContentDisposition;
      toEOL: Break; // At content
    else
      SkipLine;
    end;
  end;
  if PartName <> '' then
  begin
    if PartFileName <> '' then
    begin
      // Note.  Filename is not added as content field
      // FContentFields.Add(PartName + '=' + PartFileName);
      if FFiles = nil then
        FFiles := TWebRequestFiles.Create;
      FFiles.Add(PartName, PartFileName, PartContentType,
        AContent, AContentLength);
    end
    else if PartContentType = '' then
    begin
      Temp := '';
      if AContentLength > 0 then
      begin
        Assert(AContentLength >= 2);
        SetString(Temp, PChar(AContent), AContentLength-2);  // Exclude ch/lf
      end;
      FContentFields.Add(PartName + '=' + Temp);
    end
  end;
end;

procedure TMultipartContentParser.ParseMultiPart(Part: Pointer; Size: Integer);
var
  P: PChar;
  S: TStream;
  L: Integer;
  Parser: THTTPParser;
begin
  P := StrPos(PChar(Part), #13#10#13#10);
  if P <> nil then
  begin
    L := P-Part+4;
    S := TWebRequestFileStream.Create(Part, L);
    try
      Parser := THTTPParser.Create(S);
      try
        ParseMultiPartHeaders(Parser, PChar(Part) + L, Size-L);
      finally
        Parser.Free;
      end;
    finally
      S.Free;
    end;
  end;
end;

function TMultipartContentParser.GetContentFields: TStrings;
begin
  if FContentFields = nil then
  begin
    FContentFields := TStringList.Create;
    if IsMultiPartForm(WebRequest) then
      ExtractMultipartContentFields
    else
      WebRequest.ExtractContentFields(FContentFields);
  end;
  Result := FContentFields;
end;

function TMultipartContentParser.GetFiles: TAbstractWebRequestFiles;
begin
  GetContentFields;
  if FFiles = nil then
    FFiles := TWebRequestFiles.Create;
  Result := FFiles;
end;

class function TMultipartContentParser.CanParse(
  AWebRequest: TWebRequest): Boolean;
begin
  Result := IsMultipartForm(AWebRequest);
end;

initialization
  RegisterContentParser(TMultipartContentParser);
end.
