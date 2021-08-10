unit chartfx3;

{ This file contains pascal declarations imported from a type library.
  This file will be written during each import or refresh of the type
  library editor.  Changes to this file will be discarded during the
  refresh process. }

{ ChartFX 2.0 OLE Custom Control }
{ Version 2.0 }

{ Conversion log:
  Warning: 'Type' is a reserved word. _DChartfx.Type changed to Type_
  Warning: 'Const' is a reserved word. _DChartfx.Const changed to Const_
 }

interface

uses Windows, ActiveX, Classes, Graphics, OleCtrls, StdVCL;

const
  LIBID_ChartfxLib: TGUID = '{8996B0A4-D7BE-101B-8650-00AA003A5593}';

const

{ PointType Property settings }

{ PointTypeConstants }

  CHART_NONEMK = 0;
  CHART_RECTMK = 1;
  CHART_CIRCLEMK = 2;
  CHART_TRIANGLEMK = 3;
  CHART_MARBLEMK = 4;
  CHART_CUBEMK = 5;
  CHART_MANYMK = 6;

{ Scheme Property settings }

{ SchemeConstants }

  CHART_CSSOLID = 0;
  CHART_CSBWPATTERN = 1;
  CHART_CSPATTERN = 2;

{ Stacked Property settings }

{ StackedConstants }

  CHART_NOSTACKED = 0;
  CHART_STACKED = 1;
  CHART_STACKED100 = 2;

{ Grid Property settings }

{ GridConstants }

  CHART_NOGRID = 0;
  CHART_HORZGRID = 1;
  CHART_VERTGRID = 2;
  CHART_BOTHGRID = 3;
  CHART_GRIDY2 = 4;

{ ChartType and Type Properties settings }

{ GalleryConstants }

  LINES = 1;
  BAR = 2;
  SPLINE = 3;
  MARK = 4;
  PIE = 5;
  AREA = 6;
  PARETO = 7;
  SCATTER = 8;
  HILOW = 9;

{ ConstType Property settings }

{ ConstTypeConstants }

  CC_HIDETEXT = 1;
  CC_HIDE = 2;

{ LegendStyle Property settings }

{ LegendStyleConstants }

  CL_NOTCLIPPED = 1;
  CL_NOTCHANGECOLOR = 2;
  CL_HIDE = 4;
  CL_HIDEXLEG = 4;
  CL_FORCESERLEG = 8;
  CL_GETLEGEND = 16;
  CL_HIDEYLEG = 32;

{ Flags for OpenData,OpenDataEx and CloseData Methods }

{ OpenDataConstants }

  COD_VALUES = 1;
  COD_CONSTANTS = 2;
  COD_COLORS = 3;
  COD_STRIPES = 4;
  COD_INIVALUES = 5;
  COD_XVALUES = 6;
  COD_STATUSITEMS = 7;
  COD_UNKNOWN = -1;
  COD_UNCHANGE = 0;

{ Values for DblClk and RigClk Methods }

{ ClickConstants }

  CHART_BALLOONCLK = 0;
  CHART_DIALOGCLK = 1;
  CHART_NONECLK = 2;
  CHART_MENUCLK = 3;

{ Values for ShowDialog Method }

{ DialogConstants }

  CDIALOG_EXPORTFILE = 14;
  CDIALOG_IMPORTFILE = 15;
  CDIALOG_WRITETEMPLATE = 8;
  CDIALOG_READTEMPLATE = 9;
  CDIALOG_PAGESETUP = 4;
  CDIALOG_ABOUT = 11;
  CDIALOG_OPTIONS = 12;
  CDIALOG_EDITTITLES = 35;
  CDIALOG_FONTS = 39;
  CDIALOG_ROTATE = 52;

{ Values for Adm Property }

{ AdmConstants }

  CSA_MIN = 0;
  CSA_MAX = 1;
  CSA_GAP = 2;
  CSA_SCALE = 3;
  CSA_YLEGGAP = 4;
  CSA_PIXXVALUE = 5;
  CSA_XMIN = 6;
  CSA_XMAX = 7;
  CSA_XGAP = 8;
  CSA_LOGBASE = 9;

{ Values for Title Property }

{ TitleConstants }

  CHART_LEFTTIT = 0;
  CHART_RIGHTTIT = 1;
  CHART_TOPTIT = 2;
  CHART_BOTTOMTIT = 3;

{ Values for Fonts Property }

{ FontConstants }

  CHART_LEFTFT = 0;
  CHART_RIGHTFT = 1;
  CHART_TOPFT = 2;
  CHART_BOTTOMFT = 3;
  CHART_XLEGFT = 4;
  CHART_YLEGFT = 5;
  CHART_FIXEDFT = 6;
  CHART_LEGENDFT = 7;

{ ItemStyle,ItemWidth,ItemColor Property indexes }

{ ItemConstants }

  CI_HORZGRID = 0;
  CI_VERTGRID = 1;

{ DecimalsNum Property indexes }

{ DecimalConstants }

  CD_ALL = 0;
  CD_VALUES = 1;
  CD_YLEG = 2;
  CD_XLEG = 3;

const

{ Component class GUIDs }
  Class_Chartfx: TGUID = '{8996B0A1-D7BE-101B-8650-00AA003A5593}';

type

{ Forward declarations }
{ Forward declarations: Interfaces }
  _DChartfx = dispinterface;
  _DChartfxEvents = dispinterface;

{ Forward declarations: CoClasses }
  Chartfx = _DChartfx;

{ Forward declarations: Enums }
  PointTypeConstants = TOleEnum;
  SchemeConstants = TOleEnum;
  StackedConstants = TOleEnum;
  GridConstants = TOleEnum;
  GalleryConstants = TOleEnum;
  ConstTypeConstants = TOleEnum;
  LegendStyleConstants = TOleEnum;
  OpenDataConstants = TOleEnum;
  ClickConstants = TOleEnum;
  DialogConstants = TOleEnum;
  AdmConstants = TOleEnum;
  TitleConstants = TOleEnum;
  FontConstants = TOleEnum;
  ItemConstants = TOleEnum;
  DecimalConstants = TOleEnum;

{ Dispatch interface for ChartFX Control }

  _DChartfx = dispinterface
    ['{2DC488B0-D891-101B-8652-00AA003A5593}']
    property DesignDraw: Smallint dispid 4;
    property ThisSerie: Smallint dispid 1;
    property ThisPoint: Smallint dispid 2;
    property AutoInvalidate: WordBool dispid 3;
    property Type_: Integer dispid 5;
    property Style: Integer dispid 6;
    property NSeries: Smallint dispid 7;
    property NValues: Smallint dispid 8;
    property ThisColor: TColor dispid 9;
    property ThisBkColor: TColor dispid 10;
    property LeftGap: Smallint dispid 11;
    property RightGap: Smallint dispid 12;
    property TopGap: Smallint dispid 13;
    property BottomGap: Smallint dispid 14;
    property Decimals: Smallint dispid 15;
    property PointType: Smallint dispid 16;
    property Scheme: Smallint dispid 17;
    property Stacked: Smallint dispid 18;
    property Grid: Smallint dispid 19;
    property WallWidth: Smallint dispid 20;
    property BarHorzGap: Smallint dispid 21;
    property View3D: WordBool dispid 22;
    property Angles3D: Integer dispid 23;
    property PixFactor: Smallint dispid 24;
    property LineWidth: Smallint dispid 25;
    property LineStyle: Smallint dispid 26;
    property LineColor: TColor dispid 27;
    property LineBkColor: TColor dispid 28;
    property FixedWidth: Smallint dispid 29;
    property FixedStyle: Smallint dispid 30;
    property FixedColor: TColor dispid 31;
    property FixedBkColor: TColor dispid 32;
    property FixedGap: Smallint dispid 33;
    property RGBBarHorz: TColor dispid 34;
    property RGBBk: TColor dispid 35;
    property RGB2DBk: TColor dispid 36;
    property RGB3DBk: TColor dispid 37;
    property ShowStatus: WordBool dispid 38;
    property HText: WideString dispid 39;
    property ChartStatus: Smallint dispid 40;
    property Edit: Smallint dispid 41;
    property ChartType: Smallint dispid 42;
    property Chart3D: WordBool dispid 43;
    property ToolBar: WordBool dispid 44;
    property PaletteBar: WordBool dispid 45;
    property PatternBar: WordBool dispid 46;
    property CustTool: Integer dispid 47;
    property ReturnValue: Integer dispid 48;
    property AutoIncrement: WordBool dispid 49;
    property ThisValue: Double dispid 50;
    property VertGridGap: Smallint dispid 51;
    property XLegType: Smallint dispid 52;
    property ConstType: Smallint dispid 53;
    property LeftFont: IFontDisp dispid 54;
    property RightFont: IFontDisp dispid 55;
    property TopFont: IFontDisp dispid 56;
    property BottomFont: IFontDisp dispid 57;
    property XLegFont: IFontDisp dispid 58;
    property YLegFont: IFontDisp dispid 59;
    property FixedFont: IFontDisp dispid 60;
    property LegendFont: IFontDisp dispid 61;
    property LegendWidth: Smallint dispid 62;
    property Enabled: WordBool dispid -514;
    property hWnd: OLE_HANDLE dispid -515;
    property BorderStyle: Smallint dispid -504;
    property hCtlWnd: Integer dispid 63;
    property Value[index: Smallint]: Double dispid 82;
    property XValue[index: Smallint]: Double dispid 83;
    property IniValue[index: Smallint]: Double dispid 84;
    property Const_[index: Smallint]: Double dispid 85;
    property Color[index: Smallint]: TColor dispid 86;
    property BkColor[index: Smallint]: TColor dispid 87;
    property Adm[index: Smallint]: Double dispid 88;
    property Pattern[index: Smallint]: Smallint dispid 89;
    property Fonts[index: Smallint]: Integer dispid 90;
    property Title[index: Smallint]: WideString dispid 91;
    property Legend[index: Smallint]: WideString dispid 92;
    property SerLeg[index: Smallint]: WideString dispid 93;
    property KeyLeg[index: Smallint]: WideString dispid 94;
    property FixLeg[index: Smallint]: WideString dispid 95;
    property YLeg[index: Smallint]: WideString dispid 96;
    property KeySer[index: Smallint]: WideString dispid 97;
    property StatusText[index: Smallint]: WideString dispid 98;
    property RGBFont[index: Smallint]: TColor dispid 99;
    property HFont[index: Smallint]: Smallint dispid 100;
    property ItemWidth[index: Smallint]: Smallint dispid 101;
    property ItemStyle[index: Smallint]: Smallint dispid 102;
    property ItemColor[index: Smallint]: TColor dispid 103;
    property DecimalsNum[index: Smallint]: Smallint dispid 104;
    function OpenDataEx(nType: Smallint; n1, n2: Integer): Integer; dispid 64;
    function CloseData(nType: Smallint): WordBool; dispid 65;
    function DblClk(nType: Smallint; lExtra: Integer): Integer; dispid 66;
    function RigClk(nType: Smallint; lExtra: Integer): Integer; dispid 67;
    function Status(nItems: Smallint; lpStatus: Integer): Integer; dispid 68;
    function ShowDialog(nDialog: Smallint; lExtra: Integer): Integer; dispid 69;
    function PrintIt: Integer; dispid 70;
    function Scroll(wParam, lParam: Integer): Integer; dispid 71;
    function SetStatusItem(index: Smallint; bText: WordBool; nID: Smallint; bFrame: WordBool; nWidth, nMin, nDesp: Smallint; dwStyle: Integer): Integer; dispid 72;
    function Paint(hDC: Integer; nLeft, nTop, nRight, nBottom, wAction: Smallint; lps: Integer): Integer; dispid 73;
    function SetStripe(index: Smallint; dMin, dMax: Double; rgb: TColor): Integer; dispid 74;
    function Language(const sResource: WideString): Integer; dispid 75;
    function ExportFile(const lpszNewValue: WideString): Integer; dispid 76;
    function ImportFile(const lpszNewValue: WideString): Integer; dispid 77;
    function WriteTemplate(const lpszNewValue: WideString): Integer; dispid 78;
    function ReadTemplate(const lpszNewValue: WideString): Integer; dispid 79;
    function CopyData: Integer; dispid 80;
    function CopyBitmap: Integer; dispid 81;
    procedure Refresh; dispid -550;
    procedure AboutBox; dispid -552;
  end;

{ Event interface for ChartFX Control }

  _DChartfxEvents = dispinterface
    ['{2DC488B1-D891-101B-8652-00AA003A5593}']
    procedure LButtonDblClk(x, y, nSerie: Smallint; nPoint: Integer; var nRes: Smallint); dispid 1;
    procedure RButtonDown(x, y, nSerie: Smallint; nPoint: Integer; var nRes: Smallint); dispid 2;
    procedure ChangeValue(dValue: Double; nSerie: Smallint; nPoint: Integer; var nRes: Smallint); dispid 3;
    procedure ChangeString(nType: Smallint; nIndex: Integer; var nRes: Smallint); dispid 4;
    procedure ChangeColor(nType, nIndex: Smallint; var nRes: Smallint); dispid 5;
    procedure Destroy; dispid 6;
    procedure ReadFile; dispid 7;
    procedure ChangePalette(nIndex: Smallint; var nRes: Smallint); dispid 8;
    procedure ChangeFont(nIndex: Smallint; var nRes: Smallint); dispid 9;
    procedure ReadTemplate; dispid 10;
    procedure ChangePattern(nType, nIndex: Smallint; var nRes: Smallint); dispid 11;
    procedure ChangePattPal(nIndex: Smallint; var nRes: Smallint); dispid 12;
    procedure Menu(wParam: Integer; nSerie: Smallint; nPoint: Integer; var nRes: Smallint); dispid 13;
    procedure ChangeType(nType: Smallint; var nRes: Smallint); dispid 14;
    procedure UserScroll(wScrollMsg, wScrollParam: Integer; var nRes: Smallint); dispid 15;
    procedure GetLegend(nType: Smallint; var nRes: Smallint); dispid 16;
  end;

{ ChartFX Control }

  TChartfxLButtonDblClk = procedure(Sender: TObject; x, y, nSerie: Smallint; nPoint: Integer; var nRes: Smallint) of object;
  TChartfxRButtonDown = procedure(Sender: TObject; x, y, nSerie: Smallint; nPoint: Integer; var nRes: Smallint) of object;
  TChartfxChangeValue = procedure(Sender: TObject; dValue: Double; nSerie: Smallint; nPoint: Integer; var nRes: Smallint) of object;
  TChartfxChangeString = procedure(Sender: TObject; nType: Smallint; nIndex: Integer; var nRes: Smallint) of object;
  TChartfxChangeColor = procedure(Sender: TObject; nType, nIndex: Smallint; var nRes: Smallint) of object;
  TChartfxChangePalette = procedure(Sender: TObject; nIndex: Smallint; var nRes: Smallint) of object;
  TChartfxChangeFont = procedure(Sender: TObject; nIndex: Smallint; var nRes: Smallint) of object;
  TChartfxChangePattern = procedure(Sender: TObject; nType, nIndex: Smallint; var nRes: Smallint) of object;
  TChartfxChangePattPal = procedure(Sender: TObject; nIndex: Smallint; var nRes: Smallint) of object;
  TChartfxMenu = procedure(Sender: TObject; wParam: Integer; nSerie: Smallint; nPoint: Integer; var nRes: Smallint) of object;
  TChartfxChangeType = procedure(Sender: TObject; nType: Smallint; var nRes: Smallint) of object;
  TChartfxUserScroll = procedure(Sender: TObject; wScrollMsg, wScrollParam: Integer; var nRes: Smallint) of object;
  TChartfxGetLegend = procedure(Sender: TObject; nType: Smallint; var nRes: Smallint) of object;

  TChartfx = class(TOleControl)
  private
    FOnLButtonDblClk: TChartfxLButtonDblClk;
    FOnRButtonDown: TChartfxRButtonDown;
    FOnChangeValue: TChartfxChangeValue;
    FOnChangeString: TChartfxChangeString;
    FOnChangeColor: TChartfxChangeColor;
    FOnDestroy: TNotifyEvent;
    FOnReadFile: TNotifyEvent;
    FOnChangePalette: TChartfxChangePalette;
    FOnChangeFont: TChartfxChangeFont;
    FOnReadTemplate: TNotifyEvent;
    FOnChangePattern: TChartfxChangePattern;
    FOnChangePattPal: TChartfxChangePattPal;
    FOnMenu: TChartfxMenu;
    FOnChangeType: TChartfxChangeType;
    FOnUserScroll: TChartfxUserScroll;
    FOnGetLegend: TChartfxGetLegend;
    FIntf: _DChartfx;
    function Get_hWnd: OLE_HANDLE;
    procedure Set_hWnd(var Value: OLE_HANDLE);
    function Get_Value(index: Smallint): Double;
    procedure Set_Value(index: Smallint; Value: Double);
    function Get_XValue(index: Smallint): Double;
    procedure Set_XValue(index: Smallint; Value: Double);
    function Get_IniValue(index: Smallint): Double;
    procedure Set_IniValue(index: Smallint; Value: Double);
    function Get_Const_(index: Smallint): Double;
    procedure Set_Const_(index: Smallint; Value: Double);
    function Get_Color(index: Smallint): TColor;
    procedure Set_Color(index: Smallint; Value: TColor);
    function Get_BkColor(index: Smallint): TColor;
    procedure Set_BkColor(index: Smallint; Value: TColor);
    function Get_Adm(index: Smallint): Double;
    procedure Set_Adm(index: Smallint; Value: Double);
    function Get_Pattern(index: Smallint): Smallint;
    procedure Set_Pattern(index: Smallint; Value: Smallint);
    function Get_Fonts(index: Smallint): Integer;
    procedure Set_Fonts(index: Smallint; Value: Integer);
    function Get_Title(index: Smallint): WideString;
    procedure Set_Title(index: Smallint; const Value: WideString);
    function Get_Legend(index: Smallint): WideString;
    procedure Set_Legend(index: Smallint; const Value: WideString);
    function Get_SerLeg(index: Smallint): WideString;
    procedure Set_SerLeg(index: Smallint; const Value: WideString);
    function Get_KeyLeg(index: Smallint): WideString;
    procedure Set_KeyLeg(index: Smallint; const Value: WideString);
    function Get_FixLeg(index: Smallint): WideString;
    procedure Set_FixLeg(index: Smallint; const Value: WideString);
    function Get_YLeg(index: Smallint): WideString;
    procedure Set_YLeg(index: Smallint; const Value: WideString);
    function Get_KeySer(index: Smallint): WideString;
    procedure Set_KeySer(index: Smallint; const Value: WideString);
    function Get_StatusText(index: Smallint): WideString;
    procedure Set_StatusText(index: Smallint; const Value: WideString);
    function Get_RGBFont(index: Smallint): TColor;
    procedure Set_RGBFont(index: Smallint; Value: TColor);
    function Get_HFont(index: Smallint): Smallint;
    procedure Set_HFont(index: Smallint; Value: Smallint);
    function Get_ItemWidth(index: Smallint): Smallint;
    procedure Set_ItemWidth(index: Smallint; Value: Smallint);
    function Get_ItemStyle(index: Smallint): Smallint;
    procedure Set_ItemStyle(index: Smallint; Value: Smallint);
    function Get_ItemColor(index: Smallint): TColor;
    procedure Set_ItemColor(index: Smallint; Value: TColor);
    function Get_DecimalsNum(index: Smallint): Smallint;
    procedure Set_DecimalsNum(index: Smallint; Value: Smallint);
  protected
    procedure InitControlData; override;
    procedure InitControlInterface(const Obj: IUnknown); override;
  public
    function OpenDataEx(nType: Smallint; n1, n2: Integer): Integer;
    function CloseData(nType: Smallint): WordBool;
    function DblClk(nType: Smallint; lExtra: Integer): Integer;
    function RigClk(nType: Smallint; lExtra: Integer): Integer;
    function Status(nItems: Smallint; lpStatus: Integer): Integer;
    function ShowDialog(nDialog: Smallint; lExtra: Integer): Integer;
    function PrintIt: Integer;
    function Scroll(wParam, lParam: Integer): Integer;
    function SetStatusItem(index: Smallint; bText: WordBool; nID: Smallint; bFrame: WordBool; nWidth, nMin, nDesp: Smallint; dwStyle: Integer): Integer;
    function Paint(hDC: Integer; nLeft, nTop, nRight, nBottom, wAction: Smallint; lps: Integer): Integer;
    function SetStripe(index: Smallint; dMin, dMax: Double; rgb: TColor): Integer;
    function Language(const sResource: WideString): Integer;
    function ExportFile(const lpszNewValue: WideString): Integer;
    function ImportFile(const lpszNewValue: WideString): Integer;
    function WriteTemplate(const lpszNewValue: WideString): Integer;
    function ReadTemplate(const lpszNewValue: WideString): Integer;
    function CopyData: Integer;
    function CopyBitmap: Integer;
    procedure Refresh;
    procedure AboutBox;
    property ControlInterface: _DChartfx read FIntf;
    property Value[index: Smallint]: Double read Get_Value write Set_Value;
    property XValue[index: Smallint]: Double read Get_XValue write Set_XValue;
    property IniValue[index: Smallint]: Double read Get_IniValue write Set_IniValue;
    property Const_[index: Smallint]: Double read Get_Const_ write Set_Const_;
    property Color[index: Smallint]: TColor read Get_Color write Set_Color;
    property BkColor[index: Smallint]: TColor read Get_BkColor write Set_BkColor;
    property Adm[index: Smallint]: Double read Get_Adm write Set_Adm;
    property Pattern[index: Smallint]: Smallint read Get_Pattern write Set_Pattern;
    property Fonts[index: Smallint]: Integer read Get_Fonts write Set_Fonts;
    property Title[index: Smallint]: WideString read Get_Title write Set_Title;
    property Legend[index: Smallint]: WideString read Get_Legend write Set_Legend;
    property SerLeg[index: Smallint]: WideString read Get_SerLeg write Set_SerLeg;
    property KeyLeg[index: Smallint]: WideString read Get_KeyLeg write Set_KeyLeg;
    property FixLeg[index: Smallint]: WideString read Get_FixLeg write Set_FixLeg;
    property YLeg[index: Smallint]: WideString read Get_YLeg write Set_YLeg;
    property KeySer[index: Smallint]: WideString read Get_KeySer write Set_KeySer;
    property StatusText[index: Smallint]: WideString read Get_StatusText write Set_StatusText;
    property RGBFont[index: Smallint]: TColor read Get_RGBFont write Set_RGBFont;
    property HFont[index: Smallint]: Smallint read Get_HFont write Set_HFont;
    property ItemWidth[index: Smallint]: Smallint read Get_ItemWidth write Set_ItemWidth;
    property ItemStyle[index: Smallint]: Smallint read Get_ItemStyle write Set_ItemStyle;
    property ItemColor[index: Smallint]: TColor read Get_ItemColor write Set_ItemColor;
    property DecimalsNum[index: Smallint]: Smallint read Get_DecimalsNum write Set_DecimalsNum;
  published
    property TabStop;
    property Align;
    property DragCursor;
    property DragMode;
    property ParentShowHint;
    property PopupMenu;
    property ShowHint;
    property TabOrder;
    property Visible;
    property OnDragDrop;
    property OnDragOver;
    property OnEndDrag;
    property OnEnter;
    property OnExit;
    property OnStartDrag;
    property DesignDraw: Smallint index 4 read GetSmallintProp write SetSmallintProp stored False;
    property ThisSerie: Smallint index 1 read GetSmallintProp write SetSmallintProp stored False;
    property ThisPoint: Smallint index 2 read GetSmallintProp write SetSmallintProp stored False;
    property AutoInvalidate: WordBool index 3 read GetWordBoolProp write SetWordBoolProp stored False;
    property Type_: Integer index 5 read GetIntegerProp write SetIntegerProp stored False;
    property Style: Integer index 6 read GetIntegerProp write SetIntegerProp stored False;
    property NSeries: Smallint index 7 read GetSmallintProp write SetSmallintProp stored False;
    property NValues: Smallint index 8 read GetSmallintProp write SetSmallintProp stored False;
    property ThisColor: TColor index 9 read GetTColorProp write SetTColorProp stored False;
    property ThisBkColor: TColor index 10 read GetTColorProp write SetTColorProp stored False;
    property LeftGap: Smallint index 11 read GetSmallintProp write SetSmallintProp stored False;
    property RightGap: Smallint index 12 read GetSmallintProp write SetSmallintProp stored False;
    property TopGap: Smallint index 13 read GetSmallintProp write SetSmallintProp stored False;
    property BottomGap: Smallint index 14 read GetSmallintProp write SetSmallintProp stored False;
    property Decimals: Smallint index 15 read GetSmallintProp write SetSmallintProp stored False;
    property PointType: Smallint index 16 read GetSmallintProp write SetSmallintProp stored False;
    property Scheme: Smallint index 17 read GetSmallintProp write SetSmallintProp stored False;
    property Stacked: Smallint index 18 read GetSmallintProp write SetSmallintProp stored False;
    property Grid: Smallint index 19 read GetSmallintProp write SetSmallintProp stored False;
    property WallWidth: Smallint index 20 read GetSmallintProp write SetSmallintProp stored False;
    property BarHorzGap: Smallint index 21 read GetSmallintProp write SetSmallintProp stored False;
    property View3D: WordBool index 22 read GetWordBoolProp write SetWordBoolProp stored False;
    property Angles3D: Integer index 23 read GetIntegerProp write SetIntegerProp stored False;
    property PixFactor: Smallint index 24 read GetSmallintProp write SetSmallintProp stored False;
    property LineWidth: Smallint index 25 read GetSmallintProp write SetSmallintProp stored False;
    property LineStyle: Smallint index 26 read GetSmallintProp write SetSmallintProp stored False;
    property LineColor: TColor index 27 read GetTColorProp write SetTColorProp stored False;
    property LineBkColor: TColor index 28 read GetTColorProp write SetTColorProp stored False;
    property FixedWidth: Smallint index 29 read GetSmallintProp write SetSmallintProp stored False;
    property FixedStyle: Smallint index 30 read GetSmallintProp write SetSmallintProp stored False;
    property FixedColor: TColor index 31 read GetTColorProp write SetTColorProp stored False;
    property FixedBkColor: TColor index 32 read GetTColorProp write SetTColorProp stored False;
    property FixedGap: Smallint index 33 read GetSmallintProp write SetSmallintProp stored False;
    property RGBBarHorz: TColor index 34 read GetTColorProp write SetTColorProp stored False;
    property RGBBk: TColor index 35 read GetTColorProp write SetTColorProp stored False;
    property RGB2DBk: TColor index 36 read GetTColorProp write SetTColorProp stored False;
    property RGB3DBk: TColor index 37 read GetTColorProp write SetTColorProp stored False;
    property ShowStatus: WordBool index 38 read GetWordBoolProp write SetWordBoolProp stored False;
    property HText: WideString index 39 read GetWideStringProp write SetWideStringProp stored False;
    property ChartStatus: Smallint index 40 read GetSmallintProp write SetSmallintProp stored False;
    property Edit: Smallint index 41 read GetSmallintProp write SetSmallintProp stored False;
    property ChartType: Smallint index 42 read GetSmallintProp write SetSmallintProp stored False;
    property Chart3D: WordBool index 43 read GetWordBoolProp write SetWordBoolProp stored False;
    property ToolBar: WordBool index 44 read GetWordBoolProp write SetWordBoolProp stored False;
    property PaletteBar: WordBool index 45 read GetWordBoolProp write SetWordBoolProp stored False;
    property PatternBar: WordBool index 46 read GetWordBoolProp write SetWordBoolProp stored False;
    property CustTool: Integer index 47 read GetIntegerProp write SetIntegerProp stored False;
    property ReturnValue: Integer index 48 read GetIntegerProp write SetIntegerProp stored False;
    property AutoIncrement: WordBool index 49 read GetWordBoolProp write SetWordBoolProp stored False;
    property ThisValue: Double index 50 read GetDoubleProp write SetDoubleProp stored False;
    property VertGridGap: Smallint index 51 read GetSmallintProp write SetSmallintProp stored False;
    property XLegType: Smallint index 52 read GetSmallintProp write SetSmallintProp stored False;
    property ConstType: Smallint index 53 read GetSmallintProp write SetSmallintProp stored False;
    property LeftFont: TFont index 54 read GetTFontProp write SetTFontProp stored False;
    property RightFont: TFont index 55 read GetTFontProp write SetTFontProp stored False;
    property TopFont: TFont index 56 read GetTFontProp write SetTFontProp stored False;
    property BottomFont: TFont index 57 read GetTFontProp write SetTFontProp stored False;
    property XLegFont: TFont index 58 read GetTFontProp write SetTFontProp stored False;
    property YLegFont: TFont index 59 read GetTFontProp write SetTFontProp stored False;
    property FixedFont: TFont index 60 read GetTFontProp write SetTFontProp stored False;
    property LegendFont: TFont index 61 read GetTFontProp write SetTFontProp stored False;
    property LegendWidth: Smallint index 62 read GetSmallintProp write SetSmallintProp stored False;
    property Enabled: WordBool index -514 read GetWordBoolProp write SetWordBoolProp stored False;
    property hWnd: OLE_HANDLE read Get_hWnd write Set_hWnd stored False;
    property BorderStyle: Smallint index -504 read GetSmallintProp write SetSmallintProp stored False;
    property hCtlWnd: Integer index 63 read GetIntegerProp write SetIntegerProp stored False;
    property OnLButtonDblClk: TChartfxLButtonDblClk read FOnLButtonDblClk write FOnLButtonDblClk;
    property OnRButtonDown: TChartfxRButtonDown read FOnRButtonDown write FOnRButtonDown;
    property OnChangeValue: TChartfxChangeValue read FOnChangeValue write FOnChangeValue;
    property OnChangeString: TChartfxChangeString read FOnChangeString write FOnChangeString;
    property OnChangeColor: TChartfxChangeColor read FOnChangeColor write FOnChangeColor;
    property OnDestroy: TNotifyEvent read FOnDestroy write FOnDestroy;
    property OnReadFile: TNotifyEvent read FOnReadFile write FOnReadFile;
    property OnChangePalette: TChartfxChangePalette read FOnChangePalette write FOnChangePalette;
    property OnChangeFont: TChartfxChangeFont read FOnChangeFont write FOnChangeFont;
    property OnReadTemplate: TNotifyEvent read FOnReadTemplate write FOnReadTemplate;
    property OnChangePattern: TChartfxChangePattern read FOnChangePattern write FOnChangePattern;
    property OnChangePattPal: TChartfxChangePattPal read FOnChangePattPal write FOnChangePattPal;
    property OnMenu: TChartfxMenu read FOnMenu write FOnMenu;
    property OnChangeType: TChartfxChangeType read FOnChangeType write FOnChangeType;
    property OnUserScroll: TChartfxUserScroll read FOnUserScroll write FOnUserScroll;
    property OnGetLegend: TChartfxGetLegend read FOnGetLegend write FOnGetLegend;
  end;

procedure Register;

implementation

uses ComObj;

procedure TChartfx.InitControlData;
const
  CEventDispIDs: array[0..15] of Integer = (
    $00000001, $00000002, $00000003, $00000004, $00000005, $00000006,
    $00000007, $00000008, $00000009, $0000000A, $0000000B, $0000000C,
    $0000000D, $0000000E, $0000000F, $00000010);
  CLicenseKey: array[0..71] of Word = (
    $0043, $0068, $0061, $0072, $0074, $0020, $0046, $0058, $0020, $0032,
    $002E, $0030, $0020, $004F, $0043, $0058, $0033, $0032, $0020, $0028,
    $0033, $0032, $0020, $0042, $0069, $0074, $0073, $0029, $002E, $0020,
    $0043, $006F, $0070, $0079, $0072, $0069, $0067, $0068, $0074, $0020,
    $0028, $0063, $0029, $0020, $0031, $0039, $0039, $0034, $0020, $0053,
    $006F, $0066, $0074, $0077, $0061, $0072, $0065, $0020, $0046, $0058,
    $002C, $0020, $0049, $006E, $0063, $002E, $002D, $0031, $0039, $0039,
    $0035, $0000);
  CTFontIDs: array [0..7] of Integer = (
    $00000036, $00000037, $00000038, $00000039, $0000003A, $0000003B,
    $0000003C, $0000003D);
  CControlData: TControlData = (
    ClassID: '{8996B0A1-D7BE-101B-8650-00AA003A5593}';
    EventIID: '{2DC488B1-D891-101B-8652-00AA003A5593}';
    EventCount: 16;
    EventDispIDs: @CEventDispIDs;
    LicenseKey: @CLicenseKey;
    Flags: $00000008;
    Version: 300;
    FontCount: 8;
    FontIDs: @CTFontIDs);
begin
  ControlData := @CControlData;
end;

procedure TChartfx.InitControlInterface(const Obj: IUnknown);
begin
  FIntf := Obj as _DChartfx;
end;

function TChartfx.OpenDataEx(nType: Smallint; n1, n2: Integer): Integer;
begin
  Result := ControlInterface.OpenDataEx(nType, n1, n2);
end;

function TChartfx.CloseData(nType: Smallint): WordBool;
begin
  Result := ControlInterface.CloseData(nType);
end;

function TChartfx.DblClk(nType: Smallint; lExtra: Integer): Integer;
begin
  Result := ControlInterface.DblClk(nType, lExtra);
end;

function TChartfx.RigClk(nType: Smallint; lExtra: Integer): Integer;
begin
  Result := ControlInterface.RigClk(nType, lExtra);
end;

function TChartfx.Status(nItems: Smallint; lpStatus: Integer): Integer;
begin
  Result := ControlInterface.Status(nItems, lpStatus);
end;

function TChartfx.ShowDialog(nDialog: Smallint; lExtra: Integer): Integer;
begin
  Result := ControlInterface.ShowDialog(nDialog, lExtra);
end;

function TChartfx.PrintIt: Integer;
begin
  Result := ControlInterface.PrintIt;
end;

function TChartfx.Scroll(wParam, lParam: Integer): Integer;
begin
  Result := ControlInterface.Scroll(wParam, lParam);
end;

function TChartfx.SetStatusItem(index: Smallint; bText: WordBool; nID: Smallint; bFrame: WordBool; nWidth, nMin, nDesp: Smallint; dwStyle: Integer): Integer;
begin
  Result := ControlInterface.SetStatusItem(index, bText, nID, bFrame, nWidth, nMin, nDesp, dwStyle);
end;

function TChartfx.Paint(hDC: Integer; nLeft, nTop, nRight, nBottom, wAction: Smallint; lps: Integer): Integer;
begin
  Result := ControlInterface.Paint(hDC, nLeft, nTop, nRight, nBottom, wAction, lps);
end;

function TChartfx.SetStripe(index: Smallint; dMin, dMax: Double; rgb: TColor): Integer;
begin
  Result := ControlInterface.SetStripe(index, dMin, dMax, rgb);
end;

function TChartfx.Language(const sResource: WideString): Integer;
begin
  Result := ControlInterface.Language(sResource);
end;

function TChartfx.ExportFile(const lpszNewValue: WideString): Integer;
begin
  Result := ControlInterface.ExportFile(lpszNewValue);
end;

function TChartfx.ImportFile(const lpszNewValue: WideString): Integer;
begin
  Result := ControlInterface.ImportFile(lpszNewValue);
end;

function TChartfx.WriteTemplate(const lpszNewValue: WideString): Integer;
begin
  Result := ControlInterface.WriteTemplate(lpszNewValue);
end;

function TChartfx.ReadTemplate(const lpszNewValue: WideString): Integer;
begin
  Result := ControlInterface.ReadTemplate(lpszNewValue);
end;

function TChartfx.CopyData: Integer;
begin
  Result := ControlInterface.CopyData;
end;

function TChartfx.CopyBitmap: Integer;
begin
  Result := ControlInterface.CopyBitmap;
end;

procedure TChartfx.Refresh;
begin
  ControlInterface.Refresh;
end;

procedure TChartfx.AboutBox;
begin
  ControlInterface.AboutBox;
end;

function TChartfx.Get_hWnd: OLE_HANDLE;
begin
  Result := ControlInterface.hWnd;
end;

procedure TChartfx.Set_hWnd(var Value: OLE_HANDLE);
begin
  ControlInterface.hWnd := Value;
end;

function TChartfx.Get_Value(index: Smallint): Double;
begin
  Result := ControlInterface.Value[index];
end;

procedure TChartfx.Set_Value(index: Smallint; Value: Double);
begin
  ControlInterface.Value[index] := Value;
end;

function TChartfx.Get_XValue(index: Smallint): Double;
begin
  Result := ControlInterface.XValue[index];
end;

procedure TChartfx.Set_XValue(index: Smallint; Value: Double);
begin
  ControlInterface.XValue[index] := Value;
end;

function TChartfx.Get_IniValue(index: Smallint): Double;
begin
  Result := ControlInterface.IniValue[index];
end;

procedure TChartfx.Set_IniValue(index: Smallint; Value: Double);
begin
  ControlInterface.IniValue[index] := Value;
end;

function TChartfx.Get_Const_(index: Smallint): Double;
begin
  Result := ControlInterface.Const_[index];
end;

procedure TChartfx.Set_Const_(index: Smallint; Value: Double);
begin
  ControlInterface.Const_[index] := Value;
end;

function TChartfx.Get_Color(index: Smallint): TColor;
begin
  Result := ControlInterface.Color[index];
end;

procedure TChartfx.Set_Color(index: Smallint; Value: TColor);
begin
  ControlInterface.Color[index] := Value;
end;

function TChartfx.Get_BkColor(index: Smallint): TColor;
begin
  Result := ControlInterface.BkColor[index];
end;

procedure TChartfx.Set_BkColor(index: Smallint; Value: TColor);
begin
  ControlInterface.BkColor[index] := Value;
end;

function TChartfx.Get_Adm(index: Smallint): Double;
begin
  Result := ControlInterface.Adm[index];
end;

procedure TChartfx.Set_Adm(index: Smallint; Value: Double);
begin
  ControlInterface.Adm[index] := Value;
end;

function TChartfx.Get_Pattern(index: Smallint): Smallint;
begin
  Result := ControlInterface.Pattern[index];
end;

procedure TChartfx.Set_Pattern(index: Smallint; Value: Smallint);
begin
  ControlInterface.Pattern[index] := Value;
end;

function TChartfx.Get_Fonts(index: Smallint): Integer;
begin
  Result := ControlInterface.Fonts[index];
end;

procedure TChartfx.Set_Fonts(index: Smallint; Value: Integer);
begin
  ControlInterface.Fonts[index] := Value;
end;

function TChartfx.Get_Title(index: Smallint): WideString;
begin
  Result := ControlInterface.Title[index];
end;

procedure TChartfx.Set_Title(index: Smallint; const Value: WideString);
begin
  ControlInterface.Title[index] := Value;
end;

function TChartfx.Get_Legend(index: Smallint): WideString;
begin
  Result := ControlInterface.Legend[index];
end;

procedure TChartfx.Set_Legend(index: Smallint; const Value: WideString);
begin
  ControlInterface.Legend[index] := Value;
end;

function TChartfx.Get_SerLeg(index: Smallint): WideString;
begin
  Result := ControlInterface.SerLeg[index];
end;

procedure TChartfx.Set_SerLeg(index: Smallint; const Value: WideString);
begin
  ControlInterface.SerLeg[index] := Value;
end;

function TChartfx.Get_KeyLeg(index: Smallint): WideString;
begin
  Result := ControlInterface.KeyLeg[index];
end;

procedure TChartfx.Set_KeyLeg(index: Smallint; const Value: WideString);
begin
  ControlInterface.KeyLeg[index] := Value;
end;

function TChartfx.Get_FixLeg(index: Smallint): WideString;
begin
  Result := ControlInterface.FixLeg[index];
end;

procedure TChartfx.Set_FixLeg(index: Smallint; const Value: WideString);
begin
  ControlInterface.FixLeg[index] := Value;
end;

function TChartfx.Get_YLeg(index: Smallint): WideString;
begin
  Result := ControlInterface.YLeg[index];
end;

procedure TChartfx.Set_YLeg(index: Smallint; const Value: WideString);
begin
  ControlInterface.YLeg[index] := Value;
end;

function TChartfx.Get_KeySer(index: Smallint): WideString;
begin
  Result := ControlInterface.KeySer[index];
end;

procedure TChartfx.Set_KeySer(index: Smallint; const Value: WideString);
begin
  ControlInterface.KeySer[index] := Value;
end;

function TChartfx.Get_StatusText(index: Smallint): WideString;
begin
  Result := ControlInterface.StatusText[index];
end;

procedure TChartfx.Set_StatusText(index: Smallint; const Value: WideString);
begin
  ControlInterface.StatusText[index] := Value;
end;

function TChartfx.Get_RGBFont(index: Smallint): TColor;
begin
  Result := ControlInterface.RGBFont[index];
end;

procedure TChartfx.Set_RGBFont(index: Smallint; Value: TColor);
begin
  ControlInterface.RGBFont[index] := Value;
end;

function TChartfx.Get_HFont(index: Smallint): Smallint;
begin
  Result := ControlInterface.HFont[index];
end;

procedure TChartfx.Set_HFont(index: Smallint; Value: Smallint);
begin
  ControlInterface.HFont[index] := Value;
end;

function TChartfx.Get_ItemWidth(index: Smallint): Smallint;
begin
  Result := ControlInterface.ItemWidth[index];
end;

procedure TChartfx.Set_ItemWidth(index: Smallint; Value: Smallint);
begin
  ControlInterface.ItemWidth[index] := Value;
end;

function TChartfx.Get_ItemStyle(index: Smallint): Smallint;
begin
  Result := ControlInterface.ItemStyle[index];
end;

procedure TChartfx.Set_ItemStyle(index: Smallint; Value: Smallint);
begin
  ControlInterface.ItemStyle[index] := Value;
end;

function TChartfx.Get_ItemColor(index: Smallint): TColor;
begin
  Result := ControlInterface.ItemColor[index];
end;

procedure TChartfx.Set_ItemColor(index: Smallint; Value: TColor);
begin
  ControlInterface.ItemColor[index] := Value;
end;

function TChartfx.Get_DecimalsNum(index: Smallint): Smallint;
begin
  Result := ControlInterface.DecimalsNum[index];
end;

procedure TChartfx.Set_DecimalsNum(index: Smallint; Value: Smallint);
begin
  ControlInterface.DecimalsNum[index] := Value;
end;


procedure Register;
begin
  RegisterComponents('ActiveX', [TChartfx]);  { do not localize }
end;

end.
