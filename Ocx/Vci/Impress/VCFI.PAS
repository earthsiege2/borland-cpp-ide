unit vcfi;

{ This file contains pascal declarations imported from a type library.
  This file will be written during each import or refresh of the type
  library editor.  Changes to this file will be discarded during the
  refresh process. }

{ VCI First Impression Library }
{ Version 1.0 }

{ Conversion log:
  Warning: 'Label' is a reserved word. Label changed to Label_
  Warning: 'Array' is a reserved word. Parameter 'Array' in _DVtChart.CopyDataFromArray changed to 'Array_'
  Warning: 'Array' is a reserved word. Parameter 'Array' in _DVtChart.CopyDataToArray changed to 'Array_'
  Warning: 'Set' is a reserved word. ICoor.Set changed to Set_
  Warning: 'Set' is a reserved word. ILCoor.Set changed to Set_
  Warning: 'Set' is a reserved word. ICoor3.Set changed to Set_
  Warning: 'Set' is a reserved word. IColor.Set changed to Set_
  Warning: 'Type' is a reserved word. IPicture.Type changed to Type_
  Warning: 'Set' is a reserved word. IVcView3d.Set changed to Set_
  Warning: 'Set' is a reserved word. IVcDoughnut.Set changed to Set_
  Warning: 'Set' is a reserved word. IVcPie.Set changed to Set_
  Warning: 'Set' is a reserved word. IVcWeighting.Set changed to Set_
  Warning: 'Type' is a reserved word. Parameter 'Type' in IVcStatLines.Style changed to 'Type_'
  Warning: 'Type' is a reserved word. IVcScale.Type changed to Type_
  Warning: 'Set' is a reserved word. IVcLightSource.Set changed to Set_
 }

interface

uses Windows, ActiveX, Classes, Graphics, OleCtrls, StdVCL;

const
  LIBID_VCIFiLib: TGUID = '{5A721583-5AF0-11CE-8384-0020AF2337F2}';

const

{ The list of VtFont styles }

{ FontStyleConstants }

  VtFontStyleBold = 1;
  VtFontStyleItalic = 2;
  VtFontStyleOutline = 4;

{ The list of VtFont effects }

{ FontEffectsConstants }

  VtFontEffectStrikeThrough = 256;
  VtFontEffectUnderline = 512;

{ Frame Styles }

{ FrameStyleConstants }

  VtFrameStyleNull = 0;
  VtFrameStyleSingleLine = 1;
  VtFrameStyleDoubleLine = 2;
  VtFrameStyleThickInner = 3;
  VtFrameStyleThickOuter = 4;

{ Brush Styles }

{ BrushStyleConstants }

  VtBrushStyleNull = 0;
  VtBrushStyleSolid = 1;
  VtBrushStylePattern = 2;
  VtBrushStyleHatched = 3;

{ The list of datapoint label component types }

{ LabelComponentConstants }

  VtChLabelComponentValue = 1;
  VtChLabelComponentPercent = 2;
  VtChLabelComponentSeriesName = 4;
  VtChLabelComponentPointName = 8;

{ Brush Patterns }

{ BrushPatternConstants }

  VtBrushPattern94Percent = 0;
  VtBrushPattern88Percent = 1;
  VtBrushPattern75Percent = 2;
  VtBrushPattern50Percent = 3;
  VtBrushPattern25Percent = 4;
  VtBrushPatternBoldHorizontal = 5;
  VtBrushPatternBoldVertical = 6;
  VtBrushPatternBoldDownDiagonal = 7;
  VtBrushPatternBoldUpDiagonal = 8;
  VtBrushPatternChecks = 9;
  VtBrushPatternWeave = 10;
  VtBrushPatternHorizontal = 11;
  VtBrushPatternVertical = 12;
  VtBrushPatternDownDiagonal = 13;
  VtBrushPatternUpDiagonal = 14;
  VtBrushPatternGrid = 15;
  VtBrushPatternTrellis = 16;
  VtBrushPatternInvertedTrellis = 17;

{ Brush Hatches }

{ BrushHatchConstants }

  VtBrushHatchHorizontal = 0;
  VtBrushHatchVertical = 1;
  VtBrushHatchDownDiagonal = 2;
  VtBrushHatchUpDiagonal = 3;
  VtBrushHatchCross = 4;
  VtBrushHatchDiagonalCross = 5;

{ Shadow Styles }

{ ShadowStyleConstants }

  VtShadowStyleNull = 0;
  VtShadowStyleDrop = 1;

{ Mouse Flag Constants }

{ MouseFlagConstants }

  VtChMouseFlagShiftKeyDown = 4;
  VtChMouseFlagControlKeyDown = 8;

{ Pen Styles }

{ PenStyleConstants }

  VtPenStyleNull = 0;
  VtPenStyleSolid = 1;
  VtPenStyleDashed = 2;
  VtPenStyleDotted = 3;
  VtPenStyleDashDot = 4;
  VtPenStyleDashDotDot = 5;
  VtPenStyleDitted = 6;
  VtPenStyleDashDit = 7;
  VtPenStyleDashDitDit = 8;

{ Pen Join types }

{ PenJoinConstants }

  VtPenJoinMiter = 0;
  VtPenJoinRound = 1;
  VtPenJoinBevel = 2;

{ Pen Cap types }

{ PenCapConstants }

  VtPenCapButt = 0;
  VtPenCapRound = 1;
  VtPenCapSquare = 2;

{ Gradient Styles }

{ GradientStyleConstants }

  VtGradientStyleHorizontal = 0;
  VtGradientStyleVertical = 1;
  VtGradientStyleRectangle = 2;
  VtGradientStyleOval = 3;

{ Picture Types }

{ PictureTypeConstants }

  VtPictureTypeNull = 0;
  VtPictureTypeBMP = 1;
  VtPictureTypeWMF = 2;

{ Picture Options (WMF only) }

{ PictureOptionConstants }

  VtPictureOptionNoSizeHeader = 0;
  VtPictureOptionTextAsCurves = 1;

{ Picture Map Types }

{ PictureMapTypeConstants }

  VtPictureMapTypeActual = 0;
  VtPictureMapTypeFitted = 1;
  VtPictureMapTypeStretched = 2;
  VtPictureMapTypeTiled = 3;
  VtPictureMapTypeCropFitted = 4;

{ Fill Style Constants }

{ FillStyleConstants }

  VtFillStyleNull = 0;
  VtFillStyleBrush = 1;
  VtFillStyleGradient = 2;

{ Chart Element Location Type Constants }

{ LocationTypeConstants }

  VtChLocationTypeTopLeft = 0;
  VtChLocationTypeTop = 1;
  VtChLocationTypeTopRight = 2;
  VtChLocationTypeLeft = 3;
  VtChLocationTypeRight = 4;
  VtChLocationTypeBottomLeft = 5;
  VtChLocationTypeBottom = 6;
  VtChLocationTypeBottomRight = 7;
  VtChLocationTypeCustom = 8;

{ Axis Id Constants }

{ AxisIdConstants }

  VtChAxisIdX = 0;
  VtChAxisIdY = 1;
  VtChAxisIdY2 = 2;
  VtChAxisIdZ = 3;

{ Axis Tick Style Constants }

{ AxisTickStyleConstants }

  VtChAxisTickStyleNone = 0;
  VtChAxisTickStyleCenter = 1;
  VtChAxisTickStyleInside = 2;
  VtChAxisTickStyleOutside = 3;

{ Date Interval Constants }

{ DateIntervalTypeConstants }

  VtChDateIntervalTypeNone = 0;
  VtChDateIntervalTypeDaily = 1;
  VtChDateIntervalTypeWeekly = 2;
  VtChDateIntervalTypeSemimonthly = 3;
  VtChDateIntervalTypeMonthly = 4;
  VtChDateIntervalTypeYearly = 5;

{ Scale Type Constants }

{ ScaleTypeConstants }

  VtChScaleTypeLinear = 0;
  VtChScaleTypeLogarithmic = 1;
  VtChScaleTypePercent = 2;

{ Percent Axis Basis Constants }

{ PercentAxisBasisConstants }

  VtChPercentAxisBasisMaxChart = 0;
  VtChPercentAxisBasisMaxRow = 1;
  VtChPercentAxisBasisMaxColumn = 2;
  VtChPercentAxisBasisSumChart = 3;
  VtChPercentAxisBasisSumRow = 4;
  VtChPercentAxisBasisSumColumn = 5;

{ Pie Weight Basis Constants }

{ PieWeightBasisConstants }

  VtChPieWeightBasisNone = 0;
  VtChPieWeightBasisTotal = 1;
  VtChPieWeightBasisSeries = 2;

{ Pie Weight Style Constants }

{ PieWeightStyleConstants }

  VtChPieWeightStyleArea = 0;
  VtChPieWeightStyleDiameter = 1;

{ Sort Type Constants }

{ SortTypeConstants }

  VtSortTypeNone = 0;
  VtSortTypeAscending = 1;
  VtSortTypeDescending = 2;

{ Angle Units Constants }

{ AngleUnitsConstants }

  VtAngleUnitsDegrees = 0;
  VtAngleUnitsRadians = 1;
  VtAngleUnitsGrads = 2;

{ Sub Plot Label Location Type Constants }

{ SubPlotLabelLocationTypeConstants }

  VtChSubPlotLabelLocationTypeNone = 0;
  VtChSubPlotLabelLocationTypeAbove = 1;
  VtChSubPlotLabelLocationTypeBelow = 2;
  VtChSubPlotLabelLocationTypeCenter = 3;

{ The list of series/datapoint label line styles }

{ LabelLineStyleConstants }

  VtChLabelLineStyleNone = 0;
  VtChLabelLineStyleStraight = 1;
  VtChLabelLineStyleBent = 2;

{ The list of series/datapoint label locations }

{ LabelLocationTypeConstants }

  VtChLabelLocationTypeNone = 0;
  VtChLabelLocationTypeAbovePoint = 1;
  VtChLabelLocationTypeBelowPoint = 2;
  VtChLabelLocationTypeCenter = 3;
  VtChLabelLocationTypeBase = 4;
  VtChLabelLocationTypeInside = 5;
  VtChLabelLocationTypeOutside = 6;
  VtChLabelLocationTypeLeft = 7;
  VtChLabelLocationTypeRight = 8;

{ Contour VtColor Type Constants }

{ ContourColorTypeConstants }

  VtChContourColorTypeAutomatic = 0;
  VtChContourColorTypeGradient = 1;
  VtChContourColorTypeManual = 2;

{ Contour Display Type Constants }

{ ContourDisplayTypeConstants }

  VtChContourDisplayTypeCBands = 0;
  VtChContourDisplayTypeCLines = 1;

{ Surface Base Type Constants }

{ SurfaceBaseTypeConstants }

  VtChSurfaceBaseTypePedestal = 0;
  VtChSurfaceBaseTypeStandard = 1;
  VtChSurfaceBaseTypeStandardWithCBands = 2;
  VtChSurfaceBaseTypeStandardWithCLines = 3;

{ Surface Display Type Constants }

{ SurfaceDisplayTypeConstants }

  VtChSurfaceDisplayTypeNone = 0;
  VtChSurfaceDisplayTypeCBands = 1;
  VtChSurfaceDisplayTypeCLines = 2;
  VtChSurfaceDisplayTypeSolid = 3;
  VtChSurfaceDisplayTypeSolidWithCLines = 4;

{ Surface Projection Type Constants }

{ SurfaceProjectionTypeConstants }

  VtChSurfaceProjectionTypeNone = 0;
  VtChSurfaceProjectionTypeCBands = 1;
  VtChSurfaceProjectionTypeCLines = 2;

{ Surface Wireframe Type Constants }

{ SurfaceWireframeTypeConstants }

  VtChSurfaceWireframeTypeNone = 0;
  VtChSurfaceWireframeTypeMajor = 1;
  VtChSurfaceWireframeTypeMajorAndMinor = 2;

{ Marker Style Constants }

{ MarkerStyleConstants }

  VtMarkerStyleDash = 0;
  VtMarkerStylePlus = 1;
  VtMarkerStyleX = 2;
  VtMarkerStyleStar = 3;
  VtMarkerStyleCircle = 4;
  VtMarkerStyleSquare = 5;
  VtMarkerStyleDiamond = 6;
  VtMarkerStyleUpTriangle = 7;
  VtMarkerStyleDownTriangle = 8;
  VtMarkerStyleFilledCircle = 9;
  VtMarkerStyleFilledSquare = 10;
  VtMarkerStyleFilledDiamond = 11;
  VtMarkerStyleFilledUpTriangle = 12;
  VtMarkerStyleFilledDownTriangle = 13;
  VtMarkerStyle3dBall = 14;

{ Projection Type Constants }

{ ProjectionTypeConstants }

  VtProjectionTypePerspective = 0;
  VtProjectionTypeOblique = 1;
  VtProjectionTypeOrthogonal = 2;

{ Smoothing Type Constants }

{ SmoothingTypeConstants }

  VtSmoothingTypeNone = 0;
  VtSmoothingTypeQuadraticBSpline = 1;
  VtSmoothingTypeCubicBSpline = 2;

{ Horizontal Alignment Constants }

{ HorizontalAlignmentConstants }

  VtHorizontalAlignmentLeft = 0;
  VtHorizontalAlignmentRight = 1;
  VtHorizontalAlignmentCenter = 2;

{ Vertical Alignment Constants }

{ VerticalAlignmentConstants }

  VtVerticalAlignmentTop = 0;
  VtVerticalAlignmentBottom = 1;
  VtVerticalAlignmentCenter = 2;

{ Orientation Constants }

{ OrientationConstants }

  VtOrientationHorizontal = 0;
  VtOrientationVertical = 1;
  VtOrientationUp = 2;
  VtOrientationDown = 3;

{ Device Context Type Constants }

{ DcTypeConstants }

  VtDcTypeNull = 0;
  VtDcTypeDisplay = 1;
  VtDcTypePrinter = 2;
  VtDcTypeMetafile = 3;

{ Print Scale Type Constants }

{ PrintScaleTypeConstants }

  VtPrintScaleTypeActual = 0;
  VtPrintScaleTypeFitted = 1;
  VtPrintScaleTypeStretched = 2;

{ Stat Type Constants }

{ StatTypeConstants }

  VtChStatsMinimum = 1;
  VtChStatsMaximum = 2;
  VtChStatsMean = 4;
  VtChStatsStddev = 8;
  VtChStatsRegression = 16;

{ Print Orientation Type Constants }

{ PrintOrientationTypeConstants }

  VtPrintOrientationPortrait = 0;
  VtPrintOrientationLandscape = 1;

{ 2D Text output Type Constants }

{ TextOutputTypeConstants }

  VtTextOutputTypeHardware = 0;
  VtTextOutputTypePolygon = 1;

{ Text Length Type Constants }

{ TextLengthTypeConstants }

  VtTextLengthTypeVirtual = 0;
  VtTextLengthTypeDevice = 1;

{ Chart Part Type Constants }

{ PartTypeConstants }

  VtChPartTypeChart = 0;
  VtChPartTypeTitle = 1;
  VtChPartTypeFootnote = 2;
  VtChPartTypeLegend = 3;
  VtChPartTypePlot = 4;
  VtChPartTypeSeries = 5;
  VtChPartTypeSeriesLabel = 6;
  VtChPartTypePoint = 7;
  VtChPartTypePointLabel = 8;
  VtChPartTypeAxis = 9;
  VtChPartTypeAxisLabel = 10;
  VtChPartTypeAxisTitle = 11;

{ The list of Draw modes }

{ DrawModeConstants }

  VtChDrawModeDraw = 0;
  VtChDrawModeBlit = 1;

{ The list of Formula One spreadsheet link modes }

{ SsLinkModeConstants }

  VtChSsLinkModeOff = 0;
  VtChSsLinkModeOn = 1;
  VtChSsLinkModeAutoParse = 2;

{ The list of Series types }

{ SeriesTypeConstants }

  VtChSeriesTypeDefault = -1;
  VtChSeriesType3dBar = 0;
  VtChSeriesType2dBar = 1;
  VtChSeriesType3dHorizontalBar = 2;
  VtChSeriesType2dHorizontalBar = 3;
  VtChSeriesType3dClusteredBar = 4;
  VtChSeriesType3dLine = 5;
  VtChSeriesType2dLine = 6;
  VtChSeriesType3dArea = 7;
  VtChSeriesType2dArea = 8;
  VtChSeriesType3dStep = 9;
  VtChSeriesType2dStep = 10;
  VtChSeriesType2dXY = 11;
  VtChSeriesType2dPolar = 12;
  VtChSeriesType2dRadarLine = 13;
  VtChSeriesType2dRadarArea = 14;
  VtChSeriesType2dBubble = 15;
  VtChSeriesType2dHiLo = 16;
  VtChSeriesType2dHLC = 17;
  VtChSeriesType2dHLCRight = 18;
  VtChSeriesType2dOHLC = 19;
  VtChSeriesType2dOHLCBar = 20;
  VtChSeriesType2dGantt = 21;
  VtChSeriesType3dGantt = 22;
  VtChSeriesType3dPie = 23;
  VtChSeriesType2dPie = 24;
  VtChSeriesType3dDoughnut = 25;
  VtChSeriesType2dDates = 26;
  VtChSeriesType3dBarHiLo = 27;
  VtChSeriesType2dBarHiLo = 28;
  VtChSeriesType3dHorizontalBarHiLo = 29;
  VtChSeriesType2dHorizontalBarHiLo = 30;
  VtChSeriesType3dClusteredBarHiLo = 31;
  VtChSeriesType3dSurface = 32;
  VtChSeriesType2dContour = 33;
  VtChSeriesType3dXYZ = 34;

{ The list of Chart types }

{ ChartTypeConstants }

  VtChChartType3dBar = 0;
  VtChChartType2dBar = 1;
  VtChChartType3dLine = 2;
  VtChChartType2dLine = 3;
  VtChChartType3dArea = 4;
  VtChChartType2dArea = 5;
  VtChChartType3dStep = 6;
  VtChChartType2dStep = 7;
  VtChChartType3dCombination = 8;
  VtChChartType2dCombination = 9;
  VtChChartType3dHorizontalBar = 10;
  VtChChartType2dHorizontalBar = 11;
  VtChChartType3dClusteredBar = 12;
  VtChChartType3dPie = 13;
  VtChChartType2dPie = 14;
  VtChChartType3dDoughnut = 15;
  VtChChartType2dXY = 16;
  VtChChartType2dPolar = 17;
  VtChChartType2dRadar = 18;
  VtChChartType2dBubble = 19;
  VtChChartType2dHiLo = 20;
  VtChChartType2dGantt = 21;
  VtChChartType3dGantt = 22;
  VtChChartType3dSurface = 23;
  VtChChartType2dContour = 24;
  VtChChartType3dScatter = 25;
  VtChChartType3dXYZ = 26;

const

{ Component class GUIDs }
  Class_VtChart: TGUID = '{5A721580-5AF0-11CE-8384-0020AF2337F2}';
  Class_Coor: TGUID = '{EBF97E21-731F-11CE-840F-00AA0042CB33}';
  Class_LCoor: TGUID = '{EBF97E23-731F-11CE-840F-00AA0042CB33}';
  Class_Coor3: TGUID = '{177BF2A1-7350-11CE-840F-00AA0042CB33}';
  Class_LRect: TGUID = '{177BF2A3-7350-11CE-840F-00AA0042CB33}';
  Class_Rect: TGUID = '{FE5517C1-73FE-11CE-840F-00AA0042CB33}';
  Class_VtColor: TGUID = '{9BA79C61-7403-11CE-840F-00AA0042CB33}';
  Class_Brush: TGUID = '{AFE57021-7409-11CE-840F-00AA0042CB33}';
  Class_Shadow: TGUID = '{AFE57023-7409-11CE-840F-00AA0042CB33}';
  Class_TextLayout: TGUID = '{E26C7701-756C-11CE-840F-00AA0042CB33}';
  Class_Title: TGUID = '{C82141A1-7571-11CE-840F-00AA0042CB33}';
  Class_Location: TGUID = '{EDDF9243-764B-11CE-840F-00AA0042CB33}';
  Class_VtFont: TGUID = '{2E6A37A1-77FC-11CE-840F-00AA0042CB33}';
  Class_Backdrop: TGUID = '{2E6A37A3-77FC-11CE-840F-00AA0042CB33}';
  Class_Frame: TGUID = '{2E6A37A5-77FC-11CE-840F-00AA0042CB33}';
  Class_Gradient: TGUID = '{2E6A37A7-77FC-11CE-840F-00AA0042CB33}';
  Class_VtPicture: TGUID = '{FD30FB01-789C-11CE-840F-00AA0042CB33}';
  Class_Fill: TGUID = '{FD30FB03-789C-11CE-840F-00AA0042CB33}';
  Class_Pen: TGUID = '{279B5A41-8098-11CE-BECC-00AA0042CB33}';
  Class_Marker: TGUID = '{3080E743-813F-11CE-BECC-00AA0042CB33}';
  Class_Footnote: TGUID = '{4F053F01-8396-11CE-BECC-00AA0042CB33}';
  Class_Legend: TGUID = '{95C52B61-83B1-11CE-BECC-00AA0042CB33}';
  Class_PrintInformation: TGUID = '{CFA0AC01-8B6E-11CE-840F-00AA0042CB33}';
  Class_DataGrid: TGUID = '{6CB603A1-8F70-11CE-840F-00AA0042CB33}';
  Class_Plot: TGUID = '{F77BA681-9037-11CE-86B3-444553540000}';
  Class_View3d: TGUID = '{21645F63-90F0-11CE-86B3-444553540000}';
  Class_PlotBase: TGUID = '{508D02E1-90FC-11CE-86B3-444553540000}';
  Class_Doughnut: TGUID = '{508D02E3-90FC-11CE-86B3-444553540000}';
  Class_Pie: TGUID = '{508D02E5-90FC-11CE-86B3-444553540000}';
  Class_Weighting: TGUID = '{508D02E7-90FC-11CE-86B3-444553540000}';
  Class_Wall: TGUID = '{508D02E9-90FC-11CE-86B3-444553540000}';
  Class_Series: TGUID = '{0AA0FE21-912A-11CE-86B3-444553540000}';
  Class_Bar: TGUID = '{264931C1-91F1-11CE-840F-00AA0042CB33}';
  Class_HiLo: TGUID = '{51DCC621-95B7-11CE-86B3-444553540000}';
  Class_Position: TGUID = '{51DCC623-95B7-11CE-86B3-444553540000}';
  Class_SeriesMarker: TGUID = '{51DCC625-95B7-11CE-86B3-444553540000}';
  Class_SeriesLabel: TGUID = '{51DCC627-95B7-11CE-86B3-444553540000}';
  Class_StatLine: TGUID = '{2F6DD6A1-95E5-11CE-86B3-444553540000}';
  Class_DataPointLabel: TGUID = '{2F6DD6A3-95E5-11CE-86B3-444553540000}';
  Class_DataPoint: TGUID = '{2F6DD6A5-95E5-11CE-86B3-444553540000}';
  Class_Axis: TGUID = '{027D7901-A023-11CE-840F-00AA0042CB33}';
  Class_CategoryScale: TGUID = '{62375361-A17D-11CE-840F-00AA0042CB33}';
  Class_DateScale: TGUID = '{62375363-A17D-11CE-840F-00AA0042CB33}';
  Class_AxisGrid: TGUID = '{62375365-A17D-11CE-840F-00AA0042CB33}';
  Class_Intersection: TGUID = '{62375367-A17D-11CE-840F-00AA0042CB33}';
  Class_Tick: TGUID = '{62375369-A17D-11CE-840F-00AA0042CB33}';
  Class_AxisScale: TGUID = '{6237536B-A17D-11CE-840F-00AA0042CB33}';
  Class_ValueScale: TGUID = '{6237536D-A17D-11CE-840F-00AA0042CB33}';
  Class_AxisTitle: TGUID = '{6237536F-A17D-11CE-840F-00AA0042CB33}';
  Class_Label_: TGUID = '{62375371-A17D-11CE-840F-00AA0042CB33}';
  Class_Light: TGUID = '{B54A6421-A25E-11CE-840F-00AA0042CB33}';
  Class_Elevation: TGUID = '{A71FB701-A732-11CE-840F-00AA0042CB33}';
  Class_Attribute: TGUID = '{A71FB703-A732-11CE-840F-00AA0042CB33}';
  Class_Surface: TGUID = '{A71FB705-A732-11CE-840F-00AA0042CB33}';
  Class_Contour: TGUID = '{A71FB707-A732-11CE-840F-00AA0042CB33}';
  Class_LightSource: TGUID = '{CD9EFA61-AA40-11CE-840F-00AA0042CB33}';
  Class_SeriesCollection: TGUID = '{C14E8B61-AE2B-11CE-840F-00AA0042CB33}';
  Class_DataPoints: TGUID = '{C20E5261-B06F-11CE-840F-00AA0042CB33}';
  Class_Labels: TGUID = '{62B9A401-B93D-11CE-8410-00AA0042CB33}';
  Class_XYZ: TGUID = '{7D001801-BC65-11CE-8410-00AA0042CB33}';
  Class_LightSources: TGUID = '{6FE35CC1-CE50-11CE-8410-00AA0042CB33}';
  Class_Attributes: TGUID = '{5A693221-CFEF-11CE-8410-00AA0042CB33}';
  Class_ContourGradient: TGUID = '{69032721-D303-11CE-8410-00AA0042CB33}';

type

{ Forward declarations }
{ Forward declarations: Interfaces }
  _DVtChart = dispinterface;
  _DVtChartEvents = dispinterface;
  ICoor = dispinterface;
  ILCoor = dispinterface;
  ICoor3 = dispinterface;
  ILRect = dispinterface;
  IRect = dispinterface;
  IColor = dispinterface;
  IBrush = dispinterface;
  IShadow = dispinterface;
  ITextLayout = dispinterface;
  IVcTitle = dispinterface;
  ILocation = dispinterface;
  IFont = dispinterface;
  IBackdrop = dispinterface;
  IFrame = dispinterface;
  IGradient = dispinterface;
  IPicture = dispinterface;
  IFill = dispinterface;
  IVcPen = dispinterface;
  IVcMarker = dispinterface;
  IVcFootnote = dispinterface;
  IVcLegend = dispinterface;
  IVcPrintInformation = dispinterface;
  IVcDataGrid = dispinterface;
  IVcPlot = dispinterface;
  IVcView3d = dispinterface;
  IVcPlotBase = dispinterface;
  IVcDoughnut = dispinterface;
  IVcPie = dispinterface;
  IVcWeighting = dispinterface;
  IVcWall = dispinterface;
  IVcSeries = dispinterface;
  IVcBar = dispinterface;
  IVcHiLo = dispinterface;
  IVcPosition = dispinterface;
  IVcSeriesMarker = dispinterface;
  IVcSeriesLabel = dispinterface;
  IVcStatLines = dispinterface;
  IVcDataPointLabel = dispinterface;
  IVcDataPoint = dispinterface;
  IVcAxis = dispinterface;
  IVcCategoryScale = dispinterface;
  IVcDateScale = dispinterface;
  IVcAxisGrid = dispinterface;
  IVcIntersection = dispinterface;
  IVcTick = dispinterface;
  IVcScale = dispinterface;
  IVcValueScale = dispinterface;
  IVcAxisTitle = dispinterface;
  IVcLabel = dispinterface;
  IVcLight = dispinterface;
  IVcElevation = dispinterface;
  IVcAttribute = dispinterface;
  IVcSurface = dispinterface;
  IVcContour = dispinterface;
  IVcLightSource = dispinterface;
  IVcSeriesCollection = dispinterface;
  IVcDataPoints = dispinterface;
  IVcLabels = dispinterface;
  IVcXYZ = dispinterface;
  IVcLightSources = dispinterface;
  IVcAttributes = dispinterface;
  IVcContourGradient = dispinterface;

{ Forward declarations: CoClasses }
  VtChart = _DVtChart;
  Coor = ICoor;
  LCoor = ILCoor;
  Coor3 = ICoor3;
  LRect = ILRect;
  Rect = IRect;
  VtColor = IColor;
  Brush = IBrush;
  Shadow = IShadow;
  TextLayout = ITextLayout;
  Title = IVcTitle;
  Location = ILocation;
  VtFont = IFont;
  Backdrop = IBackdrop;
  Frame = IFrame;
  Gradient = IGradient;
  VtPicture = IPicture;
  Fill = IFill;
  Pen = IVcPen;
  Marker = IVcMarker;
  Footnote = IVcFootnote;
  Legend = IVcLegend;
  PrintInformation = IVcPrintInformation;
  DataGrid = IVcDataGrid;
  Plot = IVcPlot;
  View3d = IVcView3d;
  PlotBase = IVcPlotBase;
  Doughnut = IVcDoughnut;
  Pie = IVcPie;
  Weighting = IVcWeighting;
  Wall = IVcWall;
  Series = IVcSeries;
  Bar = IVcBar;
  HiLo = IVcHiLo;
  Position = IVcPosition;
  SeriesMarker = IVcSeriesMarker;
  SeriesLabel = IVcSeriesLabel;
  StatLine = IVcStatLines;
  DataPointLabel = IVcDataPointLabel;
  DataPoint = IVcDataPoint;
  Axis = IVcAxis;
  CategoryScale = IVcCategoryScale;
  DateScale = IVcDateScale;
  AxisGrid = IVcAxisGrid;
  Intersection = IVcIntersection;
  Tick = IVcTick;
  AxisScale = IVcScale;
  ValueScale = IVcValueScale;
  AxisTitle = IVcAxisTitle;
  Label_ = IVcLabel;
  Light = IVcLight;
  Elevation = IVcElevation;
  Attribute = IVcAttribute;
  Surface = IVcSurface;
  Contour = IVcContour;
  LightSource = IVcLightSource;
  SeriesCollection = IVcSeriesCollection;
  DataPoints = IVcDataPoints;
  Labels = IVcLabels;
  XYZ = IVcXYZ;
  LightSources = IVcLightSources;
  Attributes = IVcAttributes;
  ContourGradient = IVcContourGradient;

{ Forward declarations: Enums }
  FontStyleConstants = TOleEnum;
  FontEffectsConstants = TOleEnum;
  FrameStyleConstants = TOleEnum;
  BrushStyleConstants = TOleEnum;
  LabelComponentConstants = TOleEnum;
  BrushPatternConstants = TOleEnum;
  BrushHatchConstants = TOleEnum;
  ShadowStyleConstants = TOleEnum;
  MouseFlagConstants = TOleEnum;
  PenStyleConstants = TOleEnum;
  PenJoinConstants = TOleEnum;
  PenCapConstants = TOleEnum;
  GradientStyleConstants = TOleEnum;
  PictureTypeConstants = TOleEnum;
  PictureOptionConstants = TOleEnum;
  PictureMapTypeConstants = TOleEnum;
  FillStyleConstants = TOleEnum;
  LocationTypeConstants = TOleEnum;
  AxisIdConstants = TOleEnum;
  AxisTickStyleConstants = TOleEnum;
  DateIntervalTypeConstants = TOleEnum;
  ScaleTypeConstants = TOleEnum;
  PercentAxisBasisConstants = TOleEnum;
  PieWeightBasisConstants = TOleEnum;
  PieWeightStyleConstants = TOleEnum;
  SortTypeConstants = TOleEnum;
  AngleUnitsConstants = TOleEnum;
  SubPlotLabelLocationTypeConstants = TOleEnum;
  LabelLineStyleConstants = TOleEnum;
  LabelLocationTypeConstants = TOleEnum;
  ContourColorTypeConstants = TOleEnum;
  ContourDisplayTypeConstants = TOleEnum;
  SurfaceBaseTypeConstants = TOleEnum;
  SurfaceDisplayTypeConstants = TOleEnum;
  SurfaceProjectionTypeConstants = TOleEnum;
  SurfaceWireframeTypeConstants = TOleEnum;
  MarkerStyleConstants = TOleEnum;
  ProjectionTypeConstants = TOleEnum;
  SmoothingTypeConstants = TOleEnum;
  HorizontalAlignmentConstants = TOleEnum;
  VerticalAlignmentConstants = TOleEnum;
  OrientationConstants = TOleEnum;
  DcTypeConstants = TOleEnum;
  PrintScaleTypeConstants = TOleEnum;
  StatTypeConstants = TOleEnum;
  PrintOrientationTypeConstants = TOleEnum;
  TextOutputTypeConstants = TOleEnum;
  TextLengthTypeConstants = TOleEnum;
  PartTypeConstants = TOleEnum;
  DrawModeConstants = TOleEnum;
  SsLinkModeConstants = TOleEnum;
  SeriesTypeConstants = TOleEnum;
  ChartTypeConstants = TOleEnum;

{ Interface for VtChart Control }

  _DVtChart = dispinterface
    ['{5A721581-5AF0-11CE-8384-0020AF2337F2}']
    property AutoIncrement: WordBool dispid 1;
    property RandomFill: WordBool dispid 2;
    property ChartType: Smallint dispid 3;
    property Column: Smallint dispid 4;
    property ColumnCount: Smallint dispid 5;
    property ColumnLabel: WideString dispid 6;
    property ColumnLabelCount: Smallint dispid 7;
    property ColumnLabelIndex: Smallint dispid 8;
    property Data: WideString dispid 9;
    property FootnoteText: WideString dispid 10;
    property Repaint: WordBool dispid 11;
    property Row: Smallint dispid 12;
    property RowCount: Smallint dispid 13;
    property RowLabel: WideString dispid 14;
    property RowLabelCount: Smallint dispid 15;
    property RowLabelIndex: Smallint dispid 16;
    property SeriesColumn: Smallint dispid 17;
    property SeriesType: Smallint dispid 18;
    property ShowLegend: WordBool dispid 19;
    property SsLinkMode: Smallint dispid 20;
    property SsLinkRange: WideString dispid 21;
    property SsLinkSheet: WideString dispid 22;
    property DrawMode: Smallint dispid 23;
    property BorderStyle: Smallint dispid -504;
    property Enabled: WordBool dispid -514;
    property hWnd: Smallint dispid -515;
    property Handle: Integer readonly dispid 24;
    property Picture: IPictureDisp readonly dispid 25;
    property Title: IDispatch dispid 26;
    property Footnote: IDispatch dispid 27;
    property TitleText: WideString dispid 28;
    property Stacking: WordBool dispid 29;
    property TextLengthType: Smallint dispid 30;
    property AllowUserChanges: WordBool dispid 31;
    property AllowSelections: WordBool dispid 32;
    property AllowSeriesSelection: WordBool dispid 33;
    property AllowDynamicRotation: WordBool dispid 34;
    property ActiveSeriesCount: Smallint dispid 35;
    property Backdrop: IDispatch dispid 36;
    property PrintInformation: IDispatch dispid 37;
    property Legend: IDispatch dispid 38;
    property DataGrid: IDispatch dispid 39;
    property Plot: IDispatch dispid 40;
    property TwipsWidth: Integer dispid 41;
    property TwipsHeight: Integer dispid 42;
    property AllowDithering: WordBool dispid 43;
    property ErrorOffset: Smallint dispid 44;
    property DoSetCursor: WordBool dispid 45;
    property FileName: WideString dispid 46;
    property Chart3d: WordBool dispid 47;
    property SsLinkBook: WideString dispid 48;
    procedure EditPaste; dispid 49;
    procedure EditCopy; dispid 50;
    procedure ActivateSelectionDialog; dispid 51;
    procedure Layout; dispid 52;
    procedure ToDefaults; dispid 53;
    procedure PrintSetupDialog; dispid 54;
    procedure PrintChart; dispid 55;
    procedure SelectPart(part, index1, index2, index3, index4: Smallint); dispid 56;
    procedure GetSelectedPart(var part, index1, index2, index3, index4: Smallint); dispid 57;
    procedure GetDLLVersion(var major, minor: Smallint); dispid 58;
    procedure TwipsToChartPart(xVal, yVal: Integer; var part, index1, index2, index3, index4: Smallint); dispid 59;
    procedure ReadFromFile(const FileName: WideString); dispid 60;
    procedure WritePictureToFile(const FileName: WideString; pictureType, options: Smallint); dispid 61;
    procedure WriteToFile(const FileName: WideString); dispid 62;
    procedure ActivateFormatMenu(X, Y: Integer); dispid 63;
    procedure GetMetafile(options: Smallint; var Handle: OLE_HANDLE; var Width, Height: Integer); dispid 64;
    procedure CopyDataFromArray(Top, Left, Bottom, Right: Smallint; Array_: OleVariant); dispid 65;
    procedure CopyDataToArray(Top, Left, Bottom, Right: Smallint; Array_: OleVariant); dispid 66;
    procedure Draw(hDC: OLE_HANDLE; hDCType: Smallint; Top, Left, Bottom, Right: Integer; Layout, Stretch: WordBool); dispid 67;
    property GetBitmap[options: OleVariant]: OLE_HANDLE readonly dispid 70;
    procedure UseWizard; dispid 68;
    procedure EditChartData; dispid 69;
    procedure Refresh; dispid -550;
    procedure AboutBox; dispid -552;
  end;

{ Event interface for Vtchart Control }

  _DVtChartEvents = dispinterface
    ['{5A721582-5AF0-11CE-8384-0020AF2337F2}']
    procedure ChartSelected(var MouseFlags, Cancel: Smallint); dispid 1;
    procedure TitleSelected(var MouseFlags, Cancel: Smallint); dispid 2;
    procedure FootnoteSelected(var MouseFlags, Cancel: Smallint); dispid 3;
    procedure LegendSelected(var MouseFlags, Cancel: Smallint); dispid 4;
    procedure PlotSelected(var MouseFlags, Cancel: Smallint); dispid 5;
    procedure AxisSelected(var AxisId, AxisIndex, MouseFlags, Cancel: Smallint); dispid 6;
    procedure AxisLabelSelected(var AxisId, AxisIndex, labelSetIndex, LabelIndex, MouseFlags, Cancel: Smallint); dispid 7;
    procedure AxisTitleSelected(var AxisId, AxisIndex, MouseFlags, Cancel: Smallint); dispid 8;
    procedure PointSelected(var Series, DataPoint, MouseFlags, Cancel: Smallint); dispid 9;
    procedure PointLabelSelected(var Series, DataPoint, MouseFlags, Cancel: Smallint); dispid 10;
    procedure SeriesSelected(var Series, MouseFlags, Cancel: Smallint); dispid 11;
    procedure SeriesLabelSelected(var Series, MouseFlags, Cancel: Smallint); dispid 12;
    procedure ChartActivated(var MouseFlags, Cancel: Smallint); dispid 13;
    procedure TitleActivated(var MouseFlags, Cancel: Smallint); dispid 14;
    procedure FootnoteActivated(var MouseFlags, Cancel: Smallint); dispid 15;
    procedure LegendActivated(var MouseFlags, Cancel: Smallint); dispid 16;
    procedure PlotActivated(var MouseFlags, Cancel: Smallint); dispid 17;
    procedure AxisActivated(var AxisId, AxisIndex, MouseFlags, Cancel: Smallint); dispid 18;
    procedure AxisLabelActivated(var AxisId, AxisIndex, labelSetIndex, LabelIndex, MouseFlags, Cancel: Smallint); dispid 19;
    procedure AxisTitleActivated(var AxisId, AxisIndex, MouseFlags, Cancel: Smallint); dispid 20;
    procedure PointActivated(var Series, DataPoint, MouseFlags, Cancel: Smallint); dispid 21;
    procedure PointLabelActivated(var Series, DataPoint, MouseFlags, Cancel: Smallint); dispid 22;
    procedure SeriesActivated(var Series, MouseFlags, Cancel: Smallint); dispid 23;
    procedure SeriesLabelActivated(var Series, MouseFlags, Cancel: Smallint); dispid 24;
    procedure Click; dispid -600;
    procedure DblClick; dispid -601;
    procedure KeyDown(var KeyCode: Smallint; Shift: Smallint); dispid -602;
    procedure KeyPress(var KeyAscii: Smallint); dispid -603;
    procedure KeyUp(var KeyCode: Smallint; Shift: Smallint); dispid -604;
    procedure MouseDown(Button, Shift: Smallint; X: OLE_XPOS_PIXELS; Y: OLE_YPOS_PIXELS); dispid -605;
    procedure MouseMove(Button, Shift: Smallint; X: OLE_XPOS_PIXELS; Y: OLE_YPOS_PIXELS); dispid -606;
    procedure MouseUp(Button, Shift: Smallint; X: OLE_XPOS_PIXELS; Y: OLE_YPOS_PIXELS); dispid -607;
    procedure ApplyChanges; dispid 25;
  end;

{ Coor object }

  ICoor = dispinterface
    ['{EBF97E20-731F-11CE-840F-00AA0042CB33}']
    property X: Single dispid 1;
    property Y: Single dispid 2;
    procedure Set_(X, Y: Single); dispid 3;
  end;

{ LCoor object }

  ILCoor = dispinterface
    ['{EBF97E22-731F-11CE-840F-00AA0042CB33}']
    property X: Integer dispid 1;
    property Y: Integer dispid 2;
    procedure Set_(X, Y: Integer); dispid 3;
  end;

{ Coor3 object }

  ICoor3 = dispinterface
    ['{177BF2A0-7350-11CE-840F-00AA0042CB33}']
    property X: Single dispid 1;
    property Y: Single dispid 2;
    property Z: Single dispid 3;
    procedure Set_(X, Y, Z: Single); dispid 4;
  end;

{ LRect object }

  ILRect = dispinterface
    ['{177BF2A2-7350-11CE-840F-00AA0042CB33}']
    property Min: IDispatch dispid 1;
    property Max: IDispatch dispid 2;
  end;

{ Rect object }

  IRect = dispinterface
    ['{FE5517C0-73FE-11CE-840F-00AA0042CB33}']
    property Min: IDispatch dispid 1;
    property Max: IDispatch dispid 2;
  end;

{ VtColor object }

  IColor = dispinterface
    ['{9BA79C60-7403-11CE-840F-00AA0042CB33}']
    property Red: Smallint dispid 1;
    property Green: Smallint dispid 2;
    property Blue: Smallint dispid 3;
    property Automatic: WordBool dispid 4;
    procedure Set_(Red, Green, Blue: Smallint); dispid 5;
  end;

{ Brush object }

  IBrush = dispinterface
    ['{AFE57020-7409-11CE-840F-00AA0042CB33}']
    property Style: Smallint dispid 1;
    property FillColor: IDispatch dispid 2;
    property PatternColor: IDispatch dispid 3;
    property Index: Smallint dispid 4;
  end;

{ Shadow object }

  IShadow = dispinterface
    ['{AFE57022-7409-11CE-840F-00AA0042CB33}']
    property Style: Smallint dispid 1;
    property Brush: IDispatch dispid 2;
    property Offset: IDispatch dispid 3;
  end;

{ TextLayout object }

  ITextLayout = dispinterface
    ['{E26C7700-756C-11CE-840F-00AA0042CB33}']
    property HorzAlignment: Smallint dispid 1;
    property VertAlignment: Smallint dispid 2;
    property Orientation: Smallint dispid 3;
    property WordWrap: WordBool dispid 4;
  end;

{ Title object }

  IVcTitle = dispinterface
    ['{C82141A0-7571-11CE-840F-00AA0042CB33}']
    property TextLayout: IDispatch dispid 1;
    property Text: WideString dispid 2;
    property _Text: WideString dispid 0;
    property Location: IDispatch dispid 3;
    property Backdrop: IDispatch dispid 4;
    property VtFont: IDispatch dispid 5;
    property TextLength: Smallint dispid 6;
    procedure Select; dispid 7;
  end;

{ Location object }

  ILocation = dispinterface
    ['{EDDF9242-764B-11CE-840F-00AA0042CB33}']
    property Rect: IDispatch dispid 1;
    property Visible: WordBool dispid 2;
    property LocationType: Smallint dispid 3;
  end;

{ VtFont object }

  IFont = dispinterface
    ['{2E6A37A0-77FC-11CE-840F-00AA0042CB33}']
    property Name: WideString dispid 1;
    property Size: Single dispid 2;
    property Style: Smallint dispid 3;
    property Effect: Smallint dispid 4;
    property VtColor: IDispatch dispid 5;
  end;

{ Backdrop object }

  IBackdrop = dispinterface
    ['{2E6A37A2-77FC-11CE-840F-00AA0042CB33}']
    property Shadow: IDispatch dispid 1;
    property Frame: IDispatch dispid 2;
    property Fill: IDispatch dispid 3;
  end;

{ Frame object }

  IFrame = dispinterface
    ['{2E6A37A4-77FC-11CE-840F-00AA0042CB33}']
    property Style: Smallint dispid 1;
    property FrameColor: IDispatch dispid 2;
    property SpaceColor: IDispatch dispid 3;
    property Width: Single dispid 4;
  end;

{ Gradient object }

  IGradient = dispinterface
    ['{2E6A37A6-77FC-11CE-840F-00AA0042CB33}']
    property Style: Smallint dispid 1;
    property FromColor: IDispatch dispid 2;
    property ToColor: IDispatch dispid 3;
  end;

{ VtPicture object }

  IPicture = dispinterface
    ['{FD30FB00-789C-11CE-840F-00AA0042CB33}']
    property Type_: Smallint dispid 1;
    property Map: Smallint dispid 2;
    property Embedded: WordBool dispid 3;
    property FileName: WideString dispid 4;
  end;

{ Fill object }

  IFill = dispinterface
    ['{FD30FB02-789C-11CE-840F-00AA0042CB33}']
    property Style: Smallint dispid 1;
    property Brush: IDispatch dispid 2;
    property Gradient: IDispatch dispid 3;
    property VtPicture: IDispatch dispid 4;
  end;

{ Pen object }

  IVcPen = dispinterface
    ['{279B5A40-8098-11CE-BECC-00AA0042CB33}']
    property Style: Smallint dispid 1;
    property Join: Smallint dispid 2;
    property Cap: Smallint dispid 3;
    property VtColor: IDispatch dispid 4;
    property Width: Single dispid 5;
    property Limit: Single dispid 6;
  end;

{ Marker object }

  IVcMarker = dispinterface
    ['{3080E742-813F-11CE-BECC-00AA0042CB33}']
    property Visible: WordBool dispid 1;
    property Style: Smallint dispid 2;
    property Pen: IDispatch dispid 3;
    property Size: Single dispid 4;
    property FillColor: IDispatch dispid 5;
    property VtPicture: IDispatch dispid 6;
  end;

{ Footnote object }

  IVcFootnote = dispinterface
    ['{4F053F00-8396-11CE-BECC-00AA0042CB33}']
    property TextLayout: IDispatch dispid 1;
    property Location: IDispatch dispid 2;
    property Backdrop: IDispatch dispid 3;
    property VtFont: IDispatch dispid 4;
    property Text: WideString dispid 5;
    property _Text: WideString dispid 0;
    property TextLength: Smallint dispid 6;
    procedure Select; dispid 7;
  end;

{ Legend object }

  IVcLegend = dispinterface
    ['{95C52B60-83B1-11CE-BECC-00AA0042CB33}']
    property Location: IDispatch dispid 1;
    property Backdrop: IDispatch dispid 2;
    property VtFont: IDispatch dispid 3;
    property TextLayout: IDispatch dispid 4;
    procedure Select; dispid 5;
  end;

{ PrintInformation object }

  IVcPrintInformation = dispinterface
    ['{CFA0AC00-8B6E-11CE-840F-00AA0042CB33}']
    property ScaleType: Smallint dispid 1;
    property Orientation: Smallint dispid 2;
    property TopMargin: Single dispid 3;
    property BottomMargin: Single dispid 4;
    property LeftMargin: Single dispid 5;
    property RightMargin: Single dispid 6;
    property CenterHorizontally: WordBool dispid 7;
    property CenterVertically: WordBool dispid 8;
    property Monochrome: WordBool dispid 9;
    property LayoutForPrinter: WordBool dispid 10;
    procedure PrintCopies(NumberCopies: Smallint); dispid 11;
  end;

{ DataGrid object }

  IVcDataGrid = dispinterface
    ['{6CB603A0-8F70-11CE-840F-00AA0042CB33}']
    property ColumnCount: Smallint dispid 1;
    property ColumnLabelCount: Smallint dispid 2;
    property RowLabelCount: Smallint dispid 3;
    property RowCount: Smallint dispid 4;
    procedure DeleteColumns(Column, Count: Smallint); dispid 5;
    procedure InsertColumns(Column, Count: Smallint); dispid 6;
    procedure DeleteColumnLabels(LabelIndex, Count: Smallint); dispid 7;
    procedure InsertColumnLabels(LabelIndex, Count: Smallint); dispid 8;
    procedure DeleteRows(Row, Count: Smallint); dispid 9;
    procedure InsertRows(Row, Count: Smallint); dispid 10;
    procedure DeleteRowLabels(LabelIndex, Count: Smallint); dispid 11;
    procedure InsertRowLabels(LabelIndex, Count: Smallint); dispid 12;
    procedure RandomDataFill; dispid 13;
    procedure SetSize(RowLabelCount, ColumnLabelCount, DataRowCount, DataColumnCount: Smallint); dispid 14;
    procedure InitializeLabels; dispid 15;
    property ColumnLabel[Column, LabelIndex: Smallint]: WideString dispid 21;
    property CompositeColumnLabel[Column: Smallint]: WideString readonly dispid 22;
    property CompositeRowLabel[Row: Smallint]: WideString readonly dispid 23;
    property RowLabel[Row, LabelIndex: Smallint]: WideString dispid 24;
    procedure RandomFillColumns(Column, Count: Smallint); dispid 16;
    procedure RandomFillRows(Row, Count: Smallint); dispid 17;
    procedure MoveData(Top, Left, Bottom, Right, OverOffset, DownOffset: Smallint); dispid 18;
    procedure GetData(Row, Column: Smallint; var DataPoint: Double; var nullFlag: Smallint); dispid 19;
    procedure SetData(Row, Column: Smallint; DataPoint: Double; nullFlag: Smallint); dispid 20;
  end;

{ Plot object }

  IVcPlot = dispinterface
    ['{F77BA680-9037-11CE-86B3-444553540000}']
    property AngleUnit: Smallint dispid 1;
    property Clockwise: WordBool dispid 2;
    property Sort: Smallint dispid 3;
    property MaxBubbleToAxisRatio: Single dispid 4;
    property Backdrop: IDispatch dispid 5;
    property Perspective: IDispatch dispid 6;
    property ScaleAngle: Single dispid 7;
    property StartingAngle: Single dispid 8;
    property SubPlotLabelPosition: Smallint dispid 9;
    property BarGap: Single dispid 10;
    property xGap: Single dispid 11;
    property AutoLayout: WordBool dispid 12;
    property WidthToHeightRatio: Single dispid 13;
    property DepthToHeightRatio: Single dispid 14;
    property LocationRect: IDispatch dispid 15;
    property Projection: Smallint dispid 16;
    property zGap: Single dispid 17;
    property View3d: IDispatch dispid 18;
    property PlotBase: IDispatch dispid 19;
    property Doughnut: IDispatch dispid 20;
    property Pie: IDispatch dispid 21;
    property Weighting: IDispatch dispid 22;
    property Wall: IDispatch dispid 23;
    property Elevation: IDispatch dispid 24;
    property SeriesCollection: IDispatch dispid 25;
    property DataSeriesInRow: WordBool dispid 26;
    property Light: IDispatch dispid 27;
    property XYZ: IDispatch dispid 28;
    property DefaultPercentBasis: Smallint dispid 29;
    property UniformAxis: WordBool dispid 30;
    property Axis[AxisId: Smallint; Index: OleVariant]: IDispatch readonly dispid 31;
  end;

{ View3d object }

  IVcView3d = dispinterface
    ['{21645F62-90F0-11CE-86B3-444553540000}']
    property Rotation: Single dispid 1;
    property Elevation: Single dispid 2;
    procedure Set_(Rotation, Elevation: Single); dispid 4;
  end;

{ PlotBase object }

  IVcPlotBase = dispinterface
    ['{508D02E0-90FC-11CE-86B3-444553540000}']
    property BaseHeight: Single dispid 1;
    property Brush: IDispatch dispid 2;
    property Pen: IDispatch dispid 3;
  end;

{ Doughnut object }

  IVcDoughnut = dispinterface
    ['{508D02E2-90FC-11CE-86B3-444553540000}']
    property Sides: Smallint dispid 1;
    property InteriorRatio: Single dispid 2;
    procedure Set_(InteriorRatio: Single; Sides: Smallint); dispid 3;
  end;

{ Pie object }

  IVcPie = dispinterface
    ['{508D02E4-90FC-11CE-86B3-444553540000}']
    property ThicknessRatio: Single dispid 1;
    property TopRadiusRatio: Single dispid 2;
    procedure Set_(ThicknessRatio, TopRadiusRation: Single); dispid 3;
  end;

{ Weighting object }

  IVcWeighting = dispinterface
    ['{508D02E6-90FC-11CE-86B3-444553540000}']
    property Basis: Smallint dispid 1;
    property Style: Smallint dispid 2;
    procedure Set_(Basis, Style: Smallint); dispid 3;
  end;

{ Wall object }

  IVcWall = dispinterface
    ['{508D02E8-90FC-11CE-86B3-444553540000}']
    property Width: Single dispid 1;
    property Brush: IDispatch dispid 2;
    property Pen: IDispatch dispid 3;
  end;

{ Series object }

  IVcSeries = dispinterface
    ['{0AA0FE20-912A-11CE-86B3-444553540000}']
    property SecondaryAxis: WordBool dispid 1;
    property SmoothingType: Smallint dispid 2;
    property SmoothingFactor: Smallint dispid 3;
    property SeriesType: Smallint dispid 4;
    property GuideLinePen: IDispatch dispid 5;
    property ShowLine: WordBool dispid 6;
    property Pen: IDispatch dispid 7;
    property Bar: IDispatch dispid 8;
    property HiLo: IDispatch dispid 9;
    property Position: IDispatch dispid 10;
    property SeriesMarker: IDispatch dispid 11;
    property SeriesLabel: IDispatch dispid 12;
    property StatLine: IDispatch dispid 13;
    property DataPoints: IDispatch dispid 14;
    property LegendText: WideString dispid 15;
    property _LegendText: WideString dispid 0;
    property ShowGuideLine[AxisId: Smallint]: WordBool dispid 17;
    procedure Select; dispid 16;
    property TypeByChartType[ChartType: Smallint]: Smallint readonly dispid 18;
  end;

{ Bar object }

  IVcBar = dispinterface
    ['{264931C0-91F1-11CE-840F-00AA0042CB33}']
    property Sides: Smallint dispid 1;
    property TopRatio: Single dispid 2;
  end;

{ HiLo object }

  IVcHiLo = dispinterface
    ['{51DCC620-95B7-11CE-86B3-444553540000}']
    property GainColor: IDispatch dispid 1;
    property LossColor: IDispatch dispid 2;
  end;

{ Position object }

  IVcPosition = dispinterface
    ['{51DCC622-95B7-11CE-86B3-444553540000}']
    property Excluded: WordBool dispid 1;
    property Hidden: WordBool dispid 2;
    property Order: Smallint dispid 3;
    property StackOrder: Smallint dispid 4;
  end;

{ SeriesMarker object }

  IVcSeriesMarker = dispinterface
    ['{51DCC624-95B7-11CE-86B3-444553540000}']
    property Auto: WordBool dispid 1;
    property Show: WordBool dispid 2;
  end;

{ SeriesLabel object }

  IVcSeriesLabel = dispinterface
    ['{51DCC626-95B7-11CE-86B3-444553540000}']
    property Text: WideString dispid 1;
    property _Text: WideString dispid 0;
    property LocationType: Smallint dispid 2;
    property LineStyle: Smallint dispid 3;
    property Offset: IDispatch dispid 4;
    property Backdrop: IDispatch dispid 5;
    property VtFont: IDispatch dispid 6;
    property TextLayout: IDispatch dispid 7;
    property TextLength: Smallint dispid 8;
  end;

{ StatLine object }

  IVcStatLines = dispinterface
    ['{2F6DD6A0-95E5-11CE-86B3-444553540000}']
    property Flag: Smallint dispid 1;
    property VtColor: IDispatch dispid 2;
    property Width: Single dispid 3;
    property Style[Type_: Smallint]: Smallint dispid 4;
  end;

{ DataPointLabel object }

  IVcDataPointLabel = dispinterface
    ['{2F6DD6A2-95E5-11CE-86B3-444553540000}']
    property Text: WideString dispid 1;
    property _Text: WideString dispid 0;
    property Backdrop: IDispatch dispid 2;
    property VtFont: IDispatch dispid 3;
    property Offset: IDispatch dispid 4;
    property TextLayout: IDispatch dispid 5;
    property LocationType: Smallint dispid 6;
    property Custom: WordBool dispid 7;
    property Component: Smallint dispid 8;
    property LineStyle: Smallint dispid 9;
    property ValueFormat: WideString dispid 10;
    property PercentFormat: WideString dispid 11;
    property TextLength: Smallint dispid 12;
    procedure ResetCustomLabel; dispid 13;
    procedure Select; dispid 14;
  end;

{ DataPoint object }

  IVcDataPoint = dispinterface
    ['{2F6DD6A4-95E5-11CE-86B3-444553540000}']
    property DataPointLabel: IDispatch dispid 1;
    property Brush: IDispatch dispid 2;
    property EdgePen: IDispatch dispid 3;
    property Marker: IDispatch dispid 4;
    property Offset: Single dispid 5;
    property VtPicture: IDispatch dispid 6;
    procedure ResetCustom; dispid 7;
    procedure Select; dispid 8;
  end;

{ Axis(axisId, 1) object }

  IVcAxis = dispinterface
    ['{027D7900-A023-11CE-840F-00AA0042CB33}']
    property Pen: IDispatch dispid 1;
    property LabelLevelCount: Smallint dispid 2;
    property CategoryScale: IDispatch dispid 3;
    property DateScale: IDispatch dispid 4;
    property AxisGrid: IDispatch dispid 5;
    property Intersection: IDispatch dispid 6;
    property Tick: IDispatch dispid 7;
    property AxisScale: IDispatch dispid 8;
    property ValueScale: IDispatch dispid 9;
    property AxisTitle: IDispatch dispid 10;
    property Labels: IDispatch dispid 11;
  end;

{ CategoryScale object }

  IVcCategoryScale = dispinterface
    ['{62375360-A17D-11CE-840F-00AA0042CB33}']
    property Auto: WordBool dispid 1;
    property DivisionsPerLabel: Smallint dispid 2;
    property DivisionsPerTick: Smallint dispid 3;
    property LabelTick: WordBool dispid 4;
  end;

{ DateScale object }

  IVcDateScale = dispinterface
    ['{62375362-A17D-11CE-840F-00AA0042CB33}']
    property Auto: WordBool dispid 1;
    property Minimum: Double dispid 2;
    property Maximum: Double dispid 3;
    property MajInt: Smallint dispid 4;
    property MajFreq: Smallint dispid 5;
    property MinInt: Smallint dispid 6;
    property MinFreq: Smallint dispid 7;
    property SkipWeekend: WordBool dispid 8;
  end;

{ AxisGrid object }

  IVcAxisGrid = dispinterface
    ['{62375364-A17D-11CE-840F-00AA0042CB33}']
    property MinorPen: IDispatch dispid 1;
    property MajorPen: IDispatch dispid 2;
  end;

{ Intersection object }

  IVcIntersection = dispinterface
    ['{62375366-A17D-11CE-840F-00AA0042CB33}']
    property Auto: WordBool dispid 1;
    property Point: Double dispid 2;
    property AxisId: Smallint dispid 3;
    property Index: Smallint dispid 4;
    property LabelsInsidePlot: WordBool dispid 5;
  end;

{ Tick object }

  IVcTick = dispinterface
    ['{62375368-A17D-11CE-840F-00AA0042CB33}']
    property Length: Single dispid 1;
    property Style: Smallint dispid 2;
  end;

{ AxisScale object }

  IVcScale = dispinterface
    ['{6237536A-A17D-11CE-840F-00AA0042CB33}']
    property Hide: WordBool dispid 1;
    property Type_: Smallint dispid 2;
    property LogBase: Smallint dispid 3;
    property PercentBasis: Smallint dispid 4;
  end;

{ ValueScale object }

  IVcValueScale = dispinterface
    ['{6237536C-A17D-11CE-840F-00AA0042CB33}']
    property Auto: WordBool dispid 1;
    property Minimum: Double dispid 2;
    property Maximum: Double dispid 3;
    property MajorDivision: Smallint dispid 4;
    property MinorDivision: Smallint dispid 5;
  end;

{ AxisTitle object }

  IVcAxisTitle = dispinterface
    ['{6237536E-A17D-11CE-840F-00AA0042CB33}']
    property Text: WideString dispid 1;
    property _Text: WideString dispid 0;
    property Backdrop: IDispatch dispid 2;
    property VtFont: IDispatch dispid 3;
    property Visible: WordBool dispid 4;
    property TextLayout: IDispatch dispid 5;
    property TextLength: Smallint dispid 6;
  end;

{ Label object }

  IVcLabel = dispinterface
    ['{62375370-A17D-11CE-840F-00AA0042CB33}']
    property Backdrop: IDispatch dispid 1;
    property Format: WideString dispid 2;
    property VtFont: IDispatch dispid 3;
    property Auto: WordBool dispid 4;
    property Standing: WordBool dispid 5;
    property TextLayout: IDispatch dispid 6;
    property FormatLength: Smallint dispid 7;
  end;

{ Light object }

  IVcLight = dispinterface
    ['{B54A6420-A25E-11CE-840F-00AA0042CB33}']
    property AmbientIntensity: Single dispid 1;
    property EdgeIntensity: Single dispid 2;
    property EdgeVisible: WordBool dispid 3;
    property LightSources: IDispatch dispid 4;
  end;

{ Elevation object }

  IVcElevation = dispinterface
    ['{A71FB700-A732-11CE-840F-00AA0042CB33}']
    property ColorType: Smallint dispid 1;
    property RowSmoothing: Smallint dispid 2;
    property ColSmoothing: Smallint dispid 3;
    property Surface: IDispatch dispid 4;
    property AutoValues: WordBool dispid 5;
    property SeparateContourData: WordBool dispid 6;
    property Contour: IDispatch dispid 7;
    property Attributes: IDispatch dispid 8;
    property ContourGradient: IDispatch dispid 9;
  end;

{ Attribute object }

  IVcAttribute = dispinterface
    ['{A71FB702-A732-11CE-840F-00AA0042CB33}']
    property Value: Double dispid 1;
    property Brush: IDispatch dispid 2;
    property Pen: IDispatch dispid 3;
    property Text: WideString dispid 4;
    property _Text: WideString dispid 0;
  end;

{ Surface object }

  IVcSurface = dispinterface
    ['{A71FB704-A732-11CE-840F-00AA0042CB33}']
    property Brush: IDispatch dispid 1;
    property WireframePen: IDispatch dispid 2;
    property Projection: Smallint dispid 3;
    property DisplayType: Smallint dispid 4;
    property RowWireframe: Smallint dispid 5;
    property ColWireframe: Smallint dispid 6;
    property Base: Smallint dispid 7;
  end;

{ Contour object }

  IVcContour = dispinterface
    ['{A71FB706-A732-11CE-840F-00AA0042CB33}']
    property DisplayType: Smallint dispid 1;
  end;

{ LightSource object }

  IVcLightSource = dispinterface
    ['{CD9EFA60-AA40-11CE-840F-00AA0042CB33}']
    property Intensity: Single dispid 1;
    property X: Single dispid 2;
    property Y: Single dispid 3;
    property Z: Single dispid 4;
    property _Intensity: Single dispid 0;
    procedure Set_(X, Y, Z, Intensity: Single); dispid 5;
  end;

{ SeriesCollection Collection }

  IVcSeriesCollection = dispinterface
    ['{C14E8B60-AE2B-11CE-840F-00AA0042CB33}']
    property Count: Integer dispid 1;
    property Item[Index: Smallint]: IDispatch readonly dispid 2;
  end;

{ DataPoints Collection }

  IVcDataPoints = dispinterface
    ['{C20E5260-B06F-11CE-840F-00AA0042CB33}']
    property Count: Integer dispid 1;
    property Item[DataPoint: Smallint]: IDispatch readonly dispid 2;
    property _Item[DataPoint: Smallint]: IDispatch readonly dispid 0;
  end;

{ Labels Collection }

  IVcLabels = dispinterface
    ['{62B9A400-B93D-11CE-8410-00AA0042CB33}']
    property Count: Integer dispid 1;
    property Item[LabelIndex: Smallint]: IDispatch readonly dispid 2;
    property _Item[LabelIndex: Smallint]: IDispatch readonly dispid 0;
  end;

{ XYZ Object }

  IVcXYZ = dispinterface
    ['{7D001800-BC65-11CE-8410-00AA0042CB33}']
    property xIntersection: Double dispid 1;
    property yIntersection: Double dispid 2;
    property zIntersection: Double dispid 3;
    property Automatic: WordBool dispid 4;
  end;

{ LightSources Collection }

  IVcLightSources = dispinterface
    ['{6FE35CC0-CE50-11CE-8410-00AA0042CB33}']
    property Count: Integer dispid 1;
    property Item[Index: Smallint]: IDispatch readonly dispid 4;
    function Add(X, Y, Z, Intensity: Single): IDispatch; dispid 2;
    procedure Remove(Index: Smallint); dispid 3;
  end;

{ Contour Attributes Collection }

  IVcAttributes = dispinterface
    ['{5A693220-CFEF-11CE-8410-00AA0042CB33}']
    property Count: Smallint dispid 1;
    property Item[Index: Smallint]: IDispatch readonly dispid 4;
    property _Item[Index: Smallint]: IDispatch readonly dispid 0;
    function Add(Value: Double): IDispatch; dispid 2;
    procedure Remove(Index: Smallint); dispid 3;
  end;

{ Contour gradient from/to attributes object }

  IVcContourGradient = dispinterface
    ['{69032720-D303-11CE-8410-00AA0042CB33}']
    property FromBrushColor: IDispatch dispid 1;
    property ToBrushColor: IDispatch dispid 2;
    property FromPenColor: IDispatch dispid 3;
    property ToPenColor: IDispatch dispid 4;
  end;

{ VCI First Impression Chart }

  TVtChartChartSelected = procedure(Sender: TObject; var MouseFlags, Cancel: Smallint) of object;
  TVtChartTitleSelected = procedure(Sender: TObject; var MouseFlags, Cancel: Smallint) of object;
  TVtChartFootnoteSelected = procedure(Sender: TObject; var MouseFlags, Cancel: Smallint) of object;
  TVtChartLegendSelected = procedure(Sender: TObject; var MouseFlags, Cancel: Smallint) of object;
  TVtChartPlotSelected = procedure(Sender: TObject; var MouseFlags, Cancel: Smallint) of object;
  TVtChartAxisSelected = procedure(Sender: TObject; var AxisId, AxisIndex, MouseFlags, Cancel: Smallint) of object;
  TVtChartAxisLabelSelected = procedure(Sender: TObject; var AxisId, AxisIndex, labelSetIndex, LabelIndex, MouseFlags, Cancel: Smallint) of object;
  TVtChartAxisTitleSelected = procedure(Sender: TObject; var AxisId, AxisIndex, MouseFlags, Cancel: Smallint) of object;
  TVtChartPointSelected = procedure(Sender: TObject; var Series, DataPoint, MouseFlags, Cancel: Smallint) of object;
  TVtChartPointLabelSelected = procedure(Sender: TObject; var Series, DataPoint, MouseFlags, Cancel: Smallint) of object;
  TVtChartSeriesSelected = procedure(Sender: TObject; var Series, MouseFlags, Cancel: Smallint) of object;
  TVtChartSeriesLabelSelected = procedure(Sender: TObject; var Series, MouseFlags, Cancel: Smallint) of object;
  TVtChartChartActivated = procedure(Sender: TObject; var MouseFlags, Cancel: Smallint) of object;
  TVtChartTitleActivated = procedure(Sender: TObject; var MouseFlags, Cancel: Smallint) of object;
  TVtChartFootnoteActivated = procedure(Sender: TObject; var MouseFlags, Cancel: Smallint) of object;
  TVtChartLegendActivated = procedure(Sender: TObject; var MouseFlags, Cancel: Smallint) of object;
  TVtChartPlotActivated = procedure(Sender: TObject; var MouseFlags, Cancel: Smallint) of object;
  TVtChartAxisActivated = procedure(Sender: TObject; var AxisId, AxisIndex, MouseFlags, Cancel: Smallint) of object;
  TVtChartAxisLabelActivated = procedure(Sender: TObject; var AxisId, AxisIndex, labelSetIndex, LabelIndex, MouseFlags, Cancel: Smallint) of object;
  TVtChartAxisTitleActivated = procedure(Sender: TObject; var AxisId, AxisIndex, MouseFlags, Cancel: Smallint) of object;
  TVtChartPointActivated = procedure(Sender: TObject; var Series, DataPoint, MouseFlags, Cancel: Smallint) of object;
  TVtChartPointLabelActivated = procedure(Sender: TObject; var Series, DataPoint, MouseFlags, Cancel: Smallint) of object;
  TVtChartSeriesActivated = procedure(Sender: TObject; var Series, MouseFlags, Cancel: Smallint) of object;
  TVtChartSeriesLabelActivated = procedure(Sender: TObject; var Series, MouseFlags, Cancel: Smallint) of object;

  TVtChart = class(TOleControl)
  private
    FOnChartSelected: TVtChartChartSelected;
    FOnTitleSelected: TVtChartTitleSelected;
    FOnFootnoteSelected: TVtChartFootnoteSelected;
    FOnLegendSelected: TVtChartLegendSelected;
    FOnPlotSelected: TVtChartPlotSelected;
    FOnAxisSelected: TVtChartAxisSelected;
    FOnAxisLabelSelected: TVtChartAxisLabelSelected;
    FOnAxisTitleSelected: TVtChartAxisTitleSelected;
    FOnPointSelected: TVtChartPointSelected;
    FOnPointLabelSelected: TVtChartPointLabelSelected;
    FOnSeriesSelected: TVtChartSeriesSelected;
    FOnSeriesLabelSelected: TVtChartSeriesLabelSelected;
    FOnChartActivated: TVtChartChartActivated;
    FOnTitleActivated: TVtChartTitleActivated;
    FOnFootnoteActivated: TVtChartFootnoteActivated;
    FOnLegendActivated: TVtChartLegendActivated;
    FOnPlotActivated: TVtChartPlotActivated;
    FOnAxisActivated: TVtChartAxisActivated;
    FOnAxisLabelActivated: TVtChartAxisLabelActivated;
    FOnAxisTitleActivated: TVtChartAxisTitleActivated;
    FOnPointActivated: TVtChartPointActivated;
    FOnPointLabelActivated: TVtChartPointLabelActivated;
    FOnSeriesActivated: TVtChartSeriesActivated;
    FOnSeriesLabelActivated: TVtChartSeriesLabelActivated;
    FOnApplyChanges: TNotifyEvent;
    FIntf: _DVtChart;
    function Get_GetBitmap(options: OleVariant): OLE_HANDLE;
  protected
    procedure InitControlData; override;
    procedure InitControlInterface(const Obj: IUnknown); override;
  public
    procedure EditPaste;
    procedure EditCopy;
    procedure ActivateSelectionDialog;
    procedure Layout;
    procedure ToDefaults;
    procedure PrintSetupDialog;
    procedure PrintChart;
    procedure SelectPart(part, index1, index2, index3, index4: Smallint);
    procedure GetSelectedPart(var part, index1, index2, index3, index4: Smallint);
    procedure GetDLLVersion(var major, minor: Smallint);
    procedure TwipsToChartPart(xVal, yVal: Integer; var part, index1, index2, index3, index4: Smallint);
    procedure ReadFromFile(const FileName: WideString);
    procedure WritePictureToFile(const FileName: WideString; pictureType, options: Smallint);
    procedure WriteToFile(const FileName: WideString);
    procedure ActivateFormatMenu(X, Y: Integer);
    procedure GetMetafile(options: Smallint; var Handle: OLE_HANDLE; var Width, Height: Integer);
    procedure CopyDataFromArray(Top, Left, Bottom, Right: Smallint; Array_: OleVariant);
    procedure CopyDataToArray(Top, Left, Bottom, Right: Smallint; Array_: OleVariant);
    procedure Draw(hDC: OLE_HANDLE; hDCType: Smallint; Top, Left, Bottom, Right: Integer; Layout, Stretch: WordBool);
    procedure UseWizard;
    procedure EditChartData;
    procedure Refresh;
    procedure AboutBox;
    property ControlInterface: _DVtChart read FIntf;
    property SsLinkSheet: WideString index 22 read GetWideStringProp write SetWideStringProp;
    property Handle: Integer index 24 read GetIntegerProp;
    property Picture: TPicture index 25 read GetTPictureProp;
    property GetBitmap[options: OleVariant]: OLE_HANDLE read Get_GetBitmap;
  published
    property TabStop;
    property Align;
    property DragCursor;
    property DragMode;
    property ParentShowHint;
    property PopupMenu;
    property ShowHint;
    property TabOrder;
    property Visible;
    property OnDragDrop;
    property OnDragOver;
    property OnEndDrag;
    property OnEnter;
    property OnExit;
    property OnStartDrag;
    property OnMouseUp;
    property OnMouseMove;
    property OnMouseDown;
    property OnKeyUp;
    property OnKeyPress;
    property OnKeyDown;
    property OnDblClick;
    property OnClick;
    property AutoIncrement: WordBool index 1 read GetWordBoolProp write SetWordBoolProp stored False;
    property RandomFill: WordBool index 2 read GetWordBoolProp write SetWordBoolProp stored False;
    property ChartType: Smallint index 3 read GetSmallintProp write SetSmallintProp stored False;
    property Column: Smallint index 4 read GetSmallintProp write SetSmallintProp stored False;
    property ColumnCount: Smallint index 5 read GetSmallintProp write SetSmallintProp stored False;
    property ColumnLabel: WideString index 6 read GetWideStringProp write SetWideStringProp stored False;
    property ColumnLabelCount: Smallint index 7 read GetSmallintProp write SetSmallintProp stored False;
    property ColumnLabelIndex: Smallint index 8 read GetSmallintProp write SetSmallintProp stored False;
    property Data: WideString index 9 read GetWideStringProp write SetWideStringProp stored False;
    property FootnoteText: WideString index 10 read GetWideStringProp write SetWideStringProp stored False;
    property Repaint: WordBool index 11 read GetWordBoolProp write SetWordBoolProp stored False;
    property Row: Smallint index 12 read GetSmallintProp write SetSmallintProp stored False;
    property RowCount: Smallint index 13 read GetSmallintProp write SetSmallintProp stored False;
    property RowLabel: WideString index 14 read GetWideStringProp write SetWideStringProp stored False;
    property RowLabelCount: Smallint index 15 read GetSmallintProp write SetSmallintProp stored False;
    property RowLabelIndex: Smallint index 16 read GetSmallintProp write SetSmallintProp stored False;
    property SeriesColumn: Smallint index 17 read GetSmallintProp write SetSmallintProp stored False;
    property SeriesType: Smallint index 18 read GetSmallintProp write SetSmallintProp stored False;
    property ShowLegend: WordBool index 19 read GetWordBoolProp write SetWordBoolProp stored False;
    property SsLinkMode: Smallint index 20 read GetSmallintProp write SetSmallintProp stored False;
    property SsLinkRange: WideString index 21 read GetWideStringProp write SetWideStringProp stored False;
    property DrawMode: Smallint index 23 read GetSmallintProp write SetSmallintProp stored False;
    property BorderStyle: Smallint index -504 read GetSmallintProp write SetSmallintProp stored False;
    property Enabled: WordBool index -514 read GetWordBoolProp write SetWordBoolProp stored False;
    property hWnd: Smallint index -515 read GetSmallintProp write SetSmallintProp stored False;
    property Title: IDispatch index 26 read GetIDispatchProp write SetIDispatchProp stored False;
    property Footnote: IDispatch index 27 read GetIDispatchProp write SetIDispatchProp stored False;
    property TitleText: WideString index 28 read GetWideStringProp write SetWideStringProp stored False;
    property Stacking: WordBool index 29 read GetWordBoolProp write SetWordBoolProp stored False;
    property TextLengthType: Smallint index 30 read GetSmallintProp write SetSmallintProp stored False;
    property AllowUserChanges: WordBool index 31 read GetWordBoolProp write SetWordBoolProp stored False;
    property AllowSelections: WordBool index 32 read GetWordBoolProp write SetWordBoolProp stored False;
    property AllowSeriesSelection: WordBool index 33 read GetWordBoolProp write SetWordBoolProp stored False;
    property AllowDynamicRotation: WordBool index 34 read GetWordBoolProp write SetWordBoolProp stored False;
    property ActiveSeriesCount: Smallint index 35 read GetSmallintProp write SetSmallintProp stored False;
    property Backdrop: IDispatch index 36 read GetIDispatchProp write SetIDispatchProp stored False;
    property PrintInformation: IDispatch index 37 read GetIDispatchProp write SetIDispatchProp stored False;
    property Legend: IDispatch index 38 read GetIDispatchProp write SetIDispatchProp stored False;
    property DataGrid: IDispatch index 39 read GetIDispatchProp write SetIDispatchProp stored False;
    property Plot: IDispatch index 40 read GetIDispatchProp write SetIDispatchProp stored False;
    property TwipsWidth: Integer index 41 read GetIntegerProp write SetIntegerProp stored False;
    property TwipsHeight: Integer index 42 read GetIntegerProp write SetIntegerProp stored False;
    property AllowDithering: WordBool index 43 read GetWordBoolProp write SetWordBoolProp stored False;
    property ErrorOffset: Smallint index 44 read GetSmallintProp write SetSmallintProp stored False;
    property DoSetCursor: WordBool index 45 read GetWordBoolProp write SetWordBoolProp stored False;
    property FileName: WideString index 46 read GetWideStringProp write SetWideStringProp stored False;
    property Chart3d: WordBool index 47 read GetWordBoolProp write SetWordBoolProp stored False;
    property SsLinkBook: WideString index 48 read GetWideStringProp write SetWideStringProp stored False;
    property OnChartSelected: TVtChartChartSelected read FOnChartSelected write FOnChartSelected;
    property OnTitleSelected: TVtChartTitleSelected read FOnTitleSelected write FOnTitleSelected;
    property OnFootnoteSelected: TVtChartFootnoteSelected read FOnFootnoteSelected write FOnFootnoteSelected;
    property OnLegendSelected: TVtChartLegendSelected read FOnLegendSelected write FOnLegendSelected;
    property OnPlotSelected: TVtChartPlotSelected read FOnPlotSelected write FOnPlotSelected;
    property OnAxisSelected: TVtChartAxisSelected read FOnAxisSelected write FOnAxisSelected;
    property OnAxisLabelSelected: TVtChartAxisLabelSelected read FOnAxisLabelSelected write FOnAxisLabelSelected;
    property OnAxisTitleSelected: TVtChartAxisTitleSelected read FOnAxisTitleSelected write FOnAxisTitleSelected;
    property OnPointSelected: TVtChartPointSelected read FOnPointSelected write FOnPointSelected;
    property OnPointLabelSelected: TVtChartPointLabelSelected read FOnPointLabelSelected write FOnPointLabelSelected;
    property OnSeriesSelected: TVtChartSeriesSelected read FOnSeriesSelected write FOnSeriesSelected;
    property OnSeriesLabelSelected: TVtChartSeriesLabelSelected read FOnSeriesLabelSelected write FOnSeriesLabelSelected;
    property OnChartActivated: TVtChartChartActivated read FOnChartActivated write FOnChartActivated;
    property OnTitleActivated: TVtChartTitleActivated read FOnTitleActivated write FOnTitleActivated;
    property OnFootnoteActivated: TVtChartFootnoteActivated read FOnFootnoteActivated write FOnFootnoteActivated;
    property OnLegendActivated: TVtChartLegendActivated read FOnLegendActivated write FOnLegendActivated;
    property OnPlotActivated: TVtChartPlotActivated read FOnPlotActivated write FOnPlotActivated;
    property OnAxisActivated: TVtChartAxisActivated read FOnAxisActivated write FOnAxisActivated;
    property OnAxisLabelActivated: TVtChartAxisLabelActivated read FOnAxisLabelActivated write FOnAxisLabelActivated;
    property OnAxisTitleActivated: TVtChartAxisTitleActivated read FOnAxisTitleActivated write FOnAxisTitleActivated;
    property OnPointActivated: TVtChartPointActivated read FOnPointActivated write FOnPointActivated;
    property OnPointLabelActivated: TVtChartPointLabelActivated read FOnPointLabelActivated write FOnPointLabelActivated;
    property OnSeriesActivated: TVtChartSeriesActivated read FOnSeriesActivated write FOnSeriesActivated;
    property OnSeriesLabelActivated: TVtChartSeriesLabelActivated read FOnSeriesLabelActivated write FOnSeriesLabelActivated;
    property OnApplyChanges: TNotifyEvent read FOnApplyChanges write FOnApplyChanges;
  end;

procedure Register;

implementation

uses ComObj;

procedure TVtChart.InitControlData;
const
  CEventDispIDs: array[0..24] of Integer = (
    $00000001, $00000002, $00000003, $00000004, $00000005, $00000006,
    $00000007, $00000008, $00000009, $0000000A, $0000000B, $0000000C,
    $0000000D, $0000000E, $0000000F, $00000010, $00000011, $00000012,
    $00000013, $00000014, $00000015, $00000016, $00000017, $00000018,
    $00000019);
  CLicenseKey: array[0..42] of Word = (
    $0043, $006F, $0070, $0079, $0072, $0069, $0067, $0068, $0074, $0020,
    $0028, $0063, $0029, $0020, $0031, $0039, $0039, $0035, $0020, $0056,
    $0069, $0073, $0075, $0061, $006C, $0020, $0043, $006F, $006D, $0070,
    $006F, $006E, $0065, $006E, $0074, $0073, $002C, $0020, $0049, $006E,
    $0063, $002E, $0000);
  CTPictureIDs: array [0..0] of Integer = (
    $00000019);
  CControlData: TControlData = (
    ClassID: '{5A721580-5AF0-11CE-8384-0020AF2337F2}';
    EventIID: '{5A721582-5AF0-11CE-8384-0020AF2337F2}';
    EventCount: 25;
    EventDispIDs: @CEventDispIDs;
    LicenseKey: @CLicenseKey;
    Flags: $00000008;
    Version: 300;
    FontCount: 0;
    FontIDs: nil;
    PictureCount: 1;
    PictureIDs: @CTPictureIDs);
begin
  ControlData := @CControlData;
end;

procedure TVtChart.InitControlInterface(const Obj: IUnknown);
begin
  FIntf := Obj as _DVtChart;
end;

procedure TVtChart.EditPaste;
begin
  ControlInterface.EditPaste;
end;

procedure TVtChart.EditCopy;
begin
  ControlInterface.EditCopy;
end;

procedure TVtChart.ActivateSelectionDialog;
begin
  ControlInterface.ActivateSelectionDialog;
end;

procedure TVtChart.Layout;
begin
  ControlInterface.Layout;
end;

procedure TVtChart.ToDefaults;
begin
  ControlInterface.ToDefaults;
end;

procedure TVtChart.PrintSetupDialog;
begin
  ControlInterface.PrintSetupDialog;
end;

procedure TVtChart.PrintChart;
begin
  ControlInterface.PrintChart;
end;

procedure TVtChart.SelectPart(part, index1, index2, index3, index4: Smallint);
begin
  ControlInterface.SelectPart(part, index1, index2, index3, index4);
end;

procedure TVtChart.GetSelectedPart(var part, index1, index2, index3, index4: Smallint);
begin
  ControlInterface.GetSelectedPart(part, index1, index2, index3, index4);
end;

procedure TVtChart.GetDLLVersion(var major, minor: Smallint);
begin
  ControlInterface.GetDLLVersion(major, minor);
end;

procedure TVtChart.TwipsToChartPart(xVal, yVal: Integer; var part, index1, index2, index3, index4: Smallint);
begin
  ControlInterface.TwipsToChartPart(xVal, yVal, part, index1, index2, index3, index4);
end;

procedure TVtChart.ReadFromFile(const FileName: WideString);
begin
  ControlInterface.ReadFromFile(FileName);
end;

procedure TVtChart.WritePictureToFile(const FileName: WideString; pictureType, options: Smallint);
begin
  ControlInterface.WritePictureToFile(FileName, pictureType, options);
end;

procedure TVtChart.WriteToFile(const FileName: WideString);
begin
  ControlInterface.WriteToFile(FileName);
end;

procedure TVtChart.ActivateFormatMenu(X, Y: Integer);
begin
  ControlInterface.ActivateFormatMenu(X, Y);
end;

procedure TVtChart.GetMetafile(options: Smallint; var Handle: OLE_HANDLE; var Width, Height: Integer);
begin
  ControlInterface.GetMetafile(options, Handle, Width, Height);
end;

procedure TVtChart.CopyDataFromArray(Top, Left, Bottom, Right: Smallint; Array_: OleVariant);
begin
  ControlInterface.CopyDataFromArray(Top, Left, Bottom, Right, Array_);
end;

procedure TVtChart.CopyDataToArray(Top, Left, Bottom, Right: Smallint; Array_: OleVariant);
begin
  ControlInterface.CopyDataToArray(Top, Left, Bottom, Right, Array_);
end;

procedure TVtChart.Draw(hDC: OLE_HANDLE; hDCType: Smallint; Top, Left, Bottom, Right: Integer; Layout, Stretch: WordBool);
begin
  ControlInterface.Draw(hDC, hDCType, Top, Left, Bottom, Right, Layout, Stretch);
end;

procedure TVtChart.UseWizard;
begin
  ControlInterface.UseWizard;
end;

procedure TVtChart.EditChartData;
begin
  ControlInterface.EditChartData;
end;

procedure TVtChart.Refresh;
begin
  ControlInterface.Refresh;
end;

procedure TVtChart.AboutBox;
begin
  ControlInterface.AboutBox;
end;

function TVtChart.Get_GetBitmap(options: OleVariant): OLE_HANDLE;
begin
  Result := ControlInterface.GetBitmap[options];
end;

procedure Register;
begin
  RegisterComponents('ActiveX', [TVtChart]);  { do not localize }
end;

end.
