{ *************************************************************************** }
{                                                                             }
{ Delphi and Kylix Cross-Platform Visual Component Library                    }
{ Internet Application Runtime                                                }
{                                                                             }
{ Copyright (C) 1997, 2001 Borland Software Corporation                       }
{                                                                             }
{ Licensees holding a valid Borland No-Nonsense License for this Software may }
{ use this file in accordance with such license, which appears in the file    }
{ license.txt that came with this Software.                                   }
{                                                                             }
{ *************************************************************************** }


unit HTTPProd;     

interface

uses SysUtils, Classes, HTTPApp, Masks, Contnrs;

type

{ THTMLTagAttributes }

  THTMLAlign = (haDefault, haLeft, haRight, haCenter);
  THTMLVAlign = (haVDefault, haTop, haMiddle, haBottom, haBaseline);
  THTMLBgColor = type string;

  ILocateFileService = interface
  ['{BD2B640D-8D7F-11D4-A4E2-00C04F6BB853}']
    function GetTemplateStream(AComponent: TComponent; AFileName: string; out AOwned: Boolean): TStream;
  end;

  IWebVariableName = interface
  ['{EDB15B48-F396-11D3-A42A-00C04F6BB853}']
    function GetVariableName: string;
    property VariableName: string read GetVariableName;
  end;

  IWebVariablesContainer = interface
  ['{132142B1-0320-11D4-ABE8-E035EEC2EA5A}']
    function FindVariable(const AName: string): TComponent;
    function FindVariableContainer(const AName: string): TComponent;
    function GetVariableCount: Integer;
    function GetVariable(I: Integer): TComponent;
    property VariableCount: Integer read GetVariableCount;
    property Variables[I: Integer]: TComponent read GetVariable;
  end;

  IGetLocateFileService = interface
  ['{C9FD165B-8F1C-11D4-A4E4-00C04F6BB853}']
    function GetLocateFileService: ILocateFileService;
  end;

  IDesignerFileManager = interface
  ['{1DF271BF-F2EC-11D4-A559-00C04F6BB853}']
    function QualifyFileName(const AFileName: string): string;
    function GetStream(const AFileName: string; var AOwned: Boolean): TStream;
  end;

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

  TTag = (tgCustom, tgLink, tgImage, tgTable, tgImageMap, tgObject, tgEmbed);

  THTMLTagEvent = procedure (Sender: TObject; Tag: TTag; const TagString: string;
    TagParams: TStrings; var ReplaceText: string) of object;

  IGetProducerTemplate = interface
  ['{44AA3FC1-FEB9-11D4-A566-00C04F6BB853}']
    function GetProducerTemplateStream(out AOwned: Boolean): TStream;
    function GetProducerTemplateFileName: string;
  end;

{ TBasePageProducer }

  TBasePageProducer = class(TCustomContentProducer, IGetProducerTemplate)
  private
    FOnHTMLTag: THTMLTagEvent;
    FStripParamQuotes: Boolean;
    FWebModuleContext: TWebModuleContext;
    FLocalWebModuleContext: TWebModuleContext;
{$IFDEF MSWINDOWS}
    FScriptEngine: string;
{$ENDIF}
    function GetWebModuleContext: TWebModuleContext;
    function GetLocateFileService: ILocateFileService;
  protected
{$IFDEF MSWINDOWS}
    function GetScriptEngine: string; virtual;
    function UseScriptEngine: Boolean; virtual;
{$ENDIF}
    function GetTagID(const TagString: string): TTag;
    function HandleTag(const TagString: string;
      TagParams: TStrings): string; virtual;
    function ImplHandleTag(const TagString: string;
      TagParams: TStrings): string;
    procedure DoTagEvent(Tag: TTag; const TagString: string; TagParams: TStrings;
      var ReplaceText: string); dynamic;
    function HandleScriptTag(const TagString: string;
      TagParams: TStrings; var ReplaceString: string): Boolean; virtual;
    function ServerScriptFromStream(Stream: TStream): string;

    function GetProducerTemplateStream(out AOwned: Boolean): TStream;
    function GetProducerTemplateFileName: string;
    function GetTemplateFileName: string; virtual;
    function GetTemplateStream(out AOwned: Boolean): TStream; virtual;
    property OnHTMLTag: THTMLTagEvent read FOnHTMLTag write FOnHTMLTag;
  public
    constructor Create(AOwner: TComponent); override;
    function Content: string; override;
    function ContentFromStream(Stream: TStream): string; override;
    function ContentFromString(const S: string): string; override;
    property WebModuleContext: TWebModuleContext read GetWebModuleContext;
    property StripParamQuotes: Boolean read FStripParamQuotes write FStripParamQuotes default True;
{$IFDEF MSWINDOWS}
    property ScriptEngine: string read GetScriptEngine write FScriptEngine;
{$ENDIF}
  end;

  { TCustomPageProducer }

  TCustomPageProducer = class(TBasePageProducer)
  private
    FHTMLFile: TFileName;
    FHTMLDoc: TStrings;
    procedure SetHTMLFile(const Value: TFileName);
    procedure SetHTMLDoc(Value: TStrings);
  protected
    function GetTemplateStream(out AOwned: Boolean): TStream; override;
    function HandleTag(const TagString: string;
      TagParams: TStrings): string; override;
    function GetTemplateFileName: string; override;
  public
    constructor Create(AOwner: TComponent); override;
    destructor Destroy; override;
    property HTMLDoc: TStrings read FHTMLDoc write SetHTMLDoc;
    property HTMLFile: TFileName read FHTMLFile write SetHTMLFile;
  end;

{ TPageProducer }

  TPageProducer = class(TCustomPageProducer)
  published
    property HTMLDoc;
    property HTMLFile;
    property StripParamQuotes;
    property OnHTMLTag;
{$IFDEF MSWINDOWS}
    property ScriptEngine;
{$ENDIF}
  end;

  THandleTagProc = function(const TagString: string; TagParams: TStrings): string of object;
  THandledTagProc = function(const TagString: string; TagParams: TStrings; var ReplaceString: string): Boolean of object;

  TAbstractScriptProducer = class;
  TScriptProducerClass = class of TAbstractScriptProducer;

  TAbstractScriptErrors = class;

  EScriptError = class(EWebBrokerException)
  private
    FErrors: TAbstractScriptErrors;
    FContent: string;
  public
    constructor Create(const AErrors: TAbstractScriptErrors; const AContent: string);
    destructor Destroy; override;
    property Errors: TAbstractScriptErrors read FErrors;
    property Content: string read FContent;
  end;

  TAbstractScriptError = class(TObject)
  protected
    function GetSourceLine: string; virtual; abstract;
    function GetCharPos: Integer;  virtual; abstract;
    function GetLine: Integer; virtual; abstract;
    function GetDescription: string;  virtual; abstract;
    procedure SetDescription(const AValue: string);  virtual; abstract;
    function GetFileName: string; virtual; abstract;
  public
    property Line: Integer read GetLine;
    property CharPos: Integer read GetCharPos;
    property Description: string read GetDescription write SetDescription;
    property SourceLine: string read GetSourceLine;
    property FileName: string read GetFileName;
  end;

  TAbstractScriptErrors = class(TObject)
  protected
    function GetError(I: Integer): TAbstractScriptError; virtual; abstract;
    function GetErrorCount: Integer; virtual; abstract;
  public
    procedure Add(const AError: TAbstractScriptError); virtual; abstract;
    property Errors[I: Integer]: TAbstractScriptError read GetError; default;
    property Count: Integer read GetErrorCount;
  end;

  IScriptContext = interface
  ['{5ECF283F-1C83-47FF-8914-33AB0EFD94FB}']
    function GetWebModuleContext: TWebModuleContext;
    property WebModuleContext: TWebModuleContext read GetWebModuleContext;
  end;

  IScriptProducer = interface(IScriptContext)
  ['{53324483-A14A-497B-81DF-CA51668F36B9}']
    function GetErrors: TAbstractScriptErrors;
    function GetHTMLBlock(I: Integer): WideString;
    function GetHTMLBlockCount: Integer;
    procedure ParseStream(Stream: TStream; Owned: Boolean = False);
    procedure ParseString(const S: string);
    function ReplaceTags(const S: string): string;
    function Evaluate: string;
    function HandleScriptError(const ScriptError: IUnknown): HRESULT;
    procedure Write(const Value: PWideChar; ALength: Integer); overload;
    procedure Write(const Value: string); overload;
    procedure WriteItem(Index: Integer);
    function  GetContent: string;
    procedure SetContent(const Value: string);
    property HTMLBlocks[I: Integer]: WideString read GetHTMLBlock;
    property HTMLBlockCount: Integer read GetHTMLBlockCount;
    property Content: string read GetContent write SetContent;
    property Errors: TAbstractScriptErrors read GetErrors;
  end;

  TAbstractScriptProducer = class(TInterfacedObject)
  public
   constructor Create(AWebModuleContext: TWebModuleContext;
        AStripParamQuotes: Boolean; AHandleTag: THandleTagProc;
        const AScriptEngine: string; ALocateFileService: ILocateFileService); virtual;
  end;

  function ContentFromScriptStream(AStream: TStream;
    AWebModuleContext: TWebModuleContext;  AStripParamQuotes: Boolean;
    AHandleTag: THandleTagProc; AHandleScriptTag: THandledTagProc;
    const AScriptEngine: string; ALocateFileService: ILocateFileService): string;
  function ContentFromScriptFile(const AFileName: TFileName;
    AWebModuleContext: TWebModuleContext;  AStripParamQuotes: Boolean;
    AHandleTag: THandleTagProc; AHandleScriptTag: THandledTagProc;
    const AScriptEngine: string; ALocateFileService: ILocateFileService): string;
  function FindComponentWebModuleContext(AComponent: TComponent): TWebModuleContext;
  function GetTagID(const TagString: string): TTag;
  function ContentFromStream(AStream: TStream;
    AStripParamQuotes: Boolean; AHandleTag: THandleTagProc; AHandledTag: THandledTagProc): string;
  function ContentFromString(const AValue: string;
    AStripParamQuotes: Boolean; AHandleTag: THandleTagProc; AHandledTag: THandledTagProc): string;


const
  HTMLAlign: array[THTMLAlign] of string =
    ('',
     ' Align="left"',
     ' Align="right"',
     ' Align="center"');
  HTMLVAlign: array[THTMLVAlign] of string =
    ('',
     ' VAlign="top"',
     ' VAlign="middle"',
     ' VAlign="bottom"',
     ' VAlign="baseline"');
var
  ScriptProducerClass: TScriptProducerClass = nil;
  DesignerFileManager: IDesignerFileManager = nil;

implementation

uses CopyPrsr, WebConst;

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

{ TBasePageProducer }

constructor TBasePageProducer.Create(AOwner: TComponent);
begin
  inherited Create(AOwner);
  FStripParamQuotes := True;
{$IFDEF MSWINDOWS}
  RPR;
{$ENDIF}
{$IFDEF LINUX}
  RCS;
{$ENDIF}
end;

function TBasePageProducer.ContentFromStream(Stream: TStream): string;
begin
{$IFDEF MSWINDOWS}
  if Assigned(ScriptProducerClass) and UseScriptEngine then
    Result := HttpProd.ContentFromScriptStream(Stream, WebModuleContext, StripParamQuotes, HandleTag,
      HandleScriptTag, ScriptEngine, GetLocateFileService)
  else
{$ENDIF}
    Result := HttpProd.ContentFromStream(Stream,
       StripParamQuotes, HandleTag, nil);
end;

function TBasePageProducer.ServerScriptFromStream(Stream: TStream): string;
begin
  Result := HttpProd.ContentFromStream(Stream,
       StripParamQuotes, nil, HandleScriptTag);
end;

function TBasePageProducer.ContentFromString(const S: string): string;
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

function TBasePageProducer.HandleTag(const TagString: string; TagParams: TStrings): string;
begin
  Result := Format('<#%s>', [TagString]);
end;

function TBasePageProducer.HandleScriptTag(const TagString: string; TagParams: TStrings;
  var ReplaceString: string): Boolean;
begin
  Result := False;
end;

type
  TLocalWebModuleContext = class(TObject, IWebVariablesContainer)
  private
    FModule: TComponent;
    function FindNamedVariable(const AName: string): TComponent;
  protected
    { IUnknown }
    function QueryInterface(const IID: TGUID; out Obj): HResult; virtual; stdcall;
    function _AddRef: Integer; stdcall;
    function _Release: Integer; stdcall;
    { IWebVariablesContainer }
    function FindVariable(const AName: string): TComponent;
    function FindVariableContainer(const AName: string): TComponent;
    function GetVariableCount: Integer;
    function GetVariable(I: Integer): TComponent;
  public
    constructor Create(AModule: TComponent);
  end;

constructor TLocalWebModuleContext.Create(AModule: TComponent);
begin
  inherited Create;
  FModule := AModule;
  Assert(Assigned(FModule));
end;

function TLocalWebModuleContext._AddRef: Integer;
begin
  Result := -1;
end;

function TLocalWebModuleContext._Release: Integer;
begin
  Result := -1;
end;

function TLocalWebModuleContext.QueryInterface(const IID: TGUID;
  out Obj): HResult;
begin
  if GetInterface(IID, Obj) then Result := 0
  else Result := HRESULT($80004002); // E_NOINTERFACE
end;

function FindNamedModuleVariable(AModule: TComponent;
  const AName: string): TComponent;
var
  I: Integer;
  WebVariableName: IWebVariableName;
begin
  for I := 0 to AModule.ComponentCount - 1 do
  begin
    Result := AModule.Components[I];
    Supports(IInterface(Result), IWebVariableName, WebVariableName);
    if Assigned(WebVariableName) then
      if CompareText(WebVariableName.VariableName, AName) = 0 then
        Exit;
  end;
  Result := nil;
end;

function TLocalWebModuleContext.FindNamedVariable(
  const AName: string): TComponent;
begin
  Result := FindNamedModuleVariable(FModule, AName)
end;

function TLocalWebModuleContext.FindVariable(
  const AName: string): TComponent;
begin
  Result := FindNamedVariable(AName);
end;

function TLocalWebModuleContext.FindVariableContainer(
  const AName: string): TComponent;
var
  Intf: IUnknown;
begin
  Result := FindNamedVariable(AName);
  if Assigned(Result) and
    not Supports(IInterface(Result), IWebVariablesContainer, Intf) then
    raise EWebBrokerException.CreateFmt(sVariableIsNotAContainer, [AName]);
end;

function GetModuleVariable(AModule: TComponent; Index: Integer): TComponent;
var
  I, J: Integer;
  WebVariableName: IWebVariableName;
begin
  J := 0;
  for I := 0 to AModule.ComponentCount - 1 do
  begin
    Result := AModule.Components[I];
    Supports(IInterface(Result), IWebVariableName, WebVariableName);
    if Assigned(WebVariableName) then
      if Index = J then
        Exit
      else
        Inc(J);
  end;
  Result := nil;
end;

function TLocalWebModuleContext.GetVariable(
  I: Integer): TComponent;
begin
  Result := GetModuleVariable(FModule, I);
end;

function GetModuleVariableCount(AModule: TComponent): Integer;
var
  I: Integer;
  WebVariableName: IWebVariableName;
begin
  Result := 0;
  for I := 0 to AModule.ComponentCount - 1 do
    if Supports(IInterface(AModule.Components[I]), IWebVariableName, WebVariableName) then
      Inc(Result);
end;

function TLocalWebModuleContext.GetVariableCount: Integer;
begin
  Result := GetModuleVariableCount(FModule);
end;

function TBasePageProducer.GetWebModuleContext: TWebModuleContext;
begin
  if not Assigned(FWebModuleContext) then
  begin
    FWebModuleContext := FindComponentWebModuleContext(Self);
    if FWebModuleContext = nil then
    begin
      Assert(FLocalWebModuleContext = nil, 'Internal Error');
      if Assigned(Owner) then
        FLocalWebModuleContext := TLocalWebModuleContext.Create(Owner);
      FWebModuleContext := FLocalWebModuleContext;
    end;
  end;
  Result := FWebModuleContext;
end;


function TBasePageProducer.GetTagID(const TagString: string): TTag;
begin
  Result := HTTPProd.GetTagID(TagString);
end;

var
  TagSymbols: array[TTag] of string =
    ('', 'LINK', 'IMAGE', 'TABLE', 'IMAGEMAP', 'OBJECT', 'EMBED');
function GetTagID(const TagString: string): TTag;
begin
  Result := High(TTag);
  while Result >= Low(TTag) do
  begin
    if (Result = tgCustom) or (CompareText(TagSymbols[Result], TagString) = 0) then Break;
    Dec(Result);
  end;
end;

function TBasePageProducer.Content: string;
var
  InStream: TStream;
  Owned: Boolean;
begin
  Result := '';
  InStream := GetTemplateStream(Owned);
  try
    if InStream <> nil then
      Result := ContentFromStream(InStream);
  finally
    if Owned then
      InStream.Free;
  end;
end;

procedure TBasePageProducer.DoTagEvent(Tag: TTag; const TagString: string;
  TagParams: TStrings; var ReplaceText: string);
begin
  if Assigned(FOnHTMLTag) then
    FOnHTMLTag(Self, Tag, TagString, TagParams, ReplaceText);
end;

function TBasePageProducer.ImplHandleTag(const TagString: string;
  TagParams: TStrings): string;
var
  Tag: TTag;
begin
  Tag := GetTagID(TagString);
  Result := '';
  DoTagEvent(Tag, TagString, TagParams, Result);
end;

{$IFDEF MSWINDOWS}
function TBasePageProducer.GetScriptEngine: string;
begin
  Result := FScriptEngine;
end;

function TBasePageProducer.UseScriptEngine: Boolean;
begin
  Result := ScriptEngine <> '';
end;
{$ENDIF}

function TBasePageProducer.GetLocateFileService: ILocateFileService;
var
  GetIntf: IGetLocateFileService;
begin
  Result := nil;
  if DispatcherComponent <> nil then
    if Supports(IUnknown(DispatcherComponent), IGetLocateFileService, GetIntf) then
      Result := GetIntf.GetLocateFileService;
end;

function TBasePageProducer.GetTemplateStream(out AOwned: Boolean): TStream;
begin
  Result := nil;
end;

function TBasePageProducer.GetProducerTemplateStream(
  out AOwned: Boolean): TStream;
var
  S: string;
begin
  Result := nil;
  if DesignerFileManager <> nil then
  begin
    S := GetProducerTemplateFileName;
    if S <> '' then
      Result := DesignerFileManager.GetStream(S, AOwned);
  end;
  if Result = nil then
    Result := GetTemplateStream(AOwned);
end;

function TBasePageProducer.GetProducerTemplateFileName: string;
begin
  Result := GetTemplateFileName;
  if DesignerFileManager <> nil then
    if Result <> '' then
      Result := DesignerFileManager.QualifyFileName(Result);
end;

function TBasePageProducer.GetTemplateFileName: string;
begin
  Result := '';
end;

{ TCustomPageProducer }

constructor TCustomPageProducer.Create(AOwner: TComponent);
begin
  inherited Create(AOwner);
  FHTMLDoc := TStringList.Create;
end;

destructor TCustomPageProducer.Destroy;
begin
  FHTMLDoc.Free;
  inherited Destroy;
end;

function TCustomPageProducer.GetTemplateStream(out AOwned: Boolean): TStream;
var
  ManagerIntf: ILocateFileService;
begin
  if FHTMLFile <> '' then
  begin
    ManagerIntf := GetLocateFileService;
    if ManagerIntf <> nil then
      Result := ManagerIntf.GetTemplateStream(Self, FHTMLFile, AOwned)
    else
      Result := nil;
    if Result = nil then
    begin
      Result :=  TFileStream.Create(GetProducerTemplateFileName {Qualified name}, fmOpenRead + fmShareDenyWrite);
      AOwned := True;
    end;
  end
  else
  begin
    Result := TStringStream.Create(FHTMLDoc.Text);
    AOwned := True;
  end;
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

function TCustomPageProducer.HandleTag(const TagString: string;
  TagParams: TStrings): string;
begin
  Result := ImplHandleTag(TagString, TagParams);
end;

function ScriptProducerContentFromStream(AStream: TStream; AWebModuleContext: TWebModuleContext;
  AStripParamQuotes: Boolean; AHandleTag: THandleTagProc; const AScriptEngine: string;
  ALocateFileService: ILocateFileService): string;
var
  ScriptProducer: IScriptProducer;
begin
  Result := '';
  Assert(Assigned(ScriptProducerClass), 'Unassigned ScriptProducerClass'); // Do not localize
  ScriptProducer := ScriptProducerClass.Create(AWebModuleContext,
    AStripParamQuotes, AHandleTag, AScriptEngine, ALocateFileService) as IScriptProducer;
  ScriptProducer.ParseStream(AStream);
  Result := ScriptProducer.Evaluate;
end;

function ScriptProducerContentFromString(const S: string; AWebModuleContext: TWebModuleContext;
  AStripParamQuotes: Boolean; AHandleTag: THandleTagProc;
  const AScriptEngine: string; ALocateFileService: ILocateFileService): string;
var
  Stream: TStream;
begin
  Stream := TStringStream.Create(S);
  try
    Result := ScriptProducerContentFromStream(Stream, AWebModuleContext,
      AStripParamQuotes, AHandleTag, AScriptEngine, ALocateFileService);
  finally
    Stream.Free;
  end;
end;

function ContentFromStream(AStream: TStream;
  AStripParamQuotes: Boolean; AHandleTag: THandleTagProc; AHandledTag: THandledTagProc): string;
var
  Parser: TCopyParser;
  OutStream: TStringStream;
  ParamStr, ReplaceStr, TokenStr, SaveParamStr: string;
  ParamList: TStringList;
begin
  OutStream := TStringStream.Create('');
  try
    Parser := TCopyParser.Create(AStream, OutStream);
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
              if Assigned(AHandledTag) then
              begin
                SaveParamStr := ParamStr;  // ExtractHTTPFields modifies ParamStr
                if Length(SaveParamStr) > 0 then
                  SaveParamStr := ' ' + SaveParamStr;
                UniqueString(SaveParamStr);
              end;
              ExtractHTTPFields([' '], [' '], PChar(ParamStr), ParamList, AStripParamQuotes);
              if Assigned(AHandledTag) then
              begin
                if not AHandledTag(TokenStr, ParamList, ReplaceStr) then
                  ReplaceStr := '<#' + TokenStr + SaveParamStr + '>'
              end
              else if Assigned(AHandleTag) then
                ReplaceStr := AHandleTag(TokenStr, ParamList)
              else
                { Replace tag with empty string}
                ReplaceStr := '';
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

function ContentFromString(const AValue: string;
  AStripParamQuotes: Boolean; AHandleTag: THandleTagProc; AHandledTag: THandledTagProc): string;
var
  InStream: TStream;
begin
  InStream := TStringStream.Create(AValue);
  try
    Result := ContentFromStream(InStream, AStripParamQuotes, AHandleTag, AHandledTag);
  finally
    InStream.Free;
  end;
end;

function ContentFromScriptStream(AStream: TStream;
  AWebModuleContext: TWebModuleContext; AStripParamQuotes: Boolean;
  AHandleTag: THandleTagProc; AHandleScriptTag: THandledTagProc;
  const AScriptEngine: string; ALocateFileService: ILocateFileService): string;
begin
  if Assigned(ScriptProducerClass) then
  begin
    if Assigned(AHandleScriptTag) then
    begin
      Result := ContentFromStream(AStream, AStripParamQuotes, nil, AHandleScriptTag);
      Result := ScriptProducerContentFromString(Result, AWebModuleContext,
        AStripParamQuotes, AHandleTag, AScriptEngine, ALocateFileService);
    end
    else
      Result := ScriptProducerContentFromStream(AStream, AWebModuleContext,
        AStripParamQuotes, AHandleTag, AScriptEngine, ALocateFileService);
  end
  else
    Result := ContentFromStream(AStream, AStripParamQuotes, AHandleTag, nil);
end;

function ContentFromScriptFile(const AFileName: TFileName;
  AWebModuleContext: TWebModuleContext;  AStripParamQuotes: Boolean;
  AHandleTag: THandleTagProc; AHandleScriptTag: THandledTagProc;
  const AScriptEngine: string; ALocateFileService: ILocateFileService): string;
var
  InStream: TStream;
begin
  InStream := TFileStream.Create(AFileName, fmOpenRead + fmShareDenyWrite);
  try
    Result := ContentFromScriptStream(InStream, AWebModuleContext, AStripParamQuotes,
      AHandleTag, AHandleScriptTag, AScriptEngine, ALocateFileService);
  finally
    InStream.Free;
  end;
end;

function FindComponentWebModuleContext(AComponent: TComponent): TWebModuleContext;
var
  Intf: IUnknown;
  Component: TComponent;
begin
  Component := AComponent;
  while Assigned(Component) do
  begin
    if Supports(IInterface(Component), IWebVariablesContainer, Intf) then
    begin
      Result := Component;
      Exit;
    end;
    Component := Component.GetParentComponent;
  end;
  if (AComponent <> nil) and (AComponent.Owner <> nil) then
  begin
    Result := AComponent.Owner;
    if Supports(Result, IWebVariablesContainer, Intf) then
      Exit;
  end;

  Result := nil;
end;

function TCustomPageProducer.GetTemplateFileName: string;
begin
  Result := HTMLFile;
end;

{ TAbstractScriptProducer }

constructor TAbstractScriptProducer.Create(
  AWebModuleContext: TWebModuleContext;
  AStripParamQuotes: Boolean; AHandleTag: THandleTagProc;
  const AScriptEngine: string; ALocateFileService: ILocateFileService);
begin
  inherited Create;
end;

{ EScriptError }

constructor EScriptError.Create(const AErrors: TAbstractScriptErrors;
  const AContent: string);
begin
  inherited Create(AErrors[0].Description);
  FErrors := AErrors;
  FContent := AContent;
end;

destructor EScriptError.Destroy;
begin
  inherited;
  FErrors.Free;

end;

end.
