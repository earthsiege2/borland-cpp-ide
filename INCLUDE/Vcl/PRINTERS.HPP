// Borland C++ Builder
// Copyright (c) 1995, 1999 by Borland International
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Printers.pas' rev: 5.00

#ifndef PrintersHPP
#define PrintersHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <Forms.hpp>	// Pascal unit
#include <Graphics.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <SysUtils.hpp>	// Pascal unit
#include <WinSpool.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Printers
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
	/* Exception.CreateFmt */ inline __fastcall EPrinter(const AnsiString Msg, const System::TVarRec * 
		Args, const int Args_Size) : Sysutils::Exception(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EPrinter(int Ident)/* overload */ : Sysutils::Exception(
		Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EPrinter(int Ident, const System::TVarRec * Args, const 
		int Args_Size)/* overload */ : Sysutils::Exception(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EPrinter(const AnsiString Msg, int AHelpContext) : Sysutils::Exception(
		Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EPrinter(const AnsiString Msg, const System::TVarRec 
		* Args, const int Args_Size, int AHelpContext) : Sysutils::Exception(Msg, Args, Args_Size, AHelpContext
		) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EPrinter(int Ident, int AHelpContext)/* overload */
		 : Sysutils::Exception(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EPrinter(System::PResStringRec ResStringRec, const 
		System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : Sysutils::Exception(
		ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EPrinter(void) { }
	#pragma option pop
	
};


#pragma option push -b-
enum TPrinterState { psNoHandle, psHandleIC, psHandleDC };
#pragma option pop

#pragma option push -b-
enum TPrinterOrientation { poPortrait, poLandscape };
#pragma option pop

#pragma option push -b-
enum TPrinterCapability { pcCopies, pcOrientation, pcCollation };
#pragma option pop

typedef Set<TPrinterCapability, pcCopies, pcCollation>  TPrinterCapabilities;

class DELPHICLASS TPrinter;
class PASCALIMPLEMENTATION TPrinter : public System::TObject 
{
	typedef System::TObject inherited;
	
private:
	Graphics::TCanvas* FCanvas;
	Classes::TStrings* FFonts;
	int FPageNumber;
	Classes::TStrings* FPrinters;
	int FPrinterIndex;
	AnsiString FTitle;
	bool FPrinting;
	bool FAborted;
	TPrinterCapabilities FCapabilities;
	TPrinterState State;
	HDC DC;
	_devicemodeA *DevMode;
	unsigned DeviceMode;
	unsigned FPrinterHandle;
	void __fastcall SetState(TPrinterState Value);
	Graphics::TCanvas* __fastcall GetCanvas(void);
	int __fastcall GetNumCopies(void);
	Classes::TStrings* __fastcall GetFonts(void);
	HDC __fastcall GetHandle(void);
	TPrinterOrientation __fastcall GetOrientation(void);
	int __fastcall GetPageHeight(void);
	int __fastcall GetPageWidth(void);
	int __fastcall GetPrinterIndex(void);
	void __fastcall SetPrinterCapabilities(int Value);
	void __fastcall SetPrinterIndex(int Value);
	Classes::TStrings* __fastcall GetPrinters(void);
	void __fastcall SetNumCopies(int Value);
	void __fastcall SetOrientation(TPrinterOrientation Value);
	void __fastcall SetToDefaultPrinter(void);
	void __fastcall CheckPrinting(bool Value);
	void __fastcall FreePrinters(void);
	void __fastcall FreeFonts(void);
	
public:
	__fastcall TPrinter(void);
	__fastcall virtual ~TPrinter(void);
	void __fastcall Abort(void);
	void __fastcall BeginDoc(void);
	void __fastcall EndDoc(void);
	void __fastcall NewPage(void);
	void __fastcall GetPrinter(char * ADevice, char * ADriver, char * APort, unsigned &ADeviceMode);
	void __fastcall SetPrinter(char * ADevice, char * ADriver, char * APort, unsigned ADeviceMode);
	void __fastcall Refresh(void);
	__property bool Aborted = {read=FAborted, nodefault};
	__property Graphics::TCanvas* Canvas = {read=GetCanvas};
	__property TPrinterCapabilities Capabilities = {read=FCapabilities, nodefault};
	__property int Copies = {read=GetNumCopies, write=SetNumCopies, nodefault};
	__property Classes::TStrings* Fonts = {read=GetFonts};
	__property HDC Handle = {read=GetHandle, nodefault};
	__property TPrinterOrientation Orientation = {read=GetOrientation, write=SetOrientation, nodefault}
		;
	__property int PageHeight = {read=GetPageHeight, nodefault};
	__property int PageWidth = {read=GetPageWidth, nodefault};
	__property int PageNumber = {read=FPageNumber, nodefault};
	__property int PrinterIndex = {read=GetPrinterIndex, write=SetPrinterIndex, nodefault};
	__property bool Printing = {read=FPrinting, nodefault};
	__property Classes::TStrings* Printers = {read=GetPrinters};
	__property AnsiString Title = {read=FTitle, write=FTitle};
};


//-- var, const, procedure ---------------------------------------------------
extern PACKAGE void __fastcall AssignPrn(TextFile &F);
extern PACKAGE TPrinter* __fastcall Printer(void);
extern PACKAGE TPrinter* __fastcall SetPrinter(TPrinter* NewPrinter);

}	/* namespace Printers */
#if !defined(NO_IMPLICIT_NAMESPACE_USE)
using namespace Printers;
#endif
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// Printers
