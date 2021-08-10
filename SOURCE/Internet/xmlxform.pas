
{*******************************************************}
{                                                       }
{       Borland Delphi Visual Component Library         }
{       XML Transform Components                        }
{                                                       }
{ Copyright (c) 2000-2001 Borland Software Corporation  }
{                                                       }
{*******************************************************}

unit Xmlxform;

interface

uses

  Variants, SysUtils, Classes, Provider, DB, DBClient, DSIntf,
  xmldom, xmlutil;

type
  TranslateException = class(Exception);

{ TXMLTransform }

  TTranslateEvent = procedure(Sender: TObject; Id: string;
    SrcNode: IDOMNode; var Value: string; DestNode: IDOMNode) of object;
  TRowEvent = procedure(Sender: TObject; Id: string;
    SrcNode: IDOMNode; DestNode: IDOMNode) of object;

  TXMLTransform = class(TComponent)
  private
    FEncoding: string;
    FEncodingTrans: string;
    FDirectionToCds: Boolean;
    FVersion: string;
    FSourceXmlFile: string;
    FSourceXmlDocument: IDOMDocument;
    FSourceXml: string;
    FTransformationFile: string;
    FTransformationDocument: IDOMDocument;
    FEmptyDestinationDocument: IDOMDocument;  //Insert into this, if present
    FResultDocument: IDOMDocument;
    FResultString: string;
    FOnTranslate: TTranslateEvent;
    FBeforeEachRow: TRowEvent;
    FAfterEachRow: TRowEvent;
    FBeforeEachRowSet: TRowEvent;
    FAfterEachRowSet: TRowEvent;
  protected
    procedure Translate(const Id: string; const SrcNode: IDOMNode;
      var SrcValue: string; const DestNode: IDOMNode); dynamic;
    function DoTransform(const XMLSrc, XMLExtract, XMLOut: IDOMDocument): string;
    procedure Transform(TransNode, SrcNode, DestNode: IDOMNode;
      Count: Integer; InFromList, InDestList, InIdStrList, InValueList,
      InOptionalList, InDateFormatList, InDateFormatTypeList,
      InMapValuesList: TStringList);
    function GetData: string;
    function GetResultString: string;
  public
    function TransformXML(const SourceXml: string;
      const ATransformationFile: string = ''): string;
    property Data: string read GetData ;
    property SourceXmlDocument: IDOMDocument read FSourceXmlDocument write FSourceXmlDocument;
    property SourceXmlFile: string read FSourceXmlFile write FSourceXmlFile;
    property SourceXml: string read FSourceXml write FSourceXml;
    property TransformationDocument: IDOMDocument read FTransformationDocument write FTransformationDocument;
    property EmptyDestinationDocument: IDOMDocument read FEmptyDestinationDocument write FEmptyDestinationDocument;
    property ResultDocument: IDOMDocument read FResultDocument;
    property ResultString: string read GetResultString;
  published
    property TransformationFile: string read FTransformationFile write FTransformationFile;
    property OnTranslate: TTranslateEvent read FOnTranslate write FOnTranslate;
    property BeforeEachRow: TRowEvent read FBeforeEachRow write FBeforeEachRow;
    property AfterEachRow: TRowEvent read FAfterEachRow write FAfterEachRow;
    property BeforeEachRowSet: TRowEvent read FBeforeEachRowSet write FBeforeEachRowSet;
    property AfterEachRowSet: TRowEvent read FAfterEachRowSet write FAfterEachRowSet;
  end;

{ TXMLTransformProvider }

  { This component takes data in an arbitrary XML data file and provides it to a
    DataSnap client.  It also takes updates to the data from the DataSnap client and
    modifies the original XML data file.

    Properties:

     CacheData
        Indicates if data is cached by the provider after the GetRecords
        method is called by the client.  Caching the data will speed
        the update process, but will consume additional resources.

      XMLDataFile
        XML File containing data to be returned to the client.  This can be
        in any format that can be transformed into a DataSnap compatible format.
        Updates are written back to this file.

      TransformRead.TransformationFile
        Transform file for for converting from XMLDataFile format into a
        DataSnap format.  This file must be created using the XMLMapper program.

      TransformWrite.TransformationFile
        Transform file for for converting from a DataSnap format into the
        XMLDataFile format. This file must be created using the XMLMapper
        program.
  }

  TXMLTransformProvider = class(TCustomProvider)
  private
    FDataCache: TClientDataSet;
    FResolver: TDataSetProvider;
    FTransformRead: TXMLTransform;
    FTransformWrite: TXMLTransform;
    FCacheData: Boolean;
    function GetXMLDataFile: string;
    procedure SetXMLDataFile(const Value: string);
  protected
    function InternalApplyUpdates(const Delta: OleVariant; MaxErrors: Integer;
      out ErrorCount: Integer): OleVariant; override;
    function InternalGetRecords(Count: Integer; out RecsOut: Integer;
      Options: TGetRecordOptions; const CommandText: WideString;
      var Params: OleVariant): OleVariant; override;
  public
    constructor Create(AOwner: TComponent); override;
    destructor Destroy; override;
  published
    property TransformRead: TXMLTransform read FTransformRead ;
    property TransformWrite: TXMLTransform read FTransformWrite ;
    property XMLDataFile: string read GetXMLDataFile write SetXMLDataFile;
    property CacheData: Boolean read FCacheData write FCacheData default False;
    property BeforeApplyUpdates;
    property AfterApplyUpdates;
    property BeforeGetRecords;
    property AfterGetRecords;
    property BeforeRowRequest;
    property AfterRowRequest;
    property OnDataRequest;
 end;

{ Transform Client }

  { This component takes data returned from a DataSnap AppServer and transforms
    it into an external XML data file (GetXML method).  The format of the XML is
    determined by the TransformGetData TransformationFile.

    It also allows inserting and deleting data on the AppServer by calling the
    calling ApplyUpdates method, passing an XML file with the data to
    insert/delete, and also a reference to a file containing the
    relavant transformation info. }

  TXMLTransformClient = class(TComponent)
  private
    FDataCache: TClientDataSet;
    FSetParamsDataCache: TClientDataSet;
    FLocalAppServer: TLocalAppServer;
    FTransformGetData: TXMLTransform;
    FTransformApplyUpdates: TXMLTransform;
    FTransformSetParams: TXMLTransform;
    function GetProviderName: string;
    function GetRemoteServer: TCustomRemoteServer;
    procedure SetProviderName(const Value: string);
    procedure SetRemoteServer(const Value: TCustomRemoteServer);
  protected
    procedure SetupAppServer;
  public
    constructor Create(AOwner: TComponent); override;
    destructor Destroy; override;
    function  GetDataAsXml(const PublishTransformFile: string): string; virtual;
    function  ApplyUpdates(const UpdateXML, UpdateTransformFile: string; MaxErrors: Integer): Integer; virtual;
    procedure SetParams(const ParamsXml, ParamsTransformFile: string);
  published
    property RemoteServer: TCustomRemoteServer read GetRemoteServer write SetRemoteServer;
    property ProviderName: string read GetProviderName write SetProviderName;
    property TransformGetData: TXMLTransform read FTransformGetData ;
    property TransformApplyUpdates: TXMLTransform read FTransformApplyUpdates;
    property TransformSetParams: TXMLTransform read FTransformSetParams ;
  end;

implementation

{ Utility Functions }

procedure TransformError(const Msg: string);
begin
  raise TranslateException.Create(Msg);
end;

procedure StringToFile(const S, FileName: string);
begin
  with TStringList.Create do
  try
    Text := S;
    SaveToFile(FileName);
  finally
    Free;
  end;
end;

function GetXMLData(DataSet: TClientDataSet): string;
var
  Stream: TStringStream;
begin
  Stream := TStringStream.Create('');
  try
    DataSet.SaveToStream(Stream, dfXML);
    Result := Stream.DataString;
  finally
    Stream.Free;
  end;
end;

function CreateNestedTransform(Owner: TComponent; const Name: string): TXMLTransform;
begin
  Result := TXMLTransform.Create(Owner);
  Result.SetSubComponent(True);
  Result.Name := Name;
end;

{ TXMLTransform }

procedure TXMLTransform.Translate(const Id: string; const SrcNode: IDOMNode;
  var SrcValue: string; const DestNode: IDOMNode);
begin
  if Assigned(FOnTranslate) then
    FOnTranslate(Self, Id, SrcNode, SrcValue, DestNode);
end;

function TXMLTransform.GetData: string;
var
  FSrcDom: IDOMDocument;
  FTransDom: IDOMDocument;
begin
  if FSourceXMLFile = '' then
  begin
    if FSourceXml <> '' then
      FSrcDom := LoadDocFromString(FSourceXml)
    else if FSourceXmlDocument = nil then
      TransformError(SMissingSourceFile)
    else
      FSrcDom := FSourceXmlDocument;
  end
  else
    FSrcDom := LoadDocFromFile(FSourceXMLFile);

  if FTransformationFile = '' then
  begin
    if FTransformationDocument = nil then
      TransformError(SMissingTransform)
    else
      FTransDom := FTransformationDocument;
  end
  else
    FTransDom := LoadDocFromFile(FTransformationFile);
  Result := DoTransform(FSrcDom, FTransDom, FEmptyDestinationDocument);
end;

function TXMLTransform.GetResultString: string;
begin
  if (FResultString = '') and (FResultDocument <> nil) then
    FResultString := (FResultDocument as IDOMPersist).xml;
  Result := FResultString;
end;

function TXMLTransform.TransformXML (const SourceXML: string;
      const ATransformationFile: string = ''): string;
var
  SrcDom: IDOMDocument;
  TransDom: IDOMDocument;
begin
  Result := '';
  TransDom := nil;
  SrcDom := nil;
  if SourceXml <> '' then
    SrcDom := LoadDocFromString(SourceXML);
  if ATransformationFile <> '' then
    TransDom := LoadDocFromFile(ATransformationFile)
  else
  if FTransformationFile <> '' then
    TransDom := LoadDocFromFile(FTransformationFile)
  else
    TransformError(SMissingTransform);
  if (TransDom <> nil) and (SrcDom <> nil) then
    Result := DoTransForm(SrcDom, TransDom, FEmptyDestinationDocument);
end;

function TXMLTransform.DoTransform(const XMLSrc, XMLExtract, XMLOut: IDOMDocument): string;
var
  TransRoot: IDOMNode;
  SrcRoot, DestRoot, DestRootClone, Node, TransformNode: IDOMNode;
  I: Integer;
  cdata_skeleton: string;
  Skeleton: IDOMDocument;
  Direction: string;
  MajorVersion, MinorVersion: string;
begin
  FResultDocument := nil;
  FResultString := '';
  FEncoding := GetEncoding(XMLSrc);
  TransRoot := XMLExtract.documentElement;
  SrcRoot := XMLSrc.documentElement;
  if XMLOut <> nil then
    DestRootClone := XMLOut.documentElement
  else
  begin
    FVersion :=  GetAttribute(TransRoot, mx_Version);
    if FVersion <> '' then
    begin
      MajorVersion := Head(FVersion, '.', MinorVersion);
      if StrToInt(MajorVersion) < 1 then
        TransformError(SOldVersion);
    end;
    TransformNode := SelectNode(TransRoot, mx_Root + '\'+ mx_Transform);
    FEncodingTrans := GetAttribute(TransformNode, mx_DataEncoding);
    Direction := GetAttribute(TransformNode, mx_Direction);
    FDirectionToCds := (Direction = mx_ToCds);
    DestRoot := SelectNode(TransRoot,mx_Root+'\'+mx_Skeleton);
    if DestRoot.ChildNodes.item[0].nodeType = ELEMENT_NODE then
      DestRootClone := DestRoot.CloneNode(True)
    else if DestRoot.ChildNodes.item[0].nodeType = CDATA_SECTION_NODE then
    begin
      cdata_skeleton := DestRoot.ChildNodes.item[0].nodeValue;
      Skeleton := LoadDocFromString(cdata_skeleton);
      DestRootClone := Skeleton.documentElement;
    end;
  end;

  Node := SelectNode(TransRoot, mx_Root + '\' + mx_Transform);
  if Node <> nil then
    for I := 0 to Node.childNodes.length-1 do
      Transform(Node.childNodes.item[I], SrcRoot, DestRootClone,
      0, nil, nil, nil, nil, nil, nil, nil, nil);

  if XmlOut <> nil then
  begin
    FResultDocument := XMLOut;
    Result := (DestRootClone as IDOMNodeEx).xml;
  end
  else
  begin
    if Skeleton = nil then
      Result := (DestRootClone.childNodes.item[0] as IDOMPersist).xml
    else
    begin
      FResultDocument := Skeleton;
      Result := (Skeleton as IDOMPersist).xml;
    end;
  end;
  FResultString := Result;
end;

procedure TXMLTransform.Transform(TransNode, SrcNode, DestNode: IDOMNode;
    Count: Integer; InFromList, InDestList, InIdStrList, InValueList,
    InOptionalList, InDateFormatList, InDateFormatTypeList,
    InMapValuesList: TStringList);
var
  I, J: Integer;
  From, Dest: string;
  Value, AttrName: string;
  IdStr, RepeatName: string;
  Optional, Map_Values: string;
  DefaultValue, DateFormat, DateFormatType: string;
  More, BeforeEachRowSet: Boolean;
  RepeatDestNode, AttrNode, TmpNode: IDOMNode;
  FromList, DestList, IdStrList, ValueList, OptionalList: TStringList;
  DateFormatList, DateFormatTypeList, MapValuesList: TStringList;
begin
  if TransNode.NodeName = mx_TranslateEach then
  begin
    AttrNode := TransNode.attributes.getNamedItem(mx_FROM);
    if AttrNode <> nil then From := AttrNode.nodeValue else From := '';
    AttrNode := TransNode.attributes.getNamedItem(mx_DEST);
    if AttrNode <> nil then Dest := AttrNode.nodeValue else Dest := '';
    AttrNode := TransNode.attributes.getNamedItem(mx_ID);
    if AttrNode <> nil then IdStr := AttrNode.nodeValue else IdStr := '';
    SrcNode := SelectNode(SrcNode, From);
    if SrcNode <> nil then
    begin
      RepeatName := SrcNode.nodeName;
      DestNode := SelectCreateNode(DestNode, Dest, AttrName);
    end
    else
    begin
      RepeatName := '';
      DestNode := SelectCreateNode(DestNode, Dest, AttrName);
      if (DestNode <> nil) and (DestNode.parentNode <> nil) then
      begin
        TmpNode := DestNode;
        DestNode := DestNode.parentNode;
        DestNode.removeChild(TmpNode);
      end;
    end;
    if (SrcNode <> nil) and (DestNode <> nil) then
    begin
      More := True;
      BeforeEachRowSet := True;
      RepeatDestNode := DestNode.cloneNode(True);
    end
    else
    begin
      More := False;
      BeforeEachRowSet := False;
      RepeatDestNode := nil;
    end;
    if More and Assigned(FBeforeEachRowSet) then
      FBeforeEachRowSet(Self, IdStr, SrcNode, DestNode);

    FromList := TStringList.Create;
    DestList := TStringList.Create;
    IdStrList := TStringList.Create;
    ValueList := TStringList.Create;
    OptionalList := TStringList.Create;
    DateFormatList := TStringList.Create;
    DateFormatTypeList := TStringList.Create;
    MapValuesList := TStringList.Create;
    try
      while More do
      begin
        if Assigned(FBeforeEachRow) then
          FBeforeEachRow(Self, IdStr, SrcNode, DestNode);

        for I := 0 to TransNode.childNodes.length-1 do
          TransForm(TransNode.childNodes.item[i], SrcNode, DestNode,
             I, FromList, DestList, IdStrList, ValueList, OptionalList,
             DateFormatList, DateFormatTypeList, MapValuesList);

        if Assigned(FAfterEachRow) then
          FAfterEachRow(Self, IdStr, SrcNode, DestNode);

        while More do
        begin
          SrcNode := SrcNode.nextSibling;
          if SrcNode = nil then
            More := False
          else
          begin
            if SrcNode.nodeName = RepeatName then
            begin //found next\
              DestNode := SelectCreateSibling(DestNode, RepeatDestNode);
              if DestNode = nil then More := False;
              Break;
            end;
          end;
        end;
      end; //while More

      if BeforeEachRowSet and Assigned(FAfterEachRowSet) then
        FAfterEachRowSet(Self, IdStr, SrcNode, DestNode);
    finally
      FromList.Free;
      DestList.Free;
      IdStrList.Free;
      ValueList.Free ;
      OptionalList.Free;
      DateFormatList.Free;
      DateFormatTypeList.Free;
      MapValuesList.Free;
    end;
  end // TransNode.NodeName = mx_TranslateEach
  else if TransNode.NodeName = mx_Translate then //Field-translation
  begin
    if (InFromList = nil) or (Count >= InFromList.Count) then
    begin
      From := ''; Dest := ''; IdStr := ''; Value := ''; Optional := '';
      DateFormat := ''; DateFormatType  := ''; Map_Values := '';
      for J := 0 to TransNode.attributes.length-1 do
      begin
        TmpNode := TransNode.attributes.item[J];
        if TmpNode.NodeName = mx_FROM then
          From := TmpNode.nodeValue
        else if TmpNode.NodeName = mx_DEST then
          Dest := TmpNode.nodeValue
        else if TmpNode.NodeName = mx_VALUE then
          Value := TmpNode.nodeValue
        else if TmpNode.NodeName = mx_OPTIONAL then
          Optional := TmpNode.nodeValue
        else if TmpNode.NodeName = mx_ID then
          Idstr := TmpNode.nodeValue
        else if TmpNode.NodeName = mx_DEFAULT then
          DefaultValue := TmpNode.nodeValue
        else if (TmpNode.NodeName = mx_DATETIMEFORMAT) or
           (TmpNode.NodeName = mx_DATEFORMAT) or
           (TmpNode.NodeName = mx_TIMEFORMAT) then
        begin
          DateFormat := TmpNode.NodeValue;
          DateFormatType := TmpNode.NodeName;
        end
        else if TmpNode.NodeName = mx_MAPVALUES then
           Map_Values := TmpNode.NodeValue;
      end; // for

      if InFromList <> nil then
      begin
        InFromList.Add(From);
        InDestList.Add(Dest);
        InIdStrList.Add(IdStr);
        InValueList.Add(Value);
        InOptionalList.Add(Optional);
        InDateFormatList.Add(DateFormat);
        InDateFormatTypeList.Add(DateFormatType);
        InMapValuesList.Add(Map_Values);
      end;
    end // if (InFromList = nil) ...
    else
    begin
      From := InFromList[Count];
      Dest := InDestList[Count];
      IdStr := InIdStrList[Count];
      Value := InValueList[Count];
      Optional := InOptionalList[Count];
      DateFormat := InDateFormatList[Count];
      DateFormatType := InDateFormatTypeList[Count];
      Map_Values := InMapValuesList[Count];
    end;

    SrcNode := SelectNode(SrcNode, From);
    if SrcNode <> nil then
    begin
      if Value = '' then
      begin
        if SrcNode.nodeType = ELEMENT_NODE then
          Value := (SrcNode as IDOMNodeEx).Text
        else
          Value := SrcNode.nodeValue;
      end;
      if (IdStr <> '') and Assigned(FOnTranslate) then
        FOnTranslate(Self, IdStr, SrcNode, Value, DestNode);
    end;

    if Value = '' then
      if DefaultValue <> '' then
        Value := DefaultValue;

    if Value <> '' then
    begin
      if Map_Values <> '' then
        Value := MapValues(Map_Values, Value);
      if Value = '' then
        if DefaultValue <> '' then
          Value := DefaultValue;
      if DateFormatType <> '' then
        Value := MapDateTime(DateFormatType, DateFormat, Value, FDirectionToCds);
      if (Optional = '') or (Value <> '') then
        PutValue(DestNode, Dest, Value);
    end
    else if Optional = '' then // = '1'
      PutValue(DestNode, Dest, '');
    if (Optional <> '') and (Value = '') and
       (Dest <> '') and (Dest[1] <> '@') then
    begin
      TmpNode := SelectNode(DestNode, Dest);
      if TmpNode <> nil then
        TmpNode.parentNode.removeChild(TmpNode);
    end;
  end; // else if TransNode.NodeName = mx_Translate
end;

{ TXMLTransformProvider }

constructor TXMLTransformProvider.Create(AOwner: TComponent);
begin
  FTransformRead := CreateNestedTransform(Self, 'DataTransformRead'); // Do not localize
  FTransformWrite := CreateNestedTransform(Self, 'DataTransformWrite'); // Do not localize
  FDataCache := TClientDataSet.Create(Self);
  FResolver := TDataSetProvider.Create(Self);
  FResolver.DataSet := FDataCache;
  FResolver.ResolveToDataSet := True;
  FResolver.UpdateMode := upWhereAll; //upWhereKeyOnly;
  inherited;
end;

destructor TXMLTransformProvider.Destroy;
begin
  inherited;
end;

{ For access to protected TDataSetProvider.InternalGetRecords method }

type
  TDataSetProviderAccess = class(TDataSetProvider) end;
function TXMLTransformProvider.InternalGetRecords(Count: Integer;
  out RecsOut: Integer; Options: TGetRecordOptions;
  const CommandText: WideString; var Params: OleVariant): OleVariant;
begin
  { If we're doing partial packets, then we must cache }
  if Count <> -1 then
    CacheData := True;
  if CacheData then
  begin
    if not FDataCache.Active then
      FDataCache.Data := StringtoVariantArray(FTransformRead.Data);
    Result := TDataSetProviderAccess(FResolver).InternalGetRecords(Count, RecsOut,
      Options, CommandText, Params);
  end
  else
    Result := StringtoVariantArray(FTransformRead.Data);
end;

function TXMLTransformProvider.InternalApplyUpdates(const Delta: OleVariant;
  MaxErrors: Integer; out ErrorCount: Integer): OleVariant;
var
  S: string;
begin
  if not FCacheData or not FDataCache.Active then
    FDataCache.Data := StringToVariantArray(FTransformRead.Data);
  Result := FResolver.ApplyUpdates(Delta, MaxErrors, ErrorCount);
  FDataCache.MergeChangeLog;
  S := FTransformWrite.TransformXML(GetXMLData(FDataCache));
  if FTransformWrite.ResultDocument <> nil then
  begin
    SetEncoding(FTransformWrite.ResultDocument, FTRansformRead.FEncoding, False);
    if FTransformRead.SourceXmlFile <> '' then
      (FTransformWrite.ResultDocument as IDOMPersist).save(FTransformRead.SourceXmlFile);
  end
  else if S <> '' then
    StringToFile(S, FTransformRead.SourceXmlFile);
  if not FCacheData then
    FDataCache.Data := Null;
end;

function TXMLTransformProvider.GetXMLDataFile: string;
begin
  Result := FTransformRead.SourceXMLFile
end;

procedure TXMLTransformProvider.SetXMLDataFile(const Value: string);
begin
  FTransformRead.SourceXMLFile := Value;
end;

{ TXMLTransformClient }

constructor TXMLTransformClient.Create(AOwner: TComponent);
begin
  FTransformGetData := CreateNestedTransform(Self, 'TransformGetData'); // Do not localize
  FTransformApplyUpdates := CreateNestedTransform(Self, 'TransformApplyUpdates'); // Do not localize
  FTransformSetParams := CreateNestedTransform(Self, 'TransformSetParams'); // Do not localize
  FDataCache := TClientDataSet.Create(Self);
  inherited;
end;

destructor TXMLTransformClient.Destroy;
begin
  inherited;
  FLocalAppServer.Free;
end;

procedure TXMLTransformClient.SetupAppServer;
var
  ProvComp: TComponent;
begin
  if not Assigned(FDataCache.RemoteServer) or not FDataCache.HasAppServer then
  begin
    ProvComp := Owner.FindComponent(ProviderName);
    if Assigned(ProvComp) and (ProvComp is TCustomProvider) then
      FDataCache.AppServer := TLocalAppServer.Create(TCustomProvider(ProvComp));
  end;
end;

function TXMLTransformClient.GetDataAsXml(const PublishTransformFile: string): string;
var
  RecsOut: Integer;
  Params, OwnerData, VarPacket: OleVariant;
  TransFileName, XmlData: string;
  Options: TGetRecordOptions;
begin
  SetupAppServer;
  if FDataCache.Params.Count > 0 then
    Params := PackageParams(FDataCache.Params);
  Options :=  [grMetaData, grXML];
  VarPacket := FDataCache.AppServer.AS_GetRecords(GetProviderName, -1,
    RecsOut, Byte(Options), '', Params, OwnerData);
  XmlData := VariantArrayToString(VarPacket);
  if PublishTransformFile <> '' then
    TransFileName := PublishTransformFile else
    TransFileName := FTransformGetData.FTransformationFile;
  Result := FTransformGetData.TransformXML(XMLData, TransFileName);
  if (Result <> '') and (FTransformGetData.ResultDocument <> nil) and
     (FTransformGetData.FEncodingTrans <> '') then
    SetEncoding(FTransformGetData.ResultDocument,
      FTransformGetData.FEncodingTrans, True);
end;

function TXMLTransformClient.ApplyUpdates(const UpdateXML, UpdateTransformFile: string;
  MaxErrors: Integer): Integer;
var
  Delta: Variant;
  OwnerData: OleVariant;
  TransFileName: string;
begin
  SetupAppServer;
  if UpdateTransformFile <> '' then
    TransFileName := UpdateTransformFile else
    TransFileName := FTransformApplyUpdates.TransformationFile;
  Delta := FTransformApplyUpdates.TransformXML(UpdateXML, TransFileName);
  try
    FDataCache.AppServer.AS_ApplyUpdates(GetProviderName,
      StringToVariantArray(Delta), MaxErrors, Result, OwnerData);
  except
  end;
end;

function TXMLTransformClient.GetProviderName: string;
begin
  Result := FDataCache.ProviderName;
end;

procedure TXMLTransformClient.SetProviderName(const Value: string);
begin
  FDataCache.ProviderName := Value;
end;

function TXMLTransformClient.GetRemoteServer: TCustomRemoteServer;
begin
  Result := FDataCache.RemoteServer;
end;

procedure TXMLTransformClient.SetRemoteServer(const Value: TCustomRemoteServer);
begin
  FDataCache.RemoteServer := Value;
end;

procedure TXMLTransformClient.SetParams(const ParamsXml, ParamsTransformFile: string);
var
  I: Integer;
  Field: TField;
  Param: TParam;
  S: string;
begin
  if FSetParamsdataCache = nil then
    FSetParamsdataCache := TClientDataSet.Create(Self);
  with FSetParamsdataCache do
  begin
    Active := False;

    S := FTransformSetParams.TransformXML(ParamsXML, ParamsTransformFile);
    Data := StringToVariantArray(S);

    if (Active) and (Fields.Count > 0) then
    begin
      First;
      if not EOF then
        for I := 0 to Fields.Count -1 do
        begin
          Field := Fields[I];
          Param := FDataCache.Params.FindParam(Field.FieldName);
          if Param = nil then
            Param := FDataCache.Params.CreateParam(Field.DataType, Field.FieldName, ptInput);
          Param.Value := Field.Value;
        end;
    end;
  end;
end;
end.
