{ *************************************************************************** }
{                                                                             }
{ Kylix and Delphi Cross-Platform Visual Component Library                    }
{                                                                             }
{ Copyright (c) 1995, 2001 Borland Software Corporation                       }
{                                                                             }
{ *************************************************************************** }


unit SqlTimSt;

// need to implement CastOLE, dispatch and stream (from Eddie?)

interface

uses  Variants;

type

{ TSQLTimeStamp }
  PSQLTimeStamp = ^TSQLTimeStamp;
  TSQLTimeStamp = packed record
    Year: SmallInt;
    Month: Word;
    Day: Word;
    Hour: Word;
    Minute: Word;
    Second: Word;
    Fractions: LongWord;
  end;


{ TSQLTimeStamp variant creation utils }

procedure VarSQLTimeStampCreate(var aDest: Variant; const ASQLTimeStamp: TSQLTimeStamp); overload;
function VarSQLTimeStampCreate: Variant; overload;
function VarSQLTimeStampCreate(const AValue: string): Variant; overload;
function VarSQLTimeStampCreate(const AValue: TDateTime): Variant; overload;
function VarSQLTimeStampCreate(const ASQLTimeStamp: TSQLTimeStamp): Variant; overload;
function VarSQLTimeStamp: TVarType;
function VarIsSQLTimeStamp(const aValue: Variant): Boolean; overload;
//function VarAsSQLTimeStamp(const aValue: Variant): Variant;

{ TSQLTimeStamp conversion support }

// converts Variant SQLTimeStamp to record TSQLTimeStamp
function VarToSQLTimeStamp(const aValue: Variant): TSQLTimeStamp;
function SQLTimeStampToStr(const Format: string;
      DateTime: TSQLTimeStamp): string;
function SQLDayOfWeek(const DateTime: TSQLTimeStamp): integer;
function DateTimeToSQLTimeStamp(const DateTime: TDateTime): TSQLTimeStamp;
function SQLTimeStampToDateTime(const DateTime: TSQLTimeStamp): TDateTime;
function TryStrToSQLTimeStamp(const S: string; var TimeStamp: TSQLTimeStamp) : Boolean;
function StrToSQLTimeStamp(const S: string): TSQLTimeStamp; 

{ utility }

procedure CheckSqlTimeStamp(const ASQLTimeStamp: TSQLTimeStamp);

const

  NullSQLTimeStamp: TSQLTimeStamp = (Year: 0; Month: 0; Day: 0; Hour: 0; Minute: 0; Second: 0; Fractions: 0);

implementation

uses
  VarUtils, SysUtils, DateUtils, SysConst, DBConsts, TypInfo, Classes, {$IFDEF MSWINDOWS}Windows{$ENDIF}{$IFDEF LINUX}Types, Libc{$ENDIF};

const

  IncrementAmount: array[Boolean] of Integer = (1, -1);

type


{ TSQLTimeStampVariantType }
  TSQLTimeStampVariantType = class(TPublishableVariantType)
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

{ SQLTimeStamp that the complex variant points to }

  SQLTimeStampVariantType: TSQLTimeStampVariantType = nil;

type

{ TSQLTimeStampData }

  TSQLTimeStampData = class(TPersistent)
  private
    FDateTime: TSQLTimeStamp;
    function GetAsDateTime: TDateTime;
    function GetAsString: string;
    procedure SetAsString(const Value: string);
    procedure SetAsDateTime(const Value: TDateTime);
    procedure AdjustMonths(Reverse: Boolean);
    procedure AdjustDays(Reverse: Boolean);
    procedure AdjustHours(Reverse: Boolean);
    procedure AdjustMinutes(Reverse: Boolean);
    procedure AdjustSeconds(Reverse: Boolean);
    function DaysInMonth: Integer;
    function GetIsBlank: Boolean;
    procedure SetDay(const Value: Word);
    procedure SetFractions(const Value: LongWord);
    procedure SetHour(const Value: Word);
    procedure SetMinute(const Value: Word);
    procedure SetMonth(const Value: Word);
    procedure SetSecond(const Value: Word);
    procedure SetYear(const Value: SmallInt);
  protected
    procedure AdjustDate(Reverse: Boolean);
    property IsBlank: Boolean read GetIsBlank;
  public
    // the many ways to create
    constructor Create(const AValue: SmallInt); overload;
    constructor Create(const AValue: Integer); overload;
    constructor Create(const AValue: TDateTime); overload;
    constructor Create(const AText: string); overload;
    constructor Create(const ASQLTimeStamp: TSQLTimeStamp); overload;
    constructor Create(const ASource: TSQLTimeStampData); overload;

    // access to the private bits
    property DateTime: TSQLTimeStamp read FDateTime write FDateTime;

    // non-destructive operations
    // check this one!
    function Compare(const Value: TSQLTimeStampData): TVarCompareResult;

    // destructive operations
    procedure DoAdd(const ADateTime: TSQLTimeStampData); overload;
    procedure DoSubtract(const ADateTime: TSQLTimeStampData); overload;
    // property access
  published
    // conversion
    property AsDateTime: TDateTime read GetAsDateTime write SetAsDateTime;
    property AsString: string read GetAsString write SetAsString;
    property Day: Word read FDateTime.Day write SetDay;
    property Fractions: LongWord read FDateTime.Fractions write SetFractions;
    property Hour: Word read FDateTime.Hour write SetHour;
    property Minute: Word read FDateTime.Minute write SetMinute;
    property Month: Word read FDateTime.Month write SetMonth;
    property Second: Word read FDateTime.Second write SetSecond;
    property Year: SmallInt read FDateTime.Year write SetYear;
  end;

{ Helper record that helps crack open TSQLTimeStampObject }

  TSQLTimeStampVarData = packed record
    VType: TVarType;
    Reserved1, Reserved2, Reserved3: Word;
    VDateTime: TSQLTimeStampData;
    Reserved4: DWord;
  end;


function IsSQLTimeStampBlank(const TimeStamp: TSQLTimeStamp): Boolean;
begin
  Result := (TimeStamp.Year = 0) and
            (TimeStamp.Month = 0) and
            (TimeStamp.Day = 0) and
            (TimeStamp.Hour = 0) and
            (TimeStamp.Minute = 0) and
            (TimeStamp.Second = 0) and
            (TimeStamp.Fractions = 0);
end;

{ TSQLTimeStampData }

function TSQLTimeStampData.GetIsBlank: Boolean;
begin
  Result := IsSQLTimeStampBlank(FDateTime);
end;

// Adjust for Month > 12 or < 1
procedure TSQLTimeStampData.AdjustMonths(Reverse: Boolean);
const
  AdjustAmt: array[Boolean] of Integer = (-12, 12);
begin
  while (FDateTime.Month < 1) or(FDateTime.Month > 12) do
  begin
    Inc(FDateTime.Year, IncrementAmount[Reverse]);
    Inc(FDateTime.Month, AdjustAmt[Reverse]);
  end;
end;

// Adjust for Days > 28/30/31 or < 1
procedure TSQLTimeStampData.AdjustDays(Reverse: Boolean);
var
  Days: Integer;
begin
  Days := DaysInMonth;
  while (FDateTime.Day < 1) or (FDateTime.Day > Days) do
  begin
    Inc(FDateTime.Month, IncrementAmount[Reverse]);
    if Reverse then
      Dec(FDateTime.Day, Days)
    else
      Inc(FDateTime.Day, Days);
    AdjustMonths(Reverse);
    Days := DaysInMonth;
  end;
end;

// Adjust for Hours over 23 or less than 0
procedure TSQLTimeStampData.AdjustHours(Reverse: Boolean);
const
  AdjustAmt: array[Boolean] of Integer = (-24, 24);
begin
  while (FDateTime.Hour > 23) or (Integer(FDateTime.Hour) < 0) do
  begin
    Inc(FDateTime.Day, IncrementAmount[Reverse]);
    Inc(FDateTime.Hour, AdjustAmt[Reverse]);
    AdjustDays(Reverse);
  end;
end;

// Adjust Minutes for Hours over 59 or less than 0
procedure TSQLTimeStampData.AdjustMinutes(Reverse: Boolean);
const
  AdjustAmt: array[Boolean] of Integer = (-60, 60);
begin
  while (FDateTime.Minute > 59) or (Integer(FDateTime.Minute) < 0) do
  begin
    Inc(FDateTime.Hour, IncrementAmount[Reverse]);
    Inc(FDateTime.Minute, AdjustAmt[Reverse]);
    AdjustHours(Reverse);
  end;
end;

// Adjust Seconds for Hours over 59 or less than 0
procedure TSQLTimeStampData.AdjustSeconds(Reverse: Boolean);
const
  AdjustAmt: array[Boolean] of Integer = (-60, 60);
begin
  while (FDateTime.Second > 59) or (Integer(FDateTime.Second) < 0) do
  begin
    Inc(FDateTime.Minute, IncrementAmount[Reverse]);
    Inc(FDateTime.Second, AdjustAmt[Reverse]);
    AdjustMinutes(Reverse);
  end;
end;

procedure TSQLTimeStampData.AdjustDate(Reverse: Boolean);
begin
  if Reverse then
  begin
    AdjustSeconds(Reverse);
    AdjustMinutes(Reverse);
    AdjustHours(Reverse);
    AdjustDays(Reverse);
    AdjustMonths(Reverse);
  end else
  begin
    AdjustMonths(Reverse);
    AdjustDays(Reverse);
    AdjustHours(Reverse);
    AdjustMinutes(Reverse);
    AdjustSeconds(Reverse);
  end;
end;

function TSQLTimeStampData.DaysInMonth: Integer;
begin
  Result := DaysInAMonth(DateTime.Year, DateTime.Month);
end;

procedure TSQLTimeStampData.DoSubtract(const ADateTime: TSQLTimeStampData);
begin
  Dec(FDateTime.Year, ADateTime.Year);
  Dec(FDateTime.Hour, ADateTime.Month);
  Dec(FDateTime.Day, ADateTime.Day);
  Dec(FDateTime.Hour, ADateTime.Hour);
  Dec(FDateTime.Minute, ADateTime.Minute);
  Dec(FDateTime.Second, ADateTime.Second);
  Dec(FDateTime.Fractions, ADateTime.Fractions);
  AdjustDate(True);
end;

procedure TSQLTimeStampData.DoAdd(const ADateTime: TSQLTimeStampData);
begin
  if not IsBlank then
  begin
    Inc(FDateTime.Year, ADateTime.Year);
    Inc(FDateTime.Hour, ADateTime.Month);
    Inc(FDateTime.Day, ADateTime.Day);
    Inc(FDateTime.Hour, ADateTime.Hour);
    Inc(FDateTime.Minute, ADateTime.Minute);
    Inc(FDateTime.Second, ADateTime.Second);
    Inc(FDateTime.Fractions, ADateTime.Fractions);
    AdjustDate(False);;
  end;
end;

function TSQLTimeStampData.Compare(const Value: TSQLTimeStampData): TVarCompareResult;
var
  Status: Integer;
begin
  Status := FDateTime.Year - Value.Year;
  if Status = 0 then
    Status := FDateTime.Month - Value.Month;
  if Status = 0 then
    Status := FDateTime.Day - Value.Day;
  if Status = 0 then
    Status := FDateTime.Hour - Value.Hour;
  if Status = 0 then
    Status := FDateTime.Hour - Value.Hour;
  if Status = 0 then
    Status := FDateTime.Minute - Value.Minute;
  if Status = 0 then
    Status := FDateTime.Second - Value.Second;
  if Status = 0 then
    Status := FDateTime.Fractions - Value.Fractions;
  if Status = 0 then
    Result := crEqual
  else
  if Status > 0 then
    Result := crGreaterThan
  else
    Result := crLessThan;
end;

function TSQLTimeStampData.GetAsString: string;
begin
  Result := SQLTimeStampToStr('', FDateTime);
end;

function TSQLTimeStampData.GetAsDateTime: TDateTime;
begin
  Result := SQLTimeStampToDateTime(FDateTime);
end;

procedure TSQLTimeStampData.SetAsString(const Value: string);
begin
  FDateTime := StrToSQLTimeStamp(Value); 
end;

procedure TSQLTimeStampData.SetAsDateTime(const Value: TDateTime);
begin
  FDateTime := DateTimeToSQLTimeStamp(Value);
end;

constructor TSQLTimeStampData.Create(const AValue: Integer);
begin
  inherited Create;
  FDateTime := NullSQLTimeStamp;
  FDateTime.Day := AValue;
end;

constructor TSQLTimeStampData.Create(const AValue: SmallInt);
begin
  inherited Create;
  FDateTime := NullSQLTimeStamp;
  FDateTime.Day := AValue;
end;

constructor TSQLTimeStampData.Create(const AValue: TDateTime);
begin
  inherited Create;
  FDateTime := DateTimeToSqlTimeStamp(AValue);
end;

constructor TSQLTimeStampData.Create(const AText: string);
var
  ts: TSQLTimeStamp;
begin
  ts := StrToSQLTimeStamp(AText);
  inherited Create;
  FDateTime := ts;
end;

constructor TSQLTimeStampData.Create(const ASQLTimeStamp: TSQLTimeStamp);
begin
  CheckSqlTimeStamp( ASQLTimeStamp );
  inherited Create;
  move(ASQLTimeStamp, FDateTime, sizeof(TSQLTimeStamp));
end;

constructor TSQLTimeStampData.Create(const ASource: TSQLTimeStampData);
begin
  Create(aSource.DateTime);
end;

procedure TSQLTimeStampData.SetDay(const Value: Word);
begin
  Assert((Value >= 1) and (Value <= DaysInAMonth(Year, Month)));
  FDateTime.Day := Value;
end;

procedure TSQLTimeStampData.SetFractions(const Value: LongWord);
begin
  FDateTime.Fractions := Value;
end;

procedure TSQLTimeStampData.SetHour(const Value: Word);
begin
  Assert(Value <= 23);   // no need to check for > 0 on Word
  FDateTime.Hour := Value;
end;

procedure TSQLTimeStampData.SetMinute(const Value: Word);
begin
  Assert(Value <= 59);   // no need to check for > 0 on Word
  FDateTime.Minute := Value;
end;

procedure TSQLTimeStampData.SetMonth(const Value: Word);
begin
  Assert((Value >= 1) and (Value <= 12));
  FDateTime.Month := Value;
end;

procedure TSQLTimeStampData.SetSecond(const Value: Word);
begin
  Assert(Value <= 59);  // no need to check for > 0 on Word
  FDateTime.Second := Value;
end;

procedure TSQLTimeStampData.SetYear(const Value: SmallInt);
begin
  FDateTime.Year := Value;
end;

{ TSQLTimeStampVariantType }

procedure TSQLTimeStampVariantType.Clear(var V: TVarData);
begin
  V.VType := varEmpty;
  FreeAndNil(TSQLTimeStampVarData(V).VDateTime);
end;

procedure TSQLTimeStampVariantType.Cast(var Dest: TVarData;
  const Source: TVarData);
var
  LSource, LTemp: TVarData;
begin
  VarDataInit(LSource);
  try
    VarDataCopyNoInd(LSource, Source);
    if VarDataIsStr(LSource) then
      TSQLTimeStampVarData(Dest).VDateTime := TSQLTimeStampData.Create(VarDataToStr(LSource))
    else
    begin
      VarDataInit(LTemp);
      try
        VarDataCastTo(LTemp, LSource, varDate);
        TSQLTimeStampVarData(Dest).VDateTime := TSQLTimeStampData.Create(LTemp.VDate);
      finally
        VarDataClear(LTemp);
      end;
    end;
    Dest.VType := VarType;
  finally
    VarDataClear(LSource);
  end;
end;

procedure TSQLTimeStampVariantType.CastTo(var Dest: TVarData;
  const Source: TVarData; const AVarType: TVarType);
var
  LTemp: TVarData;
begin
  if Source.VType = VarType then
    case AVarType of
      varOleStr:
        VarDataFromOleStr(Dest, TSQLTimeStampVarData(Source).VDateTime.AsString);
      varString:
        VarDataFromStr(Dest, TSQLTimeStampVarData(Source).VDateTime.AsString);
    else
      VarDataInit(LTemp);
      try
        LTemp.VType := varDate;
        LTemp.VDate := TSQLTimeStampVarData(Source).VDateTime.AsDateTime;
        VarDataCastTo(Dest, LTemp, AVarType);
      finally
        VarDataClear(LTemp);
      end;
    end
  else
    inherited;
end;

procedure TSQLTimeStampVariantType.Copy(var Dest: TVarData; const Source: TVarData; const Indirect: Boolean);
begin
  if Indirect and VarDataIsByRef(Source) then
    VarDataCopyNoInd(Dest, Source)
  else
    with TSQLTimeStampVarData(Dest) do
    begin
      VType := VarType;
      VDateTime := TSQLTimeStampData.Create(TSQLTimeStampVarData(Source).VDateTime);
    end;
end;

function TSQLTimeStampVariantType.GetInstance(const V: TVarData): TObject;
begin
  Result := TSQLTimeStampVarData(V).VDateTime;
end;

procedure TSQLTimeStampVariantType.BinaryOp(var Left: TVarData; const Right: TVarData; const Operator: TVarOp);
begin
  case Operator of
    opAdd:
      TSQLTimeStampVarData(Left).VDateTime.DoAdd(TSQLTimeStampVarData(Right).VDateTime);
    opSubtract:
      TSQLTimeStampVarData(Left).VDateTime.DoSubtract(TSQLTimeStampVarData(Right).VDateTime);
  else
    RaiseInvalidOp;
  end;
end;

procedure TSQLTimeStampVariantType.Compare(const Left, Right: TVarData; var Relationship: TVarCompareResult);
begin
  Relationship := TSQLTimeStampVarData(Left).VDateTime.Compare(TSQLTimeStampVarData(Right).VDateTime);
end;

{ SQLTimeStamp variant create utils }

function VarSQLTimeStampCreate(const AValue: string): Variant; overload;
begin
  VarClear(Result);
  TSQLTimeStampVarData(Result).VType := SQLTimeStampVariantType.VarType;
  TSQLTimeStampVarData(Result).VDateTime := TSQLTimeStampData.Create(AValue);
end;

function VarSQLTimeStampCreate(const AValue: TDateTime): Variant; overload;
begin
  VarClear(Result);
  TSQLTimeStampVarData(Result).VType := SQLTimeStampVariantType.VarType;
  TSQLTimeStampVarData(Result).VDateTime := TSQLTimeStampData.Create(AValue);
end;

procedure VarSQLTimeStampCreate(var aDest: Variant; const ASQLTimeStamp: TSQLTimeStamp);
begin
  VarClear(aDest);
  TSQLTimeStampVarData(aDest).VType := SQLTimeStampVariantType.VarType;
  TSQLTimeStampVarData(aDest).VDateTime := TSQLTimeStampData.Create(ASQLTimeStamp);
end;

function VarSQLTimeStampCreate: Variant;
begin
  VarSQLTimeStampCreate(Result, NullSQLTimeStamp);
end;

function VarSQLTimeStampCreate(const ASQLTimeStamp: TSQLTimeStamp): Variant;
begin
  VarSQLTimeStampCreate(Result, ASQLTimeStamp);
end;

function VarSQLTimeStamp: TVarType;
begin
  Result := SQLTimeStampVariantType.VarType;
end;

function VarIsSQLTimeStamp(const aValue: Variant): Boolean;
begin
  Result := TVarData(aValue).VType = SQLTimeStampVariantType.VarType;
end;

function VarToSQLTimeStamp(const aValue: Variant): TSQLTimeStamp;
begin
  if TVarData(aValue).VType in [varNULL, varEMPTY] then
    Result := NullSqlTimeStamp
  else if (TVarData(aValue).VType = varString) then
    Result := TSQLTimeStampData.Create(String(aValue)).FDateTime
  else if (TVarData(aValue).VType = varDouble) or (TVarData(aValue).VType = varDate) then
    Result := DateTimeToSqlTimeStamp(TDateTime(aValue))
  else if (TVarData(aValue).VType = SQLTimeStampVariantType.VarType) then
    Result := TSQLTimeStampVarData(aValue).VDateTime.DateTime
  else
    Raise EVariantError.Create(SInvalidVarCast)
end;

{ SQLTimeStamp to string conversion }

function SQLTimeStampToStr(const Format: string;
  DateTime: TSQLTimeStamp): string;
var
  FTimeStamp: TDateTime;
begin
  FTimeStamp := SqlTimeStampToDateTime(DateTime);
  DateTimeToString(Result, Format, FTimeStamp);
end;

function IsSqlTimeStampValid(const ts: TSQLTimeStamp): Boolean;
begin
  if (ts.Month > 12) or (ts.Day > DaysInAMonth(ts.Year, ts.Month)) or
       (ts.Hour > 23) or (ts.Minute > 59) or (ts.Second > 59) then
    Result := False
  else
    Result := True;
end;

function TryStrToSQLTimeStamp(const S: string; var TimeStamp: TSQLTimeStamp): Boolean;
var
  DT: TDateTime;
begin
  Result := TryStrToDateTime(S, DT);
  if Result then
  begin
    TimeStamp := DateTimeToSQLTimeStamp(DT);
    Result := IsSqlTimeStampValid(TimeStamp);
  end;
  if not Result then
    TimeStamp := NullSQLTimeStamp;
end;

function StrToSQLTimeStamp(const S: string): TSQLTimeStamp;
begin
  if not TryStrToSqlTimeStamp(S, Result) then
    raise EConvertError.Create(SCouldNotParseTimeStamp);
end;

function DateTimeToSQLTimeStamp(const DateTime: TDateTime): TSQLTimeStamp;
var
  FFractions, FYear: Word;
begin
  with Result do
  begin
    DecodeDate(DateTime, FYear, Month, Day);
    Year := FYear;
    DecodeTime(DateTime, Hour, Minute, Second, FFractions);
    Fractions := FFractions;
  end;
end;

function SQLTimeStampToDateTime(const DateTime: TSQLTimeStamp): TDateTime;
begin
  if IsSQLTimeStampBlank(DateTime) then
    Result := 0
  else with DateTime do
  begin
    Result := EncodeDate(Year, Month, Day);
    if Result >= 0 then
      Result := Result + EncodeTime(Hour, Minute, Second, Fractions)
    else
      Result := Result - EncodeTime(Hour, Minute, Second, Fractions);
  end;
end;

function SQLDayOfWeek(const DateTime: TSQLTimeStamp): integer;
var
  dt: TDateTime;
begin
  dt := SQLTimeStampToDateTime(DateTime);
  Result := DayOfWeek(dt);
end;

procedure CheckSqlTimeStamp(const ASQLTimeStamp: TSQLTimeStamp);
begin  // only check if not an empty timestamp
  if ASQLTimeStamp.Year + ASQLTimeStamp.Month + ASQLTimeStamp.day +
     ASQLTimeStamp.Hour + ASQLTimeStamp.Minute + ASQLTimeStamp.Second > 0 then
  begin
    if ASQLTimeStamp.Year + ASQLTimeStamp.Month + ASQLTimeStamp.Day > 0 then
      if (ASQLTimeStamp.Year = 0) or (ASQLTimeStamp.Month = 0) or
       (ASQLTimeStamp.Day =0) or (ASQLTimeStamp.Month > 31) or (ASQLTimeStamp.Day >
       DaysInAMonth(ASQLTimeStamp.Year,ASQLTimeStamp.Month)) then
         raise EConvertError.Create(SInvalidSQLTimeStamp);
    if ASQLTimeStamp.Hour + ASQLTimeStamp.Minute + ASQLTimeStamp.Second > 0 then
       if (ASQLTimeStamp.Hour > 23) or (ASQLTimeStamp.Second > 59) or
       (ASQLTimeStamp.Minute > 59) then
         raise EConvertError.Create(SInvalidSQLTimeStamp);
  end;
end;

initialization
  SQLTimeStampVariantType := TSQLTimeStampVariantType.Create;
finalization
  FreeAndNil(SQLTimeStampVariantType);
end.