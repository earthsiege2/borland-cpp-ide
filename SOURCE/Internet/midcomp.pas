
{*******************************************************}
{                                                       }
{  Borland Delphi Visual Component Library              }
{                                                       }
{  Copyright (c) 2000, 2001 Borland Software Corp.      }
{                                                       }
{*******************************************************}

unit MidComp;

interface

{$IFDEF MSWINDOWS}
{ MSXML.H defines another IXMLDocument and references the type...
  The compiler must see this before it sees the IXMLDocument
  introduced in this unit - otherwise, references will cause
  ambiguity errors }
(*$HPPEMIT '#include <msxml.h>' *)
{$ENDIF}

uses Classes, HTTPApp, HTTPProd, Masks, WebComp;

type

  IScriptManager = interface;
  IScriptProducer = interface
  ['{555DA472-F254-11D2-AA55-00A024C11562}']
    function GetScriptManager: IScriptManager;
    property ScriptManager: IScriptManager read GetScriptManager;
  end;

  IXMLRowSet = interface;
  IXMLDocuments = interface;
  IXMLDocument = interface;
  IXMLRowSets = interface;
  IIncludeFiles = interface;
  IFunctions = interface;
  IVars = interface;
  IScriptBlocks = interface;
  IHTMLBlocks = interface;
  IAddScriptElements = interface;
  IScriptManager = interface
  ['{94B8B14E-E6D6-11D2-AFA6-00C04FB16EC3}']
    function GetXMLDocuments: IXMLDocuments;
    function GetIncludeFiles: IIncludeFiles;
    function GetFunctions: IFunctions;
    function GetWarnings: TStrings;
    function GetScriptBlocks: IScriptBlocks;
    function GetVars: IVars;
    function GetHTMLBlocks: IHTMLBlocks;
    function GetOptions: TWebContentOptions;
    function GetAddElementsIntf: IAddScriptElements;
    procedure AddError(const Error: string);
    property XMLDocuments: IXMLDocuments read GetXMLDocuments;
    property IncludeFiles: IIncludeFiles read GetIncludeFiles;
    property Warnings: TStrings read GetWarnings;
    property Functions: IFunctions read GetFunctions;
    property Vars: IVars read GetVars;
    property ScriptBlocks: IScriptBlocks read GetScriptBlocks;
    property HTMLBlocks: IHTMLBlocks read GetHTMLBlocks;
    property Options: TWebContentOptions read GetOptions;
    property AddElementsIntf: IAddScriptElements read GetAddElementsIntf;
  end;

  IIncludeFile = interface;
  IIncludeFiles = interface
  ['{F735BC77-E7A4-11D2-AFA7-00C04FB16EC3}']
    function GetCount: Integer;
    function GetItem(I: Integer): IIncludeFile;
    property Count: Integer read GetCount;
    property Items[I: Integer]: IIncludeFile read GetItem;
  end;

  IIncludeFile = interface
  ['{F735BC78-E7A4-11D2-AFA7-00C04FB16EC3}']
    function GetFileName: string;
    property FileName: string read GetFileName;
  end;

  IFunction = interface;
  IFunctions = interface
  ['{3AA43171-EC43-11D2-AFAE-00C04FB16EC3}']
    function GetCount: Integer;
    function GetItem(I: Integer): IFunction;
    property Count: Integer read GetCount;
    property Items[I: Integer]: IFunction read GetItem;
  end;

  IFunction = interface
  ['{3AA43172-EC43-11D2-AFAE-00C04FB16EC3}']
    function GetFunctionName: string;
    function GetBody: string;
    property FunctionName: string read GetFunctionName;
    property Body: string read GetBody;
  end;

  IVar = interface;
  IVars = interface
  ['{8AFBBDE2-2A11-11D3-AAAB-00A024C11562}']
    function GetCount: Integer;
    function GetItem(I: Integer): IVar;
    property Count: Integer read GetCount;
    property Items[I: Integer]: IVar read GetItem;
  end;

  IVar = interface
  ['{8AFBBDE3-2A11-11D3-AAAB-00A024C11562}']
    function GetVarName: string;
    function GetScript: string;
    property VarName: string read GetVarName;
    property Script: string read GetScript;
  end;

  IHTMLBlock = interface;
  IHTMLBlocks = interface
  ['{8AFBBDE4-2A11-11D3-AAAB-00A024C11562}']
    function GetCount: Integer;
    function GetItem(I: Integer): IHTMLBlock;
    property Count: Integer read GetCount;
    property Items[I: Integer]: IHTMLBlock read GetItem;
  end;

  IHTMLBlock = interface
  ['{8AFBBDE5-2A11-11D3-AAAB-00A024C11562}']
    function GetBlockName: string;
    function GetHTML: string;
    property BlockName: string read GetBlockName;
    property HTML: string read GetHTML;
  end;

  IScriptBlock = interface;
  IScriptBlocks = interface
  ['{8AFBBDE6-2A11-11D3-AAAB-00A024C11562}']
    function GetCount: Integer;
    function GetItem(I: Integer): IScriptBlock;
    property Count: Integer read GetCount;
    property Items[I: Integer]: IScriptBlock read GetItem;
  end;

  IScriptBlock = interface
  ['{8AFBBDE7-2A11-11D3-AAAB-00A024C11562}']
    function GetBlockName: string;
    function GetScript: string;
    property BlockName: string read GetBlockName;
    property Script: string read GetScript;
  end;

  IXMLDocuments = interface
  ['{94B8B150-E6D6-11D2-AFA6-00C04FB16EC3}']
    function GetCount: Integer;
    function GetItem(I: Integer): IXMLDocument;
    property Count: Integer read GetCount;
    property Items[I: Integer]: IXMLDocument read GetItem;
  end;

  IXMLDocument = interface
  ['{94B8B151-E6D6-11D2-AFA6-00C04FB16EC3}']
    function GetRowSets: IXMLRowSets;
    function GetComponent: TComponent;
    function GetDocumentVarName: string;
    function GetXMLVarName: string;
    property RowSets: IXMLRowSets read GetRowSets;
    property Component: TComponent read GetComponent;
    property DocumentVarName: string read GetDocumentVarName;
    property XMLVarName: string read GetXMLVarName;
  end;

  IXMLRowSets = interface
  ['{94B8B152-E6D6-11D2-AFA6-00C04FB16EC3}']
    function GetCount: Integer;
    function GetItem(I: Integer): IXMLRowSet;
    property Count: Integer read GetCount;
    property Items[I: Integer]: IXMLRowSet read GetItem;
  end;

  IXMLRowSet = interface
  ['{94B8B14F-E6D6-11D2-AFA6-00C04FB16EC3}']
    function GetPath: TStrings;
    function GetRowSetVarName: string;
    function GetMasterRowSetVarName: string;
    function GetMasterDataSetFieldName: string;
    property MasterRowSetVarName: string read GetMasterRowSetVarName;
    property MasterDataSetFieldName: string read GetMasterDataSetFieldName;
    property RowSetVarName: string read GetRowSetVarName;
  end;

  TAddScriptElementsEvent = procedure(Data: Pointer; AddScriptElements: IAddScriptElements) of object;

  IAddScriptElements = interface
  ['{2FF3A331-E790-11D2-AFA7-00C04FB16EC3}']
    function GetScriptManager: IScriptManager;
    function AddIncludeFile(FileName: string): Boolean;
    function AddRowSet(XMLProducer: TComponent; Path: TStrings): Boolean;
    function AddScriptBlock(Name: string; Script: string): Boolean;
    function AddHTMLBlock(Name: string; HTML: string): Boolean;
    function AddVar(Name: string; Script: string): Boolean;
    function AddFunction(Name: string; Body: string): Boolean;
    procedure AddError(Text: string);
    procedure AddPass(Event: TAddScriptElementsEvent; Data: Pointer);
    procedure AddScriptComponents(List: TObject);
    property ScriptManager: IScriptManager read GetScriptManager;
  end;

  IScriptComponent = interface
  ['{1B9B0962-D28E-11D2-AF8A-00C04FB16EC3}']
    procedure AddElements(AddIntf: IAddScriptElements);
    function GetSubComponents: TObject; // Object implementing IWebComponentContainer
    property SubComponents: TObject read GetSubComponents;
  end;


implementation

{$IFDEF MSWINDOWS}
uses Windows, Messages, SysUtils, WebConst ;
{$ENDIF}
{$IFDEF LINUX}
uses SysUtils, WebConst;
{$ENDIF}

end.
