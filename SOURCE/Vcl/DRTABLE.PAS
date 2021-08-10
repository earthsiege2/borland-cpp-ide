{*******************************************************}
{                                                       }
{       Borland Delphi Visual Component Library         }
{                                                       }
{       Copyright (c) 1995,99 Inprise Corporation       }
{                                                       }
{*******************************************************}

unit DRTable;

interface

uses Windows, SysUtils, Classes, BDE, DB, DBTables;

type

{ TDRList }

  TDRList = class(TBdeDataSet)
  protected
    function CreateHandle: HDBICur; override;
  end;

{ TDRDataSet }

  TDRDataSet = class(TBdeDataSet)
  private
    FDBIDR: HDBIDR;
  public
    property DRHandle: HDBIDR read FDBIDR write FDBIDR;
  end;

{ TDRObjectDescList }

  TDRObjectDescList = class(TDRDataSet)
  protected
    function CreateHandle: HDBICur; override;
  end;

{ TDRObjectItems }

  TDRObjectItems = class(TDRDataset)
  protected
    FObjectName: string;
  end;

{ TDRRelationshipDescList }

  TDRRelationshipDescList = class(TDRObjectItems)
  protected
    function CreateHandle: HDBICur; override;
  published
    property ObjectTypeName: string read FObjectName write FObjectName;
  end;

{ TDRAttrDescList }

  TDRAttrDescList = class(TDRObjectItems)
  protected
    function CreateHandle: HDBICur; override;
  published
    property TypeName: string read FObjectName write FObjectName;
  end;

{ TDRInstanceItems }

  TDRInstanceItems = class (TDRObjectItems)
  private
    FCond: string;
  published
    property Condition: string read FCond write FCond;
  end;

{ TDRObjectList }

  TDRObjectList = class(TDRInstanceItems)
  private
    FRelName: string;
    FSource: DRObject;
  protected
    function CreateHandle: HDBICur; override;
  public
    procedure NavigateFrom(const ASource: DRObject; const ARelationship: string);
  published
    property ObjectTypeName: string read FObjectName write FObjectName;
  end;

{ TDRRelationshipList }

  TDRRelationshipList = class(TDRInstanceItems)
  private
    FSource, FTarget: DRObject;
  protected
    function CreateHandle: HDBICur; override;
  public
    procedure NavigateFromTo(const ASource, ATarget: DRObject);
  published
    property RelationshipTypeName: string read FObjectName write FObjectName;
  end;

{ TQueryDescription }

  TQueryDescription = class(TBdeDataset)
  private
    FQuery: TQuery;
    FPrepared: Boolean;
  protected
    function CreateHandle: HDBICur; override;
    procedure DestroyHandle; override;
    procedure OpenCursor(InfoQuery: Boolean); override;
  public
    property Query: TQuery read FQuery write FQuery;
  end;

const
  NullDRObject: DRObject = (ulObjId: 0; iVersion: 0);

{ **************************************************************************** }

implementation

{ TDRList }

function TDRList.CreateHandle: HDBICur;
begin
  Check(DbiOpenRepositoryList(Result));
end;

{ TDRObjectDescList }

function TDRObjectDescList.CreateHandle: HDBICur;
begin
  Check(DbiDROpenObjectTypeList(DRHandle, Result));
end;

{ TDRRelationshipDescList }

function TDRRelationshipDescList.CreateHandle: HDBICur;
begin
  Check(DbiDROpenRelTypeList(DRHandle, PChar(ObjectTypeName), Result));
end;

{ TDRAttrDescList }

function TDRAttrDescList.CreateHandle: HDBICur;
begin
  Check(DbiDROpenAttrTypeList(DRHandle, PChar(TypeName), Result));
end;

{ TDRObjectList }

function TDRObjectList.CreateHandle: HDBICur;
begin
  Check(DbiDROpenObjSet(DRHandle, PChar(ObjectTypeName), @FSource, Pointer(FRelName),
    Pointer(Condition), Result));
end;

procedure TDRObjectList.NavigateFrom(const ASource: DRObject; const
  ARelationship: string);
begin
  FSource := ASource;
  FRelName := ARelationship;
end;

{ TDRRelationshipList }

function TDRRelationshipList.CreateHandle: HDBICur;
var
  PS, PT: pDRObject;
begin
  if FSource.ulObjId = 0 then PS := nil
  else PS := @FSource;
  if FTarget.ulObjId = 0 then PT := nil
  else PT := @FTarget;
  Check(DbiDROpenRelSet(DRHandle, PChar(RelationshipTypeName), PS, PT,
    Pointer(Condition), Result));
end;

procedure TDRRelationshipList.NavigateFromTo(const ASource, ATarget: DRObject);
begin
  FSource := ASource;
  FTarget := ATarget;
end;

{ TQueryDescription }

function TQueryDescription.CreateHandle: HDBICur;
begin
  Result := nil;
  if Assigned(Query) then
  begin
    if Query.StmtHandle = nil then
    begin
      Query.Prepare;
      FPrepared := True;
    end;
    Check(DBIQGetBaseDescs(Query.StmtHandle, Result));
  end;
end;

procedure TQueryDescription.DestroyHandle;
begin
  inherited DestroyHandle;
  if FPrepared then Query.UnPrepare;
end;

procedure TQueryDescription.OpenCursor(InfoQuery: Boolean);
begin
  inherited OpenCursor(InfoQuery);
  if Assigned(Query) then SetLocale(Query.Locale);
end;

end.
