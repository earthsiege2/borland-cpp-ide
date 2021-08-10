{*******************************************************}
{                                                       }
{       Borland Delphi Visual Component Library         }
{                                                       }
{       Copyright (c) 1995,99 Inprise Corporation       }
{                                                       }
{*******************************************************}

unit DSProd;

interface

uses Classes, HTTPApp, DB;

type
  TDataSetPageProducer = class(TPageProducer)
  private
    FDataSet: TDataSet;
  protected
    function GetDataSet: TDataSet; virtual;
    procedure SetDataSet(ADataSet: TDataSet); virtual;
    procedure Notification(AComponent: TComponent; Operation: TOperation); override;
    procedure DoTagEvent(Tag: TTag; const TagString: string; TagParams: TStrings;
      var ReplaceText: string); override;
  public
    function Content: string; override;
  published
    property DataSet: TDataSet read GetDataSet write SetDataSet;
    property OnHTMLTag;
  end;

implementation

function TDataSetPageProducer.GetDataSet: TDataSet;
begin
  Result := FDataSet;
end;

procedure TDataSetPageProducer.SetDataSet(ADataSet: TDataSet);
begin
  if FDataSet <> ADataSet then
  begin
    if ADataSet <> nil then ADataSet.FreeNotification(Self);
    FDataSet := ADataSet;
  end;
end;

procedure TDataSetPageProducer.Notification(AComponent: TComponent; Operation: TOperation);
begin
  inherited Notification(AComponent, Operation);
  if (Operation = opRemove) and (AComponent = FDataSet) then
    FDataSet := nil;
end;

procedure TDataSetPageProducer.DoTagEvent(Tag: TTag; const TagString: string;
  TagParams: TStrings; var ReplaceText: string);
var
  Field: TField;
begin
  if (TagParams.Count = 0) and Assigned(FDataSet) then
  begin
    Field := FDataSet.FindField(TagString);
    if Assigned(Field) then
        ReplaceText := Field.DisplayText;
  end;
  inherited DoTagEvent(Tag, TagString, TagParams, ReplaceText);
end;

function TDataSetPageProducer.Content: string;
begin
  if (FDataSet <> nil) and not FDataSet.Active then
    FDataSet.Open;
  Result := inherited Content;
end;

end.
