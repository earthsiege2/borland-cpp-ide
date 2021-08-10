// Borland C++ Builder
// Copyright (c) 1995, 1999 by Borland International
// All rights reserved

// (DO NOT EDIT: machine generated header) 'QRPrntr.pas' rev: 5.00

#ifndef QRPrntrHPP
#define QRPrntrHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <Dialogs.hpp>	// Pascal unit
#include <qr3const.hpp>	// Pascal unit
#include <DBTables.hpp>	// Pascal unit
#include <Db.hpp>	// Pascal unit
#include <Forms.hpp>	// Pascal unit
#include <Graphics.hpp>	// Pascal unit
#include <Printers.hpp>	// Pascal unit
#include <Buttons.hpp>	// Pascal unit
#include <ComCtrls.hpp>	// Pascal unit
#include <ExtCtrls.hpp>	// Pascal unit
#include <StdCtrls.hpp>	// Pascal unit
#include <Controls.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <Messages.hpp>	// Pascal unit
#include <SysUtils.hpp>	// Pascal unit
#include <WinSpool.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Qrprntr
{
//-- type declarations -------------------------------------------------------
#pragma option push -b-
enum TQRPaperSize { Default, Letter, LetterSmall, Tabloid, Ledger, Legal, Statement, Executive, A3, 
	A4, A4Small, A5, B4, B5, Folio, Quarto, qr10X14, qr11X17, Note, Env9, Env10, Env11, Env12, Env14, CSheet, 
	DSheet, ESheet, Custom };
#pragma option pop

#pragma option push -b-
enum TQRBin { First, Upper, Lower, Middle, Manual, Envelope, EnvManual, Auto, Tractor, SmallFormat, 
	LargeFormat, LargeCapacity, Cassette, Last };
#pragma option pop

#pragma option push -b-
enum TQRBandType { rbTitle, rbPageHeader, rbDetail, rbPageFooter, rbSummary, rbGroupHeader, rbGroupFooter, 
	rbSubDetail, rbColumnHeader, rbOverlay, rbChild };
#pragma option pop

class DELPHICLASS EQRError;
class PASCALIMPLEMENTATION EQRError : public Sysutils::Exception 
{
	typedef Sysutils::Exception inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall EQRError(const AnsiString Msg) : Sysutils::Exception(Msg) { }
		
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EQRError(const AnsiString Msg, const System::TVarRec * 
		Args, const int Args_Size) : Sysutils::Exception(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EQRError(int Ident)/* overload */ : Sysutils::Exception(
		Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EQRError(int Ident, const System::TVarRec * Args, const 
		int Args_Size)/* overload */ : Sysutils::Exception(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EQRError(const AnsiString Msg, int AHelpContext) : Sysutils::Exception(
		Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EQRError(const AnsiString Msg, const System::TVarRec 
		* Args, const int Args_Size, int AHelpContext) : Sysutils::Exception(Msg, Args, Args_Size, AHelpContext
		) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EQRError(int Ident, int AHelpContext)/* overload */
		 : Sysutils::Exception(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EQRError(System::PResStringRec ResStringRec, const 
		System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : Sysutils::Exception(
		ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EQRError(void) { }
	#pragma option pop
	
};


typedef Word CodeType;

typedef Byte UpIndex;

typedef Word DownIndex;

typedef DownIndex TreeDownArray[256];

typedef UpIndex TreeUpArray[513];

class DELPHICLASS TQRPrinter;
class DELPHICLASS TPrinterSettings;
typedef bool TPaperSizesSupported[27];

class PASCALIMPLEMENTATION TPrinterSettings : public System::TObject 
{
	typedef System::TObject inherited;
	
private:
	char *FDevice;
	char *FDriver;
	char *FPort;
	unsigned DeviceMode;
	_devicemodeA *DevMode;
	int FCopies;
	bool FDuplex;
	int FMaxExtentX;
	int FMaxExtentY;
	int FMinExtentX;
	int FMinExtentY;
	Printers::TPrinterOrientation FOrientation;
	TQRBin FOutputBin;
	TQRPaperSize FPaperSize;
	bool FPaperSizes[27];
	int FPaperWidth;
	int FPaperLength;
	int FPixelsPerX;
	int FPixelsPerY;
	int FTopOffset;
	int FLeftOffset;
	Printers::TPrinter* FPrinter;
	AnsiString FTitle;
	int __fastcall GetCopies(void);
	AnsiString __fastcall GetDriver();
	bool __fastcall GetDuplex(void);
	int __fastcall GetMaxExtentX(void);
	int __fastcall GetMaxExtentY(void);
	int __fastcall GetMinExtentX(void);
	int __fastcall GetMinExtentY(void);
	Printers::TPrinterOrientation __fastcall GetOrientation(void);
	TQRBin __fastcall GetOutputBin(void);
	TQRPaperSize __fastcall GetPaperSize(void);
	bool __fastcall GetPaperSizeSupported(TQRPaperSize PaperSize);
	int __fastcall GetPaperWidth(void);
	int __fastcall GetPaperLength(void);
	int __fastcall GetPixelsPerX(void);
	int __fastcall GetPixelsPerY(void);
	AnsiString __fastcall GetPort();
	Printers::TPrinter* __fastcall GetPrinter(void);
	AnsiString __fastcall GetTitle();
	int __fastcall GetTopOffset(void);
	int __fastcall GetLeftOffset(void);
	bool __fastcall Supported(int Setting);
	void __fastcall SetField(int aField);
	void __fastcall GetPrinterSettings(void);
	void __fastcall SetCopies(int Value);
	void __fastcall SetDuplex(bool Value);
	void __fastcall SetOrientation(Printers::TPrinterOrientation Value);
	void __fastcall SetOutputBin(TQRBin Value);
	void __fastcall SetPaperSize(TQRPaperSize Value);
	void __fastcall SetPaperLength(int Value);
	void __fastcall SetPaperWidth(int Value);
	void __fastcall SetPrinter(Printers::TPrinter* Value);
	void __fastcall SetTitle(AnsiString Value);
	
public:
	__fastcall TPrinterSettings(void);
	__fastcall virtual ~TPrinterSettings(void);
	void __fastcall ApplySettings(void);
	__property AnsiString Device = {read=GetDriver};
	__property AnsiString Driver = {read=GetDriver};
	__property int LeftOffset = {read=GetLeftOffset, nodefault};
	__property int MaxExtentX = {read=GetMaxExtentX, nodefault};
	__property int MaxExtentY = {read=GetMaxExtentY, nodefault};
	__property int MinExtentX = {read=GetMinExtentX, nodefault};
	__property int MinExtentY = {read=GetMinExtentY, nodefault};
	__property bool PaperSizeSupported[TQRPaperSize PaperSize] = {read=GetPaperSizeSupported};
	__property int PixelsPerX = {read=GetPixelsPerX, nodefault};
	__property int PixelsPerY = {read=GetPixelsPerY, nodefault};
	__property AnsiString Port = {read=GetPort};
	__property int TopOffset = {read=GetTopOffset, nodefault};
	__property int Copies = {read=GetCopies, write=SetCopies, nodefault};
	__property bool Duplex = {read=GetDuplex, write=SetDuplex, nodefault};
	__property Printers::TPrinterOrientation Orientation = {read=GetOrientation, write=SetOrientation, 
		nodefault};
	__property TQRBin OutputBin = {read=GetOutputBin, write=SetOutputBin, nodefault};
	__property int PaperLength = {read=GetPaperLength, write=SetPaperLength, nodefault};
	__property TQRPaperSize PaperSize = {read=GetPaperSize, write=SetPaperSize, nodefault};
	__property int PaperWidth = {read=GetPaperWidth, write=SetPaperWidth, nodefault};
	__property Printers::TPrinter* Printer = {read=GetPrinter, write=SetPrinter};
	__property AnsiString Title = {read=GetTitle, write=SetTitle};
};


class DELPHICLASS TQRStream;
class PASCALIMPLEMENTATION TQRStream : public Classes::TStream 
{
	typedef Classes::TStream inherited;
	
private:
	_RTL_CRITICAL_SECTION FLock;
	Classes::TMemoryStream* MemoryStream;
	AnsiString FFilename;
	Classes::TFileStream* FileStream;
	bool FInMemory;
	int FMemoryLimit;
	
public:
	__fastcall TQRStream(int MemoryLimit);
	__fastcall TQRStream(AnsiString Filename);
	__fastcall virtual ~TQRStream(void);
	virtual int __fastcall Write(const void *Buffer, int Count);
	virtual int __fastcall Seek(int Offset, Word Origin);
	virtual int __fastcall Read(void *Buffer, int Count);
	void __fastcall LockStream(void);
	void __fastcall UnlockStream(void);
	void __fastcall SaveToStream(Classes::TStream* AStream);
	__property bool InMemory = {read=FInMemory, nodefault};
};


typedef void __fastcall (__closure *TQRAfterPrintEvent)(System::TObject* Sender);

typedef void __fastcall (__closure *TQRAfterPreviewEvent)(System::TObject* Sender);

#pragma option push -b-
enum TQRPrinterDestination { qrdMetafile, qrdPrinter };
#pragma option pop

class DELPHICLASS TQRExportFilter;
typedef void __fastcall (__closure *TQRExportToFilterEvent)(TQRExportFilter* aFilter);

typedef void __fastcall (__closure *TQRPrintSetupEvent)(void);

#pragma option push -b-
enum TQRPrinterStatus { mpReady, mpBusy, mpFinished };
#pragma option pop

class DELPHICLASS TQRPageList;
class DELPHICLASS TQRCompress;
class PASCALIMPLEMENTATION TQRCompress : public System::TObject 
{
	typedef System::TObject inherited;
	
private:
	Byte BitPos;
	bool CompressFlag;
	CodeType InByte;
	DownIndex Left[256];
	DownIndex Right[256];
	CodeType OutByte;
	Classes::TStream* Stream;
	UpIndex Up[513];
	Byte __fastcall GetByte(void);
	void __fastcall InitializeSplay(void);
	void __fastcall Splay(CodeType Plain);
	
public:
	__fastcall TQRCompress(Classes::TStream* aStream, bool CompressData);
	__fastcall virtual ~TQRCompress(void);
	void __fastcall Expand(Byte &Expanded);
	void __fastcall Compress(CodeType Plain);
};


class PASCALIMPLEMENTATION TQRPageList : public System::TObject 
{
	typedef System::TObject inherited;
	
private:
	_RTL_CRITICAL_SECTION FLock;
	TQRCompress* aCompressor;
	bool FCompression;
	int FPageCount;
	TQRStream* FStream;
	void __fastcall SeekToFirst(void);
	void __fastcall SeekToLast(void);
	void __fastcall SeekToPage(int PageNumber);
	void __fastcall ReadFileHeader(void);
	void __fastcall WriteFileHeader(void);
	
public:
	__fastcall TQRPageList(void);
	__fastcall virtual ~TQRPageList(void);
	Graphics::TMetafile* __fastcall GetPage(int PageNumber);
	void __fastcall AddPage(Graphics::TMetafile* aMetafile);
	void __fastcall Clear(void);
	void __fastcall Finish(void);
	void __fastcall LoadFromFile(AnsiString Filename);
	void __fastcall LockList(void);
	void __fastcall SaveToFile(AnsiString Filename);
	void __fastcall UnlockList(void);
	__property bool Compression = {read=FCompression, write=FCompression, nodefault};
	__property int PageCount = {read=FPageCount, nodefault};
	__property TQRStream* Stream = {read=FStream, write=FStream};
};


class PASCALIMPLEMENTATION TQRPrinter : public Classes::TPersistent 
{
	typedef Classes::TPersistent inherited;
	
private:
	Printers::TPrinter* aPrinter;
	TPrinterSettings* aPrinterSettings;
	TQRStream* aStream;
	TQRAfterPrintEvent FAfterPrintEvent;
	TQRAfterPreviewEvent FAfterPreviewEvent;
	int FAvailablePages;
	bool FCancelled;
	Graphics::TCanvas* FCanvas;
	Controls::TWinControl* FCloseControl;
	TQRPrinterDestination FDestination;
	int FFirstPage;
	int FLastpage;
	int FLeftWaste;
	Controls::TWinControl* FClient;
	Controls::TWinControl* FMaster;
	Graphics::TMetafile* FMetafile;
	TQRExportToFilterEvent FOnExportToFilterEvent;
	Classes::TNotifyEvent FOnPreviewEvent;
	TQRPrintSetupEvent FOnPrintSetupEvent;
	Graphics::TMetafile* FPage;
	int FPageCount;
	int FPageNumber;
	bool FPrinterOK;
	int FProgress;
	AnsiString FTitle;
	int FTopWaste;
	bool FShowingPreview;
	TQRPrinterStatus FStatus;
	Extended FXFactor;
	Extended FYFactor;
	TQRPageList* PageList;
	Controls::TWinControl* PreviewControl;
	bool FReportLoaded;
	bool __fastcall CurrentPageOK(void);
	int __fastcall GetLeftWaste(void);
	TQRBin __fastcall GetBin(void);
	Graphics::TCanvas* __fastcall GetCanvas(void);
	bool __fastcall GetCompression(void);
	int __fastcall GetCopies(void);
	bool __fastcall GetDuplex(void);
	Printers::TPrinterOrientation __fastcall GetOrientation(void);
	int __fastcall GetPaperLength(void);
	TQRPaperSize __fastcall GetPaperSize(void);
	int __fastcall GetPaperWidth(void);
	int __fastcall GetPrinterIndex(void);
	Classes::TStrings* __fastcall GetPrinters(void);
	int __fastcall GetTopWaste(void);
	void __fastcall CreateMetafileCanvas(void);
	void __fastcall CreatePrinterCanvas(void);
	void __fastcall EndMetafileCanvas(void);
	void __fastcall EndPrinterCanvas(void);
	void __fastcall SetAvailablePages(int Value);
	void __fastcall SetBin(TQRBin Value);
	void __fastcall SetCompression(bool Value);
	void __fastcall SetCopies(int Value);
	void __fastcall SetDestination(TQRPrinterDestination Value);
	void __fastcall SetDuplex(bool Value);
	void __fastcall SetOrientation(Printers::TPrinterOrientation Value);
	void __fastcall SetPaperLength(int Value);
	void __fastcall SetPageNumber(int Value);
	void __fastcall SetPaperSize(TQRPaperSize Value);
	void __fastcall SetPaperWidth(int Value);
	void __fastcall SetPrinterIndex(int Value);
	void __fastcall SetProgress(int Value);
	void __fastcall SetShowingPreview(bool Value);
	
public:
	__fastcall TQRPrinter(void);
	__fastcall virtual ~TQRPrinter(void);
	Graphics::TMetafile* __fastcall GetPage(int Value);
	int __fastcall XPos(Extended Value);
	int __fastcall XSize(Extended Value);
	int __fastcall YPos(Extended Value);
	int __fastcall YSize(Extended Value);
	int __fastcall PaperLengthValue(void);
	int __fastcall PaperWidthValue(void);
	void __fastcall AbortDoc(void);
	void __fastcall BeginDoc(void);
	void __fastcall Cancel(void);
	void __fastcall Cleanup(void);
	void __fastcall ClosePreview(Controls::TWinControl* Control);
	void __fastcall EndDoc(void);
	void __fastcall ExportToFilter(TQRExportFilter* aFilter);
	void __fastcall Load(AnsiString Filename);
	void __fastcall NewPage(void);
	void __fastcall Preview(void);
	void __fastcall PreviewModal(void);
	void __fastcall Print(void);
	void __fastcall PrintSetup(void);
	void __fastcall Save(AnsiString Filename);
	__property bool ReportLoaded = {read=FReportLoaded, write=FReportLoaded, nodefault};
	__property TQRAfterPreviewEvent AfterPreview = {read=FAfterPreviewEvent, write=FAfterPreviewEvent};
		
	__property TQRAfterPrintEvent AfterPrint = {read=FAfterPrintEvent, write=FAfterPrintEvent};
	__property int AvailablePages = {read=FAvailablePages, write=SetAvailablePages, nodefault};
	__property TQRBin OutputBin = {read=GetBin, write=SetBin, nodefault};
	__property bool Cancelled = {read=FCancelled, write=FCancelled, nodefault};
	__property Graphics::TCanvas* Canvas = {read=GetCanvas};
	__property Controls::TWinControl* Client = {read=FClient, write=FClient};
	__property bool Compression = {read=GetCompression, write=SetCompression, nodefault};
	__property int Copies = {read=GetCopies, write=SetCopies, nodefault};
	__property TQRPrinterDestination Destination = {read=FDestination, write=SetDestination, nodefault}
		;
	__property bool Duplex = {read=GetDuplex, write=SetDuplex, nodefault};
	__property int FirstPage = {read=FFirstPage, write=FFirstPage, nodefault};
	__property int LastPage = {read=FLastpage, write=FLastpage, nodefault};
	__property int LeftWaste = {read=GetLeftWaste, nodefault};
	__property Controls::TWinControl* Master = {read=FMaster, write=FMaster};
	__property Printers::TPrinterOrientation Orientation = {read=GetOrientation, write=SetOrientation, 
		nodefault};
	__property TQRExportToFilterEvent OnExportToFilter = {read=FOnExportToFilterEvent, write=FOnExportToFilterEvent
		};
	__property Classes::TNotifyEvent OnPreview = {read=FOnPreviewEvent, write=FOnPreviewEvent};
	__property TQRPrintSetupEvent OnPrintSetup = {read=FOnPrintSetupEvent, write=FOnPrintSetupEvent};
	__property int PaperLength = {read=GetPaperLength, write=SetPaperLength, nodefault};
	__property Graphics::TMetafile* Page = {read=FPage};
	__property int PageCount = {read=FPageCount, write=FPageCount, nodefault};
	__property int PageNumber = {read=FPageNumber, write=SetPageNumber, nodefault};
	__property int PaperWidth = {read=GetPaperWidth, write=SetPaperWidth, nodefault};
	__property TQRPaperSize PaperSize = {read=GetPaperSize, write=SetPaperSize, nodefault};
	__property int PrinterIndex = {read=GetPrinterIndex, write=SetPrinterIndex, nodefault};
	__property bool PrinterOK = {read=FPrinterOK, nodefault};
	__property Classes::TStrings* Printers = {read=GetPrinters};
	__property int Progress = {read=FProgress, write=SetProgress, nodefault};
	__property bool ShowingPreview = {read=FShowingPreview, write=SetShowingPreview, nodefault};
	__property TQRPrinterStatus Status = {read=FStatus, nodefault};
	__property AnsiString Title = {read=FTitle, write=FTitle};
	__property int TopWaste = {read=GetTopWaste, nodefault};
	__property Extended XFactor = {read=FXFactor, write=FXFactor};
	__property Extended YFactor = {read=FYFactor, write=FYFactor};
};


struct TCM_QRPRogressUpdate
{
	unsigned Msg;
	Word Position;
	TQRPrinter* QRPrinter;
} ;

struct TCM_QRPageAvailable
{
	unsigned Msg;
	Word PageCount;
	TQRPrinter* QRPrinter;
} ;

struct TCM_QRPreviewClose
{
	unsigned Msg;
	Word Dummy;
	TQRPrinter* QRPrinter;
} ;

typedef Messages::TMessage  TCM_QRPrint;

typedef TMetaClass*TQRExportFilterClass;

class DELPHICLASS TQRExportFilterLibraryEntry;
class PASCALIMPLEMENTATION TQRExportFilterLibraryEntry : public System::TObject 
{
	typedef System::TObject inherited;
	
private:
	TMetaClass*FExportFilterClass;
	AnsiString FName;
	AnsiString FExtension;
	
public:
	__property TMetaClass* ExportFilterClass = {read=FExportFilterClass, write=FExportFilterClass};
	__property AnsiString FilterName = {read=FName, write=FName};
	__property AnsiString Extension = {read=FExtension, write=FExtension};
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall TQRExportFilterLibraryEntry(void) : System::TObject() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TQRExportFilterLibraryEntry(void) { }
	#pragma option pop
	
};


class DELPHICLASS TQRExportFilterLibrary;
class PASCALIMPLEMENTATION TQRExportFilterLibrary : public System::TObject 
{
	typedef System::TObject inherited;
	
private:
	Classes::TList* FFilterList;
	
protected:
	AnsiString __fastcall GetSaveDialogFilter();
	
public:
	__fastcall TQRExportFilterLibrary(void);
	__fastcall virtual ~TQRExportFilterLibrary(void);
	void __fastcall AddFilter(TMetaClass* AFilter);
	void __fastcall RemoveFilter(TMetaClass* AFilter);
	__property Classes::TList* Filters = {read=FFilterList};
	__property AnsiString SaveDialogFilterString = {read=GetSaveDialogFilter};
};


class DELPHICLASS TQRPreviewInterface;
class PASCALIMPLEMENTATION TQRPreviewInterface : public Classes::TComponent 
{
	typedef Classes::TComponent inherited;
	
public:
	virtual Controls::TWinControl* __fastcall Show(TQRPrinter* AQRPrinter);
	virtual Controls::TWinControl* __fastcall ShowModal(TQRPrinter* AQRPrinter);
public:
	#pragma option push -w-inl
	/* TComponent.Create */ inline __fastcall virtual TQRPreviewInterface(Classes::TComponent* AOwner) : 
		Classes::TComponent(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TComponent.Destroy */ inline __fastcall virtual ~TQRPreviewInterface(void) { }
	#pragma option pop
	
};


typedef TMetaClass*TQRPreviewInterfaceClass;

class DELPHICLASS TQRStandardPreviewInterface;
class PASCALIMPLEMENTATION TQRStandardPreviewInterface : public TQRPreviewInterface 
{
	typedef TQRPreviewInterface inherited;
	
public:
	virtual Controls::TWinControl* __fastcall Show(TQRPrinter* AQRPrinter);
	virtual Controls::TWinControl* __fastcall ShowModal(TQRPrinter* AQRPrinter);
public:
	#pragma option push -w-inl
	/* TComponent.Create */ inline __fastcall virtual TQRStandardPreviewInterface(Classes::TComponent* 
		AOwner) : TQRPreviewInterface(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TComponent.Destroy */ inline __fastcall virtual ~TQRStandardPreviewInterface(void) { }
	#pragma option pop
	
};


#pragma option push -b-
enum TQRZoomState { qrZoomToFit, qrZoomToWidth, qrZoomOther };
#pragma option pop

class DELPHICLASS TQRPreviewImage;
class PASCALIMPLEMENTATION TQRPreviewImage : public Controls::TGraphicControl 
{
	typedef Controls::TGraphicControl inherited;
	
private:
	TQRPrinter* FQRPrinter;
	int FPageNumber;
	Graphics::TMetafile* aMetaFile;
	bool FImageOK;
	void __fastcall PaintPage(void);
	void __fastcall SetPageNumber(int Value);
	
public:
	int Zoom;
	__fastcall virtual TQRPreviewImage(Classes::TComponent* AOwner);
	__fastcall virtual ~TQRPreviewImage(void);
	virtual void __fastcall Paint(void);
	__property bool ImageOK = {read=FImageOK, write=FImageOK, nodefault};
	__property int PageNumber = {read=FPageNumber, write=SetPageNumber, nodefault};
	__property TQRPrinter* QRPrinter = {read=FQRPrinter, write=FQRPrinter};
};


typedef void __fastcall (__closure *TQRProgressUpdateEvent)(System::TObject* Sender, int Progress);

typedef void __fastcall (__closure *TQRPageAvailableEvent)(System::TObject* Sender, int PageNum);

class DELPHICLASS TQRPreview;
class PASCALIMPLEMENTATION TQRPreview : public Forms::TScrollBox 
{
	typedef Forms::TScrollBox inherited;
	
private:
	TQRPageAvailableEvent FOnPageAvailableEvent;
	TQRProgressUpdateEvent FOnProgressUpdateEvent;
	TQRPreviewImage* FPreviewImage;
	int FPageNumber;
	TQRPrinter* FQRPrinter;
	int FZoom;
	TQRZoomState FZoomState;
	void __fastcall SetPageNumber(int Value);
	void __fastcall SetZoom(int value);
	void __fastcall Fixvalues(System::TObject* Sender);
	void __fastcall SetQRPrinter(TQRPrinter* Value);
	
protected:
	MESSAGE void __fastcall CMPageAvailable(TCM_QRPageAvailable &Message);
	MESSAGE void __fastcall CMProgressUpdate(TCM_QRPRogressUpdate &Message);
	
public:
	__fastcall virtual TQRPreview(Classes::TComponent* aOwner);
	__fastcall virtual ~TQRPreview(void);
	void __fastcall UpdateImage(void);
	void __fastcall UpdateZoom(void);
	void __fastcall ZoomToWidth(void);
	void __fastcall ZoomToFit(void);
	__property TQRPreviewImage* PreviewImage = {read=FPreviewImage};
	__property TQRPrinter* QRPrinter = {read=FQRPrinter, write=SetQRPrinter};
	__property TQRZoomState ZoomState = {read=FZoomState, write=FZoomState, nodefault};
	
__published:
	__property TQRPageAvailableEvent OnPageAvailable = {read=FOnPageAvailableEvent, write=FOnPageAvailableEvent
		};
	__property TQRProgressUpdateEvent OnProgressUpdate = {read=FOnProgressUpdateEvent, write=FOnProgressUpdateEvent
		};
	__property int PageNumber = {read=FPageNumber, write=SetPageNumber, nodefault};
	__property int Zoom = {read=FZoom, write=SetZoom, nodefault};
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TQRPreview(HWND ParentWindow) : Forms::TScrollBox(
		ParentWindow) { }
	#pragma option pop
	
};


class PASCALIMPLEMENTATION TQRExportFilter : public System::TObject 
{
	typedef System::TObject inherited;
	
private:
	TQRPrinter* FOriginalQRPrinter;
	bool FActive;
	AnsiString FFilename;
	Classes::TComponent* FOwner;
	
protected:
	virtual AnsiString __fastcall GetDescription();
	virtual AnsiString __fastcall GetExtension();
	virtual AnsiString __fastcall GetFilterName();
	virtual AnsiString __fastcall GetVendorName();
	virtual bool __fastcall GetStreaming(void);
	
public:
	__fastcall TQRExportFilter(AnsiString Filename);
	virtual void __fastcall Start(int PaperWidth, int PaperHeight, Graphics::TFont* Font);
	virtual void __fastcall EndPage(void);
	virtual void __fastcall Finish(void);
	virtual void __fastcall NewPage(void);
	virtual void __fastcall TextOut(Extended X, Extended Y, Graphics::TFont* Font, Graphics::TColor BGColor
		, Classes::TAlignment Alignment, AnsiString Text);
	__property bool Active = {read=FActive, write=FActive, nodefault};
	__property AnsiString Description = {read=GetDescription};
	__property AnsiString FileExtension = {read=GetExtension};
	__property AnsiString Filename = {read=FFilename};
	__property AnsiString Name = {read=GetFilterName};
	__property Classes::TComponent* Owner = {read=FOwner, write=FOwner};
	__property bool Streaming = {read=GetStreaming, nodefault};
	__property AnsiString Vendor = {read=GetVendorName};
	__property TQRPrinter* OriginalQRPrinter = {read=FOriginalQRPrinter, write=FOriginalQRPrinter};
public:
		
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TQRExportFilter(void) { }
	#pragma option pop
	
};


class DELPHICLASS TQRPrinterSettings;
class PASCALIMPLEMENTATION TQRPrinterSettings : public Classes::TPersistent 
{
	typedef Classes::TPersistent inherited;
	
private:
	int FCopies;
	bool FDuplex;
	Printers::TPrinterOrientation FOrientation;
	TQRBin FOutputBin;
	TQRPaperSize FPaperSize;
	int FPrinterIndex;
	AnsiString FTitle;
	int FFirstPage;
	int FLastPage;
	
public:
	__fastcall TQRPrinterSettings(void);
	void __fastcall ApplySettings(TQRPrinter* APrinter);
	__property int Copies = {read=FCopies, write=FCopies, nodefault};
	__property bool Duplex = {read=FDuplex, write=FDuplex, nodefault};
	__property int FirstPage = {read=FFirstPage, write=FFirstPage, nodefault};
	__property int LastPage = {read=FLastPage, write=FLastPage, nodefault};
	__property Printers::TPrinterOrientation Orientation = {read=FOrientation, write=FOrientation, nodefault
		};
	__property TQRBin OutputBin = {read=FOutputBin, write=FOutputBin, nodefault};
	__property TQRPaperSize PaperSize = {read=FPaperSize, write=FPaperSize, nodefault};
	__property int PrinterIndex = {read=FPrinterIndex, write=FPrinterIndex, nodefault};
	__property AnsiString Title = {read=FTitle, write=FTitle};
public:
	#pragma option push -w-inl
	/* TPersistent.Destroy */ inline __fastcall virtual ~TQRPrinterSettings(void) { }
	#pragma option pop
	
};


typedef void __fastcall (__closure *TQRGenerateToPrinterEvent)(void);

typedef void __fastcall (__closure *TQRPreviewEvent)(void);

//-- var, const, procedure ---------------------------------------------------
#define cQRName "QuickReport 3.0.5"
static const Word cQRVersion = 0x131;
#define cQRPDefaultExt "QRP"
#define cQRDefaultExt "QR"
extern PACKAGE Extended cQRPaperSizeMetrics[26][2];
extern PACKAGE int cQRPaperTranslate[28];
extern PACKAGE int cQRBinTranslate[14];
static const Shortint cQRPageShadowWidth = 0x2;
static const Shortint cQRPageFrameWidth = 0x1;
static const int cQRPageShadowColor = 0x0;
static const Shortint cQRCornerSize = 0x4;
static const Word MaxChar = 0x100;
static const Word EofChar = 0x100;
static const Byte PredMax = 0xff;
static const Word TwiceMax = 0x200;
static const Shortint ROOT = 0x0;
extern PACKAGE Byte BitMask[8];
static const Word CM_QRPROGRESSUPDATE = 0x400;
static const Word CM_QRPAGEAVAILABLE = 0x401;
static const Word CM_QRPRINT = 0x402;
static const Word CM_QRPRINTSETUP = 0x403;
static const Word CM_QRPREVIEWCLOSE = 0x404;
extern PACKAGE TQRExportFilterLibrary* QRExportFilterLibrary;
extern PACKAGE int __fastcall AnsiPos(AnsiString Substr, AnsiString S);
extern PACKAGE AnsiString __fastcall QRPaperName(TQRPaperSize Size);
extern PACKAGE AnsiString __fastcall TempFilename();
extern PACKAGE Classes::TStrings* __fastcall GetFonts(void);
extern PACKAGE TQRPrinter* __fastcall QRPrinter(void);
extern PACKAGE void __fastcall RegisterPreviewClass(TMetaClass* APreviewInterface);

}	/* namespace Qrprntr */
#if !defined(NO_IMPLICIT_NAMESPACE_USE)
using namespace Qrprntr;
#endif
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// QRPrntr
