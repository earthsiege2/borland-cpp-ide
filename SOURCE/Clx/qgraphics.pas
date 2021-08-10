{ *************************************************************************** }
{                                                                             }
{ Delphi and Kylix Cross-Platform Visual Component Library                    }
{                                                                             }
{ Copyright (c) 2000, 2001 Borland Software Corporation                       }
{                                                                             }
{ *************************************************************************** }


unit QGraphics;

{$P+,S-,W-,R-,T-,X+,H+}

interface

uses
{$IFDEF LINUX}
  Libc,
{$ENDIF}
{$IFDEF MSWINDOWS}
  Windows,
{$ENDIF}
  Classes, Types, QTypes, SysUtils, Qt;

const
  Version = 1;

{ TColor }

type
  PColor = ^TColor;
  TColor = -$7FFFFFFF-1..$7FFFFFFF;
  TColorRef = Cardinal;
  {$NODEFINE TColor}

  (*$HPPEMIT 'namespace Qgraphics'*)
  (*$HPPEMIT '{'*)
  (*$HPPEMIT '  enum TColor {clMin=-0x7fffffff-1, clMax=0x7fffffff};'*)
  (*$HPPEMIT '}'*)


const
  { Raw rgb values }
  clBlack = TColor($000000);
  clMaroon = TColor($000080);
  clGreen = TColor($008000);
  clOlive = TColor($008080);
  clNavy = TColor($800000);
  clPurple = TColor($800080);
  clTeal = TColor($808000);
  clGray = TColor($808080);
  clSilver = TColor($C0C0C0);
  clRed = TColor($0000FF);
  clLime = TColor($00FF00);
  clYellow = TColor($00FFFF);
  clBlue = TColor($FF0000);
  clFuchsia = TColor($FF00FF);
  clAqua = TColor($FFFF00);
  clLtGray = TColor($C0C0C0);
  clDkGray = TColor($808080);
  clWhite = TColor($FFFFFF);
  clNone = TColor($1FFFFFFF);
  clDefault = TColor($20000000);

  { Base, mapped, pseudo, rgb values }
  clForeground = TColor(-1);
  clButton = TColor(-2);
  clLight = TColor(-3);
  clMidlight = TColor(-4);
  clDark = TColor(-5);
  clMid = TColor(-6);
  clText = TColor(-7);
  clBrightText = TColor(-8);
  clButtonText = TColor(-9);
  clBase = TColor(-10);
  clBackground = TColor(-11);
  clShadow = TColor(-12);
  clHighlight = TColor(-13);
  clHighlightedText = TColor(-14);

  { Mapped role offsets }
  cloNormal = 32;
  cloDisabled = 64;
  cloActive = 96;

  { Normal, mapped, pseudo, rgb values }
  clNormalForeground = TColor(clForeground - cloNormal);
  clNormalButton = TColor(clButton - cloNormal);
  clNormalLight = TColor(clLight - cloNormal);
  clNormalMidlight = TColor(clMidlight - cloNormal);
  clNormalDark = TColor(clDark - cloNormal);
  clNormalMid = TColor(clMid - cloNormal);
  clNormalText = TColor(clText - cloNormal);
  clNormalBrightText = TColor(clBrightText - cloNormal);
  clNormalButtonText = TColor(clButtonText - cloNormal);
  clNormalBase = TColor(clBase - cloNormal);
  clNormalBackground = TColor(clBackground - cloNormal);
  clNormalShadow = TColor(clShadow - cloNormal);
  clNormalHighlight = TColor(clHighlight - cloNormal);
  clNormalHighlightedText = TColor(clHighlightedText - cloNormal);

  { Disabled, mapped, pseudo, rgb values }
  clDisabledForeground = TColor(clForeground - cloDisabled);
  clDisabledButton = TColor(clButton - cloDisabled);
  clDisabledLight = TColor(clLight - cloDisabled);
  clDisabledMidlight = TColor(clMidlight - cloDisabled);
  clDisabledDark = TColor(clDark - cloDisabled);
  clDisabledMid = TColor(clMid - cloDisabled);
  clDisabledText = TColor(clText - cloDisabled);
  clDisabledBrightText = TColor(clBrightText - cloDisabled);
  clDisabledButtonText = TColor(clButtonText - cloDisabled);
  clDisabledBase = TColor(clBase - cloDisabled);
  clDisabledBackground = TColor(clBackground - cloDisabled);
  clDisabledShadow = TColor(clShadow - cloDisabled);
  clDisabledHighlight = TColor(clHighlight - cloDisabled);
  clDisabledHighlightedText = TColor(clHighlightedText - cloDisabled);

  { Active, mapped, pseudo, rgb values }
  clActiveForeground = TColor(clForeground - cloActive);
  clActiveButton = TColor(clButton - cloActive);
  clActiveLight = TColor(clLight - cloActive);
  clActiveMidlight = TColor(clMidlight - cloActive);
  clActiveDark = TColor(clDark - cloActive);
  clActiveMid = TColor(clMid - cloActive);
  clActiveText = TColor(clText - cloActive);
  clActiveBrightText = TColor(clBrightText - cloActive);
  clActiveButtonText = TColor(clButtonText - cloActive);
  clActiveBase = TColor(clBase - cloActive);
  clActiveBackground = TColor(clBackground - cloActive);
  clActiveShadow = TColor(clShadow - cloActive);
  clActiveHighlight = TColor(clHighlight - cloActive);
  clActiveHighlightedText = TColor(clHighlightedText - cloActive);

  clFirstSpecialColor = clActiveHighlightedText;

  { Compatiblity colors }
  clScrollBar = clButton;
  clActiveCaption = clActiveHighlightedText;
  clInactiveCaption = clDisabledHighlightedText;
  clMenu = clMid;
  clWindow = clBase;
  clWindowFrame = clHighlight;
  clMenuText = clButtonText;
  clWindowText = clText;
  clCaptionText = clHighlightedText;
  clActiveBorder = clActiveHighlight;
  clInactiveBorder = clDisabledHighlight;
  clAppWorkSpace = clMid;
  clBtnFace = clButton;
  clBtnShadow = clDark;
  clGrayText = clLight;
  clBtnText = clButtonText;
  clInactiveCaptionText = clDisabledHighlightedText;
  clBtnHighlight = clActiveLight;
  cl3DDkShadow = clMid;
  cl3DLight = clMidLight;
  clInfoText = clText;
  clInfoBk = TColor($E1FFFF);
  clHighlightText = clHighlightedText;

{$IFDEF MSWINDOWS}
  clMask = clWhite;
  clDontMask = clBlack;
{$ENDIF}
{$IFDEF LINUX}
  clMask = clBlack;
  clDontMask = clWhite;
{$ENDIF}
  DrawStage_Pre = 0;
  DrawStage_Post = 1;
  DrawStage_DefaultDraw = 2;

{$IFDEF LINUX}
  RT_BITMAP = PChar(2);
{$ENDIF}

type
  TMappedColor = clActiveHighlightedText..clNormalForeground;
  EInvalidGraphic = class(Exception);
  EInvalidGraphicOperation = class(Exception);
  EInvalidHandleException = class(Exception);

{ TGraphicsObject }

type
  TGraphicsObject = class(TPersistent)
  private
    FOnChange: TNotifyEvent;
    FChangeDisabled: Integer;
    FChangePending: Boolean;
  protected
    procedure Changed; virtual;
    procedure Lock;
    procedure Unlock;
    procedure DisableChanged;
    procedure EnableChanged;
  public
    property OnChange: TNotifyEvent read FOnChange write FOnChange;
  end;

{ TFont }

type
  TFontPitch = (fpDefault, fpVariable, fpFixed);
  TFontName = type string;
  TFontStyle = (fsBold, fsItalic, fsUnderline, fsStrikeOut);
  TFontStyles = set of TFontStyle;
  {$EXTERNALSYM TFontCharSet}
  TFontCharSet = ( fcsLatin1, fcsAnyCharSet, fcsLatin2, fcsLatin3, fcsLatin4,
    fcsISO_8859_5, fcsISO_8859_6, fcsISO_8859_7, fcsISO_8859_8, fcsLatin5,
    fcsLatin6, fcsISO_8859_11, fcsISO_8859_12, fcsLatin7, fcsLatin8, fcsLatin9,
    fcsKOI8R, fcsSet_Ja, fcsSet_Ko, fcsSet_Th_TH, fcsSet_Zh, fcsSet_Zh_TW,
    fcsUnicode, fcsDefaultCharSet,
    { Windows compatiblity values }
    ANSI_CHARSET, DEFAULT_CHARSET, SYMBOL_CHARSET, MAC_CHARSET,
    SHIFTJIS_CHARSET, HANGEUL_CHARSET, JOHAB_CHARSET, GB2312_CHARSET,
    CHINESEBIG5_CHARSET,  GREEK_CHARSET, TURKISH_CHARSET, HEBREW_CHARSET,
    ARABIC_CHARSET, BALTIC_CHARSET, RUSSIAN_CHARSET, THAI_CHARSET,
    EASTEUROPE_CHARSET, OEM_CHARSET);
  (*$HPPEMIT 'enum TFontCharSet { fcsLatin1, fcsAnyCharSet, fcsLatin2, fcsLatin3, fcsLatin4, fcsISO_8859_5,' *)
  (*$HPPEMIT 'fcsISO_8859_6, fcsISO_8859_7, fcsISO_8859_8, fcsLatin5, fcsLatin6, fcsISO_8859_11, fcsISO_8859_12,' *)
  (*$HPPEMIT 'fcsLatin7, fcsLatin8, fcsLatin9, fcsKOI8R, fcsSet_Ja, fcsSet_Ko, fcsSet_Th_TH, fcsSet_Zh, fcsSet_Zh_TW,' *)
  (*$HPPEMIT 'fcsUnicode, fcsDefaultCharSet, fcsANSI_CHARSET, fcsDEFAULT_CHARSET, fcsSYMBOL_CHARSET, fcsMAC_CHARSET,' *)
  (*$HPPEMIT 'fcsSHIFTJIS_CHARSET, fcsHANGEUL_CHARSET, fcsJOHAB_CHARSET, fcsGB2312_CHARSET, fcsCHINESEBIG5_CHARSET,' *)
  (*$HPPEMIT 'fcsGREEK_CHARSET, fcsTURKISH_CHARSET, fcsHEBREW_CHARSET, fcsARABIC_CHARSET, fcsBALTIC_CHARSET,' *)
  (*$HPPEMIT 'fcsRUSSIAN_CHARSET, fcsTHAI_CHARSET, fcsEASTEUROPE_CHARSET, fcsOEM_CHARSET };' *)

const
  { TFontCharset Aliases }
  fcsISO_8859_1 = fcsLatin1;
  fcsISO_8859_2 = fcsLatin2;
  fcsISO_8859_3 = fcsLatin3;
  fcsISO_8859_4 = fcsLatin4;
  fcsISO_8859_9 = fcsLatin5;
  fcsISO_8859_10 = fcsLatin6;
  fcsISO_8859_13 = fcsLatin7;
  fcsISO_8859_14 = fcsLatin8;
  fcsISO_8859_15 = fcsLatin9;
  fcsSet_1 = fcsSet_Ja;
  fcsSet_N = fcsSet_Zh_TW;

const
  { Standard font weights }
  fwLight = Ord(QFontWeight_Light);
  fwNormal = Ord(QFontWeight_Normal);
  fwDemiBold = Ord(QFontWeight_DemiBold);
  fwBold = Ord(QFontWeight_Bold);
  fwBlack = Ord(QFontWeight_Black);

type
  TFontHint = (fhHelvetica, fhTimes, fhCourier, fhOldEnglish, fhSystem, fhAny);

const
  { Font hint aliases }
  fhSanSerif = fhHelvetica;
  fhSerif = fhTimes;
  fhTypeWriter = fhCourier;
  fhDecorative = fhOldEnglish;

type
  TFont = class(TGraphicsObject)
  private
    FPixelsPerInch: Integer;
    FColor: TColor;
    FHandle: QFontH;
    FFontPen: QPenH;
    FOriginalWeight: Integer;
    FOwned: Boolean;
    FCharSet: TFontCharSet;
    procedure FreeHandle;
    function GetHeight: Integer;
    function GetName: TFontName;
    function GetPitch: TFontPitch;
    function GetSize: Integer;
    function GetStyle: TFontStyles;
    function GetWeight: Integer;
    function IsWeightStored: Boolean;
    procedure SetCharSet(Value: TFontCharSet);
    procedure SetColor(const Value: TColor);
    procedure SetHandle(const Value: QFontH);
    procedure SetHeight(const Value: Integer);
    procedure SetName(const Value: TFontName);
    procedure SetPitch(const Value: TFontPitch);
    procedure SetSize(const Value: Integer);
    procedure SetStyle(const Value: TFontStyles);
    procedure SetWeight(const Value: Integer);
  public
    constructor Create; overload;
    constructor Create(AHandle: QFontH); overload;
    destructor Destroy; override;
    procedure Assign(Source: TPersistent); override;
    procedure OwnHandle;
    function ReleaseHandle: QFontH;
    property Handle: QFontH read FHandle write SetHandle;
    property FontPen: QPenH read FFontPen;
    property PixelsPerInch: Integer read FPixelsPerInch write FPixelsPerInch;
  published
    property CharSet: TFontCharSet read FCharSet write SetCharSet default fcsDefaultCharSet; { library }
    property Color: TColor read FColor write SetColor;
    property Height: Integer read GetHeight write SetHeight;
    property Name: TFontName read GetName write SetName;
    property Pitch: TFontPitch read GetPitch write SetPitch default fpDefault;
    property Size: Integer read GetSize write SetSize stored False;
    property Style: TFontStyles read GetStyle write SetStyle;
    property Weight: Integer read GetWeight write SetWeight stored IsWeightStored; { library }
  end;

{ TPen }

type
  TPenStyle = (psSolid, psDash, psDot, psDashDot, psDashDotDot, psClear);
  TPenMode = (pmBlack, pmWhite, pmNop, pmNot, pmCopy, pmNotCopy,
    pmMergePenNot, pmMaskPenNot, pmMergeNotPen, pmMaskNotPen, pmMerge,
    pmNotMerge, pmMask, pmNotMask, pmXor, pmNotXor);

  TPen = class(TGraphicsObject)
  private
    FHandle: QPenH;
    FColor: TColor;
    FMode: TPenMode;
    FOwned: Boolean;
    function GetStyle: TPenStyle;
    function GetWidth: Integer;
    procedure SetColor(const Value: TColor);
    procedure SetHandle(const Value: QPenH);
    procedure SetMode(const Value: TPenMode);
    procedure SetStyle(const Value: TPenStyle);
    procedure SetWidth(const Value: Integer);
    procedure FreeHandle;
  public
    constructor Create; overload;
    constructor Create(AHandle: QPenH); overload;
    destructor Destroy; override;
    procedure Assign(Source: TPersistent); override;
    procedure OwnHandle;
    function ReleaseHandle: QPenH;
    property Handle: QPenH read FHandle write SetHandle;
  published
    property Color: TColor read FColor write SetColor default clBlack;
    property Mode: TPenMode read FMode write SetMode default pmCopy;
    property Style: TPenStyle read GetStyle write SetStyle default psSolid;
    property Width: Integer read GetWidth write SetWidth default 1;
  end;

{ TBrush }

type
  TBrushStyle = (bsSolid, bsClear, bsHorizontal, bsVertical,
    bsFDiagonal, bsBDiagonal, bsCross, bsDiagCross,
    bsDense1 {library}, bsDense2 {library}, bsDense3 {library},
    bsDense4 {library}, bsDense5 {library}, bsDense6 {library},
    bsDense7 {library});

  TGraphic = class;
  TBitmap = class;
  TIcon = class;

  TBrush = class(TGraphicsObject)
  private
    FHandle: QBrushH;
    FOwned: Boolean;
    FBitmap: TBitmap;
    FColor: TColor;
    procedure FreeHandle;
    function GetStyle: TBrushStyle;
    procedure SetBitmap(const Value: TBitmap);
    function GetBitmap: TBitmap;
    procedure SetColor(const Value: TColor);
    procedure SetHandle(const Value: QBrushH);
    procedure SetStyle(const Value: TBrushStyle);
  protected
    procedure BitmapChanged(Sender: TObject); virtual;
  public
    constructor Create; overload;
    constructor Create(AHandle: QBrushH); overload;
    destructor Destroy; override;
    procedure Assign(Source: TPersistent); override;
    procedure OwnHandle;
    function ReleaseHandle: QBrushH;
    property Bitmap: TBitmap read GetBitmap write SetBitmap; { library }
    property Handle: QBrushH read FHandle write SetHandle; { library }
  published
    property Color: TColor read FColor write SetColor default clWhite;
    property Style: TBrushStyle read GetStyle write SetStyle default bsSolid;
  end;

  TFontRecall = class(TRecall)
  public
    constructor Create(AFont: TFont);
  end;

  TPenRecall = class(TRecall)
  public
    constructor Create(APen: TPen);
  end;

  TBrushRecall = class(TRecall)
  public
    constructor Create(ABrush: TBrush);
  end;

{ TCanvas }

  TCopyMode = (cmBlackness, cmDstInvert, cmMergeCopy, cmMergePaint,
    cmNotSrcCopy, cmNotSrcErase, cmPatCopy, cmPatInvert, cmPatPaint,
    cmSrcAnd, cmSrcCopy, cmSrcErase, cmSrcInvert, cmSrcPaint, cmWhiteness,
    cmCreateMask);

  TCanvasStates = (csHandleValid, csFontValid, csPenValid, csBrushValid);
  TCanvasState = set of TCanvasStates;

  TTextAlign = (taTop, taBottom);

  TCanvas = class(TPersistent)
  private
    FLockCount: Integer;
    FStartCount: Integer;
    FFont: TFont;
    FPen: TPen;
    FBrush: TBrush;
    State: TCanvasState;
    FTextAlign: TTextAlign;
    FPenPos: TPoint;
    FLock: TRTLCriticalSection;
    FCopyMode: TCopyMode;
    FOnChange: TNotifyEvent;
    FOnChanging: TNotifyEvent;
    FClipRegion: QRegionH;
    FNeedsEnd: Boolean;
    procedure BrushChanged(Sender: TObject);
    procedure CreateBrush;
    procedure CreateFont;
    procedure CreatePen;
    procedure FontChanged(Sender: TObject);
    function GetClipRect: TRect;
    function GetHandle: QPainterH;
    function GetPenPos: TPoint;
    procedure PenChanged(Sender: TObject);
    procedure SetBrush(const Value: TBrush);
    procedure SetFont(const Value: TFont);
    procedure SetHandle(const Value: QPainterH);
    procedure SetPen(const Value: TPen);
    procedure SetPenPos(const Value: TPoint);
  protected
    FHandle: QPainterH;
    procedure BeginPainting; virtual;
    procedure Changing; virtual;
    procedure Changed; virtual;
    procedure CreateHandle; virtual;
    procedure RequiredState(ReqState: TCanvasState);
  public
    constructor Create;
    destructor Destroy; override;
    procedure Arc(X1, Y1, X2, Y2, X3, Y3, X4, Y4: Integer); overload;
    procedure Arc(X, Y, W, H, Angle, AngleLength: Integer); overload;
    procedure Chord(X1, Y1, X2, Y2, X3, Y3, X4, Y4: Integer); overload;
    procedure Chord(X, Y, W, H, Angle, AngleLength: Integer); overload;
    procedure CopyRect(const Dest: TRect; Canvas: TCanvas;
      const Source: TRect);
    procedure Draw(X, Y: Integer; Graphic: TGraphic);
    procedure DrawFocusRect(const Rect: TRect);
    procedure DrawPoint(X, Y: Integer); overload;
    procedure DrawPoint(const Point: TPoint); overload;
    procedure DrawPoints(const Points: array of TPoint);
    procedure Ellipse(X1, Y1, X2, Y2: Integer); overload;
    procedure Ellipse(const Rect: TRect); overload;
    procedure FillRect(const Rect: TRect);
    function GetClipRegion: QRegionH; { library }
    procedure LineTo(X, Y: Integer);
    procedure Lock;
    procedure MoveTo(X, Y: Integer);
    procedure Pie(X1, Y1, X2, Y2, X3, Y3, X4, Y4: Integer); overload;
    procedure Pie(X, Y, W, H, Angle, AngleLength: Integer); overload;
    procedure Polygon(const Points: array of TPoint; Winding: Boolean = False;
      StartIndex: Integer = 0; NumPts: Integer = -1);
    procedure Polyline(const Points: array of TPoint; StartIndex: Integer = 0;
      NumPts: Integer = -1);
    procedure PolyBezier(const Points: array of TPoint; StartIndex: Integer = 0);
    procedure PolyBezierTo(const Points: array of TPoint; StartIndex: Integer = 0);
    procedure Rectangle(X1, Y1, X2, Y2: Integer); overload;
    procedure Rectangle(const Rect: TRect); overload;
    procedure Refresh;
    function ReleaseHandle: QPainterH;
    procedure ResetClipRegion;
    procedure RoundRect(X1, Y1, X2, Y2, X3, Y3: Integer);
    procedure SetClipRect(const ARect: TRect);
    procedure Start(FreshState: Boolean = True);
    procedure Stop;
    procedure StretchDraw(const Rect: TRect; Graphic: TGraphic);
    procedure TextExtent(const Text: WideString; var Rect: TRect; const Flags: Integer = 0); overload;
    function TextExtent(const Text: WideString; const Flags: Integer = 0): TSize; overload;
    function TextHeight(const Text: WideString): Integer;
    procedure TextOut(X, Y: Integer; const Text: WideString);
    { TextRect() flags are Qt.AlignmentFlags constants }
    procedure TextRect(Rect: TRect; X, Y: Integer; const Text: WideString;
      TextFlags: Integer = 0);
    function TextWidth(const Text: WideString): Integer;
    procedure TiledDraw(const Rect: TRect; Graphic: TGraphic);
    function TryLock: Boolean;
    procedure Unlock;
    property ClipRect: TRect read GetClipRect;
    property Handle: QPainterH read GetHandle write SetHandle;
    property LockCount: Integer read FLockCount;
    property PenPos: TPoint read GetPenPos write SetPenPos;
    property StartCount: Integer read FStartCount;
    property OnChange: TNotifyEvent read FOnChange write FOnChange;
    property OnChanging: TNotifyEvent read FOnChanging write FOnChanging;
  published
    property Brush: TBrush read FBrush write SetBrush;
    property CopyMode: TCopyMode read FCopyMode write FCopyMode default cmSrcCopy;
    property Font: TFont read FFont write SetFont;
    property Pen: TPen read FPen write SetPen;
    property TextAlign: TTextAlign read FTextAlign write FTextAlign default taTop;
  end;

  { TProgressEvent is a generic progress notification event which may be
        used by TGraphic classes with computationally intensive (slow)
        operations, such as loading, storing, or transforming image data.
    Event params:
      Stage - Indicates whether this call to the OnProgress event is to
        prepare for, process, or clean up after a graphic operation.  If
        OnProgress is called at all, the first call for a graphic operation
        will be with Stage = psStarting, to allow the OnProgress event handler
        to allocate whatever resources it needs to process subsequent progress
        notifications.  After Stage = psStarting, you are guaranteed that
        OnProgress will be called again with Stage = psEnding to allow you
        to free those resources, even if the graphic operation is aborted by
        an exception.  Zero or more calls to OnProgress with Stage = psRunning
        may occur between the psStarting and psEnding calls.
      PercentDone - The ratio of work done to work remaining, on a scale of
        0 to 100.  Values may repeat or even regress (get smaller) in
        successive calls.  PercentDone is usually only a guess, and the
        guess may be dramatically altered as new information is discovered
        in decoding the image.
      RedrawNow - Indicates whether the graphic can be/should be redrawn
        immediately.  Useful for showing successive approximations of
        an image as data is available instead of waiting for all the data
        to arrive before drawing anything.  Since there is no message loop
        activity during graphic operations, you should call Update to force
        a control to be redrawn immediately in the OnProgress event handler.
        Redrawing a graphic when RedrawNow = False could corrupt the image
        and/or cause exceptions.
      Rect - Area of image that has changed and needs to be redrawn.
      Msg - Optional text describing in one or two words what the graphic
        class is currently working on.  Ex:  "Loading" "Storing"
        "Reducing colors".  The Msg string can also be empty.
        Msg strings should be resourced for translation,  should not
        contain trailing periods, and should be used only for
        display purposes.  (do not: if Msg = 'Loading' then...)
  }

  TProgressStage = (psStarting, psRunning, psEnding);
  TProgressEvent = procedure (Sender: TObject; Stage: TProgressStage;
    PercentDone: Byte; RedrawNow: Boolean; const R: TRect;
    const Msg: WideString) of object;

  { The TGraphic class is a abstract base class for dealing with graphic images
    such as metafile, bitmaps, icons, and other image formats.
      LoadFromFile - Read the graphic from the file system.  The old contents of
        the graphic are lost.  If the file is not of the right format, an
        exception will be generated.
      SaveToFile - Writes the graphic to disk in the file provided.
      LoadFromStream - Like LoadFromFile except source is a stream (e.g.
        TBlobStream).
      SaveToStream - stream analogue of SaveToFile.
      LoadFromClipboardFormat - Replaces the current image with the data
        provided.  If the TGraphic does not support that format it will generate
        an exception.
      SaveToClipboardFormats - Converts the image to a clipboard format.  If the
        image does not support being translated into a clipboard format it
        will generate an exception.
      Height - The native, unstretched, height of the graphic.
      Palette - Color palette of image.  Zero if graphic doesn't need/use palettes.
      Transparent - Image does not completely cover its rectangular area
      Width - The native, unstretched, width of the graphic.
      OnChange - Called whenever the graphic changes
      PaletteModified - Indicates in OnChange whether color palette has changed.
        Stays true until whoever's responsible for realizing this new palette
        (ex: TImage) sets it to False.
      OnProgress - Generic progress indicator event. Propagates out to TPicture
        and TImage OnProgress events.}

  TGraphicClass = class of TGraphic;

  TGraphic = class(TPersistent)
  private
    FOnChange: TNotifyEvent;
    FOnProgress: TProgressEvent;
    FModified: Boolean;
    FTransparent: Boolean;
    procedure SetModified(Value: Boolean);
  protected
    constructor Create; virtual;
    procedure Changed(Sender: TObject); virtual;
    procedure DefineProperties(Filer: TFiler); override;
    procedure Draw(ACanvas: TCanvas; const Rect: TRect); virtual; abstract;
    function Equals(Graphic: TGraphic): Boolean; virtual;
    function GetEmpty: Boolean; virtual; abstract;
    function GetHeight: Integer; virtual; abstract;
    function GetTransparent: Boolean; virtual;
    function GetWidth: Integer; virtual; abstract;
    procedure Progress(Sender: TObject; Stage: TProgressStage;
      PercentDone: Byte;  RedrawNow: Boolean; const R: TRect;
      const Msg: WideString); dynamic;
    procedure ReadData(Stream: TStream); virtual;
    procedure SetHeight(Value: Integer); virtual; abstract;
    procedure  SetTransparent(Value: Boolean); virtual;
    procedure SetWidth(Value: Integer); virtual; abstract;
    procedure TiledDraw(ACanvas: TCanvas; const Rect: TRect); virtual;
    procedure WriteData(Stream: TStream); virtual;
  public
    class function Assigns(Source: TGraphicClass): Boolean; virtual;
    class function AssignsTo(Dest: TGraphicClass): Boolean; virtual;
    procedure LoadFromMimeSource(MimeSource: TMimeSource); virtual; abstract;
    procedure SaveToMimeSource(MimeSource: TClxMimeSource); virtual; abstract;
    procedure LoadFromFile(const Filename: string); virtual;
    procedure SaveToFile(const Filename: string); virtual;
    procedure LoadFromStream(Stream: TStream); virtual; abstract;
    procedure SaveToStream(Stream: TStream); virtual; abstract;
    procedure LoadFrom(const Filename: string); overload;
    procedure LoadFrom(Stream: TStream); overload;
    procedure SaveTo(const Filename: string); overload;
    procedure SaveTo(Stream: TStream); overload;
    property Empty: Boolean read GetEmpty;
    property Height: Integer read GetHeight write SetHeight;
    property Modified: Boolean read FModified write SetModified;
    property Transparent: Boolean read GetTransparent write SetTransparent;
    property Width: Integer read GetWidth write SetWidth;
    property OnChange: TNotifyEvent read FOnChange write FOnChange;
    property OnProgress: TProgressEvent read FOnProgress write FOnProgress;
  end;

  { TPicture }
  { TPicture is a TGraphic container.  It is used in place of a TGraphic if the
    graphic can be of any TGraphic class.  LoadFromFile and SaveToFile are
    polymorphic. For example, if the TPicture is holding an Icon, you can
    LoadFromFile a bitmap file, where if the class was TIcon you could only read
    .ICO files.
      LoadFromFile - Reads a picture from disk.  The TGraphic class created
        determined by the file extension of the file.  If the file extension is
        not recognized an exception is generated.
      SaveToFile - Writes the picture to disk.
      LoadFromClipboardFormat - Reads the picture from the handle provided in
        the given clipboard format.  If the format is not supported, an
        exception is generated.
      SaveToClipboardFormats - Allocates a global handle and writes the picture
        in its native clipboard format (CF_BITMAP for bitmaps, CF_METAFILE
        for metafiles, etc.).  Formats will contain the formats written.
        Returns the number of clipboard items written to the array pointed to
        by Formats and Datas or would be written if either Formats or Datas are
        nil.
      Assign - Copys the contents of the given TPicture.  Used most often in
        the implementation of TPicture properties.
      RegisterFileFormat - Register a new TGraphic class for use in
        LoadFromFile.
      UnRegisterGraphicClass - Removes all references to the specified TGraphic
        class and all its descendents from the file format and clipboard format
        internal lists.
      Height - The native, unstretched, height of the picture.
      Width - The native, unstretched, width of the picture.
      Graphic - The TGraphic object contained by the TPicture
      Bitmap - Returns a bitmap.  If the contents is not already a bitmap, the
        contents are thrown away and a blank bitmap is returned.
      Icon - Returns an icon.  If the contents is not already an icon, the
        contents are thrown away and a blank icon is returned. }
  TPicture = class(TInterfacedPersistent, IStreamPersist)
  private
    FGraphic: TGraphic;
    FOnChange: TNotifyEvent;
    FOnProgress: TProgressEvent;
  { FNotify: IChangeNotifier; }
    procedure ForceType(GraphicType: TGraphicClass);
    function GetBitmap: TBitmap;
    function GetHeight: Integer;
    function GetIcon: TIcon;
    function GetWidth: Integer;
    procedure ReadData(Stream: TStream);
    procedure SetBitmap(Value: TBitmap);
    procedure SetGraphic(Value: TGraphic);
    procedure SetIcon(Value: TIcon);
    procedure WriteData(Stream: TStream);
  protected
    procedure AssignTo(Dest: TPersistent); override;
    procedure Changed(Sender: TObject); dynamic;
    procedure Progress(Sender: TObject; Stage: TProgressStage;
      PercentDone: Byte;  RedrawNow: Boolean; const R: TRect;
      const Msg: WideString); dynamic;
    procedure DefineProperties(Filer: TFiler); override;
  public
    constructor Create;
    destructor Destroy; override;
    procedure LoadFromMimeSource(MimeSource: TMimeSource);
    procedure SaveToMimeSource(MimeSource: TClxMimeSource);
    procedure LoadFromFile(const Filename: string);
    procedure LoadFromStream(Stream: TStream);
    procedure SaveToStream(Stream: TStream);
    procedure SaveToFile(const Filename: string);
    procedure Assign(Source: TPersistent); override;
    class procedure RegisterFileFormat(const AExtension, ADescription: string;
      AGraphicClass: TGraphicClass);
    class procedure RegisterFileFormatRes(const AExtension: string;
      ADescriptionResID: Integer; AGraphicClass: TGraphicClass);
    class procedure UnregisterGraphicClass(AClass: TGraphicClass);
    property Bitmap: TBitmap read GetBitmap write SetBitmap;
    property Graphic: TGraphic read FGraphic write SetGraphic;
    property Height: Integer read GetHeight;
    property Icon: TIcon read GetIcon write SetIcon;
    property Width: Integer read GetWidth;
    property OnChange: TNotifyEvent read FOnChange write FOnChange;
    property OnProgress: TProgressEvent read FOnProgress write FOnProgress;
  end;


  { TBitmap }
  { TBitmap is an encapsulation of a matrix of pixels.  It has a Canvas to allow
    modifications to the image.  Creating copies of a TBitmap is very fast
    since the handle is copied not the image.  If the image is modified, and
    the handle is shared by more than one TBitmap object, the image is copied
    before the modification is performed (i.e. copy on write). }

  TBitmapFileHeader = packed record
    bfType: Word;
    bfSize: DWORD;
    bfReserved1: Word;
    bfReserved2: Word;
    bfOffBits: DWORD;
  end;

  TBitmapInfoHeader = packed record
    biSize: DWORD;              // The size of this header (always sizeof(BITMAPINFOHEADER))
    biWidth: Integer;           // The width of the bitmap
    biHeight: Integer;          // The height of the bitmap
    biPlanes: Word;             // The planes in the bitmap (usually 1)
    biBitCount: Word;           // The bits per pixel (8 for 256 color bitmaps)
    biCompression: DWORD;       // Type of compression (I use no compression or BI_RGB)
    biSizeImage: DWORD;         // Total memory used by the bitmap (width * height in a 256 color bitmap)
    biXPelsPerMeter: Integer;   // Pixels per meter along the X-axis (0 if you don't care)
    biYPelsPerMeter: Integer;   //   "     "    "     "    "  Y-axis (0 if you don't care)
    biClrUsed: DWORD;           // Usually 0 (I think) or number of colors in bitmap's palette
    biClrImportant: DWORD;      // Always 0 (All colors are important)
  end;

  TIconDirEntry = record
    bWidth: Byte;               // Image width in pixels
    bHeight: Byte;              // Image height in pixels
    bColorCount: Byte;          // 0 if >= 8 bpp
    bReserved: Byte;
    wPlanes: Word;              // Color planes (usually 0)
    wBitCount: Word;            // Bits per pixel of this image
    dwBytesInRes: DWORD;        // Total bytes of image, including Color Table
    dwImageOffset: DWORD;       // Offset from BOF for this image
  end;

  TPixelFormat = (pf1bit, pf8bit, pf16bit, pf32bit, pfCustom);
  TTransparentMode = (tmAuto, tmFixed);

  TBitmap = class(TGraphic)
  private
    FImage: QImageH;
    FPixmap: QPixmapH;
    FCanvas: TCanvas;
    FStream: TStream;
    FHeight: Integer;
    FWidth: Integer;
    FPixelFormat: TPixelFormat;
    FFormat: string;
    FTransparentColor: TColor;
    FTransparentMode: TTransparentMode;
    procedure Changing(Sender: TObject);
    function GetCanvas: TCanvas;
    function GetHandle: QPixmapH;
    function GetMonochrome: Boolean;
    procedure ResizeImage(NewWidth, NewHeight: Integer);
    procedure SetMonochrome(const Value: Boolean);
    procedure SetHandle(const Value: QPixmapH);
    function GetTransparentColor: TColor;
    procedure SetTransparentColor(const Value: TColor);
    procedure SetTransparentMode(const Value: TTransparentMode);
    function TransparentColorStored: Boolean;
    function GetScanLine(Row: Integer): Pointer;
    function GetPixelFormat: TPixelFormat;
    procedure SetPixelFormat(const Value: TPixelFormat);
  protected
    procedure AssignTo(Dest: TPersistent); override;
    procedure Draw(ACanvas: TCanvas; const Rect: TRect); override;
    function GetEmpty: Boolean; override;
    function GetHeight: Integer; override;
    function GetTransparent: Boolean; override;
    function GetWidth: Integer; override;
    procedure ImageNeeded;
    procedure HandleNeeded;
    procedure ReadData(Stream: TStream); override;
    procedure SetHeight(Value: Integer); override;
    procedure SetTransparent(Value: Boolean); override;
    procedure SetWidth(Value: Integer); override;
    procedure TiledDraw(ACanvas: TCanvas; const Rect: TRect); override;
    procedure WriteData(Stream: TStream); override;
  public
    constructor Create; override;
    destructor Destroy; override;
    procedure Assign(Source: TPersistent); override;
    class function AssignsTo(Dest: TGraphicClass): Boolean; override;
    function ColorTable: Pointer;
    procedure Dormant;
    procedure FreeImage;
    procedure FreePixmap;
    function ReleasePixmap: QPixmapH;
    procedure LoadFromMimeSource(MimeSource: TMimeSource); override;
    procedure SaveToMimeSource(MimeSource: TClxMimeSource); override;
    procedure LoadFromResourceName(Instance: Cardinal; const ResName: string);
    procedure LoadFromResourceID(Instance: Cardinal; ResID: Integer);
    procedure LoadFromStream(Stream: TStream); override;
    procedure Mask(TransparentColor: TColor);
    procedure SaveToStream(Stream: TStream); override;
    property Canvas: TCanvas read GetCanvas;
    property Format: string read FFormat write FFormat;
    property Handle: QPixmapH read GetHandle write SetHandle;
    property Monochrome: Boolean read GetMonochrome write SetMonochrome;
    property PixelFormat: TPixelFormat read GetPixelFormat write SetPixelFormat;
    property ScanLine[Row: Integer]: Pointer read GetScanLine;
    property TransparentColor: TColor read GetTransparentColor
      write SetTransparentColor stored TransparentColorStored;
    property TransparentMode: TTransparentMode read FTransparentMode
      write SetTransparentMode default tmAuto;
  end;

  TBitmapCanvas = class(TCanvas)
  private
    FBitmap: TBitmap;
  protected
    procedure BeginPainting; override;
    procedure CreateHandle; override;
  public
    constructor Create(Bitmap: TBitmap);
  end;

  TIcon = class(TGraphic)
  private
    FBitmap: TBitmap;
    FMemoryImage: TMemoryStream;
    FRequestedSize: TPoint;
    procedure NewImage;
    function GetHandle: QPixmapH;
  protected
    procedure AssignTo(Dest: TPersistent); override;
    procedure Draw(ACanvas: TCanvas; const Rect: TRect); override;
    function GetEmpty: Boolean; override;
    function GetHeight: Integer; override;
    function GetWidth: Integer; override;
    procedure SetHeight(Value: Integer); override;
    procedure SetTransparent(Value: Boolean); override;
    procedure SetWidth(Value: Integer); override;
  public
    constructor Create; override;
    destructor Destroy; override;
    procedure Assign(Source: TPersistent); override;
    class function AssignsTo(Dest: TGraphicClass): Boolean; override;
    procedure LoadFromStream(Stream: TStream); override;
    procedure LoadFromMimeSource(MimeSource: TMimeSource); override;
    procedure LoadFromResourceName(Instance: THandle; const ResName: string);
    procedure SaveToMimeSource(MimeSource: TClxMimeSource); override;
    procedure SaveToStream(Stream: TStream); override;
    property Handle: QPixmapH read GetHandle;
  end;

  TDrawing = class(TGraphic)
  private
    FHandle: QPictureH;
    FWidth: Integer;
    FHeight: Integer;
    FCanvas: TCanvas;
    function GetCanvas: TCanvas;
  protected
    procedure Draw(ACanvas: TCanvas; const Rect: TRect); override;
    function GetEmpty: Boolean; override;
    function GetHeight: Integer; override;
    function GetWidth: Integer; override;
    procedure ReadData(Stream: TStream); override;
    procedure SetHeight(Value: Integer); override;
    procedure SetWidth(Value: Integer); override;
    procedure WriteData(Stream: TStream); override;
  public
    constructor Create; override;
    destructor Destroy; override;
    procedure Assign(Source: TPersistent); override;
    procedure LoadFromMimeSource(MimeSource: TMimeSource); override;
    procedure SaveToMimeSource(MimeSource: TClxMimeSource); override;
    procedure LoadFromStream(Stream: TStream); override;
    procedure SaveToStream(Stream: TStream); override;
    property Handle: QPictureH read FHandle;
    property Canvas: TCanvas read GetCanvas;
  end;

  TDrawingCanvas = class(TCanvas)
  private
    FDrawing: TDrawing;
  protected
    procedure BeginPainting; override;
    procedure CreateHandle; override;
  public
    constructor Create(Drawing: TDrawing);
  end;

  TColorGroup = (cgInactive, cgDisabled, cgActive);
  TColorRole = (crForeground, crButton, crLight, crMidlight, crDark, crMid,
    crText, crBrightText, crButtonText, crBase, crBackground, crShadow,
    crHighlight, crHighlightText, crNoRole);

  TPalette = class
  private
    FHandle: QPaletteH;
    FBaseColor: TColor;
    FInactiveColors: QColorGroupH;
    FActiveColors: QColorGroupH;
    FDisabledColors: QColorGroupH;
    FOnChange: TNotifyEvent;
    FOwned: Boolean;
    FUpdateCount: Integer;
    procedure SetBaseColor(const Value: TColor);
    function GetHandle: QPaletteH;
    procedure SetBrush(Group: TColorGroup; Role: TColorRole; Color: TColor;
      Pixmap: QPixmapH);
    procedure SetOwned(const Value: Boolean);
    procedure SetHandle(const Value: QPaletteH);
  protected
    procedure Changed; virtual;
    procedure CreatePalette;
  public
    constructor Create; virtual;
    destructor Destroy; override;
    procedure BeginUpdate;
    function GetBrushPixmap(Group: TColorGroup; Role: TColorRole): QPixmapH;
    function GetColor(Group: TColorGroup; Role: TColorRole): TColor; overload;
    function GetColor(MappedColor: TMappedColor): TColor; overload;
    function ColorGroup(Group: TColorGroup): QColorGroupH;
    procedure EndUpdate;
    procedure SetBitmap(Group: TColorGroup; Role: TColorRole; Bitmap: TBitmap);
    procedure SetColor(Group: TColorGroup; Role: TColorRole; Color: TColor);
    property BaseColor: TColor read FBaseColor write SetBaseColor;
    property Owned: Boolean read FOwned write SetOwned;
    property Handle: QPaletteH read GetHandle write SetHandle;
    property OnChange: TNotifyEvent read FOnChange write FOnChange;
  end;

  TWidgetPalette = class(TPalette)
  private
    FColorRole: TColorRole;
    FTextColorRole: TColorRole;
    FBitmap: TBitmap;
    function GetWidgetColor: TColor;
    function GetWidgetTextColor: TColor;
    procedure SetWidgetBitmap(const Value: TBitmap);
    procedure SetWidgetColor(const Value: TColor);
    procedure SetWidgetTextColor(const Value: TColor);
    function GetWidgetBitmap: TBitmap;
  protected
    procedure BitmapChanged(Sender: TObject); virtual;
  public
    constructor Create; override;
    destructor Destroy; override;
    function IsBitmapEmpty: Boolean;
    property ColorRole: TColorRole read FColorRole write FColorRole;
    property TextColorRole: TColorRole read FTextColorRole write FTextColorRole;
    property Bitmap: TBitmap read GetWidgetBitmap write SetWidgetBitmap;
    property Color: TColor read GetWidgetColor write SetWidgetColor;
    property TextColor: TColor read GetWidgetTextColor write SetWidgetTextColor;
  end;

function GraphicFilter(GraphicClass: TGraphicClass; AllFilter: Boolean = True): string;
function GraphicExtension(GraphicClass: TGraphicClass): string;
function GraphicFileMask(GraphicClass: TGraphicClass): string;

function QColor(Color: TColor; Widget: QWidgetH = nil): QColorH;
function QColorColor(Color: QColorH): TColor;
function ColorRole(Color: TColor): QColorGroupColorRole;
function ColorGroup(Color: TColor): QPaletteColorGroup;
function MulDiv(Number, Numerator, Denominator: Integer): Integer;
{$EXTERNALSYM MulDiv}
function ColorToString(Color: TColor): string;
function StringToColor(const S: string): TColor;
procedure GetColorValues(Proc: TGetStrProc);
function ColorToIdent(Color: Longint; var Ident: string): Boolean;
function IdentToColor(const Ident: string; var Color: Longint): Boolean;

procedure InflateRect(var ARect: TRect; X, Y: Integer);
procedure OffsetRect(var ARect: TRect; X, Y: Integer);

type
  TEdgeBorder = (ebLeft, ebTop, ebRight, ebBottom);
  TEdgeBorders = set of TEdgeBorder;
  TEdgeStyle = (esNone, esRaised, esLowered);

const
  ebRect = [ebLeft, ebTop, ebRight, ebBottom];

function AllocPatternBitmap(BkColor, FgColor: TColor): TBitmap;
function ColorToRGB(Color: TColor): Longint;

procedure DrawEdge(Canvas: TCanvas; R: TRect; EdgeInner, EdgeOuter: TEdgeStyle;
  EdgeBorders: TEdgeBorders);
procedure DrawItem(Canvas: TCanvas; x, y, w, h, Flags: Integer; Enabled: Boolean;
  const Text: WideString; Length: Integer = -1; ColorGroup: QColorGroupH = nil;
  Bitmap: TBitmap = nil);
procedure DrawShadeLine(Canvas: TCanvas; x1, y1, x2, y2: Integer; Sunken: Boolean;
  LineWidth: Integer; MidLineWidth: Integer; ColorGroup: QColorGroupH = nil);
procedure DrawShadeRect(Canvas: TCanvas; x, y, w, h: Integer; Sunken: Boolean;
  LineWidth: Integer; MidLineWidth: Integer; ColorGroup: QColorGroupH = nil); overload;
procedure DrawShadeRect(Canvas: TCanvas; Rect: TRect; Sunken: Boolean;
  LineWidth: Integer; MidLineWidth: Integer; ColorGroup: QColorGroupH = nil); overload;
procedure DrawShadePanel(Canvas: TCanvas; x, y, w, h: Integer; Sunken: Boolean;
  LineWidth: Integer; ColorGroup: QColorGroupH = nil); overload;
procedure DrawShadePanel(Canvas: TCanvas; Rect: TRect; Sunken: Boolean;
  LineWidth: Integer; ColorGroup: QColorGroupH = nil); overload;
procedure DrawWinButton(Canvas: TCanvas; x, y, w, h: Integer; Sunken: Boolean;
  ColorGroup: QColorGroupH = nil); overload;
procedure DrawWinButton(Canvas: TCanvas; Rect: TRect; Sunken: Boolean;
  ColorGroup: QColorGroupH = nil); overload;
procedure DrawWinPanel(Canvas: TCanvas; x, y, w, h: Integer; Sunken: Boolean;
  ColorGroup: QColorGroupH = nil); overload;
procedure DrawWinPanel(Canvas: TCanvas; Rect: TRect; Sunken: Boolean;
  ColorGroup: QColorGroupH = nil); overload;
procedure DrawPlainRect(Canvas: TCanvas; x, y, w, h: Integer; Color: TColor;
  LineWidth: Integer); overload;
procedure DrawPlainRect(Canvas: TCanvas; Rect: TRect; Color: TColor;
  LineWidth: Integer); overload;
function GetEmptyQBrush: QBrushH;
function GetEmptyQPen: QPenH;
function GetEmptyQFont: QFontH;


{ Set this to True if you want bitmaps to preserve the stream they read to
  ensure, if they have not been changed, the will write out exactly the same
  image they loaded. Normally this is False to preserve space. If this is False
  the bitmap will right out the same image but the bytes it writes might not
  be exactly what it read in. It might, for example, correct header mistakes
  or compress or expand optional tables, etc. }
var
  ExactBitmaps: Boolean;

implementation

uses
  QConsts, Math;

var
  ScreenLogPixels: Integer;
  CounterLock: TRTLCriticalSection;

function ColorToRGB(Color: TColor): Longint;
var
  QC: QColorH;
  Rgb: QRgb;
begin
  if Color < 0 then
  begin
    QC := QColor(Color);
    try
      QColor_rgb(QC, @Rgb);
      Result := Longint(Rgb);
    finally
      QColor_destroy(QC);
    end;
  end
  else Result := Color;
end;


procedure GetColorGroupAndRole(Color: TColor; out Group: QPaletteColorGroup;
  out Role: QColorGroupColorRole);
const
  Offset: array [QPaletteColorGroup_Normal..QPaletteColorGroup_Active] of Integer =
    (cloNormal, cloDisabled, cloActive);
  Roles: array[clHighlightedText..clForeground] of QColorGroupColorRole = (
    QColorGroupColorRole_HighlightedText, QColorGroupColorRole_Highlight,
    QColorGroupColorRole_Shadow, QColorGroupColorRole_Background,
    QColorGroupColorRole_Base, QColorGroupColorRole_ButtonText,
    QColorGroupColorRole_BrightText, QColorGroupColorRole_Text,
    QColorGroupColorRole_Mid, QColorGroupColorRole_Dark,
    QColorGroupColorRole_Midlight, QColorGroupColorRole_Light,
    QColorGroupColorRole_Button, QColorGroupColorRole_Foreground);
var
  Ofs: Integer;
begin
  Group := ColorGroup(Color);
  Ofs := Color + Offset[Group];
  if Group = QPaletteColorGroup_NColorGroups then
  begin
    Group := QPaletteColorGroup_Normal;
    Role := Roles[Color];
  end
  else if (Ofs < Low(Roles)) or (Ofs > High(Roles)) then
    Role := QColorGroupColorRole_NColorRoles
  else
    Role := Roles[Ofs];
end;

function ColorRole(Color: TColor): QColorGroupColorRole;
var
  Group: QPaletteColorGroup;
begin
  GetColorGroupAndRole(Color, Group, Result);
end;

function ColorGroup(Color: TColor): QPaletteColorGroup;
begin
  Result := QPaletteColorGroup_NColorGroups;  { Used to mean none }
  if Color < -cloNormal then
    if Color > -cloDisabled then
      Result := QPaletteColorGroup_Normal
    else if Color > -cloActive then
      Result := QPaletteColorGroup_Disabled
    else
      Result := QPaletteColorGroup_Active;
end;

function GetEmptyQBrush: QBrushH;
begin
  Result := QBrush_create;
end;

function GetEmptyQPen: QPenH;
begin
  Result := QPen_create;
end;

function GetEmptyQFont: QFontH;
begin
  Result := QFont_create;
end;

procedure InvalidHandle(const ClassName: string);
begin
  raise EInvalidHandleException.CreateResFmt(@SInvalidHandle, [ClassName]);
end;

procedure InvalidOperation(Str: PResStringRec);
begin
  raise EInvalidGraphicOperation.CreateRes(Str);
end;

procedure InvalidGraphic(Str: PResStringRec);
begin
  raise EInvalidGraphic.CreateRes(Str);
end;

function MulDiv(Number, Numerator, Denominator: Integer): Integer;
begin
  if Denominator = 0 then
  begin
    Result := -1;
    Exit;
  end;
  Result := (Int64(Number) * Numerator) div Denominator;
end;

function QColor(Color: TColor; Widget: QWidgetH = nil): QColorH;
var
  Group: QPaletteColorGroup;
  Role: QColorGroupColorRole;
  Palette: QPaletteH;
begin
  if (Color < 0) and (Color >= clFirstSpecialColor) then
  begin
    GetColorGroupAndRole(Color, Group, Role);
    Palette := QPalette_create;
    QApplication_palette(Palette, Widget);
    Result := QColor_create(QPalette_color(Palette, Group, Role));
    QPalette_destroy(Palette);
  end
  else
    Result := QColor_create(Color and $FF, (Color shr 8) and $FF,
      (Color shr 16) and $FF);
end;

function QColorColor(Color: QColorH): TColor;
begin
  Result := QColor_red(Color) or (QColor_green(Color) shl 8) or
    (QColor_blue(Color) shl 16);
end;

const
  Colors: array[0..95] of TIdentMapEntry = (
    (Value: clBlack; Name: 'clBlack'),
    (Value: clMaroon; Name: 'clMaroon'),
    (Value: clGreen; Name: 'clGreen'),
    (Value: clOlive; Name: 'clOlive'),
    (Value: clNavy; Name: 'clNavy'),
    (Value: clPurple; Name: 'clPurple'),
    (Value: clTeal; Name: 'clTeal'),
    (Value: clGray; Name: 'clGray'),
    (Value: clSilver; Name: 'clSilver'),
    (Value: clRed; Name: 'clRed'),
    (Value: clLime; Name: 'clLime'),
    (Value: clYellow; Name: 'clYellow'),
    (Value: clBlue; Name: 'clBlue'),
    (Value: clFuchsia; Name: 'clFuchsia'),
    (Value: clAqua; Name: 'clAqua'),
    (Value: clWhite; Name: 'clWhite'),
    (Value: clNone; Name: 'clNone'),
    (Value: clBackground; Name: 'clBackground'),
    (Value: clHighlight; Name: 'clHighlight'),
    (Value: clHighlightText; Name: 'clHighlightText'),
    (Value: clForeground; Name: 'clForeground'),
    (Value: clButton; Name: 'clButton'),
    (Value: clLight; Name: 'clLight'),
    (Value: clMidlight; Name: 'clMidlight'),
    (Value: clDark; Name: 'clDark'),
    (Value: clMid; Name: 'clMid'),
    (Value: clText; Name: 'clText'),
    (Value: clBrightText; Name: 'clBrightText'),
    (Value: clButtonText; Name: 'clButtonText'),
    (Value: clBase; Name: 'clBase'),
    (Value: clShadow; Name: 'clShadow'),
    (Value: clNormalForeground; Name: 'clNormalForeground'),
    (Value: clNormalButton; Name: 'clNormalButton'),
    (Value: clNormalLight; Name: 'clNormalLight'),
    (Value: clNormalMidlight; Name: 'clNormalMidlight'),
    (Value: clNormalDark; Name: 'clNormalDark'),
    (Value: clNormalMid; Name: 'clNormalMid'),
    (Value: clNormalText; Name: 'clNormalText'),
    (Value: clNormalBrightText; Name: 'clNormalBrightText'),
    (Value: clNormalButtonText; Name: 'clNormalButtonText'),
    (Value: clNormalBase; Name: 'clNormalBase'),
    (Value: clNormalBackground; Name: 'clNormalBackground'),
    (Value: clNormalShadow; Name: 'clNormalShadow'),
    (Value: clNormalHighlight; Name: 'clNormalHighlight'),
    (Value: clNormalHighlightedText; Name: 'clNormalHighlightedText'),
    (Value: clDisabledForeground; Name: 'clDisabledForeground'),
    (Value: clDisabledButton; Name: 'clDisabledButton'),
    (Value: clDisabledLight; Name: 'clDisabledLight'),
    (Value: clDisabledMidlight; Name: 'clDisabledMidlight'),
    (Value: clDisabledDark; Name: 'clDisabledDark'),
    (Value: clDisabledMid; Name: 'clDisabledMid'),
    (Value: clDisabledText; Name: 'clDisabledText'),
    (Value: clDisabledBrightText; Name: 'clDisabledBrightText'),
    (Value: clDisabledButtonText; Name: 'clDisabledButtonText'),
    (Value: clDisabledBase; Name: 'clDisabledBase'),
    (Value: clDisabledBackground; Name: 'clDisabledBackground'),
    (Value: clDisabledShadow; Name: 'clDisabledShadow'),
    (Value: clDisabledHighlight; Name: 'clDisabledHighlight'),
    (Value: clDisabledHighlightedText; Name: 'clDisabledHighlightedText'),
    (Value: clActiveForeground; Name: 'clActiveForeground'),
    (Value: clActiveButton; Name: 'clActiveButton'),
    (Value: clActiveLight; Name: 'clActiveLight'),
    (Value: clActiveMidlight; Name: 'clActiveMidlight'),
    (Value: clActiveDark; Name: 'clActiveDark'),
    (Value: clActiveMid; Name: 'clActiveMid'),
    (Value: clActiveText; Name: 'clActiveText'),
    (Value: clActiveBrightText; Name: 'clActiveBrightText'),
    (Value: clActiveButtonText; Name: 'clActiveButtonText'),
    (Value: clActiveBase; Name: 'clActiveBase'),
    (Value: clActiveBackground; Name: 'clActiveBackground'),
    (Value: clActiveShadow; Name: 'clActiveShadow'),
    (Value: clActiveHighlight; Name: 'clActiveHighlight'),
    (Value: clActiveHighlightedText; Name: 'clActiveHighlightedText'),
    { compatibility values not shown in Object Inspector }
    (Value: clScrollBar; Name: 'clScrollBar'),
    (Value: clActiveCaption; Name: 'clActiveCaption'),
    (Value: clInactiveCaption; Name: 'clInactiveCaption'),
    (Value: clMenu; Name: 'clMenu'),
    (Value: clWindow; Name: 'clWindow'),
    (Value: clWindowFrame; Name: 'clWindowFrame'),
    (Value: clMenuText; Name: 'clMenuText'),
    (Value: clWindowText; Name: 'clWindowText'),
    (Value: clCaptionText; Name: 'clCaptionText'),
    (Value: clActiveBorder; Name: 'clActiveBorder'),
    (Value: clInactiveBorder; Name: 'clInactiveBorder'),
    (Value: clAppWorkSpace; Name: 'clAppWorkSpace'),
    (Value: clBtnFace; Name: 'clBtnFace'),
    (Value: clBtnShadow; Name: 'clBtnShadow'),
    (Value: clGrayText; Name: 'clGrayText'),
    (Value: clBtnText; Name: 'clBtnText'),
    (Value: clInactiveCaptionText; Name: 'clInactiveCaptionText'),
    (Value: clBtnHighlight; Name: 'clBtnHighlight'),
    (Value: cl3DDkShadow; Name: 'cl3DDkShadow'),
    (Value: cl3DLight; Name: 'cl3DLight'),
    (Value: clInfoText; Name: 'clInfoText'),
    (Value: clInfoBk; Name: 'clInfoBk'),
    (Value: clHighlightedText; Name: 'clHighlightedText'));

procedure GetColorValues(Proc: TGetStrProc);
var
  I: Integer;
begin
  for I := Low(Colors) to 74 do Proc(Colors[I].Name);
end;

function ColorToIdent(Color: Longint; var Ident: string): Boolean;
begin
  Result := IntToIdent(Color, Ident, Colors);
end;

function IdentToColor(const Ident: string; var Color: Longint): Boolean;
begin
  Result := IdentToInt(Ident, Color, Colors);
end;

function ColorToString(Color: TColor): string;
begin
  if not ColorToIdent(Color, Result) then
    FmtStr(Result, '%s%.8x', [HexDisplayPrefix, Color]);
end;

function StringToColor(const S: string): TColor;
begin
  if not IdentToColor(S, Longint(Result)) then
    Result := TColor(StrToInt(S));
end;

procedure InflateRect(var ARect: TRect; X, Y: Integer);
begin
  with ARect do
  begin
    Dec(Top, Y);
    Inc(Bottom, Y);
    Dec(Left, X);
    Inc(Right, X);
  end;
end;

procedure OffsetRect(var ARect: TRect; X, Y: Integer);
begin
  with ARect do
  begin
    Inc(Left, X);
    Inc(Top, Y);
    Inc(Right, X);
    Inc(Bottom, Y);
  end;
end;

procedure DrawEdge(Canvas: TCanvas; R: TRect; EdgeInner, EdgeOuter: TEdgeStyle;
  EdgeBorders: TEdgeBorders);
var
  RInner: TRect;
begin
  if Canvas <> nil then
  with Canvas do
  begin
    Dec(R.Bottom);
    Dec(R.Right);
    RInner := R;
    InflateRect(RInner, -1, -1);
    if ebTop in EdgeBorders then
    begin
      PenPos := R.TopLeft;
      case EdgeOuter of
        esRaised: Pen.Color := clBtnHighlight;
        esLowered: Pen.Color := clDark;
      end;
      if EdgeOuter <> esNone then
        LineTo(R.Right, R.Top);

      case EdgeInner of
        esRaised: Pen.Color := clBtnHighlight;
        esLowered: Pen.Color := clMid;
      end;
      if EdgeInner in [esRaised, esLowered] then
      begin
        PenPos := Point(RInner.Left, RInner.Top);
        LineTo(RInner.Right, RInner.Top);
      end;
    end;

    if ebLeft in EdgeBorders then
    begin
      PenPos := Point(R.Left, R.Top);
      case EdgeOuter of
        esRaised: Pen.Color := clBtnHighlight;
        esLowered: Pen.Color := clDark;
      end;
      if EdgeOuter <> esNone then
        LineTo(R.Left, R.Bottom);

      PenPos := Point(RInner.Left, RInner.Top);
      case EdgeInner of
        esRaised: Pen.Color := clBtnHighlight;
        esLowered: Pen.Color := clMid;
      end;
      if EdgeInner in [esRaised, esLowered] then
        LineTo(RInner.Left, RInner.Bottom);
    end;

    if ebRight in EdgeBorders then
    begin
      PenPos := Point(R.Right, R.Top);
      case EdgeOuter of
        esRaised: Pen.Color := clBlack;
        esLowered: Pen.Color := clBtnHighlight;
      end;
      if EdgeOuter <> esNone then
        LineTo(R.Right, R.Bottom);

      case EdgeInner of
        esRaised: Canvas.Pen.Color := clMid;
        esLowered: Canvas.Pen.Color := clBtnHighlight;
      end;
      if EdgeInner <> esNone then
      begin
        PenPos := Point(RInner.Right, RInner.Top);
        LineTo(RInner.Right, RInner.Bottom);
      end;
    end;

    if ebBottom in EdgeBorders then
    begin
      PenPos := Point(R.Left, R.Bottom);
      if EdgeOuter = esRaised then
        Pen.Color := clBlack
      else if EdgeOuter = esLowered then
        Pen.Color := clBtnHighlight;
      if EdgeOuter in [esRaised, esLowered] then
        LineTo(R.Right, R.Bottom);

      case EdgeInner of
        esRaised: Canvas.Pen.Color := clMid;
        esLowered: Canvas.Pen.Color := clBtnHighlight;
      end;
      if EdgeInner <> esNone then
      begin
        PenPos := Point(RInner.Left, RInner.Bottom);
        LineTo(RInner.Right, RInner.Bottom);
      end;
    end;
  end;
end;

procedure DrawItem(Canvas: TCanvas; x, y, w, h, Flags: Integer; Enabled: Boolean;
  const Text: WideString; Length: Integer = -1; ColorGroup: QColorGroupH = nil;
  Bitmap: TBitmap = nil);
var
  Pixmap: QPixmapH;
begin
  if Assigned(Bitmap) then
    Pixmap := Bitmap.Handle
  else
    Pixmap := nil;

  Canvas.Changing;
  Canvas.Start;
  try
    Canvas.RequiredState([csHandleValid, csPenValid, csBrushValid]);
    QClxDrawUtil_DrawItem(Canvas.Handle, x, y, w, h, Flags, ColorGroup, Enabled,
      Pixmap, PWideString(@Text), Length, nil);
  finally
    Canvas.Stop;
  end;
  Canvas.Changed;
end;

procedure DrawShadeLine(Canvas: TCanvas; x1, y1, x2, y2: Integer; Sunken: Boolean;
  LineWidth: Integer; MidLineWidth: Integer; ColorGroup: QColorGroupH = nil); overload;
begin
  Canvas.Changing;
  Canvas.Start;
  try
    Canvas.RequiredState([csHandleValid, csPenValid]);
    QClxDrawUtil_drawShadeLine(Canvas.Handle, x1, y1, x2, y2, ColorGroup, Sunken,
      LineWidth, MidLineWidth);
  finally
    Canvas.Stop;
  end;
  Canvas.Changed;
end;

procedure DrawShadeLine(Canvas: TCanvas; P1, P2: TPoint; Sunken: Boolean;
  LineWidth: Integer; MidLineWidth: Integer; ColorGroup: QColorGroupH = nil); overload;
begin
  Canvas.Changing;
  Canvas.Start;
  try
    Canvas.RequiredState([csHandleValid, csPenValid]);
    QClxDrawUtil_drawShadeLine(Canvas.Handle, @P1, @P2, ColorGroup, Sunken,
      LineWidth, MidLineWidth);
  finally
    Canvas.Stop;
  end;
  Canvas.Changed;
end;

procedure DrawShadeRect(Canvas: TCanvas; x, y, w, h: Integer; Sunken: Boolean;
  LineWidth: Integer; MidLineWidth: Integer; ColorGroup: QColorGroupH = nil);
begin
  Canvas.Changing;
  Canvas.Start;
  try
    Canvas.RequiredState([csHandleValid, csPenValid]);
    QClxDrawUtil_drawShadeRect(Canvas.Handle, x, y, w, h, ColorGroup, Sunken,
      LineWidth, MidLineWidth, nil);
  finally
    Canvas.Stop;
  end;
  Canvas.Changed;
end;

procedure DrawShadeRect(Canvas: TCanvas; Rect: TRect; Sunken: Boolean;
  LineWidth: Integer; MidLineWidth: Integer; ColorGroup: QColorGroupH = nil);
begin
  Canvas.Changing;
  Canvas.Start;
  try
    Canvas.RequiredState([csHandleValid, csPenValid]);
    QClxDrawUtil_drawShadeRect(Canvas.Handle, @Rect, ColorGroup, Sunken,
      LineWidth, MidLineWidth, nil);
  finally
    Canvas.Stop;
  end;
  Canvas.Changed;
end;

procedure DrawShadePanel(Canvas: TCanvas; x, y, w, h: Integer; Sunken: Boolean;
  LineWidth: Integer; ColorGroup: QColorGroupH = nil);
begin
  Canvas.Changing;
  Canvas.Start;
  try
    Canvas.RequiredState([csHandleValid, csPenValid, csBrushValid]);
    QClxDrawUtil_drawShadePanel(Canvas.Handle, x, y, w, h, ColorGroup, Sunken,
      LineWidth, nil);
  finally
    Canvas.Stop;
  end;
  Canvas.Changed;
end;

procedure DrawShadePanel(Canvas: TCanvas; Rect: TRect; Sunken: Boolean;
  LineWidth: Integer; ColorGroup: QColorGroupH = nil);
begin
  Canvas.Changing;
  Canvas.Start;
  try
    Canvas.RequiredState([csHandleValid, csPenValid, csBrushValid]);
    QClxDrawUtil_drawShadePanel(Canvas.Handle, @Rect, ColorGroup, Sunken,
      LineWidth, nil);
  finally
    Canvas.Stop;
  end;
  Canvas.Changed;
end;

procedure DrawWinButton(Canvas: TCanvas; x, y, w, h: Integer; Sunken: Boolean;
  ColorGroup: QColorGroupH = nil);
begin
  Canvas.Changing;
  Canvas.Start;
  try
    Canvas.RequiredState([csHandleValid, csPenValid, csBrushValid]);
    QClxDrawUtil_drawWinButton(Canvas.Handle, x, y, w, h, ColorGroup, Sunken, nil);
  finally
    Canvas.Stop;
  end;
  Canvas.Changed;
end;

procedure DrawWinButton(Canvas: TCanvas; Rect: TRect; Sunken: Boolean;
  ColorGroup: QColorGroupH = nil);
begin
  Canvas.Changing;
  Canvas.Start;
  try
    Canvas.RequiredState([csHandleValid, csPenValid, csBrushValid]);
    QClxDrawUtil_drawWinButton(Canvas.Handle, @Rect, ColorGroup, Sunken, nil);
  finally
    Canvas.Stop;
  end;
  Canvas.Changed;
end;

procedure DrawWinPanel(Canvas: TCanvas; x, y, w, h: Integer; Sunken: Boolean;
  ColorGroup: QColorGroupH = nil);
begin
  Canvas.Changing;
  Canvas.Start;
  try
    Canvas.RequiredState([csHandleValid, csPenValid, csBrushValid]);
    QClxDrawUtil_drawWinPanel(Canvas.Handle, x, y, w, h, ColorGroup, Sunken, nil);
  finally
    Canvas.Stop;
  end;
  Canvas.Changed;
end;

procedure DrawWinPanel(Canvas: TCanvas; Rect: TRect; Sunken: Boolean;
  ColorGroup: QColorGroupH = nil);
begin
  Canvas.Changing;
  Canvas.Start;
  try
    Canvas.RequiredState([csHandleValid, csPenValid, csBrushValid]);
    QClxDrawUtil_drawWinPanel(Canvas.Handle, @Rect, ColorGroup, Sunken, nil);
  finally
    Canvas.Stop;
  end;
  Canvas.Changed;
end;

procedure DrawPlainRect(Canvas: TCanvas; x, y, w, h: Integer; Color: TColor;
  LineWidth: Integer);
begin
  Canvas.Changing;
  Canvas.Start;
  try
    Canvas.RequiredState([csHandleValid, csPenValid]);
    QClxDrawUtil_drawPlainRect(Canvas.Handle, x, y, w, h, QColor(Color), LineWidth,
      nil);
  finally
    Canvas.Stop;
  end;
  Canvas.Changed;
end;

procedure DrawPlainRect(Canvas: TCanvas; Rect: TRect; Color: TColor;
  LineWidth: Integer);
begin
  Canvas.Changing;
  Canvas.Start;
  try
    Canvas.RequiredState([csHandleValid, csPenValid]);
    QClxDrawUtil_drawPlainRect(Canvas.Handle, @Rect, QColor(Color), LineWidth, nil);
  finally
    Canvas.Stop;
  end;
  Canvas.Changed;
end;

{ TGraphicsObject }

procedure TGraphicsObject.Changed;
begin
  if FChangeDisabled <> 0 then
    FChangePending := True
  else if Assigned(FOnChange) then
    FOnChange(Self);
end;

procedure TGraphicsObject.DisableChanged;
begin
  Inc(FChangeDisabled);
end;

procedure TGraphicsObject.EnableChanged;
begin
  Dec(FChangeDisabled);
  if (FChangeDisabled = 0) and FChangePending then
  begin
    FChangePending := False;
    Changed;
  end;
end;

procedure TGraphicsObject.Lock;
begin
  // Not supported
end;

procedure TGraphicsObject.Unlock;
begin
  // Not supported
end;

{ TFont }

procedure TFont.Assign(Source: TPersistent);
begin
  if Source is TFont then
  begin
    DisableChanged;
    try
      Lock;
      try
        TFont(Source).Lock;
        try
          CharSet := TFont(Source).CharSet;
          Height := TFont(Source).Height;
          Name := TFont(Source).Name;
          Pitch := TFont(Source).Pitch;
          Size := TFont(Source).Size;
          Style := TFont(Source).Style;
          Weight := TFont(Source).Weight;
          Color := TFont(Source).Color;
          Size := TFont(Source).Size;
        finally
          TFont(Source).Unlock;
        end;
      finally
        Unlock;
      end;
    finally
      EnableChanged;
    end;
  end
  else
    inherited Assign(Source);
end;

constructor TFont.Create;
begin
  inherited Create;
  FHandle := GetEmptyQFont;
  FFontPen := GetEmptyQPen;
  FOwned := True;
  FCharSet := fcsDefaultCharSet;
  FPixelsPerInch := ScreenLogPixels;
  FOriginalWeight := Weight;
end;

constructor TFont.Create(AHandle: QFontH);
begin
  inherited Create;
  FHandle := AHandle;
  FFontPen := GetEmptyQPen;
  FOwned := False;
end;

destructor TFont.Destroy;
begin
  FreeHandle;
  if FFontPen <> nil then QPen_destroy(FFontPen);
  inherited Destroy;
end;

procedure TFont.FreeHandle;
begin
  if FOwned then
    QFont_destroy(FHandle);
end;

function TFont.GetHeight: Integer;
begin
  Result := QFont_pixelSize(FHandle);
end;

function TFont.GetName: TFontName;
var
  WFontName: WideString;
begin
  QFont_family(FHandle, PWideString(@WFontName));
  Result := WFontName;
end;

function TFont.GetPitch: TFontPitch;
begin
  if QFont_fixedPitch(FHandle) then
    Result := fpFixed
  else
    Result := fpVariable;
end;

function TFont.GetSize: Integer;
begin
  Result := QFont_pointSize(FHandle);
end;

function TFont.GetStyle: TFontStyles;
begin
  Result := [];
  if QFont_bold(FHandle) then
    Include(Result, fsBold);
  if QFont_italic(FHandle) then
    Include(Result, fsItalic);
  if QFont_underline(FHandle) then
    Include(Result, fsUnderline);
  if QFont_strikeout(FHandle) then
    Include(Result, fsStrikeOut);
end;

function TFont.GetWeight: Integer;
begin
  Result := QFont_weight(FHandle);
end;

function TFont.IsWeightStored: Boolean;
begin
  Result := not (Weight in [fwNormal, fwBold]);
end;

procedure TFont.OwnHandle;
begin
  FOwned := True;
end;

function TFont.ReleaseHandle: QFontH;
begin
  Result := FHandle;
  FHandle := GetEmptyQFont;
  FOwned := True;
  Changed;
end;

procedure TFont.SetCharSet(Value: TFontCharSet);
const
  CharSetMap: array[ANSI_CHARSET..OEM_CHARSET] of TFontCharSet =
  (
    {ANSI_CHARSET}            fcsLatin1,
    {DEFAULT_CHARSET}         fcsDefaultCharSet,
    {SYMBOL_CHARSET}          fcsUnicode,
    {MAC_CHARSET}             fcsLatin1,
    {SHIFTJIS_CHARSET}        fcsSet_Ja,
    {HANGEUL_CHARSET}         fcsSet_Ko,
    {JOHAB_CHARSET}           fcsKOI8R,
    {GB2312_CHARSET}          fcsUnicode,
    {CHINESEBIG5_CHARSET}     fcsUnicode,
    {GREEK_CHARSET}           fcsUnicode,
    {TURKISH_CHARSET}         fcsUnicode,
    {HEBREW_CHARSE}           fcsUnicode,
    {ARABIC_CHARSET}          fcsUnicode,
    {BALTIC_CHARSET}          fcsUnicode,
    {RUSSIAN_CHARSET}         fcsUnicode,
    {THAI_CHARSET}            fcsUnicode,
    {EASTEUROPEN_CHARSET}     fcsUnicode,
    {OEM_CHARSET}             fcsLatin1
  );

begin
  if Value <> CharSet then
  begin
    if Value >= ANSI_CHARSET then
      Value := CharSetMap[Value];
    if Value <> FCharSet then
    begin
      FCharSet := Value;
      if Value = fcsDefaultCharSet then
        QFont_setCharSet(FHandle, QFont_charSetForLocale)
      else
        QFont_setCharSet(FHandle, QFontCharSet(Value));
      Changed;
    end;
  end;
end;

procedure TFont.SetColor(const Value: TColor);
var
  QC: QColorH;
begin
  if Value <> Color then
  begin
    FColor := Value;
    QC := QColor(Value);
    try
      QPen_setColor(FFontPen, QC);
    finally
      QColor_destroy(QC);
    end;
    Changed;
  end;
end;

procedure TFont.SetHandle(const Value: QFontH);
begin
  if Value <> FHandle then
  begin
    if not Assigned(Value) then
      InvalidHandle(ClassName);
    FreeHandle;
    FHandle := Value;
    FCharSet := TFontCharSet(QFont_charSet(Value));
    if FCharSet = TFontCharSet(QFont_charSetForLocale) then
      FCharSet := fcsDefaultCharSet;
    FOriginalWeight := QFont_weight(Value);
    Changed;
  end;
end;

procedure TFont.SetHeight(const Value: Integer);
var
  H: Integer;
begin
  // Translate negative values to positive values.
  // CLX does not have cell height vs. font height like VCL does but might
  // receive a cell height value from a VCL form.
  H := Value;
  if H < 0 then H := -H;
  if H = 0 then H := ScreenLogPixels div 10;
  if H <> Height then
  begin
    QFont_setPixelSize(FHandle, H);
    Changed;
  end;
end;

procedure TFont.SetName(const Value: TFontName);
var
  WFontName: WideString;
begin
  if Value <> Name then
  begin
    WFontName := Value;
    QFont_setFamily(FHandle, PWideString(@WFontName));
    Changed;
  end;
end;

procedure TFont.SetPitch(const Value: TFontPitch);
begin
  if (Value <> Pitch) and (Value <> fpDefault) then
  begin
    QFont_setFixedPitch(FHandle, Value = fpFixed);
    Changed;
  end;
end;

procedure TFont.SetSize(const Value: Integer);
var
  V: Integer;
begin
  // Translate negative values to positive values.
  // CLX does not have cell height vs. font height like VCL does but might
  // receive a cell height value from a VCL form.
  V := Value;
  if V < 0 then V := -V;
  if V = 0 then V := 1;
  if V <> Size then
  begin
    QFont_setPointSize(FHandle, V);
    Changed;
  end;
end;

procedure TFont.SetStyle(const Value: TFontStyles);
begin
  if Value <> Style then
  begin
    if (Weight = FOriginalWeight) or (Weight in [fwNormal, fwBold]) then
    begin
      { Ignore bold if weight is non-standard }
      QFont_setBold(FHandle, fsBold in Value);
      FOriginalWeight := -1;
    end;
    QFont_setItalic(FHandle, fsItalic in Value);
    QFont_setUnderline(FHandle, fsUnderline in Value);
    QFont_setStrikeout(FHandle, fsStrikeOut in Value);
    Changed;
  end;
end;

procedure TFont.SetWeight(const Value: Integer);
var
  AdjustedVal : Integer;
begin
  if Value <> Weight then
  begin
    { Weights are constrained because they represent percentages. }
    if Value <= -1 then AdjustedVal := 0 else
    if Value >= 99 then AdjustedVal := 99 else
      AdjustedVal := Value;
    QFont_setWeight(FHandle, AdjustedVal);
    FOriginalWeight := -1;
    Changed;
  end;
end;

{ TPen }

procedure TPen.Assign(Source: TPersistent);
begin
  if Source is TPen then
  begin
    DisableChanged;
    try
      Lock;
      try
        TPen(Source).Lock;
        try
          Color := TPen(Source).Color;
          Mode := TPen(Source).Mode;
          Style := TPen(Source).Style;
          Width := TPen(Source).Width;
        finally
          TPen(Source).Unlock;
        end;
      finally
        Unlock;
      end;
    finally
      EnableChanged;
    end;
  end
  else
    inherited Assign(Source);
end;

constructor TPen.Create;
begin
  inherited Create;
  FMode := pmCopy;
  FHandle := GetEmptyQPen;
  FOwned := True;
end;

constructor TPen.Create(AHandle: QPenH);
begin
  inherited Create;
  FHandle := AHandle;
  FOwned := False;
end;

destructor TPen.Destroy;
begin
  FreeHandle;
  inherited Destroy;
end;

procedure TPen.FreeHandle;
begin
  if FOwned then
    QPen_destroy(FHandle);
end;

function TPen.GetStyle: TPenStyle;
var
  PenStyle: QT.PenStyle;
begin
  PenStyle := QPen_style(FHandle);
  if PenStyle = PenStyle_NoPen then
    Result := psClear
  else
    {
      Assumes that enumeration in this units matches the one in QT except
      for NoPen is first instead of SolidLine. If this is no longer the case
      a mapping array should be introduced.
    }
    Result := Pred(TPenStyle(PenStyle));
end;

function TPen.GetWidth: Integer;
begin
  Result := QPen_width(FHandle);
end;

procedure TPen.OwnHandle;
begin
  FOwned := True;
end;

function TPen.ReleaseHandle: QPenH;
begin
  Result := FHandle;
  FHandle := GetEmptyQPen;
  FOwned := True;
  Changed;
end;

procedure TPen.SetColor(const Value: TColor);
var
  QC: QColorH;
begin
  if Value <> Color then
  begin
    FColor := Value;
    QC := QColor(Value);
    try
      QPen_setColor(FHandle, QC);
    finally
      QColor_destroy(QC);
    end;
    Changed;
  end;
end;

procedure TPen.SetHandle(const Value: QPenH);
begin
  if Value <> Handle then
  begin
    if not Assigned(Value) then
      InvalidHandle(ClassName);
    FreeHandle;
    FHandle := Value;
    Changed;
  end;
end;

procedure TPen.SetMode(const Value: TPenMode);
begin
  if Value <> FMode then
  begin
    FMode := Value;
    Changed;
  end;
end;

procedure TPen.SetStyle(const Value: TPenStyle);
var
  PenStyle: QT.PenStyle;
begin
  if Value <> Style then
  begin
    if Value = psClear then
      PenStyle := PenStyle_NoPen
    else
      { *See warning* in TPen.GetStyle }
      PenStyle := QT.PenStyle(Succ(Value));
    QPen_setStyle(FHandle, PenStyle);           
    Changed;
  end;
end;

procedure TPen.SetWidth(const Value: Integer);
begin
  if Value <> Width then
  begin
    QPen_setWidth(FHandle, Value);
    Changed;
  end;
end;

{ TBrush }

procedure TBrush.Assign(Source: TPersistent);
begin
  if Source is TBrush then
  begin
    DisableChanged;
    try
      Lock;
      try
        TBrush(Source).Lock;
        try
          Bitmap := TBrush(Source).Bitmap;
          Color := TBrush(Source).Color;
          Style := TBrush(Source).Style;
        finally
          TBrush(Source).Unlock;
        end;
      finally
        Unlock;
      end;
    finally
      EnableChanged;
    end;
  end
  else
    inherited Assign(Source);
end;

constructor TBrush.Create;
begin
  inherited Create;
  FHandle := GetEmptyQBrush;
  FOwned := True;
  Style := bsSolid;
  Color := clWhite;
end;

procedure TBrush.BitmapChanged(Sender: TObject);
begin
  if FBitmap <> nil then
    QBrush_setPixmap(Handle, FBitmap.Handle);
  Changed;
end;

constructor TBrush.Create(AHandle: QBrushH);
begin
  inherited Create;
  FHandle := AHandle;
  FOwned := False;
end;

destructor TBrush.Destroy;
begin
  FreeHandle;
  inherited Destroy;
end;

procedure TBrush.FreeHandle;
begin
  if FOwned then
    QBrush_destroy(FHandle);
end;

const
  QtBrushStyle: array[TBrushStyle] of Qt.BrushStyle =
    (BrushStyle_SolidPattern, BrushStyle_NoBrush, BrushStyle_HorPattern,
     BrushStyle_VerPattern, BrushStyle_FDiagPattern, BrushStyle_BDiagPattern,
     BrushStyle_CrossPattern, BrushStyle_DiagCrossPattern, BrushStyle_Dense1Pattern,
     BrushStyle_Dense2Pattern, BrushStyle_Dense3Pattern, BrushStyle_Dense4Pattern,
     BrushStyle_Dense5Pattern, BrushStyle_Dense6Pattern, BrushStyle_Dense7Pattern);

function TBrush.GetBitmap: TBitmap;
begin
  if not Assigned(FBitmap) then
  begin
    FBitmap := TBitmap.Create;
    FBitmap.OnChange := BitmapChanged;
  end;
  Result := FBitmap;
end;

function TBrush.GetStyle: TBrushStyle;
var
  AStyle: Qt.BrushStyle;
  I: TBrushStyle;
begin
  AStyle := QBrush_style(FHandle);
  Result := bsSolid;
  for I := Low(TBrushStyle) to High(TBrushStyle) do
    if QtBrushStyle[I] = AStyle then
    begin
      Result := I;
      Exit;
    end;
end;

procedure TBrush.SetBitmap(const Value: TBitmap);
begin
  if Value <> Bitmap then
  begin
    Bitmap.Assign(Value);
    BitmapChanged(FBitmap);
    Changed;
  end;
end;

function BrushFromColor(const Value: TColor; Widget: QWidgetH = nil): QBrushH;
var
  Group: QPaletteColorGroup;
  Role: QColorGroupColorRole;
  Palette: QPaletteH;
begin
  Result := nil;
  if Value >= 0 then Exit;
  GetColorGroupAndRole(Value, Group, Role);
  Palette := QPalette_create;
  try
    QApplication_palette(Palette, Widget);
    Result := QPalette_brush(Palette, Group, Role);
  finally
    QPalette_destroy(Palette);
  end;
end;

procedure TBrush.SetColor(const Value: TColor);
var
  QC: QColorH;
  LHandle: QBrushH;
  LBrushStyle: Qt.BrushStyle;
begin
  if Value <> Color then
  begin
    FColor := Value;
    LHandle := BrushFromColor(Value);
    if LHandle <> nil then
    begin
      LBrushStyle := QBrush_style(Handle);
      FreeHandle;
      FHandle := QBrush_create(LHandle);
      if (LBrushStyle <> BrushStyle_CustomPattern) and
        (LBrushStyle <> QBrush_style(LHandle)) then
        QBrush_setStyle(FHandle, LBrushStyle);
      FOwned := True;
    end
    else
    begin
      QC := QColor(Value);
      try
        QBrush_setColor(FHandle, QC);
      finally
        QColor_destroy(QC);
      end;
    end;
    Changed;
  end;
end;

procedure TBrush.SetHandle(const Value: QBrushH);
begin
  if Value <> Handle then
  begin
    if not Assigned(Value) then
      InvalidHandle(ClassName);
    FreeHandle;
    FHandle := Value;
    FOwned := False;
    Changed;
  end;
end;

procedure TBrush.SetStyle(const Value: TBrushStyle);
begin
  if Value <> Style then
  begin
    QBrush_setStyle(FHandle, QtBrushStyle[Value]);
    Changed;
  end;
end;

function TBrush.ReleaseHandle: QBrushH;
begin
  Result := FHandle;
  FHandle := QBrush_create(FHandle);
  FOwned := True;
end;

procedure TBrush.OwnHandle;
begin
  FOwned := True;
end;

{ TFontRecall }

constructor TFontRecall.Create(AFont: TFont);
begin
  inherited Create(TFont.Create, AFont);
end;

{ TPenRecall }

constructor TPenRecall.Create(APen: TPen);
begin
  inherited Create(TPen.Create, APen);
end;

{ TBrushRecall }

constructor TBrushRecall.Create(ABrush: TBrush);
begin
  inherited Create(TBrush.Create, ABrush);
end;

{ TCanvas }

const
  CopyModeToRasterOp: array[TCopyMode] of RasterOp = (
    {cmBlackness}   RasterOp_ClearROP,    {cmDstInvert}  RasterOp_NotROP,
    {cmMergeCopy}   RasterOp_AndROP,      {cmMergePaint} RasterOP_NotOrROP,
    {cmNotSrcCopy}  RasterOp_NotCopyROP,  {cmNotSrcErase}RasterOp_NorROP,
    {cmPatCopy}     RasterOp_NopROP,      {cmPatInvert}  RasterOp_NopROP,
    {cmPatPaint}    RasterOp_NotOrROP,    {cmSrcAnd}     RasterOp_AndROP,
    {cmSrcCopy}     RasterOp_CopyROP,     {cmSrcErase}   RasterOp_AndNotROP,
    {cmSrcInvert}   RasterOp_XorROP,      {cmSrcPaint}   RasterOP_OrROP,
    {cmWhiteness}   RasterOp_SetROP,      {cmCreateMask} RasterOp_NopROP);

procedure TCanvas.Arc(X1, Y1, X2, Y2, X3, Y3, X4, Y4: Integer);
var
  Width, Height: Integer;
  CenterX, CenterY: Integer;
  Theta: Extended;
  Theta2: Extended;
begin
  Width := X2-X1;
  Height := Y2-Y1;

  CenterX := X1+(Width div 2);
  CenterY := Y1+(Height div 2);
  Theta := RadToDeg(ArcTan2(-1*(Y3-CenterY), X3-CenterX));
  Theta2 := RadToDeg(ArcTan2(-1*(Y4-CenterY), X4-CenterX));
  Arc(X1, Y1, Width, Height, Trunc(Theta) shl 4, Trunc(Theta2 - Theta) shl 4);
end;

procedure TCanvas.Arc(X, Y, W, H, Angle, AngleLength: Integer);
begin
  Changing;
  Start;
  try
    RequiredState([csHandleValid, csPenValid, csBrushValid]);
    QPainter_drawArc(Handle, X, Y, W, H, Angle, AngleLength);
  finally
    Stop;
  end;
  Changed;
end;

procedure TCanvas.BrushChanged(Sender: TObject);
begin
  if CopyMode = cmCreateMask then (Sender as TBrush).Color := clDontMask;
  Exclude(State, csBrushValid);
end;

procedure TCanvas.Chord(X1, Y1, X2, Y2, X3, Y3, X4, Y4: Integer);
var
  Width, Height: Integer;
  CenterX, CenterY: Integer;
  Theta: Extended;
  Theta2: Extended;
begin
  Width := X2-X1;
  Height := Y2-Y1;

  CenterX := X1+(Width div 2);
  CenterY := Y1+(Height div 2);
  Theta := RadToDeg(ArcTan2(-1*(Y3-CenterY), X3-CenterX));
  Theta2 := RadToDeg(ArcTan2(-1*(Y4-CenterY), X4-CenterX));
  Chord(X1, Y1, Width, Height, Trunc(Theta) shl 4, Trunc(Theta2 - Theta) shl 4);
end;

procedure TCanvas.Changed;
begin
  if Assigned(FOnChange) then
    FOnChange(Self);
end;

procedure TCanvas.Changing;
begin
  if Assigned(FOnChanging) then
    FOnChanging(Self);
end;

procedure TCanvas.Chord(X, Y, W, H, Angle, AngleLength: Integer);
begin
  Changing;
  Start;
  try
    RequiredState([csHandleValid, csPenValid, csBrushValid]);
    QPainter_drawChord(Handle, X, Y, W, H, Angle, AngleLength);
  finally
    Stop;
  end;
  Changed;
end;

constructor TCanvas.Create;
begin
  inherited Create;
  InitializeCriticalSection(FLock);
  FFont := TFont.Create;
  FFont.OnChange := FontChanged;
  FPen := TPen.Create;
  FPen.OnChange := PenChanged;
  FBrush := TBrush.Create;
  FBrush.OnChange := BrushChanged;
  FCopyMode := cmSrcCopy;
  State := [];
end;

procedure TCanvas.CreateBrush;
begin
  QPainter_setBrush(FHandle, FBrush.Handle);
end;

procedure TCanvas.CreateFont;
begin
  QPainter_setFont(FHandle, FFont.Handle);
  QPainter_setPen(FHandle, FFont.FontPen);
  Exclude(State, csPenValid);
end;

procedure TCanvas.CreateHandle;
begin
  { Should be overridden by ancestor or SetHandle should be called. }
  FHandle := nil;
end;

procedure TCanvas.CreatePen;
const
  PenModeToRasterOp: array[TPenMode] of RasterOp = (
    {pmBlack}       RasterOp_ClearROP,  {pmWhite}      RasterOp_SetROP,
    {pmNop}         RasterOp_NopROP,    {pmNot}        RasterOp_NotROP,
    {pmCopy}        RasterOp_CopyROP,   {pmNotCopy}    RasterOp_NotCopyROP,
    {pmMergePenNot} RasterOp_NotOrROP,  {pmMaskPenNot} RasterOp_NotAndROP,
    {pmMergeNotPen} RasterOp_OrNotROP,  {pmMaskNotPen} RasterOp_AndNotROP,
    {pmMerge}       RasterOp_OrROP, 	{pmNotMerge}   RasterOp_NorROP,
    {pmMask}        RasterOp_AndROP,    {pmNotMask}    RasterOp_NandROP,
    {pmXor}         RasterOp_XorROP,    {pmNotXor}     RasterOp_NotXorROP);
begin
  QPainter_setPen(FHandle, FPen.Handle);
  { Set rasterop based on the pen mode }
  QPainter_setRasterOp(FHandle, PenModeToRasterOp[FPen.Mode]);
  Exclude(State, csFontValid);
end;

destructor TCanvas.Destroy;
begin
  DeleteCriticalSection(FLock);
  FPen.Free;
  FBrush.Free;
  FFont.Free;
  if Assigned(FHandle) then
    QPainter_destroy(FHandle);
  inherited Destroy;
end;

procedure TCanvas.CopyRect(const Dest: TRect; Canvas: TCanvas;
  const Source: TRect);
begin
  Changing;
  Start;
  try
    Canvas.Start;
    try
      RequiredState([csHandleValid, csFontValid, csBrushValid]);
      Canvas.RequiredState([csHandleValid, csBrushValid]);
      bitBlt(QPainter_device(Handle), Dest.Left, Dest.Top,
        QPainter_device(Canvas.Handle), Source.Left, Source.Top,
        Source.Right - Source.Left, Source.Bottom - Source.Top,
        CopyModeToRasterOp[CopyMode], False);
    finally
      Canvas.Stop;
    end;
  finally
    Stop;
  end;
  Changed;
end;

procedure TCanvas.Draw(X, Y: Integer; Graphic: TGraphic);
var
  SaveROP: RasterOp;
begin
  if (Graphic <> nil) and not Graphic.Empty then
  begin
    Changing;
    Start;
    try
      RequiredState([csHandleValid]);
      SaveROP := QPainter_rasterOp(FHandle);
      if SaveROP <> CopyModeToRasterOp[FCopyMode] then
        QPainter_setRasterOp(FHandle, CopyModeToRasterOp[FCopyMode]);
      try
        Graphic.Draw(Self, Bounds(X, Y, Graphic.Width, Graphic.Height));
      finally
        QPainter_setRasterOp(FHandle, SaveROP);
      end;
    finally
      Stop;
    end;
    Changed;
  end;
end;

procedure TCanvas.DrawFocusRect(const Rect: TRect);
begin
  Changing;
  Start;
  try
    RequiredState([csHandleValid, csPenValid, csBrushValid]);
    QPainter_drawWinFocusRect(Handle, @Rect);
  finally
    Stop;
  end;
  Changed;
end;

procedure TCanvas.DrawPoint(X, Y: Integer);
begin
  Changing;
  Start;
  try
    RequiredState([csHandleValid, csPenValid, csBrushValid]);
    QPainter_drawPoint(Handle, X, Y);
  finally
    Stop;
  end;
  Changed;
end;

procedure TCanvas.DrawPoint(const Point: TPoint);
begin
  DrawPoint(Point.X, Point.y);
end;

function PointArrayOf(const Points: array of TPoint; var TempPoints: TPointArray): PPointArray;
var
  I: Integer;
begin
  SetLength(TempPoints, High(Points) + 1);
  for I := Low(Points) to High(Points) do
    TempPoints[I] := Points[I];
  Result := @TempPoints[0];
end;

procedure TCanvas.DrawPoints(const Points: array of TPoint);
var
  TempPoints: TPointArray;
begin
  Changing;
  Start;
  try
    RequiredState([csHandleValid, csPenValid]);
    QPainter_drawPoints(Handle, PointArrayOf(Points, TempPoints), 0, -1);
  finally
    Stop;
  end;
  Changed;
end;

procedure TCanvas.Ellipse(const Rect: TRect);
begin
  Changing;
  Start;
  try
    RequiredState([csHandleValid, csPenValid, csBrushValid]);
    QPainter_drawEllipse(Handle, @Rect);
  finally
    Stop;
  end;
  Changed;
end;

procedure TCanvas.Ellipse(X1, Y1, X2, Y2: Integer);
begin
  Ellipse(Rect(X1, Y1, X2, Y2));
end;

procedure TCanvas.FillRect(const Rect: TRect);
begin
  Changing;
  Start;
  try
    RequiredState([csHandleValid, csBrushValid]);
    QPainter_fillRect(Handle, @Rect, Brush.Handle);
  finally
    Stop;
  end;
  Changed;
end;

procedure TCanvas.FontChanged(Sender: TObject);
begin
  Exclude(State, csFontValid);
end;

function TCanvas.GetClipRect: TRect;
var
  ClipRegion: QRegionH;
begin
  ClipRegion := GetClipRegion;
  QRegion_boundingRect(ClipRegion, @Result);
end;

function TCanvas.GetClipRegion: QRegionH;
begin
  Result := QPainter_clipRegion(Handle);
end;

function TCanvas.GetHandle: QPainterH;
begin
  RequiredState([csHandleValid]);
  Result := FHandle;
end;

function TCanvas.GetPenPos: TPoint;
begin
  Result := FPenPos;
end;

procedure TCanvas.LineTo(X, Y: Integer);
begin
  Changing;
  Start;
  try
    RequiredState([csHandleValid, csPenValid]);
    QPainter_lineTo(Handle, X, Y);
    FPenPos.X := X;
    FPenPos.Y := Y;
  finally
    Stop;
  end;
  Changed;
end;

procedure TCanvas.Lock;
begin
  InterlockedIncrement(FLockCount);
  EnterCriticalSection(FLock);
  Start;
end;

procedure TCanvas.MoveTo(X, Y: Integer);
begin
  if csHandleValid in State then
    QPainter_moveTo(Handle, X, Y);
  FPenPos := Point(X, Y);
end;

procedure TCanvas.PenChanged(Sender: TObject);
begin
  if CopyMode = cmCreateMask then (Sender as TPen).Color := clDontMask;
  Exclude(State, csPenValid);
end;

procedure TCanvas.Pie(X1, Y1, X2, Y2, X3, Y3, X4, Y4: Integer);
var
  Width, Height: Integer;
  CenterX, CenterY: Integer;
  Theta: Extended;
  Theta2: Extended;
begin
  Width := X2 - X1;
  Height := Y2 - Y1;
  CenterX := X1 + (Width div 2);
  CenterY := Y1 + (Height div 2);
  Theta := RadToDeg(ArcTan2(-1 * (Y3 - CenterY), X3 - CenterX));
  Theta2 := RadToDeg(ArcTan2(-1 * (Y4 - CenterY), X4 - CenterX));
  Pie(X1, Y1, Width, Height, Trunc(Theta) shl 4, Trunc(Theta2 - Theta) shl 4);
end;

procedure TCanvas.Pie(X, Y, W, H, Angle, AngleLength: Integer);
begin
  Changing;
  Start;
  try
    RequiredState([csHandleValid, csPenValid, csBrushValid]);
    QPainter_drawPie(Handle, X, Y, W, H, Angle, AngleLength);
  finally
    Stop;
  end;
  Changed;
end;

procedure TCanvas.PolyBezier(const Points: array of TPoint; StartIndex: Integer = 0);
var
  TempPoints: TPointArray;
begin
  Changing;
  Start;
  try
    RequiredState([csHandleValid, csPenValid, csBrushValid]);
    QPainter_drawQuadBezier(Handle, PointArrayOf(Points, TempPoints), StartIndex);
  finally
    Stop;
  end;
  Changed;
end;

procedure TCanvas.PolyBezierTo(const Points: array of TPoint; StartIndex: Integer = 0);
var
  Pt: TPoint;
begin
  PolyBezier(Points, StartIndex);
  Pt := Points[High(Points)];
  MoveTo(Pt.X, Pt.Y);
end;

procedure TCanvas.Polygon(const Points: array of TPoint;
  Winding: Boolean = False; StartIndex: Integer = 0; NumPts: Integer = -1);
var
  TempPoints: TPointArray;
begin
  Changing;
  Start;
  try
    RequiredState([csHandleValid, csPenValid, csBrushValid]);
    QPainter_drawPolygon(Handle, PointArrayOf(Points, TempPoints), Winding,
      StartIndex, NumPts);
  finally
    Stop;
  end;
  Changed;
end;

procedure TCanvas.Polyline(const Points: array of TPoint;
  StartIndex: Integer = 0; NumPts: Integer = -1);
var
  TempPoints: TPointArray;
begin
  Changing;
  Start;
  try
    RequiredState([csHandleValid, csPenValid]);
    QPainter_drawPolyline(Handle, PointArrayOf(Points, TempPoints), StartIndex,
      NumPts);
  finally
    Stop;
  end;
  Changed;
end;

procedure Swap(var A, B: Integer);
var
  T: Integer;
begin
  T := A;
  A := B;
  B := T;
end;

procedure TCanvas.Rectangle(X1, Y1, X2, Y2: Integer);
begin
  Changing;
  Start;
  try
    RequiredState([csHandleValid, csPenValid, csBrushValid]);
    if X2 < X1 then
      Swap(X1, X2);
    if Y2 < Y1 then
      Swap(Y1, Y2);
    QPainter_drawRect(Handle, X1, Y1, X2 - X1, Y2 - Y1);
  finally
    Stop;
  end;
  Changed;
end;

procedure TCanvas.Rectangle(const Rect: TRect);
begin
  Changing;
  Start;
  try
    RequiredState([csHandleValid, csPenValid, csBrushValid]);
    QPainter_drawRect(Handle, @Rect);
  finally
    Stop;
  end;
  Changed;
end;

procedure TCanvas.Refresh;
begin
  if (FHandle <> nil) and (State - [csPenValid, csBrushValid, csFontValid] <> State) then
  begin
    FPen.Handle := GetEmptyQPen;
    FBrush.Handle := GetEmptyQBrush;
    FFont.Handle := GetEmptyQFont;

    State := State - [csFontValid, csPenValid, csBrushValid];
  end;
end;

function TCanvas.ReleaseHandle: QPainterH;
begin
  Result := FHandle;
  Handle := nil;
end;

procedure TCanvas.RequiredState(ReqState: TCanvasState);
var
  NeededState: TCanvasState;
begin
  NeededState := ReqState - State;
  if NeededState <> [] then
  begin
    if NeededState = [csFontValid, csPenValid] then
      InvalidOperation(@SInvalidCanvasState);
    if csHandleValid in NeededState then
    begin
      CreateHandle;
      if FHandle = nil then
        InvalidOperation(@SNoCanvasHandle);
    end;
    if csFontValid in NeededState then CreateFont;
    if csPenValid in NeededState then CreatePen;
    if csBrushValid in NeededState then CreateBrush;
    State := State + NeededState;
  end;
end;

procedure TCanvas.RoundRect(X1, Y1, X2, Y2, X3, Y3: Integer);
begin
  Changing;
  Start;
  try
    RequiredState([csHandleValid, csPenValid, csBrushValid]);
    QPainter_drawRoundRect(Handle, X1, Y1, X2 - X1, Y2 - Y1, X3, Y3);
  finally
    Stop;
  end;
  Changed;
end;

procedure TCanvas.SetBrush(const Value: TBrush);
begin
  FBrush.Assign(Value);
end;

procedure TCanvas.SetClipRect(const ARect: TRect);
begin
  if FClipRegion = nil then
    FClipRegion := GetClipRegion;
  QPainter_setClipRect(Handle, @ARect);
end;

procedure TCanvas.ResetClipRegion;
begin
  if FClipRegion <> nil then
  begin
    QPainter_setClipRegion(Handle, FClipRegion);
    FClipRegion := nil;
  end;
end;

procedure TCanvas.SetFont(const Value: TFont);
begin
  FFont.Assign(Value);
end;

procedure TCanvas.SetHandle(const Value: QPainterH);
begin
  if FHandle <> Value then
  begin
    if FHandle <> nil then
    begin
      FPenPos := GetPenPos;
      FHandle := nil;
      Exclude(State, csHandleValid);
    end;
    if Value <> nil then
    begin
      State := [csHandleValid];
      FHandle := Value;
      SetPenPos(FPenPos);
    end;
  end;
end;

procedure TCanvas.SetPen(const Value: TPen);
begin
  FPen.Assign(Value);
end;

procedure TCanvas.SetPenPos(const Value: TPoint);
begin
  MoveTo(Value.X, Value.Y)
end;

procedure TCanvas.Start(FreshState: Boolean);
var
  ShouldEnd: Boolean;
begin
  if FreshState and (FStartCount = 0) then
  begin
    RequiredState([csHandleValid]);
    ShouldEnd := not QPainter_isActive(FHandle);
    BeginPainting;
    FNeedsEnd := ShouldEnd;
    MoveTo(FPenPos.X, FPenPos.Y);
    State := State - [csFontValid, csPenValid, csBrushValid];
  end;
  Inc(FStartCount);
end;

procedure TCanvas.Stop;
begin
  if FStartCount <= 0 then Exit;
  Dec(FStartCount);
  if (FStartCount = 0) and Assigned(FHandle) and QPainter_isActive(FHandle) and FNeedsEnd then
  begin
    FNeedsEnd := False;
    QPainter_end(FHandle);
  end;
end;

procedure TCanvas.StretchDraw(const Rect: TRect; Graphic: TGraphic);
begin
  if (Graphic <> nil) and not Graphic.Empty then
  begin
    Changing;
    Start;
    try
      RequiredState([csHandleValid]);
      Graphic.Draw(Self, Rect);
    finally
      Stop;
    end;
    Changed;
  end;
end;

procedure TCanvas.TextExtent(const Text: WideString; var Rect: TRect;
  const Flags: Integer);
begin
  Start;
  try
    RequiredState([csHandleValid, csFontValid]);
    QPainter_boundingRect(Handle, @Rect, @Rect, Flags, PWideString(@Text), -1,
      nil);
  finally
    Stop;
  end;
end;

function TCanvas.TextExtent(const Text: WideString; const Flags: Integer): TSize;
var
  Temp: TRect;
begin
  Temp := Rect(0, 0, MaxLongInt, MaxLongInt);
  TextExtent(Text, Temp, Flags);
  Result.CX := Temp.Right - Temp.Left;
  Result.CY := Temp.Bottom - Temp.Top;
end;

function TCanvas.TextHeight(const Text: WideString): Integer;
begin
  Result := TextExtent(Text, 0).CY;
end;

procedure TCanvas.TextOut(X, Y: Integer; const Text: WideString);
var
  R: TRect;
begin
  Changing;
  Start;
  try
    RequiredState([csHandleValid, csFontValid]);
    case TextAlign of
      taTop:
        begin
          R := Rect(X, Y, High(Word), High(Word));
          QPainter_drawText(Handle, @R, 0, PWideString(@Text), -1, nil, nil);
        end;
      taBottom:
        QPainter_drawText(Handle, X, Y, PWideString(@Text), -1);
    end;
  finally
    Stop;
  end;
  Changed;
end;

procedure TCanvas.TextRect(Rect: TRect; X, Y: Integer; const Text: WideString;
  TextFlags: Integer = 0);
var
  R: TRect;
begin
  Changing;
  Start;
  try
    R.Left := X;
    R.Top := Y;
    R.Right := Rect.Right;
    R.Bottom := Rect.Bottom;
    RequiredState([csHandleValid, csFontValid]);
    QPainter_drawText(Handle, @R, TextFlags, PWideString(@Text), -1, @Rect,
      nil);
  finally
    Stop;
  end;
  Changed;
end;

function TCanvas.TextWidth(const Text: WideString): Integer;
begin
  Result := TextExtent(Text, 0).CX;
end;

procedure TCanvas.TiledDraw(const Rect: TRect; Graphic: TGraphic);
begin
  if (Graphic <> nil) and not Graphic.Empty then
  begin
    Changing;
    Start;
    try
      RequiredState([csHandleValid]);
      Graphic.TiledDraw(Self, Rect);
    finally
      Stop;
    end;
    Changed;
  end;
end;

function TCanvas.TryLock: Boolean;
begin
  EnterCriticalSection(CounterLock);
  try
    Result := FLockCount = 0;
    if Result then Lock;
  finally
    LeaveCriticalSection(CounterLock);
  end;
end;

procedure TCanvas.Unlock;
begin
  LeaveCriticalSection(FLock);
  InterlockedDecrement(FLockCount);
  Stop;
end;

procedure TCanvas.BeginPainting;
begin
  InvalidOperation(@SNoCanvasHandle);
end;

{ TBitmapCanvas }

procedure TBitmapCanvas.BeginPainting;
begin
  if not QPainter_isActive(Handle) then
    if not QPainter_begin(Handle, FBitmap.Handle) then
      InvalidOperation(@SInvalidCanvasState);
end;

constructor TBitmapCanvas.Create(Bitmap: TBitmap);
begin
  inherited Create;
  FBitmap := Bitmap;
end;

procedure TBitmapCanvas.CreateHandle;
begin
  Handle := QPainter_create;
end;

{ TBitmap }

class function TBitmap.AssignsTo(Dest: TGraphicClass): Boolean;
begin
  Result := inherited AssignsTo(Dest);// or Dest.InheritsFrom(TIcon);
end;

procedure TBitmap.AssignTo(Dest: TPersistent);
begin
  if Dest is TIcon then
  begin
    TIcon(Dest).FMemoryImage.Position := 0;
    SaveToStream(TIcon(Dest).FMemoryImage);
    TIcon(Dest).NewImage;
  end
  else
    inherited AssignTo(Dest);
end;

procedure TBitmap.Assign(Source: TPersistent);
begin
  if (Source = nil) or (Source is TBitmap) then
  begin
    FreeImage;
    FreePixmap;
    if Source <> nil then
    begin
      if (TBitmap(Source).FImage = nil) and (TBitmap(Source).FPixmap = nil) then
      begin
        FHeight := TBitmap(Source).FHeight;
        FWidth := TBitmap(Source).FWidth;
      end else
      begin
        if TBitmap(Source).FImage <> nil then
          FImage := QImage_create(TBitmap(Source).FImage);
        if TBitmap(Source).FPixmap <> nil then
          FPixmap := QPixmap_create(TBitmap(Source).FPixmap);
      end;
    end;
    Changed(Self);
  end
  else
    if Source is TIcon then
      Assign(TIcon(Source).FBitmap)
  else
    inherited Assign(Source);
end;

function TBitmap.ColorTable: Pointer;
begin
  Result := nil;
  ImageNeeded;
  if FImage <> nil then
    Result := QImage_colorTable(FImage);
end;

constructor TBitmap.Create;
begin
  inherited Create;
  FFormat := 'BMP';
  FTransparentColor := clDefault;
  FTransparentMode := tmAuto;
  FPixelFormat := pf32bit;
end;

destructor TBitmap.Destroy;
begin
  FreeImage;
  FreePixmap;
  FCanvas.Free;
  inherited Destroy;
end;

procedure TBitmap.Changing(Sender: TObject);
begin
  HandleNeeded;
  FreeImage;
end;

procedure TBitmap.Dormant;
begin
  ImageNeeded;
  FreePixmap;
end;

procedure TBitmap.Draw(ACanvas: TCanvas; const Rect: TRect);
var
  NewMatrix: QWMatrixH;
begin
  ACanvas.RequiredState([csHandleValid]);
  HandleNeeded;
  if (Rect.Right - Rect.Left <> Width) or
    (Rect.Bottom - Rect.Top <> Height) then
  begin
    // Image must be scaled
    QPainter_saveWorldMatrix(ACanvas.Handle);
    try
      NewMatrix:= QWMatrix_create( (Rect.Right - Rect.Left) / Width ,
        0, 0, (Rect.Bottom - Rect.Top) / Height, Rect.Left, Rect.Top );
      try
        QPainter_setWorldMatrix(ACanvas.Handle, NewMatrix, True);
        QPainter_drawPixmap(ACanvas.Handle, 0, 0, FPixmap, 0, 0, Width, Height);
      finally
        QWMatrix_destroy(NewMatrix);
      end;
    finally
      QPainter_restoreWorldMatrix(ACanvas.Handle);
    end;
  end
  else
    QPainter_drawPixmap(ACanvas.Handle, Rect.Left, Rect.Top, FPixmap, 0, 0,
      Rect.Right - Rect.Left, Rect.Bottom - Rect.Top);
end;

procedure TBitmap.FreeImage;
begin
  if FImage <> nil then
  begin
    QImage_destroy(FImage);
    FImage := nil;
    FreeAndNil(FStream);
  end;
end;

procedure TBitmap.FreePixmap;
begin
  if FPixmap <> nil then
  begin
    QPixmap_destroy(FPixmap);
    FPixmap := nil;
  end;
end;

function TBitmap.GetCanvas: TCanvas;
begin
  if FCanvas = nil then
  begin
    FCanvas := TBitmapCanvas.Create(Self);
    FCanvas.OnChanging := Changing;
    FCanvas.OnChange := Changed;
  end;
  Result := FCanvas;
end;

function TBitmap.GetEmpty: Boolean;
begin
  Result := ((FPixmap = nil) or QPixmap_isNull(FPixmap)) and
    ((FImage = nil) or QImage_isNull(FImage));
end;

function TBitmap.GetHandle: QPixmapH;
begin
  HandleNeeded;
  Result := FPixmap;
end;

function TBitmap.GetHeight: Integer;
begin
  if (FPixmap <> nil) and not QPixmap_isNull(FPixmap) then
    Result := QPixmap_height(FPixmap)
  else if (FImage <> nil) and not QImage_isNull(FImage) then
    Result := QImage_height(FImage)
  else
    Result := FHeight;
end;

function TBitmap.GetMonochrome: Boolean;
begin
  if FPixmap <> nil then
    Result := QPixmap_isQBitmap(FPixmap)
  else if FImage <> nil then
    Result := PixelFormat = pf1bit
  else
    Result := False;
end;

function TBitmap.GetPixelFormat: TPixelFormat;
var
  Depth: Integer;
begin
  ImageNeeded;
  if FImage <> nil then
  begin
    Depth := QImage_depth(FImage);
    case Depth of
      1: Result := pf1bit;
      8: Result := pf8bit;
      16: Result := pf16bit;
      32: Result := pf32bit;
    else
      Result := pfCustom;
    end;
  end
  else
    Result := FPixelFormat;
end;

const
  PixelFormatMap: array[pf1bit..pf32bit] of Integer = (1, 8, 16, 32);

procedure TBitmap.SetPixelFormat(const Value: TPixelFormat);
var
  NewImage: QImageH;
  Format: TPixelFormat;
begin
  Format := GetPixelFormat;
  if Value = Format then Exit;
  if Format = pfCustom then
    InvalidGraphic(@SInvalidPixelFormat);
{$IFDEF MSWINDOWS}
  // Qt for Windows does not support 16 bit images yet.
  // This should be removed once the support is added.
  if Format = pf16bit then
    InvalidGraphic(@SInvalidPixelFormat);
{$ENDIF}
  FPixelFormat := Value;
  ImageNeeded;
  HandleNeeded;
  if FImage <> nil then
  begin
    NewImage := QImage_create;
    QImage_convertDepth(FImage, NewImage, PixelFormatMap[Value]);
    QImage_destroy(FImage);
    FImage := NewImage;
    QPixmap_convertFromImage(FPixmap, FImage, QPixmapColorMode(QPixmapColorMode_Auto));
    Changed(Self);
  end;
end;

function TBitmap.GetScanLine(Row: Integer): Pointer;
begin
  if (Row < 0) or (Row > Height) then
    InvalidOperation(@SScanLine);
  ImageNeeded;
  FreePixmap;
  if FImage <> nil then
    Result := QImage_scanLine(FImage, Row)
  else Result := nil;
end;


function TBitmap.GetWidth: Integer;
begin
  if (FPixmap <> nil) and not QPixmap_isNull(FPixmap) then
    Result := QPixmap_width(FPixmap)
  else if (FImage <> nil) and not QImage_isNull(FImage) then
    Result := QImage_width(FImage)
  else
    Result := FWidth;
end;

procedure TBitmap.HandleNeeded;
begin
  if FPixmap = nil then
    if FImage <> nil then
    begin
      FPixmap := QPixmap_create;
      QPixmap_convertFromImage(FPixmap, FImage, QPixmapColorMode(QPixmapColorMode_Auto));
    end
    else
    begin
      FPixmap := QPixmap_create(FWidth, FHeight, -1, QPixmapOptimization_DefaultOptim);
      if (FWidth > 0) and (FHeight > 0) then
        Canvas.FillRect(Rect(0, 0, FWidth, FHeight));
    end;
end;

procedure TBitmap.ImageNeeded;
begin
  if FImage = nil then
    if FPixmap <> nil then
    begin
      FImage := QImage_create;
      QPixmap_convertToImage(FPixmap, FImage);
    end
    else if (FWidth > 0) and (FHeight > 0) then
      FImage := QImage_create(FWidth, FHeight, PixelFormatMap[FPixelFormat], 0,
        QImageEndian_IgnoreEndian);
end;

procedure TBitmap.LoadFromStream(Stream: TStream);
var
  IO: QImageIOH;
  Device: QIODeviceH;
  P, S: Int64;
begin
  FreeImage;
  FreePixmap;
  if Stream.Size - Stream.Position > 0 then
  begin
    P := Stream.Position;
    Device := IODeviceFromStream(Stream);
    Format := QImageIO_imageFormat(Device);
    IO := QImageIO_create(Device, PChar(Format));
    try
      if not QImageIO_read(IO) then InvalidOperation(@SUnknownImageFormat);
      FImage := QImage_create(QImageIO_image(IO));
      if FTransparent then Mask(FTransparentColor);
    finally
      QImageIO_destroy(IO);
    end;
    if ExactBitmaps and (P <> Stream.Position) then
    begin
      // Preserve the exact bytes we read.
      S := Stream.Position - P;
      FStream := TMemoryStream.Create;
      Stream.Position := P;
      FStream.CopyFrom(Stream, S);
      Assert(Stream.Position = P + S);
    end;
  end;
  Changed(Self);
end;

type
  TColorTable = array[0..MaxInt div SizeOf(QRgb)-1] of QRgb;
  PColorTable = ^TColorTable;
  TIntArray = array[0..MaxInt div SizeOf(QRgb)-1] of Integer;
  PIntArray = ^TIntArray;

procedure TBitmap.Mask(TransparentColor: TColor);
var
  MaskImage: QImageH;
  MaskBitmap: QBitmapH;
  X, Y: Integer;
  C, TC: QRgb;
  Black,
  White: QRgb;
  SLImage32: PIntArray;
  SLImage,
  SLMask: PByteArray;
  ColorTable: PColorTable;
  TCColor: QColorH;
begin
  ImageNeeded;
  if FImage = nil then Exit; // Not enough information to create one.
  Black := clDontMask;
  White := clMask;
  MaskImage := QImage_create(Width, Height, 8, 2, QImageEndian_IgnoreEndian);
  try
    if TransparentColor = clDefault then
      QImage_pixel(FImage, @TC, 0, Height - 1)
    else
    begin
      TCColor := QColor(TransparentColor);
      try
        QColor_rgb(TCColor, @TC);
      finally
        QColor_destroy(TCColor);
      end;
    end;
    TC := TC and clMask;
    QImage_setColor(MaskImage, 0, @QRgb(Black));
    QImage_setColor(MaskImage, 1, @QRgb(White));
    case PixelFormat of
      pf1bit:
        begin
          ColorTable := PColorTable(QImage_colorTable(FImage));
          if QImage_bitOrder(FImage) = QImageEndian_LittleEndian then
          begin
            for Y := 0 to Height - 1 do
            begin
              SLImage := PByteArray(QImage_scanLine(FImage, Y));
              SLMask := PByteArray(QImage_scanLine(MaskImage, Y));
              for X := 0 to Width - 1 do
              begin
                C := ColorTable[(SLImage[x div 8] and (1 shl (x and 7))) shr (x mod 8)];
                SLMask[x] := Ord((C and clMask) = TC);
              end;
            end;
          end
          else
          begin
            for Y := 0 to Height - 1 do
            begin
              SLImage := PByteArray(QImage_scanLine(FImage, Y));
              SLMask := PByteArray(QImage_scanLine(MaskImage, Y));
              for X := 0 to Width - 1 do
              begin
                C := ColorTable[(SLImage[x div 8] and (1 shl (7 - x and 7))) shr (7 - (x mod 8))];
                SLMask[x] := Ord((C and clMask) = TC);
              end;
            end;
          end;
        end;
      pf8bit: //pf16bit??
        begin
          ColorTable := PColorTable(QImage_colorTable(FImage));
          for Y := 0 to Height - 1 do
          begin
            SLImage := PByteArray(QImage_scanLine(FImage, Y));
            SLMask := PByteArray(QImage_scanLine(MaskImage, Y));
            for X := 0 to Width - 1 do
            begin
              C := ColorTable[SLImage[x]];
              SLMask[x] := Ord((C and clMask) = TC);
            end;
          end;
        end;
      pf32bit:
        begin
          for Y := 0 to Height - 1 do
          begin
            SLImage32 := PIntArray(QImage_scanLine(FImage, Y));
            SLMask := PByteArray(QImage_scanLine(MaskImage, Y));
            for X := 0 to Width - 1 do
            begin
              C := QRgb(SLImage32[x]);
              SLMask[x] := Ord((C and clMask) = TC);
            end;
          end;
        end;
    else
      InvalidOperation(@SInvalidColorDepth);
    end;
    MaskBitmap := QBitmap_create(Width, Height, True, QPixmapOptimization_NoOptim);
    try
      QPixmap_convertFromImage(MaskBitmap, MaskImage, QPixmapColorMode_Mono);
      QPixmap_setMask(Handle, MaskBitmap);
    finally
      QBitmap_destroy(MaskBitmap);
    end;
  finally
    QImage_destroy(MaskImage);
  end;
end;

procedure LoadBitmapFromResourceStream(ABitmap: TBitmap;
  ResourceStream: TCustomMemoryStream);
var
  TmpStream: TMemoryStream;
  Header: TBitmapFileHeader;
  BmpHeader: TBitMapInfoHeader;
begin
  TmpStream := TMemoryStream.Create;
  try
    // Reads bitmap header
    ResourceStream.ReadBuffer(BmpHeader, SizeOf(BmpHeader));
    ResourceStream.Seek(0, soBeginning);

    // Builds file header
    FillChar(Header, SizeOf(Header), 0);
    Header.bfType := $4D42;
    Header.bfSize := ResourceStream.Size;
    Header.bfReserved1 := 0;
    Header.bfReserved2 := 0;

    if BmpHeader.biBitCount > 8 then
      Header.bfOffBits := sizeof(Header) + sizeof(BmpHeader)
    else
      if BmpHeader.biClrUsed = 0 then
        Header.bfOffBits := sizeof(Header) + sizeof(BmpHeader) +
          (1 shl BmpHeader.biBitCount) * 4
      else
        Header.bfOffBits := sizeof(Header) + sizeof(BmpHeader) +
          BmpHeader.biClrUsed * 4;

    // Concatenates both in TmpStream
    TmpStream.WriteBuffer(Header, SizeOf(Header));
    TmpStream.CopyFrom(ResourceStream, ResourceStream.Size);
    TmpStream.Position := 0;
    ABitmap.LoadFromStream(TmpStream);
  finally
    TmpStream.Free;
  end;
end;

procedure TBitmap.LoadFromResourceName(Instance: Cardinal;
  const ResName: string);
var
  Stream: TCustomMemoryStream;
begin
  Stream := TResourceStream.Create(Instance, ResName, RT_BITMAP);
  try
    LoadBitmapFromResourceStream(Self, Stream);
  finally
    Stream.Free;
  end;
end;

procedure TBitmap.LoadFromResourceID(Instance: Cardinal; ResID: Integer);
var
  Stream: TCustomMemoryStream;
begin
  Stream := TResourceStream.CreateFromID(Instance, ResID, RT_BITMAP);
  try
    LoadBitmapFromResourceStream(Self, Stream);
  finally
    Stream.Free;
  end;
end;

procedure TBitmap.ReadData(Stream: TStream);
var
  Dummy: Integer;
begin
  //for VCL stream compatibility
  Stream.Read(Dummy, SizeOf(Dummy));
  LoadFromStream(Stream);
end;

procedure TBitmap.ResizeImage(NewWidth, NewHeight: Integer);
var
  NewImage: QImageH;
begin
  if FPixelFormat = pfCustom then
    InvalidGraphic(@SInvalidPixelFormat);
  ImageNeeded;
  FreePixmap;
  NewImage := QImage_create(NewWidth, NewHeight, PixelFormatMap[FPixelFormat],
    1, QImageEndian_IgnoreEndian);
  QImage_copy(FImage, NewImage, 0, 0, NewWidth, NewHeight, 0);
  QImage_destroy(FImage);
  FImage := NewImage;
end;

procedure TBitmap.SaveToStream(Stream: TStream);
var
  IO: QImageIOH;
begin
  if FStream <> nil then
  begin
    // If we have an exact image use that.
    FStream.Position := 0;
    Stream.CopyFrom(FStream, FStream.Size);
  end
  else
  begin
    // Otherwise ask the QImage to write out its contents.
    ImageNeeded;
    if Empty then Exit; // Nothing to write
    IO := QImageIO_create(IODeviceFromStream(Stream), nil);
    try
      ImageNeeded;
      QImageIO_setImage(IO, FImage);
      QImageIO_setFormat(IO, PChar(Format));
      if not QImageIO_write(IO) then InvalidOperation(@SUnableToWrite);
    finally
      QImageIO_destroy(IO);
    end;
  end;
end;

procedure TBitmap.SetHandle(const Value: QPixmapH);
begin
  if FPixmap <> Value then
  begin
    FreeImage;
    FreePixmap;
    FPixmap := Value;
    FHeight := GetHeight;
    FWidth := GetWidth;
  end;
end;

procedure TBitmap.SetHeight(Value: Integer);
begin
  if Value <> Height then
  begin
    if ((FPixmap <> nil) or (FImage <> nil)) and (Width <> 0) then
      ResizeImage(Width, Value)
    else
      FHeight := Value;
  end;
end;

procedure TBitmap.SetMonochrome(const Value: Boolean);
const
  Depth: array[Boolean] of Integer = (32, 1);
var
  NewImg: QImageH;
begin
  if Value <> GetMonochrome then
  begin
    HandleNeeded;
    ImageNeeded;
    if FImage = nil then
      FPixelFormat := pf1bit
    else
    begin
      NewImg := QImage_create;
      try
        QImage_convertDepth(FImage, NewImg, Depth[Value]);
        QPixmap_convertFromImage(FPixmap, NewImg, Integer(ImageConversionFlags_AutoColor));
      finally
        QImage_destroy(NewImg);
      end;
    end;
    Changed(Self);
  end;
end;

procedure TBitmap.SetWidth(Value: Integer);
begin
  if Value <> Width then
  begin
    if ((FPixmap <> nil) or (FImage <> nil)) and (Height <> 0) then
      ResizeImage(Value, Height)
    else
      FWidth := Value;
  end;
end;

procedure TBitmap.WriteData(Stream: TStream);
var
  StartPos, Size: Integer;
begin
  StartPos := Stream.Position;
  Stream.Write(StartPos, SizeOf(StartPos));
  SaveToStream(Stream);
  Size := Stream.Position - StartPos;
  Stream.Position := StartPos;
  Stream.Write(Size, SizeOf(Size));
  Stream.Position := StartPos + Size;
end;

function TBitmap.GetTransparentColor: TColor;
var
  TempColor: QColorH;
begin
  if FTransparentColor = clDefault then
  begin
    if Monochrome then
      Result := clWhite
    else begin
      ImageNeeded;
      QImage_pixel(FImage, @Result, 0, Height - 1);
      TempColor := QColor_create;
      try
        QColor_setRgb(TempColor, QRgbH(@Result));
        Result := QColorColor(TempColor);
      finally
        QColor_destroy(TempColor);
      end;
    end;
  end
  else
    Result := FTransparentColor;
end;

procedure TBitmap.SetTransparentColor(const Value: TColor);
begin
  if Value <> FTransparentColor then
  begin
    if Value = clDefault then
      FTransparentMode := tmAuto else
      FTransparentMode := tmFixed;
    FTransparentColor := Value;
    FTransparent := True;
    if not Empty then
    begin
      Mask(Value);
      Changed(Self);
    end;
  end;
end;

procedure TBitmap.SetTransparentMode(const Value: TTransparentMode);
begin
  if Value <> FTransparentMode then
    case Value of
      tmAuto: SetTransparentColor(clDefault);
      tmFixed: SetTransparentColor(GetTransparentColor);
    end;
end;

function TBitmap.TransparentColorStored: Boolean;
begin
  Result := FTransparentMode = tmFixed;
end;

procedure TBitmap.SetTransparent(Value: Boolean);
var
  NullBitmap: QBitmapH;
begin
  if Value <> FTransparent then
  begin
    inherited SetTransparent(Value);
    if FTransparent and not Empty then
      Mask(FTransparentColor)
    else begin
      NullBitmap := QBitmap_create;
      try
        QPixmap_setMask(Handle, NullBitmap);
      finally
        QBitmap_destroy(NullBitmap);
      end;
    end;
  end;
end;

function TBitmap.GetTransparent: Boolean;
begin
  Result := FTransparent;
end;

procedure TBitmap.TiledDraw(ACanvas: TCanvas; const Rect: TRect);
begin
  QPainter_drawTiledPixmap(ACanvas.Handle, Rect.Left, Rect.Top, Rect.Right -
    Rect.Left, Rect.Bottom - Rect.Top, Handle, 0, 0);
end;

procedure TBitmap.LoadFromMimeSource(MimeSource: TMimeSource);
var
  Stream: TStream;
begin
  if MimeSource.Provides(SDelphiBitmap) then
  begin
    Stream := TMemoryStream.Create;
    try
      MimeSource.SaveToStream(SDelphiBitmap, Stream);
      Stream.Position := 0;
      LoadFromStream(Stream);
    finally
      Stream.Free;
    end;
  end;
end;

procedure TBitmap.SaveToMimeSource(MimeSource: TClxMimeSource);
var
  Stream: TStream;
begin
  Stream := TMemoryStream.Create;
  try
    SaveToStream(Stream);
    Stream.Position := 0;
    MimeSource.LoadFromStream(Stream, SDelphiBitmap);
  finally
    Stream.Free;
  end;
end;

function TBitmap.ReleasePixmap: QPixmapH;
begin
  FreeImage;
  Result := FPixmap;
  FPixmap := nil;
  FHeight := 0;
  FWidth := 0;
end;

{ TGraphic }

class function TGraphic.Assigns(Source: TGraphicClass): Boolean;
begin
  Result := Source.AssignsTo(Self);
end;

class function TGraphic.AssignsTo(Dest: TGraphicClass): Boolean;
begin
  Result := Dest.InheritsFrom(Self);
end;

procedure TGraphic.Changed(Sender: TObject);
begin
  FModified := True;
  if Assigned(FOnChange) then
    FOnChange(Self);
end;

constructor TGraphic.Create;
begin
  inherited Create;
end;

procedure TGraphic.DefineProperties(Filer: TFiler);

  function DoWrite: Boolean;
  begin
    if Filer.Ancestor <> nil then
      Result := not (Filer.Ancestor is TGraphic) or
        not Equals(TGraphic(Filer.Ancestor))
    else
      Result := not Empty;
  end;

begin
  Filer.DefineBinaryProperty('Data', ReadData, WriteData, DoWrite);
end;

function TGraphic.Equals(Graphic: TGraphic): Boolean;
var
  MyImage, GraphicsImage: TMemoryStream;
begin
  Result := (Graphic <> nil) and (ClassType = Graphic.ClassType);
  if Empty or Graphic.Empty then
  begin
    Result := Empty and Graphic.Empty;
    Exit;
  end;
  if Result then
  begin
    MyImage := TMemoryStream.Create;
    try
      WriteData(MyImage);
      GraphicsImage := TMemoryStream.Create;
      try
        Graphic.WriteData(GraphicsImage);
        Result := (MyImage.Size = GraphicsImage.Size) and
          CompareMem(MyImage.Memory, GraphicsImage.Memory, MyImage.Size);
      finally
        GraphicsImage.Free;
      end;
    finally
      MyImage.Free;
    end;
  end;
end;

function TGraphic.GetTransparent: Boolean;
begin
  Result := False;
end;

procedure TGraphic.LoadFrom(const Filename: string);
begin
  LoadFromFile(Filename);
end;

procedure TGraphic.LoadFrom(Stream: TStream);
begin
  LoadFromStream(Stream);
end;

procedure TGraphic.LoadFromFile(const Filename: string);
var
  Stream: TStream;
begin
  Stream := TFileStream.Create(Filename, fmShareDenyNone or fmOpenRead);
  try
    LoadFromStream(Stream);
  finally
    Stream.Free;
  end;
end;

procedure TGraphic.Progress(Sender: TObject; Stage: TProgressStage;
  PercentDone: Byte; RedrawNow: Boolean; const R: TRect;
  const Msg: WideString);
begin
  // Do nothing by default
end;

procedure TGraphic.ReadData(Stream: TStream);
begin
  LoadFromStream(Stream);
end;

procedure TGraphic.SaveTo(const Filename: string);
begin
  SaveToFile(Filename);
end;

procedure TGraphic.SaveTo(Stream: TStream);
begin
  SaveToStream(Stream);
end;

procedure TGraphic.SaveToFile(const Filename: string);
var
  Stream: TStream;
begin
  Stream := TFileStream.Create(Filename, fmCreate);
  try
    SaveToStream(Stream);
  finally
    Stream.Free;
  end;
end;

procedure TGraphic.SetModified(Value: Boolean);
begin
  if Value then
    Changed(Self) else
    FModified := Value;
end;

procedure TGraphic.SetTransparent(Value: Boolean);
begin
  if FTransparent <> Value then
  begin
    FTransparent := Value;
    Changed(Self);
  end;
end;

procedure TGraphic.TiledDraw(ACanvas: TCanvas; const Rect: TRect);
var
  X, Y: Integer;
  R: TRect;
begin
  X := Rect.Left;
  while X < Rect.Right do
  begin
    Y := Rect.Top;
    R.Left := X;
    R.Right := X + Width;
    while Y < Rect.Bottom do
    begin
      R.Top := Y;
      R.Bottom := Y + Height;
      Draw(ACanvas, R);
      Y := R.Bottom;
    end;
    X := R.Right;
  end;
end;

procedure TGraphic.WriteData(Stream: TStream);
begin
  SaveToStream(Stream);
end;

type
  PFileFormat = ^TFileFormat;
  TFileFormat = record
    GraphicClass: TGraphicClass;
    Extension: string;
    Description: string;
    DescResID: Integer;
  end;

  TFileFormatsList = class(TList)
  public
    constructor Create;
    destructor Destroy; override;
    procedure Add(const Ext, Desc: string; DescID: Integer; AClass: TGraphicClass);
    function FindExt(Ext: string): TGraphicClass;
    function FindClassName(const Classname: string): TGraphicClass;
    procedure Remove(AClass: TGraphicClass);
    procedure BuildFilterStrings(GraphicClass: TGraphicClass;
      var Descriptions, Filters: string; AllFilter: Boolean = True);
  end;

constructor TFileFormatsList.Create;
begin
  inherited Create;
  Add('ico', SVIcons, 0, TIcon);
  Add('xpm', SvPixmaps, 0, TBitmap);
  Add('png', SVPNGs, 0, TBitmap);
  Add('bmp', SVBitmaps, 0, TBitmap);
  Add('ddw', SDrawings, 0, TDrawing);
end;

destructor TFileFormatsList.Destroy;
var
  I: Integer;
begin
  for I := 0 to Count-1 do
    Dispose(PFileFormat(Items[I]));
  inherited Destroy;
end;

procedure TFileFormatsList.Add(const Ext, Desc: string; DescID: Integer;
  AClass: TGraphicClass);
var
  NewRec: PFileFormat;
begin
  New(NewRec);
  with NewRec^ do
  begin
    Extension := AnsiLowerCase(Ext);
    GraphicClass := AClass;
    Description := Desc;
    DescResID := DescID;
  end;
  inherited Add(NewRec);
end;

function TFileFormatsList.FindExt(Ext: string): TGraphicClass;
var
  I: Integer;
begin
  Ext := AnsiLowerCase(Ext);
  for I := Count-1 downto 0 do
    with PFileFormat(Items[I])^ do
      if Extension = Ext then
      begin
        Result := GraphicClass;
        Exit;
      end;
  Result := nil;
end;

function TFileFormatsList.FindClassName(const ClassName: string): TGraphicClass;
var
  I: Integer;
begin
  for I := Count-1 downto 0 do
  begin
    Result := PFileFormat(Items[I])^.GraphicClass;
    if Result.ClassName = Classname then Exit;
  end;
  Result := nil;
end;

procedure TFileFormatsList.Remove(AClass: TGraphicClass);
var
  I: Integer;
  P: PFileFormat;
begin
  for I := Count-1 downto 0 do
  begin
    P := PFileFormat(Items[I]);
    if P^.GraphicClass.InheritsFrom(AClass) then
    begin
      Dispose(P);
      Delete(I);
    end;
  end;
end;

procedure TFileFormatsList.BuildFilterStrings(GraphicClass: TGraphicClass;
  var Descriptions, Filters: string; AllFilter: Boolean = True);
var
  C, I: Integer;
  P: PFileFormat;
begin
  Descriptions := '';
  Filters := '';
  C := 0;
  for I := Count-1 downto 0 do
  begin
    P := PFileFormat(Items[I]);
    if (P^.GraphicClass.InheritsFrom(GraphicClass) or
      P^.GraphicClass.Assigns(GraphicClass)) and (P^.Extension <> '') then
      with P^ do
      begin
        if C <> 0 then
        begin
          Descriptions := Descriptions + '|';
          Filters := Filters + ';';
        end;
        if (Description = '') and (DescResID <> 0) then
          Description := LoadStr(DescResID);
        FmtStr(Descriptions, '%s%s (*.%s)', [Descriptions, Description, Extension]);
        FmtStr(Filters, '%s*.%s', [Filters, Extension]);
        Inc(C);
      end;
  end;
  if (C > 1) and AllFilter then
    FmtStr(Descriptions, '%s (%s)|%s', [sAllFilter, Filters, Descriptions]);
end;

var
  FileFormats: TFileFormatsList = nil;

function GetFileFormats: TFileFormatsList;
begin
  if FileFormats = nil then FileFormats := TFileFormatsList.Create;
  Result := FileFormats;
end;

function GraphicFilter(GraphicClass: TGraphicClass; AllFilter: Boolean = True): string;
var
  Filters: string;
begin
  GetFileFormats.BuildFilterStrings(GraphicClass, Result, Filters, AllFilter);
end;

function GraphicExtension(GraphicClass: TGraphicClass): string;
var
  I: Integer;
begin
  for I := GetFileFormats.Count-1 downto 0 do
    if PFileFormat(FileFormats[I])^.GraphicClass.ClassName = GraphicClass.ClassName then
    begin
      Result := PFileFormat(FileFormats[I])^.Extension;
      Exit;
    end;
  Result := '';
end;

function GraphicFileMask(GraphicClass: TGraphicClass): string;
var
  Descriptions: string;
begin
  GetFileFormats.BuildFilterStrings(GraphicClass, Descriptions, Result);
end;

{ TPicture }

procedure TPicture.Assign(Source: TPersistent);
begin
  if Source = nil then
    SetGraphic(nil)
  else if Source is TPicture then
    SetGraphic(TPicture(Source).Graphic)
  else if Source is TGraphic then
    SetGraphic(TGraphic(Source))
  else
    inherited Assign(Source);
end;

procedure TPicture.AssignTo(Dest: TPersistent);
begin
  if Graphic is Dest.ClassType then
    Dest.Assign(Graphic)
  else
    inherited AssignTo(Dest);
end;

procedure TPicture.LoadFromStream(Stream: TStream);
begin
  Bitmap.LoadFromStream(Stream);
end;

procedure TPicture.SaveToStream(Stream: TStream);
begin
  Bitmap.SaveToStream(Stream);
end;

procedure TPicture.Changed(Sender: TObject);
begin
  if Assigned(FOnChange) then FOnChange(Self);
  { if FNotify <> nil then FNotify.Changed; }
end;

constructor TPicture.Create;
begin
  inherited Create;
  GetFileFormats;
end;

procedure TPicture.DefineProperties(Filer: TFiler);

  function DoWrite: Boolean;
  var
    Ancestor: TPicture;
  begin
    if Filer.Ancestor <> nil then
    begin
      Result := True;
      if Filer.Ancestor is TPicture then
      begin
        Ancestor := TPicture(Filer.Ancestor);
        Result := not ((Graphic = Ancestor.Graphic) or
          ((Graphic <> nil) and (Ancestor.Graphic <> nil) and
          Graphic.Equals(Ancestor.Graphic)));
      end;
    end
    else Result := Graphic <> nil;
  end;

begin
  Filer.DefineBinaryProperty('Data', ReadData, WriteData, DoWrite);
end;

destructor TPicture.Destroy;
begin
  FGraphic.Free;
  inherited Destroy;
end;

procedure TPicture.ForceType(GraphicType: TGraphicClass);
begin
  if not (Graphic is GraphicType) then
  begin
    FGraphic.Free;
    FGraphic := nil;
    FGraphic := GraphicType.Create;
    FGraphic.OnChange := Changed;
    FGraphic.OnProgress := Progress;
    Changed(Self);
  end;
end;

function TPicture.GetBitmap: TBitmap;
begin
  ForceType(TBitmap);
  Result := TBitmap(Graphic);
end;

function TPicture.GetHeight: Integer;
begin
  Result := 0;
  if FGraphic <> nil then Result := FGraphic.Height;
end;

function TPicture.GetWidth: Integer;
begin
  Result := 0;
  if FGraphic <> nil then Result := FGraphic.Width;
end;

procedure TPicture.LoadFromFile(const Filename: string);
var
  Ext: string;
  NewGraphic: TGraphic;
  GraphicClass: TGraphicClass;
begin
  Ext := ExtractFileExt(Filename);
  Delete(Ext, 1, 1);
  GraphicClass := FileFormats.FindExt(Ext);
  if GraphicClass = nil then
    raise EInvalidGraphic.CreateFmt(SUnknownExtension, [Ext]);

  NewGraphic := GraphicClass.Create;
  try
    NewGraphic.OnProgress := Progress;
    NewGraphic.LoadFromFile(Filename);
  except
    NewGraphic.Free;
    raise;
  end;
  FGraphic.Free;
  FGraphic := NewGraphic;
  FGraphic.OnChange := Changed;
  Changed(Self);
end;

procedure TPicture.LoadFromMimeSource(MimeSource: TMimeSource);
begin
  if Assigned(FGraphic) then
    FGraphic.LoadFromMimeSource(MimeSource);
end;

procedure TPicture.Progress(Sender: TObject; Stage: TProgressStage;
  PercentDone: Byte; RedrawNow: Boolean; const R: TRect;
  const Msg: WideString);
begin
  if Assigned(FOnProgress) then
    FOnProgress(Sender, Stage, PercentDone, RedrawNow, R, Msg);
end;

procedure TPicture.ReadData(Stream: TStream);
var
  CName: string[63];
  NewGraphic: TGraphic;
  GraphicClass: TGraphicClass;
begin
  Stream.Read(CName[0], 1);
  Stream.Read(CName[1], Integer(CName[0]));
  GraphicClass := FileFormats.FindClassName(CName);
  NewGraphic := nil;
  if GraphicClass <> nil then
  begin
    NewGraphic := GraphicClass.Create;
    try
      NewGraphic.ReadData(Stream);
    except
      NewGraphic.Free;
      raise;
    end;
  end;
  FGraphic.Free;
  FGraphic := NewGraphic;
  if NewGraphic <> nil then
  begin
    NewGraphic.OnChange := Changed;
    NewGraphic.OnProgress := Progress;
  end;
  Changed(Self);
end;

class procedure TPicture.RegisterFileFormat(const AExtension,
  ADescription: string; AGraphicClass: TGraphicClass);
begin
  GetFileFormats.Add(AExtension, ADescription, 0, AGraphicClass);
end;

class procedure TPicture.RegisterFileFormatRes(const AExtension: String;
  ADescriptionResID: Integer; AGraphicClass: TGraphicClass);
begin
  GetFileFormats.Add(AExtension, '', ADescriptionResID, AGraphicClass);
end;

procedure TPicture.SaveToFile(const Filename: string);
begin
  if FGraphic <> nil then FGraphic.SaveToFile(Filename);
end;

procedure TPicture.SaveToMimeSource(MimeSource: TClxMimeSource);
begin
  if Assigned(FGraphic) then
    FGraphic.SaveToMimeSource(MimeSource); 
end;

procedure TPicture.SetBitmap(Value: TBitmap);
begin
  SetGraphic(Value);
end;

procedure TPicture.SetGraphic(Value: TGraphic);
var
  NewGraphic: TGraphic;
begin
  NewGraphic := nil;
  if Value <> nil then
  begin
    NewGraphic := TGraphicClass(Value.ClassType).Create;
    NewGraphic.Assign(Value);
    NewGraphic.OnChange := Changed;
    NewGraphic.OnProgress := Progress;
  end;
  try
    FGraphic.Free;
    FGraphic := NewGraphic;
    Changed(Self);
  except
    NewGraphic.Free;
    raise;
  end;
end;

class procedure TPicture.UnregisterGraphicClass(AClass: TGraphicClass);
begin
  if FileFormats <> nil then FileFormats.Remove(AClass);
end;

procedure TPicture.WriteData(Stream: TStream);
var
  CName: string[63];
begin
  with Stream do
  begin
    if Graphic <> nil then
      CName := Graphic.ClassName else
      CName := '';
    Write(CName, Length(CName) + 1);
    if Graphic <> nil then
      Graphic.WriteData(Stream);
  end;
end;

function TPicture.GetIcon: TIcon;
begin
  ForceType(TIcon);
  Result := TIcon(Graphic);
end;

procedure TPicture.SetIcon(Value: TIcon);
begin
  SetGraphic(Value);
end;

{ TDrawing }

procedure TDrawing.Assign(Source: TPersistent);
begin
  if Source is TDrawing then
    QPicture_setData(FHandle, QPicture_data(TDrawing(Source).Handle),
      QPicture_size(TDrawing(Source).Handle))
  else
    inherited Assign(Source);
end;

constructor TDrawing.Create;
begin
  inherited Create;
  FHandle := QPicture_create(0);
end;

destructor TDrawing.Destroy;
begin
  QPicture_destroy(FHandle);
  FCanvas.Free;
  inherited Destroy;
end;

procedure TDrawing.Draw(ACanvas: TCanvas; const Rect: TRect);
var
  Painter: QPainterH;
  Scale: Boolean;
begin
  Painter := ACanvas.Handle;
  Scale := (FWidth <> 0) and (FHeight <> 0) and (FWidth <> Rect.Right -
    Rect.Left) and (FHeight <> Rect.Bottom - Rect.Top);
  if Scale then
    QPainter_saveWorldMatrix(Painter);
  try
    if Scale then
    begin
      QPainter_setWindow(Painter, 0, 0, FWidth, FHeight);
      QPainter_setViewport(Painter, Rect.Left, Rect.Top, Rect.Right - Rect.Left,
        Rect.Bottom - Rect.Top);
    end;
    QPicture_play(FHandle, Painter);
  finally
    if Scale then
      QPainter_restoreWorldMatrix(Painter);
  end;
end;

function TDrawing.GetCanvas: TCanvas;
begin
  if FCanvas = nil then
    FCanvas := TDrawingCanvas.Create(Self);
  Result := FCanvas;
end;

function TDrawing.GetEmpty: Boolean;
begin
  Result := QPicture_size(FHandle) = 0;
end;

function TDrawing.GetHeight: Integer;
begin
  Result := FHeight;
end;

function TDrawing.GetWidth: Integer;
begin
  Result := FWidth;
end;

type
  TExtendedPictureHeader = record
    Size: Integer;
    Width: Integer;
    Height: Integer;
    DotsPerMeter: Integer;
  end;

procedure TDrawing.LoadFromMimeSource(MimeSource: TMimeSource);
var
  Stream: TStream;
begin
  if MimeSource.Provides(SDelphiDrawing) then
  begin
    Stream := TMemoryStream.Create;
    try
      MimeSource.SaveToStream(SDelphiDrawing, Stream);
      Stream.Position := 0;
      LoadFromStream(Stream);
    finally
      Stream.Free;
    end;
  end;
end;

procedure TDrawing.LoadFromStream(Stream: TStream);
var
  Header: TExtendedPictureHeader;
  Data: PChar;
begin
  Stream.Read(Header, SizeOf(Header));
  Data := AllocMem(Header.Size);
  try
    Stream.Read(Data^, Header.Size);
    QPicture_setData(FHandle, Data, Header.Size);
  finally
    FreeMem(Data);
  end;
  FWidth := Header.Width;
  FHeight := Header.Height;
end;

procedure TDrawing.ReadData(Stream: TStream);
begin
  LoadFromStream(Stream);
end;

procedure TDrawing.SaveToMimeSource(MimeSource: TClxMimeSource);
var
  Stream: TStream;
begin
  Stream := TMemoryStream.Create;
  try
    SaveToStream(Stream);
    Stream.Position := 0;
    MimeSource.LoadFromStream(Stream, SDelphiDrawing);
  finally
    Stream.Free;
  end;
end;

procedure TDrawing.SaveToStream(Stream: TStream);
var
  Header: TExtendedPictureHeader;
begin
  Header.Size := QPicture_size(FHandle);
  Header.Width := FWidth;
  Header.Height := FHeight;
  Header.DotsPerMeter := 0;
  Stream.Write(Header, SizeOf(Header));
  Stream.Write(QPicture_data(FHandle)^, Header.Size);
end;

procedure TDrawing.SetHeight(Value: Integer);
begin
  FHeight := Value;
end;

procedure TDrawing.SetWidth(Value: Integer);
begin
  FWidth := Value;
end;

procedure TDrawing.WriteData(Stream: TStream);
begin
  SaveToStream(Stream);
end;

{ TDrawingCanvas }

procedure TDrawingCanvas.BeginPainting;
begin
  if not QPainter_isActive(Handle) then
    QPainter_begin(Handle, FDrawing.Handle);
end;

constructor TDrawingCanvas.Create(Drawing: TDrawing);
begin
  inherited Create;
  FDrawing := Drawing;
end;

procedure TDrawingCanvas.CreateHandle;
begin
  Handle := QPainter_create;
end;

{ TPalette }

procedure TPalette.Changed;
begin
  if FUpdateCount = 0 then
  begin
    if Owned then
    begin
      QPalette_destroy(FHandle);
      FHandle := QPalette_create(FActiveColors, FDisabledColors, FInactiveColors);
    end;
    if Assigned(FOnChange) then FOnChange(Self);
  end;
end;

constructor TPalette.Create;
begin
  FBaseColor := clNone;
  FHandle := QPalette_create;
  QApplication_palette(FHandle, nil);
  FOwned := False;
end;

function TPalette.GetHandle: QPaletteH;
begin
  Result := FHandle;
end;

procedure TPalette.SetBaseColor(const Value: TColor);
var
  Pal: QPaletteH;
begin
  if FBaseColor <> Value then
  begin
    FBaseColor := Value;
    BeginUpdate;
    try
      Owned := True;
      Pal := QPalette_create(QColor(FBaseColor));
      try
        if Assigned(FActiveColors) then
          QColorGroup_destroy(FActiveColors);
        if Assigned(FInactiveColors) then
          QColorGroup_destroy(FInactiveColors);
        if Assigned(FDisabledColors) then
          QColorGroup_destroy(FDisabledColors);
        FActiveColors := QColorGroup_create(QPalette_active(Pal));
        FDisabledColors := QColorGroup_create(QPalette_disabled(Pal));
        FInactiveColors := QColorGroup_create(QPalette_inactive(Pal));
        { Qt hard codes crHighlight and crHighlightText to Qt::White and Qt::Blue (?!?) }
        SetColor(cgActive, crHighlight, clHighlight);
        SetColor(cgInactive, crHighlight, clHighlight);
        SetColor(cgDisabled, crHighlight, clHighlight);
        SetColor(cgActive, crHighlightText, clHighlightText);
        SetColor(cgInactive, crHighlightText, clHighlightText);
        SetColor(cgDisabled, crHighlightText, clHighlightText);
        { crBase isn't changed }
        //SetColor(cgActive, crBase, FBaseColor);
      finally
        QPalette_destroy(Pal);
      end;
    finally
      EndUpdate; { Changed; }
    end;
  end;
end;

const
  ColorGroupMap: array[TColorGroup] of QPaletteColorGroup =
    (QPaletteColorGroup_InActive, QPaletteColorGroup_Disabled, QPaletteColorGroup_Active);

function TPalette.GetBrushPixmap(Group: TColorGroup; Role: TColorRole): QPixmapH;
var
  Brush: QBrushH;
begin
  Result := nil;
  Brush := QPalette_brush(Handle, ColorGroupMap[Group], QColorGroupColorRole(Role));
  if Brush <> nil then
    Result := QBrush_pixmap(Brush);
end;

function TPalette.GetColor(Group: TColorGroup; Role: TColorRole): TColor;
begin
  Result := QColorColor(QPalette_color(Handle, ColorGroupMap[Group],
    QColorGroupColorRole(Role)));
end;

procedure TPalette.SetBitmap(Group: TColorGroup; Role: TColorRole; Bitmap: TBitmap);
var
  Pixmap: QPixmapH;
begin
  BeginUpdate;
  try
    Owned := True;
    if (Bitmap = nil) or (Bitmap.Empty) then
      Pixmap := nil
    else
      Pixmap := Bitmap.Handle;
    SetBrush(Group, Role, GetColor(Group, Role), Pixmap);
  finally
    EndUpdate;
  end;
end;

procedure TPalette.SetColor(Group: TColorGroup; Role: TColorRole; Color: TColor);
begin
  if GetColor(Group, Role) <> Color then
  begin
    BeginUpdate;
    try
      Owned := True;
      //QBrush_pixmap(QColorGroup_brush(ColorGroup(Group), QColorGroupColorRole(Role)));
      // SetBrush(Group, Role, Color, GetBrushPixmap(Group, Role));
      SetBrush(Group, Role, Color, nil);
    finally
      EndUpdate;
    end;
  end;
end;

function TPalette.ColorGroup(Group: TColorGroup): QColorGroupH;
begin
  case Group of
    cgInactive:
      if not Owned then
        Result := QPalette_inactive(FHandle)
      else
        Result := FInactiveColors;
    cgDisabled:
      if not Owned then
        Result := QPalette_disabled(FHandle)
      else
        Result := FDisabledColors;
    else {cgActive}
      if not Owned then
        Result := QPalette_active(FHandle)
      else
        Result := FActiveColors;
  end;
end;

procedure TPalette.SetBrush(Group: TColorGroup; Role: TColorRole;
  Color: TColor; Pixmap: QPixmapH);
var
  QC: QColorH;
  QB: QBrushH;
begin
  BeginUpdate;
  try
    Owned := True;
    QC := nil;
    try
      QC := QColor(Color);
      if Assigned(Pixmap) then
      begin
        if QPixmap_isNull(Pixmap) then
          QB := QBrush_create(QC, BrushStyle_SolidPattern)
        else
          QB := QBrush_create(QC, Pixmap);
        try
          QColorGroup_setBrush(ColorGroup(Group), QColorGroupColorRole(Role), QB);
        finally
          QBrush_destroy(QB);
        end;
      end
      else if Color < 0 then
        QColorGroup_setBrush(ColorGroup(Group), QColorGroupColorRole(Role),
          BrushFromColor(Color))
      else
        QColorGroup_setColor(ColorGroup(Group), QColorGroupColorRole(Role), QC);
    finally
      if Assigned(QC) then
        QColor_destroy(QC);
    end;
  finally
    EndUpdate;
  end;
end;

procedure TPalette.CreatePalette;
var
  Pal: QPaletteH;
begin
  Pal := QPalette_create;
  try
    QApplication_palette(Pal, nil);
    FActiveColors := QColorGroup_create(QPalette_active(Pal));
    FDisabledColors := QColorGroup_create(QPalette_disabled(Pal));
    FInactiveColors := QColorGroup_create(QPalette_inactive(Pal));
  finally
    QPalette_destroy(Pal);
  end;
  Changed;
end;

destructor TPalette.Destroy;
begin
  if Owned then
    QPalette_destroy(FHandle);
  FHandle := nil;
  inherited Destroy;
end;

procedure TPalette.SetOwned(const Value: Boolean);
begin
  if FOwned <> Value then
  begin
    FOwned := Value;
    if not FOwned then
      QApplication_palette(FHandle, nil)
    else
      CreatePalette;
    Changed;
  end;
end;

procedure TPalette.BeginUpdate;
begin
  Inc(FUpdateCount);
end;

procedure TPalette.EndUpdate;
begin
  if FUpdateCount = 0 then Exit;
  Dec(FUpdateCount);
  if FUpdateCount = 0 then Changed;
end;

function TPalette.GetColor(MappedColor: TMappedColor): TColor;
var
  Role: TColorRole;
begin
  case MappedColor of
    clNormalHighlightedText..clNormalForeground:
      begin
        Role := TColorRole(Abs(MappedColor + cloNormal) - 1);
        Result := GetColor(cgInactive, Role);
      end;
    clDisabledHighlightedText..clDisabledForeground:
      begin
        Role := TColorRole(Abs(MappedColor + cloDisabled) - 1);
        Result := GetColor(cgDisabled, Role);
      end;
    clActiveHighlightedText..clActiveForeground:
      begin
        Role := TColorRole(Abs(MappedColor + cloActive) - 1);
        Result := GetColor(cgActive, Role);
      end;
  else
    Result := 0;
  end;
end;

procedure TPalette.SetHandle(const Value: QPaletteH);
begin
  Owned := False;
  FHandle := Value;
  Changed;
end;

{ TWidgetPalette }

procedure TWidgetPalette.BitmapChanged(Sender: TObject);
begin
  BeginUpdate;
  try
    SetBitmap(cgActive, ColorRole, Bitmap);
    SetBitmap(cgInactive, ColorRole, Bitmap);
    SetBitmap(cgDisabled, ColorRole, Bitmap);
  finally
    EndUpdate;
  end;
end;

constructor TWidgetPalette.Create;
begin
  inherited Create;
  FColorRole := crBackground;
  FTextColorRole := crForeground;
end;

destructor TWidgetPalette.Destroy;
begin
  if Assigned(FBitmap) then FBitmap.Free;
  inherited Destroy;
end;

function TWidgetPalette.GetWidgetBitmap: TBitmap;
begin
  if not Assigned(FBitmap) then
  begin
    FBitmap := TBitmap.Create;
    FBitmap.OnChange := BitmapChanged;
  end;
  Result := FBitmap;
end;

function TWidgetPalette.GetWidgetColor: TColor;
begin
  Result := GetColor(cgActive, ColorRole);
end;

function TWidgetPalette.GetWidgetTextColor: TColor;
begin
  Result := GetColor(cgActive, TextColorRole);
end;

function TWidgetPalette.IsBitmapEmpty: Boolean;
begin
  Result := (not Assigned(FBitmap)) or FBitmap.Empty or QPixmap_isNull(FBitmap.Handle);
end;

procedure TWidgetPalette.SetWidgetBitmap(const Value: TBitmap);
begin
  if Bitmap <> Value then
    Bitmap.Assign(Value);
end;

procedure TWidgetPalette.SetWidgetColor(const Value: TColor);
begin
  if Color <> Value then
  begin
    BeginUpdate;
    try
      SetColor(cgActive, ColorRole, Value);
      SetColor(cgInactive, ColorRole, Value);
      SetColor(cgDisabled, ColorRole, Value);
    finally
      EndUpdate;
    end;
  end;
end;

procedure TWidgetPalette.SetWidgetTextColor(const Value: TColor);
begin
  if TextColor <> Value then
  begin
    BeginUpdate;
    try
      SetColor(cgActive, TextColorRole, Value);
      SetColor(cgInactive, TextColorRole, Value);
    finally
      EndUpdate;
    end;
  end;
end;

type
  PPattern = ^TPattern;
  TPattern = record
    Next: PPattern;
    Bitmap: TBitmap;
    BkColorRef: TColorRef;
    FgColorRef: TColorRef;
  end;

  TPatternManager = class(TObject)
  private
    List: PPattern;
    FLock: TRTLCriticalSection;
    function CreateBitmap(BkColor, FgColor: TColor): TBitmap;
  public
    constructor Create;
    destructor Destroy; override;
    function AllocPattern(BkColor, FgColor: TColorRef): PPattern;
    procedure FreePatterns;
    procedure Lock;
    procedure Unlock;
  end;

constructor TPatternManager.Create;
begin
  InitializeCriticalSection(FLock);
end;

destructor TPatternManager.Destroy;
begin
  FreePatterns;
  DeleteCriticalSection(FLock);
end;

procedure TPatternManager.Lock;
begin
  EnterCriticalSection(FLock);
end;

procedure TPatternManager.Unlock;
begin
  LeaveCriticalSection(FLock);
end;

function TPatternManager.AllocPattern(BkColor, FgColor: TColorRef): PPattern;
begin
  Lock;
  try
    BkColor := BkColor and $00FFFFFF;
    FgColor := FgColor and $00FFFFFF;
    Result := List;
    while (Result <> nil) and ((Result^.BkColorRef <> BkColor) or
      (Result^.FgColorRef <> FgColor)) do
      Result := Result^.Next;
    if Result = nil then
    begin
      GetMem(Result, SizeOf(TPattern));
      with Result^ do
      begin
        Next := List;
        Bitmap := CreateBitmap(BkColor, FgColor);
        BkColorRef := BkColor;
        FgColorRef := FgColor;
      end;
      List := Result;
    end;
  finally
    Unlock;
  end;
end;

function TPatternManager.CreateBitmap(BkColor, FgColor: TColor): TBitmap;
var
  X, Y: Integer;
begin
  Result := TBitmap.Create;
  try
    with Result do
    begin
      Width := 8;
      Height := 8;
      with Canvas do
      begin
        Brush.Style := bsSolid;
        Brush.Color := BkColor;
        FillRect(Rect(0, 0, Width, Height));
        Result.ImageNeeded;
        for Y := 0 to 7 do
          for X := 0 to 7 do
            if (Y mod 2) = (X mod 2) then  { toggles between even/odd pixles }
              QImage_setPixel(Result.FImage, X, Y, FgColor); { on even/odd rows }
      end;
      Dormant;
    end;
  except
    Result.Free;
    raise;
  end;
end;

procedure TPatternManager.FreePatterns;
var
  P: PPattern;
begin
  while List <> nil do
  begin
    P := List;
    with P^ do
    begin
      Lock;
      try
        List := Next
      finally
        Unlock;
      end;
      if Bitmap <> nil then Bitmap.Free;
    end;
    FreeMem(P);
  end;
end;

var
  PatternManager: TPatternManager;


function AllocPatternBitmap(BkColor, FgColor: TColor): TBitmap;
begin
  if PatternManager <> nil then
    Result := PatternManager.AllocPattern(ColorToRGB(BkColor),
      ColorToRGB(FgColor)).Bitmap
    else
      Result := nil;
end;

{ TIcon }

procedure TIcon.Assign(Source: TPersistent);
begin
  if Source = nil then
  begin
    FBitmap.FreeImage;
    FBitmap.FreePixmap;
    FMemoryImage.Clear;
    Changed(Self);
  end else
    inherited Assign(Source);
end;

class function TIcon.AssignsTo(Dest: TGraphicClass): Boolean;
begin
  Result := inherited AssignsTo(Dest) or Dest.InheritsFrom(TBitmap);
end;

procedure TIcon.AssignTo(Dest: TPersistent);
begin
  if (Dest = nil) or (Dest is TIcon) then
  begin
    TIcon(Dest).FBitmap.FreeImage;
    TIcon(Dest).FBitmap.FreePixmap;
    TIcon(Dest).FMemoryImage.Clear;
    if (Dest <> nil) and not FBitmap.Empty then
    begin
      FMemoryImage.Position := 0;
      TIcon(Dest).FMemoryImage.CopyFrom(FMemoryImage, FMemoryImage.Size);
      TIcon(Dest).NewImage;
    end;
  end
  else if Dest is TBitmap then
    TBitmap(Dest).Assign(FBitmap)
  else
    inherited AssignTo(Dest);
end;

constructor TIcon.Create;
begin
  inherited Create;
  FBitmap := TBitmap.Create;
  FMemoryImage := TMemoryStream.Create;
  FRequestedSize := Point(16, 16);
end;

destructor TIcon.Destroy;
begin
  FBitmap.Free;
  FMemoryImage.Free;
  inherited Destroy;
end;

procedure TIcon.Draw(ACanvas: TCanvas; const Rect: TRect);
begin
  FBitmap.Draw(ACanvas, Rect);
end;

function TIcon.GetEmpty: Boolean;
begin
  Result := (FMemoryImage.Size = 0) or FBitmap.Empty;
end;

function TIcon.GetHeight: Integer;
begin
  if Empty then
    Result := FRequestedSize.Y
  else
    Result := FBitmap.Height;
end;

function TIcon.GetHandle: QPixmapH;
begin
  if Assigned(FBitmap) then
    Result := FBitmap.Handle
  else
    Result := nil;
end;

function TIcon.GetWidth: Integer;
begin
  if Empty then
    Result := FRequestedSize.X
  else
    Result := FBitmap.Width;
end;

procedure TIcon.LoadFromMimeSource(MimeSource: TMimeSource);
begin
  InvalidOperation(@SMimeNotSupportedForIcon);
end;

procedure TIcon.LoadFromResourceName(Instance: THandle; const ResName: string);
var
  Stream: TCustomMemoryStream;
begin
  Stream := TResourceStream.Create(Instance, ResName, RT_RCDATA);
  try
    LoadFromStream(Stream);
  finally
    Stream.Free;
  end;
end;

procedure TIcon.LoadFromStream(Stream: TStream);
begin
  FMemoryImage.Clear;
  FMemoryImage.CopyFrom(Stream, Stream.Size - Stream.Position);
  NewImage;
end;

procedure TIcon.NewImage;
const
  MaskColorTable: array[0..1] of Cardinal = ($FF000000, $FFFFFFFF);

  function WidthBytes(I: Longint): Longint;
  begin
    Result := ((I + 31) div 32) * 4;
  end;

  procedure ReadIconBitsAndMask(IconInfo: TIconDirEntry; IconData: TMemoryStream);
  var
    BmpFile: TBitmapFileHeader;
    Header: TBitmapInfoHeader;
    BmpData: TMemoryStream;
    ColorTableSize,
    BitsSize,
    BitsOffset: Integer;
    Mask: TBitmap;
  begin
    IconData.Seek(IconInfo.dwImageOffset, soFromBeginning);
    IconData.Read(Header, SizeOf(Header));
    BmpData := TMemoryStream.Create;
    try
      // color (XOR) image
      FillChar(BmpFile, SizeOf(TBitmapFileHeader), 0);
      BmpFile.bfType := $4D42;
      if IconInfo.bColorCount = 0 then
        ColorTableSize := (SizeOf(DWORD) * Header.biClrUsed)
      else
        ColorTableSize := (SizeOf(DWORD) * IconInfo.bColorCount);
      BitsOffset := SizeOf(TBitmapFileHeader) + SizeOf(TBitmapInfoHeader) + ColorTableSize;
      BitsSize := (IconInfo.bHeight * IconInfo.bWidth * Header.biBitCount div 8)
             + ColorTableSize;
      BmpFile.bfSize := BitsOffset + BitsSize;
      Header.biHeight := IconInfo.bHeight;
      BmpFile.bfOffBits := BitsOffset;
      Header.biSizeImage := BitsSize;
      BmpData.Write(BmpFile, SizeOf(BmpFile));
      BmpData.Write(Header, SizeOf(Header));
      BmpData.CopyFrom(IconData, Header.biSizeImage);
      BmpData.Position := 0;
      FBitmap.LoadFromStream(BmpData);

      //Mask (AND) image
      BmpData.Clear;
      Mask := TBitmap.Create;
      try
        FillChar(BmpFile, SizeOf(TBitmapFileHeader), 0);
        BmpFile.bfType := $4D42;
        BitsSize := (WidthBytes(IconInfo.bWidth) * IconInfo.bHeight);
        BitsOffset := SizeOf(TBitmapFileHeader) + SizeOf(TBitmapInfoHeader)
          + SizeOf(MaskColorTable);
        BmpFile.bfSize := BitsOffset + BitsSize;
        Header.biBitCount := 1;
        Header.biClrUsed := 2;
        Header.biHeight := IconInfo.bHeight; 
        BmpFile.bfOffBits := BitsOffset;
        Header.biSizeImage := BitsSize;
        BmpData.Write(BmpFile, SizeOf(BmpFile));
        BmpData.Write(Header, SizeOf(Header));
        BmpData.Write(MaskColorTable, SizeOf(MaskColorTable));
        BmpData.CopyFrom(IconData, Header.biSizeImage);
        BmpData.Position := 0;
        Mask.LoadFromStream(BmpData);
        QPixmap_setMask(FBitmap.Handle, QBitmapH(Mask.Handle));
      finally
        Mask.Free;
      end;
    finally
      BmpData.Free;
    end;
  end;

  function AdjustColor(I: Integer): Integer;
  begin
    if I = 0 then
      Result := MaxInt
    else
      Result := I;
  end;

  function BetterSize(const Old, New: TIconDirEntry): Boolean;
  var
    NewX, NewY, OldX, OldY: Integer;
  begin
    NewX := New.bWidth - FRequestedSize.X;
    NewY := New.bHeight - FRequestedSize.Y;
    OldX := Old.bWidth - FRequestedSize.X;
    OldY := Old.bHeight - FRequestedSize.Y;
    Result := (Abs(NewX) <= Abs(OldX)) and ((NewX <= 0) or (NewX <= OldX)) and
       (Abs(NewY) <= Abs(OldY)) and ((NewY <= 0) or (NewY <= OldY));
  end;

type
  TIconDirEntries = array[0..127] of TIconDirEntry;

var
  idType, NumImages: Word;
  I, Index, C1, BitsPerPixel, Colors, BestColor: Integer;
  Icons: TIconDirEntries;

begin
  FMemoryImage.Position := 0;
  FMemoryImage.Read(idType, SizeOf(idType));
  if idType = 0 then
  begin
    FMemoryImage.Read(idType, SizeOf(idType));
    if idType <> 1 then InvalidOperation(@SUnknownImageFormat);
    FMemoryImage.Read(NumImages, SizeOf(NumImages));
    FMemoryImage.Read(Icons, NumImages * SizeOf(TIconDirEntry));

    BitsPerPixel := QPixmap_defaultDepth;
    if BitsPerPixel > 8 then
      Colors := MaxInt
    else
      Colors := 1 shl BitsPerPixel;

    Index := 0;
    BestColor := AdjustColor(Icons[0].bColorCount);
    for I := 1 to NumImages-1 do
    begin
      C1 := AdjustColor(Icons[I].bColorCount);
      if (C1 <= Colors) and (C1 >= BestColor) and
        BetterSize(Icons[Index], Icons[I]) then
      begin
        Index := I;
        BestColor := C1;
      end;
    end;
    ReadIconBitsAndMask(Icons[Index], FMemoryImage);
  end else
  begin
    FMemoryImage.Position := 0;
    FBitmap.LoadFromStream(FMemoryImage);
    FBitmap.Mask(clDefault);
  end;
  FMemoryImage.Position := 0;
  Changed(Self);
end;

procedure TIcon.SaveToMimeSource(MimeSource: TClxMimeSource);
begin
  InvalidOperation(@SMimeNotSupportedForIcon);
end;

procedure TIcon.SaveToStream(Stream: TStream);
begin
  FMemoryImage.Position := 0;
  Stream.CopyFrom(FMemoryImage, FMemoryImage.Size);
end;

procedure TIcon.SetHeight(Value: Integer);
begin
  FRequestedSize.Y := Value;
  if FMemoryImage.Size > 0 then
    NewImage;
end;

procedure TIcon.SetTransparent(Value: Boolean);
begin
  // Ignore assignments to this property.
  // Icons are always transparent.
end;

procedure TIcon.SetWidth(Value: Integer);
begin
  FRequestedSize.X := Value;
  if FMemoryImage.Size > 0 then
    NewImage;
end;

procedure InitScreenLogPixels;
var
  Metrics: QPaintDeviceMetricsH;
begin
  Metrics := QPaintDeviceMetrics_create(QWidget_to_QPaintDevice(QApplication_desktop));
  ScreenLogPixels := QPaintDeviceMetrics_logicalDpiY(Metrics);
  QPaintDeviceMetrics_destroy(Metrics);
end;


initialization
  RegisterIntegerConsts(TypeInfo(TColor), IdentToColor, ColorToIdent);
  InitializeCriticalSection(CounterLock);
  PatternManager := TPatternManager.Create;

finalization
  FileFormats.Free;
  DeleteCriticalSection(CounterLock);
  PatternManager.Free;

end.
