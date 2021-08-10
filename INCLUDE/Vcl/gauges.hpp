// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Gauges.pas' rev: 6.00

#ifndef GaugesHPP
#define GaugesHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <Menus.hpp>	// Pascal unit
#include <StdCtrls.hpp>	// Pascal unit
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

namespace Gauges
{
//-- type declarations -------------------------------------------------------
#pragma option push -b-
enum TGaugeKind { gkText, gkHorizontalBar, gkVerticalBar, gkPie, gkNeedle };
#pragma option pop

class DELPHICLASS TGauge;
class PASCALIMPLEMENTATION TGauge : public Controls::TGraphicControl 
{
	typedef Controls::TGraphicControl inherited;
	
private:
	int FMinValue;
	int FMaxValue;
	int FCurValue;
	TGaugeKind FKind;
	bool FShowText;
	Forms::TFormBorderStyle FBorderStyle;
	Graphics::TColor FForeColor;
	Graphics::TColor FBackColor;
	void __fastcall PaintBackground(Graphics::TBitmap* AnImage);
	void __fastcall PaintAsText(Graphics::TBitmap* AnImage, const Types::TRect &PaintRect);
	void __fastcall PaintAsNothing(Graphics::TBitmap* AnImage, const Types::TRect &PaintRect);
	void __fastcall PaintAsBar(Graphics::TBitmap* AnImage, const Types::TRect &PaintRect);
	void __fastcall PaintAsPie(Graphics::TBitmap* AnImage, const Types::TRect &PaintRect);
	void __fastcall PaintAsNeedle(Graphics::TBitmap* AnImage, const Types::TRect &PaintRect);
	void __fastcall SetGaugeKind(TGaugeKind Value);
	void __fastcall SetShowText(bool Value);
	void __fastcall SetBorderStyle(Forms::TBorderStyle Value);
	void __fastcall SetForeColor(Graphics::TColor Value);
	void __fastcall SetBackColor(Graphics::TColor Value);
	void __fastcall SetMinValue(int Value);
	void __fastcall SetMaxValue(int Value);
	void __fastcall SetProgress(int Value);
	int __fastcall GetPercentDone(void);
	
protected:
	virtual void __fastcall Paint(void);
	
public:
	__fastcall virtual TGauge(Classes::TComponent* AOwner);
	void __fastcall AddProgress(int Value);
	__property int PercentDone = {read=GetPercentDone, nodefault};
	
__published:
	__property Align  = {default=0};
	__property Anchors  = {default=3};
	__property Graphics::TColor BackColor = {read=FBackColor, write=SetBackColor, default=16777215};
	__property Forms::TBorderStyle BorderStyle = {read=FBorderStyle, write=SetBorderStyle, default=1};
	__property Color  = {default=-2147483643};
	__property Constraints ;
	__property Enabled  = {default=1};
	__property Graphics::TColor ForeColor = {read=FForeColor, write=SetForeColor, default=0};
	__property Font ;
	__property TGaugeKind Kind = {read=FKind, write=SetGaugeKind, default=1};
	__property int MinValue = {read=FMinValue, write=SetMinValue, default=0};
	__property int MaxValue = {read=FMaxValue, write=SetMaxValue, default=100};
	__property ParentColor  = {default=1};
	__property ParentFont  = {default=1};
	__property ParentShowHint  = {default=1};
	__property PopupMenu ;
	__property int Progress = {read=FCurValue, write=SetProgress, nodefault};
	__property ShowHint ;
	__property bool ShowText = {read=FShowText, write=SetShowText, default=1};
	__property Visible  = {default=1};
public:
	#pragma option push -w-inl
	/* TGraphicControl.Destroy */ inline __fastcall virtual ~TGauge(void) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Gauges */
using namespace Gauges;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// Gauges
