// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'VCFrmla1.pas' rev: 6.00

#ifndef VCFrmla1HPP
#define VCFrmla1HPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <Menus.hpp>	// Pascal unit
#include <Controls.hpp>	// Pascal unit
#include <OleCtrls.hpp>	// Pascal unit
#include <Graphics.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <OleCtl.hpp>	// Pascal unit
#include <Ole2.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Vcfrmla1
{
//-- type declarations -------------------------------------------------------
typedef void __fastcall (__closure *TVCFormulaOneClick)(System::TObject* Sender, int nRow, int nCol);

typedef void __fastcall (__closure *TVCFormulaOneDblClick)(System::TObject* Sender, int nRow, int nCol);

typedef void __fastcall (__closure *TVCFormulaOneStartEdit)(System::TObject* Sender, AnsiString &EditString, short &Cancel);

typedef void __fastcall (__closure *TVCFormulaOneEndEdit)(System::TObject* Sender, AnsiString &EditString, short &Cancel);

typedef void __fastcall (__closure *TVCFormulaOneObjClick)(System::TObject* Sender, AnsiString &ObjName, int ObjID);

typedef void __fastcall (__closure *TVCFormulaOneObjDblClick)(System::TObject* Sender, AnsiString &ObjName, int ObjID);

typedef void __fastcall (__closure *TVCFormulaOneRClick)(System::TObject* Sender, int nRow, int nCol);

typedef void __fastcall (__closure *TVCFormulaOneRDblClick)(System::TObject* Sender, int nRow, int nCol);

typedef void __fastcall (__closure *TVCFormulaOneObjValueChanged)(System::TObject* Sender, AnsiString &ObjName, int ObjID);

typedef void __fastcall (__closure *TVCFormulaOneObjGotFocus)(System::TObject* Sender, AnsiString &ObjName, int ObjID);

typedef void __fastcall (__closure *TVCFormulaOneObjLostFocus)(System::TObject* Sender, AnsiString &ObjName, int ObjID);

typedef void __fastcall (__closure *TVCFormulaOneValidationFailed)(System::TObject* Sender, AnsiString &pEntry, int nSheet, int nRow, int nCol, AnsiString &pShowMessage, short &pAction);

class DELPHICLASS TVCFormulaOne;
class PASCALIMPLEMENTATION TVCFormulaOne : public Olectrls::TOleControl 
{
	typedef Olectrls::TOleControl inherited;
	
private:
	TVCFormulaOneClick FOnClick;
	TVCFormulaOneDblClick FOnDblClick;
	Classes::TNotifyEvent FOnCancelEdit;
	Classes::TNotifyEvent FOnSelChange;
	TVCFormulaOneStartEdit FOnStartEdit;
	TVCFormulaOneEndEdit FOnEndEdit;
	Classes::TNotifyEvent FOnStartRecalc;
	Classes::TNotifyEvent FOnEndRecalc;
	Classes::TNotifyEvent FOnTopLeftChanged;
	TVCFormulaOneObjClick FOnObjClick;
	TVCFormulaOneObjDblClick FOnObjDblClick;
	TVCFormulaOneRClick FOnRClick;
	TVCFormulaOneRDblClick FOnRDblClick;
	TVCFormulaOneObjValueChanged FOnObjValueChanged;
	Classes::TNotifyEvent FOnModified;
	TVCFormulaOneObjGotFocus FOnObjGotFocus;
	TVCFormulaOneObjLostFocus FOnObjLostFocus;
	TVCFormulaOneValidationFailed FOnValidationFailed;
	AnsiString __stdcall Get_ColText(int nCol);
	void __stdcall Set_ColText(int nCol, const AnsiString Value);
	AnsiString __stdcall Get_DefinedName(const AnsiString pName);
	void __stdcall Set_DefinedName(const AnsiString pName, const AnsiString Value);
	AnsiString __stdcall Get_EntryRC(int nRow, int nCol);
	void __stdcall Set_EntryRC(int nRow, int nCol, const AnsiString Value);
	AnsiString __stdcall Get_FormattedTextRC(int nRow, int nCol);
	void __stdcall Set_FormattedTextRC(int nRow, int nCol, const AnsiString Value);
	AnsiString __stdcall Get_FormulaRC(int nRow, int nCol);
	void __stdcall Set_FormulaRC(int nRow, int nCol, const AnsiString Value);
	int __stdcall Get_LastColForRow(int nRow);
	void __stdcall Set_LastColForRow(int nRow, int Value);
	Word __stdcall Get_LogicalRC(int nRow, int nCol);
	void __stdcall Set_LogicalRC(int nRow, int nCol, Word Value);
	double __stdcall Get_NumberRC(int nRow, int nCol);
	void __stdcall Set_NumberRC(int nRow, int nCol, double Value);
	AnsiString __stdcall Get_RowText(int nRow);
	void __stdcall Set_RowText(int nRow, const AnsiString Value);
	AnsiString __stdcall Get_TextRC(int nRow, int nCol);
	void __stdcall Set_TextRC(int nRow, int nCol, const AnsiString Value);
	short __stdcall Get_TypeRC(int nRow, int nCol);
	void __stdcall Set_TypeRC(int nRow, int nCol, short Value);
	short __stdcall Get_ColWidth(int nCol);
	void __stdcall Set_ColWidth(int nCol, short Value);
	short __stdcall Get_RowHeight(int nRow);
	void __stdcall Set_RowHeight(int nRow, short Value);
	AnsiString __stdcall Get_DefinedNameByIndex(int nName);
	void __stdcall Set_DefinedNameByIndex(int nName, const AnsiString Value);
	AnsiString __stdcall Get_SheetName(int nSheet);
	void __stdcall Set_SheetName(int nSheet, const AnsiString Value);
	Graphics::TColor __stdcall Get_PaletteEntry(int nEntry);
	void __stdcall Set_PaletteEntry(int nEntry, Graphics::TColor Value);
	short __stdcall Get_ColWidthTwips(int Col);
	void __stdcall Set_ColWidthTwips(int Col, short Value);
	AnsiString __stdcall Get_ObjItem(int ID, short Item);
	void __stdcall Set_ObjItem(int ID, short Item, const AnsiString Value);
	AnsiString __stdcall Get_ObjItems(int ID);
	void __stdcall Set_ObjItems(int ID, const AnsiString Value);
	AnsiString __stdcall Get_ObjName(int ID);
	void __stdcall Set_ObjName(int ID, const AnsiString Value);
	AnsiString __stdcall Get_ObjText(int ID);
	void __stdcall Set_ObjText(int ID, const AnsiString Value);
	short __stdcall Get_ObjValue(int ID);
	void __stdcall Set_ObjValue(int ID, short Value);
	Word __stdcall Get_ObjVisible(int ID);
	void __stdcall Set_ObjVisible(int ID, Word Value);
	AnsiString __stdcall Get_AutoFillItems(short Index);
	void __stdcall Set_AutoFillItems(short Index, const AnsiString Value);
	Word __stdcall Get_ColHidden(int nCol);
	void __stdcall Set_ColHidden(int nCol, Word Value);
	Word __stdcall Get_RowHidden(int nRow);
	void __stdcall Set_RowHidden(int nRow, Word Value);
	Word __stdcall Get_SheetSelected(int nSheet);
	void __stdcall Set_SheetSelected(int nSheet, Word Value);
	
protected:
	virtual void __fastcall InitControlData(void);
	
public:
	void __stdcall EditPasteValues(void);
	void __stdcall GetAlignment(short &pHorizontal, Word &pWordWrap, short &pVertical, short &pOrientation);
	HIDESBASE void __stdcall GetBorder(short &pLeft, short &pRight, short &pTop, short &pBottom, short &pShade, Graphics::TColor &pcrLeft, Graphics::TColor &pcrRight, Graphics::TColor &pcrTop, Graphics::TColor &pcrBottom);
	void __stdcall GetFont(AnsiString &pName, short &pSize, Word &pBold, Word &pItalic, Word &pUnderline, Word &pStrikeout, Graphics::TColor &pcrColor, Word &pOutline, Word &pShadow);
	void __stdcall GetLineStyle(short &pStyle, Graphics::TColor &pcrColor, short &pWeight);
	void __stdcall GetPattern(short &pPattern, Graphics::TColor &pcrFG, Graphics::TColor &pcrBG);
	void __stdcall GetProtection(Word &pLocked, Word &pHidden);
	void __stdcall GetTabbedText(int nR1, int nC1, int nR2, int nC2, Word bValuesOnly, int &phText);
	void __stdcall SetTabbedText(int nStartRow, int nStartCol, int &pRows, int &pCols, Word bValuesOnly, const AnsiString pText);
	void __stdcall AddColPageBreak(int nCol);
	void __stdcall AddPageBreak(void);
	void __stdcall AddRowPageBreak(int nRow);
	void __stdcall AddSelection(int nR1, int nC1, int nR2, int nC2);
	void __stdcall Attach(const AnsiString pTitle);
	void __stdcall AttachToSS(int hSrcSS);
	void __stdcall CalculationDlg(void);
	void __stdcall CancelEdit(void);
	void __stdcall CheckRecalc(void);
	void __stdcall ClearClipboard(void);
	void __stdcall ClearRange(int nR1, int nC1, int nR2, int nC2, short ClearType);
	void __stdcall ColorPaletteDlg(void);
	void __stdcall ColWidthDlg(void);
	void __stdcall CopyAll(int hSrcSS);
	void __stdcall CopyRange(int nDstR1, int nDstC1, int nDstR2, int nDstC2, int hSrcSS, int nSrcR1, int nSrcC1, int nSrcR2, int nSrcC2);
	void __stdcall DefinedNameDlg(void);
	void __stdcall DeleteDefinedName(const AnsiString pName);
	void __stdcall DeleteRange(int nR1, int nC1, int nR2, int nC2, short ShiftType);
	void __stdcall Draw(int hDC, int x, int y, int cx, int cy, int nRow, int nCol, int &pRows, int &pCols, int nFixedRow, int nFixedCol, int nFixedRows, int nFixedCols);
	void __stdcall EditClear(short ClearType);
	void __stdcall EditCopy(void);
	void __stdcall EditCopyDown(void);
	void __stdcall EditCopyRight(void);
	void __stdcall EditCut(void);
	void __stdcall EditDelete(short ShiftType);
	void __stdcall EditInsert(short ShiftType);
	void __stdcall EditPaste(void);
	void __stdcall EndEdit(void);
	void __stdcall FilePageSetupDlg(void);
	void __stdcall FilePrint(Word bShowPrintDlg);
	void __stdcall FilePrintSetupDlg(void);
	void __stdcall FormatAlignmentDlg(void);
	void __stdcall FormatBorderDlg(void);
	void __stdcall FormatCurrency0(void);
	void __stdcall FormatCurrency2(void);
	void __stdcall FormatDefaultFontDlg(void);
	void __stdcall FormatFixed(void);
	void __stdcall FormatFixed2(void);
	void __stdcall FormatFontDlg(void);
	void __stdcall FormatFraction(void);
	void __stdcall FormatGeneral(void);
	void __stdcall FormatHmmampm(void);
	void __stdcall FormatMdyy(void);
	void __stdcall FormatNumberDlg(void);
	void __stdcall FormatPatternDlg(void);
	void __stdcall FormatPercent(void);
	void __stdcall FormatScientific(void);
	void __stdcall GetActiveCell(int &pRow, int &pCol);
	void __stdcall GetDefaultFont(AnsiString &pBuf, short &pSize);
	void __stdcall GetHdrSelection(Word &pTopLeftHdr, Word &pRowHdr, Word &pColHdr);
	void __stdcall GetIteration(Word &pIteration, short &pMaxIterations, double &pMaxChange);
	void __stdcall GetPrintScale(short &pScale, Word &pFitToPage, int &pVPages, int &pHPages);
	void __stdcall GetSelection(short nSelection, int &pR1, int &pC1, int &pR2, int &pC2);
	void __stdcall GotoDlg(void);
	void __stdcall HeapMin(void);
	void __stdcall InitTable(void);
	void __stdcall InsertRange(int nR1, int nC1, int nR2, int nC2, short ShiftType);
	void __stdcall LineStyleDlg(void);
	void __stdcall MoveRange(int nR1, int nC1, int nR2, int nC2, int nRowOffset, int nColOffset);
	void __stdcall ObjAddItem(int ID, const AnsiString pItem);
	void __stdcall ObjAddSelection(int ID);
	void __stdcall ObjBringToFront(void);
	void __stdcall ObjDeleteItem(int ID, short nItem);
	void __stdcall ObjGetCell(int ID, short &pControlCellType, int &pRow, int &pCol);
	void __stdcall ObjGetPos(int ID, float &pX1, float &pY1, float &pX2, float &pY2);
	void __stdcall ObjGetSelection(short nSelection, int &pID);
	void __stdcall ObjInsertItem(int ID, short nItem, const AnsiString pItem);
	void __stdcall ObjNameDlg(void);
	void __stdcall ObjNew(short ObjType, float nX1, float nY1, float nX2, float nY2, int &pID);
	void __stdcall ObjNewPicture(float nX1, float nY1, float nX2, float nY2, int &pID, int hMF, int nMapMode, int nWndExtentX, int nWndExtentY);
	void __stdcall ObjOptionsDlg(void);
	void __stdcall ObjPosToTwips(float nX1, float nY1, float nX2, float nY2, int &pX, int &pY, int &pCX, int &pCY, short &pShown);
	void __stdcall ObjSendToBack(void);
	void __stdcall ObjSetCell(int ID, short ControlCellType, int nRow, int nCol);
	void __stdcall ObjSetPicture(int ID, int hMF, short nMapMode, int nWndExtentX, int nWndExtentY);
	void __stdcall ObjSetPos(int ID, float nX1, float nY1, float nX2, float nY2);
	void __stdcall ObjSetSelection(int ID);
	void __stdcall OpenFileDlg(const AnsiString pTitle, int hWndParent, AnsiString &pBuf);
	void __stdcall ProtectionDlg(void);
	void __stdcall RangeToTwips(int nRow1, int nCol1, int nRow2, int nCol2, int &pX, int &pY, int &pCX, int &pCY, short &pShown);
	void __stdcall Read(const AnsiString pPathName, short &pFileType);
	void __stdcall ReadFromBlob(int hBlob, short nReservedBytes);
	void __stdcall Recalc(void);
	void __stdcall RemoveColPageBreak(int nCol);
	void __stdcall RemovePageBreak(void);
	void __stdcall RemoveRowPageBreak(int nRow);
	void __stdcall RowHeightDlg(void);
	void __stdcall SaveFileDlg(const AnsiString pTitle, AnsiString &pBuf, short &pFileType);
	void __stdcall SaveWindowInfo(void);
	void __stdcall SetActiveCell(int nRow, int nCol);
	void __stdcall SetAlignment(short HAlign, Word bWordWrap, short VAlign, short nOrientation);
	void __stdcall SetBorder(short nOutline, short nLeft, short nRight, short nTop, short nBottom, short nShade, Graphics::TColor crOutline, Graphics::TColor crLeft, Graphics::TColor crRight, Graphics::TColor crTop, Graphics::TColor crBottom);
	void __stdcall SetColWidth(int nC1, int nC2, short nWidth, Word bDefColWidth);
	void __stdcall SetColWidthAuto(int nR1, int nC1, int nR2, int nC2, Word bSetDefaults);
	void __stdcall SetDefaultFont(const AnsiString pName, short nSize);
	HIDESBASE void __stdcall SetFont(const AnsiString pName, short nSize, Word bBold, Word bItalic, Word bUnderline, Word bStrikeout, Graphics::TColor crColor, Word bOutline, Word bShadow);
	void __stdcall SetHdrSelection(Word bTopLeftHdr, Word bRowHdr, Word bColHdr);
	void __stdcall SetIteration(Word bIteration, short nMaxIterations, double nMaxChange);
	void __stdcall SetLineStyle(short nStyle, Graphics::TColor crColor, short nWeight);
	void __stdcall SetPattern(short nPattern, Graphics::TColor crFG, Graphics::TColor crBG);
	void __stdcall SetPrintAreaFromSelection(void);
	void __stdcall SetPrintScale(short nScale, Word bFitToPage, short nVPages, short nHPages);
	void __stdcall SetPrintTitlesFromSelection(void);
	void __stdcall SetProtection(Word bLocked, Word bHidden);
	void __stdcall SetRowHeight(int nR1, int nR2, short nHeight, Word bDefRowHeight);
	void __stdcall SetRowHeightAuto(int nR1, int nC1, int nR2, int nC2, Word bSetDefaults);
	void __stdcall SetSelection(int nR1, int nC1, int nR2, int nC2);
	void __stdcall ShowActiveCell(void);
	void __stdcall Sort3(int nR1, int nC1, int nR2, int nC2, Word bSortByRows, int nKey1, int nKey2, int nKey3);
	void __stdcall SortDlg(void);
	void __stdcall StartEdit(Word bClear, Word bInCellEditFocus, Word bArrowsExitEditMode);
	void __stdcall SwapTables(int hSS2);
	void __stdcall TransactCommit(void);
	void __stdcall TransactRollback(void);
	void __stdcall TransactStart(void);
	void __stdcall TwipsToRC(int x, int y, int &pRow, int &pCol);
	void __stdcall SSUpdate(void);
	short __stdcall SSVersion(void);
	void __stdcall Write(const AnsiString pPathName, short FileType);
	void __stdcall WriteToBlob(int &phBlob, short nReservedBytes);
	void __stdcall SetRowHidden(int nRow1, int nRow2, Word bHidden);
	void __stdcall SetColHidden(int nCol1, int nCol2, Word bHidden);
	void __stdcall SetColWidthTwips(int nCol1, int nCol2, int nWidth, Word bDefColWidth);
	void __stdcall EditInsertSheets(void);
	void __stdcall EditDeleteSheets(void);
	void __stdcall InsertSheets(int nSheet, int nSheets);
	void __stdcall DeleteSheets(int nSheet, int nSheets);
	HIDESBASE void __stdcall Refresh(void);
	int __stdcall NextColPageBreak(int Col);
	int __stdcall NextRowPageBreak(int Row);
	int __stdcall ObjFirstID(void);
	int __stdcall ObjNextID(int ID);
	short __stdcall ObjGetItemCount(int ID);
	short __stdcall ObjGetType(int ID);
	short __stdcall ObjGetSelectionCount(void);
	AnsiString __stdcall FormatRCNr(int Row, int Col, Word DoAbsolute);
	int __stdcall SS(void);
	AnsiString __stdcall ErrorNumberToText(int SSError);
	int __stdcall ObjNameToID(const AnsiString Name);
	int __stdcall DefinedNameCount(void);
	void __stdcall ValidationRuleDlg(void);
	void __stdcall SetValidationRule(const AnsiString Rule, const AnsiString Text);
	void __stdcall GetValidationRule(AnsiString &Rule, AnsiString &Text);
	short __stdcall AutoFillItemsCount(void);
	void __stdcall CopyRangeEx(int nDstSheet, int nDstR1, int nDstC1, int nDstR2, int nDstC2, int hSrcSS, int nSrcSheet, int nSrcR1, int nSrcC1, int nSrcR2, int nSrcC2);
	void __stdcall Sort(int nR1, int nC1, int nR2, int nC2, Word bSortByRows, const Variant Keys);
	void __stdcall DeleteAutoFillItems(short nIndex);
	void __stdcall ODBCConnect(AnsiString &pConnect, Word bShowErrors, short &pRetCode);
	void __stdcall ODBCDisconnect(void);
	void __stdcall ODBCQuery(AnsiString &pQuery, int nRow, int nCol, Word bForceShowDlg, Word &pSetColNames, Word &pSetColFormats, Word &pSetColWidths, Word &pSetMaxRC, short &pRetCode);
	void __stdcall LaunchDesigner(void);
	void __stdcall AboutBox(void);
	__property AnsiString ColText[int nCol] = {read=Get_ColText, write=Set_ColText};
	__property AnsiString DefinedName[AnsiString pName] = {read=Get_DefinedName, write=Set_DefinedName};
	__property AnsiString EntryRC[int nRow][int nCol] = {read=Get_EntryRC, write=Set_EntryRC};
	__property AnsiString FormattedTextRC[int nRow][int nCol] = {read=Get_FormattedTextRC, write=Set_FormattedTextRC};
	__property AnsiString FormulaRC[int nRow][int nCol] = {read=Get_FormulaRC, write=Set_FormulaRC};
	__property int LastColForRow[int nRow] = {read=Get_LastColForRow, write=Set_LastColForRow};
	__property Word LogicalRC[int nRow][int nCol] = {read=Get_LogicalRC, write=Set_LogicalRC};
	__property double NumberRC[int nRow][int nCol] = {read=Get_NumberRC, write=Set_NumberRC};
	__property AnsiString RowText[int nRow] = {read=Get_RowText, write=Set_RowText};
	__property AnsiString TextRC[int nRow][int nCol] = {read=Get_TextRC, write=Set_TextRC};
	__property short TypeRC[int nRow][int nCol] = {read=Get_TypeRC, write=Set_TypeRC};
	__property short ColWidth[int nCol] = {read=Get_ColWidth, write=Set_ColWidth};
	__property short RowHeight[int nRow] = {read=Get_RowHeight, write=Set_RowHeight};
	__property AnsiString DefinedNameByIndex[int nName] = {read=Get_DefinedNameByIndex, write=Set_DefinedNameByIndex};
	__property AnsiString SheetName[int nSheet] = {read=Get_SheetName, write=Set_SheetName};
	__property Graphics::TColor PaletteEntry[int nEntry] = {read=Get_PaletteEntry, write=Set_PaletteEntry};
	__property short ColWidthTwips[int Col] = {read=Get_ColWidthTwips, write=Set_ColWidthTwips};
	__property AnsiString ObjItem[int ID][short Item] = {read=Get_ObjItem, write=Set_ObjItem};
	__property AnsiString ObjItems[int ID] = {read=Get_ObjItems, write=Set_ObjItems};
	__property AnsiString ObjName[int ID] = {read=Get_ObjName, write=Set_ObjName};
	__property AnsiString ObjText[int ID] = {read=Get_ObjText, write=Set_ObjText};
	__property short ObjValue[int ID] = {read=Get_ObjValue, write=Set_ObjValue};
	__property Word ObjVisible[int ID] = {read=Get_ObjVisible, write=Set_ObjVisible};
	__property AnsiString AutoFillItems[short Index] = {read=Get_AutoFillItems, write=Set_AutoFillItems};
	__property Word ColHidden[int nCol] = {read=Get_ColHidden, write=Set_ColHidden};
	__property Word RowHidden[int nRow] = {read=Get_RowHidden, write=Set_RowHidden};
	__property Word SheetSelected[int nSheet] = {read=Get_SheetSelected, write=Set_SheetSelected};
	
__published:
	__property TabStop  = {default=1};
	__property DragCursor  = {default=-12};
	__property DragMode  = {default=0};
	__property ParentShowHint  = {default=1};
	__property PopupMenu ;
	__property ShowHint ;
	__property TabOrder  = {default=-1};
	__property Visible  = {default=1};
	__property OnDragDrop ;
	__property OnDragOver ;
	__property OnEndDrag ;
	__property OnEnter ;
	__property OnExit ;
	__property OnStartDrag ;
	__property OnKeyDown ;
	__property OnKeyPress ;
	__property OnKeyUp ;
	__property OnMouseDown ;
	__property OnMouseMove ;
	__property OnMouseUp ;
	__property Graphics::TColor BackColor = {read=GetColorProp, write=SetColorProp, stored=false, index=3, nodefault};
	__property int Col = {read=GetIntegerProp, write=SetIntegerProp, stored=false, index=4, nodefault};
	__property int Row = {read=GetIntegerProp, write=SetIntegerProp, stored=false, index=5, nodefault};
	__property short ShowHScrollBar = {read=GetSmallintProp, write=SetSmallintProp, stored=false, index=6, nodefault};
	__property AnsiString Text = {read=GetStringProp, write=SetStringProp, stored=false, index=7};
	__property double Number = {read=GetDoubleProp, write=SetDoubleProp, stored=false, index=8};
	__property AnsiString Formula = {read=GetStringProp, write=SetStringProp, stored=false, index=9};
	__property int FixedCol = {read=GetIntegerProp, write=SetIntegerProp, stored=false, index=10, nodefault};
	__property int FixedCols = {read=GetIntegerProp, write=SetIntegerProp, stored=false, index=11, nodefault};
	__property int FixedRow = {read=GetIntegerProp, write=SetIntegerProp, stored=false, index=12, nodefault};
	__property int FixedRows = {read=GetIntegerProp, write=SetIntegerProp, stored=false, index=13, nodefault};
	__property Word ShowGridLines = {read=GetOleBoolProp, write=SetOleBoolProp, stored=false, index=14, nodefault};
	__property Word ShowRowHeading = {read=GetOleBoolProp, write=SetOleBoolProp, stored=false, index=15, nodefault};
	__property short ShowSelections = {read=GetSmallintProp, write=SetSmallintProp, stored=false, index=16, nodefault};
	__property int LeftCol = {read=GetIntegerProp, write=SetIntegerProp, stored=false, index=17, nodefault};
	__property int MaxCol = {read=GetIntegerProp, write=SetIntegerProp, stored=false, index=18, nodefault};
	__property int MaxRow = {read=GetIntegerProp, write=SetIntegerProp, stored=false, index=19, nodefault};
	__property int TopRow = {read=GetIntegerProp, write=SetIntegerProp, stored=false, index=20, nodefault};
	__property Word AllowResize = {read=GetOleBoolProp, write=SetOleBoolProp, stored=false, index=21, nodefault};
	__property Word AllowSelections = {read=GetOleBoolProp, write=SetOleBoolProp, stored=false, index=22, nodefault};
	__property Word AllowFormulas = {read=GetOleBoolProp, write=SetOleBoolProp, stored=false, index=23, nodefault};
	__property Word AllowInCellEditing = {read=GetOleBoolProp, write=SetOleBoolProp, stored=false, index=24, nodefault};
	__property short ShowVScrollBar = {read=GetSmallintProp, write=SetSmallintProp, stored=false, index=25, nodefault};
	__property Word AllowFillRange = {read=GetOleBoolProp, write=SetOleBoolProp, stored=false, index=26, nodefault};
	__property Word AllowMoveRange = {read=GetOleBoolProp, write=SetOleBoolProp, stored=false, index=27, nodefault};
	__property int SelStartCol = {read=GetIntegerProp, write=SetIntegerProp, stored=false, index=28, nodefault};
	__property int SelStartRow = {read=GetIntegerProp, write=SetIntegerProp, stored=false, index=29, nodefault};
	__property int SelEndCol = {read=GetIntegerProp, write=SetIntegerProp, stored=false, index=30, nodefault};
	__property int SelEndRow = {read=GetIntegerProp, write=SetIntegerProp, stored=false, index=31, nodefault};
	__property Graphics::TColor ExtraColor = {read=GetColorProp, write=SetColorProp, stored=false, index=32, nodefault};
	__property AnsiString FileName = {read=GetStringProp, write=SetStringProp, stored=false, index=33};
	__property Word AutoRecalc = {read=GetOleBoolProp, write=SetOleBoolProp, stored=false, index=34, nodefault};
	__property Word PrintGridLines = {read=GetOleBoolProp, write=SetOleBoolProp, stored=false, index=35, nodefault};
	__property Word PrintRowHeading = {read=GetOleBoolProp, write=SetOleBoolProp, stored=false, index=36, nodefault};
	__property Word PrintHCenter = {read=GetOleBoolProp, write=SetOleBoolProp, stored=false, index=37, nodefault};
	__property Word PrintVCenter = {read=GetOleBoolProp, write=SetOleBoolProp, stored=false, index=38, nodefault};
	__property Word PrintLeftToRight = {read=GetOleBoolProp, write=SetOleBoolProp, stored=false, index=39, nodefault};
	__property AnsiString PrintHeader = {read=GetStringProp, write=SetStringProp, stored=false, index=40};
	__property AnsiString PrintFooter = {read=GetStringProp, write=SetStringProp, stored=false, index=41};
	__property double PrintLeftMargin = {read=GetDoubleProp, write=SetDoubleProp, stored=false, index=42};
	__property double PrintTopMargin = {read=GetDoubleProp, write=SetDoubleProp, stored=false, index=43};
	__property double PrintRightMargin = {read=GetDoubleProp, write=SetDoubleProp, stored=false, index=44};
	__property double PrintBottomMargin = {read=GetDoubleProp, write=SetDoubleProp, stored=false, index=45};
	__property AnsiString PrintArea = {read=GetStringProp, write=SetStringProp, stored=false, index=46};
	__property AnsiString PrintTitles = {read=GetStringProp, write=SetStringProp, stored=false, index=47};
	__property Word PrintNoColor = {read=GetOleBoolProp, write=SetOleBoolProp, stored=false, index=48, nodefault};
	__property AnsiString Selection = {read=GetStringProp, write=SetStringProp, stored=false, index=49};
	__property AnsiString TableName = {read=GetStringProp, write=SetStringProp, stored=false, index=50};
	__property Word DoCancelEdit = {read=GetOleBoolProp, write=SetOleBoolProp, stored=false, index=51, nodefault};
	__property Word DoSelChange = {read=GetOleBoolProp, write=SetOleBoolProp, stored=false, index=52, nodefault};
	__property Word DoStartEdit = {read=GetOleBoolProp, write=SetOleBoolProp, stored=false, index=53, nodefault};
	__property Word DoEndEdit = {read=GetOleBoolProp, write=SetOleBoolProp, stored=false, index=54, nodefault};
	__property Word DoStartRecalc = {read=GetOleBoolProp, write=SetOleBoolProp, stored=false, index=55, nodefault};
	__property Word DoEndRecalc = {read=GetOleBoolProp, write=SetOleBoolProp, stored=false, index=56, nodefault};
	__property Word DoClick = {read=GetOleBoolProp, write=SetOleBoolProp, stored=false, index=57, nodefault};
	__property Word DoDblClick = {read=GetOleBoolProp, write=SetOleBoolProp, stored=false, index=58, nodefault};
	__property Word ShowColHeading = {read=GetOleBoolProp, write=SetOleBoolProp, stored=false, index=59, nodefault};
	__property Word PrintColHeading = {read=GetOleBoolProp, write=SetOleBoolProp, stored=false, index=60, nodefault};
	__property AnsiString Entry = {read=GetStringProp, write=SetStringProp, stored=false, index=61};
	__property Word Repaint = {read=GetOleBoolProp, write=SetOleBoolProp, stored=false, index=62, nodefault};
	__property Word AllowArrows = {read=GetOleBoolProp, write=SetOleBoolProp, stored=false, index=63, nodefault};
	__property Word AllowTabs = {read=GetOleBoolProp, write=SetOleBoolProp, stored=false, index=64, nodefault};
	__property AnsiString FormattedText = {read=GetStringProp, write=SetStringProp, stored=false, index=65};
	__property Word RowMode = {read=GetOleBoolProp, write=SetOleBoolProp, stored=false, index=66, nodefault};
	__property Word AllowDelete = {read=GetOleBoolProp, write=SetOleBoolProp, stored=false, index=67, nodefault};
	__property Word EnableProtection = {read=GetOleBoolProp, write=SetOleBoolProp, stored=false, index=68, nodefault};
	__property int MinCol = {read=GetIntegerProp, write=SetIntegerProp, stored=false, index=69, nodefault};
	__property int MinRow = {read=GetIntegerProp, write=SetIntegerProp, stored=false, index=70, nodefault};
	__property Word DoTopLeftChanged = {read=GetOleBoolProp, write=SetOleBoolProp, stored=false, index=71, nodefault};
	__property Word AllowEditHeaders = {read=GetOleBoolProp, write=SetOleBoolProp, stored=false, index=72, nodefault};
	__property Word DoObjClick = {read=GetOleBoolProp, write=SetOleBoolProp, stored=false, index=73, nodefault};
	__property Word DoObjDblClick = {read=GetOleBoolProp, write=SetOleBoolProp, stored=false, index=74, nodefault};
	__property Word AllowObjSelections = {read=GetOleBoolProp, write=SetOleBoolProp, stored=false, index=75, nodefault};
	__property Word DoRClick = {read=GetOleBoolProp, write=SetOleBoolProp, stored=false, index=76, nodefault};
	__property Word DoRDblClick = {read=GetOleBoolProp, write=SetOleBoolProp, stored=false, index=77, nodefault};
	__property AnsiString Clip = {read=GetStringProp, write=SetStringProp, stored=false, index=78};
	__property AnsiString ClipValues = {read=GetStringProp, write=SetStringProp, stored=false, index=79};
	__property Word PrintLandscape = {read=GetOleBoolProp, write=SetOleBoolProp, stored=false, index=80, nodefault};
	__property Word Enabled = {read=GetOleBoolProp, write=SetOleBoolProp, stored=false, index=-514, nodefault};
	__property short BorderStyle = {read=GetSmallintProp, write=SetSmallintProp, stored=false, index=-504, nodefault};
	__property AnsiString AppName = {read=GetStringProp, write=SetStringProp, stored=false, index=81};
	__property short HdrHeight = {read=GetSmallintProp, write=SetSmallintProp, stored=false, index=82, nodefault};
	__property short HdrWidth = {read=GetSmallintProp, write=SetSmallintProp, stored=false, index=83, nodefault};
	__property AnsiString NumberFormat = {read=GetStringProp, write=SetStringProp, stored=false, index=84};
	__property AnsiString TopLeftText = {read=GetStringProp, write=SetStringProp, stored=false, index=85};
	__property Word EnterMovesDown = {read=GetOleBoolProp, write=SetOleBoolProp, stored=false, index=86, nodefault};
	__property int LastCol = {read=GetIntegerProp, write=SetIntegerProp, stored=false, index=87, nodefault};
	__property int LastRow = {read=GetIntegerProp, write=SetIntegerProp, stored=false, index=88, nodefault};
	__property Word Logical = {read=GetOleBoolProp, write=SetOleBoolProp, stored=false, index=89, nodefault};
	__property short Mode = {read=GetSmallintProp, write=SetSmallintProp, stored=false, index=90, nodefault};
	__property short PolyEditMode = {read=GetSmallintProp, write=SetSmallintProp, stored=false, index=91, nodefault};
	__property short ViewScale = {read=GetSmallintProp, write=SetSmallintProp, stored=false, index=92, nodefault};
	__property short SelectionCount = {read=GetSmallintProp, write=SetSmallintProp, stored=false, index=93, nodefault};
	__property AnsiString Title = {read=GetStringProp, write=SetStringProp, stored=false, index=94};
	__property short Type_ = {read=GetSmallintProp, write=SetSmallintProp, stored=false, index=95, nodefault};
	__property Word ShowFormulas = {read=GetOleBoolProp, write=SetOleBoolProp, stored=false, index=96, nodefault};
	__property Word ShowZeroValues = {read=GetOleBoolProp, write=SetOleBoolProp, stored=false, index=97, nodefault};
	__property short MousePointer = {read=GetSmallintProp, write=SetSmallintProp, stored=false, index=2, nodefault};
	__property Variant MouseIcon = {read=GetVariantProp, write=SetVariantProp, stored=false, index=98};
	__property Word DoObjValueChanged = {read=GetOleBoolProp, write=SetOleBoolProp, stored=false, index=99, nodefault};
	__property Word ScrollToLastRC = {read=GetOleBoolProp, write=SetOleBoolProp, stored=false, index=100, nodefault};
	__property Word Modified = {read=GetOleBoolProp, write=SetOleBoolProp, stored=false, index=101, nodefault};
	__property Word DoObjGotFocus = {read=GetOleBoolProp, write=SetOleBoolProp, stored=false, index=102, nodefault};
	__property Word DoObjLostFocus = {read=GetOleBoolProp, write=SetOleBoolProp, stored=false, index=103, nodefault};
	__property int PrintDevMode = {read=GetIntegerProp, write=SetIntegerProp, stored=false, index=104, nodefault};
	__property int NumSheets = {read=GetIntegerProp, write=SetIntegerProp, stored=false, index=105, nodefault};
	__property int Sheet = {read=GetIntegerProp, write=SetIntegerProp, stored=false, index=106, nodefault};
	__property short ColWidthUnits = {read=GetSmallintProp, write=SetSmallintProp, stored=false, index=107, nodefault};
	__property Word ShowTypeMarkers = {read=GetOleBoolProp, write=SetOleBoolProp, stored=false, index=108, nodefault};
	__property short ShowTabs = {read=GetSmallintProp, write=SetSmallintProp, stored=false, index=109, nodefault};
	__property Word ShowEditBar = {read=GetOleBoolProp, write=SetOleBoolProp, stored=false, index=110, nodefault};
	__property Word ShowEditBarCellRef = {read=GetOleBoolProp, write=SetOleBoolProp, stored=false, index=111, nodefault};
	__property Word AllowDesigner = {read=GetOleBoolProp, write=SetOleBoolProp, stored=false, index=1, nodefault};
	__property int hWnd = {read=GetIntegerProp, write=SetIntegerProp, stored=false, index=-515, nodefault};
	__property Word AllowAutoFill = {read=GetOleBoolProp, write=SetOleBoolProp, stored=false, index=112, nodefault};
	__property TVCFormulaOneClick OnClick = {read=FOnClick, write=FOnClick};
	__property TVCFormulaOneDblClick OnDblClick = {read=FOnDblClick, write=FOnDblClick};
	__property Classes::TNotifyEvent OnCancelEdit = {read=FOnCancelEdit, write=FOnCancelEdit};
	__property Classes::TNotifyEvent OnSelChange = {read=FOnSelChange, write=FOnSelChange};
	__property TVCFormulaOneStartEdit OnStartEdit = {read=FOnStartEdit, write=FOnStartEdit};
	__property TVCFormulaOneEndEdit OnEndEdit = {read=FOnEndEdit, write=FOnEndEdit};
	__property Classes::TNotifyEvent OnStartRecalc = {read=FOnStartRecalc, write=FOnStartRecalc};
	__property Classes::TNotifyEvent OnEndRecalc = {read=FOnEndRecalc, write=FOnEndRecalc};
	__property Classes::TNotifyEvent OnTopLeftChanged = {read=FOnTopLeftChanged, write=FOnTopLeftChanged};
	__property TVCFormulaOneObjClick OnObjClick = {read=FOnObjClick, write=FOnObjClick};
	__property TVCFormulaOneObjDblClick OnObjDblClick = {read=FOnObjDblClick, write=FOnObjDblClick};
	__property TVCFormulaOneRClick OnRClick = {read=FOnRClick, write=FOnRClick};
	__property TVCFormulaOneRDblClick OnRDblClick = {read=FOnRDblClick, write=FOnRDblClick};
	__property TVCFormulaOneObjValueChanged OnObjValueChanged = {read=FOnObjValueChanged, write=FOnObjValueChanged};
	__property Classes::TNotifyEvent OnModified = {read=FOnModified, write=FOnModified};
	__property TVCFormulaOneObjGotFocus OnObjGotFocus = {read=FOnObjGotFocus, write=FOnObjGotFocus};
	__property TVCFormulaOneObjLostFocus OnObjLostFocus = {read=FOnObjLostFocus, write=FOnObjLostFocus};
	__property TVCFormulaOneValidationFailed OnValidationFailed = {read=FOnValidationFailed, write=FOnValidationFailed};
public:
	#pragma option push -w-inl
	/* TOleControl.Create */ inline __fastcall virtual TVCFormulaOne(Classes::TComponent* AOwner) : Olectrls::TOleControl(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TOleControl.Destroy */ inline __fastcall virtual ~TVCFormulaOne(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TVCFormulaOne(HWND ParentWindow) : Olectrls::TOleControl(ParentWindow) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------
extern PACKAGE void __fastcall Register(void);

}	/* namespace Vcfrmla1 */
using namespace Vcfrmla1;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// VCFrmla1
