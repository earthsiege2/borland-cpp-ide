// Borland C++ Builder
// Copyright (c) 1995, 1999 by Borland International
// All rights reserved

// (DO NOT EDIT: machine generated header) 'vcf1.pas' rev: 5.00

#ifndef vcf1HPP
#define vcf1HPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <Menus.hpp>	// Pascal unit
#include <Controls.hpp>	// Pascal unit
#include <StdVCL.hpp>	// Pascal unit
#include <OleCtrls.hpp>	// Pascal unit
#include <OleServer.hpp>	// Pascal unit
#include <Graphics.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <ActiveX.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Vcf1
{
//-- type declarations -------------------------------------------------------
typedef Activex::TOleEnum F1ColWidthUnitsConstants;

typedef Activex::TOleEnum F1MousePointerConstants;

typedef Activex::TOleEnum F1ShowOffOnAutoConstants;

typedef Activex::TOleEnum F1ShowTabsConstants;

typedef Activex::TOleEnum F1ModeConstants;

typedef Activex::TOleEnum F1PolyEditModeConstants;

typedef Activex::TOleEnum F1ShiftTypeConstants;

typedef Activex::TOleEnum F1HAlignConstants;

typedef Activex::TOleEnum F1VAlignConstants;

typedef Activex::TOleEnum F1ClearTypeConstants;

typedef Activex::TOleEnum F1FileTypeConstants;

typedef Activex::TOleEnum F1ObjTypeConstants;

typedef Activex::TOleEnum F1ErrorConstants;

typedef Activex::TOleEnum F1ControlCellConstants;

__dispinterface _DVCF1;
typedef System::DelphiInterface<_DVCF1> _di__DVCF1;
__dispinterface INTERFACE_UUID("{042BADC6-5E58-11CE-B610-524153480001}") _DVCF1  : public IDispatch 
	
{
	
};
typedef _DVCF1 F1Book;

typedef short *PSmallint1;

typedef Word *PWordBool1;

typedef unsigned *PUINT1;

typedef WideString *PWideString1;

typedef unsigned *PSYSINT1;

typedef int *PInteger1;

typedef double *PDouble1;

typedef float *PSingle1;

__dispinterface _DVCF1Events;
typedef System::DelphiInterface<_DVCF1Events> _di__DVCF1Events;
__dispinterface INTERFACE_UUID("{042BADC7-5E58-11CE-B610-524153480001}") _DVCF1Events  : public IDispatch 
	
{
	
};

typedef void __fastcall (__closure *TF1BookClick)(System::TObject* Sender, int nRow, int nCol);

typedef void __fastcall (__closure *TF1BookDblClick)(System::TObject* Sender, int nRow, int nCol);

typedef void __fastcall (__closure *TF1BookStartEdit)(System::TObject* Sender, WideString &EditString
	, short &Cancel);

typedef void __fastcall (__closure *TF1BookEndEdit)(System::TObject* Sender, WideString &EditString, 
	short &Cancel);

typedef void __fastcall (__closure *TF1BookObjClick)(System::TObject* Sender, WideString &ObjName, int 
	ObjID);

typedef void __fastcall (__closure *TF1BookObjDblClick)(System::TObject* Sender, WideString &ObjName
	, int ObjID);

typedef void __fastcall (__closure *TF1BookRClick)(System::TObject* Sender, int nRow, int nCol);

typedef void __fastcall (__closure *TF1BookRDblClick)(System::TObject* Sender, int nRow, int nCol);

typedef void __fastcall (__closure *TF1BookObjValueChanged)(System::TObject* Sender, WideString &ObjName
	, int ObjID);

typedef void __fastcall (__closure *TF1BookObjGotFocus)(System::TObject* Sender, WideString &ObjName
	, int ObjID);

typedef void __fastcall (__closure *TF1BookObjLostFocus)(System::TObject* Sender, WideString &ObjName
	, int ObjID);

typedef void __fastcall (__closure *TF1BookValidationFailed)(System::TObject* Sender, WideString &pEntry
	, int nSheet, int nRow, int nCol, WideString &pShowMessage, short &pAction);

class DELPHICLASS TF1Book;
class PASCALIMPLEMENTATION TF1Book : public Olectrls::TOleControl 
{
	typedef Olectrls::TOleControl inherited;
	
private:
	TF1BookClick FOnClick;
	TF1BookDblClick FOnDblClick;
	Classes::TNotifyEvent FOnCancelEdit;
	Classes::TNotifyEvent FOnSelChange;
	TF1BookStartEdit FOnStartEdit;
	TF1BookEndEdit FOnEndEdit;
	Classes::TNotifyEvent FOnStartRecalc;
	Classes::TNotifyEvent FOnEndRecalc;
	Classes::TNotifyEvent FOnTopLeftChanged;
	TF1BookObjClick FOnObjClick;
	TF1BookObjDblClick FOnObjDblClick;
	TF1BookRClick FOnRClick;
	TF1BookRDblClick FOnRDblClick;
	TF1BookObjValueChanged FOnObjValueChanged;
	Classes::TNotifyEvent FOnModified;
	TF1BookObjGotFocus FOnObjGotFocus;
	TF1BookObjLostFocus FOnObjLostFocus;
	TF1BookValidationFailed FOnValidationFailed;
	_di__DVCF1 FIntf;
	_di__DVCF1 __fastcall GetControlInterface();
	
protected:
	HIDESBASE void __fastcall CreateControl(void);
	virtual void __fastcall InitControlData(void);
	WideString __fastcall Get_ColText(int nCol);
	void __fastcall Set_ColText(int nCol, const WideString Param2);
	WideString __fastcall Get_DefinedName(const WideString pName);
	void __fastcall Set_DefinedName(const WideString pName, const WideString Param2);
	WideString __fastcall Get_EntryRC(int nRow, int nCol);
	void __fastcall Set_EntryRC(int nRow, int nCol, const WideString Param3);
	WideString __fastcall Get_FormattedTextRC(int nRow, int nCol);
	void __fastcall Set_FormattedTextRC(int nRow, int nCol, const WideString Param3);
	WideString __fastcall Get_FormulaRC(int nRow, int nCol);
	void __fastcall Set_FormulaRC(int nRow, int nCol, const WideString Param3);
	int __fastcall Get_LastColForRow(int nRow);
	void __fastcall Set_LastColForRow(int nRow, int Param2);
	Word __fastcall Get_LogicalRC(int nRow, int nCol);
	void __fastcall Set_LogicalRC(int nRow, int nCol, Word Param3);
	double __fastcall Get_NumberRC(int nRow, int nCol);
	void __fastcall Set_NumberRC(int nRow, int nCol, double Param3);
	WideString __fastcall Get_RowText(int nRow);
	void __fastcall Set_RowText(int nRow, const WideString Param2);
	WideString __fastcall Get_TextRC(int nRow, int nCol);
	void __fastcall Set_TextRC(int nRow, int nCol, const WideString Param3);
	short __fastcall Get_TypeRC(int nRow, int nCol);
	void __fastcall Set_TypeRC(int nRow, int nCol, short Param3);
	short __fastcall Get_ColWidth(int nCol);
	void __fastcall Set_ColWidth(int nCol, short Param2);
	short __fastcall Get_RowHeight(int nRow);
	void __fastcall Set_RowHeight(int nRow, short Param2);
	WideString __fastcall Get_DefinedNameByIndex(int nName);
	void __fastcall Set_DefinedNameByIndex(int nName, const WideString Param2);
	WideString __fastcall Get_SheetName(int nSheet);
	void __fastcall Set_SheetName(int nSheet, const WideString Param2);
	unsigned __fastcall Get_PaletteEntry(int nEntry);
	void __fastcall Set_PaletteEntry(int nEntry, unsigned Param2);
	short __fastcall Get_ColWidthTwips(int Col);
	void __fastcall Set_ColWidthTwips(int Col, short Param2);
	WideString __fastcall Get_ObjItem(int ID, short Item);
	void __fastcall Set_ObjItem(int ID, short Item, const WideString Param3);
	WideString __fastcall Get_ObjItems(int ID);
	void __fastcall Set_ObjItems(int ID, const WideString Param2);
	WideString __fastcall Get_ObjName(int ID);
	void __fastcall Set_ObjName(int ID, const WideString Param2);
	WideString __fastcall Get_ObjText(int ID);
	void __fastcall Set_ObjText(int ID, const WideString Param2);
	short __fastcall Get_ObjValue(int ID);
	void __fastcall Set_ObjValue(int ID, short Param2);
	Word __fastcall Get_ObjVisible(int ID);
	void __fastcall Set_ObjVisible(int ID, Word Param2);
	WideString __fastcall Get_AutoFillItems(short Index);
	void __fastcall Set_AutoFillItems(short Index, const WideString Param2);
	Word __fastcall Get_ColHidden(int nCol);
	void __fastcall Set_ColHidden(int nCol, Word Param2);
	Word __fastcall Get_RowHidden(int nRow);
	void __fastcall Set_RowHidden(int nRow, Word Param2);
	Word __fastcall Get_SheetSelected(int nSheet);
	void __fastcall Set_SheetSelected(int nSheet, Word Param2);
	
public:
	void __fastcall EditPasteValues(void);
	void __fastcall GetAlignment(short &pHorizontal, Word &pWordWrap, short &pVertical, short &pOrientation
		);
	HIDESBASE void __fastcall GetBorder(short &pLeft, short &pRight, short &pTop, short &pBottom, short 
		&pShade, unsigned &pcrLeft, unsigned &pcrRight, unsigned &pcrTop, unsigned &pcrBottom);
	void __fastcall GetFont(WideString &pName, short &pSize, Word &pBold, Word &pItalic, Word &pUnderline
		, Word &pStrikeout, unsigned &pcrColor, Word &pOutline, Word &pShadow);
	void __fastcall GetLineStyle(short &pStyle, unsigned &pcrColor, short &pWeight);
	void __fastcall GetPattern(short &pPattern, unsigned &pcrFG, unsigned &pcrBG);
	void __fastcall GetProtection(Word &pLocked, Word &pHidden);
	void __fastcall GetTabbedText(int nR1, int nC1, int nR2, int nC2, Word bValuesOnly, unsigned &phText
		);
	void __fastcall SetTabbedText(int nStartRow, int nStartCol, int &pRows, int &pCols, Word bValuesOnly
		, const WideString pText);
	void __fastcall AddColPageBreak(int nCol);
	void __fastcall AddPageBreak(void);
	void __fastcall AddRowPageBreak(int nRow);
	void __fastcall AddSelection(int nR1, int nC1, int nR2, int nC2);
	void __fastcall Attach(const WideString pTitle);
	void __fastcall AttachToSS(int hSrcSS);
	void __fastcall CalculationDlg(void);
	void __fastcall CancelEdit(void);
	void __fastcall CheckRecalc(void);
	void __fastcall ClearClipboard(void);
	void __fastcall ClearRange(int nR1, int nC1, int nR2, int nC2, short ClearType);
	void __fastcall ColorPaletteDlg(void);
	void __fastcall ColWidthDlg(void);
	void __fastcall CopyAll(int hSrcSS);
	void __fastcall CopyRange(int nDstR1, int nDstC1, int nDstR2, int nDstC2, int hSrcSS, int nSrcR1, int 
		nSrcC1, int nSrcR2, int nSrcC2);
	void __fastcall DefinedNameDlg(void);
	void __fastcall DeleteDefinedName(const WideString pName);
	void __fastcall DeleteRange(int nR1, int nC1, int nR2, int nC2, short ShiftType);
	void __fastcall Draw(unsigned hDC, int x, int y, int cx, int cy, int nRow, int nCol, int &pRows, int 
		&pCols, int nFixedRow, int nFixedCol, int nFixedRows, int nFixedCols);
	void __fastcall EditClear(short ClearType);
	void __fastcall EditCopy(void);
	void __fastcall EditCopyDown(void);
	void __fastcall EditCopyRight(void);
	void __fastcall EditCut(void);
	void __fastcall EditDelete(short ShiftType);
	void __fastcall EditInsert(short ShiftType);
	void __fastcall EditPaste(void);
	void __fastcall EndEdit(void);
	void __fastcall FilePageSetupDlg(void);
	void __fastcall FilePrint(Word bShowPrintDlg);
	void __fastcall FilePrintSetupDlg(void);
	void __fastcall FormatAlignmentDlg(void);
	void __fastcall FormatBorderDlg(void);
	void __fastcall FormatCurrency0(void);
	void __fastcall FormatCurrency2(void);
	void __fastcall FormatDefaultFontDlg(void);
	void __fastcall FormatFixed(void);
	void __fastcall FormatFixed2(void);
	void __fastcall FormatFontDlg(void);
	void __fastcall FormatFraction(void);
	void __fastcall FormatGeneral(void);
	void __fastcall FormatHmmampm(void);
	void __fastcall FormatMdyy(void);
	void __fastcall FormatNumberDlg(void);
	void __fastcall FormatPatternDlg(void);
	void __fastcall FormatPercent(void);
	void __fastcall FormatScientific(void);
	void __fastcall GetActiveCell(int &pRow, int &pCol);
	void __fastcall GetDefaultFont(WideString &pBuf, short &pSize);
	void __fastcall GetHdrSelection(Word &pTopLeftHdr, Word &pRowHdr, Word &pColHdr);
	void __fastcall GetIteration(Word &pIteration, short &pMaxIterations, double &pMaxChange);
	void __fastcall GetPrintScale(short &pScale, Word &pFitToPage, int &pVPages, int &pHPages);
	void __fastcall GetSelection(short nSelection, int &pR1, int &pC1, int &pR2, int &pC2);
	void __fastcall GotoDlg(void);
	void __fastcall HeapMin(void);
	void __fastcall InitTable(void);
	void __fastcall InsertRange(int nR1, int nC1, int nR2, int nC2, short ShiftType);
	void __fastcall LineStyleDlg(void);
	void __fastcall MoveRange(int nR1, int nC1, int nR2, int nC2, int nRowOffset, int nColOffset);
	void __fastcall ObjAddItem(int ID, const WideString pItem);
	void __fastcall ObjAddSelection(int ID);
	void __fastcall ObjBringToFront(void);
	void __fastcall ObjDeleteItem(int ID, short nItem);
	void __fastcall ObjGetCell(int ID, short &pControlCellType, int &pRow, int &pCol);
	void __fastcall ObjGetPos(int ID, float &pX1, float &pY1, float &pX2, float &pY2);
	void __fastcall ObjGetSelection(short nSelection, int &pID);
	void __fastcall ObjInsertItem(int ID, short nItem, const WideString pItem);
	void __fastcall ObjNameDlg(void);
	void __fastcall ObjNew(short ObjType, float nX1, float nY1, float nX2, float nY2, int &pID);
	void __fastcall ObjNewPicture(float nX1, float nY1, float nX2, float nY2, int &pID, unsigned hMF, int 
		nMapMode, int nWndExtentX, int nWndExtentY);
	void __fastcall ObjOptionsDlg(void);
	void __fastcall ObjPosToTwips(float nX1, float nY1, float nX2, float nY2, int &pX, int &pY, int &pCX
		, int &pCY, short &pShown);
	void __fastcall ObjSendToBack(void);
	void __fastcall ObjSetCell(int ID, short ControlCellType, int nRow, int nCol);
	void __fastcall ObjSetPicture(int ID, unsigned hMF, short nMapMode, int nWndExtentX, int nWndExtentY
		);
	void __fastcall ObjSetPos(int ID, float nX1, float nY1, float nX2, float nY2);
	void __fastcall ObjSetSelection(int ID);
	void __fastcall OpenFileDlg(const WideString pTitle, unsigned hWndParent, WideString &pBuf);
	void __fastcall ProtectionDlg(void);
	void __fastcall RangeToTwips(int nRow1, int nCol1, int nRow2, int nCol2, int &pX, int &pY, int &pCX
		, int &pCY, short &pShown);
	void __fastcall Read(const WideString pPathName, short &pFileType);
	void __fastcall ReadFromBlob(unsigned hBlob, short nReservedBytes);
	void __fastcall Recalc(void);
	void __fastcall RemoveColPageBreak(int nCol);
	void __fastcall RemovePageBreak(void);
	void __fastcall RemoveRowPageBreak(int nRow);
	void __fastcall RowHeightDlg(void);
	void __fastcall SaveFileDlg(const WideString pTitle, WideString &pBuf, short &pFileType);
	void __fastcall SaveWindowInfo(void);
	void __fastcall SetActiveCell(int nRow, int nCol);
	void __fastcall SetAlignment(short HAlign, Word bWordWrap, short VAlign, short nOrientation);
	void __fastcall SetBorder(short nOutline, short nLeft, short nRight, short nTop, short nBottom, short 
		nShade, unsigned crOutline, unsigned crLeft, unsigned crRight, unsigned crTop, unsigned crBottom);
		
	void __fastcall SetColWidth(int nC1, int nC2, short nWidth, Word bDefColWidth);
	void __fastcall SetColWidthAuto(int nR1, int nC1, int nR2, int nC2, Word bSetDefaults);
	void __fastcall SetDefaultFont(const WideString pName, short nSize);
	HIDESBASE void __fastcall SetFont(const WideString pName, short nSize, Word bBold, Word bItalic, Word 
		bUnderline, Word bStrikeout, unsigned crColor, Word bOutline, Word bShadow);
	void __fastcall SetHdrSelection(Word bTopLeftHdr, Word bRowHdr, Word bColHdr);
	void __fastcall SetIteration(Word bIteration, short nMaxIterations, double nMaxChange);
	void __fastcall SetLineStyle(short nStyle, unsigned crColor, short nWeight);
	void __fastcall SetPattern(short nPattern, unsigned crFG, unsigned crBG);
	void __fastcall SetPrintAreaFromSelection(void);
	void __fastcall SetPrintScale(short nScale, Word bFitToPage, short nVPages, short nHPages);
	void __fastcall SetPrintTitlesFromSelection(void);
	void __fastcall SetProtection(Word bLocked, Word bHidden);
	void __fastcall SetRowHeight(int nR1, int nR2, short nHeight, Word bDefRowHeight);
	void __fastcall SetRowHeightAuto(int nR1, int nC1, int nR2, int nC2, Word bSetDefaults);
	void __fastcall SetSelection(int nR1, int nC1, int nR2, int nC2);
	void __fastcall ShowActiveCell(void);
	void __fastcall Sort3(int nR1, int nC1, int nR2, int nC2, Word bSortByRows, int nKey1, int nKey2, int 
		nKey3);
	void __fastcall SortDlg(void);
	void __fastcall StartEdit(Word bClear, Word bInCellEditFocus, Word bArrowsExitEditMode);
	void __fastcall SwapTables(int hSS2);
	void __fastcall TransactCommit(void);
	void __fastcall TransactRollback(void);
	void __fastcall TransactStart(void);
	void __fastcall TwipsToRC(int x, int y, int &pRow, int &pCol);
	void __fastcall SSUpdate(void);
	short __fastcall SSVersion(void);
	void __fastcall Write(const WideString pPathName, short FileType);
	void __fastcall WriteToBlob(unsigned &phBlob, short nReservedBytes);
	void __fastcall SetRowHidden(int nRow1, int nRow2, Word bHidden);
	void __fastcall SetColHidden(int nCol1, int nCol2, Word bHidden);
	void __fastcall SetColWidthTwips(int nCol1, int nCol2, int nWidth, Word bDefColWidth);
	void __fastcall EditInsertSheets(void);
	void __fastcall EditDeleteSheets(void);
	void __fastcall InsertSheets(int nSheet, int nSheets);
	void __fastcall DeleteSheets(int nSheet, int nSheets);
	HIDESBASE void __fastcall Refresh(void);
	int __fastcall NextColPageBreak(int Col);
	int __fastcall NextRowPageBreak(int Row);
	int __fastcall ObjFirstID(void);
	int __fastcall ObjNextID(int ID);
	short __fastcall ObjGetItemCount(int ID);
	short __fastcall ObjGetType(int ID);
	short __fastcall ObjGetSelectionCount(void);
	WideString __fastcall FormatRCNr(int Row, int Col, Word DoAbsolute);
	int __fastcall SS(void);
	WideString __fastcall ErrorNumberToText(int SSError);
	int __fastcall ObjNameToID(const WideString Name);
	int __fastcall DefinedNameCount(void);
	void __fastcall ValidationRuleDlg(void);
	void __fastcall SetValidationRule(const WideString Rule, const WideString Text);
	void __fastcall GetValidationRule(WideString &Rule, WideString &Text);
	short __fastcall AutoFillItemsCount(void);
	void __fastcall CopyRangeEx(int nDstSheet, int nDstR1, int nDstC1, int nDstR2, int nDstC2, int hSrcSS
		, int nSrcSheet, int nSrcR1, int nSrcC1, int nSrcR2, int nSrcC2);
	void __fastcall Sort(int nR1, int nC1, int nR2, int nC2, Word bSortByRows, const OleVariant &Keys);
		
	void __fastcall DeleteAutoFillItems(short nIndex);
	void __fastcall ODBCConnect(WideString &pConnect, Word bShowErrors, short &pRetCode);
	void __fastcall ODBCDisconnect(void);
	void __fastcall ODBCQuery(WideString &pQuery, int nRow, int nCol, Word bForceShowDlg, Word &pSetColNames
		, Word &pSetColFormats, Word &pSetColWidths, Word &pSetMaxRC, short &pRetCode);
	void __fastcall LaunchDesigner(void);
	void __fastcall AboutBox(void);
	__property _di__DVCF1 ControlInterface = {read=GetControlInterface};
	__property _di__DVCF1 DefaultInterface = {read=GetControlInterface};
	__property WideString ColText[int nCol] = {read=Get_ColText, write=Set_ColText};
	__property WideString DefinedName[WideString pName] = {read=Get_DefinedName, write=Set_DefinedName}
		;
	__property WideString EntryRC[int nRow][int nCol] = {read=Get_EntryRC, write=Set_EntryRC};
	__property WideString FormattedTextRC[int nRow][int nCol] = {read=Get_FormattedTextRC, write=Set_FormattedTextRC
		};
	__property WideString FormulaRC[int nRow][int nCol] = {read=Get_FormulaRC, write=Set_FormulaRC};
	__property int LastColForRow[int nRow] = {read=Get_LastColForRow, write=Set_LastColForRow};
	__property Word LogicalRC[int nRow][int nCol] = {read=Get_LogicalRC, write=Set_LogicalRC};
	__property double NumberRC[int nRow][int nCol] = {read=Get_NumberRC, write=Set_NumberRC};
	__property WideString RowText[int nRow] = {read=Get_RowText, write=Set_RowText};
	__property WideString TextRC[int nRow][int nCol] = {read=Get_TextRC, write=Set_TextRC};
	__property short TypeRC[int nRow][int nCol] = {read=Get_TypeRC, write=Set_TypeRC};
	__property short ColWidth[int nCol] = {read=Get_ColWidth, write=Set_ColWidth};
	__property short RowHeight[int nRow] = {read=Get_RowHeight, write=Set_RowHeight};
	__property WideString DefinedNameByIndex[int nName] = {read=Get_DefinedNameByIndex, write=Set_DefinedNameByIndex
		};
	__property WideString SheetName[int nSheet] = {read=Get_SheetName, write=Set_SheetName};
	__property unsigned PaletteEntry[int nEntry] = {read=Get_PaletteEntry, write=Set_PaletteEntry};
	__property short ColWidthTwips[int Col] = {read=Get_ColWidthTwips, write=Set_ColWidthTwips};
	__property WideString ObjItem[int ID][short Item] = {read=Get_ObjItem, write=Set_ObjItem};
	__property WideString ObjItems[int ID] = {read=Get_ObjItems, write=Set_ObjItems};
	__property WideString ObjName[int ID] = {read=Get_ObjName, write=Set_ObjName};
	__property WideString ObjText[int ID] = {read=Get_ObjText, write=Set_ObjText};
	__property short ObjValue[int ID] = {read=Get_ObjValue, write=Set_ObjValue};
	__property Word ObjVisible[int ID] = {read=Get_ObjVisible, write=Set_ObjVisible};
	__property WideString AutoFillItems[short Index] = {read=Get_AutoFillItems, write=Set_AutoFillItems
		};
	__property Word ColHidden[int nCol] = {read=Get_ColHidden, write=Set_ColHidden};
	__property Word RowHidden[int nRow] = {read=Get_RowHidden, write=Set_RowHidden};
	__property Word SheetSelected[int nSheet] = {read=Get_SheetSelected, write=Set_SheetSelected};
	
__published:
	__property TabStop ;
	__property Align ;
	__property DragCursor ;
	__property DragMode ;
	__property ParentShowHint ;
	__property PopupMenu ;
	__property ShowHint ;
	__property TabOrder ;
	__property Visible ;
	__property OnDragDrop ;
	__property OnDragOver ;
	__property OnEndDrag ;
	__property OnEnter ;
	__property OnExit ;
	__property OnStartDrag ;
	__property OnMouseUp ;
	__property OnMouseMove ;
	__property OnMouseDown ;
	__property OnKeyUp ;
	__property OnKeyPress ;
	__property OnKeyDown ;
	__property Graphics::TColor BackColor = {read=GetTColorProp, write=SetTColorProp, stored=false, index=3
		, nodefault};
	__property int Col = {read=GetIntegerProp, write=SetIntegerProp, stored=false, index=4, nodefault};
		
	__property int Row = {read=GetIntegerProp, write=SetIntegerProp, stored=false, index=5, nodefault};
		
	__property short ShowHScrollBar = {read=GetSmallintProp, write=SetSmallintProp, stored=false, index=6
		, nodefault};
	__property WideString Text = {read=GetWideStringProp, write=SetWideStringProp, stored=false, index=7
		};
	__property double Number = {read=GetDoubleProp, write=SetDoubleProp, stored=false, index=8};
	__property WideString Formula = {read=GetWideStringProp, write=SetWideStringProp, stored=false, index=9
		};
	__property int FixedCol = {read=GetIntegerProp, write=SetIntegerProp, stored=false, index=10, nodefault
		};
	__property int FixedCols = {read=GetIntegerProp, write=SetIntegerProp, stored=false, index=11, nodefault
		};
	__property int FixedRow = {read=GetIntegerProp, write=SetIntegerProp, stored=false, index=12, nodefault
		};
	__property int FixedRows = {read=GetIntegerProp, write=SetIntegerProp, stored=false, index=13, nodefault
		};
	__property Word ShowGridLines = {read=GetWordBoolProp, write=SetWordBoolProp, stored=false, index=14
		, nodefault};
	__property Word ShowRowHeading = {read=GetWordBoolProp, write=SetWordBoolProp, stored=false, index=15
		, nodefault};
	__property short ShowSelections = {read=GetSmallintProp, write=SetSmallintProp, stored=false, index=16
		, nodefault};
	__property int LeftCol = {read=GetIntegerProp, write=SetIntegerProp, stored=false, index=17, nodefault
		};
	__property int MaxCol = {read=GetIntegerProp, write=SetIntegerProp, stored=false, index=18, nodefault
		};
	__property int MaxRow = {read=GetIntegerProp, write=SetIntegerProp, stored=false, index=19, nodefault
		};
	__property int TopRow = {read=GetIntegerProp, write=SetIntegerProp, stored=false, index=20, nodefault
		};
	__property Word AllowResize = {read=GetWordBoolProp, write=SetWordBoolProp, stored=false, index=21, 
		nodefault};
	__property Word AllowSelections = {read=GetWordBoolProp, write=SetWordBoolProp, stored=false, index=22
		, nodefault};
	__property Word AllowFormulas = {read=GetWordBoolProp, write=SetWordBoolProp, stored=false, index=23
		, nodefault};
	__property Word AllowInCellEditing = {read=GetWordBoolProp, write=SetWordBoolProp, stored=false, index=24
		, nodefault};
	__property short ShowVScrollBar = {read=GetSmallintProp, write=SetSmallintProp, stored=false, index=25
		, nodefault};
	__property Word AllowFillRange = {read=GetWordBoolProp, write=SetWordBoolProp, stored=false, index=26
		, nodefault};
	__property Word AllowMoveRange = {read=GetWordBoolProp, write=SetWordBoolProp, stored=false, index=27
		, nodefault};
	__property int SelStartCol = {read=GetIntegerProp, write=SetIntegerProp, stored=false, index=28, nodefault
		};
	__property int SelStartRow = {read=GetIntegerProp, write=SetIntegerProp, stored=false, index=29, nodefault
		};
	__property int SelEndCol = {read=GetIntegerProp, write=SetIntegerProp, stored=false, index=30, nodefault
		};
	__property int SelEndRow = {read=GetIntegerProp, write=SetIntegerProp, stored=false, index=31, nodefault
		};
	__property Graphics::TColor ExtraColor = {read=GetTColorProp, write=SetTColorProp, stored=false, index=32
		, nodefault};
	__property WideString FileName = {read=GetWideStringProp, write=SetWideStringProp, stored=false, index=33
		};
	__property Word AutoRecalc = {read=GetWordBoolProp, write=SetWordBoolProp, stored=false, index=34, 
		nodefault};
	__property Word PrintGridLines = {read=GetWordBoolProp, write=SetWordBoolProp, stored=false, index=35
		, nodefault};
	__property Word PrintRowHeading = {read=GetWordBoolProp, write=SetWordBoolProp, stored=false, index=36
		, nodefault};
	__property Word PrintHCenter = {read=GetWordBoolProp, write=SetWordBoolProp, stored=false, index=37
		, nodefault};
	__property Word PrintVCenter = {read=GetWordBoolProp, write=SetWordBoolProp, stored=false, index=38
		, nodefault};
	__property Word PrintLeftToRight = {read=GetWordBoolProp, write=SetWordBoolProp, stored=false, index=39
		, nodefault};
	__property WideString PrintHeader = {read=GetWideStringProp, write=SetWideStringProp, stored=false, 
		index=40};
	__property WideString PrintFooter = {read=GetWideStringProp, write=SetWideStringProp, stored=false, 
		index=41};
	__property double PrintLeftMargin = {read=GetDoubleProp, write=SetDoubleProp, stored=false, index=42
		};
	__property double PrintTopMargin = {read=GetDoubleProp, write=SetDoubleProp, stored=false, index=43
		};
	__property double PrintRightMargin = {read=GetDoubleProp, write=SetDoubleProp, stored=false, index=44
		};
	__property double PrintBottomMargin = {read=GetDoubleProp, write=SetDoubleProp, stored=false, index=45
		};
	__property WideString PrintArea = {read=GetWideStringProp, write=SetWideStringProp, stored=false, index=46
		};
	__property WideString PrintTitles = {read=GetWideStringProp, write=SetWideStringProp, stored=false, 
		index=47};
	__property Word PrintNoColor = {read=GetWordBoolProp, write=SetWordBoolProp, stored=false, index=48
		, nodefault};
	__property WideString Selection = {read=GetWideStringProp, write=SetWideStringProp, stored=false, index=49
		};
	__property WideString TableName = {read=GetWideStringProp, write=SetWideStringProp, stored=false, index=50
		};
	__property Word DoCancelEdit = {read=GetWordBoolProp, write=SetWordBoolProp, stored=false, index=51
		, nodefault};
	__property Word DoSelChange = {read=GetWordBoolProp, write=SetWordBoolProp, stored=false, index=52, 
		nodefault};
	__property Word DoStartEdit = {read=GetWordBoolProp, write=SetWordBoolProp, stored=false, index=53, 
		nodefault};
	__property Word DoEndEdit = {read=GetWordBoolProp, write=SetWordBoolProp, stored=false, index=54, nodefault
		};
	__property Word DoStartRecalc = {read=GetWordBoolProp, write=SetWordBoolProp, stored=false, index=55
		, nodefault};
	__property Word DoEndRecalc = {read=GetWordBoolProp, write=SetWordBoolProp, stored=false, index=56, 
		nodefault};
	__property Word DoClick = {read=GetWordBoolProp, write=SetWordBoolProp, stored=false, index=57, nodefault
		};
	__property Word DoDblClick = {read=GetWordBoolProp, write=SetWordBoolProp, stored=false, index=58, 
		nodefault};
	__property Word ShowColHeading = {read=GetWordBoolProp, write=SetWordBoolProp, stored=false, index=59
		, nodefault};
	__property Word PrintColHeading = {read=GetWordBoolProp, write=SetWordBoolProp, stored=false, index=60
		, nodefault};
	__property WideString Entry = {read=GetWideStringProp, write=SetWideStringProp, stored=false, index=61
		};
	__property Word Repaint = {read=GetWordBoolProp, write=SetWordBoolProp, stored=false, index=62, nodefault
		};
	__property Word AllowArrows = {read=GetWordBoolProp, write=SetWordBoolProp, stored=false, index=63, 
		nodefault};
	__property Word AllowTabs = {read=GetWordBoolProp, write=SetWordBoolProp, stored=false, index=64, nodefault
		};
	__property WideString FormattedText = {read=GetWideStringProp, write=SetWideStringProp, stored=false
		, index=65};
	__property Word RowMode = {read=GetWordBoolProp, write=SetWordBoolProp, stored=false, index=66, nodefault
		};
	__property Word AllowDelete = {read=GetWordBoolProp, write=SetWordBoolProp, stored=false, index=67, 
		nodefault};
	__property Word EnableProtection = {read=GetWordBoolProp, write=SetWordBoolProp, stored=false, index=68
		, nodefault};
	__property int MinCol = {read=GetIntegerProp, write=SetIntegerProp, stored=false, index=69, nodefault
		};
	__property int MinRow = {read=GetIntegerProp, write=SetIntegerProp, stored=false, index=70, nodefault
		};
	__property Word DoTopLeftChanged = {read=GetWordBoolProp, write=SetWordBoolProp, stored=false, index=71
		, nodefault};
	__property Word AllowEditHeaders = {read=GetWordBoolProp, write=SetWordBoolProp, stored=false, index=72
		, nodefault};
	__property Word DoObjClick = {read=GetWordBoolProp, write=SetWordBoolProp, stored=false, index=73, 
		nodefault};
	__property Word DoObjDblClick = {read=GetWordBoolProp, write=SetWordBoolProp, stored=false, index=74
		, nodefault};
	__property Word AllowObjSelections = {read=GetWordBoolProp, write=SetWordBoolProp, stored=false, index=75
		, nodefault};
	__property Word DoRClick = {read=GetWordBoolProp, write=SetWordBoolProp, stored=false, index=76, nodefault
		};
	__property Word DoRDblClick = {read=GetWordBoolProp, write=SetWordBoolProp, stored=false, index=77, 
		nodefault};
	__property WideString Clip = {read=GetWideStringProp, write=SetWideStringProp, stored=false, index=78
		};
	__property WideString ClipValues = {read=GetWideStringProp, write=SetWideStringProp, stored=false, 
		index=79};
	__property Word PrintLandscape = {read=GetWordBoolProp, write=SetWordBoolProp, stored=false, index=80
		, nodefault};
	__property Word Enabled = {read=GetWordBoolProp, write=SetWordBoolProp, stored=false, index=-514, nodefault
		};
	__property short BorderStyle = {read=GetSmallintProp, write=SetSmallintProp, stored=false, index=-504
		, nodefault};
	__property WideString AppName = {read=GetWideStringProp, write=SetWideStringProp, stored=false, index=81
		};
	__property short HdrHeight = {read=GetSmallintProp, write=SetSmallintProp, stored=false, index=82, 
		nodefault};
	__property short HdrWidth = {read=GetSmallintProp, write=SetSmallintProp, stored=false, index=83, nodefault
		};
	__property WideString NumberFormat = {read=GetWideStringProp, write=SetWideStringProp, stored=false
		, index=84};
	__property WideString TopLeftText = {read=GetWideStringProp, write=SetWideStringProp, stored=false, 
		index=85};
	__property Word EnterMovesDown = {read=GetWordBoolProp, write=SetWordBoolProp, stored=false, index=86
		, nodefault};
	__property int LastCol = {read=GetIntegerProp, write=SetIntegerProp, stored=false, index=87, nodefault
		};
	__property int LastRow = {read=GetIntegerProp, write=SetIntegerProp, stored=false, index=88, nodefault
		};
	__property Word Logical = {read=GetWordBoolProp, write=SetWordBoolProp, stored=false, index=89, nodefault
		};
	__property short Mode = {read=GetSmallintProp, write=SetSmallintProp, stored=false, index=90, nodefault
		};
	__property short PolyEditMode = {read=GetSmallintProp, write=SetSmallintProp, stored=false, index=91
		, nodefault};
	__property short ViewScale = {read=GetSmallintProp, write=SetSmallintProp, stored=false, index=92, 
		nodefault};
	__property short SelectionCount = {read=GetSmallintProp, write=SetSmallintProp, stored=false, index=93
		, nodefault};
	__property WideString Title = {read=GetWideStringProp, write=SetWideStringProp, stored=false, index=94
		};
	__property short Type_ = {read=GetSmallintProp, write=SetSmallintProp, stored=false, index=95, nodefault
		};
	__property Word ShowFormulas = {read=GetWordBoolProp, write=SetWordBoolProp, stored=false, index=96
		, nodefault};
	__property Word ShowZeroValues = {read=GetWordBoolProp, write=SetWordBoolProp, stored=false, index=97
		, nodefault};
	__property short MousePointer = {read=GetSmallintProp, write=SetSmallintProp, stored=false, index=2
		, nodefault};
	__property Graphics::TPicture* MouseIcon = {read=GetTPictureProp, write=SetTPictureProp, stored=false
		, index=98};
	__property Word DoObjValueChanged = {read=GetWordBoolProp, write=SetWordBoolProp, stored=false, index=99
		, nodefault};
	__property Word ScrollToLastRC = {read=GetWordBoolProp, write=SetWordBoolProp, stored=false, index=100
		, nodefault};
	__property Word Modified = {read=GetWordBoolProp, write=SetWordBoolProp, stored=false, index=101, nodefault
		};
	__property Word DoObjGotFocus = {read=GetWordBoolProp, write=SetWordBoolProp, stored=false, index=102
		, nodefault};
	__property Word DoObjLostFocus = {read=GetWordBoolProp, write=SetWordBoolProp, stored=false, index=103
		, nodefault};
	__property int PrintDevMode = {read=GetIntegerProp, write=SetIntegerProp, stored=false, index=104, 
		nodefault};
	__property int NumSheets = {read=GetIntegerProp, write=SetIntegerProp, stored=false, index=105, nodefault
		};
	__property int Sheet = {read=GetIntegerProp, write=SetIntegerProp, stored=false, index=106, nodefault
		};
	__property short ColWidthUnits = {read=GetSmallintProp, write=SetSmallintProp, stored=false, index=107
		, nodefault};
	__property Word ShowTypeMarkers = {read=GetWordBoolProp, write=SetWordBoolProp, stored=false, index=108
		, nodefault};
	__property short ShowTabs = {read=GetSmallintProp, write=SetSmallintProp, stored=false, index=109, 
		nodefault};
	__property Word ShowEditBar = {read=GetWordBoolProp, write=SetWordBoolProp, stored=false, index=110
		, nodefault};
	__property Word ShowEditBarCellRef = {read=GetWordBoolProp, write=SetWordBoolProp, stored=false, index=111
		, nodefault};
	__property Word AllowDesigner = {read=GetWordBoolProp, write=SetWordBoolProp, stored=false, index=1
		, nodefault};
	__property int hWnd = {read=GetIntegerProp, write=SetIntegerProp, stored=false, index=-515, nodefault
		};
	__property Word AllowAutoFill = {read=GetWordBoolProp, write=SetWordBoolProp, stored=false, index=112
		, nodefault};
	__property TF1BookClick OnClick = {read=FOnClick, write=FOnClick};
	__property TF1BookDblClick OnDblClick = {read=FOnDblClick, write=FOnDblClick};
	__property Classes::TNotifyEvent OnCancelEdit = {read=FOnCancelEdit, write=FOnCancelEdit};
	__property Classes::TNotifyEvent OnSelChange = {read=FOnSelChange, write=FOnSelChange};
	__property TF1BookStartEdit OnStartEdit = {read=FOnStartEdit, write=FOnStartEdit};
	__property TF1BookEndEdit OnEndEdit = {read=FOnEndEdit, write=FOnEndEdit};
	__property Classes::TNotifyEvent OnStartRecalc = {read=FOnStartRecalc, write=FOnStartRecalc};
	__property Classes::TNotifyEvent OnEndRecalc = {read=FOnEndRecalc, write=FOnEndRecalc};
	__property Classes::TNotifyEvent OnTopLeftChanged = {read=FOnTopLeftChanged, write=FOnTopLeftChanged
		};
	__property TF1BookObjClick OnObjClick = {read=FOnObjClick, write=FOnObjClick};
	__property TF1BookObjDblClick OnObjDblClick = {read=FOnObjDblClick, write=FOnObjDblClick};
	__property TF1BookRClick OnRClick = {read=FOnRClick, write=FOnRClick};
	__property TF1BookRDblClick OnRDblClick = {read=FOnRDblClick, write=FOnRDblClick};
	__property TF1BookObjValueChanged OnObjValueChanged = {read=FOnObjValueChanged, write=FOnObjValueChanged
		};
	__property Classes::TNotifyEvent OnModified = {read=FOnModified, write=FOnModified};
	__property TF1BookObjGotFocus OnObjGotFocus = {read=FOnObjGotFocus, write=FOnObjGotFocus};
	__property TF1BookObjLostFocus OnObjLostFocus = {read=FOnObjLostFocus, write=FOnObjLostFocus};
	__property TF1BookValidationFailed OnValidationFailed = {read=FOnValidationFailed, write=FOnValidationFailed
		};
public:
	#pragma option push -w-inl
	/* TOleControl.Create */ inline __fastcall virtual TF1Book(Classes::TComponent* AOwner) : Olectrls::TOleControl(
		AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TOleControl.Destroy */ inline __fastcall virtual ~TF1Book(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TF1Book(HWND ParentWindow) : Olectrls::TOleControl(
		ParentWindow) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------
static const Shortint VCIF1LibMajorVersion = 0x1;
static const Shortint VCIF1LibMinorVersion = 0x0;
extern PACKAGE GUID LIBID_VCIF1Lib;
extern PACKAGE GUID DIID__DVCF1;
extern PACKAGE GUID DIID__DVCF1Events;
extern PACKAGE GUID CLASS_F1Book;
static const Shortint F1ColWidthUnitsCharacters = 0x0;
static const Shortint F1ColWidthUnitsTwips = 0x1;
static const Shortint F1Default = 0x0;
static const Shortint F1Arrow = 0x1;
static const Shortint F1Cross = 0x2;
static const Shortint F1IBeam = 0x3;
static const Shortint F1Icon = 0x4;
static const Shortint F1Size = 0x5;
static const Shortint F1SizeNESW = 0x6;
static const Shortint F1SizeNS = 0x7;
static const Shortint F1SizeNWSE = 0x8;
static const Shortint F1SizeWE = 0x9;
static const Shortint F1UpArrow = 0xa;
static const Shortint F1Hourglass = 0xb;
static const Shortint F1NoDrop = 0xc;
static const Shortint F1Custom = 0xd;
static const Shortint F1Off = 0x0;
static const Shortint F1On = 0x1;
static const Shortint F1Auto = 0x2;
static const Shortint F1TabsOff = 0x0;
static const Shortint F1TabsBottom = 0x1;
static const Shortint F1TabsTop = 0x2;
static const Shortint F1ModeNormal = 0x0;
static const Shortint F1ModeLine = 0x1;
static const Shortint F1ModeRectangle = 0x2;
static const Shortint F1ModeOval = 0x3;
static const Shortint F1ModeArc = 0x4;
static const Shortint F1ModeChart = 0x5;
static const Shortint F1ModeField = 0x6;
static const Shortint F1ModeButton = 0x7;
static const Shortint F1ModePolygon = 0x8;
static const Shortint F1ModeCheckBox = 0x9;
static const Shortint F1ModeDropDown = 0xa;
static const Shortint F1PolyEditModeNormal = 0x0;
static const Shortint F1PolyEditModePoints = 0x1;
static const Shortint F1ShiftHorizontal = 0x1;
static const Shortint F1ShiftVertical = 0x2;
static const Shortint F1ShiftRows = 0x3;
static const Shortint F1ShiftCols = 0x4;
static const Shortint F1HAlignGeneral = 0x1;
static const Shortint F1HAlignLeft = 0x2;
static const Shortint F1HAlignCenter = 0x3;
static const Shortint F1HAlignRight = 0x4;
static const Shortint F1HAlignFill = 0x5;
static const Shortint F1HAlignJustify = 0x6;
static const Shortint F1HAlignCenterAcrossCells = 0x7;
static const Shortint F1VAlignTop = 0x1;
static const Shortint F1VAlignCenter = 0x2;
static const Shortint F1VAlignBottom = 0x3;
static const Shortint F1ClearDlg = 0x0;
static const Shortint F1ClearAll = 0x1;
static const Shortint F1ClearFormats = 0x2;
static const Shortint F1ClearValues = 0x3;
static const Shortint F1FileFormulaOne = 0x1;
static const Shortint F1FileExcel4 = 0x2;
static const Shortint F1FileTabbedText = 0x3;
static const Shortint F1FileExcel5 = 0x4;
static const Shortint F1FileFormulaOne3 = 0x5;
static const Shortint F1FileTabbedTextValuesOnly = 0x6;
static const Shortint F1ObjLine = 0x1;
static const Shortint F1ObjRectangle = 0x2;
static const Shortint F1ObjOval = 0x3;
static const Shortint F1ObjArc = 0x4;
static const Shortint F1ObjChart = 0x5;
static const Shortint F1ObjButton = 0x7;
static const Shortint F1ObjPolygon = 0x8;
static const Shortint F1ObjCheckBox = 0x9;
static const Shortint F1ObjDropDown = 0xa;
static const Shortint F1ObjPicture = 0xb;
static const Shortint F1ErrorNone = 0x0;
static const Word F1ErrorGeneral = 0x4e21;
static const Word F1ErrorBadArgument = 0x4e22;
static const Word F1ErrorNoMemory = 0x4e23;
static const Word F1ErrorBadFormula = 0x4e24;
static const Word F1ErrorBufTooShort = 0x4e25;
static const Word F1ErrorNotFound = 0x4e26;
static const Word F1ErrorBadRC = 0x4e27;
static const Word F1ErrorBadHSS = 0x4e28;
static const Word F1ErrorTooManyHSS = 0x4e29;
static const Word F1ErrorNoTable = 0x4e2a;
static const Word F1ErrorUnableToOpenFile = 0x4e2b;
static const Word F1ErrorInvalidFile = 0x4e2c;
static const Word F1ErrorInsertShiftOffTable = 0x4e2d;
static const Word F1ErrorOnlyOneRange = 0x4e2e;
static const Word F1ErrorNothingToPaste = 0x4e2f;
static const Word F1ErrorBadNumberFormat = 0x4e30;
static const Word F1ErrorTooManyFonts = 0x4e31;
static const Word F1ErrorTooManySelectedRanges = 0x4e32;
static const Word F1ErrorUnableToWriteFile = 0x4e33;
static const Word F1ErrorNoTransaction = 0x4e34;
static const Word F1ErrorNothingToPrint = 0x4e35;
static const Word F1ErrorPrintMarginsDontFit = 0x4e36;
static const Word F1ErrorCancel = 0x4e37;
static const Word F1ErrorUnableToInitializePrinter = 0x4e38;
static const Word F1ErrorStringTooLong = 0x4e39;
static const Word F1ErrorFormulaTooLong = 0x4e3a;
static const Word F1ErrorUnableToOpenClipboard = 0x4e3b;
static const Word F1ErrorPasteWouldOverflowSheet = 0x4e3c;
static const Word F1ErrorLockedCellsCannotBeModified = 0x4e3d;
static const Word F1ErrorLockedDocCannotBeModified = 0x4e3e;
static const Word F1ErrorInvalidName = 0x4e3f;
static const Word F1ErrorCannotDeleteNameInUse = 0x4e40;
static const Word F1ErrorUnableToFindName = 0x4e41;
static const Word F1ErrorNoWindow = 0x4e42;
static const Word F1ErrorSelection = 0x4e43;
static const Word F1ErrorTooManyObjects = 0x4e44;
static const Word F1ErrorInvalidObjectType = 0x4e45;
static const Word F1ErrorObjectNotFound = 0x4e46;
static const Word F1ErrorInvalidRequest = 0x4e47;
static const Word F1ErrorBadValidationRule = 0x4e48;
static const Word F1ErrorBadInputMask = 0x4e49;
static const Word F1ErrorValidationFailed = 0x4e4a;
static const Word F1ErrorNoODBCConnection = 0x4e4b;
static const Word F1ErrorUnableToLoadODBC = 0x4e4c;
static const Word F1ErrorUnsupportedFeature = 0x4e4d;
static const Shortint F1ControlNoCell = 0x0;
static const Shortint F1ControlCellValue = 0x1;
static const Shortint F1ControlCellText = 0x2;
extern PACKAGE void __fastcall Register(void);

}	/* namespace Vcf1 */
#if !defined(NO_IMPLICIT_NAMESPACE_USE)
using namespace Vcf1;
#endif
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// vcf1
