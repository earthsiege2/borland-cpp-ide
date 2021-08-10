{************************************************************************}
{                                                                        }
{       Borland Delphi Visual Component Library                          }
{       InterBase Express core components                                }
{                                                                        }
{       Copyright (c) 1998-2001 Borland Software Corporation             }
{                                                                        }
{    InterBase Express is based in part on the product                   }
{    Free IB Components, written by Gregory H. Deatz for                 }
{    Hoagland, Longo, Moran, Dunst & Doukas Company.                     }
{    Free IB Components is used under license.                           }
{                                                                        }
{    The contents of this file are subject to the InterBase              }
{    Public License Version 1.0 (the "License"); you may not             }
{    use this file except in compliance with the License. You may obtain }
{    a copy of the License at http://www.borland.com/interbase/IPL.html  }
{    Software distributed under the License is distributed on            }
{    an "AS IS" basis, WITHOUT WARRANTY OF ANY KIND, either              }
{    express or implied. See the License for the specific language       }
{    governing rights and limitations under the License.                 }
{    The Original Code was created by InterBase Software Corporation     }
{       and its successors.                                              }
{    Portions created by Borland Software Corporation are Copyright      }
{       (C) Borland Software Corporation. All Rights Reserved.           }
{    Contributor(s): Jeff Overcash                                       }
{                                                                        }
{************************************************************************}

unit IBSQL;

interface

uses
  SysUtils, Variants,
  {$IFDEF MSWINDOWS}
  Windows,
  {$ENDIF}
  {$IFDEF LINUX}
  Libc,
  {$ENDIF}
  Classes, IBHeader, IBErrorCodes, IBExternals, DB, IB, IBDatabase,
  IBUtils, IBXConst;

type
  TIBSQL = class;
  TIBXSQLDA = class;
  
  { TIBXSQLVAR }
  TIBXSQLVAR = class(TObject)
  private
    FParent: TIBXSQLDA;
    FSQL: TIBSQL;
    FIndex: Integer;
    FModified: Boolean;
    FName: String;
    FXSQLVAR: PXSQLVAR;       { Point to the PXSQLVAR in the owner object }
    FMaxLen : Short;     (** length of data area **)

    function AdjustScale(Value: Int64; Scale: Integer): Double;
    function AdjustScaleToInt64(Value: Int64; Scale: Integer): Int64;
    function AdjustScaleToCurrency(Value: Int64; Scale: Integer): Currency;
    function GetAsCurrency: Currency;
    function GetAsInt64: Int64;
    function GetAsDateTime: TDateTime;
    function GetAsDouble: Double;
    function GetAsFloat: Float;
    function GetAsLong: Long;
    function GetAsPointer: Pointer;
    function GetAsQuad: TISC_QUAD;
    function GetAsShort: Short;
    function GetAsString: String;
    function GetAsVariant: Variant;
    function GetAsXSQLVAR: PXSQLVAR;
    function GetIsNull: Boolean;
    function GetIsNullable: Boolean;
    function GetSize: Integer;
    function GetSQLType: Integer;
    procedure SetAsCurrency(Value: Currency);
    procedure SetAsInt64(Value: Int64);
    procedure SetAsDate(Value: TDateTime);
    procedure SetAsTime(Value: TDateTime);
    procedure SetAsDateTime(Value: TDateTime);
    procedure SetAsDouble(Value: Double);
    procedure SetAsFloat(Value: Float);
    procedure SetAsLong(Value: Long);
    procedure SetAsPointer(Value: Pointer);
    procedure SetAsQuad(Value: TISC_QUAD);
    procedure SetAsShort(Value: Short);
    procedure SetAsString(Value: String);
    procedure SetAsVariant(Value: Variant);
    procedure SetAsXSQLVAR(Value: PXSQLVAR);
    procedure SetIsNull(Value: Boolean);
    procedure SetIsNullable(Value: Boolean);
    procedure SetAsTrimString(const Value: String);
    function GetAsTrimString: String;
  public
    constructor Create(Parent: TIBXSQLDA; Query: TIBSQL);
    procedure Assign(Source: TIBXSQLVAR);
    procedure LoadFromFile(const FileName: String);
    procedure LoadFromStream(Stream: TStream);
    procedure SaveToFile(const FileName: String);
    procedure SaveToStream(Stream: TStream);
    procedure Clear;
    property AsDate: TDateTime read GetAsDateTime write SetAsDate;
    property AsTime: TDateTime read GetAsDateTime write SetAsTime;
    property AsDateTime: TDateTime read GetAsDateTime write SetAsDateTime;
    property AsDouble: Double read GetAsDouble write SetAsDouble;
    property AsFloat: Float read GetAsFloat write SetAsFloat;
    property AsCurrency: Currency read GetAsCurrency write SetAsCurrency;
    property AsInt64: Int64 read GetAsInt64 write SetAsInt64;
    property AsInteger: Integer read GetAsLong write SetAsLong;
    property AsLong: Long read GetAsLong write SetAsLong;
    property AsPointer: Pointer read GetAsPointer write SetAsPointer;
    property AsQuad: TISC_QUAD read GetAsQuad write SetAsQuad;
    property AsShort: Short read GetAsShort write SetAsShort;
    property AsString: String read GetAsString write SetAsString;
    property AsTrimString : String read GetAsTrimString write SetAsTrimString;
    property AsVariant: Variant read GetAsVariant write SetAsVariant;
    property AsXSQLVAR: PXSQLVAR read GetAsXSQLVAR write SetAsXSQLVAR;
    property Data: PXSQLVAR read FXSQLVAR write FXSQLVAR;
    property IsNull: Boolean read GetIsNull write SetIsNull;
    property IsNullable: Boolean read GetIsNullable write SetIsNullable;
    property Index: Integer read FIndex;
    property Modified: Boolean read FModified write FModified;
    property Name: String read FName;
    property Size: Integer read GetSize;
    property SQLType: Integer read GetSQLType;
    property Value: Variant read GetAsVariant write SetAsVariant;
  end;

  TIBXSQLVARArray = Array of TIBXSQLVAR;

  { TIBXSQLVAR }
  TIBXSQLDA = class(TObject)
  protected
    FSQL: TIBSQL;
    FCount: Integer;
    FNames: TStrings;
    FSize: Integer;
    FXSQLDA: PXSQLDA;
    FXSQLVARs: TIBXSQLVARArray; { array of IBXQLVARs }
    FUniqueRelationName: String;
    function GetModified: Boolean;
    function GetNames: String;
    function GetRecordSize: Integer;
    function GetXSQLDA: PXSQLDA;
    function GetXSQLVAR(Idx: Integer): TIBXSQLVAR;
    function GetXSQLVARByName(Idx: String): TIBXSQLVAR;
    procedure Initialize;
    procedure SetCount(Value: Integer);
  public
    constructor Create(Query: TIBSQL);
    destructor Destroy; override;
    procedure AddName(FieldName: String; Idx: Integer);
    function ByName(Idx: String): TIBXSQLVAR;
    property AsXSQLDA: PXSQLDA read GetXSQLDA;
    property Count: Integer read FCount write SetCount;
    property Modified: Boolean read GetModified;
    property Names: String read GetNames;
    property RecordSize: Integer read GetRecordSize;
    property Vars[Idx: Integer]: TIBXSQLVAR read GetXSQLVAR; default;
    property UniqueRelationName: String read FUniqueRelationName;
  end;

  { TIBBatch }

  TIBBatch = class(TObject)
  protected
    FFilename: String;
    FColumns: TIBXSQLDA;
    FParams: TIBXSQLDA;
  public
    procedure ReadyFile; virtual; abstract;
    property Columns: TIBXSQLDA read FColumns write FColumns;
    property Filename: String read FFilename write FFilename;
    property Params: TIBXSQLDA read FParams write FParams;
  end;

  TIBBatchInput = class(TIBBatch)
  public
    function ReadParameters: Boolean; virtual; abstract;
  end;

  TIBBatchOutput = class(TIBBatch)
  public
    function WriteColumns: Boolean; virtual; abstract;
  end;

  { TIBOutputDelimitedFile }
  TIBOutputDelimitedFile = class(TIBBatchOutput)
  protected
    FFile : TFileStream;
    FOutputTitles: Boolean;
    FColDelimiter,
    FRowDelimiter: string;
  public
    destructor Destroy; override;
    procedure ReadyFile; override;
    function WriteColumns: Boolean; override;
    property ColDelimiter: string read FColDelimiter write FColDelimiter;
    property OutputTitles: Boolean read FOutputTitles
                                   write FOutputTitles;
    property RowDelimiter: string read FRowDelimiter write FRowDelimiter;
  end;

  { TIBInputDelimitedFile }
  TIBInputDelimitedFile = class(TIBBatchInput)
  protected
    FColDelimiter,
    FRowDelimiter: string;
    FEOF: Boolean;
    FFile: TFileStream;
    FLookAhead: Char;
    FReadBlanksAsNull: Boolean;
    FSkipTitles: Boolean;
  public
    destructor Destroy; override;
    function GetColumn(var Col: string): Integer;
    function ReadParameters: Boolean; override;
    procedure ReadyFile; override;
    property ColDelimiter: string read FColDelimiter write FColDelimiter;
    property ReadBlanksAsNull: Boolean read FReadBlanksAsNull
                                       write FReadBlanksAsNull;
    property RowDelimiter: string read FRowDelimiter write FRowDelimiter;
    property SkipTitles: Boolean read FSkipTitles write FSkipTitles;
  end;

  { TIBOutputRawFile }
  TIBOutputRawFile = class(TIBBatchOutput)
  protected
    FFile : TFileStream;
  public
    destructor Destroy; override;
    procedure ReadyFile; override;
    function WriteColumns: Boolean; override;
  end;

  { TIBInputRawFile }
  TIBInputRawFile = class(TIBBatchInput)
  protected
    FFile : TFileStream;
  public
    destructor Destroy; override;
    function ReadParameters: Boolean; override;
    procedure ReadyFile; override;
  end;

  { TIBSQL }
  TIBSQLTypes = (SQLUnknown, SQLSelect, SQLInsert,
                  SQLUpdate, SQLDelete, SQLDDL,
                  SQLGetSegment, SQLPutSegment,
                  SQLExecProcedure, SQLStartTransaction,
                  SQLCommit, SQLRollback,
                  SQLSelectForUpdate, SQLSetGenerator);

  TIBSQL = class(TComponent)
  private
    FIBLoaded: Boolean;
  protected
    FBase: TIBBase;
    FBOF,                          { At BOF? }
    FEOF,                          { At EOF? }
    FGoToFirstRecordOnExecute,     { Automatically position record on first record after executing }
    FOpen,                         { Is a cursor open? }
    FPrepared: Boolean;            { Has the query been prepared? }
    FRecordCount: Integer;         { How many records have been read so far? }
    FCursor: String;               { Cursor name...}
    FHandle: TISC_STMT_HANDLE;     { Once prepared, this accesses the SQL Query }
    FOnSQLChanging: TNotifyEvent;  { Call this when the SQL is changing }
    FSQL: TStrings;                { SQL Query (by user) }
    FParamCheck: Boolean;          { Check for parameters? (just like TQuery) }
    FProcessedSQL: TStrings;       { SQL Query (pre-processed for param labels) }
    FSQLParams,                    { Any parameters to the query }
    FSQLRecord: TIBXSQLDA;         { The current record }
    FSQLType: TIBSQLTypes;         { Select, update, delete, insert, create, alter, etc...}
    FGenerateParamNames: Boolean;  { Auto generate param names ?}
    procedure DoBeforeDatabaseDisconnect(Sender: TObject);
    function GetDatabase: TIBDatabase;
    function GetDBHandle: PISC_DB_HANDLE;
    function GetEOF: Boolean;
    function GetFields(const Idx: Integer): TIBXSQLVAR;
    function GetFieldIndex(FieldName: String): Integer;
    function GetPlan: String;
    function GetRecordCount: Integer;
    function GetRowsAffected: Integer;
    function GetSQLParams: TIBXSQLDA;
    function GetTransaction: TIBTransaction;
    function GetTRHandle: PISC_TR_HANDLE;
    procedure PreprocessSQL;
    procedure SetDatabase(Value: TIBDatabase);
    procedure SetSQL(Value: TStrings);
    procedure SetTransaction(Value: TIBTransaction);
    procedure SQLChanging(Sender: TObject);
    procedure BeforeTransactionEnd(Sender: TObject);
  public
    constructor Create(AOwner: TComponent); override;
    destructor Destroy; override;
    procedure BatchInput(InputObject: TIBBatchInput);
    procedure BatchOutput(OutputObject: TIBBatchOutput);
    function Call(ErrCode: ISC_STATUS; RaiseError: Boolean): ISC_STATUS;
    procedure CheckClosed;           { raise error if query is not closed. }
    procedure CheckOpen;             { raise error if query is not open.}
    procedure CheckValidStatement;   { raise error if statement is invalid.}
    procedure Close;
    function Current: TIBXSQLDA;
    procedure ExecQuery;
    function FieldByName(FieldName: String): TIBXSQLVAR;
    procedure FreeHandle;
    function Next: TIBXSQLDA;
    procedure Prepare;
    function GetUniqueRelationName: String;
    function ParamByName(Idx: String): TIBXSQLVAR;
    property Bof: Boolean read FBOF;
    property DBHandle: PISC_DB_HANDLE read GetDBHandle;
    property Eof: Boolean read GetEOF;
    property Fields[const Idx: Integer]: TIBXSQLVAR read GetFields;
    property FieldIndex[FieldName: String]: Integer read GetFieldIndex;
    property Open: Boolean read FOpen;
    property Params: TIBXSQLDA read GetSQLParams;
    property Plan: String read GetPlan;
    property Prepared: Boolean read FPrepared;
    property RecordCount: Integer read GetRecordCount;
    property RowsAffected: Integer read GetRowsAffected;
    property SQLType: TIBSQLTypes read FSQLType;
    property TRHandle: PISC_TR_HANDLE read GetTRHandle;
    property Handle: TISC_STMT_HANDLE read FHandle;
    property GenerateParamNames: Boolean read FGenerateParamNames write FGenerateParamNames;
    property UniqueRelationName: String read GetUniqueRelationName;
  published
    property Database: TIBDatabase read GetDatabase write SetDatabase;
    property GoToFirstRecordOnExecute: Boolean read FGoToFirstRecordOnExecute
                                               write FGoToFirstRecordOnExecute
                                               default True;
    property ParamCheck: Boolean read FParamCheck write FParamCheck;
    property SQL: TStrings read FSQL write SetSQL;
    property Transaction: TIBTransaction read GetTransaction write SetTransaction;
    property OnSQLChanging: TNotifyEvent read FOnSQLChanging write FOnSQLChanging;
  end;

implementation

uses
  {$IFDEF LINUX}
  Types,
  {$ENDIF}
  IBIntf, IBBlob, IBSQLMonitor;

{ TIBXSQLVAR }
constructor TIBXSQLVAR.Create(Parent: TIBXSQLDA; Query: TIBSQL);
begin
  inherited Create;
  FParent := Parent;
  FSQL := Query;
end;

procedure TIBXSQLVAR.Assign(Source: TIBXSQLVAR);
var
  szBuff: PChar;
  s_bhandle, d_bhandle: TISC_BLOB_HANDLE;
  bSourceBlob, bDestBlob: Boolean;
  iSegs, iMaxSeg, iSize: Long;
  iBlobType: Short;
begin
  szBuff := nil;
  bSourceBlob := True;
  bDestBlob := True;
  s_bhandle := nil;
  d_bhandle := nil;
  try
    if (Source.IsNull) then
    begin
      IsNull := True;
      exit;
    end
    else
      if (FXSQLVAR^.sqltype and (not 1) = SQL_ARRAY) or
         (Source.FXSQLVAR^.sqltype and (not 1) = SQL_ARRAY) then
        exit; { arrays not supported }
    if (FXSQLVAR^.sqltype and (not 1) <> SQL_BLOB) and
       (Source.FXSQLVAR^.sqltype and (not 1) <> SQL_BLOB) then
    begin
      AsXSQLVAR := Source.AsXSQLVAR;
      exit;
    end
    else
      if (Source.FXSQLVAR^.sqltype and (not 1) <> SQL_BLOB) then
      begin
        szBuff := nil;
        IBAlloc(szBuff, 0, Source.FXSQLVAR^.sqllen);
        Move(Source.FXSQLVAR^.sqldata[0], szBuff[0], Source.FXSQLVAR^.sqllen);
        bSourceBlob := False;
        iSize := Source.FXSQLVAR^.sqllen;
      end
      else
        if (FXSQLVAR^.sqltype and (not 1) <> SQL_BLOB) then
          bDestBlob := False;

    if bSourceBlob then
    begin
      { read the blob }
      Source.FSQL.Call(isc_open_blob2(StatusVector, Source.FSQL.DBHandle,
        Source.FSQL.TRHandle, @s_bhandle, PISC_QUAD(Source.FXSQLVAR.sqldata),
        0, nil), True);
      try
        IBBlob.GetBlobInfo(@s_bhandle, iSegs, iMaxSeg, iSize,
          iBlobType);
        szBuff := nil;
        IBAlloc(szBuff, 0, iSize);
        IBBlob.ReadBlob(@s_bhandle, szBuff, iSize);
      finally
        Source.FSQL.Call(isc_close_blob(StatusVector, @s_bhandle), True);
      end;
    end;

    if bDestBlob then
    begin
      { write the blob }
      FSQL.Call(isc_create_blob2(StatusVector, FSQL.DBHandle,
        FSQL.TRHandle, @d_bhandle, PISC_QUAD(FXSQLVAR.sqldata),
        0, nil), True);
      try
        IBBlob.WriteBlob(@d_bhandle, szBuff, iSize);
        IsNull := false;
      finally
        FSQL.Call(isc_close_blob(StatusVector, @d_bhandle), True);
      end;
    end
    else
    begin
      { just copy the buffer }
      FXSQLVAR.sqltype := SQL_TEXT;
      FXSQLVAR.sqllen := iSize;
      IBAlloc(FXSQLVAR.sqldata, iSize, iSize);
      Move(szBuff[0], FXSQLVAR^.sqldata[0], iSize);
    end;
  finally
    FreeMem(szBuff);
  end;
end;

function TIBXSQLVAR.AdjustScale(Value: Int64; Scale: Integer): Double;
var
  Scaling : Int64;
  i: Integer;
  Val: Double;
begin
  Scaling := 1; Val := Value;
  if Scale > 0 then
  begin
    for i := 1 to Scale do
      Scaling := Scaling * 10;
    result := Val * Scaling;
  end
  else
    if Scale < 0 then
    begin
      for i := -1 downto Scale do
        Scaling := Scaling * 10;
      result := Val / Scaling;
    end
    else
      result := Val;
end;

function TIBXSQLVAR.AdjustScaleToInt64(Value: Int64; Scale: Integer): Int64;
var
  Scaling : Int64;
  i: Integer;
  Val: Int64;
begin
  Scaling := 1; Val := Value;
  if Scale > 0 then begin
    for i := 1 to Scale do Scaling := Scaling * 10;
    result := Val * Scaling;
  end else if Scale < 0 then begin
    for i := -1 downto Scale do Scaling := Scaling * 10;
    result := Val div Scaling;
  end else
    result := Val;
end;

function TIBXSQLVAR.AdjustScaleToCurrency(Value: Int64; Scale: Integer): Currency;
var
  Scaling : Int64;
  i : Integer;
  FractionText, PadText, CurrText: string;
begin
  Result := 0;
  Scaling := 1;
  if Scale > 0 then
  begin
    for i := 1 to Scale do
      Scaling := Scaling * 10;
    result := Value * Scaling;
  end
  else
    if Scale < 0 then
    begin
      for i := -1 downto Scale do
        Scaling := Scaling * 10;
      FractionText := IntToStr(abs(Value mod Scaling));
      for i := Length(FractionText) to -Scale -1 do
        PadText := '0' + PadText;
      if Value < 0 then
        CurrText := '-' + IntToStr(Abs(Value div Scaling)) + DecimalSeparator + PadText + FractionText
      else
        CurrText := IntToStr(Abs(Value div Scaling)) + DecimalSeparator + PadText + FractionText;
      try
        result := StrToCurr(CurrText);
      except
        on E: Exception do
          IBError(ibxeInvalidDataConversion, [nil]);
      end;
    end
    else
      result := Value;
end;

function TIBXSQLVAR.GetAsCurrency: Currency;
begin
  result := 0;
  if FSQL.Database.SQLDialect < 3 then
    result := GetAsDouble
  else begin
    if not IsNull then
      case FXSQLVAR^.sqltype and (not 1) of
        SQL_TEXT, SQL_VARYING: begin
          try
            result := StrtoCurr(AsString);
          except
            on E: Exception do IBError(ibxeInvalidDataConversion, [nil]);
          end;
        end;
        SQL_SHORT:
          result := AdjustScaleToCurrency(Int64(PShort(FXSQLVAR^.sqldata)^),
                                      FXSQLVAR^.sqlscale);
        SQL_LONG:
          result := AdjustScaleToCurrency(Int64(PLong(FXSQLVAR^.sqldata)^),
                                      FXSQLVAR^.sqlscale);
        SQL_INT64:
          result := AdjustScaleToCurrency(PInt64(FXSQLVAR^.sqldata)^,
                                      FXSQLVAR^.sqlscale);
        SQL_DOUBLE, SQL_FLOAT, SQL_D_FLOAT:
          result := GetAsDouble;
        else
          IBError(ibxeInvalidDataConversion, [nil]);
      end;
    end;
end;

function TIBXSQLVAR.GetAsInt64: Int64;
begin
  result := 0;
  if not IsNull then
    case FXSQLVAR^.sqltype and (not 1) of
      SQL_TEXT, SQL_VARYING: begin
        try
          result := StrToInt64(AsString);
        except
          on E: Exception do IBError(ibxeInvalidDataConversion, [nil]);
        end;
      end;
      SQL_SHORT:
        result := AdjustScaleToInt64(Int64(PShort(FXSQLVAR^.sqldata)^),
                                    FXSQLVAR^.sqlscale);
      SQL_LONG:
        result := AdjustScaleToInt64(Int64(PLong(FXSQLVAR^.sqldata)^),
                                    FXSQLVAR^.sqlscale);
      SQL_INT64:
        result := AdjustScaleToInt64(PInt64(FXSQLVAR^.sqldata)^,
                                    FXSQLVAR^.sqlscale);
      SQL_DOUBLE, SQL_FLOAT, SQL_D_FLOAT:
        result := Trunc(AsDouble);
      else
        IBError(ibxeInvalidDataConversion, [nil]);
    end;
end;

function TIBXSQLVAR.GetAsDateTime: TDateTime;
var
  tm_date: TCTimeStructure;
begin
  result := 0;
  if not IsNull then
    case FXSQLVAR^.sqltype and (not 1) of
      SQL_TEXT, SQL_VARYING: begin
        try
          result := StrToDate(AsString);
        except
          on E: EConvertError do IBError(ibxeInvalidDataConversion, [nil]);
        end;
      end;
      SQL_TYPE_DATE: begin
        isc_decode_sql_date(PISC_DATE(FXSQLVAR^.sqldata), @tm_date);
        try
          result := EncodeDate(Word(tm_date.tm_year + 1900), Word(tm_date.tm_mon + 1),
                               Word(tm_date.tm_mday));
        except
          on E: EConvertError do begin
            IBError(ibxeInvalidDataConversion, [nil]);
          end;
        end;
      end;
      SQL_TYPE_TIME: begin
        isc_decode_sql_time(PISC_TIME(FXSQLVAR^.sqldata), @tm_date);
        try
          result := EncodeTime(Word(tm_date.tm_hour), Word(tm_date.tm_min),
                               Word(tm_date.tm_sec), 0)
        except
          on E: EConvertError do begin
            IBError(ibxeInvalidDataConversion, [nil]);
          end;
        end;
      end;
      SQL_TIMESTAMP: begin
        isc_decode_date(PISC_QUAD(FXSQLVAR^.sqldata), @tm_date);
        try
          result := EncodeDate(Word(tm_date.tm_year + 1900), Word(tm_date.tm_mon + 1),
                              Word(tm_date.tm_mday));
          if result >= 0 then
            result := result + EncodeTime(Word(tm_date.tm_hour), Word(tm_date.tm_min),
                                          Word(tm_date.tm_sec), 0)
          else
            result := result - EncodeTime(Word(tm_date.tm_hour), Word(tm_date.tm_min),
                                          Word(tm_date.tm_sec), 0)
        except
          on E: EConvertError do begin
            IBError(ibxeInvalidDataConversion, [nil]);
          end;
        end;
      end;
      else
        IBError(ibxeInvalidDataConversion, [nil]);
    end;
end;

function TIBXSQLVAR.GetAsDouble: Double;
begin
  result := 0;
  if not IsNull then begin
    case FXSQLVAR^.sqltype and (not 1) of
      SQL_TEXT, SQL_VARYING: begin
        try
          result := StrToFloat(AsString);
        except
          on E: Exception do IBError(ibxeInvalidDataConversion, [nil]);
        end;
      end;
      SQL_SHORT:
        result := AdjustScale(Int64(PShort(FXSQLVAR^.sqldata)^),
                              FXSQLVAR^.sqlscale);
      SQL_LONG:
        result := AdjustScale(Int64(PLong(FXSQLVAR^.sqldata)^),
                              FXSQLVAR^.sqlscale);
      SQL_INT64:
        result := AdjustScale(PInt64(FXSQLVAR^.sqldata)^, FXSQLVAR^.sqlscale);
      SQL_FLOAT:
        result := PFloat(FXSQLVAR^.sqldata)^;
      SQL_DOUBLE, SQL_D_FLOAT:
        result := PDouble(FXSQLVAR^.sqldata)^;
      else
        IBError(ibxeInvalidDataConversion, [nil]);
    end;
    if  FXSQLVAR^.sqlscale <> 0 then
      result :=
        StrToFloat(FloatToStrF(result, fffixed, 15,
                  Abs(FXSQLVAR^.sqlscale) ));
  end;
end;

function TIBXSQLVAR.GetAsFloat: Float;
begin
  result := 0;
  try
    result := AsDouble;
  except
    on E: SysUtils.EOverflow do
      IBError(ibxeInvalidDataConversion, [nil]);
  end;
end;

function TIBXSQLVAR.GetAsLong: Long;
begin
  result := 0;
  if not IsNull then
    case FXSQLVAR^.sqltype and (not 1) of
      SQL_TEXT, SQL_VARYING: begin
        try
          result := StrToInt(AsString);
        except
          on E: Exception do IBError(ibxeInvalidDataConversion, [nil]);
        end;
      end;
      SQL_SHORT:
        result := Trunc(AdjustScale(Int64(PShort(FXSQLVAR^.sqldata)^),
                                    FXSQLVAR^.sqlscale));
      SQL_LONG:
        result := Trunc(AdjustScale(Int64(PLong(FXSQLVAR^.sqldata)^),
                                    FXSQLVAR^.sqlscale));
      SQL_INT64:
        result := Trunc(AdjustScale(PInt64(FXSQLVAR^.sqldata)^, FXSQLVAR^.sqlscale));
      SQL_DOUBLE, SQL_FLOAT, SQL_D_FLOAT:
        result := Trunc(AsDouble);
      else
        IBError(ibxeInvalidDataConversion, [nil]);
    end;
end;

function TIBXSQLVAR.GetAsPointer: Pointer;
begin
  if not IsNull then
    result := FXSQLVAR^.sqldata
  else
    result := nil;
end;

function TIBXSQLVAR.GetAsQuad: TISC_QUAD;
begin
  result.gds_quad_high := 0;
  result.gds_quad_low := 0;
  if not IsNull then
    case FXSQLVAR^.sqltype and (not 1) of
      SQL_BLOB, SQL_ARRAY, SQL_QUAD:
        result := PISC_QUAD(FXSQLVAR^.sqldata)^;
      else
        IBError(ibxeInvalidDataConversion, [nil]);
    end;
end;

function TIBXSQLVAR.GetAsShort: Short;
begin
  result := 0;
  try
    result := AsLong;
  except
    on E: Exception do IBError(ibxeInvalidDataConversion, [nil]);
  end;
end;

function TIBXSQLVAR.GetAsString: String;
var
  sz: PChar;
  str_len: Integer;
  ss: TStringStream;
begin
  result := '';
  { Check null, if so return a default string }
  if not IsNull then
    case FXSQLVar^.sqltype and (not 1) of
      SQL_ARRAY:
        result := '(Array)'; {do not localize}
      SQL_BLOB: begin
        ss := TStringStream.Create('');
        try
          SaveToStream(ss);
          result := ss.DataString;
        finally
          ss.Free;
        end;
      end;
      SQL_TEXT, SQL_VARYING: begin
        sz := FXSQLVAR^.sqldata;
        if (FXSQLVar^.sqltype and (not 1) = SQL_TEXT) then
          str_len := FXSQLVar^.sqllen
        else
        begin
          str_len := isc_vax_integer(FXSQLVar^.sqldata, 2);
          Inc(sz, 2);
        end;
        SetString(result, sz, str_len);
      end;
      SQL_TYPE_DATE:
        case FSQL.Database.SQLDialect of
          1 : result := DateTimeToStr(AsDateTime);
          3 : result := DateToStr(AsDateTime);
        end;
      SQL_TYPE_TIME :
        result := TimeToStr(AsDateTime);
      SQL_TIMESTAMP:
        result := DateTimeToStr(AsDateTime);
      SQL_SHORT, SQL_LONG:
        if FXSQLVAR^.sqlscale = 0 then
          result := IntToStr(AsLong)
        else if FXSQLVAR^.sqlscale >= (-4) then
          result := CurrToStr(AsCurrency)
        else
          result := FloatToStr(AsDouble);
      SQL_INT64:
        if FXSQLVAR^.sqlscale = 0 then
          result := IntToStr(AsInt64)
        else if FXSQLVAR^.sqlscale >= (-4) then
          result := CurrToStr(AsCurrency)
        else
          result := FloatToStr(AsDouble);
      SQL_DOUBLE, SQL_FLOAT, SQL_D_FLOAT:
        result := FloatToStr(AsDouble);
      else
        IBError(ibxeInvalidDataConversion, [nil]);
    end;
end;

function TIBXSQLVAR.GetAsVariant: Variant;
begin
  if IsNull then
    result := NULL
  { Check null, if so return a default string }
  else case FXSQLVar^.sqltype and (not 1) of
      SQL_ARRAY:
        result := '(Array)'; {do not localize}
      SQL_BLOB:
        result := '(Blob)'; {do not localize}
      SQL_TEXT, SQL_VARYING:
        result := AsString;
      SQL_TIMESTAMP, SQL_TYPE_DATE, SQL_TYPE_TIME:
        result := AsDateTime;
      SQL_SHORT, SQL_LONG:
        if FXSQLVAR^.sqlscale = 0 then
          result := AsLong
        else if FXSQLVAR^.sqlscale >= (-4) then
          result := AsCurrency
        else
          result := AsDouble;
      SQL_INT64:
        if FXSQLVAR^.sqlscale = 0 then
          IBError(ibxeInvalidDataConversion, [nil])
        else if FXSQLVAR^.sqlscale >= (-4) then
          result := AsCurrency
        else
          result := AsDouble;
      SQL_DOUBLE, SQL_FLOAT, SQL_D_FLOAT:
        result := AsDouble;
      else
        IBError(ibxeInvalidDataConversion, [nil]);
    end;
end;

function TIBXSQLVAR.GetAsXSQLVAR: PXSQLVAR;
begin
  result := FXSQLVAR;
end;

function TIBXSQLVAR.GetIsNull: Boolean;
begin
  result := IsNullable and (FXSQLVAR^.sqlind^ = -1);
end;

function TIBXSQLVAR.GetIsNullable: Boolean;
begin
  result := (FXSQLVAR^.sqltype and 1 = 1);
end;

procedure TIBXSQLVAR.LoadFromFile(const FileName: String);
var
  fs: TFileStream;
begin
  fs := TFileStream.Create(FileName, fmOpenRead or fmShareDenyWrite);
  try
    LoadFromStream(fs);
  finally
    fs.Free;
  end;
end;

procedure TIBXSQLVAR.LoadFromStream(Stream: TStream);
var
  bs: TIBBlobStream;
begin
  bs := TIBBlobStream.Create;
  try
    bs.Mode := bmWrite;
    bs.Database := FSQL.Database;
    bs.Transaction := FSQL.Transaction;
    Stream.Seek(0, soFromBeginning);
    bs.LoadFromStream(Stream);
    bs.Finalize;
    AsQuad := bs.BlobID;
  finally
    bs.Free;
  end;
end;

procedure TIBXSQLVAR.SaveToFile(const FileName: String);
var
  fs: TFileStream;
begin
  fs := TFileStream.Create(FileName, fmCreate or fmShareExclusive);
  try
    SaveToStream(fs);
  finally
    fs.Free;
  end;
end;

procedure TIBXSQLVAR.SaveToStream(Stream: TStream);
var
  bs: TIBBlobStream;
begin
  bs := TIBBlobStream.Create;
  try
    bs.Mode := bmRead;
    bs.Database := FSQL.Database;
    bs.Transaction := FSQL.Transaction;
    bs.BlobID := AsQuad;
    bs.SaveToStream(Stream);
  finally
    bs.Free;
  end;
end;

function TIBXSQLVAR.GetSize: Integer;
begin
  result := FXSQLVAR^.sqllen;
end;

function TIBXSQLVAR.GetSQLType: Integer;
begin
  result := FXSQLVAR^.sqltype and (not 1);
end;

procedure TIBXSQLVAR.SetAsCurrency(Value: Currency);
var
  xvar: TIBXSQLVAR;
  i: Integer;
begin
  if FSQL.Database.SQLDialect < 3 then
    AsDouble := Value
  else
  begin
    if IsNullable then
      IsNull := False;
    for i := 0 to FParent.FCount - 1 do
      if FParent.FNames[i] = FName then
      begin
        xvar := FParent[i];
        xvar.FXSQLVAR^.sqltype := SQL_INT64 or (xvar.FXSQLVAR^.sqltype and 1);
        xvar.FXSQLVAR^.sqlscale := -4;
        xvar.FXSQLVAR^.sqllen := SizeOf(Int64);
        IBAlloc(xvar.FXSQLVAR^.sqldata, 0, xvar.FXSQLVAR^.sqllen);
        PCurrency(xvar.FXSQLVAR^.sqldata)^ := Value;
        xvar.FModified := True;
      end;
  end;
end;

procedure TIBXSQLVAR.SetAsInt64(Value: Int64);
var
  i: Integer;
  xvar: TIBXSQLVAR;
begin
  if IsNullable then
    IsNull := False;
  for i := 0 to FParent.FCount - 1 do
    if FParent.FNames[i] = FName then
    begin
      xvar := FParent[i];
      xvar.FXSQLVAR^.sqltype := SQL_INT64 or (xvar.FXSQLVAR^.sqltype and 1);
      xvar.FXSQLVAR^.sqlscale := 0;
      xvar.FXSQLVAR^.sqllen := SizeOf(Int64);
      IBAlloc(xvar.FXSQLVAR^.sqldata, 0, xvar.FXSQLVAR^.sqllen);
      PInt64(xvar.FXSQLVAR^.sqldata)^ := Value;
      xvar.FModified := True;
    end;
end;

procedure TIBXSQLVAR.SetAsDate(Value: TDateTime);
var
  i: Integer;
  tm_date: TCTimeStructure;
  Yr, Mn, Dy: Word;
  xvar: TIBXSQLVAR;
begin
  if FSQL.Database.SQLDialect < 3 then
  begin
    AsDateTime := Value;
    exit;
  end;
  if IsNullable then
    IsNull := False;
  for i := 0 to FParent.FCount - 1 do
    if FParent.FNames[i] = FName then
    begin
      xvar := FParent[i];
      xvar.FXSQLVAR^.sqltype := SQL_TYPE_DATE or (xvar.FXSQLVAR^.sqltype and 1);
      DecodeDate(Value, Yr, Mn, Dy);
      with tm_date do begin
        tm_sec := 0;
        tm_min := 0;
        tm_hour := 0;
        tm_mday := Dy;
        tm_mon := Mn - 1;
        tm_year := Yr - 1900;
      end;
      xvar.FXSQLVAR^.sqllen := SizeOf(ISC_DATE);
      IBAlloc(xvar.FXSQLVAR^.sqldata, 0, xvar.FXSQLVAR^.sqllen);
      isc_encode_sql_date(@tm_date, PISC_DATE(xvar.FXSQLVAR^.sqldata));
      xvar.FModified := True;
    end;
end;

procedure TIBXSQLVAR.SetAsTime(Value: TDateTime);
var
  i: Integer;
  tm_date: TCTimeStructure;
  Hr, Mt, S, Ms: Word;
  xvar: TIBXSQLVAR;
begin
  if FSQL.Database.SQLDialect < 3 then
  begin
    AsDateTime := Value;
    exit;
  end;
  if IsNullable then
    IsNull := False;
  for i := 0 to FParent.FCount - 1 do
    if FParent.FNames[i] = FName then
    begin
      xvar := FParent[i];
      xvar.FXSQLVAR^.sqltype := SQL_TYPE_TIME or (xvar.FXSQLVAR^.sqltype and 1);
      DecodeTime(Value, Hr, Mt, S, Ms);
      with tm_date do begin
        tm_sec := S;
        tm_min := Mt;
        tm_hour := Hr;
        tm_mday := 0;
        tm_mon := 0;
        tm_year := 0;
      end;
      xvar.FXSQLVAR^.sqllen := SizeOf(ISC_TIME);
      IBAlloc(xvar.FXSQLVAR^.sqldata, 0, xvar.FXSQLVAR^.sqllen);
      isc_encode_sql_time(@tm_date, PISC_TIME(xvar.FXSQLVAR^.sqldata));
      xvar.FModified := True;
    end;
end;

procedure TIBXSQLVAR.SetAsDateTime(Value: TDateTime);
var
  i: Integer;
  tm_date: TCTimeStructure;
  Yr, Mn, Dy, Hr, Mt, S, Ms: Word;
  xvar: TIBXSQLVAR;
begin
  if IsNullable then
    IsNull := False;
  for i := 0 to FParent.FCount - 1 do
    if FParent.FNames[i] = FName then
    begin
      xvar := FParent[i];
      xvar.FXSQLVAR^.sqltype := SQL_TIMESTAMP or (xvar.FXSQLVAR^.sqltype and 1);
      DecodeDate(Value, Yr, Mn, Dy);
      DecodeTime(Value, Hr, Mt, S, Ms);
      with tm_date do begin
        tm_sec := S;
        tm_min := Mt;
        tm_hour := Hr;
        tm_mday := Dy;
        tm_mon := Mn - 1;
        tm_year := Yr - 1900;
      end;
      xvar.FXSQLVAR^.sqllen := SizeOf(TISC_QUAD);
      IBAlloc(xvar.FXSQLVAR^.sqldata, 0, xvar.FXSQLVAR^.sqllen);
      isc_encode_date(@tm_date, PISC_QUAD(xvar.FXSQLVAR^.sqldata));
      xvar.FModified := True;
    end;
end;

procedure TIBXSQLVAR.SetAsDouble(Value: Double);
var
  i: Integer;
  xvar: TIBXSQLVAR;
begin
  if IsNullable then
    IsNull := False;
  for i := 0 to FParent.FCount - 1 do
    if FParent.FNames[i] = FName then
    begin
      xvar := FParent[i];
      xvar.FXSQLVAR^.sqltype := SQL_DOUBLE or (xvar.FXSQLVAR^.sqltype and 1);
      xvar.FXSQLVAR^.sqllen := SizeOf(Double);
      xvar.FXSQLVAR^.sqlscale := 0;
      IBAlloc(xvar.FXSQLVAR^.sqldata, 0, xvar.FXSQLVAR^.sqllen);
      PDouble(xvar.FXSQLVAR^.sqldata)^ := Value;
      xvar.FModified := True;
    end;
end;

procedure TIBXSQLVAR.SetAsFloat(Value: Float);
var
  i: Integer;
  xvar: TIBXSQLVAR;
begin
  if IsNullable then
    IsNull := False;
  for i := 0 to FParent.FCount - 1 do
    if FParent.FNames[i] = FName then
    begin
      xvar := FParent[i];
      xvar.FXSQLVAR^.sqltype := SQL_FLOAT or (xvar.FXSQLVAR^.sqltype and 1);
      xvar.FXSQLVAR^.sqllen := SizeOf(Float);
      xvar.FXSQLVAR^.sqlscale := 0;
      IBAlloc(xvar.FXSQLVAR^.sqldata, 0, xvar.FXSQLVAR^.sqllen);
      PSingle(xvar.FXSQLVAR^.sqldata)^ := Value;
      xvar.FModified := True;
    end;
end;

procedure TIBXSQLVAR.SetAsLong(Value: Long);
var
  i: Integer;
  xvar: TIBXSQLVAR;
begin
  if IsNullable then
    IsNull := False;
  for i := 0 to FParent.FCount - 1 do
    if FParent.FNames[i] = FName then
    begin
      xvar := FParent[i];
      xvar.FXSQLVAR^.sqltype := SQL_LONG or (xvar.FXSQLVAR^.sqltype and 1);
      xvar.FXSQLVAR^.sqllen := SizeOf(Long);
      xvar.FXSQLVAR^.sqlscale := 0;
      IBAlloc(xvar.FXSQLVAR^.sqldata, 0, xvar.FXSQLVAR^.sqllen);
      PLong(xvar.FXSQLVAR^.sqldata)^ := Value;
      xvar.FModified := True;
    end;
end;

procedure TIBXSQLVAR.SetAsPointer(Value: Pointer);
var
  i: Integer;
  xvar: TIBXSQLVAR;
begin
  if IsNullable and (Value = nil) then
    IsNull := True
  else begin
    IsNull := False;
    for i := 0 to FParent.FCount - 1 do
      if FParent.FNames[i] = FName then
      begin
        xvar := FParent[i];
        xvar.FXSQLVAR^.sqltype := SQL_TEXT or (FXSQLVAR^.sqltype and 1);
        Move(Value^, xvar.FXSQLVAR^.sqldata^, xvar.FXSQLVAR^.sqllen);
        xvar.FModified := True;
      end;
  end;
end;

procedure TIBXSQLVAR.SetAsQuad(Value: TISC_QUAD);
var
  i: Integer;
  xvar: TIBXSQLVAR;
begin
  if IsNullable then
    IsNull := False;
  for i := 0 to FParent.FCount - 1 do
    if FParent.FNames[i] = FName then
    begin
      xvar := FParent[i];
      if (xvar.FXSQLVAR^.sqltype and (not 1) <> SQL_BLOB) and
         (xvar.FXSQLVAR^.sqltype and (not 1) <> SQL_ARRAY) then
        IBError(ibxeInvalidDataConversion, [nil]);
      xvar.FXSQLVAR^.sqllen := SizeOf(TISC_QUAD);
      IBAlloc(xvar.FXSQLVAR^.sqldata, 0, xvar.FXSQLVAR^.sqllen);
      PISC_QUAD(xvar.FXSQLVAR^.sqldata)^ := Value;
      xvar.FModified := True;
    end;
end;

procedure TIBXSQLVAR.SetAsShort(Value: Short);
var
  i: Integer;
  xvar: TIBXSQLVAR;
begin
  if IsNullable then
    IsNull := False;
  for i := 0 to FParent.FCount - 1 do
    if FParent.FNames[i] = FName then
    begin
      xvar := FParent[i];
      xvar.FXSQLVAR^.sqltype := SQL_SHORT or (xvar.FXSQLVAR^.sqltype and 1);
      xvar.FXSQLVAR^.sqllen := SizeOf(Short);
      xvar.FXSQLVAR^.sqlscale := 0;
      IBAlloc(xvar.FXSQLVAR^.sqldata, 0, xvar.FXSQLVAR^.sqllen);
      PShort(xvar.FXSQLVAR^.sqldata)^ := Value;
      xvar.FModified := True;
    end;
end;

procedure TIBXSQLVAR.SetAsString(Value: String);
var
  stype: Integer;
  ss: TStringStream;

  procedure SetStringValue;
  var
    i: Integer;
    xvar: TIBXSQLVAR;
  begin
    for i := 0 to FParent.FCount - 1 do
      if FParent.FNames[i] = FName then
      begin
        xvar := FParent[i];
        if (xvar.FXSQLVAR^.sqlname = 'DB_KEY') or {do not localize}
           (xvar.FXSQLVAR^.sqlname = 'RDB$DB_KEY') then {do not localize}
          Move(Value[1], xvar.FXSQLVAR^.sqldata^, xvar.FXSQLVAR^.sqllen)
        else
        begin
          xvar.FXSQLVAR^.sqltype := SQL_TEXT or (FXSQLVAR^.sqltype and 1);
          if (FMaxLen > 0) and (Length(Value) > FMaxLen) then
            IBError(ibxeStringTooLarge, [Length(Value), FMaxLen]);
          xvar.FXSQLVAR^.sqllen := Length(Value);
          IBAlloc(xvar.FXSQLVAR^.sqldata, 0, xvar.FXSQLVAR^.sqllen + 1);
          if (Length(Value) > 0) then
            Move(Value[1], xvar.FXSQLVAR^.sqldata^, xvar.FXSQLVAR^.sqllen);
        end;
        xvar.FModified := True;
      end;
  end;

begin
  if IsNullable then
    IsNull := False;
  stype := FXSQLVAR^.sqltype and (not 1);
  if (stype = SQL_TEXT) or (stype = SQL_VARYING) then
    SetStringValue
  else
  begin
    if (stype = SQL_BLOB) then
    begin
      ss := TStringStream.Create(Value);
      try
        LoadFromStream(ss);
      finally
        ss.Free;
      end;
    end
    else
      if Value = '' then
        IsNull := True
      else
        if (stype = SQL_TIMESTAMP) or (stype = SQL_TYPE_DATE) or
          (stype = SQL_TYPE_TIME) then
          SetAsDateTime(StrToDateTime(Value))
        else
          SetStringValue;
  end;
end;

procedure TIBXSQLVAR.SetAsVariant(Value: Variant);
begin
  if VarIsNull(Value) then
    IsNull := True
  else
  case VarType(Value) of
    varEmpty, varNull:
      IsNull := True;
    varSmallint, varInteger, varByte:
      AsLong := Value;
    varSingle, varDouble:
      AsDouble := Value;
    varCurrency:
      AsCurrency := Value;
    varBoolean:
      if Value then
        AsLong := ISC_TRUE
      else
        AsLong := ISC_FALSE;
    varDate:
      AsDateTime := Value;
    varOleStr, varString:
      AsString := Value;
    varArray:
      IBError(ibxeNotSupported, [nil]);
    varByRef, varDispatch, varError, varUnknown, varVariant:
      IBError(ibxeNotPermitted, [nil]);
  end;
end;

procedure TIBXSQLVAR.SetAsXSQLVAR(Value: PXSQLVAR);
var
  i: Integer;
  xvar: TIBXSQLVAR;
  sqlind: PShort;
  sqldata: PChar;
  local_sqllen: Integer;
begin
  for i := 0 to FParent.FCount - 1 do
    if FParent.FNames[i] = FName then
    begin
      xvar := FParent[i];
      sqlind := xvar.FXSQLVAR^.sqlind;
      sqldata := xvar.FXSQLVAR^.sqldata;
      Move(Value^, xvar.FXSQLVAR^, SizeOf(TXSQLVAR));
      xvar.FXSQLVAR^.sqlind := sqlind;
      xvar.FXSQLVAR^.sqldata := sqldata;
      if (Value^.sqltype and 1 = 1) then
      begin
        if (xvar.FXSQLVAR^.sqlind = nil) then
          IBAlloc(xvar.FXSQLVAR^.sqlind, 0, SizeOf(Short));
        xvar.FXSQLVAR^.sqlind^ := Value^.sqlind^;
      end
      else
        if (xvar.FXSQLVAR^.sqlind <> nil) then
          ReallocMem(xvar.FXSQLVAR^.sqlind, 0);
      if ((xvar.FXSQLVAR^.sqltype and (not 1)) = SQL_VARYING) then
        local_sqllen := xvar.FXSQLVAR^.sqllen + 2
      else
        local_sqllen := xvar.FXSQLVAR^.sqllen;
      FXSQLVAR^.sqlscale := Value^.sqlscale;
      IBAlloc(xvar.FXSQLVAR^.sqldata, 0, local_sqllen);
      Move(Value^.sqldata[0], xvar.FXSQLVAR^.sqldata[0], local_sqllen);
      xvar.FModified := True;
    end;
end;

procedure TIBXSQLVAR.SetIsNull(Value: Boolean);
var
  i: Integer;
  xvar: TIBXSQLVAR;
begin
  if Value then
  begin
    if not IsNullable then
      IsNullable := True;
    for i := 0 to FParent.FCount - 1 do
      if FParent.FNames[i] = FName then
      begin
        xvar := FParent[i];
        if Assigned(xvar.FXSQLVAR^.sqlind) then
          xvar.FXSQLVAR^.sqlind^ := -1;
        xvar.FModified := True;
      end;
  end
  else
    if ((not Value) and IsNullable) then
    begin
      for i := 0 to FParent.FCount - 1 do
        if FParent.FNames[i] = FName then
        begin
          xvar := FParent[i];
          if Assigned(xvar.FXSQLVAR^.sqlind) then
            xvar.FXSQLVAR^.sqlind^ := 0;
          xvar.FModified := True;
        end;
    end;
end;

procedure TIBXSQLVAR.SetIsNullable(Value: Boolean);
var
  i: Integer;
  xvar: TIBXSQLVAR;
begin
  for i := 0 to FParent.FCount - 1 do
    if FParent.FNames[i] = FName then
    begin
      xvar := FParent[i];
      if (Value <> IsNullable) then
      begin
        if Value then
        begin
          xvar.FXSQLVAR^.sqltype := xvar.FXSQLVAR^.sqltype or 1;
          IBAlloc(xvar.FXSQLVAR^.sqlind, 0, SizeOf(Short));
        end
        else
        begin
          xvar.FXSQLVAR^.sqltype := xvar.FXSQLVAR^.sqltype and (not 1);
          ReallocMem(xvar.FXSQLVAR^.sqlind, 0);
        end;
      end;
    end;
end;

procedure TIBXSQLVAR.Clear;
begin
  IsNull := true;
end;

procedure TIBXSQLVAR.SetAsTrimString(const Value: String);
begin
  SetAsString(TrimRight(Value));
end;

function TIBXSQLVAR.GetAsTrimString: String;
begin
  Result := TrimRight(GetAsString);
end;

{ TIBXSQLDA }
constructor TIBXSQLDA.Create(Query: TIBSQL);
begin
  inherited Create;
  FSQL := Query;
  FNames := TStringList.Create;
  FSize := 0;
  FUniqueRelationName := '';
end;

destructor TIBXSQLDA.Destroy;
var
  i: Integer;
begin
  FNames.Free;
  if FXSQLDA <> nil then
  begin
    for i := 0 to FSize - 1 do
    begin
      FreeMem(FXSQLVARs[i].FXSQLVAR^.sqldata);
      FreeMem(FXSQLVARs[i].FXSQLVAR^.sqlind);
      FXSQLVARs[i].Free ;
    end;
    FreeMem(FXSQLDA);
    FXSQLDA := nil;
    FXSQLVARs := nil;
  end;
  inherited Destroy;
end;

procedure TIBXSQLDA.AddName(FieldName: String; Idx: Integer);
var
  fn: String;
begin
  fn := FormatIdentifierValue(FSQL.Database.SQLDialect, FieldName);
  while FNames.Count <= Idx do
    FNames.Add('');
  FNames[Idx] := fn;
  FXSQLVARs[Idx].FName := fn;
  FXSQLVARs[Idx].FIndex := Idx;
end;

function TIBXSQLDA.GetModified: Boolean;
var
  i: Integer;
begin
  result := False;
  for i := 0 to FCount - 1 do
    if FXSQLVARs[i].Modified then
    begin
      result := True;
      exit;
    end;
end;

function TIBXSQLDA.GetNames: String;
begin
  result := FNames.Text;
end;

function TIBXSQLDA.GetRecordSize: Integer;
begin
  result := SizeOf(TIBXSQLDA) + XSQLDA_LENGTH(FSize);
end;

function TIBXSQLDA.GetXSQLDA: PXSQLDA;
begin
  result := FXSQLDA;
end;

function TIBXSQLDA.GetXSQLVAR(Idx: Integer): TIBXSQLVAR;
begin
  if (Idx < 0) or (Idx >= FCount) then
    IBError(ibxeXSQLDAIndexOutOfRange, [nil]);
  result := FXSQLVARs[Idx]
end;

function TIBXSQLDA.ByName(Idx: String): TIBXSQLVAR;
begin
  result := GetXSQLVARByName(Idx);
  if result = nil then
    IBError(ibxeFieldNotFound, [Idx]);
end;

function TIBXSQLDA.GetXSQLVARByName(Idx: String): TIBXSQLVAR;
var
  s: String;
  i, Cnt: Integer;
begin
  s := FormatIdentifierValue(FSQL.Database.SQLDialect, Idx);
  i := 0;
  Cnt := FNames.Count;
  while (i < Cnt) and (FNames[i] <> s) do Inc(i);
  if i = Cnt then
    result := nil
  else
    result := GetXSQLVAR(i);
end;

procedure TIBXSQLDA.Initialize;
var
  i, j, j_len: Integer;
  NamesWereEmpty: Boolean;
  st: String;
  bUnique: Boolean;
begin
  bUnique := True;
  NamesWereEmpty := (FNames.Count = 0);
  if FXSQLDA <> nil then
  begin
    for i := 0 to FCount - 1 do
    begin
      with FXSQLVARs[i].Data^ do
      begin
        if bUnique and (String(relname) <> '') then
        begin
          if FUniqueRelationName = '' then
            FUniqueRelationName := String(relname)
          else
            if String(relname) <> FUniqueRelationName then
            begin
              FUniqueRelationName := '';
              bUnique := False;
            end;
        end;
        if NamesWereEmpty then
        begin
          st := String(aliasname);
          if st = '' then
          begin
            st := 'F_'; {do not localize}
            aliasname_length := 2;
            j := 1; j_len := 1;
            StrPCopy(aliasname, st + IntToStr(j));
          end
          else
          begin
            StrPCopy(aliasname, st);
            j := 0; j_len := 0;
          end;
          while GetXSQLVARByName(String(aliasname)) <> nil do
          begin
            Inc(j); j_len := Length(IntToStr(j));
            if j_len + aliasname_length > 31 then
              StrPCopy(aliasname,
                       Copy(st, 1, 31 - j_len) +
                       IntToStr(j))
            else
              StrPCopy(aliasname, st + IntToStr(j));
          end;
          Inc(aliasname_length, j_len);
          AddName(String(aliasname), i);
        end;
        if (sqltype and (not 1) = SQL_TEXT) or
           (sqltype and (not 1) = SQL_VARYING) then
          FXSQLVARs[i].FMaxLen := sqllen
        else
          FXSQLVARs[i].FMaxLen := 0;
        case sqltype and (not 1) of
          SQL_TEXT, SQL_TYPE_DATE, SQL_TYPE_TIME, SQL_TIMESTAMP,
          SQL_BLOB, SQL_ARRAY, SQL_QUAD, SQL_SHORT,
          SQL_LONG, SQL_INT64, SQL_DOUBLE, SQL_FLOAT, SQL_D_FLOAT:
          begin
            if (sqllen = 0) then
              { Make sure you get a valid pointer anyway
               select '' from foo }
              IBAlloc(sqldata, 0, 1)
            else
              IBAlloc(sqldata, 0, sqllen)
          end;
          SQL_VARYING:
          begin
            IBAlloc(sqldata, 0, sqllen + 2);
          end;
          else
            IBError(ibxeUnknownSQLDataType, [sqltype and (not 1)])
        end;
        if (sqltype and 1 = 1) then
          IBAlloc(sqlind, 0, SizeOf(Short))
        else
          if (sqlind <> nil) then
            ReallocMem(sqlind, 0);
      end;
    end;
  end;
end;

procedure TIBXSQLDA.SetCount(Value: Integer);
var
  i, OldSize: Integer;
  p : PXSQLVAR;
begin
  FNames.Clear;
  FCount := Value;
  if FCount = 0 then
    FUniqueRelationName := ''
  else
  begin
    if FSize > 0 then
      OldSize := XSQLDA_LENGTH(FSize)
    else
      OldSize := 0;
    if FCount > FSize then
    begin
      IBAlloc(FXSQLDA, OldSize, XSQLDA_LENGTH(FCount));
      SetLength(FXSQLVARs, FCount);
      FXSQLDA^.version := SQLDA_VERSION1;
      p := @FXSQLDA^.sqlvar[0];
      for i := 0 to FCount - 1 do
      begin
        if i >= FSize then
          FXSQLVARs[i] := TIBXSQLVAR.Create(self, FSQL);
        FXSQLVARs[i].FXSQLVAR := p;
        p := Pointer(PChar(p) + sizeof(FXSQLDA^.sqlvar));
      end;
      FSize := FCount;
    end;
    if FSize > 0 then
    begin
      FXSQLDA^.sqln := Value;
      FXSQLDA^.sqld := Value;
    end;
  end;
end;

{ TIBOutputDelimitedFile }

destructor TIBOutputDelimitedFile.Destroy;
begin
  FFile.Free;
  inherited Destroy;
end;

procedure TIBOutputDelimitedFile.ReadyFile;
var
  i: Integer;
  st: string;
begin
  if FColDelimiter = '' then
    FColDelimiter := TAB;
  if FRowDelimiter = '' then
    FRowDelimiter := CRLF;
  FFile := TFileStream.Create(FFilename, fmCreate or fmShareDenyWrite);
  if FOutputTitles then
  begin
    for i := 0 to Columns.Count - 1 do
      if i = 0 then
        st := string(Columns[i].Data^.aliasname)
      else
        st := st + FColDelimiter + string(Columns[i].Data^.aliasname);
    st := st + FRowDelimiter;
    FFile.Write(st[1], Length(st));
  end;
end;

function TIBOutputDelimitedFile.WriteColumns: Boolean;
var
  i: Integer;
  BytesWritten: DWORD;
  st: string;
begin
  result := False;
  if Assigned(FFile) then
  begin
    st := '';
    for i := 0 to Columns.Count - 1 do
    begin
      if i > 0 then
        st := st + FColDelimiter;
      st := st + StripString(Columns[i].AsString, FColDelimiter + FRowDelimiter);
    end;
    st := st + FRowDelimiter;
    BytesWritten := FFile.Write(st[1], Length(st));
    if BytesWritten = DWORD(Length(st)) then
      result := True;
  end
end;

 { TIBInputDelimitedFile }

destructor TIBInputDelimitedFile.Destroy;
begin
  FFile.Free;
  inherited Destroy;
end;

function TIBInputDelimitedFile.GetColumn(var Col: string): Integer;
var
  c: Char;
  BytesRead: Integer;

  procedure ReadInput;
  begin
    if FLookAhead <> NULL_TERMINATOR then
    begin
      c := FLookAhead;
      BytesRead := 1;
      FLookAhead := NULL_TERMINATOR;
    end else
      BytesRead := FFile.Read(c, 1);
  end;

  procedure CheckCRLF(Delimiter: string);
  begin
    if (c = CR) and (Pos(LF, Delimiter) > 0) then {mbcs ok}
    begin
      BytesRead := FFile.Read(c, 1);
      if (BytesRead = 1) and (c <> #10) then
        FLookAhead := c
    end;
  end;

begin
  Col := '';
  result := 0;
  ReadInput;
  while BytesRead <> 0 do begin
    if Pos(c, FColDelimiter) > 0 then {mbcs ok}
    begin
      CheckCRLF(FColDelimiter);
      result := 1;
      break;
    end else if Pos(c, FRowDelimiter) > 0 then {mbcs ok}
    begin
      CheckCRLF(FRowDelimiter);
      result := 2;
      break;
    end else
      Col := Col + c;
    ReadInput;
  end;
end;

function TIBInputDelimitedFile.ReadParameters: Boolean;
var
  i, curcol: Integer;
  Col: string;
begin
  result := False;
  if not FEOF then
  begin
    curcol := 0;
    repeat
      i := GetColumn(Col);
      if (i = 0) then
        FEOF := True;
      if (curcol < Params.Count) then
      begin
        try
          if (Col = '') and
             (ReadBlanksAsNull) then
            Params[curcol].IsNull := True
          else
            Params[curcol].AsString := Col;
          Inc(curcol);
        except
          on E: Exception do
          begin
            if not (FEOF and (curcol = Params.Count)) then
              raise;
          end;
        end;
      end;
    until (FEOF) or (i = 2);
    result := ((FEOF) and (curcol = Params.Count)) or
              (not FEOF);
  end;
end;

procedure TIBInputDelimitedFile.ReadyFile;
var
  col : String;
  curcol : Integer;
begin
  if FColDelimiter = '' then
    FColDelimiter := TAB;
  if FRowDelimiter = '' then
    FRowDelimiter := CRLF;
  FLookAhead := NULL_TERMINATOR;
  FEOF := False;
  if FFile <> nil then
    FFile.Free;
  FFile := TFileStream.Create(FFilename, fmOpenRead or fmShareDenyWrite);
  if FSkipTitles then
  begin
    curcol := 0;
    while curcol < Params.Count do
    begin
      GetColumn(Col);
      Inc(CurCol)
    end;
  end;
end;

{ TIBOutputRawFile }
destructor TIBOutputRawFile.Destroy;
begin
  FFile.Free;
  inherited Destroy;
end;

procedure TIBOutputRawFile.ReadyFile;
begin
  if Assigned(FFile) then
    FreeAndNil(FFile);
  FFile := TFileStream.Create(Filename, fmCreate);
end;

function TIBOutputRawFile.WriteColumns: Boolean;
var
  i: Integer;
  BytesWritten, BytesToWrite : LongInt;
  SQLVar : PXSQLVAR;
  bs : TMemoryStream;
begin
  result := False;
  if Assigned(FFile) then
  begin
    for i := 0 to Columns.Count - 1 do
    begin
      SQLVar := Columns[i].Data;
      case SQLVar^.sqltype and (not 1) of
        SQL_VARYING:
        begin
          BytesToWrite := SQLVar^.sqllen + 2;
          BytesWritten := FFile.Write(SQLVar^.sqldata^, BytesToWrite);
          if (BytesWritten <> BytesToWrite) then
            exit;
        end;
        SQL_BLOB:
        begin
          bs := TMemoryStream.Create;
          try
            Columns[i].SaveToStream(bs);
            BytesToWrite := bs.Size;
            FFile.Write(BytesToWrite, sizeof(BytesToWrite));
            BytesWritten := FFile.CopyFrom(bs, 0);
            if BytesWritten <> BytesToWrite then
            begin
              FreeAndNil(bs);
              exit;
            end;
          finally
            bs.Free;
          end;
        end;
        else
        begin
          BytesWritten := FFile.Write(SQLVar^.sqldata^, SQLVar^.sqllen);
          if BytesWritten <> SQLVar^.sqllen then
            exit;
        end;
      end;
      // Have to write out the nil indicator
      FFile.Write(SQLVar^.sqlind^, sizeof(SQLVar^.sqlind));
    end;
    result := True;
  end;
end;

{ TIBInputRawFile }
destructor TIBInputRawFile.Destroy;
begin
  FFile.Free;
  inherited Destroy;
end;

function TIBInputRawFile.ReadParameters: Boolean;
var
  i: Integer;
  BytesRead, BytesToRead : LongInt;
  SQLVar : PXSQLVAR;
  bs: TMemoryStream;
begin
  result := False;
  if Assigned(FFile) then
  begin
    for i := 0 to Params.Count - 1 do
    begin
      SQLVar := Params[i].Data;

      case SQLVar^.sqltype and (not 1) of
        SQL_VARYING:
        begin
          BytesToRead := SQLVar^.sqllen + 2;
          BytesRead := FFile.Read(SQLVar^.sqldata^, BytesToRead);
          if BytesRead <> BytesToRead then
            Exit;
        end;
        SQL_BLOB:
        begin
          bs := TMemoryStream.Create;
          try
            FFile.Read(BytesToRead, sizeof(BytesToRead));
            if BytesToRead = 0 then
              SQLVar^.sqlind^ := -1
            else
            begin
              BytesRead := bs.CopyFrom(FFile, BytesToRead);
              if BytesRead <> BytesToRead then
              begin
                FreeAndNil(bs);
                Exit;
              end;
              bs.Position := 0;
              Params[i].LoadFromStream(bs);
            end;
          finally
            bs.Free;
          end;
        end;
        else
        begin
          BytesRead := FFile.Read(SQLVar^.sqldata^, SQLVar^.sqllen);
          if BytesRead <> SQLVar^.sqllen then
            exit;
        end;
      end;
      // Have to read in the nil indicator
      FFile.Read(SQLVar^.sqlind^, sizeof(SQLVar^.sqlind));
    end;
    result := True;
  end;
end;

procedure TIBInputRawFile.ReadyFile;
begin
  if Assigned(FFile)  then
    FreeAndNil(FFile);
  FFile := TFileStream.Create(FileName, fmOpenRead);
end;

{ TIBSQL }
constructor TIBSQL.Create(AOwner: TComponent);
begin
  inherited Create(AOwner);
  FIBLoaded := False;
  CheckIBLoaded;
  FIBLoaded := True;
  FGenerateParamNames := False;
  FGoToFirstRecordOnExecute := True;
  FBase := TIBBase.Create(Self);
  FBase.BeforeDatabaseDisconnect := DoBeforeDatabaseDisconnect;
  FBase.BeforeTransactionEnd := BeforeTransactionEnd;
  FBOF := False;
  FEOF := False;
  FPrepared := False;
  FRecordCount := 0;
  FSQL := TStringList.Create;
  TStringList(FSQL).OnChanging := SQLChanging;
  FProcessedSQL := TStringList.Create;
  FHandle := nil;
  FSQLParams := TIBXSQLDA.Create(self);
  FSQLRecord := TIBXSQLDA.Create(self);
  FSQLType := SQLUnknown;
  FParamCheck := True;
  FCursor := Name + RandomString(8);
  if AOwner is TIBDatabase then
    Database := TIBDatabase(AOwner)
  else
    if AOwner is TIBTransaction then
      Transaction := TIBTransaction(AOwner);
end;

destructor TIBSQL.Destroy;
begin
  if FIBLoaded then
  begin
    if (FOpen) then
      Close;
    if (FHandle <> nil) then
      FreeHandle;
    FSQL.Free;
    FProcessedSQL.Free;
    FBase.Free;
    FSQLParams.Free;
    FSQLRecord.Free;
  end;
  inherited Destroy;
end;

procedure TIBSQL.BatchInput(InputObject: TIBBatchInput);
begin
  if not Prepared then
    Prepare;
  InputObject.Params := Self.FSQLParams;
  InputObject.ReadyFile;
  if FSQLType in [SQLInsert, SQLUpdate, SQLDelete, SQLExecProcedure] then
    while InputObject.ReadParameters do
      ExecQuery;
end;

procedure TIBSQL.BatchOutput(OutputObject: TIBBatchOutput);
begin
  CheckClosed;
  if not Prepared then
    Prepare;
  if FSQLType = SQLSelect then begin
    try
      ExecQuery;
      OutputObject.Columns := Self.FSQLRecord;
      OutputObject.ReadyFile;
      if not FGoToFirstRecordOnExecute then
        Next;
      while (not Eof) and (OutputObject.WriteColumns) do
        Next;
    finally
      Close;
    end;
  end;
end;

procedure TIBSQL.CheckClosed;
begin
  if FOpen then IBError(ibxeSQLOpen, [nil]);
end;

procedure TIBSQL.CheckOpen;
begin
  if not FOpen then IBError(ibxeSQLClosed, [nil]);
end;

procedure TIBSQL.CheckValidStatement;
begin
  FBase.CheckTransaction;
  if (FHandle = nil) then
    IBError(ibxeInvalidStatementHandle, [nil]);
end;

procedure TIBSQL.Close;
var
  isc_res: ISC_STATUS;
begin
  try
    if (FHandle <> nil) and (SQLType = SQLSelect) and FOpen then
    begin
      isc_res := Call(
                   isc_dsql_free_statement(StatusVector, @FHandle, DSQL_close),
                   False);
      if (StatusVector^ = 1) and (isc_res > 0) and
        not CheckStatusVector(
              [isc_bad_stmt_handle, isc_dsql_cursor_close_err]) then
        IBDatabaseError;
    end;
  finally
    FEOF := False;
    FBOF := False;
    FOpen := False;
    FRecordCount := 0;
  end;
end;

function TIBSQL.Call(ErrCode: ISC_STATUS; RaiseError: Boolean): ISC_STATUS;
begin
  result := 0;
 if Transaction <> nil then
    result := Transaction.Call(ErrCode, RaiseError)
  else
  if RaiseError and (ErrCode > 0) then
    IBDataBaseError;
end;

function TIBSQL.Current: TIBXSQLDA;
begin
  result := FSQLRecord;
end;

procedure TIBSQL.DoBeforeDatabaseDisconnect(Sender: TObject);
begin
  if (FHandle <> nil) then
  begin
    Close;
    FreeHandle;
  end;
end;

procedure TIBSQL.ExecQuery;
var
  fetch_res: ISC_STATUS;
begin
  CheckClosed;
  if not Prepared then
    Prepare;
  CheckValidStatement;
  case FSQLType of
    SQLSelect:
    begin
      Call(isc_dsql_execute2(StatusVector,
                            TRHandle,
                            @FHandle,
                            Database.SQLDialect,
                            FSQLParams.AsXSQLDA,
                            nil), True);
      Call(
        isc_dsql_set_cursor_name(StatusVector, @FHandle, PChar(FCursor), 0),
        True);
      FOpen := True;
      FBOF := True;
      FEOF := False;
      FRecordCount := 0;
      if FGoToFirstRecordOnExecute then
        Next;
    end;
    SQLExecProcedure:
    begin
      fetch_res := Call(isc_dsql_execute2(StatusVector,
                            TRHandle,
                            @FHandle,
                            Database.SQLDialect,
                            FSQLParams.AsXSQLDA,
                            FSQLRecord.AsXSQLDA), False);
      if (fetch_res <> 0) then
      begin
        if (fetch_res <> isc_lock_conflict) then
        begin
           { Sometimes a prepared stored procedure appears to get
             off sync on the server ....This code is meant to try
             to work around the problem simply by "retrying". This
             need to be reproduced and fixed.
           }
          isc_dsql_prepare(StatusVector, TRHandle, @FHandle, 0,
             PChar(FProcessedSQL.Text), Database.SQLDialect, nil);
          Call(isc_dsql_execute2(StatusVector,
                              TRHandle,
                              @FHandle,
                              Database.SQLDialect,
                              FSQLParams.AsXSQLDA,
                              FSQLRecord.AsXSQLDA), True);
        end
        else
          IBDataBaseError;  // go ahead and raise the lock conflict
      end;
    end
    else
      Call(isc_dsql_execute(StatusVector,
                           TRHandle,
                           @FHandle,
                           Database.SQLDialect,
                           FSQLParams.AsXSQLDA), True)
  end;
  if not (csDesigning in ComponentState) then
    MonitorHook.SQLExecute(Self);
end;

function TIBSQL.GetEOF: Boolean;
begin
  result := FEOF or not FOpen;
end;

function TIBSQL.FieldByName(FieldName: String): TIBXSQLVAR;
var
  i: Integer;
begin
  i := GetFieldIndex(FieldName);
  if (i < 0) then
    IBError(ibxeFieldNotFound, [FieldName]);
  result := GetFields(i);
end;

function TIBSQL.GetFields(const Idx: Integer): TIBXSQLVAR;
begin
  if (Idx < 0) or (Idx >= FSQLRecord.Count) then
    IBError(ibxeFieldNotFound, [IntToStr(Idx)]);
  result := FSQLRecord[Idx];
end;

function TIBSQL.GetFieldIndex(FieldName: String): Integer;
begin
  if (FSQLRecord.GetXSQLVarByName(FieldName) = nil) then
    result := -1
  else
    result := FSQLRecord.GetXSQLVarByName(FieldName).Index;
end;

function TIBSQL.Next: TIBXSQLDA;
var
  fetch_res: ISC_STATUS;
begin
  result := nil;
  if not FEOF then
  begin
    CheckOpen;
    { Go to the next record... }
    fetch_res :=
      Call(isc_dsql_fetch(StatusVector, @FHandle, Database.SQLDialect, FSQLRecord.AsXSQLDA), False);
    if (fetch_res = 100) or (CheckStatusVector([isc_dsql_cursor_err])) then
    begin
      FEOF := True;
    end
    else
      if (fetch_res > 0) then
      begin
        try
          IBDataBaseError;
        except
          Close;
          raise;
        end;
      end
      else
      begin
        Inc(FRecordCount);
        FBOF := False;
        result := FSQLRecord;
      end;
    if not (csDesigning in ComponentState) then
      MonitorHook.SQLFetch(Self);
  end;
end;

procedure TIBSQL.FreeHandle;
var
  isc_res: ISC_STATUS;
begin
  try
    { The following two lines merely set the SQLDA count
     variable FCount to 0, but do not deallocate
     That way the allocations can be reused for
     a new query sring in the same SQL instance }
    FSQLRecord.Count := 0;
    FSQLParams.Count := 0;
    if FHandle <> nil then begin
      isc_res :=
        Call(isc_dsql_free_statement(StatusVector, @FHandle, DSQL_drop), False);
      if (StatusVector^ = 1) and (isc_res > 0) and (isc_res <> isc_bad_stmt_handle) then
        IBDataBaseError;
    end;
  finally
    FPrepared := False;
    FHandle := nil;
  end;
end;

function TIBSQL.GetDatabase: TIBDatabase;
begin
  result := FBase.Database;
end;

function TIBSQL.GetDBHandle: PISC_DB_HANDLE;
begin
  result := FBase.DBHandle;
end;

function TIBSQL.GetPlan: String;
var
  result_buffer: array[0..16384] of Char;
  result_length, i: Integer;
  info_request: Char;
begin
  if (not Prepared) or
     (not (FSQLType in [SQLSelect, SQLSelectForUpdate,
       {TODO: SQLExecProcedure, }
       SQLUpdate, SQLDelete])) then
    result := ''
  else
  begin
    info_request := Char(isc_info_sql_get_plan);
    Call(isc_dsql_sql_info(StatusVector, @FHandle, 2, @info_request,
                           SizeOf(result_buffer), result_buffer), True);
    if (result_buffer[0] <> Char(isc_info_sql_get_plan)) then
      IBError(ibxeUnknownPlan, [nil]);
    result_length := isc_vax_integer(@result_buffer[1], 2);
    SetString(result, nil, result_length);
    for i := 1 to result_length do
      result[i] := result_buffer[i + 2];
    result := Trim(result);
  end;
end;

function TIBSQL.GetRecordCount: Integer;
begin
  result := FRecordCount;
end;

function TIBSQL.GetRowsAffected: integer;
var
  result_buffer: array[0..1048] of Char;
  info_request: Char;
begin
  if not Prepared then
    result := -1
  else begin
    info_request := Char(isc_info_sql_records);
    if isc_dsql_sql_info(StatusVector, @FHandle, 1, @info_request,
                         SizeOf(result_buffer), result_buffer) > 0 then
      IBDatabaseError;
    if (result_buffer[0] <> Char(isc_info_sql_records)) then
      result := -1
    else
    case SQLType of
      SQLUpdate:   Result := isc_vax_integer(@result_buffer[6], 4);
      SQLDelete:   Result := isc_vax_integer(@result_buffer[13], 4);
      SQLInsert:   Result := isc_vax_integer(@result_buffer[27], 4);
    else
      Result := -1;
    end ;
  end;
end;

function TIBSQL.GetSQLParams: TIBXSQLDA;
begin
  if not Prepared then
    Prepare;
  result := FSQLParams;
end;

function TIBSQL.GetTransaction: TIBTransaction;
begin
  result := FBase.Transaction;
end;

function TIBSQL.GetTRHandle: PISC_TR_HANDLE;
begin
  result := FBase.TRHandle;
end;

{
 Preprocess SQL
 Using FSQL, process the typed SQL and put the process SQL
 in FProcessedSQL and parameter names in FSQLParams
}
procedure TIBSQL.PreprocessSQL;
var
  cCurChar, cNextChar, cQuoteChar: Char;
  sSQL, sProcessedSQL, sParamName: String;
  i, iLenSQL, iSQLPos: Integer;
  iCurState, iCurParamState: Integer;
  iParamSuffix: Integer;
  slNames: TStrings;

const
  DefaultState = 0;
  CommentState = 1;
  QuoteState = 2;
  ParamState = 3;
  ParamDefaultState = 0;
  ParamQuoteState = 1;

  procedure AddToProcessedSQL(cChar: Char);
  begin
    sProcessedSQL[iSQLPos] := cChar;
    Inc(iSQLPos);
  end;

begin
  slNames := TStringList.Create;
  try
    { Do some initializations of variables }
    iParamSuffix := 0;
    cQuoteChar := '''';
    sSQL := FSQL.Text;
    iLenSQL := Length(sSQL);
    SetString(sProcessedSQL, nil, iLenSQL + 1);
    i := 1;
    iSQLPos := 1;
    iCurState := DefaultState;
    iCurParamState := ParamDefaultState;
    { Now, traverse through the SQL string, character by character,
     picking out the parameters and formatting correctly for InterBase }
    while (i <= iLenSQL) do begin
      { Get the current token and a look-ahead }
      cCurChar := sSQL[i];
      if i = iLenSQL then
        cNextChar := #0
      else
        cNextChar := sSQL[i + 1];
      { Now act based on the current state }
      case iCurState of
        DefaultState: begin
          case cCurChar of
            '''', '"': begin
              cQuoteChar := cCurChar;
              iCurState := QuoteState;
            end;
            '?', ':': begin
              iCurState := ParamState;
              AddToProcessedSQL('?');
            end;
            '/': if (cNextChar = '*') then begin
              AddToProcessedSQL(cCurChar);
              Inc(i);
              iCurState := CommentState;
            end;
          end;
        end;
        CommentState: begin
          if (cNextChar = #0) then
            IBError(ibxeSQLParseError, [SEOFInComment])
          else if (cCurChar = '*') then begin
            if (cNextChar = '/') then
              iCurState := DefaultState;
          end;
        end;
        QuoteState: begin
          if cNextChar = #0 then
            IBError(ibxeSQLParseError, [SEOFInString])
          else if (cCurChar = cQuoteChar) then begin
            if (cNextChar = cQuoteChar) then begin
              AddToProcessedSQL(cCurChar);
              Inc(i);
            end else
              iCurState := DefaultState;
          end;
        end;
        ParamState:
        begin
          { collect the name of the parameter }
          if iCurParamState = ParamDefaultState then
          begin
            if cCurChar = '"' then
              iCurParamState := ParamQuoteState
            else if (cCurChar in ['A'..'Z', 'a'..'z', '0'..'9', '_', '$']) then
                sParamName := sParamName + cCurChar
            else if FGenerateParamNames then
            begin
              sParamName := 'IBXParam' + IntToStr(iParamSuffix); {do not localize}
              Inc(iParamSuffix);
              iCurState := DefaultState;
              slNames.Add(sParamName);
              sParamName := '';
            end
            else
              IBError(ibxeSQLParseError, [SParamNameExpected]);
          end
          else begin
            { determine if Quoted parameter name is finished }
            if cCurChar = '"' then
            begin
              Inc(i);
              slNames.Add(sParamName);
              SParamName := '';
              iCurParamState := ParamDefaultState;
              iCurState := DefaultState;
            end
            else
              sParamName := sParamName + cCurChar
          end;
          { determine if the unquoted parameter name is finished }
          if (iCurParamState <> ParamQuoteState) and
            (iCurState <> DefaultState) then
          begin
            if not (cNextChar in ['A'..'Z', 'a'..'z',
                                  '0'..'9', '_', '$']) then begin
              Inc(i);
              iCurState := DefaultState;
              slNames.Add(sParamName);
              sParamName := '';
            end;
          end;
        end;
      end;
      if iCurState <> ParamState then
        AddToProcessedSQL(sSQL[i]);
      Inc(i);
    end;
    AddToProcessedSQL(#0);
    FSQLParams.Count := slNames.Count;
    for i := 0 to slNames.Count - 1 do
      FSQLParams.AddName(slNames[i], i);
    FProcessedSQL.Text := sProcessedSQL;
  finally
    slNames.Free;
  end;
end;

procedure TIBSQL.SetDatabase(Value: TIBDatabase);
begin
  if FBase.Database <> Value then
    FBase.Database := Value;
end;

procedure TIBSQL.Prepare;
var
  stmt_len: Integer;
  res_buffer: array[0..7] of Char;
  type_item: Char;
begin
  CheckClosed;
  FBase.CheckDatabase;
  FBase.CheckTransaction;
  if FPrepared then
    exit;
  if (FSQL.Text = '') then
    IBError(ibxeEmptyQuery, [nil]);
  if not ParamCheck then
    FProcessedSQL.Text := FSQL.Text
  else
    PreprocessSQL;
  if (FProcessedSQL.Text = '') then
    IBError(ibxeEmptyQuery, [nil]);
  try
    Call(isc_dsql_alloc_statement2(StatusVector, DBHandle,
                                    @FHandle), True);
    Call(isc_dsql_prepare(StatusVector, TRHandle, @FHandle, 0,
               PChar(FProcessedSQL.Text), Database.SQLDialect, nil), True);
    { After preparing the statement, query the stmt type and possibly
      create a FSQLRecord "holder" }
    { Get the type of the statement }
    type_item := Char(isc_info_sql_stmt_type);
    Call(isc_dsql_sql_info(StatusVector, @FHandle, 1, @type_item,
                         SizeOf(res_buffer), res_buffer), True);
    if (res_buffer[0] <> Char(isc_info_sql_stmt_type)) then
      IBError(ibxeUnknownError, [nil]);
    stmt_len := isc_vax_integer(@res_buffer[1], 2);
    FSQLType := TIBSQLTypes(isc_vax_integer(@res_buffer[3], stmt_len));
    { Done getting the type }
    case FSQLType of
      SQLGetSegment,
      SQLPutSegment,
      SQLStartTransaction:
      begin
        FreeHandle;
        IBError(ibxeNotPermitted, [nil]);
      end;
      SQLCommit,
      SQLRollback,
      SQLDDL, SQLSetGenerator,
      SQLInsert, SQLUpdate, SQLDelete, SQLSelect, SQLSelectForUpdate,
      SQLExecProcedure:
      begin
        { We already know how many inputs there are, so... }
        if (FSQLParams.FXSQLDA <> nil) and
           (Call(isc_dsql_describe_bind(StatusVector, @FHandle, Database.SQLDialect,
                                        FSQLParams.FXSQLDA), False) > 0) then
          IBDataBaseError;
        FSQLParams.Initialize;
        if FSQLType in [SQLSelect, SQLSelectForUpdate,
                        SQLExecProcedure] then
        begin
          { Allocate an initial output descriptor (with one column) }
          FSQLRecord.Count := 1;
          { Using isc_dsql_describe, get the right size for the columns... }
          Call(isc_dsql_describe(StatusVector, @FHandle, Database.SQLDialect, FSQLRecord.FXSQLDA), True);
          if FSQLRecord.FXSQLDA^.sqld > FSQLRecord.FXSQLDA^.sqln then
          begin
            FSQLRecord.Count := FSQLRecord.FXSQLDA^.sqld;
            Call(isc_dsql_describe(StatusVector, @FHandle, Database.SQLDialect, FSQLRecord.FXSQLDA), True);
          end
          else
            if FSQLRecord.FXSQLDA^.sqld = 0 then
              FSQLRecord.Count := 0;
          FSQLRecord.Initialize;
        end;
      end;
    end;
    FPrepared := True;
    if not (csDesigning in ComponentState) then
      MonitorHook.SQLPrepare(Self);
  except
    on E: Exception do
    begin
      if (FHandle <> nil) then
        FreeHandle;
      raise;
    end;
  end;
end;

function TIBSQL.GetUniqueRelationName: String;
begin
  if FPrepared and (FSQLType = SQLSelect) then
    result := FSQLRecord.UniqueRelationName
  else
    result := '';
end;

procedure TIBSQL.SetSQL(Value: TStrings);
begin
  if FSQL.Text <> Value.Text then
  begin
    FSQL.BeginUpdate;
    try
      FSQL.Assign(Value);
    finally
      FSQL.EndUpdate;
    end;
  end;
end;

procedure TIBSQL.SetTransaction(Value: TIBTransaction);
begin
  if FBase.Transaction <> Value then
    FBase.Transaction := Value;
end;

procedure TIBSQL.SQLChanging(Sender: TObject);
begin
  if Assigned(OnSQLChanging) then
    OnSQLChanging(Self);
  if FHandle <> nil then FreeHandle;
end;

procedure TIBSQL.BeforeTransactionEnd(Sender: TObject);
begin
  if (FOpen) then
    Close;
end;

function TIBSQL.ParamByName(Idx: String): TIBXSQLVAR;
begin
  if not Prepared then
    Prepare;
  result := FSQLParams.ByName(Idx);
end;

end.
