//---------------------------------------------------------------------------
#ifndef UMainH
#define UMainH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Chart.hpp>
#include <ExtCtrls.hpp>
#include <Series.hpp>
#include <TeEngine.hpp>
#include <TeeProcs.hpp>

const int NumPoints = 30;

//---------------------------------------------------------------------------
class TMiniForm : public TForm
{
__published:	// IDE-managed Components
  TPanel *Panel1;
  TChart *Chart1;
  TLineSeries *LineSeries1;
  TLineSeries *LineSeries2;
  TChart *Chart2;
  TBarSeries *BarSeries1;
  TPanel *Panel2;
  TChart *Chart3;
  TPieSeries *PieSeries1;
  TChart *Chart4;
  TAreaSeries *AreaSeries1;
  TLineSeries *LineSeries3;
  TTimer *Timer1;
  void __fastcall FormCreate(TObject *Sender);
  void __fastcall FormResize(TObject *Sender);
  void __fastcall Timer1Timer(TObject *Sender);
  void __fastcall LineSeries2AfterDrawValues(TObject *Sender);
  void __fastcall LineSeries3AfterDrawValues(TObject *Sender);
private:	// User declarations
  int PosChart1;
  int PosChart4; // used to draw vertical lines over charts
  void RefreshMonitorChart(TChart* Chart, int &PosChart);
public:		// User declarations
  __fastcall TMiniForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TMiniForm *MiniForm;
//---------------------------------------------------------------------------
#endif
 