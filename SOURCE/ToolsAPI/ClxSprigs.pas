{ ********************************************************************** }
{                                                                        }
{ Delphi Open-Tools API                                                  }
{                                                                        }
{ Copyright (C) 2000, 2001 Borland Software Corporation                  }
{                                                                        }
{ ********************************************************************** }

unit ClxSprigs;

interface

uses
  Windows, Messages, SysUtils, Classes, QControls, QForms,
  DesignIntf, DesignEditors, TypInfo, Contnrs, TreeIntf;

type
  TControlSprig = class(TComponentSprig)
  public
    constructor Create(AItem: TPersistent); override;
    class function PaletteOverTo(AParent: TSprig; AClass: TClass): Boolean; override;
    function DragOverTo(AParent: TSprig): Boolean; override;
    function DragDropTo(AParent: TSprig): Boolean; override;
  end;

  TWidgetControlSprig = class(TControlSprig)
  public
    constructor Create(AItem: TPersistent); override;
    function DragOver(AItem: TSprig): Boolean; override;
    function DragDrop(AItem: TSprig): Boolean; override;
    function PaletteOver(ASprigClass: TSprigClass; AClass: TClass): Boolean; override;
  end;

  TFrameSprig = class(TWidgetControlSprig)
  public
    constructor Create(AItem: TPersistent); override;
    procedure FigureChildren; override;
  end;

  TWidgetControlRootSprig = class(TRootSprig)
  public
    constructor Create(AItem: TPersistent); override;
    function DragOver(AItem: TSprig): Boolean; override;
    function DragDrop(AItem: TSprig): Boolean; override;
    function PaletteOver(ASprigClass: TSprigClass; AClass: TClass): Boolean; override;
  end;

  TCustomFormRootSprig = class(TWidgetControlRootSprig)
  public
    constructor Create(AItem: TPersistent); override;
  end;

  TDataModuleRootSprig = class(TRootSprig)
  public
    constructor Create(AItem: TPersistent); override;
    function DragOver(AItem: TSprig): Boolean; override;
    function PaletteOver(ASprigClass: TSprigClass; AClass: TClass): Boolean; override;
    function AcceptsClass(AClass: TClass): Boolean; override;
  end;

implementation

{ Sprigs and such }

{ TControlSprig }

constructor TControlSprig.Create(AItem: TPersistent);
begin
  inherited;
  ImageIndex := CControlSprigImage;
end;

function TControlSprig.DragDropTo(AParent: TSprig): Boolean;
begin
  Result := ((AParent is TControlSprig) or (AParent is TWidgetControlRootSprig)) and
            (csAcceptsControls in TControl(AParent.Item).ControlStyle);
end;

function TControlSprig.DragOverTo(AParent: TSprig): Boolean;
begin
  Result := ((AParent is TControlSprig) or (AParent is TWidgetControlRootSprig)) and
            (csAcceptsControls in TControl(AParent.Item).ControlStyle);
end;

class function TControlSprig.PaletteOverTo(AParent: TSprig; AClass: TClass): Boolean;
begin
  Result := ((AParent is TControlSprig) or (AParent is TWidgetControlRootSprig)) and
            (csAcceptsControls in TControl(AParent.Item).ControlStyle);
end;

{ TWidgetControlSprig & TWidgetControlRootSprig supports }

function WidgetControlDragDrop(Sender, AItem: TSprig): Boolean;
var
  LLeft, LTop: Integer;
begin
  Result := TControlSprig(AItem).Parent <> Sender;
  if Result then
    if AItem.DragDropTo(Sender) then
      with TControl(AItem.Item) do
      begin
        Parent := TWidgetControl(Sender.Item);
        LLeft := Left;
        LTop := Top;
        if LLeft + Width > Parent.ClientWidth then
          LLeft := Parent.ClientWidth - Width;
        if LTop + Height > Parent.ClientHeight then
          LTop := Parent.ClientHeight - Height;
        SetBounds(LLeft, LTop, Width, Height);
      end;
end;

function WidgetControlDragOver(Sender, AItem: TSprig): Boolean;
begin
  Result := (AItem is TControlSprig) and
            (csAcceptsControls in TControl(Sender.Item).ControlStyle) and
            AItem.DragOverTo(Sender);
end;

function WidgetControlPaletteOver(Sender: TSprig; ASprigClass: TSprigClass; AClass: TClass): Boolean;
begin
  Result := (ASprigClass.InheritsFrom(TControlSprig) or ASprigClass.InheritsFrom(TWidgetControlRootSprig)) and
            (csAcceptsControls in TControl(Sender.Item).ControlStyle) and
            ASprigClass.PaletteOverTo(Sender, AClass);
end;

{ TWidgetControlSprig }

constructor TWidgetControlSprig.Create(AItem: TPersistent);
begin
  inherited;
  ImageIndex := CUIControlImageIndex[csAcceptsControls in TControl(Item).ControlStyle];
end;

function TWidgetControlSprig.DragDrop(AItem: TSprig): Boolean;
begin
  Result := (AItem.Owner = Owner) and WidgetControlDragDrop(Self, AItem);
end;

function TWidgetControlSprig.DragOver(AItem: TSprig): Boolean;
begin
  Result := (AItem.Owner = Owner) and WidgetControlDragOver(Self, AItem);
end;

function TWidgetControlSprig.PaletteOver(ASprigClass: TSprigClass;
  AClass: TClass): Boolean;
begin
  Result := WidgetControlPaletteOver(Self, ASprigClass, AClass);
end;

{ TWidgetControlRootSprig }

constructor TWidgetControlRootSprig.Create(AItem: TPersistent);
begin
  inherited;
  ImageIndex := CUIControlImageIndex[csAcceptsControls in TControl(Item).ControlStyle];
end;

function TWidgetControlRootSprig.DragDrop(AItem: TSprig): Boolean;
begin
  Result := (AItem.Owner = Self) and
            ((AItem is TControlSprig) and WidgetControlDragDrop(Self, AItem)) or
            ((AItem is TComponentSprig) and inherited DragDrop(AItem));
end;

function TWidgetControlRootSprig.DragOver(AItem: TSprig): Boolean;
begin
  Result := (AItem.Owner = Self) and WidgetControlDragOver(Self, AItem);
end;

function TWidgetControlRootSprig.PaletteOver(ASprigClass: TSprigClass;
  AClass: TClass): Boolean;
begin
  Result := WidgetControlPaletteOver(Self, ASprigClass, AClass) or
            ASprigClass.InheritsFrom(TComponentSprig);
end;

{ TCustomFormRootSprig }

constructor TCustomFormRootSprig.Create(AItem: TPersistent);
begin
  inherited;
  ImageIndex := CFormSprigImage;
end;

{ TDataModuleRootSprig }

function TDataModuleRootSprig.AcceptsClass(AClass: TClass): Boolean;
begin
  Result := not AClass.InheritsFrom(TControl) and
            inherited AcceptsClass(AClass);
end;

constructor TDataModuleRootSprig.Create(AItem: TPersistent);
begin
  inherited;
  ImageIndex := CDataModuleSprigImage;
end;

function TDataModuleRootSprig.DragOver(AItem: TSprig): Boolean;
begin
  Result := (AItem.Owner = Self) and
            not (AItem is TControlSprig) and
            (AItem is TComponentSprig);
end;

function TDataModuleRootSprig.PaletteOver(ASprigClass: TSprigClass;
  AClass: TClass): Boolean;
begin
  Result := not ASprigClass.InheritsFrom(TControlSprig) and
            ASprigClass.InheritsFrom(TComponentSprig);
end;

{ TFrameSprig }

constructor TFrameSprig.Create(AItem: TPersistent);
begin
  inherited;
  ImageIndex := CUIControlImageIndex[True];
end;

procedure TFrameSprig.FigureChildren;
var
  I: Integer;
  LChildItem: TComponent;
  LChild: TSprig;
  LChildClass: TComponentSprigClass;
begin
  // let it go first
  inherited;

  // now lets loop through the component items
  for I := 0 to TFrame(Item).ComponentCount - 1 do
  begin

    // find the best class
    LChildItem := TFrame(Item).Components[I];
    LChild := Root.Find(LChildItem);

    // if not then create it
    if LChild = nil then
    begin
      LChildClass := TComponentSprigClass(FindBestSprigClass(LChildItem.ClassType, TComponentSprig));
      if LChildClass <> nil then
      begin
        LChild := LChildClass.Create(LChildItem, Self);

        Add(LChild);
      end;
    end;
  end;
end;

end.
