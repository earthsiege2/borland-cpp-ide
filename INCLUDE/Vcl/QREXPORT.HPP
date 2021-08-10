// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'QRExport.pas' rev: 6.00

#ifndef QRExportHPP
#define QRExportHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <Forms.hpp>	// Pascal unit
#include <Printers.hpp>	// Pascal unit
#include <QR3Const.hpp>	// Pascal unit
#include <QRCtrls.hpp>	// Pascal unit
#include <StdCtrls.hpp>	// Pascal unit
#include <DB.hpp>	// Pascal unit
#include <QuickRpt.hpp>	// Pascal unit
#include <QRPrntr.hpp>	// Pascal unit
#include <Controls.hpp>	// Pascal unit
#include <Graphics.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <SysUtils.hpp>	// Pascal unit
#include <Messages.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Qrexport
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TTextEntry;
class PASCALIMPLEMENTATION TTextEntry : public Classes::TPersistent 
{
	typedef Classes::TPersistent inherited;
	
private:
	AnsiString FText;
	Extended XPos;
	Extended YPos;
	Classes::TAlignment FAlignment;
	Graphics::TFont* TextFont;
public:
	#pragma option push -w-inl
	/* TPersistent.Destroy */ inline __fastcall virtual ~TTextEntry(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall TTextEntry(void) : Classes::TPersistent() { }
	#pragma option pop
	
};


class DELPHICLASS TQRAbstractExportFilter;
class PASCALIMPLEMENTATION TQRAbstractExportFilter : public Qrprntr::TQRExportFilter 
{
	typedef Qrprntr::TQRExportFilter inherited;
	
private:
	Classes::TList* Entries;
	Classes::TStream* FStream;
	Extended FCharWidth;
	Extended FCharHeight;
	Extended FPaperWidth;
	Extended FPaperHeight;
	int FLineCount;
	int FColCount;
	bool FPageProcessed;
	Graphics::TFont* FFont;
	Graphics::TFont* FActiveFont;
	
protected:
	AnsiString __fastcall GetText(Extended X, Extended Y, Graphics::TFont* &Font);
	virtual AnsiString __fastcall GetFilterName();
	virtual AnsiString __fastcall GetDescription();
	virtual AnsiString __fastcall GetExtension();
	void __fastcall WriteToStream(const AnsiString AText);
	void __fastcall WriteLnToStream(const AnsiString AText);
	virtual void __fastcall CreateStream(AnsiString Filename);
	virtual void __fastcall CloseStream(void);
	void __fastcall ClearEntries(void);
	virtual void __fastcall ProcessPage(void);
	void __fastcall ConvertToColumns(void);
	void __fastcall ConvertToLines(void);
	virtual void __fastcall StorePage(void);
	__property Classes::TStream* Stream = {read=FStream, write=FStream};
	__property bool PageProcessed = {read=FPageProcessed, write=FPageProcessed, nodefault};
	__property Extended CharWidth = {read=FCharWidth, write=FCharWidth};
	__property Extended CharHeight = {read=FCharHeight, write=FCharHeight};
	__property Extended PaperWidth = {read=FPaperWidth, write=FPaperWidth};
	__property Extended PaperHeight = {read=FPaperHeight, write=FPaperHeight};
	__property int LineCount = {read=FLineCount, write=FLineCount, nodefault};
	__property int ColCount = {read=FColCount, write=FColCount, nodefault};
	
public:
	virtual void __fastcall Start(int PaperWidth, int PaperHeight, Graphics::TFont* Font);
	virtual void __fastcall EndPage(void);
	virtual void __fastcall Finish(void);
	virtual void __fastcall NewPage(void);
	virtual void __fastcall TextOut(Extended X, Extended Y, Graphics::TFont* Font, Graphics::TColor BGColor, Classes::TAlignment Alignment, AnsiString Text);
public:
	#pragma option push -w-inl
	/* TQRExportFilter.Create */ inline __fastcall TQRAbstractExportFilter(AnsiString Filename) : Qrprntr::TQRExportFilter(Filename) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TQRAbstractExportFilter(void) { }
	#pragma option pop
	
};


class DELPHICLASS TQRCommaSeparatedFilter;
class PASCALIMPLEMENTATION TQRCommaSeparatedFilter : public TQRAbstractExportFilter 
{
	typedef TQRAbstractExportFilter inherited;
	
protected:
	virtual AnsiString __fastcall GetFilterName();
	virtual AnsiString __fastcall GetDescription();
	virtual AnsiString __fastcall GetExtension();
	
public:
	virtual void __fastcall StorePage(void);
public:
	#pragma option push -w-inl
	/* TQRExportFilter.Create */ inline __fastcall TQRCommaSeparatedFilter(AnsiString Filename) : TQRAbstractExportFilter(Filename) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TQRCommaSeparatedFilter(void) { }
	#pragma option pop
	
};


class DELPHICLASS TQRCSVFilter;
class PASCALIMPLEMENTATION TQRCSVFilter : public Classes::TComponent 
{
	typedef Classes::TComponent inherited;
	
protected:
	char __fastcall GetSeparator(void);
	void __fastcall SetSeparator(char Value);
	
public:
	__fastcall virtual TQRCSVFilter(Classes::TComponent* AOwner);
	__fastcall virtual ~TQRCSVFilter(void);
	
__published:
	__property char Separator = {read=GetSeparator, write=SetSeparator, nodefault};
};


class DELPHICLASS TQRHTMLDocumentFilter;
class PASCALIMPLEMENTATION TQRHTMLDocumentFilter : public TQRAbstractExportFilter 
{
	typedef TQRAbstractExportFilter inherited;
	
private:
	bool FFreeStream;
	
protected:
	virtual AnsiString __fastcall GetFilterName();
	virtual AnsiString __fastcall GetDescription();
	virtual AnsiString __fastcall GetExtension();
	virtual bool __fastcall GetStreaming(void);
	virtual void __fastcall CreateStream(AnsiString Filename);
	virtual void __fastcall CloseStream(void);
	
public:
	virtual void __fastcall StorePage(void);
	__property Stream ;
	__property bool FreeStream = {read=FFreeStream, write=FFreeStream, nodefault};
public:
	#pragma option push -w-inl
	/* TQRExportFilter.Create */ inline __fastcall TQRHTMLDocumentFilter(AnsiString Filename) : TQRAbstractExportFilter(Filename) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TQRHTMLDocumentFilter(void) { }
	#pragma option pop
	
};


class DELPHICLASS TQRHTMLFilter;
class PASCALIMPLEMENTATION TQRHTMLFilter : public Classes::TComponent 
{
	typedef Classes::TComponent inherited;
	
public:
	__fastcall virtual TQRHTMLFilter(Classes::TComponent* AOwner);
	__fastcall virtual ~TQRHTMLFilter(void);
};


typedef AnsiString QRExport__8[201];

class DELPHICLASS TQRAsciiExportFilter;
class PASCALIMPLEMENTATION TQRAsciiExportFilter : public Qrprntr::TQRExportFilter 
{
	typedef Qrprntr::TQRExportFilter inherited;
	
private:
	int LineCount;
	AnsiString Lines[201];
	TextFile aFile;
	Extended XFactor;
	Extended YFactor;
	
protected:
	virtual AnsiString __fastcall GetFilterName();
	virtual AnsiString __fastcall GetDescription();
	virtual AnsiString __fastcall GetExtension();
	
public:
	virtual void __fastcall Start(int PaperWidth, int PaperHeight, Graphics::TFont* Font);
	virtual void __fastcall EndPage(void);
	virtual void __fastcall Finish(void);
	virtual void __fastcall NewPage(void);
	virtual void __fastcall TextOut(Extended X, Extended Y, Graphics::TFont* Font, Graphics::TColor BGColor, Classes::TAlignment Alignment, AnsiString Text);
public:
	#pragma option push -w-inl
	/* TQRExportFilter.Create */ inline __fastcall TQRAsciiExportFilter(AnsiString Filename) : Qrprntr::TQRExportFilter(Filename) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TQRAsciiExportFilter(void) { }
	#pragma option pop
	
};


class DELPHICLASS TQRTextFilter;
class PASCALIMPLEMENTATION TQRTextFilter : public Classes::TComponent 
{
	typedef Classes::TComponent inherited;
	
public:
	__fastcall virtual TQRTextFilter(Classes::TComponent* AOwner);
	__fastcall virtual ~TQRTextFilter(void);
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Qrexport */
using namespace Qrexport;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// QRExport
