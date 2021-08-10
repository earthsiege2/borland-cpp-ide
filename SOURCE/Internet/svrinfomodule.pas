{***************************************************************}
{                                                               }
{   Borland Delphi Visual Component Library                     }
{                                                               }
{   Copyright (c) 2000-2001 Borland Software Corporation        }
{                                                               }
{***************************************************************}
unit SvrInfoModule;

interface

uses
  SysUtils, Classes, HTTPApp, HTTPProd;

type
  TWebModule2 = class(TWebModule)
    PageProducerSelect: TPageProducer;
    PageProducerDetails: TPageProducer;
    procedure CleanAction(Sender: TObject; Request: TWebRequest;
      Response: TWebResponse; var Handled: Boolean);
    procedure ServerListPageHTMLTag(Sender: TObject; Tag: TTag;
      const TagString: String; TagParams: TStrings;
      var ReplaceText: String);
  private
    { Private declarations }
  public
    { Public declarations }
  end;

var
  WebModule2: TWebModule2;

implementation

uses WebReq, SvrInfoConst, ActiveX, Windows, ComObj, WebCat;

{$R *.DFM}

procedure GetWebAppClsIDs(List: TStringList);
var
  EnumGUID: IEnumGUID;
  Fetched: Cardinal;
  Guid: TGUID;
  Rslt: HResult;
  CatInfo: ICatInformation;
  I, BufSize: Integer;
  ClassIDKey: HKey;
  S: string;
  Buffer: array[0..255] of Char;
begin
  List.Clear;
  Rslt := CoCreateInstance(CLSID_StdComponentCategoryMgr, nil,
    CLSCTX_INPROC_SERVER, ICatInformation, CatInfo);
  if Succeeded(Rslt) then
  begin
    OleCheck(CatInfo.EnumClassesOfCategories(1, @CATID_WebAppServer, 0, nil, EnumGUID));
    while EnumGUID.Next(1, Guid, Fetched) = S_OK do
      List.Add(GuidToString(Guid));
  end else
  begin
    if RegOpenKey(HKEY_CLASSES_ROOT, 'CLSID', ClassIDKey) <> 0 then   { do not localize }
      try
        I := 0;
        while RegEnumKey(ClassIDKey, I, Buffer, SizeOf(Buffer)) = 0 do
        begin
          S := Format('%s\Implemented Categories\%s',[Buffer,  { do not localize }
            GUIDToString(CATID_WebAppServer)]);
          if RegQueryValue(ClassIDKey, PChar(S), nil, BufSize) = 0 then
            List.Add(Buffer);
          Inc(I);
        end;
      finally
        RegCloseKey(ClassIDKey);
      end;
  end;
end;

function FormatDetail(ARequest: TWebRequest; const AClsID: string): string;
var
  ServerName, FileStatus: string;
  Buttons: string;
  ProgID: string;
begin
  Result := '';
  try
    ProgID := ClassIDToProgID(StringToGuid(AClsID));
  except
    ProgID := '';
  end;
  ServerName := GetRegStringValue('CLSID\' + AClsID + '\LocalServer32', '');      { do not localize }
  Buttons := '';
  Result := Format('%0:s' +
  '<TR><TD align="right">ClSID: </TD><TD><A HREF="%3:s/%7:s">%7:s</A></TD></TR>'#13#10 +       { do not localize }
  '<TR><TD align="right">ProgID: </TD><TD><A HREF="%3:s/%1:s">%1:s</A></TD></TR>'#13#10  +     { do not localize }
  '<TR><TD align="right">LocalServer32: </TD><TD>%6:s<A HREF="%3:s/%5:s">%5:s</A></TD></TR>'#13#10,  { do not localize }
    [Result, ProgID, ServerName, ARequest.ScriptName,
    ARequest.Host, ExtractFileName(ServerName),
    ExtractFilePath(ServerName), AClsID]);
  if ServerName <> '' then
  begin
    if FileExists(ServerName) then
      FileStatus := sFound
    else
      FileStatus := sNotFound;
    Buttons := Format('<FORM Method="POST" Action="%s/Clean">' +           { do not localize }
    '<INPUT TYPE=HIDDEN NAME="ClassID" VALUE="%s"/><INPUT TYPE=SUBMIT VALUE="' + sClean + '"/></FORM>', { do not localize }
     [ARequest.InternalScriptName, AClsID]);
    Result := Format('%0:s<TR><TD align="right">%2:s </TD><TD>%1:s</TD></TR>',   { do not localize }
      [Result, FileStatus, sFileStatus]);
  end;

  Result := Format('<TABLE border=1 width="90%%"><TD><TABLE width="100%%">' +    { do not localize }
  '<TD><TABLE>%0:s</TABLE></TD><TD align="right" valign=top">%1:s</TD>' +        { do not localize }
  '</TABLE></TABLE>', [Result, Buttons]);                                        { do not localize }
end;

function FormatDetails(ARequest: TWebRequest): string;
var
  List1, List2: TStringList;
  I: Integer;
begin
  Result := '';
  List1 := TStringList.Create;
  List2 := TStringList.Create;
  try
    GetWebAppClsIDs(List1);
    for I := 0 to List1.Count - 1 do
    begin
      try
        List2.AddObject(ClassIDToProgID(StringToGUID(List1[I])), TObject(I))
      except
        List2.AddObject('', TObject(I));
      end;
    end;
    // Sort by progid
    List2.Sort;
    for I := 0 to List2.Count - 1 do
      Result := Format('%0:s<p>%1:s', [Result, FormatDetail(ARequest, List1[Integer(List2.Objects[I])])]);
  finally
    List1.Free;
    List2.Free;
  end;
end;

function FormatOption(ARequest: TWebRequest; const AProgID: string): string;
begin
  Result := Format('<OPTION value="%0:s">%0:s</OPTION>', [AProgID]);     { do not localize }
end;

function FormatSelect(ARequest: TWebRequest): string;
var
  List: TStringList;
  I: Integer;
begin
  Result := '';
  List := TStringList.Create;
  try
    GetWebAppClsIDs(List);
    for I := 0 to List.Count - 1 do
      try
        List[I] := ClassIDToProgID(StringToGuid(List[I]));
      except
        List[I] := '';
      end;
    List.Sort;
    for I := 0 to List.Count - 1 do
      if List[I] <> '' then
        Result := Format('%0:s'#13#10'%1:s', [Result, FormatOption(ARequest, List[i])]);
    Result := Format('<SELECT name="S" size="%d" onenter="F.Submit()">'#13#10'%s'#13#10'</SELECT>', [List.Count, Result]);    { do not localize }
  finally
    List.Free;
  end;
  Result := '<FORM name="F" OnSubmit="Go(document.F.S.value);return false">'#13#10 +   { do not localize }
    '<TABLE>'#13#10 +                                                                  { do not localize }
    '<TD>'#13#10 +                                                                     { do not localize }
    Result +                                                                           { do not localize }
    '<TD valign="top">'#13#10 +                                                        { do not localize }
    '<INPUT TYPE=SUBMIT value="' + sGo + '">'#13#10 +                                  { do not localize }
    //'<INPUT TYPE=SUBMIT VALUE="Go" OnClick="Go(document.F.S.value);return false">'#13#10 +   { do not localize }
    '</TABLE>'#13#10 +                                                                 { do not localize }
    '</FORM>'#13#10;                                                                   { do not localize }

end;

procedure TWebModule2.ServerListPageHTMLTag(Sender: TObject; Tag: TTag;
  const TagString: String; TagParams: TStrings; var ReplaceText: String);
begin
  if CompareText(TagString, 'DETAILS') = 0 then                               { do not localize }
    ReplaceText := FormatDetails(Request)
  else if CompareText(TagString, 'LIST') = 0 then                             { do not localize }
    ReplaceText := FormatSelect(Request)
  else if CompareText(TagString, 'PATH') = 0 then                             { do not localize }
    ReplaceText := Request.InternalScriptName + '/';
end;

procedure CleanRegistry(AProgID, AClassID, AServerKey: string);
begin
  if AProgID <> '' then
  begin
    DeleteRegKey('CLSID\' + AClassID + '\ProgID');                              { do not localize }
    DeleteRegKey(AProgID + '\Clsid');                                           { do not localize }
    DeleteRegKey(AProgID);
  end;
  DeleteRegKey('CLSID\' + AClassID + '\' + AServerKey);                         { do not localize }
  DeleteRegKey('CLSID\' + AClassID + '\' + 'Implemented Categories');           { do not localize }
  DeleteRegKey('CLSID\' + AClassID);                                            { do not localize }
end;

procedure TWebModule2.CleanAction(Sender: TObject;
  Request: TWebRequest; Response: TWebResponse; var Handled: Boolean);
var
  Redirect: string;
  ProgID: string;
  ClassID: TGUID;
  CatReg: ICatRegister;
  Rslt: HResult;
  SClassID: string;
begin

  SClassID := Request.ContentFields.Values['ClassID'];                          { do not localize }
  if SClassID = '' then
    raise Exception.Create(sMissingClsID);

  ClassID := StringToGUID(sClassID);
  try
    ProgID := ClassIDToProgID(ClassID);
  finally
    ProgID := '';
  end;
  CleanRegistry(ProgID, SClassID, 'LocalServer32');                             { do not localize }

  Rslt := CoCreateInstance(CLSID_StdComponentCategoryMgr, nil,
    CLSCTX_INPROC_SERVER, ICatRegister, CatReg);
  if Succeeded(Rslt) then
  begin
    OleCheck(CatReg.UnRegisterClassImplCategories(ClassID, 1, @CATID_WebAppServer));
    DeleteRegKey(Format(SCatImplBaseKey, [SClassID]));
  end;

  Redirect := Format('http://%s%s/Details', [Request.Host, Request.InternalScriptName]); { Do not localize }
  Response.SendRedirect(Redirect);
end;

initialization
  WebRequestHandler.WebModuleClass := TWebModule2;

end.
