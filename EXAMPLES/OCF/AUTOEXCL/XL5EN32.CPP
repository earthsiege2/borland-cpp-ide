#include "XL5EN32.HXX"

// TKIND_DISPATCH: _Global {00020856-0000-0000-C000-000000000046}\9

TAutoVal _Global::GetActiveCell()
{
  AUTONAMES0("ActiveCell")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void _Global::SetActiveCell(TAutoVal& val)
{
  AUTONAMES0("ActiveCell")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal _Global::GetActiveChart()
{
  AUTONAMES0("ActiveChart")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void _Global::SetActiveChart(TAutoVal& val)
{
  AUTONAMES0("ActiveChart")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal _Global::GetActiveDialog()
{
  AUTONAMES0("ActiveDialog")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void _Global::SetActiveDialog(TAutoVal& val)
{
  AUTONAMES0("ActiveDialog")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal _Global::GetActiveMenuBar()
{
  AUTONAMES0("ActiveMenuBar")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void _Global::SetActiveMenuBar(TAutoVal& val)
{
  AUTONAMES0("ActiveMenuBar")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal _Global::GetActivePrinter()
{
  AUTONAMES0("ActivePrinter")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void _Global::SetActivePrinter(TAutoVal& val)
{
  AUTONAMES0("ActivePrinter")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal _Global::GetActiveSheet()
{
  AUTONAMES0("ActiveSheet")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void _Global::SetActiveSheet(TAutoVal& val)
{
  AUTONAMES0("ActiveSheet")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal _Global::GetActiveWindow()
{
  AUTONAMES0("ActiveWindow")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void _Global::SetActiveWindow(TAutoVal& val)
{
  AUTONAMES0("ActiveWindow")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal _Global::GetActiveWorkbook()
{
  AUTONAMES0("ActiveWorkbook")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void _Global::SetActiveWorkbook(TAutoVal& val)
{
  AUTONAMES0("ActiveWorkbook")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal _Global::GetCreator()
{
  AUTONAMES0("Creator")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void _Global::SetCreator(TAutoVal& val)
{
  AUTONAMES0("Creator")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal _Global::GetDDEAppReturnCode()
{
  AUTONAMES0("DDEAppReturnCode")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void _Global::SetDDEAppReturnCode(TAutoVal& val)
{
  AUTONAMES0("DDEAppReturnCode")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal _Global::GetParent()
{
  AUTONAMES0("Parent")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void _Global::SetParent(TAutoVal& val)
{
  AUTONAMES0("Parent")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal _Global::GetSelection()
{
  AUTONAMES0("Selection")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void _Global::SetSelection(TAutoVal& val)
{
  AUTONAMES0("Selection")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal _Global::GetThisWorkbook()
{
  AUTONAMES0("ThisWorkbook")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void _Global::SetThisWorkbook(TAutoVal& val)
{
  AUTONAMES0("ThisWorkbook")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal _Global::AddIns(TAutoVal& Index)
{
  AUTONAMES0("AddIns")
  AUTOARGS1(Index)
  AUTOCALL_METHOD_RET
}

TAutoVal _Global::Application()
{
  AUTONAMES0("Application")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal _Global::Calculate()
{
  AUTONAMES0("Calculate")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal _Global::Cells(TAutoVal& RowIndex, TAutoVal& ColumnIndex)
{
  AUTONAMES0("Cells")
  AUTOARGS2(RowIndex, ColumnIndex)
  AUTOCALL_METHOD_RET
}

TAutoVal _Global::Charts(TAutoVal& Index)
{
  AUTONAMES0("Charts")
  AUTOARGS1(Index)
  AUTOCALL_METHOD_RET
}

TAutoVal _Global::Columns(TAutoVal& Index)
{
  AUTONAMES0("Columns")
  AUTOARGS1(Index)
  AUTOCALL_METHOD_RET
}

TAutoVal _Global::DDEExecute(TAutoVal& Channel, TAutoVal& String)
{
  AUTONAMES0("DDEExecute")
  AUTOARGS2(Channel, String)
  AUTOCALL_METHOD_RET
}

TAutoVal _Global::DDEInitiate(TAutoVal& App, TAutoVal& Topic)
{
  AUTONAMES0("DDEInitiate")
  AUTOARGS2(App, Topic)
  AUTOCALL_METHOD_RET
}

TAutoVal _Global::DDEPoke(TAutoVal& Channel, TAutoVal& Item, TAutoVal& Data)
{
  AUTONAMES0("DDEPoke")
  AUTOARGS3(Channel, Item, Data)
  AUTOCALL_METHOD_RET
}

TAutoVal _Global::DDERequest(TAutoVal& Channel, TAutoVal& Item)
{
  AUTONAMES0("DDERequest")
  AUTOARGS2(Channel, Item)
  AUTOCALL_METHOD_RET
}

TAutoVal _Global::DDETerminate(TAutoVal& Channel)
{
  AUTONAMES0("DDETerminate")
  AUTOARGS1(Channel)
  AUTOCALL_METHOD_RET
}

TAutoVal _Global::DialogSheets(TAutoVal& Index)
{
  AUTONAMES0("DialogSheets")
  AUTOARGS1(Index)
  AUTOCALL_METHOD_RET
}

TAutoVal _Global::_Evaluate(TAutoVal& Name)
{
  AUTONAMES0("_Evaluate")
  AUTOARGS1(Name)
  AUTOCALL_METHOD_RET
}

TAutoVal _Global::Evaluate(TAutoVal& Name)
{
  AUTONAMES0("Evaluate")
  AUTOARGS1(Name)
  AUTOCALL_METHOD_RET
}

TAutoVal _Global::Excel4IntlMacroSheets(TAutoVal& Index)
{
  AUTONAMES0("Excel4IntlMacroSheets")
  AUTOARGS1(Index)
  AUTOCALL_METHOD_RET
}

TAutoVal _Global::Excel4MacroSheets(TAutoVal& Index)
{
  AUTONAMES0("Excel4MacroSheets")
  AUTOARGS1(Index)
  AUTOCALL_METHOD_RET
}

TAutoVal _Global::ExecuteExcel4Macro(TAutoVal& String)
{
  AUTONAMES0("ExecuteExcel4Macro")
  AUTOARGS1(String)
  AUTOCALL_METHOD_RET
}

TAutoVal _Global::Intersect(TAutoVal& Arg1, TAutoVal& Arg2, TAutoVal& Arg3, TAutoVal& Arg4, TAutoVal& Arg5, TAutoVal& Arg6, TAutoVal& Arg7, TAutoVal& Arg8, TAutoVal& Arg9, TAutoVal& Arg10, TAutoVal& Arg11, TAutoVal& Arg12, TAutoVal& Arg13, TAutoVal& Arg14, TAutoVal& Arg15, TAutoVal& Arg16, TAutoVal& Arg17, TAutoVal& Arg18, TAutoVal& Arg19, TAutoVal& Arg20, TAutoVal& Arg21, TAutoVal& Arg22, TAutoVal& Arg23, TAutoVal& Arg24, TAutoVal& Arg25, TAutoVal& Arg26, TAutoVal& Arg27, TAutoVal& Arg28, TAutoVal& Arg29, TAutoVal& Arg30)
{
  AUTONAMES0("Intersect")
  AUTOARGS30(Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Arg8, Arg9, Arg10, Arg11, Arg12, Arg13, Arg14, Arg15, Arg16, Arg17, Arg18, Arg19, Arg20, Arg21, Arg22, Arg23, Arg24, Arg25, Arg26, Arg27, Arg28, Arg29, Arg30)
  AUTOCALL_METHOD_RET
}

TAutoVal _Global::MenuBars(TAutoVal& Index)
{
  AUTONAMES0("MenuBars")
  AUTOARGS1(Index)
  AUTOCALL_METHOD_RET
}

TAutoVal _Global::Modules(TAutoVal& Index)
{
  AUTONAMES0("Modules")
  AUTOARGS1(Index)
  AUTOCALL_METHOD_RET
}

TAutoVal _Global::Names(TAutoVal& Index, TAutoVal& IndexLocal, TAutoVal& RefersTo)
{
  AUTONAMES0("Names")
  AUTOARGS3(Index, IndexLocal, RefersTo)
  AUTOCALL_METHOD_RET
}

TAutoVal _Global::Range(TAutoVal& Cell1, TAutoVal& Cell2)
{
  AUTONAMES0("Range")
  AUTOARGS2(Cell1, Cell2)
  AUTOCALL_METHOD_RET
}

TAutoVal _Global::Rows(TAutoVal& Index)
{
  AUTONAMES0("Rows")
  AUTOARGS1(Index)
  AUTOCALL_METHOD_RET
}

TAutoVal _Global::Run(TAutoVal& Macro, TAutoVal& Arg1, TAutoVal& Arg2, TAutoVal& Arg3, TAutoVal& Arg4, TAutoVal& Arg5, TAutoVal& Arg6, TAutoVal& Arg7, TAutoVal& Arg8, TAutoVal& Arg9, TAutoVal& Arg10, TAutoVal& Arg11, TAutoVal& Arg12, TAutoVal& Arg13, TAutoVal& Arg14, TAutoVal& Arg15, TAutoVal& Arg16, TAutoVal& Arg17, TAutoVal& Arg18, TAutoVal& Arg19, TAutoVal& Arg20, TAutoVal& Arg21, TAutoVal& Arg22, TAutoVal& Arg23, TAutoVal& Arg24, TAutoVal& Arg25, TAutoVal& Arg26, TAutoVal& Arg27, TAutoVal& Arg28, TAutoVal& Arg29, TAutoVal& Arg30)
{
  AUTONAMES0("Run")
  AUTOARGS31(Macro, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Arg8, Arg9, Arg10, Arg11, Arg12, Arg13, Arg14, Arg15, Arg16, Arg17, Arg18, Arg19, Arg20, Arg21, Arg22, Arg23, Arg24, Arg25, Arg26, Arg27, Arg28, Arg29, Arg30)
  AUTOCALL_METHOD_RET
}

TAutoVal _Global::SendKeys(TAutoVal& Keys, TAutoVal& Wait)
{
  AUTONAMES0("SendKeys")
  AUTOARGS2(Keys, Wait)
  AUTOCALL_METHOD_RET
}

TAutoVal _Global::Sheets(TAutoVal& Index)
{
  AUTONAMES0("Sheets")
  AUTOARGS1(Index)
  AUTOCALL_METHOD_RET
}

TAutoVal _Global::ShortcutMenus(TAutoVal& Index)
{
  AUTONAMES0("ShortcutMenus")
  AUTOARGS1(Index)
  AUTOCALL_METHOD_RET
}

TAutoVal _Global::Toolbars(TAutoVal& Index)
{
  AUTONAMES0("Toolbars")
  AUTOARGS1(Index)
  AUTOCALL_METHOD_RET
}

TAutoVal _Global::Union(TAutoVal& Arg1, TAutoVal& Arg2, TAutoVal& Arg3, TAutoVal& Arg4, TAutoVal& Arg5, TAutoVal& Arg6, TAutoVal& Arg7, TAutoVal& Arg8, TAutoVal& Arg9, TAutoVal& Arg10, TAutoVal& Arg11, TAutoVal& Arg12, TAutoVal& Arg13, TAutoVal& Arg14, TAutoVal& Arg15, TAutoVal& Arg16, TAutoVal& Arg17, TAutoVal& Arg18, TAutoVal& Arg19, TAutoVal& Arg20, TAutoVal& Arg21, TAutoVal& Arg22, TAutoVal& Arg23, TAutoVal& Arg24, TAutoVal& Arg25, TAutoVal& Arg26, TAutoVal& Arg27, TAutoVal& Arg28, TAutoVal& Arg29, TAutoVal& Arg30)
{
  AUTONAMES0("Union")
  AUTOARGS30(Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Arg8, Arg9, Arg10, Arg11, Arg12, Arg13, Arg14, Arg15, Arg16, Arg17, Arg18, Arg19, Arg20, Arg21, Arg22, Arg23, Arg24, Arg25, Arg26, Arg27, Arg28, Arg29, Arg30)
  AUTOCALL_METHOD_RET
}

TAutoVal _Global::Windows(TAutoVal& Index)
{
  AUTONAMES0("Windows")
  AUTOARGS1(Index)
  AUTOCALL_METHOD_RET
}

TAutoVal _Global::Workbooks(TAutoVal& Index)
{
  AUTONAMES0("Workbooks")
  AUTOARGS1(Index)
  AUTOCALL_METHOD_RET
}

TAutoVal _Global::Worksheets(TAutoVal& Index)
{
  AUTONAMES0("Worksheets")
  AUTOARGS1(Index)
  AUTOCALL_METHOD_RET
}


// TKIND_DISPATCH: Application {00020841-0000-0000-C000-000000000046}\9

TAutoVal Application::GetActiveCell()
{
  AUTONAMES0("ActiveCell")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Application::SetActiveCell(TAutoVal& val)
{
  AUTONAMES0("ActiveCell")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Application::GetActiveChart()
{
  AUTONAMES0("ActiveChart")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Application::SetActiveChart(TAutoVal& val)
{
  AUTONAMES0("ActiveChart")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Application::GetActiveDialog()
{
  AUTONAMES0("ActiveDialog")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Application::SetActiveDialog(TAutoVal& val)
{
  AUTONAMES0("ActiveDialog")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Application::GetActiveMenuBar()
{
  AUTONAMES0("ActiveMenuBar")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Application::SetActiveMenuBar(TAutoVal& val)
{
  AUTONAMES0("ActiveMenuBar")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Application::GetActivePrinter()
{
  AUTONAMES0("ActivePrinter")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Application::SetActivePrinter(TAutoVal& val)
{
  AUTONAMES0("ActivePrinter")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Application::GetActiveSheet()
{
  AUTONAMES0("ActiveSheet")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Application::SetActiveSheet(TAutoVal& val)
{
  AUTONAMES0("ActiveSheet")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Application::GetActiveWindow()
{
  AUTONAMES0("ActiveWindow")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Application::SetActiveWindow(TAutoVal& val)
{
  AUTONAMES0("ActiveWindow")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Application::GetActiveWorkbook()
{
  AUTONAMES0("ActiveWorkbook")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Application::SetActiveWorkbook(TAutoVal& val)
{
  AUTONAMES0("ActiveWorkbook")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Application::GetAlertBeforeOverwriting()
{
  AUTONAMES0("AlertBeforeOverwriting")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Application::SetAlertBeforeOverwriting(TAutoVal& val)
{
  AUTONAMES0("AlertBeforeOverwriting")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Application::GetAltStartupPath()
{
  AUTONAMES0("AltStartupPath")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Application::SetAltStartupPath(TAutoVal& val)
{
  AUTONAMES0("AltStartupPath")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Application::GetAskToUpdateLinks()
{
  AUTONAMES0("AskToUpdateLinks")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Application::SetAskToUpdateLinks(TAutoVal& val)
{
  AUTONAMES0("AskToUpdateLinks")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Application::GetAutoCorrect()
{
  AUTONAMES0("AutoCorrect")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Application::SetAutoCorrect(TAutoVal& val)
{
  AUTONAMES0("AutoCorrect")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Application::GetBuild()
{
  AUTONAMES0("Build")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Application::SetBuild(TAutoVal& val)
{
  AUTONAMES0("Build")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Application::GetCalculateBeforeSave()
{
  AUTONAMES0("CalculateBeforeSave")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Application::SetCalculateBeforeSave(TAutoVal& val)
{
  AUTONAMES0("CalculateBeforeSave")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Application::GetCalculation()
{
  AUTONAMES0("Calculation")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Application::SetCalculation(TAutoVal& val)
{
  AUTONAMES0("Calculation")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Application::GetCaller()
{
  AUTONAMES0("Caller")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Application::SetCaller(TAutoVal& val)
{
  AUTONAMES0("Caller")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Application::GetCanPlaySounds()
{
  AUTONAMES0("CanPlaySounds")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Application::SetCanPlaySounds(TAutoVal& val)
{
  AUTONAMES0("CanPlaySounds")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Application::GetCanRecordSounds()
{
  AUTONAMES0("CanRecordSounds")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Application::SetCanRecordSounds(TAutoVal& val)
{
  AUTONAMES0("CanRecordSounds")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Application::GetCaption()
{
  AUTONAMES0("Caption")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Application::SetCaption(TAutoVal& val)
{
  AUTONAMES0("Caption")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Application::GetCellDragAndDrop()
{
  AUTONAMES0("CellDragAndDrop")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Application::SetCellDragAndDrop(TAutoVal& val)
{
  AUTONAMES0("CellDragAndDrop")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Application::GetClipboardFormats()
{
  AUTONAMES0("ClipboardFormats")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Application::SetClipboardFormats(TAutoVal& val)
{
  AUTONAMES0("ClipboardFormats")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Application::GetColorButtons()
{
  AUTONAMES0("ColorButtons")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Application::SetColorButtons(TAutoVal& val)
{
  AUTONAMES0("ColorButtons")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Application::GetCommandUnderlines()
{
  AUTONAMES0("CommandUnderlines")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Application::SetCommandUnderlines(TAutoVal& val)
{
  AUTONAMES0("CommandUnderlines")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Application::GetConstrainNumeric()
{
  AUTONAMES0("ConstrainNumeric")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Application::SetConstrainNumeric(TAutoVal& val)
{
  AUTONAMES0("ConstrainNumeric")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Application::GetCopyObjectsWithCells()
{
  AUTONAMES0("CopyObjectsWithCells")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Application::SetCopyObjectsWithCells(TAutoVal& val)
{
  AUTONAMES0("CopyObjectsWithCells")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Application::GetCreator()
{
  AUTONAMES0("Creator")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Application::SetCreator(TAutoVal& val)
{
  AUTONAMES0("Creator")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Application::GetCursor()
{
  AUTONAMES0("Cursor")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Application::SetCursor(TAutoVal& val)
{
  AUTONAMES0("Cursor")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Application::GetCustomListCount()
{
  AUTONAMES0("CustomListCount")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Application::SetCustomListCount(TAutoVal& val)
{
  AUTONAMES0("CustomListCount")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Application::GetCutCopyMode()
{
  AUTONAMES0("CutCopyMode")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Application::SetCutCopyMode(TAutoVal& val)
{
  AUTONAMES0("CutCopyMode")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Application::GetDataEntryMode()
{
  AUTONAMES0("DataEntryMode")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Application::SetDataEntryMode(TAutoVal& val)
{
  AUTONAMES0("DataEntryMode")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Application::GetDDEAppReturnCode()
{
  AUTONAMES0("DDEAppReturnCode")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Application::SetDDEAppReturnCode(TAutoVal& val)
{
  AUTONAMES0("DDEAppReturnCode")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Application::GetDefaultFilePath()
{
  AUTONAMES0("DefaultFilePath")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Application::SetDefaultFilePath(TAutoVal& val)
{
  AUTONAMES0("DefaultFilePath")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Application::GetDisplayAlerts()
{
  AUTONAMES0("DisplayAlerts")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Application::SetDisplayAlerts(TAutoVal& val)
{
  AUTONAMES0("DisplayAlerts")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Application::GetDisplayClipboardWindow()
{
  AUTONAMES0("DisplayClipboardWindow")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Application::SetDisplayClipboardWindow(TAutoVal& val)
{
  AUTONAMES0("DisplayClipboardWindow")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Application::GetDisplayExcel4Menus()
{
  AUTONAMES0("DisplayExcel4Menus")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Application::SetDisplayExcel4Menus(TAutoVal& val)
{
  AUTONAMES0("DisplayExcel4Menus")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Application::GetDisplayFormulaBar()
{
  AUTONAMES0("DisplayFormulaBar")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Application::SetDisplayFormulaBar(TAutoVal& val)
{
  AUTONAMES0("DisplayFormulaBar")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Application::GetDisplayFullScreen()
{
  AUTONAMES0("DisplayFullScreen")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Application::SetDisplayFullScreen(TAutoVal& val)
{
  AUTONAMES0("DisplayFullScreen")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Application::GetDisplayInfoWindow()
{
  AUTONAMES0("DisplayInfoWindow")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Application::SetDisplayInfoWindow(TAutoVal& val)
{
  AUTONAMES0("DisplayInfoWindow")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Application::GetDisplayNoteIndicator()
{
  AUTONAMES0("DisplayNoteIndicator")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Application::SetDisplayNoteIndicator(TAutoVal& val)
{
  AUTONAMES0("DisplayNoteIndicator")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Application::GetDisplayRecentFiles()
{
  AUTONAMES0("DisplayRecentFiles")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Application::SetDisplayRecentFiles(TAutoVal& val)
{
  AUTONAMES0("DisplayRecentFiles")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Application::GetDisplayScrollBars()
{
  AUTONAMES0("DisplayScrollBars")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Application::SetDisplayScrollBars(TAutoVal& val)
{
  AUTONAMES0("DisplayScrollBars")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Application::GetDisplayStatusBar()
{
  AUTONAMES0("DisplayStatusBar")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Application::SetDisplayStatusBar(TAutoVal& val)
{
  AUTONAMES0("DisplayStatusBar")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Application::GetEditDirectlyInCell()
{
  AUTONAMES0("EditDirectlyInCell")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Application::SetEditDirectlyInCell(TAutoVal& val)
{
  AUTONAMES0("EditDirectlyInCell")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Application::GetEnableAnimations()
{
  AUTONAMES0("EnableAnimations")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Application::SetEnableAnimations(TAutoVal& val)
{
  AUTONAMES0("EnableAnimations")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Application::GetEnableAutoComplete()
{
  AUTONAMES0("EnableAutoComplete")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Application::SetEnableAutoComplete(TAutoVal& val)
{
  AUTONAMES0("EnableAutoComplete")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Application::GetEnableCancelKey()
{
  AUTONAMES0("EnableCancelKey")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Application::SetEnableCancelKey(TAutoVal& val)
{
  AUTONAMES0("EnableCancelKey")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Application::GetEnableTipWizard()
{
  AUTONAMES0("EnableTipWizard")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Application::SetEnableTipWizard(TAutoVal& val)
{
  AUTONAMES0("EnableTipWizard")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Application::GetFileConverters()
{
  AUTONAMES0("FileConverters")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Application::SetFileConverters(TAutoVal& val)
{
  AUTONAMES0("FileConverters")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Application::GetFixedDecimal()
{
  AUTONAMES0("FixedDecimal")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Application::SetFixedDecimal(TAutoVal& val)
{
  AUTONAMES0("FixedDecimal")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Application::GetFixedDecimalPlaces()
{
  AUTONAMES0("FixedDecimalPlaces")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Application::SetFixedDecimalPlaces(TAutoVal& val)
{
  AUTONAMES0("FixedDecimalPlaces")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Application::GetHeight()
{
  AUTONAMES0("Height")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Application::SetHeight(TAutoVal& val)
{
  AUTONAMES0("Height")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Application::GetIgnoreRemoteRequests()
{
  AUTONAMES0("IgnoreRemoteRequests")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Application::SetIgnoreRemoteRequests(TAutoVal& val)
{
  AUTONAMES0("IgnoreRemoteRequests")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Application::GetInteractive()
{
  AUTONAMES0("Interactive")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Application::SetInteractive(TAutoVal& val)
{
  AUTONAMES0("Interactive")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Application::GetInternational()
{
  AUTONAMES0("International")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Application::SetInternational(TAutoVal& val)
{
  AUTONAMES0("International")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Application::GetIteration()
{
  AUTONAMES0("Iteration")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Application::SetIteration(TAutoVal& val)
{
  AUTONAMES0("Iteration")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Application::GetLargeButtons()
{
  AUTONAMES0("LargeButtons")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Application::SetLargeButtons(TAutoVal& val)
{
  AUTONAMES0("LargeButtons")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Application::GetLeft()
{
  AUTONAMES0("Left")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Application::SetLeft(TAutoVal& val)
{
  AUTONAMES0("Left")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Application::GetLibraryPath()
{
  AUTONAMES0("LibraryPath")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Application::SetLibraryPath(TAutoVal& val)
{
  AUTONAMES0("LibraryPath")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Application::GetMailSession()
{
  AUTONAMES0("MailSession")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Application::SetMailSession(TAutoVal& val)
{
  AUTONAMES0("MailSession")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Application::GetMailSystem()
{
  AUTONAMES0("MailSystem")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Application::SetMailSystem(TAutoVal& val)
{
  AUTONAMES0("MailSystem")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Application::GetMathCoprocessorAvailable()
{
  AUTONAMES0("MathCoprocessorAvailable")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Application::SetMathCoprocessorAvailable(TAutoVal& val)
{
  AUTONAMES0("MathCoprocessorAvailable")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Application::GetMaxChange()
{
  AUTONAMES0("MaxChange")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Application::SetMaxChange(TAutoVal& val)
{
  AUTONAMES0("MaxChange")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Application::GetMaxIterations()
{
  AUTONAMES0("MaxIterations")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Application::SetMaxIterations(TAutoVal& val)
{
  AUTONAMES0("MaxIterations")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Application::GetMemoryFree()
{
  AUTONAMES0("MemoryFree")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Application::SetMemoryFree(TAutoVal& val)
{
  AUTONAMES0("MemoryFree")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Application::GetMemoryTotal()
{
  AUTONAMES0("MemoryTotal")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Application::SetMemoryTotal(TAutoVal& val)
{
  AUTONAMES0("MemoryTotal")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Application::GetMemoryUsed()
{
  AUTONAMES0("MemoryUsed")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Application::SetMemoryUsed(TAutoVal& val)
{
  AUTONAMES0("MemoryUsed")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Application::GetMouseAvailable()
{
  AUTONAMES0("MouseAvailable")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Application::SetMouseAvailable(TAutoVal& val)
{
  AUTONAMES0("MouseAvailable")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Application::GetMoveAfterReturn()
{
  AUTONAMES0("MoveAfterReturn")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Application::SetMoveAfterReturn(TAutoVal& val)
{
  AUTONAMES0("MoveAfterReturn")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Application::GetMoveAfterReturnDirection()
{
  AUTONAMES0("MoveAfterReturnDirection")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Application::SetMoveAfterReturnDirection(TAutoVal& val)
{
  AUTONAMES0("MoveAfterReturnDirection")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Application::GetName()
{
  AUTONAMES0("Name")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Application::SetName(TAutoVal& val)
{
  AUTONAMES0("Name")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Application::GetNetworkTemplatesPath()
{
  AUTONAMES0("NetworkTemplatesPath")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Application::SetNetworkTemplatesPath(TAutoVal& val)
{
  AUTONAMES0("NetworkTemplatesPath")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Application::GetOnCalculate()
{
  AUTONAMES0("OnCalculate")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Application::SetOnCalculate(TAutoVal& val)
{
  AUTONAMES0("OnCalculate")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Application::GetOnData()
{
  AUTONAMES0("OnData")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Application::SetOnData(TAutoVal& val)
{
  AUTONAMES0("OnData")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Application::GetOnDoubleClick()
{
  AUTONAMES0("OnDoubleClick")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Application::SetOnDoubleClick(TAutoVal& val)
{
  AUTONAMES0("OnDoubleClick")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Application::GetOnEntry()
{
  AUTONAMES0("OnEntry")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Application::SetOnEntry(TAutoVal& val)
{
  AUTONAMES0("OnEntry")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Application::GetOnSheetActivate()
{
  AUTONAMES0("OnSheetActivate")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Application::SetOnSheetActivate(TAutoVal& val)
{
  AUTONAMES0("OnSheetActivate")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Application::GetOnSheetDeactivate()
{
  AUTONAMES0("OnSheetDeactivate")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Application::SetOnSheetDeactivate(TAutoVal& val)
{
  AUTONAMES0("OnSheetDeactivate")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Application::GetOnWindow()
{
  AUTONAMES0("OnWindow")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Application::SetOnWindow(TAutoVal& val)
{
  AUTONAMES0("OnWindow")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Application::GetOperatingSystem()
{
  AUTONAMES0("OperatingSystem")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Application::SetOperatingSystem(TAutoVal& val)
{
  AUTONAMES0("OperatingSystem")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Application::GetOrganizationName()
{
  AUTONAMES0("OrganizationName")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Application::SetOrganizationName(TAutoVal& val)
{
  AUTONAMES0("OrganizationName")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Application::GetParent()
{
  AUTONAMES0("Parent")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Application::SetParent(TAutoVal& val)
{
  AUTONAMES0("Parent")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Application::GetPath()
{
  AUTONAMES0("Path")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Application::SetPath(TAutoVal& val)
{
  AUTONAMES0("Path")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Application::GetPathSeparator()
{
  AUTONAMES0("PathSeparator")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Application::SetPathSeparator(TAutoVal& val)
{
  AUTONAMES0("PathSeparator")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Application::GetPreviousSelections()
{
  AUTONAMES0("PreviousSelections")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Application::SetPreviousSelections(TAutoVal& val)
{
  AUTONAMES0("PreviousSelections")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Application::GetPromptForSummaryInfo()
{
  AUTONAMES0("PromptForSummaryInfo")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Application::SetPromptForSummaryInfo(TAutoVal& val)
{
  AUTONAMES0("PromptForSummaryInfo")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Application::GetRecordRelative()
{
  AUTONAMES0("RecordRelative")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Application::SetRecordRelative(TAutoVal& val)
{
  AUTONAMES0("RecordRelative")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Application::GetReferenceStyle()
{
  AUTONAMES0("ReferenceStyle")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Application::SetReferenceStyle(TAutoVal& val)
{
  AUTONAMES0("ReferenceStyle")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Application::GetRegisteredFunctions()
{
  AUTONAMES0("RegisteredFunctions")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Application::SetRegisteredFunctions(TAutoVal& val)
{
  AUTONAMES0("RegisteredFunctions")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Application::GetScreenUpdating()
{
  AUTONAMES0("ScreenUpdating")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Application::SetScreenUpdating(TAutoVal& val)
{
  AUTONAMES0("ScreenUpdating")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Application::GetSelection()
{
  AUTONAMES0("Selection")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Application::SetSelection(TAutoVal& val)
{
  AUTONAMES0("Selection")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Application::GetSheetsInNewWorkbook()
{
  AUTONAMES0("SheetsInNewWorkbook")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Application::SetSheetsInNewWorkbook(TAutoVal& val)
{
  AUTONAMES0("SheetsInNewWorkbook")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Application::GetShowToolTips()
{
  AUTONAMES0("ShowToolTips")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Application::SetShowToolTips(TAutoVal& val)
{
  AUTONAMES0("ShowToolTips")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Application::GetStandardFont()
{
  AUTONAMES0("StandardFont")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Application::SetStandardFont(TAutoVal& val)
{
  AUTONAMES0("StandardFont")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Application::GetStandardFontSize()
{
  AUTONAMES0("StandardFontSize")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Application::SetStandardFontSize(TAutoVal& val)
{
  AUTONAMES0("StandardFontSize")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Application::GetStartupPath()
{
  AUTONAMES0("StartupPath")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Application::SetStartupPath(TAutoVal& val)
{
  AUTONAMES0("StartupPath")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Application::GetStatusBar()
{
  AUTONAMES0("StatusBar")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Application::SetStatusBar(TAutoVal& val)
{
  AUTONAMES0("StatusBar")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Application::GetTemplatesPath()
{
  AUTONAMES0("TemplatesPath")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Application::SetTemplatesPath(TAutoVal& val)
{
  AUTONAMES0("TemplatesPath")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Application::GetThisWorkbook()
{
  AUTONAMES0("ThisWorkbook")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Application::SetThisWorkbook(TAutoVal& val)
{
  AUTONAMES0("ThisWorkbook")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Application::GetTop()
{
  AUTONAMES0("Top")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Application::SetTop(TAutoVal& val)
{
  AUTONAMES0("Top")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Application::GetTransitionMenuKey()
{
  AUTONAMES0("TransitionMenuKey")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Application::SetTransitionMenuKey(TAutoVal& val)
{
  AUTONAMES0("TransitionMenuKey")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Application::GetTransitionMenuKeyAction()
{
  AUTONAMES0("TransitionMenuKeyAction")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Application::SetTransitionMenuKeyAction(TAutoVal& val)
{
  AUTONAMES0("TransitionMenuKeyAction")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Application::GetTransitionNavigKeys()
{
  AUTONAMES0("TransitionNavigKeys")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Application::SetTransitionNavigKeys(TAutoVal& val)
{
  AUTONAMES0("TransitionNavigKeys")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Application::GetUsableHeight()
{
  AUTONAMES0("UsableHeight")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Application::SetUsableHeight(TAutoVal& val)
{
  AUTONAMES0("UsableHeight")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Application::GetUsableWidth()
{
  AUTONAMES0("UsableWidth")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Application::SetUsableWidth(TAutoVal& val)
{
  AUTONAMES0("UsableWidth")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Application::GetUserName()
{
  AUTONAMES0("UserName")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Application::SetUserName(TAutoVal& val)
{
  AUTONAMES0("UserName")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Application::GetValue()
{
  AUTONAMES0("Value")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Application::SetValue(TAutoVal& val)
{
  AUTONAMES0("Value")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Application::GetVersion()
{
  AUTONAMES0("Version")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Application::SetVersion(TAutoVal& val)
{
  AUTONAMES0("Version")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Application::GetVisible()
{
  AUTONAMES0("Visible")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Application::SetVisible(TAutoVal& val)
{
  AUTONAMES0("Visible")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Application::GetWidth()
{
  AUTONAMES0("Width")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Application::SetWidth(TAutoVal& val)
{
  AUTONAMES0("Width")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Application::GetWindowsForPens()
{
  AUTONAMES0("WindowsForPens")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Application::SetWindowsForPens(TAutoVal& val)
{
  AUTONAMES0("WindowsForPens")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Application::GetWindowState()
{
  AUTONAMES0("WindowState")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Application::SetWindowState(TAutoVal& val)
{
  AUTONAMES0("WindowState")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Application::_WSFunction(TAutoVal& Range, TAutoVal& Arg1, TAutoVal& Arg2, TAutoVal& Arg3, TAutoVal& Arg4, TAutoVal& Arg5, TAutoVal& Arg6, TAutoVal& Arg7, TAutoVal& Arg8, TAutoVal& Arg9, TAutoVal& Arg10, TAutoVal& Arg11, TAutoVal& Arg12, TAutoVal& Arg13, TAutoVal& Arg14, TAutoVal& Arg15, TAutoVal& Arg16, TAutoVal& Arg17, TAutoVal& Arg18, TAutoVal& Arg19, TAutoVal& Arg20, TAutoVal& Arg21, TAutoVal& Arg22, TAutoVal& Arg23, TAutoVal& Arg24, TAutoVal& Arg25, TAutoVal& Arg26, TAutoVal& Arg27, TAutoVal& Arg28, TAutoVal& Arg29, TAutoVal& Arg30)
{
  AUTONAMES0("_WSFunction")
  AUTOARGS31(Range, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Arg8, Arg9, Arg10, Arg11, Arg12, Arg13, Arg14, Arg15, Arg16, Arg17, Arg18, Arg19, Arg20, Arg21, Arg22, Arg23, Arg24, Arg25, Arg26, Arg27, Arg28, Arg29, Arg30)
  AUTOCALL_METHOD_RET
}

TAutoVal Application::Acos()
{
  AUTONAMES0("Acos")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Application::Acosh()
{
  AUTONAMES0("Acosh")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Application::ActivateMicrosoftApp(TAutoVal& Index)
{
  AUTONAMES0("ActivateMicrosoftApp")
  AUTOARGS1(Index)
  AUTOCALL_METHOD_RET
}

TAutoVal Application::AddChartAutoFormat(TAutoVal& Chart, TAutoVal& Name, TAutoVal& Description)
{
  AUTONAMES0("AddChartAutoFormat")
  AUTOARGS3(Chart, Name, Description)
  AUTOCALL_METHOD_RET
}

TAutoVal Application::AddCustomList(TAutoVal& ListArray, TAutoVal& ByRow)
{
  AUTONAMES0("AddCustomList")
  AUTOARGS2(ListArray, ByRow)
  AUTOCALL_METHOD_RET
}

TAutoVal Application::AddIns(TAutoVal& Index)
{
  AUTONAMES0("AddIns")
  AUTOARGS1(Index)
  AUTOCALL_METHOD_RET
}

TAutoVal Application::And()
{
  AUTONAMES0("And")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

/*
TAutoVal Application::Application()
{
  AUTONAMES0("Application")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}
*/

TAutoVal Application::Asin()
{
  AUTONAMES0("Asin")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Application::Asinh()
{
  AUTONAMES0("Asinh")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Application::Atan2()
{
  AUTONAMES0("Atan2")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Application::Atanh()
{
  AUTONAMES0("Atanh")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Application::AveDev()
{
  AUTONAMES0("AveDev")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Application::Average()
{
  AUTONAMES0("Average")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Application::BetaDist()
{
  AUTONAMES0("BetaDist")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Application::BetaInv()
{
  AUTONAMES0("BetaInv")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Application::BinomDist()
{
  AUTONAMES0("BinomDist")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Application::Calculate()
{
  AUTONAMES0("Calculate")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Application::Ceiling()
{
  AUTONAMES0("Ceiling")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Application::Cells(TAutoVal& RowIndex, TAutoVal& ColumnIndex)
{
  AUTONAMES0("Cells")
  AUTOARGS2(RowIndex, ColumnIndex)
  AUTOCALL_METHOD_RET
}

TAutoVal Application::CentimetersToPoints(TAutoVal& Centimeters)
{
  AUTONAMES0("CentimetersToPoints")
  AUTOARGS1(Centimeters)
  AUTOCALL_METHOD_RET
}

TAutoVal Application::Charts(TAutoVal& Index)
{
  AUTONAMES0("Charts")
  AUTOARGS1(Index)
  AUTOCALL_METHOD_RET
}

TAutoVal Application::CheckSpelling(TAutoVal& Word, TAutoVal& CustomDictionary, TAutoVal& IgnoreUppercase)
{
  AUTONAMES0("CheckSpelling")
  AUTOARGS3(Word, CustomDictionary, IgnoreUppercase)
  AUTOCALL_METHOD_RET
}

TAutoVal Application::ChiDist()
{
  AUTONAMES0("ChiDist")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Application::ChiInv()
{
  AUTONAMES0("ChiInv")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Application::ChiTest()
{
  AUTONAMES0("ChiTest")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Application::Choose()
{
  AUTONAMES0("Choose")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Application::Clean()
{
  AUTONAMES0("Clean")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Application::Columns(TAutoVal& Index)
{
  AUTONAMES0("Columns")
  AUTOARGS1(Index)
  AUTOCALL_METHOD_RET
}

TAutoVal Application::Combin()
{
  AUTONAMES0("Combin")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Application::Confidence()
{
  AUTONAMES0("Confidence")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Application::ConvertFormula(TAutoVal& Formula, TAutoVal& FromReferenceStyle, TAutoVal& ToReferenceStyle, TAutoVal& ToAbsolute, TAutoVal& RelativeTo)
{
  AUTONAMES0("ConvertFormula")
  AUTOARGS5(Formula, FromReferenceStyle, ToReferenceStyle, ToAbsolute, RelativeTo)
  AUTOCALL_METHOD_RET
}

TAutoVal Application::Correl()
{
  AUTONAMES0("Correl")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Application::Cosh()
{
  AUTONAMES0("Cosh")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Application::Count()
{
  AUTONAMES0("Count")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Application::CountA()
{
  AUTONAMES0("CountA")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Application::CountBlank()
{
  AUTONAMES0("CountBlank")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Application::CountIf()
{
  AUTONAMES0("CountIf")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Application::Covar()
{
  AUTONAMES0("Covar")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Application::CritBinom()
{
  AUTONAMES0("CritBinom")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Application::DAverage()
{
  AUTONAMES0("DAverage")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Application::Days360()
{
  AUTONAMES0("Days360")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Application::Db()
{
  AUTONAMES0("Db")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Application::DCount()
{
  AUTONAMES0("DCount")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Application::DCountA()
{
  AUTONAMES0("DCountA")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Application::Ddb()
{
  AUTONAMES0("Ddb")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Application::DDEExecute(TAutoVal& Channel, TAutoVal& String)
{
  AUTONAMES0("DDEExecute")
  AUTOARGS2(Channel, String)
  AUTOCALL_METHOD_RET
}

TAutoVal Application::DDEInitiate(TAutoVal& App, TAutoVal& Topic)
{
  AUTONAMES0("DDEInitiate")
  AUTOARGS2(App, Topic)
  AUTOCALL_METHOD_RET
}

TAutoVal Application::DDEPoke(TAutoVal& Channel, TAutoVal& Item, TAutoVal& Data)
{
  AUTONAMES0("DDEPoke")
  AUTOARGS3(Channel, Item, Data)
  AUTOCALL_METHOD_RET
}

TAutoVal Application::DDERequest(TAutoVal& Channel, TAutoVal& Item)
{
  AUTONAMES0("DDERequest")
  AUTOARGS2(Channel, Item)
  AUTOCALL_METHOD_RET
}

TAutoVal Application::DDETerminate(TAutoVal& Channel)
{
  AUTONAMES0("DDETerminate")
  AUTOARGS1(Channel)
  AUTOCALL_METHOD_RET
}

TAutoVal Application::Degrees()
{
  AUTONAMES0("Degrees")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Application::DeleteChartAutoFormat(TAutoVal& Name)
{
  AUTONAMES0("DeleteChartAutoFormat")
  AUTOARGS1(Name)
  AUTOCALL_METHOD_RET
}

TAutoVal Application::DeleteCustomList(TAutoVal& ListNum)
{
  AUTONAMES0("DeleteCustomList")
  AUTOARGS1(ListNum)
  AUTOCALL_METHOD_RET
}

TAutoVal Application::DevSq()
{
  AUTONAMES0("DevSq")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Application::DGet()
{
  AUTONAMES0("DGet")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Application::Dialogs(TAutoVal& Index)
{
  AUTONAMES0("Dialogs")
  AUTOARGS1(Index)
  AUTOCALL_METHOD_RET
}

TAutoVal Application::DialogSheets(TAutoVal& Index)
{
  AUTONAMES0("DialogSheets")
  AUTOARGS1(Index)
  AUTOCALL_METHOD_RET
}

TAutoVal Application::DMax()
{
  AUTONAMES0("DMax")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Application::DMin()
{
  AUTONAMES0("DMin")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Application::Dollar()
{
  AUTONAMES0("Dollar")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Application::DoubleClick()
{
  AUTONAMES0("DoubleClick")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Application::DProduct()
{
  AUTONAMES0("DProduct")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Application::DStDev()
{
  AUTONAMES0("DStDev")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Application::DStDevP()
{
  AUTONAMES0("DStDevP")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Application::DSum()
{
  AUTONAMES0("DSum")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Application::DVar()
{
  AUTONAMES0("DVar")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Application::DVarP()
{
  AUTONAMES0("DVarP")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Application::_Evaluate(TAutoVal& Name)
{
  AUTONAMES0("_Evaluate")
  AUTOARGS1(Name)
  AUTOCALL_METHOD_RET
}

TAutoVal Application::Evaluate(TAutoVal& Name)
{
  AUTONAMES0("Evaluate")
  AUTOARGS1(Name)
  AUTOCALL_METHOD_RET
}

TAutoVal Application::Even()
{
  AUTONAMES0("Even")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Application::Excel4IntlMacroSheets(TAutoVal& Index)
{
  AUTONAMES0("Excel4IntlMacroSheets")
  AUTOARGS1(Index)
  AUTOCALL_METHOD_RET
}

TAutoVal Application::Excel4MacroSheets(TAutoVal& Index)
{
  AUTONAMES0("Excel4MacroSheets")
  AUTOARGS1(Index)
  AUTOCALL_METHOD_RET
}

TAutoVal Application::ExecuteExcel4Macro(TAutoVal& String)
{
  AUTONAMES0("ExecuteExcel4Macro")
  AUTOARGS1(String)
  AUTOCALL_METHOD_RET
}

TAutoVal Application::ExponDist()
{
  AUTONAMES0("ExponDist")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Application::Fact()
{
  AUTONAMES0("Fact")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Application::FDist()
{
  AUTONAMES0("FDist")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Application::Find()
{
  AUTONAMES0("Find")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Application::FindB()
{
  AUTONAMES0("FindB")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Application::FindFile()
{
  AUTONAMES0("FindFile")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Application::FInv()
{
  AUTONAMES0("FInv")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Application::Fisher()
{
  AUTONAMES0("Fisher")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Application::FisherInv()
{
  AUTONAMES0("FisherInv")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Application::Fixed()
{
  AUTONAMES0("Fixed")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Application::Floor()
{
  AUTONAMES0("Floor")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Application::Forecast()
{
  AUTONAMES0("Forecast")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Application::Frequency()
{
  AUTONAMES0("Frequency")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Application::FTest()
{
  AUTONAMES0("FTest")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Application::Fv()
{
  AUTONAMES0("Fv")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Application::GammaDist()
{
  AUTONAMES0("GammaDist")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Application::GammaInv()
{
  AUTONAMES0("GammaInv")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Application::GammaLn()
{
  AUTONAMES0("GammaLn")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Application::GeoMean()
{
  AUTONAMES0("GeoMean")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Application::GetCustomListContents(TAutoVal& ListNum)
{
  AUTONAMES0("GetCustomListContents")
  AUTOARGS1(ListNum)
  AUTOCALL_METHOD_RET
}

TAutoVal Application::GetCustomListNum(TAutoVal& ListArray)
{
  AUTONAMES0("GetCustomListNum")
  AUTOARGS1(ListArray)
  AUTOCALL_METHOD_RET
}

TAutoVal Application::GetOpenFilename(TAutoVal& FileFilter, TAutoVal& FilterIndex, TAutoVal& Title, TAutoVal& ButtonText, TAutoVal& MultiSelect)
{
  AUTONAMES0("GetOpenFilename")
  AUTOARGS5(FileFilter, FilterIndex, Title, ButtonText, MultiSelect)
  AUTOCALL_METHOD_RET
}

TAutoVal Application::GetSaveAsFilename(TAutoVal& InitialFilename, TAutoVal& FileFilter, TAutoVal& FilterIndex, TAutoVal& Title, TAutoVal& ButtonText)
{
  AUTONAMES0("GetSaveAsFilename")
  AUTOARGS5(InitialFilename, FileFilter, FilterIndex, Title, ButtonText)
  AUTOCALL_METHOD_RET
}

TAutoVal Application::Goto(TAutoVal& Reference, TAutoVal& Scroll)
{
  AUTONAMES0("Goto")
  AUTOARGS2(Reference, Scroll)
  AUTOCALL_METHOD_RET
}

TAutoVal Application::Growth()
{
  AUTONAMES0("Growth")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Application::HarMean()
{
  AUTONAMES0("HarMean")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Application::Help(TAutoVal& HelpFile, TAutoVal& HelpContextID)
{
  AUTONAMES0("Help")
  AUTOARGS2(HelpFile, HelpContextID)
  AUTOCALL_METHOD_RET
}

TAutoVal Application::HLookup()
{
  AUTONAMES0("HLookup")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Application::HypGeomDist()
{
  AUTONAMES0("HypGeomDist")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Application::InchesToPoints(TAutoVal& Inches)
{
  AUTONAMES0("InchesToPoints")
  AUTOARGS1(Inches)
  AUTOCALL_METHOD_RET
}

TAutoVal Application::Index()
{
  AUTONAMES0("Index")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Application::InputBox(TAutoVal& Prompt, TAutoVal& Title, TAutoVal& Default, TAutoVal& Left, TAutoVal& Top, TAutoVal& HelpFile, TAutoVal& HelpContextID, TAutoVal& Type)
{
  AUTONAMES0("InputBox")
  AUTOARGS8(Prompt, Title, Default, Left, Top, HelpFile, HelpContextID, Type)
  AUTOCALL_METHOD_RET
}

TAutoVal Application::Intercept()
{
  AUTONAMES0("Intercept")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Application::Intersect(TAutoVal& Arg1, TAutoVal& Arg2, TAutoVal& Arg3, TAutoVal& Arg4, TAutoVal& Arg5, TAutoVal& Arg6, TAutoVal& Arg7, TAutoVal& Arg8, TAutoVal& Arg9, TAutoVal& Arg10, TAutoVal& Arg11, TAutoVal& Arg12, TAutoVal& Arg13, TAutoVal& Arg14, TAutoVal& Arg15, TAutoVal& Arg16, TAutoVal& Arg17, TAutoVal& Arg18, TAutoVal& Arg19, TAutoVal& Arg20, TAutoVal& Arg21, TAutoVal& Arg22, TAutoVal& Arg23, TAutoVal& Arg24, TAutoVal& Arg25, TAutoVal& Arg26, TAutoVal& Arg27, TAutoVal& Arg28, TAutoVal& Arg29, TAutoVal& Arg30)
{
  AUTONAMES0("Intersect")
  AUTOARGS30(Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Arg8, Arg9, Arg10, Arg11, Arg12, Arg13, Arg14, Arg15, Arg16, Arg17, Arg18, Arg19, Arg20, Arg21, Arg22, Arg23, Arg24, Arg25, Arg26, Arg27, Arg28, Arg29, Arg30)
  AUTOCALL_METHOD_RET
}

TAutoVal Application::Ipmt()
{
  AUTONAMES0("Ipmt")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Application::Irr()
{
  AUTONAMES0("Irr")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Application::IsErr()
{
  AUTONAMES0("IsErr")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Application::IsError()
{
  AUTONAMES0("IsError")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Application::IsLogical()
{
  AUTONAMES0("IsLogical")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Application::IsNA()
{
  AUTONAMES0("IsNA")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Application::IsNonText()
{
  AUTONAMES0("IsNonText")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Application::IsNumber()
{
  AUTONAMES0("IsNumber")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Application::Ispmt()
{
  AUTONAMES0("Ispmt")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Application::IsText()
{
  AUTONAMES0("IsText")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Application::Kurt()
{
  AUTONAMES0("Kurt")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Application::Large()
{
  AUTONAMES0("Large")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Application::LinEst()
{
  AUTONAMES0("LinEst")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Application::Ln()
{
  AUTONAMES0("Ln")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Application::Log()
{
  AUTONAMES0("Log")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Application::Log10()
{
  AUTONAMES0("Log10")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Application::LogEst()
{
  AUTONAMES0("LogEst")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Application::LogInv()
{
  AUTONAMES0("LogInv")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Application::LogNormDist()
{
  AUTONAMES0("LogNormDist")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Application::Lookup()
{
  AUTONAMES0("Lookup")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Application::MacroOptions(TAutoVal& Macro, TAutoVal& Description, TAutoVal& HasMenu, TAutoVal& MenuText, TAutoVal& HasShortcutKey, TAutoVal& ShortcutKey, TAutoVal& Category, TAutoVal& StatusBar, TAutoVal& HelpContextID, TAutoVal& HelpFile)
{
  AUTONAMES0("MacroOptions")
  AUTOARGS10(Macro, Description, HasMenu, MenuText, HasShortcutKey, ShortcutKey, Category, StatusBar, HelpContextID, HelpFile)
  AUTOCALL_METHOD_RET
}

TAutoVal Application::MailLogoff()
{
  AUTONAMES0("MailLogoff")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Application::MailLogon(TAutoVal& Name, TAutoVal& Password, TAutoVal& DownloadNewMail)
{
  AUTONAMES0("MailLogon")
  AUTOARGS3(Name, Password, DownloadNewMail)
  AUTOCALL_METHOD_RET
}

TAutoVal Application::Match()
{
  AUTONAMES0("Match")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Application::Max()
{
  AUTONAMES0("Max")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Application::MDeterm()
{
  AUTONAMES0("MDeterm")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Application::Median()
{
  AUTONAMES0("Median")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Application::MenuBars(TAutoVal& Index)
{
  AUTONAMES0("MenuBars")
  AUTOARGS1(Index)
  AUTOCALL_METHOD_RET
}

TAutoVal Application::Min()
{
  AUTONAMES0("Min")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Application::MInverse()
{
  AUTONAMES0("MInverse")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Application::MIrr()
{
  AUTONAMES0("MIrr")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Application::MMult()
{
  AUTONAMES0("MMult")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Application::Mode()
{
  AUTONAMES0("Mode")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Application::Modules(TAutoVal& Index)
{
  AUTONAMES0("Modules")
  AUTOARGS1(Index)
  AUTOCALL_METHOD_RET
}

TAutoVal Application::Names(TAutoVal& Index, TAutoVal& IndexLocal, TAutoVal& RefersTo)
{
  AUTONAMES0("Names")
  AUTOARGS3(Index, IndexLocal, RefersTo)
  AUTOCALL_METHOD_RET
}

TAutoVal Application::NegBinomDist()
{
  AUTONAMES0("NegBinomDist")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Application::NextLetter()
{
  AUTONAMES0("NextLetter")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Application::NormDist()
{
  AUTONAMES0("NormDist")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Application::NormInv()
{
  AUTONAMES0("NormInv")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Application::NormSDist()
{
  AUTONAMES0("NormSDist")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Application::NormSInv()
{
  AUTONAMES0("NormSInv")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Application::NPer()
{
  AUTONAMES0("NPer")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Application::Npv()
{
  AUTONAMES0("Npv")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Application::Odd()
{
  AUTONAMES0("Odd")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Application::OnKey(TAutoVal& Key, TAutoVal& Procedure)
{
  AUTONAMES0("OnKey")
  AUTOARGS2(Key, Procedure)
  AUTOCALL_METHOD_RET
}

TAutoVal Application::OnRepeat(TAutoVal& Text, TAutoVal& Procedure)
{
  AUTONAMES0("OnRepeat")
  AUTOARGS2(Text, Procedure)
  AUTOCALL_METHOD_RET
}

TAutoVal Application::OnTime(TAutoVal& EarliestTime, TAutoVal& Procedure, TAutoVal& LatestTime, TAutoVal& Schedule)
{
  AUTONAMES0("OnTime")
  AUTOARGS4(EarliestTime, Procedure, LatestTime, Schedule)
  AUTOCALL_METHOD_RET
}

TAutoVal Application::OnUndo(TAutoVal& Text, TAutoVal& Procedure)
{
  AUTONAMES0("OnUndo")
  AUTOARGS2(Text, Procedure)
  AUTOCALL_METHOD_RET
}

TAutoVal Application::Or()
{
  AUTONAMES0("Or")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Application::Pearson()
{
  AUTONAMES0("Pearson")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Application::Percentile()
{
  AUTONAMES0("Percentile")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Application::PercentRank()
{
  AUTONAMES0("PercentRank")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Application::Permut()
{
  AUTONAMES0("Permut")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Application::Pi()
{
  AUTONAMES0("Pi")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Application::Pmt()
{
  AUTONAMES0("Pmt")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Application::Poisson()
{
  AUTONAMES0("Poisson")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Application::Power()
{
  AUTONAMES0("Power")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Application::Ppmt()
{
  AUTONAMES0("Ppmt")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Application::Prob()
{
  AUTONAMES0("Prob")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Application::Product()
{
  AUTONAMES0("Product")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Application::Proper()
{
  AUTONAMES0("Proper")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Application::Pv()
{
  AUTONAMES0("Pv")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Application::Quartile()
{
  AUTONAMES0("Quartile")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Application::Quit()
{
  AUTONAMES0("Quit")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Application::Radians()
{
  AUTONAMES0("Radians")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Application::Range(TAutoVal& Cell1, TAutoVal& Cell2)
{
  AUTONAMES0("Range")
  AUTOARGS2(Cell1, Cell2)
  AUTOCALL_METHOD_RET
}

TAutoVal Application::Rank()
{
  AUTONAMES0("Rank")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Application::Rate()
{
  AUTONAMES0("Rate")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Application::RecordMacro(TAutoVal& BasicCode, TAutoVal& XlmCode)
{
  AUTONAMES0("RecordMacro")
  AUTOARGS2(BasicCode, XlmCode)
  AUTOCALL_METHOD_RET
}

TAutoVal Application::RegisterXLL(TAutoVal& Filename)
{
  AUTONAMES0("RegisterXLL")
  AUTOARGS1(Filename)
  AUTOCALL_METHOD_RET
}

TAutoVal Application::Repeat()
{
  AUTONAMES0("Repeat")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Application::Replace()
{
  AUTONAMES0("Replace")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Application::ReplaceB()
{
  AUTONAMES0("ReplaceB")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Application::Rept()
{
  AUTONAMES0("Rept")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Application::ResetTipWizard()
{
  AUTONAMES0("ResetTipWizard")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Application::Roman()
{
  AUTONAMES0("Roman")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Application::Round()
{
  AUTONAMES0("Round")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Application::RoundDown()
{
  AUTONAMES0("RoundDown")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Application::RoundUp()
{
  AUTONAMES0("RoundUp")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Application::Rows(TAutoVal& Index)
{
  AUTONAMES0("Rows")
  AUTOARGS1(Index)
  AUTOCALL_METHOD_RET
}

TAutoVal Application::RSq()
{
  AUTONAMES0("RSq")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Application::Run(TAutoVal& Macro, TAutoVal& Arg1, TAutoVal& Arg2, TAutoVal& Arg3, TAutoVal& Arg4, TAutoVal& Arg5, TAutoVal& Arg6, TAutoVal& Arg7, TAutoVal& Arg8, TAutoVal& Arg9, TAutoVal& Arg10, TAutoVal& Arg11, TAutoVal& Arg12, TAutoVal& Arg13, TAutoVal& Arg14, TAutoVal& Arg15, TAutoVal& Arg16, TAutoVal& Arg17, TAutoVal& Arg18, TAutoVal& Arg19, TAutoVal& Arg20, TAutoVal& Arg21, TAutoVal& Arg22, TAutoVal& Arg23, TAutoVal& Arg24, TAutoVal& Arg25, TAutoVal& Arg26, TAutoVal& Arg27, TAutoVal& Arg28, TAutoVal& Arg29, TAutoVal& Arg30)
{
  AUTONAMES0("Run")
  AUTOARGS31(Macro, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Arg8, Arg9, Arg10, Arg11, Arg12, Arg13, Arg14, Arg15, Arg16, Arg17, Arg18, Arg19, Arg20, Arg21, Arg22, Arg23, Arg24, Arg25, Arg26, Arg27, Arg28, Arg29, Arg30)
  AUTOCALL_METHOD_RET
}

TAutoVal Application::Save(TAutoVal& Filename)
{
  AUTONAMES0("Save")
  AUTOARGS1(Filename)
  AUTOCALL_METHOD_RET
}

TAutoVal Application::Search()
{
  AUTONAMES0("Search")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Application::SearchB()
{
  AUTONAMES0("SearchB")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Application::SendKeys(TAutoVal& Keys, TAutoVal& Wait)
{
  AUTONAMES0("SendKeys")
  AUTOARGS2(Keys, Wait)
  AUTOCALL_METHOD_RET
}

TAutoVal Application::SetDefaultChart(TAutoVal& FormatName)
{
  AUTONAMES0("SetDefaultChart")
  AUTOARGS1(FormatName)
  AUTOCALL_METHOD_RET
}

TAutoVal Application::Sheets(TAutoVal& Index)
{
  AUTONAMES0("Sheets")
  AUTOARGS1(Index)
  AUTOCALL_METHOD_RET
}

TAutoVal Application::ShortcutMenus(TAutoVal& Index)
{
  AUTONAMES0("ShortcutMenus")
  AUTOARGS1(Index)
  AUTOCALL_METHOD_RET
}

TAutoVal Application::Sinh()
{
  AUTONAMES0("Sinh")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Application::Skew()
{
  AUTONAMES0("Skew")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Application::Sln()
{
  AUTONAMES0("Sln")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Application::Slope()
{
  AUTONAMES0("Slope")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Application::Small()
{
  AUTONAMES0("Small")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Application::Standardize()
{
  AUTONAMES0("Standardize")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Application::StDev()
{
  AUTONAMES0("StDev")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Application::StDevP()
{
  AUTONAMES0("StDevP")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Application::StEyx()
{
  AUTONAMES0("StEyx")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Application::Substitute()
{
  AUTONAMES0("Substitute")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Application::Subtotal()
{
  AUTONAMES0("Subtotal")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Application::Sum()
{
  AUTONAMES0("Sum")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Application::SumIf()
{
  AUTONAMES0("SumIf")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Application::SumProduct()
{
  AUTONAMES0("SumProduct")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Application::SumSq()
{
  AUTONAMES0("SumSq")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Application::SumX2MY2()
{
  AUTONAMES0("SumX2MY2")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Application::SumX2PY2()
{
  AUTONAMES0("SumX2PY2")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Application::SumXMY2()
{
  AUTONAMES0("SumXMY2")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Application::Syd()
{
  AUTONAMES0("Syd")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Application::Tanh()
{
  AUTONAMES0("Tanh")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Application::TDist()
{
  AUTONAMES0("TDist")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Application::Text()
{
  AUTONAMES0("Text")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Application::TInv()
{
  AUTONAMES0("TInv")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Application::Toolbars(TAutoVal& Index)
{
  AUTONAMES0("Toolbars")
  AUTOARGS1(Index)
  AUTOCALL_METHOD_RET
}

TAutoVal Application::Transpose()
{
  AUTONAMES0("Transpose")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Application::Trend()
{
  AUTONAMES0("Trend")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Application::Trim()
{
  AUTONAMES0("Trim")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Application::TrimMean()
{
  AUTONAMES0("TrimMean")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Application::TTest()
{
  AUTONAMES0("TTest")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Application::Undo()
{
  AUTONAMES0("Undo")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Application::Union(TAutoVal& Arg1, TAutoVal& Arg2, TAutoVal& Arg3, TAutoVal& Arg4, TAutoVal& Arg5, TAutoVal& Arg6, TAutoVal& Arg7, TAutoVal& Arg8, TAutoVal& Arg9, TAutoVal& Arg10, TAutoVal& Arg11, TAutoVal& Arg12, TAutoVal& Arg13, TAutoVal& Arg14, TAutoVal& Arg15, TAutoVal& Arg16, TAutoVal& Arg17, TAutoVal& Arg18, TAutoVal& Arg19, TAutoVal& Arg20, TAutoVal& Arg21, TAutoVal& Arg22, TAutoVal& Arg23, TAutoVal& Arg24, TAutoVal& Arg25, TAutoVal& Arg26, TAutoVal& Arg27, TAutoVal& Arg28, TAutoVal& Arg29, TAutoVal& Arg30)
{
  AUTONAMES0("Union")
  AUTOARGS30(Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Arg8, Arg9, Arg10, Arg11, Arg12, Arg13, Arg14, Arg15, Arg16, Arg17, Arg18, Arg19, Arg20, Arg21, Arg22, Arg23, Arg24, Arg25, Arg26, Arg27, Arg28, Arg29, Arg30)
  AUTOCALL_METHOD_RET
}

TAutoVal Application::USDollar()
{
  AUTONAMES0("USDollar")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Application::Var()
{
  AUTONAMES0("Var")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Application::VarP()
{
  AUTONAMES0("VarP")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Application::Vdb()
{
  AUTONAMES0("Vdb")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Application::VLookup()
{
  AUTONAMES0("VLookup")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Application::Volatile(TAutoVal& Volatile)
{
  AUTONAMES0("Volatile")
  AUTOARGS1(Volatile)
  AUTOCALL_METHOD_RET
}

TAutoVal Application::Wait(TAutoVal& Time)
{
  AUTONAMES0("Wait")
  AUTOARGS1(Time)
  AUTOCALL_METHOD_RET
}

TAutoVal Application::Weekday()
{
  AUTONAMES0("Weekday")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Application::Weibull()
{
  AUTONAMES0("Weibull")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Application::Windows(TAutoVal& Index)
{
  AUTONAMES0("Windows")
  AUTOARGS1(Index)
  AUTOCALL_METHOD_RET
}

TAutoVal Application::Workbooks(TAutoVal& Index)
{
  AUTONAMES0("Workbooks")
  AUTOARGS1(Index)
  AUTOCALL_METHOD_RET
}

TAutoVal Application::Worksheets(TAutoVal& Index)
{
  AUTONAMES0("Worksheets")
  AUTOARGS1(Index)
  AUTOCALL_METHOD_RET
}


// These are overloaded versions that does not pass in any parameters.
// One should typically be able to pass VT_ERROR and DISP_E_PARAMNOTFOUND
// [i.e. TNoArg instance] to a server to indicate no parameter.
// However, in this case, EXCEL really wants *NO* parameters -
// missing parameter won't do.
//
// NOTE: These we not generated by AUTOGEN. Other methods which have these
//       pseudo-optional parameters may require a similar approach.
//
TAutoVal Application::Windows()
{
  AUTONAMES0("Windows")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Application::Workbooks()
{
  AUTONAMES0("Workbooks")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Application::Worksheets()
{
  AUTONAMES0("Worksheets")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Application::ZTest()
{
  AUTONAMES0("ZTest")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}


// TKIND_DISPATCH: Style {00020852-0000-0000-C000-000000000046}\9

TAutoVal Style::GetAddIndent()
{
  AUTONAMES0("AddIndent")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Style::SetAddIndent(TAutoVal& val)
{
  AUTONAMES0("AddIndent")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Style::GetCreator()
{
  AUTONAMES0("Creator")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Style::SetCreator(TAutoVal& val)
{
  AUTONAMES0("Creator")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Style::GetFont()
{
  AUTONAMES0("Font")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Style::SetFont(TAutoVal& val)
{
  AUTONAMES0("Font")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Style::GetFormulaHidden()
{
  AUTONAMES0("FormulaHidden")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Style::SetFormulaHidden(TAutoVal& val)
{
  AUTONAMES0("FormulaHidden")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Style::GetHorizontalAlignment()
{
  AUTONAMES0("HorizontalAlignment")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Style::SetHorizontalAlignment(TAutoVal& val)
{
  AUTONAMES0("HorizontalAlignment")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Style::GetIncludeAlignment()
{
  AUTONAMES0("IncludeAlignment")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Style::SetIncludeAlignment(TAutoVal& val)
{
  AUTONAMES0("IncludeAlignment")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Style::GetIncludeBorder()
{
  AUTONAMES0("IncludeBorder")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Style::SetIncludeBorder(TAutoVal& val)
{
  AUTONAMES0("IncludeBorder")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Style::GetIncludeFont()
{
  AUTONAMES0("IncludeFont")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Style::SetIncludeFont(TAutoVal& val)
{
  AUTONAMES0("IncludeFont")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Style::GetIncludeNumber()
{
  AUTONAMES0("IncludeNumber")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Style::SetIncludeNumber(TAutoVal& val)
{
  AUTONAMES0("IncludeNumber")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Style::GetIncludePatterns()
{
  AUTONAMES0("IncludePatterns")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Style::SetIncludePatterns(TAutoVal& val)
{
  AUTONAMES0("IncludePatterns")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Style::GetIncludeProtection()
{
  AUTONAMES0("IncludeProtection")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Style::SetIncludeProtection(TAutoVal& val)
{
  AUTONAMES0("IncludeProtection")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Style::GetInterior()
{
  AUTONAMES0("Interior")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Style::SetInterior(TAutoVal& val)
{
  AUTONAMES0("Interior")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Style::GetLocked()
{
  AUTONAMES0("Locked")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Style::SetLocked(TAutoVal& val)
{
  AUTONAMES0("Locked")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Style::GetName()
{
  AUTONAMES0("Name")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Style::SetName(TAutoVal& val)
{
  AUTONAMES0("Name")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Style::GetNameLocal()
{
  AUTONAMES0("NameLocal")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Style::SetNameLocal(TAutoVal& val)
{
  AUTONAMES0("NameLocal")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Style::GetNumberFormat()
{
  AUTONAMES0("NumberFormat")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Style::SetNumberFormat(TAutoVal& val)
{
  AUTONAMES0("NumberFormat")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Style::GetNumberFormatLocal()
{
  AUTONAMES0("NumberFormatLocal")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Style::SetNumberFormatLocal(TAutoVal& val)
{
  AUTONAMES0("NumberFormatLocal")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Style::GetOrientation()
{
  AUTONAMES0("Orientation")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Style::SetOrientation(TAutoVal& val)
{
  AUTONAMES0("Orientation")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Style::GetParent()
{
  AUTONAMES0("Parent")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Style::SetParent(TAutoVal& val)
{
  AUTONAMES0("Parent")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Style::GetValue()
{
  AUTONAMES0("Value")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Style::SetValue(TAutoVal& val)
{
  AUTONAMES0("Value")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Style::GetVerticalAlignment()
{
  AUTONAMES0("VerticalAlignment")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Style::SetVerticalAlignment(TAutoVal& val)
{
  AUTONAMES0("VerticalAlignment")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Style::GetWrapText()
{
  AUTONAMES0("WrapText")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Style::SetWrapText(TAutoVal& val)
{
  AUTONAMES0("WrapText")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Style::Application()
{
  AUTONAMES0("Application")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Style::Borders(TAutoVal& Index)
{
  AUTONAMES0("Borders")
  AUTOARGS1(Index)
  AUTOCALL_METHOD_RET
}

TAutoVal Style::Delete()
{
  AUTONAMES0("Delete")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}


// TKIND_DISPATCH: Styles {00020853-0000-0000-C000-000000000046}\9

TAutoVal Styles::GetCount()
{
  AUTONAMES0("Count")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Styles::SetCount(TAutoVal& val)
{
  AUTONAMES0("Count")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Styles::GetCreator()
{
  AUTONAMES0("Creator")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Styles::SetCreator(TAutoVal& val)
{
  AUTONAMES0("Creator")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Styles::GetParent()
{
  AUTONAMES0("Parent")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Styles::SetParent(TAutoVal& val)
{
  AUTONAMES0("Parent")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Styles::_NewEnum()
{
  AUTONAMES0("_NewEnum")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Styles::Add(TAutoVal& Name, TAutoVal& BasedOn)
{
  AUTONAMES0("Add")
  AUTOARGS2(Name, BasedOn)
  AUTOCALL_METHOD_RET
}

TAutoVal Styles::Application()
{
  AUTONAMES0("Application")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Styles::Item(TAutoVal& Index)
{
  AUTONAMES0("Item")
  AUTOARGS1(Index)
  AUTOCALL_METHOD_RET
}

TAutoVal Styles::Merge(TAutoVal& Workbook)
{
  AUTONAMES0("Merge")
  AUTOARGS1(Workbook)
  AUTOCALL_METHOD_RET
}


// TKIND_DISPATCH: Toolbar {0002085C-0000-0000-C000-000000000046}\9

TAutoVal Toolbar::GetBuiltIn()
{
  AUTONAMES0("BuiltIn")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Toolbar::SetBuiltIn(TAutoVal& val)
{
  AUTONAMES0("BuiltIn")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Toolbar::GetCreator()
{
  AUTONAMES0("Creator")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Toolbar::SetCreator(TAutoVal& val)
{
  AUTONAMES0("Creator")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Toolbar::GetHeight()
{
  AUTONAMES0("Height")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Toolbar::SetHeight(TAutoVal& val)
{
  AUTONAMES0("Height")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Toolbar::GetLeft()
{
  AUTONAMES0("Left")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Toolbar::SetLeft(TAutoVal& val)
{
  AUTONAMES0("Left")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Toolbar::GetName()
{
  AUTONAMES0("Name")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Toolbar::SetName(TAutoVal& val)
{
  AUTONAMES0("Name")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Toolbar::GetParent()
{
  AUTONAMES0("Parent")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Toolbar::SetParent(TAutoVal& val)
{
  AUTONAMES0("Parent")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Toolbar::GetPosition()
{
  AUTONAMES0("Position")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Toolbar::SetPosition(TAutoVal& val)
{
  AUTONAMES0("Position")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Toolbar::GetProtection()
{
  AUTONAMES0("Protection")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Toolbar::SetProtection(TAutoVal& val)
{
  AUTONAMES0("Protection")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Toolbar::GetTop()
{
  AUTONAMES0("Top")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Toolbar::SetTop(TAutoVal& val)
{
  AUTONAMES0("Top")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Toolbar::GetVisible()
{
  AUTONAMES0("Visible")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Toolbar::SetVisible(TAutoVal& val)
{
  AUTONAMES0("Visible")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Toolbar::GetWidth()
{
  AUTONAMES0("Width")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Toolbar::SetWidth(TAutoVal& val)
{
  AUTONAMES0("Width")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Toolbar::Application()
{
  AUTONAMES0("Application")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Toolbar::Delete()
{
  AUTONAMES0("Delete")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Toolbar::Reset()
{
  AUTONAMES0("Reset")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Toolbar::ToolbarButtons(TAutoVal& Index)
{
  AUTONAMES0("ToolbarButtons")
  AUTOARGS1(Index)
  AUTOCALL_METHOD_RET
}


// TKIND_DISPATCH: Toolbars {0002085D-0000-0000-C000-000000000046}\9

TAutoVal Toolbars::GetCount()
{
  AUTONAMES0("Count")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Toolbars::SetCount(TAutoVal& val)
{
  AUTONAMES0("Count")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Toolbars::GetCreator()
{
  AUTONAMES0("Creator")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Toolbars::SetCreator(TAutoVal& val)
{
  AUTONAMES0("Creator")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Toolbars::GetParent()
{
  AUTONAMES0("Parent")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Toolbars::SetParent(TAutoVal& val)
{
  AUTONAMES0("Parent")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Toolbars::_NewEnum()
{
  AUTONAMES0("_NewEnum")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Toolbars::Add(TAutoVal& Name)
{
  AUTONAMES0("Add")
  AUTOARGS1(Name)
  AUTOCALL_METHOD_RET
}

TAutoVal Toolbars::Application()
{
  AUTONAMES0("Application")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Toolbars::Item(TAutoVal& Index)
{
  AUTONAMES0("Item")
  AUTOARGS1(Index)
  AUTOCALL_METHOD_RET
}


// TKIND_DISPATCH: ToolbarButton {0002085E-0000-0000-C000-000000000046}\9

TAutoVal ToolbarButton::GetBuiltIn()
{
  AUTONAMES0("BuiltIn")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void ToolbarButton::SetBuiltIn(TAutoVal& val)
{
  AUTONAMES0("BuiltIn")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal ToolbarButton::GetBuiltInFace()
{
  AUTONAMES0("BuiltInFace")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void ToolbarButton::SetBuiltInFace(TAutoVal& val)
{
  AUTONAMES0("BuiltInFace")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal ToolbarButton::GetCreator()
{
  AUTONAMES0("Creator")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void ToolbarButton::SetCreator(TAutoVal& val)
{
  AUTONAMES0("Creator")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal ToolbarButton::GetEnabled()
{
  AUTONAMES0("Enabled")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void ToolbarButton::SetEnabled(TAutoVal& val)
{
  AUTONAMES0("Enabled")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal ToolbarButton::GetHelpContextID()
{
  AUTONAMES0("HelpContextID")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void ToolbarButton::SetHelpContextID(TAutoVal& val)
{
  AUTONAMES0("HelpContextID")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal ToolbarButton::GetHelpFile()
{
  AUTONAMES0("HelpFile")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void ToolbarButton::SetHelpFile(TAutoVal& val)
{
  AUTONAMES0("HelpFile")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal ToolbarButton::GetId()
{
  AUTONAMES0("Id")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void ToolbarButton::SetId(TAutoVal& val)
{
  AUTONAMES0("Id")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal ToolbarButton::GetIsGap()
{
  AUTONAMES0("IsGap")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void ToolbarButton::SetIsGap(TAutoVal& val)
{
  AUTONAMES0("IsGap")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal ToolbarButton::GetName()
{
  AUTONAMES0("Name")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void ToolbarButton::SetName(TAutoVal& val)
{
  AUTONAMES0("Name")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal ToolbarButton::GetOnAction()
{
  AUTONAMES0("OnAction")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void ToolbarButton::SetOnAction(TAutoVal& val)
{
  AUTONAMES0("OnAction")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal ToolbarButton::GetParent()
{
  AUTONAMES0("Parent")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void ToolbarButton::SetParent(TAutoVal& val)
{
  AUTONAMES0("Parent")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal ToolbarButton::GetPushed()
{
  AUTONAMES0("Pushed")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void ToolbarButton::SetPushed(TAutoVal& val)
{
  AUTONAMES0("Pushed")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal ToolbarButton::GetStatusBar()
{
  AUTONAMES0("StatusBar")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void ToolbarButton::SetStatusBar(TAutoVal& val)
{
  AUTONAMES0("StatusBar")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal ToolbarButton::GetWidth()
{
  AUTONAMES0("Width")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void ToolbarButton::SetWidth(TAutoVal& val)
{
  AUTONAMES0("Width")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal ToolbarButton::Application()
{
  AUTONAMES0("Application")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal ToolbarButton::Copy(TAutoVal& Toolbar, TAutoVal& Before)
{
  AUTONAMES0("Copy")
  AUTOARGS2(Toolbar, Before)
  AUTOCALL_METHOD_RET
}

TAutoVal ToolbarButton::CopyFace()
{
  AUTONAMES0("CopyFace")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal ToolbarButton::Delete()
{
  AUTONAMES0("Delete")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal ToolbarButton::Edit()
{
  AUTONAMES0("Edit")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal ToolbarButton::Move(TAutoVal& Toolbar, TAutoVal& Before)
{
  AUTONAMES0("Move")
  AUTOARGS2(Toolbar, Before)
  AUTOCALL_METHOD_RET
}

TAutoVal ToolbarButton::PasteFace()
{
  AUTONAMES0("PasteFace")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal ToolbarButton::Reset()
{
  AUTONAMES0("Reset")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}


// TKIND_DISPATCH: ToolbarButtons {0002085F-0000-0000-C000-000000000046}\9

TAutoVal ToolbarButtons::GetCount()
{
  AUTONAMES0("Count")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void ToolbarButtons::SetCount(TAutoVal& val)
{
  AUTONAMES0("Count")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal ToolbarButtons::GetCreator()
{
  AUTONAMES0("Creator")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void ToolbarButtons::SetCreator(TAutoVal& val)
{
  AUTONAMES0("Creator")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal ToolbarButtons::GetParent()
{
  AUTONAMES0("Parent")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void ToolbarButtons::SetParent(TAutoVal& val)
{
  AUTONAMES0("Parent")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal ToolbarButtons::_NewEnum()
{
  AUTONAMES0("_NewEnum")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal ToolbarButtons::Add(TAutoVal& Button, TAutoVal& Before, TAutoVal& OnAction, TAutoVal& Pushed, TAutoVal& Enabled, TAutoVal& StatusBar, TAutoVal& HelpFile, TAutoVal& HelpContextID)
{
  AUTONAMES0("Add")
  AUTOARGS8(Button, Before, OnAction, Pushed, Enabled, StatusBar, HelpFile, HelpContextID)
  AUTOCALL_METHOD_RET
}

TAutoVal ToolbarButtons::Application()
{
  AUTONAMES0("Application")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal ToolbarButtons::Item(TAutoVal& Index)
{
  AUTONAMES0("Item")
  AUTOARGS1(Index)
  AUTOCALL_METHOD_RET
}


// TKIND_DISPATCH: AddIn {00020857-0000-0000-C000-000000000046}\9

TAutoVal AddIn::GetAuthor()
{
  AUTONAMES0("Author")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void AddIn::SetAuthor(TAutoVal& val)
{
  AUTONAMES0("Author")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal AddIn::GetComments()
{
  AUTONAMES0("Comments")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void AddIn::SetComments(TAutoVal& val)
{
  AUTONAMES0("Comments")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal AddIn::GetCreator()
{
  AUTONAMES0("Creator")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void AddIn::SetCreator(TAutoVal& val)
{
  AUTONAMES0("Creator")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal AddIn::GetFullName()
{
  AUTONAMES0("FullName")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void AddIn::SetFullName(TAutoVal& val)
{
  AUTONAMES0("FullName")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal AddIn::GetInstalled()
{
  AUTONAMES0("Installed")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void AddIn::SetInstalled(TAutoVal& val)
{
  AUTONAMES0("Installed")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal AddIn::GetKeywords()
{
  AUTONAMES0("Keywords")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void AddIn::SetKeywords(TAutoVal& val)
{
  AUTONAMES0("Keywords")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal AddIn::GetName()
{
  AUTONAMES0("Name")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void AddIn::SetName(TAutoVal& val)
{
  AUTONAMES0("Name")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal AddIn::GetParent()
{
  AUTONAMES0("Parent")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void AddIn::SetParent(TAutoVal& val)
{
  AUTONAMES0("Parent")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal AddIn::GetPath()
{
  AUTONAMES0("Path")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void AddIn::SetPath(TAutoVal& val)
{
  AUTONAMES0("Path")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal AddIn::GetSubject()
{
  AUTONAMES0("Subject")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void AddIn::SetSubject(TAutoVal& val)
{
  AUTONAMES0("Subject")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal AddIn::GetTitle()
{
  AUTONAMES0("Title")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void AddIn::SetTitle(TAutoVal& val)
{
  AUTONAMES0("Title")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal AddIn::Application()
{
  AUTONAMES0("Application")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}


// TKIND_DISPATCH: AddIns {00020858-0000-0000-C000-000000000046}\9

TAutoVal AddIns::GetCount()
{
  AUTONAMES0("Count")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void AddIns::SetCount(TAutoVal& val)
{
  AUTONAMES0("Count")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal AddIns::GetCreator()
{
  AUTONAMES0("Creator")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void AddIns::SetCreator(TAutoVal& val)
{
  AUTONAMES0("Creator")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal AddIns::GetParent()
{
  AUTONAMES0("Parent")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void AddIns::SetParent(TAutoVal& val)
{
  AUTONAMES0("Parent")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal AddIns::_NewEnum()
{
  AUTONAMES0("_NewEnum")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal AddIns::Add(TAutoVal& Filename, TAutoVal& CopyFile)
{
  AUTONAMES0("Add")
  AUTOARGS2(Filename, CopyFile)
  AUTOCALL_METHOD_RET
}

TAutoVal AddIns::Application()
{
  AUTONAMES0("Application")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal AddIns::Item(TAutoVal& Index)
{
  AUTONAMES0("Item")
  AUTOARGS1(Index)
  AUTOCALL_METHOD_RET
}


// TKIND_DISPATCH: Areas {00020860-0000-0000-C000-000000000046}\9

TAutoVal Areas::GetCount()
{
  AUTONAMES0("Count")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Areas::SetCount(TAutoVal& val)
{
  AUTONAMES0("Count")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Areas::GetCreator()
{
  AUTONAMES0("Creator")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Areas::SetCreator(TAutoVal& val)
{
  AUTONAMES0("Creator")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Areas::GetParent()
{
  AUTONAMES0("Parent")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Areas::SetParent(TAutoVal& val)
{
  AUTONAMES0("Parent")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Areas::_NewEnum()
{
  AUTONAMES0("_NewEnum")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Areas::Application()
{
  AUTONAMES0("Application")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Areas::Item(TAutoVal& Index)
{
  AUTONAMES0("Item")
  AUTOARGS1(Index)
  AUTOCALL_METHOD_RET
}


// TKIND_DISPATCH: Range {00020846-0000-0000-C000-000000000046}\9

TAutoVal Range::GetAddIndent()
{
  AUTONAMES0("AddIndent")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Range::SetAddIndent(TAutoVal& val)
{
  AUTONAMES0("AddIndent")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Range::GetColumn()
{
  AUTONAMES0("Column")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Range::SetColumn(TAutoVal& val)
{
  AUTONAMES0("Column")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Range::GetColumnWidth()
{
  AUTONAMES0("ColumnWidth")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Range::SetColumnWidth(TAutoVal& val)
{
  AUTONAMES0("ColumnWidth")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Range::GetCount()
{
  AUTONAMES0("Count")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Range::SetCount(TAutoVal& val)
{
  AUTONAMES0("Count")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Range::GetCreator()
{
  AUTONAMES0("Creator")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Range::SetCreator(TAutoVal& val)
{
  AUTONAMES0("Creator")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Range::GetCurrentArray()
{
  AUTONAMES0("CurrentArray")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Range::SetCurrentArray(TAutoVal& val)
{
  AUTONAMES0("CurrentArray")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Range::GetCurrentRegion()
{
  AUTONAMES0("CurrentRegion")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Range::SetCurrentRegion(TAutoVal& val)
{
  AUTONAMES0("CurrentRegion")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Range::GetDependents()
{
  AUTONAMES0("Dependents")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Range::SetDependents(TAutoVal& val)
{
  AUTONAMES0("Dependents")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Range::GetDirectDependents()
{
  AUTONAMES0("DirectDependents")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Range::SetDirectDependents(TAutoVal& val)
{
  AUTONAMES0("DirectDependents")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Range::GetDirectPrecedents()
{
  AUTONAMES0("DirectPrecedents")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Range::SetDirectPrecedents(TAutoVal& val)
{
  AUTONAMES0("DirectPrecedents")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Range::GetEntireColumn()
{
  AUTONAMES0("EntireColumn")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Range::SetEntireColumn(TAutoVal& val)
{
  AUTONAMES0("EntireColumn")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Range::GetEntireRow()
{
  AUTONAMES0("EntireRow")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Range::SetEntireRow(TAutoVal& val)
{
  AUTONAMES0("EntireRow")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Range::GetFont()
{
  AUTONAMES0("Font")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Range::SetFont(TAutoVal& val)
{
  AUTONAMES0("Font")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Range::GetFormula()
{
  AUTONAMES0("Formula")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Range::SetFormula(TAutoVal& val)
{
  AUTONAMES0("Formula")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Range::GetFormulaArray()
{
  AUTONAMES0("FormulaArray")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Range::SetFormulaArray(TAutoVal& val)
{
  AUTONAMES0("FormulaArray")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Range::GetFormulaHidden()
{
  AUTONAMES0("FormulaHidden")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Range::SetFormulaHidden(TAutoVal& val)
{
  AUTONAMES0("FormulaHidden")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Range::GetFormulaLocal()
{
  AUTONAMES0("FormulaLocal")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Range::SetFormulaLocal(TAutoVal& val)
{
  AUTONAMES0("FormulaLocal")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Range::GetFormulaR1C1()
{
  AUTONAMES0("FormulaR1C1")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Range::SetFormulaR1C1(TAutoVal& val)
{
  AUTONAMES0("FormulaR1C1")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Range::GetFormulaR1C1Local()
{
  AUTONAMES0("FormulaR1C1Local")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Range::SetFormulaR1C1Local(TAutoVal& val)
{
  AUTONAMES0("FormulaR1C1Local")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Range::GetHasArray()
{
  AUTONAMES0("HasArray")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Range::SetHasArray(TAutoVal& val)
{
  AUTONAMES0("HasArray")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Range::GetHasFormula()
{
  AUTONAMES0("HasFormula")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Range::SetHasFormula(TAutoVal& val)
{
  AUTONAMES0("HasFormula")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Range::GetHeight()
{
  AUTONAMES0("Height")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Range::SetHeight(TAutoVal& val)
{
  AUTONAMES0("Height")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Range::GetHidden()
{
  AUTONAMES0("Hidden")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Range::SetHidden(TAutoVal& val)
{
  AUTONAMES0("Hidden")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Range::GetHorizontalAlignment()
{
  AUTONAMES0("HorizontalAlignment")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Range::SetHorizontalAlignment(TAutoVal& val)
{
  AUTONAMES0("HorizontalAlignment")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Range::GetInterior()
{
  AUTONAMES0("Interior")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Range::SetInterior(TAutoVal& val)
{
  AUTONAMES0("Interior")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Range::GetLeft()
{
  AUTONAMES0("Left")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Range::SetLeft(TAutoVal& val)
{
  AUTONAMES0("Left")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Range::GetListHeaderRows()
{
  AUTONAMES0("ListHeaderRows")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Range::SetListHeaderRows(TAutoVal& val)
{
  AUTONAMES0("ListHeaderRows")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Range::GetLocationInTable()
{
  AUTONAMES0("LocationInTable")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Range::SetLocationInTable(TAutoVal& val)
{
  AUTONAMES0("LocationInTable")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Range::GetLocked()
{
  AUTONAMES0("Locked")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Range::SetLocked(TAutoVal& val)
{
  AUTONAMES0("Locked")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Range::GetName()
{
  AUTONAMES0("Name")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Range::SetName(TAutoVal& val)
{
  AUTONAMES0("Name")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Range::GetNext()
{
  AUTONAMES0("Next")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Range::SetNext(TAutoVal& val)
{
  AUTONAMES0("Next")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Range::GetNumberFormat()
{
  AUTONAMES0("NumberFormat")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Range::SetNumberFormat(TAutoVal& val)
{
  AUTONAMES0("NumberFormat")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Range::GetNumberFormatLocal()
{
  AUTONAMES0("NumberFormatLocal")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Range::SetNumberFormatLocal(TAutoVal& val)
{
  AUTONAMES0("NumberFormatLocal")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Range::GetOrientation()
{
  AUTONAMES0("Orientation")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Range::SetOrientation(TAutoVal& val)
{
  AUTONAMES0("Orientation")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Range::GetOutlineLevel()
{
  AUTONAMES0("OutlineLevel")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Range::SetOutlineLevel(TAutoVal& val)
{
  AUTONAMES0("OutlineLevel")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Range::GetPageBreak()
{
  AUTONAMES0("PageBreak")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Range::SetPageBreak(TAutoVal& val)
{
  AUTONAMES0("PageBreak")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Range::GetParent()
{
  AUTONAMES0("Parent")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Range::SetParent(TAutoVal& val)
{
  AUTONAMES0("Parent")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Range::GetPivotField()
{
  AUTONAMES0("PivotField")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Range::SetPivotField(TAutoVal& val)
{
  AUTONAMES0("PivotField")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Range::GetPivotItem()
{
  AUTONAMES0("PivotItem")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Range::SetPivotItem(TAutoVal& val)
{
  AUTONAMES0("PivotItem")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Range::GetPivotTable()
{
  AUTONAMES0("PivotTable")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Range::SetPivotTable(TAutoVal& val)
{
  AUTONAMES0("PivotTable")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Range::GetPrecedents()
{
  AUTONAMES0("Precedents")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Range::SetPrecedents(TAutoVal& val)
{
  AUTONAMES0("Precedents")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Range::GetPrefixCharacter()
{
  AUTONAMES0("PrefixCharacter")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Range::SetPrefixCharacter(TAutoVal& val)
{
  AUTONAMES0("PrefixCharacter")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Range::GetPrevious()
{
  AUTONAMES0("Previous")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Range::SetPrevious(TAutoVal& val)
{
  AUTONAMES0("Previous")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Range::GetRow()
{
  AUTONAMES0("Row")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Range::SetRow(TAutoVal& val)
{
  AUTONAMES0("Row")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Range::GetRowHeight()
{
  AUTONAMES0("RowHeight")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Range::SetRowHeight(TAutoVal& val)
{
  AUTONAMES0("RowHeight")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Range::GetShowDetail()
{
  AUTONAMES0("ShowDetail")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Range::SetShowDetail(TAutoVal& val)
{
  AUTONAMES0("ShowDetail")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Range::GetSoundNote()
{
  AUTONAMES0("SoundNote")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Range::SetSoundNote(TAutoVal& val)
{
  AUTONAMES0("SoundNote")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Range::GetStyle()
{
  AUTONAMES0("Style")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Range::SetStyle(TAutoVal& val)
{
  AUTONAMES0("Style")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Range::GetSummary()
{
  AUTONAMES0("Summary")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Range::SetSummary(TAutoVal& val)
{
  AUTONAMES0("Summary")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Range::GetText()
{
  AUTONAMES0("Text")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Range::SetText(TAutoVal& val)
{
  AUTONAMES0("Text")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Range::GetTop()
{
  AUTONAMES0("Top")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Range::SetTop(TAutoVal& val)
{
  AUTONAMES0("Top")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Range::GetUseStandardHeight()
{
  AUTONAMES0("UseStandardHeight")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Range::SetUseStandardHeight(TAutoVal& val)
{
  AUTONAMES0("UseStandardHeight")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Range::GetUseStandardWidth()
{
  AUTONAMES0("UseStandardWidth")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Range::SetUseStandardWidth(TAutoVal& val)
{
  AUTONAMES0("UseStandardWidth")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Range::GetValue()
{
  AUTONAMES0("Value")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Range::SetValue(TAutoVal& val)
{
  AUTONAMES0("Value")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Range::GetVerticalAlignment()
{
  AUTONAMES0("VerticalAlignment")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Range::SetVerticalAlignment(TAutoVal& val)
{
  AUTONAMES0("VerticalAlignment")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Range::GetWidth()
{
  AUTONAMES0("Width")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Range::SetWidth(TAutoVal& val)
{
  AUTONAMES0("Width")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Range::GetWrapText()
{
  AUTONAMES0("WrapText")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Range::SetWrapText(TAutoVal& val)
{
  AUTONAMES0("WrapText")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Range::_Dummy(TAutoVal& Activate, TAutoVal& DirectObject)
{
  AUTONAMES0("_Dummy")
  AUTOARGS2(Activate, DirectObject)
  AUTOCALL_METHOD_RET
}

TAutoVal Range::_NewEnum()
{
  AUTONAMES0("_NewEnum")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Range::Activate()
{
  AUTONAMES0("Activate")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Range::Address(TAutoVal& RowAbsolute, TAutoVal& ColumnAbsolute, TAutoVal& ReferenceStyle, TAutoVal& External, TAutoVal& RelativeTo)
{
  AUTONAMES0("Address")
  AUTOARGS5(RowAbsolute, ColumnAbsolute, ReferenceStyle, External, RelativeTo)
  AUTOCALL_METHOD_RET
}

TAutoVal Range::AddressLocal(TAutoVal& RowAbsolute, TAutoVal& ColumnAbsolute, TAutoVal& ReferenceStyle, TAutoVal& External, TAutoVal& RelativeTo)
{
  AUTONAMES0("AddressLocal")
  AUTOARGS5(RowAbsolute, ColumnAbsolute, ReferenceStyle, External, RelativeTo)
  AUTOCALL_METHOD_RET
}

TAutoVal Range::AdvancedFilter(TAutoVal& Action, TAutoVal& CriteriaRange, TAutoVal& CopyToRange, TAutoVal& Unique)
{
  AUTONAMES0("AdvancedFilter")
  AUTOARGS4(Action, CriteriaRange, CopyToRange, Unique)
  AUTOCALL_METHOD_RET
}

TAutoVal Range::Application()
{
  AUTONAMES0("Application")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Range::ApplyNames(TAutoVal& Names, TAutoVal& IgnoreRelativeAbsolute, TAutoVal& UseRowColumnNames, TAutoVal& OmitColumn, TAutoVal& OmitRow, TAutoVal& Order, TAutoVal& AppendLast)
{
  AUTONAMES0("ApplyNames")
  AUTOARGS7(Names, IgnoreRelativeAbsolute, UseRowColumnNames, OmitColumn, OmitRow, Order, AppendLast)
  AUTOCALL_METHOD_RET
}

TAutoVal Range::ApplyOutlineStyles()
{
  AUTONAMES0("ApplyOutlineStyles")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Range::Areas(TAutoVal& Index)
{
  AUTONAMES0("Areas")
  AUTOARGS1(Index)
  AUTOCALL_METHOD_RET
}

TAutoVal Range::AutoComplete(TAutoVal& String)
{
  AUTONAMES0("AutoComplete")
  AUTOARGS1(String)
  AUTOCALL_METHOD_RET
}

TAutoVal Range::AutoFill(TAutoVal& Destination, TAutoVal& Type)
{
  AUTONAMES0("AutoFill")
  AUTOARGS2(Destination, Type)
  AUTOCALL_METHOD_RET
}

TAutoVal Range::AutoFilter(TAutoVal& Field, TAutoVal& Criteria1, TAutoVal& Operator, TAutoVal& Criteria2)
{
  AUTONAMES0("AutoFilter")
  AUTOARGS4(Field, Criteria1, Operator, Criteria2)
  AUTOCALL_METHOD_RET
}

TAutoVal Range::AutoFit()
{
  AUTONAMES0("AutoFit")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Range::AutoFormat(TAutoVal& Format, TAutoVal& Number, TAutoVal& Font, TAutoVal& Alignment, TAutoVal& Border, TAutoVal& Pattern, TAutoVal& Width)
{
  AUTONAMES0("AutoFormat")
  AUTOARGS7(Format, Number, Font, Alignment, Border, Pattern, Width)
  AUTOCALL_METHOD_RET
}

TAutoVal Range::AutoOutline()
{
  AUTONAMES0("AutoOutline")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Range::BorderAround(TAutoVal& LineStyle, TAutoVal& Weight, TAutoVal& ColorIndex, TAutoVal& Color)
{
  AUTONAMES0("BorderAround")
  AUTOARGS4(LineStyle, Weight, ColorIndex, Color)
  AUTOCALL_METHOD_RET
}

TAutoVal Range::Borders(TAutoVal& Index)
{
  AUTONAMES0("Borders")
  AUTOARGS1(Index)
  AUTOCALL_METHOD_RET
}

TAutoVal Range::Calculate()
{
  AUTONAMES0("Calculate")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Range::Cells(TAutoVal& RowIndex, TAutoVal& ColumnIndex)
{
  AUTONAMES0("Cells")
  AUTOARGS2(RowIndex, ColumnIndex)
  AUTOCALL_METHOD_RET
}

TAutoVal Range::Characters(TAutoVal& Start, TAutoVal& Length)
{
  AUTONAMES0("Characters")
  AUTOARGS2(Start, Length)
  AUTOCALL_METHOD_RET
}

TAutoVal Range::CheckSpelling(TAutoVal& CustomDictionary, TAutoVal& IgnoreUppercase, TAutoVal& AlwaysSuggest)
{
  AUTONAMES0("CheckSpelling")
  AUTOARGS3(CustomDictionary, IgnoreUppercase, AlwaysSuggest)
  AUTOCALL_METHOD_RET
}

TAutoVal Range::Clear()
{
  AUTONAMES0("Clear")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Range::ClearContents()
{
  AUTONAMES0("ClearContents")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Range::ClearFormats()
{
  AUTONAMES0("ClearFormats")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Range::ClearNotes()
{
  AUTONAMES0("ClearNotes")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Range::ClearOutline()
{
  AUTONAMES0("ClearOutline")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Range::ColumnDifferences(TAutoVal& Comparison)
{
  AUTONAMES0("ColumnDifferences")
  AUTOARGS1(Comparison)
  AUTOCALL_METHOD_RET
}

TAutoVal Range::Columns(TAutoVal& Index)
{
  AUTONAMES0("Columns")
  AUTOARGS1(Index)
  AUTOCALL_METHOD_RET
}

TAutoVal Range::Consolidate(TAutoVal& Sources, TAutoVal& Function, TAutoVal& TopRow, TAutoVal& LeftColumn, TAutoVal& CreateLinks)
{
  AUTONAMES0("Consolidate")
  AUTOARGS5(Sources, Function, TopRow, LeftColumn, CreateLinks)
  AUTOCALL_METHOD_RET
}

TAutoVal Range::Copy(TAutoVal& Destination)
{
  AUTONAMES0("Copy")
  AUTOARGS1(Destination)
  AUTOCALL_METHOD_RET
}

TAutoVal Range::CopyFromRecordset(TAutoVal& Data, TAutoVal& MaxRows, TAutoVal& MaxColumns)
{
  AUTONAMES0("CopyFromRecordset")
  AUTOARGS3(Data, MaxRows, MaxColumns)
  AUTOCALL_METHOD_RET
}

TAutoVal Range::CopyPicture(TAutoVal& Appearance, TAutoVal& Format)
{
  AUTONAMES0("CopyPicture")
  AUTOARGS2(Appearance, Format)
  AUTOCALL_METHOD_RET
}

TAutoVal Range::CreateNames(TAutoVal& Top, TAutoVal& Left, TAutoVal& Bottom, TAutoVal& Right)
{
  AUTONAMES0("CreateNames")
  AUTOARGS4(Top, Left, Bottom, Right)
  AUTOCALL_METHOD_RET
}

TAutoVal Range::CreatePublisher(TAutoVal& Edition, TAutoVal& Appearance, TAutoVal& ContainsPICT, TAutoVal& ContainsBIFF, TAutoVal& ContainsRTF, TAutoVal& ContainsVALU)
{
  AUTONAMES0("CreatePublisher")
  AUTOARGS6(Edition, Appearance, ContainsPICT, ContainsBIFF, ContainsRTF, ContainsVALU)
  AUTOCALL_METHOD_RET
}

TAutoVal Range::Cut(TAutoVal& Destination)
{
  AUTONAMES0("Cut")
  AUTOARGS1(Destination)
  AUTOCALL_METHOD_RET
}

TAutoVal Range::DataSeries(TAutoVal& Rowcol, TAutoVal& Type, TAutoVal& Date, TAutoVal& Step, TAutoVal& Stop, TAutoVal& Trend)
{
  AUTONAMES0("DataSeries")
  AUTOARGS6(Rowcol, Type, Date, Step, Stop, Trend)
  AUTOCALL_METHOD_RET
}

TAutoVal Range::Delete(TAutoVal& Shift)
{
  AUTONAMES0("Delete")
  AUTOARGS1(Shift)
  AUTOCALL_METHOD_RET
}

/*
TAutoVal Range::DialogBox()
{
  AUTONAMES0("DialogBox")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}
*/

TAutoVal Range::End(TAutoVal& Direction)
{
  AUTONAMES0("End")
  AUTOARGS1(Direction)
  AUTOCALL_METHOD_RET
}

TAutoVal Range::FillDown()
{
  AUTONAMES0("FillDown")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Range::FillLeft()
{
  AUTONAMES0("FillLeft")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Range::FillRight()
{
  AUTONAMES0("FillRight")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Range::FillUp()
{
  AUTONAMES0("FillUp")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Range::Find(TAutoVal& What, TAutoVal& After, TAutoVal& LookIn, TAutoVal& LookAt, TAutoVal& SearchOrder, TAutoVal& SearchDirection, TAutoVal& MatchCase, TAutoVal& MatchByte)
{
  AUTONAMES0("Find")
  AUTOARGS8(What, After, LookIn, LookAt, SearchOrder, SearchDirection, MatchCase, MatchByte)
  AUTOCALL_METHOD_RET
}

TAutoVal Range::FindNext(TAutoVal& After)
{
  AUTONAMES0("FindNext")
  AUTOARGS1(After)
  AUTOCALL_METHOD_RET
}

TAutoVal Range::FindPrevious(TAutoVal& After)
{
  AUTONAMES0("FindPrevious")
  AUTOARGS1(After)
  AUTOCALL_METHOD_RET
}

TAutoVal Range::FunctionWizard()
{
  AUTONAMES0("FunctionWizard")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Range::GoalSeek(TAutoVal& Goal, TAutoVal& ChangingCell)
{
  AUTONAMES0("GoalSeek")
  AUTOARGS2(Goal, ChangingCell)
  AUTOCALL_METHOD_RET
}

TAutoVal Range::Group(TAutoVal& Start, TAutoVal& End, TAutoVal& By, TAutoVal& Periods)
{
  AUTONAMES0("Group")
  AUTOARGS4(Start, End, By, Periods)
  AUTOCALL_METHOD_RET
}

TAutoVal Range::Insert(TAutoVal& Shift)
{
  AUTONAMES0("Insert")
  AUTOARGS1(Shift)
  AUTOCALL_METHOD_RET
}

TAutoVal Range::Item(TAutoVal& RowIndex, TAutoVal& ColumnIndex)
{
  AUTONAMES0("Item")
  AUTOARGS2(RowIndex, ColumnIndex)
  AUTOCALL_METHOD_RET
}

TAutoVal Range::Justify()
{
  AUTONAMES0("Justify")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Range::ListNames()
{
  AUTONAMES0("ListNames")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Range::NavigateArrow(TAutoVal& TowardPrecedent, TAutoVal& ArrowNumber, TAutoVal& LinkNumber)
{
  AUTONAMES0("NavigateArrow")
  AUTOARGS3(TowardPrecedent, ArrowNumber, LinkNumber)
  AUTOCALL_METHOD_RET
}

TAutoVal Range::NoteText(TAutoVal& Text, TAutoVal& Start, TAutoVal& Length)
{
  AUTONAMES0("NoteText")
  AUTOARGS3(Text, Start, Length)
  AUTOCALL_METHOD_RET
}

TAutoVal Range::Offset(TAutoVal& RowOffset, TAutoVal& ColumnOffset)
{
  AUTONAMES0("Offset")
  AUTOARGS2(RowOffset, ColumnOffset)
  AUTOCALL_METHOD_RET
}

TAutoVal Range::Parse(TAutoVal& ParseLine, TAutoVal& Destination)
{
  AUTONAMES0("Parse")
  AUTOARGS2(ParseLine, Destination)
  AUTOCALL_METHOD_RET
}

TAutoVal Range::PasteSpecial(TAutoVal& Paste, TAutoVal& Operation, TAutoVal& SkipBlanks, TAutoVal& Transpose)
{
  AUTONAMES0("PasteSpecial")
  AUTOARGS4(Paste, Operation, SkipBlanks, Transpose)
  AUTOCALL_METHOD_RET
}

TAutoVal Range::PrintOut(TAutoVal& From, TAutoVal& To, TAutoVal& Copies, TAutoVal& Preview, TAutoVal& ActivePrinter, TAutoVal& PrintToFile, TAutoVal& Collate)
{
  AUTONAMES0("PrintOut")
  AUTOARGS7(From, To, Copies, Preview, ActivePrinter, PrintToFile, Collate)
  AUTOCALL_METHOD_RET
}

TAutoVal Range::PrintPreview()
{
  AUTONAMES0("PrintPreview")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

/*
TAutoVal Range::Range(TAutoVal& Cell1, TAutoVal& Cell2)
{
  AUTONAMES0("Range")
  AUTOARGS2(Cell1, Cell2)
  AUTOCALL_METHOD_RET
}
*/

TAutoVal Range::RemoveSubtotal()
{
  AUTONAMES0("RemoveSubtotal")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Range::Replace(TAutoVal& What, TAutoVal& Replacement, TAutoVal& LookAt, TAutoVal& SearchOrder, TAutoVal& MatchCase, TAutoVal& MatchByte)
{
  AUTONAMES0("Replace")
  AUTOARGS6(What, Replacement, LookAt, SearchOrder, MatchCase, MatchByte)
  AUTOCALL_METHOD_RET
}

TAutoVal Range::Resize(TAutoVal& RowSize, TAutoVal& ColumnSize)
{
  AUTONAMES0("Resize")
  AUTOARGS2(RowSize, ColumnSize)
  AUTOCALL_METHOD_RET
}

TAutoVal Range::RowDifferences(TAutoVal& Comparison)
{
  AUTONAMES0("RowDifferences")
  AUTOARGS1(Comparison)
  AUTOCALL_METHOD_RET
}

TAutoVal Range::Rows(TAutoVal& Index)
{
  AUTONAMES0("Rows")
  AUTOARGS1(Index)
  AUTOCALL_METHOD_RET
}

TAutoVal Range::Run(TAutoVal& Arg1, TAutoVal& Arg2, TAutoVal& Arg3, TAutoVal& Arg4, TAutoVal& Arg5, TAutoVal& Arg6, TAutoVal& Arg7, TAutoVal& Arg8, TAutoVal& Arg9, TAutoVal& Arg10, TAutoVal& Arg11, TAutoVal& Arg12, TAutoVal& Arg13, TAutoVal& Arg14, TAutoVal& Arg15, TAutoVal& Arg16, TAutoVal& Arg17, TAutoVal& Arg18, TAutoVal& Arg19, TAutoVal& Arg20, TAutoVal& Arg21, TAutoVal& Arg22, TAutoVal& Arg23, TAutoVal& Arg24, TAutoVal& Arg25, TAutoVal& Arg26, TAutoVal& Arg27, TAutoVal& Arg28, TAutoVal& Arg29, TAutoVal& Arg30)
{
  AUTONAMES0("Run")
  AUTOARGS30(Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Arg8, Arg9, Arg10, Arg11, Arg12, Arg13, Arg14, Arg15, Arg16, Arg17, Arg18, Arg19, Arg20, Arg21, Arg22, Arg23, Arg24, Arg25, Arg26, Arg27, Arg28, Arg29, Arg30)
  AUTOCALL_METHOD_RET
}

TAutoVal Range::Select()
{
  AUTONAMES0("Select")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Range::Show()
{
  AUTONAMES0("Show")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Range::ShowDependents(TAutoVal& Remove)
{
  AUTONAMES0("ShowDependents")
  AUTOARGS1(Remove)
  AUTOCALL_METHOD_RET
}

TAutoVal Range::ShowErrors()
{
  AUTONAMES0("ShowErrors")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Range::ShowPrecedents(TAutoVal& Remove)
{
  AUTONAMES0("ShowPrecedents")
  AUTOARGS1(Remove)
  AUTOCALL_METHOD_RET
}

TAutoVal Range::Sort(TAutoVal& Key1, TAutoVal& Order1, TAutoVal& Key2, TAutoVal& Type, TAutoVal& Order2, TAutoVal& Key3, TAutoVal& Order3, TAutoVal& Header, TAutoVal& OrderCustom, TAutoVal& MatchCase, TAutoVal& Orientation)
{
  AUTONAMES0("Sort")
  AUTOARGS11(Key1, Order1, Key2, Type, Order2, Key3, Order3, Header, OrderCustom, MatchCase, Orientation)
  AUTOCALL_METHOD_RET
}

TAutoVal Range::SortSpecial(TAutoVal& SortMethod, TAutoVal& Key1, TAutoVal& Order1, TAutoVal& Type, TAutoVal& Key2, TAutoVal& Order2, TAutoVal& Key3, TAutoVal& Order3, TAutoVal& Header, TAutoVal& OrderCustom, TAutoVal& MatchCase, TAutoVal& Orientation)
{
  AUTONAMES0("SortSpecial")
  AUTOARGS12(SortMethod, Key1, Order1, Type, Key2, Order2, Key3, Order3, Header, OrderCustom, MatchCase, Orientation)
  AUTOCALL_METHOD_RET
}

TAutoVal Range::SpecialCells(TAutoVal& Type, TAutoVal& Value)
{
  AUTONAMES0("SpecialCells")
  AUTOARGS2(Type, Value)
  AUTOCALL_METHOD_RET
}

TAutoVal Range::SubscribeTo(TAutoVal& Edition, TAutoVal& Format)
{
  AUTONAMES0("SubscribeTo")
  AUTOARGS2(Edition, Format)
  AUTOCALL_METHOD_RET
}

TAutoVal Range::Subtotal(TAutoVal& GroupBy, TAutoVal& Function, TAutoVal& TotalList, TAutoVal& Replace, TAutoVal& PageBreaks, TAutoVal& SummaryBelowData)
{
  AUTONAMES0("Subtotal")
  AUTOARGS6(GroupBy, Function, TotalList, Replace, PageBreaks, SummaryBelowData)
  AUTOCALL_METHOD_RET
}

TAutoVal Range::Table(TAutoVal& RowInput, TAutoVal& ColumnInput)
{
  AUTONAMES0("Table")
  AUTOARGS2(RowInput, ColumnInput)
  AUTOCALL_METHOD_RET
}

TAutoVal Range::TextToColumns(TAutoVal& Destination, TAutoVal& DataType, TAutoVal& TextQualifier, TAutoVal& ConsecutiveDelimiter, TAutoVal& Tab, TAutoVal& Semicolon, TAutoVal& Comma, TAutoVal& Space, TAutoVal& Other, TAutoVal& OtherChar, TAutoVal& FieldInfo)
{
  AUTONAMES0("TextToColumns")
  AUTOARGS11(Destination, DataType, TextQualifier, ConsecutiveDelimiter, Tab, Semicolon, Comma, Space, Other, OtherChar, FieldInfo)
  AUTOCALL_METHOD_RET
}

TAutoVal Range::Ungroup()
{
  AUTONAMES0("Ungroup")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Range::Worksheet()
{
  AUTONAMES0("Worksheet")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}


// TKIND_DISPATCH: Workbook {00020861-0000-0000-C000-000000000046}\9

TAutoVal Workbook::GetActiveChart()
{
  AUTONAMES0("ActiveChart")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Workbook::SetActiveChart(TAutoVal& val)
{
  AUTONAMES0("ActiveChart")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Workbook::GetActiveSheet()
{
  AUTONAMES0("ActiveSheet")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Workbook::SetActiveSheet(TAutoVal& val)
{
  AUTONAMES0("ActiveSheet")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Workbook::GetAuthor()
{
  AUTONAMES0("Author")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Workbook::SetAuthor(TAutoVal& val)
{
  AUTONAMES0("Author")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Workbook::GetColors()
{
  AUTONAMES0("Colors")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Workbook::SetColors(TAutoVal& val)
{
  AUTONAMES0("Colors")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Workbook::GetComments()
{
  AUTONAMES0("Comments")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Workbook::SetComments(TAutoVal& val)
{
  AUTONAMES0("Comments")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Workbook::GetContainer()
{
  AUTONAMES0("Container")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Workbook::SetContainer(TAutoVal& val)
{
  AUTONAMES0("Container")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Workbook::GetCreateBackup()
{
  AUTONAMES0("CreateBackup")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Workbook::SetCreateBackup(TAutoVal& val)
{
  AUTONAMES0("CreateBackup")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Workbook::GetCreator()
{
  AUTONAMES0("Creator")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Workbook::SetCreator(TAutoVal& val)
{
  AUTONAMES0("Creator")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Workbook::GetDate1904()
{
  AUTONAMES0("Date1904")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Workbook::SetDate1904(TAutoVal& val)
{
  AUTONAMES0("Date1904")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Workbook::GetDisplayDrawingObjects()
{
  AUTONAMES0("DisplayDrawingObjects")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Workbook::SetDisplayDrawingObjects(TAutoVal& val)
{
  AUTONAMES0("DisplayDrawingObjects")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Workbook::GetFileFormat()
{
  AUTONAMES0("FileFormat")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Workbook::SetFileFormat(TAutoVal& val)
{
  AUTONAMES0("FileFormat")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Workbook::GetFullName()
{
  AUTONAMES0("FullName")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Workbook::SetFullName(TAutoVal& val)
{
  AUTONAMES0("FullName")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Workbook::GetHasMailer()
{
  AUTONAMES0("HasMailer")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Workbook::SetHasMailer(TAutoVal& val)
{
  AUTONAMES0("HasMailer")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Workbook::GetHasPassword()
{
  AUTONAMES0("HasPassword")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Workbook::SetHasPassword(TAutoVal& val)
{
  AUTONAMES0("HasPassword")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Workbook::GetHasRoutingSlip()
{
  AUTONAMES0("HasRoutingSlip")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Workbook::SetHasRoutingSlip(TAutoVal& val)
{
  AUTONAMES0("HasRoutingSlip")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Workbook::GetKeywords()
{
  AUTONAMES0("Keywords")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Workbook::SetKeywords(TAutoVal& val)
{
  AUTONAMES0("Keywords")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Workbook::GetMailer()
{
  AUTONAMES0("Mailer")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Workbook::SetMailer(TAutoVal& val)
{
  AUTONAMES0("Mailer")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Workbook::GetMultiUserEditing()
{
  AUTONAMES0("MultiUserEditing")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Workbook::SetMultiUserEditing(TAutoVal& val)
{
  AUTONAMES0("MultiUserEditing")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Workbook::GetName()
{
  AUTONAMES0("Name")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Workbook::SetName(TAutoVal& val)
{
  AUTONAMES0("Name")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Workbook::GetOnSave()
{
  AUTONAMES0("OnSave")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Workbook::SetOnSave(TAutoVal& val)
{
  AUTONAMES0("OnSave")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Workbook::GetOnSheetActivate()
{
  AUTONAMES0("OnSheetActivate")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Workbook::SetOnSheetActivate(TAutoVal& val)
{
  AUTONAMES0("OnSheetActivate")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Workbook::GetOnSheetDeactivate()
{
  AUTONAMES0("OnSheetDeactivate")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Workbook::SetOnSheetDeactivate(TAutoVal& val)
{
  AUTONAMES0("OnSheetDeactivate")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Workbook::GetParent()
{
  AUTONAMES0("Parent")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Workbook::SetParent(TAutoVal& val)
{
  AUTONAMES0("Parent")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Workbook::GetPath()
{
  AUTONAMES0("Path")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Workbook::SetPath(TAutoVal& val)
{
  AUTONAMES0("Path")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Workbook::GetPrecisionAsDisplayed()
{
  AUTONAMES0("PrecisionAsDisplayed")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Workbook::SetPrecisionAsDisplayed(TAutoVal& val)
{
  AUTONAMES0("PrecisionAsDisplayed")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Workbook::GetProtectStructure()
{
  AUTONAMES0("ProtectStructure")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Workbook::SetProtectStructure(TAutoVal& val)
{
  AUTONAMES0("ProtectStructure")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Workbook::GetProtectWindows()
{
  AUTONAMES0("ProtectWindows")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Workbook::SetProtectWindows(TAutoVal& val)
{
  AUTONAMES0("ProtectWindows")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Workbook::GetReadOnly()
{
  AUTONAMES0("ReadOnly")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Workbook::SetReadOnly(TAutoVal& val)
{
  AUTONAMES0("ReadOnly")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Workbook::GetReadOnlyRecommended()
{
  AUTONAMES0("ReadOnlyRecommended")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Workbook::SetReadOnlyRecommended(TAutoVal& val)
{
  AUTONAMES0("ReadOnlyRecommended")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Workbook::GetRevisionNumber()
{
  AUTONAMES0("RevisionNumber")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Workbook::SetRevisionNumber(TAutoVal& val)
{
  AUTONAMES0("RevisionNumber")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Workbook::GetRouted()
{
  AUTONAMES0("Routed")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Workbook::SetRouted(TAutoVal& val)
{
  AUTONAMES0("Routed")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Workbook::GetRoutingSlip()
{
  AUTONAMES0("RoutingSlip")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Workbook::SetRoutingSlip(TAutoVal& val)
{
  AUTONAMES0("RoutingSlip")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Workbook::GetSaved()
{
  AUTONAMES0("Saved")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Workbook::SetSaved(TAutoVal& val)
{
  AUTONAMES0("Saved")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Workbook::GetSaveLinkValues()
{
  AUTONAMES0("SaveLinkValues")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Workbook::SetSaveLinkValues(TAutoVal& val)
{
  AUTONAMES0("SaveLinkValues")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Workbook::GetShowConflictHistory()
{
  AUTONAMES0("ShowConflictHistory")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Workbook::SetShowConflictHistory(TAutoVal& val)
{
  AUTONAMES0("ShowConflictHistory")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Workbook::GetSubject()
{
  AUTONAMES0("Subject")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Workbook::SetSubject(TAutoVal& val)
{
  AUTONAMES0("Subject")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Workbook::GetTitle()
{
  AUTONAMES0("Title")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Workbook::SetTitle(TAutoVal& val)
{
  AUTONAMES0("Title")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Workbook::GetUpdateRemoteReferences()
{
  AUTONAMES0("UpdateRemoteReferences")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Workbook::SetUpdateRemoteReferences(TAutoVal& val)
{
  AUTONAMES0("UpdateRemoteReferences")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Workbook::GetUserStatus()
{
  AUTONAMES0("UserStatus")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Workbook::SetUserStatus(TAutoVal& val)
{
  AUTONAMES0("UserStatus")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Workbook::GetWriteReserved()
{
  AUTONAMES0("WriteReserved")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Workbook::SetWriteReserved(TAutoVal& val)
{
  AUTONAMES0("WriteReserved")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Workbook::GetWriteReservedBy()
{
  AUTONAMES0("WriteReservedBy")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Workbook::SetWriteReservedBy(TAutoVal& val)
{
  AUTONAMES0("WriteReservedBy")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Workbook::Activate()
{
  AUTONAMES0("Activate")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Workbook::Application()
{
  AUTONAMES0("Application")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Workbook::BuiltinDocumentProperties(TAutoVal& Index)
{
  AUTONAMES0("BuiltinDocumentProperties")
  AUTOARGS1(Index)
  AUTOCALL_METHOD_RET
}

TAutoVal Workbook::ChangeFileAccess(TAutoVal& Mode, TAutoVal& WritePassword, TAutoVal& Notify)
{
  AUTONAMES0("ChangeFileAccess")
  AUTOARGS3(Mode, WritePassword, Notify)
  AUTOCALL_METHOD_RET
}

TAutoVal Workbook::ChangeLink(TAutoVal& Name, TAutoVal& NewName, TAutoVal& Type)
{
  AUTONAMES0("ChangeLink")
  AUTOARGS3(Name, NewName, Type)
  AUTOCALL_METHOD_RET
}

TAutoVal Workbook::Charts(TAutoVal& Index)
{
  AUTONAMES0("Charts")
  AUTOARGS1(Index)
  AUTOCALL_METHOD_RET
}

TAutoVal Workbook::Close(TAutoVal& SaveChanges, TAutoVal& Filename, TAutoVal& RouteWorkbook)
{
  AUTONAMES0("Close")
  AUTOARGS3(SaveChanges, Filename, RouteWorkbook)
  AUTOCALL_METHOD_RET
}

TAutoVal Workbook::CustomDocumentProperties(TAutoVal& Index)
{
  AUTONAMES0("CustomDocumentProperties")
  AUTOARGS1(Index)
  AUTOCALL_METHOD_RET
}

TAutoVal Workbook::DeleteNumberFormat(TAutoVal& NumberFormat)
{
  AUTONAMES0("DeleteNumberFormat")
  AUTOARGS1(NumberFormat)
  AUTOCALL_METHOD_RET
}

TAutoVal Workbook::DialogSheets(TAutoVal& Index)
{
  AUTONAMES0("DialogSheets")
  AUTOARGS1(Index)
  AUTOCALL_METHOD_RET
}

TAutoVal Workbook::Excel4IntlMacroSheets(TAutoVal& Index)
{
  AUTONAMES0("Excel4IntlMacroSheets")
  AUTOARGS1(Index)
  AUTOCALL_METHOD_RET
}

TAutoVal Workbook::Excel4MacroSheets(TAutoVal& Index)
{
  AUTONAMES0("Excel4MacroSheets")
  AUTOARGS1(Index)
  AUTOCALL_METHOD_RET
}

TAutoVal Workbook::ExclusiveAccess()
{
  AUTONAMES0("ExclusiveAccess")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Workbook::ForwardMailer()
{
  AUTONAMES0("ForwardMailer")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Workbook::LinkInfo(TAutoVal& Name, TAutoVal& LinkInfo, TAutoVal& Type, TAutoVal& EditionRef)
{
  AUTONAMES0("LinkInfo")
  AUTOARGS4(Name, LinkInfo, Type, EditionRef)
  AUTOCALL_METHOD_RET
}

TAutoVal Workbook::LinkSources(TAutoVal& Type)
{
  AUTONAMES0("LinkSources")
  AUTOARGS1(Type)
  AUTOCALL_METHOD_RET
}

TAutoVal Workbook::Modules(TAutoVal& Index)
{
  AUTONAMES0("Modules")
  AUTOARGS1(Index)
  AUTOCALL_METHOD_RET
}

TAutoVal Workbook::Names(TAutoVal& Index, TAutoVal& IndexLocal, TAutoVal& RefersTo)
{
  AUTONAMES0("Names")
  AUTOARGS3(Index, IndexLocal, RefersTo)
  AUTOCALL_METHOD_RET
}

TAutoVal Workbook::NewWindow()
{
  AUTONAMES0("NewWindow")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Workbook::OpenLinks(TAutoVal& Name, TAutoVal& ReadOnly, TAutoVal& Type)
{
  AUTONAMES0("OpenLinks")
  AUTOARGS3(Name, ReadOnly, Type)
  AUTOCALL_METHOD_RET
}

TAutoVal Workbook::Post(TAutoVal& DestName)
{
  AUTONAMES0("Post")
  AUTOARGS1(DestName)
  AUTOCALL_METHOD_RET
}

TAutoVal Workbook::PrintOut(TAutoVal& From, TAutoVal& To, TAutoVal& Copies, TAutoVal& Preview, TAutoVal& ActivePrinter, TAutoVal& PrintToFile, TAutoVal& Collate)
{
  AUTONAMES0("PrintOut")
  AUTOARGS7(From, To, Copies, Preview, ActivePrinter, PrintToFile, Collate)
  AUTOCALL_METHOD_RET
}

TAutoVal Workbook::PrintPreview()
{
  AUTONAMES0("PrintPreview")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Workbook::Protect(TAutoVal& Password, TAutoVal& Structure, TAutoVal& Windows)
{
  AUTONAMES0("Protect")
  AUTOARGS3(Password, Structure, Windows)
  AUTOCALL_METHOD_RET
}

TAutoVal Workbook::Reply()
{
  AUTONAMES0("Reply")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Workbook::ReplyAll()
{
  AUTONAMES0("ReplyAll")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Workbook::Route()
{
  AUTONAMES0("Route")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Workbook::RunAutoMacros(TAutoVal& Which)
{
  AUTONAMES0("RunAutoMacros")
  AUTOARGS1(Which)
  AUTOCALL_METHOD_RET
}

TAutoVal Workbook::Save()
{
  AUTONAMES0("Save")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Workbook::SaveAs(TAutoVal& Filename, TAutoVal& FileFormat, TAutoVal& Password, TAutoVal& WriteResPassword, TAutoVal& ReadOnlyRecommended, TAutoVal& CreateBackup, TAutoVal& AccessMode, TAutoVal& ConflictResolution)
{
  AUTONAMES0("SaveAs")
  AUTOARGS8(Filename, FileFormat, Password, WriteResPassword, ReadOnlyRecommended, CreateBackup, AccessMode, ConflictResolution)
  AUTOCALL_METHOD_RET
}

TAutoVal Workbook::SaveCopyAs(TAutoVal& Filename)
{
  AUTONAMES0("SaveCopyAs")
  AUTOARGS1(Filename)
  AUTOCALL_METHOD_RET
}

TAutoVal Workbook::SendMail(TAutoVal& Recipients, TAutoVal& Subject, TAutoVal& ReturnReceipt)
{
  AUTONAMES0("SendMail")
  AUTOARGS3(Recipients, Subject, ReturnReceipt)
  AUTOCALL_METHOD_RET
}

TAutoVal Workbook::SendMailer(TAutoVal& FileFormat, TAutoVal& Priority)
{
  AUTONAMES0("SendMailer")
  AUTOARGS2(FileFormat, Priority)
  AUTOCALL_METHOD_RET
}

TAutoVal Workbook::SetLinkOnData(TAutoVal& Name, TAutoVal& Procedure)
{
  AUTONAMES0("SetLinkOnData")
  AUTOARGS2(Name, Procedure)
  AUTOCALL_METHOD_RET
}

TAutoVal Workbook::Sheets(TAutoVal& Index)
{
  AUTONAMES0("Sheets")
  AUTOARGS1(Index)
  AUTOCALL_METHOD_RET
}

TAutoVal Workbook::Styles(TAutoVal& Index)
{
  AUTONAMES0("Styles")
  AUTOARGS1(Index)
  AUTOCALL_METHOD_RET
}

TAutoVal Workbook::Unprotect(TAutoVal& Password)
{
  AUTONAMES0("Unprotect")
  AUTOARGS1(Password)
  AUTOCALL_METHOD_RET
}

TAutoVal Workbook::UpdateFromFile()
{
  AUTONAMES0("UpdateFromFile")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Workbook::UpdateLink(TAutoVal& Name, TAutoVal& Type)
{
  AUTONAMES0("UpdateLink")
  AUTOARGS2(Name, Type)
  AUTOCALL_METHOD_RET
}

TAutoVal Workbook::Windows(TAutoVal& Index)
{
  AUTONAMES0("Windows")
  AUTOARGS1(Index)
  AUTOCALL_METHOD_RET
}

TAutoVal Workbook::Worksheets(TAutoVal& Index)
{
  AUTONAMES0("Worksheets")
  AUTOARGS1(Index)
  AUTOCALL_METHOD_RET
}


// TKIND_DISPATCH: Workbooks {00020862-0000-0000-C000-000000000046}\9

TAutoVal Workbooks::GetCount()
{
  AUTONAMES0("Count")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Workbooks::SetCount(TAutoVal& val)
{
  AUTONAMES0("Count")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Workbooks::GetCreator()
{
  AUTONAMES0("Creator")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Workbooks::SetCreator(TAutoVal& val)
{
  AUTONAMES0("Creator")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Workbooks::GetParent()
{
  AUTONAMES0("Parent")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Workbooks::SetParent(TAutoVal& val)
{
  AUTONAMES0("Parent")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Workbooks::_NewEnum()
{
  AUTONAMES0("_NewEnum")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Workbooks::Add(TAutoVal& Template)
{
  AUTONAMES0("Add")
  AUTOARGS1(Template)
  AUTOCALL_METHOD_RET
}

TAutoVal Workbooks::Application()
{
  AUTONAMES0("Application")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Workbooks::Close()
{
  AUTONAMES0("Close")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Workbooks::Item(TAutoVal& Index)
{
  AUTONAMES0("Item")
  AUTOARGS1(Index)
  AUTOCALL_METHOD_RET
}

TAutoVal Workbooks::Open(TAutoVal& Filename, TAutoVal& UpdateLinks, TAutoVal& ReadOnly, TAutoVal& Format, TAutoVal& Password, TAutoVal& WriteResPassword, TAutoVal& IgnoreReadOnlyRecommended, TAutoVal& Origin, TAutoVal& Delimiter, TAutoVal& Editable, TAutoVal& Notify, TAutoVal& Converter)
{
  AUTONAMES0("Open")
  AUTOARGS12(Filename, UpdateLinks, ReadOnly, Format, Password, WriteResPassword, IgnoreReadOnlyRecommended, Origin, Delimiter, Editable, Notify, Converter)
  AUTOCALL_METHOD_RET
}

TAutoVal Workbooks::OpenText(TAutoVal& Filename, TAutoVal& Origin, TAutoVal& StartRow, TAutoVal& DataType, TAutoVal& TextQualifier, TAutoVal& ConsecutiveDelimiter, TAutoVal& Tab, TAutoVal& Semicolon, TAutoVal& Comma, TAutoVal& Space, TAutoVal& Other, TAutoVal& OtherChar, TAutoVal& FieldInfo)
{
  AUTONAMES0("OpenText")
  AUTOARGS13(Filename, Origin, StartRow, DataType, TextQualifier, ConsecutiveDelimiter, Tab, Semicolon, Comma, Space, Other, OtherChar, FieldInfo)
  AUTOCALL_METHOD_RET
}


// TKIND_DISPATCH: Sheets {0002084C-0000-0000-C000-000000000046}\9

TAutoVal Sheets::GetCount()
{
  AUTONAMES0("Count")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Sheets::SetCount(TAutoVal& val)
{
  AUTONAMES0("Count")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Sheets::GetCreator()
{
  AUTONAMES0("Creator")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Sheets::SetCreator(TAutoVal& val)
{
  AUTONAMES0("Creator")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Sheets::GetParent()
{
  AUTONAMES0("Parent")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Sheets::SetParent(TAutoVal& val)
{
  AUTONAMES0("Parent")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Sheets::GetVisible()
{
  AUTONAMES0("Visible")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Sheets::SetVisible(TAutoVal& val)
{
  AUTONAMES0("Visible")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Sheets::_NewEnum()
{
  AUTONAMES0("_NewEnum")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Sheets::Add(TAutoVal& Before, TAutoVal& After, TAutoVal& Count, TAutoVal& Type)
{
  AUTONAMES0("Add")
  AUTOARGS4(Before, After, Count, Type)
  AUTOCALL_METHOD_RET
}

TAutoVal Sheets::Application()
{
  AUTONAMES0("Application")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Sheets::Copy(TAutoVal& Before, TAutoVal& After)
{
  AUTONAMES0("Copy")
  AUTOARGS2(Before, After)
  AUTOCALL_METHOD_RET
}

TAutoVal Sheets::Delete()
{
  AUTONAMES0("Delete")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Sheets::FillAcrossSheets(TAutoVal& Range, TAutoVal& Type)
{
  AUTONAMES0("FillAcrossSheets")
  AUTOARGS2(Range, Type)
  AUTOCALL_METHOD_RET
}

TAutoVal Sheets::Item(TAutoVal& Index)
{
  AUTONAMES0("Item")
  AUTOARGS1(Index)
  AUTOCALL_METHOD_RET
}

TAutoVal Sheets::Move(TAutoVal& Before, TAutoVal& After)
{
  AUTONAMES0("Move")
  AUTOARGS2(Before, After)
  AUTOCALL_METHOD_RET
}

TAutoVal Sheets::PrintOut(TAutoVal& From, TAutoVal& To, TAutoVal& Copies, TAutoVal& Preview, TAutoVal& ActivePrinter, TAutoVal& PrintToFile, TAutoVal& Collate)
{
  AUTONAMES0("PrintOut")
  AUTOARGS7(From, To, Copies, Preview, ActivePrinter, PrintToFile, Collate)
  AUTOCALL_METHOD_RET
}

TAutoVal Sheets::PrintPreview()
{
  AUTONAMES0("PrintPreview")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Sheets::Select(TAutoVal& Replace)
{
  AUTONAMES0("Select")
  AUTOARGS1(Replace)
  AUTOCALL_METHOD_RET
}


// TKIND_DISPATCH: Worksheet {00020850-0000-0000-C000-000000000046}\9

TAutoVal Worksheet::GetAutoFilterMode()
{
  AUTONAMES0("AutoFilterMode")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Worksheet::SetAutoFilterMode(TAutoVal& val)
{
  AUTONAMES0("AutoFilterMode")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Worksheet::GetCircularReference()
{
  AUTONAMES0("CircularReference")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Worksheet::SetCircularReference(TAutoVal& val)
{
  AUTONAMES0("CircularReference")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Worksheet::GetConsolidationFunction()
{
  AUTONAMES0("ConsolidationFunction")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Worksheet::SetConsolidationFunction(TAutoVal& val)
{
  AUTONAMES0("ConsolidationFunction")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Worksheet::GetConsolidationOptions()
{
  AUTONAMES0("ConsolidationOptions")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Worksheet::SetConsolidationOptions(TAutoVal& val)
{
  AUTONAMES0("ConsolidationOptions")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Worksheet::GetConsolidationSources()
{
  AUTONAMES0("ConsolidationSources")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Worksheet::SetConsolidationSources(TAutoVal& val)
{
  AUTONAMES0("ConsolidationSources")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Worksheet::GetCreator()
{
  AUTONAMES0("Creator")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Worksheet::SetCreator(TAutoVal& val)
{
  AUTONAMES0("Creator")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Worksheet::GetDisplayAutomaticPageBreaks()
{
  AUTONAMES0("DisplayAutomaticPageBreaks")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Worksheet::SetDisplayAutomaticPageBreaks(TAutoVal& val)
{
  AUTONAMES0("DisplayAutomaticPageBreaks")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Worksheet::GetEnableAutoFilter()
{
  AUTONAMES0("EnableAutoFilter")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Worksheet::SetEnableAutoFilter(TAutoVal& val)
{
  AUTONAMES0("EnableAutoFilter")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Worksheet::GetEnableOutlining()
{
  AUTONAMES0("EnableOutlining")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Worksheet::SetEnableOutlining(TAutoVal& val)
{
  AUTONAMES0("EnableOutlining")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Worksheet::GetEnablePivotTable()
{
  AUTONAMES0("EnablePivotTable")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Worksheet::SetEnablePivotTable(TAutoVal& val)
{
  AUTONAMES0("EnablePivotTable")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Worksheet::GetFilterMode()
{
  AUTONAMES0("FilterMode")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Worksheet::SetFilterMode(TAutoVal& val)
{
  AUTONAMES0("FilterMode")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Worksheet::GetIndex()
{
  AUTONAMES0("Index")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Worksheet::SetIndex(TAutoVal& val)
{
  AUTONAMES0("Index")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Worksheet::GetName()
{
  AUTONAMES0("Name")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Worksheet::SetName(TAutoVal& val)
{
  AUTONAMES0("Name")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Worksheet::GetNext()
{
  AUTONAMES0("Next")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Worksheet::SetNext(TAutoVal& val)
{
  AUTONAMES0("Next")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Worksheet::GetOnCalculate()
{
  AUTONAMES0("OnCalculate")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Worksheet::SetOnCalculate(TAutoVal& val)
{
  AUTONAMES0("OnCalculate")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Worksheet::GetOnData()
{
  AUTONAMES0("OnData")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Worksheet::SetOnData(TAutoVal& val)
{
  AUTONAMES0("OnData")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Worksheet::GetOnDoubleClick()
{
  AUTONAMES0("OnDoubleClick")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Worksheet::SetOnDoubleClick(TAutoVal& val)
{
  AUTONAMES0("OnDoubleClick")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Worksheet::GetOnEntry()
{
  AUTONAMES0("OnEntry")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Worksheet::SetOnEntry(TAutoVal& val)
{
  AUTONAMES0("OnEntry")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Worksheet::GetOnSheetActivate()
{
  AUTONAMES0("OnSheetActivate")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Worksheet::SetOnSheetActivate(TAutoVal& val)
{
  AUTONAMES0("OnSheetActivate")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Worksheet::GetOnSheetDeactivate()
{
  AUTONAMES0("OnSheetDeactivate")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Worksheet::SetOnSheetDeactivate(TAutoVal& val)
{
  AUTONAMES0("OnSheetDeactivate")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Worksheet::GetOutline()
{
  AUTONAMES0("Outline")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Worksheet::SetOutline(TAutoVal& val)
{
  AUTONAMES0("Outline")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Worksheet::GetPageSetup()
{
  AUTONAMES0("PageSetup")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Worksheet::SetPageSetup(TAutoVal& val)
{
  AUTONAMES0("PageSetup")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Worksheet::GetParent()
{
  AUTONAMES0("Parent")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Worksheet::SetParent(TAutoVal& val)
{
  AUTONAMES0("Parent")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Worksheet::GetPrevious()
{
  AUTONAMES0("Previous")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Worksheet::SetPrevious(TAutoVal& val)
{
  AUTONAMES0("Previous")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Worksheet::GetProtectContents()
{
  AUTONAMES0("ProtectContents")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Worksheet::SetProtectContents(TAutoVal& val)
{
  AUTONAMES0("ProtectContents")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Worksheet::GetProtectDrawingObjects()
{
  AUTONAMES0("ProtectDrawingObjects")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Worksheet::SetProtectDrawingObjects(TAutoVal& val)
{
  AUTONAMES0("ProtectDrawingObjects")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Worksheet::GetProtectionMode()
{
  AUTONAMES0("ProtectionMode")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Worksheet::SetProtectionMode(TAutoVal& val)
{
  AUTONAMES0("ProtectionMode")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Worksheet::GetProtectScenarios()
{
  AUTONAMES0("ProtectScenarios")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Worksheet::SetProtectScenarios(TAutoVal& val)
{
  AUTONAMES0("ProtectScenarios")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Worksheet::GetStandardHeight()
{
  AUTONAMES0("StandardHeight")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Worksheet::SetStandardHeight(TAutoVal& val)
{
  AUTONAMES0("StandardHeight")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Worksheet::GetStandardWidth()
{
  AUTONAMES0("StandardWidth")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Worksheet::SetStandardWidth(TAutoVal& val)
{
  AUTONAMES0("StandardWidth")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Worksheet::GetTransitionExpEval()
{
  AUTONAMES0("TransitionExpEval")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Worksheet::SetTransitionExpEval(TAutoVal& val)
{
  AUTONAMES0("TransitionExpEval")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Worksheet::GetTransitionFormEntry()
{
  AUTONAMES0("TransitionFormEntry")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Worksheet::SetTransitionFormEntry(TAutoVal& val)
{
  AUTONAMES0("TransitionFormEntry")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Worksheet::GetType()
{
  AUTONAMES0("Type")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Worksheet::SetType(TAutoVal& val)
{
  AUTONAMES0("Type")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Worksheet::GetUsedRange()
{
  AUTONAMES0("UsedRange")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Worksheet::SetUsedRange(TAutoVal& val)
{
  AUTONAMES0("UsedRange")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Worksheet::GetVisible()
{
  AUTONAMES0("Visible")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Worksheet::SetVisible(TAutoVal& val)
{
  AUTONAMES0("Visible")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Worksheet::Activate()
{
  AUTONAMES0("Activate")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Worksheet::Application()
{
  AUTONAMES0("Application")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Worksheet::Arcs(TAutoVal& Index)
{
  AUTONAMES0("Arcs")
  AUTOARGS1(Index)
  AUTOCALL_METHOD_RET
}

TAutoVal Worksheet::Buttons(TAutoVal& Index)
{
  AUTONAMES0("Buttons")
  AUTOARGS1(Index)
  AUTOCALL_METHOD_RET
}

TAutoVal Worksheet::Calculate()
{
  AUTONAMES0("Calculate")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Worksheet::Cells(TAutoVal& RowIndex, TAutoVal& ColumnIndex)
{
  AUTONAMES0("Cells")
  AUTOARGS2(RowIndex, ColumnIndex)
  AUTOCALL_METHOD_RET
}

TAutoVal Worksheet::ChartObjects(TAutoVal& Index)
{
  AUTONAMES0("ChartObjects")
  AUTOARGS1(Index)
  AUTOCALL_METHOD_RET
}

TAutoVal Worksheet::CheckBoxes(TAutoVal& Index)
{
  AUTONAMES0("CheckBoxes")
  AUTOARGS1(Index)
  AUTOCALL_METHOD_RET
}

TAutoVal Worksheet::CheckSpelling(TAutoVal& CustomDictionary, TAutoVal& IgnoreUppercase, TAutoVal& AlwaysSuggest)
{
  AUTONAMES0("CheckSpelling")
  AUTOARGS3(CustomDictionary, IgnoreUppercase, AlwaysSuggest)
  AUTOCALL_METHOD_RET
}

TAutoVal Worksheet::ClearArrows()
{
  AUTONAMES0("ClearArrows")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Worksheet::Columns(TAutoVal& Index)
{
  AUTONAMES0("Columns")
  AUTOARGS1(Index)
  AUTOCALL_METHOD_RET
}

TAutoVal Worksheet::Copy(TAutoVal& Before, TAutoVal& After)
{
  AUTONAMES0("Copy")
  AUTOARGS2(Before, After)
  AUTOCALL_METHOD_RET
}

TAutoVal Worksheet::Delete()
{
  AUTONAMES0("Delete")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Worksheet::DrawingObjects(TAutoVal& Index)
{
  AUTONAMES0("DrawingObjects")
  AUTOARGS1(Index)
  AUTOCALL_METHOD_RET
}

TAutoVal Worksheet::Drawings(TAutoVal& Index)
{
  AUTONAMES0("Drawings")
  AUTOARGS1(Index)
  AUTOCALL_METHOD_RET
}

TAutoVal Worksheet::DropDowns(TAutoVal& Index)
{
  AUTONAMES0("DropDowns")
  AUTOARGS1(Index)
  AUTOCALL_METHOD_RET
}

TAutoVal Worksheet::_Evaluate(TAutoVal& Name)
{
  AUTONAMES0("_Evaluate")
  AUTOARGS1(Name)
  AUTOCALL_METHOD_RET
}

TAutoVal Worksheet::Evaluate(TAutoVal& Name)
{
  AUTONAMES0("Evaluate")
  AUTOARGS1(Name)
  AUTOCALL_METHOD_RET
}

TAutoVal Worksheet::GroupBoxes(TAutoVal& Index)
{
  AUTONAMES0("GroupBoxes")
  AUTOARGS1(Index)
  AUTOCALL_METHOD_RET
}

TAutoVal Worksheet::GroupObjects(TAutoVal& Index)
{
  AUTONAMES0("GroupObjects")
  AUTOARGS1(Index)
  AUTOCALL_METHOD_RET
}

TAutoVal Worksheet::Labels(TAutoVal& Index)
{
  AUTONAMES0("Labels")
  AUTOARGS1(Index)
  AUTOCALL_METHOD_RET
}

TAutoVal Worksheet::Lines(TAutoVal& Index)
{
  AUTONAMES0("Lines")
  AUTOARGS1(Index)
  AUTOCALL_METHOD_RET
}

TAutoVal Worksheet::ListBoxes(TAutoVal& Index)
{
  AUTONAMES0("ListBoxes")
  AUTOARGS1(Index)
  AUTOCALL_METHOD_RET
}

TAutoVal Worksheet::Move(TAutoVal& Before, TAutoVal& After)
{
  AUTONAMES0("Move")
  AUTOARGS2(Before, After)
  AUTOCALL_METHOD_RET
}

TAutoVal Worksheet::Names(TAutoVal& Index, TAutoVal& IndexLocal, TAutoVal& RefersTo)
{
  AUTONAMES0("Names")
  AUTOARGS3(Index, IndexLocal, RefersTo)
  AUTOCALL_METHOD_RET
}

TAutoVal Worksheet::OLEObjects(TAutoVal& Index)
{
  AUTONAMES0("OLEObjects")
  AUTOARGS1(Index)
  AUTOCALL_METHOD_RET
}

TAutoVal Worksheet::OptionButtons(TAutoVal& Index)
{
  AUTONAMES0("OptionButtons")
  AUTOARGS1(Index)
  AUTOCALL_METHOD_RET
}

TAutoVal Worksheet::Ovals(TAutoVal& Index)
{
  AUTONAMES0("Ovals")
  AUTOARGS1(Index)
  AUTOCALL_METHOD_RET
}

TAutoVal Worksheet::Paste(TAutoVal& Destination, TAutoVal& Link)
{
  AUTONAMES0("Paste")
  AUTOARGS2(Destination, Link)
  AUTOCALL_METHOD_RET
}

TAutoVal Worksheet::PasteSpecial(TAutoVal& Format, TAutoVal& Link, TAutoVal& DisplayAsIcon, TAutoVal& IconFileName, TAutoVal& IconIndex, TAutoVal& IconLabel)
{
  AUTONAMES0("PasteSpecial")
  AUTOARGS6(Format, Link, DisplayAsIcon, IconFileName, IconIndex, IconLabel)
  AUTOCALL_METHOD_RET
}

TAutoVal Worksheet::Pictures(TAutoVal& Index)
{
  AUTONAMES0("Pictures")
  AUTOARGS1(Index)
  AUTOCALL_METHOD_RET
}

TAutoVal Worksheet::PivotTables(TAutoVal& Index)
{
  AUTONAMES0("PivotTables")
  AUTOARGS1(Index)
  AUTOCALL_METHOD_RET
}

TAutoVal Worksheet::PivotTableWizard(TAutoVal& SourceType, TAutoVal& SourceData, TAutoVal& TableDestination, TAutoVal& TableName, TAutoVal& RowGrand, TAutoVal& ColumnGrand, TAutoVal& SaveData, TAutoVal& HasAutoFormat, TAutoVal& AutoPage, TAutoVal& Reserved)
{
  AUTONAMES0("PivotTableWizard")
  AUTOARGS10(SourceType, SourceData, TableDestination, TableName, RowGrand, ColumnGrand, SaveData, HasAutoFormat, AutoPage, Reserved)
  AUTOCALL_METHOD_RET
}

TAutoVal Worksheet::PrintOut(TAutoVal& From, TAutoVal& To, TAutoVal& Copies, TAutoVal& Preview, TAutoVal& ActivePrinter, TAutoVal& PrintToFile, TAutoVal& Collate)
{
  AUTONAMES0("PrintOut")
  AUTOARGS7(From, To, Copies, Preview, ActivePrinter, PrintToFile, Collate)
  AUTOCALL_METHOD_RET
}

TAutoVal Worksheet::PrintPreview()
{
  AUTONAMES0("PrintPreview")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Worksheet::Protect(TAutoVal& Password, TAutoVal& DrawingObjects, TAutoVal& Contents, TAutoVal& Scenarios, TAutoVal& UserInterfaceOnly)
{
  AUTONAMES0("Protect")
  AUTOARGS5(Password, DrawingObjects, Contents, Scenarios, UserInterfaceOnly)
  AUTOCALL_METHOD_RET
}

TAutoVal Worksheet::Range(TAutoVal& Cell1, TAutoVal& Cell2)
{
  AUTONAMES0("Range")
  AUTOARGS2(Cell1, Cell2)
  AUTOCALL_METHOD_RET
}

TAutoVal Worksheet::Rectangles(TAutoVal& Index)
{
  AUTONAMES0("Rectangles")
  AUTOARGS1(Index)
  AUTOCALL_METHOD_RET
}

TAutoVal Worksheet::Rows(TAutoVal& Index)
{
  AUTONAMES0("Rows")
  AUTOARGS1(Index)
  AUTOCALL_METHOD_RET
}

TAutoVal Worksheet::SaveAs(TAutoVal& Filename, TAutoVal& FileFormat, TAutoVal& Password, TAutoVal& WriteResPassword, TAutoVal& ReadOnlyRecommended, TAutoVal& CreateBackup)
{
  AUTONAMES0("SaveAs")
  AUTOARGS6(Filename, FileFormat, Password, WriteResPassword, ReadOnlyRecommended, CreateBackup)
  AUTOCALL_METHOD_RET
}

TAutoVal Worksheet::Scenarios(TAutoVal& Index)
{
  AUTONAMES0("Scenarios")
  AUTOARGS1(Index)
  AUTOCALL_METHOD_RET
}

TAutoVal Worksheet::ScrollBars(TAutoVal& Index)
{
  AUTONAMES0("ScrollBars")
  AUTOARGS1(Index)
  AUTOCALL_METHOD_RET
}

TAutoVal Worksheet::Select(TAutoVal& Replace)
{
  AUTONAMES0("Select")
  AUTOARGS1(Replace)
  AUTOCALL_METHOD_RET
}

TAutoVal Worksheet::SetBackgroundPicture(TAutoVal& Filename)
{
  AUTONAMES0("SetBackgroundPicture")
  AUTOARGS1(Filename)
  AUTOCALL_METHOD_RET
}

TAutoVal Worksheet::ShowAllData()
{
  AUTONAMES0("ShowAllData")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Worksheet::ShowDataForm()
{
  AUTONAMES0("ShowDataForm")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Worksheet::Spinners(TAutoVal& Index)
{
  AUTONAMES0("Spinners")
  AUTOARGS1(Index)
  AUTOCALL_METHOD_RET
}

TAutoVal Worksheet::TextBoxes(TAutoVal& Index)
{
  AUTONAMES0("TextBoxes")
  AUTOARGS1(Index)
  AUTOCALL_METHOD_RET
}

TAutoVal Worksheet::Unprotect(TAutoVal& Password)
{
  AUTONAMES0("Unprotect")
  AUTOARGS1(Password)
  AUTOCALL_METHOD_RET
}


// TKIND_DISPATCH: Worksheets {000209B1-0000-0000-C000-000000000046}\9

TAutoVal Worksheets::GetCount()
{
  AUTONAMES0("Count")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Worksheets::SetCount(TAutoVal& val)
{
  AUTONAMES0("Count")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Worksheets::GetCreator()
{
  AUTONAMES0("Creator")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Worksheets::SetCreator(TAutoVal& val)
{
  AUTONAMES0("Creator")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Worksheets::GetParent()
{
  AUTONAMES0("Parent")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Worksheets::SetParent(TAutoVal& val)
{
  AUTONAMES0("Parent")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Worksheets::GetVisible()
{
  AUTONAMES0("Visible")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Worksheets::SetVisible(TAutoVal& val)
{
  AUTONAMES0("Visible")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Worksheets::_NewEnum()
{
  AUTONAMES0("_NewEnum")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Worksheets::Add(TAutoVal& Before, TAutoVal& After, TAutoVal& Count, TAutoVal& Type)
{
  AUTONAMES0("Add")
  AUTOARGS4(Before, After, Count, Type)
  AUTOCALL_METHOD_RET
}

TAutoVal Worksheets::Application()
{
  AUTONAMES0("Application")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Worksheets::Copy(TAutoVal& Before, TAutoVal& After)
{
  AUTONAMES0("Copy")
  AUTOARGS2(Before, After)
  AUTOCALL_METHOD_RET
}

TAutoVal Worksheets::Delete()
{
  AUTONAMES0("Delete")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Worksheets::FillAcrossSheets(TAutoVal& Range, TAutoVal& Type)
{
  AUTONAMES0("FillAcrossSheets")
  AUTOARGS2(Range, Type)
  AUTOCALL_METHOD_RET
}

TAutoVal Worksheets::Item(TAutoVal& Index)
{
  AUTONAMES0("Item")
  AUTOARGS1(Index)
  AUTOCALL_METHOD_RET
}

TAutoVal Worksheets::Move(TAutoVal& Before, TAutoVal& After)
{
  AUTONAMES0("Move")
  AUTOARGS2(Before, After)
  AUTOCALL_METHOD_RET
}

TAutoVal Worksheets::PrintOut(TAutoVal& From, TAutoVal& To, TAutoVal& Copies, TAutoVal& Preview, TAutoVal& ActivePrinter, TAutoVal& PrintToFile, TAutoVal& Collate)
{
  AUTONAMES0("PrintOut")
  AUTOARGS7(From, To, Copies, Preview, ActivePrinter, PrintToFile, Collate)
  AUTOCALL_METHOD_RET
}

TAutoVal Worksheets::PrintPreview()
{
  AUTONAMES0("PrintPreview")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Worksheets::Select(TAutoVal& Replace)
{
  AUTONAMES0("Select")
  AUTOARGS1(Replace)
  AUTOCALL_METHOD_RET
}


// TKIND_DISPATCH: PivotTable {00020872-0000-0000-C000-000000000046}\9

TAutoVal PivotTable::GetColumnFields()
{
  AUTONAMES0("ColumnFields")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void PivotTable::SetColumnFields(TAutoVal& val)
{
  AUTONAMES0("ColumnFields")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal PivotTable::GetColumnGrand()
{
  AUTONAMES0("ColumnGrand")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void PivotTable::SetColumnGrand(TAutoVal& val)
{
  AUTONAMES0("ColumnGrand")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal PivotTable::GetColumnRange()
{
  AUTONAMES0("ColumnRange")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void PivotTable::SetColumnRange(TAutoVal& val)
{
  AUTONAMES0("ColumnRange")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal PivotTable::GetCreator()
{
  AUTONAMES0("Creator")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void PivotTable::SetCreator(TAutoVal& val)
{
  AUTONAMES0("Creator")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal PivotTable::GetDataBodyRange()
{
  AUTONAMES0("DataBodyRange")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void PivotTable::SetDataBodyRange(TAutoVal& val)
{
  AUTONAMES0("DataBodyRange")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal PivotTable::GetDataFields()
{
  AUTONAMES0("DataFields")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void PivotTable::SetDataFields(TAutoVal& val)
{
  AUTONAMES0("DataFields")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal PivotTable::GetDataLabelRange()
{
  AUTONAMES0("DataLabelRange")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void PivotTable::SetDataLabelRange(TAutoVal& val)
{
  AUTONAMES0("DataLabelRange")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal PivotTable::GetHasAutoFormat()
{
  AUTONAMES0("HasAutoFormat")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void PivotTable::SetHasAutoFormat(TAutoVal& val)
{
  AUTONAMES0("HasAutoFormat")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal PivotTable::GetHiddenFields()
{
  AUTONAMES0("HiddenFields")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void PivotTable::SetHiddenFields(TAutoVal& val)
{
  AUTONAMES0("HiddenFields")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal PivotTable::GetInnerDetail()
{
  AUTONAMES0("InnerDetail")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void PivotTable::SetInnerDetail(TAutoVal& val)
{
  AUTONAMES0("InnerDetail")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal PivotTable::GetName()
{
  AUTONAMES0("Name")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void PivotTable::SetName(TAutoVal& val)
{
  AUTONAMES0("Name")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal PivotTable::GetPageFields()
{
  AUTONAMES0("PageFields")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void PivotTable::SetPageFields(TAutoVal& val)
{
  AUTONAMES0("PageFields")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal PivotTable::GetPageRange()
{
  AUTONAMES0("PageRange")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void PivotTable::SetPageRange(TAutoVal& val)
{
  AUTONAMES0("PageRange")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal PivotTable::GetParent()
{
  AUTONAMES0("Parent")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void PivotTable::SetParent(TAutoVal& val)
{
  AUTONAMES0("Parent")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal PivotTable::GetRefreshDate()
{
  AUTONAMES0("RefreshDate")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void PivotTable::SetRefreshDate(TAutoVal& val)
{
  AUTONAMES0("RefreshDate")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal PivotTable::GetRefreshName()
{
  AUTONAMES0("RefreshName")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void PivotTable::SetRefreshName(TAutoVal& val)
{
  AUTONAMES0("RefreshName")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal PivotTable::GetRowFields()
{
  AUTONAMES0("RowFields")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void PivotTable::SetRowFields(TAutoVal& val)
{
  AUTONAMES0("RowFields")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal PivotTable::GetRowGrand()
{
  AUTONAMES0("RowGrand")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void PivotTable::SetRowGrand(TAutoVal& val)
{
  AUTONAMES0("RowGrand")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal PivotTable::GetRowRange()
{
  AUTONAMES0("RowRange")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void PivotTable::SetRowRange(TAutoVal& val)
{
  AUTONAMES0("RowRange")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal PivotTable::GetSaveData()
{
  AUTONAMES0("SaveData")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void PivotTable::SetSaveData(TAutoVal& val)
{
  AUTONAMES0("SaveData")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal PivotTable::GetSourceData()
{
  AUTONAMES0("SourceData")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void PivotTable::SetSourceData(TAutoVal& val)
{
  AUTONAMES0("SourceData")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal PivotTable::GetTableRange1()
{
  AUTONAMES0("TableRange1")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void PivotTable::SetTableRange1(TAutoVal& val)
{
  AUTONAMES0("TableRange1")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal PivotTable::GetTableRange2()
{
  AUTONAMES0("TableRange2")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void PivotTable::SetTableRange2(TAutoVal& val)
{
  AUTONAMES0("TableRange2")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal PivotTable::GetValue()
{
  AUTONAMES0("Value")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void PivotTable::SetValue(TAutoVal& val)
{
  AUTONAMES0("Value")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal PivotTable::GetVisibleFields()
{
  AUTONAMES0("VisibleFields")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void PivotTable::SetVisibleFields(TAutoVal& val)
{
  AUTONAMES0("VisibleFields")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal PivotTable::AddFields(TAutoVal& RowFields, TAutoVal& ColumnFields, TAutoVal& PageFields, TAutoVal& AddToTable)
{
  AUTONAMES0("AddFields")
  AUTOARGS4(RowFields, ColumnFields, PageFields, AddToTable)
  AUTOCALL_METHOD_RET
}

TAutoVal PivotTable::Application()
{
  AUTONAMES0("Application")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal PivotTable::PivotFields(TAutoVal& Index)
{
  AUTONAMES0("PivotFields")
  AUTOARGS1(Index)
  AUTOCALL_METHOD_RET
}

TAutoVal PivotTable::RefreshTable()
{
  AUTONAMES0("RefreshTable")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal PivotTable::ShowPages(TAutoVal& PageField)
{
  AUTONAMES0("ShowPages")
  AUTOARGS1(PageField)
  AUTOCALL_METHOD_RET
}


// TKIND_DISPATCH: PivotTables {00020873-0000-0000-C000-000000000046}\9

TAutoVal PivotTables::GetCount()
{
  AUTONAMES0("Count")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void PivotTables::SetCount(TAutoVal& val)
{
  AUTONAMES0("Count")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal PivotTables::GetCreator()
{
  AUTONAMES0("Creator")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void PivotTables::SetCreator(TAutoVal& val)
{
  AUTONAMES0("Creator")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal PivotTables::GetParent()
{
  AUTONAMES0("Parent")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void PivotTables::SetParent(TAutoVal& val)
{
  AUTONAMES0("Parent")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal PivotTables::_NewEnum()
{
  AUTONAMES0("_NewEnum")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal PivotTables::Application()
{
  AUTONAMES0("Application")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal PivotTables::Item(TAutoVal& Index)
{
  AUTONAMES0("Item")
  AUTOARGS1(Index)
  AUTOCALL_METHOD_RET
}


// TKIND_DISPATCH: PivotField {00020874-0000-0000-C000-000000000046}\9

TAutoVal PivotField::GetBaseField()
{
  AUTONAMES0("BaseField")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void PivotField::SetBaseField(TAutoVal& val)
{
  AUTONAMES0("BaseField")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal PivotField::GetBaseItem()
{
  AUTONAMES0("BaseItem")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void PivotField::SetBaseItem(TAutoVal& val)
{
  AUTONAMES0("BaseItem")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal PivotField::GetCalculation()
{
  AUTONAMES0("Calculation")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void PivotField::SetCalculation(TAutoVal& val)
{
  AUTONAMES0("Calculation")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal PivotField::GetChildField()
{
  AUTONAMES0("ChildField")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void PivotField::SetChildField(TAutoVal& val)
{
  AUTONAMES0("ChildField")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal PivotField::GetChildItems()
{
  AUTONAMES0("ChildItems")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void PivotField::SetChildItems(TAutoVal& val)
{
  AUTONAMES0("ChildItems")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal PivotField::GetCreator()
{
  AUTONAMES0("Creator")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void PivotField::SetCreator(TAutoVal& val)
{
  AUTONAMES0("Creator")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal PivotField::GetCurrentPage()
{
  AUTONAMES0("CurrentPage")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void PivotField::SetCurrentPage(TAutoVal& val)
{
  AUTONAMES0("CurrentPage")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal PivotField::GetDataRange()
{
  AUTONAMES0("DataRange")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void PivotField::SetDataRange(TAutoVal& val)
{
  AUTONAMES0("DataRange")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal PivotField::GetDataType()
{
  AUTONAMES0("DataType")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void PivotField::SetDataType(TAutoVal& val)
{
  AUTONAMES0("DataType")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal PivotField::GetFunction()
{
  AUTONAMES0("Function")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void PivotField::SetFunction(TAutoVal& val)
{
  AUTONAMES0("Function")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal PivotField::GetGroupLevel()
{
  AUTONAMES0("GroupLevel")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void PivotField::SetGroupLevel(TAutoVal& val)
{
  AUTONAMES0("GroupLevel")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal PivotField::GetHiddenItems()
{
  AUTONAMES0("HiddenItems")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void PivotField::SetHiddenItems(TAutoVal& val)
{
  AUTONAMES0("HiddenItems")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal PivotField::GetLabelRange()
{
  AUTONAMES0("LabelRange")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void PivotField::SetLabelRange(TAutoVal& val)
{
  AUTONAMES0("LabelRange")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal PivotField::GetName()
{
  AUTONAMES0("Name")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void PivotField::SetName(TAutoVal& val)
{
  AUTONAMES0("Name")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal PivotField::GetNumberFormat()
{
  AUTONAMES0("NumberFormat")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void PivotField::SetNumberFormat(TAutoVal& val)
{
  AUTONAMES0("NumberFormat")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal PivotField::GetOrientation()
{
  AUTONAMES0("Orientation")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void PivotField::SetOrientation(TAutoVal& val)
{
  AUTONAMES0("Orientation")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal PivotField::GetParent()
{
  AUTONAMES0("Parent")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void PivotField::SetParent(TAutoVal& val)
{
  AUTONAMES0("Parent")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal PivotField::GetParentField()
{
  AUTONAMES0("ParentField")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void PivotField::SetParentField(TAutoVal& val)
{
  AUTONAMES0("ParentField")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal PivotField::GetParentItems()
{
  AUTONAMES0("ParentItems")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void PivotField::SetParentItems(TAutoVal& val)
{
  AUTONAMES0("ParentItems")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal PivotField::GetPosition()
{
  AUTONAMES0("Position")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void PivotField::SetPosition(TAutoVal& val)
{
  AUTONAMES0("Position")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal PivotField::GetSourceName()
{
  AUTONAMES0("SourceName")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void PivotField::SetSourceName(TAutoVal& val)
{
  AUTONAMES0("SourceName")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal PivotField::GetSubtotals()
{
  AUTONAMES0("Subtotals")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void PivotField::SetSubtotals(TAutoVal& val)
{
  AUTONAMES0("Subtotals")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal PivotField::GetTotalLevels()
{
  AUTONAMES0("TotalLevels")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void PivotField::SetTotalLevels(TAutoVal& val)
{
  AUTONAMES0("TotalLevels")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal PivotField::GetValue()
{
  AUTONAMES0("Value")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void PivotField::SetValue(TAutoVal& val)
{
  AUTONAMES0("Value")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal PivotField::GetVisibleItems()
{
  AUTONAMES0("VisibleItems")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void PivotField::SetVisibleItems(TAutoVal& val)
{
  AUTONAMES0("VisibleItems")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal PivotField::Application()
{
  AUTONAMES0("Application")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal PivotField::PivotItems(TAutoVal& Index)
{
  AUTONAMES0("PivotItems")
  AUTOARGS1(Index)
  AUTOCALL_METHOD_RET
}


// TKIND_DISPATCH: PivotFields {00020875-0000-0000-C000-000000000046}\9

TAutoVal PivotFields::GetCount()
{
  AUTONAMES0("Count")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void PivotFields::SetCount(TAutoVal& val)
{
  AUTONAMES0("Count")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal PivotFields::GetCreator()
{
  AUTONAMES0("Creator")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void PivotFields::SetCreator(TAutoVal& val)
{
  AUTONAMES0("Creator")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal PivotFields::GetParent()
{
  AUTONAMES0("Parent")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void PivotFields::SetParent(TAutoVal& val)
{
  AUTONAMES0("Parent")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal PivotFields::_NewEnum()
{
  AUTONAMES0("_NewEnum")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal PivotFields::Application()
{
  AUTONAMES0("Application")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal PivotFields::Item(TAutoVal& Index)
{
  AUTONAMES0("Item")
  AUTOARGS1(Index)
  AUTOCALL_METHOD_RET
}


// TKIND_DISPATCH: PivotItem {00020876-0000-0000-C000-000000000046}\9

TAutoVal PivotItem::GetChildItems()
{
  AUTONAMES0("ChildItems")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void PivotItem::SetChildItems(TAutoVal& val)
{
  AUTONAMES0("ChildItems")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal PivotItem::GetCreator()
{
  AUTONAMES0("Creator")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void PivotItem::SetCreator(TAutoVal& val)
{
  AUTONAMES0("Creator")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal PivotItem::GetDataRange()
{
  AUTONAMES0("DataRange")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void PivotItem::SetDataRange(TAutoVal& val)
{
  AUTONAMES0("DataRange")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal PivotItem::GetLabelRange()
{
  AUTONAMES0("LabelRange")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void PivotItem::SetLabelRange(TAutoVal& val)
{
  AUTONAMES0("LabelRange")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal PivotItem::GetName()
{
  AUTONAMES0("Name")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void PivotItem::SetName(TAutoVal& val)
{
  AUTONAMES0("Name")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal PivotItem::GetParent()
{
  AUTONAMES0("Parent")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void PivotItem::SetParent(TAutoVal& val)
{
  AUTONAMES0("Parent")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal PivotItem::GetParentItem()
{
  AUTONAMES0("ParentItem")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void PivotItem::SetParentItem(TAutoVal& val)
{
  AUTONAMES0("ParentItem")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal PivotItem::GetParentShowDetail()
{
  AUTONAMES0("ParentShowDetail")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void PivotItem::SetParentShowDetail(TAutoVal& val)
{
  AUTONAMES0("ParentShowDetail")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal PivotItem::GetPosition()
{
  AUTONAMES0("Position")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void PivotItem::SetPosition(TAutoVal& val)
{
  AUTONAMES0("Position")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal PivotItem::GetShowDetail()
{
  AUTONAMES0("ShowDetail")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void PivotItem::SetShowDetail(TAutoVal& val)
{
  AUTONAMES0("ShowDetail")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal PivotItem::GetSourceName()
{
  AUTONAMES0("SourceName")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void PivotItem::SetSourceName(TAutoVal& val)
{
  AUTONAMES0("SourceName")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal PivotItem::GetValue()
{
  AUTONAMES0("Value")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void PivotItem::SetValue(TAutoVal& val)
{
  AUTONAMES0("Value")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal PivotItem::GetVisible()
{
  AUTONAMES0("Visible")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void PivotItem::SetVisible(TAutoVal& val)
{
  AUTONAMES0("Visible")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal PivotItem::Application()
{
  AUTONAMES0("Application")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}


// TKIND_DISPATCH: PivotItems {00020877-0000-0000-C000-000000000046}\9

TAutoVal PivotItems::GetCount()
{
  AUTONAMES0("Count")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void PivotItems::SetCount(TAutoVal& val)
{
  AUTONAMES0("Count")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal PivotItems::GetCreator()
{
  AUTONAMES0("Creator")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void PivotItems::SetCreator(TAutoVal& val)
{
  AUTONAMES0("Creator")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal PivotItems::GetParent()
{
  AUTONAMES0("Parent")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void PivotItems::SetParent(TAutoVal& val)
{
  AUTONAMES0("Parent")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal PivotItems::_NewEnum()
{
  AUTONAMES0("_NewEnum")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal PivotItems::Application()
{
  AUTONAMES0("Application")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal PivotItems::Item(TAutoVal& Index)
{
  AUTONAMES0("Item")
  AUTOARGS1(Index)
  AUTOCALL_METHOD_RET
}


// TKIND_DISPATCH: Scenario {00020897-0000-0000-C000-000000000046}\9

TAutoVal Scenario::GetChangingCells()
{
  AUTONAMES0("ChangingCells")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Scenario::SetChangingCells(TAutoVal& val)
{
  AUTONAMES0("ChangingCells")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Scenario::GetComment()
{
  AUTONAMES0("Comment")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Scenario::SetComment(TAutoVal& val)
{
  AUTONAMES0("Comment")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Scenario::GetCreator()
{
  AUTONAMES0("Creator")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Scenario::SetCreator(TAutoVal& val)
{
  AUTONAMES0("Creator")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Scenario::GetHidden()
{
  AUTONAMES0("Hidden")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Scenario::SetHidden(TAutoVal& val)
{
  AUTONAMES0("Hidden")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Scenario::GetIndex()
{
  AUTONAMES0("Index")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Scenario::SetIndex(TAutoVal& val)
{
  AUTONAMES0("Index")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Scenario::GetLocked()
{
  AUTONAMES0("Locked")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Scenario::SetLocked(TAutoVal& val)
{
  AUTONAMES0("Locked")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Scenario::GetName()
{
  AUTONAMES0("Name")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Scenario::SetName(TAutoVal& val)
{
  AUTONAMES0("Name")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Scenario::GetParent()
{
  AUTONAMES0("Parent")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Scenario::SetParent(TAutoVal& val)
{
  AUTONAMES0("Parent")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Scenario::GetValues()
{
  AUTONAMES0("Values")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Scenario::SetValues(TAutoVal& val)
{
  AUTONAMES0("Values")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Scenario::Application()
{
  AUTONAMES0("Application")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Scenario::ChangeScenario(TAutoVal& ChangingCells, TAutoVal& Values)
{
  AUTONAMES0("ChangeScenario")
  AUTOARGS2(ChangingCells, Values)
  AUTOCALL_METHOD_RET
}

TAutoVal Scenario::Delete()
{
  AUTONAMES0("Delete")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Scenario::Show()
{
  AUTONAMES0("Show")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}


// TKIND_DISPATCH: Scenarios {00020896-0000-0000-C000-000000000046}\9

TAutoVal Scenarios::GetCount()
{
  AUTONAMES0("Count")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Scenarios::SetCount(TAutoVal& val)
{
  AUTONAMES0("Count")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Scenarios::GetCreator()
{
  AUTONAMES0("Creator")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Scenarios::SetCreator(TAutoVal& val)
{
  AUTONAMES0("Creator")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Scenarios::GetParent()
{
  AUTONAMES0("Parent")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Scenarios::SetParent(TAutoVal& val)
{
  AUTONAMES0("Parent")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Scenarios::_NewEnum()
{
  AUTONAMES0("_NewEnum")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Scenarios::Add(TAutoVal& Name, TAutoVal& ChangingCells, TAutoVal& Values, TAutoVal& Comment, TAutoVal& Locked, TAutoVal& Hidden)
{
  AUTONAMES0("Add")
  AUTOARGS6(Name, ChangingCells, Values, Comment, Locked, Hidden)
  AUTOCALL_METHOD_RET
}

TAutoVal Scenarios::Application()
{
  AUTONAMES0("Application")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Scenarios::CreateSummary(TAutoVal& ReportType, TAutoVal& ResultCells)
{
  AUTONAMES0("CreateSummary")
  AUTOARGS2(ReportType, ResultCells)
  AUTOCALL_METHOD_RET
}

TAutoVal Scenarios::Item(TAutoVal& Index)
{
  AUTONAMES0("Item")
  AUTOARGS1(Index)
  AUTOCALL_METHOD_RET
}

TAutoVal Scenarios::Merge(TAutoVal& Source)
{
  AUTONAMES0("Merge")
  AUTOARGS1(Source)
  AUTOCALL_METHOD_RET
}


// TKIND_DISPATCH: MenuBar {00020864-0000-0000-C000-000000000046}\9

TAutoVal MenuBar::GetCaption()
{
  AUTONAMES0("Caption")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void MenuBar::SetCaption(TAutoVal& val)
{
  AUTONAMES0("Caption")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal MenuBar::GetCreator()
{
  AUTONAMES0("Creator")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void MenuBar::SetCreator(TAutoVal& val)
{
  AUTONAMES0("Creator")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal MenuBar::GetIndex()
{
  AUTONAMES0("Index")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void MenuBar::SetIndex(TAutoVal& val)
{
  AUTONAMES0("Index")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal MenuBar::GetParent()
{
  AUTONAMES0("Parent")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void MenuBar::SetParent(TAutoVal& val)
{
  AUTONAMES0("Parent")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal MenuBar::Activate()
{
  AUTONAMES0("Activate")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal MenuBar::Application()
{
  AUTONAMES0("Application")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal MenuBar::BuiltIn()
{
  AUTONAMES0("BuiltIn")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal MenuBar::Delete()
{
  AUTONAMES0("Delete")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal MenuBar::Menus(TAutoVal& Index)
{
  AUTONAMES0("Menus")
  AUTOARGS1(Index)
  AUTOCALL_METHOD_RET
}

TAutoVal MenuBar::Reset()
{
  AUTONAMES0("Reset")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}


// TKIND_DISPATCH: MenuBars {00020863-0000-0000-C000-000000000046}\9

TAutoVal MenuBars::GetCount()
{
  AUTONAMES0("Count")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void MenuBars::SetCount(TAutoVal& val)
{
  AUTONAMES0("Count")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal MenuBars::GetCreator()
{
  AUTONAMES0("Creator")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void MenuBars::SetCreator(TAutoVal& val)
{
  AUTONAMES0("Creator")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal MenuBars::GetParent()
{
  AUTONAMES0("Parent")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void MenuBars::SetParent(TAutoVal& val)
{
  AUTONAMES0("Parent")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal MenuBars::_NewEnum()
{
  AUTONAMES0("_NewEnum")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal MenuBars::Add(TAutoVal& Name)
{
  AUTONAMES0("Add")
  AUTOARGS1(Name)
  AUTOCALL_METHOD_RET
}

TAutoVal MenuBars::Application()
{
  AUTONAMES0("Application")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal MenuBars::Item(TAutoVal& Index)
{
  AUTONAMES0("Item")
  AUTOARGS1(Index)
  AUTOCALL_METHOD_RET
}


// TKIND_DISPATCH: Menu {00020866-0000-0000-C000-000000000046}\9

TAutoVal Menu::GetCaption()
{
  AUTONAMES0("Caption")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Menu::SetCaption(TAutoVal& val)
{
  AUTONAMES0("Caption")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Menu::GetCreator()
{
  AUTONAMES0("Creator")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Menu::SetCreator(TAutoVal& val)
{
  AUTONAMES0("Creator")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Menu::GetEnabled()
{
  AUTONAMES0("Enabled")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Menu::SetEnabled(TAutoVal& val)
{
  AUTONAMES0("Enabled")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Menu::GetIndex()
{
  AUTONAMES0("Index")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Menu::SetIndex(TAutoVal& val)
{
  AUTONAMES0("Index")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Menu::GetParent()
{
  AUTONAMES0("Parent")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Menu::SetParent(TAutoVal& val)
{
  AUTONAMES0("Parent")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Menu::Application()
{
  AUTONAMES0("Application")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Menu::Delete()
{
  AUTONAMES0("Delete")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Menu::MenuItems(TAutoVal& Index)
{
  AUTONAMES0("MenuItems")
  AUTOARGS1(Index)
  AUTOCALL_METHOD_RET
}


// TKIND_DISPATCH: Menus {00020865-0000-0000-C000-000000000046}\9

TAutoVal Menus::GetCount()
{
  AUTONAMES0("Count")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Menus::SetCount(TAutoVal& val)
{
  AUTONAMES0("Count")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Menus::GetCreator()
{
  AUTONAMES0("Creator")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Menus::SetCreator(TAutoVal& val)
{
  AUTONAMES0("Creator")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Menus::GetParent()
{
  AUTONAMES0("Parent")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Menus::SetParent(TAutoVal& val)
{
  AUTONAMES0("Parent")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Menus::_NewEnum()
{
  AUTONAMES0("_NewEnum")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Menus::Add(TAutoVal& Caption, TAutoVal& Before, TAutoVal& Restore)
{
  AUTONAMES0("Add")
  AUTOARGS3(Caption, Before, Restore)
  AUTOCALL_METHOD_RET
}

TAutoVal Menus::Application()
{
  AUTONAMES0("Application")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Menus::Item(TAutoVal& Index)
{
  AUTONAMES0("Item")
  AUTOARGS1(Index)
  AUTOCALL_METHOD_RET
}


// TKIND_DISPATCH: MenuItem {00020868-0000-0000-C000-000000000046}\9

TAutoVal MenuItem::GetCaption()
{
  AUTONAMES0("Caption")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void MenuItem::SetCaption(TAutoVal& val)
{
  AUTONAMES0("Caption")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal MenuItem::GetChecked()
{
  AUTONAMES0("Checked")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void MenuItem::SetChecked(TAutoVal& val)
{
  AUTONAMES0("Checked")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal MenuItem::GetCreator()
{
  AUTONAMES0("Creator")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void MenuItem::SetCreator(TAutoVal& val)
{
  AUTONAMES0("Creator")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal MenuItem::GetEnabled()
{
  AUTONAMES0("Enabled")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void MenuItem::SetEnabled(TAutoVal& val)
{
  AUTONAMES0("Enabled")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal MenuItem::GetHelpContextID()
{
  AUTONAMES0("HelpContextID")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void MenuItem::SetHelpContextID(TAutoVal& val)
{
  AUTONAMES0("HelpContextID")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal MenuItem::GetHelpFile()
{
  AUTONAMES0("HelpFile")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void MenuItem::SetHelpFile(TAutoVal& val)
{
  AUTONAMES0("HelpFile")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal MenuItem::GetIndex()
{
  AUTONAMES0("Index")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void MenuItem::SetIndex(TAutoVal& val)
{
  AUTONAMES0("Index")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal MenuItem::GetOnAction()
{
  AUTONAMES0("OnAction")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void MenuItem::SetOnAction(TAutoVal& val)
{
  AUTONAMES0("OnAction")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal MenuItem::GetParent()
{
  AUTONAMES0("Parent")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void MenuItem::SetParent(TAutoVal& val)
{
  AUTONAMES0("Parent")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal MenuItem::GetStatusBar()
{
  AUTONAMES0("StatusBar")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void MenuItem::SetStatusBar(TAutoVal& val)
{
  AUTONAMES0("StatusBar")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal MenuItem::Application()
{
  AUTONAMES0("Application")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal MenuItem::Delete()
{
  AUTONAMES0("Delete")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}


// TKIND_DISPATCH: MenuItems {00020867-0000-0000-C000-000000000046}\9

TAutoVal MenuItems::GetCount()
{
  AUTONAMES0("Count")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void MenuItems::SetCount(TAutoVal& val)
{
  AUTONAMES0("Count")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal MenuItems::GetCreator()
{
  AUTONAMES0("Creator")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void MenuItems::SetCreator(TAutoVal& val)
{
  AUTONAMES0("Creator")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal MenuItems::GetParent()
{
  AUTONAMES0("Parent")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void MenuItems::SetParent(TAutoVal& val)
{
  AUTONAMES0("Parent")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal MenuItems::_NewEnum()
{
  AUTONAMES0("_NewEnum")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal MenuItems::Add(TAutoVal& Caption, TAutoVal& OnAction, TAutoVal& ShortcutKey, TAutoVal& Before, TAutoVal& Restore, TAutoVal& StatusBar, TAutoVal& HelpFile, TAutoVal& HelpContextID)
{
  AUTONAMES0("Add")
  AUTOARGS8(Caption, OnAction, ShortcutKey, Before, Restore, StatusBar, HelpFile, HelpContextID)
  AUTOCALL_METHOD_RET
}

TAutoVal MenuItems::AddMenu(TAutoVal& Caption, TAutoVal& Before, TAutoVal& Restore)
{
  AUTONAMES0("AddMenu")
  AUTOARGS3(Caption, Before, Restore)
  AUTOCALL_METHOD_RET
}

TAutoVal MenuItems::Application()
{
  AUTONAMES0("Application")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal MenuItems::Item(TAutoVal& Index)
{
  AUTONAMES0("Item")
  AUTOARGS1(Index)
  AUTOCALL_METHOD_RET
}


// TKIND_DISPATCH: Window {00020893-0000-0000-C000-000000000046}\9

TAutoVal Window::GetActiveCell()
{
  AUTONAMES0("ActiveCell")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Window::SetActiveCell(TAutoVal& val)
{
  AUTONAMES0("ActiveCell")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Window::GetActiveChart()
{
  AUTONAMES0("ActiveChart")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Window::SetActiveChart(TAutoVal& val)
{
  AUTONAMES0("ActiveChart")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Window::GetActivePane()
{
  AUTONAMES0("ActivePane")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Window::SetActivePane(TAutoVal& val)
{
  AUTONAMES0("ActivePane")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Window::GetActiveSheet()
{
  AUTONAMES0("ActiveSheet")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Window::SetActiveSheet(TAutoVal& val)
{
  AUTONAMES0("ActiveSheet")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Window::GetCaption()
{
  AUTONAMES0("Caption")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Window::SetCaption(TAutoVal& val)
{
  AUTONAMES0("Caption")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Window::GetCreator()
{
  AUTONAMES0("Creator")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Window::SetCreator(TAutoVal& val)
{
  AUTONAMES0("Creator")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Window::GetDisplayFormulas()
{
  AUTONAMES0("DisplayFormulas")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Window::SetDisplayFormulas(TAutoVal& val)
{
  AUTONAMES0("DisplayFormulas")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Window::GetDisplayGridlines()
{
  AUTONAMES0("DisplayGridlines")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Window::SetDisplayGridlines(TAutoVal& val)
{
  AUTONAMES0("DisplayGridlines")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Window::GetDisplayHeadings()
{
  AUTONAMES0("DisplayHeadings")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Window::SetDisplayHeadings(TAutoVal& val)
{
  AUTONAMES0("DisplayHeadings")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Window::GetDisplayHorizontalScrollBar()
{
  AUTONAMES0("DisplayHorizontalScrollBar")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Window::SetDisplayHorizontalScrollBar(TAutoVal& val)
{
  AUTONAMES0("DisplayHorizontalScrollBar")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Window::GetDisplayOutline()
{
  AUTONAMES0("DisplayOutline")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Window::SetDisplayOutline(TAutoVal& val)
{
  AUTONAMES0("DisplayOutline")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Window::GetDisplayRightToLeft()
{
  AUTONAMES0("DisplayRightToLeft")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Window::SetDisplayRightToLeft(TAutoVal& val)
{
  AUTONAMES0("DisplayRightToLeft")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Window::GetDisplayVerticalScrollBar()
{
  AUTONAMES0("DisplayVerticalScrollBar")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Window::SetDisplayVerticalScrollBar(TAutoVal& val)
{
  AUTONAMES0("DisplayVerticalScrollBar")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Window::GetDisplayWorkbookTabs()
{
  AUTONAMES0("DisplayWorkbookTabs")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Window::SetDisplayWorkbookTabs(TAutoVal& val)
{
  AUTONAMES0("DisplayWorkbookTabs")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Window::GetDisplayZeros()
{
  AUTONAMES0("DisplayZeros")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Window::SetDisplayZeros(TAutoVal& val)
{
  AUTONAMES0("DisplayZeros")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Window::GetFreezePanes()
{
  AUTONAMES0("FreezePanes")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Window::SetFreezePanes(TAutoVal& val)
{
  AUTONAMES0("FreezePanes")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Window::GetGridlineColor()
{
  AUTONAMES0("GridlineColor")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Window::SetGridlineColor(TAutoVal& val)
{
  AUTONAMES0("GridlineColor")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Window::GetGridlineColorIndex()
{
  AUTONAMES0("GridlineColorIndex")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Window::SetGridlineColorIndex(TAutoVal& val)
{
  AUTONAMES0("GridlineColorIndex")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Window::GetHeight()
{
  AUTONAMES0("Height")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Window::SetHeight(TAutoVal& val)
{
  AUTONAMES0("Height")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Window::GetIndex()
{
  AUTONAMES0("Index")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Window::SetIndex(TAutoVal& val)
{
  AUTONAMES0("Index")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Window::GetLeft()
{
  AUTONAMES0("Left")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Window::SetLeft(TAutoVal& val)
{
  AUTONAMES0("Left")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Window::GetOnWindow()
{
  AUTONAMES0("OnWindow")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Window::SetOnWindow(TAutoVal& val)
{
  AUTONAMES0("OnWindow")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Window::GetPageSetup()
{
  AUTONAMES0("PageSetup")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Window::SetPageSetup(TAutoVal& val)
{
  AUTONAMES0("PageSetup")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Window::GetParent()
{
  AUTONAMES0("Parent")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Window::SetParent(TAutoVal& val)
{
  AUTONAMES0("Parent")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Window::GetRangeSelection()
{
  AUTONAMES0("RangeSelection")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Window::SetRangeSelection(TAutoVal& val)
{
  AUTONAMES0("RangeSelection")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Window::GetScrollColumn()
{
  AUTONAMES0("ScrollColumn")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Window::SetScrollColumn(TAutoVal& val)
{
  AUTONAMES0("ScrollColumn")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Window::GetScrollRow()
{
  AUTONAMES0("ScrollRow")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Window::SetScrollRow(TAutoVal& val)
{
  AUTONAMES0("ScrollRow")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Window::GetSelectedSheets()
{
  AUTONAMES0("SelectedSheets")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Window::SetSelectedSheets(TAutoVal& val)
{
  AUTONAMES0("SelectedSheets")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Window::GetSelection()
{
  AUTONAMES0("Selection")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Window::SetSelection(TAutoVal& val)
{
  AUTONAMES0("Selection")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Window::GetSplit()
{
  AUTONAMES0("Split")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Window::SetSplit(TAutoVal& val)
{
  AUTONAMES0("Split")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Window::GetSplitColumn()
{
  AUTONAMES0("SplitColumn")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Window::SetSplitColumn(TAutoVal& val)
{
  AUTONAMES0("SplitColumn")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Window::GetSplitHorizontal()
{
  AUTONAMES0("SplitHorizontal")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Window::SetSplitHorizontal(TAutoVal& val)
{
  AUTONAMES0("SplitHorizontal")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Window::GetSplitRow()
{
  AUTONAMES0("SplitRow")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Window::SetSplitRow(TAutoVal& val)
{
  AUTONAMES0("SplitRow")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Window::GetSplitVertical()
{
  AUTONAMES0("SplitVertical")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Window::SetSplitVertical(TAutoVal& val)
{
  AUTONAMES0("SplitVertical")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Window::GetTabRatio()
{
  AUTONAMES0("TabRatio")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Window::SetTabRatio(TAutoVal& val)
{
  AUTONAMES0("TabRatio")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Window::GetTop()
{
  AUTONAMES0("Top")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Window::SetTop(TAutoVal& val)
{
  AUTONAMES0("Top")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Window::GetType()
{
  AUTONAMES0("Type")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Window::SetType(TAutoVal& val)
{
  AUTONAMES0("Type")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Window::GetUsableHeight()
{
  AUTONAMES0("UsableHeight")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Window::SetUsableHeight(TAutoVal& val)
{
  AUTONAMES0("UsableHeight")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Window::GetUsableWidth()
{
  AUTONAMES0("UsableWidth")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Window::SetUsableWidth(TAutoVal& val)
{
  AUTONAMES0("UsableWidth")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Window::GetVisible()
{
  AUTONAMES0("Visible")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Window::SetVisible(TAutoVal& val)
{
  AUTONAMES0("Visible")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Window::GetVisibleRange()
{
  AUTONAMES0("VisibleRange")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Window::SetVisibleRange(TAutoVal& val)
{
  AUTONAMES0("VisibleRange")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Window::GetWidth()
{
  AUTONAMES0("Width")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Window::SetWidth(TAutoVal& val)
{
  AUTONAMES0("Width")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Window::GetWindowNumber()
{
  AUTONAMES0("WindowNumber")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Window::SetWindowNumber(TAutoVal& val)
{
  AUTONAMES0("WindowNumber")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Window::GetWindowState()
{
  AUTONAMES0("WindowState")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Window::SetWindowState(TAutoVal& val)
{
  AUTONAMES0("WindowState")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Window::GetZoom()
{
  AUTONAMES0("Zoom")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Window::SetZoom(TAutoVal& val)
{
  AUTONAMES0("Zoom")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Window::Activate()
{
  AUTONAMES0("Activate")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Window::ActivateNext()
{
  AUTONAMES0("ActivateNext")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Window::ActivatePrevious()
{
  AUTONAMES0("ActivatePrevious")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Window::Application()
{
  AUTONAMES0("Application")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Window::Close(TAutoVal& SaveChanges, TAutoVal& Filename, TAutoVal& RouteWorkbook)
{
  AUTONAMES0("Close")
  AUTOARGS3(SaveChanges, Filename, RouteWorkbook)
  AUTOCALL_METHOD_RET
}

TAutoVal Window::LargeScroll(TAutoVal& Down, TAutoVal& Up, TAutoVal& ToRight, TAutoVal& ToLeft)
{
  AUTONAMES0("LargeScroll")
  AUTOARGS4(Down, Up, ToRight, ToLeft)
  AUTOCALL_METHOD_RET
}

TAutoVal Window::NewWindow()
{
  AUTONAMES0("NewWindow")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Window::Panes(TAutoVal& Index)
{
  AUTONAMES0("Panes")
  AUTOARGS1(Index)
  AUTOCALL_METHOD_RET
}

TAutoVal Window::PrintOut(TAutoVal& From, TAutoVal& To, TAutoVal& Copies, TAutoVal& Preview, TAutoVal& ActivePrinter, TAutoVal& PrintToFile, TAutoVal& Collate)
{
  AUTONAMES0("PrintOut")
  AUTOARGS7(From, To, Copies, Preview, ActivePrinter, PrintToFile, Collate)
  AUTOCALL_METHOD_RET
}

TAutoVal Window::PrintPreview()
{
  AUTONAMES0("PrintPreview")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Window::ScrollWorkbookTabs(TAutoVal& Sheets, TAutoVal& Position)
{
  AUTONAMES0("ScrollWorkbookTabs")
  AUTOARGS2(Sheets, Position)
  AUTOCALL_METHOD_RET
}

TAutoVal Window::SetInfoDisplay(TAutoVal& Cell, TAutoVal& Formula, TAutoVal& Value, TAutoVal& Format, TAutoVal& Protection, TAutoVal& Names, TAutoVal& Precedents, TAutoVal& Dependents, TAutoVal& Note)
{
  AUTONAMES0("SetInfoDisplay")
  AUTOARGS9(Cell, Formula, Value, Format, Protection, Names, Precedents, Dependents, Note)
  AUTOCALL_METHOD_RET
}

TAutoVal Window::SmallScroll(TAutoVal& Down, TAutoVal& Up, TAutoVal& ToRight, TAutoVal& ToLeft)
{
  AUTONAMES0("SmallScroll")
  AUTOARGS4(Down, Up, ToRight, ToLeft)
  AUTOCALL_METHOD_RET
}


// TKIND_DISPATCH: Windows {00020892-0000-0000-C000-000000000046}\9

TAutoVal Windows::GetCount()
{
  AUTONAMES0("Count")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Windows::SetCount(TAutoVal& val)
{
  AUTONAMES0("Count")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Windows::GetCreator()
{
  AUTONAMES0("Creator")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Windows::SetCreator(TAutoVal& val)
{
  AUTONAMES0("Creator")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Windows::GetParent()
{
  AUTONAMES0("Parent")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Windows::SetParent(TAutoVal& val)
{
  AUTONAMES0("Parent")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Windows::_NewEnum()
{
  AUTONAMES0("_NewEnum")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Windows::Application()
{
  AUTONAMES0("Application")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Windows::Arrange(TAutoVal& ArrangeStyle, TAutoVal& ActiveWorkbook, TAutoVal& SyncHorizontal, TAutoVal& SyncVertical)
{
  AUTONAMES0("Arrange")
  AUTOARGS4(ArrangeStyle, ActiveWorkbook, SyncHorizontal, SyncVertical)
  AUTOCALL_METHOD_RET
}

TAutoVal Windows::Item(TAutoVal& Index)
{
  AUTONAMES0("Item")
  AUTOARGS1(Index)
  AUTOCALL_METHOD_RET
}


// TKIND_DISPATCH: Pane {00020895-0000-0000-C000-000000000046}\9

TAutoVal Pane::GetCreator()
{
  AUTONAMES0("Creator")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Pane::SetCreator(TAutoVal& val)
{
  AUTONAMES0("Creator")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Pane::GetIndex()
{
  AUTONAMES0("Index")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Pane::SetIndex(TAutoVal& val)
{
  AUTONAMES0("Index")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Pane::GetParent()
{
  AUTONAMES0("Parent")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Pane::SetParent(TAutoVal& val)
{
  AUTONAMES0("Parent")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Pane::GetScrollColumn()
{
  AUTONAMES0("ScrollColumn")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Pane::SetScrollColumn(TAutoVal& val)
{
  AUTONAMES0("ScrollColumn")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Pane::GetScrollRow()
{
  AUTONAMES0("ScrollRow")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Pane::SetScrollRow(TAutoVal& val)
{
  AUTONAMES0("ScrollRow")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Pane::GetVisibleRange()
{
  AUTONAMES0("VisibleRange")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Pane::SetVisibleRange(TAutoVal& val)
{
  AUTONAMES0("VisibleRange")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Pane::Activate()
{
  AUTONAMES0("Activate")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Pane::Application()
{
  AUTONAMES0("Application")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Pane::LargeScroll(TAutoVal& Down, TAutoVal& Up, TAutoVal& ToRight, TAutoVal& ToLeft)
{
  AUTONAMES0("LargeScroll")
  AUTOARGS4(Down, Up, ToRight, ToLeft)
  AUTOCALL_METHOD_RET
}

TAutoVal Pane::SmallScroll(TAutoVal& Down, TAutoVal& Up, TAutoVal& ToRight, TAutoVal& ToLeft)
{
  AUTONAMES0("SmallScroll")
  AUTOARGS4(Down, Up, ToRight, ToLeft)
  AUTOCALL_METHOD_RET
}


// TKIND_DISPATCH: Panes {00020894-0000-0000-C000-000000000046}\9

TAutoVal Panes::GetCount()
{
  AUTONAMES0("Count")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Panes::SetCount(TAutoVal& val)
{
  AUTONAMES0("Count")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Panes::GetCreator()
{
  AUTONAMES0("Creator")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Panes::SetCreator(TAutoVal& val)
{
  AUTONAMES0("Creator")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Panes::GetParent()
{
  AUTONAMES0("Parent")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Panes::SetParent(TAutoVal& val)
{
  AUTONAMES0("Parent")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Panes::Application()
{
  AUTONAMES0("Application")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Panes::Item(TAutoVal& Index)
{
  AUTONAMES0("Item")
  AUTOARGS1(Index)
  AUTOCALL_METHOD_RET
}


// TKIND_DISPATCH: Name {000208B9-0000-0000-C000-000000000046}\9

TAutoVal Name::GetCategory()
{
  AUTONAMES0("Category")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Name::SetCategory(TAutoVal& val)
{
  AUTONAMES0("Category")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Name::GetCategoryLocal()
{
  AUTONAMES0("CategoryLocal")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Name::SetCategoryLocal(TAutoVal& val)
{
  AUTONAMES0("CategoryLocal")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Name::GetCreator()
{
  AUTONAMES0("Creator")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Name::SetCreator(TAutoVal& val)
{
  AUTONAMES0("Creator")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Name::GetIndex()
{
  AUTONAMES0("Index")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Name::SetIndex(TAutoVal& val)
{
  AUTONAMES0("Index")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Name::GetMacroType()
{
  AUTONAMES0("MacroType")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Name::SetMacroType(TAutoVal& val)
{
  AUTONAMES0("MacroType")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Name::GetName()
{
  AUTONAMES0("Name")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Name::SetName(TAutoVal& val)
{
  AUTONAMES0("Name")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Name::GetNameLocal()
{
  AUTONAMES0("NameLocal")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Name::SetNameLocal(TAutoVal& val)
{
  AUTONAMES0("NameLocal")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Name::GetParent()
{
  AUTONAMES0("Parent")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Name::SetParent(TAutoVal& val)
{
  AUTONAMES0("Parent")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Name::GetRefersTo()
{
  AUTONAMES0("RefersTo")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Name::SetRefersTo(TAutoVal& val)
{
  AUTONAMES0("RefersTo")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Name::GetRefersToLocal()
{
  AUTONAMES0("RefersToLocal")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Name::SetRefersToLocal(TAutoVal& val)
{
  AUTONAMES0("RefersToLocal")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Name::GetRefersToR1C1()
{
  AUTONAMES0("RefersToR1C1")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Name::SetRefersToR1C1(TAutoVal& val)
{
  AUTONAMES0("RefersToR1C1")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Name::GetRefersToR1C1Local()
{
  AUTONAMES0("RefersToR1C1Local")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Name::SetRefersToR1C1Local(TAutoVal& val)
{
  AUTONAMES0("RefersToR1C1Local")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Name::GetRefersToRange()
{
  AUTONAMES0("RefersToRange")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Name::SetRefersToRange(TAutoVal& val)
{
  AUTONAMES0("RefersToRange")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Name::GetShortcutKey()
{
  AUTONAMES0("ShortcutKey")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Name::SetShortcutKey(TAutoVal& val)
{
  AUTONAMES0("ShortcutKey")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Name::GetValue()
{
  AUTONAMES0("Value")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Name::SetValue(TAutoVal& val)
{
  AUTONAMES0("Value")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Name::GetVisible()
{
  AUTONAMES0("Visible")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Name::SetVisible(TAutoVal& val)
{
  AUTONAMES0("Visible")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Name::Application()
{
  AUTONAMES0("Application")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Name::Delete()
{
  AUTONAMES0("Delete")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}


// TKIND_DISPATCH: Names {000208B8-0000-0000-C000-000000000046}\9

TAutoVal Names::GetCount()
{
  AUTONAMES0("Count")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Names::SetCount(TAutoVal& val)
{
  AUTONAMES0("Count")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Names::GetCreator()
{
  AUTONAMES0("Creator")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Names::SetCreator(TAutoVal& val)
{
  AUTONAMES0("Creator")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Names::GetParent()
{
  AUTONAMES0("Parent")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Names::SetParent(TAutoVal& val)
{
  AUTONAMES0("Parent")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Names::_NewEnum()
{
  AUTONAMES0("_NewEnum")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Names::Add(TAutoVal& Name, TAutoVal& RefersTo, TAutoVal& Visible, TAutoVal& MacroType, TAutoVal& ShortcutKey, TAutoVal& Category, TAutoVal& NameLocal, TAutoVal& RefersToLocal, TAutoVal& CategoryLocal, TAutoVal& RefersToR1C1, TAutoVal& RefersToR1C1Local)
{
  AUTONAMES0("Add")
  AUTOARGS11(Name, RefersTo, Visible, MacroType, ShortcutKey, Category, NameLocal, RefersToLocal, CategoryLocal, RefersToR1C1, RefersToR1C1Local)
  AUTOCALL_METHOD_RET
}

TAutoVal Names::Application()
{
  AUTONAMES0("Application")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Names::Item(TAutoVal& Index, TAutoVal& IndexLocal, TAutoVal& RefersTo)
{
  AUTONAMES0("Item")
  AUTOARGS3(Index, IndexLocal, RefersTo)
  AUTOCALL_METHOD_RET
}


// TKIND_DISPATCH: DrawingObjects {0002086F-0000-0000-C000-000000000046}\9

TAutoVal DrawingObjects::GetAccelerator()
{
  AUTONAMES0("Accelerator")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void DrawingObjects::SetAccelerator(TAutoVal& val)
{
  AUTONAMES0("Accelerator")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal DrawingObjects::GetAddIndent()
{
  AUTONAMES0("AddIndent")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void DrawingObjects::SetAddIndent(TAutoVal& val)
{
  AUTONAMES0("AddIndent")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal DrawingObjects::GetArrowHeadLength()
{
  AUTONAMES0("ArrowHeadLength")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void DrawingObjects::SetArrowHeadLength(TAutoVal& val)
{
  AUTONAMES0("ArrowHeadLength")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal DrawingObjects::GetArrowHeadStyle()
{
  AUTONAMES0("ArrowHeadStyle")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void DrawingObjects::SetArrowHeadStyle(TAutoVal& val)
{
  AUTONAMES0("ArrowHeadStyle")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal DrawingObjects::GetArrowHeadWidth()
{
  AUTONAMES0("ArrowHeadWidth")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void DrawingObjects::SetArrowHeadWidth(TAutoVal& val)
{
  AUTONAMES0("ArrowHeadWidth")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal DrawingObjects::GetAutoSize()
{
  AUTONAMES0("AutoSize")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void DrawingObjects::SetAutoSize(TAutoVal& val)
{
  AUTONAMES0("AutoSize")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal DrawingObjects::GetBorder()
{
  AUTONAMES0("Border")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void DrawingObjects::SetBorder(TAutoVal& val)
{
  AUTONAMES0("Border")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal DrawingObjects::GetCancelButton()
{
  AUTONAMES0("CancelButton")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void DrawingObjects::SetCancelButton(TAutoVal& val)
{
  AUTONAMES0("CancelButton")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal DrawingObjects::GetCaption()
{
  AUTONAMES0("Caption")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void DrawingObjects::SetCaption(TAutoVal& val)
{
  AUTONAMES0("Caption")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal DrawingObjects::GetCount()
{
  AUTONAMES0("Count")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void DrawingObjects::SetCount(TAutoVal& val)
{
  AUTONAMES0("Count")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal DrawingObjects::GetCreator()
{
  AUTONAMES0("Creator")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void DrawingObjects::SetCreator(TAutoVal& val)
{
  AUTONAMES0("Creator")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal DrawingObjects::GetDefaultButton()
{
  AUTONAMES0("DefaultButton")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void DrawingObjects::SetDefaultButton(TAutoVal& val)
{
  AUTONAMES0("DefaultButton")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal DrawingObjects::GetDismissButton()
{
  AUTONAMES0("DismissButton")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void DrawingObjects::SetDismissButton(TAutoVal& val)
{
  AUTONAMES0("DismissButton")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal DrawingObjects::GetDisplay3DShading()
{
  AUTONAMES0("Display3DShading")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void DrawingObjects::SetDisplay3DShading(TAutoVal& val)
{
  AUTONAMES0("Display3DShading")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal DrawingObjects::GetDisplayVerticalScrollBar()
{
  AUTONAMES0("DisplayVerticalScrollBar")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void DrawingObjects::SetDisplayVerticalScrollBar(TAutoVal& val)
{
  AUTONAMES0("DisplayVerticalScrollBar")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal DrawingObjects::GetDropDownLines()
{
  AUTONAMES0("DropDownLines")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void DrawingObjects::SetDropDownLines(TAutoVal& val)
{
  AUTONAMES0("DropDownLines")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal DrawingObjects::GetEnabled()
{
  AUTONAMES0("Enabled")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void DrawingObjects::SetEnabled(TAutoVal& val)
{
  AUTONAMES0("Enabled")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal DrawingObjects::GetFont()
{
  AUTONAMES0("Font")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void DrawingObjects::SetFont(TAutoVal& val)
{
  AUTONAMES0("Font")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal DrawingObjects::GetHeight()
{
  AUTONAMES0("Height")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void DrawingObjects::SetHeight(TAutoVal& val)
{
  AUTONAMES0("Height")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal DrawingObjects::GetHelpButton()
{
  AUTONAMES0("HelpButton")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void DrawingObjects::SetHelpButton(TAutoVal& val)
{
  AUTONAMES0("HelpButton")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal DrawingObjects::GetHorizontalAlignment()
{
  AUTONAMES0("HorizontalAlignment")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void DrawingObjects::SetHorizontalAlignment(TAutoVal& val)
{
  AUTONAMES0("HorizontalAlignment")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal DrawingObjects::GetInputType()
{
  AUTONAMES0("InputType")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void DrawingObjects::SetInputType(TAutoVal& val)
{
  AUTONAMES0("InputType")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal DrawingObjects::GetInterior()
{
  AUTONAMES0("Interior")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void DrawingObjects::SetInterior(TAutoVal& val)
{
  AUTONAMES0("Interior")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal DrawingObjects::GetLargeChange()
{
  AUTONAMES0("LargeChange")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void DrawingObjects::SetLargeChange(TAutoVal& val)
{
  AUTONAMES0("LargeChange")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal DrawingObjects::GetLeft()
{
  AUTONAMES0("Left")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void DrawingObjects::SetLeft(TAutoVal& val)
{
  AUTONAMES0("Left")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal DrawingObjects::GetLinkedCell()
{
  AUTONAMES0("LinkedCell")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void DrawingObjects::SetLinkedCell(TAutoVal& val)
{
  AUTONAMES0("LinkedCell")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal DrawingObjects::GetList()
{
  AUTONAMES0("List")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void DrawingObjects::SetList(TAutoVal& val)
{
  AUTONAMES0("List")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal DrawingObjects::GetListFillRange()
{
  AUTONAMES0("ListFillRange")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void DrawingObjects::SetListFillRange(TAutoVal& val)
{
  AUTONAMES0("ListFillRange")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal DrawingObjects::GetListIndex()
{
  AUTONAMES0("ListIndex")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void DrawingObjects::SetListIndex(TAutoVal& val)
{
  AUTONAMES0("ListIndex")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal DrawingObjects::GetLocked()
{
  AUTONAMES0("Locked")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void DrawingObjects::SetLocked(TAutoVal& val)
{
  AUTONAMES0("Locked")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal DrawingObjects::GetLockedText()
{
  AUTONAMES0("LockedText")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void DrawingObjects::SetLockedText(TAutoVal& val)
{
  AUTONAMES0("LockedText")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal DrawingObjects::GetMax()
{
  AUTONAMES0("Max")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void DrawingObjects::SetMax(TAutoVal& val)
{
  AUTONAMES0("Max")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal DrawingObjects::GetMin()
{
  AUTONAMES0("Min")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void DrawingObjects::SetMin(TAutoVal& val)
{
  AUTONAMES0("Min")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal DrawingObjects::GetMultiLine()
{
  AUTONAMES0("MultiLine")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void DrawingObjects::SetMultiLine(TAutoVal& val)
{
  AUTONAMES0("MultiLine")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal DrawingObjects::GetMultiSelect()
{
  AUTONAMES0("MultiSelect")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void DrawingObjects::SetMultiSelect(TAutoVal& val)
{
  AUTONAMES0("MultiSelect")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal DrawingObjects::GetOnAction()
{
  AUTONAMES0("OnAction")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void DrawingObjects::SetOnAction(TAutoVal& val)
{
  AUTONAMES0("OnAction")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal DrawingObjects::GetOrientation()
{
  AUTONAMES0("Orientation")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void DrawingObjects::SetOrientation(TAutoVal& val)
{
  AUTONAMES0("Orientation")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal DrawingObjects::GetParent()
{
  AUTONAMES0("Parent")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void DrawingObjects::SetParent(TAutoVal& val)
{
  AUTONAMES0("Parent")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal DrawingObjects::GetPhoneticAccelerator()
{
  AUTONAMES0("PhoneticAccelerator")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void DrawingObjects::SetPhoneticAccelerator(TAutoVal& val)
{
  AUTONAMES0("PhoneticAccelerator")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal DrawingObjects::GetPlacement()
{
  AUTONAMES0("Placement")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void DrawingObjects::SetPlacement(TAutoVal& val)
{
  AUTONAMES0("Placement")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal DrawingObjects::GetPrintObject()
{
  AUTONAMES0("PrintObject")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void DrawingObjects::SetPrintObject(TAutoVal& val)
{
  AUTONAMES0("PrintObject")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal DrawingObjects::GetRoundedCorners()
{
  AUTONAMES0("RoundedCorners")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void DrawingObjects::SetRoundedCorners(TAutoVal& val)
{
  AUTONAMES0("RoundedCorners")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal DrawingObjects::GetSelected()
{
  AUTONAMES0("Selected")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void DrawingObjects::SetSelected(TAutoVal& val)
{
  AUTONAMES0("Selected")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal DrawingObjects::GetShadow()
{
  AUTONAMES0("Shadow")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void DrawingObjects::SetShadow(TAutoVal& val)
{
  AUTONAMES0("Shadow")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal DrawingObjects::GetSmallChange()
{
  AUTONAMES0("SmallChange")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void DrawingObjects::SetSmallChange(TAutoVal& val)
{
  AUTONAMES0("SmallChange")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal DrawingObjects::GetText()
{
  AUTONAMES0("Text")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void DrawingObjects::SetText(TAutoVal& val)
{
  AUTONAMES0("Text")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal DrawingObjects::GetTop()
{
  AUTONAMES0("Top")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void DrawingObjects::SetTop(TAutoVal& val)
{
  AUTONAMES0("Top")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal DrawingObjects::GetValue()
{
  AUTONAMES0("Value")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void DrawingObjects::SetValue(TAutoVal& val)
{
  AUTONAMES0("Value")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal DrawingObjects::GetVerticalAlignment()
{
  AUTONAMES0("VerticalAlignment")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void DrawingObjects::SetVerticalAlignment(TAutoVal& val)
{
  AUTONAMES0("VerticalAlignment")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal DrawingObjects::GetVertices()
{
  AUTONAMES0("Vertices")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void DrawingObjects::SetVertices(TAutoVal& val)
{
  AUTONAMES0("Vertices")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal DrawingObjects::GetVisible()
{
  AUTONAMES0("Visible")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void DrawingObjects::SetVisible(TAutoVal& val)
{
  AUTONAMES0("Visible")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal DrawingObjects::GetWidth()
{
  AUTONAMES0("Width")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void DrawingObjects::SetWidth(TAutoVal& val)
{
  AUTONAMES0("Width")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal DrawingObjects::GetZOrder()
{
  AUTONAMES0("ZOrder")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void DrawingObjects::SetZOrder(TAutoVal& val)
{
  AUTONAMES0("ZOrder")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal DrawingObjects::_NewEnum()
{
  AUTONAMES0("_NewEnum")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal DrawingObjects::AddItem(TAutoVal& Text, TAutoVal& Index)
{
  AUTONAMES0("AddItem")
  AUTOARGS2(Text, Index)
  AUTOCALL_METHOD_RET
}

TAutoVal DrawingObjects::Application()
{
  AUTONAMES0("Application")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal DrawingObjects::BringToFront()
{
  AUTONAMES0("BringToFront")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal DrawingObjects::Characters(TAutoVal& Start, TAutoVal& Length)
{
  AUTONAMES0("Characters")
  AUTOARGS2(Start, Length)
  AUTOCALL_METHOD_RET
}

TAutoVal DrawingObjects::CheckSpelling(TAutoVal& CustomDictionary, TAutoVal& IgnoreUppercase, TAutoVal& AlwaysSuggest)
{
  AUTONAMES0("CheckSpelling")
  AUTOARGS3(CustomDictionary, IgnoreUppercase, AlwaysSuggest)
  AUTOCALL_METHOD_RET
}

TAutoVal DrawingObjects::Copy()
{
  AUTONAMES0("Copy")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal DrawingObjects::CopyPicture(TAutoVal& Appearance, TAutoVal& Format)
{
  AUTONAMES0("CopyPicture")
  AUTOARGS2(Appearance, Format)
  AUTOCALL_METHOD_RET
}

TAutoVal DrawingObjects::Cut()
{
  AUTONAMES0("Cut")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal DrawingObjects::Delete()
{
  AUTONAMES0("Delete")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal DrawingObjects::Duplicate()
{
  AUTONAMES0("Duplicate")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal DrawingObjects::Group()
{
  AUTONAMES0("Group")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal DrawingObjects::Item(TAutoVal& Index)
{
  AUTONAMES0("Item")
  AUTOARGS1(Index)
  AUTOCALL_METHOD_RET
}

TAutoVal DrawingObjects::LinkCombo(TAutoVal& Link)
{
  AUTONAMES0("LinkCombo")
  AUTOARGS1(Link)
  AUTOCALL_METHOD_RET
}

TAutoVal DrawingObjects::RemoveAllItems()
{
  AUTONAMES0("RemoveAllItems")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal DrawingObjects::RemoveItem(TAutoVal& Index, TAutoVal& Count)
{
  AUTONAMES0("RemoveItem")
  AUTOARGS2(Index, Count)
  AUTOCALL_METHOD_RET
}

TAutoVal DrawingObjects::Reshape(TAutoVal& Vertex, TAutoVal& Insert, TAutoVal& Left, TAutoVal& Top)
{
  AUTONAMES0("Reshape")
  AUTOARGS4(Vertex, Insert, Left, Top)
  AUTOCALL_METHOD_RET
}

TAutoVal DrawingObjects::Select(TAutoVal& Replace)
{
  AUTONAMES0("Select")
  AUTOARGS1(Replace)
  AUTOCALL_METHOD_RET
}

TAutoVal DrawingObjects::SendToBack()
{
  AUTONAMES0("SendToBack")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal DrawingObjects::Ungroup()
{
  AUTONAMES0("Ungroup")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}


// TKIND_DISPATCH: GroupObject {00020898-0000-0000-C000-000000000046}\9

TAutoVal GroupObject::GetAddIndent()
{
  AUTONAMES0("AddIndent")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void GroupObject::SetAddIndent(TAutoVal& val)
{
  AUTONAMES0("AddIndent")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal GroupObject::GetArrowHeadLength()
{
  AUTONAMES0("ArrowHeadLength")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void GroupObject::SetArrowHeadLength(TAutoVal& val)
{
  AUTONAMES0("ArrowHeadLength")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal GroupObject::GetArrowHeadStyle()
{
  AUTONAMES0("ArrowHeadStyle")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void GroupObject::SetArrowHeadStyle(TAutoVal& val)
{
  AUTONAMES0("ArrowHeadStyle")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal GroupObject::GetArrowHeadWidth()
{
  AUTONAMES0("ArrowHeadWidth")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void GroupObject::SetArrowHeadWidth(TAutoVal& val)
{
  AUTONAMES0("ArrowHeadWidth")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal GroupObject::GetAutoSize()
{
  AUTONAMES0("AutoSize")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void GroupObject::SetAutoSize(TAutoVal& val)
{
  AUTONAMES0("AutoSize")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal GroupObject::GetBorder()
{
  AUTONAMES0("Border")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void GroupObject::SetBorder(TAutoVal& val)
{
  AUTONAMES0("Border")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal GroupObject::GetBottomRightCell()
{
  AUTONAMES0("BottomRightCell")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void GroupObject::SetBottomRightCell(TAutoVal& val)
{
  AUTONAMES0("BottomRightCell")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal GroupObject::GetCreator()
{
  AUTONAMES0("Creator")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void GroupObject::SetCreator(TAutoVal& val)
{
  AUTONAMES0("Creator")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal GroupObject::GetEnabled()
{
  AUTONAMES0("Enabled")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void GroupObject::SetEnabled(TAutoVal& val)
{
  AUTONAMES0("Enabled")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal GroupObject::GetFont()
{
  AUTONAMES0("Font")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void GroupObject::SetFont(TAutoVal& val)
{
  AUTONAMES0("Font")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal GroupObject::GetHeight()
{
  AUTONAMES0("Height")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void GroupObject::SetHeight(TAutoVal& val)
{
  AUTONAMES0("Height")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal GroupObject::GetHorizontalAlignment()
{
  AUTONAMES0("HorizontalAlignment")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void GroupObject::SetHorizontalAlignment(TAutoVal& val)
{
  AUTONAMES0("HorizontalAlignment")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal GroupObject::GetIndex()
{
  AUTONAMES0("Index")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void GroupObject::SetIndex(TAutoVal& val)
{
  AUTONAMES0("Index")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal GroupObject::GetInterior()
{
  AUTONAMES0("Interior")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void GroupObject::SetInterior(TAutoVal& val)
{
  AUTONAMES0("Interior")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal GroupObject::GetLeft()
{
  AUTONAMES0("Left")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void GroupObject::SetLeft(TAutoVal& val)
{
  AUTONAMES0("Left")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal GroupObject::GetLocked()
{
  AUTONAMES0("Locked")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void GroupObject::SetLocked(TAutoVal& val)
{
  AUTONAMES0("Locked")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal GroupObject::GetName()
{
  AUTONAMES0("Name")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void GroupObject::SetName(TAutoVal& val)
{
  AUTONAMES0("Name")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal GroupObject::GetOnAction()
{
  AUTONAMES0("OnAction")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void GroupObject::SetOnAction(TAutoVal& val)
{
  AUTONAMES0("OnAction")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal GroupObject::GetOrientation()
{
  AUTONAMES0("Orientation")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void GroupObject::SetOrientation(TAutoVal& val)
{
  AUTONAMES0("Orientation")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal GroupObject::GetParent()
{
  AUTONAMES0("Parent")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void GroupObject::SetParent(TAutoVal& val)
{
  AUTONAMES0("Parent")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal GroupObject::GetPlacement()
{
  AUTONAMES0("Placement")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void GroupObject::SetPlacement(TAutoVal& val)
{
  AUTONAMES0("Placement")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal GroupObject::GetPrintObject()
{
  AUTONAMES0("PrintObject")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void GroupObject::SetPrintObject(TAutoVal& val)
{
  AUTONAMES0("PrintObject")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal GroupObject::GetRoundedCorners()
{
  AUTONAMES0("RoundedCorners")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void GroupObject::SetRoundedCorners(TAutoVal& val)
{
  AUTONAMES0("RoundedCorners")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal GroupObject::GetShadow()
{
  AUTONAMES0("Shadow")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void GroupObject::SetShadow(TAutoVal& val)
{
  AUTONAMES0("Shadow")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal GroupObject::GetTop()
{
  AUTONAMES0("Top")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void GroupObject::SetTop(TAutoVal& val)
{
  AUTONAMES0("Top")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal GroupObject::GetTopLeftCell()
{
  AUTONAMES0("TopLeftCell")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void GroupObject::SetTopLeftCell(TAutoVal& val)
{
  AUTONAMES0("TopLeftCell")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal GroupObject::GetVerticalAlignment()
{
  AUTONAMES0("VerticalAlignment")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void GroupObject::SetVerticalAlignment(TAutoVal& val)
{
  AUTONAMES0("VerticalAlignment")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal GroupObject::GetVisible()
{
  AUTONAMES0("Visible")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void GroupObject::SetVisible(TAutoVal& val)
{
  AUTONAMES0("Visible")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal GroupObject::GetWidth()
{
  AUTONAMES0("Width")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void GroupObject::SetWidth(TAutoVal& val)
{
  AUTONAMES0("Width")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal GroupObject::GetZOrder()
{
  AUTONAMES0("ZOrder")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void GroupObject::SetZOrder(TAutoVal& val)
{
  AUTONAMES0("ZOrder")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal GroupObject::Application()
{
  AUTONAMES0("Application")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal GroupObject::BringToFront()
{
  AUTONAMES0("BringToFront")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal GroupObject::CheckSpelling(TAutoVal& CustomDictionary, TAutoVal& IgnoreUppercase, TAutoVal& AlwaysSuggest)
{
  AUTONAMES0("CheckSpelling")
  AUTOARGS3(CustomDictionary, IgnoreUppercase, AlwaysSuggest)
  AUTOCALL_METHOD_RET
}

TAutoVal GroupObject::Copy()
{
  AUTONAMES0("Copy")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal GroupObject::CopyPicture(TAutoVal& Appearance, TAutoVal& Format)
{
  AUTONAMES0("CopyPicture")
  AUTOARGS2(Appearance, Format)
  AUTOCALL_METHOD_RET
}

TAutoVal GroupObject::Cut()
{
  AUTONAMES0("Cut")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal GroupObject::Delete()
{
  AUTONAMES0("Delete")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal GroupObject::Duplicate()
{
  AUTONAMES0("Duplicate")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal GroupObject::Select(TAutoVal& Replace)
{
  AUTONAMES0("Select")
  AUTOARGS1(Replace)
  AUTOCALL_METHOD_RET
}

TAutoVal GroupObject::SendToBack()
{
  AUTONAMES0("SendToBack")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal GroupObject::Ungroup()
{
  AUTONAMES0("Ungroup")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}


// TKIND_DISPATCH: GroupObjects {00020899-0000-0000-C000-000000000046}\9

TAutoVal GroupObjects::GetAddIndent()
{
  AUTONAMES0("AddIndent")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void GroupObjects::SetAddIndent(TAutoVal& val)
{
  AUTONAMES0("AddIndent")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal GroupObjects::GetArrowHeadLength()
{
  AUTONAMES0("ArrowHeadLength")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void GroupObjects::SetArrowHeadLength(TAutoVal& val)
{
  AUTONAMES0("ArrowHeadLength")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal GroupObjects::GetArrowHeadStyle()
{
  AUTONAMES0("ArrowHeadStyle")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void GroupObjects::SetArrowHeadStyle(TAutoVal& val)
{
  AUTONAMES0("ArrowHeadStyle")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal GroupObjects::GetArrowHeadWidth()
{
  AUTONAMES0("ArrowHeadWidth")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void GroupObjects::SetArrowHeadWidth(TAutoVal& val)
{
  AUTONAMES0("ArrowHeadWidth")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal GroupObjects::GetAutoSize()
{
  AUTONAMES0("AutoSize")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void GroupObjects::SetAutoSize(TAutoVal& val)
{
  AUTONAMES0("AutoSize")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal GroupObjects::GetBorder()
{
  AUTONAMES0("Border")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void GroupObjects::SetBorder(TAutoVal& val)
{
  AUTONAMES0("Border")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal GroupObjects::GetCount()
{
  AUTONAMES0("Count")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void GroupObjects::SetCount(TAutoVal& val)
{
  AUTONAMES0("Count")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal GroupObjects::GetCreator()
{
  AUTONAMES0("Creator")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void GroupObjects::SetCreator(TAutoVal& val)
{
  AUTONAMES0("Creator")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal GroupObjects::GetEnabled()
{
  AUTONAMES0("Enabled")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void GroupObjects::SetEnabled(TAutoVal& val)
{
  AUTONAMES0("Enabled")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal GroupObjects::GetFont()
{
  AUTONAMES0("Font")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void GroupObjects::SetFont(TAutoVal& val)
{
  AUTONAMES0("Font")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal GroupObjects::GetHeight()
{
  AUTONAMES0("Height")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void GroupObjects::SetHeight(TAutoVal& val)
{
  AUTONAMES0("Height")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal GroupObjects::GetHorizontalAlignment()
{
  AUTONAMES0("HorizontalAlignment")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void GroupObjects::SetHorizontalAlignment(TAutoVal& val)
{
  AUTONAMES0("HorizontalAlignment")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal GroupObjects::GetInterior()
{
  AUTONAMES0("Interior")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void GroupObjects::SetInterior(TAutoVal& val)
{
  AUTONAMES0("Interior")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal GroupObjects::GetLeft()
{
  AUTONAMES0("Left")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void GroupObjects::SetLeft(TAutoVal& val)
{
  AUTONAMES0("Left")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal GroupObjects::GetLocked()
{
  AUTONAMES0("Locked")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void GroupObjects::SetLocked(TAutoVal& val)
{
  AUTONAMES0("Locked")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal GroupObjects::GetOnAction()
{
  AUTONAMES0("OnAction")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void GroupObjects::SetOnAction(TAutoVal& val)
{
  AUTONAMES0("OnAction")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal GroupObjects::GetOrientation()
{
  AUTONAMES0("Orientation")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void GroupObjects::SetOrientation(TAutoVal& val)
{
  AUTONAMES0("Orientation")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal GroupObjects::GetParent()
{
  AUTONAMES0("Parent")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void GroupObjects::SetParent(TAutoVal& val)
{
  AUTONAMES0("Parent")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal GroupObjects::GetPlacement()
{
  AUTONAMES0("Placement")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void GroupObjects::SetPlacement(TAutoVal& val)
{
  AUTONAMES0("Placement")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal GroupObjects::GetPrintObject()
{
  AUTONAMES0("PrintObject")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void GroupObjects::SetPrintObject(TAutoVal& val)
{
  AUTONAMES0("PrintObject")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal GroupObjects::GetRoundedCorners()
{
  AUTONAMES0("RoundedCorners")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void GroupObjects::SetRoundedCorners(TAutoVal& val)
{
  AUTONAMES0("RoundedCorners")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal GroupObjects::GetShadow()
{
  AUTONAMES0("Shadow")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void GroupObjects::SetShadow(TAutoVal& val)
{
  AUTONAMES0("Shadow")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal GroupObjects::GetTop()
{
  AUTONAMES0("Top")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void GroupObjects::SetTop(TAutoVal& val)
{
  AUTONAMES0("Top")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal GroupObjects::GetVerticalAlignment()
{
  AUTONAMES0("VerticalAlignment")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void GroupObjects::SetVerticalAlignment(TAutoVal& val)
{
  AUTONAMES0("VerticalAlignment")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal GroupObjects::GetVisible()
{
  AUTONAMES0("Visible")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void GroupObjects::SetVisible(TAutoVal& val)
{
  AUTONAMES0("Visible")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal GroupObjects::GetWidth()
{
  AUTONAMES0("Width")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void GroupObjects::SetWidth(TAutoVal& val)
{
  AUTONAMES0("Width")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal GroupObjects::GetZOrder()
{
  AUTONAMES0("ZOrder")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void GroupObjects::SetZOrder(TAutoVal& val)
{
  AUTONAMES0("ZOrder")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal GroupObjects::_NewEnum()
{
  AUTONAMES0("_NewEnum")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal GroupObjects::Application()
{
  AUTONAMES0("Application")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal GroupObjects::BringToFront()
{
  AUTONAMES0("BringToFront")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal GroupObjects::CheckSpelling(TAutoVal& CustomDictionary, TAutoVal& IgnoreUppercase, TAutoVal& AlwaysSuggest)
{
  AUTONAMES0("CheckSpelling")
  AUTOARGS3(CustomDictionary, IgnoreUppercase, AlwaysSuggest)
  AUTOCALL_METHOD_RET
}

TAutoVal GroupObjects::Copy()
{
  AUTONAMES0("Copy")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal GroupObjects::CopyPicture(TAutoVal& Appearance, TAutoVal& Format)
{
  AUTONAMES0("CopyPicture")
  AUTOARGS2(Appearance, Format)
  AUTOCALL_METHOD_RET
}

TAutoVal GroupObjects::Cut()
{
  AUTONAMES0("Cut")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal GroupObjects::Delete()
{
  AUTONAMES0("Delete")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal GroupObjects::Duplicate()
{
  AUTONAMES0("Duplicate")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal GroupObjects::Group()
{
  AUTONAMES0("Group")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal GroupObjects::Item(TAutoVal& Index)
{
  AUTONAMES0("Item")
  AUTOARGS1(Index)
  AUTOCALL_METHOD_RET
}

TAutoVal GroupObjects::Select(TAutoVal& Replace)
{
  AUTONAMES0("Select")
  AUTOARGS1(Replace)
  AUTOCALL_METHOD_RET
}

TAutoVal GroupObjects::SendToBack()
{
  AUTONAMES0("SendToBack")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal GroupObjects::Ungroup()
{
  AUTONAMES0("Ungroup")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}


// TKIND_DISPATCH: Line {0002089A-0000-0000-C000-000000000046}\9

TAutoVal Line::GetArrowHeadLength()
{
  AUTONAMES0("ArrowHeadLength")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Line::SetArrowHeadLength(TAutoVal& val)
{
  AUTONAMES0("ArrowHeadLength")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Line::GetArrowHeadStyle()
{
  AUTONAMES0("ArrowHeadStyle")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Line::SetArrowHeadStyle(TAutoVal& val)
{
  AUTONAMES0("ArrowHeadStyle")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Line::GetArrowHeadWidth()
{
  AUTONAMES0("ArrowHeadWidth")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Line::SetArrowHeadWidth(TAutoVal& val)
{
  AUTONAMES0("ArrowHeadWidth")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Line::GetBorder()
{
  AUTONAMES0("Border")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Line::SetBorder(TAutoVal& val)
{
  AUTONAMES0("Border")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Line::GetBottomRightCell()
{
  AUTONAMES0("BottomRightCell")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Line::SetBottomRightCell(TAutoVal& val)
{
  AUTONAMES0("BottomRightCell")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Line::GetCreator()
{
  AUTONAMES0("Creator")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Line::SetCreator(TAutoVal& val)
{
  AUTONAMES0("Creator")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Line::GetEnabled()
{
  AUTONAMES0("Enabled")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Line::SetEnabled(TAutoVal& val)
{
  AUTONAMES0("Enabled")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Line::GetHeight()
{
  AUTONAMES0("Height")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Line::SetHeight(TAutoVal& val)
{
  AUTONAMES0("Height")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Line::GetIndex()
{
  AUTONAMES0("Index")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Line::SetIndex(TAutoVal& val)
{
  AUTONAMES0("Index")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Line::GetLeft()
{
  AUTONAMES0("Left")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Line::SetLeft(TAutoVal& val)
{
  AUTONAMES0("Left")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Line::GetLocked()
{
  AUTONAMES0("Locked")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Line::SetLocked(TAutoVal& val)
{
  AUTONAMES0("Locked")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Line::GetName()
{
  AUTONAMES0("Name")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Line::SetName(TAutoVal& val)
{
  AUTONAMES0("Name")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Line::GetOnAction()
{
  AUTONAMES0("OnAction")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Line::SetOnAction(TAutoVal& val)
{
  AUTONAMES0("OnAction")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Line::GetParent()
{
  AUTONAMES0("Parent")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Line::SetParent(TAutoVal& val)
{
  AUTONAMES0("Parent")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Line::GetPlacement()
{
  AUTONAMES0("Placement")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Line::SetPlacement(TAutoVal& val)
{
  AUTONAMES0("Placement")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Line::GetPrintObject()
{
  AUTONAMES0("PrintObject")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Line::SetPrintObject(TAutoVal& val)
{
  AUTONAMES0("PrintObject")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Line::GetTop()
{
  AUTONAMES0("Top")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Line::SetTop(TAutoVal& val)
{
  AUTONAMES0("Top")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Line::GetTopLeftCell()
{
  AUTONAMES0("TopLeftCell")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Line::SetTopLeftCell(TAutoVal& val)
{
  AUTONAMES0("TopLeftCell")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Line::GetVisible()
{
  AUTONAMES0("Visible")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Line::SetVisible(TAutoVal& val)
{
  AUTONAMES0("Visible")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Line::GetWidth()
{
  AUTONAMES0("Width")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Line::SetWidth(TAutoVal& val)
{
  AUTONAMES0("Width")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Line::GetZOrder()
{
  AUTONAMES0("ZOrder")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Line::SetZOrder(TAutoVal& val)
{
  AUTONAMES0("ZOrder")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Line::Application()
{
  AUTONAMES0("Application")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Line::BringToFront()
{
  AUTONAMES0("BringToFront")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Line::Copy()
{
  AUTONAMES0("Copy")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Line::CopyPicture(TAutoVal& Appearance, TAutoVal& Format)
{
  AUTONAMES0("CopyPicture")
  AUTOARGS2(Appearance, Format)
  AUTOCALL_METHOD_RET
}

TAutoVal Line::Cut()
{
  AUTONAMES0("Cut")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Line::Delete()
{
  AUTONAMES0("Delete")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Line::Duplicate()
{
  AUTONAMES0("Duplicate")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Line::Select(TAutoVal& Replace)
{
  AUTONAMES0("Select")
  AUTOARGS1(Replace)
  AUTOCALL_METHOD_RET
}

TAutoVal Line::SendToBack()
{
  AUTONAMES0("SendToBack")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}


// TKIND_DISPATCH: Lines {0002089B-0000-0000-C000-000000000046}\9

TAutoVal Lines::GetArrowHeadLength()
{
  AUTONAMES0("ArrowHeadLength")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Lines::SetArrowHeadLength(TAutoVal& val)
{
  AUTONAMES0("ArrowHeadLength")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Lines::GetArrowHeadStyle()
{
  AUTONAMES0("ArrowHeadStyle")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Lines::SetArrowHeadStyle(TAutoVal& val)
{
  AUTONAMES0("ArrowHeadStyle")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Lines::GetArrowHeadWidth()
{
  AUTONAMES0("ArrowHeadWidth")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Lines::SetArrowHeadWidth(TAutoVal& val)
{
  AUTONAMES0("ArrowHeadWidth")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Lines::GetBorder()
{
  AUTONAMES0("Border")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Lines::SetBorder(TAutoVal& val)
{
  AUTONAMES0("Border")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Lines::GetCount()
{
  AUTONAMES0("Count")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Lines::SetCount(TAutoVal& val)
{
  AUTONAMES0("Count")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Lines::GetCreator()
{
  AUTONAMES0("Creator")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Lines::SetCreator(TAutoVal& val)
{
  AUTONAMES0("Creator")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Lines::GetEnabled()
{
  AUTONAMES0("Enabled")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Lines::SetEnabled(TAutoVal& val)
{
  AUTONAMES0("Enabled")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Lines::GetHeight()
{
  AUTONAMES0("Height")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Lines::SetHeight(TAutoVal& val)
{
  AUTONAMES0("Height")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Lines::GetLeft()
{
  AUTONAMES0("Left")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Lines::SetLeft(TAutoVal& val)
{
  AUTONAMES0("Left")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Lines::GetLocked()
{
  AUTONAMES0("Locked")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Lines::SetLocked(TAutoVal& val)
{
  AUTONAMES0("Locked")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Lines::GetOnAction()
{
  AUTONAMES0("OnAction")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Lines::SetOnAction(TAutoVal& val)
{
  AUTONAMES0("OnAction")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Lines::GetParent()
{
  AUTONAMES0("Parent")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Lines::SetParent(TAutoVal& val)
{
  AUTONAMES0("Parent")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Lines::GetPlacement()
{
  AUTONAMES0("Placement")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Lines::SetPlacement(TAutoVal& val)
{
  AUTONAMES0("Placement")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Lines::GetPrintObject()
{
  AUTONAMES0("PrintObject")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Lines::SetPrintObject(TAutoVal& val)
{
  AUTONAMES0("PrintObject")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Lines::GetTop()
{
  AUTONAMES0("Top")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Lines::SetTop(TAutoVal& val)
{
  AUTONAMES0("Top")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Lines::GetVisible()
{
  AUTONAMES0("Visible")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Lines::SetVisible(TAutoVal& val)
{
  AUTONAMES0("Visible")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Lines::GetWidth()
{
  AUTONAMES0("Width")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Lines::SetWidth(TAutoVal& val)
{
  AUTONAMES0("Width")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Lines::GetZOrder()
{
  AUTONAMES0("ZOrder")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Lines::SetZOrder(TAutoVal& val)
{
  AUTONAMES0("ZOrder")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Lines::_NewEnum()
{
  AUTONAMES0("_NewEnum")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Lines::Add(TAutoVal& X1, TAutoVal& Y1, TAutoVal& X2, TAutoVal& Y2)
{
  AUTONAMES0("Add")
  AUTOARGS4(X1, Y1, X2, Y2)
  AUTOCALL_METHOD_RET
}

TAutoVal Lines::Application()
{
  AUTONAMES0("Application")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Lines::BringToFront()
{
  AUTONAMES0("BringToFront")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Lines::Copy()
{
  AUTONAMES0("Copy")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Lines::CopyPicture(TAutoVal& Appearance, TAutoVal& Format)
{
  AUTONAMES0("CopyPicture")
  AUTOARGS2(Appearance, Format)
  AUTOCALL_METHOD_RET
}

TAutoVal Lines::Cut()
{
  AUTONAMES0("Cut")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Lines::Delete()
{
  AUTONAMES0("Delete")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Lines::Duplicate()
{
  AUTONAMES0("Duplicate")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Lines::Group()
{
  AUTONAMES0("Group")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Lines::Item(TAutoVal& Index)
{
  AUTONAMES0("Item")
  AUTOARGS1(Index)
  AUTOCALL_METHOD_RET
}

TAutoVal Lines::Select(TAutoVal& Replace)
{
  AUTONAMES0("Select")
  AUTOARGS1(Replace)
  AUTOCALL_METHOD_RET
}

TAutoVal Lines::SendToBack()
{
  AUTONAMES0("SendToBack")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}


// TKIND_DISPATCH: Rectangle {0002089C-0000-0000-C000-000000000046}\9

TAutoVal Rectangle::GetBorder()
{
  AUTONAMES0("Border")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Rectangle::SetBorder(TAutoVal& val)
{
  AUTONAMES0("Border")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Rectangle::GetBottomRightCell()
{
  AUTONAMES0("BottomRightCell")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Rectangle::SetBottomRightCell(TAutoVal& val)
{
  AUTONAMES0("BottomRightCell")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Rectangle::GetCreator()
{
  AUTONAMES0("Creator")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Rectangle::SetCreator(TAutoVal& val)
{
  AUTONAMES0("Creator")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Rectangle::GetEnabled()
{
  AUTONAMES0("Enabled")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Rectangle::SetEnabled(TAutoVal& val)
{
  AUTONAMES0("Enabled")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Rectangle::GetHeight()
{
  AUTONAMES0("Height")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Rectangle::SetHeight(TAutoVal& val)
{
  AUTONAMES0("Height")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Rectangle::GetIndex()
{
  AUTONAMES0("Index")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Rectangle::SetIndex(TAutoVal& val)
{
  AUTONAMES0("Index")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Rectangle::GetInterior()
{
  AUTONAMES0("Interior")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Rectangle::SetInterior(TAutoVal& val)
{
  AUTONAMES0("Interior")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Rectangle::GetLeft()
{
  AUTONAMES0("Left")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Rectangle::SetLeft(TAutoVal& val)
{
  AUTONAMES0("Left")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Rectangle::GetLocked()
{
  AUTONAMES0("Locked")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Rectangle::SetLocked(TAutoVal& val)
{
  AUTONAMES0("Locked")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Rectangle::GetName()
{
  AUTONAMES0("Name")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Rectangle::SetName(TAutoVal& val)
{
  AUTONAMES0("Name")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Rectangle::GetOnAction()
{
  AUTONAMES0("OnAction")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Rectangle::SetOnAction(TAutoVal& val)
{
  AUTONAMES0("OnAction")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Rectangle::GetParent()
{
  AUTONAMES0("Parent")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Rectangle::SetParent(TAutoVal& val)
{
  AUTONAMES0("Parent")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Rectangle::GetPlacement()
{
  AUTONAMES0("Placement")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Rectangle::SetPlacement(TAutoVal& val)
{
  AUTONAMES0("Placement")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Rectangle::GetPrintObject()
{
  AUTONAMES0("PrintObject")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Rectangle::SetPrintObject(TAutoVal& val)
{
  AUTONAMES0("PrintObject")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Rectangle::GetRoundedCorners()
{
  AUTONAMES0("RoundedCorners")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Rectangle::SetRoundedCorners(TAutoVal& val)
{
  AUTONAMES0("RoundedCorners")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Rectangle::GetShadow()
{
  AUTONAMES0("Shadow")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Rectangle::SetShadow(TAutoVal& val)
{
  AUTONAMES0("Shadow")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Rectangle::GetTop()
{
  AUTONAMES0("Top")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Rectangle::SetTop(TAutoVal& val)
{
  AUTONAMES0("Top")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Rectangle::GetTopLeftCell()
{
  AUTONAMES0("TopLeftCell")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Rectangle::SetTopLeftCell(TAutoVal& val)
{
  AUTONAMES0("TopLeftCell")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Rectangle::GetVisible()
{
  AUTONAMES0("Visible")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Rectangle::SetVisible(TAutoVal& val)
{
  AUTONAMES0("Visible")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Rectangle::GetWidth()
{
  AUTONAMES0("Width")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Rectangle::SetWidth(TAutoVal& val)
{
  AUTONAMES0("Width")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Rectangle::GetZOrder()
{
  AUTONAMES0("ZOrder")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Rectangle::SetZOrder(TAutoVal& val)
{
  AUTONAMES0("ZOrder")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Rectangle::Application()
{
  AUTONAMES0("Application")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Rectangle::BringToFront()
{
  AUTONAMES0("BringToFront")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Rectangle::Copy()
{
  AUTONAMES0("Copy")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Rectangle::CopyPicture(TAutoVal& Appearance, TAutoVal& Format)
{
  AUTONAMES0("CopyPicture")
  AUTOARGS2(Appearance, Format)
  AUTOCALL_METHOD_RET
}

TAutoVal Rectangle::Cut()
{
  AUTONAMES0("Cut")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Rectangle::Delete()
{
  AUTONAMES0("Delete")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Rectangle::Duplicate()
{
  AUTONAMES0("Duplicate")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Rectangle::Select(TAutoVal& Replace)
{
  AUTONAMES0("Select")
  AUTOARGS1(Replace)
  AUTOCALL_METHOD_RET
}

TAutoVal Rectangle::SendToBack()
{
  AUTONAMES0("SendToBack")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}


// TKIND_DISPATCH: Rectangles {0002089D-0000-0000-C000-000000000046}\9

TAutoVal Rectangles::GetBorder()
{
  AUTONAMES0("Border")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Rectangles::SetBorder(TAutoVal& val)
{
  AUTONAMES0("Border")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Rectangles::GetCount()
{
  AUTONAMES0("Count")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Rectangles::SetCount(TAutoVal& val)
{
  AUTONAMES0("Count")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Rectangles::GetCreator()
{
  AUTONAMES0("Creator")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Rectangles::SetCreator(TAutoVal& val)
{
  AUTONAMES0("Creator")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Rectangles::GetEnabled()
{
  AUTONAMES0("Enabled")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Rectangles::SetEnabled(TAutoVal& val)
{
  AUTONAMES0("Enabled")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Rectangles::GetHeight()
{
  AUTONAMES0("Height")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Rectangles::SetHeight(TAutoVal& val)
{
  AUTONAMES0("Height")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Rectangles::GetInterior()
{
  AUTONAMES0("Interior")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Rectangles::SetInterior(TAutoVal& val)
{
  AUTONAMES0("Interior")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Rectangles::GetLeft()
{
  AUTONAMES0("Left")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Rectangles::SetLeft(TAutoVal& val)
{
  AUTONAMES0("Left")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Rectangles::GetLocked()
{
  AUTONAMES0("Locked")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Rectangles::SetLocked(TAutoVal& val)
{
  AUTONAMES0("Locked")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Rectangles::GetOnAction()
{
  AUTONAMES0("OnAction")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Rectangles::SetOnAction(TAutoVal& val)
{
  AUTONAMES0("OnAction")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Rectangles::GetParent()
{
  AUTONAMES0("Parent")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Rectangles::SetParent(TAutoVal& val)
{
  AUTONAMES0("Parent")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Rectangles::GetPlacement()
{
  AUTONAMES0("Placement")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Rectangles::SetPlacement(TAutoVal& val)
{
  AUTONAMES0("Placement")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Rectangles::GetPrintObject()
{
  AUTONAMES0("PrintObject")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Rectangles::SetPrintObject(TAutoVal& val)
{
  AUTONAMES0("PrintObject")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Rectangles::GetRoundedCorners()
{
  AUTONAMES0("RoundedCorners")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Rectangles::SetRoundedCorners(TAutoVal& val)
{
  AUTONAMES0("RoundedCorners")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Rectangles::GetShadow()
{
  AUTONAMES0("Shadow")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Rectangles::SetShadow(TAutoVal& val)
{
  AUTONAMES0("Shadow")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Rectangles::GetTop()
{
  AUTONAMES0("Top")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Rectangles::SetTop(TAutoVal& val)
{
  AUTONAMES0("Top")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Rectangles::GetVisible()
{
  AUTONAMES0("Visible")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Rectangles::SetVisible(TAutoVal& val)
{
  AUTONAMES0("Visible")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Rectangles::GetWidth()
{
  AUTONAMES0("Width")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Rectangles::SetWidth(TAutoVal& val)
{
  AUTONAMES0("Width")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Rectangles::GetZOrder()
{
  AUTONAMES0("ZOrder")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Rectangles::SetZOrder(TAutoVal& val)
{
  AUTONAMES0("ZOrder")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Rectangles::_NewEnum()
{
  AUTONAMES0("_NewEnum")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Rectangles::Add(TAutoVal& Left, TAutoVal& Top, TAutoVal& Width, TAutoVal& Height)
{
  AUTONAMES0("Add")
  AUTOARGS4(Left, Top, Width, Height)
  AUTOCALL_METHOD_RET
}

TAutoVal Rectangles::Application()
{
  AUTONAMES0("Application")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Rectangles::BringToFront()
{
  AUTONAMES0("BringToFront")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Rectangles::Copy()
{
  AUTONAMES0("Copy")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Rectangles::CopyPicture(TAutoVal& Appearance, TAutoVal& Format)
{
  AUTONAMES0("CopyPicture")
  AUTOARGS2(Appearance, Format)
  AUTOCALL_METHOD_RET
}

TAutoVal Rectangles::Cut()
{
  AUTONAMES0("Cut")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Rectangles::Delete()
{
  AUTONAMES0("Delete")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Rectangles::Duplicate()
{
  AUTONAMES0("Duplicate")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Rectangles::Group()
{
  AUTONAMES0("Group")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Rectangles::Item(TAutoVal& Index)
{
  AUTONAMES0("Item")
  AUTOARGS1(Index)
  AUTOCALL_METHOD_RET
}

TAutoVal Rectangles::Select(TAutoVal& Replace)
{
  AUTONAMES0("Select")
  AUTOARGS1(Replace)
  AUTOCALL_METHOD_RET
}

TAutoVal Rectangles::SendToBack()
{
  AUTONAMES0("SendToBack")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}


// TKIND_DISPATCH: Oval {0002089E-0000-0000-C000-000000000046}\9

TAutoVal Oval::GetBorder()
{
  AUTONAMES0("Border")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Oval::SetBorder(TAutoVal& val)
{
  AUTONAMES0("Border")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Oval::GetBottomRightCell()
{
  AUTONAMES0("BottomRightCell")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Oval::SetBottomRightCell(TAutoVal& val)
{
  AUTONAMES0("BottomRightCell")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Oval::GetCreator()
{
  AUTONAMES0("Creator")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Oval::SetCreator(TAutoVal& val)
{
  AUTONAMES0("Creator")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Oval::GetEnabled()
{
  AUTONAMES0("Enabled")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Oval::SetEnabled(TAutoVal& val)
{
  AUTONAMES0("Enabled")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Oval::GetHeight()
{
  AUTONAMES0("Height")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Oval::SetHeight(TAutoVal& val)
{
  AUTONAMES0("Height")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Oval::GetIndex()
{
  AUTONAMES0("Index")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Oval::SetIndex(TAutoVal& val)
{
  AUTONAMES0("Index")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Oval::GetInterior()
{
  AUTONAMES0("Interior")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Oval::SetInterior(TAutoVal& val)
{
  AUTONAMES0("Interior")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Oval::GetLeft()
{
  AUTONAMES0("Left")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Oval::SetLeft(TAutoVal& val)
{
  AUTONAMES0("Left")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Oval::GetLocked()
{
  AUTONAMES0("Locked")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Oval::SetLocked(TAutoVal& val)
{
  AUTONAMES0("Locked")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Oval::GetName()
{
  AUTONAMES0("Name")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Oval::SetName(TAutoVal& val)
{
  AUTONAMES0("Name")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Oval::GetOnAction()
{
  AUTONAMES0("OnAction")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Oval::SetOnAction(TAutoVal& val)
{
  AUTONAMES0("OnAction")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Oval::GetParent()
{
  AUTONAMES0("Parent")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Oval::SetParent(TAutoVal& val)
{
  AUTONAMES0("Parent")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Oval::GetPlacement()
{
  AUTONAMES0("Placement")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Oval::SetPlacement(TAutoVal& val)
{
  AUTONAMES0("Placement")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Oval::GetPrintObject()
{
  AUTONAMES0("PrintObject")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Oval::SetPrintObject(TAutoVal& val)
{
  AUTONAMES0("PrintObject")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Oval::GetShadow()
{
  AUTONAMES0("Shadow")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Oval::SetShadow(TAutoVal& val)
{
  AUTONAMES0("Shadow")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Oval::GetTop()
{
  AUTONAMES0("Top")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Oval::SetTop(TAutoVal& val)
{
  AUTONAMES0("Top")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Oval::GetTopLeftCell()
{
  AUTONAMES0("TopLeftCell")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Oval::SetTopLeftCell(TAutoVal& val)
{
  AUTONAMES0("TopLeftCell")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Oval::GetVisible()
{
  AUTONAMES0("Visible")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Oval::SetVisible(TAutoVal& val)
{
  AUTONAMES0("Visible")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Oval::GetWidth()
{
  AUTONAMES0("Width")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Oval::SetWidth(TAutoVal& val)
{
  AUTONAMES0("Width")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Oval::GetZOrder()
{
  AUTONAMES0("ZOrder")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Oval::SetZOrder(TAutoVal& val)
{
  AUTONAMES0("ZOrder")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Oval::Application()
{
  AUTONAMES0("Application")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Oval::BringToFront()
{
  AUTONAMES0("BringToFront")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Oval::Copy()
{
  AUTONAMES0("Copy")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Oval::CopyPicture(TAutoVal& Appearance, TAutoVal& Format)
{
  AUTONAMES0("CopyPicture")
  AUTOARGS2(Appearance, Format)
  AUTOCALL_METHOD_RET
}

TAutoVal Oval::Cut()
{
  AUTONAMES0("Cut")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Oval::Delete()
{
  AUTONAMES0("Delete")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Oval::Duplicate()
{
  AUTONAMES0("Duplicate")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Oval::Select(TAutoVal& Replace)
{
  AUTONAMES0("Select")
  AUTOARGS1(Replace)
  AUTOCALL_METHOD_RET
}

TAutoVal Oval::SendToBack()
{
  AUTONAMES0("SendToBack")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}


// TKIND_DISPATCH: Ovals {0002089F-0000-0000-C000-000000000046}\9

TAutoVal Ovals::GetBorder()
{
  AUTONAMES0("Border")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Ovals::SetBorder(TAutoVal& val)
{
  AUTONAMES0("Border")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Ovals::GetCount()
{
  AUTONAMES0("Count")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Ovals::SetCount(TAutoVal& val)
{
  AUTONAMES0("Count")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Ovals::GetCreator()
{
  AUTONAMES0("Creator")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Ovals::SetCreator(TAutoVal& val)
{
  AUTONAMES0("Creator")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Ovals::GetEnabled()
{
  AUTONAMES0("Enabled")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Ovals::SetEnabled(TAutoVal& val)
{
  AUTONAMES0("Enabled")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Ovals::GetHeight()
{
  AUTONAMES0("Height")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Ovals::SetHeight(TAutoVal& val)
{
  AUTONAMES0("Height")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Ovals::GetInterior()
{
  AUTONAMES0("Interior")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Ovals::SetInterior(TAutoVal& val)
{
  AUTONAMES0("Interior")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Ovals::GetLeft()
{
  AUTONAMES0("Left")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Ovals::SetLeft(TAutoVal& val)
{
  AUTONAMES0("Left")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Ovals::GetLocked()
{
  AUTONAMES0("Locked")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Ovals::SetLocked(TAutoVal& val)
{
  AUTONAMES0("Locked")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Ovals::GetOnAction()
{
  AUTONAMES0("OnAction")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Ovals::SetOnAction(TAutoVal& val)
{
  AUTONAMES0("OnAction")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Ovals::GetParent()
{
  AUTONAMES0("Parent")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Ovals::SetParent(TAutoVal& val)
{
  AUTONAMES0("Parent")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Ovals::GetPlacement()
{
  AUTONAMES0("Placement")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Ovals::SetPlacement(TAutoVal& val)
{
  AUTONAMES0("Placement")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Ovals::GetPrintObject()
{
  AUTONAMES0("PrintObject")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Ovals::SetPrintObject(TAutoVal& val)
{
  AUTONAMES0("PrintObject")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Ovals::GetShadow()
{
  AUTONAMES0("Shadow")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Ovals::SetShadow(TAutoVal& val)
{
  AUTONAMES0("Shadow")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Ovals::GetTop()
{
  AUTONAMES0("Top")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Ovals::SetTop(TAutoVal& val)
{
  AUTONAMES0("Top")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Ovals::GetVisible()
{
  AUTONAMES0("Visible")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Ovals::SetVisible(TAutoVal& val)
{
  AUTONAMES0("Visible")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Ovals::GetWidth()
{
  AUTONAMES0("Width")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Ovals::SetWidth(TAutoVal& val)
{
  AUTONAMES0("Width")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Ovals::GetZOrder()
{
  AUTONAMES0("ZOrder")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Ovals::SetZOrder(TAutoVal& val)
{
  AUTONAMES0("ZOrder")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Ovals::_NewEnum()
{
  AUTONAMES0("_NewEnum")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Ovals::Add(TAutoVal& Left, TAutoVal& Top, TAutoVal& Width, TAutoVal& Height)
{
  AUTONAMES0("Add")
  AUTOARGS4(Left, Top, Width, Height)
  AUTOCALL_METHOD_RET
}

TAutoVal Ovals::Application()
{
  AUTONAMES0("Application")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Ovals::BringToFront()
{
  AUTONAMES0("BringToFront")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Ovals::Copy()
{
  AUTONAMES0("Copy")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Ovals::CopyPicture(TAutoVal& Appearance, TAutoVal& Format)
{
  AUTONAMES0("CopyPicture")
  AUTOARGS2(Appearance, Format)
  AUTOCALL_METHOD_RET
}

TAutoVal Ovals::Cut()
{
  AUTONAMES0("Cut")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Ovals::Delete()
{
  AUTONAMES0("Delete")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Ovals::Duplicate()
{
  AUTONAMES0("Duplicate")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Ovals::Group()
{
  AUTONAMES0("Group")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Ovals::Item(TAutoVal& Index)
{
  AUTONAMES0("Item")
  AUTOARGS1(Index)
  AUTOCALL_METHOD_RET
}

TAutoVal Ovals::Select(TAutoVal& Replace)
{
  AUTONAMES0("Select")
  AUTOARGS1(Replace)
  AUTOCALL_METHOD_RET
}

TAutoVal Ovals::SendToBack()
{
  AUTONAMES0("SendToBack")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}


// TKIND_DISPATCH: Arc {000208A0-0000-0000-C000-000000000046}\9

TAutoVal Arc::GetBorder()
{
  AUTONAMES0("Border")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Arc::SetBorder(TAutoVal& val)
{
  AUTONAMES0("Border")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Arc::GetBottomRightCell()
{
  AUTONAMES0("BottomRightCell")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Arc::SetBottomRightCell(TAutoVal& val)
{
  AUTONAMES0("BottomRightCell")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Arc::GetCreator()
{
  AUTONAMES0("Creator")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Arc::SetCreator(TAutoVal& val)
{
  AUTONAMES0("Creator")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Arc::GetEnabled()
{
  AUTONAMES0("Enabled")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Arc::SetEnabled(TAutoVal& val)
{
  AUTONAMES0("Enabled")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Arc::GetHeight()
{
  AUTONAMES0("Height")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Arc::SetHeight(TAutoVal& val)
{
  AUTONAMES0("Height")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Arc::GetIndex()
{
  AUTONAMES0("Index")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Arc::SetIndex(TAutoVal& val)
{
  AUTONAMES0("Index")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Arc::GetInterior()
{
  AUTONAMES0("Interior")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Arc::SetInterior(TAutoVal& val)
{
  AUTONAMES0("Interior")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Arc::GetLeft()
{
  AUTONAMES0("Left")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Arc::SetLeft(TAutoVal& val)
{
  AUTONAMES0("Left")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Arc::GetLocked()
{
  AUTONAMES0("Locked")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Arc::SetLocked(TAutoVal& val)
{
  AUTONAMES0("Locked")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Arc::GetName()
{
  AUTONAMES0("Name")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Arc::SetName(TAutoVal& val)
{
  AUTONAMES0("Name")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Arc::GetOnAction()
{
  AUTONAMES0("OnAction")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Arc::SetOnAction(TAutoVal& val)
{
  AUTONAMES0("OnAction")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Arc::GetParent()
{
  AUTONAMES0("Parent")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Arc::SetParent(TAutoVal& val)
{
  AUTONAMES0("Parent")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Arc::GetPlacement()
{
  AUTONAMES0("Placement")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Arc::SetPlacement(TAutoVal& val)
{
  AUTONAMES0("Placement")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Arc::GetPrintObject()
{
  AUTONAMES0("PrintObject")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Arc::SetPrintObject(TAutoVal& val)
{
  AUTONAMES0("PrintObject")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Arc::GetTop()
{
  AUTONAMES0("Top")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Arc::SetTop(TAutoVal& val)
{
  AUTONAMES0("Top")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Arc::GetTopLeftCell()
{
  AUTONAMES0("TopLeftCell")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Arc::SetTopLeftCell(TAutoVal& val)
{
  AUTONAMES0("TopLeftCell")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Arc::GetVisible()
{
  AUTONAMES0("Visible")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Arc::SetVisible(TAutoVal& val)
{
  AUTONAMES0("Visible")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Arc::GetWidth()
{
  AUTONAMES0("Width")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Arc::SetWidth(TAutoVal& val)
{
  AUTONAMES0("Width")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Arc::GetZOrder()
{
  AUTONAMES0("ZOrder")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Arc::SetZOrder(TAutoVal& val)
{
  AUTONAMES0("ZOrder")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Arc::Application()
{
  AUTONAMES0("Application")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Arc::BringToFront()
{
  AUTONAMES0("BringToFront")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Arc::Copy()
{
  AUTONAMES0("Copy")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Arc::CopyPicture(TAutoVal& Appearance, TAutoVal& Format)
{
  AUTONAMES0("CopyPicture")
  AUTOARGS2(Appearance, Format)
  AUTOCALL_METHOD_RET
}

TAutoVal Arc::Cut()
{
  AUTONAMES0("Cut")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Arc::Delete()
{
  AUTONAMES0("Delete")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Arc::Duplicate()
{
  AUTONAMES0("Duplicate")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Arc::Select(TAutoVal& Replace)
{
  AUTONAMES0("Select")
  AUTOARGS1(Replace)
  AUTOCALL_METHOD_RET
}

TAutoVal Arc::SendToBack()
{
  AUTONAMES0("SendToBack")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}


// TKIND_DISPATCH: Arcs {000208A1-0000-0000-C000-000000000046}\9

TAutoVal Arcs::GetBorder()
{
  AUTONAMES0("Border")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Arcs::SetBorder(TAutoVal& val)
{
  AUTONAMES0("Border")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Arcs::GetCount()
{
  AUTONAMES0("Count")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Arcs::SetCount(TAutoVal& val)
{
  AUTONAMES0("Count")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Arcs::GetCreator()
{
  AUTONAMES0("Creator")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Arcs::SetCreator(TAutoVal& val)
{
  AUTONAMES0("Creator")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Arcs::GetEnabled()
{
  AUTONAMES0("Enabled")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Arcs::SetEnabled(TAutoVal& val)
{
  AUTONAMES0("Enabled")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Arcs::GetHeight()
{
  AUTONAMES0("Height")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Arcs::SetHeight(TAutoVal& val)
{
  AUTONAMES0("Height")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Arcs::GetInterior()
{
  AUTONAMES0("Interior")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Arcs::SetInterior(TAutoVal& val)
{
  AUTONAMES0("Interior")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Arcs::GetLeft()
{
  AUTONAMES0("Left")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Arcs::SetLeft(TAutoVal& val)
{
  AUTONAMES0("Left")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Arcs::GetLocked()
{
  AUTONAMES0("Locked")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Arcs::SetLocked(TAutoVal& val)
{
  AUTONAMES0("Locked")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Arcs::GetOnAction()
{
  AUTONAMES0("OnAction")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Arcs::SetOnAction(TAutoVal& val)
{
  AUTONAMES0("OnAction")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Arcs::GetParent()
{
  AUTONAMES0("Parent")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Arcs::SetParent(TAutoVal& val)
{
  AUTONAMES0("Parent")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Arcs::GetPlacement()
{
  AUTONAMES0("Placement")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Arcs::SetPlacement(TAutoVal& val)
{
  AUTONAMES0("Placement")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Arcs::GetPrintObject()
{
  AUTONAMES0("PrintObject")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Arcs::SetPrintObject(TAutoVal& val)
{
  AUTONAMES0("PrintObject")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Arcs::GetTop()
{
  AUTONAMES0("Top")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Arcs::SetTop(TAutoVal& val)
{
  AUTONAMES0("Top")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Arcs::GetVisible()
{
  AUTONAMES0("Visible")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Arcs::SetVisible(TAutoVal& val)
{
  AUTONAMES0("Visible")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Arcs::GetWidth()
{
  AUTONAMES0("Width")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Arcs::SetWidth(TAutoVal& val)
{
  AUTONAMES0("Width")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Arcs::GetZOrder()
{
  AUTONAMES0("ZOrder")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Arcs::SetZOrder(TAutoVal& val)
{
  AUTONAMES0("ZOrder")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Arcs::_NewEnum()
{
  AUTONAMES0("_NewEnum")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Arcs::Add(TAutoVal& X1, TAutoVal& Y1, TAutoVal& X2, TAutoVal& Y2)
{
  AUTONAMES0("Add")
  AUTOARGS4(X1, Y1, X2, Y2)
  AUTOCALL_METHOD_RET
}

TAutoVal Arcs::Application()
{
  AUTONAMES0("Application")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Arcs::BringToFront()
{
  AUTONAMES0("BringToFront")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Arcs::Copy()
{
  AUTONAMES0("Copy")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Arcs::CopyPicture(TAutoVal& Appearance, TAutoVal& Format)
{
  AUTONAMES0("CopyPicture")
  AUTOARGS2(Appearance, Format)
  AUTOCALL_METHOD_RET
}

TAutoVal Arcs::Cut()
{
  AUTONAMES0("Cut")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Arcs::Delete()
{
  AUTONAMES0("Delete")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Arcs::Duplicate()
{
  AUTONAMES0("Duplicate")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Arcs::Group()
{
  AUTONAMES0("Group")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Arcs::Item(TAutoVal& Index)
{
  AUTONAMES0("Item")
  AUTOARGS1(Index)
  AUTOCALL_METHOD_RET
}

TAutoVal Arcs::Select(TAutoVal& Replace)
{
  AUTONAMES0("Select")
  AUTOARGS1(Replace)
  AUTOCALL_METHOD_RET
}

TAutoVal Arcs::SendToBack()
{
  AUTONAMES0("SendToBack")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}


// TKIND_DISPATCH: TextBox {000208A4-0000-0000-C000-000000000046}\9

TAutoVal TextBox::GetAddIndent()
{
  AUTONAMES0("AddIndent")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void TextBox::SetAddIndent(TAutoVal& val)
{
  AUTONAMES0("AddIndent")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal TextBox::GetAutoSize()
{
  AUTONAMES0("AutoSize")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void TextBox::SetAutoSize(TAutoVal& val)
{
  AUTONAMES0("AutoSize")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal TextBox::GetBorder()
{
  AUTONAMES0("Border")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void TextBox::SetBorder(TAutoVal& val)
{
  AUTONAMES0("Border")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal TextBox::GetBottomRightCell()
{
  AUTONAMES0("BottomRightCell")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void TextBox::SetBottomRightCell(TAutoVal& val)
{
  AUTONAMES0("BottomRightCell")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal TextBox::GetCaption()
{
  AUTONAMES0("Caption")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void TextBox::SetCaption(TAutoVal& val)
{
  AUTONAMES0("Caption")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal TextBox::GetCreator()
{
  AUTONAMES0("Creator")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void TextBox::SetCreator(TAutoVal& val)
{
  AUTONAMES0("Creator")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal TextBox::GetEnabled()
{
  AUTONAMES0("Enabled")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void TextBox::SetEnabled(TAutoVal& val)
{
  AUTONAMES0("Enabled")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal TextBox::GetFont()
{
  AUTONAMES0("Font")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void TextBox::SetFont(TAutoVal& val)
{
  AUTONAMES0("Font")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal TextBox::GetFormula()
{
  AUTONAMES0("Formula")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void TextBox::SetFormula(TAutoVal& val)
{
  AUTONAMES0("Formula")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal TextBox::GetHeight()
{
  AUTONAMES0("Height")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void TextBox::SetHeight(TAutoVal& val)
{
  AUTONAMES0("Height")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal TextBox::GetHorizontalAlignment()
{
  AUTONAMES0("HorizontalAlignment")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void TextBox::SetHorizontalAlignment(TAutoVal& val)
{
  AUTONAMES0("HorizontalAlignment")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal TextBox::GetIndex()
{
  AUTONAMES0("Index")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void TextBox::SetIndex(TAutoVal& val)
{
  AUTONAMES0("Index")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal TextBox::GetInterior()
{
  AUTONAMES0("Interior")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void TextBox::SetInterior(TAutoVal& val)
{
  AUTONAMES0("Interior")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal TextBox::GetLeft()
{
  AUTONAMES0("Left")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void TextBox::SetLeft(TAutoVal& val)
{
  AUTONAMES0("Left")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal TextBox::GetLocked()
{
  AUTONAMES0("Locked")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void TextBox::SetLocked(TAutoVal& val)
{
  AUTONAMES0("Locked")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal TextBox::GetLockedText()
{
  AUTONAMES0("LockedText")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void TextBox::SetLockedText(TAutoVal& val)
{
  AUTONAMES0("LockedText")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal TextBox::GetName()
{
  AUTONAMES0("Name")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void TextBox::SetName(TAutoVal& val)
{
  AUTONAMES0("Name")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal TextBox::GetOnAction()
{
  AUTONAMES0("OnAction")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void TextBox::SetOnAction(TAutoVal& val)
{
  AUTONAMES0("OnAction")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal TextBox::GetOrientation()
{
  AUTONAMES0("Orientation")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void TextBox::SetOrientation(TAutoVal& val)
{
  AUTONAMES0("Orientation")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal TextBox::GetParent()
{
  AUTONAMES0("Parent")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void TextBox::SetParent(TAutoVal& val)
{
  AUTONAMES0("Parent")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal TextBox::GetPlacement()
{
  AUTONAMES0("Placement")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void TextBox::SetPlacement(TAutoVal& val)
{
  AUTONAMES0("Placement")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal TextBox::GetPrintObject()
{
  AUTONAMES0("PrintObject")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void TextBox::SetPrintObject(TAutoVal& val)
{
  AUTONAMES0("PrintObject")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal TextBox::GetRoundedCorners()
{
  AUTONAMES0("RoundedCorners")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void TextBox::SetRoundedCorners(TAutoVal& val)
{
  AUTONAMES0("RoundedCorners")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal TextBox::GetShadow()
{
  AUTONAMES0("Shadow")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void TextBox::SetShadow(TAutoVal& val)
{
  AUTONAMES0("Shadow")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal TextBox::GetText()
{
  AUTONAMES0("Text")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void TextBox::SetText(TAutoVal& val)
{
  AUTONAMES0("Text")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal TextBox::GetTop()
{
  AUTONAMES0("Top")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void TextBox::SetTop(TAutoVal& val)
{
  AUTONAMES0("Top")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal TextBox::GetTopLeftCell()
{
  AUTONAMES0("TopLeftCell")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void TextBox::SetTopLeftCell(TAutoVal& val)
{
  AUTONAMES0("TopLeftCell")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal TextBox::GetVerticalAlignment()
{
  AUTONAMES0("VerticalAlignment")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void TextBox::SetVerticalAlignment(TAutoVal& val)
{
  AUTONAMES0("VerticalAlignment")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal TextBox::GetVisible()
{
  AUTONAMES0("Visible")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void TextBox::SetVisible(TAutoVal& val)
{
  AUTONAMES0("Visible")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal TextBox::GetWidth()
{
  AUTONAMES0("Width")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void TextBox::SetWidth(TAutoVal& val)
{
  AUTONAMES0("Width")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal TextBox::GetZOrder()
{
  AUTONAMES0("ZOrder")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void TextBox::SetZOrder(TAutoVal& val)
{
  AUTONAMES0("ZOrder")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal TextBox::Application()
{
  AUTONAMES0("Application")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal TextBox::BringToFront()
{
  AUTONAMES0("BringToFront")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal TextBox::Characters(TAutoVal& Start, TAutoVal& Length)
{
  AUTONAMES0("Characters")
  AUTOARGS2(Start, Length)
  AUTOCALL_METHOD_RET
}

TAutoVal TextBox::CheckSpelling(TAutoVal& CustomDictionary, TAutoVal& IgnoreUppercase, TAutoVal& AlwaysSuggest)
{
  AUTONAMES0("CheckSpelling")
  AUTOARGS3(CustomDictionary, IgnoreUppercase, AlwaysSuggest)
  AUTOCALL_METHOD_RET
}

TAutoVal TextBox::Copy()
{
  AUTONAMES0("Copy")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal TextBox::CopyPicture(TAutoVal& Appearance, TAutoVal& Format)
{
  AUTONAMES0("CopyPicture")
  AUTOARGS2(Appearance, Format)
  AUTOCALL_METHOD_RET
}

TAutoVal TextBox::Cut()
{
  AUTONAMES0("Cut")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal TextBox::Delete()
{
  AUTONAMES0("Delete")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal TextBox::Duplicate()
{
  AUTONAMES0("Duplicate")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal TextBox::Select(TAutoVal& Replace)
{
  AUTONAMES0("Select")
  AUTOARGS1(Replace)
  AUTOCALL_METHOD_RET
}

TAutoVal TextBox::SendToBack()
{
  AUTONAMES0("SendToBack")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}


// TKIND_DISPATCH: TextBoxes {000208A5-0000-0000-C000-000000000046}\9

TAutoVal TextBoxes::GetAddIndent()
{
  AUTONAMES0("AddIndent")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void TextBoxes::SetAddIndent(TAutoVal& val)
{
  AUTONAMES0("AddIndent")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal TextBoxes::GetAutoSize()
{
  AUTONAMES0("AutoSize")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void TextBoxes::SetAutoSize(TAutoVal& val)
{
  AUTONAMES0("AutoSize")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal TextBoxes::GetBorder()
{
  AUTONAMES0("Border")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void TextBoxes::SetBorder(TAutoVal& val)
{
  AUTONAMES0("Border")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal TextBoxes::GetCaption()
{
  AUTONAMES0("Caption")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void TextBoxes::SetCaption(TAutoVal& val)
{
  AUTONAMES0("Caption")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal TextBoxes::GetCount()
{
  AUTONAMES0("Count")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void TextBoxes::SetCount(TAutoVal& val)
{
  AUTONAMES0("Count")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal TextBoxes::GetCreator()
{
  AUTONAMES0("Creator")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void TextBoxes::SetCreator(TAutoVal& val)
{
  AUTONAMES0("Creator")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal TextBoxes::GetEnabled()
{
  AUTONAMES0("Enabled")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void TextBoxes::SetEnabled(TAutoVal& val)
{
  AUTONAMES0("Enabled")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal TextBoxes::GetFont()
{
  AUTONAMES0("Font")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void TextBoxes::SetFont(TAutoVal& val)
{
  AUTONAMES0("Font")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal TextBoxes::GetFormula()
{
  AUTONAMES0("Formula")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void TextBoxes::SetFormula(TAutoVal& val)
{
  AUTONAMES0("Formula")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal TextBoxes::GetHeight()
{
  AUTONAMES0("Height")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void TextBoxes::SetHeight(TAutoVal& val)
{
  AUTONAMES0("Height")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal TextBoxes::GetHorizontalAlignment()
{
  AUTONAMES0("HorizontalAlignment")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void TextBoxes::SetHorizontalAlignment(TAutoVal& val)
{
  AUTONAMES0("HorizontalAlignment")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal TextBoxes::GetInterior()
{
  AUTONAMES0("Interior")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void TextBoxes::SetInterior(TAutoVal& val)
{
  AUTONAMES0("Interior")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal TextBoxes::GetLeft()
{
  AUTONAMES0("Left")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void TextBoxes::SetLeft(TAutoVal& val)
{
  AUTONAMES0("Left")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal TextBoxes::GetLocked()
{
  AUTONAMES0("Locked")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void TextBoxes::SetLocked(TAutoVal& val)
{
  AUTONAMES0("Locked")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal TextBoxes::GetLockedText()
{
  AUTONAMES0("LockedText")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void TextBoxes::SetLockedText(TAutoVal& val)
{
  AUTONAMES0("LockedText")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal TextBoxes::GetOnAction()
{
  AUTONAMES0("OnAction")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void TextBoxes::SetOnAction(TAutoVal& val)
{
  AUTONAMES0("OnAction")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal TextBoxes::GetOrientation()
{
  AUTONAMES0("Orientation")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void TextBoxes::SetOrientation(TAutoVal& val)
{
  AUTONAMES0("Orientation")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal TextBoxes::GetParent()
{
  AUTONAMES0("Parent")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void TextBoxes::SetParent(TAutoVal& val)
{
  AUTONAMES0("Parent")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal TextBoxes::GetPlacement()
{
  AUTONAMES0("Placement")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void TextBoxes::SetPlacement(TAutoVal& val)
{
  AUTONAMES0("Placement")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal TextBoxes::GetPrintObject()
{
  AUTONAMES0("PrintObject")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void TextBoxes::SetPrintObject(TAutoVal& val)
{
  AUTONAMES0("PrintObject")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal TextBoxes::GetRoundedCorners()
{
  AUTONAMES0("RoundedCorners")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void TextBoxes::SetRoundedCorners(TAutoVal& val)
{
  AUTONAMES0("RoundedCorners")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal TextBoxes::GetShadow()
{
  AUTONAMES0("Shadow")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void TextBoxes::SetShadow(TAutoVal& val)
{
  AUTONAMES0("Shadow")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal TextBoxes::GetText()
{
  AUTONAMES0("Text")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void TextBoxes::SetText(TAutoVal& val)
{
  AUTONAMES0("Text")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal TextBoxes::GetTop()
{
  AUTONAMES0("Top")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void TextBoxes::SetTop(TAutoVal& val)
{
  AUTONAMES0("Top")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal TextBoxes::GetVerticalAlignment()
{
  AUTONAMES0("VerticalAlignment")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void TextBoxes::SetVerticalAlignment(TAutoVal& val)
{
  AUTONAMES0("VerticalAlignment")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal TextBoxes::GetVisible()
{
  AUTONAMES0("Visible")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void TextBoxes::SetVisible(TAutoVal& val)
{
  AUTONAMES0("Visible")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal TextBoxes::GetWidth()
{
  AUTONAMES0("Width")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void TextBoxes::SetWidth(TAutoVal& val)
{
  AUTONAMES0("Width")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal TextBoxes::GetZOrder()
{
  AUTONAMES0("ZOrder")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void TextBoxes::SetZOrder(TAutoVal& val)
{
  AUTONAMES0("ZOrder")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal TextBoxes::_NewEnum()
{
  AUTONAMES0("_NewEnum")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal TextBoxes::Add(TAutoVal& Left, TAutoVal& Top, TAutoVal& Width, TAutoVal& Height)
{
  AUTONAMES0("Add")
  AUTOARGS4(Left, Top, Width, Height)
  AUTOCALL_METHOD_RET
}

TAutoVal TextBoxes::Application()
{
  AUTONAMES0("Application")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal TextBoxes::BringToFront()
{
  AUTONAMES0("BringToFront")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal TextBoxes::Characters(TAutoVal& Start, TAutoVal& Length)
{
  AUTONAMES0("Characters")
  AUTOARGS2(Start, Length)
  AUTOCALL_METHOD_RET
}

TAutoVal TextBoxes::CheckSpelling(TAutoVal& CustomDictionary, TAutoVal& IgnoreUppercase, TAutoVal& AlwaysSuggest)
{
  AUTONAMES0("CheckSpelling")
  AUTOARGS3(CustomDictionary, IgnoreUppercase, AlwaysSuggest)
  AUTOCALL_METHOD_RET
}

TAutoVal TextBoxes::Copy()
{
  AUTONAMES0("Copy")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal TextBoxes::CopyPicture(TAutoVal& Appearance, TAutoVal& Format)
{
  AUTONAMES0("CopyPicture")
  AUTOARGS2(Appearance, Format)
  AUTOCALL_METHOD_RET
}

TAutoVal TextBoxes::Cut()
{
  AUTONAMES0("Cut")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal TextBoxes::Delete()
{
  AUTONAMES0("Delete")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal TextBoxes::Duplicate()
{
  AUTONAMES0("Duplicate")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal TextBoxes::Group()
{
  AUTONAMES0("Group")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal TextBoxes::Item(TAutoVal& Index)
{
  AUTONAMES0("Item")
  AUTOARGS1(Index)
  AUTOCALL_METHOD_RET
}

TAutoVal TextBoxes::Select(TAutoVal& Replace)
{
  AUTONAMES0("Select")
  AUTOARGS1(Replace)
  AUTOCALL_METHOD_RET
}

TAutoVal TextBoxes::SendToBack()
{
  AUTONAMES0("SendToBack")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}


// TKIND_DISPATCH: Picture {000208A6-0000-0000-C000-000000000046}\9

TAutoVal Picture::GetBorder()
{
  AUTONAMES0("Border")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Picture::SetBorder(TAutoVal& val)
{
  AUTONAMES0("Border")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Picture::GetBottomRightCell()
{
  AUTONAMES0("BottomRightCell")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Picture::SetBottomRightCell(TAutoVal& val)
{
  AUTONAMES0("BottomRightCell")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Picture::GetCreator()
{
  AUTONAMES0("Creator")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Picture::SetCreator(TAutoVal& val)
{
  AUTONAMES0("Creator")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Picture::GetEnabled()
{
  AUTONAMES0("Enabled")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Picture::SetEnabled(TAutoVal& val)
{
  AUTONAMES0("Enabled")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Picture::GetFormula()
{
  AUTONAMES0("Formula")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Picture::SetFormula(TAutoVal& val)
{
  AUTONAMES0("Formula")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Picture::GetHeight()
{
  AUTONAMES0("Height")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Picture::SetHeight(TAutoVal& val)
{
  AUTONAMES0("Height")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Picture::GetIndex()
{
  AUTONAMES0("Index")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Picture::SetIndex(TAutoVal& val)
{
  AUTONAMES0("Index")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Picture::GetInterior()
{
  AUTONAMES0("Interior")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Picture::SetInterior(TAutoVal& val)
{
  AUTONAMES0("Interior")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Picture::GetLeft()
{
  AUTONAMES0("Left")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Picture::SetLeft(TAutoVal& val)
{
  AUTONAMES0("Left")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Picture::GetLocked()
{
  AUTONAMES0("Locked")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Picture::SetLocked(TAutoVal& val)
{
  AUTONAMES0("Locked")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Picture::GetName()
{
  AUTONAMES0("Name")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Picture::SetName(TAutoVal& val)
{
  AUTONAMES0("Name")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Picture::GetOnAction()
{
  AUTONAMES0("OnAction")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Picture::SetOnAction(TAutoVal& val)
{
  AUTONAMES0("OnAction")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Picture::GetParent()
{
  AUTONAMES0("Parent")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Picture::SetParent(TAutoVal& val)
{
  AUTONAMES0("Parent")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Picture::GetPlacement()
{
  AUTONAMES0("Placement")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Picture::SetPlacement(TAutoVal& val)
{
  AUTONAMES0("Placement")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Picture::GetPrintObject()
{
  AUTONAMES0("PrintObject")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Picture::SetPrintObject(TAutoVal& val)
{
  AUTONAMES0("PrintObject")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Picture::GetShadow()
{
  AUTONAMES0("Shadow")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Picture::SetShadow(TAutoVal& val)
{
  AUTONAMES0("Shadow")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Picture::GetTop()
{
  AUTONAMES0("Top")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Picture::SetTop(TAutoVal& val)
{
  AUTONAMES0("Top")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Picture::GetTopLeftCell()
{
  AUTONAMES0("TopLeftCell")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Picture::SetTopLeftCell(TAutoVal& val)
{
  AUTONAMES0("TopLeftCell")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Picture::GetVisible()
{
  AUTONAMES0("Visible")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Picture::SetVisible(TAutoVal& val)
{
  AUTONAMES0("Visible")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Picture::GetWidth()
{
  AUTONAMES0("Width")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Picture::SetWidth(TAutoVal& val)
{
  AUTONAMES0("Width")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Picture::GetZOrder()
{
  AUTONAMES0("ZOrder")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Picture::SetZOrder(TAutoVal& val)
{
  AUTONAMES0("ZOrder")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Picture::Application()
{
  AUTONAMES0("Application")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Picture::BringToFront()
{
  AUTONAMES0("BringToFront")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Picture::Copy()
{
  AUTONAMES0("Copy")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Picture::CopyPicture(TAutoVal& Appearance, TAutoVal& Format)
{
  AUTONAMES0("CopyPicture")
  AUTOARGS2(Appearance, Format)
  AUTOCALL_METHOD_RET
}

TAutoVal Picture::Cut()
{
  AUTONAMES0("Cut")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Picture::Delete()
{
  AUTONAMES0("Delete")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Picture::Duplicate()
{
  AUTONAMES0("Duplicate")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Picture::Select(TAutoVal& Replace)
{
  AUTONAMES0("Select")
  AUTOARGS1(Replace)
  AUTOCALL_METHOD_RET
}

TAutoVal Picture::SendToBack()
{
  AUTONAMES0("SendToBack")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}


// TKIND_DISPATCH: Pictures {000208A7-0000-0000-C000-000000000046}\9

TAutoVal Pictures::GetBorder()
{
  AUTONAMES0("Border")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Pictures::SetBorder(TAutoVal& val)
{
  AUTONAMES0("Border")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Pictures::GetCount()
{
  AUTONAMES0("Count")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Pictures::SetCount(TAutoVal& val)
{
  AUTONAMES0("Count")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Pictures::GetCreator()
{
  AUTONAMES0("Creator")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Pictures::SetCreator(TAutoVal& val)
{
  AUTONAMES0("Creator")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Pictures::GetEnabled()
{
  AUTONAMES0("Enabled")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Pictures::SetEnabled(TAutoVal& val)
{
  AUTONAMES0("Enabled")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Pictures::GetFormula()
{
  AUTONAMES0("Formula")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Pictures::SetFormula(TAutoVal& val)
{
  AUTONAMES0("Formula")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Pictures::GetHeight()
{
  AUTONAMES0("Height")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Pictures::SetHeight(TAutoVal& val)
{
  AUTONAMES0("Height")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Pictures::GetInterior()
{
  AUTONAMES0("Interior")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Pictures::SetInterior(TAutoVal& val)
{
  AUTONAMES0("Interior")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Pictures::GetLeft()
{
  AUTONAMES0("Left")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Pictures::SetLeft(TAutoVal& val)
{
  AUTONAMES0("Left")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Pictures::GetLocked()
{
  AUTONAMES0("Locked")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Pictures::SetLocked(TAutoVal& val)
{
  AUTONAMES0("Locked")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Pictures::GetOnAction()
{
  AUTONAMES0("OnAction")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Pictures::SetOnAction(TAutoVal& val)
{
  AUTONAMES0("OnAction")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Pictures::GetParent()
{
  AUTONAMES0("Parent")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Pictures::SetParent(TAutoVal& val)
{
  AUTONAMES0("Parent")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Pictures::GetPlacement()
{
  AUTONAMES0("Placement")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Pictures::SetPlacement(TAutoVal& val)
{
  AUTONAMES0("Placement")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Pictures::GetPrintObject()
{
  AUTONAMES0("PrintObject")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Pictures::SetPrintObject(TAutoVal& val)
{
  AUTONAMES0("PrintObject")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Pictures::GetShadow()
{
  AUTONAMES0("Shadow")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Pictures::SetShadow(TAutoVal& val)
{
  AUTONAMES0("Shadow")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Pictures::GetTop()
{
  AUTONAMES0("Top")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Pictures::SetTop(TAutoVal& val)
{
  AUTONAMES0("Top")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Pictures::GetVisible()
{
  AUTONAMES0("Visible")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Pictures::SetVisible(TAutoVal& val)
{
  AUTONAMES0("Visible")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Pictures::GetWidth()
{
  AUTONAMES0("Width")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Pictures::SetWidth(TAutoVal& val)
{
  AUTONAMES0("Width")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Pictures::GetZOrder()
{
  AUTONAMES0("ZOrder")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Pictures::SetZOrder(TAutoVal& val)
{
  AUTONAMES0("ZOrder")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Pictures::_NewEnum()
{
  AUTONAMES0("_NewEnum")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Pictures::Add(TAutoVal& Left, TAutoVal& Top, TAutoVal& Width, TAutoVal& Height)
{
  AUTONAMES0("Add")
  AUTOARGS4(Left, Top, Width, Height)
  AUTOCALL_METHOD_RET
}

TAutoVal Pictures::Application()
{
  AUTONAMES0("Application")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Pictures::BringToFront()
{
  AUTONAMES0("BringToFront")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Pictures::Copy()
{
  AUTONAMES0("Copy")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Pictures::CopyPicture(TAutoVal& Appearance, TAutoVal& Format)
{
  AUTONAMES0("CopyPicture")
  AUTOARGS2(Appearance, Format)
  AUTOCALL_METHOD_RET
}

TAutoVal Pictures::Cut()
{
  AUTONAMES0("Cut")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Pictures::Delete()
{
  AUTONAMES0("Delete")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Pictures::Duplicate()
{
  AUTONAMES0("Duplicate")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Pictures::Group()
{
  AUTONAMES0("Group")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Pictures::Insert(TAutoVal& Filename, TAutoVal& Converter)
{
  AUTONAMES0("Insert")
  AUTOARGS2(Filename, Converter)
  AUTOCALL_METHOD_RET
}

TAutoVal Pictures::Item(TAutoVal& Index)
{
  AUTONAMES0("Item")
  AUTOARGS1(Index)
  AUTOCALL_METHOD_RET
}

TAutoVal Pictures::Paste(TAutoVal& Link)
{
  AUTONAMES0("Paste")
  AUTOARGS1(Link)
  AUTOCALL_METHOD_RET
}

TAutoVal Pictures::Select(TAutoVal& Replace)
{
  AUTONAMES0("Select")
  AUTOARGS1(Replace)
  AUTOCALL_METHOD_RET
}

TAutoVal Pictures::SendToBack()
{
  AUTONAMES0("SendToBack")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}


// TKIND_DISPATCH: OLEObject {000208A2-0000-0000-C000-000000000046}\9

TAutoVal OLEObject::GetAutoLoad()
{
  AUTONAMES0("AutoLoad")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void OLEObject::SetAutoLoad(TAutoVal& val)
{
  AUTONAMES0("AutoLoad")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal OLEObject::GetAutoUpdate()
{
  AUTONAMES0("AutoUpdate")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void OLEObject::SetAutoUpdate(TAutoVal& val)
{
  AUTONAMES0("AutoUpdate")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal OLEObject::GetBorder()
{
  AUTONAMES0("Border")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void OLEObject::SetBorder(TAutoVal& val)
{
  AUTONAMES0("Border")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal OLEObject::GetBottomRightCell()
{
  AUTONAMES0("BottomRightCell")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void OLEObject::SetBottomRightCell(TAutoVal& val)
{
  AUTONAMES0("BottomRightCell")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal OLEObject::GetCreator()
{
  AUTONAMES0("Creator")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void OLEObject::SetCreator(TAutoVal& val)
{
  AUTONAMES0("Creator")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal OLEObject::GetEnabled()
{
  AUTONAMES0("Enabled")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void OLEObject::SetEnabled(TAutoVal& val)
{
  AUTONAMES0("Enabled")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal OLEObject::GetHeight()
{
  AUTONAMES0("Height")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void OLEObject::SetHeight(TAutoVal& val)
{
  AUTONAMES0("Height")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal OLEObject::GetIndex()
{
  AUTONAMES0("Index")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void OLEObject::SetIndex(TAutoVal& val)
{
  AUTONAMES0("Index")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal OLEObject::GetInterior()
{
  AUTONAMES0("Interior")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void OLEObject::SetInterior(TAutoVal& val)
{
  AUTONAMES0("Interior")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal OLEObject::GetLeft()
{
  AUTONAMES0("Left")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void OLEObject::SetLeft(TAutoVal& val)
{
  AUTONAMES0("Left")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal OLEObject::GetLocked()
{
  AUTONAMES0("Locked")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void OLEObject::SetLocked(TAutoVal& val)
{
  AUTONAMES0("Locked")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal OLEObject::GetName()
{
  AUTONAMES0("Name")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void OLEObject::SetName(TAutoVal& val)
{
  AUTONAMES0("Name")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal OLEObject::GetObject()
{
  AUTONAMES0("Object")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void OLEObject::SetObject(TAutoVal& val)
{
  AUTONAMES0("Object")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal OLEObject::GetOLEType()
{
  AUTONAMES0("OLEType")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void OLEObject::SetOLEType(TAutoVal& val)
{
  AUTONAMES0("OLEType")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal OLEObject::GetOnAction()
{
  AUTONAMES0("OnAction")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void OLEObject::SetOnAction(TAutoVal& val)
{
  AUTONAMES0("OnAction")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal OLEObject::GetParent()
{
  AUTONAMES0("Parent")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void OLEObject::SetParent(TAutoVal& val)
{
  AUTONAMES0("Parent")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal OLEObject::GetPlacement()
{
  AUTONAMES0("Placement")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void OLEObject::SetPlacement(TAutoVal& val)
{
  AUTONAMES0("Placement")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal OLEObject::GetPrintObject()
{
  AUTONAMES0("PrintObject")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void OLEObject::SetPrintObject(TAutoVal& val)
{
  AUTONAMES0("PrintObject")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal OLEObject::GetShadow()
{
  AUTONAMES0("Shadow")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void OLEObject::SetShadow(TAutoVal& val)
{
  AUTONAMES0("Shadow")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal OLEObject::GetTop()
{
  AUTONAMES0("Top")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void OLEObject::SetTop(TAutoVal& val)
{
  AUTONAMES0("Top")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal OLEObject::GetTopLeftCell()
{
  AUTONAMES0("TopLeftCell")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void OLEObject::SetTopLeftCell(TAutoVal& val)
{
  AUTONAMES0("TopLeftCell")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal OLEObject::GetVisible()
{
  AUTONAMES0("Visible")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void OLEObject::SetVisible(TAutoVal& val)
{
  AUTONAMES0("Visible")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal OLEObject::GetWidth()
{
  AUTONAMES0("Width")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void OLEObject::SetWidth(TAutoVal& val)
{
  AUTONAMES0("Width")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal OLEObject::GetZOrder()
{
  AUTONAMES0("ZOrder")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void OLEObject::SetZOrder(TAutoVal& val)
{
  AUTONAMES0("ZOrder")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal OLEObject::Activate()
{
  AUTONAMES0("Activate")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal OLEObject::Application()
{
  AUTONAMES0("Application")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal OLEObject::BringToFront()
{
  AUTONAMES0("BringToFront")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal OLEObject::Copy()
{
  AUTONAMES0("Copy")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal OLEObject::CopyPicture(TAutoVal& Appearance, TAutoVal& Format)
{
  AUTONAMES0("CopyPicture")
  AUTOARGS2(Appearance, Format)
  AUTOCALL_METHOD_RET
}

TAutoVal OLEObject::Cut()
{
  AUTONAMES0("Cut")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal OLEObject::Delete()
{
  AUTONAMES0("Delete")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal OLEObject::Duplicate()
{
  AUTONAMES0("Duplicate")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal OLEObject::Select(TAutoVal& Replace)
{
  AUTONAMES0("Select")
  AUTOARGS1(Replace)
  AUTOCALL_METHOD_RET
}

TAutoVal OLEObject::SendToBack()
{
  AUTONAMES0("SendToBack")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal OLEObject::Update()
{
  AUTONAMES0("Update")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal OLEObject::Verb(TAutoVal& Verb)
{
  AUTONAMES0("Verb")
  AUTOARGS1(Verb)
  AUTOCALL_METHOD_RET
}


// TKIND_DISPATCH: OLEObjects {000208A3-0000-0000-C000-000000000046}\9

TAutoVal OLEObjects::GetBorder()
{
  AUTONAMES0("Border")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void OLEObjects::SetBorder(TAutoVal& val)
{
  AUTONAMES0("Border")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal OLEObjects::GetCount()
{
  AUTONAMES0("Count")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void OLEObjects::SetCount(TAutoVal& val)
{
  AUTONAMES0("Count")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal OLEObjects::GetCreator()
{
  AUTONAMES0("Creator")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void OLEObjects::SetCreator(TAutoVal& val)
{
  AUTONAMES0("Creator")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal OLEObjects::GetEnabled()
{
  AUTONAMES0("Enabled")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void OLEObjects::SetEnabled(TAutoVal& val)
{
  AUTONAMES0("Enabled")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal OLEObjects::GetHeight()
{
  AUTONAMES0("Height")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void OLEObjects::SetHeight(TAutoVal& val)
{
  AUTONAMES0("Height")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal OLEObjects::GetInterior()
{
  AUTONAMES0("Interior")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void OLEObjects::SetInterior(TAutoVal& val)
{
  AUTONAMES0("Interior")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal OLEObjects::GetLeft()
{
  AUTONAMES0("Left")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void OLEObjects::SetLeft(TAutoVal& val)
{
  AUTONAMES0("Left")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal OLEObjects::GetLocked()
{
  AUTONAMES0("Locked")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void OLEObjects::SetLocked(TAutoVal& val)
{
  AUTONAMES0("Locked")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal OLEObjects::GetOnAction()
{
  AUTONAMES0("OnAction")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void OLEObjects::SetOnAction(TAutoVal& val)
{
  AUTONAMES0("OnAction")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal OLEObjects::GetParent()
{
  AUTONAMES0("Parent")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void OLEObjects::SetParent(TAutoVal& val)
{
  AUTONAMES0("Parent")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal OLEObjects::GetPlacement()
{
  AUTONAMES0("Placement")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void OLEObjects::SetPlacement(TAutoVal& val)
{
  AUTONAMES0("Placement")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal OLEObjects::GetPrintObject()
{
  AUTONAMES0("PrintObject")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void OLEObjects::SetPrintObject(TAutoVal& val)
{
  AUTONAMES0("PrintObject")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal OLEObjects::GetShadow()
{
  AUTONAMES0("Shadow")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void OLEObjects::SetShadow(TAutoVal& val)
{
  AUTONAMES0("Shadow")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal OLEObjects::GetTop()
{
  AUTONAMES0("Top")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void OLEObjects::SetTop(TAutoVal& val)
{
  AUTONAMES0("Top")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal OLEObjects::GetVisible()
{
  AUTONAMES0("Visible")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void OLEObjects::SetVisible(TAutoVal& val)
{
  AUTONAMES0("Visible")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal OLEObjects::GetWidth()
{
  AUTONAMES0("Width")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void OLEObjects::SetWidth(TAutoVal& val)
{
  AUTONAMES0("Width")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal OLEObjects::GetZOrder()
{
  AUTONAMES0("ZOrder")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void OLEObjects::SetZOrder(TAutoVal& val)
{
  AUTONAMES0("ZOrder")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal OLEObjects::_NewEnum()
{
  AUTONAMES0("_NewEnum")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal OLEObjects::Add(TAutoVal& ClassType, TAutoVal& Filename, TAutoVal& Link, TAutoVal& DisplayAsIcon, TAutoVal& IconFileName, TAutoVal& IconIndex, TAutoVal& IconLabel)
{
  AUTONAMES0("Add")
  AUTOARGS7(ClassType, Filename, Link, DisplayAsIcon, IconFileName, IconIndex, IconLabel)
  AUTOCALL_METHOD_RET
}

TAutoVal OLEObjects::Application()
{
  AUTONAMES0("Application")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal OLEObjects::BringToFront()
{
  AUTONAMES0("BringToFront")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal OLEObjects::Copy()
{
  AUTONAMES0("Copy")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal OLEObjects::CopyPicture(TAutoVal& Appearance, TAutoVal& Format)
{
  AUTONAMES0("CopyPicture")
  AUTOARGS2(Appearance, Format)
  AUTOCALL_METHOD_RET
}

TAutoVal OLEObjects::Cut()
{
  AUTONAMES0("Cut")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal OLEObjects::Delete()
{
  AUTONAMES0("Delete")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal OLEObjects::Duplicate()
{
  AUTONAMES0("Duplicate")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal OLEObjects::Group()
{
  AUTONAMES0("Group")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal OLEObjects::Item(TAutoVal& Index)
{
  AUTONAMES0("Item")
  AUTOARGS1(Index)
  AUTOCALL_METHOD_RET
}

TAutoVal OLEObjects::Select(TAutoVal& Replace)
{
  AUTONAMES0("Select")
  AUTOARGS1(Replace)
  AUTOCALL_METHOD_RET
}

TAutoVal OLEObjects::SendToBack()
{
  AUTONAMES0("SendToBack")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}


// TKIND_DISPATCH: ChartObject {000208CF-0000-0000-C000-000000000046}\9

TAutoVal ChartObject::GetBorder()
{
  AUTONAMES0("Border")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void ChartObject::SetBorder(TAutoVal& val)
{
  AUTONAMES0("Border")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal ChartObject::GetBottomRightCell()
{
  AUTONAMES0("BottomRightCell")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void ChartObject::SetBottomRightCell(TAutoVal& val)
{
  AUTONAMES0("BottomRightCell")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal ChartObject::GetChart()
{
  AUTONAMES0("Chart")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void ChartObject::SetChart(TAutoVal& val)
{
  AUTONAMES0("Chart")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal ChartObject::GetCreator()
{
  AUTONAMES0("Creator")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void ChartObject::SetCreator(TAutoVal& val)
{
  AUTONAMES0("Creator")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal ChartObject::GetEnabled()
{
  AUTONAMES0("Enabled")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void ChartObject::SetEnabled(TAutoVal& val)
{
  AUTONAMES0("Enabled")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal ChartObject::GetHeight()
{
  AUTONAMES0("Height")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void ChartObject::SetHeight(TAutoVal& val)
{
  AUTONAMES0("Height")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal ChartObject::GetIndex()
{
  AUTONAMES0("Index")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void ChartObject::SetIndex(TAutoVal& val)
{
  AUTONAMES0("Index")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal ChartObject::GetInterior()
{
  AUTONAMES0("Interior")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void ChartObject::SetInterior(TAutoVal& val)
{
  AUTONAMES0("Interior")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal ChartObject::GetLeft()
{
  AUTONAMES0("Left")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void ChartObject::SetLeft(TAutoVal& val)
{
  AUTONAMES0("Left")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal ChartObject::GetLocked()
{
  AUTONAMES0("Locked")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void ChartObject::SetLocked(TAutoVal& val)
{
  AUTONAMES0("Locked")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal ChartObject::GetName()
{
  AUTONAMES0("Name")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void ChartObject::SetName(TAutoVal& val)
{
  AUTONAMES0("Name")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal ChartObject::GetOnAction()
{
  AUTONAMES0("OnAction")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void ChartObject::SetOnAction(TAutoVal& val)
{
  AUTONAMES0("OnAction")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal ChartObject::GetParent()
{
  AUTONAMES0("Parent")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void ChartObject::SetParent(TAutoVal& val)
{
  AUTONAMES0("Parent")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal ChartObject::GetPlacement()
{
  AUTONAMES0("Placement")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void ChartObject::SetPlacement(TAutoVal& val)
{
  AUTONAMES0("Placement")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal ChartObject::GetPrintObject()
{
  AUTONAMES0("PrintObject")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void ChartObject::SetPrintObject(TAutoVal& val)
{
  AUTONAMES0("PrintObject")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal ChartObject::GetRoundedCorners()
{
  AUTONAMES0("RoundedCorners")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void ChartObject::SetRoundedCorners(TAutoVal& val)
{
  AUTONAMES0("RoundedCorners")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal ChartObject::GetShadow()
{
  AUTONAMES0("Shadow")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void ChartObject::SetShadow(TAutoVal& val)
{
  AUTONAMES0("Shadow")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal ChartObject::GetTop()
{
  AUTONAMES0("Top")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void ChartObject::SetTop(TAutoVal& val)
{
  AUTONAMES0("Top")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal ChartObject::GetTopLeftCell()
{
  AUTONAMES0("TopLeftCell")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void ChartObject::SetTopLeftCell(TAutoVal& val)
{
  AUTONAMES0("TopLeftCell")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal ChartObject::GetVisible()
{
  AUTONAMES0("Visible")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void ChartObject::SetVisible(TAutoVal& val)
{
  AUTONAMES0("Visible")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal ChartObject::GetWidth()
{
  AUTONAMES0("Width")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void ChartObject::SetWidth(TAutoVal& val)
{
  AUTONAMES0("Width")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal ChartObject::GetZOrder()
{
  AUTONAMES0("ZOrder")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void ChartObject::SetZOrder(TAutoVal& val)
{
  AUTONAMES0("ZOrder")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal ChartObject::Activate()
{
  AUTONAMES0("Activate")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal ChartObject::Application()
{
  AUTONAMES0("Application")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal ChartObject::BringToFront()
{
  AUTONAMES0("BringToFront")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal ChartObject::Copy()
{
  AUTONAMES0("Copy")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal ChartObject::CopyPicture(TAutoVal& Appearance, TAutoVal& Format)
{
  AUTONAMES0("CopyPicture")
  AUTOARGS2(Appearance, Format)
  AUTOCALL_METHOD_RET
}

TAutoVal ChartObject::Cut()
{
  AUTONAMES0("Cut")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal ChartObject::Delete()
{
  AUTONAMES0("Delete")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal ChartObject::Duplicate()
{
  AUTONAMES0("Duplicate")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal ChartObject::Select(TAutoVal& Replace)
{
  AUTONAMES0("Select")
  AUTOARGS1(Replace)
  AUTOCALL_METHOD_RET
}

TAutoVal ChartObject::SendToBack()
{
  AUTONAMES0("SendToBack")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}


// TKIND_DISPATCH: ChartObjects {000208D0-0000-0000-C000-000000000046}\9

TAutoVal ChartObjects::GetBorder()
{
  AUTONAMES0("Border")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void ChartObjects::SetBorder(TAutoVal& val)
{
  AUTONAMES0("Border")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal ChartObjects::GetCount()
{
  AUTONAMES0("Count")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void ChartObjects::SetCount(TAutoVal& val)
{
  AUTONAMES0("Count")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal ChartObjects::GetCreator()
{
  AUTONAMES0("Creator")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void ChartObjects::SetCreator(TAutoVal& val)
{
  AUTONAMES0("Creator")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal ChartObjects::GetEnabled()
{
  AUTONAMES0("Enabled")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void ChartObjects::SetEnabled(TAutoVal& val)
{
  AUTONAMES0("Enabled")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal ChartObjects::GetHeight()
{
  AUTONAMES0("Height")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void ChartObjects::SetHeight(TAutoVal& val)
{
  AUTONAMES0("Height")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal ChartObjects::GetInterior()
{
  AUTONAMES0("Interior")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void ChartObjects::SetInterior(TAutoVal& val)
{
  AUTONAMES0("Interior")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal ChartObjects::GetLeft()
{
  AUTONAMES0("Left")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void ChartObjects::SetLeft(TAutoVal& val)
{
  AUTONAMES0("Left")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal ChartObjects::GetLocked()
{
  AUTONAMES0("Locked")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void ChartObjects::SetLocked(TAutoVal& val)
{
  AUTONAMES0("Locked")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal ChartObjects::GetOnAction()
{
  AUTONAMES0("OnAction")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void ChartObjects::SetOnAction(TAutoVal& val)
{
  AUTONAMES0("OnAction")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal ChartObjects::GetParent()
{
  AUTONAMES0("Parent")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void ChartObjects::SetParent(TAutoVal& val)
{
  AUTONAMES0("Parent")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal ChartObjects::GetPlacement()
{
  AUTONAMES0("Placement")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void ChartObjects::SetPlacement(TAutoVal& val)
{
  AUTONAMES0("Placement")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal ChartObjects::GetPrintObject()
{
  AUTONAMES0("PrintObject")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void ChartObjects::SetPrintObject(TAutoVal& val)
{
  AUTONAMES0("PrintObject")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal ChartObjects::GetRoundedCorners()
{
  AUTONAMES0("RoundedCorners")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void ChartObjects::SetRoundedCorners(TAutoVal& val)
{
  AUTONAMES0("RoundedCorners")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal ChartObjects::GetShadow()
{
  AUTONAMES0("Shadow")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void ChartObjects::SetShadow(TAutoVal& val)
{
  AUTONAMES0("Shadow")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal ChartObjects::GetTop()
{
  AUTONAMES0("Top")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void ChartObjects::SetTop(TAutoVal& val)
{
  AUTONAMES0("Top")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal ChartObjects::GetVisible()
{
  AUTONAMES0("Visible")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void ChartObjects::SetVisible(TAutoVal& val)
{
  AUTONAMES0("Visible")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal ChartObjects::GetWidth()
{
  AUTONAMES0("Width")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void ChartObjects::SetWidth(TAutoVal& val)
{
  AUTONAMES0("Width")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal ChartObjects::GetZOrder()
{
  AUTONAMES0("ZOrder")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void ChartObjects::SetZOrder(TAutoVal& val)
{
  AUTONAMES0("ZOrder")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal ChartObjects::_NewEnum()
{
  AUTONAMES0("_NewEnum")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal ChartObjects::Add(TAutoVal& Left, TAutoVal& Top, TAutoVal& Width, TAutoVal& Height)
{
  AUTONAMES0("Add")
  AUTOARGS4(Left, Top, Width, Height)
  AUTOCALL_METHOD_RET
}

TAutoVal ChartObjects::Application()
{
  AUTONAMES0("Application")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal ChartObjects::BringToFront()
{
  AUTONAMES0("BringToFront")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal ChartObjects::Copy()
{
  AUTONAMES0("Copy")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal ChartObjects::CopyPicture(TAutoVal& Appearance, TAutoVal& Format)
{
  AUTONAMES0("CopyPicture")
  AUTOARGS2(Appearance, Format)
  AUTOCALL_METHOD_RET
}

TAutoVal ChartObjects::Cut()
{
  AUTONAMES0("Cut")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal ChartObjects::Delete()
{
  AUTONAMES0("Delete")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal ChartObjects::Duplicate()
{
  AUTONAMES0("Duplicate")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal ChartObjects::Group()
{
  AUTONAMES0("Group")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal ChartObjects::Item(TAutoVal& Index)
{
  AUTONAMES0("Item")
  AUTOARGS1(Index)
  AUTOCALL_METHOD_RET
}

TAutoVal ChartObjects::Select(TAutoVal& Replace)
{
  AUTONAMES0("Select")
  AUTOARGS1(Replace)
  AUTOCALL_METHOD_RET
}

TAutoVal ChartObjects::SendToBack()
{
  AUTONAMES0("SendToBack")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}


// TKIND_DISPATCH: Drawing {000208A8-0000-0000-C000-000000000046}\9

TAutoVal Drawing::GetBorder()
{
  AUTONAMES0("Border")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Drawing::SetBorder(TAutoVal& val)
{
  AUTONAMES0("Border")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Drawing::GetBottomRightCell()
{
  AUTONAMES0("BottomRightCell")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Drawing::SetBottomRightCell(TAutoVal& val)
{
  AUTONAMES0("BottomRightCell")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Drawing::GetCreator()
{
  AUTONAMES0("Creator")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Drawing::SetCreator(TAutoVal& val)
{
  AUTONAMES0("Creator")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Drawing::GetEnabled()
{
  AUTONAMES0("Enabled")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Drawing::SetEnabled(TAutoVal& val)
{
  AUTONAMES0("Enabled")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Drawing::GetHeight()
{
  AUTONAMES0("Height")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Drawing::SetHeight(TAutoVal& val)
{
  AUTONAMES0("Height")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Drawing::GetIndex()
{
  AUTONAMES0("Index")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Drawing::SetIndex(TAutoVal& val)
{
  AUTONAMES0("Index")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Drawing::GetInterior()
{
  AUTONAMES0("Interior")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Drawing::SetInterior(TAutoVal& val)
{
  AUTONAMES0("Interior")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Drawing::GetLeft()
{
  AUTONAMES0("Left")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Drawing::SetLeft(TAutoVal& val)
{
  AUTONAMES0("Left")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Drawing::GetLocked()
{
  AUTONAMES0("Locked")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Drawing::SetLocked(TAutoVal& val)
{
  AUTONAMES0("Locked")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Drawing::GetName()
{
  AUTONAMES0("Name")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Drawing::SetName(TAutoVal& val)
{
  AUTONAMES0("Name")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Drawing::GetOnAction()
{
  AUTONAMES0("OnAction")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Drawing::SetOnAction(TAutoVal& val)
{
  AUTONAMES0("OnAction")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Drawing::GetParent()
{
  AUTONAMES0("Parent")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Drawing::SetParent(TAutoVal& val)
{
  AUTONAMES0("Parent")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Drawing::GetPlacement()
{
  AUTONAMES0("Placement")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Drawing::SetPlacement(TAutoVal& val)
{
  AUTONAMES0("Placement")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Drawing::GetPrintObject()
{
  AUTONAMES0("PrintObject")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Drawing::SetPrintObject(TAutoVal& val)
{
  AUTONAMES0("PrintObject")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Drawing::GetShadow()
{
  AUTONAMES0("Shadow")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Drawing::SetShadow(TAutoVal& val)
{
  AUTONAMES0("Shadow")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Drawing::GetTop()
{
  AUTONAMES0("Top")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Drawing::SetTop(TAutoVal& val)
{
  AUTONAMES0("Top")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Drawing::GetTopLeftCell()
{
  AUTONAMES0("TopLeftCell")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Drawing::SetTopLeftCell(TAutoVal& val)
{
  AUTONAMES0("TopLeftCell")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Drawing::GetVertices()
{
  AUTONAMES0("Vertices")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Drawing::SetVertices(TAutoVal& val)
{
  AUTONAMES0("Vertices")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Drawing::GetVisible()
{
  AUTONAMES0("Visible")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Drawing::SetVisible(TAutoVal& val)
{
  AUTONAMES0("Visible")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Drawing::GetWidth()
{
  AUTONAMES0("Width")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Drawing::SetWidth(TAutoVal& val)
{
  AUTONAMES0("Width")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Drawing::GetZOrder()
{
  AUTONAMES0("ZOrder")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Drawing::SetZOrder(TAutoVal& val)
{
  AUTONAMES0("ZOrder")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Drawing::AddVertex(TAutoVal& Left, TAutoVal& Top)
{
  AUTONAMES0("AddVertex")
  AUTOARGS2(Left, Top)
  AUTOCALL_METHOD_RET
}

TAutoVal Drawing::Application()
{
  AUTONAMES0("Application")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Drawing::BringToFront()
{
  AUTONAMES0("BringToFront")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Drawing::Copy()
{
  AUTONAMES0("Copy")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Drawing::CopyPicture(TAutoVal& Appearance, TAutoVal& Format)
{
  AUTONAMES0("CopyPicture")
  AUTOARGS2(Appearance, Format)
  AUTOCALL_METHOD_RET
}

TAutoVal Drawing::Cut()
{
  AUTONAMES0("Cut")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Drawing::Delete()
{
  AUTONAMES0("Delete")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Drawing::Duplicate()
{
  AUTONAMES0("Duplicate")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Drawing::Reshape(TAutoVal& Vertex, TAutoVal& Insert, TAutoVal& Left, TAutoVal& Top)
{
  AUTONAMES0("Reshape")
  AUTOARGS4(Vertex, Insert, Left, Top)
  AUTOCALL_METHOD_RET
}

TAutoVal Drawing::Select(TAutoVal& Replace)
{
  AUTONAMES0("Select")
  AUTOARGS1(Replace)
  AUTOCALL_METHOD_RET
}

TAutoVal Drawing::SendToBack()
{
  AUTONAMES0("SendToBack")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}


// TKIND_DISPATCH: Drawings {000208A9-0000-0000-C000-000000000046}\9

TAutoVal Drawings::GetBorder()
{
  AUTONAMES0("Border")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Drawings::SetBorder(TAutoVal& val)
{
  AUTONAMES0("Border")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Drawings::GetCount()
{
  AUTONAMES0("Count")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Drawings::SetCount(TAutoVal& val)
{
  AUTONAMES0("Count")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Drawings::GetCreator()
{
  AUTONAMES0("Creator")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Drawings::SetCreator(TAutoVal& val)
{
  AUTONAMES0("Creator")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Drawings::GetEnabled()
{
  AUTONAMES0("Enabled")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Drawings::SetEnabled(TAutoVal& val)
{
  AUTONAMES0("Enabled")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Drawings::GetHeight()
{
  AUTONAMES0("Height")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Drawings::SetHeight(TAutoVal& val)
{
  AUTONAMES0("Height")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Drawings::GetInterior()
{
  AUTONAMES0("Interior")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Drawings::SetInterior(TAutoVal& val)
{
  AUTONAMES0("Interior")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Drawings::GetLeft()
{
  AUTONAMES0("Left")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Drawings::SetLeft(TAutoVal& val)
{
  AUTONAMES0("Left")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Drawings::GetLocked()
{
  AUTONAMES0("Locked")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Drawings::SetLocked(TAutoVal& val)
{
  AUTONAMES0("Locked")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Drawings::GetOnAction()
{
  AUTONAMES0("OnAction")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Drawings::SetOnAction(TAutoVal& val)
{
  AUTONAMES0("OnAction")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Drawings::GetParent()
{
  AUTONAMES0("Parent")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Drawings::SetParent(TAutoVal& val)
{
  AUTONAMES0("Parent")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Drawings::GetPlacement()
{
  AUTONAMES0("Placement")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Drawings::SetPlacement(TAutoVal& val)
{
  AUTONAMES0("Placement")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Drawings::GetPrintObject()
{
  AUTONAMES0("PrintObject")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Drawings::SetPrintObject(TAutoVal& val)
{
  AUTONAMES0("PrintObject")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Drawings::GetShadow()
{
  AUTONAMES0("Shadow")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Drawings::SetShadow(TAutoVal& val)
{
  AUTONAMES0("Shadow")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Drawings::GetTop()
{
  AUTONAMES0("Top")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Drawings::SetTop(TAutoVal& val)
{
  AUTONAMES0("Top")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Drawings::GetVisible()
{
  AUTONAMES0("Visible")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Drawings::SetVisible(TAutoVal& val)
{
  AUTONAMES0("Visible")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Drawings::GetWidth()
{
  AUTONAMES0("Width")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Drawings::SetWidth(TAutoVal& val)
{
  AUTONAMES0("Width")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Drawings::GetZOrder()
{
  AUTONAMES0("ZOrder")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Drawings::SetZOrder(TAutoVal& val)
{
  AUTONAMES0("ZOrder")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Drawings::_NewEnum()
{
  AUTONAMES0("_NewEnum")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Drawings::Add(TAutoVal& X1, TAutoVal& Y1, TAutoVal& X2, TAutoVal& Y2, TAutoVal& Closed)
{
  AUTONAMES0("Add")
  AUTOARGS5(X1, Y1, X2, Y2, Closed)
  AUTOCALL_METHOD_RET
}

TAutoVal Drawings::Application()
{
  AUTONAMES0("Application")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Drawings::BringToFront()
{
  AUTONAMES0("BringToFront")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Drawings::Copy()
{
  AUTONAMES0("Copy")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Drawings::CopyPicture(TAutoVal& Appearance, TAutoVal& Format)
{
  AUTONAMES0("CopyPicture")
  AUTOARGS2(Appearance, Format)
  AUTOCALL_METHOD_RET
}

TAutoVal Drawings::Cut()
{
  AUTONAMES0("Cut")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Drawings::Delete()
{
  AUTONAMES0("Delete")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Drawings::Duplicate()
{
  AUTONAMES0("Duplicate")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Drawings::Group()
{
  AUTONAMES0("Group")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Drawings::Item(TAutoVal& Index)
{
  AUTONAMES0("Item")
  AUTOARGS1(Index)
  AUTOCALL_METHOD_RET
}

TAutoVal Drawings::Reshape(TAutoVal& Vertex, TAutoVal& Insert, TAutoVal& Left, TAutoVal& Top)
{
  AUTONAMES0("Reshape")
  AUTOARGS4(Vertex, Insert, Left, Top)
  AUTOCALL_METHOD_RET
}

TAutoVal Drawings::Select(TAutoVal& Replace)
{
  AUTONAMES0("Select")
  AUTOARGS1(Replace)
  AUTOCALL_METHOD_RET
}

TAutoVal Drawings::SendToBack()
{
  AUTONAMES0("SendToBack")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}


// TKIND_DISPATCH: Button {0002087D-0000-0000-C000-000000000046}\9

TAutoVal Button::GetAccelerator()
{
  AUTONAMES0("Accelerator")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Button::SetAccelerator(TAutoVal& val)
{
  AUTONAMES0("Accelerator")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Button::GetAddIndent()
{
  AUTONAMES0("AddIndent")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Button::SetAddIndent(TAutoVal& val)
{
  AUTONAMES0("AddIndent")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Button::GetAutoSize()
{
  AUTONAMES0("AutoSize")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Button::SetAutoSize(TAutoVal& val)
{
  AUTONAMES0("AutoSize")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Button::GetBottomRightCell()
{
  AUTONAMES0("BottomRightCell")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Button::SetBottomRightCell(TAutoVal& val)
{
  AUTONAMES0("BottomRightCell")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Button::GetCancelButton()
{
  AUTONAMES0("CancelButton")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Button::SetCancelButton(TAutoVal& val)
{
  AUTONAMES0("CancelButton")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Button::GetCaption()
{
  AUTONAMES0("Caption")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Button::SetCaption(TAutoVal& val)
{
  AUTONAMES0("Caption")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Button::GetCreator()
{
  AUTONAMES0("Creator")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Button::SetCreator(TAutoVal& val)
{
  AUTONAMES0("Creator")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Button::GetDefaultButton()
{
  AUTONAMES0("DefaultButton")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Button::SetDefaultButton(TAutoVal& val)
{
  AUTONAMES0("DefaultButton")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Button::GetDismissButton()
{
  AUTONAMES0("DismissButton")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Button::SetDismissButton(TAutoVal& val)
{
  AUTONAMES0("DismissButton")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Button::GetEnabled()
{
  AUTONAMES0("Enabled")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Button::SetEnabled(TAutoVal& val)
{
  AUTONAMES0("Enabled")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Button::GetFont()
{
  AUTONAMES0("Font")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Button::SetFont(TAutoVal& val)
{
  AUTONAMES0("Font")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Button::GetFormula()
{
  AUTONAMES0("Formula")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Button::SetFormula(TAutoVal& val)
{
  AUTONAMES0("Formula")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Button::GetHeight()
{
  AUTONAMES0("Height")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Button::SetHeight(TAutoVal& val)
{
  AUTONAMES0("Height")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Button::GetHelpButton()
{
  AUTONAMES0("HelpButton")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Button::SetHelpButton(TAutoVal& val)
{
  AUTONAMES0("HelpButton")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Button::GetHorizontalAlignment()
{
  AUTONAMES0("HorizontalAlignment")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Button::SetHorizontalAlignment(TAutoVal& val)
{
  AUTONAMES0("HorizontalAlignment")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Button::GetIndex()
{
  AUTONAMES0("Index")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Button::SetIndex(TAutoVal& val)
{
  AUTONAMES0("Index")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Button::GetLeft()
{
  AUTONAMES0("Left")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Button::SetLeft(TAutoVal& val)
{
  AUTONAMES0("Left")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Button::GetLocked()
{
  AUTONAMES0("Locked")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Button::SetLocked(TAutoVal& val)
{
  AUTONAMES0("Locked")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Button::GetLockedText()
{
  AUTONAMES0("LockedText")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Button::SetLockedText(TAutoVal& val)
{
  AUTONAMES0("LockedText")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Button::GetName()
{
  AUTONAMES0("Name")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Button::SetName(TAutoVal& val)
{
  AUTONAMES0("Name")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Button::GetOnAction()
{
  AUTONAMES0("OnAction")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Button::SetOnAction(TAutoVal& val)
{
  AUTONAMES0("OnAction")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Button::GetOrientation()
{
  AUTONAMES0("Orientation")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Button::SetOrientation(TAutoVal& val)
{
  AUTONAMES0("Orientation")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Button::GetParent()
{
  AUTONAMES0("Parent")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Button::SetParent(TAutoVal& val)
{
  AUTONAMES0("Parent")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Button::GetPhoneticAccelerator()
{
  AUTONAMES0("PhoneticAccelerator")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Button::SetPhoneticAccelerator(TAutoVal& val)
{
  AUTONAMES0("PhoneticAccelerator")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Button::GetPlacement()
{
  AUTONAMES0("Placement")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Button::SetPlacement(TAutoVal& val)
{
  AUTONAMES0("Placement")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Button::GetPrintObject()
{
  AUTONAMES0("PrintObject")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Button::SetPrintObject(TAutoVal& val)
{
  AUTONAMES0("PrintObject")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Button::GetText()
{
  AUTONAMES0("Text")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Button::SetText(TAutoVal& val)
{
  AUTONAMES0("Text")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Button::GetTop()
{
  AUTONAMES0("Top")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Button::SetTop(TAutoVal& val)
{
  AUTONAMES0("Top")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Button::GetTopLeftCell()
{
  AUTONAMES0("TopLeftCell")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Button::SetTopLeftCell(TAutoVal& val)
{
  AUTONAMES0("TopLeftCell")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Button::GetVerticalAlignment()
{
  AUTONAMES0("VerticalAlignment")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Button::SetVerticalAlignment(TAutoVal& val)
{
  AUTONAMES0("VerticalAlignment")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Button::GetVisible()
{
  AUTONAMES0("Visible")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Button::SetVisible(TAutoVal& val)
{
  AUTONAMES0("Visible")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Button::GetWidth()
{
  AUTONAMES0("Width")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Button::SetWidth(TAutoVal& val)
{
  AUTONAMES0("Width")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Button::GetZOrder()
{
  AUTONAMES0("ZOrder")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Button::SetZOrder(TAutoVal& val)
{
  AUTONAMES0("ZOrder")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Button::Application()
{
  AUTONAMES0("Application")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Button::BringToFront()
{
  AUTONAMES0("BringToFront")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Button::Characters(TAutoVal& Start, TAutoVal& Length)
{
  AUTONAMES0("Characters")
  AUTOARGS2(Start, Length)
  AUTOCALL_METHOD_RET
}

TAutoVal Button::CheckSpelling(TAutoVal& CustomDictionary, TAutoVal& IgnoreUppercase, TAutoVal& AlwaysSuggest)
{
  AUTONAMES0("CheckSpelling")
  AUTOARGS3(CustomDictionary, IgnoreUppercase, AlwaysSuggest)
  AUTOCALL_METHOD_RET
}

TAutoVal Button::Copy()
{
  AUTONAMES0("Copy")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Button::CopyPicture(TAutoVal& Appearance, TAutoVal& Format)
{
  AUTONAMES0("CopyPicture")
  AUTOARGS2(Appearance, Format)
  AUTOCALL_METHOD_RET
}

TAutoVal Button::Cut()
{
  AUTONAMES0("Cut")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Button::Delete()
{
  AUTONAMES0("Delete")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Button::Duplicate()
{
  AUTONAMES0("Duplicate")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Button::Select(TAutoVal& Replace)
{
  AUTONAMES0("Select")
  AUTOARGS1(Replace)
  AUTOCALL_METHOD_RET
}

TAutoVal Button::SendToBack()
{
  AUTONAMES0("SendToBack")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}


// TKIND_DISPATCH: Buttons {0002087E-0000-0000-C000-000000000046}\9

TAutoVal Buttons::GetAccelerator()
{
  AUTONAMES0("Accelerator")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Buttons::SetAccelerator(TAutoVal& val)
{
  AUTONAMES0("Accelerator")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Buttons::GetAddIndent()
{
  AUTONAMES0("AddIndent")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Buttons::SetAddIndent(TAutoVal& val)
{
  AUTONAMES0("AddIndent")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Buttons::GetAutoSize()
{
  AUTONAMES0("AutoSize")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Buttons::SetAutoSize(TAutoVal& val)
{
  AUTONAMES0("AutoSize")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Buttons::GetCancelButton()
{
  AUTONAMES0("CancelButton")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Buttons::SetCancelButton(TAutoVal& val)
{
  AUTONAMES0("CancelButton")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Buttons::GetCaption()
{
  AUTONAMES0("Caption")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Buttons::SetCaption(TAutoVal& val)
{
  AUTONAMES0("Caption")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Buttons::GetCount()
{
  AUTONAMES0("Count")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Buttons::SetCount(TAutoVal& val)
{
  AUTONAMES0("Count")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Buttons::GetCreator()
{
  AUTONAMES0("Creator")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Buttons::SetCreator(TAutoVal& val)
{
  AUTONAMES0("Creator")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Buttons::GetDefaultButton()
{
  AUTONAMES0("DefaultButton")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Buttons::SetDefaultButton(TAutoVal& val)
{
  AUTONAMES0("DefaultButton")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Buttons::GetDismissButton()
{
  AUTONAMES0("DismissButton")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Buttons::SetDismissButton(TAutoVal& val)
{
  AUTONAMES0("DismissButton")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Buttons::GetEnabled()
{
  AUTONAMES0("Enabled")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Buttons::SetEnabled(TAutoVal& val)
{
  AUTONAMES0("Enabled")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Buttons::GetFont()
{
  AUTONAMES0("Font")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Buttons::SetFont(TAutoVal& val)
{
  AUTONAMES0("Font")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Buttons::GetFormula()
{
  AUTONAMES0("Formula")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Buttons::SetFormula(TAutoVal& val)
{
  AUTONAMES0("Formula")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Buttons::GetHeight()
{
  AUTONAMES0("Height")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Buttons::SetHeight(TAutoVal& val)
{
  AUTONAMES0("Height")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Buttons::GetHelpButton()
{
  AUTONAMES0("HelpButton")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Buttons::SetHelpButton(TAutoVal& val)
{
  AUTONAMES0("HelpButton")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Buttons::GetHorizontalAlignment()
{
  AUTONAMES0("HorizontalAlignment")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Buttons::SetHorizontalAlignment(TAutoVal& val)
{
  AUTONAMES0("HorizontalAlignment")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Buttons::GetLeft()
{
  AUTONAMES0("Left")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Buttons::SetLeft(TAutoVal& val)
{
  AUTONAMES0("Left")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Buttons::GetLocked()
{
  AUTONAMES0("Locked")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Buttons::SetLocked(TAutoVal& val)
{
  AUTONAMES0("Locked")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Buttons::GetLockedText()
{
  AUTONAMES0("LockedText")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Buttons::SetLockedText(TAutoVal& val)
{
  AUTONAMES0("LockedText")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Buttons::GetOnAction()
{
  AUTONAMES0("OnAction")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Buttons::SetOnAction(TAutoVal& val)
{
  AUTONAMES0("OnAction")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Buttons::GetOrientation()
{
  AUTONAMES0("Orientation")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Buttons::SetOrientation(TAutoVal& val)
{
  AUTONAMES0("Orientation")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Buttons::GetParent()
{
  AUTONAMES0("Parent")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Buttons::SetParent(TAutoVal& val)
{
  AUTONAMES0("Parent")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Buttons::GetPhoneticAccelerator()
{
  AUTONAMES0("PhoneticAccelerator")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Buttons::SetPhoneticAccelerator(TAutoVal& val)
{
  AUTONAMES0("PhoneticAccelerator")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Buttons::GetPlacement()
{
  AUTONAMES0("Placement")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Buttons::SetPlacement(TAutoVal& val)
{
  AUTONAMES0("Placement")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Buttons::GetPrintObject()
{
  AUTONAMES0("PrintObject")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Buttons::SetPrintObject(TAutoVal& val)
{
  AUTONAMES0("PrintObject")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Buttons::GetText()
{
  AUTONAMES0("Text")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Buttons::SetText(TAutoVal& val)
{
  AUTONAMES0("Text")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Buttons::GetTop()
{
  AUTONAMES0("Top")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Buttons::SetTop(TAutoVal& val)
{
  AUTONAMES0("Top")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Buttons::GetVerticalAlignment()
{
  AUTONAMES0("VerticalAlignment")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Buttons::SetVerticalAlignment(TAutoVal& val)
{
  AUTONAMES0("VerticalAlignment")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Buttons::GetVisible()
{
  AUTONAMES0("Visible")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Buttons::SetVisible(TAutoVal& val)
{
  AUTONAMES0("Visible")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Buttons::GetWidth()
{
  AUTONAMES0("Width")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Buttons::SetWidth(TAutoVal& val)
{
  AUTONAMES0("Width")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Buttons::GetZOrder()
{
  AUTONAMES0("ZOrder")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Buttons::SetZOrder(TAutoVal& val)
{
  AUTONAMES0("ZOrder")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Buttons::_NewEnum()
{
  AUTONAMES0("_NewEnum")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Buttons::Add(TAutoVal& Left, TAutoVal& Top, TAutoVal& Width, TAutoVal& Height)
{
  AUTONAMES0("Add")
  AUTOARGS4(Left, Top, Width, Height)
  AUTOCALL_METHOD_RET
}

TAutoVal Buttons::Application()
{
  AUTONAMES0("Application")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Buttons::BringToFront()
{
  AUTONAMES0("BringToFront")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Buttons::Characters(TAutoVal& Start, TAutoVal& Length)
{
  AUTONAMES0("Characters")
  AUTOARGS2(Start, Length)
  AUTOCALL_METHOD_RET
}

TAutoVal Buttons::CheckSpelling(TAutoVal& CustomDictionary, TAutoVal& IgnoreUppercase, TAutoVal& AlwaysSuggest)
{
  AUTONAMES0("CheckSpelling")
  AUTOARGS3(CustomDictionary, IgnoreUppercase, AlwaysSuggest)
  AUTOCALL_METHOD_RET
}

TAutoVal Buttons::Copy()
{
  AUTONAMES0("Copy")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Buttons::CopyPicture(TAutoVal& Appearance, TAutoVal& Format)
{
  AUTONAMES0("CopyPicture")
  AUTOARGS2(Appearance, Format)
  AUTOCALL_METHOD_RET
}

TAutoVal Buttons::Cut()
{
  AUTONAMES0("Cut")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Buttons::Delete()
{
  AUTONAMES0("Delete")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Buttons::Duplicate()
{
  AUTONAMES0("Duplicate")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Buttons::Group()
{
  AUTONAMES0("Group")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Buttons::Item(TAutoVal& Index)
{
  AUTONAMES0("Item")
  AUTOARGS1(Index)
  AUTOCALL_METHOD_RET
}

TAutoVal Buttons::Select(TAutoVal& Replace)
{
  AUTONAMES0("Select")
  AUTOARGS1(Replace)
  AUTOCALL_METHOD_RET
}

TAutoVal Buttons::SendToBack()
{
  AUTONAMES0("SendToBack")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}


// TKIND_DISPATCH: EditBox {00020883-0000-0000-C000-000000000046}\9

TAutoVal EditBox::GetBottomRightCell()
{
  AUTONAMES0("BottomRightCell")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void EditBox::SetBottomRightCell(TAutoVal& val)
{
  AUTONAMES0("BottomRightCell")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal EditBox::GetCaption()
{
  AUTONAMES0("Caption")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void EditBox::SetCaption(TAutoVal& val)
{
  AUTONAMES0("Caption")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal EditBox::GetCreator()
{
  AUTONAMES0("Creator")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void EditBox::SetCreator(TAutoVal& val)
{
  AUTONAMES0("Creator")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal EditBox::GetDisplayVerticalScrollBar()
{
  AUTONAMES0("DisplayVerticalScrollBar")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void EditBox::SetDisplayVerticalScrollBar(TAutoVal& val)
{
  AUTONAMES0("DisplayVerticalScrollBar")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal EditBox::GetEnabled()
{
  AUTONAMES0("Enabled")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void EditBox::SetEnabled(TAutoVal& val)
{
  AUTONAMES0("Enabled")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal EditBox::GetHeight()
{
  AUTONAMES0("Height")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void EditBox::SetHeight(TAutoVal& val)
{
  AUTONAMES0("Height")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal EditBox::GetIndex()
{
  AUTONAMES0("Index")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void EditBox::SetIndex(TAutoVal& val)
{
  AUTONAMES0("Index")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal EditBox::GetInputType()
{
  AUTONAMES0("InputType")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void EditBox::SetInputType(TAutoVal& val)
{
  AUTONAMES0("InputType")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal EditBox::GetLeft()
{
  AUTONAMES0("Left")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void EditBox::SetLeft(TAutoVal& val)
{
  AUTONAMES0("Left")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal EditBox::GetLinkedObject()
{
  AUTONAMES0("LinkedObject")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void EditBox::SetLinkedObject(TAutoVal& val)
{
  AUTONAMES0("LinkedObject")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal EditBox::GetLocked()
{
  AUTONAMES0("Locked")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void EditBox::SetLocked(TAutoVal& val)
{
  AUTONAMES0("Locked")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal EditBox::GetMultiLine()
{
  AUTONAMES0("MultiLine")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void EditBox::SetMultiLine(TAutoVal& val)
{
  AUTONAMES0("MultiLine")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal EditBox::GetName()
{
  AUTONAMES0("Name")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void EditBox::SetName(TAutoVal& val)
{
  AUTONAMES0("Name")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal EditBox::GetOnAction()
{
  AUTONAMES0("OnAction")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void EditBox::SetOnAction(TAutoVal& val)
{
  AUTONAMES0("OnAction")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal EditBox::GetParent()
{
  AUTONAMES0("Parent")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void EditBox::SetParent(TAutoVal& val)
{
  AUTONAMES0("Parent")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal EditBox::GetPasswordEdit()
{
  AUTONAMES0("PasswordEdit")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void EditBox::SetPasswordEdit(TAutoVal& val)
{
  AUTONAMES0("PasswordEdit")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal EditBox::GetPlacement()
{
  AUTONAMES0("Placement")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void EditBox::SetPlacement(TAutoVal& val)
{
  AUTONAMES0("Placement")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal EditBox::GetPrintObject()
{
  AUTONAMES0("PrintObject")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void EditBox::SetPrintObject(TAutoVal& val)
{
  AUTONAMES0("PrintObject")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal EditBox::GetText()
{
  AUTONAMES0("Text")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void EditBox::SetText(TAutoVal& val)
{
  AUTONAMES0("Text")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal EditBox::GetTop()
{
  AUTONAMES0("Top")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void EditBox::SetTop(TAutoVal& val)
{
  AUTONAMES0("Top")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal EditBox::GetTopLeftCell()
{
  AUTONAMES0("TopLeftCell")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void EditBox::SetTopLeftCell(TAutoVal& val)
{
  AUTONAMES0("TopLeftCell")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal EditBox::GetVisible()
{
  AUTONAMES0("Visible")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void EditBox::SetVisible(TAutoVal& val)
{
  AUTONAMES0("Visible")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal EditBox::GetWidth()
{
  AUTONAMES0("Width")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void EditBox::SetWidth(TAutoVal& val)
{
  AUTONAMES0("Width")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal EditBox::GetZOrder()
{
  AUTONAMES0("ZOrder")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void EditBox::SetZOrder(TAutoVal& val)
{
  AUTONAMES0("ZOrder")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal EditBox::Application()
{
  AUTONAMES0("Application")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal EditBox::BringToFront()
{
  AUTONAMES0("BringToFront")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal EditBox::Characters(TAutoVal& Start, TAutoVal& Length)
{
  AUTONAMES0("Characters")
  AUTOARGS2(Start, Length)
  AUTOCALL_METHOD_RET
}

TAutoVal EditBox::Copy()
{
  AUTONAMES0("Copy")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal EditBox::CopyPicture(TAutoVal& Appearance, TAutoVal& Format)
{
  AUTONAMES0("CopyPicture")
  AUTOARGS2(Appearance, Format)
  AUTOCALL_METHOD_RET
}

TAutoVal EditBox::Cut()
{
  AUTONAMES0("Cut")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal EditBox::Delete()
{
  AUTONAMES0("Delete")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal EditBox::Duplicate()
{
  AUTONAMES0("Duplicate")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal EditBox::Select(TAutoVal& Replace)
{
  AUTONAMES0("Select")
  AUTOARGS1(Replace)
  AUTOCALL_METHOD_RET
}

TAutoVal EditBox::SendToBack()
{
  AUTONAMES0("SendToBack")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}


// TKIND_DISPATCH: EditBoxes {00020884-0000-0000-C000-000000000046}\9

TAutoVal EditBoxes::GetCaption()
{
  AUTONAMES0("Caption")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void EditBoxes::SetCaption(TAutoVal& val)
{
  AUTONAMES0("Caption")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal EditBoxes::GetCount()
{
  AUTONAMES0("Count")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void EditBoxes::SetCount(TAutoVal& val)
{
  AUTONAMES0("Count")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal EditBoxes::GetCreator()
{
  AUTONAMES0("Creator")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void EditBoxes::SetCreator(TAutoVal& val)
{
  AUTONAMES0("Creator")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal EditBoxes::GetDisplayVerticalScrollBar()
{
  AUTONAMES0("DisplayVerticalScrollBar")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void EditBoxes::SetDisplayVerticalScrollBar(TAutoVal& val)
{
  AUTONAMES0("DisplayVerticalScrollBar")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal EditBoxes::GetEnabled()
{
  AUTONAMES0("Enabled")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void EditBoxes::SetEnabled(TAutoVal& val)
{
  AUTONAMES0("Enabled")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal EditBoxes::GetHeight()
{
  AUTONAMES0("Height")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void EditBoxes::SetHeight(TAutoVal& val)
{
  AUTONAMES0("Height")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal EditBoxes::GetInputType()
{
  AUTONAMES0("InputType")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void EditBoxes::SetInputType(TAutoVal& val)
{
  AUTONAMES0("InputType")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal EditBoxes::GetLeft()
{
  AUTONAMES0("Left")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void EditBoxes::SetLeft(TAutoVal& val)
{
  AUTONAMES0("Left")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal EditBoxes::GetLocked()
{
  AUTONAMES0("Locked")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void EditBoxes::SetLocked(TAutoVal& val)
{
  AUTONAMES0("Locked")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal EditBoxes::GetMultiLine()
{
  AUTONAMES0("MultiLine")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void EditBoxes::SetMultiLine(TAutoVal& val)
{
  AUTONAMES0("MultiLine")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal EditBoxes::GetOnAction()
{
  AUTONAMES0("OnAction")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void EditBoxes::SetOnAction(TAutoVal& val)
{
  AUTONAMES0("OnAction")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal EditBoxes::GetParent()
{
  AUTONAMES0("Parent")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void EditBoxes::SetParent(TAutoVal& val)
{
  AUTONAMES0("Parent")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal EditBoxes::GetPasswordEdit()
{
  AUTONAMES0("PasswordEdit")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void EditBoxes::SetPasswordEdit(TAutoVal& val)
{
  AUTONAMES0("PasswordEdit")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal EditBoxes::GetPlacement()
{
  AUTONAMES0("Placement")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void EditBoxes::SetPlacement(TAutoVal& val)
{
  AUTONAMES0("Placement")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal EditBoxes::GetPrintObject()
{
  AUTONAMES0("PrintObject")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void EditBoxes::SetPrintObject(TAutoVal& val)
{
  AUTONAMES0("PrintObject")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal EditBoxes::GetText()
{
  AUTONAMES0("Text")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void EditBoxes::SetText(TAutoVal& val)
{
  AUTONAMES0("Text")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal EditBoxes::GetTop()
{
  AUTONAMES0("Top")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void EditBoxes::SetTop(TAutoVal& val)
{
  AUTONAMES0("Top")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal EditBoxes::GetVisible()
{
  AUTONAMES0("Visible")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void EditBoxes::SetVisible(TAutoVal& val)
{
  AUTONAMES0("Visible")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal EditBoxes::GetWidth()
{
  AUTONAMES0("Width")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void EditBoxes::SetWidth(TAutoVal& val)
{
  AUTONAMES0("Width")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal EditBoxes::GetZOrder()
{
  AUTONAMES0("ZOrder")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void EditBoxes::SetZOrder(TAutoVal& val)
{
  AUTONAMES0("ZOrder")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal EditBoxes::_NewEnum()
{
  AUTONAMES0("_NewEnum")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal EditBoxes::Add(TAutoVal& Left, TAutoVal& Top, TAutoVal& Width, TAutoVal& Height)
{
  AUTONAMES0("Add")
  AUTOARGS4(Left, Top, Width, Height)
  AUTOCALL_METHOD_RET
}

TAutoVal EditBoxes::Application()
{
  AUTONAMES0("Application")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal EditBoxes::BringToFront()
{
  AUTONAMES0("BringToFront")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal EditBoxes::Characters(TAutoVal& Start, TAutoVal& Length)
{
  AUTONAMES0("Characters")
  AUTOARGS2(Start, Length)
  AUTOCALL_METHOD_RET
}

TAutoVal EditBoxes::Copy()
{
  AUTONAMES0("Copy")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal EditBoxes::CopyPicture(TAutoVal& Appearance, TAutoVal& Format)
{
  AUTONAMES0("CopyPicture")
  AUTOARGS2(Appearance, Format)
  AUTOCALL_METHOD_RET
}

TAutoVal EditBoxes::Cut()
{
  AUTONAMES0("Cut")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal EditBoxes::Delete()
{
  AUTONAMES0("Delete")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal EditBoxes::Duplicate()
{
  AUTONAMES0("Duplicate")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal EditBoxes::Group()
{
  AUTONAMES0("Group")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal EditBoxes::Item(TAutoVal& Index)
{
  AUTONAMES0("Item")
  AUTOARGS1(Index)
  AUTOCALL_METHOD_RET
}

TAutoVal EditBoxes::Select(TAutoVal& Replace)
{
  AUTONAMES0("Select")
  AUTOARGS1(Replace)
  AUTOCALL_METHOD_RET
}

TAutoVal EditBoxes::SendToBack()
{
  AUTONAMES0("SendToBack")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}


// TKIND_DISPATCH: CheckBox {0002087F-0000-0000-C000-000000000046}\9

TAutoVal CheckBox::GetAccelerator()
{
  AUTONAMES0("Accelerator")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void CheckBox::SetAccelerator(TAutoVal& val)
{
  AUTONAMES0("Accelerator")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal CheckBox::GetBorder()
{
  AUTONAMES0("Border")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void CheckBox::SetBorder(TAutoVal& val)
{
  AUTONAMES0("Border")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal CheckBox::GetBottomRightCell()
{
  AUTONAMES0("BottomRightCell")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void CheckBox::SetBottomRightCell(TAutoVal& val)
{
  AUTONAMES0("BottomRightCell")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal CheckBox::GetCaption()
{
  AUTONAMES0("Caption")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void CheckBox::SetCaption(TAutoVal& val)
{
  AUTONAMES0("Caption")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal CheckBox::GetCreator()
{
  AUTONAMES0("Creator")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void CheckBox::SetCreator(TAutoVal& val)
{
  AUTONAMES0("Creator")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal CheckBox::GetDisplay3DShading()
{
  AUTONAMES0("Display3DShading")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void CheckBox::SetDisplay3DShading(TAutoVal& val)
{
  AUTONAMES0("Display3DShading")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal CheckBox::GetEnabled()
{
  AUTONAMES0("Enabled")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void CheckBox::SetEnabled(TAutoVal& val)
{
  AUTONAMES0("Enabled")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal CheckBox::GetHeight()
{
  AUTONAMES0("Height")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void CheckBox::SetHeight(TAutoVal& val)
{
  AUTONAMES0("Height")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal CheckBox::GetIndex()
{
  AUTONAMES0("Index")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void CheckBox::SetIndex(TAutoVal& val)
{
  AUTONAMES0("Index")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal CheckBox::GetInterior()
{
  AUTONAMES0("Interior")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void CheckBox::SetInterior(TAutoVal& val)
{
  AUTONAMES0("Interior")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal CheckBox::GetLeft()
{
  AUTONAMES0("Left")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void CheckBox::SetLeft(TAutoVal& val)
{
  AUTONAMES0("Left")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal CheckBox::GetLinkedCell()
{
  AUTONAMES0("LinkedCell")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void CheckBox::SetLinkedCell(TAutoVal& val)
{
  AUTONAMES0("LinkedCell")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal CheckBox::GetLocked()
{
  AUTONAMES0("Locked")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void CheckBox::SetLocked(TAutoVal& val)
{
  AUTONAMES0("Locked")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal CheckBox::GetLockedText()
{
  AUTONAMES0("LockedText")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void CheckBox::SetLockedText(TAutoVal& val)
{
  AUTONAMES0("LockedText")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal CheckBox::GetName()
{
  AUTONAMES0("Name")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void CheckBox::SetName(TAutoVal& val)
{
  AUTONAMES0("Name")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal CheckBox::GetOnAction()
{
  AUTONAMES0("OnAction")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void CheckBox::SetOnAction(TAutoVal& val)
{
  AUTONAMES0("OnAction")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal CheckBox::GetParent()
{
  AUTONAMES0("Parent")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void CheckBox::SetParent(TAutoVal& val)
{
  AUTONAMES0("Parent")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal CheckBox::GetPhoneticAccelerator()
{
  AUTONAMES0("PhoneticAccelerator")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void CheckBox::SetPhoneticAccelerator(TAutoVal& val)
{
  AUTONAMES0("PhoneticAccelerator")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal CheckBox::GetPlacement()
{
  AUTONAMES0("Placement")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void CheckBox::SetPlacement(TAutoVal& val)
{
  AUTONAMES0("Placement")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal CheckBox::GetPrintObject()
{
  AUTONAMES0("PrintObject")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void CheckBox::SetPrintObject(TAutoVal& val)
{
  AUTONAMES0("PrintObject")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal CheckBox::GetText()
{
  AUTONAMES0("Text")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void CheckBox::SetText(TAutoVal& val)
{
  AUTONAMES0("Text")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal CheckBox::GetTop()
{
  AUTONAMES0("Top")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void CheckBox::SetTop(TAutoVal& val)
{
  AUTONAMES0("Top")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal CheckBox::GetTopLeftCell()
{
  AUTONAMES0("TopLeftCell")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void CheckBox::SetTopLeftCell(TAutoVal& val)
{
  AUTONAMES0("TopLeftCell")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal CheckBox::GetValue()
{
  AUTONAMES0("Value")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void CheckBox::SetValue(TAutoVal& val)
{
  AUTONAMES0("Value")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal CheckBox::GetVisible()
{
  AUTONAMES0("Visible")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void CheckBox::SetVisible(TAutoVal& val)
{
  AUTONAMES0("Visible")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal CheckBox::GetWidth()
{
  AUTONAMES0("Width")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void CheckBox::SetWidth(TAutoVal& val)
{
  AUTONAMES0("Width")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal CheckBox::GetZOrder()
{
  AUTONAMES0("ZOrder")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void CheckBox::SetZOrder(TAutoVal& val)
{
  AUTONAMES0("ZOrder")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal CheckBox::Application()
{
  AUTONAMES0("Application")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal CheckBox::BringToFront()
{
  AUTONAMES0("BringToFront")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal CheckBox::Characters(TAutoVal& Start, TAutoVal& Length)
{
  AUTONAMES0("Characters")
  AUTOARGS2(Start, Length)
  AUTOCALL_METHOD_RET
}

TAutoVal CheckBox::CheckSpelling(TAutoVal& CustomDictionary, TAutoVal& IgnoreUppercase, TAutoVal& AlwaysSuggest)
{
  AUTONAMES0("CheckSpelling")
  AUTOARGS3(CustomDictionary, IgnoreUppercase, AlwaysSuggest)
  AUTOCALL_METHOD_RET
}

TAutoVal CheckBox::Copy()
{
  AUTONAMES0("Copy")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal CheckBox::CopyPicture(TAutoVal& Appearance, TAutoVal& Format)
{
  AUTONAMES0("CopyPicture")
  AUTOARGS2(Appearance, Format)
  AUTOCALL_METHOD_RET
}

TAutoVal CheckBox::Cut()
{
  AUTONAMES0("Cut")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal CheckBox::Delete()
{
  AUTONAMES0("Delete")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal CheckBox::Duplicate()
{
  AUTONAMES0("Duplicate")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal CheckBox::Select(TAutoVal& Replace)
{
  AUTONAMES0("Select")
  AUTOARGS1(Replace)
  AUTOCALL_METHOD_RET
}

TAutoVal CheckBox::SendToBack()
{
  AUTONAMES0("SendToBack")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}


// TKIND_DISPATCH: CheckBoxes {00020880-0000-0000-C000-000000000046}\9

TAutoVal CheckBoxes::GetAccelerator()
{
  AUTONAMES0("Accelerator")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void CheckBoxes::SetAccelerator(TAutoVal& val)
{
  AUTONAMES0("Accelerator")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal CheckBoxes::GetBorder()
{
  AUTONAMES0("Border")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void CheckBoxes::SetBorder(TAutoVal& val)
{
  AUTONAMES0("Border")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal CheckBoxes::GetCaption()
{
  AUTONAMES0("Caption")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void CheckBoxes::SetCaption(TAutoVal& val)
{
  AUTONAMES0("Caption")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal CheckBoxes::GetCount()
{
  AUTONAMES0("Count")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void CheckBoxes::SetCount(TAutoVal& val)
{
  AUTONAMES0("Count")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal CheckBoxes::GetCreator()
{
  AUTONAMES0("Creator")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void CheckBoxes::SetCreator(TAutoVal& val)
{
  AUTONAMES0("Creator")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal CheckBoxes::GetDisplay3DShading()
{
  AUTONAMES0("Display3DShading")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void CheckBoxes::SetDisplay3DShading(TAutoVal& val)
{
  AUTONAMES0("Display3DShading")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal CheckBoxes::GetEnabled()
{
  AUTONAMES0("Enabled")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void CheckBoxes::SetEnabled(TAutoVal& val)
{
  AUTONAMES0("Enabled")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal CheckBoxes::GetHeight()
{
  AUTONAMES0("Height")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void CheckBoxes::SetHeight(TAutoVal& val)
{
  AUTONAMES0("Height")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal CheckBoxes::GetInterior()
{
  AUTONAMES0("Interior")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void CheckBoxes::SetInterior(TAutoVal& val)
{
  AUTONAMES0("Interior")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal CheckBoxes::GetLeft()
{
  AUTONAMES0("Left")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void CheckBoxes::SetLeft(TAutoVal& val)
{
  AUTONAMES0("Left")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal CheckBoxes::GetLinkedCell()
{
  AUTONAMES0("LinkedCell")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void CheckBoxes::SetLinkedCell(TAutoVal& val)
{
  AUTONAMES0("LinkedCell")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal CheckBoxes::GetLocked()
{
  AUTONAMES0("Locked")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void CheckBoxes::SetLocked(TAutoVal& val)
{
  AUTONAMES0("Locked")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal CheckBoxes::GetLockedText()
{
  AUTONAMES0("LockedText")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void CheckBoxes::SetLockedText(TAutoVal& val)
{
  AUTONAMES0("LockedText")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal CheckBoxes::GetOnAction()
{
  AUTONAMES0("OnAction")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void CheckBoxes::SetOnAction(TAutoVal& val)
{
  AUTONAMES0("OnAction")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal CheckBoxes::GetParent()
{
  AUTONAMES0("Parent")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void CheckBoxes::SetParent(TAutoVal& val)
{
  AUTONAMES0("Parent")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal CheckBoxes::GetPhoneticAccelerator()
{
  AUTONAMES0("PhoneticAccelerator")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void CheckBoxes::SetPhoneticAccelerator(TAutoVal& val)
{
  AUTONAMES0("PhoneticAccelerator")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal CheckBoxes::GetPlacement()
{
  AUTONAMES0("Placement")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void CheckBoxes::SetPlacement(TAutoVal& val)
{
  AUTONAMES0("Placement")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal CheckBoxes::GetPrintObject()
{
  AUTONAMES0("PrintObject")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void CheckBoxes::SetPrintObject(TAutoVal& val)
{
  AUTONAMES0("PrintObject")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal CheckBoxes::GetText()
{
  AUTONAMES0("Text")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void CheckBoxes::SetText(TAutoVal& val)
{
  AUTONAMES0("Text")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal CheckBoxes::GetTop()
{
  AUTONAMES0("Top")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void CheckBoxes::SetTop(TAutoVal& val)
{
  AUTONAMES0("Top")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal CheckBoxes::GetValue()
{
  AUTONAMES0("Value")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void CheckBoxes::SetValue(TAutoVal& val)
{
  AUTONAMES0("Value")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal CheckBoxes::GetVisible()
{
  AUTONAMES0("Visible")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void CheckBoxes::SetVisible(TAutoVal& val)
{
  AUTONAMES0("Visible")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal CheckBoxes::GetWidth()
{
  AUTONAMES0("Width")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void CheckBoxes::SetWidth(TAutoVal& val)
{
  AUTONAMES0("Width")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal CheckBoxes::GetZOrder()
{
  AUTONAMES0("ZOrder")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void CheckBoxes::SetZOrder(TAutoVal& val)
{
  AUTONAMES0("ZOrder")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal CheckBoxes::_NewEnum()
{
  AUTONAMES0("_NewEnum")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal CheckBoxes::Add(TAutoVal& Left, TAutoVal& Top, TAutoVal& Width, TAutoVal& Height)
{
  AUTONAMES0("Add")
  AUTOARGS4(Left, Top, Width, Height)
  AUTOCALL_METHOD_RET
}

TAutoVal CheckBoxes::Application()
{
  AUTONAMES0("Application")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal CheckBoxes::BringToFront()
{
  AUTONAMES0("BringToFront")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal CheckBoxes::Characters(TAutoVal& Start, TAutoVal& Length)
{
  AUTONAMES0("Characters")
  AUTOARGS2(Start, Length)
  AUTOCALL_METHOD_RET
}

TAutoVal CheckBoxes::CheckSpelling(TAutoVal& CustomDictionary, TAutoVal& IgnoreUppercase, TAutoVal& AlwaysSuggest)
{
  AUTONAMES0("CheckSpelling")
  AUTOARGS3(CustomDictionary, IgnoreUppercase, AlwaysSuggest)
  AUTOCALL_METHOD_RET
}

TAutoVal CheckBoxes::Copy()
{
  AUTONAMES0("Copy")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal CheckBoxes::CopyPicture(TAutoVal& Appearance, TAutoVal& Format)
{
  AUTONAMES0("CopyPicture")
  AUTOARGS2(Appearance, Format)
  AUTOCALL_METHOD_RET
}

TAutoVal CheckBoxes::Cut()
{
  AUTONAMES0("Cut")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal CheckBoxes::Delete()
{
  AUTONAMES0("Delete")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal CheckBoxes::Duplicate()
{
  AUTONAMES0("Duplicate")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal CheckBoxes::Group()
{
  AUTONAMES0("Group")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal CheckBoxes::Item(TAutoVal& Index)
{
  AUTONAMES0("Item")
  AUTOARGS1(Index)
  AUTOCALL_METHOD_RET
}

TAutoVal CheckBoxes::Select(TAutoVal& Replace)
{
  AUTONAMES0("Select")
  AUTOARGS1(Replace)
  AUTOCALL_METHOD_RET
}

TAutoVal CheckBoxes::SendToBack()
{
  AUTONAMES0("SendToBack")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}


// TKIND_DISPATCH: OptionButton {00020881-0000-0000-C000-000000000046}\9

TAutoVal OptionButton::GetAccelerator()
{
  AUTONAMES0("Accelerator")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void OptionButton::SetAccelerator(TAutoVal& val)
{
  AUTONAMES0("Accelerator")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal OptionButton::GetBorder()
{
  AUTONAMES0("Border")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void OptionButton::SetBorder(TAutoVal& val)
{
  AUTONAMES0("Border")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal OptionButton::GetBottomRightCell()
{
  AUTONAMES0("BottomRightCell")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void OptionButton::SetBottomRightCell(TAutoVal& val)
{
  AUTONAMES0("BottomRightCell")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal OptionButton::GetCaption()
{
  AUTONAMES0("Caption")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void OptionButton::SetCaption(TAutoVal& val)
{
  AUTONAMES0("Caption")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal OptionButton::GetCreator()
{
  AUTONAMES0("Creator")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void OptionButton::SetCreator(TAutoVal& val)
{
  AUTONAMES0("Creator")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal OptionButton::GetDisplay3DShading()
{
  AUTONAMES0("Display3DShading")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void OptionButton::SetDisplay3DShading(TAutoVal& val)
{
  AUTONAMES0("Display3DShading")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal OptionButton::GetEnabled()
{
  AUTONAMES0("Enabled")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void OptionButton::SetEnabled(TAutoVal& val)
{
  AUTONAMES0("Enabled")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal OptionButton::GetHeight()
{
  AUTONAMES0("Height")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void OptionButton::SetHeight(TAutoVal& val)
{
  AUTONAMES0("Height")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal OptionButton::GetIndex()
{
  AUTONAMES0("Index")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void OptionButton::SetIndex(TAutoVal& val)
{
  AUTONAMES0("Index")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal OptionButton::GetInterior()
{
  AUTONAMES0("Interior")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void OptionButton::SetInterior(TAutoVal& val)
{
  AUTONAMES0("Interior")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal OptionButton::GetLeft()
{
  AUTONAMES0("Left")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void OptionButton::SetLeft(TAutoVal& val)
{
  AUTONAMES0("Left")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal OptionButton::GetLinkedCell()
{
  AUTONAMES0("LinkedCell")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void OptionButton::SetLinkedCell(TAutoVal& val)
{
  AUTONAMES0("LinkedCell")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal OptionButton::GetLocked()
{
  AUTONAMES0("Locked")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void OptionButton::SetLocked(TAutoVal& val)
{
  AUTONAMES0("Locked")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal OptionButton::GetLockedText()
{
  AUTONAMES0("LockedText")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void OptionButton::SetLockedText(TAutoVal& val)
{
  AUTONAMES0("LockedText")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal OptionButton::GetName()
{
  AUTONAMES0("Name")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void OptionButton::SetName(TAutoVal& val)
{
  AUTONAMES0("Name")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal OptionButton::GetOnAction()
{
  AUTONAMES0("OnAction")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void OptionButton::SetOnAction(TAutoVal& val)
{
  AUTONAMES0("OnAction")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal OptionButton::GetParent()
{
  AUTONAMES0("Parent")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void OptionButton::SetParent(TAutoVal& val)
{
  AUTONAMES0("Parent")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal OptionButton::GetPhoneticAccelerator()
{
  AUTONAMES0("PhoneticAccelerator")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void OptionButton::SetPhoneticAccelerator(TAutoVal& val)
{
  AUTONAMES0("PhoneticAccelerator")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal OptionButton::GetPlacement()
{
  AUTONAMES0("Placement")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void OptionButton::SetPlacement(TAutoVal& val)
{
  AUTONAMES0("Placement")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal OptionButton::GetPrintObject()
{
  AUTONAMES0("PrintObject")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void OptionButton::SetPrintObject(TAutoVal& val)
{
  AUTONAMES0("PrintObject")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal OptionButton::GetText()
{
  AUTONAMES0("Text")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void OptionButton::SetText(TAutoVal& val)
{
  AUTONAMES0("Text")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal OptionButton::GetTop()
{
  AUTONAMES0("Top")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void OptionButton::SetTop(TAutoVal& val)
{
  AUTONAMES0("Top")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal OptionButton::GetTopLeftCell()
{
  AUTONAMES0("TopLeftCell")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void OptionButton::SetTopLeftCell(TAutoVal& val)
{
  AUTONAMES0("TopLeftCell")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal OptionButton::GetValue()
{
  AUTONAMES0("Value")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void OptionButton::SetValue(TAutoVal& val)
{
  AUTONAMES0("Value")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal OptionButton::GetVisible()
{
  AUTONAMES0("Visible")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void OptionButton::SetVisible(TAutoVal& val)
{
  AUTONAMES0("Visible")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal OptionButton::GetWidth()
{
  AUTONAMES0("Width")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void OptionButton::SetWidth(TAutoVal& val)
{
  AUTONAMES0("Width")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal OptionButton::GetZOrder()
{
  AUTONAMES0("ZOrder")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void OptionButton::SetZOrder(TAutoVal& val)
{
  AUTONAMES0("ZOrder")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal OptionButton::Application()
{
  AUTONAMES0("Application")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal OptionButton::BringToFront()
{
  AUTONAMES0("BringToFront")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal OptionButton::Characters(TAutoVal& Start, TAutoVal& Length)
{
  AUTONAMES0("Characters")
  AUTOARGS2(Start, Length)
  AUTOCALL_METHOD_RET
}

TAutoVal OptionButton::CheckSpelling(TAutoVal& CustomDictionary, TAutoVal& IgnoreUppercase, TAutoVal& AlwaysSuggest)
{
  AUTONAMES0("CheckSpelling")
  AUTOARGS3(CustomDictionary, IgnoreUppercase, AlwaysSuggest)
  AUTOCALL_METHOD_RET
}

TAutoVal OptionButton::Copy()
{
  AUTONAMES0("Copy")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal OptionButton::CopyPicture(TAutoVal& Appearance, TAutoVal& Format)
{
  AUTONAMES0("CopyPicture")
  AUTOARGS2(Appearance, Format)
  AUTOCALL_METHOD_RET
}

TAutoVal OptionButton::Cut()
{
  AUTONAMES0("Cut")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal OptionButton::Delete()
{
  AUTONAMES0("Delete")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal OptionButton::Duplicate()
{
  AUTONAMES0("Duplicate")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal OptionButton::Select(TAutoVal& Replace)
{
  AUTONAMES0("Select")
  AUTOARGS1(Replace)
  AUTOCALL_METHOD_RET
}

TAutoVal OptionButton::SendToBack()
{
  AUTONAMES0("SendToBack")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}


// TKIND_DISPATCH: OptionButtons {00020882-0000-0000-C000-000000000046}\9

TAutoVal OptionButtons::GetAccelerator()
{
  AUTONAMES0("Accelerator")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void OptionButtons::SetAccelerator(TAutoVal& val)
{
  AUTONAMES0("Accelerator")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal OptionButtons::GetBorder()
{
  AUTONAMES0("Border")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void OptionButtons::SetBorder(TAutoVal& val)
{
  AUTONAMES0("Border")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal OptionButtons::GetCaption()
{
  AUTONAMES0("Caption")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void OptionButtons::SetCaption(TAutoVal& val)
{
  AUTONAMES0("Caption")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal OptionButtons::GetCount()
{
  AUTONAMES0("Count")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void OptionButtons::SetCount(TAutoVal& val)
{
  AUTONAMES0("Count")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal OptionButtons::GetCreator()
{
  AUTONAMES0("Creator")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void OptionButtons::SetCreator(TAutoVal& val)
{
  AUTONAMES0("Creator")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal OptionButtons::GetDisplay3DShading()
{
  AUTONAMES0("Display3DShading")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void OptionButtons::SetDisplay3DShading(TAutoVal& val)
{
  AUTONAMES0("Display3DShading")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal OptionButtons::GetEnabled()
{
  AUTONAMES0("Enabled")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void OptionButtons::SetEnabled(TAutoVal& val)
{
  AUTONAMES0("Enabled")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal OptionButtons::GetHeight()
{
  AUTONAMES0("Height")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void OptionButtons::SetHeight(TAutoVal& val)
{
  AUTONAMES0("Height")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal OptionButtons::GetInterior()
{
  AUTONAMES0("Interior")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void OptionButtons::SetInterior(TAutoVal& val)
{
  AUTONAMES0("Interior")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal OptionButtons::GetLeft()
{
  AUTONAMES0("Left")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void OptionButtons::SetLeft(TAutoVal& val)
{
  AUTONAMES0("Left")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal OptionButtons::GetLinkedCell()
{
  AUTONAMES0("LinkedCell")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void OptionButtons::SetLinkedCell(TAutoVal& val)
{
  AUTONAMES0("LinkedCell")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal OptionButtons::GetLocked()
{
  AUTONAMES0("Locked")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void OptionButtons::SetLocked(TAutoVal& val)
{
  AUTONAMES0("Locked")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal OptionButtons::GetLockedText()
{
  AUTONAMES0("LockedText")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void OptionButtons::SetLockedText(TAutoVal& val)
{
  AUTONAMES0("LockedText")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal OptionButtons::GetOnAction()
{
  AUTONAMES0("OnAction")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void OptionButtons::SetOnAction(TAutoVal& val)
{
  AUTONAMES0("OnAction")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal OptionButtons::GetParent()
{
  AUTONAMES0("Parent")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void OptionButtons::SetParent(TAutoVal& val)
{
  AUTONAMES0("Parent")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal OptionButtons::GetPhoneticAccelerator()
{
  AUTONAMES0("PhoneticAccelerator")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void OptionButtons::SetPhoneticAccelerator(TAutoVal& val)
{
  AUTONAMES0("PhoneticAccelerator")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal OptionButtons::GetPlacement()
{
  AUTONAMES0("Placement")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void OptionButtons::SetPlacement(TAutoVal& val)
{
  AUTONAMES0("Placement")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal OptionButtons::GetPrintObject()
{
  AUTONAMES0("PrintObject")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void OptionButtons::SetPrintObject(TAutoVal& val)
{
  AUTONAMES0("PrintObject")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal OptionButtons::GetText()
{
  AUTONAMES0("Text")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void OptionButtons::SetText(TAutoVal& val)
{
  AUTONAMES0("Text")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal OptionButtons::GetTop()
{
  AUTONAMES0("Top")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void OptionButtons::SetTop(TAutoVal& val)
{
  AUTONAMES0("Top")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal OptionButtons::GetValue()
{
  AUTONAMES0("Value")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void OptionButtons::SetValue(TAutoVal& val)
{
  AUTONAMES0("Value")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal OptionButtons::GetVisible()
{
  AUTONAMES0("Visible")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void OptionButtons::SetVisible(TAutoVal& val)
{
  AUTONAMES0("Visible")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal OptionButtons::GetWidth()
{
  AUTONAMES0("Width")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void OptionButtons::SetWidth(TAutoVal& val)
{
  AUTONAMES0("Width")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal OptionButtons::GetZOrder()
{
  AUTONAMES0("ZOrder")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void OptionButtons::SetZOrder(TAutoVal& val)
{
  AUTONAMES0("ZOrder")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal OptionButtons::_NewEnum()
{
  AUTONAMES0("_NewEnum")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal OptionButtons::Add(TAutoVal& Left, TAutoVal& Top, TAutoVal& Width, TAutoVal& Height)
{
  AUTONAMES0("Add")
  AUTOARGS4(Left, Top, Width, Height)
  AUTOCALL_METHOD_RET
}

TAutoVal OptionButtons::Application()
{
  AUTONAMES0("Application")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal OptionButtons::BringToFront()
{
  AUTONAMES0("BringToFront")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal OptionButtons::Characters(TAutoVal& Start, TAutoVal& Length)
{
  AUTONAMES0("Characters")
  AUTOARGS2(Start, Length)
  AUTOCALL_METHOD_RET
}

TAutoVal OptionButtons::CheckSpelling(TAutoVal& CustomDictionary, TAutoVal& IgnoreUppercase, TAutoVal& AlwaysSuggest)
{
  AUTONAMES0("CheckSpelling")
  AUTOARGS3(CustomDictionary, IgnoreUppercase, AlwaysSuggest)
  AUTOCALL_METHOD_RET
}

TAutoVal OptionButtons::Copy()
{
  AUTONAMES0("Copy")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal OptionButtons::CopyPicture(TAutoVal& Appearance, TAutoVal& Format)
{
  AUTONAMES0("CopyPicture")
  AUTOARGS2(Appearance, Format)
  AUTOCALL_METHOD_RET
}

TAutoVal OptionButtons::Cut()
{
  AUTONAMES0("Cut")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal OptionButtons::Delete()
{
  AUTONAMES0("Delete")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal OptionButtons::Duplicate()
{
  AUTONAMES0("Duplicate")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal OptionButtons::Group()
{
  AUTONAMES0("Group")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal OptionButtons::Item(TAutoVal& Index)
{
  AUTONAMES0("Item")
  AUTOARGS1(Index)
  AUTOCALL_METHOD_RET
}

TAutoVal OptionButtons::Select(TAutoVal& Replace)
{
  AUTONAMES0("Select")
  AUTOARGS1(Replace)
  AUTOCALL_METHOD_RET
}

TAutoVal OptionButtons::SendToBack()
{
  AUTONAMES0("SendToBack")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}


// TKIND_DISPATCH: Spinner {0002088D-0000-0000-C000-000000000046}\9

TAutoVal Spinner::GetBottomRightCell()
{
  AUTONAMES0("BottomRightCell")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Spinner::SetBottomRightCell(TAutoVal& val)
{
  AUTONAMES0("BottomRightCell")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Spinner::GetCreator()
{
  AUTONAMES0("Creator")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Spinner::SetCreator(TAutoVal& val)
{
  AUTONAMES0("Creator")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Spinner::GetDisplay3DShading()
{
  AUTONAMES0("Display3DShading")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Spinner::SetDisplay3DShading(TAutoVal& val)
{
  AUTONAMES0("Display3DShading")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Spinner::GetEnabled()
{
  AUTONAMES0("Enabled")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Spinner::SetEnabled(TAutoVal& val)
{
  AUTONAMES0("Enabled")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Spinner::GetHeight()
{
  AUTONAMES0("Height")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Spinner::SetHeight(TAutoVal& val)
{
  AUTONAMES0("Height")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Spinner::GetIndex()
{
  AUTONAMES0("Index")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Spinner::SetIndex(TAutoVal& val)
{
  AUTONAMES0("Index")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Spinner::GetLeft()
{
  AUTONAMES0("Left")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Spinner::SetLeft(TAutoVal& val)
{
  AUTONAMES0("Left")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Spinner::GetLinkedCell()
{
  AUTONAMES0("LinkedCell")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Spinner::SetLinkedCell(TAutoVal& val)
{
  AUTONAMES0("LinkedCell")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Spinner::GetLocked()
{
  AUTONAMES0("Locked")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Spinner::SetLocked(TAutoVal& val)
{
  AUTONAMES0("Locked")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Spinner::GetMax()
{
  AUTONAMES0("Max")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Spinner::SetMax(TAutoVal& val)
{
  AUTONAMES0("Max")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Spinner::GetMin()
{
  AUTONAMES0("Min")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Spinner::SetMin(TAutoVal& val)
{
  AUTONAMES0("Min")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Spinner::GetName()
{
  AUTONAMES0("Name")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Spinner::SetName(TAutoVal& val)
{
  AUTONAMES0("Name")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Spinner::GetOnAction()
{
  AUTONAMES0("OnAction")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Spinner::SetOnAction(TAutoVal& val)
{
  AUTONAMES0("OnAction")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Spinner::GetParent()
{
  AUTONAMES0("Parent")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Spinner::SetParent(TAutoVal& val)
{
  AUTONAMES0("Parent")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Spinner::GetPlacement()
{
  AUTONAMES0("Placement")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Spinner::SetPlacement(TAutoVal& val)
{
  AUTONAMES0("Placement")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Spinner::GetPrintObject()
{
  AUTONAMES0("PrintObject")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Spinner::SetPrintObject(TAutoVal& val)
{
  AUTONAMES0("PrintObject")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Spinner::GetSmallChange()
{
  AUTONAMES0("SmallChange")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Spinner::SetSmallChange(TAutoVal& val)
{
  AUTONAMES0("SmallChange")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Spinner::GetTop()
{
  AUTONAMES0("Top")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Spinner::SetTop(TAutoVal& val)
{
  AUTONAMES0("Top")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Spinner::GetTopLeftCell()
{
  AUTONAMES0("TopLeftCell")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Spinner::SetTopLeftCell(TAutoVal& val)
{
  AUTONAMES0("TopLeftCell")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Spinner::GetValue()
{
  AUTONAMES0("Value")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Spinner::SetValue(TAutoVal& val)
{
  AUTONAMES0("Value")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Spinner::GetVisible()
{
  AUTONAMES0("Visible")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Spinner::SetVisible(TAutoVal& val)
{
  AUTONAMES0("Visible")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Spinner::GetWidth()
{
  AUTONAMES0("Width")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Spinner::SetWidth(TAutoVal& val)
{
  AUTONAMES0("Width")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Spinner::GetZOrder()
{
  AUTONAMES0("ZOrder")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Spinner::SetZOrder(TAutoVal& val)
{
  AUTONAMES0("ZOrder")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Spinner::Application()
{
  AUTONAMES0("Application")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Spinner::BringToFront()
{
  AUTONAMES0("BringToFront")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Spinner::Copy()
{
  AUTONAMES0("Copy")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Spinner::CopyPicture(TAutoVal& Appearance, TAutoVal& Format)
{
  AUTONAMES0("CopyPicture")
  AUTOARGS2(Appearance, Format)
  AUTOCALL_METHOD_RET
}

TAutoVal Spinner::Cut()
{
  AUTONAMES0("Cut")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Spinner::Delete()
{
  AUTONAMES0("Delete")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Spinner::Duplicate()
{
  AUTONAMES0("Duplicate")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Spinner::Select(TAutoVal& Replace)
{
  AUTONAMES0("Select")
  AUTOARGS1(Replace)
  AUTOCALL_METHOD_RET
}

TAutoVal Spinner::SendToBack()
{
  AUTONAMES0("SendToBack")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}


// TKIND_DISPATCH: Spinners {0002088E-0000-0000-C000-000000000046}\9

TAutoVal Spinners::GetCount()
{
  AUTONAMES0("Count")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Spinners::SetCount(TAutoVal& val)
{
  AUTONAMES0("Count")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Spinners::GetCreator()
{
  AUTONAMES0("Creator")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Spinners::SetCreator(TAutoVal& val)
{
  AUTONAMES0("Creator")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Spinners::GetDisplay3DShading()
{
  AUTONAMES0("Display3DShading")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Spinners::SetDisplay3DShading(TAutoVal& val)
{
  AUTONAMES0("Display3DShading")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Spinners::GetEnabled()
{
  AUTONAMES0("Enabled")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Spinners::SetEnabled(TAutoVal& val)
{
  AUTONAMES0("Enabled")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Spinners::GetHeight()
{
  AUTONAMES0("Height")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Spinners::SetHeight(TAutoVal& val)
{
  AUTONAMES0("Height")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Spinners::GetLeft()
{
  AUTONAMES0("Left")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Spinners::SetLeft(TAutoVal& val)
{
  AUTONAMES0("Left")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Spinners::GetLinkedCell()
{
  AUTONAMES0("LinkedCell")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Spinners::SetLinkedCell(TAutoVal& val)
{
  AUTONAMES0("LinkedCell")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Spinners::GetLocked()
{
  AUTONAMES0("Locked")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Spinners::SetLocked(TAutoVal& val)
{
  AUTONAMES0("Locked")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Spinners::GetMax()
{
  AUTONAMES0("Max")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Spinners::SetMax(TAutoVal& val)
{
  AUTONAMES0("Max")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Spinners::GetMin()
{
  AUTONAMES0("Min")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Spinners::SetMin(TAutoVal& val)
{
  AUTONAMES0("Min")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Spinners::GetOnAction()
{
  AUTONAMES0("OnAction")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Spinners::SetOnAction(TAutoVal& val)
{
  AUTONAMES0("OnAction")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Spinners::GetParent()
{
  AUTONAMES0("Parent")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Spinners::SetParent(TAutoVal& val)
{
  AUTONAMES0("Parent")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Spinners::GetPlacement()
{
  AUTONAMES0("Placement")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Spinners::SetPlacement(TAutoVal& val)
{
  AUTONAMES0("Placement")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Spinners::GetPrintObject()
{
  AUTONAMES0("PrintObject")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Spinners::SetPrintObject(TAutoVal& val)
{
  AUTONAMES0("PrintObject")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Spinners::GetSmallChange()
{
  AUTONAMES0("SmallChange")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Spinners::SetSmallChange(TAutoVal& val)
{
  AUTONAMES0("SmallChange")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Spinners::GetTop()
{
  AUTONAMES0("Top")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Spinners::SetTop(TAutoVal& val)
{
  AUTONAMES0("Top")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Spinners::GetValue()
{
  AUTONAMES0("Value")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Spinners::SetValue(TAutoVal& val)
{
  AUTONAMES0("Value")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Spinners::GetVisible()
{
  AUTONAMES0("Visible")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Spinners::SetVisible(TAutoVal& val)
{
  AUTONAMES0("Visible")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Spinners::GetWidth()
{
  AUTONAMES0("Width")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Spinners::SetWidth(TAutoVal& val)
{
  AUTONAMES0("Width")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Spinners::GetZOrder()
{
  AUTONAMES0("ZOrder")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Spinners::SetZOrder(TAutoVal& val)
{
  AUTONAMES0("ZOrder")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Spinners::_NewEnum()
{
  AUTONAMES0("_NewEnum")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Spinners::Add(TAutoVal& Left, TAutoVal& Top, TAutoVal& Width, TAutoVal& Height)
{
  AUTONAMES0("Add")
  AUTOARGS4(Left, Top, Width, Height)
  AUTOCALL_METHOD_RET
}

TAutoVal Spinners::Application()
{
  AUTONAMES0("Application")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Spinners::BringToFront()
{
  AUTONAMES0("BringToFront")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Spinners::Copy()
{
  AUTONAMES0("Copy")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Spinners::CopyPicture(TAutoVal& Appearance, TAutoVal& Format)
{
  AUTONAMES0("CopyPicture")
  AUTOARGS2(Appearance, Format)
  AUTOCALL_METHOD_RET
}

TAutoVal Spinners::Cut()
{
  AUTONAMES0("Cut")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Spinners::Delete()
{
  AUTONAMES0("Delete")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Spinners::Duplicate()
{
  AUTONAMES0("Duplicate")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Spinners::Group()
{
  AUTONAMES0("Group")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Spinners::Item(TAutoVal& Index)
{
  AUTONAMES0("Item")
  AUTOARGS1(Index)
  AUTOCALL_METHOD_RET
}

TAutoVal Spinners::Select(TAutoVal& Replace)
{
  AUTONAMES0("Select")
  AUTOARGS1(Replace)
  AUTOCALL_METHOD_RET
}

TAutoVal Spinners::SendToBack()
{
  AUTONAMES0("SendToBack")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}


// TKIND_DISPATCH: ScrollBar {00020885-0000-0000-C000-000000000046}\9

TAutoVal ScrollBar::GetBottomRightCell()
{
  AUTONAMES0("BottomRightCell")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void ScrollBar::SetBottomRightCell(TAutoVal& val)
{
  AUTONAMES0("BottomRightCell")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal ScrollBar::GetCreator()
{
  AUTONAMES0("Creator")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void ScrollBar::SetCreator(TAutoVal& val)
{
  AUTONAMES0("Creator")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal ScrollBar::GetDisplay3DShading()
{
  AUTONAMES0("Display3DShading")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void ScrollBar::SetDisplay3DShading(TAutoVal& val)
{
  AUTONAMES0("Display3DShading")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal ScrollBar::GetEnabled()
{
  AUTONAMES0("Enabled")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void ScrollBar::SetEnabled(TAutoVal& val)
{
  AUTONAMES0("Enabled")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal ScrollBar::GetHeight()
{
  AUTONAMES0("Height")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void ScrollBar::SetHeight(TAutoVal& val)
{
  AUTONAMES0("Height")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal ScrollBar::GetIndex()
{
  AUTONAMES0("Index")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void ScrollBar::SetIndex(TAutoVal& val)
{
  AUTONAMES0("Index")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal ScrollBar::GetLargeChange()
{
  AUTONAMES0("LargeChange")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void ScrollBar::SetLargeChange(TAutoVal& val)
{
  AUTONAMES0("LargeChange")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal ScrollBar::GetLeft()
{
  AUTONAMES0("Left")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void ScrollBar::SetLeft(TAutoVal& val)
{
  AUTONAMES0("Left")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal ScrollBar::GetLinkedCell()
{
  AUTONAMES0("LinkedCell")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void ScrollBar::SetLinkedCell(TAutoVal& val)
{
  AUTONAMES0("LinkedCell")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal ScrollBar::GetLocked()
{
  AUTONAMES0("Locked")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void ScrollBar::SetLocked(TAutoVal& val)
{
  AUTONAMES0("Locked")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal ScrollBar::GetMax()
{
  AUTONAMES0("Max")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void ScrollBar::SetMax(TAutoVal& val)
{
  AUTONAMES0("Max")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal ScrollBar::GetMin()
{
  AUTONAMES0("Min")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void ScrollBar::SetMin(TAutoVal& val)
{
  AUTONAMES0("Min")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal ScrollBar::GetName()
{
  AUTONAMES0("Name")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void ScrollBar::SetName(TAutoVal& val)
{
  AUTONAMES0("Name")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal ScrollBar::GetOnAction()
{
  AUTONAMES0("OnAction")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void ScrollBar::SetOnAction(TAutoVal& val)
{
  AUTONAMES0("OnAction")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal ScrollBar::GetParent()
{
  AUTONAMES0("Parent")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void ScrollBar::SetParent(TAutoVal& val)
{
  AUTONAMES0("Parent")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal ScrollBar::GetPlacement()
{
  AUTONAMES0("Placement")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void ScrollBar::SetPlacement(TAutoVal& val)
{
  AUTONAMES0("Placement")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal ScrollBar::GetPrintObject()
{
  AUTONAMES0("PrintObject")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void ScrollBar::SetPrintObject(TAutoVal& val)
{
  AUTONAMES0("PrintObject")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal ScrollBar::GetSmallChange()
{
  AUTONAMES0("SmallChange")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void ScrollBar::SetSmallChange(TAutoVal& val)
{
  AUTONAMES0("SmallChange")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal ScrollBar::GetTop()
{
  AUTONAMES0("Top")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void ScrollBar::SetTop(TAutoVal& val)
{
  AUTONAMES0("Top")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal ScrollBar::GetTopLeftCell()
{
  AUTONAMES0("TopLeftCell")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void ScrollBar::SetTopLeftCell(TAutoVal& val)
{
  AUTONAMES0("TopLeftCell")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal ScrollBar::GetValue()
{
  AUTONAMES0("Value")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void ScrollBar::SetValue(TAutoVal& val)
{
  AUTONAMES0("Value")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal ScrollBar::GetVisible()
{
  AUTONAMES0("Visible")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void ScrollBar::SetVisible(TAutoVal& val)
{
  AUTONAMES0("Visible")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal ScrollBar::GetWidth()
{
  AUTONAMES0("Width")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void ScrollBar::SetWidth(TAutoVal& val)
{
  AUTONAMES0("Width")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal ScrollBar::GetZOrder()
{
  AUTONAMES0("ZOrder")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void ScrollBar::SetZOrder(TAutoVal& val)
{
  AUTONAMES0("ZOrder")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal ScrollBar::Application()
{
  AUTONAMES0("Application")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal ScrollBar::BringToFront()
{
  AUTONAMES0("BringToFront")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal ScrollBar::Copy()
{
  AUTONAMES0("Copy")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal ScrollBar::CopyPicture(TAutoVal& Appearance, TAutoVal& Format)
{
  AUTONAMES0("CopyPicture")
  AUTOARGS2(Appearance, Format)
  AUTOCALL_METHOD_RET
}

TAutoVal ScrollBar::Cut()
{
  AUTONAMES0("Cut")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal ScrollBar::Delete()
{
  AUTONAMES0("Delete")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal ScrollBar::Duplicate()
{
  AUTONAMES0("Duplicate")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal ScrollBar::Select(TAutoVal& Replace)
{
  AUTONAMES0("Select")
  AUTOARGS1(Replace)
  AUTOCALL_METHOD_RET
}

TAutoVal ScrollBar::SendToBack()
{
  AUTONAMES0("SendToBack")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}


// TKIND_DISPATCH: ScrollBars {00020886-0000-0000-C000-000000000046}\9

TAutoVal ScrollBars::GetCount()
{
  AUTONAMES0("Count")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void ScrollBars::SetCount(TAutoVal& val)
{
  AUTONAMES0("Count")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal ScrollBars::GetCreator()
{
  AUTONAMES0("Creator")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void ScrollBars::SetCreator(TAutoVal& val)
{
  AUTONAMES0("Creator")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal ScrollBars::GetDisplay3DShading()
{
  AUTONAMES0("Display3DShading")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void ScrollBars::SetDisplay3DShading(TAutoVal& val)
{
  AUTONAMES0("Display3DShading")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal ScrollBars::GetEnabled()
{
  AUTONAMES0("Enabled")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void ScrollBars::SetEnabled(TAutoVal& val)
{
  AUTONAMES0("Enabled")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal ScrollBars::GetHeight()
{
  AUTONAMES0("Height")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void ScrollBars::SetHeight(TAutoVal& val)
{
  AUTONAMES0("Height")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal ScrollBars::GetLargeChange()
{
  AUTONAMES0("LargeChange")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void ScrollBars::SetLargeChange(TAutoVal& val)
{
  AUTONAMES0("LargeChange")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal ScrollBars::GetLeft()
{
  AUTONAMES0("Left")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void ScrollBars::SetLeft(TAutoVal& val)
{
  AUTONAMES0("Left")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal ScrollBars::GetLinkedCell()
{
  AUTONAMES0("LinkedCell")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void ScrollBars::SetLinkedCell(TAutoVal& val)
{
  AUTONAMES0("LinkedCell")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal ScrollBars::GetLocked()
{
  AUTONAMES0("Locked")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void ScrollBars::SetLocked(TAutoVal& val)
{
  AUTONAMES0("Locked")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal ScrollBars::GetMax()
{
  AUTONAMES0("Max")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void ScrollBars::SetMax(TAutoVal& val)
{
  AUTONAMES0("Max")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal ScrollBars::GetMin()
{
  AUTONAMES0("Min")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void ScrollBars::SetMin(TAutoVal& val)
{
  AUTONAMES0("Min")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal ScrollBars::GetOnAction()
{
  AUTONAMES0("OnAction")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void ScrollBars::SetOnAction(TAutoVal& val)
{
  AUTONAMES0("OnAction")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal ScrollBars::GetParent()
{
  AUTONAMES0("Parent")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void ScrollBars::SetParent(TAutoVal& val)
{
  AUTONAMES0("Parent")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal ScrollBars::GetPlacement()
{
  AUTONAMES0("Placement")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void ScrollBars::SetPlacement(TAutoVal& val)
{
  AUTONAMES0("Placement")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal ScrollBars::GetPrintObject()
{
  AUTONAMES0("PrintObject")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void ScrollBars::SetPrintObject(TAutoVal& val)
{
  AUTONAMES0("PrintObject")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal ScrollBars::GetSmallChange()
{
  AUTONAMES0("SmallChange")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void ScrollBars::SetSmallChange(TAutoVal& val)
{
  AUTONAMES0("SmallChange")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal ScrollBars::GetTop()
{
  AUTONAMES0("Top")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void ScrollBars::SetTop(TAutoVal& val)
{
  AUTONAMES0("Top")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal ScrollBars::GetValue()
{
  AUTONAMES0("Value")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void ScrollBars::SetValue(TAutoVal& val)
{
  AUTONAMES0("Value")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal ScrollBars::GetVisible()
{
  AUTONAMES0("Visible")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void ScrollBars::SetVisible(TAutoVal& val)
{
  AUTONAMES0("Visible")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal ScrollBars::GetWidth()
{
  AUTONAMES0("Width")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void ScrollBars::SetWidth(TAutoVal& val)
{
  AUTONAMES0("Width")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal ScrollBars::GetZOrder()
{
  AUTONAMES0("ZOrder")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void ScrollBars::SetZOrder(TAutoVal& val)
{
  AUTONAMES0("ZOrder")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal ScrollBars::_NewEnum()
{
  AUTONAMES0("_NewEnum")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal ScrollBars::Add(TAutoVal& Left, TAutoVal& Top, TAutoVal& Width, TAutoVal& Height)
{
  AUTONAMES0("Add")
  AUTOARGS4(Left, Top, Width, Height)
  AUTOCALL_METHOD_RET
}

TAutoVal ScrollBars::Application()
{
  AUTONAMES0("Application")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal ScrollBars::BringToFront()
{
  AUTONAMES0("BringToFront")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal ScrollBars::Copy()
{
  AUTONAMES0("Copy")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal ScrollBars::CopyPicture(TAutoVal& Appearance, TAutoVal& Format)
{
  AUTONAMES0("CopyPicture")
  AUTOARGS2(Appearance, Format)
  AUTOCALL_METHOD_RET
}

TAutoVal ScrollBars::Cut()
{
  AUTONAMES0("Cut")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal ScrollBars::Delete()
{
  AUTONAMES0("Delete")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal ScrollBars::Duplicate()
{
  AUTONAMES0("Duplicate")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal ScrollBars::Group()
{
  AUTONAMES0("Group")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal ScrollBars::Item(TAutoVal& Index)
{
  AUTONAMES0("Item")
  AUTOARGS1(Index)
  AUTOCALL_METHOD_RET
}

TAutoVal ScrollBars::Select(TAutoVal& Replace)
{
  AUTONAMES0("Select")
  AUTOARGS1(Replace)
  AUTOCALL_METHOD_RET
}

TAutoVal ScrollBars::SendToBack()
{
  AUTONAMES0("SendToBack")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}


// TKIND_DISPATCH: ListBox {00020887-0000-0000-C000-000000000046}\9

TAutoVal ListBox::GetBottomRightCell()
{
  AUTONAMES0("BottomRightCell")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void ListBox::SetBottomRightCell(TAutoVal& val)
{
  AUTONAMES0("BottomRightCell")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal ListBox::GetCreator()
{
  AUTONAMES0("Creator")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void ListBox::SetCreator(TAutoVal& val)
{
  AUTONAMES0("Creator")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal ListBox::GetDisplay3DShading()
{
  AUTONAMES0("Display3DShading")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void ListBox::SetDisplay3DShading(TAutoVal& val)
{
  AUTONAMES0("Display3DShading")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal ListBox::GetEnabled()
{
  AUTONAMES0("Enabled")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void ListBox::SetEnabled(TAutoVal& val)
{
  AUTONAMES0("Enabled")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal ListBox::GetHeight()
{
  AUTONAMES0("Height")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void ListBox::SetHeight(TAutoVal& val)
{
  AUTONAMES0("Height")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal ListBox::GetIndex()
{
  AUTONAMES0("Index")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void ListBox::SetIndex(TAutoVal& val)
{
  AUTONAMES0("Index")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal ListBox::GetLeft()
{
  AUTONAMES0("Left")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void ListBox::SetLeft(TAutoVal& val)
{
  AUTONAMES0("Left")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal ListBox::GetLinkedCell()
{
  AUTONAMES0("LinkedCell")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void ListBox::SetLinkedCell(TAutoVal& val)
{
  AUTONAMES0("LinkedCell")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal ListBox::GetLinkedObject()
{
  AUTONAMES0("LinkedObject")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void ListBox::SetLinkedObject(TAutoVal& val)
{
  AUTONAMES0("LinkedObject")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal ListBox::GetList()
{
  AUTONAMES0("List")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void ListBox::SetList(TAutoVal& val)
{
  AUTONAMES0("List")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal ListBox::GetListCount()
{
  AUTONAMES0("ListCount")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void ListBox::SetListCount(TAutoVal& val)
{
  AUTONAMES0("ListCount")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal ListBox::GetListFillRange()
{
  AUTONAMES0("ListFillRange")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void ListBox::SetListFillRange(TAutoVal& val)
{
  AUTONAMES0("ListFillRange")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal ListBox::GetListIndex()
{
  AUTONAMES0("ListIndex")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void ListBox::SetListIndex(TAutoVal& val)
{
  AUTONAMES0("ListIndex")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal ListBox::GetLocked()
{
  AUTONAMES0("Locked")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void ListBox::SetLocked(TAutoVal& val)
{
  AUTONAMES0("Locked")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal ListBox::GetMultiSelect()
{
  AUTONAMES0("MultiSelect")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void ListBox::SetMultiSelect(TAutoVal& val)
{
  AUTONAMES0("MultiSelect")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal ListBox::GetName()
{
  AUTONAMES0("Name")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void ListBox::SetName(TAutoVal& val)
{
  AUTONAMES0("Name")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal ListBox::GetOnAction()
{
  AUTONAMES0("OnAction")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void ListBox::SetOnAction(TAutoVal& val)
{
  AUTONAMES0("OnAction")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal ListBox::GetParent()
{
  AUTONAMES0("Parent")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void ListBox::SetParent(TAutoVal& val)
{
  AUTONAMES0("Parent")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal ListBox::GetPlacement()
{
  AUTONAMES0("Placement")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void ListBox::SetPlacement(TAutoVal& val)
{
  AUTONAMES0("Placement")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal ListBox::GetPrintObject()
{
  AUTONAMES0("PrintObject")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void ListBox::SetPrintObject(TAutoVal& val)
{
  AUTONAMES0("PrintObject")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal ListBox::GetSelected()
{
  AUTONAMES0("Selected")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void ListBox::SetSelected(TAutoVal& val)
{
  AUTONAMES0("Selected")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal ListBox::GetTop()
{
  AUTONAMES0("Top")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void ListBox::SetTop(TAutoVal& val)
{
  AUTONAMES0("Top")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal ListBox::GetTopLeftCell()
{
  AUTONAMES0("TopLeftCell")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void ListBox::SetTopLeftCell(TAutoVal& val)
{
  AUTONAMES0("TopLeftCell")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal ListBox::GetValue()
{
  AUTONAMES0("Value")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void ListBox::SetValue(TAutoVal& val)
{
  AUTONAMES0("Value")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal ListBox::GetVisible()
{
  AUTONAMES0("Visible")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void ListBox::SetVisible(TAutoVal& val)
{
  AUTONAMES0("Visible")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal ListBox::GetWidth()
{
  AUTONAMES0("Width")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void ListBox::SetWidth(TAutoVal& val)
{
  AUTONAMES0("Width")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal ListBox::GetZOrder()
{
  AUTONAMES0("ZOrder")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void ListBox::SetZOrder(TAutoVal& val)
{
  AUTONAMES0("ZOrder")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal ListBox::AddItem(TAutoVal& Text, TAutoVal& Index)
{
  AUTONAMES0("AddItem")
  AUTOARGS2(Text, Index)
  AUTOCALL_METHOD_RET
}

TAutoVal ListBox::Application()
{
  AUTONAMES0("Application")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal ListBox::BringToFront()
{
  AUTONAMES0("BringToFront")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal ListBox::Copy()
{
  AUTONAMES0("Copy")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal ListBox::CopyPicture(TAutoVal& Appearance, TAutoVal& Format)
{
  AUTONAMES0("CopyPicture")
  AUTOARGS2(Appearance, Format)
  AUTOCALL_METHOD_RET
}

TAutoVal ListBox::Cut()
{
  AUTONAMES0("Cut")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal ListBox::Delete()
{
  AUTONAMES0("Delete")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal ListBox::Duplicate()
{
  AUTONAMES0("Duplicate")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal ListBox::RemoveAllItems()
{
  AUTONAMES0("RemoveAllItems")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal ListBox::RemoveItem(TAutoVal& Index, TAutoVal& Count)
{
  AUTONAMES0("RemoveItem")
  AUTOARGS2(Index, Count)
  AUTOCALL_METHOD_RET
}

TAutoVal ListBox::Select(TAutoVal& Replace)
{
  AUTONAMES0("Select")
  AUTOARGS1(Replace)
  AUTOCALL_METHOD_RET
}

TAutoVal ListBox::SendToBack()
{
  AUTONAMES0("SendToBack")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}


// TKIND_DISPATCH: ListBoxes {00020888-0000-0000-C000-000000000046}\9

TAutoVal ListBoxes::GetCount()
{
  AUTONAMES0("Count")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void ListBoxes::SetCount(TAutoVal& val)
{
  AUTONAMES0("Count")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal ListBoxes::GetCreator()
{
  AUTONAMES0("Creator")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void ListBoxes::SetCreator(TAutoVal& val)
{
  AUTONAMES0("Creator")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal ListBoxes::GetDisplay3DShading()
{
  AUTONAMES0("Display3DShading")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void ListBoxes::SetDisplay3DShading(TAutoVal& val)
{
  AUTONAMES0("Display3DShading")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal ListBoxes::GetEnabled()
{
  AUTONAMES0("Enabled")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void ListBoxes::SetEnabled(TAutoVal& val)
{
  AUTONAMES0("Enabled")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal ListBoxes::GetHeight()
{
  AUTONAMES0("Height")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void ListBoxes::SetHeight(TAutoVal& val)
{
  AUTONAMES0("Height")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal ListBoxes::GetLeft()
{
  AUTONAMES0("Left")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void ListBoxes::SetLeft(TAutoVal& val)
{
  AUTONAMES0("Left")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal ListBoxes::GetLinkedCell()
{
  AUTONAMES0("LinkedCell")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void ListBoxes::SetLinkedCell(TAutoVal& val)
{
  AUTONAMES0("LinkedCell")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal ListBoxes::GetList()
{
  AUTONAMES0("List")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void ListBoxes::SetList(TAutoVal& val)
{
  AUTONAMES0("List")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal ListBoxes::GetListFillRange()
{
  AUTONAMES0("ListFillRange")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void ListBoxes::SetListFillRange(TAutoVal& val)
{
  AUTONAMES0("ListFillRange")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal ListBoxes::GetListIndex()
{
  AUTONAMES0("ListIndex")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void ListBoxes::SetListIndex(TAutoVal& val)
{
  AUTONAMES0("ListIndex")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal ListBoxes::GetLocked()
{
  AUTONAMES0("Locked")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void ListBoxes::SetLocked(TAutoVal& val)
{
  AUTONAMES0("Locked")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal ListBoxes::GetMultiSelect()
{
  AUTONAMES0("MultiSelect")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void ListBoxes::SetMultiSelect(TAutoVal& val)
{
  AUTONAMES0("MultiSelect")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal ListBoxes::GetOnAction()
{
  AUTONAMES0("OnAction")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void ListBoxes::SetOnAction(TAutoVal& val)
{
  AUTONAMES0("OnAction")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal ListBoxes::GetParent()
{
  AUTONAMES0("Parent")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void ListBoxes::SetParent(TAutoVal& val)
{
  AUTONAMES0("Parent")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal ListBoxes::GetPlacement()
{
  AUTONAMES0("Placement")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void ListBoxes::SetPlacement(TAutoVal& val)
{
  AUTONAMES0("Placement")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal ListBoxes::GetPrintObject()
{
  AUTONAMES0("PrintObject")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void ListBoxes::SetPrintObject(TAutoVal& val)
{
  AUTONAMES0("PrintObject")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal ListBoxes::GetSelected()
{
  AUTONAMES0("Selected")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void ListBoxes::SetSelected(TAutoVal& val)
{
  AUTONAMES0("Selected")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal ListBoxes::GetTop()
{
  AUTONAMES0("Top")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void ListBoxes::SetTop(TAutoVal& val)
{
  AUTONAMES0("Top")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal ListBoxes::GetValue()
{
  AUTONAMES0("Value")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void ListBoxes::SetValue(TAutoVal& val)
{
  AUTONAMES0("Value")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal ListBoxes::GetVisible()
{
  AUTONAMES0("Visible")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void ListBoxes::SetVisible(TAutoVal& val)
{
  AUTONAMES0("Visible")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal ListBoxes::GetWidth()
{
  AUTONAMES0("Width")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void ListBoxes::SetWidth(TAutoVal& val)
{
  AUTONAMES0("Width")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal ListBoxes::GetZOrder()
{
  AUTONAMES0("ZOrder")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void ListBoxes::SetZOrder(TAutoVal& val)
{
  AUTONAMES0("ZOrder")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal ListBoxes::_NewEnum()
{
  AUTONAMES0("_NewEnum")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal ListBoxes::Add(TAutoVal& Left, TAutoVal& Top, TAutoVal& Width, TAutoVal& Height)
{
  AUTONAMES0("Add")
  AUTOARGS4(Left, Top, Width, Height)
  AUTOCALL_METHOD_RET
}

TAutoVal ListBoxes::AddItem(TAutoVal& Text, TAutoVal& Index)
{
  AUTONAMES0("AddItem")
  AUTOARGS2(Text, Index)
  AUTOCALL_METHOD_RET
}

TAutoVal ListBoxes::Application()
{
  AUTONAMES0("Application")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal ListBoxes::BringToFront()
{
  AUTONAMES0("BringToFront")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal ListBoxes::Copy()
{
  AUTONAMES0("Copy")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal ListBoxes::CopyPicture(TAutoVal& Appearance, TAutoVal& Format)
{
  AUTONAMES0("CopyPicture")
  AUTOARGS2(Appearance, Format)
  AUTOCALL_METHOD_RET
}

TAutoVal ListBoxes::Cut()
{
  AUTONAMES0("Cut")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal ListBoxes::Delete()
{
  AUTONAMES0("Delete")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal ListBoxes::Duplicate()
{
  AUTONAMES0("Duplicate")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal ListBoxes::Group()
{
  AUTONAMES0("Group")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal ListBoxes::Item(TAutoVal& Index)
{
  AUTONAMES0("Item")
  AUTOARGS1(Index)
  AUTOCALL_METHOD_RET
}

TAutoVal ListBoxes::RemoveAllItems()
{
  AUTONAMES0("RemoveAllItems")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal ListBoxes::RemoveItem(TAutoVal& Index, TAutoVal& Count)
{
  AUTONAMES0("RemoveItem")
  AUTOARGS2(Index, Count)
  AUTOCALL_METHOD_RET
}

TAutoVal ListBoxes::Select(TAutoVal& Replace)
{
  AUTONAMES0("Select")
  AUTOARGS1(Replace)
  AUTOCALL_METHOD_RET
}

TAutoVal ListBoxes::SendToBack()
{
  AUTONAMES0("SendToBack")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}


// TKIND_DISPATCH: GroupBox {00020889-0000-0000-C000-000000000046}\9

TAutoVal GroupBox::GetAccelerator()
{
  AUTONAMES0("Accelerator")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void GroupBox::SetAccelerator(TAutoVal& val)
{
  AUTONAMES0("Accelerator")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal GroupBox::GetBottomRightCell()
{
  AUTONAMES0("BottomRightCell")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void GroupBox::SetBottomRightCell(TAutoVal& val)
{
  AUTONAMES0("BottomRightCell")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal GroupBox::GetCaption()
{
  AUTONAMES0("Caption")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void GroupBox::SetCaption(TAutoVal& val)
{
  AUTONAMES0("Caption")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal GroupBox::GetCreator()
{
  AUTONAMES0("Creator")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void GroupBox::SetCreator(TAutoVal& val)
{
  AUTONAMES0("Creator")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal GroupBox::GetDisplay3DShading()
{
  AUTONAMES0("Display3DShading")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void GroupBox::SetDisplay3DShading(TAutoVal& val)
{
  AUTONAMES0("Display3DShading")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal GroupBox::GetEnabled()
{
  AUTONAMES0("Enabled")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void GroupBox::SetEnabled(TAutoVal& val)
{
  AUTONAMES0("Enabled")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal GroupBox::GetHeight()
{
  AUTONAMES0("Height")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void GroupBox::SetHeight(TAutoVal& val)
{
  AUTONAMES0("Height")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal GroupBox::GetIndex()
{
  AUTONAMES0("Index")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void GroupBox::SetIndex(TAutoVal& val)
{
  AUTONAMES0("Index")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal GroupBox::GetLeft()
{
  AUTONAMES0("Left")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void GroupBox::SetLeft(TAutoVal& val)
{
  AUTONAMES0("Left")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal GroupBox::GetLocked()
{
  AUTONAMES0("Locked")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void GroupBox::SetLocked(TAutoVal& val)
{
  AUTONAMES0("Locked")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal GroupBox::GetLockedText()
{
  AUTONAMES0("LockedText")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void GroupBox::SetLockedText(TAutoVal& val)
{
  AUTONAMES0("LockedText")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal GroupBox::GetName()
{
  AUTONAMES0("Name")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void GroupBox::SetName(TAutoVal& val)
{
  AUTONAMES0("Name")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal GroupBox::GetOnAction()
{
  AUTONAMES0("OnAction")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void GroupBox::SetOnAction(TAutoVal& val)
{
  AUTONAMES0("OnAction")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal GroupBox::GetParent()
{
  AUTONAMES0("Parent")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void GroupBox::SetParent(TAutoVal& val)
{
  AUTONAMES0("Parent")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal GroupBox::GetPhoneticAccelerator()
{
  AUTONAMES0("PhoneticAccelerator")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void GroupBox::SetPhoneticAccelerator(TAutoVal& val)
{
  AUTONAMES0("PhoneticAccelerator")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal GroupBox::GetPlacement()
{
  AUTONAMES0("Placement")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void GroupBox::SetPlacement(TAutoVal& val)
{
  AUTONAMES0("Placement")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal GroupBox::GetPrintObject()
{
  AUTONAMES0("PrintObject")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void GroupBox::SetPrintObject(TAutoVal& val)
{
  AUTONAMES0("PrintObject")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal GroupBox::GetText()
{
  AUTONAMES0("Text")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void GroupBox::SetText(TAutoVal& val)
{
  AUTONAMES0("Text")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal GroupBox::GetTop()
{
  AUTONAMES0("Top")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void GroupBox::SetTop(TAutoVal& val)
{
  AUTONAMES0("Top")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal GroupBox::GetTopLeftCell()
{
  AUTONAMES0("TopLeftCell")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void GroupBox::SetTopLeftCell(TAutoVal& val)
{
  AUTONAMES0("TopLeftCell")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal GroupBox::GetVisible()
{
  AUTONAMES0("Visible")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void GroupBox::SetVisible(TAutoVal& val)
{
  AUTONAMES0("Visible")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal GroupBox::GetWidth()
{
  AUTONAMES0("Width")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void GroupBox::SetWidth(TAutoVal& val)
{
  AUTONAMES0("Width")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal GroupBox::GetZOrder()
{
  AUTONAMES0("ZOrder")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void GroupBox::SetZOrder(TAutoVal& val)
{
  AUTONAMES0("ZOrder")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal GroupBox::Application()
{
  AUTONAMES0("Application")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal GroupBox::BringToFront()
{
  AUTONAMES0("BringToFront")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal GroupBox::Characters(TAutoVal& Start, TAutoVal& Length)
{
  AUTONAMES0("Characters")
  AUTOARGS2(Start, Length)
  AUTOCALL_METHOD_RET
}

TAutoVal GroupBox::CheckSpelling(TAutoVal& CustomDictionary, TAutoVal& IgnoreUppercase, TAutoVal& AlwaysSuggest)
{
  AUTONAMES0("CheckSpelling")
  AUTOARGS3(CustomDictionary, IgnoreUppercase, AlwaysSuggest)
  AUTOCALL_METHOD_RET
}

TAutoVal GroupBox::Copy()
{
  AUTONAMES0("Copy")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal GroupBox::CopyPicture(TAutoVal& Appearance, TAutoVal& Format)
{
  AUTONAMES0("CopyPicture")
  AUTOARGS2(Appearance, Format)
  AUTOCALL_METHOD_RET
}

TAutoVal GroupBox::Cut()
{
  AUTONAMES0("Cut")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal GroupBox::Delete()
{
  AUTONAMES0("Delete")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal GroupBox::Duplicate()
{
  AUTONAMES0("Duplicate")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal GroupBox::Select(TAutoVal& Replace)
{
  AUTONAMES0("Select")
  AUTOARGS1(Replace)
  AUTOCALL_METHOD_RET
}

TAutoVal GroupBox::SendToBack()
{
  AUTONAMES0("SendToBack")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}


// TKIND_DISPATCH: GroupBoxes {0002088A-0000-0000-C000-000000000046}\9

TAutoVal GroupBoxes::GetAccelerator()
{
  AUTONAMES0("Accelerator")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void GroupBoxes::SetAccelerator(TAutoVal& val)
{
  AUTONAMES0("Accelerator")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal GroupBoxes::GetCaption()
{
  AUTONAMES0("Caption")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void GroupBoxes::SetCaption(TAutoVal& val)
{
  AUTONAMES0("Caption")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal GroupBoxes::GetCount()
{
  AUTONAMES0("Count")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void GroupBoxes::SetCount(TAutoVal& val)
{
  AUTONAMES0("Count")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal GroupBoxes::GetCreator()
{
  AUTONAMES0("Creator")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void GroupBoxes::SetCreator(TAutoVal& val)
{
  AUTONAMES0("Creator")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal GroupBoxes::GetDisplay3DShading()
{
  AUTONAMES0("Display3DShading")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void GroupBoxes::SetDisplay3DShading(TAutoVal& val)
{
  AUTONAMES0("Display3DShading")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal GroupBoxes::GetEnabled()
{
  AUTONAMES0("Enabled")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void GroupBoxes::SetEnabled(TAutoVal& val)
{
  AUTONAMES0("Enabled")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal GroupBoxes::GetHeight()
{
  AUTONAMES0("Height")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void GroupBoxes::SetHeight(TAutoVal& val)
{
  AUTONAMES0("Height")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal GroupBoxes::GetLeft()
{
  AUTONAMES0("Left")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void GroupBoxes::SetLeft(TAutoVal& val)
{
  AUTONAMES0("Left")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal GroupBoxes::GetLocked()
{
  AUTONAMES0("Locked")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void GroupBoxes::SetLocked(TAutoVal& val)
{
  AUTONAMES0("Locked")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal GroupBoxes::GetLockedText()
{
  AUTONAMES0("LockedText")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void GroupBoxes::SetLockedText(TAutoVal& val)
{
  AUTONAMES0("LockedText")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal GroupBoxes::GetOnAction()
{
  AUTONAMES0("OnAction")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void GroupBoxes::SetOnAction(TAutoVal& val)
{
  AUTONAMES0("OnAction")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal GroupBoxes::GetParent()
{
  AUTONAMES0("Parent")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void GroupBoxes::SetParent(TAutoVal& val)
{
  AUTONAMES0("Parent")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal GroupBoxes::GetPhoneticAccelerator()
{
  AUTONAMES0("PhoneticAccelerator")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void GroupBoxes::SetPhoneticAccelerator(TAutoVal& val)
{
  AUTONAMES0("PhoneticAccelerator")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal GroupBoxes::GetPlacement()
{
  AUTONAMES0("Placement")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void GroupBoxes::SetPlacement(TAutoVal& val)
{
  AUTONAMES0("Placement")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal GroupBoxes::GetPrintObject()
{
  AUTONAMES0("PrintObject")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void GroupBoxes::SetPrintObject(TAutoVal& val)
{
  AUTONAMES0("PrintObject")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal GroupBoxes::GetText()
{
  AUTONAMES0("Text")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void GroupBoxes::SetText(TAutoVal& val)
{
  AUTONAMES0("Text")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal GroupBoxes::GetTop()
{
  AUTONAMES0("Top")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void GroupBoxes::SetTop(TAutoVal& val)
{
  AUTONAMES0("Top")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal GroupBoxes::GetVisible()
{
  AUTONAMES0("Visible")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void GroupBoxes::SetVisible(TAutoVal& val)
{
  AUTONAMES0("Visible")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal GroupBoxes::GetWidth()
{
  AUTONAMES0("Width")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void GroupBoxes::SetWidth(TAutoVal& val)
{
  AUTONAMES0("Width")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal GroupBoxes::GetZOrder()
{
  AUTONAMES0("ZOrder")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void GroupBoxes::SetZOrder(TAutoVal& val)
{
  AUTONAMES0("ZOrder")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal GroupBoxes::_NewEnum()
{
  AUTONAMES0("_NewEnum")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal GroupBoxes::Add(TAutoVal& Left, TAutoVal& Top, TAutoVal& Width, TAutoVal& Height)
{
  AUTONAMES0("Add")
  AUTOARGS4(Left, Top, Width, Height)
  AUTOCALL_METHOD_RET
}

TAutoVal GroupBoxes::Application()
{
  AUTONAMES0("Application")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal GroupBoxes::BringToFront()
{
  AUTONAMES0("BringToFront")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal GroupBoxes::Characters(TAutoVal& Start, TAutoVal& Length)
{
  AUTONAMES0("Characters")
  AUTOARGS2(Start, Length)
  AUTOCALL_METHOD_RET
}

TAutoVal GroupBoxes::CheckSpelling(TAutoVal& CustomDictionary, TAutoVal& IgnoreUppercase, TAutoVal& AlwaysSuggest)
{
  AUTONAMES0("CheckSpelling")
  AUTOARGS3(CustomDictionary, IgnoreUppercase, AlwaysSuggest)
  AUTOCALL_METHOD_RET
}

TAutoVal GroupBoxes::Copy()
{
  AUTONAMES0("Copy")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal GroupBoxes::CopyPicture(TAutoVal& Appearance, TAutoVal& Format)
{
  AUTONAMES0("CopyPicture")
  AUTOARGS2(Appearance, Format)
  AUTOCALL_METHOD_RET
}

TAutoVal GroupBoxes::Cut()
{
  AUTONAMES0("Cut")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal GroupBoxes::Delete()
{
  AUTONAMES0("Delete")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal GroupBoxes::Duplicate()
{
  AUTONAMES0("Duplicate")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal GroupBoxes::Group()
{
  AUTONAMES0("Group")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal GroupBoxes::Item(TAutoVal& Index)
{
  AUTONAMES0("Item")
  AUTOARGS1(Index)
  AUTOCALL_METHOD_RET
}

TAutoVal GroupBoxes::Select(TAutoVal& Replace)
{
  AUTONAMES0("Select")
  AUTOARGS1(Replace)
  AUTOCALL_METHOD_RET
}

TAutoVal GroupBoxes::SendToBack()
{
  AUTONAMES0("SendToBack")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}


// TKIND_DISPATCH: DropDown {0002088B-0000-0000-C000-000000000046}\9

TAutoVal DropDown::GetBottomRightCell()
{
  AUTONAMES0("BottomRightCell")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void DropDown::SetBottomRightCell(TAutoVal& val)
{
  AUTONAMES0("BottomRightCell")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal DropDown::GetCaption()
{
  AUTONAMES0("Caption")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void DropDown::SetCaption(TAutoVal& val)
{
  AUTONAMES0("Caption")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal DropDown::GetCreator()
{
  AUTONAMES0("Creator")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void DropDown::SetCreator(TAutoVal& val)
{
  AUTONAMES0("Creator")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal DropDown::GetDisplay3DShading()
{
  AUTONAMES0("Display3DShading")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void DropDown::SetDisplay3DShading(TAutoVal& val)
{
  AUTONAMES0("Display3DShading")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal DropDown::GetDropDownLines()
{
  AUTONAMES0("DropDownLines")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void DropDown::SetDropDownLines(TAutoVal& val)
{
  AUTONAMES0("DropDownLines")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal DropDown::GetEnabled()
{
  AUTONAMES0("Enabled")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void DropDown::SetEnabled(TAutoVal& val)
{
  AUTONAMES0("Enabled")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal DropDown::GetHeight()
{
  AUTONAMES0("Height")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void DropDown::SetHeight(TAutoVal& val)
{
  AUTONAMES0("Height")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal DropDown::GetIndex()
{
  AUTONAMES0("Index")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void DropDown::SetIndex(TAutoVal& val)
{
  AUTONAMES0("Index")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal DropDown::GetLeft()
{
  AUTONAMES0("Left")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void DropDown::SetLeft(TAutoVal& val)
{
  AUTONAMES0("Left")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal DropDown::GetLinkedCell()
{
  AUTONAMES0("LinkedCell")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void DropDown::SetLinkedCell(TAutoVal& val)
{
  AUTONAMES0("LinkedCell")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal DropDown::GetLinkedObject()
{
  AUTONAMES0("LinkedObject")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void DropDown::SetLinkedObject(TAutoVal& val)
{
  AUTONAMES0("LinkedObject")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal DropDown::GetList()
{
  AUTONAMES0("List")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void DropDown::SetList(TAutoVal& val)
{
  AUTONAMES0("List")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal DropDown::GetListCount()
{
  AUTONAMES0("ListCount")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void DropDown::SetListCount(TAutoVal& val)
{
  AUTONAMES0("ListCount")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal DropDown::GetListFillRange()
{
  AUTONAMES0("ListFillRange")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void DropDown::SetListFillRange(TAutoVal& val)
{
  AUTONAMES0("ListFillRange")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal DropDown::GetListIndex()
{
  AUTONAMES0("ListIndex")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void DropDown::SetListIndex(TAutoVal& val)
{
  AUTONAMES0("ListIndex")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal DropDown::GetLocked()
{
  AUTONAMES0("Locked")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void DropDown::SetLocked(TAutoVal& val)
{
  AUTONAMES0("Locked")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal DropDown::GetName()
{
  AUTONAMES0("Name")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void DropDown::SetName(TAutoVal& val)
{
  AUTONAMES0("Name")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal DropDown::GetOnAction()
{
  AUTONAMES0("OnAction")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void DropDown::SetOnAction(TAutoVal& val)
{
  AUTONAMES0("OnAction")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal DropDown::GetParent()
{
  AUTONAMES0("Parent")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void DropDown::SetParent(TAutoVal& val)
{
  AUTONAMES0("Parent")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal DropDown::GetPlacement()
{
  AUTONAMES0("Placement")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void DropDown::SetPlacement(TAutoVal& val)
{
  AUTONAMES0("Placement")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal DropDown::GetPrintObject()
{
  AUTONAMES0("PrintObject")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void DropDown::SetPrintObject(TAutoVal& val)
{
  AUTONAMES0("PrintObject")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal DropDown::GetSelected()
{
  AUTONAMES0("Selected")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void DropDown::SetSelected(TAutoVal& val)
{
  AUTONAMES0("Selected")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal DropDown::GetText()
{
  AUTONAMES0("Text")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void DropDown::SetText(TAutoVal& val)
{
  AUTONAMES0("Text")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal DropDown::GetTop()
{
  AUTONAMES0("Top")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void DropDown::SetTop(TAutoVal& val)
{
  AUTONAMES0("Top")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal DropDown::GetTopLeftCell()
{
  AUTONAMES0("TopLeftCell")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void DropDown::SetTopLeftCell(TAutoVal& val)
{
  AUTONAMES0("TopLeftCell")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal DropDown::GetValue()
{
  AUTONAMES0("Value")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void DropDown::SetValue(TAutoVal& val)
{
  AUTONAMES0("Value")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal DropDown::GetVisible()
{
  AUTONAMES0("Visible")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void DropDown::SetVisible(TAutoVal& val)
{
  AUTONAMES0("Visible")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal DropDown::GetWidth()
{
  AUTONAMES0("Width")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void DropDown::SetWidth(TAutoVal& val)
{
  AUTONAMES0("Width")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal DropDown::GetZOrder()
{
  AUTONAMES0("ZOrder")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void DropDown::SetZOrder(TAutoVal& val)
{
  AUTONAMES0("ZOrder")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal DropDown::AddItem(TAutoVal& Text, TAutoVal& Index)
{
  AUTONAMES0("AddItem")
  AUTOARGS2(Text, Index)
  AUTOCALL_METHOD_RET
}

TAutoVal DropDown::Application()
{
  AUTONAMES0("Application")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal DropDown::BringToFront()
{
  AUTONAMES0("BringToFront")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal DropDown::Characters(TAutoVal& Start, TAutoVal& Length)
{
  AUTONAMES0("Characters")
  AUTOARGS2(Start, Length)
  AUTOCALL_METHOD_RET
}

TAutoVal DropDown::Copy()
{
  AUTONAMES0("Copy")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal DropDown::CopyPicture(TAutoVal& Appearance, TAutoVal& Format)
{
  AUTONAMES0("CopyPicture")
  AUTOARGS2(Appearance, Format)
  AUTOCALL_METHOD_RET
}

TAutoVal DropDown::Cut()
{
  AUTONAMES0("Cut")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal DropDown::Delete()
{
  AUTONAMES0("Delete")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal DropDown::Duplicate()
{
  AUTONAMES0("Duplicate")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal DropDown::RemoveAllItems()
{
  AUTONAMES0("RemoveAllItems")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal DropDown::RemoveItem(TAutoVal& Index, TAutoVal& Count)
{
  AUTONAMES0("RemoveItem")
  AUTOARGS2(Index, Count)
  AUTOCALL_METHOD_RET
}

TAutoVal DropDown::Select(TAutoVal& Replace)
{
  AUTONAMES0("Select")
  AUTOARGS1(Replace)
  AUTOCALL_METHOD_RET
}

TAutoVal DropDown::SendToBack()
{
  AUTONAMES0("SendToBack")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}


// TKIND_DISPATCH: DropDowns {0002088C-0000-0000-C000-000000000046}\9

TAutoVal DropDowns::GetCaption()
{
  AUTONAMES0("Caption")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void DropDowns::SetCaption(TAutoVal& val)
{
  AUTONAMES0("Caption")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal DropDowns::GetCount()
{
  AUTONAMES0("Count")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void DropDowns::SetCount(TAutoVal& val)
{
  AUTONAMES0("Count")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal DropDowns::GetCreator()
{
  AUTONAMES0("Creator")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void DropDowns::SetCreator(TAutoVal& val)
{
  AUTONAMES0("Creator")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal DropDowns::GetDisplay3DShading()
{
  AUTONAMES0("Display3DShading")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void DropDowns::SetDisplay3DShading(TAutoVal& val)
{
  AUTONAMES0("Display3DShading")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal DropDowns::GetDropDownLines()
{
  AUTONAMES0("DropDownLines")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void DropDowns::SetDropDownLines(TAutoVal& val)
{
  AUTONAMES0("DropDownLines")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal DropDowns::GetEnabled()
{
  AUTONAMES0("Enabled")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void DropDowns::SetEnabled(TAutoVal& val)
{
  AUTONAMES0("Enabled")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal DropDowns::GetHeight()
{
  AUTONAMES0("Height")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void DropDowns::SetHeight(TAutoVal& val)
{
  AUTONAMES0("Height")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal DropDowns::GetLeft()
{
  AUTONAMES0("Left")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void DropDowns::SetLeft(TAutoVal& val)
{
  AUTONAMES0("Left")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal DropDowns::GetLinkedCell()
{
  AUTONAMES0("LinkedCell")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void DropDowns::SetLinkedCell(TAutoVal& val)
{
  AUTONAMES0("LinkedCell")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal DropDowns::GetList()
{
  AUTONAMES0("List")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void DropDowns::SetList(TAutoVal& val)
{
  AUTONAMES0("List")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal DropDowns::GetListFillRange()
{
  AUTONAMES0("ListFillRange")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void DropDowns::SetListFillRange(TAutoVal& val)
{
  AUTONAMES0("ListFillRange")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal DropDowns::GetListIndex()
{
  AUTONAMES0("ListIndex")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void DropDowns::SetListIndex(TAutoVal& val)
{
  AUTONAMES0("ListIndex")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal DropDowns::GetLocked()
{
  AUTONAMES0("Locked")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void DropDowns::SetLocked(TAutoVal& val)
{
  AUTONAMES0("Locked")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal DropDowns::GetOnAction()
{
  AUTONAMES0("OnAction")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void DropDowns::SetOnAction(TAutoVal& val)
{
  AUTONAMES0("OnAction")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal DropDowns::GetParent()
{
  AUTONAMES0("Parent")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void DropDowns::SetParent(TAutoVal& val)
{
  AUTONAMES0("Parent")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal DropDowns::GetPlacement()
{
  AUTONAMES0("Placement")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void DropDowns::SetPlacement(TAutoVal& val)
{
  AUTONAMES0("Placement")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal DropDowns::GetPrintObject()
{
  AUTONAMES0("PrintObject")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void DropDowns::SetPrintObject(TAutoVal& val)
{
  AUTONAMES0("PrintObject")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal DropDowns::GetSelected()
{
  AUTONAMES0("Selected")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void DropDowns::SetSelected(TAutoVal& val)
{
  AUTONAMES0("Selected")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal DropDowns::GetText()
{
  AUTONAMES0("Text")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void DropDowns::SetText(TAutoVal& val)
{
  AUTONAMES0("Text")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal DropDowns::GetTop()
{
  AUTONAMES0("Top")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void DropDowns::SetTop(TAutoVal& val)
{
  AUTONAMES0("Top")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal DropDowns::GetValue()
{
  AUTONAMES0("Value")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void DropDowns::SetValue(TAutoVal& val)
{
  AUTONAMES0("Value")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal DropDowns::GetVisible()
{
  AUTONAMES0("Visible")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void DropDowns::SetVisible(TAutoVal& val)
{
  AUTONAMES0("Visible")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal DropDowns::GetWidth()
{
  AUTONAMES0("Width")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void DropDowns::SetWidth(TAutoVal& val)
{
  AUTONAMES0("Width")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal DropDowns::GetZOrder()
{
  AUTONAMES0("ZOrder")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void DropDowns::SetZOrder(TAutoVal& val)
{
  AUTONAMES0("ZOrder")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal DropDowns::_NewEnum()
{
  AUTONAMES0("_NewEnum")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal DropDowns::Add(TAutoVal& Left, TAutoVal& Top, TAutoVal& Width, TAutoVal& Height, TAutoVal& Editable)
{
  AUTONAMES0("Add")
  AUTOARGS5(Left, Top, Width, Height, Editable)
  AUTOCALL_METHOD_RET
}

TAutoVal DropDowns::AddItem(TAutoVal& Text, TAutoVal& Index)
{
  AUTONAMES0("AddItem")
  AUTOARGS2(Text, Index)
  AUTOCALL_METHOD_RET
}

TAutoVal DropDowns::Application()
{
  AUTONAMES0("Application")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal DropDowns::BringToFront()
{
  AUTONAMES0("BringToFront")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal DropDowns::Characters(TAutoVal& Start, TAutoVal& Length)
{
  AUTONAMES0("Characters")
  AUTOARGS2(Start, Length)
  AUTOCALL_METHOD_RET
}

TAutoVal DropDowns::Copy()
{
  AUTONAMES0("Copy")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal DropDowns::CopyPicture(TAutoVal& Appearance, TAutoVal& Format)
{
  AUTONAMES0("CopyPicture")
  AUTOARGS2(Appearance, Format)
  AUTOCALL_METHOD_RET
}

TAutoVal DropDowns::Cut()
{
  AUTONAMES0("Cut")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal DropDowns::Delete()
{
  AUTONAMES0("Delete")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal DropDowns::Duplicate()
{
  AUTONAMES0("Duplicate")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal DropDowns::Group()
{
  AUTONAMES0("Group")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal DropDowns::Item(TAutoVal& Index)
{
  AUTONAMES0("Item")
  AUTOARGS1(Index)
  AUTOCALL_METHOD_RET
}

TAutoVal DropDowns::RemoveAllItems()
{
  AUTONAMES0("RemoveAllItems")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal DropDowns::RemoveItem(TAutoVal& Index, TAutoVal& Count)
{
  AUTONAMES0("RemoveItem")
  AUTOARGS2(Index, Count)
  AUTOCALL_METHOD_RET
}

TAutoVal DropDowns::Select(TAutoVal& Replace)
{
  AUTONAMES0("Select")
  AUTOARGS1(Replace)
  AUTOCALL_METHOD_RET
}

TAutoVal DropDowns::SendToBack()
{
  AUTONAMES0("SendToBack")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}


// TKIND_DISPATCH: DialogFrame {0002088F-0000-0000-C000-000000000046}\9

TAutoVal DialogFrame::GetCaption()
{
  AUTONAMES0("Caption")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void DialogFrame::SetCaption(TAutoVal& val)
{
  AUTONAMES0("Caption")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal DialogFrame::GetCreator()
{
  AUTONAMES0("Creator")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void DialogFrame::SetCreator(TAutoVal& val)
{
  AUTONAMES0("Creator")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal DialogFrame::GetHeight()
{
  AUTONAMES0("Height")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void DialogFrame::SetHeight(TAutoVal& val)
{
  AUTONAMES0("Height")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal DialogFrame::GetLeft()
{
  AUTONAMES0("Left")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void DialogFrame::SetLeft(TAutoVal& val)
{
  AUTONAMES0("Left")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal DialogFrame::GetLocked()
{
  AUTONAMES0("Locked")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void DialogFrame::SetLocked(TAutoVal& val)
{
  AUTONAMES0("Locked")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal DialogFrame::GetLockedText()
{
  AUTONAMES0("LockedText")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void DialogFrame::SetLockedText(TAutoVal& val)
{
  AUTONAMES0("LockedText")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal DialogFrame::GetName()
{
  AUTONAMES0("Name")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void DialogFrame::SetName(TAutoVal& val)
{
  AUTONAMES0("Name")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal DialogFrame::GetOnAction()
{
  AUTONAMES0("OnAction")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void DialogFrame::SetOnAction(TAutoVal& val)
{
  AUTONAMES0("OnAction")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal DialogFrame::GetParent()
{
  AUTONAMES0("Parent")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void DialogFrame::SetParent(TAutoVal& val)
{
  AUTONAMES0("Parent")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal DialogFrame::GetText()
{
  AUTONAMES0("Text")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void DialogFrame::SetText(TAutoVal& val)
{
  AUTONAMES0("Text")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal DialogFrame::GetTop()
{
  AUTONAMES0("Top")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void DialogFrame::SetTop(TAutoVal& val)
{
  AUTONAMES0("Top")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal DialogFrame::GetWidth()
{
  AUTONAMES0("Width")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void DialogFrame::SetWidth(TAutoVal& val)
{
  AUTONAMES0("Width")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal DialogFrame::Application()
{
  AUTONAMES0("Application")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal DialogFrame::Characters(TAutoVal& Start, TAutoVal& Length)
{
  AUTONAMES0("Characters")
  AUTOARGS2(Start, Length)
  AUTOCALL_METHOD_RET
}

TAutoVal DialogFrame::CheckSpelling(TAutoVal& CustomDictionary, TAutoVal& IgnoreUppercase, TAutoVal& AlwaysSuggest)
{
  AUTONAMES0("CheckSpelling")
  AUTOARGS3(CustomDictionary, IgnoreUppercase, AlwaysSuggest)
  AUTOCALL_METHOD_RET
}

TAutoVal DialogFrame::CopyPicture(TAutoVal& Appearance, TAutoVal& Format)
{
  AUTONAMES0("CopyPicture")
  AUTOARGS2(Appearance, Format)
  AUTOCALL_METHOD_RET
}

TAutoVal DialogFrame::Select(TAutoVal& Replace)
{
  AUTONAMES0("Select")
  AUTOARGS1(Replace)
  AUTOCALL_METHOD_RET
}


// TKIND_DISPATCH: Label {00020890-0000-0000-C000-000000000046}\9

TAutoVal Label::GetAccelerator()
{
  AUTONAMES0("Accelerator")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Label::SetAccelerator(TAutoVal& val)
{
  AUTONAMES0("Accelerator")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Label::GetBottomRightCell()
{
  AUTONAMES0("BottomRightCell")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Label::SetBottomRightCell(TAutoVal& val)
{
  AUTONAMES0("BottomRightCell")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Label::GetCaption()
{
  AUTONAMES0("Caption")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Label::SetCaption(TAutoVal& val)
{
  AUTONAMES0("Caption")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Label::GetCreator()
{
  AUTONAMES0("Creator")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Label::SetCreator(TAutoVal& val)
{
  AUTONAMES0("Creator")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Label::GetEnabled()
{
  AUTONAMES0("Enabled")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Label::SetEnabled(TAutoVal& val)
{
  AUTONAMES0("Enabled")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Label::GetHeight()
{
  AUTONAMES0("Height")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Label::SetHeight(TAutoVal& val)
{
  AUTONAMES0("Height")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Label::GetIndex()
{
  AUTONAMES0("Index")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Label::SetIndex(TAutoVal& val)
{
  AUTONAMES0("Index")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Label::GetLeft()
{
  AUTONAMES0("Left")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Label::SetLeft(TAutoVal& val)
{
  AUTONAMES0("Left")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Label::GetLocked()
{
  AUTONAMES0("Locked")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Label::SetLocked(TAutoVal& val)
{
  AUTONAMES0("Locked")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Label::GetLockedText()
{
  AUTONAMES0("LockedText")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Label::SetLockedText(TAutoVal& val)
{
  AUTONAMES0("LockedText")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Label::GetName()
{
  AUTONAMES0("Name")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Label::SetName(TAutoVal& val)
{
  AUTONAMES0("Name")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Label::GetOnAction()
{
  AUTONAMES0("OnAction")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Label::SetOnAction(TAutoVal& val)
{
  AUTONAMES0("OnAction")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Label::GetParent()
{
  AUTONAMES0("Parent")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Label::SetParent(TAutoVal& val)
{
  AUTONAMES0("Parent")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Label::GetPhoneticAccelerator()
{
  AUTONAMES0("PhoneticAccelerator")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Label::SetPhoneticAccelerator(TAutoVal& val)
{
  AUTONAMES0("PhoneticAccelerator")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Label::GetPlacement()
{
  AUTONAMES0("Placement")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Label::SetPlacement(TAutoVal& val)
{
  AUTONAMES0("Placement")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Label::GetPrintObject()
{
  AUTONAMES0("PrintObject")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Label::SetPrintObject(TAutoVal& val)
{
  AUTONAMES0("PrintObject")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Label::GetText()
{
  AUTONAMES0("Text")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Label::SetText(TAutoVal& val)
{
  AUTONAMES0("Text")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Label::GetTop()
{
  AUTONAMES0("Top")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Label::SetTop(TAutoVal& val)
{
  AUTONAMES0("Top")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Label::GetTopLeftCell()
{
  AUTONAMES0("TopLeftCell")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Label::SetTopLeftCell(TAutoVal& val)
{
  AUTONAMES0("TopLeftCell")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Label::GetVisible()
{
  AUTONAMES0("Visible")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Label::SetVisible(TAutoVal& val)
{
  AUTONAMES0("Visible")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Label::GetWidth()
{
  AUTONAMES0("Width")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Label::SetWidth(TAutoVal& val)
{
  AUTONAMES0("Width")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Label::GetZOrder()
{
  AUTONAMES0("ZOrder")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Label::SetZOrder(TAutoVal& val)
{
  AUTONAMES0("ZOrder")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Label::Application()
{
  AUTONAMES0("Application")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Label::BringToFront()
{
  AUTONAMES0("BringToFront")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Label::Characters(TAutoVal& Start, TAutoVal& Length)
{
  AUTONAMES0("Characters")
  AUTOARGS2(Start, Length)
  AUTOCALL_METHOD_RET
}

TAutoVal Label::CheckSpelling(TAutoVal& CustomDictionary, TAutoVal& IgnoreUppercase, TAutoVal& AlwaysSuggest)
{
  AUTONAMES0("CheckSpelling")
  AUTOARGS3(CustomDictionary, IgnoreUppercase, AlwaysSuggest)
  AUTOCALL_METHOD_RET
}

TAutoVal Label::Copy()
{
  AUTONAMES0("Copy")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Label::CopyPicture(TAutoVal& Appearance, TAutoVal& Format)
{
  AUTONAMES0("CopyPicture")
  AUTOARGS2(Appearance, Format)
  AUTOCALL_METHOD_RET
}

TAutoVal Label::Cut()
{
  AUTONAMES0("Cut")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Label::Delete()
{
  AUTONAMES0("Delete")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Label::Duplicate()
{
  AUTONAMES0("Duplicate")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Label::Select(TAutoVal& Replace)
{
  AUTONAMES0("Select")
  AUTOARGS1(Replace)
  AUTOCALL_METHOD_RET
}

TAutoVal Label::SendToBack()
{
  AUTONAMES0("SendToBack")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}


// TKIND_DISPATCH: Labels {00020891-0000-0000-C000-000000000046}\9

TAutoVal Labels::GetAccelerator()
{
  AUTONAMES0("Accelerator")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Labels::SetAccelerator(TAutoVal& val)
{
  AUTONAMES0("Accelerator")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Labels::GetCaption()
{
  AUTONAMES0("Caption")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Labels::SetCaption(TAutoVal& val)
{
  AUTONAMES0("Caption")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Labels::GetCount()
{
  AUTONAMES0("Count")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Labels::SetCount(TAutoVal& val)
{
  AUTONAMES0("Count")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Labels::GetCreator()
{
  AUTONAMES0("Creator")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Labels::SetCreator(TAutoVal& val)
{
  AUTONAMES0("Creator")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Labels::GetEnabled()
{
  AUTONAMES0("Enabled")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Labels::SetEnabled(TAutoVal& val)
{
  AUTONAMES0("Enabled")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Labels::GetHeight()
{
  AUTONAMES0("Height")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Labels::SetHeight(TAutoVal& val)
{
  AUTONAMES0("Height")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Labels::GetLeft()
{
  AUTONAMES0("Left")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Labels::SetLeft(TAutoVal& val)
{
  AUTONAMES0("Left")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Labels::GetLocked()
{
  AUTONAMES0("Locked")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Labels::SetLocked(TAutoVal& val)
{
  AUTONAMES0("Locked")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Labels::GetLockedText()
{
  AUTONAMES0("LockedText")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Labels::SetLockedText(TAutoVal& val)
{
  AUTONAMES0("LockedText")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Labels::GetOnAction()
{
  AUTONAMES0("OnAction")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Labels::SetOnAction(TAutoVal& val)
{
  AUTONAMES0("OnAction")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Labels::GetParent()
{
  AUTONAMES0("Parent")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Labels::SetParent(TAutoVal& val)
{
  AUTONAMES0("Parent")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Labels::GetPhoneticAccelerator()
{
  AUTONAMES0("PhoneticAccelerator")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Labels::SetPhoneticAccelerator(TAutoVal& val)
{
  AUTONAMES0("PhoneticAccelerator")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Labels::GetPlacement()
{
  AUTONAMES0("Placement")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Labels::SetPlacement(TAutoVal& val)
{
  AUTONAMES0("Placement")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Labels::GetPrintObject()
{
  AUTONAMES0("PrintObject")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Labels::SetPrintObject(TAutoVal& val)
{
  AUTONAMES0("PrintObject")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Labels::GetText()
{
  AUTONAMES0("Text")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Labels::SetText(TAutoVal& val)
{
  AUTONAMES0("Text")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Labels::GetTop()
{
  AUTONAMES0("Top")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Labels::SetTop(TAutoVal& val)
{
  AUTONAMES0("Top")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Labels::GetVisible()
{
  AUTONAMES0("Visible")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Labels::SetVisible(TAutoVal& val)
{
  AUTONAMES0("Visible")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Labels::GetWidth()
{
  AUTONAMES0("Width")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Labels::SetWidth(TAutoVal& val)
{
  AUTONAMES0("Width")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Labels::GetZOrder()
{
  AUTONAMES0("ZOrder")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Labels::SetZOrder(TAutoVal& val)
{
  AUTONAMES0("ZOrder")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Labels::_NewEnum()
{
  AUTONAMES0("_NewEnum")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Labels::Add(TAutoVal& Left, TAutoVal& Top, TAutoVal& Width, TAutoVal& Height)
{
  AUTONAMES0("Add")
  AUTOARGS4(Left, Top, Width, Height)
  AUTOCALL_METHOD_RET
}

TAutoVal Labels::Application()
{
  AUTONAMES0("Application")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Labels::BringToFront()
{
  AUTONAMES0("BringToFront")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Labels::Characters(TAutoVal& Start, TAutoVal& Length)
{
  AUTONAMES0("Characters")
  AUTOARGS2(Start, Length)
  AUTOCALL_METHOD_RET
}

TAutoVal Labels::CheckSpelling(TAutoVal& CustomDictionary, TAutoVal& IgnoreUppercase, TAutoVal& AlwaysSuggest)
{
  AUTONAMES0("CheckSpelling")
  AUTOARGS3(CustomDictionary, IgnoreUppercase, AlwaysSuggest)
  AUTOCALL_METHOD_RET
}

TAutoVal Labels::Copy()
{
  AUTONAMES0("Copy")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Labels::CopyPicture(TAutoVal& Appearance, TAutoVal& Format)
{
  AUTONAMES0("CopyPicture")
  AUTOARGS2(Appearance, Format)
  AUTOCALL_METHOD_RET
}

TAutoVal Labels::Cut()
{
  AUTONAMES0("Cut")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Labels::Delete()
{
  AUTONAMES0("Delete")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Labels::Duplicate()
{
  AUTONAMES0("Duplicate")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Labels::Group()
{
  AUTONAMES0("Group")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Labels::Item(TAutoVal& Index)
{
  AUTONAMES0("Item")
  AUTOARGS1(Index)
  AUTOCALL_METHOD_RET
}

TAutoVal Labels::Select(TAutoVal& Replace)
{
  AUTONAMES0("Select")
  AUTOARGS1(Replace)
  AUTOCALL_METHOD_RET
}

TAutoVal Labels::SendToBack()
{
  AUTONAMES0("SendToBack")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}


// TKIND_DISPATCH: Interior {00020870-0000-0000-C000-000000000046}\9

TAutoVal Interior::GetColor()
{
  AUTONAMES0("Color")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Interior::SetColor(TAutoVal& val)
{
  AUTONAMES0("Color")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Interior::GetColorIndex()
{
  AUTONAMES0("ColorIndex")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Interior::SetColorIndex(TAutoVal& val)
{
  AUTONAMES0("ColorIndex")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Interior::GetCreator()
{
  AUTONAMES0("Creator")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Interior::SetCreator(TAutoVal& val)
{
  AUTONAMES0("Creator")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Interior::GetParent()
{
  AUTONAMES0("Parent")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Interior::SetParent(TAutoVal& val)
{
  AUTONAMES0("Parent")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Interior::GetPattern()
{
  AUTONAMES0("Pattern")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Interior::SetPattern(TAutoVal& val)
{
  AUTONAMES0("Pattern")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Interior::GetPatternColor()
{
  AUTONAMES0("PatternColor")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Interior::SetPatternColor(TAutoVal& val)
{
  AUTONAMES0("PatternColor")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Interior::GetPatternColorIndex()
{
  AUTONAMES0("PatternColorIndex")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Interior::SetPatternColorIndex(TAutoVal& val)
{
  AUTONAMES0("PatternColorIndex")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Interior::Application()
{
  AUTONAMES0("Application")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}


// TKIND_DISPATCH: SoundNote {0002087B-0000-0000-C000-000000000046}\9

TAutoVal SoundNote::GetCreator()
{
  AUTONAMES0("Creator")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void SoundNote::SetCreator(TAutoVal& val)
{
  AUTONAMES0("Creator")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal SoundNote::GetParent()
{
  AUTONAMES0("Parent")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void SoundNote::SetParent(TAutoVal& val)
{
  AUTONAMES0("Parent")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal SoundNote::Application()
{
  AUTONAMES0("Application")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal SoundNote::Delete()
{
  AUTONAMES0("Delete")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal SoundNote::Import(TAutoVal& Filename)
{
  AUTONAMES0("Import")
  AUTOARGS1(Filename)
  AUTOCALL_METHOD_RET
}

TAutoVal SoundNote::Play()
{
  AUTONAMES0("Play")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal SoundNote::Record()
{
  AUTONAMES0("Record")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}


// TKIND_DISPATCH: Characters {00020878-0000-0000-C000-000000000046}\9

TAutoVal Characters::GetCaption()
{
  AUTONAMES0("Caption")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Characters::SetCaption(TAutoVal& val)
{
  AUTONAMES0("Caption")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Characters::GetCount()
{
  AUTONAMES0("Count")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Characters::SetCount(TAutoVal& val)
{
  AUTONAMES0("Count")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Characters::GetCreator()
{
  AUTONAMES0("Creator")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Characters::SetCreator(TAutoVal& val)
{
  AUTONAMES0("Creator")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Characters::GetFont()
{
  AUTONAMES0("Font")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Characters::SetFont(TAutoVal& val)
{
  AUTONAMES0("Font")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Characters::GetParent()
{
  AUTONAMES0("Parent")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Characters::SetParent(TAutoVal& val)
{
  AUTONAMES0("Parent")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Characters::GetText()
{
  AUTONAMES0("Text")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Characters::SetText(TAutoVal& val)
{
  AUTONAMES0("Text")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Characters::Application()
{
  AUTONAMES0("Application")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Characters::Delete()
{
  AUTONAMES0("Delete")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Characters::Insert(TAutoVal& String)
{
  AUTONAMES0("Insert")
  AUTOARGS1(String)
  AUTOCALL_METHOD_RET
}


// TKIND_DISPATCH: Dialog {0002087A-0000-0000-C000-000000000046}\9

TAutoVal Dialog::GetCreator()
{
  AUTONAMES0("Creator")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Dialog::SetCreator(TAutoVal& val)
{
  AUTONAMES0("Creator")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Dialog::GetParent()
{
  AUTONAMES0("Parent")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Dialog::SetParent(TAutoVal& val)
{
  AUTONAMES0("Parent")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Dialog::Application()
{
  AUTONAMES0("Application")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Dialog::Show(TAutoVal& Arg1, TAutoVal& Arg2, TAutoVal& Arg3, TAutoVal& Arg4, TAutoVal& Arg5, TAutoVal& Arg6, TAutoVal& Arg7, TAutoVal& Arg8, TAutoVal& Arg9, TAutoVal& Arg10, TAutoVal& Arg11, TAutoVal& Arg12, TAutoVal& Arg13, TAutoVal& Arg14, TAutoVal& Arg15, TAutoVal& Arg16, TAutoVal& Arg17, TAutoVal& Arg18, TAutoVal& Arg19, TAutoVal& Arg20, TAutoVal& Arg21, TAutoVal& Arg22, TAutoVal& Arg23, TAutoVal& Arg24, TAutoVal& Arg25, TAutoVal& Arg26, TAutoVal& Arg27, TAutoVal& Arg28, TAutoVal& Arg29, TAutoVal& Arg30)
{
  AUTONAMES0("Show")
  AUTOARGS30(Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Arg8, Arg9, Arg10, Arg11, Arg12, Arg13, Arg14, Arg15, Arg16, Arg17, Arg18, Arg19, Arg20, Arg21, Arg22, Arg23, Arg24, Arg25, Arg26, Arg27, Arg28, Arg29, Arg30)
  AUTOCALL_METHOD_RET
}


// TKIND_DISPATCH: Dialogs {00020879-0000-0000-C000-000000000046}\9

TAutoVal Dialogs::GetCount()
{
  AUTONAMES0("Count")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Dialogs::SetCount(TAutoVal& val)
{
  AUTONAMES0("Count")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Dialogs::GetCreator()
{
  AUTONAMES0("Creator")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Dialogs::SetCreator(TAutoVal& val)
{
  AUTONAMES0("Creator")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Dialogs::GetParent()
{
  AUTONAMES0("Parent")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Dialogs::SetParent(TAutoVal& val)
{
  AUTONAMES0("Parent")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Dialogs::Application()
{
  AUTONAMES0("Application")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Dialogs::Item(TAutoVal& Index)
{
  AUTONAMES0("Item")
  AUTOARGS1(Index)
  AUTOCALL_METHOD_RET
}


// TKIND_DISPATCH: Outline {000208AB-0000-0000-C000-000000000046}\9

TAutoVal Outline::GetAutomaticStyles()
{
  AUTONAMES0("AutomaticStyles")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Outline::SetAutomaticStyles(TAutoVal& val)
{
  AUTONAMES0("AutomaticStyles")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Outline::GetCreator()
{
  AUTONAMES0("Creator")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Outline::SetCreator(TAutoVal& val)
{
  AUTONAMES0("Creator")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Outline::GetParent()
{
  AUTONAMES0("Parent")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Outline::SetParent(TAutoVal& val)
{
  AUTONAMES0("Parent")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Outline::GetSummaryColumn()
{
  AUTONAMES0("SummaryColumn")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Outline::SetSummaryColumn(TAutoVal& val)
{
  AUTONAMES0("SummaryColumn")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Outline::GetSummaryRow()
{
  AUTONAMES0("SummaryRow")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Outline::SetSummaryRow(TAutoVal& val)
{
  AUTONAMES0("SummaryRow")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Outline::Application()
{
  AUTONAMES0("Application")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Outline::ShowLevels(TAutoVal& RowLevels, TAutoVal& ColumnLevels)
{
  AUTONAMES0("ShowLevels")
  AUTOARGS2(RowLevels, ColumnLevels)
  AUTOCALL_METHOD_RET
}


// TKIND_DISPATCH: RoutingSlip {000208AA-0000-0000-C000-000000000046}\9

TAutoVal RoutingSlip::GetCreator()
{
  AUTONAMES0("Creator")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void RoutingSlip::SetCreator(TAutoVal& val)
{
  AUTONAMES0("Creator")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal RoutingSlip::GetDelivery()
{
  AUTONAMES0("Delivery")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void RoutingSlip::SetDelivery(TAutoVal& val)
{
  AUTONAMES0("Delivery")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal RoutingSlip::GetMessage()
{
  AUTONAMES0("Message")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void RoutingSlip::SetMessage(TAutoVal& val)
{
  AUTONAMES0("Message")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal RoutingSlip::GetParent()
{
  AUTONAMES0("Parent")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void RoutingSlip::SetParent(TAutoVal& val)
{
  AUTONAMES0("Parent")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal RoutingSlip::GetRecipients()
{
  AUTONAMES0("Recipients")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void RoutingSlip::SetRecipients(TAutoVal& val)
{
  AUTONAMES0("Recipients")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal RoutingSlip::GetReturnWhenDone()
{
  AUTONAMES0("ReturnWhenDone")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void RoutingSlip::SetReturnWhenDone(TAutoVal& val)
{
  AUTONAMES0("ReturnWhenDone")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal RoutingSlip::GetStatus()
{
  AUTONAMES0("Status")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void RoutingSlip::SetStatus(TAutoVal& val)
{
  AUTONAMES0("Status")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal RoutingSlip::GetSubject()
{
  AUTONAMES0("Subject")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void RoutingSlip::SetSubject(TAutoVal& val)
{
  AUTONAMES0("Subject")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal RoutingSlip::GetTrackStatus()
{
  AUTONAMES0("TrackStatus")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void RoutingSlip::SetTrackStatus(TAutoVal& val)
{
  AUTONAMES0("TrackStatus")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal RoutingSlip::Application()
{
  AUTONAMES0("Application")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal RoutingSlip::Reset()
{
  AUTONAMES0("Reset")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}


// TKIND_DISPATCH: Module {000209AD-0000-0000-C000-000000000046}\9

TAutoVal Module::GetCreator()
{
  AUTONAMES0("Creator")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Module::SetCreator(TAutoVal& val)
{
  AUTONAMES0("Creator")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Module::GetIndex()
{
  AUTONAMES0("Index")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Module::SetIndex(TAutoVal& val)
{
  AUTONAMES0("Index")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Module::GetName()
{
  AUTONAMES0("Name")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Module::SetName(TAutoVal& val)
{
  AUTONAMES0("Name")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Module::GetNext()
{
  AUTONAMES0("Next")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Module::SetNext(TAutoVal& val)
{
  AUTONAMES0("Next")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Module::GetOnDoubleClick()
{
  AUTONAMES0("OnDoubleClick")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Module::SetOnDoubleClick(TAutoVal& val)
{
  AUTONAMES0("OnDoubleClick")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Module::GetOnSheetActivate()
{
  AUTONAMES0("OnSheetActivate")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Module::SetOnSheetActivate(TAutoVal& val)
{
  AUTONAMES0("OnSheetActivate")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Module::GetOnSheetDeactivate()
{
  AUTONAMES0("OnSheetDeactivate")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Module::SetOnSheetDeactivate(TAutoVal& val)
{
  AUTONAMES0("OnSheetDeactivate")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Module::GetPageSetup()
{
  AUTONAMES0("PageSetup")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Module::SetPageSetup(TAutoVal& val)
{
  AUTONAMES0("PageSetup")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Module::GetParent()
{
  AUTONAMES0("Parent")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Module::SetParent(TAutoVal& val)
{
  AUTONAMES0("Parent")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Module::GetPrevious()
{
  AUTONAMES0("Previous")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Module::SetPrevious(TAutoVal& val)
{
  AUTONAMES0("Previous")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Module::GetProtectContents()
{
  AUTONAMES0("ProtectContents")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Module::SetProtectContents(TAutoVal& val)
{
  AUTONAMES0("ProtectContents")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Module::GetProtectionMode()
{
  AUTONAMES0("ProtectionMode")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Module::SetProtectionMode(TAutoVal& val)
{
  AUTONAMES0("ProtectionMode")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Module::GetVisible()
{
  AUTONAMES0("Visible")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Module::SetVisible(TAutoVal& val)
{
  AUTONAMES0("Visible")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Module::Activate()
{
  AUTONAMES0("Activate")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Module::Application()
{
  AUTONAMES0("Application")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Module::Copy(TAutoVal& Before, TAutoVal& After)
{
  AUTONAMES0("Copy")
  AUTOARGS2(Before, After)
  AUTOCALL_METHOD_RET
}

TAutoVal Module::Delete()
{
  AUTONAMES0("Delete")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Module::InsertFile(TAutoVal& Filename, TAutoVal& Merge)
{
  AUTONAMES0("InsertFile")
  AUTOARGS2(Filename, Merge)
  AUTOCALL_METHOD_RET
}

TAutoVal Module::Move(TAutoVal& Before, TAutoVal& After)
{
  AUTONAMES0("Move")
  AUTOARGS2(Before, After)
  AUTOCALL_METHOD_RET
}

TAutoVal Module::PrintOut(TAutoVal& From, TAutoVal& To, TAutoVal& Copies, TAutoVal& Preview, TAutoVal& ActivePrinter, TAutoVal& PrintToFile, TAutoVal& Collate)
{
  AUTONAMES0("PrintOut")
  AUTOARGS7(From, To, Copies, Preview, ActivePrinter, PrintToFile, Collate)
  AUTOCALL_METHOD_RET
}

TAutoVal Module::Protect(TAutoVal& Password, TAutoVal& DrawingObjects, TAutoVal& Contents, TAutoVal& Scenarios, TAutoVal& UserInterfaceOnly)
{
  AUTONAMES0("Protect")
  AUTOARGS5(Password, DrawingObjects, Contents, Scenarios, UserInterfaceOnly)
  AUTOCALL_METHOD_RET
}

TAutoVal Module::SaveAs(TAutoVal& Filename, TAutoVal& FileFormat, TAutoVal& Password, TAutoVal& WriteResPassword, TAutoVal& ReadOnlyRecommended, TAutoVal& CreateBackup)
{
  AUTONAMES0("SaveAs")
  AUTOARGS6(Filename, FileFormat, Password, WriteResPassword, ReadOnlyRecommended, CreateBackup)
  AUTOCALL_METHOD_RET
}

TAutoVal Module::Select(TAutoVal& Replace)
{
  AUTONAMES0("Select")
  AUTOARGS1(Replace)
  AUTOCALL_METHOD_RET
}

TAutoVal Module::Unprotect(TAutoVal& Password)
{
  AUTONAMES0("Unprotect")
  AUTOARGS1(Password)
  AUTOCALL_METHOD_RET
}


// TKIND_DISPATCH: Modules {000209AE-0000-0000-C000-000000000046}\9

TAutoVal Modules::GetCount()
{
  AUTONAMES0("Count")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Modules::SetCount(TAutoVal& val)
{
  AUTONAMES0("Count")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Modules::GetCreator()
{
  AUTONAMES0("Creator")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Modules::SetCreator(TAutoVal& val)
{
  AUTONAMES0("Creator")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Modules::GetParent()
{
  AUTONAMES0("Parent")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Modules::SetParent(TAutoVal& val)
{
  AUTONAMES0("Parent")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Modules::GetVisible()
{
  AUTONAMES0("Visible")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Modules::SetVisible(TAutoVal& val)
{
  AUTONAMES0("Visible")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Modules::_NewEnum()
{
  AUTONAMES0("_NewEnum")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Modules::Add(TAutoVal& Before, TAutoVal& After, TAutoVal& Count)
{
  AUTONAMES0("Add")
  AUTOARGS3(Before, After, Count)
  AUTOCALL_METHOD_RET
}

TAutoVal Modules::Application()
{
  AUTONAMES0("Application")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Modules::Copy(TAutoVal& Before, TAutoVal& After)
{
  AUTONAMES0("Copy")
  AUTOARGS2(Before, After)
  AUTOCALL_METHOD_RET
}

TAutoVal Modules::Delete()
{
  AUTONAMES0("Delete")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Modules::Item(TAutoVal& Index)
{
  AUTONAMES0("Item")
  AUTOARGS1(Index)
  AUTOCALL_METHOD_RET
}

TAutoVal Modules::Move(TAutoVal& Before, TAutoVal& After)
{
  AUTONAMES0("Move")
  AUTOARGS2(Before, After)
  AUTOCALL_METHOD_RET
}

TAutoVal Modules::PrintOut(TAutoVal& From, TAutoVal& To, TAutoVal& Copies, TAutoVal& Preview, TAutoVal& ActivePrinter, TAutoVal& PrintToFile, TAutoVal& Collate)
{
  AUTONAMES0("PrintOut")
  AUTOARGS7(From, To, Copies, Preview, ActivePrinter, PrintToFile, Collate)
  AUTOCALL_METHOD_RET
}

TAutoVal Modules::Select(TAutoVal& Replace)
{
  AUTONAMES0("Select")
  AUTOARGS1(Replace)
  AUTOCALL_METHOD_RET
}


// TKIND_DISPATCH: DialogSheet {000209AF-0000-0000-C000-000000000046}\9

TAutoVal DialogSheet::GetCreator()
{
  AUTONAMES0("Creator")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void DialogSheet::SetCreator(TAutoVal& val)
{
  AUTONAMES0("Creator")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal DialogSheet::GetDefaultButton()
{
  AUTONAMES0("DefaultButton")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void DialogSheet::SetDefaultButton(TAutoVal& val)
{
  AUTONAMES0("DefaultButton")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal DialogSheet::GetDialogFrame()
{
  AUTONAMES0("DialogFrame")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void DialogSheet::SetDialogFrame(TAutoVal& val)
{
  AUTONAMES0("DialogFrame")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal DialogSheet::GetDisplayAutomaticPageBreaks()
{
  AUTONAMES0("DisplayAutomaticPageBreaks")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void DialogSheet::SetDisplayAutomaticPageBreaks(TAutoVal& val)
{
  AUTONAMES0("DisplayAutomaticPageBreaks")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal DialogSheet::GetEnableAutoFilter()
{
  AUTONAMES0("EnableAutoFilter")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void DialogSheet::SetEnableAutoFilter(TAutoVal& val)
{
  AUTONAMES0("EnableAutoFilter")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal DialogSheet::GetEnableOutlining()
{
  AUTONAMES0("EnableOutlining")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void DialogSheet::SetEnableOutlining(TAutoVal& val)
{
  AUTONAMES0("EnableOutlining")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal DialogSheet::GetEnablePivotTable()
{
  AUTONAMES0("EnablePivotTable")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void DialogSheet::SetEnablePivotTable(TAutoVal& val)
{
  AUTONAMES0("EnablePivotTable")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal DialogSheet::GetFocus()
{
  AUTONAMES0("Focus")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void DialogSheet::SetFocus(TAutoVal& val)
{
  AUTONAMES0("Focus")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal DialogSheet::GetIndex()
{
  AUTONAMES0("Index")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void DialogSheet::SetIndex(TAutoVal& val)
{
  AUTONAMES0("Index")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal DialogSheet::GetName()
{
  AUTONAMES0("Name")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void DialogSheet::SetName(TAutoVal& val)
{
  AUTONAMES0("Name")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal DialogSheet::GetNext()
{
  AUTONAMES0("Next")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void DialogSheet::SetNext(TAutoVal& val)
{
  AUTONAMES0("Next")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal DialogSheet::GetOnDoubleClick()
{
  AUTONAMES0("OnDoubleClick")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void DialogSheet::SetOnDoubleClick(TAutoVal& val)
{
  AUTONAMES0("OnDoubleClick")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal DialogSheet::GetOnSheetActivate()
{
  AUTONAMES0("OnSheetActivate")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void DialogSheet::SetOnSheetActivate(TAutoVal& val)
{
  AUTONAMES0("OnSheetActivate")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal DialogSheet::GetOnSheetDeactivate()
{
  AUTONAMES0("OnSheetDeactivate")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void DialogSheet::SetOnSheetDeactivate(TAutoVal& val)
{
  AUTONAMES0("OnSheetDeactivate")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal DialogSheet::GetPageSetup()
{
  AUTONAMES0("PageSetup")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void DialogSheet::SetPageSetup(TAutoVal& val)
{
  AUTONAMES0("PageSetup")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal DialogSheet::GetParent()
{
  AUTONAMES0("Parent")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void DialogSheet::SetParent(TAutoVal& val)
{
  AUTONAMES0("Parent")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal DialogSheet::GetPrevious()
{
  AUTONAMES0("Previous")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void DialogSheet::SetPrevious(TAutoVal& val)
{
  AUTONAMES0("Previous")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal DialogSheet::GetProtectContents()
{
  AUTONAMES0("ProtectContents")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void DialogSheet::SetProtectContents(TAutoVal& val)
{
  AUTONAMES0("ProtectContents")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal DialogSheet::GetProtectDrawingObjects()
{
  AUTONAMES0("ProtectDrawingObjects")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void DialogSheet::SetProtectDrawingObjects(TAutoVal& val)
{
  AUTONAMES0("ProtectDrawingObjects")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal DialogSheet::GetProtectionMode()
{
  AUTONAMES0("ProtectionMode")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void DialogSheet::SetProtectionMode(TAutoVal& val)
{
  AUTONAMES0("ProtectionMode")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal DialogSheet::GetVisible()
{
  AUTONAMES0("Visible")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void DialogSheet::SetVisible(TAutoVal& val)
{
  AUTONAMES0("Visible")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal DialogSheet::Activate()
{
  AUTONAMES0("Activate")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal DialogSheet::Application()
{
  AUTONAMES0("Application")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal DialogSheet::Arcs(TAutoVal& Index)
{
  AUTONAMES0("Arcs")
  AUTOARGS1(Index)
  AUTOCALL_METHOD_RET
}

TAutoVal DialogSheet::Buttons(TAutoVal& Index)
{
  AUTONAMES0("Buttons")
  AUTOARGS1(Index)
  AUTOCALL_METHOD_RET
}

TAutoVal DialogSheet::ChartObjects(TAutoVal& Index)
{
  AUTONAMES0("ChartObjects")
  AUTOARGS1(Index)
  AUTOCALL_METHOD_RET
}

TAutoVal DialogSheet::CheckBoxes(TAutoVal& Index)
{
  AUTONAMES0("CheckBoxes")
  AUTOARGS1(Index)
  AUTOCALL_METHOD_RET
}

TAutoVal DialogSheet::CheckSpelling(TAutoVal& CustomDictionary, TAutoVal& IgnoreUppercase, TAutoVal& AlwaysSuggest)
{
  AUTONAMES0("CheckSpelling")
  AUTOARGS3(CustomDictionary, IgnoreUppercase, AlwaysSuggest)
  AUTOCALL_METHOD_RET
}

TAutoVal DialogSheet::Copy(TAutoVal& Before, TAutoVal& After)
{
  AUTONAMES0("Copy")
  AUTOARGS2(Before, After)
  AUTOCALL_METHOD_RET
}

TAutoVal DialogSheet::Delete()
{
  AUTONAMES0("Delete")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal DialogSheet::DrawingObjects(TAutoVal& Index)
{
  AUTONAMES0("DrawingObjects")
  AUTOARGS1(Index)
  AUTOCALL_METHOD_RET
}

TAutoVal DialogSheet::Drawings(TAutoVal& Index)
{
  AUTONAMES0("Drawings")
  AUTOARGS1(Index)
  AUTOCALL_METHOD_RET
}

TAutoVal DialogSheet::DropDowns(TAutoVal& Index)
{
  AUTONAMES0("DropDowns")
  AUTOARGS1(Index)
  AUTOCALL_METHOD_RET
}

TAutoVal DialogSheet::EditBoxes(TAutoVal& Index)
{
  AUTONAMES0("EditBoxes")
  AUTOARGS1(Index)
  AUTOCALL_METHOD_RET
}

TAutoVal DialogSheet::_Evaluate(TAutoVal& Name)
{
  AUTONAMES0("_Evaluate")
  AUTOARGS1(Name)
  AUTOCALL_METHOD_RET
}

TAutoVal DialogSheet::Evaluate(TAutoVal& Name)
{
  AUTONAMES0("Evaluate")
  AUTOARGS1(Name)
  AUTOCALL_METHOD_RET
}

TAutoVal DialogSheet::GroupBoxes(TAutoVal& Index)
{
  AUTONAMES0("GroupBoxes")
  AUTOARGS1(Index)
  AUTOCALL_METHOD_RET
}

TAutoVal DialogSheet::GroupObjects(TAutoVal& Index)
{
  AUTONAMES0("GroupObjects")
  AUTOARGS1(Index)
  AUTOCALL_METHOD_RET
}

TAutoVal DialogSheet::Hide(TAutoVal& Cancel)
{
  AUTONAMES0("Hide")
  AUTOARGS1(Cancel)
  AUTOCALL_METHOD_RET
}

TAutoVal DialogSheet::Labels(TAutoVal& Index)
{
  AUTONAMES0("Labels")
  AUTOARGS1(Index)
  AUTOCALL_METHOD_RET
}

TAutoVal DialogSheet::Lines(TAutoVal& Index)
{
  AUTONAMES0("Lines")
  AUTOARGS1(Index)
  AUTOCALL_METHOD_RET
}

TAutoVal DialogSheet::ListBoxes(TAutoVal& Index)
{
  AUTONAMES0("ListBoxes")
  AUTOARGS1(Index)
  AUTOCALL_METHOD_RET
}

TAutoVal DialogSheet::Move(TAutoVal& Before, TAutoVal& After)
{
  AUTONAMES0("Move")
  AUTOARGS2(Before, After)
  AUTOCALL_METHOD_RET
}

TAutoVal DialogSheet::Names(TAutoVal& Index, TAutoVal& IndexLocal, TAutoVal& RefersTo)
{
  AUTONAMES0("Names")
  AUTOARGS3(Index, IndexLocal, RefersTo)
  AUTOCALL_METHOD_RET
}

TAutoVal DialogSheet::OLEObjects(TAutoVal& Index)
{
  AUTONAMES0("OLEObjects")
  AUTOARGS1(Index)
  AUTOCALL_METHOD_RET
}

TAutoVal DialogSheet::OptionButtons(TAutoVal& Index)
{
  AUTONAMES0("OptionButtons")
  AUTOARGS1(Index)
  AUTOCALL_METHOD_RET
}

TAutoVal DialogSheet::Ovals(TAutoVal& Index)
{
  AUTONAMES0("Ovals")
  AUTOARGS1(Index)
  AUTOCALL_METHOD_RET
}

TAutoVal DialogSheet::Paste(TAutoVal& Destination, TAutoVal& Link)
{
  AUTONAMES0("Paste")
  AUTOARGS2(Destination, Link)
  AUTOCALL_METHOD_RET
}

TAutoVal DialogSheet::PasteSpecial(TAutoVal& Format, TAutoVal& Link, TAutoVal& DisplayAsIcon, TAutoVal& IconFileName, TAutoVal& IconIndex, TAutoVal& IconLabel)
{
  AUTONAMES0("PasteSpecial")
  AUTOARGS6(Format, Link, DisplayAsIcon, IconFileName, IconIndex, IconLabel)
  AUTOCALL_METHOD_RET
}

TAutoVal DialogSheet::Pictures(TAutoVal& Index)
{
  AUTONAMES0("Pictures")
  AUTOARGS1(Index)
  AUTOCALL_METHOD_RET
}

TAutoVal DialogSheet::PrintOut(TAutoVal& From, TAutoVal& To, TAutoVal& Copies, TAutoVal& Preview, TAutoVal& ActivePrinter, TAutoVal& PrintToFile, TAutoVal& Collate)
{
  AUTONAMES0("PrintOut")
  AUTOARGS7(From, To, Copies, Preview, ActivePrinter, PrintToFile, Collate)
  AUTOCALL_METHOD_RET
}

TAutoVal DialogSheet::PrintPreview()
{
  AUTONAMES0("PrintPreview")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal DialogSheet::Protect(TAutoVal& Password, TAutoVal& DrawingObjects, TAutoVal& Contents, TAutoVal& Scenarios, TAutoVal& UserInterfaceOnly)
{
  AUTONAMES0("Protect")
  AUTOARGS5(Password, DrawingObjects, Contents, Scenarios, UserInterfaceOnly)
  AUTOCALL_METHOD_RET
}

TAutoVal DialogSheet::Rectangles(TAutoVal& Index)
{
  AUTONAMES0("Rectangles")
  AUTOARGS1(Index)
  AUTOCALL_METHOD_RET
}

TAutoVal DialogSheet::SaveAs(TAutoVal& Filename, TAutoVal& FileFormat, TAutoVal& Password, TAutoVal& WriteResPassword, TAutoVal& ReadOnlyRecommended, TAutoVal& CreateBackup)
{
  AUTONAMES0("SaveAs")
  AUTOARGS6(Filename, FileFormat, Password, WriteResPassword, ReadOnlyRecommended, CreateBackup)
  AUTOCALL_METHOD_RET
}

TAutoVal DialogSheet::ScrollBars(TAutoVal& Index)
{
  AUTONAMES0("ScrollBars")
  AUTOARGS1(Index)
  AUTOCALL_METHOD_RET
}

TAutoVal DialogSheet::Select(TAutoVal& Replace)
{
  AUTONAMES0("Select")
  AUTOARGS1(Replace)
  AUTOCALL_METHOD_RET
}

TAutoVal DialogSheet::Show()
{
  AUTONAMES0("Show")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal DialogSheet::Spinners(TAutoVal& Index)
{
  AUTONAMES0("Spinners")
  AUTOARGS1(Index)
  AUTOCALL_METHOD_RET
}

TAutoVal DialogSheet::TextBoxes(TAutoVal& Index)
{
  AUTONAMES0("TextBoxes")
  AUTOARGS1(Index)
  AUTOCALL_METHOD_RET
}

TAutoVal DialogSheet::Unprotect(TAutoVal& Password)
{
  AUTONAMES0("Unprotect")
  AUTOARGS1(Password)
  AUTOCALL_METHOD_RET
}


// TKIND_DISPATCH: DialogSheets {000209B0-0000-0000-C000-000000000046}\9

TAutoVal DialogSheets::GetCount()
{
  AUTONAMES0("Count")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void DialogSheets::SetCount(TAutoVal& val)
{
  AUTONAMES0("Count")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal DialogSheets::GetCreator()
{
  AUTONAMES0("Creator")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void DialogSheets::SetCreator(TAutoVal& val)
{
  AUTONAMES0("Creator")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal DialogSheets::GetParent()
{
  AUTONAMES0("Parent")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void DialogSheets::SetParent(TAutoVal& val)
{
  AUTONAMES0("Parent")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal DialogSheets::GetVisible()
{
  AUTONAMES0("Visible")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void DialogSheets::SetVisible(TAutoVal& val)
{
  AUTONAMES0("Visible")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal DialogSheets::_NewEnum()
{
  AUTONAMES0("_NewEnum")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal DialogSheets::Add(TAutoVal& Before, TAutoVal& After, TAutoVal& Count)
{
  AUTONAMES0("Add")
  AUTOARGS3(Before, After, Count)
  AUTOCALL_METHOD_RET
}

TAutoVal DialogSheets::Application()
{
  AUTONAMES0("Application")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal DialogSheets::Copy(TAutoVal& Before, TAutoVal& After)
{
  AUTONAMES0("Copy")
  AUTOARGS2(Before, After)
  AUTOCALL_METHOD_RET
}

TAutoVal DialogSheets::Delete()
{
  AUTONAMES0("Delete")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal DialogSheets::Item(TAutoVal& Index)
{
  AUTONAMES0("Item")
  AUTOARGS1(Index)
  AUTOCALL_METHOD_RET
}

TAutoVal DialogSheets::Move(TAutoVal& Before, TAutoVal& After)
{
  AUTONAMES0("Move")
  AUTOARGS2(Before, After)
  AUTOCALL_METHOD_RET
}

TAutoVal DialogSheets::PrintOut(TAutoVal& From, TAutoVal& To, TAutoVal& Copies, TAutoVal& Preview, TAutoVal& ActivePrinter, TAutoVal& PrintToFile, TAutoVal& Collate)
{
  AUTONAMES0("PrintOut")
  AUTOARGS7(From, To, Copies, Preview, ActivePrinter, PrintToFile, Collate)
  AUTOCALL_METHOD_RET
}

TAutoVal DialogSheets::PrintPreview()
{
  AUTONAMES0("PrintPreview")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal DialogSheets::Select(TAutoVal& Replace)
{
  AUTONAMES0("Select")
  AUTOARGS1(Replace)
  AUTOCALL_METHOD_RET
}


// TKIND_DISPATCH: PageSetup {000208B4-0000-0000-C000-000000000046}\9

TAutoVal PageSetup::GetBlackAndWhite()
{
  AUTONAMES0("BlackAndWhite")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void PageSetup::SetBlackAndWhite(TAutoVal& val)
{
  AUTONAMES0("BlackAndWhite")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal PageSetup::GetBottomMargin()
{
  AUTONAMES0("BottomMargin")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void PageSetup::SetBottomMargin(TAutoVal& val)
{
  AUTONAMES0("BottomMargin")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal PageSetup::GetCenterFooter()
{
  AUTONAMES0("CenterFooter")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void PageSetup::SetCenterFooter(TAutoVal& val)
{
  AUTONAMES0("CenterFooter")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal PageSetup::GetCenterHeader()
{
  AUTONAMES0("CenterHeader")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void PageSetup::SetCenterHeader(TAutoVal& val)
{
  AUTONAMES0("CenterHeader")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal PageSetup::GetCenterHorizontally()
{
  AUTONAMES0("CenterHorizontally")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void PageSetup::SetCenterHorizontally(TAutoVal& val)
{
  AUTONAMES0("CenterHorizontally")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal PageSetup::GetCenterVertically()
{
  AUTONAMES0("CenterVertically")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void PageSetup::SetCenterVertically(TAutoVal& val)
{
  AUTONAMES0("CenterVertically")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal PageSetup::GetChartSize()
{
  AUTONAMES0("ChartSize")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void PageSetup::SetChartSize(TAutoVal& val)
{
  AUTONAMES0("ChartSize")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal PageSetup::GetCreator()
{
  AUTONAMES0("Creator")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void PageSetup::SetCreator(TAutoVal& val)
{
  AUTONAMES0("Creator")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal PageSetup::GetDraft()
{
  AUTONAMES0("Draft")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void PageSetup::SetDraft(TAutoVal& val)
{
  AUTONAMES0("Draft")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal PageSetup::GetFirstPageNumber()
{
  AUTONAMES0("FirstPageNumber")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void PageSetup::SetFirstPageNumber(TAutoVal& val)
{
  AUTONAMES0("FirstPageNumber")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal PageSetup::GetFitToPagesTall()
{
  AUTONAMES0("FitToPagesTall")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void PageSetup::SetFitToPagesTall(TAutoVal& val)
{
  AUTONAMES0("FitToPagesTall")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal PageSetup::GetFitToPagesWide()
{
  AUTONAMES0("FitToPagesWide")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void PageSetup::SetFitToPagesWide(TAutoVal& val)
{
  AUTONAMES0("FitToPagesWide")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal PageSetup::GetFooterMargin()
{
  AUTONAMES0("FooterMargin")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void PageSetup::SetFooterMargin(TAutoVal& val)
{
  AUTONAMES0("FooterMargin")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal PageSetup::GetHeaderMargin()
{
  AUTONAMES0("HeaderMargin")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void PageSetup::SetHeaderMargin(TAutoVal& val)
{
  AUTONAMES0("HeaderMargin")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal PageSetup::GetLeftFooter()
{
  AUTONAMES0("LeftFooter")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void PageSetup::SetLeftFooter(TAutoVal& val)
{
  AUTONAMES0("LeftFooter")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal PageSetup::GetLeftHeader()
{
  AUTONAMES0("LeftHeader")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void PageSetup::SetLeftHeader(TAutoVal& val)
{
  AUTONAMES0("LeftHeader")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal PageSetup::GetLeftMargin()
{
  AUTONAMES0("LeftMargin")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void PageSetup::SetLeftMargin(TAutoVal& val)
{
  AUTONAMES0("LeftMargin")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal PageSetup::GetOrder()
{
  AUTONAMES0("Order")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void PageSetup::SetOrder(TAutoVal& val)
{
  AUTONAMES0("Order")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal PageSetup::GetOrientation()
{
  AUTONAMES0("Orientation")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void PageSetup::SetOrientation(TAutoVal& val)
{
  AUTONAMES0("Orientation")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal PageSetup::GetPaperSize()
{
  AUTONAMES0("PaperSize")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void PageSetup::SetPaperSize(TAutoVal& val)
{
  AUTONAMES0("PaperSize")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal PageSetup::GetParent()
{
  AUTONAMES0("Parent")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void PageSetup::SetParent(TAutoVal& val)
{
  AUTONAMES0("Parent")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal PageSetup::GetPrintArea()
{
  AUTONAMES0("PrintArea")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void PageSetup::SetPrintArea(TAutoVal& val)
{
  AUTONAMES0("PrintArea")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal PageSetup::GetPrintGridlines()
{
  AUTONAMES0("PrintGridlines")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void PageSetup::SetPrintGridlines(TAutoVal& val)
{
  AUTONAMES0("PrintGridlines")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal PageSetup::GetPrintHeadings()
{
  AUTONAMES0("PrintHeadings")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void PageSetup::SetPrintHeadings(TAutoVal& val)
{
  AUTONAMES0("PrintHeadings")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal PageSetup::GetPrintNotes()
{
  AUTONAMES0("PrintNotes")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void PageSetup::SetPrintNotes(TAutoVal& val)
{
  AUTONAMES0("PrintNotes")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal PageSetup::GetPrintQuality()
{
  AUTONAMES0("PrintQuality")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void PageSetup::SetPrintQuality(TAutoVal& val)
{
  AUTONAMES0("PrintQuality")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal PageSetup::GetPrintTitleColumns()
{
  AUTONAMES0("PrintTitleColumns")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void PageSetup::SetPrintTitleColumns(TAutoVal& val)
{
  AUTONAMES0("PrintTitleColumns")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal PageSetup::GetPrintTitleRows()
{
  AUTONAMES0("PrintTitleRows")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void PageSetup::SetPrintTitleRows(TAutoVal& val)
{
  AUTONAMES0("PrintTitleRows")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal PageSetup::GetRightFooter()
{
  AUTONAMES0("RightFooter")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void PageSetup::SetRightFooter(TAutoVal& val)
{
  AUTONAMES0("RightFooter")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal PageSetup::GetRightHeader()
{
  AUTONAMES0("RightHeader")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void PageSetup::SetRightHeader(TAutoVal& val)
{
  AUTONAMES0("RightHeader")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal PageSetup::GetRightMargin()
{
  AUTONAMES0("RightMargin")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void PageSetup::SetRightMargin(TAutoVal& val)
{
  AUTONAMES0("RightMargin")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal PageSetup::GetTopMargin()
{
  AUTONAMES0("TopMargin")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void PageSetup::SetTopMargin(TAutoVal& val)
{
  AUTONAMES0("TopMargin")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal PageSetup::GetZoom()
{
  AUTONAMES0("Zoom")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void PageSetup::SetZoom(TAutoVal& val)
{
  AUTONAMES0("Zoom")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal PageSetup::Application()
{
  AUTONAMES0("Application")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}


// TKIND_DISPATCH: Mailer {000208D1-0000-0000-C000-000000000046}\9

TAutoVal Mailer::GetBCCRecipients()
{
  AUTONAMES0("BCCRecipients")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Mailer::SetBCCRecipients(TAutoVal& val)
{
  AUTONAMES0("BCCRecipients")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Mailer::GetCCRecipients()
{
  AUTONAMES0("CCRecipients")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Mailer::SetCCRecipients(TAutoVal& val)
{
  AUTONAMES0("CCRecipients")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Mailer::GetCreator()
{
  AUTONAMES0("Creator")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Mailer::SetCreator(TAutoVal& val)
{
  AUTONAMES0("Creator")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Mailer::GetEnclosures()
{
  AUTONAMES0("Enclosures")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Mailer::SetEnclosures(TAutoVal& val)
{
  AUTONAMES0("Enclosures")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Mailer::GetParent()
{
  AUTONAMES0("Parent")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Mailer::SetParent(TAutoVal& val)
{
  AUTONAMES0("Parent")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Mailer::GetReceived()
{
  AUTONAMES0("Received")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Mailer::SetReceived(TAutoVal& val)
{
  AUTONAMES0("Received")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Mailer::GetSendDateTime()
{
  AUTONAMES0("SendDateTime")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Mailer::SetSendDateTime(TAutoVal& val)
{
  AUTONAMES0("SendDateTime")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Mailer::GetSender()
{
  AUTONAMES0("Sender")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Mailer::SetSender(TAutoVal& val)
{
  AUTONAMES0("Sender")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Mailer::GetSubject()
{
  AUTONAMES0("Subject")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Mailer::SetSubject(TAutoVal& val)
{
  AUTONAMES0("Subject")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Mailer::GetToRecipients()
{
  AUTONAMES0("ToRecipients")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Mailer::SetToRecipients(TAutoVal& val)
{
  AUTONAMES0("ToRecipients")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Mailer::GetWhichAddress()
{
  AUTONAMES0("WhichAddress")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Mailer::SetWhichAddress(TAutoVal& val)
{
  AUTONAMES0("WhichAddress")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Mailer::Application()
{
  AUTONAMES0("Application")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}


// TKIND_DISPATCH: Font {0002084D-0000-0000-C000-000000000046}\9

TAutoVal Font::GetBackground()
{
  AUTONAMES0("Background")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Font::SetBackground(TAutoVal& val)
{
  AUTONAMES0("Background")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Font::GetBold()
{
  AUTONAMES0("Bold")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Font::SetBold(TAutoVal& val)
{
  AUTONAMES0("Bold")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Font::GetColor()
{
  AUTONAMES0("Color")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Font::SetColor(TAutoVal& val)
{
  AUTONAMES0("Color")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Font::GetColorIndex()
{
  AUTONAMES0("ColorIndex")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Font::SetColorIndex(TAutoVal& val)
{
  AUTONAMES0("ColorIndex")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Font::GetCreator()
{
  AUTONAMES0("Creator")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Font::SetCreator(TAutoVal& val)
{
  AUTONAMES0("Creator")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Font::GetFontStyle()
{
  AUTONAMES0("FontStyle")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Font::SetFontStyle(TAutoVal& val)
{
  AUTONAMES0("FontStyle")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Font::GetItalic()
{
  AUTONAMES0("Italic")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Font::SetItalic(TAutoVal& val)
{
  AUTONAMES0("Italic")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Font::GetName()
{
  AUTONAMES0("Name")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Font::SetName(TAutoVal& val)
{
  AUTONAMES0("Name")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Font::GetOutlineFont()
{
  AUTONAMES0("OutlineFont")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Font::SetOutlineFont(TAutoVal& val)
{
  AUTONAMES0("OutlineFont")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Font::GetParent()
{
  AUTONAMES0("Parent")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Font::SetParent(TAutoVal& val)
{
  AUTONAMES0("Parent")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Font::GetShadow()
{
  AUTONAMES0("Shadow")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Font::SetShadow(TAutoVal& val)
{
  AUTONAMES0("Shadow")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Font::GetSize()
{
  AUTONAMES0("Size")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Font::SetSize(TAutoVal& val)
{
  AUTONAMES0("Size")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Font::GetStrikethrough()
{
  AUTONAMES0("Strikethrough")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Font::SetStrikethrough(TAutoVal& val)
{
  AUTONAMES0("Strikethrough")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Font::GetSubscript()
{
  AUTONAMES0("Subscript")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Font::SetSubscript(TAutoVal& val)
{
  AUTONAMES0("Subscript")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Font::GetSuperscript()
{
  AUTONAMES0("Superscript")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Font::SetSuperscript(TAutoVal& val)
{
  AUTONAMES0("Superscript")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Font::GetUnderline()
{
  AUTONAMES0("Underline")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Font::SetUnderline(TAutoVal& val)
{
  AUTONAMES0("Underline")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Font::Application()
{
  AUTONAMES0("Application")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}


// TKIND_DISPATCH: Border {00020854-0000-0000-C000-000000000046}\9

TAutoVal Border::GetColor()
{
  AUTONAMES0("Color")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Border::SetColor(TAutoVal& val)
{
  AUTONAMES0("Color")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Border::GetColorIndex()
{
  AUTONAMES0("ColorIndex")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Border::SetColorIndex(TAutoVal& val)
{
  AUTONAMES0("ColorIndex")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Border::GetCreator()
{
  AUTONAMES0("Creator")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Border::SetCreator(TAutoVal& val)
{
  AUTONAMES0("Creator")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Border::GetLineStyle()
{
  AUTONAMES0("LineStyle")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Border::SetLineStyle(TAutoVal& val)
{
  AUTONAMES0("LineStyle")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Border::GetParent()
{
  AUTONAMES0("Parent")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Border::SetParent(TAutoVal& val)
{
  AUTONAMES0("Parent")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Border::GetWeight()
{
  AUTONAMES0("Weight")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Border::SetWeight(TAutoVal& val)
{
  AUTONAMES0("Weight")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Border::Application()
{
  AUTONAMES0("Application")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}


// TKIND_DISPATCH: Borders {00020855-0000-0000-C000-000000000046}\9

TAutoVal Borders::GetColor()
{
  AUTONAMES0("Color")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Borders::SetColor(TAutoVal& val)
{
  AUTONAMES0("Color")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Borders::GetColorIndex()
{
  AUTONAMES0("ColorIndex")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Borders::SetColorIndex(TAutoVal& val)
{
  AUTONAMES0("ColorIndex")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Borders::GetCount()
{
  AUTONAMES0("Count")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Borders::SetCount(TAutoVal& val)
{
  AUTONAMES0("Count")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Borders::GetCreator()
{
  AUTONAMES0("Creator")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Borders::SetCreator(TAutoVal& val)
{
  AUTONAMES0("Creator")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Borders::GetLineStyle()
{
  AUTONAMES0("LineStyle")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Borders::SetLineStyle(TAutoVal& val)
{
  AUTONAMES0("LineStyle")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Borders::GetParent()
{
  AUTONAMES0("Parent")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Borders::SetParent(TAutoVal& val)
{
  AUTONAMES0("Parent")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Borders::GetValue()
{
  AUTONAMES0("Value")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Borders::SetValue(TAutoVal& val)
{
  AUTONAMES0("Value")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Borders::GetWeight()
{
  AUTONAMES0("Weight")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Borders::SetWeight(TAutoVal& val)
{
  AUTONAMES0("Weight")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Borders::_NewEnum()
{
  AUTONAMES0("_NewEnum")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Borders::Application()
{
  AUTONAMES0("Application")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Borders::Item(TAutoVal& Index)
{
  AUTONAMES0("Item")
  AUTOARGS1(Index)
  AUTOCALL_METHOD_RET
}


// TKIND_DISPATCH: Corners {000208C0-0000-0000-C000-000000000046}\9

TAutoVal Corners::GetCreator()
{
  AUTONAMES0("Creator")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Corners::SetCreator(TAutoVal& val)
{
  AUTONAMES0("Creator")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Corners::GetName()
{
  AUTONAMES0("Name")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Corners::SetName(TAutoVal& val)
{
  AUTONAMES0("Name")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Corners::GetParent()
{
  AUTONAMES0("Parent")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Corners::SetParent(TAutoVal& val)
{
  AUTONAMES0("Parent")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Corners::Application()
{
  AUTONAMES0("Application")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Corners::Select()
{
  AUTONAMES0("Select")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}


// TKIND_DISPATCH: SeriesLines {000208C1-0000-0000-C000-000000000046}\9

TAutoVal SeriesLines::GetBorder()
{
  AUTONAMES0("Border")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void SeriesLines::SetBorder(TAutoVal& val)
{
  AUTONAMES0("Border")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal SeriesLines::GetCreator()
{
  AUTONAMES0("Creator")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void SeriesLines::SetCreator(TAutoVal& val)
{
  AUTONAMES0("Creator")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal SeriesLines::GetName()
{
  AUTONAMES0("Name")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void SeriesLines::SetName(TAutoVal& val)
{
  AUTONAMES0("Name")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal SeriesLines::GetParent()
{
  AUTONAMES0("Parent")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void SeriesLines::SetParent(TAutoVal& val)
{
  AUTONAMES0("Parent")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal SeriesLines::Application()
{
  AUTONAMES0("Application")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal SeriesLines::Delete()
{
  AUTONAMES0("Delete")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal SeriesLines::Select()
{
  AUTONAMES0("Select")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}


// TKIND_DISPATCH: HiLoLines {000208C2-0000-0000-C000-000000000046}\9

TAutoVal HiLoLines::GetBorder()
{
  AUTONAMES0("Border")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void HiLoLines::SetBorder(TAutoVal& val)
{
  AUTONAMES0("Border")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal HiLoLines::GetCreator()
{
  AUTONAMES0("Creator")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void HiLoLines::SetCreator(TAutoVal& val)
{
  AUTONAMES0("Creator")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal HiLoLines::GetName()
{
  AUTONAMES0("Name")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void HiLoLines::SetName(TAutoVal& val)
{
  AUTONAMES0("Name")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal HiLoLines::GetParent()
{
  AUTONAMES0("Parent")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void HiLoLines::SetParent(TAutoVal& val)
{
  AUTONAMES0("Parent")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal HiLoLines::Application()
{
  AUTONAMES0("Application")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal HiLoLines::Delete()
{
  AUTONAMES0("Delete")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal HiLoLines::Select()
{
  AUTONAMES0("Select")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}


// TKIND_DISPATCH: Gridlines {000208C3-0000-0000-C000-000000000046}\9

TAutoVal Gridlines::GetBorder()
{
  AUTONAMES0("Border")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Gridlines::SetBorder(TAutoVal& val)
{
  AUTONAMES0("Border")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Gridlines::GetCreator()
{
  AUTONAMES0("Creator")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Gridlines::SetCreator(TAutoVal& val)
{
  AUTONAMES0("Creator")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Gridlines::GetName()
{
  AUTONAMES0("Name")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Gridlines::SetName(TAutoVal& val)
{
  AUTONAMES0("Name")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Gridlines::GetParent()
{
  AUTONAMES0("Parent")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Gridlines::SetParent(TAutoVal& val)
{
  AUTONAMES0("Parent")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Gridlines::Application()
{
  AUTONAMES0("Application")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Gridlines::Delete()
{
  AUTONAMES0("Delete")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Gridlines::Select()
{
  AUTONAMES0("Select")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}


// TKIND_DISPATCH: DropLines {000208C4-0000-0000-C000-000000000046}\9

TAutoVal DropLines::GetBorder()
{
  AUTONAMES0("Border")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void DropLines::SetBorder(TAutoVal& val)
{
  AUTONAMES0("Border")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal DropLines::GetCreator()
{
  AUTONAMES0("Creator")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void DropLines::SetCreator(TAutoVal& val)
{
  AUTONAMES0("Creator")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal DropLines::GetName()
{
  AUTONAMES0("Name")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void DropLines::SetName(TAutoVal& val)
{
  AUTONAMES0("Name")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal DropLines::GetParent()
{
  AUTONAMES0("Parent")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void DropLines::SetParent(TAutoVal& val)
{
  AUTONAMES0("Parent")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal DropLines::Application()
{
  AUTONAMES0("Application")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal DropLines::Delete()
{
  AUTONAMES0("Delete")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal DropLines::Select()
{
  AUTONAMES0("Select")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}


// TKIND_DISPATCH: ErrorBars {000208CE-0000-0000-C000-000000000046}\9

TAutoVal ErrorBars::GetBorder()
{
  AUTONAMES0("Border")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void ErrorBars::SetBorder(TAutoVal& val)
{
  AUTONAMES0("Border")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal ErrorBars::GetCreator()
{
  AUTONAMES0("Creator")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void ErrorBars::SetCreator(TAutoVal& val)
{
  AUTONAMES0("Creator")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal ErrorBars::GetEndStyle()
{
  AUTONAMES0("EndStyle")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void ErrorBars::SetEndStyle(TAutoVal& val)
{
  AUTONAMES0("EndStyle")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal ErrorBars::GetName()
{
  AUTONAMES0("Name")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void ErrorBars::SetName(TAutoVal& val)
{
  AUTONAMES0("Name")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal ErrorBars::GetParent()
{
  AUTONAMES0("Parent")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void ErrorBars::SetParent(TAutoVal& val)
{
  AUTONAMES0("Parent")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal ErrorBars::Application()
{
  AUTONAMES0("Application")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal ErrorBars::ClearFormats()
{
  AUTONAMES0("ClearFormats")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal ErrorBars::Delete()
{
  AUTONAMES0("Delete")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal ErrorBars::Select()
{
  AUTONAMES0("Select")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}


// TKIND_DISPATCH: UpBars {000208C5-0000-0000-C000-000000000046}\9

TAutoVal UpBars::GetBorder()
{
  AUTONAMES0("Border")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void UpBars::SetBorder(TAutoVal& val)
{
  AUTONAMES0("Border")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal UpBars::GetCreator()
{
  AUTONAMES0("Creator")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void UpBars::SetCreator(TAutoVal& val)
{
  AUTONAMES0("Creator")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal UpBars::GetInterior()
{
  AUTONAMES0("Interior")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void UpBars::SetInterior(TAutoVal& val)
{
  AUTONAMES0("Interior")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal UpBars::GetName()
{
  AUTONAMES0("Name")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void UpBars::SetName(TAutoVal& val)
{
  AUTONAMES0("Name")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal UpBars::GetParent()
{
  AUTONAMES0("Parent")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void UpBars::SetParent(TAutoVal& val)
{
  AUTONAMES0("Parent")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal UpBars::Application()
{
  AUTONAMES0("Application")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal UpBars::Delete()
{
  AUTONAMES0("Delete")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal UpBars::Select()
{
  AUTONAMES0("Select")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}


// TKIND_DISPATCH: DownBars {000208C6-0000-0000-C000-000000000046}\9

TAutoVal DownBars::GetBorder()
{
  AUTONAMES0("Border")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void DownBars::SetBorder(TAutoVal& val)
{
  AUTONAMES0("Border")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal DownBars::GetCreator()
{
  AUTONAMES0("Creator")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void DownBars::SetCreator(TAutoVal& val)
{
  AUTONAMES0("Creator")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal DownBars::GetInterior()
{
  AUTONAMES0("Interior")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void DownBars::SetInterior(TAutoVal& val)
{
  AUTONAMES0("Interior")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal DownBars::GetName()
{
  AUTONAMES0("Name")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void DownBars::SetName(TAutoVal& val)
{
  AUTONAMES0("Name")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal DownBars::GetParent()
{
  AUTONAMES0("Parent")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void DownBars::SetParent(TAutoVal& val)
{
  AUTONAMES0("Parent")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal DownBars::Application()
{
  AUTONAMES0("Application")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal DownBars::Delete()
{
  AUTONAMES0("Delete")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal DownBars::Select()
{
  AUTONAMES0("Select")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}


// TKIND_DISPATCH: ChartTitle {00020849-0000-0000-C000-000000000046}\9

TAutoVal ChartTitle::GetBorder()
{
  AUTONAMES0("Border")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void ChartTitle::SetBorder(TAutoVal& val)
{
  AUTONAMES0("Border")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal ChartTitle::GetCaption()
{
  AUTONAMES0("Caption")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void ChartTitle::SetCaption(TAutoVal& val)
{
  AUTONAMES0("Caption")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal ChartTitle::GetCreator()
{
  AUTONAMES0("Creator")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void ChartTitle::SetCreator(TAutoVal& val)
{
  AUTONAMES0("Creator")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal ChartTitle::GetFont()
{
  AUTONAMES0("Font")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void ChartTitle::SetFont(TAutoVal& val)
{
  AUTONAMES0("Font")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal ChartTitle::GetHorizontalAlignment()
{
  AUTONAMES0("HorizontalAlignment")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void ChartTitle::SetHorizontalAlignment(TAutoVal& val)
{
  AUTONAMES0("HorizontalAlignment")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal ChartTitle::GetInterior()
{
  AUTONAMES0("Interior")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void ChartTitle::SetInterior(TAutoVal& val)
{
  AUTONAMES0("Interior")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal ChartTitle::GetLeft()
{
  AUTONAMES0("Left")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void ChartTitle::SetLeft(TAutoVal& val)
{
  AUTONAMES0("Left")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal ChartTitle::GetName()
{
  AUTONAMES0("Name")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void ChartTitle::SetName(TAutoVal& val)
{
  AUTONAMES0("Name")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal ChartTitle::GetOrientation()
{
  AUTONAMES0("Orientation")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void ChartTitle::SetOrientation(TAutoVal& val)
{
  AUTONAMES0("Orientation")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal ChartTitle::GetParent()
{
  AUTONAMES0("Parent")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void ChartTitle::SetParent(TAutoVal& val)
{
  AUTONAMES0("Parent")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal ChartTitle::GetShadow()
{
  AUTONAMES0("Shadow")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void ChartTitle::SetShadow(TAutoVal& val)
{
  AUTONAMES0("Shadow")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal ChartTitle::GetText()
{
  AUTONAMES0("Text")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void ChartTitle::SetText(TAutoVal& val)
{
  AUTONAMES0("Text")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal ChartTitle::GetTop()
{
  AUTONAMES0("Top")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void ChartTitle::SetTop(TAutoVal& val)
{
  AUTONAMES0("Top")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal ChartTitle::GetVerticalAlignment()
{
  AUTONAMES0("VerticalAlignment")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void ChartTitle::SetVerticalAlignment(TAutoVal& val)
{
  AUTONAMES0("VerticalAlignment")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal ChartTitle::Application()
{
  AUTONAMES0("Application")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal ChartTitle::Characters(TAutoVal& Start, TAutoVal& Length)
{
  AUTONAMES0("Characters")
  AUTOARGS2(Start, Length)
  AUTOCALL_METHOD_RET
}

TAutoVal ChartTitle::Delete()
{
  AUTONAMES0("Delete")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal ChartTitle::Select()
{
  AUTONAMES0("Select")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}


// TKIND_DISPATCH: AxisTitle {0002084A-0000-0000-C000-000000000046}\9

TAutoVal AxisTitle::GetBorder()
{
  AUTONAMES0("Border")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void AxisTitle::SetBorder(TAutoVal& val)
{
  AUTONAMES0("Border")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal AxisTitle::GetCaption()
{
  AUTONAMES0("Caption")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void AxisTitle::SetCaption(TAutoVal& val)
{
  AUTONAMES0("Caption")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal AxisTitle::GetCreator()
{
  AUTONAMES0("Creator")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void AxisTitle::SetCreator(TAutoVal& val)
{
  AUTONAMES0("Creator")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal AxisTitle::GetFont()
{
  AUTONAMES0("Font")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void AxisTitle::SetFont(TAutoVal& val)
{
  AUTONAMES0("Font")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal AxisTitle::GetHorizontalAlignment()
{
  AUTONAMES0("HorizontalAlignment")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void AxisTitle::SetHorizontalAlignment(TAutoVal& val)
{
  AUTONAMES0("HorizontalAlignment")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal AxisTitle::GetInterior()
{
  AUTONAMES0("Interior")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void AxisTitle::SetInterior(TAutoVal& val)
{
  AUTONAMES0("Interior")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal AxisTitle::GetLeft()
{
  AUTONAMES0("Left")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void AxisTitle::SetLeft(TAutoVal& val)
{
  AUTONAMES0("Left")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal AxisTitle::GetName()
{
  AUTONAMES0("Name")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void AxisTitle::SetName(TAutoVal& val)
{
  AUTONAMES0("Name")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal AxisTitle::GetOrientation()
{
  AUTONAMES0("Orientation")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void AxisTitle::SetOrientation(TAutoVal& val)
{
  AUTONAMES0("Orientation")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal AxisTitle::GetParent()
{
  AUTONAMES0("Parent")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void AxisTitle::SetParent(TAutoVal& val)
{
  AUTONAMES0("Parent")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal AxisTitle::GetShadow()
{
  AUTONAMES0("Shadow")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void AxisTitle::SetShadow(TAutoVal& val)
{
  AUTONAMES0("Shadow")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal AxisTitle::GetText()
{
  AUTONAMES0("Text")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void AxisTitle::SetText(TAutoVal& val)
{
  AUTONAMES0("Text")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal AxisTitle::GetTop()
{
  AUTONAMES0("Top")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void AxisTitle::SetTop(TAutoVal& val)
{
  AUTONAMES0("Top")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal AxisTitle::GetVerticalAlignment()
{
  AUTONAMES0("VerticalAlignment")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void AxisTitle::SetVerticalAlignment(TAutoVal& val)
{
  AUTONAMES0("VerticalAlignment")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal AxisTitle::Application()
{
  AUTONAMES0("Application")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal AxisTitle::Characters(TAutoVal& Start, TAutoVal& Length)
{
  AUTONAMES0("Characters")
  AUTOARGS2(Start, Length)
  AUTOCALL_METHOD_RET
}

TAutoVal AxisTitle::Delete()
{
  AUTONAMES0("Delete")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal AxisTitle::Select()
{
  AUTONAMES0("Select")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}


// TKIND_DISPATCH: Floor {000208C7-0000-0000-C000-000000000046}\9

TAutoVal Floor::GetBorder()
{
  AUTONAMES0("Border")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Floor::SetBorder(TAutoVal& val)
{
  AUTONAMES0("Border")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Floor::GetCreator()
{
  AUTONAMES0("Creator")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Floor::SetCreator(TAutoVal& val)
{
  AUTONAMES0("Creator")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Floor::GetInterior()
{
  AUTONAMES0("Interior")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Floor::SetInterior(TAutoVal& val)
{
  AUTONAMES0("Interior")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Floor::GetName()
{
  AUTONAMES0("Name")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Floor::SetName(TAutoVal& val)
{
  AUTONAMES0("Name")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Floor::GetParent()
{
  AUTONAMES0("Parent")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Floor::SetParent(TAutoVal& val)
{
  AUTONAMES0("Parent")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Floor::Application()
{
  AUTONAMES0("Application")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Floor::ClearFormats()
{
  AUTONAMES0("ClearFormats")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Floor::Select()
{
  AUTONAMES0("Select")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}


// TKIND_DISPATCH: Walls {000208C8-0000-0000-C000-000000000046}\9

TAutoVal Walls::GetBorder()
{
  AUTONAMES0("Border")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Walls::SetBorder(TAutoVal& val)
{
  AUTONAMES0("Border")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Walls::GetCreator()
{
  AUTONAMES0("Creator")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Walls::SetCreator(TAutoVal& val)
{
  AUTONAMES0("Creator")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Walls::GetInterior()
{
  AUTONAMES0("Interior")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Walls::SetInterior(TAutoVal& val)
{
  AUTONAMES0("Interior")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Walls::GetName()
{
  AUTONAMES0("Name")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Walls::SetName(TAutoVal& val)
{
  AUTONAMES0("Name")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Walls::GetParent()
{
  AUTONAMES0("Parent")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Walls::SetParent(TAutoVal& val)
{
  AUTONAMES0("Parent")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Walls::Application()
{
  AUTONAMES0("Application")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Walls::ClearFormats()
{
  AUTONAMES0("ClearFormats")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Walls::Select()
{
  AUTONAMES0("Select")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}


// TKIND_DISPATCH: PlotArea {000208CB-0000-0000-C000-000000000046}\9

TAutoVal PlotArea::GetBorder()
{
  AUTONAMES0("Border")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void PlotArea::SetBorder(TAutoVal& val)
{
  AUTONAMES0("Border")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal PlotArea::GetCreator()
{
  AUTONAMES0("Creator")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void PlotArea::SetCreator(TAutoVal& val)
{
  AUTONAMES0("Creator")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal PlotArea::GetHeight()
{
  AUTONAMES0("Height")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void PlotArea::SetHeight(TAutoVal& val)
{
  AUTONAMES0("Height")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal PlotArea::GetInterior()
{
  AUTONAMES0("Interior")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void PlotArea::SetInterior(TAutoVal& val)
{
  AUTONAMES0("Interior")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal PlotArea::GetLeft()
{
  AUTONAMES0("Left")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void PlotArea::SetLeft(TAutoVal& val)
{
  AUTONAMES0("Left")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal PlotArea::GetName()
{
  AUTONAMES0("Name")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void PlotArea::SetName(TAutoVal& val)
{
  AUTONAMES0("Name")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal PlotArea::GetParent()
{
  AUTONAMES0("Parent")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void PlotArea::SetParent(TAutoVal& val)
{
  AUTONAMES0("Parent")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal PlotArea::GetTop()
{
  AUTONAMES0("Top")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void PlotArea::SetTop(TAutoVal& val)
{
  AUTONAMES0("Top")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal PlotArea::GetWidth()
{
  AUTONAMES0("Width")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void PlotArea::SetWidth(TAutoVal& val)
{
  AUTONAMES0("Width")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal PlotArea::Application()
{
  AUTONAMES0("Application")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal PlotArea::ClearFormats()
{
  AUTONAMES0("ClearFormats")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal PlotArea::Select()
{
  AUTONAMES0("Select")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}


// TKIND_DISPATCH: ChartArea {000208CC-0000-0000-C000-000000000046}\9

TAutoVal ChartArea::GetBorder()
{
  AUTONAMES0("Border")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void ChartArea::SetBorder(TAutoVal& val)
{
  AUTONAMES0("Border")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal ChartArea::GetCreator()
{
  AUTONAMES0("Creator")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void ChartArea::SetCreator(TAutoVal& val)
{
  AUTONAMES0("Creator")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal ChartArea::GetFont()
{
  AUTONAMES0("Font")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void ChartArea::SetFont(TAutoVal& val)
{
  AUTONAMES0("Font")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal ChartArea::GetHeight()
{
  AUTONAMES0("Height")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void ChartArea::SetHeight(TAutoVal& val)
{
  AUTONAMES0("Height")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal ChartArea::GetInterior()
{
  AUTONAMES0("Interior")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void ChartArea::SetInterior(TAutoVal& val)
{
  AUTONAMES0("Interior")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal ChartArea::GetLeft()
{
  AUTONAMES0("Left")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void ChartArea::SetLeft(TAutoVal& val)
{
  AUTONAMES0("Left")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal ChartArea::GetName()
{
  AUTONAMES0("Name")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void ChartArea::SetName(TAutoVal& val)
{
  AUTONAMES0("Name")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal ChartArea::GetParent()
{
  AUTONAMES0("Parent")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void ChartArea::SetParent(TAutoVal& val)
{
  AUTONAMES0("Parent")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal ChartArea::GetShadow()
{
  AUTONAMES0("Shadow")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void ChartArea::SetShadow(TAutoVal& val)
{
  AUTONAMES0("Shadow")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal ChartArea::GetTop()
{
  AUTONAMES0("Top")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void ChartArea::SetTop(TAutoVal& val)
{
  AUTONAMES0("Top")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal ChartArea::GetWidth()
{
  AUTONAMES0("Width")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void ChartArea::SetWidth(TAutoVal& val)
{
  AUTONAMES0("Width")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal ChartArea::Application()
{
  AUTONAMES0("Application")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal ChartArea::Clear()
{
  AUTONAMES0("Clear")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal ChartArea::ClearContents()
{
  AUTONAMES0("ClearContents")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal ChartArea::ClearFormats()
{
  AUTONAMES0("ClearFormats")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal ChartArea::Copy()
{
  AUTONAMES0("Copy")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal ChartArea::Select()
{
  AUTONAMES0("Select")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}


// TKIND_DISPATCH: Legend {000208CD-0000-0000-C000-000000000046}\9

TAutoVal Legend::GetBorder()
{
  AUTONAMES0("Border")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Legend::SetBorder(TAutoVal& val)
{
  AUTONAMES0("Border")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Legend::GetCreator()
{
  AUTONAMES0("Creator")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Legend::SetCreator(TAutoVal& val)
{
  AUTONAMES0("Creator")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Legend::GetFont()
{
  AUTONAMES0("Font")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Legend::SetFont(TAutoVal& val)
{
  AUTONAMES0("Font")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Legend::GetHeight()
{
  AUTONAMES0("Height")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Legend::SetHeight(TAutoVal& val)
{
  AUTONAMES0("Height")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Legend::GetInterior()
{
  AUTONAMES0("Interior")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Legend::SetInterior(TAutoVal& val)
{
  AUTONAMES0("Interior")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Legend::GetLeft()
{
  AUTONAMES0("Left")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Legend::SetLeft(TAutoVal& val)
{
  AUTONAMES0("Left")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Legend::GetName()
{
  AUTONAMES0("Name")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Legend::SetName(TAutoVal& val)
{
  AUTONAMES0("Name")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Legend::GetParent()
{
  AUTONAMES0("Parent")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Legend::SetParent(TAutoVal& val)
{
  AUTONAMES0("Parent")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Legend::GetPosition()
{
  AUTONAMES0("Position")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Legend::SetPosition(TAutoVal& val)
{
  AUTONAMES0("Position")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Legend::GetShadow()
{
  AUTONAMES0("Shadow")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Legend::SetShadow(TAutoVal& val)
{
  AUTONAMES0("Shadow")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Legend::GetTop()
{
  AUTONAMES0("Top")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Legend::SetTop(TAutoVal& val)
{
  AUTONAMES0("Top")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Legend::GetWidth()
{
  AUTONAMES0("Width")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Legend::SetWidth(TAutoVal& val)
{
  AUTONAMES0("Width")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Legend::Application()
{
  AUTONAMES0("Application")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Legend::Delete()
{
  AUTONAMES0("Delete")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Legend::LegendEntries(TAutoVal& Index)
{
  AUTONAMES0("LegendEntries")
  AUTOARGS1(Index)
  AUTOCALL_METHOD_RET
}

TAutoVal Legend::Select()
{
  AUTONAMES0("Select")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}


// TKIND_DISPATCH: TickLabels {000208C9-0000-0000-C000-000000000046}\9

TAutoVal TickLabels::GetCreator()
{
  AUTONAMES0("Creator")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void TickLabels::SetCreator(TAutoVal& val)
{
  AUTONAMES0("Creator")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal TickLabels::GetFont()
{
  AUTONAMES0("Font")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void TickLabels::SetFont(TAutoVal& val)
{
  AUTONAMES0("Font")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal TickLabels::GetName()
{
  AUTONAMES0("Name")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void TickLabels::SetName(TAutoVal& val)
{
  AUTONAMES0("Name")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal TickLabels::GetNumberFormat()
{
  AUTONAMES0("NumberFormat")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void TickLabels::SetNumberFormat(TAutoVal& val)
{
  AUTONAMES0("NumberFormat")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal TickLabels::GetNumberFormatLinked()
{
  AUTONAMES0("NumberFormatLinked")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void TickLabels::SetNumberFormatLinked(TAutoVal& val)
{
  AUTONAMES0("NumberFormatLinked")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal TickLabels::GetOrientation()
{
  AUTONAMES0("Orientation")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void TickLabels::SetOrientation(TAutoVal& val)
{
  AUTONAMES0("Orientation")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal TickLabels::GetParent()
{
  AUTONAMES0("Parent")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void TickLabels::SetParent(TAutoVal& val)
{
  AUTONAMES0("Parent")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal TickLabels::Application()
{
  AUTONAMES0("Application")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal TickLabels::Delete()
{
  AUTONAMES0("Delete")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal TickLabels::Select()
{
  AUTONAMES0("Select")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}


// TKIND_DISPATCH: Chart {00020847-0000-0000-C000-000000000046}\9

TAutoVal Chart::GetArea3DGroup()
{
  AUTONAMES0("Area3DGroup")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Chart::SetArea3DGroup(TAutoVal& val)
{
  AUTONAMES0("Area3DGroup")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Chart::GetAutoScaling()
{
  AUTONAMES0("AutoScaling")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Chart::SetAutoScaling(TAutoVal& val)
{
  AUTONAMES0("AutoScaling")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Chart::GetBar3DGroup()
{
  AUTONAMES0("Bar3DGroup")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Chart::SetBar3DGroup(TAutoVal& val)
{
  AUTONAMES0("Bar3DGroup")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Chart::GetChartArea()
{
  AUTONAMES0("ChartArea")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Chart::SetChartArea(TAutoVal& val)
{
  AUTONAMES0("ChartArea")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Chart::GetChartTitle()
{
  AUTONAMES0("ChartTitle")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Chart::SetChartTitle(TAutoVal& val)
{
  AUTONAMES0("ChartTitle")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Chart::GetColumn3DGroup()
{
  AUTONAMES0("Column3DGroup")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Chart::SetColumn3DGroup(TAutoVal& val)
{
  AUTONAMES0("Column3DGroup")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Chart::GetCorners()
{
  AUTONAMES0("Corners")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Chart::SetCorners(TAutoVal& val)
{
  AUTONAMES0("Corners")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Chart::GetCreator()
{
  AUTONAMES0("Creator")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Chart::SetCreator(TAutoVal& val)
{
  AUTONAMES0("Creator")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Chart::GetDepthPercent()
{
  AUTONAMES0("DepthPercent")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Chart::SetDepthPercent(TAutoVal& val)
{
  AUTONAMES0("DepthPercent")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Chart::GetDisplayBlanksAs()
{
  AUTONAMES0("DisplayBlanksAs")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Chart::SetDisplayBlanksAs(TAutoVal& val)
{
  AUTONAMES0("DisplayBlanksAs")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Chart::GetElevation()
{
  AUTONAMES0("Elevation")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Chart::SetElevation(TAutoVal& val)
{
  AUTONAMES0("Elevation")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Chart::GetFloor()
{
  AUTONAMES0("Floor")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Chart::SetFloor(TAutoVal& val)
{
  AUTONAMES0("Floor")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Chart::GetGapDepth()
{
  AUTONAMES0("GapDepth")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Chart::SetGapDepth(TAutoVal& val)
{
  AUTONAMES0("GapDepth")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Chart::GetHasAxis()
{
  AUTONAMES0("HasAxis")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Chart::SetHasAxis(TAutoVal& val)
{
  AUTONAMES0("HasAxis")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Chart::GetHasLegend()
{
  AUTONAMES0("HasLegend")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Chart::SetHasLegend(TAutoVal& val)
{
  AUTONAMES0("HasLegend")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Chart::GetHasTitle()
{
  AUTONAMES0("HasTitle")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Chart::SetHasTitle(TAutoVal& val)
{
  AUTONAMES0("HasTitle")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Chart::GetHeightPercent()
{
  AUTONAMES0("HeightPercent")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Chart::SetHeightPercent(TAutoVal& val)
{
  AUTONAMES0("HeightPercent")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Chart::GetIndex()
{
  AUTONAMES0("Index")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Chart::SetIndex(TAutoVal& val)
{
  AUTONAMES0("Index")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Chart::GetLegend()
{
  AUTONAMES0("Legend")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Chart::SetLegend(TAutoVal& val)
{
  AUTONAMES0("Legend")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Chart::GetLine3DGroup()
{
  AUTONAMES0("Line3DGroup")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Chart::SetLine3DGroup(TAutoVal& val)
{
  AUTONAMES0("Line3DGroup")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Chart::GetName()
{
  AUTONAMES0("Name")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Chart::SetName(TAutoVal& val)
{
  AUTONAMES0("Name")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Chart::GetNext()
{
  AUTONAMES0("Next")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Chart::SetNext(TAutoVal& val)
{
  AUTONAMES0("Next")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Chart::GetOnDoubleClick()
{
  AUTONAMES0("OnDoubleClick")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Chart::SetOnDoubleClick(TAutoVal& val)
{
  AUTONAMES0("OnDoubleClick")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Chart::GetOnSheetActivate()
{
  AUTONAMES0("OnSheetActivate")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Chart::SetOnSheetActivate(TAutoVal& val)
{
  AUTONAMES0("OnSheetActivate")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Chart::GetOnSheetDeactivate()
{
  AUTONAMES0("OnSheetDeactivate")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Chart::SetOnSheetDeactivate(TAutoVal& val)
{
  AUTONAMES0("OnSheetDeactivate")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Chart::GetPageSetup()
{
  AUTONAMES0("PageSetup")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Chart::SetPageSetup(TAutoVal& val)
{
  AUTONAMES0("PageSetup")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Chart::GetParent()
{
  AUTONAMES0("Parent")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Chart::SetParent(TAutoVal& val)
{
  AUTONAMES0("Parent")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Chart::GetPerspective()
{
  AUTONAMES0("Perspective")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Chart::SetPerspective(TAutoVal& val)
{
  AUTONAMES0("Perspective")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Chart::GetPie3DGroup()
{
  AUTONAMES0("Pie3DGroup")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Chart::SetPie3DGroup(TAutoVal& val)
{
  AUTONAMES0("Pie3DGroup")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Chart::GetPlotArea()
{
  AUTONAMES0("PlotArea")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Chart::SetPlotArea(TAutoVal& val)
{
  AUTONAMES0("PlotArea")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Chart::GetPlotVisibleOnly()
{
  AUTONAMES0("PlotVisibleOnly")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Chart::SetPlotVisibleOnly(TAutoVal& val)
{
  AUTONAMES0("PlotVisibleOnly")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Chart::GetPrevious()
{
  AUTONAMES0("Previous")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Chart::SetPrevious(TAutoVal& val)
{
  AUTONAMES0("Previous")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Chart::GetProtectContents()
{
  AUTONAMES0("ProtectContents")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Chart::SetProtectContents(TAutoVal& val)
{
  AUTONAMES0("ProtectContents")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Chart::GetProtectDrawingObjects()
{
  AUTONAMES0("ProtectDrawingObjects")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Chart::SetProtectDrawingObjects(TAutoVal& val)
{
  AUTONAMES0("ProtectDrawingObjects")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Chart::GetProtectionMode()
{
  AUTONAMES0("ProtectionMode")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Chart::SetProtectionMode(TAutoVal& val)
{
  AUTONAMES0("ProtectionMode")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Chart::GetRightAngleAxes()
{
  AUTONAMES0("RightAngleAxes")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Chart::SetRightAngleAxes(TAutoVal& val)
{
  AUTONAMES0("RightAngleAxes")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Chart::GetRotation()
{
  AUTONAMES0("Rotation")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Chart::SetRotation(TAutoVal& val)
{
  AUTONAMES0("Rotation")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Chart::GetSizeWithWindow()
{
  AUTONAMES0("SizeWithWindow")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Chart::SetSizeWithWindow(TAutoVal& val)
{
  AUTONAMES0("SizeWithWindow")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Chart::GetSubType()
{
  AUTONAMES0("SubType")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Chart::SetSubType(TAutoVal& val)
{
  AUTONAMES0("SubType")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Chart::GetSurfaceGroup()
{
  AUTONAMES0("SurfaceGroup")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Chart::SetSurfaceGroup(TAutoVal& val)
{
  AUTONAMES0("SurfaceGroup")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Chart::GetType()
{
  AUTONAMES0("Type")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Chart::SetType(TAutoVal& val)
{
  AUTONAMES0("Type")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Chart::GetVisible()
{
  AUTONAMES0("Visible")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Chart::SetVisible(TAutoVal& val)
{
  AUTONAMES0("Visible")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Chart::GetWalls()
{
  AUTONAMES0("Walls")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Chart::SetWalls(TAutoVal& val)
{
  AUTONAMES0("Walls")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Chart::GetWallsAndGridlines2D()
{
  AUTONAMES0("WallsAndGridlines2D")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Chart::SetWallsAndGridlines2D(TAutoVal& val)
{
  AUTONAMES0("WallsAndGridlines2D")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Chart::Activate()
{
  AUTONAMES0("Activate")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Chart::Application()
{
  AUTONAMES0("Application")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Chart::ApplyDataLabels(TAutoVal& Type, TAutoVal& LegendKey)
{
  AUTONAMES0("ApplyDataLabels")
  AUTOARGS2(Type, LegendKey)
  AUTOCALL_METHOD_RET
}

TAutoVal Chart::Arcs(TAutoVal& Index)
{
  AUTONAMES0("Arcs")
  AUTOARGS1(Index)
  AUTOCALL_METHOD_RET
}

TAutoVal Chart::AreaGroups(TAutoVal& Index)
{
  AUTONAMES0("AreaGroups")
  AUTOARGS1(Index)
  AUTOCALL_METHOD_RET
}

TAutoVal Chart::AutoFormat(TAutoVal& Gallery, TAutoVal& Format)
{
  AUTONAMES0("AutoFormat")
  AUTOARGS2(Gallery, Format)
  AUTOCALL_METHOD_RET
}

TAutoVal Chart::Axes(TAutoVal& Type, TAutoVal& AxisGroup)
{
  AUTONAMES0("Axes")
  AUTOARGS2(Type, AxisGroup)
  AUTOCALL_METHOD_RET
}

TAutoVal Chart::BarGroups(TAutoVal& Index)
{
  AUTONAMES0("BarGroups")
  AUTOARGS1(Index)
  AUTOCALL_METHOD_RET
}

TAutoVal Chart::Buttons(TAutoVal& Index)
{
  AUTONAMES0("Buttons")
  AUTOARGS1(Index)
  AUTOCALL_METHOD_RET
}

TAutoVal Chart::ChartGroups(TAutoVal& Index)
{
  AUTONAMES0("ChartGroups")
  AUTOARGS1(Index)
  AUTOCALL_METHOD_RET
}

TAutoVal Chart::ChartObjects(TAutoVal& Index)
{
  AUTONAMES0("ChartObjects")
  AUTOARGS1(Index)
  AUTOCALL_METHOD_RET
}

TAutoVal Chart::ChartWizard(TAutoVal& Source, TAutoVal& Gallery, TAutoVal& Format, TAutoVal& PlotBy, TAutoVal& CategoryLabels, TAutoVal& SeriesLabels, TAutoVal& HasLegend, TAutoVal& Title, TAutoVal& CategoryTitle, TAutoVal& ValueTitle, TAutoVal& ExtraTitle)
{
  AUTONAMES0("ChartWizard")
  AUTOARGS11(Source, Gallery, Format, PlotBy, CategoryLabels, SeriesLabels, HasLegend, Title, CategoryTitle, ValueTitle, ExtraTitle)
  AUTOCALL_METHOD_RET
}

TAutoVal Chart::CheckBoxes(TAutoVal& Index)
{
  AUTONAMES0("CheckBoxes")
  AUTOARGS1(Index)
  AUTOCALL_METHOD_RET
}

TAutoVal Chart::CheckSpelling(TAutoVal& CustomDictionary, TAutoVal& IgnoreUppercase, TAutoVal& AlwaysSuggest)
{
  AUTONAMES0("CheckSpelling")
  AUTOARGS3(CustomDictionary, IgnoreUppercase, AlwaysSuggest)
  AUTOCALL_METHOD_RET
}

TAutoVal Chart::ColumnGroups(TAutoVal& Index)
{
  AUTONAMES0("ColumnGroups")
  AUTOARGS1(Index)
  AUTOCALL_METHOD_RET
}

TAutoVal Chart::Copy(TAutoVal& Before, TAutoVal& After)
{
  AUTONAMES0("Copy")
  AUTOARGS2(Before, After)
  AUTOCALL_METHOD_RET
}

TAutoVal Chart::CopyPicture(TAutoVal& Appearance, TAutoVal& Format, TAutoVal& Size)
{
  AUTONAMES0("CopyPicture")
  AUTOARGS3(Appearance, Format, Size)
  AUTOCALL_METHOD_RET
}

TAutoVal Chart::CreatePublisher(TAutoVal& Edition, TAutoVal& Appearance, TAutoVal& Size, TAutoVal& ContainsPICT, TAutoVal& ContainsBIFF, TAutoVal& ContainsRTF, TAutoVal& ContainsVALU)
{
  AUTONAMES0("CreatePublisher")
  AUTOARGS7(Edition, Appearance, Size, ContainsPICT, ContainsBIFF, ContainsRTF, ContainsVALU)
  AUTOCALL_METHOD_RET
}

TAutoVal Chart::Delete()
{
  AUTONAMES0("Delete")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Chart::Deselect()
{
  AUTONAMES0("Deselect")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Chart::DoughnutGroups(TAutoVal& Index)
{
  AUTONAMES0("DoughnutGroups")
  AUTOARGS1(Index)
  AUTOCALL_METHOD_RET
}

TAutoVal Chart::DrawingObjects(TAutoVal& Index)
{
  AUTONAMES0("DrawingObjects")
  AUTOARGS1(Index)
  AUTOCALL_METHOD_RET
}

TAutoVal Chart::Drawings(TAutoVal& Index)
{
  AUTONAMES0("Drawings")
  AUTOARGS1(Index)
  AUTOCALL_METHOD_RET
}

TAutoVal Chart::DropDowns(TAutoVal& Index)
{
  AUTONAMES0("DropDowns")
  AUTOARGS1(Index)
  AUTOCALL_METHOD_RET
}

TAutoVal Chart::_Evaluate(TAutoVal& Name)
{
  AUTONAMES0("_Evaluate")
  AUTOARGS1(Name)
  AUTOCALL_METHOD_RET
}

TAutoVal Chart::Evaluate(TAutoVal& Name)
{
  AUTONAMES0("Evaluate")
  AUTOARGS1(Name)
  AUTOCALL_METHOD_RET
}

TAutoVal Chart::GroupBoxes(TAutoVal& Index)
{
  AUTONAMES0("GroupBoxes")
  AUTOARGS1(Index)
  AUTOCALL_METHOD_RET
}

TAutoVal Chart::GroupObjects(TAutoVal& Index)
{
  AUTONAMES0("GroupObjects")
  AUTOARGS1(Index)
  AUTOCALL_METHOD_RET
}

TAutoVal Chart::Labels(TAutoVal& Index)
{
  AUTONAMES0("Labels")
  AUTOARGS1(Index)
  AUTOCALL_METHOD_RET
}

TAutoVal Chart::LineGroups(TAutoVal& Index)
{
  AUTONAMES0("LineGroups")
  AUTOARGS1(Index)
  AUTOCALL_METHOD_RET
}

TAutoVal Chart::Lines(TAutoVal& Index)
{
  AUTONAMES0("Lines")
  AUTOARGS1(Index)
  AUTOCALL_METHOD_RET
}

TAutoVal Chart::ListBoxes(TAutoVal& Index)
{
  AUTONAMES0("ListBoxes")
  AUTOARGS1(Index)
  AUTOCALL_METHOD_RET
}

TAutoVal Chart::Move(TAutoVal& Before, TAutoVal& After)
{
  AUTONAMES0("Move")
  AUTOARGS2(Before, After)
  AUTOCALL_METHOD_RET
}

TAutoVal Chart::OLEObjects(TAutoVal& Index)
{
  AUTONAMES0("OLEObjects")
  AUTOARGS1(Index)
  AUTOCALL_METHOD_RET
}

TAutoVal Chart::OptionButtons(TAutoVal& Index)
{
  AUTONAMES0("OptionButtons")
  AUTOARGS1(Index)
  AUTOCALL_METHOD_RET
}

TAutoVal Chart::Ovals(TAutoVal& Index)
{
  AUTONAMES0("Ovals")
  AUTOARGS1(Index)
  AUTOCALL_METHOD_RET
}

TAutoVal Chart::Paste(TAutoVal& Type)
{
  AUTONAMES0("Paste")
  AUTOARGS1(Type)
  AUTOCALL_METHOD_RET
}

TAutoVal Chart::Pictures(TAutoVal& Index)
{
  AUTONAMES0("Pictures")
  AUTOARGS1(Index)
  AUTOCALL_METHOD_RET
}

TAutoVal Chart::PieGroups(TAutoVal& Index)
{
  AUTONAMES0("PieGroups")
  AUTOARGS1(Index)
  AUTOCALL_METHOD_RET
}

TAutoVal Chart::PrintOut(TAutoVal& From, TAutoVal& To, TAutoVal& Copies, TAutoVal& Preview, TAutoVal& ActivePrinter, TAutoVal& PrintToFile, TAutoVal& Collate)
{
  AUTONAMES0("PrintOut")
  AUTOARGS7(From, To, Copies, Preview, ActivePrinter, PrintToFile, Collate)
  AUTOCALL_METHOD_RET
}

TAutoVal Chart::PrintPreview()
{
  AUTONAMES0("PrintPreview")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Chart::Protect(TAutoVal& Password, TAutoVal& DrawingObjects, TAutoVal& Contents, TAutoVal& Scenarios, TAutoVal& UserInterfaceOnly)
{
  AUTONAMES0("Protect")
  AUTOARGS5(Password, DrawingObjects, Contents, Scenarios, UserInterfaceOnly)
  AUTOCALL_METHOD_RET
}

TAutoVal Chart::RadarGroups(TAutoVal& Index)
{
  AUTONAMES0("RadarGroups")
  AUTOARGS1(Index)
  AUTOCALL_METHOD_RET
}

TAutoVal Chart::Rectangles(TAutoVal& Index)
{
  AUTONAMES0("Rectangles")
  AUTOARGS1(Index)
  AUTOCALL_METHOD_RET
}

TAutoVal Chart::SaveAs(TAutoVal& Filename, TAutoVal& FileFormat, TAutoVal& Password, TAutoVal& WriteResPassword, TAutoVal& ReadOnlyRecommended, TAutoVal& CreateBackup)
{
  AUTONAMES0("SaveAs")
  AUTOARGS6(Filename, FileFormat, Password, WriteResPassword, ReadOnlyRecommended, CreateBackup)
  AUTOCALL_METHOD_RET
}

TAutoVal Chart::ScrollBars(TAutoVal& Index)
{
  AUTONAMES0("ScrollBars")
  AUTOARGS1(Index)
  AUTOCALL_METHOD_RET
}

TAutoVal Chart::Select(TAutoVal& Replace)
{
  AUTONAMES0("Select")
  AUTOARGS1(Replace)
  AUTOCALL_METHOD_RET
}

TAutoVal Chart::SeriesCollection(TAutoVal& Index)
{
  AUTONAMES0("SeriesCollection")
  AUTOARGS1(Index)
  AUTOCALL_METHOD_RET
}

TAutoVal Chart::SetBackgroundPicture(TAutoVal& Filename)
{
  AUTONAMES0("SetBackgroundPicture")
  AUTOARGS1(Filename)
  AUTOCALL_METHOD_RET
}

TAutoVal Chart::Spinners(TAutoVal& Index)
{
  AUTONAMES0("Spinners")
  AUTOARGS1(Index)
  AUTOCALL_METHOD_RET
}

TAutoVal Chart::TextBoxes(TAutoVal& Index)
{
  AUTONAMES0("TextBoxes")
  AUTOARGS1(Index)
  AUTOCALL_METHOD_RET
}

TAutoVal Chart::Unprotect(TAutoVal& Password)
{
  AUTONAMES0("Unprotect")
  AUTOARGS1(Password)
  AUTOCALL_METHOD_RET
}

TAutoVal Chart::XYGroups(TAutoVal& Index)
{
  AUTONAMES0("XYGroups")
  AUTOARGS1(Index)
  AUTOCALL_METHOD_RET
}


// TKIND_DISPATCH: Charts {0002086D-0000-0000-C000-000000000046}\9

TAutoVal Charts::GetCount()
{
  AUTONAMES0("Count")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Charts::SetCount(TAutoVal& val)
{
  AUTONAMES0("Count")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Charts::GetCreator()
{
  AUTONAMES0("Creator")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Charts::SetCreator(TAutoVal& val)
{
  AUTONAMES0("Creator")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Charts::GetParent()
{
  AUTONAMES0("Parent")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Charts::SetParent(TAutoVal& val)
{
  AUTONAMES0("Parent")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Charts::GetVisible()
{
  AUTONAMES0("Visible")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Charts::SetVisible(TAutoVal& val)
{
  AUTONAMES0("Visible")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Charts::_NewEnum()
{
  AUTONAMES0("_NewEnum")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Charts::Add(TAutoVal& Before, TAutoVal& After, TAutoVal& Count)
{
  AUTONAMES0("Add")
  AUTOARGS3(Before, After, Count)
  AUTOCALL_METHOD_RET
}

TAutoVal Charts::Application()
{
  AUTONAMES0("Application")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Charts::Copy(TAutoVal& Before, TAutoVal& After)
{
  AUTONAMES0("Copy")
  AUTOARGS2(Before, After)
  AUTOCALL_METHOD_RET
}

TAutoVal Charts::Delete()
{
  AUTONAMES0("Delete")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Charts::Item(TAutoVal& Index)
{
  AUTONAMES0("Item")
  AUTOARGS1(Index)
  AUTOCALL_METHOD_RET
}

TAutoVal Charts::Move(TAutoVal& Before, TAutoVal& After)
{
  AUTONAMES0("Move")
  AUTOARGS2(Before, After)
  AUTOCALL_METHOD_RET
}

TAutoVal Charts::PrintOut(TAutoVal& From, TAutoVal& To, TAutoVal& Copies, TAutoVal& Preview, TAutoVal& ActivePrinter, TAutoVal& PrintToFile, TAutoVal& Collate)
{
  AUTONAMES0("PrintOut")
  AUTOARGS7(From, To, Copies, Preview, ActivePrinter, PrintToFile, Collate)
  AUTOCALL_METHOD_RET
}

TAutoVal Charts::PrintPreview()
{
  AUTONAMES0("PrintPreview")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Charts::Select(TAutoVal& Replace)
{
  AUTONAMES0("Select")
  AUTOARGS1(Replace)
  AUTOCALL_METHOD_RET
}


// TKIND_DISPATCH: ChartGroup {00020859-0000-0000-C000-000000000046}\9

TAutoVal ChartGroup::GetAxisGroup()
{
  AUTONAMES0("AxisGroup")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void ChartGroup::SetAxisGroup(TAutoVal& val)
{
  AUTONAMES0("AxisGroup")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal ChartGroup::GetCreator()
{
  AUTONAMES0("Creator")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void ChartGroup::SetCreator(TAutoVal& val)
{
  AUTONAMES0("Creator")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal ChartGroup::GetDoughnutHoleSize()
{
  AUTONAMES0("DoughnutHoleSize")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void ChartGroup::SetDoughnutHoleSize(TAutoVal& val)
{
  AUTONAMES0("DoughnutHoleSize")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal ChartGroup::GetDownBars()
{
  AUTONAMES0("DownBars")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void ChartGroup::SetDownBars(TAutoVal& val)
{
  AUTONAMES0("DownBars")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal ChartGroup::GetDropLines()
{
  AUTONAMES0("DropLines")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void ChartGroup::SetDropLines(TAutoVal& val)
{
  AUTONAMES0("DropLines")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal ChartGroup::GetFirstSliceAngle()
{
  AUTONAMES0("FirstSliceAngle")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void ChartGroup::SetFirstSliceAngle(TAutoVal& val)
{
  AUTONAMES0("FirstSliceAngle")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal ChartGroup::GetGapWidth()
{
  AUTONAMES0("GapWidth")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void ChartGroup::SetGapWidth(TAutoVal& val)
{
  AUTONAMES0("GapWidth")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal ChartGroup::GetHasDropLines()
{
  AUTONAMES0("HasDropLines")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void ChartGroup::SetHasDropLines(TAutoVal& val)
{
  AUTONAMES0("HasDropLines")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal ChartGroup::GetHasHiLoLines()
{
  AUTONAMES0("HasHiLoLines")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void ChartGroup::SetHasHiLoLines(TAutoVal& val)
{
  AUTONAMES0("HasHiLoLines")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal ChartGroup::GetHasRadarAxisLabels()
{
  AUTONAMES0("HasRadarAxisLabels")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void ChartGroup::SetHasRadarAxisLabels(TAutoVal& val)
{
  AUTONAMES0("HasRadarAxisLabels")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal ChartGroup::GetHasSeriesLines()
{
  AUTONAMES0("HasSeriesLines")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void ChartGroup::SetHasSeriesLines(TAutoVal& val)
{
  AUTONAMES0("HasSeriesLines")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal ChartGroup::GetHasUpDownBars()
{
  AUTONAMES0("HasUpDownBars")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void ChartGroup::SetHasUpDownBars(TAutoVal& val)
{
  AUTONAMES0("HasUpDownBars")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal ChartGroup::GetHiLoLines()
{
  AUTONAMES0("HiLoLines")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void ChartGroup::SetHiLoLines(TAutoVal& val)
{
  AUTONAMES0("HiLoLines")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal ChartGroup::GetOverlap()
{
  AUTONAMES0("Overlap")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void ChartGroup::SetOverlap(TAutoVal& val)
{
  AUTONAMES0("Overlap")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal ChartGroup::GetParent()
{
  AUTONAMES0("Parent")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void ChartGroup::SetParent(TAutoVal& val)
{
  AUTONAMES0("Parent")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal ChartGroup::GetRadarAxisLabels()
{
  AUTONAMES0("RadarAxisLabels")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void ChartGroup::SetRadarAxisLabels(TAutoVal& val)
{
  AUTONAMES0("RadarAxisLabels")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal ChartGroup::GetSeriesLines()
{
  AUTONAMES0("SeriesLines")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void ChartGroup::SetSeriesLines(TAutoVal& val)
{
  AUTONAMES0("SeriesLines")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal ChartGroup::GetSubType()
{
  AUTONAMES0("SubType")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void ChartGroup::SetSubType(TAutoVal& val)
{
  AUTONAMES0("SubType")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal ChartGroup::GetType()
{
  AUTONAMES0("Type")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void ChartGroup::SetType(TAutoVal& val)
{
  AUTONAMES0("Type")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal ChartGroup::GetUpBars()
{
  AUTONAMES0("UpBars")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void ChartGroup::SetUpBars(TAutoVal& val)
{
  AUTONAMES0("UpBars")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal ChartGroup::GetVaryByCategories()
{
  AUTONAMES0("VaryByCategories")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void ChartGroup::SetVaryByCategories(TAutoVal& val)
{
  AUTONAMES0("VaryByCategories")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal ChartGroup::Application()
{
  AUTONAMES0("Application")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal ChartGroup::SeriesCollection(TAutoVal& Index)
{
  AUTONAMES0("SeriesCollection")
  AUTOARGS1(Index)
  AUTOCALL_METHOD_RET
}


// TKIND_DISPATCH: ChartGroups {0002085A-0000-0000-C000-000000000046}\9

TAutoVal ChartGroups::GetCount()
{
  AUTONAMES0("Count")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void ChartGroups::SetCount(TAutoVal& val)
{
  AUTONAMES0("Count")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal ChartGroups::GetCreator()
{
  AUTONAMES0("Creator")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void ChartGroups::SetCreator(TAutoVal& val)
{
  AUTONAMES0("Creator")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal ChartGroups::GetParent()
{
  AUTONAMES0("Parent")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void ChartGroups::SetParent(TAutoVal& val)
{
  AUTONAMES0("Parent")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal ChartGroups::_NewEnum()
{
  AUTONAMES0("_NewEnum")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal ChartGroups::Application()
{
  AUTONAMES0("Application")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal ChartGroups::Item(TAutoVal& Index)
{
  AUTONAMES0("Item")
  AUTOARGS1(Index)
  AUTOCALL_METHOD_RET
}


// TKIND_DISPATCH: Axis {00020848-0000-0000-C000-000000000046}\9

TAutoVal Axis::GetAxisBetweenCategories()
{
  AUTONAMES0("AxisBetweenCategories")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Axis::SetAxisBetweenCategories(TAutoVal& val)
{
  AUTONAMES0("AxisBetweenCategories")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Axis::GetAxisGroup()
{
  AUTONAMES0("AxisGroup")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Axis::SetAxisGroup(TAutoVal& val)
{
  AUTONAMES0("AxisGroup")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Axis::GetAxisTitle()
{
  AUTONAMES0("AxisTitle")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Axis::SetAxisTitle(TAutoVal& val)
{
  AUTONAMES0("AxisTitle")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Axis::GetBorder()
{
  AUTONAMES0("Border")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Axis::SetBorder(TAutoVal& val)
{
  AUTONAMES0("Border")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Axis::GetCategoryNames()
{
  AUTONAMES0("CategoryNames")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Axis::SetCategoryNames(TAutoVal& val)
{
  AUTONAMES0("CategoryNames")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Axis::GetCreator()
{
  AUTONAMES0("Creator")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Axis::SetCreator(TAutoVal& val)
{
  AUTONAMES0("Creator")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Axis::GetCrosses()
{
  AUTONAMES0("Crosses")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Axis::SetCrosses(TAutoVal& val)
{
  AUTONAMES0("Crosses")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Axis::GetCrossesAt()
{
  AUTONAMES0("CrossesAt")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Axis::SetCrossesAt(TAutoVal& val)
{
  AUTONAMES0("CrossesAt")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Axis::GetHasMajorGridlines()
{
  AUTONAMES0("HasMajorGridlines")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Axis::SetHasMajorGridlines(TAutoVal& val)
{
  AUTONAMES0("HasMajorGridlines")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Axis::GetHasMinorGridlines()
{
  AUTONAMES0("HasMinorGridlines")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Axis::SetHasMinorGridlines(TAutoVal& val)
{
  AUTONAMES0("HasMinorGridlines")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Axis::GetHasTitle()
{
  AUTONAMES0("HasTitle")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Axis::SetHasTitle(TAutoVal& val)
{
  AUTONAMES0("HasTitle")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Axis::GetMajorGridlines()
{
  AUTONAMES0("MajorGridlines")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Axis::SetMajorGridlines(TAutoVal& val)
{
  AUTONAMES0("MajorGridlines")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Axis::GetMajorTickMark()
{
  AUTONAMES0("MajorTickMark")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Axis::SetMajorTickMark(TAutoVal& val)
{
  AUTONAMES0("MajorTickMark")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Axis::GetMajorUnit()
{
  AUTONAMES0("MajorUnit")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Axis::SetMajorUnit(TAutoVal& val)
{
  AUTONAMES0("MajorUnit")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Axis::GetMajorUnitIsAuto()
{
  AUTONAMES0("MajorUnitIsAuto")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Axis::SetMajorUnitIsAuto(TAutoVal& val)
{
  AUTONAMES0("MajorUnitIsAuto")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Axis::GetMaximumScale()
{
  AUTONAMES0("MaximumScale")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Axis::SetMaximumScale(TAutoVal& val)
{
  AUTONAMES0("MaximumScale")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Axis::GetMaximumScaleIsAuto()
{
  AUTONAMES0("MaximumScaleIsAuto")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Axis::SetMaximumScaleIsAuto(TAutoVal& val)
{
  AUTONAMES0("MaximumScaleIsAuto")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Axis::GetMinimumScale()
{
  AUTONAMES0("MinimumScale")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Axis::SetMinimumScale(TAutoVal& val)
{
  AUTONAMES0("MinimumScale")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Axis::GetMinimumScaleIsAuto()
{
  AUTONAMES0("MinimumScaleIsAuto")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Axis::SetMinimumScaleIsAuto(TAutoVal& val)
{
  AUTONAMES0("MinimumScaleIsAuto")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Axis::GetMinorGridlines()
{
  AUTONAMES0("MinorGridlines")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Axis::SetMinorGridlines(TAutoVal& val)
{
  AUTONAMES0("MinorGridlines")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Axis::GetMinorTickMark()
{
  AUTONAMES0("MinorTickMark")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Axis::SetMinorTickMark(TAutoVal& val)
{
  AUTONAMES0("MinorTickMark")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Axis::GetMinorUnit()
{
  AUTONAMES0("MinorUnit")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Axis::SetMinorUnit(TAutoVal& val)
{
  AUTONAMES0("MinorUnit")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Axis::GetMinorUnitIsAuto()
{
  AUTONAMES0("MinorUnitIsAuto")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Axis::SetMinorUnitIsAuto(TAutoVal& val)
{
  AUTONAMES0("MinorUnitIsAuto")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Axis::GetParent()
{
  AUTONAMES0("Parent")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Axis::SetParent(TAutoVal& val)
{
  AUTONAMES0("Parent")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Axis::GetReversePlotOrder()
{
  AUTONAMES0("ReversePlotOrder")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Axis::SetReversePlotOrder(TAutoVal& val)
{
  AUTONAMES0("ReversePlotOrder")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Axis::GetScaleType()
{
  AUTONAMES0("ScaleType")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Axis::SetScaleType(TAutoVal& val)
{
  AUTONAMES0("ScaleType")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Axis::GetTickLabelPosition()
{
  AUTONAMES0("TickLabelPosition")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Axis::SetTickLabelPosition(TAutoVal& val)
{
  AUTONAMES0("TickLabelPosition")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Axis::GetTickLabels()
{
  AUTONAMES0("TickLabels")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Axis::SetTickLabels(TAutoVal& val)
{
  AUTONAMES0("TickLabels")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Axis::GetTickLabelSpacing()
{
  AUTONAMES0("TickLabelSpacing")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Axis::SetTickLabelSpacing(TAutoVal& val)
{
  AUTONAMES0("TickLabelSpacing")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Axis::GetTickMarkSpacing()
{
  AUTONAMES0("TickMarkSpacing")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Axis::SetTickMarkSpacing(TAutoVal& val)
{
  AUTONAMES0("TickMarkSpacing")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Axis::GetType()
{
  AUTONAMES0("Type")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Axis::SetType(TAutoVal& val)
{
  AUTONAMES0("Type")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Axis::Application()
{
  AUTONAMES0("Application")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Axis::Delete()
{
  AUTONAMES0("Delete")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Axis::Select()
{
  AUTONAMES0("Select")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}


// TKIND_DISPATCH: Axes {0002085B-0000-0000-C000-000000000046}\9

TAutoVal Axes::GetCount()
{
  AUTONAMES0("Count")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Axes::SetCount(TAutoVal& val)
{
  AUTONAMES0("Count")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Axes::GetCreator()
{
  AUTONAMES0("Creator")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Axes::SetCreator(TAutoVal& val)
{
  AUTONAMES0("Creator")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Axes::GetParent()
{
  AUTONAMES0("Parent")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Axes::SetParent(TAutoVal& val)
{
  AUTONAMES0("Parent")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Axes::_NewEnum()
{
  AUTONAMES0("_NewEnum")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Axes::Application()
{
  AUTONAMES0("Application")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Axes::Item(TAutoVal& Type, TAutoVal& AxisGroup)
{
  AUTONAMES0("Item")
  AUTOARGS2(Type, AxisGroup)
  AUTOCALL_METHOD_RET
}


// TKIND_DISPATCH: DataLabel {000208B2-0000-0000-C000-000000000046}\9

TAutoVal DataLabel::GetAutoText()
{
  AUTONAMES0("AutoText")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void DataLabel::SetAutoText(TAutoVal& val)
{
  AUTONAMES0("AutoText")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal DataLabel::GetBorder()
{
  AUTONAMES0("Border")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void DataLabel::SetBorder(TAutoVal& val)
{
  AUTONAMES0("Border")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal DataLabel::GetCaption()
{
  AUTONAMES0("Caption")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void DataLabel::SetCaption(TAutoVal& val)
{
  AUTONAMES0("Caption")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal DataLabel::GetCreator()
{
  AUTONAMES0("Creator")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void DataLabel::SetCreator(TAutoVal& val)
{
  AUTONAMES0("Creator")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal DataLabel::GetFont()
{
  AUTONAMES0("Font")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void DataLabel::SetFont(TAutoVal& val)
{
  AUTONAMES0("Font")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal DataLabel::GetHorizontalAlignment()
{
  AUTONAMES0("HorizontalAlignment")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void DataLabel::SetHorizontalAlignment(TAutoVal& val)
{
  AUTONAMES0("HorizontalAlignment")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal DataLabel::GetInterior()
{
  AUTONAMES0("Interior")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void DataLabel::SetInterior(TAutoVal& val)
{
  AUTONAMES0("Interior")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal DataLabel::GetLeft()
{
  AUTONAMES0("Left")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void DataLabel::SetLeft(TAutoVal& val)
{
  AUTONAMES0("Left")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal DataLabel::GetName()
{
  AUTONAMES0("Name")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void DataLabel::SetName(TAutoVal& val)
{
  AUTONAMES0("Name")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal DataLabel::GetNumberFormat()
{
  AUTONAMES0("NumberFormat")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void DataLabel::SetNumberFormat(TAutoVal& val)
{
  AUTONAMES0("NumberFormat")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal DataLabel::GetNumberFormatLinked()
{
  AUTONAMES0("NumberFormatLinked")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void DataLabel::SetNumberFormatLinked(TAutoVal& val)
{
  AUTONAMES0("NumberFormatLinked")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal DataLabel::GetOrientation()
{
  AUTONAMES0("Orientation")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void DataLabel::SetOrientation(TAutoVal& val)
{
  AUTONAMES0("Orientation")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal DataLabel::GetParent()
{
  AUTONAMES0("Parent")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void DataLabel::SetParent(TAutoVal& val)
{
  AUTONAMES0("Parent")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal DataLabel::GetShadow()
{
  AUTONAMES0("Shadow")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void DataLabel::SetShadow(TAutoVal& val)
{
  AUTONAMES0("Shadow")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal DataLabel::GetShowLegendKey()
{
  AUTONAMES0("ShowLegendKey")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void DataLabel::SetShowLegendKey(TAutoVal& val)
{
  AUTONAMES0("ShowLegendKey")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal DataLabel::GetText()
{
  AUTONAMES0("Text")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void DataLabel::SetText(TAutoVal& val)
{
  AUTONAMES0("Text")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal DataLabel::GetTop()
{
  AUTONAMES0("Top")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void DataLabel::SetTop(TAutoVal& val)
{
  AUTONAMES0("Top")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal DataLabel::GetType()
{
  AUTONAMES0("Type")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void DataLabel::SetType(TAutoVal& val)
{
  AUTONAMES0("Type")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal DataLabel::GetVerticalAlignment()
{
  AUTONAMES0("VerticalAlignment")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void DataLabel::SetVerticalAlignment(TAutoVal& val)
{
  AUTONAMES0("VerticalAlignment")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal DataLabel::Application()
{
  AUTONAMES0("Application")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal DataLabel::Characters(TAutoVal& Start, TAutoVal& Length)
{
  AUTONAMES0("Characters")
  AUTOARGS2(Start, Length)
  AUTOCALL_METHOD_RET
}

TAutoVal DataLabel::Delete()
{
  AUTONAMES0("Delete")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal DataLabel::Select()
{
  AUTONAMES0("Select")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}


// TKIND_DISPATCH: DataLabels {000208B3-0000-0000-C000-000000000046}\9

TAutoVal DataLabels::GetAutoText()
{
  AUTONAMES0("AutoText")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void DataLabels::SetAutoText(TAutoVal& val)
{
  AUTONAMES0("AutoText")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal DataLabels::GetBorder()
{
  AUTONAMES0("Border")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void DataLabels::SetBorder(TAutoVal& val)
{
  AUTONAMES0("Border")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal DataLabels::GetCount()
{
  AUTONAMES0("Count")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void DataLabels::SetCount(TAutoVal& val)
{
  AUTONAMES0("Count")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal DataLabels::GetCreator()
{
  AUTONAMES0("Creator")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void DataLabels::SetCreator(TAutoVal& val)
{
  AUTONAMES0("Creator")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal DataLabels::GetFont()
{
  AUTONAMES0("Font")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void DataLabels::SetFont(TAutoVal& val)
{
  AUTONAMES0("Font")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal DataLabels::GetHorizontalAlignment()
{
  AUTONAMES0("HorizontalAlignment")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void DataLabels::SetHorizontalAlignment(TAutoVal& val)
{
  AUTONAMES0("HorizontalAlignment")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal DataLabels::GetInterior()
{
  AUTONAMES0("Interior")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void DataLabels::SetInterior(TAutoVal& val)
{
  AUTONAMES0("Interior")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal DataLabels::GetName()
{
  AUTONAMES0("Name")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void DataLabels::SetName(TAutoVal& val)
{
  AUTONAMES0("Name")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal DataLabels::GetNumberFormat()
{
  AUTONAMES0("NumberFormat")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void DataLabels::SetNumberFormat(TAutoVal& val)
{
  AUTONAMES0("NumberFormat")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal DataLabels::GetNumberFormatLinked()
{
  AUTONAMES0("NumberFormatLinked")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void DataLabels::SetNumberFormatLinked(TAutoVal& val)
{
  AUTONAMES0("NumberFormatLinked")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal DataLabels::GetOrientation()
{
  AUTONAMES0("Orientation")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void DataLabels::SetOrientation(TAutoVal& val)
{
  AUTONAMES0("Orientation")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal DataLabels::GetParent()
{
  AUTONAMES0("Parent")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void DataLabels::SetParent(TAutoVal& val)
{
  AUTONAMES0("Parent")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal DataLabels::GetShadow()
{
  AUTONAMES0("Shadow")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void DataLabels::SetShadow(TAutoVal& val)
{
  AUTONAMES0("Shadow")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal DataLabels::GetShowLegendKey()
{
  AUTONAMES0("ShowLegendKey")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void DataLabels::SetShowLegendKey(TAutoVal& val)
{
  AUTONAMES0("ShowLegendKey")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal DataLabels::GetType()
{
  AUTONAMES0("Type")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void DataLabels::SetType(TAutoVal& val)
{
  AUTONAMES0("Type")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal DataLabels::GetVerticalAlignment()
{
  AUTONAMES0("VerticalAlignment")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void DataLabels::SetVerticalAlignment(TAutoVal& val)
{
  AUTONAMES0("VerticalAlignment")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal DataLabels::_NewEnum()
{
  AUTONAMES0("_NewEnum")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal DataLabels::Application()
{
  AUTONAMES0("Application")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal DataLabels::Delete()
{
  AUTONAMES0("Delete")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal DataLabels::Item(TAutoVal& Index)
{
  AUTONAMES0("Item")
  AUTOARGS1(Index)
  AUTOCALL_METHOD_RET
}

TAutoVal DataLabels::Select()
{
  AUTONAMES0("Select")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}


// TKIND_DISPATCH: Point {0002086A-0000-0000-C000-000000000046}\9

TAutoVal Point::GetBorder()
{
  AUTONAMES0("Border")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Point::SetBorder(TAutoVal& val)
{
  AUTONAMES0("Border")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Point::GetCreator()
{
  AUTONAMES0("Creator")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Point::SetCreator(TAutoVal& val)
{
  AUTONAMES0("Creator")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Point::GetDataLabel()
{
  AUTONAMES0("DataLabel")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Point::SetDataLabel(TAutoVal& val)
{
  AUTONAMES0("DataLabel")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Point::GetExplosion()
{
  AUTONAMES0("Explosion")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Point::SetExplosion(TAutoVal& val)
{
  AUTONAMES0("Explosion")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Point::GetHasDataLabel()
{
  AUTONAMES0("HasDataLabel")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Point::SetHasDataLabel(TAutoVal& val)
{
  AUTONAMES0("HasDataLabel")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Point::GetInterior()
{
  AUTONAMES0("Interior")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Point::SetInterior(TAutoVal& val)
{
  AUTONAMES0("Interior")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Point::GetInvertIfNegative()
{
  AUTONAMES0("InvertIfNegative")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Point::SetInvertIfNegative(TAutoVal& val)
{
  AUTONAMES0("InvertIfNegative")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Point::GetMarkerBackgroundColor()
{
  AUTONAMES0("MarkerBackgroundColor")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Point::SetMarkerBackgroundColor(TAutoVal& val)
{
  AUTONAMES0("MarkerBackgroundColor")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Point::GetMarkerBackgroundColorIndex()
{
  AUTONAMES0("MarkerBackgroundColorIndex")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Point::SetMarkerBackgroundColorIndex(TAutoVal& val)
{
  AUTONAMES0("MarkerBackgroundColorIndex")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Point::GetMarkerForegroundColor()
{
  AUTONAMES0("MarkerForegroundColor")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Point::SetMarkerForegroundColor(TAutoVal& val)
{
  AUTONAMES0("MarkerForegroundColor")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Point::GetMarkerForegroundColorIndex()
{
  AUTONAMES0("MarkerForegroundColorIndex")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Point::SetMarkerForegroundColorIndex(TAutoVal& val)
{
  AUTONAMES0("MarkerForegroundColorIndex")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Point::GetMarkerStyle()
{
  AUTONAMES0("MarkerStyle")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Point::SetMarkerStyle(TAutoVal& val)
{
  AUTONAMES0("MarkerStyle")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Point::GetParent()
{
  AUTONAMES0("Parent")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Point::SetParent(TAutoVal& val)
{
  AUTONAMES0("Parent")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Point::GetPictureType()
{
  AUTONAMES0("PictureType")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Point::SetPictureType(TAutoVal& val)
{
  AUTONAMES0("PictureType")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Point::GetPictureUnit()
{
  AUTONAMES0("PictureUnit")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Point::SetPictureUnit(TAutoVal& val)
{
  AUTONAMES0("PictureUnit")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Point::Application()
{
  AUTONAMES0("Application")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Point::ApplyDataLabels(TAutoVal& Type, TAutoVal& LegendKey)
{
  AUTONAMES0("ApplyDataLabels")
  AUTOARGS2(Type, LegendKey)
  AUTOCALL_METHOD_RET
}

TAutoVal Point::ClearFormats()
{
  AUTONAMES0("ClearFormats")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Point::Copy()
{
  AUTONAMES0("Copy")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Point::Delete()
{
  AUTONAMES0("Delete")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Point::Paste()
{
  AUTONAMES0("Paste")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Point::Select()
{
  AUTONAMES0("Select")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}


// TKIND_DISPATCH: Points {00020869-0000-0000-C000-000000000046}\9

TAutoVal Points::GetCount()
{
  AUTONAMES0("Count")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Points::SetCount(TAutoVal& val)
{
  AUTONAMES0("Count")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Points::GetCreator()
{
  AUTONAMES0("Creator")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Points::SetCreator(TAutoVal& val)
{
  AUTONAMES0("Creator")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Points::GetParent()
{
  AUTONAMES0("Parent")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Points::SetParent(TAutoVal& val)
{
  AUTONAMES0("Parent")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Points::_NewEnum()
{
  AUTONAMES0("_NewEnum")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Points::Application()
{
  AUTONAMES0("Application")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Points::Item(TAutoVal& Index)
{
  AUTONAMES0("Item")
  AUTOARGS1(Index)
  AUTOCALL_METHOD_RET
}


// TKIND_DISPATCH: Series {0002086B-0000-0000-C000-000000000046}\9

TAutoVal Series::GetAxisGroup()
{
  AUTONAMES0("AxisGroup")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Series::SetAxisGroup(TAutoVal& val)
{
  AUTONAMES0("AxisGroup")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Series::GetBorder()
{
  AUTONAMES0("Border")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Series::SetBorder(TAutoVal& val)
{
  AUTONAMES0("Border")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Series::GetCreator()
{
  AUTONAMES0("Creator")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Series::SetCreator(TAutoVal& val)
{
  AUTONAMES0("Creator")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Series::GetErrorBars()
{
  AUTONAMES0("ErrorBars")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Series::SetErrorBars(TAutoVal& val)
{
  AUTONAMES0("ErrorBars")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Series::GetExplosion()
{
  AUTONAMES0("Explosion")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Series::SetExplosion(TAutoVal& val)
{
  AUTONAMES0("Explosion")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Series::GetFormula()
{
  AUTONAMES0("Formula")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Series::SetFormula(TAutoVal& val)
{
  AUTONAMES0("Formula")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Series::GetFormulaLocal()
{
  AUTONAMES0("FormulaLocal")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Series::SetFormulaLocal(TAutoVal& val)
{
  AUTONAMES0("FormulaLocal")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Series::GetFormulaR1C1()
{
  AUTONAMES0("FormulaR1C1")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Series::SetFormulaR1C1(TAutoVal& val)
{
  AUTONAMES0("FormulaR1C1")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Series::GetFormulaR1C1Local()
{
  AUTONAMES0("FormulaR1C1Local")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Series::SetFormulaR1C1Local(TAutoVal& val)
{
  AUTONAMES0("FormulaR1C1Local")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Series::GetHasDataLabels()
{
  AUTONAMES0("HasDataLabels")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Series::SetHasDataLabels(TAutoVal& val)
{
  AUTONAMES0("HasDataLabels")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Series::GetHasErrorBars()
{
  AUTONAMES0("HasErrorBars")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Series::SetHasErrorBars(TAutoVal& val)
{
  AUTONAMES0("HasErrorBars")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Series::GetInterior()
{
  AUTONAMES0("Interior")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Series::SetInterior(TAutoVal& val)
{
  AUTONAMES0("Interior")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Series::GetInvertIfNegative()
{
  AUTONAMES0("InvertIfNegative")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Series::SetInvertIfNegative(TAutoVal& val)
{
  AUTONAMES0("InvertIfNegative")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Series::GetMarkerBackgroundColor()
{
  AUTONAMES0("MarkerBackgroundColor")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Series::SetMarkerBackgroundColor(TAutoVal& val)
{
  AUTONAMES0("MarkerBackgroundColor")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Series::GetMarkerBackgroundColorIndex()
{
  AUTONAMES0("MarkerBackgroundColorIndex")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Series::SetMarkerBackgroundColorIndex(TAutoVal& val)
{
  AUTONAMES0("MarkerBackgroundColorIndex")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Series::GetMarkerForegroundColor()
{
  AUTONAMES0("MarkerForegroundColor")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Series::SetMarkerForegroundColor(TAutoVal& val)
{
  AUTONAMES0("MarkerForegroundColor")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Series::GetMarkerForegroundColorIndex()
{
  AUTONAMES0("MarkerForegroundColorIndex")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Series::SetMarkerForegroundColorIndex(TAutoVal& val)
{
  AUTONAMES0("MarkerForegroundColorIndex")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Series::GetMarkerStyle()
{
  AUTONAMES0("MarkerStyle")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Series::SetMarkerStyle(TAutoVal& val)
{
  AUTONAMES0("MarkerStyle")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Series::GetName()
{
  AUTONAMES0("Name")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Series::SetName(TAutoVal& val)
{
  AUTONAMES0("Name")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Series::GetParent()
{
  AUTONAMES0("Parent")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Series::SetParent(TAutoVal& val)
{
  AUTONAMES0("Parent")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Series::GetPictureType()
{
  AUTONAMES0("PictureType")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Series::SetPictureType(TAutoVal& val)
{
  AUTONAMES0("PictureType")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Series::GetPictureUnit()
{
  AUTONAMES0("PictureUnit")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Series::SetPictureUnit(TAutoVal& val)
{
  AUTONAMES0("PictureUnit")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Series::GetPlotOrder()
{
  AUTONAMES0("PlotOrder")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Series::SetPlotOrder(TAutoVal& val)
{
  AUTONAMES0("PlotOrder")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Series::GetSmooth()
{
  AUTONAMES0("Smooth")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Series::SetSmooth(TAutoVal& val)
{
  AUTONAMES0("Smooth")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Series::GetType()
{
  AUTONAMES0("Type")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Series::SetType(TAutoVal& val)
{
  AUTONAMES0("Type")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Series::GetValues()
{
  AUTONAMES0("Values")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Series::SetValues(TAutoVal& val)
{
  AUTONAMES0("Values")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Series::GetXValues()
{
  AUTONAMES0("XValues")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Series::SetXValues(TAutoVal& val)
{
  AUTONAMES0("XValues")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Series::Application()
{
  AUTONAMES0("Application")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Series::ApplyDataLabels(TAutoVal& Type, TAutoVal& LegendKey)
{
  AUTONAMES0("ApplyDataLabels")
  AUTOARGS2(Type, LegendKey)
  AUTOCALL_METHOD_RET
}

TAutoVal Series::ClearFormats()
{
  AUTONAMES0("ClearFormats")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Series::Copy()
{
  AUTONAMES0("Copy")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Series::DataLabels(TAutoVal& Index)
{
  AUTONAMES0("DataLabels")
  AUTOARGS1(Index)
  AUTOCALL_METHOD_RET
}

TAutoVal Series::Delete()
{
  AUTONAMES0("Delete")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Series::ErrorBar(TAutoVal& Direction, TAutoVal& Include, TAutoVal& Type, TAutoVal& Amount, TAutoVal& MinusValues)
{
  AUTONAMES0("ErrorBar")
  AUTOARGS5(Direction, Include, Type, Amount, MinusValues)
  AUTOCALL_METHOD_RET
}

TAutoVal Series::Paste()
{
  AUTONAMES0("Paste")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Series::Points(TAutoVal& Index)
{
  AUTONAMES0("Points")
  AUTOARGS1(Index)
  AUTOCALL_METHOD_RET
}

TAutoVal Series::Select()
{
  AUTONAMES0("Select")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Series::Trendlines(TAutoVal& Index)
{
  AUTONAMES0("Trendlines")
  AUTOARGS1(Index)
  AUTOCALL_METHOD_RET
}


// TKIND_DISPATCH: SeriesCollection {0002086C-0000-0000-C000-000000000046}\9

TAutoVal SeriesCollection::GetCount()
{
  AUTONAMES0("Count")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void SeriesCollection::SetCount(TAutoVal& val)
{
  AUTONAMES0("Count")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal SeriesCollection::GetCreator()
{
  AUTONAMES0("Creator")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void SeriesCollection::SetCreator(TAutoVal& val)
{
  AUTONAMES0("Creator")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal SeriesCollection::GetParent()
{
  AUTONAMES0("Parent")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void SeriesCollection::SetParent(TAutoVal& val)
{
  AUTONAMES0("Parent")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal SeriesCollection::_NewEnum()
{
  AUTONAMES0("_NewEnum")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal SeriesCollection::Add(TAutoVal& Source, TAutoVal& Rowcol, TAutoVal& SeriesLabels, TAutoVal& CategoryLabels, TAutoVal& Replace)
{
  AUTONAMES0("Add")
  AUTOARGS5(Source, Rowcol, SeriesLabels, CategoryLabels, Replace)
  AUTOCALL_METHOD_RET
}

TAutoVal SeriesCollection::Application()
{
  AUTONAMES0("Application")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal SeriesCollection::Extend(TAutoVal& Source, TAutoVal& Rowcol, TAutoVal& CategoryLabels)
{
  AUTONAMES0("Extend")
  AUTOARGS3(Source, Rowcol, CategoryLabels)
  AUTOCALL_METHOD_RET
}

TAutoVal SeriesCollection::Item(TAutoVal& Index)
{
  AUTONAMES0("Item")
  AUTOARGS1(Index)
  AUTOCALL_METHOD_RET
}

TAutoVal SeriesCollection::Paste(TAutoVal& Rowcol, TAutoVal& SeriesLabels, TAutoVal& CategoryLabels, TAutoVal& Replace, TAutoVal& NewSeries)
{
  AUTONAMES0("Paste")
  AUTOARGS5(Rowcol, SeriesLabels, CategoryLabels, Replace, NewSeries)
  AUTOCALL_METHOD_RET
}


// TKIND_DISPATCH: LegendEntry {000208BA-0000-0000-C000-000000000046}\9

TAutoVal LegendEntry::GetCreator()
{
  AUTONAMES0("Creator")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void LegendEntry::SetCreator(TAutoVal& val)
{
  AUTONAMES0("Creator")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal LegendEntry::GetFont()
{
  AUTONAMES0("Font")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void LegendEntry::SetFont(TAutoVal& val)
{
  AUTONAMES0("Font")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal LegendEntry::GetIndex()
{
  AUTONAMES0("Index")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void LegendEntry::SetIndex(TAutoVal& val)
{
  AUTONAMES0("Index")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal LegendEntry::GetLegendKey()
{
  AUTONAMES0("LegendKey")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void LegendEntry::SetLegendKey(TAutoVal& val)
{
  AUTONAMES0("LegendKey")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal LegendEntry::GetParent()
{
  AUTONAMES0("Parent")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void LegendEntry::SetParent(TAutoVal& val)
{
  AUTONAMES0("Parent")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal LegendEntry::Application()
{
  AUTONAMES0("Application")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal LegendEntry::Delete()
{
  AUTONAMES0("Delete")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal LegendEntry::Select()
{
  AUTONAMES0("Select")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}


// TKIND_DISPATCH: LegendEntries {000208BB-0000-0000-C000-000000000046}\9

TAutoVal LegendEntries::GetCount()
{
  AUTONAMES0("Count")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void LegendEntries::SetCount(TAutoVal& val)
{
  AUTONAMES0("Count")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal LegendEntries::GetCreator()
{
  AUTONAMES0("Creator")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void LegendEntries::SetCreator(TAutoVal& val)
{
  AUTONAMES0("Creator")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal LegendEntries::GetParent()
{
  AUTONAMES0("Parent")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void LegendEntries::SetParent(TAutoVal& val)
{
  AUTONAMES0("Parent")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal LegendEntries::_NewEnum()
{
  AUTONAMES0("_NewEnum")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal LegendEntries::Application()
{
  AUTONAMES0("Application")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal LegendEntries::Item(TAutoVal& Index)
{
  AUTONAMES0("Item")
  AUTOARGS1(Index)
  AUTOCALL_METHOD_RET
}


// TKIND_DISPATCH: LegendKey {000208BC-0000-0000-C000-000000000046}\9

TAutoVal LegendKey::GetBorder()
{
  AUTONAMES0("Border")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void LegendKey::SetBorder(TAutoVal& val)
{
  AUTONAMES0("Border")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal LegendKey::GetCreator()
{
  AUTONAMES0("Creator")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void LegendKey::SetCreator(TAutoVal& val)
{
  AUTONAMES0("Creator")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal LegendKey::GetInterior()
{
  AUTONAMES0("Interior")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void LegendKey::SetInterior(TAutoVal& val)
{
  AUTONAMES0("Interior")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal LegendKey::GetInvertIfNegative()
{
  AUTONAMES0("InvertIfNegative")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void LegendKey::SetInvertIfNegative(TAutoVal& val)
{
  AUTONAMES0("InvertIfNegative")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal LegendKey::GetMarkerBackgroundColor()
{
  AUTONAMES0("MarkerBackgroundColor")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void LegendKey::SetMarkerBackgroundColor(TAutoVal& val)
{
  AUTONAMES0("MarkerBackgroundColor")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal LegendKey::GetMarkerBackgroundColorIndex()
{
  AUTONAMES0("MarkerBackgroundColorIndex")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void LegendKey::SetMarkerBackgroundColorIndex(TAutoVal& val)
{
  AUTONAMES0("MarkerBackgroundColorIndex")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal LegendKey::GetMarkerForegroundColor()
{
  AUTONAMES0("MarkerForegroundColor")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void LegendKey::SetMarkerForegroundColor(TAutoVal& val)
{
  AUTONAMES0("MarkerForegroundColor")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal LegendKey::GetMarkerForegroundColorIndex()
{
  AUTONAMES0("MarkerForegroundColorIndex")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void LegendKey::SetMarkerForegroundColorIndex(TAutoVal& val)
{
  AUTONAMES0("MarkerForegroundColorIndex")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal LegendKey::GetMarkerStyle()
{
  AUTONAMES0("MarkerStyle")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void LegendKey::SetMarkerStyle(TAutoVal& val)
{
  AUTONAMES0("MarkerStyle")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal LegendKey::GetParent()
{
  AUTONAMES0("Parent")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void LegendKey::SetParent(TAutoVal& val)
{
  AUTONAMES0("Parent")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal LegendKey::GetSmooth()
{
  AUTONAMES0("Smooth")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void LegendKey::SetSmooth(TAutoVal& val)
{
  AUTONAMES0("Smooth")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal LegendKey::Application()
{
  AUTONAMES0("Application")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal LegendKey::ClearFormats()
{
  AUTONAMES0("ClearFormats")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal LegendKey::Delete()
{
  AUTONAMES0("Delete")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal LegendKey::Select()
{
  AUTONAMES0("Select")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}


// TKIND_DISPATCH: Trendline {000208BE-0000-0000-C000-000000000046}\9

TAutoVal Trendline::GetBackward()
{
  AUTONAMES0("Backward")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Trendline::SetBackward(TAutoVal& val)
{
  AUTONAMES0("Backward")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Trendline::GetBorder()
{
  AUTONAMES0("Border")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Trendline::SetBorder(TAutoVal& val)
{
  AUTONAMES0("Border")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Trendline::GetCreator()
{
  AUTONAMES0("Creator")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Trendline::SetCreator(TAutoVal& val)
{
  AUTONAMES0("Creator")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Trendline::GetDataLabel()
{
  AUTONAMES0("DataLabel")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Trendline::SetDataLabel(TAutoVal& val)
{
  AUTONAMES0("DataLabel")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Trendline::GetDisplayEquation()
{
  AUTONAMES0("DisplayEquation")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Trendline::SetDisplayEquation(TAutoVal& val)
{
  AUTONAMES0("DisplayEquation")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Trendline::GetDisplayRSquared()
{
  AUTONAMES0("DisplayRSquared")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Trendline::SetDisplayRSquared(TAutoVal& val)
{
  AUTONAMES0("DisplayRSquared")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Trendline::GetForward()
{
  AUTONAMES0("Forward")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Trendline::SetForward(TAutoVal& val)
{
  AUTONAMES0("Forward")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Trendline::GetIndex()
{
  AUTONAMES0("Index")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Trendline::SetIndex(TAutoVal& val)
{
  AUTONAMES0("Index")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Trendline::GetIntercept()
{
  AUTONAMES0("Intercept")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Trendline::SetIntercept(TAutoVal& val)
{
  AUTONAMES0("Intercept")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Trendline::GetInterceptIsAuto()
{
  AUTONAMES0("InterceptIsAuto")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Trendline::SetInterceptIsAuto(TAutoVal& val)
{
  AUTONAMES0("InterceptIsAuto")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Trendline::GetName()
{
  AUTONAMES0("Name")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Trendline::SetName(TAutoVal& val)
{
  AUTONAMES0("Name")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Trendline::GetNameIsAuto()
{
  AUTONAMES0("NameIsAuto")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Trendline::SetNameIsAuto(TAutoVal& val)
{
  AUTONAMES0("NameIsAuto")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Trendline::GetOrder()
{
  AUTONAMES0("Order")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Trendline::SetOrder(TAutoVal& val)
{
  AUTONAMES0("Order")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Trendline::GetParent()
{
  AUTONAMES0("Parent")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Trendline::SetParent(TAutoVal& val)
{
  AUTONAMES0("Parent")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Trendline::GetPeriod()
{
  AUTONAMES0("Period")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Trendline::SetPeriod(TAutoVal& val)
{
  AUTONAMES0("Period")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Trendline::GetType()
{
  AUTONAMES0("Type")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Trendline::SetType(TAutoVal& val)
{
  AUTONAMES0("Type")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Trendline::Application()
{
  AUTONAMES0("Application")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Trendline::ClearFormats()
{
  AUTONAMES0("ClearFormats")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Trendline::Delete()
{
  AUTONAMES0("Delete")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Trendline::Select()
{
  AUTONAMES0("Select")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}


// TKIND_DISPATCH: Trendlines {000208BD-0000-0000-C000-000000000046}\9

TAutoVal Trendlines::GetCount()
{
  AUTONAMES0("Count")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Trendlines::SetCount(TAutoVal& val)
{
  AUTONAMES0("Count")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Trendlines::GetCreator()
{
  AUTONAMES0("Creator")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Trendlines::SetCreator(TAutoVal& val)
{
  AUTONAMES0("Creator")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Trendlines::GetParent()
{
  AUTONAMES0("Parent")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void Trendlines::SetParent(TAutoVal& val)
{
  AUTONAMES0("Parent")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal Trendlines::_NewEnum()
{
  AUTONAMES0("_NewEnum")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Trendlines::Add(TAutoVal& Type, TAutoVal& Order, TAutoVal& Period, TAutoVal& Forward, TAutoVal& Backward, TAutoVal& Intercept, TAutoVal& DisplayEquation, TAutoVal& DisplayRSquared, TAutoVal& Name)
{
  AUTONAMES0("Add")
  AUTOARGS9(Type, Order, Period, Forward, Backward, Intercept, DisplayEquation, DisplayRSquared, Name)
  AUTOCALL_METHOD_RET
}

TAutoVal Trendlines::Application()
{
  AUTONAMES0("Application")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal Trendlines::Item(TAutoVal& Index)
{
  AUTONAMES0("Item")
  AUTOARGS1(Index)
  AUTOCALL_METHOD_RET
}


// TKIND_DISPATCH: AutoCorrect {000208D4-0000-0000-C000-000000000046}\9

TAutoVal AutoCorrect::GetCapitalizeNamesOfDays()
{
  AUTONAMES0("CapitalizeNamesOfDays")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void AutoCorrect::SetCapitalizeNamesOfDays(TAutoVal& val)
{
  AUTONAMES0("CapitalizeNamesOfDays")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal AutoCorrect::GetCreator()
{
  AUTONAMES0("Creator")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void AutoCorrect::SetCreator(TAutoVal& val)
{
  AUTONAMES0("Creator")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal AutoCorrect::GetParent()
{
  AUTONAMES0("Parent")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void AutoCorrect::SetParent(TAutoVal& val)
{
  AUTONAMES0("Parent")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal AutoCorrect::GetReplacementList()
{
  AUTONAMES0("ReplacementList")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void AutoCorrect::SetReplacementList(TAutoVal& val)
{
  AUTONAMES0("ReplacementList")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal AutoCorrect::GetReplaceText()
{
  AUTONAMES0("ReplaceText")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void AutoCorrect::SetReplaceText(TAutoVal& val)
{
  AUTONAMES0("ReplaceText")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal AutoCorrect::GetTwoInitialCapitals()
{
  AUTONAMES0("TwoInitialCapitals")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void AutoCorrect::SetTwoInitialCapitals(TAutoVal& val)
{
  AUTONAMES0("TwoInitialCapitals")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TAutoVal AutoCorrect::AddReplacement(TAutoVal& What, TAutoVal& Replacement)
{
  AUTONAMES0("AddReplacement")
  AUTOARGS2(What, Replacement)
  AUTOCALL_METHOD_RET
}

TAutoVal AutoCorrect::Application()
{
  AUTONAMES0("Application")
  AUTOARGS0()
  AUTOCALL_METHOD_RET
}

TAutoVal AutoCorrect::DeleteReplacement(TAutoVal& What)
{
  AUTONAMES0("DeleteReplacement")
  AUTOARGS1(What)
  AUTOCALL_METHOD_RET
}

