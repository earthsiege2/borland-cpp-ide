{ *************************************************************************** }
{                                                                             }
{ Kylix and Delphi Cross-Platform Visual Component Library                    }
{                                                                             }
{ Copyright (c) 1995, 2001 Borland Software Corporation                       }
{                                                                             }
{ *************************************************************************** }


unit FMTBcd;

interface

uses SysUtils, Variants;

const

  MaxStringDigits = 100;
  _NoDecimal = -255;
  _DefaultDecimals = 10;

  { From DB.pas }
  { Max supported by Midas }
  MaxFMTBcdFractionSize = 64;
  { Max supported by Midas }
  MaxFMTBcdDigits =   32;
  DefaultFMTBcdScale = 6;
  MaxBcdPrecision =   18;
  MaxBcdScale     =   4;

type

  PBcd = ^TBcd;
  TBcd  = packed record
    Precision: Byte;                        { 1..64 }
    SignSpecialPlaces: Byte;                { Sign:1, Special:1, Places:6 }
    Fraction: packed array [0..31] of Byte; { BCD Nibbles, 00..99 per Byte, high Nibble 1st }
  end;

{ Exception classes }

  EBcdException = class(Exception);
  EBcdOverflowException = class(EBcdException);

{ Utility functions for TBcd access }

function BcdPrecision(const Bcd: TBcd): Word;
function BcdScale(const Bcd: TBcd): Word;
function IsBcdNegative(const Bcd: TBcd): Boolean;

{ Bcd Arithmetic}

procedure BcdAdd(const bcdIn1, bcdIn2: TBcd; var bcdOut: TBcd);
procedure BcdSubtract(const bcdIn1, bcdIn2: TBcd; var bcdOut: TBcd);
{ Returns True if successful, False if Int Digits needed to be truncated }
function NormalizeBcd(const InBcd: TBcd; var OutBcd: TBcd; const Prec, Scale: Word): Boolean;

procedure BcdMultiply(const bcdIn1, bcdIn2: TBcd; var bcdOut: TBcd); overload;
procedure BcdMultiply(const bcdIn: TBcd; const DoubleIn: Double; var bcdOut: TBcd); overload;
procedure BcdMultiply(const bcdIn: TBcd; const StringIn: string; var bcdOut: TBcd); overload;
procedure BcdMultiply(StringIn1, StringIn2: string; var bcdOut: TBcd); overload;
procedure BcdDivide(Dividend, Divisor: string; var bcdOut: TBcd); overload;
procedure BcdDivide(const Dividend, Divisor: TBcd; var bcdOut: TBcd); overload;
procedure BcdDivide(const Dividend: TBcd; const Divisor: Double; var bcdOut: TBcd); overload;
procedure BcdDivide(const Dividend: TBcd; const Divisor: string; var bcdOut: TBcd); overload;

{ TBcd variant creation utils }
procedure VarFMTBcdCreate(var ADest: Variant; const ABcd: TBcd); overload;
function VarFMTBcdCreate: Variant; overload;
function VarFMTBcdCreate(const AValue: string; Precision, Scale: Word): Variant; overload;
function VarFMTBcdCreate(const AValue: Double; Precision: Word = 18; Scale: Word = 4): Variant; overload;
function VarFMTBcdCreate(const ABcd: TBcd): Variant; overload;
function VarIsFMTBcd(const AValue: Variant): Boolean; overload;
function VarFMTBcd: TVarType;

{ Convert String/Double/Integer to BCD struct }
function StrToBcd(const AValue: string): TBcd; 
function TryStrToBcd(const AValue: string; var Bcd: TBcd): Boolean;
function DoubleToBcd(const AValue: Double): TBcd; overload;
procedure DoubleToBcd(const AValue: Double; var bcd: TBcd); overload;
function IntegerToBcd(const AValue: Integer): TBcd;
function VarToBcd(const AValue: Variant): TBcd;

{ From DB.pas }
function CurrToBCD(const Curr: Currency; var BCD: TBcd; Precision: Integer = 32;
  Decimals: Integer = 4): Boolean;

{ Convert Bcd struct to string/Double/Integer }
function BcdToStr(const Bcd: TBcd): string; overload;
function BcdToDouble(const Bcd: TBcd): Double;
function BcdToInteger(const Bcd: TBcd; Truncate: Boolean = False): Integer;

{ From DB.pas }
function BCDToCurr(const BCD: TBcd; var Curr: Currency): Boolean;
{ Formatting Bcd as string }
function BcdToStrF(const Bcd: TBcd; Format: TFloatFormat; const Precision, Digits: Integer): string;
function FormatBcd(const Format: string; Bcd: TBcd): string;
function BcdCompare(const bcd1, bcd2: TBcd): Integer;

const

  NullBcd: TBcd = (Precision: 0; SignSpecialPlaces: 0; Fraction: (0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0));

implementation

uses VarUtils, SysConst, DBConsts, TypInfo, Math, Classes;

type

{ TFMTBcdVariantType }

  TFMTBcdVariantType = class(TPublishableVariantType)
  protected
    function GetInstance(const V: TVarData): TObject; override;
  public
    procedure Clear(var V: TVarData); override;
    procedure Copy(var Dest: TVarData; const Source: TVarData; const Indirect: Boolean); override;
    procedure Cast(var Dest: TVarData; const Source: TVarData); override;
    procedure CastTo(var Dest: TVarData; const Source: TVarData; const AVarType: TVarType); override;
    procedure BinaryOp(var Left: TVarData; const Right: TVarData; const Operator: TVarOp); override;
    procedure Compare(const Left, Right: TVarData; var Relationship: TVarCompareResult); override;
  end;

var

{ FMTBcd that the complex variant points to }

  FMTBcdVariantType: TFMTBcdVariantType = nil;

type

{ TFMTBcdData }

  TFMTBcdData = class(TPersistent)
  private
    FBcd: TBcd;
    function GetAsCurrency: Currency;
    function GetAsDouble: Double;
    function GetAsInteger: Integer;
    function GetAsString: string;
    function GetAsSmallInt: SmallInt;
    procedure SetAsCurrency(const Value: Currency);
    procedure SetAsDouble(const Value: Double);
    procedure SetAsInteger(const Value: Integer);
    procedure SetAsSmallInt(const Value: SmallInt);
    procedure SetAsString(const Value: string);
  public
    constructor Create(const AValue: Integer); overload;
    constructor Create(const AValue: Double; Precision, Scale: Word); overload;
    constructor Create(const AValue: Currency); overload;
    constructor Create(const AText: string; Precision, Scale: Word); overload;
    constructor Create(const ABcd: TBcd); overload;
    constructor Create(const ASource: TFMTBcdData); overload;

    property Bcd: TBcd read FBcd write FBcd;

    function Compare(const Value: TFMTBcdData): TVarCompareResult;

    procedure DoAdd(const Value: TBcd); overload;
    procedure DoAdd(const AFMTBcd: TFMTBcdData); overload;
    procedure DoSubtract(const Value: TBcd); overload;
    procedure DoSubtract(const AFMTBcd: TFMTBcdData); overload;
    procedure DoMultiply(const ABcdData: TFMTBcdData); overload;
    procedure DoDivide(const ABcdData: TFMTBcdData); overload;
  published
    { Conversion }
    property AsCurrency: Currency read GetAsCurrency write SetAsCurrency;
    property AsDouble: Double read GetAsDouble write SetAsDouble;
    property AsInteger: Integer read GetAsInteger write SetAsInteger;
    property AsSmallInt: SmallInt read GetAsSmallInt write SetAsSmallInt;
    property AsString: string read GetAsString write SetAsString;
  end;

{ Helper record that helps crack open TFMTBcdObject }

  TFMTBcdVarData = packed record
    VType: TVarType;
    Reserved1, Reserved2, Reserved3: Word;
    VBcd: TFMTBcdData;
    Reserved4: LongWord;
  end;

procedure BcdErrorFmt(const Message, BcdAsString: string);
begin
  raise EBcdException.Create(Format(Message, [BcdAsString]));
end;

procedure BcdError(const Message: string);
begin
  raise EBcdException.Create(Message);
end;

procedure OverflowError(const Message: string);
begin
  raise EBcdOverflowException.Create(Message);
end;

{ TFMTBcdData }

procedure TFMTBcdData.DoAdd(const Value: TBcd);
var
  NewBcd: TBcd;
begin
  BcdAdd(Self.Bcd, Value, NewBcd);
  Self.Bcd := NewBcd;
end;

procedure TFMTBcdData.DoAdd(const AFMTBcd: TFMTBcdData);
begin
  DoAdd(AFMTBcd.Bcd);
end;

procedure TFMTBcdData.DoSubtract(const Value: TBcd);
var
  NewBcd: TBcd;
begin
  BcdSubtract(Self.Bcd, Value, NewBcd);
  Self.Bcd := NewBcd;
end;

procedure TFMTBcdData.DoSubtract(const AFMTBcd: TFMTBcdData);
begin
  DoSubtract(AFMTBcd.Bcd);
end;

procedure TFMTBcdData.DoMultiply(const ABcdData: TFMTBcdData);
var
  ABcd: TBcd;
begin
  BcdMultiply(Self.Bcd, ABcdData.Bcd, ABcd);
  Self.Bcd := ABcd;
end;

procedure TFMTBcdData.DoDivide(const ABcdData: TFMTBcdData);
var
  ABcd: TBcd;
begin
  ABcd.signSpecialPlaces := Byte(Max((ABcdData.FBcd.signSpecialPlaces and 63),
                                (Self.FBcd.signSpecialPlaces and 63)));
  BcdDivide(Self.Bcd, ABcdData.Bcd, ABcd);
  Self.Bcd := ABcd;
end;

function TFMTBcdData.Compare(const Value: TFMTBcdData): TVarCompareResult;
begin
  Result := TVarCompareResult(BcdCompare(Self.FBcd, Value.FBcd)+1);
end;

function TFMTBcdData.GetAsString: string;
begin
  Result := BcdToStr(Self.FBcd);
end;

function TFMTBcdData.GetAsDouble: Double;
begin
  Result := StrToFloat(BcdToStr(Self.FBcd));
end;

function TFMTBcdData.GetAsInteger: Integer;
begin
  Result := StrToInt(BcdToStr(Self.FBcd));
end;

function TFMTBcdData.GetAsSmallInt: SmallInt;
begin
  Result := SmallInt(GetAsInteger);
end;

function TFMTBcdData.GetAsCurrency: Currency;
begin
  BCDToCurr(Self.FBcd, Result);
end;

procedure TFMTBcdData.SetAsString(const Value: string);
begin
  FBcd := StrToBcd(Value);
end;

procedure TFMTBcdData.SetAsDouble(const Value: Double);
begin
  FBcd := StrToBcd(FloatToStr(Value));
end;

procedure TFMTBcdData.SetAsInteger(const Value: Integer);
begin
  FBcd := StrToBcd(IntToStr(Value));
end;

procedure TFMTBcdData.SetAsSmallInt(const Value: SmallInt);
begin
  SetAsInteger(Integer(Value));
end;

procedure TFMTBcdData.SetAsCurrency(const Value: Currency);
begin
  CurrToBcd(Value, FBcd);
end;

constructor TFMTBcdData.Create(const ABcd: TBcd);
begin
  inherited Create;
  Move(ABcd, FBcd, SizeOf(TBcd));
end;

constructor TFMTBcdData.Create(const AValue: Integer);
begin
  Create(IntegerToBcd(AValue));
end;

constructor TFMTBcdData.Create(const AValue: Double; Precision, Scale: Word);
var
  ABcd, OutBcd: TBcd;
begin
  ABcd := StrToBcd(FloatToStr(AValue));
  if not NormalizeBcd(ABcd, OutBcd, Precision, Scale) then
    OverflowError(SBcdOverflow);
  Create(OutBcd);
end;

constructor TFMTBcdData.Create(const AValue: Currency);
var
  OutBcd: TBcd;
begin
  CurrToBcd(AValue, OutBcd);
  Create(OutBcd);
end;

constructor TFMTBcdData.Create(const AText: string; Precision, Scale: Word);
var
  ABcd, OutBcd: TBcd;
begin
  ABcd := StrToBcd(AText);
  if not NormalizeBcd(ABcd,OutBcd,Precision,Scale) then
    OverflowError(SBcdOverflow);
  Create(OutBcd);
end;

constructor TFMTBcdData.Create(const ASource: TFMTBcdData);
begin
  Create(aSource.Bcd);
end;

{ TFMTBcdVariantType }

procedure TFMTBcdVariantType.Clear(var V: TVarData);
begin
  V.VType := varEmpty;
  FreeAndNil(TFMTBcdVarData(V).VBcd);
end;

procedure TFMTBcdVariantType.Cast(var Dest: TVarData;
  const Source: TVarData);
var
  LSource, LTemp: TVarData;
begin
  VarDataInit(LSource);
  try
    VarDataCopyNoInd(LSource, Source);
    if VarDataIsStr(LSource) then
      TFMTBcdVarData(Dest).VBcd := TFMTBcdData.Create(VarDataToStr(LSource), 32, 8)
    else
    begin
      VarDataInit(LTemp);
      try
        VarDataCastTo(LTemp, LSource, varDouble);
        TFMTBcdVarData(Dest).VBcd := TFMTBcdData.Create(LTemp.VDouble, 32, 8);
      finally
        VarDataClear(LTemp);
      end;
    end;
    Dest.VType := VarType;
  finally
    VarDataClear(LSource);
  end;
end;

procedure TFMTBcdVariantType.CastTo(var Dest: TVarData;
  const Source: TVarData; const AVarType: TVarType);
var
  LTemp: TVarData;
begin
  if Source.VType = VarType then
    case AVarType of
      varOleStr:
        VarDataFromOleStr(Dest, TFMTBcdVarData(Source).VBcd.AsString);
      varString:
        VarDataFromStr(Dest, TFMTBcdVarData(Source).VBcd.AsString);
    else
      VarDataInit(LTemp);
      try
        LTemp.VType := varDouble;
        LTemp.VDouble := BcdToDouble(TFMTBcdVarData(Source).VBcd.Bcd);
        VarDataCastTo(Dest, LTemp, AVarType);
      finally
        VarDataClear(LTemp);
      end;
    end
  else
    inherited;
end;

procedure TFMTBcdVariantType.Copy(var Dest: TVarData; const Source: TVarData; const Indirect: Boolean);
begin
  if Indirect and VarDataIsByRef(Source) then
    VarDataCopyNoInd(Dest, Source)
  else
    with TFMTBcdVarData(Dest) do
    begin
      VType := VarType;
      VBcd := TFMTBcdData.Create(TFMTBcdVarData(Source).VBcd);
    end;
end;

procedure TFMTBcdVariantType.BinaryOp(var Left: TVarData; const Right: TVarData; const Operator: TVarOp);
begin
  case Operator of
    opAdd:
      TFMTBcdVarData(Left).VBcd.DoAdd(TFMTBcdVarData(Right).VBcd);
    opSubtract:
      TFMTBcdVarData(Left).VBcd.DoSubtract(TFMTBcdVarData(Right).VBcd);
    opMultiply:
      TFMTBcdVarData(Left).VBcd.DoMultiply(TFMTBcdVarData(Right).VBcd);
    opDivide:
      TFMTBcdVarData(Left).VBcd.DoDivide(TFMTBcdVarData(Right).VBcd);
  else
    RaiseInvalidOp;
  end;
end;

function TFMTBcdVariantType.GetInstance(const V: TVarData): TObject;
begin
  Result := TFMTBcdVarData(V).VBcd;
end;

procedure TFMTBcdVariantType.Compare(const Left, Right: TVarData; var Relationship: TVarCompareResult);
begin
  Relationship := TFMTBcdVarData(Left).VBcd.Compare(TFMTBcdVarData(Right).VBcd);
end;

{ FMTBcd variant create utils }

function VarFMTBcdCreate(const AValue: string; Precision, Scale: Word): Variant; overload;
begin
  VarClear(Result);
  TFMTBcdVarData(Result).VType := FMTBcdVariantType.VarType;
  TFMTBcdVarData(Result).VBcd := TFMTBcdData.Create(AValue, Precision, Scale);
end;

function VarFMTBcdCreate(const AValue: Double; Precision, Scale: Word): Variant; overload;
begin
  VarClear(Result);
  TFMTBcdVarData(Result).VType := FMTBcdVariantType.VarType;
  TFMTBcdVarData(Result).VBcd := TFMTBcdData.Create(AValue, Precision, Scale);
end;

procedure VarFMTBcdCreate(var ADest: Variant; const ABcd: TBcd); overload;
begin
  VarClear(ADest);
  TFMTBcdVarData(ADest).VType := FMTBcdVariantType.VarType;
  TFMTBcdVarData(ADest).VBcd := TFMTBcdData.Create(ABcd);
end;

function VarFMTBcdCreate: Variant; overload;
begin
  VarFMTBcdCreate(Result, NullBcd);
end;

function VarFMTBcdCreate(const ABcd: TBcd): Variant;
begin
  VarFMTBcdCreate(Result, ABcd);
end;

function VarIsFMTBcd(const AValue: Variant): Boolean;
begin
  Result := (TVarData(AValue).VType = FMTBcdVariantType.VarType);
end;

function VarFMTBcd: TVarType;
begin
  Result := FMTBcdVariantType.VarType;
end;

function StrToBcd(const AValue: string): TBcd;
var
  Success: Boolean;
begin
  Success := TryStrToBcd(AValue, Result);
  if not Success then
    BcdErrorFmt(SInvalidBcdValue, AValue);
end;

procedure DoubleToBcd(const AValue: Double; var bcd: TBcd); overload;
begin
  bcd := StrToBcd(FloatToStr(AValue));
end;
function DoubleToBcd(const AValue: Double): TBcd; overload;
begin
  DoubleToBcd(AValue, Result);
end;

function VarToBcd(const AValue: Variant): TBcd;
begin
  if VarType(AValue) = FMTBcdVariantType.VarType then
    Result := TFMTBcdVarData(AValue).VBcd.FBcd
  else
    Result := TFMTBcdVarData(VarFmtBcdCreate(AValue)).VBcd.FBcd;
end;

function IntegerToBcd( const AValue: Integer): TBcd;
begin
  Result := StrToBcd(IntToStr(AValue));
end;

function BcdToDouble(const Bcd: TBcd): Double;
begin
  Result := StrToFloat(BcdToStr(Bcd));
end;

function BcdToInteger(const Bcd: TBcd; Truncate: Boolean = False): Integer;
var
  ABcd: TBcd;
begin
  if (Truncate) and (BcdScale(Bcd) > 0 ) then
    NormalizeBcd(Bcd,ABcd,Bcd.Precision,0)
  else
    ABcd := Bcd;
  Result := StrToInt(BcdToStr(ABcd));    
end;

{ utility routines }

function RoundAt(const Value: string; Position: SmallInt): string;
var
  P, PP: PChar;
  DecPos: SmallInt;
  Dot : Char;
begin
  Dot := DecimalSeparator;
  DecPos := Pos(Dot, Value);
  if DecPos = 0 then DecPos := Length(Value)
  else Inc(Position, DecPos);
  if (Position < (Length(Value) -1)) and (DecPos < Position) then
  begin
    PP := PChar(Value) + ((Position -1));
    P := PP+1;
    if Byte(P^) >= 53  then    { if '5' or greater }
      PP^ := Char(Byte(PP^)+1);
    while (Position > 0) and ((Byte(PP^) > 57) or (PP^ = Dot)) do  {if greater than '9' then }
    begin
      if PP^ <> Dot then
        PP^ := '0';
      Dec(Position);
      Dec(PP);
      if PP^ <> Dot then
        PP^ := Char(Byte(PP^)+1);
    end;
    if Byte(PP^) > 57 then
    begin
      PP^ := '0';
      Result := '1' + Copy(Value,1,Position -1);
    end else
      Result := Copy(Value,1,Position);
  end else
    Result := Value;
end;

function LeftTrim(const Value: string): string;
begin
  Result := Value;
  while (Length(Result) > 1) and (Result[1] = '0') do
    Result := Copy(Result, 2, Length(Result) -1);
end;

function CompareDigits(S1, S2: string): Integer;
begin
  S1 := LeftTrim(S1);
  if Length(S1) > Length(S2) then
    Result := 1
  else if Length(S2) > Length(S1) then
    Result := -1
  else
    Result := CompareStr(S1, S2);
end;

procedure GetValueAndMultiplyOrder(A, B: string; var V, M: string; LA, LB: Integer; var Wid, Len, DecPos: Integer);
var
  DecimalPosA, DecimalPosB: Integer;
  Dot : Char;
begin
  Dot := DecimalSeparator;
  DecPos := 0;
  if CompareDigits(A,B) > 1 then
  begin
    V := A;
    M := B;
    Wid := LA;
    Len := LB;
  end else
  begin
    M := A;
    V := B;
    Wid := LB;
    Len := LA;
  end;  
  { to get rid of GetDecimalPosition }
  DecimalPosA := Pos(Dot, V);
  DecimalPosB := Pos(Dot, M);
  if (DecimalPosA = 0) and (DecimalPosB = 0) then
    DecPos := _NoDecimal
  else
  begin
    if DecimalPosA > 0 then
    begin
      V := StringReplace(V, Dot, '', []);
      DecPos := Wid - DecimalPosA;
      Dec(Wid);
    end;
    if DecimalPosB > 0 then
    begin
      M := StringReplace(M, Dot,'',[]);
      DecPos := DecPos + (Len - DecimalPosB);
      Dec(Len);
    end;
  end;
end;

function AddChars(V, M: Char; var R: Byte): string;
var
  Value: Byte;
begin
  Value := Byte((Byte(V)-48) + (Byte(M)-48) + R);
  if Value > 9 then
  begin
    Result := Char((Value - 10) + 48);
    R := Byte(1);
  end else
  begin
    Result :=  Char(Value + 48);
    R := Byte(0);
  end;
  if Result = '' then Result := '0';
end;

function SubtractChars(V, M: Char; var R: Byte): string;
var
  Value: Byte;
begin
  Value := Byte((Byte(V)-48) - ((Byte(M)-48) + R));
  if Value > 9 then  // Byte is unsigned: values will be between 246-255
  begin
    Result := Char((Value + 10) + 48);
    R := Byte(1);
  end else
  begin
    Result :=  Char(Value + 48);
    R := Byte(0);
  end;
end;

function AddStrings(const V, M: string): string;
var
  Digit: string;
  pV, pM: PChar;     // pointer to string A, string B;
  LenV, LenM, MaxDigits, I, DigitV, DigitM: Integer;
  R: Byte;           // Remainder
  CV, CM: Char;      // char from string A, string B
begin
  if (V = '') or (V = '0') then
  begin
    Result := M;
    Exit;
  end;
  if (M = '') or (M = '0') then
  begin
    Result := V;
    Exit;
  end;
  R := 0;
  pV := PChar(V);
  pM := PChar(M);
  LenV := Length(V);
  LenM := Length(M);
  MaxDigits := Max(LenV, LenM);
  Result := '';
  for I := 1 to MaxDigits do
  begin
    DigitV := LenV - I;
    DigitM := LenM - I;
    if I <= LenV then CV := pV[DigitV] else CV := '0';
    if I <= LenM then CM := pM[DigitM] else CM := '0';
    Digit := AddChars(CV, CM, R);
    Result := Digit + Result;
  end;
  if R > 0 then
    Result := '1' + Result;
end;

function SubtractStrings(const Value, Minus: string): string;
var
  Digit, V, M: string;
  pV, pM: PChar;     // pointer to string A, string B;
  LenV, LenM, MaxDigits, I, DigitV, DigitM: Integer;
  R: Byte;           // Remainder
  CV, CM: Char;      // char from string A, string B
begin
  if CompareDigits(Value, Minus) >= 0 then
  begin
    V := Value;
    M := Minus;
    Result := '';
  end else
  begin
    M := Value;
    V := Minus;
    Result := '-';
  end;
  if (V = '') or (M = '') then
  begin
    if V = '' then Result := '-' + M else Result := V;
  end;
  if (V = '0') or (M = '0') then
  begin
    if M = '0' then
      Result := V
    else if V = '0' then
      Result := '0'
    else
      Result := M;
    Exit;
  end;
  R := 0;
  pV := PChar(V);
  pM := PChar(M);
  LenV := Length(V);
  LenM := Length(M);
  MaxDigits := Max(LenV, LenM);
  Result := '';
  for I := 1 to MaxDigits do
  begin
    DigitV := LenV - I;
    DigitM := LenM - I;
    if I <= LenV then CV := pV[DigitV] else CV := '0';
    if I <= LenM then CM := pM[DigitM] else CM := '0';
    Digit := SubtractChars(CV, CM, R);
    Result := Digit + Result;
  end;
  if Result = '' then Result := '0';
end;

function _ShortMultiply(const A, B: string): string;
var
  DecPos,W,L,I: Integer;
  S, SS, Times: LongWord;
  pMultiplier: PChar;
  Value, Multiplier: string;
  Dot : Char;
begin
  Dot := DecimalSeparator;
  GetValueAndMultiplyOrder(A, B, Value, Multiplier, Length(A), Length(B), W, L, DecPos);
  PMultiplier := PChar(Multiplier);
  Times := 1;
  S := 0;
  for I := L - 1 downto 0 do
  begin
    SS := LongWord(LongWord((Byte(PMultiplier[I])-Byte(48))) * LongWord(StrToInt(Value)) * Times);
    S := SS + S;
    Times := Times * 10;
  end;
  Result := IntToStr(S);
  if DecPos <> _NoDecimal then
  begin
    I := Length(Result) - DecPos;
    if I = 0 then
      Result := '0' + Dot + Result
    else if I > 0 then
      Result := Copy(Result,1, I) + Dot + Copy(Result,I+1,DecPos)
    else if I < 0 then
      Result := Dot + StringOfChar('0', -I) + Result;
  end;
end;

function StringMultiplyByByte(const Value: string; B: Byte): string; pascal;
var
  L : SmallInt;
  PValue, PResult: PChar;
begin
  L := Length(Value);
  PValue := PChar(Value) + (L - 1);   // point to end of input string
  SetLength(Result, L + 1);          // allocate, perhaps 1 more byte than needed.
  PResult := PChar(Result) + L;
  asm
       PUSH          ECX
       PUSH          EDI
       PUSH          ESI
       PUSH          EBX
       MOV           BH,10             // divisor to get both digits
       MOV           EDI,PResult
       MOV           ESI,PValue
       MOV           CX,L               // Store # of digits in Value to CX
       MOV           DX,0               // DX holds remainder, which comes from AH
@@1:   CMP           CX,0               // any more digits:
       JE            @@2
       MOV           AL,[ESI]           // move digit to AL
       SUB           ESI,1              // decrement pointer
       SUB           AL,'0'             // convert from char digit to #
       MUL           B                  // multiply by B: result goes to AX
       ADD           AX,DX              // Add Remainder from DL
       MOV           DX,0               // set remainder back to 0
       DIV           BH                 // Divide by 10; result goes to AL, remainder to AH
       MOV           DL,AL              // move remainder to DL (DH will always 0 here)
       ADD           AH,'0'             // convert from # to char digit
       MOV           [EDI],AH           // move digit to Result
       SUB           EDI,1              // decrement output pointer
       SUB           CX,1
       JMP           @@1
@@2:   ADD           DL,'0'             // move '0' or remainder to last
       MOV           [EDI],DL           // digit of Result
@@3:   POP           EBX
       POP           ESI
       POP           EDI
       POP           ECX
  end;
  if Result[1] = '0' then
    Result := Copy(Result, 2, Length(Result) -1 );
end;

function _LongMultiply(const A, B: string): string;
const
  MaxSmall = 9;
var
  DecPos, W, L, I: Integer;
  Times, S, SS: string;
  pMultiplier: PChar;
  Value, Multiplier: string;
  T1, T2: Integer;
  Dot : Char;
begin
  Dot := DecimalSeparator;
  GetValueAndMultiplyOrder(A, B, Value, Multiplier, Length(A), Length(B), W, L, DecPos);
  T1 := Length(Value);
  T2 := Length(Multiplier);
  pMultiplier := PChar(Multiplier);
  Times := '';
  for I := L-1 downto 0 do
  begin
    if W < MaxSmall then
      SS := IntToStr(LongWord((Byte(PMultiplier[I])-48) * StrToInt(Value))) + Times
    else
      SS := StringMultiplyByByte(Value,Byte(PMultiplier[I])-48) + Times;
    S := AddStrings(SS,S);
    Times := Times + '0';
  end;
  Result := S;
  while Result[1] = '0' do
    Result := Copy(Result, 2, Length(Result) -1);
  if DecPos <> _NoDecimal then
  begin
    I := Length(Result) - DecPos;
    if I = 0 then
      Result := '0' + Dot + Result
    else if I > 0 then
      Result := Copy(Result,1, I) + Dot + Copy(Result,I+1,DecPos)
    else if I < 0 then
      Result := Dot + StringOfChar('0', -I) + Result;
    if T1 + T2 > 1024 then Result := ''  
  end;
end;

// Go through 2 strings and determine if total length > MaxDigits
function CanUseShort(A, B: PChar; MaxDigits: ShortInt): Boolean; pascal;
var
  Dot: Char;
begin
  Dot := DecimalSeparator;
  asm
      PUSH      EAX
      PUSH      EBX
      PUSH      ECX
      PUSH      EDX
      PUSH      EDI
      MOV       EDI,A
      MOV       Result,False
      MOV       CL,0               // Flag for A/B
      MOV       CH,0               // Total Digit counter
      MOV       AH,MaxDigits       // Max Integer Digits
      MOV       DL,0               // Flag for first char
      MOV       DH,0               // Values of first chars
@@1:  MOV       AL,[EDI]
      ADD       EDI,1
      CMP       DL,0               // if first char
      JNE       @@2                // then
      ADD       DH,AL              // save value to DH
      MOV       DL,1
@@2:  CMP       AL,0
      JE        @@3
      CMP       AL,Dot             // if '.' don't count
      JE        @@1
      ADD       CH,1
      JMP       @@1
@@3:  CMP       CL,0
      JNE       @@4
      MOV       CL,1
      MOV       DL,0
      MOV       EDI,B
      JMP       @@1
@@4:  CMP       DH,107
      JA        @@5
      ADD       AH,1
@@5:  CMP       CH,AH
      JA        @@6               // if CH > then AH (Max), then Result stays False
      MOV       Result,True       // otherwise, it's true.
@@6:  POP       EDI
      POP       EDX
      POP       ECX
      POP       EBX
      POP       EAX
  end;
end;

// Return True if S evaluates to 0
function BlankArgument(const S: string): Boolean;
var
  I: Integer;
begin
  Result := True;
  for I := 1 to Length(S) do
    if not (S[I] in ['0', '.']) then
    begin
      Result := False;
      break;
    end;
end;

function _Multiply(const A, B: string): string;
begin
  if BlankArgument(A) and BlankArgument(B) then
    Result := '0'
  else if CanUseShort(PChar(A), PChar(B), 9) then
    Result := _ShortMultiply(A,B)
  else
    Result := _LongMultiply(A,B);
end;

function NextDigit(const V, D: string; var R: string): string;
begin
  R := V;
  Result := '0';
  while CompareDigits(R, D) >= 0 do
  begin
    Result := IntToStr(StrToInt(Result) + 1);
    R := LeftTrim(SubtractStrings(R, D));
  end;
end;

function AdjustDecimalPosition(const Value: string; DecPos: SmallInt): string;
var
  Dot : Char;
begin
  Dot := DecimalSeparator;
  Result := Value;
  while Result[1] = '0' do 
    Result := Copy(Result, 2, length(Result) -1);
  if DecPos = 0 then
    Result := '0.' + Result
  else if DecPos > 0 then
    Result := '0' + Dot + StringOfChar('0', DecPos) + Result
  else // DecPos < 0 then
  begin
    if -DecPos >= Length(Result) then
      Result := Result + StringOfChar('0', (-DecPos)-Length(Result))
    else if -DecPos < Length(Result) then
    begin
      Result := Copy(Result, 1, -DecPos) + Dot + Copy(Result, (-DecPos)+1, Length(Result));
    end;
  end;
end;

function ValueOverOne(D: string): string;
var
  R: string;
  V: string;
  AddZeros, DecimalPos: SmallInt;
  Dot : Char;
begin
  Dot := DecimalSeparator;
  DecimalPos := Pos(Dot, D);
  if DecimalPos > 0 then
  begin
    Result := '10';
    Dec(DecimalPos,2);  // 1/.2 = 5.0; 1/2.2 = .45;
    if PChar(D)[0]= Dot then
    begin
      D := Copy(D, 2, Length(D) -1);
      while PChar(D)[0] = '0' do
      begin
        Result := Result + '0';       // copy back later
        D := Copy(D, 2, Length(D) -1);
        Dec(DecimalPos);
      end;
    end else
    D := StringReplace(D, Dot, '', []);
  end else
  begin
    DecimalPos := Length(D) -1;
    Result := '1';
  end;
  if (D ='1') or (D = '1' + StringOfChar('0', Length(D) -1)) then
    Result := AdjustDecimalPosition(Result, DecimalPos -1)
  else
  begin
    V := '1';
    R := V;
    AddZeros := Length(V) -1;  // for divisor of 12345, add 4 zeros
    V := V + StringOfChar('0', AddZeros);
    if CompareDigits(V,D) < 0 then   // if still ess add 1
      V := V + '0';
    Result := '';
    while (R <> '0') and (Length(Result) < (MaxFMTBcdFractionSize + AddZeros)) do
    begin
      Result := Result + NextDigit(V, D, R);
      V := R + '0';
    end;
    Result := AdjustDecimalPosition(Result, DecimalPos);
  end;
end;

function _LongDivide(A, B: string): string;
var
  Negative: Boolean;
begin
  // save pos/minus info and remove '-'
  Negative := (PChar(A)[0] <> PChar(B)[0]) and
           ((PChar(A)[0] = '-') or (PChar(A)[0] = '-'));
  if PChar(A)[0] = '-' then A := Copy(A, 2, Length(A)-1);
  if PChar(B)[0] = '-' then B := Copy(B, 2, Length(B)-1);
  while PChar(A)[0] = '0' do A := Copy(A, 2, Length(A)-1);
  while PChar(B)[0] = '0' do B := Copy(B, 2, Length(B)-1);
  Result := ValueOverOne(B);
  Result := _Multiply(A, Result);
  if Negative then
    Result := '-' + Result;
end;

function _Divide(const A, B: string): string;
begin
  if BlankArgument(A) and BlankArgument(B) then
  begin
    if (A = '') or (A = '0') then
      Result := '0'
    else
      BcdError(SDivByZero);
  end
  else if B = '1' then
    Result := A
  else if B = '-1' then
    Result := '-' + A
  else if CompareStr(A,B) = 0 then
    Result := '1'
  else
    Result := _LongDivide(A,B);
end;

procedure _GetRemainder;
asm
        ADD     DL,DH            // Add remainder
        CMP     DL,10            // if over 10
        JB      @@1
        MOV     DH,1             // then remainder of 1
        SUB     DL,10            // and subtract 10 from value
        JMP     @@2
@@1:    MOV     DH,0             // otherwise remainder of 0
@@2:
end;

procedure _GetSubRemainder;
asm
        SUB     DL,DH            // Subtract remainder
        CMP     DL,10            // if less than 0
        JBE     @@1              //
        MOV     DH,1             // then remainder of 1
        ADD     DL,10            // and ADD 10 to value
        JMP     @@2
@@1:    MOV     DH,0             // otherwise remainder of 0
@@2:
end;

procedure _CopyBytes;
asm
@@1:    CMP     CL,0                // set # of bytes to copy
        JBE     @@2                 // so just
        LODSB                       // copy all bytes
        SUB     CL,2
        STOSB                       // from in to out
        CMP     CL,0
        JLE     @@2
        JMP     @@1
@@2:
end;

procedure _CopyOddFractions;
asm
@@1:    CMP     CL,CH            // splitting nibbles:
        JAE     @@4
        MOV     AH,DL            // DL contains last nibble
        ADD     CL,1
        CMP     CL,CH
        JNE     @@2
        MOV     AL,0
        JMP     @@3
@@2:    LODSB
        MOV     DL,AL           // save off nibble
        SHR     AL,4            // get 1st Nibble of new byte
@@3:    AND     AH,15           // get 2nd Nibble of saved byte
        SHL     AH,4            // make 2nd Nibble of saved 1st Nibble of new
        OR      AH,AL           // make 1st Nibble of new 2nd Nibble of new
        MOV     AL,AH
        STOSB
        ADD     CL,1
        JMP     @@1
@@4:
end;

procedure _CopyRestBlank;
asm
@@1:    CMP     CL,1
        JBE     @@2
        MOV     AL,0
        STOSB
        SUB     CL,2
        JMP     @@1
@@2:
end;

procedure NormalizeFractions(const pIn: PChar; InPrec, InScale, OutPrec, outScale: ShortInt; pOut: PChar); pascal;
asm
  // setup
        PUSH    ESI
        PUSH    EDI
        PUSH    EBX
        PUSH    ECX
        PUSH    EDX
        MOV     EDI,pOut
        MOV     ESI,pIn
        MOV     CL,OutPrec
        MOV     CH,OutScale
        CMP     CL,InPrec
        JA      @@6                // if OutPrec > InPrec ...
        CMP     CL,InPrec
        JE      @@4                // if OutPrec = InPrec, move to CheckScale
        MOV     AH,InPrec
        SUB     AH,OutPrec
        MOV     CL,InPrec
// Case where Output precision is less than input: cut it down
@@0:    CMP     AH,0
        JE      @@9
        LODSB
        CMP     AL,0
        JE      @@1
        MOV     [EDI],AL
        ADD     EDI,1
@@1:    SUB     AH,1
        CMP     AH,0
        JE      @@2
        SUB     AH,1
        SUB     CL,2
        JMP     @@0
@@2:    MOV     DL,AL              // save byte to DL: splitting required
        CMP     CH,InScale         // CH contains OutScale
        JBE     @@3
        MOV     CH,InScale         // # of digits to store =
@@3:    ADD     CH,OutPrec         // Min(InScale,OutScale) + OutPrec
        MOV     CL,0               // nothing stored yet
        CALL    _CopyOddFractions;
        MOV     CL,OutScale
        CMP     CL,InScale
        JBE     @@12
        SUB     CL,InScale
        CALL    _CopyRestBlank;
        JMP     @@12
@@4:    ADD     CL,InScale         // case where outputsize = input size, so just copy bytes
@@5:    CALL    _CopyBytes          // Otherwise, copy only Prec bytes
        CMP     CH,InScale
        JE      @@12
        MOV     CL,CH
        CALL    _CopyRestBlank
        JMP     @@12
// case where additional blank nibbles to prefixed to Fractions
@@6:    SUB     CL,InPrec
@@7:    CMP     CL,0
        JE      @@9
        SUB     CL,1
        CMP     CL,0
        JE      @@8
        MOV     AL,0                // add two blank nibbles
        STOSB
        SUB     CL,1
        JMP     @@7
@@8:    LODSB
        MOV     DL,AL                // save copy of input byte
        SHR     AL,4                 // get first nibble
        OR      AL,0
        STOSB
        MOV     AL,DL
        MOV     AH,InPrec
        MOV     OutPrec,AH
        MOV     CL,1               // 1 nibble stored already
        JMP     @@2
//      even # of fractions to copy
@@9:    MOV     CH,OutScale         // CL must be set to scale values to be copies.
        MOV     CL,InPrec
        CMP     CH,InScale
        JAE     @@10
        ADD     CL,CH
        JMP     @@11
@@10:   ADD     CL,InScale
@@11:   CALL    _CopyBytes
        MOV     CL,OutPrec
        CMP     CL,InPrec
        JBE     @@12
        SUB     CL,InPrec
        CALL    _CopyRestBlank;
@@12:   POP     EDX
        POP     ECX
        POP     EBX
        POP     EDI
        POP     ESI
end;

procedure StrToFraction(pTo: PChar; pFrom: PChar; count: SmallInt); pascal;
var
  Dot: Char;
begin
  Dot := DecimalSeparator;
  asm
   // From bytes to nibbles, both left aligned
        PUSH    ESI
        PUSH    EDI
        PUSH    EBX
        MOV     ESI,pFrom  // move pFrom to ESI
        MOV     EDI,pTo    // move pTo to EDI
        XOR     ECX,ECX    // set ECX to 0
        MOV     CX,count   // store count in CX
        MOV     DL,0       // Flag: when to store
        CLD
@@1:    LODSB              // moves [ESI] into al
        CMP     AL,Dot
        JE      @@4
        SUB     AL,'0'
        CMP     DL,0
        JNE     @@2
        SHL     AL,4
        MOV     AH,AL
        JMP     @@3
@@2:    OR      AL,AH     // takes AH and ors in AL
        STOSB             // always moves AL into [EDI]
@@3:    NOT     dl        // flip all bits
@@4:    LOOP    @@1       // decrements cx and checks if it's 0
        CMP     DL,0      // are any bytes left unstored?
        JE      @@5
        MOV     AL,AH     // if so, move to al
        STOSB             // and store to [EDI]
@@5:    POP     EBX
        POP     EDI
        POP     ESI
  end;
end;

function InvalidBcdString(PValue: PChar): Boolean; 
var
  Dot: Char;
  P: PChar;
begin
  Dot := DecimalSeparator;
  P := PValue;
  Result := False;
  while P^ <> #0 do
  begin
    if not (P^ in ['0'..'9', '-', Dot]) then
    begin
      Result := True;
      break;
    end;
    Inc(P);
  end;
end;

function TryStrToBcd(const AValue: string; var Bcd: TBcd): Boolean;
const
  spaceChars: set of Char = [ ' ', #6, #10, #13, #14];
  digits: set of Char = ['0'..'9'];
var
  Neg: Boolean;
  NumDigits, DecimalPos: Word;
  pTmp, pSource: PChar;
  Dot : Char;
begin
  Dot := DecimalSeparator;
  if InvalidBcdString(PChar(AValue)) then
  begin
    Result := False;
    exit;
  end;
  if (AValue = '0') or (AValue = '') then
  begin
    Result := True;
    Bcd.Precision := 8;
    Bcd.SignSpecialPlaces := 2;
    pSource := PChar(@Bcd.Fraction);
    FillChar(PSource^, SizeOf(Bcd.Fraction), 0);
    Exit
  end;
  Result := True;
  Neg := False;
  DecimalPos := Pos(Dot, AValue);

  pSource := pCHAR(AValue);
  { Strip leading whitespace }
  while (pSource^ in spaceChars) or (pSource^ = '0') do
  begin
    Inc(pSource);
    if DecimalPos > 0 then Dec(DecimalPos);
  end;

  { Strip trailing whitespace }
  pTmp := @pSource[ StrLen( pSource ) -1 ];
  while pTmp^ in spaceChars do
  begin
    pTmp^ := #0;
    Dec(pTmp);
  end;

  { Is the number negative? }
  if pSource^ = '-' then
  begin
    Neg := TRUE;
    if DecimalPos > 0 then Dec(DecimalPos);
  end;
  if (pSource^ = '-') or (pSource^ ='+') then
    Inc(pSource);

  { Clear structure }
  pTmp := pCHAR(@Bcd.Fraction);
  FillChar(pTmp^, SizeOf(Bcd.Fraction), 0);
  if (pSource[0] = '0') then
  begin
    Inc(PSource);  // '0.' scenario
    if DecimalPos > 0 then Dec(DecimalPos);
  end;
  NumDigits := StrLen(pSource);
  if (NumDigits > MaxFMTBcdFractionSize) then
  begin
    if (DecimalPos > 0) and (DecimalPos <= MaxFMTBcdFractionSize) then
      NumDigits := MaxFMTBcdFractionSize // truncate to 64
    else begin
      Bcd.Precision := NumDigits;
      Exit;
    end;
  end;

  if NumDigits > 0 then
    StrToFraction(pTmp, pSource, SmallInt(NumDigits))
  else begin
    Bcd.Precision := 10;
    Bcd.SignSpecialPlaces := 2;
  end;

  if DecimalPos > 0 then
  begin
    Bcd.Precision := Byte(NumDigits-1);
    if Neg then
      Bcd.SignSpecialPlaces := ( 1 shl 7 ) + (BYTE(NumDigits - DecimalPos))
    else
      Bcd.SignSpecialPlaces := ( 0 shl 7 ) + (BYTE(NumDigits - DecimalPos));
  end else
  begin
    Bcd.Precision := Byte(NumDigits);
    if Neg then
      Bcd.SignSpecialPlaces := (1 shl 7)
    else
      Bcd.SignSpecialPlaces := (0 shl 7);
  end;
end;

function SignificantIntDigits(const pIn: PChar; Digits: Word): Word; pascal;
asm
        PUSH    ESI
        PUSH    EBX
        MOV     ESI, pIn
        MOV     CX,Digits         // start with all digits
        CLD
@@1:    CMP     CX,0              // if 0,
        JE      @@3               // then end
        LODSB                     // load pIn BYTE into AL and
        CMP     AL,0              // if 0
        JNE     @@2
        SUB     CX,1              // then subtract 1 from CX
        CMP     CX,0              // make sure it's not 0
        JE      @@3
        SUB     CX,1              // subtract 1 again and
        JMP     @@1               // start again
@@2:    SHR     AL,4              // check last nibble
        CMP     AL,0              // if 0, then
        JNE     @@3
        SUB     CX,1              // subtract 1 more from CX
@@3:    MOV     Result,CX         // Result is CX
        POP     EBX
        POP     ESI
end;

procedure SubtractNormalizedFractions(const pIn1, pIn2, pOut: PChar; Digits: SmallInt); pascal;
var
  OddFlag: SmallInt;
begin
   asm
        PUSH    ESI
        PUSH    EDI
        PUSH    EBX
        PUSH    ECX
        PUSH    EDX
        MOV     OddFlag,0        // Flag for odd # of Digits
        MOV     CX,Digits
        MOV     DH,0        // Remainder
        MOV     EDI,pOut
        MOV     EBX,pIn1
        MOV     ESI,pIn2
@@0:    CMP     CX,2
        JBE     @@2
        ADD     EDI,1
        ADD     ESI,1
        ADD     EBX,1
        SUB     CX,1
        CMP     CX,2
        JNE     @@1
        MOV     OddFlag,1            // there are odd # of digits
        JMP     @@2
@@1:    SUB     CX,1
        JMP     @@0
@@2:    MOV     CX,Digits
@@3:    CMP     CX,0            // at end?
        JE      @@5
        CMP     OddFlag,1
        JNE     @@12
        MOV     AH,0
        MOV     OddFlag,0
        JMP     @@13
@@12:   MOV     AL,[ESI]
        MOV     AH,[EBX]
        AND     AL,15            // get last nibble
        AND     AH,15            //  values
        MOV     DL,AH
        SUB     DL,AL            // SUBTRACT [ESI] FROM [EBX]
        CALL    _GetSubRemainder // get remainder and
        MOV     AH,DL            // store in AH
        SUB     CX,1
        CMP     CX,0
        JE      @@4
@@13:   MOV     AL,[ESI]         // AH now has last values added
        MOV     DL,[EBX]         // so now get
        SHR     AL,4             //  first
        SHR     DL,4             //  values
        SUB     DL,AL            // into DL
        CALL    _GetSubRemainder
        SHL     DL,4
        OR      DL,AH
        MOV     [EDI],DL
        SUB     EDI,1
        SUB     ESI,1
        SUB     EBX,1
        SUB     CX,1
        JMP     @@3
@@4:    MOV     DL,0           // if end is reached on odd nibble
        OR      DL,AH          // OR with 0 and flush
        MOV     [EDI],DL
@@5:    POP     EDX
        POP     ECX
        POP     EBX
        POP     EDI
        POP     ESI
  end;
end;

procedure AddNormalizedFractions(const pIn1, pIn2, pOut: PChar; Digits: SmallInt); pascal;
var
  OddFlag: SmallInt;
begin
   asm
        PUSH    ESI
        PUSH    EDI
        PUSH    EBX
        PUSH    ECX
        PUSH    EDX
        MOV     CX,Digits
        MOV     DH,0        // Remainder
        MOV     EDI,pOut
        MOV     EBX,pIn1
        MOV     ESI,pIn2
        MOV     OddFlag,0
@@0:    CMP     CX,2
        JBE     @@2
        ADD     EDI,1
        ADD     ESI,1
        ADD     EBX,1
        SUB     CX,1
        CMP     CX,2
        JNE     @@1
        MOV     OddFlag,1
        JMP     @@2
@@1:    SUB     CX,1
        JMP     @@0
@@2:    MOV     CX,Digits
@@3:    CMP     CX,0           // at end?
        JE      @@5
        CMP     OddFlag,1
        JNE     @@12
        MOV     AH,0
        MOV     OddFlag,0
        JMP     @@13
@@12:   MOV     AL,[ESI]
        MOV     AH,[EBX]
        AND     AL,15            // get last nibble
        AND     AH,15            //  values
        MOV     DL,AH
        ADD     DL,AL            // Add 2 values
        CALL    _GetRemainder    // get remainder and
        MOV     AH,DL            // store in AH
        SUB     CX,1
        CMP     CX,0
        JE      @@4
@@13:   MOV     AL,[ESI]         // AH now has last values added
        MOV     DL,[EBX]         // so now get
        SHR     AL,4             //  first
        SHR     DL,4             //  values
        ADD     DL,AL            // into DL
        CALL    _GetRemainder
        SHL     DL,4
        OR      DL,AH
        MOV     [EDI],DL
        SUB     EDI,1
        SUB     ESI,1
        SUB     EBX,1
        SUB     CX,1
        JMP     @@3
@@4:    MOV     DL,0           // if end is reached on odd nibble
        OR      DL,AH          // OR with 0 and flush
        MOV     [EDI],DL
@@5:    POP     EDX
        POP     ECX
        POP     EBX
        POP     EDI
        POP     ESI
  end;
end;

// compare where both FRACTIONs have same # of Nibbles
function CompareNormalizedFractions(const pIn1, pIn2: PChar; Digits1, Digits2: SmallInt): Integer; pascal;
asm
        PUSH    ESI
        PUSH    EDI
        PUSH    EBX
        PUSH    EDX
        MOV     CX,Digits1
        MOV     DX,Digits2
        MOV     EDI,pIn2
        MOV     ESI,pIn1
        MOV     Result,0          // initialize Result to 0
        CLD
@@1:    CMP     CX,0
        JE      @@7               // no more digits
        LODSB                     // load [ESI] into AL
        MOV     AH,[EDI]          // load [EDI] into AH
        INC     EDI               // advance EDI
@@2:    CMP     AL,AH             // start by comparing 2 nibbles at once
        JNE     @@3
        SUB     CX,1
        SUB     DX,1
        CMP     CX,0
        JE      @@7
        SUB     CX,1
        SUB     DX,1
        JMP     @@1
@@3:    MOV     BL,AH             // don't appear to match:
        MOV     AH,AL             // put first nibble of
        SHR     AH,4              // input1 into AH, and first nibble
        MOV     BH,BL             // of input2 into bh,
        SHR     BH,4              // and them
        CMP     BH,AH             //
        JNE     @@4               //
        CMP     CX,0              // make sure we didn't end on odd-nibble
        JE      @@7
        MOV     AH,AL             // it's the 2nd nibble that's different
        MOV     BH,BL             // so move 2nd nibble
        AND     AH,15             // for input1 and input2
        AND     BH,15             // into AH and BH
@@4:    CMP     BH,AH             // we know they're not the same
        JA      @@6
@@5:    MOV     Result,1          // input1 > input2
        JMP     @@8
@@6:    MOV     Result,-1         // input2 > input1
        JMP     @@8
@@7:    CMP     DX,0
        JLE     @@8
        MOV     AH,[EDI]          // Digits2 > Digits1:
        INC     EDI
        SUB     DX,2              // All must be 0 or Fail
        CMP     AH,0
        JE      @@7
        CMP     Result,0
        JNE     @@8
        MOV     Result,-1
@@8:    POP     EDX
        POP     EBX
        POP     EDI
        POP     ESI
end;

function ReverseNegative(SignSpecialPlaces: Byte): Byte;
begin
  if (SignSpecialPlaces and (1 shl 7)) <> 0 then
    Result := (SignSpecialPlaces and 63)
  else
    Result := (SignSpecialPlaces and 63) or (1 shl 7);
end;

function NormalizeBcd(const InBcd: TBcd; var OutBcd: TBcd; const Prec, Scale: Word): Boolean;
var
  PIn, POut: PChar;
  I: Integer;
  Start, DecDigits: SmallInt;
  Negative: Boolean;
begin
  Result := True;
  if (Word(InBcd.Precision) = Prec) and (Word(InBcd.SignSpecialPlaces and 63) = Scale) then
    OutBcd := InBcd
  else 
  begin
    Negative := InBcd.SignSpecialPlaces and (1 shl 7) <> 0;
    DecDigits := InBcd.SignSpecialPlaces and 63;
    OutBcd.Precision := Prec;
    OutBcd.SignSpecialPlaces := Scale;
    PIn := PChar(@InBcd.Fraction);
    POut := PChar(@OutBcd.Fraction);
    FillChar(POut^, SizeOf(OutBcd.Fraction), 0);
    if (Prec < Word(InBcd.Precision)) and (SignificantIntDigits(pIn, Word(InBcd.Precision)) > Prec) then
      Result := False
    else
    begin
    { Precision is IntegerDigits, Scale is Decimal Digits }
      NormalizeFractions(PIn, SmallInt(InBcd.Precision - DecDigits),
          DecDigits, Prec-(Scale and 63), Scale and 63, pOut);
      if Negative and (OutBcd.SignSpecialPlaces and (1 shl 7) = 0) then
        OutBcd.SignSpecialPlaces := ReverseNegative(OutBcd.SignSpecialPlaces);
    end;
  end;
  { Guarantee unused Nibbles are blank }
  POut := PChar(@OutBcd.Fraction);
  Start := OutBcd.Precision div 2;
  if (OutBcd.Precision mod 2) = 1 then Inc(Start);
  for I := Start to SizeOf(OutBcd.Fraction) -1 do
    POut[I] := #0;
end;

function NumberOfDigits(const ABcd: TBcd): Integer;
var
  PFractions: PChar;
begin
  Result := ABcd.Precision;
  PFractions := PChar(@Abcd.Fraction);
  while (Result > 1) and (PFractions^ = #0) do
  begin
    Dec(Result, 2);   // decrement two nibbles per byte
    Inc(PFractions);
  end;
end;

function CompactBcd(const ABcd: TBcd; const MinSize: Integer): TBcd;
var
  PFractions, POut: PChar;
begin
  if ABcd.Precision <= MinSize then
  begin
    Result := ABcd;
    exit;
  end;
  Result.Precision := ABcd.Precision;
  Result.SignSpecialPlaces := ABcd.SignSpecialPlaces;
  POut := PChar(@Result.Fraction);
  FillChar(pOut^, SizeOf(Result.Fraction), 0);
  PFractions := PChar(@ABcd.Fraction);
  while (Result.Precision > MinSize) and (PFractions^ = #0) do
  begin
    Dec(Result.Precision,2);
    Inc(PFractions);
  end;
  Move(PFractions^, POut^, 1 + (Result.Precision + BcdScale(Result)));
end;

procedure NormalizeBcdPair(const BcdIn1, BcdIn2: TBcd; var bcdOut1, bcdOut2: TBcd; ExtraDigits: Word = 0 );
var
  Digits: Word;
  Bcd1, Bcd2: TBcd;

  { Shift Fractions one Nibble to Left }
  procedure MoveNibbles(var POut: PChar; const PIn: PChar; const Size: Byte);
  var
    I: Integer;
    P1: PChar;
    N1, N2: BYTE;
  begin
    I := 0;
    P1 := PIn;
    n1 := BYTE(POut^);
    while I < Size do
    begin
      N2 := Byte(P1^);
      POut^ := Char((Byte(N1 AND 15) SHL 4) OR Byte(N2 SHR 4));
      N1 := N2;
      Inc(POut);
      Inc(P1);
      Inc(I,2);
    end;
  end;

  { Guarantee Bcd has even number Precision }
  function AdjustNibbles(ABcd: TBcd): TBcd;
  var
    POut, PBcd: PChar;
    I, Start: Integer;
  begin
    Result := ABcd;
    if (ABcd.Precision mod 2) <> 0 then
    begin
      PBcd := PChar(@ABcd.Fraction);
      POut := PChar(@Result.Fraction);
      POut^ := #0;
      Result.Precision := ABcd.Precision +1;
      MoveNibbles(POut, PBcd, ABcd.Precision);
    end;
    { Guarantee unused Nibbles are blank}
    POut := PChar(@Result.Fraction);
    Start := (Result.Precision div 2);
    for I := Start to SizeOf(Result.Fraction) -1 do
      POut[I] := #0;
  end;

begin
  Bcd1 := AdjustNibbles(BcdIn1);
  Bcd2 := AdjustNibbles(BcdIn2);
  Digits := Max(NumberOfDigits(bcdIn1), NumberOfDigits(bcdIn2));
  if (Bcd1.Precision > 32) or (Bcd2.Precision > 32) then
  begin
    Bcd1 := CompactBcd(Bcd1, Digits);
    Bcd2 := CompactBcd(Bcd2, Digits);
  end;
  NormalizeBcd(Bcd1, BcdOut1, Max(Bcd1.Precision, Bcd2.Precision), Max(BcdScale(Bcd1), BcdScale(Bcd2)));
  NormalizeBcd(Bcd2, BcdOut2, Max(Bcd1.Precision, Bcd2.Precision), Max(BcdScale(Bcd1), BcdScale(Bcd2)));
end;

function BcdCompare(const Bcd1, Bcd2: TBcd): Integer;
var
  TempBcd1, TempBcd2: TBcd;
  PBcd1, PBcd2: PChar;
  Digits1,Digits2: ShortInt;
  Negative: Boolean;
begin
  if (Bcd1.SignSpecialPlaces and (1 shl 7)) <> (Bcd2.SignSpecialPlaces and (1 shl 7)) then
  begin  // if Negative setting doesn't match.
    if (Bcd1.SignSpecialPlaces and (1 shl 7)) <> 0 then
      Result := -1
    else
      Result := 1;
  end else
  begin  // both Negative or both Positive
    Negative := (Bcd1.SignSpecialPlaces and (1 shl 7)) <> 0;
    pBcd1 := pCHAR(@Bcd1.Fraction);   // move to fractions
    pBcd2 := pCHAR(@Bcd2.Fraction);   // move to fractions
    Digits1 := SignificantIntDigits(pBcd1, SmallInt(Bcd1.Precision - (Bcd1.SignSpecialPlaces and 63)));
    Digits2 := SignificantIntDigits(pBcd2, SmallInt(Bcd2.Precision - (Bcd2.SignSpecialPlaces and 63)));
    if Digits1 <> Digits2 then
    begin
      if Digits1 > Digits2 then
        Result := 1
      else
        Result := -1;
    end else
    begin
      NormalizeBcdPair(Bcd1, Bcd2, TempBcd1, TempBcd2);
      PBcd1 := PChar(@TempBcd1.Fraction);
      PBcd2 := PChar(@TempBcd2.Fraction);
      Result := CompareNormalizedFractions(pBcd1, pBcd2, TempBcd1.Precision, TempBcd2.Precision);
    end;
    if Negative then Result := -Result;
  end;
end;

procedure BcdSubtract(const bcdIn1, bcdIn2: TBcd; var bcdOut: TBcd);
var
  newBcd2: TBcd;
begin
  newBcd2 := bcdIn2;
  newBcd2.SignSpecialPlaces := ReverseNegative(newBcd2.SignSpecialPlaces);
  BcdAdd(bcdIn1, newBcd2, bcdOut);
end;

procedure BcdMultiply(StringIn1, StringIn2: string; var bcdOut: TBcd); overload;
var
  Output: string;
  NegCount: Integer;
begin
  NegCount := 0;
  if PChar(StringIn1)[0] = '-' then
  begin
    Inc(NegCount);
    StringIn1 := Copy(StringIn1, 2, Length(StringIn1)-1);
  end;
  if PChar(StringIn2)[0] = '-' then
  begin
    Inc(NegCount);
    StringIn2 := Copy(StringIn2, 2, Length(StringIn2)-1);
  end;
  Output := _Multiply(StringIn1, StringIn2);
  bcdOut := StrToBcd(Output);
  if (NegCount mod 2) <> 0 then
    bcdOut.SignSpecialPlaces := (bcdOut.SignSpecialPlaces and 63) or (1 shl 7);
end;

procedure BcdMultiply(const bcdIn1, bcdIn2: TBcd; var bcdOut: TBcd);
begin
  BcdMultiply(BcdToStr(bcdIn1), BcdToStr(bcdIn2), bcdOut);
end;

procedure BcdMultiply(const bcdIn: TBcd; const DoubleIn: Double; var bcdOut: TBcd);
begin
  BcdMultiply(BcdToStr(bcdIn), FloatToStr(DoubleIn), bcdOut);
end;

procedure BcdMultiply(const bcdIn: TBcd; const StringIn: string; var bcdOut: TBcd);
begin
  BcdMultiply(BcdToStr(bcdIn), StringIn, bcdOut);
end;

procedure BcdDivide(Dividend, Divisor: string; var bcdOut: TBcd); overload;
var
  Output: string;
  NegCount: Integer;
  MaxDecimals: Byte;
begin
  NegCount := 0;        
  MaxDecimals := bcdOut.signSpecialPlaces and 63;
  if MaxDecimals = 0 then MaxDecimals := _DefaultDecimals;
  if PChar(Dividend)[0] = '-' then
  begin
    Inc(NegCount);
    Dividend := Copy(Dividend, 2, Length(Dividend)-1);
  end;
  if PChar(Divisor)[0] = '-' then
  begin
    Inc(NegCount);
    Divisor := Copy(Divisor, 2, Length(Divisor)-1);
  end;
  Output := RoundAt(_Divide(Dividend, Divisor), MaxDecimals);
  bcdOut := StrToBcd(Output);
  if (NegCount mod 2) <> 0 then
    bcdOut.SignSpecialPlaces := (bcdOut.SignSpecialPlaces and 63) or (1 shl 7);
end;

procedure BcdDivide(const Dividend, Divisor: TBcd; var bcdOut: TBcd);
begin
  BcdDivide(BcdToStr(Dividend), BcdToStr(Divisor), bcdOut);
end;

procedure BcdDivide(const Dividend: TBcd; const Divisor: Double; var bcdOut: TBcd);
begin
  BcdDivide(BcdToStr(Dividend), FloatToStr(Divisor), bcdOut);
end;

procedure BcdDivide(const Dividend: TBcd; const Divisor: string; var bcdOut: TBcd);
begin
  BcdDivide(BcdToStr(Dividend), Divisor, bcdOut);
end;

procedure BcdAdd(const bcdIn1, bcdIn2: TBcd; var bcdOut: TBcd);
var
  bcd1, bcd2: TBcd;
  pIn1, pIn2, pOut: PChar;
  Prec, Scale: Word;
  Neg1, Neg2: Boolean;
  Digits1, Digits2: Integer;
begin
  NormalizeBcdPair(bcdIn1, bcdIn2, bcd1, bcd2, 1);
  Prec := bcd1.Precision;
  Scale := bcd1.SignSpecialPlaces;
  Neg1 := (BcdIn1.SignSpecialPlaces and (1 shl 7)) <> 0;
  Neg2 := (BcdIn2.SignSpecialPlaces and (1 shl 7)) <> 0;
  bcdOut.Precision := Prec;
  if (Neg1 = Neg2) or ((bcd1.SignSpecialPlaces and 63) >= (bcd2.SignSpecialPlaces and 63)) then
    bcdOut.SignSpecialPlaces := Scale
  else
    bcdOut.SignSpecialPlaces := ReverseNegative(Scale);
  pIn1 := PChar(@bcd1.Fraction);
  pIn2 := PChar(@bcd2.Fraction);
  pOut := PChar(@bcdOut.Fraction);
  FillChar(pOut^, SizeOf(bcdOut.Fraction), 0);
  if Neg1 = Neg2 then
    AddNormalizedFractions(pIn1, pIn2, pOut, prec)
  else
  begin
    Digits1 := SignificantIntDigits(pIn1, Prec);
    Digits2 := SignificantIntDigits(pIn2, Prec);
    if Digits1 > Digits2 then
      SubtractNormalizedFractions(pIn1,pIn2,pOut, Prec)
    else if Digits2 > Digits1 then
    begin
      SubtractNormalizedFractions(pIn2,pIn1,pOut,prec);
      bcdOut.SignSpecialPlaces := ReverseNegative(bcdOut.SignSpecialPlaces);
    end
    else if CompareNormalizedFractions(pIn1,pIn2,prec,prec) >= 0 then
      SubtractNormalizedFractions(pIn1,pIn2,pOut, prec)
    else
    begin
      SubtractNormalizedFractions(pIn2,pIn1,pOut,prec);
      bcdOut.SignSpecialPlaces := ReverseNegative(bcdOut.SignSpecialPlaces);
    end;
  end;
end;

function FractionToStr(const pIn: PChar; count: SmallInt;
         DecPosition: ShortInt; Negative: Boolean;
         StartWithDecimal: Boolean): string;
var
  NibblesIn, BytesIn, DigitsOut: Integer;
  P, POut: PChar;
  Dot: Char;

  procedure AddOneChar(Value: Char);
  begin
    P[0] := Value;
    Inc(P);
    Inc(DigitsOut);
  end;
  procedure AddDigit(Value: Char);
  begin
    if ((DecPosition > 0) and (NibblesIn  = DecPosition)) or
       ((NibblesIn = 0) and StartWithDecimal) then
    begin
      if DigitsOut = 0 then AddOneChar('0');
      AddOneChar(Dot);
    end;
    if (Value > #0) or (DigitsOut > 0) then
      AddOneChar(Char(Integer(Value)+48));
    Inc(NibblesIn);
  end;

begin
  POut := AllocMem(Count + 3);  // count + negative/decimal/zero
  try
    Dot := DecimalSeparator;
    P := POut;
    DigitsOut := 0;
    BytesIn := 0;
    NibblesIn := 0;
    while NibblesIn < Count do
    begin
      AddDigit(Char(Integer(pIn[BytesIn]) SHR 4));
      if NibblesIn < Count then
        AddDigit(Char(Integer(pIn[BytesIn]) AND 15));
      Inc(BytesIn);
    end;
    while (DecPosition > 0) and (NibblesIn  > DecPosition) and (DigitsOut > 1) do
    begin
      if POut[DigitsOut-1] = '0' then
      begin
        Dec(DigitsOut);
        POut[DigitsOut] := #0;
      end else
        break;
    end;
    if POut[DigitsOut-1] = Dot then
      Dec(DigitsOut);
    POut[DigitsOut] := #0;
    SetString(Result, POut, DigitsOut);
  finally
    FreeMem(POut, Count + 2);
  end;
  if Result = '' then Result := '0'
  else if Negative then Result := '-' + Result;
end;

function BcdToStr(const Bcd: TBcd): string;
var
  NumDigits: Integer;
  pStart: PChar;
  DecPos: SmallInt;
  Negative: Boolean;
begin
  if (Bcd.Precision = 0) or (Bcd.Precision > MaxFMTBcdFractionSize) then
    OverFlowError(SBcdOverFlow)
  else
  begin
    Negative := Bcd.SignSpecialPlaces and (1 shl 7) <> 0;
    NumDigits := Bcd.Precision;
    pStart := pCHAR(@Bcd.Fraction);   // move to fractions
    // use lower 6 bits of iSignSpecialPlaces.
    if (Bcd.SignSpecialPlaces and 63) > 0 then
    begin
      DecPos := ShortInt(NumDigits - (Bcd.SignSpecialPlaces and 63));
    end else
      DecPos := NumDigits + 1;     // out of range
    Result := FractionToStr(pStart, NumDigits, DecPos, Negative,
           (NumDigits = Bcd.SignSpecialPlaces and 63));
    if Result[1] in ['0', '-'] then
      if (Result = '-0') or (Result = '0.0') or (Result = '-0.0') then Result := '0';
  end;
end;

function BcdPrecision(const Bcd: TBcd): Word;
begin
  Result := Bcd.Precision - BcdScale(Bcd);
end;

function BcdScale(const Bcd: TBcd): Word;
begin
  Result := (Bcd.SignSpecialPlaces and 63);
end;

function IsBcdNegative(const Bcd: TBcd): Boolean;
begin
  Result := (Bcd.SignSpecialPlaces and (1 shl 7)) <> 0;
end;

function IsBcdZero(const Bcd: TBcd): Boolean;
var
  P: PChar;
  I, Scale: Integer;
begin
  Result := True;
  P := PChar(@Bcd.Fraction);
  I := 0;
  Scale := BcdScale(Bcd);
  while Result and (I < Scale div 2) do
  begin
    if Byte(P^) <> 0 then
      Result := False;
    Inc(P);
    Inc(I);
  end;
{ if odd nibble, check it }
  if Result and (Scale mod 2 > 0) then
    if (Byte(P^) SHR 4) > 0 then
      Result := False;
end;











function CurrToBCD(const Curr: Currency; var BCD: TBcd; Precision: Integer = 32;
  Decimals: Integer = 4): Boolean;
const
  Power10: array[0..3] of Single = (10000, 1000, 100, 10);
var
  Digits: array[0..63] of Byte;
asm
        PUSH    EBX
        PUSH    ESI
        PUSH    EDI
        MOV     ESI,EAX
        XCHG    ECX,EDX








        MOV     [ESI].TBcd.Precision,CL
        MOV     [ESI].TBcd.SignSpecialPlaces,DL
@@1:    SUB     EDX,4
        JE      @@3
        JA      @@2
        FILD    Curr  



        FDIV    Power10.Single[EDX*4+16]

        FISTP   Curr
        JMP     @@3
@@2:    DEC     ECX
        MOV     Digits.Byte[ECX],0
        DEC     EDX
        JNE     @@2
@@3:    MOV     EAX,Curr.Integer[0]
        MOV     EBX,Curr.Integer[4]
        OR      EBX,EBX
        JNS     @@4
        NEG     EBX
        NEG     EAX
        SBB     EBX,0
        OR      [ESI].TBcd.SignSpecialPlaces,80H
@@4:    MOV     EDI,10
@@5:    MOV     EDX,EAX
        OR      EDX,EBX
        JE      @@7
        XOR     EDX,EDX
        OR      EBX,EBX
        JE      @@6
        XCHG    EAX,EBX
        DIV     EDI
        XCHG    EAX,EBX
@@6:    DIV     EDI
@@7:    MOV     Digits.Byte[ECX-1],DL
        DEC     ECX
        JNE     @@5
        OR      EAX,EBX
        MOV     AL,0
        JNE     @@9
        MOV     CL,[ESI].TBcd.Precision
        INC     ECX
        SHR     ECX,1
@@8:    MOV     AX,Digits.Word[ECX*2-2]
        SHL     AL,4
        OR      AL,AH
        MOV     [ESI].TBcd.Fraction.Byte[ECX-1],AL
        DEC     ECX
        JNE     @@8
        MOV     AL,1
@@9:    POP     EDI
        POP     ESI
        POP     EBX
end;

function BCDToCurr(const BCD: TBcd; var Curr: Currency): Boolean;
const
  FConst10: Single = 10;
  CWNear: Word = $133F;
var
  CtrlWord: Word;
  Temp: Integer;
  Digits: array[0..63] of Byte;
asm
        PUSH    EBX
        PUSH    EDI
        PUSH    ESI










        XOR     EBX,EBX

        MOV     EDI,EAX
        MOV     ESI,EDX
        MOV     AL,0
        MOVZX   EDX,[EDI].TBcd.Precision
        OR      EDX,EDX
        JE      @@8
        LEA     ECX,[EDX+1]
        SHR     ECX,1
@@1:    MOV     AL,[EDI].TBcd.Fraction.Byte[ECX-1]
        MOV     AH,AL
        SHR     AL,4
        AND     AH,0FH
        MOV     Digits.Word[ECX*2-2],AX
        DEC     ECX
        JNE     @@1
        XOR     EAX,EAX
@@2:    MOV     AL,Digits.Byte[ECX]
        OR      AL,AL
        JNE     @@3
        INC     ECX
        CMP     ECX,EDX
        JNE     @@2
        FLDZ
        JMP     @@7
@@3:    MOV     Temp,EAX
        FILD    Temp
@@4:    INC     ECX
        CMP     ECX,EDX
        JE      @@5
        FMUL    [EBX].FConst10
        MOV     AL,Digits.Byte[ECX]
        MOV     Temp,EAX
        FIADD   Temp
        JMP     @@4
@@5:    MOV     AL,[EDI].TBcd.SignSpecialPlaces
        OR      AL,AL
        JNS     @@6
        FCHS
@@6:    AND     EAX,3FH
        SUB     EAX,4
        NEG     EAX
        CALL    FPower10
@@7:    FSTCW   CtrlWord
        FLDCW   [EBX].CWNear
        FISTP   [ESI].Currency
        FSTSW   AX
        NOT     AL
        AND     AL,1
        FCLEX
        FLDCW   CtrlWord
        FWAIT
@@8:
        POP     ESI
        POP     EDI
        POP     EBX
end;

procedure CopyByte(var Buffer: array of Char; const Byte: Char; var Pos: Integer);
begin
  Buffer[Pos] := Byte;
  Inc(Pos);
end;

{ ffGeneral - General number format. The value is converted to the shortest
  possible decimal string using fixed format. Trailing zeros
  are removed from the resulting string, and a decimal point appears only
  if necessary. The resulting string uses fixed point format if the number
  of digits to the left of the decimal point in the value is less than or
  equal to the specified precision.  Otherwise an exception is thrown }

function BcdGeneralFormat(const Bcd: TBcd; const Precision, Digits: Integer): string;
begin
  Result := BcdToStr(Bcd);
end;
  
{ ffExponent - Scientific format. Not supported for FMTBcd -- Bcd is 
  by definition fixed format }

function BcdScientificFormat(const Bcd: TBcd; const Precision, Digits: Integer): string;
begin
  BcdError(SInvalidFormatType);
end;

{ ffFixed - Fixed point format. The value is converted to a string of the
  form "-ddd.ddd...". The resulting string starts with a minus sign if the
  number is negative, and at least one digit always precedes the decimal
  point. The number of digits after the decimal point is given by the Digits
  parameter--it must be between 0 and 18. If the value has more decimal values
  than permitted by Digits, it is truncated.  If the number of digits to the
  left of the decimal point is greater than the specified precision, an
  exception is thrown 
  ffNumber - Number format. The ffNumber format corresponds to the ffFixed
  format, except that the resulting string contains thousand separators. }

function BcdFixedOrNumberFormat(const Start: string; Format: TFloatFormat; const Precision, Digits: Integer): string;
var
  P: PChar;
  AddCommaDigits, DecDigits, BufPos: Integer;
  Buffer: array[0..255] of Char;
  Comma, Dot: Char;
begin
  BufPos := 0;
  Dot := DecimalSeparator;
  Comma := ThousandSeparator;
  Result := Start;
  P := PChar(Result);
  DecDigits := -1;
  if Format = ffNumber then
  begin
    AddCommaDigits := Pos(Dot, Result);
    if AddCommaDigits > 0 then
      Dec(AddCommaDigits)
    else
      AddCommaDigits := Length(Result);
  end else
    AddCommaDigits := 0;
  if P^ = '-' then
  begin
    CopyByte(Buffer, P^, BufPos);
    Inc(P);
    if AddCommaDigits > 0 then Dec(AddCommaDigits);
  end;
  while P^ <> #0 do
  begin
    CopyByte(Buffer, P^, BufPos);
    if P^ = Dot then
      DecDigits := 0
    else if DecDigits > -1 then
      Inc(DecDigits);
    Inc(P);
    if AddCommaDigits > 3 then
    begin
      Dec(AddCommaDigits);
      if (AddCommaDigits mod 3 = 0) then
        CopyByte(Buffer, Comma, BufPos);
    end;
  end;
  if DecDigits = -1 then
  begin
    if Digits > 0 then
      CopyByte(Buffer, Dot, BufPos);
    DecDigits := 0;
  end;
  while DecDigits < Digits do
  begin
    CopyByte(Buffer, '0', BufPos);
    Inc(DecDigits);
  end;
  if Buffer[BufPos -1] = Dot then
    Dec(BufPos);
  Buffer[BufPos] := #0;
  SetString(Result, Buffer, BufPos);
  Result := RoundAt( Result, Digits);
end;

{ ffCurrency - Currency format. The value is converted to a string that
  represents a currency amount. The conversion is controlled by the
  CurrencyString, CurrencyFormat, NegCurrFormat, ThousandSeparator, and
  DecimalSeparator global variables
  The number of digits after the decimal point is given by the Digits
  parameter--it must be between 0 and 18. }

{  0 = '$1',   1 = '1$',    2 = '$ 1',  3 = '1 $' }
function AddCurrencySymbol(const Value, CurrSymbol: string; const CurrFormat: Byte): string;
begin
  case CurrFormat of 
    0: Result := Format('%s%s', [CurrSymbol, Value]);
    1: Result := Format('%s%s', [Value, CurrSymbol]);
    2: Result := Format('%s %s', [CurrSymbol, Value]);
    3: Result := Format('%s %s', [Value, CurrSymbol]);
  end;
end;

{   0 = '($1)'      4 = '(1$)'      8 = '-1 $'      12 = '$ -1'
    1 = '-$1'       5 = '-1$'       9 = '-$ 1'      13 = '1- $'
    2 = '$-1'       6 = '1-$'      10 = '1 $-'      14 = '($ 1)'
    3 = '$1-'       7 = '1$-'      11 = '$ 1-'      15 = '(1 $)'  }
function AddNegCurrencySymbol(const Value, CurrSymbol: string; const CurrFormat: Byte): string;
begin
  case CurrFormat of 
    0: Result := Format('(%s%s)', [CurrSymbol, Value]);
    1: Result := Format('-%s%s', [CurrSymbol, Value]);
    2: Result := Format('%s-%s', [CurrSymbol, Value]);
    3: Result := Format('%s%s-', [CurrSymbol, Value]);
    4: Result := Format('(%s%s)', [Value, CurrSymbol]);
    5: Result := Format('-%s%s', [Value, CurrSymbol]);
    6: Result := Format('%s-%s', [Value, CurrSymbol]);
    7: Result := Format('%s%s-', [Value, CurrSymbol]);
    8: Result := Format('-%s %s', [Value, CurrSymbol]);
    9: Result := Format('-%s %s', [CurrSymbol, Value]);
   10: Result := Format('%s %s-', [Value, CurrSymbol]);
   11: Result := Format('%s %s-', [CurrSymbol, Value]);
   12: Result := Format('%s %s', [CurrSymbol, Value]);
   13: Result := Format('%s -%s', [Value, CurrSymbol]);
   14: Result := Format('(%s- %s)', [CurrSymbol, Value]);
   15: Result := Format('(%s %s)', [Value, CurrSymbol]);
  end;
end;

function BcdCurrencyFormat(const Bcd: TBcd; const Start: string; const Precision, Digits: Integer): string;
var
  CurrSymbol: string;
  CurrFormat: Byte;
  NegFormat: Byte;
begin
  CurrSymbol := CurrencyString;
  CurrFormat := CurrencyFormat;
  NegFormat := NegCurrFormat;
  Result := BcdFixedOrNumberFormat(Start, ffNumber, Precision, Digits);
  if IsBcdNegative(Bcd) then
    Result := AddNegCurrencySymbol(String(PChar(Result)+1), CurrSymbol, NegFormat)
  else
    Result := AddCurrencySymbol(Result, CurrSymbol, CurrFormat);
end;

function BcdToStrF(const Bcd: TBcd; Format: TFloatFormat; const Precision, Digits: Integer): string;
begin
  Result := BcdGeneralFormat(Bcd, Precision, Digits);
  case Format of
    ffExponent:
      Result := BcdScientificFormat(Bcd, Precision, Digits);
    ffCurrency:
      Result := BcdCurrencyFormat(Bcd, Result, Precision, Digits);
    ffFixed, ffNumber:
      Result := BcdFixedOrNumberFormat(Result, Format, Precision, Digits);
  end;
end;

function ExtractMoneySymbol( var CurrencyPos: Integer; var HoldFormat: String): string;
var
  TempPos: Integer;
begin
  TempPos := CurrencyPos;
  Result := '$';
  while (CurrencyPos > 0) and (HoldFormat[CurrencyPos-1] = ' ') do
  begin
    Dec(CurrencyPos);
    Result := ' ' + Result;
  end;
  while (TempPos < Length(HoldFormat)) and (HoldFormat[TempPos+1] = ' ') do
  begin
    Inc(TempPos);
    Result := Result + ' ';
  end;
  HoldFormat := StringReplace(HoldFormat, Result, '', []);
  Result := StringReplace(Result, '$', CurrencyString, []);
end;

procedure CalcPrecisionAndDigits( const HoldFormat: string; var Precision, Digits, ReqIntDigits: Integer);
begin
  if Digits > 0 then
  begin
    ReqIntDigits := Digits -1;
    Precision := Length(HoldFormat) -1;
    Digits := Length(HoldFormat) - Digits;
  end else
  begin
    Precision := Length(HoldFormat);
    ReqIntDigits := Precision;
    Digits := 0;
  end;
end;

function PadInputString(var InputString: string; var Precision: Integer; const ReqIntDigits: Integer): Boolean;
var
  DecSep: Char;
  IntDigits, PadCount: Integer;
begin
  Result := True;
  DecSep := DecimalSeparator;
  IntDigits := Pos(DecSep, InputString);
  if IntDigits = 0 then
    IntDigits := Length(InputString)
  else
    Dec(IntDigits);
  PadCount := ReqIntDigits - IntDigits;
  if PadCount > 0 then
  begin
    InputString := '1' + StringOfChar('0', PadCount -1) + InputString;
    Inc(Precision);
  end else
    Result := False;
end;

procedure AddCurrency(var Output: string; const CurrencyPos: Integer; const MoneySymbol: string);
begin
  if CurrencyPos = 1 then
    Output := MoneySymbol + Output
  else if CurrencyPos >= Length(Output) then
    Output := Output + MoneySymbol
  else
    Output := Copy(Output, 1, CurrencyPos -1 ) + MoneySymbol +
      Copy(Output, CurrencyPos, Length(Output));
end;

type
  TLiteralInfo = class
  private
    FValue: string;
    FPosition: Integer;
  public
    property Value: string read FValue write FValue;
    property Position: Integer read FPosition write FPosition;
    constructor Create(Val: string; Pos: Integer);
  end;

constructor TLiteralInfo.Create;
begin
  FValue := Val;
  FPosition := Pos;
end;

procedure ExtractLiterals(LiteralList: TList; var HoldFormat: string);
const
  FormatChars = ['#', '0', ',', '.'];
  LiteralMarkers = [#39, '"'];
var
  P, PStart: PChar;
  I, Pos, LiteralPos: Integer;
  LiteralString: string;
  InLiteral: Boolean;
begin
  InLiteral := False;
  P := PChar(HoldFormat);
  LiteralPos := 0;
  Pos := 0;
  LiteralString := '';
  while P^ <> #0 do
  begin
    if P^ in LiteralMarkers then
      InLiteral := not InLiteral
    else if not (P^ in FormatChars) then
    begin
      LiteralPos := Pos;
      PStart := P;
      while ((InLiteral) or not (P^ in FormatChars)) do
      begin
        Inc(P);
        Inc(Pos);
        if (P^ in LiteralMarkers) or (P^ = #0) then
        begin
          InLiteral := False;
          break;
        end;
      end;
      SetString(LiteralString, PStart, P-PStart);
    end;
    if (not InLiteral) and (LiteralString <> '') then
    begin
      LiteralList.Add(TLiteralInfo.Create(LiteralString, LiteralPos));
      LiteralString := '';
    end;
    if P^ <> #0 then Inc(P);
    Inc(Pos);
  end;
  for I := 0 to LiteralList.Count -1 do
    HoldFormat := StringReplace(HoldFormat, TLiteralInfo(LiteralList.Items[I]).Value, '', []);
end;

procedure AddLiterals(LiteralList: TList; var Output: string; const Format: string);
var
  I, Add: Integer;
  Pos: Integer;
begin
  Add := (Length(Output)+1) - Length(Format);
  if Add < 0 then Add := 0;
  for I := 0 to LiteralList.Count -1 do
  begin
    Pos := TLiteralInfo(LiteralList.Items[I]).Position;
    if Pos = 0 then
      Output := TLiteralInfo(LiteralList.Items[I]).Value + Output
    else if (Pos + Add) < Length(Output) then
    begin
      Inc(Pos, Add);
      Output := Copy(Output, 1, Pos -1 ) + TLiteralInfo(LiteralList.Items[I]).Value +
           Copy(Output, Pos, length(Output) - (Pos -1));
    end else
      Output := Output + TLiteralInfo(LiteralList.Items[I]).Value;
    TLiteralInfo(LiteralList.Items[I]).Free;
  end;
end;

function FormatOneBcd(const Format: string; Bcd: TBcd): string;
const
  Dot: Char = '.';
var
  Precision, Digits, ReqDigits: Integer;
  TempPos, CurrencyPos: Integer;
  MoneySymbol: string;
  FFormat: TFloatFormat;
  LeftPadZeros, RightPadZeros, UseCommas: Boolean;
  Neg, HoldFormat: string;
  LiteralList: TList;
begin
  Neg := '';
  LiteralList := TList.Create;
  try
    HoldFormat := Format;
    CurrencyPos := Pos('$', Format);
    if CurrencyPos > 0 then
      MoneySymbol := ExtractMoneySymbol(CurrencyPos, HoldFormat);
    ExtractLiterals(LiteralList,HoldFormat);
    UseCommas := (Pos(',', HoldFormat) > 0);
    if UseCommas then
      HoldFormat := StringReplace(HoldFormat, ',', '', []);
    Digits := Pos(Dot, HoldFormat);
    CalcPrecisionAndDigits(HoldFormat, Precision, Digits, ReqDigits);
    TempPos := Pos('0', HoldFormat);
    LeftPadZeros := (TempPos > 0) and (TempPos < ReqDigits);
    TempPos := Pos('0', Copy(HoldFormat, ReqDigits, Digits + 1));
    RightPadZeros := TempPos > 0;
    if UseCommas then
      FFormat := ffNumber
    else
      if RightPadZeros or (Digits < BcdScale(Bcd)) then
        FFormat := ffFixed
      else
        FFormat := ffGeneral;
    Result := BcdGeneralFormat(Bcd, Precision, Digits);
    if IsBcdNegative(Bcd) then
    begin
      Neg := '-';
      Result := StringReplace(Result, Neg, '', []);
      Inc(CurrencyPos);
    end;
    if LeftPadZeros then
      LeftPadZeros := PadInputString(Result, Precision, ReqDigits);
    if FFormat <> ffGeneral then
      Result := BcdFixedOrNumberFormat(Result, FFormat, Precision, Digits);
    if LeftPadZeros then
      Result := Neg + '0' + Copy(Result, 2, Length(Result) -1)
    else
      Result := Neg + Result;
    if MoneySymbol <> '' then
      AddCurrency(Result, CurrencyPos, MoneySymbol);
    AddLiterals(LiteralList, Result, HoldFormat);
  finally
    LiteralList.Free;
  end;      
end;

type
  TFormatSection = (sectionPositive, sectionNegative, sectionZero);

function GetFormat(const Format: string; Section: TFormatSection): string;
const
  Separator: Char = ';';
  LiteralMarkers = [#39, '"'];
var 
  InLiteral: Boolean;
  P, PThisSection: PChar;
  SectionCount: Integer;
begin
  if Pos(Separator,Format) = 0 then
    Result := Format
  else
  begin
    PThisSection := PChar(Format);
    P := PThisSection;
    InLiteral := False;
    SectionCount := 0;
    while P^ <> #0 do
    begin 
      if P^ in LiteralMarkers then
        InLiteral := not InLiteral
      else
      begin
        if (P^ = Separator) and (not InLiteral) then
        begin
          if Integer(Section) = SectionCount then
            break
          else
          begin
            Inc(SectionCount);
          end;
        end;   
      end;
      Inc(P);
    end;
    SetString(Result, PThisSection, P-PThisSection);
  end;
end;

function FormatBcd(const Format: string; Bcd: TBcd): string;
begin
  if IsBcdNegative(Bcd) then
    Result := FormatOneBcd(GetFormat(Format, sectionNegative), Bcd)
  else if IsBcdZero(Bcd) then
    Result := FormatOneBcd(GetFormat(Format, sectionZero), Bcd)
  else
    Result := FormatOneBcd(GetFormat(Format, sectionPositive), Bcd);
end;

initialization
  FMTBcdVariantType := TFMTBcdVariantType.Create;
finalization
  FreeAndNil(FMTBcdVariantType);
end.
