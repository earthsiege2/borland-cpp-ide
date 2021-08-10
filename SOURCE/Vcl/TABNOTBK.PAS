
{*******************************************************}
{                                                       }
{       Borland Delphi Visual Component Library         }
{                                                       }
{       Copyright (c) 1995,99 Inprise Corporation       }
{                                                       }
{*******************************************************}

{ This unit defines the TTabbedNotebook Component. }

unit Tabnotbk;

{$H+,X+}

interface

uses Windows, Classes,  Stdctrls, Forms, Messages, Graphics, Controls,
  ComCtrls;

const
  CM_TABFONTCHANGED = CM_BASE + 100;

type

  TPageChangeEvent = procedure(Sender: TObject; NewTab: Integer;
    var AllowChange: Boolean) of object;

  { Class       : TTabPage
    Description : This class implements the individual tab page behavior.
                  Each instance of this class will hold controls to be
                  displayed when it is the active page of a TTabbedNotebook
                  component. }
  TTabPage = class(TWinControl)
  protected
    procedure ReadState(Reader: TReader); override;
  public
    constructor Create(AOwner: TComponent); override;
  published
    property Caption;
    property Height stored False;
    property TabOrder stored False;
    property Visible stored False;
    property Width stored False;
    property Enabled stored False;
  end;

  { Class       : TTabbedNotebook
    Description : This class implements Tabbed notebook component.
                  It holds a collection of TTabPages onto which
                  users can drop controls.  It uses MS-Word style
                  tab buttons to allow the user to control which
                  page is currently active. }
  TTabbedNotebook = class(TCustomTabControl)
  private
    FPageList: TList;
    FAccess: TStrings;
    FPageIndex: Integer;
    FTabFont: TFont;
    FTabsPerRow: Integer;
    FOnClick: TNotifyEvent;
    FOnChange: TPageChangeEvent;
    function GetActivePage: string;
    procedure SetPages(Value: TStrings);
    procedure SetActivePage(const Value: string);
    procedure SetTabFont(Value: TFont);
    procedure SetTabsPerRow(NewTabCount: Integer);
    procedure WMGetDlgCode(var Message: TWMGetDlgCode); message WM_GETDLGCODE;
    procedure CMDialogChar(var Message: TCMDialogChar); message CM_DIALOGCHAR;
    procedure WMPaint(var Message: TWMPaint); message wm_Paint;
  protected
    procedure AlignControls(AControl: TControl; var Rect: TRect); override;
    procedure Change; override;
    procedure Click; override;
    procedure CreateHandle; override;
    procedure CreateParams(var Params: TCreateParams); override;
    function GetChildOwner: TComponent; override;
    procedure GetChildren(Proc: TGetChildProc; Root: TComponent); override;
    procedure Loaded; override;
    procedure KeyDown(var Key: Word; Shift: TShiftState); override;
    procedure ReadState(Reader: TReader); override;
    procedure SetPageIndex(Value: Integer);
    procedure ShowControl(AControl: TControl); override;
    procedure CMTabFontChanged(var Message: TMessage); message CM_TABFONTCHANGED;
  public
    constructor Create(AOwner: TComponent); override;
    destructor  Destroy; override;
    function GetIndexForPage(const PageName: string): Integer;
    property TopFont: TFont read FTabFont;
    procedure TabFontChanged(Sender: TObject);
  published
    property ActivePage: string read GetActivePage write SetActivePage
      stored False;
    property Align;
    property Anchors;
    property Constraints;
    property Enabled;
    property PageIndex: Integer read FPageIndex write SetPageIndex default 0;
    property Pages: TStrings read FAccess write SetPages stored False;
    property Font;
    property TabsPerRow: Integer read FTabsPerRow write SetTabsPerRow default 3;
    property TabFont: TFont read FTabFont write SetTabFont;
    property ParentShowHint;
    property PopupMenu;
    property ShowHint;
    property TabOrder;
    property TabStop default True;
    property Visible;
    property OnClick: TNotifyEvent read FOnClick write FOnClick;
    property OnChange: TPageChangeEvent read FOnChange write FOnChange;
    property OnContextPopup;
    property OnEnter;
    property OnExit;
  end;

implementation

uses SysUtils, Consts;

const
  TabTopBorder = 4;
  PageLeftBorder = 2;
  PageBevelWidth = 3;
  BorderWidth  = 8;

type
  { Class       : TTabPageAccess
    Description : Maintains the list of TTabPages for a
                  TTabbedNotebook component. }
  TTabPageAccess = class(TStrings)
  private
    PageList: TList;
    Notebook: TTabbedNotebook;
  protected
    function GetCount: Integer; override;
    function Get(Index: Integer): string; override;
    procedure Put(Index: Integer; const S: string); override;
    function GetObject(Index: Integer): TObject; override;
    procedure SetUpdateState(Updating: Boolean); override;
  public
    constructor Create(APageList: TList; ANotebook: TTabbedNotebook);
    procedure Clear; override;
    procedure Delete(Index: Integer); override;
    procedure Insert(Index: Integer; const S: string); override;
    procedure Move(CurIndex, NewIndex: Integer); override;
  end;

{ TTabPageAccess }

{ Method      : Create
  Description : Keeps track of the pages for the notebook. }
constructor TTabPageAccess.Create(APageList: TList; ANotebook: TTabbedNotebook);
begin
  inherited Create;
  PageList := APageList;
  Notebook := ANotebook;
end;

{ Method      : GetCount
  Description : Return the number of pages in the notebook. }
function TTabPageAccess.GetCount: Integer;
begin
  Result := PageList.Count;
end;

{ Method      : Get
  Description : Return the name of the indexed page, which should match
                the name of the corresponding button. }
function TTabPageAccess.Get(Index: Integer): string;
begin
  Result := TTabPage(PageList[Index]).Caption;
end;

{ Method      : Put
  Description : Put a name into a page.  The button for the page must have
                the same name. }
procedure TTabPageAccess.Put(Index: Integer; const S: string);
begin
  TTabPage(PageList[Index]).Caption := S;
  if Notebook.HandleAllocated then
    Notebook.Tabs[Index] := S;
end;

{ Method      : GetObject
  Description : Return the page indexed. }
function TTabPageAccess.GetObject(Index: Integer): TObject;
begin
  Result := PageList[Index];
end;

{ Method      : SetUpdateState
  Description : We don't want to do this. }
procedure TTabPageAccess.SetUpdateState(Updating: Boolean);
begin
  { do nothing }
end;

{ Method      : Clear
  Description : Remove the pages and buttons from the list. }
procedure TTabPageAccess.Clear;
var
  Index: Integer;
begin
  for Index := 0 to PageList.Count - 1 do
    (TObject(PageList[Index]) as TTabPage).Free;
  PageList.Clear;

  if Notebook.HandleAllocated then
    Notebook.Tabs.Clear;

  Notebook.Realign;
end;

{ Method      : Delete
  Description : Delete a page from the pagelist.  Take its button away too. }
procedure TTabPageAccess.Delete(Index: Integer);
begin
  (TObject(PageList[Index]) as TTabPage).Free;
  PageList.Delete(Index);

  if Notebook.HandleAllocated then
    Notebook.Tabs.Delete(Index);

  { We need to make sure the active page index moves along with the pages. }
  if index = Notebook.FPageIndex then
    begin
      Notebook.FpageIndex := -1;
      Notebook.SetPageIndex(0);
    end
  else if index < Notebook.FPageIndex then
    Dec(Notebook.FPageIndex);

  { Clean up the apperance. }
  Notebook.Realign;
  Notebook.Invalidate;
end;

{ Method      : Insert
  Description : Add a page, along with its button, to the list. }
procedure TTabPageAccess.Insert(Index: Integer; const S: string);
var
  Page: TTabPage;
begin
  Page := TTabPage.Create(Notebook);
  with Page do
  begin
    Parent := Notebook;
    Caption := S;
  end;
  PageList.Insert(Index, Page);
  if Notebook.HandleAllocated then
    Notebook.Tabs.Insert(Index, S);

  Notebook.SetPageIndex(Index);

  { Clean up the apperance. }
  Notebook.Realign;
  Notebook.Invalidate;
end;

{ Method      : Move
  Description : Move a page, and its button, to a new index.  the object
                currently at the new location gets swapped to the old
                position. }
procedure TTabPageAccess.Move(CurIndex, NewIndex: Integer);
begin
  if CurIndex <> NewIndex then
  begin
    PageList.Exchange(CurIndex, NewIndex);
    with Notebook do
    begin
      if HandleAllocated then
        Tabs.Exchange(CurIndex, NewIndex);
      if PageIndex = CurIndex then
        PageIndex := NewIndex
      else if PageIndex = NewIndex then
        PageIndex := CurIndex;
      Realign;
    end;
  end;
end;

{ TTabPage }

{ Method      : Create
  Description : Since the border is drawn by the notebook, this should be
                invisible.  Don't waste time drawing pages you can't see. }
constructor TTabPage.Create(AOwner: TComponent);
begin
  inherited Create(AOwner);
  ControlStyle := ControlStyle + [csAcceptsControls];
  Align := alClient;
  TabStop := False;
  Enabled := False;
  Visible := False;
end;

{ Method      : ReadState
  Description : Another procedure that shouldn't be messed with. }
procedure TTabPage.ReadState(Reader: TReader);
begin
  if Reader.Parent is TTabbedNotebook then
    TTabbedNotebook(Reader.Parent).FPageList.Add(Self);
  inherited ReadState(Reader);
  TabStop := False;
end;

{ TTabbedNotebook }

{ Method      : Create
  Description : Set all the notebook defaults and create the mandatory
                one page. }
var
  Registered: Boolean = False;  { static class data }

constructor TTabbedNotebook.Create(AOwner: TComponent);
begin
  inherited Create(AOwner);
  Exclude(FComponentStyle, csInheritable);
  ControlStyle := ControlStyle + [csClickEvents] - [csAcceptsControls];
  Width := 300;
  Height := 250;
  TabStop := True;
  FPageList := TList.Create;

  FTabFont := TFont.Create;
  FTabFont.Color := clBtnText;
  FTabFont.OnChange := TabFontChanged;

  FTabsPerRow := 3;
  FAccess := TTabPageAccess.Create(FPageList, Self);
  FPageIndex := -1;
  FAccess.Add(SDefault);
  PageIndex := 0;

  if not Registered then
  begin
    RegisterClasses([TTabPage]);
    Registered := True;
  end;
end;

{ Method      : Destroy
  Description : Remove all the lists before removing self. }
destructor  TTabbedNotebook.Destroy;
begin
  FAccess.Free;
  FPageList.Free;
  FTabFont.Free;
  inherited  Destroy;
end;

procedure TTabbedNotebook.CreateHandle;
var
  X: Integer;
begin
  inherited CreateHandle;
  if not (csReading in ComponentState) and (Tabs.Count = 0) then
  begin
    { don't copy the objects into the Tabs list }
    for X := 0 to FAccess.Count-1 do
      Tabs.Add(FAccess[X]);
    TabIndex := FPageIndex;
  end;
end;

{ Method      : CreateParams
  Description : Make sure ClipChildren is set. }
procedure TTabbedNotebook.CreateParams(var Params: TCreateParams);
begin
  inherited CreateParams(Params);
  Params.Style := Params.Style or WS_CLIPCHILDREN;
end;

function TTabbedNotebook.GetChildOwner: TComponent;
begin
  Result := Self;
end;

procedure TTabbedNotebook.GetChildren(Proc: TGetChildProc; Root: TComponent);
var
  I: Integer;
begin
  for I := 0 to FPageList.Count - 1 do Proc(TControl(FPageList[I]));
end;

{ Method      : Loaded
  Description : Make sure only one page is visible, the one set as the
                default page. }
procedure TTabbedNotebook.Loaded;
var
  Index: Integer;
begin
  inherited Loaded;
  for Index := 0 to FPageList.Count - 1 do
    if Index <> FPageIndex then
    begin
      (TObject(FPageList[Index]) as TTabPage).Enabled := False;
      (TObject(FPageList[Index]) as TTabPage).Visible := False;
    end
    else
    begin
      (TObject(FPageList[Index]) as TTabPage).Enabled := True;
      (TObject(FPageList[Index]) as TTabPage).Visible := True;
    end;
  if HandleAllocated then
  begin
    Tabs.Clear;
    for Index := 0 to FAccess.Count-1 do
      Tabs.Add(FAccess[Index]);
    TabIndex := FPageIndex;
  end;
  Realign;
end;

{ Method      : ReadState
  Description : Don't send the button information out since it is all the
                same anyway.}
procedure TTabbedNotebook.ReadState(Reader: TReader);
begin
  FAccess.Clear;
  inherited ReadState(Reader);
  if (FPageIndex >= 0) and (FPageIndex < FPageList.Count) then
  begin
    with (TObject(FPageList[FPageIndex]) as TTabPage) do
    begin
      Enabled := True;
      BringToFront;
      Align := alClient;
    end;
  end
  else
    FPageIndex := -1;
end;

{ Method      : SetPages
  Description : }
procedure TTabbedNotebook.SetPages(Value: TStrings);
begin
  FAccess.Assign(Value);
  if FAccess.Count > 0 then
    FPageIndex := 0
  else
    FPageIndex := -1;
end;

procedure TTabbedNotebook.ShowControl(AControl: TControl);
var
  I: Integer;
begin
  for I := 0 to FPageList.Count - 1 do
    if FPageList[I] = AControl then
    begin
      SetPageIndex(I);
      Exit;
    end;
  inherited ShowControl(AControl);
end;

{ Method      : SetPageIndex
  Description : Set the active page to the one specified in Value. }
procedure TTabbedNotebook.SetPageIndex(Value: Integer);
var
  AllowChange: Boolean;
  ParentForm: TCustomForm;
begin
  if csLoading in ComponentState then
  begin
    FPageIndex := Value;
    Exit;
  end;

  if (Value <> FPageIndex) and (Value >= 0) and (Value < FPageList.Count) then
  begin
    if Assigned(FOnChange) then
    begin
      AllowChange := True;
      FOnChange(Self, Value, AllowChange);
      if not AllowChange then Exit;
    end;

    ParentForm := GetParentForm(Self);
    if ParentForm <> nil then
      if ContainsControl(ParentForm.ActiveControl) then
        ParentForm.ActiveControl := Self;

    if HandleAllocated then
      TabIndex := Value;

    with TTabPage(FPageList[Value]) do
    begin
      BringToFront;
      Visible := True;
      Enabled := True;
    end;

    if (FPageIndex >= 0) and (FPageIndex < FPageList.Count) then
      with TTabPage(FPageList[FPageIndex]) do
      begin
        Visible := False;
        Enabled := False;
      end;

    if (FPageIndex div FTabsPerRow) <> (Value div FTabsPerRow) then
    begin
      FPageIndex := Value;
      Realign;
    end
    else
      FPageIndex := Value;
  end;
end;


{ Method      : SetActivePage
  Description : Set the active page to the named page. }
procedure TTabbedNotebook.SetActivePage(const Value: string);
begin
  SetPageIndex(FAccess.IndexOf(Value));
end;

{ Method      : GetActivePage
  Description : Return the name of the currently active page. }
function TTabbedNotebook.GetActivePage: string;
begin
  if (FAccess.Count > 0) and (FPageIndex >= 0) then
    Result := FAccess[FPageIndex]
  else
    Result := '';
end;

{ Method      : WMGetDlgCode
  Description : Get arrow keys to manage the tab focus rect }
procedure TTabbedNotebook.WMGetDlgCode(var Message: TWMGetDlgCode);
begin
  Message.Result := DLGC_WANTARROWS;
end;

{ Method      : CMDialogChar
  Description : Check for dialog keys in the tabs }
procedure TTabbedNotebook.CMDialogChar(var Message: TCMDialogChar);
var
  Index: Integer;
begin
  with Message do
    if FPageList <> nil then
    begin
      for Index := 0 to FPageList.Count - 1 do
      begin
        if IsAccel(CharCode, TTabPage(FPageList[Index]).Caption) then
        begin
          SetFocus;
          if Focused then
          begin
            SetPageIndex(Index);
            Click;
          end;
          Result := 1;
          Exit;
        end;
      end;
    end;
    inherited;
end;

{ Method      : KeyDown
  Description : Grab arrow keys to manage the active page. }
procedure TTabbedNotebook.KeyDown(var Key: Word; Shift: TShiftState);
begin
  case Key of
    VK_RIGHT, VK_DOWN:
      begin
        if FPageIndex >= (FPageList.Count-1) then SetPageIndex(0)
        else SetPageIndex(FPageIndex + 1);
        Click;
      end;
    VK_LEFT, VK_UP:
      begin
        if FPageIndex > 0 then SetPageIndex(FPageIndex - 1)
        else SetPageIndex(FPageList.Count - 1);
        Click;
      end;
  end;
end;

{ Method      : SetTabsPerRow
  Description : Set the number of tabs in each row.  Don't allow less than
                three. }
procedure TTabbedNotebook.SetTabsPerRow(NewTabCount: Integer);
begin
  if (NewTabCount >= 3) then
  begin
    FTabsPerRow := NewTabCount;
    Realign;
    Invalidate;
  end;
end;

{ Mathod: GetIndexForPage
  Description : Given a page name, return its index number. }
function TTabbedNotebook.GetIndexForPage(const PageName: String): Integer;
var
  Index: Integer;
begin
  Result := -1;

  if FPageList <> nil then
  begin
    For Index := 0 to FPageList.Count-1 do
    begin
      if ((TObject(FPageList[Index]) as TTabPage).Caption = PageName) then
      begin
        Result := Index;
        Exit;
      end;
    end;
  end;
end;

{ Method      : SetTabFont
  Description : Set the font for the tabs. }
procedure TTabbedNotebook.SetTabFont(Value: TFont);
begin
  FTabFont.Assign(Value);
end;

{ Method      : CMTabFontChanged
  Description : Fix the TopFont and redraw the buttons with the new font. }
procedure TTabbedNotebook.CMTabFontChanged(var Message: TMessage);
begin
  Invalidate;
end;

procedure TTabbedNotebook.AlignControls(AControl: TControl; var Rect: TRect);
begin
  If (FPageIndex >= 0) and (FPageIndex < FPageList.Count) then
    inherited AlignControls(FPageList[FPageIndex], Rect);
end;

{ Method      : TabFontChanged
  Description : Send out the proper message. }
procedure TTabbedNotebook.TabFontChanged(Sender: TObject);
begin
  Perform(CM_TABFONTCHANGED, 0, 0);
end;

{ Method      : Click
  Description : Call event procedure. }
procedure TTabbedNotebook.Click;
begin
  if Assigned(FOnClick) then FOnClick(Self);
end;

procedure TTabbedNotebook.Change;
begin
  if TabIndex >= 0 then
    SetPageIndex(TabIndex);
  if FPageIndex = TabIndex then
    inherited Change
  else
    TabIndex := FPageIndex;
end;

procedure TTabbedNotebook.WMPaint(var Message: TWMPaint);
begin
  SendMessage(Handle, wm_SetFont, TabFont.Handle, 0);
  inherited;
end;


end.

