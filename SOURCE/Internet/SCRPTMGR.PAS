
{*******************************************************}
{                                                       }
{       Borland Delphi Visual Component Library         }
{                                                       }
{       Copyright (c) 1999 Inprise Corporation          }
{                                                       }
{*******************************************************}

unit ScrptMgr;

interface

uses Classes, Messages, ImgList, HTTPApp, WebComp,
  CompProd, SysUtils, Db, DbClient, PagItems, XMLBrokr, Contnrs;

type

  TScriptManager = class;

  TScriptObject = class(TInterfacedObject)
  private
    FParent: TObject;
  public
    constructor Create(AParent: TObject);
  end;

  INameContent = interface
  ['{8AFBBDE8-2A11-11D3-AAAB-00A024C11562}']
    function GetName: string;
    function GetContent: string;
    function MatchName(const Name: string): Boolean;
    property Name: string read GetName;
    property Content: string read GetContent;
  end;

  TNameContentScriptObject = class(TScriptObject, INameContent)
  private
    FName: string;
    FContent: string;
  protected
    function GetName: string;
    function GetContent: string;
    function MatchName(const AName: string): Boolean;
  public
    constructor Create(AParent: TObject; const AName, AContent: string);
    property Name: string read GetName;
    property Content: string read GetContent;
  end;

  TItemHolder = record
    FIntf: IUnknown;
    FObject: TScriptObject;
  end;

  TScriptObjectContainer = class(TScriptObject)
  private
    FItems: array of TItemHolder;
  protected
    function Add(AObject: TScriptObject): Integer;
    function GetCount: Integer;
    function GetAsObject(I: Integer): TScriptObject;
    function GetAsIntf(I: Integer): IUnknown;
  public
    destructor Destroy; override;
    function FindNameObject(const AName: string): TScriptObject;
    property Count: Integer read GetCount;
    property Objects[I: Integer]: TScriptObject read GetAsObject;
  end;

  TAddScriptElements = class;
  TXMLDocuments = class;
  TIncludeFiles = class;
  TFunctions = class;
  TScriptBlocks = class;
  THTMLBlocks = class;
  TVars = class;
  TPassList = class;
  TScriptManager = class(TInterfacedObject, IScriptManager)
  private
    FOptions: TWebContentOptions;
    FWarnings: TStrings;
    FXMLDocumentsIntf: IXMLDocuments;
    FXMLDocuments: TXMLDocuments;
    FIncludeFiles: TIncludeFiles;
    FIncludeFilesIntf: IIncludeFiles;
    FFunctions: TFunctions;
    FFunctionsIntf: IFunctions;
    FScriptBlocks: TScriptBlocks;
    FScriptBlocksIntf: IScriptBlocks;
    FVars: TVars;
    FVarsIntf: IVars;
    FHTMLBlocks: THTMLBlocks;
    FHTMLBlocksIntf: IHTMLBlocks;
    FPassList: TPassList;
    FAddElements: TAddScriptElements;
    FAddElementsIntf: IAddScriptElements;
    procedure AddScriptComponentsInternal(List: TObject);
  protected
    { IScriptManager }
    function GetXMLDocuments: IXMLDocuments;
    function GetIncludeFiles: IIncludeFiles;
    function GetHTMLBlocks: IHTMLBlocks;
    function GetVars: IVars;
    function GetScriptBlocks: IScriptBlocks;
    procedure AddError(const S: string);
    function GetFunctions: IFunctions;
    function GetWarnings: TStrings;
    function GetOptions: TWebContentOptions;
    function GetAddElementsIntf: IAddScriptElements;
  public
    constructor Create(Options: TWebContentOptions);
    destructor Destroy; override;
    procedure AddScriptComponents(List: TObject);
    property IncludeFiles: IIncludeFiles read FIncludeFilesIntf;
    property ScriptBlocks: IScriptBlocks read FScriptBlocksIntf;
    property Vars: IVars read FVarsIntf;
    property HTMLBlocks: IHTMLBlocks read FHTMLBlocksIntf;
    property PassList: TPassList read FPassList;
    property Options: TWebContentOptions read GetOptions;
    property AddElementsIntf: IAddScriptElements read GetAddElementsIntf;
  end;

  TIncludeFile = class;
  TIncludeFiles = class(TScriptObjectContainer, IIncludeFiles)
  private
    function GetObject(I: Integer): TIncludeFile;
  protected
    function GetItem(I: Integer): IIncludeFile;
  public
    function AddFileName(const FileName: string): TIncludeFile;
    function FindFileName(const FileName: string): TIncludeFile;
    property Objects[I: Integer]: TIncludeFile read GetObject;
    property Items[I: Integer]: IIncludeFile read GetItem;
  end;

  TIncludeFile = class(TScriptObject, IIncludeFile)
  private
    FFileName: string;
  protected
    function GetFileName: string;
    property FileName: string read GetFileName;
  end;

  TFunction = class;
  TFunctions = class(TScriptObjectContainer, IFunctions)
  private
    function GetObject(I: Integer): TFunction;
  protected
    function GetItem(I: Integer): IFunction;
  public
    function AddFunction(const Name, Body: string): TFunction;
    function FindFunctionName(const Name: string): TFunction;
    property Objects[I: Integer]: TFunction read GetObject;
    property Items[I: Integer]: IFunction read GetItem;
  end;

  TFunction = class(TNameContentScriptObject, IFunction)
  protected
    function GetFunctionName: string;
    function GetBody: string;
    property FunctionName: string read GetFunctionName;
    property Body: string read GetBody;
  end;

  TVar = class;
  TVars = class(TScriptObjectContainer, IVars)
  private
    function GetObject(I: Integer): TVar;
  protected
    function GetItem(I: Integer): IVar;
  public
    function AddVar(const Name, Script: string): TVar;
    function FindVarName(const Name: string): TVar;
    property Objects[I: Integer]: TVar read GetObject;
    property Items[I: Integer]: IVar read GetItem;
  end;

  TVar = class(TNameContentScriptObject, IVar)
  protected
    function GetVarName: string;
    function GetScript: string;
    property VarName: string read GetVarName;
    property Script: string read GetScript;
  end;

  TScriptBlock = class;
  TScriptBlocks = class(TScriptObjectContainer, IScriptBlocks)
  private
    function GetObject(I: Integer): TScriptBlock;
  protected
    function GetItem(I: Integer): IScriptBlock;
  public
    function AddBlock(const Name, Script: string): TScriptBlock;
    function FindBlockName(const Name: string): TScriptBlock;
    property Objects[I: Integer]: TScriptBlock read GetObject;
    property Items[I: Integer]: IScriptBlock read GetItem;
  end;

  TScriptBlock = class(TNameContentScriptObject, IScriptBlock)
  protected
    function GetBlockName: string;
    function GetScript: string;
    property BlockName: string read GetBlockName;
    property Script: string read GetScript;
  end;

  THTMLBlock = class;
  THTMLBlocks = class(TScriptObjectContainer, IHTMLBlocks)
  private
    function GetObject(I: Integer): THTMLBlock;
  protected
    function GetItem(I: Integer): IHTMLBlock;
  public
    function AddBlock(const Name, HTML: string): THTMLBlock;
    function FindBlockName(const Name: string): THTMLBlock;
    property Objects[I: Integer]: THTMLBlock read GetObject;
    property Items[I: Integer]: IHTMLBlock read GetItem;
  end;

  THTMLBlock = class(TNameContentScriptObject, IHTMLBlock)
  protected
    function GetBlockName: string;
    function GetHTML: string;
    property BlockName: string read GetBlockName;
    property HTML: string read GetHTML;
  end;

  TXMLDocument = class;
  TXMLDocuments = class(TScriptObjectContainer, IXMLDocuments)
  private
    function GetObject(I: Integer): TXMLDocument;
  protected
    function GetItem(I: Integer): IXMLDocument;
  public
    function AddXMLBroker(XMLBroker: TXMLBroker): TXMLDocument;
    function FindXMLBroker(XMLBroker: TXMLBroker): TXMLDocument;
    property Objects[I: Integer]: TXMLDocument read GetObject;
    property Items[I: Integer]: IXMLDocument read GetItem;
  end;

  TXMLRowSets = class;
  TXMLDocument = class(TScriptObject, IXMLDocument)
  private
    FXMLRowSets: TXMLRowSets;
    FXMLRowSetsIntf: IXMLRowSets;
    FXMLBroker: TXMLBroker;
  protected
    function GetRowSets: IXMLRowSets;
    function GetComponent: TComponent;
    function GetDocumentVarName: string;
    function GetXMLVarName: string;

    function GetXMLBroker: TXMLBroker;
    property XMLBroker: TXMLBroker read GetXMLBroker;
  public
    constructor Create(AXMLDocuments: TXMLDocuments);
    destructor Destroy; override;
  end;

  TXMLRowSet = class;
  TXMLRowSets = class(TScriptObjectContainer, IXMLRowSets)
  private
    FXMLDocument: TXMLDocument;
  protected
    function FindPath(Path: TStrings): TXMLRowSet;
    function AddPath(Path: TStrings): TXMLRowSet;
    function GetItem(I: Integer): IXMLRowSet;

    function GetObject(I: Integer): TXMLRowSet;
    property Objects[I: Integer]: TXMLRowSet read GetObject;
  public
    constructor Create(AXMLDocument: TXMLDocument);
    destructor Destroy; override;
  end;

  TXMLRowSet = class(TScriptObject, IXMLRowSet)
  private
    FPath: TStrings;
    FXMLRowSets: TXMLRowSets;
  protected
    function GetPath: TStrings;
    function GetRowSetVarName: string;
    function GetMasterRowSetVarName: string;
    function GetMasterDataSetFieldName: string;
  public
    constructor Create(AXMLRowSets: TXMLRowSets);
    destructor Destroy; override;
  end;

  TPass = class;
  TPassList = class(TObjectList)
  protected
    function GetItem(I: Integer): TPass;
  public
    procedure Add(Event: TAddScriptElementsEvent; Data: Pointer);
    property Items[Index: Integer]: TPass read GetItem;
  end;

  TPass = class(TObject)
  private
    Event: TAddScriptElementsEvent;
    Data: Pointer;
  public
    constructor Create(AEvent: TAddScriptElementsEvent; AData: Pointer);
  end;

  TAddScriptElements = class(TInterfacedObject, IAddScriptElements)
  private
    FScriptManager: TScriptManager;
    FEmptyPath: TStrings;
  protected
    function AddIncludeFile(FileName: string): Boolean;
    function AddRowSet(XMLBroker: TComponent; Path: TStrings): Boolean;
    function AddHTMLBlock(Name: string; HTML: string): Boolean;
    function AddScriptBlock(Name: string; Script: string): Boolean;
    function AddFunction(Name: string; Body: string): Boolean;
    function AddVar(Name: string; Script: string): Boolean;
    procedure AddError(Text: string);
    procedure AddPass(Event: TAddScriptElementsEvent; Data: Pointer);
    procedure AddScriptComponents(List: TObject);
    function GetScriptManager: IScriptManager;
  public
    constructor Create(AScriptManager: TScriptManager);
    destructor Destroy; override;
  end;

implementation

uses WbmConst;


{ TScriptManager }

constructor TScriptManager.Create(Options: TWebContentOptions);
begin
  inherited Create;
  FOptions := Options;
  FXMLDocuments := TXMLDocuments.Create(Self);
  FXMLDocumentsIntf := FXMLDocuments;
  FIncludeFiles := TIncludeFiles.Create(Self);
  FIncludeFilesIntf := FIncludeFiles;
  FScriptBlocks := TScriptBlocks.Create(Self);
  FScriptBlocksIntf := FScriptBlocks;
  FVars := TVars.Create(Self);
  FVarsIntf := FVars;
  FHTMLBlocks := THTMLBlocks.Create(Self);
  FHTMLBlocksIntf := FHTMLBlocks;
  FFunctions := TFunctions.Create(Self);
  FFunctionsIntf := FFunctions;
  FWarnings := TStringList.Create;
  FPassList := TPassList.Create;
  FAddElements := TAddScriptElements.Create(Self);
  FAddElementsIntf := FAddElements;
end;

procedure TScriptManager.AddScriptComponentsInternal(List: TObject);
var
  Intf: IWebComponentContainer;
  I: Integer;
  ScriptComponent: IScriptComponent;
  SubList: TObject;
  Component: TComponent;
begin
  if List.GetInterface(IWebComponentContainer, Intf) then
    for I := 0 to Intf.ComponentCount - 1 do
    begin
      try
        Component := Intf.Components[I];
        if Component.GetInterface(IScriptComponent, ScriptComponent) then
        begin
          ScriptComponent.AddElements(AddElementsIntf);
          SubList := ScriptComponent.SubComponents;
          if Assigned(SubList) then
            AddScriptComponentsInternal(SubList);
        end;
      except
        on e: Exception do
          AddError(e.Message);
      end;
    end;
end;

procedure TScriptManager.AddScriptComponents(List: TObject);
begin
  Assert(Assigned(AddElementsIntf), 'AddElementsIntf = nil');
  AddScriptComponentsInternal(List);

  while PassList.Count > 0 do
  begin
    with PassList.Items[0] do
      Event(Data, AddElementsIntf);
    PassList.Delete(0);
  end;
end;

procedure TScriptManager.AddError(const S: string);
begin
  if FWarnings.IndexOf(S) = -1 then
    FWarnings.Add(S);
end;

function TScriptManager.GetXMLDocuments: IXMLDocuments;
begin
  Result := FXMLDocumentsIntf;
end;

destructor TScriptManager.Destroy;
begin
  inherited;
  FWarnings.Free;
  FPassList.Free;
end;

function TScriptManager.GetIncludeFiles: IIncludeFiles;
begin
  Result := FIncludeFilesIntf;
end;

function TScriptManager.GetFunctions: IFunctions;
begin
  Result := FFunctionsIntf;
end;

function TScriptManager.GetHTMLBlocks: IHTMLBlocks;
begin
  Result := FHTMLBlocksIntf;
end;

function TScriptManager.GetVars: IVars;
begin
  Result := FVarsIntf;
end;

function TScriptManager.GetWarnings: TStrings;
begin
  Result := FWarnings;
end;

function TScriptManager.GetScriptBlocks: IScriptBlocks;
begin
  Result := FScriptBlocksIntf;
end;

function TScriptManager.GetOptions: TWebContentOptions;
begin
  Result := FOptions;
end;

function TScriptManager.GetAddElementsIntf: IAddScriptElements;
begin
  Result := FAddElementsIntf;
end;

{ TScriptObjectContainer }

function TScriptObjectContainer.Add(
  AObject: TScriptObject): Integer;
begin
  Result := Length(FItems);
  SetLength(FItems, Result+1);
  FItems[Result].FObject := AObject;
  FItems[Result].FIntf := AObject;
end;

function TScriptObjectContainer.GetCount: Integer;
begin
  Result := Length(FItems);
end;

function TScriptObjectContainer.GetAsIntf(I: Integer): IUnknown;
begin
  Result := FItems[I].FIntf;
end;

function TScriptObjectContainer.GetAsObject(I: Integer): TScriptObject;
begin
  Result := FItems[I].FObject;
end;

destructor TScriptObjectContainer.Destroy;
begin
  inherited Destroy;
end;

function TScriptObjectContainer.FindNameObject(const AName: string): TScriptObject;
var
  Intf: INameContent;
  I: Integer;
begin
  for I := 0 to Count - 1 do
  begin
    Result := Objects[I];
    if Result.GetInterface(INameContent, Intf) then
      if Intf.MatchName(AName) then
        Exit;
  end;
  Result := nil;
end;

{ TXMLDocuments }

function TXMLDocuments.AddXMLBroker(
  XMLBroker: TXMLBroker): TXMLDocument;
begin
  Result := TXMLDocument.Create(Self);
  Result.FXMLBroker := XMLBroker;
  inherited Add(Result);
end;

function TXMLDocuments.FindXMLBroker(
  XMLBroker: TXMLBroker): TXMLDocument;
var
  I: Integer;
begin
  for I := 0 to Count - 1 do
  begin
    Result := Objects[I];
    if Result.FXMLBroker = XMLBroker then
      Exit;
  end;
  Result := nil;
end;

function TXMLDocuments.GetItem(I: Integer): IXMLDocument;
begin
  Result := inherited GetAsIntf(I) as IXMLDocument
end;

function TXMLDocuments.GetObject(I: Integer): TXMLDocument;
begin
  Result := inherited GetAsObject(I) as TXMLDocument;
end;

{ TXMLRowSets }

function TXMLRowSets.AddPath(Path: TStrings): TXMLRowSet;
begin
  Result := TXMLRowSet.Create(Self);
  Result.FPath.Assign(Path);
  inherited Add(Result);
end;

constructor TXMLRowSets.Create(AXMLDocument: TXMLDocument);
begin
  inherited Create(AXMLDocument);
  FXMLDocument := AXMLDocument;
end;

destructor TXMLRowSets.Destroy;
begin
  inherited Destroy;
end;

function TXMLRowSets.FindPath(Path: TStrings): TXMLRowSet;
  function ComparePath(APath1, APath2: TStrings): Boolean;
  var
    I: Integer;
  begin
    Result := False;
    if APath1.Count = APath2.Count then
    begin
      for I := 0 to APath1.Count - 1 do
      begin
        if CompareText(APath1[I], APath2[I]) <> 0 then
          Exit;
      end;
      Result := True;
    end;
  end;
var
  I: Integer;
begin
  for I := 0 to Count - 1 do
  begin
    Result := Objects[I];
    if ComparePath(Result.FPath, Path) then
      Exit;
  end;
  Result := nil;
end;

function TXMLRowSets.GetItem(I: Integer): IXMLRowSet;
begin
  Result := inherited GetAsIntf(I) as IXMLRowSet;

end;

function TXMLRowSets.GetObject(I: Integer): TXMLRowSet;
begin
  Result := inherited GetAsObject(I) as TXMLRowSet;

end;

{ TXMLRowSet }

constructor TXMLRowSet.Create(AXMLRowSets: TXMLRowSets);
begin
  inherited Create(AXMLRowSets);
  FXMLRowSets := AXMLRowSets;
  FPath := TStringList.Create;
end;

destructor TXMLRowSet.Destroy;
begin
  FPath.Free;
  inherited;
end;

function TXMLRowSet.GetMasterDataSetFieldName: string;
begin
  if FPath.Count > 0 then
    Result := Format('"%s"', [FPath[FPath.Count-1]])
  else
    Result := 'null';
end;

function TXMLRowSet.GetMasterRowSetVarName: string;
begin
  if FPath.Count > 0 then
    Result := FXMLRowSets.FXMLDocument.FXMLBroker.MasterRowSetVarName(FPath)
  else
    Result := 'null';
end;

function TXMLRowSet.GetPath: TStrings;
begin
  Result := FPath;
end;

function TXMLRowSet.GetRowSetVarName: string;
begin
  Result := FXMLRowSets.FXMLDocument.FXMLBroker.RowSetVarName(FPath)
end;

{ TXMLDocument }

constructor TXMLDocument.Create(AXMLDocuments: TXMLDocuments);
begin
  inherited Create(AXMLDocuments);
  FXMLRowSets := TXMLRowSets.Create(Self);
  FXMLRowSetsIntf := FXMLRowSets;
end;

destructor TXMLDocument.Destroy;
begin
  inherited;
end;

function TXMLDocument.GetComponent: TComponent;
begin
  Result := FXMLBroker;
end;

function TXMLDocument.GetDocumentVarName: string;
begin
  Result := Format(ScriptDocumentVarName, [FXMLBroker.Name])
end;

function TXMLDocument.GetRowSets: IXMLRowSets;
begin
  Result := FXMLRowSetsIntf;
end;

function TXMLDocument.GetXMLBroker: TXMLBroker;
begin
  Result := FXMLBroker;
end;

function TXMLDocument.GetXMLVarName: string;
begin
  Result := Format(ScriptXMLVarName, [FXMLBroker.Name]);
end;

{ TScriptObject }

constructor TScriptObject.Create(AParent: TObject);
begin
  inherited Create;
  FParent := AParent;
end;

{ TScriptComponentElements }

function TAddScriptElements.AddScriptBlock(Name: string; Script: string): Boolean;
begin
  Result := (Name = '') or (FScriptManager.FScriptBlocks.FindBlockName(Name) = nil);
  if Result then
    FScriptManager.FScriptBlocks.AddBlock(Name, Script);
end;

function TAddScriptElements.AddHTMLBlock(Name: string; HTML: string): Boolean;
begin
  Result := (Name = '') or (FScriptManager.FHTMLBlocks.FindBlockName(Name) = nil);
  if Result then
    FScriptManager.FHTMLBlocks.AddBlock(Name, HTML);
end;

function TAddScriptElements.AddVar(Name: string; Script: string): Boolean;
begin
  Result := FScriptManager.FVars.FindVarName(Name) = nil;
  if Result then
    FScriptManager.FVars.AddVar(Name, Script);
end;

function TAddScriptElements.AddRowSet(XMLBroker: TComponent;
  Path: TStrings): Boolean;
var
  XMLDocument: TXMLDocument;
  TempPath: TStrings;
begin
  XMLDocument := FScriptManager.FXMLDocuments.FindXMLBroker(XMLBroker as TXMLBroker);
  if not Assigned(XMLDocument) then
    XMLDocument := FScriptManager.FXMLDocuments.AddXMLBroker(TXMLBroker(XMLBroker));
  if Path = nil then
    Path := FEmptyPath;
  Result := XMLDocument.FXMLRowSets.FindPath(Path) = nil;
  if Result then
  begin
    // Define a complete rowset path
    if Path.Count >= 1 then
    begin
      TempPath := TStringList.Create;
      try
        while TempPath.Count < Path.Count do
        begin
          if XMLDocument.FXMLRowSets.FindPath(TempPath) = nil then
             XMLDocument.FXMLRowSets.AddPath(TempPath);
          TempPath.Add(Path[TempPath.Count]);
        end;
      finally
        TempPath.Free;
      end;
    end;
    XMLDocument.FXMLRowSets.AddPath(Path);
  end;
end;

function TAddScriptElements.AddFunction(Name, Body: string): Boolean;
begin
  Result := FScriptManager.FFunctions.FindFunctionName(Name) = nil;
  if Result then
    FScriptManager.FFunctions.AddFunction(Name, Body);
end;

function TAddScriptElements.AddIncludeFile(FileName: string): Boolean;
begin
  Result := FScriptManager.FIncludeFiles.FindFileName(FileName) = nil;
  if Result then
    FScriptManager.FIncludeFiles.AddFileName(FileName);
end;

constructor TAddScriptElements.Create(AScriptManager: TScriptManager);
begin
  FScriptManager := AScriptManager;
  FEmptyPath := TStringList.Create;
end;

destructor TAddScriptElements.Destroy;
begin
  inherited;
  FEmptyPath.Free;
end;

procedure TAddScriptElements.AddError(Text: string);
begin
  FScriptManager.AddError(Text);
end;

procedure TAddScriptElements.AddPass(Event: TAddScriptElementsEvent;
  Data: Pointer);
begin
  FScriptManager.FPassList.Add(Event, Data);
end;

function TAddScriptElements.GetScriptManager: IScriptManager;
begin
  FScriptManager.GetInterface(IScriptManager, Result);
end;

{ TIncludeFiles }

function TIncludeFiles.AddFileName(const FileName: string): TIncludeFile;
begin
  Result := TIncludeFile.Create(Self);
  Result.FFileName := FileName;
  inherited Add(Result);
end;

function TIncludeFiles.FindFileName(const FileName: string): TIncludeFile;
var
  I: Integer;
begin
  for I := 0 to Count - 1 do
  begin
    Result := Objects[I];
    if CompareText(FileName,Result.FileName) = 0 then
      Exit;
  end;
  Result := nil;
end;

function TIncludeFiles.GetItem(I: Integer): IIncludeFile;
begin
  Result := inherited GetAsIntf(I) as IIncludeFile;
end;

function TIncludeFiles.GetObject(I: Integer): TIncludeFile;
begin
  Result := inherited GetAsObject(I) as TIncludeFile;
end;

{ TIncludeFile }

function TIncludeFile.GetFileName: string;
begin
  Result := FFileName;
end;

{ TFunctions }

function TFunctions.AddFunction(const Name,
  Body: string): TFunction;
begin
  Result := TFunction.Create(Self, Name, Body);
  inherited Add(Result);
end;

function TFunctions.FindFunctionName(
  const Name: string): TFunction;
begin
  Result := TFunction(FindNameObject(Name));
end;

function TFunctions.GetItem(I: Integer): IFunction;
begin
  Result := inherited GetAsIntf(I) as IFunction;
end;

function TFunctions.GetObject(I: Integer): TFunction;
begin
  Result := inherited GetAsObject(I) as TFunction;
end;

{ TFunction }

function TFunction.GetBody: string;
begin
  Result := Content;
end;

function TFunction.GetFunctionName: string;
begin
  Result := Name;
end;

{ THTMLBlocks }

function THTMLBlocks.AddBlock(const Name,
  HTML: string): THTMLBlock;
begin
  Result := THTMLBlock.Create(Self, Name, HTML);
  inherited Add(Result);
end;

function THTMLBlocks.FindBlockName(
  const Name: string): THTMLBlock;
begin
  Result := THTMLBlock(FindNameObject(Name));
end;

function THTMLBlocks.GetItem(I: Integer): IHTMLBlock;
begin
  Result := inherited GetAsIntf(I) as IHTMLBlock;
end;

function THTMLBlocks.GetObject(I: Integer): THTMLBlock;
begin
  Result := inherited GetAsObject(I) as THTMLBlock;
end;

{ THTMLBlock }

function THTMLBlock.GetHTML: string;
begin
  Result := Content;
end;

function THTMLBlock.GetBlockName: string;
begin
  Result := Name;
end;

{ TScriptBlocks }

function TScriptBlocks.AddBlock(const Name,
  Script: string): TScriptBlock;
begin
  Result := TScriptBlock.Create(Self, Name, Script);
  inherited Add(Result);
end;

function TScriptBlocks.FindBlockName(
  const Name: string): TScriptBlock;
begin
  Result := TScriptBlock(FindNameObject(Name));
end;

function TScriptBlocks.GetItem(I: Integer): IScriptBlock;
begin
  Result := inherited GetAsIntf(I) as IScriptBlock;
end;

function TScriptBlocks.GetObject(I: Integer): TScriptBlock;
begin
  Result := inherited GetAsObject(I) as TScriptBlock;
end;

{ TScriptBlock }

function TScriptBlock.GetScript: string;
begin
  Result := Content;
end;

function TScriptBlock.GetBlockName: string;
begin
  Result := Name;
end;

{ TVars }

function TVars.AddVar(const Name,
  Script: string): TVar;
begin
  Result := TVar.Create(Self, Name, Script);
  inherited Add(Result);
end;

function TVars.FindVarName(
  const Name: string): TVar;
begin
  Result := TVar(FindNameObject(Name));
end;

function TVars.GetItem(I: Integer): IVar;
begin
  Result := inherited GetAsIntf(I) as IVar;
end;

function TVars.GetObject(I: Integer): TVar;
begin
  Result := inherited GetAsObject(I) as TVar;
end;

{ TVar }

function TVar.GetScript: string;
begin
  Result := Content;
end;

function TVar.GetVarName: string;
begin
  Result := Name;
end;

{ TPassList }

procedure TPassList.Add(Event: TAddScriptElementsEvent; Data: Pointer);
begin
  inherited Add(TPass.Create(Event, Data));
end;

function TPassList.GetItem(I: Integer): TPass;
begin
  Result := inherited Items[I] as TPass;
end;

{ TPass }

constructor TPass.Create(AEvent: TAddScriptElementsEvent; AData: Pointer);
begin
  Event := AEvent;
  Data := AData;
end;


{ TNameContentScriptObject }

constructor TNameContentScriptObject.Create(AParent: TObject; const AName,
  AContent: string);
begin
  inherited Create(AParent);
  FName := AName;
  FContent := AContent;
end;

function TNameContentScriptObject.GetContent: string;
begin
  Result := FContent;
end;

function TNameContentScriptObject.GetName: string;
begin
  Result := FName;
end;

function TNameContentScriptObject.MatchName(const AName: string): Boolean;
begin
  Result := AName = Name;
end;

procedure TAddScriptElements.AddScriptComponents(List: TObject);
begin
  FScriptManager.AddScriptComponents(List);
end;

end.

