
{*******************************************************}
{                                                       }
{       Borland Delphi Visual Component Library         }
{       Parser object to allow on-the-fly parsing and   }
{       text insertion                                  }
{                                                       }
{       Copyright (c) 1997,99 Inprise Corporation       }
{                                                       }
{*******************************************************}

unit CopyPrsr;

interface

uses Classes;

const
  toEOL = Char(5);

type
{ TCopyParser }

  TCopyParser = class(TObject)
  private
    FStream: TStream;
    FOutStream: TStream;
    FOrigin: Longint;
    FBuffer: PChar;
    FBufPtr: PChar;
    FBufEnd: PChar;
    FSourcePtr: PChar;
    FSourceEnd: PChar;
    FTokenPtr: PChar;
    FStringPtr: PChar;
    FSourceLine: Integer;
    FSaveChar: Char;
    FToken: Char;
    procedure ReadBuffer;
    procedure SkipBlanks(DoCopy: Boolean);
    function SkipToNextToken(CopyBlanks, DoCopy: Boolean): Char;
    function CopySkipTo(Length: Integer; DoCopy: Boolean): string;
    function CopySkipToToken(AToken: Char; DoCopy: Boolean): string;
    function CopySkipToEOL(DoCopy: Boolean): string;
    function CopySkipToEOF(DoCopy: Boolean): string;
    procedure UpdateOutStream(StartPos: PChar);
  public
    constructor Create(Stream, OutStream: TStream);
    destructor Destroy; override;
    procedure CheckToken(T: Char);
    procedure CheckTokenSymbol(const S: string);
    function CopyTo(Length: Integer): string;
    function CopyToToken(AToken: Char): string;
    function CopyToEOL: string;
    function CopyToEOF: string;
    procedure CopyTokenToOutput;
    procedure Error(const Ident: string);
    procedure ErrorFmt(const Ident: string; const Args: array of const);
    procedure ErrorStr(const Message: string);
    function NextToken: Char;
    function SkipToken(CopyBlanks: Boolean): Char;
    procedure SkipEOL;
    function SkipTo(Length: Integer): string;
    function SkipToToken(AToken: Char): string;
    function SkipToEOL: string;
    function SkipToEOF: string;
    function SourcePos: Longint;
    function TokenComponentIdent: String;
    function TokenFloat: Extended;
    function TokenInt: Longint;
    function TokenString: string;
    function TokenSymbolIs(const S: string): Boolean;
    property SourceLine: Integer read FSourceLine;
    property Token: Char read FToken;
  end;

implementation

uses SysUtils, Consts;

{ TCopyParser }

const
  ParseBufSize = 4096;

constructor TCopyParser.Create(Stream, OutStream: TStream);
begin
  FStream := Stream;
  FOutStream := OutStream;
  GetMem(FBuffer, ParseBufSize);
  FBuffer[0] := #0;
  FBufPtr := FBuffer;
  FBufEnd := FBuffer + ParseBufSize;
  FSourcePtr := FBuffer;
  FSourceEnd := FBuffer;
  FTokenPtr := FBuffer;
  FSourceLine := 1;
  SkipToken(True);
end;

destructor TCopyParser.Destroy;
begin
  if FBuffer <> nil then
  begin
    FStream.Seek(Longint(FTokenPtr) - Longint(FBufPtr), 1);
    FreeMem(FBuffer, ParseBufSize);
  end;
end;

procedure TCopyParser.CheckToken(T: Char);
begin
  if Token <> T then
    case T of
      toSymbol:
        Error(SIdentifierExpected);
      toString:
        Error(SStringExpected);
      toInteger, toFloat:
        Error(SNumberExpected);
    else
      ErrorFmt(SCharExpected, [T]);
    end;
end;

procedure TCopyParser.CheckTokenSymbol(const S: string);
begin
  if not TokenSymbolIs(S) then ErrorFmt(SSymbolExpected, [S]);
end;

function TCopyParser.CopySkipTo(Length: Integer; DoCopy: Boolean): string;
var
  P: PChar;
  Temp: string;
begin
  Result := '';
  repeat
    P := FTokenPtr;
    while (Length > 0) and (P^ <> #0) do
    begin
      Inc(P);
      Dec(Length);
    end;
    if DoCopy and (FOutStream <> nil) then
        FOutStream.WriteBuffer(FTokenPtr^, P - FTokenPtr);
    SetString(Temp, FTokenPtr, P - FTokenPtr);
    Result := Result + Temp;
    if Length > 0 then ReadBuffer;
  until (Length = 0) or (Token = toEOF);
  FSourcePtr := P;
end;

function TCopyParser.CopySkipToEOL(DoCopy: Boolean): string;
var
  P: PChar;
begin
  P := FTokenPtr;
  while not (P^ in [#13, #10, #0]) do Inc(P);
  SetString(Result, FTokenPtr, P - FTokenPtr);
  if P^ = #13 then Inc(P);
  FSourcePtr := P;
  if DoCopy then UpdateOutStream(FTokenPtr);
  NextToken;
end;

function TCopyParser.CopySkipToEOF(DoCopy: Boolean): string;
var
  P: PChar;
  Temp: string;
begin
  repeat
    P := FTokenPtr;
    while P^ <> #0 do Inc(P);
    FSourcePtr := P;
    SetString(Temp, FTokenPtr, P - FTokenPtr);
    Result := Result + Temp;
    if DoCopy then
    begin
      UpdateOutStream(FTokenPtr);
      NextToken;
    end else SkipToken(False);
    FTokenPtr := FSourcePtr;
  until Token = toEOF;
end;

function TCopyParser.CopySkipToToken(AToken: Char; DoCopy: Boolean): string;
var
  S: PChar;
  Temp: string;

  procedure InternalSkipBlanks;
  begin
    while True do
    begin
      case FSourcePtr^ of
        #0:
          begin
            SetString(Temp, S, FSourcePtr - S);
            Result := Result + Temp;
            if DoCopy then UpdateOutStream(S);
            ReadBuffer;
            if FSourcePtr^ = #0 then Exit;
            S := FSourcePtr;
            Continue;
          end;
        #10:
          Inc(FSourceLine);
        #33..#255:
          Break;
      end;
      Inc(FSourcePtr);
    end;
    if DoCopy then UpdateOutStream(S);
  end;

begin
  Result := '';
  while (Token <> AToken) and (Token <> toEOF) do
  begin
    S := FSourcePtr;
    InternalSkipBlanks;
    if S <> FSourcePtr then
    begin
      SetString(Temp, S, FSourcePtr - S);
      Result := Result + Temp;
    end;
    SkipToNextToken(DoCopy, DoCopy);
    if Token <> AToken then
    begin
      SetString(Temp, FTokenPtr, FSourcePtr - FTokenPtr);
      Result := Result + Temp;
    end;
  end;
end;

function TCopyParser.CopyTo(Length: Integer): string;
begin
  Result := CopySkipTo(Length, True);
end;

function TCopyParser.CopyToToken(AToken: Char): string;
begin
  Result := CopySkipToToken(AToken, True);
end;

function TCopyParser.CopyToEOL: string;
begin
  Result := CopySkipToEOL(True);
end;

function TCopyParser.CopyToEOF: string;
begin
  Result := CopySkipToEOF(True);
end;

procedure TCopyParser.CopyTokenToOutput;
begin
  UpdateOutStream(FTokenPtr);
end;

procedure TCopyParser.Error(const Ident: string);
begin
  ErrorStr(Ident);
end;

procedure TCopyParser.ErrorFmt(const Ident: string; const Args: array of const);
begin
  ErrorStr(Format(Ident, Args));
end;

procedure TCopyParser.ErrorStr(const Message: string);
begin
  raise EParserError.CreateResFmt(@SParseError, [Message, FSourceLine]);
end;

function TCopyParser.NextToken: Char;
begin
  Result := SkipToNextToken(True, True);
end;

function TCopyParser.SkipTo(Length: Integer): string;
begin
  Result := CopySkipTo(Length, False);
end;

function TCopyParser.SkipToToken(AToken: Char): string;
begin
  Result := CopySkipToToken(AToken, False);
end;

function TCopyParser.SkipToEOL: string;
begin
  Result := CopySkipToEOL(False);
end;

function TCopyParser.SkipToEOF: string;
begin
  Result := CopySkipToEOF(False);
end;

function TCopyParser.SkipToNextToken(CopyBlanks, DoCopy: Boolean): Char;
var
  P, StartPos: PChar;
begin
  SkipBlanks(CopyBlanks);
  P := FSourcePtr;
  FTokenPtr := P;
  case P^ of
    'A'..'Z', 'a'..'z', '_':
      begin
        Inc(P);
        while P^ in ['A'..'Z', 'a'..'z', '0'..'9', '_'] do Inc(P);
        Result := toSymbol;
      end;
    #10:
      begin
        Inc(P);
        Inc(FSourceLine);
        Result := toEOL;
      end;
  else
    Result := P^;
    if Result <> toEOF then Inc(P);
  end;
  StartPos := FSourcePtr;
  FSourcePtr := P;
  if DoCopy then UpdateOutStream(StartPos);
  FToken := Result;
end;

function TCopyParser.SkipToken(CopyBlanks: Boolean): Char;
begin
  Result := SkipToNextToken(CopyBlanks, False);
end;

procedure TCopyParser.ReadBuffer;
var
  Count: Integer;
begin
  Inc(FOrigin, FSourcePtr - FBuffer);
  FSourceEnd[0] := FSaveChar;
  Count := FBufPtr - FSourcePtr;
  if Count <> 0 then Move(FSourcePtr[0], FBuffer[0], Count);
  FBufPtr := FBuffer + Count;
  Inc(FBufPtr, FStream.Read(FBufPtr[0], FBufEnd - FBufPtr));
  FSourcePtr := FBuffer;
  FSourceEnd := FBufPtr;
  if FSourceEnd = FBufEnd then
  begin
    FSourceEnd := LineStart(FBuffer, FSourceEnd - 1);
    if FSourceEnd = FBuffer then Error(SLineTooLong);
  end;
  FSaveChar := FSourceEnd[0];
  FSourceEnd[0] := #0;
end;

procedure TCopyParser.SkipBlanks(DoCopy: Boolean);
var
  Start: PChar;
begin
  Start := FSourcePtr;
  while True do
  begin
    case FSourcePtr^ of
      #0:
        begin
          if DoCopy then UpdateOutStream(Start);
          ReadBuffer;
          if FSourcePtr^ = #0 then Exit;
          Start := FSourcePtr;
          Continue;
        end;
      #10:
        Inc(FSourceLine);
      #33..#255:
        Break;
    end;
    Inc(FSourcePtr);
  end;
  if DoCopy then UpdateOutStream(Start);
end;

function TCopyParser.SourcePos: Longint;
begin
  Result := FOrigin + (FTokenPtr - FBuffer);
end;

procedure TCopyParser.SkipEOL;
begin
  if Token = toEOL then
  begin
    while FTokenPtr^ in [#13, #10] do Inc(FTokenPtr);
    FSourcePtr := FTokenPtr;
    if FSourcePtr^ <> #0 then
      NextToken
    else FToken := #0;
  end;
end;

function TCopyParser.TokenFloat: Extended;
begin
  Result := StrToFloat(TokenString);
end;

function TCopyParser.TokenInt: Longint;
begin
  Result := StrToInt(TokenString);
end;

function TCopyParser.TokenString: string;
var
  L: Integer;
begin
  if FToken = toString then
    L := FStringPtr - FTokenPtr else
    L := FSourcePtr - FTokenPtr;
  SetString(Result, FTokenPtr, L);
end;

function TCopyParser.TokenSymbolIs(const S: string): Boolean;
begin
  Result := (Token = toSymbol) and (CompareText(S, TokenString) = 0);
end;

function TCopyParser.TokenComponentIdent: String;
var
  P: PChar;
begin
  CheckToken(toSymbol);
  P := FSourcePtr;
  while P^ = '.' do
  begin
    Inc(P);
    if not (P^ in ['A'..'Z', 'a'..'z', '_']) then
      Error(SIdentifierExpected);
    repeat
      Inc(P)
    until not (P^ in ['A'..'Z', 'a'..'z', '0'..'9', '_']);
  end;
  FSourcePtr := P;
  Result := TokenString;
end;

procedure TCopyParser.UpdateOutStream(StartPos: PChar);
begin
  if FOutStream <> nil then
    FOutStream.WriteBuffer(StartPos^, FSourcePtr - StartPos);
end;

end.
