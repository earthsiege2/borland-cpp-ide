// Borland C++ Builder
// Copyright (c) 1995, 1999 by Borland International
// All rights reserved

// (DO NOT EDIT: machine generated header) 'TeeAbout.pas' rev: 5.00

#ifndef TeeAboutHPP
#define TeeAboutHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <ComCtrls.hpp>	// Pascal unit
#include <Buttons.hpp>	// Pascal unit
#include <ExtCtrls.hpp>	// Pascal unit
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

namespace Teeabout
{
//-- type declarations -------------------------------------------------------
#pragma pack(push, 1)
struct TTeeProduct
{
	AnsiString Description;
	int Price;
	int Ship;
} ;
#pragma pack(pop)

typedef TTeeProduct TeeAbout__2[11];

class DELPHICLASS TTeeAboutForm;
class PASCALIMPLEMENTATION TTeeAboutForm : public Forms::TForm 
{
	typedef Forms::TForm inherited;
	
__published:
	Stdctrls::TButton* BClose;
	Stdctrls::TLabel* LabelVersion;
	Stdctrls::TButton* BNext;
	Stdctrls::TButton* BPrevious;
	Dialogs::TPrintDialog* PrintDialog1;
	Dialogs::TSaveDialog* SaveDialog1;
	Extctrls::TPanel* Panel1;
	Extctrls::TNotebook* Notebook1;
	Extctrls::TImage* Image1;
	Stdctrls::TLabel* Label2;
	Stdctrls::TLabel* Label3;
	Stdctrls::TLabel* LabelSourceCode;
	Stdctrls::TLabel* Labelwww;
	Stdctrls::TLabel* LabelVersions;
	Stdctrls::TGroupBox* GroupBox2;
	Stdctrls::TLabel* Label9;
	Stdctrls::TLabel* Label8;
	Stdctrls::TLabel* Label10;
	Stdctrls::TLabel* Label11;
	Stdctrls::TLabel* Label16;
	Stdctrls::TLabel* Label14;
	Stdctrls::TLabel* Label15;
	Stdctrls::TLabel* Label13;
	Stdctrls::TLabel* Label12;
	Stdctrls::TLabel* Label17;
	Stdctrls::TEdit* EAddress;
	Stdctrls::TEdit* ECity;
	Stdctrls::TEdit* EState;
	Stdctrls::TEdit* EZIP;
	Stdctrls::TEdit* ECountry;
	Stdctrls::TEdit* EPhone;
	Stdctrls::TEdit* EEMail;
	Stdctrls::TEdit* ECompany;
	Stdctrls::TEdit* EName;
	Stdctrls::TEdit* EFAX;
	Stdctrls::TGroupBox* GPCard;
	Stdctrls::TLabel* Label19;
	Stdctrls::TLabel* Label20;
	Stdctrls::TEdit* ECardNumber;
	Stdctrls::TEdit* ECardDate;
	Stdctrls::TLabel* LabelThanks;
	Stdctrls::TButton* BPrintOrder;
	Stdctrls::TButton* BSaveOrder;
	Stdctrls::TButton* BCopyOrder;
	Extctrls::TRadioGroup* RGLicense;
	Extctrls::TPanel* Panel3;
	Stdctrls::TLabel* Label31;
	Stdctrls::TEdit* SEQuantity;
	Stdctrls::TLabel* Label32;
	Extctrls::TPanel* Panel4;
	Stdctrls::TLabel* Label23;
	Stdctrls::TLabel* LTotal;
	Stdctrls::TLabel* Label18;
	Stdctrls::TEdit* ECardHolder;
	Extctrls::TRadioGroup* CBPaymentType;
	Stdctrls::TComboBox* CBShip;
	Stdctrls::TLabel* LShip;
	Stdctrls::TLabel* Label6;
	Stdctrls::TEdit* EECTax;
	Extctrls::TPanel* Panel2;
	Stdctrls::TLabel* Label24;
	Stdctrls::TLabel* Label25;
	Stdctrls::TLabel* Label26;
	Stdctrls::TLabel* Label28;
	Stdctrls::TLabel* Label27;
	Stdctrls::TLabel* Label33;
	Stdctrls::TLabel* Label34;
	Stdctrls::TLabel* Label29;
	Stdctrls::TLabel* Label30;
	Stdctrls::TLabel* Label22;
	Stdctrls::TLabel* Label36;
	Stdctrls::TLabel* Label37;
	Stdctrls::TLabel* Label35;
	Stdctrls::TLabel* Label38;
	Stdctrls::TMemo* Memo1;
	Stdctrls::TLabel* Label39;
	Buttons::TBitBtn* BOrder;
	Stdctrls::TLabel* Label40;
	Stdctrls::TLabel* Label41;
	Comctrls::TUpDown* UDQuantity;
	Extctrls::TImage* Image2;
	void __fastcall BCloseClick(System::TObject* Sender);
	void __fastcall BOrderClick(System::TObject* Sender);
	void __fastcall FormCreate(System::TObject* Sender);
	void __fastcall BNextClick(System::TObject* Sender);
	void __fastcall BPreviousClick(System::TObject* Sender);
	void __fastcall BPrintOrderClick(System::TObject* Sender);
	void __fastcall BSaveOrderClick(System::TObject* Sender);
	void __fastcall BCopyOrderClick(System::TObject* Sender);
	void __fastcall SEQuantityChange(System::TObject* Sender);
	void __fastcall FormCloseQuery(System::TObject* Sender, bool &CanClose);
	void __fastcall RGLicenseClick(System::TObject* Sender);
	void __fastcall CBPaymentTypeChange(System::TObject* Sender);
	void __fastcall CBShipChange(System::TObject* Sender);
	void __fastcall ENameKeyPress(System::TObject* Sender, char &Key);
	void __fastcall LabelwwwClick(System::TObject* Sender);
	void __fastcall FormShow(System::TObject* Sender);
	
public:
	bool OrderProcessed;
	int ProductCount;
	TTeeProduct TeeProducts[11];
	bool ShowOrderInfo;
	void __fastcall CheckButtons(void);
	Classes::TStringList* __fastcall GetOrderForm(void);
	AnsiString __fastcall FormatUSD(int Value);
	int __fastcall ShippingPrice(void);
	void __fastcall RefreshTotal(void);
	int __fastcall CalcTotal(void);
	int __fastcall NumCopies(void);
	void __fastcall ClearProducts(void);
	void __fastcall AddProduct(const AnsiString ADesc, int APrice, int AShip);
public:
	#pragma option push -w-inl
	/* TCustomForm.Create */ inline __fastcall virtual TTeeAboutForm(Classes::TComponent* AOwner) : Forms::TForm(
		AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.CreateNew */ inline __fastcall virtual TTeeAboutForm(Classes::TComponent* AOwner, int 
		Dummy) : Forms::TForm(AOwner, Dummy) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.Destroy */ inline __fastcall virtual ~TTeeAboutForm(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TTeeAboutForm(HWND ParentWindow) : Forms::TForm(
		ParentWindow) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------
extern PACKAGE AnsiString TeeDefProductName;
extern PACKAGE void __fastcall TeeShowAboutBox(bool ShowOrder);
extern PACKAGE void __fastcall GotoURL(int Handle, const AnsiString URL);

}	/* namespace Teeabout */
#if !defined(NO_IMPLICIT_NAMESPACE_USE)
using namespace Teeabout;
#endif
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// TeeAbout
