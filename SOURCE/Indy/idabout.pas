unit IdAbout;

interface

uses
{$IFDEF LINUX}
  QStdCtrls, QForms, QExtCtrls, QControls, QGraphics,
{$ELSE}
  Windows, Messages, StdCtrls, Buttons, ExtCtrls, Graphics, Controls, Forms,
{$ENDIF}
  Classes, SysUtils;

type
{$IFNDEF Linux}
  TScrollCredits = class;
{$ENDIF}

  TformAbout = class(TForm)
{$IFDEF Linux}
    scbxCredits: TScrollBox;
    imgLogo: TImage;
    lblName: TLabel;
    lblCopyright: TLabel;
    lblVersion: TLabel;
    lbCoordinator: TLabel;
    lblKudzu: TLabel;
    lblNevronaOne: TLabel;
    lbCoCordinator: TLabel;
    lblHadi: TLabel;
    lblNevronaTwo: TLabel;
    lblIndyPitCrew: TLabel;
    lblAndrewPeeMee: TLabel;
    lblCharlesStack: TLabel;
    lblGregorIbic: TLabel;
    lblIntelicomdoo: TLabel;
    lblJPeterMugaas: TLabel;
    lblNevronaThree: TLabel;
    lblJimGunkel: TLabel;
    lblNevronaDesignsFour: TLabel;
    lblMarkHolmes: TLabel;
    lblRuneMoberg: TLabel;
    lblStephaneGrobety: TLabel;
    lblDocumentCoordinator: TLabel;
    lblDonSIders: TLabel;
    lblProgramsCoordinator: TLabel;
    lblAllenOneil: TLabel;
    bvlBorder: TBevel;
    lblPleaseVisitUs: TLabel;
    lblURL: TLabel;
    btnOk: TButton;
    pbxDividerButtons: TPaintBox;
    PaintBox1: TPaintBox;
    panlScroll: TPanel;
    procedure FormCreate(Sender: TObject);
    procedure pbxDividerButtonsPaint(Sender: TObject);
{$ELSE}
    Panel1: TPanel;
    Panel2: TPanel;
    bvlDialogBorder: TBevel;
    lblCopyright: TLabel;
    lblVersion: TLabel;
    lblName: TLabel;
    lblPleaseVisitUs: TLabel;
    lblURL: TLabel;
    btnOk: TButton;
    tmrScroll: TTimer;
    procedure FormCreate(Sender: TObject);
    procedure lblURLClick(Sender: TObject);
    procedure tmrScrollTimer(Sender: TObject);
    procedure FormShow(Sender: TObject);
{$ENDIF}
  private
  protected
{$IFNDEF Linux}
    scrCredits: TScrollCredits;
    procedure ScrollClick(Sender: TObject);
    procedure WMEraseBkgnd(var Message: TWMEraseBkgnd); message WM_ERASEBKGND;
{$ENDIF}
  public
  end;

{$IFNDEF Linux}
  TCreditString = class(TCollectionItem)
  private
    FHeader: string;
    FBody: TStrings;
    FColCount: Integer;
    FTextExtent: TSize;
    procedure SetBody(const Value: TStrings);
    procedure SetHeader(const Value: string);
    procedure BodyChanged(sender: TObject);
    procedure SetColCount(const Value: Integer);
    function GetBodyItems(Index: Integer): string;
    procedure SetBodyItems(Index: Integer; const Value: string);
{$HINTS OFF}
    property BodyItems[Index: Integer]: string read GetBodyItems write
      SetBodyItems; default;
{$HINTS ON}
  protected
    function TextExtent(Canvas: TCanvas): TSize;
    procedure RenderText(const ATop, AWidth: Integer; Canvas: TCanvas);
  public
    constructor Create(Collection: TCollection); override;
    destructor Destroy; override;
    procedure Assign(Source: TPersistent); override;
  published
    property Header: string read FHeader write SetHeader;
    property Body: TStrings read FBody write SetBody;
    property ColCount: Integer read FColCount write SetColCount default 1;
  end;

  TCreditStrings = class(TOwnedCollection)
  private
    FOwner: TScrollCredits;
    FHeaderFont: TFont;
    FBodyFont: TFont;
    FColSpace: Integer;
    function GetItems(Index: Integer): TCreditString;
    procedure SetItems(Index: Integer; const Value: TCreditString);
    procedure SetBodyFont(const Value: TFont);
    procedure SetHeaderFont(const Value: TFont);
    procedure FontChange(Sender: TObject);
    procedure SetColSpace(const Value: Integer);
  protected
    procedure Update(Item: TCollectionItem); override;
  public
    function Add: TCreditString;
    constructor Create(AnOwner: TScrollCredits);
    destructor Destroy; override;
    procedure Assign(Source: TPersistent); override;
    function TextExtent(Canvas: TCanvas): TSize;
    procedure RenderText(const ATop, AWidth: Integer; Canvas: TCanvas);
  public
    property ColSpace: Integer read FColSpace write SetColSpace;
    property Items[Index: Integer]: TCreditString read GetItems write SetItems;
      default;
    property HeaderFont: TFont read FHeaderFont write SetHeaderFont;
    property BodyFont: TFont read FBodyFont write SetBodyFont;
  end;

  TScrollCredits = class(TGraphicControl)
  private
    bmpCredits,
      bmpBack,
      bmpBuffer: TBitmap;
    FCredits: TCreditStrings;
    FCurrentLine: Integer;
    FBackground: TPicture;
    procedure SetCredits(const Value: TCreditStrings);
    procedure BackgroundChange(Sender: TObject);
    procedure CreditsChange;
    procedure SetCurrentLine(const Value: Integer);
    procedure SetBackground(const Value: TPicture);
    procedure TransposeCredits;
  protected
    procedure Paint; override;
    procedure CMFontchanged(var Message: TMessage); message CM_FONTCHANGED;
    procedure InvalidateBitmap;
  public
    constructor Create(AOwner: TComponent); override;
    destructor Destroy; override;
  published
    property Background: TPicture read FBackground write SetBackground;
    property Credits: TCreditStrings read FCredits write SetCredits;
    property CurrentLine: Integer read FCurrentLine write SetCurrentLine;
    property OnClick;
  end;
{$ENDIF}

procedure ShowAboutBox(const AProductName, AProductVersion: string);

implementation
{$IFDEF Linux}
{$R *.xfm}
{$ELSE}
{$R *.dfm}
{$R IdCreditsBitmap.res}
{$ENDIF}

uses
{$IFNDEF Linux}ShellApi, {$ENDIF}
  IdGlobal, IdResourceStrings;

{$IFDEF Linux}

procedure ShowAboutBox(const AProductName, AProductVersion: string);
begin
  with TformAbout.Create(Application) do
  try
    lblName.Caption := AProductName;
    lblVersion.Caption := Format(RSAAboutBoxVersion, [AProductVersion]);
    ShowModal;
  finally Free;
  end;
end;

procedure TformAbout.FormCreate(Sender: TObject);
begin
  panlScroll.Width := scbxCredits.ClientWidth;
  lblCopyright.Caption := RSAAboutBoxCopyright;
  lblPleaseVisitUs.Caption := RSAAboutBoxPleaseVisit;
  lbCoordinator.Caption := RSAAboutCreditsCoordinator;
  lbCoCordinator.Caption := RSAAboutCreditsCoCordinator;
end;

procedure TformAbout.pbxDividerButtonsPaint(Sender: TObject);
begin
  with (Sender as TPaintBox).Canvas do
  begin
    Pen.Color := clBlack;
    MoveTo(0, 0);
    LineTo(Width, PenPos.Y);
  end;
end;
{$ELSE}

procedure ShowAboutBox(const AProductName, AProductVersion: string);
begin
  with TformAbout.Create(Application) do
  try
    lblName.Caption := AProductName;
    lblVersion.Caption := Format(RSAAboutBoxVersion, [AProductVersion]);
    ShowModal;
  finally
    Free;
  end;
end;

procedure TformAbout.FormCreate(Sender: TObject);
begin
  Caption := RSAAboutFormCaption;
  lblCopyright.Caption := RSAAboutBoxCopyright;
  lblPleaseVisitUs.Caption := RSAAboutBoxPleaseVisit;
  lblURL.Caption := RSAAboutBoxIndyWebsite;
  scrCredits := TScrollCredits.Create(self);
  with scrCredits do
  try
    Credits.BeginUpdate;
    Parent := Self;
    Align := alClient;
    Background.Bitmap.LoadFromResourceName(HInstance, 'TIDABOUTPICTURE');
    self.Width := Background.Bitmap.Width + Panel2.Width;
    self.Height := Background.Bitmap.Height + Panel1.Height;
    self.Position := poScreenCenter;
    with Credits.HeaderFont do
    begin
      Name := 'Arial';
      Size := 17;
      Color := clRed;
      Style := [fsBold];
    end;
    with Credits.BodyFont do
    begin
      Name := 'Courier New';
      Size := 14;
      Color := clBlue;
      Style := [fsBold];
    end;
    with Credits.Add do
    begin
      Header := RSAAboutCreditsCoordinator;
      Body.Add('Kudzu (Chad Z. Hower)');
      Body.Add('- Nevrona Designs -');
    end;
    with Credits.Add do
    begin
      Header := RSAAboutCreditsCoCordinator;
      Body.Add('Hadi Hariri');
      Body.Add('- Nevrona Designs -');
    end;
    with Credits.Add do
    begin
      ColCount := 2;
      Header := 'The Indy Pit Crew'; // YEAH!
      with Body do
      begin
        Add('Andrew Peter Mee');
        Add('Charles Stack');
        Add('Gregor Ibic');
        Add('- Intelicom d.o.o. -');
        Add('J. Peter Mugaas');
        Add('- Nevrona Designs -');
        Add('Jim Gunkel');
        Add('- Nevrona Designs -');
        Add('Mark Holmes');
        Add('Rune Moberg');
        Add('Stéphane Grobéty');
      end;
    end;
    with Credits.Add do
    begin
      ColCount := 1;
      Header := 'Documentation Coordinator';
      Body.Add('Don Siders');
    end;
    with Credits.Add do
    begin
      ColCount := 1;
      Header := 'Demo Coordinator';
      Body.Add('Allen O''Neill');
    end;
    OnClick := ScrollClick;
  finally
    Credits.EndUpdate;
  end;
  Brush.Style := bsClear;
end;

procedure TformAbout.lblURLClick(Sender: TObject);
begin
  ShellAPI.shellExecute((Self as TControl).Handle, PChar('open'),
    PChar(lblURL.Caption), nil, nil, 0);
end;

procedure TformAbout.ScrollClick(Sender: TObject);
begin
  (Sender as TScrollCredits).CurrentLine := 0;
end;

procedure TformAbout.tmrScrollTimer(Sender: TObject);
begin
  scrCredits.CurrentLine := Succ(scrCredits.CurrentLine);
end;

procedure TformAbout.WMEraseBkgnd(var Message: TWMEraseBkgnd);
begin
  Message.Result := 1;
end;

type
  TRGB32 = packed record
    b, g, r, a: byte;
  end;
  PRGB32Array = ^TRGB32Array;
  TRGB32Array = packed array[0..maxint div sizeof(TRGB32) - 1] of TRGB32;
  PRGB24 = ^TRGB24;
  TRGB24 = packed record
    b, g, r: byte;
  end;
  PRGB24Array = ^TRGB24Array;
  TRGB24Array = packed array[0..maxint div sizeof(TRGB24) - 1] of TRGB24;

function AddSizeY(var size1: TSize; const size2: TSize): TSize;
begin
  with Result do
  begin
    cx := Max(size1.cx, size2.cx);
    cy := size1.cy + size2.cy;
  end;
  size1 := Result;
end;

function TextToStrings(const s: string): TStrings;
begin
  Result := TStringList.Create;
  Result.Text := s;
end;

{ TScrollCredits }

procedure TScrollCredits.BackgroundChange(Sender: TObject);
begin
  bmpBack.Assign(FBackground.Bitmap);
  bmpBack.PixelFormat := pf24bit;
  bmpBuffer.Width := bmpBack.Width;
  bmpBuffer.Height := bmpBack.Height;
  bmpBuffer.Canvas.Draw(0, 0, bmpBack);
  Invalidate;
end;

procedure TScrollCredits.CMFontchanged(var Message: TMessage);
begin
  InvalidateBitmap;
  inherited;
end;

constructor TScrollCredits.Create(AOwner: TComponent);
begin
  inherited;
  FCredits := TCreditStrings.Create(self);
  bmpCredits := TBitmap.Create;
  bmpCredits.PixelFormat := pf32bit;
  bmpBack := TBitmap.Create;
  bmpBuffer := TBitmap.Create;
  bmpBuffer.PixelFormat := pf24bit;
  FBackground := TPicture.Create;
  FBackground.OnChange := BackgroundChange;
  ControlStyle := ControlStyle + [csOpaque];
end;

procedure TScrollCredits.CreditsChange;
begin
  InvalidateBitmap;
  Invalidate;
end;

destructor TScrollCredits.Destroy;
begin
  bmpCredits.Free;
  bmpBack.Free;
  bmpBuffer.Free;
  FCredits.Free;
  FBackground.Free;
  inherited;
end;

procedure TScrollCredits.InvalidateBitmap;
var
  x, i: integer;
  sl: PRGB32Array;
begin
  with bmpCredits do
  begin
    with Credits.TextExtent(Canvas) do
    begin
      Width := cx;
      Height := cy + 10;
    end;
    for i := 0 to Height - 1 do
    begin
      sl := ScanLine[i];
      for x := 0 to Width - 1 do
      begin
        FillChar(sl[x], sizeof(TRGB32), clSilver);
        sl[x].a := $FF;
      end;
    end;
    Canvas.Brush.Style := bsClear;
    Credits.RenderText(0, Width, Canvas);
  end;
end;

procedure TScrollCredits.Paint;
var
  x, y, w, h: integer;
begin
  bmpBuffer.Width := Width;
  bmpBuffer.Height := Height;
  TransposeCredits;
  with Canvas.ClipRect do
  begin
    x := Left;
    y := Top;
    w := Right - Left;
    h := Bottom - Top;
  end;
  BitBlt(Canvas.Handle, x, y, w, h, bmpBuffer.Canvas.Handle, x, y, SRCCOPY);
end;

procedure TScrollCredits.SetBackground(const Value: TPicture);
begin
  FBackground.Assign(Value);
end;

procedure TScrollCredits.SetCredits(const Value: TCreditStrings);
begin
  FCredits.Assign(Value);
end;

procedure TScrollCredits.SetCurrentLine(const Value: Integer);
begin
  if FCurrentLine > Value then
    bmpBuffer.Canvas.Draw(0, 0, bmpBack);
  if FCurrentLine <> Value then
  begin
    Invalidate;
    FCurrentLine := Value;
  end;
end;

procedure TScrollCredits.TransposeCredits;
var
  x, y,
    w, h, starty, maxh,
    startx: integer;
  transparency: integer;
  targetline, backdropline: PRGB24Array;
  sourceline: PRGB32Array;
begin
  h := bmpBuffer.Height;
  starty := Max(h - CurrentLine, 0);
  maxh := Min(h, bmpCredits.Height + h - CurrentLine);
  startx := Max(0, (bmpBuffer.Width - bmpCredits.Width) div 2);
  w := Min(bmpBuffer.Width, bmpCredits.Width + startx);
  for y := starty to maxh - 1 do
  begin
    transparency := Round(100 * (h - y) / h);
    targetline := bmpBuffer.ScanLine[y];
    sourceline := bmpCredits.ScanLine[y - (h - CurrentLine)];
    backdropline := bmpBack.ScanLine[y];
    for x := startx to w - 1 do
      if sourceline[x - startx].a < $7F then
        with backdropline[x] do
        begin
          targetline[x].b := Round((Transparency * b + (100 - Transparency) *
            sourceline[x - startx].b) * 0.01);
          targetline[x].g := Round((Transparency * g + (100 - Transparency) *
            sourceline[x - startx].g) * 0.01);
          targetline[x].r := Round((Transparency * r + (100 - Transparency) *
            sourceline[x - startx].r) * 0.01);
        end
      else
        targetline[x] := backdropline[x];
  end;
end;

{ TCreditString }

procedure TCreditString.Assign(Source: TPersistent);
begin
  if Source is TCreditString then
  begin
    FHeader := TCreditString(Source).Header;
    FBody := TCreditString(Source).Body;
  end
  else
    inherited;
end;

procedure TCreditString.BodyChanged(sender: TObject);
begin
  Changed(False);
end;

constructor TCreditString.Create(Collection: TCollection);
begin
  inherited;
  FColCount := 1;
  FBody := TStringList.Create;
  TStringList(FBody).OnChange := BodyChanged;
end;

destructor TCreditString.Destroy;
begin
  FBody.Free;
  inherited;
end;

function TCreditString.GetBodyItems(Index: Integer): string;
begin
  Result := Body[Index];
end;

procedure TCreditString.RenderText(const ATop, AWidth: Integer; Canvas:
  TCanvas);
var
  cw: Integer;

  procedure TextOut(const X, Y: Integer; const Text: string);
  var
    SaveColor: TColor;
  begin
    with Canvas do
    begin
      SaveColor := Font.Color;
      Font.Color := clBlack;
      TextOut(x + 2, y + 2, Text);
      Font.Color := clWhite;
      TextOut(x, y, Text);
      Font.Color := SaveColor;
      TextOut(x + 1, y + 1, Text);
    end;
  end;

  procedure CenterText(const X, Y, AWidth: Integer; const Text: string);
  var
    rx: Integer;
  begin
    rx := Round((AWidth - Canvas.TextWidth(Text)) / 2);
    TextOut(X + rx, Y, Text);
  end;

  procedure DrawColumn(const X, Y, Column: Integer);
  var
    i, li: Integer;
    currenty, lineheight: Integer;
  begin
    if Body.Count = 0 then Exit;
    lineheight := Canvas.TextHeight(Body[0]);
    currenty := Y;
    for i := 0 to Body.Count - 1 do
      if i mod ColCount = Column then
      begin
        with TextToStrings(Body[i]) do
        try
          for li := 0 to Count - 1 do
          begin
            CenterText(X, currenty, cw, Strings[li]);
            currenty := currenty + lineheight;
          end;
        finally
          Free;
        end;
      end;
  end;

  function ColumnWidth: integer;
  begin
    Result := (AWidth - TCreditStrings(Collection).ColSpace * (ColCount - 1)) div
      ColCount;
  end;

var
  i,
    h,
    cs: Integer;
begin
  cw := ColumnWidth;
  cs := TCreditStrings(Collection).ColSpace;
  h := 0;
  if Header <> '' then
  begin
    Canvas.Font := TCreditStrings(Collection).HeaderFont;
    CenterText(0, ATop, AWidth, Header);
    h := Canvas.TextHeight(Header);
  end;
  Canvas.Font := TCreditStrings(Collection).BodyFont;
  for i := 0 to ColCount - 1 do
    DrawColumn((cw + cs) * i, ATop + h, i);
end;

procedure TCreditString.SetBody(const Value: TStrings);
begin
  FBody.Assign(Value);
end;

procedure TCreditString.SetBodyItems(Index: Integer; const Value: string);
begin
  Body[Index] := Value;
end;

procedure TCreditString.SetColCount(const Value: Integer);
begin
  if (FColCount <> Value) and (Value > 0) then
  begin
    FColCount := Value;
    Changed(False);
  end;
end;

procedure TCreditString.SetHeader(const Value: string);
begin
  if Value <> FHeader then
  begin
    FHeader := Value;
    Changed(False);
  end;
end;

function TCreditString.TextExtent(Canvas: TCanvas): TSize;

  function TextExtent(const s: string): TSize;
  var
    i: integer;
  begin
    FillChar(Result, SizeOf(TSize), 0);
    with TextToStrings(s) do
    try
      for i := 0 to Count - 1 do
        AddSizeY(Result, Canvas.TextExtent(Strings[i]));
    finally
      Free;
    end;
  end;

  function ColumnExtent(const Column: integer): TSize;
  var
    i: integer;
  begin
    FillChar(Result, SizeOf(TSize), 0);
    for i := 0 to Body.Count - 1 do
      if i mod ColCount = Column then
        AddSizeY(Result, TextExtent(Body[i]));
  end;

var
  i: integer;
  maxcolcx, maxcolcy: integer;
  csize: TSize;
begin
  if (FTextExtent.cx <> 0) or (FTextExtent.cy <> 0) then
    Result := FTextExtent
  else
  begin
    FillChar(Result, SizeOf(TSize), 0);
    maxcolcx := 0;
    maxcolcy := 0;
    if Header <> '' then
    begin
      Canvas.Font := (Collection as TCreditStrings).HeaderFont;
      Result := TextExtent(Header);
    end;
    Canvas.Font := (Collection as TCreditStrings).BodyFont;
    for i := 0 to ColCount - 1 do
    begin
      csize := ColumnExtent(i);
      maxcolcx := Max(csize.cx, maxcolcx);
      maxcolcy := Max(csize.cy, maxcolcy);
    end;
    i := TCreditStrings(Collection).ColSpace * (ColCount - 1);
    csize.cy := maxcolcy;
    csize.cx := maxcolcx * ColCount + i;
    AddSizeY(Result, csize);
    FTextExtent := Result;
  end;
end;

function TCreditStrings.Add: TCreditString;
begin
  result := TCreditString(inherited Add);
end;

procedure TCreditStrings.Assign(Source: TPersistent);
begin
  BeginUpdate;
  try
    if Source is TCreditStrings then
    begin
      ColSpace := TCreditStrings(Source).ColSpace;
      HeaderFont := TCreditStrings(Source).HeaderFont;
      BodyFont := TCreditStrings(Source).BodyFont;
    end;
    inherited;
  finally
    EndUpdate;
  end;
end;

constructor TCreditStrings.Create(AnOwner: TScrollCredits);
begin
  FOwner := AnOwner;
  inherited Create(AnOwner, TCreditString);
  FBodyFont := TFont.Create;
  FBodyFont.Assign(FOwner.Font);
  FBodyFont.OnChange := FontChange;
  FHeaderFont := TFont.Create;
  FHeaderFont.Assign(FOwner.Font);
  FHeaderFont.OnChange := FontChange;
end;

destructor TCreditStrings.Destroy;
begin
  FHeaderFont.Free;
  FBodyFont.Free;
  inherited;
end;

procedure TCreditStrings.FontChange(Sender: TObject);
begin
  Changed;
end;

function TCreditStrings.GetItems(Index: Integer): TCreditString;
begin
  Result := TCreditString(inherited Items[Index]);
end;

procedure TCreditStrings.RenderText(const ATop, AWidth: Integer;
  Canvas: TCanvas);
var
  i,
    y: integer;
begin
  y := ATop;
  for i := 0 to Count - 1 do
  begin
    Items[i].RenderText(y, AWidth, Canvas);
    y := y + Items[i].TextExtent(Canvas).cy;
  end;
end;

procedure TCreditStrings.SetBodyFont(const Value: TFont);
begin
  FBodyFont.Assign(Value);
end;

procedure TCreditStrings.SetColSpace(const Value: Integer);
begin
  if FColSpace <> Value then
  begin
    FColSpace := Value;
    Changed;
  end;
end;

procedure TCreditStrings.SetHeaderFont(const Value: TFont);
begin
  FHeaderFont.Assign(Value);
end;

procedure TCreditStrings.SetItems(Index: Integer;
  const Value: TCreditString);
begin
  inherited Items[Index] := Value;
end;

function TCreditStrings.TextExtent(Canvas: TCanvas): TSize;
var
  i: integer;
begin
  FillChar(Result, SizeOf(TSize), 0);
  for i := 0 to Count - 1 do
    AddSizeY(Result, Items[i].TextExtent(Canvas));
end;

procedure TCreditStrings.Update(Item: TCollectionItem);
var
  i: integer;
begin
  inherited;
  if Assigned(Item) then
    FillChar(TCreditString(Item).FTextExtent, SizeOf(TSize), 0)
  else
    for i := 0 to Count - 1 do
      FillChar(Items[i].FTextExtent, SizeOf(TSize), 0);
  FOwner.CreditsChange;
end;

procedure TformAbout.FormShow(Sender: TObject);
begin
  tmrScroll.enabled := true;
end;
{$ENDIF}

end.
