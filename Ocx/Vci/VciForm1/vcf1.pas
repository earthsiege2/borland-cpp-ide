unit vcf1;

{ This file contains pascal declarations imported from a type library.
  This file will be written during each import or refresh of the type
  library editor.  Changes to this file will be discarded during the
  refresh process. }

{ VCI Formula One Library }
{ Version 1.0 }

{ Conversion log:
  Warning: 'Type' is a reserved word. _DVCF1.Type changed to Type_
 }

interface

uses Windows, ActiveX, Classes, Graphics, OleCtrls, StdVCL;

const
  LIBID_VCIF1Lib: TGUID = '{042BADC8-5E58-11CE-B610-524153480001}';

const

{ Specify how column widths are stored and displayed }

{ F1ColWidthUnitsConstants }

  F1ColWidthUnitsCharacters = 0;
  F1ColWidthUnitsTwips = 1;

{ Specify appearance of mouse. }

{ F1MousePointerConstants }

  F1Default = 0;
  F1Arrow = 1;
  F1Cross = 2;
  F1IBeam = 3;
  F1Icon = 4;
  F1Size = 5;
  F1SizeNESW = 6;
  F1SizeNS = 7;
  F1SizeNWSE = 8;
  F1SizeWE = 9;
  F1UpArrow = 10;
  F1Hourglass = 11;
  F1NoDrop = 12;
  F1Custom = 13;

{ Specifies behaviour of scroll bars and selections. }

{ F1ShowOffOnAutoConstants }

  F1Off = 0;
  F1On = 1;
  F1Auto = 2;

{ Specify sheet tab behavior. }

{ F1ShowTabsConstants }

  F1TabsOff = 0;
  F1TabsBottom = 1;
  F1TabsTop = 2;

{ Specify cursor mode for drawing objects. }

{ F1ModeConstants }

  F1ModeNormal = 0;
  F1ModeLine = 1;
  F1ModeRectangle = 2;
  F1ModeOval = 3;
  F1ModeArc = 4;
  F1ModeChart = 5;
  F1ModeField = 6;
  F1ModeButton = 7;
  F1ModePolygon = 8;
  F1ModeCheckBox = 9;
  F1ModeDropDown = 10;

{ Specify polygon editing mode. }

{ F1PolyEditModeConstants }

  F1PolyEditModeNormal = 0;
  F1PolyEditModePoints = 1;

{ Specify how data is shifted when new cells are inserted or deleted. }

{ F1ShiftTypeConstants }

  F1ShiftHorizontal = 1;
  F1ShiftVertical = 2;
  F1ShiftRows = 3;
  F1ShiftCols = 4;

{ Specify how data is aligned horizontally. }

{ F1HAlignConstants }

  F1HAlignGeneral = 1;
  F1HAlignLeft = 2;
  F1HAlignCenter = 3;
  F1HAlignRight = 4;
  F1HAlignFill = 5;
  F1HAlignJustify = 6;
  F1HAlignCenterAcrossCells = 7;

{ Specify how data is aligned vertically. }

{ F1VAlignConstants }

  F1VAlignTop = 1;
  F1VAlignCenter = 2;
  F1VAlignBottom = 3;

{ Specify how data is cleared. }

{ F1ClearTypeConstants }

  F1ClearDlg = 0;
  F1ClearAll = 1;
  F1ClearFormats = 2;
  F1ClearValues = 3;

{ Specify a file type. }

{ F1FileTypeConstants }

  F1FileFormulaOne = 1;
  F1FileExcel4 = 2;
  F1FileTabbedText = 3;
  F1FileExcel5 = 4;
  F1FileFormulaOne3 = 5;
  F1FileTabbedTextValuesOnly = 6;

{ Specify an object type. }

{ F1ObjTypeConstants }

  F1ObjLine = 1;
  F1ObjRectangle = 2;
  F1ObjOval = 3;
  F1ObjArc = 4;
  F1ObjChart = 5;
  F1ObjButton = 7;
  F1ObjPolygon = 8;
  F1ObjCheckBox = 9;
  F1ObjDropDown = 10;
  F1ObjPicture = 11;

{ Formula One error constants. }

{ F1ErrorConstants }

  F1ErrorNone = 0;
  F1ErrorGeneral = 20001;
  F1ErrorBadArgument = 20002;
  F1ErrorNoMemory = 20003;
  F1ErrorBadFormula = 20004;
  F1ErrorBufTooShort = 20005;
  F1ErrorNotFound = 20006;
  F1ErrorBadRC = 20007;
  F1ErrorBadHSS = 20008;
  F1ErrorTooManyHSS = 20009;
  F1ErrorNoTable = 20010;
  F1ErrorUnableToOpenFile = 20011;
  F1ErrorInvalidFile = 20012;
  F1ErrorInsertShiftOffTable = 20013;
  F1ErrorOnlyOneRange = 20014;
  F1ErrorNothingToPaste = 20015;
  F1ErrorBadNumberFormat = 20016;
  F1ErrorTooManyFonts = 20017;
  F1ErrorTooManySelectedRanges = 20018;
  F1ErrorUnableToWriteFile = 20019;
  F1ErrorNoTransaction = 20020;
  F1ErrorNothingToPrint = 20021;
  F1ErrorPrintMarginsDontFit = 20022;
  F1ErrorCancel = 20023;
  F1ErrorUnableToInitializePrinter = 20024;
  F1ErrorStringTooLong = 20025;
  F1ErrorFormulaTooLong = 20026;
  F1ErrorUnableToOpenClipboard = 20027;
  F1ErrorPasteWouldOverflowSheet = 20028;
  F1ErrorLockedCellsCannotBeModified = 20029;
  F1ErrorLockedDocCannotBeModified = 20030;
  F1ErrorInvalidName = 20031;
  F1ErrorCannotDeleteNameInUse = 20032;
  F1ErrorUnableToFindName = 20033;
  F1ErrorNoWindow = 20034;
  F1ErrorSelection = 20035;
  F1ErrorTooManyObjects = 20036;
  F1ErrorInvalidObjectType = 20037;
  F1ErrorObjectNotFound = 20038;
  F1ErrorInvalidRequest = 20039;
  F1ErrorBadValidationRule = 20040;
  F1ErrorBadInputMask = 20041;
  F1ErrorValidationFailed = 20042;
  F1ErrorNoODBCConnection = 20043;
  F1ErrorUnableToLoadODBC = 20044;
  F1ErrorUnsupportedFeature = 20045;

{ Specify cell reference behavior for list box. }

{ F1ControlCellConstants }

  F1ControlNoCell = 0;
  F1ControlCellValue = 1;
  F1ControlCellText = 2;

const

{ Component class GUIDs }
  Class_F1Book: TGUID = '{042BADC5-5E58-11CE-B610-524153480001}';

type

{ Forward declarations }
{ Forward declarations: Interfaces }
  _DVCF1 = dispinterface;
  _DVCF1Events = dispinterface;

{ Forward declarations: CoClasses }
  F1Book = _DVCF1;

{ Forward declarations: Enums }
  F1ColWidthUnitsConstants = TOleEnum;
  F1MousePointerConstants = TOleEnum;
  F1ShowOffOnAutoConstants = TOleEnum;
  F1ShowTabsConstants = TOleEnum;
  F1ModeConstants = TOleEnum;
  F1PolyEditModeConstants = TOleEnum;
  F1ShiftTypeConstants = TOleEnum;
  F1HAlignConstants = TOleEnum;
  F1VAlignConstants = TOleEnum;
  F1ClearTypeConstants = TOleEnum;
  F1FileTypeConstants = TOleEnum;
  F1ObjTypeConstants = TOleEnum;
  F1ErrorConstants = TOleEnum;
  F1ControlCellConstants = TOleEnum;

{ Dispatch interface for Formula One Workbook }

  _DVCF1 = dispinterface
    ['{042BADC6-5E58-11CE-B610-524153480001}']
    property BackColor: TColor dispid 3;
    property Col: Integer dispid 4;
    property Row: Integer dispid 5;
    property ShowHScrollBar: Smallint dispid 6;
    property Text: WideString dispid 7;
    property Number: Double dispid 8;
    property Formula: WideString dispid 9;
    property FixedCol: Integer dispid 10;
    property FixedCols: Integer dispid 11;
    property FixedRow: Integer dispid 12;
    property FixedRows: Integer dispid 13;
    property ShowGridLines: WordBool dispid 14;
    property ShowRowHeading: WordBool dispid 15;
    property ShowSelections: Smallint dispid 16;
    property LeftCol: Integer dispid 17;
    property MaxCol: Integer dispid 18;
    property MaxRow: Integer dispid 19;
    property TopRow: Integer dispid 20;
    property AllowResize: WordBool dispid 21;
    property AllowSelections: WordBool dispid 22;
    property AllowFormulas: WordBool dispid 23;
    property AllowInCellEditing: WordBool dispid 24;
    property ShowVScrollBar: Smallint dispid 25;
    property AllowFillRange: WordBool dispid 26;
    property AllowMoveRange: WordBool dispid 27;
    property SelStartCol: Integer dispid 28;
    property SelStartRow: Integer dispid 29;
    property SelEndCol: Integer dispid 30;
    property SelEndRow: Integer dispid 31;
    property ExtraColor: TColor dispid 32;
    property FileName: WideString dispid 33;
    property AutoRecalc: WordBool dispid 34;
    property PrintGridLines: WordBool dispid 35;
    property PrintRowHeading: WordBool dispid 36;
    property PrintHCenter: WordBool dispid 37;
    property PrintVCenter: WordBool dispid 38;
    property PrintLeftToRight: WordBool dispid 39;
    property PrintHeader: WideString dispid 40;
    property PrintFooter: WideString dispid 41;
    property PrintLeftMargin: Double dispid 42;
    property PrintTopMargin: Double dispid 43;
    property PrintRightMargin: Double dispid 44;
    property PrintBottomMargin: Double dispid 45;
    property PrintArea: WideString dispid 46;
    property PrintTitles: WideString dispid 47;
    property PrintNoColor: WordBool dispid 48;
    property Selection: WideString dispid 49;
    property TableName: WideString dispid 50;
    property DoCancelEdit: WordBool dispid 51;
    property DoSelChange: WordBool dispid 52;
    property DoStartEdit: WordBool dispid 53;
    property DoEndEdit: WordBool dispid 54;
    property DoStartRecalc: WordBool dispid 55;
    property DoEndRecalc: WordBool dispid 56;
    property DoClick: WordBool dispid 57;
    property DoDblClick: WordBool dispid 58;
    property ShowColHeading: WordBool dispid 59;
    property PrintColHeading: WordBool dispid 60;
    property Entry: WideString dispid 61;
    property Repaint: WordBool dispid 62;
    property AllowArrows: WordBool dispid 63;
    property AllowTabs: WordBool dispid 64;
    property FormattedText: WideString dispid 65;
    property RowMode: WordBool dispid 66;
    property AllowDelete: WordBool dispid 67;
    property EnableProtection: WordBool dispid 68;
    property MinCol: Integer dispid 69;
    property MinRow: Integer dispid 70;
    property DoTopLeftChanged: WordBool dispid 71;
    property AllowEditHeaders: WordBool dispid 72;
    property DoObjClick: WordBool dispid 73;
    property DoObjDblClick: WordBool dispid 74;
    property AllowObjSelections: WordBool dispid 75;
    property DoRClick: WordBool dispid 76;
    property DoRDblClick: WordBool dispid 77;
    property Clip: WideString dispid 78;
    property ClipValues: WideString dispid 79;
    property PrintLandscape: WordBool dispid 80;
    property Enabled: WordBool dispid -514;
    property BorderStyle: Smallint dispid -504;
    property AppName: WideString dispid 81;
    property HdrHeight: Smallint dispid 82;
    property HdrWidth: Smallint dispid 83;
    property NumberFormat: WideString dispid 84;
    property TopLeftText: WideString dispid 85;
    property EnterMovesDown: WordBool dispid 86;
    property LastCol: Integer dispid 87;
    property LastRow: Integer dispid 88;
    property Logical: WordBool dispid 89;
    property Mode: Smallint dispid 90;
    property PolyEditMode: Smallint dispid 91;
    property ViewScale: Smallint dispid 92;
    property SelectionCount: Smallint dispid 93;
    property Title: WideString dispid 94;
    property Type_: Smallint dispid 95;
    property ShowFormulas: WordBool dispid 96;
    property ShowZeroValues: WordBool dispid 97;
    property MousePointer: Smallint dispid 2;
    property MouseIcon: IPictureDisp dispid 98;
    property DoObjValueChanged: WordBool dispid 99;
    property ScrollToLastRC: WordBool dispid 100;
    property Modified: WordBool dispid 101;
    property DoObjGotFocus: WordBool dispid 102;
    property DoObjLostFocus: WordBool dispid 103;
    property PrintDevMode: OLE_HANDLE dispid 104;
    property NumSheets: Integer dispid 105;
    property Sheet: Integer dispid 106;
    property ColWidthUnits: Smallint dispid 107;
    property ShowTypeMarkers: WordBool dispid 108;
    property ShowTabs: Smallint dispid 109;
    property ShowEditBar: WordBool dispid 110;
    property ShowEditBarCellRef: WordBool dispid 111;
    property AllowDesigner: WordBool dispid 1;
    property hWnd: OLE_HANDLE dispid -515;
    property AllowAutoFill: WordBool dispid 112;
    property ColText[nCol: Integer]: WideString dispid 272;
    property DefinedName[const pName: WideString]: WideString dispid 273;
    property EntryRC[nRow, nCol: Integer]: WideString dispid 274;
    property FormattedTextRC[nRow, nCol: Integer]: WideString dispid 275;
    property FormulaRC[nRow, nCol: Integer]: WideString dispid 276;
    property LastColForRow[nRow: Integer]: Integer dispid 277;
    property LogicalRC[nRow, nCol: Integer]: WordBool dispid 278;
    property NumberRC[nRow, nCol: Integer]: Double dispid 279;
    property RowText[nRow: Integer]: WideString dispid 280;
    property TextRC[nRow, nCol: Integer]: WideString dispid 281;
    property TypeRC[nRow, nCol: Integer]: Smallint dispid 282;
    procedure EditPasteValues; dispid 113;
    procedure GetAlignment(var pHorizontal: Smallint; var pWordWrap: WordBool; var pVertical, pOrientation: Smallint); dispid 114;
    procedure GetBorder(var pLeft, pRight, pTop, pBottom, pShade: Smallint; var pcrLeft, pcrRight, pcrTop, pcrBottom: TColor); dispid 115;
    procedure GetFont(var pName: WideString; var pSize: Smallint; var pBold, pItalic, pUnderline, pStrikeout: WordBool; var pcrColor: TColor; var pOutline, pShadow: WordBool); dispid 116;
    procedure GetLineStyle(var pStyle: Smallint; var pcrColor: TColor; var pWeight: Smallint); dispid 117;
    procedure GetPattern(var pPattern: Smallint; var pcrFG, pcrBG: TColor); dispid 118;
    procedure GetProtection(var pLocked, pHidden: WordBool); dispid 119;
    procedure GetTabbedText(nR1, nC1, nR2, nC2: Integer; bValuesOnly: WordBool; var phText: OLE_HANDLE); dispid 120;
    procedure SetTabbedText(nStartRow, nStartCol: Integer; var pRows, pCols: Integer; bValuesOnly: WordBool; const pText: WideString); dispid 121;
    procedure AddColPageBreak(nCol: Integer); dispid 122;
    procedure AddPageBreak; dispid 123;
    procedure AddRowPageBreak(nRow: Integer); dispid 124;
    procedure AddSelection(nR1, nC1, nR2, nC2: Integer); dispid 125;
    procedure Attach(const pTitle: WideString); dispid 126;
    procedure AttachToSS(hSrcSS: Integer); dispid 127;
    procedure CalculationDlg; dispid 128;
    procedure CancelEdit; dispid 129;
    procedure CheckRecalc; dispid 130;
    procedure ClearClipboard; dispid 131;
    procedure ClearRange(nR1, nC1, nR2, nC2: Integer; ClearType: Smallint); dispid 132;
    procedure ColorPaletteDlg; dispid 133;
    procedure ColWidthDlg; dispid 134;
    procedure CopyAll(hSrcSS: Integer); dispid 135;
    procedure CopyRange(nDstR1, nDstC1, nDstR2, nDstC2, hSrcSS, nSrcR1, nSrcC1, nSrcR2, nSrcC2: Integer); dispid 136;
    procedure DefinedNameDlg; dispid 137;
    procedure DeleteDefinedName(const pName: WideString); dispid 138;
    procedure DeleteRange(nR1, nC1, nR2, nC2: Integer; ShiftType: Smallint); dispid 139;
    procedure Draw(hDC: OLE_HANDLE; x, y, cx, cy, nRow, nCol: Integer; var pRows, pCols: Integer; nFixedRow, nFixedCol, nFixedRows, nFixedCols: Integer); dispid 140;
    procedure EditClear(ClearType: Smallint); dispid 141;
    procedure EditCopy; dispid 142;
    procedure EditCopyDown; dispid 143;
    procedure EditCopyRight; dispid 144;
    procedure EditCut; dispid 145;
    procedure EditDelete(ShiftType: Smallint); dispid 146;
    procedure EditInsert(ShiftType: Smallint); dispid 147;
    procedure EditPaste; dispid 148;
    procedure EndEdit; dispid 149;
    procedure FilePageSetupDlg; dispid 150;
    procedure FilePrint(bShowPrintDlg: WordBool); dispid 151;
    procedure FilePrintSetupDlg; dispid 152;
    procedure FormatAlignmentDlg; dispid 153;
    procedure FormatBorderDlg; dispid 154;
    procedure FormatCurrency0; dispid 155;
    procedure FormatCurrency2; dispid 156;
    procedure FormatDefaultFontDlg; dispid 157;
    procedure FormatFixed; dispid 158;
    procedure FormatFixed2; dispid 159;
    procedure FormatFontDlg; dispid 160;
    procedure FormatFraction; dispid 161;
    procedure FormatGeneral; dispid 162;
    procedure FormatHmmampm; dispid 163;
    procedure FormatMdyy; dispid 164;
    procedure FormatNumberDlg; dispid 165;
    procedure FormatPatternDlg; dispid 166;
    procedure FormatPercent; dispid 167;
    procedure FormatScientific; dispid 168;
    procedure GetActiveCell(var pRow, pCol: Integer); dispid 169;
    property ColWidth[nCol: Integer]: Smallint dispid 283;
    property RowHeight[nRow: Integer]: Smallint dispid 284;
    procedure GetDefaultFont(var pBuf: WideString; var pSize: Smallint); dispid 170;
    procedure GetHdrSelection(var pTopLeftHdr, pRowHdr, pColHdr: WordBool); dispid 171;
    procedure GetIteration(var pIteration: WordBool; var pMaxIterations: Smallint; var pMaxChange: Double); dispid 172;
    procedure GetPrintScale(var pScale: Smallint; var pFitToPage: WordBool; var pVPages, pHPages: Integer); dispid 173;
    procedure GetSelection(nSelection: Smallint; var pR1, pC1, pR2, pC2: Integer); dispid 174;
    procedure GotoDlg; dispid 175;
    procedure HeapMin; dispid 176;
    procedure InitTable; dispid 177;
    procedure InsertRange(nR1, nC1, nR2, nC2: Integer; ShiftType: Smallint); dispid 178;
    procedure LineStyleDlg; dispid 179;
    procedure MoveRange(nR1, nC1, nR2, nC2, nRowOffset, nColOffset: Integer); dispid 180;
    procedure ObjAddItem(ID: Integer; const pItem: WideString); dispid 181;
    procedure ObjAddSelection(ID: Integer); dispid 182;
    procedure ObjBringToFront; dispid 183;
    procedure ObjDeleteItem(ID: Integer; nItem: Smallint); dispid 184;
    procedure ObjGetCell(ID: Integer; var pControlCellType: Smallint; var pRow, pCol: Integer); dispid 185;
    procedure ObjGetPos(ID: Integer; var pX1, pY1, pX2, pY2: Single); dispid 186;
    procedure ObjGetSelection(nSelection: Smallint; var pID: Integer); dispid 187;
    procedure ObjInsertItem(ID: Integer; nItem: Smallint; const pItem: WideString); dispid 188;
    procedure ObjNameDlg; dispid 189;
    procedure ObjNew(ObjType: Smallint; nX1, nY1, nX2, nY2: Single; var pID: Integer); dispid 190;
    procedure ObjNewPicture(nX1, nY1, nX2, nY2: Single; var pID: Integer; hMF: OLE_HANDLE; nMapMode, nWndExtentX, nWndExtentY: Integer); dispid 191;
    procedure ObjOptionsDlg; dispid 192;
    procedure ObjPosToTwips(nX1, nY1, nX2, nY2: Single; var pX, pY, pCX, pCY: Integer; var pShown: Smallint); dispid 193;
    procedure ObjSendToBack; dispid 194;
    procedure ObjSetCell(ID: Integer; ControlCellType: Smallint; nRow, nCol: Integer); dispid 195;
    procedure ObjSetPicture(ID: Integer; hMF: OLE_HANDLE; nMapMode: Smallint; nWndExtentX, nWndExtentY: Integer); dispid 196;
    procedure ObjSetPos(ID: Integer; nX1, nY1, nX2, nY2: Single); dispid 197;
    procedure ObjSetSelection(ID: Integer); dispid 198;
    procedure OpenFileDlg(const pTitle: WideString; hWndParent: OLE_HANDLE; var pBuf: WideString); dispid 199;
    procedure ProtectionDlg; dispid 200;
    procedure RangeToTwips(nRow1, nCol1, nRow2, nCol2: Integer; var pX, pY, pCX, pCY: Integer; var pShown: Smallint); dispid 201;
    procedure Read(const pPathName: WideString; var pFileType: Smallint); dispid 202;
    procedure ReadFromBlob(hBlob: OLE_HANDLE; nReservedBytes: Smallint); dispid 203;
    procedure Recalc; dispid 204;
    procedure RemoveColPageBreak(nCol: Integer); dispid 205;
    procedure RemovePageBreak; dispid 206;
    procedure RemoveRowPageBreak(nRow: Integer); dispid 207;
    procedure RowHeightDlg; dispid 208;
    procedure SaveFileDlg(const pTitle: WideString; var pBuf: WideString; var pFileType: Smallint); dispid 209;
    procedure SaveWindowInfo; dispid 210;
    procedure SetActiveCell(nRow, nCol: Integer); dispid 211;
    procedure SetAlignment(HAlign: Smallint; bWordWrap: WordBool; VAlign, nOrientation: Smallint); dispid 212;
    procedure SetBorder(nOutline, nLeft, nRight, nTop, nBottom, nShade: Smallint; crOutline, crLeft, crRight, crTop, crBottom: TColor); dispid 213;
    procedure SetColWidth(nC1, nC2: Integer; nWidth: Smallint; bDefColWidth: WordBool); dispid 214;
    procedure SetColWidthAuto(nR1, nC1, nR2, nC2: Integer; bSetDefaults: WordBool); dispid 215;
    procedure SetDefaultFont(const pName: WideString; nSize: Smallint); dispid 216;
    procedure SetFont(const pName: WideString; nSize: Smallint; bBold, bItalic, bUnderline, bStrikeout: WordBool; crColor: TColor; bOutline, bShadow: WordBool); dispid 217;
    procedure SetHdrSelection(bTopLeftHdr, bRowHdr, bColHdr: WordBool); dispid 218;
    procedure SetIteration(bIteration: WordBool; nMaxIterations: Smallint; nMaxChange: Double); dispid 219;
    procedure SetLineStyle(nStyle: Smallint; crColor: TColor; nWeight: Smallint); dispid 220;
    procedure SetPattern(nPattern: Smallint; crFG, crBG: TColor); dispid 221;
    procedure SetPrintAreaFromSelection; dispid 222;
    procedure SetPrintScale(nScale: Smallint; bFitToPage: WordBool; nVPages, nHPages: Smallint); dispid 223;
    procedure SetPrintTitlesFromSelection; dispid 224;
    procedure SetProtection(bLocked, bHidden: WordBool); dispid 225;
    procedure SetRowHeight(nR1, nR2: Integer; nHeight: Smallint; bDefRowHeight: WordBool); dispid 226;
    procedure SetRowHeightAuto(nR1, nC1, nR2, nC2: Integer; bSetDefaults: WordBool); dispid 227;
    procedure SetSelection(nR1, nC1, nR2, nC2: Integer); dispid 228;
    procedure ShowActiveCell; dispid 229;
    procedure Sort3(nR1, nC1, nR2, nC2: Integer; bSortByRows: WordBool; nKey1, nKey2, nKey3: Integer); dispid 230;
    procedure SortDlg; dispid 231;
    procedure StartEdit(bClear, bInCellEditFocus, bArrowsExitEditMode: WordBool); dispid 232;
    procedure SwapTables(hSS2: Integer); dispid 233;
    procedure TransactCommit; dispid 234;
    procedure TransactRollback; dispid 235;
    procedure TransactStart; dispid 236;
    procedure TwipsToRC(x, y: Integer; var pRow, pCol: Integer); dispid 237;
    procedure SSUpdate; dispid 238;
    function SSVersion: Smallint; dispid 239;
    procedure Write(const pPathName: WideString; FileType: Smallint); dispid 240;
    procedure WriteToBlob(var phBlob: OLE_HANDLE; nReservedBytes: Smallint); dispid 241;
    procedure SetRowHidden(nRow1, nRow2: Integer; bHidden: WordBool); dispid 242;
    procedure SetColHidden(nCol1, nCol2: Integer; bHidden: WordBool); dispid 243;
    procedure SetColWidthTwips(nCol1, nCol2, nWidth: Integer; bDefColWidth: WordBool); dispid 244;
    property DefinedNameByIndex[nName: Integer]: WideString dispid 285;
    property SheetName[nSheet: Integer]: WideString dispid 286;
    property PaletteEntry[nEntry: Integer]: TColor dispid 287;
    procedure EditInsertSheets; dispid 245;
    procedure EditDeleteSheets; dispid 246;
    procedure InsertSheets(nSheet, nSheets: Integer); dispid 247;
    procedure DeleteSheets(nSheet, nSheets: Integer); dispid 248;
    procedure Refresh; dispid -550;
    property ColWidthTwips[Col: Integer]: Smallint dispid 288;
    function NextColPageBreak(Col: Integer): Integer; dispid 249;
    function NextRowPageBreak(Row: Integer): Integer; dispid 250;
    function ObjFirstID: Integer; dispid 251;
    function ObjNextID(ID: Integer): Integer; dispid 252;
    function ObjGetItemCount(ID: Integer): Smallint; dispid 253;
    function ObjGetType(ID: Integer): Smallint; dispid 254;
    function ObjGetSelectionCount: Smallint; dispid 255;
    function FormatRCNr(Row, Col: Integer; DoAbsolute: WordBool): WideString; dispid 256;
    function SS: Integer; dispid 257;
    function ErrorNumberToText(SSError: Integer): WideString; dispid 258;
    property ObjItem[ID: Integer; Item: Smallint]: WideString dispid 289;
    property ObjItems[ID: Integer]: WideString dispid 290;
    property ObjName[ID: Integer]: WideString dispid 291;
    property ObjText[ID: Integer]: WideString dispid 292;
    property ObjValue[ID: Integer]: Smallint dispid 293;
    property ObjVisible[ID: Integer]: WordBool dispid 294;
    function ObjNameToID(const Name: WideString): Integer; dispid 259;
    function DefinedNameCount: Integer; dispid 260;
    property AutoFillItems[Index: Smallint]: WideString dispid 295;
    procedure ValidationRuleDlg; dispid 261;
    procedure SetValidationRule(const Rule, Text: WideString); dispid 262;
    procedure GetValidationRule(var Rule, Text: WideString); dispid 263;
    function AutoFillItemsCount: Smallint; dispid 264;
    procedure CopyRangeEx(nDstSheet, nDstR1, nDstC1, nDstR2, nDstC2, hSrcSS, nSrcSheet, nSrcR1, nSrcC1, nSrcR2, nSrcC2: Integer); dispid 265;
    procedure Sort(nR1, nC1, nR2, nC2: Integer; bSortByRows: WordBool; Keys: OleVariant); dispid 266;
    property ColHidden[nCol: Integer]: WordBool dispid 296;
    property RowHidden[nRow: Integer]: WordBool dispid 297;
    procedure DeleteAutoFillItems(nIndex: Smallint); dispid 267;
    procedure ODBCConnect(var pConnect: WideString; bShowErrors: WordBool; var pRetCode: Smallint); dispid 268;
    procedure ODBCDisconnect; dispid 269;
    procedure ODBCQuery(var pQuery: WideString; nRow, nCol: Integer; bForceShowDlg: WordBool; var pSetColNames, pSetColFormats, pSetColWidths, pSetMaxRC: WordBool; var pRetCode: Smallint); dispid 270;
    property SheetSelected[nSheet: Integer]: WordBool dispid 298;
    procedure LaunchDesigner; dispid 271;
    procedure AboutBox; dispid -552;
  end;

{ Event interface for Formula One Workbook }

  _DVCF1Events = dispinterface
    ['{042BADC7-5E58-11CE-B610-524153480001}']
    procedure Click(nRow, nCol: Integer); dispid 1;
    procedure DblClick(nRow, nCol: Integer); dispid 2;
    procedure CancelEdit; dispid 3;
    procedure SelChange; dispid 4;
    procedure StartEdit(var EditString: WideString; var Cancel: Smallint); dispid 5;
    procedure EndEdit(var EditString: WideString; var Cancel: Smallint); dispid 6;
    procedure StartRecalc; dispid 7;
    procedure EndRecalc; dispid 8;
    procedure TopLeftChanged; dispid 9;
    procedure ObjClick(var ObjName: WideString; ObjID: Integer); dispid 10;
    procedure ObjDblClick(var ObjName: WideString; ObjID: Integer); dispid 11;
    procedure RClick(nRow, nCol: Integer); dispid 12;
    procedure RDblClick(nRow, nCol: Integer); dispid 13;
    procedure ObjValueChanged(var ObjName: WideString; ObjID: Integer); dispid 14;
    procedure Modified; dispid 15;
    procedure MouseDown(Button, Shift: Smallint; x: OLE_XPOS_PIXELS; y: OLE_YPOS_PIXELS); dispid -605;
    procedure MouseUp(Button, Shift: Smallint; x: OLE_XPOS_PIXELS; y: OLE_YPOS_PIXELS); dispid -607;
    procedure MouseMove(Button, Shift: Smallint; x: OLE_XPOS_PIXELS; y: OLE_YPOS_PIXELS); dispid -606;
    procedure ObjGotFocus(var ObjName: WideString; ObjID: Integer); dispid 16;
    procedure ObjLostFocus(var ObjName: WideString; ObjID: Integer); dispid 17;
    procedure ValidationFailed(var pEntry: WideString; nSheet, nRow, nCol: Integer; var pShowMessage: WideString; var pAction: Smallint); dispid 18;
    procedure KeyPress(var KeyAscii: Smallint); dispid -603;
    procedure KeyDown(var KeyCode: Smallint; Shift: Smallint); dispid -602;
    procedure KeyUp(var KeyCode: Smallint; Shift: Smallint); dispid -604;
  end;

{ VCI Formula One Workbook }

  TF1BookClick = procedure(Sender: TObject; nRow, nCol: Integer) of object;
  TF1BookDblClick = procedure(Sender: TObject; nRow, nCol: Integer) of object;
  TF1BookStartEdit = procedure(Sender: TObject; var EditString: WideString; var Cancel: Smallint) of object;
  TF1BookEndEdit = procedure(Sender: TObject; var EditString: WideString; var Cancel: Smallint) of object;
  TF1BookObjClick = procedure(Sender: TObject; var ObjName: WideString; ObjID: Integer) of object;
  TF1BookObjDblClick = procedure(Sender: TObject; var ObjName: WideString; ObjID: Integer) of object;
  TF1BookRClick = procedure(Sender: TObject; nRow, nCol: Integer) of object;
  TF1BookRDblClick = procedure(Sender: TObject; nRow, nCol: Integer) of object;
  TF1BookObjValueChanged = procedure(Sender: TObject; var ObjName: WideString; ObjID: Integer) of object;
  TF1BookObjGotFocus = procedure(Sender: TObject; var ObjName: WideString; ObjID: Integer) of object;
  TF1BookObjLostFocus = procedure(Sender: TObject; var ObjName: WideString; ObjID: Integer) of object;
  TF1BookValidationFailed = procedure(Sender: TObject; var pEntry: WideString; nSheet, nRow, nCol: Integer; var pShowMessage: WideString; var pAction: Smallint) of object;

  TF1Book = class(TOleControl)
  private
    FOnClick: TF1BookClick;
    FOnDblClick: TF1BookDblClick;
    FOnCancelEdit: TNotifyEvent;
    FOnSelChange: TNotifyEvent;
    FOnStartEdit: TF1BookStartEdit;
    FOnEndEdit: TF1BookEndEdit;
    FOnStartRecalc: TNotifyEvent;
    FOnEndRecalc: TNotifyEvent;
    FOnTopLeftChanged: TNotifyEvent;
    FOnObjClick: TF1BookObjClick;
    FOnObjDblClick: TF1BookObjDblClick;
    FOnRClick: TF1BookRClick;
    FOnRDblClick: TF1BookRDblClick;
    FOnObjValueChanged: TF1BookObjValueChanged;
    FOnModified: TNotifyEvent;
    FOnObjGotFocus: TF1BookObjGotFocus;
    FOnObjLostFocus: TF1BookObjLostFocus;
    FOnValidationFailed: TF1BookValidationFailed;
    FIntf: _DVCF1;
    function Get_PrintDevMode: OLE_HANDLE;
    procedure Set_PrintDevMode(var Value: OLE_HANDLE);
    function Get_hWnd: OLE_HANDLE;
    procedure Set_hWnd(var Value: OLE_HANDLE);
    function Get_ColText(nCol: Integer): WideString;
    procedure Set_ColText(nCol: Integer; const Value: WideString);
    function Get_DefinedName(const pName: WideString): WideString;
    procedure Set_DefinedName(const pName: WideString; const Value: WideString);
    function Get_EntryRC(nRow, nCol: Integer): WideString;
    procedure Set_EntryRC(nRow, nCol: Integer; const Value: WideString);
    function Get_FormattedTextRC(nRow, nCol: Integer): WideString;
    procedure Set_FormattedTextRC(nRow, nCol: Integer; const Value: WideString);
    function Get_FormulaRC(nRow, nCol: Integer): WideString;
    procedure Set_FormulaRC(nRow, nCol: Integer; const Value: WideString);
    function Get_LastColForRow(nRow: Integer): Integer;
    procedure Set_LastColForRow(nRow: Integer; Value: Integer);
    function Get_LogicalRC(nRow, nCol: Integer): WordBool;
    procedure Set_LogicalRC(nRow, nCol: Integer; Value: WordBool);
    function Get_NumberRC(nRow, nCol: Integer): Double;
    procedure Set_NumberRC(nRow, nCol: Integer; Value: Double);
    function Get_RowText(nRow: Integer): WideString;
    procedure Set_RowText(nRow: Integer; const Value: WideString);
    function Get_TextRC(nRow, nCol: Integer): WideString;
    procedure Set_TextRC(nRow, nCol: Integer; const Value: WideString);
    function Get_TypeRC(nRow, nCol: Integer): Smallint;
    procedure Set_TypeRC(nRow, nCol: Integer; Value: Smallint);
    function Get_ColWidth(nCol: Integer): Smallint;
    procedure Set_ColWidth(nCol: Integer; Value: Smallint);
    function Get_RowHeight(nRow: Integer): Smallint;
    procedure Set_RowHeight(nRow: Integer; Value: Smallint);
    function Get_DefinedNameByIndex(nName: Integer): WideString;
    procedure Set_DefinedNameByIndex(nName: Integer; const Value: WideString);
    function Get_SheetName(nSheet: Integer): WideString;
    procedure Set_SheetName(nSheet: Integer; const Value: WideString);
    function Get_PaletteEntry(nEntry: Integer): TColor;
    procedure Set_PaletteEntry(nEntry: Integer; Value: TColor);
    function Get_ColWidthTwips(Col: Integer): Smallint;
    procedure Set_ColWidthTwips(Col: Integer; Value: Smallint);
    function Get_ObjItem(ID: Integer; Item: Smallint): WideString;
    procedure Set_ObjItem(ID: Integer; Item: Smallint; const Value: WideString);
    function Get_ObjItems(ID: Integer): WideString;
    procedure Set_ObjItems(ID: Integer; const Value: WideString);
    function Get_ObjName(ID: Integer): WideString;
    procedure Set_ObjName(ID: Integer; const Value: WideString);
    function Get_ObjText(ID: Integer): WideString;
    procedure Set_ObjText(ID: Integer; const Value: WideString);
    function Get_ObjValue(ID: Integer): Smallint;
    procedure Set_ObjValue(ID: Integer; Value: Smallint);
    function Get_ObjVisible(ID: Integer): WordBool;
    procedure Set_ObjVisible(ID: Integer; Value: WordBool);
    function Get_AutoFillItems(Index: Smallint): WideString;
    procedure Set_AutoFillItems(Index: Smallint; const Value: WideString);
    function Get_ColHidden(nCol: Integer): WordBool;
    procedure Set_ColHidden(nCol: Integer; Value: WordBool);
    function Get_RowHidden(nRow: Integer): WordBool;
    procedure Set_RowHidden(nRow: Integer; Value: WordBool);
    function Get_SheetSelected(nSheet: Integer): WordBool;
    procedure Set_SheetSelected(nSheet: Integer; Value: WordBool);
  protected
    procedure InitControlData; override;
    procedure InitControlInterface(const Obj: IUnknown); override;
  public
    procedure EditPasteValues;
    procedure GetAlignment(var pHorizontal: Smallint; var pWordWrap: WordBool; var pVertical, pOrientation: Smallint);
    procedure GetBorder(var pLeft, pRight, pTop, pBottom, pShade: Smallint; var pcrLeft, pcrRight, pcrTop, pcrBottom: TColor);
    procedure GetFont(var pName: WideString; var pSize: Smallint; var pBold, pItalic, pUnderline, pStrikeout: WordBool; var pcrColor: TColor; var pOutline, pShadow: WordBool);
    procedure GetLineStyle(var pStyle: Smallint; var pcrColor: TColor; var pWeight: Smallint);
    procedure GetPattern(var pPattern: Smallint; var pcrFG, pcrBG: TColor);
    procedure GetProtection(var pLocked, pHidden: WordBool);
    procedure GetTabbedText(nR1, nC1, nR2, nC2: Integer; bValuesOnly: WordBool; var phText: OLE_HANDLE);
    procedure SetTabbedText(nStartRow, nStartCol: Integer; var pRows, pCols: Integer; bValuesOnly: WordBool; const pText: WideString);
    procedure AddColPageBreak(nCol: Integer);
    procedure AddPageBreak;
    procedure AddRowPageBreak(nRow: Integer);
    procedure AddSelection(nR1, nC1, nR2, nC2: Integer);
    procedure Attach(const pTitle: WideString);
    procedure AttachToSS(hSrcSS: Integer);
    procedure CalculationDlg;
    procedure CancelEdit;
    procedure CheckRecalc;
    procedure ClearClipboard;
    procedure ClearRange(nR1, nC1, nR2, nC2: Integer; ClearType: Smallint);
    procedure ColorPaletteDlg;
    procedure ColWidthDlg;
    procedure CopyAll(hSrcSS: Integer);
    procedure CopyRange(nDstR1, nDstC1, nDstR2, nDstC2, hSrcSS, nSrcR1, nSrcC1, nSrcR2, nSrcC2: Integer);
    procedure DefinedNameDlg;
    procedure DeleteDefinedName(const pName: WideString);
    procedure DeleteRange(nR1, nC1, nR2, nC2: Integer; ShiftType: Smallint);
    procedure Draw(hDC: OLE_HANDLE; x, y, cx, cy, nRow, nCol: Integer; var pRows, pCols: Integer; nFixedRow, nFixedCol, nFixedRows, nFixedCols: Integer);
    procedure EditClear(ClearType: Smallint);
    procedure EditCopy;
    procedure EditCopyDown;
    procedure EditCopyRight;
    procedure EditCut;
    procedure EditDelete(ShiftType: Smallint);
    procedure EditInsert(ShiftType: Smallint);
    procedure EditPaste;
    procedure EndEdit;
    procedure FilePageSetupDlg;
    procedure FilePrint(bShowPrintDlg: WordBool);
    procedure FilePrintSetupDlg;
    procedure FormatAlignmentDlg;
    procedure FormatBorderDlg;
    procedure FormatCurrency0;
    procedure FormatCurrency2;
    procedure FormatDefaultFontDlg;
    procedure FormatFixed;
    procedure FormatFixed2;
    procedure FormatFontDlg;
    procedure FormatFraction;
    procedure FormatGeneral;
    procedure FormatHmmampm;
    procedure FormatMdyy;
    procedure FormatNumberDlg;
    procedure FormatPatternDlg;
    procedure FormatPercent;
    procedure FormatScientific;
    procedure GetActiveCell(var pRow, pCol: Integer);
    procedure GetDefaultFont(var pBuf: WideString; var pSize: Smallint);
    procedure GetHdrSelection(var pTopLeftHdr, pRowHdr, pColHdr: WordBool);
    procedure GetIteration(var pIteration: WordBool; var pMaxIterations: Smallint; var pMaxChange: Double);
    procedure GetPrintScale(var pScale: Smallint; var pFitToPage: WordBool; var pVPages, pHPages: Integer);
    procedure GetSelection(nSelection: Smallint; var pR1, pC1, pR2, pC2: Integer);
    procedure GotoDlg;
    procedure HeapMin;
    procedure InitTable;
    procedure InsertRange(nR1, nC1, nR2, nC2: Integer; ShiftType: Smallint);
    procedure LineStyleDlg;
    procedure MoveRange(nR1, nC1, nR2, nC2, nRowOffset, nColOffset: Integer);
    procedure ObjAddItem(ID: Integer; const pItem: WideString);
    procedure ObjAddSelection(ID: Integer);
    procedure ObjBringToFront;
    procedure ObjDeleteItem(ID: Integer; nItem: Smallint);
    procedure ObjGetCell(ID: Integer; var pControlCellType: Smallint; var pRow, pCol: Integer);
    procedure ObjGetPos(ID: Integer; var pX1, pY1, pX2, pY2: Single);
    procedure ObjGetSelection(nSelection: Smallint; var pID: Integer);
    procedure ObjInsertItem(ID: Integer; nItem: Smallint; const pItem: WideString);
    procedure ObjNameDlg;
    procedure ObjNew(ObjType: Smallint; nX1, nY1, nX2, nY2: Single; var pID: Integer);
    procedure ObjNewPicture(nX1, nY1, nX2, nY2: Single; var pID: Integer; hMF: OLE_HANDLE; nMapMode, nWndExtentX, nWndExtentY: Integer);
    procedure ObjOptionsDlg;
    procedure ObjPosToTwips(nX1, nY1, nX2, nY2: Single; var pX, pY, pCX, pCY: Integer; var pShown: Smallint);
    procedure ObjSendToBack;
    procedure ObjSetCell(ID: Integer; ControlCellType: Smallint; nRow, nCol: Integer);
    procedure ObjSetPicture(ID: Integer; hMF: OLE_HANDLE; nMapMode: Smallint; nWndExtentX, nWndExtentY: Integer);
    procedure ObjSetPos(ID: Integer; nX1, nY1, nX2, nY2: Single);
    procedure ObjSetSelection(ID: Integer);
    procedure OpenFileDlg(const pTitle: WideString; hWndParent: OLE_HANDLE; var pBuf: WideString);
    procedure ProtectionDlg;
    procedure RangeToTwips(nRow1, nCol1, nRow2, nCol2: Integer; var pX, pY, pCX, pCY: Integer; var pShown: Smallint);
    procedure Read(const pPathName: WideString; var pFileType: Smallint);
    procedure ReadFromBlob(hBlob: OLE_HANDLE; nReservedBytes: Smallint);
    procedure Recalc;
    procedure RemoveColPageBreak(nCol: Integer);
    procedure RemovePageBreak;
    procedure RemoveRowPageBreak(nRow: Integer);
    procedure RowHeightDlg;
    procedure SaveFileDlg(const pTitle: WideString; var pBuf: WideString; var pFileType: Smallint);
    procedure SaveWindowInfo;
    procedure SetActiveCell(nRow, nCol: Integer);
    procedure SetAlignment(HAlign: Smallint; bWordWrap: WordBool; VAlign, nOrientation: Smallint);
    procedure SetBorder(nOutline, nLeft, nRight, nTop, nBottom, nShade: Smallint; crOutline, crLeft, crRight, crTop, crBottom: TColor);
    procedure SetColWidth(nC1, nC2: Integer; nWidth: Smallint; bDefColWidth: WordBool);
    procedure SetColWidthAuto(nR1, nC1, nR2, nC2: Integer; bSetDefaults: WordBool);
    procedure SetDefaultFont(const pName: WideString; nSize: Smallint);
    procedure SetFont(const pName: WideString; nSize: Smallint; bBold, bItalic, bUnderline, bStrikeout: WordBool; crColor: TColor; bOutline, bShadow: WordBool);
    procedure SetHdrSelection(bTopLeftHdr, bRowHdr, bColHdr: WordBool);
    procedure SetIteration(bIteration: WordBool; nMaxIterations: Smallint; nMaxChange: Double);
    procedure SetLineStyle(nStyle: Smallint; crColor: TColor; nWeight: Smallint);
    procedure SetPattern(nPattern: Smallint; crFG, crBG: TColor);
    procedure SetPrintAreaFromSelection;
    procedure SetPrintScale(nScale: Smallint; bFitToPage: WordBool; nVPages, nHPages: Smallint);
    procedure SetPrintTitlesFromSelection;
    procedure SetProtection(bLocked, bHidden: WordBool);
    procedure SetRowHeight(nR1, nR2: Integer; nHeight: Smallint; bDefRowHeight: WordBool);
    procedure SetRowHeightAuto(nR1, nC1, nR2, nC2: Integer; bSetDefaults: WordBool);
    procedure SetSelection(nR1, nC1, nR2, nC2: Integer);
    procedure ShowActiveCell;
    procedure Sort3(nR1, nC1, nR2, nC2: Integer; bSortByRows: WordBool; nKey1, nKey2, nKey3: Integer);
    procedure SortDlg;
    procedure StartEdit(bClear, bInCellEditFocus, bArrowsExitEditMode: WordBool);
    procedure SwapTables(hSS2: Integer);
    procedure TransactCommit;
    procedure TransactRollback;
    procedure TransactStart;
    procedure TwipsToRC(x, y: Integer; var pRow, pCol: Integer);
    procedure SSUpdate;
    function SSVersion: Smallint;
    procedure Write(const pPathName: WideString; FileType: Smallint);
    procedure WriteToBlob(var phBlob: OLE_HANDLE; nReservedBytes: Smallint);
    procedure SetRowHidden(nRow1, nRow2: Integer; bHidden: WordBool);
    procedure SetColHidden(nCol1, nCol2: Integer; bHidden: WordBool);
    procedure SetColWidthTwips(nCol1, nCol2, nWidth: Integer; bDefColWidth: WordBool);
    procedure EditInsertSheets;
    procedure EditDeleteSheets;
    procedure InsertSheets(nSheet, nSheets: Integer);
    procedure DeleteSheets(nSheet, nSheets: Integer);
    procedure Refresh;
    function NextColPageBreak(Col: Integer): Integer;
    function NextRowPageBreak(Row: Integer): Integer;
    function ObjFirstID: Integer;
    function ObjNextID(ID: Integer): Integer;
    function ObjGetItemCount(ID: Integer): Smallint;
    function ObjGetType(ID: Integer): Smallint;
    function ObjGetSelectionCount: Smallint;
    function FormatRCNr(Row, Col: Integer; DoAbsolute: WordBool): WideString;
    function SS: Integer;
    function ErrorNumberToText(SSError: Integer): WideString;
    function ObjNameToID(const Name: WideString): Integer;
    function DefinedNameCount: Integer;
    procedure ValidationRuleDlg;
    procedure SetValidationRule(const Rule, Text: WideString);
    procedure GetValidationRule(var Rule, Text: WideString);
    function AutoFillItemsCount: Smallint;
    procedure CopyRangeEx(nDstSheet, nDstR1, nDstC1, nDstR2, nDstC2, hSrcSS, nSrcSheet, nSrcR1, nSrcC1, nSrcR2, nSrcC2: Integer);
    procedure Sort(nR1, nC1, nR2, nC2: Integer; bSortByRows: WordBool; Keys: OleVariant);
    procedure DeleteAutoFillItems(nIndex: Smallint);
    procedure ODBCConnect(var pConnect: WideString; bShowErrors: WordBool; var pRetCode: Smallint);
    procedure ODBCDisconnect;
    procedure ODBCQuery(var pQuery: WideString; nRow, nCol: Integer; bForceShowDlg: WordBool; var pSetColNames, pSetColFormats, pSetColWidths, pSetMaxRC: WordBool; var pRetCode: Smallint);
    procedure LaunchDesigner;
    procedure AboutBox;
    property ControlInterface: _DVCF1 read FIntf;
    property ColText[nCol: Integer]: WideString read Get_ColText write Set_ColText;
    property DefinedName[const pName: WideString]: WideString read Get_DefinedName write Set_DefinedName;
    property EntryRC[nRow, nCol: Integer]: WideString read Get_EntryRC write Set_EntryRC;
    property FormattedTextRC[nRow, nCol: Integer]: WideString read Get_FormattedTextRC write Set_FormattedTextRC;
    property FormulaRC[nRow, nCol: Integer]: WideString read Get_FormulaRC write Set_FormulaRC;
    property LastColForRow[nRow: Integer]: Integer read Get_LastColForRow write Set_LastColForRow;
    property LogicalRC[nRow, nCol: Integer]: WordBool read Get_LogicalRC write Set_LogicalRC;
    property NumberRC[nRow, nCol: Integer]: Double read Get_NumberRC write Set_NumberRC;
    property RowText[nRow: Integer]: WideString read Get_RowText write Set_RowText;
    property TextRC[nRow, nCol: Integer]: WideString read Get_TextRC write Set_TextRC;
    property TypeRC[nRow, nCol: Integer]: Smallint read Get_TypeRC write Set_TypeRC;
    property ColWidth[nCol: Integer]: Smallint read Get_ColWidth write Set_ColWidth;
    property RowHeight[nRow: Integer]: Smallint read Get_RowHeight write Set_RowHeight;
    property DefinedNameByIndex[nName: Integer]: WideString read Get_DefinedNameByIndex write Set_DefinedNameByIndex;
    property SheetName[nSheet: Integer]: WideString read Get_SheetName write Set_SheetName;
    property PaletteEntry[nEntry: Integer]: TColor read Get_PaletteEntry write Set_PaletteEntry;
    property ColWidthTwips[Col: Integer]: Smallint read Get_ColWidthTwips write Set_ColWidthTwips;
    property ObjItem[ID: Integer; Item: Smallint]: WideString read Get_ObjItem write Set_ObjItem;
    property ObjItems[ID: Integer]: WideString read Get_ObjItems write Set_ObjItems;
    property ObjName[ID: Integer]: WideString read Get_ObjName write Set_ObjName;
    property ObjText[ID: Integer]: WideString read Get_ObjText write Set_ObjText;
    property ObjValue[ID: Integer]: Smallint read Get_ObjValue write Set_ObjValue;
    property ObjVisible[ID: Integer]: WordBool read Get_ObjVisible write Set_ObjVisible;
    property AutoFillItems[Index: Smallint]: WideString read Get_AutoFillItems write Set_AutoFillItems;
    property ColHidden[nCol: Integer]: WordBool read Get_ColHidden write Set_ColHidden;
    property RowHidden[nRow: Integer]: WordBool read Get_RowHidden write Set_RowHidden;
    property SheetSelected[nSheet: Integer]: WordBool read Get_SheetSelected write Set_SheetSelected;
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
    property OnMouseUp;
    property OnMouseMove;
    property OnMouseDown;
    property OnKeyUp;
    property OnKeyPress;
    property OnKeyDown;
    property BackColor: TColor index 3 read GetTColorProp write SetTColorProp stored False;
    property Col: Integer index 4 read GetIntegerProp write SetIntegerProp stored False;
    property Row: Integer index 5 read GetIntegerProp write SetIntegerProp stored False;
    property ShowHScrollBar: Smallint index 6 read GetSmallintProp write SetSmallintProp stored False;
    property Text: WideString index 7 read GetWideStringProp write SetWideStringProp stored False;
    property Number: Double index 8 read GetDoubleProp write SetDoubleProp stored False;
    property Formula: WideString index 9 read GetWideStringProp write SetWideStringProp stored False;
    property FixedCol: Integer index 10 read GetIntegerProp write SetIntegerProp stored False;
    property FixedCols: Integer index 11 read GetIntegerProp write SetIntegerProp stored False;
    property FixedRow: Integer index 12 read GetIntegerProp write SetIntegerProp stored False;
    property FixedRows: Integer index 13 read GetIntegerProp write SetIntegerProp stored False;
    property ShowGridLines: WordBool index 14 read GetWordBoolProp write SetWordBoolProp stored False;
    property ShowRowHeading: WordBool index 15 read GetWordBoolProp write SetWordBoolProp stored False;
    property ShowSelections: Smallint index 16 read GetSmallintProp write SetSmallintProp stored False;
    property LeftCol: Integer index 17 read GetIntegerProp write SetIntegerProp stored False;
    property MaxCol: Integer index 18 read GetIntegerProp write SetIntegerProp stored False;
    property MaxRow: Integer index 19 read GetIntegerProp write SetIntegerProp stored False;
    property TopRow: Integer index 20 read GetIntegerProp write SetIntegerProp stored False;
    property AllowResize: WordBool index 21 read GetWordBoolProp write SetWordBoolProp stored False;
    property AllowSelections: WordBool index 22 read GetWordBoolProp write SetWordBoolProp stored False;
    property AllowFormulas: WordBool index 23 read GetWordBoolProp write SetWordBoolProp stored False;
    property AllowInCellEditing: WordBool index 24 read GetWordBoolProp write SetWordBoolProp stored False;
    property ShowVScrollBar: Smallint index 25 read GetSmallintProp write SetSmallintProp stored False;
    property AllowFillRange: WordBool index 26 read GetWordBoolProp write SetWordBoolProp stored False;
    property AllowMoveRange: WordBool index 27 read GetWordBoolProp write SetWordBoolProp stored False;
    property SelStartCol: Integer index 28 read GetIntegerProp write SetIntegerProp stored False;
    property SelStartRow: Integer index 29 read GetIntegerProp write SetIntegerProp stored False;
    property SelEndCol: Integer index 30 read GetIntegerProp write SetIntegerProp stored False;
    property SelEndRow: Integer index 31 read GetIntegerProp write SetIntegerProp stored False;
    property ExtraColor: TColor index 32 read GetTColorProp write SetTColorProp stored False;
    property FileName: WideString index 33 read GetWideStringProp write SetWideStringProp stored False;
    property AutoRecalc: WordBool index 34 read GetWordBoolProp write SetWordBoolProp stored False;
    property PrintGridLines: WordBool index 35 read GetWordBoolProp write SetWordBoolProp stored False;
    property PrintRowHeading: WordBool index 36 read GetWordBoolProp write SetWordBoolProp stored False;
    property PrintHCenter: WordBool index 37 read GetWordBoolProp write SetWordBoolProp stored False;
    property PrintVCenter: WordBool index 38 read GetWordBoolProp write SetWordBoolProp stored False;
    property PrintLeftToRight: WordBool index 39 read GetWordBoolProp write SetWordBoolProp stored False;
    property PrintHeader: WideString index 40 read GetWideStringProp write SetWideStringProp stored False;
    property PrintFooter: WideString index 41 read GetWideStringProp write SetWideStringProp stored False;
    property PrintLeftMargin: Double index 42 read GetDoubleProp write SetDoubleProp stored False;
    property PrintTopMargin: Double index 43 read GetDoubleProp write SetDoubleProp stored False;
    property PrintRightMargin: Double index 44 read GetDoubleProp write SetDoubleProp stored False;
    property PrintBottomMargin: Double index 45 read GetDoubleProp write SetDoubleProp stored False;
    property PrintArea: WideString index 46 read GetWideStringProp write SetWideStringProp stored False;
    property PrintTitles: WideString index 47 read GetWideStringProp write SetWideStringProp stored False;
    property PrintNoColor: WordBool index 48 read GetWordBoolProp write SetWordBoolProp stored False;
    property Selection: WideString index 49 read GetWideStringProp write SetWideStringProp stored False;
    property TableName: WideString index 50 read GetWideStringProp write SetWideStringProp stored False;
    property DoCancelEdit: WordBool index 51 read GetWordBoolProp write SetWordBoolProp stored False;
    property DoSelChange: WordBool index 52 read GetWordBoolProp write SetWordBoolProp stored False;
    property DoStartEdit: WordBool index 53 read GetWordBoolProp write SetWordBoolProp stored False;
    property DoEndEdit: WordBool index 54 read GetWordBoolProp write SetWordBoolProp stored False;
    property DoStartRecalc: WordBool index 55 read GetWordBoolProp write SetWordBoolProp stored False;
    property DoEndRecalc: WordBool index 56 read GetWordBoolProp write SetWordBoolProp stored False;
    property DoClick: WordBool index 57 read GetWordBoolProp write SetWordBoolProp stored False;
    property DoDblClick: WordBool index 58 read GetWordBoolProp write SetWordBoolProp stored False;
    property ShowColHeading: WordBool index 59 read GetWordBoolProp write SetWordBoolProp stored False;
    property PrintColHeading: WordBool index 60 read GetWordBoolProp write SetWordBoolProp stored False;
    property Entry: WideString index 61 read GetWideStringProp write SetWideStringProp stored False;
    property Repaint: WordBool index 62 read GetWordBoolProp write SetWordBoolProp stored False;
    property AllowArrows: WordBool index 63 read GetWordBoolProp write SetWordBoolProp stored False;
    property AllowTabs: WordBool index 64 read GetWordBoolProp write SetWordBoolProp stored False;
    property FormattedText: WideString index 65 read GetWideStringProp write SetWideStringProp stored False;
    property RowMode: WordBool index 66 read GetWordBoolProp write SetWordBoolProp stored False;
    property AllowDelete: WordBool index 67 read GetWordBoolProp write SetWordBoolProp stored False;
    property EnableProtection: WordBool index 68 read GetWordBoolProp write SetWordBoolProp stored False;
    property MinCol: Integer index 69 read GetIntegerProp write SetIntegerProp stored False;
    property MinRow: Integer index 70 read GetIntegerProp write SetIntegerProp stored False;
    property DoTopLeftChanged: WordBool index 71 read GetWordBoolProp write SetWordBoolProp stored False;
    property AllowEditHeaders: WordBool index 72 read GetWordBoolProp write SetWordBoolProp stored False;
    property DoObjClick: WordBool index 73 read GetWordBoolProp write SetWordBoolProp stored False;
    property DoObjDblClick: WordBool index 74 read GetWordBoolProp write SetWordBoolProp stored False;
    property AllowObjSelections: WordBool index 75 read GetWordBoolProp write SetWordBoolProp stored False;
    property DoRClick: WordBool index 76 read GetWordBoolProp write SetWordBoolProp stored False;
    property DoRDblClick: WordBool index 77 read GetWordBoolProp write SetWordBoolProp stored False;
    property Clip: WideString index 78 read GetWideStringProp write SetWideStringProp stored False;
    property ClipValues: WideString index 79 read GetWideStringProp write SetWideStringProp stored False;
    property PrintLandscape: WordBool index 80 read GetWordBoolProp write SetWordBoolProp stored False;
    property Enabled: WordBool index -514 read GetWordBoolProp write SetWordBoolProp stored False;
    property BorderStyle: Smallint index -504 read GetSmallintProp write SetSmallintProp stored False;
    property AppName: WideString index 81 read GetWideStringProp write SetWideStringProp stored False;
    property HdrHeight: Smallint index 82 read GetSmallintProp write SetSmallintProp stored False;
    property HdrWidth: Smallint index 83 read GetSmallintProp write SetSmallintProp stored False;
    property NumberFormat: WideString index 84 read GetWideStringProp write SetWideStringProp stored False;
    property TopLeftText: WideString index 85 read GetWideStringProp write SetWideStringProp stored False;
    property EnterMovesDown: WordBool index 86 read GetWordBoolProp write SetWordBoolProp stored False;
    property LastCol: Integer index 87 read GetIntegerProp write SetIntegerProp stored False;
    property LastRow: Integer index 88 read GetIntegerProp write SetIntegerProp stored False;
    property Logical: WordBool index 89 read GetWordBoolProp write SetWordBoolProp stored False;
    property Mode: Smallint index 90 read GetSmallintProp write SetSmallintProp stored False;
    property PolyEditMode: Smallint index 91 read GetSmallintProp write SetSmallintProp stored False;
    property ViewScale: Smallint index 92 read GetSmallintProp write SetSmallintProp stored False;
    property SelectionCount: Smallint index 93 read GetSmallintProp write SetSmallintProp stored False;
    property Title: WideString index 94 read GetWideStringProp write SetWideStringProp stored False;
    property Type_: Smallint index 95 read GetSmallintProp write SetSmallintProp stored False;
    property ShowFormulas: WordBool index 96 read GetWordBoolProp write SetWordBoolProp stored False;
    property ShowZeroValues: WordBool index 97 read GetWordBoolProp write SetWordBoolProp stored False;
    property MousePointer: Smallint index 2 read GetSmallintProp write SetSmallintProp stored False;
    property MouseIcon: TPicture index 98 read GetTPictureProp write SetTPictureProp stored False;
    property DoObjValueChanged: WordBool index 99 read GetWordBoolProp write SetWordBoolProp stored False;
    property ScrollToLastRC: WordBool index 100 read GetWordBoolProp write SetWordBoolProp stored False;
    property Modified: WordBool index 101 read GetWordBoolProp write SetWordBoolProp stored False;
    property DoObjGotFocus: WordBool index 102 read GetWordBoolProp write SetWordBoolProp stored False;
    property DoObjLostFocus: WordBool index 103 read GetWordBoolProp write SetWordBoolProp stored False;
    property PrintDevMode: OLE_HANDLE read Get_PrintDevMode write Set_PrintDevMode stored False;
    property NumSheets: Integer index 105 read GetIntegerProp write SetIntegerProp stored False;
    property Sheet: Integer index 106 read GetIntegerProp write SetIntegerProp stored False;
    property ColWidthUnits: Smallint index 107 read GetSmallintProp write SetSmallintProp stored False;
    property ShowTypeMarkers: WordBool index 108 read GetWordBoolProp write SetWordBoolProp stored False;
    property ShowTabs: Smallint index 109 read GetSmallintProp write SetSmallintProp stored False;
    property ShowEditBar: WordBool index 110 read GetWordBoolProp write SetWordBoolProp stored False;
    property ShowEditBarCellRef: WordBool index 111 read GetWordBoolProp write SetWordBoolProp stored False;
    property AllowDesigner: WordBool index 1 read GetWordBoolProp write SetWordBoolProp stored False;
    property hWnd: OLE_HANDLE read Get_hWnd write Set_hWnd stored False;
    property AllowAutoFill: WordBool index 112 read GetWordBoolProp write SetWordBoolProp stored False;
    property OnClick: TF1BookClick read FOnClick write FOnClick;
    property OnDblClick: TF1BookDblClick read FOnDblClick write FOnDblClick;
    property OnCancelEdit: TNotifyEvent read FOnCancelEdit write FOnCancelEdit;
    property OnSelChange: TNotifyEvent read FOnSelChange write FOnSelChange;
    property OnStartEdit: TF1BookStartEdit read FOnStartEdit write FOnStartEdit;
    property OnEndEdit: TF1BookEndEdit read FOnEndEdit write FOnEndEdit;
    property OnStartRecalc: TNotifyEvent read FOnStartRecalc write FOnStartRecalc;
    property OnEndRecalc: TNotifyEvent read FOnEndRecalc write FOnEndRecalc;
    property OnTopLeftChanged: TNotifyEvent read FOnTopLeftChanged write FOnTopLeftChanged;
    property OnObjClick: TF1BookObjClick read FOnObjClick write FOnObjClick;
    property OnObjDblClick: TF1BookObjDblClick read FOnObjDblClick write FOnObjDblClick;
    property OnRClick: TF1BookRClick read FOnRClick write FOnRClick;
    property OnRDblClick: TF1BookRDblClick read FOnRDblClick write FOnRDblClick;
    property OnObjValueChanged: TF1BookObjValueChanged read FOnObjValueChanged write FOnObjValueChanged;
    property OnModified: TNotifyEvent read FOnModified write FOnModified;
    property OnObjGotFocus: TF1BookObjGotFocus read FOnObjGotFocus write FOnObjGotFocus;
    property OnObjLostFocus: TF1BookObjLostFocus read FOnObjLostFocus write FOnObjLostFocus;
    property OnValidationFailed: TF1BookValidationFailed read FOnValidationFailed write FOnValidationFailed;
  end;

procedure Register;

implementation

uses ComObj;

procedure TF1Book.InitControlData;
const
  CEventDispIDs: array[0..17] of Integer = (
    $00000001, $00000002, $00000003, $00000004, $00000005, $00000006,
    $00000007, $00000008, $00000009, $0000000A, $0000000B, $0000000C,
    $0000000D, $0000000E, $0000000F, $00000010, $00000011, $00000012);
  CLicenseKey: array[0..42] of Word = (
    $0043, $006F, $0070, $0079, $0072, $0069, $0067, $0068, $0074, $0020,
    $0028, $0063, $0029, $0020, $0031, $0039, $0039, $0035, $0020, $0056,
    $0069, $0073, $0075, $0061, $006C, $0020, $0043, $006F, $006D, $0070,
    $006F, $006E, $0065, $006E, $0074, $0073, $002C, $0020, $0049, $006E,
    $0063, $002E, $0000);
  CTPictureIDs: array [0..0] of Integer = (
    $00000062);
  CControlData: TControlData = (
    ClassID: '{042BADC5-5E58-11CE-B610-524153480001}';
    EventIID: '{042BADC7-5E58-11CE-B610-524153480001}';
    EventCount: 18;
    EventDispIDs: @CEventDispIDs;
    LicenseKey: @CLicenseKey;
    Flags: $00000008;
    Version: 300;
    FontCount: 0;
    FontIDs: nil;
    PictureCount: 1;
    PictureIDs: @CTPictureIDs);
begin
  ControlData := @CControlData;
end;

procedure TF1Book.InitControlInterface(const Obj: IUnknown);
begin
  FIntf := Obj as _DVCF1;
end;

procedure TF1Book.EditPasteValues;
begin
  ControlInterface.EditPasteValues;
end;

procedure TF1Book.GetAlignment(var pHorizontal: Smallint; var pWordWrap: WordBool; var pVertical, pOrientation: Smallint);
begin
  ControlInterface.GetAlignment(pHorizontal, pWordWrap, pVertical, pOrientation);
end;

procedure TF1Book.GetBorder(var pLeft, pRight, pTop, pBottom, pShade: Smallint; var pcrLeft, pcrRight, pcrTop, pcrBottom: TColor);
begin
  ControlInterface.GetBorder(pLeft, pRight, pTop, pBottom, pShade, pcrLeft, pcrRight, pcrTop, pcrBottom);
end;

procedure TF1Book.GetFont(var pName: WideString; var pSize: Smallint; var pBold, pItalic, pUnderline, pStrikeout: WordBool; var pcrColor: TColor; var pOutline, pShadow: WordBool);
begin
  ControlInterface.GetFont(pName, pSize, pBold, pItalic, pUnderline, pStrikeout, pcrColor, pOutline, pShadow);
end;

procedure TF1Book.GetLineStyle(var pStyle: Smallint; var pcrColor: TColor; var pWeight: Smallint);
begin
  ControlInterface.GetLineStyle(pStyle, pcrColor, pWeight);
end;

procedure TF1Book.GetPattern(var pPattern: Smallint; var pcrFG, pcrBG: TColor);
begin
  ControlInterface.GetPattern(pPattern, pcrFG, pcrBG);
end;

procedure TF1Book.GetProtection(var pLocked, pHidden: WordBool);
begin
  ControlInterface.GetProtection(pLocked, pHidden);
end;

procedure TF1Book.GetTabbedText(nR1, nC1, nR2, nC2: Integer; bValuesOnly: WordBool; var phText: OLE_HANDLE);
begin
  ControlInterface.GetTabbedText(nR1, nC1, nR2, nC2, bValuesOnly, phText);
end;

procedure TF1Book.SetTabbedText(nStartRow, nStartCol: Integer; var pRows, pCols: Integer; bValuesOnly: WordBool; const pText: WideString);
begin
  ControlInterface.SetTabbedText(nStartRow, nStartCol, pRows, pCols, bValuesOnly, pText);
end;

procedure TF1Book.AddColPageBreak(nCol: Integer);
begin
  ControlInterface.AddColPageBreak(nCol);
end;

procedure TF1Book.AddPageBreak;
begin
  ControlInterface.AddPageBreak;
end;

procedure TF1Book.AddRowPageBreak(nRow: Integer);
begin
  ControlInterface.AddRowPageBreak(nRow);
end;

procedure TF1Book.AddSelection(nR1, nC1, nR2, nC2: Integer);
begin
  ControlInterface.AddSelection(nR1, nC1, nR2, nC2);
end;

procedure TF1Book.Attach(const pTitle: WideString);
begin
  ControlInterface.Attach(pTitle);
end;

procedure TF1Book.AttachToSS(hSrcSS: Integer);
begin
  ControlInterface.AttachToSS(hSrcSS);
end;

procedure TF1Book.CalculationDlg;
begin
  ControlInterface.CalculationDlg;
end;

procedure TF1Book.CancelEdit;
begin
  ControlInterface.CancelEdit;
end;

procedure TF1Book.CheckRecalc;
begin
  ControlInterface.CheckRecalc;
end;

procedure TF1Book.ClearClipboard;
begin
  ControlInterface.ClearClipboard;
end;

procedure TF1Book.ClearRange(nR1, nC1, nR2, nC2: Integer; ClearType: Smallint);
begin
  ControlInterface.ClearRange(nR1, nC1, nR2, nC2, ClearType);
end;

procedure TF1Book.ColorPaletteDlg;
begin
  ControlInterface.ColorPaletteDlg;
end;

procedure TF1Book.ColWidthDlg;
begin
  ControlInterface.ColWidthDlg;
end;

procedure TF1Book.CopyAll(hSrcSS: Integer);
begin
  ControlInterface.CopyAll(hSrcSS);
end;

procedure TF1Book.CopyRange(nDstR1, nDstC1, nDstR2, nDstC2, hSrcSS, nSrcR1, nSrcC1, nSrcR2, nSrcC2: Integer);
begin
  ControlInterface.CopyRange(nDstR1, nDstC1, nDstR2, nDstC2, hSrcSS, nSrcR1, nSrcC1, nSrcR2, nSrcC2);
end;

procedure TF1Book.DefinedNameDlg;
begin
  ControlInterface.DefinedNameDlg;
end;

procedure TF1Book.DeleteDefinedName(const pName: WideString);
begin
  ControlInterface.DeleteDefinedName(pName);
end;

procedure TF1Book.DeleteRange(nR1, nC1, nR2, nC2: Integer; ShiftType: Smallint);
begin
  ControlInterface.DeleteRange(nR1, nC1, nR2, nC2, ShiftType);
end;

procedure TF1Book.Draw(hDC: OLE_HANDLE; x, y, cx, cy, nRow, nCol: Integer; var pRows, pCols: Integer; nFixedRow, nFixedCol, nFixedRows, nFixedCols: Integer);
begin
  ControlInterface.Draw(hDC, x, y, cx, cy, nRow, nCol, pRows, pCols, nFixedRow, nFixedCol, nFixedRows, nFixedCols);
end;

procedure TF1Book.EditClear(ClearType: Smallint);
begin
  ControlInterface.EditClear(ClearType);
end;

procedure TF1Book.EditCopy;
begin
  ControlInterface.EditCopy;
end;

procedure TF1Book.EditCopyDown;
begin
  ControlInterface.EditCopyDown;
end;

procedure TF1Book.EditCopyRight;
begin
  ControlInterface.EditCopyRight;
end;

procedure TF1Book.EditCut;
begin
  ControlInterface.EditCut;
end;

procedure TF1Book.EditDelete(ShiftType: Smallint);
begin
  ControlInterface.EditDelete(ShiftType);
end;

procedure TF1Book.EditInsert(ShiftType: Smallint);
begin
  ControlInterface.EditInsert(ShiftType);
end;

procedure TF1Book.EditPaste;
begin
  ControlInterface.EditPaste;
end;

procedure TF1Book.EndEdit;
begin
  ControlInterface.EndEdit;
end;

procedure TF1Book.FilePageSetupDlg;
begin
  ControlInterface.FilePageSetupDlg;
end;

procedure TF1Book.FilePrint(bShowPrintDlg: WordBool);
begin
  ControlInterface.FilePrint(bShowPrintDlg);
end;

procedure TF1Book.FilePrintSetupDlg;
begin
  ControlInterface.FilePrintSetupDlg;
end;

procedure TF1Book.FormatAlignmentDlg;
begin
  ControlInterface.FormatAlignmentDlg;
end;

procedure TF1Book.FormatBorderDlg;
begin
  ControlInterface.FormatBorderDlg;
end;

procedure TF1Book.FormatCurrency0;
begin
  ControlInterface.FormatCurrency0;
end;

procedure TF1Book.FormatCurrency2;
begin
  ControlInterface.FormatCurrency2;
end;

procedure TF1Book.FormatDefaultFontDlg;
begin
  ControlInterface.FormatDefaultFontDlg;
end;

procedure TF1Book.FormatFixed;
begin
  ControlInterface.FormatFixed;
end;

procedure TF1Book.FormatFixed2;
begin
  ControlInterface.FormatFixed2;
end;

procedure TF1Book.FormatFontDlg;
begin
  ControlInterface.FormatFontDlg;
end;

procedure TF1Book.FormatFraction;
begin
  ControlInterface.FormatFraction;
end;

procedure TF1Book.FormatGeneral;
begin
  ControlInterface.FormatGeneral;
end;

procedure TF1Book.FormatHmmampm;
begin
  ControlInterface.FormatHmmampm;
end;

procedure TF1Book.FormatMdyy;
begin
  ControlInterface.FormatMdyy;
end;

procedure TF1Book.FormatNumberDlg;
begin
  ControlInterface.FormatNumberDlg;
end;

procedure TF1Book.FormatPatternDlg;
begin
  ControlInterface.FormatPatternDlg;
end;

procedure TF1Book.FormatPercent;
begin
  ControlInterface.FormatPercent;
end;

procedure TF1Book.FormatScientific;
begin
  ControlInterface.FormatScientific;
end;

procedure TF1Book.GetActiveCell(var pRow, pCol: Integer);
begin
  ControlInterface.GetActiveCell(pRow, pCol);
end;

procedure TF1Book.GetDefaultFont(var pBuf: WideString; var pSize: Smallint);
begin
  ControlInterface.GetDefaultFont(pBuf, pSize);
end;

procedure TF1Book.GetHdrSelection(var pTopLeftHdr, pRowHdr, pColHdr: WordBool);
begin
  ControlInterface.GetHdrSelection(pTopLeftHdr, pRowHdr, pColHdr);
end;

procedure TF1Book.GetIteration(var pIteration: WordBool; var pMaxIterations: Smallint; var pMaxChange: Double);
begin
  ControlInterface.GetIteration(pIteration, pMaxIterations, pMaxChange);
end;

procedure TF1Book.GetPrintScale(var pScale: Smallint; var pFitToPage: WordBool; var pVPages, pHPages: Integer);
begin
  ControlInterface.GetPrintScale(pScale, pFitToPage, pVPages, pHPages);
end;

procedure TF1Book.GetSelection(nSelection: Smallint; var pR1, pC1, pR2, pC2: Integer);
begin
  ControlInterface.GetSelection(nSelection, pR1, pC1, pR2, pC2);
end;

procedure TF1Book.GotoDlg;
begin
  ControlInterface.GotoDlg;
end;

procedure TF1Book.HeapMin;
begin
  ControlInterface.HeapMin;
end;

procedure TF1Book.InitTable;
begin
  ControlInterface.InitTable;
end;

procedure TF1Book.InsertRange(nR1, nC1, nR2, nC2: Integer; ShiftType: Smallint);
begin
  ControlInterface.InsertRange(nR1, nC1, nR2, nC2, ShiftType);
end;

procedure TF1Book.LineStyleDlg;
begin
  ControlInterface.LineStyleDlg;
end;

procedure TF1Book.MoveRange(nR1, nC1, nR2, nC2, nRowOffset, nColOffset: Integer);
begin
  ControlInterface.MoveRange(nR1, nC1, nR2, nC2, nRowOffset, nColOffset);
end;

procedure TF1Book.ObjAddItem(ID: Integer; const pItem: WideString);
begin
  ControlInterface.ObjAddItem(ID, pItem);
end;

procedure TF1Book.ObjAddSelection(ID: Integer);
begin
  ControlInterface.ObjAddSelection(ID);
end;

procedure TF1Book.ObjBringToFront;
begin
  ControlInterface.ObjBringToFront;
end;

procedure TF1Book.ObjDeleteItem(ID: Integer; nItem: Smallint);
begin
  ControlInterface.ObjDeleteItem(ID, nItem);
end;

procedure TF1Book.ObjGetCell(ID: Integer; var pControlCellType: Smallint; var pRow, pCol: Integer);
begin
  ControlInterface.ObjGetCell(ID, pControlCellType, pRow, pCol);
end;

procedure TF1Book.ObjGetPos(ID: Integer; var pX1, pY1, pX2, pY2: Single);
begin
  ControlInterface.ObjGetPos(ID, pX1, pY1, pX2, pY2);
end;

procedure TF1Book.ObjGetSelection(nSelection: Smallint; var pID: Integer);
begin
  ControlInterface.ObjGetSelection(nSelection, pID);
end;

procedure TF1Book.ObjInsertItem(ID: Integer; nItem: Smallint; const pItem: WideString);
begin
  ControlInterface.ObjInsertItem(ID, nItem, pItem);
end;

procedure TF1Book.ObjNameDlg;
begin
  ControlInterface.ObjNameDlg;
end;

procedure TF1Book.ObjNew(ObjType: Smallint; nX1, nY1, nX2, nY2: Single; var pID: Integer);
begin
  ControlInterface.ObjNew(ObjType, nX1, nY1, nX2, nY2, pID);
end;

procedure TF1Book.ObjNewPicture(nX1, nY1, nX2, nY2: Single; var pID: Integer; hMF: OLE_HANDLE; nMapMode, nWndExtentX, nWndExtentY: Integer);
begin
  ControlInterface.ObjNewPicture(nX1, nY1, nX2, nY2, pID, hMF, nMapMode, nWndExtentX, nWndExtentY);
end;

procedure TF1Book.ObjOptionsDlg;
begin
  ControlInterface.ObjOptionsDlg;
end;

procedure TF1Book.ObjPosToTwips(nX1, nY1, nX2, nY2: Single; var pX, pY, pCX, pCY: Integer; var pShown: Smallint);
begin
  ControlInterface.ObjPosToTwips(nX1, nY1, nX2, nY2, pX, pY, pCX, pCY, pShown);
end;

procedure TF1Book.ObjSendToBack;
begin
  ControlInterface.ObjSendToBack;
end;

procedure TF1Book.ObjSetCell(ID: Integer; ControlCellType: Smallint; nRow, nCol: Integer);
begin
  ControlInterface.ObjSetCell(ID, ControlCellType, nRow, nCol);
end;

procedure TF1Book.ObjSetPicture(ID: Integer; hMF: OLE_HANDLE; nMapMode: Smallint; nWndExtentX, nWndExtentY: Integer);
begin
  ControlInterface.ObjSetPicture(ID, hMF, nMapMode, nWndExtentX, nWndExtentY);
end;

procedure TF1Book.ObjSetPos(ID: Integer; nX1, nY1, nX2, nY2: Single);
begin
  ControlInterface.ObjSetPos(ID, nX1, nY1, nX2, nY2);
end;

procedure TF1Book.ObjSetSelection(ID: Integer);
begin
  ControlInterface.ObjSetSelection(ID);
end;

procedure TF1Book.OpenFileDlg(const pTitle: WideString; hWndParent: OLE_HANDLE; var pBuf: WideString);
begin
  ControlInterface.OpenFileDlg(pTitle, hWndParent, pBuf);
end;

procedure TF1Book.ProtectionDlg;
begin
  ControlInterface.ProtectionDlg;
end;

procedure TF1Book.RangeToTwips(nRow1, nCol1, nRow2, nCol2: Integer; var pX, pY, pCX, pCY: Integer; var pShown: Smallint);
begin
  ControlInterface.RangeToTwips(nRow1, nCol1, nRow2, nCol2, pX, pY, pCX, pCY, pShown);
end;

procedure TF1Book.Read(const pPathName: WideString; var pFileType: Smallint);
begin
  ControlInterface.Read(pPathName, pFileType);
end;

procedure TF1Book.ReadFromBlob(hBlob: OLE_HANDLE; nReservedBytes: Smallint);
begin
  ControlInterface.ReadFromBlob(hBlob, nReservedBytes);
end;

procedure TF1Book.Recalc;
begin
  ControlInterface.Recalc;
end;

procedure TF1Book.RemoveColPageBreak(nCol: Integer);
begin
  ControlInterface.RemoveColPageBreak(nCol);
end;

procedure TF1Book.RemovePageBreak;
begin
  ControlInterface.RemovePageBreak;
end;

procedure TF1Book.RemoveRowPageBreak(nRow: Integer);
begin
  ControlInterface.RemoveRowPageBreak(nRow);
end;

procedure TF1Book.RowHeightDlg;
begin
  ControlInterface.RowHeightDlg;
end;

procedure TF1Book.SaveFileDlg(const pTitle: WideString; var pBuf: WideString; var pFileType: Smallint);
begin
  ControlInterface.SaveFileDlg(pTitle, pBuf, pFileType);
end;

procedure TF1Book.SaveWindowInfo;
begin
  ControlInterface.SaveWindowInfo;
end;

procedure TF1Book.SetActiveCell(nRow, nCol: Integer);
begin
  ControlInterface.SetActiveCell(nRow, nCol);
end;

procedure TF1Book.SetAlignment(HAlign: Smallint; bWordWrap: WordBool; VAlign, nOrientation: Smallint);
begin
  ControlInterface.SetAlignment(HAlign, bWordWrap, VAlign, nOrientation);
end;

procedure TF1Book.SetBorder(nOutline, nLeft, nRight, nTop, nBottom, nShade: Smallint; crOutline, crLeft, crRight, crTop, crBottom: TColor);
begin
  ControlInterface.SetBorder(nOutline, nLeft, nRight, nTop, nBottom, nShade, crOutline, crLeft, crRight, crTop, crBottom);
end;

procedure TF1Book.SetColWidth(nC1, nC2: Integer; nWidth: Smallint; bDefColWidth: WordBool);
begin
  ControlInterface.SetColWidth(nC1, nC2, nWidth, bDefColWidth);
end;

procedure TF1Book.SetColWidthAuto(nR1, nC1, nR2, nC2: Integer; bSetDefaults: WordBool);
begin
  ControlInterface.SetColWidthAuto(nR1, nC1, nR2, nC2, bSetDefaults);
end;

procedure TF1Book.SetDefaultFont(const pName: WideString; nSize: Smallint);
begin
  ControlInterface.SetDefaultFont(pName, nSize);
end;

procedure TF1Book.SetFont(const pName: WideString; nSize: Smallint; bBold, bItalic, bUnderline, bStrikeout: WordBool; crColor: TColor; bOutline, bShadow: WordBool);
begin
  ControlInterface.SetFont(pName, nSize, bBold, bItalic, bUnderline, bStrikeout, crColor, bOutline, bShadow);
end;

procedure TF1Book.SetHdrSelection(bTopLeftHdr, bRowHdr, bColHdr: WordBool);
begin
  ControlInterface.SetHdrSelection(bTopLeftHdr, bRowHdr, bColHdr);
end;

procedure TF1Book.SetIteration(bIteration: WordBool; nMaxIterations: Smallint; nMaxChange: Double);
begin
  ControlInterface.SetIteration(bIteration, nMaxIterations, nMaxChange);
end;

procedure TF1Book.SetLineStyle(nStyle: Smallint; crColor: TColor; nWeight: Smallint);
begin
  ControlInterface.SetLineStyle(nStyle, crColor, nWeight);
end;

procedure TF1Book.SetPattern(nPattern: Smallint; crFG, crBG: TColor);
begin
  ControlInterface.SetPattern(nPattern, crFG, crBG);
end;

procedure TF1Book.SetPrintAreaFromSelection;
begin
  ControlInterface.SetPrintAreaFromSelection;
end;

procedure TF1Book.SetPrintScale(nScale: Smallint; bFitToPage: WordBool; nVPages, nHPages: Smallint);
begin
  ControlInterface.SetPrintScale(nScale, bFitToPage, nVPages, nHPages);
end;

procedure TF1Book.SetPrintTitlesFromSelection;
begin
  ControlInterface.SetPrintTitlesFromSelection;
end;

procedure TF1Book.SetProtection(bLocked, bHidden: WordBool);
begin
  ControlInterface.SetProtection(bLocked, bHidden);
end;

procedure TF1Book.SetRowHeight(nR1, nR2: Integer; nHeight: Smallint; bDefRowHeight: WordBool);
begin
  ControlInterface.SetRowHeight(nR1, nR2, nHeight, bDefRowHeight);
end;

procedure TF1Book.SetRowHeightAuto(nR1, nC1, nR2, nC2: Integer; bSetDefaults: WordBool);
begin
  ControlInterface.SetRowHeightAuto(nR1, nC1, nR2, nC2, bSetDefaults);
end;

procedure TF1Book.SetSelection(nR1, nC1, nR2, nC2: Integer);
begin
  ControlInterface.SetSelection(nR1, nC1, nR2, nC2);
end;

procedure TF1Book.ShowActiveCell;
begin
  ControlInterface.ShowActiveCell;
end;

procedure TF1Book.Sort3(nR1, nC1, nR2, nC2: Integer; bSortByRows: WordBool; nKey1, nKey2, nKey3: Integer);
begin
  ControlInterface.Sort3(nR1, nC1, nR2, nC2, bSortByRows, nKey1, nKey2, nKey3);
end;

procedure TF1Book.SortDlg;
begin
  ControlInterface.SortDlg;
end;

procedure TF1Book.StartEdit(bClear, bInCellEditFocus, bArrowsExitEditMode: WordBool);
begin
  ControlInterface.StartEdit(bClear, bInCellEditFocus, bArrowsExitEditMode);
end;

procedure TF1Book.SwapTables(hSS2: Integer);
begin
  ControlInterface.SwapTables(hSS2);
end;

procedure TF1Book.TransactCommit;
begin
  ControlInterface.TransactCommit;
end;

procedure TF1Book.TransactRollback;
begin
  ControlInterface.TransactRollback;
end;

procedure TF1Book.TransactStart;
begin
  ControlInterface.TransactStart;
end;

procedure TF1Book.TwipsToRC(x, y: Integer; var pRow, pCol: Integer);
begin
  ControlInterface.TwipsToRC(x, y, pRow, pCol);
end;

procedure TF1Book.SSUpdate;
begin
  ControlInterface.SSUpdate;
end;

function TF1Book.SSVersion: Smallint;
begin
  Result := ControlInterface.SSVersion;
end;

procedure TF1Book.Write(const pPathName: WideString; FileType: Smallint);
begin
  ControlInterface.Write(pPathName, FileType);
end;

procedure TF1Book.WriteToBlob(var phBlob: OLE_HANDLE; nReservedBytes: Smallint);
begin
  ControlInterface.WriteToBlob(phBlob, nReservedBytes);
end;

procedure TF1Book.SetRowHidden(nRow1, nRow2: Integer; bHidden: WordBool);
begin
  ControlInterface.SetRowHidden(nRow1, nRow2, bHidden);
end;

procedure TF1Book.SetColHidden(nCol1, nCol2: Integer; bHidden: WordBool);
begin
  ControlInterface.SetColHidden(nCol1, nCol2, bHidden);
end;

procedure TF1Book.SetColWidthTwips(nCol1, nCol2, nWidth: Integer; bDefColWidth: WordBool);
begin
  ControlInterface.SetColWidthTwips(nCol1, nCol2, nWidth, bDefColWidth);
end;

procedure TF1Book.EditInsertSheets;
begin
  ControlInterface.EditInsertSheets;
end;

procedure TF1Book.EditDeleteSheets;
begin
  ControlInterface.EditDeleteSheets;
end;

procedure TF1Book.InsertSheets(nSheet, nSheets: Integer);
begin
  ControlInterface.InsertSheets(nSheet, nSheets);
end;

procedure TF1Book.DeleteSheets(nSheet, nSheets: Integer);
begin
  ControlInterface.DeleteSheets(nSheet, nSheets);
end;

procedure TF1Book.Refresh;
begin
  ControlInterface.Refresh;
end;

function TF1Book.NextColPageBreak(Col: Integer): Integer;
begin
  Result := ControlInterface.NextColPageBreak(Col);
end;

function TF1Book.NextRowPageBreak(Row: Integer): Integer;
begin
  Result := ControlInterface.NextRowPageBreak(Row);
end;

function TF1Book.ObjFirstID: Integer;
begin
  Result := ControlInterface.ObjFirstID;
end;

function TF1Book.ObjNextID(ID: Integer): Integer;
begin
  Result := ControlInterface.ObjNextID(ID);
end;

function TF1Book.ObjGetItemCount(ID: Integer): Smallint;
begin
  Result := ControlInterface.ObjGetItemCount(ID);
end;

function TF1Book.ObjGetType(ID: Integer): Smallint;
begin
  Result := ControlInterface.ObjGetType(ID);
end;

function TF1Book.ObjGetSelectionCount: Smallint;
begin
  Result := ControlInterface.ObjGetSelectionCount;
end;

function TF1Book.FormatRCNr(Row, Col: Integer; DoAbsolute: WordBool): WideString;
begin
  Result := ControlInterface.FormatRCNr(Row, Col, DoAbsolute);
end;

function TF1Book.SS: Integer;
begin
  Result := ControlInterface.SS;
end;

function TF1Book.ErrorNumberToText(SSError: Integer): WideString;
begin
  Result := ControlInterface.ErrorNumberToText(SSError);
end;

function TF1Book.ObjNameToID(const Name: WideString): Integer;
begin
  Result := ControlInterface.ObjNameToID(Name);
end;

function TF1Book.DefinedNameCount: Integer;
begin
  Result := ControlInterface.DefinedNameCount;
end;

procedure TF1Book.ValidationRuleDlg;
begin
  ControlInterface.ValidationRuleDlg;
end;

procedure TF1Book.SetValidationRule(const Rule, Text: WideString);
begin
  ControlInterface.SetValidationRule(Rule, Text);
end;

procedure TF1Book.GetValidationRule(var Rule, Text: WideString);
begin
  ControlInterface.GetValidationRule(Rule, Text);
end;

function TF1Book.AutoFillItemsCount: Smallint;
begin
  Result := ControlInterface.AutoFillItemsCount;
end;

procedure TF1Book.CopyRangeEx(nDstSheet, nDstR1, nDstC1, nDstR2, nDstC2, hSrcSS, nSrcSheet, nSrcR1, nSrcC1, nSrcR2, nSrcC2: Integer);
begin
  ControlInterface.CopyRangeEx(nDstSheet, nDstR1, nDstC1, nDstR2, nDstC2, hSrcSS, nSrcSheet, nSrcR1, nSrcC1, nSrcR2, nSrcC2);
end;

procedure TF1Book.Sort(nR1, nC1, nR2, nC2: Integer; bSortByRows: WordBool; Keys: OleVariant);
begin
  ControlInterface.Sort(nR1, nC1, nR2, nC2, bSortByRows, Keys);
end;

procedure TF1Book.DeleteAutoFillItems(nIndex: Smallint);
begin
  ControlInterface.DeleteAutoFillItems(nIndex);
end;

procedure TF1Book.ODBCConnect(var pConnect: WideString; bShowErrors: WordBool; var pRetCode: Smallint);
begin
  ControlInterface.ODBCConnect(pConnect, bShowErrors, pRetCode);
end;

procedure TF1Book.ODBCDisconnect;
begin
  ControlInterface.ODBCDisconnect;
end;

procedure TF1Book.ODBCQuery(var pQuery: WideString; nRow, nCol: Integer; bForceShowDlg: WordBool; var pSetColNames, pSetColFormats, pSetColWidths, pSetMaxRC: WordBool; var pRetCode: Smallint);
begin
  ControlInterface.ODBCQuery(pQuery, nRow, nCol, bForceShowDlg, pSetColNames, pSetColFormats, pSetColWidths, pSetMaxRC, pRetCode);
end;

procedure TF1Book.LaunchDesigner;
begin
  ControlInterface.LaunchDesigner;
end;

procedure TF1Book.AboutBox;
begin
  ControlInterface.AboutBox;
end;

function TF1Book.Get_PrintDevMode: OLE_HANDLE;
begin
  Result := ControlInterface.PrintDevMode;
end;

procedure TF1Book.Set_PrintDevMode(var Value: OLE_HANDLE);
begin
  ControlInterface.PrintDevMode := Value;
end;

function TF1Book.Get_hWnd: OLE_HANDLE;
begin
  Result := ControlInterface.hWnd;
end;

procedure TF1Book.Set_hWnd(var Value: OLE_HANDLE);
begin
  ControlInterface.hWnd := Value;
end;

function TF1Book.Get_ColText(nCol: Integer): WideString;
begin
  Result := ControlInterface.ColText[nCol];
end;

procedure TF1Book.Set_ColText(nCol: Integer; const Value: WideString);
begin
  ControlInterface.ColText[nCol] := Value;
end;

function TF1Book.Get_DefinedName(const pName: WideString): WideString;
begin
  Result := ControlInterface.DefinedName[pName];
end;

procedure TF1Book.Set_DefinedName(const pName: WideString; const Value: WideString);
begin
  ControlInterface.DefinedName[pName] := Value;
end;

function TF1Book.Get_EntryRC(nRow, nCol: Integer): WideString;
begin
  Result := ControlInterface.EntryRC[nRow, nCol];
end;

procedure TF1Book.Set_EntryRC(nRow, nCol: Integer; const Value: WideString);
begin
  ControlInterface.EntryRC[nRow, nCol] := Value;
end;

function TF1Book.Get_FormattedTextRC(nRow, nCol: Integer): WideString;
begin
  Result := ControlInterface.FormattedTextRC[nRow, nCol];
end;

procedure TF1Book.Set_FormattedTextRC(nRow, nCol: Integer; const Value: WideString);
begin
  ControlInterface.FormattedTextRC[nRow, nCol] := Value;
end;

function TF1Book.Get_FormulaRC(nRow, nCol: Integer): WideString;
begin
  Result := ControlInterface.FormulaRC[nRow, nCol];
end;

procedure TF1Book.Set_FormulaRC(nRow, nCol: Integer; const Value: WideString);
begin
  ControlInterface.FormulaRC[nRow, nCol] := Value;
end;

function TF1Book.Get_LastColForRow(nRow: Integer): Integer;
begin
  Result := ControlInterface.LastColForRow[nRow];
end;

procedure TF1Book.Set_LastColForRow(nRow: Integer; Value: Integer);
begin
  ControlInterface.LastColForRow[nRow] := Value;
end;

function TF1Book.Get_LogicalRC(nRow, nCol: Integer): WordBool;
begin
  Result := ControlInterface.LogicalRC[nRow, nCol];
end;

procedure TF1Book.Set_LogicalRC(nRow, nCol: Integer; Value: WordBool);
begin
  ControlInterface.LogicalRC[nRow, nCol] := Value;
end;

function TF1Book.Get_NumberRC(nRow, nCol: Integer): Double;
begin
  Result := ControlInterface.NumberRC[nRow, nCol];
end;

procedure TF1Book.Set_NumberRC(nRow, nCol: Integer; Value: Double);
begin
  ControlInterface.NumberRC[nRow, nCol] := Value;
end;

function TF1Book.Get_RowText(nRow: Integer): WideString;
begin
  Result := ControlInterface.RowText[nRow];
end;

procedure TF1Book.Set_RowText(nRow: Integer; const Value: WideString);
begin
  ControlInterface.RowText[nRow] := Value;
end;

function TF1Book.Get_TextRC(nRow, nCol: Integer): WideString;
begin
  Result := ControlInterface.TextRC[nRow, nCol];
end;

procedure TF1Book.Set_TextRC(nRow, nCol: Integer; const Value: WideString);
begin
  ControlInterface.TextRC[nRow, nCol] := Value;
end;

function TF1Book.Get_TypeRC(nRow, nCol: Integer): Smallint;
begin
  Result := ControlInterface.TypeRC[nRow, nCol];
end;

procedure TF1Book.Set_TypeRC(nRow, nCol: Integer; Value: Smallint);
begin
  ControlInterface.TypeRC[nRow, nCol] := Value;
end;

function TF1Book.Get_ColWidth(nCol: Integer): Smallint;
begin
  Result := ControlInterface.ColWidth[nCol];
end;

procedure TF1Book.Set_ColWidth(nCol: Integer; Value: Smallint);
begin
  ControlInterface.ColWidth[nCol] := Value;
end;

function TF1Book.Get_RowHeight(nRow: Integer): Smallint;
begin
  Result := ControlInterface.RowHeight[nRow];
end;

procedure TF1Book.Set_RowHeight(nRow: Integer; Value: Smallint);
begin
  ControlInterface.RowHeight[nRow] := Value;
end;

function TF1Book.Get_DefinedNameByIndex(nName: Integer): WideString;
begin
  Result := ControlInterface.DefinedNameByIndex[nName];
end;

procedure TF1Book.Set_DefinedNameByIndex(nName: Integer; const Value: WideString);
begin
  ControlInterface.DefinedNameByIndex[nName] := Value;
end;

function TF1Book.Get_SheetName(nSheet: Integer): WideString;
begin
  Result := ControlInterface.SheetName[nSheet];
end;

procedure TF1Book.Set_SheetName(nSheet: Integer; const Value: WideString);
begin
  ControlInterface.SheetName[nSheet] := Value;
end;

function TF1Book.Get_PaletteEntry(nEntry: Integer): TColor;
begin
  Result := ControlInterface.PaletteEntry[nEntry];
end;

procedure TF1Book.Set_PaletteEntry(nEntry: Integer; Value: TColor);
begin
  ControlInterface.PaletteEntry[nEntry] := Value;
end;

function TF1Book.Get_ColWidthTwips(Col: Integer): Smallint;
begin
  Result := ControlInterface.ColWidthTwips[Col];
end;

procedure TF1Book.Set_ColWidthTwips(Col: Integer; Value: Smallint);
begin
  ControlInterface.ColWidthTwips[Col] := Value;
end;

function TF1Book.Get_ObjItem(ID: Integer; Item: Smallint): WideString;
begin
  Result := ControlInterface.ObjItem[ID, Item];
end;

procedure TF1Book.Set_ObjItem(ID: Integer; Item: Smallint; const Value: WideString);
begin
  ControlInterface.ObjItem[ID, Item] := Value;
end;

function TF1Book.Get_ObjItems(ID: Integer): WideString;
begin
  Result := ControlInterface.ObjItems[ID];
end;

procedure TF1Book.Set_ObjItems(ID: Integer; const Value: WideString);
begin
  ControlInterface.ObjItems[ID] := Value;
end;

function TF1Book.Get_ObjName(ID: Integer): WideString;
begin
  Result := ControlInterface.ObjName[ID];
end;

procedure TF1Book.Set_ObjName(ID: Integer; const Value: WideString);
begin
  ControlInterface.ObjName[ID] := Value;
end;

function TF1Book.Get_ObjText(ID: Integer): WideString;
begin
  Result := ControlInterface.ObjText[ID];
end;

procedure TF1Book.Set_ObjText(ID: Integer; const Value: WideString);
begin
  ControlInterface.ObjText[ID] := Value;
end;

function TF1Book.Get_ObjValue(ID: Integer): Smallint;
begin
  Result := ControlInterface.ObjValue[ID];
end;

procedure TF1Book.Set_ObjValue(ID: Integer; Value: Smallint);
begin
  ControlInterface.ObjValue[ID] := Value;
end;

function TF1Book.Get_ObjVisible(ID: Integer): WordBool;
begin
  Result := ControlInterface.ObjVisible[ID];
end;

procedure TF1Book.Set_ObjVisible(ID: Integer; Value: WordBool);
begin
  ControlInterface.ObjVisible[ID] := Value;
end;

function TF1Book.Get_AutoFillItems(Index: Smallint): WideString;
begin
  Result := ControlInterface.AutoFillItems[Index];
end;

procedure TF1Book.Set_AutoFillItems(Index: Smallint; const Value: WideString);
begin
  ControlInterface.AutoFillItems[Index] := Value;
end;

function TF1Book.Get_ColHidden(nCol: Integer): WordBool;
begin
  Result := ControlInterface.ColHidden[nCol];
end;

procedure TF1Book.Set_ColHidden(nCol: Integer; Value: WordBool);
begin
  ControlInterface.ColHidden[nCol] := Value;
end;

function TF1Book.Get_RowHidden(nRow: Integer): WordBool;
begin
  Result := ControlInterface.RowHidden[nRow];
end;

procedure TF1Book.Set_RowHidden(nRow: Integer; Value: WordBool);
begin
  ControlInterface.RowHidden[nRow] := Value;
end;

function TF1Book.Get_SheetSelected(nSheet: Integer): WordBool;
begin
  Result := ControlInterface.SheetSelected[nSheet];
end;

procedure TF1Book.Set_SheetSelected(nSheet: Integer; Value: WordBool);
begin
  ControlInterface.SheetSelected[nSheet] := Value;
end;


procedure Register;
begin
  RegisterComponents('ActiveX', [TF1Book]);  { do not localize }
end;

end.
