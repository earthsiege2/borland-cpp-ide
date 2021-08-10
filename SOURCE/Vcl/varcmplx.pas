{ *********************************************************************** }
{                                                                         }
{ Delphi Runtime Library                                                  }
{                                                                         }
{ Copyright (c) 2001 Borland Software Corporation                         }
{                                                                         }
{ *********************************************************************** }

unit VarCmplx;

{ This unit contains complex number handling via a custom variant type.
  The native format for complex numbers in this is rectangular [x + yi] but
  limited conversion support for polar format [r*CIS(theta)] is provided.

  Some of the functions, concepts or constants in this unit were provided by
  Earl F. Glynn (www.efg2.com), who in turn, made the following acknowledgments..

    Some ideas in this UNIT were borrowed from "A Pascal Tool for Complex
    Numbers", Journal of Pascal, Ada, & Modula-2, May/June 1985, pp. 23-29.
    Many complex formulas were taken from Chapter 4, "Handbook of Mathematical
    Functions" (Ninth Printing), Abramowitz and Stegun (editors), Dover, 1972.
}

interface

uses
  Variants;

{ Complex variant creation utils }

function VarComplexCreate: Variant; overload;
function VarComplexCreate(const AReal: Double): Variant; overload;
function VarComplexCreate(const AReal, AImaginary: Double): Variant; overload;
function VarComplexCreate(const AText: string): Variant; overload;

function VarComplex: TVarType;
function VarIsComplex(const AValue: Variant): Boolean;
function VarAsComplex(const AValue: Variant): Variant;
function VarComplexSimplify(const AValue: Variant): Variant;

{ Complex variant support }

function VarComplexAbsSqr(const AValue: Variant): Double;
function VarComplexAbs(const AValue: Variant): Double;
function VarComplexAngle(const AValue: Variant): Double;
function VarComplexConjugate(const AValue: Variant): Variant;
function VarComplexInverse(const AValue: Variant): Variant;
function VarComplexExp(const AValue: Variant): Variant;
function VarComplexLn(const AValue: Variant): Variant;
function VarComplexSqr(const AValue: Variant): Variant;
function VarComplexSqrt(const AValue: Variant): Variant;
function VarComplexTimesPosI(const AValue: Variant): Variant;
function VarComplexTimesNegI(const AValue: Variant): Variant;
function VarComplexPower(const AValue, APower: Variant): Variant;

{ Complex variant trig support }

function VarComplexCos(const AValue: Variant): Variant;
function VarComplexSin(const AValue: Variant): Variant;
function VarComplexTan(const AValue: Variant): Variant;
function VarComplexCot(const AValue: Variant): Variant;
function VarComplexSec(const AValue: Variant): Variant;
function VarComplexCsc(const AValue: Variant): Variant;
function VarComplexArcCos(const AValue: Variant): Variant;
function VarComplexArcSin(const AValue: Variant): Variant;
function VarComplexArcTan(const AValue: Variant): Variant;
function VarComplexArcCot(const AValue: Variant): Variant;
function VarComplexArcSec(const AValue: Variant): Variant;
function VarComplexArcCsc(const AValue: Variant): Variant;
function VarComplexCosH(const AValue: Variant): Variant;
function VarComplexSinH(const AValue: Variant): Variant;
function VarComplexTanH(const AValue: Variant): Variant;
function VarComplexCotH(const AValue: Variant): Variant;
function VarComplexSecH(const AValue: Variant): Variant;
function VarComplexCscH(const AValue: Variant): Variant;
function VarComplexArcCosH(const AValue: Variant): Variant;
function VarComplexArcSinH(const AValue: Variant): Variant;
function VarComplexArcTanH(const AValue: Variant): Variant;
function VarComplexArcCotH(const AValue: Variant): Variant;
function VarComplexArcSecH(const AValue: Variant): Variant;
function VarComplexArcCscH(const AValue: Variant): Variant;

procedure VarComplexToPolar(const AValue: Variant; var ARadius, ATheta: Double;
  AFixTheta: Boolean = True);
function VarComplexFromPolar(const ARadius, ATheta: Double): Variant;

var
  ComplexNumberSymbol: string = 'i';
  ComplexNumberSymbolBeforeImaginary: Boolean = False;

implementation

uses
  VarUtils, SysUtils, Math, SysConst, TypInfo, Classes;

type
  { Complex variant type handler }
  TComplexVariantType = class(TPublishableVariantType, IVarStreamable)
  protected
    function LeftPromotion(const V: TVarData; const Operator: TVarOp;
      out RequiredVarType: TVarType): Boolean; override;
    function RightPromotion(const V: TVarData; const Operator: TVarOp;
      out RequiredVarType: TVarType): Boolean; override;
    function GetInstance(const V: TVarData): TObject; override;
  public
    procedure Clear(var V: TVarData); override;
    function IsClear(const V: TVarData): Boolean; override;
    procedure Copy(var Dest: TVarData; const Source: TVarData;
      const Indirect: Boolean); override;
    procedure Cast(var Dest: TVarData; const Source: TVarData); override;
    procedure CastTo(var Dest: TVarData; const Source: TVarData;
      const AVarType: TVarType); override;

    procedure BinaryOp(var Left: TVarData; const Right: TVarData;
      const Operator: TVarOp); override;
    procedure UnaryOp(var Right: TVarData; const Operator: TVarOp); override;
    function CompareOp(const Left: TVarData; const Right: TVarData;
      const Operator: Integer): Boolean; override;

    procedure StreamIn(var Dest: TVarData; const Stream: TStream);
    procedure StreamOut(const Source: TVarData; const Stream: TStream);
  end;

var
  { Complex variant type handler instance }
  ComplexVariantType: TComplexVariantType = nil;

type
  { Complex data that the complex variant points to }
  TComplexData = class(TPersistent)
  private
    FReal, FImaginary: Double;
    function GetAsString: String;
    procedure SetAsString(const Value: String);
    function GetRadius: Double;
    function GetTheta: Double;
    function GetFixedTheta: Double;
  protected
    procedure SetBoth(const AReal, AImaginary: Double);
  public

    // the many ways to create
    constructor Create(const AReal, AImaginary: Double); overload;
    constructor Create(const AText: string); overload;
    constructor Create(const AData: TComplexData); overload;

    // non-destructive operations
    function GetAbsSqr: Double;
    function GetAbs: Double;
    function GetAngle: Double;
    function Equal(const Right: TComplexData): Boolean; overload;
    function Equal(const AText: string): Boolean; overload;
    function IsZero: Boolean;

    // conversion operations
    procedure GetAsPolar(var ARadius, ATheta: Double; AFixTheta: Boolean = True);
    procedure SetAsPolar(const ARadius, ATheta: Double);

    // destructive operations
    procedure DoAdd(const Right: TComplexData);
    procedure DoSubtract(const Right: TComplexData);
    procedure DoMultiply(const Right: TComplexData);
    procedure DoDivide(const Right: TComplexData);
    procedure DoNegate;
    procedure DoConjugate;
    procedure DoInverse;
    procedure DoExp;
    procedure DoLn;
    procedure DoSqr;
    procedure DoSqrt;
    procedure DoTimesPosI;
    procedure DoTimesNegI;
    procedure DoCos;
    procedure DoSin;
    procedure DoTan;
    procedure DoPower(const APower: TComplexData);

    // conversion
    property AsString: String read GetAsString write SetAsString;
  published
    property Real: Double read FReal write FReal;
    property Imaginary: Double read FImaginary write FImaginary;
    property Radius: Double read GetRadius;
    property Theta: Double read GetTheta;
    property FixedTheta: Double read GetFixedTheta;
  end;

  { Helper record that helps crack open TVarData }
  TComplexVarData = packed record
    VType: TVarType;
    Reserved1, Reserved2, Reserved3: Word;
    VComplex: TComplexData;
    Reserved4: LongInt;
  end;

{ TComplexData }

procedure TComplexData.DoAdd(const Right: TComplexData);
begin
  SetBoth(Real + Right.Real,
          Imaginary + Right.Imaginary);
end;

constructor TComplexData.Create(const AReal, AImaginary: Double);
begin
  inherited Create;
  SetBoth(AReal, AImaginary);
end;

constructor TComplexData.Create(const AText: string);
begin
  inherited Create;
  AsString := AText;
end;

constructor TComplexData.Create(const AData: TComplexData);
begin
  inherited Create;
  SetBoth(AData.Real, AData.Imaginary);
end;

procedure TComplexData.DoDivide(const Right: TComplexData);
var
  LDenominator: Double;
begin
  LDenominator := Right.GetAbsSqr;
  if Math.IsZero(LDenominator) then
    raise EZeroDivide.Create(SDivByZero);
  SetBoth(((Real * Right.Real) + (Imaginary * Right.Imaginary)) / LDenominator,
          ((Imaginary * Right.Real) - (Real * Right.Imaginary)) / LDenominator);
end;

function TComplexData.GetAsString: String;
const
  cFormats: array [Boolean] of string = ('%2:g %1:s %3:g%0:s',
                                         '%2:g %1:s %0:s%3:g'); { do not localize }
  cSign: array [Boolean] of string = ('-', '+');
begin
  Result := Format(cFormats[ComplexNumberSymbolBeforeImaginary],
    [ComplexNumberSymbol, cSign[Imaginary >= 0], Real, Abs(Imaginary)]);
end;

procedure TComplexData.DoMultiply(const Right: TComplexData);
begin
  SetBoth((Real * Right.Real) - (Imaginary * Right.Imaginary),
          (Real * Right.Imaginary) + (Imaginary * Right.Real));
end;

procedure TComplexData.DoNegate;
begin
  SetBoth(-Real, -Imaginary);
end;

resourcestring
  SCouldNotParseImaginary = 'Could not parse imaginary portion';
  SCouldNotParseSymbol = 'Could not parse required ''%s'' symbol';
  SCouldNotParsePlus = 'Could not parse required ''+'' (or ''-'') symbol';
  SCouldNotParseReal = 'Could not parse real portion';
  SUnexpectedEOS = 'Unexpected end of string [%s]';
  SErrorSuffix = '%s [%s<?>%s]';

procedure TComplexData.SetAsString(const Value: String);
var
  LPart, LLeftover: string;
  LReal, LImaginary: Double;
  LSign: Integer;
  function ParseNumber(const AText: string; out ARest: string;
    out ANumber: Double): Boolean;
  var
    LAt: Integer;
    LFirstPart: string;
  begin
    Result := True;
    Val(AText, ANumber, LAt);
    if LAt <> 0 then
    begin
      ARest := Copy(AText, LAt, MaxInt);
      LFirstPart := Copy(AText, 1, LAt - 1);
      Val(LFirstPart, ANumber, LAt);
      if LAt <> 0 then
        Result := False;
    end;
  end;
  procedure ParseWhiteSpace(const AText: string; out ARest: string);
  var
    LAt: Integer;
  begin
    LAt := 1;
    if AText <> '' then
    begin
      while AText[LAt] = ' ' do
        Inc(LAt);
      ARest := Copy(AText, LAt, MaxInt);
    end;
    if ARest = '' then
      raise EConvertError.CreateFmt(SUnexpectedEOS, [Value]);
  end;
  procedure ParseError(const AMessage: string);
  begin
    raise EConvertError.CreateFmt(SErrorSuffix, [AMessage,
      Copy(Value, 1, Length(Value) - Length(LLeftOver)),
      Copy(Value, Length(Value) - Length(LLeftOver) + 1, MaxInt)]);
  end;
begin
  // where to start?
  LLeftover := Value;

  // first get the real portion
  if not ParseNumber(LLeftover, LPart, LReal) then
    ParseError(SCouldNotParseReal);

  // now make sure there is more
  ParseWhiteSpace(LPart, LLeftover);

  // look for the concat symbol
  LSign := 1;
  if LLeftover[1] = '-' then
    LSign := -1
  else if LLeftover[1] <> '+' then
    ParseError(SCouldNotParsePlus);
  LPart := Copy(LLeftover, 2, MaxInt);

  // make sure there is still more
  ParseWhiteSpace(LPart, LLeftover);

  // symbol before?
  if ComplexNumberSymbolBeforeImaginary then
  begin
    if not AnsiSameText(Copy(LLeftOver, 1, Length(ComplexNumberSymbol)),
                        ComplexNumberSymbol) then
      ParseError(Format(SCouldNotParseSymbol, [ComplexNumberSymbol]));
    LPart := Copy(LLeftover, Length(ComplexNumberSymbol) + 1, MaxInt);

    // make sure there is more
    ParseWhiteSpace(LPart, LLeftover);
  end;

  // imaginary part
  if not ParseNumber(LLeftover, LPart, LImaginary) then
    ParseError(SCouldNotParseImaginary);

  // correct for sign
  LImaginary := LImaginary * LSign;

  // symbol after?
  if not ComplexNumberSymbolBeforeImaginary then
  begin
    // skip possible whitespace
    ParseWhiteSpace(LPart, LLeftover);

    // make sure there is symbol!
    if not AnsiSameText(Copy(LLeftOver, 1, Length(ComplexNumberSymbol)),
                        ComplexNumberSymbol) then
      ParseError(Format(SCouldNotParseSymbol, [ComplexNumberSymbol]));
  end;

  // make it then
  SetBoth(LReal, LImaginary)
end;

procedure TComplexData.DoSubtract(const Right: TComplexData);
begin
  SetBoth(Real - Right.Real,
          Imaginary - Right.Imaginary);
end;

procedure TComplexData.SetBoth(const AReal, AImaginary: Double);
begin
  FReal := AReal;
  FImaginary := AImaginary;
end;

function TComplexData.GetAbs: Double;
begin
  Result := Sqrt(GetAbsSqr);
end;

function TComplexData.GetAbsSqr: Double;
begin
  Result := Sqr(Real) + Sqr(Imaginary);
end;

function TComplexData.GetAngle: Double;
begin
  Result := ArcTan2(Imaginary, Real);
end;

procedure TComplexData.DoCos;
begin
  if Math.IsZero(Imaginary) then
    Real := Cos(Real)
  else
    SetBoth(Cos(Real) * CosH(Imaginary), -Sin(Real) * SinH(Imaginary));
end;

procedure TComplexData.DoSin;
begin
  if Math.IsZero(Imaginary) then
    Real := Sin(Real)
  else
    SetBoth(Sin(Real) * CosH(Imaginary), Cos(Real) * SinH(Imaginary));
end;

procedure TComplexData.DoTan;
var
  LDenominator: Double;
begin
  if Math.IsZero(Imaginary) then
    Real := Tan(Real)
  else
  begin
    LDenominator := Cos(2.0 * Real) + CosH(2.0 * Imaginary);
    if Math.IsZero(LDenominator) then
      raise EZeroDivide.Create(SDivByZero);
    SetBoth(Sin(2.0 * Real) / LDenominator, SinH(2.0 * Imaginary) / LDenominator);
  end;
end;

procedure TComplexData.DoConjugate;
begin
  Imaginary := -Imaginary;
end;

procedure TComplexData.DoExp;
var
  LExp: Double;
begin
  if Math.IsZero(Imaginary) then
    Real := Exp(Real)
  else
  begin
    LExp := Exp(Real);
    SetBoth(LExp * Cos(Imaginary), LExp * Sin(Imaginary));
  end;
end;

procedure TComplexData.DoInverse;
var
  LDenominator: Double;
begin
  LDenominator := GetAbsSqr;
  if Math.IsZero(LDenominator) then
    raise EZeroDivide.Create(SDivByZero);
  SetBoth(Real / LDenominator, -(Imaginary / LDenominator));
end;

procedure TComplexData.DoLn;
var
  LRadius, LTheta: Double;
begin
  if Math.IsZero(Imaginary) then
    Real := Ln(Real)
  else
  begin
    GetAsPolar(LRadius, LTheta);
    SetBoth(Ln(LRadius), LTheta);
  end;
end;

procedure TComplexData.DoSqr;
begin
  if Math.IsZero(Imaginary) then
    Real := Sqr(Real)
  else
    SetBoth((Real * Real) - (Imaginary * Imaginary),
            (Real * Imaginary) + (Imaginary * Real));
end;

procedure TComplexData.DoSqrt;
var
  LValue1, LValue2: Double;
begin
  if Math.IsZero(Imaginary) and (Real >= 0.0) then
    Real := Sqrt(Real)
  else
  begin
    LValue1 := Sqrt(0.5 * (Abs(Real) + GetAbs));
    if Math.IsZero(LValue1) then
      raise EZeroDivide.Create(SDivByZero);
    LValue2 := Imaginary / (2.0 * LValue1);
    if Real >= 0.0 then
      SetBoth(LValue1, LValue2)
    else if Imaginary < 0.0 then
      SetBoth(LValue2, -LValue1)
    else
      SetBoth(LValue2, LValue1);
  end;
end;

procedure TComplexData.DoTimesNegI;
begin
  SetBoth(Imaginary, -Real);
end;

procedure TComplexData.DoTimesPosI;
begin
  SetBoth(-Imaginary, Real);
end;

function TComplexData.IsZero: Boolean;
begin
  Result := Math.IsZero(Real) and Math.IsZero(Imaginary);
end;

function TComplexData.Equal(const Right: TComplexData): Boolean;
begin
  Result := Math.SameValue(Real, Right.Real) and
            Math.SameValue(Imaginary, Right.Imaginary);
end;

function TComplexData.Equal(const AText: string): Boolean;
begin
  Result := AnsiSameText(AsString, AText);
end;

procedure TComplexData.DoPower(const APower: TComplexData);
begin
  if Math.IsZero(GetAbsSqr) then
    if Math.IsZero(APower.GetAbsSqr) then
      SetBoth(1, 0)
    else
      SetBoth(0, 0)
  else
  begin
    DoLn;
    DoMultiply(APower);
    DoExp;
  end;
end;

procedure TComplexData.GetAsPolar(var ARadius, ATheta: Double; AFixTheta: Boolean);
begin
  if Math.IsZero(Real) then
    if Math.IsZero(Imaginary) then
    begin
      ARadius := 0;
      ATheta := 0;
    end
    else
      if Imaginary > 0 then
      begin
        ARadius := Imaginary;
        ATheta := 0.5 * Pi;
      end
      else
      begin
        ARadius := -Imaginary;
        ATheta := -0.5 * Pi;
      end
  else
  begin
    ARadius := GetAbs;
    ATheta := ArcTan(Imaginary / Real);
    if Real < 0 then
      if Imaginary >= 0 then
        ATheta := Pi + ATheta
      else
        ATheta := -Pi + ATheta;
  end;
  if AFixTheta then
  begin
    while ATheta > Pi do
      ATheta := ATheta - 2.0 * Pi;
    while ATheta <= -Pi do
      ATheta := ATheta + 2.0 * Pi;
  end;
end;

procedure TComplexData.SetAsPolar(const ARadius, ATheta: Double);
begin
  SetBoth(ARadius * Cos(ATheta), ARadius * Sin(ATheta));
end;

function TComplexData.GetRadius: Double;
var
  Temp: Double;
begin
  GetAsPolar(Result, Temp);
end;

function TComplexData.GetTheta: Double;
var
  Temp: Double;
begin
  GetAsPolar(Temp, Result, False);
end;

function TComplexData.GetFixedTheta: Double;
var
  Temp: Double;
begin
  GetAsPolar(Temp, Result, True);
end;

{ TComplexVariantType }

procedure TComplexVariantType.BinaryOp(var Left: TVarData;
  const Right: TVarData; const Operator: TVarOp);
begin
  if Right.VType = VarType then
    case Left.VType of
      varString:
        case Operator of
          opAdd:
            Variant(Left) := Variant(Left) + TComplexVarData(Right).VComplex.AsString;
        else
          RaiseInvalidOp;
        end;
    else
      if Left.VType = VarType then
        case Operator of
          opAdd:
            TComplexVarData(Left).VComplex.DoAdd(TComplexVarData(Right).VComplex);
          opSubtract:
            TComplexVarData(Left).VComplex.DoSubtract(TComplexVarData(Right).VComplex);
          opMultiply:
            TComplexVarData(Left).VComplex.DoMultiply(TComplexVarData(Right).VComplex);
          opDivide:
            TComplexVarData(Left).VComplex.DoDivide(TComplexVarData(Right).VComplex);
        else
          RaiseInvalidOp;
        end
      else
        RaiseInvalidOp;
    end
  else
    RaiseInvalidOp;
end;

procedure TComplexVariantType.Cast(var Dest: TVarData; const Source: TVarData);
var
  LSource, LTemp: TVarData;
begin
  VarDataInit(LSource);
  try
    VarDataCopyNoInd(LSource, Source);
    if VarDataIsStr(LSource) then
      TComplexVarData(Dest).VComplex := TComplexData.Create(VarDataToStr(LSource))
    else
    begin
      VarDataInit(LTemp);
      try
        VarDataCastTo(LTemp, LSource, varDouble);
        TComplexVarData(Dest).VComplex := TComplexData.Create(LTemp.VDouble, 0);
      finally
        VarDataClear(LTemp);
      end;
    end;
    Dest.VType := VarType;
  finally
    VarDataClear(LSource);
  end;
end;

procedure TComplexVariantType.CastTo(var Dest: TVarData; const Source: TVarData;
  const AVarType: TVarType);
var
  LTemp: TVarData;
begin
  if Source.VType = VarType then
    case AVarType of
      varOleStr:
        VarDataFromOleStr(Dest, TComplexVarData(Source).VComplex.AsString);
      varString:
        VarDataFromStr(Dest, TComplexVarData(Source).VComplex.AsString);
    else
      VarDataInit(LTemp);
      try
        LTemp.VType := varDouble;
        LTemp.VDouble := TComplexVarData(LTemp).VComplex.Real;
        VarDataCastTo(Dest, LTemp, AVarType);
      finally
        VarDataClear(LTemp);
      end;
    end
  else
    inherited;
end;

procedure TComplexVariantType.Clear(var V: TVarData);
begin
  V.VType := varEmpty;
  FreeAndNil(TComplexVarData(V).VComplex);
end;

function TComplexVariantType.CompareOp(const Left, Right: TVarData;
  const Operator: Integer): Boolean;
begin
  Result := False;
  if (Left.VType = VarType) and (Right.VType = VarType) then
    case Operator of
      opCmpEQ:
        Result := TComplexVarData(Left).VComplex.Equal(TComplexVarData(Right).VComplex);
      opCmpNE:
        Result := not TComplexVarData(Left).VComplex.Equal(TComplexVarData(Right).VComplex);
    else
      RaiseInvalidOp;
    end
  else
    RaiseInvalidOp;
end;

procedure TComplexVariantType.Copy(var Dest: TVarData; const Source: TVarData;
  const Indirect: Boolean);
begin
  if Indirect and VarDataIsByRef(Source) then
    VarDataCopyNoInd(Dest, Source)
  else
    with TComplexVarData(Dest) do
    begin
      VType := VarType;
      VComplex := TComplexData.Create(TComplexVarData(Source).VComplex);
    end;
end;

function TComplexVariantType.GetInstance(const V: TVarData): TObject;
begin
  Result := TComplexVarData(V).VComplex;
end;

function TComplexVariantType.IsClear(const V: TVarData): Boolean;
begin
  Result := (TComplexVarData(V).VComplex = nil) or
            TComplexVarData(V).VComplex.IsZero;
end;

function TComplexVariantType.LeftPromotion(const V: TVarData;
  const Operator: TVarOp; out RequiredVarType: TVarType): Boolean;
begin
  { TypeX Op Complex }
  if (Operator = opAdd) and VarDataIsStr(V) then
    RequiredVarType := varString
  else
    RequiredVarType := VarType;

  Result := True;
end;

function TComplexVariantType.RightPromotion(const V: TVarData;
  const Operator: TVarOp; out RequiredVarType: TVarType): Boolean;
begin
  { Complex Op TypeX }
  RequiredVarType := VarType;
  Result := True;
end;

procedure TComplexVariantType.StreamIn(var Dest: TVarData;
  const Stream: TStream);
begin
  with TReader.Create(Stream, 1024) do
  try
    with TComplexVarData(Dest) do
    begin
      VComplex := TComplexData.Create;
      VComplex.Real := ReadFloat;
      VComplex.Imaginary := ReadFloat;
    end;
  finally
    Free;
  end;
end;

procedure TComplexVariantType.StreamOut(const Source: TVarData;
  const Stream: TStream);
begin
  with TWriter.Create(Stream, 1024) do
  try
    with TComplexVarData(Source).VComplex do
    begin
      WriteFloat(Real);
      WriteFloat(Imaginary);
    end;
  finally
    Free;
  end;
end;

procedure TComplexVariantType.UnaryOp(var Right: TVarData;
  const Operator: TVarOp);
begin
  if Right.VType = VarType then
    case Operator of
      opNegate:
        TComplexVarData(Right).VComplex.DoNegate;
    else
      RaiseInvalidOp;
    end
  else
    RaiseInvalidOp;
end;

{ Complex variant creation utils }

procedure VarComplexCreateInto(var ADest: Variant; const AComplex: TComplexData);
begin
  VarClear(ADest);
  TComplexVarData(ADest).VType := VarComplex;
  TComplexVarData(ADest).VComplex := AComplex;
end;

function VarComplexCreate: Variant;
begin
  VarComplexCreateInto(Result, TComplexData.Create(0, 0));
end;

function VarComplexCreate(const AReal: Double): Variant;
begin
  VarComplexCreateInto(Result, TComplexData.Create(AReal, 0));
end;

function VarComplexCreate(const AReal, AImaginary: Double): Variant;
begin
  VarComplexCreateInto(Result, TComplexData.Create(AReal, AImaginary));
end;

function VarComplexCreate(const AText: string): Variant;
begin
  VarComplexCreateInto(Result, TComplexData.Create(AText));
end;

function VarComplex: TVarType;
begin
  Result := ComplexVariantType.VarType;
end;

function VarIsComplex(const AValue: Variant): Boolean;
begin
  Result := (TVarData(AValue).VType and varTypeMask) = VarComplex;
end;

function VarAsComplex(const AValue: Variant): Variant;
begin
  if not VarIsComplex(AValue) then
    VarCast(Result, AValue, VarComplex)
  else
    Result := AValue;
end;

function VarComplexSimplify(const AValue: Variant): Variant;
begin
  if VarIsComplex(AValue) and
     Math.IsZero(TComplexVarData(AValue).VComplex.Imaginary) then
    Result := TComplexVarData(AValue).VComplex.Real
  else
    Result := AValue;
end;

{ Complex variant support }

function VarComplexAbsSqr(const AValue: Variant): Double;
var
  LTemp: Variant;
begin
  VarCast(LTemp, AValue, VarComplex);
  Result := TComplexVarData(LTemp).VComplex.GetAbsSqr;
end;

function VarComplexAbs(const AValue: Variant): Double;
var
  LTemp: Variant;
begin
  VarCast(LTemp, AValue, VarComplex);
  Result := TComplexVarData(LTemp).VComplex.GetAbs;
end;

function VarComplexAngle(const AValue: Variant): Double;
var
  LTemp: Variant;
begin
  VarCast(LTemp, AValue, VarComplex);
  Result := TComplexVarData(LTemp).VComplex.GetAngle;
end;

function VarComplexConjugate(const AValue: Variant): Variant;
begin
  VarCast(Result, AValue, VarComplex);
  TComplexVarData(Result).VComplex.DoConjugate;
end;

function VarComplexInverse(const AValue: Variant): Variant;
begin
  VarCast(Result, AValue, VarComplex);
  TComplexVarData(Result).VComplex.DoInverse;
end;

function VarComplexExp(const AValue: Variant): Variant;
begin
  VarCast(Result, AValue, VarComplex);
  TComplexVarData(Result).VComplex.DoExp;
end;

function VarComplexLn(const AValue: Variant): Variant;
begin
  VarCast(Result, AValue, VarComplex);
  TComplexVarData(Result).VComplex.DoLn;
end;

function VarComplexSqr(const AValue: Variant): Variant;
begin
  VarCast(Result, AValue, VarComplex);
  TComplexVarData(Result).VComplex.DoSqr;
end;

function VarComplexSqrt(const AValue: Variant): Variant;
begin
  VarCast(Result, AValue, VarComplex);
  TComplexVarData(Result).VComplex.DoSqrt;
end;

function VarComplexTimesPosI(const AValue: Variant): Variant;
begin
  VarCast(Result, AValue, VarComplex);
  TComplexVarData(Result).VComplex.DoTimesPosI;
end;

function VarComplexTimesNegI(const AValue: Variant): Variant;
begin
  VarCast(Result, AValue, VarComplex);
  TComplexVarData(Result).VComplex.DoTimesNegI;
end;

function VarComplexPower(const AValue, APower: Variant): Variant;
var
  LTemp: Variant;
begin
  VarCast(Result, AValue, VarComplex);
  VarCast(LTemp, APower, VarComplex);
  TComplexVarData(Result).VComplex.DoPower(TComplexVarData(LTemp).VComplex);
end;

{ Complex variant trig support }

function VarComplexCos(const AValue: Variant): Variant;
begin
  VarCast(Result, AValue, VarComplex);
  TComplexVarData(Result).VComplex.DoCos;
end;

function VarComplexSin(const AValue: Variant): Variant;
begin
  VarCast(Result, AValue, VarComplex);
  TComplexVarData(Result).VComplex.DoSin;
end;

function VarComplexTan(const AValue: Variant): Variant;
begin
  VarCast(Result, AValue, VarComplex);
  TComplexVarData(Result).VComplex.DoTan;
end;

function VarComplexCot(const AValue: Variant): Variant;
begin
  Result := 1 / VarComplexTan(AValue);
end;

function VarComplexSec(const AValue: Variant): Variant;
begin
  Result := 1 / VarComplexCos(AValue);
end;

function VarComplexCsc(const AValue: Variant): Variant;
begin
  Result := 1 / VarComplexSin(AValue);
end;

function VarComplexArcCos(const AValue: Variant): Variant;
begin
  Result := VarComplexTimesNegI(VarComplexArcCosH(AValue));
end;

function VarComplexArcSin(const AValue: Variant): Variant;
begin
  Result := VarComplexTimesNegI(VarComplexArcCosH(VarComplexTimesPosI(AValue)));
end;

function VarComplexArcTan(const AValue: Variant): Variant;
begin
  Result := VarComplexTimesNegI(VarComplexArcTanH(VarComplexTimesPosI(AValue)));
end;

function VarComplexArcCot(const AValue: Variant): Variant;
begin
  Result := VarComplexArcTan(1 / AValue);
end;

function VarComplexArcSec(const AValue: Variant): Variant;
begin
  Result := VarComplexArcCos(1 / AValue);
end;

function VarComplexArcCsc(const AValue: Variant): Variant;
begin
  Result := VarComplexArcSin(1 / AValue);
end;

function VarComplexCosH(const AValue: Variant): Variant;
begin
  Result := (VarComplexExp(AValue) + VarComplexExp(-AValue)) * 0.5;
end;

function VarComplexSinH(const AValue: Variant): Variant;
begin
  Result := (VarComplexExp(AValue) - VarComplexExp(-AValue)) * 0.5;
end;

function VarComplexTanH(const AValue: Variant): Variant;
begin
  Result := VarComplexSinH(AValue) / VarComplexCosH(AValue);
end;

function VarComplexCotH(const AValue: Variant): Variant;
begin
  Result := 1 / VarComplexTanH(AValue);
end;

function VarComplexSecH(const AValue: Variant): Variant;
begin
  Result := 1 / VarComplexCosH(AValue);
end;

function VarComplexCscH(const AValue: Variant): Variant;
begin
  Result := 1 / VarComplexSinH(AValue);
end;

function VarComplexArcCosH(const AValue: Variant): Variant;
begin
  Result := VarComplexLn(AValue + VarComplexSqrt(VarComplexSqr(AValue) - 1));
end;

function VarComplexArcSinH(const AValue: Variant): Variant;
begin
  Result := VarComplexLn(AValue + VarComplexSqrt(VarComplexSqr(AValue) + 1));
end;

function VarComplexArcTanH(const AValue: Variant): Variant;
begin
  Result := VarComplexLn((-AValue - 1) / (AValue - 1)) * 0.5;
end;

function VarComplexArcCotH(const AValue: Variant): Variant;
begin
  Result := VarComplexArcTanH(1 / AValue);
end;

function VarComplexArcSecH(const AValue: Variant): Variant;
begin
  Result := VarComplexArcCosH(1 / AValue);
end;

function VarComplexArcCscH(const AValue: Variant): Variant;
begin
  Result := VarComplexArcSinH(1 / AValue);
end;

procedure VarComplexToPolar(const AValue: Variant; var ARadius, ATheta: Double;
  AFixTheta: Boolean);
var
  Temp: Variant;
begin
  VarCast(Temp, AValue, VarComplex);
  TComplexVarData(Temp).VComplex.GetAsPolar(ARadius, ATheta, AFixTheta);
end;

function VarComplexFromPolar(const ARadius, ATheta: Double): Variant;
begin
  Result := VarComplexCreate;
  TComplexVarData(Result).VComplex.SetAsPolar(ARadius, ATheta);
end;

initialization
  ComplexVariantType := TComplexVariantType.Create;
finalization
  FreeAndNil(ComplexVariantType);
end.
