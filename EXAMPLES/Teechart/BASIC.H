//---------------------------------------------------------------------------
#ifndef BasicH
#define BasicH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Buttons.hpp>
#include <Chart.hpp>
#include <Dialogs.hpp>
#include <ExtCtrls.hpp>
#include <Series.hpp>
#include <TeEngine.hpp>
#include <TeeProcs.hpp>
//---------------------------------------------------------------------------
class TBasicForm : public TForm
{
__published:	// IDE-managed Components
  TChart *Chart1;
  TLineSeries *Winter;
  TLineSeries *Summer;
  TChart *Chart2;
  TBarSeries *BarSeries1;
  TChart *Chart3;
  TAreaSeries *South;
  TAreaSeries *North;
  TChart *Chart4;
  TPointSeries *Speaking;
  TPointSeries *Writing;
  TPointSeries *Reading;
  TPanel *Panel1;
  TCheckBox *CheckBox1;
  TBitBtn *BitBtn1;
  TRadioGroup *RadioGroup1;
  TCheckBox *CheckBox2;
  TBitBtn *BitBtn2;
  TBitBtn *BitBtn3;
  TPanel *Panel2;
  TLabel *Label1;
  TTimer *Timer1;
  TSaveDialog *SaveDialog1;
  void __fastcall FormCreate(TObject *Sender);
  void __fastcall CheckBox1Click(TObject *Sender);
  
  void __fastcall Timer1Timer(TObject *Sender);
  void __fastcall FormResize(TObject *Sender);
  void __fastcall FormShow(TObject *Sender);
  void __fastcall BitBtn1Click(TObject *Sender);
  void __fastcall CheckBox2Click(TObject *Sender);
  void __fastcall BitBtn2Click(TObject *Sender);
private:	// User declarations
  void Animate(TChartSeries* Series);
public:		// User declarations
  __fastcall TBasicForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TBasicForm *BasicForm;
//---------------------------------------------------------------------------
#endif
