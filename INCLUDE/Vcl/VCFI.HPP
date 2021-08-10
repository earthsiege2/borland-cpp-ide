// Borland C++ Builder
// Copyright (c) 1995, 1999 by Borland International
// All rights reserved

// (DO NOT EDIT: machine generated header) 'vcfi.pas' rev: 5.00

#ifndef vcfiHPP
#define vcfiHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <Menus.hpp>	// Pascal unit
#include <Controls.hpp>	// Pascal unit
#include <StdVCL.hpp>	// Pascal unit
#include <OleCtrls.hpp>	// Pascal unit
#include <OleServer.hpp>	// Pascal unit
#include <Graphics.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <ActiveX.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Vcfi
{
//-- type declarations -------------------------------------------------------
typedef Activex::TOleEnum FontStyleConstants;

typedef Activex::TOleEnum FontEffectsConstants;

typedef Activex::TOleEnum FrameStyleConstants;

typedef Activex::TOleEnum BrushStyleConstants;

typedef Activex::TOleEnum LabelComponentConstants;

typedef Activex::TOleEnum BrushPatternConstants;

typedef Activex::TOleEnum BrushHatchConstants;

typedef Activex::TOleEnum ShadowStyleConstants;

typedef Activex::TOleEnum MouseFlagConstants;

typedef Activex::TOleEnum PenStyleConstants;

typedef Activex::TOleEnum PenJoinConstants;

typedef Activex::TOleEnum PenCapConstants;

typedef Activex::TOleEnum GradientStyleConstants;

typedef Activex::TOleEnum PictureTypeConstants;

typedef Activex::TOleEnum PictureOptionConstants;

typedef Activex::TOleEnum PictureMapTypeConstants;

typedef Activex::TOleEnum FillStyleConstants;

typedef Activex::TOleEnum LocationTypeConstants;

typedef Activex::TOleEnum AxisIdConstants;

typedef Activex::TOleEnum AxisTickStyleConstants;

typedef Activex::TOleEnum DateIntervalTypeConstants;

typedef Activex::TOleEnum ScaleTypeConstants;

typedef Activex::TOleEnum PercentAxisBasisConstants;

typedef Activex::TOleEnum PieWeightBasisConstants;

typedef Activex::TOleEnum PieWeightStyleConstants;

typedef Activex::TOleEnum SortTypeConstants;

typedef Activex::TOleEnum AngleUnitsConstants;

typedef Activex::TOleEnum SubPlotLabelLocationTypeConstants;

typedef Activex::TOleEnum LabelLineStyleConstants;

typedef Activex::TOleEnum LabelLocationTypeConstants;

typedef Activex::TOleEnum ContourColorTypeConstants;

typedef Activex::TOleEnum ContourDisplayTypeConstants;

typedef Activex::TOleEnum SurfaceBaseTypeConstants;

typedef Activex::TOleEnum SurfaceDisplayTypeConstants;

typedef Activex::TOleEnum SurfaceProjectionTypeConstants;

typedef Activex::TOleEnum SurfaceWireframeTypeConstants;

typedef Activex::TOleEnum MarkerStyleConstants;

typedef Activex::TOleEnum ProjectionTypeConstants;

typedef Activex::TOleEnum SmoothingTypeConstants;

typedef Activex::TOleEnum HorizontalAlignmentConstants;

typedef Activex::TOleEnum VerticalAlignmentConstants;

typedef Activex::TOleEnum OrientationConstants;

typedef Activex::TOleEnum DcTypeConstants;

typedef Activex::TOleEnum PrintScaleTypeConstants;

typedef Activex::TOleEnum StatTypeConstants;

typedef Activex::TOleEnum PrintOrientationTypeConstants;

typedef Activex::TOleEnum TextOutputTypeConstants;

typedef Activex::TOleEnum TextLengthTypeConstants;

typedef Activex::TOleEnum PartTypeConstants;

typedef Activex::TOleEnum DrawModeConstants;

typedef Activex::TOleEnum SsLinkModeConstants;

typedef Activex::TOleEnum SeriesTypeConstants;

typedef Activex::TOleEnum ChartTypeConstants;

__dispinterface _DVtChart;
typedef System::DelphiInterface<_DVtChart> _di__DVtChart;
__dispinterface INTERFACE_UUID("{5A721581-5AF0-11CE-8384-0020AF2337F2}") _DVtChart  : public IDispatch 
	
{
	
};
typedef _DVtChart VtChart;

__dispinterface ICoor;
typedef System::DelphiInterface<ICoor> _di_ICoor;
__dispinterface INTERFACE_UUID("{EBF97E20-731F-11CE-840F-00AA0042CB33}") ICoor  : public IDispatch 
{
	
};
typedef ICoor Coor;

__dispinterface ILCoor;
typedef System::DelphiInterface<ILCoor> _di_ILCoor;
__dispinterface INTERFACE_UUID("{EBF97E22-731F-11CE-840F-00AA0042CB33}") ILCoor  : public IDispatch 
	
{
	
};
typedef ILCoor LCoor;

__dispinterface ICoor3;
typedef System::DelphiInterface<ICoor3> _di_ICoor3;
__dispinterface INTERFACE_UUID("{177BF2A0-7350-11CE-840F-00AA0042CB33}") ICoor3  : public IDispatch 
	
{
	
};
typedef ICoor3 Coor3;

__dispinterface ILRect;
typedef System::DelphiInterface<ILRect> _di_ILRect;
__dispinterface INTERFACE_UUID("{177BF2A2-7350-11CE-840F-00AA0042CB33}") ILRect  : public IDispatch 
	
{
	
};
typedef ILRect LRect;

__dispinterface IRect;
typedef System::DelphiInterface<IRect> _di_IRect;
__dispinterface INTERFACE_UUID("{FE5517C0-73FE-11CE-840F-00AA0042CB33}") IRect  : public IDispatch 
{
	
};
typedef IRect Rect;

__dispinterface IColor;
typedef System::DelphiInterface<IColor> _di_IColor;
__dispinterface INTERFACE_UUID("{9BA79C60-7403-11CE-840F-00AA0042CB33}") IColor  : public IDispatch 
	
{
	
};
typedef IColor VtColor;

__dispinterface IBrush;
typedef System::DelphiInterface<IBrush> _di_IBrush;
__dispinterface INTERFACE_UUID("{AFE57020-7409-11CE-840F-00AA0042CB33}") IBrush  : public IDispatch 
	
{
	
};
typedef IBrush Brush;

__dispinterface IShadow;
typedef System::DelphiInterface<IShadow> _di_IShadow;
__dispinterface INTERFACE_UUID("{AFE57022-7409-11CE-840F-00AA0042CB33}") IShadow  : public IDispatch 
	
{
	
};
typedef IShadow Shadow;

__dispinterface ITextLayout;
typedef System::DelphiInterface<ITextLayout> _di_ITextLayout;
__dispinterface INTERFACE_UUID("{E26C7700-756C-11CE-840F-00AA0042CB33}") ITextLayout  : public IDispatch 
	
{
	
};
typedef ITextLayout TextLayout;

__dispinterface IVcTitle;
typedef System::DelphiInterface<IVcTitle> _di_IVcTitle;
__dispinterface INTERFACE_UUID("{C82141A0-7571-11CE-840F-00AA0042CB33}") IVcTitle  : public IDispatch 
	
{
	
};
typedef IVcTitle Title;

__dispinterface ILocation;
typedef System::DelphiInterface<ILocation> _di_ILocation;
__dispinterface INTERFACE_UUID("{EDDF9242-764B-11CE-840F-00AA0042CB33}") ILocation  : public IDispatch 
	
{
	
};
typedef ILocation Location;

__dispinterface IFont;
typedef System::DelphiInterface<IFont> _di_IFont;
__dispinterface INTERFACE_UUID("{2E6A37A0-77FC-11CE-840F-00AA0042CB33}") IFont  : public IDispatch 
{
	
};
typedef IFont VtFont;

__dispinterface IBackdrop;
typedef System::DelphiInterface<IBackdrop> _di_IBackdrop;
__dispinterface INTERFACE_UUID("{2E6A37A2-77FC-11CE-840F-00AA0042CB33}") IBackdrop  : public IDispatch 
	
{
	
};
typedef IBackdrop Backdrop;

__dispinterface IFrame;
typedef System::DelphiInterface<IFrame> _di_IFrame;
__dispinterface INTERFACE_UUID("{2E6A37A4-77FC-11CE-840F-00AA0042CB33}") IFrame  : public IDispatch 
	
{
	
};
typedef IFrame Frame;

__dispinterface IGradient;
typedef System::DelphiInterface<IGradient> _di_IGradient;
__dispinterface INTERFACE_UUID("{2E6A37A6-77FC-11CE-840F-00AA0042CB33}") IGradient  : public IDispatch 
	
{
	
};
typedef IGradient Gradient;

__dispinterface IPicture;
typedef System::DelphiInterface<IPicture> _di_IPicture;
__dispinterface INTERFACE_UUID("{FD30FB00-789C-11CE-840F-00AA0042CB33}") IPicture  : public IDispatch 
	
{
	
};
typedef IPicture VtPicture;

__dispinterface IFill;
typedef System::DelphiInterface<IFill> _di_IFill;
__dispinterface INTERFACE_UUID("{FD30FB02-789C-11CE-840F-00AA0042CB33}") IFill  : public IDispatch 
{
	
};
typedef IFill Fill;

__dispinterface IVcPen;
typedef System::DelphiInterface<IVcPen> _di_IVcPen;
__dispinterface INTERFACE_UUID("{279B5A40-8098-11CE-BECC-00AA0042CB33}") IVcPen  : public IDispatch 
	
{
	
};
typedef IVcPen Pen;

__dispinterface IVcMarker;
typedef System::DelphiInterface<IVcMarker> _di_IVcMarker;
__dispinterface INTERFACE_UUID("{3080E742-813F-11CE-BECC-00AA0042CB33}") IVcMarker  : public IDispatch 
	
{
	
};
typedef IVcMarker Marker;

__dispinterface IVcFootnote;
typedef System::DelphiInterface<IVcFootnote> _di_IVcFootnote;
__dispinterface INTERFACE_UUID("{4F053F00-8396-11CE-BECC-00AA0042CB33}") IVcFootnote  : public IDispatch 
	
{
	
};
typedef IVcFootnote Footnote;

__dispinterface IVcLegend;
typedef System::DelphiInterface<IVcLegend> _di_IVcLegend;
__dispinterface INTERFACE_UUID("{95C52B60-83B1-11CE-BECC-00AA0042CB33}") IVcLegend  : public IDispatch 
	
{
	
};
typedef IVcLegend Legend;

__dispinterface IVcPrintInformation;
typedef System::DelphiInterface<IVcPrintInformation> _di_IVcPrintInformation;
__dispinterface INTERFACE_UUID("{CFA0AC00-8B6E-11CE-840F-00AA0042CB33}") IVcPrintInformation  : public IDispatch 
	
{
	
};
typedef IVcPrintInformation PrintInformation;

__dispinterface IVcDataGrid;
typedef System::DelphiInterface<IVcDataGrid> _di_IVcDataGrid;
__dispinterface INTERFACE_UUID("{6CB603A0-8F70-11CE-840F-00AA0042CB33}") IVcDataGrid  : public IDispatch 
	
{
	
};
typedef IVcDataGrid DataGrid;

__dispinterface IVcPlot;
typedef System::DelphiInterface<IVcPlot> _di_IVcPlot;
__dispinterface INTERFACE_UUID("{F77BA680-9037-11CE-86B3-444553540000}") IVcPlot  : public IDispatch 
	
{
	
};
typedef IVcPlot Plot;

__dispinterface IVcView3d;
typedef System::DelphiInterface<IVcView3d> _di_IVcView3d;
__dispinterface INTERFACE_UUID("{21645F62-90F0-11CE-86B3-444553540000}") IVcView3d  : public IDispatch 
	
{
	
};
typedef IVcView3d View3d;

__dispinterface IVcPlotBase;
typedef System::DelphiInterface<IVcPlotBase> _di_IVcPlotBase;
__dispinterface INTERFACE_UUID("{508D02E0-90FC-11CE-86B3-444553540000}") IVcPlotBase  : public IDispatch 
	
{
	
};
typedef IVcPlotBase PlotBase;

__dispinterface IVcDoughnut;
typedef System::DelphiInterface<IVcDoughnut> _di_IVcDoughnut;
__dispinterface INTERFACE_UUID("{508D02E2-90FC-11CE-86B3-444553540000}") IVcDoughnut  : public IDispatch 
	
{
	
};
typedef IVcDoughnut Doughnut;

__dispinterface IVcPie;
typedef System::DelphiInterface<IVcPie> _di_IVcPie;
__dispinterface INTERFACE_UUID("{508D02E4-90FC-11CE-86B3-444553540000}") IVcPie  : public IDispatch 
	
{
	
};
typedef IVcPie Pie;

__dispinterface IVcWeighting;
typedef System::DelphiInterface<IVcWeighting> _di_IVcWeighting;
__dispinterface INTERFACE_UUID("{508D02E6-90FC-11CE-86B3-444553540000}") IVcWeighting  : public IDispatch 
	
{
	
};
typedef IVcWeighting Weighting;

__dispinterface IVcWall;
typedef System::DelphiInterface<IVcWall> _di_IVcWall;
__dispinterface INTERFACE_UUID("{508D02E8-90FC-11CE-86B3-444553540000}") IVcWall  : public IDispatch 
	
{
	
};
typedef IVcWall Wall;

__dispinterface IVcSeries;
typedef System::DelphiInterface<IVcSeries> _di_IVcSeries;
__dispinterface INTERFACE_UUID("{0AA0FE20-912A-11CE-86B3-444553540000}") IVcSeries  : public IDispatch 
	
{
	
};
typedef IVcSeries Series;

__dispinterface IVcBar;
typedef System::DelphiInterface<IVcBar> _di_IVcBar;
__dispinterface INTERFACE_UUID("{264931C0-91F1-11CE-840F-00AA0042CB33}") IVcBar  : public IDispatch 
	
{
	
};
typedef IVcBar Bar;

__dispinterface IVcHiLo;
typedef System::DelphiInterface<IVcHiLo> _di_IVcHiLo;
__dispinterface INTERFACE_UUID("{51DCC620-95B7-11CE-86B3-444553540000}") IVcHiLo  : public IDispatch 
	
{
	
};
typedef IVcHiLo HiLo;

__dispinterface IVcPosition;
typedef System::DelphiInterface<IVcPosition> _di_IVcPosition;
__dispinterface INTERFACE_UUID("{51DCC622-95B7-11CE-86B3-444553540000}") IVcPosition  : public IDispatch 
	
{
	
};
typedef IVcPosition Position;

__dispinterface IVcSeriesMarker;
typedef System::DelphiInterface<IVcSeriesMarker> _di_IVcSeriesMarker;
__dispinterface INTERFACE_UUID("{51DCC624-95B7-11CE-86B3-444553540000}") IVcSeriesMarker  : public IDispatch 
	
{
	
};
typedef IVcSeriesMarker SeriesMarker;

__dispinterface IVcSeriesLabel;
typedef System::DelphiInterface<IVcSeriesLabel> _di_IVcSeriesLabel;
__dispinterface INTERFACE_UUID("{51DCC626-95B7-11CE-86B3-444553540000}") IVcSeriesLabel  : public IDispatch 
	
{
	
};
typedef IVcSeriesLabel SeriesLabel;

__dispinterface IVcStatLines;
typedef System::DelphiInterface<IVcStatLines> _di_IVcStatLines;
__dispinterface INTERFACE_UUID("{2F6DD6A0-95E5-11CE-86B3-444553540000}") IVcStatLines  : public IDispatch 
	
{
	
};
typedef IVcStatLines StatLine;

__dispinterface IVcDataPointLabel;
typedef System::DelphiInterface<IVcDataPointLabel> _di_IVcDataPointLabel;
__dispinterface INTERFACE_UUID("{2F6DD6A2-95E5-11CE-86B3-444553540000}") IVcDataPointLabel  : public IDispatch 
	
{
	
};
typedef IVcDataPointLabel DataPointLabel;

__dispinterface IVcDataPoint;
typedef System::DelphiInterface<IVcDataPoint> _di_IVcDataPoint;
__dispinterface INTERFACE_UUID("{2F6DD6A4-95E5-11CE-86B3-444553540000}") IVcDataPoint  : public IDispatch 
	
{
	
};
typedef IVcDataPoint DataPoint;

__dispinterface IVcAxis;
typedef System::DelphiInterface<IVcAxis> _di_IVcAxis;
__dispinterface INTERFACE_UUID("{027D7900-A023-11CE-840F-00AA0042CB33}") IVcAxis  : public IDispatch 
	
{
	
};
typedef IVcAxis Axis;

__dispinterface IVcCategoryScale;
typedef System::DelphiInterface<IVcCategoryScale> _di_IVcCategoryScale;
__dispinterface INTERFACE_UUID("{62375360-A17D-11CE-840F-00AA0042CB33}") IVcCategoryScale  : public IDispatch 
	
{
	
};
typedef IVcCategoryScale CategoryScale;

__dispinterface IVcDateScale;
typedef System::DelphiInterface<IVcDateScale> _di_IVcDateScale;
__dispinterface INTERFACE_UUID("{62375362-A17D-11CE-840F-00AA0042CB33}") IVcDateScale  : public IDispatch 
	
{
	
};
typedef IVcDateScale DateScale;

__dispinterface IVcAxisGrid;
typedef System::DelphiInterface<IVcAxisGrid> _di_IVcAxisGrid;
__dispinterface INTERFACE_UUID("{62375364-A17D-11CE-840F-00AA0042CB33}") IVcAxisGrid  : public IDispatch 
	
{
	
};
typedef IVcAxisGrid AxisGrid;

__dispinterface IVcIntersection;
typedef System::DelphiInterface<IVcIntersection> _di_IVcIntersection;
__dispinterface INTERFACE_UUID("{62375366-A17D-11CE-840F-00AA0042CB33}") IVcIntersection  : public IDispatch 
	
{
	
};
typedef IVcIntersection Intersection;

__dispinterface IVcTick;
typedef System::DelphiInterface<IVcTick> _di_IVcTick;
__dispinterface INTERFACE_UUID("{62375368-A17D-11CE-840F-00AA0042CB33}") IVcTick  : public IDispatch 
	
{
	
};
typedef IVcTick Tick;

__dispinterface IVcScale;
typedef System::DelphiInterface<IVcScale> _di_IVcScale;
__dispinterface INTERFACE_UUID("{6237536A-A17D-11CE-840F-00AA0042CB33}") IVcScale  : public IDispatch 
	
{
	
};
typedef IVcScale AxisScale;

__dispinterface IVcValueScale;
typedef System::DelphiInterface<IVcValueScale> _di_IVcValueScale;
__dispinterface INTERFACE_UUID("{6237536C-A17D-11CE-840F-00AA0042CB33}") IVcValueScale  : public IDispatch 
	
{
	
};
typedef IVcValueScale ValueScale;

__dispinterface IVcAxisTitle;
typedef System::DelphiInterface<IVcAxisTitle> _di_IVcAxisTitle;
__dispinterface INTERFACE_UUID("{6237536E-A17D-11CE-840F-00AA0042CB33}") IVcAxisTitle  : public IDispatch 
	
{
	
};
typedef IVcAxisTitle AxisTitle;

__dispinterface IVcLabel;
typedef System::DelphiInterface<IVcLabel> _di_IVcLabel;
__dispinterface INTERFACE_UUID("{62375370-A17D-11CE-840F-00AA0042CB33}") IVcLabel  : public IDispatch 
	
{
	
};
typedef IVcLabel Label_;

__dispinterface IVcLight;
typedef System::DelphiInterface<IVcLight> _di_IVcLight;
__dispinterface INTERFACE_UUID("{B54A6420-A25E-11CE-840F-00AA0042CB33}") IVcLight  : public IDispatch 
	
{
	
};
typedef IVcLight Light;

__dispinterface IVcElevation;
typedef System::DelphiInterface<IVcElevation> _di_IVcElevation;
__dispinterface INTERFACE_UUID("{A71FB700-A732-11CE-840F-00AA0042CB33}") IVcElevation  : public IDispatch 
	
{
	
};
typedef IVcElevation Elevation;

__dispinterface IVcAttribute;
typedef System::DelphiInterface<IVcAttribute> _di_IVcAttribute;
__dispinterface INTERFACE_UUID("{A71FB702-A732-11CE-840F-00AA0042CB33}") IVcAttribute  : public IDispatch 
	
{
	
};
typedef IVcAttribute Attribute;

__dispinterface IVcSurface;
typedef System::DelphiInterface<IVcSurface> _di_IVcSurface;
__dispinterface INTERFACE_UUID("{A71FB704-A732-11CE-840F-00AA0042CB33}") IVcSurface  : public IDispatch 
	
{
	
};
typedef IVcSurface Surface;

__dispinterface IVcContour;
typedef System::DelphiInterface<IVcContour> _di_IVcContour;
__dispinterface INTERFACE_UUID("{A71FB706-A732-11CE-840F-00AA0042CB33}") IVcContour  : public IDispatch 
	
{
	
};
typedef IVcContour Contour;

__dispinterface IVcLightSource;
typedef System::DelphiInterface<IVcLightSource> _di_IVcLightSource;
__dispinterface INTERFACE_UUID("{CD9EFA60-AA40-11CE-840F-00AA0042CB33}") IVcLightSource  : public IDispatch 
	
{
	
};
typedef IVcLightSource LightSource;

__dispinterface IVcSeriesCollection;
typedef System::DelphiInterface<IVcSeriesCollection> _di_IVcSeriesCollection;
__dispinterface INTERFACE_UUID("{C14E8B60-AE2B-11CE-840F-00AA0042CB33}") IVcSeriesCollection  : public IDispatch 
	
{
	
};
typedef IVcSeriesCollection SeriesCollection;

__dispinterface IVcDataPoints;
typedef System::DelphiInterface<IVcDataPoints> _di_IVcDataPoints;
__dispinterface INTERFACE_UUID("{C20E5260-B06F-11CE-840F-00AA0042CB33}") IVcDataPoints  : public IDispatch 
	
{
	
};
typedef IVcDataPoints DataPoints;

__dispinterface IVcLabels;
typedef System::DelphiInterface<IVcLabels> _di_IVcLabels;
__dispinterface INTERFACE_UUID("{62B9A400-B93D-11CE-8410-00AA0042CB33}") IVcLabels  : public IDispatch 
	
{
	
};
typedef IVcLabels Labels;

__dispinterface IVcXYZ;
typedef System::DelphiInterface<IVcXYZ> _di_IVcXYZ;
__dispinterface INTERFACE_UUID("{7D001800-BC65-11CE-8410-00AA0042CB33}") IVcXYZ  : public IDispatch 
	
{
	
};
typedef IVcXYZ XYZ;

__dispinterface IVcLightSources;
typedef System::DelphiInterface<IVcLightSources> _di_IVcLightSources;
__dispinterface INTERFACE_UUID("{6FE35CC0-CE50-11CE-8410-00AA0042CB33}") IVcLightSources  : public IDispatch 
	
{
	
};
typedef IVcLightSources LightSources;

__dispinterface IVcAttributes;
typedef System::DelphiInterface<IVcAttributes> _di_IVcAttributes;
__dispinterface INTERFACE_UUID("{5A693220-CFEF-11CE-8410-00AA0042CB33}") IVcAttributes  : public IDispatch 
	
{
	
};
typedef IVcAttributes Attributes;

__dispinterface IVcContourGradient;
typedef System::DelphiInterface<IVcContourGradient> _di_IVcContourGradient;
__dispinterface INTERFACE_UUID("{69032720-D303-11CE-8410-00AA0042CB33}") IVcContourGradient  : public IDispatch 
	
{
	
};
typedef IVcContourGradient ContourGradient;

typedef short *PSmallint1;

typedef unsigned *PSYSINT1;

typedef int *PInteger1;

typedef double *PDouble1;

__dispinterface _DVtChartEvents;
typedef System::DelphiInterface<_DVtChartEvents> _di__DVtChartEvents;
__dispinterface INTERFACE_UUID("{5A721582-5AF0-11CE-8384-0020AF2337F2}") _DVtChartEvents  : public IDispatch 
	
{
	
};

typedef void __fastcall (__closure *TVtChartChartSelected)(System::TObject* Sender, short &MouseFlags
	, short &Cancel);

typedef void __fastcall (__closure *TVtChartTitleSelected)(System::TObject* Sender, short &MouseFlags
	, short &Cancel);

typedef void __fastcall (__closure *TVtChartFootnoteSelected)(System::TObject* Sender, short &MouseFlags
	, short &Cancel);

typedef void __fastcall (__closure *TVtChartLegendSelected)(System::TObject* Sender, short &MouseFlags
	, short &Cancel);

typedef void __fastcall (__closure *TVtChartPlotSelected)(System::TObject* Sender, short &MouseFlags
	, short &Cancel);

typedef void __fastcall (__closure *TVtChartAxisSelected)(System::TObject* Sender, short &AxisId, short 
	&AxisIndex, short &MouseFlags, short &Cancel);

typedef void __fastcall (__closure *TVtChartAxisLabelSelected)(System::TObject* Sender, short &AxisId
	, short &AxisIndex, short &labelSetIndex, short &LabelIndex, short &MouseFlags, short &Cancel);

typedef void __fastcall (__closure *TVtChartAxisTitleSelected)(System::TObject* Sender, short &AxisId
	, short &AxisIndex, short &MouseFlags, short &Cancel);

typedef void __fastcall (__closure *TVtChartPointSelected)(System::TObject* Sender, short &Series, short 
	&DataPoint, short &MouseFlags, short &Cancel);

typedef void __fastcall (__closure *TVtChartPointLabelSelected)(System::TObject* Sender, short &Series
	, short &DataPoint, short &MouseFlags, short &Cancel);

typedef void __fastcall (__closure *TVtChartSeriesSelected)(System::TObject* Sender, short &Series, 
	short &MouseFlags, short &Cancel);

typedef void __fastcall (__closure *TVtChartSeriesLabelSelected)(System::TObject* Sender, short &Series
	, short &MouseFlags, short &Cancel);

typedef void __fastcall (__closure *TVtChartChartActivated)(System::TObject* Sender, short &MouseFlags
	, short &Cancel);

typedef void __fastcall (__closure *TVtChartTitleActivated)(System::TObject* Sender, short &MouseFlags
	, short &Cancel);

typedef void __fastcall (__closure *TVtChartFootnoteActivated)(System::TObject* Sender, short &MouseFlags
	, short &Cancel);

typedef void __fastcall (__closure *TVtChartLegendActivated)(System::TObject* Sender, short &MouseFlags
	, short &Cancel);

typedef void __fastcall (__closure *TVtChartPlotActivated)(System::TObject* Sender, short &MouseFlags
	, short &Cancel);

typedef void __fastcall (__closure *TVtChartAxisActivated)(System::TObject* Sender, short &AxisId, short 
	&AxisIndex, short &MouseFlags, short &Cancel);

typedef void __fastcall (__closure *TVtChartAxisLabelActivated)(System::TObject* Sender, short &AxisId
	, short &AxisIndex, short &labelSetIndex, short &LabelIndex, short &MouseFlags, short &Cancel);

typedef void __fastcall (__closure *TVtChartAxisTitleActivated)(System::TObject* Sender, short &AxisId
	, short &AxisIndex, short &MouseFlags, short &Cancel);

typedef void __fastcall (__closure *TVtChartPointActivated)(System::TObject* Sender, short &Series, 
	short &DataPoint, short &MouseFlags, short &Cancel);

typedef void __fastcall (__closure *TVtChartPointLabelActivated)(System::TObject* Sender, short &Series
	, short &DataPoint, short &MouseFlags, short &Cancel);

typedef void __fastcall (__closure *TVtChartSeriesActivated)(System::TObject* Sender, short &Series, 
	short &MouseFlags, short &Cancel);

typedef void __fastcall (__closure *TVtChartSeriesLabelActivated)(System::TObject* Sender, short &Series
	, short &MouseFlags, short &Cancel);

class DELPHICLASS TVtChart;
class PASCALIMPLEMENTATION TVtChart : public Olectrls::TOleControl 
{
	typedef Olectrls::TOleControl inherited;
	
private:
	TVtChartChartSelected FOnChartSelected;
	TVtChartTitleSelected FOnTitleSelected;
	TVtChartFootnoteSelected FOnFootnoteSelected;
	TVtChartLegendSelected FOnLegendSelected;
	TVtChartPlotSelected FOnPlotSelected;
	TVtChartAxisSelected FOnAxisSelected;
	TVtChartAxisLabelSelected FOnAxisLabelSelected;
	TVtChartAxisTitleSelected FOnAxisTitleSelected;
	TVtChartPointSelected FOnPointSelected;
	TVtChartPointLabelSelected FOnPointLabelSelected;
	TVtChartSeriesSelected FOnSeriesSelected;
	TVtChartSeriesLabelSelected FOnSeriesLabelSelected;
	TVtChartChartActivated FOnChartActivated;
	TVtChartTitleActivated FOnTitleActivated;
	TVtChartFootnoteActivated FOnFootnoteActivated;
	TVtChartLegendActivated FOnLegendActivated;
	TVtChartPlotActivated FOnPlotActivated;
	TVtChartAxisActivated FOnAxisActivated;
	TVtChartAxisLabelActivated FOnAxisLabelActivated;
	TVtChartAxisTitleActivated FOnAxisTitleActivated;
	TVtChartPointActivated FOnPointActivated;
	TVtChartPointLabelActivated FOnPointLabelActivated;
	TVtChartSeriesActivated FOnSeriesActivated;
	TVtChartSeriesLabelActivated FOnSeriesLabelActivated;
	Classes::TNotifyEvent FOnApplyChanges;
	_di__DVtChart FIntf;
	_di__DVtChart __fastcall GetControlInterface();
	
protected:
	HIDESBASE void __fastcall CreateControl(void);
	virtual void __fastcall InitControlData(void);
	_di_IDispatch __fastcall Get_Title();
	void __fastcall Set_Title(const _di_IDispatch Value);
	_di_IDispatch __fastcall Get_Footnote();
	void __fastcall Set_Footnote(const _di_IDispatch Value);
	_di_IDispatch __fastcall Get_Backdrop();
	void __fastcall Set_Backdrop(const _di_IDispatch Value);
	_di_IDispatch __fastcall Get_PrintInformation();
	void __fastcall Set_PrintInformation(const _di_IDispatch Value);
	_di_IDispatch __fastcall Get_Legend();
	void __fastcall Set_Legend(const _di_IDispatch Value);
	_di_IDispatch __fastcall Get_DataGrid();
	void __fastcall Set_DataGrid(const _di_IDispatch Value);
	_di_IDispatch __fastcall Get_Plot();
	void __fastcall Set_Plot(const _di_IDispatch Value);
	unsigned __fastcall Get_GetBitmap(const OleVariant &options);
	
public:
	void __fastcall EditPaste(void);
	void __fastcall EditCopy(void);
	void __fastcall ActivateSelectionDialog(void);
	void __fastcall Layout(void);
	void __fastcall ToDefaults(void);
	void __fastcall PrintSetupDialog(void);
	void __fastcall PrintChart(void);
	void __fastcall SelectPart(short part, short index1, short index2, short index3, short index4);
	void __fastcall GetSelectedPart(short &part, short &index1, short &index2, short &index3, short &index4
		);
	void __fastcall GetDLLVersion(short &major, short &minor);
	void __fastcall TwipsToChartPart(int xVal, int yVal, short &part, short &index1, short &index2, short 
		&index3, short &index4);
	void __fastcall ReadFromFile(const WideString FileName);
	void __fastcall WritePictureToFile(const WideString FileName, short pictureType, short options);
	void __fastcall WriteToFile(const WideString FileName);
	void __fastcall ActivateFormatMenu(int X, int Y);
	void __fastcall GetMetafile(short options, unsigned &Handle, int &Width, int &Height);
	void __fastcall CopyDataFromArray(short Top, short Left, short Bottom, short Right, const OleVariant 
		&Array_);
	void __fastcall CopyDataToArray(short Top, short Left, short Bottom, short Right, const OleVariant 
		&Array_);
	void __fastcall Draw(unsigned hDC, short hDCType, int Top, int Left, int Bottom, int Right, Word Layout
		, Word Stretch);
	void __fastcall UseWizard(void);
	void __fastcall EditChartData(void);
	HIDESBASE void __fastcall Refresh(void);
	void __fastcall AboutBox(void);
	__property _di__DVtChart ControlInterface = {read=GetControlInterface};
	__property _di__DVtChart DefaultInterface = {read=GetControlInterface};
	__property WideString SsLinkSheet = {read=GetWideStringProp, write=SetWideStringProp, index=22};
	__property int Handle = {read=GetIntegerProp, index=24, nodefault};
	__property Graphics::TPicture* Picture = {read=GetTPictureProp, index=25};
	__property _di_IDispatch Title = {read=GetIDispatchProp, write=SetIDispatchProp, index=26};
	__property _di_IDispatch Footnote = {read=GetIDispatchProp, write=SetIDispatchProp, index=27};
	__property _di_IDispatch Backdrop = {read=GetIDispatchProp, write=SetIDispatchProp, index=36};
	__property _di_IDispatch PrintInformation = {read=GetIDispatchProp, write=SetIDispatchProp, index=37
		};
	__property _di_IDispatch Legend = {read=GetIDispatchProp, write=SetIDispatchProp, index=38};
	__property _di_IDispatch DataGrid = {read=GetIDispatchProp, write=SetIDispatchProp, index=39};
	__property _di_IDispatch Plot = {read=GetIDispatchProp, write=SetIDispatchProp, index=40};
	__property unsigned GetBitmap[OleVariant options] = {read=Get_GetBitmap};
	
__published:
	__property TabStop ;
	__property Align ;
	__property DragCursor ;
	__property DragMode ;
	__property ParentShowHint ;
	__property PopupMenu ;
	__property ShowHint ;
	__property TabOrder ;
	__property Visible ;
	__property OnDragDrop ;
	__property OnDragOver ;
	__property OnEndDrag ;
	__property OnEnter ;
	__property OnExit ;
	__property OnStartDrag ;
	__property OnMouseUp ;
	__property OnMouseMove ;
	__property OnMouseDown ;
	__property OnKeyUp ;
	__property OnKeyPress ;
	__property OnKeyDown ;
	__property OnDblClick ;
	__property OnClick ;
	__property Word AutoIncrement = {read=GetWordBoolProp, write=SetWordBoolProp, stored=false, index=1
		, nodefault};
	__property Word RandomFill = {read=GetWordBoolProp, write=SetWordBoolProp, stored=false, index=2, nodefault
		};
	__property short ChartType = {read=GetSmallintProp, write=SetSmallintProp, stored=false, index=3, nodefault
		};
	__property short Column = {read=GetSmallintProp, write=SetSmallintProp, stored=false, index=4, nodefault
		};
	__property short ColumnCount = {read=GetSmallintProp, write=SetSmallintProp, stored=false, index=5, 
		nodefault};
	__property WideString ColumnLabel = {read=GetWideStringProp, write=SetWideStringProp, stored=false, 
		index=6};
	__property short ColumnLabelCount = {read=GetSmallintProp, write=SetSmallintProp, stored=false, index=7
		, nodefault};
	__property short ColumnLabelIndex = {read=GetSmallintProp, write=SetSmallintProp, stored=false, index=8
		, nodefault};
	__property WideString Data = {read=GetWideStringProp, write=SetWideStringProp, stored=false, index=9
		};
	__property WideString FootnoteText = {read=GetWideStringProp, write=SetWideStringProp, stored=false
		, index=10};
	__property Word Repaint = {read=GetWordBoolProp, write=SetWordBoolProp, stored=false, index=11, nodefault
		};
	__property short Row = {read=GetSmallintProp, write=SetSmallintProp, stored=false, index=12, nodefault
		};
	__property short RowCount = {read=GetSmallintProp, write=SetSmallintProp, stored=false, index=13, nodefault
		};
	__property WideString RowLabel = {read=GetWideStringProp, write=SetWideStringProp, stored=false, index=14
		};
	__property short RowLabelCount = {read=GetSmallintProp, write=SetSmallintProp, stored=false, index=15
		, nodefault};
	__property short RowLabelIndex = {read=GetSmallintProp, write=SetSmallintProp, stored=false, index=16
		, nodefault};
	__property short SeriesColumn = {read=GetSmallintProp, write=SetSmallintProp, stored=false, index=17
		, nodefault};
	__property short SeriesType = {read=GetSmallintProp, write=SetSmallintProp, stored=false, index=18, 
		nodefault};
	__property Word ShowLegend = {read=GetWordBoolProp, write=SetWordBoolProp, stored=false, index=19, 
		nodefault};
	__property short SsLinkMode = {read=GetSmallintProp, write=SetSmallintProp, stored=false, index=20, 
		nodefault};
	__property WideString SsLinkRange = {read=GetWideStringProp, write=SetWideStringProp, stored=false, 
		index=21};
	__property short DrawMode = {read=GetSmallintProp, write=SetSmallintProp, stored=false, index=23, nodefault
		};
	__property short BorderStyle = {read=GetSmallintProp, write=SetSmallintProp, stored=false, index=-504
		, nodefault};
	__property Word Enabled = {read=GetWordBoolProp, write=SetWordBoolProp, stored=false, index=-514, nodefault
		};
	__property short hWnd = {read=GetSmallintProp, write=SetSmallintProp, stored=false, index=-515, nodefault
		};
	__property WideString TitleText = {read=GetWideStringProp, write=SetWideStringProp, stored=false, index=28
		};
	__property Word Stacking = {read=GetWordBoolProp, write=SetWordBoolProp, stored=false, index=29, nodefault
		};
	__property short TextLengthType = {read=GetSmallintProp, write=SetSmallintProp, stored=false, index=30
		, nodefault};
	__property Word AllowUserChanges = {read=GetWordBoolProp, write=SetWordBoolProp, stored=false, index=31
		, nodefault};
	__property Word AllowSelections = {read=GetWordBoolProp, write=SetWordBoolProp, stored=false, index=32
		, nodefault};
	__property Word AllowSeriesSelection = {read=GetWordBoolProp, write=SetWordBoolProp, stored=false, 
		index=33, nodefault};
	__property Word AllowDynamicRotation = {read=GetWordBoolProp, write=SetWordBoolProp, stored=false, 
		index=34, nodefault};
	__property short ActiveSeriesCount = {read=GetSmallintProp, write=SetSmallintProp, stored=false, index=35
		, nodefault};
	__property int TwipsWidth = {read=GetIntegerProp, write=SetIntegerProp, stored=false, index=41, nodefault
		};
	__property int TwipsHeight = {read=GetIntegerProp, write=SetIntegerProp, stored=false, index=42, nodefault
		};
	__property Word AllowDithering = {read=GetWordBoolProp, write=SetWordBoolProp, stored=false, index=43
		, nodefault};
	__property short ErrorOffset = {read=GetSmallintProp, write=SetSmallintProp, stored=false, index=44
		, nodefault};
	__property Word DoSetCursor = {read=GetWordBoolProp, write=SetWordBoolProp, stored=false, index=45, 
		nodefault};
	__property WideString FileName = {read=GetWideStringProp, write=SetWideStringProp, stored=false, index=46
		};
	__property Word Chart3d = {read=GetWordBoolProp, write=SetWordBoolProp, stored=false, index=47, nodefault
		};
	__property WideString SsLinkBook = {read=GetWideStringProp, write=SetWideStringProp, stored=false, 
		index=48};
	__property TVtChartChartSelected OnChartSelected = {read=FOnChartSelected, write=FOnChartSelected};
		
	__property TVtChartTitleSelected OnTitleSelected = {read=FOnTitleSelected, write=FOnTitleSelected};
		
	__property TVtChartFootnoteSelected OnFootnoteSelected = {read=FOnFootnoteSelected, write=FOnFootnoteSelected
		};
	__property TVtChartLegendSelected OnLegendSelected = {read=FOnLegendSelected, write=FOnLegendSelected
		};
	__property TVtChartPlotSelected OnPlotSelected = {read=FOnPlotSelected, write=FOnPlotSelected};
	__property TVtChartAxisSelected OnAxisSelected = {read=FOnAxisSelected, write=FOnAxisSelected};
	__property TVtChartAxisLabelSelected OnAxisLabelSelected = {read=FOnAxisLabelSelected, write=FOnAxisLabelSelected
		};
	__property TVtChartAxisTitleSelected OnAxisTitleSelected = {read=FOnAxisTitleSelected, write=FOnAxisTitleSelected
		};
	__property TVtChartPointSelected OnPointSelected = {read=FOnPointSelected, write=FOnPointSelected};
		
	__property TVtChartPointLabelSelected OnPointLabelSelected = {read=FOnPointLabelSelected, write=FOnPointLabelSelected
		};
	__property TVtChartSeriesSelected OnSeriesSelected = {read=FOnSeriesSelected, write=FOnSeriesSelected
		};
	__property TVtChartSeriesLabelSelected OnSeriesLabelSelected = {read=FOnSeriesLabelSelected, write=
		FOnSeriesLabelSelected};
	__property TVtChartChartActivated OnChartActivated = {read=FOnChartActivated, write=FOnChartActivated
		};
	__property TVtChartTitleActivated OnTitleActivated = {read=FOnTitleActivated, write=FOnTitleActivated
		};
	__property TVtChartFootnoteActivated OnFootnoteActivated = {read=FOnFootnoteActivated, write=FOnFootnoteActivated
		};
	__property TVtChartLegendActivated OnLegendActivated = {read=FOnLegendActivated, write=FOnLegendActivated
		};
	__property TVtChartPlotActivated OnPlotActivated = {read=FOnPlotActivated, write=FOnPlotActivated};
		
	__property TVtChartAxisActivated OnAxisActivated = {read=FOnAxisActivated, write=FOnAxisActivated};
		
	__property TVtChartAxisLabelActivated OnAxisLabelActivated = {read=FOnAxisLabelActivated, write=FOnAxisLabelActivated
		};
	__property TVtChartAxisTitleActivated OnAxisTitleActivated = {read=FOnAxisTitleActivated, write=FOnAxisTitleActivated
		};
	__property TVtChartPointActivated OnPointActivated = {read=FOnPointActivated, write=FOnPointActivated
		};
	__property TVtChartPointLabelActivated OnPointLabelActivated = {read=FOnPointLabelActivated, write=
		FOnPointLabelActivated};
	__property TVtChartSeriesActivated OnSeriesActivated = {read=FOnSeriesActivated, write=FOnSeriesActivated
		};
	__property TVtChartSeriesLabelActivated OnSeriesLabelActivated = {read=FOnSeriesLabelActivated, write=
		FOnSeriesLabelActivated};
	__property Classes::TNotifyEvent OnApplyChanges = {read=FOnApplyChanges, write=FOnApplyChanges};
public:
		
	#pragma option push -w-inl
	/* TOleControl.Create */ inline __fastcall virtual TVtChart(Classes::TComponent* AOwner) : Olectrls::TOleControl(
		AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TOleControl.Destroy */ inline __fastcall virtual ~TVtChart(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TVtChart(HWND ParentWindow) : Olectrls::TOleControl(
		ParentWindow) { }
	#pragma option pop
	
};


class DELPHICLASS CoCoor;
class PASCALIMPLEMENTATION CoCoor : public System::TObject 
{
	typedef System::TObject inherited;
	
public:
	/*         class method */ static _di_ICoor __fastcall Create(TMetaClass* vmt);
	/*         class method */ static _di_ICoor __fastcall CreateRemote(TMetaClass* vmt, const AnsiString 
		MachineName);
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall CoCoor(void) : System::TObject() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~CoCoor(void) { }
	#pragma option pop
	
};


class DELPHICLASS CoLCoor;
class PASCALIMPLEMENTATION CoLCoor : public System::TObject 
{
	typedef System::TObject inherited;
	
public:
	/*         class method */ static _di_ILCoor __fastcall Create(TMetaClass* vmt);
	/*         class method */ static _di_ILCoor __fastcall CreateRemote(TMetaClass* vmt, const AnsiString 
		MachineName);
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall CoLCoor(void) : System::TObject() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~CoLCoor(void) { }
	#pragma option pop
	
};


class DELPHICLASS CoCoor3;
class PASCALIMPLEMENTATION CoCoor3 : public System::TObject 
{
	typedef System::TObject inherited;
	
public:
	/*         class method */ static _di_ICoor3 __fastcall Create(TMetaClass* vmt);
	/*         class method */ static _di_ICoor3 __fastcall CreateRemote(TMetaClass* vmt, const AnsiString 
		MachineName);
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall CoCoor3(void) : System::TObject() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~CoCoor3(void) { }
	#pragma option pop
	
};


class DELPHICLASS CoLRect;
class PASCALIMPLEMENTATION CoLRect : public System::TObject 
{
	typedef System::TObject inherited;
	
public:
	/*         class method */ static _di_ILRect __fastcall Create(TMetaClass* vmt);
	/*         class method */ static _di_ILRect __fastcall CreateRemote(TMetaClass* vmt, const AnsiString 
		MachineName);
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall CoLRect(void) : System::TObject() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~CoLRect(void) { }
	#pragma option pop
	
};


class DELPHICLASS CoRect;
class PASCALIMPLEMENTATION CoRect : public System::TObject 
{
	typedef System::TObject inherited;
	
public:
	/*         class method */ static _di_IRect __fastcall Create(TMetaClass* vmt);
	/*         class method */ static _di_IRect __fastcall CreateRemote(TMetaClass* vmt, const AnsiString 
		MachineName);
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall CoRect(void) : System::TObject() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~CoRect(void) { }
	#pragma option pop
	
};


class DELPHICLASS CoVtColor;
class PASCALIMPLEMENTATION CoVtColor : public System::TObject 
{
	typedef System::TObject inherited;
	
public:
	/*         class method */ static _di_IColor __fastcall Create(TMetaClass* vmt);
	/*         class method */ static _di_IColor __fastcall CreateRemote(TMetaClass* vmt, const AnsiString 
		MachineName);
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall CoVtColor(void) : System::TObject() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~CoVtColor(void) { }
	#pragma option pop
	
};


class DELPHICLASS CoBrush;
class PASCALIMPLEMENTATION CoBrush : public System::TObject 
{
	typedef System::TObject inherited;
	
public:
	/*         class method */ static _di_IBrush __fastcall Create(TMetaClass* vmt);
	/*         class method */ static _di_IBrush __fastcall CreateRemote(TMetaClass* vmt, const AnsiString 
		MachineName);
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall CoBrush(void) : System::TObject() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~CoBrush(void) { }
	#pragma option pop
	
};


class DELPHICLASS CoShadow;
class PASCALIMPLEMENTATION CoShadow : public System::TObject 
{
	typedef System::TObject inherited;
	
public:
	/*         class method */ static _di_IShadow __fastcall Create(TMetaClass* vmt);
	/*         class method */ static _di_IShadow __fastcall CreateRemote(TMetaClass* vmt, const AnsiString 
		MachineName);
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall CoShadow(void) : System::TObject() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~CoShadow(void) { }
	#pragma option pop
	
};


class DELPHICLASS CoTextLayout;
class PASCALIMPLEMENTATION CoTextLayout : public System::TObject 
{
	typedef System::TObject inherited;
	
public:
	/*         class method */ static _di_ITextLayout __fastcall Create(TMetaClass* vmt);
	/*         class method */ static _di_ITextLayout __fastcall CreateRemote(TMetaClass* vmt, const AnsiString 
		MachineName);
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall CoTextLayout(void) : System::TObject() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~CoTextLayout(void) { }
	#pragma option pop
	
};


class DELPHICLASS CoTitle;
class PASCALIMPLEMENTATION CoTitle : public System::TObject 
{
	typedef System::TObject inherited;
	
public:
	/*         class method */ static _di_IVcTitle __fastcall Create(TMetaClass* vmt);
	/*         class method */ static _di_IVcTitle __fastcall CreateRemote(TMetaClass* vmt, const AnsiString 
		MachineName);
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall CoTitle(void) : System::TObject() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~CoTitle(void) { }
	#pragma option pop
	
};


class DELPHICLASS CoLocation;
class PASCALIMPLEMENTATION CoLocation : public System::TObject 
{
	typedef System::TObject inherited;
	
public:
	/*         class method */ static _di_ILocation __fastcall Create(TMetaClass* vmt);
	/*         class method */ static _di_ILocation __fastcall CreateRemote(TMetaClass* vmt, const AnsiString 
		MachineName);
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall CoLocation(void) : System::TObject() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~CoLocation(void) { }
	#pragma option pop
	
};


class DELPHICLASS CoVtFont;
class PASCALIMPLEMENTATION CoVtFont : public System::TObject 
{
	typedef System::TObject inherited;
	
public:
	/*         class method */ static _di_IFont __fastcall Create(TMetaClass* vmt);
	/*         class method */ static _di_IFont __fastcall CreateRemote(TMetaClass* vmt, const AnsiString 
		MachineName);
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall CoVtFont(void) : System::TObject() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~CoVtFont(void) { }
	#pragma option pop
	
};


class DELPHICLASS CoBackdrop;
class PASCALIMPLEMENTATION CoBackdrop : public System::TObject 
{
	typedef System::TObject inherited;
	
public:
	/*         class method */ static _di_IBackdrop __fastcall Create(TMetaClass* vmt);
	/*         class method */ static _di_IBackdrop __fastcall CreateRemote(TMetaClass* vmt, const AnsiString 
		MachineName);
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall CoBackdrop(void) : System::TObject() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~CoBackdrop(void) { }
	#pragma option pop
	
};


class DELPHICLASS CoFrame;
class PASCALIMPLEMENTATION CoFrame : public System::TObject 
{
	typedef System::TObject inherited;
	
public:
	/*         class method */ static _di_IFrame __fastcall Create(TMetaClass* vmt);
	/*         class method */ static _di_IFrame __fastcall CreateRemote(TMetaClass* vmt, const AnsiString 
		MachineName);
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall CoFrame(void) : System::TObject() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~CoFrame(void) { }
	#pragma option pop
	
};


class DELPHICLASS CoGradient;
class PASCALIMPLEMENTATION CoGradient : public System::TObject 
{
	typedef System::TObject inherited;
	
public:
	/*         class method */ static _di_IGradient __fastcall Create(TMetaClass* vmt);
	/*         class method */ static _di_IGradient __fastcall CreateRemote(TMetaClass* vmt, const AnsiString 
		MachineName);
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall CoGradient(void) : System::TObject() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~CoGradient(void) { }
	#pragma option pop
	
};


class DELPHICLASS CoVtPicture;
class PASCALIMPLEMENTATION CoVtPicture : public System::TObject 
{
	typedef System::TObject inherited;
	
public:
	/*         class method */ static _di_IPicture __fastcall Create(TMetaClass* vmt);
	/*         class method */ static _di_IPicture __fastcall CreateRemote(TMetaClass* vmt, const AnsiString 
		MachineName);
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall CoVtPicture(void) : System::TObject() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~CoVtPicture(void) { }
	#pragma option pop
	
};


class DELPHICLASS CoFill;
class PASCALIMPLEMENTATION CoFill : public System::TObject 
{
	typedef System::TObject inherited;
	
public:
	/*         class method */ static _di_IFill __fastcall Create(TMetaClass* vmt);
	/*         class method */ static _di_IFill __fastcall CreateRemote(TMetaClass* vmt, const AnsiString 
		MachineName);
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall CoFill(void) : System::TObject() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~CoFill(void) { }
	#pragma option pop
	
};


class DELPHICLASS CoPen;
class PASCALIMPLEMENTATION CoPen : public System::TObject 
{
	typedef System::TObject inherited;
	
public:
	/*         class method */ static _di_IVcPen __fastcall Create(TMetaClass* vmt);
	/*         class method */ static _di_IVcPen __fastcall CreateRemote(TMetaClass* vmt, const AnsiString 
		MachineName);
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall CoPen(void) : System::TObject() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~CoPen(void) { }
	#pragma option pop
	
};


class DELPHICLASS CoMarker;
class PASCALIMPLEMENTATION CoMarker : public System::TObject 
{
	typedef System::TObject inherited;
	
public:
	/*         class method */ static _di_IVcMarker __fastcall Create(TMetaClass* vmt);
	/*         class method */ static _di_IVcMarker __fastcall CreateRemote(TMetaClass* vmt, const AnsiString 
		MachineName);
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall CoMarker(void) : System::TObject() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~CoMarker(void) { }
	#pragma option pop
	
};


class DELPHICLASS CoFootnote;
class PASCALIMPLEMENTATION CoFootnote : public System::TObject 
{
	typedef System::TObject inherited;
	
public:
	/*         class method */ static _di_IVcFootnote __fastcall Create(TMetaClass* vmt);
	/*         class method */ static _di_IVcFootnote __fastcall CreateRemote(TMetaClass* vmt, const AnsiString 
		MachineName);
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall CoFootnote(void) : System::TObject() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~CoFootnote(void) { }
	#pragma option pop
	
};


class DELPHICLASS CoLegend;
class PASCALIMPLEMENTATION CoLegend : public System::TObject 
{
	typedef System::TObject inherited;
	
public:
	/*         class method */ static _di_IVcLegend __fastcall Create(TMetaClass* vmt);
	/*         class method */ static _di_IVcLegend __fastcall CreateRemote(TMetaClass* vmt, const AnsiString 
		MachineName);
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall CoLegend(void) : System::TObject() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~CoLegend(void) { }
	#pragma option pop
	
};


class DELPHICLASS CoPrintInformation;
class PASCALIMPLEMENTATION CoPrintInformation : public System::TObject 
{
	typedef System::TObject inherited;
	
public:
	/*         class method */ static _di_IVcPrintInformation __fastcall Create(TMetaClass* vmt);
	/*         class method */ static _di_IVcPrintInformation __fastcall CreateRemote(TMetaClass* vmt, 
		const AnsiString MachineName);
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall CoPrintInformation(void) : System::TObject() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~CoPrintInformation(void) { }
	#pragma option pop
	
};


class DELPHICLASS CoDataGrid;
class PASCALIMPLEMENTATION CoDataGrid : public System::TObject 
{
	typedef System::TObject inherited;
	
public:
	/*         class method */ static _di_IVcDataGrid __fastcall Create(TMetaClass* vmt);
	/*         class method */ static _di_IVcDataGrid __fastcall CreateRemote(TMetaClass* vmt, const AnsiString 
		MachineName);
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall CoDataGrid(void) : System::TObject() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~CoDataGrid(void) { }
	#pragma option pop
	
};


class DELPHICLASS CoPlot;
class PASCALIMPLEMENTATION CoPlot : public System::TObject 
{
	typedef System::TObject inherited;
	
public:
	/*         class method */ static _di_IVcPlot __fastcall Create(TMetaClass* vmt);
	/*         class method */ static _di_IVcPlot __fastcall CreateRemote(TMetaClass* vmt, const AnsiString 
		MachineName);
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall CoPlot(void) : System::TObject() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~CoPlot(void) { }
	#pragma option pop
	
};


class DELPHICLASS CoView3d;
class PASCALIMPLEMENTATION CoView3d : public System::TObject 
{
	typedef System::TObject inherited;
	
public:
	/*         class method */ static _di_IVcView3d __fastcall Create(TMetaClass* vmt);
	/*         class method */ static _di_IVcView3d __fastcall CreateRemote(TMetaClass* vmt, const AnsiString 
		MachineName);
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall CoView3d(void) : System::TObject() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~CoView3d(void) { }
	#pragma option pop
	
};


class DELPHICLASS CoPlotBase;
class PASCALIMPLEMENTATION CoPlotBase : public System::TObject 
{
	typedef System::TObject inherited;
	
public:
	/*         class method */ static _di_IVcPlotBase __fastcall Create(TMetaClass* vmt);
	/*         class method */ static _di_IVcPlotBase __fastcall CreateRemote(TMetaClass* vmt, const AnsiString 
		MachineName);
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall CoPlotBase(void) : System::TObject() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~CoPlotBase(void) { }
	#pragma option pop
	
};


class DELPHICLASS CoDoughnut;
class PASCALIMPLEMENTATION CoDoughnut : public System::TObject 
{
	typedef System::TObject inherited;
	
public:
	/*         class method */ static _di_IVcDoughnut __fastcall Create(TMetaClass* vmt);
	/*         class method */ static _di_IVcDoughnut __fastcall CreateRemote(TMetaClass* vmt, const AnsiString 
		MachineName);
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall CoDoughnut(void) : System::TObject() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~CoDoughnut(void) { }
	#pragma option pop
	
};


class DELPHICLASS CoPie;
class PASCALIMPLEMENTATION CoPie : public System::TObject 
{
	typedef System::TObject inherited;
	
public:
	/*         class method */ static _di_IVcPie __fastcall Create(TMetaClass* vmt);
	/*         class method */ static _di_IVcPie __fastcall CreateRemote(TMetaClass* vmt, const AnsiString 
		MachineName);
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall CoPie(void) : System::TObject() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~CoPie(void) { }
	#pragma option pop
	
};


class DELPHICLASS CoWeighting;
class PASCALIMPLEMENTATION CoWeighting : public System::TObject 
{
	typedef System::TObject inherited;
	
public:
	/*         class method */ static _di_IVcWeighting __fastcall Create(TMetaClass* vmt);
	/*         class method */ static _di_IVcWeighting __fastcall CreateRemote(TMetaClass* vmt, const AnsiString 
		MachineName);
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall CoWeighting(void) : System::TObject() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~CoWeighting(void) { }
	#pragma option pop
	
};


class DELPHICLASS CoWall;
class PASCALIMPLEMENTATION CoWall : public System::TObject 
{
	typedef System::TObject inherited;
	
public:
	/*         class method */ static _di_IVcWall __fastcall Create(TMetaClass* vmt);
	/*         class method */ static _di_IVcWall __fastcall CreateRemote(TMetaClass* vmt, const AnsiString 
		MachineName);
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall CoWall(void) : System::TObject() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~CoWall(void) { }
	#pragma option pop
	
};


class DELPHICLASS CoSeries;
class PASCALIMPLEMENTATION CoSeries : public System::TObject 
{
	typedef System::TObject inherited;
	
public:
	/*         class method */ static _di_IVcSeries __fastcall Create(TMetaClass* vmt);
	/*         class method */ static _di_IVcSeries __fastcall CreateRemote(TMetaClass* vmt, const AnsiString 
		MachineName);
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall CoSeries(void) : System::TObject() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~CoSeries(void) { }
	#pragma option pop
	
};


class DELPHICLASS CoBar;
class PASCALIMPLEMENTATION CoBar : public System::TObject 
{
	typedef System::TObject inherited;
	
public:
	/*         class method */ static _di_IVcBar __fastcall Create(TMetaClass* vmt);
	/*         class method */ static _di_IVcBar __fastcall CreateRemote(TMetaClass* vmt, const AnsiString 
		MachineName);
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall CoBar(void) : System::TObject() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~CoBar(void) { }
	#pragma option pop
	
};


class DELPHICLASS CoHiLo;
class PASCALIMPLEMENTATION CoHiLo : public System::TObject 
{
	typedef System::TObject inherited;
	
public:
	/*         class method */ static _di_IVcHiLo __fastcall Create(TMetaClass* vmt);
	/*         class method */ static _di_IVcHiLo __fastcall CreateRemote(TMetaClass* vmt, const AnsiString 
		MachineName);
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall CoHiLo(void) : System::TObject() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~CoHiLo(void) { }
	#pragma option pop
	
};


class DELPHICLASS CoPosition;
class PASCALIMPLEMENTATION CoPosition : public System::TObject 
{
	typedef System::TObject inherited;
	
public:
	/*         class method */ static _di_IVcPosition __fastcall Create(TMetaClass* vmt);
	/*         class method */ static _di_IVcPosition __fastcall CreateRemote(TMetaClass* vmt, const AnsiString 
		MachineName);
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall CoPosition(void) : System::TObject() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~CoPosition(void) { }
	#pragma option pop
	
};


class DELPHICLASS CoSeriesMarker;
class PASCALIMPLEMENTATION CoSeriesMarker : public System::TObject 
{
	typedef System::TObject inherited;
	
public:
	/*         class method */ static _di_IVcSeriesMarker __fastcall Create(TMetaClass* vmt);
	/*         class method */ static _di_IVcSeriesMarker __fastcall CreateRemote(TMetaClass* vmt, const 
		AnsiString MachineName);
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall CoSeriesMarker(void) : System::TObject() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~CoSeriesMarker(void) { }
	#pragma option pop
	
};


class DELPHICLASS CoSeriesLabel;
class PASCALIMPLEMENTATION CoSeriesLabel : public System::TObject 
{
	typedef System::TObject inherited;
	
public:
	/*         class method */ static _di_IVcSeriesLabel __fastcall Create(TMetaClass* vmt);
	/*         class method */ static _di_IVcSeriesLabel __fastcall CreateRemote(TMetaClass* vmt, const 
		AnsiString MachineName);
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall CoSeriesLabel(void) : System::TObject() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~CoSeriesLabel(void) { }
	#pragma option pop
	
};


class DELPHICLASS CoStatLine;
class PASCALIMPLEMENTATION CoStatLine : public System::TObject 
{
	typedef System::TObject inherited;
	
public:
	/*         class method */ static _di_IVcStatLines __fastcall Create(TMetaClass* vmt);
	/*         class method */ static _di_IVcStatLines __fastcall CreateRemote(TMetaClass* vmt, const AnsiString 
		MachineName);
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall CoStatLine(void) : System::TObject() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~CoStatLine(void) { }
	#pragma option pop
	
};


class DELPHICLASS CoDataPointLabel;
class PASCALIMPLEMENTATION CoDataPointLabel : public System::TObject 
{
	typedef System::TObject inherited;
	
public:
	/*         class method */ static _di_IVcDataPointLabel __fastcall Create(TMetaClass* vmt);
	/*         class method */ static _di_IVcDataPointLabel __fastcall CreateRemote(TMetaClass* vmt, const 
		AnsiString MachineName);
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall CoDataPointLabel(void) : System::TObject() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~CoDataPointLabel(void) { }
	#pragma option pop
	
};


class DELPHICLASS CoDataPoint;
class PASCALIMPLEMENTATION CoDataPoint : public System::TObject 
{
	typedef System::TObject inherited;
	
public:
	/*         class method */ static _di_IVcDataPoint __fastcall Create(TMetaClass* vmt);
	/*         class method */ static _di_IVcDataPoint __fastcall CreateRemote(TMetaClass* vmt, const AnsiString 
		MachineName);
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall CoDataPoint(void) : System::TObject() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~CoDataPoint(void) { }
	#pragma option pop
	
};


class DELPHICLASS CoAxis;
class PASCALIMPLEMENTATION CoAxis : public System::TObject 
{
	typedef System::TObject inherited;
	
public:
	/*         class method */ static _di_IVcAxis __fastcall Create(TMetaClass* vmt);
	/*         class method */ static _di_IVcAxis __fastcall CreateRemote(TMetaClass* vmt, const AnsiString 
		MachineName);
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall CoAxis(void) : System::TObject() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~CoAxis(void) { }
	#pragma option pop
	
};


class DELPHICLASS CoCategoryScale;
class PASCALIMPLEMENTATION CoCategoryScale : public System::TObject 
{
	typedef System::TObject inherited;
	
public:
	/*         class method */ static _di_IVcCategoryScale __fastcall Create(TMetaClass* vmt);
	/*         class method */ static _di_IVcCategoryScale __fastcall CreateRemote(TMetaClass* vmt, const 
		AnsiString MachineName);
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall CoCategoryScale(void) : System::TObject() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~CoCategoryScale(void) { }
	#pragma option pop
	
};


class DELPHICLASS CoDateScale;
class PASCALIMPLEMENTATION CoDateScale : public System::TObject 
{
	typedef System::TObject inherited;
	
public:
	/*         class method */ static _di_IVcDateScale __fastcall Create(TMetaClass* vmt);
	/*         class method */ static _di_IVcDateScale __fastcall CreateRemote(TMetaClass* vmt, const AnsiString 
		MachineName);
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall CoDateScale(void) : System::TObject() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~CoDateScale(void) { }
	#pragma option pop
	
};


class DELPHICLASS CoAxisGrid;
class PASCALIMPLEMENTATION CoAxisGrid : public System::TObject 
{
	typedef System::TObject inherited;
	
public:
	/*         class method */ static _di_IVcAxisGrid __fastcall Create(TMetaClass* vmt);
	/*         class method */ static _di_IVcAxisGrid __fastcall CreateRemote(TMetaClass* vmt, const AnsiString 
		MachineName);
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall CoAxisGrid(void) : System::TObject() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~CoAxisGrid(void) { }
	#pragma option pop
	
};


class DELPHICLASS CoIntersection;
class PASCALIMPLEMENTATION CoIntersection : public System::TObject 
{
	typedef System::TObject inherited;
	
public:
	/*         class method */ static _di_IVcIntersection __fastcall Create(TMetaClass* vmt);
	/*         class method */ static _di_IVcIntersection __fastcall CreateRemote(TMetaClass* vmt, const 
		AnsiString MachineName);
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall CoIntersection(void) : System::TObject() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~CoIntersection(void) { }
	#pragma option pop
	
};


class DELPHICLASS CoTick;
class PASCALIMPLEMENTATION CoTick : public System::TObject 
{
	typedef System::TObject inherited;
	
public:
	/*         class method */ static _di_IVcTick __fastcall Create(TMetaClass* vmt);
	/*         class method */ static _di_IVcTick __fastcall CreateRemote(TMetaClass* vmt, const AnsiString 
		MachineName);
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall CoTick(void) : System::TObject() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~CoTick(void) { }
	#pragma option pop
	
};


class DELPHICLASS CoAxisScale;
class PASCALIMPLEMENTATION CoAxisScale : public System::TObject 
{
	typedef System::TObject inherited;
	
public:
	/*         class method */ static _di_IVcScale __fastcall Create(TMetaClass* vmt);
	/*         class method */ static _di_IVcScale __fastcall CreateRemote(TMetaClass* vmt, const AnsiString 
		MachineName);
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall CoAxisScale(void) : System::TObject() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~CoAxisScale(void) { }
	#pragma option pop
	
};


class DELPHICLASS CoValueScale;
class PASCALIMPLEMENTATION CoValueScale : public System::TObject 
{
	typedef System::TObject inherited;
	
public:
	/*         class method */ static _di_IVcValueScale __fastcall Create(TMetaClass* vmt);
	/*         class method */ static _di_IVcValueScale __fastcall CreateRemote(TMetaClass* vmt, const 
		AnsiString MachineName);
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall CoValueScale(void) : System::TObject() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~CoValueScale(void) { }
	#pragma option pop
	
};


class DELPHICLASS CoAxisTitle;
class PASCALIMPLEMENTATION CoAxisTitle : public System::TObject 
{
	typedef System::TObject inherited;
	
public:
	/*         class method */ static _di_IVcAxisTitle __fastcall Create(TMetaClass* vmt);
	/*         class method */ static _di_IVcAxisTitle __fastcall CreateRemote(TMetaClass* vmt, const AnsiString 
		MachineName);
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall CoAxisTitle(void) : System::TObject() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~CoAxisTitle(void) { }
	#pragma option pop
	
};


class DELPHICLASS CoLabel_;
class PASCALIMPLEMENTATION CoLabel_ : public System::TObject 
{
	typedef System::TObject inherited;
	
public:
	/*         class method */ static _di_IVcLabel __fastcall Create(TMetaClass* vmt);
	/*         class method */ static _di_IVcLabel __fastcall CreateRemote(TMetaClass* vmt, const AnsiString 
		MachineName);
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall CoLabel_(void) : System::TObject() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~CoLabel_(void) { }
	#pragma option pop
	
};


class DELPHICLASS CoLight;
class PASCALIMPLEMENTATION CoLight : public System::TObject 
{
	typedef System::TObject inherited;
	
public:
	/*         class method */ static _di_IVcLight __fastcall Create(TMetaClass* vmt);
	/*         class method */ static _di_IVcLight __fastcall CreateRemote(TMetaClass* vmt, const AnsiString 
		MachineName);
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall CoLight(void) : System::TObject() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~CoLight(void) { }
	#pragma option pop
	
};


class DELPHICLASS CoElevation;
class PASCALIMPLEMENTATION CoElevation : public System::TObject 
{
	typedef System::TObject inherited;
	
public:
	/*         class method */ static _di_IVcElevation __fastcall Create(TMetaClass* vmt);
	/*         class method */ static _di_IVcElevation __fastcall CreateRemote(TMetaClass* vmt, const AnsiString 
		MachineName);
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall CoElevation(void) : System::TObject() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~CoElevation(void) { }
	#pragma option pop
	
};


class DELPHICLASS CoAttribute;
class PASCALIMPLEMENTATION CoAttribute : public System::TObject 
{
	typedef System::TObject inherited;
	
public:
	/*         class method */ static _di_IVcAttribute __fastcall Create(TMetaClass* vmt);
	/*         class method */ static _di_IVcAttribute __fastcall CreateRemote(TMetaClass* vmt, const AnsiString 
		MachineName);
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall CoAttribute(void) : System::TObject() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~CoAttribute(void) { }
	#pragma option pop
	
};


class DELPHICLASS CoSurface;
class PASCALIMPLEMENTATION CoSurface : public System::TObject 
{
	typedef System::TObject inherited;
	
public:
	/*         class method */ static _di_IVcSurface __fastcall Create(TMetaClass* vmt);
	/*         class method */ static _di_IVcSurface __fastcall CreateRemote(TMetaClass* vmt, const AnsiString 
		MachineName);
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall CoSurface(void) : System::TObject() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~CoSurface(void) { }
	#pragma option pop
	
};


class DELPHICLASS CoContour;
class PASCALIMPLEMENTATION CoContour : public System::TObject 
{
	typedef System::TObject inherited;
	
public:
	/*         class method */ static _di_IVcContour __fastcall Create(TMetaClass* vmt);
	/*         class method */ static _di_IVcContour __fastcall CreateRemote(TMetaClass* vmt, const AnsiString 
		MachineName);
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall CoContour(void) : System::TObject() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~CoContour(void) { }
	#pragma option pop
	
};


class DELPHICLASS CoLightSource;
class PASCALIMPLEMENTATION CoLightSource : public System::TObject 
{
	typedef System::TObject inherited;
	
public:
	/*         class method */ static _di_IVcLightSource __fastcall Create(TMetaClass* vmt);
	/*         class method */ static _di_IVcLightSource __fastcall CreateRemote(TMetaClass* vmt, const 
		AnsiString MachineName);
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall CoLightSource(void) : System::TObject() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~CoLightSource(void) { }
	#pragma option pop
	
};


class DELPHICLASS CoSeriesCollection;
class PASCALIMPLEMENTATION CoSeriesCollection : public System::TObject 
{
	typedef System::TObject inherited;
	
public:
	/*         class method */ static _di_IVcSeriesCollection __fastcall Create(TMetaClass* vmt);
	/*         class method */ static _di_IVcSeriesCollection __fastcall CreateRemote(TMetaClass* vmt, 
		const AnsiString MachineName);
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall CoSeriesCollection(void) : System::TObject() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~CoSeriesCollection(void) { }
	#pragma option pop
	
};


class DELPHICLASS CoDataPoints;
class PASCALIMPLEMENTATION CoDataPoints : public System::TObject 
{
	typedef System::TObject inherited;
	
public:
	/*         class method */ static _di_IVcDataPoints __fastcall Create(TMetaClass* vmt);
	/*         class method */ static _di_IVcDataPoints __fastcall CreateRemote(TMetaClass* vmt, const 
		AnsiString MachineName);
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall CoDataPoints(void) : System::TObject() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~CoDataPoints(void) { }
	#pragma option pop
	
};


class DELPHICLASS CoLabels;
class PASCALIMPLEMENTATION CoLabels : public System::TObject 
{
	typedef System::TObject inherited;
	
public:
	/*         class method */ static _di_IVcLabels __fastcall Create(TMetaClass* vmt);
	/*         class method */ static _di_IVcLabels __fastcall CreateRemote(TMetaClass* vmt, const AnsiString 
		MachineName);
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall CoLabels(void) : System::TObject() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~CoLabels(void) { }
	#pragma option pop
	
};


class DELPHICLASS CoXYZ;
class PASCALIMPLEMENTATION CoXYZ : public System::TObject 
{
	typedef System::TObject inherited;
	
public:
	/*         class method */ static _di_IVcXYZ __fastcall Create(TMetaClass* vmt);
	/*         class method */ static _di_IVcXYZ __fastcall CreateRemote(TMetaClass* vmt, const AnsiString 
		MachineName);
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall CoXYZ(void) : System::TObject() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~CoXYZ(void) { }
	#pragma option pop
	
};


class DELPHICLASS CoLightSources;
class PASCALIMPLEMENTATION CoLightSources : public System::TObject 
{
	typedef System::TObject inherited;
	
public:
	/*         class method */ static _di_IVcLightSources __fastcall Create(TMetaClass* vmt);
	/*         class method */ static _di_IVcLightSources __fastcall CreateRemote(TMetaClass* vmt, const 
		AnsiString MachineName);
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall CoLightSources(void) : System::TObject() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~CoLightSources(void) { }
	#pragma option pop
	
};


class DELPHICLASS CoAttributes;
class PASCALIMPLEMENTATION CoAttributes : public System::TObject 
{
	typedef System::TObject inherited;
	
public:
	/*         class method */ static _di_IVcAttributes __fastcall Create(TMetaClass* vmt);
	/*         class method */ static _di_IVcAttributes __fastcall CreateRemote(TMetaClass* vmt, const 
		AnsiString MachineName);
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall CoAttributes(void) : System::TObject() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~CoAttributes(void) { }
	#pragma option pop
	
};


class DELPHICLASS CoContourGradient;
class PASCALIMPLEMENTATION CoContourGradient : public System::TObject 
{
	typedef System::TObject inherited;
	
public:
	/*         class method */ static _di_IVcContourGradient __fastcall Create(TMetaClass* vmt);
	/*         class method */ static _di_IVcContourGradient __fastcall CreateRemote(TMetaClass* vmt, const 
		AnsiString MachineName);
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall CoContourGradient(void) : System::TObject() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~CoContourGradient(void) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------
static const Shortint VCIFiLibMajorVersion = 0x1;
static const Shortint VCIFiLibMinorVersion = 0x0;
extern PACKAGE GUID LIBID_VCIFiLib;
extern PACKAGE GUID DIID__DVtChart;
extern PACKAGE GUID DIID__DVtChartEvents;
extern PACKAGE GUID CLASS_VtChart;
extern PACKAGE GUID DIID_ICoor;
extern PACKAGE GUID CLASS_Coor;
extern PACKAGE GUID DIID_ILCoor;
extern PACKAGE GUID CLASS_LCoor;
extern PACKAGE GUID DIID_ICoor3;
extern PACKAGE GUID CLASS_Coor3;
extern PACKAGE GUID DIID_ILRect;
extern PACKAGE GUID CLASS_LRect;
extern PACKAGE GUID DIID_IRect;
extern PACKAGE GUID CLASS_Rect;
extern PACKAGE GUID DIID_IColor;
extern PACKAGE GUID CLASS_VtColor;
extern PACKAGE GUID DIID_IBrush;
extern PACKAGE GUID CLASS_Brush;
extern PACKAGE GUID DIID_IShadow;
extern PACKAGE GUID CLASS_Shadow;
extern PACKAGE GUID DIID_ITextLayout;
extern PACKAGE GUID CLASS_TextLayout;
extern PACKAGE GUID DIID_IVcTitle;
extern PACKAGE GUID CLASS_Title;
extern PACKAGE GUID DIID_ILocation;
extern PACKAGE GUID CLASS_Location;
extern PACKAGE GUID DIID_IFont;
extern PACKAGE GUID CLASS_VtFont;
extern PACKAGE GUID DIID_IBackdrop;
extern PACKAGE GUID CLASS_Backdrop;
extern PACKAGE GUID DIID_IFrame;
extern PACKAGE GUID CLASS_Frame;
extern PACKAGE GUID DIID_IGradient;
extern PACKAGE GUID CLASS_Gradient;
extern PACKAGE GUID DIID_IPicture;
extern PACKAGE GUID CLASS_VtPicture;
extern PACKAGE GUID DIID_IFill;
extern PACKAGE GUID CLASS_Fill;
extern PACKAGE GUID DIID_IVcPen;
extern PACKAGE GUID CLASS_Pen;
extern PACKAGE GUID DIID_IVcMarker;
extern PACKAGE GUID CLASS_Marker;
extern PACKAGE GUID DIID_IVcFootnote;
extern PACKAGE GUID CLASS_Footnote;
extern PACKAGE GUID DIID_IVcLegend;
extern PACKAGE GUID CLASS_Legend;
extern PACKAGE GUID DIID_IVcPrintInformation;
extern PACKAGE GUID CLASS_PrintInformation;
extern PACKAGE GUID DIID_IVcDataGrid;
extern PACKAGE GUID CLASS_DataGrid;
extern PACKAGE GUID DIID_IVcPlot;
extern PACKAGE GUID CLASS_Plot;
extern PACKAGE GUID DIID_IVcView3d;
extern PACKAGE GUID CLASS_View3d;
extern PACKAGE GUID DIID_IVcPlotBase;
extern PACKAGE GUID CLASS_PlotBase;
extern PACKAGE GUID DIID_IVcDoughnut;
extern PACKAGE GUID CLASS_Doughnut;
extern PACKAGE GUID DIID_IVcPie;
extern PACKAGE GUID CLASS_Pie;
extern PACKAGE GUID DIID_IVcWeighting;
extern PACKAGE GUID CLASS_Weighting;
extern PACKAGE GUID DIID_IVcWall;
extern PACKAGE GUID CLASS_Wall;
extern PACKAGE GUID DIID_IVcSeries;
extern PACKAGE GUID CLASS_Series;
extern PACKAGE GUID DIID_IVcBar;
extern PACKAGE GUID CLASS_Bar;
extern PACKAGE GUID DIID_IVcHiLo;
extern PACKAGE GUID CLASS_HiLo;
extern PACKAGE GUID DIID_IVcPosition;
extern PACKAGE GUID CLASS_Position;
extern PACKAGE GUID DIID_IVcSeriesMarker;
extern PACKAGE GUID CLASS_SeriesMarker;
extern PACKAGE GUID DIID_IVcSeriesLabel;
extern PACKAGE GUID CLASS_SeriesLabel;
extern PACKAGE GUID DIID_IVcStatLines;
extern PACKAGE GUID CLASS_StatLine;
extern PACKAGE GUID DIID_IVcDataPointLabel;
extern PACKAGE GUID CLASS_DataPointLabel;
extern PACKAGE GUID DIID_IVcDataPoint;
extern PACKAGE GUID CLASS_DataPoint;
extern PACKAGE GUID DIID_IVcAxis;
extern PACKAGE GUID CLASS_Axis;
extern PACKAGE GUID DIID_IVcCategoryScale;
extern PACKAGE GUID CLASS_CategoryScale;
extern PACKAGE GUID DIID_IVcDateScale;
extern PACKAGE GUID CLASS_DateScale;
extern PACKAGE GUID DIID_IVcAxisGrid;
extern PACKAGE GUID CLASS_AxisGrid;
extern PACKAGE GUID DIID_IVcIntersection;
extern PACKAGE GUID CLASS_Intersection;
extern PACKAGE GUID DIID_IVcTick;
extern PACKAGE GUID CLASS_Tick;
extern PACKAGE GUID DIID_IVcScale;
extern PACKAGE GUID CLASS_AxisScale;
extern PACKAGE GUID DIID_IVcValueScale;
extern PACKAGE GUID CLASS_ValueScale;
extern PACKAGE GUID DIID_IVcAxisTitle;
extern PACKAGE GUID CLASS_AxisTitle;
extern PACKAGE GUID DIID_IVcLabel;
extern PACKAGE GUID CLASS_Label_;
extern PACKAGE GUID DIID_IVcLight;
extern PACKAGE GUID CLASS_Light;
extern PACKAGE GUID DIID_IVcElevation;
extern PACKAGE GUID CLASS_Elevation;
extern PACKAGE GUID DIID_IVcAttribute;
extern PACKAGE GUID CLASS_Attribute;
extern PACKAGE GUID DIID_IVcSurface;
extern PACKAGE GUID CLASS_Surface;
extern PACKAGE GUID DIID_IVcContour;
extern PACKAGE GUID CLASS_Contour;
extern PACKAGE GUID DIID_IVcLightSource;
extern PACKAGE GUID CLASS_LightSource;
extern PACKAGE GUID DIID_IVcSeriesCollection;
extern PACKAGE GUID CLASS_SeriesCollection;
extern PACKAGE GUID DIID_IVcDataPoints;
extern PACKAGE GUID CLASS_DataPoints;
extern PACKAGE GUID DIID_IVcLabels;
extern PACKAGE GUID CLASS_Labels;
extern PACKAGE GUID DIID_IVcXYZ;
extern PACKAGE GUID CLASS_XYZ;
extern PACKAGE GUID DIID_IVcLightSources;
extern PACKAGE GUID CLASS_LightSources;
extern PACKAGE GUID DIID_IVcAttributes;
extern PACKAGE GUID CLASS_Attributes;
extern PACKAGE GUID DIID_IVcContourGradient;
extern PACKAGE GUID CLASS_ContourGradient;
static const Shortint VtFontStyleBold = 0x1;
static const Shortint VtFontStyleItalic = 0x2;
static const Shortint VtFontStyleOutline = 0x4;
static const Word VtFontEffectStrikeThrough = 0x100;
static const Word VtFontEffectUnderline = 0x200;
static const Shortint VtFrameStyleNull = 0x0;
static const Shortint VtFrameStyleSingleLine = 0x1;
static const Shortint VtFrameStyleDoubleLine = 0x2;
static const Shortint VtFrameStyleThickInner = 0x3;
static const Shortint VtFrameStyleThickOuter = 0x4;
static const Shortint VtBrushStyleNull = 0x0;
static const Shortint VtBrushStyleSolid = 0x1;
static const Shortint VtBrushStylePattern = 0x2;
static const Shortint VtBrushStyleHatched = 0x3;
static const Shortint VtChLabelComponentValue = 0x1;
static const Shortint VtChLabelComponentPercent = 0x2;
static const Shortint VtChLabelComponentSeriesName = 0x4;
static const Shortint VtChLabelComponentPointName = 0x8;
static const Shortint VtBrushPattern94Percent = 0x0;
static const Shortint VtBrushPattern88Percent = 0x1;
static const Shortint VtBrushPattern75Percent = 0x2;
static const Shortint VtBrushPattern50Percent = 0x3;
static const Shortint VtBrushPattern25Percent = 0x4;
static const Shortint VtBrushPatternBoldHorizontal = 0x5;
static const Shortint VtBrushPatternBoldVertical = 0x6;
static const Shortint VtBrushPatternBoldDownDiagonal = 0x7;
static const Shortint VtBrushPatternBoldUpDiagonal = 0x8;
static const Shortint VtBrushPatternChecks = 0x9;
static const Shortint VtBrushPatternWeave = 0xa;
static const Shortint VtBrushPatternHorizontal = 0xb;
static const Shortint VtBrushPatternVertical = 0xc;
static const Shortint VtBrushPatternDownDiagonal = 0xd;
static const Shortint VtBrushPatternUpDiagonal = 0xe;
static const Shortint VtBrushPatternGrid = 0xf;
static const Shortint VtBrushPatternTrellis = 0x10;
static const Shortint VtBrushPatternInvertedTrellis = 0x11;
static const Shortint VtBrushHatchHorizontal = 0x0;
static const Shortint VtBrushHatchVertical = 0x1;
static const Shortint VtBrushHatchDownDiagonal = 0x2;
static const Shortint VtBrushHatchUpDiagonal = 0x3;
static const Shortint VtBrushHatchCross = 0x4;
static const Shortint VtBrushHatchDiagonalCross = 0x5;
static const Shortint VtShadowStyleNull = 0x0;
static const Shortint VtShadowStyleDrop = 0x1;
static const Shortint VtChMouseFlagShiftKeyDown = 0x4;
static const Shortint VtChMouseFlagControlKeyDown = 0x8;
static const Shortint VtPenStyleNull = 0x0;
static const Shortint VtPenStyleSolid = 0x1;
static const Shortint VtPenStyleDashed = 0x2;
static const Shortint VtPenStyleDotted = 0x3;
static const Shortint VtPenStyleDashDot = 0x4;
static const Shortint VtPenStyleDashDotDot = 0x5;
static const Shortint VtPenStyleDitted = 0x6;
static const Shortint VtPenStyleDashDit = 0x7;
static const Shortint VtPenStyleDashDitDit = 0x8;
static const Shortint VtPenJoinMiter = 0x0;
static const Shortint VtPenJoinRound = 0x1;
static const Shortint VtPenJoinBevel = 0x2;
static const Shortint VtPenCapButt = 0x0;
static const Shortint VtPenCapRound = 0x1;
static const Shortint VtPenCapSquare = 0x2;
static const Shortint VtGradientStyleHorizontal = 0x0;
static const Shortint VtGradientStyleVertical = 0x1;
static const Shortint VtGradientStyleRectangle = 0x2;
static const Shortint VtGradientStyleOval = 0x3;
static const Shortint VtPictureTypeNull = 0x0;
static const Shortint VtPictureTypeBMP = 0x1;
static const Shortint VtPictureTypeWMF = 0x2;
static const Shortint VtPictureOptionNoSizeHeader = 0x0;
static const Shortint VtPictureOptionTextAsCurves = 0x1;
static const Shortint VtPictureMapTypeActual = 0x0;
static const Shortint VtPictureMapTypeFitted = 0x1;
static const Shortint VtPictureMapTypeStretched = 0x2;
static const Shortint VtPictureMapTypeTiled = 0x3;
static const Shortint VtPictureMapTypeCropFitted = 0x4;
static const Shortint VtFillStyleNull = 0x0;
static const Shortint VtFillStyleBrush = 0x1;
static const Shortint VtFillStyleGradient = 0x2;
static const Shortint VtChLocationTypeTopLeft = 0x0;
static const Shortint VtChLocationTypeTop = 0x1;
static const Shortint VtChLocationTypeTopRight = 0x2;
static const Shortint VtChLocationTypeLeft = 0x3;
static const Shortint VtChLocationTypeRight = 0x4;
static const Shortint VtChLocationTypeBottomLeft = 0x5;
static const Shortint VtChLocationTypeBottom = 0x6;
static const Shortint VtChLocationTypeBottomRight = 0x7;
static const Shortint VtChLocationTypeCustom = 0x8;
static const Shortint VtChAxisIdX = 0x0;
static const Shortint VtChAxisIdY = 0x1;
static const Shortint VtChAxisIdY2 = 0x2;
static const Shortint VtChAxisIdZ = 0x3;
static const Shortint VtChAxisTickStyleNone = 0x0;
static const Shortint VtChAxisTickStyleCenter = 0x1;
static const Shortint VtChAxisTickStyleInside = 0x2;
static const Shortint VtChAxisTickStyleOutside = 0x3;
static const Shortint VtChDateIntervalTypeNone = 0x0;
static const Shortint VtChDateIntervalTypeDaily = 0x1;
static const Shortint VtChDateIntervalTypeWeekly = 0x2;
static const Shortint VtChDateIntervalTypeSemimonthly = 0x3;
static const Shortint VtChDateIntervalTypeMonthly = 0x4;
static const Shortint VtChDateIntervalTypeYearly = 0x5;
static const Shortint VtChScaleTypeLinear = 0x0;
static const Shortint VtChScaleTypeLogarithmic = 0x1;
static const Shortint VtChScaleTypePercent = 0x2;
static const Shortint VtChPercentAxisBasisMaxChart = 0x0;
static const Shortint VtChPercentAxisBasisMaxRow = 0x1;
static const Shortint VtChPercentAxisBasisMaxColumn = 0x2;
static const Shortint VtChPercentAxisBasisSumChart = 0x3;
static const Shortint VtChPercentAxisBasisSumRow = 0x4;
static const Shortint VtChPercentAxisBasisSumColumn = 0x5;
static const Shortint VtChPieWeightBasisNone = 0x0;
static const Shortint VtChPieWeightBasisTotal = 0x1;
static const Shortint VtChPieWeightBasisSeries = 0x2;
static const Shortint VtChPieWeightStyleArea = 0x0;
static const Shortint VtChPieWeightStyleDiameter = 0x1;
static const Shortint VtSortTypeNone = 0x0;
static const Shortint VtSortTypeAscending = 0x1;
static const Shortint VtSortTypeDescending = 0x2;
static const Shortint VtAngleUnitsDegrees = 0x0;
static const Shortint VtAngleUnitsRadians = 0x1;
static const Shortint VtAngleUnitsGrads = 0x2;
static const Shortint VtChSubPlotLabelLocationTypeNone = 0x0;
static const Shortint VtChSubPlotLabelLocationTypeAbove = 0x1;
static const Shortint VtChSubPlotLabelLocationTypeBelow = 0x2;
static const Shortint VtChSubPlotLabelLocationTypeCenter = 0x3;
static const Shortint VtChLabelLineStyleNone = 0x0;
static const Shortint VtChLabelLineStyleStraight = 0x1;
static const Shortint VtChLabelLineStyleBent = 0x2;
static const Shortint VtChLabelLocationTypeNone = 0x0;
static const Shortint VtChLabelLocationTypeAbovePoint = 0x1;
static const Shortint VtChLabelLocationTypeBelowPoint = 0x2;
static const Shortint VtChLabelLocationTypeCenter = 0x3;
static const Shortint VtChLabelLocationTypeBase = 0x4;
static const Shortint VtChLabelLocationTypeInside = 0x5;
static const Shortint VtChLabelLocationTypeOutside = 0x6;
static const Shortint VtChLabelLocationTypeLeft = 0x7;
static const Shortint VtChLabelLocationTypeRight = 0x8;
static const Shortint VtChContourColorTypeAutomatic = 0x0;
static const Shortint VtChContourColorTypeGradient = 0x1;
static const Shortint VtChContourColorTypeManual = 0x2;
static const Shortint VtChContourDisplayTypeCBands = 0x0;
static const Shortint VtChContourDisplayTypeCLines = 0x1;
static const Shortint VtChSurfaceBaseTypePedestal = 0x0;
static const Shortint VtChSurfaceBaseTypeStandard = 0x1;
static const Shortint VtChSurfaceBaseTypeStandardWithCBands = 0x2;
static const Shortint VtChSurfaceBaseTypeStandardWithCLines = 0x3;
static const Shortint VtChSurfaceDisplayTypeNone = 0x0;
static const Shortint VtChSurfaceDisplayTypeCBands = 0x1;
static const Shortint VtChSurfaceDisplayTypeCLines = 0x2;
static const Shortint VtChSurfaceDisplayTypeSolid = 0x3;
static const Shortint VtChSurfaceDisplayTypeSolidWithCLines = 0x4;
static const Shortint VtChSurfaceProjectionTypeNone = 0x0;
static const Shortint VtChSurfaceProjectionTypeCBands = 0x1;
static const Shortint VtChSurfaceProjectionTypeCLines = 0x2;
static const Shortint VtChSurfaceWireframeTypeNone = 0x0;
static const Shortint VtChSurfaceWireframeTypeMajor = 0x1;
static const Shortint VtChSurfaceWireframeTypeMajorAndMinor = 0x2;
static const Shortint VtMarkerStyleDash = 0x0;
static const Shortint VtMarkerStylePlus = 0x1;
static const Shortint VtMarkerStyleX = 0x2;
static const Shortint VtMarkerStyleStar = 0x3;
static const Shortint VtMarkerStyleCircle = 0x4;
static const Shortint VtMarkerStyleSquare = 0x5;
static const Shortint VtMarkerStyleDiamond = 0x6;
static const Shortint VtMarkerStyleUpTriangle = 0x7;
static const Shortint VtMarkerStyleDownTriangle = 0x8;
static const Shortint VtMarkerStyleFilledCircle = 0x9;
static const Shortint VtMarkerStyleFilledSquare = 0xa;
static const Shortint VtMarkerStyleFilledDiamond = 0xb;
static const Shortint VtMarkerStyleFilledUpTriangle = 0xc;
static const Shortint VtMarkerStyleFilledDownTriangle = 0xd;
static const Shortint VtMarkerStyle3dBall = 0xe;
static const Shortint VtProjectionTypePerspective = 0x0;
static const Shortint VtProjectionTypeOblique = 0x1;
static const Shortint VtProjectionTypeOrthogonal = 0x2;
static const Shortint VtSmoothingTypeNone = 0x0;
static const Shortint VtSmoothingTypeQuadraticBSpline = 0x1;
static const Shortint VtSmoothingTypeCubicBSpline = 0x2;
static const Shortint VtHorizontalAlignmentLeft = 0x0;
static const Shortint VtHorizontalAlignmentRight = 0x1;
static const Shortint VtHorizontalAlignmentCenter = 0x2;
static const Shortint VtVerticalAlignmentTop = 0x0;
static const Shortint VtVerticalAlignmentBottom = 0x1;
static const Shortint VtVerticalAlignmentCenter = 0x2;
static const Shortint VtOrientationHorizontal = 0x0;
static const Shortint VtOrientationVertical = 0x1;
static const Shortint VtOrientationUp = 0x2;
static const Shortint VtOrientationDown = 0x3;
static const Shortint VtDcTypeNull = 0x0;
static const Shortint VtDcTypeDisplay = 0x1;
static const Shortint VtDcTypePrinter = 0x2;
static const Shortint VtDcTypeMetafile = 0x3;
static const Shortint VtPrintScaleTypeActual = 0x0;
static const Shortint VtPrintScaleTypeFitted = 0x1;
static const Shortint VtPrintScaleTypeStretched = 0x2;
static const Shortint VtChStatsMinimum = 0x1;
static const Shortint VtChStatsMaximum = 0x2;
static const Shortint VtChStatsMean = 0x4;
static const Shortint VtChStatsStddev = 0x8;
static const Shortint VtChStatsRegression = 0x10;
static const Shortint VtPrintOrientationPortrait = 0x0;
static const Shortint VtPrintOrientationLandscape = 0x1;
static const Shortint VtTextOutputTypeHardware = 0x0;
static const Shortint VtTextOutputTypePolygon = 0x1;
static const Shortint VtTextLengthTypeVirtual = 0x0;
static const Shortint VtTextLengthTypeDevice = 0x1;
static const Shortint VtChPartTypeChart = 0x0;
static const Shortint VtChPartTypeTitle = 0x1;
static const Shortint VtChPartTypeFootnote = 0x2;
static const Shortint VtChPartTypeLegend = 0x3;
static const Shortint VtChPartTypePlot = 0x4;
static const Shortint VtChPartTypeSeries = 0x5;
static const Shortint VtChPartTypeSeriesLabel = 0x6;
static const Shortint VtChPartTypePoint = 0x7;
static const Shortint VtChPartTypePointLabel = 0x8;
static const Shortint VtChPartTypeAxis = 0x9;
static const Shortint VtChPartTypeAxisLabel = 0xa;
static const Shortint VtChPartTypeAxisTitle = 0xb;
static const Shortint VtChDrawModeDraw = 0x0;
static const Shortint VtChDrawModeBlit = 0x1;
static const Shortint VtChSsLinkModeOff = 0x0;
static const Shortint VtChSsLinkModeOn = 0x1;
static const Shortint VtChSsLinkModeAutoParse = 0x2;
static const unsigned VtChSeriesTypeDefault = 0xffffffff;
static const Shortint VtChSeriesType3dBar = 0x0;
static const Shortint VtChSeriesType2dBar = 0x1;
static const Shortint VtChSeriesType3dHorizontalBar = 0x2;
static const Shortint VtChSeriesType2dHorizontalBar = 0x3;
static const Shortint VtChSeriesType3dClusteredBar = 0x4;
static const Shortint VtChSeriesType3dLine = 0x5;
static const Shortint VtChSeriesType2dLine = 0x6;
static const Shortint VtChSeriesType3dArea = 0x7;
static const Shortint VtChSeriesType2dArea = 0x8;
static const Shortint VtChSeriesType3dStep = 0x9;
static const Shortint VtChSeriesType2dStep = 0xa;
static const Shortint VtChSeriesType2dXY = 0xb;
static const Shortint VtChSeriesType2dPolar = 0xc;
static const Shortint VtChSeriesType2dRadarLine = 0xd;
static const Shortint VtChSeriesType2dRadarArea = 0xe;
static const Shortint VtChSeriesType2dBubble = 0xf;
static const Shortint VtChSeriesType2dHiLo = 0x10;
static const Shortint VtChSeriesType2dHLC = 0x11;
static const Shortint VtChSeriesType2dHLCRight = 0x12;
static const Shortint VtChSeriesType2dOHLC = 0x13;
static const Shortint VtChSeriesType2dOHLCBar = 0x14;
static const Shortint VtChSeriesType2dGantt = 0x15;
static const Shortint VtChSeriesType3dGantt = 0x16;
static const Shortint VtChSeriesType3dPie = 0x17;
static const Shortint VtChSeriesType2dPie = 0x18;
static const Shortint VtChSeriesType3dDoughnut = 0x19;
static const Shortint VtChSeriesType2dDates = 0x1a;
static const Shortint VtChSeriesType3dBarHiLo = 0x1b;
static const Shortint VtChSeriesType2dBarHiLo = 0x1c;
static const Shortint VtChSeriesType3dHorizontalBarHiLo = 0x1d;
static const Shortint VtChSeriesType2dHorizontalBarHiLo = 0x1e;
static const Shortint VtChSeriesType3dClusteredBarHiLo = 0x1f;
static const Shortint VtChSeriesType3dSurface = 0x20;
static const Shortint VtChSeriesType2dContour = 0x21;
static const Shortint VtChSeriesType3dXYZ = 0x22;
static const Shortint VtChChartType3dBar = 0x0;
static const Shortint VtChChartType2dBar = 0x1;
static const Shortint VtChChartType3dLine = 0x2;
static const Shortint VtChChartType2dLine = 0x3;
static const Shortint VtChChartType3dArea = 0x4;
static const Shortint VtChChartType2dArea = 0x5;
static const Shortint VtChChartType3dStep = 0x6;
static const Shortint VtChChartType2dStep = 0x7;
static const Shortint VtChChartType3dCombination = 0x8;
static const Shortint VtChChartType2dCombination = 0x9;
static const Shortint VtChChartType3dHorizontalBar = 0xa;
static const Shortint VtChChartType2dHorizontalBar = 0xb;
static const Shortint VtChChartType3dClusteredBar = 0xc;
static const Shortint VtChChartType3dPie = 0xd;
static const Shortint VtChChartType2dPie = 0xe;
static const Shortint VtChChartType3dDoughnut = 0xf;
static const Shortint VtChChartType2dXY = 0x10;
static const Shortint VtChChartType2dPolar = 0x11;
static const Shortint VtChChartType2dRadar = 0x12;
static const Shortint VtChChartType2dBubble = 0x13;
static const Shortint VtChChartType2dHiLo = 0x14;
static const Shortint VtChChartType2dGantt = 0x15;
static const Shortint VtChChartType3dGantt = 0x16;
static const Shortint VtChChartType3dSurface = 0x17;
static const Shortint VtChChartType2dContour = 0x18;
static const Shortint VtChChartType3dScatter = 0x19;
static const Shortint VtChChartType3dXYZ = 0x1a;
extern PACKAGE void __fastcall Register(void);

}	/* namespace Vcfi */
#if !defined(NO_IMPLICIT_NAMESPACE_USE)
using namespace Vcfi;
#endif
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// vcfi
