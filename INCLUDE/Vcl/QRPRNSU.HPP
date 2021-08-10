// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'QRPrnSu.pas' rev: 6.00

#ifndef QRPrnSuHPP
#define QRPrnSuHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <Printers.hpp>	// Pascal unit
#include <Dialogs.hpp>	// Pascal unit
#include <StdCtrls.hpp>	// Pascal unit
#include <Forms.hpp>	// Pascal unit
#include <Controls.hpp>	// Pascal unit
#include <Graphics.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <CommDlg.hpp>	// Pascal unit
#include <SysUtils.hpp>	// Pascal unit
#include <Messages.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Qrprnsu
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TQRCommonDialog;
class PASCALIMPLEMENTATION TQRCommonDialog : public Classes::TComponent 
{
	typedef Classes::TComponent inherited;
	
private:
	bool FCtl3D;
	void *FDefWndProc;
	Classes::THelpContext FHelpContext;
	HWND FHandle;
	void *FObjectInstance;
	char *FTemplate;
	Classes::TNotifyEvent FOnClose;
	Classes::TNotifyEvent FOnShow;
	MESSAGE void __fastcall WMDestroy(Messages::TWMNoParams &Message);
	MESSAGE void __fastcall WMInitDialog(Messages::TWMInitDialog &Message);
	MESSAGE void __fastcall WMNCDestroy(Messages::TWMNoParams &Message);
	
protected:
	virtual void __fastcall DefaultHandler(void *Message);
	virtual void __fastcall WndProc(Messages::TMessage &Message);
	virtual bool __fastcall MessageHook(Messages::TMessage &Msg);
	virtual BOOL __fastcall TaskModalDialog(void * DialogFunc, void *DialogData);
	DYNAMIC void __fastcall DoClose(void);
	DYNAMIC void __fastcall DoShow(void);
	virtual bool __fastcall Execute(void) = 0 ;
	__property char * Template = {read=FTemplate, write=FTemplate};
	
public:
	__fastcall virtual TQRCommonDialog(Classes::TComponent* AOwner);
	__fastcall virtual ~TQRCommonDialog(void);
	__property HWND Handle = {read=FHandle, nodefault};
	
__published:
	__property bool Ctl3D = {read=FCtl3D, write=FCtl3D, default=1};
	__property Classes::THelpContext HelpContext = {read=FHelpContext, write=FHelpContext, default=0};
	__property Classes::TNotifyEvent OnClose = {read=FOnClose, write=FOnClose};
	__property Classes::TNotifyEvent OnShow = {read=FOnShow, write=FOnShow};
};


class DELPHICLASS TQRBasePrintDialog;
class PASCALIMPLEMENTATION TQRBasePrintDialog : public TQRCommonDialog 
{
	typedef TQRCommonDialog inherited;
	
private:
	Printers::TPrinter* FPrinter;
	
protected:
	char Device[80];
	char Driver[80];
	char Port[80];
	unsigned __fastcall CopyData(unsigned Handle);
	void __fastcall SetPrinter(unsigned DeviceMode, unsigned DeviceNames);
	void __fastcall GetPrinter(unsigned &DeviceMode, unsigned &DeviceNames);
	
public:
	__fastcall virtual TQRBasePrintDialog(Classes::TComponent* AOwner);
	__property Printers::TPrinter* Printer = {read=FPrinter, write=FPrinter};
public:
	#pragma option push -w-inl
	/* TQRCommonDialog.Destroy */ inline __fastcall virtual ~TQRBasePrintDialog(void) { }
	#pragma option pop
	
};


class DELPHICLASS TQRPrinterSetupDialog;
class PASCALIMPLEMENTATION TQRPrinterSetupDialog : public TQRBasePrintDialog 
{
	typedef TQRBasePrintDialog inherited;
	
public:
	virtual bool __fastcall Execute(void);
public:
	#pragma option push -w-inl
	/* TQRBasePrintDialog.Create */ inline __fastcall virtual TQRPrinterSetupDialog(Classes::TComponent* AOwner) : TQRBasePrintDialog(AOwner) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TQRCommonDialog.Destroy */ inline __fastcall virtual ~TQRPrinterSetupDialog(void) { }
	#pragma option pop
	
};


class DELPHICLASS TQRPrintDialog;
class PASCALIMPLEMENTATION TQRPrintDialog : public TQRBasePrintDialog 
{
	typedef TQRBasePrintDialog inherited;
	
private:
	int FFromPage;
	int FToPage;
	bool FCollate;
	Dialogs::TPrintDialogOptions FOptions;
	bool FPrintToFile;
	Dialogs::TPrintRange FPrintRange;
	int FMinPage;
	int FMaxPage;
	int FCopies;
	void __fastcall SetNumCopies(int Value);
	
public:
	virtual bool __fastcall Execute(void);
	
__published:
	__property bool Collate = {read=FCollate, write=FCollate, default=0};
	__property int Copies = {read=FCopies, write=SetNumCopies, default=0};
	__property int FromPage = {read=FFromPage, write=FFromPage, default=0};
	__property int MinPage = {read=FMinPage, write=FMinPage, default=0};
	__property int MaxPage = {read=FMaxPage, write=FMaxPage, default=0};
	__property Dialogs::TPrintDialogOptions Options = {read=FOptions, write=FOptions, default=0};
	__property bool PrintToFile = {read=FPrintToFile, write=FPrintToFile, default=0};
	__property Dialogs::TPrintRange PrintRange = {read=FPrintRange, write=FPrintRange, default=0};
	__property int ToPage = {read=FToPage, write=FToPage, default=0};
public:
	#pragma option push -w-inl
	/* TQRBasePrintDialog.Create */ inline __fastcall virtual TQRPrintDialog(Classes::TComponent* AOwner) : TQRBasePrintDialog(AOwner) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TQRCommonDialog.Destroy */ inline __fastcall virtual ~TQRPrintDialog(void) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------
static const Shortint MaxCustomColors = 0x10;

}	/* namespace Qrprnsu */
using namespace Qrprnsu;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// QRPrnSu
