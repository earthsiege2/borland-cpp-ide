// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'TeeShape.pas' rev: 6.00

#ifndef TeeShapeHPP
#define TeeShapeHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <TeCanvas.hpp>	// Pascal unit
#include <TeEngine.hpp>	// Pascal unit
#include <Series.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <Graphics.hpp>	// Pascal unit
#include <Chart.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Teeshape
{
//-- type declarations -------------------------------------------------------
#pragma option push -b-
enum TChartShapeXYStyle { xysPixels, xysAxis, xysAxisOrigin };
#pragma option pop

#pragma option push -b-
enum TChartShapeStyle { chasRectangle, chasCircle, chasVertLine, chasHorizLine, chasTriangle, chasInvertTriangle, chasLine, chasDiamond, chasCube, chasCross, chasDiagCross, chasStar, chasPyramid, chasInvertPyramid };
#pragma option pop

class DELPHICLASS TChartShape;
class PASCALIMPLEMENTATION TChartShape : public Teengine::TChartSeries 
{
	typedef Teengine::TChartSeries inherited;
	
private:
	Classes::TAlignment FAlignment;
	Chart::TChartBrush* FBrush;
	Graphics::TFont* FFont;
	Tecanvas::TChartPen* FPen;
	bool FRoundRectangle;
	TChartShapeStyle FStyle;
	Classes::TStrings* FText;
	bool FTransparent;
	TChartShapeXYStyle FXYStyle;
	void __fastcall AddDefaultPoints(void);
	void __fastcall SetAlignment(Classes::TAlignment Value);
	void __fastcall SetBrush(Chart::TChartBrush* Value);
	void __fastcall SetFont(Graphics::TFont* Value);
	void __fastcall SetPen(Tecanvas::TChartPen* Value);
	void __fastcall SetRoundRectangle(bool Value);
	void __fastcall SetStyle(TChartShapeStyle Value);
	void __fastcall SetTransparent(bool Value);
	void __fastcall SetX0(const double Value);
	void __fastcall SetX1(const double Value);
	void __fastcall SetY0(const double Value);
	void __fastcall SetY1(const double Value);
	double __fastcall GetX0(void);
	double __fastcall GetX1(void);
	double __fastcall GetY0(void);
	double __fastcall GetY1(void);
	void __fastcall SetXYStyle(TChartShapeXYStyle Value);
	
protected:
	void __fastcall DrawShape(bool Is3D, const Types::TRect &R);
	void __fastcall DrawText(const Types::TRect &R);
	virtual void __fastcall SetSeriesColor(Graphics::TColor AColor);
	Types::TRect __fastcall GetAdjustedRectangle();
	virtual Types::TRect __fastcall GetShapeRectangle();
	void __fastcall SetShapeRectangle(const Types::TRect &ARect);
	virtual void __fastcall SetText(Classes::TStrings* Value);
	virtual bool __fastcall MoreSameZOrder(void);
	
public:
	__fastcall virtual TChartShape(Classes::TComponent* AOwner);
	__fastcall virtual ~TChartShape(void);
	virtual void __fastcall Assign(Classes::TPersistent* Source);
	virtual void __fastcall CalcZOrder(void);
	virtual int __fastcall Clicked(int x, int y);
	virtual void __fastcall DrawLegendShape(int ValueIndex, const Types::TRect &Rect);
	virtual void __fastcall DrawValue(int ValueIndex);
	virtual void __fastcall FillSampleValues(int NumValues);
	virtual void __fastcall PrepareForGallery(bool IsEnabled);
	virtual AnsiString __fastcall GetEditorClass();
	virtual bool __fastcall IsValidSourceOf(Teengine::TChartSeries* Value);
	virtual bool __fastcall UseAxis(void);
	__property Types::TRect Bounds = {read=GetShapeRectangle, write=SetShapeRectangle};
	
__published:
	__property Classes::TAlignment Alignment = {read=FAlignment, write=SetAlignment, default=2};
	__property Chart::TChartBrush* Brush = {read=FBrush, write=SetBrush};
	__property Graphics::TFont* Font = {read=FFont, write=SetFont};
	__property Classes::TStrings* Text = {read=FText, write=SetText};
	__property Tecanvas::TChartPen* Pen = {read=FPen, write=SetPen};
	__property bool RoundRectangle = {read=FRoundRectangle, write=SetRoundRectangle, default=0};
	__property TChartShapeStyle Style = {read=FStyle, write=SetStyle, default=1};
	__property bool Transparent = {read=FTransparent, write=SetTransparent, default=0};
	__property TChartShapeXYStyle XYStyle = {read=FXYStyle, write=SetXYStyle, default=1};
	__property double X0 = {read=GetX0, write=SetX0};
	__property double X1 = {read=GetX1, write=SetX1};
	__property double Y0 = {read=GetY0, write=SetY0};
	__property double Y1 = {read=GetY1, write=SetY1};
	__property XValues ;
	__property YValues ;
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Teeshape */
using namespace Teeshape;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// TeeShape
