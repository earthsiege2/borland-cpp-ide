unit DdeReg;

interface

uses Windows, SysUtils, Classes, Graphics, Forms, Controls, Buttons, TypInfo,
  DesignIntf, DesignEditors, DdeMan, Messages, StdCtrls, ExtCtrls;

{  TComponentEditors }

type
  TSrvrConvEdit = class(TDefaultEditor)
  protected
    procedure EditProperty(const Prop: IProperty; var Continue: Boolean); override;
  end;

  TCliConvEdit = class(TDefaultEditor)
  protected
    procedure EditProperty(const Prop: IProperty; var Continue: Boolean); override;
  end;

  TSrvrItemEdit = class(TDefaultEditor)
  public
    procedure Copy; override;
  end;


{  TForms }
type
  TDdeLinkDlg = class(TForm)
    TopicEdit: TEdit;
    AppEdit: TEdit;
    Label1: TLabel;
    Label2: TLabel;
    OK: TButton;
    CancelBtn: TButton;
    PasteBtn: TButton;
    HelpBtn: TButton;
    procedure doPasteLink(Sender: TObject);
    procedure DoPasteCheck(Sender: TObject);
    procedure FormCreate(Sender: TObject);
    procedure HelpBtnClick(Sender: TObject);
  private
    procedure WMActivate(var Message: TWMActivate); message WM_ACTIVATE;
  end;


  TDdeLinkInfoProperty = class(TPropertyEditor)
  public
    function GetAttributes: TPropertyAttributes; override;
    procedure Edit; override;
    function  GetValue: string; override;
  end;

  TDdeClientItemProperty = class(TStringProperty)
  public
    function GetAttributes: TPropertyAttributes; override;
    procedure GetValues(Proc: TGetStrProc); override;
  end;

procedure Register;

implementation

uses Dialogs, LibHelp, ExptIntf, ToolIntf, EditIntf, DsnConst;

{$R *.dfm}
{---------------------------------------}

procedure TSrvrConvEdit.EditProperty(const Prop: IProperty; var Continue: Boolean);
var
  PropName: string;
begin
  PropName := Prop.GetName;
  if (CompareText(PropName, 'ONEXECUTEMACRO') = 0) then
  begin
    Prop.Edit;
    Continue := False;
  end
  else
    inherited EditProperty(Prop, Continue);
end;


procedure TCliConvEdit.EditProperty(const Prop: IProperty; var Continue: Boolean);
var
  PropName: string;
begin
  PropName := Prop.GetName;
  if (CompareText(PropName, 'ONOPEN') = 0) then
  begin
    Prop.Edit;
    Continue := False;
  end
  else
    inherited EditProperty(Prop, Continue);
end;

procedure TSrvrItemEdit.Copy;
begin
  TDdeServerItem(Component).CopyToClipboard;
end;


{---------------------------------------}
{ TDdeLinkInfoProperty }

function TDdeLinkInfoProperty.GetAttributes: TPropertyAttributes;
begin
  Result := inherited GetAttributes + [paDialog, paReadOnly]
                      - [paMultiSelect, paSubProperties];
end;

function TDdeLinkInfoProperty.GetValue: string;
begin
  if GetStrValue = '' then Result := SDdeEmptyConnection
  else Result := Format ('(%s)', [GetStrValue]);
end;

procedure TDdeLinkInfoProperty.Edit;
var
  DdeCli      : TDdeClientConv;
  LinkDlg     : TDdeLinkDlg;
begin
  DdeCli := TDdeClientConv (GetComponent(0));
  LinkDlg := TDdeLinkDlg.Create(Application);
  try
    LinkDlg.AppEdit.Text    :=   DdeCli.DdeService;
    LinkDlg.TopicEdit.Text  :=   DdeCli.DdeTopic;

    if LinkDlg.ShowModal = idOk then
    begin
      if Not DdeCli.SetLink(LinkDlg.AppEdit.Text,
                            LinkDlg.TopicEdit.Text) then
        MessageDlg(SDdeNoConnect, mtError, [mbOK], 0);
      Modified;
    end;
  finally
    LinkDlg.Free;
  end;
end;

{---------------------------------------}

procedure TDdeLinkDlg.doPasteLink(Sender: TObject);
var
  Service, Topic, Item : String;
begin
  if  GetPasteLinkInfo (Service, Topic, Item) = True  then
  begin
    AppEdit.Text   := Service;
    TopicEdit.Text := Topic;
  end
  else
  begin
    AppEdit.Text   := EmptyStr;
    TopicEdit.Text := EmptyStr;
  end;
end;

procedure TDdeLinkDlg.DoPasteCheck(Sender: TObject);
var
  enable : Boolean;
  Service, Topic, Item : String;
begin
  enable := False;
  if  GetPasteLinkInfo (Service, Topic, Item) = True  then
    enable := True;
  if enable <> PasteBtn.Enabled then
    PasteBtn.Enabled := enable;
end;

procedure TDdeLinkDlg.WMActivate(var Message: TWMActivate);
begin
  inherited;
  if Message.Active <> WA_INACTIVE then DoPasteCheck(Self);
end;

procedure TDdeLinkDlg.FormCreate(Sender: TObject);
begin
  HelpContext := hcDDDEInfo;
end;

procedure TDdeLinkDlg.HelpBtnClick(Sender: TObject);
begin
  Application.HelpContext(HelpContext);
end;

{-------}
{ TDdeClientItemProperty }

function TDdeClientItemProperty.GetAttributes: TPropertyAttributes;
begin
  Result := inherited GetAttributes + [paValueList] - [paMultiSelect,
    paSubProperties];
end;

procedure TDdeClientItemProperty.GetValues(Proc: TGetStrProc);
var
  Cli  : TDdeClientConv;
  Service, Topic, Item : String;
begin
  Cli := TDdeClientConv(TDdeClientItem (GetComponent(0)).DdeConv);
  if Cli <> Nil then
  begin
    if  GetPasteLinkInfo (Service, Topic, Item) = True  then
    begin
      if (Service = Cli.DdeService) and
         (Topic = Cli.DdeTopic) then
        Proc (Item);
    end;
  end;
end;

type
  TDDEProjectNotifier = class(TIAddInNotifier)
    procedure FileNotification(NotifyCode: TFileNotification;
      const FileName: string; var Cancel: Boolean); override;
    procedure EventNotification(NotifyCode: TEventNotification;
      var Cancel: Boolean); override;
  end;

  TDDEModuleNotifier = class(TIModuleNotifier)
  private
    ModuleInterface: TIModuleInterface;
  public
    constructor Create(AModuleInterface: TIModuleInterface);
    destructor Destroy; override;
    procedure Notify(NotifyCode: TNotifyCode); override;
    procedure ComponentRenamed(const AComponent: TComponent;
      const OldName, NewName: string); override;
  end;

var
  ProjHooks: TList;
  ProjHook: TDDEProjectNotifier;

procedure TDDEProjectNotifier.FileNotification;
var
  MI: TIModuleInterface;
  Hook: TDDEModuleNotifier;
begin
// Per Chuck Allen
{
  case NotifyCode of
    fnProjectOpened:
      begin
        DDEMgr.AppName := ChangeFileExt(ExtractFileName(FileName),'');
        MI := ToolServices.GetModuleInterface(FileName);
        if MI <> nil then
        begin
          Hook := TDDEModuleNotifier.Create(MI);
          ProjHooks.Add(Hook);
          MI.AddNotifier(Hook);
          MI.Release;
        end;
      end;
    fnProjectClosing: DDEMgr.AppName := '';
  end;
}  
end;

procedure TDDEProjectNotifier.EventNotification;
begin
end;

constructor TDDEModuleNotifier.Create(AModuleInterface: TIModuleInterface);
begin
  inherited Create;
  ModuleInterface := AModuleInterface;
  ModuleInterface.AddRef;
end;

destructor TDDEModuleNotifier.Destroy;
begin
  ProjHooks.Remove(Self);
  ModuleInterface.Release;
  inherited Destroy;
end;

procedure TDDEModuleNotifier.Notify(NotifyCode: TNotifyCode);
var
  EditInterface: TIEditorInterface;
begin
  case NotifyCode of
    ncModuleDeleted:
      begin
        ModuleInterface.RemoveNotifier(Self);
        Release;
      end;
    ncModuleRenamed:
      begin
        EditInterface := ModuleInterface.GetEditorInterface;
        if EditInterface <> nil then
        try
          DDEMgr.AppName := ChangeFileExt(ExtractFileName(EditInterface.FileName),'');
        finally
          EditInterface.Free;
        end;
      end;
  end;
end;

procedure TDDEModuleNotifier.ComponentRenamed(const AComponent: TComponent;
  const OldName, NewName: string);
begin
end;

procedure Register;
begin
  RegisterComponents(srSystem, [TDdeClientConv, TDdeClientItem, TDdeServerConv,
    TDdeServerItem]);
  RegisterPropertyEditor(TypeInfo(string), TDdeClientConv, 'DdeService', TDdeLinkInfoProperty);
  RegisterPropertyEditor(TypeInfo(string), TDdeClientConv, 'DdeTopic', TDdeLinkInfoProperty);
  RegisterPropertyEditor(TypeInfo(string), TDdeClientItem, 'DdeItem', TDdeClientItemProperty);
  RegisterComponentEditor(TDdeServerItem, TSrvrItemEdit);
  RegisterComponentEditor(TDdeServerConv, TSrvrConvEdit);
  RegisterComponentEditor(TDdeClientConv, TCliConvEdit);
  RegisterPropertiesInCategory(sLocalizableCategoryName, TDdeServerItem, ['Lines']); { Text property displays Lines[0] }
  RegisterPropertiesInCategory(sLocalizableCategoryName, TDdeClientItem, ['Lines']); { Text property displays Lines[0] }
  ProjHook := TDDEProjectNotifier.Create;
  ToolServices.AddNotifier(ProjHook);
end;

procedure FreeProjFileHooks;
var
  I: Integer;
begin
  if (ToolServices = nil) or (ProjHooks = nil) then Exit;
  I := ProjHooks.Count - 1;
  while I > -1 do
  begin
    TDDEModuleNotifier(ProjHooks[I]).Notify(ncModuleDeleted);
    Dec(I);
  end;
  ToolServices.RemoveNotifier(ProjHook);
  ProjHook.Release;
  ProjHook := nil;
end;

initialization
  ProjHooks := TList.Create;
finalization
  FreeProjFileHooks;
  ProjHooks.Free;
  ProjHooks := nil;
end.
