{*******************************************************}
{                                                       }
{ Borland Delphi Visual Component Library               }
{                SOAP Support                           }
{                                                       }
{ Copyright (c) 2001 Borland Software Corporation       }
{                                                       }
{*******************************************************}
unit XSBuiltIns;

interface

uses SysUtils, InvokeRegistry, FMTBcd, Types;

const
  SHexMarker               = '$';      { do not localize }
  SoapTimePrefix           = 'T';      { do not localize }
  XMLDateSeparator         = '-';      { do not localize }
  XMLHourOffsetMinusMarker = '-';      { do not localize }
  XMLHourOffsetPlusMarker  = '+';      { do not localize }
  XMLTimeSeparator         = ':';      { do not localize }
  XMLMonthPos              = 6;                    
  XMLDayPos                = 9;                      
  XMLYearPos               = 1;
  XMLMilSecPos             = 10;
  XMLDefaultYearDigits     = 4;        
  XMLDurationStart         = 'P';      { do not localize }
  XMLDurationYear          = 'Y';      { do not localize }
  XMLDurationMonth         = 'M';      { do not localize }
  XMLDurationDay           = 'D';      { do not localize }
  XMLDurationHour          = 'H';      { do not localize }
  XMLDurationMinute        = 'M';      { do not localize }
  XMLDurationSecond        = 'S';      { do not localize }
  SNAN                     = 'NAN';    { do not localize }
  SSciNotationMarker: Char = 'E';      { do not localize }
  SDecimal: Char           = '.';      { do not localize }
  SNegative: Char          = '-';      { do not localize }
  SPlus: Char              = '+';      { do not localize }

type

{ forward declarations }

TXSDuration = class;
TXSTime = class;
TXSDate = class;
TXSDateTime = class;

{ TXSTime }

TXSTime = class(TRemotableXS)
  private
    FFractionalSecondString: string;
    FHour: Word;
    FHourOffset: SmallInt;
    FMinute: Word;
    FMinuteOffset: SmallInt;
    FNegativeOffset: Boolean;
    FSecond: Word;
    FUseZeroMilliseconds: Boolean;
    function BuildHourOffset: WideString;
    function IntToFractionalSeconds(Value: Word): string;
  protected
    function GetAsTime: TDateTime;
    function GetFractionalSeconds: Double;
    function GetFractionalSecondString: string;
    function GetHourOffset: SmallInt;
    function GetMillisecond: Word;
    function GetMinuteOffset: SmallInt;
    procedure SetAsTime(Value: TDateTime);
    procedure SetFractionalSeconds(Value: Double);
    procedure SetHour(const Value: Word);
    procedure SetHourOffset(const Value: SmallInt);
    procedure SetMillisecond(const Value: Word);
    procedure SetMinute(const Value: Word);
    procedure SetMinuteOffset(const Value: SmallInt);
    procedure SetSecond(const Value: Word);
    property FractionalSecondString: string read GetFractionalSecondString;
  public
    property AsTime: TDateTime read GetAsTime write SetAsTime;
    property FractionalSeconds: Double read GetFractionalSeconds write
             SetFractionalSeconds;
    property Hour: Word read FHour write SetHour default 0;
    property HourOffset: SmallInt read GetHourOffset write SetHourOffset default 0;
    property Millisecond: Word read GetMillisecond write SetMillisecond default 0;
    property Minute: Word read FMinute write SetMinute default 0;
    property MinuteOffset: SmallInt read GetMinuteOffset write SetMinuteOffset;
    property Second: Word read FSecond write SetSecond default 0;
    property UseZeroMilliseconds: Boolean read FUseZeroMilliseconds write
             FUseZeroMilliseconds;
    function Clone: TXSTime;
    procedure XSToNative(Value: WideString); override;
    function NativeToXS: WideString; override;
end;

{ TXSDate }

TXSDate = class(TRemotableXS)
  private
    { place holder for future work supporting years with greater than 4 digits }
    FAdditionalYearDigits: Word;
    FMonth: Word;
    FDay: Word;
    FYear: Integer;
    FMaxDay: Word;
    FMaxMonth: Word;
    FMinDay: Word;
    FMinMonth: Word;
    FNegativeDate: Boolean;
  protected
    function GetAsDate: TDateTime;
    function GetYear: Integer;
    procedure SetAsDate(Value: TDateTime);
    procedure SetMonth(const Value: Word);
    procedure SetDay(const Value: Word);
    procedure SetYear(const Value: Integer);
    property MaxDay: Word read FMaxDay write FMaxDay;
    property MaxMonth: Word read FMaxMonth write FMaxMonth;
    property MinDay: Word read FMinDay write FMinDay;
    property MinMonth: Word read FMinMonth write FMinMonth;
  public
    constructor Create; override;
    property Month: Word read FMonth write SetMonth default 0;
    property Day: Word read FDay write SetDay default 0;
    property Year: Integer read GetYear write SetYear default 0;
    function Clone: TXSDate;
    procedure XSToNative(Value: WideString); override;
    function NativeToXS: WideString; override;
    property AsDate: TDateTime read GetAsDate write SetAsDate;
end;

{ TXSCustomDateTime }

TXSCustomDateTime = class(TRemotableXS)
  private
    FDateParam: TXSDate;
    FTimeParam: TXSTime;
    procedure SetUseZeroMilliseconds(Value: Boolean);
    function GetUseZeroMilliseconds: Boolean;
  protected
    function GetAsDateTime: TDateTime;
    function GetDay: Word;
    function GetFractionalSeconds: Double;
    function GetHour: Word;
    function GetHourOffset: SmallInt;
    function GetMonth: Word;
    function GetMillisecond: Word;
    function GetMinute: Word;
    function GetMinuteOffset: SmallInt;
    function GetSecond: Word;
    function GetYear: Integer;
    procedure SetAsDateTime(Value: TDateTime);
    procedure SetFractionalSeconds(Value: Double);
    procedure SetDay(const Value: Word); virtual;
    procedure SetHour(const Value: Word); virtual;
    procedure SetHourOffset(const Value: SmallInt); virtual;
    procedure SetMillisecond(const Value: Word); virtual;
    procedure SetMinute(const Value: Word); virtual;
    procedure SetMinuteOffset(const Value: SmallInt); virtual;
    procedure SetMonth(const Value: Word); virtual;
    procedure SetSecond(const Value: Word); virtual;
    procedure SetYear(const Value: Integer); virtual;
    property Millisecond: Word read GetMillisecond write SetMillisecond default 0;
  public
    constructor Create;  override;
    destructor Destroy; override;
    property AsDateTime: TDateTime read GetAsDateTime write SetAsDateTime;
    property Hour: Word read GetHour write SetHour default 0;
    property Minute: Word read GetMinute write SetMinute default 0;
    property Second: Word read GetSecond write SetSecond default 0;
    property Month: Word read GetMonth write SetMonth default 0;
    property Day: Word read GetDay write SetDay default 0;
    property Year: Integer read GetYear write SetYear default 0;
    property UseZeroMilliseconds: Boolean read GetUseZeroMilliseconds write
             SetUseZeroMilliseconds;
end;

{ TXSDateTime }

TXSDateTime = class(TXSCustomDateTime)
  private
    function ValidValue(Value, Subtract, Min, Max: Integer; var Remainder: Integer): Integer;
  public  
    function CompareDateTimeParam(const Value1, Value2: TXSDateTime): TXSDuration;
  public
    function Clone: TXSDateTime;
    property Millisecond: Word read GetMillisecond write SetMillisecond default 0;
    property HourOffset: SmallInt read GetHourOffset write SetHourOffset default 0;
    property MinuteOffset: SmallInt read GetMinuteOffset write SetMinuteOffset default 0;
    procedure XSToNative(Value: WideString); override;
    function NativeToXS: WideString; override;
end;

{ TXSDuration }

TXSDuration = class(TXSCustomDateTime)
  private
    FDecimalSecond: Double;
    function GetDecimalValue(const AParam: String; const AType: string): Double;
    function GetIntegerValue(const AParam: String; const AType: string): Integer;
    function GetNumericString(const AParam: string; const AType: String;
             const Decimals: Boolean = False): WideString;
  protected
    procedure SetDecimalSecond(const Value: Double);
  public
    constructor Create; override;
    procedure XSToNative(Value: WideString); override;
    function NativeToXS: WideString; override;
    property DecimalSecond: Double read FDecimalSecond write SetDecimalSecond;
end;

EXSDateTimeException = class(Exception);
EXSDecimalException = class(Exception);
EXSHexBinaryException = class(Exception);

{ TXSHexBinary }
TXSHexBinary = class(TRemotableXS)
  private
    FHexBinaryString: string;
    procedure  SetAsByteArray(Value: TByteDynArray);
    function   GetAsByteArray: TByteDynArray;
  public
    procedure XSToNative(Value: WideString); override;
    function  NativeToXS: WideString; override;
    property  HexBinaryString: string read FHexBinaryString write FHexBinaryString;
    property  AsByteArray: TByteDynArray read GetAsByteArray write SetAsByteArray;
end;

{ TXSDecimal }
{ Rudimentary support (strictly to handle xsd:decimal) for now }
TXSDecimal = class(TRemotableXS)
  private
    FDecimalString: string;
    function GetAsBcd: TBcd;
    procedure SetAsBcd(Value: TBcd);
  public
    procedure XSToNative(Value: WideString); override;
    function  NativeToXS: WideString; override;
    property  DecimalString: string read FDecimalString write FDecimalString;
    property  AsBcd: TBcd read GetAsBcd write SetAsBcd;
end;

{ TXSString }
TXSString = class(TRemotableXS)
  private
    FString: WideString;
  public
    procedure XSToNative(Value: WideString); override;
    function  NativeToXS: WideString; override;
  end;

TXSTimeInstant = TXSDateTime;

{ Utility function }

function DateTimeToXSDateTime(Value: TDateTime; CalcLocalBias: Boolean = False): TXSDateTime;

implementation

uses SOAPConst, {$IFDEF MSWINDOWS}Windows{$ENDIF}{$IFDEF LINUX}Libc, Types{$ENDIF},
     DateUtils, Classes;

{ exception routines }

procedure SoapDateTimeError(const Message: string); local;
begin
  raise EXSDateTimeException.Create(Message);
end;

procedure SoapDateTimeErrorFmt(const Message: string; const Args: array of const); local;
begin
  SoapDateTimeError(Format(Message,Args));
end;

procedure SoapDecimalError(const Message: string); local;
begin
  raise EXSDecimalException.Create(Message);
end;

procedure SoapDecimalErrorFmt(const Message: string; const Args: array of const); local;
begin
  SoapDecimalError(Format(Message,Args));
end;

procedure SoapHexBinaryError(const Message: string); local;
begin
  raise EXSHexBinaryException.Create(Message);
end;

procedure SoapHexBinaryErrorFmt(const Message: string; const Args: array of const); local;
begin
  SoapHexBinaryError(Format(Message,Args));
end;

{ Utility functions }

procedure AddUTCBias(var DateTime: TXSDateTime);
{$IFDEF MSWINDOWS}
var
  Info: TTimeZoneInformation;
  Status: DWORD;
{$ENDIF}
begin
{$IFDEF MSWINDOWS}
  Status := GetTimeZoneInformation(Info);
  if (Status = TIME_ZONE_ID_UNKNOWN) or (Status = TIME_ZONE_ID_INVALID) then
    SoapDateTimeError(SInvalidTimeZone);
  DateTime.HourOffset := Info.Bias div 60;
  DateTime.MinuteOffset := Info.Bias - (DateTime.HourOffset * 60);
{$ENDIF}
end;

function GetNext(const P: PChar; Digits: Integer; SError, Value: string): string;
const
  Separator : Char = ':';
var  
  I: Integer;
begin
  SetLength(Result, Digits);
  for I := 0 to Digits -1 do
  begin
    if P[I] in ['0'..'9'] then
      Result[I+1] := P[I]
    else
      raise EXSDateTimeException.CreateFmt(SError, [Value]);
  end;
end;

function DateTimeToXSDateTime(Value: TDateTime; CalcLocalBias: Boolean = False): TXSDateTime;
begin
  Result := TXSDateTime.Create;
  Result.AsDateTime := Value;
  if CalcLocalBias then
    AddUTCBias(Result);
end;

function GetAdditionalYears(var Value: string): Integer;
var
  AYear: String;
  Digits: Integer;
begin
  Result := 0;
  if Value[5] = '-' then exit;
  if (Value[1] = '-') and (Value[6] = '-') then exit;
  AYear := Value;
  if AYear[1] = '-' then
    AYear := Copy(AYear, 2, Length(AYear));
  Digits := Pos('-', AYear) - 5;
  if Digits > 0 then
  begin
    try
      Result := StrToInt(Copy(AYear, 1, Digits));
    except
      raise EXSDateTimeException.CreateFmt(SInvalidDateString, [Value]);
    end;
    AYear := Copy(AYear, Digits+1, 12);
  end;
  if Value[1] = '-' then
    Value := WideChar('-') + AYear
  else
    Value := AYear;
end;

function XMLDateToStr(ADate: WideString; AddDigits: Word = 0): WideString;
begin
  Result := Copy(ADate, XMLMonthPos + AddDigits, 2) + DateSeparator +
            Copy(ADate, XMLDayPos + AddDigits, 2 ) +
            DateSeparator + Copy(ADate, XMLYearPos, XMLDefaultYearDigits + AddDigits);
end;

{ Get Small Int Using Digits in value, positive or negative. }
{ TXSTime }

function TXSTime.IntToFractionalSeconds(Value: Word): string;
begin
  if Value < 1000 then
  begin
    Result := StringReplace(Format('.%3d', [Value]), ' ', '0', [rfReplaceAll]);
  end else
    SoapDateTimeErrorFmt(SInvalidMillisecond, [Value]);
end;

function TXSTime.GetFractionalSeconds: Double;
begin
  if FFractionalSecondString = '' then
    Result := 0
  else
    Result := StrToFloat(FFractionalSecondString);
end;

procedure TXSTime.SetFractionalSeconds(Value: Double);
begin
  if Value > 0 then
    SoapDateTimeErrorFmt(SInvalidFractionalSecond, [Value]);
  FFractionalSecondString := FloatToStr(Value);
end;

function TXSTime.GetFractionalSecondString: string;
begin
  if (FFractionalSecondString = '') and UseZeroMilliseconds then
      Result := '.000'
  else
    Result := FFractionalSecondString;
end;

function TXSTime.GetMilliSecond: Word;
begin
  Result := Round(FractionalSeconds*1000);
end;

function TXSTime.Clone: TXSTime;
begin
  Result := TXSTime.Create;
  Result.Hour := Hour;
  Result.Minute := Minute;
  Result.Second := Second;
  Result.MilliSecond := MilliSecond;
  Result.HourOffset := HourOffset;
  Result.MinuteOffset := MinuteOffset;
end;

procedure TXSTime.SetHour(const Value: Word);
begin
  if Value < HoursPerDay then
    FHour := Value
  else
    SoapDateTimeErrorFmt(SInvalidHour, [Value]);
end;

procedure TXSTime.SetMinute(const Value: Word);
begin
  if Value < 60 then
    FMinute := Value
  else
    SoapDateTimeErrorFmt(SInvalidMinute, [Value]);
end;

procedure TXSTime.SetSecond(const Value: Word);
begin
  if Value < 60 then
    FSecond := Value
  else
    SoapDateTimeErrorFmt(SInvalidSecond, [Value]);
end;

procedure TXSTime.SetMillisecond(const Value: Word);
begin
  FFractionalSecondString := IntToFractionalSeconds(Value);
end;

procedure TXSTime.SetHourOffset(const Value: SmallInt);
begin
  if Abs(Value) <= (HoursPerDay div 2) then
  begin
    FHourOffset := Abs(Value);
    if Value < 0 then
      FNegativeOffset := True;
  end else
    SoapDateTimeErrorFmt(SInvalidHourOffset, [Value]);
end;

procedure TXSTime.SetMinuteOffset(const Value: SmallInt);
begin
  if Abs(Value) < 60 then
    FMinuteOffset := Abs(Value)
  else
    SoapDateTimeErrorFmt(SInvalidMinute, [Value]);
end;

function TXSTime.GetHourOffset: SmallInt;
begin
  if FNegativeOffset then
    Result := -FHourOffset
  else
    Result := FHourOffset;
end;

function TXSTime.GetMinuteOffset: SmallInt;
begin
  if FNegativeOffset then
    Result := -FMinuteOffset
  else
    Result := FMinuteOffset;
end;

procedure TXSTime.XSToNative(Value: WideString);
const
  XMLMilSecSeparator : char = '.';
var
  PMilSec, P: PChar;
  LValue: Integer;
  SValue: string;
begin
  { make sure string is long enough }
  SValue := Value;
  LValue := Length(SValue);
  if LValue < 8 then
    raise EXSDateTimeException.CreateFmt(SValue, [SValue]);
  P := PChar(SValue);
  FHour := StrToInt(GetNext(P, 2, SInvalidTimeString, SValue));
  Inc(P, 3);
  FMinute := StrToInt(GetNext(P, 2, SInvalidTimeString, SValue));
  Inc(P, 3);
  FSecond := StrToInt(GetNext(P, 2, SInvalidTimeString, SValue));
  Inc(P, 2);   { now pointing to byte after last second digit }
  { millisecond portion is optional }
  if P^ = XMLMilSecSeparator then
  begin
    { make sure string is long enough }
    if LValue < 10 then
      raise EXSDateTimeException.CreateFmt(SInvalidTimeString, [SValue]);
    PMilSec := P; { save starting position }
    Inc(P);      { skip over Dot }
    if not (P^ in ['0' .. '9']) then
      raise EXSDateTimeException.CreateFmt(SInvalidTimeString, [SValue]);
    while P^ in ['0' .. '9'] do
      Inc(P);
    SetString(FFractionalSecondString, PMilSec, P-PMilSec);
    FUseZeroMilliseconds := True;
  end else
  begin
    FFractionalSecondString := '';
    FUseZeroMilliseconds := False;
  end;
  if P^ in ['-', '+'] then
  begin
    { make sure string is long enough }
    if (LValue < 13 + Length(FFractionalSecondString)) then
      raise EXSDateTimeException.CreateFmt(SInvalidTimeString, [SValue]);
    FNegativeOffset := (P^ = '-');
    Inc(P);
    FHourOffset := StrToInt(GetNext(P, 2, SInvalidTimeOffset, SValue));
    Inc(P, 3);
    MinuteOffset := StrToInt(GetNext(P, 2, SInvalidTimeOffset, SValue));
  end else
  begin
    HourOffset := 0;
    MinuteOffset := 0;
  end;
end;

function TXSTime.BuildHourOffset: WideString;
var
  Marker: String;
begin
  if Abs(FHourOffset) + Abs(FMinuteOffset) > 0 then
  begin
    if FNegativeOffset then
      Marker := XMLHourOffsetMinusMarker
    else
      Marker := XMLHourOffsetPlusMarker;
    Result := IntToStr(Abs(HourOffset));
    if Abs(HourOffset) < 10 then
      Result := '0' + Result;
    if Abs(MinuteOffSet) > 9 then
      Result := Result + XMLTimeSeparator + IntToStr(Abs(MinuteOffset))
    else if Abs(MinuteOffSet) > 0 then
      Result := Result + XMLTimeSeparator + '0' + IntToStr(Abs(MinuteOffset))
    else
      Result := Result + XMLTimeSeparator + '00';
    Result := Marker + Result;
  end;
end;

function TXSTime.NativeToXS: WideString;
begin
  Result := Format('%2d%s%2d%s%2d', [Hour, XMLTimeSeparator,
            Minute, XMLTimeSeparator, Second]) +
            FFractionalSecondString + BuildHourOffset;
  Result := StringReplace(Result, ' ', '0', [rfReplaceAll]);
end;

procedure TXSTime.SetAsTime(Value: TDateTime);
var
  AMilSeconds: Word;
begin
  DecodeTime(Value, FHour, FMinute, FSecond, AMilSeconds);
  FFractionalSecondString := IntToFractionalSeconds(AMilSeconds);
end;

function TXSTime.GetAsTime: TDateTime;
var
  TimeString: string;
  Colon: string;
begin
  Colon := TimeSeparator;
  TimeString := IntToStr(Hour) + Colon + IntToStr(Minute) + Colon +
                IntToStr(Second);
  Result := StrToTime(TimeString);
end;

{ TXSDate }

constructor TXSDate.Create;
begin
  inherited Create;
  FMaxMonth := 12;
  FMinMonth := 1;
  FMaxDay := 31;
  FMinDay := 1;
end;

function TXSDate.Clone: TXSDate;
begin
  Result := TXSDate.Create;
  Result.Day := Day;
  Result.Month := Month;
  Result.Year := Year;
end;

procedure TXSDate.SetMonth(const Value: Word);
begin
  if (Value <= FMaxMonth) and (Value >= FMinMonth) then
    FMonth := Value
  else
    SoapDateTimeErrorFmt(SInvalidMonth, [Value]);
end;

procedure TXSDate.SetDay(const Value: Word);
begin
  { Perform more complete check when all values set }
  if (Value <= FMaxDay) and (Value >= FMinDay) then
    FDay := Value
  else
    SoapDateTimeErrorFmt(SInvalidDay, [Value]);
end;

procedure TXSDate.SetYear(const Value: Integer);
var
  Digits: Integer;
  SYear: string;
begin
  { Non-negative years, Values from 0 to 9999 }
  if (Value < 10000) and (Value >= 0) then
  begin
    FYear := Value;
    FAdditionalYearDigits := 0;
    FNegativeDate := False;
  end else
  begin
    SYear  := IntToStr(Value);
    FNegativeDate := Value < 0;
    { Negative year }
    if FNegativeDate then
      SYear := Copy(SYear, 2, Length(SYear));
    Digits := Length(SYear) - 4;
    FYear := StrToInt(Copy(SYear, 1+Digits, Length(SYear)));
    if Digits > 0 then
      { Value > 9999 }
      FAdditionalYearDigits := StrToInt(Copy(SYear, 1, Digits))
    else
      FAdditionalYearDigits := 0;
  end;
end;


procedure TXSDate.XSToNative(Value: WideString);

  procedure ConvertDate(var Value: string);
  var
    P: PChar;
  begin
    P := PChar(Value);
    FYear := StrToInt(GetNext(P, 4, SInvalidDateString, Value));
    Inc(P, 5);
    FMonth := StrToInt(GetNext(P, 2, SInvalidDateString, Value));
    Inc(P, 3);
    FDay := StrToInt(GetNext(P, 2, SInvalidDateString, Value));
  end;

var
  TempValue: string;
begin
  FNegativeDate := (Value[1] = '-');
  if FNegativeDate then
    TempValue := Copy(Value, 2, Length(Value))
  else
    TempValue := Value;
  FAdditionalYearDigits := GetAdditionalYears(TempValue);
  ConvertDate(TempValue);
end;

function TXSDate.NativeToXS: WideString;
var
  TempDate: TDateTime;
  FormatString: string;
begin
  if Year + Month + Day = 0 then exit;
  TempDate := EncodeDate(FYear, Month, Day);
  FormatString := Format('yyyy%smm%sdd', [XMLDateSeparator, XMLDateSeparator]);
  if FAdditionalYearDigits > 0 then
    FormatString := IntToStr(FAdditionalYearDigits) + FormatString;
  if FNegativeDate then
    FormatString := '-' + FormatString;
  Result := FormatDateTime(FormatString, TempDate);
end;

function TXSDate.GetYear: Integer;
begin
  Result := (FAdditionalYearDigits * 10000) + FYear;
  if FNegativeDate then
    Result := -Result;
end;

function TXSDate.GetAsDate: TDateTime;
var
  DateString: string;
  Slash: string;
begin
  Slash := DateSeparator;
  DateString := IntToStr(Month) + Slash + IntToStr(Day) + Slash + IntToStr(Year);
  Result := StrToDate(DateString);
end;

procedure TXSDate.SetAsDate(Value: TDateTime);
var
  AYear: Word;
begin
  FNegativeDate := False;
  FAdditionalYearDigits :=0;
  DecodeDate(Value, AYear, FMonth, FDay);
  FYear := Integer(AYear);
end;

{ TXSCustomDateTime }

constructor TXSCustomDateTime.Create;
begin
  Inherited Create;
  FDateParam := TXSDate.Create;
  FTimeParam := TXSTime.Create;
end;

destructor TXSCustomDateTime.Destroy;
begin
  FreeAndNil(FDateParam);
  FreeAndNil(FTimeParam);
  inherited Destroy;
end;

function TXSCustomDateTime.GetFractionalSeconds: Double;
begin
  Result := FTimeParam.GetFractionalSeconds;
end;

procedure TXSCustomDateTime.SetFractionalSeconds(Value: Double);
begin
  FTimeParam.SetFractionalSeconds(Value);
end;

procedure TXSCustomDateTime.SetUseZeroMilliseconds(Value: Boolean);
begin
  FTimeParam.FUseZeroMilliseconds := Value;
end;

function TXSCustomDateTime.GetUseZeroMilliseconds: Boolean;
begin
  Result := FTimeParam.FUseZeroMilliseconds;
end;

function TXSCustomDateTime.GetHour: Word;
begin
  Result := FTimeParam.Hour;
end;

function TXSCustomDateTime.GetMinute: Word;
begin
  Result := FTimeParam.Minute;
end;

function TXSCustomDateTime.GetSecond: Word;
begin
  Result := FTimeParam.Second;
end;

function TXSCustomDateTime.GetMilliSecond: Word;
begin
  Result := FTimeParam.MilliSecond;
end;

function TXSCustomDateTime.GetHourOffset: SmallInt;
begin
  Result := FTimeParam.HourOffset
end;

function TXSCustomDateTime.GetMinuteOffset: SmallInt;
begin
  Result := FTimeParam.MinuteOffset
end;

function TXSCustomDateTime.GetMonth: Word;
begin
  Result := FDateParam.Month;
end;

function TXSCustomDateTime.GetDay: Word;
begin
  Result := FDateParam.Day;
end;

function TXSCustomDateTime.GetYear: Integer;
begin
  Result := FDateParam.Year;
end;

procedure TXSCustomDateTime.SetHour(const Value: Word);
begin
  FTimeParam.SetHour(Value);
end;

procedure TXSCustomDateTime.SetMinute(const Value: Word);
begin
  FTimeParam.SetMinute(Value);
end;

procedure TXSCustomDateTime.SetSecond(const Value: Word);
begin
  FTimeParam.SetSecond(Value);
end;

procedure TXSCustomDateTime.SetMillisecond(const Value: Word);
begin
  FTimeParam.SetMillisecond(Value);
end;

procedure TXSCustomDateTime.SetHourOffset(const Value: SmallInt);
begin
  FTimeParam.SetHourOffset(Value);
end;

procedure TXSCustomDateTime.SetMinuteOffset(const Value: SmallInt);
begin
  FTimeParam.SetMinuteOffset(Value);
end;

procedure TXSCustomDateTime.SetMonth(const Value: Word);
begin
  FDateParam.SetMonth(Value);
end;

procedure TXSCustomDateTime.SetDay(const Value: Word);
begin
  FDateParam.SetDay(Value);
end;

procedure TXSCustomDateTime.SetYear(const Value: Integer);
begin
  FDateParam.SetYear(Value);
end;

procedure TXSCustomDateTime.SetAsDateTime(Value: TDateTime);
begin
  FDateParam.AsDate := Value;
  FTimeParam.AsTime := Value;
end;

function TXSCustomDateTime.GetAsDateTime: TDateTime;
begin
  Result := EncodeDateTime(Year, Month, Day, Hour, Minute, Second, 0);
end;

{ TXSDateTime }

function TXSDateTime.Clone: TXSDateTime;
begin
  Result := TXSDateTime.Create;
  Result.FDateParam.Day := Day;
  Result.FDateParam.Month := Month;
  Result.FDateParam.Year := Year;
  Result.FTimeParam.Hour := Hour;
  Result.FTimeParam.Minute := Minute;
  Result.FTimeParam.Second := Second;
  Result.FTimeParam.MilliSecond := MilliSecond;
  Result.FTimeParam.HourOffset := HourOffset;
  Result.FTimeParam.MinuteOffset := MinuteOffset;
end;

procedure TXSDateTime.XSToNative(Value: WideString);
var
  TimeString, DateString: WideString;
  TimePosition: Integer;
begin
  TimePosition := Pos(SoapTimePrefix, Value);
  if TimePosition > 0 then
  begin
    DateString := Copy(Value, 1, TimePosition -1);
    TimeString := Copy(Value, TimePosition + 1, Length(Value) - TimePosition);
    FDateParam.XSToNative(DateString);
    FTimeParam.XSToNative(TimeString);
  end else
  begin
    FTimeParam.Hour := 0;
    FTimeParam.Minute := 0;
    FTimeParam.Second := 0;
    FTimeParam.Millisecond := 0;
    FTimeParam.HourOffset := 0;
    FDateParam.XSToNative(Value);
  end;
end;

function TXSDateTime.NativeToXS: WideString;
var
  TimeString: WideString;
begin
  TimeString := FTimeParam.NativeToXS;
  if TimeString <> '' then
    Result := FDateParam.NativeToXS + SoapTimePrefix + TimeString
  else
    Result := FDateParam.NativeToXS;
end;

function TXSDateTime.ValidValue(Value, Subtract, Min, Max: Integer; var Remainder: Integer): Integer;
begin
  Result := Value - Subtract;
  Remainder := 0;
  if Result < Min then
  begin
    Remainder := 1;
    Inc(Result,Max);
  end;
end;

function TXSDateTime.CompareDateTimeParam(const Value1, Value2: TXSDateTime): TXSDuration;
var
  Remainder, Milliseconds, Seconds: Integer;
begin
    Result := TXSDuration.Create;
    try
      MilliSeconds := ValidValue(Value1.Millisecond, Value2.Millisecond, 0, 1000, Remainder);
      Seconds := ValidValue(Value1.Second + Remainder, Value2.Second, 0, 60, Remainder);
      Result.DecimalSecond := Seconds + Milliseconds / 1000;
      Result.Minute := ValidValue(Value1.Minute + Remainder, Value2.Minute, 0, 60, Remainder);
      Result.Hour := ValidValue(Value1.Hour + Remainder, Value2.Hour, 0, 24, Remainder);
      Result.Day := ValidValue(Value1.Day + Remainder, Value2.Day, 0, 31, Remainder);
      Result.Month := ValidValue(Value1.Month + Remainder, Value2.Month, 0, 12, Remainder);
      Result.Year := ValidValue(Value1.Year + Remainder, Value2.Year, -9999, 0, Remainder);
    except
      Result.Free;
      Result := nil;
    end;
end;


{ TXSDuration }

constructor TXSDuration.Create;
begin
  inherited Create;
  FDateParam.MaxDay := 30;
  FDateParam.MinDay := 0;
  FDateParam.MaxMonth := 11;
  FDateParam.MinMonth := 0;
end;

procedure TXSDuration.SetDecimalSecond(const Value: Double);
begin
  if Value < 60 then
    FDecimalSecond := Value
  else
    SoapDateTimeErrorFmt(SInvalidFractionSecond, [Value]);
end;

function TXSDuration.GetNumericString(const AParam: string; const AType: string;
         const Decimals: Boolean = False): WideString;
var
  I, J: Integer;
begin
  I := Pos(AType, AParam);
  J := I;
  while (I > 0) and ((AParam[I-1] in ['0'..'9']) or
        (Decimals and (AParam[I-1] = '.'))) do
    Dec(I);
  if J > I then
    Result := Copy(AParam, I, J-I)
  else
    Result := '0';
end;

function TXSDuration.GetIntegerValue(const AParam: string; const AType: string): Integer;
begin
  Result := StrToInt(GetNumericString(AParam, AType));
end;

function TXSDuration.GetDecimalValue(const AParam: string; const AType: string): Double;
begin
  Result := StrToFloat(GetNumericString(AParam, AType, True));
end;

procedure TXSDuration.XSToNative(Value: WideString);
var
  DateString, TimeString: string;
  TimePosition: Integer;
begin
  if Value[1] <> XMLDurationStart then
    SoapDateTimeErrorFmt(SInvalidDuration, [Value]);
  TimePosition := Pos(SoapTimePrefix, Value);
  if TimePosition > 0 then
  begin
    TimeString := Copy(Value, TimePosition + 1, Length(Value) - TimePosition);
    DateString := Copy(Value, 1, TimePosition - 1);
  end else
    DateString := Value;
  Year := GetIntegerValue(DateString, XMLDurationYear);
  Month := GetIntegerValue(DateString, XMLDurationMonth);
  Day := GetIntegerValue(DateString, XMLDurationDay);
  if TimePosition > 0 then
  begin
    Hour := GetIntegerValue(TimeString, XMLDurationHour);
    Minute := GetIntegerValue(TimeString, XMLDurationMinute);
    DecimalSecond := GetDecimalValue(TimeString, XMLDurationSecond);
  end;
end;

{ Format is 'P1Y2M3DT10H30M12.3S' }
function TXSDuration.NativeToXS: WideString;
begin
  Result := XMLDurationStart +
              IntToStr(Year) + XMLDurationYear +
              IntToStr(Month) + XMLDurationMonth +
              IntToStr(Day) + XMLDurationDay + SoapTimePrefix +
              IntToStr(Hour) + XMLDurationHour +
              IntToStr(Minute) + XMLDurationMinute +
              FloatToStr(DecimalSecond) + XMLDurationSecond;
end;

{ TXSHexBinary }

function TXSHexBinary.NativeToXS: WideString;
begin
  Result := FHexBinaryString;
end;

procedure TXSHexBinary.XSToNative(Value: WideString);
var
  PText: PChar;
  V: string;
  L : Integer;
begin
  V := Value;
  L := Length(V);
  PText := AllocMem(L * 2 + 1);
  try
    if Pos(SHexMarker, V) = 0 then
      V := SHexMarker + V;
    if HexToBin(PChar(V), PText, L) > 0 then
      SoapHexBinaryErrorFmt(SInvalidHexValue, [Value]);
    FHexBinaryString := Value;
  finally
    FreeMem(PText);
  end;
end;

function TXSHexBinary.GetAsByteArray: TByteDynArray;
var
  P: PChar;
begin
  if FHexBinaryString = '' then
    SetLength(Result, 0)
  else
  begin
    SetLength(Result, Length(FHexBinaryString));
    P := @Result[0];
    HexToBin(PChar(FHexBinaryString), P, Length(FHexBinaryString));
  end;
end;

procedure TXSHexBinary.SetAsByteArray(Value: TByteDynArray);
var
  P, PText: PChar;
  L : Integer;
begin
  P := @Value[0];
  L := Length(Value);
  PText := AllocMem((L+1) * 2);
  try
    BinToHex(P, PText, L);
    SetString(FHexBinaryString, PText, StrLen(PText));
  finally
    FreeMem(PText);
  end;
end;

{ TXSDecimal }

function TXSDecimal.NativeToXS: WideString;
begin
  Result := FDecimalString;
end;

procedure TXSDecimal.XSToNative(Value: WideString);
begin
  FDecimalString := Value;
end;

function TXSDecimal.GetAsBcd: TBcd;

  procedure CheckDecimalString;
  begin
    if FDecimalString = '' then
      SoapDecimalError(SEmptyDecimalString)
    else if Pos(SSciNotationMarker, FDecimalString) > 0 then  
      SoapDecimalError(SNoSciNotation)
    else if Pos(SNAN, FDecimalString) > 0 then  
      SoapDecimalError(SNoNAN)
    else if Length(FDecimalString) > 2 + (MaxFMTBcdDigits * 2) then
      SoapDecimalErrorFMT(SBcdStringTooBig, [FDecimalString]);
  end;

begin
  CheckDecimalString;
  if not TryStrToBcd(FDecimalString, Result) then
    SoapDecimalErrorFmt(SInvalidDecimalString, [FDecimalString]);
end;

procedure TXSDecimal.SetAsBcd(Value: TBcd);
begin
  if (Value.Precision > MaxFMTBcdDigits * 2) or
     (Value.Precision < 1) or
     (BcdScale(Value) > MaxFMTBcdDigits * 2) then
    SoapDecimalErrorFmt(SInvalidBcd, [Value.Precision, BcdScale(Value)]);
  FDecimalString := BcdToStr(Value);
end;

{ TXSString }
procedure TXSString.XSToNative(Value: WideString);
begin
  FString := Value;
end;

function  TXSString.NativeToXS: WideString;
begin
  Result := FString;
end;

const
  DupeChecks = 3;
  DupeTypes: array[0..DupeChecks] of Char = ('-', '.', 'E', '+');

type
  NoDupes = array[0..DupeChecks] of Boolean;
  TValidOnce = (voNeg, voDec, voSci, voPlus);
  
initialization
  RemClassRegistry.RegisterXSClass(TXSDateTime, XMLSchemaNameSpace, 'dateTime', '',True);
  { timeInstant is not really TXDateTime due to different lexical format }
  RemClassRegistry.RegisterXSClass(TXSTimeInstant, XMLSchemaNameSpace, 'timeInstant', '', True);
  RemClassRegistry.RegisterXSClass(TXSTime, XMLSchemaNameSpace, 'time', '', True);
  RemClassRegistry.RegisterXSClass(TXSDate, XMLSchemaNameSpace, 'date', '', True);
  RemClassRegistry.RegisterXSClass(TXSDuration, XMLSchemaNameSpace, 'duration', '', True);
  RemClassRegistry.RegisterXSClass(TXSDuration, XMLSchemaNameSpace, 'timeDuration', '', True);
  RemClassRegistry.RegisterXSClass(TXSHexBinary, XMLSchemaNamespace, 'hexBinary', '', True);
  RemClassRegistry.RegisterXSClass(TXSDecimal, XMLSchemaNamespace, 'decimal', '', True);

  RemClassRegistry.RegisterXSClass(TXSDecimal, XMLSchemaNamespace, 'negativeInteger', '', True);
  RemClassRegistry.RegisterXSClass(TXSDecimal, XMLSchemaNamespace, 'nonNegativeInteger', '', True);
  RemClassRegistry.RegisterXSClass(TXSDecimal, XMLSchemaNamespace, 'nonPositiveInteger', '', True);
  RemClassRegistry.RegisterXSClass(TXSDecimal, XMLSchemaNamespace, 'positiveInteger', '', True);
end.
