//---------------------------------------------------------------------------
#ifndef TeeBasicH
#define TeeBasicH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ArrowCha.hpp>
#include <BubbleCh.hpp>
#include <Buttons.hpp>
#include <Chart.hpp>
#include <ExtCtrls.hpp>
#include <GanttCh.hpp>
#include <Series.hpp>
#include <TeEngine.hpp>
#include <TeeProcs.hpp>
#include <TeeShape.hpp>
//---------------------------------------------------------------------------
class TDemoForm : public TForm
{
__published:	// IDE-managed Components
    TLabel *Label4;
    TLabel *Label5;
    TPanel *Panel2;
    TSpeedButton *SpeedButton1;
    TSpeedButton *SpeedButton2;
    TSpeedButton *SpeedButton3;
    TSpeedButton *SpeedButton4;
    TButton *Button2;
    TBitBtn *BitBtn1;
    TBitBtn *BitBtn2;
    TButton *Button3;
    TPanel *Panel3;
    TLabel *Label1;
    TLabel *Label2;
    TLabel *Label3;
    TLabel *Label8;
    TLabel *Label9;
    TListBox *ListBox1;
    TCheckBox *CheckBox1;
    TCheckBox *CheckBox2;
    TScrollBar *ScrollBar1;
    TScrollBar *ScrollBar2;
    TScrollBar *ScrollBar3;
    TScrollBar *ScrollBar4;
    TNotebook *Notebook1;
    TChart *Chart1;
    TLineSeries *Series1;
    TLineSeries *Series2;
    TLineSeries *Series3;
    TLineSeries *Series4;
    TChart *Chart3;
    TComboBox *ComboBox2;
    THorizBarSeries *Series8;
    THorizBarSeries *Series10;
    THorizBarSeries *Series9;
    TChart *Chart4;
    TCheckBox *CheckBox4;
    TAreaSeries *Series11;
    TAreaSeries *Series12;
    TChart *Chart5;
    TPointSeries *Series13;
    TPointSeries *Series14;
    TPointSeries *Series15;
    TPointSeries *Series16;
    TPointSeries *Series17;
    TPointSeries *Series18;
    TChart *Chart6;
    TCheckBox *CheckBox3;
    TPieSeries *Series19;
    TChart *Chart7;
    TFastLineSeries *Series20;
    TFastLineSeries *Series21;
    TFastLineSeries *Series22;
    TFastLineSeries *Series23;
    TFastLineSeries *Series24;
    TChart *Chart8;
    TArrowSeries *Series26;
    TArrowSeries *Series27;
    TChart *Chart9;
    TBubbleSeries *Series28;
    TChart *Chart10;
    TGanttSeries *Series29;
    TChart *Chart11;
    TChartShape *Series30;
    TChartShape *Series31;
    TChartShape *Series32;
    TTimer *Timer1;
    TChart *Chart2;
    TComboBox *ComboBox1;
    TBarSeries *Series5;
    TBarSeries *Series7;
    TBarSeries *Series6;
    void __fastcall ListBox1Click(TObject *Sender);
    void __fastcall FormCreate(TObject *Sender);
    void __fastcall CheckBox1Click(TObject *Sender);
    void __fastcall CheckBox2Click(TObject *Sender);
    void __fastcall ScrollBar1Change(TObject *Sender);
    void __fastcall Timer1Timer(TObject *Sender);
    void __fastcall Button2Click(TObject *Sender);
    void __fastcall BitBtn1Click(TObject *Sender);
    void __fastcall BitBtn2Click(TObject *Sender);
    void __fastcall SpeedButton1Click(TObject *Sender);
    void __fastcall SpeedButton4Click(TObject *Sender);
    void __fastcall SpeedButton2Click(TObject *Sender);
    void __fastcall SpeedButton3Click(TObject *Sender);
    void __fastcall CheckBox3Click(TObject *Sender);
    void __fastcall ComboBox1Click(TObject *Sender);
    void __fastcall ScrollBar2Change(TObject *Sender);
    void __fastcall Series28GetMarkText(TChartSeries *Sender,
          int ValueIndex, AnsiString &MarkText);
    void __fastcall Button3Click(TObject *Sender);
    void __fastcall CheckBox4Click(TObject *Sender);
    void __fastcall FormShow(TObject *Sender);
    void __fastcall ScrollBar3Change(TObject *Sender);
    void __fastcall ScrollBar4Change(TObject *Sender);
        
private:	// User declarations
public:		// User declarations
  int tmpSeries;
  int tmpIndex;
  int tmpRandom;
  int tmpTimes;
  TChart* TheChart();
  void HorizScroll(const double Percent);
  void VertScroll(const double Percent);
  void ScrollAxis(TChartAxis* Axis, const double Percent);
  __fastcall TDemoForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TDemoForm *DemoForm;
//---------------------------------------------------------------------------
#endif
