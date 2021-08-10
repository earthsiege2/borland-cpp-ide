{*******************************************************}
{                                                       }
{ Borland Delphi Visual Component Library               }
{                SOAP Support                           }
{                                                       }
{ Copyright (c) 2001 Borland Software Corporation       }
{                                                       }
{*******************************************************}

unit SOAPDomConv;

interface

uses Classes, xmldom, XMLIntf, XMLDoc;

type

  IDOMHeaderProcessor = interface
  ['{27F23F8F-23A2-4257-95A8-0204EEFF937B}']
    procedure ProcessHeader(HeaderNode: IXMLNode; var Handled, AbortRequest: Boolean);
    function  CreateHeader(HeaderNode: IXMLNode): IXMLNode;
  end;

  TDOMHeaderProcessorEntry = record
     Processor: IDOMHeaderProcessor;
     NameSpace: WideString;
     HeaderName: WideString;
     TypeName: WideString;
  end;

  TDOMHeaderProcessorArray = array of TDOMHeaderProcessorEntry;

  TSOAPDOMProcessor = class(TComponent, IInterface)
  private
    FRefCount: Integer;
    FOwnerIsComponent: Boolean;
  protected
    FHeaderProcessors:  TDOMHeaderProcessorArray;
    function  FindHeaderProcessor(Namespace, HeaderName, TypeName: WideString): IDOMHeaderProcessor; virtual;
    function  MakeHeaderNodes(HeaderNode: IXMLNode): IXMLNode;
    function _AddRef: Integer; stdcall;
    function _Release: Integer; stdcall;
  public
    procedure AddHeaderProcessor(Namespace, HeaderName, TypeName: WideString; Processor: IDOMHeaderProcessor); virtual;
    procedure DefaultProcessHeader(HeaderNode: IXMLNode; var Handled, AbortRequest: Boolean); virtual;
    
    class function NewInstance: TObject; override;
    procedure AfterConstruction; override;
    destructor Destroy; override;
  end;

implementation

uses Variants, SysUtils, SOAPConst, {$IFDEF MSWINDOWS}Windows{$ENDIF}{$IFDEF LINUX}Libc{$ENDIF};

{ TSOAPDOMProcessor }

destructor TSOAPDOMProcessor.Destroy;
begin
  inherited;
end;

class function TSOAPDOMProcessor.NewInstance: TObject;
begin
  Result := inherited NewInstance;
  TSOAPDOMProcessor(Result).FRefCount := 1;
end;

procedure TSOAPDOMProcessor.AfterConstruction;
begin
  inherited;
  FOwnerIsComponent := Assigned(Owner) and (Owner is TComponent);
  InterlockedDecrement(FRefCount);
end;

{ IInterface }

function TSOAPDOMProcessor._AddRef: Integer;
begin
  Result := InterlockedIncrement(FRefCount)
end;

function TSOAPDOMProcessor._Release: Integer;
begin
  Result := InterlockedDecrement(FRefCount);
  { If we are not being used as a TComponent, then use refcount to manage our
    lifetime as with TInterfacedObject. }
  if (Result = 0) and not FOwnerIsComponent then
    Destroy;
end;

procedure TSOAPDOMProcessor.AddHeaderProcessor(Namespace, HeaderName, TypeName: WideString;
  Processor: IDOMHeaderProcessor);
var
  I: Integer;
begin
  I := Length(FHeaderProcessors);
  SetLength(FHeaderProcessors, I + 1);
  FHeaderProcessors[I].NameSpace := NameSpace;
  FHeaderProcessors[I].HeaderName := HeaderName;
  FHeaderProcessors[I].TypeName := TypeName;
  FHeaderProcessors[I].Processor := Processor;
end;

procedure TSOAPDOMProcessor.DefaultProcessHeader(HeaderNode: IXMLNode;
  var Handled, AbortRequest: Boolean);
var
  V: Variant;
begin
  V := HeaderNode.Attributes[SSoapMustUnderstand];
  if not VarIsNull(V) then
  begin
    if V = '1' then
      raise Exception.CreateFmt(SHeaderAttributeError, [ExtractLocalName(HeaderNode.NodeName)]);
  end;
end;

function TSOAPDOMProcessor.FindHeaderProcessor(Namespace, HeaderName,
  TypeName: WideString): IDOMHeaderProcessor;
var
  I: Integer;
begin
  Result := nil;
  for I := 0 to Length(FHeaderProcessors) - 1 do
  begin
    if (FHeaderProcessors[I].NameSpace = NameSpace) and
       (FHeaderProcessors[I].HeaderName = HeaderName) and
       (FHeaderProcessors[I].TypeName = TypeName) then
    begin
      Result :=  FHeaderProcessors[I].Processor;
      Exit;
    end;
  end;
end;

function TSOAPDOMProcessor.MakeHeaderNodes(HeaderNode: IXMLNode): IXMLNode;
var
  I: Integer;
  Node: IXMLNode;
begin
  for I := 0 to Length(FHeaderProcessors) - 1 do
    if Assigned(FHeaderProcessors[I].Processor) then
    begin
      Node := FHeaderProcessors[I].Processor.CreateHeader(HeaderNode);
      if Node <> nil then
        HeaderNode.ChildNodes.Add(Node);
    end;
end;

end.
