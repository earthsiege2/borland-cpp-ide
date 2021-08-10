
{*******************************************************}
{                                                       }
{       Borland Delphi Visual Component Library         }
{                                                       }
{       Copyright (c) 1999 Inprise Corporation          }
{                                                       }
{*******************************************************}

unit PagItems;

interface

uses Classes, Messages, ImgList, HTTPApp, WebComp,
  CompProd;

type

  TPageItemsProducer = class(TComponentsPageProducer, IGetWebComponentList)
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

implementation

constructor TPageItemsProducer.Create(AOwner: TComponent);
begin
  inherited;
  FWebPageItems := TWebComponentList.Create(Self);
end;

destructor TPageItemsProducer.Destroy;
begin
  inherited;
  FWebPageItems.Free;
end;

procedure TPageItemsProducer.GetChildren(Proc: TGetChildProc; Root: TComponent);
var
  I: Integer;
  WebComponent: TComponent;
begin
  for I := 0 to FWebPageItems.Count - 1 do
  begin
    WebComponent := FWebPageItems.WebComponents[I];
    if WebComponent.Owner = Root then Proc(WebComponent);
  end;
end;

function TPageItemsProducer.GetComponentList: TObject;
begin
  Result := FWebPageItems;
end;

function TPageItemsProducer.GetDefaultComponentList: TObject;
begin
  Assert(False, 'No default components list');
  Result := nil;
end;

procedure TPageItemsProducer.SetChildOrder(Component: TComponent;
  Order: Integer);
var
  Intf: IWebComponent;
begin
  if FWebPageItems.IndexOf(Component) >= 0 then
    if Component.GetInterface(IWebComponent, Intf) then
      Intf.Index := Order
    else
      Assert(False, 'Interface not supported');
end;

end.

