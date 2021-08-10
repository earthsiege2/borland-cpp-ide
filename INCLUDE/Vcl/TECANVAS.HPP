// Borland C++ Builder
// Copyright (c) 1995, 1999 by Borland International
// All rights reserved

// (DO NOT EDIT: machine generated header) 'TeCanvas.pas' rev: 5.00

#ifndef TeCanvasHPP
#define TeCanvasHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <SysUtils.hpp>	// Pascal unit
#include <Graphics.hpp>	// Pascal unit
#include <Controls.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Tecanvas
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TChartPen;
class PASCALIMPLEMENTATION TChartPen : public Graphics::TPen 
{
	typedef Graphics::TPen inherited;
	
private:
	bool FSmallDots;
	bool FVisible;
	void __fastcall SetVisible(bool Value);
	void __fastcall SetSmallDots(bool Value);
	
public:
	__fastcall TChartPen(Classes::TNotifyEvent OnChangeEvent);
	virtual void __fastcall Assign(Classes::TPersistent* Source);
	
__published:
	__property bool SmallDots = {read=FSmallDots, write=SetSmallDots, default=0};
	__property bool Visible = {read=FVisible, write=SetVisible, default=1};
public:
	#pragma option push -w-inl
	/* TPen.Destroy */ inline __fastcall virtual ~TChartPen(void) { }
	#pragma option pop
	
};


class DELPHICLASS TChartHiddenPen;
class PASCALIMPLEMENTATION TChartHiddenPen : public TChartPen 
{
	typedef TChartPen inherited;
	
public:
	__fastcall TChartHiddenPen(Classes::TNotifyEvent OnChangeEvent);
	
__published:
	__property Visible ;
public:
	#pragma option push -w-inl
	/* TPen.Destroy */ inline __fastcall virtual ~TChartHiddenPen(void) { }
	#pragma option pop
	
};


class DELPHICLASS TDottedGrayPen;
class PASCALIMPLEMENTATION TDottedGrayPen : public TChartPen 
{
	typedef TChartPen inherited;
	
public:
	__fastcall TDottedGrayPen(Classes::TNotifyEvent OnChangeEvent);
	
__published:
	__property Color ;
	__property Style ;
public:
	#pragma option push -w-inl
	/* TPen.Destroy */ inline __fastcall virtual ~TDottedGrayPen(void) { }
	#pragma option pop
	
};


class DELPHICLASS TDarkGrayPen;
class PASCALIMPLEMENTATION TDarkGrayPen : public TChartPen 
{
	typedef TChartPen inherited;
	
public:
	__fastcall TDarkGrayPen(Classes::TNotifyEvent OnChangeEvent);
	
__published:
	__property Color ;
public:
	#pragma option push -w-inl
	/* TPen.Destroy */ inline __fastcall virtual ~TDarkGrayPen(void) { }
	#pragma option pop
	
};


class DELPHICLASS TChartArrowPen;
class PASCALIMPLEMENTATION TChartArrowPen : public TChartPen 
{
	typedef TChartPen inherited;
	
public:
	__fastcall TChartArrowPen(Classes::TNotifyEvent OnChangeEvent);
	
__published:
	__property Color ;
public:
	#pragma option push -w-inl
	/* TPen.Destroy */ inline __fastcall virtual ~TChartArrowPen(void) { }
	#pragma option pop
	
};


class DELPHICLASS TChartAxisPen;
class PASCALIMPLEMENTATION TChartAxisPen : public TChartPen 
{
	typedef TChartPen inherited;
	
public:
	__fastcall TChartAxisPen(Classes::TNotifyEvent OnChangeEvent);
	
__published:
	__property Width ;
public:
	#pragma option push -w-inl
	/* TPen.Destroy */ inline __fastcall virtual ~TChartAxisPen(void) { }
	#pragma option pop
	
};


typedef void __fastcall (__closure *TTeeView3DScrolled)(bool IsHoriz);

typedef void __fastcall (__closure *TTeeView3DChangedZoom)(int NewZoom);

class DELPHICLASS TView3DOptions;
class PASCALIMPLEMENTATION TView3DOptions : public Classes::TPersistent 
{
	typedef Classes::TPersistent inherited;
	
private:
	int FElevation;
	int FHorizOffset;
	bool FOrthogonal;
	int FPerspective;
	int FRotation;
	int FTilt;
	int FVertOffset;
	int FZoom;
	bool FZoomText;
	TTeeView3DScrolled FOnScrolled;
	TTeeView3DChangedZoom FOnChangedZoom;
	Controls::TWinControl* FParent;
	void __fastcall SetElevation(int Value);
	void __fastcall SetPerspective(int Value);
	void __fastcall SetRotation(int Value);
	void __fastcall SetTilt(int Value);
	void __fastcall SetHorizOffset(int Value);
	void __fastcall SetVertOffset(int Value);
	void __fastcall SetOrthogonal(bool Value);
	void __fastcall SetZoom(int Value);
	void __fastcall SetZoomText(bool Value);
	void __fastcall SetBooleanProperty(bool &Variable, bool Value);
	void __fastcall SetIntegerProperty(int &Variable, int Value);
	
public:
	__fastcall TView3DOptions(Controls::TWinControl* AParent);
	void __fastcall Repaint(void);
	virtual void __fastcall Assign(Classes::TPersistent* Source);
	__property Controls::TWinControl* Parent = {read=FParent, write=FParent};
	__property TTeeView3DChangedZoom OnChangedZoom = {read=FOnChangedZoom, write=FOnChangedZoom};
	__property TTeeView3DScrolled OnScrolled = {read=FOnScrolled, write=FOnScrolled};
	
__published:
	__property int Elevation = {read=FElevation, write=SetElevation, default=345};
	__property int HorizOffset = {read=FHorizOffset, write=SetHorizOffset, default=0};
	__property bool Orthogonal = {read=FOrthogonal, write=SetOrthogonal, default=1};
	__property int Perspective = {read=FPerspective, write=SetPerspective, default=15};
	__property int Rotation = {read=FRotation, write=SetRotation, default=345};
	__property int Tilt = {read=FTilt, write=SetTilt, default=0};
	__property int VertOffset = {read=FVertOffset, write=SetVertOffset, default=0};
	__property int Zoom = {read=FZoom, write=SetZoom, default=100};
	__property bool ZoomText = {read=FZoomText, write=SetZoomText, default=1};
public:
	#pragma option push -w-inl
	/* TPersistent.Destroy */ inline __fastcall virtual ~TView3DOptions(void) { }
	#pragma option pop
	
};


#pragma option push -b-
enum TCanvasBackMode { cbmNone, cbmTransparent, cbmOpaque };
#pragma option pop

typedef int TCanvasTextAlign;

#pragma option push -b-
enum TGradientDirection { gdTopBottom, gdBottomTop, gdLeftRight, gdRightLeft, gdFromCenter, gdFromTopLeft, 
	gdFromBottomLeft };
#pragma option pop

class DELPHICLASS TTeeCanvas;
class PASCALIMPLEMENTATION TTeeCanvas : public System::TObject 
{
	typedef System::TObject inherited;
	
private:
	Graphics::TCanvas* FCanvas;
	Graphics::TFont* FFont;
	Graphics::TPen* FPen;
	Graphics::TBrush* FBrush;
	bool FMetafiling;
	
protected:
	void __fastcall SetCanvas(Graphics::TCanvas* ACanvas);
	virtual Graphics::TColor __fastcall GetBackColor(void) = 0 ;
	virtual TCanvasBackMode __fastcall GetBackMode(void) = 0 ;
	virtual HDC __fastcall GetHandle(void) = 0 ;
	virtual bool __fastcall GetMonochrome(void) = 0 ;
	virtual int __fastcall GetTextAlign(void) = 0 ;
	virtual bool __fastcall GetUseBuffer(void) = 0 ;
	virtual void __fastcall SetBackColor(Graphics::TColor Color) = 0 ;
	virtual void __fastcall SetBackMode(TCanvasBackMode Mode) = 0 ;
	virtual void __fastcall SetMonochrome(bool Value) = 0 ;
	virtual void __fastcall SetPixel(int X, int Y, Graphics::TColor Value) = 0 ;
	virtual void __fastcall SetTextAlign(int Align) = 0 ;
	virtual void __fastcall SetUseBuffer(bool Value) = 0 ;
	
public:
	void __fastcall AssignVisiblePen(TChartPen* APen);
	void __fastcall ResetState(void);
	virtual void __fastcall Arc(int X1, int Y1, int X2, int Y2, int X3, int Y3, int X4, int Y4) = 0 ;
	virtual void __fastcall Draw(int X, int Y, Graphics::TGraphic* Graphic) = 0 ;
	virtual void __fastcall Ellipse(int X1, int Y1, int X2, int Y2) = 0 ;
	virtual void __fastcall FillRect(const Windows::TRect &Rect) = 0 ;
	virtual void __fastcall Frame3D(const Windows::TRect &Rect, Graphics::TColor TopColor, Graphics::TColor 
		BottomColor, int Width) = 0 ;
	virtual void __fastcall LineTo(int X, int Y) = 0 ;
	virtual void __fastcall MoveTo(int X, int Y) = 0 ;
	virtual void __fastcall Pie(int X1, int Y1, int X2, int Y2, int X3, int Y3, int X4, int Y4) = 0 ;
	virtual void __fastcall Rectangle(int X0, int Y0, int X1, int Y1) = 0 ;
	virtual void __fastcall RoundRect(int X1, int Y1, int X2, int Y2, int X3, int Y3) = 0 ;
	virtual void __fastcall StretchDraw(const Windows::TRect &Rect, Graphics::TGraphic* Graphic) = 0 ;
	virtual void __fastcall TextOut(int X, int Y, const AnsiString Text) = 0 ;
	virtual int __fastcall TextWidth(const AnsiString St);
	virtual int __fastcall TextHeight(const AnsiString St);
	int __fastcall FontHeight(void);
	virtual void __fastcall ClipRectangle(const Windows::TRect &Rect) = 0 ;
	virtual void __fastcall DoHorizLine(int X0, int X1, int Y) = 0 ;
	virtual void __fastcall DoRectangle(const Windows::TRect &Rect) = 0 ;
	virtual void __fastcall DoVertLine(int X, int Y0, int Y1) = 0 ;
	virtual void __fastcall EraseBackground(const Windows::TRect &Rect) = 0 ;
	virtual void __fastcall GradientFill(const Windows::TRect &Rect, Graphics::TColor StartColor, Graphics::TColor 
		EndColor, TGradientDirection Direction) = 0 ;
	virtual void __fastcall Invalidate(void) = 0 ;
	virtual void __fastcall Line(int X0, int Y0, int X1, int Y1) = 0 ;
	virtual void __fastcall Polygon(const Windows::TPoint * Points, const int Points_Size) = 0 ;
	virtual void __fastcall RotateLabel(int x, int y, const AnsiString St, int RotDegree) = 0 ;
	virtual void __fastcall UnClipRectangle(void) = 0 ;
	__property Graphics::TColor BackColor = {read=GetBackColor, write=SetBackColor, nodefault};
	__property TCanvasBackMode BackMode = {read=GetBackMode, write=SetBackMode, nodefault};
	__property Graphics::TBrush* Brush = {read=FBrush};
	__property Graphics::TFont* Font = {read=FFont};
	__property HDC Handle = {read=GetHandle, nodefault};
	__property bool Metafiling = {read=FMetafiling, write=FMetafiling, nodefault};
	__property bool Monochrome = {read=GetMonochrome, write=SetMonochrome, nodefault};
	__property Graphics::TPen* Pen = {read=FPen};
	__property Graphics::TColor Pixels[int X][int Y] = {write=SetPixel};
	__property Graphics::TCanvas* ReferenceCanvas = {read=FCanvas, write=SetCanvas};
	__property int TextAlign = {read=GetTextAlign, write=SetTextAlign, nodefault};
	__property bool UseBuffer = {read=GetUseBuffer, write=SetUseBuffer, nodefault};
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall TTeeCanvas(void) : System::TObject() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TTeeCanvas(void) { }
	#pragma option pop
	
};


#pragma pack(push, 1)
struct TPoint3D
{
	int x;
	int y;
	int z;
} ;
#pragma pack(pop)

typedef Windows::TPoint TFourPoints[4];

typedef TPoint3D TTrianglePoints3D[3];

typedef Graphics::TColor TTriangleColors3D[3];

typedef bool __fastcall (__closure *TTeeCanvasCalcPoints)(int x, int z, TPoint3D &P0, TPoint3D &P1, 
	Graphics::TColor &Color0, Graphics::TColor &Color1);

#pragma option push -b-
enum TTeeCanvasSurfaceStyle { tcsSolid, tcsWire, tcsDot };
#pragma option pop

class DELPHICLASS TCanvas3D;
class PASCALIMPLEMENTATION TCanvas3D : public TTeeCanvas 
{
	typedef TTeeCanvas inherited;
	
private:
	TView3DOptions* F3DOptions;
	bool FIsOrthogonal;
	
protected:
	virtual void __fastcall SetPixel3D(int X, int Y, int Z, Graphics::TColor Value) = 0 ;
	virtual bool __fastcall GetSupportsFullRotation(void) = 0 ;
	virtual bool __fastcall GetSupports3DText(void) = 0 ;
	
public:
	virtual void __fastcall Calculate2DPosition(int &x, int &y, int z) = 0 ;
	virtual Windows::TPoint __fastcall Calculate3DPosition(int x, int y, int z) = 0 ;
	virtual Windows::TRect __fastcall InitWindow(Graphics::TCanvas* DestCanvas, TView3DOptions* A3DOptions
		, Graphics::TColor ABackColor, bool Is3D, const Windows::TRect &UserRect) = 0 ;
	virtual void __fastcall Assign(TCanvas3D* Source);
	virtual void __fastcall Projection(int MaxDepth, const Windows::TRect &Bounds, const Windows::TRect 
		&Rect) = 0 ;
	virtual void __fastcall ShowImage(Graphics::TCanvas* DestCanvas, Graphics::TCanvas* DefaultCanvas, 
		const Windows::TRect &UserRect) = 0 ;
	virtual bool __fastcall ReDrawBitmap(void) = 0 ;
	virtual void __fastcall Arrow(bool Filled, const Windows::TPoint &FromPoint, const Windows::TPoint 
		&ToPoint, int ArrowWidth, int ArrowHeight, int Z) = 0 ;
	virtual void __fastcall ClipCube(const Windows::TRect &Rect, int MinZ, int MaxZ) = 0 ;
	virtual void __fastcall Cone(bool Vertical, int Left, int Top, int Right, int Bottom, int Z0, int Z1
		, int ConePercent) = 0 ;
	virtual void __fastcall Cube(int Left, int Right, int Top, int Bottom, int Z0, int Z1, bool DarkSides
		) = 0 ;
	virtual void __fastcall Cylinder(bool Vertical, int Left, int Top, int Right, int Bottom, int Z0, int 
		Z1, bool Dark3D) = 0 ;
	virtual void __fastcall HorizLine3D(int Left, int Right, int Y, int Z) = 0 ;
	virtual void __fastcall VertLine3D(int X, int Top, int Bottom, int Z) = 0 ;
	virtual void __fastcall ZLine3D(int X, int Y, int Z0, int Z1) = 0 ;
	virtual void __fastcall EllipseWithZ(int X1, int Y1, int X2, int Y2, int Z) = 0 ;
	virtual void __fastcall FrontPlaneBegin(void) = 0 ;
	virtual void __fastcall FrontPlaneEnd(void) = 0 ;
	virtual void __fastcall LineWithZ(int X0, int Y0, int X1, int Y1, int Z) = 0 ;
	virtual void __fastcall MoveTo3D(int X, int Y, int Z) = 0 ;
	virtual void __fastcall LineTo3D(int X, int Y, int Z) = 0 ;
	virtual void __fastcall Pie3D(int XCenter, int YCenter, int XRadius, int YRadius, int Z0, int Z1, const 
		double StartAngle, const double EndAngle, bool DarkSides, bool DrawSides) = 0 ;
	virtual void __fastcall Plane3D(const Windows::TPoint &A, const Windows::TPoint &B, int Z0, int Z1)
		 = 0 ;
	virtual void __fastcall PlaneWithZ(const Windows::TPoint &P1, const Windows::TPoint &P2, const Windows::TPoint 
		&P3, const Windows::TPoint &P4, int Z) = 0 ;
	virtual void __fastcall PlaneFour3D(Windows::TPoint * Points, int Z0, int Z1) = 0 ;
	virtual void __fastcall PolygonWithZ(const Windows::TPoint * Points, const int Points_Size, int Z) = 0 
		;
	virtual void __fastcall Pyramid(bool Vertical, int Left, int Top, int Right, int Bottom, int z0, int 
		z1, bool DarkSides) = 0 ;
	virtual void __fastcall RectangleWithZ(const Windows::TRect &Rect, int Z) = 0 ;
	virtual void __fastcall RectangleY(int Left, int Top, int Right, int Z0, int Z1) = 0 ;
	virtual void __fastcall RectangleZ(int Left, int Top, int Bottom, int Z0, int Z1) = 0 ;
	virtual void __fastcall RotateLabel3D(int x, int y, int z, const AnsiString St, int RotDegree) = 0 
		;
	virtual void __fastcall Sphere(int x, int y, int z, const double Radius) = 0 ;
	virtual void __fastcall Surface3D(TTeeCanvasSurfaceStyle Style, bool SameBrush, int NumXValues, int 
		NumZValues, TTeeCanvasCalcPoints CalcPoints) = 0 ;
	virtual void __fastcall TextOut3D(int x, int y, int z, const AnsiString Text) = 0 ;
	virtual void __fastcall Triangle3D(const TPoint3D * Points, const Graphics::TColor * Colors) = 0 ;
	virtual void __fastcall TriangleWithZ(const Windows::TPoint &P1, const Windows::TPoint &P2, const Windows::TPoint 
		&P3, int Z) = 0 ;
	__property Graphics::TColor Pixels3D[int X][int Y][int Z] = {write=SetPixel3D};
	__property bool Supports3DText = {read=GetSupports3DText, nodefault};
	__property bool SupportsFullRotation = {read=GetSupportsFullRotation, nodefault};
	__property TView3DOptions* View3DOptions = {read=F3DOptions, write=F3DOptions};
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall TCanvas3D(void) : TTeeCanvas() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TCanvas3D(void) { }
	#pragma option pop
	
};


class DELPHICLASS TTeeCanvas3D;
class PASCALIMPLEMENTATION TTeeCanvas3D : public TCanvas3D 
{
	typedef TCanvas3D inherited;
	
private:
	int FXCenter;
	int FYCenter;
	int FZCenter;
	int FXCenterOffset;
	int FYCenterOffset;
	Extended s2;
	Extended c2s1;
	double c2s3;
	double c2c3;
	double c2c1;
	double tempXX;
	double tempYX;
	double tempXZ;
	double tempYZ;
	bool FWas3D;
	bool FIs3D;
	Graphics::TBitmap* FBitmap;
	bool FBufferedDisplay;
	bool FMonochrome;
	bool FDirty;
	Windows::TRect FBounds;
	bool IZoomText;
	double IZoomFactor;
	double IPerspec;
	void __fastcall TransferBitmap(int ALeft, int ATop, Graphics::TCanvas* ACanvas);
	void __fastcall DeleteBitmap(void);
	
protected:
	virtual Graphics::TColor __fastcall GetBackColor(void);
	virtual TCanvasBackMode __fastcall GetBackMode(void);
	virtual HDC __fastcall GetHandle(void);
	virtual bool __fastcall GetMonochrome(void);
	virtual bool __fastcall GetSupports3DText(void);
	virtual bool __fastcall GetSupportsFullRotation(void);
	virtual int __fastcall GetTextAlign(void);
	virtual bool __fastcall GetUseBuffer(void);
	virtual void __fastcall SetBackColor(Graphics::TColor Color);
	virtual void __fastcall SetBackMode(TCanvasBackMode Mode);
	virtual void __fastcall SetMonochrome(bool Value);
	virtual void __fastcall SetPixel(int X, int Y, Graphics::TColor Value);
	virtual void __fastcall SetTextAlign(int Align);
	virtual void __fastcall SetUseBuffer(bool Value);
	void __fastcall Calc3DTPoint(Windows::TPoint &P, int z);
	Windows::TPoint __fastcall Calc3DTPoint3D(const TPoint3D &P);
	void __fastcall Calc3DPoint(Windows::TPoint &P, int x, int y, int z);
	virtual void __fastcall SetPixel3D(int X, int Y, int Z, Graphics::TColor Value);
	void __fastcall Calc3DPos(int &x, int &y, int z);
	__property Graphics::TBitmap* Bitmap = {read=FBitmap};
	
public:
	virtual void __fastcall Calculate2DPosition(int &x, int &y, int z);
	virtual Windows::TPoint __fastcall Calculate3DPosition(int x, int y, int z);
	__fastcall TTeeCanvas3D(void);
	__fastcall virtual ~TTeeCanvas3D(void);
	virtual Windows::TRect __fastcall InitWindow(Graphics::TCanvas* DestCanvas, TView3DOptions* A3DOptions
		, Graphics::TColor ABackColor, bool Is3D, const Windows::TRect &UserRect);
	virtual bool __fastcall ReDrawBitmap(void);
	virtual void __fastcall ShowImage(Graphics::TCanvas* DestCanvas, Graphics::TCanvas* DefaultCanvas, 
		const Windows::TRect &UserRect);
	virtual void __fastcall Arc(int X1, int Y1, int X2, int Y2, int X3, int Y3, int X4, int Y4);
	virtual void __fastcall Draw(int X, int Y, Graphics::TGraphic* Graphic);
	virtual void __fastcall Ellipse(int X1, int Y1, int X2, int Y2);
	virtual void __fastcall EraseBackground(const Windows::TRect &Rect);
	virtual void __fastcall FillRect(const Windows::TRect &Rect);
	virtual void __fastcall Frame3D(const Windows::TRect &Rect, Graphics::TColor TopColor, Graphics::TColor 
		BottomColor, int Width);
	virtual void __fastcall LineTo(int X, int Y);
	virtual void __fastcall MoveTo(int X, int Y);
	virtual void __fastcall Pie(int X1, int Y1, int X2, int Y2, int X3, int Y3, int X4, int Y4);
	virtual void __fastcall Rectangle(int X0, int Y0, int X1, int Y1);
	virtual void __fastcall RoundRect(int X1, int Y1, int X2, int Y2, int X3, int Y3);
	virtual void __fastcall StretchDraw(const Windows::TRect &Rect, Graphics::TGraphic* Graphic);
	virtual void __fastcall TextOut(int X, int Y, const AnsiString Text);
	virtual void __fastcall ClipRectangle(const Windows::TRect &Rect);
	virtual void __fastcall ClipCube(const Windows::TRect &Rect, int MinZ, int MaxZ);
	virtual void __fastcall DoRectangle(const Windows::TRect &Rect);
	virtual void __fastcall DoHorizLine(int X0, int X1, int Y);
	virtual void __fastcall DoVertLine(int X, int Y0, int Y1);
	virtual void __fastcall GradientFill(const Windows::TRect &Rect, Graphics::TColor StartColor, Graphics::TColor 
		EndColor, TGradientDirection Direction);
	virtual void __fastcall Invalidate(void);
	virtual void __fastcall Line(int X0, int Y0, int X1, int Y1);
	virtual void __fastcall Polygon(const Windows::TPoint * Points, const int Points_Size);
	virtual void __fastcall RotateLabel(int x, int y, const AnsiString St, int RotDegree);
	virtual void __fastcall RotateLabel3D(int x, int y, int z, const AnsiString St, int RotDegree);
	virtual void __fastcall UnClipRectangle(void);
	__property int XCenter = {read=FXCenter, write=FXCenter, nodefault};
	__property int YCenter = {read=FYCenter, write=FYCenter, nodefault};
	virtual void __fastcall Projection(int MaxDepth, const Windows::TRect &Bounds, const Windows::TRect 
		&Rect);
	virtual void __fastcall Arrow(bool Filled, const Windows::TPoint &FromPoint, const Windows::TPoint 
		&ToPoint, int ArrowWidth, int ArrowHeight, int Z);
	virtual void __fastcall Cone(bool Vertical, int Left, int Top, int Right, int Bottom, int Z0, int Z1
		, int ConePercent);
	virtual void __fastcall Cube(int Left, int Right, int Top, int Bottom, int Z0, int Z1, bool DarkSides
		);
	virtual void __fastcall Cylinder(bool Vertical, int Left, int Top, int Right, int Bottom, int Z0, int 
		Z1, bool Dark3D);
	virtual void __fastcall EllipseWithZ(int X1, int Y1, int X2, int Y2, int Z);
	virtual void __fastcall RectangleZ(int Left, int Top, int Bottom, int Z0, int Z1);
	virtual void __fastcall RectangleY(int Left, int Top, int Right, int Z0, int Z1);
	virtual void __fastcall FrontPlaneBegin(void);
	virtual void __fastcall FrontPlaneEnd(void);
	virtual void __fastcall HorizLine3D(int Left, int Right, int Y, int Z);
	virtual void __fastcall LineTo3D(int X, int Y, int Z);
	virtual void __fastcall LineWithZ(int X0, int Y0, int X1, int Y1, int Z);
	virtual void __fastcall MoveTo3D(int X, int Y, int Z);
	virtual void __fastcall Pie3D(int XCenter, int YCenter, int XRadius, int YRadius, int Z0, int Z1, const 
		double StartAngle, const double EndAngle, bool DarkSides, bool DrawSides);
	virtual void __fastcall Plane3D(const Windows::TPoint &A, const Windows::TPoint &B, int Z0, int Z1)
		;
	virtual void __fastcall PlaneWithZ(const Windows::TPoint &P1, const Windows::TPoint &P2, const Windows::TPoint 
		&P3, const Windows::TPoint &P4, int Z);
	virtual void __fastcall PlaneFour3D(Windows::TPoint * Points, int Z0, int Z1);
	virtual void __fastcall PolygonWithZ(const Windows::TPoint * Points, const int Points_Size, int Z);
		
	virtual void __fastcall Pyramid(bool Vertical, int Left, int Top, int Right, int Bottom, int z0, int 
		z1, bool DarkSides);
	virtual void __fastcall RectangleWithZ(const Windows::TRect &Rect, int Z);
	virtual void __fastcall Sphere(int x, int y, int z, const double Radius);
	virtual void __fastcall Surface3D(TTeeCanvasSurfaceStyle Style, bool SameBrush, int NumXValues, int 
		NumZValues, TTeeCanvasCalcPoints CalcPoints);
	virtual void __fastcall TextOut3D(int X, int Y, int Z, const AnsiString Text);
	virtual void __fastcall Triangle3D(const TPoint3D * Points, const Graphics::TColor * Colors);
	virtual void __fastcall TriangleWithZ(const Windows::TPoint &P1, const Windows::TPoint &P2, const Windows::TPoint 
		&P3, int Z);
	virtual void __fastcall VertLine3D(int X, int Top, int Bottom, int Z);
	virtual void __fastcall ZLine3D(int X, int Y, int Z0, int Z1);
	__property Windows::TRect Bounds = {read=FBounds};
};


//-- var, const, procedure ---------------------------------------------------
static const char TeeCharForHeight = '\x57';
extern PACKAGE Byte DarkerColorQuantity;
extern PACKAGE Byte DarkColorQuantity;
extern PACKAGE int TeeGradientPrecision;
extern PACKAGE void __fastcall SinCos(const Extended Angle, Extended &ResultSin, Extended &ResultCos
	);
extern PACKAGE Extended __fastcall ArcTan2(Extended Y, Extended X);
extern PACKAGE TPoint3D __fastcall Point3D(int x, int y, int z);
extern PACKAGE void __fastcall RectSize(const Windows::TRect &R, int &RectWidth, int &RectHeight);
extern PACKAGE void __fastcall RectCenter(const Windows::TRect &R, int &XCenter, int &YCenter);
extern PACKAGE void __fastcall ClipCanvas(Graphics::TCanvas* ACanvas, const Windows::TRect &Rect);
extern PACKAGE void __fastcall UnClipCanvas(Graphics::TCanvas* ACanvas);
extern PACKAGE Graphics::TColor __fastcall ApplyDark(Graphics::TColor Color, Byte HowMuch);
extern PACKAGE Graphics::TColor __fastcall ApplyBright(Graphics::TColor Color, Byte HowMuch);
extern PACKAGE double __fastcall MaxDouble(const double a, const double b);
extern PACKAGE double __fastcall MinDouble(const double a, const double b);
extern PACKAGE int __fastcall MaxLong(int a, int b);
extern PACKAGE int __fastcall MinLong(int a, int b);
extern PACKAGE void __fastcall SwapLongint(int &a, int &b);
extern PACKAGE void __fastcall SwapDouble(double &a, double &b);
extern PACKAGE void __fastcall SwapInteger(int &a, int &b);

}	/* namespace Tecanvas */
#if !defined(NO_IMPLICIT_NAMESPACE_USE)
using namespace Tecanvas;
#endif
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// TeCanvas
