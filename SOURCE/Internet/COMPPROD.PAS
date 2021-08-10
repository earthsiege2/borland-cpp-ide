{*******************************************************}
{                                                       }
{       Borland Delphi Visual Component Library         }
{                                                       }
{       Copyright (c) 1995-2001 Borland Software Corp.  }
{                                                       }
{*******************************************************}

unit CompProd;

interface

uses Classes, HTTPApp, HTTPProd, WebComp;

type
  TComponentsPageProducer = class(TBasePageProducer)
  protected
    function FindComponent(TagParams: TStrings): TComponent; virtual;
    function FindComponentName(TagParams: TStrings): string;
    function GetComponentContent(TagParams: TStrings): string; virtual;
    procedure DoTagEvent(Tag: TTag; const TagString: string; TagParams: TStrings;
      var ReplaceText: string); override;
    function GetContentOptions(var Owned: Boolean): TWebContentOptions; virtual;
    function HandleTag(const TagString: string;
      TagParams: TStrings): string; override;
  published
    property OnHTMLTag;
  end;

implementation

uses SysUtils;

procedure TComponentsPageProducer.DoTagEvent(Tag: TTag; const TagString: string;
  TagParams: TStrings; var ReplaceText: string);
begin
  if Tag = tgCustom then
  begin
    if CompareText(TagString, 'COMPONENT') = 0 then
    begin
      ReplaceText := GetComponentContent(TagParams);
      Exit;
    end;
  end;
  inherited DoTagEvent(Tag, TagString, TagParams, ReplaceText);
end;

function TComponentsPageProducer.FindComponentName(TagParams: TStrings): string;
begin
  Result := TagParams.Values['Name'];
end;

function TComponentsPageProducer.FindComponent(TagParams: TStrings): TComponent;
var
  ComponentName: string;
begin
  ComponentName := FindComponentName(TagParams);
  if ComponentName <> '' then
    if Owner <> nil then
    begin
      Result := Owner.FindComponent(ComponentName);
      Exit;
    end;
  Result := nil;
end;

function TComponentsPageProducer.GetComponentContent(TagParams: TStrings): string;
var
  Component: TComponent;
  ContentIntf: IWebContent;
  Options: TWebContentOptions;
  Owned: Boolean;
begin
  Component := FindComponent(TagParams);
  if Assigned(Component) then
    if Supports(Component, IWebContent, ContentIntf) then
    begin
      Options := GetContentOptions(Owned);
      try
        Result := ContentIntf.Content(Options, nil);
      finally
        if Owned then
          Options.Free;
      end;
    end;
end;

function TComponentsPageProducer.GetContentOptions(var Owned: Boolean): TWebContentOptions;
begin
  Owned := True;
  Result := TWebContentOptions.Create([]);
end;

function TComponentsPageProducer.HandleTag(const TagString: string;
  TagParams: TStrings): string;
begin
  Result := ImplHandleTag(TagString, TagParams);
end;

end.
