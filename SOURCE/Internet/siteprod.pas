
{*******************************************************}
{                                                       }
{       Borland Delphi Visual Component Library         }
{                                                       }
{  Copyright (c) 2000-2001 Borland Software Corp.       }
{                                                       }
{*******************************************************}

unit SiteProd;

interface

uses Classes, HTTPApp, HTTPProd, PagItems, MidProd,
  CompProd, WebComp, SysUtils, DSProd, SiteComp, Contnrs, WebForm;

type

  TSitePageElements = class(TObject)
  public
    StylesContent: string;
    WarningsContent: string;
    ServerScriptContent: string;
    ServerFunctionsContent: string;
    ServerVariablesContent: string;
  end;

  TBaseAdapterPageProducer = class(TBasePageItemsProducer, IWebComponentEditor, ISetWebContentOptions,
     IProducerEditorViewSupport)
  private
    FPageElements: TSitePageElements;
    FStyles: TStrings;
    FStylesFile: TFileName;
    FBeforeGetContent: TNotifyEvent;
    FAfterGetContent: TNotifyEvent;
    FLockContent: Integer;
    FContentOptions: TWebContentOptions;
    procedure LockContent;
    procedure UnlockContent;
    function DeclareScriptFunctions(
      AGeneratedFunctions: TGeneratedFunctions): string;
    function DeclareScriptVariables(AVariables: TStrings): string;
  protected
    { IWebPageProducerEditorViewSupport }
    function HasScriptView: Boolean;
    function HasXMLBrowserView: Boolean;
    function HasXSLBrowserView: Boolean;
    function HasHTMLBrowserView: Boolean;
    function GetXMLData(var Owned: Boolean): TStream;
    function GetXSLData(var Owned: Boolean): TStream;
    function GetTemplateFileType: string;
    { ISetWebContentOptions }
    procedure SetWebContentOptions(AOptions: TWebContentOptions);
    { IWebComponentEditor }
    function CanAddClass(AParent: TComponent; AClass: TClass): Boolean;
    function ImplCanAddClass(AParent: TComponent; AClass: TClass): Boolean; virtual;

    procedure DoBeforeGetContent;
    procedure DoAfterGetContent;
    procedure GeneratePageElements; virtual;
    procedure DoTagEvent(Tag: TTag; const TagString: string; TagParams: TStrings;
       var ReplaceText: string); override;
    function HandleScriptTag(const TagString: string;
      TagParams: TStrings; var ReplaceString: string): Boolean; override;

    function DeclareStyles: string; virtual;
    function DeclareWarnings(Warnings: TStrings): string; virtual;
    function CreatePageElements: TSitePageElements; virtual;
    property PageElements: TSitePageElements read FPageElements;
    function GetContentOptions(var Owned: Boolean): TWebContentOptions; override;
    function GetDefaultTemplate: string; virtual;
  public
    constructor Create(AComponent: TComponent); override;
    destructor Destroy; override;
    function ContentFromStream(InStream: TStream): string; override;
    class function GetRequiredTags: string;
    class procedure GetScriptEngines(S: TStrings);
    procedure SetStyles(Value: TStrings);
    procedure SetStylesFile(const Value: TFileName);
    property OnBeforeGetContent: TNotifyEvent read FBeforeGetContent write FBeforeGetContent;
    property OnAfterGetContent: TNotifyEvent read FAfterGetContent write FAfterGetContent;
    property Styles: TStrings read FStyles write SetStyles;
    property StylesFile: TFileName read FStylesFile write SetStylesFile;
  end;

  TCustomAdapterPageProducer = class(TBaseAdapterPageProducer, IWebContent)
  private
    FHTMLFile: TFileName;
    FHTMLDoc: TStrings;
  protected
    function GetTemplateFileName: string; override;
    function GetTemplateStream(out AOwned: Boolean): TStream; override;
    { IWebContent }
    function IWebContent.Content = WebContent;
    function WebContent(Options: TWebContentOptions; Layout: TLayout): string;

    procedure SetHTMLDoc(const Value: TStrings);
    procedure SetHTMLFile(const Value: TFileName);
  public
    constructor Create(AOwner: TComponent); override;
    destructor Destroy; override;
    property HTMLDoc: TStrings read FHTMLDoc write SetHTMLDoc;
    property HTMLFile: TFileName read FHTMLFile write SetHTMLFile;
  end;

  TAdapterPageProducer = class(TCustomAdapterPageProducer)
  published
    property OnBeforeGetContent;
    property OnAfterGetContent;
    property Styles;
    property StylesFile;
    property WebPageItems;
    property HTMLDoc;
    property HTMLFile;
  end;


implementation

uses WebConst,
  DB, DBClient, MidItems, WbmConst;

{ TCustomSizePageProducerModule }

const
  sStylesTag = 'STYLES';
  sWarningsTag = 'WARNINGS';
  sServerScriptTag = 'SERVERSCRIPT';

procedure TBaseAdapterPageProducer.DoTagEvent(Tag: TTag; const TagString: string;
  TagParams: TStrings; var ReplaceText: string);
var
  I: Integer;
  WebContentOptions: TWebContentOptions;
  Owned: Boolean;
begin
  if (Tag = tgCustom) and (CompareText(TagString, sWarningsTag) = 0) then
  begin
    if Assigned(PageElements) then
      ReplaceText := PageElements.WarningsContent;
    Exit;
  end
  else if (Tag = tgCustom) and (CompareText(TagString, sStylesTag) = 0) then
  begin
    if Assigned(PageElements) then
      ReplaceText := PageElements.StylesContent;
    Exit;
  end;
  inherited DoTagEvent(Tag, TagString, TagParams, ReplaceText);
  if (csDesigning in ComponentState) and (ReplaceText = '') then
  begin
    WebContentOptions := GetContentOptions(Owned);
    try
      if not (coNoScript in WebContentOptions.Flags) then
      begin
        // Preserve custom tag when viewing HTML
        for I := 0 to TagParams.Count - 1 do
          ReplaceText := ReplaceText + ' ' + TagParams[I];
        ReplaceText := Format('<#%s%s>', [TagString, ReplaceText]);
      end
    finally
      if Owned then
        WebContentOptions.Free;
    end;
  end;
end;

function TBaseAdapterPageProducer.HandleScriptTag(const TagString: string;
  TagParams: TStrings; var ReplaceString: string): Boolean;
begin
  Result := False;
  if CompareText(TagString, sServerScriptTag) = 0 then
  begin
    Result := Assigned(PageElements);
    if Result then
      ReplaceString := #13#10 + PageElements.ServerVariablesContent + PageElements.ServerFunctionsContent + PageElements.ServerScriptContent;
  end;
end;

function TBaseAdapterPageProducer.CreatePageElements: TSitePageElements;
begin
  Result := TSitePageElements.Create;
end;

function TBaseAdapterPageProducer.DeclareStyles: string;
  function FormatStyles(const S: string): string;
  begin
    if S <> '' then
      Result := Format('<STYLE TYPE="text/css">'#13#10'%0:s'#13#10'</STYLE>'#13#10,  { do not localize }
        [S])
    else
      Result := '';
  end;

var
  InStream: TFileStream;
  S: string;
begin
  if StylesFile <> '' then
  begin
    InStream := TFileStream.Create(StylesFile, fmOpenRead + fmShareDenyWrite);
    try
      SetLength(S, InStream.Size);
      SetLength(S, InStream.Read(PChar(S)[0], Instream.Size));
      Result := FormatStyles(S);
    finally
      Instream.Free;
    end;
  end
  else
    Result := FormatStyles(Styles.Text);
end;

function TBaseAdapterPageProducer.DeclareScriptFunctions(AGeneratedFunctions: TGeneratedFunctions): string;
var
  I: Integer;
begin
  Result := '';
  for I := 0 to AGeneratedFunctions.ItemCount - 1 do
    Result := Result + AGeneratedFunctions.Script[I] + #13#10;
end;


function TBaseAdapterPageProducer.DeclareScriptVariables(AVariables: TStrings): string;
var
  I: Integer;
begin
  Result := '';
  for I := 0 to AVariables.Count - 1 do
    Result := Result + AVariables[I] + #13#10;
  if Result <> '' then
    Result := '<%'#13#10 + Result + '%>'#13#10;  
end;


function TBaseAdapterPageProducer.DeclareWarnings(Warnings: TStrings): string;
var
  I: Integer;
begin
  Result := '';
  if Warnings.Count > 0 then
  begin
    for I := 0 to Warnings.Count - 1 do
      Result := Format('%s  <LI>%s'#13#10, [Result, Warnings[I]]);  { do not localize }
    Result := Format('<UL>'#13#10 +                                 { do not localize }
                     '%s' +
                     '</UL>'#13#10, [Result]);                      { do not localize }
    Result := Format(sWarningsBody, [Result]);
  end;
end;

type
  TFormRequirements = class(TAbstractFormRequirements)
  private
    FGeneratedFunctions: TGeneratedFunctions;
    FVariables: TStrings;
  public
    procedure AddObject(AObject: TObject);
    function IsFunctionDefined(const AName: string): Boolean; override;
    function IsVariableDefined(const AName: string): Boolean; override;
    procedure DefineVariable(const AName, AValue: string); override;
    procedure DefineFunction(const AName, ABody: string); override;
    constructor Create;
    destructor Destroy; override;
  end;

function TFormRequirements.IsFunctionDefined(const AName: string): Boolean;
begin
  Result := FGeneratedFunctions.Exists(AName);
end;

procedure TFormRequirements.DefineFunction(const AName, ABody: string);
begin
  FGeneratedFunctions.Add(AName, ABody);
end;

constructor TFormRequirements.Create;
begin
  FGeneratedFunctions := TGeneratedFunctions.Create;
  FVariables := TStringList.Create;
end;

destructor TFormRequirements.Destroy;
begin
  inherited;
  FGeneratedFunctions.Free;
  FVariables.Free;
end;

procedure TFormRequirements.AddObject(AObject: TObject);
var
  I: Integer;
  GetIntf: IGetFormRequirements;
  GetWebComponentList: IGetWebComponentList;
  Container: IWebComponentContainer;
begin
  if Supports(AObject, IGetFormRequirements, GetIntf) then
    GetIntf.GetFormRequirements(Self)
  else if Supports(AObject, IGetWebComponentList, GetWebComponentList) then
  begin
    Supports(GetWebComponentList.GetComponentList, IWebComponentContainer, Container);
    if Container <> nil then
      for I := 0 to Container.ComponentCount - 1 do
        Self.AddObject(Container.Components[I]);
  end;
end;

{ TBaseAdapterPageProducer }

procedure TBaseAdapterPageProducer.GeneratePageElements;
var
  I: Integer;
  WebContent: IWebContent;
  WebContentOptions: TWebContentOptions;
  Owned: Boolean;
  Warnings: TDesigntimeWarnings;
  FormRequirements: TFormRequirements;
begin
  WebContentOptions := GetContentOptions(Owned);
  try
    for I := 0 to WebPageItems.Count - 1 do
      if Supports(IInterface(WebPageItems[I]), IWebContent, WebContent) then
        PageElements.ServerScriptContent := PageElements.ServerScriptContent + WebContent.Content(WebContentOptions, nil);

    PageElements.StylesContent := DeclareStyles;

    FormRequirements := TFormRequirements.Create;
    try
      for I := 0 to WebPageItems.Count - 1 do
        FormRequirements.AddObject(WebPageItems[I]);
      PageElements.ServerFunctionsContent := DeclareScriptFunctions(FormRequirements.FGeneratedFunctions);
      PageElements.ServerVariablesContent := DeclareScriptVariables(FormRequirements.FVariables);
    finally
      FormRequirements.Free;
    end;

    if csDesigning in ComponentState then
    begin
      Warnings := TDesignTimeWarnings.Create;
      try
        for I := 0 to WebPageItems.Count - 1 do
          Warnings.AddObject(WebPageItems[I]);
        PageElements.WarningsContent := DeclareWarnings(Warnings.Strings);
      finally
        Warnings.Free;
      end;
    end;
  finally
    if Owned then
      WebContentOptions.Free;
  end;
end;

constructor TBaseAdapterPageProducer.Create(AComponent: TComponent);
begin
  inherited;
  FStyles := TStringList.Create;
  ScriptEngine := 'JScript';  { do not localize }
end;

destructor TBaseAdapterPageProducer.Destroy;
begin
  FStyles.Free; 
  inherited;
end;

function TBaseAdapterPageProducer.GetDefaultTemplate: string;
begin
  Result := Format('<html>'#13#10 +                { do not localize }
             '<head>'#13#10 +                      { do not localize }
             '</head>'#13#10 +                     { do not localize }
             '<body>'#13#10 +                      { do not localize }
             '<#%0:s><#%1:s><#%2:s>'#13#10 +
             '</body>'#13#10 +                     { do not localize }
             '</html>'#13#10, [sStylesTag,         { do not localize }
               sWarningsTag, sServerScriptTag]);

end;

class function TBaseAdapterPageProducer.GetRequiredTags: string;
begin
  Result := Format('<#%0:s><#%1:s><#%2:s>', [sStylesTag,
               sWarningsTag, sServerScriptTag]);

end;

function TBaseAdapterPageProducer.CanAddClass(AParent: TComponent; AClass: TClass): Boolean;
begin
  Result := ImplCanAddClass(AParent, AClass);
end;

function TBaseAdapterPageProducer.ImplCanAddClass(AParent: TComponent; AClass: TClass): Boolean;
begin
  Result := AClass.InheritsFrom(TCustomAdapterForm) or
    AClass.InheritsFrom(TCustomLayoutGroup);
end;

procedure TBaseAdapterPageProducer.SetStyles(Value: TStrings);
begin
  FStyles.Assign(Value);
  FStylesFile := '';
end;

procedure TBaseAdapterPageProducer.SetStylesFile(const Value: TFileName);
begin
  if CompareText(FStylesFile, Value) <> 0 then
  begin
    FStyles.Clear;
    FStylesFile := Value;
  end;
end;

function TBaseAdapterPageProducer.ContentFromStream(InStream: TStream): string;
var
  Options: TWebContentOptions;
  Owned: Boolean;
begin
  Result := '';
  if FLockContent = 0 then
  begin
    LockContent;
    Options := GetContentOptions(Owned);
    try
      try
        DoBeforeGetContent;
        try
          if not Assigned(Dispatcher) or not Assigned(Dispatcher.Response) or not
            Dispatcher.Response.Sent then
          begin
            Assert(FPageElements = nil, 'Unexpected value');  { do not localize }
            FPageElements := CreatePageElements;
            try
              GeneratePageElements;
              Result := '';
              if (coNoExecuteScript in Options.Flags) then
                Result := ServerScriptFromStream(InStream)
              else
                Result := inherited ContentFromStream(InStream);
            finally
              FreeAndNil(FPageElements);
            end;
          end;
        finally
          DoAfterGetContent;
        end;
      finally
        if Owned then
          Options.Free;
      end;
    finally
      UnlockContent;
    end;
  end;
end;


procedure TBaseAdapterPageProducer.LockContent;
begin
  Inc(FLockContent);
end;

procedure TBaseAdapterPageProducer.UnlockContent;
begin
  Dec(FLockContent);
end;

procedure TBaseAdapterPageProducer.DoAfterGetContent;
begin
  if Assigned(FAfterGetContent) then
    FAfterGetContent(Self);
end;

procedure TBaseAdapterPageProducer.DoBeforeGetContent;
begin
  if Assigned(FBeforeGetContent) then
    FBeforeGetContent(Self);
end;

function TBaseAdapterPageProducer.GetContentOptions(
  var Owned: Boolean): TWebContentOptions;
begin
  if Assigned(FContentOptions) then
  begin
    Owned := False;
    Result := FContentOptions;
  end
  else
  begin
    Owned := True;
    Result := TWebContentOptions.Create([]);
  end;
end;

{ TCustomAdapterPageProducer }

constructor TCustomAdapterPageProducer.Create(AOwner: TComponent);
begin
  inherited;
  FHTMLDoc := TStringList.Create;
  FHTMLDoc.Text := GetDefaultTemplate;
end;

destructor TCustomAdapterPageProducer.Destroy;
begin
  inherited;
  FHTMLDoc.Free;
end;

procedure TCustomAdapterPageProducer.SetHTMLDoc(const Value: TStrings);
begin
  FHTMLDoc.Assign(Value);
  FHTMLFile := '';
end;

procedure TCustomAdapterPageProducer.SetHTMLFile(const Value: TFileName);
begin
  if CompareText(FHTMLFile, Value) <> 0 then
  begin
    FHTMLDoc.Clear;
    FHTMLFile := Value;
  end;
end;

function TCustomAdapterPageProducer.GetTemplateStream(out AOwned: Boolean): TStream;
  function GetLocateFileService: ILocateFileService;
  var
    GetIntf: IGetLocateFileService;
  begin
    Result := nil;
    if Supports(IUnknown(DispatcherComponent), IGetLocateFileService, GetIntf) then
      Result := GetIntf.GetLocateFileService;
  end;
var
  S: string;
  ManagerIntf: ILocateFileService;
begin
  AOwned := True;
  if HTMLFile <> '' then
  begin
    // Result := TFileStream.Create(HTMLFile, fmOpenRead + fmShareDenyWrite)
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
    S := HTMLDoc.Text;
    if Trim(S) = '' then
      S := GetDefaultTemplate;
    Result := TStringStream.Create(S);
  end;
end;

function TCustomAdapterPageProducer.WebContent(
  Options: TWebContentOptions; Layout: TLayout): string;
var
  InStream: TStream;
  Owned: Boolean;
begin
  InStream := GetTemplateStream(Owned);
  Assert(FContentOptions = nil, 'Unexpected value');  { do not localize }
  FContentOptions := Options;
  try
    Result := ContentFromStream(InStream);
  finally
    if Owned then
      InStream.Free;
    FContentOptions := nil;
  end;
end;

procedure TBaseAdapterPageProducer.SetWebContentOptions(
  AOptions: TWebContentOptions);
begin
  FContentOptions := AOptions;
end;

class procedure TBaseAdapterPageProducer.GetScriptEngines(S: TStrings);
begin
  S.Clear;
  S.Add('JSCRIPT');  // Do not localize
end;

function TBaseAdapterPageProducer.HasScriptView: Boolean;
begin
  Result := True;
end;

function TBaseAdapterPageProducer.HasXMLBrowserView: Boolean;
begin
  Result := False;
end;

function TBaseAdapterPageProducer.GetXMLData(var Owned: Boolean): TStream;
begin
  Result := nil;
end;

function TBaseAdapterPageProducer.GetXSLData(var Owned: Boolean): TStream;
begin
  Result := nil;
end;

function TBaseAdapterPageProducer.HasHTMLBrowserView: Boolean;
begin
  Result := True;
end;

function TBaseAdapterPageProducer.HasXSLBrowserView: Boolean;
begin
  Result := False;
end;

function TBaseAdapterPageProducer.GetTemplateFileType: string;
begin
  Result := 'HTML';  { do not localize }
end;

function TCustomAdapterPageProducer.GetTemplateFileName: string;
begin
  Result := HTMLFile;
end;

procedure TFormRequirements.DefineVariable(const AName, AValue: string);
begin
  inherited;
  FVariables.Add(Format('%s=%s', [AName, AValue]))
end;

function TFormRequirements.IsVariableDefined(const AName: string): Boolean;
begin
  Result := FVariables.IndexOf(AName) <> -1;
end;

end.

