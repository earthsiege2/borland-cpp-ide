{ *************************************************************************** }
{                                                                             }
{ Delphi and Kylix Cross-Platform Visual Component Library                    }
{                                                                             }
{ Copyright (c) 2000, 2001 Borland Software Corporation                       }
{                                                                             }
{ *************************************************************************** }

unit QPrinters;

{$R-,T-,X+,H+}

interface

uses
  Qt, QGraphics, Types, Classes, QConsts, SysUtils;

type
  EPrinter = class(Exception);

  TOutputType = (otPrinter, otProgram, otFileName, otPort, otCustom);
  TPrinterOrientation = (poPortrait, poLandscape);
  TPrinterCapability = (pcCopies, pcOrientation, pcCollation);
  TPrintAdapter = class;
  TPageSize = (psA4, psB5, psLetter, psLegal, psExecutive, psA0, psA1, psA2,
    psA3, psA5, psA6, psA7, psA8, psA9, psB0, psB1, psB10, psB2, psB3, psB4, psB6,
    psB7, psB8, psB9, psC5E, psComm10E, psDLE, psFolio, psLedger, psTabloid, psNPageSize);

{ TPrinter }

  TPrinter = class
  private
    PrintAdapterOwned: Boolean;
    FPrinters: TStrings;
  protected
    FPageNumber: Integer;
    FPrintAdapter: TPrintAdapter;
    FPrinting: Boolean;
    FTitle: WideString;
    FMargins: TSize;
    FPageSize: TPageSize;
    FXDPI: Integer;
    FYDPI: Integer;
    procedure CheckPrinting(Value: Boolean);
    function GetAborted: Boolean;
    function GetCanvas: TCanvas; virtual;
    function GetNumCopies: Integer;
    procedure SetNumCopies(Value: Integer);
    function GetHandle: QPaintDeviceH;
    function GetOrientation: TPrinterOrientation;
    procedure SetOrientation(Value: TPrinterOrientation);
    function GetPageHeight: Integer;
    function GetPageWidth: Integer;
    function GetPrinters: TStrings;
    function GetPrintAdapter: TPrintAdapter;
    procedure SetPrintAdapter(Value: TPrintAdapter);
    function GetMargins: TSize;
    procedure SetTitle(const Value: WideString);
    function GetTitle: WideString;
    function GetXDPI: Integer;
    function GetYDPI: Integer;
    function GetOutputType: TOutputType;
    function GetOutputDevice: WideString;
  public
    constructor Create;
    destructor Destroy; override;
    procedure Abort;
    procedure BeginDoc;
    procedure EndDoc;
    procedure NewPage;
    function ExecuteSetup: Boolean;
    function SetPrinter(const Value: string): Boolean;
    function SetOutputProgram(const Value: string): Boolean;
    function SetOutputFileName(const Value: string): Boolean;
    function SetOutputPort(const Value: string): Boolean;
    function SupportOutputType(OutputType: TOutputType): Boolean;
    property Aborted: Boolean read GetAborted;
    property Canvas: TCanvas read GetCanvas;
    property Copies: Integer read GetNumCopies write SetNumCopies;
    property Handle: QPaintDeviceH read GetHandle;
    property Orientation: TPrinterOrientation read GetOrientation write SetOrientation;
    property PageHeight: Integer read GetPageHeight;
    property PageWidth: Integer read GetPageWidth;
    property PageNumber: Integer read FPageNumber;
    property PrintAdapter: TPrintAdapter read GetPrintAdapter write SetPrintAdapter;
    property Printing: Boolean read FPrinting;
    property Printers: TStrings read GetPrinters;
    property Title: WideString read GetTitle write SetTitle;
    property Margins: TSize read GetMargins;
    property XDPI: Integer read GetXDPI;
    property YDPI: Integer read GetYDPI;
    property OutputType: TOutputType read GetOutputType;
    property OutputDevice: WideString read GetOutputDevice;
  end;

{ TPrintAdapter }

  TPrintAdapter = class
  protected
    function GetAborted: boolean; virtual; abstract;
    function GetCanvas: TCanvas; virtual; abstract;
    function GetCopies: Integer; virtual;
    procedure SetCopies(Value: Integer); virtual;
    function GetHandle: QPaintDeviceH; virtual; abstract;
    function GetOutputID: string; virtual; abstract;
    function GetPageHeight: Integer; virtual; abstract;
    function GetPageWidth: Integer; virtual; abstract;
    function GetOrientation: TPrinterOrientation; virtual; abstract;
    procedure SetOrientation(const Value: TPrinterOrientation); virtual; abstract;
    procedure GetPrinters(Printers: TStrings); virtual;
    function GetOutputType: TOutputType; virtual; abstract;
    function GetOutputDevice: WideString; virtual; abstract;
    function GetMargins: TSize; virtual; abstract;
    procedure SetTitle(const Value: WideString); virtual; abstract;
    function GetTitle: WideString; virtual; abstract;
    procedure SetPageSize(const Value: TPageSize); virtual; abstract;
    function GetPageSize: TPageSize; virtual; abstract;
    function GetXDPI: Integer; virtual; abstract;
    function GetYDPI: Integer; virtual; abstract;
    function GetDeviceMetrics: QPaintDeviceMetricsH; virtual; abstract;
  public
    procedure Abort; virtual; abstract;
    procedure BeginDoc; virtual; abstract;
    procedure EndDoc; virtual; abstract;
    procedure NewPage; virtual; abstract;
    function ExecuteSetup: Boolean; virtual; abstract;
    function SupportOutputType(Value: TOutputType): Boolean; virtual; abstract;
    function SetOutput(AOutputType: TOutputType;
      const AOutputDevice: WideString): Boolean; virtual; abstract;
    function TextExtent(const AText: WideString): TSize; virtual;
    property Aborted: Boolean read GetAborted;
    property Canvas: TCanvas read GetCanvas;
    property Handle: QPaintDeviceH read GetHandle;
    property DeviceMetrics: QPaintDeviceMetricsH read GetDeviceMetrics;
    property Copies: Integer read GetCopies write SetCopies;
    property OutputID: string read GetOutputID;
    property PageHeight: Integer read GetPageHeight;
    property PageWidth: Integer read GetPageWidth;
    property PageSize: TPageSize read GetPageSize write SetPageSize;
    property OutputType: TOutputType read GetOutputType;
    property OutputDevice: WideString read GetOutputDevice;
  end;

{ TPrintAdapterCanvas }

  TPrintAdapterCanvas = class(TCanvas)
  private
    FPrintAdapter: TPrintAdapter;
  protected
    procedure BeginPainting; override;
    procedure CreateHandle; override;
    procedure Changing; override;
    procedure UpdateFont;
  public
    constructor Create(PrintAdapter: TPrintAdapter);
  end;

{ TQPrintAdapter }

  TQPrintAdapter = class(TPrintAdapter)
  protected
    FHandle: QPaintDeviceH;
    FCanvas: TCanvas;
    FDeviceMetrics: QPaintDeviceMetricsH;
    FOutputDevice: WideString;
    FOutputType: TOutputType;
    function GetAborted: Boolean; override;
    function GetCanvas: TCanvas; override;
    function GetHandle: QPaintDeviceH; override;
    function GetDeviceMetrics: QPaintDeviceMetricsH; override;
    function GetOutputID: string; override;
    function GetPageHeight: Integer; override;
    function GetPageWidth: Integer; override;
    function GetOrientation: TPrinterOrientation; override;
    procedure SetOrientation(const Value: TPrinterOrientation); override;
    function GetOutputType: TOutputType; override;
    function GetOutputDevice: WideString; override;
    procedure GetPrinters(Printers: TStrings); override;
    procedure SetFullPage(Value: Boolean);
    function GetFullPage: Boolean;
    procedure SetColorMode(const Value: QPrinterColorMode);
    function GetColorMode: QPrinterColorMode;
    procedure SetPageOrder(const Value: QPrinterPageOrder);
    function GetPageOrder: QPrinterPageOrder;
    procedure SetPageSize(const Value: TPageSize); override;
    function GetPageSize: TPageSize; override;
    function GetMargins: TSize; override;
    procedure SetTitle(const Value: WideString); override;
    function GetTitle: WideString; override;
    function GetXDPI: Integer; override;
    function GetYDPI: Integer; override;
  public
    constructor Create;
    procedure Abort; override;
    procedure BeginDoc; override;
    procedure EndDoc; override;
    procedure NewPage; override;
    function ExecuteSetup: Boolean; override;
    function SupportOutputType(Value: TOutputType): Boolean; override;
    function SetOutput(AOutputType: TOutputType;
      const AOutputDevice: WideString): Boolean; override;
    property FullPage: Boolean read GetFullPage write SetFullPage;
    property ColorMode: QPrinterColorMode read GetColorMode write SetColorMode;
    property PageOrder: QPrinterPageOrder read GetPageOrder write SetPageOrder;
  end;

{ Printer function - Replaces the Printer global variable of previous versions,
  to improve smart linking (reduce exe size in projects that don't use
  the printer).  Code which assigned to the Printer global variable
  must call SetPrinter instead.  SetPrinter returns current printer object
  and makes the new printer object the current printer.  It is the caller's
  responsibility to free the old printer, if appropriate.  (This allows
  toggling between different printer objects without destroying configuration
  settings.) }

  function Printer: TPrinter;
  function SetPrinter(NewPrinter: TPrinter): TPrinter;

{ AssignPrn - Assigns a Text variable to a TPrinter device.  If a TPrinter
  device is not explicitly passed in for the APrinter parameter or nil is
  passed in, an internal TPrinter object will be created then destroyed when
  the text device is closed.  The result of AssignPrn will be the TPrinter
  object that it will print to.  Use the Rewrite procedure after calling
  AssignPrn to enable the printer output.  Any Write or Writeln's going to
  that file variable will be written on the printer using the Canvas
  property's font.  A new page is automatically started if a CR is
  encountered on (or a Writeln is written to) the last line on the page.
  Closing the text file will imply a call to the Printer.EndDoc method.  }

  function AssignPrn(var AFile: Text;
                         APrinter: TPrinter = nil): TPrinter;
  procedure RaisePrinterError(const Msg: string);
  procedure CheckPrinting(Adapter: TPrintAdapter; Value: Boolean);

implementation

{$IFDEF MSWINDOWS}
uses
  Windows, WinSpool;
{$ENDIF}

type
  TPageWidthHeight = record
    Width: Integer;
    Height: Integer;
  end;

const
  PageSizeArray: array[0..30] of TPageWidthHeight =
    (
      (Width: 8268; Height: 11693),  // psA4
      (Width: 7165; Height: 10118),  // psB5
      (Width: 8500; Height: 11000),  // psLetter
      (Width: 8500; Height: 14000),  // psLegal
      (Width: 7500; Height: 10000),  // psExecutive
      (Width: 33110; Height: 46811), // psA0
      (Width: 23386; Height: 33110), // psA1
      (Width: 16535; Height: 23386), // psA2
      (Width: 11693; Height: 16535), // psA3
      (Width: 5827; Height: 8268),   // psA5
      (Width: 4134; Height: 5827),   // psA6
      (Width: 2913; Height: 4134),   // psA7
      (Width: 2047; Height: 2913),   // psA8
      (Width: 1457; Height: 2047),   // psA9
      (Width: 40551; Height: 57323), // psB0
      (Width: 28661; Height: 40551), // psB1
      (Width: 1260; Height: 1772),   // psB10
      (Width: 20276; Height: 28661), // psB2
      (Width: 14331; Height: 20276), // psB3
      (Width: 10118; Height: 14331), // psB4
      (Width: 5039; Height: 7165),   // psB6
      (Width: 3583; Height: 5039),   // psB7
      (Width: 2520; Height: 3583),   // psB8
      (Width: 1772; Height: 2520),   // psB9
      (Width: 6417; Height: 9016),   // psC5E
      (Width: 4125; Height: 9500),   // psComm10E
      (Width: 4331; Height: 8661),   // psDLE
      (Width: 8250; Height: 13000),  // psFolio
      (Width: 17000; Height: 11000), // psLedger
      (Width: 11000; Height: 17000), // psTabloid
      (Width: -1; Height: -1)        // psNPageSize
    );

{ TPrinter }

constructor TPrinter.Create;
begin
  inherited;
end;

destructor TPrinter.Destroy;
begin
  FPrintAdapter.Free;
  inherited Destroy;
end;

procedure TPrinter.CheckPrinting(Value: Boolean);
begin
  if Printing <> Value then
    if Value then
      RaisePrinterError(SNotPrinting)
    else
      RaisePrinterError(SPrinting);
end;

function TPrinter.GetAborted: Boolean;
begin
  Result := PrintAdapter.Aborted;
end;

function TPrinter.GetCanvas: TCanvas;
begin
  Result := PrintAdapter.Canvas;
end;

function TPrinter.GetNumCopies: Integer;
begin
  Result := PrintAdapter.Copies;
end;

procedure TPrinter.SetNumCopies(Value: Integer);
begin
  PrintAdapter.Copies := Value;
end;

function TPrinter.GetHandle: QPaintDeviceH;
begin
  Result := PrintAdapter.Handle;
end;

function TPrinter.GetOrientation: TPrinterOrientation;
begin
  Result := PrintAdapter.GetOrientation;
end;

procedure TPrinter.SetOrientation(Value: TPrinterOrientation);
begin
  PrintAdapter.SetOrientation(Value);
end;

function TPrinter.GetPageHeight: Integer;
begin
  Result := PrintAdapter.PageHeight;
end;

function TPrinter.GetPageWidth: Integer;
begin
  Result := PrintAdapter.PageWidth;
end;

function TPrinter.GetPrinters: TStrings;
begin
  if FPrinters = nil then
  begin
    FPrinters := TStringList.Create;
    PrintAdapter.GetPrinters(FPrinters);
  end;
  Result := FPrinters;
end;

procedure TPrinter.Abort;
begin
  CheckPrinting(True);
  PrintAdapter.Abort;
end;

procedure TPrinter.BeginDoc;
begin
  CheckPrinting(False);
  PrintAdapter.BeginDoc;
  FPrinting := True;
end;

procedure TPrinter.EndDoc;
begin
  CheckPrinting(True);
  PrintAdapter.EndDoc;
  if PrintAdapterOwned then
  begin
    //move the spirit of this code to TQPrintAdapter.Destroy
    //when interface changes are allowed.
    if (FPrintAdapter is TQPrintAdapter) then
      with TQPrintAdapter(FPrintAdapter) do
      begin
        if FHandle <> nil then
        begin
          QPrinter_destroy(QPrinterH(FHandle));
          FHandle := nil;
        end;
        if Assigned(Canvas) then
        begin
          Canvas.Free;
          FCanvas := nil;
        end;
      end;
    FreeAndNil(FPrintAdapter);
  end;
  FPrinting := False;
end;

procedure TPrinter.NewPage;
begin
  CheckPrinting(True);
  PrintAdapter.NewPage;
end;

function TPrinter.ExecuteSetup: Boolean;
begin
  Result := PrintAdapter.ExecuteSetup;
end;

function TPrinter.SetPrinter(const Value: string): Boolean;
begin
  Result := PrintAdapter.SetOutput(otPrinter,Value);
end;

function TPrinter.SetOutputProgram(const Value: string): Boolean;
begin
  Result := PrintAdapter.SetOutput(otProgram,Value);
end;

function TPrinter.SetOutputFileName(const Value: string): Boolean;
begin
  Result := PrintAdapter.SetOutput(otFileName,Value);
end;

function TPrinter.SetOutputPort(const Value: string): Boolean;
begin
  Result := PrintAdapter.SetOutput(otPort,Value);
end;

function TPrinter.SupportOutputType(OutputType: TOutputType): Boolean;
begin
  Result := PrintAdapter.SupportOutputType(OutputType);
end;

function TPrinter.GetPrintAdapter: TPrintAdapter;
begin
  if FPrintAdapter = nil then
  begin
    FPrintAdapter := TQPrintAdapter.Create;
    PrintAdapterOwned := True;
  end;
  Result := FPrintAdapter;
end;

procedure TPrinter.SetPrintAdapter(Value: TPrintAdapter);
begin
  CheckPrinting(False);
  if PrintAdapterOwned then
    FreeAndNil(FPrintAdapter);
  FPrintAdapter := Value;
end;

function TPrinter.GetMargins: TSize;
begin
  Result := PrintAdapter.GetMargins;
end;

function TPrinter.GetTitle: WideString;
begin
  Result := PrintAdapter.GetTitle;
end;

procedure TPrinter.SetTitle(const Value: WideString);
begin
  PrintAdapter.SetTitle(Value);
  FTitle := Value;
end;

function TPrinter.GetXDPI: Integer;
begin
  Result := PrintAdapter.GetXDPI;
end;

function TPrinter.GetYDPI: Integer;
begin
  Result := PrintAdapter.GetYDPI;
end;

function TPrinter.GetOutputDevice: WideString;
begin
  Result := PrintAdapter.OutputDevice;
end;

function TPrinter.GetOutputType: TOutputType;
begin
  Result := PrintAdapter.OutputType;
end;

{ TPrintAdapter }

function TPrintAdapter.GetCopies: Integer;
begin
  Result := 1;
end;

procedure TPrintAdapter.SetCopies(Value: Integer);
begin
// Ignore SetCopies by default
end;

procedure TPrintAdapter.GetPrinters(Printers: TStrings);
begin
  Printers.Clear;
end;

function TPrintAdapter.TextExtent(const AText: WideString): TSize;
begin
  Result := TSize(Canvas.TextExtent(AText, 0));
end;

{ TPrintAdapterCanvas }

constructor TPrintAdapterCanvas.Create(PrintAdapter: TPrintAdapter);
begin
  inherited Create;
  FPrintAdapter := PrintAdapter;
end;

procedure TPrintAdapterCanvas.BeginPainting;
begin
  if not QPainter_isActive(Handle) then
  begin
    if not Assigned(FPrintAdapter) then
      RaisePrinterError(SNoAdapter);
    if not QPainter_begin(Handle,FPrintAdapter.Handle) then
      RaisePrinterError(SInvalidCanvasState);
  end;
end;

procedure TPrintAdapterCanvas.CreateHandle;
begin
  Handle := QPainter_create;
end;

procedure TPrintAdapterCanvas.Changing;
begin
  CheckPrinting(FPrintAdapter, True);
  inherited Changing;
  UpdateFont;
end;

procedure TPrintAdapterCanvas.UpdateFont;
var
  FontSize: Integer;
begin
  if FPrintAdapter.GetYDPI <> Font.PixelsPerInch then
  begin
    FontSize := Font.Size;
    Font.PixelsPerInch := FPrintAdapter.GetYDPI;
    Font.Size := FontSize;
  end;
end;

{ TQPrintAdapter }

constructor TQPrintAdapter.Create;
begin
  inherited Create;
  FOutputType := otPrinter;
end;

function TQPrintAdapter.GetHandle: QPaintDeviceH;
begin
  if FHandle = nil then
    FHandle := QPrinter_create;
  Result := FHandle;
end;

function TQPrintAdapter.GetOutputType: TOutputType;
begin
  Result := FOutputType;
end;

function TQPrintAdapter.GetOutputDevice: WideString;
begin
  Result := FOutputDevice;
end;

function TQPrintAdapter.GetDeviceMetrics: QPaintDeviceMetricsH;
begin
  if FDeviceMetrics = nil then
    FDeviceMetrics := QPaintDeviceMetrics_create (Handle);
  Result := FDeviceMetrics;
end;

function TQPrintAdapter.GetAborted: Boolean;
begin
  Result := QPrinter_aborted(QPrinterH(Handle));
end;

function TQPrintAdapter.GetCanvas: TCanvas;
begin
  if FCanvas = nil then
    FCanvas := TPrintAdapterCanvas.Create(Self);
  Result := FCanvas;
end;

function TQPrintAdapter.GetOutputID: string;
begin
  Result := 'QPrinter';
end;

procedure TQPrintAdapter.GetPrinters(Printers: TStrings);
{$IFDEF MSWINDOWS}
  function FetchStr(var Str: PChar): PChar;
  var
    P: PChar;
  begin
    Result := Str;
    if Str = nil then Exit;
    P := Str;
    while P^ = ' ' do Inc(P);
    Result := P;
    while (P^ <> #0) and (P^ <> ',') do Inc(P);
    if P^ = ',' then
    begin
      P^ := #0;
      Inc(P);
    end;
    Str := P;
  end;

var
  LineCur, Port: PChar;
  Buffer, PrinterInfo: PChar;
  Flags, Count, NumInfo: DWORD;
  I: Integer;
  Level: Byte;
{$ELSE}
var
  PrintCap: TStrings;
  i,
  j: Integer;
  ALine: string;
{$ENDIF}
begin
  Printers.Clear;
{$IFDEF MSWINDOWS}
  if Win32Platform = VER_PLATFORM_WIN32_NT then
  begin
    Flags := PRINTER_ENUM_CONNECTIONS or PRINTER_ENUM_LOCAL;
    Level := 4;
  end
  else
  begin
    Flags := PRINTER_ENUM_LOCAL;
    Level := 5;
  end;
  Count := 0;
  EnumPrinters(Flags, nil, Level, nil, 0, Count, NumInfo);
  if Count = 0 then
    Exit;
  GetMem(Buffer, Count);
  try
    if not EnumPrinters(Flags, nil, Level, PByte(Buffer), Count, Count, NumInfo) then
      Exit;
    PrinterInfo := Buffer;
    for I := 0 to NumInfo - 1 do
      if Level = 4 then
        with PPrinterInfo4(PrinterInfo)^ do
        begin
          Printers.Add(pPrinterName);
          Inc(PrinterInfo, sizeof(TPrinterInfo4));
        end
      else
        with PPrinterInfo5(PrinterInfo)^ do
        begin
          LineCur := pPortName;
          Port := FetchStr(LineCur);
          while Port^ <> #0 do
          begin
            Printers.Add(Format(SDeviceOnPort,[pPrinterName,Port]));
            Port := FetchStr(LineCur);
          end;
          Inc(PrinterInfo,sizeof(TPrinterInfo5));
        end;
  finally
    FreeMem(Buffer,Count);
  end;
{$ELSE}
begin
  PrintCap := TStringList.Create;
  try
    PrintCap.LoadFromFile('/etc/printcap');
    for i := 0 to PrintCap.Count - 1 do
    begin
      ALine := PrintCap.Strings[i];
      if AnsiSameText(Copy(ALine, 1, 11), '##PRINTTOOL') then
      begin
        for j := 1 to 6 do
        begin
          Delete(ALine, 1, Pos(' ', ALine));
        end;
        ALine := Copy(ALine, 1, Pos(' ', ALine));
        Printers.Add(Aline);
      end;
    end;
  finally
    PrintCap.Free;
  end;
end;
{$ENDIF}
end;

procedure TQPrintAdapter.Abort;
begin
  QPrinter_abort(QPrinterH(Handle));
end;

procedure TQPrintAdapter.BeginDoc;
begin
  Canvas.Start;
end;

procedure TQPrintAdapter.EndDoc;
begin
  Canvas.Stop;
end;

procedure TQPrintAdapter.NewPage;
begin
  QPrinter_newPage(QPrinterH(Handle));
end;

function TQPrintAdapter.GetPageHeight: Integer;
begin
  if Printer.Orientation = poPortrait then
  begin
    Result := (PageSizeArray[Ord(PageSize)].Height * GetYDPI) div 1000;
  end
  else
  begin
    Result := (PageSizeArray[Ord(PageSize)].Width * GetXDPI) div 1000;
  end;
end;

function TQPrintAdapter.GetPageWidth: Integer;
begin
  if Printer.Orientation = poPortrait then
  begin
    Result := (PageSizeArray[Ord(PageSize)].Width * GetXDPI) div 1000;
  end
  else
  begin
    Result := (PageSizeArray[Ord(PageSize)].Height * GetYDPI) div 1000;
  end;
end;

function TQPrintAdapter.ExecuteSetup: Boolean;
begin
  Result := QPrinter_setup(QPrinterH(Handle), nil);
end;

function TQPrintAdapter.GetFullPage: Boolean;
begin
  Result := QPrinter_fullPage(QPrinterH(Handle));
end;

procedure TQPrintAdapter.SetFullPage(Value: Boolean);
begin
  QPrinter_setFullPage(QPrinterH(Handle), Value);
end;

function TQPrintAdapter.GetColorMode: QPrinterColorMode;
begin
  Result := QPrinter_colorMode(QPrinterH(Handle));
end;

procedure TQPrintAdapter.SetColorMode(const Value: QPrinterColorMode);
begin
  QPrinter_setColorMode(QPrinterH(Handle), Value);
end;

function TQPrintAdapter.GetPageOrder: QPrinterPageOrder;
begin
  Result := QPrinter_pageOrder(QPrinterH(Handle));
end;

procedure TQPrintAdapter.SetPageOrder(const Value: QPrinterPageOrder);
begin
  CheckPrinting(Self, False);
  QPrinter_setPageOrder(QPrinterH(Handle), Value);
end;

function TQPrintAdapter.GetPageSize: TPageSize;
begin
  Result := TPageSize(Ord(QPrinter_pageSize(QPrinterH(Handle))));
end;

procedure TQPrintAdapter.SetPageSize(const Value: TPageSize);
begin
  CheckPrinting(Self, False);
  QPrinter_setPageSize(QPrinterH(Handle), QPrinterPageSize(Ord(Value)));
end;

function TQPrintAdapter.GetMargins: TSize;
begin
  QPrinter_margins(QPrinterH(Handle), @Result);
end;

function TQPrintAdapter.GetTitle: WideString;
begin
  QPrinter_docName(QPrinterH(Handle), @Result);
end;

procedure TQPrintAdapter.SetTitle(const Value: WideString);
begin
  QPrinter_setDocName(QPrinterH(Handle), PWideString(@Value));
end;

function TQPrintAdapter.GetXDPI: Integer;
begin
  Result := QPaintDeviceMetrics_logicalDpiX(DeviceMetrics);
end;

function TQPrintAdapter.GetYDPI: Integer;
begin
  Result := QPaintDeviceMetrics_logicalDpiY(DeviceMetrics);
end;

function TQPrintAdapter.SupportOutputType(Value: TOutputType): Boolean;
begin
  Result := Value in [otPrinter, otProgram, otFileName];
end;

function TQPrintAdapter.SetOutput(AOutputType: TOutputType;
  const AOutputDevice: WideString): Boolean;
begin
  CheckPrinting(Self, False);
  Result := SupportOutputType(AOutputType);
  if Result then
  begin
    FOutputType := AOutputType;
    FOutputDevice := AOutputDevice;
    case FOutputType of
      otProgram: QPrinter_setPrintProgram(QPrinterH(Handle),
                 PWideString(@FOutputDevice));
      otFileName: QPrinter_setOutputFileName(QPrinterH(Handle),
                  PWideString(@FOutputDevice));
      otPrinter: QPrinter_setPrinterName(QPrinterH(Handle),
                 PWideString(@FOutputDevice));
    end;
  end;
end;

function TQPrintAdapter.GetOrientation: TPrinterOrientation;
begin
  if QPrinter_orientation(QPrinterH(Handle)) = QPrinterOrientation_Portrait then
    Result := poPortrait
  else
    Result := poLandscape;
end;

procedure TQPrintAdapter.SetOrientation(const Value: TPrinterOrientation);
begin
  if Value = poPortrait then
    QPrinter_setOrientation(QPrinterH(Handle), QPrinterOrientation_Portrait)
  else
    QPrinter_setOrientation(QPrinterH(Handle), QPrinterOrientation_Landscape);
end;

{ Global Printer Functions }

var
  FPrinter: TPrinter;

function Printer: TPrinter;
begin
  if FPrinter = nil then
    FPrinter := TPrinter.Create;
  Result := FPrinter;
end;

function SetPrinter(NewPrinter: TPrinter): TPrinter;
begin
  Result := FPrinter;
  FPrinter := NewPrinter;
end;

{ AssignPrn Function }

type
  PrnRec = record
    case Integer of
      1: (
        Cur: TPoint;
        Finish: TPoint;             // End of the printable area
        Height: Integer;            // Height of the current line
        AssignedPrinter: TPrinter;  // Assigned TPrinter object
        PrinterOwned: boolean);     // Printer object owned
      2: (
        Tmp: array[1..32] of Char);
  end;

procedure NewPage(var Prn: PrnRec);
begin
  with Prn do
  begin
    Cur.X := 0;
    Cur.Y := 0;
    AssignedPrinter.NewPage;
  end;
end;

{ Start a new line on the current page, if no more lines left start a new page. }

procedure NewLine(var Prn: PrnRec);
begin
  with Prn do
  begin
    Cur.X := 0;
    if Height = 0 then
      Inc(Cur.Y, AssignedPrinter.PrintAdapter.TextExtent('X').cY)
    else
      Inc(Cur.Y, Height);
    if Cur.Y > (Finish.Y - (Height * 2)) then
      NewPage(Prn);
    Height := 0;
  end;
end;

{ Print a string to the printer without regard to special characters.  These
  should handled by the caller. }

procedure PrnOutStr(var Prn: PrnRec; Text: PChar; Len: Integer);
var
  Extent: TSize;
  TextLen: Integer;
  SubText: string;
begin
  with Prn do
  begin
    while Len > 0 do
    begin
      TextLen := Len;
      SubText := Copy(Text, 1, TextLen);
      Extent := AssignedPrinter.PrintAdapter.TextExtent(SubText);

      while (TextLen > 0) and ((Extent.cX + Cur.X) > Finish.X) do
      begin
        Dec(TextLen);
        SubText := Copy(Text, 1, TextLen);
        Extent := AssignedPrinter.PrintAdapter.TextExtent(SubText);
      end;

      if Extent.cY > Height then
        Height := Extent.cY + 2;
      AssignedPrinter.Canvas.TextOut(Cur.X, Cur.Y, SubText);
      Dec(Len, TextLen);
      Inc(Text, TextLen);
      if Len > 0 then
        NewLine(Prn)
      else
        Inc(Cur.X, Extent.cX);
    end;
  end;
end;

{ Print a string to the printer handling special characters. }

procedure PrnString(var Prn: PrnRec; Text: PChar; Len: Integer);
var
  TextPos: Integer;
  TabWidth: Word;

  procedure Flush;
  begin
    if TextPos <> 0 then
      PrnOutStr(Prn, Text, TextPos);
    Inc(Text, TextPos + 1);
    Dec(Len, TextPos + 1);
    TextPos := 0;
  end;

begin
  TextPos := 0;
  with Prn do
    while TextPos < Len do
      case Text[TextPos] of
        #9:
          begin
            Flush;
            TabWidth := AssignedPrinter.XDPI div 2;
            Inc(Cur.X, TabWidth - ((Cur.X + TabWidth + 1) mod TabWidth) + 1);
            if Cur.X > Finish.X then
              NewLine(Prn);
          end;
        #13: Flush;
        #10:
          begin
            Flush;
            NewLine(Prn);
          end;
        ^L:
          begin
            Flush;
            NewPage(Prn);
          end;
        else
          begin
            Inc(TextPos);
          end;
      end;
  Flush;
end;

{ Called when a Read or Readln is applied to a printer file. Since reading is
  illegal this routine tells the I/O system that no characters where read, which
  generates a runtime error. }

function PrnInput(var AFile: TTextRec): Integer;
begin
  with AFile do
  begin
    BufPos := 0;
    BufEnd := 0;
  end;
  Result := 0;
end;

{ Called when a Write or Writeln is applied to a printer file. The calls
  PrnString to write the text in the buffer to the printer. }

function PrnOutput(var ATextRec: TTextRec): Integer;
begin
  with ATextRec do
  begin
    PrnString(PrnRec(UserData), PChar(BufPtr), BufPos);
    BufPos := 0;
    Result := 0;
  end;
end;

{ Will ignore certain requests by the I/O system such as flush while doing an
  input. }

function PrnIgnore(var ATextRec: TTextRec): Integer;
begin
  Result := 0;
end;

{ Deallocates the resources allocated to the printer file. }

function PrnClose(var ATextRec: TTextRec): Integer;
begin
  PrnRec(ATextRec.UserData).AssignedPrinter.EndDoc;
  if PrnRec(ATextRec.UserData).PrinterOwned then
    FreeAndNil(PrnRec(ATextRec.UserData).AssignedPrinter);
  Result := 0;
end;

{ Called to open I/O on a printer file.  Sets up the TTextFile to point to
  printer I/O functions. }

function PrnOpen(var ATextRec: TTextRec): Integer;
begin
  with ATextRec do
  begin
    if Mode = fmInput then
    begin
      InOutFunc := @PrnInput;
      FlushFunc := @PrnIgnore;
      CloseFunc := @PrnIgnore;
    end
    else
    begin
      Mode := fmOutput;
      InOutFunc := @PrnOutput;
      FlushFunc := @PrnOutput;
      CloseFunc := @PrnClose;

      with PrnRec(UserData) do
      begin
        AssignedPrinter.BeginDoc;
        Cur.X := 0;
        Cur.Y := 0;
        Finish.X := AssignedPrinter.PageWidth;
        Finish.Y := AssignedPrinter.PageHeight;
        Height := 0;
      end;
    end;
    Result := 0;
  end;
end;

function AssignPrn(var AFile: Text;
                       APrinter: TPrinter = nil): TPrinter;
begin
  with TTextRec(AFile) do
  begin
    FillChar(AFile, SizeOf(AFile), 0);
    Mode := fmClosed;
    BufSize := SizeOf(Buffer);
    BufPtr := @Buffer;
    OpenFunc := @PrnOpen;
    if APrinter = nil then
    begin
      Result := TPrinter.Create;
      PrnRec(UserData).PrinterOwned := true;
    end
    else
    begin
      Result := APrinter;
    end;
    PrnRec(UserData).AssignedPrinter := Result;
  end;
end;

procedure CheckPrinting(Adapter: TPrintAdapter; Value: Boolean);
begin
  if Assigned(Adapter) and Assigned(Adapter.Canvas) then
    if QPainter_isActive(Adapter.Canvas.Handle) <> Value then
      if Value then
        RaisePrinterError(SNotPrinting)
      else
        RaisePrinterError(SPrinting);
end;

procedure RaisePrinterError(const Msg: string);
begin
  raise EPrinter.Create(Msg);
end;

initialization
finalization
  FreeAndNil(FPrinter);
end.
