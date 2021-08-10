
{*******************************************************}
{                                                       }
{       Borland Delphi Visual Component Library         }
{       Web server application components               }
{                                                       }
{       Copyright (c) 1997,99 Inprise Corporation       }
{                                                       }
{*******************************************************}

unit HTTPApp;

interface

uses SyncObjs, SysUtils, Classes, Forms, Masks, Contnrs;

const
  sDateFormat = '"%s", dd "%s" yyyy hh:mm:ss';

  MAX_STRINGS = 12;
  MAX_INTEGERS = 1;
  MAX_DATETIMES = 3;

type
  TMethodType = (mtAny, mtGet, mtPut, mtPost, mtHead);

{ Forward declaration }

  TWebResponse = class;

{ TWebRequest }

  TWebRequest = class(TObject)
  private
    FMethodType: TMethodType;
    FContentFields,
    FCookieFields,
    FQueryFields: TStrings;
    function GetContentFields: TStrings;
    function GetCookieFields: TStrings;
    function GetQueryFields: TStrings;
  protected
    function GetStringVariable(Index: Integer): string; virtual; abstract;
    function GetDateVariable(Index: Integer): TDateTime; virtual; abstract;
    function GetIntegerVariable(Index: Integer): Integer; virtual; abstract;
  public
    constructor Create;
    destructor Destroy; override;
    // Read count bytes from client
    function ReadClient(var Buffer; Count: Integer): Integer; virtual; abstract;
    // Read count characters as a string from client
    function ReadString(Count: Integer): string; virtual; abstract;
    // Translate a relative URI to a local absolute path
    function TranslateURI(const URI: string): string; virtual; abstract;
    // Write count bytes back to client
    function WriteClient(var Buffer; Count: Integer): Integer; virtual; abstract;
    // Write string contents back to client
    function WriteString(const AString: string): Boolean; virtual; abstract;
    // Utility to extract fields from a given string buffer
    procedure ExtractFields(Separators, WhiteSpace: TSysCharSet;
      Content: PChar; Strings: TStrings);
    // Fills the given string list with the content fields as the result
    // of a POST method
    procedure ExtractContentFields(Strings: TStrings);
    // Fills the given string list with values from the cookie header field
    procedure ExtractCookieFields(Strings: TStrings);
    // Fills the given TStrings with the values from the Query data
    // (ie: data following the "?" in the URL)
    procedure ExtractQueryFields(Strings: TStrings);
    // Read an arbitrary HTTP/Server Field not lists here
    function GetFieldByName(const Name: string): string; virtual; abstract;
    // The request method as an enumeration
    property MethodType: TMethodType read FMethodType;
    // Field lists
    property ContentFields: TStrings read GetContentFields;
    property CookieFields: TStrings read GetCookieFields;
    property QueryFields: TStrings read GetQueryFields;
    // HTTP header Fields
    property Method: string index 0 read GetStringVariable;
    property ProtocolVersion: string index 1 read GetStringVariable;
    property URL: string index 2 read GetStringVariable;
    property Query: string index 3 read GetStringVariable;
    property PathInfo: string index 4 read GetStringVariable;
    property PathTranslated: string index 5 read GetStringVariable;
    property Authorization: string index 28 read GetStringVariable;
    property CacheControl: string index 6 read GetStringVariable;
    property Cookie: string index 27 read GetStringVariable;
    property Date: TDateTime index 7 read GetDateVariable;
    property Accept: string index 8 read GetStringVariable;
    property From: string index 9 read GetStringVariable;
    property Host: string index 10 read GetStringVariable;
    property IfModifiedSince: TDateTime index 11 read GetDateVariable;
    property Referer: string index 12 read GetStringVariable;
    property UserAgent: string index 13 read GetStringVariable;
    property ContentEncoding: string index 14 read GetStringVariable;
    property ContentType: string index 15 read GetStringVariable;
    property ContentLength: Integer index 16 read GetIntegerVariable;
    property ContentVersion: string index 17 read GetStringVariable;
    property Content: string index 25 read GetStringVariable;
    property Connection: string index 26 read GetStringVariable;
    property DerivedFrom: string index 18 read GetStringVariable;
    property Expires: TDateTime index 19 read GetDateVariable;
    property Title: string index 20 read GetStringVariable;
    property RemoteAddr: string index 21 read GetStringVariable;
    property RemoteHost: string index 22 read GetStringVariable;
    property ScriptName: string index 23 read GetStringVariable;
    property ServerPort: Integer index 24 read GetIntegerVariable;
  end;

{ TCookie }

  TCookie = class(TCollectionItem)
  private
    FName: string;
    FValue: string;
    FPath: string;
    FDomain: string;
    FExpires: TDateTime;
    FSecure: Boolean;
  protected
    function GetHeaderValue: string;
  public
    constructor Create(Collection: TCollection); override;
    procedure AssignTo(Dest: TPersistent); override;
    property Name: string read FName write FName;
    property Value: string read FValue write FValue;
    property Domain: string read FDomain write FDomain;
    property Path: string read FPath write FPath;
    property Expires: TDateTime read FExpires write FExpires;
    property Secure: Boolean read FSecure write FSecure;
    property HeaderValue: string read GetHeaderValue;
  end;

{ TCookieCollection }

  TCookieCollection = class(TCollection)
  private
    FWebResponse: TWebResponse;
  protected
    function GetCookie(Index: Integer): TCookie;
    procedure SetCookie(Index: Integer; Cookie: TCookie);
  public
    constructor Create(WebResponse: TWebResponse; ItemClass: TCollectionItemClass);
    function  Add: TCookie;
    property WebResponse: TWebResponse read FWebResponse;
    property Items[Index: Integer]: TCookie read GetCookie write SetCookie; default;
  end;

{ TWebResponse }

  TWebResponse = class(TObject)
  private
    FContentStream: TStream;
    FCustomHeaders: TStrings;
    FCookies: TCookieCollection;
    procedure SetCustomHeaders(Value: TStrings);
  protected
    FHTTPRequest: TWebRequest;
    procedure AddCustomHeaders(var Headers: string);
    function GetStringVariable(Index: Integer): string; virtual; abstract;
    procedure SetStringVariable(Index: Integer; const Value: string); virtual; abstract;
    function GetDateVariable(Index: Integer): TDateTime; virtual; abstract;
    procedure SetDateVariable(Index: Integer; const Value: TDateTime); virtual; abstract;
    function GetIntegerVariable(Index: Integer): Integer; virtual; abstract;
    procedure SetIntegerVariable(Index: Integer; Value: Integer); virtual; abstract;
    function GetContent: string; virtual; abstract;
    procedure SetContent(const Value: string); virtual; abstract;
    procedure SetContentStream(Value: TStream); virtual;
    function GetStatusCode: Integer; virtual; abstract;
    procedure SetStatusCode(Value: Integer); virtual; abstract;
    function GetLogMessage: string; virtual; abstract;
    procedure SetLogMessage(const Value: string); virtual; abstract;
  public
    constructor Create(HTTPRequest: TWebRequest);
    destructor Destroy; override;
    function GetCustomHeader(const Name: string): String;
    procedure SendResponse; virtual; abstract;
    procedure SendRedirect(const URI: string); virtual; abstract;
    procedure SendStream(AStream: TStream); virtual; abstract;
    function Sent: Boolean; virtual;
    procedure SetCookieField(Values: TStrings; const ADomain, APath: string;
      AExpires: TDateTime; ASecure: Boolean);
    procedure SetCustomHeader(const Name, Value: string);
    property Cookies: TCookieCollection read FCookies;
    property HTTPRequest: TWebRequest read FHTTPRequest;
    property Version: string index 0 read GetStringVariable write SetStringVariable;
    property ReasonString: string index 1 read GetStringVariable write SetStringVariable;
    property Server: string index 2 read GetStringVariable write SetStringVariable;
    property WWWAuthenticate: string index 3 read GetStringVariable write SetStringVariable;
    property Realm: string index 4 read GetStringVariable write SetStringVariable;
    property Allow: string index 5 read GetStringVariable write SetStringVariable;
    property Location: string index 6 read GetStringVariable write SetStringVariable;
    property ContentEncoding: string index 7 read GetStringVariable write SetStringVariable;
    property ContentType: string index 8 read GetStringVariable write SetStringVariable;
    property ContentVersion: string index 9 read GetStringVariable write SetStringVariable;
    property DerivedFrom: string index 10 read GetStringVariable write SetStringVariable;
    property Title: string index 11 read GetStringVariable write SetStringVariable;

    property StatusCode: Integer read GetStatusCode write SetStatusCode;
    property ContentLength: Integer index 0 read GetIntegerVariable write SetIntegerVariable;

    property Date: TDateTime index 0 read GetDateVariable write SetDateVariable;
    property Expires: TDateTime index 1 read GetDateVariable write SetDateVariable;
    property LastModified: TDateTime index 2 read GetDateVariable write SetDateVariable;

    property Content: string read GetContent write SetContent;
    property ContentStream: TStream read FContentStream write SetContentStream;

    property LogMessage: string read GetLogMessage write SetLogMessage;

    property CustomHeaders: TStrings read FCustomHeaders write SetCustomHeaders;
  end;

{ TWebDispatcherEditor }

  TCustomWebDispatcher = class;
  TCustomContentProducer = class;

{ THTMLTagAttributes }

  THTMLAlign = (haDefault, haLeft, haRight, haCenter);
  THTMLVAlign = (haVDefault, haTop, haMiddle, haBottom, haBaseline);
  THTMLBgColor = type string;

  THTMLTagAttributes = class(TPersistent)
  private
    FProducer: TCustomContentProducer;
    FCustom: string;
    FOnChange: TNotifyEvent;
    procedure SetCustom(const Value: string);
  protected
    procedure Changed;
  public
    constructor Create(Producer: TCustomContentProducer);
    procedure RestoreDefaults; virtual;
    property Producer: TCustomContentProducer read FProducer;
    property OnChange: TNotifyEvent read FOnChange write FOnChange;
  published
    property Custom: string read FCustom write SetCustom;
  end;

  THTMLTableAttributes = class(THTMLTagAttributes)
  private
    FAlign: THTMLAlign;
    FBorder: Integer;
    FBgColor: THTMLBgColor;
    FCellSpacing: Integer;
    FCellPadding: Integer;
    FWidth: Integer;
    procedure SetAlign(Value: THTMLAlign);
    procedure SetBorder(Value: Integer);
    procedure SetBGColor(Value: THTMLBgColor);
    procedure SetCellSpacing(Value: Integer);
    procedure SetCellPadding(Value: Integer);
    procedure SetWidth(Value: Integer);
  protected
    procedure AssignTo(Dest: TPersistent); override;
  public
    constructor Create(Producer: TCustomContentProducer);
    procedure RestoreDefaults; override;
  published
    property Align: THTMLAlign read FAlign write SetAlign default haDefault;
    property BgColor: THTMLBgColor read FBgColor write SetBgColor;
    property Border: Integer read FBorder write SetBorder default -1;
    property CellSpacing: Integer read FCellSpacing write SetCellSpacing default -1;
    property CellPadding: Integer read FCellPadding write SetCellPAdding default -1;
    property Width: Integer read FWidth write SetWidth default 100;
  end;

  THTMLTableElementAttributes = class(THTMLTagAttributes)
  private
    FAlign: THTMLAlign;
    FBgColor: THTMLBgColor;
    FVAlign: THTMLVAlign;
    procedure SetAlign(Value: THTMLAlign);
    procedure SetBGColor(Value: THTMLBgColor);
    procedure SetVAlign(Value: THTMLVAlign);
  protected
    procedure AssignTo(Dest: TPersistent); override;
  public  
    procedure RestoreDefaults; override;
  published
    property Align: THTMLAlign read FAlign write SetAlign default haDefault;
    property BgColor: THTMLBgColor read FBgColor write SetBgColor;
    property VAlign: THTMLVAlign read FVAlign write SetVAlign default haVDefault;
  end;

  THTMLTableHeaderAttributes = class(THTMLTableElementAttributes)
  private
    FCaption: string;
    procedure SetCaption(Value: string);
  protected
    procedure AssignTo(Dest: TPersistent); override;
  public
    procedure RestoreDefaults; override;
  published
    property Caption: string read FCaption write SetCaption;
  end;

  THTMLTableRowAttributes = class(THTMLTableElementAttributes);
  THTMLTableCellAttributes = class(THTMLTableElementAttributes);

{ TCustomContentProducer }

  TCustomContentProducer = class(TComponent)
  private
    FDispatcher: TCustomWebDispatcher;
  protected
    procedure SetDispatcher(Value: TCustomWebDispatcher); virtual;
    procedure Notification(AComponent: TComponent; Operation: TOperation); override;
  public
    function Content: string; virtual;
    function ContentFromStream(Stream: TStream): string; virtual;
    function ContentFromString(const S: string): string; virtual;
  published
    property Dispatcher: TCustomWebDispatcher read FDispatcher
      write SetDispatcher stored False;
  end;

{ TCustomHTTPPageProducer }

  TCustomPageProducer = class(TCustomContentProducer)
  private
    FHTMLFile: TFileName;
    FHTMLDoc: TStrings;
    FStripParamQuotes: Boolean;
    procedure SetHTMLFile(const Value: TFileName);
    procedure SetHTMLDoc(Value: TStrings);
  protected
    function HandleTag(const TagString: string; TagParams: TStrings): string; virtual;
    property HTMLDoc: TStrings read FHTMLDoc write SetHTMLDoc;
    property HTMLFile: TFileName read FHTMLFile write SetHTMLFile;
    property StripParamQuotes: Boolean read FStripParamQuotes write FStripParamQuotes default True;
  public
    constructor Create(AOwner: TComponent); override;
    destructor Destroy; override;
    function Content: string; override;
    function ContentFromStream(Stream: TStream): string; override;
    function ContentFromString(const S: string): string; override;
  end;

{ TPageProducer }

  TTag = (tgCustom, tgLink, tgImage, tgTable, tgImageMap, tgObject, tgEmbed);

  THTMLTagEvent = procedure (Sender: TObject; Tag: TTag; const TagString: string;
    TagParams: TStrings; var ReplaceText: string) of object;

  TPageProducer = class(TCustomPageProducer)
  private
    FOnHTMLTag: THTMLTagEvent;
  protected
    function HandleTag(const TagString: string; TagParams: TStrings): string; override;
    procedure DoTagEvent(Tag: TTag; const TagString: string; TagParams: TStrings;
      var ReplaceText: string); dynamic;
  published
    property HTMLDoc;
    property HTMLFile;
    property StripParamQuotes;
    property OnHTMLTag: THTMLTagEvent read FOnHTMLTag write FOnHTMLTag;
  end;

{ TWebActionItem }

  THTTPMethodEvent = procedure (Sender: TObject; Request: TWebRequest;
    Response: TWebResponse; var Handled: Boolean) of object;

  TWebActionItem = class(TCollectionItem)
  private
    FOnAction: THTTPMethodEvent;
    FPathInfo: string;
    FMethodType: TMethodType;
    FDefault: Boolean;
    FEnabled: Boolean;
    FMaskPathInfo: string;
    FMask: TMask;
    FName: string;
    FProducer: TCustomContentProducer;
    function DispatchAction(Request: TWebRequest; Response: TWebResponse;
      DoDefault: Boolean): Boolean;
    procedure SetDefault(Value: Boolean);
    procedure SetEnabled(Value: Boolean);
    procedure SetMethodType(Value: TMethodType);
    procedure SetOnAction(Value: THTTPMethodEvent);
    procedure SetPathInfo(const Value: string);
    procedure SetProducer(const Value: TCustomContentProducer);
    function GetMask: TMask;
    function ProducerPathInfo: string;
  protected
    function GetDisplayName: string; override;
    procedure SetDisplayName(const Value: string); override;
    function GetPathInfo: string;
  public
    constructor Create(Collection: TCollection); override;
    destructor Destroy; override;
    procedure AssignTo(Dest: TPersistent); override;
  published
    property Default: Boolean read FDefault write SetDefault default False;
    property Enabled: Boolean read FEnabled write SetEnabled default True;
    property MethodType: TMethodType read FMethodType write SetMethodType default mtAny;
    property Name: string read GetDisplayName write SetDisplayName;
    property PathInfo: string read GetPathInfo write SetPathInfo;
    property Producer: TCustomContentProducer read FProducer write SetProducer;
    property OnAction: THTTPMethodEvent read FOnAction write SetOnAction;
  end;

{ TWebActionItems }

  TWebActionItems = class(TCollection)
  private
    FWebDispatcher: TCustomWebDispatcher;
    function GetActionItem(Index: Integer): TWebActionItem;
    procedure SetActionItem(Index: Integer; Value: TWebActionItem);
  protected
    function GetAttrCount: Integer; override;
    function GetAttr(Index: Integer): string; override;
    function GetItemAttr(Index, ItemIndex: Integer): string; override;
    function GetOwner: TPersistent; override;
    procedure SetItemName(Item: TCollectionItem); override;
    procedure Update(Item: TCollectionItem); override;
  public
    constructor Create(WebDispatcher: TCustomWebDispatcher;
      ItemClass: TCollectionItemClass);
    function  Add: TWebActionItem;
    property WebDispatcher: TCustomWebDispatcher read FWebDispatcher;
    property Items[Index: Integer]: TWebActionItem read GetActionItem
      write SetActionItem; default;
  end;

{ IWebDispatch }

  IWebDispatch = interface
  ['{F358F272-DB6D-11D2-AA3F-00A024C11562}']
    function DispatchEnabled: Boolean;
    function DispatchMethodType: TMethodType;
    function DispatchRequest(Sender: TObject; Request: TWebRequest; Response: TWebResponse): Boolean;
    function DispatchMask: TMask;
    function DispatchSubItems: IInterfaceList;
    property Enabled: Boolean read DispatchEnabled;
    property MethodType: TMethodType read DispatchMethodType;
    property Mask: TMask read DispatchMask;
    property SubItems: IInterfaceList read DispatchSubItems;
  end;

{ TCustomWebDispatcher }

  TCustomWebDispatcher = class(TDataModule)
  private
    FRequest: TWebRequest;
    FResponse: TWebResponse;
    FActions: TWebActionItems;
    FBeforeDispatch: THTTPMethodEvent;
    FAfterDispatch: THTTPMethodEvent;
    FDispatchList: TComponentList;
    function GetAction(Index: Integer): TWebActionItem;
    procedure SetActions(Value: TWebActionItems);
  protected
    function DoAfterDispatch(Request: TWebRequest; Response: TWebResponse): Boolean;
    function DoBeforeDispatch(Request: TWebRequest; Response: TWebResponse): Boolean;
    function DispatchAction(Request: TWebRequest;
      Response: TWebResponse): Boolean;
    procedure Notification(AComponent: TComponent; Operation: TOperation); override;
    property BeforeDispatch: THTTPMethodEvent read FBeforeDispatch write FBeforeDispatch;
    property AfterDispatch: THTTPMethodEvent read FAfterDispatch write FAfterDispatch;
  public
    constructor Create(AOwner: TComponent); override;
    destructor Destroy; override;
    function ActionByName(const AName: string): TWebActionItem;
    property Actions: TWebActionItems read FActions write SetActions;
    property Action[Index: Integer]: TWebActionItem read GetAction;
    property Request: TWebRequest read FRequest;
    property Response: TWebResponse read FResponse;
  end;

{ TWebDispatcher }

  TWebDispatcher = class(TCustomWebDispatcher)
  published
    property Actions;
    property BeforeDispatch;
    property AfterDispatch;
  end;

{ TWebModule }

  TWebModule = class(TCustomWebDispatcher)
  public
    constructor Create(AOwner: TComponent); override;
  published
    property Actions;
    property BeforeDispatch;
    property AfterDispatch;
  end;

const
  HTMLAlign: array[THTMLAlign] of string =
    ('',
     ' Align="Left"',
     ' Align="Right"',
     ' Align="Center"');
  HTMLVAlign: array[THTMLVAlign] of string =
    ('',
     ' VAlign="Top"',
     ' VAlign="Middle"',
     ' VAlign="Bottom"',
     ' VAlign="Basline"');

function DosPathToUnixPath(const Path: string): string;
function HTTPDecode(const AStr: String): string;
function HTTPEncode(const AStr: String): string;
function ParseDate(const DateStr: string): TDateTime;
procedure ExtractHTTPFields(Separators, WhiteSpace: TSysCharSet; Content: PChar;
  Strings: TStrings; StripQuotes: Boolean = False);
procedure ExtractHeaderFields(Separators, WhiteSpace: TSysCharSet; Content: PChar;
  Strings: TStrings; Decode: Boolean; StripQuotes: Boolean = False);
function StatusString(StatusCode: Integer): string;
function UnixPathToDosPath(const Path: string): string;
function MonthStr(DateTime: TDateTime): string;
function DayOfWeekStr(DateTime: TDateTime): string;

implementation

uses Windows, CopyPrsr, WebConst;

{ TWebRequest }

constructor TWebRequest.Create;
begin
  inherited Create;
  if CompareText(Method, 'GET') = 0 then
    FMethodType := mtGet
  else if CompareText(Method, 'PUT') = 0 then
    FMethodType := mtPut
  else if CompareText(Method, 'POST') = 0 then
    FMethodType := mtPost
  else if CompareText(Method, 'HEAD') = 0 then
    FMethodType := mtHead;
end;

destructor TWebRequest.Destroy;
begin
  FContentFields.Free;
  FCookieFields.Free;
  FQueryFields.Free;
  inherited Destroy;
end;

procedure TWebRequest.ExtractFields(Separators, WhiteSpace: TSysCharSet;
  Content: PChar; Strings: TStrings);
begin
  ExtractHTTPFields(Separators, WhiteSpace, Content, Strings);
end;

procedure TWebRequest.ExtractContentFields(Strings: TStrings);
var
  ContentStr: string;
begin
  if ContentLength > 0 then
  begin
    ContentStr := Content;
    if Length(ContentStr) < ContentLength then
      ContentStr := ContentStr + ReadString(ContentLength - Length(ContentStr));
    ExtractFields(['&'], [], PChar(ContentStr), Strings);
  end;
end;

procedure TWebRequest.ExtractCookieFields(Strings: TStrings);
var
  CookieStr: string;
begin
  CookieStr := Cookie;
  ExtractHeaderFields([';'], [' '], PChar(CookieStr), Strings, False);
end;

procedure TWebRequest.ExtractQueryFields(Strings: TStrings);
var
  ContentStr: string;
begin
  ContentStr := Query;
  ExtractFields(['&'], [], PChar(ContentStr), Strings);
end;

function TWebRequest.GetContentFields: TStrings;
begin
  if FContentFields = nil then
  begin
    FContentFields := TStringList.Create;
    ExtractContentFields(FContentFields);
  end;
  Result := FContentFields;
end;

function TWebRequest.GetCookieFields: TStrings;
begin
  if FCookieFields = nil then
  begin
    FCookieFields := TStringList.Create;
    ExtractCookieFields(FCookieFields);
  end;
  Result := FCookieFields;
end;

function TWebRequest.GetQueryFields: TStrings;
begin
  if FQueryFields = nil then
  begin
    FQueryFields := TStringList.Create;
    ExtractQueryFields(FQueryFields);
  end;
  Result := FQueryFields;
end;

{ TCookie }

constructor TCookie.Create(Collection: TCollection);
begin
  inherited Create(Collection);
  FExpires := -1;
end;

procedure TCookie.AssignTo(Dest: TPersistent);
begin
  if Dest is TCookie then
    with TCookie(Dest) do
    begin
      Name := Self.FName;
      Value := Self.FValue;
      Domain := Self.FDomain;
      Path := Self.FPath;
      Expires := Self.FExpires;
      Secure := Self.FSecure;
    end else inherited AssignTo(Dest);
end;

function TCookie.GetHeaderValue: string;
begin
  Result := Format('%s=%s; ', [FName, FValue]);
  if Domain <> '' then
    Result := Result + Format('domain=%s; ', [Domain]);
  if Path <> '' then
    Result := Result + Format('path=%s; ', [Path]);
  if Expires > -1 then
    Result := Result +
      Format(FormatDateTime('"expires="' + sDateFormat + ' "GMT; "', Expires),
        [DayOfWeekStr(Expires), MonthStr(Expires)]);
  if Secure then Result := Result + 'secure';
  if Copy(Result, Length(Result) - 2, MaxInt) = '; ' then
    SetLength(Result, Length(Result) - 2);
end;

{ TCookieCollection }

constructor TCookieCollection.Create(WebResponse: TWebResponse; ItemClass: TCollectionItemClass);
begin
  inherited Create(ItemClass);
  FWebResponse := WebResponse;
end;

function TCookieCollection.Add: TCookie;
begin
  Result := TCookie(inherited Add);
end;

function TCookieCollection.GetCookie(Index: Integer): TCookie;
begin
  Result := TCookie(inherited Items[Index]);
end;

procedure TCookieCollection.SetCookie(Index: Integer; Cookie: TCookie);
begin
  Items[Index].Assign(Cookie);
end;

{ TWebResponse }

constructor TWebResponse.Create(HTTPRequest: TWebRequest);
begin
  inherited Create;
  FHTTPRequest := HTTPRequest;
  FCustomHeaders := TStringList.Create;
  FCookies := TCookieCollection.Create(Self, TCookie);
end;

destructor TWebResponse.Destroy;
begin
  FContentStream.Free;
  FCustomHeaders.Free;
  FCookies.Free;
  inherited Destroy;
end;

procedure TWebResponse.AddCustomHeaders(var Headers: string);
var
  I: Integer;
  Name, Value: string;
begin
  for I := 0 to FCustomHeaders.Count - 1 do
  begin
    Name := FCustomHeaders.Names[I];
    Value := FCustomHeaders.values[Name];
    Headers := Headers + Name + ': ' + Value + #13#10;
  end;
end;

function TWebResponse.GetCustomHeader(const Name: string): string;
begin
  Result := FCustomHeaders.Values[Name];
end;

function TWebResponse.Sent: Boolean;
begin
  Result := False;
end;

procedure TWebResponse.SetContentStream(Value: TStream);
begin
  if Value <> FContentStream then
  begin
    FContentStream.Free;
    FContentStream := Value;
    if FContentStream <> nil then
      ContentLength := FContentStream.Size
    else ContentLength := Length(Content);  
  end;
end;

procedure TWebResponse.SetCookieField(Values: TStrings; const ADomain,
  APath: string; AExpires: TDateTime; ASecure: Boolean);
var
  I: Integer;
begin
  for I := 0 to Values.Count - 1 do
    with Cookies.Add do
    begin
      Name := Values.Names[I];
      Value := Values.Values[Values.Names[I]];
      Domain := ADomain;
      Path := APath;
      Expires := AExpires;
      Secure := ASecure;
    end;
end;

procedure TWebResponse.SetCustomHeader(const Name, Value: string);
begin
  FCustomHeaders.Values[Name] := Value;
end;

procedure TWebResponse.SetCustomHeaders(Value: TStrings);
begin
  FCustomHeaders.Assign(Value);
end;

{ THTMLTagAttributes }

constructor THTMLTagAttributes.Create(Producer: TCustomContentProducer);
begin
  inherited Create;
  FProducer := Producer;
end;

procedure THTMLTagAttributes.Changed;
begin
  if Assigned(FOnChange) then FOnChange(Self);
end;

procedure THTMLTagAttributes.RestoreDefaults;
begin
  FCustom := '';
  Changed;
end;

procedure THTMLTagAttributes.SetCustom(const Value: string);
begin
  if Value <> FCustom then
  begin
    FCustom := Value;
    Changed;
  end;
end;

{ THTMLTableAttributes }

constructor THTMLTableAttributes.Create(Producer: TCustomContentProducer);
begin
  inherited Create(Producer);
  FWidth := 100;
  FBorder := -1;
  FCellPadding := -1;
  FCellSpacing := -1;
end;

procedure THTMLTableAttributes.AssignTo(Dest: TPersistent);
begin
  if Dest is THTMLTableAttributes then
    with THTMLTableAttributes(Dest) do
    begin
      FWidth := Self.FWidth;
      FAlign := Self.FAlign;
      FBorder := Self.FBorder;
      FBgColor := Self.FBgColor;
      FCellSpacing := Self.FCellSpacing;
      FCellPadding := Self.FCellPadding;
      Changed;
    end else inherited AssignTo(Dest);
end;

procedure THTMLTableAttributes.RestoreDefaults;
begin
  FCustom := '';
  FAlign := haDefault;
  FWidth := 100;
  FBorder := -1;
  FCellPadding := -1;
  FCellSpacing := -1;
  Changed;
end;

procedure THTMLTableAttributes.SetAlign(Value: THTMLAlign);
begin
  if Value <> FAlign then
  begin
    FAlign := Value;
    Changed;
  end;
end;

procedure THTMLTableAttributes.SetBorder(Value: Integer);
begin
  if Value <> FBorder then
  begin
    FBorder := Value;
    Changed;
  end;
end;

procedure THTMLTableAttributes.SetBGColor(Value: THTMLBgColor);
begin
  if Value <> FBgColor then
  begin
    FBgColor := Value;
    Changed;
  end;
end;

procedure THTMLTableAttributes.SetCellSpacing(Value: Integer);
begin
  if Value <> FCellSpacing then
  begin
    FCellSpacing := Value;
    Changed;
  end;
end;

procedure THTMLTableAttributes.SetCellPadding(Value: Integer);
begin
  if Value <> FCellPadding then
  begin
    FCellPadding := Value;
    Changed;
  end;
end;

procedure THTMLTableAttributes.SetWidth(Value: Integer);
begin
  if Value <> FWidth then
  begin
    FWidth := Value;
    Changed;
  end;
end;

{ THTMLTableElementAttributes }

procedure THTMLTableElementAttributes.AssignTo(Dest: TPersistent);
begin
  if Dest is THTMLTableElementAttributes then
    with THTMLTableElementAttributes(Dest) do
    begin
      FAlign := Self.FAlign;
      FVAlign := Self.FVAlign;
      FBgColor := Self.FBgColor;
      Changed;
    end else inherited AssignTo(Dest);
end;

procedure THTMLTableElementAttributes.RestoreDefaults;
begin
  FCustom := '';
  FAlign := haDefault;
  FVAlign := haVDefault;
  FBgColor := '';
  Changed;
end;

procedure THTMLTableElementAttributes.SetAlign(Value: THTMLAlign);
begin
  if Value <> FAlign then
  begin
    FAlign := Value;
    Changed;
  end;
end;

procedure THTMLTableElementAttributes.SetBGColor(Value: THTMLBgColor);
begin
  if Value <> FBgColor then
  begin
    FBgColor := Value;
    Changed;
  end;
end;

procedure THTMLTableElementAttributes.SetVAlign(Value: THTMLVAlign);
begin
  if Value <> FVAlign then
  begin
    FVAlign := Value;
    Changed;
  end;
end;

{ THTMLTableHeaderAttributes }

procedure THTMLTableHeaderAttributes.AssignTo(Dest: TPersistent);
begin
  if Dest is THTMLTableHeaderAttributes then
    with THTMLTableHeaderAttributes(Dest) do
    begin
      FAlign := Self.FAlign;
      FVAlign := Self.FVAlign;
      FBgColor := Self.FBgColor;
      FCaption := Self.FCaption;
      Changed;
    end else inherited AssignTo(Dest);
end;

procedure THTMLTableHeaderAttributes.RestoreDefaults;
begin
  FCustom := '';
  FAlign := haDefault;
  FVAlign := haVDefault;
  FBgColor := '';
  FCaption := '';
  Changed;
end;

procedure THTMLTableHeaderAttributes.SetCaption(Value: string);
begin
  if AnsiCompareStr(Value, FCaption) <> 0 then
  begin
    FCaption := Value;
    Changed;
  end;
end;

{ TCustomHTMLProducer }

procedure TCustomContentProducer.Notification(AComponent: TComponent;
  Operation: TOperation);
begin
  inherited Notification(AComponent, Operation);
  if (Operation = opRemove) and (AComponent = FDispatcher) then
    FDispatcher := nil;
end;

procedure TCustomContentProducer.SetDispatcher(Value: TCustomWebDispatcher);
begin
  if FDispatcher <> Value then
  begin
    if Value <> nil then Value.FreeNotification(Self);
    FDispatcher := Value;
  end;
end;

function TCustomContentProducer.Content: string;
begin
  Result := '';
end;

function TCustomContentProducer.ContentFromStream(Stream: TStream): string;
begin
  Result := Content;
end;

function TCustomContentProducer.ContentFromString(const S: string): string;
begin
  Result := Content;
end;

{ TCustomPageProducer }

constructor TCustomPageProducer.Create(AOwner: TComponent);
begin
  inherited Create(AOwner);
  RPR;
  FStripParamQuotes := True;
  FHTMLDoc := TStringList.Create;
end;

destructor TCustomPageProducer.Destroy;
begin
  FHTMLDoc.Free;
  inherited Destroy;
end;

function TCustomPageProducer.Content: string;
var
  InStream: TStream;
begin
  Result := '';
  if FHTMLFile <> '' then
    InStream := TFileStream.Create(FHTMLFile, fmOpenRead + fmShareDenyWrite)
  else InStream := TStringStream.Create(FHTMLDoc.Text);
  if InStream <> nil then
  try
    Result := ContentFromStream(InStream);
  finally
    InStream.Free;
  end;
end;

function TCustomPageProducer.ContentFromStream(Stream: TStream): string;
var
  Parser: TCopyParser;
  OutStream: TStringStream;
  ParamStr, ReplaceStr, TokenStr: string;
  ParamList: TStringList;
begin
  OutStream := TStringStream.Create('');
  try
    Parser := TCopyParser.Create(Stream, OutStream);
    with Parser do
    try
      while True do
      begin
        while not (Token in [toEof, '<']) do
        begin
          CopyTokenToOutput;
          SkipToken(True);
        end;
        if Token = toEOF then Break;
        if Token = '<' then
        begin
          if SkipToken(False) = '#' then
          begin
            SkipToken(False);
            TokenStr := TokenString;
            ParamStr := TrimLeft(TrimRight(SkipToToken('>')));
            ParamList := TStringList.Create;
            try
              ExtractHTTPFields([' '], [' '], PChar(ParamStr), ParamList, FStripParamQuotes);
              ReplaceStr := HandleTag(TokenStr, ParamList);
              OutStream.WriteString(ReplaceStr);
            finally
              ParamList.Free;
            end;
            SkipToken(True);
          end else
          begin
            OutStream.WriteString('<');
            CopyTokenToOutput;
            SkipToken(True);
          end;
        end;
      end;
    finally
      Parser.Free;
    end;
    Result := OutStream.DataString;
  finally
    OutStream.Free;
  end;
end;

function TCustomPageProducer.ContentFromString(const S: string): string;
var
  InStream: TStream;
begin
  InStream := TStringStream.Create(S);
  try
    Result := ContentFromStream(InStream);
  finally
    InStream.Free;
  end;
end;

function TCustomPageProducer.HandleTag(const TagString: string; TagParams: TStrings): string;
begin
  Result := Format('<#%s>', [TagString]);
end;

procedure TCustomPageProducer.SetHTMLFile(const Value: TFileName);
begin
  if CompareText(FHTMLFile, Value) <> 0 then
  begin
    FHTMLDoc.Clear;
    FHTMLFile := Value;
  end;
end;

procedure TCustomPageProducer.SetHTMLDoc(Value: TStrings);
begin
  FHTMLDoc.Assign(Value);
  FHTMLFile := '';
end;

{ TPageProducer }

var
  TagSymbols: array[TTag] of string =
    ('', 'LINK', 'IMAGE', 'TABLE', 'IMAGEMAP', 'OBJECT', 'EMBED');

function TPageProducer.HandleTag(const TagString: string; TagParams: TStrings): string;
var
  Tag: TTag;
begin
  Tag := High(TTag);
  while Tag >= Low(TTag) do
  begin
    if (Tag = tgCustom) or (CompareText(TagSymbols[Tag], TagString) = 0) then Break;
    Dec(Tag);
  end;
  Result := '';
  DoTagEvent(Tag, TagString, TagParams, Result);
end;

procedure TPageProducer.DoTagEvent(Tag: TTag; const TagString: string;
  TagParams: TStrings; var ReplaceText: string);
begin
  if Assigned(FOnHTMLTag) then
    FOnHTMLTag(Self, Tag, TagString, TagParams, ReplaceText);
end;

{ TWebActionItem }

constructor TWebActionItem.Create(Collection: TCollection);
begin
  inherited Create(Collection);
  FEnabled := True;
end;

destructor TWebActionItem.Destroy;
begin
  FMask.Free;
  inherited Destroy;
end;

procedure TWebActionItem.AssignTo(Dest: TPersistent);
begin
  if Dest is TWebActionItem then
  begin
    if Assigned(Collection) then Collection.BeginUpdate;
    try
      with TWebActionItem(Dest) do
      begin
        Default := Self.Default;
        PathInfo := Self.PathInfo;
        Enabled := Self.Enabled;
        MethodType := Self.MethodType;
      end;
    finally
      if Assigned(Collection) then Collection.EndUpdate;
    end;
  end else inherited AssignTo(Dest);
end;

function TWebActionItem.DispatchAction(Request: TWebRequest; Response: TWebResponse;
  DoDefault: Boolean): Boolean;
begin
  Result := False;
  if (FDefault and DoDefault) or (FEnabled and ((FMethodType = mtAny) or
    (FMethodType = Request.MethodType)) and
    GetMask.Matches(Request.PathInfo)) then
  begin
    if Assigned(FProducer) then
    begin
      Result := True;
      Response.Content := FProducer.Content;
    end;
    if Assigned(FOnAction) then
    begin
      Result := True;
      FOnAction(Self, Request, Response, Result);
    end
  end;
end;

function TWebActionItem.GetDisplayName: string;
begin
  Result := FName;
end;

procedure TWebActionItem.SetDefault(Value: Boolean);
var
  I: Integer;
  Action: TWebActionItem;
begin
  if Value <> FDefault then
  begin
    if Value and (Collection <> nil) then
      for I := 0 to Collection.Count - 1 do
      begin
        Action := TWebActionItems(Collection).Items[I];
        if (Action <> Self) and (Action is TWebActionItem) then
          Action.Default := False;
      end;
    FDefault := Value;
    Changed(False);
  end;
end;

procedure TWebActionItem.SetEnabled(Value: Boolean);
begin
  if Value <> FEnabled then
  begin
    FEnabled := Value;
    Changed(False);
  end;
end;

procedure TWebActionItem.SetMethodType(Value: TMethodType);
begin
  if Value <> FMethodType then
  begin
    FMethodType := Value;
    Changed(False);
  end;
end;

procedure TWebActionItem.SetDisplayName(const Value: string);
var
  I: Integer;
  Action: TWebActionItem;
begin
  if AnsiCompareText(Value, FName) <> 0 then
  begin
    if Collection <> nil then
      for I := 0 to Collection.Count - 1 do
      begin
        Action := TWebActionItems(Collection).Items[I];
        if (Action <> Self) and (Action is TWebActionItem) and
          (AnsiCompareText(Value, Action.Name) = 0) then
          raise Exception.Create(sDuplicateActionName);
      end;
    FName := Value;
    Changed(False);
  end;
end;

procedure TWebActionItem.SetOnAction(Value: THTTPMethodEvent);
begin
  FOnAction := Value;
  Changed(False);
end;

procedure TWebActionItem.SetPathInfo(const Value: string);
var
  NewValue: string;
begin
  if Value <> '' then NewValue := DosPathToUnixPath(Value);
  if (NewValue <> '') and (NewValue[1] <> '/') then Insert('/', NewValue, 1);
  if Assigned(FProducer) and (NewValue = ProducerPathInfo) then
    NewValue := '';
  if AnsiCompareText(FPathInfo, NewValue) <> 0 then
  begin
    FPathInfo := NewValue;
    Changed(False);
  end;
end;

procedure TWebActionItem.SetProducer(const Value: TCustomContentProducer);
begin
  if Assigned(Value) then
    Value.FreeNotification(TWebActionItems(Collection).WebDispatcher);
  FProducer := Value;
end;

function TWebActionItem.ProducerPathInfo: string;
begin
  Assert(Assigned(FProducer));
  Result := '/' + FProducer.Name
end;

function TWebActionItem.GetPathInfo: string;
begin
  if (FPathInfo = '') and Assigned(FProducer) then
    Result := ProducerPathInfo
  else
    Result := FPathInfo;
end;

function TWebActionItem.GetMask: TMask;
var
  Mask: TMask;
  MaskPathInfo: string;
begin
  MaskPathInfo := GetPathInfo;
  if (not Assigned(FMask)) or
    (AnsiCompareText(FMaskPathInfo, MaskPathInfo) <> 0) then
  begin
    Mask := TMask.Create(MaskPathInfo);
    try
      FMaskPathInfo := MaskPathInfo;
      if Assigned(FMask) then
      begin
        FMask.Free;
        FMask := nil;
      end;
    except
      Mask.Free;
      raise;
    end;
    FMask := Mask;
  end;
  Result := FMask;
end;

{ TWebActionItems }

constructor TWebActionItems.Create(WebDispatcher: TCustomWebDispatcher;
  ItemClass: TCollectionItemClass);
begin
  inherited Create(ItemClass);
  FWebDispatcher := WebDispatcher;
end;

function TWebActionItems.Add: TWebActionItem;
begin
  Result := TWebActionItem(inherited Add);
end;

function TWebActionItems.GetActionItem(Index: Integer): TWebActionItem;
begin
  Result := TWebActionItem(inherited Items[Index]);
end;

function TWebActionItems.GetAttrCount: Integer;
begin
  Result := 5;
end;

function TWebActionItems.GetAttr(Index: Integer): string;
begin
  case Index of
    0: Result := sHTTPItemName;
    1: Result := sHTTPItemURI;
    2: Result := sHTTPItemEnabled;
    3: Result := sHTTPItemDefault;
    4: Result := sHTTPItemProducer;
  else
    Result := '';
  end;
end;

function TWebActionItems.GetItemAttr(Index, ItemIndex: Integer): string;
begin
  case Index of
    0: Result := Items[ItemIndex].Name;
    1: Result := Items[ItemIndex].PathInfo;
    2: if Items[ItemIndex].Enabled then
         Result := 'True' else Result := 'False'; // do not localize
    3: if Items[ItemIndex].Default then
         Result := '*' else Result := '';  //do not localize
    4: if Items[ItemIndex].Producer <> nil then
         Result := Items[ItemIndex].Producer.Name else Result := '';  //do not localize
  else
    Result := '';
  end;
end;

function TWebActionItems.GetOwner: TPersistent;
begin
  Result := FWebDispatcher;
end;

procedure TWebActionItems.SetActionItem(Index: Integer; Value: TWebActionItem);
begin
  Items[Index].Assign(Value);
end;

procedure TWebActionItems.SetItemName(Item: TCollectionItem);
var
  I, J: Integer;
  ItemName: string;
  CurItem: TWebActionItem;
begin
  J := 1;
  while True do
  begin
    ItemName := Format('WebActionItem%d', [J]);
    I := 0;
    while I < Count do
    begin
      CurItem := Items[I] as TWebActionItem;
      if (CurItem <> Item) and (CompareText(CurItem.Name, ItemName) = 0) then
      begin
        Inc(J);
        Break;
      end;
      Inc(I);
    end;
    if I >= Count then
    begin
      (Item as TWebActionItem).Name := ItemName;
      Break;
    end;
  end;
end;

procedure TWebActionItems.Update(Item: TCollectionItem);
begin
{!!!  if (FWebDispatcher <> nil) and
    not (csLoading in FWebDispatcher.ComponentState) then }
end;

{ TCustomWebDispatcher }

constructor TCustomWebDispatcher.Create(AOwner: TComponent);
var
  I: Integer;
  Component: TComponent;
  DispatchIntf: IWebDispatch;
begin
  RPR;
  FDispatchList := TComponentList.Create;
  FDispatchList.OwnsObjects := False;
  if (AOwner <> nil) and (AOwner <> Application) then
    if AOwner is TCustomWebDispatcher then
      raise Exception.Create(sOnlyOneDispatcher)
    else if csDesigning in ComponentState then 
      for I := 0 to AOwner.ComponentCount - 1 do
        if AOwner.Components[I] is TCustomWebDispatcher then
          raise Exception.Create(sOnlyOneDispatcher);
  inherited CreateNew(AOwner);
  FActions := TWebActionItems.Create(Self, TWebActionItem);
  if Owner <> nil then
    for I := 0 to Owner.ComponentCount - 1 do
    begin
      Component := Owner.Components[I];
      if Component is TCustomContentProducer then
        TCustomContentProducer(Component).Dispatcher := Self
      else if Component.GetInterface(IWebDispatch, DispatchIntf) then
        FDispatchList.Add(Component);
    end;
end;

destructor TCustomWebDispatcher.Destroy;
begin
  inherited Destroy;
  FActions.Free;
  FDispatchList.Free;
end;

function TCustomWebDispatcher.ActionByName(const AName: string): TWebActionItem;
var
  I: Integer;
begin
  for I := 0 to FActions.Count - 1 do
  begin
    Result := FActions[I];
    if AnsiCompareText(AName, Result.Name) = 0 then Exit;
  end;
  Result := nil;
end;

function TCustomWebDispatcher.DoAfterDispatch(Request: TWebRequest; Response: TWebResponse): Boolean;
begin
  Result := True;
  if Assigned(FAfterDispatch) then
    FAfterDispatch(Self, Request, Response, Result);
end;

function TCustomWebDispatcher.DoBeforeDispatch(Request: TWebRequest; Response: TWebResponse): Boolean;
begin
  Result := False;
  if Assigned(FBeforeDispatch) then
    FBeforeDispatch(Self, Request, Response, Result);
end;

function DispatchHandler(Sender: TObject; Dispatch: IWebDispatch; Request: TWebRequest; Response: TWebResponse;
  DoDefault: Boolean): Boolean;
begin
  Result := False;
  if (Dispatch.Enabled and ((Dispatch.MethodType = mtAny) or
    (Dispatch.MethodType = Dispatch.MethodType)) and
    Dispatch.Mask.Matches(Request.PathInfo)) then
  begin
    Result := Dispatch.DispatchRequest(Sender, Request, Response);
  end;
end;

function TCustomWebDispatcher.DispatchAction(Request: TWebRequest;
  Response: TWebResponse): Boolean;
var
  I: Integer;
  Action, Default: TWebActionItem;
  Dispatch: IWebDispatch;
begin
  FRequest := Request;
  FResponse := Response;
  I := 0;
  Default := nil;
  Result := DoBeforeDispatch(Request, Response) or Response.Sent;
  while not Result and (I < FActions.Count) do
  begin
    Action := FActions[I];
    Result := Action.DispatchAction(Request, Response, False);
    if Action.Default then Default := Action;
    Inc(I);
  end;
  // Dispatch to self registering components
  I := 0;
  while not Result and (I < FDispatchList.Count) do
  begin
    if FDispatchList.Items[I].GetInterface(IWebDispatch, Dispatch) then
    begin
      Result := DispatchHandler(Self, Dispatch,
        Request, Response, False);
    end;
    Inc(I);
  end;

  if not Result and Assigned(Default) then
    Result := Default.DispatchAction(Request, Response, True);
  if Result and not Response.Sent then
    Result := DoAfterDispatch(Request, Response);

end;

function TCustomWebDispatcher.GetAction(Index: Integer): TWebActionItem;
begin
  Result := FActions[Index];
end;

procedure TCustomWebDispatcher.Notification(AComponent: TComponent;
  Operation: TOperation);
var
  I: Integer;
  DispatchIntf: IWebDispatch;
begin
  inherited Notification(AComponent, Operation);
  if (Operation = opInsert) then
  begin
    if (AComponent is TCustomContentProducer) then
      TCustomContentProducer(AComponent).Dispatcher := Self
    else if AComponent.GetInterface(IWebDispatch, DispatchIntf) then
      FDispatchList.Add(AComponent);
  end;
  if (Operation = opRemove) and (AComponent is TCustomContentProducer) then
    for I := 0 to FActions.Count - 1 do
      if FActions.Items[I].Producer = AComponent then
        FActions.Items[I].Producer := nil;
end;

procedure TCustomWebDispatcher.SetActions(Value: TWebActionItems);
begin
  FActions.Assign(Value);
end;

{ TWebModule }

constructor TWebModule.Create(AOwner: TComponent);
begin
  inherited Create(AOwner);
  if (ClassType <> TCustomWebDispatcher) and not (csDesigning in ComponentState) then
  begin
    if not InitInheritedComponent(Self, TCustomWebDispatcher) then
      raise EResNotFound.CreateFmt(SResNotFound, [ClassName]);
    try
      if Assigned(OnCreate) and OldCreateOrder then OnCreate(Self);
    except
      Forms.Application.HandleException(Self);
    end;
  end;
end;

function HTTPDecode(const AStr: String): String;
var
  Sp, Rp, Cp: PChar;
begin
  SetLength(Result, Length(AStr));
  Sp := PChar(AStr);
  Rp := PChar(Result);
  while Sp^ <> #0 do
  begin
    if not (Sp^ in ['+','%']) then
      Rp^ := Sp^
    else
      if Sp^ = '+' then
        Rp^ := ' '
      else
      begin
        inc(Sp);
        if Sp^ = '%' then
          Rp^ := '%'
        else
        begin
          Cp := Sp;
          Inc(Sp);
          Rp^ := Chr(StrToInt(Format('$%s%s',[Cp^, Sp^])));
        end;
      end;
    Inc(Rp);
    Inc(Sp);
  end;
  SetLength(Result, Rp - PChar(Result));
end;

function HTTPEncode(const AStr: String): String;
const
  NoConversion = ['A'..'Z','a'..'z','*','@','.','_','-',
                  '0'..'9','$','!','''','(',')'];
var
  Sp, Rp: PChar;
begin
  SetLength(Result, Length(AStr) * 3);
  Sp := PChar(AStr);
  Rp := PChar(Result);
  while Sp^ <> #0 do
  begin
    if Sp^ in NoConversion then
      Rp^ := Sp^
    else
      if Sp^ = ' ' then
        Rp^ := '+'
      else
      begin
        FormatBuf(Rp^, 3, '%%%.2x', 6, [Ord(Sp^)]);
        Inc(Rp,2);
      end;
    Inc(Rp);
    Inc(Sp);
  end;
  SetLength(Result, Rp - PChar(Result));
end;

const
// These strings are NOT to be resourced

  Months: array[1..12] of string = (
    'Jan', 'Feb', 'Mar', 'Apr',
    'May', 'Jun', 'Jul', 'Aug',
    'Sep', 'Oct', 'Nov', 'Dec');
  DaysOfWeek: array[1..7] of string = (
    'Sun', 'Mon', 'Tue', 'Wed',
    'Thu', 'Fri', 'Sat');

function ParseDate(const DateStr: string): TDateTime;
var
  Month, Day, Year, Hour, Minute, Sec: Integer;
  Parser: TParser;
  StringStream: TStringStream;

  function GetMonth: Boolean;
  begin
    Month := 1;
    while not Parser.TokenSymbolIs(Months[Month]) and (Month < 13) do Inc(Month);
    Result := Month < 13;
  end;

  procedure GetTime;
  begin
    with Parser do
    begin
      Hour := TokenInt;
      NextToken;
      if Token = ':' then NextToken;
      Minute := TokenInt;
      NextToken;
      if Token = ':' then NextToken;
      Sec := TokenInt;
      NextToken;
    end;
  end;

begin
  StringStream := TStringStream.Create(DateStr);
  try
    Parser := TParser.Create(StringStream);
    with Parser do
    try
      NextToken;
      if Token = ':' then NextToken;
      NextToken;
      if Token = ',' then NextToken;
      if GetMonth then
      begin
        NextToken;
        Day := TokenInt;
        NextToken;
        GetTime;
        Year := TokenInt;
      end else
      begin
        Day := TokenInt;
        NextToken;
        if Token = '-' then NextToken;
        GetMonth;
        NextToken;
        if Token = '-' then NextToken;
        Year := TokenInt;
        if Year < 100 then Inc(Year, 1900);
        NextToken;
        GetTime;
      end;
      Result := EncodeDate(Year, Month, Day) + EncodeTime(Hour, Minute, Sec, 0);
    finally
      Free;
    end;
  finally
    StringStream.Free;
  end;
end;

procedure ExtractHeaderFields(Separators, WhiteSpace: TSysCharSet; Content: PChar;
  Strings: TStrings; Decode: Boolean; StripQuotes: Boolean = False);
var
  Head, Tail: PChar;
  EOS, InQuote, LeadQuote: Boolean;
  QuoteChar: Char;

  function DoStripQuotes(const S: string): string;
  var
    I: Integer;
  begin
    Result := S;
    if StripQuotes then
      for I := Length(Result) downto 1 do
        if Result[I] in ['''', '"'] then
          Delete(Result, I, 1);
  end;

begin
  if (Content = nil) or (Content^ = #0) then Exit;
  Tail := Content;
  InQuote := False;
  QuoteChar := #0;
  repeat
    while Tail^ in WhiteSpace + [#13, #10] do Inc(Tail);
    Head := Tail;
    LeadQuote := False;
    while True do
    begin
      while (InQuote and (Tail^ <> '"')) or
        not (Tail^ in Separators + [#0, #13, #10, '"']) do Inc(Tail);
      if Tail^ = '"' then
      begin
        if (QuoteChar <> #0) and (QuoteChar = Tail^) then
          QuoteChar := #0
        else
        begin
          LeadQuote := Head = Tail;
          QuoteChar := Tail^;
          if LeadQuote then Inc(Head);
        end;
        InQuote := QuoteChar <> #0;
        if InQuote then
          Inc(Tail)
        else Break;
      end else Break;
    end;
    if not LeadQuote and (Tail^ <> #0) and (Tail^ = '"') then
      Inc(Tail);
    EOS := Tail^ = #0;
    Tail^ := #0;
    if Head^ <> #0 then
      if Decode then
        Strings.Add(DoStripQuotes(HTTPDecode(Head)))
      else Strings.Add(DoStripQuotes(Head));
    Inc(Tail);
  until EOS;
end;

procedure ExtractHTTPFields(Separators, WhiteSpace: TSysCharSet; Content: PChar;
  Strings: TStrings; StripQuotes: Boolean = False);
begin
  ExtractHeaderFields(Separators, WhiteSpace, Content, Strings, True, StripQuotes);
end;

function StatusString(StatusCode: Integer): string;
begin
  case StatusCode of
    100: Result := 'Continue';
    101: Result := 'Switching Protocols';
    200: Result := 'OK';
    201: Result := 'Created';
    202: Result := 'Accepted';
    203: Result := 'Non-Authoritative Information';
    204: Result := 'No Content';
    205: Result := 'Reset Content';
    206: Result := 'Partial Content';
    300: Result := 'Multiple Choices';
    301: Result := 'Moved Permanently';
    302: Result := 'Moved Temporarily';
    303: Result := 'See Other';
    304: Result := 'Not Modified';
    305: Result := 'Use Proxy';
    400: Result := 'Bad Request';
    401: Result := 'Unauthorized';
    402: Result := 'Payment Required';
    403: Result := 'Forbidden';
    404: Result := 'Not Found';
    405: Result := 'Method Not Allowed';
    406: Result := 'None Acceptable';
    407: Result := 'Proxy Authentication Required';
    408: Result := 'Request Timeout';
    409: Result := 'Conflict';
    410: Result := 'Gone';
    411: Result := 'Length Required';
    412: Result := 'Unless True';
    500: Result := 'Internal Server Error';
    501: Result := 'Not Implemented';
    502: Result := 'Bad Gateway';
    503: Result := 'Service Unavailable';
    504: Result := 'Gateway Timeout';
  else
    Result := '';
  end
end;

function TranslateChar(const Str: string; FromChar, ToChar: Char): string;
var
  I: Integer;
begin
  Result := Str;
  for I := 1 to Length(Result) do
    if Result[I] = FromChar then
      Result[I] := ToChar;
end;

function UnixPathToDosPath(const Path: string): string;
begin
  Result := TranslateChar(Path, '/', '\');
end;

function DosPathToUnixPath(const Path: string): string;
begin
  Result := TranslateChar(Path, '\', '/');
end;

function MonthStr(DateTime: TDateTime): string;
var
  Year, Month, Day: Word;
begin
  DecodeDate(DateTime, Year, Month, Day);
  Result := Months[Month];
end;

function DayOfWeekStr(DateTime: TDateTime): string;
begin
  Result := DaysOfWeek[DayOfWeek(DateTime)];
end;

end.
