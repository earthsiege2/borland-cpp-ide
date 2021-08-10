// Borland C++ Builder
// Copyright (c) 1995, 1999 by Borland International
// All rights reserved

// (DO NOT EDIT: machine generated header) 'TeePrevi.pas' rev: 5.00

#ifndef TeePreviHPP
#define TeePreviHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <ComCtrls.hpp>	// Pascal unit
#include <TeeProcs.hpp>	// Pascal unit
#include <Buttons.hpp>	// Pascal unit
#include <StdCtrls.hpp>	// Pascal unit
#include <ExtCtrls.hpp>	// Pascal unit
#include <Dialogs.hpp>	// Pascal unit
#include <Forms.hpp>	// Pascal unit
#include <Controls.hpp>	// Pascal unit
#include <Graphics.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <Messages.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <SysUtils.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Teeprevi
{
//-- type declarations -------------------------------------------------------
typedef void __fastcall (__closure *TOnChangeMarginsEvent)(System::TObject* Sender, bool DisableProportional
	, const Windows::TRect &NewMargins);

#pragma option push -b-
enum TeePreviewZones { teePrev_None, teePrev_Left, teePrev_Top, teePrev_Right, teePrev_Bottom, teePrev_Image, 
	teePrev_LeftTop, teePrev_RightTop, teePrev_LeftBottom, teePrev_RightBottom };
#pragma option pop

class DELPHICLASS TTeePreviewPage;
class PASCALIMPLEMENTATION TTeePreviewPage : public Controls::TGraphicControl 
{
	typedef Controls::TGraphicControl inherited;
	
private:
	bool FAllowResize;
	bool FAllowMove;
	bool FAsBitmap;
	Teeprocs::TCustomTeePanel* FImage;
	bool FDragImage;
	TOnChangeMarginsEvent FOnChangeMargins;
	bool FOldShowImage;
	Graphics::TColor FPaperColor;
	bool FShowImage;
	bool FShowMargins;
	TeePreviewZones FDragged;
	int OldX;
	int OldY;
	Windows::TRect OldRect;
	Windows::TRect ImageRect;
	Windows::TRect PaperRect;
	void __fastcall SetShowMargins(bool Value);
	void __fastcall SetImage(Teeprocs::TCustomTeePanel* Value);
	Graphics::TBitmap* __fastcall GetPrintingBitmap(void);
	
protected:
	virtual void __fastcall Paint(void);
	DYNAMIC void __fastcall MouseDown(Controls::TMouseButton Button, Classes::TShiftState Shift, int X, 
		int Y);
	DYNAMIC void __fastcall MouseUp(Controls::TMouseButton Button, Classes::TShiftState Shift, int X, int 
		Y);
	DYNAMIC void __fastcall MouseMove(Classes::TShiftState Shift, int X, int Y);
	
public:
	__fastcall virtual TTeePreviewPage(Classes::TComponent* AOwner);
	Windows::TRect __fastcall CalcImagePrintMargins();
	void __fastcall DrawPaper(Graphics::TCanvas* ACanvas);
	void __fastcall DrawBack(Graphics::TCanvas* ACanvas);
	void __fastcall DrawImage(Graphics::TCanvas* ACanvas);
	void __fastcall DrawMargins(Graphics::TCanvas* ACanvas);
	TeePreviewZones __fastcall WhereIsCursor(int x, int y);
	void __fastcall Print(void);
	
__published:
	__property bool AllowResize = {read=FAllowResize, write=FAllowResize, default=1};
	__property bool AllowMove = {read=FAllowMove, write=FAllowMove, default=1};
	__property bool AsBitmap = {read=FAsBitmap, write=FAsBitmap, nodefault};
	__property bool DragImage = {read=FDragImage, write=FDragImage, default=0};
	__property Graphics::TColor PaperColor = {read=FPaperColor, write=FPaperColor, nodefault};
	__property bool ShowImage = {read=FShowImage, write=FShowImage, default=1};
	__property bool ShowMargins = {read=FShowMargins, write=SetShowMargins, default=1};
	__property TOnChangeMarginsEvent OnChangeMargins = {read=FOnChangeMargins, write=FOnChangeMargins};
		
	__property Teeprocs::TCustomTeePanel* Image = {read=FImage, write=SetImage};
public:
	#pragma option push -w-inl
	/* TGraphicControl.Destroy */ inline __fastcall virtual ~TTeePreviewPage(void) { }
	#pragma option pop
	
};


class DELPHICLASS TChartPreview;
class PASCALIMPLEMENTATION TChartPreview : public Forms::TForm 
{
	typedef Forms::TForm inherited;
	
__published:
	Extctrls::TPanel* Panel1;
	Stdctrls::TComboBox* Printers;
	Stdctrls::TLabel* Label1;
	Buttons::TBitBtn* BSetupPrinter;
	Extctrls::TPanel* Panel2;
	Extctrls::TRadioGroup* Orientation;
	Stdctrls::TGroupBox* GBMargins;
	Stdctrls::TEdit* SETopMa;
	Stdctrls::TEdit* SELeftMa;
	Stdctrls::TEdit* SEBotMa;
	Stdctrls::TEdit* SERightMa;
	Dialogs::TPrinterSetupDialog* PrinterSetupDialog1;
	Stdctrls::TCheckBox* ShowMargins;
	Stdctrls::TButton* BReset;
	Stdctrls::TGroupBox* ChangeDetailGroup;
	Stdctrls::TLabel* Label2;
	Stdctrls::TLabel* Label3;
	Stdctrls::TButton* BClose;
	Stdctrls::TScrollBar* Resolution;
	Stdctrls::TButton* BPrint;
	Comctrls::TUpDown* UDLeftMa;
	Comctrls::TUpDown* UDTopMa;
	Comctrls::TUpDown* UDRightMa;
	Comctrls::TUpDown* UDBotMa;
	Stdctrls::TCheckBox* CBProp;
	void __fastcall FormShow(System::TObject* Sender);
	void __fastcall BSetupPrinterClick(System::TObject* Sender);
	void __fastcall PrintersChange(System::TObject* Sender);
	void __fastcall OrientationClick(System::TObject* Sender);
	void __fastcall SETopMaChange(System::TObject* Sender);
	void __fastcall SERightMaChange(System::TObject* Sender);
	void __fastcall SEBotMaChange(System::TObject* Sender);
	void __fastcall SELeftMaChange(System::TObject* Sender);
	void __fastcall ShowMarginsClick(System::TObject* Sender);
	void __fastcall FormCreate(System::TObject* Sender);
	void __fastcall BResetClick(System::TObject* Sender);
	void __fastcall ResolutionChange(System::TObject* Sender);
	void __fastcall BPrintClick(System::TObject* Sender);
	void __fastcall FormDestroy(System::TObject* Sender);
	void __fastcall BCloseClick(System::TObject* Sender);
	void __fastcall CBPropClick(System::TObject* Sender);
	
private:
	bool CreatingForm;
	bool ChangingMargins;
	bool ChangingProp;
	void __fastcall ResetMargins(void);
	
protected:
	HIDESBASE MESSAGE void __fastcall WMEraseBkgnd(Messages::TWMEraseBkgnd &Message);
	
public:
	TTeePreviewPage* PreviewPage;
	Windows::TRect OldMargins;
	void __fastcall RefreshPage(void);
	void __fastcall RecalcControls(void);
	void __fastcall PreviewPageChangeMargins(System::TObject* Sender, bool DisableProportional, const Windows::TRect 
		&NewMargins);
	void __fastcall ChangeMargin(Comctrls::TUpDown* UpDown, int &APos, int OtherSide);
public:
	#pragma option push -w-inl
	/* TCustomForm.Create */ inline __fastcall virtual TChartPreview(Classes::TComponent* AOwner) : Forms::TForm(
		AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.CreateNew */ inline __fastcall virtual TChartPreview(Classes::TComponent* AOwner, int 
		Dummy) : Forms::TForm(AOwner, Dummy) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.Destroy */ inline __fastcall virtual ~TChartPreview(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TChartPreview(HWND ParentWindow) : Forms::TForm(
		ParentWindow) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------
extern PACKAGE void __fastcall ChartPreview(Classes::TComponent* AOwner, Teeprocs::TCustomTeePanel* 
	TeePanel);

}	/* namespace Teeprevi */
#if !defined(NO_IMPLICIT_NAMESPACE_USE)
using namespace Teeprevi;
#endif
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// TeePrevi
