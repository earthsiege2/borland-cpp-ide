// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'VCFImprs.pas' rev: 6.00

#ifndef VCFImprsHPP
#define VCFImprsHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <Menus.hpp>	// Pascal unit
#include <Controls.hpp>	// Pascal unit
#include <OleCtrls.hpp>	// Pascal unit
#include <Graphics.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <OleCtl.hpp>	// Pascal unit
#include <Ole2.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Vcfimprs
{
//-- type declarations -------------------------------------------------------
typedef void __fastcall (__closure *TVCFirstImpressionChartSelected)(System::TObject* Sender, short &MouseFlags, short &Cancel);

typedef void __fastcall (__closure *TVCFirstImpressionTitleSelected)(System::TObject* Sender, short &MouseFlags, short &Cancel);

typedef void __fastcall (__closure *TVCFirstImpressionFootnoteSelected)(System::TObject* Sender, short &MouseFlags, short &Cancel);

typedef void __fastcall (__closure *TVCFirstImpressionLegendSelected)(System::TObject* Sender, short &MouseFlags, short &Cancel);

typedef void __fastcall (__closure *TVCFirstImpressionPlotSelected)(System::TObject* Sender, short &MouseFlags, short &Cancel);

typedef void __fastcall (__closure *TVCFirstImpressionAxisSelected)(System::TObject* Sender, short &AxisId, short &AxisIndex, short &MouseFlags, short &Cancel);

typedef void __fastcall (__closure *TVCFirstImpressionAxisLabelSelected)(System::TObject* Sender, short &AxisId, short &AxisIndex, short &labelSetIndex, short &LabelIndex, short &MouseFlags, short &Cancel);

typedef void __fastcall (__closure *TVCFirstImpressionAxisTitleSelected)(System::TObject* Sender, short &AxisId, short &AxisIndex, short &MouseFlags, short &Cancel);

typedef void __fastcall (__closure *TVCFirstImpressionPointSelected)(System::TObject* Sender, short &Series, short &DataPoint, short &MouseFlags, short &Cancel);

typedef void __fastcall (__closure *TVCFirstImpressionPointLabelSelected)(System::TObject* Sender, short &Series, short &DataPoint, short &MouseFlags, short &Cancel);

typedef void __fastcall (__closure *TVCFirstImpressionSeriesSelected)(System::TObject* Sender, short &Series, short &MouseFlags, short &Cancel);

typedef void __fastcall (__closure *TVCFirstImpressionSeriesLabelSelected)(System::TObject* Sender, short &Series, short &MouseFlags, short &Cancel);

typedef void __fastcall (__closure *TVCFirstImpressionChartActivated)(System::TObject* Sender, short &MouseFlags, short &Cancel);

typedef void __fastcall (__closure *TVCFirstImpressionTitleActivated)(System::TObject* Sender, short &MouseFlags, short &Cancel);

typedef void __fastcall (__closure *TVCFirstImpressionFootnoteActivated)(System::TObject* Sender, short &MouseFlags, short &Cancel);

typedef void __fastcall (__closure *TVCFirstImpressionLegendActivated)(System::TObject* Sender, short &MouseFlags, short &Cancel);

typedef void __fastcall (__closure *TVCFirstImpressionPlotActivated)(System::TObject* Sender, short &MouseFlags, short &Cancel);

typedef void __fastcall (__closure *TVCFirstImpressionAxisActivated)(System::TObject* Sender, short &AxisId, short &AxisIndex, short &MouseFlags, short &Cancel);

typedef void __fastcall (__closure *TVCFirstImpressionAxisLabelActivated)(System::TObject* Sender, short &AxisId, short &AxisIndex, short &labelSetIndex, short &LabelIndex, short &MouseFlags, short &Cancel);

typedef void __fastcall (__closure *TVCFirstImpressionAxisTitleActivated)(System::TObject* Sender, short &AxisId, short &AxisIndex, short &MouseFlags, short &Cancel);

typedef void __fastcall (__closure *TVCFirstImpressionPointActivated)(System::TObject* Sender, short &Series, short &DataPoint, short &MouseFlags, short &Cancel);

typedef void __fastcall (__closure *TVCFirstImpressionPointLabelActivated)(System::TObject* Sender, short &Series, short &DataPoint, short &MouseFlags, short &Cancel);

typedef void __fastcall (__closure *TVCFirstImpressionSeriesActivated)(System::TObject* Sender, short &Series, short &MouseFlags, short &Cancel);

typedef void __fastcall (__closure *TVCFirstImpressionSeriesLabelActivated)(System::TObject* Sender, short &Series, short &MouseFlags, short &Cancel);

class DELPHICLASS TVCFirstImpression;
class PASCALIMPLEMENTATION TVCFirstImpression : public Olectrls::TOleControl 
{
	typedef Olectrls::TOleControl inherited;
	
private:
	TVCFirstImpressionChartSelected FOnChartSelected;
	TVCFirstImpressionTitleSelected FOnTitleSelected;
	TVCFirstImpressionFootnoteSelected FOnFootnoteSelected;
	TVCFirstImpressionLegendSelected FOnLegendSelected;
	TVCFirstImpressionPlotSelected FOnPlotSelected;
	TVCFirstImpressionAxisSelected FOnAxisSelected;
	TVCFirstImpressionAxisLabelSelected FOnAxisLabelSelected;
	TVCFirstImpressionAxisTitleSelected FOnAxisTitleSelected;
	TVCFirstImpressionPointSelected FOnPointSelected;
	TVCFirstImpressionPointLabelSelected FOnPointLabelSelected;
	TVCFirstImpressionSeriesSelected FOnSeriesSelected;
	TVCFirstImpressionSeriesLabelSelected FOnSeriesLabelSelected;
	TVCFirstImpressionChartActivated FOnChartActivated;
	TVCFirstImpressionTitleActivated FOnTitleActivated;
	TVCFirstImpressionFootnoteActivated FOnFootnoteActivated;
	TVCFirstImpressionLegendActivated FOnLegendActivated;
	TVCFirstImpressionPlotActivated FOnPlotActivated;
	TVCFirstImpressionAxisActivated FOnAxisActivated;
	TVCFirstImpressionAxisLabelActivated FOnAxisLabelActivated;
	TVCFirstImpressionAxisTitleActivated FOnAxisTitleActivated;
	TVCFirstImpressionPointActivated FOnPointActivated;
	TVCFirstImpressionPointLabelActivated FOnPointLabelActivated;
	TVCFirstImpressionSeriesActivated FOnSeriesActivated;
	TVCFirstImpressionSeriesLabelActivated FOnSeriesLabelActivated;
	Classes::TNotifyEvent FOnApplyChanges;
	int __stdcall Get_GetBitmap(const Variant options);
	
protected:
	virtual void __fastcall InitControlData(void);
	
public:
	void __stdcall EditPaste(void);
	void __stdcall EditCopy(void);
	void __stdcall ActivateSelectionDialog(void);
	void __stdcall Layout(void);
	void __stdcall ToDefaults(void);
	void __stdcall PrintSetupDialog(void);
	void __stdcall PrintChart(void);
	void __stdcall SelectPart(short part, short index1, short index2, short index3, short index4);
	void __stdcall GetSelectedPart(short &part, short &index1, short &index2, short &index3, short &index4);
	void __stdcall GetDLLVersion(short &major, short &minor);
	void __stdcall TwipsToChartPart(int xVal, int yVal, short &part, short &index1, short &index2, short &index3, short &index4);
	void __stdcall ReadFromFile(const AnsiString FileName);
	void __stdcall WritePictureToFile(const AnsiString FileName, short pictureType, short options);
	void __stdcall WriteToFile(const AnsiString FileName);
	void __stdcall ActivateFormatMenu(int X, int Y);
	void __stdcall GetMetafile(short options, int &Handle, int &Width, int &Height);
	void __stdcall CopyDataFromArray(short Top, short Left, short Bottom, short Right, const Variant Array_);
	void __stdcall CopyDataToArray(short Top, short Left, short Bottom, short Right, const Variant Array_);
	void __stdcall Draw(int hDC, short hDCType, int Top, int Left, int Bottom, int Right, Word Layout, Word Stretch);
	void __stdcall UseWizard(void);
	void __stdcall EditChartData(void);
	HIDESBASE void __stdcall Refresh(void);
	void __stdcall AboutBox(void);
	__property AnsiString SsLinkSheet = {read=GetStringProp, write=SetStringProp, index=22};
	__property int Handle = {read=GetIntegerProp, write=SetIntegerProp, index=24, nodefault};
	__property Variant Picture = {read=GetVariantProp, write=SetVariantProp, index=25};
	__property int GetBitmap[Variant options] = {read=Get_GetBitmap};
	
__published:
	__property TabStop  = {default=1};
	__property DragCursor  = {default=-12};
	__property DragMode  = {default=0};
	__property ParentShowHint  = {default=1};
	__property PopupMenu ;
	__property ShowHint ;
	__property TabOrder  = {default=-1};
	__property Visible  = {default=1};
	__property OnDragDrop ;
	__property OnDragOver ;
	__property OnEndDrag ;
	__property OnEnter ;
	__property OnExit ;
	__property OnStartDrag ;
	__property OnClick ;
	__property OnDblClick ;
	__property OnKeyDown ;
	__property OnKeyPress ;
	__property OnKeyUp ;
	__property OnMouseDown ;
	__property OnMouseMove ;
	__property OnMouseUp ;
	__property Word AutoIncrement = {read=GetOleBoolProp, write=SetOleBoolProp, stored=false, index=1, nodefault};
	__property Word RandomFill = {read=GetOleBoolProp, write=SetOleBoolProp, stored=false, index=2, nodefault};
	__property short ChartType = {read=GetSmallintProp, write=SetSmallintProp, stored=false, index=3, nodefault};
	__property short Column = {read=GetSmallintProp, write=SetSmallintProp, stored=false, index=4, nodefault};
	__property short ColumnCount = {read=GetSmallintProp, write=SetSmallintProp, stored=false, index=5, nodefault};
	__property AnsiString ColumnLabel = {read=GetStringProp, write=SetStringProp, stored=false, index=6};
	__property short ColumnLabelCount = {read=GetSmallintProp, write=SetSmallintProp, stored=false, index=7, nodefault};
	__property short ColumnLabelIndex = {read=GetSmallintProp, write=SetSmallintProp, stored=false, index=8, nodefault};
	__property AnsiString Data = {read=GetStringProp, write=SetStringProp, stored=false, index=9};
	__property AnsiString FootnoteText = {read=GetStringProp, write=SetStringProp, stored=false, index=10};
	__property Word Repaint = {read=GetOleBoolProp, write=SetOleBoolProp, stored=false, index=11, nodefault};
	__property short Row = {read=GetSmallintProp, write=SetSmallintProp, stored=false, index=12, nodefault};
	__property short RowCount = {read=GetSmallintProp, write=SetSmallintProp, stored=false, index=13, nodefault};
	__property AnsiString RowLabel = {read=GetStringProp, write=SetStringProp, stored=false, index=14};
	__property short RowLabelCount = {read=GetSmallintProp, write=SetSmallintProp, stored=false, index=15, nodefault};
	__property short RowLabelIndex = {read=GetSmallintProp, write=SetSmallintProp, stored=false, index=16, nodefault};
	__property short SeriesColumn = {read=GetSmallintProp, write=SetSmallintProp, stored=false, index=17, nodefault};
	__property short SeriesType = {read=GetSmallintProp, write=SetSmallintProp, stored=false, index=18, nodefault};
	__property Word ShowLegend = {read=GetOleBoolProp, write=SetOleBoolProp, stored=false, index=19, nodefault};
	__property short SsLinkMode = {read=GetSmallintProp, write=SetSmallintProp, stored=false, index=20, nodefault};
	__property AnsiString SsLinkRange = {read=GetStringProp, write=SetStringProp, stored=false, index=21};
	__property short DrawMode = {read=GetSmallintProp, write=SetSmallintProp, stored=false, index=23, nodefault};
	__property short BorderStyle = {read=GetSmallintProp, write=SetSmallintProp, stored=false, index=-504, nodefault};
	__property Word Enabled = {read=GetOleBoolProp, write=SetOleBoolProp, stored=false, index=-514, nodefault};
	__property short hWnd = {read=GetSmallintProp, write=SetSmallintProp, stored=false, index=-515, nodefault};
	__property Variant Title = {read=GetVariantProp, write=SetVariantProp, stored=false, index=26};
	__property Variant Footnote = {read=GetVariantProp, write=SetVariantProp, stored=false, index=27};
	__property AnsiString TitleText = {read=GetStringProp, write=SetStringProp, stored=false, index=28};
	__property Word Stacking = {read=GetOleBoolProp, write=SetOleBoolProp, stored=false, index=29, nodefault};
	__property short TextLengthType = {read=GetSmallintProp, write=SetSmallintProp, stored=false, index=30, nodefault};
	__property Word AllowUserChanges = {read=GetOleBoolProp, write=SetOleBoolProp, stored=false, index=31, nodefault};
	__property Word AllowSelections = {read=GetOleBoolProp, write=SetOleBoolProp, stored=false, index=32, nodefault};
	__property Word AllowSeriesSelection = {read=GetOleBoolProp, write=SetOleBoolProp, stored=false, index=33, nodefault};
	__property Word AllowDynamicRotation = {read=GetOleBoolProp, write=SetOleBoolProp, stored=false, index=34, nodefault};
	__property short ActiveSeriesCount = {read=GetSmallintProp, write=SetSmallintProp, stored=false, index=35, nodefault};
	__property Variant Backdrop = {read=GetVariantProp, write=SetVariantProp, stored=false, index=36};
	__property Variant PrintInformation = {read=GetVariantProp, write=SetVariantProp, stored=false, index=37};
	__property Variant Legend = {read=GetVariantProp, write=SetVariantProp, stored=false, index=38};
	__property Variant DataGrid = {read=GetVariantProp, write=SetVariantProp, stored=false, index=39};
	__property Variant Plot = {read=GetVariantProp, write=SetVariantProp, stored=false, index=40};
	__property int TwipsWidth = {read=GetIntegerProp, write=SetIntegerProp, stored=false, index=41, nodefault};
	__property int TwipsHeight = {read=GetIntegerProp, write=SetIntegerProp, stored=false, index=42, nodefault};
	__property Word AllowDithering = {read=GetOleBoolProp, write=SetOleBoolProp, stored=false, index=43, nodefault};
	__property short ErrorOffset = {read=GetSmallintProp, write=SetSmallintProp, stored=false, index=44, nodefault};
	__property Word DoSetCursor = {read=GetOleBoolProp, write=SetOleBoolProp, stored=false, index=45, nodefault};
	__property AnsiString FileName = {read=GetStringProp, write=SetStringProp, stored=false, index=46};
	__property Word Chart3d = {read=GetOleBoolProp, write=SetOleBoolProp, stored=false, index=47, nodefault};
	__property AnsiString SsLinkBook = {read=GetStringProp, write=SetStringProp, stored=false, index=48};
	__property TVCFirstImpressionChartSelected OnChartSelected = {read=FOnChartSelected, write=FOnChartSelected};
	__property TVCFirstImpressionTitleSelected OnTitleSelected = {read=FOnTitleSelected, write=FOnTitleSelected};
	__property TVCFirstImpressionFootnoteSelected OnFootnoteSelected = {read=FOnFootnoteSelected, write=FOnFootnoteSelected};
	__property TVCFirstImpressionLegendSelected OnLegendSelected = {read=FOnLegendSelected, write=FOnLegendSelected};
	__property TVCFirstImpressionPlotSelected OnPlotSelected = {read=FOnPlotSelected, write=FOnPlotSelected};
	__property TVCFirstImpressionAxisSelected OnAxisSelected = {read=FOnAxisSelected, write=FOnAxisSelected};
	__property TVCFirstImpressionAxisLabelSelected OnAxisLabelSelected = {read=FOnAxisLabelSelected, write=FOnAxisLabelSelected};
	__property TVCFirstImpressionAxisTitleSelected OnAxisTitleSelected = {read=FOnAxisTitleSelected, write=FOnAxisTitleSelected};
	__property TVCFirstImpressionPointSelected OnPointSelected = {read=FOnPointSelected, write=FOnPointSelected};
	__property TVCFirstImpressionPointLabelSelected OnPointLabelSelected = {read=FOnPointLabelSelected, write=FOnPointLabelSelected};
	__property TVCFirstImpressionSeriesSelected OnSeriesSelected = {read=FOnSeriesSelected, write=FOnSeriesSelected};
	__property TVCFirstImpressionSeriesLabelSelected OnSeriesLabelSelected = {read=FOnSeriesLabelSelected, write=FOnSeriesLabelSelected};
	__property TVCFirstImpressionChartActivated OnChartActivated = {read=FOnChartActivated, write=FOnChartActivated};
	__property TVCFirstImpressionTitleActivated OnTitleActivated = {read=FOnTitleActivated, write=FOnTitleActivated};
	__property TVCFirstImpressionFootnoteActivated OnFootnoteActivated = {read=FOnFootnoteActivated, write=FOnFootnoteActivated};
	__property TVCFirstImpressionLegendActivated OnLegendActivated = {read=FOnLegendActivated, write=FOnLegendActivated};
	__property TVCFirstImpressionPlotActivated OnPlotActivated = {read=FOnPlotActivated, write=FOnPlotActivated};
	__property TVCFirstImpressionAxisActivated OnAxisActivated = {read=FOnAxisActivated, write=FOnAxisActivated};
	__property TVCFirstImpressionAxisLabelActivated OnAxisLabelActivated = {read=FOnAxisLabelActivated, write=FOnAxisLabelActivated};
	__property TVCFirstImpressionAxisTitleActivated OnAxisTitleActivated = {read=FOnAxisTitleActivated, write=FOnAxisTitleActivated};
	__property TVCFirstImpressionPointActivated OnPointActivated = {read=FOnPointActivated, write=FOnPointActivated};
	__property TVCFirstImpressionPointLabelActivated OnPointLabelActivated = {read=FOnPointLabelActivated, write=FOnPointLabelActivated};
	__property TVCFirstImpressionSeriesActivated OnSeriesActivated = {read=FOnSeriesActivated, write=FOnSeriesActivated};
	__property TVCFirstImpressionSeriesLabelActivated OnSeriesLabelActivated = {read=FOnSeriesLabelActivated, write=FOnSeriesLabelActivated};
	__property Classes::TNotifyEvent OnApplyChanges = {read=FOnApplyChanges, write=FOnApplyChanges};
public:
	#pragma option push -w-inl
	/* TOleControl.Create */ inline __fastcall virtual TVCFirstImpression(Classes::TComponent* AOwner) : Olectrls::TOleControl(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TOleControl.Destroy */ inline __fastcall virtual ~TVCFirstImpression(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TVCFirstImpression(HWND ParentWindow) : Olectrls::TOleControl(ParentWindow) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------
extern PACKAGE void __fastcall Register(void);

}	/* namespace Vcfimprs */
using namespace Vcfimprs;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// VCFImprs
