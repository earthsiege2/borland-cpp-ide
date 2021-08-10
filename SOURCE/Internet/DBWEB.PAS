
{*******************************************************}
{                                                       }
{       Borland Delphi Visual Component Library         }
{       Database Web server application components      }
{                                                       }
{       Copyright (c) 1997,99 Inprise Corporation       }
{                                                       }
{*******************************************************}

unit DBWeb;

interface

uses Windows, SysUtils, Classes, SyncObjs, HTTPApp, DB, DBTables;

type

  TDSTableProducer = class;

{ TDSTableProducerEditor }

  TDSTableProducerEditor = class
  private
    FDSTableProducer: TDSTableProducer;
    function GetDataSource: TDataSource;
    procedure SetDataSource(DataSource: TDataSource);
  public
    constructor Create(DSTableProducer: TDSTableProducer);
    destructor Destroy; override;
    procedure Changed; virtual;
    procedure PostChange; virtual;
    property DSTableProducer: TDSTableProducer read FDSTableProducer;
    property DataSource: TDataSource read GetDataSource write SetDataSource;
  end;

{ THTTPDataLink }

  THTTPDataLink = class(TDataLink)
  private
    FDSTableProducer: TDSTableProducer;
    FFieldCount: Integer;
    FFieldMapSize: Integer;
    FFieldMap: Pointer;
    FModified: Boolean;
    FSparseMap: Boolean;
    function GetDefaultFields: Boolean;
    function GetFields(I: Integer): TField;
  protected
    procedure ActiveChanged; override;
    procedure DataSetChanged; override;
    procedure DataSetScrolled(Distance: Integer); override;
    procedure FocusControl(Field: TFieldRef); override;
    procedure EditingChanged; override;
    procedure LayoutChanged; override;
    procedure RecordChanged(Field: TField); override;
    procedure UpdateData; override;
    function  GetMappedIndex(ColIndex: Integer): Integer;
  public
    constructor Create(DSTableProducer: TDSTableProducer);
    destructor Destroy; override;
    function AddMapping(const FieldName: string): Boolean;
    procedure ClearMapping;
    procedure Modified;
    procedure Reset;
    property DefaultFields: Boolean read GetDefaultFields;
    property FieldCount: Integer read FFieldCount;
    property Fields[I: Integer]: TField read GetFields;
    property SparseMap: Boolean read FSparseMap write FSparseMap;
  end;

{ THTMLTableColumn }

  THTMLTableColumn = class(TCollectionItem)
  private
    FField: TField;
    FFieldName: string;
    FAlign: THTMLAlign;
    FBgColor: THTMLBgColor;
    FCustom: string;
    FVAlign: THTMLVAlign;
    FTitle: THTMLTableHeaderAttributes;
    function GetField: TField;
    function GetTableProducer: TDSTableProducer;
    procedure SetAlign(Value: THTMLAlign);
    procedure SetBgColor(const Value: THTMLBgColor);
    procedure SetCustom(const Value: string);
    procedure SetField(Value: TField);
    procedure SetFieldName(const Value: string);
    procedure SetTitle(Value: THTMLTableHeaderAttributes);
    procedure SetVAlign(Value: THTMLVAlign);
    procedure TitleChanged(Sender: TObject);
  protected
    function GeTDSTableProducer: TDSTableProducer;
    function GetDisplayName: string; override;
  public
    constructor Create(Collection: TCollection); override;
    destructor Destroy; override;
    procedure AssignTo(Dest: TPersistent); override;
    procedure RestoreDefaults;
    procedure Update;
    property Field: TField read GetField write SetField;
    property DSTableProducer: TDSTableProducer read GetTableProducer;
  published
    property Align: THTMLAlign read FAlign write SetAlign default haDefault;
    property BgColor: THTMLBgColor read FBgColor write SetBgColor;
    property Custom: string read FCustom write SetCustom;
    property FieldName: string read FFieldName write SetFieldName;
    property Title: THTMLTableHeaderAttributes read FTitle write SetTitle;
    property VAlign: THTMLVAlign read FVAlign write SetVAlign default haVDefault;
  end;

  THTMLTableColumnClass = class of THTMLTableColumn;

{ THTMLTableColumns }

  THTMLColumnState = (csDefault, csCustom);

  THTMLTableColumns = class(TCollection)
  private
    FDSTableProducer: TDSTableProducer;
    function GetColumn(Index: Integer): THTMLTableColumn;
    function GetState: THTMLColumnState;
    procedure SetColumn(Index: Integer; Value: THTMLTableColumn);
    procedure SetState(Value: THTMLColumnState);
  protected
    function GetAttrCount: Integer; override;
    function GetAttr(Index: Integer): string; override;
    function GetItemAttr(Index, ItemIndex: Integer): string; override;
    function GetOwner: TPersistent; override;
    procedure Update(Item: TCollectionItem); override;
  public
    constructor Create(DSTableProducer: TDSTableProducer;
      ColumnClass: THTMLTableColumnClass);
    function  Add: THTMLTableColumn;
    procedure RestoreDefaults;
    procedure RebuildColumns;
    property State: THTMLColumnState read GetState write SetState;
    property DSTableProducer: TDSTableProducer read FDSTableProducer;
    property Items[Index: Integer]: THTMLTableColumn read GetColumn write SetColumn; default;
  end;

{ TDSTableProducer }

  THTMLCaptionAlignment = (caDefault, caTop, caBottom);

  TCreateContentEvent = procedure (Sender: TObject; var Continue: Boolean) of object;
  THTMLGetTableCaptionEvent = procedure (Sender: TObject; var Caption: string;
    var Alignment: THTMLCaptionAlignment) of object;
  THTMLFormatCellEvent = procedure (Sender: TObject; CellRow, CellColumn: Integer;
    var BgColor: THTMLBgColor; var Align: THTMLAlign; var VAlign: THTMLVAlign;
    var CustomAttrs, CellData: string) of object;
  THTMLDataSetEmpty = procedure (Sender: TObject; var Continue: Boolean) of object;

  TDSTableProducer = class(TCustomContentProducer)
  private
    FCaption: string;
    FCaptionAlignment: THTMLCaptionAlignment;
    FDataLink: THTTPDataLink;
    FInternalDataSource: TDataSource;
    FEditor: TDSTableProducerEditor;
    FColumns: THTMLTableColumns;
    FHeader: TStrings;
    FFooter: TStrings;
    FMaxRows: Integer;
    FModified: Boolean;
    FLayoutLock: Integer;
    FUpdateLock: Integer;
    FRowAttributes: THTMLTableRowAttributes;
    FTableAttributes: THTMLTableAttributes;
    FOnCreateContent: TCreateContentEvent;
    FOnFormatCell: THTMLFormatCellEvent;
    FOnGetTableCaption: THTMLGetTableCaptionEvent;
    procedure AttributeChanged(Sender: TObject);
    procedure Changed;
    procedure InternalLayout;
    procedure SetCaption(const Value: string);
    procedure SetCaptionAlignment(Value: THTMLCaptionAlignment);
    procedure SetFooter(Value: TStrings);
    procedure SetHeader(Value: TStrings);
    procedure SetMaxRows(Value: Integer);
    procedure SetRowAttributes(Value: THTMLTableRowAttributes);
    procedure SetTableAttributes(Value: THTMLTableAttributes);
  protected
    function AcquireLayoutLock: Boolean;
    procedure BeginLayout;
    function ColumnHeader: string; dynamic;
    procedure DefineFieldMap;
    function DoCreateContent: Boolean;
    procedure DoFormatCell(CellRow, CellColumn: Integer; var BgColor: THTMLBgColor;
      var Align: THTMLAlign; var VAlign: THTMLVAlign;
      var CustomAttrs, CellData: string); dynamic;
    procedure DoGetCaption(var TableCaption: string;
      var CaptionAlign: THTMLCaptionAlignment); dynamic;
    procedure EndLayout;
    function FormatCell(CellRow, CellColumn: Integer; CellData: string;
      const Tag: string; const BgColor: THTMLBgColor; Align: THTMLAlign;
      VAlign: THTMLVAlign; const Custom: string): string; dynamic;
    function GetDataSet: TDataSet; virtual; abstract;
    function GetDataSource: TDataSource;
    procedure Notification(AComponent: TComponent; Operation: TOperation); override;
    procedure LayoutChanged;
    procedure LinkActive(Value: Boolean);
    function RowHeader: string; dynamic;
    procedure SetColumns(Value: THTMLTableColumns);
    procedure SetDataSet(ADataSet: TDataSet); virtual; abstract;
    procedure SetDataSource(Value: TDataSource);
    function StoreColumns: Boolean;
    function TableHeader: string; dynamic;
    function TableCaption: string; dynamic;
    property DataLink: THTTPDataLink read FDataLink;
    property DataSource: TDataSource read GetDataSource write SetDataSource;
    property InternalDataSource: TDataSource read FInTernalDataSource;
    property OnCreateContent: TCreateContentEvent read FOnCreateContent
      write FOnCreateContent;
    property OnFormatCell: THTMLFormatCellEvent read FOnFormatCell
      write FOnFormatCell;
    property OnGetTableCaption: THTMLGetTableCaptionEvent
      read FOnGetTableCaption write FOnGetTableCaption;
  public
    constructor Create(AOwner: TComponent); override;
    destructor Destroy; override;
    procedure BeginUpdate;
    procedure EndUpdate;
    property Caption: string read FCaption write SetCaption;
    property CaptionAlignment: THTMLCaptionAlignment read FCaptionAlignment
      write SetCaptionAlignment default caDefault;
    property Columns: THTMLTableColumns read FColumns write SetColumns stored StoreColumns;
    property DataSet: TDataSet read GetDataSet write SetDataSet;
    property Editor: TDSTableProducerEditor read FEditor write FEditor;
    property Footer: TStrings read FFooter write SetFooter;
    property Header: TStrings read FHeader write SetHeader;
    property MaxRows: Integer read FMaxRows write SetMaxRows default 20;
    property RowAttributes: THTMLTableRowAttributes read FRowAttributes
      write SetRowAttributes;
    property TableAttributes: THTMLTableAttributes read FTableAttributes
      write SetTableAttributes;
  end;

{ TQueryTableProducer }

  TQueryTableProducer = class(TDSTableProducer)
  private
    FQuery: TQuery;
    procedure SetQuery(AQuery: TQuery);
  protected
    function GetDataSet: TDataSet; override;
    procedure Notification(AComponent: TComponent; Operation: TOperation); override;
    procedure SetDataSet(ADataSet: TDataSet); override;
  public
    function Content: string; override;
  published
    property Caption;
    property CaptionAlignment;
    property Columns;
    property Footer;
    property Header;
    property MaxRows;
    property Query: TQuery read FQuery write SetQuery;
    property RowAttributes;
    property TableAttributes;
    property OnCreateContent;
    property OnFormatCell;
    property OnGetTableCaption;
  end;

{ TDataSetTableProducer }

  TDataSetTableProducer = class(TDSTableProducer)
  private
    FDataSet: TDataSet;
  protected
    function GetDataSet: TDataSet; override;
    procedure Notification(AComponent: TComponent; Operation: TOperation); override;
    procedure SetDataSet(ADataSet: TDataSet); override;
  public
    function Content: string; override;
  published
    property Caption;
    property CaptionAlignment;
    property Columns;
    property Footer;
    property Header;
    property MaxRows;
    property DataSet;
    property RowAttributes;
    property TableAttributes;
    property OnCreateContent;
    property OnFormatCell;
    property OnGetTableCaption;
  end;

function HtmlTable(DataSet: TDataSet; DataSetHandler: TDSTableProducer;
  MaxRows: Integer): string;

implementation

uses
  WebConst;

{ Error reporting }

procedure TableError(const S: string);
begin
  raise Exception.Create(S);
end;

{ DSTableProducerEditor }

constructor TDSTableProducerEditor.Create(DSTableProducer: TDSTableProducer);
begin
  inherited Create;
  RPR;
  FDSTableProducer := DSTableProducer;
  FDSTableProducer.Editor := Self;
end;

destructor TDSTableProducerEditor.Destroy;
begin
  if FDSTableProducer <> nil then FDSTableProducer.Editor := nil;
  inherited Destroy;
end;

procedure TDSTableProducerEditor.Changed;
begin
end;

procedure TDSTableProducerEditor.PostChange;
begin
end;

function TDSTableProducerEditor.GetDataSource;
begin
  if Assigned(FDSTableProducer) then
    Result := FDSTableProducer.DataSource
  else Result := nil;
end;

procedure TDSTableProducerEditor.SetDataSource(DataSource: TDataSource);
begin
  if Assigned(FDSTableProducer) then
    FDSTableProducer.DataSource := DataSource;
end;

{ THTMLTableColumn }

constructor THTMLTableColumn.Create(Collection: TCollection);
var
  DataSetHandler: TDSTableProducer;
begin
  DataSetHandler := nil;
  if (Collection <> nil) and (Collection is THTMLTableColumns) then
    DataSetHandler := THTMLTableColumns(Collection).DSTableProducer;
  if DataSetHandler <> nil then
    DataSetHandler.BeginLayout;
  try
    inherited Create(Collection);
    FTitle := THTMLTableHeaderAttributes.Create(nil);
    FTitle.OnChange := TitleChanged;
  finally
    if DataSetHandler <> nil then
      DataSetHandler.EndLayout;
  end;
end;

destructor THTMLTableColumn.Destroy;
begin
  FTitle.Free;
  inherited Destroy;
end;

procedure THTMLTableColumn.AssignTo(Dest: TPersistent);
begin
  if Dest is THTMLTableColumn then
  begin
    if Assigned(Collection) then Collection.BeginUpdate;
    try
      with THTMLTableColumn(Dest) do
      begin
        FieldName := Self.FieldName;
        Align := Self.Align;
        BgColor := Self.BgColor;
        VAlign := Self.VAlign;
        Title := Self.Title;
      end;
    finally
      if Assigned(Collection) then Collection.EndUpdate;
    end;
  end else inherited AssignTo(Dest);
end;

function THTMLTableColumn.GetField: TField;
var
  HTTPDSHandler: TDSTableProducer;
begin
  HTTPDSHandler := GetDSTableProducer;
  if (FField = nil) and (FFieldName <> '') and Assigned(HTTPDsHandler) and
    Assigned(HTTPDSHandler.DataLink.DataSet) then
  with HTTPDSHandler.Datalink.Dataset do
    if Active or (not DefaultFields) then
      SetField(FindField(FieldName));
  Result := FField;
end;

function THTMLTableColumn.GetTableProducer: TDSTableProducer;
begin
  if Assigned(Collection) and (Collection is THTMLTableColumns) then
    Result := THTMLTableColumns(Collection).DSTableProducer
  else
    Result := nil;
end;

function THTMLTableColumn.GetDSTableProducer: TDSTableProducer;
begin
  if Assigned(Collection) and (Collection is THTMLTableColumns) then
    Result := THTMLTableColumns(Collection).DSTableProducer
  else Result := nil;
end;

function THTMLTableColumn.GetDisplayName: string;
begin
  if FFieldName <> '' then
    Result := FFieldName
  else Result := inherited GetDisplayName;
end;

procedure THTMLTableColumn.RestoreDefaults;
begin
  FAlign := haDefault;
  FBgColor := '';
  FCustom := '';
  FVAlign := haVDefault;
  FTitle.RestoreDefaults;
end;

procedure THTMLTableColumn.SetAlign(Value: THTMLAlign);
begin
  if Value <> FAlign then
  begin
    FAlign := Value;
    Changed(False);
  end;
end;

procedure THTMLTableColumn.SetBgColor(const Value: THTMLBgColor);
begin
  if Value <> FBgColor then
  begin
    FBgColor := Value;
    Changed(False);
  end;
end;

procedure THTMLTableColumn.SetCustom(const Value: string);
begin
  if Value <> FCustom then
  begin
    FCustom := Value;
    Changed(False);
  end;
end;

procedure THTMLTableColumn.SetField(Value: TField);
begin
  if Value <> FField then
  begin
    FField := Value;
    if Assigned(Value) then
      FFieldName := Value.FieldName;
    Changed(False);
  end;
end;

procedure THTMLTableColumn.SetFieldName(const Value: string);
var
  AField: TField;
  DataSetHandler: TDSTableProducer;
begin
  AField := nil;
  DataSetHandler := GetDSTableProducer;
  if Assigned(DataSetHandler) and Assigned(DataSetHandler.DataLink.DataSet) and
    not (csLoading in DataSetHandler.ComponentState) and (Value <> '') then
      AField := DataSetHandler.DataLink.DataSet.FindField(Value); { no exceptions }
  FFieldName := Value;
  SetField(AField);
  Changed(False);
end;

procedure THTMLTableColumn.SetTitle(Value: THTMLTableHeaderAttributes);
begin
  FTitle.Assign(Value);
end;

procedure THTMLTableColumn.SetVAlign(Value: THTMLVAlign);
begin
  if Value <> FVAlign then
  begin
    FVAlign := Value;
    Changed(False);
  end;
end;

procedure THTMLTableColumn.TitleChanged(Sender: TObject);
begin
  Changed(False);
end;

procedure THTMLTableColumn.Update;
begin
  GetField;
end;

type
  TDefaultHTMLTableColumn = class(THTMLTableColumn)
    constructor Create(Collection: TCollection); override;
  end;

{ TDefaultHTMLTableColumn }

constructor TDefaultHTMLTableColumn.Create(Collection: TCollection);
begin
  inherited Create(Collection);
end;

{ THTMLTableColumns }

constructor THTMLTableColumns.Create(DSTableProducer: TDSTableProducer;
  ColumnClass: THTMLTableColumnClass);
begin
  inherited Create(ColumnClass);
  FDSTableProducer := DSTableProducer;
end;

function THTMLTableColumns.Add: THTMLTableColumn;
begin
  Result := THTMLTableColumn(inherited Add);
end;

function THTMLTableColumns.GetColumn(Index: Integer): THTMLTableColumn;
begin
  Result := THTMLTableColumn(inherited Items[Index]);
end;

function THTMLTableColumns.GetState: THTMLColumnState;
begin
  Result := THTMLColumnState((Count > 0) and not (Items[0] is TDefaultHTMLTableColumn));
end;

procedure THTMLTableColumns.RestoreDefaults;
var
  I: Integer;
begin
  BeginUpdate;
  try
    for I := 0 to Count - 1 do
      Items[I].RestoreDefaults;
  finally
    EndUpdate;
  end;
end;

procedure THTMLTableColumns.RebuildColumns;
var
  I: Integer;
begin
  Clear;
  if Assigned(FDSTableProducer) and Assigned(FDSTableProducer.DataSource) and
    Assigned(FDSTableProducer.Datasource.Dataset) then
  begin
    FDSTableProducer.BeginLayout;
    try
      with FDSTableProducer.Datasource.Dataset do
        for I := 0 to FieldCount - 1 do
          Add.Field := Fields[I];
    finally
      FDSTableProducer.EndLayout;
    end;
    for I := 0 to Count - 1 do Items[I].Update;
  end;
end;

procedure THTMLTableColumns.SetColumn(Index: Integer; Value: THTMLTableColumn);
begin
  Items[Index].Assign(Value);
end;

procedure THTMLTableColumns.SetState(Value: THTMLColumnState);
begin
  if Value <> State then
  begin
    if Value = csDefault then
      Clear
    else
      RebuildColumns;
  end;
end;

{ Design-time support }
function THTMLTableColumns.GetAttrCount: Integer;
begin
  Result := 2;
end;

function THTMLTableColumns.GetAttr(Index: Integer): string;
begin
  case Index of
    0: Result := sFieldNameColumn;
    1: Result := sFieldTypeColumn;
  else
    Result := '';
  end;
end;

function THTMLTableColumns.GetItemAttr(Index, ItemIndex: Integer): string;
begin
  case Index of
    0: Result := Items[ItemIndex].DisplayName;
    1:
      with Items[ItemIndex] do
      begin
        GetField;
        if Field <> nil then
          Result := Field.ClassName
        else Result := '';
      end;
  else
    Result := '';
  end;
end;

function THTMLTableColumns.GetOwner: TPersistent;
begin
  Result := FDSTableProducer;
end;

procedure THTMLTableColumns.Update(Item: TCollectionItem);
begin
  if (FDSTableProducer <> nil) and
    not (csLoading in FDSTableProducer.ComponentState) then
    if Item = nil then
      FDSTableProducer.LayoutChanged
    else if FDSTableProducer.Editor <> nil then
      FDSTableProducer.Editor.PostChange;
end;

{ THTTPDataLink }

const
  MaxMapSize = (MaxInt div 2) div SizeOf(Integer);  { 250 million }

type
  TIntArray = array[0..MaxMapSize - 1] of Integer;
  PIntArray = ^TIntArray;

constructor THTTPDataLink.Create(DSTableProducer: TDSTableProducer);
begin
  inherited Create;
  FDSTableProducer := DSTableProducer;
end;

destructor THTTPDataLink.Destroy;
begin
  ClearMapping;
  inherited Destroy;
end;

function THTTPDataLink.GetDefaultFields: Boolean;
var
  I: Integer;
begin
  Result := True;
  if DataSet <> nil then Result := DataSet.DefaultFields;
  if Result and SparseMap then
  for I := 0 to FFieldCount - 1 do
    if PIntArray(FFieldMap)^[I] < 0 then
    begin
      Result := False;
      Exit;
    end;
end;

function THTTPDataLink.GetFields(I: Integer): TField;
begin
  if (0 <= I) and (I < FFieldCount) and (PIntArray(FFieldMap)^[I] >= 0) then
    Result := DataSet.Fields[PIntArray(FFieldMap)^[I]]
  else
    Result := nil;
end;

function THTTPDataLink.AddMapping(const FieldName: string): Boolean;
var
  Field: TField;
  NewSize: Integer;
begin
  Result := True;
  if FFieldCount >= MaxMapSize then TableError(STooManyColumns);
  if SparseMap then
    Field := DataSet.FindField(FieldName)
  else
    Field := DataSet.FieldByName(FieldName);

  if FFieldCount = FFieldMapSize then
  begin
    NewSize := FFieldMapSize;
    if NewSize = 0 then
      NewSize := 8
    else
      Inc(NewSize, NewSize);
    if (NewSize < FFieldCount) then
      NewSize := FFieldCount + 1;
    if (NewSize > MaxMapSize) then
      NewSize := MaxMapSize;
    ReallocMem(FFieldMap, NewSize * SizeOf(Integer));
    FFieldMapSize := NewSize;
  end;
  if Assigned(Field) then
  begin
    PIntArray(FFieldMap)^[FFieldCount] := Field.Index;
    Field.FreeNotification(FDSTableProducer);
  end
  else
    PIntArray(FFieldMap)^[FFieldCount] := -1;
  Inc(FFieldCount);
end;

procedure THTTPDataLink.ActiveChanged;
begin
  FDSTableProducer.LinkActive(Active);
end;

procedure THTTPDataLink.ClearMapping;
begin
  if FFieldMap <> nil then
  begin
    FreeMem(FFieldMap, FFieldMapSize * SizeOf(Integer));
    FFieldMap := nil;
    FFieldMapSize := 0;
    FFieldCount := 0;
  end;
end;

procedure THTTPDataLink.Modified;
begin
  FModified := True;
end;

procedure THTTPDataLink.DataSetChanged;
begin
  FDSTableProducer.Changed;
  FModified := False;
end;

procedure THTTPDataLink.DataSetScrolled(Distance: Integer);
begin
//  FGrid.Scroll(Distance);
end;

procedure THTTPDataLink.LayoutChanged;
begin
  FDSTableProducer.LayoutChanged;
end;

procedure THTTPDataLink.FocusControl(Field: TFieldRef);
begin
//  Not Needed
end;

procedure THTTPDataLink.EditingChanged;
begin
//  Not Needed
end;

procedure THTTPDataLink.RecordChanged(Field: TField);
begin
//  Not Needed
end;

procedure THTTPDataLink.UpdateData;
begin
//  Not Needed
end;

function THTTPDataLink.GetMappedIndex(ColIndex: Integer): Integer;
begin
  if (0 <= ColIndex) and (ColIndex < FFieldCount) then
    Result := PIntArray(FFieldMap)^[ColIndex]
  else
    Result := -1;
end;

procedure THTTPDataLink.Reset;
begin
  if FModified then RecordChanged(nil) else Dataset.Cancel;
end;

{ TDSTableProducer }

constructor TDSTableProducer.Create(AOwner: TComponent);
begin
  inherited Create(AOwner);
  FFooter := TStringList.Create;
  FHeader := TStringList.Create;
  FDataLink := THTTPDataLink.Create(Self);
  FInternalDataSource := TDataSource.Create(Self);
  FColumns := THTMLTableColumns.Create(Self, THTMLTableColumn);
  FRowAttributes := THTMLTableRowAttributes.Create(Self);
  FRowAttributes.OnChange := AttributeChanged;
  FTableAttributes := THTMLTableAttributes.Create(Self);
  FTableAttributes.OnChange := AttributeChanged;
  FMaxRows := 20;
  DataSource := FInternalDataSource; // must be the last thing
end;

destructor TDSTableProducer.Destroy;
begin
  BeginUpdate;
  DataSource := nil;
  FColumns.Free;
  FColumns := nil;
  FDataLink.Free;
  FDataLink := nil;
  FInternalDataSource.Free;
  FInternalDataSource := nil;
  FRowAttributes.Free;
  FTableAttributes.Free;
  FFooter.Free;
  FHeader.Free;
  inherited Destroy;
end;

function TDSTableProducer.AcquireLayoutLock: Boolean;
begin
  Result := (FLayoutLock = 0) and (FUpdateLock = 0);
  if Result then BeginLayout;
end;

procedure TDSTableProducer.AttributeChanged(Sender: TObject);
begin
  Changed;
end;

procedure TDSTableProducer.BeginLayout;
begin
  BeginUpdate;
  if FLayoutLock = 0 then FColumns.BeginUpdate;
  Inc(FLayoutLock);
end;

procedure TDSTableProducer.BeginUpdate;
begin
  Inc(FUpdateLock);
end;

procedure TDSTableProducer.Changed;
begin
  if (FUpdateLock = 0) and Assigned(FEditor) then
    FEditor.Changed
  else FModified := True;
end;

procedure TDSTableProducer.DefineFieldMap;
var
  I: Integer;
begin
  if FColumns.State = csCustom then
  begin   { Build the column/field map from the column attributes }
    DataLink.SparseMap := True;
    for I := 0 to FColumns.Count - 1 do
      FDataLink.AddMapping(FColumns[I].FieldName);
  end
  else   { Build the column/field map from the field list order }
  begin
    FDataLink.SparseMap := False;
    with Datalink.Dataset do
      for I := 0 to FieldCount - 1 do
        with Fields[I] do Datalink.AddMapping(FieldName);
  end;
end;

function TDSTableProducer.DoCreateContent: Boolean;
begin
  Result := True;
  if Assigned(FOnCreateContent) then
    FOnCreateContent(Self, Result);
end;

procedure TDSTableProducer.DoFormatCell(CellRow, CellColumn: Integer;
  var BgColor: THTMLBgColor; var Align: THTMLAlign; var VAlign: THTMLVAlign;
  var CustomAttrs, CellData: string);
begin
  if Assigned(FOnFormatCell) then
    FOnFormatCell(Self, CellRow, CellColumn, BgColor, Align, VAlign, CustomAttrs, CellData);
end;

procedure TDSTableProducer.DoGetCaption(var TableCaption: string;
  var CaptionAlign: THTMLCaptionAlignment);
begin
  TableCaption := FCaption;
  CaptionAlign := FCaptionAlignment;
  if Assigned(FOnGetTableCaption) then
    FOnGetTableCaption(Self, TableCaption, CaptionAlign);
end;

procedure TDSTableProducer.EndLayout;
begin
  if FLayoutLock > 0 then
  begin
    try
      try
        if FLayoutLock = 1 then
          InternalLayout;
      finally
        if FLayoutLock = 1 then
          FColumns.EndUpdate;
      end;
    finally
      Dec(FLayoutLock);
      EndUpdate;
    end;
  end;
end;

procedure TDSTableProducer.EndUpdate;
begin
  if (FUpdateLock = 1) and Assigned(FEditor) and (FModified or
    (FInternalDataSource.DataSet = nil) or
    ((FInternalDataSource.DataSet <> nil) and (FInternalDataSource.State = dsInactive))) then
  begin
    FModified := False;
    FEditor.Changed;
  end;
  if FUpdateLock > 0 then
    Dec(FUpdateLock);
end;

function TDSTableProducer.GetDataSource: TDataSource;
begin
  Result := FDataLink.DataSource;
end;

procedure TDSTableProducer.InternalLayout;
var
  I, J, K: Integer;
  Fld: TField;
  Column: THTMLTableColumn;
  SeenDefColumn: Boolean;

  function FieldIsMapped(F: TField): Boolean;
  var
    X: Integer;
  begin
    Result := False;
    if F <> nil then
      for X := 0 to FDatalink.FieldCount - 1 do
        if FDatalink.Fields[X] = F then
        begin
          Result := True;
          Exit;
        end;
  end;

begin
  if (csLoading in ComponentState) then Exit;
  SeenDefColumn := False;
  for I := 0 to FColumns.Count - 1 do
  begin
    if (FColumns[I] is TDefaultHTMLTableColumn) then
      SeenDefColumn := True
    else
      if SeenDefColumn then
      begin   { We have both custom and "passthrough columns". Kill the latter }
        for J := FColumns.Count-1 downto 0 do
        begin
          Column := FColumns[J];
          if Column is TDefaultHTMLTableColumn then
            Column.Free;
        end;
        Break;
      end;
  end;
  FDatalink.ClearMapping;
  if FDatalink.Active then DefineFieldMap;
  if FColumns.State = csDefault then
  begin
     { Destroy columns whose fields have been destroyed or are no longer
       in field map }
    if (not FDataLink.Active) and (FDatalink.DefaultFields) then
      FColumns.Clear
    else
      for J := FColumns.Count - 1 downto 0 do
        with FColumns[J] do
          if not Assigned(Field)
            or not FieldIsMapped(Field) then Free;
    I := FDataLink.FieldCount;
    for J := 0 to I - 1 do
    begin
      Fld := FDatalink.Fields[J];
      if Assigned(Fld) then
      begin
        K := J;
         { Pointer compare is valid here because the table sets matching
           column.field properties to nil in response to field object
           free notifications.  Closing a dataset that has only default
           field objects will destroy all the fields and set associated
           column.field props to nil. }
        while (K < FColumns.Count) and (FColumns[K].Field <> Fld) do
          Inc(K);
        if K < FColumns.Count then
          Column := FColumns[K]
        else
        begin
          Column := TDefaultHTMLTableColumn.Create(FColumns);
          Column.Field := Fld;
        end;
      end
      else
        Column := TDefaultHTMLTableColumn.Create(FColumns);
      Column.Index := J;
    end;
  end
  else
  begin
    { Force columns to reaquire fields (in case dataset has changed) }
    for I := 0 to FColumns.Count - 1 do
      FColumns[I].Field := nil;
  end;
end;

procedure TDSTableProducer.LayoutChanged;
begin
  if AcquireLayoutLock then EndLayout;
end;

procedure TDSTableProducer.LinkActive(Value: Boolean);
begin
  LayoutChanged;
end;

procedure TDSTableProducer.Notification(AComponent: TComponent; Operation: TOperation);
var
  I: Integer;
begin
  inherited Notification(AComponent, Operation);
  if (Operation = opRemove) and (FDataLink <> nil) then
    if (AComponent = DataSource)  then
      DataSource := nil
    else if (AComponent is TField) then
    begin
      BeginLayout;
      try
        for I := 0 to Columns.Count - 1 do
          with Columns[I] do
            if Field = AComponent then
              Field := nil;
      finally
        EndLayout;
      end;
    end;
end;

procedure TDSTableProducer.SetCaption(const Value: string);
begin
  FCaption := Value;
  Changed;
end;

procedure TDSTableProducer.SetCaptionAlignment(Value: THTMLCaptionAlignment);
begin
  if FCaptionAlignment <> Value then
  begin
    FCaptionAlignment := Value;
    Changed;
  end;
end;

procedure TDSTableProducer.SetColumns(Value: THTMLTableColumns);
begin
  Columns.Assign(Value);
end;

procedure TDSTableProducer.SetDataSource(Value: TDataSource);
begin
  if Value = FDatalink.Datasource then Exit;
  FDataLink.DataSource := Value;
  if Value <> nil then Value.FreeNotification(Self);
  if (Owner <> nil) and not (csLoading in Owner.ComponentState) then
    LinkActive(FDataLink.Active);
end;

procedure TDSTableProducer.SetFooter(Value: TStrings);
begin
  FFooter.Assign(Value);
  Changed;
end;

procedure TDSTableProducer.SetHeader(Value: TStrings);
begin
  FHeader.Assign(Value);
  Changed;
end;

procedure TDSTableProducer.SetMaxRows(Value: Integer);
begin
  if FMaxRows <> Value then
  begin
    FMaxRows := Value;
    Changed;
  end;
end;

procedure TDSTableProducer.SetRowAttributes(Value: THTMLTableRowAttributes);
begin
  FRowAttributes.Assign(Value);
end;

procedure TDSTableProducer.SetTableAttributes(Value: THTMLTableAttributes);
begin
  FTableAttributes.Assign(Value);
end;

function TDSTableProducer.StoreColumns: Boolean;
begin
  Result := Columns.State = csCustom;
end;

const
  Align: array[THTMLCaptionAlignment] of string =
    ('>',
     ' Align="Top">',
     ' Align="Bottom">');
  EndRow = '</TR>';

function TDSTableProducer.FormatCell(CellRow, CellColumn: Integer;
  CellData: string; const Tag: string; const BgColor: THTMLBgColor;
  Align: THTMLAlign; VAlign: THTMLVAlign; const Custom: string): string;
var
  CellAlign: THTMLAlign;
  CellVAlign: THTMLVAlign;
  CellBg: THTMLBgColor;
  CustomAttrs: string;
begin
  Result := Format('<%s', [Tag]);
  CellBg := BgColor;
  CellAlign := Align;
  CellVAlign := VAlign;
  CustomAttrs := Custom;
  DoFormatCell(CellRow, CellColumn, CellBg, CellAlign, CellVAlign, CustomAttrs,
    CellData);
  Result := Result + HTMLAlign[CellAlign];
  Result := Result + HTMLVAlign[CellVAlign];
  if CellBg <> '' then
    Result := Format('%s BgColor="%s"', [Result, CellBg]);
  if CustomAttrs <> '' then
    Result := Format('%s %s', [Result, CustomAttrs]);
  Result := Result + Format('>%s</%s>', [CellData, Tag]);
end;

function TDSTableProducer.RowHeader: string;
begin
  Result := '<TR';
  with RowAttributes do
  begin
    Result := Result + HTMLAlign[Align];
    Result := Result + HTMLVAlign[VAlign];
    if BgColor <> '' then
      Result := Format('%s BgColor="%s"', [Result, BgColor]);
    if Custom <> '' then
      Result := Format('%s %s', [Result, Custom]);
  end;
  Result := Result + '>';
end;

function TDSTableProducer.TableCaption: string;
var
  ACaption: string;
  CaptionAlign: THTMLCaptionAlignment;
begin
  ACaption := Caption;
  CaptionAlign := CaptionAlignment;
  DoGetCaption(ACaption, CaptionAlign);
  if ACaption <> '' then
    Result := Format('<Caption %s%s</Caption>', [Align[CaptionAlign], ACaption])
  else Result := '';
end;

function TDSTableProducer.TableHeader: string;
begin
  Result := '<Table';
  with TableAttributes do
  begin
    if Width > 0 then
      Result := Format('%s Width="%d%%"', [Result, Width]);
    Result := Result + HTMLAlign[Align];
    if CellSpacing > -1 then
      Result := Format('%s CellSpacing=%d', [Result, CellSpacing]);
    if CellPadding > -1 then
      Result := Format('%s CellPadding=%d', [Result, CellPadding]);
    if Border > -1 then
      Result := Format('%s Border=%d', [Result, Border]);
    if BgColor <> '' then
      Result := Format('%s BgColor="%s"', [Result, BgColor]);
    if Custom <> '' then
      Result := Format('%s %s', [Result, Custom]);
  end;
  Result := Result + '>';
end;

function TDSTableProducer.ColumnHeader: string;
var
  I: Integer;
  DisplayText: string;
  Field: TField;
  Column: THTMLTableColumn;
begin
  Result := '';
  for I := 0 to Columns.Count - 1 do
  begin
    Column := Columns[I];
    Field := Column.Field;
    if Column.Title.Caption <> '' then
      DisplayText := Column.Title.Caption
    else if Field <> nil then
      DisplayText := Field.DisplayLabel
    else DisplayText := Column.DisplayName;
    with Column.Title do
      Result := Result + FormatCell(0, I, DisplayText, 'TH',
        BgColor, Align, VAlign, Custom);
  end;
end;

{ TQueryTableProducer }

function TQueryTableProducer.Content: string;
var
  Params: TStrings;
  I: Integer;
  Name: string;
  Param: TParam;
begin
  Result := '';
  if FQuery <> nil then
  begin
    FQuery.Close;
    Params := nil;
    if Dispatcher <> nil then
      if Dispatcher.Request.MethodType = mtPost then
        Params := Dispatcher.Request.ContentFields
      else if Dispatcher.Request.MethodType = mtGet then
        Params := Dispatcher.Request.QueryFields;
    if Params <> nil then
      for I := 0 to Params.Count - 1 do
      begin
        Name := Params.Names[I];
        Param := FQuery.Params.ParamByName(Name);
        if Param <> nil then
          Param.Text := Params.Values[Name];
      end;
    FQuery.Open;
    if DoCreateContent then
      Result := FHeader.Text + HTMLTable(FQuery, Self, FMaxRows) + FFooter.Text;
  end;
end;

function TQueryTableProducer.GetDataSet: TDataSet;
begin
  Result := FQuery;
end;

procedure TQueryTableProducer.Notification(AComponent: TComponent; Operation: TOperation);
begin
  inherited Notification(AComponent, Operation);
  if (Operation = opRemove) and (AComponent = FQuery) then
    FQuery := nil;
end;

procedure TQueryTableProducer.SetDataSet(ADataSet: TDataSet);
begin
  SetQuery(ADataSet as TQuery);
end;

procedure TQueryTableProducer.SetQuery(AQuery: TQuery);
begin
  if FQuery <> AQuery then
  begin
    if AQuery <> nil then AQuery.FreeNotification(Self);
    FQuery := AQuery;
    InternalDataSource.DataSet := FQuery;
  end;
end;

{ TDataSetTableProducer }

function TDataSetTableProducer.Content: string;
begin
  Result := '';
  if FDataSet <> nil then
  begin
    if FDataSet.Active and (Columns.Count = 0) then LayoutChanged;
    if DoCreateContent then
      Result := FHeader.Text + HTMLTable(FDataSet, Self, FMaxRows) + FFooter.Text;
  end;
end;

function TDataSetTableProducer.GetDataSet: TDataSet;
begin
  Result := FDataSet;
end;

procedure TDataSetTableProducer.Notification(AComponent: TComponent; Operation: TOperation);
begin
  inherited Notification(AComponent, Operation);
  if (Operation = opRemove) and (AComponent = FDataSet) then
    FDataSet := nil;
end;

procedure TDataSetTableProducer.SetDataSet(ADataSet: TDataSet);
begin
  if FDataSet <> ADataSet then
  begin
    if ADataSet <> nil then ADataSet.FreeNotification(Self);
    FDataSet := ADataSet;
    InternalDataSource.DataSet := FDataSet;
  end;
end;

function HtmlTable(DataSet: TDataSet; DataSetHandler: TDSTableProducer;
  MaxRows: Integer): string;
var
  I, J: Integer;
  DisplayText, RowHeaderStr: string;
  Field: TField;
  Column: THTMLTableColumn;
begin
  RowHeaderStr := DataSetHandler.RowHeader;
  Result := DataSetHandler.TableHeader + DataSetHandler.TableCaption + #13#10 +
    RowHeaderStr;
  Result := Result + DataSetHandler.ColumnHeader + EndRow + #13#10;
  if DataSet.State = dsBrowse then
  begin
    J := 1;
    while (MaxRows <> 0) and not DataSet.EOF do
    begin
      Result := Result + RowHeaderStr;
      for I := 0 to DataSetHandler.Columns.Count - 1 do
      begin
        Column := DataSetHandler.Columns[I];
        Field := Column.Field;
        if Field <> nil then
          DisplayText := Field.DisplayText
        else DisplayText := '';
        with Column do
          Result := Result + DataSetHandler.FormatCell(J, I, DisplayText, 'TD',
            BgColor, Align, VAlign, Custom);
      end;
      Result := Result + EndRow + #13#10;
      DataSet.Next;
      Dec(MaxRows);
      Inc(J);
    end;
  end;
  Result := Result + '</Table>';
end;

end.
