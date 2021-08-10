//---------------------------------------------------------------------------
#ifndef UOverbarH
#define UOverbarH
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
class TOverBarForm : public TForm
{
__published:	// IDE-managed Components
  TChart *Chart1;
  TBarSeries *BarSeries3;
  TBarSeries *BarSeries2;
  TBarSeries *BarSeries1;
  TPanel *Panel1;
  TLabel *Label1;
  TLabel *Label2;
  TMemo *Memo1;
  TBitBtn *BitBtn3;
  TCheckBox *CBPatterns;
        TScrollBar *ScrollBar1;
        TScrollBar *ScrollBar2;
  void __fastcall FormCreate(TObject *Sender);
  void __fastcall BarSeries2Click(TChartSeries *Sender, int ValueIndex,
          TMouseButton Button, TShiftState Shift, int X, int Y);
  void __fastcall BarSeries1Click(TChartSeries *Sender, int ValueIndex,
          TMouseButton Button, TShiftState Shift, int X, int Y);
  void __fastcall CBPatternsClick(TObject *Sender);
  void __fastcall BarSeries3Click(TChartSeries *Sender, int ValueIndex,
          TMouseButton Button, TShiftState Shift, int X, int Y);
        void __fastcall ScrollBar1Change(TObject *Sender);
        void __fastcall ScrollBar2Change(TObject *Sender);
private:	// User declarations
  void ChangeOverBars();
public:		// User declarations
  __fastcall TOverBarForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TOverBarForm *OverBarForm;
//---------------------------------------------------------------------------
#endif
  