{*******************************************************}
{                                                       }
{       Borland Delphi Visual Component Library         }
{                                                       }
{       Copyright (c) 1997,99 Inprise Corporation       }
{                                                       }
{*******************************************************}

unit mxdimedt;

interface

uses
 Windows, Messages, SysUtils, Classes, Controls, StdCtrls, Graphics, DB,
 Grids, Forms, ExtCtrls, mxConsts, mxgrid, mxdb, mxstore, mxdconst,
 DsgnIntf, DsgnWnds;

type
  TDimEditor = class(TDesignWindow)
    DimListBox1: TListBox;
    procedure DimListBox1Click(Sender: TObject);
  private
    myDims: TCollection;
    myForm: TCustomForm;
    myDesigner: IFormDesigner;
    myObject: TComponent;
    procedure UpdateSelection;
    procedure UpdateList;
  protected
    function UniqueName(Component: TComponent): string; override;
    procedure Activated; override;
  public
    procedure ComponentDeleted(Component: IPersistent); override;
    procedure FormClosed(AForm: TCustomForm); override;
    procedure FormModified; override;
  end;

procedure ShowDisplayDimEditor(const Designer: IDesigner; anObject: TComponent);

implementation

{$R *.DFM}

procedure ShowDisplayDimEditor(const Designer: IDesigner; anObject: TComponent);
var
  aForm: TDimEditor;
begin
  aForm := TDimEditor.Create(application);
  aForm.myDesigner := Designer as IFormDesigner;
  aForm.myForm := Designer.Form;
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
var
  Msg: TMessage;
begin
  Msg.Msg := WM_ACTIVATE;
  Msg.WParam := 1;
  myDesigner.IsDesignMsg(myForm, Msg);
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
  ComponentList: TDesignerSelectionList;
begin
  bSelected := False;
  if not assigned(myDims) then Exit;
  ComponentList := TDesignerSelectionList.Create;
  try
    with DimListBox1 do
      for I := 0 to Items.Count - 1 do
        if Selected[I] then
        begin
          bSelected := True;
          ComponentList.Add(myDims.Items[i]);
        end;
  except
    ComponentList.Free;
    raise;
  end;
  if not bSelected then
    ComponentList.Free
  else
    myDesigner.SetSelections(ComponentList);
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
procedure TDimEditor.ComponentDeleted(Component: IPersistent);
begin
  if ExtractPersistent(Component) = myObject then Close;
end;

procedure TDimEditor.FormClosed(AForm: TCustomForm);
begin
  if (myForm = AForm) then Close;
end;

procedure TDimEditor.FormModified;
begin
  UpdateList;
  UpdateSelection;
end;

procedure TDimEditor.DimListBox1Click(Sender: TObject);
begin
  UpdateSelection;
end;

end.
