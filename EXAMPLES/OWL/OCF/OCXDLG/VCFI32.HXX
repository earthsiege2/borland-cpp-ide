// Type Library: vcfi32.ocx  VCI First Impression Library
// VCIFiLib 1.0 {5A721583-5AF0-11CE-8384-0020AF2337F2}\0

#if !defined(_PROXY_VCFI32_HXX)
#define _PROXY_VCFI32_HXX

#include <ocf/automacr.h>

class _DVtChart;
class _DVtChartEvents;
class ICoor;
class ILCoor;
class ICoor3;
class ILRect;
class IRect;
class IColor;
class IBrush;
class IShadow;
class ITextLayout;
class IVcTitle;
class ILocation;
class IBackdrop;
class IFrame;
class IGradient;
class IFill;
class IVcPen;
class IVcMarker;
class IVcFootnote;
class IVcLegend;
class IVcPrintInformation;
class IVcDataGrid;
class IVcPlot;
class IVcView3d;
class IVcPlotBase;
class IVcDoughnut;
class IVcPie;
class IVcWeighting;
class IVcWall;
class IVcSeries;
class IVcBar;
class IVcHiLo;
class IVcPosition;
class IVcSeriesMarker;
class IVcSeriesLabel;
class IVcStatLines;
class IVcDataPointLabel;
class IVcDataPoint;
class IVcAxis;
class IVcCategoryScale;
class IVcDateScale;
class IVcAxisGrid;
class IVcIntersection;
class IVcTick;
class IVcScale;
class IVcValueScale;
class IVcAxisTitle;
class IVcLabel;
class IVcLight;
class IVcElevation;
class IVcAttribute;
class IVcSurface;
class IVcContour;
class IVcLightSource;
class IVcSeriesCollection;
class IVcDataPoints;
class IVcLabels;
class IVcXYZ;
class IVcLightSources;
class IVcAttributes;
class IVcContourGradient;

// TKIND_ENUM: FontStyleConstants {A899E1A2-1032-11CF-8411-00AA0042CB33}\409 The list of VtFont styles

enum FontStyleConstants {
  VtFontStyleBold,
  VtFontStyleItalic,
  VtFontStyleOutline,
};

// TKIND_ENUM: FontEffectsConstants {A899E1A3-1032-11CF-8411-00AA0042CB33}\409 The list of VtFont effects

enum FontEffectsConstants {
  VtFontEffectStrikeThrough,
  VtFontEffectUnderline,
};

// TKIND_ENUM: FrameStyleConstants {A899E1A5-1032-11CF-8411-00AA0042CB33}\409 Frame Styles

enum FrameStyleConstants {
  VtFrameStyleNull,
  VtFrameStyleSingleLine,
  VtFrameStyleDoubleLine,
  VtFrameStyleThickInner,
  VtFrameStyleThickOuter,
};

// TKIND_ENUM: BrushStyleConstants {A899E1A6-1032-11CF-8411-00AA0042CB33}\409 Brush Styles

enum BrushStyleConstants {
  VtBrushStyleNull,
  VtBrushStyleSolid,
  VtBrushStylePattern,
  VtBrushStyleHatched,
};

// TKIND_ENUM: LabelComponentConstants {A899E1A7-1032-11CF-8411-00AA0042CB33}\409 The list of datapoint label component types

enum LabelComponentConstants {
  VtChLabelComponentValue,
  VtChLabelComponentPercent,
  VtChLabelComponentSeriesName,
  VtChLabelComponentPointName,
};

// TKIND_ENUM: BrushPatternConstants {A899E1A8-1032-11CF-8411-00AA0042CB33}\409 Brush Patterns

enum BrushPatternConstants {
  VtBrushPattern94Percent,
  VtBrushPattern88Percent,
  VtBrushPattern75Percent,
  VtBrushPattern50Percent,
  VtBrushPattern25Percent,
  VtBrushPatternBoldHorizontal,
  VtBrushPatternBoldVertical,
  VtBrushPatternBoldDownDiagonal,
  VtBrushPatternBoldUpDiagonal,
  VtBrushPatternChecks,
  VtBrushPatternWeave,
  VtBrushPatternHorizontal,
  VtBrushPatternVertical,
  VtBrushPatternDownDiagonal,
  VtBrushPatternUpDiagonal,
  VtBrushPatternGrid,
  VtBrushPatternTrellis,
  VtBrushPatternInvertedTrellis,
};

// TKIND_ENUM: BrushHatchConstants {A899E1A9-1032-11CF-8411-00AA0042CB33}\409 Brush Hatches

enum BrushHatchConstants {
  VtBrushHatchHorizontal,
  VtBrushHatchVertical,
  VtBrushHatchDownDiagonal,
  VtBrushHatchUpDiagonal,
  VtBrushHatchCross,
  VtBrushHatchDiagonalCross,
};

// TKIND_ENUM: ShadowStyleConstants {A899E1AA-1032-11CF-8411-00AA0042CB33}\409 Shadow Styles

enum ShadowStyleConstants {
  VtShadowStyleNull,
  VtShadowStyleDrop,
};

// TKIND_ENUM: MouseFlagConstants {A899E1AB-1032-11CF-8411-00AA0042CB33}\409 Mouse Flag Constants

enum MouseFlagConstants {
  VtChMouseFlagShiftKeyDown,
  VtChMouseFlagControlKeyDown,
};

// TKIND_ENUM: PenStyleConstants {A899E1AC-1032-11CF-8411-00AA0042CB33}\409 Pen Styles

enum PenStyleConstants {
  VtPenStyleNull,
  VtPenStyleSolid,
  VtPenStyleDashed,
  VtPenStyleDotted,
  VtPenStyleDashDot,
  VtPenStyleDashDotDot,
  VtPenStyleDitted,
  VtPenStyleDashDit,
  VtPenStyleDashDitDit,
};

// TKIND_ENUM: PenJoinConstants {A899E1AD-1032-11CF-8411-00AA0042CB33}\409 Pen Join types

enum PenJoinConstants {
  VtPenJoinMiter,
  VtPenJoinRound,
  VtPenJoinBevel,
};

// TKIND_ENUM: PenCapConstants {A899E1AE-1032-11CF-8411-00AA0042CB33}\409 Pen Cap types

enum PenCapConstants {
  VtPenCapButt,
  VtPenCapRound,
  VtPenCapSquare,
};

// TKIND_ENUM: GradientStyleConstants {A899E1AF-1032-11CF-8411-00AA0042CB33}\409 Gradient Styles

enum GradientStyleConstants {
  VtGradientStyleHorizontal,
  VtGradientStyleVertical,
  VtGradientStyleRectangle,
  VtGradientStyleOval,
};

// TKIND_ENUM: PictureTypeConstants {A899E1B0-1032-11CF-8411-00AA0042CB33}\409 Picture Types

enum PictureTypeConstants {
  VtPictureTypeNull,
  VtPictureTypeBMP,
  VtPictureTypeWMF,
};

// TKIND_ENUM: PictureOptionConstants {A899E1B1-1032-11CF-8411-00AA0042CB33}\409 Picture Options (WMF only)

enum PictureOptionConstants {
  VtPictureOptionNoSizeHeader,
  VtPictureOptionTextAsCurves,
};

// TKIND_ENUM: PictureMapTypeConstants {A899E1B2-1032-11CF-8411-00AA0042CB33}\409 Picture Map Types

enum PictureMapTypeConstants {
  VtPictureMapTypeActual,
  VtPictureMapTypeFitted,
  VtPictureMapTypeStretched,
  VtPictureMapTypeTiled,
  VtPictureMapTypeCropFitted,
};

// TKIND_ENUM: FillStyleConstants {A899E1B4-1032-11CF-8411-00AA0042CB33}\409 Fill Style Constants

enum FillStyleConstants {
  VtFillStyleNull,
  VtFillStyleBrush,
  VtFillStyleGradient,
};

// TKIND_ENUM: LocationTypeConstants {A899E1B5-1032-11CF-8411-00AA0042CB33}\409 Chart Element Location Type Constants

enum LocationTypeConstants {
  VtChLocationTypeTopLeft,
  VtChLocationTypeTop,
  VtChLocationTypeTopRight,
  VtChLocationTypeLeft,
  VtChLocationTypeRight,
  VtChLocationTypeBottomLeft,
  VtChLocationTypeBottom,
  VtChLocationTypeBottomRight,
  VtChLocationTypeCustom,
};

// TKIND_ENUM: AxisIdConstants {A899E1B6-1032-11CF-8411-00AA0042CB33}\409 Axis Id Constants

enum AxisIdConstants {
  VtChAxisIdX,
  VtChAxisIdY,
  VtChAxisIdY2,
  VtChAxisIdZ,
};

// TKIND_ENUM: AxisTickStyleConstants {A899E1B7-1032-11CF-8411-00AA0042CB33}\409 Axis Tick Style Constants

enum AxisTickStyleConstants {
  VtChAxisTickStyleNone,
  VtChAxisTickStyleCenter,
  VtChAxisTickStyleInside,
  VtChAxisTickStyleOutside,
};

// TKIND_ENUM: DateIntervalTypeConstants {A899E1B8-1032-11CF-8411-00AA0042CB33}\409 Date Interval Constants

enum DateIntervalTypeConstants {
  VtChDateIntervalTypeNone,
  VtChDateIntervalTypeDaily,
  VtChDateIntervalTypeWeekly,
  VtChDateIntervalTypeSemimonthly,
  VtChDateIntervalTypeMonthly,
  VtChDateIntervalTypeYearly,
};

// TKIND_ENUM: ScaleTypeConstants {A899E1B9-1032-11CF-8411-00AA0042CB33}\409 Scale Type Constants

enum ScaleTypeConstants {
  VtChScaleTypeLinear,
  VtChScaleTypeLogarithmic,
  VtChScaleTypePercent,
};

// TKIND_ENUM: PercentAxisBasisConstants {A899E1BA-1032-11CF-8411-00AA0042CB33}\409 Percent Axis Basis Constants

enum PercentAxisBasisConstants {
  VtChPercentAxisBasisMaxChart,
  VtChPercentAxisBasisMaxRow,
  VtChPercentAxisBasisMaxColumn,
  VtChPercentAxisBasisSumChart,
  VtChPercentAxisBasisSumRow,
  VtChPercentAxisBasisSumColumn,
};

// TKIND_ENUM: PieWeightBasisConstants {A899E1BB-1032-11CF-8411-00AA0042CB33}\409 Pie Weight Basis Constants

enum PieWeightBasisConstants {
  VtChPieWeightBasisNone,
  VtChPieWeightBasisTotal,
  VtChPieWeightBasisSeries,
};

// TKIND_ENUM: PieWeightStyleConstants {A899E1BC-1032-11CF-8411-00AA0042CB33}\409 Pie Weight Style Constants

enum PieWeightStyleConstants {
  VtChPieWeightStyleArea,
  VtChPieWeightStyleDiameter,
};

// TKIND_ENUM: SortTypeConstants {A899E1BD-1032-11CF-8411-00AA0042CB33}\409 Sort Type Constants

enum SortTypeConstants {
  VtSortTypeNone,
  VtSortTypeAscending,
  VtSortTypeDescending,
};

// TKIND_ENUM: AngleUnitsConstants {A899E1BE-1032-11CF-8411-00AA0042CB33}\409 Angle Units Constants

enum AngleUnitsConstants {
  VtAngleUnitsDegrees,
  VtAngleUnitsRadians,
  VtAngleUnitsGrads,
};

// TKIND_ENUM: SubPlotLabelLocationTypeConstants {A899E1BF-1032-11CF-8411-00AA0042CB33}\409 Sub Plot Label Location Type Constants

enum SubPlotLabelLocationTypeConstants {
  VtChSubPlotLabelLocationTypeNone,
  VtChSubPlotLabelLocationTypeAbove,
  VtChSubPlotLabelLocationTypeBelow,
  VtChSubPlotLabelLocationTypeCenter,
};

// TKIND_ENUM: LabelLineStyleConstants {A899E1C0-1032-11CF-8411-00AA0042CB33}\409 The list of series/datapoint label line styles

enum LabelLineStyleConstants {
  VtChLabelLineStyleNone,
  VtChLabelLineStyleStraight,
  VtChLabelLineStyleBent,
};

// TKIND_ENUM: LabelLocationTypeConstants {A899E1C1-1032-11CF-8411-00AA0042CB33}\409 The list of series/datapoint label locations

enum LabelLocationTypeConstants {
  VtChLabelLocationTypeNone,
  VtChLabelLocationTypeAbovePoint,
  VtChLabelLocationTypeBelowPoint,
  VtChLabelLocationTypeCenter,
  VtChLabelLocationTypeBase,
  VtChLabelLocationTypeInside,
  VtChLabelLocationTypeOutside,
  VtChLabelLocationTypeLeft,
  VtChLabelLocationTypeRight,
};

// TKIND_ENUM: ContourColorTypeConstants {A899E1C2-1032-11CF-8411-00AA0042CB33}\409 Contour VtColor Type Constants

enum ContourColorTypeConstants {
  VtChContourColorTypeAutomatic,
  VtChContourColorTypeGradient,
  VtChContourColorTypeManual,
};

// TKIND_ENUM: ContourDisplayTypeConstants {A899E1C3-1032-11CF-8411-00AA0042CB33}\409 Contour Display Type Constants

enum ContourDisplayTypeConstants {
  VtChContourDisplayTypeCBands,
  VtChContourDisplayTypeCLines,
};

// TKIND_ENUM: SurfaceBaseTypeConstants {A899E1C4-1032-11CF-8411-00AA0042CB33}\409 Surface Base Type Constants

enum SurfaceBaseTypeConstants {
  VtChSurfaceBaseTypePedestal,
  VtChSurfaceBaseTypeStandard,
  VtChSurfaceBaseTypeStandardWithCBands,
  VtChSurfaceBaseTypeStandardWithCLines,
};

// TKIND_ENUM: SurfaceDisplayTypeConstants {A899E1C6-1032-11CF-8411-00AA0042CB33}\409 Surface Display Type Constants

enum SurfaceDisplayTypeConstants {
  VtChSurfaceDisplayTypeNone,
  VtChSurfaceDisplayTypeCBands,
  VtChSurfaceDisplayTypeCLines,
  VtChSurfaceDisplayTypeSolid,
  VtChSurfaceDisplayTypeSolidWithCLines,
};

// TKIND_ENUM: SurfaceProjectionTypeConstants {A899E1C7-1032-11CF-8411-00AA0042CB33}\409 Surface Projection Type Constants

enum SurfaceProjectionTypeConstants {
  VtChSurfaceProjectionTypeNone,
  VtChSurfaceProjectionTypeCBands,
  VtChSurfaceProjectionTypeCLines,
};

// TKIND_ENUM: SurfaceWireframeTypeConstants {A899E1C8-1032-11CF-8411-00AA0042CB33}\409 Surface Wireframe Type Constants

enum SurfaceWireframeTypeConstants {
  VtChSurfaceWireframeTypeNone,
  VtChSurfaceWireframeTypeMajor,
  VtChSurfaceWireframeTypeMajorAndMinor,
};

// TKIND_ENUM: MarkerStyleConstants {A899E1C9-1032-11CF-8411-00AA0042CB33}\409 Marker Style Constants

enum MarkerStyleConstants {
  VtMarkerStyleDash,
  VtMarkerStylePlus,
  VtMarkerStyleX,
  VtMarkerStyleStar,
  VtMarkerStyleCircle,
  VtMarkerStyleSquare,
  VtMarkerStyleDiamond,
  VtMarkerStyleUpTriangle,
  VtMarkerStyleDownTriangle,
  VtMarkerStyleFilledCircle,
  VtMarkerStyleFilledSquare,
  VtMarkerStyleFilledDiamond,
  VtMarkerStyleFilledUpTriangle,
  VtMarkerStyleFilledDownTriangle,
  VtMarkerStyle3dBall,
};

// TKIND_ENUM: ProjectionTypeConstants {A899E1CA-1032-11CF-8411-00AA0042CB33}\409 Projection Type Constants

enum ProjectionTypeConstants {
  VtProjectionTypePerspective,
  VtProjectionTypeOblique,
  VtProjectionTypeOrthogonal,
};

// TKIND_ENUM: SmoothingTypeConstants {A899E1CC-1032-11CF-8411-00AA0042CB33}\409 Smoothing Type Constants

enum SmoothingTypeConstants {
  VtSmoothingTypeNone,
  VtSmoothingTypeQuadraticBSpline,
  VtSmoothingTypeCubicBSpline,
};

// TKIND_ENUM: HorizontalAlignmentConstants {A899E1CD-1032-11CF-8411-00AA0042CB33}\409 Horizontal Alignment Constants

enum HorizontalAlignmentConstants {
  VtHorizontalAlignmentLeft,
  VtHorizontalAlignmentRight,
  VtHorizontalAlignmentCenter,
};

// TKIND_ENUM: VerticalAlignmentConstants {A899E1CE-1032-11CF-8411-00AA0042CB33}\409 Vertical Alignment Constants

enum VerticalAlignmentConstants {
  VtVerticalAlignmentTop,
  VtVerticalAlignmentBottom,
  VtVerticalAlignmentCenter,
};

// TKIND_ENUM: OrientationConstants {A899E1CF-1032-11CF-8411-00AA0042CB33}\409 Orientation Constants

enum OrientationConstants {
  VtOrientationHorizontal,
  VtOrientationVertical,
  VtOrientationUp,
  VtOrientationDown,
};

// TKIND_ENUM: DcTypeConstants {A899E1D7-1032-11CF-8411-00AA0042CB33}\409 Device Context Type Constants

enum DcTypeConstants {
  VtDcTypeNull,
  VtDcTypeDisplay,
  VtDcTypePrinter,
  VtDcTypeMetafile,
};

// TKIND_ENUM: PrintScaleTypeConstants {A899E1D1-1032-11CF-8411-00AA0042CB33}\409 Print Scale Type Constants

enum PrintScaleTypeConstants {
  VtPrintScaleTypeActual,
  VtPrintScaleTypeFitted,
  VtPrintScaleTypeStretched,
};

// TKIND_ENUM: StatTypeConstants {A899E1D2-1032-11CF-8411-00AA0042CB33}\409 Stat Type Constants

enum StatTypeConstants {
  VtChStatsMinimum,
  VtChStatsMaximum,
  VtChStatsMean,
  VtChStatsStddev,
  VtChStatsRegression,
};

// TKIND_ENUM: PrintOrientationTypeConstants {A899E1D3-1032-11CF-8411-00AA0042CB33}\409 Print Orientation Type Constants

enum PrintOrientationTypeConstants {
  VtPrintOrientationPortrait,
  VtPrintOrientationLandscape,
};

// TKIND_ENUM: TextOutputTypeConstants {A899E1D4-1032-11CF-8411-00AA0042CB33}\409 2D Text output Type Constants

enum TextOutputTypeConstants {
  VtTextOutputTypeHardware,
  VtTextOutputTypePolygon,
};

// TKIND_ENUM: TextLengthTypeConstants {A899E1D5-1032-11CF-8411-00AA0042CB33}\409 Text Length Type Constants

enum TextLengthTypeConstants {
  VtTextLengthTypeVirtual,
  VtTextLengthTypeDevice,
};

// TKIND_ENUM: PartTypeConstants {A899E1D6-1032-11CF-8411-00AA0042CB33}\409 Chart Part Type Constants

enum PartTypeConstants {
  VtChPartTypeChart,
  VtChPartTypeTitle,
  VtChPartTypeFootnote,
  VtChPartTypeLegend,
  VtChPartTypePlot,
  VtChPartTypeSeries,
  VtChPartTypeSeriesLabel,
  VtChPartTypePoint,
  VtChPartTypePointLabel,
  VtChPartTypeAxis,
  VtChPartTypeAxisLabel,
  VtChPartTypeAxisTitle,
};

// TKIND_ENUM: DrawModeConstants {BD2C42F1-6931-11CE-B525-0020AF2337F2}\409 The list of Draw modes

enum DrawModeConstants {
  VtChDrawModeDraw,
  VtChDrawModeBlit,
};

// TKIND_ENUM: SsLinkModeConstants {73F50FE0-69F4-11CE-86B3-444553540000}\409 The list of Formula One spreadsheet link modes

enum SsLinkModeConstants {
  VtChSsLinkModeOff,
  VtChSsLinkModeOn,
  VtChSsLinkModeAutoParse,
};

// TKIND_ENUM: SeriesTypeConstants {E0E187A1-69EF-11CE-86B3-444553540000}\409 The list of Series types

enum SeriesTypeConstants {
  VtChSeriesTypeDefault,
  VtChSeriesType3dBar,
  VtChSeriesType2dBar,
  VtChSeriesType3dHorizontalBar,
  VtChSeriesType2dHorizontalBar,
  VtChSeriesType3dClusteredBar,
  VtChSeriesType3dLine,
  VtChSeriesType2dLine,
  VtChSeriesType3dArea,
  VtChSeriesType2dArea,
  VtChSeriesType3dStep,
  VtChSeriesType2dStep,
  VtChSeriesType2dXY,
  VtChSeriesType2dPolar,
  VtChSeriesType2dRadarLine,
  VtChSeriesType2dRadarArea,
  VtChSeriesType2dBubble,
  VtChSeriesType2dHiLo,
  VtChSeriesType2dHLC,
  VtChSeriesType2dHLCRight,
  VtChSeriesType2dOHLC,
  VtChSeriesType2dOHLCBar,
  VtChSeriesType2dGantt,
  VtChSeriesType3dGantt,
  VtChSeriesType3dPie,
  VtChSeriesType2dPie,
  VtChSeriesType3dDoughnut,
  VtChSeriesType2dDates,
  VtChSeriesType3dBarHiLo,
  VtChSeriesType2dBarHiLo,
  VtChSeriesType3dHorizontalBarHiLo,
  VtChSeriesType2dHorizontalBarHiLo,
  VtChSeriesType3dClusteredBarHiLo,
  VtChSeriesType3dSurface,
  VtChSeriesType2dContour,
  VtChSeriesType3dXYZ,
};

// TKIND_ENUM: ChartTypeConstants {30B9EDB0-691A-11CE-B525-0020AF2337F2}\409 The list of Chart types

enum ChartTypeConstants {
  VtChChartType3dBar,
  VtChChartType2dBar,
  VtChChartType3dLine,
  VtChChartType2dLine,
  VtChChartType3dArea,
  VtChChartType2dArea,
  VtChChartType3dStep,
  VtChChartType2dStep,
  VtChChartType3dCombination,
  VtChChartType2dCombination,
  VtChChartType3dHorizontalBar,
  VtChChartType2dHorizontalBar,
  VtChChartType3dClusteredBar,
  VtChChartType3dPie,
  VtChChartType2dPie,
  VtChChartType3dDoughnut,
  VtChChartType2dXY,
  VtChChartType2dPolar,
  VtChChartType2dRadar,
  VtChChartType2dBubble,
  VtChChartType2dHiLo,
  VtChChartType2dGantt,
  VtChChartType3dGantt,
  VtChChartType3dSurface,
  VtChChartType2dContour,
  VtChChartType3dScatter,
  VtChChartType3dXYZ,
};

// TKIND_DISPATCH: _DVtChart {5A721581-5AF0-11CE-8384-0020AF2337F2}\409 Interface for VtChart Control

class _DVtChart : public TAutoProxy {
  public:
    _DVtChart() : TAutoProxy(0x409) {}
    // Determines whether the current data point row and column is automatically incremented after the Data property is used to enter or update data in the data grid.
    bool GetAutoIncrement();     // [id(1), prop r/w]
    void SetAutoIncrement(bool); // [id(1), prop r/w]
    // Determines whether random data is used to generate the chart.
    bool GetRandomFill();     // [id(2), prop r/w]
    void SetRandomFill(bool); // [id(2), prop r/w]
    // Returns/sets the type of chart used to plot the data in the data grid. (ChartTypeConstants)
    short GetChartType();     // [id(3), prop r/w]
    void SetChartType(short); // [id(3), prop r/w]
    // Returns/sets the active column in the data grid.
    short GetColumn();     // [id(4), prop r/w]
    void SetColumn(short); // [id(4), prop r/w]
    // Returns/sets the number of columns in the data grid.
    short GetColumnCount();     // [id(5), prop r/w]
    void SetColumnCount(short); // [id(5), prop r/w]
    // Returns/sets the label associated with the column identified by the Column property.
    TAutoString GetColumnLabel();     // [id(6), prop r/w]
    void SetColumnLabel(TAutoString); // [id(6), prop r/w]
    // Returns/sets the number of levels of labels above the data columns in the data grid.
    short GetColumnLabelCount();     // [id(7), prop r/w]
    void SetColumnLabelCount(short); // [id(7), prop r/w]
    // Identifies a particular level of column labels.
    short GetColumnLabelIndex();     // [id(8), prop r/w]
    void SetColumnLabelIndex(short); // [id(8), prop r/w]
    // Returns/sets the value of a specific data point in the data grid identified by Column and Row.
    TAutoString GetData();     // [id(9), prop r/w]
    void SetData(TAutoString); // [id(9), prop r/w]
    // Returns/sets the text used as a chart footnote.
    TAutoString GetFootnoteText();     // [id(10), prop r/w]
    void SetFootnoteText(TAutoString); // [id(10), prop r/w]
    // Determines whether First Impression repaints after a change is made to the chart.
    bool GetRepaint();     // [id(11), prop r/w]
    void SetRepaint(bool); // [id(11), prop r/w]
    // Returns/sets the active row of the data grid.
    short GetRow();     // [id(12), prop r/w]
    void SetRow(short); // [id(12), prop r/w]
    // Returns/sets the number of rows in the data grid.
    short GetRowCount();     // [id(13), prop r/w]
    void SetRowCount(short); // [id(13), prop r/w]
    // Returns/sets the label associated with the row identified bythe Row property.
    TAutoString GetRowLabel();     // [id(14), prop r/w]
    void SetRowLabel(TAutoString); // [id(14), prop r/w]
    // Returns/sets the number of levels of labels to the left of the data rows in the data grid
    short GetRowLabelCount();     // [id(15), prop r/w]
    void SetRowLabelCount(short); // [id(15), prop r/w]
    // Identifies a particular level of row labels.
    short GetRowLabelIndex();     // [id(16), prop r/w]
    void SetRowLabelIndex(short); // [id(16), prop r/w]
    // Returns/sets the column of the chart in which the current series is displayed.
    short GetSeriesColumn();     // [id(17), prop r/w]
    void SetSeriesColumn(short); // [id(17), prop r/w]
    // Returns/sets the chart type used to display the series identified in the Column property. (SeriesTypeConstants)
    short GetSeriesType();     // [id(18), prop r/w]
    void SetSeriesType(short); // [id(18), prop r/w]
    // Determines whether the legend is displayed on the chart.
    bool GetShowLegend();     // [id(19), prop r/w]
    void SetShowLegend(bool); // [id(19), prop r/w]
    // Determines whether a Formula One spreadsheet is used as the data source for the chart control. (SsLinkModeConstants)
    short GetSsLinkMode();     // [id(20), prop r/w]
    void SetSsLinkMode(short); // [id(20), prop r/w]
    // Returns/sets the range in the spreadsheet identified by SsLinkSheet that contains the source data for the chart.
    TAutoString GetSsLinkRange();     // [id(21), prop r/w]
    void SetSsLinkRange(TAutoString); // [id(21), prop r/w]
    // Returns/sets the Formula One spreadsheet used as the data source for the chart control.
    TAutoString GetSsLinkSheet();     // [id(22), prop r/w, hidden]
    void SetSsLinkSheet(TAutoString); // [id(22), prop r/w, hidden]
    // Determines when and how the chart is repainted. (DrawModeConstants)
    short GetDrawMode();     // [id(23), prop r/w]
    void SetDrawMode(short); // [id(23), prop r/w]
    // Returns/sets the border style for the chart.
    short GetBorderStyle();     // [id(-504), prop r/w, bindable, requestedit]
    void SetBorderStyle(short); // [id(-504), prop r/w, bindable, requestedit]
    // Determines whether the chart can respond to user-generated events.
    bool GetEnabled();     // [id(-514), prop r/w, bindable, requestedit]
    void SetEnabled(bool); // [id(-514), prop r/w, bindable, requestedit]
    // Returns the HWND of the chart.
    short GethWnd();     // [id(-515), prop r/w]
    void SethWnd(short); // [id(-515), prop r/w]
    // Returns a handle to the chart.
    long GetHandle();     // [id(24), prop r/o, hidden]
    // Returns a graphic to be displayed in the chart.
    IPictureDisp far* GetPicture();     // [id(25), prop r/o, hidden]
    // Returns the Title object associated with the chart.
    IDispatch* GetTitle();     // [id(26), prop r/w]
    void SetTitle(IDispatch*); // [id(26), prop r/w]
    // Returns the Footnote object associated with the chart
    IDispatch* GetFootnote();     // [id(27), prop r/w]
    void SetFootnote(IDispatch*); // [id(27), prop r/w]
    // Returns/sets the text to be used as the chart title
    TAutoString GetTitleText();     // [id(28), prop r/w]
    void SetTitleText(TAutoString); // [id(28), prop r/w]
    // Determines whether all the series in the chart are stacked.
    bool GetStacking();     // [id(29), prop r/w]
    void SetStacking(bool); // [id(29), prop r/w]
    // Returns/sets how text is drawn to optimize the appearance either on the screen or on the printed page. (TextLengthTypeConstants)
    short GetTextLengthType();     // [id(30), prop r/w]
    void SetTextLengthType(short); // [id(30), prop r/w]
    // Determines whether the end user can use First Impression dialog boxes to change chart properties.
    bool GetAllowUserChanges();     // [id(31), prop r/w]
    void SetAllowUserChanges(bool); // [id(31), prop r/w]
    // Determines whether the user can select chart elements.
    bool GetAllowSelections();     // [id(32), prop r/w]
    void SetAllowSelections(bool); // [id(32), prop r/w]
    // Determines whether clicking on an individual data point selects the entire series containing the data point.
    bool GetAllowSeriesSelection();     // [id(33), prop r/w]
    void SetAllowSeriesSelection(bool); // [id(33), prop r/w]
    // Determines whether or not the user can interactively rotate 3D charts.
    bool GetAllowDynamicRotation();     // [id(34), prop r/w]
    void SetAllowDynamicRotation(bool); // [id(34), prop r/w]
    // Returns the number of series that appear on the chart.
    short GetActiveSeriesCount();     // [id(35), prop r/w]
    void SetActiveSeriesCount(short); // [id(35), prop r/w]
    // Returns the Backdrop object associated with the chart.
    IDispatch* GetBackdrop();     // [id(36), prop r/w]
    void SetBackdrop(IDispatch*); // [id(36), prop r/w]
    // Returns the PrintInformation object associated with the chart.
    IDispatch* GetPrintInformation();     // [id(37), prop r/w]
    void SetPrintInformation(IDispatch*); // [id(37), prop r/w]
    // Returns the Legend object associated with the chart.
    IDispatch* GetLegend();     // [id(38), prop r/w]
    void SetLegend(IDispatch*); // [id(38), prop r/w]
    // Returns the DataGrid object associated with the chart.
    IDispatch* GetDataGrid();     // [id(39), prop r/w]
    void SetDataGrid(IDispatch*); // [id(39), prop r/w]
    // Returns the Plot object associated with the chart.
    IDispatch* GetPlot();     // [id(40), prop r/w]
    void SetPlot(IDispatch*); // [id(40), prop r/w]
    // Returns the width of the chart, in twips.
    long GetTwipsWidth();     // [id(41), prop r/w]
    void SetTwipsWidth(long); // [id(41), prop r/w]
    // Returns the height of the chart, in twips.
    long GetTwipsHeight();     // [id(42), prop r/w]
    void SetTwipsHeight(long); // [id(42), prop r/w]
    // Returns/sets whether to disable color dithering for charts in order to enhance the chart display.
    bool GetAllowDithering();     // [id(43), prop r/w]
    void SetAllowDithering(bool); // [id(43), prop r/w]
    // Sets or returns the adjustment to Visual Basic trappable error numbers returned by First Impression
    short GetErrorOffset();     // [id(44), prop r/w]
    void SetErrorOffset(short); // [id(44), prop r/w]
    // Returns/sets whether or not the mouse cursor type can be set by the chart.
    bool GetDoSetCursor();     // [id(45), prop r/w]
    void SetDoSetCursor(bool); // [id(45), prop r/w]
    // Returns/sets the chart filename.
    TAutoString GetFileName();     // [id(46), prop r/w]
    void SetFileName(TAutoString); // [id(46), prop r/w]
    // Returns whether the chart is three dimensional.
    bool GetChart3d();     // [id(47), prop r/w]
    void SetChart3d(bool); // [id(47), prop r/w]
    // Returns/sets the Formula One spreadsheet used as the data source for the chart control.
    TAutoString GetSsLinkBook();     // [id(48), prop r/w]
    void SetSsLinkBook(TAutoString); // [id(48), prop r/w]
    // Pastes a Windows Metafile graphic from the clipboard into the current selection.
    void EditPaste(); // [id(49), method]
    // Copies the current chart to the clipboard in Windows Metafile format.
    void EditCopy(); // [id(50), method]
    // Displays the dialog box associated with the currently selected chart part.
    void ActivateSelectionDialog(); // [id(51), method]
    // Forces the chart to recalculate the "automatic"attributes.
    void Layout(); // [id(52), method]
    // Returns the chart to its initial settings.
    void ToDefaults(); // [id(53), method]
    // Displays the Print Setup dialog box.
    void PrintSetupDialog(); // [id(54), method]
    // Sends current chart to the current printer using the information set by VtChSetPrintInformation.
    void PrintChart(); // [id(55), method]
    // Selects the specified chart part.
    void SelectPart(short part, short index1, short index2, short index3, short index4); // [id(56), method]
    // Returns the currently selected chart element.
    void GetSelectedPart(short far* part, short far* index1, short far* index2, short far* index3, short far* index4); // [id(57), method]
    // Returns the version number of the First Impression DLL you are using.
    void GetDLLVersion(short far* major, short far* minor); // [id(58), method]
    // Uses a set of coords on the chart to identify a part.
    void TwipsToChartPart(long xVal, long yVal, short far* part, short far* index1, short far* index2, short far* index3, short far* index4); // [id(59), method]
    // Opens an existing chart file.
    void ReadFromFile(TAutoString FileName); // [id(60), method]
    // Saves the chart to a file in a supported graphic format.
    void WritePictureToFile(TAutoString FileName, short pictureType, short options); // [id(61), method]
    // Saves the chart to a file.
    void WriteToFile(TAutoString FileName); // [id(62), method]
    // Displays the floating format menu on the chart control.
    void ActivateFormatMenu(long X, long Y); // [id(63), method]
    // Provides a handle to a copy of the chart in metafile format.
    void GetMetafile(short options, OLE_HANDLE far* Handle, long far* Width, long far* Height); // [id(64), method]
    // Copies data from an array into the data grid.
    void CopyDataFromArray(short Top, short Left, short Bottom, short Right, TAutoVal& Array); // [id(65), method]
    // Copies data from the data grid into an array.
    void CopyDataToArray(short Top, short Left, short Bottom, short Right, TAutoVal& Array); // [id(66), method]
    // Prints  a chart at a specific location on a page.
    void Draw(OLE_HANDLE hDC, short hDCType, long Top, long Left, long Bottom, long Right, bool Layout, bool Stretch); // [id(67), method]
    // Returns a handle to a copy of the current chart in bitmap format.
    OLE_HANDLE GetGetBitmap(TAutoVal& options); // [id(70), propget]
    // Invokes the chart wizard.
    void UseWizard(); // [id(68), method]
    // Invokes the data grid editor.
    void EditChartData(); // [id(69), method]
    // Repaints the chart.
    void Refresh(); // [id(-550), method]
    // Displays First Impression program information and copyright.
    void AboutBox(); // [id(-552), method]
};

// TKIND_DISPATCH: _DVtChartEvents {5A721582-5AF0-11CE-8384-0020AF2337F2}\409 Event interface for Vtchart Control

class _DVtChartEvents : public TAutoProxy {
  public:
    _DVtChartEvents() : TAutoProxy(0x409) {}
    void ChartSelected(short far* MouseFlags, short far* Cancel); // [id(1), method]
    void TitleSelected(short far* MouseFlags, short far* Cancel); // [id(2), method]
    void FootnoteSelected(short far* MouseFlags, short far* Cancel); // [id(3), method]
    void LegendSelected(short far* MouseFlags, short far* Cancel); // [id(4), method]
    void PlotSelected(short far* MouseFlags, short far* Cancel); // [id(5), method]
    void AxisSelected(short far* AxisId, short far* AxisIndex, short far* MouseFlags, short far* Cancel); // [id(6), method]
    void AxisLabelSelected(short far* AxisId, short far* AxisIndex, short far* labelSetIndex, short far* LabelIndex, short far* MouseFlags, short far* Cancel); // [id(7), method]
    void AxisTitleSelected(short far* AxisId, short far* AxisIndex, short far* MouseFlags, short far* Cancel); // [id(8), method]
    void PointSelected(short far* Series, short far* DataPoint, short far* MouseFlags, short far* Cancel); // [id(9), method]
    void PointLabelSelected(short far* Series, short far* DataPoint, short far* MouseFlags, short far* Cancel); // [id(10), method]
    void SeriesSelected(short far* Series, short far* MouseFlags, short far* Cancel); // [id(11), method]
    void SeriesLabelSelected(short far* Series, short far* MouseFlags, short far* Cancel); // [id(12), method]
    void ChartActivated(short far* MouseFlags, short far* Cancel); // [id(13), method]
    void TitleActivated(short far* MouseFlags, short far* Cancel); // [id(14), method]
    void FootnoteActivated(short far* MouseFlags, short far* Cancel); // [id(15), method]
    void LegendActivated(short far* MouseFlags, short far* Cancel); // [id(16), method]
    void PlotActivated(short far* MouseFlags, short far* Cancel); // [id(17), method]
    void AxisActivated(short far* AxisId, short far* AxisIndex, short far* MouseFlags, short far* Cancel); // [id(18), method]
    void AxisLabelActivated(short far* AxisId, short far* AxisIndex, short far* labelSetIndex, short far* LabelIndex, short far* MouseFlags, short far* Cancel); // [id(19), method]
    void AxisTitleActivated(short far* AxisId, short far* AxisIndex, short far* MouseFlags, short far* Cancel); // [id(20), method]
    void PointActivated(short far* Series, short far* DataPoint, short far* MouseFlags, short far* Cancel); // [id(21), method]
    void PointLabelActivated(short far* Series, short far* DataPoint, short far* MouseFlags, short far* Cancel); // [id(22), method]
    void SeriesActivated(short far* Series, short far* MouseFlags, short far* Cancel); // [id(23), method]
    void SeriesLabelActivated(short far* Series, short far* MouseFlags, short far* Cancel); // [id(24), method]
    void Click(); // [id(-600), method]
    void DblClick(); // [id(-601), method]
    void KeyDown(short far* KeyCode, short Shift); // [id(-602), method]
    void KeyPress(short far* KeyAscii); // [id(-603), method]
    void KeyUp(short far* KeyCode, short Shift); // [id(-604), method]
    void MouseDown(short Button, short Shift, OLE_XPOS_PIXELS X, OLE_YPOS_PIXELS Y); // [id(-605), method]
    void MouseMove(short Button, short Shift, OLE_XPOS_PIXELS X, OLE_YPOS_PIXELS Y); // [id(-606), method]
    void MouseUp(short Button, short Shift, OLE_XPOS_PIXELS X, OLE_YPOS_PIXELS Y); // [id(-607), method]
    void ApplyChanges(); // [id(25), method]
};

// TKIND_DISPATCH: ICoor {EBF97E20-731F-11CE-840F-00AA0042CB33}\409 Coor object

class ICoor : public TAutoProxy {
  public:
    ICoor() : TAutoProxy(0x409) {}
    // X coordinate
    float GetX();     // [id(1), prop r/w]
    void SetX(float); // [id(1), prop r/w]
    // Y coordinate
    float GetY();     // [id(2), prop r/w]
    void SetY(float); // [id(2), prop r/w]
    // Sets the x and y coordinate values
    void Set(float X, float Y); // [id(3), method]
};

// TKIND_DISPATCH: ILCoor {EBF97E22-731F-11CE-840F-00AA0042CB33}\409 LCoor object

class ILCoor : public TAutoProxy {
  public:
    ILCoor() : TAutoProxy(0x409) {}
    // X coordinate
    long GetX();     // [id(1), prop r/w]
    void SetX(long); // [id(1), prop r/w]
    // Y coordinate
    long GetY();     // [id(2), prop r/w]
    void SetY(long); // [id(2), prop r/w]
    // Sets the x and y coordinate values
    void Set(long X, long Y); // [id(3), method]
};

// TKIND_DISPATCH: ICoor3 {177BF2A0-7350-11CE-840F-00AA0042CB33}\409 Coor3 object

class ICoor3 : public TAutoProxy {
  public:
    ICoor3() : TAutoProxy(0x409) {}
    // X coordinate
    float GetX();     // [id(1), prop r/w]
    void SetX(float); // [id(1), prop r/w]
    // Y coordinate
    float GetY();     // [id(2), prop r/w]
    void SetY(float); // [id(2), prop r/w]
    // Z coordinate
    float GetZ();     // [id(3), prop r/w]
    void SetZ(float); // [id(3), prop r/w]
    // Sets the x, y and z coordinate values
    void Set(float X, float Y, float Z); // [id(4), method]
};

// TKIND_DISPATCH: ILRect {177BF2A2-7350-11CE-840F-00AA0042CB33}\409 LRect object

class ILRect : public TAutoProxy {
  public:
    ILRect() : TAutoProxy(0x409) {}
    // Minimum LCoor object
    IDispatch* GetMin();     // [id(1), prop r/w]
    void SetMin(IDispatch*); // [id(1), prop r/w]
    // Maximum LCoor object
    IDispatch* GetMax();     // [id(2), prop r/w]
    void SetMax(IDispatch*); // [id(2), prop r/w]
};

// TKIND_DISPATCH: IRect {FE5517C0-73FE-11CE-840F-00AA0042CB33}\409 Rect object

class IRect : public TAutoProxy {
  public:
    IRect() : TAutoProxy(0x409) {}
    // Minimum Coor object
    IDispatch* GetMin();     // [id(1), prop r/w]
    void SetMin(IDispatch*); // [id(1), prop r/w]
    // Maximum Coor object
    IDispatch* GetMax();     // [id(2), prop r/w]
    void SetMax(IDispatch*); // [id(2), prop r/w]
};

// TKIND_DISPATCH: IColor {9BA79C60-7403-11CE-840F-00AA0042CB33}\409 VtColor object

class IColor : public TAutoProxy {
  public:
    IColor() : TAutoProxy(0x409) {}
    // Red value
    short GetRed();     // [id(1), prop r/w]
    void SetRed(short); // [id(1), prop r/w]
    // Green value
    short GetGreen();     // [id(2), prop r/w]
    void SetGreen(short); // [id(2), prop r/w]
    // Blue value
    short GetBlue();     // [id(3), prop r/w]
    void SetBlue(short); // [id(3), prop r/w]
    // Automatic VtColor selection
    bool GetAutomatic();     // [id(4), prop r/w]
    void SetAutomatic(bool); // [id(4), prop r/w]
    // Set red, green, and blue values
    void Set(short Red, short Green, short Blue); // [id(5), method]
};

// TKIND_DISPATCH: IBrush {AFE57020-7409-11CE-840F-00AA0042CB33}\409 Brush object

class IBrush : public TAutoProxy {
  public:
    IBrush() : TAutoProxy(0x409) {}
    // (BrushStyleConstants)
    short GetStyle();     // [id(1), prop r/w]
    void SetStyle(short); // [id(1), prop r/w]
    // Fill VtColor object
    IDispatch* GetFillColor();     // [id(2), prop r/w]
    void SetFillColor(IDispatch*); // [id(2), prop r/w]
    // Pattern VtColor object
    IDispatch* GetPatternColor();     // [id(3), prop r/w]
    void SetPatternColor(IDispatch*); // [id(3), prop r/w]
    // (BrushPatternConstants)
    short GetIndex();     // [id(4), prop r/w]
    void SetIndex(short); // [id(4), prop r/w]
};

// TKIND_DISPATCH: IShadow {AFE57022-7409-11CE-840F-00AA0042CB33}\409 Shadow object

class IShadow : public TAutoProxy {
  public:
    IShadow() : TAutoProxy(0x409) {}
    // Determines whether this shadow object's parent has a shadow. (ShadowStyleConstants)
    short GetStyle();     // [id(1), prop r/w]
    void SetStyle(short); // [id(1), prop r/w]
    // Returns the Brush object associated with this shadow.
    IDispatch* GetBrush();     // [id(2), prop r/w]
    void SetBrush(IDispatch*); // [id(2), prop r/w]
    // Returns the Coor object that describes the distance the shadow is offset from its parent object.
    IDispatch* GetOffset();     // [id(3), prop r/w]
    void SetOffset(IDispatch*); // [id(3), prop r/w]
};

// TKIND_DISPATCH: ITextLayout {E26C7700-756C-11CE-840F-00AA0042CB33}\409 TextLayout object

class ITextLayout : public TAutoProxy {
  public:
    ITextLayout() : TAutoProxy(0x409) {}
    // (HorizontalAlignmentConstants)
    short GetHorzAlignment();     // [id(1), prop r/w]
    void SetHorzAlignment(short); // [id(1), prop r/w]
    // (VerticalAlignmentConstants)
    short GetVertAlignment();     // [id(2), prop r/w]
    void SetVertAlignment(short); // [id(2), prop r/w]
    // (OrientationConstants)
    short GetOrientation();     // [id(3), prop r/w]
    void SetOrientation(short); // [id(3), prop r/w]
    // Text Word Wrap
    bool GetWordWrap();     // [id(4), prop r/w]
    void SetWordWrap(bool); // [id(4), prop r/w]
};

// TKIND_DISPATCH: IVcTitle {C82141A0-7571-11CE-840F-00AA0042CB33}\409 Title object

class IVcTitle : public TAutoProxy {
  public:
    IVcTitle() : TAutoProxy(0x409) {}
    // Text Layout object
    IDispatch* GetTextLayout();     // [id(1), prop r/w]
    void SetTextLayout(IDispatch*); // [id(1), prop r/w]
    // Returns/sets the title text
    TAutoString GetText();     // [id(2), prop r/w]
    void SetText(TAutoString); // [id(2), prop r/w]
    TAutoString Get_Text();     // [id(0), prop r/w, hidden]
    void Set_Text(TAutoString); // [id(0), prop r/w, hidden]
    // Location object
    IDispatch* GetLocation();     // [id(3), prop r/w]
    void SetLocation(IDispatch*); // [id(3), prop r/w]
    // Backdrop object
    IDispatch* GetBackdrop();     // [id(4), prop r/w]
    void SetBackdrop(IDispatch*); // [id(4), prop r/w]
    // Returns the VtFont object associated with this title.
    IDispatch* GetVtFont();     // [id(5), prop r/w]
    void SetVtFont(IDispatch*); // [id(5), prop r/w]
    // Returns the length of the title text.
    short GetTextLength();     // [id(6), prop r/w]
    void SetTextLength(short); // [id(6), prop r/w]
    // Selects the chart title.
    void Select(); // [id(7), method]
};

// TKIND_DISPATCH: ILocation {EDDF9242-764B-11CE-840F-00AA0042CB33}\409 Location object

class ILocation : public TAutoProxy {
  public:
    ILocation() : TAutoProxy(0x409) {}
    // Rect object
    IDispatch* GetRect();     // [id(1), prop r/w]
    void SetRect(IDispatch*); // [id(1), prop r/w]
    // Determines if text is visible
    bool GetVisible();     // [id(2), prop r/w]
    void SetVisible(bool); // [id(2), prop r/w]
    // Determines the position of the text (LocationTypeConstants)
    short GetLocationType();     // [id(3), prop r/w]
    void SetLocationType(short); // [id(3), prop r/w]
};

// TKIND_DISPATCH: IBackdrop {2E6A37A2-77FC-11CE-840F-00AA0042CB33}\409 Backdrop object

class IBackdrop : public TAutoProxy {
  public:
    IBackdrop() : TAutoProxy(0x409) {}
    // Shadow object
    IDispatch* GetShadow();     // [id(1), prop r/w]
    void SetShadow(IDispatch*); // [id(1), prop r/w]
    // Frame object
    IDispatch* GetFrame();     // [id(2), prop r/w]
    void SetFrame(IDispatch*); // [id(2), prop r/w]
    // Fill object
    IDispatch* GetFill();     // [id(3), prop r/w]
    void SetFill(IDispatch*); // [id(3), prop r/w]
};

// TKIND_DISPATCH: IFrame {2E6A37A4-77FC-11CE-840F-00AA0042CB33}\409 Frame object

class IFrame : public TAutoProxy {
  public:
    IFrame() : TAutoProxy(0x409) {}
    // The type of frame (FrameStyleConstants)
    short GetStyle();     // [id(1), prop r/w]
    void SetStyle(short); // [id(1), prop r/w]
    // The VtColor of the frame
    IDispatch* GetFrameColor();     // [id(2), prop r/w]
    void SetFrameColor(IDispatch*); // [id(2), prop r/w]
    // The VtColor of the space between frames
    IDispatch* GetSpaceColor();     // [id(3), prop r/w]
    void SetSpaceColor(IDispatch*); // [id(3), prop r/w]
    // The width, in points, of the frame
    float GetWidth();     // [id(4), prop r/w]
    void SetWidth(float); // [id(4), prop r/w]
};

// TKIND_DISPATCH: IGradient {2E6A37A6-77FC-11CE-840F-00AA0042CB33}\409 Gradient object

class IGradient : public TAutoProxy {
  public:
    IGradient() : TAutoProxy(0x409) {}
    // The type of gradient (GradientStyleConstants)
    short GetStyle();     // [id(1), prop r/w]
    void SetStyle(short); // [id(1), prop r/w]
    // The starting VtColor used to make the gradient
    IDispatch* GetFromColor();     // [id(2), prop r/w]
    void SetFromColor(IDispatch*); // [id(2), prop r/w]
    // The ending VtColor used to make the gradient
    IDispatch* GetToColor();     // [id(3), prop r/w]
    void SetToColor(IDispatch*); // [id(3), prop r/w]
};

// TKIND_DISPATCH: IFill {FD30FB02-789C-11CE-840F-00AA0042CB33}\409 Fill object

class IFill : public TAutoProxy {
  public:
    IFill() : TAutoProxy(0x409) {}
    // The type of fill. (FillStyleConstants)
    short GetStyle();     // [id(1), prop r/w]
    void SetStyle(short); // [id(1), prop r/w]
    // Brush object that describes the brush used in a brush style fill.
    IDispatch* GetBrush();     // [id(2), prop r/w]
    void SetBrush(IDispatch*); // [id(2), prop r/w]
    // Gradient object that describes the gradient used in a gradient style fill
    IDispatch* GetGradient();     // [id(3), prop r/w]
    void SetGradient(IDispatch*); // [id(3), prop r/w]
    // VtPicture object that describes a graphic used in the fill.
    IDispatch* GetVtPicture();     // [id(4), prop r/w]
    void SetVtPicture(IDispatch*); // [id(4), prop r/w]
};

// TKIND_DISPATCH: IVcPen {279B5A40-8098-11CE-BECC-00AA0042CB33}\409 Pen object

class IVcPen : public TAutoProxy {
  public:
    IVcPen() : TAutoProxy(0x409) {}
    // The type of line (PenStyleConstants)
    short GetStyle();     // [id(1), prop r/w]
    void SetStyle(short); // [id(1), prop r/w]
    // Defines how line segments are joined (PenJoinConstants)
    short GetJoin();     // [id(2), prop r/w]
    void SetJoin(short); // [id(2), prop r/w]
    // Defines how line ends are capped (PenCapConstants)
    short GetCap();     // [id(3), prop r/w]
    void SetCap(short); // [id(3), prop r/w]
    // The VtColor used to draw the line
    IDispatch* GetVtColor();     // [id(4), prop r/w]
    void SetVtColor(IDispatch*); // [id(4), prop r/w]
    // Defines the width, in points, of the line
    float GetWidth();     // [id(5), prop r/w]
    void SetWidth(float); // [id(5), prop r/w]
    // Defines the joint limit as a multiple of the line width
    float GetLimit();     // [id(6), prop r/w]
    void SetLimit(float); // [id(6), prop r/w]
};

// TKIND_DISPATCH: IVcMarker {3080E742-813F-11CE-BECC-00AA0042CB33}\409 Marker object

class IVcMarker : public TAutoProxy {
  public:
    IVcMarker() : TAutoProxy(0x409) {}
    // Determines if marker is visible
    bool GetVisible();     // [id(1), prop r/w]
    void SetVisible(bool); // [id(1), prop r/w]
    // The type of marker (MarkerStyleConstants)
    short GetStyle();     // [id(2), prop r/w]
    void SetStyle(short); // [id(2), prop r/w]
    // The pen used to draw marker outline
    IDispatch* GetPen();     // [id(3), prop r/w]
    void SetPen(IDispatch*); // [id(3), prop r/w]
    // Size of the marker in points
    float GetSize();     // [id(4), prop r/w]
    void SetSize(float); // [id(4), prop r/w]
    // VtColor used to fill the marker
    IDispatch* GetFillColor();     // [id(5), prop r/w]
    void SetFillColor(IDispatch*); // [id(5), prop r/w]
    // VtPicture used for marker
    IDispatch* GetVtPicture();     // [id(6), prop r/w]
    void SetVtPicture(IDispatch*); // [id(6), prop r/w]
};

// TKIND_DISPATCH: IVcFootnote {4F053F00-8396-11CE-BECC-00AA0042CB33}\409 Footnote object

class IVcFootnote : public TAutoProxy {
  public:
    IVcFootnote() : TAutoProxy(0x409) {}
    // Text Layout object
    IDispatch* GetTextLayout();     // [id(1), prop r/w]
    void SetTextLayout(IDispatch*); // [id(1), prop r/w]
    // Location object
    IDispatch* GetLocation();     // [id(2), prop r/w]
    void SetLocation(IDispatch*); // [id(2), prop r/w]
    // Backdrop object
    IDispatch* GetBackdrop();     // [id(3), prop r/w]
    void SetBackdrop(IDispatch*); // [id(3), prop r/w]
    // VtFont object
    IDispatch* GetVtFont();     // [id(4), prop r/w]
    void SetVtFont(IDispatch*); // [id(4), prop r/w]
    // Returns/sets the footnote text
    TAutoString GetText();     // [id(5), prop r/w]
    void SetText(TAutoString); // [id(5), prop r/w]
    TAutoString Get_Text();     // [id(0), prop r/w, hidden]
    void Set_Text(TAutoString); // [id(0), prop r/w, hidden]
    // Returns the length of the footnote text.
    short GetTextLength();     // [id(6), prop r/w]
    void SetTextLength(short); // [id(6), prop r/w]
    // Selects the chart footnote.
    void Select(); // [id(7), method]
};

// TKIND_DISPATCH: IVcLegend {95C52B60-83B1-11CE-BECC-00AA0042CB33}\409 Legend object

class IVcLegend : public TAutoProxy {
  public:
    IVcLegend() : TAutoProxy(0x409) {}
    // Returns the Location object associated with the chart legend.
    IDispatch* GetLocation();     // [id(1), prop r/w]
    void SetLocation(IDispatch*); // [id(1), prop r/w]
    // Returns the Backdrop object associated with the chart legend.
    IDispatch* GetBackdrop();     // [id(2), prop r/w]
    void SetBackdrop(IDispatch*); // [id(2), prop r/w]
    // Returns the VtFont object associated with the chart legend.
    IDispatch* GetVtFont();     // [id(3), prop r/w]
    void SetVtFont(IDispatch*); // [id(3), prop r/w]
    // Returns the TextLayout object associated with the chart legend.
    IDispatch* GetTextLayout();     // [id(4), prop r/w]
    void SetTextLayout(IDispatch*); // [id(4), prop r/w]
    // Selects the chart legend.
    void Select(); // [id(5), method]
};

// TKIND_DISPATCH: IVcPrintInformation {CFA0AC00-8B6E-11CE-840F-00AA0042CB33}\409 PrintInformation object

class IVcPrintInformation : public TAutoProxy {
  public:
    IVcPrintInformation() : TAutoProxy(0x409) {}
    // Specifies how the chart is scaled to fit on the page. (PrintScaleTypeConstants)
    short GetScaleType();     // [id(1), prop r/w]
    void SetScaleType(short); // [id(1), prop r/w]
    // The direction in which the chart is printed on the page. (PrintOrientationTypeConstants)
    short GetOrientation();     // [id(2), prop r/w]
    void SetOrientation(short); // [id(2), prop r/w]
    // The amount of white space at the edges of the paper.
    float GetTopMargin();     // [id(3), prop r/w]
    void SetTopMargin(float); // [id(3), prop r/w]
    // The amount of white space at the edges of the paper.
    float GetBottomMargin();     // [id(4), prop r/w]
    void SetBottomMargin(float); // [id(4), prop r/w]
    // The amount of white space at the edges of the paper.
    float GetLeftMargin();     // [id(5), prop r/w]
    void SetLeftMargin(float); // [id(5), prop r/w]
    // The amount of white space at the edges of the paper.
    float GetRightMargin();     // [id(6), prop r/w]
    void SetRightMargin(float); // [id(6), prop r/w]
    // The horizontal position of the chart on a page.
    bool GetCenterHorizontally();     // [id(7), prop r/w]
    void SetCenterHorizontally(bool); // [id(7), prop r/w]
    // The vertical position of the chart on a page.
    bool GetCenterVertically();     // [id(8), prop r/w]
    void SetCenterVertically(bool); // [id(8), prop r/w]
    // Currently unused.
    bool GetMonochrome();     // [id(9), prop r/w]
    void SetMonochrome(bool); // [id(9), prop r/w]
    // Specifies whether the chart is re-laid out to best fit onto the page.
    bool GetLayoutForPrinter();     // [id(10), prop r/w]
    void SetLayoutForPrinter(bool); // [id(10), prop r/w]
    // Print a number of copies.
    void PrintCopies(short NumberCopies); // [id(11), method]
};

// TKIND_DISPATCH: IVcDataGrid {6CB603A0-8F70-11CE-840F-00AA0042CB33}\409 DataGrid object

class IVcDataGrid : public TAutoProxy {
  public:
    IVcDataGrid() : TAutoProxy(0x409) {}
    // Returns/sets the number of data columns in the data grid.
    short GetColumnCount();     // [id(1), prop r/w]
    void SetColumnCount(short); // [id(1), prop r/w]
    // Returns/sets the number of levels of labels on data columns in the data grid.
    short GetColumnLabelCount();     // [id(2), prop r/w]
    void SetColumnLabelCount(short); // [id(2), prop r/w]
    // Returns/sets the number of levels of labels on data rows in the data grid.
    short GetRowLabelCount();     // [id(3), prop r/w]
    void SetRowLabelCount(short); // [id(3), prop r/w]
    // Returns/sets the number of data rows in the data grid.
    short GetRowCount();     // [id(4), prop r/w]
    void SetRowCount(short); // [id(4), prop r/w]
    // Deletes columns of data and their associated labels from the data grid.
    void DeleteColumns(short Column, short Count); // [id(5), method]
    // Adds one or more data columns to the data grid.
    void InsertColumns(short Column, short Count); // [id(6), method]
    // Deletes levels of labels from the data columns in a data grid.
    void DeleteColumnLabels(short LabelIndex, short Count); // [id(7), method]
    // Adds one or more levels of labels to the data columns in the data grid.
    void InsertColumnLabels(short LabelIndex, short Count); // [id(8), method]
    // Deletes rows of data and their associated labels from the data grid.
    void DeleteRows(short Row, short Count); // [id(9), method]
    // Adds one or more data rows to the data grid.
    void InsertRows(short Row, short Count); // [id(10), method]
    // Deletes levels of labels from the data rows in a data grid.
    void DeleteRowLabels(short LabelIndex, short Count); // [id(11), method]
    // Adds one or more levels of labels to the data rows in the data grid.
    void InsertRowLabels(short LabelIndex, short Count); // [id(12), method]
    // Fills the data grid with randomly generated data.
    void RandomDataFill(); // [id(13), method]
    // Sets the number and levels of data columns and rows.
    void SetSize(short RowLabelCount, short ColumnLabelCount, short DataRowCount, short DataColumnCount); // [id(14), method]
    // Assigns each label in the first level of data grid labels a unique identifier.
    void InitializeLabels(); // [id(15), method]
    // Returns/sets the label on a data column in the grid.
    TAutoString GetColumnLabel(short Column, short LabelIndex); // [id(21), propget]
    // Returns/sets the label on a data column in the grid.
    void SetColumnLabel(short, short Column, TAutoString LabelIndex); // [id(21), propset]
    // Returns the multi-level label that identifies a column in the data grid.
    TAutoString GetCompositeColumnLabel(short Column); // [id(22), propget]
    // Returns the multi-level label that identifies a row in the data grid.
    TAutoString GetCompositeRowLabel(short Row); // [id(23), propget]
    // Returns/sets the label associated with a row in a data grid.
    TAutoString GetRowLabel(short Row, short LabelIndex); // [id(24), propget]
    // Returns/sets the label associated with a row in a data grid.
    void SetRowLabel(short, short Row, TAutoString LabelIndex); // [id(24), propset]
    // Fills one or more columns of the data grid with randomly generated data.
    void RandomFillColumns(short Column, short Count); // [id(16), method]
    // Fills one or more rows of the data grid with randomly generated data.
    void RandomFillRows(short Row, short Count); // [id(17), method]
    // Moves a block of cells on the data grid.
    void MoveData(short Top, short Left, short Bottom, short Right, short OverOffset, short DownOffset); // [id(18), method]
    // Gets the value of a datagrid cell.
    void GetData(short Row, short Column, double far* DataPoint, short far* nullFlag); // [id(19), method]
    // Sets the value of a datagrid cell.
    void SetData(short Row, short Column, double DataPoint, short nullFlag); // [id(20), method]
};

// TKIND_DISPATCH: IVcPlot {F77BA680-9037-11CE-86B3-444553540000}\409 Plot object

class IVcPlot : public TAutoProxy {
  public:
    IVcPlot() : TAutoProxy(0x409) {}
    // Returns/sets the unit of measure used for all chart angles. (AngleUnitsConstants)
    short GetAngleUnit();     // [id(1), prop r/w]
    void SetAngleUnit(short); // [id(1), prop r/w]
    // Determines whether pie, doughnut, polar, and radar charts are drawn in a clockwise or counterclockwise direction.
    bool GetClockwise();     // [id(2), prop r/w]
    void SetClockwise(bool); // [id(2), prop r/w]
    // Returns/sets the order in which the slices of a pie or doughnut are drawn. (SortTypeConstants)
    short GetSort();     // [id(3), prop r/w]
    void SetSort(short); // [id(3), prop r/w]
    // Returns/sets the percentage of the shortest chart axis that is used as the diameter of the largest bubble.
    float GetMaxBubbleToAxisRatio();     // [id(4), prop r/w]
    void SetMaxBubbleToAxisRatio(float); // [id(4), prop r/w]
    // Returns the Backdrop object associated with the chart plot.
    IDispatch* GetBackdrop();     // [id(5), prop r/w]
    void SetBackdrop(IDispatch*); // [id(5), prop r/w]
    // Returns the Coor3 object which indicates the distance and position from which a 3D chart is viewed.
    IDispatch* GetPerspective();     // [id(6), prop r/w]
    void SetPerspective(IDispatch*); // [id(6), prop r/w]
    // Returns/sets the angle at which the scale appears on a polar or radar chart.
    float GetScaleAngle();     // [id(7), prop r/w]
    void SetScaleAngle(float); // [id(7), prop r/w]
    // Returns/sets the starting angle used to draw pie, doughnut, polar, and radar charts.
    float GetStartingAngle();     // [id(8), prop r/w]
    void SetStartingAngle(float); // [id(8), prop r/w]
    // Returns/sets the position used to display a label on each pie or doughnut in the chart. (SubPlotLabelLocationTypeConstants)
    short GetSubPlotLabelPosition();     // [id(9), prop r/w]
    void SetSubPlotLabelPosition(short); // [id(9), prop r/w]
    // Returns/sets the spacing of 2D and 3D bars in the chart.
    float GetBarGap();     // [id(10), prop r/w]
    void SetBarGap(float); // [id(10), prop r/w]
    // Returns/sets the x spacing of 3D bars in the chart.
    float GetxGap();     // [id(11), prop r/w]
    void SetxGap(float); // [id(11), prop r/w]
    // Determines whether the plot is in automatic layout mode.
    bool GetAutoLayout();     // [id(12), prop r/w]
    void SetAutoLayout(bool); // [id(12), prop r/w]
    // Returns/sets the percentage of the chart height to be used as the chart width.
    float GetWidthToHeightRatio();     // [id(13), prop r/w]
    void SetWidthToHeightRatio(float); // [id(13), prop r/w]
    // Returns/sets the percentage of the chart height to be used as the chart depth.
    float GetDepthToHeightRatio();     // [id(14), prop r/w]
    void SetDepthToHeightRatio(float); // [id(14), prop r/w]
    // Returns the Rect object which indicates the position of the plot area of the chart.
    IDispatch* GetLocationRect();     // [id(15), prop r/w]
    void SetLocationRect(IDispatch*); // [id(15), prop r/w]
    // Returns/sets the projection type used to display a 3D chart on a 2D output device. (ProjectionTypeConstants)
    short GetProjection();     // [id(16), prop r/w]
    void SetProjection(short); // [id(16), prop r/w]
    // Returns/sets the z spacing of 3D bars in the chart.
    float GetzGap();     // [id(17), prop r/w]
    void SetzGap(float); // [id(17), prop r/w]
    // Returns the View3d object which indicates the rotation and elevation used to display a 3D chart.
    IDispatch* GetView3d();     // [id(18), prop r/w]
    void SetView3d(IDispatch*); // [id(18), prop r/w]
    // Returns the PlotBase object associated with this chart plot.
    IDispatch* GetPlotBase();     // [id(19), prop r/w]
    void SetPlotBase(IDispatch*); // [id(19), prop r/w]
    // Returns the Doughnut object associated with this chart plot.
    IDispatch* GetDoughnut();     // [id(20), prop r/w]
    void SetDoughnut(IDispatch*); // [id(20), prop r/w]
    // Returns the Pie object associated with this chart plot.
    IDispatch* GetPie();     // [id(21), prop r/w]
    void SetPie(IDispatch*); // [id(21), prop r/w]
    // Returns the Weighting object associated with this chart plot.
    IDispatch* GetWeighting();     // [id(22), prop r/w]
    void SetWeighting(IDispatch*); // [id(22), prop r/w]
    // Returns the Wall object associated with this chart plot.
    IDispatch* GetWall();     // [id(23), prop r/w]
    void SetWall(IDispatch*); // [id(23), prop r/w]
    // Returns the Elevation object associated with this chart plot.
    IDispatch* GetElevation();     // [id(24), prop r/w]
    void SetElevation(IDispatch*); // [id(24), prop r/w]
    // Series Collection
    IDispatch* GetSeriesCollection();     // [id(25), prop r/w]
    void SetSeriesCollection(IDispatch*); // [id(25), prop r/w]
    // Indicates whether series data is being read from a row rather  than a column in a data grid.
    bool GetDataSeriesInRow();     // [id(26), prop r/w]
    void SetDataSeriesInRow(bool); // [id(26), prop r/w]
    // The light source illuminating a chart.
    IDispatch* GetLight();     // [id(27), prop r/w]
    void SetLight(IDispatch*); // [id(27), prop r/w]
    // The point at which the axes of a 3D XYZ chart intersect.
    IDispatch* GetXYZ();     // [id(28), prop r/w]
    void SetXYZ(IDispatch*); // [id(28), prop r/w]
    // Returns/sets the type of percentage used to plot chart values oin a percent axis.
    short GetDefaultPercentBasis();     // [id(29), prop r/w]
    void SetDefaultPercentBasis(short); // [id(29), prop r/w]
    // Specifies whether or not the unit scale for all value axes in a chart is uniform.
    bool GetUniformAxis();     // [id(30), prop r/w]
    void SetUniformAxis(bool); // [id(30), prop r/w]
    // Returns the Axis object associated with this chart plot.
    IDispatch* GetAxis(short AxisId, TAutoVal& Index); // [id(31), propget]
};

// TKIND_DISPATCH: IVcView3d {21645F62-90F0-11CE-86B3-444553540000}\409 View3d object

class IVcView3d : public TAutoProxy {
  public:
    IVcView3d() : TAutoProxy(0x409) {}
    // Returns/sets the degree of rotation from which the chart is viewed.
    float GetRotation();     // [id(1), prop r/w]
    void SetRotation(float); // [id(1), prop r/w]
    // Returns/sets the degree of elevation from which the chart is viewed.
    float GetElevation();     // [id(2), prop r/w]
    void SetElevation(float); // [id(2), prop r/w]
    // Sets the rotation and elevation used to display the chart.
    void Set(float Rotation, float Elevation); // [id(4), method]
};

// TKIND_DISPATCH: IVcPlotBase {508D02E0-90FC-11CE-86B3-444553540000}\409 PlotBase object

class IVcPlotBase : public TAutoProxy {
  public:
    IVcPlotBase() : TAutoProxy(0x409) {}
    // Returns/sets the height of the chart base in points.
    float GetBaseHeight();     // [id(1), prop r/w]
    void SetBaseHeight(float); // [id(1), prop r/w]
    // Returns the brush object associated with the chart base.
    IDispatch* GetBrush();     // [id(2), prop r/w]
    void SetBrush(IDispatch*); // [id(2), prop r/w]
    // Returns the pen object associated with the pen base.
    IDispatch* GetPen();     // [id(3), prop r/w]
    void SetPen(IDispatch*); // [id(3), prop r/w]
};

// TKIND_DISPATCH: IVcDoughnut {508D02E2-90FC-11CE-86B3-444553540000}\409 Doughnut object

class IVcDoughnut : public TAutoProxy {
  public:
    IVcDoughnut() : TAutoProxy(0x409) {}
    // Returns/sets the number of sides used to draw the doughnut.
    short GetSides();     // [id(1), prop r/w]
    void SetSides(short); // [id(1), prop r/w]
    // Returns/sets the ratio of the radius of the doughnut that is used to display the interior "hole"inthedoughnut.
    float GetInteriorRatio();     // [id(2), prop r/w]
    void SetInteriorRatio(float); // [id(2), prop r/w]
    // Sets the attributes used to display a doughnut chart.
    void Set(float InteriorRatio, short Sides); // [id(3), method]
};

// TKIND_DISPATCH: IVcPie {508D02E4-90FC-11CE-86B3-444553540000}\409 Pie object

class IVcPie : public TAutoProxy {
  public:
    IVcPie() : TAutoProxy(0x409) {}
    // Returns/sets the percentage of a pie radius that is used to determine the height of a 3D pie.
    float GetThicknessRatio();     // [id(1), prop r/w]
    void SetThicknessRatio(float); // [id(1), prop r/w]
    // Returns/sets the percentage of a pie radius that is used to determine the size of the top of the 3D pie.
    float GetTopRadiusRatio();     // [id(2), prop r/w]
    void SetTopRadiusRatio(float); // [id(2), prop r/w]
    // Sets the attributes used to display pie charts.
    void Set(float ThicknessRatio, float TopRadiusRation); // [id(3), method]
};

// TKIND_DISPATCH: IVcWeighting {508D02E6-90FC-11CE-86B3-444553540000}\409 Weighting object

class IVcWeighting : public TAutoProxy {
  public:
    IVcWeighting() : TAutoProxy(0x409) {}
    // Returns/sets the type of weighting used to determine pie or doughnut size. (PieWeightBasisConstants)
    short GetBasis();     // [id(1), prop r/w]
    void SetBasis(short); // [id(1), prop r/w]
    // Determines how the weighting factor is applied. (PieWeightStyleConstants)
    short GetStyle();     // [id(2), prop r/w]
    void SetStyle(short); // [id(2), prop r/w]
    // Sets the size of each 2D or 3D pie or doughnut in relation to other pies or doughnuts in the same chart.
    void Set(short Basis, short Style); // [id(3), method]
};

// TKIND_DISPATCH: IVcWall {508D02E8-90FC-11CE-86B3-444553540000}\409 Wall object

class IVcWall : public TAutoProxy {
  public:
    IVcWall() : TAutoProxy(0x409) {}
    // Returns/sets the thickness of the walls of a 3D chart, in points.
    float GetWidth();     // [id(1), prop r/w]
    void SetWidth(float); // [id(1), prop r/w]
    // Returns the Brush object associated with the chart wall.
    IDispatch* GetBrush();     // [id(2), prop r/w]
    void SetBrush(IDispatch*); // [id(2), prop r/w]
    // Returns the Pen object associated with the chart wall.
    IDispatch* GetPen();     // [id(3), prop r/w]
    void SetPen(IDispatch*); // [id(3), prop r/w]
};

// TKIND_DISPATCH: IVcSeries {0AA0FE20-912A-11CE-86B3-444553540000}\409 Series object

class IVcSeries : public TAutoProxy {
  public:
    IVcSeries() : TAutoProxy(0x409) {}
    // Determines whether a series is charted on the secondary Y axis.
    bool GetSecondaryAxis();     // [id(1), prop r/w]
    void SetSecondaryAxis(bool); // [id(1), prop r/w]
    // Returns/sets the type of mathematical function used to smooth the series. (SmoothingTypeConstants)
    short GetSmoothingType();     // [id(2), prop r/w]
    void SetSmoothingType(short); // [id(2), prop r/w]
    // Returns/sets the number of facets or points that are sampled between the chart data points to create the smoothing effect.
    short GetSmoothingFactor();     // [id(3), prop r/w]
    void SetSmoothingFactor(short); // [id(3), prop r/w]
    // Returns/sets the chart type being used to display this series in the chart. (SeriesTypeConstants)
    short GetSeriesType();     // [id(4), prop r/w]
    void SetSeriesType(short); // [id(4), prop r/w]
    // Returns the Pen object associated with this series guidelines.
    IDispatch* GetGuideLinePen();     // [id(5), prop r/w]
    void SetGuideLinePen(IDispatch*); // [id(5), prop r/w]
    // Determines whether the guidelines are displayed for a series.
    bool GetShowLine();     // [id(6), prop r/w]
    void SetShowLine(bool); // [id(6), prop r/w]
    // Returns the Pen object associated with this series.
    IDispatch* GetPen();     // [id(7), prop r/w]
    void SetPen(IDispatch*); // [id(7), prop r/w]
    // Returns the Bar object associated with this series.
    IDispatch* GetBar();     // [id(8), prop r/w]
    void SetBar(IDispatch*); // [id(8), prop r/w]
    // Returns the HiLo object associated with this series.
    IDispatch* GetHiLo();     // [id(9), prop r/w]
    void SetHiLo(IDispatch*); // [id(9), prop r/w]
    // Returns the Position object associated with this series.
    IDispatch* GetPosition();     // [id(10), prop r/w]
    void SetPosition(IDispatch*); // [id(10), prop r/w]
    // Returns the SeriesMarker object associated with this series.
    IDispatch* GetSeriesMarker();     // [id(11), prop r/w]
    void SetSeriesMarker(IDispatch*); // [id(11), prop r/w]
    // Returns the SeriesLabel object associated with this series.
    IDispatch* GetSeriesLabel();     // [id(12), prop r/w]
    void SetSeriesLabel(IDispatch*); // [id(12), prop r/w]
    // Returns the StatLine object associated with this series.
    IDispatch* GetStatLine();     // [id(13), prop r/w]
    void SetStatLine(IDispatch*); // [id(13), prop r/w]
    // A collection of datapoints on a chart.
    IDispatch* GetDataPoints();     // [id(14), prop r/w]
    void SetDataPoints(IDispatch*); // [id(14), prop r/w]
    // Sets or returns the text in the that identifies the series in the legend.
    TAutoString GetLegendText();     // [id(15), prop r/w]
    void SetLegendText(TAutoString); // [id(15), prop r/w]
    TAutoString Get_LegendText();     // [id(0), prop r/w, hidden]
    void Set_LegendText(TAutoString); // [id(0), prop r/w, hidden]
    // Determines whether the guidelines are displayed for a series.
    bool GetShowGuideLine(short AxisId); // [id(17), propget]
    // Determines whether the guidelines are displayed for a series.
    void SetShowGuideLine(short, bool AxisId); // [id(17), propset]
    // Selects a chart series.
    void Select(); // [id(16), method]
    // Returns the series type used to draw the series if chart type is set to ChartType.
    short GetTypeByChartType(short ChartType); // [id(18), propget]
};

// TKIND_DISPATCH: IVcBar {264931C0-91F1-11CE-840F-00AA0042CB33}\409 Bar object

class IVcBar : public TAutoProxy {
  public:
    IVcBar() : TAutoProxy(0x409) {}
    // Returns/sets the number of sides displayed on the bar.
    short GetSides();     // [id(1), prop r/w]
    void SetSides(short); // [id(1), prop r/w]
    // Returns/sets the percentage of the base size that is used to draw the top of the bar.
    float GetTopRatio();     // [id(2), prop r/w]
    void SetTopRatio(float); // [id(2), prop r/w]
};

// TKIND_DISPATCH: IVcHiLo {51DCC620-95B7-11CE-86B3-444553540000}\409 HiLo object

class IVcHiLo : public TAutoProxy {
  public:
    IVcHiLo() : TAutoProxy(0x409) {}
    // Returns the VtColor object used to show elements that have gained value.
    IDispatch* GetGainColor();     // [id(1), prop r/w]
    void SetGainColor(IDispatch*); // [id(1), prop r/w]
    // Returns the VtColor object used to show elements that have lost value.
    IDispatch* GetLossColor();     // [id(2), prop r/w]
    void SetLossColor(IDispatch*); // [id(2), prop r/w]
};

// TKIND_DISPATCH: IVcPosition {51DCC622-95B7-11CE-86B3-444553540000}\409 Position object

class IVcPosition : public TAutoProxy {
  public:
    IVcPosition() : TAutoProxy(0x409) {}
    // Determines whether a series is included on the chart.
    bool GetExcluded();     // [id(1), prop r/w]
    void SetExcluded(bool); // [id(1), prop r/w]
    // Determines whether a series is displayed on the chart.
    bool GetHidden();     // [id(2), prop r/w]
    void SetHidden(bool); // [id(2), prop r/w]
    // Returns/sets the position of the series in the chart.
    short GetOrder();     // [id(3), prop r/w]
    void SetOrder(short); // [id(3), prop r/w]
    // Returns/sets position in which the current series is drawn if it is stacked with other series.
    short GetStackOrder();     // [id(4), prop r/w]
    void SetStackOrder(short); // [id(4), prop r/w]
};

// TKIND_DISPATCH: IVcSeriesMarker {51DCC624-95B7-11CE-86B3-444553540000}\409 SeriesMarker object

class IVcSeriesMarker : public TAutoProxy {
  public:
    IVcSeriesMarker() : TAutoProxy(0x409) {}
    // Determines whether First Impression automatically assigns the next available marker type to all data points in the series.
    bool GetAuto();     // [id(1), prop r/w]
    void SetAuto(bool); // [id(1), prop r/w]
    // Stores the display status of markers on a chart.
    bool GetShow();     // [id(2), prop r/w]
    void SetShow(bool); // [id(2), prop r/w]
};

// TKIND_DISPATCH: IVcSeriesLabel {51DCC626-95B7-11CE-86B3-444553540000}\409 SeriesLabel object

class IVcSeriesLabel : public TAutoProxy {
  public:
    IVcSeriesLabel() : TAutoProxy(0x409) {}
    // Returns/sets the information you want to display as the label for this series.
    TAutoString GetText();     // [id(1), prop r/w]
    void SetText(TAutoString); // [id(1), prop r/w]
    TAutoString Get_Text();     // [id(0), prop r/w, hidden]
    void Set_Text(TAutoString); // [id(0), prop r/w, hidden]
    // Returns/sets the standard position used to display the series label. (LocationTypeConstants)
    short GetLocationType();     // [id(2), prop r/w]
    void SetLocationType(short); // [id(2), prop r/w]
    // Returns/sets the type of line used to connect a series to a label. (LabelLineStyleConstants)
    short GetLineStyle();     // [id(3), prop r/w]
    void SetLineStyle(short); // [id(3), prop r/w]
    // Returns the Coor object identifying the distance that the label is moved from one of the standard label positions.
    IDispatch* GetOffset();     // [id(4), prop r/w]
    void SetOffset(IDispatch*); // [id(4), prop r/w]
    // Returns the Backdrop object associated with this series label.
    IDispatch* GetBackdrop();     // [id(5), prop r/w]
    void SetBackdrop(IDispatch*); // [id(5), prop r/w]
    // Returns the VtFont object associated with this series label.
    IDispatch* GetVtFont();     // [id(6), prop r/w]
    void SetVtFont(IDispatch*); // [id(6), prop r/w]
    // Returns the TextLayout object associated with this series label.
    IDispatch* GetTextLayout();     // [id(7), prop r/w]
    void SetTextLayout(IDispatch*); // [id(7), prop r/w]
    // Returns the length of the series label text.
    short GetTextLength();     // [id(8), prop r/w]
    void SetTextLength(short); // [id(8), prop r/w]
};

// TKIND_DISPATCH: IVcStatLines {2F6DD6A0-95E5-11CE-86B3-444553540000}\409 StatLine object

class IVcStatLines : public TAutoProxy {
  public:
    IVcStatLines() : TAutoProxy(0x409) {}
    // Determines which statistic lines are being displayed for a series. (StatTypeConstants)
    short GetFlag();     // [id(1), prop r/w]
    void SetFlag(short); // [id(1), prop r/w]
    // Returns the VtColor object associated with this statistic line.
    IDispatch* GetVtColor();     // [id(2), prop r/w]
    void SetVtColor(IDispatch*); // [id(2), prop r/w]
    // Returns/sets the thickness of the statistics line, in points.
    float GetWidth();     // [id(3), prop r/w]
    void SetWidth(float); // [id(3), prop r/w]
    // Returns/sets the line type used to display the statistic line.
    short GetStyle(short Type); // [id(4), propget]
    // Returns/sets the line type used to display the statistic line.
    void SetStyle(short, short Type); // [id(4), propset]
};

// TKIND_DISPATCH: IVcDataPointLabel {2F6DD6A2-95E5-11CE-86B3-444553540000}\409 DataPointLabel object

class IVcDataPointLabel : public TAutoProxy {
  public:
    IVcDataPointLabel() : TAutoProxy(0x409) {}
    // Returns/sets the point label text.
    TAutoString GetText();     // [id(1), prop r/w]
    void SetText(TAutoString); // [id(1), prop r/w]
    TAutoString Get_Text();     // [id(0), prop r/w, hidden]
    void Set_Text(TAutoString); // [id(0), prop r/w, hidden]
    // Returns the Backdrop object associated with this data point label.
    IDispatch* GetBackdrop();     // [id(2), prop r/w]
    void SetBackdrop(IDispatch*); // [id(2), prop r/w]
    // Returns the VtFont object associated with this data point label.
    IDispatch* GetVtFont();     // [id(3), prop r/w]
    void SetVtFont(IDispatch*); // [id(3), prop r/w]
    // Returns the Coor object which describes the offset of the data point label from one of the predefined label positions.
    IDispatch* GetOffset();     // [id(4), prop r/w]
    void SetOffset(IDispatch*); // [id(4), prop r/w]
    // Returns the TextLayout object associated with this data point label.
    IDispatch* GetTextLayout();     // [id(5), prop r/w]
    void SetTextLayout(IDispatch*); // [id(5), prop r/w]
    // Returns/sets the standard position used to display the label. (LocationTypeConstants)
    short GetLocationType();     // [id(6), prop r/w]
    void SetLocationType(short); // [id(6), prop r/w]
    // Determines whether custom text is used to label the data point.
    bool GetCustom();     // [id(7), prop r/w]
    void SetCustom(bool); // [id(7), prop r/w]
    // Returns/sets the type of label to be used to identify the point. (LabelComponentConstants)
    short GetComponent();     // [id(8), prop r/w]
    void SetComponent(short); // [id(8), prop r/w]
    // Returns/sets the type of line used to connect a pie slice to a label displayed outside the slice. (LabelLineStyleConstants)
    short GetLineStyle();     // [id(9), prop r/w]
    void SetLineStyle(short); // [id(9), prop r/w]
    // Returns/sets the format used to display the label as a value.
    TAutoString GetValueFormat();     // [id(10), prop r/w]
    void SetValueFormat(TAutoString); // [id(10), prop r/w]
    // Returns/sets the format used to display the label as a percent.
    TAutoString GetPercentFormat();     // [id(11), prop r/w]
    void SetPercentFormat(TAutoString); // [id(11), prop r/w]
    // Returns the length of the data point label text.
    short GetTextLength();     // [id(12), prop r/w]
    void SetTextLength(short); // [id(12), prop r/w]
    // Resets any custom attributes placed on a data point label to the series default.
    void ResetCustomLabel(); // [id(13), method]
    // Selects a data point label.
    void Select(); // [id(14), method]
};

// TKIND_DISPATCH: IVcDataPoint {2F6DD6A4-95E5-11CE-86B3-444553540000}\409 DataPoint object

class IVcDataPoint : public TAutoProxy {
  public:
    IVcDataPoint() : TAutoProxy(0x409) {}
    // Returns the DataPointLabel object associated with this data point.
    IDispatch* GetDataPointLabel();     // [id(1), prop r/w]
    void SetDataPointLabel(IDispatch*); // [id(1), prop r/w]
    // Returns the Brush object associated with this data point.
    IDispatch* GetBrush();     // [id(2), prop r/w]
    void SetBrush(IDispatch*); // [id(2), prop r/w]
    // Returns the Pen object used to draw the edge of the data point.
    IDispatch* GetEdgePen();     // [id(3), prop r/w]
    void SetEdgePen(IDispatch*); // [id(3), prop r/w]
    // Returns the Marker object associated with this data point.
    IDispatch* GetMarker();     // [id(4), prop r/w]
    void SetMarker(IDispatch*); // [id(4), prop r/w]
    // Returns/sets how far the pie slice representing this data point is offset or pulled away from the pie.
    float GetOffset();     // [id(5), prop r/w]
    void SetOffset(float); // [id(5), prop r/w]
    // Returns the VtPicture object associated with this data point.
    IDispatch* GetVtPicture();     // [id(6), prop r/w]
    void SetVtPicture(IDispatch*); // [id(6), prop r/w]
    // Resets any custom attributes placed on a data point to the series default.
    void ResetCustom(); // [id(7), method]
    // Selects an individual data point.
    void Select(); // [id(8), method]
};

// TKIND_DISPATCH: IVcAxis {027D7900-A023-11CE-840F-00AA0042CB33}\409 Axis(axisId, 1) object

class IVcAxis : public TAutoProxy {
  public:
    IVcAxis() : TAutoProxy(0x409) {}
    // Returns the Pen object used to draw the axis lines and tick marks.
    IDispatch* GetPen();     // [id(1), prop r/w]
    void SetPen(IDispatch*); // [id(1), prop r/w]
    // Returns the number of levels of labels for a given axis.
    short GetLabelLevelCount();     // [id(2), prop r/w]
    void SetLabelLevelCount(short); // [id(2), prop r/w]
    // Returns the CategoryScale object associated with this axis.
    IDispatch* GetCategoryScale();     // [id(3), prop r/w]
    void SetCategoryScale(IDispatch*); // [id(3), prop r/w]
    // Returns the DateScale object associated with this axis.
    IDispatch* GetDateScale();     // [id(4), prop r/w]
    void SetDateScale(IDispatch*); // [id(4), prop r/w]
    // Returns the AxisGrid object associated with this axis.
    IDispatch* GetAxisGrid();     // [id(5), prop r/w]
    void SetAxisGrid(IDispatch*); // [id(5), prop r/w]
    // Returns the Intersection object associated with this axis.
    IDispatch* GetIntersection();     // [id(6), prop r/w]
    void SetIntersection(IDispatch*); // [id(6), prop r/w]
    // Returns the Tick object associated with this axis.
    IDispatch* GetTick();     // [id(7), prop r/w]
    void SetTick(IDispatch*); // [id(7), prop r/w]
    // Returns the Scale object associated with this axis.
    IDispatch* GetAxisScale();     // [id(8), prop r/w]
    void SetAxisScale(IDispatch*); // [id(8), prop r/w]
    // Returns the ValueScale object associated with this axis.
    IDispatch* GetValueScale();     // [id(9), prop r/w]
    void SetValueScale(IDispatch*); // [id(9), prop r/w]
    // Returns the AxisTitle object associated with this axis.
    IDispatch* GetAxisTitle();     // [id(10), prop r/w]
    void SetAxisTitle(IDispatch*); // [id(10), prop r/w]
    // A group of chart axis labels.
    IDispatch* GetLabels();     // [id(11), prop r/w]
    void SetLabels(IDispatch*); // [id(11), prop r/w]
};

// TKIND_DISPATCH: IVcCategoryScale {62375360-A17D-11CE-840F-00AA0042CB33}\409 CategoryScale object

class IVcCategoryScale : public TAutoProxy {
  public:
    IVcCategoryScale() : TAutoProxy(0x409) {}
    // Determines whether the axis is automatically scaled.
    bool GetAuto();     // [id(1), prop r/w]
    void SetAuto(bool); // [id(1), prop r/w]
    // Returns/sets how many divisions are skipped between labels.
    short GetDivisionsPerLabel();     // [id(2), prop r/w]
    void SetDivisionsPerLabel(short); // [id(2), prop r/w]
    // Returns/sets how many divisions are skipped between tick marks.
    short GetDivisionsPerTick();     // [id(3), prop r/w]
    void SetDivisionsPerTick(short); // [id(3), prop r/w]
    // Determines where category axis labels are positioned relative to the axis tick.
    bool GetLabelTick();     // [id(4), prop r/w]
    void SetLabelTick(bool); // [id(4), prop r/w]
};

// TKIND_DISPATCH: IVcDateScale {62375362-A17D-11CE-840F-00AA0042CB33}\409 DateScale object

class IVcDateScale : public TAutoProxy {
  public:
    IVcDateScale() : TAutoProxy(0x409) {}
    // Determines whether the axis is automatically scaled.
    bool GetAuto();     // [id(1), prop r/w]
    void SetAuto(bool); // [id(1), prop r/w]
    // Returns/sets the beginning date on the date axis.
    double GetMinimum();     // [id(2), prop r/w]
    void SetMinimum(double); // [id(2), prop r/w]
    // Returns/sets the ending date on the date axis.
    double GetMaximum();     // [id(3), prop r/w]
    void SetMaximum(double); // [id(3), prop r/w]
    // Returns/sets the type of major interval used to display dates on an axis. (DateIntervalTypeConstants)
    short GetMajInt();     // [id(4), prop r/w]
    void SetMajInt(short); // [id(4), prop r/w]
    // Returns/sets how many major intervals pass before a label is placed on the axis.
    short GetMajFreq();     // [id(5), prop r/w]
    void SetMajFreq(short); // [id(5), prop r/w]
    // Returns/sets the type of minor interval used to display dates on an axis. (DateIntervalTypeConstants)
    short GetMinInt();     // [id(6), prop r/w]
    void SetMinInt(short); // [id(6), prop r/w]
    // Returns/sets how many minor intervals pass before a label is placed on the axis.
    short GetMinFreq();     // [id(7), prop r/w]
    void SetMinFreq(short); // [id(7), prop r/w]
    // Determines whether dates that fall on the weekend are displayed on the chart.
    bool GetSkipWeekend();     // [id(8), prop r/w]
    void SetSkipWeekend(bool); // [id(8), prop r/w]
};

// TKIND_DISPATCH: IVcAxisGrid {62375364-A17D-11CE-840F-00AA0042CB33}\409 AxisGrid object

class IVcAxisGrid : public TAutoProxy {
  public:
    IVcAxisGrid() : TAutoProxy(0x409) {}
    // Returns the Pen object used to draw the minor axis grid lines.
    IDispatch* GetMinorPen();     // [id(1), prop r/w]
    void SetMinorPen(IDispatch*); // [id(1), prop r/w]
    // Returns the Pen object used to draw the major axis grid lines.
    IDispatch* GetMajorPen();     // [id(2), prop r/w]
    void SetMajorPen(IDispatch*); // [id(2), prop r/w]
};

// TKIND_DISPATCH: IVcIntersection {62375366-A17D-11CE-840F-00AA0042CB33}\409 Intersection object

class IVcIntersection : public TAutoProxy {
  public:
    IVcIntersection() : TAutoProxy(0x409) {}
    // Determines whether First Impression uses the value of Point to position the axis.
    bool GetAuto();     // [id(1), prop r/w]
    void SetAuto(bool); // [id(1), prop r/w]
    // Returns/sets where the current axis intersects the axis perpendicular to it.
    double GetPoint();     // [id(2), prop r/w]
    void SetPoint(double); // [id(2), prop r/w]
    // Identifies a specific axis. (AxisIdConstants)
    short GetAxisId();     // [id(3), prop r/w]
    void SetAxisId(short); // [id(3), prop r/w]
    // Reserved for future use.  Must be set to 1.
    short GetIndex();     // [id(4), prop r/w]
    void SetIndex(short); // [id(4), prop r/w]
    // Axis labels are adjacent to the axis.
    bool GetLabelsInsidePlot();     // [id(5), prop r/w]
    void SetLabelsInsidePlot(bool); // [id(5), prop r/w]
};

// TKIND_DISPATCH: IVcTick {62375368-A17D-11CE-840F-00AA0042CB33}\409 Tick object

class IVcTick : public TAutoProxy {
  public:
    IVcTick() : TAutoProxy(0x409) {}
    // Returns/sets the length of axis tick marks, measured in points.
    float GetLength();     // [id(1), prop r/w]
    void SetLength(float); // [id(1), prop r/w]
    // Returns/sets the position of the axis tick. (AxisTickStyleConstants)
    short GetStyle();     // [id(2), prop r/w]
    void SetStyle(short); // [id(2), prop r/w]
};

// TKIND_DISPATCH: IVcScale {6237536A-A17D-11CE-840F-00AA0042CB33}\409 AxisScale object

class IVcScale : public TAutoProxy {
  public:
    IVcScale() : TAutoProxy(0x409) {}
    // Determines whether the axis is hidden.
    bool GetHide();     // [id(1), prop r/w]
    void SetHide(bool); // [id(1), prop r/w]
    // Returns/sets the type of axis scale. (ScaleTypeConstants)
    short GetType();     // [id(2), prop r/w]
    void SetType(short); // [id(2), prop r/w]
    // Returns/sets the logarithm base used to plot chart values on a logarithmic axis.
    short GetLogBase();     // [id(3), prop r/w]
    void SetLogBase(short); // [id(3), prop r/w]
    // Returns/sets the type of percentage used to plot chart values on a percent axis. (PercentAxisBasisConstants)
    short GetPercentBasis();     // [id(4), prop r/w]
    void SetPercentBasis(short); // [id(4), prop r/w]
};

// TKIND_DISPATCH: IVcValueScale {6237536C-A17D-11CE-840F-00AA0042CB33}\409 ValueScale object

class IVcValueScale : public TAutoProxy {
  public:
    IVcValueScale() : TAutoProxy(0x409) {}
    // Determines whether automatic scaling is used to draw the axis.
    bool GetAuto();     // [id(1), prop r/w]
    void SetAuto(bool); // [id(1), prop r/w]
    // Returns/sets the lowest or beginning value used to scale the axis.
    double GetMinimum();     // [id(2), prop r/w]
    void SetMinimum(double); // [id(2), prop r/w]
    // Returns/sets the highest or ending value used to scale the axis.
    double GetMaximum();     // [id(3), prop r/w]
    void SetMaximum(double); // [id(3), prop r/w]
    // Returns/sets the number of major divisions displayed on the axis.
    short GetMajorDivision();     // [id(4), prop r/w]
    void SetMajorDivision(short); // [id(4), prop r/w]
    // Returns/sets the number of minor divisions displayed within each major division of the axis.
    short GetMinorDivision();     // [id(5), prop r/w]
    void SetMinorDivision(short); // [id(5), prop r/w]
};

// TKIND_DISPATCH: IVcAxisTitle {6237536E-A17D-11CE-840F-00AA0042CB33}\409 AxisTitle object

class IVcAxisTitle : public TAutoProxy {
  public:
    IVcAxisTitle() : TAutoProxy(0x409) {}
    // Returns/sets the text used as an axis title.
    TAutoString GetText();     // [id(1), prop r/w]
    void SetText(TAutoString); // [id(1), prop r/w]
    TAutoString Get_Text();     // [id(0), prop r/w, hidden]
    void Set_Text(TAutoString); // [id(0), prop r/w, hidden]
    // Returns the Backdrop object associated with this axis title.
    IDispatch* GetBackdrop();     // [id(2), prop r/w]
    void SetBackdrop(IDispatch*); // [id(2), prop r/w]
    // Returns the VtFont object associated with this axis title.
    IDispatch* GetVtFont();     // [id(3), prop r/w]
    void SetVtFont(IDispatch*); // [id(3), prop r/w]
    // Determines whether the axis title is visible.
    bool GetVisible();     // [id(4), prop r/w]
    void SetVisible(bool); // [id(4), prop r/w]
    // Returns the TextLayout object associated with this axis title.
    IDispatch* GetTextLayout();     // [id(5), prop r/w]
    void SetTextLayout(IDispatch*); // [id(5), prop r/w]
    // Returns the length of the axis title.
    short GetTextLength();     // [id(6), prop r/w]
    void SetTextLength(short); // [id(6), prop r/w]
};

// TKIND_DISPATCH: IVcLabel {62375370-A17D-11CE-840F-00AA0042CB33}\409 Label object

class IVcLabel : public TAutoProxy {
  public:
    IVcLabel() : TAutoProxy(0x409) {}
    // Returns the Backdrop object associated with this label.
    IDispatch* GetBackdrop();     // [id(1), prop r/w]
    void SetBackdrop(IDispatch*); // [id(1), prop r/w]
    // Returns/sets the format used to display the label.
    TAutoString GetFormat();     // [id(2), prop r/w]
    void SetFormat(TAutoString); // [id(2), prop r/w]
    // Returns/sets the VtFont object associated with this label.
    IDispatch* GetVtFont();     // [id(3), prop r/w]
    void SetVtFont(IDispatch*); // [id(3), prop r/w]
    // Determines whether First Impression can determine if rotating the label would improve the chart layout.
    bool GetAuto();     // [id(4), prop r/w]
    void SetAuto(bool); // [id(4), prop r/w]
    // Determines whether axis labels are displayed laying down in the X or Z plane or rotated up on the text baseline to stand in the Y plane.
    bool GetStanding();     // [id(5), prop r/w]
    void SetStanding(bool); // [id(5), prop r/w]
    // Returns the TextLayout object associated with this label.
    IDispatch* GetTextLayout();     // [id(6), prop r/w]
    void SetTextLayout(IDispatch*); // [id(6), prop r/w]
    // Returns the length of the format string.
    short GetFormatLength();     // [id(7), prop r/w]
    void SetFormatLength(short); // [id(7), prop r/w]
};

// TKIND_DISPATCH: IVcLight {B54A6420-A25E-11CE-840F-00AA0042CB33}\409 Light object

class IVcLight : public TAutoProxy {
  public:
    IVcLight() : TAutoProxy(0x409) {}
    // Returns/sets the percentage of ambient light illuminating a 3D chart.
    float GetAmbientIntensity();     // [id(1), prop r/w]
    void SetAmbientIntensity(float); // [id(1), prop r/w]
    // Returns/sets the intensity used to display the edges on a 3D chart.
    float GetEdgeIntensity();     // [id(2), prop r/w]
    void SetEdgeIntensity(float); // [id(2), prop r/w]
    // Determines whether edges are displayed on the elements in a 3D chart.
    bool GetEdgeVisible();     // [id(3), prop r/w]
    void SetEdgeVisible(bool); // [id(3), prop r/w]
    // A collection of light sources.
    IDispatch* GetLightSources();     // [id(4), prop r/w]
    void SetLightSources(IDispatch*); // [id(4), prop r/w]
};

// TKIND_DISPATCH: IVcElevation {A71FB700-A732-11CE-840F-00AA0042CB33}\409 Elevation object

class IVcElevation : public TAutoProxy {
  public:
    IVcElevation() : TAutoProxy(0x409) {}
    // Returns/sets the way contour VtColor is displayed on the chart. (ContourColorTypeConstants)
    short GetColorType();     // [id(1), prop r/w]
    void SetColorType(short); // [id(1), prop r/w]
    // Returns/sets the smoothing factor to be applied to rows.
    short GetRowSmoothing();     // [id(2), prop r/w]
    void SetRowSmoothing(short); // [id(2), prop r/w]
    // Returns/sets the smoothing factor to be applied to columns.
    short GetColSmoothing();     // [id(3), prop r/w]
    void SetColSmoothing(short); // [id(3), prop r/w]
    // The chart surface.
    IDispatch* GetSurface();     // [id(4), prop r/w]
    void SetSurface(IDispatch*); // [id(4), prop r/w]
    // Refers to the values used to display chart contours.
    bool GetAutoValues();     // [id(5), prop r/w]
    void SetAutoValues(bool); // [id(5), prop r/w]
    // Returns/sets whether or not the data grid contains separate elevation and contouring data.
    bool GetSeparateContourData();     // [id(6), prop r/w]
    void SetSeparateContourData(bool); // [id(6), prop r/w]
    // A surface contour on a 3D elevation chart.
    IDispatch* GetContour();     // [id(7), prop r/w]
    void SetContour(IDispatch*); // [id(7), prop r/w]
    // A group of chart contour attributes.
    IDispatch* GetAttributes();     // [id(8), prop r/w]
    void SetAttributes(IDispatch*); // [id(8), prop r/w]
    // A gradient contour band or line on a 3D elevation chart.
    IDispatch* GetContourGradient();     // [id(9), prop r/w]
    void SetContourGradient(IDispatch*); // [id(9), prop r/w]
};

// TKIND_DISPATCH: IVcAttribute {A71FB702-A732-11CE-840F-00AA0042CB33}\409 Attribute object

class IVcAttribute : public TAutoProxy {
  public:
    IVcAttribute() : TAutoProxy(0x409) {}
    // Returns/sets the contour data value where the contour is displayed.
    double GetValue();     // [id(1), prop r/w]
    void SetValue(double); // [id(1), prop r/w]
    // Returns/sets the color and style used to display the chart contour as a band.
    IDispatch* GetBrush();     // [id(2), prop r/w]
    void SetBrush(IDispatch*); // [id(2), prop r/w]
    // Returns/sets the color and style used to display the chart contour as a line.
    IDispatch* GetPen();     // [id(3), prop r/w]
    void SetPen(IDispatch*); // [id(3), prop r/w]
    // Returns/sets the text used to identify the contour in the legend.
    TAutoString GetText();     // [id(4), prop r/w]
    void SetText(TAutoString); // [id(4), prop r/w]
    TAutoString Get_Text();     // [id(0), prop r/w, hidden]
    void Set_Text(TAutoString); // [id(0), prop r/w, hidden]
};

// TKIND_DISPATCH: IVcSurface {A71FB704-A732-11CE-840F-00AA0042CB33}\409 Surface object

class IVcSurface : public TAutoProxy {
  public:
    IVcSurface() : TAutoProxy(0x409) {}
    // Returns the Brush object describing the VtColor used to draw the chart surface.
    IDispatch* GetBrush();     // [id(1), prop r/w]
    void SetBrush(IDispatch*); // [id(1), prop r/w]
    // Returns the Pen object describing the appearance of the wireframe on the surface chart.
    IDispatch* GetWireframePen();     // [id(2), prop r/w]
    void SetWireframePen(IDispatch*); // [id(2), prop r/w]
    // Returns/sets the appearance of the planar contour chart projected above the surface. (ProjectionTypeConstants)
    short GetProjection();     // [id(3), prop r/w]
    void SetProjection(short); // [id(3), prop r/w]
    // Returns/sets how the surface itself is represented. (SurfaceDisplayTypeConstants)
    short GetDisplayType();     // [id(4), prop r/w]
    void SetDisplayType(short); // [id(4), prop r/w]
    // Returns/sets the row wireframe appearance. (SurfaceWireframeTypeConstants)
    short GetRowWireframe();     // [id(5), prop r/w]
    void SetRowWireframe(short); // [id(5), prop r/w]
    // Returns/sets the column wireframe appearance. (SurfaceWireframeTypeConstants)
    short GetColWireframe();     // [id(6), prop r/w]
    void SetColWireframe(short); // [id(6), prop r/w]
    // Returns/sets how the base of a surface chart is represented. (SurfaceBaseTypeConstants)
    short GetBase();     // [id(7), prop r/w]
    void SetBase(short); // [id(7), prop r/w]
};

// TKIND_DISPATCH: IVcContour {A71FB706-A732-11CE-840F-00AA0042CB33}\409 Contour object

class IVcContour : public TAutoProxy {
  public:
    IVcContour() : TAutoProxy(0x409) {}
    // Returns/sets the type of contour used in the 2D contour charts. (ContourDisplayTypeConstants)
    short GetDisplayType();     // [id(1), prop r/w]
    void SetDisplayType(short); // [id(1), prop r/w]
};

// TKIND_DISPATCH: IVcLightSource {CD9EFA60-AA40-11CE-840F-00AA0042CB33}\409 LightSource object

class IVcLightSource : public TAutoProxy {
  public:
    IVcLightSource() : TAutoProxy(0x409) {}
    // Returns/sets  the strength of the light coming from the light source.
    float GetIntensity();     // [id(1), prop r/w]
    void SetIntensity(float); // [id(1), prop r/w]
    // Returns/sets  the X coordinate for the location of the LightSource.
    float GetX();     // [id(2), prop r/w]
    void SetX(float); // [id(2), prop r/w]
    // Returns/sets  the Y coordinate for the location of the LightSource.
    float GetY();     // [id(3), prop r/w]
    void SetY(float); // [id(3), prop r/w]
    // Returns/sets  the Z coordinate for the location of the LightSource.
    float GetZ();     // [id(4), prop r/w]
    void SetZ(float); // [id(4), prop r/w]
    float Get_Intensity();     // [id(0), prop r/w, hidden]
    void Set_Intensity(float); // [id(0), prop r/w, hidden]
    // Sets the x,y,z coordinates for the LightSource location and the intensity of the LightSource.
    void Set(float X, float Y, float Z, float Intensity); // [id(5), method]
};

// TKIND_DISPATCH: IVcSeriesCollection {C14E8B60-AE2B-11CE-840F-00AA0042CB33}\409 SeriesCollection Collection

class IVcSeriesCollection : public TAutoProxy {
  public:
    IVcSeriesCollection() : TAutoProxy(0x409) {}
    // Returns the number of items in this collection.
    long GetCount();     // [id(1), prop r/w]
    void SetCount(long); // [id(1), prop r/w]
    // Returns a specific item from this collection.
    IDispatch* GetItem(short Index); // [id(2), propget]
};

// TKIND_DISPATCH: IVcDataPoints {C20E5260-B06F-11CE-840F-00AA0042CB33}\409 DataPoints Collection

class IVcDataPoints : public TAutoProxy {
  public:
    IVcDataPoints() : TAutoProxy(0x409) {}
    // Returns the number of items in this collection.
    long GetCount();     // [id(1), prop r/w]
    void SetCount(long); // [id(1), prop r/w]
    // Returns a specific item from this collection.
    IDispatch* GetItem(short DataPoint); // [id(2), propget]
    IDispatch* Get_Item(short DataPoint); // [id(0), propget, hidden]
};

// TKIND_DISPATCH: IVcLabels {62B9A400-B93D-11CE-8410-00AA0042CB33}\409 Labels Collection

class IVcLabels : public TAutoProxy {
  public:
    IVcLabels() : TAutoProxy(0x409) {}
    // Returns the number of items in this collection.
    long GetCount();     // [id(1), prop r/w]
    void SetCount(long); // [id(1), prop r/w]
    // Returns a specific item from this collection.
    IDispatch* GetItem(short LabelIndex); // [id(2), propget]
    IDispatch* Get_Item(short LabelIndex); // [id(0), propget, hidden]
};

// TKIND_DISPATCH: IVcXYZ {7D001800-BC65-11CE-8410-00AA0042CB33}\409 XYZ Object

class IVcXYZ : public TAutoProxy {
  public:
    IVcXYZ() : TAutoProxy(0x409) {}
    // Sets or returns the point on the X axis of a 3DXYZ chart where the Y and Z axes intersect.
    double GetxIntersection();     // [id(1), prop r/w]
    void SetxIntersection(double); // [id(1), prop r/w]
    // Sets or returns the point on theY axis of a 3DXYZ chart where the X and Z axes intersect.
    double GetyIntersection();     // [id(2), prop r/w]
    void SetyIntersection(double); // [id(2), prop r/w]
    // Returns/sets the point on the Z axis of a 3DXYZ chart where the X and Y axes intersect.
    double GetzIntersection();     // [id(3), prop r/w]
    void SetzIntersection(double); // [id(3), prop r/w]
    // Sets or returns whether First Impression uses the xintersection value, yintersection value and zintersection value to position the intersection point.
    bool GetAutomatic();     // [id(4), prop r/w]
    void SetAutomatic(bool); // [id(4), prop r/w]
};

// TKIND_DISPATCH: IVcLightSources {6FE35CC0-CE50-11CE-8410-00AA0042CB33}\409 LightSources Collection

class IVcLightSources : public TAutoProxy {
  public:
    IVcLightSources() : TAutoProxy(0x409) {}
    // Returns the number of items in this collection.
    long GetCount();     // [id(1), prop r/w]
    void SetCount(long); // [id(1), prop r/w]
    // Returns a specific item from this collection.
    IDispatch* GetItem(short Index); // [id(4), propget]
    // Add a new LightSource to the collection.
    IDispatch* Add(float X, float Y, float Z, float Intensity); // [id(2), method]
    // Remove a LightSource from the collection.
    void Remove(short Index); // [id(3), method]
};

// TKIND_DISPATCH: IVcAttributes {5A693220-CFEF-11CE-8410-00AA0042CB33}\409 Contour Attributes Collection

class IVcAttributes : public TAutoProxy {
  public:
    IVcAttributes() : TAutoProxy(0x409) {}
    // Returns the number of contour items in this collection.
    short GetCount();     // [id(1), prop r/w]
    void SetCount(short); // [id(1), prop r/w]
    // Returns the contour item whose value is given.
    IDispatch* GetItem(short Index); // [id(4), propget]
    // Returns the contour item whose value is given.
    IDispatch* Get_Item(short Index); // [id(0), propget]
    // Adds a contour item at the given value.
    IDispatch* Add(double Value); // [id(2), method]
    // Removes the contour item whose index is given.
    void Remove(short Index); // [id(3), method]
};

// TKIND_DISPATCH: IVcContourGradient {69032720-D303-11CE-8410-00AA0042CB33}\409 Contour gradient from/to attributes object

class IVcContourGradient : public TAutoProxy {
  public:
    IVcContourGradient() : TAutoProxy(0x409) {}
    // Sets or returns the brush color for the beginning gradient on a chart contour.
    IDispatch* GetFromBrushColor();     // [id(1), prop r/w]
    void SetFromBrushColor(IDispatch*); // [id(1), prop r/w]
    // Sets or returns the brush color for the ending gradient on a chart contour.
    IDispatch* GetToBrushColor();     // [id(2), prop r/w]
    void SetToBrushColor(IDispatch*); // [id(2), prop r/w]
    // Sets or returns the pen color for the beginning line on a chart contour.
    IDispatch* GetFromPenColor();     // [id(3), prop r/w]
    void SetFromPenColor(IDispatch*); // [id(3), prop r/w]
    // Sets or returns the pen color for the ending line on a chart contour.
    IDispatch* GetToPenColor();     // [id(4), prop r/w]
    void SetToPenColor(IDispatch*); // [id(4), prop r/w]
};

#endif // _PROXY_VCFI32_HXX
