{***************************************************************}
{                                                               }
{   Borland Delphi Visual Component Library                     }
{                                                               }
{   Copyright (c) 2000-2001 Borland Software Corporation        }
{                                                               }
{***************************************************************}
unit WSDLPub;


interface

uses InvokeRegistry, Classes, HTTPApp, AutoDisp, Masks, Types;

type

  IWSDLPublish = interface(IInvokable)
  ['{ECD820DD-F242-11D4-928A-00C04F990435}']
    procedure GetPortTypeList(var PortTypes: TWideStringDynArray);  stdcall;
    function  GetWSDLForPortType(PortType: WideString): WideString;  stdcall;
    procedure GetTypeSystemsList(TypeSystems: TWideStringDynArray); stdcall;
    function  GetXSDForTypeSystem(TypeSystem: WideString): WideString;  stdcall;
  end;

  TWSDLPublish = class(TInvokableClass, IWSDLPublish)
  private
    Locations: array of WideString;
    PortNames: array of WideString;
    FTargetNamespace: WideString;
  public
    property TargetNamespace: WideString read FTargetNamespace write FTargetNamespace;
    procedure GetPortTypeEntries(var Entries: TInvRegIntfEntryArray);
    { IWSDLPublish }
    procedure GetPortTypeList(var PortTypes: TWideStringDynArray);   stdcall;
    procedure GetTypeSystemsList(TypeSystems: TWideStringDynArray);    stdcall;
    function  GetWSDLForPortType(PortType: WideString): WideString;    stdcall;
    function  GetXSDForTypeSystem(TypeSystem: WideString): WideString;   stdcall;
  end;

  SOAPPublishOptions = (poDefault, poPublishLocationAsSecure);
  TSOAPPublishOptions= set of SOAPPublishOptions;

  TWSDLHTMLPublish =  class(TComponent, IWebDispatch)
  private
    Pub: TWSDLPublish;
    FWebDispatch: TWebDispatch;
    FAdminEnabled: Boolean;
    FTargetNamespace: WideString;
    FPublishOptions: TSOAPPublishOptions;
    procedure SetWebDispatch(const Value: TWebDispatch);
  protected
    procedure AddInterfaceList(htmldoc: TStringList; const WSDLBaseURL: String);
    procedure AddPortList(htmldoc: TStringList; const PortType: String);
    procedure UpdatePortList(PortList: TStrings; const PortType, Command: String);
    function GetHostScriptBaseURL(Request: TWebRequest): String;
  public
    constructor Create(AOwner: TComponent); override;
    destructor Destroy; override;
    { IWebDispatch }
    function DispatchEnabled: Boolean;
    function DispatchMask: TMask;
    function DispatchMethodType: TMethodType;
    function DispatchRequest(Sender: TObject; Request: TWebRequest;
      Response: TWebResponse): Boolean;
    procedure ServiceInfo(Sender: TObject; Request: TWebRequest;
                Response: TWebResponse; var Handled: Boolean);
    function HandleRequest(Resp: TStringList; const Path: String;
                           const HostScriptBaseURL: String;
                           var ContentType: String; Request: TWebRequest): integer;
    function GetTargetNamespace: WideString;
  published
    property WebDispatch: TWebDispatch read FWebDispatch write SetWebDispatch;
    property AdminEnabled: Boolean read FAdminEnabled write FAdminEnabled;
    property TargetNamespace: WideString read GetTargetNamespace write FTargetNamespace;
    property PublishOptions: TSOAPPublishOptions read FPublishOptions write FPublishOptions;
  end;

  procedure WSDLPubFactory(out obj: TObject);

implementation

uses {$IFDEF MSWINDOWS}Windows, ActiveX, {$ENDIF}
  SysUtils, TypInfo, IntfInfo, XMLSchema, WSDLIntf, WebServExp, WSDLBind,
  WSDLItems, WSDLSOAP, IniFiles, OPToSOAPDomConv, SOAPConst;

{ TWSDLPublish }

var
  AdminIniFile: string;
  ServicePath: string;
  ServiceName: string;
  ModuleName: array[0..MAX_PATH] of char;


procedure AddElem(htmldoc: TStringList; const Elem: string; const cls: string);
begin
  htmldoc.Add('<td class="'+cls+'">' + Elem + '</td>');   { Do not localize }
end;

procedure TWSDLHTMLPublish.AddInterfaceList(htmldoc: TStringList; const WSDLBaseURL: String);
var
  I: Integer;
  Entries: TInvRegIntfEntryArray;
  Entry: InvRegIntfEntry;
  Doc: string;
begin
  htmldoc.Add('<table ' + TableStyle + '>');        { Do not localize }
  htmldoc.Add('<tr>');                              { Do not localize }
  AddElem(htmldoc, sPortType, sTblHdrCls);
  AddElem(htmldoc, sNamespaceURI, sTblHdrCls);
  AddElem(htmldoc, sDocumentation, sTblHdrCls);
  AddElem(htmldoc, sWSDL, sTblHdrCls);
  htmldoc.Add('</tr>');
  Pub.GetPortTypeEntries(Entries);
  for I := 0 to Length(Entries) - 1 do
  begin
    Entry := Entries[I];
    htmldoc.Add('<tr>');                  { Do not localize }
    AddElem(htmldoc, Entry.Name, sTblRow);
    AddElem(htmldoc, Entry.Namespace, sTblRow);
    Doc := Entry.Documentation;
    if Doc = '' then
      Doc := sNBSP;
    AddElem(htmldoc, Doc, sTblRow);
    AddElem(htmldoc, '<a href="' + WSDLBaseURL + '/' + Entry.Name + '">' + sWSDLFor + Entry.Name + '</a>', sTblRow); { Do not localize }
    htmldoc.Add('</tr>');                 { Do not localize }
  end;
  htmldoc.Add('</table>');                { Do not localize }
end;

procedure TWSDLHTMLPublish.AddPortList(htmldoc: TStringList; const PortType: string);
var
  I: Integer;
  IniFile: TMemIniFile;
  PortList: TStringList;
begin
  IniFile := TMemIniFile.Create(AdminIniFile);
  try
    htmldoc.Add('<table ' + TableStyle + '>');  { Do not localize }
    htmldoc.Add('<tr>');                        { Do not localize }
    AddElem(htmldoc, sPortName, sTblHdrCls);
    AddElem(htmldoc, sAddress, sTblHdrCls);
    htmldoc.Add('</tr>');                       { Do not localize }
    if IniFile.SectionExists(PortType) then
    begin
      PortList := TStringList.Create;
      try
        IniFile.ReadSectionValues(PortType, PortList);
        for I := 0 to PortList.Count - 1 do
        begin
          htmldoc.Add('<tr>');                  { Do not localize }
          AddElem(htmldoc, PortList.Names[I], sTblRow);
          AddElem(htmldoc, PortList.Values[PortList.Names[I]], sTblRow);
          htmldoc.Add('</tr>');                 { Do not localize }
        end;
      finally
        PortList.Free;
      end;
    end;
    htmldoc.Add('</table>');
  finally
    IniFile.Free;
  end;
end;

procedure TWSDLHTMLPublish.UpdatePortList(PortList: TStrings; const PortType, Command: String);
var
  IniFile: TMemIniFile;
begin
  if PortList.Count > 0 then
  begin
    IniFile := TMemIniFile.Create(AdminIniFile);
    try
      if PortList.Values['PortName'] <> '' then     { Do not localize }
        if UpperCase(Command) = 'ADD' then          { Do not localize }
          IniFile.WriteString(PortType, PortList.Values[sPortName], PortList.Values[sAddress])
        else if UpperCase(Command) = 'REMOVE' then  { Do not localize }
          IniFile.DeleteKey(PortType, PortList.Values[sPortName]);
      if AdminEnabled then
        IniFile.UpdateFile;
    finally
      IniFile.Free;
    end;
  end;
end;

function TWSDLHTMLPublish.GetHostScriptBaseURL(Request: TWebRequest): String;
begin
  { Here we automatically detect the default HTTPS port [sure hope no one dares
    to use 443 for non SSL purposes] or if user configured publisher to publish
    service location as SSL }
  if (Request.ServerPort = 443) or (poPublishLocationAsSecure in PublishOptions) then
    Result := 'https://' + Request.Host + Request.InternalScriptName        { do not localize }
  else if (Request.ServerPort <> 80) and (Pos(':', Request.Host) = 0) then
    Result := 'http://' + Request.Host + ':' + IntToStr(Request.ServerPort) + Request.InternalScriptName         { do not localize }
  else
    Result := 'http://' + Request.Host + Request.InternalScriptName;    { do not localize }
end;

procedure TWSDLPublish.GetPortTypeList(var PortTypes: TWideStringDynArray);
var
  I, Count: Integer;
  IntfEntry: InvRegIntfEntry;
begin
  { Use invrg to list all the interfaces registered, add new method if necessary }
  Count := InvRegistry.GetInterfaceCount;
  SetLength(PortTypes, Count);
  for I:= 0 to Count -1 do
  begin
    IntfEntry := InvRegistry.GetRegInterfaceEntry(I);
    PortTypes[I] := IntfEntry.Name;
  end;
end;


procedure TWSDLPublish.GetTypeSystemsList(TypeSystems: TWideStringDynArray);
var
  I, Count: Integer;
  URIMap: TRemRegEntry;
  TypeSystemList: TStringList;
begin
  { TODO - This does not handle WideStrings!! }
  TypeSystemList := TStringList.Create;
  try
    { use xsdclasses to list all the unique URIs registered, add new implementation if necessary }
    Count := RemClassRegistry.GetURICount;
    for I := 0 to Count -1 do
    begin
      URIMap := RemClassRegistry.GetURIMap(I);
      if TypeSystemList.IndexOf(URIMap.URI) = -1 then
        TypeSystemList.Add(URIMap.URI)
    end;
    SetLength(TypeSystems, Count);
    for I := 0 to Count -1 do
      TypeSystems[I] := TypeSystemList[I];
  finally
    TypeSystemList.Free;
  end;
end;

function TWSDLPublish.GetWSDLForPortType(PortType: WideString): WideString;
var
  IID: TGUID;
  Info: PTypeInfo;
  WSDLDoc: IWSDLDocument;
  WebServExp: TWebServExp;
begin
  try
    { Use invrg to get typeinfo for porttype name ( interface name ) }
    { Convert to WSDL fragement }
    InvRegistry.GetInterfaceInfoFromName ('', PortType, Info, IID);

    { TODO Should we throw an exception if interface is not registered?? }
    if Info <> nil then
    begin
      WSDLDoc := TWSDLDocument.Create(nil);
      WSDLDoc.Active := True;
      WebServExp := TWebServExp.Create;
      WebServExp.TargetNameSpace := TargetNamespace;
      try
        WSDLDoc.Encoding := 'utf-8';        { Do not localize }
        WebServExp.BindingType := btSoap;
        WebServExp.WSDLElements :=  WebServExp.WSDLElements + [weService];
        WebServExp.GetWSDLForInterface(Info, WSDLDoc, PortNames, Locations);
        WSDLDoc.SaveToXML(Result);
      finally
        WebServExp.Free;
      end;
    end;
  finally
  end;
end;

function TWSDLPublish.GetXSDForTypeSystem(TypeSystem: WideString): WideString;
var
  I, Count: Integer;
  URIMap: TRemRegEntry;
  WebServExp: TWebServExp;
  XMLDoc: IXMLSchemaDoc;
begin
  { Use xsdclasses to get list of all classes registered with same URI and }
  { Create XML schema doc for this. }
  Count := RemClassRegistry.GetURICount;
  for I := 0 to Count -1 do
  begin
    URIMap := RemClassRegistry.GetURIMap(I);
    if TypeSystem = URIMap.URI then
    begin
      WebServExp := TWebServExp.Create;
      try
        XMLDoc := NewXmlSchema;
        WebServExp.GenerateXMLSchema(XMLDoc.SchemaDef, PTypeInfo(URIMap.ClassType.ClassInfo), nil, '');
        XMLDoc.SaveToXML(Result);
      finally
        WebServExp.Free;
      end;
    end;
  end;
end;

procedure WSDLPubFactory(out obj: TObject);
begin
  obj := TWSDLPublish.Create;
end;

procedure TWSDLPublish.GetPortTypeEntries(var Entries: TInvRegIntfEntryArray);
var
  I, J, Count: Integer;
  Entry: InvRegIntfEntry;
begin
  Count := InvRegistry.GetInterfaceCount;
  SetLength(Entries, Count);
  J := 0;
  for I:= 0 to Count -1 do
  begin
    { Put the built-in publisher last }
    Entry := InvRegistry.GetRegInterfaceEntry(I);
    if Entry.Info = TypeInfo(IWSDLPublish) then
      Entries[Count-1] := Entry
    else
    begin
      Entries[J] := Entry;
      Inc(J);
    end;
  end;
end;

{ TWSDLHTMLPublish }

constructor TWSDLHTMLPublish.Create(AOwner: TComponent);
begin
  RCS;
  inherited Create(AOwner);
  FWebDispatch := TWebDispatch.Create(Self);
  FWebDispatch.PathInfo := 'wsdl*';
  FWebDispatch.MethodType := mtAny;
end;

destructor TWSDLHTMLPublish.Destroy;
begin
  inherited Destroy;
  FWebDispatch.Free;
end;


function TWSDLHTMLPublish.DispatchEnabled: Boolean;
begin
  Result := True;
end;

function TWSDLHTMLPublish.DispatchMask: TMask;
begin
    Result := FWebDispatch.Mask;
end;

function TWSDLHTMLPublish.DispatchMethodType: TMethodType;
begin
   Result := FWebDispatch.MethodType;
end;


function TWSDLHTMLPublish.HandleRequest(Resp: TStringList; const Path: String;
                                        const HostScriptBaseURL: String;
                                        var ContentType: String;
                                        Request: TWebRequest): integer;
var
  Pub: TWSDLPublish;

  procedure AddAdmin(const URL: string);
  begin
    Resp.Add('<FORM NAME="admin" METHOD="GET" ACTION=' + '"' + URL + '"' + '>'); { do not localize }
    Resp.Add('<INPUT TYPE="SUBMIT" VALUE="Administrator">'); { do not localize }
    Resp.Add('</FORM>');                                     { do not localize }
  end;

  function getDefaultPortValue(Name: string): string;
  begin
    Result := HostScriptBaseURL + '/soap/' + Name;    { Do not localize }
  end;

  function getDefaultPortKey(Name: string): string;
  begin
    Result := Name + 'Port';                          { Do not localize }
  end;

  procedure CreateDefaultEntries;
  var
    I: Integer;
    Entries: TInvRegIntfEntryArray;
    IniFile: TMemIniFile;
  begin
    if not FileExists(AdminIniFile) then
    begin
      IniFile := TMemIniFile.Create(AdminIniFile);
      try
        Pub.GetPortTypeEntries(Entries);
        for I := 0 to Length(Entries) - 1 do
        with Entries[I] do
          IniFile.WriteString(Name, getDefaultPortKey(Name), getDefaultPortValue(Name));  { do not localize }
        if AdminEnabled then
          IniFile.UpdateFile;
      finally
        IniFile.Free;
      end;
    end;
  end;

  procedure NewServicePortForm;
  begin
    Resp.Add('<FORM NAME="admin" METHOD="GET" ACTION=' + '"' + { do not localize }
             HostScriptBaseURL + Path + '"' + '>');          { do not localize }
    Resp.Add('<table ' + TableStyle + '>');                  { do not localize }
    Resp.Add('<tr>');                                        { do not localize }
    AddElem(Resp, sPortName, sTblHdrCls);
    AddElem(Resp, sAddress, sTblHdrCls);
    Resp.Add('</tr>');                                       { do not localize }
    Resp.Add('<tr>');                                        { do not localize }
    AddElem(Resp, '<INPUT TYPE="TEXT" NAME="' + sPortName + '" SIZE="20" VALUE="" MAXLENGTH="4096">', sTblRow); { do not localize }
    AddElem(Resp, '<INPUT TYPE="TEXT" NAME="' + sAddress + '" SIZE="40" VALUE="" MAXLENGTH="4096">', sTblRow); { do not localize }
    Resp.Add('</tr>');                                       { do not localize }
    Resp.Add('</table>');                                    { do not localize }
    Resp.Add('<p>');                                         { do not localize }
    Resp.Add('<INPUT TYPE="SUBMIT" VALUE="Add" NAME="COMMAND">'); { do not localize }
    Resp.Add('<INPUT TYPE="SUBMIT" VALUE="Remove" NAME="COMMAND">'); { do not localize }
    Resp.Add('</FORM>');                                     { do not localize }
  end;

  procedure GetServicePorts(PortType: string);
  var
    I: Integer;
    IniFile: TMemIniFile;
    PortList: TStringList;
  begin
    IniFile := TMemIniFile.Create(AdminIniFile);
    try
      { If the section exists, use what's there}
      if IniFile.SectionExists(PortType) then
      begin
        PortList := TStringList.Create;
        try
          IniFile.ReadSectionValues(PortType, PortList);
          Pub.PortNames := nil;
          Pub.Locations := nil;
          SetLength(Pub.PortNames, PortList.Count);
          SetLength(Pub.Locations, PortList.Count);
          for I := 0 to PortList.Count - 1 do
          begin
            Pub.PortNames[I] := PortList.Names[I];
            Pub.Locations[I] := PortList.Values[PortList.Names[I]];
          end;
        finally
          PortList.Free;
        end;
      end
      else
      { Here there was nothing for this PortType in the .INI file...
        So we create at least one default so we have something for
        the address location }
      begin
        Pub.PortNames := nil;
        Pub.Locations := nil;
        SetLength(Pub.PortNames, 1);
        SetLength(Pub.Locations, 1);
        Pub.PortNames[0] := getDefaultPortKey(PortType);
        Pub.Locations[0] := getDefaultPortValue(PortType);
      end;
    finally
      IniFile.Free;
    end;
  end;

var
  LastName, PreName: string;
  WSDL: string;
  WSDLBaseURL: String;

begin
  Result   := 200;
  LastName := Copy(Path, LastDelimiter('/', Path) + 1, High(Integer));
  PreName  := Copy(Path, 1, LastDelimiter('/', Path) - 1);
  PreName  :=  Copy(PreName, LastDelimiter('/', PreName) + 1, High(Integer));
  WSDLBaseURL := HostScriptBaseURL + Path;
{$IFDEF MSWINDOWS}
  CoInitialize(nil);
{$ENDIF}
  try
    Pub :=  TWSDLPublish.Create;
    try
      Pub.TargetNamespace := TargetNamespace;
      CreateDefaultEntries;
      if LastName = 'wsdl' then                              { do not localize }
      begin
        Resp.Add(Format(HTMLTopTNoM, [ServiceName]) +
                        InfoTitle1 +
                        Format(InfoTitle2, [ServiceName, sWebServiceListing]));
        Resp.Add('<center><br>');                            { do not localize }
        AddInterfaceList(Resp, WSDLBaseURL);
        if AdminEnabled then
          AddAdmin(WSDLBaseURL + '/' + 'admin');             { do not localize }
        Resp.Add('</center>');                               { do not localize }
        Resp.Add(HTMLEnd);
        ContentType := sTextHtml;
      end
      else if LastName = 'admin' then                        { do not localize }
      begin
        if not AdminEnabled then
        begin
          Result := 403;
          Resp.Add(sForbiddenAccess);
          ContentType := sTextHtml;
          Exit;
        end;

        Resp.Add(Format(HTMLTopTitle, [sWebServiceListingAdmin]));
        Resp.Add('<h1>' + sWebServiceListingAdmin + '</h1><p>'); { do not localize }
        AddInterfaceList(Resp, WSDLBaseURL);
        Resp.Add(HTMLEnd);
        ContentType := sTextHtml;
      end
      else
      begin
        if PreName = 'wsdl' then                             { do not localize }
        begin
          GetServicePorts(LastName);
          WSDL := Pub.GetWSDLForPortType(LastName);
          if WSDL <> '' then
          begin
            Resp.Add(UTF8Encode(WSDL));
            ContentType := sTextXML;
          end
          else
          begin
            { interface not found... }
            Resp.Add(Format(sInterfaceNotFound, [LastName]));
            ContentType := sTextHtml;
          end;
        end
        else if PreName = 'admin' then                       { do not localize }
        begin
          if not AdminEnabled then
          begin
            Result := 403;
            Resp.Add(sForbiddenAccess);
            ContentType := sTextHtml;
            Exit;
          end;
          UpdatePortList(Request.QueryFields, LastName, Request.QueryFields.Values['COMMAND']);  { do not localize }
          Resp.Add(Format(HTMLTopTitle, [sWSDLPortsforPortType]));
          Resp.Add('<h1>' + sWSDLPortsforPortType + ' ' + LastName + '</h1><p>'); { do not localize }
          AddPortList(Resp, LastName);
          Resp.Add('<p>');                          { do not localize }
          NewServicePortForm;
          Resp.Add(HTMLEnd);                        { do not localize }
          ContentType := sTextHtml;
        end;
      end;
    finally
      Pub.Free;
    end;
  finally
{$IFDEF MSWINDOWS}
    CoUnInitialize;
{$ENDIF}
  end;
end;

function TWSDLHTMLPublish.DispatchRequest(Sender: TObject;
  Request: TWebRequest; Response: TWebResponse): Boolean;
var
  Resp: TStringList;
  Path: string;
  HostScriptBaseURL: String;
  ContentType: String;
begin
  try
    HostScriptBaseURL := GetHostScriptBaseURL(Request);
    Path := Request.InternalPathInfo;
    { Strip ending '/' }
    if Path[Length(Path)] = '/' then
      Path := Copy(Path, 1, Length(Path)-1);
{$IFDEF MSWINDOWS}
    CoInitialize(nil);
{$ENDIF}
    try
      Resp := TStringList.Create;
      try
        Response.StatusCode := HandleRequest(Resp, Path, HostScriptBaseURL, ContentType, Request);
        Response.ContentType := ContentType;
        Response.Content := Resp.Text;
      finally
        Resp.Free;
      end;
    finally
{$IFDEF MSWINDOWS}
      CoUnInitialize;
{$ENDIF}
    end;
  except
    on E: Exception do
    begin
      Response.Content := HTMLTop+'<h1>' + sErrorColon + E.Message + '/'+ E.ClassName+'</h1>'+HTMLEnd; { do no localize }
      Response.ContentType := sTextHtml;
    end
    else
    begin
      Response.Content := HTMLTop+'<h1>'+sUnknownError +'</h1>'+HTMLEnd; { do not localize }
      Response.ContentType := sTextHtml;
    end;
  end;
  Result := True;
end;

procedure TWSDLHTMLPublish.ServiceInfo(Sender: TObject;
  Request: TWebRequest; Response: TWebResponse; var Handled: Boolean);

const
  IntfHdr0= '<table width="100%" border=0 cellpadding=1 cellspacing=0>'                + sLineBreak;
  IntfHdr1= '<br>' + IntfHdr0 +
            '<tr><td width="1%" class="Info">&nbsp;</td><td width="99%" class="Info">' + sLineBreak;
  IntfHdr2= IntfHdr0 +
            '<tr class="NavBar">'                                                      + sLineBreak +
            '<td width="1%" class="NavBar">&nbsp;</td>'                                + sLineBreak +
            '<td width="99%" class="NavBar">'                                          + sLineBreak;
  IntfHdr3= '</td></tr>'                                                               + sLineBreak +
            '<tr><td>&nbsp;</td><td>&nbsp;</td></tr>'                                  + sLineBreak;

  IntfBeg = '<tr>' +
            '<td width="1%">&nbsp;</td>' +
            '<td width="99%">' +
            '<ul>';
  IntfEntL=  '<li>'                                                                    + sLineBreak +
            '<a class="IntfName" href="%1:s?' + sQueryStringIntf + '=%0:s">%0:s</a>'   + sLineBreak;
  IntfEntP= '<li>'                                                                     + sLineBreak +
            '<span class="IntfName">%0:s</span>'                                       + sLineBreak;

  IntfWSDL= '<span class="WSDL">[</span>'                                              +
            '<a class="WSDL" href="%s">WSDL</a>'                                       +
            '<span class="WSDL">]</span>'                                              + sLineBreak;
  IntfNS =  '&nbsp;<span class="Namespace">(%0:s)</span>'                              + sLineBreak;
  IntDoc1=  '<table><tr><td width="2%">&nbsp;</td><td>'                                + sLineBreak;
  IntDoc2=  '<span class="Tip">%s</span></td></tr></table>'                            + sLineBreak;
  MethBeg=  '<ul>';
  MethEnt=  '<li><span class="MethName">%s</span></li>';
  MethEnd=  '</ul>';

  MethBeg2= '<table>'                                                                  + sLineBreak;
  MethEnt2= '<tr><td width="10%%" class="MethName">&nbsp;</td>' +
            '<td class="ParmName">%s</td><td>%s</td></tr>'                             + sLineBreak;
  MethEnt3= '<span class="MethName">%s(</span>%s<span class="MethName">)</span>';
  MethEnd2= '</table>'                                                                 + sLineBreak;

  IntfEnd=  '</li>' +
            '</ul>' +
            '</td>' +
            '</tr>';
  IntfFtr=  '</table>';

  RegHdr =  '<a name="types"></a><center><h3>Registered Types</h3>' +
            '<table cellpadding=2 cellspacing=1 border=0><tr>' +
            '<td class="TblHdr">Type</td>' +
            '<td class="TblHdr">XML Name</td>' +
            '<td class="TblHdr">Namespace</td>' +
            '<td class="TblHdr">Class</td>' +
            '<td class="TblHdr">Address</td>' +
            '<td class="TblHdr">ExtName</td></tr>';
  RegRow =  '%0:s<tr>' +
            '<td class="%1:s">%2:s</td>' +
            '<td class="%1:s">%3:s</td>' +
            '<td class="%1:s">%4:s</td>' +
            '<td class="%1:s">%5:s</td>' +
            '<td class="%1:s">%6:d</td>' +
            '<td class="%1:s">%7:s</td></tr>';
  RegFtr =  '</table></center>';

var
  Path: string;
  HostScriptBaseURL: String;

  function ValidIntfName(const Entries: TInvRegIntfEntryArray;  const name: string): Boolean;
  var
    Entry: InvRegIntfEntry;
    I: Integer;
  begin
    Result := False;
    if Length(Entries) > 0 then
    begin
      for I := 0 to Length(Entries)-1 do
      begin
        Entry := Entries[I];
        if Entry.Name = name then
        begin
          Result := True;
          Exit;
        end;
      end;
    end;
  end;

  function GetReturnStr(const RInfo: PTypeInfo): string;
  var
    IsScalar: Boolean;
    URI, Name: WideString;
  begin
    Result := 'void ';          { Do not localize }
    if RInfo <> nil then
    begin
      if RemClassRegistry.InfoToURI(RInfo, URI, Name, IsScalar) then
        Result := Name + ' '
      else
        Name := '????';         { Do not localize }
    end;
  end;

  function GetParams(const Params: TIntfParamEntryArray): string;
  const
    Commas : array[Boolean] of string = ('', ', ');
  var
    I: Integer;
    Param: TIntfParamEntry;
    PName, TName: string;
    IsScalar: Boolean;
    URI, Name: WideString;
  begin
    Result := '';
    if Length(Params) > 0 then
    begin
      for I := 0 to Length(Params)-1 do
      begin
        Param := Params[I];
        if Param.Info = nil then
          continue;
        if RemClassRegistry.InfoToURI(Param.Info, URI, Name, IsScalar) then
          TName := Name
        else
          TName := '????';    { Do not localize }
        PName := Param.Name;
        Result:= Format('%s' +                                    { Do not localize }
                        '<span class="MethName">%s</span>'+       { Do not localize }
                        '<span class="ParmName">%s</span>'+       { Do not localize }
                        '<span class="MethName">&nbsp;%s</span>', { Do not localize }
                        [Result, Commas[Length(Result)>0], TName, PName]);
      end;
    end;
  end;

  function GetInterfaceInfo(const name: string): string;
  var
    Entries: TInvRegIntfEntryArray;
    Entry: InvRegIntfEntry;
    I, J: Integer;
    IntfInfo: PTypeInfo;
    IntfMD: TIntfMetaData;
    MethEntry: TIntfMethEntry;
    Namespace: string;
    IntfName : string;
    FuncSig, RetStr: string;
  begin;
    Result := '';
    Pub.GetPortTypeEntries(Entries);

    { Check if it's for a special interface }
    if name <> '' then
    begin
      if ValidIntfName(Entries, name) then
        IntfName := name
      else
        IntfName := '';
    end;

    if Length(Entries) > 0 then
    begin
      if IntfName = '' then
        Result := IntfHdr1 + Format(sServiceInfo, [ServiceName]) + IntfHdr3
      else
        Result := IntfHdr2 + Format(sInterfaceInfo, [HostScriptBaseURL, ServiceName, IntfName]) + IntfHdr3;

      for I := 0 to Length(Entries)-1 do
      begin
        Entry := Entries[I];
        if (IntfName <> '') and (Entry.Name <> IntfName) then
          continue;

        IntfInfo := InvRegistry.GetInterfaceTypeInfo(Entry.GUID);
        GetIntfMetaData(IntfInfo, IntfMD);
        Result := Result + IntfBeg;
        { Display linked or plain version of interface name }
        if (IntfName <> '') then
          Result := Result + Format(IntfEntP, [IntfMD.Name])
        else
          Result := Result + Format(IntfEntL, [IntfMD.Name, HostScriptBaseURL]);
        { Add link to WSDL }
        Result := Result + Format(IntfWSDL, [HostScriptBaseURL + '/wsdl/'+IntfMD.Name]);
        if IntfName <> '' then
        begin
          Namespace:= InvRegistry.GetNamespaceByGUID(Entry.GUID);
          Result := Result + Format(IntfNS, [Namespace]);
        end;
        if Entry.Documentation <> '' then
        begin
          Result := Result + IntDoc1;
          Result := Result + Format(IntDoc2, [Entry.Documentation]);
        end;
        if Length(IntfMD.MDA) > 0 then
        begin
          if IntfName <> '' then
            Result := Result + MethBeg2;
          for J := 0 to Length(IntfMD.MDA)-1 do
          begin
            MethEntry := IntfMD.MDA[J];
            if IntfName <> '' then
            begin
              FuncSig:= Format(MethEnt3, [IntfMD.MDA[J].Name, GetParams(MethEntry.Params)]);
              RetStr := GetReturnStr(MethEntry.ResultInfo);
              Result := Result + Format(MethEnt2, [RetStr, FuncSig]);
            end
            else
            begin
              Result := Result + MethBeg + Format(MethEnt, [IntfMD.MDA[J].Name]) + MethEnd;
            end;
          end;
          if IntfName <> '' then
            Result := Result + MethEnd2;
        end;
        Result := Result + IntfEnd;
      end;
      Result := Result + IntfFtr;
    end;
  end;

  function GetRegisteredTypes: string;
  var
    I: Integer;
    Entry: TRemRegEntry;
    ObjName: string;
    InfoName: string;
    Style: string;
  begin
    Result := '';
    if RemClassRegistry.GetURICount > 0 then
    begin
      Result := RegHdr;
      for I := 0 to RemClassRegistry.GetURICount-1 do
      begin
        RemClassRegistry.GetURIMap(I, Entry);
        if Assigned(Entry.ClassType) then
          ObjName := Entry.ClassType.ClassName
        else
          ObjName := '';
        InfoName := Entry.Info.Name;
        Style := TblCls[I and 1 = 0];
        Result := Format(RegRow, [Result, Style, InfoName, Entry.Name, Entry.URI, ObjName, Integer(Entry.Info), Entry.ExtName]);
      end;
      Result := Result + RegFtr;
    end;
  end;
var
  RegTypes: string;
  IntfInfo: string;
  IntfName: string;
begin
  HostScriptBaseURL := GetHostScriptBaseURL(Request);
  Path := Request.InternalPathInfo;

  try
    if (Request.QueryFields.Values[sQueryStringTypes] = '1' ) then
      RegTypes := GetRegisteredTypes;
  except
    { Don't let retrieval of bad types bring us down - IOW, since there's no way to enforce
      registration or registration of valid types, for that matter, let's be safe }
  end;

  { See if request was for a special interface }
  IntfName := Request.QueryFields.Values[sQueryStringIntf];
  IntfInfo := GetInterfaceInfo(IntfName);

  Response.Content := Format(HTMLTopTNoM, [ServiceName]) +
                      InfoTitle1 +
                      Format(InfoTitle2, [ServiceName, sServiceInfoPage]) +
                      IntfInfo + RegTypes +
                      HTMLEnd;
  Handled := True;
end;

function TWSDLHTMLPublish.GetTargetNamespace: WideString;
begin
  if (FTargetNamespace <> '') then
    Result := FTargetNamespace
  else
    Result := WSDLIntf.tns;
end;

procedure TWSDLHTMLPublish.SetWebDispatch(const Value: TWebDispatch);
begin
 FWebDispatch.Assign(Value);
end;


initialization
  { IWSDLPublish registration }
  InvRegistry.RegisterInterface(TypeInfo(IWSDLPublish), SBorlandTypeNamespace,
                                '', IWSDLPublishDoc);
  InvRegistry.RegisterDefaultSOAPAction(TypeInfo(IWSDLPublish),
                                        SBorlandTypeNamespace + '-IWSDLPublish');
  InvRegistry.RegisterInvokableClass(TWSDLPublish);

  { Admin Ini File }
  GetModuleFileName(HInstance, ModuleName, SizeOf(ModuleName));
  ServicePath := Copy(ModuleName, 1, StrLen(ModuleName) - Cardinal(Length(ExtractFileExt(ModuleName))));
  ServiceName := ExtractFileName(ServicePath);
  AdminIniFile:= ServicePath + '_WSDLADMIN.INI';  { do not localize } 
end.
