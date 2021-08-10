
{*******************************************************}
{                                                       }
{       Borland Delphi Visual Component Library         }
{       XML Node and Document Interfaces                }
{                                                       }
{   Copyright (c) 20001 Borland Software Corporation    }
{                                                       }
{*******************************************************}

unit XMLIntf;

interface

{$IFDEF MSWINDOWS}
{ MSXML.H defines another IXMLDocument and references the type...
  The compiler must see this before it sees the IXMLDocument
  introduced in this unit - otherwise, references will cause
  ambiguity errors }
(*$HPPEMIT '#include <msxml.h>' *)
{$ENDIF}

uses SysUtils, Classes, xmldom;

type

{ Data types }

  TNodeType = (ntReserved, ntElement, ntAttribute, ntText, ntCData,
    ntEntityRef, ntEntity, ntProcessingInstr, ntComment, ntDocument,
    ntDocType, ntDocFragment, ntNotation);

{ Forward Declarartions }

  IXMLNode = interface;
  IXMLNodeList = interface;
  IXMLNodeCollection = interface;
  IXMLDocument = interface;

{ EXMLDocError }

  EXMLDocError = class(Exception)
  end;

{ IXMLNode }

  IXMLNode = interface
    ['{395950C0-7E5D-11D4-83DA-00C04F60B2DD}']
    { Property Accessors }
    function GetAttribute(const AttrName: DOMString): OleVariant;
    function GetAttributeNodes: IXMLNodeList;
    function GetChildNodes: IXMLNodeList;
    function GetChildValue(const IndexOrName: OleVariant): OleVariant;
    function GetCollection: IXMLNodeCollection;
    function GetDOMNode: IDOMNode;
    function GetHasChildNodes: Boolean;
    function GetIsTextElement: Boolean;
    function GetLocalName: DOMString;
    function GetNamespaceURI: DOMString;
    function GetNodeName: DOMString;
    function GetNodeType: TNodeType;
    function GetNodeValue: OleVariant;
    function GetOwnerDocument: IXMLDocument;
    function GetParentNode: IXMLNode;
    function GetPrefix: DOMString;
    function GetReadOnly: Boolean;
    function GetText: DOMString;
    function GetXML: DOMString;
    procedure SetAttribute(const AttrName: DOMString; const Value: OleVariant);
    procedure SetChildValue(const IndexOrName: OleVariant; const Value: OleVariant);
    procedure SetNodeValue(const Value: OleVariant);
    procedure SetReadOnly(const Value: Boolean);
    procedure SetText(const Value: DOMString);
    { Methods }
    function AddChild(const TagName: DOMString; Index: Integer = -1): IXMLNode; overload;
    function AddChild(const TagName, NamespaceURI: DOMString;
      GenPrefix: Boolean = False; Index: Integer = -1): IXMLNode; overload;
    function CloneNode(Deep: Boolean): IXMLNode;
    procedure DeclareNamespace(const Prefix, URI: DOMString);
    function FindNamespaceURI(const TagOrPrefix: DOMString): DOMString;
    function FindNamespaceDecl(const NamespaceURI: DOMString): IXMLNode;
    function GetAttributeNS(const AttrName, NamespaceURI: DOMString): OleVariant;
    function HasAttribute(const Name: DOMString): Boolean; overload;
    function HasAttribute(const Name, NamespaceURI: DOMString): Boolean; overload;
    function NextSibling: IXMLNode;
    procedure Normalize; 
    function PreviousSibling: IXMLNode;
    procedure Resync;
    procedure SetAttributeNS(const AttrName, NamespaceURI: DOMString; const Value: OleVariant);
    procedure TransformNode(const stylesheet: IXMLNode; var output: WideString); overload;
    procedure TransformNode(const stylesheet: IXMLNode; const output: IXMLDocument); overload;
    { Properties }
    property Attributes[const AttrName: DOMString]: OleVariant read GetAttribute write SetAttribute;
    property AttributeNodes: IXMLNodeList read GetAttributeNodes;
    property ChildNodes: IXMLNodeList read GetChildNodes;
    property ChildValues[const IndexOrName: OleVariant]: OleVariant read GetChildValue write SetChildValue; default;
    property Collection: IXMLNodeCollection read GetCollection;
    property DOMNode: IDOMNode read GetDOMNode;
    property OwnerDocument: IXMLDocument read GetOwnerDocument;
    property HasChildNodes: Boolean read GetHasChildNodes;
    property IsTextElement: Boolean read GetIsTextElement;
    property LocalName: DOMString read GetLocalName;
    property NamespaceURI: DOMString read GetNameSpaceURI;
    property NodeName: DOMstring read GetNodeName;
    property NodeType: TNodeType read GetNodeType;
    property NodeValue: OleVariant read GetNodeValue write SetNodeValue;
    property ParentNode: IXMLNode read GetParentNode;
    property Prefix: DOMString read GetPrefix;
    property ReadOnly: Boolean read GetReadOnly write SetReadOnly;
    property Text: DOMString read GetText write SetText;
    property XML: DOMString read GetXML;
  end;

{ IXMLNodeList }

  IXMLNodeList = interface
    ['{395950C1-7E5D-11D4-83DA-00C04F60B2DD}']
    { Property Accessors }
    function GetCount: Integer;
    function GetNode(const IndexOrName: OleVariant): IXMLNode;
    function GetUpdateCount: Integer;
    { Methods }
    function Add(const Node: IXMLNode): Integer;
    procedure BeginUpdate;
    procedure Clear;
    function Delete(const Index: Integer): Integer; overload;
    function Delete(const Name: DOMString): Integer; overload;
    function Delete(const Name, NamespaceURI: DOMString): Integer; overload;
    procedure EndUpdate;
    function First: IXMLNode;
    function FindNode(NodeName: DOMString): IXMLNode; overload;
    function FindNode(NodeName, NamespaceURI: DOMString): IXMLNode; overload;
    function FindNode(ChildNodeType: TGuid): IXMLNode; overload;
    function FindSibling(const Node: IXMLNode; Delta: Integer): IXMLNode;
    function Get(Index: Integer): IXMLNode;
    function IndexOf(const Node: IXMLNode): Integer; overload;
    function IndexOf(const Name: DOMString): Integer; overload;
    function IndexOf(const Name, NamespaceURI: DOMString): Integer; overload;
    procedure Insert(Index: Integer; const Node: IXMLNode);
    function Last: IXMLNode;
    function Remove(const Node: IXMLNode): Integer;
    function ReplaceNode(const OldNode, NewNode: IXMLNode): IXMLNode;
    { Properties }
    property Count: Integer read GetCount;
    property Nodes[const IndexOrName: OleVariant]: IXMLNode read GetNode; default;
    property UpdateCount: Integer read GetUpdateCount;
  end;

{ IXMLNodeCollection }

  IXMLNodeCollection = interface(IXMLNode)
    ['{395950C2-7E5D-11D4-83DA-00C04F60B2DD}']
    { Property Accessors }
    function GetCount: Integer;
    function GetNode(Index: Integer): IXMLNode;
    { Public properties }
    procedure Clear;
    procedure Delete(Index: Integer);
    function Remove(const Node: IXMLNode): Integer;
    property Count: Integer read GetCount;
    property Nodes[Index: Integer]: IXMLNode read GetNode; default;
  end;

{ IXMLDocument }

  TXMLDocOption = (doNodeAutoCreate, doNodeAutoIndent, doAttrNull,
    doAutoPrefix, doNamespaceDecl, doAutoSave);
  TXMLDocOptions = set of TXMLDocOption;

  TParseOption = (poResolveExternals, poValidateOnParse, poPreserveWhiteSpace,
    poAsyncLoad);
  TParseOptions = set of TParseOption;

  TXMLEncodingType = (xetUnknown, xetUCS_4BE, xetUCS_4LE, xetUCS_4Order2134,
    xetUCS_4Order3412, xetUTF_16BE, xetUTF_16LE, xetUTF_8, xetUCS_4Like,
    xetUTF_16BELike, xetUTF_16LELike, xetUTF_8Like, xetEBCDICLike);

  IXMLDocument = interface(IInterface)
    ['{395950C3-7E5D-11D4-83DA-00C04F60B2DD}']
    { Property Accessors }
    function GetActive: Boolean;
    function GetAsyncLoadState: Integer;
    function GetChildNodes: IXMLNodeList;
    function GetDocumentElement: IXMLNode;
    function GetDocumentNode: IXMLNode;
    function GetDOMDocument: IDOMDocument;
    function GetEncoding: DOMString;
    function GetFileName: DOMString;
    function GetModified: Boolean;
    function GetNodeIndentStr: DOMString;
    function GetOptions: TXMLDocOptions;
    function GetParseOptions: TParseOptions;
    function GetSchemaRef: DOMString;
    function GetStandAlone: DOMString;
    function GetVersion: DOMString;
    function GetXML: TStrings;
    procedure SetActive(const Value: Boolean);
    procedure SetDocumentElement(const Value: IXMLNode);
    procedure SetDOMDocument(const Value: IDOMDocument);
    procedure SetEncoding(const Value: DOMString);
    procedure SetFileName(const Value: DOMString);
    procedure SetNodeIndentStr(const Value: DOMString);
    procedure SetOptions(const Value: TXMLDocOptions);
    procedure SetParseOptions(const Value: TParseOptions);
    procedure SetStandAlone(const Value: DOMString);
    procedure SetVersion(const Value: DOMString);
    procedure SetXML(const Value: TStrings);
    { Methods }
    function AddChild(const TagName: DOMString): IXMLNode; overload;
    function AddChild(const TagName, NamespaceURI: DOMString): IXMLNode; overload;
    function CreateElement(const TagOrData, NamespaceURI: DOMString): IXMLNode;
    function CreateNode(const NameOrData: DOMString;
      NodeType: TNodeType = ntElement; const AddlData: DOMString = ''): IXMLNode;
    function GeneratePrefix(const Node: IXMLNode): DOMString;
    function GetDocBinding(const TagName: DOMString;
      DocNodeClass: TClass; NamespaceURI: DOMString = ''): IXMLNode;
    function IsEmptyDoc: Boolean;
    procedure LoadFromFile(const AFileName: DOMString);
    procedure LoadFromStream(const Stream: TStream; EncodingType:
      TXMLEncodingType = xetUnknown);
    procedure LoadFromXML(const XML: string); overload;
    procedure LoadFromXML(const XML: DOMString); overload;
    procedure Refresh;
    procedure RegisterDocBinding(const TagName: DOMString;
      DocNodeClass: TClass; NamespaceURI: DOMString = '');
    procedure Resync;
    procedure SaveToFile(const AFileName: DOMString);
    procedure SaveToStream(const Stream: TStream);
    procedure SaveToXML(var XML: DOMString); overload;
    procedure SaveToXML(var XML: string); overload;
    procedure SetOnAsyncLoad(const Value: TAsyncEventHandler);
    { Properties }
    property Active: Boolean read GetActive write SetActive;
    property AsyncLoadState: Integer read GetAsyncLoadState;
    property ChildNodes: IXMLNodeList read GetChildNodes;
    property DocumentElement: IXMLNode read GetDocumentElement write SetDocumentElement;
    property DOMDocument: IDOMDocument read GetDOMDocument write SetDOMDocument;
    property Encoding: DOMString read GetEncoding write SetEncoding;
    property FileName: DOMString read GetFileName write SetFileName;
    property Modified: Boolean read GetModified;
    property Node: IXMLNode read GetDocumentNode;
    property NodeIndentStr: DOMString read GetNodeIndentStr write SetNodeIndentStr;
    property Options: TXMLDocOptions read GetOptions write SetOptions;
    property ParseOptions: TParseOptions read GetParseOptions write SetParseOptions;
    property SchemaRef: DOMString read GetSchemaRef;
    property StandAlone: DOMString read GetStandAlone write SetStandAlone;
    property Version: DOMString read GetVersion write SetVersion;
    property XML: TStrings read GetXML write SetXML;
  end;


const
  NodeTypeNames: array[TNodeType] of string =  { Do not localize }
    ('', 'Element','Attribute','Text','CDATASection', 'EntityRef','Entity',
     'ProcessingInstr', 'Comment','Document','DocumentType',
     'DocumentFragment','Notation');


implementation

end.
