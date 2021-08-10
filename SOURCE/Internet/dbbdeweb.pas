
{*******************************************************}
{                                                       }
{       Borland Delphi Visual Component Library         }
{       Database Web server application components      }
{                                                       }
{ Copyright (c) 1997, 2001 Borland Software Corporation }
{                                                       }
{*******************************************************}

unit DBBdeWeb;

interface

uses Classes, HTTPApp, DB, DBWeb, DBTables;

type

{ TQueryTableProducer }

  TQueryTableProducer = class(TDSTableProducer)
  private
    FQuery: TQuery;
    procedure SetQuery(AQuery: TQuery);
  protected
    function GetDataSet: TDataSet; override;
    procedure Notification(AComponent: TComponent; Operation: TOperation); override;
    procedure SetDataSet(ADataSet: TDataSet); override;
  public
    function Content: string; override;
  published
    property Caption;
    property CaptionAlignment;
    property Columns;
    property Footer;
    property Header;
    property MaxRows;
    property Query: TQuery read FQuery write SetQuery;
    property RowAttributes;
    property TableAttributes;
    property OnCreateContent;
    property OnFormatCell;
    property OnGetTableCaption;
  end;

implementation

{ TQueryTableProducer }

function TQueryTableProducer.Content: string;
var
  Params: TStrings;
  I: Integer;
  Name: string;
  Param: TParam;
begin
  Result := '';
  if FQuery <> nil then
  begin
    FQuery.Close;
    if FQuery.ParamCount <> 0 then
    begin
      Params := nil;
      if Dispatcher <> nil then
        if Dispatcher.Request.MethodType = mtPost then
          Params := Dispatcher.Request.ContentFields
        else if Dispatcher.Request.MethodType = mtGet then
          Params := Dispatcher.Request.QueryFields;
      if Params <> nil then
        for I := 0 to Params.Count - 1 do
        begin
          Name := Params.Names[I];
          Param := FQuery.Params.ParamByName(Name);
          if Param <> nil then
            Param.Text := Params.Values[Name];
        end;
    end;
    FQuery.Open;
    if DoCreateContent then
      Result := Header.Text + HTMLTable(FQuery, Self, MaxRows) + Footer.Text;
  end;
end;

function TQueryTableProducer.GetDataSet: TDataSet;
begin
  Result := FQuery;
end;

procedure TQueryTableProducer.Notification(AComponent: TComponent; Operation: TOperation);
begin
  inherited Notification(AComponent, Operation);
  if (Operation = opRemove) and (AComponent = FQuery) then
    FQuery := nil;
end;

procedure TQueryTableProducer.SetDataSet(ADataSet: TDataSet);
begin
  SetQuery(ADataSet as TQuery);
end;

procedure TQueryTableProducer.SetQuery(AQuery: TQuery);
begin
  if FQuery <> AQuery then
  begin
    if AQuery <> nil then AQuery.FreeNotification(Self);
    FQuery := AQuery;
    InternalDataSource.DataSet := FQuery;
  end;
end;

end.
