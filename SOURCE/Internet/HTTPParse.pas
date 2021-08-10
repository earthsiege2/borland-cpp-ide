{*******************************************************}
{                                                       }
{       Borland Delphi Visual Component Library         }
{       Web server application components               }
{                                                       }
{ Copyright (c) 2000, 2001 Borland Software Corporation }
{                                                       }
{*******************************************************}

// Parse an HTTP header.

unit HTTPParse;

interface

uses SysUtils, Classes;

const
  toEOL           = Char(5);
  toGET           = Char(6);
  toHEAD          = Char(7);
  toPUT           = Char(8);
  toDELETE        = Char(9);
  toPOST          = Char(10);
  toPATCH         = Char(11);
  toCOPY          = Char(12);
  toUserAgent     = Char(13);
  toAccept        = Char(14);
  toContentType   = Char(15);
  toContentLength = Char(16);
  toReferer       = Char(17);
  toAuthorization = Char(18);
  toCacheControl  = Char(19);
  toDate          = Char(20);
  toFrom          = Char(21);
  toHost          = Char(22);
  toIfModified    = Char(23);
  toContentEncoding = Char(24);
  toContentVersion= Char(25);
  toAllow         = Char(26);
  toConnection    = Char(27);
  toCookie        = Char(28);
  toContentDisposition = Char(29);

  hcGET            = $14F5;
  hcPUT            = $4AF5;
  hcDELETE         = $92B2;
  hcPOST           = $361D;
  hcCacheControl   = $4FF6;
  hcDate           = $0EE6;
  hcFrom           = $418F;
  hcHost           = $3611;
  hcIfModified     = $DDF0;
  hcAllow          = $3D80;
  hcUserAgent      = $E890;
  hcAccept         = $1844;
  hcContentEncoding= $C586;
  hcContentVersion = $EDF4;
  hcContentType    = $F0E0;
  hcContentLength  = $B0C4;
  hcReferer        = $CEA5;
  hcAuthorization  = $ABCA;
  hcConnection     = $0EDE;
  hcCookie         = $27B3;
  hcContentDisposition = $CBEB;

type

{ THTTPParser }

  THTTPParser = class(TObject)
  private
    FStream: TStream;
    FOrigin: Longint;
    FBuffer: PChar;
    FBufPtr: PChar;
    FBufEnd: PChar;
    FSourcePtr: PChar;
    FSourceEnd: PChar;
    FStringPtr: PChar;
    FSourceLine: Integer;
    FSaveChar: Char;
    FToken: Char;
    FHeaderField: Boolean;
    FTokenPtr: PChar;
    procedure ReadBuffer;
    procedure SkipBlanks;
  public
    constructor Create(Stream: TStream);
    destructor Destroy; override;
    procedure CheckToken(T: Char);
    procedure CheckTokenSymbol(const S: string);
    function CopyTo(Length: Integer): string;
    function CopyToEOL: string;
    function CopyToEOF: string;
    procedure Error(const Ident: string);
    procedure ErrorFmt(const Ident: string; const Args: array of const);
    procedure ErrorStr(const Message: string);
    procedure HexToBinary(Stream: TStream);
    function NextToken: Char;
    procedure SkipEOL;
    function SourcePos: Longint;
    function TokenFloat: Extended;
    function TokenInt: Longint;
    function TokenString: string;
    function TokenSymbolIs(const S: string): Boolean;
    function BufferRequest(Length: Integer): TStream;
    property SourceLine: Integer read FSourceLine;
    property Token: Char read FToken;
    property HeaderField: Boolean read FHeaderField write FHeaderField;
    property SourcePtr: PChar read FSourcePtr write FSourcePtr;
    property TokenPtr: PChar read FTokenPtr write FTokenPtr;
    property Stream: TStream read FStream;
    property SourceEnd: PChar read FSourceEnd;
  end;


implementation

uses RTLConsts;

const
  ParseBufSize = 4096;

{ THTTPParser }

constructor THTTPParser.Create(Stream: TStream);
begin
  FStream := Stream;
  GetMem(FBuffer, ParseBufSize);
  FBuffer[0] := #0;
  FBufPtr := FBuffer;
  FBufEnd := FBuffer + ParseBufSize;
  FSourcePtr := FBuffer;
  FSourceEnd := FBuffer;
  FTokenPtr := FBuffer;
  FSourceLine := 1;
  FHeaderField := True;

  NextToken;
 end;

function THTTPParser.BufferRequest(Length: Integer): TStream;
const
  BufSize = 1000;
var
  Buffer: array[0..BufSize-1] of byte;
  Count: Integer;
  L, R, T, C: Integer;
  P1, P2: PChar;
begin

  // Get processed contents of parser buffer
  Result := TMemoryStream.Create;
  Count := FSourcePtr - FBuffer;
  Result.Write(Pointer(FBuffer)^, Count);

  // Find end of parser buffer
  if Length > 0 then
  begin
    P1 := FSourcePtr;
    P2 := P1;
    while (P2^ <> #0) do Inc(P2);

    while Length > 0 do
    begin
      if Length > BufSize then
        L := BufSize
      else
        L := Length;
      if P1 < P2 then
      begin
        // Read from parser buffer
        if L > P2 - P1 then
          R := P2 - P1
        else
          R := L;
        Move(P1^, Buffer, R);
        L := R;
        P1 := P1 + R;
      end
      else
      begin
        T := 0;
        R := L;
        repeat
          C := FStream.Read(Buffer[T], R-T);
          T := T + C;
        until (C = 0) or (T = R);
      end;
      Result.Write(Buffer, L);
      Length := Length - R;
    end;
  end;
  Result.Seek(Count, soFromBeginning);
  FStream := Result;
end;

destructor THTTPParser.Destroy;
begin
  if FBuffer <> nil then
  begin
    FStream.Seek(Longint(FTokenPtr) - Longint(FSourceEnd), 1);
    FreeMem(FBuffer, ParseBufSize);
  end;
end;

procedure THTTPParser.CheckToken(T: Char);
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

procedure THTTPParser.CheckTokenSymbol(const S: string);
begin
  if not TokenSymbolIs(S) then ErrorFmt(SSymbolExpected, [S]);
end;

function THTTPParser.CopyTo(Length: Integer): string;
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
    SetString(Temp, FTokenPtr, P - FTokenPtr);
    Result := Result + Temp;
    if Length > 0 then ReadBuffer;
  until (Length = 0) or (Token = toEOF);
  FSourcePtr := P;
end;

function THTTPParser.CopyToEOL: string;
var
  P: PChar;
begin
  P := FTokenPtr;
  while not (P^ in [#13, #10, #0]) do Inc(P);
  SetString(Result, FTokenPtr, P - FTokenPtr);
  if P^ = #13 then Inc(P);
  FSourcePtr := P;
  if P^ <> #0 then
    NextToken
  else
    FToken := #0;
end;

function THTTPParser.CopyToEOF: string;
var
  P: PChar;
  Temp: string;
begin
  repeat
    P := FTokenPtr;
    while P^ <> #0 do Inc(P);
    FSourcePtr := P;
    ReadBuffer;
    SetString(Temp, FTokenPtr, P - FTokenPtr);
    Result := Result + Temp;
    NextToken;
  until Token = toEOF;
end;

procedure THTTPParser.Error(const Ident: string);
begin
  ErrorStr(Ident);
end;

procedure THTTPParser.ErrorFmt(const Ident: string; const Args: array of const);
begin
  ErrorStr(Format(Ident, Args));
end;

procedure THTTPParser.ErrorStr(const Message: string);
begin
  raise EParserError.CreateResFmt(@SParseError, [Message, FSourceLine]);
end;

procedure THTTPParser.HexToBinary(Stream: TStream);
var
  Count: Integer;
  Buffer: array[0..255] of Char;
begin
  SkipBlanks;
  while FSourcePtr^ <> '}' do
  begin
    Count := HexToBin(FSourcePtr, Buffer, SizeOf(Buffer));
    if Count = 0 then Error(SInvalidBinary);
    Stream.Write(Buffer, Count);
    Inc(FSourcePtr, Count * 2);
    SkipBlanks;
  end;
  NextToken;
end;

const
  CharValue: array[Byte] of Byte = (
    $00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,
    $00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,
    $00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,
    $30,$31,$32,$33,$34,$35,$36,$37,$38,$39,$00,$00,$00,$00,$00,$00,
    $00,$41,$42,$43,$44,$45,$46,$47,$48,$49,$4A,$4B,$4C,$4D,$4E,$4F,
    $50,$51,$52,$53,$54,$55,$56,$57,$58,$59,$5A,$00,$00,$00,$00,$5F,
    $00,$41,$42,$43,$44,$45,$46,$47,$48,$49,$4A,$4B,$4C,$4D,$4E,$4F,
    $50,$51,$52,$53,$54,$55,$56,$57,$58,$59,$5A,$00,$00,$00,$00,$00,
    $00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,
    $00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,
    $00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,
    $00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,
    $00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,
    $00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,
    $00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,
    $00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00);

function GetHashCode(Ident: PChar; Length: Integer): Word;
asm
      PUSH ESI

	PUSH	EBX
	XOR	EBX,EBX

      MOV  ESI, EAX
      XOR  EAX, EAX
      XOR  ECX, ECX
@@1:  MOV   AL,[ESI]
      ROL	CX,5
      XOR	CL,CharValue.Byte[EBX + EAX]
      INC	ESI
      DEC	EDX
	JNE	@@1
      MOV	EAX,ECX

	POP	EBX

      POP   ESI
end;

type
  TSymbolEntry = record
    HashCode: Word;
    Symbol: PChar;
    Token: Char;
  end;

const
  SymbolTable: array[0..20] of TSymbolEntry = (
    (HashCode: hcGet; Symbol: 'GET'; Token: toGET),
    (HashCode: hcPut; Symbol: 'PUT'; Token: toPUT),
    (HashCode: hcDelete; Symbol: 'DELETE'; Token: toDELETE),
    (HashCode: hcPost; Symbol: 'POST'; Token: toPOST),
    (HashCode: hcCacheControl; Symbol: 'Cache-Control'; Token: toCacheControl),
    (HashCode: hcDate; Symbol: 'Date'; Token: toDate),
    (HashCode: hcFrom; Symbol: 'From'; Token: toFrom),
    (HashCode: hcHost; Symbol: 'Host'; Token: toHost),
    (HashCode: hcIfModified; Symbol: 'If-Modified-Since'; Token: toIfModified),
    (HashCode: hcAllow; Symbol: 'Allow'; Token: toAllow),
    (HashCode: hcUserAgent; Symbol: 'User-Agent'; Token: toUserAgent),
    (HashCode: hcAccept; Symbol: 'Accept'; Token: toAccept),
    (HashCode: hcContentEncoding; Symbol: 'Content-Encoding'; Token: toContentEncoding),
    (HashCode: hcContentVersion; Symbol: 'Content-Version'; Token: toContentVersion),
    (HashCode: hcContentType; Symbol: 'Content-Type'; Token: toContentType),
    (HashCode: hcContentLength; Symbol: 'Content-Length'; Token: toContentLength),
    (HashCode: hcReferer; Symbol: 'Referer'; Token: toReferer),
    (HashCode: hcConnection; Symbol: 'Connection'; Token: toConnection),
    (HashCode: hcCookie; Symbol: 'Cookie'; Token: toCookie),
    (HashCode: hcAuthorization; Symbol: 'Authorization'; Token: toAuthorization),
    (HashCode: hcContentDisposition; Symbol: 'Content-Disposition'; Token: toContentDisposition));

function LookupToken(Sym: PChar): Char;
var
  HCode: Word;
  I: Integer;
begin
  Result := toSymbol;
  HCode := GetHashCode(Sym, StrLen(Sym));
  for I := Low(SymbolTable) to High(SymbolTable) do
    with SymbolTable[I] do
      if HCode = HashCode then
        if StrIComp(Symbol, Sym) = 0 then
        begin
          Result := Token;
          Break;
        end;
end;

function THTTPParser.NextToken: Char;
var
  I: Integer;
  P, S: PChar;
  SaveChar: Char;
  TokenChars: set of Char;
begin
  SkipBlanks;
  P := FSourcePtr;
  FTokenPtr := P;
  if FHeaderField then
    TokenChars := ['A'..'Z', 'a'..'z', '0'..'9', '_', '-']
  else TokenChars := ['A'..'Z', 'a'..'z', '0'..'9', '_'];
  case P^ of
    'A'..'Z', 'a'..'z', '_':
      begin
        Inc(P);
        while P^ in TokenChars do Inc(P);
        SaveChar := P^;
        try
          P^ := #0;
          Result := LookupToken(FTokenPtr);
        finally
          P^ := SaveChar;
        end;
      end;
    #10:
      begin
        Inc(P);
        Inc(FSourceLine);
        Result := toEOL;
      end;
    '#', '''':
      begin
        S := P;
        while True do
          case P^ of
            '#':
              begin
                Inc(P);
                I := 0;
                while P^ in ['0'..'9'] do
                begin
                  I := I * 10 + (Ord(P^) - Ord('0'));
                  Inc(P);
                end;
                S^ := Chr(I);
                Inc(S);
              end;
            '''':
              begin
                Inc(P);
                while True do
                begin
                  case P^ of
                    #0, #10, #13:
                      Error(SInvalidString);
                    '''':
                      begin
                        Inc(P);
                        if P^ <> '''' then Break;
                      end;
                  end;
                  S^ := P^;
                  Inc(S);
                  Inc(P);
                end;
              end;
          else
            Break;
          end;
        FStringPtr := S;
        Result := toString;
      end;
    '$':
      begin
        Inc(P);
        while P^ in ['0'..'9', 'A'..'F', 'a'..'f'] do Inc(P);
        Result := toInteger;
      end;
    '0'..'9':
      begin
        Inc(P);
        while P^ in ['0'..'9'] do Inc(P);
        Result := toInteger;
        while P^ in ['0'..'9', '.', 'e', 'E', '+'] do
        begin
          Inc(P);
          Result := toFloat;
        end;
      end;
  else
    Result := P^;
    if Result <> toEOF then Inc(P);
  end;
  FSourcePtr := P;
  FToken := Result;
end;

procedure THTTPParser.ReadBuffer;
var
  Count: Integer;
  P: PChar;
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
  P := FBuffer;
  while P < FSourceEnd do
  begin
    Inc(P);
  end;
  FSaveChar := FSourceEnd[0];
  FSourceEnd[0] := #0;
end;

procedure THTTPParser.SkipBlanks;
begin
  while True do
  begin
    case FSourcePtr^ of
      #0:
        begin
          ReadBuffer;
          if FSourcePtr^ = #0 then Exit;
          Continue;
        end;
      #10: Exit;
      #33..#255:
        Exit;
    end;
    Inc(FSourcePtr);
  end;
end;

function THTTPParser.SourcePos: Longint;
begin
  Result := FOrigin + (FTokenPtr - FBuffer);
end;

procedure THTTPParser.SkipEOL;
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

function THTTPParser.TokenFloat: Extended;
begin
  Result := StrToFloat(TokenString);
end;

function THTTPParser.TokenInt: Longint;
begin
  Result := StrToInt(TokenString);
end;

function THTTPParser.TokenString: string;
var
  L: Integer;
begin
  if FToken = toString then
    L := FStringPtr - FTokenPtr else
    L := FSourcePtr - FTokenPtr;
  SetString(Result, FTokenPtr, L);
end;

function THTTPParser.TokenSymbolIs(const S: string): Boolean;
begin
  Result := (Token = toSymbol) and (CompareText(S, TokenString) = 0);
end;

end.
