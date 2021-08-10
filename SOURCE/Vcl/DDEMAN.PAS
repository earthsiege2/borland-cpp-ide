
{*******************************************************}
{                                                       }
{       Borland Delphi Visual Component Library         }
{                                                       }
{       Copyright (c) 1995,99 Inprise Corporation       }
{                                                       }
{*******************************************************}

unit DdeMan;

{$R-,T-,H+,X+}

interface

uses
  Windows, Classes, Graphics, Forms, Controls, DDEML, StdCtrls;

type
  TDataMode = (ddeAutomatic, ddeManual);
  TDdeServerConv = class;

  TMacroEvent = procedure(Sender: TObject; Msg: TStrings) of object;

  TDdeClientItem = class;

{ TDdeClientConv }

  TDdeClientConv = class(TComponent)
  private
    FDdeService: string;
    FDdeTopic: string;
    FConv: HConv;
    FCnvInfo: TConvInfo;
    FItems: TList;
    FHszApp: HSZ;
    FHszTopic: HSZ;
    FDdeFmt: Integer;
    FOnClose: TNotifyEvent;
    FOnOpen: TNotifyEvent;
    FAppName: string;
    FDataMode: TDataMode;
    FConnectMode: TDataMode;
    FWaitStat: Boolean;
    FFormatChars: Boolean;
    procedure SetDdeService(const Value: string);
    procedure SetDdeTopic(const Value: string);
    procedure SetService(const Value: string);
    procedure SetTopic(const Value: string);
    procedure SetConnectMode(NewMode: TDataMode);
    procedure SetFormatChars(NewFmt: Boolean);
    procedure XactComplete;
    procedure SrvrDisconnect;
    procedure DataChange(DdeDat: HDDEData; hszIt: HSZ);
  protected
    function CreateDdeConv(FHszApp: HSZ; FHszTopic: HSZ): Boolean;
    function GetCliItemByName(const ItemName: string): TPersistent;
    function GetCliItemByCtrl(ACtrl: TDdeClientItem): TPersistent;
    procedure Loaded; override;
    procedure DefineProperties(Filer: TFiler); override;
    procedure ReadLinkInfo(Reader: TReader);
    procedure WriteLinkInfo(Writer: TWriter);
    function OnSetItem(aCtrl: TDdeClientItem; const S: string): Boolean;
    procedure OnAttach(aCtrl: TDdeClientItem);
    procedure OnDetach(aCtrl: TDdeClientItem);
    procedure Close; dynamic;
    procedure Open; dynamic;
    function ChangeLink(const App, Topic, Item: string): Boolean;
    procedure ClearItems;
    procedure Notification(AComponent: TComponent;
      Operation: TOperation); override;
  public
    constructor Create(AOwner: TComponent); override;
    destructor Destroy; override;
    function PasteLink: Boolean;
    function OpenLink: Boolean;
    function SetLink(const Service, Topic: string): Boolean;
    procedure CloseLink;
    function StartAdvise: Boolean;
    function PokeDataLines(const Item: string; Data: TStrings): Boolean;
    function PokeData(const Item: string; Data: PChar): Boolean;
    function ExecuteMacroLines(Cmd: TStrings; waitFlg: Boolean): Boolean;
    function ExecuteMacro(Cmd: PChar; waitFlg: Boolean): Boolean;
    function RequestData(const Item: string): PChar;
    property DdeFmt: Integer read FDdeFmt;
    property WaitStat: Boolean read FWaitStat;
    property Conv: HConv read FConv;
    property DataMode: TDataMode read FDataMode write FDataMode;
  published
    property ServiceApplication: string read FAppName write FAppName;
    property DdeService: string read FDdeService write SetDdeService;
    property DdeTopic: string read FDdeTopic write SetDdeTopic;
    property ConnectMode: TDataMode read FConnectMode write SetConnectMode default ddeAutomatic;
    property FormatChars: Boolean read FFormatChars write SetFormatChars default False;
    property OnClose: TNotifyEvent read FOnClose write FOnClose;
    property OnOpen: TNotifyEvent read FOnOpen write FOnOpen;
  end;

{ TDdeClientItem }

  TDdeClientItem = class(TComponent)
  private
    FLines: TStrings;
    FDdeClientConv: TDdeClientConv;
    FDdeClientItem: string;
    FOnChange: TNotifyEvent;
    function GetText: string;
    procedure SetDdeClientItem(const Val: string);
    procedure SetDdeClientConv(Val: TDdeClientConv);
    procedure SetText(const S: string);
    procedure SetLines(L: TStrings);
    procedure OnAdvise;
  protected
    procedure Notification(AComponent: TComponent;
      Operation: TOperation); override;
  public
    constructor Create(AOwner: TComponent); override;
    destructor Destroy; override;
  published
    property Text: string read GetText write SetText;
    property Lines: TStrings read FLines write SetLines;
    property DdeConv: TDdeClientConv read FDdeClientConv write SetDdeClientConv;
    property DdeItem: string read FDdeClientItem write SetDdeClientItem;
    property OnChange: TNotifyEvent read FOnChange write FOnChange;
  end;

{ TDdeServerConv }

  TDdeServerConv = class(TComponent)
  private
    FOnOpen: TNotifyEvent;
    FOnClose: TNotifyEvent;
    FOnExecuteMacro: TMacroEvent;
  protected
    procedure Connect; dynamic;
    procedure Disconnect; dynamic;
  public
    constructor Create(AOwner: TComponent); override;
    destructor Destroy; override;
    function ExecuteMacro(Data: HDdeData): LongInt;
  published
    property OnOpen: TNotifyEvent read FOnOpen write FOnOpen;
    property OnClose: TNotifyEvent read FOnClose write FOnClose;
    property OnExecuteMacro: TMacroEvent read FOnExecuteMacro write FOnExecuteMacro;
  end;

{ TDdeServerItem }

  TDdeServerItem = class(TComponent)
  private
    FLines: TStrings;
    FServerConv: TDdeServerConv;
    FOnChange: TNotifyEvent;
    FOnPokeData: TNotifyEvent;
    FFmt: Integer;
    procedure ValueChanged;
  protected
    function GetText: string;
    procedure SetText(const Item: string);
    procedure SetLines(Value: TStrings);
    procedure SetServerConv(SConv: TDdeServerConv);
    procedure Notification(AComponent: TComponent;
      Operation: TOperation); override;
  public
    constructor Create(AOwner: TComponent); override;
    destructor Destroy; override;
    function PokeData(Data: HDdeData): LongInt;
    procedure CopyToClipboard;
    procedure Change; dynamic;
    property Fmt: Integer read FFmt;
  published
    property ServerConv: TDdeServerConv read FServerConv write SetServerConv;
    property Text: string read GetText write SetText;
    property Lines: TStrings read FLines write SetLines;
    property OnChange: TNotifyEvent read FOnChange write FOnChange;
    property OnPokeData: TNotifyEvent read FOnPokeData write FOnPokeData;
  end;

{ TDdeMgr }

  TDdeMgr = class(TComponent)
  private
    FAppName: string;
    FHszApp: HSZ;
    FConvs: TList;
    FCliConvs: TList;
    FConvCtrls: TList;
    FDdeInstId: Longint;
    FLinkClipFmt: Word;
    procedure Disconnect(DdeSrvrConv: TComponent);
    function GetSrvrConv(const Topic: string ): TComponent;
    function AllowConnect(hszApp: HSZ; hszTopic: HSZ): Boolean;
    function AllowWildConnect(hszApp: HSZ; hszTopic: HSZ): HDdeData;
    function Connect(Conv: HConv; hszTopic: HSZ; SameInst: Boolean): Boolean;
    procedure PostDataChange(const Topic: string; Item: string);
    procedure SetAppName(const Name: string);
    procedure ResetAppName;
    function  GetServerConv(const Topic: string): TDdeServerConv;
    procedure InsertServerConv(SConv: TDdeServerConv);
    procedure RemoveServerConv(SConv: TDdeServerConv);
//    procedure DoError;
    function  GetForm(const Topic: string): TForm;
  public
    constructor Create(AOwner: TComponent); override;
    destructor Destroy; override;
    function GetExeName: string;     // obsolete
    property DdeInstId: LongInt read FDdeInstId write FDdeInstId;
    property AppName: string read FAppName write SetAppName;
    property LinkClipFmt: Word read FLinkClipFmt;
  end;

  function GetPasteLinkInfo(var Service: string; var Topic: string;
    var Item: string): Boolean;
var
  ddeMgr: TDdeMgr;

implementation

uses SysUtils, Dialogs, Consts, Clipbrd;

type
  EDdeError = class(Exception);
  TDdeSrvrConv = class;

{ TDdeSrvrItem }

  TDdeSrvrItem = class(TComponent)
  private
    FConv: TDdeSrvrConv;
    FItem: string;
    FHszItem: HSZ;
    FSrvr: TDdeServerItem;
  protected
    procedure SetItem(const Value: string);
  public
    constructor Create(AOwner: TComponent); override;
    destructor Destroy; override;
    function RequestData(Fmt: Word): HDdeData;
    procedure PostDataChange;
    property Conv: TDdeSrvrConv read FConv write FConv;
    property Item: string read FItem write SetItem;
    property Srvr: TDdeServerItem read FSrvr write FSrvr;
    property HszItem: HSZ read FHszItem;
  end;

{ TDdeSrvrConv }

  TDdeSrvrConv = class(TComponent)
  private
    FTopic: string;
    FHszTopic: HSZ;
    FForm: TForm;
    FSConv: TDdeServerConv;
    FConv: HConv;
//    FCnvInfo: TConvInfo;
//    FDdeFmt: Integer;
    FItems: TList;
  protected
    function GetControl(WinCtrl: TWinControl; DdeConv: TDdeServerConv; const ItemName: string): TDdeServerItem;
    function GetSrvrItem(hszItem: HSZ): TDdeSrvrItem;
  public
    constructor Create(AOwner: TComponent); override;
    destructor Destroy; override;
    function RequestData(Conv: HConv; hszTopic: HSZ; hszItem: HSZ;
      Fmt: Word): HDdeData;
    function AdvStart(Conv: HConv; hszTopic: HSZ; hszItem: HSZ;
      Fmt: Word): Boolean;
    procedure AdvStop(Conv: HConv; hszTopic: HSZ; hszItem: HSZ);
    function PokeData(Conv: HConv; hszTopic: HSZ; hszItem: HSZ; Data: HDdeData;
      Fmt: Integer): LongInt;
    function ExecuteMacro(Conv: HConv; hszTopic: HSZ; Data: HDdeData): Integer;
    function GetItem(const ItemName: string): TDdeSrvrItem;
    property Conv: HConv read FConv;
    property Form: TForm read FForm;
    property SConv: TDdeServerConv read FSConv;
    property Topic: string read FTopic write FTopic;
    property HszTopic: HSZ read FHszTopic;
  end;

{ TDdeCliItem }

  TDdeCliItem = class(TPersistent)
  protected
    FItem: string;
    FHszItem: HSZ;
    FCliConv: TDdeClientConv;
    FCtrl: TDdeClientItem;
    function StartAdvise: Boolean;
    function StopAdvise: Boolean;
    procedure StoreData(DdeDat: HDDEData);
    procedure DataChange;
    function AccessData(DdeDat: HDDEData; pDataLen: PDWORD): Pointer;
    procedure ReleaseData(DdeDat: HDDEData);
  public
    constructor Create(ADS: TDdeClientConv);
    destructor Destroy; override;
    function RefreshData: Boolean;
    function SetItem(const S: string): Boolean;
    procedure SrvrDisconnect;
    property HszItem: HSZ read FHszItem;
    property Control: TDdeClientItem read FCtrl write FCtrl;
  published
    property Item: string read FItem;
  end;

procedure DDECheck(Success: Boolean);
var
  err: Integer;
  ErrStr: string;
begin
  if Success then Exit;
  err := DdeGetLastError(DDEMgr.DdeInstId);
  case err of
    DMLERR_LOW_MEMORY, DMLERR_MEMORY_ERROR:
      ErrStr := Format(SDdeMemErr, [err]);
    DMLERR_NO_CONV_ESTABLISHED:
      ErrStr := Format(SDdeConvErr, [err]);
  else
    ErrStr := Format(SDdeErr, [err]);
  end;
  raise EDdeError.Create(ErrStr);
end;

function DdeMgrCallBack(CallType, Fmt : UINT; Conv: HConv; hsz1, hsz2: HSZ;
  Data: HDDEData; Data1, Data2: DWORD): HDDEData; stdcall;
var
  ci: TConvInfo;
  ddeCli: TComponent;
  ddeSrv: TDdeSrvrConv;
  ddeObj: TComponent;
  xID: DWORD;
begin
  Result := 0;
  case CallType of
    XTYP_CONNECT:
      Result := HDdeData(ddeMgr.AllowConnect(hsz2, hsz1));
    XTYP_WILDCONNECT:
      Result := ddeMgr.AllowWildConnect(hsz2, hsz1);
    XTYP_CONNECT_CONFIRM:
      ddeMgr.Connect(Conv, hsz1, Boolean(Data2));
  end;
  if Conv <> 0 then
  begin
    ci.cb := sizeof(TConvInfo);
    if CallType = XTYP_XACT_COMPLETE then
      xID := Data1
    else
      xID := QID_SYNC;
    if DdeQueryConvInfo(Conv, xID, @ci) = 0 then Exit;
    case CallType of
      XTYP_ADVREQ:
        begin
          ddeSrv := TDdeSrvrConv(ci.hUser);
          Result := ddeSrv.RequestData(Conv, hsz1, hsz2, Fmt);
        end;
      XTYP_REQUEST:
        begin
          ddeSrv := TDdeSrvrConv(ci.hUser);
          Result := ddeSrv.RequestData(Conv, hsz1, hsz2, Fmt);
        end;
      XTYP_ADVSTOP:
        begin
          ddeSrv := TDdeSrvrConv(ci.hUser);
          ddeSrv.AdvStop(Conv, hsz1, hsz2);
        end;
      XTYP_ADVSTART:
        begin
          ddeSrv := TDdeSrvrConv(ci.hUser);
          Result := HDdeData(ddeSrv.AdvStart(Conv, hsz1, hsz2, Fmt));
        end;
      XTYP_POKE:
        begin
          ddeSrv := TDdeSrvrConv(ci.hUser);
          Result := HDdeData(ddeSrv.PokeData(Conv, hsz1, hsz2, Data, Fmt));
        end;
      XTYP_EXECUTE:
        begin
          ddeSrv := TDdeSrvrConv(ci.hUser);
          Result := HDdeData(ddeSrv.ExecuteMacro(Conv, hsz1, Data));
        end;
      XTYP_XACT_COMPLETE:
        begin
          ddeCli := TComponent(ci.hUser);
          if ddeCli <> nil then TDdeClientConv(ddeCli).XactComplete
        end;
      XTYP_ADVDATA:
        begin
          ddeCli := TComponent(ci.hUser);
          TDdeClientConv(ddeCli).DataChange(Data, hsz2);
        end;
      XTYP_DISCONNECT:
        begin
          ddeObj := TComponent(ci.hUser);
          if ddeObj <> nil then
          begin
            if ddeObj is TDdeClientConv then
              TDdeClientConv(ddeObj).SrvrDisconnect
            else
              ddeMgr.Disconnect(ddeObj);
          end;
        end;
    end;
  end;
end;

function GetPasteLinkInfo(var Service, Topic, Item: string): Boolean;
var
  hData: THandle;
  pData: Pointer;
  P: PChar;
begin
  Result := False;
  Clipboard.Open;
  hData := Clipboard.GetAsHandle(ddeMgr.LinkClipFmt);
  if hData <> 0 then
  begin
    pData := GlobalLock(hData);
    try
      P := PChar(pData);
      Service := PChar(pData);
      P := P + Length(Service) + 1;
      Topic := P;
      P := P + Length(Topic) + 1;
      Item := P;
    finally
      GlobalUnlock(hData);
    end;
    Result := True;
  end;
  Clipboard.Close;
end;


{ TDdeMgr }

constructor TDdeMgr.Create(AOwner: TComponent);
begin
  inherited Create(AOwner);
  FLinkClipFmt := RegisterClipboardFormat('Link');
  FDdeInstId := 0;
  DDECheck(DdeInitialize(FDdeInstId, DdeMgrCallBack, APPCLASS_STANDARD, 0) = 0);
  FConvs := TList.Create;
  FCliConvs := TList.Create;
  FConvCtrls := TList.Create;
  AppName := ParamStr(0);
end;

destructor TDdeMgr.Destroy;
var
  I: Integer;
begin
  if FConvs <> nil then
  begin
    for I := 0 to FConvs.Count - 1 do
      TDdeSrvrConv(FConvs[I]).Free;
    FConvs.Free;
    FConvs := nil;
  end;
  if FCliConvs <> nil then
  begin
    for I := 0 to FCliConvs.Count - 1 do
      TDdeSrvrConv(FCliConvs[I]).Free;
    FCliConvs.Free;
    FCliConvs := nil;
  end;
  if FConvCtrls <> nil then
  begin
    FConvCtrls.Free;
    FConvCtrls := nil;
  end;
  ResetAppName;
  DdeUnInitialize(FDdeInstId);
  inherited Destroy;
end;

function TDdeMgr.AllowConnect(hszApp: HSZ; hszTopic: HSZ): Boolean;
var
  Topic: string;
  Buffer: array[0..4095] of Char;
  Form: TForm;
  SConv: TDdeServerConv;
begin
  Result := False;
  if (hszApp = 0) or (DdeCmpStringHandles(hszApp, FHszApp) = 0)  then
  begin
    SetString(Topic, Buffer, DdeQueryString(FDdeInstId, hszTopic, Buffer,
      SizeOf(Buffer), CP_WINANSI));
    SConv := GetServerConv(Topic);
    if SConv <> nil then
      Result := True
    else begin
      Form := GetForm(Topic);
      if Form <> nil then Result := True;
    end;
  end;
end;

function TDdeMgr.AllowWildConnect(hszApp: HSZ; hszTopic: HSZ): HDdeData;
var
  conns: packed array[0..1] of THSZPair;
begin
  Result := 0;
  if hszTopic = 0 then Exit;
  if AllowConnect(hszApp, hszTopic) = True then
  begin
    conns[0].hszSvc := FHszApp;
    conns[0].hszTopic := hszTopic;
    conns[1].hszSvc := 0;
    conns[1].hszTopic := 0;
    Result := DdeCreateDataHandle(ddeMgr.DdeInstId, @conns,
      2 * sizeof(THSZPair), 0, 0, CF_TEXT, 0);
  end;
end;

function TDdeMgr.Connect(Conv: HConv; hszTopic: HSZ; SameInst: Boolean): Boolean;
var
  Topic: string;
  Buffer: array[0..4095] of Char;
  DdeConv: TDdeSrvrConv;
begin
  DdeConv := TDdeSrvrConv.Create(Self);
  SetString(Topic, Buffer, DdeQueryString(FDdeInstId, hszTopic, Buffer,
    SizeOf(Buffer), CP_WINANSI));
  DdeConv.Topic := Topic;
  DdeConv.FSConv := GetServerConv(Topic);
  if DdeConv.FSConv = nil then
    DdeConv.FForm := GetForm(Topic);
  DdeConv.FConv := Conv;
  DdeSetUserHandle(Conv, QID_SYNC, DWORD(DdeConv));
  FConvs.Add(DdeConv);
  if DdeConv.FSConv <> nil then DdeConv.FSConv.Connect;
  Result := True;
end;

procedure TDdeMgr.Disconnect(DdeSrvrConv: TComponent);
var
  DdeConv: TDdeSrvrConv;
begin
  DdeConv := TDdeSrvrConv(DdeSrvrConv);
  if DdeConv.FSConv <> nil then DdeConv.FSConv.Disconnect;
  if DdeConv.FConv <> 0 then DdeSetUserHandle(DdeConv.FConv, QID_SYNC, 0);
  DdeConv.FConv := 0;
  if FConvs <> nil then
  begin
    FConvs.Remove(DdeConv);
    DdeConv.Free;
  end;
end;

function TDdeMgr.GetExeName: string;
begin
  Result := ParamStr(0);
end;

procedure TDdeMgr.SetAppName(const Name: string);
var
  Dot: Integer;
begin
  ResetAppName;
  FAppName := ExtractFileName(Name);
  Dot := Pos('.', FAppName);
  if Dot <> 0 then
    Delete(FAppName, Dot, Length(FAppName));
  FHszApp := DdeCreateStringHandle(FDdeInstId, PChar(FAppName), CP_WINANSI);
  DdeNameService(FDdeInstId, FHszApp, 0, DNS_REGISTER);
end;

procedure TDdeMgr.ResetAppName;
begin
  if FHszApp <> 0 then
  begin
    DdeNameService(FDdeInstId, FHszApp, 0, DNS_UNREGISTER);
    DdeFreeStringHandle(FDdeInstId, FHszApp);
  end;
  FHszApp := 0;
end;

function TDdeMgr.GetServerConv(const Topic: string): TDdeServerConv;
var
  I: Integer;
  SConv: TDdeServerConv;
begin
  Result := nil;
  for I := 0 to FConvCtrls.Count - 1 do
  begin
    SConv := TDdeServerConv(FConvCtrls[I]);
    if AnsiCompareText(SConv.Name, Topic) = 0 then
    begin
      Result := SConv;
      Exit;
    end;
  end;
end;

function TDdeMgr.GetForm(const Topic: string): TForm;
var
  I: Integer;
  Form: TForm;
begin
  Result := nil;
  for I := 0 to Screen.FormCount - 1 do
  begin
    Form := TForm(Screen.Forms[I]);
    if AnsiCompareText(Form.Caption, Topic) = 0 then
    begin
      Result := Form;
      Exit;
    end;
  end;
end;

function TDdeMgr.GetSrvrConv(const Topic: string ): TComponent;
var
  I: Integer;
  Conv: TDdeSrvrConv;
begin
  Result := nil;
  for I := 0 to FConvs.Count - 1 do
  begin
    Conv := FConvs[I];
    if AnsiCompareText(Conv.Topic, Topic) = 0 then
    begin
      Result := Conv;
      Exit;
    end;
  end;
end;

procedure TDdeMgr.PostDataChange(const Topic: string; Item: string);
var
  Conv: TDdeSrvrConv;
  Itm: TDdeSrvrItem;
begin
  Conv := TDdeSrvrConv(GetSrvrConv (Topic));
  If Conv <> nil then
  begin
    Itm := Conv.GetItem(Item);
    if Itm <> nil then Itm.PostDataChange;
  end;
end;

procedure TDdeMgr.InsertServerConv(SConv: TDdeServerConv);
begin
  FConvCtrls.Insert(FConvCtrls.Count, SConv);
end;

procedure TDdeMgr.RemoveServerConv(SConv: TDdeServerConv);
begin
  FConvCtrls.Remove(SConv);
end;

{procedure TDdeMgr.DoError;
begin
  DDECheck(False);
end;}

constructor TDdeClientConv.Create(AOwner: TComponent);
begin
  inherited Create(AOwner);
  FItems := TList.Create;
end;

destructor TDdeClientConv.Destroy;
begin
  CloseLink;
  inherited Destroy;
  FItems.Free;
  FItems := nil;
end;

procedure TDdeClientConv.DefineProperties(Filer: TFiler);
begin
  inherited DefineProperties(Filer);
  Filer.DefineProperty('LinkInfo', ReadLinkInfo, WriteLinkInfo,
    not ((DdeService = '') and (DdeTopic = '')));
end;

procedure TDdeClientConv.Loaded;
var
  Service, Topic: string;
begin
  inherited Loaded;
  Service := DdeService;
  Topic := DdeTopic;
  if (Length(Service) <> 0) and (ConnectMode <> ddeManual) then
    ChangeLink(Service, Topic, '');
end;

procedure TDdeClientConv.ReadLinkInfo (Reader: TReader);
var
  Value: string;
  Text: string;
  Temp: Integer;
begin
  Reader.ReadListBegin;
  while not Reader.EndOfList do
  begin
    Value := Reader.ReadString;
    Temp := Pos(' ', Value);
    Text := Copy(Value, Temp + 1, Length (Value) - Temp);
    case Value[1] of
      'S': SetService(Text);
      'T': SetTopic(Text);
    end;
  end;
  Reader.ReadListEnd;
end;

procedure TDdeClientConv.WriteLinkInfo (Writer: TWriter);
var
  Value: string;
begin
  Writer.WriteListBegin;
  Value := DdeService;
  Writer.WriteString(Format('Service %s', [Value]));
  Value := DdeTopic;
  Writer.WriteString(Format('Topic %s', [Value]));
  Writer.WriteListEnd;
end;

procedure TDdeClientConv.OnAttach(aCtrl: TDdeClientItem);
var
  ItemLnk: TDdeCliItem;
begin
  ItemLnk := TDdeCliItem.Create(Self);
  FItems.Insert(FItems.Count, ItemLnk);
  ItemLnk.Control := aCtrl;
  ItemLnk.SetItem('');
end;

procedure TDdeClientConv.OnDetach(aCtrl: TDdeClientItem);
var
  ItemLnk: TDdeCliItem;
begin
  ItemLnk := TDdeCliItem(GetCliItemByCtrl(aCtrl));
  if ItemLnk <> nil then
  begin
    ItemLnk.SetItem('');
    FItems.Remove(ItemLnk);
    ItemLnk.Free;
  end;
end;

function TDdeClientConv.OnSetItem(aCtrl: TDdeClientItem; const S: string): Boolean;
var
  ItemLnk: TDdeCliItem;
begin
  Result := True;
  ItemLnk := TDdeCliItem(GetCliItemByCtrl(aCtrl));

  if (ItemLnk = nil) and (Length(S) > 0) then
  begin
    OnAttach (aCtrl);
    ItemLnk := TDdeCliItem(GetCliItemByCtrl(aCtrl));
  end;

  if (ItemLnk <> nil) and (Length(S) = 0) then
  begin
    OnDetach (aCtrl);
  end
  else if ItemLnk <> nil then
  begin
    Result := ItemLnk.SetItem(S);
    if Not (Result) and Not (csLoading in ComponentState) then
      OnDetach (aCtrl);  {error occurred, do cleanup}
  end;
end;

function TDdeClientConv.GetCliItemByCtrl(ACtrl: TDdeClientItem): TPersistent;
var
  ItemLnk: TDdeCliItem;
  I: word;
begin
  Result := nil;
  I := 0;
  while I < FItems.Count do
  begin
    ItemLnk := FItems[I];
    if ItemLnk.Control = aCtrl then
    begin
      Result := ItemLnk;
      Exit;
    end;
    Inc(I);
  end;
end;

function TDdeClientConv.PasteLink: Boolean;
var
  Service, Topic, Item: string;
begin
  if GetPasteLinkInfo(Service, Topic, Item) = True then
    Result := ChangeLink(Service, Topic, Item) else
    Result := False;
end;

function TDdeClientConv.ChangeLink(const App, Topic, Item: string): Boolean;
begin
  CloseLink;
  SetService(App);
  SetTopic(Topic);
  Result := OpenLink;
  if Not Result then
  begin
    SetService('');
    SetTopic('');
  end;
end;

function TDdeClientConv.OpenLink: Boolean;
var
  CharVal: array[0..255] of Char;
  Res: Boolean;
begin
  Result := False;
  if FConv <> 0 then Exit;

  if (Length(DdeService) = 0) and (Length(DdeTopic) = 0) then
  begin
    ClearItems;
    Exit;
  end;

  if FHszApp = 0 then
  begin
    StrPCopy(CharVal, DdeService);
    FHszApp := DdeCreateStringHandle(ddeMgr.DdeInstId, CharVal, CP_WINANSI);
  end;
  if FHszTopic = 0 then
  begin
    StrPCopy(CharVal, DdeTopic);
    FHszTopic := DdeCreateStringHandle(ddeMgr.DdeInstId, CharVal, CP_WINANSI);
  end;
  Res := CreateDdeConv(FHszApp, FHszTopic);
  if Not Res then
  begin
    if Not((Length(DdeService) = 0) and
      (Length(ServiceApplication) = 0)) then
    begin
      if Length(ServiceApplication) <> 0 then
        StrPCopy(CharVal, ServiceApplication)
      else
        StrPCopy(CharVal, DdeService + ' ' + DdeTopic);
      if WinExec(CharVal, SW_SHOWMINNOACTIVE) >= 32 then
        Res := CreateDdeConv(FHszApp, FHszTopic);
    end;
  end;
  if Not Res then
  begin
    ClearItems;
    Exit;
  end;
  if FCnvInfo.wFmt <> 0 then FDdeFmt := FCnvInfo.wFmt
  else FDdeFmt := CF_TEXT;
  if StartAdvise = False then Exit;
  Open;
  DataChange(0, 0);
  Result := True;
end;

procedure TDdeClientConv.CloseLink;
var
  OldConv: HConv;
begin
  if FConv <> 0 then
  begin
    OldConv := FConv;
    SrvrDisconnect;
    FConv := 0;
    DdeSetUserHandle(OldConv, QID_SYNC, 0);
    DdeDisconnect(OldConv);
  end;

  if FHszApp <> 0 then
  begin
    DdeFreeStringHandle(ddeMgr.DdeInstId, FHszApp);
    FHszApp := 0;
  end;

  if FHszTopic <> 0 then
  begin
    DdeFreeStringHandle(ddeMgr.DdeInstId, FHszTopic);
    FHszTopic := 0;
  end;
  SetService('');
  SetTopic('');
end;

procedure TDdeClientConv.ClearItems;
var
  ItemLnk: TDdeCliItem;
  i: word;
begin
  if FItems.Count = 0 then Exit;

  for I := 0 to FItems.Count - 1 do
  begin
    ItemLnk := TDdeCliItem(FItems [0]);
    ItemLnk.Control.DdeItem := EmptyStr;
  end;
end;

function TDdeClientConv.CreateDdeConv(FHszApp: HSZ; FHszTopic: HSZ): Boolean;
var
  Context: TConvContext;
begin
  FillChar(Context, SizeOf(Context), 0);
  with Context do
  begin
    cb := SizeOf(TConvConText);
    iCodePage := CP_WINANSI;
  end;
  FConv := DdeConnect(ddeMgr.DdeInstId, FHszApp, FHszTopic, @Context);
  Result := FConv <> 0;
  if Result then
  begin
    FCnvInfo.cb := sizeof(TConvInfo);
    DdeQueryConvInfo(FConv, QID_SYNC, @FCnvInfo);
    DdeSetUserHandle(FConv, QID_SYNC, LongInt(Self));
  end;
end;

function TDdeClientConv.StartAdvise: Boolean;
var
  ItemLnk: TDdeCliItem;
  i: word;
begin
  Result := False;
  if FConv = 0 then Exit;

  i := 0;
  while i < FItems.Count do
  begin
    ItemLnk := TDdeCliItem(FItems [i]);
    if Not ItemLnk.StartAdvise then
    begin
      ItemLnk.Control.DdeItem := EmptyStr;
    end else
      Inc(i);
    if i >= FItems.Count then
      break;
  end;
  Result := True;
end;

function TDdeClientConv.ExecuteMacroLines(Cmd: TStrings; waitFlg: Boolean): Boolean;
begin
  Result := False;
  if (FConv = 0) or FWaitStat then Exit;
  Result := ExecuteMacro(PChar(Cmd.Text), waitFlg);
end;

function TDdeClientConv.ExecuteMacro(Cmd: PChar; waitFlg: Boolean): Boolean;
var
  hszCmd: HDDEData;
  hdata: HDDEData;
  ddeRslt: LongInt;
begin
  Result := False;
  if (FConv = 0) or FWaitStat then Exit;
  hszCmd := DdeCreateDataHandle(ddeMgr.DdeInstId, Cmd, StrLen(Cmd) + 1,
    0, 0, FDdeFmt, 0);
  if hszCmd = 0 then Exit;
  if waitFlg = True then FWaitStat := True;
  hdata := DdeClientTransaction(Pointer(hszCmd), DWORD(-1), FConv, 0, FDdeFmt,
     XTYP_EXECUTE, TIMEOUT_ASYNC, @ddeRslt);
  if hdata = 0 then FWaitStat := False
  else Result := True;
end;

function TDdeClientConv.PokeDataLines(const Item: string; Data: TStrings): Boolean;
begin
  Result := False;
  if (FConv = 0) or FWaitStat then Exit;
  Result := PokeData(Item, PChar(Data.Text));
end;

function TDdeClientConv.PokeData(const Item: string; Data: PChar): Boolean;
var
  hszDat: HDDEData;
  hdata: HDDEData;
  hszItem: HSZ;
begin
  Result := False;
  if (FConv = 0) or FWaitStat then Exit;
  hszItem := DdeCreateStringHandle(ddeMgr.DdeInstId, PChar(Item), CP_WINANSI);
  if hszItem = 0 then Exit;
  hszDat := DdeCreateDataHandle (ddeMgr.DdeInstId, Data, StrLen(Data) + 1,
    0, hszItem, FDdeFmt, 0);
  if hszDat <> 0 then
  begin
    hdata := DdeClientTransaction(Pointer(hszDat), DWORD(-1), FConv, hszItem,
      FDdeFmt, XTYP_POKE, TIMEOUT_ASYNC, nil);
    Result := hdata <> 0;
  end;
  DdeFreeStringHandle (ddeMgr.DdeInstId, hszItem);
end;

function TDdeClientConv.RequestData(const Item: string): PChar;
var
  hData: HDDEData;
  ddeRslt: LongInt;
  hItem: HSZ;
  pData: Pointer;
  Len: Integer;
begin
  Result := nil;
  if (FConv = 0) or FWaitStat then Exit;
  hItem := DdeCreateStringHandle(ddeMgr.DdeInstId, PChar(Item), CP_WINANSI);
  if hItem <> 0 then
  begin
    hData := DdeClientTransaction(nil, 0, FConv, hItem, FDdeFmt,
      XTYP_REQUEST, 10000, @ddeRslt);
    DdeFreeStringHandle(ddeMgr.DdeInstId, hItem);
    if hData <> 0 then
    try
      pData := DdeAccessData(hData, @Len);
      if pData <> nil then
      try
        Result := StrAlloc(Len + 1);
        Move(pData^, Result^, len);    // data is binary, may contain nulls
        Result[len] := #0;
      finally
        DdeUnaccessData(hData);
      end;
    finally
      DdeFreeDataHandle(hData);
    end;
  end;
end;

function TDdeClientConv.GetCliItemByName(const ItemName: string): TPersistent;
var
  ItemLnk: TDdeCliItem;
  i: word;
begin
  Result := nil;
  i := 0;
  while i < FItems.Count do
  begin
    ItemLnk := TDdeCliItem(FItems[i]);
    if ItemLnk.Item = ItemName then
    begin
      Result := ItemLnk;
      Exit;
    end;
    Inc(i);
  end;
end;

procedure TDdeClientConv.XactComplete;
begin
   FWaitStat := False;
end;

procedure TDdeClientConv.SrvrDisconnect;
var
  ItemLnk: TDdeCliItem;
  i: word;
begin
  if FConv <> 0 then Close;
  FConv := 0;
  i := 0;
  while i < FItems.Count do
  begin
    ItemLnk := TDdeCliItem(FItems [i]);
    ItemLnk.SrvrDisconnect;
    inc(i);
  end;
end;

procedure TDdeClientConv.DataChange(DdeDat: HDDEData; hszIt: HSZ);
var
  ItemLnk: TDdeCliItem;
  i: word;
begin
  i := 0;
  while i < FItems.Count do
  begin
    ItemLnk := TDdeCliItem(FItems [i]);
    if (hszIt = 0) or (ItemLnk.HszItem = hszIt) then
    begin
        { data has changed and we found a link that might be interested }
      ItemLnk.StoreData(DdeDat);
    end;
    Inc(i);
  end;
end;

function TDdeClientConv.SetLink(const Service, Topic: string): Boolean;
begin
  CloseLink;
  if FConnectMode = ddeAutomatic then
    Result := ChangeLink(Service, Topic, '')
  else begin
    SetService(Service);
    SetTopic(Topic);
    DataChange(0,0);
    Result := True;
  end;
end;

procedure TDdeClientConv.SetConnectMode(NewMode: TDataMode);
begin
  if FConnectMode <> NewMode then
  begin
    if (NewMode = ddeAutomatic) and (Length(DdeService) <> 0) and
      (Length(DdeTopic) <> 0) and not OpenLink then
      raise Exception.CreateRes(@SDdeNoConnect);
    FConnectMode := NewMode;
  end;
end;

procedure TDdeClientConv.SetFormatChars(NewFmt: Boolean);
begin
  if FFormatChars <> NewFmt then
  begin
    FFormatChars := NewFmt;
    if FConv <> 0 then DataChange(0, 0);
  end;
end;

procedure TDdeClientConv.SetDdeService(const Value: string);
begin
end;

procedure TDdeClientConv.SetDdeTopic(const Value: string);
begin
end;

procedure TDdeClientConv.SetService(const Value: string);
begin
  FDdeService := Value;
end;

procedure TDdeClientConv.SetTopic(const Value: string);
begin
  FDdeTopic := Value;
end;

procedure TDdeClientConv.Close;
begin
  if Assigned(FOnClose) then FOnClose(Self);
end;

procedure TDdeClientConv.Open;
begin
  if Assigned(FOnOpen) then FOnOpen(Self);
end;

procedure TDdeClientConv.Notification(AComponent: TComponent;
  Operation: TOperation);
var
  ItemLnk: TDdeCliItem;
  i: word;
begin
  inherited Notification(AComponent, Operation);
  if (Operation = opRemove) and (FItems <> nil) then
  begin
    i := 0;
    while i < FItems.Count do
    begin
      ItemLnk := TDdeCliItem(FItems [i]);
      if (AComponent = ItemLnk.Control) then
        ItemLnk.Control.DdeItem := EmptyStr;
      if i >= FItems.Count then break;
      Inc(I);
    end;
  end;
end;

constructor TDdeClientItem.Create(AOwner: TComponent);
begin
  inherited Create(AOwner);
  FLines := TStringList.Create;
end;

destructor TDdeClientItem.Destroy;
begin
  FLines.Free;
  inherited Destroy;
end;

procedure TDdeClientItem.SetDdeClientConv(Val: TDdeClientConv);
var
  OldItem: string;
begin
  if Val <> FDdeClientConv then
  begin
    OldItem := DdeItem;
    FDdeClientItem := '';
    if FDdeClientConv <> nil then
      FDdeClientConv.OnDetach (Self);

    FDdeClientConv := Val;
    if FDdeClientConv <> nil then
    begin
      FDdeClientConv.FreeNotification(Self);
      if Length(OldItem) <> 0 then SetDdeClientItem (OldItem);
    end;
  end;
end;

procedure TDdeClientItem.SetDdeClientItem(const Val: string);
begin
  if FDdeClientConv <> nil then
  begin
    FDdeClientItem := Val;
    if Not FDdeClientConv.OnSetItem (Self, Val) then
    begin
      if Not (csLoading in ComponentState) or
        not ((FDdeClientConv.FConv = 0) and
        (FDdeClientConv.ConnectMode = ddeManual)) then
        FDdeClientItem := '';
    end;
  end
  else if (csLoading in ComponentState) then
    FDdeClientItem := Val;
end;

procedure TDdeClientItem.Notification(AComponent: TComponent;
  Operation: TOperation);
begin
  inherited Notification(AComponent, Operation);
  if (Operation = opRemove) and (AComponent = FDdeClientConv) then
  begin
    FDdeClientConv.OnDetach (Self);
    FDdeClientConv := nil;
    FDdeClientItem := '';
  end;
end;

procedure TDdeClientItem.OnAdvise;
begin
  if csDesigning in ComponentState then
  begin
    if Owner.InheritsFrom (TForm) and (TForm(Owner).Designer <> nil) then
      TForm(Owner).Designer.Modified;
  end;
  if Assigned(FOnChange) then FOnChange(Self);
end;

function TDdeClientItem.GetText: string;
begin
  if FLines.Count > 0 then
    Result := FLines.Strings[0]
  else Result := '';
end;

procedure TDdeClientItem.SetText(const S: string);
begin
end;

procedure TDdeClientItem.SetLines(L: TStrings);
begin
end;

constructor TDdeCliItem.Create(ADS: TDdeClientConv);
begin
  inherited Create;
  FHszItem := 0;
  FCliConv := ADS;
end;

destructor TDdeCliItem.Destroy;
begin
  StopAdvise;
  inherited Destroy;
end;

function TDdeCliItem.SetItem(const S: string): Boolean;
var
  OldItem: string;
begin
  Result := False;
  OldItem := Item;
  if FHszItem <> 0 then StopAdvise;

  FItem := S;
  FCtrl.Lines.Clear;

  if (Length(Item) <> 0) then
  begin
    if (FCliConv.Conv <> 0) then
    begin
      Result := StartAdvise;
      if Not Result then
        FItem := '';
    end
    else if FCliConv.ConnectMode = ddeManual then Result := True;
  end;
  RefreshData;
end;

procedure TDdeCliItem.StoreData(DdeDat: HDDEData);
var
  Len: Longint;
  Data: string;
  I: Integer;
begin
  if DdeDat = 0 then
  begin
    RefreshData;
    Exit;
  end;

  Data := PChar(AccessData(DdeDat, @Len));
  if Data <> '' then
  begin
    FCtrl.Lines.Text := Data;
    ReleaseData(DdeDat);
    if FCliConv.FormatChars = False then
    begin
      for I := 1 to Length(Data) do
        if (Data[I] > #0) and (Data[I] < ' ') then Data[I] := ' ';
      FCtrl.Lines.Text := Data;
    end;
  end;
  DataChange;
end;

function TDdeCliItem.RefreshData: Boolean;
var
  ddeRslt: LongInt;
  DdeDat: HDDEData;
begin
  Result := False;
  if (FCliConv.Conv <> 0) and (FHszItem <> 0) then
  begin
    if FCliConv.WaitStat = True then Exit;
    DdeDat := DdeClientTransaction(nil, DWORD(-1), FCliConv.Conv, FHszItem,
      FCliConv.DdeFmt, XTYP_REQUEST, 1000, @ddeRslt);
    if DdeDat = 0 then Exit
    else begin
      StoreData(DdeDat);
      DdeFreeDataHandle(DdeDat);
      Result := True;
      Exit;
    end;
  end;
  DataChange;
end;

function TDdeCliItem.AccessData(DdeDat: HDDEData; pDataLen: PDWORD): Pointer;
begin
  Result := DdeAccessData(DdeDat, pDataLen);
end;

procedure TDdeCliItem.ReleaseData(DdeDat: HDDEData);
begin
  DdeUnaccessData(DdeDat);
end;

function TDdeCliItem.StartAdvise: Boolean;
var
  ddeRslt: LongInt;
  hdata: HDDEData;
begin
  Result := False;
  if FCliConv.Conv = 0 then Exit;
  if Length(Item) = 0 then Exit;
  if FHszItem = 0 then
    FHszItem := DdeCreateStringHandle(ddeMgr.DdeInstId, PChar(Item), CP_WINANSI);
  hdata := DdeClientTransaction(nil, DWORD(-1), FCliConv.Conv, FHszItem,
    FCliConv.DdeFmt, XTYP_ADVSTART or XTYPF_NODATA, 1000, @ddeRslt);
  if hdata = 0 then
  begin
    DdeGetLastError(ddeMgr.DdeInstId);
    DdeFreeStringHandle(ddeMgr.DdeInstId, FHszItem);
    FHszItem := 0;
    FCtrl.Lines.Clear;
  end else
    Result := True;
end;

function TDdeCliItem.StopAdvise: Boolean;
var
  ddeRslt: LongInt;
begin
  if FCliConv.Conv <> 0 then
    if FHszItem <> 0 then
      DdeClientTransaction(nil, DWORD(-1), FCliConv.Conv, FHszItem,
        FCliConv.DdeFmt, XTYP_ADVSTOP, 1000, @ddeRslt);
  SrvrDisconnect;
  Result := True;
end;

procedure TDdeCliItem.SrvrDisconnect;
begin
  if FHszItem <> 0 then
  begin
    DdeFreeStringHandle(ddeMgr.DdeInstId, FHszItem);
    FHszItem := 0;
  end;
end;

procedure TDdeCliItem.DataChange;
begin
  FCtrl.OnAdvise;
end;

constructor TDdeServerItem.Create(AOwner: TComponent);
begin
  inherited Create(AOwner);
  FFmt := CF_TEXT;
  FLines := TStringList.Create;
end;

destructor TDdeServerItem.Destroy;
begin
  FLines.Free;
  inherited Destroy;
end;

procedure TDdeServerItem.SetServerConv(SConv: TDdeServerConv);
begin
  FServerConv := SConv;
  if SConv <> nil then SConv.FreeNotification(Self);
end;

function TDdeServerItem.GetText: string;
begin
  if FLines.Count > 0 then
    Result := FLines.Strings[0]
  else Result := '';
end;

procedure TDdeServerItem.SetText(const Item: string);
begin
  FFmt := CF_TEXT;
  FLines.Clear;
  FLines.Add(Item);
  ValueChanged;
end;

procedure TDdeServerItem.SetLines(Value: TStrings);
begin
  if AnsiCompareStr(Value.Text, FLines.Text) <> 0 then
  begin
    FFmt := CF_TEXT;
    FLines.Assign(Value);
    ValueChanged;
  end;
end;

procedure TDdeServerItem.ValueChanged;
begin
  if Assigned(FOnChange) then FOnChange(Self);
  if FServerConv <> nil then
    ddeMgr.PostDataChange(FServerConv.Name, Name)
  else if (Owner <> nil) and (Owner is TForm) then
    ddeMgr.PostDataChange(TForm(Owner).Caption, Name);
end;

function TDdeServerItem.PokeData(Data: HDdeData): LongInt;
var
  Len: Integer;
  pData: Pointer;
begin
  Result := dde_FNotProcessed;
  pData := DdeAccessData(Data, @Len);
  if pData <> nil then
  begin
    Lines.Text := PChar(pData);
    DdeUnaccessData(Data);
    ValueChanged;
    if Assigned(FOnPokeData) then FOnPokeData(Self);
    Result := dde_FAck;
  end;
end;

procedure TDdeServerItem.CopyToClipboard;
var
  Data: THandle;
  LinkData: string;
  DataPtr: Pointer;
begin
  if FServerConv <> nil then
    LinkData := ddeMgr.AppName + #0 + FServerConv.Name + #0 + Name
  else if (Owner =nil) then Exit
  else if Owner is TForm then
    LinkData := ddeMgr.AppName + #0 + TForm(Owner).Caption + #0 + Name;
  try
    Clipboard.AsText := Text;
    Data := GlobalAlloc(GMEM_MOVEABLE, Length(LinkData) + 1);
    try
      DataPtr := GlobalLock(Data);
      try
        Move(PChar(LinkData)^, DataPtr^, Length(LinkData) + 1);
        Clipboard.SetAsHandle(DdeMgr.LinkClipFmt, Data);
      finally
        GlobalUnlock(Data);
      end;
    except
      GlobalFree(Data);
      raise;
    end;
  finally
    Clipboard.Close;
  end;
end;

procedure TDdeServerItem.Change;
begin
  if Assigned(FOnChange) then FOnChange(Self);
end;

procedure TDdeServerItem.Notification(AComponent: TComponent;
  Operation: TOperation);
begin
  inherited Notification(AComponent, Operation);
  if (AComponent = FServerConv) and (Operation = opRemove) then
    FServerConv := nil;
end;

constructor TDdeServerConv.Create(AOwner: TComponent);
begin
  inherited Create(AOwner);
  ddeMgr.InsertServerConv (Self);
end;

destructor TDdeServerConv.Destroy;
begin
  ddeMgr.RemoveServerConv(Self);
  inherited Destroy;
end;

function TDdeServerConv.ExecuteMacro(Data: HDdeData): LongInt;
var
  Len: Integer;
  pData: Pointer;
  MacroLines: TStringList;
begin
  Result := dde_FNotProcessed;
  pData := DdeAccessData(Data, @Len);
  if pData <> nil then
  begin
    if Assigned(FOnExecuteMacro) then
    begin
      MacroLines := TStringList.Create;
      MacroLines.Text := PChar(pData);
      FOnExecuteMacro(Self, MacroLines);
      MacroLines.Destroy;
    end;
    Result := dde_FAck;
  end;
end;

procedure TDdeServerConv.Connect;
begin
  if Assigned(FOnOpen) then FOnOpen(Self);
end;

procedure TDdeServerConv.Disconnect;
begin
  if Assigned(FOnClose) then FOnClose(Self);
end;

constructor TDdeSrvrConv.Create(AOwner: TComponent);
begin
  inherited Create(AOwner);
  FItems := TList.Create;
end;

destructor TDdeSrvrConv.Destroy;
var
  I: Integer;
begin
  if FItems <> nil then
  begin
    for I := 0 to FItems.Count - 1 do
      TDdeSrvrItem(FItems[I]).Free;
    FItems.Free;
    FItems := nil;
  end;
  if FConv <> 0 then DdeDisconnect(FConv);
  if FHszTopic <> 0 then
  begin
    DdeFreeStringHandle(ddeMgr.DdeInstId, FHszTopic);
    FHszTopic := 0;
  end;
  inherited Destroy;
end;

function TDdeSrvrConv.AdvStart(Conv: HConv; hszTopic: HSZ; hszItem: HSZ;
  Fmt: Word): Boolean;
var
  Srvr: TDdeServerItem;
  Buffer: array[0..4095] of Char;
  SrvrItem: TDdeSrvrItem;
begin
  Result := False;
  if Fmt <> CF_TEXT then Exit;
  DdeQueryString(ddeMgr.DdeInstId, hszItem, Buffer, SizeOf(Buffer), CP_WINANSI);
  Srvr := GetControl(FForm, FSConv, Buffer);
  if Srvr = nil then Exit;
  SrvrItem := TDdeSrvrItem.Create(Self);
  SrvrItem.Srvr := Srvr;
  SrvrItem.Item := Buffer;
  FItems.Add(SrvrItem);
  SrvrItem.FreeNotification(Self);
  if FHszTopic = 0 then
    FHszTopic := DdeCreateStringHandle(ddeMgr.DdeInstId, PChar(Topic), CP_WINANSI);
  Result := True;
end;

procedure TDdeSrvrConv.AdvStop(Conv: HConv; hszTopic: HSZ; hszItem :HSZ);
var
  SrvrItem: TDdeSrvrItem;
begin
  SrvrItem := GetSrvrItem(hszItem);
  if SrvrItem <> nil then
  begin
    FItems.Remove(SrvrItem);
    SrvrItem.Free;
  end;
end;

function TDdeSrvrConv.PokeData(Conv: HConv; hszTopic: HSZ; hszItem: HSZ;
  Data: HDdeData; Fmt: Integer): LongInt;
var
  Srvr: TDdeServerItem;
  Buffer: array[0..4095] of Char;
begin
  Result := dde_FNotProcessed;
  if Fmt <> CF_TEXT then Exit;
  DdeQueryString(ddeMgr.DdeInstId, hszItem, Buffer, SizeOf(Buffer), CP_WINANSI);
  Srvr := GetControl(FForm, FSConv, Buffer);
  if Srvr <> nil then Result := Srvr.PokeData(Data);
end;

function TDdeSrvrConv.ExecuteMacro(Conv: HConv; hszTopic: HSZ;
  Data: HDdeData): Integer;
begin
  Result := dde_FNotProcessed;
  if (FSConv <> nil)  then
    Result := FSConv.ExecuteMacro(Data);
end;

function TDdeSrvrConv.RequestData(Conv: HConv; hszTopic: HSZ; hszItem :HSZ;
  Fmt: Word): HDdeData;
var
  Data: string;
  Buffer: array[0..4095] of Char;
  SrvrIt: TDdeSrvrItem;
  Srvr: TDdeServerItem;
begin
  Result := 0;
  SrvrIt := GetSrvrItem(hszItem);
  if SrvrIt <> nil then
    Result := SrvrIt.RequestData(Fmt)
  else
  begin
    DdeQueryString(ddeMgr.DdeInstId, hszItem, Buffer, SizeOf(Buffer), CP_WINANSI);
    Srvr := GetControl(FForm, FSConv, Buffer);
    if Srvr <> nil then
    begin
      if Fmt = CF_TEXT then
      begin
        Data := Srvr.Lines.Text;
        Result := DdeCreateDataHandle(ddeMgr.DdeInstId, PChar(Data),
          Length(Data) + 1, 0, hszItem, Fmt, 0 );
      end;
    end;
  end;
end;

function TDdeSrvrConv.GetControl(WinCtrl: TWinControl; DdeConv: TDdeServerConv; const ItemName: string): TDdeServerItem;
var
  I: Integer;
  Ctrl: TComponent;
  MainCtrl: TWinControl;
  Srvr: TDdeServerItem;
begin
  Result := nil;
  MainCtrl := WinCtrl;
  if MainCtrl = nil then
  begin
    if (DdeConv <> nil) and (DdeConv.Owner <> nil) and
      (DdeConv.Owner is TForm) then
      MainCtrl := TWinControl(DdeConv.Owner);
  end;
  if MainCtrl = nil then Exit;
  for I := 0 to MainCtrl.ComponentCount - 1 do
  begin
    Ctrl := MainCtrl.Components[I];
    if Ctrl is TDdeServerItem then
    begin
      if (Ctrl.Name = ItemName) and
        (TDdeServerItem(Ctrl).ServerConv = DdeConv) then
      begin
        Result := TDdeServerItem(Ctrl);
        Exit;
      end;
    end;
    if Ctrl is TWinControl then
    begin
      Srvr := GetControl(TWinControl(Ctrl), DdeConv, ItemName);
      if Srvr <> nil then
      begin
        Result := Srvr;
        Exit;
      end;
    end;
  end;
end;

function TDdeSrvrConv.GetItem(const ItemName: string): TDdeSrvrItem;
var
  I: Integer;
  Item: TDdeSrvrItem;
begin
  Result := nil;
  for I := 0 to FItems.Count - 1 do
  begin
    Item := FItems[I];
    If Item.Item = ItemName then
    begin
      Result := Item;
      Exit;
    end;
  end;
end;

function TDdeSrvrConv.GetSrvrItem(hszItem: HSZ): TDdeSrvrItem;
var
  I: Integer;
  Item: TDdeSrvrItem;
begin
  Result := nil;
  for I := 0 to FItems.Count - 1 do
  begin
    Item := FItems[I];
    If DdeCmpStringHandles(Item.HszItem, hszItem) = 0 then
    begin
      Result := Item;
      Exit;
    end;
  end;
end;

constructor TDdeSrvrItem.Create(AOwner: TComponent);
begin
  FConv := TDdeSrvrConv(AOwner);
  inherited Create(AOwner);
end;

destructor TDdeSrvrItem.Destroy;
begin
  if FHszItem <> 0 then
  begin
    DdeFreeStringHandle(ddeMgr.DdeInstId, FHszItem);
    FHszItem := 0;
  end;
  inherited Destroy;
end;

function TDdeSrvrItem.RequestData(Fmt: Word): HDdeData;
var
  Data: string;
  Buffer: array[0..4095] of Char;
begin
  Result := 0;
  SetString(FItem, Buffer, DdeQueryString(ddeMgr.DdeInstId, FHszItem, Buffer,
    SizeOf(Buffer), CP_WINANSI));
  if Fmt = CF_TEXT then
  begin
    Data := FSrvr.Lines.Text;
    Result := DdeCreateDataHandle(ddeMgr.DdeInstId, PChar(Data), Length(Data) + 1,
      0, FHszItem, Fmt, 0 );
  end;
end;

procedure TDdeSrvrItem.PostDataChange;
begin
  DdePostAdvise(ddeMgr.DdeInstId, FConv.HszTopic, FHszItem);
end;

procedure TDdeSrvrItem.SetItem(const Value: string);
begin
  FItem := Value;
  if FHszItem <> 0 then
  begin
    DdeFreeStringHandle(ddeMgr.DdeInstId, FHszItem);
    FHszItem := 0;
  end;
  if Length(FItem) > 0 then
    FHszItem := DdeCreateStringHandle(ddeMgr.DdeInstId, PChar(FItem), CP_WINANSI);
end;

begin
  ddeMgr := TDdeMgr.Create(Application);
end.

