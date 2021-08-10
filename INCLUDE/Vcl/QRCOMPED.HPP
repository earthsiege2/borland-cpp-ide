// Borland C++ Builder
// Copyright (c) 1995, 1999 by Borland International
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Qrcomped.pas' rev: 5.00

#ifndef QrcompedHPP
#define QrcompedHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <qr3const.hpp>	// Pascal unit
#include <Buttons.hpp>	// Pascal unit
#include <DBTables.hpp>	// Pascal unit
#include <Db.hpp>	// Pascal unit
#include <ExtCtrls.hpp>	// Pascal unit
#include <qrabout.hpp>	// Pascal unit
#include <QuickRpt.hpp>	// Pascal unit
#include <QRPrntr.hpp>	// Pascal unit
#include <Printers.hpp>	// Pascal unit
#include <ComCtrls.hpp>	// Pascal unit
#include <StdCtrls.hpp>	// Pascal unit
#include <Dialogs.hpp>	// Pascal unit
#include <Forms.hpp>	// Pascal unit
#include <Controls.hpp>	// Pascal unit
#include <Graphics.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <SysUtils.hpp>	// Pascal unit
#include <Messages.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Qrcomped
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TQRCompEd;
class PASCALIMPLEMENTATION TQRCompEd : public Forms::TForm 
{
	typedef Forms::TForm inherited;
	
__published:
	Stdctrls::TButton* About;
	Stdctrls::TButton* Preview;
	Stdctrls::TButton* Apply1;
	Stdctrls::TButton* OK1;
	Stdctrls::TButton* Cancel1;
	Stdctrls::TGroupBox* PaperSizeGB;
	Stdctrls::TLabel* Label5;
	Stdctrls::TLabel* Label6;
	Stdctrls::TComboBox* PaperSize;
	Stdctrls::TEdit* PageWidth;
	Stdctrls::TEdit* PageLength;
	Stdctrls::TComboBox* OrientationCB;
	Stdctrls::TGroupBox* MarginsGB;
	Stdctrls::TLabel* Label1;
	Stdctrls::TLabel* Label2;
	Stdctrls::TLabel* Label3;
	Stdctrls::TLabel* Label4;
	Stdctrls::TLabel* Label7;
	Stdctrls::TEdit* Topmargin;
	Stdctrls::TEdit* BottomMargin;
	Stdctrls::TEdit* LeftMargin;
	Stdctrls::TEdit* RightMargin;
	Stdctrls::TEdit* ColumnMargin;
	Stdctrls::TGroupBox* OtherGB;
	Stdctrls::TLabel* Label9;
	Stdctrls::TLabel* Label10;
	Stdctrls::TLabel* Label11;
	Stdctrls::TComboBox* Units;
	Stdctrls::TComboBox* FontName;
	Stdctrls::TComboBox* FontSize;
	Stdctrls::TLabel* Label8;
	Stdctrls::TEdit* Columns;
	Stdctrls::TGroupBox* PageFrameGB;
	Stdctrls::TLabel* Label12;
	Extctrls::TShape* FrameColor;
	Stdctrls::TLabel* Label13;
	Stdctrls::TCheckBox* PageFrameTop;
	Stdctrls::TCheckBox* PageFrameBottom;
	Stdctrls::TCheckBox* PageFrameLeft;
	Stdctrls::TCheckBox* PageFrameRight;
	Stdctrls::TButton* ColorButton;
	Stdctrls::TEdit* PageFramePenWidth;
	Stdctrls::TGroupBox* BandsGB;
	Stdctrls::TLabel* Label14;
	Stdctrls::TLabel* Label15;
	Stdctrls::TCheckBox* Title;
	Stdctrls::TCheckBox* PageHeader;
	Stdctrls::TCheckBox* ColumnHeader;
	Stdctrls::TCheckBox* Detail;
	Stdctrls::TEdit* PageHeaderLength;
	Stdctrls::TEdit* TitleLength;
	Stdctrls::TEdit* ColumnHeaderLength;
	Stdctrls::TEdit* DetailLength;
	Stdctrls::TEdit* SummaryLength;
	Stdctrls::TCheckBox* PageFooter;
	Stdctrls::TCheckBox* Summary;
	Stdctrls::TEdit* PageFooterLength;
	Stdctrls::TCheckBox* FirstPageHeader;
	Stdctrls::TCheckBox* LastPageFooter;
	Buttons::TSpeedButton* SpeedButton1;
	Buttons::TSpeedButton* SpeedButton2;
	Buttons::TSpeedButton* SpeedButton3;
	Buttons::TSpeedButton* SpeedButton4;
	void __fastcall FormCreate(System::TObject* Sender);
	void __fastcall Cancel1Click(System::TObject* Sender);
	void __fastcall OK1Click(System::TObject* Sender);
	void __fastcall Apply1Click(System::TObject* Sender);
	void __fastcall FloatKeyPress(System::TObject* Sender, char &Key);
	void __fastcall PageWidthExit(System::TObject* Sender);
	void __fastcall AboutClick(System::TObject* Sender);
	void __fastcall PreviewClick(System::TObject* Sender);
	void __fastcall ColorButtonClick(System::TObject* Sender);
	void __fastcall FormDestroy(System::TObject* Sender);
	void __fastcall SpeedButton1Click(System::TObject* Sender);
	void __fastcall SpeedButton2Click(System::TObject* Sender);
	void __fastcall SpeedButton3Click(System::TObject* Sender);
	void __fastcall SpeedButton4Click(System::TObject* Sender);
	void __fastcall PageWidthEnter(System::TObject* Sender);
	
private:
	Quickrpt::TQuickRep* FQuickRep;
	Classes::TStrings* FAvailableDataSets;
	AnsiString Saver;
	void __fastcall GetValues(void);
	void __fastcall SetValues(void);
	void __fastcall SetQuickRep(Quickrpt::TQuickRep* Value);
	void __fastcall SetAvailableDataSets(Classes::TStrings* Value);
	void __fastcall ChangeValue(Stdctrls::TEdit* Edit, int Value, int MinValue);
	
public:
	__property Quickrpt::TQuickRep* QuickRep = {read=FQuickRep, write=SetQuickRep};
	__property Classes::TStrings* AvailableDataSets = {read=FAvailableDataSets, write=SetAvailableDataSets
		};
public:
	#pragma option push -w-inl
	/* TCustomForm.Create */ inline __fastcall virtual TQRCompEd(Classes::TComponent* AOwner) : Forms::TForm(
		AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.CreateNew */ inline __fastcall virtual TQRCompEd(Classes::TComponent* AOwner, int Dummy
		) : Forms::TForm(AOwner, Dummy) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.Destroy */ inline __fastcall virtual ~TQRCompEd(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TQRCompEd(HWND ParentWindow) : Forms::TForm(ParentWindow
		) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Qrcomped */
#if !defined(NO_IMPLICIT_NAMESPACE_USE)
using namespace Qrcomped;
#endif
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// Qrcomped
