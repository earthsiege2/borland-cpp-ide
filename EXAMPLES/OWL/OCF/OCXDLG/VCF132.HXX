// Type Library: vcf132.ocx  VCI Formula One Library
// VCIF1Lib 1.0 {042BADC8-5E58-11CE-B610-524153480001}\0

#if !defined(_PROXY_VCF132_HXX)
#define	_PROXY_VCF132_HXX

#include <ocf/automacr.h>

class _DVCF1;

// TKIND_ENUM: F1ColWidthUnitsConstants {042BADD0-5E58-11CE-B610-524153480001}\409 Specify how column widths are stored and displayed

enum F1ColWidthUnitsConstants {
  F1ColWidthUnitsCharacters,
  F1ColWidthUnitsTwips,
};

// TKIND_ENUM: F1MousePointerConstants {042BADD1-5E58-11CE-B610-524153480001}\409 Specify appearance of mouse.

enum F1MousePointerConstants {
  F1Default,
  F1Arrow,
  F1Cross,
  F1IBeam,
  F1Icon,
  F1Size,
  F1SizeNESW,
  F1SizeNS,
  F1SizeNWSE,
  F1SizeWE,
  F1UpArrow,
  F1Hourglass,
  F1NoDrop,
  F1Custom,
};

// TKIND_ENUM: F1ShowOffOnAutoConstants {042BADD2-5E58-11CE-B610-524153480001}\409 Specifies behaviour of scroll bars and selections.

enum F1ShowOffOnAutoConstants {
  F1Off,
  F1On,
  F1Auto,
};

// TKIND_ENUM: F1ShowTabsConstants {042BADD3-5E58-11CE-B610-524153480001}\409 Specify sheet tab behavior.

enum F1ShowTabsConstants {
  F1TabsOff,
  F1TabsBottom,
  F1TabsTop,
};

// TKIND_ENUM: F1ModeConstants {042BADD4-5E58-11CE-B610-524153480001}\409 Specify cursor mode for drawing objects.

enum F1ModeConstants {
  F1ModeNormal,
  F1ModeLine,
  F1ModeRectangle,
  F1ModeOval,
  F1ModeArc,
  F1ModeChart,
  F1ModeField,
  F1ModeButton,
  F1ModePolygon,
  F1ModeCheckBox,
  F1ModeDropDown,
};

// TKIND_ENUM: F1PolyEditModeConstants {042BADD5-5E58-11CE-B610-524153480001}\409 Specify polygon editing mode.

enum F1PolyEditModeConstants {
  F1PolyEditModeNormal,
  F1PolyEditModePoints,
};

// TKIND_ENUM: F1ShiftTypeConstants {042BADD6-5E58-11CE-B610-524153480001}\409 Specify how data is shifted when new cells are inserted or deleted.

enum F1ShiftTypeConstants {
  F1ShiftHorizontal,
  F1ShiftVertical,
  F1ShiftRows,
  F1ShiftCols,
};

// TKIND_ENUM: F1HAlignConstants {042BADD7-5E58-11CE-B610-524153480001}\409 Specify how data is aligned horizontally.

enum F1HAlignConstants {
  F1HAlignGeneral,
  F1HAlignLeft,
  F1HAlignCenter,
  F1HAlignRight,
  F1HAlignFill,
  F1HAlignJustify,
  F1HAlignCenterAcrossCells,
};

// TKIND_ENUM: F1VAlignConstants {042BADD8-5E58-11CE-B610-524153480001}\409 Specify how data is aligned vertically.

enum F1VAlignConstants {
  F1VAlignTop,
  F1VAlignCenter,
  F1VAlignBottom,
};

// TKIND_ENUM: F1ClearTypeConstants {042BADD9-5E58-11CE-B610-524153480001}\409 Specify how data is cleared.

enum F1ClearTypeConstants {
  F1ClearDlg,
  F1ClearAll,
  F1ClearFormats,
  F1ClearValues,
};

// TKIND_ENUM: F1FileTypeConstants {042BADDA-5E58-11CE-B610-524153480001}\409 Specify a file type.

enum F1FileTypeConstants {
  F1FileFormulaOne,
  F1FileExcel4,
  F1FileTabbedText,
  F1FileExcel5,
  F1FileFormulaOne3,
  F1FileTabbedTextValuesOnly,
};

// TKIND_ENUM: F1ObjTypeConstants {042BADDB-5E58-11CE-B610-524153480001}\409 Specify an object type.

enum F1ObjTypeConstants {
  F1ObjLine,
  F1ObjRectangle,
  F1ObjOval,
  F1ObjArc,
  F1ObjChart,
  F1ObjButton,
  F1ObjPolygon,
  F1ObjCheckBox,
  F1ObjDropDown,
  F1ObjPicture,
};

// TKIND_ENUM: F1ErrorConstants {042BADDC-5E58-11CE-B610-524153480001}\409 Formula One error constants.

enum F1ErrorConstants {
  F1ErrorNone,
  F1ErrorGeneral,
  F1ErrorBadArgument,
  F1ErrorNoMemory,
  F1ErrorBadFormula,
  F1ErrorBufTooShort,
  F1ErrorNotFound,
  F1ErrorBadRC,
  F1ErrorBadHSS,
  F1ErrorTooManyHSS,
  F1ErrorNoTable,
  F1ErrorUnableToOpenFile,
  F1ErrorInvalidFile,
  F1ErrorInsertShiftOffTable,
  F1ErrorOnlyOneRange,
  F1ErrorNothingToPaste,
  F1ErrorBadNumberFormat,
  F1ErrorTooManyFonts,
  F1ErrorTooManySelectedRanges,
  F1ErrorUnableToWriteFile,
  F1ErrorNoTransaction,
  F1ErrorNothingToPrint,
  F1ErrorPrintMarginsDontFit,
  F1ErrorCancel,
  F1ErrorUnableToInitializePrinter,
  F1ErrorStringTooLong,
  F1ErrorFormulaTooLong,
  F1ErrorUnableToOpenClipboard,
  F1ErrorPasteWouldOverflowSheet,
  F1ErrorLockedCellsCannotBeModified,
  F1ErrorLockedDocCannotBeModified,
  F1ErrorInvalidName,
  F1ErrorCannotDeleteNameInUse,
  F1ErrorUnableToFindName,
  F1ErrorNoWindow,
  F1ErrorSelection,
  F1ErrorTooManyObjects,
  F1ErrorInvalidObjectType,
  F1ErrorObjectNotFound,
  F1ErrorInvalidRequest,
  F1ErrorBadValidationRule,
  F1ErrorBadInputMask,
  F1ErrorValidationFailed,
  F1ErrorNoODBCConnection,
  F1ErrorUnableToLoadODBC,
  F1ErrorUnsupportedFeature,
};

// TKIND_ENUM: F1ControlCellConstants {042BADDD-5E58-11CE-B610-524153480001}\409 Specify cell reference behavior for list box.

enum F1ControlCellConstants {
  F1ControlNoCell,
  F1ControlCellValue,
  F1ControlCellText,
};

// TKIND_DISPATCH: _DVCF1 {042BADC6-5E58-11CE-B610-524153480001}\409 Dispatch interface for Formula One Workbook

class _DVCF1 : public TAutoProxy {
  public:
    _DVCF1() : TAutoProxy(0x409) {}
    // Sets or returns the background color of the view.
    OLE_COLOR GetBackColor();     // [id(3), prop r/w]
    void SetBackColor(OLE_COLOR); // [id(3), prop r/w]
    // Determines the active column in the worksheet.
    long GetCol();     // [id(4), prop r/w]
    void SetCol(long); // [id(4), prop r/w]
    // Determines the active row in the worksheet.
    long GetRow();     // [id(5), prop r/w]
    void SetRow(long); // [id(5), prop r/w]
    // Sets or returns the horizontal scroll bar display status.
    short GetShowHScrollBar();     // [id(6), prop r/w]
    void SetShowHScrollBar(short); // [id(6), prop r/w]
    // Sets or returns the text value of the active cell.
    TAutoString GetText();     // [id(7), prop r/w]
    void SetText(TAutoString); // [id(7), prop r/w]
    // Sets or returns the numeric value of the active cell.
    double GetNumber();     // [id(8), prop r/w]
    void SetNumber(double); // [id(8), prop r/w]
    // Sets or returns the text version of the formula in the active cell.
    TAutoString GetFormula();     // [id(9), prop r/w]
    void SetFormula(TAutoString); // [id(9), prop r/w]
    // Sets or returns the starting fixed column.
    long GetFixedCol();     // [id(10), prop r/w]
    void SetFixedCol(long); // [id(10), prop r/w]
    // Sets or returns the number of fixed columns.
    long GetFixedCols();     // [id(11), prop r/w]
    void SetFixedCols(long); // [id(11), prop r/w]
    // Sets or returns the starting fixed row.
    long GetFixedRow();     // [id(12), prop r/w]
    void SetFixedRow(long); // [id(12), prop r/w]
    // Sets or returns the number of fixed rows.
    long GetFixedRows();     // [id(13), prop r/w]
    void SetFixedRows(long); // [id(13), prop r/w]
    // Sets or returns the grid lines display status.
    bool GetShowGridLines();     // [id(14), prop r/w]
    void SetShowGridLines(bool); // [id(14), prop r/w]
    // Sets or returns the row heading display status.
    bool GetShowRowHeading();     // [id(15), prop r/w]
    void SetShowRowHeading(bool); // [id(15), prop r/w]
    // Sets or returns whether selections are displayed.
    short GetShowSelections();     // [id(16), prop r/w]
    void SetShowSelections(short); // [id(16), prop r/w]
    // Sets or returns the leftmost column displayed in the view.
    long GetLeftCol();     // [id(17), prop r/w]
    void SetLeftCol(long); // [id(17), prop r/w]
    // Sets or returns the last displayable column.
    long GetMaxCol();     // [id(18), prop r/w]
    void SetMaxCol(long); // [id(18), prop r/w]
    // Sets or returns the last displayable row.
    long GetMaxRow();     // [id(19), prop r/w]
    void SetMaxRow(long); // [id(19), prop r/w]
    // Sets or returns the top row displayed in the view.
    long GetTopRow();     // [id(20), prop r/w]
    void SetTopRow(long); // [id(20), prop r/w]
    // Sets or returns you can resize rows and columns by dragging.
    bool GetAllowResize();     // [id(21), prop r/w]
    void SetAllowResize(bool); // [id(21), prop r/w]
    // Sets or returns whether users can make selections.
    bool GetAllowSelections();     // [id(22), prop r/w]
    void SetAllowSelections(bool); // [id(22), prop r/w]
    // Sets or returns whether the user is allowed to enter formulas.
    bool GetAllowFormulas();     // [id(23), prop r/w]
    void SetAllowFormulas(bool); // [id(23), prop r/w]
    // Sets or returns whether in cell editing is enabled.
    bool GetAllowInCellEditing();     // [id(24), prop r/w]
    void SetAllowInCellEditing(bool); // [id(24), prop r/w]
    // Sets or returns the vertical scroll bar display status.
    short GetShowVScrollBar();     // [id(25), prop r/w]
    void SetShowVScrollBar(short); // [id(25), prop r/w]
    // Sets or returns whether you can fill a worksheet range by dragging.
    bool GetAllowFillRange();     // [id(26), prop r/w]
    void SetAllowFillRange(bool); // [id(26), prop r/w]
    // Sets or returns whether you can move ranges by dragging them.
    bool GetAllowMoveRange();     // [id(27), prop r/w]
    void SetAllowMoveRange(bool); // [id(27), prop r/w]
    // Determines the starting column of a selected range.
    long GetSelStartCol();     // [id(28), prop r/w]
    void SetSelStartCol(long); // [id(28), prop r/w]
    // Determines the starting row of a selected range.
    long GetSelStartRow();     // [id(29), prop r/w]
    void SetSelStartRow(long); // [id(29), prop r/w]
    // Determines the starting column of a selected range.
    long GetSelEndCol();     // [id(30), prop r/w]
    void SetSelEndCol(long); // [id(30), prop r/w]
    // Determines the ending row of a selected range.
    long GetSelEndRow();     // [id(31), prop r/w]
    void SetSelEndRow(long); // [id(31), prop r/w]
    // Sets to returns the color outside the worksheet.
    OLE_COLOR GetExtraColor();     // [id(32), prop r/w]
    void SetExtraColor(OLE_COLOR); // [id(32), prop r/w]
    // Attaches a workbook file to a view control or returns the name of the file currently attached to the control.
    TAutoString GetFileName();     // [id(33), prop r/w]
    void SetFileName(TAutoString); // [id(33), prop r/w]
    // Sets or returns whether automatic recalculation is turned on.
    bool GetAutoRecalc();     // [id(34), prop r/w]
    void SetAutoRecalc(bool); // [id(34), prop r/w]
    // Sets or returns whether gridlines are printed.
    bool GetPrintGridLines();     // [id(35), prop r/w]
    void SetPrintGridLines(bool); // [id(35), prop r/w]
    // Sets or returns whether row headings are printed.
    bool GetPrintRowHeading();     // [id(36), prop r/w]
    void SetPrintRowHeading(bool); // [id(36), prop r/w]
    // Sets or returns whether the worksheet is centered horizontally.
    bool GetPrintHCenter();     // [id(37), prop r/w]
    void SetPrintHCenter(bool); // [id(37), prop r/w]
    // Sets or returns whether the worksheet is centered vertically.
    bool GetPrintVCenter();     // [id(38), prop r/w]
    void SetPrintVCenter(bool); // [id(38), prop r/w]
    // Sets or returns whether worksheet pages are printed left to right.
    bool GetPrintLeftToRight();     // [id(39), prop r/w]
    void SetPrintLeftToRight(bool); // [id(39), prop r/w]
    // Sets or returns the page header.
    TAutoString GetPrintHeader();     // [id(40), prop r/w]
    void SetPrintHeader(TAutoString); // [id(40), prop r/w]
    // Sets or returns the page footer.
    TAutoString GetPrintFooter();     // [id(41), prop r/w]
    void SetPrintFooter(TAutoString); // [id(41), prop r/w]
    // Sets or returns the left page margin used during printing.
    double GetPrintLeftMargin();     // [id(42), prop r/w]
    void SetPrintLeftMargin(double); // [id(42), prop r/w]
    // Sets or returns the top page margin used during printing.
    double GetPrintTopMargin();     // [id(43), prop r/w]
    void SetPrintTopMargin(double); // [id(43), prop r/w]
    // Sets or returns the right page margin used during printing.
    double GetPrintRightMargin();     // [id(44), prop r/w]
    void SetPrintRightMargin(double); // [id(44), prop r/w]
    // Sets or returns the bottom page margin used during printing.
    double GetPrintBottomMargin();     // [id(45), prop r/w]
    void SetPrintBottomMargin(double); // [id(45), prop r/w]
    // Sets or returns the current print area.
    TAutoString GetPrintArea();     // [id(46), prop r/w]
    void SetPrintArea(TAutoString); // [id(46), prop r/w]
    // Sets or returns the print titles.
    TAutoString GetPrintTitles();     // [id(47), prop r/w]
    void SetPrintTitles(TAutoString); // [id(47), prop r/w]
    // Sets or returns whether color is printed.
    bool GetPrintNoColor();     // [id(48), prop r/w]
    void SetPrintNoColor(bool); // [id(48), prop r/w]
    // Selects the specified range or defined name, or returns the start and end row and column of the specified selection.
    TAutoString GetSelection();     // [id(49), prop r/w]
    void SetSelection(TAutoString); // [id(49), prop r/w]
    // Sets or returns the name assigned to the workbook associated with the current view control.
    TAutoString GetTableName();     // [id(50), prop r/w]
    void SetTableName(TAutoString); // [id(50), prop r/w]
    // Determines if the CancelEdit event can be fired.
    bool GetDoCancelEdit();     // [id(51), prop r/w]
    void SetDoCancelEdit(bool); // [id(51), prop r/w]
    // Determines if the SelChange event can be fired.
    bool GetDoSelChange();     // [id(52), prop r/w]
    void SetDoSelChange(bool); // [id(52), prop r/w]
    // Determines if the StartEdit event can be fired.
    bool GetDoStartEdit();     // [id(53), prop r/w]
    void SetDoStartEdit(bool); // [id(53), prop r/w]
    // Determines if the EndEdit event can be fired.
    bool GetDoEndEdit();     // [id(54), prop r/w]
    void SetDoEndEdit(bool); // [id(54), prop r/w]
    // Determines if the StartRecalc event can be fired.
    bool GetDoStartRecalc();     // [id(55), prop r/w]
    void SetDoStartRecalc(bool); // [id(55), prop r/w]
    // Determines if the EndRecalc event can be fired.
    bool GetDoEndRecalc();     // [id(56), prop r/w]
    void SetDoEndRecalc(bool); // [id(56), prop r/w]
    // Determines if the Click event can be fired.
    bool GetDoClick();     // [id(57), prop r/w]
    void SetDoClick(bool); // [id(57), prop r/w]
    // Determines if the DblClick event can be fired.
    bool GetDoDblClick();     // [id(58), prop r/w]
    void SetDoDblClick(bool); // [id(58), prop r/w]
    // Sets or returns the column heading display status.
    bool GetShowColHeading();     // [id(59), prop r/w]
    void SetShowColHeading(bool); // [id(59), prop r/w]
    // Sets or returns whether column headings are printed.
    bool GetPrintColHeading();     // [id(60), prop r/w]
    void SetPrintColHeading(bool); // [id(60), prop r/w]
    // Sets or returns the value of the current cell in edit mode format.
    TAutoString GetEntry();     // [id(61), prop r/w]
    void SetEntry(TAutoString); // [id(61), prop r/w]
    // Sets or returns the repaint status of the worksheet.
    bool GetRepaint();     // [id(62), prop r/w]
    void SetRepaint(bool); // [id(62), prop r/w]
    // Sets or returns whether arrow keys can be used to navigate the worksheet.
    bool GetAllowArrows();     // [id(63), prop r/w]
    void SetAllowArrows(bool); // [id(63), prop r/w]
    // Sets or returns whether tab key repositions the active cell in a selected range.
    bool GetAllowTabs();     // [id(64), prop r/w]
    void SetAllowTabs(bool); // [id(64), prop r/w]
    // Sets or returns the value of the current cell as it appears in the worksheet.
    TAutoString GetFormattedText();     // [id(65), prop r/w]
    void SetFormattedText(TAutoString); // [id(65), prop r/w]
    // Sets or returns whether an entire row is selected when you select a cell.
    bool GetRowMode();     // [id(66), prop r/w]
    void SetRowMode(bool); // [id(66), prop r/w]
    // Sets or returns whether the delete key deletes records and clears selections.
    bool GetAllowDelete();     // [id(67), prop r/w]
    void SetAllowDelete(bool); // [id(67), prop r/w]
    // Sets or returns the state of the enable protection flag.
    bool GetEnableProtection();     // [id(68), prop r/w]
    void SetEnableProtection(bool); // [id(68), prop r/w]
    // Sets or returns the first displayable column.
    long GetMinCol();     // [id(69), prop r/w]
    void SetMinCol(long); // [id(69), prop r/w]
    // Sets or returns the first displayable row.
    long GetMinRow();     // [id(70), prop r/w]
    void SetMinRow(long); // [id(70), prop r/w]
    // Determines if the TopLeftChanged event can be fired.
    bool GetDoTopLeftChanged();     // [id(71), prop r/w]
    void SetDoTopLeftChanged(bool); // [id(71), prop r/w]
    // Sets or returns whether users can edit headers.
    bool GetAllowEditHeaders();     // [id(72), prop r/w]
    void SetAllowEditHeaders(bool); // [id(72), prop r/w]
    // Determines if the ObjClick event can be fired.
    bool GetDoObjClick();     // [id(73), prop r/w]
    void SetDoObjClick(bool); // [id(73), prop r/w]
    // Determines if the ObjDblClick event can be fired.
    bool GetDoObjDblClick();     // [id(74), prop r/w]
    void SetDoObjDblClick(bool); // [id(74), prop r/w]
    // Sets or returns whether objects can be selected.
    bool GetAllowObjSelections();     // [id(75), prop r/w]
    void SetAllowObjSelections(bool); // [id(75), prop r/w]
    // Determines if the RClick event can be fired.
    bool GetDoRClick();     // [id(76), prop r/w]
    void SetDoRClick(bool); // [id(76), prop r/w]
    // Determines if the RDblClick event can be fired.
    bool GetDoRDblClick();     // [id(77), prop r/w]
    void SetDoRDblClick(bool); // [id(77), prop r/w]
    // Imports and exports tab-delimited text strings to and from worksheets.
    TAutoString GetClip();     // [id(78), prop r/w]
    void SetClip(TAutoString); // [id(78), prop r/w]
    // Imports and exports tab-delimited text strings to and from worksheets, ignoring formatting.
    TAutoString GetClipValues();     // [id(79), prop r/w]
    void SetClipValues(TAutoString); // [id(79), prop r/w]
    // Sets or returns the print orientation.
    bool GetPrintLandscape();     // [id(80), prop r/w]
    void SetPrintLandscape(bool); // [id(80), prop r/w]
    // Determines if the Formula One object is enabled.
    bool GetEnabled();     // [id(-514), prop r/w, bindable, requestedit]
    void SetEnabled(bool); // [id(-514), prop r/w, bindable, requestedit]
    // Sets or returns the border style for the Formula One window.
    short GetBorderStyle();     // [id(-504), prop r/w, bindable, requestedit]
    void SetBorderStyle(short); // [id(-504), prop r/w, bindable, requestedit]
    // Sets or returns application name that appears in the title bar of error dialog boxes.
    TAutoString GetAppName();     // [id(81), prop r/w]
    void SetAppName(TAutoString); // [id(81), prop r/w]
    // Sets or returns the height of column headers.
    short GetHdrHeight();     // [id(82), prop r/w]
    void SetHdrHeight(short); // [id(82), prop r/w]
    // Sets or returns the width of row headers.
    short GetHdrWidth();     // [id(83), prop r/w]
    void SetHdrWidth(short); // [id(83), prop r/w]
    // Sets or returns the number format for the selected cells.
    TAutoString GetNumberFormat();     // [id(84), prop r/w]
    void SetNumberFormat(TAutoString); // [id(84), prop r/w]
    // Sets or returns the text for the top left header.
    TAutoString GetTopLeftText();     // [id(85), prop r/w]
    void SetTopLeftText(TAutoString); // [id(85), prop r/w]
    // Sets or returns whether the enter key moves to the next cell.
    bool GetEnterMovesDown();     // [id(86), prop r/w]
    void SetEnterMovesDown(bool); // [id(86), prop r/w]
    // Sets or returns the column number of the last occupied column.
    long GetLastCol();     // [id(87), prop r/w]
    void SetLastCol(long); // [id(87), prop r/w]
    // Returns the row number of the last occupied row.
    long GetLastRow();     // [id(88), prop r/w]
    void SetLastRow(long); // [id(88), prop r/w]
    // Sets or returns the logical (True or False) value of the active cell.
    bool GetLogical();     // [id(89), prop r/w]
    void SetLogical(bool); // [id(89), prop r/w]
    // Sets or returns the current mode for mouse actions in a view.
    short GetMode();     // [id(90), prop r/w]
    void SetMode(short); // [id(90), prop r/w]
    // Sets or returns the polygon editing mode.
    short GetPolyEditMode();     // [id(91), prop r/w]
    void SetPolyEditMode(short); // [id(91), prop r/w]
    // Sets or returns the current display scale setting.
    short GetViewScale();     // [id(92), prop r/w]
    void SetViewScale(short); // [id(92), prop r/w]
    // Returns the number of selected ranges in the active worksheet.
    short GetSelectionCount();     // [id(93), prop r/w]
    void SetSelectionCount(short); // [id(93), prop r/w]
    // Sets or returns the title of the workbook.
    TAutoString GetTitle();     // [id(94), prop r/w]
    void SetTitle(TAutoString); // [id(94), prop r/w]
    // Returns the cell type of the active cell.
    short GetType();     // [id(95), prop r/w]
    void SetType(short); // [id(95), prop r/w]
    // Sets or returns the formulas display status.
    bool GetShowFormulas();     // [id(96), prop r/w]
    void SetShowFormulas(bool); // [id(96), prop r/w]
    // Sets or returns the zero values display status.
    bool GetShowZeroValues();     // [id(97), prop r/w]
    void SetShowZeroValues(bool); // [id(97), prop r/w]
    // Sets or return the type of mouse pointer displayed.
    short GetMousePointer();     // [id(2), prop r/w]
    void SetMousePointer(short); // [id(2), prop r/w]
    // Sets a custom mouse icon.
    IPictureDisp far* GetMouseIcon();     // [id(98), prop r/w]
    void SetMouseIcon(IPictureDisp far*); // [id(98), prop r/w]
    // Determines whether an event is triggered when the value of a listbox or checkbox changes.
    bool GetDoObjValueChanged();     // [id(99), prop r/w]
    void SetDoObjValueChanged(bool); // [id(99), prop r/w]
    // Sets or returns how scroll bars work.
    bool GetScrollToLastRC();     // [id(100), prop r/w]
    void SetScrollToLastRC(bool); // [id(100), prop r/w]
    // Sets or returns whether modifications have been made to a view.
    bool GetModified();     // [id(101), prop r/w]
    void SetModified(bool); // [id(101), prop r/w]
    // Determines whether an event is triggered when an object gets focus.
    bool GetDoObjGotFocus();     // [id(102), prop r/w]
    void SetDoObjGotFocus(bool); // [id(102), prop r/w]
    // Determines whether an event is triggered when an object loses focus.
    bool GetDoObjLostFocus();     // [id(103), prop r/w]
    void SetDoObjLostFocus(bool); // [id(103), prop r/w]
    // Reads and writes the Windows API DEVMODE printer structure.
    OLE_HANDLE GetPrintDevMode();     // [id(104), prop r/w]
    void SetPrintDevMode(OLE_HANDLE); // [id(104), prop r/w]
    // Sets or returns the number of worksheets in the current workbook.
    long GetNumSheets();     // [id(105), prop r/w]
    void SetNumSheets(long); // [id(105), prop r/w]
    // Sets or returns the active worksheet.
    long GetSheet();     // [id(106), prop r/w]
    void SetSheet(long); // [id(106), prop r/w]
    // Sets or returns the unit used to store and displayed column widths.
    short GetColWidthUnits();     // [id(107), prop r/w]
    void SetColWidthUnits(short); // [id(107), prop r/w]
    // Sets or returns whether frames are displayed around cells to identify the cell types.
    bool GetShowTypeMarkers();     // [id(108), prop r/w]
    void SetShowTypeMarkers(bool); // [id(108), prop r/w]
    // Sets or returns whether tabs are displayed at the top, bottom or not at all.
    short GetShowTabs();     // [id(109), prop r/w]
    void SetShowTabs(short); // [id(109), prop r/w]
    // Sets or returns the editbar display status.
    bool GetShowEditBar();     // [id(110), prop r/w]
    void SetShowEditBar(bool); // [id(110), prop r/w]
    // Sets or returns the editbar cell reference display status.
    bool GetShowEditBarCellRef();     // [id(111), prop r/w]
    void SetShowEditBarCellRef(bool); // [id(111), prop r/w]
    // Sets or returns whether the Workbook Designer can be launched at run time.
    bool GetAllowDesigner();     // [id(1), prop r/w]
    void SetAllowDesigner(bool); // [id(1), prop r/w]
    // Returns a handle to a window or control.
    OLE_HANDLE GethWnd();     // [id(-515), prop r/w]
    void SethWnd(OLE_HANDLE); // [id(-515), prop r/w]
    // Sets or returns whether auto fill is enabled.
    bool GetAllowAutoFill();     // [id(112), prop r/w]
    void SetAllowAutoFill(bool); // [id(112), prop r/w]
    // Sets or returns the text for a column header.
    TAutoString GetColText(long nCol); // [id(272), propget]
    // Sets or returns the text for a column header.
    void SetColText(long, TAutoString nCol); // [id(272), propset]
    // Sets or returns the range definition for a user defined name.
    TAutoString GetDefinedName(TAutoString pName); // [id(273), propget]
    // Sets or returns the range definition for a user defined name.
    void SetDefinedName(TAutoString, TAutoString pName); // [id(273), propset]
    // Sets or returns the value of the specified cell in edit mode format.
    TAutoString GetEntryRC(long nRow, long nCol); // [id(274), propget]
    // Sets or returns the value of the specified cell in edit mode format.
    void SetEntryRC(long, long nRow, TAutoString nCol); // [id(274), propset]
    // Sets or returns the value of the specified cell as it appears in the worksheet.
    TAutoString GetFormattedTextRC(long nRow, long nCol); // [id(275), propget]
    // Sets or returns the value of the specified cell as it appears in the worksheet.
    void SetFormattedTextRC(long, long nRow, TAutoString nCol); // [id(275), propset]
    // Sets or returns the text version of the formula of the specified cell.
    TAutoString GetFormulaRC(long nRow, long nCol); // [id(276), propget]
    // Sets or returns the text version of the formula of the specified cell.
    void SetFormulaRC(long, long nRow, TAutoString nCol); // [id(276), propset]
    // Returns the number of the last occupied column for the specified row.
    long GetLastColForRow(long nRow); // [id(277), propget]
    // Returns the number of the last occupied column for the specified row.
    void SetLastColForRow(long, long nRow); // [id(277), propset]
    // Sets or returns the logical (True or False) value of the specified cell.
    bool GetLogicalRC(long nRow, long nCol); // [id(278), propget]
    // Sets or returns the logical (True or False) value of the specified cell.
    void SetLogicalRC(long, long nRow, bool nCol); // [id(278), propset]
    // Sets or returns the numeric value of the specified cell.
    double GetNumberRC(long nRow, long nCol); // [id(279), propget]
    // Sets or returns the numeric value of the specified cell.
    void SetNumberRC(long, long nRow, double nCol); // [id(279), propset]
    // Sets or returns the text for a row header.
    TAutoString GetRowText(long nRow); // [id(280), propget]
    // Sets or returns the text for a row header.
    void SetRowText(long, TAutoString nRow); // [id(280), propset]
    // Sets or returns the text value of the specified cell.
    TAutoString GetTextRC(long nRow, long nCol); // [id(281), propget]
    // Sets or returns the text value of the specified cell.
    void SetTextRC(long, long nRow, TAutoString nCol); // [id(281), propset]
    // Sets or returns the cell type of the specified cell.
    short GetTypeRC(long nRow, long nCol); // [id(282), propget]
    // Sets or returns the cell type of the specified cell.
    void SetTypeRC(long, long nRow, short nCol); // [id(282), propset]
    // Pastes values from the internal clipboard to the selected range, ignoring formatting.
    void EditPasteValues(); // [id(113), method]
    // Returns the data alignment for a selection.
    void GetAlignment(short far* pHorizontal, bool far* pWordWrap, short far* pVertical, short far* pOrientation); // [id(114), method]
    void GetBorder(short far* pLeft, short far* pRight, short far* pTop, short far* pBottom, short far* pShade, OLE_COLOR far* pcrLeft, OLE_COLOR far* pcrRight, OLE_COLOR far* pcrTop, OLE_COLOR far* pcrBottom); // [id(115), method]
    void GetFont(TAutoString far* pName, short far* pSize, bool far* pBold, bool far* pItalic, bool far* pUnderline, bool far* pStrikeout, OLE_COLOR far* pcrColor, bool far* pOutline, bool far* pShadow); // [id(116), method]
    // Returns the line style, weight, and color of the selected line object or border of  the selected object.
    void GetLineStyle(short far* pStyle, OLE_COLOR far* pcrColor, short far* pWeight); // [id(117), method]
    // Returns the fill pattern and colors for the selected cells.
    void GetPattern(short far* pPattern, OLE_COLOR far* pcrFG, OLE_COLOR far* pcrBG); // [id(118), method]
    // Returns the protection of the currently selected cells.
    void GetProtection(bool far* pLocked, bool far* pHidden); // [id(119), method]
    // Obtains a range of data and creates a tab-delimited text string.
    void GetTabbedText(long nR1, long nC1, long nR2, long nC2, bool bValuesOnly, OLE_HANDLE far* phText); // [id(120), method]
    // Sets a tab-delimited text string in a worksheet.
    void SetTabbedText(long nStartRow, long nStartCol, long far* pRows, long far* pCols, bool bValuesOnly, TAutoString pText); // [id(121), method]
    // Adds a vertical page break adjacent to the current cell.
    void AddColPageBreak(long nCol); // [id(122), method]
    // Adds vertical and horizontal page breaks adjacent to the current cell.
    void AddPageBreak(); // [id(123), method]
    // Adds a horizontal page break adjacent to the current cell.
    void AddRowPageBreak(long nRow); // [id(124), method]
    // Adds a new selection to the current selection list.
    void AddSelection(long nR1, long nC1, long nR2, long nC2); // [id(125), method]
    // Attaches a workbook with the given title and to a view.
    void Attach(TAutoString pTitle); // [id(126), method]
    // Attaches a workbook from one view to another.
    void AttachToSS(long hSrcSS); // [id(127), method]
    // Displays the Calculations dialog box.
    void CalculationDlg(); // [id(128), method]
    // Aborts edit mode and leaves current cell unchanged.
    void CancelEdit(); // [id(129), method]
    // Recalculates the worksheet if needed.
    void CheckRecalc(); // [id(130), method]
    // Clears the clipboard.
    void ClearClipboard(); // [id(131), method]
    // Clears the specified range.
    void ClearRange(long nR1, long nC1, long nR2, long nC2, short ClearType); // [id(132), method]
    // Displays Color Palette dialog box.
    void ColorPaletteDlg(); // [id(133), method]
    // Displays the Column Width dialog box.
    void ColWidthDlg(); // [id(134), method]
    // Copies the contents of one workbook to another.
    void CopyAll(long hSrcSS); // [id(135), method]
    void CopyRange(long nDstR1, long nDstC1, long nDstR2, long nDstC2, long hSrcSS, long nSrcR1, long nSrcC1, long nSrcR2, long nSrcC2); // [id(136), method]
    // This dialog box allows you to add and delete user defined names.
    void DefinedNameDlg(); // [id(137), method]
    // Deletes a user defined name.
    void DeleteDefinedName(TAutoString pName); // [id(138), method]
    // Deletes cells, rows, or columns from the specified range.
    void DeleteRange(long nR1, long nC1, long nR2, long nC2, short ShiftType); // [id(139), method]
    void Draw(OLE_HANDLE hDC, long x, long y, long cx, long cy, long nRow, long nCol, long far* pRows, long far* pCols, long nFixedRow, long nFixedCol, long nFixedRows, long nFixedCols); // [id(140), method]
    // Clears all cells in the selected ranges and all selected objects.
    void EditClear(short ClearType); // [id(141), method]
    // Copies the selected range or objects to the internal clipboard.
    void EditCopy(); // [id(142), method]
    // Copies cells in the top row of a selection down.
    void EditCopyDown(); // [id(143), method]
    // Copies cells in the left column of a selection to columns to the right.
    void EditCopyRight(); // [id(144), method]
    // Cuts the selected range or object to the internal clipboard.
    void EditCut(); // [id(145), method]
    // Deletes cells, rows, or columns from the selected range.
    void EditDelete(short ShiftType); // [id(146), method]
    // Inserts cells, rows, or columns in the selected range.
    void EditInsert(short ShiftType); // [id(147), method]
    // Pastes the internal clipboard to the selected range. Also pastes objects.
    void EditPaste(); // [id(148), method]
    // Exits edit mode and commits changes to current cell.
    void EndEdit(); // [id(149), method]
    // This dialog box allows you to define header and footer text, page margins, page print order, page centering, worksheet-related print options.
    void FilePageSetupDlg(); // [id(150), method]
    // Prints a worksheet.
    void FilePrint(bool bShowPrintDlg); // [id(151), method]
    // This dialog box allows you to select the printer to which the worksheet is sent, the page orientation, and paper size.
    void FilePrintSetupDlg(); // [id(152), method]
    // Displays the Alignment dialog box.
    void FormatAlignmentDlg(); // [id(153), method]
    // This dialog box allows you to specify the placement of borders in the selected range. In addition, you can specify the border line style and color.
    void FormatBorderDlg(); // [id(154), method]
    // Formats selected ranges with currency format and no decimal places.
    void FormatCurrency0(); // [id(155), method]
    // Formats selected ranges with currency format and two decimal places.
    void FormatCurrency2(); // [id(156), method]
    // This dialog box allows you to set the default font for the active worksheet.
    void FormatDefaultFontDlg(); // [id(157), method]
    // Formats selected ranges with fixed format and no decimal places.
    void FormatFixed(); // [id(158), method]
    // Formats selected ranges with fixed format and two decimal places.
    void FormatFixed2(); // [id(159), method]
    // This dialog box allows you to specify the font, point size, font style, and color of data in the selected range.
    void FormatFontDlg(); // [id(160), method]
    // Formats the selected ranges with the fraction format.
    void FormatFraction(); // [id(161), method]
    // Formats the selected ranges with the general format.
    void FormatGeneral(); // [id(162), method]
    // Formats the selected ranges in 12-hour time format.
    void FormatHmmampm(); // [id(163), method]
    // Formats the selected ranges with the date format.
    void FormatMdyy(); // [id(164), method]
    // This dialog box allows you to define custom number formats for data in the selected range.
    void FormatNumberDlg(); // [id(165), method]
    // This dialog box allows you to specify the fill pattern and foreground and background colors for the selected range.
    void FormatPatternDlg(); // [id(166), method]
    // Formats the selected ranges in percent format.
    void FormatPercent(); // [id(167), method]
    // Formats the selected ranges in scientific format.
    void FormatScientific(); // [id(168), method]
    // Returns the row and column of the active cell.
    void GetActiveCell(long far* pRow, long far* pCol); // [id(169), method]
    // Sets or returns the width of a single column.
    short GetColWidth(long nCol); // [id(283), propget]
    // Sets or returns the width of a single column.
    void SetColWidth(long, short nCol); // [id(283), propset]
    // Sets or returns the height of the specified row.
    short GetRowHeight(long nRow); // [id(284), propget]
    // Sets or returns the height of the specified row.
    void SetRowHeight(long, short nRow); // [id(284), propset]
    // Returns the default font and font size for the specified worksheet.
    void GetDefaultFont(TAutoString far* pBuf, short far* pSize); // [id(170), method]
    // Returns the whether column, row, or intersection headers are selected.
    void GetHdrSelection(bool far* pTopLeftHdr, bool far* pRowHdr, bool far* pColHdr); // [id(171), method]
    // Returns the iteration information.
    void GetIteration(bool far* pIteration, short far* pMaxIterations, double far* pMaxChange); // [id(172), method]
    // Returns the current print scale settings.
    void GetPrintScale(short far* pScale, bool far* pFitToPage, long far* pVPages, long far* pHPages); // [id(173), method]
    void GetSelection(short nSelection, long far* pR1, long far* pC1, long far* pR2, long far* pC2); // [id(174), method]
    // This dialog box allows you to select the worksheet page to display.
    void GotoDlg(); // [id(175), method]
    // Releases unused memory that was allocated for Formula One worksheets.
    void HeapMin(); // [id(176), method]
    // Initializes a view.
    void InitTable(); // [id(177), method]
    // Inserts cells, rows, or columns in the specified range.
    void InsertRange(long nR1, long nC1, long nR2, long nC2, short ShiftType); // [id(178), method]
    // Displays the Line Style dialog box.
    void LineStyleDlg(); // [id(179), method]
    // Moves a range.
    void MoveRange(long nR1, long nC1, long nR2, long nC2, long nRowOffset, long nColOffset); // [id(180), method]
    // Adds an item to the list of items for the specified list box.
    void ObjAddItem(long ID, TAutoString pItem); // [id(181), method]
    // Selects the specified object; all previously selected objects remain selected.
    void ObjAddSelection(long ID); // [id(182), method]
    // Places the selected objects in front of the unselected objects in a worksheet.
    void ObjBringToFront(); // [id(183), method]
    // Deletes an item from the list of items for the specified list box.
    void ObjDeleteItem(long ID, short nItem); // [id(184), method]
    // Returns the input value cell for the specified check box or list box object.
    void ObjGetCell(long ID, short far* pControlCellType, long far* pRow, long far* pCol); // [id(185), method]
    // Returns the position of the anchor points for the specified object.
    void ObjGetPos(long ID, float far* pX1, float far* pY1, float far* pX2, float far* pY2); // [id(186), method]
    // Returns the identification number of a selected object.
    void ObjGetSelection(short nSelection, long far* pID); // [id(187), method]
    // Inserts an item at a specific location in a list of items for a list box.
    void ObjInsertItem(long ID, short nItem, TAutoString pItem); // [id(188), method]
    // This dialog box allows you to set a name for the selected object.
    void ObjNameDlg(); // [id(189), method]
    // Creates a new object.
    void ObjNew(short ObjType, float nX1, float nY1, float nX2, float nY2, long far* pID); // [id(190), method]
    // ?
    void ObjNewPicture(float nX1, float nY1, float nX2, float nY2, long far* pID, OLE_HANDLE hMF, long nMapMode, long nWndExtentX, long nWndExtentY); // [id(191), method]
    // This dialog box allows you to set the options for the selected object.
    void ObjOptionsDlg(); // [id(192), method]
    // ?
    void ObjPosToTwips(float nX1, float nY1, float nX2, float nY2, long far* pX, long far* pY, long far* pCX, long far* pCY, short far* pShown); // [id(193), method]
    // Places the selected objects behind the unselected objects in a worksheet.
    void ObjSendToBack(); // [id(194), method]
    // Sets the input value cell for the specified check box or list box object.
    void ObjSetCell(long ID, short ControlCellType, long nRow, long nCol); // [id(195), method]
    // Places a metafile in an existing picture object.
    void ObjSetPicture(long ID, OLE_HANDLE hMF, short nMapMode, long nWndExtentX, long nWndExtentY); // [id(196), method]
    // Sets the placement of an object's anchor points.
    void ObjSetPos(long ID, float nX1, float nY1, float nX2, float nY2); // [id(197), method]
    // Selects the specified object.
    void ObjSetSelection(long ID); // [id(198), method]
    // Displays the Open File dialog box.
    void OpenFileDlg(TAutoString pTitle, OLE_HANDLE hWndParent, TAutoString far* pBuf); // [id(199), method]
    // Displays the Protection dialog box.
    void ProtectionDlg(); // [id(200), method]
    // ?
    void RangeToTwips(long nRow1, long nCol1, long nRow2, long nCol2, long far* pX, long far* pY, long far* pCX, long far* pCY, short far* pShown); // [id(201), method]
    // Reads a worksheet or workbook from disk.
    void Read(TAutoString pPathName, short far* pFileType); // [id(202), method]
    // Reads a worksheet that has been stored in memory in a blob variable.
    void ReadFromBlob(OLE_HANDLE hBlob, short nReservedBytes); // [id(203), method]
    // Recalculates the workbook.
    void Recalc(); // [id(204), method]
    // Removes a vertical page break adjacent to the current cell.
    void RemoveColPageBreak(long nCol); // [id(205), method]
    // Removes vertical and horizontal page breaks adjacent to the current cell.
    void RemovePageBreak(); // [id(206), method]
    // Removes a horizontal page break adjacent to the current cell.
    void RemoveRowPageBreak(long nRow); // [id(207), method]
    // Displays the RowHeight dialog box.
    void RowHeightDlg(); // [id(208), method]
    // This dialog box allows you to save the current file in Formula One, Excel 4.0, or tabbed text format.
    void SaveFileDlg(TAutoString pTitle, TAutoString far* pBuf, short far* pFileType); // [id(209), method]
    // Saves the window specific information from a view to its worksheet.
    void SaveWindowInfo(); // [id(210), method]
    // Sets the active cell to the specified row and column.
    void SetActiveCell(long nRow, long nCol); // [id(211), method]
    // Specifies data alignment for a selection.
    void SetAlignment(short HAlign, bool bWordWrap, short VAlign, short nOrientation); // [id(212), method]
    void SetBorder(short nOutline, short nLeft, short nRight, short nTop, short nBottom, short nShade, OLE_COLOR crOutline, OLE_COLOR crLeft, OLE_COLOR crRight, OLE_COLOR crTop, OLE_COLOR crBottom); // [id(213), method]
    // Determines the width for the specified columns.
    void SetColWidth(long nC1, long nC2, short nWidth, bool bDefColWidth); // [id(214), method]
    // Specifies that column widths are set automatically.
    void SetColWidthAuto(long nR1, long nC1, long nR2, long nC2, bool bSetDefaults); // [id(215), method]
    // Sets the default font and font size for the specified worksheet.
    void SetDefaultFont(TAutoString pName, short nSize); // [id(216), method]
    // ?
    void SetFont(TAutoString pName, short nSize, bool bBold, bool bItalic, bool bUnderline, bool bStrikeout, OLE_COLOR crColor, bool bOutline, bool bShadow); // [id(217), method]
    // Specifies whether the column, row, and top left header are selected.
    void SetHdrSelection(bool bTopLeftHdr, bool bRowHdr, bool bColHdr); // [id(218), method]
    // Sets the iteration information.
    void SetIteration(bool bIteration, short nMaxIterations, double nMaxChange); // [id(219), method]
    // Sets formatting information for lines.
    void SetLineStyle(short nStyle, OLE_COLOR crColor, short nWeight); // [id(220), method]
    // Specifies the fill pattern and colors for the selected cells.
    void SetPattern(short nPattern, OLE_COLOR crFG, OLE_COLOR crBG); // [id(221), method]
    // Sets the print range to the currently selected ranges.
    void SetPrintAreaFromSelection(); // [id(222), method]
    // Specifies the current print scale settings.
    void SetPrintScale(short nScale, bool bFitToPage, short nVPages, short nHPages); // [id(223), method]
    // Sets the print titles to the currently selected ranges.
    void SetPrintTitlesFromSelection(); // [id(224), method]
    // Specifies the protection of the currently selected cells.
    void SetProtection(bool bLocked, bool bHidden); // [id(225), method]
    // Specifies the height for the specified rows.
    void SetRowHeight(long nR1, long nR2, short nHeight, bool bDefRowHeight); // [id(226), method]
    // Specifies that row heights are set automatically.
    void SetRowHeightAuto(long nR1, long nC1, long nR2, long nC2, bool bSetDefaults); // [id(227), method]
    // Selects the specified range.
    void SetSelection(long nR1, long nC1, long nR2, long nC2); // [id(228), method]
    // Positions the view to show the active cell if it is not currently in the window.
    void ShowActiveCell(); // [id(229), method]
    // Sorts the selected range of date with as many as three sort keys.
    void Sort3(long nR1, long nC1, long nR2, long nC2, bool bSortByRows, long nKey1, long nKey2, long nKey3); // [id(230), method]
    // Displays Sort dialog box.
    void SortDlg(); // [id(231), method]
    // Begins edit mode.
    void StartEdit(bool bClear, bool bInCellEditFocus, bool bArrowsExitEditMode); // [id(232), method]
    // Exchanges the workbooks attached to two views.
    void SwapTables(long hSS2); // [id(233), method]
    // Commits all changes since transaction began.
    void TransactCommit(); // [id(234), method]
    // Undoes all changes since transaction began.
    void TransactRollback(); // [id(235), method]
    // Starts a transaction.
    void TransactStart(); // [id(236), method]
    // Returns the row and column that correspond to a given point.
    void TwipsToRC(long x, long y, long far* pRow, long far* pCol); // [id(237), method]
    // Updates all workbooks.
    void SSUpdate(); // [id(238), method]
    // Returns the version number of the Formula One control.
    short SSVersion(); // [id(239), method]
    // Saves the workbook to a file.
    void Write(TAutoString pPathName, short FileType); // [id(240), method]
    // Writes a worksheet to a blob variable.
    void WriteToBlob(OLE_HANDLE far* phBlob, short nReservedBytes); // [id(241), method]
    // Changes the display status of one or more rows.
    void SetRowHidden(long nRow1, long nRow2, bool bHidden); // [id(242), method]
    // Sets or the display status of a range of columns.
    void SetColHidden(long nCol1, long nCol2, bool bHidden); // [id(243), method]
    // Changes the width of the one or more columns to the specified number of twips.
    void SetColWidthTwips(long nCol1, long nCol2, long nWidth, bool bDefColWidth); // [id(244), method]
    // Changes or returns a defined name.
    TAutoString GetDefinedNameByIndex(long nName); // [id(285), propget]
    // Changes or returns a defined name.
    void SetDefinedNameByIndex(long, TAutoString nName); // [id(285), propset]
    // Sets or returns a worksheet name.
    TAutoString GetSheetName(long nSheet); // [id(286), propget]
    // Sets or returns a worksheet name.
    void SetSheetName(long, TAutoString nSheet); // [id(286), propset]
    // Allows you to replace a color in the Formula One color palette.
    OLE_COLOR GetPaletteEntry(long nEntry); // [id(287), propget]
    // Allows you to replace a color in the Formula One color palette.
    void SetPaletteEntry(long, OLE_COLOR nEntry); // [id(287), propset]
    // Inserts one or more new worksheets, depending on the number and position of the currently selected worksheets.
    void EditInsertSheets(); // [id(245), method]
    // Deletes all selected worksheets.
    void EditDeleteSheets(); // [id(246), method]
    // Inserts one or more worksheets at the specified location.
    void InsertSheets(long nSheet, long nSheets); // [id(247), method]
    // Deletes one or more worksheets from a workbook.
    void DeleteSheets(long nSheet, long nSheets); // [id(248), method]
    // ?
    void Refresh(); // [id(-550), method]
    // Sets or returns the width of a specified column in twips.
    short GetColWidthTwips(long Col); // [id(288), propget]
    // Sets or returns the width of a specified column in twips.
    void SetColWidthTwips(long, short Col); // [id(288), propset]
    // Returns the next column where there is a page break.
    long NextColPageBreak(long Col); // [id(249), method]
    // Returns the next row where there is a page break.
    long NextRowPageBreak(long Row); // [id(250), method]
    // Returns the identification number of the first object in the worksheet.
    long ObjFirstID(); // [id(251), method]
    // Given an object identification number, returns the identification number of the next object in a worksheet.
    long ObjNextID(long ID); // [id(252), method]
    // Returns the number of items contained in a list box.
    short ObjGetItemCount(long ID); // [id(253), method]
    // Returns the object type of the specified object.
    short ObjGetType(long ID); // [id(254), method]
    // Returns the number of selected objects.
    short ObjGetSelectionCount(); // [id(255), method]
    // Creates a string containing a formatted row and column reference.
    TAutoString FormatRCNr(long Row, long Col, bool DoAbsolute); // [id(256), method]
    // Returns the handle to the workbook associated with the current view control.
    long SS(); // [id(257), method]
    // Returns the error text corresponding to the specified error number.
    TAutoString ErrorNumberToText(long SSError); // [id(258), method]
    // Sets or returns the specified item from a list of items in a list box.
    TAutoString GetObjItem(long ID, short Item); // [id(289), propget]
    // Sets or returns the specified item from a list of items in a list box.
    void SetObjItem(long, short ID, TAutoString Item); // [id(289), propset]
    // Sets or returns the list of items contained in a list box.
    TAutoString GetObjItems(long ID); // [id(290), propget]
    // Sets or returns the list of items contained in a list box.
    void SetObjItems(long, TAutoString ID); // [id(290), propset]
    // Sets or returns the object name assigned to the specified object.
    TAutoString GetObjName(long ID); // [id(291), propget]
    // Sets or returns the object name assigned to the specified object.
    void SetObjName(long, TAutoString ID); // [id(291), propset]
    // Sets or returns the text displayed on a check box or button.
    TAutoString GetObjText(long ID); // [id(292), propget]
    // Sets or returns the text displayed on a check box or button.
    void SetObjText(long, TAutoString ID); // [id(292), propset]
    // Sets or returns the current selection value in a specified check box or list box.
    short GetObjValue(long ID); // [id(293), propget]
    // Sets or returns the current selection value in a specified check box or list box.
    void SetObjValue(long, short ID); // [id(293), propset]
    // Sets or returns the display status of the specified object.
    bool GetObjVisible(long ID); // [id(294), propget]
    // Sets or returns the display status of the specified object.
    void SetObjVisible(long, bool ID); // [id(294), propset]
    // Returns the identification number of a named object.
    long ObjNameToID(TAutoString Name); // [id(259), method]
    // Returns the number of defined names.
    long DefinedNameCount(); // [id(260), method]
    // Sets or returns an autofill list.
    TAutoString GetAutoFillItems(short Index); // [id(295), propget]
    // Sets or returns an autofill list.
    void SetAutoFillItems(short, TAutoString Index); // [id(295), propset]
    // Displays the Validation Rule dialog box.
    void ValidationRuleDlg(); // [id(261), method]
    // Sets the validation rule for the currently selected range of cells.
    void SetValidationRule(TAutoString Rule, TAutoString Text); // [id(262), method]
    // Returns the validation rule for the currently selected range of cells.
    void GetValidationRule(TAutoString far* Rule, TAutoString far* Text); // [id(263), method]
    // Returns the number of Autofill lists.
    short AutoFillItemsCount(); // [id(264), method]
    // ?
    void CopyRangeEx(long nDstSheet, long nDstR1, long nDstC1, long nDstR2, long nDstC2, long hSrcSS, long nSrcSheet, long nSrcR1, long nSrcC1, long nSrcR2, long nSrcC2); // [id(265), method]
    // Sorts the selected range.
    void Sort(long nR1, long nC1, long nR2, long nC2, bool bSortByRows, VARIANT far* Keys); // [id(266), method]
    // Sets or returns the display status of an individual column.
    bool GetColHidden(long nCol); // [id(296), propget]
    // Sets or returns the display status of an individual column.
    void SetColHidden(long, bool nCol); // [id(296), propset]
    // Sets or returns the display status of an individual row.
    bool GetRowHidden(long nRow); // [id(297), propget]
    // Sets or returns the display status of an individual row.
    void SetRowHidden(long, bool nRow); // [id(297), propset]
    // Deletes the specified autofill list.
    void DeleteAutoFillItems(short nIndex); // [id(267), method]
    // Connects to an ODBC database.
    void ODBCConnect(TAutoString far* pConnect, bool bShowErrors, short far* pRetCode); // [id(268), method]
    // Disconnect from an ODBC database.
    void ODBCDisconnect(); // [id(269), method]
    void ODBCQuery(TAutoString far* pQuery, long nRow, long nCol, bool bForceShowDlg, bool far* pSetColNames, bool far* pSetColFormats, bool far* pSetColWidths, bool far* pSetMaxRC, short far* pRetCode); // [id(270), method]
    // Sets or returns the selected status of a worksheet.
    bool GetSheetSelected(long nSheet); // [id(298), propget]
    // Sets or returns the selected status of a worksheet.
    void SetSheetSelected(long, bool nSheet); // [id(298), propset]
    // Launches the Workbook Designer
    void LaunchDesigner(); // [id(271), method]
    // Displays the About Formula One dialog box.
    void AboutBox(); // [id(-552), method]
};

#endif	// _PROXY_VCF132_HXX
