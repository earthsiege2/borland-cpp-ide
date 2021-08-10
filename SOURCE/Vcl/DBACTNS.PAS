
{*******************************************************}
{                                                       }
{       Borland Delphi Visual Component Library         }
{                                                       }
{       Copyright (c) 1999 Inprise Corporation          }
{                                                       }
{*******************************************************}

unit DBActns;

{$H+,X+}

interface

uses Classes, ActnList, Db;

type
  { DataSet actions }
  TDataSetAction = class(TAction)
  private
    FDataSource: TDataSource;
    procedure SetDataSource(Value: TDataSource);
  protected
    function GetDataSet(Target: TObject): TDataSet; virtual;
    procedure Notification(AComponent: TComponent; Operation: TOperation); override;
  public
    function HandlesTarget(Target: TObject): Boolean; override;
    property DataSource: TDataSource read FDataSource write SetDataSource;
  end;

  TDataSetFirst = class(TDataSetAction)
  public
    procedure ExecuteTarget(Target: TObject); override;
    procedure UpdateTarget(Target: TObject); override;
  published
    property DataSource;
  end;

  TDataSetPrior = class(TDataSetAction)
  public
    procedure ExecuteTarget(Target: TObject); override;
    procedure UpdateTarget(Target: TObject); override;
  published
    property DataSource;
  end;

  TDataSetNext = class(TDataSetAction)
  public
    procedure ExecuteTarget(Target: TObject); override;
    procedure UpdateTarget(Target: TObject); override;
  published
    property DataSource;
  end;

  TDataSetLast = class(TDataSetAction)
  public
    procedure ExecuteTarget(Target: TObject); override;
    procedure UpdateTarget(Target: TObject); override;
  published
    property DataSource;
  end;

  TDataSetInsert = class(TDataSetAction)
  public
    procedure ExecuteTarget(Target: TObject); override;
    procedure UpdateTarget(Target: TObject); override;
  published
    property DataSource;
  end;

  TDataSetDelete = class(TDataSetAction)
  public
    procedure ExecuteTarget(Target: TObject); override;
    procedure UpdateTarget(Target: TObject); override;
  published
    property DataSource;
  end;

  TDataSetEdit = class(TDataSetAction)
  public
    procedure ExecuteTarget(Target: TObject); override;
    procedure UpdateTarget(Target: TObject); override;
  published
    property DataSource;
  end;

  TDataSetPost = class(TDataSetAction)
  public
    procedure ExecuteTarget(Target: TObject); override;
    procedure UpdateTarget(Target: TObject); override;
  published
    property DataSource;
  end;

  TDataSetCancel = class(TDataSetAction)
  public
    procedure ExecuteTarget(Target: TObject); override;
    procedure UpdateTarget(Target: TObject); override;
  published
    property DataSource;
  end;

  TDataSetRefresh = class(TDataSetAction)
  public
    procedure ExecuteTarget(Target: TObject); override;
    procedure UpdateTarget(Target: TObject); override;
  published
    property DataSource;
  end;

implementation

{ TDataSetAction }

function TDataSetAction.GetDataSet(Target: TObject): TDataSet;
begin
  { We could cast Target as a TDataSource since HandlesTarget "should" be
    called before ExecuteTarget and UpdateTarget, however, we're being safe. }
  Result := (Target as TDataSource).DataSet;
end;

function TDataSetAction.HandlesTarget(Target: TObject): Boolean;
begin
  { Only handle Target if we don't already have a DataSource assigned and the
    Target is a TDataSource with a non nil DataSet assigned. }
  Result := (DataSource <> nil) and (Target = DataSource) and
    (DataSource.DataSet <> nil) or (DataSource = nil) and
    (Target is TDataSource) and (TDataSource(Target).DataSet <> nil);
end;

procedure TDataSetAction.Notification(AComponent: TComponent;
  Operation: TOperation);
begin
  inherited Notification(AComponent, Operation);
  if (Operation = opRemove) and (AComponent = DataSource) then DataSource := nil;
end;

procedure TDataSetAction.SetDataSource(Value: TDataSource);
begin
  if Value <> FDataSource then
  begin
    FDataSource := Value;
    if Value <> nil then Value.FreeNotification(Self);
  end;
end;

{ TDataSetFirst }

procedure TDataSetFirst.ExecuteTarget(Target: TObject);
begin
  GetDataSet(Target).First;
end;

procedure TDataSetFirst.UpdateTarget(Target: TObject);
begin
  with GetDataSet(Target) do
    Enabled := Active and not Bof;
end;

{ TDataSetPrior }

procedure TDataSetPrior.ExecuteTarget(Target: TObject);
begin
  GetDataSet(Target).Prior;
end;

procedure TDataSetPrior.UpdateTarget(Target: TObject);
begin
  with GetDataSet(Target) do
    Enabled := Active and not Bof;
end;

{ TDataSetNext }

procedure TDataSetNext.ExecuteTarget(Target: TObject);
begin
  GetDataSet(Target).Next;
end;

procedure TDataSetNext.UpdateTarget(Target: TObject);
begin
  with GetDataSet(Target) do
    Enabled := Active and not Eof;
end;

{ TDataSetLast }

procedure TDataSetLast.ExecuteTarget(Target: TObject);
begin
  GetDataSet(Target).Last;
end;

procedure TDataSetLast.UpdateTarget(Target: TObject);
begin
  with GetDataSet(Target) do
    Enabled := Active and not Eof;
end;

{ TDataSetInsert }

procedure TDataSetInsert.ExecuteTarget(Target: TObject);
begin
  GetDataSet(Target).Insert;
end;

procedure TDataSetInsert.UpdateTarget(Target: TObject);
begin
  with GetDataSet(Target) do
    Enabled := Active and CanModify;
end;

{ TDataSetRefresh }

procedure TDataSetRefresh.ExecuteTarget(Target: TObject);
begin
  GetDataSet(Target).Refresh;
end;

procedure TDataSetRefresh.UpdateTarget(Target: TObject);
begin
  with GetDataSet(Target) do
    Enabled := Active and CanModify;
end;

{ TDataSetPost }

procedure TDataSetPost.ExecuteTarget(Target: TObject);
begin
  GetDataSet(Target).Post;
end;

procedure TDataSetPost.UpdateTarget(Target: TObject);
begin
  with GetDataSet(Target) do
    Enabled := Active and CanModify and (State in dsEditModes);
end;

{ TDataSetCancel }

procedure TDataSetCancel.ExecuteTarget(Target: TObject);
begin
  GetDataSet(Target).Cancel;
end;

procedure TDataSetCancel.UpdateTarget(Target: TObject);
begin
  with GetDataSet(Target) do
    Enabled := Active and CanModify and (State in dsEditModes);
end;

{ TDataSetEdit }

procedure TDataSetEdit.ExecuteTarget(Target: TObject);
begin
  GetDataSet(Target).Edit;
end;

procedure TDataSetEdit.UpdateTarget(Target: TObject);
begin
  with GetDataSet(Target) do
    Enabled := Active and CanModify and not (State in dsEditModes);
end;

{ TDataSetDelete }

procedure TDataSetDelete.ExecuteTarget(Target: TObject);
begin
  GetDataSet(Target).Delete;
end;

procedure TDataSetDelete.UpdateTarget(Target: TObject);
begin
  with GetDataSet(Target) do
    Enabled := Active and CanModify and not (Bof and Eof);
end;

end.
