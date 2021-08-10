{ ********************************************************************** }
{                                                                        }
{ Delphi and Kylix Cross-Platform Open Tools API                         }
{                                                                        }
{ Copyright (C) 1995, 2001 Borland Software Corporation                  }
{                                                                        }
{ All Rights Reserved.                                                   }
{                                                                        }
{ ********************************************************************** }


unit ClxDesignWindows;

interface

uses SysUtils, Classes, Qt, QControls, QForms, DesignIntf, ComponentDesigner;

type
  TClxDesignWindow = class(TForm, IUnknown, IDesignWindow, IDesignNotification,
    IEditHandler, IActivatable
{$IFDEF LINUX}
    , IDesignerThreadAffinity
{$ENDIF}
    )
  private
    FSelection: IDesignerSelections;
    FOwner: TComponent;
    FDesigner: IDesigner;
    FComponentDesigner: IComponentDesigner;
    FActive: Boolean;
    procedure ComponentRead(Component: TComponent);
    procedure ReaderSetName(Reader: TReader; Component: TComponent;
      var Name: string);
  protected
    procedure Activated; dynamic;
    procedure ActivateInspector(Ch: Char);
    function ClipboardComponents: Boolean;
    procedure CopyComponents(Root: TComponent;
      const Components: IDesignerSelections);
    procedure PasteComponents(AOwner, AParent: TComponent;
      const Components: IDesignerSelections);
    procedure SetSelection(const Components: IDesignerSelections);
    function UniqueName(Component: TComponent): string; virtual; abstract;
  public
    constructor Create(AOwner: TComponent); override;
    destructor Destroy; override;

    // IEditHandler
    function GetEditState: TEditState; virtual;
    function EditAction(Action: TEditAction): Boolean; virtual;

    // IDesignNotification
    procedure ItemDeleted(const ADesigner: IDesigner; Item: TPersistent); virtual;
    procedure ItemInserted(const ADesigner: IDesigner; Item: TPersistent); virtual;
    procedure SelectionChanged(const ADesigner: IDesigner; const ASelection: IDesignerSelections); virtual;
    procedure DesignerOpened(const Designer: IDesigner; AResurrecting: Boolean); virtual;
    procedure DesignerClosed(const Designer: IDesigner; AGoingDormant: Boolean); virtual;
    procedure ItemsModified(const Designer: IDesigner); virtual;

    // IDesignWindowActions
    procedure WindowHide; virtual;
    procedure WindowShow; virtual;

    // IActivatable
    procedure IActivatable.Activate = ForceActive;
    procedure ForceActive;
{$IFDEF LINUX}
    // IDesignerThreadAffinity
    function GetThreadAffinity: TThreadAffinity;
{$ENDIF}
    property Active: Boolean read FActive;
    property Designer: IDesigner read FDesigner write FDesigner;
    property ComponentDesigner: IComponentDesigner read FComponentDesigner;
  end;

implementation

uses
  QClipbrd, DesignEditors, ClxEditors;

constructor TClxDesignWindow.Create(AOwner: TComponent);
begin
  inherited Create(AOwner);
  FComponentDesigner := ActiveDesigner;
  RegisterDesignNotification(Self);
  SetBounds(200, ComponentDesigner.Environment.GetMainWindowSize.Bottom + 2, Width, Height);
end;

destructor TClxDesignWindow.Destroy;
begin
  UnregisterDesignNotification(Self);
  inherited Destroy;
end;

procedure TClxDesignWindow.Activated;
begin
end;

(*procedure TClxDesignWindow.WMActivate(var Msg: TWMActivate);
begin
  inherited;
  FActive := Msg.Active <> 0;
  if FActive then
    Activated;
end;*)

procedure TClxDesignWindow.ActivateInspector(Ch: Char);
begin
  ComponentDesigner.Environment.ModalEdit(Ch, Self);
end;

function TClxDesignWindow.ClipboardComponents: Boolean;
begin
  try
    Result := False;
(*    Result := Clipboard.HasFormat(CF_COMPONENTS) or
      (Clipboard.HasFormat(CF_TEXT) and PossibleStream(Clipboard.AsText)); *)
  except
    Result := False;
  end;
end;

procedure TClxDesignWindow.CopyComponents(Root: TComponent;
  const Components: IDesignerSelections);
var
  S: TMemoryStream;
  W: TWriter;
  I: Integer;
begin
  S := TMemoryStream.Create;
  try
    W := TWriter.Create(S, 1024);
    try
      W.Root := Root;
      for I := 0 to Components.Count - 1 do
      begin
        W.WriteSignature;
        W.WriteComponent(TComponent(Components[I]));
      end;
      W.WriteListEnd;
    finally
      W.Free;
    end;
    CopyStreamToClipboard(S);
  finally
    S.Free;
  end;
end;

function TClxDesignWindow.GetEditState: TEditState;
begin
  Result := [];
end;

function TClxDesignWindow.EditAction(Action: TEditAction): Boolean;
begin
  Result := False;
end;

procedure TClxDesignWindow.ForceActive;
begin
  QWidget_setActiveWindow(Handle);
end;

procedure TClxDesignWindow.WindowHide;
begin
  if Visible then
    QWidget_hide(Handle);
end;

procedure TClxDesignWindow.WindowShow;
begin
  if Visible then
    QWidget_show(Handle);
end;

procedure TClxDesignWindow.ComponentRead(Component: TComponent);
begin
  FSelection.Add(Component);
end;

procedure TClxDesignWindow.ReaderSetName(Reader: TReader; Component: TComponent;
  var Name: string);
begin
  if (Reader.Root = FOwner) and (FOwner.FindComponent(Name) <> nil) then
    Name := UniqueName(Component);
end;

procedure TClxDesignWindow.PasteComponents(AOwner, AParent: TComponent;
  const Components: IDesignerSelections);
var
  S: TStream;
  R: TReader;
begin
  S := GetClipboardStream;
  try
    R := TReader.Create(S, 1024);
    try
      R.OnSetName := ReaderSetName;
      FOwner := AOwner;
      FSelection := Components;
      R.ReadComponents(AOwner, AParent, ComponentRead);
    finally
      R.Free;
    end;
  finally
    S.Free;
  end;
end;

procedure TClxDesignWindow.SelectionChanged(const ADesigner: IDesigner;
  const ASelection: IDesignerSelections);
begin
end;

procedure TClxDesignWindow.SetSelection(const Components: IDesignerSelections);
begin
  ComponentDesigner.SetSelection(Designer, Self, Components);
end;

procedure TClxDesignWindow.ItemDeleted(const ADesigner: IDesigner; Item: TPersistent);
begin

end;

procedure TClxDesignWindow.ItemInserted(const ADesigner: IDesigner; Item: TPersistent);
begin

end;

procedure TClxDesignWindow.DesignerClosed(const Designer: IDesigner; AGoingDormant: Boolean);
begin
  if FDesigner = Designer then
  begin
    FDesigner := nil;
    FComponentDesigner := nil;
  end;
end;

procedure TClxDesignWindow.DesignerOpened(const Designer: IDesigner; AResurrecting: Boolean);
begin
  FDesigner := Designer;
  FComponentDesigner := ActiveDesigner;
end;

procedure TClxDesignWindow.ItemsModified(const Designer: IDesigner);
begin
end;

{$IFDEF LINUX}
function TClxDesignWindow.GetThreadAffinity: TThreadAffinity;
begin
  Result := taQT;
end;
{$ENDIF}

end.
