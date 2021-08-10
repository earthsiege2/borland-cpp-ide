{*******************************************************}
{                                                       }
{       Borland Delphi Visual Component Library         }
{                                                       }
{       Copyright (c) 1997,99 Inprise Corporation       }
{                                                       }
{*******************************************************}

unit MXDIMEDT;

interface

uses
 Windows, Messages, SysUtils, Classes, Controls, StdCtrls, Graphics, DB,
 Grids, Forms, ExtCtrls, Mxconsts, MXGRID, MXDB, Mxstore, MXDCONST,
 DesignIntf, DesignEditors, DesignWindows;

type
  TDimEditor = class(TDesignWindow)
    DimListBox1: TListBox;
    procedure DimListBox1Click(Sender: TObject);
  private
    myDims: TCollection;
    myForm: TCustomForm;
    myDesigner: IDesigner;
    myObject: TComponent;
    procedure UpdateSelection;
    procedure UpdateList;
  protected
    function UniqueName(Component: TComponent): string; override;
    procedure Activated; override;
  public
    procedure ItemDeleted(const ADesigner: IDesigner; AItem: TPersistent); override;
    procedure DesignerClosed(const ADesigner: IDesigner; AGoingDormant: Boolean); override;
    procedure ItemsModified(const ADesigner: IDesigner); override;
  end;

procedure ShowDisplayDimEditor(const Designer: IDesigner; anObject: TComponent);

implementation

{$R *.dfm}

procedure ShowDisplayDimEditor(const Designer: IDesigner; anObject: TComponent);
var
  aForm: TDimEditor;
begin
  aForm := TDimEditor.Create(application);
  aForm.myDesigner := Designer as IDesigner;
  aForm.myForm := Designer.Root as TCustomForm;
  aForm.myObject := anObject;
  aForm.Caption := sGridDimOptions;
  if (anObject is TDecisionGrid) then
  begin
    aForm.myDims := TDecisionGrid(anObject).Dimensions;
    aForm.Caption := sGridDimSettings;
  end
  else if (anObject is TDecisionCube) then
  begin
    aForm.myDims := TDecisionCube(anObject).DimensionMap;
    aForm.Caption := sCubeProperties;
  end
  else
    Exit;
  aForm.UpdateList;
  aForm.Show;
end;

procedure TDimEditor.Activated;
begin
  myDesigner.Activate;
  UpdateSelection;
end;

function TDimEditor.UniqueName(Component: TComponent): string;
begin
  Result := 'xxyss';
end;

procedure TDimEditor.UpdateSelection;
var
  i: Integer;
  bSelected: Boolean;
  List: IDesignerSelections;
begin
  bSelected := False;
  if not assigned(myDims) then Exit;

  List := CreateSelectionList;
  with DimListBox1 do
    for I := 0 to Items.Count - 1 do
      if Selected[I] then
      begin
        bSelected := True;
        List.Add(myDims.Items[i]);
      end;

  if bSelected then
    myDesigner.SetSelections(List);
end;

procedure TDimEditor.UpdateList;
var
  i: Integer;
begin
  if not assigned(myDims) then Exit;
  DimListBox1.Clear;
  for I := 0 to myDims.count-1 do
  begin
    if (myObject is TDecisionGrid) then
      DimListBox1.Items.Add(TDecisionGrid(myObject).Dimensions[i].FieldName)
    else if (myObject is TDecisionCube) then
      DimListBox1.Items.Add(TDecisionCube(myObject).DimensionMap[i].FieldName)
    else
      DimListBox1.Items.Add('# ' + inttostr(i + 1));
  end;
end;

procedure TDimEditor.ItemDeleted(const ADesigner: IDesigner; AItem: TPersistent);
begin
  if AItem = myObject then Close;
end;

procedure TDimEditor.DesignerClosed(const ADesigner: IDesigner; AGoingDormant: Boolean);
begin
  if (myForm = ADesigner.Root) then Close;
end;

procedure TDimEditor.ItemsModified(const ADesigner: IDesigner);
begin
  UpdateList;
  UpdateSelection;
end;

procedure TDimEditor.DimListBox1Click(Sender: TObject);
begin
  UpdateSelection;
end;

end.