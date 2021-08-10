//---------------------------------------------------------------------------
#ifndef UShapesH
#define UShapesH
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
#include <TeeShape.hpp>
//---------------------------------------------------------------------------
class TShapesForm : public TForm
{
__published:	// IDE-managed Components
  TChart *Chart1;
  TLineSeries *LineSeries1;
  TChartShape *ChartShape3;
  TLineSeries *LineSeries2;
  TChartShape *ChartShape2;
  TChartShape *ChartShape1;
  TPanel *Panel2;
  TBitBtn *BitBtn2;
  TMemo *Memo1;
  void __fastcall FormCreate(TObject *Sender);
  void __fastcall ChartShape3Click(TChartSeries *Sender, int ValueIndex,
          TMouseButton Button, TShiftState Shift, int X, int Y);
private:	// User declarations
public:		// User declarations
  __fastcall TShapesForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TShapesForm *ShapesForm;
//---------------------------------------------------------------------------
#endif
   