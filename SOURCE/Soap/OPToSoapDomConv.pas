{*******************************************************}
{                                                       }
{ Borland Delphi Visual Component Library               }
{                 SOAP Support                          }
{                                                       }
{ Copyright (c) 2001 Borland Software Corporation       }
{                                                       }
{*******************************************************}

{ Converts a SOAP RPC request to/from an internal Delphi format using a DOM }

{$IFDEF MSWINDOWS}
{$DEFINE MSXMLDOM}
{$ENDIF}
{$IFDEF LINUX}
{$DEFINE OPENDOM}
{$ENDIF}

unit OPToSOAPDomConv;

interface

uses SysUtils, Variants, TypInfo, Classes, xmldom, XMLDoc, IntfInfo, InvokeRegistry,
     XMLIntf, OPConvert, WSDLNode, SOAPEnv, SOAPDomConv, Types;

const
  SVarArrayType = 'VarArrayType';     { do not localize }

type

  ESOAPDomConvertError = class(Exception);

  TSOAPArrayElemDesc = record
    MultiDim: Boolean;
    Dims: TIntegerDynArray;
  end;
  TSOAPArrayDesc = array of TSOAPArrayElemDesc;

  TMultiRefNodeMapElem = record
    Instance: Pointer;
    ID: string;
  end;
  TMultiRefNodeMap = array of TMultiRefNodeMapElem;

  TXMLNodeArray  = array of IXMLNode;
  TMultiRefNodeElem = record
    Node: IXMLNode;
    MultiRefChildren: TXMLNodeArray;
  end;
  TMultiRefNodes = array of TMultiRefNodeElem;

  ConvNodeState = (nsClientSend, nsServerReceive, nsServerSend, nsClientReceive);

  TSOAPDomConv = class(TSOAPDOMProcessor)
  private
    FIDs: Integer;
    RefMap: TMultiRefNodeMap;
    MultiRefNodes: TMultiRefNodes;
    FOptions: TSOAPConvertOptions;
    ObjsWriting: array of TObject;
  protected
    function NodeIsNULL(Node: IXMLNode): Boolean;
    function ChildNodesAreNull(Node: IXMLNode): Boolean;
    function CreateNULLNode(RootNode, ParentNode: IXMLNode; Name: InvString; UseParentNode: Boolean = False): IXMLNode;
    function GetNewID: string;
    function FindPrefixForURI(RootNode, Node: IXMLNode; URI: InvString; DeclIfNone: Boolean = False): InvString;
    function AddNamespaceDecl(Node: IXMLNode; URI: InvString): InvString;
    procedure SetAttributeNS(RootNode, Node: IXMLNode; Attr: InvString; NS: InvString; Value: InvString);
    function GetElementType(Node: IXMLNode; var TypeURI, TypeName: InvString): Boolean;
    function CreateScalarNodeXS(RootNode, ParentNode: IXMLNode;  NodeName, URI, TypeName: WideString; Value: WideString; GenPre: Boolean = False): IXMLNode;
    function GetTypeBySchemaNS(Node: IXMLNode; URI: InvString): Variant;
    function CreateTypedNode(RootNode, ParentNode: IXMLNode; NodeName, URI, TypeName: WideString; GenPre: Boolean = False): IXMLNode;
    procedure SetNodeType(RootNode, InstNode: IXMLNode; const ElemURI, TypeName: InvString);
    function GetNodeAsText(Node: IXMLNode): InvString;
    function GetDataNode(RootNode, Node: IXMLNode; var ID: InvString): IXMLNode;
    procedure CheckEncodingStyle(Node: IXMLNode);
    { Methods to handle mutli-referenced nodes }
    procedure AddMultiRefNode(ID: string; Instance: Pointer);
    function FindMultiRefNodeByInstance(Instance: Pointer): string;
    function FindMultiRefNodeByID(ID: string): Pointer;
    function  CreateMultiRefNode(RootNode: IXMLNode; Name, ID: InvString): IXMLNode;
    procedure FinalizeMultiRefNodes;
    function FindNodeByHREF(RootNode: IXMLNode; HREF: InvString): IXMLNode;
    procedure AddObjectAsWriting(Instance: TObject);
    procedure RemoveObjectAsWriting(Instance: TObject);
    function IsObjectWriting(Instance: TObject): Boolean;
    procedure ResetMultiRef;
    { Methods to handle Variants }
    procedure ConvertVariantToSoap(RootNode, Node: IXMLNode;
          Name: InvString; Info: PTypeInfo; P: PVarData; NumIndirect: Integer; V: Variant; UseVariant: Boolean);
    procedure ConvertSoapToVariant(Node: IXMLNode; InvData: Pointer);
    function  IsNodeAVarArray(const Node: IXMLNode; var VT: TVarType): Boolean;
    procedure WriteVarArray(RootNode, Node: IXMLNode; Name: InvString; V: Variant);
    procedure WriteVariant(RootNode, Node: IXMLNode; Name: InvString; V: Variant);
    procedure ReadVariant(Node: IXMLNode; P: Pointer);
    function ReadVarArrayDim(Node: IXMLNode; IsVarVArray: Boolean = False; VT: TVarType = 0): Variant;
    procedure WriteVarArrayAsB64(RootNode, Node: IXMLNode; Name: InvString; V: Variant);
    { Methods to handle native delphi array types }
    function MakeArrayNode(RootNode, Node: IXMLNode;  Name, URI,  TypeName: InvString;
            Indices: array of Integer): IXMLNode;
    procedure ConvertNativeArrayToSoap(RootNode, Node: IXMLNode;
      Name: InvString; Info: PTypeInfo; P: Pointer; NumIndirect: Integer; InlineElements: Boolean = False);
    procedure  WriteNonRectDynArray(RootNode, Node: IXMLNode; Name: InvString; Info: PTypeInfo; URI, TypeName: InvString; P: Pointer; Dims: Integer);
    function WriteNonRectDynArrayElem(RootNode, Node: IXMLNode;  Info: PTypeInfo; URI, TypeName: InvString; P: Pointer; Dim: Integer): Integer;
    function ConvertSoapToNativeArray(DataP: Pointer;  TypeInfo: PTypeInfo;
      RootNode, Node: IXMLNode): Pointer;
    function  ConvertSoapToNativeArrayElem(ArrayInfo, ElemInfo: PTypeInfo;
       RootNode, Node: IXMLNode; ArrayDesc: TSOAPArrayDesc; Dims, CurDim: Integer; DataP: Pointer): Pointer;
    procedure WriteRectDynArrayElem(RootNode, Node: IXMLNode; Info: PTypeInfo; Size, Dim: Integer; P: Pointer; TypeName: InvString);
    procedure  WriteRectDynArray(RootNode, Node: IXMLNode; Info: PTypeInfo; Dims: Integer; P: Pointer; TypeName: InvString);
    procedure ReadRectDynArray(RootNode, Node: IXMLNode; Info: PTypeInfo; Dims: Integer; P: Pointer; CurElem: Integer);
    procedure ReadRectDynArrayElem(RootNode, Node: IXMLNode; Info: PTypeInfo; Size, Dim: Integer; P: Pointer; var CurElem: Integer);
    procedure ReadRow(RootNode, Node: IXMLNode; var CurElem: Integer; Size: Integer; P: Pointer; Info: PTypeInfo);
    { Enums }
    function ConvertEnumToSoap(Info: PTypeInfo; P: Pointer; NumIndirect: Integer): InvString;
    function ConvertSoapToEnum(Info: PTypeInfo; S: InvString; IsNull: Boolean): Integer;

    { Methods that handle TObjects with RTTI }
    function MultiRefObject(Cls: TClass): Boolean;
    procedure  ConvertObjectToSOAP(Name: InvString; ObjP: Pointer; RootNode, Node: IXMLNOde; NumIndirect: Integer);
    function ConvertSOAPToObject(RootNode, Node: IXMLNode;
       AClass: TClass; URI, TypeName: WideString; ObjP: Pointer; NumIndirect: Integer): TObject;
    function CreateObjectNode(Instance: TObject; RootNode, Node: IXMLNode; Name, URI: InvString; UsePrefix: Boolean = True): InvString;
    procedure LoadObject(Instance: TObject; RootNode, Node: IXMLNode);
    procedure SetObjectPropFromText(Instance: TObject; PropInfo: PPropInfo; SoapData: WideString);
    function GetObjectPropAsText(Instance: TObject; PropInfo: PPropInfo): WideString;

    function GetOptions: TSOAPConvertOptions;
    procedure SetOptions(Value: TSOAPConvertOptions);
 public
    constructor Create(AOwner: TComponent); override;
    procedure ConvertNativeDataToSoap(RootNode, Node: IXMLNode;
      Name: InvString; Info: PTypeInfo; P: Pointer; NumIndirect: Integer); dynamic;
    procedure ConvertSoapToNativeData(DataP: Pointer; TypeInfo: PTypeInfo;
      Context: TDataContext; RootNode, Node: IXMLNode; Translate, ByRef: Boolean; NumIndirect: Integer); dynamic;
  published
    property Options: TSOAPConvertOptions read FOptions write FOptions;
  end;

  TOPToSoapDomConvert = class(TSOAPDomConv, IOPConvert)
  private
    FWSDLView: TWSDLView;
    Envelope:  TSoapEnvelope;
    function   GetSoapNS(MD: TIntfMetaData): InvString;
    procedure  ProcessFault(FaultNode: IXMLNode);
    procedure  ProcessSuccess(RespNode: IXMLNode; const IntfMD: TIntfMetaData;
                              const MD: TIntfMethEntry; InvContext: TInvContext);
    function   GetPartName(MethMD: TIntfMetaData; ParamName: InvString): InvString;
    procedure  CheckWSDL;
    function   GetBinding: InvString;
    procedure  SetWSDLView(const WSDLView: TWSDLView);
  public
    constructor Create(AOwner: TComponent); override;
    destructor  Destroy; override;
    { IOPConvert }
    procedure MsgToInvContext(const Request: InvString; const IntfMD: TIntfMetaData;
                              var MethNum: Integer; Context: TInvContext); overload; virtual;
    procedure MsgToInvContext(const Request: TStream; const IntfMD: TIntfMetaData;
                              var MethNum: Integer; Context: TInvContext); overload; virtual;
    function  InvContextToMsg(const IntfMD: TIntfMetaData; MethNum: Integer; Con: TInvContext): InvString;
    procedure MakeResponse(const IntfMD: TIntfMetaData; const MethNum: Integer;  Context: TInvContext; Response: TStream); virtual;
    function  MakeFault(const Ex: Exception): InvString; virtual;
    procedure ProcessResponse(const Resp: InvString;
                              const IntfMD: TIntfMetaData;
                              const MD: TIntfMethEntry;
                              Context: TInvContext); overload; virtual;
    procedure ProcessResponse(const Resp: TStream;
                              const IntfMD: TIntfMetaData;
                              const MD: TIntfMethEntry;
                              Context: TInvContext); overload; virtual;

    { Helper routine }
    procedure ProcessResponse(const XMLDoc: IXMLDocument;
                              const IntfMD: TIntfMetaData;
                              const MD: TIntfMethEntry;
                              Context: TInvContext); overload; virtual;
  published
    property WSDLView: TWSDLView read FWSDLView write SetWSDLView;
  end;

var
  DefArrayElemName: string = 'item';    { do not lcoalize }


implementation

uses
{$IFDEF MSWINDOWS}
  ComObj,
{$ENDIF}
EncdDecd, SOAPConst, InvRules, TypeTrans, OPToSOAPDomCustom, VarUtils,
  XSBuiltIns, WSDLBind, XMLSchema, HTTPUtil, WSDLItems;

procedure ParseDims(DimString: InvString; var Dims: TSOAPArrayDesc);
var
  I, J: Integer;
  CurDim, NumDims, SubDims, SubDim: Integer;
  StrLen: Integer;
  DimSize: InvString;
begin
  CurDim := 0;
  NumDims := 0;
  StrLen := Length(DimString);
  for I := 1 to StrLen do
    if DimString[I] = '[' then      { do not localize }
      Inc(NumDims);
  SetLength(Dims, NumDims);
  I := 1;
  while I < StrLen do
  begin
    if DimString[I] = '[' then       { do not localize }
    begin
      DimSize := '';
      Inc(I);
      SubDims := 1;
      SubDim := 0;
      if DimString[I] = ']' then               { do not localize }
        SetLength(Dims[CurDim].Dims, 1);
      while (DimString[I] <> ']') and (I < StrLen) do     { do not localize }
      begin
        J := I;
        while (DimString[J] <> ']') and (J < StrLen) do       { do not localize }
        begin
          if DimString[J] = ',' then
            Inc(SubDims);
          Inc(J);
        end;
        SetLength(Dims[CurDim].Dims, SubDims);
        if SubDims > 1 then
        begin
          Dims[CurDim].MultiDim := True;
          while (DimString[I] <> ']') and (I < StrLen) do     { do not localize }
          begin
            DimSize := '';
            while (DimString[I] <> ',') and (DimString[I] <> ']') and (I < StrLen) do   { do not localize }
            begin
              DimSize := DimSize + DimString[I];
              Inc(I);
            end;
            if DimString[I] = ',' then
              Inc(I);
            if trim(DimSize) <> '' then
              Dims[CurDim].Dims[SubDim] := StrToInt(trim(DimSize))
            else
              Dims[CurDim].Dims[SubDim] := 0;
            Inc(SubDim);
          end
        end else
        begin
          while (DimString[I] <> ']') and (I < StrLen) do      { do not localize }
          begin
            DimSize := DimSize + DimString[I];
            Inc(I);
          end;
          if trim(DimSize) <> '' then
            Dims[CurDim].Dims[SubDim] := StrToInt(trim(DimSize))
          else
            Dims[CurDim].Dims[SubDim] := 0;
        end;
      end;
      Inc(I);
      Inc(CurDim);
    end else
      Inc(I);
  end;
end;

{ TOPToSoapDomConvert }

type
  PTObject = ^TObject;


{ Server Recieve Message }
procedure TOPToSoapDomConvert.MsgToInvContext(const Request: InvString;
  const IntfMD: TIntfMetaData; var MethNum: Integer; Context: TInvContext);
var
  Stream: TStream;
begin
  Stream := TMemoryStream.Create;
  try
    Stream.Write(Request[1], Length(Request) * 2);
    Stream.Position := 0;
    MsgToInvContext(Stream, IntfMD, MethNum, Context);
  finally
    Stream.Free;
  end;
end;

procedure TOPToSoapDomConvert.MsgToInvContext(const Request: TStream;
  const IntfMD: TIntfMetaData; var MethNum: Integer; Context: TInvContext);
var
  XmlDoc: IXMLDocument;
  I, J, K, L: Integer;
  MethodName, InternalMethodName, ExtParamName: InvString;
  EnvNode, MethNode, Node, HdrNode: IXMLNode;
  ProcessedBody: Boolean;
  MD: TIntfMethEntry;
  HeaderProcessor:   IDOMHeaderProcessor;
  HeaderHandled, AbortRequest: Boolean;
  Translate: Boolean;
begin
  XmlDoc := NewXMLDocument;
  Request.Position := 0;
  XmlDoc.LoadFromStream(Request);
  EnvNode := XmlDoc.DocumentElement;
  if EnvNode = nil then
    raise ESOAPDomConvertError.Create(SInvalidSOAPRequest);
  if (ExtractLocalName(EnvNode.NodeName) <> SSoapEnvelope) or (EnvNode.NamespaceURI <> SSoapNameSpace) then
    raise ESOAPDomConvertError.Create(SInvalidSOAPRequest);

  ProcessedBody := False;
  try
    if EnvNode.hasChildNodes then
    begin
      for I := 0 to EnvNode.childNodes.Count -1 do
      begin
        Node := EnvNode.childNodes[I];
        if Node.NodeType <> ntElement then continue;
        if ExtractLocalName(Node.NodeName) = SSoapHeader then
        begin
          if Node.hasChildNodes then
          begin
            for L := 0 to Node.childNodes.Count-1 do
            begin
              HdrNode := Node.childNodes[L];
              AbortRequest := False;
              HeaderProcessor := FindHeaderProcessor(HdrNode.NameSpaceURI,
                                                    ExtractLocalName(HdrNode.NodeName),
                                                    '');
              if HeaderProcessor <> nil then
                HeaderProcessor.ProcessHeader(HdrNode, HeaderHandled, AbortRequest)
              else
                DefaultProcessHeader(HdrNode, HeaderHandled, AbortRequest);
              if AbortRequest then
                raise ESOAPDomConvertError.CreateFmt(SHeaderError, [ExtractLocalName(Node.NodeName)]);
            end;
          end;
        end
        else if ExtractLocalName(Node.NodeName) = SSoapBody then
        begin
          if ProcessedBody then
            raise ESOAPDomConvertError.Create(SMultiBodyNotSupported);
          CheckEncodingStyle(EnvNode);
          ProcessedBody := True;
          if Node.ChildNodes.Count > 0 then
          begin
            MethNode := Node.childNodes[0];  
            CheckEncodingStyle(MethNode);
            MethodName := ExtractLocalName(MethNode.NodeName);
            InternalMethodName := InvRegistry.GetMethInternalName(IntfMD.Info, MethodName);
            MethNum := GetMethNum(IntfMD, InternalMethodName);
            if MethNum = -1 then
                raise ESOAPDomConvertError.CreateFmt(SNoSuchMethod, [MethodName, IntfMD.Name]);
            MD := IntfMD.MDA[MethNum];
            Context.SetMethodInfo(MD);
            Context.AllocServerData(MD);
            for K := 0 to Length(MD.Params) - 1 do
            begin
              ExtParamName := InvRegistry.GetParamExternalName(IntfMD.Info, InternalMethodName, MD.Params[K].Name);
              for J := 0 to MethNode.childNodes.Count -1 do
              begin
                { TODO OWNER:BB How will this fare in case-sensitive issues }
                if SameText(ExtParamName, ExtractLocalName(MethNode.childNodes[J].NodeName)) then
                begin
                  CheckEncodingStyle(MethNode.childNodes[J]);
                  Translate := (pfVar in MD.Params[K].Flags)
                    or (pfConst in  MD.Params[K].Flags)
                    or ([] =  MD.Params[K].Flags)
                    or ((pfReference in MD.Params[K].Flags) and (MD.Params[K].Info.Kind = tkVariant))
                    or ((pfReference in MD.Params[K].Flags) and (MD.Params[K].Info.Kind = tkString));
                  ConvertSoapToNativeData(Context.GetParamPointer(K), MD.Params[K].Info, Context, MethNode,
                    MethNode.childNodes[J], Translate, False,  1);
                  break;
                end;
              end;
            end;
          end;
        end;
      end;
    end else
      raise ESOAPDomConvertError.Create(SInvalidSOAPRequest);
  finally
    ResetMultiRef;
  end;
end;


procedure TOPToSoapDomConvert.MakeResponse(const IntfMD: TIntfMetaData; const MethNum: Integer;  Context: TInvContext; Response: TStream);
var
  I: Integer;
  XmlDoc: IXMLDocument;
  EnvNode, BodyNode, MethNode: IXMLNode;
  MD: TIntfMethEntry;
  SoapNS: InvString;
  ArgName: InvString;
  P: Pointer;
  WResp: WideString;
begin
  MD := IntfMD.MDA[MethNum];
  XMLDoc := NewXMLDocument;
  XMLDoc.Encoding := SUTF8;
  EnvNode := Envelope.MakeEnvelope(XMLDoc, Options);
  XmlDoc.DocumentElement := EnvNode;
  BodyNode := Envelope.MakeBody(EnvNode);
  SoapNS := GetSoapNS(IntfMD);
  MethNode := BodyNode.AddChild(MD.Name + SSoapResponseSuff, SoapNS, True);
  { The following used to put the encoding on the method node;
    The Body node seems more apropos - keep that in mind for interop }
  if not (soDocument in Options) then
{$IFDEF OPENDOM}
    BodyNode.SetAttributeNS(SSoapEncodingAttr, SSoap11EncodingS5, SSoapNameSpace);
{$ELSE}
    BodyNode.Attributes[FindPrefixForURI(EnvNode, BodyNode, SSoapNameSpace) + ':' + SSoapEncodingAttr] := SSoap11EncodingS5;   { do not localize }
{$ENDIF}
  { Result the MultiRef IDs as we're about to create a new Response }
  FIDS := 1;
  try
    if MD.ResultInfo <> nil  then
    begin
      ArgName := GetPartName(IntfMD, '');
      ConvertNativeDataToSoap(MethNode, MethNode, ArgName, MD.ResultInfo, Context.GetResultPointer, 1);
    end;
    for I := 0 to MD.ParamCount - 1  do
    begin
      if (pfVar in MD.Params[I].Flags) or (pfOut in MD.Params[I].Flags)
      then
      begin
        P := Context.GetParamPointer(I);
        ConvertNativeDataToSoap(MethNode, MethNode, MD.Params[I].Name, MD.Params[I].Info, P, 1);
      end;
    end;
  finally
    FinalizeMultiRefNodes;
    ResetMultiRef;
  end;
  XmlDoc.SaveToXML(WResp);
  Response.Position := 0;
  { (BB) Don't send XML Header - let DOM do that
  Hdr := SSoapXMLHeader;
  Response.Write(Hdr[1], Length(Hdr) * 2);
  }
  WResp := Trim(WResp);
  Response.Write(WResp[1], Length(WResp) * 2);
  Response.Position := 0;
end;

function TOPToSoapDomConvert.GetSoapNS(MD: TIntfMetaData): InvString;
var
  ExtName: WideString;
begin
  if Assigned(WSDLView) then
  begin
    ExtName :=  InvRegistry.GetMethExternalName(MD.Info, WSDLVIew.Operation);
    Result := WSDLView.WSDL.GetSoapBodyAttribute(GetBinding, ExtName, WSDLBind.SInput, WSDLBind.SNameSpace);
    { NOTE: Document Style WSDL don't have a namespace on the input/ouput nodes }
    if (Result = '') then
      Result := InvRegistry.GetNamespaceByGUID(MD.IID);
  end else
    Result := InvRegistry.GetNamespaceByGUID(MD.IID);
end;

function TOPToSoapDomConvert.MakeFault(const Ex: Exception): InvString;
var
  XmlDoc: IXMLDocument;
  EnvNode, BodyNode, FaultNode, FC, FS, FD: IXMLNode;
  I, Count: Integer;
  PropList: PPropList;
  URI, TypeName, Prefix: WideString;
  IsScalar: Boolean;
begin
  Result := '';
  XMLDoc := NewXMLDocument;
  XMLDoc.Encoding := SUTF8;
  EnvNode := Envelope.MakeEnvelope(XMLDoc, Options);
  BodyNode := Envelope.MakeBody(EnvNode);
  FaultNode := Envelope.MakeFault(BodyNode);
  FC := FaultNode.AddChild(SSoapFaultCode);
  { This could be cleaned up }
  FC.Text := 'SOAP-ENV:Server';             { do not localize }
  FS := FaultNode.AddChild(SSoapFaultString);
  FS.Text := Ex.Message;
  if Ex.InheritsFrom(ERemotableException) then
  begin
    RemClassRegistry.ClassToURI(Ex.ClassType, URI, TypeName, IsScalar);
    FD := FaultNode.AddChild(SSoapFaultDetails, URI, True);
{$IFDEF OPENDOM}
    FD.SetAttributeNS(SSoapType, XMLSchemaInstNameSpace, FD.Prefix + ':' + TypeName);
{$ELSE}
    Prefix := FindPrefixForURI(BodyNode, FaultNode, XMLSchemaInstNameSpace, True);
    FD.Attributes[MakeNodeName(Prefix, SSoapType)] := FD.Prefix + ':' + TypeName;
{$ENDIF}
    Count := GetTypeData(Ex.ClassInfo)^.PropCount;
    if Count > 0 then
    begin
      GetMem(PropList, Count * SizeOf(Pointer));
      try
        GetPropInfos(Ex.ClassInfo, PropList);
        for I := 0 to Count - 1 do
        begin
          if not RemTypeRegistry.TypeInfoToXSD( (PropList[I].PropType)^, URI, TypeName) then
            raise ESOAPDomConvertError.CreateFmt(SRemTypeNotRegistered, [(PropList[I].PropType)^.Name]);
          CreateScalarNodeXS(FaultNode, FD, PropList[I].Name, URI, TypeName, GetObjectPropAsText(Ex, PropList[I]));
        end;
      finally
        FreeMem(PropList, Count * SizeOf(Pointer));
      end;
    end;
  end;

  XmlDoc.SaveToXML(Result);
  Result := Trim(Result);
end;

function TOPToSoapDomConvert.InvContextToMsg(const IntfMD: TIntfMetaData; MethNum: Integer; Con: TInvContext): InvString;
var
  XMLDoc: IXMLDocument;
  EnvNode, BodyNode, MethNode: IXMLNode;
  I: Integer;
  SoapMethNS: InvString;
  MethMD: TIntfMethEntry;
  P: Pointer;
  Indir: Integer;
  ExtMethName, ExtParamName: InvString;
begin
  MethMD := IntfMD.MDA[MethNum];

  { Here we update the WSDLView to inform it of
    the Operation we're about to execute }
  if Assigned(WSDLView) then
  begin
    WSDLView.Operation := MethMD.Name;
    WSDLView.IntfInfo := IntfMD.Info;
  end;

  XMLDoc := NewXMLDocument;
  XMLDoc.Encoding := SUTF8;
  EnvNode := Envelope.MakeEnvelope(XMLDoc, Options);
  BodyNode := Envelope.MakeBody(EnvNode);

  SoapMethNS := GetSoapNS(IntfMD);
  { Add Method node with appropriate namespace }
  ExtMethName := InvRegistry.GetMethExternalName(IntfMD.Info, MethMD.Name);
  if not (soDocument in Options) then
  begin
    MethNode := BodyNode.AddChild(ExtMethName, SoapMethNS, (SoapMethNS <> ''));
    { Use encoding style defined by SOAP 1.1 section 5 }
    { NOTE: We used to put this on the method node; it seems more intuitive on
            the body node; Keep this in mind when investigating interop issues }
    BodyNode.SetAttributeNS(SSoapEncodingAttr, SSoapNameSpace, SSoap11EncodingS5); { do not localize }
  end
  else
  begin
    { In document mode, SoapMethNS is the default namespace }
    MethNode := BodyNode.AddChild(ExtMethName, SoapMethNS);
  end;

  { Result MultiRef IDs are we're about to create new request }
  FIDS := 1;
  try
    { Add each parameter to the method node }
    for I := 0 to MethMD.ParamCount - 1  do
    begin
      if not (pfOut in MethMD.Params[I].Flags) then
      begin
        ExtParamName := InvRegistry.GetParamExternalName(IntfMD.Info, MethMD.Name, MethMD.Params[I].Name);
        P := Con.GetParamPointer(I);
        Indir := 1;
        if IsParamByRef(MethMd.Params[I].Flags, MethMD.Params[I].Info, MethMD.CC) then
          Inc(Indir);
        ConvertNativeDataToSoap(MethNode, MethNode, ExtParamName,
                                MethMD.Params[I].Info, P, Indir);
      end;
    end;
    FinalizeMultiRefNodes;
  finally
    ResetMultiRef;
  end;

  XMLDoc.SaveToXML(Result);
  Result := Trim(Result);
end;

procedure TOPToSoapDomConvert.ProcessSuccess(RespNode: IXMLNode;
                                             const IntfMD: TIntfMetaData;
                                             const MD: TIntfMethEntry;
                                             InvContext: TInvContext);

  { This is the tricky part of deserializing; How to determine the return index;
    This function should only be used if we're processing a function - IOW, this
    function should only be called if the method we're processing has
    MD.ResultInfo <> nil }
  function FindReturnNodeIndex: integer;
  var
    X, Y, First, Ret, Count: Integer;
    Node: IXMLNode;
    ReturnParams: TStringDynArray;
  begin
    First := -1;
    Ret := -1;
    Count := 0;
    { Get array of return parameter names }
    ReturnParams := StringToStringArray(InvRegistry.GetReturnParamNames(IntfMD.Info),
                                        sReturnParamDelimiters);
    for X := 0 to RespNode.ChildNodes.Count-1 do
    begin
      Node := RespNode.ChildNodes[X];
      if Node.NodeType <> ntElement then
        continue;
      { Save first valid node }
      if First = -1 then
        First := X;
      { Save Return param name(s) matches }
      if (Ret = -1) and (Length(ReturnParams) > 0) then
      begin
        for Y := 0 to Length(ReturnParams)-1 do
        begin
          if SameText(ExtractLocalName(Node.NodeName), ReturnParams[Y]) then
            Ret := X;
        end;
      end;
      Inc(Count);
    end;
    if Count = 1 then
      Result := First
    else
      Result := Ret;
  end;

var
  I, J, RetIndex: Integer;
  InvData: Pointer;
  Node: IXMLNode;
  ByRef: Boolean;
  Indir: Integer;
  ParamProcessed: TBooleanDynArray;
begin
  SetLength(ParamProcessed, MD.ParamCount);
  for J := 0 to Length(ParamProcessed) - 1 do
    ParamProcessed[J] := False;

  { Find index of return node - if we're expecting one }
  if (MD.ResultInfo <> nil) then
  begin
    RetIndex := FindReturnNodeIndex;
    { In document mode we'll be lenient since empty document is valid }
    if (RetIndex = -1) and not (soDocument in Options) then
      raise ESOAPDomConvertError.CreateFmt(SMissingSoapReturn, [RespNode.XML]);
  end
  else
    RetIndex := -1;

  { Process returned nodes }
  for I := 0 to RespNode.childNodes.Count - 1 do
  begin
    Node := RespNode.childNodes[I];
    { Skip non-valid nodes }
    if Node.NodeType <> ntElement then continue;
    { Process Return value, if we're expecting one }
    if I = RetIndex then
    begin
      InvData := InvContext.GetResultPointer;
      ByRef := IsParamByRef([pfOut], MD.ResultInfo, MD.CC);
      ConvertSoapToNativeData(InvData, MD.ResultInfo, InvContext, RespNode, Node, True, ByRef, 1);
    end
    else
    begin
      J := 0;
      while J < MD.ParamCount do
      begin
        if MD.Params[J].Name = ExtractLocalName(Node.NodeName) then
          break;
        Inc(J);
      end;
      if (J < MD.ParamCount) and not ParamProcessed[J]  then
      begin
        ParamProcessed[J] := True;
        InvData := InvContext.GetParamPointer(J);
        ByRef := IsParamByRef(MD.Params[J].Flags, MD.Params[J].Info, MD.CC);
        Indir := 1;
        if IsParamByRef(MD.Params[J].Flags, MD.Params[J].Info, MD.CC) then
          Inc(Indir);
        ConvertSoapToNativeData(InvData, MD.Params[J].Info, InvContext, RespNode, Node, True, ByRef,  Indir);
      end;
    end;
  end;
end;


procedure TOPToSoapDomConvert.ProcessFault(FaultNode: IXMLNode);
var
  FA, FC, FD, FS: IXMLNode;
  I, J: Integer;
  Message: WideString;
  AClass: TClass;
  URI, TypeName: WideString;
  IsScalar: Boolean;
  Count: Integer;
  PropList: PPropList;
  Ex: ERemotableException;
begin
  FA := nil;
  FC := nil;
  FD := nil;
  FS := nil;
  Ex := nil;
  for I := 0 to FaultNode.ChildNodes.Count - 1 do
  begin
    if      SameText(ExtractLocalName(FaultNode.ChildNodes[I].NodeName), SSoapFaultCode) then
      FC := FaultNode.ChildNodes[I]
    else if SameText(ExtractLocalName(FaultNode.ChildNodes[I].NodeName), SSoapFaultString) then
      FS := FaultNode.ChildNodes[I]
    else if SameText(ExtractLocalName(FaultNode.ChildNodes[I].NodeName), SSoapFaultDetails) then
      FD := FaultNode.ChildNodes[I]
    else if SameText(ExtractLocalName(FaultNode.ChildNodes[I].NodeName), SSoapFaultActor) then
      FA := FaultNode.ChildNodes[I];
  end;

  { Retrieve message from FaultString node }
  if FS <> nil then
    Message := FS.Text;

  { If there's a <detail> node, try to map it to a registered type }
  if FD <> nil then
  begin
    { The following logic is not very well settled. The current assumption is that
      the type and namespace will be on the <detail> node itself. Some SOAP stacks,
      including current Delphi and others (see
      http://softwaredev.earthweb.com/script/article/0,,12063_641361_2,00.html)
      do use that approach:

      Listing 4 - Application Fault Details
      <SOAP-ENV:Fault>
        <faultcode>300</faultcode>
        <faultstring>Invalid Request</faultstring>
        <runcode>1</runcode>
        <detail xmlns:e="GetTemperatureErr-URI"
                xmlns:xsi="http://www.w3.org/1999/XMLSchema-instance"
                xsi:type="e:GetTemperatureFault">
            <number>5575910</number>
            <description>Sensor Failure</description>
            <file>GetTemperatureClass.cpp</file>
            <line>481</line>
        </detail>
      </SOAP-ENV:Fault>

      However, much more common is the approach where the type and namespace
      are on the childnode of the <detail> node. Apache, MS and the SOAP spec.
      seem to lean towards that approach:

      Example 10 from the SOAP 1.1 Spec:

      <SOAP-ENV:Envelope
        xmlns:SOAP-ENV="http://schemas.xmlsoap.org/soap/envelope/">
         <SOAP-ENV:Body>
             <SOAP-ENV:Fault>
                 <faultcode>SOAP-ENV:Server</faultcode>
                 <faultstring>Server Error</faultstring>
                 <detail>
                     <e:myfaultdetails xmlns:e="Some-URI">
                       <message>
                         My application didn't work
                       </message>
                       <errorcode>
                         1001
                       </errorcode>
                     </e:myfaultdetails>
                 </detail>
             </SOAP-ENV:Fault>
         </SOAP-ENV:Body>
      </SOAP-ENV:Envelope>

      I favor the later approach but will need to find out more before
      changing the logic. Safest currently would be to offer an option
      on where to expect the detail information
    }
    GetElementType(FD, URI, TypeName);
    AClass := RemClassRegistry.URIToClass(URI, TypeName, IsScalar);
    if AClass <> nil then
    begin
      if AClass.InheritsFrom(ERemotableException) then
      begin
        Ex := ERemotableExceptionClass(AClass).Create(Message);
        Count := GetTypeData(Ex.ClassInfo)^.PropCount;
        if (Count > 0) and Assigned(FD.ChildNodes) then
        begin
          GetMem(PropList, Count * SizeOf(Pointer));
          try
            GetPropInfos(Ex.ClassInfo, PropList);
            for I := 0 to Count - 1 do
            begin
              for J := 0 to FD.ChildNodes.Count - 1 do
                if ExtractLocalName(FD.ChildNodes[J].NodeName) = PropList[I].Name then
                 SetObjectPropFromText(Ex, PropList[I], FD.ChildNodes[J].Text);
            end;
          finally
            FreeMem(PropList, Count * SizeOf(Pointer));
          end;
        end;
      end;
    end;
  end;

  { Create default SOAP invocation exception if no suitable on was found }
  if Ex = nil then
    Ex := ERemotableException.Create(Message);
  if FA <> nil then
    Ex.FaultActor := FA.Text;
  if FC <> nil then
    Ex.FaultCode := FC.Text;
  if FD <> nil then
    Ex.FaultDetail := FD.XML;
  raise Ex;
end;


procedure TOPToSoapDomConvert.ProcessResponse(const Resp: InvString;
                                              const IntfMD: TIntfMetaData;
                                              const MD: TIntfMethEntry;
                                              Context: TInvContext);
var
 Stream: TMemoryStream;
begin
   Stream := TMemoryStream.Create;
  try
    Stream.Write(Resp[1], Length(Resp));
    ProcessResponse(Stream, IntfMD, MD, Context);
  finally
    Stream.Free;
  end
end;

procedure TOPToSoapDomConvert.ProcessResponse(const XMLDoc: IXMLDocument;
                                              const IntfMD: TIntfMetaData;
                                              const MD: TIntfMethEntry;
                                              Context: TInvContext);
var
  I, J, RespNodeIndex: Integer;
  EnvNode, RespNode, Node, HdrNode: IXMLNode;
  ProcessedHeader, ProcessedBody: Boolean;
  HeaderProcessor: IDOMHeaderProcessor;
  HeaderHandled, AbortRequest, FirstNode: Boolean;
begin
  EnvNode := XMLDoc.DocumentElement;
  if EnvNode = nil then
    raise ESOAPDomConvertError.Create(SInvalidResponse);
  if (ExtractLocalName(EnvNode.NodeName) <> SSoapEnvelope) or
     (EnvNode.NamespaceURI <>  SSoapNameSpace) then
    raise ESOAPDomConvertError.CreateFmt(SWrongDocElem, [SSoapNameSpace, SSoapEnvelope, EnvNode.NamespaceURI,
                                                         ExtractLocalName(EnvNode.NodeName)]);
  ProcessedHeader := False;
  ProcessedBody := False;
  FirstNode := True;

  if EnvNode.hasChildNodes then
  begin
    RespNodeIndex := 0;
    for I := 0 to EnvNode.childNodes.Count -1 do
    begin
      Node := EnvNode.childNodes[I];
      if Node.NodeType <> ntElement then
      begin
        if FirstNode then Inc(RespNodeIndex);
        continue;
      end;
      if ExtractLocalName(Node.NodeName) = SSoapHeader then
      begin
        if ProcessedHeader then
          raise ESOAPDomConvertError.Create(SInvalidSOAPRequest);
        ProcessedHeader := True;

        if Node.hasChildNodes then
        begin
          for J := 0 to Node.childNodes.Count-1 do
          begin
            HdrNode := Node.childNodes[J];
            AbortRequest := False;
            HeaderProcessor := FindHeaderProcessor(HdrNode.NameSpaceURI,
                                                  ExtractLocalName(HdrNode.NodeName),
                                                  '');
            if HeaderProcessor <> nil then
              HeaderProcessor.ProcessHeader(HdrNode, HeaderHandled, AbortRequest)
            else
              DefaultProcessHeader(HdrNode, HeaderHandled, AbortRequest);
            if AbortRequest then
              raise ESOAPDomConvertError.CreateFmt(SHeaderError, [ExtractLocalName(Node.NodeName)]);
          end;
        end;
      end
      else if ExtractLocalName(Node.NodeName) = SSoapBody then
      begin
        if ProcessedBody then
          raise ESOAPDomConvertError.Create(SInvalidSOAPRequest);
        ProcessedBody := True;
        FirstNode := False;
        RespNode := Node.childNodes[RespNodeIndex];
        try
          if ExtractLocalName(RespNode.NodeName) = SSoapFault then
            ProcessFault(RespNode)
          else
            ProcessSuccess(RespNode, IntfMD, MD, Context);
        finally
          ResetMultiRef;
        end;
      end;
    end
  end else
    raise ESOAPDomConvertError.Create(SInvalidSOAPRequest);
end;

procedure TOPToSoapDomConvert.ProcessResponse(const Resp: TStream;
                                              const IntfMD: TIntfMetaData;
                                              const MD: TIntfMethEntry;
                                              Context: TInvContext);
var
  XMLDoc: IXMLDocument;
begin
  XMLDoc := NewXMLDocument;
  XMLDoc.Encoding := SUTF8;
  Resp.Position := 0;
  XMLDoc.LoadFromStream(Resp);
  ProcessResponse(XMLDoc, IntfMD, MD, Context);
end;

constructor TOPToSoapDomConvert.Create(AOwner: TComponent);
begin
  inherited;
  Envelope := TSoapEnvelope.Create;
  FIDs := 1;
  Options := Options + [soSendMultiRefObj,
                        soRootRefNodesToBody,
                        soTryAllSchema];
end;

destructor TOPToSoapDomConvert.Destroy;
begin
  Envelope.Free;
  inherited;
end;

procedure TOPToSoapDomConvert.CheckWSDL;
begin
  if Assigned(WSDLView.WSDL) then
  begin
    WSDLView.Activate;
  end
  else
    raise ESOAPDomConvertError.Create(SNoWSDL);
end;

function TOPToSoapDomConvert.GetBinding: InvString;
var
  QName: IQualifiedName;
begin
  CheckWSDL;
  QName := WSDLView.WSDL.GetBindingForServicePort(WSDLView.Service, WSDLView.Port);
  if QName <> nil then
    Result := QName.Name;
end;

procedure TOPToSoapDomConvert.SetWSDLView(const WSDLView: TWSDLView);
begin
  FWSDLView := WSDLView;
end;

{ ParamName = '' implies function return value }
function TOPToSoapDomConvert.GetPartName(MethMD: TIntfMetaData; ParamName: InvString): InvString;
begin
  if ParamName = '' then
    Result := SDefaultReturnName
  else
    Result := InvRegistry.GetNamespaceByGUID(MethMD.IID);
end;


{ TSOAPDomConv }
constructor TSOAPDomConv.Create(AOwner: TComponent);
begin
  inherited;
end;


procedure TSOAPDomConv.ConvertVariantToSoap(RootNode, Node: IXMLNode;
  Name: InvString; Info: PTypeInfo; P: PVarData; NumIndirect: Integer; V: Variant; UseVariant: Boolean);
var
  DataP: Pointer;
begin
  if UseVariant then
  begin
    if VarIsNull(V) then
      CreateNULLNode(RootNode, Node, Name)
    else
      WriteVariant(RootNode, Node, Name, V);
  end else
  begin
    DataP := P;
    if NumIndirect > 1 then
      DataP := Pointer(PInteger(DataP)^);
    if (DataP = nil) or VarIsNull(Variant(DataP^)) then
      CreateNULLNode(RootNode,Node, Name)
    else
      WriteVariant(RootNode, Node, Name, Variant(DataP^));
  end;
end;


procedure TSOAPDomConv.WriteVariant(RootNode, Node: IXMLNode; Name: InvString; V: Variant);
var
  S, URI, TypeName: InvString;
  Info: PTypeInfo;
  AClass: TClass;
  IsScalar: Boolean;
  DT: TXSDateTime;
begin
  if VarIsArray(V) then
  begin
    if VarIsType(V, varByte or varArray) then
    begin
      WriteVarArrayAsB64(RootNode, Node, Name, V);
    end
    else
    WriteVarArray(RootNode, Node, Name, V);
  end
  else
  begin
    if VarIsNull(V) or VarIsEmpty(V) then
       CreateNULLNode(RootNode,Node, Name)
    else
    begin
      Info :=  RemTypeRegistry.VariantToInfo(V, soTryAllSchema in Options);
      if Info = nil then
         raise ESOAPDomConvertError.Create(SUnsupportedVariant);
      RemTypeRegistry.InfoToURI(Info, URI, TypeName, IsScalar);
      if Info.Kind = tkClass then
      begin
        AClass := GetTypeData(Info).ClassType;
        if not AClass.InheritsFrom(TRemotableXS) then
          raise ESOAPDomConvertError.Create(SUnsupportedVariant);
        DT := DateTimeToXSDateTime(V);
        S := DT.NativeToXS;
        DT.Free;
      end else
        S := V;
      CreateScalarNodeXS(RootNode, Node, Name, URI, TypeName, S);
    end;
  end;
end;

function TSOAPDomConv.MakeArrayNode(RootNode, Node: IXMLNode;  Name, URI, TypeName: InvString;
  Indices: array of Integer): IXMLNode;
var
  ArraySpec, Dims: InvString;
  I: Integer;
  First: Boolean;
  SoapPre, Pre, TypeNs: InvString;
  ID: string;
  MultiRefNode: IXMLNode;
begin
  { Assume we have a variant type and don't create an array node }
  if (URI = '') or (TypeName = '') then
  begin
    Result := Node.AddChild(Name);
  end else
  begin

    if (soSendMultiRefArray in Options) and not (soDocument in Options) then
    begin
      ID := GetNewID;
      Pre := FindPrefixForURI(RootNode, Node,  URI, True);
      Result :=  Node.AddChild(MakeNodeName(Pre, Name));
      Result.Attributes[SXMLHREF] := SHREFPre + ID;
      Pre := FindPrefixForURI(RootNode, Node, SSoap11EncodingS5, True);
      MultiRefNode := CreateMultiRefNode(RootNode, MakeNodeName(Pre, SSoapEncodingArray), ID);   { do not localize }
      Result := MultiRefNode;
    end else
    begin
      MultiRefNode := nil;
      if (soDocument in Options) then
      begin
        TypeNS := ''
      end
      else
      begin
        TypeNS := SSoap11EncodingS5;
      end;
      Result := CreateTypedNode(RootNode, Node, Name, TypeNS, SSoapEncodingArray);
    end;
    begin
      I := 0;
      if Indices[I] = 0 then
      begin
        while (I < Length(Indices) - 1) and (Indices[I] = 0) do
        begin
          Dims := Dims + '[]';    { do not localize }
          Inc(I);
        end;
      end;

      First := True;
      if I < Length(Indices)  then
      begin
        Dims := Dims + '[';          { do not localize }
        while I < Length(Indices)  do
        begin
          if not First then
          begin
            Dims := Dims + ',';      { do not localize }
          end;
          First := False;
{         if Indices[I] <> 0 then -  { Why not emit size 0 ?? }
            Dims := Dims + IntToStr(Indices[I]);
          Inc(I);
        end;
        Dims := Dims +  ']';       { do not localize }
      end;
    end;
    if not (soSendUntyped in Options) and not (soDocument in Options) then
    begin
      SoapPre := FindPrefixForURI(RootNode, Node, SSoap11EncodingS5, True);
      Pre := FindPrefixForURI(RootNode, Node, URI, True);
      ArraySpec := Pre + ':' + TypeName + Dims;     { do not localize }
      { JMK TODO: verify we're using the correct Namespace here! }
{$IFDEF OPENDOM}
      Result.SetAttributeNS(SSoapEncodingArrayType, SSoap11EncodingS5, ArraySpec);
{$ELSE}
      { TODO - MS DOM is picky about above approach - investigate!!}
      Result.Attributes[MakeNodeName(SoapPre, SSoapEncodingArrayType)] := ArraySpec;
{$ENDIF}
    end;
  end;
end;

procedure TSOAPDomConv.WriteVarArrayAsB64(RootNode, Node: IXMLNode; Name: InvString; V: Variant);
var
  I, DimCount, VSize: Integer;
  LoDim, HiDim: array of integer;
  P: Pointer;
  S, Encd: String;
  ElemNode: IXMLNode;
begin
  DimCount := VarArrayDimCount(V);
  SetLength(LoDim, DimCount);
  SetLength(HiDim, DimCount);
  for I := 1 to DimCount do
  begin
    LoDim[I - 1] := VarArrayLowBound(V, I);
    HiDim[I - 1] := VarArrayHighBound(V, I);
  end;
  VSize := 0;
  for i := 0 to DimCount - 1 do
    VSize := (HiDim[i] - LoDim[i] + 1);
  P := VarArrayLock(V);
  try
    SetString(S, PChar(P), VSize);
  finally
    VarArrayUnlock(V);
  end;
  Encd :=  EncodeString(S);
  ElemNode := CreateScalarNodeXS(RootNode, Node, Name, XMLSchemaNamespace, 'base64Binary', Encd);   { do not localize }
end;

procedure TSOAPDomConv.WriteVarArray(RootNode, Node: IXMLNode; Name: InvString; V: Variant);
var
  I, DimCount: Integer;
  LoDim, HiDim, Indices: array of integer;
  V1: Variant;
  ElemNode: IXMLNode;
  VAPropSet: Boolean;
begin
  if  not VarIsArray(V) then
  begin
    WriteVariant(RootNode, Node, Name, V);
  end
  else
  begin
    ElemNode := Node.AddChild(Name);
    DimCount := VarArrayDimCount(V);
    SetLength(LoDim, DimCount);
    SetLength(HiDim, DimCount);
    for I := 1 to DimCount do
    begin
      LoDim[I - 1] := VarArrayLowBound(V, I);
      HiDim[I - 1] := VarArrayHighBound(V, I);
    end;
    SetLength(Indices, DimCount);
    for I := 0 to DimCount - 1 do
      Indices[I] := LoDim[I];
    VAPropSet := False;
    while True do
    begin
      V1 := VarArrayGet(V, Indices);
      if VarIsArray(V1) and not VarIsType(V1, varArray or varByte) then
        WriteVarArray(RootNode, ElemNode, SDefVariantElemName, V1)
      else
      begin
        WriteVariant(RootNode, ElemNode, SDefVariantElemName, V1);
        if not VAPropSet then
        begin
          SetAttributeNS(RootNode, ElemNode, SVarArrayType, SBorlandTypeNamespace, IntToStr(VarType(V)));
          ElemNode.SetAttributeNS(SVarArrayType, SBorlandTypeNamespace, VarType(V));
          VAPropSet := True;
        end;          
      end;
      Inc(Indices[DimCount - 1]);
      if Indices[DimCount - 1] > HiDim[DimCount - 1] then
        for i := DimCount - 1 downto 0 do
          if Indices[i] > HiDim[i] then
          begin
            if i = 0 then Exit;
            Inc(Indices[i - 1]);
            Indices[i] := LoDim[i];
          end;
    end;
  end;
end;

function  TSOAPDomConv.ReadVarArrayDim(Node: IXMLNode; IsVarVArray: Boolean; VT: TVarType): Variant;
var
  I: Integer;
  SoapTypeInfo: PTypeInfo;
  ChildNode: IXMLNode;
  TypeURI, TypeName: InvString;
  DT: TXSDateTime;
begin
  if Node.ChildNodes.Count = 0 then
  begin
    Result := NULL;
    Exit;
  end;

  { It would be better here to find out the number of ntElement ChildNodes
    and create the array using that instead of the total number of ChildNodes
    -----
    Also, we could use the TVarType to (re)create a Variant of the
    original array type; Using VarVariant, however, is more
    resilient; and as long as no one cracks the Variant open - i.e.
    casts to TVarData and starts accessing members directly - we're safe.
    Sure hopes no one does that!!
  }
  Result := VarArrayCreate([0, Node.ChildNodes.Count-1], VarVariant);
  for I := 0 to Node.ChildNodes.Count -1 do
  begin
    ChildNode := Node.ChildNodes[I];
    if ChildNode.NodeType <> ntElement then continue;
    IsVarVArray := IsNodeAVarArray(ChildNode, VT);
    if IsVarVarray or (ChildNode.ChildNodes.Count > 1) then
    begin
      Result[I] := ReadVarArrayDim(ChildNode, IsVarVArray, VT);
    end else
    begin
      if not NodeIsNULL(ChildNode) then
      begin
        GetElementType(ChildNode, TypeURI, TypeName);
        SoapTypeInfo := RemTypeRegistry.XSDToTypeInfo(TypeURI, TypeName);
        if SoapTypeInfo = nil then
          SoapTypeInfo := TypeInfo(System.WideString);
        if (SoapTypeInfo.Kind = tkClass) and (GetTypeData(SoapTypeInfo).ClassType = TXSDateTime) then
        begin
          DT := TXSDateTime.Create;
          DT.XSToNative(ChildNode.Text);
          Result[I] := DT.AsDateTime;
          DT.Free;
        end else
        Result[I] := TypeTranslator.CastSoapToVariant(SoapTypeInfo, ChildNode.Text);
      end else
        Result[I] := NULL;
    end;
  end;
end;

function TSOAPDomConv.IsNodeAVarArray(const Node: IXMLNode; var VT: TVarType): Boolean;
begin
  if not VarIsNull(Node.GetAttributeNS(SVarArrayType, '')) then
  begin
    VT := StrToInt(Node.GetAttributeNS(SVarArrayType, ''));
    Result := True;
  end else
    Result := False;
end;


procedure TSOAPDomConv.ConvertSoapToVariant(Node: IXMLNode; InvData: Pointer);
var
  Info: PTypeInfo;
  TypeURI, TypeName: InvString;
  DT: TXSDateTime;
  IsVarray: Boolean;
  VT: TVarType;
begin
  if not Assigned(Node.ChildNodes) then
    Exit;
  if Node.ChildNodes.Count = 0 then
    Variant(PVarData(InvData)^) := NULL;
  IsVarray := IsNodeAVarArray(Node, VT);
  if (Node.ChildNodes.Count > 1) or Node.ChildNodes[0].IsTextElement or IsVarray then
    Variant(PVarData(InvData)^) := ReadVarArrayDim(Node, IsVarray, VT)
  else
  begin
    GetElementType(Node, TypeURI, TypeName);
    Info := RemTypeRegistry.XSDToTypeInfo(TypeURI, TypeName);
    if Info = nil then
      Info := TypeInfo(System.WideString);
    if (Info.Kind = tkClass) and (GetTypeData(Info).ClassType = TXSDateTime) then
    begin
      DT := TXSDateTime.Create;
      try
        DT.XSToNative(Node.Text);
        Variant(PVarData(InvData)^) := DT.AsDateTime;
      finally
        DT.Free;
      end;
    end else
      TypeTranslator.CastSoapToVariant(Info, GetNodeAsText(Node), InvData);
  end;
end;

function TSOAPDomConv.FindNodeByHREF(RootNode: IXMLNode; HREF: InvString): IXMLNode;

  function findNode(root: IXMLNode): IXMLNode;
  var
    I: Integer;
    V: Variant;
  begin
    for I := 0 to root.ChildNodes.Count -1 do
    begin
      V := root.ChildNodes[I].Attributes[SXMLID];
      if not VarIsNull(V) and (SHREFPre + V = HREF) then
      begin
        Result := root.ChildNodes[I];
        Exit;
      end;
    end;
  end;

begin
  Result := nil;
  { First look at the root node }
  Result := findNode(RootNode);

  {If we could not find it, move up one level }
  if (Result = nil) and (RootNode.ParentNode <> nil) then
    Result := findNode(RootNode.ParentNode);
end;


function GetDynArrayLength(P: Pointer): Integer;
begin
  asm
    MOV  EAX, DWORD PTR P
    CALL System.@DynArrayLength
    MOV DWORD PTR [Result], EAX
  end;
end;

function RecurseArray(P: Pointer; var Dims: Integer): Boolean;
var
  I, Len, Size: Integer;
  ElemDataP: Pointer;
  Size2: Integer;
begin
  Result := True;
  if Dims > 1 then
  begin
    Len := GetDynArrayLength(P);
    ElemDataP := Pointer(PInteger(P)^);
    Size := GetDynArrayLength(ElemDataP);
    for i := 0 to Len - 1 do
    begin
      Size2 :=  GetDynArrayLength(ElemDataP);
      if Size <> Size2 { GetDynArrayLength(ElemDataP) } then
      begin
        Result := False;
        Exit;
      end;
      if Dims > 1 then
      begin
        Dec(Dims);
        Result := RecurseArray(ElemDataP, Dims);
        if not Result then
          Exit;
      end;
      ElemDataP := Pointer(PInteger(Pointer(Integer(P) + 4))^);
    end;
  end;
end;

function IsArrayRect(P: Pointer; Dims: Integer): Boolean;
var
  D: Integer;
begin
  D := Dims;
  Result := RecurseArray(P, D);
end;


procedure GetDims(ArrP: Pointer; DimAr: TIntegerDynArray; Dims: Integer);
var
  I: Integer;
begin
  for I := 0 to Dims - 1 do
  begin
    DimAr[I] := GetDynArrayLength(ArrP);
    if I < Dims - 1 then
      ArrP := Pointer(PInteger(ArrP)^);
  end;
end;

procedure TSOAPDomConv.WriteRectDynArrayElem(RootNode, Node: IXMLNode;
                                             Info: PTypeInfo;
                                             Size, Dim: Integer;
                                             P: Pointer;
                                             TypeName: InvString);
var
  I: Integer;
  S: InvString;
  IsNull: Boolean;
  ArNode: IXMLNode;
  ElemSize: Integer;
  NodeName: InvString;
begin
  if Dim > 1 then
  begin
    Dec(Dim);
    for I := 0 to Size - 1 do
    begin
      ElemSize := GetDynArrayLength(Pointer(PInteger(P)^));
      WriteRectDynArrayElem(RootNode, Node, Info, ElemSize, Dim, Pointer(PInteger(P)^), TypeName);
      P := Pointer(Integer(P) + sizeof(Pointer));
    end;
  end
  else
  begin
    { Determine name of node }
    if (soDocument in options) then
      NodeName := TypeName
    else
      NodeName := DefArrayElemName;

    { Write out data }
    for I := 0 to Size - 1 do
    begin
      if Info.Kind = tkClass then
      begin
        ConvertObjectToSOAP(NodeName, P, RootNode,  Node, 1);
      end else
      if Info.Kind = tkVariant then
      begin
        ConvertVariantToSoap(RootNode, Node, NodeName, Info, P, 1, NULL, False);
      end else
      begin
        if Info.Kind = tkEnumeration then
          S := ConvertEnumToSoap(Info, P, 1)
        else
          TypeTranslator.CastNativeToSoap(Info, S, P, IsNull);

        { Create node }
        if (soDocument in Options) then
          ArNode := Node.AddChild(NodeName)
        else
          ArNode := Node.AddChild(NodeName, ''); { No namespace prefix }
        { Set Value }
        ArNode.Text := S;
      end;
      P := Pointer( Integer(P) + GetTypeSize(Info));
    end;
  end;
end;

procedure  TSOAPDomConv.WriteRectDynArray(RootNode, Node: IXMLNode; Info: PTypeInfo; Dims: Integer; P: Pointer; TypeName: InvString);
begin
  WriteRectDynArrayElem(RootNode, Node, Info, GetDynArrayLength(P), Dims, P, TypeName);
end;

function TSOAPDomConv.WriteNonRectDynArrayElem(RootNode, Node: IXMLNode;  Info: PTypeInfo; URI, TypeName: InvString; P: Pointer; Dim: Integer): Integer;
var
  I, Len: Integer;
  IsNull: Boolean;
  ElemNode, DataNode: IXMLNode;
  ArrayDims: TIntegerDynArray;
  ID: Integer;
  S: InvString;
  NodeName : InvString;
begin
  { Compute NodeName }
  if soDocument in Options then
    NodeName := TypeName
  else
    NodeName := DefArrayElemName;

  Len := GetDynArrayLength(P);
  if Dim > 1 then
  begin
    SetLength(ArrayDims, Dim);
    for I := 0 to Dim - 2 do
      ArrayDims[I] := 0;
    ArrayDims[Dim-1] := Len;
    Dec(Dim);
    ElemNode := MakeArrayNode(RootNode, RootNode,  NodeName, URI, TypeName, ArrayDims);
    Result := FIDs;
    ElemNode.Attributes[SXMLID] := SArrayIDPre + IntToStr(Result);
    Inc(FIDs);
    for I := 0 to Len - 1 do
    begin
      ID := WriteNonRectDynArrayElem(RootNode, ElemNode, Info, URI, TypeName, Pointer( PInteger(P)^), Dim);
      if ID <> 0 then
      begin
        DataNode := ElemNode.AddChild(NodeName);
        DataNode.Attributes[SXMLHREF] := SHREFPre + SArrayIDPre + IntToStr(ID);
      end;
      P := Pointer(Integer(P) + sizeof(Pointer));
    end;
  end
  else
  begin
    SetLength(ArrayDims, 1);
    ArrayDims[0] := Len;
    ElemNode := MakeArrayNode(RootNode, RootNode, NodeName, URI, TypeName, ArrayDims);

    Result := FIDs;
    Inc(FIDs);
    ElemNode.Attributes[SXMLID] :=  SArrayIDPre + IntToStr(Result);

    for I := 0 to Len - 1 do
    begin
      TypeTranslator.CastNativeToSoap(Info, S, P, IsNull);
      DataNode := ElemNode.AddChild(NodeName);
      DataNode.Text := S;
      P := Pointer( Integer(P) + GetTypeSize(Info));
    end;
  end;
end;

procedure TSOAPDomConv.ReadVariant(Node: IXMLNode; P: Pointer);
var
  SoapTypeInfo: PTypeInfo;
  DT: TXSDateTime;
  URI, TypeName: InvString;
begin
  Variant(PVarData(P)^) := NULL;
  if  Node.ChildNodes.Count > 1 then
    Variant(PVarData(P)^) := ReadVarArrayDim(Node)
  else
  begin
    GetElementType(Node, URI, TypeName);
    SoapTypeInfo := RemTypeRegistry.XSDToTypeInfo(URI, TypeName);
    if SoapTypeInfo = nil then
      SoapTypeInfo := TypeInfo(System.WideString);
   if (SoapTypeInfo.Kind = tkClass) and (GetTypeData(SoapTypeInfo).ClassType = TXSDateTime) then 
   begin
     DT := TXSDateTime.Create;
     DT.XSToNative(Node.Text);
     Variant(PVarData(P)^) := DT.AsDateTime;
     DT.Free;
   end else
     Variant(PVarData(P)^) :=  TypeTranslator.CastSoapToVariant(SoapTypeInfo, GetNodeAsText(Node));
 end;
end;

procedure TSOAPDomConv.ReadRow(RootNode, Node: IXMLNode; var CurElem: Integer; Size: Integer; P: Pointer; Info: PTypeInfo);
var
  I: Integer;
  URI, TypeName: InvString;
  IsNull, IsScalar: Boolean;
begin
  if CurElem > Node.ChildNodes.Count -1 then
     raise ESOAPDomConvertError.Create(SArrayTooManyElem);
   if Info.Kind = tkClass then
   begin
     for I := 0 to Size - 1 do
     begin
       RemClassRegistry.ClassToURI(GetTypeData(Info).ClassType, URI, TypeName, IsScalar);
       PTObject(P)^ := ConvertSOAPToObject(RootNode, Node.ChildNodes[CurElem],
                          GetTypeData(Info).ClassType, URI, TypeName, P, 1);
       P := Pointer(Integer(P) + sizeof(Pointer));
       Inc(CurElem);
     end;
   end else if Info.Kind = tkVariant then
   begin
     for I := 0 to Size - 1 do
     begin
       ReadVariant(Node.ChildNodes[CurElem], P);
       P := Pointer(Integer(P) + GetTypeSize(Info));
       Inc(CurElem);
     end;
   end else
   begin
     IsNull := False;
     for I := 0 to Size - 1 do
     begin
      TypeTranslator.CastSoapToNative(Info,  Node.ChildNodes[CurElem].Text, P, IsNull);
      P := Pointer(Integer(P) + GetTypeSize(Info));
      Inc(CurElem);
     end;
  end;
end;


procedure TSOAPDomConv.ReadRectDynArrayElem(RootNode, Node: IXMLNode; Info: PTypeInfo; Size, Dim: Integer; P: Pointer;
  var CurElem: Integer);
var
  I: Integer;
  ElemSize: Integer;
  ID: InvString;
begin
  Node := GetDataNode(RootNode, Node, ID);
  if Dim > 1 then
  begin
    Dec(Dim);
    for I := 0 to Size - 1 do
    begin
      ElemSize := GetDynArrayLength(Pointer(PInteger(P)^));
      ReadRectDynArrayElem(RootNode, Node, Info, ElemSize, Dim, Pointer(PInteger(P)^), CurElem);
      P := Pointer(Integer(P) + sizeof(Pointer));
    end;
  end
  else
  begin
     if CurElem > Node.ChildNodes.Count -1 then
       raise ESOAPDomConvertError.Create(SArrayTooManyElem);

     ReadRow(RootNode, Node, CurElem, Size, P, Info);
  end;
end;


procedure TSOAPDomConv.ReadRectDynArray(RootNode, Node: IXMLNode; Info: PTypeInfo; Dims: Integer; P: Pointer; CurElem: Integer);
begin
  ReadRectDynArrayElem(RootNode, Node, Info, GetDynArrayLength(P), Dims, P, CurElem);
end;

function TSOAPDomConv.ConvertSoapToNativeArrayElem(ArrayInfo, ElemInfo: PTypeInfo;
  RootNode, Node: IXMLNode; ArrayDesc: TSOAPArrayDesc; Dims, CurDim: Integer; DataP: Pointer): Pointer;
var
  PElem, ChildP, DynP: Pointer;
  Size, I: Integer;
  ID: InvString;
  ChildNode: IXMLNode;
  NodeOffset: Integer;
  CurElem: Integer;
  IntVec: TIntegerDynArray;
  DimCnt: Integer;
begin
  Result := nil;
  Node := GetDataNode(RootNode, Node, ID);
  if Dims > 1 then
  begin
    if (Length(ArrayDesc) > 0 ) and ArrayDesc[CurDim].MultiDim then
    begin
      DynP := Pointer(PInteger(DataP)^);
      DynArraySetLength(DynP, ArrayInfo, Length(ArrayDesc[CurDim].Dims), PLongInt(ArrayDesc[CurDim].Dims));
      Result := DynP;
      Size :=  Length(ArrayDesc[CurDim].Dims);
      NodeOffset := 0;
      ReadRectDynArray(RootNode,  Node, ElemInfo, Size, DynP, NodeOffset);
    end else
    begin
      Size := Node.ChildNodes.Count;
      DynP := Pointer(PInteger(DataP)^);
      if Length(ArrayDesc) = 0 then
      begin
        SetLength(IntVec, 1);
        DimCnt := 1;
      end else
      begin
        SetLength(IntVec, Length(ArrayDesc[CurDim].Dims));
        DimCnt := Length(ArrayDesc[CurDim].Dims);
      end;
      for I := 0 to Length(IntVec) -1 do
        IntVec[I] := Size;
      DynArraySetLength(DynP, ArrayInfo, DimCnt, PLongInt(IntVec));
      PElem := DynP;
      Result := DynP;
      Dec(Dims);
      Inc(CurDim);
      for I := 0 to Size - 1 do
      begin
        ChildNode := GetDataNode(RootNode, Node.ChildNodes[I], ID);
        ChildP :=  ConvertSoapToNativeArrayElem(GetDynArrayNextInfo(ArrayInfo), ElemInfo, RootNode,
                     ChildNode, ArrayDesc, Dims, CurDim, PElem);
        PInteger(PElem)^ := Integer(ChildP);
        PElem := Pointer(Integer(PElem) + sizeof(Pointer));
      end;
    end;
  end else if Dims = 1 then
  begin
    begin
      Size := Node.ChildNodes.Count;
      if DataP <> nil then
      begin
        DynP := Pointer(PInteger(DataP)^);
        if Length(ArrayDesc) = 0 then
        begin
          SetLength(IntVec, 1);
          DimCnt := 1;
        end else
        begin
          SetLength(IntVec, Length(ArrayDesc[CurDim].Dims));
          DimCnt := Length(ArrayDesc[CurDim].Dims);
        end;
        for I := 0 to Length(IntVec) -1 do
          IntVec[I] := Size;
        DynArraySetLength(DynP, ArrayInfo, DimCnt,  PLongInt(IntVec) );
        PElem := DynP;
        Result := DynP;
        CurElem := 0;
        if Size > 0 then
          ReadRow(RootNode, Node, CurElem,  Size, PElem, ElemInfo);
      end;
    end;
  end;
end;

function TSOAPDomConv.ConvertSoapToNativeArray(DataP: Pointer;  TypeInfo: PTypeInfo;
  RootNode, Node: IXMLNode): Pointer;
var
  Dims: Integer;
  ElemInfo: PTypeInfo;
  ArrayDesc: TSOAPArrayDesc;
  ArrayType: InvString;
  V : Variant;
  TypeURI, TypeName: InvString;
  S: String;
  ArrayLen: Integer;
  DynP: Pointer;
begin
  GetElementType(Node, TypeURI, TypeName);
  GetDynArrayElTypeInfo(TypeInfo, ElemInfo, Dims);
  if ElemInfo = nil then
    raise  ESOAPDomConvertError.CreateFmt(SNoArrayElemRTTI, [TypeInfo.Name]);
  if (Dims = 1) and
     ((ElemInfo.Kind = tkInteger) or (ElemInfo.Kind = tkChar)) and
     (GetTypeData(ElemInfo).OrdType = otUByte) and
     (({(TypeURI = SXMLSchemaURI_2001) and }(TypeName = 'base64Binary')) or
      ((TypeURI = SSoap11EncodingS5) and (TypeName = 'base64'))) then
  begin
    S := DecodeString(Node.Text);
    ArrayLen := Length(S);
    DynP := Pointer(PInteger(DataP)^);
    DynArraySetLength(DynP, TypeInfo, 1, @ArrayLen);
    Move(S[1], DynP^, Length(S));
    Result := DynP;
  end else
  begin
    V := Node.GetAttributeNS(SSoapEncodingArrayType, SSoap11EncodingS5);
    if not VarIsNull(V) then
    begin
      ArrayType := V;
      ArrayType := Copy(ArrayType, Pos('[',ArrayType), High(Integer));     { do not localize }
    end;

    if ElemInfo.Kind = tkVariant then
    begin
      SetLength(ArrayDesc, 1);
      SetLength(ArrayDesc[0].Dims, 1);
    end else
    begin
      ParseDims(ArrayType, ArrayDesc);
    end;
    Result := ConvertSoapToNativeArrayElem(TypeInfo, ElemInfo, RootNode, Node, ArrayDesc, Dims, 0, DataP);
  end;
end;

function TSOAPDomConv.GetNewID: string;
begin
  Result := IntToStr(FIDs);
  Inc(FIDs);
end;

function TSOAPDomConv.CreateMultiRefNode(RootNode: IXMLNode; Name, ID: InvString): IXMLNode;
var
  I, J: Integer;
begin
  Result := RootNode.OwnerDocument.CreateNode(Name);
  Result.Attributes[SXMLID] := ID;
  I := 0;
  while I < Length(MultiRefNodes) do
  begin
    if MultiRefNodes[I].Node = RootNode then
      break;
    Inc(I);
  end;
  if I = Length(MultiRefNodes) then
  begin
    SetLength(MultiRefNodes, I + 1);
    MultiRefNodes[I].Node := RootNode;
  end;
  J := Length(MultiRefNodes[I].MultiRefChildren);
  SetLength(MultiRefNodes[I].MultiRefChildren, J + 1);
  MultiRefNodes[I].MultiRefChildren[J] := Result;
end;

procedure TSOAPDomConv.FinalizeMultiRefNodes;
var
  I, J: Integer;
  RootNode: IXMLNode;
  RefNode: IXMLNode;
begin
  for I := 0 to Length(MultiRefNodes) - 1 do
  begin
    for J := 0 to Length(MultiRefNodes[I].MultiRefChildren) - 1 do
    begin
      RootNode := MultiRefNodes[I].Node;
      
      { Root ref nodes at the body }
      if (soRootRefNodesToBody in Options) then
        RootNode := RootNode.ParentNode;

      { Get Ref node and add }
      RefNode :=  MultiRefNodes[I].MultiRefChildren[J];
      RootNode.ChildNodes.Add(RefNode);
    end;
  end;
  for I := 0 to Length(MultiRefNodes) - 1 do
  begin
    SetLength(MultiRefNodes[I].MultiRefChildren, 0);
  end;
  SetLength(MultiRefNodes, 0);
end;

function GetOrdPropEx(Instance: TObject; PropInfo: PPropInfo): Longint;
asm
        { ->    EAX Pointer to instance         }
        {       EDX Pointer to property info    }
        { <-    EAX Longint result              }

        PUSH    EBX
        PUSH    EDI
        MOV     EDI,[EDX].TPropInfo.PropType
        MOV     EDI,[EDI]
        MOV     BL,otSLong
        CMP     [EDI].TTypeInfo.Kind,tkClass
        JE      @@isClass
        CMP     [EDI].TTypeInfo.Kind,tkDynArray
        JE      @@isDynArray
        CMP     [EDI].TTypeInfo.Kind,tkInterface
        JE      @@isInterface
        XOR     ECX,ECX
        MOV     CL,[EDI].TTypeInfo.Name.Byte[0]
        MOV     BL,[EDI].TTypeInfo.Name[ECX+1].TTypeData.OrdType
@@isDynArray:
@@isInterface:
@@isClass:
        MOV     ECX,[EDX].TPropInfo.GetProc
        CMP     [EDX].TPropInfo.GetProc.Byte[3],$FE
        MOV     EDX,[EDX].TPropInfo.Index
        JB      @@isStaticMethod
        JA      @@isField

        {       the GetProc is a virtual method }
        MOVSX   ECX,CX                  { sign extend slot offs }
        ADD     ECX,[EAX]               { vmt   + slotoffs      }
        CALL    dword ptr [ECX]         { call vmt[slot]        }
        JMP     @@final

@@isStaticMethod:
        CALL    ECX
        JMP     @@final

@@isField:
        AND     ECX,$00FFFFFF
        ADD     ECX,EAX
        MOV     AL,[ECX]
        CMP     BL,otSWord
        JB      @@final
        MOV     AX,[ECX]
        CMP     BL,otSLong
        JB      @@final
        MOV     EAX,[ECX]
@@final:
        CMP     BL,otSLong
        JAE     @@exit
        CMP     BL,otSWord
        JAE     @@word
        CMP     BL,otSByte
        MOVSX   EAX,AL
        JE      @@exit
        AND     EAX,$FF
        JMP     @@exit
@@word:
        MOVSX   EAX,AX
        JE      @@exit
        AND     EAX,$FFFF
@@exit:
        POP     EDI
        POP     EBX
end;


procedure SetOrdPropEx(Instance: TObject; PropInfo: PPropInfo;
  Value: Longint); assembler;
asm
        { ->    EAX Pointer to instance         }
        {       EDX Pointer to property info    }
        {       ECX Value                       }

        PUSH    EBX
        PUSH    ESI
        PUSH    EDI
        MOV     EDI,EDX

        MOV     ESI,[EDI].TPropInfo.PropType
        MOV     ESI,[ESI]
        MOV     BL,otSLong
        CMP     [ESI].TTypeInfo.Kind,tkClass
        JE      @@isClass
        CMP     [ESI].TTypeInfo.Kind,tkDynArray
        JE      @@isDynArray
        CMP     [ESI].TTypeInfo.Kind,tkInterface
        JE      @@isInterface
        XOR     EBX,EBX
        MOV     BL,[ESI].TTypeInfo.Name.Byte[0]
        MOV     BL,[ESI].TTypeInfo.Name[EBX+1].TTypeData.OrdType
@@isDynArray:
@@isInterface:
@@isClass:
        MOV     EDX,[EDI].TPropInfo.Index       { pass Index in DX      }
        CMP     EDX,$80000000
        JNE     @@hasIndex
        MOV     EDX,ECX                         { pass value in EDX     }
@@hasIndex:
        MOV     ESI,[EDI].TPropInfo.SetProc
        CMP     [EDI].TPropInfo.SetProc.Byte[3],$FE
        JA      @@isField
        JB      @@isStaticMethod

        {       SetProc turned out to be a virtual method. call it      }
        MOVSX   ESI,SI                          { sign extend slot offset }
        ADD     ESI,[EAX]                       { vmt   + slot offset   }
        CALL    dword ptr [ESI]
        JMP     @@exit

@@isStaticMethod:
        CALL    ESI
        JMP     @@exit

@@isField:
        AND     ESI,$00FFFFFF
        ADD     EAX,ESI
        MOV     [EAX],CL
        CMP     BL,otSWord
        JB      @@exit
        MOV     [EAX],CX
        CMP     BL,otSLong
        JB      @@exit
        MOV     [EAX],ECX
@@exit:
        POP     EDI
        POP     ESI
        POP     EBX
end;


function TSOAPDomConv.MultiRefObject(Cls: TClass): Boolean;
var
  MultiRefOpt: TObjMultiOptions;
begin
  { Retrieve registered options of this type }
  MultiRefOpt :=  RemTypeRegistry.ClassOptions(Cls);
  { Are we multiref'in the node }
  Result := (soSendMultiRefObj in Options) and (MultiRefOpt <> ocNoMultiRef) and
            not (soDocument in Options);
end;

function TSOAPDomConv.CreateObjectNode(Instance: TObject; RootNode, Node: IXMLNode;
                                       Name,  URI: InvString; UsePrefix: Boolean): InvString;

var
  ID, Pre: InvString;
  I, Count: Integer;
  PropList: PPropList;
  Kind: TTypeKind;
  V: Variant;
  Obj: TObject;
  NodeURI, ElemURI, TypeName, NodeVal, AttrNodePre: InvString;
  IsScalar: Boolean;
  PrefixNode, InstNode, ElemNode, AttrNode: IXMLNode;
  P: Pointer;
  ExtPropName: InvString;
  MultiRef: Boolean;
  SerialOpts: TSerializationOptions;
  ClsType: TClass;
begin
  { Get a new ID for this node - in case we're MultiRefing... }
  Result := GetNewID;

  { Retrieve the Serializatin options of this class }
  SerialOpts := RemTypeRegistry.SerializeOptions(Instance.ClassType) +
                TRemotable(Instance).SerializationOptions;

  { Get namespace prefix }
  PrefixNode := RootNode;

  { Are we multiref'in the node }
  MultiRef := MultiRefObject(Instance.ClassType);

  { If we're multiref'ing and putting them on the body node, move the prefix one up }
  if MultiRef and (soRootRefNodesToBody in Options) and (PrefixNode.ParentNode <> nil) then
    PrefixNode := PrefixNode.ParentNode;

  { No prefix in document style - or if flag set to false }
  if not (soDocument in Options) and UsePrefix then
    Pre := FindPrefixForURI(PrefixNode, Node,  URI, True)
  else
    Pre := '';

  { Create the Node, if necessary }
  if not (xoHolderClass in SerialOpts) then
  begin
    if not MultiRef then
    begin
      if (soDocument in Options) then
        InstNode := Node.AddChild(Name)
      else
      begin
        if UsePrefix or (Pre <> '') then
          InstNode := Node.AddChild(MakeNodeName(Pre, Name))
        else
          { Create a node without any prefix }
          InstNode := Node.AddChild(MakeNodeName(Pre, Name), '');
      end;
    end
    else
      InstNode := CreateMultiRefNode(RootNode, MakeNodeName(Pre, Name), Result);
  end
  else
    InstNode := Node;

  { Retrieve Type Namespace }
  RemClassRegistry.ClassToURI(Instance.ClassType, NodeURI, TypeName, IsScalar);

  SetNodeType(PrefixNode, InstNode, NodeURI, TypeName);

  { Store info that we multi refed' }
  if MultiRef  then
    AddMultiRefNode(Result, Instance);

  Count := GetTypeData(Instance.ClassInfo)^.PropCount;
  if Count > 0 then
  begin
    GetMem(PropList, Count * SizeOf(Pointer));
    try
      GetPropInfos(Instance.ClassInfo, PropList);
      for I := 0 to Count - 1 do
      begin
        ExtPropName := RemTypeRegistry.GetExternalPropName(Instance.ClassInfo, PropList[I].Name);
        Kind := (PropList[I].PropType)^.Kind;
        if Kind = tkClass then
        begin
          Obj := GetObjectProp(Instance, PropList[I]);
          if Obj = nil then
          begin
            if not (soDontSendEmptyNodes in Options) then
              CreateNULLNode(RootNode, InstNode, ExtPropName)
          end
          else
          begin
            ClsType := GetTypeData((PropList[I].PropType)^).ClassType;
            RemClassRegistry.ClassToURI(ClsType, ElemURI, TypeName, IsScalar);
            MultiRef := MultiRefObject(ClsType);

            if IsScalar then
            begin
              ElemNode := InstNode.AddChild(ExtPropName);
              if not RemTypeRegistry.TypeInfoToXSD((PropList[I].PropType)^, ElemURI, TypeName) then
                raise ESOAPDomConvertError.CreateFmt(SRemTypeNotRegistered,[GetTypeData((PropList[I].PropType)^).ClassType.ClassName]);
              if not GetTypeData((PropList[I].PropType)^).ClassType.InheritsFrom(TRemotable) then
                raise ESOAPDomConvertError.CreateFmt(SScalarFromTRemotableS, [GetTypeData((PropList[I].PropType)^).ClassType.ClassName]);
{$IFDEF OPENDOM}
              ElemNode.SetAttributeNS(SSoapType, XMLSchemaInstNameSpace, TypeName);
{$ELSE}
              AttrNodePre := FindPrefixForURI(RootNode, Node, XMLSchemaInstNamespace);
              ElemNode.Attributes[MakeNodeName(AttrNodePre, SSoapType)] := TypeName;
{$ENDIF}
              ElemNode.Text := TRemotableXS(Obj).NativeToXS;
            end
            else
            begin
              if not MultiRef then
              begin
                if IsObjectWriting(Obj) then
                  raise ESOAPDomConvertError.Create(SNoSerializeGraphs);
                AddObjectAsWriting(Instance);
                { NOTE: No prefix for nested types }
                CreateObjectNode(Obj, RootNode, InstNode, ExtPropName, ElemURI, False);
                RemoveObjectAsWriting(Obj);
              end else
              begin
                ElemNode := InstNode.AddChild(ExtPropName, '');
                ID := FindMultiRefNodeByInstance(Obj);
                { NOTE: No prefix for nested types }
                if ID = '' then
                  ID := CreateObjectNode(Obj, RootNode, InstNode, ExtPropName, ElemURI, False);
                ElemNode.Attributes[SXMLHREF] := SHREFPre + ID;
              end;
            end;
          end;
        end else if Kind = tkDynArray then
        begin
          P := Pointer(GetOrdPropEx(Instance, PropList[I]));
          ConvertNativeArrayToSoap(RootNode, InstNode, ExtPropName,
                                   (PropList[I].PropType)^, P, 0,
                                   (xoInlineArrays in SerialOpts));
        end else if Kind = tkVariant then
        begin
           V := GetVariantProp(Instance, PropList[I]);
           ConvertVariantToSoap(RootNode, InstNode, ExtPropName, nil, nil, 0, V, True);
        end else
        begin
          if not RemTypeRegistry.TypeInfoToXSD((PropList[I].PropType)^, ElemURI, TypeName) then
            raise ESOAPDomConvertError.CreateFmt(SRemTypeNotRegistered, [(PropList[I].PropType)^.Name]);
          { Here we check the stored property flag - that's the flag to use an
            attribute instead of a separate node - if the property is marked
            stored False, we'll use an attribute instead }
          if not IsStoredProp(Instance, PropList[I]) then
          begin
            { Typically attributes go on the root/instance node. However, in some
              cases the class serializes members and then the attribute goes on
              the last member; this option allows attributes on specific members }
            AttrNode := InstNode;
            if (xoAttributeOnLastMember in SerialOpts) then
            begin
              if InstNode.ChildNodes.Count > 0 then
                AttrNode := InstNode.ChildNodes[InstNode.ChildNodes.Count-1];
            end;
            AttrNode.Attributes[ExtPropName] := GetObjectPropAsText(Instance, PropList[I]);
          end
          else
          begin
            NodeVal := GetObjectPropAsText(Instance, PropList[I]);
            { Check if user does not want to send empty nodes }
            if (not (soDontSendEmptyNodes in Options)) or (NodeVal <> '') then
              ElemNode := CreateScalarNodeXS(RootNode, InstNode, ExtPropName, ElemURI, TypeName, NodeVal);
          end;
        end;
      end;
    finally
      FreeMem(PropList, Count * SizeOf(Pointer));
    end;
  end;
end;

procedure TSOAPDomConv.ConvertObjectToSOAP(Name: InvString;
  ObjP: Pointer; RootNode, Node: IXMLNOde; NumIndirect: Integer);
var
  ElemNode: IXMLNOde;
  I: Integer;
  ID: string;
  URI, TypeName: WideString;
  IsScalar: Boolean;
  P: Pointer;
  Instance: TObject;
  MultiRef: Boolean;
begin
  P := ObjP;
  for I := 0 to NumIndirect - 1 do
    P := Pointer(PInteger(P)^);
  Instance := P;

  if Assigned(Instance) and not Instance.InheritsFrom(TRemotable) then
    raise ESOAPDomConvertError.CreateFmt(SUnsuportedClassType, [Instance.ClassName]);

  if not Assigned(Instance) then
    CreateNULLNode(RootNode, Node, Name)
  else
  begin
    if not RemClassRegistry.ClassToURI(Instance.ClassType, URI, TypeName, IsScalar) then
      raise ESOAPDomConvertError.CreateFmt(SRemTypeNotRegistered, [Instance.ClassName]);
    if IsScalar then
    begin
      if not Instance.ClassType.InheritsFrom(TRemotableXS) then
        raise ESOAPDomConvertError.CreateFmt(SScalarFromTRemotableS, [Instance.ClassType.ClassName]);

      ElemNode := CreateScalarNodeXS(RootNode, Node, Name, URI, TypeName, TRemotableXS(Instance).NativeToXS, True);
    end else
    begin
      MultiRef := MultiRefObject(Instance.ClassType);
      if not MultiRef then
      begin
        if IsObjectWriting(Instance) then
          raise ESOAPDomConvertError.Create(SNoSerializeGraphs);
        AddObjectAsWriting(Instance);
        { NOTE: Passing 'True' to prefix here can cause problems with some
                SOAP implementations. However, passing 'False' cause problems
                too ?? }
        CreateObjectNode(Instance, RootNode, Node, Name, URI, False);
        RemoveObjectAsWriting(Instance);
      end
      else
      begin
        ID := FindMultiRefNodeByInstance(Instance);
        { NOTE: Passing 'True' to prefix here can cause problems with some
                SOAP implementations. However, removing it can cause problems
                too ?? }
        if ID = '' then
          { The ref'ed node must be of the TypeName - not the referring node name }
          { ID := CreateObjectNode(Instance, RootNode, ElemNode, Name, URI); }
          ID := CreateObjectNode(Instance, RootNode, ElemNode, TypeName, URI, True);
        ElemNode := Node.AddChild(Name, '' {No Namespace prefix});
        ElemNode.Attributes[SXMLHREF] := SHREFPre + ID;
      end;

    end;
  end;
end;


function TSOAPDomConv.GetObjectPropAsText(Instance: TObject;
  PropInfo: PPropInfo): WideString;
var
 I: LongInt;
 E: Extended;
 I64: Int64;
begin
  case (PropInfo.PropType)^.Kind of
    tkInteger:
      begin
        I := GetOrdProp(Instance, PropInfo);
        Result := IntToStr(I);
      end;
    tkFloat:
      begin
        E := GetFloatProp(Instance, PropInfo);
        Result := FloatToStrEx(E);
      end;
    tkWString:
      Result := GetWideStrProp(Instance, PropInfo);
    tkString,
    tkLString:
      Result := GetStrProp(Instance, PropInfo);
    tkInt64:
      begin
        I64 := GetInt64Prop(Instance, PropInfo);
        Result := IntToStr(I64);
      end;
    tkEnumeration:
      Result := GetEnumProp(Instance, PropInfo);
    tkChar:
      begin
        I := GetOrdProp(Instance, PropInfo);
        Result :=  InvString(Char(I));
      end;
    tkWChar:
      begin
        I := GetOrdProp(Instance, PropInfo);
        Result :=  InvString(WideChar(I));
      end;
    tkClass:
      ;
    tkSet,
    tkMethod,

    tkArray,
    tkRecord,
    tkInterface,


    tkDynArray,
    tkVariant:
      raise ESOAPDomConvertError.CreateFmt(SUnexpectedDataType, [KindNameArray[(PropInfo.PropType)^.Kind]]); 

  end;

end;

function TSOAPDomConv.GetTypeBySchemaNS(Node: IXMLNode; URI: InvString): Variant;
var
  I: Integer;
begin
  Result := Node.GetAttributeNS(SSoapType, URI);
  if VarIsNull(Result) and (soTryAllSchema in Options) then
  begin
    for I := Low(XMLSchemaInstNamepspaces) to High(XMLSchemaInstNamepspaces) do
    begin
      Result := Node.GetAttributeNS(SSoapType, XMLSchemaInstNamepspaces[I]);
      if not VarIsNull(Result) then
        break;
    end;
  end;
end;

function TSOAPDomConv.GetElementType(Node: IXMLNode; var TypeURI, TypeName: InvString): Boolean;
var
  Idx: Integer;
  S : InvString;
  V: Variant;
  Pre: InvString;
begin
  TypeURI := '';
  TypeName := '';
  Result := False;
  if (Node.NamespaceURI = SSoap11EncodingS5) and
     (ExtractLocalName(Node.NodeName) = SSoapEncodingArray) then
  begin
    TypeURI := SSoap11EncodingS5;
    TypeName := SSoapEncodingArray;
    Result := True;
  end else
  begin
    V := GetTypeBySchemaNS(Node, XMLSchemaInstNameSpace);
    if VarIsNull(V) then
      V := Node.GetAttribute(SSoapType);
    if not VarIsNull(V) then
    begin
      S := V;
      Idx := Pos(':', S);  { do not localize }
      if Idx <> 0 then
      begin
        TypeName := Copy(S, Idx + 1, High(Integer));
        Pre := Copy(S, 1, Idx - 1);
        TypeURI := Node.FindNamespaceURI(Pre);
      end
      else
      begin
        TypeName := S;
        TypeURI := '';
      end;
      Result := True;
    end;
  end
end;

procedure TSOAPDomConv.SetObjectPropFromText(Instance: TObject; PropInfo: PPropInfo; SoapData: WideString);
var
 I: LongInt;
 E: Extended;
 I64: Int64;
begin
  case (PropInfo.PropType)^.Kind of
    tkInteger:
      begin
        I := StrToInt(SoapData);
        SetOrdProp(Instance, PropInfo, I);
      end;
    tkFloat:
      begin
        E := StrToFloatEx(SoapData);
        SetFloatProp(Instance, PropInfo, E);
      end;
    tkWString:
      SetWideStrProp(Instance, PropInfo, SoapData);
    tkString,
    tkLString:
       SetStrProp(Instance, PropInfo, SoapData);

    tkInt64:
      begin
        I64 := StrToInt64(SoapData);
        SetInt64Prop(Instance, PropInfo, I64);
      end;
    tkEnumeration:
      SetEnumProp(Instance, PropInfo, SoapData);
    tkChar,
    tkWChar:
      if SoapData <> '' then
        SetOrdProp(Instance, PropInfo, Integer(SoapData[1]));
    tkClass:
      ;
    tkSet,
    tkMethod,
    tkArray,
    tkRecord,
    tkInterface,
    tkDynArray,
    tkVariant:
      raise ESOAPDomConvertError.CreateFmt(SUnexpectedDataType, [KindNameArray[(PropInfo.PropType)^.Kind]]);

  end;
end;

{ This routine is no-op; it's just a convenient way to find out if a particular
  member of a class did not get deserialize off the wire }
procedure NoShow(MemberName: string);
begin
end;

procedure TSOAPDomConv.LoadObject(Instance: TObject; RootNode, Node: IXMLNode);
var
  PropList: PPropList;
  Count: Integer;
  Kind: TTypeKind;
  I, K: Integer;
  Obj: TObject;
  IsNull: Boolean;
  URI, TypeName, ChildNodeName: InvString;
  ChildNode: IXMLNode;
  ArrayPtr: Pointer;
  V: Variant;
  SoapTypeInfo: PTypeInfo;
  DT: TXSDateTime;
  InternalName: string;
  SerialOpts: TSerializationOptions;
begin
  {
    If the object that we're streaming into is really just for serialization
    purposes - i.e. an object that roots it members to its parent node instead
    of creating a node for itself, here then we should back node up to its parent.
    Adjust for shell that actually wrap arrays whose members are inline or shells
    that are the types of literal parts....
  }
  SerialOpts := RemTypeRegistry.SerializeOptions(Instance.ClassType) +
                TRemotable(Instance).SerializationOptions;
  if (xoHolderClass in SerialOpts) then
    if not (xoInlineArrays in SerialOpts) or (xoLiteralParam in SerialOpts) then
      Node := Node.ParentNode;

  Count := GetTypeData(Instance.ClassInfo)^.PropCount;
  if Count > 0 then
  begin
    GetMem(PropList, Count * SizeOf(Pointer));
    try
      { Iterate through properties matching them to nodes or attributes }
      GetPropInfos(Instance.ClassInfo, PropList);
      for I := 0 to Count - 1 do
      begin
        K := 0;
        while K < Node.ChildNodes.Count do
        begin
          ChildNode := Node.ChildNodes[K];
          ChildNodeName := ExtractLocalName(ChildNode.NodeName);
          InternalName := RemTypeRegistry.GetInternalPropName(Instance.ClassInfo, ChildNodeName);
          { NOTE: Here we assume properties are not case-sensitive!! So, if you're
                  in a case-sensitive environment, make sure each member is
                  unique in a case-insensitive way }
          if SameText(InternalName, PropList[I].Name) then
            break;
          Inc(K);
        end;

        { Retrieve type of this property }
        Kind := (PropList[I].PropType)^.Kind;

        { This property did not match any Child node - try attributes }
        { NOTE: We only do this for simple types }
        if K >= Node.ChildNodes.Count then
        begin
          if (Kind <> tkClass) and (Kind <> tkDynArray) and
             (Kind <> tkVariant) then
          begin
            if Node.HasAttribute(PropList[I].Name) then
            begin
              SetObjectPropFromText(Instance, PropList[I],
                                    Node.Attributes[PropList[I].Name]);
            end
            else
            begin
              { Here something we were expecting did *NOT* come down the wire ?? }
              NoShow(PropList[I].Name);
            end;
          end;

          { Go to next property... }
          continue;
        end;

        { Here we match the property to a Child Node }
        if Kind = tkClass then
        begin
          Obj := ConvertSOAPToObject(RootNode, ChildNode, GetTypeData((PropList[I].PropType)^).ClassType,
            '', '', nil, 0);
          if Obj <> nil then
            SetObjectProp(Instance, PropList[I], Obj);
        end else if Kind = tkDynArray then
        begin
          IsNull := NodeIsNull(ChildNode);
          { In document mode, the node could have attributes that we want to retrieve }
          if (not IsNull) or (soDocument in Options) then
          begin
            GetElementType(ChildNode, URI, TypeName);
            ArrayPtr := nil;
            { Here if the object we're writing to inlines members, then here we pass a parent node }
            if (xoinlineArrays in SerialOpts) then
              ChildNode := ChildNode.ParentNode;
            ArrayPtr := ConvertSoapToNativeArray(@ArrayPtr, (PropList[I].PropType)^,
                                                 RootNode,  ChildNode);
            SetOrdPropEx(Instance, PropList[I], Integer(ArrayPtr));
          end;
        end else if Kind = tkVariant then
        begin
          if ChildNode.ChildNodes.Count > 1 then
            V := ReadVarArrayDim(ChildNode)
          else
          begin
            if NodeIsNull(ChildNode) then
              V := NULL
            else
            begin
              GetElementType(ChildNode, URI, TypeName);
              SoapTypeInfo := RemTypeRegistry.XSDToTypeInfo(URI, TypeName);
              if SoapTypeInfo = nil then
                SoapTypeInfo := TypeInfo(System.WideString);
              if (SoapTypeInfo.Kind = tkClass) and (GetTypeData(SoapTypeInfo).ClassType = TXSDateTime) then
              begin
                DT := TXSDateTime.Create;
                DT.XSToNative(ChildNode.Text);
                V := DT.AsDateTime;
                DT.Free;
              end else
                V := TypeTranslator.CastSoapToVariant(SoapTypeInfo, ChildNode.Text);
            end;
          end;
          SetVariantProp(Instance, PropList[I], V);
        end else
          SetObjectPropFromText(Instance, PropList[I], ChildNode.Text);
      end;
    finally
      FreeMem(PropList, Count * SizeOf(Pointer));
    end;
  end;
end;


function  TSOAPDomConv.ConvertSOAPToObject(RootNode, Node: IXMLNode; AClass: TClass;
  URI, TypeName: WideString; ObjP: Pointer; NumIndirect: Integer): TObject;
var
  ID: InvString;
  ObjNode: IXMLNode;
  IsScalar: Boolean;
  Obj, LoadedObj: TObject;
  P: Pointer;
  I: Integer;
  NodeClass: TClass;
  NodeURI, NodeTypeName: InvString;
  LegalRef: Boolean;
  S: string;
begin
  { NOTE: In document mode a node could contain attributes that we want to retrieve }
  if NodeIsNULL(Node) and not (soDocument in Options) then
  begin
    Result := nil;
    Exit;
  end;

  P := ObjP;
  for I := 0 to NumIndirect - 1 do
    P := Pointer(PInteger(P)^);
  Obj := TObject(P);

  { Scalar nodes simply need the text of the node }
  IsScalar := RemClassRegistry.IsClassScalar(AClass);
  if IsScalar then
  begin
    if not AClass.InheritsFrom(TRemotableXS) then
        raise ESOAPDomConvertError.CreateFmt(SScalarFromTRemotableS, [AClass.ClassName]);
      Obj := TRemotableXSClass(AClass).Create;
      Result := Obj;
    TRemotableXS(Obj).XSToNative(Node.Text);
  end else
  begin
    S := ExtractLocalName(Node.NodeName);
    ObjNode := GetDataNode(RootNode, Node, ID);
    if ID <> '' then
      LoadedObj :=  FindMultiRefNodeByID(ID)
    else
      LoadedObj := nil;

    if Assigned(LoadedObj) then
      Result := LoadedObj
    else
    begin
      GetElementType(ObjNode, NodeURI, NodeTypeName);
      NodeClass := RemTypeRegistry.URIToClass(NodeURI, NodeTypeName, IsScalar);
      LegalRef := True;
      if Assigned(Obj) then
      begin
        try
          if Obj.ClassType <> nil then
            LegalRef := True;
        except
          LegalRef := False;
        end;
      end;
      if Assigned(Obj) and  LegalRef then
      begin
        if (NodeClass <> nil) and (NodeClass <> Obj.ClassType) then
          Obj := NodeClass.Create;
      end else
      begin
        if (NodeClass <> nil) and NodeClass.InheritsFrom(AClass) then
          Obj := TRemotableClass(NodeClass).Create
        else
          Obj := TRemotableClass(AClass).Create;
      end;
      Result := Obj;
      AddMultiRefNode(ID, Obj);
      LoadObject(Obj, RootNode, ObjNode);
    end;
  end;
end;


procedure  TSOAPDomConv.WriteNonRectDynArray(RootNode, Node: IXMLNode; Name: InvString; Info: PTypeInfo; URI,  TypeName: InvString; P: Pointer; Dims: Integer);
var
  I, Len: Integer;
  ArrayDims: TIntegerDynArray;
  ElemNode, DataNode: IXMLNode;
  ID: Integer;
begin
  Len := GetDynArrayLength(P);
  SetLength(ArrayDims, Dims);
  for I := 0 to Dims -2 do
    ArrayDims[I] := 0;
  ArrayDims[Dims-1] := Len;
  ElemNode := MakeArrayNode(Node, Node,   Name, URI, TypeName, ArrayDims);

  for I := 0 to Len - 1 do
  begin
    ID := WriteNonRectDynArrayElem(Node, ElemNode, Info, URI, TypeName, Pointer( PInteger(P)^),  Dims-1);
    if ID <> 0 then
    begin
      DataNode := ElemNode.AddChild(DefArrayElemName); { Namespace prefix ?? (BB) }
      DataNode.Attributes[SXMLHREF] := SHREFPre + SArrayIDPre + IntToStr(ID);
    end;
    P := Pointer(Integer(P) + sizeof(Pointer));
  end;
end;


procedure TSOAPDomConv.ConvertNativeArrayToSoap(RootNode,
  Node: IXMLNode; Name: InvString; Info: PTypeInfo; P: Pointer; NumIndirect: Integer; InlineElements: Boolean);
var
  ElemInfoP: PTypeInfo;
  Dims, I: Integer;
  DimAr: TIntegerDynArray;
  URI, TypeName: InvString;
  ElemNode: IXMLNode;
  S, S1: String;
  ElemInfo: PTypeInfo;
begin
  for I := 0 to NumIndirect - 1 do
    P := Pointer(PInteger(P)^);
  Dims := 0;
  GetDynArrayElTypeInfo(Info, ElemInfoP, Dims);
  if (ElemInfoP.Kind <> tkVariant) and not RemTypeRegistry.TypeInfoToXSD(ElemInfoP, URI, TypeName) then
      raise ESOAPDomConvertError.CreateFmt(SRemTypeNotRegistered, [ElemInfoP.Name]);
  if not Assigned(P) or IsArrayRect(P, Dims) then
  begin
    SetLength(DimAr, Dims);
    if Assigned(P) then
      GetDims(P, DimAr, Dims);
    GetDynArrayElTypeInfo(Info, ElemInfo, Dims);
    { Array of bytes is handled separately - serialized as base64 }
    if (Dims = 1) and
       ((ElemInfo.Kind = tkInteger{P}) or (ElemInfo.Kind = tkChar{C++})) and
       (GetTypeData(ElemInfo).OrdType = otUByte) then
    begin
      SetLength(S, GetDynArrayLength(P));
      Move(P^, S[1], Length(S));
      S1 :=  EncodeString(S);
      CreateScalarNodeXS(RootNode, Node, Name, XMLSchemaNamespace, 'base64Binary', S1);
    end else
    begin
      if not InlineElements then
      begin
        ElemNode := MakeArrayNode(RootNode, Node,  Name, URI, TypeName, DimAr);
      end
      else
      begin
        { If we're inlining the array, we'll use the name passed in for each element }
        ElemNode := Node;
        TypeName := Name;
      end;
      WriteRectDynArray(RootNode, ElemNode, ElemInfoP, Dims, P, TypeName);
      { Not exactly optimal approach - but works for now -
        Check if user does not want to send empty nodes and snip
        this node if it has no child nodes - another approach would
        be not to parent the array node and wait until we know but... ?? }
      if (soDontSendEmptyNodes in Options) and
         (ElemNode.ChildNodes.Count < 1) then
      begin
        Node.ChildNodes.Delete(Node.ChildNodes.IndexOf(ElemNode));
      end;
    end;
  end else
  begin
    WriteNonRectDynArray(RootNode, Node, Name, ElemInfoP, URI, TypeName, P, Dims);
    { NOTE: For now I'm not putting the snip empty node code in non rectangular
            arrays as there has not been a need for this here yet }
  end;
end;


procedure TSOAPDomConv.ConvertNativeDataToSoap(
  RootNode, Node: IXMLNode; Name: InvString; Info: PTypeInfo; P: Pointer; NumIndirect: Integer);
var
  ElemNode: IXMLNode;
  TypeName: InvString;
  URI, S: InvString;
  IsNull: Boolean;
  I: Integer;
  IsScalar: Boolean;
begin
  case Info.Kind of
    tkClass:
      ConvertObjectToSOAP(Name, P, RootNode, Node, NumIndirect);
    tkDynArray:
      ConvertNativeArrayToSoap(RootNode, Node, Name, Info, P, NumIndirect);
    tkSet,
    tkMethod,
    tkArray,
    tkRecord,
    tkInterface:
      raise ESOAPDomConvertError.CreateFmt(SDataTypeNotSupported, [KindNameArray[Info.Kind]]);

    tkVariant:
    begin
      ConvertVariantToSoap(RootNode, Node, Name, Info, P, NumIndirect, NULL, False);
    end;
    else
    begin
      if Info.Kind = tkEnumeration then
      begin
        if not RemClassRegistry.InfoToURI(Info, URI, TypeName, IsScalar) then
          raise ESOAPDomConvertError.CreateFmt(SRemTypeNotRegistered, [Info.Name]);
        S := ConvertEnumToSoap(Info, P, NumIndirect);
        ElemNode := CreateScalarNodeXS(RootNode, Node, Name, URI, TypeName, S);
      end else
      begin
        if NumIndirect > 1 then
          for I := 0 to NumIndirect - 2 do
            P := Pointer(PInteger(P)^);
        TypeTranslator.CastNativeToSoap(Info, S, P, IsNull);
        if IsNull then
          CreateNULLNode(RootNode,ElemNode, Name)
        else
        begin
          if not RemTypeRegistry.TypeInfoToXSD(Info, URI, TypeName) then
            raise ESOAPDomConvertError.CreateFmt(SRemTypeNotRegistered, [Info.Name]);
          ElemNode := CreateScalarNodeXS(RootNode, Node, Name, URI, TypeName, S);
        end;
      end
    end;
  end;
end;


procedure TSOAPDomConv.AddMultiRefNode(ID: string; Instance: Pointer);
var
  I: Integer;
begin
  for I := 0 to Length(RefMap) -1  do
    if (RefMap[I].ID = ID) and ( RefMap[I].Instance = Instance) then
      Exit;
  I := Length(RefMap);
  SetLength(RefMap, I + 1);
  RefMap[I].ID := ID;
  RefMap[I].Instance :=Instance;
end;

function  TSOAPDomConv.FindMultiRefNodeByInstance(Instance: Pointer): string;
var
  I: Integer;
begin
  for I := 0 to Length(RefMap) - 1 do
    if RefMap[I].Instance = Instance then
      Result := RefMap[I].ID;
end;


function  TSOAPDomConv.FindMultiRefNodeByID(ID: string): Pointer;
var
  I: Integer;
begin
  Result := nil;
  for I := 0 to Length(RefMap) - 1 do
    if RefMap[I].ID = ID then
    begin
      Result := RefMap[I].Instance;
      break;
    end;
end;


procedure TSOAPDomConv.ConvertSoapToNativeData(DataP: Pointer; TypeInfo: PTypeInfo;
  Context: TDataContext; RootNode, Node: IXMLNode; Translate, ByRef: Boolean;
  NumIndirect: Integer);
var
  TypeUri, TypeName: InvString;
  IsNull: Boolean;
  Obj: TObject;
  P: Pointer;
  I: Integer;
  ID: InvString;
begin
  Node := GetDataNode(RootNode, Node, ID);
  IsNull := NodeIsNull(Node);
  if TypeInfo.Kind = tkVariant then
  begin
    if NumIndirect > 1 then
      DataP := Pointer(PInteger(DataP)^);
    if IsNull then
    begin
      Variant(PVarData(DataP)^) := NULL;
    end else
      ConvertSoapToVariant(Node, DataP);
  end else
  if TypeInfo.Kind = tkDynArray then
  begin
    P := DataP;
    for I := 0 to NumIndirect - 2 do
      P := Pointer(PInteger(P)^);
    P := ConvertSoapToNativeArray(P, TypeInfo, RootNode, Node);
    if NumIndirect = 1 then
      PInteger(DataP)^ := Integer(P)
    else if NumIndirect = 2 then
    begin
      DataP := Pointer(PInteger(DataP)^);
      PInteger(DataP)^ := Integer(P);
    end;
  end else
  if TypeInfo.Kind = tkClass then
  begin
    Obj := ConvertSOAPToObject(RootNode, Node, GetTypeData(TypeInfo).ClassType, TypeURI, TypeName, DataP, NumIndirect);
    if NumIndirect = 1 then
      PTObject(DataP)^ := Obj
    else if NumIndirect = 2 then
    begin
      DataP := Pointer(PInteger(DataP)^);
      PTObject(DataP)^ := Obj;
    end;
  end else
  begin
    if Translate then
    begin
      if NumIndirect > 1 then
        DataP := Pointer(PInteger(DataP)^);
      if not TypeTranslator.CastSoapToNative(TypeInfo, GetNodeAsText(Node), DataP, IsNull) then
        raise ESOAPDomConvertError.CreateFmt(STypeMismatchInParam, [node.nodeName]);
    end;
  end;
end;


function TSOAPDomConv.ConvertEnumToSoap(Info: PTypeInfo;
  P: Pointer; NumIndirect: Integer): InvString;
var
  Value: Pointer;
  I: Integer;
begin
  Value := P;
  for I := 0 to NumIndirect - 2 do
    Value := Pointer(PInteger(Value)^);
  if NumIndirect = 0 then
    Result := GetEnumName(Info, Byte(Value))
  else
    Result := GetEnumName(Info, PByte(Value)^);
  { NOTE: No need to use SameTypeInfo here since C++ has proper case }    
  if Info = TypeInfo(System.Boolean) then
    Result := Lowercase(Result);
end;


function TSOAPDomConv.ConvertSoapToEnum(Info: PTypeInfo; S: InvString;
  IsNull: Boolean): Integer;
begin
  Result := GetEnumValueEx(Info, S);
end;


function TSOAPDomConv.CreateNULLNode(RootNode, ParentNode: IXMLNode; Name: InvString; UseParentNode: Boolean): IXMLNode;
begin
  if not UseParentNode then
    Result := ParentNode.AddChild(Name)
  else
    Result := ParentNode;
  SetAttributeNS(RootNode, Result, SSoapNULL, XMLSchemaInstNameSpace, 'true');
end;


function TSOAPDomConv.NodeIsNULL(Node: IXMLNode): Boolean;
var
  V: Variant;
begin
  Result := False;
  V := Node.GetAttributeNS(SSoapNull, XMLSchemaInstNameSpace);
  if not VarIsNull(V) and ((V = '1') or SameText(V,'True')) then   { do not lcoalize }
    Result := True;
  if Node.ChildNodes.Count = 0 then
  begin
    V := Node.Attributes[SXMLHREF];
    if  VarIsNull(V) then
      Result := True;
  end;
end;

function TSOAPDomConv.ChildNodesAreNull(Node: IXMLNode): Boolean;
var
  I: Integer;
  Child: IXMLNode;
begin
  Result := True;
  if Node.ChildNodes.Count > 0 then
  begin
    for I := 0 to Node.ChildNodes.Count-1 do
    begin
      Child := Node.ChildNodes[I];
      if Child.NodeType <> ntElement then
        continue; 
      if not NodeIsNull(Node.ChildNodes[I]) then
      begin
        Result := False;
        Exit;
      end;
    end;
  end;
end;

function TSOAPDomConv.FindPrefixForURI(RootNode, Node: IXMLNode; URI: InvString; DeclIfNone: Boolean = False): InvString;
var
  DeclNode: IXMLNode;
begin
  DeclNode := RootNode.FindNamespaceDecl(URI);
  if DeclNode <> nil then
    Result := ExtractLocalName(DeclNode.NodeName);
  if (Result = '') and DeclIfNone then
    Result := AddNamespaceDecl(RootNode, URI);
end;

function TSOAPDomConv.AddNamespaceDecl(Node: IXMLNode; URI: InvString): InvString;
begin
  Result := Node.OwnerDocument.GeneratePrefix(Node);
  Node.DeclareNamespace(Result, URI);
end;

procedure TSOAPDomConv.SetAttributeNS(RootNode, Node: IXMLNode; Attr: InvString; NS: InvString; Value: InvString);
{$IFDEF MSXMLDOM}
var
  Prefix: InvString;
begin
  Prefix := FindPrefixForURI(RootNode, Node, NS, True);
  Node.Attributes[MakeNodeName(Prefix, Attr)] := Value;
{$ELSE}
begin
  Node.SetAttributeNS(Attr, NS, Value);
{$ENDIF}
end;

function TSOAPDomConv.CreateTypedNode(RootNode, ParentNode: IXMLNode;
   NodeName, URI, TypeName: WideString; GenPre: Boolean = False): IXMLNode;
var
  AttNodePre, AttValPre: InvString;
  DeclNode: IXMLNode;
begin
  if GenPre then
    Result := ParentNode.AddChild(NodeName, URI, True)
  else
  begin
    { Send no namespace for nested nodes }
    if (soDocument in Options) then
      Result := ParentNode.AddChild(NodeName)
    else
      Result := ParentNode.AddChild(NodeName, '');
  end;

  { In document or untyped mode, we don't bother setting xsi:type="xxxxx" }
  if not (soSendUntyped in Options) and not (soDocument in Options) then
  begin
    AttNodePre := FindPrefixForURI(RootNode, ParentNode, XMLSchemaInstNamespace);
    if (URI <> '') then
    begin
      DeclNode := ParentNode.FindNamespaceDecl(URI);
      if DeclNode = nil then
        DeclNode := RootNode.FindNamespaceDecl(URI);
      if DeclNode <> nil then
        AttValPre := ExtractLocalName(DeclNode.NodeName);
      if AttValPre = '' then
      begin
        AttValPre := Result.OwnerDocument.GeneratePrefix(Result);
        Result.DeclareNamespace(AttValPre, URI);
      end;
      { Type name }
      TypeName := MakeNodeName(AttValPre, TypeName);
{$IFDEF OPENDOM}
      {JMK TODO: Verify that XMLSchemaInstNamespace is correct Name Space here }
      Result.SetAttributeNS(SSoapType, XMLSchemaInstNamespace, TypeName);
{$ELSE}
      { TODO OWNER:BB
        See comment in SetNodeType about why we have two approaches here -
        Investigate & Collapse to single source }
      Result.Attributes[MakeNodeName(AttNodePre, SSoapType)] := TypeName;
{$ENDIF}
    end;
  end;
end;

function TSOAPDomConv.CreateScalarNodeXS(RootNode, ParentNode: IXMLNode;
   NodeName, URI, TypeName: WideString; Value: WideString; GenPre: Boolean = False): IXMLNode;
begin
  Result := CreateTypedNode(RootNode, ParentNode, NodeName, URI, TypeName);
  Result.Text := Value;
end;

procedure TSOAPDomConv.SetNodeType(RootNode, InstNode: IXMLNode; const ElemURI,
  TypeName: InvString);
var
  Pre, AttNodePre: InvString;
begin
  if not (soSendUntyped in Options) and not (soDocument in Options) then
  begin
    { Namespace prefix of Typename }
    if ElemURI <> '' then
      Pre := FindPrefixForURI(RootNode, InstNode, ElemURI, True)
    else
      Pre := '';

    { Namespace prefix for "type" attribute }
    AttNodePre := FindPrefixForURI(RootNode, InstNode, XMLSchemaInstNamespace);
    { NOTE: The first approach of setting the attribute may not work on all DOMs.
            It fails on the OpenDOM currently used under Linux }
{$IFDEF MSXMLDOM}
    if AttNodePre <> '' then
      InstNode.Attributes[MakeNodeName(AttNodePre, SSoapType)] := MakeNodeName(Pre, TypeName)
    else
{$ENDIF}
      { TODO The following fails to output 'xsi:type="xxxx"' under the MSXML DOM;
             instead we get just 'type="xxxx"; Ideally we'd have single source for
             DOM processing - Investigate!! }
      InstNode.SetAttributeNS(SSoapType, XMLSchemaInstNameSpace, MakeNodeName(Pre, TypeName));
  end;
end;

function TSOAPDomConv.GetOptions: TSOAPConvertOptions;
begin
  Result := FOptions;
end;

procedure TSOAPDomConv.SetOptions(Value: TSOAPConvertOptions);
begin
  { NOTE: Some options are mutually exclusive - for example, soDocument
          does not jive well with others. We could provide logic to handle
          this here or we can rely on the caller to know how to set options }
  FOptions := Value;
end;

function TSOAPDomConv.GetNodeAsText(Node: IXMLNode): InvString;
var
  I: Integer;
begin
  Result := '';
  if Node.IsTextElement then
    Result := Node.Text
  else
    for I := 0 to Node.ChildNodes.Count - 1 do
      Result := Result + Node.ChildNodes[I].XML;
end;

function TSOAPDomConv.GetDataNode(RootNode, Node: IXMLNode; var ID: InvString): IXMLNode;
var
  V: Variant;
  REF: InvString;
begin
  ID := '';
  Result := Node;
  V := Node.Attributes[SXMLHREF];
  if not VarIsNull(V) then
  begin
    REF := V;
    if REF <> '' then
    begin
      Result := FindNodeByHREF(RootNode, REF);
      if not Assigned(Result) and Assigned(RootNode.ParentNode) then
        Result := GetDataNode(RootNode.ParentNode, Node, REF);
      ID := Copy(REF, 2, High(Integer));
    end;
  end else
  begin
    V := Node.Attributes[SXMLID];
    if not VarIsNull(V) then
      ID := V;
  end;
end;

procedure TSOAPDomConv.CheckEncodingStyle(Node: IXMLNode);
var
  V: Variant;
begin
  V := Node.GetAttributeNS(SSoapEncodingAttr, SSoapNameSpace);
  if not VarIsNull(V) then
  begin
    if V <> SSoap11EncodingS5 then
      raise ESOAPDomConvertError.CreateFmt(SUnsupportedEncodingSyle, [V]);
  end;
end;

procedure TSOAPDomConv.AddObjectAsWriting(Instance: TObject);
var
  I: Integer;
begin
{
  for I := 0 to Length(ObjsWriting) - 1 do
    if ObjsWriting[I] = Instance then
      Exit;
}
  I :=  Length(ObjsWriting);
  SetLength(ObjsWriting, I + 1);
  ObjsWriting[I] := Instance;
end;

function TSOAPDomConv.IsObjectWriting(Instance: TObject): Boolean;
var
  I: Integer;
begin
  Result := False;
  for I := 0 to Length(ObjsWriting) -1 do
    if ObjsWriting[I] = Instance then
    begin
      Result := True;
      break;
    end;
end;

procedure TSOAPDomConv.RemoveObjectAsWriting(Instance: TObject);
var
  I, J: Integer;
begin
  I := 0;
  while I < Length(ObjsWriting) do
  begin
    if ObjsWriting[I] = Instance then
      break;
    Inc(I);
  end;
  if I <  Length(ObjsWriting) then
  begin
    for J := I to Length(ObjsWriting)  - 2 do
      ObjsWriting[J] := ObjsWriting[J+1];
    SetLength(ObjsWriting, Length(ObjsWriting) -1);
  end;
end;

procedure TSOAPDomConv.ResetMultiRef;
begin
  SetLength(RefMap, 0);
  SetLength(ObjsWriting, 0);
end;

end.
