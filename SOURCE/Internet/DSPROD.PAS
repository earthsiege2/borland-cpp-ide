{ *************************************************************************** }
{                                                                             }
{ Delphi and Kylix Cross-Platform Visual Component Library                    }
{ Internet Application Runtime                                                }
{                                                                             }
{ Copyright (C) 1995, 2001 Borland Software Corporation                       }
{                                                                             }
{ Licensees holding a valid Borland No-Nonsense License for this Software may }
{ use this file in accordance with such license, which appears in the file    }
{ license.txt that came with this Software.                                   }
{                                                                             }
{ *************************************************************************** }


unit DSProd;    

interface

uses Classes, HTTPApp, HTTPProd, DB, SysUtils;

type

  TCustomDataSetPageProducer = class(TCustomPageProducer)
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
    property DataSet: TDataSet read GetDataSet write SetDataSet;
  end;

  TDataSetPageProducer = class(TCustomDataSetPageProducer)
  published
    property HTMLDoc;
    property HTMLFile;
    property DataSet;
    property OnHTMLTag;
{$IFDEF MSWINDOWS}
    property ScriptEngine;
{$ENDIF}
  end;

implementation

function TCustomDataSetPageProducer.GetDataSet: TDataSet;
begin
  Result := FDataSet;
end;

procedure TCustomDataSetPageProducer.SetDataSet(ADataSet: TDataSet);
begin
  if FDataSet <> ADataSet then
  begin
    if ADataSet <> nil then ADataSet.FreeNotification(Self);
    FDataSet := ADataSet;
  end;
end;

procedure TCustomDataSetPageProducer.Notification(AComponent: TComponent; Operation: TOperation);
begin
  inherited Notification(AComponent, Operation);
  if (Operation = opRemove) and (AComponent = FDataSet) then
    FDataSet := nil;
end;

procedure TCustomDataSetPageProducer.DoTagEvent(Tag: TTag; const TagString: string;
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

function TCustomDataSetPageProducer.Content: string;
begin
  if (FDataSet <> nil) and not FDataSet.Active then
    FDataSet.Open;
  Result := inherited Content;
end;

end.
