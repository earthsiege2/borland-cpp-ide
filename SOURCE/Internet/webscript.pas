
{*******************************************************}
{                                                       }
{       Borland Delphi Visual Component Library         }
{       Web server application components               }
{                                                       }
{  Copyright (c) 2000-2001 Borland Software Corp.       }
{                                                       }
{*******************************************************}

unit WebScript;

interface

uses SysUtils, Classes, Contnrs, HTTPApp, HTTPProd, AscrLib, ActiveX, SiteComp, WebScript_TLB, WebAuto,
  WebCntxt;

type

  { Exception to look out for }
  EActiveScriptError = class(EWebBrokerException);

  ECannotCreateScriptEngine = class(EActiveScriptError)
  private
    FProgID: string;
    FHR: HRESULT;
  public
    constructor Create(const AProgID: string; AHR: HRESULT);
    property ProgID: string read FProgID;
    property HR: HRESULT read FHR;
  end;

  ERecursiveIncludeFile = class(EActiveScriptError)
  end;

  THTMLItem = class;
  THTMLItems = class;
  TScriptItem = class;
  TScriptItems = class;
  TLineNumberMap = class;

  TScriptProducer = class;
  TScriptFile = class
  private
    FSourceStream: TStream;
    FStreamOwned: Boolean;
    FProducer: TScriptProducer;
    FScriptItems: TScriptItems;
    FLineNumberMap: TLineNumberMap;
    function GetScript: WideString;
    function GetSource: string;
    function GetApplicationName: WideString;
    function GetLongName: WideString;
    function GetShortName: WideString;
    function GetDestLineCount: Integer;
  public
    constructor Create(AProducer: TScriptProducer);
    destructor Destroy; override;
    procedure ParseStream(ASource: TStream; AOwned: Boolean);
    procedure ParseString(const ASource: string);
    property Script: WideString read GetScript;
    property Source: string read GetSource;
    property ShortName: WideString read GetShortName;
    property LongName: WideString read GetLongName;
    property ApplicationName: WideString read GetApplicationName;
  end;
  {$EXTERNALSYM TScriptFile}  

  TIncludeType = (incFile, incPage);
  TScriptIncludeFile = class(TScriptFile)
  private
    FFileName: string;
    FIncludeType: TIncludeType;
    FLoaded: Boolean;
    FLoading: Boolean;
    procedure LoadIncludeFile;
    procedure LoadIncludePage;
  public
    constructor Create(AProducer: TScriptProducer; AIncludeType: TIncludeType; const AFileName: string);
    procedure LoadFile;
  end;
  {$EXTERNALSYM TScriptIncludeFile}

  TScriptIncludeFiles = class(TObjectList)
  private
    FProducer: TScriptProducer;
  public
    constructor Create(AProducer: TScriptProducer);
    function GetScriptIncludeFile(I: Integer): TScriptIncludeFile;
    property Items[Index: Integer]: TScriptIncludeFile read GetScriptIncludeFile; default;
  end;
  {$EXTERNALSYM TScriptIncludeFiles}

  TScriptProducer = class(TAbstractScriptProducer, IScriptProducer, IScriptContext)
  private
    FDesigning: Boolean;
    FScriptFile: TScriptFile;
    FHTMLItems: THTMLItems;
    FIncludeFiles: TScriptIncludeFiles;
    FWebModuleContext: TWebModuleContext;
    FStripParamQuotes: Boolean;
    FHandleTag: THandleTagProc;
    FContent: TMemoryStream;
    FErrors: TAbstractScriptErrors;
    FScriptEngine: string;
    FLocateFileService: ILocateFileService;
    function EvaluateExpression(AScriptFile: TScriptFile): string;
    function GetHTMLItem(I: Integer): THTMLItem;
    function GetHTMLItemCount: Integer;
    function GetScript: string;
    function GetComponent: TComponent;
    procedure WritePChar(const AValue: PChar; ALength: Integer);
  protected
    { IScriptContext }
    function GetWebModuleContext: TWebModuleContext;
    { IScriptProducer }
    function GetHTMLBlock(I: Integer): WideString;
    function GetHTMLBlockCount: Integer;
    function GetErrors: TAbstractScriptErrors;
    procedure ParseStream(Stream: TStream; Owned: Boolean);
    procedure ParseString(const S: string);
    function ReplaceTags(const AValue: string): string;
    function Evaluate: string;
    procedure HandleParserError(E: Exception);
    function HandleScriptError(const ScriptError: IUnknown): HRESULT;
    procedure Write(const AValue: PWideChar; ALength: Integer); overload;
    procedure Write(const Value: string); overload;
    function  GetContent: string;
    procedure SetContent(const Value: string);
    procedure WriteItem(Index: Integer);
    property Script: string read GetScript;
    property Errors: TAbstractScriptErrors read FErrors;
    property Designing: Boolean read FDesigning;
    property Component: TComponent read GetComponent;
    property Content: string read GetContent;
  public
    constructor Create(AWebModuleContext: TWebModuleContext;
        AStripParamQuotes: Boolean; AHandleTag: THandleTagProc;
        const AScriptEngine: string; ALocateFileService: ILocateFileService); override;
    destructor Destroy; override;
  end;
  {$EXTERNALSYM TScriptProducer}

  TAbstractScriptObjectFactory = class;

  TAbstractScriptSite = class;
  TScriptSiteClass = class of TAbstractScriptSite;
  TAbstractScriptSite = class(TInterfacedObject, IActiveScriptSite)
  private
    FProducer: IScriptProducer;
    function GetWebModuleContext: TWebModuleContext;
  protected
    { IActiveScriptSite }
    function  GetLCID(out plcid: LongWord): HResult; stdcall;
    function  GetItemInfo(pstrName: PWideChar; dwReturnMask: LongWord; out ppiunkItem: IUnknown;
                          out ppti: IUnknown): HResult; stdcall;
    function  GetDocVersionString(out pbstrVersion: WideString): HResult; stdcall;
    function  OnScriptTerminate(var pvarResult: OleVariant; var pexcepinfo: EXCEPINFO): HResult; stdcall;
    function  OnStateChange(ssScriptState: tagSCRIPTSTATE): HResult; stdcall;
    function  OnScriptError(const pscripterror: IActiveScriptError): HResult; stdcall;
    function  OnEnterScript: HResult; stdcall;
    function  OnLeaveScript: HResult; stdcall;

    function GetNamedItemCount: Integer; virtual; abstract;
    function GetNamedItemName(I: Integer): string; virtual; abstract;
  public
    constructor Create(AProducer: IScriptProducer); virtual;
    procedure RunExpression(AScriptFile: TScriptFile;
      AEngine: IActiveScript); virtual; abstract;
    procedure AddNamedIntf(const AName: string; AIntf: IUnknown); virtual; abstract;
    procedure AddNamedComponentIntf(const AName: string; AObject: TObject); virtual; abstract;
    function FindNamedItemIntf(const AName: string): IUnknown; virtual; abstract;
    property WebModuleContext: TWebModuleContext read GetWebModuleContext;
    property NamedItemCount: Integer read GetNamedItemCount;
    property NamedItemName[I: Integer]: string read GetNamedItemName;
    property Producer: IScriptProducer read FProducer;
  end;
  {$EXTERNALSYM TAbstractScriptSite}

  TVariableLookup = class(TObject)
  private
    FValue: Variant;
    FIdent: string;
    FObject: TObject;
    FWebModuleContext: TWebModuleContext;
    function FindFieldVariable(AParent: TComponent;
      const AName: string): TComponent;
    function FindVariable(const AName: string): TComponent;
    procedure SetIdent(const Value: string);
    function GetObject: TObject;
  public
    function FindGlobalVariable(const AName: string): TComponent;
    function FindGlobalVariableContainer(const AName: string): TComponent;
    constructor Create(const AIdent: string; AWebModuleContext: TWebModuleContext);
    function LookupObject: Boolean;
    property Ident: string read FIdent write SetIdent;
    property Obj: TObject read GetObject;
  end;

  THTMLItems = class(TObjectList)
  private
    FStream: TMemoryStream;
    FBuffer: PChar;
    FProducer: TScriptProducer;
  public
    constructor Create(AProducer: TScriptProducer);
    destructor Destroy; override;
    procedure Prepare;
    function MakeIdentifier(AItem: THTMLItem): string;
    function GetHTMLItem(I: Integer): THTMLItem;
    property Items[Index: Integer]: THTMLItem read GetHTMLItem; default;
  end;
  {$EXTERNALSYM THTMLItems}

  THTMLItem = class(TObject)
  private
    FItems: THTMLItems;
    FIndex: Integer;
    FOffset: Integer;
    FStreamOffset: Integer;
    FLength: Integer;
    FTagToken: Boolean;
    function GetHTML: WideString;
    function GetIdent: string;
    function GetPHTMLChar: PChar;
    function GetHTMLString: string;
  public
    constructor Create(AItems: THTMLItems);
    procedure AssignString(AOffset: Integer; AHTML: PChar; ALength: Integer);
    property Offset: Integer read FOffset;
    property Ident: string read GetIdent;
    property HTML: WideString read GetHTML;
    property TagToken: Boolean read FTagToken write FTagToken;
    property Length: Integer read FLength;
  end;
  {$EXTERNALSYM THTMLItem}

  TScriptItems = class(TObjectList)
  private
    FProducer: TScriptProducer;
  public
    constructor Create(AProducer: TScriptProducer);
    function GetScriptItem(I: Integer): TScriptItem;
    property Items[Index: Integer]: TScriptItem read GetScriptItem; default;
  end;
  {$EXTERNALSYM TScriptItems}

  TScriptItem = class(TObject)
  private
    FItems: TScriptItems;
  protected
    function GetScript: string; virtual;
  public
    constructor Create(AItems: TScriptItems);
    property Script: string read GetScript;
  end;
  {$EXTERNALSYM TScriptItem}

  TScriptCodeItem = class(TScriptItem)
  private
    FScript: string;
  protected
    function GetScript: string; override;
  public
    procedure AssignString(const AValue: string);
  end;
  {$EXTERNALSYM TScriptCodeItem}

  TScriptIncludeItem = class(TScriptItem)
  private
    FScriptIncludeFile: TScriptIncludeFile;
  protected
    function GetScript: string; override;
  public
    constructor Create(AItems: TScriptItems;  AIncludeFile: TScriptIncludeFile);
  end;
  {$EXTERNALSYM TScriptIncludeItem}

  TGlobalScriptVariables = (
    svPage, svPages, svModules, svApplication, svSession, svEndUser, svResponse, svRequest, svHTMLItems, svProducer);

  TAbstractScriptObjectFactory = class
  protected
    procedure AddGlobalObjects(AScriptSite: TAbstractScriptSite); virtual;
  public
    function CreateGlobalObject(AVariable: TGlobalScriptVariables; AContext: IScriptContext): IDispatch; virtual; abstract;
    constructor Create;
    destructor Destroy; override;
  end;
  {$EXTERNALSYM TAbstractScriptObjectFactory}

  TScriptObjectFactory = class(TAbstractScriptObjectFactory)
  protected
    procedure AddGlobalObjects(AScriptSite: TAbstractScriptSite); override;
  public
    function CreateGlobalObject(AVariable: TGlobalScriptVariables; AContext: IScriptContext): IDispatch; override;
  end;
  {$EXTERNALSYM TScriptObjectFactory}

  TBaseScriptSite = class(TAbstractScriptSite)
  private
    FIntfList: IInterfaceList;
    FNamedList: TStrings;
  public
    procedure RunExpression(AScriptFile: TScriptFile;
      AEngine: IActiveScript); override;
    function GetNamedItemCount: Integer; override;
    function GetNamedItemName(I: Integer): string; override;
    procedure AddNamedIntf(const AName: string; AIntf: IUnknown); override;
    procedure AddNamedComponentIntf(const AName: string; AObject: TObject); override;
    function FindNamedItemIntf(const AName: string): IUnknown; override;
    constructor Create(AProducer: IScriptProducer); override;
    destructor Destroy; override;
  end;
  {$EXTERNALSYM TBaseScriptSite}

  TScriptSite = class(TBaseScriptSite);

  TScriptErrors = class(TAbstractScriptErrors)
  private
    FList: TObjectList;
  protected
    function GetError(I: Integer): TAbstractScriptError; override;
    function GetErrorCount: Integer; override;
  public
    constructor Create;
    destructor Destroy; override;
    procedure Add(const AError: TAbstractScriptError); override;
  end;

  TScriptError = class(TAbstractScriptError)
  private
    FLine: Integer;
    FCharPos: Integer;
    FDescription: string;
    FSourceLine: string;
    FFileName: string;
  protected
    function GetSourceLine: string; override;
    function GetCharPos: Integer;  override;
    function GetLine: Integer; override;
    function GetDescription: string; override;
    procedure SetDescription(const AValue: string); override;
    function GetFileName: string; override;
  public
    constructor Create(const ScriptError: IActiveScriptError; ALineNumberMap: TLineNumberMap); overload;
    constructor Create(E: Exception); overload;
  end;

  TWebResponseWrapper = class;
  THTMLItemsWrapper = class;

  TWebResponseWrapper = class(TScriptObject, IResponseWrapper)
  private
    FProducer: IScriptProducer;
  private
    { IResponseWrapper }
    procedure Write(varText: OleVariant); safecall;
    function  Get_Content: WideString; safecall;
    procedure Set_Content(const Value: WideString); safecall;
  public
    constructor Create(AProducer: IScriptProducer);
    property Content: WideString read Get_Content write Set_Content;
  end;
  {$EXTERNALSYM TWebResponseWrapper}

  TWebRequestWrapper = class(TScriptObject, IRequestWrapper)
  protected
    function Request: TWebRequest;
    { IRequestWrapper }
    function  Get_PathInfo {Flags(1), (1/0) CC:0, INV:2, DBG:6}: WideString; safecall;
    function  Get_ScriptName {Flags(1), (1/0) CC:0, INV:2, DBG:6}: WideString; safecall;
    function  Get_Host {Flags(1), (1/0) CC:0, INV:2, DBG:6}: WideString; safecall;
  public
    constructor Create(AContext: IScriptContext);
  end;

  TWebSessionIDWrapper = class(TScriptObject, ISessionIDWrapper)
  protected
    function  Get_Value: WideString; safecall;
  end;

  TWebSessionWrapper = class(TScriptObject, ISessionWrapper)
  private
    FSessionIDWrapper: ISessionIDWrapper;
  protected
    { IWebSession }
    function  Get_Values(const Name: WideString): OleVariant; safecall;
    function  Get_SessionID: ISessionIDWrapper; safecall;
  end;

  TWebProducerWrapper = class(TScriptObject, IProducerWrapper)
  private
    FProducer: IScriptProducer;
  private
    { IAdapterRecordWrapper }
    procedure Write(varText: OleVariant); safecall;
    function  Get_Content: WideString; safecall;
    procedure Set_Content(const Value: WideString); safecall;
  public
    constructor Create(AProducer: IScriptProducer);
    property Content: WideString read Get_Content write Set_Content;
  end;
  {$EXTERNALSYM TWebProducerWrapper}  

  THTMLItemsWrapper = class(TScriptObject, IHTMLItemsWrapper)
  private
    FProducer: IScriptProducer;
  protected
    function  Get_ControlDefault({VT_3:0}Index: Integer): OleVariant; safecall;
    function  Count: Integer; safecall;
    function  Get_Item({VT_3:0}Index: Integer): WideString; safecall;
    procedure  WriteItem({VT_3:0}Index: Integer); safecall;
    property ControlDefault[{VT_3:0}Index: Integer]: OleVariant read Get_ControlDefault; default;
    property Item[{VT_3:0}Index: Integer]: WideString read Get_Item;
  public
    constructor Create(AProducer: IScriptProducer);
  end;
  {$EXTERNALSYM THTMLItemsWrapper}  

  TCurrentWebPageInfo = class(TInterfacedObject, IWebPageInfo)
  private
    FContext: IScriptContext;
    FWebPageInfo: IWebPageInfo;
  protected
    function WebPageInfo: IWebPageInfo;
    { IWebPageInfo }
    function GetPageName: string;
    function GetPageHREF: string;
    function GetPageDescription: string;
    function GetPageTitle: string;
    function GetPageIsPublished: Boolean;
    function GetLoginRequired: Boolean;
    function GetHasViewAccess: Boolean;
  public
    constructor Create(AContext: IScriptContext);
  end;

  TSampleWebPageInfo = class(TInterfacedObject, IWebPageInfo)
  private
    FPageName: string;
  protected
    { IWebPageInfo }
    function GetPageName: string;
    function GetPageHREF: string;
    function GetPageDescription: string;
    function GetPageTitle: string;
    function GetPageIsPublished: Boolean;
    function GetLoginRequired: Boolean;
    function GetHasViewAccess: Boolean;
  public
    constructor Create(const APageName: string);
  end;

  TWebPageWrapper = class(TScriptObject, IPageWrapper)
  private
    FPageInfo: IWebPageInfo;
    FPageDispatcher: IPageDispatcher;
    FContext: IScriptContext;
  protected
    { IWebPage }
    function  Get_Name: WideString; safecall;
    function  Get_HREF: WideString; safecall;
    function  Get_Title: WideString; safecall;
    function  Get_Description: WideString; safecall;
    function  Get_Published_: WordBool; safecall;
    function  Get_LoginRequired: WordBool; safecall;
    function  Get_CanView: WordBool; safecall;
    function  Get_DefaultAction: IAdapterActionWrapper; safecall;
  public
    constructor Create(AContext: IScriptContext; const APageInfo: IWebPageInfo);
    function PageDispatcher: IPageDispatcher;
    property Name: WideString read Get_Name;
  end;

  TWebModulesWrapper = class(TWebComponentsWrapper, IModulesWrapper)
  protected
    function  Get_NewEnum {Flags(1), (1/0) CC:0, INV:1, DBG:6}: IUnknown; safecall;
    function FindObject(const AName: string): TObject; override;
  end;

  TWebPagesWrapper = class(TWebComponentsWrapper, IPagesWrapper)
  private
    FSamplePages: IInterfaceList;
    FContext: IScriptContext;
  protected
    { IWebPages }
    function  Get_NewEnum {Flags(1), (1/0) CC:0, INV:1, DBG:6}: IUnknown; safecall;
    function DispatchOfName(const AName: string): IDispatch; override;
    function FindPageInfo(const AName: string): IWebPageInfo;
    function FindSamplePage(const AName: string): IWebPageInfo;
  public
    constructor Create(AContext: IScriptContext); reintroduce;
  end;

  TListEnumerator = class(TScriptObject, IEnumVariant)
  private
    FReset: Boolean;
    FCurrentIndex: Integer;
  protected
    function GetListCount: Integer; virtual;
    function GetListItem(I: Integer): IDispatch; virtual;
    { IEnumVariant }
    function Clone(out ppenum: IEnumVARIANT): HResult; stdcall;
    function Next(celt: LongWord; var rgvar: OleVariant;
      out pceltFetched: LongWord): HResult; stdcall;
    function Reset: HResult; stdcall;
    function Skip(celt: LongWord): HResult; stdcall;
    function EOF: Boolean;
  public
    constructor Create;
  end;

  TWebPagesEnumerator = class(TListEnumerator)
  private
    FContext: IScriptContext;
  protected
    function GetListCount: Integer; override;
    function GetListItem(I: Integer): IDispatch; override;
  public
    constructor Create(AContext: IScriptContext);
  end;

  TWebModulesEnumerator = class(TListEnumerator)
  protected
    function GetListCount: Integer; override;
    function GetListItem(I: Integer): IDispatch; override;
  end;

  TScriptObjectFactories = class(TObject)
  private
    FObjectList: TObjectList;
    function GetCount: Integer;
    function GetFactory(I: Integer): TAbstractScriptObjectFactory;
  public
    constructor Create;
    destructor Destroy; override;
    function CreateGlobalObject(AVariable: TGlobalScriptVariables; AContext: IScriptContext): IDispatch;
    property Count: Integer read GetCount;
    property Factories[I: Integer]: TAbstractScriptObjectFactory read GetFactory; default;
  end;
  {$EXTERNALSYM TScriptObjectFactories}

  TLineNumbers = record
    SourceStartLine: Integer;
    SourceLineCount: Integer;
    DestStartLine: Integer;
    DestLineCount: Integer;
    ScriptIncludeFile: TScriptIncludeFile;
  end;

  PLineNumbers = ^TLineNumbers;

  TLineNumberMap = class(TObject)
  private
    FFileName: string;
    FArray: array of TLineNumbers;
    function GetCount: Integer;
    function GetLineNumbers(I: Integer): PLineNumbers;
  public
    function New: PLineNumbers;
    function DestLineToSourceLine(ALine: Integer; var AFileName: string): Integer;
    property Count: Integer read GetCount;
    property Items[I: Integer]: PLineNumbers read GetLineNumbers; default;
  end;
var
  ScriptSiteClass: TScriptSiteClass;
  ScriptObjectFactories: TScriptObjectFactories;
  {$EXTERNALSYM ScriptObjectFactories} 
const
  GlobalScriptVariableNames: array[TGlobalScriptVariables] of string =
    ('Page', 'Pages', 'Modules', 'Application', 'Session', 'EndUser', 'Response', 'Request', 'HTML_',
    'Producer');

implementation

uses Windows, CopyPrsr, WebConst, WebComp, Variants, ComObj, AutoAdap, WebDisp, SiteConst;

procedure RaiseCannotCreateScriptEngine(const AProgID: string;
  HR: HRESULT);
begin
  raise ECannotCreateScriptEngine.Create(AProgID, HR);
end;

procedure RaiseIncludePageNotFound(const APage: string);
begin
  raise EActiveScriptError.CreateFmt(sCantFindIncludePage, [APage]);
end;

procedure RaisePageDoesNotSupportInclusion(const APage: string);
begin
  raise EActiveScriptError.CreateFmt(sInclusionNotSupported, [APage]);
end;

{ TScriptProducer }

procedure TScriptProducer.ParseStream(Stream: TStream; Owned: Boolean);
begin
  FHTMLItems.Clear;
  FScriptFile.ParseStream(Stream, Owned);
  FHTMLItems.Prepare;
end;

procedure TScriptProducer.ParseString(const S: string);
begin
  FHTMLItems.Clear;
  FScriptFile.ParseString(S);
  FHTMLItems.Prepare;
end;

constructor TScriptProducer.Create(AWebModuleContext: TWebModuleContext;
    AStripParamQuotes: Boolean; AHandleTag: THandleTagProc;
    const AScriptEngine: string; ALocateFileService: ILocateFileService);
begin
  inherited Create(AWebModuleContext, AStripParamQuotes, AHandleTag, AScriptEngine,
    ALocateFileService);
  FContent := TMemoryStream.Create;
  FDesigning := (AWebModuleContext is TComponent) and (csDesigning in TComponent(AWebModuleContext).ComponentState);
  FLocateFileService := ALocateFileService;
  FScriptEngine := AScriptEngine;
  if FScriptEngine = '' then
    FScriptEngine := 'JSCRIPT';
  FErrors := TScriptErrors.Create;
  FHTMLItems := THTMLItems.Create(Self);
  FScriptFile := TScriptFile.Create(Self);
  FIncludeFiles := TScriptIncludeFiles.Create(Self);
  FWebModuleContext := AWebModuleContext;
  FStripParamQuotes := AStripParamQuotes;
  FHandleTag := AHandleTag;
end;

destructor TScriptProducer.Destroy;
begin
  inherited;
  FHTMLItems.Free;
  FScriptFile.Free;
  FIncludeFiles.Free;
  FErrors.Free;
  FContent.Free;
end;

function TScriptProducer.GetHTMLItemCount: Integer;
begin
  Result := FHTMLItems.Count;
end;

function TScriptProducer.GetHTMLItem(I: Integer): THTMLItem;
begin
  Result := THTMLItem(FHTMLItems[I]);
end;

function TScriptProducer.GetHTMLBlock(I: Integer): WideString;
begin
  Result := GetHTMLItem(I).HTML;
end;

function TScriptProducer.EvaluateExpression(AScriptFile: TScriptFile): string;
var
  ClsID: TGUID;
  hr: HRESULT;
  Engine: IActiveScript;
  Parser: IActiveScriptParse;
  ScriptSite: TAbstractScriptSite;
  SaveScriptSite: IUnknown;
  ProgID: WideString;
  E: Exception;
begin
  ProgID := FScriptEngine;
  CLSIDFromProgID(PWideChar(ProgID), ClsID);

  // Call coinitialize on this thread
  if (CoInitFlags <> -1) and Assigned(ComObj.CoInitializeEx) then
    ComObj.CoInitializeEx(nil, CoInitFlags);

  hr := CoCreateInstance(ClsID, nil, CLSCTX_INPROC_SERVER,
      IActiveScript, Engine);
  if (FAILED(hr)) then
    RaiseCannotCreateScriptEngine(ProgID, hr);

  //Now query for the IActiveScriptParse interface of the engine
  hr := Engine.QueryInterface(IActiveScriptParse, Parser);
  OLECHECK(hr);

  //The engine needs to know the host it runs on.
  if ScriptSiteClass <> nil then
    ScriptSite := ScriptSiteClass.Create(Self)
  else
    ScriptSite := TScriptSite.Create(Self);
  SaveScriptSite := ScriptSite;
  ScriptSite.RunExpression(AScriptFile, Engine);
  hr := Engine.Close();
  OLECHECK(hr);

  if FErrors.Count > 0 then
  begin
    E := EScriptError.Create(FErrors, Content);
    FErrors := nil;
    raise E;
  end;

  Result := Content;
end;

function TScriptProducer.Evaluate: string;
begin
  Result := EvaluateExpression(FScriptFile);
end;

function TScriptProducer.GetContent: string;
begin
  SetString(Result, PChar(FContent.Memory), FContent.Size);
end;

procedure TScriptProducer.SetContent(const Value: string);
begin
  FContent.Size := 0;
  Write(Value);
end;

procedure TScriptProducer.Write(const AValue: PWideChar; ALength: Integer);
begin
  Write(WideCharLenToString(AValue, ALength));
end;

procedure TScriptProducer.WritePChar(const AValue: PChar; ALength: Integer);
begin
  FContent.Write(AValue[0], ALength)
end;

procedure TScriptProducer.Write(const Value: string);
begin
  FContent.Write(Value[1], Length(Value))
end;

function TScriptProducer.HandleScriptError(
  const ScriptError: IUnknown): HRESULT;
begin
  FErrors.Add(TScriptError.Create(ScriptError as IActiveScriptError, FScriptFile.FLineNumberMap));
  Result := S_OK;
end;

procedure TScriptProducer.HandleParserError(
  E: Exception);
begin
  FErrors.Add(TScriptError.Create(E));
end;

function TScriptProducer.GetScript: string;
begin
  Result := FScriptFile.Script;
end;

function TScriptProducer.GetErrors: TAbstractScriptErrors;
begin
  Result := FErrors;
end;

function TScriptProducer.GetComponent: TComponent;
begin
  if FWebModuleContext is TComponent then
    Result := TComponent(FWebModuleContext)
  else
    Result := nil;
end;

{ TVariableLookup }

function TVariableLookup.LookupObject: Boolean;
begin
  if (FObject = nil) and (FIdent <> '') then
    FObject := FindVariable(FIdent);
  Result := Assigned(FObject);
end;

function TVariableLookup.FindVariable(const AName: string): TComponent;
var
  S1, S2: string;
  P: Integer;
  Context: TComponent;
begin
  Result := nil;
  if AName <> '' then
  begin
    S1 := AName;
    Context := nil;
    P := Pos('.', S1);
    if P > 0 then
    begin
      while P > 0 do
      begin
        S2 := Copy(S1, 1, P-1);
        Delete(S1, 1, P);
        if not Assigned(Context) then
          Context := FindGlobalVariableContainer(S2)
        else
          Context := FindFieldVariable(Context, S2);
        if not Assigned(Context) then
          raise EActiveScriptError.CreateFmt(sVariableNotFound, [AName]);
        P := Pos('.', S1);
      end;
      Result := FindFieldVariable(Context, S1);
    end
    else
      Result := FindGlobalVariable(AName);
  end;
end;

function TVariableLookup.FindGlobalVariableContainer(const AName: string): TComponent;
var
  WebVariablesContainer: IWebVariablesContainer;
begin
  Result := nil;
  if FWebModuleContext <> nil then
  begin
    if Supports(FWebModuleContext, IWebVariablesContainer, WebVariablesContainer) then
    begin
      Result := WebVariablesContainer.FindVariableContainer(AName);
      if Assigned(Result) then
        Exit;
    end;
  end;
  if not Assigned(Result) then
    if WebContext <> nil then
    begin
      Result := WebContext.FindVariableContainer(AName);
      if Assigned(Result) then
        Exit;
    end;
  raise EActiveScriptError.CreateFmt(sVariableNotFound, [AName]);
end;

function TVariableLookup.FindGlobalVariable(const AName: string): TComponent;
var
  WebVariablesContainer: IWebVariablesContainer;
begin
  Result := nil;
  if AName <> '' then
    if FWebModuleContext <> nil then
      if Supports(FWebModuleContext, IWebVariablesContainer, WebVariablesContainer) then
        Result := WebVariablesContainer.FindVariable(AName)
      else
        Assert(False, 'IWebVariablesContainer not implemented');
end;

function TVariableLookup.FindFieldVariable(AParent: TComponent; const AName: string): TComponent;
var
  WebVariablesContainer: IWebVariablesContainer;
begin
  Result := nil;
  if Supports(IInterface(AParent), IWebVariablesContainer, WebVariablesContainer) then
    Result := WebVariablesContainer.FindVariable(AName)
end;

constructor TVariableLookup.Create(const AIdent: string; AWebModuleContext: TWebModuleContext);
begin
  inherited Create;
  Ident := AIdent;
  FWebModuleContext := AWebModuleContext;
end;

procedure TVariableLookup.SetIdent(const Value: string);
begin
  FIdent := Value;
  FValue := Unassigned;
  FObject := nil;
end;

function TVariableLookup.GetObject: TObject;
begin
  if LookupObject then
    Result := FObject
  else
    Result := nil;
end;

function TScriptProducer.ReplaceTags(const AValue: string): string;
begin
  Result := ContentFromString(AValue, FStripParamQuotes,
    FHandleTag, nil);
end;

function TScriptProducer.GetHTMLBlockCount: Integer;
begin
  Result := GetHTMLItemCount;
end;

function TScriptProducer.GetWebModuleContext: TWebModuleContext;
begin
  Result := FWebModuleContext;
end;

{ THTMLItem }

procedure THTMLItem.AssignString(AOffset: Integer; AHTML: PChar; ALength: Integer);
begin
  FOffset := AOffset;
  FStreamOffset := FItems.FStream.Size;
  FLength := ALength;
  FItems.FStream.Write(AHTML[0], ALength);
end;

constructor THTMLItem.Create(AItems: THTMLItems);
begin
  inherited Create;
  FItems := AItems;
  FIndex := AItems.Count;
  AItems.Add(Self);
end;

function THTMLItem.GetIdent: string;
begin
  Result := FItems.MakeIdentifier(Self);
end;

function THTMLItem.GetHTMLString: string;
begin
  SetString(Result, FItems.FBuffer + FStreamOffset, FLength);
end;

function THTMLItem.GetHTML: WideString;
begin
  Result := GetHTMLString;
end;

function THTMLItem.GetPHTMLChar: PChar;
begin
  Result := FItems.FBuffer + FStreamOffset;
end;

{ THTMLItems }

constructor THTMLItems.Create(AProducer: TScriptProducer);
begin
  inherited Create(True); // it owns the objects
  FProducer := AProducer;
  FStream := TMemoryStream.Create;
end;

destructor THTMLItems.Destroy;
begin
  FStream.Free;
  if FBuffer <> nil then
    FreeMem(FBuffer);
  inherited;
end;

function THTMLItems.GetHTMLItem(I: Integer): THTMLItem;
begin
  Result := THTMLItem(GetItem(I));
end;

function THTMLItems.MakeIdentifier(AItem: THTMLItem): string;
begin
  Result := Format('%s.Item(%d)', [GlobalScriptVariableNames[svHTMLItems], AItem.FIndex]);
end;

{ TAbstractScriptSite }

constructor TAbstractScriptSite.Create(AProducer: IScriptProducer);
begin
  FProducer := AProducer;
  inherited Create;
end;

function TAbstractScriptSite.GetDocVersionString(
  out pbstrVersion: WideString): HResult;
begin
  Result := E_NOTIMPL;
end;

function TAbstractScriptSite.GetItemInfo(pstrName: PWideChar;
  dwReturnMask: LongWord; out ppiunkItem: IUnknown;
  out ppti: IUnknown): HResult;
begin

   if (dwReturnMask and SCRIPTINFO_IUNKNOWN) <> 0 then
   begin
     ppiunkItem := FindNamedItemIntf(pstrName);
     if ppiunkItem <> nil then
       Result := S_OK
     else
       Result := E_NOTIMPL;
     Exit;
   end
   else if (dwReturnMask and SCRIPTINFO_ITYPEINFO) <> 0 then
   begin
     Result := E_NOTIMPL;
     Exit;
   end;

   Result := TYPE_E_ELEMENTNOTFOUND;
end;

function TAbstractScriptSite.GetLCID(out plcid: LongWord): HResult;
begin
  Result := E_NOTIMPL;
end;

function TAbstractScriptSite.OnEnterScript: HResult;
begin
  result := S_OK;
end;

function TAbstractScriptSite.OnLeaveScript: HResult;
begin
  result := S_OK;
end;

function TAbstractScriptSite.OnScriptError(
  const pscripterror: IActiveScriptError): HResult;
begin
  Result := Producer.HandleScriptError(pscripterror);
end;

function TAbstractScriptSite.OnScriptTerminate(var pvarResult: OleVariant;
  var pexcepinfo: ExcepInfo): HResult;
begin
  Result := S_OK;
end;

function TAbstractScriptSite.OnStateChange(ssScriptState: tagSCRIPTSTATE): HResult;
begin
   case ssScriptState of
     SCRIPTSTATE_UNINITIALIZED:;
     SCRIPTSTATE_INITIALIZED:;
     SCRIPTSTATE_STARTED:;
     SCRIPTSTATE_CONNECTED:;
     SCRIPTSTATE_DISCONNECTED:;
     SCRIPTSTATE_CLOSED:;
   end;

   Result := S_OK;
end;

function TAbstractScriptSite.GetWebModuleContext: TWebModuleContext;
begin
  Result := Producer.WebModuleContext;
end;

{ TBaseScriptSite }

procedure TBaseScriptSite.AddNamedIntf(const AName: string; AIntf: IUnknown);
begin
  FNamedList.Add(AName);
  FIntfList.Add(AIntf);
end;

procedure TBaseScriptSite.AddNamedComponentIntf(const AName: string; AObject: TObject);
var
  GetIntf: IGetScriptObject;
begin
  // Objects that do not implement IGetScriptObject have variable names in order to be located by the
  // adapter dispatcher but are not scriptable.
  if Supports(AObject, IGetScriptObject, GetIntf) then
    AddNamedIntf(AName, GetIntf.GetScriptObject)
end;

constructor TBaseScriptSite.Create(AProducer: IScriptProducer);
var
  I: Integer;
begin
  inherited Create(AProducer);
  FNamedList := TStringList.Create;
  FIntfList := TInterfaceList.Create;
  for I := 0 to ScriptObjectFactories.Count - 1 do
    ScriptObjectFactories[I].AddGlobalObjects(Self);
end;

procedure TBaseScriptSite.RunExpression(AScriptFile: TScriptFile; AEngine: IActiveScript);
var
  hr: HRESULT;
  Parser: IActiveScriptParse;
  I: Integer;
  ExcepInfo: TExcepInfo;
begin
  //Now query for the IActiveScriptParse interface of the engine
  hr := AEngine.QueryInterface(IActiveScriptParse, Parser);
  OLECHECK(hr);

  //The engine needs to know the host it runs on.
  hr := AEngine.SetScriptSite(Self);
  OLECHECK(hr);

  //Initialize the script engine so it's ready to run.
  hr := Parser.InitNew();
  OLECHECK(hr);

  for I := 0 to Self.NamedItemCount - 1 do
    AEngine.AddNamedItem(PWideChar(WideString(Self.NamedItemName[I])), SCRIPTITEM_ISVISIBLE);

  hr := Parser.ParseScriptText(PWideChar(AScriptFile.Script), nil {sScriptMain}, nil, nil,
       0, 0, 0, { V1 }nil, ExcepInfo);
  // hr <> S_OK means that an error occured.  FErrors should
  // contain the error
  Assert((hr = S_OK) or (Producer.Errors.Count > 0), 'Errors expected');

  if hr = S_OK then
  begin
    hr := AEngine.SetScriptState(SCRIPTSTATE_CONNECTED);
    // hr <> S_OK means that an error occured.  FErrors should
    // contain the error
    Assert((hr = S_OK) or (Producer.Errors.Count > 0), 'Errors expected');
  end;

end;

destructor TBaseScriptSite.Destroy;
begin
  inherited;
  FNamedList.Free;
end;

function TBaseScriptSite.FindNamedItemIntf(const AName: string): IUnknown;
var
  I: Integer;
begin
  I := FNamedList.IndexOf(AName);
  if I >= 0 then
    Result := FIntfList[I]
  else
    Result := nil;
end;

function TBaseScriptSite.GetNamedItemCount: Integer;
begin
  Result := FNamedList.Count;
end;

function TBaseScriptSite.GetNamedItemName(I: Integer): string;
begin
  Result := FNamedList[I];
end;

{ TWebResponseWrapper }

constructor TWebResponseWrapper.Create(AProducer: IScriptProducer);
begin
  FProducer := AProducer;
  inherited Create;
end;

function TWebResponseWrapper.Get_Content: WideString;
begin
  Result := FProducer.Content;
end;

procedure TWebResponseWrapper.Set_Content(const Value: WideString);
begin
  FProducer.Content := Value;
end;

procedure TWebResponseWrapper.Write(varText: OleVariant);
var
  W: WideString;
begin
  if not VarIsClear(varText) and not VarIsNull(varText) then
  begin
    if TVarData(varText).VType = varOleStr then
      FProducer.Write(TVarData(varText).VOleStr, Length(PWideString(@TVarData(varText).VOleStr)^))
    else
    begin
      W := varText;
      FProducer.Write(PWideChar(W), Length(W));
    end;
  end;
end;

{ TWebProducerWrapper }

constructor TWebProducerWrapper.Create(AProducer: IScriptProducer);
begin
  FProducer := AProducer;
  inherited Create;
end;

function TWebProducerWrapper.Get_Content: WideString;
begin
  Result := FProducer.Content;
end;

procedure TWebProducerWrapper.Set_Content(const Value: WideString);
begin
  FProducer.Content := FProducer.ReplaceTags(Value);
end;

procedure TWebProducerWrapper.Write(varText: OleVariant);
begin
  if not VarIsClear(varText) and not VarIsNull(varText) then
    FProducer.Write(FProducer.ReplaceTags(varText));
end;

{ THTMLItemsWrapper }

function THTMLItemsWrapper.Count: Integer;
begin
  Result := FProducer.HTMLBlockCount;
end;

constructor THTMLItemsWrapper.Create(AProducer: IScriptProducer);
begin
  FProducer := AProducer;
  inherited Create;
end;

function THTMLItemsWrapper.Get_ControlDefault(Index: Integer): OleVariant;
begin
  Result := FProducer.HTMLBlocks[Index];
end;

function THTMLItemsWrapper.Get_Item(Index: Integer): WideString;
begin
  Result := FProducer.HTMLBlocks[Index];
end;

{ TWebPageWrapper }

constructor TWebPageWrapper.Create(AContext: IScriptContext; const APageInfo: IWebPageInfo);
begin
  FPageInfo := APageInfo;
  FContext := AContext;
  inherited Create;
end;

function TWebPageWrapper.Get_Description: WideString;
begin
  Result := FPageInfo.PageDescription;
end;

function TWebPageWrapper.Get_Title: WideString;
begin
  Result := FPageInfo.PageTitle;
  if Result = '' then
    Result := FPageInfo.PageName;
end;

function TWebPageWrapper.Get_HREF: WideString;
begin
  Result := FPageInfo.PageHREF;
end;

function TWebPageWrapper.Get_Name: WideString;
begin
  Result := FPageInfo.PageName;
end;

function TWebPageWrapper.Get_Published_: WordBool;
begin
  Result := FPageInfo.PageIsPublished;
end;

function TWebPageWrapper.Get_LoginRequired: WordBool;
begin
  if PageDispatcher <> nil then
    Result := PageDispatcher.GetLoginRequired(FPageInfo.PageName)
  else
    Result := FPageInfo.LoginRequired;
end;

function TWebPageWrapper.Get_CanView: WordBool;
begin
  if PageDispatcher <> nil then
    Result := PageDispatcher.GetCanView(FPageInfo.PageName)
  else
    Result := FPageInfo.HasViewAccess;
end;

function TWebPageWrapper.PageDispatcher: IPageDispatcher;
var
  AppModule: TComponent;
  GetIntf: IGetWebAppComponents;
begin
  if not Assigned(FPageDispatcher) then
  begin
    if WebContext <> nil then
    begin
      AppModule := WebContext.FindApplicationModule(FContext.WebModuleContext);
      if Supports(IUnknown(AppModule), IGetWebAppComponents, GetIntf) then
        FPageDispatcher := GetIntf.GetPageDispatcher;
    end;
  end;
  Result := FPageDispatcher;
end;

function TWebPageWrapper.Get_DefaultAction: IAdapterActionWrapper;
var
  PageObj: TObject;
  ActionObj: TComponent;
  Intf: IGetDefaultAction;
  Link: TInterfacedObject;
  Wrapper: TAdapterActionWrapper;
begin
  Result := nil;
  if WebContext.FindPage(FPageInfo.PageName, [], PageObj) then
  begin
    if Supports(PageObj, IGetDefaultAction, Intf) then
    begin
      ActionObj := Intf.DefaultAction;
      if ActionObj <> nil then
      begin
        Link := TActionLink.Create(ActionObj, FPageInfo.PageName, FPageInfo.PageName);
        Wrapper := TAdapterActionWrapper.Create(Link);
        Result := Wrapper;
      end;
    end;
  end;
end;

{ TCurrentWebPageInfo }

constructor TCurrentWebPageInfo.Create(AContext: IScriptContext);
begin
  FContext := AContext;
  inherited Create;
end;

function TCurrentWebPageInfo.GetPageDescription: string;
begin
  if WebPageInfo <> nil then
    Result := WebPageInfo.PageDescription
  else
    Result := GetPageName;
end;

function TCurrentWebPageInfo.GetPageHREF: string;
begin
  if WebPageInfo <> nil then
    Result := WebPageInfo.PageHREF
  else
    Result := '';

end;

function TCurrentWebPageInfo.GetPageIsPublished: Boolean;
begin
  if WebPageInfo <> nil then
    Result := WebPageInfo.PageIsPublished
  else
    Result := False;
end;

function TCurrentWebPageInfo.GetLoginRequired: Boolean;
begin
  if WebPageInfo <> nil then
    Result := WebPageInfo.LoginRequired
  else
    Result := False;
end;

function TCurrentWebPageInfo.GetPageTitle: string;
begin
  if WebPageInfo <> nil then
    Result := WebPageInfo.PageTitle
  else
    Result := '';

end;

function TCurrentWebPageInfo.GetPageName: string;
begin
  if WebPageInfo <> nil then
    Result := WebPageInfo.PageName
  else
    Result := WebContext.DispatchedPageName
end;

function TCurrentWebPageInfo.WebPageInfo: IWebPageInfo;
var
  I: Integer;
begin
  Result := FWebPageInfo;
  if (Result = nil) and (WebContext <> nil) then
  begin
    for I := 0 to WebContext.PageCount - 1 do
    begin
      Result := WebContext.Pages[I];
      if CompareText(Result.PageName, WebContext.DispatchedPageName) = 0 then
        Exit;
    end;
    Result := nil;
  end;
end;

function TCurrentWebPageInfo.GetHasViewAccess: Boolean;
begin
  if WebPageInfo <> nil then
    Result := WebPageInfo.GetHasViewAccess
  else
    Result := True;
end;

{ ECannotCreateScriptEngine }

constructor ECannotCreateScriptEngine.Create(const AProgID: string;
  AHR: HRESULT);
begin
  FProgID := AProgID;
  FHR := AHR;
  inherited CreateFmt(sCannotCreateScriptEngine, [AProgID, HR]);
end;

{ TScriptError }

constructor TScriptError.Create(const ScriptError: IActiveScriptError; ALineNumberMap: TLineNumberMap);
var
  Context, Line: LongWord;
  CharPos: Integer;
  W: WideString;
  E: ExcepInfo;
begin
   if ScriptError.GetExceptionInfo(E) = S_OK then
     FDescription := E.bstrDescription;

   if ScriptError.GetSourcePosition(Context, Line, CharPos) = S_OK then
   begin
     FLine := ALineNumberMap.DestLineToSourceLine(Line, FFileName);
     FCharPos := CharPos;
   end;

   if ScriptError.GetSourceLineText(W) = S_OK then
     FSourceLine := W;
end;

constructor TScriptError.Create(E: Exception);
begin
   inherited Create;
   FDescription := E.Message;
end;

function TScriptError.GetCharPos: Integer;
begin
  Result := FCharPos;
end;

function TScriptError.GetDescription: string;
begin
  Result := FDescription;
end;

function TScriptError.GetFileName: string;
begin
  Result := FFileName;
end;

function TScriptError.GetLine: Integer;
begin
  Result := FLine;
end;

function TScriptError.GetSourceLine: string;
begin
  Result := FSourceLine;
end;

procedure TScriptError.SetDescription(const AValue: string);
begin
  FDescription := AValue;
end;

{ TScriptErrors }

procedure TScriptErrors.Add(const AError: TAbstractScriptError);
begin
  FList.Add(AError);
end;

constructor TScriptErrors.Create;
begin
  inherited Create;
  FList := TObjectList.Create(True { Owned });
end;

destructor TScriptErrors.Destroy;
begin
  FList.Free;
  inherited;
end;

function TScriptErrors.GetError(I: Integer): TAbstractScriptError;
begin
  Result := FList[I] as TAbstractScriptError;
end;

function TScriptErrors.GetErrorCount: Integer;
begin
  Result := FList.Count;
end;

{ TWebPagesWrapper }

constructor TWebPagesWrapper.Create(AContext: IScriptContext);
begin
  FContext := AContext;
  if (AContext.WebModuleContext is TComponent) and
   (csDesigning in TComponent(AContext.WebModuleContext).ComponentState) then
    FSamplePages := TInterfaceList.Create;
  inherited Create(nil);
end;

function TWebPagesWrapper.DispatchOfName(const AName: string): IDispatch;
var
  Intf: IWebPageInfo;
begin
  Intf := FindPageInfo(AName);
  if Intf <> nil then
    Result := TWebPageWrapper.Create(FContext, Intf)
  else
    Result := nil;
end;

function TWebPagesWrapper.FindPageInfo(const AName: string): IWebPageInfo;
var
  I: Integer;
begin
  for I := 0 to WebContext.PageCount - 1 do
  begin
    Result := WebContext.Pages[I];
    if SameText(Result.PageName, AName) then
      Exit;
  end;
  Result := nil;
  if Result = nil then
    Result := FindSamplePage(AName);
end;

function TWebPagesWrapper.FindSamplePage(
  const AName: string): IWebPageInfo;
var
  I: Integer;
begin
  if FSamplePages <> nil then
  begin
    for I := 0 to FSamplePages.Count - 1 do
    begin
      Result := (FSamplePages[I] as IWebPageInfo);
      if SameText(Result.PageName, AName) then
        Exit;
    end;
    Result := TSampleWebPageInfo.Create(AName) as IWebPageInfo;
    FSamplePages.Add(Result);
  end
  else
    Result := nil;
end;

function TWebPagesWrapper.Get_NewEnum: IUnknown;
begin
  Result := TWebPagesEnumerator.Create(FContext) as IEnumVariant;
end;

{ TListEnumerator }

function TListEnumerator.Clone(out ppenum: IEnumVARIANT): HResult;
begin
  Assert(False, 'Clone not implemented');
  Result := E_NOTIMPL;
end;

constructor TListEnumerator.Create;
begin
  FReset := True;
  inherited Create;
end;

function TListEnumerator.EOF: Boolean;
begin
  Result :=
    (FCurrentIndex >= GetListCount);
end;

function TListEnumerator.GetListCount: Integer;
begin
  Assert(False);  // Descendent must implement
  Result := 0;
end;

function TListEnumerator.GetListItem(I: Integer): IDispatch;
begin
  Assert(False); // Descendent must implement
  Result := nil;
end;

function TListEnumerator.Next(celt: LongWord;
  var rgvar: OleVariant; out pceltFetched: LongWord): HResult;
begin
  if FReset then
  begin
    FReset := False;
    FCurrentIndex := 0;
  end
  else
    Inc(FCurrentIndex);
  if not EOF then
  begin
    if celt = 1 then
    begin
      rgVar := GetListItem(FCurrentIndex);
      if @pceltFetched <> nil then
        pceltFetched := celt;
    end
    else
    begin
      Result := E_NOTIMPL;
      Exit;
    end;
  end;
  if not EOF then
    Result := S_OK
  else
    Result := S_FALSE
end;

function TListEnumerator.Reset: HResult;
begin
  FReset := True;
  Result := S_OK;
end;

function TListEnumerator.Skip(celt: LongWord): HResult;
var
  I: LongWord;
begin
  if EOF then
    Result := S_FALSE
  else
  begin
    I := 0;
    while (not EOF) and (I < celt) do
    begin
      Inc(FCurrentIndex);
      Inc(I);
    end;
    if not EOF then
      Result := S_OK
    else
      Result := S_FALSE
  end
end;

{ TWebPagesEnumerator }

constructor TWebPagesEnumerator.Create(AContext: IScriptContext);
begin
  FContext := AContext;
  inherited Create;
end;

function TWebPagesEnumerator.GetListCount: Integer;
begin
  if WebContext <> nil then
    Result := WebContext.PageCount
  else
    Result := 0;
end;

function TWebPagesEnumerator.GetListItem(I: Integer): IDispatch;
begin
  Result := TWebPageWrapper.Create(FContext, WebContext.Pages[I]) as IDispatch;
end;

{ TSampleWebPageInfo }

constructor TSampleWebPageInfo.Create(const APageName: string);
begin
  FPageName := APageName;
  inherited Create;
end;

function TSampleWebPageInfo.GetPageTitle: string;
begin
  Result := FPageName;
end;

function TSampleWebPageInfo.GetPageDescription: string;
begin
  Result := FPageName;
end;

function TSampleWebPageInfo.GetPageHREF: string;
begin
  Result := FPageName;
end;

function TSampleWebPageInfo.GetPageIsPublished: Boolean;
begin
  Result := True;
end;

function TSampleWebPageInfo.GetLoginRequired: Boolean;
begin
  Result := False;
end;

function TSampleWebPageInfo.GetPageName: string;
begin
  Result := FPageName;
end;

function TSampleWebPageInfo.GetHasViewAccess: Boolean;
begin
  Result := True;
end;

{ TWebSessionWrapper }

function TWebSessionWrapper.Get_SessionID: ISessionIDWrapper;
begin
  if FSessionIDWrapper = nil then
    FSessionIDWrapper := TWebSessionIDWrapper.Create;
  Result := FSessionIDWrapper;
end;

function TWebSessionWrapper.Get_Values(const Name: WideString): OleVariant;
begin
  Result := WebContext.Session.Values[Name];
end;

{ TWebSessionIDWrapper }

function TWebSessionIDWrapper.Get_Value: WideString;
begin
  Result := WebContext.Session.SessionID;
end;

{ TAbstractScriptObjectFactory }

procedure TAbstractScriptObjectFactory.AddGlobalObjects(
  AScriptSite: TAbstractScriptSite);
begin
  Assert(False, 'AddNamed not implemented');
end;

constructor TAbstractScriptObjectFactory.Create;
begin
  inherited Create;
  ScriptObjectFactories.FObjectList.Add(Self);
end;

destructor TAbstractScriptObjectFactory.Destroy;
begin
  inherited;
  ScriptObjectFactories.FObjectList.Remove(Self);
end;

{ TScriptObjectFactory }

procedure TScriptObjectFactory.AddGlobalObjects(AScriptSite: TAbstractScriptSite);

var
  Context: IScriptContext;

  procedure Add(AVariable: TGlobalScriptVariables);
  begin
    with AScriptSite do
      AddNamedIntf(GlobalScriptVariableNames[AVariable], CreateGlobalObject(AVariable, FProducer));
  end;

var
  WebVariablesContainer: IWebVariablesContainer;
  I: Integer;
  V: TComponent;
  Intf: IInterface;
begin
  with AScriptSite do
  begin
    Context := FProducer;
    AddNamedIntf(GlobalScriptVariableNames[svResponse], TWebResponseWrapper.Create(FProducer));
    AddNamedIntf(GlobalScriptVariableNames[svProducer], TWebProducerWrapper.Create(FProducer));
    AddNamedIntf(GlobalScriptVariableNames[svHTMLItems], THTMLItemsWrapper.Create(FProducer));
    if Supports(WebModuleContext, IWebVariablesContainer, WebVariablesContainer) then
      for I := 0 to WebVariablesContainer.VariableCount - 1 do
      begin
        V := WebVariablesContainer.Variables[I];
        if Supports(V, IGetScriptObject, Intf) then
          AddNamedComponentIntf(V.Name, V);
      end;
  end;

  Add(svRequest);
  Add(svPage);
  Add(svModules);
  Add(svPages);
  Add(svApplication);
  Add(svEndUser);
  Add(svSession);

end;

function TScriptObjectFactory.CreateGlobalObject(AVariable: TGlobalScriptVariables; AContext: IScriptContext): IDispatch;
begin
  case AVariable of
    svRequest: Result := TWebRequestWrapper.Create(AContext);
    svPage: Result := TWebPageWrapper.Create(AContext, TCurrentWebPageInfo.Create(AContext));
    svModules: Result := TWebModulesWrapper.Create(nil);
    svPages: Result := TWebPagesWrapper.Create(AContext);
    svApplication: Result := TWebApplicationWrapper.Create(AContext);
    svEndUser: Result := TWebEndUserWrapper.Create(AContext);
    svSession: Result := TWebSessionWrapper.Create;
  else
    Result := nil;
    Assert(False); // Unknown object type or type not supported by this method
  end;
end;

{ TScriptCodeItem }

function TScriptCodeItem.GetScript: string;
begin
  Result := FScript;
end;

procedure TScriptCodeItem.AssignString(const AValue: string);
begin
  FScript := AValue;
end;

{ TScriptItem }

constructor TScriptItem.Create(AItems: TScriptItems);
begin
  inherited Create;
  FItems := AItems;
  FItems.Add(self);
end;

function TScriptItem.GetScript: string;
begin
  Assert(False);
end;

{ TScriptIncludeItem }

constructor TScriptIncludeItem.Create(AItems: TScriptItems; AIncludeFile: TScriptIncludeFile);
begin
  inherited Create(AItems);
  FScriptIncludeFile := AIncludeFile;
end;

function TScriptIncludeItem.GetScript: string;
begin
  Result := FScriptIncludeFile.Script;
end;

{ TScriptFile }

constructor TScriptFile.Create(AProducer: TScriptProducer);
begin
  FProducer := AProducer;
  FScriptItems := TScriptItems.Create(AProducer);
  FLineNumberMap := TLineNumberMap.Create;
  inherited Create;
end;

function TScriptFile.GetDestLineCount: Integer;
var
  I: Integer;
  P: PLineNumbers;
begin
  Result := 0;
  if FLineNumberMap.Count > 0 then
    with FLineNumberMap[FLineNumberMap.Count - 1]^ do
    begin
      Result := (DestStartLine - 1) + DestLineCount;
    end;
  for I := 0 to FLineNumberMap.Count - 1 do
  begin
    P := FLineNumberMap[I];
    if P.ScriptIncludeFile <> nil then
      Result := Result + P.ScriptIncludeFile.GetDestLineCount;
  end;
end;

destructor TScriptFile.Destroy;
begin
  inherited;
  FScriptItems.Free;
  if FStreamOwned then
    FSourceStream.Free;
  FLineNumberMap.Free;
end;

function TScriptFile.GetApplicationName: WideString;
var
  C: TComponent;
begin
  C := FProducer.GetComponent;
  if C <> nil then
    Result := C.Name
  else
    Result := '';
end;

function TScriptFile.GetLongName: WideString;
begin
  Result := GetApplicationName;
end;

function TScriptFile.GetScript: WideString;
var
  I: Integer;
begin
  Result := '';
  for I := 0 to FScriptItems.Count - 1 do
    Result := Result + FScriptItems[I].Script;
end;

function TScriptFile.GetShortName: WideString;
begin
  Result := GetApplicationName;
end;

function TScriptFile.GetSource: string;
begin
  Result := '';
  if FSourceStream <> nil then
  begin
    SetLength(Result, FSourceStream.Size);
    FSourceStream.Seek(0, soBeginning);
    FSourceStream.ReadBuffer(Result[1], FSourceStream.Size)
  end;
end;

procedure TScriptFile.ParseStream(ASource: TStream; AOwned: Boolean);
  function NotBlank(P: PChar; L: Integer): Boolean;
  var
    I: Integer;
  begin
    for I := 0 to L - 1 do
      if not (P[I] in [' ', #13, #10]) then
      begin
        Result := True;
        Exit;
      end;
    Result := False;
  end;
type
  TScriptCmd = (cmdEcho, cmdNone);
var
  OutStream: TMemoryStream;
  ScriptSection: string;
  Parser: TCopyParser;
  TagToken: Boolean;
  ScriptLine: Integer;
  ScriptBlockLines: Integer;

  procedure WriteHTML(ASourceStartLine, ASourceEndLine: Integer);
  var
    Item: THTMLItem;
  begin
    if NotBlank(PChar(OutStream.Memory), OutStream.Size) then
    begin
      Item := THTMLItem.Create(FProducer.FHTMLItems);
      Item.AssignString(0, PChar(OutStream.Memory), OutStream.Size);
      Item.TagToken := TagToken;
      ScriptSection := ScriptSection +
        Format('%s.WriteItem(%d)'#13#10, [GlobalScriptVariableNames[svHTMLItems], Item.FIndex]);  // Do not localize
      OutStream.Size := 0;
      with FLineNumberMap.New^ do
      begin
        SourceStartLine := ASourceStartLine;
        SourceLineCount := ASourceEndLine;
        DestStartLine := ScriptLine;
        DestLineCount := 1;
      end;
      Inc(ScriptLine, 1);
    end
    else
      with FLineNumberMap.New^ do
      begin
        SourceStartLine := ASourceStartLine;
        SourceLineCount := ASourceEndLine;
        DestStartLine := ScriptLine;
        DestLineCount := 0;
      end;
    TagToken := False;
  end;

  procedure WriteScript;
  var
    Item: TScriptCodeItem;
  begin
    if (Trim(ScriptSection) <> '') then
    begin
      Item := TScriptCodeItem.Create(FScriptItems);
      try
        Item.AssignString(ScriptSection);
      except
        Item.Free;
        raise;
      end;
      ScriptSection := '';
    end;
  end;

  function IncludeTypeOfString(const AToken: string): TIncludeType;
  begin
    if SameText(AToken, 'file') then
      Result := incFile
    else if SameText(AToken, 'page') then
      Result := incPage
    else
    begin
      Assert(False);
      Result := incFile;
    end;
  end;

  procedure WriteIncludeFile(const AIncludeType, AFileName: string; ASourceStartLine, ASourceLineCount: Integer);
  var
    IncludeFile: TScriptIncludeFile;
  begin
    IncludeFile := TScriptIncludeFile.Create(FProducer, IncludeTypeOfString(AIncludeType), AFileName);
    TScriptIncludeItem.Create(FScriptItems, IncludeFile);
    IncludeFile.LoadFile;
    with FLineNumberMap.New^ do
    begin
      SourceStartLine := ASourceStartLine;
      SourceLineCount := ASourceLineCount;
      DestStartLine := ScriptLine;
      ScriptIncludeFile := IncludeFile;
    end;
  end;

  function ExtractIncludeFile(var AType, AFileName: string): Boolean;
  begin
    Result := False;
    with Parser do
    begin
      if (NextToken = '-') and
         (NextToken = '-') and
         (NextToken = '#') and
         (NextToken = toSymbol) and TokenSymbolIs('include') then
      begin
        // Have include file
        if (NextToken = toSymbol) and (TokenSymbolIs('file') or
           TokenSymbolIs('virtual') or
           TokenSymbolIs('page')) then
        begin
          AType := TokenString;
          if NextToken = '=' then
          begin
            if NextToken = '"' then
            begin
              AFileName := '';
              NextToken;
              while not (Token in [toEof, '"', '>']) do
              begin
                if Token = toSymbol then
                  AFileName := AFileName + TokenString
                else
                  AFileName := AFileName + Token;
                NextToken;
              end;
              if Token <> '"' then
                raise EScriptError.CreateFmt(sIncDblQuoteError,
                  [Parser.SourceLine]);
              if Token <> '>' then
              begin
                CopyToToken('>');
                Result := True;
              end;
            end
            else
              raise EScriptError.CreateFmt(sIncDblQuoteError, [Parser.SourceLine]);
          end
          else
            raise EScriptError.CreateFmt(sIncEqualsError, [Parser.SourceLine]);
        end
        else if (Token = toSymbol) then
          raise EScriptError.CreateFmt(sIncTypeError,
            [Parser.SourceLine, TokenString]);
      end
    end;
  end;

  procedure TrimScriptBlock(ACmd: TScriptCmd; AScriptEnd: Integer; var AScriptBlock: string);
  var
    C: Char;
    I: Integer;
  begin
    for I := 1 to Length(AScriptBlock) do
    begin
      C := AScriptBlock[I];
      if not (C in [#13, #10]) then
        AScriptBlock[I] := ' ';
      if ACmd = cmdEcho then
      begin
        if C = '=' then break;
      end
      else  if C = '%' then break;
    end;
    if AScriptEnd > 0 then
      for I := Length(AScriptBlock) - (OutStream.Position - AScriptEnd) to Length(AScriptBlock) do
        if not (AScriptBlock[I] in [#13, #10]) then
          AScriptBlock[I] := ' ';
    if ACmd <> cmdEcho then
      AScriptBlock := AScriptBlock + #13#10;
  end;

var
  ScriptBlock: string;
  Cmd: TScriptCmd;
  IncludeFileName: string;
  IncludeType: string;
  SavePos: Integer;
  SaveSize: Int64;
  ScriptEnd: Integer;
  SaveScriptSourceLine: Integer;
  SaveHTMLSourceLine: Integer;
begin
  Assert(FSourceStream = nil);  // Only expect to process one stream
  FStreamOwned := AOwned;
  FSourceStream := ASource;

  ScriptSection := '';
  ScriptLine := 1;
  SaveHTMLSourceLine := 1;
  OutStream := TMemoryStream.Create;
  try
    Parser := TCopyParser.Create(ASource, OutStream);
    with Parser do
    try
      CopyTokenToOutput;
      while True do
      begin
        while not (Token in [toEof, '<']) do
          NextToken;
        if Token = toEOF then Break;
        if Token = '<' then
        begin
          SavePos := OutStream.Position;
          SaveSize := OutStream.Size;
          SaveScriptSourceLine := Parser.SourceLine;
          if NextToken = '%' then
          begin
            try
              ScriptEnd := -1;
              if NextToken = '=' then
                Cmd := cmdEcho
              else
                Cmd := cmdNone;
              while True do
              begin
                if (NextToken = '%') then
                begin
                  ScriptEnd := OutStream.Position;
                  if (NextToken = '>') then
                    break;
                end;
                if Token = toEOF then
                begin
                  Assert(False, 'Expected %>');
                  break;
                end;
              end;
              ScriptBlock := Copy(PChar(OutStream.Memory), SavePos, OutStream.Position - SavePos + 1);
              ScriptBlockLines := Parser.SourceLine - SaveScriptSourceLine + 1;
              TrimScriptBlock(Cmd, ScriptEnd, ScriptBlock);
              case Cmd of
                cmdEcho:
                  begin
                    ScriptBlock := Format('Response.Write(%s)'#13#10, [ScriptBlock]);
                  end;
                cmdNone: ;
              end;
              OutStream.Position := SavePos-1;
              OutStream.Size := SaveSize-1;
              WriteHTML(SaveHTMLSourceLine, SaveScriptSourceLine - SaveHTMLSourceLine);
              SaveHTMLSourceLine := Parser.SourceLine + 1;
              ScriptLine := ScriptLine + ScriptBlockLines;
              ScriptSection := ScriptSection + ScriptBlock;
            except
              on E: Exception do
                FProducer.HandleParserError(E);
            end;
            if Token = toEof then break;
            NextToken;
          end
          else if Token = '!' then
          begin
            try
              if ExtractIncludeFile(IncludeType, IncludeFileName) then
              begin
                OutStream.Position := SavePos-1;
                OutStream.Size := SaveSize-1;
                WriteHTML(SaveHTMLSourceLine, SaveScriptSourceLine - SaveHTMLSourceLine + 1);
                SaveHTMLSourceLine := Parser.SourceLine + 1;
                WriteScript;
                WriteIncludeFile(IncludeType, IncludeFileName, SaveScriptSourceLine,
                  Parser.SourceLine - SaveScriptSourceLine + 1);
              end
            except
              on E: Exception do
                FProducer.HandleParserError(E);
            end;
            if Token = toEof then break;
            NextToken;
          end
          else if Token = '#' then
            TagToken := True;
        end
      end;
      WriteHTML(SaveHTMLSourceLine, Parser.SourceLine - SaveHTMLSourceLine + 1);
      WriteScript;
    finally
      Parser.Free;
    end;
  finally
    OutStream.Free;
  end;
end;

procedure TScriptFile.ParseString(const ASource: string);
var
  InStream: TStream;
begin
  InStream := TStringStream.Create(ASource);
  ParseStream(InStream, True);
end;

{ TScriptItems }

constructor TScriptItems.Create(AProducer: TScriptProducer);
begin
  FProducer := AProducer;
  inherited Create;
end;

function TScriptItems.GetScriptItem(I: Integer): TScriptItem;
begin
  Result := inherited Items[I] as TScriptItem;
end;

{ TScriptIncludeFile }

constructor TScriptIncludeFile.Create(AProducer: TScriptProducer; AIncludeType: TIncludeType; const AFileName: string);
begin
  inherited Create(AProducer);
  FFileName := AFileName;
  FIncludeType := AIncludeType;
  FLineNumberMap.FFileName := FFileName;
  AProducer.FIncludeFiles.Add(Self);
end;

procedure TScriptIncludeFile.LoadFile;
begin
  case FIncludeType of
    incFile: LoadIncludeFile;
    incPage: LoadIncludePage;
  else
    Assert(False);
  end;
end;

procedure TScriptIncludeFile.LoadIncludeFile;
var
  S: TStream;
  Temp: string;
  Owned: Boolean;
  FindIncludeFile: IFindIncludeFile;
  FileFound: Boolean;
begin
  if not FLoaded then
  begin
    if FLoading then
      raise ERecursiveIncludeFile.CreateFmt(sRecursiveIncludeFile, [FFileName]);
    FLoading := True;
    S := nil;
    try
      try
        FileFound := False;
        if FProducer.FLocateFileService <> nil then
        begin
          S := FProducer.FLocateFileService.GetTemplateStream(FProducer.Component, FFileName, Owned);
          if S = nil then
          begin
            if Supports(FProducer.FLocateFileService, IFindIncludeFile, FindIncludeFile) then
            begin
              if FindIncludeFile.FindIncludeFile(FProducer.Component, FFileName, Temp) then
              begin
                FileFound := True;
                FFileName := Temp;
              end;
            end;
          end;
        end;
        if (S = nil) and (not FileFound) then
          if IDEFileManager <> nil then
          begin
            Temp := IDEFileManager.SearchFile(FFileName);
            if Temp <> '' then
              FFileName := Temp;
          end;
        if S = nil then
          if DesignerFileManager <> nil then
            S := DesignerFileManager.GetStream(FFileName, Owned);
        if S = nil then
        begin
          FFileName := QualifyFileName(FFileName);
          S := TFileStream.Create(FFileName, fmOpenRead or fmShareDenyNone);
          Owned := True;
        end;
      except
        if Owned then
          S.Free;
        raise;
      end;
      ParseStream(S, Owned);
    finally
      FLoaded := True;
      FLoading := False;
    end;
  end;
end;

procedure TScriptIncludeFile.LoadIncludePage;
var
  S: TStream;
  Owned: Boolean;
  PageComponent: TObject;
  IncludePage: IPageResult;
begin
  if not FLoaded then
  begin
    if not WebContext.FindPage(FFileName, [], PageComponent) then
      RaiseIncludePageNotFound(FFileName);
    if not Supports(PageComponent, IPageResult, IncludePage) then
      RaisePageDoesNotSupportInclusion(FFileName);
    S := IncludePage.IncludePage(FFileName, Owned);
    try
      ParseStream(S, Owned);
    finally
      FLoaded := True;
    end;
  end;
end;

{ TScriptIncludeFiles }

constructor TScriptIncludeFiles.Create(AProducer: TScriptProducer);
begin
  FProducer := AProducer;
  inherited Create;
end;

function TScriptIncludeFiles.GetScriptIncludeFile(
  I: Integer): TScriptIncludeFile;
begin
  Result := inherited Items[I] as TScriptIncludeFile;
end;

{ TWebModulesWrapper }

function TWebModulesWrapper.FindObject(const AName: string): TObject;
var
  Lookup: TVariableLookup;
begin
  Lookup := TVariableLookup.Create(AName, nil { app global context });
  try
    Result := Lookup.FindGlobalVariableContainer(AName);
    Assert(Assigned(Result), 'Component not found: ' + AName);
  finally
    Lookup.Free;
  end;
end;

function TWebModulesWrapper.Get_NewEnum: IUnknown;
begin
  Result := TWebModulesEnumerator.Create as IEnumVariant;
end;

{ TWebModulesEnumerator }

function TWebModulesEnumerator.GetListCount: Integer;
begin
  Result := WebContext.WebModules.ItemCount;
end;

function TWebModulesEnumerator.GetListItem(I: Integer): IDispatch;
var
  Module: TComponent;
  GetIntf: IGetScriptObject;
begin
  Module := WebContext.WebModules.Items[I];
  if Supports(IUnknown(Module), IGetScriptObject, GetIntf) then
    Result := GetIntf.GetScriptObject
  else
  begin
    Assert(False);
    Result := nil;
  end;
end;

{ TWebRequestWrapper }

function TWebRequestWrapper.Request: TWebRequest;
begin
  if WebContext <> nil then
    Result := WebContext.Request
  else
    Result := nil;
end;

function TWebRequestWrapper.Get_PathInfo: WideString;
begin
  if Request <> nil then
    Result := Request.InternalPathInfo
  else
    Result := '';
end;

function TWebRequestWrapper.Get_ScriptName: WideString;
begin
  if Request <> nil then
    Result := Request.InternalScriptName
  else
    Result := '';
end;

function TWebRequestWrapper.Get_Host: WideString;
begin
  if Request <> nil then
    Result := Request.Host
  else
    Result := '';
end;

{ TScriptObjectFactories }

constructor TScriptObjectFactories.Create;
begin
  inherited Create;
  FObjectList := TObjectList.Create(True { owned });
end;

function TScriptObjectFactories.CreateGlobalObject(AVariable: TGlobalScriptVariables; 
  AContext: IScriptContext): IDispatch;
var
  I: Integer;
begin
  Result := nil;
  for I := Count - 1 downto 0 do
  begin
    Result := Factories[I].CreateGlobalObject(AVariable, AContext);

    if Result <> nil then
      exit;
  end;
end;

destructor TScriptObjectFactories.Destroy;
begin
  inherited;
  FObjectList.Free;
end;

function TScriptObjectFactories.GetCount: Integer;
begin
  Result := FObjectList.Count;
end;

function TScriptObjectFactories.GetFactory(
  I: Integer): TAbstractScriptObjectFactory;
begin
  Result := TAbstractScriptObjectFactory(FObjectList[I]);
end;

constructor TWebRequestWrapper.Create(AContext: IScriptContext);
begin
  inherited Create;
  // AContext not used
end;

// Copy from system
function WCharFromChar(WCharDest: PWideChar; DestChars: Integer; const CharSource: PChar; SrcBytes: Integer): Integer;
begin
{$IFDEF LINUX}
  Result := BufConvert(WCharDest, DestChars * sizeof(WideChar), CharSource, SrcBytes,
     iconv_open('UNICODELITTLE', nl_langinfo(_NL_CTYPE_CODESET_NAME))) div sizeof(WideChar);
{$ENDIF}
{$IFDEF MSWINDOWS}
  Result := MultiByteToWideChar(0, 0, CharSource, SrcBytes,
      WCharDest, DestChars);
{$ENDIF}
end;

procedure THTMLItems.Prepare;
var
  L: Integer;
begin
  L := FStream.Size;
  GetMem(FBuffer, L);
  try
    FStream.Seek(soFromBeginning, 0);
    FStream.Read(FBuffer[0], FStream.Size)
  except
    FreeMem(FBuffer);
    FBuffer := nil;
    raise;
  end;
end;

procedure THTMLItemsWrapper.WriteItem(Index: Integer);
begin
  FProducer.WriteItem(Index);
end;

procedure TScriptProducer.WriteItem(Index: Integer);
var
  Item: THTMLItem;
begin
  Item := GetHTMLItem(Index);
  if Item.TagToken then
    Write(ReplaceTags(Item.GetHTMLString))
  else
    WritePChar(Item.GetPHTMLChar, Item.Length);
end;

{ TLineNumberMap }

function TLineNumberMap.GetCount: Integer;
begin
  Result := Length(FArray);
end;

function TLineNumberMap.GetLineNumbers(I: Integer): PLineNumbers;
begin
  Result := @FArray[I];
end;

function TLineNumberMap.New: PLineNumbers;
begin
  SetLength(FArray, Length(FArray)+1);
  Result := Items[Count-1];
end;

function TLineNumberMap.DestLineToSourceLine(ALine: Integer; var AFileName: string): Integer;
var
  I: Integer;
  Item: PLineNumbers;
begin
  AFileName := QualifyFileName(FFileName);
  ALine := ALine + 1; // Make one based
  for I := 0 to Count - 1 do
  begin
    Item := Items[I];
    if (ALine >= Item.DestStartLine) and
      (Item.ScriptIncludeFile <> nil) and
      (ALine <= Item.DestStartLine + Item.ScriptIncludeFile.GetDestLineCount -1) then
    begin
      ALine := ALine - 1; // Make zero based
      Result := Item.SourceStartLine +
        Item.ScriptIncludeFile.FLineNumberMap.DestLineToSourceLine(ALine -
          Item.DestStartLine + 1, AFileName) - 1;
      Exit;
    end
    else if (ALine >= Item.DestStartLine) and
      (ALine <= Item.DestStartLine + Item.DestLineCount - 1) then
    begin
      Result := Item.SourceStartLine + ALine - Item.DestStartLine;
      Exit;
    end
    else if (ALine >= Item.DestStartLine + Item.DestLineCount) then
      if (I = Count-1) or (ALine < Items[I+1].DestStartLine) then
      begin
        Result := Item.SourceStartLine + Item.SourceLineCount +
          ALine - (Item.DestStartLine + Item.DestLineCount);
        Exit;
      end;
    if Item.ScriptIncludeFile <> nil then
      ALine := ALine - Item.ScriptIncludeFile.GetDestLineCount;
  end;
  Result := ALine;
end;

initialization
  if ScriptSiteClass = nil then
    ScriptSiteClass := TScriptSite;
  ScriptObjectFactories := TScriptObjectFactories.Create();
  if HTTPProd.ScriptProducerClass = nil then
    HTTPProd.ScriptProducerClass := TScriptProducer;
  ScriptComServer.RegisterScriptClass(TWebResponseWrapper, Class_ResponseWrapper);
  ScriptComServer.RegisterScriptClass(TWebRequestWrapper, Class_RequestWrapper);
  ScriptComServer.RegisterScriptClass(TWebProducerWrapper, Class_ProducerWrapper);
  ScriptComServer.RegisterScriptClass(THTMLItemsWrapper, Class_HTMLItemsWrapper);
  ScriptComServer.RegisterScriptClass(TWebPageWrapper, Class_PageWrapper);
  ScriptComServer.RegisterScriptClass(TWebModulesWrapper, Class_ModulesWrapper);
  ScriptComServer.RegisterScriptClass(TWebPagesWrapper, Class_PagesWrapper);
  ScriptComServer.RegisterScriptClass(TWebApplicationWrapper, Class_ApplicationWrapper);
  ScriptComServer.RegisterScriptClass(TWebEndUserWrapper, Class_EndUserWrapper);
  ScriptComServer.RegisterScriptClass(TWebPagesEnumerator, Class_EnumVariantWrapper);
  ScriptComServer.RegisterScriptClass(TWebModulesEnumerator, Class_EnumVariantWrapper);
  ScriptComServer.RegisterScriptClass(TWebSessionWrapper, Class_SessionWrapper);
  ScriptComServer.RegisterScriptClass(TWebSessionIDWrapper, Class_SessionIDWrapper);
  // Register script objects
  TScriptObjectFactory.Create;
finalization
  ScriptObjectFactories.Free;
end.
