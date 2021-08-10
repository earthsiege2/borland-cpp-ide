// Borland C++ Builder
// Copyright (c) 1995, 1999 by Borland International
// All rights reserved

// (DO NOT EDIT: machine generated header) 'qrextra.pas' rev: 5.00

#ifndef qrextraHPP
#define qrextraHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <QRPrev.hpp>	// Pascal unit
#include <DBTables.hpp>	// Pascal unit
#include <QRExpbld.hpp>	// Pascal unit
#include <Qrcomped.hpp>	// Pascal unit
#include <Qrctrls.hpp>	// Pascal unit
#include <QuickRpt.hpp>	// Pascal unit
#include <QRPrntr.hpp>	// Pascal unit
#include <Clipbrd.hpp>	// Pascal unit
#include <Db.hpp>	// Pascal unit
#include <Printers.hpp>	// Pascal unit
#include <Dialogs.hpp>	// Pascal unit
#include <Forms.hpp>	// Pascal unit
#include <Buttons.hpp>	// Pascal unit
#include <Graphics.hpp>	// Pascal unit
#include <ExtCtrls.hpp>	// Pascal unit
#include <StdCtrls.hpp>	// Pascal unit
#include <Controls.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <SysUtils.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Qrextra
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TQRPrintJob;
class PASCALIMPLEMENTATION TQRPrintJob : public System::TObject 
{
	typedef System::TObject inherited;
	
protected:
	virtual void __fastcall CreateOutput(Qrprntr::TQRPrinter* AQRPrinter);
	
public:
	void __fastcall Preview(void);
	void __fastcall Print(void);
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall TQRPrintJob(void) : System::TObject() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TQRPrintJob(void) { }
	#pragma option pop
	
};


class DELPHICLASS TQRPHandler;
class PASCALIMPLEMENTATION TQRPHandler : public System::TObject 
{
	typedef System::TObject inherited;
	
private:
	AnsiString FFilename;
	Qrprntr::TQRPrinter* FQRPrinter;
	
protected:
	void __fastcall SetFilename(AnsiString Value);
	
public:
	__fastcall TQRPHandler(void);
	__fastcall virtual ~TQRPHandler(void);
	void __fastcall Preview(void);
	void __fastcall Print(void);
	__property AnsiString Filename = {read=FFilename, write=SetFilename};
};


class DELPHICLASS TQRBuilder;
class PASCALIMPLEMENTATION TQRBuilder : public Classes::TComponent 
{
	typedef Classes::TComponent inherited;
	
private:
	bool FActive;
	Graphics::TFont* FFont;
	Printers::TPrinterOrientation FOrientation;
	Quickrpt::TCustomQuickRep* FReport;
	AnsiString FTitle;
	Classes::TStrings* NameList;
	
protected:
	AnsiString __fastcall NewName(AnsiString AClassName);
	virtual void __fastcall BuildFramework(void);
	void __fastcall RenameObjects(void);
	virtual void __fastcall SetActive(bool Value);
	virtual void __fastcall SetOrientation(Printers::TPrinterOrientation Value);
	virtual void __fastcall SetTitle(AnsiString Value);
	
public:
	__fastcall virtual TQRBuilder(Classes::TComponent* AOwner);
	__fastcall virtual ~TQRBuilder(void);
	Quickrpt::TCustomQuickRep* __fastcall FetchReport(void);
	__property bool Active = {read=FActive, write=SetActive, nodefault};
	__property Graphics::TFont* Font = {read=FFont, write=FFont};
	__property Printers::TPrinterOrientation Orientation = {read=FOrientation, write=SetOrientation, nodefault
		};
	__property Quickrpt::TCustomQuickRep* Report = {read=FReport, write=FReport};
	__property AnsiString Title = {read=FTitle, write=SetTitle};
};


class DELPHICLASS TQRListBuilder;
class PASCALIMPLEMENTATION TQRListBuilder : public TQRBuilder 
{
	typedef TQRBuilder inherited;
	
private:
	Db::TDataSet* FDataSet;
	Classes::TStrings* FFields;
	void __fastcall SetFields(Classes::TStrings* Value);
	
protected:
	virtual void __fastcall SetActive(bool Value);
	virtual void __fastcall BuildList(void);
	
public:
	__fastcall virtual TQRListBuilder(Classes::TComponent* AOwner);
	__fastcall virtual ~TQRListBuilder(void);
	void __fastcall AddAllFields(void);
	__property Db::TDataSet* DataSet = {read=FDataSet, write=FDataSet};
	__property Classes::TStrings* Fields = {read=FFields, write=SetFields};
};


//-- var, const, procedure ---------------------------------------------------
extern PACKAGE void __fastcall PopulateFontSizeCombo(Stdctrls::TComboBox* aCombo);
extern PACKAGE Classes::TStrings* __fastcall AllDataSets(Forms::TCustomForm* Form, bool IncludeDataModules
	);
extern PACKAGE Quickrpt::TQuickRep* __fastcall QRLoadReport(AnsiString Filename);
extern PACKAGE void __fastcall QRFreeReport(Quickrpt::TQuickRep* aReport);
extern PACKAGE void __fastcall QRCreateList(Quickrpt::TCustomQuickRep* &AReport, Classes::TComponent* 
	AOwner, Db::TDataSet* aDataSet, AnsiString aTitle, Classes::TStrings* aFieldList);

}	/* namespace Qrextra */
#if !defined(NO_IMPLICIT_NAMESPACE_USE)
using namespace Qrextra;
#endif
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// qrextra
