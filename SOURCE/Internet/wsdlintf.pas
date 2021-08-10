
{*******************************************************}
{                                                       }
{       Borland Delphi Visual Component Library         }
{       WSDL constants                                  }
{                                                       }
{   Copyright (c) 2001 Borland Software Corporation     }
{                                                       }
{*******************************************************}

unit WSDLIntf;

interface
  uses SysUtils, Classes, XMLIntf, XMLDoc;

type
  TBindingType = (btUnknown, btSoap, btHttp, btMime);
  TWSDLElement = (weServiceIntf, weServiceImpl, weMessage, wePortType, weBinding,
    weService, weTypes, WeImport, weOperation, wePart);
  TWSDLElements = set of TWSDLElement;

  TWString = record
    WString: WideString;
  end;

  TWideStrings = class
  private
    FWideStringList: TList;
    function Get(Index: Integer): WideString;
    procedure Put(Index: Integer; const S: WideString);
  public
    constructor Create;
    destructor Destroy; override;
    function  Count: Integer;
    procedure Clear;
    function Add(const S: WideString): Integer;
    function IndexOf(const S: WideString): Integer;
    function IndexOfIgnoreCase(const S: WideString): Integer;
    procedure Insert(Index: Integer; const S: WideString);
    property Strings[Index: Integer]: WideString read Get write Put; default;
  end;

const

  { WSDL Schema Tags and attribute names }

  SDefinitions = 'definitions';     { do not localize }
  SMessage     = 'message';         { do not localize }
  SPart        = 'part';            { do not localize }
  SType        = 'type';            { do not localize }
  STypes       = 'types';           { do not localize }
  SImport      = 'import';          { do not localize }
  SPort        = 'port';            { do not localize }
  SPortType    = 'portType';        { do not localize }
  SOperation   = 'operation';       { do not localize }
  SBinding     = 'binding';         { do not localize }
  SService     = 'service';         { do not localize }
  SSchema      = 'schema';          { do not localize }
  SName        = 'name';            { do not localize }
  STns         = 'targetNamespace'; { do not localize }
  SInput       = 'input';           { do not localize }
  SOutput      = 'output';          { do not localize }
  SInOut       = 'inout';           { do not localize }
  SRequest     = 'Request';         { do not localize }
  SResponse    = 'Response';        { do not localize }
  SReturn      = 'return';          { do not localize }
  SElement     = 'element';         { do not localize }
  SComplexType = 'complexType';     { do not localize }
  xsdns        = 'http:/'+'/www.w3.org/1999/XMLSchema';     { do not localize }
  tns          = 'http:/'+'/tempuri.org/';                  { do not localize }
  Wsdlns       = 'http:/'+'/schemas.xmlsoap.org/wsdl/';     { do not localize }
  Soapns       =  Wsdlns +'soap/';                          { do not localize }
  Httpns       =  Wsdlns +'http/';
//  SoapEncoding = 'http:/'+'/schemas.xmlsoap.org/soap/encoding';     { do not localize }

  SAddress     = 'address';             { do not localize }
  SBody        = 'body';                { do not localize }
  SHeader      = 'header';              { do not localize }
  SFault       = 'fault';               { do not localize }
  SVerb        = 'verb';                { do not localize }
  SStyle       = 'style';               { do not localize }
  STransport   = 'transport';           { do not localize }
  SLocation    = 'location';            { do not localize }
  SSoapAction  = 'soapAction';          { do not localize }
  SParts       = 'parts';               { do not localize }
  SUse         = 'use';                 { do not localize }
  SNameSpace   = 'namespace';           { do not localize }
  SEncodingStyle = 'encodingStyle';     { do not localize }
  SArrayOf     = 'ArrayOf';             { do not localize }
  SArray       = 'Array';               { do not localize }
  SArrayType   = 'arrayType';           { do not localize }

  SUnknown     = 'Unknown';             { do not localize }
  SDynArray    = 'array of ';           { do not localize }
  SAnySimpleType = 'anySimpleType';     { do not localize }
  SNsPrefix    = 'ns';                  { do not localize }

  ReservedWords: array[0..64] of string = ('and', 'array', 'as', 'asm', 'begin','case',
    'class','const','constructor','destructor', 'dispinterface', 'div', 'do','downto',
    'else', 'end', 'except', 'exports', 'file', 'finalization', 'finally', 'for','function',
    'goto', 'if', 'implementation', 'in','inherited','initialization', 'inline','interface',
    'is','label','library', 'mod','nil','not','object','of','or','out','packed','procedure',
    'program','property','raise','record','repeat', 'resourcestring', 'set','shl','shr', 'string',
    'then', 'threadvar', 'to','try','type','unit','until','uses','var','while','with','xor');

  Directives: array[0..43] of string = ('absolute','abstract','assembler','automated','cdecl','contains',
    'default','dispid', 'dynamic', 'export','external','far','forward','implements','index','message',
    'name','near','nodefault','overload','override','package','pascal','private','protected','public',
    'published','read','readonly','register','reintroduce','requires','resident','safecall','stdcall',
    'stored','virtual','write','writeonly','on','platform','deprecated','local','varargs');

  Operators: array[0..12] of string = ('+','-','*','/','@','^','=','>','<','<>','<=','>=',':=');

  ScalarArrayTypes: array[0..12] of string = ('Integer','Cardinal','Word','SmallInt','Byte','ShortInt','Int64',
    'LongWord','Single','Double','Boolean','String','WideString');

  DynArrayTypes: array[0..12] of string = ('TIntegerDynArray','TCardinalDynArray','TWordDynArray',
    'TSmallIntDynArray','TByteDynArray','TShortIntDynArray','TInt64DynArray','TLongWordDynArray','TSingleDynArray',
    'TDoubleDynArray','TBooleanDynArray','TStringDynArray','TWideStringDynArray');


implementation

uses SOAPConst;

{ TWideStrings implementation }
constructor TWideStrings.Create;
begin
  FWideStringList := TList.Create;
end;

destructor TWideStrings.Destroy;
var
  Index: Integer;
  PWStr: ^TWString;
begin
  { TODO - BB Investigate : Could call Clear here }
  for Index := 0 to FWideStringList.Count-1 do
  begin
    PWStr := FWideStringList.Items[Index];
    if PWStr <> nil then
      Dispose(PWStr);
  end;
  FWideStringList.Free;
  inherited Destroy;
end;

function TWideStrings.Get(Index: Integer): WideString;
var
  PWStr: ^TWString;
begin
  Result := '';
  if ( (Index >= 0) and (Index < FWideStringList.Count) ) then
  begin
    PWStr := FWideStringList.Items[Index];
    if PWStr <> nil then
      Result := PWStr^.WString;
  end;
end;

procedure TWideStrings.Put(Index: Integer; const S: WideString);
begin
  Insert(Index,S);
end;

function TWideStrings.Add(const S: WideString): Integer;
var
  PWStr: ^TWString;
begin
  New(PWStr);
  PWStr^.WString := S;
  Result := FWideStringList.Add(PWStr);
end;

function TWideStrings.IndexOfIgnoreCase(const S: WideString): Integer;
var
  Index: Integer;
  PWStr: ^TWString;
begin
  Result := -1;
  for Index := 0 to FWideStringList.Count -1 do
  begin
    PWStr := FWideStringList.Items[Index];
    if PWStr <> nil then
    begin
      if CompareText(S, PWStr^.WString) = 0 then
      begin
        Result := Index;
        break;
      end;
    end;
  end;
end;

function TWideStrings.IndexOf(const S: WideString): Integer;
var
  Index: Integer;
  PWStr: ^TWString;
begin
  Result := -1;
  for Index := 0 to FWideStringList.Count -1 do
  begin
    PWStr := FWideStringList.Items[Index];
    if PWStr <> nil then
    begin
      if S = PWStr^.WString then
      begin
        Result := Index;
        break;
      end;
    end;
  end;
end;

function TWideStrings.Count: Integer;
begin
  Result := FWideStringList.Count;
end;

procedure TWideStrings.Clear;
var
  Index: Integer;
  PWStr: ^TWString;
begin
  for Index := 0 to FWideStringList.Count-1 do
  begin
    PWStr := FWideStringList.Items[Index];
    if PWStr <> nil then
      Dispose(PWStr);
  end;
  FWideStringList.Clear;
end;

procedure TWideStrings.Insert(Index: Integer; const S: WideString);
var
  PWStr: ^TWString;
begin
  if((Index < 0) or (Index > FWideStringList.Count)) then
    raise Exception.Create(SWideStringOutofBounds);
  if Index < FWideStringList.Count then
  begin
    PWStr := FWideStringList.Items[Index];
    if PWStr <> nil then
      PWStr.WString := S;
  end
  else
    Add(S);
end;

end.
