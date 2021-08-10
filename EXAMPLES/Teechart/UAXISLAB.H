//---------------------------------------------------------------------------
#ifndef UAxisLabH
#define UAxisLabH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Buttons.hpp>
#include <Chart.hpp>
#include <ExtCtrls.hpp>
#include <Series.hpp>
#include <TeEngine.hpp>
#include <TeeProcs.hpp>
//---------------------------------------------------------------------------
class TAxisLabelsForm : public TForm
{
__published:	// IDE-managed Components
  TChart *Chart1;
  TLineSeries *LineSeries1;
  TPointSeries *PointSeries1;
  TPanel *Panel1;
  TRadioGroup *RadioGroup1;
  TBitBtn *BitBtn3;
  TMemo *Memo1;
  void __fastcall FormCreate(TObject *Sender);
  void __fastcall RadioGroup1Click(TObject *Sender);
  void __fastcall Chart1GetNextAxisLabel(TChartAxis *Sender,
          int LabelIndex, double &LabelValue, bool &Stop);
private:	// User declarations
  bool DefaultLabels;
public:		// User declarations
  __fastcall TAxisLabelsForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TAxisLabelsForm *AxisLabelsForm;
//---------------------------------------------------------------------------
#endif
 