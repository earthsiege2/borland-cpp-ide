
{*******************************************************}
{                                                       }
{       Borland Delphi Visual Component Library         }
{                                                       }
{  Copyright (c) 1999-2001 Borland Software Corp.       }
{                                                       }
{*******************************************************}

unit PagItems;

interface

uses Classes,  HTTPApp, WebComp,
  CompProd, SysUtils;

type

  TBasePageItemsProducer = class(TComponentsPageProducer, IGetWebComponentList, ITopLevelWebComponent)
  private
    FWebPageItems: TWebComponentList;
  protected
    { IGetWebComponentsList }
    function GetComponentList: TObject;
    function GetDefaultComponentList: TObject;
    procedure GetChildren(Proc: TGetChildProc; Root: TComponent); override;
    procedure SetChildOrder(Component: TComponent; Order: Integer); override;
  public
    constructor Create(AOwner: TComponent); override;
    destructor Destroy; override;
    property WebPageItems: TWebComponentList read FWebPageItems;
  end;

  TPageItemsProducer = class(TBasePageItemsProducer)
  private
    FHTMLFile: TFileName;
    FHTMLDoc: TStrings;
    procedure SetHTMLFile(const Value: TFileName);
    procedure SetHTMLDoc(Value: TStrings);
  protected
    function GetTemplateStream(out AOwned: Boolean): TStream; override;
  public
    constructor Create(AOwner: TComponent); override;
    destructor Destroy; override;
    property HTMLDoc: TStrings read FHTMLDoc write SetHTMLDoc;
    property HTMLFile: TFileName read FHTMLFile write SetHTMLFile;
  end;

implementation

constructor TBasePageItemsProducer.Create(AOwner: TComponent);
begin
  FWebPageItems := TWebComponentList.Create(Self);
  inherited;
end;

destructor TBasePageItemsProducer.Destroy;
begin
  inherited;
  FWebPageItems.Free;
end;

procedure TBasePageItemsProducer.GetChildren(Proc: TGetChildProc; Root: TComponent);
var
  I: Integer;
  WebComponent: TComponent;
begin
  inherited GetChildren(Proc, Root);
  for I := 0 to FWebPageItems.Count - 1 do
  begin
    WebComponent := FWebPageItems.WebComponents[I];
    if WebComponent.Owner = Root then Proc(WebComponent);
  end;
end;

function TBasePageItemsProducer.GetComponentList: TObject;
begin
  Result := FWebPageItems;
end;

function TBasePageItemsProducer.GetDefaultComponentList: TObject;
begin
  Assert(False, 'No default components list');  { Do not localize }
  Result := nil;
end;

procedure TBasePageItemsProducer.SetChildOrder(Component: TComponent;
  Order: Integer);
var
  Intf: IWebComponent;
begin
  if FWebPageItems.IndexOf(Component) >= 0 then
    if Supports(IInterface(Component), IWebComponent, Intf) then
      Intf.Index := Order
    else
      Assert(False, 'Interface not supported');
end;

{ TPageItemsProducer }

constructor TPageItemsProducer.Create(AOwner: TComponent);
begin
 FHTMLDoc := TStringList.Create;
  inherited;
end;

destructor TPageItemsProducer.Destroy;
begin
  inherited;
  FHTMLDoc.Free;
end;

function TPageItemsProducer.GetTemplateStream(out AOwned: Boolean): TStream;
begin
  AOwned := True;
  if FHTMLFile <> '' then
    Result := TFileStream.Create(FHTMLFile, fmOpenRead + fmShareDenyWrite)
  else Result := TStringStream.Create(FHTMLDoc.Text);
end;

procedure TPageItemsProducer.SetHTMLFile(const Value: TFileName);
begin
  if CompareText(FHTMLFile, Value) <> 0 then
  begin
    FHTMLDoc.Clear;
    FHTMLFile := Value;
  end;
end;

procedure TPageItemsProducer.SetHTMLDoc(Value: TStrings);
begin
  FHTMLDoc.Assign(Value);
  FHTMLFile := '';
end;

end.

