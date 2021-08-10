{*******************************************************}
{                                                       }
{       Borland Delphi Visual Component Library         }
{                                                       }
{  Copyright (C) 2000-2001 Borland Software Corp.       }
{                                                       }
{*******************************************************}

unit WebContnrs;

interface

uses
  Classes, SysUtils;

type
  ENamedVariantsError = class(Exception);

  TAbstractNamedVariants = class(TPersistent)
  private
    FUpdateCount: Integer;
    function GetName(Index: Integer): string;
    function GetValue(const Name: string): Variant;
    procedure ReadData(Reader: TReader);
    procedure SetValue(const Name: string; const Value: Variant);
    procedure WriteData(Writer: TWriter);
    procedure AddNamedVariants(ANamedVariants: TAbstractNamedVariants);
    function GetVariant(Index: Integer): Variant;
    procedure PutVariant(Index: Integer; const Value: Variant);
  protected
    procedure DefineProperties(Filer: TFiler); override;
    procedure Error(const Msg: string; Data: Integer); overload;
    function Get(Index: Integer; out AName: string; out AValue: Variant): Boolean; virtual; abstract;
    function GetCapacity: Integer; virtual;
    function GetCount: Integer; virtual; abstract;
    procedure Put(Index: Integer; const AName: string; const AValue: Variant); virtual; abstract;
    procedure SetCapacity(NewCapacity: Integer); virtual;
    procedure SetUpdateState(Updating: Boolean); virtual;
    property UpdateCount: Integer read FUpdateCount;
    function CompareStrings(const S1, S2: string): Integer; virtual;
  public
    destructor Destroy; override;
    function Add(const S: string; const AValue: Variant): Integer; virtual;
    procedure Append(const S: string; const AValue: Variant);
    procedure Assign(Source: TPersistent); override;
    procedure BeginUpdate;
    procedure Clear; virtual; abstract;
    procedure Delete(Index: Integer); virtual; abstract;
    procedure EndUpdate;
    function Equals(ANamedVariants: TAbstractNamedVariants): Boolean;
    procedure Exchange(Index1, Index2: Integer); virtual;
    function IndexOfName(const Name: string): Integer; virtual;
    procedure Insert(Index: Integer; const S: string; const AValue: Variant); virtual; abstract;
    procedure Move(CurIndex, NewIndex: Integer); virtual;
    property Capacity: Integer read GetCapacity write SetCapacity;
    property Count: Integer read GetCount;
    property Names[Index: Integer]: string read GetName;
    property Values[const Name: string]: Variant read GetValue write SetValue;
    property Variants[Index: Integer]: Variant read GetVariant write PutVariant;
  end;

  PNamedVariantItem = ^TNamedVariantItem;
  TNamedVariantItem = record
    FString: string;
    FVariant: Variant;
  end;

  PNamedVariantList = ^TNamedVariantList;
  TNamedVariantList = array[0..2000000000 div sizeof(TNamedVariantItem)] of TNamedVariantItem;

  TNamedVariantsList = class(TAbstractNamedVariants)
  private
    FList: PNamedVariantList;
    FCount: Integer;
    FCapacity: Integer;
    procedure Grow;
  protected
    procedure SetCapacity(NewCapacity: Integer); override;
    function GetCapacity: Integer; override;
    function Get(Index: Integer; out AName: string; out AValue: Variant): Boolean; override;
    procedure Put(Index: Integer; const AName: string; const AValue: Variant); override;
    function GetCount: Integer; override;
  public
    destructor Destroy; override;
    procedure Clear; override;
    procedure Delete(Index: Integer); override;
    procedure Insert(Index: Integer; const S: string; const AValue: Variant); override;
  end;

implementation

uses Variants, RtlConsts;

{ TAbstractNamedVariants }

function TAbstractNamedVariants.Add(const S: string;
  const AValue: Variant): Integer;
begin
  Result := GetCount;
  Insert(Result, S, AValue);
end;

procedure TAbstractNamedVariants.Append(const S: string; const AValue: Variant);
begin
  Add(S, AValue);
end;

procedure TAbstractNamedVariants.AddNamedVariants(ANamedVariants: TAbstractNamedVariants);
var
  I: Integer;
  S: string;
  V: Variant;
begin
  BeginUpdate;
  try
    for I := 0 to ANamedVariants.Count - 1 do
    begin
      ANamedVariants.Get(I, S, V);
      Add(S, V);
    end;
  finally
    EndUpdate;
  end;
end;

procedure TAbstractNamedVariants.Assign(Source: TPersistent);
begin
  if Source is TAbstractNamedVariants then
  begin
    BeginUpdate;
    try
      Clear;
      AddNamedVariants(TAbstractNamedVariants(Source));
    finally
      EndUpdate;
    end;
    Exit;
  end;
  inherited Assign(Source);
end;

procedure TAbstractNamedVariants.BeginUpdate;
begin
  if FUpdateCount = 0 then SetUpdateState(True);
  Inc(FUpdateCount);
end;

function TAbstractNamedVariants.CompareStrings(const S1, S2: string): Integer;
begin
  Result := AnsiCompareText(S1, S2);
end;

procedure TAbstractNamedVariants.DefineProperties(Filer: TFiler);
  function DoWrite: Boolean;
  begin
    if Filer.Ancestor <> nil then
    begin
      Result := True;
      if Filer.Ancestor is TAbstractNamedVariants then
        Result := not Equals(TAbstractNamedVariants(Filer.Ancestor))
    end
    else Result := Count > 0;
  end;

begin
  Filer.DefineProperty('NamedVariants', ReadData, WriteData, DoWrite);
end;

destructor TAbstractNamedVariants.Destroy;
begin
  inherited;

end;

procedure TAbstractNamedVariants.EndUpdate;
begin
  Dec(FUpdateCount);
  if FUpdateCount = 0 then SetUpdateState(False);
end;

function TAbstractNamedVariants.Equals(ANamedVariants: TAbstractNamedVariants): Boolean;
var
  I, Count: Integer;
begin
  Result := False;
  Count := GetCount;
  if Count <> ANamedVariants.GetCount then Exit;
  for I := 0 to Count - 1 do
    if (Names[I] <> ANamedVariants.Names[I]) or
       (Variants[I] <> ANamedVariants.Variants[I]) then Exit;
  Result := True;
end;

procedure TAbstractNamedVariants.Error(const Msg: string; Data: Integer);
begin
  raise ENamedVariantsError.CreateFmt(Msg, [Data]);
end;

procedure TAbstractNamedVariants.Exchange(Index1, Index2: Integer);
var
  TempVariant: Variant;
  TempName: string;
begin
  BeginUpdate;
  try
    Get(Index1, TempName, TempVariant);
    Put(Index1, Names[Index2], Variants[Index2]);
    Put(Index2, TempName, TempVariant);
  finally
    EndUpdate;
  end;
end;

function TAbstractNamedVariants.GetCapacity: Integer;
begin  // descendants may optionally override/replace this default implementation
  Result := Count;
end;

function TAbstractNamedVariants.GetValue(const Name: string): Variant;
var
  I: Integer;
begin
  I := IndexOfName(Name);
  if I >= 0 then
    Result := GetVariant(I) else
    Result := Unassigned;
end;

function TAbstractNamedVariants.IndexOfName(const Name: string): Integer;
begin
  for Result := 0 to GetCount - 1 do
    if CompareStrings(GetName(Result), Name) = 0 then Exit;
  Result := -1;
end;

procedure TAbstractNamedVariants.Move(CurIndex, NewIndex: Integer);
var
  TempVariant: Variant;
  TempName: string;
begin
  if CurIndex <> NewIndex then
  begin
    BeginUpdate;
    try
      Get(CurIndex, TempName, TempVariant);
      Delete(CurIndex);
      Insert(NewIndex, TempName, TempVariant);
    finally
      EndUpdate;
    end;
  end;
end;

procedure TAbstractNamedVariants.ReadData(Reader: TReader);
var
  V: Variant;
  S: string;
begin
  Reader.ReadListBegin;
  BeginUpdate;
  try
    Clear;
    while not Reader.EndOfList do
    begin
       S := Reader.ReadString;
       V := Reader.ReadVariant;
       Add(S, V);
    end;
  finally
    EndUpdate;
  end;
  Reader.ReadListEnd;
end;

procedure TAbstractNamedVariants.SetCapacity(NewCapacity: Integer);
begin
  // do nothing - descendants may optionally implement this method
end;

procedure TAbstractNamedVariants.SetUpdateState(Updating: Boolean);
begin
  // do nothing
end;

procedure TAbstractNamedVariants.SetValue(const Name: string;
  const Value: Variant);
var
  I: Integer;
begin
  I := IndexOfName(Name);
  if I < 0 then
    Add(Name, Value)
  else
    PutVariant(I, Value);
end;

procedure TAbstractNamedVariants.WriteData(Writer: TWriter);
var
  I: Integer;
begin
  Writer.WriteListBegin;
  for I := 0 to Count - 1 do
  begin
    Writer.WriteString(Names[I]);
    Writer.WriteVariant(Variants[I]);
  end;
  Writer.WriteListEnd;
end;

function TAbstractNamedVariants.GetName(Index: Integer): string;
var
  TempVariant: Variant;
begin
  Get(Index, Result, TempVariant);
end;

function TAbstractNamedVariants.GetVariant(Index: Integer): Variant;
var
  TempName: string;
begin
  Get(Index, TempName, Result);
end;

procedure TAbstractNamedVariants.PutVariant(Index: Integer; const Value: Variant);
begin
  Put(Index, GetName(Index), Value);
end;

{ TNamedVariantsList }

destructor TNamedVariantsList.Destroy;
begin
  inherited Destroy;
  if FCount <> 0 then Finalize(FList^[0], FCount);
  FCount := 0;
  SetCapacity(0);
end;

procedure TNamedVariantsList.Clear;
begin
  if FCount <> 0 then
  begin
    Finalize(FList^[0], FCount);
    FCount := 0;
    SetCapacity(0);
  end;
end;

procedure TNamedVariantsList.Delete(Index: Integer);
begin
  if (Index < 0) or (Index >= FCount) then Error(SListIndexError, Index);
  Finalize(FList^[Index]);
  Dec(FCount);
  if Index < FCount then
    System.Move(FList^[Index + 1], FList^[Index],
      (FCount - Index) * SizeOf(TNamedVariantItem));
end;

function TNamedVariantsList.Get(Index: Integer; out AName: string; out AValue: Variant): Boolean;
begin
  Result := True;
  if (Index < 0) or (Index >= FCount) then Error(sListIndexError, Index);
  AName := FList^[Index].FString;
  AValue := FList^[Index].FVariant;
end;

function TNamedVariantsList.GetCapacity: Integer;
begin
  Result := FCapacity;
end;

function TNamedVariantsList.GetCount: Integer;
begin
  Result := FCount;
end;

procedure TNamedVariantsList.Grow;
var
  Delta: Integer;
begin
  if FCapacity > 64 then Delta := FCapacity div 4 else
    if FCapacity > 8 then Delta := 16 else
      Delta := 4;
  SetCapacity(FCapacity + Delta);
end;

procedure TNamedVariantsList.Insert(Index: Integer; const S: string; const AValue: Variant);
begin
  if (Index < 0) or (Index > FCount) then Error(SListIndexError, Index);
  if FCount = FCapacity then Grow;
  if Index < FCount then
    System.Move(FList^[Index], FList^[Index + 1],
      (FCount - Index) * SizeOf(TNamedVariantItem));
  with FList^[Index] do
  begin
    Pointer(FString) := nil;
    FillChar(TVarData(FVariant), sizeof(TVarData), 0);
    FVariant := AValue;
    FString := S;
  end;
  Inc(FCount);
end;

procedure TNamedVariantsList.Put(Index: Integer; const AName: string; const AValue: Variant);
begin
  if (Index < 0) or (Index >= FCount) then Error(SListIndexError, Index);
  FList^[Index].FString := AName;
  FList^[Index].FVariant := AValue;
end;

procedure TNamedVariantsList.SetCapacity(NewCapacity: Integer);
begin
  ReallocMem(FList, NewCapacity * SizeOf(TNamedVariantItem));
  FCapacity := NewCapacity;
end;

end.
 