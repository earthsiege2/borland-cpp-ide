unit Unit2;

interface

uses
  SysUtils, Windows, Messages, Classes, Graphics, Controls,
  StdCtrls, Forms, DBCtrls, DB, DBTables, Mask, ExtCtrls,
  EmbForm, Ole2;

type
  TForm3 = class(TEmbeddableForm)
    Table1SiteID: TFloatField;
    Table1Site: TStringField;
    Table1Location: TStringField;
    Table1When: TStringField;
    Table1Airport: TStringField;
    Table1TourismPeak: TStringField;
    Table1Image: TGraphicField;
    Table1Description: TMemoField;
    Table1Contact: TStringField;
    Table1Phone: TStringField;
    ScrollBox: TScrollBox;
    Label1: TLabel;
    EditSiteID: TDBEdit;
    Label2: TLabel;
    EditSite: TDBEdit;
    Label3: TLabel;
    EditLocation: TDBEdit;
    Label4: TLabel;
    EditWhen: TDBEdit;
    Label5: TLabel;
    EditAirport: TDBEdit;
    Label6: TLabel;
    EditTourismPeak: TDBEdit;
    Label8: TLabel;
    EditDescription: TDBEdit;
    Label9: TLabel;
    EditContact: TDBEdit;
    Label10: TLabel;
    EditPhone: TDBEdit;
    DBNavigator: TDBNavigator;
    Panel1: TPanel;
    DataSource1: TDataSource;
    Panel2: TPanel;
    Table1: TTable;
    Label11: TLabel;
    DBImage1: TDBImage;
    procedure FormCreate(Sender: TObject);
  private
    { private declarations }
  public
    { public declarations }
    function GoNext: Integer; stdcall;
    function GoPrev: Integer; stdcall;
  end;

  // Form interface definition
  IMyObj = class(IUnknown)
  public
    function GoNext:Integer; virtual; stdcall; abstract;
    function GoPrev: Integer; virtual; stdcall; abstract;
  end;

  // Form interface implementation object
  TMyFormInterface = class(IMyObj)
  private
    FCount: Integer;
    FForm: TForm3;
  public
    constructor Create( AForm: TForm3 );
    function QueryInterface(const iid: TIID; var obj): HResult; stdcall;
    function AddRef: Longint; stdcall;
    function Release: Longint; stdcall;
    function GoNext: Integer; stdcall;
    function GoPrev: Integer; stdcall;
  end;


function MakeTestForm( hWndParent: HWND; var obj: IUnknown ): HWND; stdcall;

var
  Form3: TForm3;


implementation

{$R *.DFM}

function MakeTestForm( hWndParent: HWND; var obj: IUnknown ): HWND; stdcall;
var theForm: TForm3;
begin
    Application.CreateForm( TForm3, theForm );
    theForm.ParentHandle := hWndParent;
    Result := theForm.Handle;
    TMyFormInterface.Create( theForm ).QueryInterface(IID_IUnknown, obj);
// optionally, return another interface to the window, too
end;


// -------- Form interface ---------
constructor TMyFormInterface.Create( AForm: TForm3 );
begin
  FForm := AForm;
  FCount := 0;
end;


function TMyFormInterface.QueryInterface(const iid: TIID; var obj): HResult; stdcall;
begin
  AddRef;
  IUnknown(obj) := self as IMyObj;
  Result := S_OK;
end;

function TMyFormInterface.AddRef: Longint; stdcall;
begin
  INC(FCount);
  Result := FCount;
end;

function TMyFormInterface.Release: Longint; stdcall;
begin
  DEC(FCount);
  Result := FCount;
end;

function TMyFormInterface.GoNext: Integer; stdcall;
begin
  Result := FForm.GoNext;
end;

function TMyFormInterface.GoPrev: Integer; stdcall;
begin
  Result := FForm.GoPrev;
end;

// ----------------- Form methods -----------------------
procedure TForm3.FormCreate(Sender: TObject);
begin
  Table1.Open;
end;
// -------- Form methods ---------
function TForm3.GoNext:Integer;
begin
  try
    Table1.Next;
    Result := 1;
  except
    Result := 0;
  end;
end;

function TForm3.GoPrev:Integer;
begin
  try
   Table1.Prior;
    Result := 1;
  except
    Result := 0;
  end;
end;

end.
