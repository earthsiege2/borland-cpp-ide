// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'QPrinters.pas' rev: 6.00

#ifndef QPrintersHPP
#define QPrintersHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <SysUtils.hpp>	// Pascal unit
#include <QConsts.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <Types.hpp>	// Pascal unit
#include <QGraphics.hpp>	// Pascal unit
#include <Qt.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Qprinters
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS EPrinter;
class PASCALIMPLEMENTATION EPrinter : public Sysutils::Exception 
{
	typedef Sysutils::Exception inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall EPrinter(const AnsiString Msg) : Sysutils::Exception(Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EPrinter(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size) : Sysutils::Exception(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EPrinter(int Ident)/* overload */ : Sysutils::Exception(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EPrinter(int Ident, const System::TVarRec * Args, const int Args_Size)/* overload */ : Sysutils::Exception(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EPrinter(const AnsiString Msg, int AHelpContext) : Sysutils::Exception(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EPrinter(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size, int AHelpContext) : Sysutils::Exception(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EPrinter(int Ident, int AHelpContext)/* overload */ : Sysutils::Exception(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EPrinter(System::PResStringRec ResStringRec, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : Sysutils::Exception(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EPrinter(void) { }
	#pragma option pop
	
};


#pragma option push -b-
enum TOutputType { otPrinter, otProgram, otFileName, otPort, otCustom };
#pragma option pop

#pragma option push -b-
enum TPrinterOrientation { poPortrait, poLandscape };
#pragma option pop

#pragma option push -b-
enum TPrinterCapability { pcCopies, pcOrientation, pcCollation };
#pragma option pop

#pragma option push -b-
enum TPageSize { psA4, psB5, psLetter, psLegal, psExecutive, psA0, psA1, psA2, psA3, psA5, psA6, psA7, psA8, psA9, psB0, psB1, psB10, psB2, psB3, psB4, psB6, psB7, psB8, psB9, psC5E, psComm10E, psDLE, psFolio, psLedger, psTabloid, psNPageSize };
#pragma option pop

class DELPHICLASS TPrinter;
class DELPHICLASS TPrintAdapter;
class PASCALIMPLEMENTATION TPrintAdapter : public System::TObject 
{
	typedef System::TObject inherited;
	
protected:
	virtual bool __fastcall GetAborted(void) = 0 ;
	virtual Qgraphics::TCanvas* __fastcall GetCanvas(void) = 0 ;
	virtual int __fastcall GetCopies(void);
	virtual void __fastcall SetCopies(int Value);
	virtual Qt::QPaintDeviceH* __fastcall GetHandle(void) = 0 ;
	virtual AnsiString __fastcall GetOutputID(void) = 0 ;
	virtual int __fastcall GetPageHeight(void) = 0 ;
	virtual int __fastcall GetPageWidth(void) = 0 ;
	virtual TPrinterOrientation __fastcall GetOrientation(void) = 0 ;
	virtual void __fastcall SetOrientation(const TPrinterOrientation Value) = 0 ;
	virtual void __fastcall GetPrinters(Classes::TStrings* Printers);
	virtual TOutputType __fastcall GetOutputType(void) = 0 ;
	virtual WideString __fastcall GetOutputDevice(void) = 0 ;
	virtual tagSIZE __fastcall GetMargins(void) = 0 ;
	virtual void __fastcall SetTitle(const WideString Value) = 0 ;
	virtual WideString __fastcall GetTitle(void) = 0 ;
	virtual void __fastcall SetPageSize(const TPageSize Value) = 0 ;
	virtual TPageSize __fastcall GetPageSize(void) = 0 ;
	virtual int __fastcall GetXDPI(void) = 0 ;
	virtual int __fastcall GetYDPI(void) = 0 ;
	virtual Qt::QPaintDeviceMetricsH* __fastcall GetDeviceMetrics(void) = 0 ;
	
public:
	virtual void __fastcall Abort(void) = 0 ;
	virtual void __fastcall BeginDoc(void) = 0 ;
	virtual void __fastcall EndDoc(void) = 0 ;
	virtual void __fastcall NewPage(void) = 0 ;
	virtual bool __fastcall ExecuteSetup(void) = 0 ;
	virtual bool __fastcall SupportOutputType(TOutputType Value) = 0 ;
	virtual bool __fastcall SetOutput(TOutputType AOutputType, const WideString AOutputDevice) = 0 ;
	virtual tagSIZE __fastcall TextExtent(const WideString AText);
	__property bool Aborted = {read=GetAborted, nodefault};
	__property Qgraphics::TCanvas* Canvas = {read=GetCanvas};
	__property Qt::QPaintDeviceH* Handle = {read=GetHandle};
	__property Qt::QPaintDeviceMetricsH* DeviceMetrics = {read=GetDeviceMetrics};
	__property int Copies = {read=GetCopies, write=SetCopies, nodefault};
	__property AnsiString OutputID = {read=GetOutputID};
	__property int PageHeight = {read=GetPageHeight, nodefault};
	__property int PageWidth = {read=GetPageWidth, nodefault};
	__property TPageSize PageSize = {read=GetPageSize, write=SetPageSize, nodefault};
	__property TOutputType OutputType = {read=GetOutputType, nodefault};
	__property WideString OutputDevice = {read=GetOutputDevice};
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall TPrintAdapter(void) : System::TObject() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TPrintAdapter(void) { }
	#pragma option pop
	
};


class PASCALIMPLEMENTATION TPrinter : public System::TObject 
{
	typedef System::TObject inherited;
	
private:
	bool PrintAdapterOwned;
	Classes::TStrings* FPrinters;
	
protected:
	int FPageNumber;
	TPrintAdapter* FPrintAdapter;
	bool FPrinting;
	WideString FTitle;
	#pragma pack(push, 1)
	tagSIZE FMargins;
	#pragma pack(pop)
	
	TPageSize FPageSize;
	int FXDPI;
	int FYDPI;
	void __fastcall CheckPrinting(bool Value);
	bool __fastcall GetAborted(void);
	virtual Qgraphics::TCanvas* __fastcall GetCanvas(void);
	int __fastcall GetNumCopies(void);
	void __fastcall SetNumCopies(int Value);
	Qt::QPaintDeviceH* __fastcall GetHandle(void);
	TPrinterOrientation __fastcall GetOrientation(void);
	void __fastcall SetOrientation(TPrinterOrientation Value);
	int __fastcall GetPageHeight(void);
	int __fastcall GetPageWidth(void);
	Classes::TStrings* __fastcall GetPrinters(void);
	TPrintAdapter* __fastcall GetPrintAdapter(void);
	void __fastcall SetPrintAdapter(TPrintAdapter* Value);
	tagSIZE __fastcall GetMargins();
	void __fastcall SetTitle(const WideString Value);
	WideString __fastcall GetTitle();
	int __fastcall GetXDPI(void);
	int __fastcall GetYDPI(void);
	TOutputType __fastcall GetOutputType(void);
	WideString __fastcall GetOutputDevice();
	
public:
	__fastcall TPrinter(void);
	__fastcall virtual ~TPrinter(void);
	void __fastcall Abort(void);
	void __fastcall BeginDoc(void);
	void __fastcall EndDoc(void);
	void __fastcall NewPage(void);
	bool __fastcall ExecuteSetup(void);
	bool __fastcall SetPrinter(const AnsiString Value);
	bool __fastcall SetOutputProgram(const AnsiString Value);
	bool __fastcall SetOutputFileName(const AnsiString Value);
	bool __fastcall SetOutputPort(const AnsiString Value);
	bool __fastcall SupportOutputType(TOutputType OutputType);
	__property bool Aborted = {read=GetAborted, nodefault};
	__property Qgraphics::TCanvas* Canvas = {read=GetCanvas};
	__property int Copies = {read=GetNumCopies, write=SetNumCopies, nodefault};
	__property Qt::QPaintDeviceH* Handle = {read=GetHandle};
	__property TPrinterOrientation Orientation = {read=GetOrientation, write=SetOrientation, nodefault};
	__property int PageHeight = {read=GetPageHeight, nodefault};
	__property int PageWidth = {read=GetPageWidth, nodefault};
	__property int PageNumber = {read=FPageNumber, nodefault};
	__property TPrintAdapter* PrintAdapter = {read=GetPrintAdapter, write=SetPrintAdapter};
	__property bool Printing = {read=FPrinting, nodefault};
	__property Classes::TStrings* Printers = {read=GetPrinters};
	__property WideString Title = {read=GetTitle, write=SetTitle};
	__property tagSIZE Margins = {read=GetMargins};
	__property int XDPI = {read=GetXDPI, nodefault};
	__property int YDPI = {read=GetYDPI, nodefault};
	__property TOutputType OutputType = {read=GetOutputType, nodefault};
	__property WideString OutputDevice = {read=GetOutputDevice};
};


class DELPHICLASS TPrintAdapterCanvas;
class PASCALIMPLEMENTATION TPrintAdapterCanvas : public Qgraphics::TCanvas 
{
	typedef Qgraphics::TCanvas inherited;
	
private:
	TPrintAdapter* FPrintAdapter;
	
protected:
	virtual void __fastcall BeginPainting(void);
	virtual void __fastcall CreateHandle(void);
	virtual void __fastcall Changing(void);
	void __fastcall UpdateFont(void);
	
public:
	__fastcall TPrintAdapterCanvas(TPrintAdapter* PrintAdapter);
public:
	#pragma option push -w-inl
	/* TCanvas.Destroy */ inline __fastcall virtual ~TPrintAdapterCanvas(void) { }
	#pragma option pop
	
};


class DELPHICLASS TQPrintAdapter;
class PASCALIMPLEMENTATION TQPrintAdapter : public TPrintAdapter 
{
	typedef TPrintAdapter inherited;
	
protected:
	Qt::QPaintDeviceH* FHandle;
	Qgraphics::TCanvas* FCanvas;
	Qt::QPaintDeviceMetricsH* FDeviceMetrics;
	WideString FOutputDevice;
	TOutputType FOutputType;
	virtual bool __fastcall GetAborted(void);
	virtual Qgraphics::TCanvas* __fastcall GetCanvas(void);
	virtual Qt::QPaintDeviceH* __fastcall GetHandle(void);
	virtual Qt::QPaintDeviceMetricsH* __fastcall GetDeviceMetrics(void);
	virtual AnsiString __fastcall GetOutputID();
	virtual int __fastcall GetPageHeight(void);
	virtual int __fastcall GetPageWidth(void);
	virtual TPrinterOrientation __fastcall GetOrientation(void);
	virtual void __fastcall SetOrientation(const TPrinterOrientation Value);
	virtual TOutputType __fastcall GetOutputType(void);
	virtual WideString __fastcall GetOutputDevice();
	virtual void __fastcall GetPrinters(Classes::TStrings* Printers);
	void __fastcall SetFullPage(bool Value);
	bool __fastcall GetFullPage(void);
	void __fastcall SetColorMode(const Qt::QPrinterColorMode Value);
	Qt::QPrinterColorMode __fastcall GetColorMode(void);
	void __fastcall SetPageOrder(const Qt::QPrinterPageOrder Value);
	Qt::QPrinterPageOrder __fastcall GetPageOrder(void);
	virtual void __fastcall SetPageSize(const TPageSize Value);
	virtual TPageSize __fastcall GetPageSize(void);
	virtual tagSIZE __fastcall GetMargins();
	virtual void __fastcall SetTitle(const WideString Value);
	virtual WideString __fastcall GetTitle();
	virtual int __fastcall GetXDPI(void);
	virtual int __fastcall GetYDPI(void);
	
public:
	__fastcall TQPrintAdapter(void);
	virtual void __fastcall Abort(void);
	virtual void __fastcall BeginDoc(void);
	virtual void __fastcall EndDoc(void);
	virtual void __fastcall NewPage(void);
	virtual bool __fastcall ExecuteSetup(void);
	virtual bool __fastcall SupportOutputType(TOutputType Value);
	virtual bool __fastcall SetOutput(TOutputType AOutputType, const WideString AOutputDevice);
	__property bool FullPage = {read=GetFullPage, write=SetFullPage, nodefault};
	__property Qt::QPrinterColorMode ColorMode = {read=GetColorMode, write=SetColorMode, nodefault};
	__property Qt::QPrinterPageOrder PageOrder = {read=GetPageOrder, write=SetPageOrder, nodefault};
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TQPrintAdapter(void) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------
extern PACKAGE TPrinter* __fastcall Printer(void);
extern PACKAGE TPrinter* __fastcall SetPrinter(TPrinter* NewPrinter);
extern PACKAGE TPrinter* __fastcall AssignPrn(TextFile &AFile, TPrinter* APrinter = (TPrinter*)(0x0));
extern PACKAGE void __fastcall CheckPrinting(TPrintAdapter* Adapter, bool Value);
extern PACKAGE void __fastcall RaisePrinterError(const AnsiString Msg);

}	/* namespace Qprinters */
using namespace Qprinters;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// QPrinters
