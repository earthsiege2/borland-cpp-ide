// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'TeeGally.pas' rev: 6.00

#ifndef TeeGallyHPP
#define TeeGallyHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <TeeFunci.hpp>	// Pascal unit
#include <Chart.hpp>	// Pascal unit
#include <TeEngine.hpp>	// Pascal unit
#include <ComCtrls.hpp>	// Pascal unit
#include <StdCtrls.hpp>	// Pascal unit
#include <ExtCtrls.hpp>	// Pascal unit
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

namespace Teegally
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TTeeTabControl;
class PASCALIMPLEMENTATION TTeeTabControl : public Comctrls::TTabControl 
{
	typedef Comctrls::TTabControl inherited;
	
public:
	void __fastcall AlignTab(void);
	void __fastcall SetTabEvent(Classes::TNotifyEvent Value);
public:
	#pragma option push -w-inl
	/* TCustomTabControl.Create */ inline __fastcall virtual TTeeTabControl(Classes::TComponent* AOwner) : Comctrls::TTabControl(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomTabControl.Destroy */ inline __fastcall virtual ~TTeeTabControl(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TTeeTabControl(HWND ParentWindow) : Comctrls::TTabControl(ParentWindow) { }
	#pragma option pop
	
};


class DELPHICLASS TTeeGalleryPanel;
class PASCALIMPLEMENTATION TTeeGalleryPanel : public Extctrls::TPanel 
{
	typedef Extctrls::TPanel inherited;
	
private:
	bool FView3D;
	Classes::TNotifyEvent FOnSelectedChart;
	Classes::TNotifyEvent FOnChangeChart;
	void __fastcall CheckShowLabels(Chart::TCustomChart* AChart);
	Chart::TCustomChart* __fastcall GetChart(int Index);
	void __fastcall SetView3D(bool Value);
	void __fastcall SetMargins(Chart::TCustomChart* AChart);
	
protected:
	DYNAMIC void __fastcall Resize(void);
	
public:
	Chart::TCustomChart* SelectedChart;
	Teengine::TChartSeries* SelectedSeries;
	int RowHeight;
	int ColWidth;
	int NumRows;
	int NumCols;
	Classes::TList* ChartList;
	bool CheckSeries;
	__fastcall virtual TTeeGalleryPanel(Classes::TComponent* AOwner);
	__fastcall virtual ~TTeeGalleryPanel(void);
	void __fastcall ResizeCharts(void);
	void __fastcall CalcChartWidthHeight(void);
	void __fastcall SetRowCols(int ARows, int ACols);
	void __fastcall ResizeChart(Chart::TCustomChart* AChart);
	void __fastcall GetChartXY(Chart::TCustomChart* AChart, int &x, int &y);
	void __fastcall RemoveCharts(void);
	void __fastcall CreateChart(const Chart::TTeeSeriesType* tmpType, int Index);
	void __fastcall ChartOnClick(System::TObject* Sender);
	void __fastcall ChartOnDblClick(System::TObject* Sender);
	void __fastcall ShowSelectedChart(void);
	void __fastcall FindSelectedChart(void);
	__property bool View3D = {read=FView3D, write=SetView3D, nodefault};
	void __fastcall ProcessKeyDown(System::TObject* Sender, Word &Key, Classes::TShiftState Shift);
	void __fastcall CreateChartList(TMetaClass* * ASeriesList, const int ASeriesList_Size);
	__property Chart::TCustomChart* Chart[int Index] = {read=GetChart};
	
__published:
	__property Classes::TNotifyEvent OnSelectedChart = {read=FOnSelectedChart, write=FOnSelectedChart};
	__property Classes::TNotifyEvent OnChangeChart = {read=FOnChangeChart, write=FOnChangeChart};
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TTeeGalleryPanel(HWND ParentWindow) : Extctrls::TPanel(ParentWindow) { }
	#pragma option pop
	
};


class DELPHICLASS TTeeGallery;
class PASCALIMPLEMENTATION TTeeGallery : public Forms::TForm 
{
	typedef Forms::TForm inherited;
	
__published:
	Extctrls::TPanel* P1;
	Stdctrls::TButton* BOk;
	Stdctrls::TButton* BCancel;
	Stdctrls::TCheckBox* CB3D;
	void __fastcall CB3DClick(System::TObject* Sender);
	void __fastcall FormShow(System::TObject* Sender);
	void __fastcall FormResize(System::TObject* Sender);
	void __fastcall FormCreate(System::TObject* Sender);
	void __fastcall FormKeyDown(System::TObject* Sender, Word &Key, Classes::TShiftState Shift);
	
public:
	TTeeGalleryPanel* GalleryPanel;
	bool CreatingForm;
	bool FunctionsVisible;
	TTeeTabControl* TabControl;
	Classes::TNotifyEvent OnChangeChart;
	void __fastcall CreateGallery(int APage);
	void __fastcall HideButtons(void);
	void __fastcall HideFunctions(void);
	int __fastcall CalcNumSeriesPage(const AnsiString APage);
	void __fastcall TabControl1Change(System::TObject* Sender);
	void __fastcall GalleryPanelOnSelected(System::TObject* Sender);
	bool __fastcall ValidSeries(const Chart::TTeeSeriesType* ASeriesType, const AnsiString APage);
	void __fastcall CreateGalleryList(TMetaClass* * ASeriesList, const int ASeriesList_Size);
public:
	#pragma option push -w-inl
	/* TCustomForm.Create */ inline __fastcall virtual TTeeGallery(Classes::TComponent* AOwner) : Forms::TForm(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.CreateNew */ inline __fastcall virtual TTeeGallery(Classes::TComponent* AOwner, int Dummy) : Forms::TForm(AOwner, Dummy) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.Destroy */ inline __fastcall virtual ~TTeeGallery(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TTeeGallery(HWND ParentWindow) : Forms::TForm(ParentWindow) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------
static const int clTeeGallery1 = 0xff;
static const int clTeeGallery2 = 0xff0000;
extern PACKAGE AnsiString __fastcall GetGallerySeriesName(Teengine::TChartSeries* ASeries);
extern PACKAGE bool __fastcall GetChartGalleryClass(Classes::TComponent* AOwner, Teengine::TChartSeries* OldSeries, bool ShowFunctions, TMetaClass* &tmpClass, bool &Show3D, TMetaClass* &tmpFunctionClass);
extern PACKAGE Teengine::TChartSeries* __fastcall CreateNewSeriesGallery(Classes::TComponent* AOwner, Teengine::TChartSeries* OldSeries, Chart::TCustomChart* tmpChart, bool AllowSameType, bool ShowFunctions);
extern PACKAGE void __fastcall ChangeSeriesTypeGallery(Classes::TComponent* AOwner, Teengine::TChartSeries* &tmpSeries);
extern PACKAGE void __fastcall ChangeAllSeriesGallery(Classes::TComponent* AOwner, Chart::TCustomChart* AChart);

}	/* namespace Teegally */
using namespace Teegally;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// TeeGally
