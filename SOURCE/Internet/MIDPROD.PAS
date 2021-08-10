
{*******************************************************}
{                                                       }
{       Borland Delphi Visual Component Library         }
{                                                       }
{       Copyright (c) 1999 Inprise Corporation          }
{                                                       }
{*******************************************************}

unit MidProd;

interface

uses Classes, Messages, ImgList, HTTPApp, PagItems, XMLBrokr,
  CompProd, WebComp, SysUtils;

type

  TXMLDataEvent = procedure (Sender: TObject; Request: TWebRequest; XMLBroker: TXMLBroker; var OwnerData: OleVariant) of object;

  TMidasPageElements = class(TObject)
  public
    IncludesContent: string;
    StylesContent: string;
    FormsContent: string;
    ScriptContent: string;
    WarningsContent: string;
    function BodyContent: string; virtual;
  end;

  TStdInclude = (jsDom, jsDB, jsDisp, jsBind, jsErrDisp, jsShow);
  TStdIncludes = set of TStdInclude;

  TCustomMidasPageProducer = class(TPageItemsProducer, IWebContent, IWebComponentEditor,
    IScriptProducer)
  private
    FPageElements: TMidasPageElements;
    FStyles: TStrings;
    FEnableXMLIslands: Boolean;
    FIncludePathURL: string;
    FScriptManager: IScriptManager;
    FBeforeGetXMLData: TXMLDataEvent;
    FAfterGetXMLData: TXMLDataEvent;
    FStylesFile: TFileName;
    FBeforeGetContent: TNotifyEvent;
    FAfterGetContent: TNotifyEvent;
  protected
    { IWebComponentEditor }
    function CanAddClass(AParent: TComponent; AClass: TClass): Boolean;
    function ImplCanAddClass(AParent: TComponent; AClass: TClass): Boolean; virtual;

    procedure DoBeforeGetXMLData(XMLBroker: TXMLBroker; var OwnerData: OleVariant);
    procedure DoAfterGetXMLData(XMLBroker: TXMLBroker; var OwnerData: OleVariant);
    procedure DoBeforeGetContent;
    procedure DoAfterGetContent;
    procedure GeneratePageElements; virtual;
    procedure DoTagEvent(Tag: TTag; const TagString: string; TagParams: TStrings;
      var ReplaceText: string); override;
    function GetContentOptions(var Owned: Boolean): TWebContentOptions; override;
    { IWebContent }
    function IWebContent.Content = WebContent;
    function WebContent(Options: TWebContentOptions; Layout: TLayout): string;
    { IScriptProducer }
    function GetScriptManager: IScriptManager;
    function GetXMLDelta(XMLBroker: TXMLBroker): string;
    function GetXMLErrors(XMLBroker: TXMLBroker): string;
    function GetDefaultTemplate: string; virtual;
    function GetUseXMLIslands: Boolean; virtual;
    function DeclareRowSets: string; virtual;
    function DeclareXMLDocuments: string; virtual;
    function DeclareXMLIslands: string; virtual;
    function DeclareIncludes: string; virtual;
    function DeclareStyles: string; virtual;
    function DeclareFunctions: string; virtual;
    function DeclareWarnings(Warnings: TStrings): string; virtual;
    function DeclareScript(XMLIslands: Boolean): string; virtual;
    procedure AddScriptComponents; virtual;
    procedure AddIncludes; virtual;
    function CreateScriptManager(Options: TWebContentOptions): TObject; virtual;
    function CreatePageElements: TMidasPageElements; virtual;
    property ScriptManager: IScriptManager read GetScriptManager;
    property PageElements: TMidasPageElements read FPageElements;
  public
    constructor Create(AComponent: TComponent); override;
    destructor Destroy; override;
    function FindXMLBroker(TagParams: TStrings): TXMLBroker; virtual;
    function FindXMLBrokerName(TagParams: TStrings): string;  virtual;
    function GetXMLData(XMLBroker: TXMLBroker; XMLOptions: TXMLOptions): string; virtual;
    function Content: string; override;
    procedure SetIncludePathURL(const Value: string);
    procedure SetStyles(Value: TStrings);
    procedure SetStylesFile(const Value: TFileName);
    property IncludePathURL: string read FIncludePathURL write SetIncludePathURL;
    property OnBeforeGetXMLData: TXMLDataEvent read FBeforeGetXMLData write FBeforeGetXMLData;
    property OnAfterGetXMLData: TXMLDataEvent read FAfterGetXMLData write FAfterGetXMLData;
    property OnBeforeGetContent: TNotifyEvent read FBeforeGetContent write FBeforeGetContent;
    property OnAfterGetContent: TNotifyEvent read FAfterGetContent write FAfterGetContent;
    property Styles: TStrings read FStyles write SetStyles;
    property StylesFile: TFileName read FStylesFile write SetStylesFile;
    property EnableXMLIslands: Boolean read FEnableXMLIslands write FEnableXMLIslands default true;
  end;

  TMidasPageProducer = class(TCustomMidasPageProducer)
  published
    property IncludePathURL;
    property OnBeforeGetXMLData;
    property OnAfterGetXMLData;
    property OnBeforeGetContent;
    property OnAfterGetContent;
    property Styles;
    property StylesFile;
    property WebPageItems;
    property EnableXMLIslands;
  end;

const
  sXMLBroker = 'XMLBROKER';
  sXMLReadyVar = 'xml_ready';

procedure AddStdIncludes(StdIncludes: TStdIncludes; AddIntf: IAddScriptElements);
function PathInfoToRelativePath(const PathInfo: string): string;

implementation

uses Forms, Menus, Consts, Graphics, Controls, WebConst,
  Db, DbClient, ScrptMgr, MidItems, WbmConst;

{ TCustomMidasPageProducer }

const
  sDataPacketTag = 'DATAPACKET';
  sQuoteXMLAttribute = 'QUOTE';
  sQuoteXML = sQuoteXMLAttribute + '="True"'; // Do not localize
  sScriptTag = 'SCRIPT';
  sStylesTag = 'STYLES';
  sFormsTag = 'FORMS';
  sIncludesTag = 'INCLUDES';
  sBodyTag = 'BODYELEMENTS';
  sWarningsTag = 'WARNINGS';

function TCustomMidasPageProducer.FindXMLBrokerName(TagParams: TStrings): string;
begin
  Result := TagParams.Values[sXMLBroker];
end;

function TCustomMidasPageProducer.FindXMLBroker(TagParams: TStrings): TXMLBroker;
var
  XMLBrokerName: string;
  Component: TComponent;
begin
  XMLBrokerName := FindXMLBrokerName(TagParams);
  if XMLBrokerName <> '' then
    if Owner <> nil then
    begin
      Component := Owner.FindComponent(XMLBrokerName);
      if Assigned(Component) and (Component is TXMLBroker) then
      begin
        Result := TXMLBroker(Component);
        Exit;
      end;
    end;
  Result := nil;
end;

function TCustomMidasPageProducer.GetXMLDelta(XMLBroker: TXMLBroker): string;
begin
  if Dispatcher <> nil then
    Result := XMLBroker.GetDelta(Dispatcher.Request)
  else
    Result := '';
end;

function TCustomMidasPageProducer.GetXMLErrors(XMLBroker: TXMLBroker): string;
begin
  Result := XMLBroker.GetErrors;
end;

function TCustomMidasPageProducer.GetUseXMLIslands: Boolean;
var
  Request: TWebRequest;
  P: Integer;
begin
  Result := False;
  if EnableXMLIslands then
  begin
    if (csDesigning in ComponentState) then
      Result := True
    else
    begin
      if Dispatcher <> nil then
        Request := Dispatcher.Request
      else
        Request := nil;
      if Assigned(Request) then
      begin
        P := Pos('MSIE', Request.UserAgent);
        Result := (P > 0) and (Copy(Request.UserAgent, P + 5, 1) >= '5');
      end;
    end;
  end;
end;

function TCustomMidasPageProducer.GetXMLData(XMLBroker: TXMLBroker;
  XMLOptions: TXMLOptions): string;
var
  OwnerData: OleVariant;
  Request: TWebRequest;
  RecCount: Integer;    
begin
  if Dispatcher <> nil then
    Request := Dispatcher.Request
  else
    Request := nil;
  DoBeforeGetXMLData(XMLBroker, OwnerData);
  Result := XMLBroker.RequestRecords(Self, Request, RecCount, OwnerData, XMLOptions);
  DoAfterGetXMLData(XMLBroker, OwnerData);
end;

procedure TCustomMidasPageProducer.DoTagEvent(Tag: TTag; const TagString: string;
  TagParams: TStrings; var ReplaceText: string);
var
  XMLBroker: TXMLBroker;
  XMLOptions: TXMLOptions;
  I: Integer;
begin
  if not (csDesigning in ComponentState) then
    if (Tag = tgCustom) and (CompareText(TagString, sDataPacketTag) = 0) then
    begin
      XMLBroker := FindXMLBroker(TagParams);
      XMLOptions := [];
      if CompareText(TagParams.Values[sQuoteXMLAttribute], 'True') = 0 then
        XMLOptions := XMLOptions + [xoQuote];
      if Assigned(XMLBroker) then
        ReplaceText := GetXMLData(XMLBroker, XMLOptions);
      Exit;
    end;

  if (Tag = tgCustom) and (CompareText(TagString, sScriptTag) = 0) then
  begin
    if Assigned(PageElements) then
      ReplaceText := PageElements.ScriptContent;
    Exit;
  end
  else if (Tag = tgCustom) and (CompareText(TagString, sIncludesTag) = 0) then
  begin
    if Assigned(PageElements) then
      ReplaceText := PageElements.IncludesContent;
    Exit;
  end
  else if (Tag = tgCustom) and (CompareText(TagString, sWarningsTag) = 0) then
  begin
    if Assigned(PageElements) then
      ReplaceText := PageElements.WarningsContent;
    Exit;
  end
  else if (Tag = tgCustom) and (CompareText(TagString, sFormsTag) = 0) then
  begin
    if Assigned(PageElements) then
      ReplaceText := PageElements.FormsContent;
    Exit;
  end
  else if (Tag = tgCustom) and (CompareText(TagString, sStylesTag) = 0) then
  begin
    if Assigned(PageElements) then
      ReplaceText := PageElements.StylesContent;
    Exit;
  end
  else if (Tag = tgCustom) and (CompareText(TagString, sBodyTag) = 0) then
  begin
    if Assigned(PageElements) then
      ReplaceText := PageElements.BodyContent;
    Exit;
  end;
  inherited DoTagEvent(Tag, TagString, TagParams, ReplaceText);
  if (csDesigning in ComponentState) and (ReplaceText = '') and
    Assigned(ScriptManager) and not (coNoScript in ScriptManager.Options.Flags) then
    begin
      // Preserve custom tag when viewing HTML
      for I := 0 to TagParams.Count - 1 do
        ReplaceText := ReplaceText + ' ' + TagParams[I];
      ReplaceText := Format('<#%s%s>', [TagString, ReplaceText]);
    end;
end;

function TCustomMidasPageProducer.CreateScriptManager(Options: TWebContentOptions): TObject;
begin
  Result := TScriptManager.Create(Options);
end;

function TCustomMidasPageProducer.CreatePageElements: TMidasPageElements;
begin
  Result := TMidasPageElements.Create;
end;

function TCustomMidasPageProducer.DeclareRowSets: string;
var
  I, J: Integer;
  Names: TStrings;
  S: string;
  XMLDocument: IXMLDocument;
  XMLRowSet: IXMLRowSet;
begin
  Result := '';
  Names := TStringList.Create;
  try
    for I := 0 to ScriptManager.XMLDocuments.Count - 1 do
    begin
      XMLDocument := ScriptManager.XMLDocuments.Items[I];
      for J := 0 to XMLDocument.RowSets.Count - 1 do
      begin
        XMLRowSet := XMLDocument.RowSets.Items[J];
        S := XMLRowSet.GetRowSetVarName;
        if Names.IndexOf(S) = -1 then
        begin
          Names.Add(S);
          Result := Result + Format('var %0:s = new xmlRowSet(%1:s, %2:s, %3:s);'#13#10,
            [S, XMLDocument.DocumentVarName, XMLRowSet.MasterRowSetVarName,
              XMLRowSet.MasterDataSetFieldName]);
        end;
      end;
    end;
  finally
    Names.Free;
  end;
end;

function TCustomMidasPageProducer.DeclareXMLDocuments: string;
var
  I: Integer;
  XMLDocument: IXMLDocument;
  XMLBroker: TXMLBroker;
  XMLOptions: TXMLOptions;
begin
  XMLOptions := [xoQuote];
  Result := '';
  for I := 0 to ScriptManager.XMLDocuments.Count - 1 do
  begin
    XMLDocument := ScriptManager.XMLDocuments.Items[I];
    if XMLDocument.RowSets.Count > 0 then
    begin
      XMLBroker := XMLDocument.Component as TXMLBroker;
      Result := Format('%svar %s = '#13#10, [Result, XMLDocument.XMLVarName]);
      if csDesigning in ComponentState then
        Result := Format('%s<#%s %s=%s %s>;'#13#10,
          [Result, sDataPacketTag, sXMLBroker, XMLBroker.Name, sQuoteXML])
      else
        Result := Format('%s%s;'#13#10, [Result, GetXMLData(XMLBroker, XMLOptions)]);;
      Result := Format('%svar %s = new Document(%s);'#13#10,
       [Result, XMLDocument.DocumentVarName, XMLDocument.XMLVarName]);
    end;
  end;
end;

function TCustomMidasPageProducer.DeclareXMLIslands: string;
var
  I: Integer;
  XMLDocument: IXMLDocument;
  XMLBroker: TXMLBroker;
  XMLOptions: TXMLOptions;
begin
  if (not (coNoScript in ScriptManager.Options.Flags)) then
  begin
    XMLOptions := [];
    Result := #13#10;
    for I := 0 to ScriptManager.XMLDocuments.Count - 1 do
    begin
      XMLDocument := ScriptManager.XMLDocuments.Items[I];
      if XMLDocument.RowSets.Count > 0 then
      begin
        XMLBroker := XMLDocument.Component as TXMLBroker;

        Result := Format('%s<XML ID=%s>'#13#10, [Result, XMLDocument.DocumentVarName]);
        if csDesigning in ComponentState then
          Result := Format('%s<#%s %s=%s>'#13#10,
            [Result, sDataPacketTag, sXMLBroker, XMLBroker.Name])
        else
          Result := Format('%s%s', [Result, GetXMLData(XMLBroker, XMLOptions)]);
        Result := Result + #13#10'</XML>'#13#10;
      end;
    end;
  end;
end;

function TCustomMidasPageProducer.DeclareIncludes: string;
  function FormatInclude(const FileName, Path: string): string;
  begin
    Result := Format('<SCRIPT language=JavaScript type="text/javascript" SRC="%s"></SCRIPT>'#13#10,
      [Path + FileName]);
  end;
var
  Path: string;
  IncludeFile: IIncludeFile;
  I: Integer;
begin
  Result := '';
  Path := IncludePathURL;
  // Make default path refer to root.  
  if Path = '' then
    if Assigned(Dispatcher) and Assigned(Dispatcher.Request) then
      Path := PathInfoToRelativePath(Dispatcher.Request.PathInfo);
  for I := 0 to ScriptManager.IncludeFiles.Count - 1 do
  begin
    IncludeFile := ScriptManager.IncludeFiles.Items[I];
    Result := Result + FormatInclude(IncludeFile.FileName, Path);
  end;
end;

function TCustomMidasPageProducer.DeclareStyles: string;
  function FormatStyles(const S: string): string;
  begin
    if S <> '' then
      Result := Format('<STYLE TYPE="text/css">'#13#10'%0:s'#13#10'</STYLE>'#13#10,
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

function TCustomMidasPageProducer.DeclareFunctions: string;
var
  F: IFunction;
  I: Integer;
begin
  Result := '';
  for I := 0 to ScriptManager.Functions.Count - 1 do
  begin
    F := ScriptManager.Functions.Items[I];
    Result := Result + F.Body;
  end;
end;

function TCustomMidasPageProducer.DeclareWarnings(Warnings: TStrings): string;
var
  I: Integer;
begin
  Result := '';
  if Warnings.Count > 0 then
  begin
    for I := 0 to Warnings.Count - 1 do
      Result := Format('%s  <LI>%s'#13#10, [Result, Warnings[I]]);
    Result := Format('<UL>'#13#10 +
                     '%s' +
                     '</UL>'#13#10, [Result]);
    Result := Format(sWarningsBody, [Result]);
  end;
end;

function TCustomMidasPageProducer.DeclareScript(XMLIslands: Boolean): string;
var
  ScriptBlocks: IScriptBlocks;
  I: Integer;
  Vars: IVars;
begin
  Result := '';
  if (not (coNoScript in ScriptManager.Options.Flags)) then
  begin
    if not XMLIslands then
      Result := Result + DeclareXMLDocuments;
    Result := Result + DeclareRowSets;
    Result := Result + DeclareFunctions;
    ScriptBlocks := ScriptManager.ScriptBlocks;
    for I := 0 to ScriptBlocks.Count - 1 do
      Result := Result + ScriptBlocks.Items[I].Script;
    Vars := ScriptManager.Vars;
    for I := 0 to Vars.Count - 1 do
      Result := Result + Vars.Items[I].Script;
    Result :=
      Format(#13#10'<SCRIPT language=JavaScript type="text/javascript">'#13#10 +
             '%s</SCRIPT>'#13#10,
        [Result]);
  end;
end;

procedure TCustomMidasPageProducer.AddScriptComponents;
begin
  ScriptManager.GetAddElementsIntf.AddScriptComponents(WebPageItems);
  AddIncludes;
  if ScriptManager.XMLDocuments.Count > 0 then
    ScriptManager.GetAddElementsIntf.AddVar(sXMLReadyVar,
      Format('%s=true;'#13#10, [sXMLReadyVar]));
end;

procedure TCustomMidasPageProducer.AddIncludes;
var
  StdIncludes: TStdIncludes;
begin
  if ScriptManager.XMLDocuments.Count > 0 then
  begin
    StdIncludes := [jsDb, jsDisp];
    if not GetUseXMLIslands then
      StdIncludes := StdIncludes + [jsDom];
    AddStdIncludes(StdIncludes, ScriptManager.GetAddElementsIntf);
  end;
end;

function PathInfoToRelativePath(const PathInfo: string): string;
var
  P, P2: PChar;
begin
  Result := '';
  P := PChar(PathInfo);
  P2 := P;
  repeat
    P2 := StrPos(P2, '/');
    if Assigned(P2) and
      IsDelimiter('/', PathInfo, P2 - P + 1) then
    begin
      Result := Result + '../';
      Inc(P2);
    end;
  until P2 = nil;
end;

procedure AddStdIncludes(StdIncludes: TStdIncludes;
  AddIntf: IAddScriptElements);
begin
  Assert(Assigned(AddIntf), 'AddIntf not found');
  if jsDom in StdIncludes then
    AddIntf.AddIncludeFile('xmldom.js');
  if jsDb in StdIncludes then
    AddIntf.AddIncludeFile('xmldb.js');
  if jsDisp in StdIncludes then
    AddIntf.AddIncludeFile('xmldisp.js');
  if jsErrDisp in StdIncludes then
    AddIntf.AddIncludeFile('xmlerrdisp.js');
  if jsShow in StdIncludes then
    AddIntf.AddIncludeFile('xmlshow.js');
end;

procedure TCustomMidasPageProducer.GeneratePageElements;
var
  I: Integer;
  WebContent: IWebContent;
  XMLIslands: Boolean;
  HTMLBlocks: IHTMLBlocks;
begin
  AddScriptComponents;
  for I := 0 to WebPageItems.Count - 1 do
    if WebPageItems[I].GetInterface(IWebContent, WebContent) then
      PageElements.FormsContent := PageElements.FormsContent + WebContent.Content(ScriptManager.Options, nil);

  HTMLBlocks := ScriptManager.HTMLBlocks;
  for I := 0 to HTMLBlocks.Count - 1 do
    PageElements.ScriptContent := PageElements.ScriptContent + HTMLBlocks.Items[I].HTML;
  XMLIslands := GetUseXMLIslands;
  if XMLIslands then
    PageElements.ScriptContent := PageElements.ScriptContent + DeclareXMLIslands;
  PageElements.ScriptContent := PageElements.ScriptContent + DeclareScript(XMLIslands);

  if not (coNoScript in ScriptManager.Options.Flags) then
    PageElements.IncludesContent := DeclareIncludes;

  PageElements.StylesContent := DeclareStyles;

  if csDesigning in ComponentState then
    PageElements.WarningsContent := DeclareWarnings(FScriptManager.Warnings);
end;

constructor TCustomMidasPageProducer.Create(AComponent: TComponent);
begin
  inherited;
  FStyles := TStringList.Create;
  HTMLDoc.Text := GetDefaultTemplate;
  FEnableXMLIslands := True;
end;

destructor TCustomMidasPageProducer.Destroy;
begin
  inherited;
end;

function TCustomMidasPageProducer.GetScriptManager: IScriptManager;
begin
  Result := FScriptManager;
end;

function TCustomMidasPageProducer.WebContent(
  Options: TWebContentOptions; Layout: TLayout): string;
var
  M: TScriptManager;
  InStream: TStream;
  S: string;
begin
  Assert(FScriptManager = nil, 'Unexpected value');
  M := CreateScriptManager(Options) as TScriptManager;
  FScriptManager := M;
  DoBeforeGetContent;
  try
    if not Assigned(Dispatcher) or not Assigned(Dispatcher.Response) or not
      Dispatcher.Response.Sent then
    begin
      Assert(FPageElements = nil, 'Unexpected value');
      FPageElements := CreatePageElements;
      try
        GeneratePageElements;
        Result := '';
        if HTMLFile <> '' then
          InStream := TFileStream.Create(HTMLFile, fmOpenRead + fmShareDenyWrite)
        else
        begin
          S := HTMLDoc.Text;
          if Trim(S) = '' then
            S := GetDefaultTemplate;
          InStream := TStringStream.Create(S);
        end;
        if InStream <> nil then
        try
          Result := ContentFromStream(InStream);
        finally
          InStream.Free;
        end;
      finally
        FreeAndNil(FPageElements);
      end;
    end;
  finally
    DoAfterGetContent;
    FScriptManager := nil;
  end;
end;

function TCustomMidasPageProducer.GetDefaultTemplate: string;
begin
  Result := Format('<HTML>'#13#10 +
             '<HEAD>'#13#10 +
             '</HEAD>'#13#10 +
             '<BODY>'#13#10 +
             '<#%0:s><#%1:s><#%2:s><#%3:s><#%4:s>'#13#10 +
             '</BODY>'#13#10 +
             '</HTML>'#13#10, [sIncludesTag, sStylesTag,
               sWarningsTag, sFormsTag, sScriptTag]);
end;

function TCustomMidasPageProducer.Content: string;
var
  Options: TWebContentOptions;
  Owned: Boolean;
begin
  Options := GetContentOptions(Owned);
  try
    Result := WebContent(Options, nil);
  finally
    if Owned then
      Options.Free;
  end;
end;

procedure TCustomMidasPageProducer.DoAfterGetXMLData(XMLBroker: TXMLBroker; var OwnerData: OleVariant);
begin
  if Assigned(FAfterGetXMLData) and Assigned(Dispatcher) then
    FAfterGetXMLData(Self, Dispatcher.Request, XMLBroker, OwnerData);
end;

procedure TCustomMidasPageProducer.DoBeforeGetXMLData(XMLBroker: TXMLBroker; var OwnerData: OleVariant);
begin
  if Assigned(FBeforeGetXMLData) and Assigned(Dispatcher) then
    FBeforeGetXMLData(Self, Dispatcher.Request, XMLBroker, OwnerData);
end;

procedure TCustomMidasPageProducer.SetIncludePathURL(const Value: string);
var
  NewValue: string;
begin
  if Value <> '' then
  begin
    NewValue := DosPathToUnixPath(Value);
    if not IsDelimiter('/', NewValue, Length(NewValue)) then
      NewValue := NewValue + '/';
  end;
  if AnsiCompareText(FIncludePathURL, NewValue) <> 0 then
  begin
    FIncludePathURL := NewValue;
  end;
end;

function TCustomMidasPageProducer.CanAddClass(AParent: TComponent; AClass: TClass): Boolean;
begin
  Result := ImplCanAddClass(AParent, AClass);
end;

function TCustomMidasPageProducer.ImplCanAddClass(AParent: TComponent; AClass: TClass): Boolean;
begin
  Result := AClass.InheritsFrom(TWebForm) or
    AClass.InheritsFrom(TCustomLayoutGroup);
end;

procedure TCustomMidasPageProducer.SetStyles(Value: TStrings);
begin
  FStyles.Assign(Value);
  FStylesFile := '';
end;

procedure TCustomMidasPageProducer.SetStylesFile(const Value: TFileName);
begin
  if CompareText(FStylesFile, Value) <> 0 then
  begin
    FStyles.Clear;
    FStylesFile := Value;
  end;
end;

procedure TCustomMidasPageProducer.DoAfterGetContent;
begin
  if Assigned(FAfterGetContent) then
    FAfterGetContent(Self);
end;

procedure TCustomMidasPageProducer.DoBeforeGetContent;
begin
  if Assigned(FBeforeGetContent) then
    FBeforeGetContent(Self);
end;

function TCustomMidasPageProducer.GetContentOptions(
  var Owned: Boolean): TWebContentOptions;
begin
  if Assigned(ScriptManager) then
  begin
    Owned := False;
    Result := ScriptManager.Options;
  end
  else
  begin
    Owned := True;
    Result := TWebContentOptions.Create([]);
  end;
end;

{ TMidasPageElements }

function TMidasPageElements.BodyContent: string;
begin
  Result :=
      IncludesContent +
      StylesContent +
      WarningsContent +
      FormsContent +
      ScriptContent;
end;

end.

