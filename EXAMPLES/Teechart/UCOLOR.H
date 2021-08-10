//---------------------------------------------------------------------------
#ifndef UColorH
#define UColorH
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
class TColoredForm : public TForm
{
__published:	// IDE-managed Components
  TChart *Chart1;
  TLineSeries *LineSeries1;
  TPointSeries *PointSeries1;
  TPanel *Panel1;
  TCheckBox *CheckBox1;
  TBitBtn *BitBtn2;
  TMemo *Memo1;
  void __fastcall FormCreate(TObject *Sender);
  void __fastcall CheckBox1Click(TObject *Sender);
private:	// User declarations
  void AddColors(TChartSeries* Series);
public:		// User declarations
  __fastcall TColoredForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TColoredForm *ColoredForm;
//---------------------------------------------------------------------------
#endif
