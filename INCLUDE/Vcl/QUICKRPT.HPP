// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'QuickRpt.pas' rev: 6.00

#ifndef QuickRptHPP
#define QuickRptHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <QRExpBld.hpp>	// Pascal unit
#include <QRExpr.hpp>	// Pascal unit
#include <QRPrgres.hpp>	// Pascal unit
#include <QR3Const.hpp>	// Pascal unit
#include <QRPrntr.hpp>	// Pascal unit
#include <DBTables.hpp>	// Pascal unit
#include <DB.hpp>	// Pascal unit
#include <Printers.hpp>	// Pascal unit
#include <Dialogs.hpp>	// Pascal unit
#include <ExtCtrls.hpp>	// Pascal unit
#include <Forms.hpp>	// Pascal unit
#include <Buttons.hpp>	// Pascal unit
#include <Graphics.hpp>	// Pascal unit
#include <SysUtils.hpp>	// Pascal unit
#include <StdCtrls.hpp>	// Pascal unit
#include <Controls.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Quickrpt
{
//-- type declarations -------------------------------------------------------
typedef TMetaClass*TQRNewComponentClass;

typedef void __fastcall (__closure *TQROnNeedDataEvent)(System::TObject* Sender, bool &MoreData);

#pragma option push -b-
enum TQRNotifyOperation { qrMasterDataAdvance, qrBandPrinted, qrBandSizeChange };
#pragma option pop

typedef void __fastcall (__closure *TQRNotifyOperationEvent)(System::TObject* Sender, TQRNotifyOperation Operation);

class DELPHICLASS TQRCustomController;
class DELPHICLASS TCustomQuickRep;
class DELPHICLASS TQRBasePanel;
class DELPHICLASS TQRFrame;
class PASCALIMPLEMENTATION TQRFrame : public Classes::TPersistent 
{
	typedef Classes::TPersistent inherited;
	
private:
	Graphics::TColor FColor;
	bool FBottom;
	bool FLeft;
	Controls::TControl* FParent;
	Graphics::TPenStyle FPenStyle;
	bool FRight;
	bool FTop;
	int FWidth;
	void __fastcall SetColor(Graphics::TColor Value);
	void __fastcall SetParent(Controls::TControl* Value);
	void __fastcall SetStyle(Graphics::TPenStyle Value);
	void __fastcall SetValue(int index, bool Value);
	void __fastcall SetWidth(int Value);
	
protected:
	void __fastcall PaintIt(Graphics::TCanvas* ACanvas, const Types::TRect &ARect, Extended XFact, Extended YFact);
	void __fastcall SetPen(Graphics::TPen* aPen);
	
public:
	__fastcall TQRFrame(void);
	bool __fastcall AnyFrame(void);
	__property Controls::TControl* Parent = {read=FParent, write=SetParent};
	
__published:
	__property Graphics::TColor Color = {read=FColor, write=SetColor, nodefault};
	__property bool DrawTop = {read=FTop, write=SetValue, index=0, nodefault};
	__property bool DrawBottom = {read=FBottom, write=SetValue, index=1, nodefault};
	__property bool DrawLeft = {read=FLeft, write=SetValue, index=2, nodefault};
	__property bool DrawRight = {read=FRight, write=SetValue, index=3, nodefault};
	__property Graphics::TPenStyle Style = {read=FPenStyle, write=SetStyle, default=0};
	__property int Width = {read=FWidth, write=SetWidth, default=1};
public:
	#pragma option push -w-inl
	/* TPersistent.Destroy */ inline __fastcall virtual ~TQRFrame(void) { }
	#pragma option pop
	
};


#pragma option push -b-
enum TQRUnit { MM, Inches, Pixels, Characters, Native };
#pragma option pop

class PASCALIMPLEMENTATION TQRBasePanel : public Extctrls::TCustomPanel 
{
	typedef Extctrls::TCustomPanel inherited;
	
private:
	int FFontSize;
	int FZoom;
	TQRFrame* FFrame;
	TQRFrame* __fastcall GetFrame(void);
	void __fastcall SetFrame(TQRFrame* Value);
	
protected:
	virtual void __fastcall SetZoom(int Value);
	virtual void __fastcall Paint(void);
	virtual void __fastcall PaintRuler(TQRUnit Units);
	void __fastcall PrepareComponents(void);
	void __fastcall UnprepareComponents(void);
	virtual void __fastcall CreateParams(Controls::TCreateParams &Params);
	
public:
	__fastcall virtual TQRBasePanel(Classes::TComponent* AOwner);
	__fastcall virtual ~TQRBasePanel(void);
	__property int Zoom = {read=FZoom, write=SetZoom, nodefault};
	__property int FontSize = {read=FFontSize, write=FFontSize, nodefault};
	
__published:
	__property TQRFrame* Frame = {read=GetFrame, write=SetFrame};
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TQRBasePanel(HWND ParentWindow) : Extctrls::TCustomPanel(ParentWindow) { }
	#pragma option pop
	
};


class DELPHICLASS TQRCreateReportThread;
class PASCALIMPLEMENTATION TQRCreateReportThread : public Classes::TThread 
{
	typedef Classes::TThread inherited;
	
private:
	Qrprntr::TQRPrinter* FQRPrinter;
	TCustomQuickRep* FQuickRep;
	
public:
	__fastcall TQRCreateReportThread(TCustomQuickRep* AReport);
	virtual void __fastcall Execute(void);
	__property TCustomQuickRep* QuickRep = {read=FQuickRep, write=FQuickRep};
public:
	#pragma option push -w-inl
	/* TThread.Destroy */ inline __fastcall virtual ~TQRCreateReportThread(void) { }
	#pragma option pop
	
};


class DELPHICLASS TQuickRepBands;
class DELPHICLASS TQRCustomBand;
class PASCALIMPLEMENTATION TQuickRepBands : public Classes::TPersistent 
{
	typedef Classes::TPersistent inherited;
	
private:
	TCustomQuickRep* FOwner;
	TQRCustomBand* __fastcall BandInList(Qrprntr::TQRBandType BandType);
	void __fastcall SetBand(Qrprntr::TQRBandType BandType, bool Value);
	TQRCustomBand* __fastcall GetBand(int Index);
	bool __fastcall GetHasBand(int Index);
	void __fastcall SetHasBand(int Index, bool Value);
	
public:
	__fastcall TQuickRepBands(TCustomQuickRep* AOwner);
	__property TQRCustomBand* TitleBand = {read=GetBand, index=1};
	__property TQRCustomBand* PageHeaderBand = {read=GetBand, index=2};
	__property TQRCustomBand* ColumnHeaderBand = {read=GetBand, index=3};
	__property TQRCustomBand* DetailBand = {read=GetBand, index=4};
	__property TQRCustomBand* ColumnFooterBand = {read=GetBand, index=5};
	__property TQRCustomBand* PageFooterBand = {read=GetBand, index=6};
	__property TQRCustomBand* SummaryBand = {read=GetBand, index=7};
	
__published:
	__property bool HasTitle = {read=GetHasBand, write=SetHasBand, stored=false, index=1, nodefault};
	__property bool HasPageHeader = {read=GetHasBand, write=SetHasBand, stored=false, index=2, nodefault};
	__property bool HasColumnHeader = {read=GetHasBand, write=SetHasBand, stored=false, index=3, nodefault};
	__property bool HasDetail = {read=GetHasBand, write=SetHasBand, stored=false, index=4, nodefault};
	__property bool HasPageFooter = {read=GetHasBand, write=SetHasBand, stored=false, index=6, nodefault};
	__property bool HasSummary = {read=GetHasBand, write=SetHasBand, stored=false, index=7, nodefault};
public:
	#pragma option push -w-inl
	/* TPersistent.Destroy */ inline __fastcall virtual ~TQuickRepBands(void) { }
	#pragma option pop
	
};


typedef void __fastcall (__closure *TQRReportBeforePrintEvent)(TCustomQuickRep* Sender, bool &PrintReport);

typedef void __fastcall (__closure *TQRNotifyEvent)(TCustomQuickRep* Sender);

#pragma option push -b-
enum TQuickReportOption { FirstPageHeader, LastPageFooter, Compression };
#pragma option pop

typedef Set<TQuickReportOption, FirstPageHeader, Compression>  TQuickReportOptions;

class DELPHICLASS TQRPage;
class DELPHICLASS TQRUnitBase;
class PASCALIMPLEMENTATION TQRUnitBase : public Classes::TPersistent 
{
	typedef Classes::TPersistent inherited;
	
private:
	int FResolution;
	TQRUnit FUnits;
	TQRUnit SavedUnits;
	TCustomQuickRep* FParentReport;
	bool FParentUpdating;
	int FZoom;
	virtual Extended __fastcall LoadUnit(Extended Value, TQRUnit aUnit, bool Horizontal);
	virtual Extended __fastcall SaveUnit(Extended Value, TQRUnit aUnit, bool Horizontal);
	
protected:
	virtual TQRUnit __fastcall GetUnits(void);
	virtual void __fastcall DefineProperties(Classes::TFiler* Filer);
	virtual void __fastcall Loaded(void);
	virtual void __fastcall ReadValues(Classes::TReader* Reader);
	virtual void __fastcall SetParentSizes(void);
	virtual void __fastcall SetUnits(TQRUnit Value);
	virtual void __fastcall WriteValues(Classes::TWriter* Writer);
	void __fastcall SetPixels(void);
	void __fastcall RestoreUnit(void);
	
public:
	__fastcall TQRUnitBase(void);
	__property TCustomQuickRep* ParentReport = {read=FParentReport, write=FParentReport};
	__property bool ParentUpdating = {read=FParentUpdating, write=FParentUpdating, nodefault};
	__property int Resolution = {read=FResolution, nodefault};
	__property TQRUnit Units = {read=GetUnits, write=SetUnits, nodefault};
	__property int Zoom = {read=FZoom, write=FZoom, nodefault};
public:
	#pragma option push -w-inl
	/* TPersistent.Destroy */ inline __fastcall virtual ~TQRUnitBase(void) { }
	#pragma option pop
	
};


#pragma option push -b-
enum TQRPrintOrder { ColByCol, RowByRow };
#pragma option pop

class PASCALIMPLEMENTATION TQRPage : public TQRUnitBase 
{
	typedef TQRUnitBase inherited;
	
private:
	Extended FBottomMargin;
	Extended FColumnSpace;
	int FColumns;
	Extended FLeftMargin;
	Extended FLength;
	Printers::TPrinterOrientation FOrientation;
	Qrprntr::TQRPaperSize FPaperSize;
	TQRPrintOrder FPrintOrder;
	Extended FRightMargin;
	bool FRuler;
	Extended FTopMargin;
	Extended FWidth;
	TCustomQuickRep* Parent;
	Qrprntr::TQRPaperSize __fastcall GetPaperSize(void);
	bool __fastcall GetRuler(void);
	Extended __fastcall GetValue(int Index);
	void __fastcall SetColumns(int Value);
	void __fastcall SetOrientation(Printers::TPrinterOrientation Value);
	void __fastcall SetPaperSize(Qrprntr::TQRPaperSize Value);
	void __fastcall SetPrintOrder(TQRPrintOrder Value);
	void __fastcall SetRuler(bool Value);
	void __fastcall SetValue(int Index, Extended Value);
	__property TQRPrintOrder PrintOrder = {read=FPrintOrder, write=SetPrintOrder, nodefault};
	
protected:
	virtual void __fastcall ReadValues(Classes::TReader* Reader);
	virtual void __fastcall SetParentSizes(void);
	virtual void __fastcall SetUnits(TQRUnit Value);
	virtual void __fastcall WriteValues(Classes::TWriter* Writer);
	void __fastcall FixZoom(void);
	
public:
	__fastcall TQRPage(TCustomQuickRep* AParent);
	
__published:
	__property Extended BottomMargin = {read=GetValue, write=SetValue, stored=false, index=0};
	__property Extended ColumnSpace = {read=GetValue, write=SetValue, stored=false, index=6};
	__property int Columns = {read=FColumns, write=SetColumns, nodefault};
	__property Extended LeftMargin = {read=GetValue, write=SetValue, stored=false, index=4};
	__property Extended Length = {read=GetValue, write=SetValue, stored=false, index=1};
	__property Printers::TPrinterOrientation Orientation = {read=FOrientation, write=SetOrientation, nodefault};
	__property Qrprntr::TQRPaperSize PaperSize = {read=GetPaperSize, write=SetPaperSize, nodefault};
	__property Extended RightMargin = {read=GetValue, write=SetValue, stored=false, index=5};
	__property bool Ruler = {read=GetRuler, write=SetRuler, default=1};
	__property Extended TopMargin = {read=GetValue, write=SetValue, stored=false, index=2};
	__property Extended Width = {read=GetValue, write=SetValue, stored=false, index=3};
public:
	#pragma option push -w-inl
	/* TPersistent.Destroy */ inline __fastcall virtual ~TQRPage(void) { }
	#pragma option pop
	
};


class DELPHICLASS TQuickRepPrinterSettings;
class PASCALIMPLEMENTATION TQuickRepPrinterSettings : public Qrprntr::TQRPrinterSettings 
{
	typedef Qrprntr::TQRPrinterSettings inherited;
	
__published:
	__property Copies ;
	__property Duplex ;
	__property FirstPage ;
	__property LastPage ;
	__property OutputBin ;
public:
	#pragma option push -w-inl
	/* TQRPrinterSettings.Create */ inline __fastcall TQuickRepPrinterSettings(void) : Qrprntr::TQRPrinterSettings() { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TPersistent.Destroy */ inline __fastcall virtual ~TQuickRepPrinterSettings(void) { }
	#pragma option pop
	
};


#pragma option push -b-
enum TQRState { qrAvailable, qrPrepare, qrPreview, qrPrint, qrEdit };
#pragma option pop

class DELPHICLASS TQRBand;
class DELPHICLASS TQRPrintable;
class PASCALIMPLEMENTATION TCustomQuickRep : public TQRBasePanel 
{
	typedef TQRBasePanel inherited;
	
private:
	TQRCreateReportThread* BGThread;
	Classes::TList* BandRegList;
	Classes::TList* FAllDataSets;
	Qrprntr::TQRAfterPrintEvent FAfterPrintEvent;
	Qrprntr::TQRAfterPreviewEvent FAfterPreviewEvent;
	bool FAvailable;
	Classes::TList* FBandList;
	TQuickRepBands* FBands;
	TQRReportBeforePrintEvent FBeforePrintEvent;
	bool FCancelled;
	TQRCustomController* FController;
	int FColumnTopPosition;
	int FCurrentColumn;
	int FCurrentX;
	int FCurrentY;
	Classes::TStrings* FDescription;
	Qrexpr::TQREvEnvironment* FEnvironment;
	Qrprntr::TQRExportFilter* FExportFilter;
	bool FExporting;
	bool FFinalPass;
	bool FHideBands;
	bool FLastPage;
	bool FModified;
	TQRNotifyEvent FOnEndPageEvent;
	TQROnNeedDataEvent FOnNeedDataEvent;
	Classes::TNotifyEvent FOnPreviewEvent;
	TQRNotifyEvent FOnStartPageEvent;
	TQuickReportOptions FOptions;
	TQRPage* FPage;
	Graphics::TMetafile* FPreviewPage;
	int FPageCount;
	Extended FPageFooterSize;
	TQuickRepPrinterSettings* FPrinterSettings;
	AnsiString FReportTitle;
	int FRotateBands;
	bool FShowProgress;
	bool FSnapToGrid;
	TQRState FState;
	Qrprntr::TQRPrinter* FQRPrinter;
	bool NewColumnForced;
	bool NewPageForced;
	unsigned ReferenceDC;
	bool PreparingDesignTime;
	Qrexpr::TQREvElement* EvPageNumber;
	Qrexpr::TQREvElement* EvColumnNumber;
	Qrexpr::TQREvElement* EvReportTitle;
	bool NoForceNewPage;
	TQRUnit __fastcall GetUnits(void);
	bool __fastcall GetPrintIfEmpty(void);
	void __fastcall PrintBand(TQRCustomBand* ABand);
	void __fastcall PrintPageBackground(void);
	void __fastcall SetExportFilter(Qrprntr::TQRExportFilter* Value);
	virtual void __fastcall SetUnits(TQRUnit Value);
	void __fastcall SetDescription(Classes::TStrings* Value);
	void __fastcall SetPrinterValues(void);
	void __fastcall SetController(TQRCustomController* Value);
	
protected:
	virtual void __fastcall Execute(void);
	MESSAGE void __fastcall CMPageAvailable(Qrprntr::TCM_QRPageAvailable &Message);
	MESSAGE void __fastcall CMPreviewClose(Qrprntr::TCM_QRPreviewClose &Message);
	MESSAGE void __fastcall CMPrint(Messages::TMessage &Message);
	int __fastcall AvailableSpace(void);
	bool __fastcall PrepareQRPrinter(void);
	virtual void __fastcall CreateReport(bool CompositeReport);
	void __fastcall ForceNewColumn(void);
	void __fastcall ForceNewPage(void);
	DYNAMIC void __fastcall GetChildren(Classes::TGetChildProc Proc, Classes::TComponent* root);
	virtual void __fastcall Loaded(void);
	virtual void __fastcall Notification(Classes::TComponent* AComponent, Classes::TOperation Operation);
	virtual void __fastcall PaintColumns(void);
	virtual void __fastcall PaintMargins(void);
	virtual void __fastcall PaintFrame(void);
	virtual void __fastcall PaintRuler(TQRUnit Units);
	void __fastcall PreviewFinished(System::TObject* Sender);
	void __fastcall PreviewIt(bool Modal);
	void __fastcall PrintFinished(System::TObject* Sender);
	void __fastcall RebuildBandList(void);
	void __fastcall RegisterBand(TQRCustomBand* aBand);
	virtual void __fastcall SetControllerBands(void);
	virtual void __fastcall SetPrintIfEmpty(bool Value);
	void __fastcall SetHideBands(bool Value);
	void __fastcall SetRotateBands(int Value);
	virtual void __fastcall SetZoom(int Value);
	__property TQRCustomController* Controller = {read=FController, write=SetController};
	
public:
	__fastcall virtual TCustomQuickRep(Classes::TComponent* AOwner);
	__fastcall virtual TCustomQuickRep(Classes::TComponent* AOwner, int Dummy);
	__fastcall virtual ~TCustomQuickRep(void);
	TQRBand* __fastcall CreateBand(Qrprntr::TQRBandType BandType);
	int __fastcall TextHeight(Graphics::TFont* aFont, AnsiString aText);
	int __fastcall TextWidth(Graphics::TFont* aFont, AnsiString aText);
	void __fastcall AddBand(TQRCustomBand* aBand);
	virtual void __fastcall AddNotifyClient(TQRPrintable* Value);
	void __fastcall Cancel(void);
	void __fastcall ExportToFilter(Qrprntr::TQRExportFilter* AFilter);
	void __fastcall EndPage(void);
	void __fastcall Modify(void);
	void __fastcall NewColumn(void);
	void __fastcall NewPage(void);
	virtual void __fastcall Paint(void);
	void __fastcall Print(void);
	void __fastcall PrintBackground(void);
	void __fastcall PrinterSetup(void);
	void __fastcall Prepare(void);
	void __fastcall Preview(void);
	void __fastcall PreviewModeless(void);
	void __fastcall PreviewModal(void);
	void __fastcall ResetPageFooterSize(void);
	void __fastcall RemoveBand(TQRCustomBand* aBand);
	void __fastcall SetBandValues(void);
	virtual void __fastcall SetBounds(int ALeft, int ATop, int AWidth, int AHeight);
	__property bool Available = {read=FAvailable, nodefault};
	__property Classes::TList* AllDataSets = {read=FAllDataSets, write=FAllDataSets};
	__property Classes::TList* BandList = {read=FBandList};
	__property bool Cancelled = {read=FCancelled, nodefault};
	__property int ColumnTopPosition = {read=FColumnTopPosition, write=FColumnTopPosition, nodefault};
	__property int CurrentColumn = {read=FCurrentColumn, nodefault};
	__property int CurrentX = {read=FCurrentX, write=FCurrentX, nodefault};
	__property int CurrentY = {read=FCurrentY, write=FCurrentY, nodefault};
	__property Qrprntr::TQRExportFilter* ExportFilter = {read=FExportFilter, write=SetExportFilter};
	__property bool Exporting = {read=FExporting, nodefault};
	__property bool FinalPass = {read=FFinalPass, nodefault};
	__property bool HideBands = {read=FHideBands, write=SetHideBands, nodefault};
	__property int PageNumber = {read=FPageCount, nodefault};
	__property Qrprntr::TQRPrinter* Printer = {read=FQRPrinter};
	__property Qrprntr::TQRPrinter* QRPrinter = {read=FQRPrinter, write=FQRPrinter};
	__property int RotateBands = {read=FRotateBands, write=SetRotateBands, nodefault};
	__property TQRState State = {read=FState, write=FState, nodefault};
	__property Qrprntr::TQRAfterPrintEvent AfterPrint = {read=FAfterPrintEvent, write=FAfterPrintEvent};
	__property Qrprntr::TQRAfterPreviewEvent AfterPreview = {read=FAfterPreviewEvent, write=FAfterPreviewEvent};
	__property TQuickRepBands* Bands = {read=FBands, write=FBands};
	__property TQRReportBeforePrintEvent BeforePrint = {read=FBeforePrintEvent, write=FBeforePrintEvent};
	__property Classes::TStrings* Description = {read=FDescription, write=SetDescription};
	__property Font ;
	__property Qrexpr::TQREvEnvironment* Functions = {read=FEnvironment, write=FEnvironment, stored=true};
	__property TQRNotifyEvent OnEndPage = {read=FOnEndPageEvent, write=FOnEndPageEvent};
	__property TQROnNeedDataEvent OnNeedData = {read=FOnNeedDataEvent, write=FOnNeedDataEvent};
	__property Classes::TNotifyEvent OnPreview = {read=FOnPreviewEvent, write=FOnPreviewEvent};
	__property TQRNotifyEvent OnStartPage = {read=FOnStartPageEvent, write=FOnStartPageEvent};
	__property TQuickReportOptions Options = {read=FOptions, write=FOptions, nodefault};
	__property TQRPage* Page = {read=FPage, write=FPage};
	__property bool PrintIfEmpty = {read=GetPrintIfEmpty, write=SetPrintIfEmpty, nodefault};
	__property TQuickRepPrinterSettings* PrinterSettings = {read=FPrinterSettings, write=FPrinterSettings};
	__property AnsiString ReportTitle = {read=FReportTitle, write=FReportTitle};
	__property bool ShowProgress = {read=FShowProgress, write=FShowProgress, default=1};
	__property bool SnapToGrid = {read=FSnapToGrid, write=FSnapToGrid, nodefault};
	__property TQRUnit Units = {read=GetUnits, write=SetUnits, stored=true, nodefault};
	__property Zoom ;
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TCustomQuickRep(HWND ParentWindow) : TQRBasePanel(ParentWindow) { }
	#pragma option pop
	
};


class PASCALIMPLEMENTATION TQRCustomController : public Classes::TComponent 
{
	typedef Classes::TComponent inherited;
	
private:
	Classes::TComponent* OrgOwner;
	Classes::TComponent* FMaster;
	Classes::TList* PrintAfterList;
	Classes::TList* PrintBeforeList;
	Classes::TList* GroupList;
	bool FPrintIfEmpty;
	Classes::TComponent* FSelfCheck;
	TCustomQuickRep* FParentReport;
	bool FPrintBefore;
	Classes::TList* NotifyList;
	Qrexpr::TQREvElement* EvConstant;
	bool __fastcall CheckGroups(void);
	void __fastcall CheckLastGroupFooters(void);
	void __fastcall NewPageCheckGroups(void);
	void __fastcall SetMaster(Classes::TComponent* Value);
	
protected:
	virtual Qrexpr::TQREvResult __fastcall LocalVarValue();
	void __fastcall AddAfter(TQRCustomController* aController);
	void __fastcall AddBefore(TQRCustomController* aController);
	virtual void __fastcall BuildTree(void);
	virtual void __fastcall Execute(void);
	void __fastcall NotifyClients(TQRNotifyOperation Operation);
	virtual void __fastcall Prepare(void);
	virtual void __fastcall Unprepare(void);
	virtual void __fastcall PrintAfterControllers(void);
	virtual void __fastcall PrintBeforeControllers(void);
	virtual void __fastcall PrintEmptyController(void);
	void __fastcall PrintGroupHeaders(void);
	void __fastcall PrintGroupFooters(void);
	virtual void __fastcall RegisterBands(void);
	virtual void __fastcall RegisterDatasets(void);
	virtual void __fastcall SetPrintBefore(bool Value);
	virtual void __fastcall UpdateLocalVar(void);
	
public:
	__fastcall virtual TQRCustomController(Classes::TComponent* AOwner);
	__fastcall virtual ~TQRCustomController(void);
	void __fastcall AddNotifyClient(TQRPrintable* Value);
	__property Classes::TComponent* Master = {read=FMaster, write=SetMaster};
	__property TCustomQuickRep* ParentReport = {read=FParentReport, write=FParentReport};
	__property bool PrintBefore = {read=FPrintBefore, write=SetPrintBefore, nodefault};
	__property bool PrintIfEmpty = {read=FPrintIfEmpty, write=FPrintIfEmpty, nodefault};
	__property Classes::TComponent* SelfCheck = {read=FSelfCheck, write=FSelfCheck};
};


class DELPHICLASS TQRController;
class PASCALIMPLEMENTATION TQRController : public TQRCustomController 
{
	typedef TQRCustomController inherited;
	
private:
	Db::TDataSet* FDataSet;
	TQRCustomBand* FDetail;
	TQRCustomBand* FFooter;
	TQRCustomBand* FHeader;
	TQROnNeedDataEvent FOnNeedDataEvent;
	int FDetailNumber;
	bool UpdateSQLParams;
	void __fastcall SetDataSet(Db::TDataSet* Value);
	
protected:
	virtual void __fastcall Notification(Classes::TComponent* AComponent, Classes::TOperation Operation);
	virtual void __fastcall Prepare(void);
	virtual void __fastcall PrintEmptyController(void);
	virtual void __fastcall RegisterBands(void);
	virtual void __fastcall RegisterDatasets(void);
	virtual void __fastcall Execute(void);
	
public:
	__property Db::TDataSet* DataSet = {read=FDataSet, write=SetDataSet};
	__property int DetailNumber = {read=FDetailNumber, nodefault};
	__property TQRCustomBand* Detail = {read=FDetail, write=FDetail};
	__property TQRCustomBand* Footer = {read=FFooter, write=FFooter};
	__property TQRCustomBand* Header = {read=FHeader, write=FHeader};
	__property TQROnNeedDataEvent OnNeedData = {read=FOnNeedDataEvent, write=FOnNeedDataEvent};
public:
	#pragma option push -w-inl
	/* TQRCustomController.Create */ inline __fastcall virtual TQRController(Classes::TComponent* AOwner) : TQRCustomController(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TQRCustomController.Destroy */ inline __fastcall virtual ~TQRController(void) { }
	#pragma option pop
	
};


class DELPHICLASS TQRBandSize;
class PASCALIMPLEMENTATION TQRBandSize : public TQRUnitBase 
{
	typedef TQRUnitBase inherited;
	
private:
	Extended FWidth;
	Extended FLength;
	TQRCustomBand* Parent;
	Extended __fastcall GetValue(int Index);
	void __fastcall SetValue(int Index, Extended Value);
	
protected:
	virtual void __fastcall ReadValues(Classes::TReader* Reader);
	virtual void __fastcall SetParentSizes(void);
	virtual void __fastcall WriteValues(Classes::TWriter* Writer);
	void __fastcall FixZoom(void);
	
public:
	__fastcall TQRBandSize(TQRCustomBand* AParent);
	__property Extended Length = {read=GetValue, write=SetValue, stored=false, index=0};
	
__published:
	__property Extended Height = {read=GetValue, write=SetValue, stored=false, index=0};
	__property Extended Width = {read=GetValue, write=SetValue, stored=false, index=1};
public:
	#pragma option push -w-inl
	/* TPersistent.Destroy */ inline __fastcall virtual ~TQRBandSize(void) { }
	#pragma option pop
	
};


typedef void __fastcall (__closure *TQRBandBeforePrintEvent)(TQRCustomBand* Sender, bool &PrintBand);

typedef void __fastcall (__closure *TQRBandAfterPrintEvent)(TQRCustomBand* Sender, bool BandPrinted);

class DELPHICLASS TQRChildBand;
class PASCALIMPLEMENTATION TQRCustomBand : public TQRBasePanel 
{
	typedef TQRBasePanel inherited;
	
private:
	#pragma pack(push, 1)
	Types::TRect BandFrameRect;
	#pragma pack(pop)
	
	bool ButtonDown;
	Extended FExpanded;
	TQRBandAfterPrintEvent FAfterPrintEvent;
	bool FAlignToBottom;
	TQRBandBeforePrintEvent FBeforePrintEvent;
	bool FEnabled;
	bool FForceNewColumn;
	bool FForceNewPage;
	TQRCustomBand* FLinkBand;
	TCustomQuickRep* FParentReport;
	bool FParentUpdating;
	Qrprntr::TQRBandType FQRBandType;
	int LoadedHeight;
	TQRBandSize* FSize;
	TQRCustomController* FNotifyController;
	void __fastcall SetLinkBand(TQRCustomBand* Value);
	TQRBandSize* __fastcall GetBandSize(void);
	bool __fastcall GetHasChild(void);
	TQRChildBand* __fastcall GetChild(void);
	void __fastcall SetBandType(Qrprntr::TQRBandType Value);
	void __fastcall SetHasChild(bool Value);
	
protected:
	TQRUnit __fastcall GetUnits(void);
	Extended __fastcall StretchHeight(bool IncludeNext);
	virtual AnsiString __fastcall BandTypeName();
	virtual AnsiString __fastcall BandComponentName();
	void __fastcall AdvancePaper(void);
	virtual void __fastcall Loaded(void);
	void __fastcall MakeSpace(void);
	virtual void __fastcall Notification(Classes::TComponent* AComponent, Classes::TOperation Operation);
	virtual void __fastcall Paint(void);
	virtual void __fastcall PaintRuler(TQRUnit Units);
	void __fastcall Print(void);
	virtual void __fastcall SetParent(Controls::TWinControl* AParent);
	virtual void __fastcall SetParentReport(TCustomQuickRep* AParentReport);
	void __fastcall SetBandSize(TQRBandSize* Value);
	virtual void __fastcall SetBounds(int ALeft, int ATop, int AWidth, int AHeight);
	virtual void __fastcall SetEnabled(bool Value);
	void __fastcall SetUnits(TQRUnit Value);
	virtual void __fastcall SetZoom(int Value);
	virtual void __fastcall WriteDummy(Classes::TWriter* Writer);
	__property TQRCustomController* NotifyController = {read=FNotifyController, write=FNotifyController};
	__property bool ParentUpdating = {read=FParentUpdating, write=FParentUpdating, nodefault};
	__property TQRUnit Units = {read=GetUnits, write=SetUnits, nodefault};
	
public:
	__fastcall virtual TQRCustomBand(Classes::TComponent* AOwner);
	__fastcall virtual ~TQRCustomBand(void);
	TQRPrintable* __fastcall AddPrintable(TMetaClass* PrintableClass);
	bool __fastcall CanExpand(Extended Value);
	bool __fastcall ExpandBand(Extended Value, Extended &NewExpanded, bool &HasExpanded);
	__property Extended Expanded = {read=FExpanded};
	__property Qrprntr::TQRBandType BandType = {read=FQRBandType, write=SetBandType, nodefault};
	__property TQRChildBand* ChildBand = {read=GetChild};
	__property TCustomQuickRep* ParentReport = {read=FParentReport, write=SetParentReport};
	
__published:
	__property TQRBandAfterPrintEvent AfterPrint = {read=FAfterPrintEvent, write=FAfterPrintEvent};
	__property bool AlignToBottom = {read=FAlignToBottom, write=FAlignToBottom, nodefault};
	__property TQRBandBeforePrintEvent BeforePrint = {read=FBeforePrintEvent, write=FBeforePrintEvent};
	__property Color  = {default=-2147483633};
	__property bool Enabled = {read=FEnabled, write=SetEnabled, default=1};
	__property Font ;
	__property bool ForceNewColumn = {read=FForceNewColumn, write=FForceNewColumn, nodefault};
	__property bool ForceNewPage = {read=FForceNewPage, write=FForceNewPage, nodefault};
	__property bool HasChild = {read=GetHasChild, write=SetHasChild, stored=false, nodefault};
	__property TQRCustomBand* LinkBand = {read=FLinkBand, write=SetLinkBand};
	__property ParentFont  = {default=1};
	__property TQRBandSize* Size = {read=GetBandSize, write=SetBandSize};
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TQRCustomBand(HWND ParentWindow) : TQRBasePanel(ParentWindow) { }
	#pragma option pop
	
};


class PASCALIMPLEMENTATION TQRBand : public TQRCustomBand 
{
	typedef TQRCustomBand inherited;
	
__published:
	__property BandType ;
public:
	#pragma option push -w-inl
	/* TQRCustomBand.Create */ inline __fastcall virtual TQRBand(Classes::TComponent* AOwner) : TQRCustomBand(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TQRCustomBand.Destroy */ inline __fastcall virtual ~TQRBand(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TQRBand(HWND ParentWindow) : TQRCustomBand(ParentWindow) { }
	#pragma option pop
	
};


class PASCALIMPLEMENTATION TQRChildBand : public TQRCustomBand 
{
	typedef TQRCustomBand inherited;
	
private:
	TQRCustomBand* FParentBand;
	void __fastcall SetParentBand(TQRCustomBand* Value);
	virtual void __fastcall Notification(Classes::TComponent* AComponent, Classes::TOperation Operation);
	
public:
	__fastcall virtual TQRChildBand(Classes::TComponent* AOwner);
	
__published:
	__property TQRCustomBand* ParentBand = {read=FParentBand, write=SetParentBand};
public:
	#pragma option push -w-inl
	/* TQRCustomBand.Destroy */ inline __fastcall virtual ~TQRChildBand(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TQRChildBand(HWND ParentWindow) : TQRCustomBand(ParentWindow) { }
	#pragma option pop
	
};


class DELPHICLASS TQRControllerBand;
class PASCALIMPLEMENTATION TQRControllerBand : public TQRCustomBand 
{
	typedef TQRCustomBand inherited;
	
private:
	bool LocalVarCreated;
	TQRCustomController* FController;
	Classes::TComponent* FMaster;
	
protected:
	bool __fastcall GetPrintIfEmpty(void);
	bool __fastcall GetPrintBefore(void);
	void __fastcall SetPrintBefore(bool Value);
	virtual void __fastcall CreateController(void);
	virtual void __fastcall RegisterBands(void);
	virtual void __fastcall SetMaster(Classes::TComponent* Value);
	virtual void __fastcall SetName(const AnsiString NewName);
	virtual void __fastcall SetParent(Controls::TWinControl* AParent);
	virtual void __fastcall SetParentReport(TCustomQuickRep* AParentReport);
	virtual void __fastcall CreateLocalVar(void);
	virtual void __fastcall RemoveLocalVar(void);
	virtual AnsiString __fastcall LocalVarExpression();
	void __fastcall SetPrintIfEmpty(bool Value);
	__property TQRCustomController* Controller = {read=FController, write=FController};
	
public:
	__fastcall virtual TQRControllerBand(Classes::TComponent* AOwner);
	__fastcall virtual ~TQRControllerBand(void);
	__property bool PrintIfEmpty = {read=GetPrintIfEmpty, write=SetPrintIfEmpty, nodefault};
	__property bool PrintBefore = {read=GetPrintBefore, write=SetPrintBefore, nodefault};
	
__published:
	__property Classes::TComponent* Master = {read=FMaster, write=SetMaster};
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TQRControllerBand(HWND ParentWindow) : TQRCustomBand(ParentWindow) { }
	#pragma option pop
	
};


class DELPHICLASS TQRSubDetailGroupBands;
class DELPHICLASS TQRSubDetail;
class PASCALIMPLEMENTATION TQRSubDetail : public TQRControllerBand 
{
	typedef TQRControllerBand inherited;
	
private:
	TQRSubDetailGroupBands* FBands;
	Db::TDataSet* __fastcall GetDataSet(void);
	TQRCustomBand* __fastcall GetFooterBand(void);
	TQRCustomBand* __fastcall GetHeaderBand(void);
	TQROnNeedDataEvent __fastcall GetOnNeedData();
	void __fastcall SetDataSet(Db::TDataSet* Value);
	void __fastcall SetFooterBand(TQRCustomBand* Value);
	void __fastcall SetHeaderBand(TQRCustomBand* Value);
	void __fastcall SetOnNeedData(TQROnNeedDataEvent Value);
	
protected:
	virtual void __fastcall Notification(Classes::TComponent* AComponent, Classes::TOperation Operation);
	virtual void __fastcall RegisterBands(void);
	
public:
	__fastcall virtual TQRSubDetail(Classes::TComponent* AOwner);
	__fastcall virtual ~TQRSubDetail(void);
	void __fastcall AddNotifyClient(TQRPrintable* Value);
	
__published:
	__property TQRSubDetailGroupBands* Bands = {read=FBands, write=FBands};
	__property Db::TDataSet* DataSet = {read=GetDataSet, write=SetDataSet};
	__property TQRCustomBand* FooterBand = {read=GetFooterBand, write=SetFooterBand};
	__property TQRCustomBand* HeaderBand = {read=GetHeaderBand, write=SetHeaderBand};
	__property TQROnNeedDataEvent OnNeedData = {read=GetOnNeedData, write=SetOnNeedData};
	__property PrintBefore ;
	__property PrintIfEmpty ;
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TQRSubDetail(HWND ParentWindow) : TQRControllerBand(ParentWindow) { }
	#pragma option pop
	
};


class PASCALIMPLEMENTATION TQRSubDetailGroupBands : public Classes::TPersistent 
{
	typedef Classes::TPersistent inherited;
	
private:
	TQRSubDetail* Owner;
	TQRCustomBand* __fastcall GetFooterBand(void);
	bool __fastcall GetHasFooter(void);
	bool __fastcall GetHasHeader(void);
	TQRCustomBand* __fastcall GetHeaderBand(void);
	void __fastcall SetHasFooter(bool Value);
	void __fastcall SetHasHeader(bool Value);
	
public:
	__fastcall TQRSubDetailGroupBands(TQRSubDetail* AOwner);
	__property TQRCustomBand* FooterBand = {read=GetFooterBand};
	__property TQRCustomBand* HeaderBand = {read=GetHeaderBand};
	
__published:
	__property bool HasFooter = {read=GetHasFooter, write=SetHasFooter, stored=false, nodefault};
	__property bool HasHeader = {read=GetHasHeader, write=SetHasHeader, stored=false, nodefault};
public:
	#pragma option push -w-inl
	/* TPersistent.Destroy */ inline __fastcall virtual ~TQRSubDetailGroupBands(void) { }
	#pragma option pop
	
};


class DELPHICLASS TQRLoopController;
class PASCALIMPLEMENTATION TQRLoopController : public TQRCustomController 
{
	typedef TQRCustomController inherited;
	
private:
	int FCount;
	int FPrintCount;
	TQRCustomBand* FDetailBand;
	
protected:
	virtual Qrexpr::TQREvResult __fastcall LocalVarValue();
	virtual void __fastcall RegisterBands(void);
	
public:
	__fastcall virtual TQRLoopController(Classes::TComponent* AOwner);
	virtual void __fastcall Execute(void);
	__property TQRCustomBand* Detail = {read=FDetailBand, write=FDetailBand};
	__property int PrintCount = {read=FPrintCount, write=FPrintCount, nodefault};
	__property int Count = {read=FCount, write=FCount, nodefault};
public:
	#pragma option push -w-inl
	/* TQRCustomController.Destroy */ inline __fastcall virtual ~TQRLoopController(void) { }
	#pragma option pop
	
};


class DELPHICLASS TQRLoopBand;
class PASCALIMPLEMENTATION TQRLoopBand : public TQRControllerBand 
{
	typedef TQRControllerBand inherited;
	
protected:
	int __fastcall GetPrintCount(void);
	void __fastcall SetPrintCount(int Value);
	virtual void __fastcall CreateController(void);
	virtual void __fastcall Notification(Classes::TComponent* AComponent, Classes::TOperation Operation);
	virtual AnsiString __fastcall BandTypeName();
	virtual AnsiString __fastcall BandComponentName();
	int __fastcall GetCount(void);
	virtual AnsiString __fastcall LocalVarExpression();
	
public:
	__fastcall virtual TQRLoopBand(Classes::TComponent* AOwner);
	__property int Count = {read=GetCount, nodefault};
	
__published:
	__property int PrintCount = {read=GetPrintCount, write=SetPrintCount, nodefault};
	__property PrintBefore ;
public:
	#pragma option push -w-inl
	/* TQRControllerBand.Destroy */ inline __fastcall virtual ~TQRLoopBand(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TQRLoopBand(HWND ParentWindow) : TQRControllerBand(ParentWindow) { }
	#pragma option pop
	
};


class DELPHICLASS TQRStringsController;
class PASCALIMPLEMENTATION TQRStringsController : public TQRCustomController 
{
	typedef TQRCustomController inherited;
	
private:
	Classes::TStrings* FItems;
	int FIndex;
	TQRCustomBand* FDetailBand;
	
protected:
	virtual Qrexpr::TQREvResult __fastcall LocalVarValue();
	virtual void __fastcall RegisterBands(void);
	
public:
	__fastcall virtual TQRStringsController(Classes::TComponent* AOwner);
	__fastcall virtual ~TQRStringsController(void);
	virtual void __fastcall Execute(void);
	__property TQRCustomBand* Detail = {read=FDetailBand, write=FDetailBand};
	__property Classes::TStrings* Items = {read=FItems, write=FItems};
	__property int Index = {read=FIndex, write=FIndex, nodefault};
};


class DELPHICLASS TQRStringsBand;
class PASCALIMPLEMENTATION TQRStringsBand : public TQRControllerBand 
{
	typedef TQRControllerBand inherited;
	
protected:
	int __fastcall GetIndex(void);
	AnsiString __fastcall GetItem();
	Classes::TStrings* __fastcall GetItems(void);
	virtual AnsiString __fastcall BandTypeName();
	virtual AnsiString __fastcall BandComponentName();
	virtual AnsiString __fastcall LocalVarExpression();
	void __fastcall SetItems(Classes::TStrings* Value);
	virtual void __fastcall CreateController(void);
	virtual void __fastcall Notification(Classes::TComponent* AComponent, Classes::TOperation Operation);
	
public:
	__fastcall virtual TQRStringsBand(Classes::TComponent* AOwner);
	__property AnsiString Item = {read=GetItem};
	__property int Index = {read=GetIndex, nodefault};
	
__published:
	__property Classes::TStrings* Items = {read=GetItems, write=SetItems};
	__property PrintBefore ;
public:
	#pragma option push -w-inl
	/* TQRControllerBand.Destroy */ inline __fastcall virtual ~TQRStringsBand(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TQRStringsBand(HWND ParentWindow) : TQRControllerBand(ParentWindow) { }
	#pragma option pop
	
};


class DELPHICLASS TQRCompositePrinterSettings;
class PASCALIMPLEMENTATION TQRCompositePrinterSettings : public TQuickRepPrinterSettings 
{
	typedef TQuickRepPrinterSettings inherited;
	
__published:
	__property Orientation ;
	__property PaperSize ;
public:
	#pragma option push -w-inl
	/* TQRPrinterSettings.Create */ inline __fastcall TQRCompositePrinterSettings(void) : TQuickRepPrinterSettings() { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TPersistent.Destroy */ inline __fastcall virtual ~TQRCompositePrinterSettings(void) { }
	#pragma option pop
	
};


class DELPHICLASS TQuickRep;
class PASCALIMPLEMENTATION TQuickRep : public TCustomQuickRep 
{
	typedef TCustomQuickRep inherited;
	
private:
	Db::TDataSet* __fastcall GetDataSet(void);
	int __fastcall GetRecordCount(void);
	int __fastcall GetRecordNumber(void);
	void __fastcall SetDataSet(Db::TDataSet* Value);
	
protected:
	virtual void __fastcall Execute(void);
	virtual void __fastcall Notification(Classes::TComponent* AComponent, Classes::TOperation Operation);
	virtual void __fastcall SetControllerBands(void);
	
public:
	__fastcall virtual TQuickRep(Classes::TComponent* AOwner, int Dummy);
	__fastcall virtual ~TQuickRep(void);
	__property int RecordCount = {read=GetRecordCount, nodefault};
	__property int RecordNumber = {read=GetRecordNumber, nodefault};
	
__published:
	__property AfterPrint ;
	__property AfterPreview ;
	__property TQuickRepBands* Bands = {read=FBands, write=FBands};
	__property BeforePrint ;
	__property Db::TDataSet* DataSet = {read=GetDataSet, write=SetDataSet};
	__property Description ;
	__property Font ;
	__property Functions ;
	__property OnEndPage ;
	__property OnNeedData ;
	__property OnPreview ;
	__property OnStartPage ;
	__property Options ;
	__property Page ;
	__property PrinterSettings ;
	__property PrintIfEmpty ;
	__property ReportTitle ;
	__property ShowProgress  = {default=1};
	__property SnapToGrid ;
	__property Units ;
	__property Zoom ;
public:
	#pragma option push -w-inl
	/* TCustomQuickRep.Create */ inline __fastcall virtual TQuickRep(Classes::TComponent* AOwner) : TCustomQuickRep(AOwner) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TQuickRep(HWND ParentWindow) : TCustomQuickRep(ParentWindow) { }
	#pragma option pop
	
};


class DELPHICLASS TQuickAbstractRep;
class PASCALIMPLEMENTATION TQuickAbstractRep : public TCustomQuickRep 
{
	typedef TCustomQuickRep inherited;
	
__published:
	__property AfterPrint ;
	__property AfterPreview ;
	__property TQuickRepBands* Bands = {read=FBands, write=FBands};
	__property BeforePrint ;
	__property Description ;
	__property Font ;
	__property Functions ;
	__property OnEndPage ;
	__property OnPreview ;
	__property OnStartPage ;
	__property Options ;
	__property Page ;
	__property PrinterSettings ;
	__property PrintIfEmpty ;
	__property ReportTitle ;
	__property Units ;
	__property Zoom ;
public:
	#pragma option push -w-inl
	/* TCustomQuickRep.Create */ inline __fastcall virtual TQuickAbstractRep(Classes::TComponent* AOwner) : TCustomQuickRep(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomQuickRep.CreateNew */ inline __fastcall virtual TQuickAbstractRep(Classes::TComponent* AOwner, int Dummy) : TCustomQuickRep(AOwner, Dummy) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomQuickRep.Destroy */ inline __fastcall virtual ~TQuickAbstractRep(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TQuickAbstractRep(HWND ParentWindow) : TCustomQuickRep(ParentWindow) { }
	#pragma option pop
	
};


class DELPHICLASS TQRLabelSetup;
class PASCALIMPLEMENTATION TQRLabelSetup : public TQRUnitBase 
{
	typedef TQRUnitBase inherited;
	
private:
	Extended FTopMargin;
	Extended FSideMargin;
	Extended FVerticalPitch;
	Extended FLabelWidth;
	Extended FLabelHeight;
	Extended FHorizontalPitch;
	int FNumberDown;
	int FNumberAcross;
	TCustomQuickRep* FParent;
	
protected:
	Extended __fastcall GetValue(int Index);
	int __fastcall GetInteger(int Index);
	void __fastcall SetValue(int Index, Extended Value);
	void __fastcall SetInteger(int Index, int Value);
	
public:
	__fastcall TQRLabelSetup(TCustomQuickRep* Parent);
	
__published:
	__property Extended TopMargin = {read=GetValue, write=SetValue, stored=false, index=0};
	__property Extended SideMargin = {read=GetValue, write=SetValue, stored=false, index=1};
	__property Extended VerticalPitch = {read=GetValue, write=SetValue, stored=false, index=2};
	__property Extended LabelWidth = {read=GetValue, write=SetValue, stored=false, index=3};
	__property Extended LabelHeight = {read=GetValue, write=SetValue, stored=false, index=4};
	__property Extended HorizontalPitch = {read=GetValue, write=SetValue, stored=false, index=5};
	__property int NumberDown = {read=GetInteger, write=SetInteger, stored=false, index=0, nodefault};
	__property int NumberAcross = {read=GetInteger, write=SetInteger, stored=false, index=1, nodefault};
public:
	#pragma option push -w-inl
	/* TPersistent.Destroy */ inline __fastcall virtual ~TQRLabelSetup(void) { }
	#pragma option pop
	
};


class DELPHICLASS TQuickLabelReport;
class PASCALIMPLEMENTATION TQuickLabelReport : public TCustomQuickRep 
{
	typedef TCustomQuickRep inherited;
	
private:
	TQRLabelSetup* FLabelSetup;
	
public:
	__fastcall virtual TQuickLabelReport(Classes::TComponent* AOwner, int Dummy);
	__fastcall virtual ~TQuickLabelReport(void);
	
__published:
	__property TQRLabelSetup* LabelSetup = {read=FLabelSetup, write=FLabelSetup};
public:
	#pragma option push -w-inl
	/* TCustomQuickRep.Create */ inline __fastcall virtual TQuickLabelReport(Classes::TComponent* AOwner) : TCustomQuickRep(AOwner) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TQuickLabelReport(HWND ParentWindow) : TCustomQuickRep(ParentWindow) { }
	#pragma option pop
	
};


class DELPHICLASS TQRGroup;
class PASCALIMPLEMENTATION TQRGroup : public TQRCustomBand 
{
	typedef TQRCustomBand inherited;
	
private:
	Qrexpr::TQREvaluator* Evaluator;
	AnsiString FExpression;
	TQRBand* FFooterBand;
	Classes::TComponent* FMaster;
	bool FReprint;
	bool FReprintOnNewPage;
	Qrexpr::TQREvResult GroupValue;
	bool HasResult;
	bool InGroup;
	int PrintPageNumber;
	void __fastcall SetFooterBand(TQRBand* Value);
	void __fastcall SetMaster(Classes::TComponent* Value);
	
protected:
	__property bool Reprint = {read=FReprint, write=FReprint, nodefault};
	void __fastcall Check(void);
	void __fastcall NewPageCheck(void);
	virtual void __fastcall Notification(Classes::TComponent* AComponent, Classes::TOperation Operation);
	void __fastcall Prepare(void);
	void __fastcall PrintGroupHeader(void);
	void __fastcall PrintGroupFooter(void);
	void __fastcall SetExpression(AnsiString Value);
	virtual void __fastcall SetParent(Controls::TWinControl* AParent);
	void __fastcall Unprepare(void);
	
public:
	__fastcall virtual TQRGroup(Classes::TComponent* AOwner);
	__fastcall virtual ~TQRGroup(void);
	
__published:
	__property AnsiString Expression = {read=FExpression, write=SetExpression};
	__property TQRBand* FooterBand = {read=FFooterBand, write=SetFooterBand};
	__property Classes::TComponent* Master = {read=FMaster, write=SetMaster};
	__property bool ReprintOnNewPage = {read=FReprintOnNewPage, write=FReprintOnNewPage, nodefault};
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TQRGroup(HWND ParentWindow) : TQRCustomBand(ParentWindow) { }
	#pragma option pop
	
};


class DELPHICLASS TQRPrintableSize;
class PASCALIMPLEMENTATION TQRPrintableSize : public TQRUnitBase 
{
	typedef TQRUnitBase inherited;
	
private:
	Extended FHeight;
	Extended FLeft;
	Extended FTop;
	Extended FWidth;
	TQRPrintable* Parent;
	Extended __fastcall GetValue(int Index);
	void __fastcall SetValue(int Index, Extended Value);
	
protected:
	virtual void __fastcall SetParentSizes(void);
	virtual void __fastcall ReadValues(Classes::TReader* Reader);
	virtual void __fastcall WriteValues(Classes::TWriter* Writer);
	void __fastcall FixZoom(void);
	
public:
	__fastcall TQRPrintableSize(TQRPrintable* AParent);
	
__published:
	__property Extended Height = {read=GetValue, write=SetValue, stored=false, index=0};
	__property Extended Left = {read=GetValue, write=SetValue, stored=false, index=1};
	__property Extended Top = {read=GetValue, write=SetValue, stored=false, index=2};
	__property Extended Width = {read=GetValue, write=SetValue, stored=false, index=3};
public:
	#pragma option push -w-inl
	/* TPersistent.Destroy */ inline __fastcall virtual ~TQRPrintableSize(void) { }
	#pragma option pop
	
};


typedef TMetaClass*TQRPrintableClass;

typedef TMetaClass*TQRPrintableEditorClass;

class DELPHICLASS TQRPrintableEditor;
class PASCALIMPLEMENTATION TQRPrintableEditor : public System::TObject 
{
	typedef System::TObject inherited;
	
private:
	TQRPrintable* FControl;
	
protected:
	virtual Graphics::TColor __fastcall GetColor(void);
	virtual Graphics::TFont* __fastcall GetFont(void);
	virtual TMetaClass* __fastcall GetPrintableClass(void);
	virtual AnsiString __fastcall GetValue();
	virtual AnsiString __fastcall GetGlyphResName();
	virtual AnsiString __fastcall GetControlName();
	virtual void __fastcall SetColor(Graphics::TColor Value) = 0 ;
	virtual void __fastcall SetFont(Graphics::TFont* Value) = 0 ;
	virtual void __fastcall SetValue(AnsiString Value) = 0 ;
	
public:
	__fastcall virtual TQRPrintableEditor(TQRPrintable* AControl);
	virtual bool __fastcall ShowEditor(void) = 0 ;
	__property TQRPrintable* Control = {read=FControl, write=FControl};
	__property Graphics::TColor Color = {read=GetColor, write=SetColor, nodefault};
	__property Graphics::TFont* Font = {read=GetFont, write=SetFont};
	__property TMetaClass* PrintableClass = {read=GetPrintableClass};
	__property AnsiString Value = {read=GetValue, write=SetValue};
	__property AnsiString GlyphResName = {read=GetGlyphResName};
	__property AnsiString ControlName = {read=GetControlName};
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TQRPrintableEditor(void) { }
	#pragma option pop
	
};


class PASCALIMPLEMENTATION TQRPrintable : public Controls::TCustomControl 
{
	typedef Controls::TCustomControl inherited;
	
private:
	bool AlignUpdating;
	Classes::TAlignment FAlignment;
	bool FAlignToBand;
	bool ButtonDown;
	TQRFrame* FFrame;
	bool FIsPrinting;
	TCustomQuickRep* FParentReport;
	bool FPrintFinished;
	Qrprntr::TQRPrinter* FQRPrinter;
	TQRPrintableSize* FSize;
	int LoadedTop;
	int LoadedWidth;
	int LoadedHeight;
	int LoadedLeft;
	bool __fastcall GetTransparent(void);
	void __fastcall SetTransparent(bool Value);
	int __fastcall GetZoom(void);
	void __fastcall SetAlignToBand(bool Value);
	void __fastcall SetFrame(TQRFrame* Value);
	
protected:
	virtual bool __fastcall IsEnabled(void);
	virtual TMetaClass* __fastcall GetEditorClass(void);
	virtual void __fastcall AlignIt(void);
	virtual void __fastcall Loaded(void);
	void __fastcall PaintCorners(void);
	virtual void __fastcall SetParent(Controls::TWinControl* AParent);
	void __fastcall SetZoom(int Value);
	virtual void __fastcall Paint(void);
	virtual void __fastcall Prepare(void);
	virtual void __fastcall Print(int OfsX, int OfsY);
	virtual void __fastcall QRNotification(System::TObject* Sender, TQRNotifyOperation Operation);
	virtual void __fastcall SetAlignment(Classes::TAlignment Value);
	virtual void __fastcall SetBounds(int ALeft, int ATop, int AWidth, int AHeight);
	virtual void __fastcall UnPrepare(void);
	__property Classes::TAlignment Alignment = {read=FAlignment, write=SetAlignment, nodefault};
	__property bool AlignToBand = {read=FAlignToBand, write=SetAlignToBand, nodefault};
	__property bool IsPrinting = {read=FIsPrinting, write=FIsPrinting, nodefault};
	__property bool PrintFinished = {read=FPrintFinished, write=FPrintFinished, nodefault};
	__property Qrprntr::TQRPrinter* QRPrinter = {read=FQRPrinter, write=FQRPrinter};
	__property bool Transparent = {read=GetTransparent, write=SetTransparent, nodefault};
	
public:
	__fastcall virtual TQRPrintable(Classes::TComponent* AOwner);
	__fastcall virtual ~TQRPrintable(void);
	__property TCustomQuickRep* ParentReport = {read=FParentReport, write=FParentReport};
	__property int Zoom = {read=GetZoom, write=SetZoom, nodefault};
	__property TMetaClass* EditorClass = {read=GetEditorClass};
	
__published:
	__property Enabled  = {default=1};
	__property TQRFrame* Frame = {read=FFrame, write=SetFrame};
	__property TQRPrintableSize* Size = {read=FSize, write=FSize};
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TQRPrintable(HWND ParentWindow) : Controls::TCustomControl(ParentWindow) { }
	#pragma option pop
	
};


class DELPHICLASS TQRCompositeWinControl;
class DELPHICLASS TQRCompositeReport;
class PASCALIMPLEMENTATION TQRCompositeReport : public Classes::TComponent 
{
	typedef Classes::TComponent inherited;
	
private:
	Classes::TNotifyEvent FOnAddReports;
	Classes::TNotifyEvent FOnFinished;
	TQuickReportOptions FOptions;
	TQRCompositePrinterSettings* FPrinterSettings;
	Qrprntr::TQRPrinter* FQRPrinter;
	Classes::TList* FReports;
	int FIndex;
	AnsiString FReportTitle;
	bool FGenerating;
	TQuickRep* aReport;
	TQRCompositeWinControl* aWinControl;
	void __fastcall CreateComposite(void);
	void __fastcall SetPrinterValues(void);
	
protected:
	void __fastcall CMPreviewClose(Qrprntr::TCM_QRPreviewClose &Message);
	void __fastcall CMPrint(Messages::TMessage &Message);
	__property bool Generating = {read=FGenerating, nodefault};
	
public:
	__fastcall virtual TQRCompositeReport(Classes::TComponent* AOwner);
	__fastcall virtual ~TQRCompositeReport(void);
	void __fastcall Prepare(void);
	void __fastcall PrinterSetup(void);
	void __fastcall Preview(void);
	void __fastcall Print(void);
	__property int Index = {read=FIndex, nodefault};
	__property Classes::TList* Reports = {read=FReports, write=FReports};
	
__published:
	__property Classes::TNotifyEvent OnAddReports = {read=FOnAddReports, write=FOnAddReports};
	__property Classes::TNotifyEvent OnFinished = {read=FOnFinished, write=FOnFinished};
	__property TQuickReportOptions Options = {read=FOptions, write=FOptions, nodefault};
	__property TQRCompositePrinterSettings* PrinterSettings = {read=FPrinterSettings, write=FPrinterSettings};
	__property AnsiString ReportTitle = {read=FReportTitle, write=FReportTitle};
};


class PASCALIMPLEMENTATION TQRCompositeWinControl : public Controls::TWinControl 
{
	typedef Controls::TWinControl inherited;
	
protected:
	TQRCompositeReport* ParentReport;
	MESSAGE void __fastcall CMPreviewClose(Qrprntr::TCM_QRPreviewClose &Message);
	MESSAGE void __fastcall CMPrint(Messages::TMessage &Message);
	
public:
	__fastcall virtual ~TQRCompositeWinControl(void);
public:
	#pragma option push -w-inl
	/* TWinControl.Create */ inline __fastcall virtual TQRCompositeWinControl(Classes::TComponent* AOwner) : Controls::TWinControl(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TQRCompositeWinControl(HWND ParentWindow) : Controls::TWinControl(ParentWindow) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------
extern PACKAGE AnsiString __fastcall UniqueName(Classes::TComponent* AComponent, AnsiString Start);
extern PACKAGE void __fastcall PerformSQLParamsUpdate(Dbtables::TQuery* Query, Qrexpr::TQREvEnvironment* Environment);
extern PACKAGE void __fastcall SetQRHiColor(void);
extern PACKAGE void __fastcall SetQRLoColor(void);

}	/* namespace Quickrpt */
using namespace Quickrpt;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// QuickRpt
