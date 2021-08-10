unit EmbForm;

interface
uses
  Windows, Messages, SysUtils, Classes, Graphics, Controls, Forms, Dialogs,
  StdCtrls, ComCtrls;
  
type                           
  TEmbeddableForm = class(TForm)
  private
    { Private declarations }
    FParentHandle: HWND;
    DestroyingForRecreate: Boolean;
    FNeedsToShow: Boolean;
    procedure CreateParams(var Params: TCreateParams); override;
    procedure DestroyWnd; override;
    procedure WMNCDestroy(var Message: TWMNCDestroy); message WM_NCDESTROY;
    procedure SetParentHandle( hWndParent: HWND );
    procedure SetVisible(Value: Boolean);
  public
    { Public declarations }
    constructor Create(AOwner: TComponent); override;
    property ParentHandle: HWND read FParentHandle write SetParentHandle;
  published
    property Visible write SetVisible default False;
  end;

implementation

constructor TEmbeddableForm.Create(AOwner: TComponent);
begin                     
    DestroyingForRecreate := False;
    FNeedsToShow := False;
    FParentHandle := 0;
    inherited Create(AOwner);
end;
    
procedure TEmbeddableForm.CreateParams(var Params: TCreateParams);
begin
    inherited CreateParams(Params);
    with Params do
    begin
        WndParent := FParentHandle;
        // if there is a parent, then set the style, too
        if FParentHandle <> 0 then
            Style := (Style or WS_CHILD) and (not WS_POPUP);
    end;
end;

procedure TEmbeddableForm.DestroyWnd; 
begin
    DestroyingForRecreate := True;
    inherited;
    DestroyingForRecreate := False;
end;   

procedure TEmbeddableForm.WMNCDestroy(var Message: TWMNCDestroy);
begin
    inherited;
    if not DestroyingForRecreate then
        Free;
end;

procedure TEmbeddableForm.SetVisible( Value: Boolean); 
begin
    if FParentHandle = 0 then
        FNeedsToShow := Value
    else
        inherited Visible := Value;
end;

procedure TEmbeddableForm.SetParentHandle( hWndParent: HWND );
var needShow: Boolean;
begin
    // If it was hidden because there was no parent,
    // we will need to show it after we set its parent.
    needShow := (FParentHandle = 0) and FNeedsToShow;
    FParentHandle := hWndParent;
    RecreateWnd;
    if needShow then
      Visible := True;
end;

end.
 